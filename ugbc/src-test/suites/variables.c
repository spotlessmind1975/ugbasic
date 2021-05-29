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

void test_variables( ) {

    create_test( "variables_add01", &test_variables_add01_payload, &test_variables_add01_tester );    

}
