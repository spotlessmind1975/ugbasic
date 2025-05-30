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

#ifdef __vic20__

#include "../ugbc.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
    { 0x00, 0x00, 0x00, 0xff, 0, "BLACK" },
    { 0xff, 0xff, 0xff, 0xff, 1, "WHITE" },
    { 0x88, 0x00, 0x00, 0xff, 2, "RED" },
    { 0xaa, 0xff, 0xe6, 0xff, 3, "CYAN" },
    { 0xcc, 0x44, 0xcc, 0xff, 4, "VIOLET" },
    { 0x00, 0xcc, 0x55, 0xff, 5, "GREEN" },
    { 0x00, 0x00, 0xaa, 0xff, 6, "BLUE" },
    { 0xee, 0xee, 0x77, 0xff, 7, "YELLOW" },
    { 0xa1, 0x68, 0x3c, 0xff, 8, "ORANGE" },
    { 0xdd, 0x88, 0x65, 0xff, 9, "BROWN" },
    { 0xff, 0x77, 0x77, 0xff, 10, "LIGHT_RED" },
    { 0x33, 0x33, 0x33, 0xff, 11, "DARK_GREY" },
    { 0x77, 0x77, 0x77, 0xff, 12, "GREY" },
    { 0xaa, 0xff, 0x66, 0xff, 13, "LIGHT GREEN" },
    { 0x00, 0x88, 0xff, 0xff, 14, "LIGHT BLUE" },
    { 0xbb, 0xbb, 0xbb, 0xff, 15, "LIGHT GREY" }
};

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

