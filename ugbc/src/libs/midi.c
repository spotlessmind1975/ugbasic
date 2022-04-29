/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *----------------------------------------------------------------------------
 * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
 * (la "Licenza"); è proibito usare questo file se non in conformità alla
 * Licenza. Una copia della Licenza è disponibile all'indirizzo:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Se non richiesto dalla legislazione vigente o concordato per iscritto,
 * il software distribuito nei termini della Licenza è distribuito
 * "COSÌ COM'È", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

#include <endian.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef  __APPLE__
#include <malloc.h>
#endif
#include "midi.h"

typedef struct _MidiLastNote {
	BYTE note, chn;
	BYTE valid, p2;
	DWORD end_pos;
} MidiLastNote;

typedef struct _MidiFileTrack {
	BYTE *ptr;
	BYTE *pBase;
	BYTE *pEnd;
	DWORD pos;
	DWORD dt;
	DWORD sz;
	DWORD iBlockSize;
	BYTE iDefaultChannel;
	BYTE last_status;
	MidiLastNote LastNote[MAX_TRACK_POLYPHONY];
} MidiFileTrack;

typedef struct _MidiHeader {
	DWORD	iHeaderSize;
	WORD	iVersion;
	WORD	iNumTracks;
	WORD	PPQN;
} MidiHeader;

typedef struct _MidiFileInternal {
	FILE				*pFile;
	int				bOpenForWriting;
	MidiHeader			Header;
	BYTE *ptr;			
	DWORD file_sz;
	MidiFileTrack		Track[MAX_MIDI_TRACKS];
} MidiFileInternal;

#define DT_DEF				32

#if BYTE_ORDER == BIG_ENDIAN
	#define SWAP_WORD(w)		(w)
	#define SWAP_DWORD(d)	(d)
#else
	#define SWAP_WORD(w)		(WORD)(((w)>>8)|((w)<<8))
	#define SWAP_DWORD(d)	(DWORD)((d)>>24)|(((d)>>8)&0xff00)|(((d)<<8)&0xff0000)|(((d)<<24))
#endif

#define _VAR_CAST				MidiFileInternal *pMF = (MidiFileInternal *)_pMF
#define IsFilePtrValid(pMF)		(pMF)
#define IsTrackValid(_x)		(_midiValidateTrack(pMF, _x))
#define IsChannelValid(_x)		((_x)>=1 && (_x)<=16)
#define IsNoteValid(_x)			((_x)>=0 && (_x)<128)
#define IsMessageValid(_x)		((_x)>=messageNoteOff && (_x)<=messageMetaEvent)

static int _midiValidateTrack(const MidiFileInternal *pMF, int iTrack)
{
	if (!IsFilePtrValid(pMF))	return FALSE;
	
	if (pMF->bOpenForWriting)
		{
		if (iTrack < 0 || iTrack >= MAX_MIDI_TRACKS)
			return FALSE;
		}
	else
		{
		if (!pMF->ptr)
			return FALSE;
		
		if (iTrack < 0 || iTrack>=pMF->Header.iNumTracks)
			return FALSE;
		}
	
	return TRUE;
}

static BYTE *_midiWriteVarLen(BYTE *ptr, int n){
register long buffer;
register long value=n;

	buffer = value & 0x7f;
	while ((value >>= 7) > 0)
		{
		buffer <<= 8;
		buffer |= 0x80;
		buffer += (value & 0x7f);
		}

	while (TRUE)
		{
		*ptr++ = (BYTE)buffer;
		if (buffer & 0x80)
			buffer >>= 8;
		else
			break;
		}
	
	return(ptr);
}

static BYTE *_midiGetPtr(MidiFileInternal *pMF, int iTrack, int sz_reqd)
{
const DWORD mem_sz_inc = 8092;
BYTE *ptr;
int curr_offset;
MidiFileTrack *pTrack = &pMF->Track[iTrack];

	ptr = pTrack->ptr;
	if (ptr == NULL || ptr+sz_reqd > pTrack->pEnd)
		{
		curr_offset = ptr-pTrack->pBase;
		if ((ptr = (BYTE *)realloc(pTrack->pBase, mem_sz_inc+pTrack->iBlockSize)))
			{
			pTrack->pBase = ptr;
			pTrack->iBlockSize += mem_sz_inc;
			pTrack->pEnd = ptr+pTrack->iBlockSize;
			pTrack->ptr = ptr+curr_offset;
			ptr += curr_offset;
			}
		else
			{
			return NULL;
			}
		}

	return ptr;
}


static int _midiGetLength(int ppqn, int iNoteLen, int bOverride)
{
int length = ppqn;
	
	if (bOverride)
		{
		length = iNoteLen;
		}
	else
		{
		switch(iNoteLen)
			{
			case	MIDI_DURATION_DOTTED_MINIM:
						length *= 3;
						break;

			case	MIDI_DURATION_DOTTED_CROCHET:
						length *= 3;
						length /= 2;
						break;

			case	MIDI_DURATION_DOTTED_QUAVER:
						length *= 3;
						length /= 4;
						break;

			case	MIDI_DURATION_DOTTED_SEMIQUAVER:
						length *= 3;
						length /= 8;
						break;

			case	MIDI_DURATION_DOTTED_SEMIDEMIQUAVER:
						length *= 3;
						length /= 16;
						break;

			case	MIDI_DURATION_BREVE:
						length *= 4;
						break;

			case	MIDI_DURATION_MINIM:
						length *= 2;
						break;

			case	MIDI_DURATION_QUAVER:
						length /= 2;
						break;

			case	MIDI_DURATION_SEMIQUAVER:
						length /= 4;
						break;

			case	MIDI_DURATION_SEMIDEMIQUAVER:
						length /= 8;
						break;
			
			case	MIDI_DURATION_TRIPLE_CROCHET:
						length *= 2;
						length /= 3;
						break;			
			}
		}
	
	return length;
}

MidiFile  *midiFileCreate(const char *pFilename, int bOverwriteIfExists)
{
MidiFileInternal *pMF = (MidiFileInternal *)malloc(sizeof(MidiFileInternal));
int i;

	if (!pMF)							return NULL;
	
	if (!bOverwriteIfExists)
		{
		if ((pMF->pFile = fopen(pFilename, "r")))
			{
			fclose(pMF->pFile);
			free(pMF);
			return NULL;
			}
		}
	
	if ((pMF->pFile = fopen(pFilename, "wb+")))
		{ }
	else
		{
		free((void *)pMF);
		return NULL;
		}
	
	pMF->bOpenForWriting = TRUE;
	pMF->Header.PPQN = MIDI_PPQN_DEFAULT;
	pMF->Header.iVersion = MIDI_VERSION_DEFAULT;
	
	for(i=0;i<MAX_MIDI_TRACKS;++i)
		{
		pMF->Track[i].pos = 0;
		pMF->Track[i].ptr = NULL;
		pMF->Track[i].pBase = NULL;
		pMF->Track[i].pEnd = NULL;
		pMF->Track[i].iBlockSize = 0;
		pMF->Track[i].dt = 0;
		pMF->Track[i].iDefaultChannel = (BYTE)(i & 0xf);
		
		memset(pMF->Track[i].LastNote, '\0', sizeof(pMF->Track[i].LastNote));
		}
	
	return (MidiFile *)pMF;
}

