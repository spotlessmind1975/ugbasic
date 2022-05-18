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

#if defined(__msx1__) || defined(__coleco__) || defined(__sc3000__) || defined(__sg1000__)

#include "../ugbc.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
        { 0x00, 0x00, 0x00, 1, "BLACK" },
        { 0x00, 0x00, 0x00, 0, "TRANSPARENT" },
        { 0x00, 0x80, 0x00, 2, "GREEN" },
        { 0x00, 0xff, 0x00, 3, "LIGHT_GREEN" },
        { 0x00, 0x00, 0x80, 4, "DARK_BLUE" },
        { 0x00, 0x00, 0xff, 5, "LIGHT_BLUE" },
        { 0x80, 0x00, 0x00, 6, "DARK_RED" },
        { 0x00, 0xff, 0xff, 7, "CYAN" },
        { 0x80, 0x00, 0x00, 8, "RED" },
        { 0xff, 0x00, 0x00, 9, "LIGHT_RED" },
        { 0xff, 0xff, 0x20, 10, "DARK_YELLOW" },
        { 0xff, 0xff, 0xee, 11, "LIGHT_YELLOW" },
        { 0x00, 0x40, 0x00, 12, "DARK_GREEN" },
        { 0xaa, 0x00, 0xaa, 13, "MAGENTA" },
        { 0xaa, 0xaa, 0xaa, 14, "GRAY" },
        { 0xff, 0xff, 0xff, 15, "WHITE" }
};

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

RGBi * tms9918_image_nearest_system_color( RGBi * _color ) {

    int minDistance = 0xffff;
    int colorIndex = 0;
    for (int j = 0; j < COLOR_COUNT; ++j) {
        int distance = rgbi_distance(&SYSTEM_PALETTE[j], _color);
        if (distance < minDistance) {
            minDistance = distance;
            colorIndex = j;
        }
    }

    return &SYSTEM_PALETTE[colorIndex];

}

/**
 * This method can be used to convert 
 *     8x8 RGB (3 bytes) pixel (_source) [8x8x3 = 192 bytes]
 * into 
 *     8x8 bitmap (1 bit) pixel + 8 (byte) [8x1 + 8 = 16 bytes]
 *       foreground and background color (_dest)
 * 
 * Since the 8x8 pixel area belong to a larger picture,
 * this function will need the picture _width in order
 * to move to the next line to analyze.
 */
static void tms9918_image_converter_tile( char * _source, char * _dest, int _width, int _source_width ) {

    int colorIndexesCount[COLOR_COUNT];

    int colorBackgroundMax = 0;
    int colorBackground[8];
    memset( colorBackground, 0, 8 );
    
    int colorForegroundMax = 0;
    int colorForeground[8];
    memset( colorForeground, 0, 8 );

    char * source = _source;

    // Clear the box and colors
    memset( _dest, 0, 16 );

    // Loop for all the box surface
    for (int y=0; y<8; ++y) {

        memset(colorIndexesCount, 0, COLOR_COUNT * sizeof( int ) );
        colorBackgroundMax = 0;
        colorForegroundMax = 0;

        for (int x=0; x<8; ++x) {

            RGBi rgb;

            memset( &rgb, 0, sizeof( RGBi ) );

            // Take the color of the pixel
            rgb.red = *source;
            rgb.green = *(source + 1);
            rgb.blue = *(source + 2);

            RGBi *systemRgb = tms9918_image_nearest_system_color( &rgb );

            ++colorIndexesCount[systemRgb->index];

            source += 3;

        }

        for( int xx = 0; xx<COLOR_COUNT; ++xx ) {
            if ( colorIndexesCount[xx] > colorBackgroundMax ) {
                colorBackground[y] = xx;
                colorBackgroundMax = colorIndexesCount[xx];
            };
        }

        colorIndexesCount[colorBackground[y]] = 0;

        for( int xx = 0; xx<COLOR_COUNT; ++xx ) {
            if ( colorIndexesCount[xx] > colorForegroundMax ) {
                colorForeground[y] = xx;
                colorForegroundMax = colorIndexesCount[xx];
            };
        }

        source += 3 * ( _source_width - 8 );

    }

    source = _source;

    for (int y=0; y<8; ++y) {
        for (int x=0; x<8; ++x) {

            RGBi rgb;

            memset( &rgb, 0, sizeof( RGBi ) );

            rgb.red = *source;
            rgb.green = *(source + 1);
            rgb.blue = *(source + 2);

            RGBi *systemRgb = tms9918_image_nearest_system_color( &rgb );

            char bitmask = 1 << ( 7 - ((x) & 0x7) );

            if ( systemRgb->index != colorBackground[y] ) {
                *( _dest + y ) |= bitmask;
                // printf("*");
            } else {
                *( _dest + y ) &= ~bitmask;
                // printf(" ");
            }

            source += 3;

        }

        source += 3 * ( _source_width - 8 );

    }

    for( int i=0; i<8; ++i ) {
        *( _dest + 8 + i ) = ( colorForeground[i] << 4 ) | colorBackground[i] ;
    }

}

/**
 * This method can be used to convert 
 *     WxH RGB (3 bytes) pixel (_source) [WxHx3 bytes]
 * into 
 *     WxH bitmap (1 bit) pixel + (W/8xH + W/8xH) (bytes)
 *       foreground and background color (_dest)
 * 
 * Since the WXH pixel area could belong to a larger picture,
 * this function will need the picture _source_width in order
 * to move to the next line to analyze.
 */
static void tms9918_image_converter_tiles( char * _source, char * _dest, int _width, int _height, int _source_width ) {

    int bitmapSize = ( _width>>3 ) * _height;
    int colormapSize = ( _width>>3 ) * _height;

    memset( _dest, 0, bitmapSize + colormapSize );

    for( int y=0; y<_height; y+=8 ) {
        for( int x=0; x<_width; x+=8 ) {

            char * source = _source + ( ( y * _source_width ) + x ) * 3;
            char tile[16];

            tms9918_image_converter_tile( source, tile, _width, _source_width );

            int offset = ((y>>3) * 8 *( _width >> 3 ) ) + ((x>>3) * 8) + ((y) & 0x07);
            // x = 8, y = 8
            // offset = ((8 >> 3) * 8 * (16>>3) ) + ((8>>3) * 8) + ((8) & 7)
            // offset = (1 * 8 * 2 ) + (1 * 8)
            // offset = 16 + 8 = 24

            char * destBitmap = _dest + offset;
            char * destColormap = _dest + bitmapSize + offset;
            for( int i=0; i<8; ++i ) {
                *destBitmap = tile[i];
                *destColormap = tile[i+8];
                ++destBitmap;
                ++destColormap;
            }
        }
    }
}

/**
 * @brief <i>TMS9918</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with another sprite. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable.
 * 
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
Variable * tms9918_collision( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(collision)" );

    deploy( sprite, src_hw_tms9918_sprites_asm );
    
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL SPRITECOL");
    } else {
        outline0("CALL SPRITECOLNMI2");
    }

    outline1("LD (%s), A", result->realName )

    return result;
    
}

/**
 * @brief <i>TMS9918</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with a tile. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable.
 * *
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void tms9918_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

    //todo

}

/**
 * @brief <i>TMS9918</i>: emit code to change border color
 * 
 * This function can be used to issue code aimed at changing the
 * border color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _border_color Border color to use
 */
void tms9918_border_color( Environment * _environment, char * _border_color ) {

// #ifdef __coleco__
//     MAKE_LABEL
//     if ( ! _environment->hasGameLoop ) {
//         outline1("JP %sskip", label );
//         outhead1("%s:", label );
//     }
// #endif
    outline1("LD E, %2.2x", VDP_RCOLOR );
    outline0("CALL VDPREGIN" );
    outline0("AND $F0" );
    outline0("LD B, A" );
    outline1("LD E, %2.2x", VDP_RCOLOR );
    outline1("LD A, (%s)", _border_color );
    outline0("AND $0F" );
    outline0("OR B" );
    outline0("CALL VDPSETREG" );
// #ifdef __coleco__
//     if ( ! _environment->hasGameLoop ) {
//         outline0("RET" );
//         outhead1("%sskip:", label );
//         outline0("CALL WAIT_VDP_HOOK" );
//         outline1("LD HL, %s", label );
//         outline0("CALL SET_VDP_HOOK0" );
//         outline0("CALL WAIT_VDP_HOOK" );
//     }
// #endif

}

