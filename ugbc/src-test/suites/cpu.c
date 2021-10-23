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

    char buffer[9]; 
    memset( buffer, 0, 9 );

    Variable * number = variable_define( e, "number", VT_BYTE, 2 );
    Variable * string = variable_define( e, "string", VT_BUFFER, 0 );
    Variable * address = variable_define( e, "address", VT_ADDRESS, 0x4100 );
    Variable * size = variable_define( e, "size", VT_BYTE, 0 );

    variable_store_buffer( e, string->name, buffer, 9, 0x4100 );
    
    cpu_bits_to_string( e, number->realName, address->realName, size->realName, 8 );

    _te->debug.inspections[0].name="string";
    _te->debug.inspections[0].address=0x4100;
    _te->debug.inspections[0].size=32;
    ++_te->debug.inspections_count;
    
    _te->trackedVariables[0] = size;

}

int test_cpu_bits_to_string_tester( TestEnvironment * _te ) {

    Variable * size = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    _te->debug.inspections[0].memory[size->value] = 0;

printf("memory = %s\n", _te->debug.inspections[0].memory );

    return strcmp( _te->debug.inspections[0].memory, "00000010" ) == 0;

}

//===========================================================================

void test_cpu_bits_to_string32_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    char buffer[33]; 
    memset( buffer, 0, 33 );

    Variable * number = variable_define( e, "number", VT_DWORD, 0x00000055 );
    Variable * string = variable_define( e, "string", VT_BUFFER, 0 );
    Variable * address = variable_define( e, "address", VT_ADDRESS, 0x4100 );
    Variable * size = variable_define( e, "size", VT_BYTE, 0 );

    variable_store_buffer( e, string->name, buffer, 9, 0x4100 );

    cpu_bits_to_string( e, number->realName, address->realName, size->realName, 32 );

    _te->debug.inspections[0].name="string";
    _te->debug.inspections[0].address=0x4100;
    _te->debug.inspections[0].size=32;
    ++_te->debug.inspections_count;
    
    _te->trackedVariables[0] = size;

}

int test_cpu_bits_to_string32_tester( TestEnvironment * _te ) {

    Variable * size = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    _te->debug.inspections[0].memory[size->value] = 0;

// printf("memory = %s\n", _te->debug.inspections[0].memory );

    return strcmp( _te->debug.inspections[0].memory, "00000000000000000000000001010101" ) == 0 ||
            strcmp( _te->debug.inspections[0].memory, "01010101" ) == 0;

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

    variable_store_string( e, st->name, "test");
    cpu_dsdefine( e, st->realName, dy->realName );
    cpu_dsgc( e );

    _te->trackedVariables[0] = using;

}

int test_cpu_dsgc_tester( TestEnvironment * _te ) {

    Variable * using = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

// printf( "using = %2.2x (%d) [expected 0xff]\n", using->value, using->value );

    return using->value == 0xff;

}

//===========================================================================

void test_cpu_dsgc_payloadA( TestEnvironment * _te ) {

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

int test_cpu_dsgc_testerA( TestEnvironment * _te ) {

    Variable * dy = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * a = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * b = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * c = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * d = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );
    Variable * times = variable_retrieve( &_te->environment, _te->trackedVariables[5]->name );
    Variable * using = variable_retrieve( &_te->environment, _te->trackedVariables[6]->name );
    Variable * k = variable_retrieve( &_te->environment, _te->trackedVariables[7]->name );
    Variable * freeString = variable_retrieve( &_te->environment, _te->trackedVariables[8]->name );

    return  a->value == 1 &&
            b->value == 1 &&
            c->value == 1 &&
            d->value == 1;

}

//===========================================================================

void test_cpu_dsgc_payloadB( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * using = variable_import( e, "USING", VT_BYTE );

    Variable * st = variable_define( e, "st", VT_STRING, 0 );
    Variable * dy = variable_define( e, "dy", VT_DSTRING, 0 );
    Variable * zero = variable_define( e, "zero", VT_WORD, 0 );
    Variable * one = variable_define( e, "one", VT_WORD, 1 );
    Variable * false = variable_define( e, "false", VT_BYTE, 0 );
    Variable * true = variable_define( e, "true", VT_BYTE, 0xff );
    Variable * four = variable_define( e, "four", VT_BYTE, 4 );
    Variable * times = variable_define( e, "times", VT_WORD, 0 );
    Variable * limit = variable_define( e, "limit", VT_WORD, 257 );
    Variable * a = variable_define( e, "a", VT_WORD, 0 );
    Variable * b = variable_define( e, "b", VT_WORD, 0 );
    Variable * b2 = variable_define( e, "b2", VT_WORD, 0 );
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

        variable_store_string( e, st->name, "test  ");
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

        variable_move_naked( e, one->name, b2->name );
        cpu_dsresize( e, dy->realName, four->realName );
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
    _te->trackedVariables[9] = b2;

}

int test_cpu_dsgc_testerB( TestEnvironment * _te ) {

    Variable * dy = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * a = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * b = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * c = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * d = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );
    Variable * times = variable_retrieve( &_te->environment, _te->trackedVariables[5]->name );
    Variable * using = variable_retrieve( &_te->environment, _te->trackedVariables[6]->name );
    Variable * k = variable_retrieve( &_te->environment, _te->trackedVariables[7]->name );
    Variable * freeString = variable_retrieve( &_te->environment, _te->trackedVariables[8]->name );
    Variable * b2 = variable_retrieve( &_te->environment, _te->trackedVariables[9]->name );

    return  a->value == 1 &&
            b->value == 1 &&
            c->value == 1 &&
            d->value == 1 &&
            b->value == 1;

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

// printf("and00 = %2.2x (%d) [expected 0x00]\n", and00->value, and00->value );
// printf("and01 = %2.2x (%d) [expected 0x00]\n", and01->value, and01->value );
// printf("and10 = %2.2x (%d) [expected 0x00]\n", and10->value, and10->value );
// printf("and11 = %2.2x (%d) [expected 0xff]\n", and11->value, and11->value );

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

//===========================================================================

void test_cpu_bit_check_extended_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * true = variable_define( e, "true", VT_BYTE, 0xff );
    Variable * false = variable_define( e, "false", VT_BYTE, 0x00 );

    Variable * value = variable_define( e, "value", VT_BYTE, 0x55 );

    Variable * pos0 = variable_define( e, "pos0", VT_BYTE, 0x00 );
    Variable * pos1 = variable_define( e, "pos1", VT_BYTE, 0x01 );
    Variable * pos2 = variable_define( e, "pos2", VT_BYTE, 0x02 );
    Variable * pos3 = variable_define( e, "pos3", VT_BYTE, 0x03 );
    Variable * pos4 = variable_define( e, "pos4", VT_BYTE, 0x04 );
    Variable * pos5 = variable_define( e, "pos5", VT_BYTE, 0x05 );
    Variable * pos6 = variable_define( e, "pos6", VT_BYTE, 0x06 );
    Variable * pos7 = variable_define( e, "pos7", VT_BYTE, 0x07 );

    Variable * result0 = variable_define( e, "result0", VT_BYTE, 0x00 );
    Variable * result1 = variable_define( e, "result1", VT_BYTE, 0x01 );
    Variable * result2 = variable_define( e, "result2", VT_BYTE, 0x02 );
    Variable * result3 = variable_define( e, "result3", VT_BYTE, 0x03 );
    Variable * result4 = variable_define( e, "result4", VT_BYTE, 0x04 );
    Variable * result5 = variable_define( e, "result5", VT_BYTE, 0x05 );
    Variable * result6 = variable_define( e, "result6", VT_BYTE, 0x06 );
    Variable * result7 = variable_define( e, "result7", VT_BYTE, 0x07 );

    cpu_bit_check_extended( e, value->realName, pos0->realName, result0->realName, VT_BITWIDTH( value->type ) );
    cpu_bit_check_extended( e, value->realName, pos1->realName, result1->realName, VT_BITWIDTH( value->type ) );
    cpu_bit_check_extended( e, value->realName, pos2->realName, result2->realName, VT_BITWIDTH( value->type ) );
    cpu_bit_check_extended( e, value->realName, pos3->realName, result3->realName, VT_BITWIDTH( value->type ) );
    cpu_bit_check_extended( e, value->realName, pos4->realName, result4->realName, VT_BITWIDTH( value->type ) );
    cpu_bit_check_extended( e, value->realName, pos5->realName, result5->realName, VT_BITWIDTH( value->type ) );
    cpu_bit_check_extended( e, value->realName, pos6->realName, result6->realName, VT_BITWIDTH( value->type ) );
    cpu_bit_check_extended( e, value->realName, pos7->realName, result7->realName, VT_BITWIDTH( value->type ) );
    
    _te->trackedVariables[0] = result0;
    _te->trackedVariables[1] = result1;
    _te->trackedVariables[2] = result2;
    _te->trackedVariables[3] = result3;
    _te->trackedVariables[4] = result4;
    _te->trackedVariables[5] = result5;
    _te->trackedVariables[6] = result6;
    _te->trackedVariables[7] = result7;

}

int test_cpu_bit_check_extended_tester( TestEnvironment * _te ) {

    Variable * result0 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * result1 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * result2 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * result3 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * result4 = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );
    Variable * result5 = variable_retrieve( &_te->environment, _te->trackedVariables[5]->name );
    Variable * result6 = variable_retrieve( &_te->environment, _te->trackedVariables[6]->name );
    Variable * result7 = variable_retrieve( &_te->environment, _te->trackedVariables[7]->name );

    // printf("result0: %2.2x [expected 0xff]\n", result0->value );
    // printf("result1: %2.2x [expected 0x00]\n", result1->value );
    // printf("result2: %2.2x [expected 0xff]\n", result2->value );
    // printf("result3: %2.2x [expected 0x00]\n", result3->value );
    // printf("result4: %2.2x [expected 0xff]\n", result4->value );
    // printf("result5: %2.2x [expected 0x00]\n", result5->value );
    // printf("result6: %2.2x [expected 0xff]\n", result6->value );
    // printf("result7: %2.2x [expected 0x00]\n", result7->value );

    return  result0->value == 0xff && 
            result1->value == 0x00 &&
            result2->value == 0xff && 
            result3->value == 0x00 &&
            result4->value == 0xff && 
            result5->value == 0x00 &&
            result6->value == 0xff && 
            result7->value == 0x00;

}

//===========================================================================

void test_cpu_less_than_8bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_BYTE, 0x42 );
    Variable * ub = variable_define( e, "ub", VT_BYTE, 0x84 );
    Variable * sa = variable_define( e, "sa", VT_SBYTE, 0x10 );
    Variable * sb = variable_define( e, "sb", VT_SBYTE, 0xF0 );

    Variable * resultu1 = variable_temporary( e,VT_BYTE, "(result unsigned 1)");
    Variable * results1 = variable_temporary( e,VT_BYTE, "(result signed 1)");
    Variable * resultu2 = variable_temporary( e,VT_BYTE, "(result unsigned 2)");
    Variable * results2 = variable_temporary( e,VT_BYTE, "(result signed 2)");

    cpu_less_than_8bit( e, ua->realName, ub->realName, resultu1->realName, 0, 0 );
    cpu_less_than_8bit( e, ub->realName, ua->realName, resultu2->realName, 0, 0 );
    cpu_less_than_8bit( e, sa->realName, sb->realName, results1->realName, 0, 1 );
    cpu_less_than_8bit( e, sb->realName, sa->realName, results2->realName, 0, 1 );

    _te->trackedVariables[0] = resultu1;
    _te->trackedVariables[1] = resultu2;
    _te->trackedVariables[2] = results1;
    _te->trackedVariables[3] = results2;

}

int test_cpu_less_than_8bit_tester( TestEnvironment * _te ) {

    Variable * resultu1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * resultu2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * results1 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * results2 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    // printf( "ru1 = %2.2x (expected: 0xff)\n", resultu1->value );
    // printf( "ru2 = %2.2x (expected: 0x00)\n", resultu2->value );
    // printf( "rs1 = %2.2x (expected: 0x00)\n", results1->value );
    // printf( "rs2 = %2.2x (expected: 0xff)\n", results2->value );

    return  resultu1->value == 0xff && 
            resultu2->value == 0x00 &&
            results1->value == 0x00 && 
            results2->value == 0xff;

}

//===========================================================================

void test_cpu_less_than_16bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_WORD, 0x4242 );
    Variable * ub = variable_define( e, "ub", VT_WORD, 0x8484 );
    Variable * sa = variable_define( e, "sa", VT_SWORD, 0x1000 );
    Variable * sb = variable_define( e, "sb", VT_SWORD, 0xFF00 );

    Variable * resultu1 = variable_temporary( e,VT_BYTE, "(result unsigned 1)");
    Variable * results1 = variable_temporary( e,VT_BYTE, "(result signed 1)");
    Variable * resultu2 = variable_temporary( e,VT_BYTE, "(result unsigned 2)");
    Variable * results2 = variable_temporary( e,VT_BYTE, "(result signed 2)");
    Variable * resultu3 = variable_temporary( e,VT_BYTE, "(result unsigned 1)");
    Variable * results3 = variable_temporary( e,VT_BYTE, "(result signed 1)");
    Variable * resultu4 = variable_temporary( e,VT_BYTE, "(result unsigned 2)");
    Variable * results4 = variable_temporary( e,VT_BYTE, "(result signed 2)");
    Variable * resultu5 = variable_temporary( e,VT_BYTE, "(result unsigned 2)");
    Variable * results5 = variable_temporary( e,VT_BYTE, "(result signed 2)");

    cpu_less_than_16bit( e, ua->realName, ub->realName, resultu1->realName, 0, 0 );
    cpu_less_than_16bit( e, ub->realName, ua->realName, resultu2->realName, 0, 0 );
    cpu_less_than_16bit( e, sa->realName, sb->realName, results1->realName, 0, 1 );
    cpu_less_than_16bit( e, sb->realName, sa->realName, results2->realName, 0, 1 );
    cpu_less_than_16bit( e, ua->realName, ub->realName, resultu3->realName, 1, 0 );
    cpu_less_than_16bit( e, ub->realName, ua->realName, resultu4->realName, 1, 0 );
    cpu_less_than_16bit( e, sa->realName, sb->realName, results3->realName, 1, 1 );
    cpu_less_than_16bit( e, sb->realName, sa->realName, results4->realName, 1, 1 );
    cpu_less_than_16bit( e, ua->realName, ua->realName, resultu5->realName, 1, 0 );
    cpu_less_than_16bit( e, sa->realName, sa->realName, results5->realName, 1, 1 );

    _te->trackedVariables[0] = resultu1;
    _te->trackedVariables[1] = resultu2;
    _te->trackedVariables[2] = results1;
    _te->trackedVariables[3] = results2;
    _te->trackedVariables[4] = resultu3;
    _te->trackedVariables[5] = resultu4;
    _te->trackedVariables[6] = results3;
    _te->trackedVariables[7] = results4;
    _te->trackedVariables[8] = resultu5;
    _te->trackedVariables[9] = results5;

}

int test_cpu_less_than_16bit_tester( TestEnvironment * _te ) {

    Variable * resultu1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * resultu2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * results1 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * results2 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * resultu3 = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );
    Variable * resultu4 = variable_retrieve( &_te->environment, _te->trackedVariables[5]->name );
    Variable * results3 = variable_retrieve( &_te->environment, _te->trackedVariables[6]->name );
    Variable * results4 = variable_retrieve( &_te->environment, _te->trackedVariables[7]->name );
    Variable * resultu5 = variable_retrieve( &_te->environment, _te->trackedVariables[8]->name );
    Variable * results5 = variable_retrieve( &_te->environment, _te->trackedVariables[9]->name );

    // printf( "ru1 = %2.2x\n", resultu1->value );
    // printf( "ru2 = %2.2x\n", resultu2->value );
    // printf( "rs1 = %2.2x\n", results1->value );
    // printf( "rs2 = %2.2x\n", results2->value );
    // printf( "ru3 = %2.2x\n", resultu3->value );
    // printf( "ru4 = %2.2x\n", resultu4->value );
    // printf( "rs3 = %2.2x\n", results3->value );
    // printf( "rs4 = %2.2x\n", results4->value );
    // printf( "ru5 = %2.2x\n", resultu5->value );
    // printf( "rs5 = %2.2x\n", results5->value );

    return  resultu1->value == 0xff && 
            resultu2->value == 0x00 &&
            results1->value == 0x00 && 
            results2->value == 0xff &&
            resultu3->value == 0xff && 
            resultu4->value == 0x00 &&
            results3->value == 0x00 && 
            results4->value == 0xff &&
            resultu5->value == 0xff && 
            results5->value == 0xff
            ;

}

//===========================================================================

void test_cpu_less_than_16bit_payloadB( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_WORD, 0x4242 );
    Variable * ub = variable_define( e, "ub", VT_WORD, 0x4284 );
    Variable * sa = variable_define( e, "sa", VT_SWORD, 0xFFF0 );
    Variable * sb = variable_define( e, "sb", VT_SWORD, 0xFF00 );

    Variable * resultu1 = variable_temporary( e,VT_BYTE, "(result unsigned 1)");
    Variable * results1 = variable_temporary( e,VT_BYTE, "(result signed 1)");
    Variable * resultu2 = variable_temporary( e,VT_BYTE, "(result unsigned 2)");
    Variable * results2 = variable_temporary( e,VT_BYTE, "(result signed 2)");
    Variable * resultu3 = variable_temporary( e,VT_BYTE, "(result unsigned 2)");
    Variable * results3 = variable_temporary( e,VT_BYTE, "(result signed 2)");

    cpu_less_than_16bit( e, ua->realName, ub->realName, resultu1->realName, 0, 0 );
    cpu_less_than_16bit( e, ub->realName, ua->realName, resultu2->realName, 0, 0 );
    cpu_less_than_16bit( e, sa->realName, sb->realName, results1->realName, 0, 1 );
    cpu_less_than_16bit( e, sb->realName, sa->realName, results2->realName, 0, 1 );
    cpu_less_than_16bit( e, ua->realName, ua->realName, resultu3->realName, 1, 0 );
    cpu_less_than_16bit( e, sb->realName, sa->realName, results3->realName, 1, 1 );

    _te->trackedVariables[0] = resultu1;
    _te->trackedVariables[1] = resultu2;
    _te->trackedVariables[2] = results1;
    _te->trackedVariables[3] = results2;
    _te->trackedVariables[4] = resultu3;
    _te->trackedVariables[5] = results3;

}

int test_cpu_less_than_16bit_testerB( TestEnvironment * _te ) {

    Variable * resultu1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * resultu2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * results1 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * results2 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * resultu3 = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );
    Variable * results3 = variable_retrieve( &_te->environment, _te->trackedVariables[5]->name );

    return  resultu1->value == 0xff && 
            resultu2->value == 0x00 &&
            results1->value == 0x00 && 
            results2->value == 0xff &&
            resultu3->value == 0xff &&
            results3->value == 0xff
            ;

}

//===========================================================================