int		midiFileSetTracksDefaultChannel(MidiFile *_pMF, int iTrack, int iChannel)
{
int prev;

	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return 0;
	if (!IsTrackValid(iTrack))				return 0;
	if (!IsChannelValid(iChannel))			return 0;

	prev = pMF->Track[iTrack].iDefaultChannel+1;
	pMF->Track[iTrack].iDefaultChannel = (BYTE)(iChannel-1);
	return prev;
}

int		midiFileGetTracksDefaultChannel(const MidiFile *_pMF, int iTrack)
{
	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return 0;
	if (!IsTrackValid(iTrack))				return 0;

	return pMF->Track[iTrack].iDefaultChannel+1;
}

int		midiFileSetPPQN(MidiFile *_pMF, int PPQN)
{
int prev;

	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return MIDI_PPQN_DEFAULT;
	prev = pMF->Header.PPQN;
	pMF->Header.PPQN = (WORD)PPQN;
	return prev;
}

int		midiFileGetPPQN(const MidiFile *_pMF)
{
	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return MIDI_PPQN_DEFAULT;
	return (int)pMF->Header.PPQN;
}

int		midiFileSetVersion(MidiFile *_pMF, int iVersion)
{
int prev;

	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return MIDI_VERSION_DEFAULT;
	if (iVersion<0 || iVersion>2)			return MIDI_VERSION_DEFAULT;
	prev = pMF->Header.iVersion;
	pMF->Header.iVersion = (WORD)iVersion;
	return prev;
}

int			midiFileGetVersion(const MidiFile *_pMF)
{
	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return MIDI_VERSION_DEFAULT;
	return pMF->Header.iVersion;
}

MidiFile  *midiFileOpen(const char *pFilename)
{
FILE *fp = fopen(pFilename, "rb");
MidiFileInternal *pMF = NULL;
BYTE *ptr;
int bValidFile=FALSE;
long size;

	if (fp)
		{
		if ((pMF = (MidiFileInternal *)malloc(sizeof(MidiFileInternal))))
			{
			fseek(fp, 0L, SEEK_END);
			size = ftell(fp);
			if ((pMF->ptr = (BYTE *)malloc(size)))
				{
				fseek(fp, 0L, SEEK_SET);
				(void)!fread(pMF->ptr, sizeof(BYTE), size, fp);
				ptr = pMF->ptr;
				if (*(ptr+0) == 'M' && *(ptr+1) == 'T' && 
					*(ptr+2) == 'h' && *(ptr+3) == 'd')
					{
					DWORD dwData;
					WORD wData;
					int i;

					dwData = *((DWORD *)(ptr+4));
					pMF->Header.iHeaderSize = SWAP_DWORD(dwData);
					
					wData = *((WORD *)(ptr+8));
					pMF->Header.iVersion = (WORD)SWAP_WORD(wData);
					
					wData = *((WORD *)(ptr+10));
					pMF->Header.iNumTracks = (WORD)SWAP_WORD(wData);
					
					wData = *((WORD *)(ptr+12));
					pMF->Header.PPQN = (WORD)SWAP_WORD(wData);
					
					ptr += pMF->Header.iHeaderSize+8;

					for(i=0;i<MAX_MIDI_TRACKS;++i)
						{
						pMF->Track[i].pos = 0;
						pMF->Track[i].last_status = 0;
						}
					
					for(i=0;i<pMF->Header.iNumTracks;++i)
						{
						pMF->Track[i].pBase = ptr;
						pMF->Track[i].ptr = ptr+8;
						dwData = *((DWORD *)(ptr+4));
						pMF->Track[i].sz = SWAP_DWORD(dwData);
						pMF->Track[i].pEnd = ptr+pMF->Track[i].sz+8;
						ptr += pMF->Track[i].sz+8;
						}
						   
					pMF->bOpenForWriting = FALSE;
					pMF->pFile = NULL;
					bValidFile = TRUE;
					}
				}
			}

		fclose(fp);
		}
	
	if (!bValidFile)
		{
		if (pMF)		free((void *)pMF);
		return NULL;
		}
	
	return (MidiFile *)pMF;
}

typedef struct {
		int	iIdx;
		int	iEndPos;
		} MIDI_END_POINT;

static int qs_cmp_pEndPoints(const void *e1, const void *e2)
{
MIDI_END_POINT *p1 = (MIDI_END_POINT *)e1;
MIDI_END_POINT *p2 = (MIDI_END_POINT *)e2;

	return p1->iEndPos-p2->iEndPos;
}

int	midiFileFlushTrack(MidiFile *_pMF, int iTrack, int bFlushToEnd, DWORD dwEndTimePos)
{
int sz;
BYTE *ptr;
MIDI_END_POINT *pEndPoints;
int num, i, mx_pts;

	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return FALSE;
	if (!_midiValidateTrack(pMF, iTrack))	return FALSE;
	sz = sizeof(pMF->Track[0].LastNote)/sizeof(pMF->Track[0].LastNote[0]);

	pEndPoints = (MIDI_END_POINT *)malloc(sz * sizeof(MIDI_END_POINT));
	mx_pts = 0;
	for(i=0;i<sz;++i)
		if (pMF->Track[iTrack].LastNote[i].valid)
			{
			pEndPoints[mx_pts].iIdx = i;
			pEndPoints[mx_pts].iEndPos = pMF->Track[iTrack].LastNote[i].end_pos;
			mx_pts++;
			}
	
	if (bFlushToEnd)
		{
		if (mx_pts)
			dwEndTimePos = pEndPoints[mx_pts-1].iEndPos;
		else
			dwEndTimePos = pMF->Track[iTrack].pos;
		}
	
	if (mx_pts)
		{
		qsort(pEndPoints, mx_pts, sizeof(MIDI_END_POINT), qs_cmp_pEndPoints);
		
		i = 0;
		while ((dwEndTimePos >= (DWORD)pEndPoints[i].iEndPos || bFlushToEnd) && i<mx_pts)
			{
			ptr = _midiGetPtr(pMF, iTrack, DT_DEF);
			if (!ptr)
				return FALSE;
			
			num = pEndPoints[i].iIdx;
			
			ptr = _midiWriteVarLen(ptr, pMF->Track[iTrack].LastNote[num].end_pos - pMF->Track[iTrack].pos);
			*ptr++ = (BYTE)(messageNoteOff | pMF->Track[iTrack].LastNote[num].chn);
			*ptr++ = pMF->Track[iTrack].LastNote[num].note;
			*ptr++ = 0;
			
			pMF->Track[iTrack].LastNote[num].valid = FALSE;
			pMF->Track[iTrack].pos = pMF->Track[iTrack].LastNote[num].end_pos;
			
			pMF->Track[iTrack].ptr = ptr;
			
			++i;
			}
		}
	
	free((void *)pEndPoints);
	pMF->Track[iTrack].dt = dwEndTimePos - pMF->Track[iTrack].pos;
	
	return TRUE;
}

