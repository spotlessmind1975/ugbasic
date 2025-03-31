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

#if defined(__pc128op__) || defined(__mo5__) || defined(__to8__)

#include "../ugbc.h"
#include <math.h>

#if defined(__pc128op__)

    static RGBi SYSTEM_PALETTE[] = {
            { 0x00, 0x00, 0x00, 0xff, 0, "BLACK", 0 },        
            { 0xff, 0xff, 0xff, 0xff, 1, "WHITE", 1 },
            { 0x88, 0x00, 0x00, 0xff, 2, "RED", 2 },
            { 0xaa, 0xff, 0xe6, 0xff, 3, "CYAN", 3 },
            { 0xcc, 0x44, 0xcc, 0xff, 4, "VIOLET", 4 },
            { 0x00, 0xcc, 0x55, 0xff, 5, "GREEN", 5 },
            { 0x00, 0x00, 0xaa, 0xff, 6, "BLUE", 6 },
            { 0xee, 0xee, 0x77, 0xff, 7, "YELLOW", 7 },
            { 0xa1, 0x68, 0x3c, 0xff, 8, "ORANGE", 8 },
            { 0xdd, 0x88, 0x65, 0xff, 9, "BROWN", 9 },
            { 0xff, 0x77, 0x77, 0xff, 10, "LIGHT RED", 10 },
            { 0x33, 0x33, 0x33, 0xff, 11, "DARK GREY", 11 },
            { 0x77, 0x77, 0x77, 0xff, 12, "GREY", 12 },
            { 0xaa, 0xff, 0x66, 0xff, 13, "LIGHT GREEN", 13 },
            { 0x00, 0x88, 0xff, 0xff, 14, "LIGHT BLUE", 14 },
            { 0xbb, 0xbb, 0xbb, 0xff, 15, "LIGHT GREY", 15 }
    };

#elif defined(__mo5__)

    static RGBi SYSTEM_PALETTE[] = {
            { 0x00, 0x00, 0x00, 0xff, 0, "BLACK", 0 },        
            { 0x88, 0x00, 0x00, 0xff, 1, "RED", 1 },
            { 0x00, 0xcc, 0x55, 0xff, 2, "GREEN", 2 },
            { 0xee, 0xee, 0x77, 0xff, 3, "YELLOW", 3 },
            { 0x00, 0x00, 0xaa, 0xff, 4, "BLUE", 4 },
            { 0xcc, 0x44, 0xcc, 0xff, 5, "VIOLET", 5 },
            { 0xaa, 0xff, 0xe6, 0xff, 6, "CYAN", 6 },
            { 0xff, 0xff, 0xff, 0xff, 7, "WHITE", 7 },
            { 0x77, 0x77, 0x77, 0xff, 8, "GREY", 8 },
            { 0xff, 0x77, 0x77, 0xff, 9, "OLD ROSE", 9 },
            { 0xaa, 0xff, 0x66, 0xff, 10, "LIGHT GREEN", 10 },
            { 0xdd, 0x88, 0x65, 0xff, 11, "SAND", 11 },
            { 0x00, 0x88, 0xff, 0xff, 12, "SKY BLUE", 12 },
            { 0xec, 0x54, 0xe4, 0xff, 13, "LIGHT MAGENTA", 13 },
            { 0xee, 0xff, 0xff, 0xff, 14, "CYAN", 14 },
            { 0xa1, 0x68, 0x3c, 0xff, 15, "ORANGE", 15 }
        };

#elif defined(__to8__)

    static RGBi SYSTEM_PALETTE[] = {
            { 0x00, 0x00, 0x00, 0xff, 0, "BLACK", 0 },        
            { 0xff, 0xff, 0xff, 0xff, 1, "WHITE", 1 },
            { 0x88, 0x00, 0x00, 0xff, 2, "RED", 2 },
            { 0xaa, 0xff, 0xe6, 0xff, 3, "CYAN", 3 },
            { 0xcc, 0x44, 0xcc, 0xff, 4, "VIOLET", 4 },
            { 0x00, 0xcc, 0x55, 0xff, 5, "GREEN", 5 },
            { 0x00, 0x00, 0xaa, 0xff, 6, "BLUE", 6 },
            { 0xee, 0xee, 0x77, 0xff, 7, "YELLOW", 7 },
            { 0xa1, 0x68, 0x3c, 0xff, 8, "ORANGE", 8 },
            { 0xdd, 0x88, 0x65, 0xff, 9, "BROWN", 9 },
            { 0xff, 0x77, 0x77, 0xff, 10, "LIGHT RED", 10 },
            { 0x33, 0x33, 0x33, 0xff, 11, "DARK GREY", 11 },
            { 0x77, 0x77, 0x77, 0xff, 12, "GREY", 12 },
            { 0xaa, 0xff, 0x66, 0xff, 13, "LIGHT GREEN", 13 },
            { 0x00, 0x88, 0xff, 0xff, 14, "LIGHT BLUE", 14 },
            { 0xbb, 0xbb, 0xbb, 0xff, 15, "LIGHT GREY", 15 }
    };

#endif

static RGBi * commonPalette;
int lastUsedSlotInCommonPalette = 0;

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

extern char DATATYPE_AS_STRING[][16];

static int rgbConverterFunction( int _red, int _green, int _blue ) {
    
    int value = ( ( ( _blue >> 4 ) & 0x0f ) << 8 ) |
            ( ( ( _green >> 4 ) & 0x0f ) << 4 ) |
            ( ( ( _red >> 4 ) & 0x0f ) );

    return value;

}

static void rgbConverterFunctionInverse( int _value, unsigned char* _red, unsigned char* _green, unsigned char* _blue ) {
    
    *_red = (unsigned char)( _value & 0xf ) << 4;
    *_green = (unsigned char)( _value & 0xf0 );
    *_blue = (unsigned char)( _value & 0xf00 ) >> 4;

}