void test_cpu_less_than_32bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_DWORD, 0x42000042 );
    Variable * ub = variable_define( e, "ub", VT_DWORD, 0x84000084 );
    Variable * sa = variable_define( e, "sa", VT_SDWORD, 0x1000000 );
    Variable * sb = variable_define( e, "sb", VT_SDWORD, 0xFFFF0000 );
    Variable * sc = variable_define( e, "sc", VT_SDWORD, 0xFFFF0000 );
    Variable * sd = variable_define( e, "sd", VT_SDWORD, 0xFFFF0000 );

    Variable * resultu1 = variable_temporary( e,VT_BYTE, "(result unsigned 1)");
    Variable * results1 = variable_temporary( e,VT_BYTE, "(result signed 1)");
    Variable * resultu2 = variable_temporary( e,VT_BYTE, "(result unsigned 2)");
    Variable * results2 = variable_temporary( e,VT_BYTE, "(result signed 2)");
    Variable * results3 = variable_temporary( e,VT_BYTE, "(result signed 3)");
    Variable * results4 = variable_temporary( e,VT_BYTE, "(result signed 4)");

    cpu_less_than_32bit( e, ua->realName, ub->realName, resultu1->realName, 0, 0 );
    cpu_less_than_32bit( e, ub->realName, ua->realName, resultu2->realName, 0, 0 );
    cpu_less_than_32bit( e, sa->realName, sb->realName, results1->realName, 0, 1 );
    cpu_less_than_32bit( e, sb->realName, sa->realName, results2->realName, 0, 1 );
    cpu_less_than_32bit( e, sc->realName, sd->realName, results3->realName, 0, 1 );
    cpu_less_than_32bit( e, sd->realName, sc->realName, results4->realName, 1, 1 );

    _te->trackedVariables[0] = resultu1;
    _te->trackedVariables[1] = resultu2;
    _te->trackedVariables[2] = results1;
    _te->trackedVariables[3] = results2;
    _te->trackedVariables[4] = results3;
    _te->trackedVariables[5] = results4;

}

int test_cpu_less_than_32bit_tester( TestEnvironment * _te ) {

    Variable * resultu1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * resultu2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * results1 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * results2 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * results3 = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );
    Variable * results4 = variable_retrieve( &_te->environment, _te->trackedVariables[5]->name );

    return  resultu1->value == 0xff && 
            resultu2->value == 0x00 &&
            results1->value == 0x00 && 
            results2->value == 0xff &&
            results3->value == 0x00 && 
            results4->value == 0xff
            ;

}

//////////////

//===========================================================================

void test_cpu_greater_than_8bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_BYTE, 0x42 );
    Variable * ub = variable_define( e, "ub", VT_BYTE, 0x84 );
    Variable * sa = variable_define( e, "sa", VT_SBYTE, 0x10 );
    Variable * sb = variable_define( e, "sb", VT_SBYTE, 0xF0 );

    Variable * resultu1 = variable_temporary( e,VT_BYTE, "(result unsigned 1)");
    Variable * results1 = variable_temporary( e,VT_BYTE, "(result signed 1)");
    Variable * resultu2 = variable_temporary( e,VT_BYTE, "(result unsigned 2)");
    Variable * results2 = variable_temporary( e,VT_BYTE, "(result signed 2)");

    cpu_greater_than_8bit( e, ua->realName, ub->realName, resultu1->realName, 0, 0 );
    cpu_greater_than_8bit( e, ub->realName, ua->realName, resultu2->realName, 0, 0 );
    cpu_greater_than_8bit( e, sa->realName, sb->realName, results1->realName, 0, 1 );
    cpu_greater_than_8bit( e, sb->realName, sa->realName, results2->realName, 0, 1 );

    _te->trackedVariables[0] = resultu1;
    _te->trackedVariables[1] = resultu2;
    _te->trackedVariables[2] = results1;
    _te->trackedVariables[3] = results2;

}

int test_cpu_greater_than_8bit_tester( TestEnvironment * _te ) {

    Variable * resultu1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * resultu2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * results1 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * results2 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    return  resultu1->value == 0x00 && 
            resultu2->value == 0xff &&
            results1->value == 0xff && 
            results2->value == 0x00;

}

//===========================================================================

void test_cpu_greater_than_16bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_WORD, 0x4242 );
    Variable * ub = variable_define( e, "ub", VT_WORD, 0x8484 );
    Variable * sa = variable_define( e, "sa", VT_SWORD, 0x1000 );
    Variable * sb = variable_define( e, "sb", VT_SWORD, 0xFF00 );

    Variable * resultu1 = variable_temporary( e,VT_BYTE, "(result unsigned 1)");
    Variable * results1 = variable_temporary( e,VT_BYTE, "(result signed 1)");
    Variable * resultu2 = variable_temporary( e,VT_BYTE, "(result unsigned 2)");
    Variable * results2 = variable_temporary( e,VT_BYTE, "(result signed 2)");

    cpu_greater_than_16bit( e, ua->realName, ub->realName, resultu1->realName, 0, 0 );
    cpu_greater_than_16bit( e, ub->realName, ua->realName, resultu2->realName, 0, 0 );
    cpu_greater_than_16bit( e, sa->realName, sb->realName, results1->realName, 0, 1 );
    cpu_greater_than_16bit( e, sb->realName, sa->realName, results2->realName, 0, 1 );

    _te->trackedVariables[0] = resultu1;
    _te->trackedVariables[1] = resultu2;
    _te->trackedVariables[2] = results1;
    _te->trackedVariables[3] = results2;

}

int test_cpu_greater_than_16bit_tester( TestEnvironment * _te ) {

    Variable * resultu1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * resultu2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * results1 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * results2 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    return  resultu1->value == 0x00 && 
            resultu2->value == 0xff &&
            results1->value == 0xff && 
            results2->value == 0x00;

}

//===========================================================================

void test_cpu_greater_than_32bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_DWORD, 0x42000042 );
    Variable * ub = variable_define( e, "ub", VT_DWORD, 0x84000084 );
    Variable * sa = variable_define( e, "sa", VT_SDWORD, 0x1000000 );
    Variable * sb = variable_define( e, "sb", VT_SDWORD, 0xFF00FF00 );

    Variable * resultu1 = variable_temporary( e,VT_BYTE, "(result unsigned 1)");
    Variable * results1 = variable_temporary( e,VT_BYTE, "(result signed 1)");
    Variable * resultu2 = variable_temporary( e,VT_BYTE, "(result unsigned 2)");
    Variable * results2 = variable_temporary( e,VT_BYTE, "(result signed 2)");

    cpu_greater_than_32bit( e, ua->realName, ub->realName, resultu1->realName, 0, 0 );
    cpu_greater_than_32bit( e, ub->realName, ua->realName, resultu2->realName, 0, 0 );
    cpu_greater_than_32bit( e, sa->realName, sb->realName, results1->realName, 0, 1 );
    cpu_greater_than_32bit( e, sb->realName, sa->realName, results2->realName, 0, 1 );

    _te->trackedVariables[0] = resultu1;
    _te->trackedVariables[1] = resultu2;
    _te->trackedVariables[2] = results1;
    _te->trackedVariables[3] = results2;

}

int test_cpu_greater_than_32bit_tester( TestEnvironment * _te ) {

    Variable * resultu1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * resultu2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * results1 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * results2 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    return  resultu1->value == 0x00 && 
            resultu2->value == 0xff &&
            results1->value == 0xff && 
            results2->value == 0x00;

}

//===========================================================================

void test_cpu_math_div2_8bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_BYTE, 0x21 );
    Variable * sa = variable_define( e, "sa", VT_SBYTE, 0xf8 );

    cpu_math_div2_8bit( e, ua->realName, 1, 0  );
    cpu_math_div2_8bit( e, sa->realName, 1, 1  );

    _te->trackedVariables[0] = ua;
    _te->trackedVariables[1] = sa;

}

int test_cpu_math_div2_8bit_tester( TestEnvironment * _te ) {

    Variable * ua = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * sa = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

// printf("ua = %2.2x (%d) [expected 0x10]\n", ua->value, ua->value );
// printf("sa = %2.2x (%d) [expected -4]\n", sa->value, sa->value );

    return  ua->value == 0x10 && 
            sa->value == -4;

}

//===========================================================================

void test_cpu_math_div2_const_16bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_WORD, 0x2121 );
    Variable * sa = variable_define( e, "sa", VT_SWORD, 0xfff8 );

    cpu_math_div2_const_16bit( e, ua->realName, 1, 0  );
    cpu_math_div2_const_16bit( e, sa->realName, 1, 1  );

    _te->trackedVariables[0] = ua;
    _te->trackedVariables[1] = sa;

}

int test_cpu_math_div2_const_16bit_tester( TestEnvironment * _te ) {

    Variable * ua = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * sa = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return  ua->value == 0x1090 && 
            sa->value == -4;

}

//===========================================================================

void test_cpu_math_div2_const_32bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_DWORD, 0x21212121 );
    Variable * sa = variable_define( e, "sa", VT_SDWORD, 0xfffffff8 );

    cpu_math_div2_const_32bit( e, ua->realName, 1, 0  );
    cpu_math_div2_const_32bit( e, sa->realName, 1, 1  );

    _te->trackedVariables[0] = ua;
    _te->trackedVariables[1] = sa;

}

int test_cpu_math_div2_const_32bit_tester( TestEnvironment * _te ) {

    Variable * ua = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * sa = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    // printf("ua = %8.8x (%d) [expected 0x10909090]\n", ua->value, ua->value );
    // printf("sa = %8.8x (%d) [expected -4]\n", sa->value, sa->value );

    return  ua->value == 0x10909090 && 
            sa->value == -4;

}

//===========================================================================

void test_cpu_math_div2_const_8bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_BYTE, 0x21 );
    Variable * sa = variable_define( e, "sa", VT_SBYTE, 0xf8 );

    cpu_math_div2_const_8bit( e, ua->realName, 1, 0  );
    cpu_math_div2_const_8bit( e, sa->realName, 1, 1  );

    _te->trackedVariables[0] = ua;
    _te->trackedVariables[1] = sa;

}

int test_cpu_math_div2_const_8bit_tester( TestEnvironment * _te ) {

    Variable * ua = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * sa = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

// printf( "ua = %2.2x (%d) [expected 0x10]\n", ua->value, ua->value );
// printf( "sa = %2.2x (%d) [expected -4]\n", sa->value, sa->value );

    return  ua->value == 0x10 && 
            sa->value == -4;

}

//===========================================================================

void test_cpu_math_double_16bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_WORD, 0x2121 );
    Variable * sa = variable_define( e, "sa", VT_SWORD, 0xfff8 );

    cpu_math_double_16bit( e, ua->realName, ua->realName, 0  );
    cpu_math_double_16bit( e, sa->realName, sa->realName, 1  );

    _te->trackedVariables[0] = ua;
    _te->trackedVariables[1] = sa;

}

int test_cpu_math_double_16bit_tester( TestEnvironment * _te ) {

    Variable * ua = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * sa = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return  ua->value == 0x4242 && 
            sa->value == -16;

}

//===========================================================================

void test_cpu_math_double_32bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_DWORD, 0x21212121 );
    Variable * sa = variable_define( e, "sa", VT_SDWORD, 0xfffffff8 );

    cpu_math_double_32bit( e, ua->realName, ua->realName, 0  );
    cpu_math_double_32bit( e, sa->realName, sa->realName, 1  );

    _te->trackedVariables[0] = ua;
    _te->trackedVariables[1] = sa;

}

int test_cpu_math_double_32bit_tester( TestEnvironment * _te ) {

    Variable * ua = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * sa = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return  ua->value == 0x42424242 && 
            sa->value == -16;

}

//===========================================================================

void test_cpu_math_double_8bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_BYTE, 0x21 );
    Variable * sa = variable_define( e, "sa", VT_SBYTE, 0xec );

    cpu_math_double_8bit( e, ua->realName, ua->realName, 0  );
    cpu_math_double_8bit( e, sa->realName, sa->realName, 1  );

    _te->trackedVariables[0] = ua;
    _te->trackedVariables[1] = sa;

}

int test_cpu_math_double_8bit_tester( TestEnvironment * _te ) {

    Variable * ua = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * sa = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return  ua->value == 0x42 && 
            sa->value == -40;

}

//===========================================================================

void test_cpu_math_mul_16bit_to_32bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_WORD, 0x2121 );
    Variable * ub = variable_define( e, "ub", VT_WORD, 0x1010 );
    Variable * sa = variable_define( e, "sa", VT_WORD, 0xfff8 );
    Variable * sb = variable_define( e, "sb", VT_WORD, 0xfff0 );
    Variable * resultu = variable_temporary( e, VT_DWORD, "(result unsigned)" );
    Variable * results = variable_temporary( e, VT_DWORD, "(result signed)" );

    cpu_math_mul_16bit_to_32bit( e, ua->realName, ub->realName, resultu->realName, 0 );
    cpu_math_mul_16bit_to_32bit( e, sa->realName, sb->realName, results->realName, 1 );

    _te->trackedVariables[0] = resultu;
    _te->trackedVariables[1] = results;

}

int test_cpu_math_mul_16bit_to_32bit_tester( TestEnvironment * _te ) {

    Variable * resultu = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * results = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

// printf( "resultu = %8.8x (%d) [expected 0x2142210]\n", resultu->value, resultu->value );
// printf( "results = %8.8x (%d) [expected 0x80]\n", results->value, results->value );
    
    return  resultu->value == 0x2142210 && 
            results->value == 0x80;

}

//===========================================================================

void test_cpu_math_mul_8bit_to_16bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_BYTE, 0x21 );
    Variable * ub = variable_define( e, "ub", VT_BYTE, 0x10 );
    Variable * sa = variable_define( e, "sa", VT_SBYTE, 0xf8 );
    Variable * sb = variable_define( e, "sb", VT_SBYTE, 0xf0 );
    Variable * resultu = variable_temporary( e, VT_WORD, "(result unsigned)" );
    Variable * results = variable_temporary( e, VT_SWORD, "(result signed)" );

    cpu_math_mul_8bit_to_16bit( e, ua->realName, ub->realName, resultu->realName, 0 );
    cpu_math_mul_8bit_to_16bit( e, sa->realName, sb->realName, results->realName, 1 );

    _te->trackedVariables[0] = resultu;
    _te->trackedVariables[1] = results;

}

int test_cpu_math_mul_8bit_to_16bit_tester( TestEnvironment * _te ) {

    Variable * resultu = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * results = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

// printf( "resultu = %4.4x (%d) [expected 0x210]\n", resultu->value, resultu->value );
// printf( "results = %4.4x (%d) [expected 128]\n", results->value, results->value );

    return  resultu->value == 0X210 && 
            results->value == 128;

}

//===========================================================================

void test_cpu_math_div_32bit_to_16bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_DWORD, 0x21212121 );
    Variable * ub = variable_define( e, "ub", VT_DWORD, 0x10101010 );
    Variable * sa = variable_define( e, "sa", VT_SDWORD, 0xfffffff8 );
    Variable * sb = variable_define( e, "sb", VT_SDWORD, 0xfffffff0 );
    Variable * resultu = variable_temporary( e, VT_WORD, "(result unsigned)" );
    Variable * remainderu = variable_temporary( e, VT_WORD, "(result unsigned)" );
    Variable * results = variable_temporary( e, VT_SWORD, "(result unsigned)" );
    Variable * remainders = variable_temporary( e, VT_SWORD, "(result signed)" );

    cpu_math_div_32bit_to_16bit( e, ua->realName, ub->realName, resultu->realName, remainderu->realName, 0 );
    cpu_math_div_32bit_to_16bit( e, sa->realName, sb->realName, results->realName, remainders->realName, 1 );

    _te->trackedVariables[0] = resultu;
    _te->trackedVariables[1] = results;
    _te->trackedVariables[2] = remainderu;
    _te->trackedVariables[3] = remainders;

}

int test_cpu_math_div_32bit_to_16bit_tester( TestEnvironment * _te ) {

    Variable * resultu = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * results = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * remainderu = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * remainders = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    return  resultu->value == 0x2 &&
            remainderu->value == 0x1010101 && 
            results->value == 0x1 && 
            remainders->value == 0x1;

}

//===========================================================================

void test_cpu_math_div_16bit_to_16bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_WORD, 0x2121 );
    Variable * ub = variable_define( e, "ub", VT_WORD, 0x1010 );
    Variable * sa = variable_define( e, "sa", VT_SWORD, 0xfff8 );
    Variable * sb = variable_define( e, "sb", VT_SWORD, 0xfff0 );
    Variable * resultu = variable_temporary( e, VT_WORD, "(result unsigned)" );
    Variable * remainderu = variable_temporary( e, VT_WORD, "(result unsigned)" );
    Variable * results = variable_temporary( e, VT_SWORD, "(result unsigned)" );
    Variable * remainders = variable_temporary( e, VT_SWORD, "(result signed)" );

    cpu_math_div_16bit_to_16bit( e, ua->realName, ub->realName, resultu->realName, remainderu->realName, 0 );
    cpu_math_div_16bit_to_16bit( e, sa->realName, sb->realName, results->realName, remainders->realName, 1 );

    _te->trackedVariables[0] = resultu;
    _te->trackedVariables[1] = results;
    _te->trackedVariables[2] = remainderu;
    _te->trackedVariables[3] = remainders;

}

int test_cpu_math_div_16bit_to_16bit_tester( TestEnvironment * _te ) {

    Variable * resultu = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * results = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * remainderu = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * remainders = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    // printf("resultu = %4.4x (%d) [expected 0x2]\n", resultu->value, resultu->value );
    // printf("remainderu = %4.4x (%d) [expected 0x101]\n", remainderu->value, remainderu->value );
    // printf("results = %4.4x (%d) [expected 0x0]\n", results->value, results->value );
    // printf("remainders = %4.4x (%d) [expected 0x0008]\n", remainders->value, remainders->value );
    
    return  resultu->value == 0x2 &&
            remainderu->value == 0x101 && 
            results->value == 0x0 && 
            remainders->value == 0X0008;

}

//===========================================================================

void test_cpu_math_div_16bit_to_16bit_payloadB( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_WORD, 320 );
    Variable * ub = variable_define( e, "ub", VT_WORD, 2 );
    Variable * sa = variable_define( e, "sa", VT_SWORD, 320 );
    Variable * sb = variable_define( e, "sb", VT_SWORD, 2 );
    Variable * resultu = variable_temporary( e, VT_WORD, "(result unsigned)" );
    Variable * remainderu = variable_temporary( e, VT_WORD, "(result unsigned)" );
    Variable * results = variable_temporary( e, VT_SWORD, "(result unsigned)" );
    Variable * remainders = variable_temporary( e, VT_SWORD, "(result signed)" );

    cpu_math_div_16bit_to_16bit( e, ua->realName, ub->realName, resultu->realName, remainderu->realName, 0 );
    cpu_math_div_16bit_to_16bit( e, sa->realName, sb->realName, results->realName, remainders->realName, 1 );

    _te->trackedVariables[0] = resultu;
    _te->trackedVariables[1] = results;
    _te->trackedVariables[2] = remainderu;
    _te->trackedVariables[3] = remainders;

}

