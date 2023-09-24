/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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

#if defined(__coco3__)

#include "../ugbc.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
    { 0x00, 0xcc, 0x55, 0xff, 0, "GREEN" }
};

static RGBi * commonPalette;
int lastUsedSlotInCommonPalette = 0;

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

/**
 * @brief <i>VIC-II</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with another sprite. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable.
 * 
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void gime_collision( Environment * _environment, char * _sprite_mask, char * _result ) {
    
}

/**
 * @brief <i>VIC-II</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with a tile. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable.
 * 
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void gime_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to change border color
 * 
 * This function can be used to issue code aimed at changing the
 * border color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _border_color Border color to use
 */
void gime_border_color( Environment * _environment, char * _border_color ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void gime_background_color( Environment * _environment, char * _index, char * _background_color ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to change common sprite's color 
 * 
 * This function can be used to issue code aimed at changing the
 * common color of the sprites.

 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _common_color Index of the color to use
 */
void gime_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to set raster irq
 * 
 * This function outputs assembly code needed to initialize a raster routine. 
 * In other words, asynchronously and in parallel with the execution of the 
 * main program, the routine starting from the label provided will be executed
 * when the vertical brush on the screen reaches the value of _position. 
 * This function is particularly useful when the position is communicated 
 * is given as an integer.
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _positionlo The vertical position to wait for (bits 7..0)
 * @param _positionhi The vertical position to wait for (bit 8)
 */
void gime_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to wait for next raster irq
 * 
 * This function outputs assembly code needed to wait for the
 * next raster. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 *
 */
void gime_next_raster( Environment * _environment ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to wait for next raster irq at different position
 * 
 * This function outputs assembly code needed to wait for the
 * next raster on a different position with a different code to
 * execute. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _positionlo The vertical position to wait for (bits 7..0)
 * @param _positionhi The vertical position to wait for (bit 8)
 */
void gime_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to enable ECM
 * 
 * @param _environment Current calling environment
 */
void gime_enable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void gime_disable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to enable MCM
 * 
 * @param _environment Current calling environment
 */
void gime_enable_mcm( Environment * _environment ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void gime_disable_mcm( Environment * _environment ) {

}

void gime_bank_select( Environment * _environment, int _bank ) {

}

#define GIME_MODE( _graphics, _linesize ) \
    outline1( "LDA #$%2.2x", ( ( _graphics & 0x01 ) << 7 ) | ( _linesize & 0x03 ) ); \
    outline0( "STA GIMEVIDM" ); \
    outline0( "STA GIMEVIDMSHADOW" );

#define GIME_TEXT( )       GIME_MODE( 0, 3 )
#define GIME_GRAPH( )      GIME_MODE( 1, 1 )

#define GIME_24ROWS         0
#define GIME_25ROWS         1
#define GIME_UNUSED         2
#define GIME_28ROWS         3

#define GIME_HRES_32COLS    0    // or 2 is equal!
#define GIME_CRES_32COLS    1    // or 3 is equal!

#define GIME_HRES_40COLS    1    // or 3 is equal!
#define GIME_CRES_40COLS    1    // or 3 is equal!

#define GIME_HRES_64COLS    4    // or 6 is equal!
#define GIME_CRES_64COLS    1    // or 3 is equal!

#define GIME_HRES_80COLS    5    // or 7 is equal!
#define GIME_CRES_80COLS    1    // or 3 is equal!

#define GIME_2COLORS         0
#define GIME_4COLORS         1
#define GIME_16COLORS        2
#define GIME_32COLORS        3  // unused!!

#define GIME_128PIXELS       0
#define GIME_160PIXELS       1
#define GIME_256PIXELS       2
#define GIME_320PIXELS       3
#define GIME_512PIXELS       4
#define GIME_640PIXELS       5
#define GIME_1024PIXELS      6
#define GIME_1280PIXELS      7

#define GIME_RESOLUTION( _hres, _cres,  _vres ) \
    outline1( "LDA #$%2.2x", ( ( _vres & 0x03 ) << 5 ) | ( ( _hres & 0x07 ) << 2 ) | ( ( _cres & 0x03 ) ) ); \
    outline0( "STA GIMEVIDR" );

#define GIME_ADDRESS( _address ) \
    outline1( "LDD #$%4.4x", ( _address >> 3 ) ); \
    outline0( "STA GIMEVOFF1" ); \
    outline0( "STB GIMEVOFF0" ); \
    outline0( "CLR GIMEHOFF" );

#define GIME_128K( )  GIME_ADDRESS( 0x60000 )
#define GIME_512K( )  GIME_ADDRESS( 0x00000 )

int gime_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    // deploy( gimevars, src_hw_gime_vars_asm );

    GIME_128K( );

    _environment->fontWidth = 8;
    _environment->fontHeight = 8;
    _environment->screenShades = 4;
    _environment->screenTiles = 128;
    switch( _screen_mode->id ) {

        case TILEMAP_MODE_32X24:
            
            GIME_TEXT()
            GIME_RESOLUTION( GIME_HRES_32COLS, GIME_CRES_32COLS, GIME_24ROWS )

            _environment->screenTilesWidth = 32;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 16;
            break;

        case TILEMAP_MODE_32X25:
            
            GIME_TEXT()
            GIME_RESOLUTION( GIME_HRES_32COLS, GIME_CRES_32COLS, GIME_25ROWS )

            _environment->screenTilesWidth = 32;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 16;
            break;

        case TILEMAP_MODE_32X28:

            GIME_TEXT()
            GIME_RESOLUTION( GIME_HRES_32COLS, GIME_CRES_32COLS, GIME_28ROWS )

            _environment->screenTilesWidth = 32;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 16;
            break;

        case TILEMAP_MODE_40X24:

            GIME_TEXT()
            GIME_RESOLUTION( GIME_HRES_40COLS, GIME_CRES_40COLS, GIME_24ROWS )

            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 16;
            break;

        case TILEMAP_MODE_40X25:

            GIME_TEXT()
            GIME_RESOLUTION( GIME_HRES_40COLS, GIME_CRES_40COLS, GIME_25ROWS )

            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 16;
            break;

        case TILEMAP_MODE_40X28:

            GIME_TEXT()
            GIME_RESOLUTION( GIME_HRES_40COLS, GIME_CRES_40COLS, GIME_28ROWS )

            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 16;
            break;

        case TILEMAP_MODE_64X24:

            GIME_TEXT()
            GIME_RESOLUTION( GIME_HRES_64COLS, GIME_CRES_64COLS, GIME_24ROWS )

            _environment->screenTilesWidth = 64;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 16;
            break;

        case TILEMAP_MODE_64X25:

            GIME_TEXT()
            GIME_RESOLUTION( GIME_HRES_64COLS, GIME_CRES_64COLS, GIME_25ROWS )

            _environment->screenTilesWidth = 64;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 16;
            break;

        case TILEMAP_MODE_64X28:

            GIME_TEXT()
            GIME_RESOLUTION( GIME_HRES_64COLS, GIME_CRES_64COLS, GIME_28ROWS )

            _environment->screenTilesWidth = 64;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 16;
            break;

        case TILEMAP_MODE_80X24:

            GIME_TEXT()
            GIME_RESOLUTION( GIME_HRES_80COLS, GIME_CRES_80COLS, GIME_24ROWS )

            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 16;
            break;

        case TILEMAP_MODE_80X25:

            GIME_TEXT()
            GIME_RESOLUTION( GIME_HRES_80COLS, GIME_CRES_80COLS, GIME_25ROWS )

            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 16;
            break;

        case TILEMAP_MODE_80X28:

            GIME_TEXT()
            GIME_RESOLUTION( GIME_HRES_80COLS, GIME_CRES_80COLS, GIME_28ROWS )

            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 16;
            break;

        //////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////

        case BITMAP_MODE_128x192x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_128PIXELS, GIME_2COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 16;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_128x200x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_128PIXELS, GIME_2COLORS, GIME_25ROWS )
            
            _environment->screenTilesWidth = 16;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_128x225x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_128PIXELS, GIME_2COLORS, GIME_28ROWS )
            
            _environment->screenTilesWidth = 16;
            _environment->screenTilesHeight = 29;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_64x192x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_128PIXELS, GIME_4COLORS, GIME_24ROWS )
            
            _environment->screenTilesWidth = 8;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_64x200x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_128PIXELS, GIME_4COLORS, GIME_25ROWS )
            
            _environment->screenTilesWidth = 8;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_64x225x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_128PIXELS, GIME_4COLORS, GIME_28ROWS )
            
            _environment->screenTilesWidth = 8;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_160x192x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_160PIXELS, GIME_2COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 20;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_160x200x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_160PIXELS, GIME_2COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 20;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_160x225x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_160PIXELS, GIME_2COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 20;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_80x192x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_160PIXELS, GIME_4COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 10;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_80x200x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_160PIXELS, GIME_4COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 10;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_80x225x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_160PIXELS, GIME_4COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 10;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_256x192x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_256PIXELS, GIME_2COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 32;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_256x200x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_256PIXELS, GIME_2COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 32;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_256x225x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_256PIXELS, GIME_2COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 32;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_128x192x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_256PIXELS, GIME_4COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 16;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_128x200x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_256PIXELS, GIME_4COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 16;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_128x225x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_256PIXELS, GIME_4COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 16;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_64x192x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_256PIXELS, GIME_16COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 8;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 16;
            break;

        case BITMAP_MODE_64x200x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_256PIXELS, GIME_16COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 8;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 16;
            break;

        case BITMAP_MODE_64x225x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_256PIXELS, GIME_16COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 8;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 16;
            break;

        case BITMAP_MODE_320x192x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_320PIXELS, GIME_2COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_320x200x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_320PIXELS, GIME_2COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_320x225x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_320PIXELS, GIME_2COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_160x192x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_320PIXELS, GIME_4COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 20;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_160x200x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_320PIXELS, GIME_4COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 20;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_160x225x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_320PIXELS, GIME_4COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 20;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_80x192x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_320PIXELS, GIME_16COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 10;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 16;
            break;

        case BITMAP_MODE_80x200x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_320PIXELS, GIME_16COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 10;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 16;
            break;

        case BITMAP_MODE_80x225x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_320PIXELS, GIME_16COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 10;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 16;
            break;

        case BITMAP_MODE_512x192x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_512PIXELS, GIME_2COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 64;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_512x200x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_512PIXELS, GIME_2COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 64;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_512x225x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_512PIXELS, GIME_2COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 64;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_256x192x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_512PIXELS, GIME_4COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 32;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_256x200x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_512PIXELS, GIME_4COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 32;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_256x225x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_512PIXELS, GIME_4COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 32;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_128x192x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_512PIXELS, GIME_16COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 16;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 16;
            break;

        case BITMAP_MODE_128x200x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_512PIXELS, GIME_16COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 16;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 16;
            break;

        case BITMAP_MODE_128x225x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_512PIXELS, GIME_16COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 16;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 16;
            break;

        case BITMAP_MODE_640x192x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_640PIXELS, GIME_2COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_640x200x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_640PIXELS, GIME_2COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_640x225x2:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_640PIXELS, GIME_2COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 2;
            break;

        case BITMAP_MODE_320x192x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_640PIXELS, GIME_4COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_320x200x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_640PIXELS, GIME_4COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_320x225x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_640PIXELS, GIME_4COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_160x192x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_640PIXELS, GIME_16COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 20;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 16;
            break;

        case BITMAP_MODE_160x200x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_640PIXELS, GIME_16COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 20;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 16;
            break;

        case BITMAP_MODE_160x225x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_640PIXELS, GIME_16COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 20;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 16;
            break;

        case BITMAP_MODE_512x192x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_1024PIXELS, GIME_4COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 64;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_512x200x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_1024PIXELS, GIME_4COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 64;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_512x225x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_1024PIXELS, GIME_4COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 64;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_256x192x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_1024PIXELS, GIME_16COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 32;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 16;
            break;

        case BITMAP_MODE_256x200x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_1024PIXELS, GIME_16COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 32;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 16;
            break;

        case BITMAP_MODE_256x225x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_1024PIXELS, GIME_16COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 32;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 16;
            break;

        case BITMAP_MODE_640x192x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_1280PIXELS, GIME_4COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_640x200x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_1280PIXELS, GIME_4COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_640x225x4:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_1280PIXELS, GIME_4COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 4;
            break;

        case BITMAP_MODE_320x192x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_1280PIXELS, GIME_16COLORS, GIME_24ROWS )

            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 24;
            _environment->screenColors = 16;
            break;

        case BITMAP_MODE_320x200x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_1280PIXELS, GIME_16COLORS, GIME_25ROWS )

            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 16;
            break;

        case BITMAP_MODE_320x225x16:

            GIME_GRAPH()
            GIME_RESOLUTION( GIME_1280PIXELS, GIME_16COLORS, GIME_28ROWS )

            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 28;
            _environment->screenColors = 16;
            break;

        default:
            CRITICAL_SCREEN_UNSUPPORTED( _screen_mode->id );
    }

    _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
    _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;

    int currentFrameSize;

    if ( _screen_mode->bitmap ) {
        switch( _environment->screenColors ) {
            case 2:
                currentFrameSize = ( ( _environment->screenWidth / 8 ) * _environment->screenHeight );
                break;
            case 4:
                currentFrameSize = ( ( _environment->screenWidth / 8 ) * _environment->screenHeight ) * 2;
                break;
            case 16:
            default:
                currentFrameSize = ( ( _environment->screenWidth / 8 ) * _environment->screenHeight ) * 4;
                break;
        }
    } else {
        currentFrameSize =  _environment->screenTilesWidth * _environment->screenTilesHeight * 2;
    }

    if ( currentFrameSize <= 0x2000 ) {
        cpu_store_8bit( _environment, "GIMEMMUSTART", 3 );
        cpu_store_16bit( _environment, "BITMAPADDRESS", 0xe000 );
        cpu_store_16bit( _environment, "TEXTADDRESS", 0xe000 );
    } else 
    if ( currentFrameSize <= 0x4000 ) {
        cpu_store_8bit( _environment, "GIMEMMUSTART", 2 );
        cpu_store_16bit( _environment, "BITMAPADDRESS", 0xc000 );
        cpu_store_16bit( _environment, "TEXTADDRESS", 0xc000 );
    } else if ( currentFrameSize <= 0x6000 ) {
        cpu_store_8bit( _environment, "GIMEMMUSTART", 1 );
        cpu_store_16bit( _environment, "BITMAPADDRESS", 0xa000 );
        cpu_store_16bit( _environment, "TEXTADDRESS", 0xa000 );
    } else {
        cpu_store_8bit( _environment, "GIMEMMUSTART", 0 );
        cpu_store_16bit( _environment, "BITMAPADDRESS", 0x8000 );
        cpu_store_16bit( _environment, "TEXTADDRESS", 0x8000 );
    }

    cpu_store_16bit( _environment, "ORIGINX", 0 );
    cpu_store_16bit( _environment, "ORIGINY", 0 );
    cpu_store_16bit( _environment, "CURRENTWIDTH", _environment->screenWidth );
    cpu_store_16bit( _environment, "CURRENTHEIGHT", _environment->screenHeight );
    cpu_move_16bit( _environment, "CURRENTWIDTH", "RESOLUTIONX" );
    cpu_move_16bit( _environment, "CURRENTHEIGHT", "RESOLUTIONY" );
    cpu_store_8bit( _environment, "CURRENTTILES", _environment->screenTiles );
    cpu_store_8bit( _environment, "CURRENTTILESWIDTH", _environment->screenTilesWidth );
    cpu_store_8bit( _environment, "CURRENTTILESHEIGHT", _environment->screenTilesHeight );
    cpu_store_8bit( _environment, "PALETTELIMIT", _environment->screenColors );
    cpu_store_16bit( _environment, "CURRENTFRAMESIZE", currentFrameSize );

    cpu_call( _environment, "GIMERAM" );

}