/**
 * @brief <i>VIC-II</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with another sprite. The result (0 = no collision, 0xff = 
 * collision occurred) is returned in the output variable.
 * 
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void ef936x_collision( Environment * _environment, char * _sprite_mask, char * _result ) {
    
}

/**
 * @brief <i>VIC-II</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with a tile. The result (0 = no collision, 0xff = 
 * collision occurred) is returned in the output variable.
 * 
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void ef936x_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

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
void ef936x_border_color( Environment * _environment, char * _border_color ) {

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
void ef936x_background_color( Environment * _environment, int _index, int _background_color ) {

    outline1("LDB #$%2.2x", ( _index & 0x0f ) * 2 );
    outline0("STB BASE_SEGMENT+$DB" );
    outline1("LDD #$%4.4x", _background_color );
    outline1("STD SHADOWPALETTE+$%2.2x", ( _index & 0x0f ) * 2 );
    outline0("STB BASE_SEGMENT+$DA" );
    outline0("STA BASE_SEGMENT+$DA" );

    rgbConverterFunctionInverse( _background_color, &SYSTEM_PALETTE[_index].red, &SYSTEM_PALETTE[_index].green, &SYSTEM_PALETTE[_index].blue );

    // printf("SYSTEM_PALETTE[_index].index = %d\n", _index );
    // printf("SYSTEM_PALETTE[_index].red = %2.2x\n", SYSTEM_PALETTE[_index].red );
    // printf("SYSTEM_PALETTE[_index].green = %2.2x\n", SYSTEM_PALETTE[_index].green );
    // printf("SYSTEM_PALETTE[_index].blue = %2.2x\n", SYSTEM_PALETTE[_index].blue );
    // printf("\n" );

    SYSTEM_PALETTE[_index].index = _index;
    strcpy( SYSTEM_PALETTE[_index].description, "custom" );
    SYSTEM_PALETTE[_index].used = 0;
    SYSTEM_PALETTE[_index].count = 0;

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
void ef936x_background_color_vars( Environment * _environment, char * _index, char * _background_color ) {

    outline1("LDB %s", _index );
    outline0("LSLB" );
    outline0("STB BASE_SEGMENT+$DB" );
    outline1("LDD %s", _background_color );
    outline0("STB BASE_SEGMENT+$DA" );
    outline0("STA BASE_SEGMENT+$DA" );
    outline0("LDX #SHADOWPALETTE" );
    outline1("LDB %s", _index );
    outline0("LSLB" );
    outline0("ABX" );
    outline1("LDD %s", _background_color );
    outline0("STD B,X" );

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
void ef936x_background_color_semivars( Environment * _environment, int _index, char * _background_color ) {

    outline1("LDB #$%2.2x", (( _index & 0x0f ) *2) );
    outline0("STB BASE_SEGMENT+$DB" );
    outline1("LDD %s", _background_color );
    outline0("STB BASE_SEGMENT+$DA" );
    outline0("STA BASE_SEGMENT+$DA" );
    outline1("STD SHADOWPALETTE+$%2.2x", ( _index & 0x0f ) * 2 );

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
void ef936x_background_color_get_vars( Environment * _environment, char * _index, char * _background_color ) {

    outline1("LDB %s", _index );
    outline0("ASLB" );
    outline0("LDX #SHADOWPALETTE" );
    outline0("LDD B,X" );
    outline1("STD %s", _background_color );

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
void ef936x_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {

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
void ef936x_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

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
void ef936x_next_raster( Environment * _environment ) {

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
void ef936x_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

void ef936x_bank_select( Environment * _environment, int _bank ) {

}

void console_calculate( Environment * _environment ) {

    #if defined(__to8__)
        int consoleSA = 0x4000;
    #else
        int consoleSA = 0x0000;
    #endif
    int consoleWB = _environment->activeConsole.width * _environment->currentModeBW;
    int consoleHB = _environment->activeConsole.height * 8;

    cpu_store_16bit( _environment, "CONSOLESA", consoleSA );
    cpu_store_8bit( _environment, "CONSOLEWB", consoleWB );
    cpu_store_8bit( _environment, "CONSOLEHB", consoleHB );

}

void console_calculate_vars( Environment * _environment ) {

    outline0( "JSR CONSOLECALCULATE" );

}

int ef936x_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    deploy_preferred( ef936xvars, src_hw_ef936x_vars_asm );

    _environment->fontWidth = 8;
    _environment->fontHeight = 8;
    _environment->screenTiles = 255;
    switch( _screen_mode->id ) {
        case BITMAP_MODE_40_COLUMN:
            _environment->screenWidth = 320;
            _environment->screenHeight = 200;
            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 16;
            _environment->currentModeBW = 4;
            #if defined(__to8__)
                outline0("LDA #%00100000");
            #else
                outline0("LDA #%00000000");
            #endif
            outline0("STA BASE_SEGMENT+$DC");
            break;
        case BITMAP_MODE_80_COLUMN:
            _environment->screenWidth = 640;
            _environment->screenHeight = 200;
            _environment->screenTilesWidth = 80;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 4;
            _environment->currentModeBW = 2;
            outline0("LDA #%00101010");
            outline0("STA BASE_SEGMENT+$DC");
            break;
        case BITMAP_MODE_BITMAP_4:
            _environment->screenWidth = 320;
            _environment->screenHeight = 200;
            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 4;
            _environment->currentModeBW = 2;
            outline0("LDA #%00100001");
            outline0("STA BASE_SEGMENT+$DC");
            break;
        case BITMAP_MODE_BITMAP_16:
            _environment->screenWidth = 160;
            _environment->screenHeight = 200;
            _environment->screenTilesWidth = 20;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 16;
            _environment->currentModeBW = 4;
            outline0("LDA #%01111011");
            outline0("STA BASE_SEGMENT+$DC");
            break;
        case BITMAP_MODE_PAGE:
            _environment->screenWidth = 320;
            _environment->screenHeight = 200;
            _environment->screenTilesWidth = 40;
            _environment->screenTilesHeight = 25;
            _environment->screenColors = 4;
            _environment->currentModeBW = 2;
            outline0("LDA #%00100100");
            outline0("STA BASE_SEGMENT+$DC");
            break;
        default:
            CRITICAL_SCREEN_UNSUPPORTED( _screen_mode->id );
    }

    _environment->consoleTilesWidth = _environment->screenTilesWidth;
    _environment->consoleTilesHeight = _environment->screenTilesHeight;

    cpu_store_16bit( _environment, "CLIPX1", 0 );
    cpu_store_16bit( _environment, "CLIPX2", _environment->screenWidth-1 );
    cpu_store_16bit( _environment, "CLIPY1", 0 );
    cpu_store_16bit( _environment, "CLIPY2", _environment->screenHeight-1 );
    cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 40*200 );

    cpu_store_16bit( _environment, "ORIGINX", 0 );
    cpu_store_16bit( _environment, "ORIGINY", 0 );

    cpu_store_16bit( _environment, "CURRENTWIDTH", _environment->screenWidth );
    cpu_store_16bit( _environment, "CURRENTHEIGHT", _environment->screenHeight );
    cpu_move_16bit( _environment, "CURRENTWIDTH", "RESOLUTIONX" );
    cpu_move_16bit( _environment, "CURRENTHEIGHT", "RESOLUTIONY" );
    cpu_store_8bit( _environment, "CURRENTTILES", _environment->screenTiles );
    cpu_store_8bit( _environment, "CURRENTTILESWIDTH", _environment->screenTilesWidth );
    cpu_store_8bit( _environment, "CURRENTTILESHEIGHT", _environment->screenTilesHeight );

    console_init( _environment );

    if (_environment->vestigialConfig.clsImplicit ) {
        ef936x_cls( _environment );
    }

}

void ef936x_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors, 8, 8 );

    if ( mode ) {
        ef936x_screen_mode_enable( _environment, mode );
        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 0 );
        _environment->currentMode = mode->id;
        _environment->currentTileMode = 0;
    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void ef936x_bitmap_disable( Environment * _environment ) {    

}

void ef936x_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors, _tile_width, _tile_height );

    if ( mode ) {
        ef936x_screen_mode_enable( _environment, mode );
        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 1 );
        _environment->currentMode = mode->id;
        _environment->currentTileMode = 1;
    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void ef936x_bitmap_at( Environment * _environment, char * _address ) {

}

void ef936x_colormap_at( Environment * _environment, char * _address ) {    

}

void ef936x_textmap_at( Environment * _environment, char * _address ) {  

}

void ef936x_pset_int( Environment * _environment, int _x, int _y, int *_c ) {

    deploy_preferred( ef936xvars, src_hw_ef936x_vars_asm );
    deploy( plot, src_hw_ef936x_plot_asm );
    
    outline0("LDA #1");
    outline1("LDX %4.4x", (_x & 0xffff ) );
    outline1("LDU %4.4x", ( _y & 0xffff ) );
    if ( _c ) {
        outline1("LDB #$%2.2x", ( *_c & 0Xff ) );
    } else {
        Variable * c = variable_retrieve( _environment, "PEN" );
        outline1("LDB %s", c->realName );
    }
    outline0("STB <PLOTCPE" );
    outline0("JSR PLOT");  
}

void ef936x_pset_vars( Environment * _environment, char *_x, char *_y, char * _c ) {

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    Variable * c;
    
    if ( _c ) {
        c = variable_retrieve_or_define( _environment, _c, VT_COLOR, 0 );
    } else {
        c = variable_retrieve( _environment, "PEN" );
    }

    deploy_preferred( ef936xvars, src_hw_ef936x_vars_asm );
    deploy( plot, src_hw_ef936x_plot_asm );
    
    outline0("LDA #1");
    outline1("LDX %s", x->realName );
    outline1("LDU %s", y->realName );
    outline1("LDB %s", c->realName );
    outline0("STB <PLOTCPE" );
    outline0("JSR PLOT");

}

void ef936x_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result ) {

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    Variable * result = variable_retrieve_or_define( _environment, _result, VT_BYTE, 0 );

    deploy_preferred( ef936xvars, src_hw_ef936x_vars_asm );
    deploy( plot, src_hw_ef936x_plot_asm );
    
    outline0("LDA #3");
    outline1("LDX %s", x->realName );
    outline1("LDU %s", y->realName );
    outline0("JSR PLOT");
    outline1("STB %s", result->realName );    

}

void ef936x_screen_on( Environment * _environment ) {

}

void ef936x_screen_off( Environment * _environment ) {

}

void ef936x_screen_rows( Environment * _environment, char * _rows ) {

}

void ef936x_screen_columns( Environment * _environment, char * _columns ) {

}

void ef936x_sprite_data_from( Environment * _environment, char * _sprite, char * _address ) {

}

void ef936x_sprite_data_set( Environment * _environment, char * _sprite, char * _address ) {

}

void ef936x_sprite_enable( Environment * _environment, char * _sprite ) {

}

void ef936x_sprite_disable( Environment * _environment, char * _sprite ) {

}

void ef936x_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

}

void ef936x_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

}

void ef936x_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

}

void ef936x_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

}

void ef936x_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

}

void ef936x_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void ef936x_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void ef936x_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

}

void ef936x_sprite_priority( Environment * _environment, char * _sprite, char * _priority ) {

}

void ef936x_tiles_at( Environment * _environment, char * _address ) {

}

void ef936x_vertical_scroll( Environment * _environment, char * _displacement ) {

}

void ef936x_horizontal_scroll( Environment * _environment, char * _displacement ) {

}

void ef936x_get_width( Environment * _environment, char *_result ) {

    outline0("LDD CURRENTWIDTH" );
    outline1("STD %s", _result );

}

void ef936x_tiles_get( Environment * _environment, char *_result ) {

    outline0("LDB CURRENTTILES" );
    outline1("STB %s", _result );

}

void ef936x_get_height( Environment * _environment, char *_result ) {

    outline0("LDD CURRENTHEIGHT" );
    outline1("STD %s", _result );

}

void ef936x_cls( Environment * _environment ) {
    
    deploy( clsGraphic, src_hw_ef936x_cls_asm );
    
    outline0("JSR CLS");

}    
    
void ef936x_cls_box( Environment * _environment, char * _x1, char * _y1, char * _w, char * _h ) {

    deploy( clsBox, src_hw_ef936x_cls_box_asm );
    outline1("LDD %s", _x1 );
    outline0("STD <IMAGEX" );
    outline1("LDD %s", _y1 );
    outline0("STD <IMAGEY" );
    outline1("LDD %s", _w );
    outline0("STD <IMAGEW" );
    outline1("LDA %s", _h );
    outline0("STA <IMAGEH" );
    outline0("JSR CLSBOX");

}

void ef936x_scroll_text( Environment * _environment, int _direction, int _overlap ) {

    deploy( vScrollText, src_hw_ef936x_vscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA <DIRECTION" );

    outline0("JSR VSCROLLT");

}

void ef936x_text( Environment * _environment, char * _text, char * _text_size, int _raw ) {

    deploy_preferred( ef936xvars, src_hw_ef936x_vars_asm);
    deploy( vScrollText, src_hw_ef936x_vscroll_text_asm );
    deploy( clsGraphic, src_hw_ef936x_cls_asm );

    if( ! _environment->descriptors ) {
        font_descriptors_init( _environment, 0 );
    }

    outline1("LDY %s", _text);
    outline0("STY <TEXTPTR" );
    outline1("LDA %s", _text_size);
    outline0("STA <TEXTSIZE" );

    if ( _raw ) {
        deploy_preferred( textEncodedAtGraphicRaw, src_hw_ef936x_text_at_raw_asm );
        outline0("JSR TEXTATRAW");
    } else {
        deploy_preferred( textEncodedAtGraphic, src_hw_ef936x_text_at_asm );
        outline0("JSR TEXTAT");
    }

}

void ef936x_initialization( Environment * _environment ) {

    deploy_preferred( ef936xvars, src_hw_ef936x_vars_asm );
    deploy_preferred( ef936xstartup, src_hw_ef936x_startup_asm );

    variable_import( _environment, "CURRENTMODE", VT_BYTE, 0 );
    variable_global( _environment, "CURRENTMODE" );
    variable_import( _environment, "CURRENTTILEMODE", VT_BYTE, 1 );
    variable_global( _environment, "CURRENTTILEMODE" );

    variable_import( _environment, "CURRENTWIDTH", VT_POSITION, 320 );
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION, 200  );
    variable_global( _environment, "CURRENTHEIGHT" );
    variable_import( _environment, "CURRENTTILES", VT_BYTE, 255 );
    variable_global( _environment, "CURRENTTILES" );
    variable_import( _environment, "CURRENTTILESWIDTH", VT_SBYTE, 40 );
    variable_global( _environment, "CURRENTTILESWIDTH" );
    variable_import( _environment, "CURRENTTILESHEIGHT", VT_SBYTE, 25 );
    variable_global( _environment, "CURRENTTILESHEIGHT" );
    variable_import( _environment, "FONTWIDTH", VT_BYTE, 8 );
    variable_global( _environment, "FONTWIDTH" );
    variable_import( _environment, "FONTHEIGHT", VT_BYTE, 8 );
    variable_global( _environment, "FONTHEIGHT" );

#if !defined(__mo5__)
    SCREEN_MODE_DEFINE( BITMAP_MODE_BITMAP_16, 1, 160, 200, 16, 8, 8, "BITMAP MODE BITMAP 16" );
#endif
    SCREEN_MODE_DEFINE( BITMAP_MODE_40_COLUMN, 1, 320, 200, 15, 8, 8, "BITMAP MODE 40 COLUMN" );
#if !defined(__mo5__)
    SCREEN_MODE_DEFINE( BITMAP_MODE_BITMAP_4, 1, 320, 200, 4, 8, 8, "BITMAP MODE BITMAP 4" );
#endif
    // SCREEN_MODE_DEFINE( BITMAP_MODE_80_COLUMN, 1, 640, 200, 2, 8, 8, "BITMAP MODE 80 COLUMN" );
    // SCREEN_MODE_DEFINE( BITMAP_MODE_PAGE, 1, 320, 200, 4, 8, 8, "BITMAP MODE PAGE" );

    outline0("JSR EF936XSTARTUP");

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
    variable_import( _environment, "CLIPX2", VT_POSITION, 319 );
    variable_global( _environment, "CLIPX2" );
    variable_import( _environment, "CLIPY1", VT_POSITION, 0 );
    variable_global( _environment, "CLIPY1" );
    variable_import( _environment, "CLIPY2", VT_POSITION, 199 );
    variable_global( _environment, "CLIPY2" );

    variable_import( _environment, "ORIGINX", VT_POSITION, 0 );
    variable_global( _environment, "ORIGINX" );
    variable_import( _environment, "ORIGINY", VT_POSITION, 0 );
    variable_global( _environment, "ORIGINY" );

    variable_import( _environment, "RESOLUTIONX", VT_POSITION, 0 );
    variable_global( _environment, "RESOLUTIONX" );
    variable_import( _environment, "RESOLUTIONY", VT_POSITION, 0 );
    variable_global( _environment, "RESOLUTIONY" );

    // ef936x_cls( _environment );

    _environment->fontWidth = 8;
    _environment->fontHeight = 8;
    _environment->screenTilesWidth = 40;
    _environment->screenTilesHeight = 25;
    _environment->consoleTilesWidth = 40;
    _environment->consoleTilesHeight = 25;
    _environment->screenTiles = 255;
    _environment->screenWidth = _environment->screenTilesWidth * _environment->fontWidth;
    _environment->screenHeight = _environment->screenTilesHeight * _environment->fontHeight;
    _environment->screenShades = 16;
    _environment->screenColors = 16;
    _environment->currentModeBW = 1;
    _environment->currentRgbConverterFunction = rgbConverterFunction;

    cpu_store_16bit( _environment, "CLIPX1", 0 );
    cpu_store_16bit( _environment, "CLIPX2", _environment->screenWidth-1 );
    cpu_store_16bit( _environment, "CLIPY1", 0 );
    cpu_store_16bit( _environment, "CLIPY2", _environment->screenHeight-1 );
    cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 40*200 );

    cpu_store_16bit( _environment, "ORIGINX", 0 );
    cpu_store_16bit( _environment, "ORIGINY", 0 );

    cpu_store_16bit( _environment, "CURRENTWIDTH", _environment->screenWidth );
    cpu_store_16bit( _environment, "CURRENTHEIGHT", _environment->screenHeight );
    cpu_store_8bit( _environment, "CURRENTTILESWIDTH", _environment->screenTilesWidth );
    cpu_store_8bit( _environment, "CURRENTTILESHEIGHT", _environment->screenTilesHeight );

    font_descriptors_init( _environment, 1 );

    _environment->currentRgbConverterFunction = rgbConverterFunction;
    _environment->screenShades = 4096;

    console_init( _environment );
    
    screen_mode( _environment, 0 );

}

extern RGBi * commonPalette;

// Converts a PC color to a thomson color for ef936 
// considering its very high gamma value.
// Author: Samuel Devulder
static int pc_to_ef936x(int _pc_color) {
	// if(1) return (_pc_color>>4)&15;
	double pc_color = _pc_color/255.0;
	double ef936_color = 15*pow(pc_color, 1.67);
	return 0x0F & (int)(ef936_color + 0.5);
}

// Calculate gamma value for each component.
// Author: Dino Florenzi
static unsigned short df_gamma(unsigned char c)
{
    int i,col=0;
    int ef_vals[16]={0,60,90,110,130,148,165,180,193,205,215,225,230,235,240,255};
    for (i=0;i<15;i++)
    {
        if((c>=ef_vals[i])&&(c<ef_vals[i+1])) return i;
    }
    return 15;
}

void ef936x_finalization( Environment * _environment ) {

    int i;

    outhead0("COMMONPALETTE");
    out0("      fdb ");

    RGBi * palette;

    if ( commonPalette ) {
        palette = commonPalette;
    } else {
        palette = SYSTEM_PALETTE;
    }

#if defined( __to8__ ) || defined( __mo5__ )
    if ( _environment->currentMode < 3 ) {
        
        RGBi * transposedPalette = malloc_palette( 16 );
        rgbi_move( &palette[0], &transposedPalette[8] );
        rgbi_move( &palette[1], &transposedPalette[10] );
        rgbi_move( &palette[2], &transposedPalette[12] );
        rgbi_move( &palette[3], &transposedPalette[14] );

        rgbi_move( &palette[4], &transposedPalette[0] );
        rgbi_move( &palette[5], &transposedPalette[2] );
        rgbi_move( &palette[6], &transposedPalette[4] );
        rgbi_move( &palette[7], &transposedPalette[6] );

        palette = transposedPalette;
    }
#endif

    for( i=0; i<15; ++i ) {
        switch( _environment->gammaCorrection ) {
            case GAMMA_CORRECTION_NONE:
                out4( "$%1.1x%1.1x%1.1x%1.1x, ", 
                    0, 
                    ( EF936X_COMPONENT_BITMASK * 0x10 ) | ( ( palette[i].blue >> 4 ) & 0x0f ) , 
                    ( ( palette[i].green >> 4 ) & 0x0f ) , 
                    ( ( palette[i].red >> 4 ) & 0x0f )  
                );
                break;
            case GAMMA_CORRECTION_TYPE1:
                out4( "$%1.1x%1.1x%1.1x%1.1x, ", 
                    0, 
                    ( EF936X_COMPONENT_BITMASK * 0x10 ) | ( pc_to_ef936x( palette[i].blue >> 4 ) & 0x0f ) , 
                    ( pc_to_ef936x( palette[i].green >> 4 ) & 0x0f ) , 
                    ( pc_to_ef936x( palette[i].red >> 4 ) & 0x0f )  
                );
                break;
            case GAMMA_CORRECTION_TYPE2:
                out4( "$%1.1x%1.1x%1.1x%1.1x, ", 
                    0, 
                    ( EF936X_COMPONENT_BITMASK * 0x10 ) | ( df_gamma( palette[i].blue >> 4 ) & 0x0f ) , 
                    ( df_gamma( palette[i].green >> 4 ) & 0x0f ) , 
                    ( df_gamma( palette[i].red >> 4 ) & 0x0f )  
                );
                break;
        }
    }
    outline4("$%1.1x%1.1x%1.1x%1.1x", 0, EF936X_COMPONENT_BITMASK * 0x10 | ( ( palette[15].blue >> 4 ) & 0x0f ) , ( ( palette[15].green >> 4 ) & 0x0f ) , ( ( palette[15].red >> 4 ) & 0x0f )  );

    if ( _environment->vestigialConfig.clsImplicit ) {
        deploy( clsGraphic, src_hw_ef936x_cls_asm );

    }

}

void ef936x_hscroll_line( Environment * _environment, int _direction, int _overlap ) {

    deploy( textHScroll, src_hw_ef936x_hscroll_text_asm );

    Variable * y = variable_retrieve( _environment, "YCURSYS" );
    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA <DIRECTION" );
    outline1("LDA %s", y->realName );
    outline0("STA <CLINEY");

    outline0("JSR HSCROLLLT");    

}

void ef936x_hscroll_screen( Environment * _environment, int _direction, int _overlap ) {

    deploy( textHScroll, src_hw_ef936x_hscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA <DIRECTION" );

    outline0("JSR HSCROLLST");    

}

void ef936x_back( Environment * _environment ) {

}

void ef936x_cline( Environment * _environment, char * _characters ) {

    deploy( textCline, src_hw_ef936x_cline_asm );
    Variable * x = variable_retrieve( _environment, "XCURSYS" );
    Variable * y = variable_retrieve( _environment, "YCURSYS" );

    if ( _characters ) {
        outline1("LDA %s", _characters);
    } else {
        outline0("LDA #0");
    }
    outline0("STA <CHARACTERS");
    outline1("LDA %s", x->realName );
    outline0("STA <CLINEX" );
    outline1("LDA %s", y->realName );
    outline0("STA <CLINEY");
    outline0("JSR CLINEG");

}

int ef936x_image_size( Environment * _environment, int _width, int _height, int _mode ) {

    switch( _mode ) {
        case BITMAP_MODE_40_COLUMN:
            return 3 + 2 * ( ( _width >> 3 ) * _height );
        case BITMAP_MODE_BITMAP_4:
            return 3 + 2 * ( ( _width >> 3 ) * _height ) /*+ 8*/;
        case BITMAP_MODE_80_COLUMN:
        case BITMAP_MODE_BITMAP_16:
            return 3 + 2 * ( ( _width >> 2 ) * _height ) /*+ 32*/;
        case BITMAP_MODE_PAGE:
            // WARNING_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );
            break;
    }

    return 0;

}