int	midiFileSyncTracks(MidiFile *_pMF, int iTrack1, int iTrack2)
{
int p1, p2;

	_VAR_CAST;
	if (!IsFilePtrValid(pMF))			return FALSE;
	if (!IsTrackValid(iTrack1))			return FALSE;
	if (!IsTrackValid(iTrack2))			return FALSE;

	p1 = pMF->Track[iTrack1].pos + pMF->Track[iTrack1].dt;
	p2 = pMF->Track[iTrack2].pos + pMF->Track[iTrack2].dt;
	
	if (p1 < p2)		midiTrackIncTime(pMF, iTrack1, p2-p1, TRUE);
	else if (p2 < p1)	midiTrackIncTime(pMF, iTrack2, p1-p2, TRUE);
	
	return TRUE;
}


int	midiFileClose(MidiFile *_pMF)
{
	_VAR_CAST;
	if (!IsFilePtrValid(pMF))			return FALSE;
	
	if (pMF->bOpenForWriting)	
		{
		WORD iNumTracks = 0;
		WORD wTest = 256;
		int bSwap = FALSE;
		int i;

		if (*((BYTE *)&wTest) == 0)
			bSwap = TRUE;

		for(i=0;i<MAX_MIDI_TRACKS;++i)
			{
			if (pMF->Track[i].ptr)
				{
				midiSongAddEndSequence(pMF, i);
				midiFileFlushTrack(pMF, i, TRUE, 0);
				iNumTracks++;
				}
			}

		{
		const BYTE mthd[4] = {'M', 'T', 'h', 'd'};
		DWORD dwData;
		WORD wData;
		WORD version, PPQN;

			fwrite(mthd, sizeof(BYTE), 4, pMF->pFile);
			dwData = 6;
			if (bSwap)	dwData = SWAP_DWORD(dwData);
			fwrite(&dwData, sizeof(DWORD), 1, pMF->pFile);

			wData = (WORD)(iNumTracks==1?pMF->Header.iVersion:1);
			if (bSwap)	version = SWAP_WORD(wData); else version = (WORD)wData;
			if (bSwap)	iNumTracks = SWAP_WORD(iNumTracks);
			wData = pMF->Header.PPQN;
			if (bSwap)	PPQN = SWAP_WORD(wData); else PPQN = wData;
			fwrite(&version, sizeof(WORD), 1, pMF->pFile);
			fwrite(&iNumTracks, sizeof(WORD), 1, pMF->pFile);
			fwrite(&PPQN, sizeof(WORD), 1, pMF->pFile);
		}

		for(i=0;i<MAX_MIDI_TRACKS;++i)
			if (pMF->Track[i].ptr)
				{
				const BYTE mtrk[4] = {'M', 'T', 'r', 'k'};
				DWORD sz, dwData;

				fwrite(&mtrk, sizeof(BYTE), 4, pMF->pFile);

				sz = dwData = (int)(pMF->Track[i].ptr - pMF->Track[i].pBase);
				if (bSwap)	sz = SWAP_DWORD(sz);
				fwrite(&sz, sizeof(DWORD), 1, pMF->pFile);

				fwrite(pMF->Track[i].pBase, sizeof(BYTE), dwData, pMF->pFile);
				
				free((void *)pMF->Track[i].pBase);
				}

		}

	if (pMF->pFile)
		return fclose(pMF->pFile)?FALSE:TRUE;
	free((void *)pMF);
	return TRUE;
}

int	midiSongAddSMPTEOffset(MidiFile *_pMF, int iTrack, int iHours, int iMins, int iSecs, int iFrames, int iFFrames)
{
static BYTE tmp[] = {messageMetaEvent, metaInfoSMPTEOffset, 0x05, 0,0,0,0,0};

	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return FALSE;
	if (!IsTrackValid(iTrack))				return FALSE;

	if (iMins<0 || iMins>59)		iMins=0;
	if (iSecs<0 || iSecs>59)		iSecs=0;
	if (iFrames<0 || iFrames>24)	iFrames=0;

	tmp[3] = (BYTE)iHours;
	tmp[4] = (BYTE)iMins;
	tmp[5] = (BYTE)iSecs;
	tmp[6] = (BYTE)iFrames;
	tmp[7] = (BYTE)iFFrames;
	return midiTrackAddRaw(pMF, iTrack, sizeof(tmp), tmp, FALSE, 0);
}


int	midiSongAddSimpleTimeSig(MidiFile *_pMF, int iTrack, int iNom, int iDenom)
{
	return midiSongAddTimeSig(_pMF, iTrack, iNom, iDenom, 24, 8);
}

int	midiSongAddTimeSig(MidiFile *_pMF, int iTrack, int iNom, int iDenom, int iClockInMetroTick, int iNotated32nds)
{
static BYTE tmp[] = {messageMetaEvent, metaInfoTimeSig, 0x04, 0,0,0,0};

	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return FALSE;
	if (!IsTrackValid(iTrack))				return FALSE;

	tmp[3] = (BYTE)iNom;
	tmp[4] = (BYTE)(MIDI_DURATION_MINIM/iDenom);
	tmp[5] = (BYTE)iClockInMetroTick;
	tmp[6] = (BYTE)iNotated32nds;
	return midiTrackAddRaw(pMF, iTrack, sizeof(tmp), tmp, FALSE, 0);
}

int	midiSongAddKeySig(MidiFile *_pMF, int iTrack, MidiNote iKey)
{
static BYTE tmp[] = {messageMetaEvent, metaInfoKeySig, 0x02, 0, 0};

	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return FALSE;
	if (!IsTrackValid(iTrack))				return FALSE;

	tmp[3] = (BYTE)((iKey&noteMaskKey)*((iKey&noteMaskNeg)?-1:1));
	tmp[4] = (BYTE)((iKey&noteMaskMin)?1:0);
	return midiTrackAddRaw(pMF, iTrack, sizeof(tmp), tmp, FALSE, 0);
}

int	midiSongAddTempo(MidiFile *_pMF, int iTrack, int iTempo)
{
static BYTE tmp[] = {messageMetaEvent, metaInfoSetTempo, 0x03, 0,0,0};
int us;

	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return FALSE;
	if (!IsTrackValid(iTrack))				return FALSE;

	us = 60000000L/iTempo;
	tmp[3] = (BYTE)((us>>16)&0xff);
	tmp[4] = (BYTE)((us>>8)&0xff);
	tmp[5] = (BYTE)((us>>0)&0xff);
	return midiTrackAddRaw(pMF, iTrack, sizeof(tmp), tmp, FALSE, 0);
}

int	midiSongAddMIDIPort(MidiFile *_pMF, int iTrack, int iPort)
{
static BYTE tmp[] = {messageMetaEvent, metaInfoMIDIPort, 1, 0};

	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return FALSE;
	if (!IsTrackValid(iTrack))				return FALSE;
	tmp[3] = (BYTE)iPort;
	return midiTrackAddRaw(pMF, iTrack, sizeof(tmp), tmp, FALSE, 0);
}

int	midiSongAddEndSequence(MidiFile *_pMF, int iTrack)
{
static BYTE tmp[] = {messageMetaEvent, metaInfoEndSequence, 0};

	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return FALSE;
	if (!IsTrackValid(iTrack))				return FALSE;

	return midiTrackAddRaw(pMF, iTrack, sizeof(tmp), tmp, FALSE, 0);
}