void gime_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors, 8, 8 );

    if ( mode ) {
        gime_screen_mode_enable( _environment, mode );

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 0 );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 0;
    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void gime_bitmap_disable( Environment * _environment ) {    

}

void gime_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors, _tile_width, _tile_height );

    if ( mode ) {
        gime_screen_mode_enable( _environment, mode );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 1;

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );    
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 1 );

    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void gime_bitmap_at( Environment * _environment, char * _address ) {

}

void gime_colormap_at( Environment * _environment, char * _address ) {    

}

void gime_textmap_at( Environment * _environment, char * _address ) {

}

void gime_point_at_int( Environment * _environment, int _x, int _y ) {

    deploy( gimevars, src_hw_gime_vars_asm );
    deploy( plot, src_hw_gime_plot_asm );
    
    outline1("LDX %4.4x", (_x & 0xffff ) );
    outline0("STX PLOTX");
    outline1("LDD %4.4x", ( _y & 0xffff ) );
    outline0("STD PLOTY");
    outline0("LDA #1");
    outline0("STA PLOTM");
    outline0("JSR PLOT");
    

}

void gime_point_at_vars( Environment * _environment, char *_x, char *_y ) {

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );

    deploy( gimevars, src_hw_gime_vars_asm );
    deploy( plot, src_hw_gime_plot_asm );
    
    outline1("LDX %s", x->realName );
    outline0("STX PLOTX");
    outline1("LDD %s", y->realName );
    outline0("STD PLOTY");
    outline0("LDA #1");
    outline0("STA PLOTM");
    outline0("JSR PLOT");

}

