/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
#include "../../libs/msc1.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

// SET VOLUME, 2 bytes, 
//          FORMAT: 
//              1110cccc -> cccc is hardware audio channel
//              nnnnnnnn -> nnnnnnnn is the value (0...255)
// #define IMF_SET_VOLUME_CHANNEL( channel ) 0xe0 | ( ( 1 << ( ( channel ) % ( MAX_AUDIO_CHANNELS ) ) ) )

// NOTE OFF, 1 byte, FORMAT: 1110cccc -> cccc is hardware audio channel
#define IMF_NOTE_OFF( channel ) 0xe0 | ( ( 1 << ( ( channel ) % ( MAX_AUDIO_CHANNELS ) ) ) )

// NOTE ON, 3 bytes, 
//          FORMAT: 
//              110ccccc -> cccc is hardware audio channel
//              nnnnnnnn -> nnnnnnnn is the note value
//              nnnnnnnn -> nnnnnnnn is the volume (0...255)
#define IMF_NOTE_ON_CHANNEL( channel ) 0xc0 | ( ( 1 << ( ( channel ) % ( MAX_AUDIO_CHANNELS ) ) ) )
#define IMF_NOTE_ON_NOTE( note ) ( ( note ) & 0xff )
#define IMF_SET_VOLUME_VALUE( value ) ( ( value ) & 0xff )

// SET PROGRAM, 2 bytes, 
//          FORMAT: 
//              10cccccc -> cccc is hardware audio channel
//              pppppppp -> pppppppp is the program value
#define IMF_SET_PROGRAM_CHANNEL( channel ) 0x80 | ( ( 1 << ( ( channel ) % ( MAX_AUDIO_CHANNELS ) ) ) )
#define IMF_SET_PROGRAM_PROGRAM( program ) ( ( program ) & 0xff )

// DELAY, 1 byte, FORMAT: 0dddddddd -> dddddddd is the delay (in jiffies)
#define IMF_DELAY( jiffies ) ( ( jiffies ) & 0x7f )

// Maximum size of an IMF stream.
#define IMF_MAX_STREAM_SIZE ( 16 * MAX_TEMPORARY_STORAGE );

// Maximum number of MIDI channels
#define MAX_MIDI_CHANNELS 127

// Current position in the produced IMF stream.
static int imfStreamPos = 0;

// Number of tracks in the MIDI files
static int numMidiTracks;

// Store if the track is finished
static int * finishedTrack;

// Store if the track has been used
static int * usedTrack;

// Store the last note played on that IMF channel
static int * lastNoteOnChannel;

// Store if IMF channel has been used.
static int usedChannel[MAX_AUDIO_CHANNELS];

// Store bounded MIDI channel
static int * lastProgramOnMIDITrack;

// Store bounded IMF channel
static int lastProgramOnChannel[MAX_AUDIO_CHANNELS];

// Store bounded MIDI channel
static int lastChannelOnChannel[MAX_AUDIO_CHANNELS];

// Tempo of the MIDI file
static int tempo = 81;

// IMF buffer
static char * imfBuffer = NULL;

// This routine will check if the IMF stream can be stored
// into the allocated IMF stream.

static int decode_midi_inside_memory_limits( ) {

    return imfStreamPos < IMF_MAX_STREAM_SIZE;

}

// This routine will help to decode the (overall) tempo of the MIDI track.
// It returns always 0.
static int decode_midi_payload_set_tempo( MidiMessagePayload * _payload ) {

    // printf( "iBPM = %d\n", _payload->MsgData.MetaEvent.Data.Tempo.iBPM );

    tempo = _payload->MsgData.MetaEvent.Data.Tempo.iBPM;

    return 0;

}

