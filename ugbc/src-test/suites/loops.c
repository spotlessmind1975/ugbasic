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

void test_for_step_minus_one_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * index = variable_define( e, "index", VT_SWORD, 0 );
    Variable * hundred = variable_define( e, "hundred", VT_SWORD, 100 );
    Variable * zero = variable_define( e, "zero", VT_SWORD, 0 );
    Variable * minusOne = variable_define( e, "minusone", VT_SWORD, -1 );

    begin_for_step( e, index->name, hundred->name, zero->name, minusOne->name );
    end_for( e );
    
    _te->trackedVariables[0] = index;
    _te->trackedVariables[1] = minusOne;

}

int test_for_step_minus_one_tester( TestEnvironment * _te ) {

    Variable * index = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * minusOne = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    return index->value == -1 && minusOne->value == -1;

}

void test_loops( ) {

    create_test( "for_step_minus_one", &test_for_step_minus_one_payload, &test_for_step_minus_one_tester );    

}