/**
 * @brief <i>TMS9918</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void tms9918_background_color( Environment * _environment, int _index, int _background_color ) {

    char value[MAX_TEMPORARY_STORAGE]; sprintf( value, "$%2.2x", _background_color );

    tms9918_background_color_vars( _environment, NULL, value );
    
}

/**
 * @brief <i>TMS9918</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void tms9918_background_color_vars( Environment * _environment, char * _index, char * _background_color ) {

    _index = 0;

    tms9918_border_color( _environment, _background_color );

}

/**
 * @brief <i>TMS9918</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void tms9918_background_color_semivars( Environment * _environment, int _index, char * _background_color ) {

    _index = 0;

    tms9918_border_color( _environment, _background_color );

}

/**
 * @brief <i>TMS9918</i>: emit code to retrieve background color
 * 
 * This function can be used to issue code aimed at retrieving the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void tms9918_background_color_get_vars( Environment * _environment, char * _index, char * _background_color ) {

    //TODO

}

/**
 * @brief <i>TMS9918</i>: emit code to change common sprite's color 
 * 
 * This function can be used to issue code aimed at changing the
 * common color of the sprites.

 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _common_color Index of the color to use
 */
void tms9918_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {

// #ifdef __coleco__
//     MAKE_LABEL
//     if ( ! _environment->hasGameLoop ) {
//         outline1("JP %sskip", label );
//         outhead1("%s:", label );
//     }
// #endif
    outline0("LD HL, $1000");
    outline1("LD E, (%s)", _index );
    outline0("SLA E");
    outline0("SLA E");
    outline0("INC E");
    outline0("INC E");
    outline0("INC E");
    outline0("LD D, 0");
    outline0("ADD HL, DE");
    outline0("CALL VDPINCHAR");
    outline0("AND $F0");
    outline0("LD B, A");
    outline1("LD A, (%s)", _common_color );
    outline0("OR B");
    outline0("CALL VDPOUTCHAR");
// #ifdef __coleco__
//     if ( ! _environment->hasGameLoop ) {
//         outline0("RET" );
//         outhead1("%sskip:", label );
//         outline0("CALL WAIT_VDP_HOOK" );
//         outline1("LD HL, %s", label );
//         outline0("CALL SET_VDP_HOOK0" );
//         outline0("CALL WAIT_VDP_HOOK" );
//     }
// #endif

}

/**
 * @brief <i>TMS9918</i>: emit code to set raster irq
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
void tms9918_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>TMS9918</i>: emit code to wait for next raster irq
 * 
 * This function outputs assembly code needed to wait for the
 * next raster. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 *
 */
void tms9918_next_raster( Environment * _environment ) {

}

/**
 * @brief <i>TMS9918</i>: emit code to wait for next raster irq at different position
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
void tms9918_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>TMS9918</i>: emit code to enable ECM
 * 
 * @param _environment Current calling environment
 */
void tms9918_enable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>TMS9918</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void tms9918_disable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>TMS9918</i>: emit code to enable MCM
 * 
 * @param _environment Current calling environment
 */
void tms9918_enable_mcm( Environment * _environment ) {

}

