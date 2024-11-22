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
 * @brief Emit code for <strong>RUN PARALLEL</strong>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword ANIMATING

@english

This statement lets you know if there is a specific animation running 
on an animatable element.

@italian

Questa istruzione permette di sapere se vi è una specifica animazione 
in corso su un elemento animabile.

@syntax = ANIMATING(prefix,animation)

@example IF NOT ANIMATING(wheel,animRotating) THEN
@example    ANIM wheel WITH animBrake
@example ENDIF
</usermanual> */
Variable * animating( Environment * _environment, char * _prefix, char * _animation ) {

    char prefixAnimation[MAX_TEMPORARY_STORAGE]; sprintf( prefixAnimation, "%sAnimation", _prefix );

    if ( ! variable_exists( _environment, prefixAnimation ) ) {
        CRITICAL_CANNOT_USE_ANIMATING_WITHOUT_ANIMATION(_prefix);
    }

    Variable * prefixAnimationVar = variable_retrieve( _environment, prefixAnimation );

    if ( prefixAnimationVar->type != VT_THREAD ) {
        CRITICAL_CANNOT_USE_ANIMATING_WITHOUT_ANIMATION(_prefix);
    }
    
    return running( _environment, prefixAnimationVar->name, _animation );
    
}