int test_cpu_math_div_16bit_to_16bit_testerB( TestEnvironment * _te ) {

    Variable * resultu = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * results = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * remainderu = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * remainders = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );


    // printf("resultu = %4.4x (%d) [expected 160]\n", resultu->value, resultu->value );
    // printf("remainderu = %4.4x (%d) [expected 0]\n", remainderu->value, remainderu->value );
    // printf("results = %4.4x (%d) [expected 160]\n", results->value, results->value );
    // printf("remainders = %4.4x (%d) [expected 0]\n", remainders->value, remainders->value );

    return  resultu->value == 160 &&
            remainderu->value == 0 && 
            results->value == 160 && 
            remainders->value == 0;

}

//===========================================================================

void test_cpu_math_div_16bit_to_16bit_payloadC( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_WORD, 90 );
    Variable * ub = variable_define( e, "ub", VT_WORD, 60 );
    Variable * sa = variable_define( e, "sa", VT_SWORD, 130 );
    Variable * sb = variable_define( e, "sb", VT_SWORD, 60 );
    Variable * resultu = variable_temporary( e, VT_WORD, "(result unsigned)" );
    Variable * remainderu = variable_temporary( e, VT_WORD, "(result unsigned)" );
    Variable * results = variable_temporary( e, VT_SWORD, "(result unsigned)" );
    Variable * remainders = variable_temporary( e, VT_SWORD, "(result signed)" );

    cpu_math_div_16bit_to_16bit( e, ua->realName, ub->realName, resultu->realName, remainderu->realName, 0 );
    cpu_math_div_16bit_to_16bit( e, sa->realName, sb->realName, results->realName, remainders->realName, 1 );

    _te->trackedVariables[0] = resultu;
    _te->trackedVariables[1] = results;
    _te->trackedVariables[2] = remainderu;
    _te->trackedVariables[3] = remainders;

}

int test_cpu_math_div_16bit_to_16bit_testerC( TestEnvironment * _te ) {

    Variable * resultu = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * results = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * remainderu = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * remainders = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    // printf("resultu = %4.4x (%d) [expected 1]\n", resultu->value, resultu->value );
    // printf("remainderu = %4.4x (%d) [expected30]\n", remainderu->value, remainderu->value );
    // printf("results = %4.4x (%d) [expected 2]\n", results->value, results->value );
    // printf("remainders = %4.4x (%d) [expected 10]\n", remainders->value, remainders->value );
    
    return  resultu->value == 1 &&
            remainderu->value == 30 && 
            results->value == 2 && 
            remainders->value == 10;

}

//===========================================================================

void test_cpu_math_div_16bit_to_16bit_payloadD( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_WORD, 62 );
    Variable * ub = variable_define( e, "ub", VT_WORD, 60 );
    Variable * sa = variable_define( e, "sa", VT_SWORD, 62 );
    Variable * sb = variable_define( e, "sb", VT_SWORD, 60 );
    Variable * resultu = variable_temporary( e, VT_WORD, "(result unsigned)" );
    Variable * remainderu = variable_temporary( e, VT_WORD, "(result unsigned)" );
    Variable * results = variable_temporary( e, VT_SWORD, "(result unsigned)" );
    Variable * remainders = variable_temporary( e, VT_SWORD, "(result signed)" );

    cpu_math_div_16bit_to_16bit( e, ua->realName, ub->realName, resultu->realName, remainderu->realName, 0 );
    cpu_math_div_16bit_to_16bit( e, sa->realName, sb->realName, results->realName, remainders->realName, 1 );

    _te->trackedVariables[0] = resultu;
    _te->trackedVariables[1] = results;
    _te->trackedVariables[2] = remainderu;
    _te->trackedVariables[3] = remainders;

}

int test_cpu_math_div_16bit_to_16bit_testerD( TestEnvironment * _te ) {

    Variable * resultu = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * results = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * remainderu = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * remainders = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    // printf("resultu = %4.4x (%d) [expected 1]\n", resultu->value, resultu->value );
    // printf("remainderu = %4.4x (%d) [expected 2]\n", remainderu->value, remainderu->value );
    // printf("results = %4.4x (%d) [expected 1]\n", results->value, results->value );
    // printf("remainders = %4.4x (%d) [expected 2]\n", remainders->value, remainders->value );
    
    return  resultu->value == 1 &&
            remainderu->value == 2 && 
            results->value == 1 && 
            remainders->value == 2;

}

//===========================================================================

void test_cpu_math_div_8bit_to_8bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_BYTE, 0x21 );
    Variable * ub = variable_define( e, "ub", VT_BYTE, 0x10 );
    Variable * sa = variable_define( e, "sa", VT_SBYTE, 0xf8 );
    Variable * sb = variable_define( e, "sb", VT_SBYTE, 0xf0 );
    Variable * resultu = variable_temporary( e, VT_BYTE, "(result unsigned)" );
    Variable * remainderu = variable_temporary( e, VT_BYTE, "(result unsigned)" );
    Variable * results = variable_temporary( e, VT_SBYTE, "(result unsigned)" );
    Variable * remainders = variable_temporary( e, VT_SBYTE, "(result signed)" );

    cpu_math_div_8bit_to_8bit( e, ua->realName, ub->realName, resultu->realName, remainderu->realName, 0 );
    cpu_math_div_8bit_to_8bit( e, sa->realName, sb->realName, results->realName, remainders->realName, 1 );

    _te->trackedVariables[0] = resultu;
    _te->trackedVariables[1] = results;
    _te->trackedVariables[2] = remainderu;
    _te->trackedVariables[3] = remainders;

}

int test_cpu_math_div_8bit_to_8bit_tester( TestEnvironment * _te ) {

    Variable * resultu = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * results = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * remainderu = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * remainders = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    // printf("resultu = %2.2x (%d) [expected 0x2 (2)]\n", resultu->value, resultu->value );
    // printf("remainderu = %2.2x (%d) [expected 0x1 (1)]\n", remainderu->value, remainderu->value );
    // printf("results = %2.2x (%d) [expected 0x0 (0)]\n", results->value, results->value );
    // printf("remainders = %2.2x (%d) [expected 0x8 (8)]\n", remainders->value, remainders->value );

    return  resultu->value == 0x2 &&
            remainderu->value == 0x1 && 
            results->value == 0x0 && 
            remainders->value == 0x8;

}

//===========================================================================

void test_cpu_math_mul2_const_16bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_WORD, 0x2121 );
    Variable * sa = variable_define( e, "sa", VT_SWORD, 0xfff8 );

    cpu_math_mul2_const_16bit( e, ua->realName, 1, 0 );
    cpu_math_mul2_const_16bit( e, sa->realName, 1, 1 );

    _te->trackedVariables[0] = ua;
    _te->trackedVariables[1] = sa;

}

int test_cpu_math_mul2_const_16bit_tester( TestEnvironment * _te ) {

    Variable * ua = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * sa = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return  ua->value == 0x4242 &&
            sa->value == -16;

}

//===========================================================================

void test_cpu_math_mul2_const_32bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_DWORD, 0x21212121 );
    Variable * sa = variable_define( e, "sa", VT_SDWORD, 0xfffffff8 );

    cpu_math_mul2_const_32bit( e, ua->realName, 1, 0 );
    cpu_math_mul2_const_32bit( e, sa->realName, 1, 1 );

    _te->trackedVariables[0] = ua;
    _te->trackedVariables[1] = sa;

}

int test_cpu_math_mul2_const_32bit_tester( TestEnvironment * _te ) {

    Variable * ua = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * sa = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return  ua->value == 0x42424242 &&
            sa->value == -16;

}

//===========================================================================

void test_cpu_math_mul2_const_8bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * ua = variable_define( e, "ua", VT_BYTE, 0x21 );
    Variable * sa = variable_define( e, "sa", VT_SBYTE, 0xf8 );

    cpu_math_mul2_const_8bit( e, ua->realName, 1, 0 );
    cpu_math_mul2_const_8bit( e, sa->realName, 1, 1 );

    _te->trackedVariables[0] = ua;
    _te->trackedVariables[1] = sa;


}

int test_cpu_math_mul2_const_8bit_tester( TestEnvironment * _te ) {

    Variable * ua = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * sa = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return  ua->value == 0x42 &&
            sa->value == -16;

}

//===========================================================================

void test_cpu_bit_check_extended_payloadB( TestEnvironment * _te ) {

    Environment * e = &_te->environment;
    Variable *position[16];
    Variable *result[16];

    int i=0;
    for( i=0; i<16; ++i ) {
        char buffer[MAX_TEMPORARY_STORAGE];
        sprintf( buffer, "position%d", i );
        position[i] = variable_define( e, buffer, VT_BYTE, i );
    }

    Variable * value = variable_define( e, "value", VT_WORD, 0x5555 );

    for( i=0; i<16; ++i ) {
        char buffer[MAX_TEMPORARY_STORAGE];
        sprintf( buffer, "result%d", i );
        result[i] = variable_define( e, buffer, VT_BYTE, 0x55 );
        cpu_bit_check_extended( e, value->realName, position[i]->realName, result[i]->realName, VT_BITWIDTH( value->type ) );
    }

    for( i=0; i<16; ++i ) {
        _te->trackedVariables[i] = result[i];
    }

}

int test_cpu_bit_check_extended_testerB( TestEnvironment * _te ) {

    Variable *result[16];

    int i = 0;
    for( i=0; i<16; ++i ) {
        result[i] = variable_retrieve( &_te->environment, _te->trackedVariables[i]->name );
    }

    for( i=0; i<16; ++i ) {
        // printf( "result[%d] = %2.2x [expected %2.2x]\n", i, result[i]->value, ( i % 2 ) == 0 ? 0x00 : 0xff );
    }

    for( i=0; i<16; ++i ) {
        if ( ( i % 2 ) == 0 ) {
            if ( result[i]->value == 0x00 ) {
                return 0;
            }
        } else {
            if ( result[i]->value == 0xff ) {
                return 0;
            }
        }
    }

    return 1;

}

//===========================================================================

void test_cpu_number_to_string_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    char buffer[128]; sprintf(buffer, "                                  ");

    Variable * value = variable_define( e, "e", VT_BYTE, 42 );
    Variable * address = variable_temporary( e, VT_ADDRESS, "(temporary for PRINT)");
    Variable * size = variable_temporary( e, VT_BYTE, "(temporary for PRINT)");
    Variable * tmp = variable_temporary( e, VT_BUFFER, "(temporary for PRINT)");
    Variable * atmp = variable_define( e, "atmp", VT_ADDRESS, 0x4100);

    variable_store_buffer( e, tmp->name, buffer, 32, 0x4100 );

    cpu_number_to_string( e, value->realName, atmp->realName, size->realName, VT_BITWIDTH( value->type ), VT_SIGNED( value->type ) );

    _te->debug.inspections[0].name="tmp";
    _te->debug.inspections[0].address=0x4100;
    _te->debug.inspections[0].size=32;
    ++_te->debug.inspections_count;
    
    _te->trackedVariables[0] = size;

}

int test_cpu_number_to_string_tester( TestEnvironment * _te ) {

    Variable * size = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    _te->debug.inspections[0].memory[size->value] = 0;

// printf("memory = %s\n", _te->debug.inspections[0].memory );

    return strcmp( _te->debug.inspections[0].memory, "42" ) == 0;

}

//===========================================================================

void test_cpu_number_to_string_payloadB( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * value = variable_define( e, "e", VT_BYTE, 42 );
    Variable * address = variable_temporary( e, VT_ADDRESS, "(temporary for PRINT)");
    Variable * size = variable_temporary( e, VT_BYTE, "(temporary for PRINT)");
    Variable * tmp = variable_temporary( e, VT_DSTRING, "(temporary for PRINT)");

    variable_store_string( e, tmp->name, "          " );
    cpu_dswrite( e, tmp->realName );
    cpu_dsdescriptor( e, tmp->realName, address->realName, size->realName );
    cpu_number_to_string( e, value->realName, address->realName, size->realName, VT_BITWIDTH( value->type ), VT_SIGNED( value->type ) );
    cpu_dsresize( e, tmp->realName, size->realName );

    variable_store_string( e, tmp->name, "          " );
    cpu_dswrite( e, tmp->realName );
    cpu_dsdescriptor( e, tmp->realName, address->realName, size->realName );
    cpu_number_to_string( e, value->realName, address->realName, size->realName, VT_BITWIDTH( value->type ), VT_SIGNED( value->type ) );
    cpu_dsresize( e, tmp->realName, size->realName );

    variable_store_string( e, tmp->name, "          " );
    cpu_dswrite( e, tmp->realName );
    cpu_dsdescriptor( e, tmp->realName, address->realName, size->realName );
    cpu_number_to_string( e, value->realName, address->realName, size->realName, VT_BITWIDTH( value->type ), VT_SIGNED( value->type ) );
    cpu_dsresize( e, tmp->realName, size->realName );

    variable_store_string( e, tmp->name, "          " );
    cpu_dswrite( e, tmp->realName );
    cpu_dsdescriptor( e, tmp->realName, address->realName, size->realName );
    cpu_number_to_string( e, value->realName, address->realName, size->realName, VT_BITWIDTH( value->type ), VT_SIGNED( value->type ) );
    cpu_dsresize( e, tmp->realName, size->realName );

    variable_store_string( e, tmp->name, "          " );
    cpu_dswrite( e, tmp->realName );
    cpu_dsdescriptor( e, tmp->realName, address->realName, size->realName );
    cpu_number_to_string( e, value->realName, address->realName, size->realName, VT_BITWIDTH( value->type ), VT_SIGNED( value->type ) );
    cpu_dsresize( e, tmp->realName, size->realName );

    _te->trackedVariables[0] = tmp;
    _te->trackedVariables[1] = size;

}

int test_cpu_number_to_string_testerB( TestEnvironment * _te ) {

    Variable * tmp = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * size = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    // printf( "size = %d\n", size->value );
    // printf( "memory = %s\n", tmp->valueString );

    return size->value == 2 && strcmp( tmp->valueString, "42" ) == 0;

}

//===========================================================================

void test_cpu_number_to_string_payloadC( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    int i;

    Variable * value[10], * result[10];
    
    for(i=0; i<10;++i) {
        char valueName[MAX_TEMPORARY_STORAGE]; sprintf(valueName, "value%i", i );
        value[i] = variable_define( e, valueName, VT_BYTE, i+6 );
    } 

    for(i=0; i<10;++i) {
        char resultName[MAX_TEMPORARY_STORAGE]; sprintf(resultName, "result%i", i );
        result[i] = variable_define( e, resultName, VT_DSTRING, 0 );
    } 

    Variable * address = variable_temporary( e, VT_ADDRESS, "(temporary for PRINT)");
    Variable * size = variable_temporary( e, VT_BYTE, "(temporary for PRINT)");

    for(i=0; i<10;++i) {
        variable_store_string( e, result[i]->name, "          " );
        cpu_dswrite( e, result[i]->realName );
        cpu_dsdescriptor( e, result[i]->realName, address->realName, size->realName );
        cpu_number_to_string( e, value[i]->realName, address->realName, size->realName, VT_BITWIDTH( value[i]->type ), VT_SIGNED( value[i]->type ) );
        cpu_dsresize( e, result[i]->realName, size->realName );
    }

    for(i=0; i<10;++i) {
        _te->trackedVariables[i] = result[i];
    }

}

int test_cpu_number_to_string_testerC( TestEnvironment * _te ) {

    int i;
    Variable * result[10];
    char expected[MAX_TEMPORARY_STORAGE];

    for(i=0; i<10;++i) {
        result[i] = variable_retrieve( &_te->environment, _te->trackedVariables[i]->name );
        sprintf(expected, "%d", i+6 );
        // printf( "result[%d] = %s\n", i, result[i]->valueString );
        if ( strcmp( result[i]->valueString, expected ) != 0 ) {
            return 0;
        }
    }

    return 1;

}

//===========================================================================

void test_cpu_number_to_string_payloadD( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * a = variable_define( e, "a", VT_WORD, 1210 );
    Variable * b = variable_define( e, "b", VT_WORD, 60 );
    Variable * c = variable_define( e, "c", VT_WORD, 0 );
    Variable * d = variable_define( e, "d", VT_WORD, 0 );
    Variable * string = variable_define( e, "string", VT_DSTRING, 0 );
    Variable * size = variable_define( e, "size", VT_BYTE, 0 );
    Variable * address = variable_define( e, "address", VT_ADDRESS, 0 );
    Variable * size2 = variable_define( e, "size2", VT_BYTE, 0 );

    char buffer[16]; memset( buffer, 32, 16 );
    variable_store_string( e, string->name, buffer );

    cpu_dswrite( e, string->realName );
    cpu_dsdescriptor( e, string->realName, address->realName, size->realName );

    cpu_math_div_16bit_to_16bit( e, a->realName, b->realName, c->realName, d->realName, VT_SIGNED( c->type ) );
    cpu_number_to_string( e, c->realName, address->realName, size2->realName, VT_BITWIDTH( c->type ), VT_SIGNED( c->type ) );
    cpu_dsresize( e, string->realName, size2->realName );

    _te->trackedVariables[0] = c;
    _te->trackedVariables[1] = d;
    _te->trackedVariables[2] = string;
    _te->trackedVariables[3] = size2;

}

int test_cpu_number_to_string_testerD( TestEnvironment * _te ) {

    Variable * c = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * d = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * string = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * size = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

// printf("c = %4.4x (%d) [expected 20]\n", c->value, c->value );
// printf("d = %4.4x (%d) [expected 1]\n", d->value, d->value );
// printf("string = %s [expected '20']\n", string->valueString );
// printf("size = %2.2x (%d) [expected 2]\n", size->value, size->value );

    return c->value == 20 && d->value == 10 && strcmp( string->valueString, "20" ) == 0 && size->value == 2; 

}

//===========================================================================

void test_cpu_number_to_string_payloadE( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * a = variable_define( e, "a", VT_SBYTE, 0xff );

    Variable * string = variable_define( e, "string", VT_DSTRING, 0 );
    Variable * size = variable_define( e, "size", VT_BYTE, 0 );
    Variable * address = variable_define( e, "address", VT_ADDRESS, 0 );
    Variable * size2 = variable_define( e, "size2", VT_BYTE, 0 );

    char buffer[16]; memset( buffer, 32, 16 );
    variable_store_string( e, string->name, buffer );

    cpu_dswrite( e, string->realName );
    cpu_dsdescriptor( e, string->realName, address->realName, size->realName );

    cpu_number_to_string( e, a->realName, address->realName, size2->realName, VT_BITWIDTH( a->type ), VT_SIGNED( a->type ) );
    cpu_dsresize( e, string->realName, size2->realName );

    _te->trackedVariables[0] = string;

}

int test_cpu_number_to_string_testerE( TestEnvironment * _te ) {

    Variable * string = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

// printf("string = %s [expected '-1']\n", string->valueString );

    return strcmp( string->valueString, "-1" ) == 0; 

}

//===========================================================================

