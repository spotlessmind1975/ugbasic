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

#ifdef __zx__

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

void test_zx_text_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * texts = variable_define( e, "texts", VT_STRING, 0 );
    Variable * textd = variable_define( e, "textd", VT_DSTRING, 0 );

    Variable * pen = variable_define( e, "pen", VT_BYTE, 0 );
    Variable * paper = variable_define( e, "paper", VT_BYTE, 0 );
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

    zx_text( e, address->realName, size->realName, pen->realName );

    cpu_dsdescriptor( e, textd->realName, address2->realName, size2->realName );

    zx_text( e, address2->realName, size2->realName, pen->realName );

}

int test_zx_text_tester( TestEnvironment * _te ) {

    return 1;

}

//============================================================================

void test_zx_bitmap_enable_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    // a) Standard Bitmap Mode
    zx_bitmap_enable( e, 0, 0, 0 );

    // b) Standard Bitmap Mode
    zx_bitmap_enable( e, 320, 0, 0 );

    // c) Standard Bitmap Mode
    zx_bitmap_enable( e, 160, 0, 0 );

    // d) Standard Bitmap Mode
    zx_bitmap_enable( e, 0, 200, 0 );
    
    // e) Standard Bitmap Mode
    zx_bitmap_enable( e, 0, 0, 2 );

    // f) Standard Bitmap Mode
    zx_bitmap_enable( e, 0, 0, 4 );

    // g) Standard Bitmap Mode
    zx_bitmap_enable( e, 0, 0, 8 );

    // h)  Standard Bitmap Mode
    zx_bitmap_enable( e, 0, 0, 16 );
    
}

int test_zx_bitmap_enable_tester( TestEnvironment * _te ) {

    return 1;

}

//============================================================================

void test_zx_tilemap_enable_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    // a) (Emulated) Standard Character Mode
    zx_tilemap_enable( e, 0, 0, 0 );

    // b) (Emulated) Standard Character Mode
    zx_tilemap_enable( e, 80, 0, 0 );

    // c) (Emulated) Standard Character Mode
    zx_tilemap_enable( e, 30, 0, 0 );

    // d) (Emulated) Standard Character Mode
    zx_tilemap_enable( e, 0, 30, 0 );
    
    // e) (Emulated) Standard Character Mode
    zx_tilemap_enable( e, 0, 0, 8 );

    // f) (Emulated) Standard Character Mode
    zx_tilemap_enable( e, 0, 0, 16 );

    // g) (Emulated) Standard Character Mode
    zx_tilemap_enable( e, 0, 0, 20 );

    // h) (Emulated) Standard Character Mode
    zx_tilemap_enable( e, 0, 0, 16 );
    
}

int test_zx_tilemap_enable_tester( TestEnvironment * _te ) {

    return 1;

}

//============================================================================

void test_zx_cls_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * red = variable_define( e, "red", VT_COLOR, COLOR_RED );
    Variable * yellow = variable_define( e, "yellow", VT_COLOR, COLOR_YELLOW );

    _te->debug.inspections[0].name="BITMAP";
    _te->debug.inspections[0].address=0x4000;
    _te->debug.inspections[0].size=6144;
    ++_te->debug.inspections_count;

    _te->debug.inspections[1].name="COLORMAP";
    _te->debug.inspections[1].address=0x5800;
    _te->debug.inspections[1].size=768;
    ++_te->debug.inspections_count;

    // a) Standard Character Mode
    zx_bitmap_enable( e, 0, 0, 0 );
    paper( e, red->name );
    pen( e, yellow->name );
    zx_cls( e, yellow->realName, red->realName );
    
    _te->trackedVariables[0] = red;
    _te->trackedVariables[1] = yellow;

}

int test_zx_cls_tester( TestEnvironment * _te ) {

    Variable * red = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * yellow = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    int i=0, j=0; 

    for( i=0; i<_te->debug.inspections[0].size; ++i ) {
        if ( _te->debug.inspections[0].memory[i] != 0 ) {
            printf( "Failed text at %d\n",i);
            return 0;
        }
    }

    for( i=0; i<_te->debug.inspections[1].size; ++i ) {
        if ( _te->debug.inspections[1].memory[i] != ( ( red->value << 3 ) | ( yellow->value ) ) ) {
            printf( "Failed color at %d\n",i);
            return 0;
        }
    }

    return 1;

}

