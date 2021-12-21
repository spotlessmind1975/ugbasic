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

void test_vic2_text_payloadA( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * texts = variable_define( e, "texts", VT_STRING, 0 );
    Variable * textd = variable_define( e, "textd", VT_DSTRING, 0 );

    Variable * pen = variable_define( e, "pen", VT_BYTE, 0 );
    Variable * address = variable_temporary( e, VT_ADDRESS, "(text address)" );
    Variable * size = variable_temporary( e, VT_BYTE, "(text size)" );
    Variable * address2 = variable_temporary( e, VT_ADDRESS, "(text address)" );
    Variable * size2 = variable_temporary( e, VT_BYTE, "(text size)" );

    variable_store_string( e, texts->name, "TEST1" );
    variable_store_string( e, textd->name, "TEST2" );

    cpu_move_8bit( e, texts->realName, size->realName );
    cpu_addressof_16bit( e, texts->realName, address->realName );
    cpu_inc_16bit( e, address->realName );

    vic2_text( e, address->realName, size->realName );

    cpu_dsdescriptor( e, textd->realName, address2->realName, size2->realName );

    vic2_text( e, address2->realName, size2->realName );

}

int test_vic2_text_testerA( TestEnvironment * _te ) {

    return 1;

}

//============================================================================

void test_vic2_bitmap_enable_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * d011a = variable_define( e, "d011a", VT_BYTE, 0 );
    Variable * d016a = variable_define( e, "d016a", VT_BYTE, 0 );
    Variable * d011b = variable_define( e, "d011b", VT_BYTE, 0 );
    Variable * d016b = variable_define( e, "d016b", VT_BYTE, 0 );
    Variable * d011c = variable_define( e, "d011c", VT_BYTE, 0 );
    Variable * d016c = variable_define( e, "d016c", VT_BYTE, 0 );
    Variable * d011d = variable_define( e, "d011d", VT_BYTE, 0 );
    Variable * d016d = variable_define( e, "d016d", VT_BYTE, 0 );
    Variable * d011e = variable_define( e, "d011e", VT_BYTE, 0 );
    Variable * d016e = variable_define( e, "d016e", VT_BYTE, 0 );
    Variable * d011f = variable_define( e, "d011f", VT_BYTE, 0 );
    Variable * d016f = variable_define( e, "d016f", VT_BYTE, 0 );
    Variable * d011g = variable_define( e, "d011g", VT_BYTE, 0 );
    Variable * d016g = variable_define( e, "d016g", VT_BYTE, 0 );
    Variable * d011h = variable_define( e, "d011h", VT_BYTE, 0 );
    Variable * d016h = variable_define( e, "d016h", VT_BYTE, 0 );

    // a) Standard Bitmap Mode
    vic2_bitmap_enable( e, 0, 0, 0 );
    cpu_move_8bit( e, "$D011", d011a->realName );
    cpu_move_8bit( e, "$D016", d016a->realName );

    // b) Standard Bitmap Mode
    vic2_bitmap_enable( e, 320, 0, 0 );
    cpu_move_8bit( e, "$D011", d011b->realName );
    cpu_move_8bit( e, "$D016", d016b->realName );

    // c) Multicolor Character Mode
    vic2_bitmap_enable( e, 160, 0, 0 );
    cpu_move_8bit( e, "$D011", d011c->realName );
    cpu_move_8bit( e, "$D016", d016c->realName );

    // d) Standard Bitmap Mode
    vic2_bitmap_enable( e, 0, 200, 0 );
    cpu_move_8bit( e, "$D011", d011d->realName );
    cpu_move_8bit( e, "$D016", d016d->realName );
    
    // e) Standard Bitmap Mode
    vic2_bitmap_enable( e, 0, 0, 2 );
    cpu_move_8bit( e, "$D011", d011e->realName );
    cpu_move_8bit( e, "$D016", d016e->realName );

    // f) Multicolor Bitmap Mode
    vic2_bitmap_enable( e, 0, 0, 4 );
    cpu_move_8bit( e, "$D011", d011f->realName );
    cpu_move_8bit( e, "$D016", d016f->realName );

    // g) Multicolor Bitmap Mode
    vic2_bitmap_enable( e, 0, 0, 8 );
    cpu_move_8bit( e, "$D011", d011g->realName );
    cpu_move_8bit( e, "$D016", d016g->realName );

    // h) Multicolor Bitmap Mode
    vic2_bitmap_enable( e, 0, 0, 16 );
    cpu_move_8bit( e, "$D011", d011h->realName );
    cpu_move_8bit( e, "$D016", d016h->realName );
    
    _te->trackedVariables[0] = d011a;
    _te->trackedVariables[1] = d016a;
    _te->trackedVariables[2] = d011b;
    _te->trackedVariables[3] = d016b;
    _te->trackedVariables[4] = d011c;
    _te->trackedVariables[5] = d016c;
    _te->trackedVariables[6] = d011d;
    _te->trackedVariables[7] = d016d;
    _te->trackedVariables[8] = d011e;
    _te->trackedVariables[9] = d016e;
    _te->trackedVariables[10] = d011f;
    _te->trackedVariables[11] = d016f;
    _te->trackedVariables[12] = d011g;
    _te->trackedVariables[13] = d016g;
    _te->trackedVariables[14] = d011h;
    _te->trackedVariables[15] = d016h;


}

