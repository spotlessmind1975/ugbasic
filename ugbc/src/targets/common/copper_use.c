/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit code for <strong>BEGIN COPPER</strong>
 * 
 * @param _environment Current calling environment
 */
 /* <usermanual>
@keyword COPPER USE

@english

The ''COPPER USE'' command is used to select and activate a specific copper list, 
replacing the currently running one. This command comes into play when you create 
multiple copper lists and want to switch between them.

@italian

Il comando ''COPPER USE'' serve a selezionare e attivare una specifica copper list, 
sostituendo quella che è attualmente in esecuzione. Il comando entra in gioco quando 
si creano diverse copper list, e si vuol passare da una all'altra. 

@syntax COPPER USE name

@example BEGIN COPPER first
@example    COPPER WAIT LINE 10
@example    COPPER COLOR BACKGROUND RED
@example    COPPER WAIT LINE 30
@example    COPPER COLOR BACKGROUND BLUE
@example END COPPER
@example BEGIN COPPER second
@example    COPPER WAIT LINE 20
@example    COPPER COLOR BACKGROUND RED
@example    COPPER WAIT LINE 40
@example    COPPER COLOR BACKGROUND BLUE
@example END COPPER
@example COPPER USE first: WAIT KEY: COPPER USE second

</usermanual> */

extern char DATATYPE_AS_STRING[][16];

void copper_use( Environment * _environment, char * _name ) {

    CopperList * copperList = find_copper_list( _environment, _name );

    if ( !copperList ) {
        CRITICAL_COPPER_LIST_UNKNOWN( _name );
    }

    char copperListActivationRoutine[MAX_TEMPORARY_STORAGE];
    sprintf(copperListActivationRoutine, "COPPERACTIVATE%s", _name );

    cpu_call(_environment, copperListActivationRoutine);

}
