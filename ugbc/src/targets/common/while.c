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
@keyword WHILE [expression] ... WEND

@english
Implement an conditional loop. 

@italian
Implementa un loop condizionato.

@syntax WHILE [expression] ... WEND

@example WHILE lives ... WEND

@target all
</usermanual> */
void begin_while( Environment * _environment, char * _expression ) {

    outline0( "; WHILE ... ");

    Variable * expression = variable_retrieve( _environment, _expression );

    MAKE_LABEL

    Loop * loop = malloc( sizeof( Loop ) );
    loop->label = strdup( label );
    loop->type = LT_WHILE;
    loop->next = _environment->loops;
    _environment->loops = loop;

    unsigned char newLabel[32]; sprintf(newLabel, "%sbis", loop->label );

    cpu6502_bveq( _environment, expression->realName, newLabel );

    cpu_label( _environment, loop->label );

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

    // TODO: Better management of conditional types and missing
    Loop * loop = _environment->loops;

    if ( ! loop ) {
        CRITICAL("WEND without WHILE");
    }

    if ( loop->type != LT_WHILE ) {
        CRITICAL("WEND outside a WHILE loop");
    }

    _environment->loops = _environment->loops->next;

    cpu_jump( _environment, loop->label );

    unsigned char newLabel[32]; sprintf(newLabel, "%sbis", loop->label );

    cpu_label( _environment, newLabel );

};