int	midiTrackAddRaw(MidiFile *_pMF, int iTrack, int data_sz, const BYTE *pData, int bMovePtr, int dt)
{
MidiFileTrack *pTrk;
BYTE *ptr;
int dtime;

	_VAR_CAST;
	if (!IsFilePtrValid(pMF))			return FALSE;
	if (!IsTrackValid(iTrack))			return FALSE;
	
	pTrk = &pMF->Track[iTrack];
	ptr = _midiGetPtr(pMF, iTrack, data_sz+DT_DEF);
	if (!ptr)
		return FALSE;
	
	dtime = pTrk->dt;
	if (bMovePtr)
		dtime += dt;
	
	ptr = _midiWriteVarLen(ptr, dtime);
	memcpy(ptr, pData, data_sz);
	
	pTrk->pos += dtime;
	pTrk->dt = 0;
	pTrk->ptr = ptr+data_sz;
	
	return TRUE;
}


int	midiTrackIncTime(MidiFile *_pMF, int iTrack, int iDeltaTime, int bOverridePPQN)
{
DWORD will_end_at;

	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return FALSE;
	if (!IsTrackValid(iTrack))				return FALSE;
	
	will_end_at = _midiGetLength(pMF->Header.PPQN, iDeltaTime, bOverridePPQN);
	will_end_at += pMF->Track[iTrack].pos + pMF->Track[iTrack].dt;
	
	midiFileFlushTrack(pMF, iTrack, FALSE, will_end_at);
	
	return TRUE;
}

int	midiTrackAddText(MidiFile *_pMF, int iTrack, MidiTextInfo iType, const char *pTxt)
{
BYTE *ptr;
int sz;

	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return FALSE;
	if (!IsTrackValid(iTrack))				return FALSE;

	sz = strlen(pTxt);
	if ((ptr = _midiGetPtr(pMF, iTrack, sz+DT_DEF)))
		{
		*ptr++ = 0;		
		*ptr++ = messageMetaEvent;
		*ptr++ = (BYTE)iType;
		ptr = _midiWriteVarLen((BYTE *)ptr, sz);
		strcpy((char *)ptr, pTxt);
		pMF->Track[iTrack].ptr = ptr+sz;
		return TRUE;
		}
	else		 
		{
		return FALSE;
		}
}

int	midiTrackSetKeyPressure(MidiFile *pMF, int iTrack, int iNote, int iAftertouch)
{
	return midiTrackAddMsg(pMF, iTrack, messageNoteKeyPressure, iNote, iAftertouch);
}

int	midiTrackAddControlChange(MidiFile *pMF, int iTrack, MidiControlCommand iCCType, int iParam)
{
	return midiTrackAddMsg(pMF, iTrack, messageControlChange, iCCType, iParam);
}

int	midiTrackAddProgramChange(MidiFile *pMF, int iTrack, int iInstrPatch)
{
	return midiTrackAddMsg(pMF, iTrack, messageSetProgram, iInstrPatch, 0);
}

int	midiTrackChangeKeyPressure(MidiFile *pMF, int iTrack, int iDeltaPressure)
{
	return midiTrackAddMsg(pMF, iTrack, messageChangePressure, iDeltaPressure&0x7f, 0);
}

int	midiTrackSetPitchWheel(MidiFile *pMF, int iTrack, int iWheelPos)
{
WORD wheel = (WORD)iWheelPos;

	wheel += MIDI_WHEEL_CENTRE;
	return midiTrackAddMsg(pMF, iTrack, messageSetPitchWheel, wheel&0x7f, (wheel>>7)&0x7f);
}

int	midiTrackAddMsg(MidiFile *_pMF, int iTrack, MidiMessage iMsg, int iParam1, int iParam2)
{
BYTE *ptr;
BYTE data[3];
int sz;

	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return FALSE;
	if (!IsTrackValid(iTrack))				return FALSE;
	if (!IsMessageValid(iMsg))				return FALSE;

	ptr = _midiGetPtr(pMF, iTrack, DT_DEF);
	if (!ptr)
		return FALSE;
	
	data[0] = (BYTE)(iMsg | pMF->Track[iTrack].iDefaultChannel);
	data[1] = (BYTE)(iParam1 & 0x7f); 
	data[2] = (BYTE)(iParam2 & 0x7f); 
 	switch(iMsg)
		{
		case	messageSetProgram:			
		case	messageChangePressure:
									sz = 2;
									break;

		default:						
									sz = 3;
									break;
		}
	
	return midiTrackAddRaw(pMF, iTrack, sz, data, FALSE, 0);

}

int	midiTrackAddNote(MidiFile *_pMF, int iTrack, int iNote, int iLength, int iVol, int bAutoInc, int bOverrideLength)
{
MidiFileTrack *pTrk;
BYTE *ptr;
int bSuccess = FALSE;
int i, chn;

	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return FALSE;
	if (!IsTrackValid(iTrack))				return FALSE;
	if (!IsNoteValid(iNote))				return FALSE;
	
	pTrk = &pMF->Track[iTrack];
	ptr = _midiGetPtr(pMF, iTrack, DT_DEF);
	if (!ptr)
		return FALSE;
	
	chn = pTrk->iDefaultChannel;
	iLength = _midiGetLength(pMF->Header.PPQN, iLength, bOverrideLength);
	
	for(i=0;i<sizeof(pTrk->LastNote)/sizeof(pTrk->LastNote[0]);++i)
		if (pTrk->LastNote[i].valid == FALSE)
			{
			pTrk->LastNote[i].note = (BYTE)iNote;
			pTrk->LastNote[i].chn = (BYTE)chn;
			pTrk->LastNote[i].end_pos = pTrk->pos+pTrk->dt+iLength;
			pTrk->LastNote[i].valid = TRUE;
			bSuccess = TRUE;
			
			ptr = _midiWriteVarLen(ptr, pTrk->dt);		
			*ptr++ = (BYTE)(messageNoteOn | chn);
			*ptr++ = (BYTE)iNote;
			*ptr++ = (BYTE)iVol;
			break;
			}
	
	if (!bSuccess)
		return FALSE;
	
	pTrk->ptr = ptr;
	
	pTrk->pos += pTrk->dt;
	pTrk->dt = 0;
	
	if (bAutoInc)
		return midiTrackIncTime(pMF, iTrack, iLength, bOverrideLength);
	
	return TRUE;
}

int	midiTrackAddRest(MidiFile *_pMF, int iTrack, int iLength, int bOverridePPQN)
{
	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return FALSE;
	if (!IsTrackValid(iTrack))				return FALSE;

	iLength = _midiGetLength(pMF->Header.PPQN, iLength, bOverridePPQN);
	return midiTrackIncTime(pMF, iTrack, iLength, bOverridePPQN);
}

int		midiTrackGetEndPos(MidiFile *_pMF, int iTrack)
{
	_VAR_CAST;
	if (!IsFilePtrValid(pMF))				return FALSE;
	if (!IsTrackValid(iTrack))				return FALSE;

	return pMF->Track[iTrack].pos;
}

