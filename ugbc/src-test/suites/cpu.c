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

void test_cpu_bits_to_string_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * number = variable_define( e, "number", VT_BYTE, 2 );
    Variable * string = variable_define( e, "string", VT_DSTRING, 0 );
    Variable * address = variable_define( e, "address", VT_ADDRESS, 0 );
    Variable * size = variable_define( e, "size", VT_BYTE, 0 );
    cpu_dsalloc_size( e, 8, string->realName );
    cpu_dsdescriptor( e, string->realName, address->realName, size->realName );
    cpu_bits_to_string( e, number->realName, address->realName, size->realName, 8 );

    _te->trackedVariables[0] = string;

}

int test_cpu_bits_to_string_tester( TestEnvironment * _te ) {

    Variable * string = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return strcmp( string->valueString, "00000010" ) == 0;

}

//===========================================================================

void test_cpu_bits_to_string32_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * number = variable_define( e, "number", VT_DWORD, 0x00000055 );
    Variable * string = variable_define( e, "string", VT_DSTRING, 0 );
    Variable * address = variable_define( e, "address", VT_ADDRESS, 0 );
    Variable * size = variable_define( e, "size", VT_BYTE, 0 );
    cpu_dsalloc_size( e, 32, string->realName );
    cpu_dsdescriptor( e, string->realName, address->realName, size->realName );
    cpu_bits_to_string( e, number->realName, address->realName, size->realName, 32 );

    _te->trackedVariables[0] = string;

}

int test_cpu_bits_to_string32_tester( TestEnvironment * _te ) {

    Variable * string = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return strcmp( string->valueString, "00000000000000000000000001010101" ) == 0 ||
            strcmp( string->valueString, "01010101" ) == 0;

}

//===========================================================================

void test_cpu_dswrite_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * st = variable_define( e, "st", VT_STRING, 0 );
    Variable * dy = variable_define( e, "dy", VT_DSTRING, 0 );
    Variable * address = variable_define( e, "address", VT_ADDRESS, 0 );
    Variable * size = variable_define( e, "size", VT_BYTE, 0 );
    Variable * address2 = variable_define( e, "address2", VT_ADDRESS, 0 );
    Variable * size2 = variable_define( e, "size2", VT_BYTE, 0 );
    variable_store_string( e, st->name, "test");
    cpu_dsdefine( e, st->realName, dy->realName );
    cpu_dsdescriptor( e, dy->realName, address->realName, size->realName );
    cpu_dswrite( e, dy->realName );
    cpu_dsdescriptor( e, dy->realName, address2->realName, size2->realName );

    _te->trackedVariables[0] = address;
    _te->trackedVariables[1] = address2;
    _te->trackedVariables[2] = dy;

}

int test_cpu_dswrite_tester( TestEnvironment * _te ) {

    Variable * address = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * address2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * dy = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );

    return ( address->value != address2->value ) && strcasecmp( dy->valueString, "test") == 0;

}

//===========================================================================

void test_cpu_dsgc_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * using = variable_import( e, "USING", VT_BYTE );

    Variable * st = variable_define( e, "st", VT_STRING, 0 );
    Variable * dy = variable_define( e, "dy", VT_DSTRING, 0 );
    Variable * zero = variable_define( e, "zero", VT_WORD, 0 );
    Variable * one = variable_define( e, "one", VT_WORD, 1 );
    Variable * false = variable_define( e, "false", VT_BYTE, 0 );
    Variable * true = variable_define( e, "true", VT_BYTE, 0xff );
    Variable * times = variable_define( e, "times", VT_WORD, 0 );
    Variable * limit = variable_define( e, "limit", VT_WORD, 257 );
    Variable * a = variable_define( e, "a", VT_WORD, 0 );
    Variable * b = variable_define( e, "b", VT_WORD, 0 );
    Variable * c = variable_define( e, "c", VT_WORD, 0 );
    Variable * d = variable_define( e, "d", VT_WORD, 0 );
    Variable * k = variable_define( e, "k", VT_BYTE, 0 );
    Variable * freeString = variable_retrieve( e, "FREE_STRING");

    variable_store_string( e, st->name, "test");
    cpu_dsdefine( e, st->realName, dy->realName );

    int i = 0;

    begin_loop( e );
        variable_move_naked( e, zero->name, a->name );
        variable_move_naked( e, zero->name, b->name );
        variable_move_naked( e, zero->name, c->name );
        variable_move_naked( e, zero->name, d->name );
        variable_move_naked( e, using->name, k->name );

        variable_store_string( e, st->name, "test");
        if_then( e, variable_and( e, variable_compare_not( e, using->name, false->name )->name, variable_compare_not( e, using->name, true->name )->name )->name );
            variable_move_naked( e, using->name, k->name );
            stop_test( e );
        end_if_then( e );

        variable_move_naked( e, one->name, a->name );
        cpu_dsdefine( e, st->realName, dy->realName );
        if_then( e, variable_and( e, variable_compare_not( e, using->name, false->name )->name, variable_compare_not( e, using->name, true->name )->name )->name );
            variable_move_naked( e, using->name, k->name );
            stop_test( e );
        end_if_then( e );

        variable_move_naked( e, one->name, b->name );
        cpu_dswrite( e, dy->realName );
        if_then( e, variable_and( e, variable_compare_not( e, using->name, false->name )->name, variable_compare_not( e, using->name, true->name )->name )->name );
            variable_move_naked( e, using->name, k->name );
            stop_test( e );
        end_if_then( e );

        variable_move_naked( e, one->name, c->name );
        cpu_dsfree( e, dy->realName );
        if_then( e, variable_and( e, variable_compare_not( e, using->name, false->name )->name, variable_compare_not( e, using->name, true->name )->name )->name );
            variable_move_naked( e, using->name, k->name );
            stop_test( e );
        end_if_then( e );

        variable_move_naked( e, one->name, d->name );
        variable_move( e, variable_add( e, times->name, one->name )->name, times->name );
        if_then( e, variable_compare( e, times->name, limit->name )->name );
            variable_move_naked( e, using->name, k->name );
            stop_test( e );
        end_if_then( e );
    end_loop( e );

    _te->trackedVariables[0] = dy;
    _te->trackedVariables[1] = a;
    _te->trackedVariables[2] = b;
    _te->trackedVariables[3] = c;
    _te->trackedVariables[4] = d;
    _te->trackedVariables[5] = times;
    _te->trackedVariables[6] = using;
    _te->trackedVariables[7] = k;
    _te->trackedVariables[8] = freeString;

}

