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
 * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../tester.h"


/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

void test_conditional_if_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * test1 = variable_temporary( e, VT_WORD, "(test1)" );
    Variable * test2 = variable_temporary( e, VT_WORD, "(test2)" );

    Variable * one = variable_temporary( e, VT_WORD, "(1)" );
    variable_store( e, one->name, 1 );
    Variable * three = variable_temporary( e, VT_WORD, "(3)" );
    variable_store( e, three->name, 3 );
    if_then( e, variable_greater_than( e, one->name, three->name, 0 )->name );
        variable_move( e, one->name, test1->name );    
    end_if_then( e );
    if_then( e, variable_greater_than( e, three->name, one->name, 0 )->name );
        variable_move( e, one->name, test2->name );    
    end_if_then( e );

    _te->trackedVariables[0] = test1;
    _te->trackedVariables[1] = test2;

}

int test_conditional_if_tester( TestEnvironment * _te ) {

    Variable * test1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * test2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return test1->value == 0 && test2->value == 1;

}

//===========================================================================

void test_conditional_if_not_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * zero = variable_define( e, "zero", VT_WORD, 0 );
    Variable * one = variable_define( e, "one", VT_WORD, 1 );
    Variable * a = variable_define( e, "a", VT_WORD, 0 );
    Variable * b = variable_define( e, "b", VT_WORD, 2 );

    Variable * x = variable_define( e, "x", VT_WORD, 0 );
    Variable * y = variable_define( e, "y", VT_WORD, 0 );

    if_then( e, variable_and( e, variable_compare_not( e, a->name, zero->name )->name, variable_compare_not( e, a->name, one->name )->name )->name );
        stop_test( e );
    end_if_then( e );
    variable_move_naked( e, one->name, x->name );

    if_then( e, variable_and( e, variable_compare_not( e, b->name, zero->name )->name, variable_compare_not( e, b->name, one->name )->name )->name );
        variable_move_naked( e, one->name, y->name );
    end_if_then( e );

    _te->trackedVariables[0] = x;
    _te->trackedVariables[1] = y;

}

int test_conditional_if_not_tester( TestEnvironment * _te ) {

    Variable * x = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * y = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return x->value == 1 && y->value == 1;

}

void test_conditionals( ) {

    create_test( "conditional_if", &test_conditional_if_payload, &test_conditional_if_tester );    
    create_test( "conditional_if_not", &test_conditional_if_not_payload, &test_conditional_if_not_tester );    

}
