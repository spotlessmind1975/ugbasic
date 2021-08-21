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

//===========================================================================

void test_variables_bin2_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * fiftyfive = variable_define( e, "fiftyfive", VT_BYTE, 0x55 );

    Variable * j = variable_define( e, "j", VT_BYTE, 0 );
    Variable * one = variable_define( e, "one", VT_WORD, 1 );
    Variable * limit = variable_define( e, "limit", VT_WORD, 100 );
    Variable * five = variable_define( e, "five", VT_WORD, 5 );
    Variable * times = variable_define( e, "times", VT_WORD, 0 );
    Variable * b = variable_define( e, "b", VT_DSTRING, 42 );

    variable_store_string( e, b->name, "" );

    begin_loop( e );
        b = variable_bin( e, j->name, five->name );
        variable_reset( e );
        variable_move( e, variable_add( e, times->name, one->name )->name, times->name );
        if_then( e, variable_compare( e, times->name, limit->name )->name );
            b = variable_bin( e, fiftyfive->name, five->name );
            stop_test( e );
        end_if_then( e );
    end_loop( e );

    _te->trackedVariables[0] = b;

}

int test_variables_bin2_tester( TestEnvironment * _te ) {

    Variable * b = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return b->valueString != NULL && strcmp( b->valueString, "01010101" ) == 0 || strcmp( b->valueString, "00000000000000000000000001010101" ) == 0;

}

//===========================================================================

void test_variables_and_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * zero = variable_define( e, "zero", VT_WORD, 0 );
    Variable * one = variable_define( e, "one", VT_WORD, 1 );
    Variable * a = variable_define( e, "a", VT_WORD, 0 );
    Variable * b = variable_define( e, "b", VT_WORD, 1 );
    Variable * c = variable_define( e, "c", VT_WORD, 2 );

    Variable * x = variable_define( e, "x", VT_BYTE, 0 );
    Variable * y = variable_define( e, "y", VT_BYTE, 0 );
    Variable * z = variable_define( e, "z", VT_BYTE, 0 );

    x = variable_and( e, variable_compare_not( e, a->name, zero->name )->name, variable_compare_not( e, a->name, one->name )->name );
    y = variable_and( e, variable_compare_not( e, b->name, zero->name )->name, variable_compare_not( e, b->name, one->name )->name );
    z = variable_and( e, variable_compare_not( e, c->name, zero->name )->name, variable_compare_not( e, c->name, one->name )->name );

    _te->trackedVariables[0] = x;
    _te->trackedVariables[1] = y;
    _te->trackedVariables[2] = z;

}

int test_variables_and_tester( TestEnvironment * _te ) {

    Variable * x = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * y = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * z = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );

    return x->value == 0x00 && y->value == 0x00 && z->value == 0xff;

}

//===========================================================================

void test_variables_not_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * true = variable_define( e, "true", VT_BYTE, 0xff );
    Variable * false = variable_define( e, "false", VT_BYTE, 0x00 );

    Variable * x = variable_define( e, "x", VT_BYTE, 0 );
    Variable * y = variable_define( e, "y", VT_BYTE, 0 );

    x = variable_not( e, true->name );
    y = variable_not( e, false->name );

    _te->trackedVariables[0] = x;
    _te->trackedVariables[1] = y;

}

int test_variables_not_tester( TestEnvironment * _te ) {

    Variable * x = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * y = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return x->value == 0x00 && y->value == 0xff;

}

//===========================================================================

void test_variables_cast_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * a = variable_define( e, "a", VT_BYTE, 0x55 );
    Variable * b = variable_cast( e, a->name, VT_DWORD );

    _te->trackedVariables[0] = b;

}

int test_variables_cast_tester( TestEnvironment * _te ) {

    Variable * b = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return b->value == 0x00000055;

}

//==========================================================================

