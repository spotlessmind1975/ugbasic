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

void test_control_by_expression_01_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * prima = variable_define( e, "prima", VT_WORD, 0 );
    Variable * seconda = variable_define( e, "seconda", VT_WORD, 0 );
    Variable * terza = variable_define( e, "terza", VT_WORD, 0 );
    Variable * one = variable_define( e, "one", VT_WORD, 1 );
    Variable * three = variable_define( e, "three", VT_WORD, 3 );

    Variable * times = variable_define( e, "times", VT_WORD, 1 );
    cpu_label( e, "start" );
    on_goto( e, times->name );
    on_goto_index( e, "first" );
    on_goto_index( e, "second" );
    on_goto_index( e, "third" );
    on_goto_end( e );
    cpu_label( e, "nextLoop" );
    variable_store( e, one->name, 1 );    
    variable_move( e, variable_add( e, times->name, one->name )->name, times->name );
    variable_store( e, three->name, 3 );    
    if_then( e, variable_greater_than( e, times->name, three->name, 0 )->name );
        variable_move( e, one->name, times->name );    
        stop_test( e );
    end_if_then( e );
    cpu_jump( e, "start" );

    cpu_label( e, "first");
    variable_move( e, one->name, prima->name );
    cpu_jump( e, "nextLoop" );
     
    cpu_label( e, "second");
    variable_move( e, one->name, seconda->name );
    cpu_jump( e, "nextLoop" );
     
    cpu_label( e, "third");
    variable_move( e, one->name, terza->name );
    cpu_jump( e, "nextLoop" );

    _te->trackedVariables[0] = prima;
    _te->trackedVariables[1] = seconda;
    _te->trackedVariables[2] = terza;

}

int test_control_by_expression_01_tester( TestEnvironment * _te ) {

    Variable * prima = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * seconda = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * terza = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );

    return prima->value == 1 && seconda->value == 1 && terza->value == 1;

}

//===========================================================================

void test_controls_joy_01_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * j = variable_define( e, "j", VT_BYTE, 0 );
    Variable * one = variable_define( e, "one", VT_WORD, 1 );
    Variable * limit = variable_define( e, "limit", VT_WORD, 1000 );
    Variable * five = variable_define( e, "five", VT_WORD, 5 );
    Variable * times = variable_define( e, "times", VT_WORD, 0 );

    begin_loop( e );
        variable_move( e, joy( e, one->name )->name, j->name );
        print( e, variable_bin( e, j->name, five->name )->name, 0 );
        print_tab( e, 0 );
        print( e, j->name, 1 );
        variable_move( e, variable_add( e, times->name, one->name )->name, times->name );
        if_then( e, variable_compare( e, times->name, limit->name )->name );
            stop_test( e );
        end_if_then( e );
    end_loop( e );

    _te->trackedVariables[0] = j;
    _te->trackedVariables[1] = times;
    _te->trackedVariables[2] = limit;

}

int test_controls_joy_01_tester( TestEnvironment * _te ) {

    Variable * j = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * times = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * limit = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );

    return (  j->value == 0xff || j->value == 0x1f  || j->value == 0x00 ) && times->value == limit->value;
    
}

//===========================================================================

void test_controls_keyboard_01_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * k = variable_define( e, "k", VT_DSTRING, 0 );
    Variable * q = variable_define( e, "q", VT_DSTRING, 0 );
    Variable * s = variable_define( e, "s", VT_STRING, 0 );
    Variable * empty = variable_define( e, "empty", VT_STRING, 0 );
    Variable * limit = variable_define( e, "limit", VT_WORD, 100 );
    Variable * times = variable_define( e, "times", VT_WORD, 0 );
    Variable * one = variable_define( e, "one", VT_WORD, 1 );

    variable_store_string( e, s->name, "YOU PRESSED A KEY!" );
    variable_store_string( e, empty->name, "" );
    variable_store_string( e, q->name, "q" );

    begin_loop( e );
        variable_move( e, inkey( e )->name, k->name );
        if_then( e, variable_compare_not( e, k->name, empty->name )->name );
            print( e, s->name, 1 );
        end_if_then( e );
        variable_move( e, variable_add( e, times->name, one->name )->name, times->name );
        if_then( e, variable_compare( e, times->name, limit->name )->name );
            stop_test( e );
        end_if_then( e );
    end_loop( e );

    _te->trackedVariables[0] = k;

}

int test_controls_keyboard_01_tester( TestEnvironment * _te ) {

    Variable * k = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return strcmp( k->valueString, "" ) == 0;
    
}

//===========================================================================

void test_rnd_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * max1 = variable_define( e, "max1", VT_POSITION, 256 );
    Variable * max2 = variable_define( e, "max2", VT_POSITION, 255 );

    Variable * r1 = rnd( e, max1->name );
    Variable * r2 = rnd( e, max2->name );

    _te->trackedVariables[0] = r1;
    _te->trackedVariables[1] = r2;

}

int test_rnd_tester( TestEnvironment * _te ) {

    Variable * r1 = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * r2 = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return r1->value != 0 && r2->value != 0;
    
}

void test_examples( ) {

    create_test( "control_by_expression_01", &test_control_by_expression_01_payload, &test_control_by_expression_01_tester );    
    create_test( "controls_joy_01", &test_controls_joy_01_payload, &test_controls_joy_01_tester );    
    create_test( "controls_keyboard_01", &test_controls_keyboard_01_payload, &test_controls_keyboard_01_tester );    
    create_test( "rnd", &test_rnd_payload, &test_rnd_tester );    

}