RGBi * vic1_image_nearest_system_color( RGBi * _color ) {

    unsigned int minDistance = 0xffff;
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
 * @brief <i>VIC</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with another sprite. The result (0 = no collision, 0xff = 
 * collision occurred) is returned in the output variable.
 * 
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void vic1_collision( Environment * _environment, char * _sprite_mask, char * _result ) {

}

/**
 * @brief <i>VIC</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with a tile. The result (0 = no collision, 0xff = 
 * collision occurred) is returned in the output variable.
 * 
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void vic1_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

}

/**
 * @brief <i>VIC</i>: emit code to change border color
 * 
 * This function can be used to issue code aimed at changing the
 * border color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _border_color Border color to use
 */
void vic1_border_color( Environment * _environment, char * _border_color ) {

    outline0("LDA $900F" );
    outline0("AND #$F8" );
    outline0("STA $900F");
    outline1("LDA %s", _border_color );
    outline0("AND #$07" );
    outline0("ORA $900F" );
    outline0("STA $900F" );

}

/**
 * @brief <i>VIC</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void vic1_background_color( Environment * _environment, int _index, int _background_color ) {
 
    outline1("LDA #$%2.2x", ( _background_color >> 4 ) );
    outline0("STA MATHPTR0");
    outline0("LDA $900F");
    outline0("AND #$0F");
    outline0("ORA MATHPTR0");
    outline0("STA $900F");
}

/**
 * @brief <i>VIC</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void vic1_background_color_vars( Environment * _environment, char * _index, char * _background_color ) {
 
    outline1("LDA %s", _background_color );
    outline0("ASL A");
    outline0("ASL A");
    outline0("ASL A");
    outline0("ASL A");
    outline0("STA MATHPTR0");
    outline0("LDA $900F");
    outline0("AND #$0F");
    outline0("ORA MATHPTR0");
    outline0("STA $900F");
}

/**
 * @brief <i>VIC</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void vic1_background_color_semivars( Environment * _environment, int _index, char * _background_color ) {
 
    outline1("LDA %s", _background_color );
    outline0("ASL A");
    outline0("ASL A");
    outline0("ASL A");
    outline0("ASL A");
    outline0("STA MATHPTR0");
    outline0("LDA $900F");
    outline0("AND #$0F");
    outline0("ORA MATHPTR0");
    outline0("STA $900F");
}

/**
 * @brief <i>VIC</i>: emit code to retrieve background color
 * 
 * This function can be used to issue code aimed at retrieving the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void vic1_background_color_get_vars( Environment * _environment, char * _index, char * _background_color ) {
 
    outline0("LDA $900F");
    outline0("AND #$F0");
    outline0("LSR A");
    outline0("LSR A");
    outline0("LSR A");
    outline0("LSR A");
    outline1("STA %s", _background_color );

}


/**
 * @brief <i>VIC</i>: emit code to change common sprite's color 
 * 
 * This function can be used to issue code aimed at changing the
 * common color of the sprites.

 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _common_color Index of the color to use
 */
void vic1_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {
 
}

/**
 * @brief <i>VIC</i>: emit code to set raster irq
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
void vic1_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>VIC</i>: emit code to wait for next raster irq
 * 
 * This function outputs assembly code needed to wait for the
 * next raster. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 *
 */
void vic1_next_raster( Environment * _environment ) {

}

/**
 * @brief <i>VIC</i>: emit code to wait for next raster irq at different position
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
void vic1_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

void vic1_bank_select( Environment * _environment, int _bank ) {
    
}

static int rgbConverterFunction( int _red, int _green, int _blue ) {
    
    int colorIndex = 0;
    unsigned int minDistance = 0xffffffff;
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

int vic1_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    _screen_mode->selected = 1;

    // deploy( bitmap, src_hw_vic1_bitmap_asm );
    Variable * colormapAddress = variable_retrieve( _environment, "COLORMAPADDRESS" );

    _environment->fontWidth = 8;
    _environment->fontHeight = 8;
    _environment->screenTiles = 255;
    switch( _screen_mode->id ) {
        case BITMAP_MODE_STANDARD:

            outline0("LDA $9005");
            outline0("AND #$F0");
            outline0("ORA #$0E");
            outline0("STA $9005");

            _environment->screenTilesWidth = 22;
            _environment->screenTilesHeight = 23;

            break;
        case TILEMAP_MODE_STANDARD:
            _environment->screenTilesWidth = 22;
            _environment->screenTilesHeight = 23;

            outline0("LDA $9005");
            outline0("AND #$F0");
            outline0("STA $9005");

            vic1_cls( _environment );

            break;
        default:
            CRITICAL_SCREEN_UNSUPPORTED( _screen_mode->id );
    }

    _environment->screenWidth = _environment->screenTilesWidth * 8;
    _environment->screenHeight = _environment->screenTilesHeight * 8;
    _environment->consoleTilesWidth = _environment->screenTilesWidth;
    _environment->consoleTilesHeight = _environment->screenTilesHeight;

    _environment->screenColors = 2;
    _environment->screenShades = 8;

    cpu_store_16bit( _environment, "CURRENTWIDTH", _environment->screenWidth );
    cpu_store_16bit( _environment, "CURRENTHEIGHT", _environment->screenHeight );
    cpu_store_8bit( _environment, "CURRENTTILES", _environment->screenTiles );
    cpu_store_8bit( _environment, "CURRENTTILESWIDTH", _environment->screenTilesWidth );
    cpu_store_8bit( _environment, "CURRENTTILESHEIGHT", _environment->screenTilesHeight );

    console_init( _environment );

    if (_environment->vestigialConfig.clsImplicit ) {
        vic1_cls( _environment );
    }

}

void console_calculate( Environment * _environment ) {

    int consoleSA = 0;
    int consoleCA = 0;

    switch( _environment->currentMode ) {
        case BITMAP_MODE_STANDARD:
        case TILEMAP_MODE_STANDARD:
            consoleSA = 0x1000 + (_environment->activeConsole.y1*22)+_environment->activeConsole.x1;
            consoleCA = 0x9400 + (_environment->activeConsole.y1*22)+_environment->activeConsole.x1;
            _environment->currentModeBW = 1;
            break;
        default:
            CRITICAL_SCREEN_UNSUPPORTED( _environment->currentMode );
    }

    int consoleWB = _environment->activeConsole.width * _environment->currentModeBW;
    int consoleHB = _environment->activeConsole.height;

    cpu_store_16bit( _environment, "CONSOLESA", consoleSA );
    cpu_store_16bit( _environment, "CONSOLECA", consoleCA );
    cpu_store_8bit( _environment, "CONSOLEWB", consoleWB );
    cpu_store_8bit( _environment, "CONSOLEHB", consoleHB );

}

void console_calculate_vars( Environment * _environment ) {

    outline0( "JSR CONSOLECALCULATE" );

}

void vic1_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors, 8, 8 );

    if ( mode ) {
        vic1_screen_mode_enable( _environment, mode );

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 0 );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 0;
    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void vic1_bitmap_disable( Environment * _environment ) {

}

void vic1_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors, _tile_width, _tile_height );

    if ( mode ) {
        vic1_screen_mode_enable( _environment, mode );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 1;

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 1 );

    } else {
        WARNING_SCREEN_MODE( -1 );
    }


}

void vic1_bitmap_at( Environment * _environment, char * _address ) {

}

void vic1_colormap_at( Environment * _environment, char * _address ) {

}

void vic1_textmap_at( Environment * _environment, char * _address ) {

}

void vic1_pset_int( Environment * _environment, int _x, int _y, int *_c ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm);
    deploy( plot, src_hw_vic1_plot_asm );
    
    if ( _c ) {
        outline1("LDA #$%2.2x", ( *_c & 0xff ) );
    } else {
        Variable * c = variable_retrieve( _environment, "PEN" );
        outline1("LDA %s", c->realName );
    }
    outline0("STA PLOTCPE");
    outline1("LDA %2.2x", (_x & 0xff ) );
    outline0("STA PLOTX");
    outline1("LDA %2.2x", ( ( _x >> 8 ) & 0xff ) );
    outline0("STA PLOTX+1");
    outline1("LDA %2.2x", ( _y & 0xff ) );
    outline0("STA PLOTY");
    outline0("LDA #1");
    outline0("STA PLOTM");
    outline0("JSR PLOT");

}

void vic1_pset_vars( Environment * _environment, char *_x, char *_y, char *_c ) {

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    Variable * c;
    
    if ( _c ) {
        c = variable_retrieve_or_define( _environment, _c, VT_COLOR, 0 );
    } else {
        c = variable_retrieve( _environment, "PEN" );
    }

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm);
    deploy( plot, src_hw_vic1_plot_asm );
    
    outline1("LDA %s", c->realName );
    outline0("STA PLOTCPE");
    outline1("LDA %s", x->realName );
    outline0("STA PLOTX");
    if ( VT_BITWIDTH( x->type ) > 8 ) {
        outline1("LDA %s", address_displacement(_environment, x->realName, "1") );
    } else {
        outline0("LDA #0");
    }
    outline0("STA PLOTX+1");
    outline1("LDA %s", y->realName );
    outline0("STA PLOTY");
    outline0("LDA #1");
    outline0("STA PLOTM");
    outline0("JSR PLOT");

}

void vic1_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );
    Variable * result = variable_retrieve( _environment, _result );

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm);
    deploy( plot, src_hw_vic1_plot_asm );
    
    outline1("LDA %s", x->realName );
    outline0("STA PLOTX");
    outline1("LDA %s", address_displacement(_environment, x->realName, "1") );
    outline0("STA PLOTX+1");
    outline1("LDA %s", y->realName );
    outline0("STA PLOTY");
    outline0("LDA #3");
    outline0("STA PLOTM");
    outline0("JSR PLOT");
    outline0("LDA PLOTM");
    outline1("STA %s", result->realName);

}

void vic1_screen_on( Environment * _environment ) {

}

void vic1_screen_off( Environment * _environment ) {

}

void vic1_screen_rows( Environment * _environment, char * _rows ) {

}

void vic1_screen_columns( Environment * _environment, char * _columns ) {

}

void vic1_sprite_data_set( Environment * _environment, char * _sprite, char * _address ) {

}

void vic1_sprite_data_from( Environment * _environment, char * _sprite, char * _address ) {

}

void vic1_sprite_enable( Environment * _environment, char * _sprite ) {

}

void vic1_sprite_disable( Environment * _environment, char * _sprite ) {

}

void vic1_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

}

void vic1_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

}

void vic1_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

}

void vic1_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

}

void vic1_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

}

void vic1_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void vic1_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void vic1_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

}

void vic1_sprite_priority( Environment * _environment, char * _sprite, char * _priority ) {

}

void vic1_tiles_at( Environment * _environment, char * _address ) {

}

void vic1_vertical_scroll( Environment * _environment, char * _displacement ) {

}

void vic1_horizontal_scroll( Environment * _environment, char * _displacement ) {

}

void vic1_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline0("LDA #$00");
    outline0("STA TMPPTR");
    outhead1("%sfirst:", label );
    outline0("LDA #$01");
    outhead1("%ssecond:", label );
    outline0("CMP $9004");
    outline1("BNE %ssecond", label);
    outhead1("%sthird:", label );
    outline0("CMP $9004");
    outline1("BEQ %sthird", label);
    outline0("INC TMPPTR");
    outline0("LDA TMPPTR");
    outline1("CMP %s", _timing );
    outline1("BNE %sfirst", label );

}

void vic1_get_width( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTWIDTH" );
    outline1("STA %s", _result );
    outline0("LDA CURRENTWIDTH+1" );
    outline1("STA %s", address_displacement(_environment, _result, "1") );

}

void vic1_tiles_get( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILES" );
    outline1("STA %s", _result );

}

void vic1_get_height( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTHEIGHT" );
    outline1("STA %s", _result );
    outline0("LDA CURRENTHEIGHT+1" );
    outline1("STA %s", address_displacement(_environment, _result, "1") );

}

void vic1_cls( Environment * _environment ) {
    
    deploy( cls, src_hw_vic1_cls_asm );

    outline0("JSR CLS");

}

void vic1_cls_box( Environment * _environment, char * _x1, char * _y1, char * _w, char * _h ) {
    
}

void vic1_scroll_text( Environment * _environment, int _direction, int _overlap ) {

    if ( _direction > 0 ) {
        deploy_preferred( vScrollTextDown, src_hw_vic1_vscroll_text_down_asm );
        outline1("LDA #$%2.2x", (unsigned char)(_overlap&0xff) );
        outline0("STA PORT" );
        outline0("JSR VSCROLLTDOWN");
    } else {
        deploy_preferred( vScrollTextUp, src_hw_vic1_vscroll_text_up_asm );
        outline1("LDA #$%2.2x", (unsigned char)(_overlap&0xff) );
        outline0("STA PORT" );
        outline0("JSR VSCROLLTUP");
    }

}

void vic1_text( Environment * _environment, char * _text, char * _text_size, int _raw ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm);
    deploy_preferred( vScrollTextUp, src_hw_vic1_vscroll_text_up_asm );
    deploy_preferred( vScrollTextDown, src_hw_vic1_vscroll_text_down_asm );
    deploy( cls, src_hw_vic1_cls_asm );

    if ( _environment->currentMode > 0 ) {
        _environment->fontConfig.schema = FONT_SCHEMA_ALPHA;
        font_descriptors_init( _environment, 0 );
    }

    outline1("LDA %s", _text);
    outline0("STA TEXTPTR" );
    outline1("LDA %s", address_displacement(_environment, _text, "1"));
    outline0("STA TEXTPTR+1" );
    outline1("LDA %s", _text_size);
    outline0("STA TEXTSIZE" );

    if ( _raw ) {
        deploy_deferred( textEncodedAtTextRaw, src_hw_vic1_text_at_raw_asm );
        outline0("JSR TEXTATRAW");
    } else {
        deploy_deferred( textEncodedAtText, src_hw_vic1_text_at_asm );
        outline0("JSR TEXTAT");
    }

}

void vic1_initialization( Environment * _environment ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy_deferred( vic1startup, src_hw_vic1_startup_asm );

    variable_import( _environment, "CURRENTMODE", VT_BYTE, 0 );
    variable_global( _environment, "CURRENTMODE" );
    variable_import( _environment, "CURRENTTILEMODE", VT_BYTE, 1 );
    variable_global( _environment, "CURRENTTILEMODE" );

    variable_import( _environment, "CURRENTWIDTH", VT_POSITION, 166 );
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION, 184  );
    variable_global( _environment, "CURRENTHEIGHT" );
    variable_import( _environment, "CURRENTTILES", VT_BYTE, 255 );
    variable_global( _environment, "CURRENTTILES" );
    variable_import( _environment, "CURRENTTILESWIDTH", VT_SBYTE, 22 );
    variable_global( _environment, "CURRENTTILESWIDTH" );
    variable_import( _environment, "CURRENTTILESHEIGHT", VT_SBYTE, 23 );
    variable_global( _environment, "CURRENTTILESHEIGHT" );
    variable_import( _environment, "FONTWIDTH", VT_BYTE, 8 );
    variable_global( _environment, "FONTWIDTH" );
    variable_import( _environment, "FONTHEIGHT", VT_BYTE, 8 );
    variable_global( _environment, "FONTHEIGHT" );

    SCREEN_MODE_DEFINE( TILEMAP_MODE_STANDARD, 0, 22, 23, 8, 8, 8, "Standard Character Mode" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_STANDARD, 1, 176, 184, 8, 8, 8, "Standard Bitmap Mode (tilemapped)" );
    // SCREEN_MODE_DEFINE( BITMAP_MODE_EXTENDED, 1, 128, 128, 8, 8, 8, "Extended Bitmap Mode" );

    outline0("JSR VIC1STARTUP");

    variable_import( _environment, "XGR", VT_POSITION, 0 );
    variable_global( _environment, "XGR" );
    variable_import( _environment, "YGR", VT_POSITION, 0 );
    variable_global( _environment, "YGR" );
    variable_import( _environment, "LINE", VT_WORD, (unsigned short) (0xffff) );
    variable_global( _environment, "LINE" );
    variable_import( _environment, "TABCOUNT", VT_BYTE, 4 );
    variable_global( _environment, "TABCOUNT" );

    variable_import( _environment, "CLIPX1", VT_POSITION, 0 );
    variable_global( _environment, "CLIPX1" );
    variable_import( _environment, "CLIPX2", VT_POSITION, 165 );
    variable_global( _environment, "CLIPX2" );
    variable_import( _environment, "CLIPY1", VT_POSITION, 0 );
    variable_global( _environment, "CLIPY1" );
    variable_import( _environment, "CLIPY2", VT_POSITION, 183 );
    variable_global( _environment, "CLIPY2" );

    variable_import( _environment, "ORIGINX", VT_POSITION, 0 );
    variable_global( _environment, "ORIGINX" );
    variable_import( _environment, "ORIGINY", VT_POSITION, 0 );
    variable_global( _environment, "ORIGINY" );

    variable_import( _environment, "RESOLUTIONX", VT_POSITION, 0 );
    variable_global( _environment, "RESOLUTIONX" );
    variable_import( _environment, "RESOLUTIONY", VT_POSITION, 0 );
    variable_global( _environment, "RESOLUTIONY" );

    cpu_move_16bit( _environment, "CURRENTWIDTH", "RESOLUTIONX" );
    cpu_move_16bit( _environment, "CURRENTHEIGHT", "RESOLUTIONY" );

    _environment->fontWidth = 8;
    _environment->fontHeight = 8;
    _environment->screenTilesWidth = 22;
    _environment->screenTilesHeight = 23;
    _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
    _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
    _environment->screenColors = 16;
    _environment->consoleTilesWidth = 22;
    _environment->consoleTilesHeight = 23;

    console_init( _environment );

    font_descriptors_init( _environment, 1 );

    _environment->currentRgbConverterFunction = rgbConverterFunction;
    _environment->screenShades = 8;

    if (_environment->vestigialConfig.clsImplicit ) {
        vic1_cls( _environment );
    }
    
}

void vic1_finalization( Environment * _environment ) {

    if ( ! _environment->deployed.vic1startup ) {
        cpu_label( _environment, "VIC1STARTUP" );
        outline0( "RTS" );
        cpu_label( _environment, "MUSICPLAYER" );
        outline0( "RTS" );
    }

    if ( _environment->vestigialConfig.clsImplicit ) {
        deploy( cls, src_hw_vic1_cls_asm );
    }

}

void vic1_hscroll_line( Environment * _environment, int _direction, int _overlap ) {

    deploy_preferred( textHScroll, src_hw_vic1_hscroll_text_asm );

    Variable * y = variable_retrieve( _environment, "YCURSYS" );
    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );
    outline1("LDA #$%2.2x", ( _overlap & 0xff ) );
    outline0("STA PORT" );
    outline1("LDA %s", y->realName );
    outline0("STA CLINEY");

    outline0("JSR HSCROLLLT");

}

void vic1_hscroll_screen( Environment * _environment, int _direction, int _overlap ) {

    deploy_preferred( textHScroll, src_hw_vic1_hscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );
    outline1("LDA #$%2.2x", ( _overlap & 0xff ) );
    outline0("STA PORT" );

    outline0("JSR HSCROLLST");
}

void vic1_back( Environment * _environment ) {

    deploy( back, src_hw_vic1_back_asm );

    outline0("JSR BACK");

}

void vic1_cline( Environment * _environment, char * _characters ) {

    deploy( textCline, src_hw_vic1_cline_asm );
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

int vic1_image_size( Environment * _environment, int _width, int _height, int _mode ) {

   switch( _mode ) {

        case BITMAP_MODE_STANDARD:
            return 3 + ( _width >> 3 ) * ( _height );
            break;
        case TILEMAP_MODE_STANDARD:
            break;
    }

    return 0;

}

static int calculate_images_size( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

   switch( _mode ) {

        case BITMAP_MODE_STANDARD:
            return 3 + ( 3 + ( _width >> 3 ) * ( _height ) ) * _frames;
            break;
        case TILEMAP_MODE_STANDARD:
            break;
    }

    return 0;

}

static int calculate_sequence_size( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

   switch( _mode ) {

        case BITMAP_MODE_STANDARD:
            return 3 + ( ( 3 + ( _width >> 3 ) * ( _height ) ) * _frames ) * _sequences;
            break;
        case TILEMAP_MODE_STANDARD:
            break;
    }

    return 0;

}


static Variable * vic1_image_converter_bitmap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    image_converter_asserts( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    if ( _environment->freeImageWidth ) {
        if ( _width % 8 ) {
            _width = ( ( ( _width - 1 ) / 8 ) - 1 ) * 8;
        }
        if ( _frame_width % 8 ) {
            _frame_width = ( ( ( _frame_width - 1 ) / 8 ) - 1 ) * 8;
        }
    }
    
    if ( _environment->freeImageHeight ) {
        if ( _height % 8 ) {
            _height = ( ( ( _height - 1 ) / 8 ) - 1 ) * 8;
        }
        if ( _frame_height % 8 ) {
            _frame_height = ( ( ( _frame_height - 1 ) / 8 ) - 1 ) * 8;
        }
    }

    RGBi palette[MAX_PALETTE];

    int colorUsed = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, 1 /* sorted */);

    if (colorUsed > 2) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( colorUsed );
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = colorUsed;

    int i, j, k;

    for( i=0; i<colorUsed; ++i ) {
        int minDistance = 0xffff;
        int colorIndex = 0;
        for (j = 0; j < sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++j) {
            int distance = rgbi_distance(&SYSTEM_PALETTE[j], &palette[i]);
            // printf("%d <-> %d [%d] = %d [min = %d]\n", i, j, SYSTEM_PALETTE[j].index, distance, minDistance );
            if (distance < minDistance) {
                // printf(" candidated...\n" );
                for( k=0; k<i; ++k ) {
                    if ( palette[k].index == SYSTEM_PALETTE[j].index ) {
                        // printf(" ...used!\n" );
                        break;
                    }
                }
                if ( k>=i ) {
                    // printf(" ...ok! (%d)\n", SYSTEM_PALETTE[j].index );
                    minDistance = distance;
                    colorIndex = j;
                }
            }
        }
        palette[i].index = SYSTEM_PALETTE[colorIndex].index;
        strcopy( palette[i].description, SYSTEM_PALETTE[colorIndex].description );
        // printf("%d) %d %2.2x%2.2x%2.2x\n", i, palette[i].index, palette[i].red, palette[i].green, palette[i].blue);
    }

    memcpy( result->originalPalette, palette, MAX_PALETTE * sizeof( RGBi ) );

    int bufferSize = vic1_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_STANDARD );

    // printf("bufferSize = %d\n", bufferSize );

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
            if ( _depth > 3 ) {
                rgb.alpha = *(_source + 3);
            } else {
                rgb.alpha = 255;
            }

            for( i=0; i<colorUsed; ++i ) {
                if ( rgbi_equals_rgba( &palette[i], &rgb ) ) {
                    break;
                }
            }

            // printf("%d", i );

            // Calculate the relative tile
            tile_y = (image_y >> 3);
            tile_x = (image_x >> 3);
            
            // Calculate the offset starting from the tile surface area
            // and the bit to set.
            offset = (tile_y * 8 *( _frame_width >> 3 ) ) + (tile_x * 8) + (image_y & 0x07);
            bitmask = 1 << ( 7 - (image_x & 0x7) );

            if ( i == 1 ) {
                *( buffer + offset + 2) |= bitmask;
            } else {
                *( buffer + offset + 2) &= ~bitmask;
            }

            offset = tile_y * ( _frame_width >> 3 ) + tile_x;
            *( buffer + 2 + ( ( _frame_width >> 3 ) * _frame_height ) + offset ) = ( palette[1].index << 4 ) | palette[0].index; 

            _source += 3;

        }

        _source += 3 * ( _width - _frame_width );

        // printf("\n" );

    }

    // printf("\n----\n\n");

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    // printf("----\n");

    return result;

}

