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

//===========================================================================

void test_variables_add01_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * op1 = variable_define( e, "operand1", VT_WORD, 42 );
    Variable * op2 = variable_define( e, "operand2", VT_WORD, 24 );
    Variable * sum = variable_add( e, op1->name, op2->name );

    _te->trackedVariables[0] = sum;

}

int test_variables_add01_tester( TestEnvironment * _te ) {

    Variable * sum = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return sum->value == 66;

}

//===========================================================================

void test_variables_greater_than_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * one = variable_temporary( e, VT_WORD, "(1)" );
    variable_store( e, one->name, 1 );
    Variable * three = variable_temporary( e, VT_WORD, "(3)" );
    variable_store( e, three->name, 3 );
    Variable * compare1 = variable_greater_than( e, one->name, one->name, 0 );
    Variable * compare2 = variable_greater_than( e, one->name, three->name, 0 );
    Variable * compare3 = variable_greater_than( e, three->name, one->name, 0 );
    Variable * compare4 = variable_greater_than( e, three->name, three->name, 0 );

    _te->trackedVariables[0] = compare1;
    _te->trackedVariables[1] = compare2;
    _te->trackedVariables[2] = compare3;
    _te->trackedVariables[3] = compare4;

}

int test_variables_greater_than_tester( TestEnvironment * _te ) {

    Variable * compare1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * compare2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * compare3 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * compare4 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    return compare1->value == 0 && compare2->value == 0 && compare3->value == 0xff && compare4->value == 0;

}

//===========================================================================

void test_variables_bin_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * fiftyfive = variable_define( e, "fiftyfive", VT_BYTE, 0x55 );
    Variable * five = variable_define( e, "five", VT_WORD, 5 );
    Variable * b = variable_bin( e, fiftyfive->name, five->name );

    _te->trackedVariables[0] = b;

}

int test_variables_bin_tester( TestEnvironment * _te ) {

    Variable * b = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return strcmp( b->valueString, "01010101" ) == 0;

}



void test_variables( ) {

    create_test( "variables_add01", &test_variables_add01_payload, &test_variables_add01_tester );    
    create_test( "variables_greater", &test_variables_greater_than_payload, &test_variables_greater_than_tester );    
    create_test( "variables_bin", &test_variables_bin_payload, &test_variables_bin_tester );    

}
