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
 * @brief Emit ASM code for <b>BOOM ...</b>
 * 
 * This function emits a code capable of play a explosion-like sound.
 * 
 * @param _environment Current calling environment
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword BOOM
@target coleco
</usermanual> */
void boom( Environment * _environment, int _duration, int _channels ) {

    sn76489z_set_program( _environment, _channels, IMF_INSTRUMENT_EXPLOSION );
    sn76489z_start( _environment, _channels );
    sn76489z_set_frequency( _environment, _channels, 1000 );

    long durationInCycles = ( _duration / 20 ) & 0xffff;

    sn76489z_set_duration( _environment, durationInCycles, _channels );

    if ( ! _environment->audioConfig.async ) {
        sn76489z_wait_duration( _environment, _channels );
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
@target coleco
</usermanual> */
void boom_var( Environment * _environment, char * _duration, char * _channels ) {

    if ( _channels ) {
        Variable * channels = variable_retrieve_or_define( _environment, _channels, VT_WORD, 0x07 );
        sn76489z_start_var( _environment, channels->realName );
        sn76489z_set_program_semi_var( _environment, channels->realName, IMF_INSTRUMENT_EXPLOSION );
    } else {
        sn76489z_start_var( _environment, NULL );
        sn76489z_set_program_semi_var( _environment, NULL, IMF_INSTRUMENT_EXPLOSION );
    }

    if ( _duration ) {
        Variable * duration = variable_retrieve_or_define( _environment, _channels, VT_WORD, 0x07 );
        cpu_math_div2_const_16bit( _environment, duration->realName, 4, 0 );
        sn76489z_set_duration_vars( _environment, _channels, duration->realName );
    } else {
        sn76489z_set_duration_vars( _environment, _channels, NULL );
    } 

    if ( ! _environment->audioConfig.async ) {
        sn76489z_wait_duration_vars( _environment, _channels );
    }

}

