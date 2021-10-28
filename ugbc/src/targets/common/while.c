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
 * @brief Emit ASM code for <b>WHILE ...</b>
 * 
 * This function outputs the code to implement the starting
 * point of a WHILE...WEND loop.
 * 
 * @param _environment Current calling environment
 * @param _expression Expression to evaluate
 */
/* <usermanual>
@keyword WHILE...WEND

@english
This instruction define a conditional loop, or a list of statements that will be executed
while an expression is true. ''WHILE'' acts as the starting position while ''WEND'' 
as the ending one. This command provides a convenient way of making the program repeat 
a group of instructions all the time a particular condition is true. The condition is
checked again at every turn of the loop, until it is no longer true. 

@italian
Questa istruzione definisce un ciclo condizionale o un elenco di istruzioni che verranno eseguite
mentre un'espressione è vera. ''WHILE'' funge da posizione di partenza del loop mentre ''WEND''
come quello di fine. Questo comando fornisce un modo conveniente per ripetere un gruppo
di istruzioni per tutto il tempo nel quale una particolare condizione è vera. La condizione è
controllata di nuovo ad ogni ciclo, fino a quando non è più vera.

@syntax WHILE [expression] : ... : WEND
@syntax WHILE [expression]
@syntax   ...
@syntax WEND

@example WHILE alive : score = score + 1 : WEND

@usedInExample control_loops_04.bas

@target all
</usermanual> */

void begin_while( Environment * _environment ) {

    MAKE_LABEL

    Loop * loop = malloc( sizeof( Loop ) );
    loop->label = strdup( label );
    loop->type = LT_WHILE;
    loop->next = _environment->loops;
    _environment->loops = loop;

    unsigned char endWhile[MAX_TEMPORARY_STORAGE]; sprintf(endWhile, "%sbis", loop->label );

    cpu_label( _environment, loop->label );

}

void begin_while_condition( Environment * _environment, char * _expression ) {

    Loop * loop = _environment->loops;

    if ( ! loop ) {
        CRITICAL("Internal error on WHILE...WEND");
    }

    if ( loop->type != LT_WHILE ) {
        CRITICAL("Internal error on WHILE...WEND (2)");
    }

    Variable * expression = variable_retrieve_or_define( _environment, _expression, VT_BYTE, 0 );

    unsigned char endWhile[MAX_TEMPORARY_STORAGE]; sprintf(endWhile, "%sbis", loop->label );

    cpu_bveq( _environment, expression->realName, endWhile );

}

/**
 * @brief Emit ASM code for <b>... WEND</b>
 * 
 * This function outputs the code to implement the end of
 * a while loop, by defining the last point of the loop.
 * 
 * @param _environment Current calling environment
 */
void end_while( Environment * _environment ) {

    Loop * loop = _environment->loops;

    if ( ! loop ) {
        CRITICAL("WEND without WHILE");
    }

    if ( loop->type != LT_WHILE ) {
        CRITICAL("WEND outside a WHILE loop");
    }

    if ( _environment->procedureName && _environment->protothread ) {
        yield( _environment );
    }
    
    cpu_jump( _environment, loop->label );

    unsigned char endWhile[MAX_TEMPORARY_STORAGE]; sprintf(endWhile, "%sbis", loop->label );

    cpu_label( _environment, endWhile );

    _environment->loops = _environment->loops->next;

};