//============================================================================

void test_zx_cls2_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * red = variable_define( e, "red", VT_COLOR, COLOR_RED );
    Variable * yellow = variable_define( e, "yellow", VT_COLOR, COLOR_YELLOW );

    _te->debug.inspections[0].name="BITMAP";
    _te->debug.inspections[0].address=0x4000;
    _te->debug.inspections[0].size=6144;
    ++_te->debug.inspections_count;

    _te->debug.inspections[1].name="COLORMAP";
    _te->debug.inspections[1].address=0x5800;
    _te->debug.inspections[1].size=768;
    ++_te->debug.inspections_count;

    // a) Standard Character Mode
    zx_tilemap_enable( e, 0, 0, 0 );
    paper( e, red->name );
    pen( e, yellow->name );
    zx_cls( e, yellow->realName, red->realName );
    
    _te->trackedVariables[0] = red;
    _te->trackedVariables[1] = yellow;

}

int test_zx_cls2_tester( TestEnvironment * _te ) {

    Variable * red = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * yellow = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    int i=0, j=0; 

    for( i=0; i<_te->debug.inspections[0].size; ++i ) {
        if ( _te->debug.inspections[0].memory[i] != 0 ) {
            printf( "Failed clearing text\n");
            return 0;
        }
    }

    for( i=0; i<_te->debug.inspections[1].size; ++i ) {
        if ( _te->debug.inspections[1].memory[i] != ( ( red->value << 3 ) | ( yellow->value ) ) ) {
            printf( "Failed clearing background\n");
            return 0;
        }
    }

    return 1;

}

//============================================================================

void test_zx_cls3_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * emptyTile = variable_retrieve( e, "EMPTYTILE" );
    Variable * red = variable_define( e, "red", VT_COLOR, COLOR_RED );
    Variable * yellow = variable_define( e, "yellow", VT_COLOR, COLOR_YELLOW );

    _te->debug.inspections[0].name="BITMAP";
    _te->debug.inspections[0].address=0x4000;
    _te->debug.inspections[0].size=6144;
    ++_te->debug.inspections_count;

    _te->debug.inspections[1].name="COLORMAP";
    _te->debug.inspections[1].address=0x5800;
    _te->debug.inspections[1].size=768;
    ++_te->debug.inspections_count;

    // a) Standard Character Mode
    cpu_store_8bit( e, emptyTile->realName, 42 );
    zx_tilemap_enable( e, 0, 0, 0 );
    paper( e, red->name );
    pen( e, yellow->name );
    zx_cls( e, yellow->realName, red->realName );
    
    _te->trackedVariables[0] = emptyTile;
    _te->trackedVariables[1] = red;
    _te->trackedVariables[2] = yellow;

}

int test_zx_cls3_tester( TestEnvironment * _te ) {

    int i=0, j=0; 

    Variable * emptyTile = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * red = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * yellow = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );

    // for( i=0; i<_te->debug.inspections[0].size; ++i ) {
    //     if ( _te->debug.inspections[0].memory[i] != emptyTile->value ) {
    //         printf( "Failed clearing text at %4.4x\n", i);
    //         return 0;
    //     }
    // }

    for( i=0; i<_te->debug.inspections[1].size; ++i ) {
        if ( _te->debug.inspections[1].memory[i] != ( ( red->value << 3 ) | ( yellow->value ) ) ) {
            printf( "Failed clearing background\n");
            return 0;
        }
    }

    return 1;

}

void test_zx( ) {

    create_test( "zx_text", &test_zx_text_payload, &test_zx_text_tester );    
    create_test( "zx_bitmap_enabled", &test_zx_bitmap_enable_payload, &test_zx_bitmap_enable_tester );    
    create_test( "zx_tilemap_enabled", &test_zx_bitmap_enable_payload, &test_zx_bitmap_enable_tester );    
    create_test( "zx_cls", &test_zx_cls_payload, &test_zx_cls_tester );
    create_test( "zx_cls2", &test_zx_cls2_payload, &test_zx_cls2_tester );
    create_test( "zx_cls3", &test_zx_cls3_payload, &test_zx_cls3_tester );

}

#endif