void test_cpu_peek_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * address1 = variable_define( e, "address1", VT_ADDRESS, 0x1000 );
    Variable * address2 = variable_define( e, "address2", VT_ADDRESS, 0x1010 );
    Variable * a = variable_define( e, "a", VT_BYTE, 42 );
    Variable * b = variable_define( e, "b", VT_BYTE, 84 );
    Variable * c = variable_define( e, "c", VT_BYTE, 21 );
    Variable * d = variable_define( e, "d", VT_BYTE, 0 );
    Variable * f = variable_define( e, "f", VT_BYTE, 0 );

    cpu_poke( e, address1->realName, a->realName );
    cpu_peek( e, address1->realName, b->realName );
    cpu_poke( e, address1->realName, c->realName );
    cpu_peek( e, address1->realName, d->realName );
    cpu_poke( e, address2->realName, c->realName );
    cpu_peek( e, address2->realName, f->realName );

    _te->trackedVariables[0] = b;
    _te->trackedVariables[1] = d;
    _te->trackedVariables[2] = f;
    _te->trackedVariables[3] = a;
    _te->trackedVariables[4] = c;

}

int test_cpu_peek_tester( TestEnvironment * _te ) {

    Variable * b = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * d = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * f = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * a = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * c = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );

    // printf( "a = %2.2x\n", a->value );
    // printf( "b = %2.2x\n", b->value );
    // printf( "c = %2.2x\n", c->value );
    // printf( "d = %2.2x\n", d->value );
    // printf( "f = %2.2x\n", f->value );

    return b->value == a->value && d->value == c->value && f->value == c->value;

}

//===========================================================================

void test_cpu_poke_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * address1 = variable_define( e, "address1", VT_ADDRESS, 0x1000 );
    Variable * a = variable_define( e, "a", VT_BYTE, 42 );
    Variable * b = variable_define( e, "b", VT_BYTE, 84 );

    cpu_poke( e, address1->realName, a->realName );
    cpu_peek( e, address1->realName, b->realName );

    _te->trackedVariables[0] = a;
    _te->trackedVariables[1] = b;

}

int test_cpu_poke_tester( TestEnvironment * _te ) {

    Variable * a = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * b = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return b->value == a->value;

}

//===========================================================================

void test_cpu_fill_blocks_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * address = variable_define( e, "address", VT_ADDRESS, 0x4000 );
    Variable * blocks1 = variable_define( e, "blocks1", VT_WORD, 2 );
    Variable * blocks2 = variable_define( e, "blocks2", VT_WORD, 4 );
    Variable * pattern1 = variable_define( e, "pattern1", VT_BYTE, 0x42 );
    Variable * pattern2 = variable_define( e, "pattern2", VT_BYTE, 0x00 );

    cpu_fill_blocks( e, address->realName, blocks2->realName, pattern2->realName );
    cpu_fill_blocks( e, address->realName, blocks1->realName, pattern1->realName );

    _te->debug.inspections[0].name="target";
    _te->debug.inspections[0].address=0x4000;
    _te->debug.inspections[0].size=blocks2->value*256;
    ++_te->debug.inspections_count;

    _te->trackedVariables[0] = address;
    _te->trackedVariables[1] = blocks1;
    _te->trackedVariables[2] = pattern1;
    _te->trackedVariables[3] = blocks2;
    _te->trackedVariables[4] = pattern2;
    
}

int test_cpu_fill_blocks_tester( TestEnvironment * _te ) {

    Variable * address = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * blocks1 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * pattern1 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * blocks2 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * pattern2 = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );

    int i=0;

    for( i=0; i<blocks1->value*256; ++i ) {
        if ( _te->debug.inspections[0].memory[i] != pattern1->value ) {
            printf( "\nError (1) at position %4.4x/%4.4x: %2.2x\n", i, (blocks1->value*256), _te->debug.inspections[0].memory[i] );
            return 0;
        }
    }

    for( i=blocks1->value*256; i<blocks2->value*256; ++i ) {
        if ( _te->debug.inspections[0].memory[i] != pattern2->value ) {
            printf( "\nError (2) at position %4.4x: %2.2x\n", i, _te->debug.inspections[0].memory[i] );
            return 0;
        }
    }

    return address->value == 0x4000 && blocks1->value == 2 && pattern1->value == 0x42 && blocks2->value == 4 && pattern2->value == 0x00;

}

//===========================================================================

void test_cpu_fill_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * address = variable_define( e, "address", VT_ADDRESS, 0x1000 );
    Variable * bytes1 = variable_define( e, "bytes1", VT_BYTE, 2 );
    Variable * bytes2 = variable_define( e, "bytes2", VT_BYTE, 4 );
    Variable * pattern1 = variable_define( e, "pattern1", VT_BYTE, 0x42 );
    Variable * pattern2 = variable_define( e, "pattern2", VT_BYTE, 0x00 );

    cpu_fill( e, address->realName, bytes2->realName, pattern2->realName );
    cpu_fill( e, address->realName, bytes1->realName, pattern1->realName );

    _te->debug.inspections[0].name="target";
    _te->debug.inspections[0].address=0x1000;
    _te->debug.inspections[0].size=bytes2->value;
    ++_te->debug.inspections_count;

    _te->trackedVariables[0] = address;
    _te->trackedVariables[1] = bytes1;
    _te->trackedVariables[2] = pattern1;
    _te->trackedVariables[3] = bytes2;
    _te->trackedVariables[4] = pattern2;
    
}

int test_cpu_fill_tester( TestEnvironment * _te ) {

    Variable * address = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * bytes1 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * pattern1 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * bytes2 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * pattern2 = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );

    int i=0;

    for( i=0; i<bytes1->value; ++i ) {
        if ( _te->debug.inspections[0].memory[i] != pattern1->value ) {
            // printf( "\nError (1) at position %4.4x/%4.4x: %2.2x\n", i, bytes1->value, _te->debug.inspections[0].memory[i] );
            return 0;
        }
    }

    for( i=bytes1->value; i<bytes2->value; ++i ) {
        if ( _te->debug.inspections[0].memory[i] != pattern2->value ) {
            // printf( "\nError (2) at position %4.4x: %2.2x\n", i, _te->debug.inspections[0].memory[i] );
            return 0;
        }
    }

    return address->value == 0x1000 && bytes1->value == 2 && pattern1->value == 0x42 && bytes2->value == 4 && pattern2->value == 0x00;

}

//===========================================================================

void test_cpu_compare_8bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * byte1 = variable_define( e, "byte1", VT_BYTE, 1 );
    Variable * byte2 = variable_define( e, "byte2", VT_BYTE, 2 );
    Variable * result12p = variable_define( e, "result12p", VT_BYTE, 0x42 );
    Variable * result12n = variable_define( e, "result12n", VT_BYTE, 0x42 );
    Variable * result11p = variable_define( e, "result11p", VT_BYTE, 0x42 );
    Variable * result11n = variable_define( e, "result11n", VT_BYTE, 0x42 );

    cpu_compare_8bit( e, byte1->realName, byte2->realName, result12p->realName, 1 );
    cpu_compare_8bit( e, byte1->realName, byte2->realName, result12n->realName, 0 );
    cpu_compare_8bit( e, byte1->realName, byte1->realName, result11p->realName, 1 );
    cpu_compare_8bit( e, byte1->realName, byte1->realName, result11n->realName, 0 );

    _te->trackedVariables[0] = byte1;
    _te->trackedVariables[1] = byte2;
    _te->trackedVariables[2] = result12p;
    _te->trackedVariables[3] = result12n;
    _te->trackedVariables[4] = result11p;
    _te->trackedVariables[5] = result11n;
    
}

int test_cpu_compare_8bit_tester( TestEnvironment * _te ) {

    Variable * byte1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * byte2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * result12p = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * result12n = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * result11p = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );
    Variable * result11n = variable_retrieve( &_te->environment, _te->trackedVariables[5]->name );

    // printf( "byte1 = %2.2x\n", byte1->value );
    // printf( "byte2 = %2.2x\n", byte2->value );
    // printf( "result12p = %2.2x\n", result12p->value );
    // printf( "result12n = %2.2x\n", result12n->value );
    // printf( "result11p = %2.2x\n", result11p->value );
    // printf( "result11n = %2.2x\n", result11n->value );

    return byte1->value == 1 && 
            byte2->value == 2 && 
            result12p->value == 0x00 && 
            result12n->value == 0xff && 
            result11p->value == 0xff &&
            result11n->value == 0x00;

}

//===========================================================================

void test_cpu_math_add_8bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * first = variable_define( e, "first", VT_BYTE, 1 );
    Variable * second = variable_define( e, "second", VT_BYTE, 2 );
    Variable * result = variable_define( e, "result", VT_BYTE, 0x42 );

    cpu_math_add_8bit( e, first->realName, second->realName, result->realName );

    _te->trackedVariables[0] = first;
    _te->trackedVariables[1] = second;
    _te->trackedVariables[2] = result;
    
}

int test_cpu_math_add_8bit_tester( TestEnvironment * _te ) {

    Variable * first = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * second = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * result = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );

    // printf( "first = %2.2x\n", first->value );
    // printf( "second = %2.2x\n", second->value );
    // printf( "result = %2.2x\n", result->value );

    return first->value == 1 && 
            second->value == 2 && 
            result->value == 3;

}

//===========================================================================

void test_cpu_math_sub_8bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * first = variable_define( e, "first", VT_BYTE, 2 );
    Variable * second = variable_define( e, "second", VT_BYTE, 1 );
    Variable * result = variable_define( e, "result", VT_BYTE, 0x55 );

    cpu_math_sub_8bit( e, first->realName, second->realName, result->realName );

    _te->trackedVariables[0] = first;
    _te->trackedVariables[1] = second;
    _te->trackedVariables[2] = result;
    
}

int test_cpu_math_sub_8bit_tester( TestEnvironment * _te ) {

    Variable * first = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * second = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * result = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );

    // printf( "first = %2.2x\n", first->value );
    // printf( "second = %2.2x\n", second->value );
    // printf( "result = %2.2x\n", result->value );

    return first->value == 2 && 
            second->value == 1 && 
            result->value == 1;

}

//===========================================================================

void test_cpu_math_complement_const_8bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * first = variable_define( e, "first", VT_BYTE, 0x42 );

    cpu_math_complement_const_8bit( e, first->realName, 0x42 );

    _te->trackedVariables[0] = first;
    
}

int test_cpu_math_complement_const_8bit_tester( TestEnvironment * _te ) {

    Variable * first = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return first->value == 0;

}

//===========================================================================

void test_cpu_math_and_const_8bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * first = variable_define( e, "first", VT_BYTE, 0x42 );

    cpu_math_and_const_8bit( e, first->realName, 0x00 );

    _te->trackedVariables[0] = first;
    
}

int test_cpu_math_and_const_8bit_tester( TestEnvironment * _te ) {

    Variable * first = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return first->value == 0;

}

//===========================================================================

void test_cpu_move_16bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * first = variable_define( e, "first", VT_WORD, 0x42 );
    Variable * second = variable_define( e, "second", VT_WORD, 0x84 );

    cpu_move_16bit( e, first->realName, second->realName );

    _te->trackedVariables[0] = first;
    _te->trackedVariables[1] = second;
    
}

int test_cpu_move_16bit_tester( TestEnvironment * _te ) {

    Variable * first = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * second = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return first->value == second->value && second->value == 0x42;

}

//===========================================================================

void test_cpu_addressof_16bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * first = variable_define( e, "first", VT_WORD, 0x42 );
    Variable * second = variable_define( e, "second", VT_WORD, 0x84 );

    cpu_addressof_16bit( e, first->realName, second->realName );

    _te->trackedVariables[0] = first;
    _te->trackedVariables[1] = second;
    
}

int test_cpu_addressof_16bit_tester( TestEnvironment * _te ) {

    Variable * first = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * second = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return first->value != second->value && second->value != 0x84;

}

//===========================================================================

void test_cpu_compare_16bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * word1 = variable_define( e, "word1", VT_WORD, 0x2142 );
    Variable * word2 = variable_define( e, "word2", VT_WORD, 0x1042 );
    Variable * result12p = variable_define( e, "result12p", VT_BYTE, 0x42 );
    Variable * result12n = variable_define( e, "result12n", VT_BYTE, 0x42 );
    Variable * result11p = variable_define( e, "result11p", VT_BYTE, 0x42 );
    Variable * result11n = variable_define( e, "result11n", VT_BYTE, 0x42 );

    cpu_compare_16bit( e, word1->realName, word2->realName, result12p->realName, 1 );
    cpu_compare_16bit( e, word1->realName, word2->realName, result12n->realName, 0 );
    cpu_compare_16bit( e, word1->realName, word1->realName, result11p->realName, 1 );
    cpu_compare_16bit( e, word1->realName, word1->realName, result11n->realName, 0 );

    _te->trackedVariables[0] = word1;
    _te->trackedVariables[1] = word2;
    _te->trackedVariables[2] = result12p;
    _te->trackedVariables[3] = result12n;
    _te->trackedVariables[4] = result11p;
    _te->trackedVariables[5] = result11n;
    
}

int test_cpu_compare_16bit_tester( TestEnvironment * _te ) {

    Variable * word1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * word2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * result12p = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * result12n = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * result11p = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );
    Variable * result11n = variable_retrieve( &_te->environment, _te->trackedVariables[5]->name );

    // printf( "word1 = %2.2x [expected 0x2142]\n", word1->value );
    // printf( "word2 = %2.2x [expected 0x1042]\n", word2->value );
    // printf( "result12p = %2.2x [expected 0x00]\n", result12p->value );
    // printf( "result12n = %2.2x [expected 0xff]\n", result12n->value );
    // printf( "result11p = %2.2x [expected 0xff]\n", result11p->value );
    // printf( "result11n = %2.2x [expected 0x00]\n", result11n->value );

    return word1->value == 0x2142 && 
            word2->value == 0x1042 && 
            result12p->value == 0x00 && 
            result12n->value == 0xff && 
            result11p->value == 0xff &&
            result11n->value == 0x00;

}

//===========================================================================

void test_cpu_math_add_16bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * word1 = variable_define( e, "word1", VT_WORD, 0x2142 );
    Variable * word2 = variable_define( e, "word2", VT_WORD, 0x1042 );
    Variable * result = variable_define( e, "result12p", VT_WORD, 0x42 );

    cpu_math_add_16bit( e, word1->realName, word2->realName, result->realName );

    _te->trackedVariables[0] = word1;
    _te->trackedVariables[1] = word2;
    _te->trackedVariables[2] = result;
    
}

int test_cpu_math_add_16bit_tester( TestEnvironment * _te ) {

    Variable * word1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * word2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * result = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );

    return word1->value == 0x2142 && 
            word2->value == 0x1042 && 
            result->value == word1->value + word2->value;

}

//===========================================================================

void test_cpu_math_add_16bit_with_16bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * word1 = variable_define( e, "word1", VT_WORD, 0x2142 );
    Variable * word2 = variable_define( e, "word2", VT_WORD, 0x1042 );
    Variable * aword2 = variable_define( e, "aword2", VT_ADDRESS, 0x0000 );
    Variable * result = variable_define( e, "result12p", VT_WORD, 0x42 );

    cpu_addressof_16bit( e, word2->realName, aword2->realName );
    cpu_math_add_16bit_with_16bit( e, word1->realName, word2->realName, result->realName );

    _te->trackedVariables[0] = word1;
    _te->trackedVariables[1] = word2;
    _te->trackedVariables[2] = result;
    _te->trackedVariables[3] = aword2;
    
}

int test_cpu_math_add_16bit_with_16bit_tester( TestEnvironment * _te ) {

    Variable * word1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * word2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * result = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * aword2 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

// printf( "word1 = %4.4x (%d) [expected 0x2142]\n", word1->value, word1->value );
// printf( "word2 = %4.4x (%d) [expected 0x1042]\n", word2->value, word2->value );
// printf( "aword2 = %4.4x (%d) [expected ??????]\n", aword2->value, aword2->value );
// printf( "result = %4.4x (%d) [expected %4.4x]\n", result->value, result->value, word1->value + aword2->value );

    return word1->value == 0x2142 && 
            word2->value == 0x1042 && 
            result->value == word1->value + aword2->value;

}

//===========================================================================

void test_cpu_math_add_16bit_with_8bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * word = variable_define( e, "word", VT_WORD, 0x2142 );
    Variable * byte = variable_define( e, "byte", VT_BYTE, 0x10 );
    Variable * result = variable_define( e, "result", VT_WORD, 0x2152 );

    cpu_math_add_16bit_with_8bit( e, word->realName, byte->realName, result->realName );

    _te->trackedVariables[0] = word;
    _te->trackedVariables[1] = byte;
    _te->trackedVariables[2] = result;
    
}

int test_cpu_math_add_16bit_with_8bit_tester( TestEnvironment * _te ) {

    Variable * word = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * byte = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * result = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );

    return word->value == 0x2142 && 
            byte->value == 0x10 && 
            result->value == word->value + byte->value;

}

//===========================================================================

void test_cpu_math_sub_16bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * word1 = variable_define( e, "word1", VT_WORD, 0x2142 );
    Variable * word2 = variable_define( e, "word2", VT_WORD, 0x1010 );
    Variable * result = variable_define( e, "result", VT_WORD, 0x0 );

    cpu_math_sub_16bit( e, word1->realName, word2->realName, result->realName );

    _te->trackedVariables[0] = word1;
    _te->trackedVariables[1] = word2;
    _te->trackedVariables[2] = result;
    
}

int test_cpu_math_sub_16bit_tester( TestEnvironment * _te ) {

    Variable * word1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * word2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * result = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );

    // printf( "word1: %4.4x (%d) [expected: 0x2142]\n", word1->value, word1->value );
    // printf( "word2: %4.4x (%d) [expected: 0x1010]\n", word2->value, word2->value );
    // printf( "result: %4.4x (%d) [expected: 0x1132]\n", result->value, result->value );

    return word1->value == 0x2142 && 
            word2->value == 0x1010 && 
            result->value == word1->value - word2->value;

}

//===========================================================================

void test_cpu_math_sub_16bit_with_8bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * word1 = variable_define( e, "word1", VT_WORD, 0x2142 );
    Variable * byte2 = variable_define( e, "byte2", VT_BYTE, 0x10 );
    Variable * result = variable_define( e, "result", VT_WORD, 0x0 );

    cpu_math_sub_16bit_with_8bit( e, word1->realName, byte2->realName, result->realName );

    _te->trackedVariables[0] = word1;
    _te->trackedVariables[1] = byte2;
    _te->trackedVariables[2] = result;
    
}

int test_cpu_math_sub_16bit_with_8bit_tester( TestEnvironment * _te ) {

    Variable * word1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * byte2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * result = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );

    // printf( "word1: %4.4x (%d) [expected: 0x2142]\n", word1->value, word1->value );
    // printf( "byte2: %2.2x (%d) [expected: 0x10]\n", byte2->value, byte2->value );
    // printf( "result: %4.4x (%d) [expected: 0x2132]\n", result->value, result->value );

    return word1->value == 0x2142 && 
            byte2->value == 0x10 && 
            result->value == word1->value - byte2->value;

}

