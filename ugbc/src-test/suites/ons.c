/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

void test_ons_01_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * one = variable_define( e, "one", VT_WORD, 1 );
    Variable * prima = variable_define( e, "prima", VT_WORD, 0 );
    Variable * times = variable_define( e, "times", VT_WORD, 1 );
    cpu_label( e, "start" );
    on_goto( e, times->name );
    on_goto_index( e, "first" );
    on_goto_end( e );
    stop_test( e );

    cpu_label( e, "first");
    variable_move( e, one->name, prima->name );
    stop_test( e );

    _te->trackedVariables[0] = prima;

}

int test_ons_01_tester( TestEnvironment * _te ) {

    Variable * prima = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return prima->value == 1;

}

void test_ons( ) {

    create_test( "ons_01", &test_ons_01_payload, &test_ons_01_tester );    

}