static BYTE *_midiReadVarLen(BYTE *ptr, DWORD *num)
{
register DWORD value;
register BYTE c;

    if ((value = *ptr++) & 0x80)
		{
		value &= 0x7f;
		do
			{
			value = (value << 7) + ((c = *ptr++) & 0x7f);
			} while (c & 0x80);
		}
	*num = value;
	return(ptr);
}


static int _midiReadTrackCopyData(MidiMessagePayload *pMsg, BYTE *ptr, DWORD sz, int bCopyPtrData)
{
	if (sz > pMsg->data_sz)
		{
		pMsg->data = (BYTE *)realloc(pMsg->data, sz);
		pMsg->data_sz = sz;
		}
	
	if (!pMsg->data)
		return FALSE;
	
	if (bCopyPtrData && ptr)
		memcpy(pMsg->data, ptr, sz);
	
	return TRUE;
}

int midiReadGetNumTracks(const MidiFile *_pMF)
{
	_VAR_CAST;
	return pMF->Header.iNumTracks;
}

int midiReadGetNextMessage(const MidiFile *_pMF, int iTrack, MidiMessagePayload *pMsg)
{
MidiFileTrack *pTrack;
BYTE *bptr, *pMsgDataPtr;
int sz;

	_VAR_CAST;
	if (!IsTrackValid(iTrack))			return FALSE;
	
	pTrack = &pMF->Track[iTrack];
	if (pTrack->ptr >= pTrack->pEnd)
		return FALSE;
	
	pTrack->ptr = _midiReadVarLen(pTrack->ptr, &pMsg->dt);
	pTrack->pos += pMsg->dt;

	pMsg->dwAbsPos = pTrack->pos;

	if (*pTrack->ptr & 0x80)	
		{
		pMsg->iType = (MidiMessage)((*pTrack->ptr) & 0xf0);
		pMsgDataPtr = pTrack->ptr+1;

		if (pMsg->iType == 0xf0)
			pMsg->iType = (MidiMessage)(*pTrack->ptr);
		}
	else						
		{
		pMsg->iType = pMsg->iLastMsgType;
		pMsgDataPtr = pTrack->ptr;
		}
	
	pMsg->iLastMsgType = (MidiMessage)pMsg->iType;
	pMsg->iLastMsgChnl = (BYTE)((*pTrack->ptr) & 0x0f)+1;

	switch(pMsg->iType)
		{
		case	messageNoteOn:
							pMsg->MsgData.NoteOn.iChannel = pMsg->iLastMsgChnl;
							pMsg->MsgData.NoteOn.iNote = *(pMsgDataPtr);
							pMsg->MsgData.NoteOn.iVolume = *(pMsgDataPtr+1);
							pMsg->iMsgSize = 3;
							break;

		case	messageNoteOff:
							pMsg->MsgData.NoteOff.iChannel = pMsg->iLastMsgChnl;
							pMsg->MsgData.NoteOff.iNote = *(pMsgDataPtr);
							pMsg->iMsgSize = 3;
							break;

		case	messageNoteKeyPressure:
							pMsg->MsgData.NoteKeyPressure.iChannel = pMsg->iLastMsgChnl;
							pMsg->MsgData.NoteKeyPressure.iNote = *(pMsgDataPtr);
							pMsg->MsgData.NoteKeyPressure.iPressure = *(pMsgDataPtr+1);
							pMsg->iMsgSize = 3;
							break;

		case	messageSetParameter:
							pMsg->MsgData.NoteParameter.iChannel = pMsg->iLastMsgChnl;
							pMsg->MsgData.NoteParameter.iControl = (MidiControlCommand)*(pMsgDataPtr);
							pMsg->MsgData.NoteParameter.iParam = *(pMsgDataPtr+1);
							pMsg->iMsgSize = 3;
							break;

		case	messageSetProgram:
							pMsg->MsgData.ChangeProgram.iChannel = pMsg->iLastMsgChnl;
							pMsg->MsgData.ChangeProgram.iProgram = *(pMsgDataPtr);
							pMsg->iMsgSize = 2;
							break;

		case	messageChangePressure:
							pMsg->MsgData.ChangePressure.iChannel = pMsg->iLastMsgChnl;
							pMsg->MsgData.ChangePressure.iPressure = *(pMsgDataPtr);
							pMsg->iMsgSize = 2;
							break;

		case	messageSetPitchWheel:
							pMsg->MsgData.PitchWheel.iChannel = pMsg->iLastMsgChnl;
							pMsg->MsgData.PitchWheel.iPitch = *(pMsgDataPtr) | (*(pMsgDataPtr+1) << 7);
							pMsg->MsgData.PitchWheel.iPitch -= MIDI_WHEEL_CENTRE;
							pMsg->iMsgSize = 3;
							break;

		case	messageMetaEvent:
							bptr = pTrack->ptr;
							pMsg->MsgData.MetaEvent.iType = (MidiMetaInfo)*(pTrack->ptr+1);
							pTrack->ptr = _midiReadVarLen(pTrack->ptr+2, &pMsg->iMsgSize);
							sz = (pTrack->ptr-bptr)+pMsg->iMsgSize;
							
							if (_midiReadTrackCopyData(pMsg, pTrack->ptr, sz, FALSE) == FALSE)
								return FALSE;

							memcpy(pMsg->data, bptr, sz);

							switch(pMsg->MsgData.MetaEvent.iType)
								{
								case	metaInfoMIDIPort:
										pMsg->MsgData.MetaEvent.Data.iMIDIPort = *(pTrack->ptr+0);
										break;
								case	metaInfoSequenceNumber:
										pMsg->MsgData.MetaEvent.Data.iSequenceNumber = *(pTrack->ptr+0);
										break;
								case	metaInfoTextEvent:
								case	metaInfoCopyright:
								case	metaInfoTrackName:
								case	metaInfoInstrument:
								case	metaInfoLyric:
								case	metaInfoMarker:
								case	metaInfoCuePoint:
										pMsg->MsgData.MetaEvent.Data.Text.pData = pTrack->ptr;
										break;
								case	metaInfoEndSequence:
										break;
								case	metaInfoSetTempo:
										{
										DWORD us = ((*(pTrack->ptr+0))<<16)|((*(pTrack->ptr+1))<<8)|(*(pTrack->ptr+2));
										pMsg->MsgData.MetaEvent.Data.Tempo.iBPM = 60000000L/us;
										}
										break;
								case	metaInfoSMPTEOffset:
										pMsg->MsgData.MetaEvent.Data.SMPTE.iHours = *(pTrack->ptr+0);
										pMsg->MsgData.MetaEvent.Data.SMPTE.iMins= *(pTrack->ptr+1);
										pMsg->MsgData.MetaEvent.Data.SMPTE.iSecs = *(pTrack->ptr+2);
										pMsg->MsgData.MetaEvent.Data.SMPTE.iFrames = *(pTrack->ptr+3);
										pMsg->MsgData.MetaEvent.Data.SMPTE.iFF = *(pTrack->ptr+4);
										break;
								case	metaInfoTimeSig:
										pMsg->MsgData.MetaEvent.Data.TimeSig.iNom = *(pTrack->ptr+0);
										pMsg->MsgData.MetaEvent.Data.TimeSig.iDenom = *(pTrack->ptr+1) * MIDI_DURATION_MINIM;
										break;
								case	metaInfoKeySig:
										if (*pTrack->ptr & 0x80)
											{
											pMsg->MsgData.MetaEvent.Data.KeySig.iKey = ((256-*pTrack->ptr)&noteMaskKey);
											pMsg->MsgData.MetaEvent.Data.KeySig.iKey |= noteMaskNeg;
											}
										else
											{
											pMsg->MsgData.MetaEvent.Data.KeySig.iKey = (MidiNote)(*pTrack->ptr&noteMaskKey);
											}
										if (*(pTrack->ptr+1)) 
											pMsg->MsgData.MetaEvent.Data.KeySig.iKey |= noteMaskMin;
										break;
								case	metaInfoSequencerSpecific:
										pMsg->MsgData.MetaEvent.Data.Sequencer.iSize = pMsg->iMsgSize;
										pMsg->MsgData.MetaEvent.Data.Sequencer.pData = pTrack->ptr;
										break;
								}

							pTrack->ptr += pMsg->iMsgSize;
							pMsg->iMsgSize = sz;
							break;

		case	messageSysEx1:
		case	messageSysEx2:
							bptr = pTrack->ptr;
							pTrack->ptr = _midiReadVarLen(pTrack->ptr+1, &pMsg->iMsgSize);
							sz = (pTrack->ptr-bptr)+pMsg->iMsgSize;
							
							if (_midiReadTrackCopyData(pMsg, pTrack->ptr, sz, FALSE) == FALSE)
								return FALSE;

							memcpy(pMsg->data, bptr, sz);
							pTrack->ptr += pMsg->iMsgSize;
							pMsg->iMsgSize = sz;
							pMsg->MsgData.SysEx.pData = pMsg->data;
							pMsg->MsgData.SysEx.iSize = sz;
							break;
		}
	pMsg->bImpliedMsg = FALSE;
	if ((pMsg->iType&0xf0) != 0xf0)
		{
		if (*pTrack->ptr & 0x80) 
			{
			}
		else 
			{
			pMsg->bImpliedMsg = TRUE;
			pMsg->iImpliedMsg = pMsg->iLastMsgType;
			pMsg->iMsgSize--;
			}
		_midiReadTrackCopyData(pMsg, pTrack->ptr, pMsg->iMsgSize, TRUE);
		pTrack->ptr+=pMsg->iMsgSize;
		}
	return TRUE;
}