void gime_point( Environment * _environment, char *_x, char *_y, char * _result ) {

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    Variable * result = variable_retrieve_or_define( _environment, _result, VT_BYTE, 0 );

    deploy( gimevars, src_hw_gime_vars_asm );
    deploy( plot, src_hw_gime_plot_asm );
    
    outline1("LDD %s", x->realName );
    outline0("STD PLOTX");
    outline1("LDD %s", y->realName );
    outline0("STD PLOTY");
    outline0("LDA #3");
    outline0("STA PLOTM");
    outline0("JSR PLOT");
    outline0("LDA PLOTM");
    outline1("STA %s", result->realName );    

}

void gime_screen_on( Environment * _environment ) {

}

void gime_screen_off( Environment * _environment ) {

}

void gime_screen_rows( Environment * _environment, char * _rows ) {

}

void gime_screen_columns( Environment * _environment, char * _columns ) {

}

void gime_sprite_data_from( Environment * _environment, char * _sprite, char * _address ) {

}

void gime_sprite_enable( Environment * _environment, char * _sprite ) {

}

void gime_sprite_disable( Environment * _environment, char * _sprite ) {

}

void gime_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

}

void gime_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

}

void gime_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

}

void gime_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

}

void gime_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

}

void gime_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void gime_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void gime_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

}

