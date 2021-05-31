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

#ifdef __c64__

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

void test_vic2_text_at_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * texts = variable_define( e, "texts", VT_STRING, 0 );
    Variable * textd = variable_define( e, "textd", VT_DSTRING, 0 );

    Variable * x = variable_define( e, "x", VT_WORD, 0 );
    Variable * y = variable_define( e, "y", VT_WORD, 0 );
    Variable * pen = variable_define( e, "pen", VT_BYTE, 0 );
    Variable * ww = variable_define( e, "ww", VT_BYTE, 0 );
    Variable * address = variable_temporary( e, VT_ADDRESS, "(text address)" );
    Variable * size = variable_temporary( e, VT_BYTE, "(text size)" );
    Variable * address2 = variable_temporary( e, VT_ADDRESS, "(text address)" );
    Variable * size2 = variable_temporary( e, VT_BYTE, "(text size)" );

    variable_store_string( e, texts->name, "TEST1" );
    variable_store_string( e, textd->name, "TEST2" );

    cpu_move_8bit( e, texts->realName, size->realName );
    cpu_addressof_16bit( e, texts->realName, address->realName );
    cpu_inc_16bit( e, address->realName );

    vic2_text_at( e, x->realName, y->realName, address->realName, size->realName, pen->realName, ww->realName );

    cpu_dsdescriptor( e, textd->realName, address2->realName, size2->realName );

    vic2_text_at( e, x->realName, y->realName, address2->realName, size2->realName, pen->realName, ww->realName );

}

int test_vic2_text_at_tester( TestEnvironment * _te ) {

    return 1;

}

void test_vic2( ) {

   create_test( "vic2_text_at", &test_vic2_text_at_payload, &test_vic2_text_at_tester );    

}

#endif