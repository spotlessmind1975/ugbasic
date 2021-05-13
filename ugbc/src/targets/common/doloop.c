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
 * @brief Emit ASM code for <b>DO ...</b>
 * 
 * This function outputs the code to implement the starting
 * point of a DO...LOOP loop.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword DO...LOOP

@english
This instruction define a loop, or a list of statements that will be executed forever.
''DO'' acts as the starting position while ''LOOP'' the endig one.

@italian
Questa istruzione definisce un "loop" cioè un elenco di istruzioni che saranno
eseguite per sempre. La parola chiave ''DO'' indica il punto di innesto del
loop mentre la parola ''LOOP'' l'ultima istruzione del loop.

@syntax DO : ... : LOOP
@syntax DO
@syntax   ...
@syntax LOOP

@example DO : x = x + 1 : LOOP
@usedInExample control_loops_01.bas
@usedInExample control_loops_02.bas
@usedInExample control_loops_03.bas
@usedInExample control_loops_04.bas
@usedInExample control_loops_05.bas

@target all
</usermanual> */
void begin_loop( Environment * _environment ) {

    outline0( "; DO ... ");

    MAKE_LABEL

    Loop * loop = malloc( sizeof( Loop ) );
    loop->label = strdup( label );
    loop->type = LT_DO;
    loop->next = _environment->loops;
    _environment->loops = loop;

    cpu_label( _environment, loop->label );

}

/**
 * @brief Emit ASM code for <b>... LOOP</b>
 * 
 * This function outputs the code to implement the end of
 * loop, by defining the last point of the loop.
 * 
 * @param _environment Current calling environment
 */
void end_loop( Environment * _environment ) {

    Loop * loop = _environment->loops;

    if ( ! loop ) {
        CRITICAL("LOOP without DO");
    }

    if ( loop->type != LT_DO ) {
        CRITICAL("LOOP without DO");
    }

    _environment->loops = _environment->loops->next;

    cpu_jump( _environment, loop->label );

    unsigned char newLabel[MAX_TEMPORARY_STORAGE]; sprintf(newLabel, "%sbis", loop->label );

    cpu_label( _environment, newLabel );

};

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

If you need to leave a loop as a result of a specific set of conditions, 
this can be made by using the ''EXIT IF'' instruction. The ''EXIT'' will 
only be performed ''IF'' the result is found to true. 

Finally, an optional number can be given to specify the number of loops 
to be jumped out, otherwise only the current loop will be aborted.

@italian
Questa istruzione forza il programma ad abbandonare immediatamente un 
ciclo e può essere usato per uscire da tutti i tipi di loop, come 
''FOR...NEXT'', ''REPEAT...UNTIL'', ''WHILE...WEND'' e ''DO...LOOP''.

Se usato da solo, ''EXIT'' uscità solo dal loop più interno.
Includendo un numero dopo ''EXIT'', si uscirà da quel numero di 
cicli annidati.

Se è necessario abbandonare un ciclo in base a delle condizioni,
può essere utile l'istruzione ''EXIT IF'': tale istruzione uscirà
(''EXIT'') solo se se (''IF'') il risultato viene valutato come vero.

Infine, può essere fornito un numero opzionale per specificare il numero di loop
da cui uscire, altrimenti verrà interrotto solo il loop più interno.

@syntax EXIT { [number] }
@syntax EXIT IF [expression]{, [number] }

@example EXIT 2
@example EXIT IF lifes == 0, 2

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

    Variable * expression = variable_retrieve( _environment, expression->name );

    cpu_bvneq( _environment,  expression->realName, newLabel );
       
}