/**
 * @brief <i>TMS9918</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void tms9918_disable_mcm( Environment * _environment ) {

}

void tms9918_bank_select( Environment * _environment, int _bank ) {
    
}

static int rgbConverterFunction( int _red, int _green, int _blue ) {
    
    int colorIndex = 0;
    int minDistance = 0xffffffff;
    int j;

    RGBi rgb;
    rgb.red = _red;
    rgb.green = _green;
    rgb.blue = _blue;

    for (j = 0; j < sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++j) {
        int distance = rgbi_distance(&SYSTEM_PALETTE[j], &rgb);
        if (distance < minDistance) {
            minDistance = distance;
            colorIndex = j;
        }
    }

    return colorIndex;

}

int tms9918_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    cpu_store_8bit( _environment, "_PEN", DEFAULT_PEN_COLOR );
    cpu_store_8bit( _environment, "_PAPER", DEFAULT_PAPER_COLOR );

// #ifdef __coleco__

//     MAKE_LABEL
        
//     if ( ! _environment->hasGameLoop ) {
//         outline1("JP %sdone", label );
//         outhead1("%s:", label );
//     }

// #endif

    switch( _screen_mode->id ) {
        // M1 M2 M3 Display Mode
        // 0  0  0  Graphics I Mode
        // 0  0  1  Graphics II Mode
        // 0  1  0  Multicolor Mode
        // 1  0  0  Text Mode
        case TILEMAP_MODE_STANDARD:
            _environment->fontWidth = 6;
            _environment->fontHeight = 8;
            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 24;
            _environment->screenTiles = 255;
            _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
            _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
            _environment->screenColors = 16;

            // M3 = 0
            WVDP_R0( 0x00 );
            //  1 + = Selects 16K bytes of VRAM.
            //  2 + = Enables the active display
            //  4 + = Enables VDP interrupt
            //  8 + = M1 x 1 = 8
            //      = M2 x 0 = 0
            //      = Reserved Bit (must be set to O)
            //      = Selects Size 0 sprites (8x8 pixels)
            //      = Selects no magnification
            WVDP_R1( 0xb0 );

            // Register 2 tells the VDP where the starting address of the Name Table is located in VRAM. The
            // range of its contents is from O-F. The contents of the register form the upper four bits of
            // the 14-bit VDP address, therefore making the location of the Name Table in VRAM equal to
            // (Register 2) * 400 (Hex)
            WVDP_RNAME( 0x06 );

            // Register 4 tells the VDP where the starting address of the Pattern Table is located in VRAM.
            // The range of its contents is from 0-7. The contents of the register form the upper three bits of
            // the 14 bit VDP address, therefore making the location of the Pattern Table in VRAM equal to
            // (Register 4) * 800 (Hex).
            // 5-3
            // NOTE
            // Register 4 functions differently when the VDP is in Graphics II Mode. In this
            // mode the Pattern Table can only be located in one of two places in VRAM, either
            // Hex 0000 or Hex 2000. If Hex 0000 is where you wish the Pattern Table to
            // be located, then the MSB in Register 4 has to be a 0. If Hex 2000 is the location
            // choice for your Pattern Generator Table, then the MSB in Register 4 must be a
            // 1. In either case, all the LSBs in Register 4 must be set to ls. Therefore, in
            // Graphics II Mode the only two values that work correctly in Register 4 are Hex
            // 03 and Hex 07.
            WVDP_RPATTERN( 0x00 );

            WVDP_RSPRITEA( 0xff );
            WVDP_RSPRITEP( 0xff );

            outline0("CALL TMS9918AUDCCHAR01");

            WVDP_R1( 0xf0 );

            break;
        case TILEMAP_MODE_GRAPHIC1:
            _environment->fontWidth = 8;
            _environment->fontHeight = 8;
            _environment->screenTilesWidth = 32;
            _environment->screenTilesHeight = 24;
            _environment->screenTiles = 255;
            _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
            _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
            _environment->screenColors = 16;    

            // M3 = 0
            WVDP_R0( 0x00 );
            //  1 + = Selects 16K bytes of VRAM.
            //  2 + = Enables the active display
            //  4 + = Enables VDP interrupt
            //  8 + = M1 x 0 = 0
            //      = M2 x 0 = 0
            //      = Reserved Bit (must be set to O)
            //      = Selects Size 0 sprites (8x8 pixels)
            //      = Selects no magnification
            WVDP_R1( 0xa0 );

            // Register 2 tells the VDP where the starting address of the Name Table is located in VRAM. The
            // range of its contents is from O-F. The contents of the register form the upper four bits of
            // the 14-bit VDP address, therefore making the location of the Name Table in VRAM equal to
            // (Register 2) * 400 (Hex)
            WVDP_RNAME( 0x06 );

            // Register 3 tells the VDP where the starting address of the Color Table is located in VRAM. The
            // range of its contents is from O-FF. The contents of the register form the upper eight bits of
            // the 14-bit VDP address, therefore making the. location of the Color Table in VRAM equal to
            // (Register 3) * 40 (Hex).
            // NOTE
            // Register 3 functions differently when the VDP is in Graphics II Mode. In this
            // mode the Color Table can only be located ~n one of two places in VRAM, either
            // Hex 0000 or Hex 2000. If Hex 0000 is where you wish the Color Table to be
            // located, then the MSB in Register 3 has to be a O. If Hex 2000 is the location
            // choice for your Color Table, then the MSB in Register 3 must be a 1. In either
            // case, all the LSBs in Register 3 must be set to ls. Therefore, in Graphics II
            // Mode the only two values that work correctly in Register 3 are Hex 7F and Hex
            // FF.
            WVDP_RCOLORTABLE( 0x12 );

            // Register 4 tells the VDP where the starting address of the Pattern Table is located in VRAM.
            // The range of its contents is from 0-7. The contents of the register form the upper three bits of
            // the 14 bit VDP address, therefore making the location of the Pattern Table in VRAM equal to
            // (Register 4) * 800 (Hex).
            // 5-3
            // NOTE
            // Register 4 functions differently when the VDP is in Graphics II Mode. In this
            // mode the Pattern Table can only be located in one of two places in VRAM, either
            // Hex 0000 or Hex 2000. If Hex 0000 is where you wish the Pattern Table to
            // be located, then the MSB in Register 4 has to be a 0. If Hex 2000 is the location
            // choice for your Pattern Generator Table, then the MSB in Register 4 must be a
            // 1. In either case, all the LSBs in Register 4 must be set to ls. Therefore, in
            // Graphics II Mode the only two values that work correctly in Register 4 are Hex
            // 03 and Hex 07.
            WVDP_RPATTERN( 0x0 );

            WVDP_RSPRITEA( 0x20 ); // 1000
            WVDP_RSPRITEP( 0x00 ); // 0000

            outline0("CALL TMS9918AUDCCHAR01");

            WVDP_R1( 0xe0 );

            break;
        case BITMAP_MODE_GRAPHIC2:
        case BITMAP_MODE_MULTICOLOR:
            _environment->fontWidth = 8;
            _environment->fontHeight = 8;
            _environment->screenTilesWidth = 32;
            _environment->screenTilesHeight = 24;
            _environment->screenTiles = 255;
            _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
            _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
            _environment->screenColors = 16;    

            // M3 = 1
            WVDP_R0( 0x02 );
            //  1 + = Selects 16K bytes of VRAM.
            //  2 + = Enables the active display
            //  4 + = Enables VDP interrupt
            //  8 + = M1 x 0 = 0
            //      = M2 x 0 = 0
            //      = Reserved Bit (must be set to O)
            //      = Selects Size 0 sprites (8x8 pixels)
            //      = Selects no magnification
            WVDP_R1( 0x80 );

            // Register 2 tells the VDP where the starting address of the Name Table is located in VRAM. The
            // range of its contents is from O-F. The contents of the register form the upper four bits of
            // the 14-bit VDP address, therefore making the location of the Name Table in VRAM equal to
            // (Register 2) * 400 (Hex)
            WVDP_RNAME( 0x0e );

            // Register 3 tells the VDP where the starting address of the Color Table is located in VRAM. The
            // range of its contents is from O-FF. The contents of the register form the upper eight bits of
            // the 14-bit VDP address, therefore making the. location of the Color Table in VRAM equal to
            // (Register 3) * 40 (Hex).
            // NOTE
            // Register 3 functions differently when the VDP is in Graphics II Mode. In this
            // mode the Color Table can only be located ~n one of two places in VRAM, either
            // Hex 0000 or Hex 2000. If Hex 0000 is where you wish the Color Table to be
            // located, then the MSB in Register 3 has to be a O. If Hex 2000 is the location
            // choice for your Color Table, then the MSB in Register 3 must be a 1. In either
            // case, all the LSBs in Register 3 must be set to ls. Therefore, in Graphics II
            // Mode the only two values that work correctly in Register 3 are Hex 7F and Hex
            // FF.
            WVDP_RCOLORTABLE( 0xff );

            // Register 4 tells the VDP where the starting address of the Pattern Table is located in VRAM.
            // The range of its contents is from 0-7. The contents of the register form the upper three bits of
            // the 14 bit VDP address, therefore making the location of the Pattern Table in VRAM equal to
            // (Register 4) * 800 (Hex).
            // 5-3
            // NOTE
            // Register 4 functions differently when the VDP is in Graphics II Mode. In this
            // mode the Pattern Table can only be located in one of two places in VRAM, either
            // Hex 0000 or Hex 2000. If Hex 0000 is where you wish the Pattern Table to
            // be located, then the MSB in Register 4 has to be a 0. If Hex 2000 is the location
            // choice for your Pattern Generator Table, then the MSB in Register 4 must be a
            // 1. In either case, all the LSBs in Register 4 must be set to ls. Therefore, in
            // Graphics II Mode the only two values that work correctly in Register 4 are Hex
            // 03 and Hex 07.
            WVDP_RPATTERN( 0x03 );

            WVDP_RSPRITEA( 0x76 ); // 1000
            WVDP_RSPRITEP( 0x03 ); // 0000

            outline0("CALL TMS9918AUDCCHAR23");

            WVDP_R1( 0xe0 );

            break;
    }

    cpu_store_16bit( _environment, "CLIPX1", 0 );
    cpu_store_16bit( _environment, "CLIPX2", (_environment->screenWidth-1) );
    cpu_store_16bit( _environment, "CLIPY1", 0 );
    cpu_store_16bit( _environment, "CLIPY2", (_environment->screenHeight-1) );

    cpu_store_16bit( _environment, "CURRENTWIDTH", _environment->screenWidth );
    cpu_store_16bit( _environment, "CURRENTHEIGHT", _environment->screenHeight );
    cpu_store_8bit( _environment, "CURRENTTILES", _environment->screenTiles );
    cpu_store_8bit( _environment, "CURRENTTILESWIDTH", _environment->screenTilesWidth );
    cpu_store_8bit( _environment, "CURRENTTILESHEIGHT", _environment->screenTilesHeight );
    cpu_store_8bit( _environment, "FONTWIDTH", _environment->fontWidth );
    cpu_store_8bit( _environment, "FONTHEIGHT", _environment->fontHeight );

// #ifdef __coleco__

//     if ( ! _environment->hasGameLoop ) {
//         outline0("RET");
//         outline1("%sdone:", label );
//         outline0("CALL WAIT_VDP_HOOK" );
//         outline1("LD HL, %s", label );
//         outline0("CALL SET_VDP_HOOK0" );
//         outline0("CALL WAIT_VDP_HOOK");
//     }
    
// #endif

    // printf("tms9918_tilemap_enable() -> screen tiles width %d\n", _environment->screenTilesWidth );

}

void tms9918_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors, 8, 8 );

    if ( mode ) {
        tms9918_screen_mode_enable( _environment, mode );

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 0 );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 0;

        tms9918_cls( _environment );

    } else {
        WARNING_SCREEN_MODE( -1 );
    }
}

void tms9918_bitmap_disable( Environment * _environment ) {

    //todo

}

void tms9918_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors, _tile_width, _tile_height );

    if ( mode ) {

        // printf("tms9918_tilemap_enable() -> %d\n", mode->id );
        
        tms9918_screen_mode_enable( _environment, mode );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 1;

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 1 );

        tms9918_cls( _environment );

    } else {
        // printf("tms9918_tilemap_enable() -> -1\n" );
        WARNING_SCREEN_MODE( -1 );
    }

}

void tms9918_bitmap_at( Environment * _environment, char * _address ) {

}

void tms9918_colormap_at( Environment * _environment, char * _address ) {

}

void tms9918_textmap_at( Environment * _environment, char * _address ) {

}

void tms9918_point_at_int( Environment * _environment, int _x, int _y ) {

    deploy( tms9918vars, src_hw_tms9918_vars_asm);
    deploy( tms9918varsGraphic, src_hw_tms9918_vars_graphic_asm );
    deploy( plot, src_hw_tms9918_plot_asm );
    
    outline1("LD A, $%2.2x", ( _y & 0xff ) );
    outline0("LD D, A");
    outline1("LD A, $%2.2x", ( _x & 0xff ) );
    outline0("LD E, A");
    outline0("LD A, 1");
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL PLOT");
    } else {
        outline0("CALL PLOTNMI2");
    }

}

void tms9918_point_at_vars( Environment * _environment, char *_x, char *_y ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy( tms9918vars, src_hw_tms9918_vars_asm);
    deploy( tms9918varsGraphic, src_hw_tms9918_vars_graphic_asm );
    deploy( plot, src_hw_tms9918_plot_asm );
    
    outline1("LD A, (%s)", y->realName );
    outline0("LD D, A");
    outline1("LD A, (%s)", x->realName );
    outline0("LD E, A");
    outline0("LD A, 1");
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL PLOT");
    } else {
        outline0("CALL PLOTNMI2");
    }

}

void tms9918_point( Environment * _environment, char *_x, char *_y, char * _result ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );
    Variable * result = variable_retrieve( _environment, _result );

    deploy( tms9918vars, src_hw_tms9918_vars_asm);
    deploy( tms9918varsGraphic, src_hw_tms9918_vars_graphic_asm );
    deploy( plot, src_hw_tms9918_plot_asm );
    
    outline1("LD A, (%s)", y->realName );
    outline0("LD D, A");
    outline1("LD A, (%s)", x->realName );
    outline0("LD E, A");
    outline0("LD A, 3");
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL PLOT");
    } else {
        outline0("CALL PLOTNMI2");
    }    
    outline1("LD (%s), A", result->realName);

}

void tms9918_screen_on( Environment * _environment ) {

// #ifdef __coleco__
//     MAKE_LABEL
//     if ( ! _environment->hasGameLoop ) {
//         outline1("JP %sskip", label );
//         outhead1("%s:", label );
//     }
// #endif
    outline1("LD E, %2.2x", VDP_R1 );
    outline0("CALL VDPREGIN" );
    outline0("OR $40" );
    outline0("CALL VDPSETREG" );
// #ifdef __coleco__
//     if ( ! _environment->hasGameLoop ) {
//         outline0("RET" );
//         outhead1("%sskip:", label );
//         outline0("CALL WAIT_VDP_HOOK" );
//         outline1("LD HL, %s", label );
//         outline0("CALL SET_VDP_HOOK0" );
//         outline0("CALL WAIT_VDP_HOOK" );
//     }
// #endif

}

void tms9918_screen_off( Environment * _environment ) {

// #ifdef __coleco__
//     MAKE_LABEL
//     if ( ! _environment->hasGameLoop ) {
//         outline1("JP %sskip", label );
//         outhead1("%s:", label );
//     }
// #endif
    outline1("LD E, %2.2x", VDP_R1 );
    outline0("CALL VDPREGIN" );
    outline0("AND $BF" );
    outline0("CALL VDPSETREG" );
// #ifdef __coleco__
//     if ( ! _environment->hasGameLoop ) {
//         outline0("RET" );
//         outhead1("%sskip:", label );
//         outline0("CALL WAIT_VDP_HOOK" );
//         outline1("LD HL, %s", label );
//         outline0("CALL SET_VDP_HOOK0" );
//         outline0("CALL WAIT_VDP_HOOK" );
//     }
// #endif

}

void tms9918_screen_rows( Environment * _environment, char * _rows ) {

}

void tms9918_screen_columns( Environment * _environment, char * _columns ) {

}

void tms9918_sprite_data_from( Environment * _environment, char * _sprite, char * _image ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    Variable * image = variable_retrieve_or_define( _environment, _image, VT_IMAGE, 0 );

    deploy( sprite, src_hw_tms9918_sprites_asm );
    
    outline1("LD A, (%s)", sprite->realName );
    outline0("LD B, A");
    outline1("LD HL, %s", image->realName );
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL SPRITEDATAFROM");
    } else {
        outline0("CALL SPRITEDATAFROMNMI2");
    }

}

void tms9918_sprite_enable( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );

    deploy( sprite, src_hw_tms9918_sprites_asm );
    
    outline1("LD A, (%s)", sprite->realName );
    outline0("LD B, A");
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL SPRITEENABLE");
    } else {
        outline0("CALL SPRITEENABLENMI2");
    }

}

void tms9918_sprite_disable( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );

    deploy( sprite, src_hw_tms9918_sprites_asm );
    
    outline1("LD A, (%s)", sprite->realName );
    outline0("LD B, A");
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL SPRITEDISABLE");
    } else {
        outline0("CALL SPRITEDISABLENMI2");
    }

}

void tms9918_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );

    deploy( sprite, src_hw_tms9918_sprites_asm );
    
    outline1("LD A, (%s)", sprite->realName );
    outline0("LD B, A");
    outline1("LD A, (%s)", x->realName );
    outline0("LD H, A");
    outline1("LD A, (%s)", y->realName );
    outline0("LD L, A");
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL SPRITEAT");
    } else {
        outline0("CALL SPRITEATNMI2");
    }

}

void tms9918_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

    _sprite = NULL;

    deploy( sprite, src_hw_tms9918_sprites_asm );
    
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL SPRITEEXPAND");
    } else {
        outline0("CALL SPRITEEXPANDNMI2");
    }

}

void tms9918_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

    _sprite = NULL;

    deploy( sprite, src_hw_tms9918_sprites_asm );
    
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL SPRITEEXPAND");
    } else {
        outline0("CALL SPRITEEXPANDNMI2");
    }

}

void tms9918_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

    _sprite = NULL;

    deploy( sprite, src_hw_tms9918_sprites_asm );
    
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL SPRITECOMPRESS");
    } else {
        outline0("CALL SPRITECOMPRESSNMI2");
    }

}

void tms9918_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

    _sprite = NULL;

    deploy( sprite, src_hw_tms9918_sprites_asm );
    
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL SPRITECOMPRESS");
    } else {
        outline0("CALL SPRITECOMPRESSNMI2");
    }

}

void tms9918_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void tms9918_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void tms9918_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_WHITE );

    deploy( sprite, src_hw_tms9918_sprites_asm );
    
    outline1("LD A, (%s)", sprite->realName );
    outline0("LD B, A");
    outline1("LD A, (%s)", color->realName );
    outline0("LD C, A");
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL SPRITECOLOR");
    } else {
        outline0("CALL SPRITECOLORNMI2");
    }

}

void tms9918_tiles_at( Environment * _environment, char * _address ) {

}

void tms9918_vertical_scroll( Environment * _environment, char * _displacement ) {

}

void tms9918_horizontal_scroll( Environment * _environment, char * _displacement ) {

}

void tms9918_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline1("LD C, (%s)", _timing);
    outline0("CALL VDPREGIN");
    outhead1("%sfirst:", label );
    outline0("CALL VDPREGIN");
    outline0("AND $01");
    outline1("JP Z, %sfirst", label);
    outline0("DEC C");
    outline1("JP NZ, %sfirst", label);

}

void tms9918_get_width( Environment * _environment, char *_result ) {

    outline0("LD HL, (CURRENTWIDTH)" );
    outline1("LD (%s), HL", _result );

}

void tms9918_tiles_get( Environment * _environment, char *_result ) {

    outline0("LD A, (CURRENTTILES)" );
    outline1("LD (%s), A", _result );

}

void tms9918_tiles_get_width( Environment * _environment, char *_result ) {

    outline0("LD A, (CURRENTTILESWIDTH)" );
    outline1("LD (%s), A", _result );

}

void tms9918_get_height( Environment * _environment, char *_result ) {

    outline0("LD HL, (CURRENTHEIGHT)" );
    outline1("LD (%s), HL", _result );

}

void tms9918_tiles_get_height( Environment * _environment, char *_result ) {

    outline0("LD A, (CURRENTTILESHEIGHT)" );
    outline1("LD (%s), A", _result );

}

void tms9918_cls( Environment * _environment ) {
    
    if ( ( _environment->currentMode == 2 || _environment->currentMode == 3 ) && !_environment->currentTileMode ) {
        deploy( clsGraphic, src_hw_tms9918_cls_graphic_asm );
        if ( ! _environment->hasGameLoop ) {
            outline0("CALL CLSG");
        } else {
            outline0("CALL CLSGNMI2");
        }
    } else {
        deploy( clsText, src_hw_tms9918_cls_text_asm );
        if ( ! _environment->hasGameLoop ) {
            outline0("CALL CLST");
        } else {
            outline0("CALL CLSTNMI2");
        }
    }

}

void tms9918_scroll_text( Environment * _environment, int _direction ) {

    if ( _direction > 0 ) {
        deploy( vScrollTextDown, src_hw_tms9918_vscroll_text_down_asm );
        if ( ! _environment->hasGameLoop ) {
            outline0("CALL VSCROLLTDOWN");
        } else {
            outline0("CALL VSCROLLTDOWNNMI2");
        }
    } else {
        deploy( vScrollTextUp, src_hw_tms9918_vscroll_text_up_asm );
        if ( ! _environment->hasGameLoop ) {
            outline0("CALL VSCROLLTUP");
        } else {
            outline0("CALL VSCROLLTUPNMI2");
        }
    }

}

void tms9918_text( Environment * _environment, char * _text, char * _text_size ) {

    deploy( tms9918vars, src_hw_tms9918_vars_asm);
    deploy( vScrollTextUp, src_hw_tms9918_vscroll_text_up_asm );

    outline1("LD DE, (%s)", _text);
    outline1("LD A, (%s)", _text_size);
    outline0("LD C, A");

    if ( ( _environment->currentMode == 2 || _environment->currentMode == 3 ) && !_environment->currentTileMode ) {
        deploy( clsGraphic, src_hw_tms9918_cls_graphic_asm );
        deploy( tms9918varsGraphic, src_hw_tms9918_vars_graphic_asm );
        deploy( textEncodedAt, src_hw_tms9918_text_asm );
        deploy( textEncodedAtGraphic, src_hw_tms9918_text_at_graphic_asm );
        deploy( font, src_hw_tms9918_font_asm );
        if ( ! _environment->hasGameLoop ) {
            outline0("CALL TEXTATBITMAPMODE");
        } else {
            outline0("CALL TEXTATBITMAPMODENMI2");
        }
    } else {
        deploy( tms9918varsGraphic, src_hw_tms9918_vars_graphic_asm );
        deploy( clsText, src_hw_tms9918_cls_text_asm );
        #if defined(__sc3000__) || defined(__sg1000__)
                deploy( textEncodedAt, src_hw_tms9918_text_asm );
        #endif
        deploy( textEncodedAtText, src_hw_tms9918_text_at_text_asm );
        if ( ! _environment->hasGameLoop ) {
            outline0("CALL TEXTATTILEMODE");
        } else {
            outline0("CALL TEXTATTILEMODENMI2");
        }
    }

}

void tms9918_initialization( Environment * _environment ) {

    deploy( tms9918vars, src_hw_tms9918_vars_asm );
    deploy( tms9918startup, src_hw_tms9918_startup_asm );
    src_hw_chipset_mob_asm = src_hw_tms9918_mob_asm;
    src_hw_chipset_mob_asm_len = src_hw_tms9918_mob_asm_len;

    variable_import( _environment, "CURRENTWIDTH", VT_POSITION, 256 );
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION, 192  );
    variable_global( _environment, "CURRENTHEIGHT" );
    variable_import( _environment, "CURRENTTILES", VT_BYTE, 255 );
    variable_global( _environment, "CURRENTTILES" );
    variable_import( _environment, "CURRENTTILESWIDTH", VT_BYTE, 40 );
    variable_global( _environment, "CURRENTTILESWIDTH" );
    variable_import( _environment, "CURRENTTILESHEIGHT", VT_BYTE, 24 );
    variable_global( _environment, "CURRENTTILESHEIGHT" );
    variable_import( _environment, "FONTWIDTH", VT_BYTE, 8 );
    variable_global( _environment, "FONTWIDTH" );
    variable_import( _environment, "FONTHEIGHT", VT_BYTE, 8 );
    variable_global( _environment, "FONTHEIGHT" );

    SCREEN_MODE_DEFINE( TILEMAP_MODE_STANDARD, 0, 40, 24, 20, 6, 8, "Text Mode" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_GRAPHIC2, 0, 32, 24, 16, 8, 8, "Graphic II" );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_GRAPHIC1, 0, 32, 24, 16, 8, 8, "Graphic I" );

    SCREEN_MODE_DEFINE( BITMAP_MODE_GRAPHIC2, 1, 256, 192, 16, 8, 8, "Graphic II" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_MULTICOLOR, 1, 256, 192, 16, 8, 8, "Multicolor" );
 
    outline0("CALL TMS9918STARTUP");

    variable_import( _environment, "XGR", VT_POSITION, 0 );
    variable_global( _environment, "XGR" );
    variable_import( _environment, "YGR", VT_POSITION, 0 );
    variable_global( _environment, "YGR" );
    variable_import( _environment, "LINE", VT_WORD, (unsigned short)(0xffff) );
    variable_global( _environment, "LINE" );

    variable_import( _environment, "CLIPX1", VT_POSITION, 0 );
    variable_global( _environment, "CLIPX1" );
    variable_import( _environment, "CLIPX2", VT_POSITION, 255 );
    variable_global( _environment, "CLIPX2" );
    variable_import( _environment, "CLIPY1", VT_POSITION, 0 );
    variable_global( _environment, "CLIPY1" );
    variable_import( _environment, "CLIPY2", VT_POSITION, 191 );
    variable_global( _environment, "CLIPY2" );

    variable_import( _environment, "XCURSYS", VT_BYTE, 0 );
    variable_global( _environment, "XCURSYS" );
    variable_import( _environment, "YCURSYS", VT_BYTE, 0 );
    variable_global( _environment, "YCURSYS" );
    variable_import( _environment, "TABCOUNT", VT_BYTE, 4 );
    variable_global( _environment, "TABCOUNT" );

    variable_import( _environment, "CLINEX", VT_BYTE, 0 );
    variable_global( _environment, "CLINEX" );

    variable_import( _environment, "CLINEY", VT_BYTE, 0 );
    variable_global( _environment, "CLINEY" );

    variable_import( _environment, "TABSTODRAW", VT_BYTE, 0 );
    variable_global( _environment, "TABSTODRAW" );

    variable_import( _environment, "CURRENTMODE", VT_BYTE, 0 );
    variable_global( _environment, "CURRENTMODE" );
    variable_import( _environment, "CURRENTTILEMODE", VT_BYTE, 1 );
    variable_global( _environment, "CURRENTTILEMODE" );

    variable_import( _environment, "SPRITECOUNT", VT_SPRITE, 0 );
    variable_global( _environment, "SPRITECOUNT" );

    variable_import( _environment, "SPRITEXY", VT_BUFFER, SPRITE_COUNT * 2 );
    variable_global( _environment, "SPRITEXY" );

    variable_import( _environment, "TILEX", VT_BYTE, 0 );
    variable_global( _environment, "TILEX" );
    variable_import( _environment, "TILEY", VT_BYTE, 0 );
    variable_global( _environment, "TILEY" );
    variable_import( _environment, "TILEX2", VT_BYTE, 0 );
    variable_global( _environment, "TILEX2" );
    variable_import( _environment, "TILET", VT_BYTE, 0 );
    variable_global( _environment, "TILET" );
    variable_import( _environment, "TILEW", VT_BYTE, 0 );
    variable_global( _environment, "TILEW" );
    variable_import( _environment, "TILEH", VT_BYTE, 0 );
    variable_global( _environment, "TILEH" );
    variable_import( _environment, "TILEW2", VT_BYTE, 0 );
    variable_global( _environment, "TILEW2" );
    variable_import( _environment, "TILEH2", VT_BYTE, 0 );
    variable_global( _environment, "TILEH2" );
    variable_import( _environment, "TILEA", VT_BYTE, 0 );
    variable_global( _environment, "TILEA" );
    variable_import( _environment, "TILEO", VT_WORD, 0 );
    variable_global( _environment, "TILEO" );

    variable_import( _environment, "XSCROLLPOS", VT_BYTE, 0 );
    variable_global( _environment, "XSCROLLPOS" );
    variable_import( _environment, "YSCROLLPOS", VT_BYTE, 0 );
    variable_global( _environment, "YSCROLLPOS" );
    variable_import( _environment, "XSCROLL", VT_BYTE, 0 );
    variable_global( _environment, "XSCROLL" );
    variable_import( _environment, "YSCROLL", VT_BYTE, 0 );
    variable_global( _environment, "YSCROLL" );
    variable_import( _environment, "DIRECTION", VT_BYTE, 0 );
    variable_global( _environment, "DIRECTION" );

    variable_import( _environment, "ONSCROLLUP", VT_BUFFER, 3 );
    variable_global( _environment, "ONSCROLLUP" );

    variable_import( _environment, "ONSCROLLDOWN", VT_BUFFER, 3 );
    variable_global( _environment, "ONSCROLLDOWN" );

    variable_import( _environment, "ONSCROLLLEFT", VT_BUFFER, 3 );
    variable_global( _environment, "ONSCROLLLEFT" );

    variable_import( _environment, "ONSCROLLRIGHT", VT_BUFFER, 3 );
    variable_global( _environment, "ONSCROLLRIGHT" );

    variable_import( _environment, "IMAGEF", VT_BYTE, 0 );
    variable_global( _environment, "IMAGEF" );

    // #if __coleco__
    //     variable_import( _environment, "VDP_HOOK", VT_BUFFER, 10 );
    //     variable_global( _environment, "VDP_HOOK" );
    // #endif

    tms9918_tilemap_enable( _environment, 40, 24, 1, 8, 8 );

    tms9918_cls( _environment );

    _environment->descriptors = precalculate_tile_descriptors_for_font( data_fonttms9918_bin );

    _environment->descriptors->first = 0;
    _environment->descriptors->firstFree = 128;
    _environment->descriptors->lastFree = 255;
    _environment->descriptors->count = 128;
    
    _environment->currentRgbConverterFunction = rgbConverterFunction;
    _environment->screenShades = 16;

}

void tms9918_finalization( Environment * _environment ) {

}

void tms9918_hscroll_line( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_tms9918_hscroll_text_asm );

    Variable * y = variable_retrieve( _environment, "YCURSYS" );
    outline1("LD A, $%2.2x", ( _direction & 0xff ) );
    outline1("LD B, (%s)", y->realName );
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL HSCROLLLT");
    } else {
        outline0("CALL HSCROLLLTNMI2");
    }

}

void tms9918_hscroll_screen( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_tms9918_hscroll_text_asm );

    outline1("LD A, $%2.2x", ( _direction & 0xff ) );
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL HSCROLLST");
    } else {
        outline0("CALL HSCROLLSTNMI2");
    }

}

void tms9918_back( Environment * _environment ) {

    deploy( back, src_hw_tms9918_back_asm );

    if ( ! _environment->hasGameLoop ) {
        outline0("CALL BACK");
    } else {
        outline0("CALL BACKNMI2");
    }

}

void tms9918_cline( Environment * _environment, char * _characters ) {

    deploy( textCline, src_hw_tms9918_cline_asm );

    if ( _characters ) {
        outline1("LD A, (%s)", _characters);
        outline0("LD C, A");
    } else {
        outline0("LD A, 0");
        outline0("LD C, A");
    }
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL CLINE");
    } else {
        outline0("CALL CLINENMI2");
    }

}

/**
 * @brief Calculate the luminance of a color
 * 
 * This function calculates the luminance of a color. 
 * By luminance we mean the modulus of the three-dimensional 
 * vector, drawn in the space composed of the three components 
 * (red, green and blue). The returned value is normalized to
 * the nearest 8-bit value.
 * 
 * @param _a 
 * @return int 
 */