#define ecm(a,b) ( ( a & 0x40 ) == 0x40 )
#define bmm(a,b) ( ( a & 0x20 ) == 0x20 )
#define mcm(a,b) ( ( b & 0x10 ) == 0x10 )
#define standard_character_mode( a, b )     ( ( !ecm(a,b) ) && ( !bmm(a,b) ) && ( !mcm(a,b) ) )
#define multicolor_character_mode( a, b )   ( ( !ecm(a,b) ) && ( !bmm(a,b) ) && ( mcm(a,b) ) )
#define standard_bitmap_mode( a, b )        ( ( !ecm(a,b) ) && ( bmm(a,b) ) && ( !mcm(a,b) ) )
#define multicolor_bitmap_mode( a, b )      ( ( !ecm(a,b) ) && ( bmm(a,b) ) && ( mcm(a,b) ) )
#define extended_character_mode( a, b )    ( ( !ecm(a,b) ) && ( !bmm(a,b) ) && ( mcm(a,b) ) )

int test_vic2_bitmap_enable_tester( TestEnvironment * _te ) {

    Variable * d011a = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * d016a = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * d011b = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * d016b = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * d011c = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );
    Variable * d016c = variable_retrieve( &_te->environment, _te->trackedVariables[5]->name );
    Variable * d011d = variable_retrieve( &_te->environment, _te->trackedVariables[6]->name );
    Variable * d016d = variable_retrieve( &_te->environment, _te->trackedVariables[7]->name );
    Variable * d011e = variable_retrieve( &_te->environment, _te->trackedVariables[8]->name );
    Variable * d016e = variable_retrieve( &_te->environment, _te->trackedVariables[9]->name );
    Variable * d011f = variable_retrieve( &_te->environment, _te->trackedVariables[10]->name );
    Variable * d016f = variable_retrieve( &_te->environment, _te->trackedVariables[11]->name );
    Variable * d011g = variable_retrieve( &_te->environment, _te->trackedVariables[12]->name );
    Variable * d016g = variable_retrieve( &_te->environment, _te->trackedVariables[13]->name );
    Variable * d011h = variable_retrieve( &_te->environment, _te->trackedVariables[14]->name );
    Variable * d016h = variable_retrieve( &_te->environment, _te->trackedVariables[15]->name );

    return standard_bitmap_mode( d011a->value, d016a->value ) &&
            standard_bitmap_mode( d011b->value, d016b->value ) &&
            multicolor_bitmap_mode( d011c->value, d016c->value ) &&
            standard_bitmap_mode( d011d->value, d016d->value ) &&
            standard_bitmap_mode( d011e->value, d016e->value ) &&
            multicolor_bitmap_mode( d011f->value, d016f->value ) &&
            multicolor_bitmap_mode( d011g->value, d016g->value ) &&
            multicolor_bitmap_mode( d011h->value, d016h->value );

}

//============================================================================

