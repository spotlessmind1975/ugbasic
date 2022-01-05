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

void test_print_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * s = variable_define( e, "t", VT_STRING, 0 );

    variable_store_string( e, s->name, "TEST" );

    print( e, s->name, 1 );

}

int test_print_tester( TestEnvironment * _te ) {

    return 1;

}

//==========================================================================

void test_print2_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * d = variable_define( e, "t", VT_DSTRING, 0 );

    variable_store_string( e, d->name, "test" );
    
    cpu_dswrite( e, d->realName );

    print( e, d->name, 1 );

    _te->trackedVariables[0] = d;

}

int test_print2_tester( TestEnvironment * _te ) {

    Variable * d = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return strcasecmp( d->valueString, "TEST" ) == 0;

}

void test_print( ) {

   create_test( "print", &test_print_payload, &test_print_tester );    
   create_test( "print2", &test_print2_payload, &test_print2_tester );    

}