//===========================================================================

void test_cpu_math_complement_const_16bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * word1 = variable_define( e, "word1", VT_WORD, 0x1000 );

    cpu_math_complement_const_16bit( e, word1->realName, 0x4000 );

    _te->trackedVariables[0] = word1;
    
}

int test_cpu_math_complement_const_16bit_tester( TestEnvironment * _te ) {

    Variable * word1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    // printf( "word1: %4.4x (%d) [expected: 0x2142]\n", word1->value, word1->value );

    return word1->value == 0x3000;

}

//===========================================================================

void test_cpu_math_and_const_16bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * word1 = variable_define( e, "word1", VT_WORD, 0x55ff );

    cpu_math_and_const_16bit( e, word1->realName, 0x5555 );

    _te->trackedVariables[0] = word1;
    
}

int test_cpu_math_and_const_16bit_tester( TestEnvironment * _te ) {

    Variable * word1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    // printf( "word1: %4.4x (%d) [expected: 0x5555]\n", word1->value, word1->value );

    return word1->value == 0x5555;

}

//===========================================================================

void test_cpu_move_32bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * word1 = variable_define( e, "word1", VT_DWORD, 0x55ff55ff );
    Variable * word2 = variable_define( e, "word2", VT_DWORD, 0X00000000 );

    cpu_move_32bit( e, word1->realName, word2->realName );

    _te->trackedVariables[0] = word1;
    _te->trackedVariables[1] = word2;
    
}

int test_cpu_move_32bit_tester( TestEnvironment * _te ) {

    Variable * word1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * word2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    // printf( "word1: %4.4x (%d) [expected: 0x55ff55ff]\n", word1->value, word1->value );
    // printf( "word2: %4.4x (%d) [expected: 0x55ff55ff]\n", word2->value, word2->value );

    return word1->value == word2->value;

}

//===========================================================================

void test_cpu_store_32bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * word1 = variable_define( e, "word1", VT_DWORD, 0x55ff55ff );

    cpu_store_32bit( e, word1->realName, 0xff00ff00 );

    _te->trackedVariables[0] = word1;
    
}

int test_cpu_store_32bit_tester( TestEnvironment * _te ) {

    Variable * word1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    // printf( "word1: %4.4x (%d) [expected: 0xff00ff00]\n", word1->value, word1->value );

    return word1->value == 0xff00ff00;

}

//===========================================================================

void test_cpu_compare_32bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * dword1 = variable_define( e, "dword1", VT_DWORD, 0x55662142 );
    Variable * dword2 = variable_define( e, "dword2", VT_DWORD, 0x22331042 );
    Variable * result12p = variable_define( e, "result12p", VT_BYTE, 0x42 );
    Variable * result12n = variable_define( e, "result12n", VT_BYTE, 0x42 );
    Variable * result11p = variable_define( e, "result11p", VT_BYTE, 0x42 );
    Variable * result11n = variable_define( e, "result11n", VT_BYTE, 0x42 );

    cpu_compare_32bit( e, dword1->realName, dword2->realName, result12p->realName, 1 );
    cpu_compare_32bit( e, dword1->realName, dword2->realName, result12n->realName, 0 );
    cpu_compare_32bit( e, dword1->realName, dword1->realName, result11p->realName, 1 );
    cpu_compare_32bit( e, dword1->realName, dword1->realName, result11n->realName, 0 );

    _te->trackedVariables[0] = dword1;
    _te->trackedVariables[1] = dword2;
    _te->trackedVariables[2] = result12p;
    _te->trackedVariables[3] = result12n;
    _te->trackedVariables[4] = result11p;
    _te->trackedVariables[5] = result11n;
    
}

int test_cpu_compare_32bit_tester( TestEnvironment * _te ) {

    Variable * dword1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * dword2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * result12p = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * result12n = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * result11p = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );
    Variable * result11n = variable_retrieve( &_te->environment, _te->trackedVariables[5]->name );

    // printf( "dword1 = %2.2x [expected 0x55662142]\n", dword1->value );
    // printf( "dword2 = %2.2x [expected 0x22331042]\n", dword2->value );
    // printf( "result12p = %2.2x [expected 0x00]\n", result12p->value );
    // printf( "result12n = %2.2x [expected 0xff]\n", result12n->value );
    // printf( "result11p = %2.2x [expected 0xff]\n", result11p->value );
    // printf( "result11n = %2.2x [expected 0x00]\n", result11n->value );

    return dword1->value == 0x55662142 && 
            dword2->value == 0x22331042 && 
            result12p->value == 0x00 && 
            result12n->value == 0xff && 
            result11p->value == 0xff &&
            result11n->value == 0x00;

}

//===========================================================================

void test_cpu_math_add_32bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * dword1 = variable_define( e, "dword1", VT_DWORD, 0x1122A142 );
    Variable * dword2 = variable_define( e, "dword2", VT_DWORD, 0x1122B042 );
    Variable * result = variable_define( e, "result12p", VT_DWORD, 0x42 );

    cpu_math_add_32bit( e, dword1->realName, dword2->realName, result->realName );

    _te->trackedVariables[0] = dword1;
    _te->trackedVariables[1] = dword2;
    _te->trackedVariables[2] = result;
    
}

int test_cpu_math_add_32bit_tester( TestEnvironment * _te ) {

    Variable * dword1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * dword2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * result = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );

    // printf( "dword1 = %8.8x (%d) [expected 0x1122A142]\n", dword1->value, dword1->value );
    // printf( "dword2 = %8.8x (%d) [expected 0x1122B042]\n", dword2->value, dword2->value );
    // printf( "result = %8.8x (%d) [expected 0x22455184]\n", result->value, result->value );

    return dword1->value == 0x1122A142 && 
            dword2->value == 0x1122B042 && 
            result->value == dword1->value + dword2->value;

}

//===========================================================================

void test_cpu_math_sub_32bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * dword1 = variable_define( e, "dword1", VT_DWORD, 0x1122B142 );
    Variable * dword2 = variable_define( e, "dword2", VT_DWORD, 0x1122A042 );
    Variable * result = variable_define( e, "result12p", VT_DWORD, 0x42 );

    cpu_math_sub_32bit( e, dword1->realName, dword2->realName, result->realName );

    _te->trackedVariables[0] = dword1;
    _te->trackedVariables[1] = dword2;
    _te->trackedVariables[2] = result;
    
}

int test_cpu_math_sub_32bit_tester( TestEnvironment * _te ) {

    Variable * dword1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * dword2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * result = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );

    // printf( "dword1 = %8.8x (%d) [expected 0x1122B142]\n", dword1->value, dword1->value );
    // printf( "dword2 = %8.8x (%d) [expected 0x1122A042]\n", dword2->value, dword2->value );
    // printf( "result = %8.8x (%d) [expected %8.8x]\n", result->value, result->value, ( dword1->value - dword2->value ) );

    return dword1->value == 0x1122B142 && 
            dword2->value == 0x1122A042 && 
            result->value == dword1->value - dword2->value;

}

//===========================================================================

void test_cpu_math_complement_const_32bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * dword1 = variable_define( e, "dword1", VT_DWORD, 0x02000000 );

    cpu_math_complement_const_32bit( e, dword1->realName, 0x03000000 );

    _te->trackedVariables[0] = dword1;
    
}

int test_cpu_math_complement_const_32bit_tester( TestEnvironment * _te ) {

    Variable * dword1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    // printf( "dword1 = %8.8x (%d) [expected 0x01000000]\n", dword1->value, dword1->value );

    return dword1->value == 0x01000000;

}

//===========================================================================

void test_cpu_math_and_const_32bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * dword1 = variable_define( e, "dword1", VT_DWORD, 0xff5555ff );

    cpu_math_and_const_32bit( e, dword1->realName, 0x55555555 );

    _te->trackedVariables[0] = dword1;
    
}

int test_cpu_math_and_const_32bit_tester( TestEnvironment * _te ) {

    Variable * dword1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    // printf( "dword1: %8.8x (%d) [expected: 0x55555555]\n", dword1->value, dword1->value );

    return dword1->value == 0x55555555;

}

//===========================================================================

void test_cpu_combine_nibbles_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * low = variable_define( e, "low", VT_BYTE, 0x0a );
    Variable * hi = variable_define( e, "hi", VT_BYTE, 0x01 );
    Variable * result = variable_define( e, "result", VT_BYTE, 0x00 );

    cpu_combine_nibbles( e, low->realName, hi->realName, result->realName );

    _te->trackedVariables[0] = result;
    
}

int test_cpu_combine_nibbles_tester( TestEnvironment * _te ) {

    Variable * result = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    // printf( "result: %2.2x (%d) [expected: 0x1a]\n", result->value, result->value );

    return result->value == 0x1a;

}

//===========================================================================

void test_cpu_mem_move_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    int i=0;
    char buffer1[160]; 
    for(i=0;i<160; ++i ) {
        buffer1[i] = i;
    }
    char buffer2[160]; memset( buffer2, 0x24, 160 );

    Variable * source = variable_define( e, "source", VT_BUFFER, 0x0 );
    Variable * destination = variable_define( e, "destination", VT_BUFFER, 0x0 );
    Variable * size = variable_define( e, "size", VT_BYTE, 160 );

    variable_store_buffer( e, source->name, buffer1, 160, 0x4000 );
    variable_store_buffer( e, destination->name, buffer2, 160, 0x4100 );

    Variable * asource = variable_define( e, "asource", VT_ADDRESS, 0x4000 );
    Variable * adestination = variable_define( e, "adestination", VT_ADDRESS, 0x4100 );

    cpu_mem_move( e, asource->realName, adestination->realName, size->realName );

    _te->debug.inspections[_te->debug.inspections_count].name="buffer1";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4000;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    _te->debug.inspections[_te->debug.inspections_count].name="buffer2";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4100;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;

    _te->trackedVariables[0] = size;
    
}

int test_cpu_mem_move_tester( TestEnvironment * _te ) {

    Variable * size = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    int i = 0;
    for( i=0; i<size->value; ++i ) {
        if ( _te->debug.inspections[0].memory[i] != _te->debug.inspections[1].memory[i] ) {
            // printf( "\nError (1) at position %4.4x/%4.4x: %2.2x\n", i, size->value, _te->debug.inspections[1].memory[i] );
            return 0;
        }
    }

    return size->value == 160;

}

//===========================================================================

void test_cpu_mem_move_size_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    int i=0;
    char buffer1[160]; 
    for(i=0;i<160; ++i ) {
        buffer1[i] = i;
    }
    char buffer2[160]; memset( buffer2, 0x24, 160 );

    Variable * source = variable_define( e, "source", VT_BUFFER, 0x0 );
    Variable * destination = variable_define( e, "destination", VT_BUFFER, 0x0 );

    variable_store_buffer( e, source->name, buffer1, 160, 0x4000 );
    variable_store_buffer( e, destination->name, buffer2, 160, 0x4100 );

    Variable * asource = variable_define( e, "asource", VT_ADDRESS, 0x4000 );
    Variable * adestination = variable_define( e, "adestination", VT_ADDRESS, 0x4100 );

    cpu_mem_move_size( e, asource->realName, adestination->realName, 160 );

    _te->debug.inspections[_te->debug.inspections_count].name="buffer1";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4000;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    _te->debug.inspections[_te->debug.inspections_count].name="buffer2";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4100;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    
}

int test_cpu_mem_move_size_tester( TestEnvironment * _te ) {

    int i = 0;
    for( i=0; i<160; ++i ) {
        if ( _te->debug.inspections[1].memory[i] != _te->debug.inspections[1].memory[i] ) {
            printf( "\nError (1) at position %4.4x/%4.4x: %2.2x != %2.2x\n", i, 160, _te->debug.inspections[0].memory[i], _te->debug.inspections[1].memory[i] );
            return 0;
        }
    }

    return 1;

}

//===========================================================================

void test_cpu_mem_move_direct_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    int i=0;
    char buffer1[160]; 
    for(i=0;i<160; ++i ) {
        buffer1[i] = i;
    }
    char buffer2[160]; memset( buffer2, 0x24, 160 );

    Variable * source = variable_define( e, "source", VT_BUFFER, 0x0 );
    Variable * destination = variable_define( e, "destination", VT_BUFFER, 0x0 );
    Variable * size = variable_define( e, "size", VT_BYTE, 160 );

    variable_store_buffer( e, source->name, buffer1, 160, 0x4000 );
    variable_store_buffer( e, destination->name, buffer2, 160, 0x4100 );

    cpu_mem_move_direct( e, source->realName, destination->realName, size->realName );

    _te->debug.inspections[_te->debug.inspections_count].name="buffer1";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4000;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    _te->debug.inspections[_te->debug.inspections_count].name="buffer2";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4100;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;

    _te->trackedVariables[0] = size;

}

int test_cpu_mem_move_direct_tester( TestEnvironment * _te ) {

    Variable * size = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    int i = 0;
    for( i=0; i<size->value; ++i ) {
        if ( _te->debug.inspections[1].memory[i] != _te->debug.inspections[1].memory[i] ) {
            // printf( "\nError (1) at position %4.4x/%4.4x: %2.2x\n", i, size->value, _te->debug.inspections[1].memory[i] );
            return 0;
        }
    }

    return size->value == 160;

}

//===========================================================================

void test_cpu_mem_move_direct_size_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    int i=0;
    char buffer1[160]; 
    for(i=0;i<160; ++i ) {
        buffer1[i] = i;
    }
    char buffer2[160]; memset( buffer2, 0x24, 160 );

    Variable * source = variable_define( e, "source", VT_BUFFER, 0x0 );
    Variable * destination = variable_define( e, "destination", VT_BUFFER, 0x0 );

    variable_store_buffer( e, source->name, buffer1, 160, 0x4000 );
    variable_store_buffer( e, destination->name, buffer2, 160, 0x4100 );

    cpu_mem_move_direct_size( e, source->realName, destination->realName, 160 );

    _te->debug.inspections[_te->debug.inspections_count].name="buffer1";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4000;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    _te->debug.inspections[_te->debug.inspections_count].name="buffer2";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4100;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;

}

int test_cpu_mem_move_direct_size_tester( TestEnvironment * _te ) {

    int i = 0;
    for( i=0; i<160; ++i ) {
        if ( _te->debug.inspections[1].memory[i] != _te->debug.inspections[1].memory[i] ) {
            // printf( "\nError (1) at position %4.4x/%4.4x: %2.2x\n", i, 160, _te->debug.inspections[1].memory[i] );
            return 0;
        }
    }

    return 1;

}

//===========================================================================

void test_cpu_mem_move_direct_indirect_size_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    int i=0;
    char buffer1[160]; 
    for(i=0;i<160; ++i ) {
        buffer1[i] = i;
    }
    char buffer2[160]; memset( buffer2, 0x24, 160 );

    Variable * source = variable_define( e, "source", VT_BUFFER, 0x0 );
    Variable * destination = variable_define( e, "destination", VT_BUFFER, 0x0 );
    Variable * adestination = variable_define( e, "adestination", VT_ADDRESS, 0x4100 );

    variable_store_buffer( e, source->name, buffer1, 160, 0x4000 );
    variable_store_buffer( e, destination->name, buffer2, 160, 0x4100 );

    cpu_mem_move_direct_indirect_size( e, source->realName, adestination->realName, 160 );

    _te->debug.inspections[_te->debug.inspections_count].name="buffer1";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4000;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    _te->debug.inspections[_te->debug.inspections_count].name="buffer2";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4100;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;

}

int test_cpu_mem_move_direct_indirect_size_tester( TestEnvironment * _te ) {

    int i = 0;
    for( i=0; i<160; ++i ) {
        if ( _te->debug.inspections[1].memory[i] != _te->debug.inspections[1].memory[i] ) {
            // printf( "\nError (1) at position %4.4x/%4.4x: %2.2x\n", i, 160, _te->debug.inspections[1].memory[i] );
            return 0;
        }
    }

    return 1;

}

//===========================================================================

void test_cpu_compare_memory_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    int i=0;
    char buffer1[160]; 
    char buffer2[160];
    char buffer3[160];
    for(i=0;i<160; ++i ) {
        buffer1[i] = i;
        buffer2[i] = i;
        if ( i < 100 ) {
            buffer3[i] = i;
        } else {
            buffer3[i] = 0x42;
        }
    }

    Variable * source = variable_define( e, "source", VT_BUFFER, 0x0 );
    Variable * same = variable_define( e, "same", VT_BUFFER, 0x0 );
    Variable * different = variable_define( e, "different", VT_BUFFER, 0x0 );
    Variable * asource = variable_define( e, "asource", VT_ADDRESS, 0x4000 );
    Variable * asame = variable_define( e, "asame", VT_ADDRESS, 0x4100 );
    Variable * adifferent = variable_define( e, "adifferent", VT_ADDRESS, 0x4200 );
    Variable * size = variable_define( e, "size", VT_BYTE, 160 );

    Variable * resultsame0 = variable_define( e, "resultsame0", VT_BYTE, 0x42 );
    Variable * resultsame1 = variable_define( e, "resultsame1", VT_BYTE, 0x42 );
    Variable * resultdifferent0 = variable_define( e, "resultdifferent0", VT_BYTE, 0x42 );
    Variable * resultdifferent1 = variable_define( e, "resultdifferent1", VT_BYTE, 0x42 );

    variable_store_buffer( e, source->name, buffer1, 160, 0x4000 );
    variable_store_buffer( e, same->name, buffer2, 160, 0x4100 );
    variable_store_buffer( e, different->name, buffer3, 160, 0x4200 );

    cpu_compare_memory( e, asource->realName, asame->realName, size->realName, resultsame1->realName, 1 );
    cpu_compare_memory( e, asource->realName, asame->realName, size->realName, resultsame0->realName, 0 );
    cpu_compare_memory( e, asource->realName, adifferent->realName, size->realName, resultdifferent1->realName, 1 );
    cpu_compare_memory( e, asource->realName, adifferent->realName, size->realName, resultdifferent0->realName, 0 );

    _te->debug.inspections[_te->debug.inspections_count].name="buffer1";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4000;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    _te->debug.inspections[_te->debug.inspections_count].name="buffer2";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4100;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    _te->debug.inspections[_te->debug.inspections_count].name="buffer3";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4200;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;

    _te->trackedVariables[0] = resultsame0;
    _te->trackedVariables[1] = resultsame1;
    _te->trackedVariables[2] = resultdifferent0;
    _te->trackedVariables[3] = resultdifferent1;

}

int test_cpu_compare_memory_tester( TestEnvironment * _te ) {

    Variable * resultsame0 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * resultsame1 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * resultdifferent0 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * resultdifferent1 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    // printf("resultsame0 = %2.2x [expected 0x00]\n", resultsame0->value );
    // printf("resultsame1 = %2.2x [expected 0xff]\n", resultsame1->value );
    // printf("resultdifferent0 = %2.2x [expected 0xff]\n", resultdifferent0->value );
    // printf("resultdifferent1 = %2.2x [expected 0x00]\n", resultdifferent1->value );
    
    return resultsame0->value == 0x00 && 
            resultsame1->value == 0xff && 
            resultdifferent0->value == 0xff && 
            resultdifferent1->value == 0x00;

}