void gime_tiles_at( Environment * _environment, char * _address ) {

}

void gime_vertical_scroll( Environment * _environment, char * _displacement ) {

}

void gime_horizontal_scroll( Environment * _environment, char * _displacement ) {

}

void gime_get_width( Environment * _environment, char *_result ) {

    outline0("LDX CURRENTWIDTH" );
    outline1("STX %s", _result );

}

void gime_tiles_get( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILES" );
    outline1("STA %s", _result );

}

void gime_tiles_get_width( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILESWIDTH" );
    outline1("STA %s", _result );

}

void gime_get_height( Environment * _environment, char *_result ) {

    outline0("LDX CURRENTHEIGHT" );
    outline1("STX %s", _result );

}

void gime_tiles_get_height( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILESHEIGHT" );
    outline1("STA %s", _result );

}

void gime_cls( Environment * _environment ) {

    deploy( gimevars, src_hw_gime_vars_asm);

    if ( _environment->currentTileMode ) {
        deploy( clsText, src_hw_gime_cls_text_asm );
        outline0("JSR CLST");
    } else {
        deploy( clsGraphic, src_hw_gime_cls_graphic_asm );
        outline0("JSR CLSG");
    }

}

void gime_scroll_text( Environment * _environment, int _direction ) {

    deploy( vScrollText, src_hw_gime_vscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );

    outline0("JSR VSCROLLT");

}

