/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit ASM code for <b>BELL ...</b>
 * 
 * This function emits a code capable of play a bell sound
 * 
 * @param _environment Current calling environment
 * @param _pitch frequency to play
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword BELL
@target cpc
</usermanual> */
void bell( Environment * _environment, int _note, int _duration, int _channels ) {

    ay8910_start( _environment, ( _channels & 0x07 ) );
    ay8910_set_program( _environment, _channels, IMF_INSTRUMENT_GLOCKENSPIEL );
    ay8910_set_note( _environment, _channels, _note );

    long durationInCycles = ( _duration / 20 ) & 0xffff;

    ay8910_set_duration( _environment,  _channels, durationInCycles );

    if ( ! _environment->audioConfig.async ) {
        ay8910_wait_duration( _environment, _channels );
    }

}

/**
 * @brief Emit ASM code for <b>BELL ...</b>
 * 
 * This function emits a code capable of play a bell-like sound.
 * 
 * @param _environment Current calling environment
 * @param _pitch frequency to play
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword BELL
@target cpc
</usermanual> */
void bell_vars( Environment * _environment, char * _note, char * _duration, char * _channels, int _sync ) {

    Variable * note = variable_retrieve_or_define( _environment, _note, VT_WORD, 42 );
    if ( _channels ) {
        Variable * channels = variable_retrieve_or_define( _environment, _channels, VT_WORD, 0x07 );
        ay8910_start_var( _environment, channels->realName );
        ay8910_set_program_semi_var( _environment, channels->realName, IMF_INSTRUMENT_GLOCKENSPIEL );
        ay8910_set_note_vars( _environment, channels->realName, note->realName );
    } else {
        ay8910_start_var( _environment, NULL );
        ay8910_set_program_semi_var( _environment, NULL, IMF_INSTRUMENT_GLOCKENSPIEL );
        ay8910_set_note_vars( _environment, NULL, note->realName );
    }

    if ( _duration ) {
        Variable * duration = variable_retrieve_or_define( _environment, _duration, VT_WORD, 1500 );
        Variable * durationInTicks = variable_div_const( _environment, duration->name, 20, NULL );
        ay8910_set_duration_vars( _environment, _channels, durationInTicks->realName );
    } else {
        ay8910_set_duration_vars( _environment, _channels, NULL );
    } 

    if ( ! _environment->audioConfig.async || _sync ) {
        ay8910_wait_duration_vars( _environment, _channels );
    }

}