void test_vic2_tilemap_enable_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * d011a = variable_define( e, "d011a", VT_BYTE, 0 );
    Variable * d016a = variable_define( e, "d016a", VT_BYTE, 0 );
    Variable * d011b = variable_define( e, "d011b", VT_BYTE, 0 );
    Variable * d016b = variable_define( e, "d016b", VT_BYTE, 0 );
    Variable * d011c = variable_define( e, "d011c", VT_BYTE, 0 );
    Variable * d016c = variable_define( e, "d016c", VT_BYTE, 0 );
    Variable * d011d = variable_define( e, "d011d", VT_BYTE, 0 );
    Variable * d016d = variable_define( e, "d016d", VT_BYTE, 0 );
    Variable * d011e = variable_define( e, "d011e", VT_BYTE, 0 );
    Variable * d016e = variable_define( e, "d016e", VT_BYTE, 0 );
    Variable * d011f = variable_define( e, "d011f", VT_BYTE, 0 );
    Variable * d016f = variable_define( e, "d016f", VT_BYTE, 0 );
    Variable * d011g = variable_define( e, "d011g", VT_BYTE, 0 );
    Variable * d016g = variable_define( e, "d016g", VT_BYTE, 0 );
    Variable * d011h = variable_define( e, "d011h", VT_BYTE, 0 );
    Variable * d016h = variable_define( e, "d016h", VT_BYTE, 0 );

    // a) Standard Character Mode
    vic2_tilemap_enable( e, 0, 0, 0 );
    cpu_move_8bit( e, "$D011", d011a->realName );
    cpu_move_8bit( e, "$D016", d016a->realName );

    // b) Standard Character Mode
    vic2_tilemap_enable( e, 80, 0, 0 );
    cpu_move_8bit( e, "$D011", d011b->realName );
    cpu_move_8bit( e, "$D016", d016b->realName );

    // c) Standard Character Mode
    vic2_tilemap_enable( e, 30, 0, 0 );
    cpu_move_8bit( e, "$D011", d011c->realName );
    cpu_move_8bit( e, "$D016", d016c->realName );

    // d) Standard Character Mode
    vic2_tilemap_enable( e, 0, 30, 0 );
    cpu_move_8bit( e, "$D011", d011d->realName );
    cpu_move_8bit( e, "$D016", d016d->realName );
    
    // e) Multicolor Character Mode
    vic2_tilemap_enable( e, 0, 0, 8 );
    cpu_move_8bit( e, "$D011", d011e->realName );
    cpu_move_8bit( e, "$D016", d016e->realName );

    // f) Multicolor Character Mode
    vic2_tilemap_enable( e, 0, 0, 16 );
    cpu_move_8bit( e, "$D011", d011f->realName );
    cpu_move_8bit( e, "$D016", d016f->realName );

    // g) Extended Multicolor Character Mode
    vic2_tilemap_enable( e, 0, 0, 20 );
    cpu_move_8bit( e, "$D011", d011g->realName );
    cpu_move_8bit( e, "$D016", d016g->realName );

    // h) Multicolor Character Mode
    vic2_tilemap_enable( e, 0, 0, 16 );
    cpu_move_8bit( e, "$D011", d011h->realName );
    cpu_move_8bit( e, "$D016", d016h->realName );
    
    _te->trackedVariables[0] = d011a;
    _te->trackedVariables[1] = d016a;
    _te->trackedVariables[2] = d011b;
    _te->trackedVariables[3] = d016b;
    _te->trackedVariables[4] = d011c;
    _te->trackedVariables[5] = d016c;
    _te->trackedVariables[6] = d011d;
    _te->trackedVariables[7] = d016d;
    _te->trackedVariables[8] = d011e;
    _te->trackedVariables[9] = d016e;
    _te->trackedVariables[10] = d011f;
    _te->trackedVariables[11] = d016f;
    _te->trackedVariables[12] = d011g;
    _te->trackedVariables[13] = d016g;
    _te->trackedVariables[14] = d011h;
    _te->trackedVariables[15] = d016h;


}