static Variable * vic1_image_converter_multicolor_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    image_converter_asserts( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    if ( _environment->freeImageWidth ) {
        if ( _width % 8 ) {
            _width = ( ( ( _width - 1 ) / 8 ) - 1 ) * 8;
        }
        if ( _frame_width % 8 ) {
            _frame_width = ( ( ( _frame_width - 1 ) / 8 ) - 1 ) * 8;
        }
    }
    
    if ( _environment->freeImageHeight ) {
        if ( _height % 8 ) {
            _height = ( ( ( _height - 1 ) / 8 ) - 1 ) * 8;
        }
        if ( _frame_height % 8 ) {
            _frame_height = ( ( ( _frame_height - 1 ) / 8 ) - 1 ) * 8;
        }
    }

    RGBi palette[MAX_PALETTE];

    int colorUsed = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, 1 /* sorted */);

    if (colorUsed > 4) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( colorUsed );
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = colorUsed;

    int i, j, k;

    for( i=0; i<colorUsed; ++i ) {
        int minDistance = 0xffff;
        int colorIndex = 0;
        for (j = 0; j < sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++j) {
            int distance = rgbi_distance(&SYSTEM_PALETTE[j], &palette[i]);
            // printf("%d <-> %d [%d] = %d [min = %d]\n", i, j, SYSTEM_PALETTE[j].index, distance, minDistance );
            if (distance < minDistance) {
                // printf(" candidated...\n" );
                for( k=0; k<i; ++k ) {
                    if ( palette[k].index == SYSTEM_PALETTE[j].index ) {
                        // printf(" ...used!\n" );
                        break;
                    }
                }
                if ( k>=i ) {
                    // printf(" ...ok! (%d)\n", SYSTEM_PALETTE[j].index );
                    minDistance = distance;
                    colorIndex = j;
                }
            }
        }
        palette[i].index = SYSTEM_PALETTE[colorIndex].index;
        strcopy( palette[i].description, SYSTEM_PALETTE[colorIndex].description );
        // printf("%d) %d %2.2x%2.2x%2.2x\n", i, palette[i].index, palette[i].red, palette[i].green, palette[i].blue);
    }

    memcpy( result->originalPalette, palette, MAX_PALETTE * sizeof( RGBi ) );

    int bufferSize = 3 + ( ( _frame_width >> 2 ) * _frame_height ) + 2 * ( ( _frame_width >> 2 ) * ( _frame_height >> 3 ) ) + 1;
    
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

    *(buffer) = _width;
    *(buffer+1) = _height;

    _source += ( ( _offset_y * _width ) + _offset_x ) * 3;

    // Loop for all the source surface.
    for (image_y = _offset_y; image_y < _height; ++image_y) {
        for (image_x = _offset_x; image_x < _width; ++image_x) {

            // Take the color of the pixel
            rgb.red = *_source;
            rgb.green = *(_source + 1);
            rgb.blue = *(_source + 2);
            if ( _depth > 3 ) {
                rgb.alpha = *(_source + 3);
            } else {
                rgb.alpha = 255;
            }

            // Calculate the relative tile
            tile_y = (image_y >> 3);
            tile_x = (image_x >> 2);

            // Calculate the offset starting from the tile surface area
            // and the bit to set.
            offset = (tile_y * 8 *( _frame_width >> 2 ) ) + (tile_x * 8) + (image_y & 0x07);
            offsetc = (tile_y * ( _frame_width >> 2 ) ) + (tile_x);

            int minDistance = 0xffff;
            int colorIndex = 0;

            for( i=0; i<colorUsed; ++i ) {
                if ( rgbi_equals_rgba( &palette[i], &rgb ) ) {
                    break;
                }
            }

            colorIndex = i;

            // printf( "%1.1x", colorIndex );

            bitmask = colorIndex << (6 - ((image_x & 0x3) * 2));

            switch( colorIndex ) {
                case 0:
                    *(buffer + 2 + ( ( _frame_width >> 2 ) * _frame_height ) + 2 * ( _frame_width >> 2 ) * ( _frame_height >> 3 ) ) = palette[colorIndex].index;
                    break;
                case 1:
                    *(buffer + 2 + ( ( _frame_width >> 2 ) * _frame_height ) + offsetc ) &= 0x0f;
                    *(buffer + 2 + ( ( _frame_width >> 2 ) * _frame_height ) + offsetc ) |= ( palette[colorIndex].index << 4 );
                    break;
                case 2:
                    *(buffer + 2 + ( ( _frame_width >> 2 ) * _frame_height ) + offsetc ) &= 0xf0;
                    *(buffer + 2 + ( ( _frame_width >> 2 ) * _frame_height ) + offsetc ) |= palette[colorIndex].index;
                    break;
                case 3:
                    *(buffer + 2 + ( ( _frame_width >> 2 ) * _frame_height ) + ( _frame_width >> 2 ) * ( _frame_height >> 3 ) + offsetc ) = palette[colorIndex].index;
                    break;

            }

            *(buffer + 2 + offset) |= bitmask;

            _source += 3;

        }

        _source += ( _width - _frame_width ) * 3;

        // printf("\n" );
    }

    // for(i=0; i<4; ++i ) {
    //     printf( "%1.1x = %2.2x\n", i, palette[i].index );
    // }

    // printf("\n" );
    // printf("\n" );

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    return result;

}


/////////////////////////////////////////////////////////////////////////

/**
 * This method can be used to convert 
 *     8x8 RGB (3 bytes) pixel (_source) [8x8x3 = 192 bytes]
 * into 
 *     8x8 bitmap (1 bit) pixel + 1 (byte) [8x1 + 1 = 9 bytes]
 *       foreground and background color (_dest)
 * 
 * Since the 8x8 pixel area belong to a larger picture,
 * this function will need the picture _width in order
 * to move to the next line to analyze.
 */
static void vic1_image_converter_tile( Environment * _environment, char * _source, char * _dest, int _width, int _depth, int _source_width ) {

    int colorIndexesCount[COLOR_COUNT];
    memset(colorIndexesCount, 0, COLOR_COUNT * sizeof( int ) );
    int trans = 0;

    char * source = _source;

    // Clear the box and colors
    memset( _dest, 0, 9 );

    // Loop for all the box surface
    for (int y=0; y<8; ++y) {
        for (int x=0; x<8; ++x) {

            RGBi rgb;

            memset( &rgb, 0, sizeof( RGBi ) );

            // Take the color of the pixel
            rgb.red = *source;
            rgb.green = *(source + 1);
            rgb.blue = *(source + 2);
            if ( _depth > 3 ) {
                rgb.alpha = *(_source + 3);
            } else {
                rgb.alpha = 255;
            }
            if ( rgb.alpha == 0 ) {
                rgb.red = 0;
                rgb.green = 0;
                rgb.blue = 0;
            }

            if ( rgb.alpha < 255 ) {
                trans = 1;
            } else {
                RGBi *systemRgb = vic1_image_nearest_system_color( &rgb );
                ++colorIndexesCount[systemRgb->index];
            }

            source += _depth;

        }

        source += _depth * ( _source_width - 8 );

    }

    int colorBackground = 0;
    int colorBackgroundMax = 0;
    int colorForeground = 0;
    int colorForegroundMax = 0;
    for( int xx = 0; xx<COLOR_COUNT; ++xx ) {
        if ( colorIndexesCount[xx] > colorBackgroundMax ) {
            colorBackground = xx;
            colorBackgroundMax = colorIndexesCount[xx];
        };
    }

    colorIndexesCount[colorBackground] = 0;

    for( int xx = 0; xx<COLOR_COUNT; ++xx ) {
        if ( colorIndexesCount[xx] > colorForegroundMax ) {
            colorForeground = xx;
            colorForegroundMax = colorIndexesCount[xx];
        };
    }

    if ( colorForeground == 0 ) {
        colorForeground = colorBackground; 
        colorBackground = 0;
    }

    if ( trans ) {
        if ( colorForeground == 0 ) {
            colorForeground = colorBackground; 
            colorBackground = 0;
        } else {
            colorBackground = 0;
        }
    }

    if ( colorForeground == colorBackground ) {
        colorForeground = ( colorBackground == 0 ) ? 1 : 0;
    }

    source = _source;

    for (int y=0; y<8; ++y) {
        for (int x=0; x<8; ++x) {

            RGBi rgb;

            memset( &rgb, 0, sizeof( RGBi ) );

            rgb.red = *source;
            rgb.green = *(source + 1);
            rgb.blue = *(source + 2);
            if ( _depth > 3 ) {
                rgb.alpha = *(_source + 3);
            } else {
                rgb.alpha = 255;
            }
            if ( rgb.alpha == 0 ) {
                rgb.red = 0;
                rgb.green = 0;
                rgb.blue = 0;
            }

            RGBi *systemRgb = vic1_image_nearest_system_color( &rgb );

            char bitmask = 1 << ( 7 - ((x) & 0x7) );

            if ( rgb.alpha < 255 ) {
                *( _dest + y ) &= ~bitmask;
                adilinepixel(colorBackground);
            } else {
                if ( systemRgb->index != colorBackground ) {
                    adilinepixel(colorForeground);
                    *( _dest + y ) |= bitmask;
                    // printf("*");
                } else {
                   adilinepixel(colorBackground);
                     *( _dest + y ) &= ~bitmask;
                    // printf(" ");
                }
            }

            source += _depth;

        }

        source += _depth * ( _source_width - 8 );

    }

    *( _dest + 8 ) = colorForeground | ( colorBackground << 4 ) ;

}