// 

static int calculate_luminance(RGBi _a) {

    // Extract the vector's components 
    // (each partecipate up to 1/3 of the luminance).
    double red = (double) _a.red / 3;
    double green = (double)_a.green / 3;
    double blue = (double)_a.blue / 3;

    // Calculate luminance using Pitagora's Theorem
    return (int)sqrt(pow(red, 2) + pow(green, 2) + pow(blue, 2));

}

static int calculate_image_size( Environment * _environment, int _width, int _height, int _mode ) {

    switch( _mode ) {

        case BITMAP_MODE_GRAPHIC2:

            return 3 + ( ( _width >> 3 ) * _height ) + ( ( _width >> 3 ) * ( _height ) );

        case BITMAP_MODE_MULTICOLOR:
        case TILEMAP_MODE_STANDARD:
        case TILEMAP_MODE_GRAPHIC1:
            break;
    }

    return 0;

}

static Variable * tms9918_image_converter_bitmap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    deploy( tms9918varsGraphic, src_hw_tms9918_vars_graphic_asm );

    image_converter_asserts_free_height( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    RGBi palette[MAX_PALETTE];

    int colorUsed = rgbi_extract_palette(_source, _width, _height, palette, MAX_PALETTE, 1 /* sorted */);

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = colorUsed;

    int i, j, k;

    if ( ( _flags & FLAG_TRANSPARENCY ) ) {
        if (colorUsed > 15) {
            CRITICAL_IMAGE_CONVERTER_TOO_COLORS( colorUsed );
        }
    } else if ( ( _flags & FLAG_OVERLAYED ) ) {
        if (colorUsed > 15) {
            CRITICAL_IMAGE_CONVERTER_TOO_COLORS( colorUsed );
        }
    } else {
        // if (colorUsed > 16) {
        //     CRITICAL_IMAGE_CONVERTER_TOO_COLORS( colorUsed );
        // }
    }

    for( i=0; i<colorUsed; ++i ) {
        int minDistance = 0xffff;
        int colorIndex = 0;
        for (j = 0; j < sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++j) {
            int distance = rgbi_distance(&SYSTEM_PALETTE[j], &palette[i]);
            if (distance < minDistance) {
                for( k=0; k<i; ++k ) {
                    if ( palette[k].index == SYSTEM_PALETTE[j].index ) {
                        break;
                    }
                }
                if ( k>=i ) {
                    minDistance = distance;
                    colorIndex = j;
                }
            }
        }
        palette[i].index = SYSTEM_PALETTE[colorIndex].index;
        strcpy( palette[i].description, SYSTEM_PALETTE[colorIndex].description );
    }

    if ( _flags & FLAG_OVERLAYED ) {
        int i=0;
        for( i=colorUsed-2; i>-1; --i) {
            rgbi_move( &palette[i], &palette[i+1] );
        }
        rgbi_move( &SYSTEM_PALETTE[0], &palette[0] );
    }

    if ( _flags & FLAG_TRANSPARENCY ) {
        if ( palette[0].index == SYSTEM_PALETTE[0].index ) {
            int i=0;
            for( i=colorUsed-2; i>0; --i) {
                rgbi_move( &palette[i], &palette[i+1] );
            }
        } else {
            int i=0;
            for( i=colorUsed-1; i>0; --i) {
                rgbi_move( &palette[i], &palette[i+1] );
            }
        }
        rgbi_move( &SYSTEM_PALETTE[0], &palette[0] );
        rgbi_move( &SYSTEM_PALETTE[0], &palette[1] );
        ++colorUsed;
    }

    if ( _transparent_color != -1 ) {
        if ( colorUsed < 4 ) {
            for( i=0;i<COLOR_COUNT;++i) {
                if ( SYSTEM_PALETTE[i].index == _transparent_color ) {
                    rgbi_move(&palette[0], &palette[colorUsed]);
                    ++colorUsed;
                    rgbi_move(&SYSTEM_PALETTE[i], &palette[0]);
                    break;
                }
            }
        } else {
            for(i=0;i<4;++i) {
                if ( palette[i].index == _transparent_color ) {
                    RGBi tmp;
                    rgbi_move(&palette[i], &tmp);
                    rgbi_move(&palette[0], &palette[i]);
                    rgbi_move(&tmp, &palette[0]);
                    break;
                }
            }
        }
    }

    memcpy( result->originalPalette, palette, MAX_PALETTE * sizeof( RGBi ) );

    int bufferSize = calculate_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_GRAPHIC2 );
    
    char * buffer = malloc ( bufferSize );
    memset( buffer, 0, bufferSize );

    // Position of the pixel in the original image
    int image_x, image_y;
    
    // Position of the pixel, in terms of tiles
    int tile_x, tile_y;
    
    // Position of the pixel, in terms of offset and bitmask
    int offset, offsetc, bitmask;

    // Color of the pixel to convert
    RGBi rgb;

    *(buffer) = (_frame_width & 0xff);
    *(buffer+1) = (_frame_width >> 8 ) & 0xff;
    *(buffer+2) = _frame_height;

    _source += ( ( _offset_y * _width ) + _offset_x ) * 3;

    tms9918_image_converter_tiles( _source, buffer+3, _frame_width, _frame_height, _width );

    if ( _environment->debugImageLoad ) {
        printf("\n" );
    
        printf("PALETTE:\n" );
        for( i=0; i<colorUsed; ++i ) {
            printf("  (%2.2d) = %2.2d (%s)\n", i, palette[i].index, palette[i].description );
        }
        // if ( ( _flags & FLAG_OVERLAYED ) == 0 ) {
        //     printf("  background  (00) = %2.2x (%s)\n", palette[0].index, palette[0].description );
        // } else {
        //     printf("  background  (00) = %2.2x (%s) [currently ignored since it can be overlayed]\n", palette[0].index, palette[0].description );
        // }
        // printf("  low screen  (01) = %2.2x (%s)\n", palette[1].index, palette[1].description );
        // printf("  high screen (10) = %2.2x (%s)\n", palette[2].index, palette[2].description );
        // printf("  colormap    (11) = %2.2x (%s)\n", palette[3].index, palette[3].description );
        // printf("\n" );
        // printf("\n" );
    }
    
    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );
 
    return result;

}