int test_vic2_tilemap_enable_tester( TestEnvironment * _te ) {

    Variable * d011a = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * d016a = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * d011b = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );
    Variable * d016b = variable_retrieve( &_te->environment, _te->trackedVariables[3]->name );
    Variable * d011c = variable_retrieve( &_te->environment, _te->trackedVariables[4]->name );
    Variable * d016c = variable_retrieve( &_te->environment, _te->trackedVariables[5]->name );
    Variable * d011d = variable_retrieve( &_te->environment, _te->trackedVariables[6]->name );
    Variable * d016d = variable_retrieve( &_te->environment, _te->trackedVariables[7]->name );
    Variable * d011e = variable_retrieve( &_te->environment, _te->trackedVariables[8]->name );
    Variable * d016e = variable_retrieve( &_te->environment, _te->trackedVariables[9]->name );
    Variable * d011f = variable_retrieve( &_te->environment, _te->trackedVariables[10]->name );
    Variable * d016f = variable_retrieve( &_te->environment, _te->trackedVariables[11]->name );
    Variable * d011g = variable_retrieve( &_te->environment, _te->trackedVariables[12]->name );
    Variable * d016g = variable_retrieve( &_te->environment, _te->trackedVariables[13]->name );
    Variable * d011h = variable_retrieve( &_te->environment, _te->trackedVariables[14]->name );
    Variable * d016h = variable_retrieve( &_te->environment, _te->trackedVariables[15]->name );

    return standard_character_mode( d011a->value, d016a->value ) &&
            standard_character_mode( d011b->value, d016b->value ) &&
            standard_character_mode( d011c->value, d016c->value ) &&
            standard_character_mode( d011d->value, d016d->value ) &&
            multicolor_character_mode( d011e->value, d016e->value ) &&
            multicolor_character_mode( d011f->value, d016f->value ) &&
            extended_character_mode( d011g->value, d016g->value ) &&
            multicolor_character_mode( d011h->value, d016h->value );

}

//============================================================================

void test_vic2_cls_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * red = variable_define( e, "red", VT_COLOR, COLOR_RED );
    Variable * yellow = variable_define( e, "yellow", VT_COLOR, COLOR_YELLOW );

    _te->debug.inspections[0].name="BITMAP";
    _te->debug.inspections[0].address=0xA000;
    _te->debug.inspections[0].size=8000;
    ++_te->debug.inspections_count;

    _te->debug.inspections[1].name="COLORMAP";
    _te->debug.inspections[1].address=0x8400;
    _te->debug.inspections[1].size=1000;
    ++_te->debug.inspections_count;

    // a) Standard Character Mode
    vic2_bitmap_enable( e, 0, 0, 0 );
    paper( e, red->name );
    pen( e, yellow->name );
    vic2_cls( e );
    
    _te->trackedVariables[0] = red;
    _te->trackedVariables[1] = yellow;

}

int test_vic2_cls_tester( TestEnvironment * _te ) {

    Variable * red = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * yellow = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    int i=0, j=0; 

    for( i=0; i<_te->debug.inspections[0].size; ++i ) {
        if ( _te->debug.inspections[0].memory[i] != 0 ) {
            return 0;
        }
    }

    for( i=0; i<_te->debug.inspections[1].size; ++i ) {
        if ( _te->debug.inspections[1].memory[i] != ( red->value | ( yellow->value << 4 ) ) ) {
            return 0;
        }
    }

    return 1;

}

//============================================================================

void test_vic2_cls2_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * red = variable_define( e, "red", VT_COLOR, COLOR_RED );
    Variable * yellow = variable_define( e, "yellow", VT_COLOR, COLOR_YELLOW );

    _te->debug.inspections[0].name="TEXTAREA";
    _te->debug.inspections[0].address=0x8400;
    _te->debug.inspections[0].size=1000;
    ++_te->debug.inspections_count;

    _te->debug.inspections[1].name="COLORMAP";
    _te->debug.inspections[1].address=0xD800;
    _te->debug.inspections[1].size=1000;
    ++_te->debug.inspections_count;

    _te->debug.inspections[2].name="BG";
    _te->debug.inspections[2].address=0xd021;
    _te->debug.inspections[2].size=1;
    ++_te->debug.inspections_count;

    // a) Standard Character Mode
    vic2_tilemap_enable( e, 0, 0, 0 );
    paper( e, red->name );
    pen( e, yellow->name );
    vic2_cls( e );
    
    _te->trackedVariables[0] = red;
    _te->trackedVariables[1] = yellow;

}

int test_vic2_cls2_tester( TestEnvironment * _te ) {

    Variable * red = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * yellow = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );

    int i=0, j=0; 

    for( i=0; i<_te->debug.inspections[0].size; ++i ) {
        if ( _te->debug.inspections[0].memory[i] != 32 ) {
            printf( "Failed clearing text\n");
            return 0;
        }
    }

    for( i=0; i<_te->debug.inspections[1].size; ++i ) {
        if ( _te->debug.inspections[1].memory[i] != ( yellow->value ) ) {
            printf( "Failed clearing background\n");
            return 0;
        }
    }

    if ( _te->debug.inspections[2].memory[0] != ( red->value ) ) {
            printf( "Failed background color\n");
        return 0;
    }

    return 1;

}

