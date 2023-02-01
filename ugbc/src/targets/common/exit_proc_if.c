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
 * @brief Emit ASM code for <b>EXIT PROC IF</b>
 * 
 * This function out of the current procedure on condition.
 * 
 * @param _environment Current calling environment
 * @param _expression Expression to check
 */
/* <usermanual>
@keyword EXIT PROC IF

@english
The instruction forces the program to leave a procedure under a specific 
set of conditions. The ''EXIT'' will only be performed ''IF'' the
result is found to true. 

@italian
Questa istruzione forza il programma ad abbandonare una procedura
in base a delle condizioni: tale istruzione uscirà
(''EXIT'') solo se (''IF'') il risultato viene valutato come vero.

@syntax EXIT PROC IF [expression]

@example EXIT PROC IF lifes == 0

@usedInExample control_loops_02.bas
@usedInExample control_loops_03.bas

@target all
</usermanual> */

void exit_proc_if( Environment * _environment, char * _expression, char * _value ) {

    MAKE_LABEL

    Variable * expression = variable_retrieve( _environment, _expression );

    cpu_bveq( _environment,  expression->realName, label );

    if ( _value ) {
        return_procedure( _environment, _value );
    } else {
        cpu_return( _environment );
    }

    cpu_label( _environment, label );

}