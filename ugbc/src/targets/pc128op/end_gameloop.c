/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit ASM code for <b>END GAMELOOP</b>
 * 
 * This function is called to emit the code necessary to define the ending 
 * point of a game loop.
 * 
 * @pre A <b>BEGIN GAMELOOP</b> must be issued before use this function.
 * 
 * @param _environment Current calling environment
 * @throw EXIT_FAILURE "Cannot call END GAMELOOP without BEGIN GAMELOOP"
 */
/* <usermanual>
@keyword END GAMELOOP

@english
Define the ending point of a game loop.

@italian
Definisce il punto di arrivo di un loop di gioco.

@syntax END GAMELOOP

@example END GAMELOOP

@target pc128op
</usermanual> */
void end_gameloop( Environment * _environment ) {

Loop * loop = _environment->loops;

    if ( ! loop ) {
        CRITICAL("END GAMELOOP without BEGIN GAMELOOP");
    }

    if ( loop->type != LT_GAMELOOP ) {
        CRITICAL("END GAMELOOP without BEGIN GAMELOOP");
    }

    _environment->loops = _environment->loops->next;

    if ( _environment->hasGameLoop ) {
        if ( _environment->anyProtothread ) {
            run_parallel( _environment );
        }
        cpu_call( _environment, "WAITVBL");
        deploy_embedded( cpu_mem_move, src_hw_6809_cpu_mem_move_asm );
        if ( _environment->doubleBufferEnabled ) {
            outline0( "JSR SWITCHTILEMAP");
        }
        cpu_jump( _environment, loop->label );
        unsigned char newLabel[MAX_TEMPORARY_STORAGE]; sprintf(newLabel, "%sbis", loop->label );
        cpu_label( _environment, newLabel );
        _environment->hasGameLoop = 0;
    } else {
         CRITICAL("Cannot call END GAMELOOP without BEGIN GAMELOOP");
    }

}