Variable * tms9918_sprite_converter( Environment * _environment, char * _source, int _width, int _height, RGBi * _color ) {

    deploy( tms9918varsGraphic, src_hw_tms9918_vars_graphic_asm );

    RGBi palette[MAX_PALETTE];

    int colorUsed = rgbi_extract_palette(_source, _width, _height, palette, MAX_PALETTE, 1 /* sorted */);

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = colorUsed;

    int i, j, k;

    for( i=0; i<colorUsed; ++i ) {
        int minDistance = 0xffff;
        int colorIndex = 0;
        for (j = 0; j < sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++j) {
            int distance = rgbi_distance(&SYSTEM_PALETTE[j], &palette[i]);
            if (distance < minDistance) {
                for( k=0; k<i; ++k ) {
                    if ( palette[k].index == SYSTEM_PALETTE[j].index ) {
                        break;
                    }
                }
                if ( k>=i ) {
                    minDistance = distance;
                    colorIndex = j;
                }
            }
        }
        palette[i].index = SYSTEM_PALETTE[colorIndex].index;
        strcpy( palette[i].description, SYSTEM_PALETTE[colorIndex].description );
    }

    memcpy( result->originalPalette, palette, MAX_PALETTE * sizeof( RGBi ) );

    int bufferSize = ( ( _width >> 3 ) * _height ) + 3;
    
    char * buffer = malloc ( bufferSize );
    memset( buffer, 0, bufferSize );

    // Position of the pixel in the original image
    int image_x, image_y;
    
    // Position of the pixel, in terms of tiles
    int tile_x, tile_y;
    
    // Position of the pixel, in terms of offset and bitmask
    int offset, bitmask;

    // Color of the pixel to convert
    RGBi rgb;

    // Loop for all the source surface.
    for (image_y = 0; image_y < _height; ++image_y) {
        if ( image_y == 8 ) {
            break;
        }
        for (image_x = 0; image_x < _width; ++image_x) {
            if ( image_x == 8 ) {
                break;
            }

            // Take the color of the pixel
            rgb.red = *_source;
            rgb.green = *(_source + 1);
            rgb.blue = *(_source + 2);

            // Calculate the relative tile

            // Calculate the offset starting from the tile surface area
            // and the bit to set.
            offset = (image_y * ( _width>>3 ) ) + (image_x >> 3);

            int minDistance = 0xffff;
            int colorIndex = 0;

            if ( rgbi_equals_rgb( _color, &rgb ) ) {
                i = 1;
            } else {
                i = 0;
            }

            colorIndex = i;

            if ( _environment->debugImageLoad ) {
                printf( "%1.1x", ( palette[colorIndex].index & 0x0f ) );
            }

            bitmask = ( colorIndex == 0 ? 0 : 1 ) << (7 - ((image_x & 0x7)));
            *(buffer + 2 + offset) |= bitmask;

            _source += 3;

        }

        _source += 3 * ( _width - image_x );

        if ( _environment->debugImageLoad ) {
            printf("\n" );
        }
    }

    *(buffer + 2 + ( ( _width >> 3 ) * _height )) = _color->index | ( _color->index << 4 );

    if ( _environment->debugImageLoad ) {
        printf("\n" );
    
        printf("PALETTE:\n" );
        for( i=0; i<colorUsed; ++i ) {
            printf("  (%2.2d) = %2.2d (%s)\n", i, palette[i].index, palette[i].description );
        }
        // if ( ( _flags & FLAG_OVERLAYED ) == 0 ) {
        //     printf("  background  (00) = %2.2x (%s)\n", palette[0].index, palette[0].description );
        // } else {
        //     printf("  background  (00) = %2.2x (%s) [currently ignored since it can be overlayed]\n", palette[0].index, palette[0].description );
        // }
        // printf("  low screen  (01) = %2.2x (%s)\n", palette[1].index, palette[1].description );
        // printf("  high screen (10) = %2.2x (%s)\n", palette[2].index, palette[2].description );
        // printf("  colormap    (11) = %2.2x (%s)\n", palette[3].index, palette[3].description );
        // printf("\n" );
        // printf("\n" );
    }
    
    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );
 
    return result;

}

