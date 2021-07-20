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

    return strcmp( string->valueString, "00000000000000000000000000000010" ) == 0 ||
            strcmp( string->valueString, "00000010" ) == 0;

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

    cpu_bit_check_extended( e, value->realName, pos0->realName, result0->realName );
    cpu_bit_check_extended( e, value->realName, pos1->realName, result1->realName );
    cpu_bit_check_extended( e, value->realName, pos2->realName, result2->realName );
    cpu_bit_check_extended( e, value->realName, pos3->realName, result3->realName );
    cpu_bit_check_extended( e, value->realName, pos4->realName, result4->realName );
    cpu_bit_check_extended( e, value->realName, pos5->realName, result5->realName );
    cpu_bit_check_extended( e, value->realName, pos6->realName, result6->realName );
    cpu_bit_check_extended( e, value->realName, pos7->realName, result7->realName );
    
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

    cpu_less_than_16bit( e, ua->realName, ub->realName, resultu1->realName, 0, 0 );
    cpu_less_than_16bit( e, ub->realName, ua->realName, resultu2->realName, 0, 0 );
    cpu_less_than_16bit( e, sa->realName, sb->realName, results1->realName, 0, 1 );
    cpu_less_than_16bit( e, sb->realName, sa->realName, results2->realName, 0, 1 );

    _te->trackedVariables[0] = resultu1;
    _te->trackedVariables[1] = resultu2;
    _te->trackedVariables[2] = results1;
    _te->trackedVariables[3] = results2;

}

int test_cpu_less_than_16bit_tester( TestEnvironment * _te ) {

    Variable * resultu1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * resultu2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * results1 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * results2 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    return  resultu1->value == 0xff && 
            resultu2->value == 0x00 &&
            results1->value == 0x00 && 
            results2->value == 0xff;

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

    cpu_less_than_16bit( e, ua->realName, ub->realName, resultu1->realName, 0, 0 );
    cpu_less_than_16bit( e, ub->realName, ua->realName, resultu2->realName, 0, 0 );
    cpu_less_than_16bit( e, sa->realName, sb->realName, results1->realName, 0, 1 );
    cpu_less_than_16bit( e, sb->realName, sa->realName, results2->realName, 0, 1 );

    _te->trackedVariables[0] = resultu1;
    _te->trackedVariables[1] = resultu2;
    _te->trackedVariables[2] = results1;
    _te->trackedVariables[3] = results2;

}

int test_cpu_less_than_16bit_testerB( TestEnvironment * _te ) {

    Variable * resultu1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * resultu2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * results1 = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * results2 = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );

    return  resultu1->value == 0xff && 
            resultu2->value == 0x00 &&
            results1->value == 0x00 && 
            results2->value == 0xff;

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

    return  resultu->value == 160 &&
            remainderu->value == 0 && 
            results->value == 160 && 
            remainders->value == 0;

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
        cpu_bit_check_extended( e, value->realName, position[i]->realName, result[i]->realName );
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



void test_cpu( ) {

    create_test( "cpu_bits_to_string", &test_cpu_bits_to_string_payload, &test_cpu_bits_to_string_tester );    
    create_test( "cpu_bits_to_string32", &test_cpu_bits_to_string32_payload, &test_cpu_bits_to_string32_tester );    
    create_test( "cpu_dswrite", &test_cpu_dswrite_payload, &test_cpu_dswrite_tester );    
    create_test( "cpu_dsgc A", &test_cpu_dsgc_payloadA, &test_cpu_dsgc_testerA );    
    create_test( "cpu_dsgc B", &test_cpu_dsgc_payloadB, &test_cpu_dsgc_testerB );    
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
    create_test( "cpu_math_mul2_const_16bit", &test_cpu_math_mul2_const_16bit_payload, &test_cpu_math_mul2_const_16bit_tester );
    create_test( "cpu_math_mul2_const_32bit", &test_cpu_math_mul2_const_32bit_payload, &test_cpu_math_mul2_const_32bit_tester );
    create_test( "cpu_math_mul2_const_8bit", &test_cpu_math_mul2_const_8bit_payload, &test_cpu_math_mul2_const_8bit_tester );

}