void test_variable_compare_not_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * k = variable_define( e, "k", VT_DSTRING, 0 );
    Variable * empty = variable_define( e, "empty", VT_STRING, 0 );

    variable_store_string( e, k->name, "" );
    variable_store_string( e, empty->name, "" );

    Variable * result0 = variable_compare( e, k->name, empty->name );
    Variable * result1 = variable_compare_not( e, k->name, empty->name );

    _te->trackedVariables[0] = result0;
    _te->trackedVariables[1] = result1;

}

int test_variable_compare_not_tester( TestEnvironment * _te ) {

    Variable * result0 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * result1 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return result1->value == 0x0 && result0->value == 0xff;
    
}

//===========================================================================

void test_variables_bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * data = variable_define( e, "data", VT_BYTE, 0x55 );

    Variable * pos0 = variable_define( e, "pos0", VT_BYTE, 0x00 );
    Variable * pos1 = variable_define( e, "pos1", VT_BYTE, 0x01 );
    Variable * pos2 = variable_define( e, "pos2", VT_BYTE, 0x02 );
    Variable * pos3 = variable_define( e, "pos3", VT_BYTE, 0x03 );
    Variable * pos4 = variable_define( e, "pos4", VT_BYTE, 0x04 );
    Variable * pos5 = variable_define( e, "pos5", VT_BYTE, 0x05 );
    Variable * pos6 = variable_define( e, "pos6", VT_BYTE, 0x06 );
    Variable * pos7 = variable_define( e, "pos7", VT_BYTE, 0x07 );

    Variable * result0 = variable_bit( e, data->name, pos0->name );
    Variable * result1 = variable_bit( e, data->name, pos1->name );
    Variable * result2 = variable_bit( e, data->name, pos2->name );
    Variable * result3 = variable_bit( e, data->name, pos3->name );
    Variable * result4 = variable_bit( e, data->name, pos4->name );
    Variable * result5 = variable_bit( e, data->name, pos5->name );
    Variable * result6 = variable_bit( e, data->name, pos6->name );
    Variable * result7 = variable_bit( e, data->name, pos7->name );

    _te->trackedVariables[0] = result0;
    _te->trackedVariables[1] = result1;
    _te->trackedVariables[2] = result2;
    _te->trackedVariables[3] = result3;
    _te->trackedVariables[4] = result4;
    _te->trackedVariables[5] = result5;
    _te->trackedVariables[6] = result6;
    _te->trackedVariables[7] = result7;

}

int test_variables_bit_tester( TestEnvironment * _te ) {

    Variable * result0 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * result1 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * result2 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * result3 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * result4 = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );
    Variable * result5 = variable_retrieve( &_te->environment, _te->trackedVariables[5]->name );
    Variable * result6 = variable_retrieve( &_te->environment, _te->trackedVariables[6]->name );
    Variable * result7 = variable_retrieve( &_te->environment, _te->trackedVariables[7]->name );

    return  result0->value == 0xff && 
            result1->value == 0x00 &&
            result2->value == 0xff && 
            result3->value == 0x00 &&
            result4->value == 0xff && 
            result5->value == 0x00 &&
            result6->value == 0xff && 
            result7->value == 0x00;

}

void test_variables( ) {

    create_test( "variables_add01", &test_variables_add01_payload, &test_variables_add01_tester );    
    create_test( "variables_greater", &test_variables_greater_than_payload, &test_variables_greater_than_tester );    
    create_test( "variables_bin", &test_variables_bin_payload, &test_variables_bin_tester );    
    create_test( "variables_bin2", &test_variables_bin2_payload, &test_variables_bin2_tester );    
    create_test( "variables_and", &test_variables_and_payload, &test_variables_and_tester );
    create_test( "variables_not", &test_variables_not_payload, &test_variables_not_tester );
    create_test( "variables_cast", &test_variables_not_payload, &test_variables_not_tester );
    create_test( "variables_compare_not", &test_variable_compare_not_payload, &test_variable_compare_not_tester );
    create_test( "variables_bit", &test_variables_bit_payload, &test_variables_bit_tester );

}