static int calculate_images_size( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

    switch( _mode ) {
        case BITMAP_MODE_40_COLUMN:
            return 3 + ( 3 + 2 * ( ( _width >> 3 ) * _height ) ) * _frames;
        case BITMAP_MODE_BITMAP_4:
            return 3 + ( 3 + 2 * ( ( _width >> 3 ) * _height ) /*+ 8*/ ) * _frames;
        case BITMAP_MODE_80_COLUMN:
        case BITMAP_MODE_BITMAP_16:
            return 3 + ( 3 + 2 * ( ( _width >> 2 ) * _height ) /*+ 32*/ ) * _frames;
        case BITMAP_MODE_PAGE:
            // WARNING_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );
            break;
    }

    return 0;

}

static int calculate_sequence_size( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

    switch( _mode ) {
        case BITMAP_MODE_40_COLUMN:
            return 3 + ( ( 3 + 2 * ( ( _width >> 3 ) * _height ) ) * _frames ) * _sequences;
        case BITMAP_MODE_BITMAP_4:
            return 3 + ( ( 3 + 2 * ( ( _width >> 3 ) * _height ) /*+ 8*/ ) * _frames ) * _sequences;
        case BITMAP_MODE_80_COLUMN:
        case BITMAP_MODE_BITMAP_16:
            return 3 + ( ( 3 + 2 * ( ( _width >> 2 ) * _height ) /*+ 32*/ ) * _frames ) * _sequences;
        case BITMAP_MODE_PAGE:
            // WARNING_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );
            break;
    }

    return 0;

}

