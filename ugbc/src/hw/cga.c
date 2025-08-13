/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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

#if defined(__pccga__)

#include "../ugbc.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
        {    0,    0,    0, 0xff,  0, "BLACK" },
        {    0,    0,  170, 0xff,  1, "DARK_BLUE" },
        {    0,  170,    0, 0xff,  2, "DARK_GREEN" },
        {    0,  170,  170, 0xff,  3, "DARK_CYAN" },
        {  170,    0,    0, 0xff,  4, "DARK_RED" },
        {  170,    0,  170, 0xff,  5, "DARK_MAGENTA" },
        {  170,   85,    0, 0xff,  6, "BROWN" },
        {  170,  170,  170, 0xff,  7, "LIGHT_GRAY" },
        {   85,   85,   85, 0xff,  8, "DARK_GRAY" },
        {   85,   85,  255, 0xff,  9, "LIGHT_BLUE" },
        {   85,  255,   85, 0xff, 10, "LIGHT_GREEN" },
        {   85,  255,  255, 0xff, 11, "LIGHT_CYAN" },
        {  255,   85,   85, 0xff, 12, "LIGHT_RED" },
        {  255,   85,  255, 0xff, 13, "LIGHT_MAGENTA" },
        {  255,  255,   85, 0xff, 14, "YELLOW" },
        {  255,  255,  255, 0xff, 15, "WHITE" }
};

static RGBi * commonPalette;
int lastUsedSlotInCommonPalette = 0;

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#define CGA_COLOR_BLUE          0x01
#define CGA_COLOR_GREEN         0x02
#define CGA_COLOR_RED           0x04
#define CGA_COLOR_LIGHT         0x08
#define CGA_COLOR_LIGHT2        0x10
#define CGA_COLOR_CSET1         0x20
#define CGA_COLOR_CSET2         0x00

#define WRITE_COLOR_SELECT_REGISTER( v ) \
    outline1("MOV AL, 0x%2.2x", v ) \
    outline0("CALL WRITECGACOLORSELECTREG")

#define CGA_MODE_80x25          0x01
#define CGA_MODE_40x25          0x00

#define CGA_MODE_GRAPHIC        0x02
#define CGA_MODE_TEXT           0x00

#define CGA_MODE_BW             0x04
#define CGA_MODE_COLOR          0x00

#define CGA_MODE_ENABLE         0x08
#define CGA_MODE_DISABLE        0x00

#define CGA_MODE_HIRES          0x10
#define CGA_MODE_LORES          0x00

#define CGA_MODE_BLINK          0x20
#define CGA_MODE_NOBLINK        0x00

#define WRITE_MODE_CONTROL_REGISTER( v ) \
    outline1("MOV AL, 0x%2.2x", v ) \
    outline0("CALL WRITECGAMODECONTROLREG")

RGBi * CGA_image_nearest_system_color( RGBi * _color ) {

    unsigned int minDistance = 0xffff;
    int colorIndex = 0;
    for (int j = 0; j < COLOR_COUNT; ++j) {
        int distance = rgbi_distance(&SYSTEM_PALETTE[j], _color);
        if ( _color->alpha < 255 ) {
            if ( rgbi_equals_rgb( &SYSTEM_PALETTE[j], _color ) ) {
                minDistance = 0;
                distance = 0;
                colorIndex = j;
            }
        } else {
            if ( SYSTEM_PALETTE[j].alpha < 255 ) {
                continue;
            }
            if (distance < minDistance) {
                minDistance = distance;
                colorIndex = j;
            }
        }
    }

    return &SYSTEM_PALETTE[colorIndex];

}

Variable * cga_collision( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    Variable * result = variable_temporary( _environment, VT_SBYTE, "(collision)" );

    deploy( sprite, src_hw_cga_sprites_asm );
    
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL SPRITECOL");
    } else {
        outline0("CALL SPRITECOLNMI2");
    }

    outline1("LD (%s), A", result->realName )

    return result;
    
}

/**
 * @brief <i>CGA</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with a tile. The result (0 = no collision, 0xff = 
 * collision occurred) is returned in the output variable.
 * *
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void cga_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

    //todo

}

/**
 * @brief <i>CGA</i>: emit code to change border color
 * 
 * This function can be used to issue code aimed at changing the
 * border color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _border_color Border color to use
 */