void midiReadInitMessage(MidiMessagePayload *pMsg)
{
	pMsg->data = NULL;
	pMsg->data_sz = 0;
	pMsg->bImpliedMsg = FALSE;
}

void midiReadFreeMessage(MidiMessagePayload *pMsg)
{
	if (pMsg->data)	free((void *)pMsg->data);
	pMsg->data = NULL;
}

static char *szPatchList[128] = {
	"Acoustic Grand Piano",
	"Bright Acoustic Piano",
	"Electric Grand Piano",
	"Honky-tonk Piano",
	"Electric Piano 1",
	"Electric Piano 2",
	"Harpsichord",
	"Clavinet",
	"Celesta",
	"Glockenspiel",
	"Music Box",
	"Vibraphone",
	"Marimba",
	"Xylophone",
	"Tubular Bells",
	"Dulcimer",
	"Draw Organ",
	"Percussive Organ",
	"Rock Organ",
	"Church Organ",
	"Reed Organ",
	"Accordian",
	"Harmonica",
	"Tango Accordian",
	"Acoustic Guitar (nylon)",
	"Acoustic Guitar (steel)",
	"Electric Guitar (jazz)",
	"Electric Guitar (clean)",
	"Electric Guitar (muted)",
	"Overdriven Guitar",
	"Distortion Guitar",
	"Guitar harmonics",
	"Acoustic bass",
	"Electric Bass (finger)",
	"Electric Bass (picked)",
	"Fretless Bass",
	"Slap Bass 1",
	"Slap Bass 2",
	"Synth bass 1",
	"Synth bass 2",
	"Violin",
	"Viola",
	"Cello",
	"Contrabass",
	"Tremolo strings",
	"Pizzicato strings",
	"Orchestral harp",
	"Timpani",
	"String ensemble 1",
	"String ensemble 2",
	"Synth strings 1",
	"Synth strings 2",
	"Choir Ahhs",
	"Voice oohs",
	"Synth voice",
	"Orchestra hit",
	"Trumpet",
	"Trombone",
	"Tuba",
	"Muted trumpet",
	"French horn",
	"Brass section",
	"Synth brass 1",
	"Synth brass 2",
	"Soprano sax",
	"Alto sax",
	"Tenor sax",
	"Baritone sax",
	"Oboe",
	"English horn",
	"Bassoon",
	"Clarinet",
	"Picclo",
	"Flute",
	"Recorder",
	"Pan Flute",
	"Bottle Blow",
	"Shakuhachi",
	"Whistle",
	"Ocarina",
	"Lead 5 (Square)",
	"Lead 5 (Sawtooth)",
	"Lead 5 (Calliope)",
	"Lead 5 (Chiff)",
	"Lead 5 (Charang)",
	"Lead 5 (Voice)",
	"Lead 5 (Fifths)",
	"Lead 5 (Bass+lead)",
	"Pad 1 (New age)",
	"Pad 2 (Warm)",
	"Pad 3 (Polysynth)",
	"Pad 4 (Choir)",
	"Pad 5 (Bowed)",
	"Pad 6 (Metallic)",
	"Pad 7 (Halo)",
	"Pad 8 (Sweep)",
	"FX 1 (Rain)",
	"FX 2 (Soundtrack)",
	"FX 3 (Crystal)",
	"FX 4 (Atmosphere)",
	"FX 5 (Brightness)",
	"FX 6 (Goblins)",
	"FX 7 (Echoes)",
	"FX 8 (Sci-fi)",
	"Sitar",
	"Banjo",
	"Shamisen",
	"Koto",
	"Kalimba",
	"Bagpipe",
	"Fiddle",
	"Shanai",
	"Tinkle bell",
	"Agogo",
	"Steel drums",
	"Woodblock",
	"Taiko drum",
	"Melodic tom",
	"Synth drum",
	"Reverse cymbal",
	"Guitar fret noise",
	"Breath noise",
	"Seashore",
	"Bird tweet",
	"Telephone ring",
	"Helicopter",
	"Applause",
	"Gunshot",
};

