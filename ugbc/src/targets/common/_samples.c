/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../../ugbc.h"

#include <stdio.h>
#include <sndfile.h>

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

Variable * samples_load_to_variable( Environment * _environment, char * _filename, char * _alias, int _bank_expansion ) {

    Variable * result = variable_temporary( _environment, VT_SAMPLES, "(samples)");

    // SNDFILE*  sf_open    (const char *path, int mode, SF_INFO *sfinfo) ;
    // The sf_open() function opens the sound file at the specified path. The filename is byte encoded, 
    // but may be utf-8 on Linux, while on Mac OS X it will use the filesystem character set. 
    // On Windows, there is also a Windows specific sf_wchar_open() that takes a UTF16_BE encoded filename.

    SF_INFO sfInfo;
    memset( &sfInfo, 0, sizeof(SF_INFO) );
    SNDFILE * sndFile = sf_open( _filename, SFM_READ, &sfInfo) ;

    if ( !sndFile ) {
        CRITICAL_CANNOT_LOAD_SAMPLES(_filename);
    }

    if ( sfInfo.channels > 1 ) {
        CRITICAL_CANNOT_LOAD_STEREO_SAMPLES(_filename);
    }

    unsigned char * samplesBuffer = malloc( sfInfo.frames + 1 );
    memset( samplesBuffer, 0, sfInfo.frames + 1 );
    short sample = 0;
    for( int i = 0; i<sfInfo.frames; ++i ) {
        sf_read_short ( sndFile, &sample, 1 );
        samplesBuffer[i] = (unsigned char) ( 8 + ( sample >> 12 ) );
    } 

    samplesBuffer[sfInfo.frames] = 0;
    
    variable_store_buffer( _environment, result->name, samplesBuffer, sfInfo.frames, 0 );

    // The SF_INFO structure is for passing data between the calling function and the library when 
    // opening a file for reading or writing. It is defined in sndfile.h as follows:

    // typedef struct
    // {    sf_count_t  frames ;     /* Used to be called samples. */
    //         int         samplerate ;
    //         int         channels ;
    //         int         format ;
    //         int         sections ;
    //         int         seekable ;
    //     } SF_INFO ;

    // When opening a file for read, the format field should be set to zero before calling sf_open(). 
    // The only exception to this is the case of RAW files where the caller has to set the samplerate, 
    // channels and format fields to valid values. All other fields of the structure are filled in by the library.

    // Note: The libsndfile library will reject values ​​for field channels that are greater than 1024. These 
    // value ​​represent the maximum theoretical limit and may be less for specific formats.

    // Name	Value	Description
    // Major formats.	 	 
    // SF_FORMAT_WAV	0x010000	Microsoft WAV format (little endian).
    // SF_FORMAT_AIFF	0x020000	Apple/SGI AIFF format (big endian).
    // SF_FORMAT_AU	0x030000	Sun/NeXT AU format (big endian).
    // SF_FORMAT_RAW	0x040000	RAW PCM data.
    // SF_FORMAT_PAF	0x050000	Ensoniq PARIS file format.
    // SF_FORMAT_SVX	0x060000	Amiga IFF / SVX8 / SV16 format.
    // SF_FORMAT_NIST	0x070000	Sphere NIST format.
    // SF_FORMAT_VOC	0x080000	VOC files.
    // SF_FORMAT_IRCAM	0x0A0000	Berkeley/IRCAM/CARL
    // SF_FORMAT_W64	0x0B0000	Sonic Foundry’s 64 bit RIFF/WAV
    // SF_FORMAT_MAT4	0x0C0000	Matlab (tm) V4.2 / GNU Octave 2.0
    // SF_FORMAT_MAT5	0x0D0000	Matlab (tm) V5.0 / GNU Octave 2.1
    // SF_FORMAT_PVF	0x0E0000	Portable Voice Format
    // SF_FORMAT_XI	0x0F0000	Fasttracker 2 Extended Instrument
    // SF_FORMAT_HTK	0x100000	HMM Tool Kit format
    // SF_FORMAT_SDS	0x110000	Midi Sample Dump Standard
    // SF_FORMAT_AVR	0x120000	Audio Visual Research
    // SF_FORMAT_WAVEX	0x130000	MS WAVE with WAVEFORMATEX
    // SF_FORMAT_SD2	0x160000	Sound Designer 2
    // SF_FORMAT_FLAC	0x170000	FLAC lossless file format
    // SF_FORMAT_CAF	0x180000	Core Audio File format
    // SF_FORMAT_WVE	0x190000	Psion WVE format
    // SF_FORMAT_OGG	0x200000	Xiph OGG container
    // SF_FORMAT_MPC2K	0x210000	Akai MPC 2000 sampler
    // SF_FORMAT_RF64	0x220000	RF64 WAV file
    // SF_FORMAT_MPEG	0x230000	MPEG-1/2 audio stream
    // Subtypes.	 	 
    // SF_FORMAT_PCM_S8	0x0001	Signed 8 bit data
    // SF_FORMAT_PCM_16	0x0002	Signed 16 bit data
    // SF_FORMAT_PCM_24	0x0003	Signed 24 bit data
    // SF_FORMAT_PCM_32	0x0004	Signed 32 bit data
    // SF_FORMAT_PCM_U8	0x0005	Unsigned 8 bit data (WAV and RAW only)
    // SF_FORMAT_FLOAT	0x0006	32 bit float data
    // SF_FORMAT_DOUBLE	0x0007	64 bit float data
    // SF_FORMAT_ULAW	0x0010	U-Law encoded.
    // SF_FORMAT_ALAW	0x0011	A-Law encoded.
    // SF_FORMAT_IMA_ADPCM	0x0012	IMA ADPCM.
    // SF_FORMAT_MS_ADPCM	0x0013	Microsoft ADPCM.
    // SF_FORMAT_GSM610	0x0020	GSM 6.10 encoding.
    // SF_FORMAT_VOX_ADPCM	0x0021	OKI / Dialogix ADPCM
    // SF_FORMAT_NMS_ADPCM_16	0x0022	16kbs NMS G721-variant encoding.
    // SF_FORMAT_NMS_ADPCM_24	0x0023	24kbs NMS G721-variant encoding.
    // SF_FORMAT_NMS_ADPCM_32	0x0024	32kbs NMS G721-variant encoding.
    // SF_FORMAT_G721_32	0x0030	32kbs G721 ADPCM encoding.
    // SF_FORMAT_G723_24	0x0031	24kbs G723 ADPCM encoding.
    // SF_FORMAT_G723_40	0x0032	40kbs G723 ADPCM encoding.
    // SF_FORMAT_DWVW_12	0x0040	12 bit Delta Width Variable Word encoding.
    // SF_FORMAT_DWVW_16	0x0041	16 bit Delta Width Variable Word encoding.
    // SF_FORMAT_DWVW_24	0x0042	24 bit Delta Width Variable Word encoding.
    // SF_FORMAT_DWVW_N	0x0043	N bit Delta Width Variable Word encoding.
    // SF_FORMAT_DPCM_8	0x0050	8 bit differential PCM (XI only)
    // SF_FORMAT_DPCM_16	0x0051	16 bit differential PCM (XI only)
    // SF_FORMAT_VORBIS	0x0060	Xiph Vorbis encoding.
    // SF_FORMAT_OPUS	0x0064	Xiph/Skype Opus encoding.
    // SF_FORMAT_ALAC_16	0x0070	Apple Lossless Audio Codec (16 bit).
    // SF_FORMAT_ALAC_20	0x0071	Apple Lossless Audio Codec (20 bit).
    // SF_FORMAT_ALAC_24	0x0072	Apple Lossless Audio Codec (24 bit).
    // SF_FORMAT_ALAC_32	0x0073	Apple Lossless Audio Codec (32 bit).
    // SF_FORMAT_MPEG_LAYER_I	0x0080	MPEG-1 Audio Layer I.
    // SF_FORMAT_MPEG_LAYER_II	0x0081	MPEG-1 Audio Layer II.
    // SF_FORMAT_MPEG_LAYER_III	0x0082	MPEG-2 Audio Layer III.
    // Endian-ness options.	 	 
    // SF_ENDIAN_FILE	0x00000000	Default file endian-ness.
    // SF_ENDIAN_LITTLE	0x10000000	Force little endian-ness.
    // SF_ENDIAN_BIG	0x20000000	Force big endian-ness.
    // SF_ENDIAN_CPU	0x30000000	Force CPU endian-ness.
    // SF_FORMAT_SUBMASK	0x0000FFFF	 
    // SF_FORMAT_TYPEMASK	0x0FFF0000	 
    // SF_FORMAT_ENDMASK	0x30000000	 

    sf_close( sndFile );

    return result;

}