/**
 * This method can be used to convert 
 *     WxH RGB (3/4 bytes) pixel (_source) [WxHx3/4 bytes]
 * into 
 *     WxH bitmap (1 bit) pixel + (W/8xH + W/8xH/8) (bytes)
 *       foreground and background color (_dest)
 * 
 * Since the WXH pixel area could belong to a larger picture,
 * this function will need the picture _source_width in order
 * to move to the next line to analyze.
 */
static void vic1_image_converter_tiles( Environment * _environment, char * _source, char * _dest, int _width, int _height, int _depth, int _source_width ) {

    int bitmapSize = ( _width>>3 ) * _height;
    int colormapSize = ( _width>>3 ) * (_height>>3);

    memset( _dest, 0, bitmapSize + colormapSize );

    adilinebeginbitmap("BMD2");

    for( int y=0; y<_height; y+=8 ) {
        for( int x=0; x<_width; x+=8 ) {

            char * source = _source + ( ( y * _source_width ) + x ) * _depth;
            char tile[9];

            vic1_image_converter_tile( _environment, source, tile, _width, _depth, _source_width );

            int offset = ((y>>3) * 8 *( _width >> 3 ) ) + ((x>>3) * 8) + ((y) & 0x07);
            // x = 8, y = 8
            // offset = ((8 >> 3) * 8 * (16>>3) ) + ((8>>3) * 8) + ((8) & 7)
            // offset = (1 * 8 * 2 ) + (1 * 8)
            // offset = 16 + 8 = 24

            char * destBitmap = _dest + offset;
            char * destColormap = _dest + bitmapSize + ( ( ( y >> 3 ) * ( _width >> 3 ) ) + ( x >> 3 ) );
            for( int i=0; i<8; ++i ) {
                *destBitmap = tile[i];
                ++destBitmap;
            }
            // printf("tile at %d,%d color = %2.2x\n", x, y, tile[8] );
            *destColormap = tile[8];            
        }
    }

    adilineendbitmap();

}

////////////////////////////////////////////////////////////////////////

static Variable * OLD__vic1_image_converter_tilemap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    image_converter_asserts( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    if ( _environment->freeImageWidth ) {
        if ( _width % 8 ) {
            _width = ( ( ( _width - 1 ) / 8 ) - 1 ) * 8;
        }
        if ( _frame_width % 8 ) {
            _frame_width = ( ( ( _frame_width - 1 ) / 8 ) - 1 ) * 8;
        }
    }
    
    if ( _environment->freeImageHeight ) {
        if ( _height % 8 ) {
            _height = ( ( ( _height - 1 ) / 8 ) - 1 ) * 8;
        }
        if ( _frame_height % 8 ) {
            _frame_height = ( ( ( _frame_height - 1 ) / 8 ) - 1 ) * 8;
        }
    }

    RGBi palette[MAX_PALETTE];

    int colorUsed = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, 1 /* sorted */);

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = colorUsed;

    int i, j, k;

    for( i=0; i<colorUsed; ++i ) {
        int minDistance = 0xffff;
        int colorIndex = 0;
        for (j = 0; j < sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++j) {
            int distance = rgbi_distance(&SYSTEM_PALETTE[j], &palette[i]);
            // printf("%d <-> %d [%d] = %d [min = %d]\n", i, j, SYSTEM_PALETTE[j].index, distance, minDistance );
            if (distance < minDistance) {
                // printf(" candidated...\n" );
                for( k=0; k<i; ++k ) {
                    if ( palette[k].index == SYSTEM_PALETTE[j].index ) {
                        // printf(" ...used!\n" );
                        break;
                    }
                }
                if ( k>=i ) {
                    // printf(" ...ok! (%d)\n", SYSTEM_PALETTE[j].index );
                    minDistance = distance;
                    colorIndex = j;
                }
            }
        }
        palette[i].index = SYSTEM_PALETTE[colorIndex].index;
        strcopy( palette[i].description, SYSTEM_PALETTE[colorIndex].description );
        // printf("%d) %d %2.2x%2.2x%2.2x\n", i, palette[i].index, palette[i].red, palette[i].green, palette[i].blue);
    }

    memcpy( result->originalPalette, palette, MAX_PALETTE * sizeof( RGBi ) );
    
    int bufferSize;
    
    if ( colorUsed == 2 ) {
        bufferSize = 3 + ( ( _frame_width >> 3 ) * ( _frame_height >> 3 ) ) + 2;
    } else {
        bufferSize = 3 + 2* ( ( _frame_width >> 3 ) * ( _frame_height >> 3 ) );
    } 

    // printf("bufferSize = %d\n", bufferSize );

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

    *(buffer) = _frame_width;
    *(buffer+1) = _frame_height;

    if ( colorUsed > 2 ) {
        *(buffer+2) = 1;
    } else {
        *(buffer+2) = 0;
    }

    int cx=0,cy=0;

    _source += ( ( _offset_y * _width ) + _offset_x ) * _depth;

    // commonTileDescriptors = precalculate_tile_descriptors_for_font( data_fontvic1_bin );

    for( cy=0; cy<(_frame_height >> 3);++cy) {
        for( cx=0; cx<(_frame_width >> 3);++cx) {

            char *source = _source + ( ( cy * 8 * _width ) + cx * 8 ) * _depth;
            char convertedTile[9];

            vic1_image_converter_tile( _environment, source, convertedTile, _width, _depth, _width );

            TileData tileData;
            memset(&tileData,0,sizeof(TileData));
            memcpy(&tileData.data[0], convertedTile, 8 );

            // printf("\n" );
            
            TileDescriptor * t = calculate_tile_descriptor( &tileData );

            if ( ! _environment->descriptors ) {
                _environment->descriptors = precalculate_tile_descriptors_for_font( data_font_alpha_bin, data_font_standard_bin_len / 8 );
                _environment->descriptors->first = 0;
                _environment->descriptors->firstFree = ( (data_font_alpha_bin_len / 8) );
                _environment->descriptors->lastFree = 255;
                _environment->descriptors->count = _environment->descriptors->firstFree;
            }
            
            int tile = calculate_exact_tile( t, _environment->descriptors );

            if ( tile == -1 ) {
                if ( _environment->descriptors->count < 256 ) {
                    tile = (_environment->descriptors->count++);
                    _environment->descriptors->descriptor[tile] = t; 
                    memcpy( &_environment->descriptors->data[tile], &tileData, sizeof( TileData ) ); 
                } else {
                    tile = calculate_nearest_tile( t, _environment->descriptors );
                }
                // printf("*** tile = %d\n", tile );
            } else {
                // printf("    tile = %d\n", tile );
            }

            *(buffer + 3 + (cy * ( _frame_width >> 3 ) ) + cx ) = tile;
            if ( colorUsed > 2 ) {
                // printf( "c = %1.1x\n", mostFrequentColorIndex );
                *(buffer + 3 + ( ( _frame_width >> 3 ) * ( _frame_height >> 3 ) ) + (cy * ( _frame_width >> 3 ) ) + cx ) = ( convertedTile[8] >> 4 ) & 0x7;
            }

            // printf("\ntile: %2.2x\n", tile );

        }
        // printf("\n");
    }

    if ( colorUsed <= 2 ) {
        *(buffer + 3 + ( ( _frame_width >> 3 ) * ( _frame_height >> 3 ) ) ) = palette[1].index;
        *(buffer + 3 + ( ( _frame_width >> 3 ) * ( _frame_height >> 3 ) ) + 1 ) = ( palette[0].index << 4 );
    } else {
        *(buffer + 3 + ( ( _frame_width >> 3 ) * ( _frame_height >> 3 ) ) + ( (_frame_height >> 3 ) * ( _frame_width >> 3 ) ) ) = ( palette[0].index << 4 ) & 0xf0;
    }
    // printf("----\n");

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    // printf("----\n");

    return result;

}

static Variable * vic1_image_converter_tilemap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    _environment->bitmaskNeeded = 1;

    image_converter_asserts( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    if ( _environment->freeImageWidth ) {
        if ( _width % 8 ) {
            _width = ( ( ( _width - 1 ) / 8 ) - 1 ) * 8;
        }
        if ( _frame_width % 8 ) {
            _frame_width = ( ( ( _frame_width - 1 ) / 8 ) - 1 ) * 8;
        }
    }
    
    if ( _environment->freeImageHeight ) {
        if ( _height % 8 ) {
            _height = ( ( ( _height - 1 ) / 8 ) - 1 ) * 8;
        }
        if ( _frame_height % 8 ) {
            _frame_height = ( ( ( _frame_height - 1 ) / 8 ) - 1 ) * 8;
        }
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(mage)");
    result->locked = 1;

    // timeslot: 1 byte
    // width: 1 byte
    // size: 1 byte
    // (indexes): size bytes
    // tiles' data

    int size = ( ( _frame_width >> 3 ) * ( _frame_height >> 3 ) );

    int bufferSize = 3 + size + size * 8 + size;

    char * buffer = malloc ( bufferSize );

    memset( buffer, 0, bufferSize );

    buffer[0] = 0xff; // force update at first PUT IMAGE
    buffer[1] = ( _frame_width >> 3 );
    buffer[2] = size;

    int cx, cy;

    _source += ( ( _offset_y * _width ) + _offset_x ) * _depth;

    for( cy=0; cy<(_frame_height >> 3);++cy) {
        for( cx=0; cx<(_frame_width >> 3);++cx) {

            int tileDataOffset = 3 + size + ( (cy * ( _frame_width >> 3 ) ) + cx ) * ( 8 );
            int tileColorOffset = 3 + size + size * 8 + ( cy * (_frame_width >> 3) ) + cx;

            char * source = _source + ( ( cy * 8 * _width ) + cx * 8 ) * _depth;

            char convertedTile[9];

            vic1_image_converter_tile( _environment, source, convertedTile, _width, _depth, _width );
            
            memcpy( &buffer[tileDataOffset], convertedTile, 8 );
            buffer[tileColorOffset] = convertedTile[8];

        }

    }

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    return result;

}

Variable * vic1_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

   switch( _mode ) {
        case BITMAP_MODE_STANDARD:
        case TILEMAP_MODE_STANDARD:
            return vic1_image_converter_tilemap_mode_standard( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );
            break;
    }

    WARNING_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

    return vic1_new_image( _environment, 8, 8, BITMAP_MODE_STANDARD );

}

void vic1_calculate_sequence_frame_offset( Environment * _environment, char * _offset, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

}