static Variable * ef936x_image_converter_bitmap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    // ignored on bitmap mode
    (void)!_transparent_color;

    image_converter_asserts_free( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    RGBi * palette = malloc_palette( MAX_PALETTE );
    
    int paletteColorCount = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    if (paletteColorCount > 2) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( paletteColorCount );
    }

    int i, j, k;

    if ( ! commonPalette ) {

        commonPalette = palette_match_hardware_index( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
        commonPalette = palette_remove_duplicates( palette, paletteColorCount, &paletteColorCount );

        if ( _transparent_color & 0x0f0000 ) {
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, paletteColorCount );
        }
        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, paletteColorCount, 2 );
            paletteColorCount = 2;
        }

        lastUsedSlotInCommonPalette = paletteColorCount;
        adilinepalette( "CPM1:%d", paletteColorCount, commonPalette );

    } else {

        commonPalette = palette_match_hardware_index( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
        RGBi * newPalette = palette_remove_duplicates( palette, paletteColorCount, &paletteColorCount );
        adilinepalette( "CPM1:%d", paletteColorCount, newPalette );

        int mergedCommonPalette = 0;

        commonPalette = palette_merge( commonPalette, lastUsedSlotInCommonPalette, newPalette, paletteColorCount, &mergedCommonPalette );

        if ( _transparent_color & 0x0f0000 ) {
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, mergedCommonPalette );
        }
        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, mergedCommonPalette, 16 );
            mergedCommonPalette = 2;
        }

        lastUsedSlotInCommonPalette = mergedCommonPalette;
        if ( lastUsedSlotInCommonPalette > 2 ) {
            lastUsedSlotInCommonPalette = 2;
        }
        adilinepalette( "CPM2:%d", lastUsedSlotInCommonPalette, commonPalette );

    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = lastUsedSlotInCommonPalette;
    memcpy( result->originalPalette, commonPalette, lastUsedSlotInCommonPalette * sizeof( RGBi ) );

    int bufferSize = ef936x_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_DEFAULT );;
    // printf("bufferSize = %d\n", bufferSize );

    adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_DEFAULT );

    adilinebeginbitmap("BMD");

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

    *(buffer) = (_frame_width >> 8 ) & 0xff;
    *(buffer+1) = (_frame_width ) & 0xff;
    *(buffer+2) = _frame_height;

    _source += ( ( _offset_y * _width ) + _offset_x ) * _depth;

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
            if ( rgb.alpha == 0 ) {
                rgb.red = 0;
                rgb.green = 0;
                rgb.blue = 0;
            }

            int colorIndex = 0;
            int firstIndex = 0;
            if ( _transparent_color & 0x0f0000 ) {
                firstIndex = 1;
            }

            if ( rgb.alpha < 255 ) {
                colorIndex = 0;
            } else {
                unsigned int minDistance = 0xffff;
                for( i=firstIndex; i<lastUsedSlotInCommonPalette; ++i ) {
                    if ( commonPalette[i].alpha < 255 ) continue;
                    unsigned int distance = rgbi_distance(&commonPalette[i], &rgb);
                    if ( minDistance > distance ) {
                        minDistance = distance;
                        colorIndex = i;
                    }
                }
            }

            adilinepixel(colorIndex);

            // printf("%d", i );

            // Calculate the offset starting from the tile surface area
            // and the bit to set.
            offset = ( image_y * ( _frame_width >> 3 ) ) + ( image_x >> 3 );
            bitmask = 1 << ( 7 - (image_x & 0x7) );

            if ( i == 1 ) {
                *( buffer + offset + 3) |= bitmask;
                // printf("*");
            } else {
                *( buffer + offset + 3) &= ~bitmask;
                // printf(" ");
            }

            _source += _depth;

        }

        _source += ( _width - _frame_width ) * _depth;

        // printf("\n" );

    }

    adilineendbitmap();

    // printf("----\n");

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    // printf("----\n");

    return result;

}

static Variable * ef936x_image_converter_multicolor_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    image_converter_asserts_free( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

#if defined( __mo5__ ) 

    RGBi * palette = &SYSTEM_PALETTE[0];
    int paletteColorCount = 16;
    commonPalette = &SYSTEM_PALETTE[0];
    lastUsedSlotInCommonPalette = 16;

#else

    RGBi * palette = malloc_palette( MAX_PALETTE );
    
    int paletteColorCount = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    if (paletteColorCount > 16) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( paletteColorCount );
    }

    int i, j, k;

    if ( ! commonPalette ) {

        commonPalette = palette_match_hardware_index( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
        commonPalette = palette_remove_duplicates( commonPalette, paletteColorCount, &paletteColorCount );

        if ( ( _transparent_color & 0x0f0000 ) || ( _transparent_color & 0xf00000 ) ) {
            commonPalette = palette_shift( commonPalette, (paletteColorCount == MAX_PALETTE) ? (MAX_PALETTE-1) : (paletteColorCount), 1 );
        }
        
        if ( _transparent_color & 0x0f0000 ) {
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, paletteColorCount );
        }
        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, paletteColorCount, 4 );
            paletteColorCount = 16;
        }        

        lastUsedSlotInCommonPalette = paletteColorCount;
        adilinepalette( "CPM1:%d", paletteColorCount, commonPalette );

    } else {

        RGBi * newPalette = palette_match_hardware_index( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
        newPalette = palette_remove_duplicates( newPalette, paletteColorCount, &paletteColorCount );
        adilinepalette( "CPM1:%d", paletteColorCount, newPalette );

        int mergedCommonPalette = 0;

        commonPalette = palette_merge( commonPalette, lastUsedSlotInCommonPalette, newPalette, paletteColorCount, &mergedCommonPalette );

        if ( _transparent_color & 0x0f0000 ) {
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, mergedCommonPalette );
        }
        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, mergedCommonPalette, 16 );
            mergedCommonPalette = 16;
        }

        lastUsedSlotInCommonPalette = mergedCommonPalette;
        if ( lastUsedSlotInCommonPalette > 16 ) {
            lastUsedSlotInCommonPalette = 16;
        }
        adilinepalette( "CPM2:%d", lastUsedSlotInCommonPalette, commonPalette );

    }

