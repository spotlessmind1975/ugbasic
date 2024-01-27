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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit ASM code for <b>PLAY ...</b>
 * 
 * This function emits a code capable of play a note for a certain amount of time
 * on specific channels
 * 
 * @param _environment Current calling environment
 * @param _note note to play
 * @param _delay delay of playing
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword PLAY
@target c128
</usermanual> */
void play( Environment * _environment, int _note, int _delay, int _channels ) {

    sid_start( _environment, _channels );
    sid_set_note( _environment, _channels, _note );
    if ( _delay ) {
        wait_milliseconds( _environment, _delay );
    }

}

/**
 * @brief Emit ASM code for <b>PLAY ...</b>
 * 
 * This function emits a code capable of play a note for a certain amount of time
 * on specific channels
 * 
 * @param _environment Current calling environment
 * @param _note note to play
 * @param _delay delay of playing
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword PLAY
@target c128
</usermanual> */
void play_vars( Environment * _environment, char * _note, char * _delay, char * _channels ) {

    Variable * note = variable_retrieve_or_define( _environment, _note, VT_BYTE, 42 );
    if ( _channels ) {
        Variable * channels = variable_retrieve_or_define( _environment, _channels, VT_WORD, 0x07 );
        sid_start_var( _environment, channels->realName );
        sid_set_note_vars( _environment, channels->realName, note->realName );
    } else {
        sid_start_var( _environment, NULL );
        sid_set_note_vars( _environment, NULL, note->realName );
    }
    if ( _delay ) {
        wait_milliseconds_var( _environment, _delay );
    }

}