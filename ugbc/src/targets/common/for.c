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
 * @brief Emit ASM code for <b>FOR ...</b>
 * 
 * This function outputs the code to implement the starting
 * point of a FOR...NEXT loop
 * 
 * @param _environment Current calling environment
 * @param _expression Expression to evaluate
 */
/* <usermanual>
@keyword FOR ... NEXT

@english
Implement an conditional loop. 

@italian
Implementa un loop condizionato.

@syntax FOR [identifier] = [expression] TO [expression] { STEP [expression] }

@example FOR levels = 1 to 10 STEP 2

@target all
</usermanual> */
void begin_for( Environment * _environment, char * _index, char * _from, char * _to ) {

    outline0( "; FOR ... ");

    Variable * index = variable_retrieve( _environment, _index );
    Variable * from = variable_retrieve( _environment, _from );
    Variable * to = variable_retrieve( _environment, _to );
    Variable * step = variable_temporary( _environment, VT_BYTE, "(step 1)" );

    variable_store( _environment, step->name, 1 );
    
    MAKE_LABEL

    Loop * loop = malloc( sizeof( Loop ) );
    loop->label = strdup( label );
    loop->type = LT_FOR;
    loop->next = _environment->loops;
    loop->index = index;
    loop->index->locked = 1;
    loop->step = step;
    loop->step->locked = 1;
    _environment->loops = loop;

    variable_move( _environment, from->name, index->name );

    unsigned char beginFor[32]; sprintf(beginFor, "%sbf", loop->label );
    unsigned char endFor[32]; sprintf(endFor, "%sef", loop->label );

    cpu_label( _environment, beginFor );

    cpu_bvneq( _environment, variable_compare( _environment, index->name, variable_add( _environment, to->name, loop->step->name )->name )->realName, endFor );

}

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit ASM code for <b>FOR ...</b>
 * 
 * This function outputs the code to implement the starting
 * point of a FOR...NEXT loop
 * 
 * @param _environment Current calling environment
 * @param _expression Expression to evaluate
 */
/* <usermanual>
@keyword FOR ... NEXT

@english
Implement an conditional loop. 

@italian
Implementa un loop condizionato.

@syntax FOR [identifier] = [expression] TO [expression] { STEP [expression] }

@example FOR levels = 1 to 10 STEP 2

@target all
</usermanual> */
void begin_for_step( Environment * _environment, char * _index, char * _from, char * _to, char * _step ) {

    outline0( "; FOR ... ");

    Variable * index = variable_retrieve( _environment, _index );
    Variable * from = variable_retrieve( _environment, _from );
    Variable * to = variable_retrieve( _environment, _to );
    Variable * step = variable_retrieve( _environment, _step );

    variable_store( _environment, step->name, 1 );
    
    MAKE_LABEL

    Loop * loop = malloc( sizeof( Loop ) );
    loop->label = strdup( label );
    loop->type = LT_FOR;
    loop->next = _environment->loops;
    loop->index = index;
    loop->index->locked = 1;
    loop->step = step;
    loop->step->locked = 1;
    _environment->loops = loop;

    variable_move( _environment, from->name, index->name );

    unsigned char beginFor[32]; sprintf(beginFor, "%sbf", loop->label );
    unsigned char endFor[32]; sprintf(endFor, "%sef", loop->label );

    cpu_label( _environment, beginFor );

    cpu_bvneq( _environment, variable_compare( _environment, index->name, variable_add( _environment, to->name, loop->step->name )->name )->realName, endFor );

}

/**
 * @brief Emit ASM code for <b>... NEXT</b>
 * 
 * This function outputs the code to implement the end of
 * a for...next loop, by defining the last point of the loop.
 * 
 * @param _environment Current calling environment
 */
void end_for( Environment * _environment ) {

    // TODO: Better management of conditional types and missing
    Loop * loop = _environment->loops;

    if ( ! loop ) {
        CRITICAL("NEXT WITHOUT FOR");
    }

    if ( loop->type != LT_FOR ) {
        CRITICAL("NEXT outside a FOR loop");
    }

    unsigned char beginFor[32]; sprintf(beginFor, "%sbf", loop->label );
    unsigned char endFor[32]; sprintf(endFor, "%sef", loop->label );

    variable_move_naked( _environment, variable_add( _environment, loop->index->name, loop->step->name )->name, loop->index->name );

    cpu_jump( _environment, beginFor );

    cpu_label( _environment, endFor );

    loop->index->locked = 0;
    loop->step->locked = 0;

    _environment->loops = _environment->loops->next;

};