Variable * tms9918_image_converter( Environment * _environment, char * _data, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

    switch( _mode ) {

        case BITMAP_MODE_GRAPHIC2:

            return tms9918_image_converter_bitmap_mode_standard( _environment, _data, _width, _height, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );

            break;
    }

    WARNING_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

    return tms9918_new_image( _environment, 8, 8, BITMAP_MODE_GRAPHIC2 );

}

void tms9918_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    deploy( tms9918vars, src_hw_tms9918_vars_asm);
    deploy( tms9918varsGraphic, src_hw_tms9918_vars_graphic_asm );
    deploy( putimage, src_hw_tms9918_put_image_asm );

    MAKE_LABEL

    outhead1("putimage%s:", label);
    outline1("LD A, $%2.2x", ( _flags & 0xff ) );
    outline1("LD HL, %s", _image );
    if ( _sequence ) {

        outline0("LD DE, $0003" );
        outline0("ADD HL, DE" );
        if ( strlen(_sequence) == 0 ) {

        } else {
            outline0("PUSH HL" );
            outline1("LD A, (%s)", _sequence );
            outline0("LD L, A" );
            outline0("LD H, 0" );
            outline0("ADD HL, HL" );
            outline0("LD DE, HL" );
            outline1("LD HL, OFFSETS%4.4x", _frame_size * _frame_count );
            outline0("ADD HL, DE" );
            outline0("LD A, (HL)" );
            outline0("LD E, A" );
            outline0("INC HL" );
            outline0("LD A, (HL)" );
            outline0("LD D, A" );
            outline0("POP HL" );
            outline0("ADD HL, DE" );
        }

        if ( _frame ) {
            if ( strlen(_frame) == 0 ) {

            } else {
                outline0("PUSH HL" );
                outline1("LD A, (%s)", _frame );
                outline0("LD L, A" );
                outline0("LD H, 0" );
                outline0("ADD HL, HL" );
                outline0("LD DE, HL" );
                outline1("LD HL, OFFSETS%4.4x", _frame_size * _frame_count );
                outline0("ADD HL, DE" );
                outline0("LD A, (HL)" );
                outline0("LD E, A" );
                outline0("INC HL" );
                outline0("LD A, (HL)" );
                outline0("LD D, A" );
                outline0("POP HL" );
                outline0("ADD HL, DE" );
            }
        }

    } else {

        if ( _frame ) {
            outline0("LD DE, $0003" );
            outline0("ADD HL, DE" );
            if ( strlen(_frame) == 0 ) {

            } else {
                outline0("PUSH HL" );
                outline1("LD A, (%s)", _frame );
                outline0("LD L, A" );
                outline0("LD H, 0" );
                outline0("ADD HL, HL" );
                outline0("LD DE, HL" );
                outline1("LD HL, OFFSETS%4.4x", _frame_size );
                outline0("ADD HL, DE" );
                outline0("LD A, (HL)" );
                outline0("LD E, A" );
                outline0("INC HL" );
                outline0("LD A, (HL)" );
                outline0("LD D, A" );
                outline0("POP HL" );
                outline0("ADD HL, DE" );
            }
        }


    }
    outline1("LD A, (%s)", _x );
    outline0("LD E, A" );
    outline1("LD A, (%s)", _y );
    outline0("LD D, A" );
    outline1("LD A, $%2.2x", _flags );
    outline0("LD (IMAGEF), A" );

    if ( ! _environment->hasGameLoop ) {
        outline0("CALL PUTIMAGE");
    } else {
        outline0("CALL PUTIMAGENMI2");
    }

}