// This routine will help to decode a single (explicit) NOTE OFF message.
// IMF FORMAT: 1 byte = 1110cccc
// It returns 0 if nothing has been produced on the stream.
static int decode_midi_payload_note_off( MidiMessagePayload * _payload ) {

    // First of all, we have to select which IMF channel we have to
    // turn off. Since it is possibile that the MIDI channel has been
    // ignored, this command could translate in a "NOP", that is:
    // nothing is generated on IMF stream.
    int imfChannelIndex;
    for( imfChannelIndex=0; imfChannelIndex<MAX_AUDIO_CHANNELS; ++imfChannelIndex ) {

        // If the IMF channel is really used, and the note played on that IMF channel
        // is the same as the MIDI channel, then...
        if ( usedChannel[ imfChannelIndex ] && lastNoteOnChannel[ imfChannelIndex ] == _payload->MsgData.NoteOff.iNote ) {

            // Turn off the note.
            lastNoteOnChannel[ imfChannelIndex ] = 0;

            // Free IMF channel.
            usedChannel[ imfChannelIndex ] = 0;

            // Produce the data on the IMF stream.
            imfBuffer[imfStreamPos++] = IMF_NOTE_OFF( imfChannelIndex );

            // printf( "%d: NOTE OFF\n", imfChannelIndex );

            // printf( " -> note off on %d\n", imfChannelIndex );

            break;

        }

    }

    if ( imfChannelIndex >= MAX_AUDIO_CHANNELS ) {
        // printf( " ! NOTE OFF skipped since there is no audio channel\n" );
    }

    // printf( "\n" );

    return ( imfChannelIndex < MAX_AUDIO_CHANNELS );

}

// This routine will help to decode a single (explicit) NOTE ON message.
// In order to decode also the NOTE ON as NOTE OFF case, this routine
// could decode using both formats:
// IMF NOTE OFF FORMAT: 1 byte = 1110cccc
// IMF NOTE ON FORMAT: 2 bytes = 1110cccc; nnnnnnnn
// The routine returns 0 if nothing is produced, 1 if NOTE OFF has been
// produced, 2 if NOTE ON has been produced.
static int decode_midi_payload_note_on( MidiMessagePayload * _payload ) {

    // First of all, we have to distinguish between a real NOTE ON
    // and a NOTE ON used to "mute" the previous NOTE ON (and it is
    // like a NOTE OFF). All of this is done by using the volume as
    // indicator. A volume of 0 means "NOTE OFF", otherwise is a
    // NOTE ON.
    if ( _payload->MsgData.NoteOn.iVolume > 0 ) {

        int alreadyAllocated = MAX_AUDIO_CHANNELS;
        int imfChannelIndex = 0;

        // printf( "LOOKING FOR MIDI CHANNEL = %2.2x\n", _payload->MsgData.NoteOn.iChannel );

        for( imfChannelIndex=0; imfChannelIndex<MAX_AUDIO_CHANNELS; ++imfChannelIndex ) {
            // We exit as soon as we found one.
            if ( lastChannelOnChannel[ imfChannelIndex ] == _payload->MsgData.NoteOn.iChannel &&
                (lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ] != -1) && (lastProgramOnChannel[ imfChannelIndex ] != -1) && (lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ] == lastProgramOnChannel[ imfChannelIndex ])  ) {
                alreadyAllocated = imfChannelIndex;
                // printf( "ALREADY ALLOCATED, IMF = %2.2x, MIDI = %2.2x", alreadyAllocated, _payload->MsgData.NoteOn.iChannel );
                break;
            }
        }

        if ( alreadyAllocated == MAX_AUDIO_CHANNELS ) {

            // We have to look for an already setted channel, and not used.
            for( imfChannelIndex=0; imfChannelIndex<MAX_AUDIO_CHANNELS; ++imfChannelIndex ) {
                // printf( "%d) IMF: %2.2x MIDI: %2.2x\n", imfChannelIndex, lastProgramOnChannel[ imfChannelIndex ], lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ] );
                // We exit as soon as we found one.
                if ( (lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ] != -1) && (lastProgramOnChannel[ imfChannelIndex ] != -1) && (lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ] == lastProgramOnChannel[ imfChannelIndex ]) ) {
                    // printf( "%d: POTENTIAL %2.2x (channel=%2.2x)\n", imfChannelIndex, lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ], _payload->MsgData.NoteOn.iChannel );
                    if ( ! usedChannel[ imfChannelIndex ] ) {
                        // printf( "%d: SELECTED!\n", imfChannelIndex );
                        break;
                    }
                }
            }

            if ( imfChannelIndex == MAX_AUDIO_CHANNELS ) {
                // printf( "NONE POTENTIAL\n" );
                // We have to look for a free one. 
                // So we have to look for an unused one.
                for( imfChannelIndex=0; imfChannelIndex<MAX_AUDIO_CHANNELS; ++imfChannelIndex ) {
                    // We exit as soon as we found one.
                    if ( ! usedChannel[ imfChannelIndex ] ) {
                        // printf( "%d: FREE!\n", imfChannelIndex );
                        break;
                    }
                }
            }

        } else {
            imfChannelIndex = alreadyAllocated;
        }

        // If we found a channel...
        if ( imfChannelIndex < MAX_AUDIO_CHANNELS ) {

            // Allocate that channel
            // (note that bounded channels are already allocated)
            usedChannel[ imfChannelIndex ] = 1;

            if ( lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ] != lastProgramOnChannel[ imfChannelIndex ] ) {
                if ( ( lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ] & 0xff ) != 0xff ) {
                    if ( lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ] == 0 ) {
                        lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ] = IMF_INSTRUMENT_CELLO;
                    }
                    imfBuffer[imfStreamPos++] = IMF_SET_PROGRAM_CHANNEL( imfChannelIndex );
                    imfBuffer[imfStreamPos++] = IMF_SET_PROGRAM_PROGRAM( lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ] );
                    // printf( " -> set program $%2.2x on on %d\n", lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ], imfChannelIndex );
                    lastProgramOnChannel[ imfChannelIndex ] = lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ];
                    lastChannelOnChannel[ imfChannelIndex ] = _payload->MsgData.NoteOn.iChannel;
                    // printf( "%d: SET PROGRAM %2.2x (channel=%2.2x)\n", imfChannelIndex, lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ], _payload->MsgData.NoteOn.iChannel );
                } else {
                    lastProgramOnChannel[ imfChannelIndex ] = IMF_INSTRUMENT_CELLO;
                    lastChannelOnChannel[ imfChannelIndex ] = _payload->MsgData.NoteOn.iChannel;
                }
            } else {

            }

            // Produce the 2 bytes data on the stream
            imfBuffer[imfStreamPos++] = IMF_NOTE_ON_CHANNEL( imfChannelIndex );
            imfBuffer[imfStreamPos++] = IMF_NOTE_ON_NOTE( _payload->MsgData.NoteOn.iNote );  

            // printf( "%d: NOTE ON %d [%2.2x]\n", imfChannelIndex, _payload->MsgData.NoteOn.iNote, lastProgramOnChannel[ imfChannelIndex ] );
            
            // Produce the 2 bytes with the volume on the stream
            // imfBuffer[imfStreamPos++] = IMF_SET_VOLUME_CHANNEL( imfChannelIndex );
            imfBuffer[imfStreamPos++] = IMF_SET_VOLUME_VALUE( _payload->MsgData.NoteOn.iVolume );  

            // We have to store, also, the note played on that channel.
            lastNoteOnChannel[ imfChannelIndex ] = _payload->MsgData.NoteOn.iNote;

            // printf( " -> note on on %d\n", imfChannelIndex );

            return 2;
        } else {

            if ( imfChannelIndex >= MAX_AUDIO_CHANNELS ) {
                // printf( " ! NOTE ON skipped since there is no free audio channel\n" );
            }

            return 0;
        }

    } else {
        return decode_midi_payload_note_off( _payload );
    }

    // printf( "\n" );

}