void cga_border_color( Environment * _environment, char * _border_color ) {

}

/**
 * @brief <i>CGA</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void cga_background_color( Environment * _environment, int _index, int _background_color ) {

    char value[MAX_TEMPORARY_STORAGE]; sprintf( value, "$%2.2x", _background_color );

    cga_background_color_vars( _environment, NULL, value );
    
}

/**
 * @brief <i>CGA</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void cga_background_color_vars( Environment * _environment, char * _index, char * _background_color ) {

}

/**
 * @brief <i>CGA</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void cga_background_color_semivars( Environment * _environment, int _index, char * _background_color ) {

}

/**
 * @brief <i>CGA</i>: emit code to retrieve background color
 * 
 * This function can be used to issue code aimed at retrieving the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void cga_background_color_get_vars( Environment * _environment, char * _index, char * _background_color ) {

}

/**
 * @brief <i>CGA</i>: emit code to change common sprite's color 
 * 
 * This function can be used to issue code aimed at changing the
 * common color of the sprites.

 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _common_color Index of the color to use
 */
void cga_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {

}

/**
 * @brief <i>CGA</i>: emit code to set raster irq
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
void cga_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>CGA</i>: emit code to wait for next raster irq
 * 
 * This function outputs assembly code needed to wait for the
 * next raster. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 *
 */
void cga_next_raster( Environment * _environment ) {

}

