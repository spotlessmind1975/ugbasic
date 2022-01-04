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

#ifdef __msx1__

#include "../ugbc.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
        { 0x00, 0x00, 0x00, 0, "TRANSPARENT" },
        { 0x00, 0x00, 0x00, 1, "BLACK" },
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
void tms9918_collision( Environment * _environment, char * _sprite_mask, char * _result ) {

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

    outline1("LD E, %2.2x", VDP_RCOLOR );
    outline1("LD A, (%s)", _border_color );
    outline0("CALL VDPSETREG" );

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

    // @TODO

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

    // @TODO

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

    // @TODO

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

    // @TODO

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

    // @TODO

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

    // @TODO

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

    // @TODO

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

    // @TODO

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

    cpu_store_8bit( _environment, "_PEN", 0x01 );
    cpu_store_8bit( _environment, "_PAPER", 0x00 );

    printf("Screen %d\n", _screen_mode->id );

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
            WVDP_R1( 0xf0 );

            // Register 2 tells the VDP where the starting address of the Name Table is located in VRAM. The
            // range of its contents is from O-F. The contents of the register form the upper four bits of
            // the 14-bit VDP address, therefore making the location of the Name Table in VRAM equal to
            // (Register 2) * 400 (Hex)
            WVDP_RNAME( 0x00 );

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
            WVDP_RPATTERN( 0x01 );

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
            WVDP_R1( 0xe0 );

            // Register 2 tells the VDP where the starting address of the Name Table is located in VRAM. The
            // range of its contents is from O-F. The contents of the register form the upper four bits of
            // the 14-bit VDP address, therefore making the location of the Name Table in VRAM equal to
            // (Register 2) * 400 (Hex)
            WVDP_RNAME( 0x00 );

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
            WVDP_RPATTERN( 0x1 );

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
            WVDP_R1( 0xe2 );

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

    tms9918_cls( _environment );
    
}

void tms9918_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors );

    if ( mode ) {
        tms9918_screen_mode_enable( _environment, mode );

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        
        _environment->currentMode = mode->id;
    } else {
        WARNING_SCREEN_MODE( -1 );
    }
}

void tms9918_bitmap_disable( Environment * _environment ) {

}

void tms9918_tilemap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors );

    if ( mode ) {
        tms9918_screen_mode_enable( _environment, mode );

        _environment->currentMode = mode->id;

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
    } else {
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
    
    outline1("LD A, $%2.2x", _y );
    outline0("LD D, A");
    outline1("LD A, $%2.2x", _x );
    outline0("LD E, A");
    outline0("LD A, 1");
    outline0("CALL PLOT");

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
    outline0("CALL PLOT");

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
    outline0("CALL PLOT");
    outline1("LD (%s), A", result->realName);

}

void tms9918_screen_on( Environment * _environment ) {

}

void tms9918_screen_off( Environment * _environment ) {
    
}

void tms9918_screen_rows( Environment * _environment, char * _rows ) {

}

void tms9918_sprite_data_from( Environment * _environment, char * _sprite, char * _address ) {

}

void tms9918_sprite_enable( Environment * _environment, char * _sprite ) {

}

void tms9918_sprite_disable( Environment * _environment, char * _sprite ) {

}

void tms9918_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

}

void tms9918_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

}

void tms9918_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

}

void tms9918_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

}

void tms9918_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

}

void tms9918_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void tms9918_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void tms9918_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

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
    
    if ( _environment->currentMode == 2 || _environment->currentMode == 3 ) {
        deploy( clsGraphic, src_hw_tms9918_cls_graphic_asm );
        outline0("CALL CLSG");
    } else {
        deploy( clsText, src_hw_tms9918_cls_text_asm );
        outline0("CALL CLST");
    }

}

void tms9918_scroll_text( Environment * _environment, int _direction ) {

    if ( _direction > 0 ) {
        deploy( vScrollTextDown, src_hw_tms9918_vscroll_text_down_asm );
        outline0("CALL VSCROLLTDOWN");
    } else {
        deploy( vScrollTextUp, src_hw_tms9918_vscroll_text_up_asm );
        outline0("CALL VSCROLLTUP");
    }

}

