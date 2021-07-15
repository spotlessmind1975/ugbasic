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
 * @brief Emit ASM code for <b>EXIT</b>
 * 
 * This function out of the loop. Optionally, the programmer can
 * give the number of loops to jump out.
 * 
 * @param _environment Current calling environment
 * @param _number Number of loops to exit.
 */
/* <usermanual>
@keyword EXIT

@english
The instruction forces the program to leave a loop immediately, and it can 
be used to escape from all the types of loop, such as ''FOR...NEXT'', 
''REPEAT...UNTIL'', ''WHILE...WEND'' and ''DO...LOOP''.

When used on its own, ''EXIT'' will short-circuit the innermost loop only. 
By including a number after EXIT, that number of nested loops will be taken 
into account before the ''EXIT'' is made.

@italian
Questa istruzione forza il programma ad abbandonare immediatamente un 
ciclo e può essere usato per uscire da tutti i tipi di loop, come 
''FOR...NEXT'', ''REPEAT...UNTIL'', ''WHILE...WEND'' e ''DO...LOOP''.

Se usato da solo, ''EXIT'' uscità solo dal loop più interno.
Includendo un numero dopo ''EXIT'', si uscirà da quel numero di 
cicli annidati.

@syntax EXIT { [number] }

@example EXIT 2

@usedInExample control_loops_02.bas
@usedInExample control_loops_03.bas

@target all
</usermanual> */
void exit_loop( Environment * _environment, int _number ) {

    outline1( "; EXIT %d", _number );

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

    cpu_jump( _environment, newLabel );

}