// This routine will help to decode a single (explicit) SET PROGRAM message.
// IMF FORMAT: 2 bytes = 10cccccc; nnnnnnnn
// The routine returns 0 if nothing is produced, 2 if SET PROGRAM
// has been produced.
static int decode_midi_payload_set_program( MidiMessagePayload * _payload ) {

    int imfChannelIndex;

    // printf( "MIDI CHANNEL = %2.2x, PROGRAM = %2.2x\n", _payload->MsgData.ChangeProgram.iChannel, _payload->MsgData.ChangeProgram.iProgram );

    // // Produce the 2 bytes data on the stream
    // imfBuffer[imfStreamPos++] = IMF_SET_PROGRAM_CHANNEL( imfChannelIndex );
    // imfBuffer[imfStreamPos++] = IMF_SET_PROGRAM_PROGRAM( _payload->MsgData.ChangeProgram.iProgram );

    // We have to store, also, the MIDI channel that this program is
    // allocated. This is needed, in order to avoid to play a wrong
    // note on the wrong channel.-
    char str[MAX_TEMPORARY_STORAGE];

    if ( _payload->MsgData.ChangeProgram.iChannel == 10 ) {
        if ( _payload->MsgData.ChangeProgram.iProgram == 0 ) {
            lastProgramOnMIDITrack[ _payload->MsgData.ChangeProgram.iChannel ] = 0;
        } else {
            lastProgramOnMIDITrack[ _payload->MsgData.ChangeProgram.iChannel ] = _payload->MsgData.ChangeProgram.iProgram;
        }
    } else {
        lastProgramOnMIDITrack[ _payload->MsgData.ChangeProgram.iChannel ] = _payload->MsgData.ChangeProgram.iProgram;
    }

    return 0;

}