void tms9918_text( Environment * _environment, char * _text, char * _text_size ) {

    deploy( tms9918vars, src_hw_tms9918_vars_asm);
    deploy( vScrollTextUp, src_hw_tms9918_vscroll_text_up_asm );

    outline1("LD DE, (%s)", _text);
    outline1("LD A, (%s)", _text_size);
    outline0("LD C, A");

    if ( _environment->currentMode == 2 || _environment->currentMode == 3 ) {
        deploy( clsGraphic, src_hw_tms9918_cls_graphic_asm );
        deploy( tms9918varsGraphic, src_hw_tms9918_vars_graphic_asm );
        deploy( textEncodedAtGraphic, src_hw_tms9918_text_at_graphic_asm );
        outline0("CALL TEXTATBITMAPMODE");
    } else {
        deploy( clsText, src_hw_tms9918_cls_text_asm );
        deploy( textEncodedAtText, src_hw_tms9918_text_at_text_asm );
        outline0("CALL TEXTATTILEMODE");
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

    variable_import( _environment, "VDPDATAPORTREAD", VT_BYTE, 0x98 );
    variable_global( _environment, "VDPDATAPORTREAD" );

    variable_import( _environment, "VDPDATAPORTWRITE", VT_BYTE, 0x98 );
    variable_global( _environment, "VDPDATAPORTWRITE" );

    variable_import( _environment, "VDPCONTROLPORTREAD", VT_BYTE, 0x99 );
    variable_global( _environment, "VDPCONTROLPORTREAD" );

    variable_import( _environment, "VDPCONTROLPORTWRITE", VT_BYTE, 0x99 );
    variable_global( _environment, "VDPCONTROLPORTWRITE" );

    SCREEN_MODE_DEFINE( TILEMAP_MODE_STANDARD, 0, 40, 24, 20, "Text Mode" );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_GRAPHIC1, 0, 32, 24, 16, "Graphic I" );

    SCREEN_MODE_DEFINE( BITMAP_MODE_GRAPHIC2, 1, 256, 192, 16, "Graphic II" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_MULTICOLOR, 1, 256, 192, 16, "Multicolor" );
 
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

    variable_import( _environment, "XCURS", VT_BYTE, 0 );
    variable_global( _environment, "XCURS" );
    variable_import( _environment, "YCURS", VT_BYTE, 0 );
    variable_global( _environment, "YCURS" );
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

    tms9918_cls( _environment );

    _environment->fontWidth = 6;
    _environment->fontHeight = 8;
    _environment->screenTilesWidth = 40;
    _environment->screenTilesHeight = 24;
    _environment->screenTiles = 255;
    _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
    _environment->screenHeight = _environment->screenTilesHeight * _environment->screenTilesHeight;
    _environment->screenColors = 16;

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
    outline0("CALL HSCROLLLT");

}

void tms9918_hscroll_screen( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_tms9918_hscroll_text_asm );

    outline1("LD A, $%2.2x", ( _direction & 0xff ) );
    outline0("CALL HSCROLLST");

}

void tms9918_back( Environment * _environment ) {

    deploy( back, src_hw_tms9918_back_asm );

    outline0("CALL BACK");

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
    outline0("CALL CLINE");

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

            return 2 + ( ( _width >> 3 ) * _height ) + ( ( _width >> 3 ) * ( _height ) );

        case BITMAP_MODE_MULTICOLOR:
        case TILEMAP_MODE_STANDARD:
        case TILEMAP_MODE_GRAPHIC1:
            break;
    }

    return 0;

}

