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

void test_cpu( ) {

    create_test( "cpu_bits_to_string", &test_cpu_bits_to_string_payload, &test_cpu_bits_to_string_tester );    
    create_test( "cpu_dswrite", &test_cpu_dswrite_payload, &test_cpu_dswrite_tester );    

}
