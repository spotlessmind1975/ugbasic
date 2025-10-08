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
 * @brief Emit ASM code for <b>BOOM ...</b>
 * 
 * This function emits a code capable of play a explosion-like sound.
 * 
 * @param _environment Current calling environment
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword BOOM
@target c16
</usermanual> */
void boom( Environment * _environment, int _duration, int _channels ) {

    _channels = 0x02; // second channel only

    ted_set_program( _environment, _channels, IMF_INSTRUMENT_EXPLOSION );
    ted_start( _environment, _channels );
    ted_set_frequency( _environment, _channels, 500 );

    long durationInTicks = ( _duration / 20 ) & 0xff;

    ted_set_duration( _environment, _channels, durationInTicks );

    if ( ! _environment->audioConfig.async ) {
        ted_wait_duration( _environment, _channels );
    }

}

/**
 * @brief Emit ASM code for <b>BOOM ...</b>
 * 
 * This function emits a code capable of play a explosion-like sound.
 * 
 * @param _environment Current calling environment
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword BOOM
@target c16
</usermanual> */
void boom_var( Environment * _environment, char * _duration, char * _channels ) {

    int channels = 0x02; // second channel only

    ted_set_program( _environment, channels, IMF_INSTRUMENT_EXPLOSION );
    ted_start( _environment, channels );
    ted_set_frequency( _environment, channels, 500 );
    if ( _duration ) {
        Variable * duration = variable_retrieve_or_define( _environment, _duration, VT_WORD, 0x07 );
        Variable * durationInTicks = variable_div_const( _environment, duration->name, 20, NULL );
        ted_set_duration_vars( _environment, NULL, durationInTicks->realName );
    } else {
        ted_set_duration_vars( _environment, NULL, NULL );
    }
    if ( ! _environment->audioConfig.async ) {
        ted_wait_duration_vars( _environment, NULL );
    }        
    
}