static Variable * tms9918_image_converter_bitmap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    deploy( tms9918varsGraphic, src_hw_tms9918_vars_graphic_asm );

    image_converter_asserts( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    RGBi palette[MAX_PALETTE];

    int colorUsed = rgbi_extract_palette(_source, _width, _height, palette, MAX_PALETTE);

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
        if (colorUsed > 16) {
            CRITICAL_IMAGE_CONVERTER_TOO_COLORS( colorUsed );
        }
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

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
 
    int bufferSize = calculate_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_GRAPHIC2 );
    
    printf( "image size = %d\n", bufferSize );

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

    *(buffer) = _frame_width;
    *(buffer+1) = _frame_height;

    _source += ( ( _offset_y * _width ) + _offset_x ) * 3;

    // Loop for all the source surface.
    for (image_y = 0; image_y < _frame_height; ++image_y) {
        for (image_x = 0; image_x < _frame_width; ++image_x) {

            // Take the color of the pixel
            rgb.red = *_source;
            rgb.green = *(_source + 1);
            rgb.blue = *(_source + 2);

            // Calculate the relative tile
            tile_y = (image_y >> 3);
            tile_x = (image_x >> 3);

            // Calculate the offset starting from the tile surface area
            // and the bit to set.
            offset = (tile_y * 8 *( _frame_width >> 3 ) ) + (tile_x * 8) + (image_y & 0x07);
            offsetc = (image_y * ( _frame_width >> 3 ) ) + (tile_x);

            int minDistance = 0xffff;
            int colorIndex = 0;

            for( i= ( _flags & FLAG_OVERLAYED ) ? 1 : 0; i<colorUsed; ++i ) {
                if ( rgbi_equals_rgb( &palette[i], &rgb ) ) {
                    break;
                }
            }

            colorIndex = i;

            if ( _environment->debugImageLoad ) {
                printf( "%1.1x", colorIndex );
            }

            bitmask = ( colorIndex == 0 ? 0 : 1 ) << (8 - ((image_x & 0x7)));
            if ( colorIndex ) {
                *(buffer + 2 + ( ( _frame_width >> 3 ) * _frame_height ) + offsetc ) = ( ( ( palette[colorIndex].index & 0x0f ) << 4 ) | palette[0].index );
            }
            *(buffer + 2 + offset) |= bitmask;

            _source += 3;

        }

        _source += 3 * ( _width - _frame_width );

        if ( _environment->debugImageLoad ) {
            printf("\n" );
        }
    }

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

    CRITICAL_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

}

void tms9918_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, int _frame_size, int _flags ) {

    deploy( tms9918vars, src_hw_tms9918_vars_asm);
    deploy( tms9918varsGraphic, src_hw_tms9918_vars_graphic_asm );
    deploy( putimage, src_hw_tms9918_put_image_asm );

    MAKE_LABEL

    outhead1("putimage%s:", label);
    outline1("LD A, $%2.2x", _flags );
    outline1("LD HL, %s", _image );
    if ( _frame ) {
        outline0("LD DE, $0002" );
        outline0("ADD HL, DE" );
        if ( strlen(_frame) == 0 ) {

        } else {
            outline0("PUSH HL" );
            outline1("LD A, %s", _frame );
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
    outline1("LD A, (%s)", _x );
    outline0("LD E, A" );
    outline1("LD A, (%s)", _y );
    outline0("LD D, A" );

    outline0("CALL PUTIMAGE");

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

    *(buffer) = _width;
    *(buffer+1) = _height;

    result->valueBuffer = buffer;
    result->size = size;
    
    return result;

}

void tms9918_get_image( Environment * _environment, char * _image, char * _x, char * _y ) {

    // deploy( tms9918vars, src_hw_tms9918_vars_asm);
    // deploy( tms9918varsGraphic, src_hw_tms9918_vars_graphic_asm );
    // deploy( getimage, src_hw_tms9918_get_image_asm );

    // MAKE_LABEL

    // outhead1("getimage%s:", label);
    // outline1("LDA #<%s", _image );
    // outline0("STA TMPPTR" );
    // outline1("LDA #>%s", _image );
    // outline0("STA TMPPTR+1" );
    // outline1("LDA %s", _x );
    // outline0("STA IMAGEX" );
    // outline1("LDA %s+1", _x );
    // outline0("STA IMAGEX+1" );
    // outline1("LDA %s", _y );
    // outline0("STA IMAGEY" );
    // outline1("LDA %s+1", _y );
    // outline0("STA IMAGEY+1" );

    // outline0("JSR GETIMAGE");

}

#endif