//===========================================================================

void test_cpu_compare_memory_size_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    int i=0;
    char buffer1[160]; 
    char buffer2[160];
    char buffer3[160];
    for(i=0;i<160; ++i ) {
        buffer1[i] = i;
        buffer2[i] = i;
        if ( i < 100 ) {
            buffer3[i] = i;
        } else {
            buffer3[i] = 0x42;
        }
    }

    Variable * source = variable_define( e, "source", VT_BUFFER, 0x0 );
    Variable * same = variable_define( e, "same", VT_BUFFER, 0x0 );
    Variable * different = variable_define( e, "different", VT_BUFFER, 0x0 );
    Variable * asource = variable_define( e, "asource", VT_ADDRESS, 0x4000 );
    Variable * asame = variable_define( e, "asame", VT_ADDRESS, 0x4100 );
    Variable * adifferent = variable_define( e, "adifferent", VT_ADDRESS, 0x4200 );

    Variable * resultsame0 = variable_define( e, "resultsame0", VT_BYTE, 0x42 );
    Variable * resultsame1 = variable_define( e, "resultsame1", VT_BYTE, 0x42 );
    Variable * resultdifferent0 = variable_define( e, "resultdifferent0", VT_BYTE, 0x42 );
    Variable * resultdifferent1 = variable_define( e, "resultdifferent1", VT_BYTE, 0x42 );

    variable_store_buffer( e, source->name, buffer1, 160, 0x4000 );
    variable_store_buffer( e, same->name, buffer2, 160, 0x4100 );
    variable_store_buffer( e, different->name, buffer3, 160, 0x4200 );

    cpu_compare_memory_size( e, asource->realName, asame->realName, 160, resultsame1->realName, 1 );
    cpu_compare_memory_size( e, asource->realName, asame->realName, 160, resultsame0->realName, 0 );
    cpu_compare_memory_size( e, asource->realName, adifferent->realName, 160, resultdifferent1->realName, 1 );
    cpu_compare_memory_size( e, asource->realName, adifferent->realName, 160, resultdifferent0->realName, 0 );

    _te->debug.inspections[_te->debug.inspections_count].name="buffer1";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4000;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    _te->debug.inspections[_te->debug.inspections_count].name="buffer2";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4100;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    _te->debug.inspections[_te->debug.inspections_count].name="buffer3";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4200;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;

    _te->trackedVariables[0] = resultsame0;
    _te->trackedVariables[1] = resultsame1;
    _te->trackedVariables[2] = resultdifferent0;
    _te->trackedVariables[3] = resultdifferent1;

}

int test_cpu_compare_memory_size_tester( TestEnvironment * _te ) {

    Variable * resultsame0 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * resultsame1 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * resultdifferent0 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * resultdifferent1 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    // printf("resultsame0 = %2.2x [expected 0x00]\n", resultsame0->value );
    // printf("resultsame1 = %2.2x [expected 0xff]\n", resultsame1->value );
    // printf("resultdifferent0 = %2.2x [expected 0xff]\n", resultdifferent0->value );
    // printf("resultdifferent1 = %2.2x [expected 0x00]\n", resultdifferent1->value );
    
    return resultsame0->value == 0x00 && 
            resultsame1->value == 0xff && 
            resultdifferent0->value == 0xff && 
            resultdifferent1->value == 0x00;

}

//===========================================================================

void test_cpu_less_than_memory_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    int i=0;
    char buffer1[160]; 
    char buffer2[160];
    char buffer3[160];
    for(i=0;i<160; ++i ) {
        buffer1[i] = i;
        buffer2[i] = i;
        buffer3[i] = i+1;
    }

    Variable * source = variable_define( e, "source", VT_BUFFER, 0x0 );
    Variable * same = variable_define( e, "same", VT_BUFFER, 0x0 );
    Variable * different = variable_define( e, "different", VT_BUFFER, 0x0 );
    Variable * asource = variable_define( e, "asource", VT_ADDRESS, 0x4000 );
    Variable * asame = variable_define( e, "asame", VT_ADDRESS, 0x4100 );
    Variable * adifferent = variable_define( e, "adifferent", VT_ADDRESS, 0x4200 );
    Variable * size = variable_define( e, "size", VT_BYTE, 160 );

    Variable * resultsame0 = variable_define( e, "resultsame0", VT_BYTE, 0x42 );
    Variable * resultsame1 = variable_define( e, "resultsame1", VT_BYTE, 0x42 );
    Variable * resultdifferent0 = variable_define( e, "resultdifferent0", VT_BYTE, 0x42 );
    Variable * resultdifferent1 = variable_define( e, "resultdifferent1", VT_BYTE, 0x42 );

    variable_store_buffer( e, source->name, buffer1, 160, 0x4000 );
    variable_store_buffer( e, same->name, buffer2, 160, 0x4100 );
    variable_store_buffer( e, different->name, buffer3, 160, 0x4200 );

    cpu_less_than_memory( e, asource->realName, asame->realName, size->realName, resultsame1->realName, 1 );
    cpu_less_than_memory( e, asource->realName, asame->realName, size->realName, resultsame0->realName, 0 );
    cpu_less_than_memory( e, asource->realName, adifferent->realName, size->realName, resultdifferent1->realName, 1 );
    cpu_less_than_memory( e, asource->realName, adifferent->realName, size->realName, resultdifferent0->realName, 0 );

    _te->debug.inspections[_te->debug.inspections_count].name="buffer1";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4000;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    _te->debug.inspections[_te->debug.inspections_count].name="buffer2";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4100;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    _te->debug.inspections[_te->debug.inspections_count].name="buffer3";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4200;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;

    _te->trackedVariables[0] = resultsame0;
    _te->trackedVariables[1] = resultsame1;
    _te->trackedVariables[2] = resultdifferent0;
    _te->trackedVariables[3] = resultdifferent1;

}

int test_cpu_less_than_memory_tester( TestEnvironment * _te ) {

    Variable * resultsame0 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * resultsame1 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * resultdifferent0 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * resultdifferent1 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

// printf("resultsame0 = %2.2x [expected 0x00]\n", resultsame0->value );
// printf("resultsame1 = %2.2x [expected 0xff]\n", resultsame1->value );
// printf("resultdifferent0 = %2.2x [expected 0xff]\n", resultdifferent0->value );
// printf("resultdifferent1 = %2.2x [expected 0xff]\n", resultdifferent1->value );
    
    return resultsame0->value == 0x00 && 
            resultsame1->value == 0xff && 
            resultdifferent0->value == 0xff && 
            resultdifferent1->value == 0xff;

}

//===========================================================================

void test_cpu_less_than_memory_size_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    int i=0;
    char buffer1[160]; 
    char buffer2[160];
    char buffer3[160];
    for(i=0;i<160; ++i ) {
        buffer1[i] = i;
        buffer2[i] = i;
        buffer3[i] = i+1;
    }

    Variable * source = variable_define( e, "source", VT_BUFFER, 0x0 );
    Variable * same = variable_define( e, "same", VT_BUFFER, 0x0 );
    Variable * different = variable_define( e, "different", VT_BUFFER, 0x0 );
    Variable * asource = variable_define( e, "asource", VT_ADDRESS, 0x4000 );
    Variable * asame = variable_define( e, "asame", VT_ADDRESS, 0x4100 );
    Variable * adifferent = variable_define( e, "adifferent", VT_ADDRESS, 0x4200 );

    Variable * resultsame0 = variable_define( e, "resultsame0", VT_BYTE, 0x42 );
    Variable * resultsame1 = variable_define( e, "resultsame1", VT_BYTE, 0x42 );
    Variable * resultdifferent0 = variable_define( e, "resultdifferent0", VT_BYTE, 0x42 );
    Variable * resultdifferent1 = variable_define( e, "resultdifferent1", VT_BYTE, 0x42 );

    variable_store_buffer( e, source->name, buffer1, 160, 0x4000 );
    variable_store_buffer( e, same->name, buffer2, 160, 0x4100 );
    variable_store_buffer( e, different->name, buffer3, 160, 0x4200 );

    cpu_less_than_memory_size( e, asource->realName, asame->realName, 160, resultsame1->realName, 1 );
    cpu_less_than_memory_size( e, asource->realName, asame->realName, 160, resultsame0->realName, 0 );
    cpu_less_than_memory_size( e, asource->realName, adifferent->realName, 160, resultdifferent1->realName, 1 );
    cpu_less_than_memory_size( e, asource->realName, adifferent->realName, 160, resultdifferent0->realName, 0 );

    _te->debug.inspections[_te->debug.inspections_count].name="buffer1";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4000;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    _te->debug.inspections[_te->debug.inspections_count].name="buffer2";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4100;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    _te->debug.inspections[_te->debug.inspections_count].name="buffer3";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4200;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;

    _te->trackedVariables[0] = resultsame0;
    _te->trackedVariables[1] = resultsame1;
    _te->trackedVariables[2] = resultdifferent0;
    _te->trackedVariables[3] = resultdifferent1;

}

int test_cpu_less_than_memory_size_tester( TestEnvironment * _te ) {

    Variable * resultsame0 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * resultsame1 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * resultdifferent0 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * resultdifferent1 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    // printf("resultsame0 = %2.2x [expected 0x00]\n", resultsame0->value );
    // printf("resultsame1 = %2.2x [expected 0xff]\n", resultsame1->value );
    // printf("resultdifferent0 = %2.2x [expected 0xff]\n", resultdifferent0->value );
    // printf("resultdifferent1 = %2.2x [expected 0xff]\n", resultdifferent1->value );
    
    return resultsame0->value == 0x00 && 
            resultsame1->value == 0xff && 
            resultdifferent0->value == 0xff && 
            resultdifferent1->value == 0xff;

}

//===========================================================================

void test_cpu_greater_than_memory_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    int i=0;
    char buffer1[160]; 
    char buffer2[160];
    char buffer3[160];
    for(i=0;i<160; ++i ) {
        buffer1[i] = i;
        buffer2[i] = i;
        buffer3[i] = i+1;
    }

    Variable * source = variable_define( e, "source", VT_BUFFER, 0x0 );
    Variable * same = variable_define( e, "same", VT_BUFFER, 0x0 );
    Variable * different = variable_define( e, "different", VT_BUFFER, 0x0 );
    Variable * asource = variable_define( e, "asource", VT_ADDRESS, 0x4000 );
    Variable * asame = variable_define( e, "asame", VT_ADDRESS, 0x4100 );
    Variable * adifferent = variable_define( e, "adifferent", VT_ADDRESS, 0x4200 );
    Variable * size = variable_define( e, "size", VT_BYTE, 160 );

    Variable * resultsame0 = variable_define( e, "resultsame0", VT_BYTE, 0x42 );
    Variable * resultsame1 = variable_define( e, "resultsame1", VT_BYTE, 0x42 );
    Variable * resultdifferent0 = variable_define( e, "resultdifferent0", VT_BYTE, 0x42 );
    Variable * resultdifferent1 = variable_define( e, "resultdifferent1", VT_BYTE, 0x42 );

    variable_store_buffer( e, source->name, buffer1, 160, 0x4000 );
    variable_store_buffer( e, same->name, buffer2, 160, 0x4100 );
    variable_store_buffer( e, different->name, buffer3, 160, 0x4200 );

    cpu_greater_than_memory( e, asource->realName, asame->realName, size->realName, resultsame1->realName, 1 );
    cpu_greater_than_memory( e, asource->realName, asame->realName, size->realName, resultsame0->realName, 0 );
    cpu_greater_than_memory( e, asource->realName, adifferent->realName, size->realName, resultdifferent1->realName, 1 );
    cpu_greater_than_memory( e, asource->realName, adifferent->realName, size->realName, resultdifferent0->realName, 0 );

    _te->debug.inspections[_te->debug.inspections_count].name="buffer1";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4000;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    _te->debug.inspections[_te->debug.inspections_count].name="buffer2";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4100;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    _te->debug.inspections[_te->debug.inspections_count].name="buffer3";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4200;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;

    _te->trackedVariables[0] = resultsame0;
    _te->trackedVariables[1] = resultsame1;
    _te->trackedVariables[2] = resultdifferent0;
    _te->trackedVariables[3] = resultdifferent1;

}

int test_cpu_greater_than_memory_tester( TestEnvironment * _te ) {

    Variable * resultsame0 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * resultsame1 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * resultdifferent0 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * resultdifferent1 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    // printf("resultsame0 = %2.2x [expected 0x00]\n", resultsame0->value );
    // printf("resultsame1 = %2.2x [expected 0xff]\n", resultsame1->value );
    // printf("resultdifferent0 = %2.2x [expected 0x00]\n", resultdifferent0->value );
    // printf("resultdifferent1 = %2.2x [expected 0x00]\n", resultdifferent1->value );
    
    return resultsame0->value == 0x00 && 
            resultsame1->value == 0xff && 
            resultdifferent0->value == 0x00 && 
            resultdifferent1->value == 0x00;

}

//===========================================================================

void test_cpu_greater_than_memory_size_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    int i=0;
    char buffer1[160]; 
    char buffer2[160];
    char buffer3[160];
    for(i=0;i<160; ++i ) {
        buffer1[i] = i;
        buffer2[i] = i;
        buffer3[i] = i+1;
    }

    Variable * source = variable_define( e, "source", VT_BUFFER, 0x0 );
    Variable * same = variable_define( e, "same", VT_BUFFER, 0x0 );
    Variable * different = variable_define( e, "different", VT_BUFFER, 0x0 );
    Variable * asource = variable_define( e, "asource", VT_ADDRESS, 0x4000 );
    Variable * asame = variable_define( e, "asame", VT_ADDRESS, 0x4100 );
    Variable * adifferent = variable_define( e, "adifferent", VT_ADDRESS, 0x4200 );

    Variable * resultsame0 = variable_define( e, "resultsame0", VT_BYTE, 0x42 );
    Variable * resultsame1 = variable_define( e, "resultsame1", VT_BYTE, 0x42 );
    Variable * resultdifferent0 = variable_define( e, "resultdifferent0", VT_BYTE, 0x42 );
    Variable * resultdifferent1 = variable_define( e, "resultdifferent1", VT_BYTE, 0x42 );

    variable_store_buffer( e, source->name, buffer1, 160, 0x4000 );
    variable_store_buffer( e, same->name, buffer2, 160, 0x4100 );
    variable_store_buffer( e, different->name, buffer3, 160, 0x4200 );

    cpu_greater_than_memory_size( e, asource->realName, asame->realName, 160, resultsame1->realName, 1 );
    cpu_greater_than_memory_size( e, asource->realName, asame->realName, 160, resultsame0->realName, 0 );
    cpu_greater_than_memory_size( e, asource->realName, adifferent->realName, 160, resultdifferent1->realName, 1 );
    cpu_greater_than_memory_size( e, asource->realName, adifferent->realName, 160, resultdifferent0->realName, 0 );

    _te->debug.inspections[_te->debug.inspections_count].name="buffer1";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4000;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    _te->debug.inspections[_te->debug.inspections_count].name="buffer2";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4100;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;
    _te->debug.inspections[_te->debug.inspections_count].name="buffer3";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4200;
    _te->debug.inspections[_te->debug.inspections_count].size=160;
    ++_te->debug.inspections_count;

    _te->trackedVariables[0] = resultsame0;
    _te->trackedVariables[1] = resultsame1;
    _te->trackedVariables[2] = resultdifferent0;
    _te->trackedVariables[3] = resultdifferent1;

}

int test_cpu_greater_than_memory_size_tester( TestEnvironment * _te ) {

    Variable * resultsame0 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * resultsame1 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * resultdifferent0 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * resultdifferent1 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    // printf("resultsame0 = %2.2x [expected 0x00]\n", resultsame0->value );
    // printf("resultsame1 = %2.2x [expected 0xff]\n", resultsame1->value );
    // printf("resultdifferent0 = %2.2x [expected 0x00]\n", resultdifferent0->value );
    // printf("resultdifferent1 = %2.2x [expected 0x00]\n", resultdifferent1->value );
    
    return resultsame0->value == 0x00 && 
            resultsame1->value == 0xff && 
            resultdifferent0->value == 0x00 && 
            resultdifferent1->value == 0x00;

}

//===========================================================================

void test_cpu_move_8bit_indirect_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * asource = variable_define( e, "asource", VT_ADDRESS, 0x4000 );
    Variable * value = variable_define( e, "value", VT_BYTE, 0x42 );

    cpu_move_8bit_indirect( e, value->realName, asource->realName );

    _te->debug.inspections[_te->debug.inspections_count].name="buffer1";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4000;
    _te->debug.inspections[_te->debug.inspections_count].size=1;
    ++_te->debug.inspections_count;
    
}

int test_cpu_move_8bit_indirect_tester( TestEnvironment * _te ) {

    if ( _te->debug.inspections[0].memory[0] != 0x42 ) {
        return 0;
    }
    return 1;

}

//===========================================================================

void test_cpu_move_8bit_indirect_with_offset_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * asource = variable_define( e, "asource", VT_ADDRESS, 0x4000 );
    Variable * value = variable_define( e, "value", VT_BYTE, 0x42 );

    cpu_move_8bit_indirect_with_offset( e, value->realName, asource->realName, 159 );

    _te->debug.inspections[_te->debug.inspections_count].name="buffer1";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4000;
    _te->debug.inspections[_te->debug.inspections_count].size=320;
    ++_te->debug.inspections_count;
    
}

int test_cpu_move_8bit_indirect_with_offset_tester( TestEnvironment * _te ) {

    if ( _te->debug.inspections[0].memory[159] != 0x42 ) {
        return 0;
    }
    return 1;

}

//===========================================================================

void test_cpu_move_8bit_with_offset_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * asource = variable_define( e, "asource", VT_ADDRESS, 0x4000 );
    Variable * value = variable_define( e, "value", VT_BYTE, 0x42 );

    cpu_move_8bit_with_offset( e, value->realName, asource->realName, 1 );

    _te->debug.inspections[_te->debug.inspections_count].name="buffer1";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4000;
    _te->debug.inspections[_te->debug.inspections_count].size=320;
    ++_te->debug.inspections_count;
    
    _te->trackedVariables[0] = asource;

}

int test_cpu_move_8bit_with_offset_tester( TestEnvironment * _te ) {

    Variable * asource = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return asource->value = 0x4042;

}

//===========================================================================

void test_cpu_move_8bit_indirect_with_offset2_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * asource = variable_define( e, "asource", VT_ADDRESS, 0x4000 );
    Variable * value = variable_define( e, "value", VT_BYTE, 0x42 );
    Variable * size = variable_define( e, "size", VT_BYTE, 159 );

    cpu_move_8bit_indirect_with_offset2( e, value->realName, asource->realName, size->realName );

    _te->debug.inspections[_te->debug.inspections_count].name="buffer1";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4000;
    _te->debug.inspections[_te->debug.inspections_count].size=320;
    ++_te->debug.inspections_count;
    
}