#endif

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = lastUsedSlotInCommonPalette;
    memcpy( result->originalPalette, commonPalette, lastUsedSlotInCommonPalette * sizeof( RGBi ) );

    int bufferSize = ef936x_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_40_COLUMN );
    
    adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_40_COLUMN );

    adilinebeginbitmap("BMD");

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

    *(buffer) = (_frame_width >> 8 ) & 0xff;
    *(buffer+1) = ( _frame_width ) & 0xff;
    *(buffer+2) = _frame_height;

    _source += ( ( _offset_y * _width ) + _offset_x ) * _depth;

    // Loop for all the source surface.
    for (image_y = 0; image_y < _frame_height; ++image_y) {
        for (image_x = 0; image_x < _frame_width; image_x+=8) {
            int colorIndexes[8];
            memset( colorIndexes, 0, 8*sizeof( int ) );
            int trans = 0;

            for( int xx = 0; xx<8; ++xx ) {
                // Take the color of the pixel
                rgb.red = *_source;
                rgb.green = *(_source + 1);
                rgb.blue = *(_source + 2);
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

                int firstIndex = 0;
                if ( _transparent_color & 0x0f0000 ) {
                    firstIndex = 1;
                }

                if ( rgb.alpha < 255 ) {
                    colorIndexes[xx] = 0;
                } else {
                    int minDistance = 9999;
                    for( int i=firstIndex; i<lastUsedSlotInCommonPalette; ++i ) {
                    if ( commonPalette[i].alpha < 255 ) continue;
                        int distance = rgbi_distance(&commonPalette[i], &rgb );
                        if ( distance < minDistance ) {
                            minDistance = distance;
                            colorIndexes[xx] = i;
                        }
                    }
                }

                _source += _depth;

            }

            int colorIndexesCount[16];
            memset( colorIndexesCount, 0, 16*sizeof( int ) );

            for( int xx = 0; xx<8; ++xx ) {
                ++colorIndexesCount[colorIndexes[xx]];
            }

            int colorBackground = 0;
            int colorBackgroundMax = 0;
            int colorForeground = 0;
            int colorForegroundMax = 0;

            if ( trans ) {

            } else {
                for( int xx = 0; xx<16; ++xx ) {
                    if ( colorIndexesCount[xx] > colorBackgroundMax ) {
                        colorBackground = xx;
                        colorBackgroundMax = colorIndexesCount[xx];
                    };
                }

            }

            colorIndexesCount[colorBackground] = 0;

            for( int xx = 0; xx<16; ++xx ) {
                if ( colorIndexesCount[xx] > colorForegroundMax ) {
                    colorForeground = xx;
                    colorForegroundMax = colorIndexesCount[xx];
                };
            }

            if ( colorForeground == colorBackground ) {
                colorForeground = ( colorBackground == 0 ) ? 1 : 0;
            }

            for( int xx = 0; xx<8; ++xx ) {
                offset = ( image_y * ( _frame_width >> 3 ) ) + ( image_x >> 3 );
                bitmask = 1 << ( 7 - ((image_x+xx) & 0x7) );

                if ( colorIndexes[xx] != colorBackground ) {
                    adilinepixel(colorForeground);
                    *( buffer + offset + 3) |= bitmask;
                    if ( _environment->debugImageLoad ) {
                        printf( "%1.1x", colorForeground );
                    }
                    // printf("*");
                } else {
                    adilinepixel(colorBackground);
                    *( buffer + offset + 3) &= ~bitmask;
                    // printf(" ");
                    if ( _environment->debugImageLoad ) {
                        printf( "%1.1x", colorBackground );
                    }
                }

                offset = ( image_y * ( _frame_width >> 3 ) ) + ( image_x >> 3 );

                bitmask = colorForeground << 4 | ( colorBackground );
                *(buffer + 3 + ( ( _frame_width >> 3 ) * _frame_height ) + offset) = bitmask;

            }
        }

        _source += ( _width - _frame_width ) * _depth;

        if ( _environment->debugImageLoad ) {
            printf("\n" );
        }
    }

    adilineendbitmap();

    // for(i=0; i<4; ++i ) {
    //     printf( "%1.1x = %2.2x\n", i, palette[i].index );
    // }

    if ( _environment->debugImageLoad ) {
        printf("\n" );
        printf("\n" );
    }
    
    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    return result;

}

static Variable * ef936x_image_converter_multicolor_mode4( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    image_converter_asserts_free( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

#if defined( __mo5__ ) 

    RGBi * palette = &SYSTEM_PALETTE[0];
    int paletteColorCount = 16;
    commonPalette = &SYSTEM_PALETTE[0];
    lastUsedSlotInCommonPalette = 16;

    int i;

#else

    RGBi * palette = malloc_palette( MAX_PALETTE );
    
    int paletteColorCount = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    if (paletteColorCount > 4) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( paletteColorCount );
    }

    int i, j, k;

    if ( ! commonPalette ) {

        commonPalette = palette_match_hardware_index( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
        commonPalette = palette_remove_duplicates( commonPalette, paletteColorCount, &paletteColorCount );

        if ( ( _transparent_color & 0x0f0000 ) || ( _transparent_color & 0xf00000 ) ) {
            commonPalette = palette_shift( commonPalette, (paletteColorCount == MAX_PALETTE) ? (MAX_PALETTE-1) : (paletteColorCount), 1 );
        }
        
        if ( _transparent_color & 0x0f0000 ) {
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, paletteColorCount );
        }
        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, paletteColorCount, 16 );
            paletteColorCount = 4;
        }

        lastUsedSlotInCommonPalette = paletteColorCount;
        adilinepalette( "CPM1:%d", paletteColorCount, commonPalette );

    } else {

        RGBi * newPalette = palette_match_hardware_index( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
        newPalette = palette_remove_duplicates( newPalette, paletteColorCount, &paletteColorCount );
        adilinepalette( "CPM1:%d", paletteColorCount, newPalette );

        int mergedCommonPalette = 0;

        commonPalette = palette_merge( commonPalette, lastUsedSlotInCommonPalette, newPalette, paletteColorCount, &mergedCommonPalette );

        if ( _transparent_color & 0x0f0000 ) {
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, mergedCommonPalette );
        }
        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, mergedCommonPalette, 16 );
            mergedCommonPalette = 4;
        }

        lastUsedSlotInCommonPalette = mergedCommonPalette;
        if ( lastUsedSlotInCommonPalette > 4 ) {
            lastUsedSlotInCommonPalette = 4;
        }
        adilinepalette( "CPM2:%d", lastUsedSlotInCommonPalette, commonPalette );

    }

#endif

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = lastUsedSlotInCommonPalette;
    memcpy( result->originalPalette, commonPalette, lastUsedSlotInCommonPalette * sizeof( RGBi ) );

    int bufferSize = ef936x_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_BITMAP_4 );
    
    adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_BITMAP_4 );

    adilinebeginbitmap("BMD");

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

    *(buffer) = ( _frame_width >> 8 ) & 0xff;
    *(buffer+1) = ( _frame_width ) & 0xff;
    *(buffer+2) = _frame_height;

    _source += ( ( _offset_y * _width ) + _offset_x ) * _depth;

    // Loop for all the source surface.
    for (image_y = 0; image_y < _frame_height; ++image_y) {
        for (image_x = 0; image_x < _frame_width; ++image_x) {

            // Take the color of the pixel
            rgb.red = *_source;
            rgb.green = *(_source + 1);
            rgb.blue = *(_source + 2);
            if ( _depth > 3 ) {
                rgb.alpha = *(_source + 3 );
            } else {
                rgb.alpha= 255;
            }
            if ( rgb.alpha == 0 ) {
                rgb.red = 0;
                rgb.green = 0;
                rgb.blue = 0;
            }

            unsigned int minDistance = 0xffff;
            int colorIndex = 0;
            int firstIndex = 0;
            if ( _transparent_color & 0x0f0000 ) {
                firstIndex = 1;
            }

            colorIndex = 0;

            if ( rgb.alpha < 255 ) {

            } else {
                for( i=firstIndex; i<lastUsedSlotInCommonPalette; ++i ) {
                    if ( commonPalette[i].alpha < 255 ) continue;
                    unsigned int distance = rgbi_distance(&commonPalette[i], &rgb);
                    if ( minDistance > distance ) {
                        minDistance = distance;
                        colorIndex = i;
                    }
                }
            }
            // printf( "%1.1x", colorIndex );

            adilinepixel(colorIndex);

            bitmask = 1 << ( 7 - (image_x & 0x7) );

            *(buffer + 3 + ( image_x >> 3 ) + ( ( _frame_width >> 3 ) * image_y ) ) |= ( ( colorIndex & 0x02 ) == 0x02 ) ? bitmask : 0;
            *(buffer + 3 + ( ( _frame_width >> 3 ) * _frame_height ) + ( ( image_x >> 3 ) + ( _frame_width >> 3 ) * image_y ) ) |= ( ( colorIndex & 0x01 ) == 0x01 ) ? bitmask : 0;

            _source += _depth;

        }

        _source += ( _width - _frame_width ) * _depth;

        // printf("\n" );
    }

    adilineendbitmap();

    // RGBi * color = &SYSTEM_PALETTE[commonPalette[0].index];
    // *(buffer + 2 + 2 * ( ( _width >> 3 ) * _height ) + 1 ) = ( color->green & 0xf0 ) | ( ( color->red & 0xf0 ) >> 4 );
    // *(buffer + 2 + 2 * ( ( _width >> 3 ) * _height ) ) = ( ( color->blue & 0xf0 ) >> 4 );
    
    // color = &SYSTEM_PALETTE[commonPalette[1].index];
    // *(buffer + 2 + 2 * ( ( _width >> 3 ) * _height ) + 3 ) = ( color->green & 0xf0 ) | ( ( color->red & 0xf0 ) >> 4 );
    // *(buffer + 2 + 2 * ( ( _width >> 3 ) * _height ) + 2 ) = ( ( color->blue & 0xf0 ) >> 4 );

    // color = &SYSTEM_PALETTE[commonPalette[2].index];
    // *(buffer + 2 + 2 * ( ( _width >> 3 ) * _height ) + 5 ) = ( color->green & 0xf0 ) | ( ( color->red & 0xf0 ) >> 4 );
    // *(buffer + 2 + 2 * ( ( _width >> 3 ) * _height ) + 4 ) = ( ( color->blue & 0xf0 ) >> 4 );

    // color = &SYSTEM_PALETTE[commonPalette[3].index];
    // *(buffer + 2 + 2 * ( ( _width >> 3 ) * _height ) + 7 ) = ( color->green & 0xf0 ) | ( ( color->red & 0xf0 ) >> 4 );
    // *(buffer + 2 + 2 * ( ( _width >> 3 ) * _height ) + 6 ) = ( ( color->blue & 0xf0 ) >> 4 );

    // for(i=0; i<4; ++i ) {
    //     printf( "%1.1x = %2.2x\n", i, palette[i].index );
    // }

    // printf("\n" );
    // printf("\n" );

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    return result;

}

