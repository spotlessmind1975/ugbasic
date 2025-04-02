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

#if defined(__vz200__)

#include "../ugbc.h"
#include <math.h>

static RGBi SYSTEM_PALETTE_ALTERNATE[][4] = {
        {
            { 0x00, 0xcc, 0x55, 0xff, 0, "GREEN" },
            { 0xee, 0xee, 0x77, 0xff, 1, "YELLOW" },
            { 0x00, 0x00, 0xaa, 0xff, 2, "BLUE" },
            { 0x88, 0x00, 0x00, 0xff, 3, "RED" }
        },
        {
            { 0x00, 0x00, 0x00, 0xff, 0, "BLACK" },        
            { 0xf0, 0xf0, 0xf0, 0xff, 5, "BUFF" },
            { 0xaa, 0xff, 0xe6, 0xff, 6, "CYAN" },
            { 0xcc, 0x44, 0xcc, 0xff, 7, "MAGENTA" } //,
            // { 0xa1, 0x68, 0x3c, 0xff, 8, "ORANGE" }            
        }
};

static RGBi * SYSTEM_PALETTE = &SYSTEM_PALETTE_ALTERNATE[0][0];

static RGBi * commonPalette;
int lastUsedSlotInCommonPalette = 0;

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

extern char DATATYPE_AS_STRING[][16];

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
void c6847z_collision( Environment * _environment, char * _sprite_mask, char * _result ) {
    
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
void c6847z_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

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
void c6847z_border_color( Environment * _environment, char * _border_color ) {

    // MAKE_LABEL

    // outline1( "LDA %s", _border_color );
    // outline0( "CMPA 4" );
    // outline1( "BCs %scss0", label );
    // outhead1( "%scss1", label );
    // CSS_SET;
    // outline1( "JMP %sdone", label );
    // outhead1( "%scss0", label );
    // CSS_CLR;
    // outhead1( "%sdone", label );

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
void c6847z_background_color( Environment * _environment, char * _index, char * _background_color ) {

    // MAKE_LABEL

    // (void) _index;

    // outline1( "LDA %s", _background_color );
    // outline0( "CMPA 4" );
    // outline1( "BCs %scss0", label );
    // outhead1( "%scss1", label );
    // CSS_SET;
    // outline1( "JMP %sdone", label );
    // outhead1( "%scss0", label );
    // CSS_CLR;
    // outhead1( "%sdone", label );

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
void c6847z_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {

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
void c6847z_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

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
void c6847z_next_raster( Environment * _environment ) {

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
void c6847z_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

void c6847z_bank_select( Environment * _environment, int _bank ) {

}

#define SET_VIDEOAT_400     SAM_F0_CLR; SAM_F1_CLR; SAM_F2_CLR; SAM_F3_CLR; SAM_F4_CLR; SAM_F5_CLR; SAM_F6_CLR; SAM_F1_SET;
#define SET_VIDEOAT_600     SAM_F0_CLR; SAM_F1_CLR; SAM_F2_CLR; SAM_F3_CLR; SAM_F4_CLR; SAM_F5_CLR; SAM_F6_CLR; SAM_F0_SET; SAM_F1_SET; 
#define SET_VIDEOAT_C00     SAM_F0_CLR; SAM_F1_CLR; SAM_F2_CLR; SAM_F3_CLR; SAM_F4_CLR; SAM_F5_CLR; SAM_F6_CLR; SAM_F1_SET; SAM_F2_SET; 

void console_calculate( Environment * _environment ) {

    // int consoleSA = 0x0c00;
    // int consoleWB = _environment->activeConsole.width;
    // int consoleHB = _environment->activeConsole.height * 8;

    // switch( _environment->currentMode ) {
    //     case TILEMAP_MODE_INTERNAL:         // Alphanumeric Internal	32 × 16	2	512
    //     case TILEMAP_MODE_EXTERNAL:         // Alphanumeric External	32 × 16	2	512
    //     case TILEMAP_MODE_SEMIGRAPHICS4:    // Semigraphics 4	        64 × 32	8	512
    //     case TILEMAP_MODE_SEMIGRAPHICS6:    // Semigraphics 6	        64 × 48	4	512
    //     case TILEMAP_MODE_SEMIGRAPHICS8:    // Semigraphics 8	        64 × 64	2	512
    //     case TILEMAP_MODE_SEMIGRAPHICS12:    // Semigraphics 6	        64 × 96 1	3072
    //     case TILEMAP_MODE_SEMIGRAPHICS24:    // Semigraphics 6	        64 × 96 1	3072
    //         break;
    //     case BITMAP_MODE_COLOR1:            // Color Graphics 1	64 × 64	4	1024
    //         consoleSA += ( _environment->activeConsole.y1 << 7 ) + ( _environment->activeConsole.x1 << 1 );
    //         consoleWB = _environment->activeConsole.width * 2;
    //         break;
    //     case BITMAP_MODE_RESOLUTION1:       // Resolution Graphics 1	128 × 64	1 + Black	1024
    //         consoleSA += ( _environment->activeConsole.y1 << 7 ) + ( _environment->activeConsole.x1 << 2 );
    //         break;
    //     case BITMAP_MODE_COLOR2:            // Color Graphics 2	128 × 64	4	2048
    //         consoleSA += ( _environment->activeConsole.y1 << 8 ) + ( _environment->activeConsole.x1 << 1 );
    //         consoleWB = _environment->activeConsole.width * 2;
    //         break;
    //     case BITMAP_MODE_RESOLUTION2:       // Resolution Graphics 2 128 × 96	1 + Black	1536
    //         consoleSA += ( _environment->activeConsole.y1 << 7 ) + ( _environment->activeConsole.x1 << 1 );
    //         break;
    //     case BITMAP_MODE_COLOR3:            // Color Graphics 3	128 × 96	4	3072
    //         consoleSA += ( _environment->activeConsole.y1 << 8 ) + ( _environment->activeConsole.x1 << 1 );
    //         consoleWB = _environment->activeConsole.width * 2;
    //         break;
    //     case BITMAP_MODE_RESOLUTION3:       // Resolution Graphics 3	128 × 192	1 + Black	3072
    //         consoleSA += ( _environment->activeConsole.y1 << 7 ) + ( _environment->activeConsole.x1 << 2 );
    //         break;
    //     case BITMAP_MODE_COLOR6:            // Color Graphics 6	128 × 192	4	6144
    //         consoleSA += ( _environment->activeConsole.y1 << 8 ) + ( _environment->activeConsole.x1 << 1 );
    //         consoleWB = _environment->activeConsole.width * 2;
    //         break;
    //     case BITMAP_MODE_RESOLUTION6:       // Resolution Graphics 6	256 × 192	1 + Black	6144            break;
    //         consoleSA += ( _environment->activeConsole.y1 << 8 ) + ( _environment->activeConsole.x1 );
    //         consoleWB = _environment->activeConsole.width * 2;
    //         break;
    //     default:
    //         CRITICAL_SCREEN_UNSUPPORTED( _environment->currentMode );
    // }

    // cpu_store_16bit( _environment, "CONSOLESA", consoleSA );
    // cpu_store_8bit( _environment, "CONSOLEWB", consoleWB );
    // cpu_store_8bit( _environment, "CONSOLEHB", consoleHB );

}

void console_calculate_vars( Environment * _environment ) {

    // outline0( "JSR CONSOLECALCULATE" );

}


int c6847z_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {
    // deploy( c6847vars, src_hw_6847_vars_asm );

    _environment->fontWidth = 8;
    _environment->fontHeight = 8;
    _environment->screenShades = 4;
    _environment->screenTiles = 128;
    switch( _screen_mode->id ) {
        // ALPHANUMERIC DISPLAY MODES – All alphanumeric modes occupy an 8 x 12 
        // dot character matrix box and there are 32 x 16 character boxes per TV frame. 
        // Each horizontal dot (dot-clock) corresponds to one half the period duration of
        // the 3.58 MHz clock and each vertical dot is one scan line. One of two colors 
        // for the lighted dots may be selected by the color set select pin (pin 39). 
        // An internal ROM will generate 64 ASCII display characters in a standard 5 x 7 box. 
        // Six bits of the eight-bit data word are used for the ASCII character generator 
        // and the two bits not used are used to implement inverse video and mode 
        // switching to semigraphics – 4, – 8, – 12, or – 24.
        case TILEMAP_MODE_INTERNAL:         // Alphanumeric Internal	32 × 16	2	512
            _environment->screenWidth = 32*8;
            _environment->screenHeight = 16*12;
            _environment->screenTilesWidth = 32;
            _environment->screenTilesHeight = 16;
            _environment->screenColors = 4;
            // Internal alphanumeric 0 X X 0 0 0 0 32x16 ( 5x7 pixel ch)
            outline0("LD HL, $6800");
            outline0("LD A, (HL)");
            outline0("AND $F7");
            outline0("LD (HL), A");
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 31 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 15 );
            cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 32*16 );
            break;
        // The 128 x 64 Color Graphics mode generates a display matrix 128 
        // elements wide by 64 elements high. Each element may be one of four 
        // colors. A 2K x 8 display memory is required. Each pixel equals
        // two dot-clocks by three scan lines.
        case BITMAP_MODE_COLOR2:            // Color Graphics 2	128 × 64	4	2048
            _environment->screenWidth = 128;
            _environment->screenHeight = 64;
            _environment->screenTilesWidth = _environment->screenWidth/_environment->fontWidth;
            _environment->screenTilesHeight = _environment->screenHeight/_environment->fontHeight;
            _environment->screenColors = 4;
            // Full graphic 2-C 1 0 1 0 0 1 0 128x64x4 $800(2048)
            outline0("LD HL, $6800");
            outline0("LD A, (HL)");
            outline0("OR $08");
            outline0("LD (HL), A");
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 127 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 63 );
            cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 2048 );
            cpu_store_8bit( _environment, "CURRENTSL", 128 / 4 );
            break;
    }

    _environment->consoleTilesWidth = _environment->screenTilesWidth;
    _environment->consoleTilesHeight = _environment->screenTilesHeight;

    cpu_store_16bit( _environment, "ORIGINX", 0 );
    cpu_store_16bit( _environment, "ORIGINY", 0 );
    cpu_store_16bit( _environment, "CURRENTWIDTH", _environment->screenWidth );
    cpu_store_16bit( _environment, "CURRENTHEIGHT", _environment->screenHeight );
    cpu_move_16bit( _environment, "CURRENTWIDTH", "RESOLUTIONX" );
    cpu_move_16bit( _environment, "CURRENTHEIGHT", "RESOLUTIONY" );
    cpu_store_8bit( _environment, "CURRENTTILES", _environment->screenTiles );
    cpu_store_8bit( _environment, "CURRENTTILESWIDTH", _environment->screenTilesWidth );
    cpu_store_8bit( _environment, "CURRENTTILESHEIGHT", _environment->screenTilesHeight );

    // console_init( _environment );

    // console_calculate( _environment );

    // console_calculate_vars( _environment );

    if (_environment->vestigialConfig.clsImplicit ) {
        c6847z_cls( _environment );
    }

}

void c6847z_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors, 8, 8 );

    if ( mode ) {

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 0 );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 0;

        c6847z_screen_mode_enable( _environment, mode );

    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void c6847z_bitmap_disable( Environment * _environment ) {    

}

