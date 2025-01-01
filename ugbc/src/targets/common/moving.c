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
 * @brief Emit code for <strong>MOVING</strong>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword MOVING

@english

This statement lets you know if there is a specific movement running 
on a movable element.

@italian

Questa istruzione permette di sapere se vi è uno specifico movimento in corso
su un elemento spostabile.

@syntax = MOVING(prefix)
@syntax = MOVING(prefix,movement)

@example IF NOT MOVING(wheel,moveLeft) THEN
@example    MOVE wheel WITH moveRight
@example ENDIF
</usermanual> */
Variable * moving( Environment * _environment, char * _prefix, char * _movement ) {

    char prefixMovement[MAX_TEMPORARY_STORAGE]; sprintf( prefixMovement, "%sMovement", _prefix );

    if ( ! variable_exists( _environment, prefixMovement ) ) {
        CRITICAL_CANNOT_USE_MOVING_WITHOUT_MOVEMENT(_prefix);
    }

    Variable * prefixMovementVar = variable_retrieve( _environment, prefixMovement );

    if ( prefixMovementVar->type != VT_THREAD ) {
        CRITICAL_CANNOT_USE_MOVING_WITHOUT_MOVEMENT(_prefix);
    }
    
    return running( _environment, prefixMovementVar->name, _movement );
    
}