// This routine will help to decode a single frame of MIDI message, converting
// it into a (simplier) IMF sequence. The method will return the number of
// bytes generated on the IMF stream.
static int decode_midi_payload( MidiMessagePayload * _payload, int _control_only ) {

    // First of all, decode the main event type
    int ev;
    if (_payload->bImpliedMsg) { 
        ev = _payload->iImpliedMsg; 
    } else { 
        ev = _payload->iType; 
    }

    // Based on the event type, we produce a different sequence.
    switch(ev) {
        case	messageNoteOff: 
            // printf( "%4.4x: NOTE OFF iNote = $%2.2x iChannel = $%2.2x\n", _payload->dwAbsPos, _payload->MsgData.NoteOff.iNote, _payload->MsgData.NoteOff.iChannel );
            if ( !_control_only ) {
                return decode_midi_payload_note_off( _payload );
            } else {
                // printf( " ! ignored since control only\n" );   
            }
            break;
        case	messageNoteOn:
            // printf( "%4.4x: NOTE ON iNote = $%2.2x iChannel = $%2.2x iVolume = $%2.2x iProgram = $%2.2x\n", _payload->dwAbsPos, _payload->MsgData.NoteOn.iNote, _payload->MsgData.NoteOn.iChannel, _payload->MsgData.NoteOn.iVolume, lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ] & 0xff );
            if ( !_control_only ) {
                return decode_midi_payload_note_on( _payload );
            } else {
                // printf( " ! ignored since control only\n" );   
            }
            break;
        case	messageSetProgram:
            // printf( "%4.4x: SET PROGRAM iProgram = $%2.2x iChannel = $%2.2x\n", _payload->dwAbsPos, _payload->MsgData.ChangeProgram.iProgram, _payload->MsgData.ChangeProgram.iChannel );
            return decode_midi_payload_set_program( _payload );
            break;
        case	messageNoteKeyPressure:
            // printf( "%4.4x: NOTE KEY PRESSURE\n", _payload->dwAbsPos );
            break;
        case	messageSetParameter:
            // printf( "%4.4x: SET PARAMETER\n", _payload->dwAbsPos );
            break;
        case	messageChangePressure:
            // printf( "%4.4x: CHANGE PRESSURE\n", _payload->dwAbsPos );
            break;
        case	messageSetPitchWheel:
            //  printf( "%4.4x: SET PITCH WHEEL\n", _payload->dwAbsPos );
            break;
        case	messageMetaEvent:
            // printf( "%4.4x: META EVENT -", _payload->dwAbsPos );
            switch(_payload->MsgData.MetaEvent.iType) {
                case	metaInfoMIDIPort:
                    // printf( "metaInfoMIDIPort\n" );
                    break;
                case	metaInfoSequenceNumber:
                    // printf( "metaInfoSequenceNumber\n" );
                    break;
                case	metaInfoTextEvent:
                    // printf( "metaInfoTextEvent\n" );
                    break;
                case	metaInfoCopyright:
                    // printf( "metaInfoCopyright\n" );
                    break;
                case	metaInfoTrackName:
                    // printf( "metaInfoTrackName\n" );
                    break;
                case	metaInfoInstrument:
                    // printf( "metaInfoInstrument\n" );
                    break;
                case	metaInfoLyric:
                    // printf( "metaInfoLyric\n" );
                    break;
                case	metaInfoMarker:
                    // printf( "metaInfoMarker\n" );
                    break;
                case	metaInfoCuePoint:
                    // printf( "metaInfoCuePoint\n" );
                    break;
                case	metaInfoEndSequence:
                    // printf( "metaInfoEndSequence\n" );
                    break;
                case	metaInfoSMPTEOffset:
                    // printf( "metaInfoSMPTEOffset\n" );
                    break;
                case	metaInfoTimeSig:
                    // printf( "metaInfoTimeSig\n" );
                    break;
                case	metaInfoKeySig:
                    // printf( "metaInfoKeySig\n" );
                    break;
                case	metaInfoSequencerSpecific:
                    // printf( "metaInfoSequencerSpecific\n" );
                    break;
                case	metaInfoSetTempo:
                    // printf( "metaInfoSetTempo\n" );
                    return decode_midi_payload_set_tempo( _payload );
                    break;
            }
            break;
        case	messageSysEx1:
            // printf( "%4.4x: SYS EX1\n", _payload->dwAbsPos );
            break;
        case	messageSysEx2:
            // printf( "%4.4x: SYS EX2\n", _payload->dwAbsPos );
            break;
    }

    return 0;

}