static void vic1_load_image_address_to_register( Environment * _environment, char * _register, Resource * _source, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

    if ( !_sequence && !_frame ) {
        if ( _source->isAddress ) {
            outline1("LDA %s", _source->realName );
            outline1("STA %s", _register );
            outline1("LDA %s", address_displacement(_environment, _source->realName, "1") );
            outline1("STA %s", address_displacement(_environment, _register, "1") );
        } else {
            outline1("LDA #<%s", _source->realName );
            outline1("STA %s", _register );
            outline1("LDA #>%s", _source->realName );
            outline1("STA %s", address_displacement(_environment, _register, "1") );
        }
    } else {
        if ( _source->isAddress ) {
            outline1("LDA %s", _source->realName );
            outline0("STA TMPPTR" );
            outline1("LDA %s", address_displacement(_environment, _source->realName, "1") );
            outline0("STA TMPPTR+1" );
        } else {
            outline1("LDA #<%s", _source->realName );
            outline0("STA TMPPTR" );
            outline1("LDA #>%s", _source->realName );
            outline0("STA TMPPTR+1" );
        }

        if ( _sequence ) {
            outline0("CLC" );
            outline0("LDA TMPPTR" );
            outline0("ADC #3" );
            outline0("STA TMPPTR" );
            outline0("LDA TMPPTR+1" );
            outline0("ADC #0" );
            outline0("STA  TMPPTR+1" );

            if ( strlen(_sequence) == 0 ) {

            } else {
                outline1("LDA %s", _sequence );
                outline0("STA MATHPTR0" );
                outline1("JSR %soffsetsequence", _source->realName );
            }
            if ( _frame ) {
                if ( strlen(_frame) == 0 ) {

                } else {
                    outline1("LDA %s", _frame );
                    outline0("STA MATHPTR0" );
                    outline1("JSR %soffsetframe", _source->realName );
                }
            }

        } else {

            if ( _frame ) {
                outline0("CLC" );
                outline0("LDA TMPPTR" );
                outline0("ADC #3" );
                outline0("STA TMPPTR" );
                outline0("LDA TMPPTR+1" );
                outline0("ADC #0" );
                outline0("STA  TMPPTR+1" );
                if ( strlen(_frame) == 0 ) {

                } else {
                    outline1("LDA %s", _frame );
                    outline0("STA MATHPTR0" );
                    outline1("JSR %soffsetframe", _source->realName );
                }
            }

        }

        if ( _source->isAddress ) {
            outline0("LDA TMPPTR" );
            outline1("STA %s", _register );
            outline0("LDA TMPPTR+1" );
            outline1("STA %s", address_displacement(_environment, _register, "1") );
        } else {
            outline0("LDA TMPPTR" );
            outline1("STA %s", _register );
            outline0("LDA TMPPTR+1" );
            outline1("STA %s", address_displacement(_environment, _register, "1") );
        }

    }
}

void vic1_put_image( Environment * _environment, Resource * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _flags ) {

    // currently unused
    (void)!_flags;

    _environment->bitmaskNeeded = 1;
    
    deploy_preferred( vic1vars, src_hw_vic1_vars_asm);
    deploy( putimage, src_hw_vic1_put_image_asm );

    if ( _frame_size ) {
        vic1_load_image_address_to_register( _environment, "TMPPTR", _image, _sequence, _frame, _frame_size, _frame_count );
    }

    outline1("LDA %s", _x );
    outline0("STA IMAGEX" );
    outline1("LDA %s", address_displacement(_environment, _x, "1") );
    outline0("STA IMAGEX+1" );
    outline1("LDA %s", _y );
    outline0("STA IMAGEY" );
    outline1("LDA %s", address_displacement(_environment, _y, "1") );
    outline0("STA IMAGEY+1" );
    // outline1("LDA %s", _flags);
    // if ( strchr( _flags, '#' ) ) {
    //     outline1("LDA #((%s)&255)", _flags+1 );
    //     outline0("STA IMAGEF" );
    //     outline1("LDA #(((%s)>>8)&255)", _flags+1 );
    //     outline0("STA IMAGET" );
    // } else {
    //     outline1("LDA %s", _flags );
    //     outline0("STA IMAGEF" );
    //     outline1("LDA %s", address_displacement(_environment, _flags, "1") );
    //     outline0("STA IMAGET" );
    // }    

    outline0("JSR PUTIMAGE");

}

void vic1_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm);
    deploy( blitimage, src_hw_vic1_blit_image_asm );

    if ( _source_count > 2 ) {
        CRITICAL_BLIT_TOO_MUCH_SOURCES( );
    }

    MAKE_LABEL

    outhead1("blitimage%s:", label);

    outline1("LDA #<%s", _blit );
    outline0("STA BLITIMAGEBLITADDR+1" );
    outline1("LDA #>%s", _blit );
    outline0("STA BLITIMAGEBLITADDR+2" );

    if ( _source_count > 0 ) {
        Resource resource;
        resource.realName = strdup( _sources[0] );
        resource.type = VT_IMAGE;
        vic1_load_image_address_to_register( _environment, "BLITTMPPTR", &resource, _sequence, _frame, _frame_size, _frame_count );
    } else {
        outline0( "LDA #$0" );
        outline0( "STA BLITTMPPTR" );
        outline0( "STA BLITTMPPTR+1" );
    }

    if ( _source_count > 1 ) {
        Resource resource;
        resource.realName = strdup( _sources[0] );
        resource.type = VT_IMAGE;
        vic1_load_image_address_to_register( _environment, "BLITTMPPTR2", &resource, _sequence, _frame, _frame_size, _frame_count );
    } else {
        outline0( "LDA #$0" );
        outline0( "STA BLITTMPPTR2" );
        outline0( "STA BLITTMPPTR2+1" );
    }

    outhead1("putimage%s:", label);

    outline1("LDA %s", _x );
    outline0("STA IMAGEX" );
    outline1("LDA %s", address_displacement(_environment, _x, "1") );
    outline0("STA IMAGEX+1" );
    outline1("LDA %s", _y );
    outline0("STA IMAGEY" );
    outline1("LDA %s", address_displacement(_environment, _y, "1") );
    outline0("STA IMAGEY+1" );
    outline1("LDA #$%2.2x", ( _flags & 0xff ) );
    outline0("STA IMAGEF" );
    outline1("LDA #$%2.2x", ( (_flags>>8) & 0xff ) );
    outline0("STA IMAGET" );

    outline0("JSR BLITIMAGE");

}

void vic1_wait_vbl( Environment * _environment ) {

    deploy( vbl, src_hw_vic1_vbl_asm);

    outline0("JSR VBL");

}

Variable * vic1_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    int size = vic1_image_size( _environment, _width, _height, _mode );

    // if ( ! size ) {
    //     CRITICAL_NEW_IMAGE_UNSUPPORTED_MODE( _mode );
    // }

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(new image)" );

    result->size = size;
    result->valueBuffer = malloc(size);    

    return result;
}

Variable * vic1_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

    int size = calculate_images_size( _environment, _frames, _width, _height, _mode );
    int frameSize = vic1_image_size( _environment, _width, _height, _mode );

    // if ( ! size ) {
    //     CRITICAL_NEW_IMAGE_UNSUPPORTED_MODE( _mode );
    // }

    Variable * result = variable_temporary( _environment, VT_IMAGES, "(new images)" );

    result->size = size;
    result->frameSize = frameSize;
    result->frameCount = _frames;
    result->valueBuffer = malloc( size );
    
    return result;
}

Variable * vic1_new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

    int size2 = calculate_sequence_size( _environment, _sequences, _frames, _width, _height, _mode );
    int size = calculate_images_size( _environment, _frames, _width, _height, _mode );
    int frameSize = vic1_image_size( _environment, _width, _height, _mode );

    // if ( ! size ) {
    //     CRITICAL_NEW_IMAGE_UNSUPPORTED_MODE( _mode );
    // }

    Variable * result = variable_temporary( _environment, VT_IMAGES, "(new images)" );

    result->size = size;
    result->frameSize = frameSize;
    result->frameCount = _frames;
    result->valueBuffer = malloc( size );
    
    return result;
}

void vic1_get_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _palette ) {
    
}

void vic1_scroll( Environment * _environment, int _dx, int _dy ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm);
    deploy( scroll, src_hw_vic1_scroll_asm);
    deploy_preferred( textHScroll, src_hw_vic1_hscroll_text_asm );
    deploy_preferred( vScrollTextUp, src_hw_vic1_vscroll_text_up_asm );
    deploy_preferred( vScrollTextDown, src_hw_vic1_vscroll_text_down_asm );

    outline1("LDA #$%2.2x", (unsigned char)(_dx&0xff) );
    outline0("STA MATHPTR0" );
    outline1("LDA #$%2.2x", (unsigned char)(_dy&0xff) );
    outline0("STA MATHPTR1" );
    outline0("JSR SCROLL");

}

void vic1_put_tile( Environment * _environment, char * _tile, char * _x, char * _y ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm);
    deploy( tiles, src_hw_vic1_tiles_asm );

    outline1("LDA %s", _tile );
    outline0("STA TILET" );
    outline1("LDA %s", _x );
    outline0("STA TILEX" );
    outline1("LDA %s", _y );
    outline0("STA TILEY" );
    outline0("LDA #1" );
    outline0("STA TILEW" );
    outline0("STA TILEH" );
    outline0("STA TILEW2" );
    outline0("STA TILEH2" );

    outline0("JSR PUTTILE");

}

void vic1_move_tiles( Environment * _environment, char * _tile, char * _x, char * _y ) {

    Variable * tile = variable_retrieve( _environment, _tile );
    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm);
    deploy( tiles, src_hw_vic1_tiles_asm );

    outline1("LDA %s", tile->realName );
    outline0("STA TILET" );
    outline1("LDA %s", x->realName );
    outline0("STA TILEX" );
    outline1("LDA %s", y->realName );
    outline0("STA TILEY" );
    outline1("LDA %s", address_displacement(_environment, tile->realName, "1") );
    outline0("STA TILEW" );
    outline0("STA TILEW2" );
    outline1("LDA %s", address_displacement(_environment, tile->realName, "2") );
    outline0("STA TILEH" );
    outline0("STA TILEH2" );
    outline1("LDA %s", address_displacement(_environment, tile->realName, "3") );
    outline0("STA TILEA" );

    int size = ( tile->originalWidth >> 3 ) * ( tile->originalHeight >> 3 );

    if ( size ) {
        outline1("LDA #<OFFSETS%4.4x", size );
        outline0("STA TMPPTR2" );
        outline1("LDA #>OFFSETS%4.4x", size );
        outline0("STA TMPPTR2+1" );
    } else {
        outline0("LDA #0" );
        outline0("STA TMPPTR2" );
        outline0("STA TMPPTR2+1" );
    }

    outline0("JSR MOVETILE");

}

void vic1_put_tiles( Environment * _environment, char * _tile, char * _x, char * _y, char *_w, char *_h ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm);
    deploy( tiles, src_hw_vic1_tiles_asm );

    outline1("LDA %s", _tile );
    outline0("STA TILET" );
    outline1("LDA %s", _x );
    outline0("STA TILEX" );
    outline1("LDA %s", _y );
    outline0("STA TILEY" );
    outline1("LDA %s", address_displacement(_environment, _tile, "1") );
    outline0("STA TILEW" );
    if ( _w ) {
        outline1("LDA %s", _w );
    }
    outline0("STA TILEW2" );
    outline1("LDA %s", address_displacement(_environment, _tile, "2") );
    outline0("STA TILEH" );
    if ( _h ) {
        outline1("LDA %s", _h );
    }
    outline0("STA TILEH2" );

    outline0("JSR PUTTILE");

}