//============================================================================

void test_vic2_cls3_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * emptyTile = variable_retrieve( e, "EMPTYTILE" );
    Variable * red = variable_define( e, "red", VT_COLOR, COLOR_RED );
    Variable * yellow = variable_define( e, "yellow", VT_COLOR, COLOR_YELLOW );

    _te->debug.inspections[0].name="TEXTAREA";
    _te->debug.inspections[0].address=0x8400;
    _te->debug.inspections[0].size=1000;
    ++_te->debug.inspections_count;

    _te->debug.inspections[1].name="COLORMAP";
    _te->debug.inspections[1].address=0xD800;
    _te->debug.inspections[1].size=1000;
    ++_te->debug.inspections_count;

    _te->debug.inspections[2].name="BG";
    _te->debug.inspections[2].address=0xd021;
    _te->debug.inspections[2].size=1;
    ++_te->debug.inspections_count;

    // a) Standard Character Mode
    cpu_store_8bit( e, emptyTile->realName, 42 );
    vic2_tilemap_enable( e, 0, 0, 0 );
    paper( e, red->name );
    pen( e, yellow->name );
    vic2_cls( e );
    
    _te->trackedVariables[0] = emptyTile;
    _te->trackedVariables[1] = red;
    _te->trackedVariables[2] = yellow;

}

int test_vic2_cls3_tester( TestEnvironment * _te ) {

    int i=0, j=0; 

    Variable * emptyTile = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );
    Variable * red = variable_retrieve( &_te->environment, _te->trackedVariables[1]->name );
    Variable * yellow = variable_retrieve( &_te->environment, _te->trackedVariables[2]->name );

    for( i=0; i<_te->debug.inspections[0].size; ++i ) {
        if ( _te->debug.inspections[0].memory[i] != emptyTile->value ) {
            printf( "Failed clearing text at %4.4x\n", i);
            return 0;
        }
    }

    for( i=0; i<_te->debug.inspections[1].size; ++i ) {
        if ( _te->debug.inspections[1].memory[i] != ( yellow->value ) ) {
            printf( "Failed clearing background\n");
            return 0;
        }
    }

    if ( _te->debug.inspections[2].memory[0] != ( red->value ) ) {
        printf( "Failed background color\n");
        return 0;
    }

    return 1;

}

//============================================================================

void test_vic2_background_color_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * red = variable_define( e, "red", VT_COLOR, COLOR_RED );

    _te->debug.inspections[0].name="BG";
    _te->debug.inspections[0].address=0xd021;
    _te->debug.inspections[0].size=1;
    ++_te->debug.inspections_count;

    vic2_background_color_vars( e, "#0", red->realName );

    _te->trackedVariables[0] = red;

}

int test_vic2_background_color_tester( TestEnvironment * _te ) {

    int i=0, j=0; 

    Variable * red = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    if ( _te->debug.inspections[0].memory[0] != ( red->value ) ) {
        printf( "Failed background color\n");
        return 0;
    }

    return 1;

}

//============================================================================

void test_vic2_point_at_vars_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * x = variable_define( e, "x", VT_POSITION, 0 );
    Variable * y = variable_define( e, "y", VT_POSITION, 0 );
    Variable * c = variable_define( e, "c", VT_COLOR, COLOR_RED );

    _te->debug.inspections[0].name="BITMAP";
    _te->debug.inspections[0].address=0xA000;
    _te->debug.inspections[0].size=8000;
    ++_te->debug.inspections_count;

    _te->debug.inspections[1].name="COLORMAP";
    _te->debug.inspections[1].address=0x8400;
    _te->debug.inspections[1].size=1000;
    ++_te->debug.inspections_count;

    vic2_bitmap_enable( e, 0, 0, 0 );
    pen( e, c->name );
    vic2_point_at_vars( e, x->name, y->name );
    variable_store( e, x->name, 9 );
    vic2_point_at_vars( e, x->name, y->name );

}