void gime_text( Environment * _environment, char * _text, char * _text_size ) {

    deploy( gimevars, src_hw_gime_vars_asm);

    deploy( textEncodedAt, src_hw_gime_text_at_asm );

    outline1("LDY %s", _text);
    outline0("STY TEXTPTR" );
    outline1("LDA %s", _text_size);
    outline0("STA TEXTSIZE" );

    if ( _environment->currentMode < 0x10 ) {
        deploy( clsText, src_hw_gime_cls_text_asm );
        deploy( vScrollText, src_hw_gime_vscroll_text_asm );
        deploy( textEncodedAtText, src_hw_gime_text_at_text_asm );
        outline0("JSR TEXTATTILEMODE");
    } else {
        // deploy( clsGraphic, src_hw_gime_cls_graphic_asm );
        // deploy( textEncodedAtGraphic, src_hw_gime_text_at_graphic_asm );
        // outline0("JSR TEXTATBITMAPMODE");
    }

}

void gime_initialization( Environment * _environment ) {

    deploy( gimevars, src_hw_gime_vars_asm );
    deploy( gimestartup, src_hw_gime_startup_asm );

    variable_import( _environment, "CURRENTMODE", VT_BYTE, 0 );
    variable_global( _environment, "CURRENTMODE" );
    variable_import( _environment, "CURRENTTILEMODE", VT_BYTE, 1 );
    variable_global( _environment, "CURRENTTILEMODE" );

    variable_import( _environment, "CURRENTWIDTH", VT_POSITION, 256 );
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION, 128  );
    variable_global( _environment, "CURRENTHEIGHT" );
    variable_import( _environment, "CURRENTTILESWIDTH", VT_BYTE, 32 );
    variable_global( _environment, "CURRENTTILESWIDTH" );
    variable_import( _environment, "CURRENTTILESHEIGHT", VT_BYTE, 16 );
    variable_global( _environment, "CURRENTTILESHEIGHT" );
    variable_import( _environment, "CURRENTTILES", VT_BYTE, 255 );
    variable_global( _environment, "CURRENTTILES" );
    variable_import( _environment, "FONTWIDTH", VT_BYTE, 8 );
    variable_global( _environment, "FONTWIDTH" );
    variable_import( _environment, "FONTHEIGHT", VT_BYTE, 8 );
    variable_global( _environment, "FONTHEIGHT" );
    variable_import( _environment, "PALETTELIMIT", VT_BYTE, 0 );
    variable_global( _environment, "PALETTELIMIT" );
    variable_import( _environment, "GIMEMMUSTART", VT_BYTE, 2 );
    variable_global( _environment, "GIMEMMUSTART" );

    SCREEN_MODE_DEFINE( TILEMAP_MODE_40X25, 0, 40, 25, 16, 8, 8, "Alphanumeric 40 columns x 25 rows");
    SCREEN_MODE_DEFINE( TILEMAP_MODE_32X24, 0, 32, 24, 16, 8, 8, "Alphanumeric 32 columns x 24 rows");
    SCREEN_MODE_DEFINE( TILEMAP_MODE_32X25, 0, 32, 25, 16, 8, 8, "Alphanumeric 32 columns x 25 rows");
    SCREEN_MODE_DEFINE( TILEMAP_MODE_32X28, 0, 32, 28, 16, 8, 8, "Alphanumeric 32 columns x 28 rows");
    SCREEN_MODE_DEFINE( TILEMAP_MODE_40X24, 0, 40, 24, 16, 8, 8, "Alphanumeric 40 columns x 24 rows");
    SCREEN_MODE_DEFINE( TILEMAP_MODE_40X28, 0, 40, 28, 16, 8, 8, "Alphanumeric 40 columns x 28 rows");
    SCREEN_MODE_DEFINE( TILEMAP_MODE_64X24, 0, 64, 24, 16, 8, 8, "Alphanumeric 64 columns x 24 rows");
    SCREEN_MODE_DEFINE( TILEMAP_MODE_64X25, 0, 64, 25, 16, 8, 8, "Alphanumeric 64 columns x 25 rows");
    SCREEN_MODE_DEFINE( TILEMAP_MODE_64X28, 0, 64, 28, 16, 8, 8, "Alphanumeric 64 columns x 28 rows");
    SCREEN_MODE_DEFINE( TILEMAP_MODE_80X24, 0, 80, 24, 16, 8, 8, "Alphanumeric 80 columns x 24 rows");
    SCREEN_MODE_DEFINE( TILEMAP_MODE_80X25, 0, 80, 25, 16, 8, 8, "Alphanumeric 80 columns x 25 rows");
    SCREEN_MODE_DEFINE( TILEMAP_MODE_80X28, 0, 80, 28, 16, 8, 8, "Alphanumeric 80 columns x 28 rows");

    SCREEN_MODE_DEFINE( BITMAP_MODE_320x200x16, 1, 320, 200, 16, 8, 8, "Graphic 320x200x16");
    SCREEN_MODE_DEFINE( BITMAP_MODE_128x192x2, 1, 128, 192, 2, 8, 8, "Graphic 128x192x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_128x200x2, 1, 128, 200, 2, 8, 8, "Graphic 128x200x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_128x225x2, 1, 128, 225, 2, 8, 8, "Graphic 128x225x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_64x192x4, 1, 64, 192, 4, 8, 8, "Graphic 64x192x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_64x200x4, 1, 64, 200, 4, 8, 8, "Graphic 64x200x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_64x225x4, 1, 64, 225, 4, 8, 8, "Graphic 64x225x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_160x192x2, 1, 160, 192, 2, 8, 8, "Graphic 160x192x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_160x200x2, 1, 160, 200, 2, 8, 8, "Graphic 160x200x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_160x225x2, 1, 160, 225, 2, 8, 8, "Graphic 160x225x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_80x192x4, 1, 80, 192, 4, 8, 8, "Graphic 80x192x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_80x200x4, 1, 80, 200, 4, 8, 8, "Graphic 80x200x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_80x225x4, 1, 80, 225, 4, 8, 8, "Graphic 80x225x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_256x192x2, 1, 256, 192, 2, 8, 8, "Graphic 256x192x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_256x200x2, 1, 256, 200, 2, 8, 8, "Graphic 256x200x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_256x225x2, 1, 256, 225, 2, 8, 8, "Graphic 256x225x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_128x192x4, 1, 128, 192, 4, 8, 8, "Graphic 128x192x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_128x200x4, 1, 128, 200, 4, 8, 8, "Graphic 128x200x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_128x225x4, 1, 128, 225, 4, 8, 8, "Graphic 128x225x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_64x192x16, 1, 64, 192, 16, 8, 8, "Graphic 64x192x16");
    SCREEN_MODE_DEFINE( BITMAP_MODE_64x200x16, 1, 64, 200, 16, 8, 8, "Graphic 64x200x16");
    SCREEN_MODE_DEFINE( BITMAP_MODE_64x225x16, 1, 64, 225, 16, 8, 8, "Graphic 64x225x16");
    SCREEN_MODE_DEFINE( BITMAP_MODE_320x192x2, 1, 320, 192, 2, 8, 8, "Graphic 320x192x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_320x200x2, 1, 320, 200, 2, 8, 8, "Graphic 320x200x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_320x225x2, 1, 320, 225, 2, 8, 8, "Graphic 320x225x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_160x192x4, 1, 160, 192, 4, 8, 8, "Graphic 160x192x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_160x200x4, 1, 160, 200, 4, 8, 8, "Graphic 160x200x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_160x225x4, 1, 160, 225, 4, 8, 8, "Graphic 160x225x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_80x192x16, 1, 80, 192, 16, 8, 8, "Graphic 80x192x16");
    SCREEN_MODE_DEFINE( BITMAP_MODE_80x200x16, 1, 80, 200, 16, 8, 8, "Graphic 80x200x16");
    SCREEN_MODE_DEFINE( BITMAP_MODE_80x225x16, 1, 80, 225, 16, 8, 8, "Graphic 80x225x16");
    SCREEN_MODE_DEFINE( BITMAP_MODE_512x192x2, 1, 512, 192, 2, 8, 8, "Graphic 512x192x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_512x200x2, 1, 512, 200, 2, 8, 8, "Graphic 512x200x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_512x225x2, 1, 512, 225, 2, 8, 8, "Graphic 512x225x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_256x192x4, 1, 256, 192, 4, 8, 8, "Graphic 256x192x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_256x200x4, 1, 256, 200, 4, 8, 8, "Graphic 256x200x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_256x225x4, 1, 256, 225, 4, 8, 8, "Graphic 256x225x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_128x192x16, 1, 128, 192, 16, 8, 8, "Graphic 128x192x16");
    SCREEN_MODE_DEFINE( BITMAP_MODE_128x200x16, 1, 128, 200, 16, 8, 8, "Graphic 128x200x16");
    SCREEN_MODE_DEFINE( BITMAP_MODE_128x225x16, 1, 128, 225, 16, 8, 8, "Graphic 128x225x16");
    SCREEN_MODE_DEFINE( BITMAP_MODE_640x192x2, 1, 640, 192, 2, 8, 8, "Graphic 640x192x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_640x200x2, 1, 640, 200, 2, 8, 8, "Graphic 640x200x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_640x225x2, 1, 640, 225, 2, 8, 8, "Graphic 640x225x2");
    SCREEN_MODE_DEFINE( BITMAP_MODE_320x192x4, 1, 320, 192, 4, 8, 8, "Graphic 320x192x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_320x200x4, 1, 320, 200, 4, 8, 8, "Graphic 320x200x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_320x225x4, 1, 320, 225, 4, 8, 8, "Graphic 320x225x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_160x192x16, 1, 160, 192, 16, 8, 8, "Graphic 160x192x16");
    SCREEN_MODE_DEFINE( BITMAP_MODE_160x200x16, 1, 160, 200, 16, 8, 8, "Graphic 160x200x16");
    SCREEN_MODE_DEFINE( BITMAP_MODE_160x225x16, 1, 160, 225, 16, 8, 8, "Graphic 160x225x16");
    SCREEN_MODE_DEFINE( BITMAP_MODE_512x192x4, 1, 512, 192, 4, 8, 8, "Graphic 512x192x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_512x200x4, 1, 512, 200, 4, 8, 8, "Graphic 512x200x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_512x225x4, 1, 512, 225, 4, 8, 8, "Graphic 512x225x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_256x192x16, 1, 256, 192, 16, 8, 8, "Graphic 256x192x16");
    SCREEN_MODE_DEFINE( BITMAP_MODE_256x200x16, 1, 256, 200, 16, 8, 8, "Graphic 256x200x16");
    SCREEN_MODE_DEFINE( BITMAP_MODE_256x225x16, 1, 256, 225, 16, 8, 8, "Graphic 256x225x16");
    SCREEN_MODE_DEFINE( BITMAP_MODE_640x192x4, 1, 640, 192, 4, 8, 8, "Graphic 640x192x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_640x200x4, 1, 640, 200, 4, 8, 8, "Graphic 640x200x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_640x225x4, 1, 640, 225, 4, 8, 8, "Graphic 640x225x4");
    SCREEN_MODE_DEFINE( BITMAP_MODE_320x192x16, 1, 320, 192, 16, 8, 8, "Graphic 320x192x16");
    SCREEN_MODE_DEFINE( BITMAP_MODE_320x225x16, 1, 320, 225, 16, 8, 8, "Graphic 320x225x16");

    outline0("JSR GIMESTARTUP");

    variable_import( _environment, "XGR", VT_POSITION, 0 );
    variable_global( _environment, "XGR" );
    variable_import( _environment, "YGR", VT_POSITION, 0 );
    variable_global( _environment, "YGR" );
    variable_import( _environment, "LINE", VT_WORD, (unsigned short)(0xffff) );
    variable_global( _environment, "LINE" );
    variable_import( _environment, "TABCOUNT", VT_BYTE, 4 );
    variable_global( _environment, "TABCOUNT" );

    variable_import( _environment, "CLIPX1", VT_POSITION, 0 );
    variable_global( _environment, "CLIPX1" );
    variable_import( _environment, "CLIPX2", VT_POSITION, 255 );
    variable_global( _environment, "CLIPX2" );
    variable_import( _environment, "CLIPY1", VT_POSITION, 0 );
    variable_global( _environment, "CLIPY1" );
    variable_import( _environment, "CLIPY2", VT_POSITION, 127 );
    variable_global( _environment, "CLIPY2" );

    variable_import( _environment, "ORIGINX", VT_POSITION, 0 );
    variable_global( _environment, "ORIGINX" );
    variable_import( _environment, "ORIGINY", VT_POSITION, 0 );
    variable_global( _environment, "ORIGINY" );
    variable_import( _environment, "RESOLUTIONX", VT_POSITION, 0 );
    variable_global( _environment, "RESOLUTIONX" );
    variable_import( _environment, "RESOLUTIONY", VT_POSITION, 0 );
    variable_global( _environment, "RESOLUTIONY" );

    _environment->fontWidth = 8;
    _environment->fontHeight = 8;
    _environment->screenTilesWidth = 40;
    _environment->screenTilesHeight = 25;
    _environment->screenTiles = 128;
    _environment->screenWidth = _environment->screenTilesWidth*_environment->fontWidth;
    _environment->screenHeight = _environment->screenTilesHeight*_environment->fontHeight;
    _environment->screenShades = 16;
    _environment->screenColors = 16;

    gime_tilemap_enable( _environment, 40, 25, 16, 8, 8 );

    gime_cls( _environment );

}

void gime_finalization( Environment * _environment ) {

}

void gime_hscroll_line( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_gime_hscroll_text_asm );

    Variable * y = variable_retrieve( _environment, "YCURSYS" );
    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );
    outline1("LDA %s", y->realName );
    outline0("STA CLINEY");

    outline0("JSR HSCROLLLT");    


}