void vic1_tile_at( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm);
    deploy( tiles, src_hw_vic1_tiles_asm );

    outline1("LDA %s", _x );
    outline0("STA TILEX" );
    outline1("LDA %s", _y );
    outline0("STA TILEY" );

    outline0("JSR TILEAT");

    outline0("LDA TILET" );
    outline1("STA %s", _result );

}

void vic1_use_tileset( Environment * _environment, char * _tileset ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm);
    deploy( tiles, src_hw_vic1_tiles_asm );

    outline1("LDA %s", _tileset );

    outline0("JSR USETILESET");

}

Variable * vic1_get_raster_line( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_WORD, "(raster line)" );

    outline0( "LDA $9004" );
    outline0( "ASL" );
    outline1( "STA %s", result->realName );
    outline0( "LDA #$0" );
    outline0( "ROL" );
    outline1( "STA %s", address_displacement(_environment, result->realName, "1") );

    return result;
    
}

/* audio */

static unsigned int SOUND_FREQUENCIES[] = {
    19,		19,		19,		19,		19,		19,		19,		19,		19,		19,
    19,		19,		19,		19,		19,		19,		19,		19,		19,		19,
    19,		19,		19,	    19,     19,     19,     32,     45,     57,     68,
    78,     88,     98,     106,    115,    123,    130,    137,    144,    150,
    156,    161,    167,    172,    176,    181,    185,    189,    193,    196,
    199,    202,    205,    208,    211,    213,    216,    218,    220,    222,
    224,    226,    227,    229,    230,    232,    233,    234,    235,    236,
    237,    238,    239,    240,    241,    242,    243,    243,    244,    245,
    245,    246,    246,    247,    247,    248,    248,    248,    249,    249,
    249,    250,    250,    250,    251,    251,    251,    251,    252,    252,
    252,    252,    252,    252,    253,    253,    253,    253,    253,    253,
    253,    253,    253,    254,    254,    254,    254,    254,    254    
};

void vic1_start( Environment * _environment, int _channels ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy_deferred( vic1startup, src_hw_vic1_startup_asm );

    if ( _channels & 0x01 ) {
        outline0("JSR VIC1START0");
    }
    if ( _channels & 0x02 ) {
        outline0("JSR VIC1START1");
    }
    if ( _channels & 0x04 ) {
        outline0("JSR VIC1START2");
    }

}

void vic1_set_volume( Environment * _environment, int _channels, int _volume ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );

    outline1("LDX #%2.2x", ( _volume & 0x0f ) );
    outline0("JSR VIC1STARTVOL");

}