int test_cpu_move_8bit_indirect_with_offset2_tester( TestEnvironment * _te ) {

    if ( _te->debug.inspections[0].memory[159] != 0x42 ) {
        return 0;
    }
    return 1;

}

//===========================================================================

void test_cpu_move_8bit_with_offset2_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * asource = variable_define( e, "asource", VT_ADDRESS, 0x4000 );
    Variable * value = variable_define( e, "value", VT_BYTE, 0x42 );
    Variable * offset = variable_define( e, "offset", VT_BYTE, 0x1 );

    cpu_move_8bit_with_offset2( e, value->realName, asource->realName, offset->realName );

    _te->debug.inspections[_te->debug.inspections_count].name="buffer1";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4000;
    _te->debug.inspections[_te->debug.inspections_count].size=320;
    ++_te->debug.inspections_count;
    
    _te->trackedVariables[0] = asource;

}

int test_cpu_move_8bit_with_offset2_tester( TestEnvironment * _te ) {

    Variable * asource = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return asource->value = 0x4042;

}

//===========================================================================

void test_cpu_move_8bit_indirect2_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    char buffer[10]; buffer[0] = 0x21;

    Variable * b = variable_define( e, "b", VT_BUFFER, 0x00 );
    Variable * value = variable_define( e, "value", VT_BYTE, 0x00 );

    variable_store_buffer( e, b->name, buffer, 10, 0x0 );

    cpu_move_8bit_indirect2( e, b->realName, value->realName );

    _te->trackedVariables[0] = value;

}

int test_cpu_move_8bit_indirect2_tester( TestEnvironment * _te ) {

    Variable * asource = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return asource->value = 0x21;

}

//===========================================================================

void test_cpu_move_16bit_indirect_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    char buffer[10]; buffer[0] = 0x21; buffer[1] = 0x33;

    Variable * b = variable_define( e, "b", VT_BUFFER, 0x00 );
    Variable * value = variable_define( e, "value", VT_WORD, 0x0000 );

    variable_store_buffer( e, b->name, buffer, 10, 0x0 );
    
    cpu_move_16bit_indirect( e, b->realName, value->realName );

    _te->trackedVariables[0] = value;

}

int test_cpu_move_16bit_indirect_tester( TestEnvironment * _te ) {

    Variable * asource = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return asource->value = 0x2133;

}

//===========================================================================

void test_cpu_move_16bit_indirect2_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    char buffer[10]; buffer[0] = 0x21; buffer[1] = 0x33;

    Variable * b = variable_define( e, "b", VT_BUFFER, 0x00 );
    Variable * value = variable_define( e, "value", VT_WORD, 0x0000 );

    variable_store_buffer( e, b->name, buffer, 10, 0x0 );
    
    cpu_move_16bit_indirect2( e, b->realName, value->realName );

    _te->trackedVariables[0] = value;

}

int test_cpu_move_16bit_indirect2_tester( TestEnvironment * _te ) {

    Variable * asource = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return asource->value = 0x2133;

}

//===========================================================================

void test_cpu_move_32bit_indirect_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    char buffer[10]; buffer[0] = 0x21; buffer[1] = 0x33; buffer[2] = 0x44; buffer[3] = 0x55;

    Variable * b = variable_define( e, "b", VT_BUFFER, 0x00 );
    Variable * value = variable_define( e, "value", VT_WORD, 0x0000 );

    variable_store_buffer( e, b->name, buffer, 10, 0x0 );
    
    cpu_move_16bit_indirect( e, b->realName, value->realName );

    _te->trackedVariables[0] = value;

}

int test_cpu_move_32bit_indirect_tester( TestEnvironment * _te ) {

    Variable * asource = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return asource->value = 0x21334455;

}

//===========================================================================

void test_cpu_move_32bit_indirect2_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    char buffer[10]; buffer[0] = 0x21; buffer[1] = 0x33; buffer[2] = 0x44; buffer[3] = 0x55;

    Variable * b = variable_define( e, "b", VT_BUFFER, 0x00 );
    Variable * value = variable_define( e, "value", VT_WORD, 0x0000 );

    variable_store_buffer( e, b->name, buffer, 10, 0x0 );
    
    cpu_move_32bit_indirect2( e, b->realName, value->realName );

    _te->trackedVariables[0] = value;

}

int test_cpu_move_32bit_indirect2_tester( TestEnvironment * _te ) {

    Variable * asource = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return asource->value = 0x21333355;

}

//===========================================================================

void test_cpu_uppercase_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    char buffer[32]; sprintf(buffer, "String text" );

    Variable * original = variable_define( e, "original", VT_BUFFER, 0x00 );
    Variable * uppercased = variable_define( e, "uppercased", VT_BUFFER, 0x00 );
    Variable * size = variable_define( e, "size", VT_BYTE, strlen( buffer ) );
    Variable * aoriginal = variable_define( e, "aoriginal", VT_ADDRESS, 0x4000 );
    Variable * auppercased = variable_define( e, "auppercased", VT_ADDRESS, 0x4100 );

    variable_store_buffer( e, original->name, buffer, strlen(buffer), 0x4000 );
    variable_store_buffer( e, uppercased->name, buffer, strlen(buffer), 0x4100 );
    
    cpu_uppercase( e, aoriginal->realName, size->realName, auppercased->realName );

    _te->debug.inspections[_te->debug.inspections_count].name="uppercased";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4100;
    _te->debug.inspections[_te->debug.inspections_count].size=64;
    ++_te->debug.inspections_count;
    
    _te->trackedVariables[0] = size;

}

int test_cpu_uppercase_tester( TestEnvironment * _te ) {

    Variable * size = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    _te->debug.inspections[0].memory[size->value] = 0;

    // printf( "%s", _te->debug.inspections[0].memory );

    return strcmp( _te->debug.inspections[0].memory, "STRING TEXT" ) == 0;

}

//===========================================================================

void test_cpu_lowercase_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    char buffer[32]; sprintf(buffer, "AlFaBeTaGaMmA" );

    Variable * original = variable_define( e, "original", VT_BUFFER, 0x00 );
    Variable * lowercased = variable_define( e, "lowercased", VT_BUFFER, 0x00 );
    Variable * size = variable_define( e, "size", VT_BYTE, strlen( buffer ) );
    Variable * aoriginal = variable_define( e, "aoriginal", VT_ADDRESS, 0x4000 );
    Variable * alowercased = variable_define( e, "alowercased", VT_ADDRESS, 0x4100 );

    variable_store_buffer( e, original->name, buffer, strlen(buffer), 0x4000 );
    variable_store_buffer( e, lowercased->name, buffer, strlen(buffer), 0x4100 );
    
    cpu_lowercase( e, aoriginal->realName, size->realName, alowercased->realName );

    _te->debug.inspections[_te->debug.inspections_count].name="lowercased";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4100;
    _te->debug.inspections[_te->debug.inspections_count].size=64;
    ++_te->debug.inspections_count;
    
    _te->trackedVariables[0] = size;

}

int test_cpu_lowercase_tester( TestEnvironment * _te ) {

    Variable * size = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    _te->debug.inspections[0].memory[size->value] = 0;

    // printf( "%s", _te->debug.inspections[0].memory );

    return strcmp( _te->debug.inspections[0].memory, "alfabetagamma" ) == 0;

}

//===========================================================================

void test_cpu_convert_string_into_16bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    char buffer[32]; sprintf(buffer, "1975" );

    Variable * original = variable_define( e, "original", VT_BUFFER, 0x00 );
    Variable * value = variable_define( e, "value", VT_WORD, 0x00 );
    Variable * size = variable_define( e, "size", VT_BYTE, strlen( buffer ) );
    Variable * aoriginal = variable_define( e, "aoriginal", VT_ADDRESS, 0x4000 );

    variable_store_buffer( e, original->name, buffer, strlen(buffer), 0x4000 );
    
    cpu_convert_string_into_16bit( e, aoriginal->realName, size->realName, value->realName );

    _te->trackedVariables[0] = value;

}

int test_cpu_convert_string_into_16bit_tester( TestEnvironment * _te ) {

    Variable * value = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return value->value = 1975;

}

//===========================================================================

void test_cpu_flip_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    char buffer[32]; sprintf(buffer, "ugbasic" );
    char buffer2[32]; sprintf(buffer2, "       " );

    Variable * original = variable_define( e, "original", VT_BUFFER, 0x00 );
    Variable * flipped = variable_define( e, "flipped", VT_BUFFER, 0x00 );
    Variable * size = variable_define( e, "size", VT_BYTE, strlen( buffer ) );
    Variable * aoriginal = variable_define( e, "aoriginal", VT_ADDRESS, 0x4000 );
    Variable * aflipped = variable_define( e, "aflipped", VT_ADDRESS, 0x4100 );

    variable_store_buffer( e, original->name, buffer, strlen(buffer), 0x4000 );
    variable_store_buffer( e, flipped->name, buffer2, strlen(buffer2), 0x4100 );
    
    cpu_flip( e, aoriginal->realName, size->realName, aflipped->realName );

    _te->debug.inspections[_te->debug.inspections_count].name="original";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4000;
    _te->debug.inspections[_te->debug.inspections_count].size=64;
    ++_te->debug.inspections_count;

    _te->debug.inspections[_te->debug.inspections_count].name="flipped";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4100;
    _te->debug.inspections[_te->debug.inspections_count].size=64;
    ++_te->debug.inspections_count;

    _te->trackedVariables[0] = size;

}

int test_cpu_flip_tester( TestEnvironment * _te ) {

    Variable * size = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    _te->debug.inspections[1].memory[size->value] = 0;

// printf( "memory = %s\n", _te->debug.inspections[1].memory );

    return strcmp( _te->debug.inspections[1].memory, "cisabgu" ) == 0;

}

//===========================================================================

void test_cpu_bit_check_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * value = variable_define( e, "value", VT_WORD, 0x4280 );
    Variable * result1 = variable_define( e, "result1", VT_BYTE, 0x00 );
    Variable * result0 = variable_define( e, "result0", VT_BYTE, 0x42 );

    cpu_bit_check( e, value->realName, 7, result1->realName, VT_BITWIDTH( value->type ) );
    cpu_bit_check( e, value->realName, 8, result0->realName, VT_BITWIDTH( value->type ) );

    _te->trackedVariables[0] = result1;
    _te->trackedVariables[1] = result0;

}

int test_cpu_bit_check_tester( TestEnvironment * _te ) {

    Variable * result1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * result0 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

// printf( "result1 = %2.2x [expected 0xff]\n", result1->value );
// printf( "result0 = %2.2x [expected 0x00]\n", result0->value );

    return result0->value == 0x00 && result1->value == 0xff;

}

//===========================================================================

void test_cpu_bit_check_payloadB( TestEnvironment * _te ) {

    Environment * e = &_te->environment;
    Variable *result[16];

    Variable * value = variable_define( e, "value", VT_WORD, 0x5555 );

    int i=0;
    for( i=0; i<16; ++i ) {
        char buffer[MAX_TEMPORARY_STORAGE]; sprintf(buffer, "result%d", i );
        result[i] = variable_define( e, buffer, VT_BYTE, 0x55 );
        cpu_bit_check( e, value->realName, i, result[i]->realName, VT_BITWIDTH( value->type ) );
    }

    for( i=0; i<16; ++i ) {
        _te->trackedVariables[i] = result[i];
    }

}

int test_cpu_bit_check_testerB( TestEnvironment * _te ) {

    Variable *result[16];

    int i = 0;
    for( i=0; i<16; ++i ) {
        result[i] = variable_retrieve( &_te->environment, _te->trackedVariables[i]->name );
    }

    for( i=0; i<16; ++i ) {
        // printf( "result[%d] = %2.2x [expected %2.2x]\n", i, result[i]->value, ( i % 2 ) == 0 ? 0x00 : 0xff );
    }

    for( i=0; i<16; ++i ) {
        if ( ( i % 2 ) == 0 ) {
            if ( result[i]->value == 0x00 ) {
                return 0;
            }
        } else {
            if ( result[i]->value == 0xff ) {
                return 0;
            }
        }
    }

    return 1;

}

//===========================================================================

void test_cpu_dsdefine_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * string = variable_define( e, "string", VT_STRING, 0 );
    Variable * index = variable_define( e, "index", VT_DSTRING, 1 );
    Variable * address = variable_define( e, "address", VT_ADDRESS, 0x4242 );
    Variable * size = variable_define( e, "size", VT_BYTE, 0x00 );
    Variable * address2 = variable_define( e, "address2", VT_ADDRESS, 0x4100 );

    variable_store_string( e, string->name, "Prova" );

    cpu_dsdefine( e, string->realName, index->realName );
    cpu_dsdescriptor( e, index->realName, address->realName, size->realName );
    cpu_mem_move( e, address->realName, address2->realName, size->realName );

    _te->debug.inspections[_te->debug.inspections_count].name="address2";
    _te->debug.inspections[_te->debug.inspections_count].address=0x4100;
    _te->debug.inspections[_te->debug.inspections_count].size=64;
    ++_te->debug.inspections_count;
    
    _te->trackedVariables[0] = string;
    _te->trackedVariables[1] = index;
    _te->trackedVariables[2] = address;
    _te->trackedVariables[3] = size;
    _te->trackedVariables[4] = address2;

}

int test_cpu_dsdefine_tester( TestEnvironment * _te ) {

    Variable * string = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * index = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * address = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * size = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * address2 = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );

    _te->debug.inspections[0].memory[size->value] = 0;

// // printf( "string = %s [expected 'Prova']\n", string->valueString );
// printf( "index = %2.2x (%d) [expected: 0x01]\n", index->value, index->value );
// printf( "address = %4.4x (%d) [expected: != 0x4242]\n", address->value, address->value );
// printf( "size = %2.2x (%d) [expected: 5]\n", size->value, size->value );
// printf( "address2 = %4.4x (%d) [expected: 0x4100]\n", address2->value, address2->value );
// // printf( "memory = %s [expected 'Prova']\n", _te->debug.inspections[0].memory );

    return 
        // // to be adapter on charset of target strcmp( _te->debug.inspections[0].memory, "Prova" ) == 0 &&
        // // to be adapter on charset of target strcmp( string->valueString, "Prova" ) == 0 &&
        index->value == 1 &&
        address->value != 0x4242 &&
        size->value == 5 &&
        address2->value == 0x4100;

}

//===========================================================================

void test_cpu_dsalloc_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * index = variable_define( e, "index", VT_DSTRING, 1 );
    Variable * address = variable_define( e, "address", VT_ADDRESS, 0x4242 );
    Variable * size = variable_define( e, "size", VT_BYTE, 0x42 );

    cpu_dsalloc( e, size->realName, index->realName );
    cpu_dsdescriptor( e, index->realName, address->realName, size->realName );

    _te->trackedVariables[0] = index;
    _te->trackedVariables[1] = address;
    _te->trackedVariables[2] = size;

}

int test_cpu_dsalloc_tester( TestEnvironment * _te ) {

    Variable * index = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * address = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * size = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );

// printf( "index = %2.2x (%d) [expected: 0x01]\n", index->value, index->value );
// printf( "address = %4.4x (%d) [expected: != 0x4242]\n", address->value, address->value );
// printf( "size = %2.2x (%d) [expected: 42]\n", size->value, size->value );

    return 
        index->value == 1 &&
        address->value != 0x4242 &&
        size->value == 0x42;

}

//===========================================================================

void test_cpu_dsfree_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * index1 = variable_define( e, "index1", VT_DSTRING, 1 );
    Variable * address1 = variable_define( e, "address1", VT_ADDRESS, 0x4242 );
    Variable * size1 = variable_define( e, "size1", VT_BYTE, 0x42 );
    Variable * size1c = variable_define( e, "size1c", VT_BYTE, 0x00 );
    Variable * index2 = variable_define( e, "index2", VT_DSTRING, 1 );
    Variable * address2 = variable_define( e, "address2", VT_ADDRESS, 0x4242 );
    Variable * size2 = variable_define( e, "size2", VT_BYTE, 0x64 );
    Variable * size2c = variable_define( e, "size2c", VT_BYTE, 0x00 );

    cpu_dsalloc( e, size1->realName, index1->realName );
    cpu_dsdescriptor( e, index1->realName, address1->realName, size1c->realName );
    cpu_dsfree( e, index1->realName );
    cpu_dsalloc( e, size2->realName, index2->realName );
    cpu_dsdescriptor( e, index2->realName, address2->realName, size2c->realName );

    _te->trackedVariables[0] = index1;
    _te->trackedVariables[1] = address1;
    _te->trackedVariables[2] = size1;
    _te->trackedVariables[3] = size1c;

    _te->trackedVariables[4] = index2;
    _te->trackedVariables[5] = address2;
    _te->trackedVariables[6] = size2;
    _te->trackedVariables[7] = size2c;

}

int test_cpu_dsfree_tester( TestEnvironment * _te ) {

    Variable * index1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * address1 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * size1 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * size1c = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    Variable * index2 = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );
    Variable * address2 = variable_retrieve( &_te->environment, _te->trackedVariables[5]->name );
    Variable * size2 = variable_retrieve( &_te->environment, _te->trackedVariables[6]->name );
    Variable * size2c = variable_retrieve( &_te->environment, _te->trackedVariables[7]->name );

// printf( "index1 = %2.2x (%d) [expected: 0x01]\n", index1->value, index1->value );
// printf( "address1 = %4.4x (%d) [expected: != 0x4242]\n", address1->value, address1->value );
// printf( "size1 = %2.2x (%d) [expected: 42]\n", size1->value, size1->value );
// printf( "size1c = %2.2x (%d) [expected: 42]\n", size1c->value, size1c->value );

// printf( "index2 = %2.2x (%d) [expected: 0x01]\n", index2->value, index2->value );
// printf( "address2 = %4.4x (%d) [expected: != 0x4242]\n", address2->value, address2->value );
// printf( "size2 = %2.2x (%d) [expected: 64]\n", size2->value, size2->value );
// printf( "size2c = %2.2x (%d) [expected: 64]\n", size2c->value, size2c->value );

    return 
        index1->value == 1 &&
        address1->value != 0x4242 &&
        size1->value == 0x42 &&
        size1c->value == size1->value &&
        index2->value == 1 &&
        address2->value != 0x4242 &&
        size2->value == 0x64 &&
        size2c->value == size2->value;

}

//===========================================================================

void test_cpu_dswrite_payloadB( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * index1 = variable_define( e, "index1", VT_DSTRING, 1 );
    Variable * address1 = variable_define( e, "address1", VT_ADDRESS, 0x4242 );
    Variable * size1c = variable_define( e, "size1c", VT_BYTE, 0x00 );
    Variable * address2 = variable_define( e, "address2", VT_ADDRESS, 0x4242 );
    Variable * size2c = variable_define( e, "size2c", VT_BYTE, 0x00 );

    Variable * string = variable_define( e, "string", VT_STRING, 0 );

    variable_store_string( e, string->name, "Prova" );

    cpu_dsdefine( e, string->realName, index1->realName );
    cpu_dsdescriptor( e, index1->realName, address1->realName, size1c->realName );
    cpu_dswrite( e, index1->realName );
    cpu_dsdescriptor( e, index1->realName, address2->realName, size2c->realName );

    _te->trackedVariables[0] = index1;
    _te->trackedVariables[1] = address1;
    _te->trackedVariables[2] = size1c;

    _te->trackedVariables[3] = address2;
    _te->trackedVariables[4] = size2c;

}

