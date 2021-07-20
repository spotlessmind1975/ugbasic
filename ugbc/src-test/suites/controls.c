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

void test_controls_joy_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * j = variable_define( e, "j", VT_BYTE, 0 );
    Variable * one = variable_define( e, "one", VT_WORD, 1 );
    variable_move( e, joy( e, one->name )->name, j->name );

    _te->trackedVariables[0] = j;

}

int test_controls_joy_tester( TestEnvironment * _te ) {

    Variable * j = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return j->value == 0x1f || j->value == 0xff || j->value == 0x00;
    
}

void test_controls( ) {

    create_test( "controls_joy", &test_controls_joy_payload, &test_controls_joy_tester );    

}