#define     PROGRAM_FREQUENCY( c, f ) \
    outline1("LDX #$%2.2x", ( ( ( f >> 9 ) & 0xff ) ) ); \
    outline1("LDY #$%2.2x", 0 ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR VIC1PROGFREQ0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR VIC1PROGFREQ1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR VIC1PROGFREQ2" );

#define     PROGRAM_FREQUENCY_V( c, f ) \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline1("LDX %s", f ); \
    outline1("LDY %s", address_displacement(_environment, f, "1") ); \
    outline0("JSR VIC1FREQ" );

#define     PROGRAM_FREQUENCY_SV( c, f ) \
    outline1("LDX #$%2.2x", ( ( ( f >> 9 ) ) & 0xff ) ); \
    outline1("LDY #$%2.2x", 0 ); \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("JSR VIC1FREQ2" );

#define     PROGRAM_DURATION( c, d ) \
    outline1("LDX #$%2.2x", ( ( d & 0xff ) ) ); \
    outline1("LDY #$%2.2x", ( ( ( d >> 9 ) & 0xff ) ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR VIC1SETDURATION0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR VIC1SETDURATION1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR VIC1SETDURATION2" );

#define     WAIT_DURATION( c ) \
    if ( ( c & 0x01 ) ) \
        outline0("JSR VIC1WAITDURATION0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR VIC1WAITDURATION1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR VIC1WAITDURATION2" );

#define     PROGRAM_PITCH( c, f ) \
    outline1("LDX #$%2.2x", ( f & 0xff ) ); \
    outline1("LDY #$%2.2x", 0 ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR VIC1PROGFREQ0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR VIC1PROGFREQ1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR VIC1PROGFREQ2" );

#define     PROGRAM_PITCH_V( c, f ) \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline1("LDX %s", f ); \
    outline1("LDY %s", address_displacement(_environment, f, "1") ); \
    outline0("JSR VIC1PROGFREQ" );

#define     PROGRAM_PITCH_SV( c, f ) \
    outline1("LDX #$%2.2x", ( f & 0xff ) ); \
    outline1("LDY #$%2.2x", 0 ); \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("JSR VIC1PROGFREQ" );

#define     PROGRAM_PULSE( c, p ) \
    outline1("LDX #$%2.2x", ( p & 0xff ) ); \
    outline1("LDY #$%2.2x", 0 ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR VIC1PROGPULSE0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR VIC1PROGPULSE1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR VIC1PROGPULSE2" );

#define     PROGRAM_PULSE_V( c, p ) \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline1("LDX %s", p ); \
    outline1("LDY %s", address_displacement(_environment, p, "1") ); \
    outline0("JSR VIC1PROGPULSE" );

#define     PROGRAM_PULSE_SV( c, p ) \
    outline1("LDX #$%2.2x", ( p & 0xff ) ); \
    outline1("LDY #$%2.2x", 0 ); \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("JSR VIC1PROGPULSE" );

#define     PROGRAM_NOISE( c ) \
    outline0("LDX #$82" ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR VIC1PROGCTR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR VIC1PROGCTR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR VIC1PROGCTR2" );

#define     PROGRAM_NOISE_V( c, p ) \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("LDX #$82" ); \
    outline0("JSR VIC1PROGCTR" );

#define     PROGRAM_NOISE_SV( c ) \
    outline0("LDX #$82" ); \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("JSR VIC1PROGCTR" );

#define     PROGRAM_SAW( c ) \
    outline0("LDX #$22" ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR VIC1PROGCTR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR VIC1PROGCTR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR VIC1PROGCTR2" );

#define     PROGRAM_SAW_V( c) \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("LDX #$22" ); \
    outline0("JSR VIC1PROGCTR" );

#define     PROGRAM_SAW_SV( c ) \
    outline0("LDX #$22" ); \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("JSR VIC1PROGCTR" );

#define     PROGRAM_TRIANGLE( c ) \
    outline0("LDX #$12" ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR VIC1PROGCTR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR VIC1PROGCTR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR VIC1PROGCTR2" );

#define     PROGRAM_TRIANGLE_V( c ) \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("LDX #$12" ); \
    outline0("JSR VIC1PROGCTR" );

#define     PROGRAM_TRIANGLE_SV( c ) \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("LDX #$12" ); \
    outline0("JSR VIC1PROGCTR" );

#define     PROGRAM_SAW_TRIANGLE( c ) \
    outline0("LDX #$32" ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR VIC1PROGCTR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR VIC1PROGCTR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR VIC1PROGCTR2" );

#define     PROGRAM_SAW_TRIANGLE_V( c ) \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("LDX #$32" ); \
    outline0("JSR VIC1PROGCTR" );

#define     PROGRAM_SAW_TRIANGLE_SV( c ) \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("LDX #$32" ); \
    outline0("JSR VIC1PROGCTR" );

#define     PROGRAM_ATTACK_DECAY( c, a, d ) \
    outline1("LDX #$%2.2x", ( a & 0x0f ) ); \
    outline1("LDY #$%2.2x", ( d & 0x0f ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR VIC1PROGAD0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR VIC1PROGAD1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR VIC1PROGAD2" );

#define     PROGRAM_ATTACK_DECAY_V( c, a, d ) \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline1("LDX %s", a ); \
    outline1("LDY %s", d ); \
    outline0("JSR VIC1PROGAD" );

#define     PROGRAM_ATTACK_DECAY_SV( c, a, d ) \
    outline1("LDX #$%2.2x", ( a & 0x0f ) ); \
    outline1("LDY #$%2.2x", ( d & 0x0f ) ); \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("JSR VIC1PROGAD" );

#define     PROGRAM_SUSTAIN_RELEASE( c, s, r ) \
    outline1("LDX #$%2.2x", ( s & 0x0f ) ); \
    outline1("LDY #$%2.2x", ( r & 0x0f ) ); \
    if ( ( c & 0x01 ) ) \
        outline0("JSR VIC1PROGSR0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR VIC1PROGSR1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR VIC1PROGSR2" );

#define     PROGRAM_SUSTAIN_RELEASE_V( c, s, r ) \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline1("LDX %s", s ); \
    outline1("LDY %s", r ); \
    outline0("JSR VIC1PROGSR" );

#define     PROGRAM_SUSTAIN_RELEASE_SV( c, s, r ) \
    outline1("LDX #$%2.2x", ( s & 0x0f ) ); \
    outline1("LDY #$%2.2x", ( r & 0x0f ) ); \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("JSR VIC1PROGSR" );

#define     STOP_FREQUENCY( c ) \
    if ( ( c & 0x01 ) ) \
        outline0("JSR VIC1STOP0" ); \
    if ( ( c & 0x02 ) ) \
        outline0("JSR VIC1STOP1" ); \
    if ( ( c & 0x04 ) ) \
        outline0("JSR VIC1STOP2" );

#define     STOP_FREQUENCY_V( c ) \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("JSR VIC1STOP" );

#define     STOP_FREQUENCY_SV( c ) \
    outline1("LDA %s", ( c == NULL ? "#$7" : c ) ); \
    outline0("JSR VIC1STOP" );

void vic1_set_program( Environment * _environment, int _channels, int _program ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );

    switch (_program) {
        case IMF_INSTRUMENT_EXPLOSION:
            PROGRAM_NOISE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 2, 11);
            PROGRAM_SUSTAIN_RELEASE(_channels, 0, 1);
            break;
        case IMF_INSTRUMENT_GUNSHOT:
            PROGRAM_NOISE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 2, 4);
            PROGRAM_SUSTAIN_RELEASE(_channels, 0, 1);
            break;
        case IMF_INSTRUMENT_PAD_5_BOWED:
        case IMF_INSTRUMENT_PAD_6_METALLIC:
        case IMF_INSTRUMENT_PAD_7_HALO:
        case IMF_INSTRUMENT_PAD_8_SWEEP:
        case IMF_INSTRUMENT_ACOUSTIC_GRAND_PIANO:
        case IMF_INSTRUMENT_BRIGHT_ACOUSTIC_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_GRAND_PIANO:
        case IMF_INSTRUMENT_HONKY_TONK_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_PIANO1:
        case IMF_INSTRUMENT_ELECTRIC_PIANO2:
            PROGRAM_TRIANGLE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 4, 2);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_HARPSICHORD:
        case IMF_INSTRUMENT_CLAVI:
        case IMF_INSTRUMENT_CELESTA:
            PROGRAM_PULSE(_channels, 1024);
            PROGRAM_ATTACK_DECAY(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 3);
            break;

        case IMF_INSTRUMENT_LEAD_3_CALLIOPE:
        case IMF_INSTRUMENT_GLOCKENSPIEL:
        case IMF_INSTRUMENT_MUSIC_BOX:
        case IMF_INSTRUMENT_VIBRAPHONE:
        case IMF_INSTRUMENT_MARIMBA:
        case IMF_INSTRUMENT_XYLOPHONE:
        case IMF_INSTRUMENT_TUBULAR_BELLS:
        case IMF_INSTRUMENT_DULCIMER:
            PROGRAM_TRIANGLE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 2, 10);
            PROGRAM_SUSTAIN_RELEASE(_channels, 12, 14);
            break;

        default:
        case IMF_INSTRUMENT_PAD_3_POLYSYNTH:
        case IMF_INSTRUMENT_DRAWBAR_ORGAN:
        case IMF_INSTRUMENT_PERCUSSIVE_ORGAN:
        case IMF_INSTRUMENT_ROCK_ORGAN:
        case IMF_INSTRUMENT_CHURCH_ORGAN:
        case IMF_INSTRUMENT_REED_ORGAN:
        case IMF_INSTRUMENT_ACCORDION:
        case IMF_INSTRUMENT_HARMONICA:
        case IMF_INSTRUMENT_TANGO_ACCORDION:
            PROGRAM_TRIANGLE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_NYLON:
        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_STEEL:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_JAZZ:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_CLEAN:
        case IMF_INSTRUMENT_OVERDRIVEN_GUITAR:
        case IMF_INSTRUMENT_DISTORTION_GUITAR:
        case IMF_INSTRUMENT_GUITAR_HARMONICS:
            PROGRAM_PULSE(_channels, 128);
            PROGRAM_ATTACK_DECAY(_channels, 10, 10);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_ELECTRIC_GUITAR_MUTED:
            PROGRAM_PULSE(_channels, 128);
            PROGRAM_ATTACK_DECAY(_channels, 1, 2);
            PROGRAM_SUSTAIN_RELEASE(_channels, 4, 3);
            break;

        case IMF_INSTRUMENT_LEAD_8_BASS_LEAD:
        case IMF_INSTRUMENT_ACOUSTIC_BASS:
        case IMF_INSTRUMENT_ELECTRIC_BASS_FINGER:
        case IMF_INSTRUMENT_ELECTRIC_BASS_PICK:
        case IMF_INSTRUMENT_FRETLESS_BASS:
        case IMF_INSTRUMENT_SLAP_BASS_1:
        case IMF_INSTRUMENT_SLAP_BASS_2:
        case IMF_INSTRUMENT_SYNTH_BASS_1:
        case IMF_INSTRUMENT_SYNTH_BASS_2:
            PROGRAM_TRIANGLE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 2, 10);
            PROGRAM_SUSTAIN_RELEASE(_channels, 12, 14);
            break;

        case IMF_INSTRUMENT_LEAD_1_SQUARE:
        case IMF_INSTRUMENT_VIOLIN:
        case IMF_INSTRUMENT_VIOLA:
        case IMF_INSTRUMENT_CELLO:
        case IMF_INSTRUMENT_CONTRABASS:
        case IMF_INSTRUMENT_TREMOLO_STRINGS:
        case IMF_INSTRUMENT_PIZZICATO_STRINGS:
        case IMF_INSTRUMENT_ORCHESTRAL_HARP:
        case IMF_INSTRUMENT_STRING_ENSEMBLE_1:
        case IMF_INSTRUMENT_STRING_ENSEMBLE_2:
        case IMF_INSTRUMENT_SYNTHSTRINGS_1:
        case IMF_INSTRUMENT_SYNTHSTRINGS_2:
            PROGRAM_PULSE(_channels, 128);
            PROGRAM_ATTACK_DECAY(_channels, 10, 10);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_PAD_4_CHOIR:
        case IMF_INSTRUMENT_CHOIR_AAHS:
        case IMF_INSTRUMENT_VOICE_OOHS:
        case IMF_INSTRUMENT_SYNTH_VOICE:
        case IMF_INSTRUMENT_LEAD_4_CHIFF:
        case IMF_INSTRUMENT_LEAD_5_CHARANG:
        case IMF_INSTRUMENT_LEAD_6_VOICE:
        case IMF_INSTRUMENT_LEAD_7_FIFTHS:
        case IMF_INSTRUMENT_FX_1_RAIN:
        case IMF_INSTRUMENT_FX_2_SOUNDTRACK:
        case IMF_INSTRUMENT_FX_3_CRYSTAL:
        case IMF_INSTRUMENT_FX_4_ATMOSPHERE:
        case IMF_INSTRUMENT_FX_5_BRIGHTNESS:
        case IMF_INSTRUMENT_FX_6_GOBLINS:
        case IMF_INSTRUMENT_FX_7_ECHOES:
        case IMF_INSTRUMENT_FX_8_SCI_FI:
        case IMF_INSTRUMENT_TIMPANI:
        case IMF_INSTRUMENT_ORCHESTRA_HIT:
        case IMF_INSTRUMENT_APPLAUSE:
            PROGRAM_NOISE(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 1, 14);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_LEAD_2_SAWTOOTH:
        case IMF_INSTRUMENT_PAD_1_NEW_AGE:
        case IMF_INSTRUMENT_PAD_2_WARM:
        case IMF_INSTRUMENT_TRUMPET:
        case IMF_INSTRUMENT_TROMBONE:
        case IMF_INSTRUMENT_TUBA:
        case IMF_INSTRUMENT_MUTED_TRUMPET:
        case IMF_INSTRUMENT_FRENCH_HORN:
        case IMF_INSTRUMENT_BRASS_SECTION:
        case IMF_INSTRUMENT_SYNTHBRASS_1:
        case IMF_INSTRUMENT_SYNTHBRASS_2:
        case IMF_INSTRUMENT_SOPRANO_SAX:
        case IMF_INSTRUMENT_ALTO_SAX:
        case IMF_INSTRUMENT_TENOR_SAX:
        case IMF_INSTRUMENT_BARITONE_SAX:
        case IMF_INSTRUMENT_OBOE:
        case IMF_INSTRUMENT_ENGLISH_HORN:
        case IMF_INSTRUMENT_BASSOON:
        case IMF_INSTRUMENT_CLARINET:
        case IMF_INSTRUMENT_PICCOLO:
        case IMF_INSTRUMENT_FLUTE:
        case IMF_INSTRUMENT_RECORDER:
        case IMF_INSTRUMENT_PAN_FLUTE:
        case IMF_INSTRUMENT_BLOWN_BOTTLE:
        case IMF_INSTRUMENT_SHAKUHACHI:
        case IMF_INSTRUMENT_WHISTLE:
        case IMF_INSTRUMENT_OCARINA:
            PROGRAM_SAW(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_SITAR:
        case IMF_INSTRUMENT_BANJO:
        case IMF_INSTRUMENT_SHAMISEN:
        case IMF_INSTRUMENT_KOTO:
        case IMF_INSTRUMENT_KALIMBA:
        case IMF_INSTRUMENT_BAG_PIPE:
        case IMF_INSTRUMENT_FIDDLE:
        case IMF_INSTRUMENT_SHANAI:
        case IMF_INSTRUMENT_TINKLE_BELL:
        case IMF_INSTRUMENT_AGOGO:
        case IMF_INSTRUMENT_STEEL_DRUMS:
        case IMF_INSTRUMENT_WOODBLOCK:
        case IMF_INSTRUMENT_TAIKO_DRUM:
        case IMF_INSTRUMENT_MELODIC_TOM:
        case IMF_INSTRUMENT_SYNTH_DRUM:
        case IMF_INSTRUMENT_REVERSE_CYMBAL:
        case IMF_INSTRUMENT_GUITAR_FRET_NOISE:
        case IMF_INSTRUMENT_BREATH_NOISE:
        case IMF_INSTRUMENT_SEASHORE:
        case IMF_INSTRUMENT_BIRD_TWEET:
        case IMF_INSTRUMENT_TELEPHONE_RING:
        case IMF_INSTRUMENT_HELICOPTER:
            PROGRAM_SAW(_channels);
            PROGRAM_ATTACK_DECAY(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE(_channels, 14, 14);
            break;
    }

}

void vic1_set_parameter( Environment * _environment, int _channels, int _parameter, int _value ) {

}

void vic1_set_frequency( Environment * _environment, int _channels, int _frequency ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );

    PROGRAM_FREQUENCY( _channels, _frequency );

}

void vic1_set_pitch( Environment * _environment, int _channels, int _pitch ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );

    PROGRAM_PITCH( _channels, _pitch );

}

void vic1_set_note( Environment * _environment, int _channels, int _note ) {

    vic1_set_pitch( _environment, _channels, SOUND_FREQUENCIES[_note] );

}

void vic1_stop( Environment * _environment, int _channels ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );

    STOP_FREQUENCY( _channels );

}

void vic1_start_var( Environment * _environment, char * _channels ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$7" );
    }
    outline0("JSR VIC1START");

}

void vic1_set_volume_vars( Environment * _environment, char * _channels, char * _volume ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );

    outline1("LDA %s", _volume );
    outline0("LSR" );
    outline0("LSR" );
    outline0("LSR" );
    outline0("LSR" );
    outline0("TAX" );
    outline0("JSR VIC1STARTVOL");

}

void vic1_set_volume_semi_var( Environment * _environment, char * _channel, int _volume ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );

    outline1("LDX #$%2.2x", _volume );
    outline0("JSR VIC1STARTVOL");

}

void vic1_set_program_semi_var( Environment * _environment, char * _channels, int _program ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );

    switch (_program) {
        case IMF_INSTRUMENT_EXPLOSION:
            PROGRAM_NOISE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 2, 11);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 0, 1);
            break;
        case IMF_INSTRUMENT_GUNSHOT:
            PROGRAM_NOISE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 2, 4);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 0, 1);
            break;
        case IMF_INSTRUMENT_PAD_5_BOWED:
        case IMF_INSTRUMENT_PAD_6_METALLIC:
        case IMF_INSTRUMENT_PAD_7_HALO:
        case IMF_INSTRUMENT_PAD_8_SWEEP:
        case IMF_INSTRUMENT_ACOUSTIC_GRAND_PIANO:
        case IMF_INSTRUMENT_BRIGHT_ACOUSTIC_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_GRAND_PIANO:
        case IMF_INSTRUMENT_HONKY_TONK_PIANO:
        case IMF_INSTRUMENT_ELECTRIC_PIANO1:
        case IMF_INSTRUMENT_ELECTRIC_PIANO2:
            PROGRAM_TRIANGLE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 4, 2);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_HARPSICHORD:
        case IMF_INSTRUMENT_CLAVI:
        case IMF_INSTRUMENT_CELESTA:
            PROGRAM_PULSE_SV(_channels, 1024);
            PROGRAM_ATTACK_DECAY_SV(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 3);
            break;

        case IMF_INSTRUMENT_LEAD_3_CALLIOPE:
        case IMF_INSTRUMENT_GLOCKENSPIEL:
        case IMF_INSTRUMENT_MUSIC_BOX:
        case IMF_INSTRUMENT_VIBRAPHONE:
        case IMF_INSTRUMENT_MARIMBA:
        case IMF_INSTRUMENT_XYLOPHONE:
        case IMF_INSTRUMENT_TUBULAR_BELLS:
        case IMF_INSTRUMENT_DULCIMER:
            PROGRAM_TRIANGLE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 2, 10);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 12, 14);
            break;

        default:
        case IMF_INSTRUMENT_PAD_3_POLYSYNTH:
        case IMF_INSTRUMENT_DRAWBAR_ORGAN:
        case IMF_INSTRUMENT_PERCUSSIVE_ORGAN:
        case IMF_INSTRUMENT_ROCK_ORGAN:
        case IMF_INSTRUMENT_CHURCH_ORGAN:
        case IMF_INSTRUMENT_REED_ORGAN:
        case IMF_INSTRUMENT_ACCORDION:
        case IMF_INSTRUMENT_HARMONICA:
        case IMF_INSTRUMENT_TANGO_ACCORDION:
            PROGRAM_TRIANGLE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_NYLON:
        case IMF_INSTRUMENT_ACOUSTIC_GUITAR_STEEL:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_JAZZ:
        case IMF_INSTRUMENT_ELECTRIC_GUITAR_CLEAN:
        case IMF_INSTRUMENT_OVERDRIVEN_GUITAR:
        case IMF_INSTRUMENT_DISTORTION_GUITAR:
        case IMF_INSTRUMENT_GUITAR_HARMONICS:
            PROGRAM_PULSE_SV(_channels, 128);
            PROGRAM_ATTACK_DECAY_SV(_channels, 10, 10);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_ELECTRIC_GUITAR_MUTED:
            PROGRAM_PULSE_SV(_channels, 128);
            PROGRAM_ATTACK_DECAY_SV(_channels, 1, 2);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 4, 3);
            break;

        case IMF_INSTRUMENT_LEAD_8_BASS_LEAD:
        case IMF_INSTRUMENT_ACOUSTIC_BASS:
        case IMF_INSTRUMENT_ELECTRIC_BASS_FINGER:
        case IMF_INSTRUMENT_ELECTRIC_BASS_PICK:
        case IMF_INSTRUMENT_FRETLESS_BASS:
        case IMF_INSTRUMENT_SLAP_BASS_1:
        case IMF_INSTRUMENT_SLAP_BASS_2:
        case IMF_INSTRUMENT_SYNTH_BASS_1:
        case IMF_INSTRUMENT_SYNTH_BASS_2:
            PROGRAM_TRIANGLE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 2, 10);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 12, 14);
            break;

        case IMF_INSTRUMENT_LEAD_1_SQUARE:
        case IMF_INSTRUMENT_VIOLIN:
        case IMF_INSTRUMENT_VIOLA:
        case IMF_INSTRUMENT_CELLO:
        case IMF_INSTRUMENT_CONTRABASS:
        case IMF_INSTRUMENT_TREMOLO_STRINGS:
        case IMF_INSTRUMENT_PIZZICATO_STRINGS:
        case IMF_INSTRUMENT_ORCHESTRAL_HARP:
        case IMF_INSTRUMENT_STRING_ENSEMBLE_1:
        case IMF_INSTRUMENT_STRING_ENSEMBLE_2:
        case IMF_INSTRUMENT_SYNTHSTRINGS_1:
        case IMF_INSTRUMENT_SYNTHSTRINGS_2:
            PROGRAM_PULSE_SV(_channels, 128);
            PROGRAM_ATTACK_DECAY_SV(_channels, 10, 10);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 10);
            break;

        case IMF_INSTRUMENT_PAD_4_CHOIR:
        case IMF_INSTRUMENT_CHOIR_AAHS:
        case IMF_INSTRUMENT_VOICE_OOHS:
        case IMF_INSTRUMENT_SYNTH_VOICE:
        case IMF_INSTRUMENT_LEAD_4_CHIFF:
        case IMF_INSTRUMENT_LEAD_5_CHARANG:
        case IMF_INSTRUMENT_LEAD_6_VOICE:
        case IMF_INSTRUMENT_LEAD_7_FIFTHS:
        case IMF_INSTRUMENT_FX_1_RAIN:
        case IMF_INSTRUMENT_FX_2_SOUNDTRACK:
        case IMF_INSTRUMENT_FX_3_CRYSTAL:
        case IMF_INSTRUMENT_FX_4_ATMOSPHERE:
        case IMF_INSTRUMENT_FX_5_BRIGHTNESS:
        case IMF_INSTRUMENT_FX_6_GOBLINS:
        case IMF_INSTRUMENT_FX_7_ECHOES:
        case IMF_INSTRUMENT_FX_8_SCI_FI:
        case IMF_INSTRUMENT_TIMPANI:
        case IMF_INSTRUMENT_ORCHESTRA_HIT:
        case IMF_INSTRUMENT_APPLAUSE:
            PROGRAM_NOISE_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 1, 14);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_LEAD_2_SAWTOOTH:
        case IMF_INSTRUMENT_PAD_1_NEW_AGE:
        case IMF_INSTRUMENT_PAD_2_WARM:
        case IMF_INSTRUMENT_TRUMPET:
        case IMF_INSTRUMENT_TROMBONE:
        case IMF_INSTRUMENT_TUBA:
        case IMF_INSTRUMENT_MUTED_TRUMPET:
        case IMF_INSTRUMENT_FRENCH_HORN:
        case IMF_INSTRUMENT_BRASS_SECTION:
        case IMF_INSTRUMENT_SYNTHBRASS_1:
        case IMF_INSTRUMENT_SYNTHBRASS_2:
        case IMF_INSTRUMENT_SOPRANO_SAX:
        case IMF_INSTRUMENT_ALTO_SAX:
        case IMF_INSTRUMENT_TENOR_SAX:
        case IMF_INSTRUMENT_BARITONE_SAX:
        case IMF_INSTRUMENT_OBOE:
        case IMF_INSTRUMENT_ENGLISH_HORN:
        case IMF_INSTRUMENT_BASSOON:
        case IMF_INSTRUMENT_CLARINET:
        case IMF_INSTRUMENT_PICCOLO:
        case IMF_INSTRUMENT_FLUTE:
        case IMF_INSTRUMENT_RECORDER:
        case IMF_INSTRUMENT_PAN_FLUTE:
        case IMF_INSTRUMENT_BLOWN_BOTTLE:
        case IMF_INSTRUMENT_SHAKUHACHI:
        case IMF_INSTRUMENT_WHISTLE:
        case IMF_INSTRUMENT_OCARINA:
            PROGRAM_SAW_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 14);
            break;

        case IMF_INSTRUMENT_SITAR:
        case IMF_INSTRUMENT_BANJO:
        case IMF_INSTRUMENT_SHAMISEN:
        case IMF_INSTRUMENT_KOTO:
        case IMF_INSTRUMENT_KALIMBA:
        case IMF_INSTRUMENT_BAG_PIPE:
        case IMF_INSTRUMENT_FIDDLE:
        case IMF_INSTRUMENT_SHANAI:
        case IMF_INSTRUMENT_TINKLE_BELL:
        case IMF_INSTRUMENT_AGOGO:
        case IMF_INSTRUMENT_STEEL_DRUMS:
        case IMF_INSTRUMENT_WOODBLOCK:
        case IMF_INSTRUMENT_TAIKO_DRUM:
        case IMF_INSTRUMENT_MELODIC_TOM:
        case IMF_INSTRUMENT_SYNTH_DRUM:
        case IMF_INSTRUMENT_REVERSE_CYMBAL:
        case IMF_INSTRUMENT_GUITAR_FRET_NOISE:
        case IMF_INSTRUMENT_BREATH_NOISE:
        case IMF_INSTRUMENT_SEASHORE:
        case IMF_INSTRUMENT_BIRD_TWEET:
        case IMF_INSTRUMENT_TELEPHONE_RING:
        case IMF_INSTRUMENT_HELICOPTER:
            PROGRAM_SAW_SV(_channels);
            PROGRAM_ATTACK_DECAY_SV(_channels, 3, 3);
            PROGRAM_SUSTAIN_RELEASE_SV(_channels, 14, 14);
            break;
    }

}