void tms9918_wait_vbl( Environment * _environment ) {

    deploy( tms9918varsGraphic, src_hw_tms9918_vars_graphic_asm );
    deploy( vbl, src_hw_tms9918_vbl_asm);

    outline0("JSR VBL");

}

Variable * tms9918_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    deploy( tms9918varsGraphic, src_hw_tms9918_vars_graphic_asm );

    int size = calculate_image_size( _environment, _width, _height, _mode );

    if ( ! size ) {
        CRITICAL_NEW_IMAGE_UNSUPPORTED_MODE( _mode );
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(new image)" );

    char * buffer = malloc ( size );
    memset( buffer, 0, size );

    *(buffer) = (_width & 0xff);
    *(buffer+1) = (_width>>8) & 0xff;
    *(buffer+2) = _height;

    result->valueBuffer = buffer;
    result->size = size;
    
    return result;

}

void tms9918_get_image( Environment * _environment, char * _image, char * _x, char * _y ) {

    deploy( tms9918vars, src_hw_tms9918_vars_asm);
    deploy( tms9918varsGraphic, src_hw_tms9918_vars_graphic_asm );
    deploy( getimage, src_hw_tms9918_get_image_asm );

    MAKE_LABEL

    outline1("LD HL, %s", _image );
    outline1("LD A, (%s)", _x );
    outline0("LD E, A" );
    outline1("LD A, (%s)", _y );
    outline0("LD D, A" );

    if ( ! _environment->hasGameLoop ) {
        outline0("CALL GETIMAGE");
    } else {
        outline0("CALL GETIMAGENMI2");
    }

}


