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

#if defined(__d32__) || defined(__d64__)

#include "../ugbc.h"
#include "6809.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
    // { "BLACK", 
        { 0x00, 0x00, 0x00, 0 },        
    // { "GREEN", 
        { 0x00, 0xcc, 0x55, 1 },
    // { "YELLOW", 
        { 0xee, 0xee, 0x77, 2 },
    // { "BLUE", 
        { 0x00, 0x00, 0xaa, 3 },
    // { "RED", 
        { 0x88, 0x00, 0x00, 4 },
    // { "BUFF", 
        { 0xf0, 0xf0, 0xf0, 5 },
    // { "CYAN", 
        { 0xaa, 0xff, 0xe6, 6 },
    // { "MAGENTA", <- 
        { 0xcc, 0x44, 0xcc, 7 },
    // { "ORANGE", 
        { 0xa1, 0x68, 0x3c, 8 }
};

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
void c6847_collision( Environment * _environment, char * _sprite_mask, char * _result ) {
    
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
void c6847_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

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
void c6847_border_color( Environment * _environment, char * _border_color ) {

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
void c6847_background_color( Environment * _environment, char * _index, char * _background_color ) {

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
void c6847_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {

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
void c6847_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

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
void c6847_next_raster( Environment * _environment ) {

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
void c6847_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to enable ECM
 * 
 * @param _environment Current calling environment
 */
void c6847_enable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void c6847_disable_ecm( Environment * _environment ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to enable MCM
 * 
 * @param _environment Current calling environment
 */
void c6847_enable_mcm( Environment * _environment ) {

}

/**
 * @brief <i>VIC-II</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void c6847_disable_mcm( Environment * _environment ) {

}

void c6847_bank_select( Environment * _environment, int _bank ) {

}

#define SET_VIDEOAT_400     SAM_F0_CLR; SAM_F1_CLR; SAM_F2_CLR; SAM_F3_CLR; SAM_F4_CLR; SAM_F5_CLR; SAM_F6_CLR; SAM_F1_SET;
#define SET_VIDEOAT_600     SAM_F0_CLR; SAM_F1_CLR; SAM_F2_CLR; SAM_F3_CLR; SAM_F4_CLR; SAM_F5_CLR; SAM_F6_CLR; SAM_F0_SET; SAM_F1_SET; 
#define SET_VIDEOAT_C00     SAM_F0_CLR; SAM_F1_CLR; SAM_F2_CLR; SAM_F3_CLR; SAM_F4_CLR; SAM_F5_CLR; SAM_F6_CLR; SAM_F1_SET; SAM_F2_SET; 

int c6847_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    deploy( c6847vars, src_hw_6847_vars_asm );

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
            // Internal alphanumeric 0 X X 0 0 0 0 32x16 ( 5x7 pixel ch)
            SET_VIDEOAT_400;
            VDG_TEXT;
            SAM_V2_CLR;
            SAM_V1_CLR;
            SAM_V0_CLR;
            GM2_CLR;
            GM1_CLR;
            GM0_CLR;
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 31 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 15 );
            cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 32*16 );
            break;
        case TILEMAP_MODE_EXTERNAL:         // Alphanumeric External	32 × 16	2	512
            _environment->screenWidth = 32*8;
            _environment->screenHeight = 16*12;
            _environment->screenTilesWidth = 32;
            _environment->screenTilesHeight = 16;
            // External alphanumeric 0 X X 1 0 0 0 32x16 (8x12 pixel ch)
            SET_VIDEOAT_400;
            VDG_TEXT;
            SAM_V2_CLR;
            SAM_V1_CLR;
            SAM_V0_CLR;
            GM2_CLR;
            GM1_CLR;
            GM0_SET;
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 31 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 15 );
            cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 32*16 );
            break;
        // The ALPHA SEMIGRAPHICS – 4 mode translates bits 0 through 3 into a 4 x 6 dot 
        // element in the standard 8 x 12 dot box. Three data bits may be used to select
        // one of eight colors for the entire character box. The extra bit is used to 
        // switch to alphanumeric. A 512 byte display memory is required. A density of 
        // 64 x 32 elements is available in the display area. The element area is four
        // dot-clocks wide by six lines high.
        case TILEMAP_MODE_SEMIGRAPHICS4:    // Semigraphics 4	        64 × 32	8	512
            _environment->screenWidth = 64*4;
            _environment->screenHeight = 32*6;
            _environment->screenTilesWidth = 64;
            _environment->screenTilesHeight = 32;
            // Semigraphic-4 0 X X 0 0 0 0 32x16 ch, 64x32 pixels
            SET_VIDEOAT_400;
            VDG_TEXT;
            SAM_V2_CLR;
            SAM_V1_CLR;
            SAM_V0_CLR;
            GM2_CLR;
            GM1_CLR;
            GM0_CLR;
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 63 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 31 );
            cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 512 );
            break;
        // The ALPHA SEMIGRAPHICS – 6 mode maps six 4 x 4 dot elements into the standard
        // 8 x 12 dot alphanumeric box, a screen density of 64 x 48 elements is available. 
        // Six bits are used to generate this map and two data bits may be used to select 
        // one of four colors in the display box. A 512 byte display memory is required. 
        // The element area is four dot-clocks wide by four lines high.
        case TILEMAP_MODE_SEMIGRAPHICS6:    // Semigraphics 6	        64 × 48	4	512
            _environment->screenWidth = 64*8;
            _environment->screenHeight = 48*12;
            _environment->screenTilesWidth = 64;
            _environment->screenTilesHeight = 48;
            // Semigraphic-6 0 X X 1 0 0 0 64x48 pixels
            SET_VIDEOAT_400;
            VDG_TEXT;
            SAM_V2_CLR;
            SAM_V1_CLR;
            SAM_V0_CLR;
            GM2_CLR;
            GM1_CLR;
            GM0_SET;
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 63 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 47 );
            cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 512 );
            break;
        // The ALPHA SEMIGRAPHICS – 8 mode maps eight 4 x 3 dot elements into the 
        // standard 8 x 12 dot box. This mode requires four memory locations per box 
        // and each memory location may specify one of eight colors or black. 
        // A 2048 byte display memory is required. A density of 64 x 64 elements is 
        // available in the display area. The element area is four dot-clocks wide 
        // by three lines high.
        case TILEMAP_MODE_SEMIGRAPHICS8:    // Semigraphics 8	        64 × 64	2	512
            _environment->screenWidth = 64*8;
            _environment->screenHeight = 64*12;
            _environment->screenTilesWidth = 64;
            _environment->screenTilesHeight = 64;
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 63 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 63 );
            cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 2048 );
            break;
        // The ALPHA SEMIGRAPHICS – 12 mode maps twelve 4 x 2 dot elements into the 
        // standard 8 x 12 dot box. This mode requires six memory locations per box and 
        // each memory location may specify one of eight colors or black. A 3072 byte 
        // display memory is required. A density of 64 x 96 elements is available in the
        // display area. The element area is four dot-clocks wide by two lineshigh.
        case TILEMAP_MODE_SEMIGRAPHICS12:    // Semigraphics 6	        64 × 96 1	3072
            _environment->screenWidth = 64*8;
            _environment->screenHeight = 96*12;
            _environment->screenTilesWidth = 64;
            _environment->screenTilesHeight = 96;
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 63 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 95 );
            cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 3072 );
            break;
        // The ALPHA SEMIGRAPHICS – 24 mode maps twenty-four 4 x 1 dot elements into 
        // the standard 8 x 12 dot box. This mode requires twelve memory locations 
        // per box and each memory location may specify one of eight colors or black. 
        // A 6144 byte display memory is required. A density of 64 x 192
        // elements is available in the display are. The element area is four 
        // dot-clocks wide by one line high.
        case TILEMAP_MODE_SEMIGRAPHICS24:    // Semigraphics 6	        64 × 96 1	3072
            _environment->screenWidth = 64*8;
            _environment->screenHeight = 96*12;
            _environment->screenTilesWidth = 64;
            _environment->screenTilesHeight = 96;
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 63 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 191 );
            cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 6144 );
            break;
        // The 64 x 64 Color Graphics mode generates a display matrix of 64 
        // elements wide by 64 elements high. Each element may be one of four 
        // colors. A 1K x 8 display memory is required. Each pixel equals 
        // four dot-clocks by three scan lines.
        case BITMAP_MODE_COLOR1:            // Color Graphics 1	64 × 64	4	1024
            _environment->screenWidth = 64;
            _environment->screenHeight = 64;
            _environment->screenTilesWidth = 64/8;
            _environment->screenTilesHeight = 96/12;
            // Full graphic 1-C 1 0 0 0 0 0 1 64x64x4 $400(1024)
            SET_VIDEOAT_C00;
            VDG_GRAPH;
            SAM_V2_CLR;
            SAM_V1_CLR;
            SAM_V0_SET;
            GM2_CLR;
            GM1_CLR;
            GM0_CLR;
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 63 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 63 );
            cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 1024 );
            cpu_store_8bit( _environment, "CURRENTSL", 64 / 4 );            
            break;
        // The 128 x 64 Graphics Mode generates a matrix 128 elements wide 
        // by 64 elements high. Each element may be either ON or OFF. However, 
        // the entire display may be one of two colors, selected by using the 
        // color set select pin. A 1K x 8 display memory is required. Each 
        // pixel equals two dotclocks by three scan lines.
        case BITMAP_MODE_RESOLUTION1:       // Resolution Graphics 1	128 × 64	1 + Black	1024
            _environment->screenWidth = 128;
            _environment->screenHeight = 64;
            _environment->screenTilesWidth = 128/8;
            _environment->screenTilesHeight = 64/12;
            // Full graphic 1-R 1 0 0 1 0 0 1 128x64x2 $400(1024)
            SET_VIDEOAT_C00;
            VDG_GRAPH;
            SAM_V2_CLR;
            SAM_V1_CLR;
            SAM_V0_SET;
            GM2_CLR;
            GM1_CLR;
            GM0_SET;
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 127 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 63 );
            cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 1024 );
            cpu_store_8bit( _environment, "CURRENTSL", 128 / 8 );            
            break;
        // The 128 x 64 Color Graphics mode generates a display matrix 128 
        // elements wide by 64 elements high. Each element may be one of four 
        // colors. A 2K x 8 display memory is required. Each pixel equals
        // two dot-clocks by three scan lines.
        case BITMAP_MODE_COLOR2:            // Color Graphics 2	128 × 64	4	2048
            _environment->screenWidth = 128;
            _environment->screenHeight = 64;
            _environment->screenTilesWidth = 128/8;
            _environment->screenTilesHeight = 64/12;
            // Full graphic 2-C 1 0 1 0 0 1 0 128x64x4 $800(2048)
            SET_VIDEOAT_C00;
            VDG_GRAPH;
            SAM_V2_CLR;
            SAM_V1_SET;
            SAM_V0_CLR;
            GM2_CLR;
            GM1_SET;
            GM0_CLR;
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 127 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 63 );
            cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 2048 );
            cpu_store_8bit( _environment, "CURRENTSL", 128 / 4 );
            break;
        // The 128 x 96 Graphics mode generates a display matrix 128 
        // elements wide by 96 elements high. Each element may be either 
        // ON or OFF. However, the entire display may be one of two colors
        // selected by using the color select pin. A 2K x 8 display memory 
        // is required. Each pixel equals two dot-clocks by two scan lines.
        case BITMAP_MODE_RESOLUTION2:       // Resolution Graphics 2 128 × 96	1 + Black	1536
            _environment->screenWidth = 128;
            _environment->screenHeight = 96;
            _environment->screenTilesWidth = 128/8;
            _environment->screenTilesHeight = 96/12;
            // Full graphic 2-R 1 0 1 1 0 1 1 128x96x2 $600(1536)
            SET_VIDEOAT_C00;
            VDG_GRAPH;
            SAM_V2_CLR;
            SAM_V1_SET;
            SAM_V0_SET;
            GM2_CLR;
            GM1_SET;
            GM0_SET;
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 127 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 95 );
            cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 1536 );
            cpu_store_8bit( _environment, "CURRENTSL", 128 / 8 );
            break;
        // The 128 x 96 Color Graphics mode generates a display 128 elements 
        // wide by 96 elements high. Each element may be one of four colors. 
        // A 3K x 8 display memory is required. Each pixel equals two 
        // dot-clocks by two scan lines.
        case BITMAP_MODE_COLOR3:            // Color Graphics 3	128 × 96	4	3072
            _environment->screenWidth = 128;
            _environment->screenHeight = 96;
            _environment->screenTilesWidth = 128/8;
            _environment->screenTilesHeight = 96/12;
            // Full graphic 3-C 1 1 0 0 1 0 0 128x96x4 $C00(3072)
            SET_VIDEOAT_C00;
            VDG_GRAPH;
            SAM_V2_SET;
            SAM_V1_CLR;
            SAM_V0_CLR;
            GM2_SET;
            GM1_CLR;
            GM0_CLR;
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 127 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 95 );
            cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 3072 );
            cpu_store_8bit( _environment, "CURRENTSL", 128 / 4 );
            break;
        // The 128 x 192 Graphics mode generates a display matrix 128 elements 
        // wide by 192 elements high. Each element may be either ON or OFF,
        // but the ON elements may be one of two colors selected with color 
        // set select pin. A 3K x 8 display memory is required. Each pixel 
        // equals two dot-clocks by one scan line.
        case BITMAP_MODE_RESOLUTION3:       // Resolution Graphics 3	128 × 192	1 + Black	3072
            _environment->screenWidth = 128;
            _environment->screenHeight = 192;
            _environment->screenTilesWidth = 128/8;
            _environment->screenTilesHeight = 192/12;
            // Full graphic 3-R 1 1 0 1 1 0 1 128x192x2 $C00(3072)
            SET_VIDEOAT_C00;
            VDG_GRAPH;
            SAM_V2_SET;
            SAM_V1_CLR;
            SAM_V0_SET;
            GM2_SET;
            GM1_CLR;
            GM0_SET;
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 127 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 191 );
            cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 3072 );
            cpu_store_8bit( _environment, "CURRENTSL", 128 / 8 );
            break;
        // The 128 x 192 Color Graphics mode generates a display 128 elements 
        // wide by 192 elements high. Each element may be one of four colors.
        // A 6K x 8 display memory is required. Each pixel equals two dot-clocks 
        // by one scan line.
        case BITMAP_MODE_COLOR6:            // Color Graphics 6	128 × 192	4	6144
            _environment->screenWidth = 128;
            _environment->screenHeight = 192;
            _environment->screenTilesWidth = 128/8;
            _environment->screenTilesHeight = 192/12;
            // Full graphic 6-C 1 1 1 0 1 1 0 128x192x4 $1800(6144)
            SET_VIDEOAT_C00;
            VDG_GRAPH;
            SAM_V2_SET;
            SAM_V1_SET;
            SAM_V0_CLR;
            GM2_SET;
            GM1_SET;
            GM0_CLR;
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 127 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 191 );
            cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 6144 );
            cpu_store_8bit( _environment, "CURRENTSL", 128 / 4 );
            break;
        // The 256 x 192 Graphics mode generates a display 256 elements wide by 
        // 192 elements high. Each element may be either ON or OFF, but the ON 
        // element may be one of two colors selected with the color set select pin. 
        // A 6K x 8 display memory is required. Each pixel equals one 
        // dot-clock by one scan line.
        case BITMAP_MODE_RESOLUTION6:       // Resolution Graphics 6	256 × 192	1 + Black	6144            break;
            _environment->screenWidth = 256;
            _environment->screenHeight = 192;
            _environment->screenTilesWidth = 256/8;
            _environment->screenTilesHeight = 192/12;
            // Full graphic 6-R 1 1 1 1 1 1 0 256x192x2 $1800(6144)
            SET_VIDEOAT_C00;
            VDG_GRAPH;
            SAM_V2_SET;
            SAM_V1_SET;
            SAM_V0_CLR;
            SAM_V2_SET;
            SAM_V1_SET;
            SAM_V0_SET;
            cpu_store_16bit( _environment, "CLIPX1", 0 );
            cpu_store_16bit( _environment, "CLIPX2", 255 );
            cpu_store_16bit( _environment, "CLIPY1", 0 );
            cpu_store_16bit( _environment, "CLIPY2", 191 );
            cpu_store_16bit( _environment, "CURRENTFRAMESIZE", 6144 );
            cpu_store_8bit( _environment, "CURRENTSL", 256 / 8 );
            break;
        default:
            CRITICAL_SCREEN_UNSUPPORTED( _screen_mode->id );
    }

    cpu_store_16bit( _environment, "CURRENTWIDTH", _environment->screenWidth );
    cpu_store_16bit( _environment, "CURRENTHEIGHT", _environment->screenHeight );
    cpu_store_8bit( _environment, "CURRENTTILESWIDTH", _environment->screenTilesWidth );
    cpu_store_8bit( _environment, "CURRENTTILESHEIGHT", _environment->screenTilesHeight );

}

void c6847_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors );

    c6847_screen_mode_enable( _environment, mode );

    cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
    
    _environment->currentMode = mode->id;

}

void c6847_bitmap_disable( Environment * _environment ) {    

}

void c6847_tilemap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors );

    c6847_screen_mode_enable( _environment, mode );

    _environment->currentMode = mode->id;

    cpu_store_8bit( _environment, "CURRENTMODE", mode->id );    

}

void c6847_bitmap_at( Environment * _environment, char * _address ) {

    MAKE_LABEL

    outline1("LDA %s", _address);
    outline0("LDB #$07");
    outline0("LDX #$FFC6");
    outhead1("%s", label);
    outline0("RORA");
    outline1("BCC %s_bit0", label);
    outline0("STA 1,X");
    outline1("BRA %s_next", label);
    outhead1("%s_bit0", label);
    outline0("STA ,X");
    outhead1("%s_next", label);
    outline0("LEAX 2,X");
    outline0("DECB");
    outline1("BNE %s", label );

}

void c6847_colormap_at( Environment * _environment, char * _address ) {    

}

void c6847_textmap_at( Environment * _environment, char * _address ) {

    MAKE_LABEL

    outline1("LDA %s", _address);
    outline0("LDB #$07");
    outline0("LDX #$FFC6");
    outhead1("%s", label);
    outline0("RORA");
    outline1("BCC %s_bit0", label);
    outline0("STA 1,X");
    outline1("BRA %s_next", label);
    outhead1("%s_bit0", label);
    outline0("STA ,X");
    outhead1("%s_next", label);
    outline0("LEAX 2,X");
    outline0("DECB");
    outline1("BNE %s", label );    

}

void c6847_point_at_int( Environment * _environment, int _x, int _y ) {

    deploy( c6847vars, src_hw_6847_vars_asm );
    deploy( plot, src_hw_6847_plot_asm );
    
    outline1("LDX %4.4x", (_x & 0xffff ) );
    outline0("STX PLOTX");
    outline1("LDD %4.4x", ( _y & 0xffff ) );
    outline0("STD PLOTY");
    outline0("LDA #1");
    outline0("STA PLOTM");
    outline0("JSR PLOT");
    

}

void c6847_point_at_vars( Environment * _environment, char *_x, char *_y ) {

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );

    deploy( c6847vars, src_hw_6847_vars_asm );
    deploy( plot, src_hw_6847_plot_asm );
    
    outline1("LDX %s", x->realName );
    outline0("STX PLOTX");
    outline1("LDD %s", y->realName );
    outline0("STD PLOTY");
    outline0("LDA #1");
    outline0("STA PLOTM");
    outline0("JSR PLOT");

}

void c6847_point( Environment * _environment, char *_x, char *_y, char * _result ) {

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    Variable * result = variable_retrieve_or_define( _environment, _result, VT_BYTE, 0 );

    deploy( c6847vars, src_hw_6847_vars_asm );
    deploy( plot, src_hw_6847_plot_asm );
    
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

void c6847_screen_on( Environment * _environment ) {

}

void c6847_screen_off( Environment * _environment ) {

}

void c6847_screen_rows( Environment * _environment, char * _rows ) {

}

void c6847_sprite_data_from( Environment * _environment, char * _sprite, char * _address ) {

}

void c6847_sprite_enable( Environment * _environment, char * _sprite ) {

}

void c6847_sprite_disable( Environment * _environment, char * _sprite ) {

}

void c6847_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

}

void c6847_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

}

void c6847_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

}

void c6847_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

}

void c6847_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

}

void c6847_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void c6847_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void c6847_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

}

void c6847_tiles_at( Environment * _environment, char * _address ) {

}

void c6847_vertical_scroll( Environment * _environment, char * _displacement ) {

}

void c6847_horizontal_scroll( Environment * _environment, char * _displacement ) {

}

void c6847_get_width( Environment * _environment, char *_result ) {

    outline0("LDX CURRENTWIDTH" );
    outline1("STX %s", _result );

}

void c6847_tiles_get_width( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILESWIDTH" );
    outline1("STA %s", _result );

}

void c6847_get_height( Environment * _environment, char *_result ) {

    outline0("LDX CURRENTHEIGHT" );
    outline1("STX %s", _result );

}

void c6847_tiles_get_height( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILESHEIGHT" );
    outline1("STA %s", _result );

}

void c6847_cls( Environment * _environment ) {

    deploy( cls, src_hw_6847_cls_asm );

    outline0("JSR CLS");

}

void c6847_scroll_text( Environment * _environment, int _direction ) {

    deploy( vScrollText, src_hw_6847_vscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );

    outline0("JSR VSCROLLT");

}

void c6847_text_at( Environment * _environment, char * _x, char * _y, char * _text, char * _text_size, char * _pen, char *_ww ) {

    deploy( c6847vars, src_hw_6847_vars_asm);
    deploy( vScrollText, src_hw_6847_vscroll_text_asm );
    deploy( textEncodedAt, src_hw_6847_text_at_asm );

    outline1("LDY %s", _text);
    outline0("STY TEXTPTR" );
    outline0("LDY TEXTADDRESS" );
    outline0("STY COPYOFTEXTADDRESS" );
    outline1("LDA %s", _x );
    outline0("STA XCURSYS" );
    outline1("LDA %s", _y );
    outline0("STA YCURSYS" );
    outline1("LDA %s", _text_size);
    outline0("STA TEXTSIZE" );
    outline0("LDA #0" );
    outline0("STA TABSTODRAW" );
    outline1("LDA %s", _ww );
    outline0("STA TEXTWW" );
    outline1("LDA %s", _pen );
    outline0("STA TEXTPEN" );
    outline0("LDA _PAPER" );
    outline0("STA TEXTPAPER" );

    outline0("JSR TEXTAT");

    outline0("LDA YCURSYS" );
    outline1("STA %s", _y );
    outline0("LDA XCURSYS");
    outline1("STA %s", _x );

}

void c6847_initialization( Environment * _environment ) {

    deploy( c6847vars, src_hw_6847_vars_asm );
    deploy( c6847startup, src_hw_6847_startup_asm );
    // src_hw_chipset_mob_asm = src_hw_c6847_mob_asm;
    // src_hw_chipset_mob_asm_len = src_hw_c6847_mob_asm_len;

    variable_import( _environment, "CURRENTWIDTH", VT_POSITION );
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION  );
    variable_global( _environment, "CURRENTHEIGHT" );
    variable_import( _environment, "CURRENTTILESWIDTH", VT_BYTE );
    variable_global( _environment, "CURRENTTILESWIDTH" );
    variable_import( _environment, "CURRENTTILESHEIGHT", VT_BYTE );
    variable_global( _environment, "CURRENTTILESHEIGHT" );

    SCREEN_MODE_DEFINE( TILEMAP_MODE_INTERNAL, 0, 32, 16, 2, "Alphanumeric Internal");
    SCREEN_MODE_DEFINE( TILEMAP_MODE_EXTERNAL, 0, 32, 16, 2, "Alphanumeric External");
    SCREEN_MODE_DEFINE( TILEMAP_MODE_SEMIGRAPHICS4, 0, 64, 32, 8, "Semigraphics 4" );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_SEMIGRAPHICS6, 0, 64, 48, 4, "Semigraphics 6" );

    SCREEN_MODE_DEFINE( BITMAP_MODE_COLOR6, 1, 128, 192, 4, "Color Graphics 6" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_RESOLUTION6, 1, 256, 192, 2, "Resolution Graphics 6" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_RESOLUTION3, 1, 128, 192, 2, "Resolution Graphics 3" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_COLOR3, 1, 128, 96, 4, "Color Graphics 3" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_RESOLUTION2, 1, 128, 96, 2, "Resolution Graphics 2" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_COLOR2, 1, 128, 64, 4, "Color Graphics 2" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_RESOLUTION1, 1, 128, 64, 2, "Resolution Graphics 1" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_COLOR1, 1, 64, 64, 4, "Color Graphics 1" );

    outline0("JSR C6847STARTUP");

    variable_import( _environment, "XGR", VT_POSITION );
    variable_global( _environment, "XGR" );
    variable_import( _environment, "YGR", VT_POSITION );
    variable_global( _environment, "YGR" );
    variable_import( _environment, "LINE", VT_WORD );
    variable_global( _environment, "LINE" );

    variable_import( _environment, "CLIPX1", VT_POSITION );
    variable_global( _environment, "CLIPX1" );
    variable_import( _environment, "CLIPX2", VT_POSITION );
    variable_global( _environment, "CLIPX2" );
    variable_import( _environment, "CLIPY1", VT_POSITION );
    variable_global( _environment, "CLIPY1" );
    variable_import( _environment, "CLIPY2", VT_POSITION );
    variable_global( _environment, "CLIPY2" );

    c6847_cls( _environment );

}

void c6847_hscroll_line( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_6847_hscroll_text_asm );

    Variable * y = variable_retrieve( _environment, "windowCY" );
    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );
    outline1("LDA %s", y->realName );
    outline0("STA CLINEY");

    outline0("JSR HSCROLLLT");    

}

void c6847_hscroll_screen( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_6847_hscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );

    outline0("JSR HSCROLLST");    

}

void c6847_back( Environment * _environment ) {

}

void c6847_cline( Environment * _environment, char * _characters ) {

    deploy( textCline, src_hw_6847_cline_asm );
    Variable * x = variable_retrieve( _environment, "windowCX" );
    Variable * y = variable_retrieve( _environment, "windowCY" );

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


/**
 * @brief Calculate the distance between two colors
 *
 * This function calculates the color distance between two colors(_a and _b).
 * By "distance" we mean the geometric distance between two points in a 
 * three-dimensional space, where each dimension corresponds to one of the 
 * components (red, green and blue). The returned value is normalized to 
 * the nearest 8-bit value. 
 * 
 * @param _a First color 
 * @param _b Second color
 * @return int distance
 */

static int calculate_distance(RGBi e1, RGBi e2) {

    long rmean = ( (long)e1.red + (long)e2.red ) / 2;
    long r = (long)e1.red - (long)e2.red;
    long g = (long)e1.green - (long)e2.green;
    long b = (long)e1.blue - (long)e2.blue;
    return (int)( sqrt((((512+rmean)*r*r)>>8) + 4*g*g + (((767-rmean)*b*b)>>8)) );

}

/**
 * @brief Extract the color palette from the given image
 * 
 * @param _source 
 * @param _palette 
 * @param _palette_size 
 * @return int 
 */
static int extract_color_palette(unsigned char* _source, int _width, int _height, RGBi _palette[], int _palette_size) {

    RGBi rgb;

    int image_x, image_y;

    int usedPalette = 0;
    int i = 0;
    unsigned char* source = _source;

    for (image_y = 0; image_y < _height; ++image_y) {
        for (image_x = 0; image_x < _width; ++image_x) {
            rgb.red = *source;
            rgb.green = *(source + 1);
            rgb.blue = *(source + 2);

            for (i = 0; i < usedPalette; ++i) {
                if (_palette[i].red == rgb.red && _palette[i].green == rgb.green && _palette[i].blue == rgb.blue) {
                    break;
                }
            }

            if (i >= usedPalette) {
                _palette[usedPalette].red = rgb.red;
                _palette[usedPalette].green = rgb.green;
                _palette[usedPalette].blue = rgb.blue;
                ++usedPalette;
                if (usedPalette > _palette_size) {
                    break;
                }
            }
            source += 3;
        }
        if (usedPalette > _palette_size) {
            break;
        }
    }

    return usedPalette;

}

static Variable * c6847_image_converter_bitmap_mode_standard( Environment * _environment, char * _source, int _width, int _height ) {

    if ( _width % 8 ) {
        CRITICAL_IMAGE_CONVERTER_INVALID_WIDTH( _width );
    }

    if ( _height % 8 ) {
        CRITICAL_IMAGE_CONVERTER_INVALID_HEIGHT( _height );
    }

    RGBi palette[MAX_PALETTE];

    int colorUsed = extract_color_palette(_source, _width, _height, palette, MAX_PALETTE);

    if (colorUsed > 2) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( colorUsed );
    }

    int i, j, k;

    for( i=0; i<colorUsed; ++i ) {
        int minDistance = 0xffff;
        int colorIndex = 0;
        for (j = 0; j < sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++j) {
            int distance = calculate_distance(SYSTEM_PALETTE[j], palette[i]);
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
        // printf("%d) %d %2.2x%2.2x%2.2x\n", i, palette[i].index, palette[i].red, palette[i].green, palette[i].blue);
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
 
    int bufferSize = 2 + ( ( _width >> 3 ) * _height );
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

    *(buffer) = _width;
    *(buffer+1) = _height;

    // Loop for all the source surface.
    for (image_y = 0; image_y < _height; ++image_y) {
        for (image_x = 0; image_x < _width; ++image_x) {

            // Take the color of the pixel
            rgb.red = *_source;
            rgb.green = *(_source + 1);
            rgb.blue = *(_source + 2);

            for( i=0; i<colorUsed; ++i ) {
                if ( palette[i].red == rgb.red && palette[i].green == rgb.green && palette[i].blue == rgb.blue ) {
                    break;
                }
            }

            // printf("%d", i );

            // Calculate the offset starting from the tile surface area
            // and the bit to set.
            offset = ( image_y * ( _width >> 3 ) ) + ( image_x >> 3 );
            bitmask = 1 << ( 7 - (image_x & 0x7) );

            // If the pixes has enough luminance value, it must be 
            // considered as "on"; otherwise, it is "off".
            // int luminance = calculate_luminance(rgb);

            if ( i == 1 ) {
                *( buffer + offset + 2) |= bitmask;
                printf("*");
            } else {
                *( buffer + offset + 2) &= ~bitmask;
                printf(" ");
            }

            _source += 3;

        }

        printf("\n" );

    }

    // printf("----\n");

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    // printf("----\n");

    return result;

}

static Variable * c6847_image_converter_multicolor_mode_standard( Environment * _environment, char * _source, int _width, int _height ) {

    if ( _width % 8 ) {
        CRITICAL_IMAGE_CONVERTER_INVALID_WIDTH( _width );
    }

    if ( _height % 8 ) {
        CRITICAL_IMAGE_CONVERTER_INVALID_HEIGHT( _height );
    }

    RGBi palette[MAX_PALETTE];

    int colorUsed = extract_color_palette(_source, _width, _height, palette, MAX_PALETTE);

    if (colorUsed > 4) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( colorUsed );
    }

    int i, j, k;

    for( i=0; i<colorUsed; ++i ) {
        int minDistance = 0xffff;
        int colorIndex = 0;
        for (j = 0; j < sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++j) {
            int distance = calculate_distance(SYSTEM_PALETTE[j], palette[i]);
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
        // printf("%d) %d %2.2x%2.2x%2.2x\n", i, palette[i].index, palette[i].red, palette[i].green, palette[i].blue);
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
 
    int bufferSize = 2 + ( ( _width >> 2 ) * _height );
    
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

    // Loop for all the source surface.
    for (image_y = 0; image_y < _height; ++image_y) {
        for (image_x = 0; image_x < _width; ++image_x) {

            // Take the color of the pixel
            rgb.red = *_source;
            rgb.green = *(_source + 1);
            rgb.blue = *(_source + 2);

            offset = ( image_y * ( _width >> 2 ) ) + ( image_x >> 2 );

            int minDistance = 0xffff;
            int colorIndex = 0;

            for( i=0; i<colorUsed; ++i ) {
                if ( palette[i].red == rgb.red && palette[i].green == rgb.green && palette[i].blue == rgb.blue ) {
                    break;
                }
            }

            colorIndex = i;

            // printf( "%1.1x", colorIndex );

            bitmask = colorIndex << (6 - ((image_x & 0x3) * 2));

            *(buffer + 2 + offset) |= bitmask;

            _source += 3;

        }

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

Variable * c6847_image_converter( Environment * _environment, char * _data, int _width, int _height, int _mode ) {

    switch( _mode ) {
        case TILEMAP_MODE_INTERNAL:         // Alphanumeric Internal	32 × 16	2	512
        case TILEMAP_MODE_EXTERNAL:         // Alphanumeric External	32 × 16	2	512
        case TILEMAP_MODE_SEMIGRAPHICS4:    // Semigraphics 4	        64 × 32	8	512
        case TILEMAP_MODE_SEMIGRAPHICS6:    // Semigraphics 6	        64 × 48	4	512
        case TILEMAP_MODE_SEMIGRAPHICS8:    // Semigraphics 8	        64 × 64	2	512
        case TILEMAP_MODE_SEMIGRAPHICS12:    // Semigraphics 6	        64 × 96 1	3072
        case TILEMAP_MODE_SEMIGRAPHICS24:    // Semigraphics 6	        64 × 96 1	3072
            break;
        case BITMAP_MODE_COLOR1:            // Color Graphics 1	64 × 64	4	1024
        case BITMAP_MODE_COLOR2:            // Color Graphics 2	128 × 64	4	2048
        case BITMAP_MODE_COLOR3:            // Color Graphics 3	128 × 96	4	3072
        case BITMAP_MODE_COLOR6:            // Color Graphics 6	128 × 192	4	6144

            return c6847_image_converter_multicolor_mode_standard( _environment, _data, _width, _height );
            break;

        case BITMAP_MODE_RESOLUTION1:       // Resolution Graphics 1	128 × 64	1 + Black	1024
        case BITMAP_MODE_RESOLUTION2:       // Resolution Graphics 2 128 × 96	1 + Black	1536
        case BITMAP_MODE_RESOLUTION3:       // Resolution Graphics 3	128 × 192	1 + Black	3072
        case BITMAP_MODE_RESOLUTION6:       // Resolution Graphics 6	256 × 192	1 + Black	6144            break;

            return c6847_image_converter_bitmap_mode_standard( _environment, _data, _width, _height );

    }

    CRITICAL_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

}

void c6847_put_image( Environment * _environment, char * _image, char * _x, char * _y ) {

    deploy( c6847vars, src_hw_6847_vars_asm);
    deploy( image, src_hw_6847_image_asm );

    outline1("LDY #%s", _image );
    outline1("LDD %s", _x );
    outline0("STD IMAGEX" );
    outline1("LDD %s", _y );
    outline0("STD IMAGEY" );

    outline0("JSR PUTIMAGE");
    
}

#endif