void gime_hscroll_screen( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_gime_hscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );

    outline0("JSR HSCROLLST");    

}

void gime_back( Environment * _environment ) {

}

void gime_cline( Environment * _environment, char * _characters ) {

    deploy( textCline, src_hw_gime_cline_asm );
    Variable * x = variable_retrieve( _environment, "XCURSYS" );
    Variable * y = variable_retrieve( _environment, "YCURSYS" );

    if ( _characters ) {
        outline1("LDA %s", _characters);
    } else {
        outline0("LDA #0");
    }
    outline0("STA CHARACTERS");
    outline1("LDA %s", x->realName );
    outline0("STA CLINEX" );
    outline1("LDA %s", y->realName );
    outline0("STA CLINEY");
    outline0("JSR CLINE");

}

static int calculate_image_size( Environment * _environment, int _width, int _height, int _mode ) {

    // switch( _mode ) {
    //     case TILEMAP_MODE_40X25:         // Alphanumeric Internal	32 × 16	2	512
    //         break;
    // }

    return 0;

}

Variable * gime_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

    // switch( _mode ) {
    //     case TILEMAP_MODE_INTERNAL:         // Alphanumeric Internal	32 × 16	2	512
    //         break;
    // }

    WARNING_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

    return gime_new_image( _environment, 8, 8, BITMAP_MODE_DEFAULT );

}