void c6847z_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {

    // ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors, _tile_width, _tile_height );

    // if ( mode ) {

    //     _environment->currentMode = mode->id;
    //     _environment->currentTileMode = 1;

    //     cpu_store_8bit( _environment, "CURRENTMODE", mode->id );    
    //     cpu_store_8bit( _environment, "CURRENTTILEMODE", 1 );

    //     c6847z_screen_mode_enable( _environment, mode );


    // } else {
    //     WARNING_SCREEN_MODE( -1 );
    // }

}

void c6847z_bitmap_at( Environment * _environment, char * _address ) {

    // outline1("LDD %s", _address);
    // outline0("JSR C6847VIDEOSTARTATB" );

}

void c6847z_colormap_at( Environment * _environment, char * _address ) {    

}

void c6847z_textmap_at( Environment * _environment, char * _address ) {

    // outline1("LDD %s", _address);
    // outline0("JSR C6847VIDEOSTARTATT" );
    
}

void c6847z_pset_int( Environment * _environment, int _x, int _y, int *_c ) {

    deploy( plot, src_hw_6847z_plot_asm );
    
    outline1("LD A, 0x%2.2x", ( _y & 0xff ) );
    outline0("LD D, A");
    outline1("LD A, 0x%2.2x", ( _x & 0xff ) );
    outline0("LD E, A");
    outline1("LD A, 0x%2.2x", ( ( _x >> 8 ) & 0xff ) );
    outline0("LD (PLOTCPE), A");
    outline0("LD A, 1");
    outline0("CALL PLOT");

}

void c6847z_pset_vars( Environment * _environment, char *_x, char *_y, char *_c ) {

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    Variable * c;
    
    if ( _c ) {
        c = variable_retrieve_or_define( _environment, _c, VT_COLOR, 0 );
    } else {
        c = variable_retrieve( _environment, "PEN" );
    }

    deploy( plot, src_hw_6847z_plot_asm );
    
    outline1("LD A, (%s)", y->realName );
    outline0("LD D, A");
    outline1("LD A, (%s)", x->realName );
    outline0("LD E, A");
    outline1("LD A, (%s)", c->realName );
    outline0("LD (PLOTCPE), A");
    outline0("LD A, 1");
    outline0("CALL PLOT");

}
void c6847z_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result ) {

    // Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    // Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    // Variable * result = variable_retrieve_or_define( _environment, _result, VT_BYTE, 0 );

    // deploy( c6847vars, src_hw_6847_vars_asm );
    // deploy_preferred( plot, src_hw_6847_plot_asm );

    // switch( VT_BITWIDTH( x->type ) ) {
    //     case 32:
    //         if ( x->initializedByConstant ) {
    //             outline1("LDB #$%2.2x", (unsigned char)(x->value&0xff) );
    //         } else {
    //             outline1("LDB %s+3", x->realName );
    //         }
    //         outline0("STB <PLOTX" );
    //         break;
    //     case 16:
    //         if ( x->initializedByConstant ) {
    //             outline1("LDB #$%2.2x", (unsigned char)(x->value&0xff) );
    //         } else {
    //             outline1("LDB %s+1", x->realName );
    //         }
    //         outline0("STB <PLOTX" );
    //         break;
    //     case 8:
    //         if ( x->initializedByConstant ) {
    //             outline1("LDB #$%2.2x", (unsigned char)(x->value&0xff) );
    //         } else {
    //             outline1("LDB %s", x->realName );
    //         }
    //         outline0("STB <PLOTX" );
    //         break;
    //     default:
    //         CRITICAL_PLOT_X_UNSUPPORTED( _x, DATATYPE_AS_STRING[x->type]);
    // }

    // switch( VT_BITWIDTH( y->type ) ) {
    //     case 32:
    //         if ( y->initializedByConstant ) {
    //             outline1("LDB #$%2.2x", (unsigned char)(y->value&0xff) );
    //         } else {
    //             outline1("LDB %s+3", y->realName );
    //         }
    //         outline0("STB <PLOTY" );
    //         break;
    //     case 16:
    //         if ( y->initializedByConstant ) {
    //             outline1("LDB #$%2.2x", (unsigned char)(y->value&0xff) );
    //         } else {
    //             outline1("LDB %s+1", y->realName );
    //         }
    //         outline0("STB <PLOTY" );
    //         break;
    //     case 8:
    //         if ( y->initializedByConstant ) {
    //             outline1("LDB #$%2.2x", (unsigned char)(y->value&0xff) );
    //         } else {
    //             outline1("LDB %s", y->realName );
    //         }
    //         outline0("STB <PLOTY" );
    //         break;
    //     default:
    //         CRITICAL_PLOT_Y_UNSUPPORTED( _y, DATATYPE_AS_STRING[y->type]);
    // }

    // outline0("LDB #3");
    // outline0("STB <PLOTM");
    // outline0("JSR PLOT");
    // outline0("LDA <PLOTM");
    // outline1("STA %s", result->realName );    

}

