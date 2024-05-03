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

@target coco
</usermanual> */
void bell( Environment * _environment, int _note, int _duration, int _channels ) {

    if ( _environment->audioConfig.async ) {
        CRITICAL_BELL_NOT_ASYNC();
    }

    deploy( random, src_hw_6809_cpu_random_asm );
    deploy( audio1startup, src_hw_coco3_audio1_asm );

    long durationInCycles = ( _duration * 67 ) & 0xffff;

    outline1( "LDB $%2.2x", _note );
    outline1( "LDY $%4.4x", durationInCycles );
    outline0( "JSR COCO3AUDIO1BELL" );

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
</usermanual> */
void bell_vars( Environment * _environment, char * _note, char * _duration, char * _channels ) {

    if ( _environment->audioConfig.async ) {
        CRITICAL_BELL_NOT_ASYNC();
    }
    
    deploy( random, src_hw_6809_cpu_random_asm );
    deploy( audio1startup, src_hw_coco3_audio1_asm );

    if ( _note ) {
        Variable * note = variable_retrieve_or_define( _environment, _note, VT_BYTE, 0 );
        outline1( "LDB %s", note->realName );
    } else {
        outline0( "LDB #36" );
    }

    if ( _duration ) {
        Variable * duration = variable_retrieve_or_define( _environment, _duration, VT_WORD, 3500 );

        outline1( "LDD %s", duration->realName );
        outline0( "ASLB" );
        outline0( "ROLA" );
        outline0( "ASLB" );
        outline0( "ROLA" );
        outline0( "ASLB" );
        outline0( "ROLA" );
        outline0( "TFR D, Y" );

    } else {
        
    }
    cpu_call( _environment, "COCO3AUDIO1BELL" );

}