/**
 * @brief <i>CGA</i>: emit code to wait for next raster irq at different position
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
void cga_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

void cga_bank_select( Environment * _environment, int _bank ) {
    
}

int cga_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    _screen_mode->selected = 1;

    cpu_store_8bit( _environment, "_PEN", _environment->defaultPenColor );
    cpu_store_8bit( _environment, "_PAPER", _environment->defaultPaperColor );

    switch( _screen_mode->id ) {
        case TILEMAP_MODE_40x25x2:
            _environment->fontWidth = 8;
            _environment->fontHeight = 8;
            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 25;
            _environment->screenTiles = 255;
            _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
            _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
            _environment->screenColors = 2;
            _environment->currentModeBW = 0;

            //   Sequence of Events for Changing Modes
            // 1 Determine the mode of operation.
            // 2 Reset the video-enable bit in the mode-control register.
            WRITE_MODE_CONTROL_REGISTER( CGA_MODE_DISABLE )
            // 3 Program the 6845 CRT Controller to select the mode.
            WRITE_MODE_CONTROL_REGISTER( CGA_MODE_40x25 | CGA_MODE_BW );
            // 4 Program the mode-control and color-select registers
            // including re-enabling the video.
            WRITE_COLOR_SELECT_REGISTER( CGA_COLOR_CSET1 )
            // 4 Program the mode-control and color-select registers
            WRITE_MODE_CONTROL_REGISTER( CGA_MODE_40x25 | CGA_MODE_BW | CGA_MODE_ENABLE );

            cpu_store_16bit( _environment, "TEXTADDRESS", 0x0000 );

            break;
    }

    _environment->consoleTilesWidth = _environment->screenTilesWidth;
    _environment->consoleTilesHeight = _environment->screenTilesHeight;

    cpu_store_16bit( _environment, "CLIPX1", 0 );
    cpu_store_16bit( _environment, "CLIPX2", (_environment->screenWidth-1) );
    cpu_store_16bit( _environment, "CLIPY1", 0 );
    cpu_store_16bit( _environment, "CLIPY2", (_environment->screenHeight-1) );

    cpu_store_16bit( _environment, "ORIGINX", 0 );
    cpu_store_16bit( _environment, "ORIGINY", 0 );

    cpu_store_16bit( _environment, "CURRENTWIDTH", _environment->screenWidth );
    cpu_store_16bit( _environment, "CURRENTHEIGHT", _environment->screenHeight );
    cpu_move_16bit( _environment, "CURRENTWIDTH", "RESOLUTIONX" );
    cpu_move_16bit( _environment, "CURRENTHEIGHT", "RESOLUTIONY" );
    cpu_store_8bit( _environment, "CURRENTTILES", _environment->screenTiles );
    cpu_store_8bit( _environment, "CURRENTTILESWIDTH", _environment->screenTilesWidth );
    cpu_store_8bit( _environment, "CURRENTTILESWIDTHX8", _environment->screenTilesWidth * 8 );
    cpu_store_8bit( _environment, "CURRENTTILESHEIGHT", _environment->screenTilesHeight );
    cpu_store_8bit( _environment, "FONTWIDTH", _environment->fontWidth );
    cpu_store_8bit( _environment, "FONTHEIGHT", _environment->fontHeight );
    cpu_store_8bit( _environment, "CONSOLEX1", 0 );
    cpu_store_8bit( _environment, "CONSOLEY1", 0 );
    cpu_store_8bit( _environment, "CONSOLEX2", _environment->consoleTilesWidth-1 );
    cpu_store_8bit( _environment, "CONSOLEY2", _environment->consoleTilesHeight-1 );
    cpu_store_8bit( _environment, "CONSOLEW", _environment->consoleTilesWidth );
    cpu_store_8bit( _environment, "CONSOLEH", _environment->consoleTilesHeight );

    console_calculate( _environment );
    
    if (_environment->vestigialConfig.clsImplicit ) {
        cga_cls( _environment );
    }

}

void console_calculate( Environment * _environment ) {

}

void console_calculate_vars( Environment * _environment ) {

}

void cga_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors, 8, 8 );

    if ( mode ) {
        cga_screen_mode_enable( _environment, mode );

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 0 );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 0;

        if (_environment->vestigialConfig.clsImplicit ) {
            cga_cls( _environment );
        }

    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void cga_bitmap_disable( Environment * _environment ) {

}

void cga_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors, _tile_width, _tile_height );

    if ( mode ) {

        // printf("cga_tilemap_enable() -> %d\n", mode->id );
        
        cga_screen_mode_enable( _environment, mode );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 1;

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 1 );

        if (_environment->vestigialConfig.clsImplicit ) {
            cga_cls( _environment );
        }

    } else {
        // printf("cga_tilemap_enable() -> -1\n" );
        WARNING_SCREEN_MODE( -1 );
    }

}

void cga_bitmap_at( Environment * _environment, char * _address ) {

}

void cga_colormap_at( Environment * _environment, char * _address ) {

}

void cga_textmap_at( Environment * _environment, char * _address ) {

}

void cga_pset_int( Environment * _environment, int _x, int _y, int *_c ) {

}

void cga_pset_vars( Environment * _environment, char *_x, char *_y, char *_c ) {

}

void cga_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result ) {

}

void cga_screen_on( Environment * _environment ) {

}

void cga_screen_off( Environment * _environment ) {

}

void cga_screen_rows( Environment * _environment, char * _rows ) {

}

void cga_screen_columns( Environment * _environment, char * _columns ) {

}

void cga_sprite_data_set( Environment * _environment, char * _sprite, char * _address ) {

}

void cga_sprite_data_from( Environment * _environment, char * _sprite, char * _image ) {

}

void cga_sprite_enable( Environment * _environment, char * _sprite ) {

}

void cga_sprite_disable( Environment * _environment, char * _sprite ) {

}

void cga_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

}

void cga_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

}

void cga_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

}

void cga_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

}

void cga_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

}

void cga_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void cga_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void cga_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

}

void cga_sprite_priority( Environment * _environment, char * _sprite, char * _priority ) {

}

void cga_tiles_at( Environment * _environment, char * _address ) {

}

void cga_vertical_scroll( Environment * _environment, char * _displacement ) {

}

void cga_horizontal_scroll( Environment * _environment, char * _displacement ) {

}

void cga_busy_wait( Environment * _environment, char * _timing ) {

}

void cga_get_width( Environment * _environment, char *_result ) {

}

void cga_tiles_get( Environment * _environment, char *_result ) {

}

void cga_get_height( Environment * _environment, char *_result ) {

}

void cga_cls( Environment * _environment ) {
    
    if ( _environment->currentMode == 0 ) {
        deploy( clsText, src_hw_cga_cls_text_asm );
        outline0("CALL CLST");
    } else {

    }

}

void cga_cls_box( Environment * _environment, char * _x1, char * _y1, char * _w, char * _h ) {
    
}

void cga_scroll_text( Environment * _environment, int _direction, int _overlap ) {

}

void cga_text( Environment * _environment, char * _text, char * _text_size, int _raw ) {

    deploy( cgavars, src_hw_cga_vars_asm);
    // deploy( vScrollTextUp, src_hw_cga_vscroll_text_up_asm );

    outline1("MOV SI, [%s]", _text);
    outline1("MOV CL, [%s]", _text_size);

    if ( _raw ) {

        // if ( ( _environment->currentMode == 2 || _environment->currentMode == 3 ) && !_environment->currentTileMode ) {
        //     deploy( clsGraphic, src_hw_cga_cls_graphic_asm );
        //     deploy( cgavarsGraphic, src_hw_cga_vars_graphic_asm );
        //     deploy( textEncodedAt, src_hw_cga_text_asm );
        //     deploy( textEncodedAtGraphicRaw, src_hw_cga_text_at_graphic_raw_asm );
        //     if ( ! _environment->hasGameLoop ) {
        //         outline0("CALL TEXTATBITMAPMODERAW");
        //     } else {
        //         outline0("CALL TEXTATBITMAPMODENMI2RAW");
        //     }
        // } else {
        //     deploy( cgavarsGraphic, src_hw_cga_vars_graphic_asm );
        //     deploy( clsText, src_hw_cga_cls_text_asm );
        //     #if defined(__sc3000__) || defined(__sg1000__)  || defined(__msx1__) || defined(__coleco__)
        //             deploy( textEncodedAt, src_hw_cga_text_asm );
        //     #endif
        //     deploy( textEncodedAtTextRaw, src_hw_cga_text_at_text_raw_asm );
        //     if ( ! _environment->hasGameLoop ) {
        //         outline0("CALL TEXTATTILEMODERAW");
        //     } else {
        //         outline0("CALL TEXTATTILEMODENMI2RAW");
        //     }
        // }

    } else {

        // if ( ( _environment->currentMode == 2 || _environment->currentMode == 3 ) && !_environment->currentTileMode ) {
            // deploy( clsGraphic, src_hw_cga_cls_graphic_asm );
            // deploy( cgavarsGraphic, src_hw_cga_vars_graphic_asm );
            // deploy( textEncodedAt, src_hw_cga_text_asm );
            // deploy( textEncodedAtGraphic, src_hw_cga_text_at_graphic_asm );
            // if ( ! _environment->hasGameLoop ) {
            //     outline0("CALL TEXTATBITMAPMODE");
            // } else {
            //     outline0("CALL TEXTATBITMAPMODENMI2");
            // }
        // } else {
            // deploy( cgavarsGraphic, src_hw_cga_vars_graphic_asm );
            deploy( clsText, src_hw_cga_cls_text_asm );
            deploy( textEncodedAt, src_hw_cga_text_asm );
            deploy( textEncodedAtText, src_hw_cga_text_at_text_asm );
            outline0("CALL TEXTATTILEMODE");
        // }


    }

}

void cga_initialization( Environment * _environment ) {

    // deploy( cgavars, src_hw_cga_vars_asm );
    deploy_preferred( cgastartup, src_hw_cga_startup_asm );
    
    cpu_call( _environment, "CGASTARTUP" );

    variable_import( _environment, "CURRENTWIDTH", VT_POSITION, 256 );
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION, 192  );
    variable_global( _environment, "CURRENTHEIGHT" );
    variable_import( _environment, "CURRENTTILES", VT_BYTE, 255 );
    variable_global( _environment, "CURRENTTILES" );
    variable_import( _environment, "CURRENTTILESWIDTH", VT_SBYTE, 40 );
    variable_global( _environment, "CURRENTTILESWIDTH" );
    variable_import( _environment, "CURRENTTILESWIDTHX8", VT_WORD, 320 );
    variable_global( _environment, "CURRENTTILESWIDTHX8" );
    variable_import( _environment, "CURRENTTILESHEIGHT", VT_SBYTE, 24 );
    variable_global( _environment, "CURRENTTILESHEIGHT" );
    variable_import( _environment, "FONTWIDTH", VT_BYTE, 8 );
    variable_global( _environment, "FONTWIDTH" );
    variable_import( _environment, "FONTHEIGHT", VT_BYTE, 8 );
    variable_global( _environment, "FONTHEIGHT" );
    variable_import( _environment, "SPRITEADDRESS", VT_ADDRESS, 0x3b00 );
    variable_global( _environment, "SPRITEADDRESS" );    
    variable_import( _environment, "SPRITEAADDRESS", VT_ADDRESS, 0x1800 );
    variable_global( _environment, "SPRITEAADDRESS" );    
    variable_import( _environment, "TEXTADDRESS", VT_ADDRESS, 0x0e * 0x0400 );
    variable_global( _environment, "TEXTADDRESS" );    
    variable_import( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0x2000 );
    variable_global( _environment, "COLORMAPADDRESS" );    
    variable_import( _environment, "PATTERNADDRESS", VT_ADDRESS, 0x0000 );
    variable_global( _environment, "PATTERNADDRESS" );    

    SCREEN_MODE_DEFINE( TILEMAP_MODE_40x25x2, 0, 40, 25, 2, 8, 8, "Text Mode (40x25, b/w)" );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_40x25x16, 0, 40, 25, 16, 8, 8, "Text Mode (40x25, 16 colors)" );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_80x25x2, 0, 80, 25, 2, 8, 8, "Text Mode (80x25, 2 colors)" );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_80x25x16, 0, 80, 25, 16, 8, 8, "Text Mode (80x25, 16 colors)" );
    
    SCREEN_MODE_DEFINE( BITMAP_MODE_320x200x2, 1, 320, 200, 2, 8, 8, "Grahic Mode (320x200, 2 colors)" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_320x200x4, 1, 320, 200, 4, 8, 8, "Grahic Mode (320x200, 4 colors)" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_640x200x2, 1, 640, 200, 2, 8, 8, "Grahic Mode (640x200, 2 colors)" );

    // outline0("CALL TMS9918STARTUP");

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

    variable_import( _environment, "ORIGINX", VT_POSITION, 0 );
    variable_global( _environment, "ORIGINX" );
    variable_import( _environment, "ORIGINY", VT_POSITION, 0 );
    variable_global( _environment, "ORIGINY" );

    variable_import( _environment, "RESOLUTIONX", VT_POSITION, 0 );
    variable_global( _environment, "RESOLUTIONX" );
    variable_import( _environment, "RESOLUTIONY", VT_POSITION, 0 );
    variable_global( _environment, "RESOLUTIONY" );
    
    variable_import( _environment, "TABCOUNT", VT_BYTE, 4 );
    variable_global( _environment, "TABCOUNT" );

    variable_import( _environment, "CLINEX", VT_BYTE, 0 );
    variable_global( _environment, "CLINEX" );

    variable_import( _environment, "CLINEY", VT_BYTE, 0 );
    variable_global( _environment, "CLINEY" );

    variable_import( _environment, "PLOTCPE", VT_BYTE, 0 );
    variable_global( _environment, "PLOTCPE" );

    variable_import( _environment, "TABSTODRAW", VT_BYTE, 0 );
    variable_global( _environment, "TABSTODRAW" );

    variable_import( _environment, "CURRENTMODE", VT_BYTE, 2 );
    variable_global( _environment, "CURRENTMODE" );
    variable_import( _environment, "CURRENTTILEMODE", VT_BYTE, 1 );
    variable_global( _environment, "CURRENTTILEMODE" );

    variable_import( _environment, "SPRITECOUNT", VT_SPRITE, 0 );
    variable_global( _environment, "SPRITECOUNT" );

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

    variable_import( _environment, "IMAGET", VT_BYTE, 0 );
    variable_global( _environment, "IMAGET" );

    variable_import( _environment, "IMAGEY", VT_BYTE, 0 );
    variable_global( _environment, "IMAGEY" );

    variable_import( _environment, "BLITIMAGEBLITTINGADDR", VT_ADDRESS, 0 );
    variable_global( _environment, "BLITIMAGEBLITTINGADDR" );
    variable_import( _environment, "BLITTMPPTR", VT_ADDRESS, 0 );
    variable_global( _environment, "BLITTMPPTR" );
    variable_import( _environment, "BLITTMPPTR2", VT_ADDRESS, 0 );
    variable_global( _environment, "BLITTMPPTR2" );

    variable_import( _environment, "VBLFLAG", VT_BYTE, 0 );
    variable_global( _environment, "VBLFLAG" ); 
    variable_import( _environment, "VDPINUSE", VT_BYTE, 0 );
    variable_global( _environment, "VDPINUSE" );

    variable_import( _environment, "SLICEX", VT_POSITION, 0 );
    variable_global( _environment, "SLICEX" );
    variable_import( _environment, "SLICEY", VT_POSITION, 0 );
    variable_global( _environment, "SLICEY" );
    variable_import( _environment, "SLICEDTARGET", VT_POSITION, 0 );
    variable_global( _environment, "SLICEDTARGET" );

    variable_import( _environment, "CONSOLESA", VT_ADDRESS, 0x0 );
    variable_global( _environment, "CONSOLESA" );
    variable_import( _environment, "CONSOLEHB", VT_BYTE, 0x0 );
    variable_global( _environment, "CONSOLEHB" );
    variable_import( _environment, "CONSOLEWB", VT_BYTE, 0x0 );
    variable_global( _environment, "CONSOLEWB" );

    cga_tilemap_enable( _environment, 40, 24, 1, 8, 8 );

    font_descriptors_init( _environment, 0 );
    
    console_calculate( _environment );

    // _environment->currentRgbConverterFunction = rgbConverterFunction;
    _environment->screenShades = 16;

}

void cga_finalization( Environment * _environment ) {

}

void cga_hscroll_line( Environment * _environment, int _direction, int _overlap ) {

}

void cga_hscroll_screen( Environment * _environment, int _direction, int _overlap ) {

}

void cga_back( Environment * _environment ) {

}

void cga_cline( Environment * _environment, char * _characters ) {

}

int cga_image_size( Environment * _environment, int _width, int _height, int _mode ) {

}

static int calculate_images_size( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

}

static int calculate_sequence_size( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

}

Variable * cga_sprite_converter( Environment * _environment, char * _source, int _width, int _height, int _depth, RGBi * _color, int _slot_x, int _slot_y ) {

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );

    return result;

}

Variable * cga_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

    return cga_new_image( _environment, 8, 8, BITMAP_MODE_STANDARD );

}

void cga_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

}

void cga_put_image( Environment * _environment, Resource * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _flags ) {

}

void cga_wait_vbl( Environment * _environment ) {

}

Variable * cga_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(new image)" );

    return result;

}

Variable * cga_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

    Variable * result = variable_temporary( _environment, VT_IMAGES, "(new images)" );

    return result;

}

Variable * cga_new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

    Variable * result = variable_temporary( _environment, VT_SEQUENCE, "(new sequence)" );

    return result;

}

void cga_get_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _palette ) {

}

void cga_scroll( Environment * _environment, int _dx, int _dy ) {

}

void cga_put_tile( Environment * _environment, char * _tile, char * _x, char * _y ) {

}

void cga_move_tiles( Environment * _environment, char * _tile, char * _x, char * _y ) {

}

void cga_put_tiles( Environment * _environment, char * _tile, char * _x, char * _y, char *_w, char *_h ) {

}

void cga_tile_at( Environment * _environment, char * _x, char * _y, char *_result ) {

}

void cga_use_tileset( Environment * _environment, char * _tileset ) {

}

Variable * cga_get_raster_line( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_WORD, "(raster line)" );

    variable_store( _environment, result->name, 0 );

    return result;
    
}

void cga_move_memory_video( Environment * _environment, char * _from, char * _to, char * _size ) {

}

void cga_move_video_memory( Environment * _environment, char * _from, char * _to, char * _size ) {

}

void cga_colors_vars( Environment * _environment, char * _foreground_color, char * _background_color ) {

}

void cga_slice_image( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination ) {

}

void cga_slice_image_copy( Environment * _environment, char * _image,  char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination ) {

}

void cga_slice_image_extract( Environment * _environment, char * _image,  char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination ) {

}

int cga_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette ) {

    int paletteColorCount = rgbi_extract_palette(_environment, _data, _width, _height, _depth, _palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    memcpy( _palette, palette_match( _palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) ), paletteColorCount * sizeof( RGBi ) );

    int uniquePaletteCount = 0;

    memcpy( _palette, palette_remove_duplicates( _palette, paletteColorCount, &uniquePaletteCount ), paletteColorCount * sizeof( RGBi ) );

    return uniquePaletteCount;

}

void cga_calculate_sequence_frame_offset( Environment * _environment, char * _offset, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

}

void cga_flip_image( Environment * _environment, Resource * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _direction ) {

}

void cga_screen( Environment * _environment, char * _x, char * _y, char * _c ) {

}

#endif