void c6847z_screen_on( Environment * _environment ) {

}

void c6847z_screen_off( Environment * _environment ) {

}

void c6847z_screen_rows( Environment * _environment, char * _rows ) {

}

void c6847z_screen_columns( Environment * _environment, char * _columns ) {

}

void c6847z_sprite_data_from( Environment * _environment, char * _sprite, char * _address ) {

}

void c6847z_sprite_data_set( Environment * _environment, char * _sprite, char * _address ) {

}

void c6847z_sprite_enable( Environment * _environment, char * _sprite ) {

}

void c6847z_sprite_disable( Environment * _environment, char * _sprite ) {

}

void c6847z_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

}

void c6847z_sprite_priority( Environment * _environment, char * _sprite, char * _priority ) {

}

void c6847z_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

}

void c6847z_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

}

void c6847z_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

}

void c6847z_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

}

void c6847z_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void c6847z_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void c6847z_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

}

void c6847z_tiles_at( Environment * _environment, char * _address ) {

}

void c6847z_vertical_scroll( Environment * _environment, char * _displacement ) {

}

void c6847z_horizontal_scroll( Environment * _environment, char * _displacement ) {

}

void c6847z_get_width( Environment * _environment, char *_result ) {

    // outline0("LDX CURRENTWIDTH" );
    // outline1("STX %s", _result );

}

void c6847z_tiles_get( Environment * _environment, char *_result ) {

    // outline0("LDA CURRENTTILES" );
    // outline1("STA %s", _result );

}

void c6847z_get_height( Environment * _environment, char *_result ) {

    // outline0("LDX CURRENTHEIGHT" );
    // outline1("STX %s", _result );

}

void c6847z_cls( Environment * _environment ) {

    if ( _environment->currentMode < 7 ) {
        // deploy( clsText, src_hw_6847z_cls_text_asm );
        // outline0("JSR CLST");
    } else {
        deploy( clsGraphic, src_hw_6847z_cls_graphic_asm );
        outline0("CALL CLSG");
    }

}

void c6847z_scroll_text( Environment * _environment, int _direction, int _overlap ) {

    // if ( _environment->currentMode < 7 ) {
    //     deploy_preferred( vScrollText, src_hw_6847_vscroll_text_asm );
    //     outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    //     outline0("STA <DIRECTION" );
    //     outline1("LDA #$%2.2x", ( _overlap & 0xff ) );
    //     outline0("STA <PORT" );
    //     outline0("JSR VSCROLLT");
    // } else {
    //     deploy_preferred( vScroll, src_hw_6847_vscroll_graphic_asm );
    //     outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    //     outline0("STA <DIRECTION" );
    //     outline1("LDA #$%2.2x", ( _overlap & 0xff ) );
    //     outline0("STA <PORT" );
    //     outline0("JSR VSCROLLG");
    // }

}

void c6847z_text( Environment * _environment, char * _text, char * _text_size, int _raw ) {

    // deploy( vScrollTextUp, src_hw_6847z_vscroll_text_up_asm );
    deploy( textEncodedAt, src_hw_6847z_text_at_asm );

    outline1("LD DE, (%s)", _text);
    outline1("LD A, (%s)", _text_size);
    outline0("LD C, A");

    if ( _raw ) {
        if ( _environment->currentMode < 7 ) {
            // deploy( clsText, src_hw_6847_cls_text_asm );
            // deploy_preferred( vScrollText, src_hw_6847_vscroll_text_asm );
            // deploy( textEncodedAtTextRaw, src_hw_6847_text_at_text_raw_asm );
            // outline0("JSR TEXTATTILEMODERAW");
        } else {
            // deploy( clsGraphic, src_hw_6847_cls_graphic_asm );
            // deploy( vScroll, src_hw_6847_vscroll_graphic_asm );
            // deploy( textEncodedAtGraphicRaw, src_hw_6847_text_at_graphic_raw_asm );
            // outline0("JSR TEXTATBITMAPMODERAW");
        }
    } else {
        if ( _environment->currentMode < 7 ) {
            // deploy( clsText, src_hw_6847_cls_text_asm );
            // deploy_preferred( vScrollText, src_hw_6847_vscroll_text_asm );
            deploy( textEncodedAtText, src_hw_6847z_text_at_text_asm );
            outline0("CALL TEXTATTILEMODE");
        } else {
            // deploy( clsGraphic, src_hw_6847_cls_graphic_asm );
            // deploy( vScroll, src_hw_6847_vscroll_graphic_asm );
            // deploy( textEncodedAtGraphic, src_hw_6847_text_at_graphic_asm );
            // outline0("JSR TEXTATBITMAPMODE");
        }
    }

}