int test_vic2_point_at_vars_tester( TestEnvironment * _te ) {

    if ( ( _te->debug.inspections[0].memory[0] ) != 0x80 ) {
        printf( "Failed pixel 1 = %2.2x\n", _te->debug.inspections[0].memory[0] );
        return 0;
    }

    if ( ( _te->debug.inspections[0].memory[8] ) != 0x40 ) {
        printf( "Failed pixel 2\n");
        return 0;
    }

    if ( ( _te->debug.inspections[1].memory[0] ) != ( ( COLOR_RED << 4 ) & 0xff ) ) {
        printf( "Failed color 1 = %2.2x\n", _te->debug.inspections[1].memory[0] );
        return 0;
    }

    if ( ( _te->debug.inspections[1].memory[1] ) != ( ( COLOR_RED << 4 ) & 0xff ) ) {
        printf( "Failed color 1 = %2.2x\n", _te->debug.inspections[1].memory[0] );
        return 0;
    }

    return 1;

}

//============================================================================

void test_vic2_point_at_vars_payloadB( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * x = variable_define( e, "x", VT_POSITION, 0 );
    Variable * y = variable_define( e, "y", VT_POSITION, 0 );
    Variable * c = variable_define( e, "c", VT_COLOR, COLOR_RED );

    _te->debug.inspections[0].name="BITMAP";
    _te->debug.inspections[0].address=0xA000;
    _te->debug.inspections[0].size=8000;
    ++_te->debug.inspections_count;

    _te->debug.inspections[1].name="COLORMAP";
    _te->debug.inspections[1].address=0x8400;
    _te->debug.inspections[1].size=1000;
    ++_te->debug.inspections_count;

    vic2_bitmap_enable( e, 0, 0, 0 );
    pen( e, c->name );
    int i;
    for( i=0; i<16; ++i ) {
        variable_store( e, x->name, i );
        vic2_point_at_vars( e, x->name, y->name );
    }

}

int test_vic2_point_at_vars_testerB( TestEnvironment * _te ) {

    if ( ( _te->debug.inspections[0].memory[0] ) != 0xff ) {
        printf( "Failed pixel 1 = %2.2x\n", _te->debug.inspections[0].memory[0] );
        return 0;
    }

    if ( ( _te->debug.inspections[0].memory[8] ) != 0xff ) {
        printf( "Failed pixel 2 = %2.2x\n", _te->debug.inspections[0].memory[8] );
        return 0;
    }

    if ( ( _te->debug.inspections[1].memory[0] ) != ( ( COLOR_RED << 4 ) & 0xff ) ) {
        printf( "Failed color 1 = %2.2x\n", _te->debug.inspections[1].memory[0] );
        return 0;
    }

    if ( ( _te->debug.inspections[1].memory[1] ) != ( ( COLOR_RED << 4 ) & 0xff ) ) {
        printf( "Failed color 1 = %2.2x\n", _te->debug.inspections[1].memory[0] );
        return 0;
    }

    return 1;

}

//============================================================================

void test_vic2_point_at_vars_payloadC( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * x = variable_define( e, "x", VT_POSITION, 0 );
    Variable * y = variable_define( e, "y", VT_POSITION, 0 );
    Variable * red = variable_define( e, "red", VT_COLOR, COLOR_RED );
    Variable * white = variable_define( e, "white", VT_COLOR, COLOR_WHITE );
    Variable * zero = variable_define( e, "zero", VT_SWORD, 0 );
    Variable * screenWidth = variable_define( e, "screenWidth", VT_SWORD, 319 );
    Variable * screenHeight = variable_define( e, "screenHeight", VT_SWORD, 199 );

    _te->debug.inspections[0].name="BITMAP";
    _te->debug.inspections[0].address=0xA000;
    _te->debug.inspections[0].size=8000;
    ++_te->debug.inspections_count;

    _te->debug.inspections[1].name="COLORMAP";
    _te->debug.inspections[1].address=0x8400;
    _te->debug.inspections[1].size=1000;
    ++_te->debug.inspections_count;

    vic2_bitmap_enable( e, 0, 0, 0 );
    paper( e, red->name );
    vic2_cls( e );
    begin_for( e, y->name, zero->name, screenHeight->name );
        begin_for( e, x->name, zero->name, screenWidth->name );
            pen( e, white->name );
            vic2_point_at_vars( e, x->name, y->name );
        end_for( e );
    end_for( e );

}