void vic1_set_frequency_vars( Environment * _environment, char * _channels, char * _frequency ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$7" );
    }
    outline1("LDX %s", _frequency );
    outline1("LDY %s", address_displacement(_environment, _frequency, "1") );

    outline0("JSR VIC1FREQ");

}

void vic1_set_pitch_vars( Environment * _environment, char * _channels, char * _pitch ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$7" );
    }
    outline1("LDX %s", _pitch );
    outline1("LDY %s", address_displacement(_environment, _pitch, "1") );

    outline0("JSR VIC1PROGFREQ");

}

void vic1_set_note_vars( Environment * _environment, char * _channels, char * _note ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );

    outline0("LDA #<VIC1FREQTABLE");
    outline0("STA TMPPTR");
    outline0("LDA #>VIC1FREQTABLE");
    outline0("STA TMPPTR+1");
    outline1("LDY %s", _note);
    outline0("TYA");
    outline0("ASL");
    outline0("TAY");
    outline0("LDA (TMPPTR),Y");
    outline0("TAX");
    outline0("INY");
    outline0("LDA (TMPPTR),Y");
    outline0("TAY");

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$7" );
    }

    outline0("JSR VIC1PROGFREQ");

}

void vic1_stop_vars( Environment * _environment, char * _channels ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );

    outline1("LDA %s", _channels );
    outline0("JSR VIC1STOP");

}

void vic1_music( Environment * _environment, char * _music, int _size, int _loop ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );

    outline0("SEI");
    outline1("LDA #<%s", _music);
    outline0("STA VIC1TMPPTR_BACKUP");
    outline1("LDA #>%s", _music);
    outline0("STA VIC1TMPPTR_BACKUP+1");
    outline1("LDA #$%2.2x", ( _size>>8 ) & 0xff);
    outline0("STA VIC1BLOCKS_BACKUP");
    outline1("LDA #$%2.2x", _size & 0xff );
    outline0("STA VIC1LASTBLOCK_BACKUP");
    outline1("LDA #$%2.2x", _loop);
    outline0("STA VIC1MUSICLOOP");
    outline0("JSR MUSICPLAYERRESET");
    outline0("CLI");

}

void vic1_slice_image( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination ) {

}

int vic1_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette ) {

    int paletteColorCount = rgbi_extract_palette(_environment, _data, _width, _height, _depth, _palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    memcpy( _palette, palette_match( _palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) ), paletteColorCount * sizeof( RGBi ) );

    int uniquePaletteCount = 0;

    memcpy( _palette, palette_remove_duplicates( _palette, paletteColorCount, &uniquePaletteCount ), paletteColorCount * sizeof( RGBi ) );

    return uniquePaletteCount;

}

void vic1_set_duration( Environment * _environment, int _channels, int _duration ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );

    PROGRAM_DURATION( _channels, _duration );

}

void vic1_wait_duration( Environment * _environment, int _channels ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );

    WAIT_DURATION( _channels );

}

void vic1_set_duration_vars( Environment * _environment, char * _channels, char * _duration ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );

    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$f" );
    }
    if ( _duration ) {
        outline1("LDX %s", _duration );
    } else {
        outline0("LDX #50" );
    }
    
    outline0("JSR VIC1SETDURATION");

}

void vic1_wait_duration_vars( Environment * _environment, char * _channels ) {

    deploy_preferred( vic1vars, src_hw_vic1_vars_asm );
    deploy( vic1startup, src_hw_vic1_startup_asm );
    
    if ( _channels ) {
        outline1("LDA %s", _channels );
    } else {
        outline0("LDA #$f" );
    }

    outline0("JSR VIC1WAITDURATION");

}

void vic1_screen( Environment * _environment, char * _x, char * _y, char * _c ) {

    deploy( screen, src_hw_vic1_screen_asm);

    outline1( "LDA %s", _x );
    outline0( "STA MATHPTR1" );
    outline1( "LDA %s", _y );
    outline0( "STA MATHPTR0" );
    outline0( "JSR SCREEN" );
    outline1( "STA %s", _c );

}

#endif