void c6847z_initialization( Environment * _environment ) {

    // deploy( c6847vars, src_hw_6847_vars_asm );
    deploy( c6847startup, src_hw_6847z_startup_asm );

    variable_import( _environment, "CURRENTMODE", VT_BYTE, 0 );
    variable_global( _environment, "CURRENTMODE" );
    variable_import( _environment, "CURRENTTILEMODE", VT_BYTE, 1 );
    variable_global( _environment, "CURRENTTILEMODE" );

    variable_import( _environment, "CURRENTWIDTH", VT_POSITION, 256 );
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION, 128  );
    variable_global( _environment, "CURRENTHEIGHT" );
    variable_import( _environment, "CURRENTTILESWIDTH", VT_SBYTE, 32 );
    variable_global( _environment, "CURRENTTILESWIDTH" );
    variable_import( _environment, "CURRENTTILESHEIGHT", VT_SBYTE, 16 );
    variable_global( _environment, "CURRENTTILESHEIGHT" );
    variable_import( _environment, "CURRENTTILES", VT_BYTE, 255 );
    variable_global( _environment, "CURRENTTILES" );
    variable_import( _environment, "FONTWIDTH", VT_BYTE, 8 );
    variable_global( _environment, "FONTWIDTH" );
    variable_import( _environment, "FONTHEIGHT", VT_BYTE, 8 );
    variable_global( _environment, "FONTHEIGHT" );
    variable_import( _environment, "CURRENTFRAMESIZE", VT_WORD, 0 );
    variable_global( _environment, "CURRENTFRAMESIZE" );

    SCREEN_MODE_DEFINE( TILEMAP_MODE_INTERNAL, 0, 32, 16, 2, 8, 8, "Alphanumeric Internal");
    SCREEN_MODE_DEFINE( BITMAP_MODE_COLOR2, 1, 128, 64, 4, 8, 8, "Color Graphics 2" );

    outline0("CALL C6847ZSTARTUP");

    variable_import( _environment, "XGR", VT_POSITION, 0 );
    variable_global( _environment, "XGR" );
    variable_import( _environment, "YGR", VT_POSITION, 0 );
    variable_global( _environment, "YGR" );
    // variable_import( _environment, "LINE", VT_WORD, (unsigned short)(0xffff) );
    // variable_global( _environment, "LINE" );
    variable_import( _environment, "TABCOUNT", VT_BYTE, 4 );
    variable_global( _environment, "TABCOUNT" );
    variable_import( _environment, "TABSTODRAW", VT_BYTE, 0 );
    variable_global( _environment, "TABSTODRAW" );

    variable_import( _environment, "PLOTAMA", VT_BYTE, 0 );
    variable_global( _environment, "PLOTAMA" );
    variable_import( _environment, "PLOTOMA", VT_BYTE, 0 );
    variable_global( _environment, "PLOTOMA" );
    variable_import( _environment, "PLOTNB", VT_BYTE, 0 );
    variable_global( _environment, "PLOTNB" );
    variable_import( _environment, "PLOTND", VT_BYTE, 0 );
    variable_global( _environment, "PLOTND" );
    variable_import( _environment, "PLOTCPE", VT_BYTE, 0 );
    variable_global( _environment, "PLOTCPE" );

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

    _environment->fontConfig.schema = FONT_SCHEMA_ASCII;

    font_descriptors_init( _environment, 0 );

    _environment->fontWidth = 8;
    _environment->fontHeight = 8;
    _environment->screenTilesWidth = 32;
    _environment->screenTilesHeight = 16;
    _environment->consoleTilesWidth = 32;
    _environment->consoleTilesHeight = 16;
    _environment->screenTiles = 128;
    _environment->screenWidth = _environment->screenTilesWidth*_environment->fontWidth;
    _environment->screenHeight = _environment->screenTilesHeight*_environment->fontHeight;
    _environment->screenShades = 4;
    _environment->screenColors = 4;

    console_init( _environment );
    
    if ( _environment->vestigialConfig.clsImplicit ) {
        c6847z_cls( _environment );
    }

}

void c6847z_finalization( Environment * _environment ) {

    // if (_environment->vestigialConfig.clsImplicit ) {
    //     deploy( clsText, src_hw_6847_cls_text_asm );
    // }
    
}

void c6847z_hscroll_line( Environment * _environment, int _direction, int _overlap ) {

    // deploy_preferred( textHScroll, src_hw_6847_hscroll_text_asm );

    // Variable * y = variable_retrieve( _environment, "YCURSYS" );
    // outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    // outline0("STA <DIRECTION" );
    // outline1("LDA #$%2.2x", ( _overlap & 0xff ) );
    // outline0("STA <PORT" );
    // outline1("LDA %s", y->realName );
    // outline0("STA <CLINEY");

    // outline0("JSR HSCROLLLT");    

}

void c6847z_hscroll_screen( Environment * _environment, int _direction, int _overlap ) {

    // deploy_preferred( textHScroll, src_hw_6847_hscroll_text_asm );

    // outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    // outline0("STA <DIRECTION" );
    // outline1("LDA #$%2.2x", ( _overlap & 0xff ) );
    // outline0("STA <PORT" );

    // outline0("JSR HSCROLLST");    

}

void c6847z_back( Environment * _environment ) {

}

void c6847z_cline( Environment * _environment, char * _characters ) {

    // Variable * x = variable_retrieve( _environment, "XCURSYS" );
    // Variable * y = variable_retrieve( _environment, "YCURSYS" );

    // if ( _characters ) {
    //     outline1("LDD %s", _characters);
    // } else {
    //     outline0("LDD #0");
    // }
    // outline0("STB <CHARACTERS");
    // outline1("LDA %s", x->realName );
    // outline0("STA <CLINEX" );
    // outline1("LDA %s", y->realName );
    // outline0("STA <CLINEY");

    // if ( _environment->currentMode < 7 ) {
    //     deploy( textCline, src_hw_6847_cline_text_asm );
    //     outline0("JSR CLINE");
    // } else {
    //     deploy( textClineGraphic, src_hw_6847_cline_graphic_asm );
    //     outline0("JSR CLINEG");
    // }

}

int c6847z_image_size( Environment * _environment, int _width, int _height, int _mode ) {

    // switch( _mode ) {
    //     case TILEMAP_MODE_INTERNAL:         // Alphanumeric Internal	32 × 16	2	512
    //     case TILEMAP_MODE_EXTERNAL:         // Alphanumeric External	32 × 16	2	512
    //     case TILEMAP_MODE_SEMIGRAPHICS4:    // Semigraphics 4	        64 × 32	8	512
    //     case TILEMAP_MODE_SEMIGRAPHICS6:    // Semigraphics 6	        64 × 48	4	512
    //     case TILEMAP_MODE_SEMIGRAPHICS8:    // Semigraphics 8	        64 × 64	2	512
    //     case TILEMAP_MODE_SEMIGRAPHICS12:    // Semigraphics 6	        64 × 96 1	3072
    //     case TILEMAP_MODE_SEMIGRAPHICS24:    // Semigraphics 6	        64 × 96 1	3072
    //         break;
    //     case BITMAP_MODE_COLOR1:            // Color Graphics 1	64 × 64	4	1024
    //     case BITMAP_MODE_COLOR2:            // Color Graphics 2	128 × 64	4	2048
    //     case BITMAP_MODE_COLOR3:            // Color Graphics 3	128 × 96	4	3072
    //     case BITMAP_MODE_COLOR6:            // Color Graphics 6	128 × 192	4	6144
    //         return 2 + ( ( _width >> 2 ) * _height );
    //     case BITMAP_MODE_RESOLUTION1:       // Resolution Graphics 1	128 × 64	1 + Black	1024
    //     case BITMAP_MODE_RESOLUTION2:       // Resolution Graphics 2 128 × 96	1 + Black	1536
    //     case BITMAP_MODE_RESOLUTION3:       // Resolution Graphics 3	128 × 192	1 + Black	3072
    //     case BITMAP_MODE_RESOLUTION6:       // Resolution Graphics 6	256 × 192	1 + Black	6144            break;
    //         return 2 + ( ( _width >> 3 ) * _height );

    // }

    // return 0;

}

static int calculate_images_size( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

    // switch( _mode ) {
    //     case TILEMAP_MODE_INTERNAL:         // Alphanumeric Internal	32 × 16	2	512
    //     case TILEMAP_MODE_EXTERNAL:         // Alphanumeric External	32 × 16	2	512
    //     case TILEMAP_MODE_SEMIGRAPHICS4:    // Semigraphics 4	        64 × 32	8	512
    //     case TILEMAP_MODE_SEMIGRAPHICS6:    // Semigraphics 6	        64 × 48	4	512
    //     case TILEMAP_MODE_SEMIGRAPHICS8:    // Semigraphics 8	        64 × 64	2	512
    //     case TILEMAP_MODE_SEMIGRAPHICS12:    // Semigraphics 6	        64 × 96 1	3072
    //     case TILEMAP_MODE_SEMIGRAPHICS24:    // Semigraphics 6	        64 × 96 1	3072
    //         break;
    //     case BITMAP_MODE_COLOR1:            // Color Graphics 1	64 × 64	4	1024
    //     case BITMAP_MODE_COLOR2:            // Color Graphics 2	128 × 64	4	2048
    //     case BITMAP_MODE_COLOR3:            // Color Graphics 3	128 × 96	4	3072
    //     case BITMAP_MODE_COLOR6:            // Color Graphics 6	128 × 192	4	6144
    //         return 3 + ( 2 + ( ( _width >> 2 ) * _height ) ) * _frames;
    //     case BITMAP_MODE_RESOLUTION1:       // Resolution Graphics 1	128 × 64	1 + Black	1024
    //     case BITMAP_MODE_RESOLUTION2:       // Resolution Graphics 2 128 × 96	1 + Black	1536
    //     case BITMAP_MODE_RESOLUTION3:       // Resolution Graphics 3	128 × 192	1 + Black	3072
    //     case BITMAP_MODE_RESOLUTION6:       // Resolution Graphics 6	256 × 192	1 + Black	6144            break;
    //         return 3 + ( 2 + ( ( _width >> 3 ) * _height ) ) * _frames;

    // }

    // return 0;

}

