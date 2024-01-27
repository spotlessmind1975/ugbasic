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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

// NOTE OFF, 1 byte, FORMAT: 1110cccc -> cccc is hardware audio channel
#define IMF_NOTE_OFF( channel ) 0xe0 | ( ( 1 << ( ( channel ) % ( MAX_AUDIO_CHANNELS ) ) ) )

// NOTE ON, 2 bytes, 
//          FORMAT: 
//              110ccccc -> cccc is hardware audio channel
//              nnnnnnnn -> nnnnnnnn is the note value
#define IMF_NOTE_ON_CHANNEL( channel ) 0xc0 | ( ( 1 << ( ( channel ) % ( MAX_AUDIO_CHANNELS ) ) ) )
#define IMF_NOTE_ON_NOTE( note ) ( ( note ) & 0xff )

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

        int imfChannelIndex;

        // We have to look for a free one. 
        // So we have to look for an unused one.
        for( imfChannelIndex=0; imfChannelIndex<MAX_AUDIO_CHANNELS; ++imfChannelIndex ) {
            // We exit as soon as we found one.
            if ( ! usedChannel[ imfChannelIndex ] ) {
                break;
            }
        }

        // If we found a channel...
        if ( imfChannelIndex < MAX_AUDIO_CHANNELS ) {

            // Allocate that channel
            // (note that bounded channels are already allocated)
            usedChannel[ imfChannelIndex ] = 1;

            if ( ( lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ] & 0xff ) != 0xff ) {
                imfBuffer[imfStreamPos++] = IMF_SET_PROGRAM_CHANNEL( imfChannelIndex );
                imfBuffer[imfStreamPos++] = IMF_SET_PROGRAM_PROGRAM( lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ] );
                // printf( " -> set program $%2.2x on on %d\n", lastProgramOnMIDITrack[ _payload->MsgData.NoteOn.iChannel ], imfChannelIndex );
            } else {
                imfBuffer[imfStreamPos++] = IMF_SET_PROGRAM_CHANNEL( imfChannelIndex );
                imfBuffer[imfStreamPos++] = IMF_SET_PROGRAM_PROGRAM( 0 );
            }

            // Produce the 2 bytes data on the stream
            imfBuffer[imfStreamPos++] = IMF_NOTE_ON_CHANNEL( imfChannelIndex );
            imfBuffer[imfStreamPos++] = IMF_NOTE_ON_NOTE( _payload->MsgData.NoteOn.iNote );  

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

    // // Produce the 2 bytes data on the stream
    // imfBuffer[imfStreamPos++] = IMF_SET_PROGRAM_CHANNEL( imfChannelIndex );
    // imfBuffer[imfStreamPos++] = IMF_SET_PROGRAM_PROGRAM( _payload->MsgData.ChangeProgram.iProgram );

    // We have to store, also, the MIDI channel that this program is
    // allocated. This is needed, in order to avoid to play a wrong
    // note on the wrong channel.-
    char str[MAX_TEMPORARY_STORAGE];

    lastProgramOnMIDITrack[ _payload->MsgData.ChangeProgram.iChannel ] = _payload->MsgData.ChangeProgram.iProgram;

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

/**
 * @brief Emit code for <strong>LOAD MUSIC(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 */
/* <usermanual>
@keyword MUSIC (storage)

@english
The ''MUSIC'' command, inserted inside a ''BEGIN STORAGE'' - ''ENDSTORAGE'' block, 
allows you to define the content of the mass storage element as a music. The basic 
syntax requires indicating the name of the ''source'' file that will be converted
and inserted into the medium. If you don't want to use the same name, you can indicate 
an alias (''AS target'').

@italian
Il comando ''MUSIC'', inserito all'interno di un blocco ''BEGIN STORAGE'' - 
''ENDSTORAGE'', permette di definire il contenuto dell'elemento di memorizzazione
di massa come musica. La sintassi di base prevede di indicare il nome del file 
sorgente che sarà convertito e inserito nel supporto. Se non si vuole utilizzare 
lo stesso nome, è possibile indicare un alias (''AS target'').

@syntax MUSIC source AS target

@example MUSIC "fugue.mid" AS "fugue"

@target all
</usermanual> */
Variable * music_storage( Environment * _environment, char * _source_name, char * _target_name, int _bank_expansion ) {

    file_storage( _environment, _source_name, _target_name );

    Variable * result = music_load_to_variable( _environment, _source_name, _target_name, _bank_expansion );

    _environment->currentFileStorage->size = result->size;
    _environment->currentFileStorage->content = result->valueBuffer;

    return result;

}
