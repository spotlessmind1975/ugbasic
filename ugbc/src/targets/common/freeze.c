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
 * @brief Emit code for <strong>FREEZE ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the procedure
 */
/* <usermanual>
@keyword FREEZE

@english

This command can be used to temporarily pause the execution of an animation. 
It will then be held still on the last frame reached.

@italian

Questo comando può essere utilizzato per sospendere, temporaneamente, 
l'esecuzione di una animazione. Sarà quindi mantenuto fermo sull'ultimo 
fotogramma raggiunto.

@syntax FREEZE prefix

@example ANIMATE airplane WITH anim AT 20, 20
@example RUN PARALLEL
@example FREEZE airplane

@target all
</usermanual> */
void freeze_vars( Environment * _environment, char * _prefix ) {

    MAKE_LABEL

    char prefixAnimation[MAX_TEMPORARY_STORAGE]; sprintf( prefixAnimation, "%sAnimation", _prefix );

    if ( ! variable_exists( _environment, prefixAnimation ) ) {
        CRITICAL_CANNOT_USE_FREEZE_WITHOUT_ANIMATION(_prefix);
    }

    Variable * prefixAnimationVar = variable_retrieve( _environment, prefixAnimation );

    if ( prefixAnimationVar->type != VT_THREAD ) {
        CRITICAL_CANNOT_USE_FREEZE_WITHOUT_ANIMATION(_prefix);
    }

    suspend_vars( _environment, prefixAnimationVar->name );
    
}