int test_vic2_point_at_vars_testerC( TestEnvironment * _te ) {

    int i=0;
    
    for( i=0; i<_te->debug.inspections[0].size; ++i ) {
        if ( ( _te->debug.inspections[0].memory[i] ) != 0xff ) {
            printf( "Failed pixel %d = %2.2x\n", i, _te->debug.inspections[0].memory[i] );
            return 0;
        }
    }

    for( i=0; i<_te->debug.inspections[1].size; ++i ) {
        if ( ( _te->debug.inspections[1].memory[i] ) != ( ( COLOR_RED << 4 ) & 0xff ) ) {
            printf( "Failed color %d = %2.2x\n", i, _te->debug.inspections[0].memory[i] );
            return 0;
        }
    }

    return 1;

}

//============================================================================

void test_vic2_point_at_vars_payloadD( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * x = variable_define( e, "x", VT_POSITION, 0 );
    Variable * y = variable_define( e, "y", VT_POSITION, 199 );
    Variable * c = variable_define( e, "c", VT_COLOR, COLOR_RED );

    _te->debug.inspections[0].name="BITMAP";
    _te->debug.inspections[0].address=0xA000;
    _te->debug.inspections[0].size=8000;
    ++_te->debug.inspections_count;

    _te->debug.inspections[1].name="COLORMAP";
    _te->debug.inspections[1].address=0x8400;
    _te->debug.inspections[1].size=1000;
    ++_te->debug.inspections_count;

    vic2_bitmap_enable( e, 0, 0, 0 );
    pen( e, c->name );
    int i;
    for( i=312; i<320; ++i ) {
        variable_store( e, x->name, i );
        vic2_point_at_vars( e, x->name, y->name );
    }

}

int test_vic2_point_at_vars_testerD( TestEnvironment * _te ) {

    if ( ( _te->debug.inspections[0].memory[0] ) != 0xff ) {
        printf( "Failed pixel 1 = %2.2x\n", _te->debug.inspections[0].memory[0] );
        return 0;
    }

    if ( ( _te->debug.inspections[0].memory[0] ) != 0xff ) {
        printf( "Failed pixel 2 = %2.2x\n", _te->debug.inspections[0].memory[8] );
        return 0;
    }

    if ( ( _te->debug.inspections[1].memory[0] ) != ( ( COLOR_RED << 4 ) & 0xff ) ) {
        printf( "Failed color 1 = %2.2x\n", _te->debug.inspections[1].memory[0] );
        return 0;
    }

    if ( ( _te->debug.inspections[1].memory[1] ) != ( ( COLOR_RED << 4 ) & 0xff ) ) {
        printf( "Failed color 1 = %2.2x\n", _te->debug.inspections[1].memory[0] );
        return 0;
    }

    return 1;

}
//============================================================================

void test_vic2_point_payload( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * x = variable_define( e, "x", VT_POSITION, 160 );
    Variable * y = variable_define( e, "y", VT_POSITION, 120 );
    Variable * c = variable_define( e, "c", VT_COLOR, COLOR_RED );
    Variable * result = variable_define( e, "r", VT_COLOR, 0 );

    vic2_bitmap_enable( e, 0, 0, 0 );
    pen( e, c->name );
    vic2_point_at_vars( e, x->name, y->name );
    vic2_point( e, x->name, y->name, result->name );

    _te->trackedVariables[0] = result;

}

int test_vic2_point_tester( TestEnvironment * _te ) {

    Variable * result = variable_retrieve( &_te->environment, _te->trackedVariables[0]->name );

    return result->value == COLOR_RED;

}

//============================================================================

void test_vic2_text_payloadB( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * text = variable_define( e, "text", VT_DSTRING, 0 );
    Variable * c = variable_define( e, "c", VT_COLOR, COLOR_RED );

    variable_store_string( e, text->name, "abcde" );

    Variable * address = variable_temporary( e, VT_ADDRESS, "(text address)" );
    Variable * size = variable_temporary( e, VT_BYTE, "(text size)" );

    cpu_dsdescriptor( e, text->realName, address->realName, size->realName );

    _te->debug.inspections[0].name="TEXT";
    _te->debug.inspections[0].address=0x8400;
    _te->debug.inspections[0].size=1000;
    ++_te->debug.inspections_count;

    _te->debug.inspections[1].name="COLORMAP";
    _te->debug.inspections[1].address=0xD800;
    _te->debug.inspections[1].size=1000;
    ++_te->debug.inspections_count;

    vic2_text( e, address->realName, size->realName );

}