static Variable * ef936x_image_converter_multicolor_mode16( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    image_converter_asserts_free( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

#if defined( __mo5__ ) 

    RGBi * palette = &SYSTEM_PALETTE[0];
    int paletteColorCount = 16;
    commonPalette = &SYSTEM_PALETTE[0];
    lastUsedSlotInCommonPalette = 16;

    int i;
    
#else

    RGBi * palette = malloc_palette( MAX_PALETTE );
    
    int paletteColorCount = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    if (paletteColorCount > 16) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( paletteColorCount );
    }

    int i, j, k;

    if ( ! commonPalette ) {

        commonPalette = palette_match_hardware_index( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
        commonPalette = palette_remove_duplicates( commonPalette, paletteColorCount, &paletteColorCount );
        if ( ( _transparent_color & 0x0f0000 ) || ( _transparent_color & 0xf00000 ) ) {
            commonPalette = palette_shift( commonPalette, (paletteColorCount == MAX_PALETTE) ? (MAX_PALETTE-1) : (paletteColorCount), 1 );
        }

        if ( _transparent_color & 0x0f0000 ) {
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, paletteColorCount );
        }

        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, paletteColorCount, 16 );
            paletteColorCount = 16;
        }

        lastUsedSlotInCommonPalette = paletteColorCount;
        adilinepalette( "CPM1:%d", paletteColorCount, commonPalette );

    } else {

        RGBi * newPalette = palette_match_hardware_index( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );

        newPalette = palette_remove_duplicates( newPalette, paletteColorCount, &paletteColorCount );

        adilinepalette( "CPM1:%d", paletteColorCount, newPalette );

        int mergedCommonPalette = 0;

        commonPalette = palette_merge( commonPalette, lastUsedSlotInCommonPalette, newPalette, paletteColorCount, &mergedCommonPalette );

        if ( _transparent_color & 0x0f0000 ) {
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, mergedCommonPalette );
        }

        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, mergedCommonPalette, 16 );
            mergedCommonPalette = 16;
        }

        lastUsedSlotInCommonPalette = mergedCommonPalette;
        if ( lastUsedSlotInCommonPalette > 16 ) {
            lastUsedSlotInCommonPalette = 16;
        }
        adilinepalette( "CPM2:%d", lastUsedSlotInCommonPalette, commonPalette );

    }

#endif

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = lastUsedSlotInCommonPalette;
    memcpy( result->originalPalette, commonPalette, lastUsedSlotInCommonPalette * sizeof( RGBi ) );

    int bufferSize = ef936x_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_BITMAP_16 );
    
    adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_BITMAP_4 );

    adilinebeginbitmap("BMD");    

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

    *(buffer) = ( _frame_width >> 8 ) & 0xff;
    *(buffer+1) = ( _frame_width ) & 0xff;
    *(buffer+2) = _frame_height;

    _source += ( ( _offset_y * _width ) + _offset_x ) * _depth;

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
            if ( rgb.alpha == 0 ) {
                rgb.red = 0;
                rgb.green = 0;
                rgb.blue = 0;
            }

            int minDistance = 0xffff;
            int colorIndex = 0;
            int firstIndex = 0;
            if ( _transparent_color & 0x0f0000 ) {
                firstIndex = 1;
            }

            colorIndex = 0;

            if ( rgb.alpha < 255 ) {

            } else {
                for( i=firstIndex; i<lastUsedSlotInCommonPalette; ++i ) {
                    if ( commonPalette[i].alpha < 255 ) continue;
                    int distance = rgbi_distance(&commonPalette[i], &rgb);
                    if ( minDistance > distance ) {
                        minDistance = distance;
                        colorIndex = i;
                    }
                }
            }

            // printf( "%1.1x", colorIndex );

            bitmask = colorIndex << ( 4 * ( 1 - (image_x & 0x1) ) );

            adilinepixel(colorIndex);

            // printf( "%2.2x", bitmask );

            if ( ( ( image_x & 0x03 ) < 0x02 ) ) {
                *(buffer + 3 + ( image_x >> 2 ) + ( ( _frame_width >> 2 ) * image_y ) ) |= bitmask;
            } else {
                *(buffer + 3 + ( ( _frame_width >> 2 ) * _frame_height ) + ( ( image_x >> 2 ) + ( _frame_width >> 2 ) * image_y ) ) |= bitmask;
            }

            _source += _depth;

        }

        _source += ( _width - _frame_width ) * _depth;

        // printf("\n" );
    }

    adilineendbitmap();
    
    // for (i=0; i<16; ++i ) {
    //     RGBi * color = &SYSTEM_PALETTE[commonPalette[i].index];
    //     *(buffer + 2 + 2 * ( ( _width >> 2 ) * _height ) + 2*i + 1 ) = ( color->green & 0xf0 ) | ( ( color->red & 0xf0 ) >> 4 );
    //     *(buffer + 2 + 2 * ( ( _width >> 2 ) * _height ) + 2*i ) = ( ( color->blue & 0xf0 ) >> 4 );
    // }
    
    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    return result;

}

Variable * ef936x_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

    switch( _mode ) {
        case BITMAP_MODE_40_COLUMN:
            return ef936x_image_converter_multicolor_mode_standard( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );
        case BITMAP_MODE_BITMAP_4:
            return ef936x_image_converter_multicolor_mode4( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );
        case BITMAP_MODE_80_COLUMN:
        case BITMAP_MODE_BITMAP_16:
            return ef936x_image_converter_multicolor_mode16( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );
        case BITMAP_MODE_PAGE:
            // WARNING_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );
            break;
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    
    return result;

}

static void ef936x_load_image_address_to_y( Environment * _environment, char * _source, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

    if ( !_sequence && !_frame ) {
        outline1("LDY #%s", _source );
    } else {

        outline1("LDY #%s", _source );

        if ( _sequence ) {
            outline0("LEAY 3,y" );
            if ( strlen(_sequence) == 0 ) {
            } else {
                outline1("LDB %s", _sequence );
                outline1("JSR fs%4.4xoffsetsequence", _frame_count * _frame_size );
            }
            if ( _frame ) {
                if ( strlen(_frame) == 0 ) {
                } else {
                    outline1("LDB %s", _frame );
                    outline1("JSR fs%4.4xoffsetframe", _frame_size );
                }
            }
        } else {
            if ( _frame ) {
                outline0("LEAY 3,y" );
                if ( strlen(_frame) == 0 ) {
                } else {
                    outline1("LDB %s", _frame );
                    outline1("JSR fs%4.4xoffsetframe", _frame_size );
                }
            }
        }

    }

}

static void ef936x_load_image_address_to_register( Environment * _environment, char * _register, Resource * _source, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

    if ( !_sequence && !_frame ) {
        if ( _source->isAddress ) {
            outline1("LDY %s", _source->realName );
        } else {
            outline1("LDY #%s", _source->realName );
        }
    } else {

        if ( _source->isAddress ) {
            outline1("LDY %s", _source->realName );
        } else {
            outline1("LDY #%s", _source->realName );
        }

        if ( _sequence ) {
            outline0("LEAY 3,y" );
            if ( strlen(_sequence) == 0 ) {
            } else {
                outline1("LDB %s", _sequence );
                outline1("JSR %soffsetsequence", _source->realName );
            }
            if ( _frame ) {
                if ( strlen(_frame) == 0 ) {
                } else {
                    outline1("LDB %s", _frame );
                    outline1("JSR %soffsetframe", _source->realName );
                }
            }
        } else {
            if ( _frame ) {
                outline0("LEAY 3,y" );
                if ( strlen(_frame) == 0 ) {
                } else {
                    outline1("LDB %s", _frame );
                    outline1("JSR %soffsetframe", _source->realName );
                }
            }
        }

    }

    if ( _register ) {
        outline1("STY %s", _register );
    }

}