static char *szGMDrums[128]={
	"???",
	"???",	
	"???",	
	"???",	
	"???",	
	"???",	
	"???",	
	"???",	
	"???",	
	"???",	
	"???",	
	"???",	
	"???",
	"???",	
	"???",	
	"???",	
	"???",	
	"???",	
	"???",	
	"???",	
	"???",	
	"???",	
	"???",	
	"???",	
	"???",
	"???",	
	"???",	
	"High Q",	
	"Slap",	
	"???",	
	"???",	
	"Sticks",	
	"Square click",	
	"???",	
	"???",	
	"Acoustic Kick Drum",	
	"Electric Kick Drum",
	"Side Stick",
	"Acoustic Snare Drum",
	"Hand Clap",
	"Electric Snare Drum ",
	"Low Floor Tom",
	"Closed Hi Hat",
	"High Floor Tom",
	"Opening Hi Hat",
	"Low Tom",
	"Open Hi Hat",
	"Low Mid Tom",
	"High Mid Tom",
	"Crash Cymbal 1",
	"High Tom",
	"Ride Cymbal 1",
	"Chinese Boom",
	"Ride Bell",
	"Tamborine",
	"Splash cymbal",
	"Cowbell",
	"Crash Cymbal (2)",
	"Vibra Slap",
	"Ride Cymbal (2)",
	"Hi bongo",
	"Lo bongo",
	"Mute High Conga",
	"Open High Conga",
	"Low Conga",
	"High Timbale",
	"Low Timbale",
	"High Agogo",
	"Low Agogo",
	"Cabasa",
	"Maracas",
	"Short Hi Whistle",
	"Long Low Whistle",
	"Short Guiro",
	"Long Guiro",
	"Claves",
	"High Woodblock",
	"Low Woodblock",
	"Mute Cuica",
	"Open Cuica",
	"Mute Triangle",
	"Open Triangle",
	"Shaker",
	"Jingle Bell",
	"Tring",
	"Castinets",	
	"Mute Sudro",	
	"Open Sudro",	
};

static char *szCCList[] = {
	"Bank Select",
	"Modulation",
	"Breath Control",
	"Undefined 3",
	"Foot",
	"Portamento Time",
	"Date Entry",
	"Volume	",
	"Balance",
	"Undefined 9",
	"Pan",
	"Expression",
	"Effort Control 1",
	"Effort Control 2",
	"Undefined 14",
	"Undefined 15",
	"General Purpose 1",
	"General Purpose 2",
	"General Purpose 3",
	"General Purpose 4",
	"Undefined 20",
	"Undefined 21",
	"Undefined 22",
	"Undefined 23",
	"Undefined 24",
	"Undefined 25",
	"Undefined 26",
	"Undefined 27",
	"Undefined 28",
	"Undefined 29",
	"Undefined 30",
	"Undefined 31",
	"lsb-32", "lsb-33", "lsb-34", "lsb-35", "lsb-36", "lsb-37", "lsb-38", 
	"lsb-39", "lsb-40", "lsb-41", "lsb-42", "lsb-43", "lsb-44", "lsb-45", 
	"lsb-46", "lsb-47", "lsb-48", "lsb-49", "lsb-50", "lsb-51", "lsb-52", 
	"lsb-53", "lsb-54", "lsb-55", "lsb-56", "lsb-57", "lsb-58", "lsb-59", 
	"lsb-60", "lsb-61", "lsb-62", "lsb-63",

	"Sustain Pedal",
	"Portamento",
	"Pedal Sustenuto",
	"Pedal Soft",
	"Legato Foot Switch",
	"Hold 2",
	"Sound Variation",
	"Harm Content",
	"Release Time",
	"Attack Time",
	"Brightness",
	"Reverb",
	"Delay",
	"Pitch Transpose",
	"Flange",
	"Special FX",
	"General Purpose 5",
	"General Purpose 6",
	"General Purpose 7",
	"General Purpose 8",
	"Portamento Control",
	"Undefined 85",
	"Undefined 86",
	"Undefined 87",
	"Undefined 88",
	"Undefined 89",
	"Undefined 90",
	"FX Depth",
	"Tremelo Depth",
	"Chorus Depth",
	"Celesta Depth",
	"Phaser Depth",
	"Data Inc",
	"Data Dec",
	"Non Reg Param LSB",
	"Non Ref Param MSB",
	"Reg Param LSB",
	"Reg Param MSB",
	"Undefined 102",
	"Undefined 103",
	"Undefined 104",
	"Undefined 105",
	"Undefined 106",
	"Undefined 107",
	"Undefined 108",
	"Undefined 109",
	"Undefined 110",
	"Undefined 111",
	"Undefined 112",
	"Undefined 113",
	"Undefined 114",
	"Undefined 115",
	"Undefined 116",
	"Undefined 117",
	"Undefined 118",
	"Undefined 119",
	"All Sound Off",
	"Reset All Controllers",
	"Local Control",
	"All Notes Off",
	"Omni Mode Off",
	"Omni Mode On",
	"Mono Mode On",
	"Poly Mode On",
};

static char *szNoteName[] = {
	"C ",
	"Db",
	"D ",
	"Eb",
	"E ",
	"F ",
	"Gb",
	"G ",
	"Ab",
	"A ",
	"Bb",
	"B ",
};

static float fFreqlist[] = {
	261.63f,
	277.18f,
	293.66f,
	311.13f,
	329.63f,
	349.23f,
	369.99f,
	392.00f,
	415.30f,
	440.00f,
	466.16f,
	493.88f,
};

int muGetInstrumentName(char *pName, int iInstr)
{
	if (iInstr < 0 || iInstr > 127)
		return FALSE;
	strcpy(pName, szPatchList[iInstr]);
	return TRUE;
}

int muGetDrumName(char *pName, int iInstr)
{
	if (iInstr < 0 || iInstr > 127)
		return FALSE;
	strcpy(pName, szGMDrums[iInstr]);
	return TRUE;
}

int muGetMIDIMsgName(char *pName, MidiMessage iMsg)
{
	switch(iMsg)
		{
		case	messageNoteOff:
				strcpy(pName, "Note off");
				break;

		case	messageNoteOn:
				strcpy(pName, "Note on");
				break;

		case	messageNoteKeyPressure:
				strcpy(pName, "Note key pressure");
				break;

		case	messageSetParameter:
				strcpy(pName, "Set parameter");
				break;

		case	messageSetProgram:
				strcpy(pName, "Set program");
				break;

		case	messageChangePressure:
				strcpy(pName, "Change pressure");
				break;

		case	messageSetPitchWheel:
				strcpy(pName, "Set pitch wheel");
				break;

		case	messageMetaEvent:
				strcpy(pName, "Meta event");
				break;

		case	messageSysEx1:
				strcpy(pName, "SysEx1");
				break;

		case	messageSysEx2:
				strcpy(pName, "SysEx2");
				break;

		default:
				return FALSE;
		}
	return TRUE;
}

int muGetControlName(char *pName, MidiControlCommand iCC)
{
	if (iCC < 0 || iCC > 127)
		return FALSE;
	strcpy(pName, szCCList[iCC]);
	return TRUE;
}

int muGetKeySigName(char *pName, MidiNote iKey)
{
static char *iKeysList[2][8] = {
{"C ", "G ", "D ", "A ", "E ", "B ", "F#", "C#", },
{"C ", "F ", "Bb", "Eb", "Ab", "Db", "Gb", "Cb", },
};

int iRootNum = (iKey&7);
int iFlats = (iKey&noteMaskNeg);
int iMin = (iKey&noteMaskMin);

	strcpy(pName,iKeysList[iFlats?1:0][iRootNum]);
	strcat(pName,iMin?" Min":" Maj");
	return TRUE;
}