static int calculate_sequence_size( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

    // switch( _mode ) {
    //     case TILEMAP_MODE_INTERNAL:         // Alphanumeric Internal	32 × 16	2	512
    //     case TILEMAP_MODE_EXTERNAL:         // Alphanumeric External	32 × 16	2	512
    //     case TILEMAP_MODE_SEMIGRAPHICS4:    // Semigraphics 4	        64 × 32	8	512
    //     case TILEMAP_MODE_SEMIGRAPHICS6:    // Semigraphics 6	        64 × 48	4	512
    //     case TILEMAP_MODE_SEMIGRAPHICS8:    // Semigraphics 8	        64 × 64	2	512
    //     case TILEMAP_MODE_SEMIGRAPHICS12:    // Semigraphics 6	        64 × 96 1	3072
    //     case TILEMAP_MODE_SEMIGRAPHICS24:    // Semigraphics 6	        64 × 96 1	3072
    //         break;
    //     case BITMAP_MODE_COLOR1:            // Color Graphics 1	64 × 64	4	1024
    //     case BITMAP_MODE_COLOR2:            // Color Graphics 2	128 × 64	4	2048
    //     case BITMAP_MODE_COLOR3:            // Color Graphics 3	128 × 96	4	3072
    //     case BITMAP_MODE_COLOR6:            // Color Graphics 6	128 × 192	4	6144
    //         return 3 + ( ( 2 + ( ( _width >> 2 ) * _height ) ) * _frames ) * _sequences;
    //     case BITMAP_MODE_RESOLUTION1:       // Resolution Graphics 1	128 × 64	1 + Black	1024
    //     case BITMAP_MODE_RESOLUTION2:       // Resolution Graphics 2 128 × 96	1 + Black	1536
    //     case BITMAP_MODE_RESOLUTION3:       // Resolution Graphics 3	128 × 192	1 + Black	3072
    //     case BITMAP_MODE_RESOLUTION6:       // Resolution Graphics 6	256 × 192	1 + Black	6144            break;
    //         return 3 + ( ( 2 + ( ( _width >> 3 ) * _height ) ) * _frames ) * _sequences;

    // }

    // return 0;

}

static Variable * c6847z_image_converter_bitmap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    // // ignored on bitmap mode
    // (void)!_transparent_color;

    // RGBi white = { 0xff, 0xff, 0xff, 0xff };
    // RGBi black = { 0x00, 0x00, 0x00, 0xff };

    // // ignored on bitmap mode
    // (void)!_transparent_color;

    // image_converter_asserts_free_height( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    // if ( _environment->freeImageWidth ) {
    //     if ( _width % 8 ) {
    //         _width = ( ( ( _width - 1 ) / 8 ) - 1 ) * 8;
    //     }
    //     if ( _frame_width % 8 ) {
    //         _frame_width = ( ( ( _frame_width - 1 ) / 8 ) - 1 ) * 8;
    //     }
    // }

    // RGBi * palette = malloc_palette( MAX_PALETTE );
    
    // int paletteColorCount = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    // if (paletteColorCount > 2) {
    //     CRITICAL_IMAGE_CONVERTER_TOO_COLORS( paletteColorCount );
    // }

    // int i, j, k;

    // SYSTEM_PALETTE = &SYSTEM_PALETTE_ALTERNATE[_environment->paletteSelected][0];

    // commonPalette = palette_match( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE_ALTERNATE[0]) / sizeof(RGBi) );
    // commonPalette = palette_remove_duplicates( commonPalette, paletteColorCount, &paletteColorCount );
    // lastUsedSlotInCommonPalette = paletteColorCount;
    // adilinepalette( "CPM1:%d", paletteColorCount, commonPalette );

    // adilinepalette( "CPMS:%d", (int)(sizeof(SYSTEM_PALETTE_ALTERNATE[0]) / sizeof(RGBi)), SYSTEM_PALETTE );

    // Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    // result->originalColors = lastUsedSlotInCommonPalette;
    // memcpy( result->originalPalette, commonPalette, lastUsedSlotInCommonPalette * sizeof( RGBi ) );

    // int bufferSize = c6847z_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_RESOLUTION1 );
    // // printf("bufferSize = %d\n", bufferSize );

    // adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_RESOLUTION1 );

    // char * buffer = malloc ( bufferSize );
    // memset( buffer, 0, bufferSize );

    // // Position of the pixel in the original image
    // int image_x, image_y;
    
    // // Position of the pixel, in terms of tiles
    // int tile_x, tile_y;
    
    // // Position of the pixel, in terms of offset and bitmask
    // int offset, bitmask;

    // // Color of the pixel to convert
    // RGBi rgb;

    // *(buffer) = _frame_width;
    // *(buffer+1) = _frame_height;

    // _source += ( ( _offset_y * _width ) + _offset_x ) * _depth;

    // adilinebeginbitmap("BMD");

    // int colorIndex = 0;

    // // Loop for all the source surface.
    // for (image_y = 0; image_y < _frame_height; ++image_y) {
    //     for (image_x = 0; image_x < _frame_width; ++image_x) {

    //         // Take the color of the pixel
    //         rgb.red = *_source;
    //         rgb.green = *(_source + 1);
    //         rgb.blue = *(_source + 2);
    //         if ( _depth > 3 ) {
    //             rgb.alpha = *(_source + 3);
    //         } else {
    //             rgb.alpha = 255;
    //         }
    //         if ( rgb.alpha == 0 ) {
    //             rgb.red = 0;
    //             rgb.green = 0;
    //             rgb.blue = 0;
    //         }

    //         if ( ( rgb.alpha < 255 ) || rgbi_equals_rgba( &black, &rgb ) ) {
    //             colorIndex = 0;
    //         } else if ( ( rgb.alpha == 255 ) && rgbi_equals_rgba( &white, &rgb ) ) {
    //             colorIndex = 1;
    //         } else {
    //             int minDistance = 9999;
    //             for( int i=0; i<2; ++i ) {
    //                 int distance = rgbi_distance(&commonPalette[i], &rgb );
    //                 if ( distance < minDistance ) {
    //                     minDistance = distance;
    //                     colorIndex = i;
    //                 }
    //             }
    //         }

    //         // printf("%d", i );

    //         // Calculate the offset starting from the tile surface area
    //         // and the bit to set.
    //         offset = ( image_y * ( _frame_width >> 3 ) ) + ( image_x >> 3 );
    //         bitmask = 1 << ( 7 - (image_x & 0x7) );

    //         if ( colorIndex > 0) {
    //             *( buffer + offset + 2) |= bitmask;
    //             // printf("*");
    //         } else {
    //             *( buffer + offset + 2) &= ~bitmask;
    //             // printf(" ");
    //         }

    //         adilinepixel(colorIndex);

    //         _source += _depth;

    //     }

    //     _source += ( _width - _frame_width ) * _depth;

    //     // printf("\n" );

    // }

    // adilineendbitmap();

    // // printf("----\n");

    // variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    // // printf("----\n");

    // return result;

}