int test_cpu_dsgc_tester( TestEnvironment * _te ) {

    Variable * dy = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * a = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * b = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * c = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * d = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );
    Variable * times = variable_retrieve( &_te->environment, _te->trackedVariables[5]->name );
    Variable * using = variable_retrieve( &_te->environment, _te->trackedVariables[6]->name );
    Variable * k = variable_retrieve( &_te->environment, _te->trackedVariables[7]->name );
    Variable * freeString = variable_retrieve( &_te->environment, _te->trackedVariables[8]->name );

    // printf("a = %2.2x\n", a->value );
    // printf("b = %2.2x\n", b->value );
    // printf("c = %2.2x\n", c->value );
    // printf("d = %2.2x\n", d->value );
    // printf("k = %2.2x\n", k->value );
    // printf("freeString = %d\n", freeString->value );
    // printf("times = %d\n", times->value );

    return  a->value == 1 &&
            b->value == 1 &&
            c->value == 1 &&
            d->value == 1;

}

//===========================================================================

void test_cpu_logical_and_8bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * true = variable_define( e, "true", VT_BYTE, 0xff );
    Variable * false = variable_define( e, "false", VT_BYTE, 0x00 );

    Variable * and00 = variable_define( e, "and00", VT_BYTE, 0x00 );
    Variable * and01 = variable_define( e, "and01", VT_BYTE, 0x00 );
    Variable * and10 = variable_define( e, "and10", VT_BYTE, 0x00 );
    Variable * and11 = variable_define( e, "and11", VT_BYTE, 0x00 );

    cpu_logical_and_8bit( e, false->realName, false->realName, and00->realName );
    cpu_logical_and_8bit( e, false->realName, true->realName, and01->realName );
    cpu_logical_and_8bit( e, true->realName, false->realName, and10->realName );
    cpu_logical_and_8bit( e, true->realName, true->realName, and11->realName );

    _te->trackedVariables[0] = and00;
    _te->trackedVariables[1] = and01;
    _te->trackedVariables[2] = and10;
    _te->trackedVariables[3] = and11;

}

int test_cpu_logical_and_8bit_tester( TestEnvironment * _te ) {

    Variable * and00 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * and01 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * and10 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * and11 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    return  and00->value == 0x00 && 
            and01->value == 0x00 && 
            and10->value == 0x00 && 
            and11->value == 0xff;

}

//===========================================================================

void test_cpu_logical_not_8bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * true = variable_define( e, "true", VT_BYTE, 0xff );
    Variable * false = variable_define( e, "false", VT_BYTE, 0x00 );

    Variable * not0 = variable_define( e, "not0", VT_BYTE, 0x00 );
    Variable * not1 = variable_define( e, "not1", VT_BYTE, 0x00 );

    cpu_logical_not_8bit( e, false->realName, not0->realName );
    cpu_logical_not_8bit( e, true->realName, not1->realName );

    _te->trackedVariables[0] = not0;
    _te->trackedVariables[1] = not1;

}

int test_cpu_logical_not_8bit_tester( TestEnvironment * _te ) {

    Variable * not0 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * not1 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return  not0->value == 0xff && 
            not1->value == 0x00;

}

void test_cpu( ) {

    create_test( "cpu_bits_to_string", &test_cpu_bits_to_string_payload, &test_cpu_bits_to_string_tester );    
    create_test( "cpu_bits_to_string32", &test_cpu_bits_to_string32_payload, &test_cpu_bits_to_string32_tester );    
    create_test( "cpu_dswrite", &test_cpu_dswrite_payload, &test_cpu_dswrite_tester );    
    create_test( "cpu_dsgc", &test_cpu_dsgc_payload, &test_cpu_dsgc_tester );    
    create_test( "cpu_logical_and_8bit", &test_cpu_logical_and_8bit_payload, &test_cpu_logical_and_8bit_tester );    
    create_test( "cpu_logical_not_8bit", &test_cpu_logical_not_8bit_payload, &test_cpu_logical_not_8bit_tester );    

}