int muGetTextName(char *pName, MidiTextInfo iEvent)
{
	if (iEvent<1 || iEvent>7)	return FALSE;
	return muGetMetaName(pName, (MidiMetaInfo)iEvent);
}

int muGetMetaName(char *pName, MidiMetaInfo iEvent)
{
	switch(iEvent)
		{
		case	metaInfoSequenceNumber:	strcpy(pName, "Sequence Number");	break;
		case	metaInfoTextEvent:		strcpy(pName, "Text Event");		break;
		case	metaInfoCopyright:		strcpy(pName, "Copyright");			break;
		case	metaInfoTrackName:		strcpy(pName, "Track Name");		break;
		case	metaInfoInstrument:		strcpy(pName, "Instrument");		break;
		case	metaInfoLyric:			strcpy(pName, "Lyric");				break;
		case	metaInfoMarker:			strcpy(pName, "Marker");			break;
		case	metaInfoCuePoint:		strcpy(pName, "Cue Point");			break;
		case	metaInfoMIDIPort:		strcpy(pName, "MIDI Port");		 break;
		case	metaInfoEndSequence:	strcpy(pName, "End Sequence");		break;
		case	metaInfoSetTempo:		strcpy(pName, "Set Tempo");			break;
		case	metaInfoSMPTEOffset:	strcpy(pName, "SMPTE Offset");		break;
		case	metaInfoTimeSig:		strcpy(pName, "Time Sig");			break;
		case	metaInfoKeySig:			strcpy(pName, "Key Sig");			break;
		case	metaInfoSequencerSpecific:	strcpy(pName, "Sequencer Specific");	break;
		default:	return FALSE;
		}
	return TRUE;

}

int muGetNoteFromName(const char *pName)
{
int note_map[] = {9, 11, 0, 2, 4, 5, 7};
char *p, cpy[16];
int note=0;

	strncpy(cpy, pName, 15);
	cpy[15] = '\0';
	p = cpy;

	while(!isalpha(*p) && *p)
		p++;
	
	if (*p)
		{
		note = toupper(*p)-'A';
		if (note >= 0 && note <= 7)
			{
			note = note_map[note];
			p++;
			if (*p == 'b')
				note--, p++;
			else if (*p == '#')
				note++, p++;
			
			note += atoi(p)*12+MIDI_NOTE_C0;
			}
		}
	
	return note;
}

char *muGetNameFromNote(char *pStr, int iNote)
{
	if (!pStr)		return NULL;

	if (iNote<0 || iNote>127)
		strcpy(pStr, "ERR");
	else
		sprintf(pStr, "%s%d", szNoteName[iNote%12], ((iNote-MIDI_NOTE_C0)/12));
	
	return pStr;
}

float muGetFreqFromNote(int iNote)
{
int oct = iNote/12-5;
float freq;

	if (iNote<0 || iNote>127)	return 0;

	freq = fFreqlist[iNote%12];
	
	while(oct > 0)
		freq *= 2.0f, oct--;
	
	while(oct < 0)
		freq /= 2.0f, oct++;
	
	return freq;
}

int muGetNoteFromFreq(float fFreq)
{
int iNote, iBestNote=0;
float fDiff=20000, f;

	for(iNote=0;iNote<127;++iNote)
		{
		f = muGetFreqFromNote(iNote);
		f -= fFreq; if (f<0) f=-f;
		if (f < fDiff)
			{
			fDiff = f; 
			iBestNote = iNote;
			}
		}
		
	return iBestNote;
}


int muGuessChord(const int *pNoteStatus, const int channel, const int lowRange, const int highRange) {
	int octave[24];
	int i;
	int lowestNote=999;
	int startNote = 999;
	int chordRoot = 0;
	int chordType = 0;
	int chordAdditions = 0;

	for(i=0;i<24;++i) {
		octave[i] = 0;
	}

	for(i=lowRange;i<=highRange;++i) {
		if (pNoteStatus[channel*128 + i]) {
			if (i<lowestNote) {
				lowestNote = i;
			}
			++octave[i%12];
			++octave[i%12+12];
			if ((i%12) < startNote) {
				startNote = i%12;
			}
		}
	}

	if (lowestNote == 999) {
		return -1;
	}

	lowestNote %= 12;
	
	if (octave[startNote+3] && octave[startNote+8]) {
		chordRoot = startNote+8;
		chordType = CHORD_TYPE_MAJOR;
	} else if (octave[startNote+5] && octave[startNote+9]) {
		chordRoot = startNote+5;
		chordType = CHORD_TYPE_MAJOR;
	} else if (octave[startNote+4] && octave[startNote+7]) {
		chordRoot = startNote;
		chordType = CHORD_TYPE_MAJOR;
	} else if (octave[startNote+4] && octave[startNote+9]) {
		chordRoot = startNote+9;
		chordType = CHORD_TYPE_MINOR;
	} else if (octave[startNote+5] && octave[startNote+8]) {
		chordRoot = startNote+5;
		chordType = CHORD_TYPE_MINOR;
	} else if (octave[startNote+3] && octave[startNote+7]) {
		chordRoot = startNote;
		chordType = CHORD_TYPE_MINOR;
	} else if (octave[startNote+3] && octave[startNote+6]) {
		chordRoot = lowestNote;
		chordType = CHORD_TYPE_DIM;
	} else if (octave[startNote+6] && octave[startNote+9]) {
		chordRoot = lowestNote;
		chordType = CHORD_TYPE_DIM;
	} else if (octave[startNote+4] && octave[startNote+8]) {
		chordRoot = lowestNote;
		chordType = CHORD_TYPE_AUG;
	}
	if (octave[chordRoot + 10]) {
		chordAdditions |= CHORD_ADD_7TH;
	}
	if (octave[chordRoot + 11]) {
		chordAdditions |= CHORD_ADD_MAJ7TH;
	}
	if (octave[chordRoot + 2]) {
		chordAdditions |= CHORD_ADD_9TH;
	}

	chordRoot %= 12;

	if (chordType == 0) {
		return -1;
	}

	return chordRoot | chordType | chordAdditions | (lowestNote<<16);
}

char *muGetChordName(char *str, int chord) {
	int root = chord & CHORD_ROOT_MASK;
	int bass = (chord & CHORD_BASS_MASK) >> 16;

	if (root < 0 || root > 11) {
		root = 0;
	}

	if (bass < 0 || bass > 11) {
		bass = 0;
	}

	strcpy(str, szNoteName[root]);

	switch(chord & CHORD_TYPE_MASK) {
		case CHORD_TYPE_MAJOR:
			break;
		case CHORD_TYPE_MINOR:
			strcat(str, "m");
			break;
		case CHORD_TYPE_AUG:
			strcat(str, " aug");
			break;
		case CHORD_TYPE_DIM:
			strcat(str, " dim");
			break;
	}

	if (chord & CHORD_ADD_7TH) {
		strcat(str, "+7");
	}
	if (chord & CHORD_ADD_9TH) {
		strcat(str, "+9");
	}
	if (chord & CHORD_ADD_MAJ7TH) {
		strcat(str, "+7M");
	}
	
	if (bass != root) {
		strcat(str, "/");
		strcat(str, szNoteName[bass]);
	}

	return str;
}