static Variable * c6847z_image_converter_multicolor_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    // RGBi white = { 0xff, 0xff, 0xff, 0xff };
    // RGBi black = { 0x00, 0x00, 0x00, 0x00 };

    // // ignored on bitmap mode
    // (void)!_transparent_color;

    // image_converter_asserts_free_height( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    // if ( _environment->freeImageWidth ) {
    //     if ( _width % 8 ) {
    //         _width = ( ( ( _width - 1 ) / 8 ) - 1 ) * 8;
    //     }
    //     if ( _frame_width % 8 ) {
    //         _frame_width = ( ( ( _frame_width - 1 ) / 8 ) - 1 ) * 8;
    //     }
    // }
    
    // RGBi * palette = malloc_palette( MAX_PALETTE );
    
    // int paletteColorCount = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    // if (paletteColorCount > 4) {
    //     CRITICAL_IMAGE_CONVERTER_TOO_COLORS( paletteColorCount );
    // }

    // int i, j, k;

    // SYSTEM_PALETTE = &SYSTEM_PALETTE_ALTERNATE[_environment->paletteSelected][0];

    // commonPalette = palette_match( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE_ALTERNATE[0]) / sizeof(RGBi) );
    // commonPalette = palette_remove_duplicates( commonPalette, paletteColorCount, &paletteColorCount );
    // lastUsedSlotInCommonPalette = paletteColorCount;
    // adilinepalette( "CPM1:%d", paletteColorCount, commonPalette );

    // adilinepalette( "CPMS:%d", (int)(sizeof(SYSTEM_PALETTE_ALTERNATE[0]) / sizeof(RGBi)), SYSTEM_PALETTE );

    // Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    // result->originalColors = lastUsedSlotInCommonPalette;
    // memcpy( result->originalPalette, commonPalette, lastUsedSlotInCommonPalette * sizeof( RGBi ) );

    // int bufferSize = c6847z_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_COLOR1 );
    
    // adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_RESOLUTION1 );

    // char * buffer = malloc ( bufferSize );
    // memset( buffer, 0, bufferSize );

    // // Position of the pixel in the original image
    // int image_x, image_y;
    
    // // Position of the pixel, in terms of tiles
    // int tile_x, tile_y;
    
    // // Position of the pixel, in terms of offset and bitmask
    // int offset, offsetc, bitmask;

    // // Color of the pixel to convert
    // RGBi rgb;

    // *(buffer) = _frame_width;
    // *(buffer+1) = _frame_height;

    // _source += ( ( _offset_y * _width ) + _offset_x ) * _depth;

    // adilinebeginbitmap("BMD");

    // // Loop for all the source surface.
    // for (image_y = 0; image_y < _frame_height; ++image_y) {
    //     for (image_x = 0; image_x < _frame_width; ++image_x) {

    //         // Take the color of the pixel
    //         rgb.red = *_source;
    //         rgb.green = *(_source + 1);
    //         rgb.blue = *(_source + 2);
    //         if ( _depth > 3 ) {
    //             rgb.alpha = *(_source + 3);
    //         } else {
    //             rgb.alpha = 255;
    //         }
    //         if ( rgb.alpha == 0 ) {
    //             rgb.red = 0;
    //             rgb.green = 0;
    //             rgb.blue = 0;
    //         }

    //         offset = ( image_y * ( _frame_width >> 2 ) ) + ( image_x >> 2 );

    //         int colorIndex = 0;

    //         if ( rgb.alpha < 255 ) {
    //             colorIndex = 0;
    //         } else {
    //             int minDistance = 9999;
    //             for( int i=0; i<lastUsedSlotInCommonPalette; ++i ) {
    //                 int distance = rgbi_distance(&commonPalette[i], &rgb );
    //                 if ( distance < minDistance ) {
    //                     minDistance = distance;
    //                     colorIndex = commonPalette[i].index;
    //                 }
    //             }
    //         }

    //         adilinepixel(colorIndex);

    //         // printf( "%1.1x", colorIndex );

    //         bitmask = colorIndex << (6 - ((image_x & 0x3) * 2));

    //         *(buffer + 2 + offset) |= bitmask;

    //         _source += _depth;

    //     }

    //     _source += ( _width - _frame_width ) * _depth;

    //     // printf("\n" );
    // }

    // adilineendbitmap();

    // // for(i=0; i<4; ++i ) {
    // //     printf( "%1.1x = %2.2x\n", i, palette[i].index );
    // // }

    // // printf("\n" );
    // // printf("\n" );

    // variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    // return result;

}

Variable * c6847z_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

    // switch( _mode ) {
    //     case TILEMAP_MODE_INTERNAL:         // Alphanumeric Internal	32 × 16	2	512
    //     case TILEMAP_MODE_EXTERNAL:         // Alphanumeric External	32 × 16	2	512
    //     case TILEMAP_MODE_SEMIGRAPHICS4:    // Semigraphics 4	        64 × 32	8	512
    //     case TILEMAP_MODE_SEMIGRAPHICS6:    // Semigraphics 6	        64 × 48	4	512
    //     case TILEMAP_MODE_SEMIGRAPHICS8:    // Semigraphics 8	        64 × 64	2	512
    //     case TILEMAP_MODE_SEMIGRAPHICS12:    // Semigraphics 6	        64 × 96 1	3072
    //     case TILEMAP_MODE_SEMIGRAPHICS24:    // Semigraphics 6	        64 × 96 1	3072
    //         break;
    //     case BITMAP_MODE_COLOR1:            // Color Graphics 1	64 × 64	4	1024
    //     case BITMAP_MODE_COLOR2:            // Color Graphics 2	128 × 64	4	2048
    //     case BITMAP_MODE_COLOR3:            // Color Graphics 3	128 × 96	4	3072
    //     case BITMAP_MODE_COLOR6:            // Color Graphics 6	128 × 192	4	6144

    //         return c6847z_image_converter_multicolor_mode_standard( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );

    //         break;

    //     case BITMAP_MODE_RESOLUTION1:       // Resolution Graphics 1	128 × 64	1 + Black	1024
    //     case BITMAP_MODE_RESOLUTION2:       // Resolution Graphics 2 128 × 96	1 + Black	1536
    //     case BITMAP_MODE_RESOLUTION3:       // Resolution Graphics 3	128 × 192	1 + Black	3072
    //     case BITMAP_MODE_RESOLUTION6:       // Resolution Graphics 6	256 × 192	1 + Black	6144            break;

    //         return c6847z_image_converter_bitmap_mode_standard( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height, _transparent_color, _flags );

    // }

    // WARNING_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

    // return c6847z_new_image( _environment, 8, 8, BITMAP_MODE_RESOLUTION6 );

}

static void c6847z_load_image_address_to_register( Environment * _environment, char * _register, Resource * _source, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

    // if ( !_sequence && !_frame ) {
    //     if ( _source->isAddress ) {
    //         outline1("LDY %s", _source->realName );
    //         outline1("STY %s", _register );
    //     } else {
    //         outline1("LDY #%s", _source->realName );
    //         outline1("STY %s", _register );
    //     }
    // } else {

    //     if ( _source->isAddress ) {
    //         outline1("LDY %s", _source->realName );
    //     } else {
    //         outline1("LDY #%s", _source->realName );
    //     }

    //     if ( _sequence ) {
    //         outline0("LEAY 3,y" );
    //         if ( strlen(_sequence) == 0 ) {
    //         } else {
    //             outline1("LDB %s", _sequence );
    //             outline1("JSR %soffsetsequence", _source->realName );
    //         }
    //         if ( _frame ) {
    //             if ( strlen(_frame) == 0 ) {
    //             } else {
    //                 outline1("LDB %s", _frame );
    //                 outline1("JSR %soffsetframe", _source->realName );
    //             }
    //         }
    //     } else {
    //         if ( _frame ) {
    //             outline0("LEAY 3,y" );
    //             if ( strlen(_frame) == 0 ) {
    //             } else {
    //                 outline1("LDB %s", _frame );
    //                 outline1("JSR %soffsetframe", _source->realName );
    //             }
    //         }
    //     }

    //     outline1("STY %s", _register );

    // }

}

