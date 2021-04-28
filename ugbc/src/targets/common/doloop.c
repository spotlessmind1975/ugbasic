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
@keyword DO ... LOOP

@english
Implement an unconditional loop. The ''DO'' instruction defines the starting 
point of the loop, while the ''LOOP'' instruction defines the end point.

@italian
Implementa un loop incondizionato. L'istruzione ''DO'' definisce il
punto iniziale del loop, mentre la parola chiave ''LOOP' definisce il
punto finale.

@syntax DO ... LOOP

@example DO : x = x + 1 : LOOP

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

    // TODO: Better management of conditional types and missing
    Loop * loop = _environment->loops;

    if ( ! loop ) {
        CRITICAL("LOOP without DO");
    }

    if ( loop->type != LT_DO ) {
        CRITICAL("LOOP without DO");
    }

    _environment->loops = _environment->loops->next;

    cpu_jump( _environment, loop->label );

    unsigned char newLabel[32]; sprintf(newLabel, "%sbis", loop->label );

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
Exits from a ''DO...LOOP''. Optionally, you can
give a number that represent the number of loops to jump out.

@italian
Esce da un loop incondizionato. Opzionalmente, può essere dato
un numero che rappresenta il numero di loop da cui uscire.

@syntax EXIT { [number] }

@example EXIT 2

@target all
</usermanual> */
void exit_loop( Environment * _environment, int _number ) {

    outline1( "; EXIT %d", _number );

    // TODO: Better management of conditional types and missing
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

    unsigned char newLabel[32]; sprintf(newLabel, "%sbis", loop->label );

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
/* <usermanual>
@keyword EXIT IF

@english
Exits from a ''DO...LOOP'' on condition. Optionally, you can
give a number that represent the number of loops to jump out.

@italian
Esce da un loop incondizionato in base a una condizione. 
Opzionalmente, può essere dato un numero che rappresenta 
il numero di loop da cui uscire.

@syntax EXIT IF [expression] {,  [number] }

@example EXIT 2

@target all
</usermanual> */
void exit_loop_if( Environment * _environment, char * _expression, int _number ) {

    outline2( "; EXIT IF %s, %d", _expression, _number );

    // TODO: Better management of conditional types and missing
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

    unsigned char newLabel[32]; sprintf(newLabel, "%sbis", loop->label );

    Variable * expression = variable_retrieve( _environment, expression->name );

    cpu_bvneq( _environment,  expression->realName, newLabel );
       
}