void ef936x_put_image( Environment * _environment, Resource * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _flags ) {

    deploy_preferred( ef936xvars, src_hw_ef936x_vars_asm);
    deploy_preferred( putimage, src_hw_ef936x_put_image_asm );

    if ( _frame_size ) {
        ef936x_load_image_address_to_register( _environment, NULL, _image, _sequence, _frame, _frame_size, _frame_count );
    }

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    switch( VT_BITWIDTH( x->type ) ) {
        case 32:
            if ( _environment->currentMode == BITMAP_MODE_BITMAP_16 ) {
                if ( x->initializedByConstant ) {
                    outline1("LDB #$%2.2x", (unsigned char)(x->value&0xff) );
                } else {
                    outline1("LDB %s+3", x->realName );
                }
                outline0("STB <(IMAGEX+1)" );
            } else {
                if ( x->initializedByConstant ) {
                    outline1("LDD #$%4.4x", (unsigned int)(x->value&0xffff) );
                } else {
                    outline1("LDD %s+2", x->realName );
                }
                outline0("STD <IMAGEX" );
            }
            break;
        case 16:
            if ( _environment->currentMode == BITMAP_MODE_BITMAP_16 ) {
                if ( x->initializedByConstant ) {
                    outline1("LDB #$%2.2x", (unsigned char)(x->value&0xff) );
                } else {
                    outline1("LDB %s+1", x->realName );
                }
                outline0("STB <(IMAGEX+1)" );
            } else {
                if ( x->initializedByConstant ) {
                    outline1("LDD #$%4.4x", (unsigned int)(x->value&0xffff) );
                } else {
                    outline1("LDD %s", x->realName );
                }
                outline0("STD <IMAGEX" );
            }
            break;
        case 8:
            if ( x->initializedByConstant ) {
                outline1("LDB #$%2.2x", (unsigned char)(x->value&0xff) );
            } else {
                outline1("LDB %s", x->realName );
            }
            outline0("STB <(IMAGEX+1)" );
            break;
        default:
            CRITICAL_PUT_IMAGE_X_UNSUPPORTED( _x, DATATYPE_AS_STRING[x->type]);
    }

    switch( VT_BITWIDTH( y->type ) ) {
        case 32:
            if ( _environment->currentMode == BITMAP_MODE_BITMAP_16 ) {
                if ( x->initializedByConstant ) {
                    outline1("LDB #$%2.2x", (unsigned char)(y->value&0xff) );
                } else {
                    outline1("LDB %s+3", y->realName );
                }
                outline0("STB <(IMAGEY+1)" );
            } else {
                if ( x->initializedByConstant ) {
                    outline1("LDD #$%4.4x", (unsigned int)(y->value&0xffff) );
                } else {
                    outline1("LDD %s+2", y->realName );
                }
                outline0("STD <IMAGEY" );
            }
            break;
        case 16:
            if ( y->initializedByConstant ) {
                outline1("LDB #$%2.4x", y->value );
            } else {
                outline1("LDB %s+1", y->realName );
            }
            outline0("STB <(IMAGEY+1)" );
            break;
        case 8:
            if ( y->initializedByConstant ) {
                outline1("LDB #$%2.2x", y->value );
            } else {
                outline1("LDB %s", y->realName );
            }
            outline0("STB <(IMAGEY+1)" );
            break;
        default:
            CRITICAL_PUT_IMAGE_Y_UNSUPPORTED( _y, DATATYPE_AS_STRING[y->type]);
    }

    if( _flags && strcmp( _flags, "#PUTIMAGEFLAGS0000" ) != 0 ) {
        _environment->transparencyUsed = 1;
        outline1("LDD %s", _flags );
        outline0("STD <IMAGET" );
    }

    outline0("JSR PUTIMAGE");
    
}

Variable * ef936x_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    int size = ef936x_image_size( _environment, _width, _height, _mode );

    if ( ! size ) {
        CRITICAL_NEW_IMAGE_UNSUPPORTED_MODE( _mode );
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(new image)" );

    char * buffer = malloc ( size );
    memset( buffer, 0, size );

    *(buffer) = ( _width >> 8 ) & 0xff;
    *(buffer+1) = ( _width & 0xff );
    *(buffer+2) = _height;

    result->valueBuffer = buffer;
    result->size = size;
    
    return result;
    
}

Variable * ef936x_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

    int size = calculate_images_size( _environment, _frames, _width, _height, _mode );
    int frameSize = ef936x_image_size( _environment, _width, _height, _mode );

    if ( ! size ) {
        CRITICAL_NEW_IMAGES_UNSUPPORTED_MODE( _mode );
    }

    Variable * result = variable_temporary( _environment, VT_IMAGES, "(new images)" );

    char * buffer = malloc ( size );
    memset( buffer, 0, size );

    *(buffer) = _frames;
    *(buffer+1) = ( _width >> 8 ) & 0xff;
    *(buffer+2) = ( _width & 0xff );
    for( int i=0; i<_frames; ++i ) {
        *(buffer+3+(i*frameSize)) = ( ( _width >> 8 ) & 0xff );
        *(buffer+3+(i*frameSize)+1) = ( _width & 0xff );
        *(buffer+3+(i*frameSize)+2) = ( _height & 0xff );
    }

    result->valueBuffer = buffer;
    result->frameSize = frameSize;
    result->size = size;
    result->frameCount = _frames;

    return result;
    
}

Variable * ef936x_new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

    int size2 = calculate_sequence_size( _environment, _sequences, _frames, _width, _height, _mode );
    int size = calculate_images_size( _environment, _frames, _width, _height, _mode );
    int frameSize = ef936x_image_size( _environment, _width, _height, _mode );

    if ( ! size ) {
        CRITICAL_NEW_IMAGES_UNSUPPORTED_MODE( _mode );
    }

    Variable * result = variable_temporary( _environment, VT_SEQUENCE, "(new sequence)" );

    char * buffer = malloc ( size2 );
    memset( buffer, 0, size2 );

    *(buffer) = _frames;
    *(buffer+1) = _width;
    *(buffer+2) = _sequences;
    for( int i=0; i<(_frames*_sequences); ++i ) {
        *(buffer+3+(i*frameSize)) = ( _width & 0xff );
        *(buffer+3+(i*frameSize)+1) = ( ( _width >> 8 ) & 0xff );
        *(buffer+3+(i*frameSize)+2) = ( _height & 0xff );
    }

    result->valueBuffer = buffer;
    result->frameSize = frameSize;
    result->size = size;
    result->frameCount = _frames;

    return result;
    
}

void ef936x_get_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _palette ) {

    deploy_preferred( ef936xvars, src_hw_ef936x_vars_asm);
    deploy_preferred( getimage, src_hw_ef936x_get_image_asm );

    ef936x_load_image_address_to_y( _environment, _image, _sequence, _frame, _frame_size, _frame_count );

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    switch( VT_BITWIDTH( x->type ) ) {
        case 16:
            if ( _environment->currentMode == BITMAP_MODE_BITMAP_16 ) {
                if ( x->initializedByConstant ) {
                    outline1("LDB #$%2.2x", (unsigned char)(x->value&0xff) );
                } else {
                    outline1("LDB %s+1", x->realName );
                }
                outline0("STB <(IMAGEX+1)" );
            } else {
                if ( x->initializedByConstant ) {
                    outline1("LDD #$%4.4x", (unsigned int)(x->value&0xffff) );
                } else {
                    outline1("LDD %s", x->realName );
                }
                outline0("STD <IMAGEX" );
            }
            break;
        case 8:
            if ( x->initializedByConstant ) {
                outline1("LDB #$%2.2x", (unsigned char)(x->value&0xff) );
            } else {
                outline1("LDB %s", x->realName );
            }
            outline0("STB <(IMAGEX+1)" );
            break;
        default:
            CRITICAL_PUT_IMAGE_X_UNSUPPORTED( _x, DATATYPE_AS_STRING[x->type]);
    }

    switch( VT_BITWIDTH( y->type ) ) {
        case 16:
            if ( y->initializedByConstant ) {
                outline1("LDB #$%2.42", y->value );
            } else {
                outline1("LDB %s+1", y->realName );
            }
            outline0("STB <(IMAGEY+1)" );
            break;
        case 8:
            if ( y->initializedByConstant ) {
                outline1("LDB #$%2.2x", y->value );
            } else {
                outline1("LDB %s", y->realName );
            }
            outline0("STB <(IMAGEY+1)" );
            break;
        default:
            CRITICAL_PUT_IMAGE_X_UNSUPPORTED( _y, DATATYPE_AS_STRING[y->type]);
    }

    outline1("LDA #$%2.2x", _palette );
    outline0("STA <IMAGET" );

    outline0("JSR GETIMAGE");
    
}

void ef936x_scroll( Environment * _environment, int _dx, int _dy ) {

    deploy_preferred( ef936xvars, src_hw_ef936x_vars_asm);
    deploy( scroll, src_hw_ef936x_scroll_asm);
    deploy( textHScroll, src_hw_ef936x_hscroll_text_asm );
    deploy( vScrollText, src_hw_ef936x_vscroll_text_asm );

    outline1("LDA #$%2.2x", (unsigned char)(_dx&0xff) );
    outline0("STA <MATHPTR0" );
    outline1("LDA #$%2.2x", (unsigned char)(_dy&0xff) );
    outline0("STA <MATHPTR1" );
    outline0("JSR SCROLL");


}

void ef936x_put_tile( Environment * _environment, char * _tile, char * _x, char * _y ) {

}

void ef936x_move_tiles( Environment * _environment, char * _tile, char * _x, char * _y ) {

}

void ef936x_put_tiles( Environment * _environment, char * _tile, char * _x, char * _y, char *_w, char *_h ) {


}

void ef936x_tile_at( Environment * _environment, char * _x, char * _y, char * _result ) {

}

void ef936x_use_tileset( Environment * _environment, char * _tileset ) {

}

Variable * ef936x_get_raster_line( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_WORD, "(raster line)" );

    variable_store( _environment, result->name, 0 );

    return result;
    
}