void c6847z_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    // deploy( c6847vars, src_hw_6847_vars_asm);
    // deploy( blitimage, src_hw_6847_blit_image_asm );

    // if ( _source_count > 2 ) {
    //     CRITICAL_BLIT_TOO_MUCH_SOURCES( );
    // }

    // MAKE_LABEL

    // outhead1("blitimage%s", label);

    // outline1("LDY #%s", _blit );
    // outline0("STY BLITIMAGEBLITADDR" );

    // if ( _source_count > 0 ) {
    //     Resource resource;
    //     resource.realName = strdup( _sources[0] );
    //     resource.isAddress = 0;
    //     resource.type = VT_IMAGE;
    //     c6847z_load_image_address_to_register( _environment, "BLITTMPPTR", &resource, _sequence, _frame, _frame_size, _frame_count );
    // } else {
    //     outline0( "LDY #0" );
    //     outline0( "STY BLITTMPPTR" );
    // }

    // if ( _source_count > 1 ) {
    //     Resource resource;
    //     resource.realName = strdup( _sources[1] );
    //     resource.isAddress = 0;
    //     resource.type = VT_IMAGE;
    //     c6847z_load_image_address_to_register( _environment, "BLITTMPPTR2", &resource, _sequence, _frame, _frame_size, _frame_count );
    // } else {
    //     outline0( "LDY #0" );
    //     outline0( "STY BLITTMPPTR2" );
    // }

    // outline1("LDD %s", _x );
    // outline0("STD <IMAGEX" );
    // outline1("LDD %s", _y );
    // outline0("STD <IMAGEY" );

    // outline1("LDA #$%2.2x", ( _flags & 0xff ) );
    // outline0("STA <IMAGEF" );
    // outline1("LDA #$%2.2x", ( (_flags>>8) & 0xff ) );
    // outline0("STA <IMAGET" );

    // outline0("JSR BLITIMAGE");
    
}

void c6847z_put_image( Environment * _environment, Resource * _source, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _flags ) {

    // deploy( c6847vars, src_hw_6847_vars_asm);
    // deploy( putimage, src_hw_6847_put_image_asm );

    // if ( _source->isAddress ) {
    //     outline1("LDY %s", _source->realName );
    // } else {
    //     outline1("LDY #%s", _source->realName );
    // }

    // if ( _frame_size ) {
    //     if ( !_sequence && !_frame ) {
    //     } else {
    //         if ( _sequence ) {
    //             outline0("LEAY 3,y" );
    //             if ( strlen(_sequence) == 0 ) {
    //             } else {
    //                 outline1("LDB %s", _sequence );
    //                 outline1("JSR %soffsetsequence", _source->realName );
    //             }
    //             if ( _frame ) {
    //                 if ( strlen(_frame) == 0 ) {
    //                 } else {
    //                     outline1("LDB %s", _frame );
    //                     outline1("JSR %soffsetframe", _source->realName );
    //                 }
    //             }
    //         } else {
    //             if ( _frame ) {
    //                 outline0("LEAY 3,y" );
    //                 if ( strlen(_frame) == 0 ) {
    //                 } else {
    //                     outline1("LDB %s", _frame );
    //                     outline1("JSR %soffsetframe", _source->realName );
    //                 }
    //             }
    //         }

    //     }
    // }
    
    // outline1("LDD %s", _x );
    // outline0("STD <IMAGEX" );
    // outline1("LDD %s", _y );
    // outline0("STD <IMAGEY" );

    // outline1("LDD %s", _flags );
    // outline0("STB <IMAGEF" );
    // outline0("STA <IMAGET" );

    // outline0("JSR PUTIMAGE");
    
}

Variable * c6847z_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    // int size = c6847z_image_size( _environment, _width, _height, _mode );

    // if ( ! size ) {
    //     CRITICAL_NEW_IMAGE_UNSUPPORTED_MODE( _mode );
    // }

    // Variable * result = variable_temporary( _environment, VT_IMAGE, "(new image)" );

    // char * buffer = malloc ( size );
    // memset( buffer, 0, size );

    // *(buffer) = _width;
    // *(buffer+1) = _height;

    // result->valueBuffer = buffer;
    // result->size = size;
    
    // return result;

}

Variable * c6847z_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

    // int size = calculate_images_size( _environment, _frames, _width, _height, _mode );
    // int frameSize = c6847z_image_size( _environment, _width, _height, _mode );

    // if ( ! size ) {
    //     CRITICAL_NEW_IMAGES_UNSUPPORTED_MODE( _mode );
    // }

    // Variable * result = variable_temporary( _environment, VT_IMAGES, "(new images)" );

    // char * buffer = malloc ( size );
    // memset( buffer, 0, size );

    // *(buffer) = _frames;
    // *(buffer+1) = ( _width & 0xff );
    // *(buffer+2) = ( _width >> 8 ) & 0xff;
    // for( int i=0; i<_frames; ++i ) {
    //     *(buffer+3+(i*frameSize)) = _width;
    //     *(buffer+3+(i*frameSize)+1) = _height;
    // }

    // result->valueBuffer = buffer;
    // result->frameSize = frameSize;
    // result->size = size;
    // result->frameCount = _frames;
    
    // return result;

}

Variable * c6847z_new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

    // int size2 = calculate_sequence_size( _environment, _sequences, _frames, _width, _height, _mode );
    // int size = calculate_images_size( _environment, _frames, _width, _height, _mode );
    // int frameSize = c6847z_image_size( _environment, _width, _height, _mode );

    // if ( ! size ) {
    //     CRITICAL_NEW_IMAGES_UNSUPPORTED_MODE( _mode );
    // }

    // Variable * result = variable_temporary( _environment, VT_SEQUENCE, "(new sequence)" );

    // char * buffer = malloc ( size2 );
    // memset( buffer, 0, size2 );

    // *(buffer) = _frames;
    // *(buffer+1) = _width;
    // *(buffer+2) = _sequences;
    // for( int i=0; i<(_frames * _sequences); ++i ) {
    //     *(buffer+3+(i*frameSize)) = _width;
    //     *(buffer+3+(i*frameSize)+1) = _height;
    // }

    // result->valueBuffer = buffer;
    // result->frameSize = frameSize;
    // result->size = size2;
    // result->frameCount = _frames;
    
    // return result;

}

