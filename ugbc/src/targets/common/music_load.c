/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
#include "../../libs/midi.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>LOAD MUSIC(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 */
/* <usermanual>
@keyword LOAD MUSIC

@english

@italian

@syntax = LOAD MUSIC([filename])
@syntax = LOAD MUSIC([filename] AS [alias])

@example fugue = LOAD MUSIC("fugue.imf")
@example fugueAnotherCopy = LOAD MUSIC("fugue.imf" as "fugue2")

@target all
</usermanual> */
Variable * music_load( Environment * _environment, char * _filename, char * _alias, int _bank_expansion ) {

    if ( _environment->tenLinerRulesEnforced ) {
        CRITICAL_10_LINE_RULES_ENFORCED( "LOAD MUSIC");
    }

    LoadedFile * first = _environment->loadedFiles;
    char *lookfor = _filename;
    if ( _alias ) {
        lookfor = _alias;
    }
    while( first ) {
        if ( strcmp(lookfor, first->fileName ) == 0 ) {
            return first->variable;
        }
        first = first->next;
    }

    Variable * result = variable_temporary( _environment, VT_MUSIC, "(buffer)" );

    char * imfBuffer = NULL;
    int size = 0;

    MidiFile * mf = midiFileOpen(_filename);

    // If the file to read is a MIDI...
    if ( mf ) {

        imfBuffer = malloc( 16 * MAX_TEMPORARY_STORAGE );
        int tempo = 81;
        int ppq = 240;
        int done = 0;
        int i = 0;

        // Prepare to read all tracks of the file.
        int iNum = midiReadGetNumTracks(mf);

        // Read each track indipendently
        MidiMessagePayload * msg = malloc( iNum * sizeof( MidiMessagePayload ) );
        memset( msg, 0, iNum * sizeof( MidiMessagePayload ) );
        for( int i=0; i<iNum; ++i ) {
    		midiReadInitMessage(&msg[i]);
        }

        // We take note if the track is finished
        int * finished = malloc( iNum * sizeof( int ) );
        memset( finished, 0, iNum * sizeof( int ) );

        // We take note if the track has been used
        int * used = malloc( iNum * sizeof( int ) );
        memset( used, 0xff, iNum * sizeof( int ) );

        // int channel = 0;
        int * lastNoteOnChannel = malloc( iNum * sizeof( int ) );
        memset( lastNoteOnChannel, 0, iNum * sizeof( int ) );

        // Used channels
        int usedChannel[MAX_AUDIO_CHANNELS];
        memset( usedChannel, 0, MAX_AUDIO_CHANNELS * sizeof( int ) );

        // Current position examinated
        int pos = 0;

        // Repeat until the MIDI file is finished
		while( ! done ) {

            // printf("%d:", pos );

            // For each track we must check if the current message
            // is "up to date" in respect of the current position.
            // If not, we must read another message from the MIDI
            // file for that track.
            for( int i=0; i<iNum; ++i ) {
                if ( ! finished[i] ) {
                    // If the current position is AFTER the one
                    // in the message, and the message has been
                    // used, the message is outdated.
                    if ( msg[i].dwAbsPos < pos ) {
                        while( msg[i].dwAbsPos < pos ) {
                            // Try to read the next message. If the track
                            // is finished, we take note of that.
                            if ( !midiReadGetNextMessage(mf, i, &msg[i]) ) {
                                finished[i] = 1;
                                // printf("E[----]");
                                break;
                            }
                        }
                        if ( !finished[i] ) {
                            used[i] = 0;
                            // printf("R[%4.4d]", msg[i].dwAbsPos);
                        }
                    } else {
                        // printf(".[    ]");
                    }
                } else {
                    // printf("E[----]");
                }
            }

            // printf("\n");

            // Now we check if the MIDI file is ended, that is
            // if every track is finished.
            for(i=0; i<iNum; ++i ) {
                if ( !finished[i] ) 
                    break;
            }
            if ( i >= iNum ) {
                done = 1;
            }

            // If the MIDI file is not finished...
            if ( ! done ) {

                // printf(" ");

                // channel = 0;

                // For each track...
                for( i=0; i<iNum; ++i ) {

                    // Skip if the track has been already used.
                    if ( used[i] ) {
                        // printf("u");
                        continue;
                    }

                    // Skip if message is after this moment
                    if ( msg[i].dwAbsPos > pos ) {
                        // printf("a");
                        continue;
                    }

                    // printf(" %.6ld ", msg.dwAbsPos);
                    int ev;
                    if (msg[i].bImpliedMsg)
                        { ev = msg[i].iImpliedMsg; }
                    else
                        { ev = msg[i].iType; }

                    // if (muGetMIDIMsgName(str, ev))	printf("%s\t", str);
                    // Free instructions:
                    // 0xxxxxxx     WAIT JIFFIES[x]
                    // 10xxxxxx     AVAILABLE
                    // 110xxxxx     NOTE ON[channel][note]
                    // 1110xxxx     NOTE OFF[channel]
                    // 11110xxx     AVAILABLE
                    // 111110xx     AVAILABLE
                    // 1111110x     AVAILABLE
                    // 11111110     AVAILABLE
                    // 11111111     AVAILABLE
                    switch(ev) {
                        case	messageNoteOff: {
                            // 1110cccc
                            // printf( "NOTE OFF %d\n", msg[i].MsgData.NoteOff.iChannel);
                            int j;
                            for( j=0; j<MAX_AUDIO_CHANNELS; ++j ) {
                                if ( usedChannel[j] && lastNoteOnChannel[j] == msg[i].MsgData.NoteOff.iNote ) {
                                    lastNoteOnChannel[j] = 0;
                                    usedChannel[j] = 0;
                                    imfBuffer[size++] = 0xe0 | ( /*msg[i].MsgData.NoteOff.iChannel*/ ( 1 << ( j & MAX_AUDIO_CHANNELS ) ) );
                                    // printf("(%d) <%1.1x> ", pos, j );
                                    // printf("F");
                                    break;
                                }
                            }
                            if ( j >= iNum ) {
                                // printf("(%d) <<%1.1x>> ", pos, j );
                            }
                            break;
                        }
                        case	messageNoteOn:
                            if ( msg[i].MsgData.NoteOn.iVolume > 0 ) {
                                // 1100cccc
                                // printf( "NOTE ON %d, %d\n", msg[i].MsgData.NoteOff.iChannel, msg[i].MsgData.NoteOn.iNote);
                                int j;
                                for (j=0; j<MAX_AUDIO_CHANNELS; ++j ) {
                                    if ( ! usedChannel[j] ) break;
                                }
                                // printf( "j = %d", j );
                                if ( j<MAX_AUDIO_CHANNELS ) {
                                    usedChannel[j] = 1;
                                    imfBuffer[size++] = 0xc0 | ( /*msg[i].MsgData.NoteOff.iChannel*/ ( 1 << ( j & MAX_AUDIO_CHANNELS ) ) );
                                    // nnnnnnnn
                                    imfBuffer[size++] = msg[i].MsgData.NoteOn.iNote & 0xff;
                                    // printf("(%d) [%1.1x][%2.2x] ", pos, j, msg[i].MsgData.NoteOn.iNote & 0xff );
                                    lastNoteOnChannel[j] = msg[i].MsgData.NoteOn.iNote;
                                } else {
                                    // printf("(%d) [[%1.1x][%2.2x]] ", pos, j, msg[i].MsgData.NoteOn.iNote & 0xff );
                                }
                            } else {
                                // 1110cccc
                                // printf( "NOTE OFF %d\n", msg[i].MsgData.NoteOff.iChannel);
                                int j;
                                for( j=0; j<MAX_AUDIO_CHANNELS; ++j ) {
                                    if ( usedChannel[j] && lastNoteOnChannel[j] == msg[i].MsgData.NoteOff.iNote ) {
                                        usedChannel[j] = 0;
                                        lastNoteOnChannel[j] = 0;
                                        imfBuffer[size++] = 0xe0 | ( /*msg[i].MsgData.NoteOff.iChannel*/ ( 1 << ( j & MAX_AUDIO_CHANNELS ) ) );
                                        // printf("(%d) <%1.1x> ", pos, j );
                                        break;
                                    }
                                }
                                if ( j >= MAX_AUDIO_CHANNELS ) {
                                    // printf("(%d) <<%1.1x>> ", pos, j );
                                }
                                break;
                            }
                            break;
                        case	messageNoteKeyPressure:
                        case	messageSetParameter:
                        case	messageSetProgram:
                        case	messageChangePressure:
                        case	messageSetPitchWheel:
                            // printf("#");
                            break;
                        case	messageMetaEvent:
                            switch(msg[i].MsgData.MetaEvent.iType) {
                                case	metaInfoMIDIPort:
                                case	metaInfoSequenceNumber:
                                case	metaInfoTextEvent:
                                case	metaInfoCopyright:
                                case	metaInfoTrackName:
                                case	metaInfoInstrument:
                                case	metaInfoLyric:
                                case	metaInfoMarker:
                                case	metaInfoCuePoint:
                                case	metaInfoEndSequence:
                                case	metaInfoSMPTEOffset:
                                case	metaInfoTimeSig:
                                case	metaInfoKeySig:
                                case	metaInfoSequencerSpecific:
                                    // printf("#");
                                    break;
                                case	metaInfoSetTempo:
                                        // printf( "TEMPO %d\n", msg[i].MsgData.MetaEvent.Data.Tempo.iBPM);
                                        tempo = msg[i].MsgData.MetaEvent.Data.Tempo.iBPM;
                                        // printf("T");
                                        break;
                                }
                            break;

                        case	messageSysEx1:
                        case	messageSysEx2:
                                // printf("#");
                                break;
                    }

                    used[i] = 1;

                    if ( size > 16 * MAX_TEMPORARY_STORAGE ) {
                        CRITICAL("out of memory");
                    }

                }

                // printf("\n");

                // Now check for unused messages, to find out
                // the nearest in terms of position.

                int minPos = pos + 0xffffff;
                // printf(" ");
                for( int i=0; i<iNum; ++i ) {
                    // printf("%1.1x", used[i]);
                    if ( !finished[i] && msg[i].dwAbsPos < minPos ) {
                        minPos = msg[i].dwAbsPos;
                    }
                }
                // printf("\n");

                if ( minPos > pos && minPos < (pos + 0xffffff) ) {
                    // printf("%d:", pos);
                    int jiffies = ( ( minPos - pos ) * 600 ) / ( tempo * ppq );
                    while( jiffies > 127 ) {
                        // printf("P");
                        // printf( "PAUSE 127\n");
                        // printf(", ");
                        imfBuffer[size++] = 0x7f;
                        jiffies -= 127;
                        if ( size > 16 * MAX_TEMPORARY_STORAGE ) {
                            CRITICAL("out of memory");
                        }
                    }
                    // printf("P\n");
                    // printf("; ");
                    imfBuffer[size++] = jiffies;
                    pos = minPos;
                    if ( size > 16 * MAX_TEMPORARY_STORAGE ) {
                        CRITICAL("out of memory");
                    }
                } else {
                    ++pos;
                }

            }

        }

        for( int i=0; i<iNum; ++i ) {
            midiReadFreeMessage(&msg[i]);
        }

        midiFileClose(mf);

    } else {

        check_if_filename_is_valid( _environment,  _filename );

        FILE * file = fopen( _filename, "rb" );

        if ( !file ) {
            CRITICAL_LOAD_MISSING_FILE( _filename );
        }
        
        fseek( file, 0, SEEK_END );
        size = ftell( file );
        fseek( file, 0, SEEK_SET );

        imfBuffer = malloc( size );

        (void)!fread( imfBuffer, size, 1, file );

        fclose( file );

    }

    variable_store_buffer( _environment, result->name, imfBuffer, size, 0 );

    if ( _bank_expansion && _environment->expansionBanks ) {

        Bank * bank = _environment->expansionBanks;

        while( bank ) {
            if ( bank->remains > result->size ) {
                break;
            }
            bank = bank->next;
        } 

        if ( ! bank ) {
            CRITICAL_EXPANSION_OUT_OF_MEMORY_LOADING( _filename );
        }

        result->bankAssigned = bank->id;
        result->absoluteAddress = bank->address;
        result->residentAssigned = _bank_expansion;
        result->variableUniqueId = UNIQUE_RESOURCE_ID;
        memcpy( &bank->data[bank->address], result->valueBuffer, result->size );

        bank->address += result->size;
        bank->remains -= result->size;
        if ( _environment->maxExpansionBankSize[_bank_expansion] < result->size ) {
            _environment->maxExpansionBankSize[_bank_expansion] = result->size;
        }

    }

    LoadedFile * loaded = malloc( sizeof( LoadedFile ) );
    loaded->next = first;
    loaded->variable = result;
    loaded->fileName = lookfor;
    _environment->loadedFiles = loaded;

    if ( _alias ) {
        const_define_numeric( _environment, _alias, UNIQUE_ID );
    }
    
    return result;

}