static void gime_load_image_address_to_register( Environment * _environment, char * _register, char * _source, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

}

void gime_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {
    
}

void gime_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {
    
}

Variable * gime_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    int size = calculate_image_size( _environment, _width, _height, _mode );

    if ( ! size ) {
        CRITICAL_NEW_IMAGE_UNSUPPORTED_MODE( _mode );
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(new image)" );

    char * buffer = malloc ( size );
    memset( buffer, 0, size );

    *(buffer) = _width;
    *(buffer+1) = _height;

    result->valueBuffer = buffer;
    result->size = size;
    
    return result;

}

void gime_get_image( Environment * _environment, char * _image, char * _x, char * _y, int _palette ) {

}

void gime_scroll( Environment * _environment, int _dx, int _dy ) {

}

void gime_put_tile( Environment * _environment, char * _tile, char * _x, char * _y ) {

}

void gime_tile_at( Environment * _environment, char * _x, char * _y, char * _result ) {

}

void gime_move_tiles( Environment * _environment, char * _tile, char * _x, char * _y ) {

}

void gime_put_tiles( Environment * _environment, char * _tile, char * _x, char * _y, char *_w, char *_h ) {


}

void gime_use_tileset( Environment * _environment, char * _tileset ) {

}

Variable * gime_get_raster_line( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_WORD, "(raster line)" );

    return result;
    
}

void gime_slice_image( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination ) {

}

int gime_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette ) {

    int paletteColorCount = rgbi_extract_palette(_environment, _data, _width, _height, _depth, _palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    memcpy( _palette, palette_match( _palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) ), paletteColorCount * sizeof( RGBi ) );

    int uniquePaletteCount = 0;

    memcpy( _palette, palette_remove_duplicates( _palette, paletteColorCount, &uniquePaletteCount ), paletteColorCount * sizeof( RGBi ) );

    return uniquePaletteCount;

}

#endif