int test_cpu_dswrite_testerB( TestEnvironment * _te ) {

    Variable * index1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * address1 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * size1c = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );

    Variable * address2 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * size2c = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );

// printf( "index1 = %2.2x (%d) [expected: 0x01]\n", index1->value, index1->value );
// printf( "address1 = %4.4x (%d) [expected: != 0x4242]\n", address1->value, address1->value );
// printf( "size1c = %2.2x (%d) [expected: 5]\n", size1c->value, size1c->value );

// printf( "address2 = %4.4x (%d) [expected: != 0x4242]\n", address2->value, address2->value );
// printf( "size2c = %2.2x (%d) [expected: 5]\n", size2c->value, size2c->value );

    return 
        index1->value == 1 &&
        address1->value != 0x4242 &&
        address2->value != address1->value &&
        size2c->value == size1c->value;

}

//===========================================================================

void test_cpu_dswrite_payloadC( TestEnvironment * _te ) {

    Environment * e = &_te->environment;
    Variable * i = variable_define( e, "i", VT_WORD, 0 );
    Variable * limit = variable_define( e, "limit", VT_WORD, 20000 );

    begin_loop( e );
        Variable * address = variable_temporary( e, VT_ADDRESS, "(temporary for PRINT)");
        Variable * size = variable_temporary( e, VT_BYTE, "(temporary for PRINT)");
        Variable * tmp = variable_temporary( e, VT_DSTRING, "(temporary for PRINT)");
        variable_store_string( e, tmp->name, "           " );
        cpu_dswrite( e, tmp->realName );        
        cpu_dsfree( e, tmp->realName );        
        cpu_inc_16bit( e, i->realName );
        Variable * c = variable_compare( e, i->name, limit->name);
        exit_loop_if( e, c->name, 0 );
    end_loop( e );

    _te->trackedVariables[0] = i;
    _te->trackedVariables[1] = limit;


}

int test_cpu_dswrite_testerC( TestEnvironment * _te ) {

    Variable * i = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * limit = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return i->value == limit->value;

}

//===========================================================================

void test_cpu_move_8bit_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * first = variable_define( e, "first", VT_BYTE, 0x42 );
    Variable * second = variable_define( e, "second", VT_BYTE, 0x84 );

    cpu_move_8bit( e, first->realName, second->realName );

    _te->trackedVariables[0] = first;
    _te->trackedVariables[1] = second;
    
}

int test_cpu_move_8bit_tester( TestEnvironment * _te ) {

    Variable * first = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * second = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return first->value == second->value && second->value == 0x42;

}

//===========================================================================

void test_cpu_dsresize_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * string = variable_define( e, "string", VT_STRING, 0 );
    Variable * dstring = variable_define( e, "dstring", VT_DSTRING, 0 );
    Variable * address = variable_define( e, "address", VT_ADDRESS, 0 );
    Variable * size = variable_define( e, "size", VT_BYTE, 0 );
    Variable * resize = variable_define( e, "resize", VT_BYTE, 1 );

    variable_store_string( e, string->name, "caparezza" );

    cpu_dsdefine( e, string->realName, dstring->realName );

    cpu_dswrite( e, dstring->realName );

    cpu_dsdescriptor( e, dstring->realName, address->realName, size->realName );

    cpu_dsresize( e, dstring->realName, resize->realName );

    _te->trackedVariables[0] = dstring;
    
}

int test_cpu_dsresize_tester( TestEnvironment * _te ) {

    Variable * dstring = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    // printf( "result = %s [%2.2x] [expected 'c']\n", dstring->valueString, (unsigned char)dstring->valueString[0] );

    return strlen( dstring->valueString ) == 1;

}

//===========================================================================

void test_cpu_sqroot_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * value = variable_define( e, "value", VT_WORD, 81 );
    Variable * result = variable_define( e, "result", VT_BYTE, 0 );

    cpu_sqroot( e, value->realName, result->realName );

    _te->trackedVariables[0] = result;
    
}

int test_cpu_sqroot_tester( TestEnvironment * _te ) {

    Variable * result = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

// printf( "result = %2.2x (%d) [expected 9]\n", result->value, result->value );

    return result->value == 9;

}

void test_cpu( ) {

    // to be adapted (false negative) create_test( "cpu_bits_to_string", &test_cpu_bits_to_string_payload, &test_cpu_bits_to_string_tester );    
    // to be adapted (false negative) create_test( "cpu_bits_to_string32", &test_cpu_bits_to_string32_payload, &test_cpu_bits_to_string32_tester );    
    create_test( "cpu_dswrite", &test_cpu_dswrite_payload, &test_cpu_dswrite_tester );    
    create_test( "cpu_dsgc", &test_cpu_dsgc_payload, &test_cpu_dsgc_tester );    
    // to be adapted not using DSTRING  create_test( "cpu_dsgc A", &test_cpu_dsgc_payloadA, &test_cpu_dsgc_testerA );    
    // to be adapted not using DSTRING  create_test( "cpu_dsgc B", &test_cpu_dsgc_payloadB, &test_cpu_dsgc_testerB );    
    create_test( "cpu_logical_and_8bit", &test_cpu_logical_and_8bit_payload, &test_cpu_logical_and_8bit_tester );    
    create_test( "cpu_logical_not_8bit", &test_cpu_logical_not_8bit_payload, &test_cpu_logical_not_8bit_tester );    
    create_test( "cpu_bit_check_extended", &test_cpu_bit_check_extended_payload, &test_cpu_bit_check_extended_tester );    
    create_test( "cpu_bit_check_extended B", &test_cpu_bit_check_extended_payloadB, &test_cpu_bit_check_extended_testerB );
    create_test( "cpu_less_than_8bit", &test_cpu_less_than_8bit_payload, &test_cpu_less_than_8bit_tester );    
    create_test( "cpu_less_than_16bit A", &test_cpu_less_than_16bit_payload, &test_cpu_less_than_16bit_tester );    
    create_test( "cpu_less_than_16bit B", &test_cpu_less_than_16bit_payloadB, &test_cpu_less_than_16bit_testerB );    
    create_test( "cpu_less_than_32bit", &test_cpu_less_than_32bit_payload, &test_cpu_less_than_32bit_tester );    
    create_test( "cpu_greater_than_8bit", &test_cpu_greater_than_8bit_payload, &test_cpu_greater_than_8bit_tester );    
    create_test( "cpu_greater_than_16bit", &test_cpu_greater_than_16bit_payload, &test_cpu_greater_than_16bit_tester );    
    create_test( "cpu_greater_than_32bit", &test_cpu_greater_than_32bit_payload, &test_cpu_greater_than_32bit_tester );    
    create_test( "cpu_math_div2_8bit", &test_cpu_math_div2_8bit_payload, &test_cpu_math_div2_8bit_tester );
    create_test( "cpu_math_div2_const_16bit", &test_cpu_math_div2_const_16bit_payload, &test_cpu_math_div2_const_16bit_tester );
    create_test( "cpu_math_div2_const_32bit", &test_cpu_math_div2_const_32bit_payload, &test_cpu_math_div2_const_32bit_tester );
    create_test( "cpu_math_div2_const_8bit", &test_cpu_math_div2_const_8bit_payload, &test_cpu_math_div2_const_8bit_tester );
    create_test( "cpu_math_double_16bit", &test_cpu_math_double_16bit_payload, &test_cpu_math_double_16bit_tester );
    create_test( "cpu_math_double_32bit", &test_cpu_math_double_32bit_payload, &test_cpu_math_double_32bit_tester );
    create_test( "cpu_math_double_8bit", &test_cpu_math_double_8bit_payload, &test_cpu_math_double_8bit_tester );
    create_test( "cpu_math_mul_8bit_to_16bit", &test_cpu_math_mul_8bit_to_16bit_payload, &test_cpu_math_mul_8bit_to_16bit_tester );
    create_test( "cpu_math_mul_16bit_to_32bit", &test_cpu_math_mul_16bit_to_32bit_payload, &test_cpu_math_mul_16bit_to_32bit_tester );
    create_test( "cpu_math_div_8bit_to_8bit", &test_cpu_math_div_8bit_to_8bit_payload, &test_cpu_math_div_8bit_to_8bit_tester );
    create_test( "cpu_math_div_16bit_to_16bit A", &test_cpu_math_div_16bit_to_16bit_payload, &test_cpu_math_div_16bit_to_16bit_tester );
    create_test( "cpu_math_div_16bit_to_16bit B", &test_cpu_math_div_16bit_to_16bit_payloadB, &test_cpu_math_div_16bit_to_16bit_testerB );
    create_test( "cpu_math_div_16bit_to_16bit C", &test_cpu_math_div_16bit_to_16bit_payloadC, &test_cpu_math_div_16bit_to_16bit_testerC );
    create_test( "cpu_math_div_16bit_to_16bit D", &test_cpu_math_div_16bit_to_16bit_payloadD, &test_cpu_math_div_16bit_to_16bit_testerD );
    create_test( "cpu_math_mul2_const_16bit", &test_cpu_math_mul2_const_16bit_payload, &test_cpu_math_mul2_const_16bit_tester );
    create_test( "cpu_math_mul2_const_32bit", &test_cpu_math_mul2_const_32bit_payload, &test_cpu_math_mul2_const_32bit_tester );
    create_test( "cpu_math_mul2_const_8bit", &test_cpu_math_mul2_const_8bit_payload, &test_cpu_math_mul2_const_8bit_tester );
    create_test( "cpu_number_to_string_payload", &test_cpu_number_to_string_payload, &test_cpu_number_to_string_tester );
    create_test( "cpu_number_to_string_payloadB", &test_cpu_number_to_string_payloadB, &test_cpu_number_to_string_testerB );
    create_test( "cpu_number_to_string_payloadC", &test_cpu_number_to_string_payloadC, &test_cpu_number_to_string_testerC );
    create_test( "cpu_number_to_string_payloadD", &test_cpu_number_to_string_payloadD, &test_cpu_number_to_string_testerD );
    create_test( "cpu_number_to_string_payloadE", &test_cpu_number_to_string_payloadE, &test_cpu_number_to_string_testerE );
    create_test( "cpu_peek", &test_cpu_peek_payload, &test_cpu_peek_tester );
    create_test( "cpu_poke", &test_cpu_poke_payload, &test_cpu_poke_tester );
    create_test( "cpu_move_8bit", &test_cpu_move_8bit_payload, &test_cpu_move_8bit_tester );
    create_test( "cpu_fill_blocks", &test_cpu_fill_blocks_payload, &test_cpu_fill_blocks_tester );
    create_test( "cpu_fill", &test_cpu_fill_payload, &test_cpu_fill_tester );
    create_test( "cpu_compare_8bit", &test_cpu_compare_8bit_payload, &test_cpu_compare_8bit_tester );
    create_test( "cpu_math_add_8bit", &test_cpu_math_add_8bit_payload, &test_cpu_math_add_8bit_tester );
    create_test( "cpu_math_sub_8bit", &test_cpu_math_sub_8bit_payload, &test_cpu_math_sub_8bit_tester );
    create_test( "cpu_math_complement_const_8bit", &test_cpu_math_complement_const_8bit_payload, &test_cpu_math_complement_const_8bit_tester );
    create_test( "cpu_math_and_const_8bit", &test_cpu_math_and_const_8bit_payload, &test_cpu_math_and_const_8bit_tester );
    create_test( "cpu_move_16bit", &test_cpu_move_16bit_payload, &test_cpu_move_16bit_tester );
    create_test( "cpu_addressof_16bit", &test_cpu_addressof_16bit_payload, &test_cpu_addressof_16bit_tester );
    create_test( "cpu_compare_16bit", &test_cpu_compare_16bit_payload, &test_cpu_compare_16bit_tester );
    create_test( "cpu_math_add_16bit", &test_cpu_math_add_16bit_payload, &test_cpu_math_add_16bit_tester );
    create_test( "cpu_math_add_16bit_with_16bit", &test_cpu_math_add_16bit_with_16bit_payload, &test_cpu_math_add_16bit_with_16bit_tester );
    create_test( "cpu_math_add_16bit_with_8bit", &test_cpu_math_add_16bit_with_8bit_payload, &test_cpu_math_add_16bit_with_8bit_tester );
    create_test( "cpu_math_sub_16bit", &test_cpu_math_sub_16bit_payload, &test_cpu_math_sub_16bit_tester );
    create_test( "cpu_math_sub_16bit_with_8bit", &test_cpu_math_sub_16bit_with_8bit_payload, &test_cpu_math_sub_16bit_with_8bit_tester );
    create_test( "cpu_math_complement_const_16bit", &test_cpu_math_complement_const_16bit_payload, &test_cpu_math_complement_const_16bit_tester );
    create_test( "cpu_math_and_const_16bit", &test_cpu_math_and_const_16bit_payload, &test_cpu_math_and_const_16bit_tester );
    create_test( "cpu_move_32bit", &test_cpu_move_32bit_payload, &test_cpu_move_32bit_tester );
    create_test( "cpu_store_32bit", &test_cpu_store_32bit_payload, &test_cpu_store_32bit_tester );
    create_test( "cpu_compare_32bit", &test_cpu_compare_32bit_payload, &test_cpu_compare_32bit_tester );
    create_test( "cpu_math_add_32bit", &test_cpu_math_add_32bit_payload, &test_cpu_math_add_32bit_tester );
    create_test( "cpu_math_sub_32bit", &test_cpu_math_sub_32bit_payload, &test_cpu_math_sub_32bit_tester );
    create_test( "cpu_math_complement_const_32bit", &test_cpu_math_complement_const_32bit_payload, &test_cpu_math_complement_const_32bit_tester );
    create_test( "cpu_math_and_const_32bit", &test_cpu_math_and_const_32bit_payload, &test_cpu_math_and_const_32bit_tester );
    create_test( "cpu_combine_nibbles", &test_cpu_combine_nibbles_payload, &test_cpu_combine_nibbles_tester );
    create_test( "cpu_mem_move", &test_cpu_mem_move_payload, &test_cpu_mem_move_tester );
    create_test( "cpu_mem_move_size", &test_cpu_mem_move_size_payload, &test_cpu_mem_move_size_tester );
    create_test( "cpu_mem_move_direct", &test_cpu_mem_move_direct_payload, &test_cpu_mem_move_direct_tester );
    create_test( "cpu_mem_move_direct_size", &test_cpu_mem_move_direct_size_payload, &test_cpu_mem_move_direct_size_tester );
    create_test( "cpu_mem_move_direct_indirect_size", &test_cpu_mem_move_direct_indirect_size_payload, &test_cpu_mem_move_direct_indirect_size_tester );
    create_test( "cpu_compare_memory", &test_cpu_compare_memory_payload, &test_cpu_compare_memory_tester );
    create_test( "cpu_compare_memory_size", &test_cpu_compare_memory_size_payload, &test_cpu_compare_memory_size_tester );
    create_test( "cpu_less_than_memory", &test_cpu_less_than_memory_payload, &test_cpu_less_than_memory_tester );
    create_test( "cpu_less_than_memory_size", &test_cpu_less_than_memory_size_payload, &test_cpu_less_than_memory_size_tester );
    create_test( "cpu_greater_than_memory", &test_cpu_greater_than_memory_payload, &test_cpu_greater_than_memory_tester );
    create_test( "cpu_greater_than_memory_size", &test_cpu_greater_than_memory_size_payload, &test_cpu_greater_than_memory_size_tester );
    create_test( "cpu_move_8bit_indirect", &test_cpu_move_8bit_indirect_payload, &test_cpu_move_8bit_indirect_tester );
    create_test( "cpu_move_8bit_indirect_with_offset", &test_cpu_move_8bit_indirect_with_offset_payload, &test_cpu_move_8bit_indirect_with_offset_tester );
    create_test( "cpu_move_8bit_with_offset", &test_cpu_move_8bit_with_offset_payload, &test_cpu_move_8bit_with_offset_tester );
    create_test( "cpu_move_8bit_indirect_with_offset2", &test_cpu_move_8bit_indirect_with_offset2_payload, &test_cpu_move_8bit_indirect_with_offset2_tester );
    create_test( "cpu_move_8bit_with_offset2", &test_cpu_move_8bit_with_offset2_payload, &test_cpu_move_8bit_with_offset2_tester );
    create_test( "cpu_move_8bit_indirect2_payload", &test_cpu_move_8bit_indirect2_payload, &test_cpu_move_8bit_indirect2_tester );
    create_test( "cpu_move_16bit_indirect", &test_cpu_move_16bit_indirect_payload, &test_cpu_move_16bit_indirect_tester );
    create_test( "cpu_move_16bit_indirect2", &test_cpu_move_16bit_indirect2_payload, &test_cpu_move_16bit_indirect2_tester );
    create_test( "cpu_move_32bit_indirect", &test_cpu_move_32bit_indirect_payload, &test_cpu_move_32bit_indirect_tester );
    create_test( "cpu_move_32bit_indirect2", &test_cpu_move_32bit_indirect2_payload, &test_cpu_move_32bit_indirect2_tester );
    // // // // to be adapted on target charset create_test( "cpu_uppercase", &test_cpu_uppercase_payload, &test_cpu_uppercase_tester );
    // // // // to be adapted on target charset create_test( "cpu_lowercase", &test_cpu_lowercase_payload, &test_cpu_lowercase_tester );
    create_test( "cpu_convert_string_into_16bit", &test_cpu_convert_string_into_16bit_payload, &test_cpu_convert_string_into_16bit_tester );
    create_test( "cpu_flip", &test_cpu_flip_payload, &test_cpu_flip_tester );
    create_test( "cpu_bit_check", &test_cpu_bit_check_payload, &test_cpu_bit_check_tester );
    create_test( "cpu_bit_checkB", &test_cpu_bit_check_payloadB, &test_cpu_bit_check_testerB );
    create_test( "cpu_dsdefine", &test_cpu_dsdefine_payload, &test_cpu_dsdefine_tester );
    create_test( "cpu_dsalloc", &test_cpu_dsalloc_payload, &test_cpu_dsalloc_tester );
    create_test( "cpu_dsfree", &test_cpu_dsfree_payload, &test_cpu_dsfree_tester );
    create_test( "cpu_dswrite B", &test_cpu_dswrite_payloadB, &test_cpu_dswrite_testerB );
    create_test( "cpu_dswrite C", &test_cpu_dswrite_payloadC, &test_cpu_dswrite_testerC );
    create_test( "cpu_dsresize", &test_cpu_dsresize_payload, &test_cpu_dsresize_tester );
    create_test( "cpu_sqroot", &test_cpu_sqroot_payload, &test_cpu_sqroot_tester );

}
