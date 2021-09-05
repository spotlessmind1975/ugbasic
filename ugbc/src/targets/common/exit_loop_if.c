/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit ASM code for <b>EXIT IF</b>
 * 
 * This function out of the loop on condition. Optionally, the programmer can
 * give the number of loops to jump out.
 * 
 * @param _environment Current calling environment
 * @param _expression Expression to check
 * @param _number Number of loops to exit.
 */
/* <usermanual>
@keyword EXIT IF

@english
The instruction forces the program to leave a loop, such as ''FOR...NEXT'', 
''REPEAT...UNTIL'', ''WHILE...WEND'' and ''DO...LOOP'' under a specific 
set of conditions. The ''EXIT'' will only be performed ''IF'' the
result is found to true. 

An optional number can be given to specify the number of loops 
to be jumped out, otherwise only the current loop will be aborted.

@italian
Questa istruzione forza il programma ad abbandonare un 
ciclo di tutti i tipi, come 
''FOR...NEXT'', ''REPEAT...UNTIL'', ''WHILE...WEND'' e ''DO...LOOP'',
in base a delle condizioni: tale istruzione uscirà
(''EXIT'') solo se (''IF'') il risultato viene valutato come vero.

Può essere fornito un numero opzionale per specificare il numero di loop
da cui uscire, altrimenti verrà interrotto solo il loop più interno.

@syntax EXIT IF [expression]{, [number] }
@syntax EXIT [number] IF [expression]

@example EXIT IF lifes == 0, 2
@example EXIT 2 IF lifes

@usedInExample control_loops_02.bas
@usedInExample control_loops_03.bas

@target all
</usermanual> */

void exit_loop_if( Environment * _environment, char * _expression, int _number ) {

    outline2( "; EXIT IF %s, %d", _expression, _number );

    Loop * loop = _environment->loops;

    if ( ! loop ) {
        CRITICAL("EXIT without any loop");
    }

    if ( _number ) {
        --_number;
    }

    while( _number-- ) {
        loop = loop->next;

        if ( ! loop ) {
            CRITICAL("EXIT without enough loops");
        }
    }

    unsigned char newLabel[MAX_TEMPORARY_STORAGE]; sprintf(newLabel, "%sbis", loop->label );

    Variable * expression = variable_retrieve( _environment, _expression );

    cpu_bvneq( _environment,  expression->realName, newLabel );
       
}