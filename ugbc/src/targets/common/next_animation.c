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
 * @brief Emit code for <strong>KILL ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _handle Identifier of the thread
 */
/* <usermanual>
@keyword NEXT ANIMATION

@english

This command can be used to stop the execution of the central part of an animation, 
and therefore go to the possible "ease out" and execute the next animation, if present.

@italian

Questo comando può essere utilizzato per interrompere l'esecuzione della parte centrale 
di una animazione, e portarsi quindi nell'eventuale "ease out" nonché eseguire l'animazione 
successiva, se presente.

@syntax NEXT ANIMATION prefix

@example NEXT ANIMATION airplane

</usermanual> */
void next_animation( Environment * _environment, char * _prefix ) {

    MAKE_LABEL

    char prefixAnimation[MAX_TEMPORARY_STORAGE]; sprintf( prefixAnimation, "%sAnimation", _prefix );
    char prefixNext[MAX_TEMPORARY_STORAGE]; sprintf( prefixNext, "%sNext", _prefix );

    if ( ! variable_exists( _environment, prefixAnimation ) ) {
        CRITICAL_CANNOT_USE_NEXT_ANIMATION_WITHOUT_ANIMATION(_prefix);
    }

    if ( ! variable_exists( _environment, prefixNext ) ) {
        CRITICAL_CANNOT_USE_NEXT_ANIMATION_WITHOUT_ANIMATION(_prefix);
    }

    Variable * prefixAnimationVar = variable_retrieve( _environment, prefixAnimation );

    if ( prefixAnimationVar->type != VT_THREAD ) {
        CRITICAL_CANNOT_USE_NEXT_ANIMATION_WITHOUT_ANIMATION(_prefix);
    }

    char doneLabel[MAX_TEMPORARY_STORAGE]; sprintf( doneLabel, "%sDone", label );

    Variable * prefixNextVar = variable_retrieve( _environment, prefixNext );

    cpu_or_8bit_const( _environment, prefixNextVar->realName, 0x80, prefixNextVar->realName );

    begin_loop( _environment, 1 );
        variable_compare_and_branch_const( _environment, 
            variable_and_const( _environment, prefixNextVar->name, 0x02)->name, 0x02, doneLabel, 1 );
        run_parallel( _environment );
    end_loop( _environment, 1 );

    cpu_label( _environment, doneLabel );
    
}