void ef936x_calculate_sequence_frame_offset_regy( Environment * _environment, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

    if ( _sequence ) {
        outline0("LEAY 3, Y" );
        if ( strlen(_sequence) == 0 ) {
        } else {

            Variable * sequence = variable_retrieve( _environment, _sequence );

            if ( sequence->initializedByConstant ) {
                outline1("LDB #$%2.2x", sequence->value );
            } else {
                outline1("LDB %s", sequence->realName );
            }

            outline1("JSR fs%4.4xoffsetsequence", _frame_count * _frame_size );
        }
        if ( _frame ) {
            if ( strlen(_frame) == 0 ) {
            } else {

                Variable * frame = variable_retrieve( _environment, _frame );

                if ( frame->initializedByConstant ) {
                    outline1("LDB #$%2.2x", frame->value );
                } else {
                    outline1("LDB %s", frame->realName );
                }

                outline1("JSR fs%4.4xoffsetframe", _frame_size );
            }
        }
    } else {
        if ( _frame ) {
            outline0("LEAY 3, Y" );
            if ( strlen(_frame) == 0 ) {
            } else {
                Variable * frame = variable_retrieve( _environment, _frame );

                if ( frame->initializedByConstant ) {
                    outline1("LDB #$%2.2x", frame->value );
                } else {
                    outline1("LDB %s", frame->realName );
                }

                outline1("JSR fs%4.4xoffsetframe", _frame_size );
            }
        }
    }

}

void ef936x_calculate_sequence_frame_offset( Environment * _environment, char * _offset, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

    if ( _sequence ) {
        outline0("LDY #$3" );
        if ( strlen(_sequence) == 0 ) {
        } else {

            outline1("LDB %s", _sequence );
            outline1("JSR fs%4.4xoffsetsequence", _frame_count * _frame_size );
        }
        if ( _frame ) {
            if ( strlen(_frame) == 0 ) {
            } else {
                outline1("LDB %s", _frame );
                outline1("JSR fs%4.4xoffsetframe", _frame_size );
            }
        }
    } else {
        if ( _frame ) {
            outline0("LDY #$3" );
            if ( strlen(_frame) == 0 ) {
            } else {
                outline1("LDB %s", _frame );
                outline1("JSR fs%4.4xoffsetframe", _frame_size );
            }
        } else {
            outline0("LDY #$0" );
        }
    }

    if ( _offset ) {
        outline1("STY %s", _offset );
    }

}

void ef936x_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    deploy_preferred( ef936xvars, src_hw_ef936x_vars_asm);
    deploy( blitimage, src_hw_ef936x_blit_image_asm );

    if ( _source_count > 2 ) {
        CRITICAL_BLIT_TOO_MUCH_SOURCES( );
    }

    MAKE_LABEL

    outhead1("blitimage%s", label);

    outline1("LDY #%s", _blit );
    outline0("STY BLITIMAGEBLITADDR" );

    if ( _source_count > 0 ) {
        Resource resource;
        resource.realName = strdup( _sources[0] );
        resource.type = VT_IMAGE;
        ef936x_load_image_address_to_register( _environment, "BLITTMPPTR", &resource, _sequence, _frame, _frame_size, _frame_count );
    } else {
        outline0( "LDY #0" );
        outline0( "STY BLITTMPPTR" );
    }

    if ( _source_count > 1 ) {
        Resource resource;
        resource.realName = strdup( _sources[1] );
        resource.type = VT_IMAGE;
        ef936x_load_image_address_to_register( _environment, "BLITTMPPTR2", &resource, _sequence, _frame, _frame_size, _frame_count );
    } else {
        outline0( "LDY #0" );
        outline0( "STY BLITTMPPTR2" );
    }

    outline1("LDD %s", _x );
    outline0("STD <IMAGEX" );
    outline1("LDD %s", _y );
    outline0("STD <IMAGEY" );

    outline1("LDA #$%2.2x", ( _flags & 0xff ) );
    outline0("STA <IMAGEF" );
    outline1("LDA #$%2.2x", ( (_flags>>8) & 0xff ) );
    outline0("STA <IMAGET" );

    outline0("JSR BLITIMAGE");
    
}

void ef936x_slice_image( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination ) {

}

int ef936x_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette ) {

    int paletteColorCount = rgbi_extract_palette(_environment, _data, _width, _height, _depth, _palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    memcpy( _palette, palette_match( _palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) ), paletteColorCount * sizeof( RGBi ) );

    int uniquePaletteCount = 0;

    memcpy( _palette, palette_remove_duplicates( _palette, paletteColorCount, &uniquePaletteCount ), paletteColorCount * sizeof( RGBi ) );

    return uniquePaletteCount;

}

void ef936x_flip_image( Environment * _environment, Resource * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _direction ) {

    deploy_preferred( ef936xvars, src_hw_ef936x_vars_asm);

    if ( strcmp( _direction, "#FLIPIMAGEDIRECTION0001" ) == 0 || strcmp( _direction, "#FLIPIMAGEDIRECTION0003" ) == 0 ) {
        ef936x_load_image_address_to_register( _environment, NULL, _image, _sequence, _frame, _frame_size, _frame_count );
        deploy( flipimagex, src_hw_ef936x_flip_image_x_asm );
        if ( _image->isAddress && _image->bankNumber != -1 ) {
            outline0("ORCC #$50");
            #if defined(__to8__)
                outline0("LEAY $A000,Y");
            #else
                outline0("LEAY $6000,Y");
            #endif
            bank_set( _environment, _image->bankNumber );
        }
        outline0("JSR FLIPIMAGEX");
        if ( _image->isAddress && _image->bankNumber != -1 ) {
            bank_set( _environment, 0x07 );
            outline0("ANDCC #$AF");
        }
    } else {
        
        MAKE_LABEL

        ef936x_load_image_address_to_register( _environment, NULL, _image, _sequence, _frame, _frame_size, _frame_count );
        deploy( flipimagex, src_hw_ef936x_flip_image_x_asm );
        outline1("LDA %s", _direction );
        outline1("ANDA #$%2.2x", FLAG_FLIP_X );
        outline1("BEQ %s", label );
        if ( _image->isAddress && _image->bankNumber != -1 ) {
            outline0("ORCC #$50");
            #if defined(__to8__)
                outline0("LEAY $A000,Y");
            #else
                outline0("LEAY $6000,Y");
            #endif
            bank_set( _environment, _image->bankNumber );
        }
        outline0("JSR FLIPIMAGEX");
        if ( _image->isAddress && _image->bankNumber != -1 ) {
            bank_set( _environment, 0x07 );
            outline0("ANDCC #$AF");
        }
        outhead1("%s", label );

    }
    
    if ( strcmp( _direction, "#FLIPIMAGEDIRECTION0002" ) == 0 || strcmp( _direction, "#FLIPIMAGEDIRECTION0003" ) == 0 ) {
        ef936x_load_image_address_to_register( _environment, NULL, _image, _sequence, _frame, _frame_size, _frame_count );
        deploy( flipimagey, src_hw_ef936x_flip_image_y_asm );
        if ( _image->isAddress && _image->bankNumber != -1 ) {
            outline0("ORCC #$50");
            #if defined(__to8__)
                outline0("LEAY $A000,Y");
            #else
                outline0("LEAY $6000,Y");
            #endif
            bank_set( _environment, _image->bankNumber );
        }
        outline0("JSR FLIPIMAGEY");
        if ( _image->isAddress && _image->bankNumber != -1 ) {
            bank_set( _environment, 0x07 );
            outline0("ANDCC #$AF");
        }
    } else {
        
        MAKE_LABEL

        ef936x_load_image_address_to_register( _environment, NULL, _image, _sequence, _frame, _frame_size, _frame_count );
        deploy( flipimagey, src_hw_ef936x_flip_image_y_asm );
        outline1("LDA %s", _direction );
        outline1("ANDA #$%2.2x", FLAG_FLIP_Y );
        outline1("BEQ %s", label );
        if ( _image->isAddress && _image->bankNumber != -1 ) {
            outline0("ORCC #$50");
            #if defined(__to8__)
                outline0("LEAY $A000,Y");
            #else
                outline0("LEAY $6000,Y");
            #endif
            bank_set( _environment, _image->bankNumber );
        }
        outline0("JSR FLIPIMAGEY");
        if ( _image->isAddress && _image->bankNumber != -1 ) {
            bank_set( _environment, 0x07 );
            outline0("ANDCC #$AF");
        }
        outhead1("%s", label );

    }

}

void ef936x_fade_out( Environment * _environment, char * _period ) {

    deploy( fade, src_hw_ef936x_fade_asm );

    if ( _period ) {
        outline1( "LDD %s", _period );
    } else {
        outline0( "LDD #4" );
    }
    outline0( "STD FADEOUTPERIOD+1" );
    outline0("JSR FADEOUT");

}

void ef936x_fade_in( Environment * _environment, char * _period  ) {

    deploy( fade, src_hw_ef936x_fade_asm );

    if ( _period ) {
        outline1( "LDD %s", _period );
    } else {
        outline0( "LDD #4" );
    }
    outline0( "STD FADEINPERIOD+1" );
    outline0("JSR FADEIN");

}

void ef936x_fade_in_color( Environment * _environment, int _index, int _background_color ) {

    outline1("LDD #$%4.4x", _background_color );
    outline1("STD COMMONPALETTE+$%2.2x", ( _index & 0x0f ) * 2 );

}

void ef936x_fade_in_color_vars( Environment * _environment, char * _index, char * _background_color ) {

    outline0("LDX #COMMONPALETTE" );
    outline1("LDB %s", _index );
    outline0("LSLB" );
    outline0("ABX" );
    outline1("LDD %s", _background_color );
    outline0("STD ,X" );

}

void ef936x_fade_in_color_semivars( Environment * _environment, int _index, char * _background_color ) {

    outline1("LDD %s", _background_color );
    outline1("STD COMMONPALETTE+$%2.2x", ( _index & 0x0f ) * 2 );

}

#endif