int test_vic2_text_testerB( TestEnvironment * _te ) {

    int x = 1;

    for( int i=0; i<5; ++i ) {
        if ( ( _te->debug.inspections[0].memory[i] ) != x ) {
            printf( "Failed letter %d = %2.2x %2.2x\n", i, _te->debug.inspections[0].memory[i], x );
            return 0;
        }
        ++x;
    }

    return 1;

}

//============================================================================

void test_vic2_text_payloadC( TestEnvironment * _te ) {

    Environment * e = &_te->environment;

    Variable * text = variable_define( e, "text", VT_DSTRING, 0 );
    Variable * c = variable_define( e, "c", VT_COLOR, COLOR_RED );

    char sequence[MAX_TEMPORARY_STORAGE]; sprintf(sequence, "abcde%s%s%sabcde", "\x4","\x4", "\x4" );

    variable_store_string( e, text->name, sequence );

    Variable * address = variable_temporary( e, VT_ADDRESS, "(text address)" );
    Variable * size = variable_temporary( e, VT_BYTE, "(text size)" );

    cpu_dsdescriptor( e, text->realName, address->realName, size->realName );

    _te->debug.inspections[0].name="TEXT";
    _te->debug.inspections[0].address=0x8400;
    _te->debug.inspections[0].size=1000;
    ++_te->debug.inspections_count;

    _te->debug.inspections[1].name="COLORMAP";
    _te->debug.inspections[1].address=0xD800;
    _te->debug.inspections[1].size=1000;
    ++_te->debug.inspections_count;

    vic2_text( e, address->realName, size->realName );

}

int test_vic2_text_testerC( TestEnvironment * _te ) {

    int x = 1, i = 0;

    for( i=0; i<5; ++i ) {
        if ( ( _te->debug.inspections[0].memory[i] ) != x ) {
            printf( "Failed letter %d = %2.2x %2.2x\n", i, _te->debug.inspections[0].memory[i], x );
            return 0;
        }
        ++x;
    }

    x = 1;

    for( i=0; i<5; ++i ) {
        if ( ( _te->debug.inspections[0].memory[40*4+4+i] ) != x ) {
            printf( "Failed letter %d = %2.2x %2.2x\n", i+5, _te->debug.inspections[0].memory[40*4+4+i], x );
            return 0;
        }
        ++x;
    }

    return 1;

}


void test_vic2( ) {

    create_test( "vic2_text A", &test_vic2_text_payloadA, &test_vic2_text_testerA );    
    create_test( "vic2_text B", &test_vic2_text_payloadB, &test_vic2_text_testerB );
    create_test( "vic2_text C", &test_vic2_text_payloadC, &test_vic2_text_testerC );
    create_test( "vic2_bitmap_enabled", &test_vic2_bitmap_enable_payload, &test_vic2_bitmap_enable_tester );    
    create_test( "vic2_tilemap_enabled", &test_vic2_bitmap_enable_payload, &test_vic2_bitmap_enable_tester );
    create_test( "vic2_cls", &test_vic2_cls_payload, &test_vic2_cls_tester );
    create_test( "vic2_cls2", &test_vic2_cls2_payload, &test_vic2_cls2_tester );
    create_test( "vic2_cls3", &test_vic2_cls3_payload, &test_vic2_cls3_tester );
    create_test( "vic2_background_color", &test_vic2_background_color_payload, &test_vic2_background_color_tester );
    create_test( "vic2_point_at_vars", &test_vic2_point_at_vars_payload, &test_vic2_point_at_vars_tester );
    create_test( "vic2_point", &test_vic2_point_payload, &test_vic2_point_tester );

    create_test( "vic2_point_at_vars B", &test_vic2_point_at_vars_payloadB, &test_vic2_point_at_vars_testerB );
    create_test( "vic2_point_at_vars C", &test_vic2_point_at_vars_payloadC, &test_vic2_point_at_vars_testerC );
    create_test( "vic2_point_at_vars D", &test_vic2_point_at_vars_payloadD, &test_vic2_point_at_vars_testerD );

}

#endif