void c6847z_get_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _palette ) {

    // deploy( c6847vars, src_hw_6847_vars_asm);
    // deploy( getimage, src_hw_6847_get_image_asm );

    // outline1("LDY #%s", _image );
    // if ( _sequence ) {
    //     outline0("LEAY 3,y" );
    //     if ( strlen(_sequence) == 0 ) {
    //     } else {
    //         outline1("LDX #OFFSETS%4.4x", _frame_count * _frame_size );
    //         outline1("LDB %s", _sequence );
    //         outline0("LDA #0" );
    //         outline0("LEAX D, X" );
    //         outline0("LEAX D, X" );
    //         outline0("LDD ,X" );
    //         outline0("LEAY D, Y" );
    //     }
    //     if ( _frame ) {
    //         if ( strlen(_frame) == 0 ) {
    //         } else {
    //             outline1("LDX #OFFSETS%4.4x", _frame_size );
    //             outline1("LDB %s", _frame );
    //             outline0("LDA #0" );
    //             outline0("LEAX D, X" );
    //             outline0("LEAX D, X" );
    //             outline0("LDD ,X" );
    //             outline0("LEAY D, Y" );
    //         }
    //     }
    // } else {
    //     if ( _frame ) {
    //         outline0("LEAY 3,y" );
    //         if ( strlen(_frame) == 0 ) {
    //         } else {
    //             outline1("LDX #OFFSETS%4.4x", _frame_size );
    //             outline1("LDB %s", _frame );
    //             outline0("LDA #0" );
    //             outline0("LEAX D, X" );
    //             outline0("LEAX D, X" );
    //             outline0("LDD ,X" );
    //             outline0("LEAY D, Y" );
    //         }
    //     }
    // }

    // outline1("LDD %s", _x );
    // outline0("STD <IMAGEX" );
    // outline1("LDD %s", _y );
    // outline0("STD <IMAGEY" );
    // outline1("LDA #$%2.2x", _palette );
    // outline0("STA <IMAGET");

    // outline0("JSR GETIMAGE");

}

void c6847z_scroll( Environment * _environment, int _dx, int _dy ) {

}

void c6847z_put_tile( Environment * _environment, char * _tile, char * _x, char * _y ) {

}

void c6847z_tile_at( Environment * _environment, char * _x, char * _y, char * _result ) {

}

void c6847z_move_tiles( Environment * _environment, char * _tile, char * _x, char * _y ) {

}

void c6847z_put_tiles( Environment * _environment, char * _tile, char * _x, char * _y, char *_w, char *_h ) {


}

void c6847z_use_tileset( Environment * _environment, char * _tileset ) {

}

Variable * c6847z_get_raster_line( Environment * _environment ) {

    // Variable * result = variable_temporary( _environment, VT_WORD, "(raster line)" );

    // variable_store( _environment, result->name, 0 );

    // return result;
    
}

void c6847z_slice_image( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination ) {

}

int c6847z_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette ) {

    // int paletteColorCount = rgbi_extract_palette(_environment, _data, _width, _height, _depth, _palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    // SYSTEM_PALETTE = &SYSTEM_PALETTE_ALTERNATE[_environment->paletteSelected][0];

    // memcpy( _palette, palette_match( _palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) ), paletteColorCount * sizeof( RGBi ) );

    // int uniquePaletteCount = 0;

    // memcpy( _palette, palette_remove_duplicates( _palette, paletteColorCount, &uniquePaletteCount ), paletteColorCount * sizeof( RGBi ) );

    // return uniquePaletteCount;

}

void c6847z_calculate_sequence_frame_offset( Environment * _environment, char * _offset, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

    // outline0("LDY #$0" );
    // if ( _sequence ) {
    //     outline0("LEAY 3,y" );
    //     if ( strlen(_sequence) == 0 ) {
    //     } else {
    //         outline1("LDX #OFFSETS%4.4x", _frame_count * _frame_size );
    //         outline1("LDB %s", _sequence );
    //         outline0("LDA #0" );
    //         outline0("LEAX D, X" );
    //         outline0("LEAX D, X" );
    //         outline0("LDD ,X" );
    //         outline0("LEAY D, Y" );
    //     }
    //     if ( _frame ) {
    //         if ( strlen(_frame) == 0 ) {
    //         } else {
    //             outline1("LDX #OFFSETS%4.4x", _frame_size );
    //             outline1("LDB %s", _frame );
    //             outline0("LDA #0" );
    //             outline0("LEAX D, X" );
    //             outline0("LEAX D, X" );
    //             outline0("LDD ,X" );
    //             outline0("LEAY D, Y" );
    //         }
    //     }
    // } else {
    //     if ( _frame ) {
    //         outline0("LEAY 3,y" );
    //         if ( strlen(_frame) == 0 ) {
    //         } else {
    //             outline1("LDX #OFFSETS%4.4x", _frame_size );
    //             outline1("LDB %s", _frame );
    //             outline0("LDA #0" );
    //             outline0("LEAX D, X" );
    //             outline0("LEAX D, X" );
    //             outline0("LDD ,X" );
    //             outline0("LEAY D, Y" );
    //         }
    //     }
    // }

    // outline1("STY %s", _offset );

}

void c6847z_flip_image( Environment * _environment, Resource * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _direction ) {

    // deploy( c6847vars, src_hw_6847_vars_asm);

    // if ( strcmp( _direction, "#FLIPIMAGEDIRECTION0001" ) == 0 || strcmp( _direction, "#FLIPIMAGEDIRECTION0003" ) == 0 ) {
    //     c6847z_load_image_address_to_register( _environment, "TMPPTR", _image, _sequence, _frame, _frame_size, _frame_count );
    //     deploy( flipimagex, src_hw_6847_flip_image_x_asm );
    //     outline0("JSR FLIPIMAGEX");
    // } else {
        
    //     MAKE_LABEL

    //     c6847z_load_image_address_to_register( _environment, "TMPPTR", _image, _sequence, _frame, _frame_size, _frame_count );
    //     deploy( flipimagex, src_hw_6847_flip_image_x_asm );
    //     outline1("LDA %s", _direction );
    //     outline1("ANDA #$%2.2x", FLAG_FLIP_X );
    //     outline1("BEQ %s", label );
    //     outline0("JSR FLIPIMAGEX");
    //     outhead1("%s", label );

    // }
    
    // if ( strcmp( _direction, "#FLIPIMAGEDIRECTION0002" ) == 0 || strcmp( _direction, "#FLIPIMAGEDIRECTION0003" ) == 0 ) {
    //     c6847z_load_image_address_to_register( _environment, "TMPPTR", _image, _sequence, _frame, _frame_size, _frame_count );
    //     deploy( flipimagey, src_hw_6847_flip_image_y_asm );
    //     outline0("JSR FLIPIMAGEY");
    // } else {
        
    //     MAKE_LABEL

    //     c6847z_load_image_address_to_register( _environment, "TMPPTR", _image, _sequence, _frame, _frame_size, _frame_count );
    //     deploy( flipimagey, src_hw_6847_flip_image_y_asm );
    //     outline1("LDA %s", _direction );
    //     outline1("ANDA #$%2.2x", FLAG_FLIP_Y );
    //     outline1("BEQ %s", label );
    //     outline0("JSR FLIPIMAGEY");
    //     outhead1("%s", label );

    // }

}

void c6847z_screen( Environment * _environment, char * _x, char * _y, char * _c ) {

    // deploy( screen, src_hw_6847_screen_asm);

    // outline1("LDA %s", _x );
    // outline1("LDB %s", _y );
    // outline0("JSR SCREEN" );
    // outline1("STA %s", _c );

}
void c6847z_cls_box( Environment * _environment, char * _x1, char * _y1, char * _w, char * _h ) {

    if ( _environment->currentMode < 7 ) {

    } else {
        // deploy( clsBox, src_hw_6847_cls_box_asm );
        // outline1("LDD %s", _x1 );
        // outline0("STD <IMAGEX" );
        // outline1("LDD %s", _y1 );
        // outline0("STD <IMAGEY"  );
        // outline1("LDA %s", _w );
        // outline0("STA <IMAGEW" );
        // outline1("LDA %s", _h );
        // outline0("STA <IMAGEH" );
        // outline0("JSR CLSBOX");
    }

}

#endif