void tms9918_scroll( Environment * _environment, int _dx, int _dy ) {

    deploy( vic2vars, src_hw_tms9918_vars_asm);
    deploy( scroll, src_hw_tms9918_scroll_asm);
    deploy( textHScroll, src_hw_tms9918_hscroll_text_asm );
    deploy( vScrollTextDown, src_hw_tms9918_vscroll_text_down_asm );
    deploy( vScrollTextUp, src_hw_tms9918_vscroll_text_up_asm );

    outline1("LD A, $%2.2x", (unsigned char)(_dx&0xff) );
    outline0("LD B, A" );
    outline1("LD A, $%2.2x", (unsigned char)(_dy&0xff) );
    outline0("LD C, A" );
    outline0("CALL SCROLL");

}

void tms9918_put_tile( Environment * _environment, char * _tile, char * _x, char * _y ) {

    deploy( tms9918vars, src_hw_tms9918_vars_asm);
    deploy( tiles, src_hw_tms9918_tiles_asm );

    outline1("LD A, (%s)", _tile );
    outline0("LD (TILET), A" );
    outline1("LD A, (%s)", _x );
    outline0("LD (TILEX), A" );
    outline1("LD A, (%s)", _y );
    outline0("LD (TILEY), A" );
    outline0("LD A, 1" );
    outline0("LD (TILEW), A" );
    outline0("LD (TILEH), A" );
    outline0("LD (TILEW2), A" );
    outline0("LD (TILEH2), A" );

    if ( ! _environment->hasGameLoop ) {
        outline0("CALL PUTTILE");
    } else {
        outline0("CALL PUTTILENMI2");
    }

}

void tms9918_move_tiles( Environment * _environment, char * _tile, char * _x, char * _y ) {

    Variable * tile = variable_retrieve( _environment, _tile );
    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy( tms9918vars, src_hw_tms9918_vars_asm);
    deploy( tiles, src_hw_tms9918_tiles_asm );

    int size = ( tile->originalWidth >> 3 ) * ( tile->originalHeight >> 3 );

    if ( size ) {
        outline1("LD HL, OFFSETS%4.4x", size );
        outline0("LD A, L" );
        outline0("LD (TILEO), A" );
        outline0("LD A, H" );
        outline0("LD (TILEO+1), A" );
    } else {
        outline0("LD A, 0" );
        outline0("LD (TILEO), A" );
        outline0("LD (TILEO+1), A" );
    }

    outline1("LD A, (%s)", tile->realName );
    outline0("LD (TILET), A" );
    outline1("LD A, (%s)", x->realName );
    outline0("LD (TILEX), A" );
    outline1("LD A, (%s)", y->realName );
    outline0("LD (TILEY), A" );
    outline1("LD A, (%s+1)", tile->realName );
    outline0("LD (TILEW), A" );
    outline0("LD (TILEW2), A" );
    outline1("LD A, (%s+2)", tile->realName );
    outline0("LD (TILEH), A" );
    outline0("LD (TILEH2), A" );
    outline1("LD A, (%s+3)", tile->realName );
    outline0("LD (TILEA), A" );

    if ( ! _environment->hasGameLoop ) {
        outline0("CALL MOVETILE");
    } else {
        outline0("CALL MOVETILENMI2");
    }

}

void tms9918_put_tiles( Environment * _environment, char * _tile, char * _x, char * _y, char *_w, char *_h ) {

    deploy( tms9918vars, src_hw_tms9918_vars_asm);
    deploy( tiles, src_hw_tms9918_tiles_asm );

    outline1("LD A, (%s)", _tile );
    outline0("LD (TILET), A" );
    outline1("LD A, (%s)", _x );
    outline0("LD (TILEX), A" );
    outline1("LD A, (%s)", _y );
    outline0("LD (TILEY), A" );
    outline1("LD A, (%s+1)", _tile );
    outline0("LD (TILEW), A" );
    if ( _w ) {
        outline1("LD A, (%s)", _w );
    }
    outline0("LD (TILEW2), A" );
    outline1("LD A, (%s+2)", _tile );
    outline0("LD (TILEH), A" );
    if ( _h ) {
        outline1("LD A, (%s)", _h );
    }
    outline0("LD (TILEH2), A" );

    if ( ! _environment->hasGameLoop ) {
        outline0("CALL PUTTILE");
    } else {
        outline0("CALL PUTTILENMI2");
    }

}

void tms9918_tile_at( Environment * _environment, char * _x, char * _y, char *_result ) {

    deploy( tms9918vars, src_hw_tms9918_vars_asm);
    deploy( tiles, src_hw_tms9918_tiles_asm );

    outline1("LD A, (%s)", _x );
    outline0("LD (TILEX), A" );
    outline1("LD A, (%s)", _y );
    outline0("LD (TILEY), A" );

    if ( ! _environment->hasGameLoop ) {
        outline0("CALL TILEAT");
    } else {
        outline0("CALL TILEATNMI2");
    }

    outline0("LD A, (TILET)" );
    outline1("LD (%s), A", _result );

}

void tms9918_use_tileset( Environment * _environment, char * _tileset ) {

    deploy( tms9918vars, src_hw_tms9918_vars_asm);
    deploy( tiles, src_hw_tms9918_tiles_asm );

    outline1("LD A, (%s)", _tileset );

    if ( ! _environment->hasGameLoop ) {
        outline0("CALL USETILESET");
    } else {
        outline0("CALL USETILESETNMI2");
    }

}

Variable * tms9918_get_raster_line( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_WORD, "(raster line)" );

    variable_store( _environment, result->name, 0 );

    return result;
    
}

void tms9918_move_memory_video( Environment * _environment, char * _from, char * _to, char * _size ) {

    outline1("LD HL, (%s)", _from );
    outline1("LD DE, (%s)", _to );
    outline1("LD BC, (%s)", _size );
    outline0("JP VDPWRITE" );

}

void tms9918_move_video_memory( Environment * _environment, char * _from, char * _to, char * _size ) {

    outline1("LD HL, (%s)", _to );
    outline1("LD DE, (%s)", _from );
    outline1("LD BC, (%s)", _size );
    outline0("JP VDPREAD" );

}

void tms9918_colors_vars( Environment * _environment, char * _foreground_color, char * _background_color ) {

// #ifdef __coleco__
//     MAKE_LABEL
//     if ( ! _environment->hasGameLoop ) {
//         outline1("JP %sskip", label );
//         outhead1("%s:", label );
//     }
// #endif
    outline1("LD E, %2.2x", VDP_RCOLOR );
    outline0("CALL VDPREGIN" );
    outline1("LD A, (%s)", _foreground_color );
    outline0("SLA A" );
    outline0("SLA A" );
    outline0("SLA A" );
    outline0("SLA A" );
    outline0("LD B, A" );
    outline1("LD A, (%s)", _background_color );
    outline0("OR B" );
    outline0("CALL VDPSETREG" );
// #ifdef __coleco__
//     if ( ! _environment->hasGameLoop ) {
//         outline0("RET" );
//         outhead1("%sskip:", label );
//         outline0("CALL WAIT_VDP_HOOK" );
//         outline1("LD HL, %s", label );
//         outline0("CALL SET_VDP_HOOK0" );
//         outline0("CALL WAIT_VDP_HOOK" );
//     }
// #endif

}

#endif