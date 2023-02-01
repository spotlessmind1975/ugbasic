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

@english
This command makes the computer emit a bell-like sound. It is possible to indicate 
on which voices the system should emit the sound. If omitted, it will be issued on all.

@italian
Questo comando fa emettere al computer un suono tipo campana. E' possibile indicare su 
quali voci il sistema dovrà emettere il suono. Se omesso, sarà emesso su tutte.

@syntax BELL #[note] {ON #[channels]}

@example BELL #42
@example BELL #42 ON #%001

@target msx1
</usermanual> */
void bell( Environment * _environment, int _note, int _channels ) {

    ay8910_start( _environment, _channels );
    ay8910_set_program( _environment, _channels, IMF_INSTRUMENT_GLOCKENSPIEL );
    ay8910_set_note( _environment, _channels, _note );

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

@syntax BELL [note] {ON [channels]}

@example SOUND laDiesis
@example SOUND solMaggiore, breve
@example SOUND solMaggiore, lunga ON primaVoce

@target msx1
</usermanual> */
void bell_vars( Environment * _environment, char * _note, char * _channels ) {

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

}