Variable * music_load_to_variable( Environment * _environment, char * _filename, char * _alias, int _bank_expansion ) {

    // Reinitialize all parameters for MIDI>IMF decoding.
    imfStreamPos = 0;
    numMidiTracks = 0;
    finishedTrack = NULL;
    usedTrack = NULL;
    lastNoteOnChannel = NULL;
    memset( usedChannel, 0, MAX_AUDIO_CHANNELS * sizeof( int ) );
    lastProgramOnMIDITrack = NULL;
    memset( lastProgramOnChannel, 0, MAX_AUDIO_CHANNELS * sizeof( int ) );
    memset( lastChannelOnChannel, 0, MAX_AUDIO_CHANNELS * sizeof( int ) );
    tempo = 81;
    imfBuffer = NULL;

    Variable * result = variable_temporary( _environment, VT_MUSIC, "(buffer)" );

    int size = 0;
    
    MidiFile * mf = midiFileOpen(_filename);

    // If the file to read is a MIDI...
    if ( mf ) {

        imfBuffer = malloc( 16 * MAX_TEMPORARY_STORAGE );
        int ppq = midiFileGetPPQN(mf);
        int midiConversionDone = 0;
        int track = 0;

        // Prepare to read all tracks of the file.
        int numMidiTracks = midiReadGetNumTracks(mf);

        // Read each track indipendently
        MidiMessagePayload * msg = malloc( numMidiTracks * sizeof( MidiMessagePayload ) );
        memset( msg, 0, numMidiTracks * sizeof( MidiMessagePayload ) );

        // Initialize each track.
        for( track=0; track<numMidiTracks; ++track ) {
    		midiReadInitMessage( &msg[track] );
        }

        // We take note if the track is finished
        finishedTrack = malloc( numMidiTracks * sizeof( int ) );
        memset( finishedTrack, 0, numMidiTracks * sizeof( int ) );

        // We take note if the track has been used
        usedTrack = malloc( numMidiTracks * sizeof( int ) );
        memset( usedTrack, 0xff, numMidiTracks * sizeof( int ) );

        // We take note of the last note on channel
        lastNoteOnChannel = malloc( MAX_AUDIO_CHANNELS * sizeof( int ) );
        memset( lastNoteOnChannel, 0, MAX_AUDIO_CHANNELS * sizeof( int ) );

        // Used channels
        memset( usedChannel, 0, MAX_AUDIO_CHANNELS * sizeof( int ) );

        // Bounded midi channels.
        lastProgramOnMIDITrack = malloc( MAX_MIDI_CHANNELS * sizeof( int ) );
        memset( lastProgramOnMIDITrack, 0xff, MAX_MIDI_CHANNELS * sizeof( int ) );
        memset( lastProgramOnChannel, 0xff, MAX_AUDIO_CHANNELS * sizeof( int ) );
        memset( lastChannelOnChannel, 0xff, MAX_AUDIO_CHANNELS * sizeof( int ) );

        // Current position examinated
        int midiPosition = 0;

        // Repeat until the MIDI file is finished
		while( ! midiConversionDone ) {

            // printf("\n-------------------------------------------------\n" );
            // printf("POSITION %4.4x\n", midiPosition );
            // printf("-------------------------------------------------\n" );

            // For each track we must check if the current message
            // is "up to date" in respect of the current position.
            // If not, we must read another message from the MIDI
            // file for that track.
            for( track=0; track<numMidiTracks; ++track ) {

                // printf(" TRACK %d finished = %d\n", track, finishedTrack[ track ] );

                // If the track has not bneen finished...
                if ( ! finishedTrack[ track ] ) {

                    // printf(" TRACK %d msg position = %4.4x\n", track, msg[track].dwAbsPos );

                    // If the current position is AFTER the one
                    // in the message, and the message has been
                    // used, the message is outdated.
                    if ( msg[track].dwAbsPos < midiPosition ) {

                        // printf(" >> TRANSLATING " );

                        while( msg[track].dwAbsPos < midiPosition ) {

                            // printf(" >> FORWARD " );

                            // Before reading the next message, decode the current
                            // one if of control type.
                            decode_midi_payload( &msg[track], 1 );

                            // Try to read the next message. If the track
                            // is finished, we take note of that.
                            if ( !midiReadGetNextMessage(mf, track, &msg[track]) ) {
                                // printf(" !! EOF " );
                                finishedTrack[track] = 1;
                                break;
                            }
                        }

                        // If the track is not finished, we can consider
                        // it for the next round.
                        if ( !finishedTrack[track] ) {
                            usedTrack[track] = 0;
                        }

                        // printf( "\n" );

                    } else if ( msg[track].dwAbsPos == midiPosition && usedTrack[ track ] ) {

                        // printf(" >> NEXT MESSAGE\n" );

                        // Before reading the next message, decode the current
                        // one if of control type.
                        decode_midi_payload( &msg[track], 1 );

                        // Try to read the next message. If the track
                        // is finished, we take note of that.
                        if ( !midiReadGetNextMessage(mf, track, &msg[track]) ) {
                            // printf(" !! EOF\n" );
                            finishedTrack[track] = 1;
                            break;
                        }

                        // If the track is not finished, we can consider
                        // it for the next round.
                        if ( !finishedTrack[track] ) {
                            usedTrack[track] = 0;
                        }

                    }
                }
            }

            // Now we check if the MIDI file is ended, that is
            // if every track is finished.
            for(track=0; track<numMidiTracks; ++track ) {
                if ( !finishedTrack[track] ) 
                    break;
            }
            if ( track >= numMidiTracks ) {
                midiConversionDone = 1;
            }

            // If the MIDI file is not finished...
            if ( ! midiConversionDone ) {

                // For each track...
                for( track=0; track<numMidiTracks; ++track ) {

                    // printf(" PARSING %d\n", track );

                    // Skip if the track has been already used.
                    if ( usedTrack[track] ) {
                        // printf(" -- skipped since unused track\n" );
                        continue;
                    }

                    // Skip if message is after this moment
                    if ( msg[track].dwAbsPos > midiPosition ) {
                        // printf(" -- skipped since after this position \n" );
                        continue;
                    }

                    decode_midi_payload( &msg[track], 0 );

                    usedTrack[track] = 1;

                    if ( !decode_midi_inside_memory_limits() ) {
                        CRITICAL_MIDI_OUT_OF_MEMORY(_filename);
                    }

                }

                // Now check for unused messages, to find out
                // the nearest in terms of position.
                int midiMinPosition = midiPosition + 0xffffff;
                for( track=0; track<numMidiTracks; ++track ) {
                    if ( !finishedTrack[track] && msg[track].dwAbsPos < midiMinPosition ) {
                        midiMinPosition = msg[track].dwAbsPos;
                    }
                }

                // printf(" NEXT MIN POSITION: %4.4x\n", midiMinPosition );

                // If the minimum position is valid...
                if ( midiMinPosition >= midiPosition && midiMinPosition < (midiPosition + 0xffffff) ) {

                    // just divide 60,000 by your tempo and you will get the number of milliseconds per beat. 
                    // Thereafter you can divide by two for eighth notes or four for sixteenth notes.
                    // microseconds per tick = microseconds per quarter note / ticks per quarter note

                    float kMillisecondsPerBPM = (float)( 60 * 1000 ) / (float)tempo;
                    float kMillisecondsPerTick = kMillisecondsPerBPM / ppq;
                    float deltaTimeInMilliseconds = ( midiMinPosition - midiPosition ) * kMillisecondsPerTick;

                    // We must calculate the effective delay (in jiffies) 
                    // to introduce into the IMF stream, and it is based
                    // on the real MIDI tempo.
                    int jiffies = deltaTimeInMilliseconds / 20;

                    // printf( " ( midiMinPosition - midiPosition ): %d\n",  ( midiMinPosition - midiPosition ) );
                    // printf( "deltaTimeInMilliseconds: %f, jiffies: %d\n", deltaTimeInMilliseconds, jiffies );

                    // printf(" DELAY: %d jiffies\n", jiffies );

                    // Since the IMF format can represent a pause of
                    // maximum 127 jiffies for each byte produced,
                    // we must split a larger delay. The former
                    // will have 127 jiffies of delay, the last one
                    // will be the rest of the jiffies.
                    while( jiffies > 127 ) {
                        imfBuffer[imfStreamPos++] = IMF_DELAY( 127 );
                        jiffies -= 127;
                        // printf( "DELAY 2.54 seconds\n" );
                        if ( !decode_midi_inside_memory_limits( ) ) {
                            CRITICAL_MIDI_OUT_OF_MEMORY( _filename )
                        }
                    }
                    if ( jiffies > 0 ) {
                        imfBuffer[imfStreamPos++] = IMF_DELAY( jiffies );
                        // printf( "DELAY %f seconds (%d jiffies)\n", (((float)jiffies) / ((float)50)), jiffies );
                        if ( !decode_midi_inside_memory_limits( ) ) {
                            CRITICAL_MIDI_OUT_OF_MEMORY( _filename )
                        }
                    }

                    // Update the current position on the stream
                    // with the minimum one.
                    midiPosition = midiMinPosition;

                } else {
                    // // There is no "valid" minimum position, so we move
                    // // directly on the next message.
                    // ++midiPosition;
                }

            }

        }

        // Free each track read.
        for( track=0; track<numMidiTracks; ++track ) {
            midiReadFreeMessage( &msg[track] );
        }

        // Close the file
        midiFileClose(mf);

        size = imfStreamPos;

        // printf( "size = %d\n", size );

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

    // If a bank expasion has been requested, and there is at least one bank...
    if ( 0 /*_bank_expansion && _environment->expansionBanks*/ ) {

        // Try to compress the result of image conversion.
        // This means that the buffer will be compressed using MSC1
        // algorithm, up to 32 frequent sequences. The original size of
        // the buffer will be considered as "uncompressed" size.
        MSC1Compressor * compressor = msc1_create( 32 );
        result->uncompressedSize = result->size;
        MemoryBlock * output = msc1_compress( compressor, result->valueBuffer, result->uncompressedSize, &result->size );

        int temporary;
        MemoryBlock * outputCheck = msc1_uncompress( compressor, output, result->size, &temporary );

        if ( memcmp( outputCheck, result->valueBuffer, result->uncompressedSize ) != 0 ) {
            CRITICAL_COMPRESSION_FAILED(_filename);
        }
        msc1_free( compressor );

        // If the compressed memory is greater than the original
        // size, we discard the compression and we will continue as
        // usual.
        if ( result->uncompressedSize < result->size ) {
            result->size = result->uncompressedSize;
            result->uncompressedSize = 0;
            free( output );
        } 
        // Otherwise, we can safely replace the original data
        // buffer with the compressed one.
        else {
            free( result->valueBuffer );
            result->valueBuffer = output;
        }

        if ( ! banks_store( _environment, result, _bank_expansion ) ) {
            CRITICAL_EXPANSION_OUT_OF_MEMORY_LOADING( _filename );
        }

    // We can compress also if COMPRESSED flag is used.
    } else if ( 0 /*_flags & FLAG_COMPRESSED*/ ) {

        // Try to compress the result of image conversion.
        // This means that the buffer will be compressed using MSC1
        // algorithm, up to 32 frequent sequences. The original size of
        // the buffer will be considered as "uncompressed" size.
        MSC1Compressor * compressor = msc1_create( 32 );
        result->uncompressedSize = result->size;
        MemoryBlock * output = msc1_compress( compressor, result->valueBuffer, result->uncompressedSize, &result->size );

        int temporary;
        MemoryBlock * outputCheck = msc1_uncompress( compressor, output, result->size, &temporary );
        if ( memcmp( outputCheck, result->valueBuffer, result->uncompressedSize ) != 0 ) {
            CRITICAL_COMPRESSION_FAILED(_filename);
        }
        msc1_free( compressor );

        // If the compressed memory is greater than the original
        // size, we discard the compression and we will continue as
        // usual.
        // If the compressed memory is greater than the original
        // size, we discard the compression and we will continue as
        // usual.
        if ( result->uncompressedSize < result->size ) {
            result->size = result->uncompressedSize;
            result->uncompressedSize = 0;
            free( output );
        } 
        // Otherwise, we can safely replace the original data
        // buffer with the compressed one.
        else {
            result->valueBuffer = output;
            if ( ! banks_store( _environment, result, 1 ) ) {
                CRITICAL_EXPANSION_OUT_OF_MEMORY_LOADING( result->name );
            };
            free( result->valueBuffer );
            result->valueBuffer = NULL;
        }
        
    }


    return result;

}
