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

#if defined(__atari__) || defined(__atarixl__)

#include "../ugbc.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
        { 0x00, 0x00, 0x00, 0, "BLACK" },        
        { 0xff, 0xff, 0xff, 0x0f, "WHITE" },
        { 0x88, 0x00, 0x00, 0x27, "RED" },
        { 0xaa, 0xff, 0xe6, 3, "CYAN" },
        { 0xcc, 0x44, 0xcc, 0x44, "VIOLET" },
        { 0x00, 0xcc, 0x55, 0xa2, "GREEN" },
        { 0x00, 0x00, 0xaa, 0x62, "BLUE" },
        { 0xee, 0xee, 0x77, 0xda, "YELLOW" },
        { 0xa1, 0x68, 0x3c, 0x2a, "ORANGE" },
        { 0xdd, 0x88, 0x65, 0x14, "BROWN" },
        { 0xff, 0x77, 0x77, 0x2f,"LIGHT RED" },
        { 0x33, 0x33, 0x33, 0x04, "DARK GREY" },
        { 0x77, 0x77, 0x77, 0x08, "GREY" },
        { 0xaa, 0xff, 0x66, 0xa8, "LIGHT GREEN" },
        { 0x00, 0x88, 0xff, 0x68, "LIGHT BLUE" },
        { 0xbb, 0xbb, 0xbb, 0x0b, "LIGHT GREY" },
        { 0xf9, 0x84, 0xe5, 0x1e, "MAGENTA" },
        { 0xdc, 0xd0, 0xff, 0x55, "LAVENDER" },
        { 0xFF, 0xd7, 0x00, 0xd6, "GOLD" },
        { 0x40, 0xe0, 0xd0, 0x78, "TURQUOISE" },
        { 0xdc, 0xca, 0x98, 0x65, "TAN" },
        { 0x9a, 0xcd, 0x32, 0xaa, "YELLOW GREEN" },
        { 0x4b, 0x53, 0x20, 0xa6, "OLIVE GREEN" },
        { 0xff, 0xc0, 0xcb, 0x3a, "PINK" },
        { 0xff, 0xcb, 0xa4, 0x38, "PEACH" },
        { 0x00, 0xff, 0xff, 0x6a, "CYAN" },
        { 0x00, 0x00, 0x80, 0x60, "DARK BLUE" }
};

static RGBi * commonPalette;
int lastUsedSlotInCommonPalette = 0;

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

void gtia_collision( Environment * _environment, char * _sprite_mask, char * _result ) {

}

void gtia_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

}

/**
 * @brief <i>GTIA</i>: emit code to change border color
 * 
 * This function can be used to issue code aimed at changing the
 * border color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _border_color Border color to use
 */
void gtia_border_color( Environment * _environment, char * _border_color ) {

    outline1("LDA %s", _border_color );
    outline0("STA $02c8");

}

/**
 * @brief <i>GTIA</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void gtia_background_color( Environment * _environment, int _index, int _background_color ) {
 
    outline1("LDA #$%2.2x", _background_color );
    outline0("AND #$0f" );
    outline1("STA $02C5+%d", (_index & 0x07) )

}

/**
 * @brief <i>GTIA</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void gtia_background_color_vars( Environment * _environment, char * _index, char * _background_color ) {
 
    outline1("LDA %s", _index);
    outline0("AND #$07");
    outline0("TAX");
    outline1("LDA %s", _background_color );
    outline0("AND #$0f" );
    outline0("STA $02C5,X")

}

/**
 * @brief <i>GTIA</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void gtia_background_color_semivars( Environment * _environment, int _index, char * _background_color ) {
 
    outline1("LDA #$%2.2x", _index);
    outline0("AND #$07");
    outline0("TAX");
    outline1("LDA %s", _background_color );
    outline0("AND #$0f" );
    outline0("STA $02C5,X")

}

/**
 * @brief <i>GTIA</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void gtia_background_color_get_vars( Environment * _environment, char * _index, char * _background_color ) {
 
    outline1("LDA %s", _index);
    outline0("AND #$07");
    outline0("TAX");
    outline0("LDA $02C5,X")
    outline0("AND #$0f" );
    outline1("STA %s", _background_color );

}

void gtia_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {

}

void gtia_enable_ecm( Environment * _environment ) {

}

void gtia_disable_ecm( Environment * _environment ) {

}

void gtia_enable_mcm( Environment * _environment ) {

}

void gtia_disable_mcm( Environment * _environment ) {

}

void gtia_bank_select( Environment * _environment, int _bank ) {

}

static int rgbConverterFunction( int _red, int _green, int _blue ) {
    
    int j;

    RGBi rgb;
    rgb.red = _red;
    rgb.green = _green;
    rgb.blue = _blue;

    double r = (double)rgb.red / (double)255;
    double g = (double)rgb.green / (double)255;
    double b = (double)rgb.blue / (double)255;

    double max = max_of_three(r, g, b);
    double min = min_of_three(r, g, b);
    double h = 0, l = 0;

    l = (0.2126*(rgb.red) + 0.7152*(rgb.green) + 0.0722*(rgb.blue));

    if ( (max-min) == 0 ) {
        h = 0;
    } else {
        if ( max == r ) {
            h = (g-b)/(max-min);
        } else if ( max == g ) {
            h = 2.0f + (b-r)/(max-min);
        } else if ( max == b ) {
            h = 4.0f + (r-g)/(max-min);
        } else {
            h = 0;
        }
    }

    return ( (((int)h)& 0x0f ) <<4 ) | ( (((int)l)& 0x0f )) ;
    
}

int gtia_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    int i;
    int screenMemoryOffset = 0;
    int screenMemoryOffset2 = 0;
    int currentHeight = 0;
    int scanline = 0;
    int dliListStartOffset;

    deploy( gtiavars, src_hw_gtia_vars_asm );
    
    unsigned char * dliListStart = malloc( DLI_COUNT ), * dliListCurrent = dliListStart;
    
    Variable * dli = variable_retrieve_or_define( _environment, "DLI", VT_BUFFER, 0 );

    _environment->fontWidth = 8;
    _environment->fontHeight = 8;

    _environment->screenShades = 256;
    _environment->screenTiles = 255;

    switch( _screen_mode->id ) {
        // Graphics 3 (ANTIC 8)
        // This four-color graphics mode turns a split screen into 20 rows of 40 graphics cells or pixels. 
        // Each pixel is 8 x 8 or the size of a normal character. The data in each pixel is encoded as two bit pairs, 
        // four per byte. The four possible bit pair combinations 00, 01, 10, and 11 point to one of the four color registers. 
        // The bits 00 is assigned to the background color register and the rest refer to the three foreground color registers. 
        // When the CTIA/GTIA chip interprets the data for the four adjacent pixels stored within the byte, it refers to the color 
        // register encoded in the bit pattern to plot the color.        
        // 40x20, 4 colors
        case BITMAP_MODE_ANTIC8:
            _environment->screenWidth = 40;
            _environment->screenHeight = 24;
            _environment->screenColors = 4;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 72	\Display ANTIC mode 8 (BASIC 3) 64+8
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 8, 0xA000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<23; ++i ) {
                // 8	\Display ANTIC mode 8 for second mode line
                DLI_MODE( dliListCurrent, 8 );
            }

            DLI_IRQ( dliListCurrent, 8 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=0xA000 - (dliListCurrent - dliListStart) - 16
            DLI_JVB( dliListCurrent, dli->absoluteAddress );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            scanline = 10;
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 40 );
            cpu_store_8bit( _environment, "CURRENTSL", scanline );
            
            break;        

        // Graphics 4 (ANTIC 9)
        // This is a two-color graphics mode with four times the resolution of GRAPHICS 3. The pixels are 4 x 4, and 48 rows of 80 
        // pixels fit on a full screen. A single bit is used to store each pixel's color register. A zero refers to the background 
        // color register and a one to the foreground color register. The mode is used primarily to conserve screen memory. 
        // Only one bit is used for the color, so eight adjacent pixels are encoded within one byte, and only half as much screen 
        // memory is needed for a display of similiar-sized pixels.
        // 80x48, 2 colors
        case BITMAP_MODE_ANTIC9:
            _environment->screenWidth = 80;
            _environment->screenHeight = 48;
            _environment->screenColors = 2;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 72	\Display ANTIC mode 9 (BASIC 3) 64+9
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 9, 0xA000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<47; ++i ) {
                // 8	\Display ANTIC mode 9 for second mode line
                DLI_MODE( dliListCurrent, 9 );
            }

            DLI_IRQ( dliListCurrent, 9 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=0xA000 - (dliListCurrent - dliListStart) - 16
            DLI_JVB( dliListCurrent, dli->absoluteAddress );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            scanline = 10;
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 40 );
            cpu_store_8bit( _environment, "CURRENTSL", scanline );
            break;

        // Graphics 5 (ANTIC A or 10)
        // This is the four color equivalent of GRAPHICS 4 sized pixels. The pixels are 4 x 4, but two bits are required to address 
        // the four color registers. With only four adjacent pixels encoded within a byte, the screen uses twice as much memory, 
        // about 1K.
        // 80x48, 4 colors
        case BITMAP_MODE_ANTIC10:
            _environment->screenWidth = 80;
            _environment->screenHeight = 48;
            _environment->screenColors = 4;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 74	\Display ANTIC mode 10 (BASIC 5) 64+10
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 10, 0xA000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<47; ++i ) {
                // 8	\Display ANTIC mode 10 for second mode line
                DLI_MODE( dliListCurrent, 10 );
            }

            DLI_IRQ( dliListCurrent, 10 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=0xA000 - (dliListCurrent - dliListStart) - 16
            DLI_JVB( dliListCurrent, 0xA000 - (dliListCurrent - dliListStart) - 16 );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            currentHeight = 48;
            scanline = 20;
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 40 );
            cpu_store_8bit( _environment, "CURRENTSL", scanline );
            break;

        // Graphics 6 (ANTIC B or 11)
        // This two color graphics mode has reasonably fine resolution. The 2 x 2 sized pixels allow 96 rows of 160 pixels to fit 
        // on a full screen. Although only a single bit is used to encode the color, screen memory still requires approximately 2K.
        // 160x96, 2 colors
        case BITMAP_MODE_ANTIC11: 
            _environment->screenWidth = 160;
            _environment->screenHeight = 96;
            _environment->screenColors = 2;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 75	\Display ANTIC mode 11 (BASIC 8) 64+11
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 11, 0xA000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<95; ++i ) {
                // 8	\Display ANTIC mode 11 for second mode line
                DLI_MODE( dliListCurrent, 11 );
            }

            DLI_IRQ( dliListCurrent, 10 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=0xA000 - (dliListCurrent - dliListStart) - 16
            DLI_JVB( dliListCurrent, dli->absoluteAddress );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            currentHeight = 96;
            scanline = 20;
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 40 );
            cpu_store_8bit( _environment, "CURRENTSL", scanline );
        break;

        // Graphics 7 (ANTIC D or 13)
        // This is the four color equivalent to GRAPHICS mode 6. It is the finest resolution four color mode and naturally the
        // most popular. The color is encoded in two bit-pairs exactly the same way as in GRAPHICS 3. The memory requirements 
        // of course is much greater as there are 96 rows of 160 - 2 x 2 sized pixels. It requires 3840 bytes of screen memory
        // with another 104 bytes for the display list.
        // 160x96, 4 colors
        case BITMAP_MODE_ANTIC13:
            _environment->screenWidth = 160;
            _environment->screenHeight = 96;
            _environment->screenColors = 4;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 77	\Display ANTIC mode 13 (BASIC 7) 64+13
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 13, 0xA000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<(96+16); ++i ) {
                // 8	\Display ANTIC mode 13 for second mode line
                DLI_MODE( dliListCurrent, 13 );
            }

            DLI_IRQ( dliListCurrent, 13 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=0xA000 - (dliListCurrent - dliListStart) - 16
            DLI_JVB( dliListCurrent, 0xA000 - (dliListCurrent - dliListStart) );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            currentHeight = 96;
            scanline = 40;
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 40 );
            cpu_store_8bit( _environment, "CURRENTSL", scanline );
        break;

        // Graphics 8 (ANTIC F or 15)
        // This mode is definitely the finest resolution available on the Atari. Individual dot-sized pixels can be addressed in 
        // this one-color, two-luminance mode. There are 192 rows of 320 dots in the full screen mode. Graphics 8 is memory 
        // intensive; it takes 8K bytes (eight pixels/byte) to address an entire screen. The color scheme is quite similar to that 
        // in GRAPHICS mode 0. Color register #2 sets the background color. Color register #1 sets the luminance. Changing the color
        // in this register has no effect, but, this doesn't mean that you are limited to just one color.
        // Fortunately, the pixels are each one half of a color clock. It takes two pixels to span one color clock made up of
        // alternating columns of complementary colors. If the background is set to black, these columns consist of blue and 
        // green stripes. If only the odd-columned pixels are plotted, you get blue pixels. If only the odd-columned pixels 
        // are plotted, you get green pixels. And if pairs of adjacent pixels are plotted, you get white. So by cleverly 
        // staggering the pixel patterns, you can achieve three colors. This method is called artifacting. This all depends
        // on background color and luminance.
        // 320x192, 3 colors
        case BITMAP_MODE_ANTIC15:
            _environment->screenWidth = 320;
            _environment->screenHeight = 192;
            _environment->screenColors = 2;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 81	\Display ANTIC mode 15 (BASIC 7) 64+15
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 15, 0xA000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<96; ++i ) {
                // 8	\Display ANTIC mode 15 for second mode line
                DLI_MODE( dliListCurrent, 15 );
            }

            DLI_LMS( dliListCurrent, 15, 0xA000 + 40 * 96 );

            screenMemoryOffset2 = dliListCurrent - dliListStart - 2;

            for( i=0; i<95; ++i ) {
                // 8	\Display ANTIC mode 15 for second mode line
                DLI_MODE( dliListCurrent, 15 );
            }

            DLI_IRQ( dliListCurrent, 15 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=0xA000 - (dliListCurrent - dliListStart) - 16
            DLI_JVB( dliListCurrent, dli->absoluteAddress );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            scanline = 40;
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 40 );
            cpu_store_8bit( _environment, "CURRENTSL", scanline );
        break;
            
        // The following five graphics modes have no equivalent in BASIC on older machine but if indicated do correspond to
        // an equivalent graphics mode on the newer XL models.

        // Antic C (Graphics 14-XL computers only)
        // This two-color, bit-mapped mode the eight bits correspond directly to the pixels on the screen. If a pixel is lit 
        // it receives its color information from color register #0, otherwise the color is set to the background color 
        // register #4. Each pixel is one scan line high and one color clock wide. This mode's advantages are that it 
        // only uses 4K of screen memory and doesn't have artifacting problems.
        // 320x192, 2 colors
        case BITMAP_MODE_ANTIC12:
            _environment->screenWidth = 320;
            _environment->screenHeight = 192;
            _environment->screenColors = 2;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 76	\Display ANTIC mode 12 64+12
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 12, 0xA000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<191; ++i ) {
                // 8	\Display ANTIC mode 15 for second mode line
                DLI_MODE( dliListCurrent, 12 );
            }

            DLI_IRQ( dliListCurrent, 12 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=0xA000 - (dliListCurrent - dliListStart) - 16
            DLI_JVB( dliListCurrent, dli->absoluteAddress );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            scanline = 40;
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 40 );
            cpu_store_8bit( _environment, "CURRENTSL", scanline );
            break;

        // Antic E (Graphics 15-XL computers only)
        // This four-color, bit-mapped mode is sometimes known as BASIC 7 1/2. Its resolution is 160 x 192 or twice that of 
        // GRAPHIC 7. Each byte is divided into four pairs of bits. Like the character data in ANTIC 4, the bit pairs point to a
        // particular color register. The screen data, however, is not character data but individual bytes. The user has a lot
        // more control, but this mode uses a lot more memory, approximately
        // 160x192, 4 colors
        case BITMAP_MODE_ANTIC14:
            _environment->screenWidth = 160;
            _environment->screenHeight = 192;
            _environment->screenColors = 4;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 76	\Display ANTIC mode 12 64+14
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 14, 0xA000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<191; ++i ) {
                // 8	\Display ANTIC mode 15 for second mode line
                DLI_MODE( dliListCurrent, 14 );
            }

            DLI_IRQ( dliListCurrent, 14 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=0xA000 - (dliListCurrent - dliListStart) - 16
            DLI_JVB( dliListCurrent, dli->absoluteAddress );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            scanline = 20;
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 40 );
            cpu_store_8bit( _environment, "CURRENTSL", scanline );
            break;

        // Graphics Mode 0 (ANTIC 2)
        // This is the normal-sized character or text mode that the computer defaults to on start up. 
        // Being a character mode, screen memory consists of bytes that represent individual characters in either the 
        // ROM or a custom character set. ANTIC displays forty of these 8 x 8 sized characters on each of 
        // twenty-four lines. Graphics 0 is a 1 1/2 color mode. Color register #2 is used as the background color 
        // register. Color register #1 sets the luminance of the characters against the background. Setting the 
        // color has no effect. Bits within a character are turned on in pairs to produce the luminace color. 
        // Otherwise single bits tend to produce colored artifacts on the high resolution screen. These colors
        // depend on whether the computer has a CTIA or GTIA chip, and the color of the background.
        // 40x24, 1 color
        case TILEMAP_MODE_ANTIC2:
            _environment->screenWidth = 40 * _environment->fontWidth;
            _environment->screenHeight = 24 * _environment->fontHeight;
            _environment->screenColors = 2;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 66	\Display ANTIC mode 2 (BASIC 0) 64+2
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 2, 40000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for(i=1; i<23; ++i ) {
                // 2	\Display ANTIC mode 2 for second mode line
                DLI_MODE( dliListCurrent, 2 );
            }

            DLI_IRQ( dliListCurrent, 2 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=0xA000 - (dliListCurrent - dliListStart) - 16
            DLI_JVB( dliListCurrent, dli->absoluteAddress );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 152 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 192 );
            cpu_store_8bit( _environment, "CURRENTSL", scanline );
            break;

        // Graphics 1 (ANTIC 6)
        // This is one the expanded text modes. Each characters is 8 x 8 but the pixels are one color clock in 
        // width instead of the 1/2 color clock mode of Graphics 0 making the characters twice as wide. Only twenty 
        // characters fit on any line. A graphics 1 screen has twenty rows while the full screen mode has twenty-four 
        // rows of characters. The two high bits of each ATASCII character, that normally identify lowercase or 
        // inverse video text in Graphics 1, set the color register for the 64 character set. Decimal character
        // numbers 0-63 use color register zero, while those same 64 characters if given character numbers 64-127 
        // use color register #1. If you are typing from the Atari keyboard, the uppercase letters A-Z ATASCII 65-90
        // (Internal # 33-58) are assigned to color register zero, while the lowercase numbers 97-122 
        // (Internal # 97-122) are signed to register #1.
        // 20x24, 4 color
        case TILEMAP_MODE_ANTIC6:
            _environment->screenWidth = 20 * _environment->fontWidth;
            _environment->screenHeight = 24 * _environment->fontHeight;
            _environment->screenColors = 2;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 66	\Display ANTIC mode 2 (BASIC 0) 64+2
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 6, 40000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for(i=1; i<23; ++i ) {
                // 2	\Display ANTIC mode 2 for second mode line
                DLI_MODE( dliListCurrent, 6 );
            }

            DLI_IRQ( dliListCurrent, 6 );
            
            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=0xA000 - (dliListCurrent - dliListStart) - 16
            DLI_JVB( dliListCurrent, dli->absoluteAddress );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 204 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 224 );
            cpu_store_8bit( _environment, "CURRENTSL", scanline );
            break;

        // Graphics 2 (ANTIC 7)
        // This text mode is basically the same as the previous mode except that each row of pixels is two scan lines high.
        // Thus 12 rows of 20 characters are displayed on a full screen. Only ten rows fit on a split screen.
        // 20x12, 4 color
        case TILEMAP_MODE_ANTIC7:
            _environment->screenWidth = 20 * _environment->fontWidth;
            _environment->screenHeight = 12 * _environment->fontHeight;
            _environment->screenColors = 2;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 71	\Display ANTIC mode 2 (BASIC 0) 64+7
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 7, 40000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for(i=1; i<11; ++i ) {
                // 2	\Display ANTIC mode 2 for second mode line
                DLI_MODE( dliListCurrent, 7 );
            }

            DLI_IRQ( dliListCurrent, 7 );
            
            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=0xA000 - (dliListCurrent - dliListStart) - 16
            DLI_JVB( dliListCurrent, dli->absoluteAddress );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 204 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 224 );
            cpu_store_8bit( _environment, "CURRENTSL", scanline );
            break;

        // Antic 3
        // This rarely used text mode is sometimes called the lowercase descenders mode. Each of the forty characters per line
        // are ten scan lines high, but since each of the characters are only eight scan lines high, the lower two scan lines are
        // normally left empty. However, if you use the last quarter of the character set, the top two lines remain blank, 
        // allowing you to create lowercase characters with descenders.
        // 40x24, 4 color
        case TILEMAP_MODE_ANTIC3:
            _environment->screenWidth = 40 * _environment->fontWidth;
            _environment->screenHeight = 24 * _environment->fontHeight;
            _environment->screenColors = 2;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 66	\Display ANTIC mode 2 (BASIC 0) 64+2
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 3, 40000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for(i=1; i<23; ++i ) {
                // 2	\Display ANTIC mode 2 for second mode line
                DLI_MODE( dliListCurrent, 3 );
            }

            DLI_IRQ( dliListCurrent, 3 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=0xA000 - (dliListCurrent - dliListStart) - 16
            DLI_JVB( dliListCurrent, dli->absoluteAddress );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 152 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 192 );
            cpu_store_8bit( _environment, "CURRENTSL", scanline );
            break;
        
        // Antic 4 (Graphics 12-XL computers only)
        // This very powerful character graphics mode supports four colors while using relatively little screen memory (1 K). 
        // In addition its 4 x 8 sized characters have the same horizontal resolution as GRAPHICS 7, yet twice the vertical resolution.
        // A large number of games with colorful and detailed playfields use this mode. These characters differ considerably from 
        // ANTIC 6 (BASIC 2) characters, in that each character contains pixels of four different colors, not just a choice of one color
        // determined by the character number. Each byte in the character is broken into four bit pairs, each of which selects the color
        // register for the pixel. That is why the horizontal resolution is only four bits. A special character set generator is used
        // to form these characters.
        // 20x24, 4 color
        case TILEMAP_MODE_ANTIC4:
            _environment->screenWidth = 20 * _environment->fontWidth;
            _environment->screenHeight = 24 * _environment->fontHeight;
            _environment->screenColors = 4;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 66	\Display ANTIC mode 2 (BASIC 0) 64+2
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 4, 40000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for(i=1; i<23; ++i ) {
                // 2	\Display ANTIC mode 2 for second mode line
                DLI_MODE( dliListCurrent, 4 );
            }

            DLI_IRQ( dliListCurrent, 4 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=0xA000 - (dliListCurrent - dliListStart) - 16
            DLI_JVB( dliListCurrent, dli->absoluteAddress );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 152 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 192 );
            cpu_store_8bit( _environment, "CURRENTSL", scanline );
        break;

        // Antic 5 (Graphics 13-XL computers only)
        // This mode is essentially the same as ANTIC 4 except that each character is sixteen scan lines high. 
        // The character set data is still eight bytes high so ANTIC double plots each scan line.
        // 20x24, 4 color  
        case TILEMAP_MODE_ANTIC5:
            _environment->screenWidth = 20 * _environment->fontWidth;
            _environment->screenHeight = 24 * _environment->fontHeight;
            _environment->screenColors = 4;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 66	\Display ANTIC mode 2 (BASIC 0) 64+2
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 5, 40000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for(i=1; i<23; ++i ) {
                // 2	\Display ANTIC mode 2 for second mode line
                DLI_MODE( dliListCurrent, 5 );
            }

            DLI_IRQ( dliListCurrent, 5 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=0xA000 - (dliListCurrent - dliListStart) - 16
            DLI_JVB( dliListCurrent, dli->absoluteAddress );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 152 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 192 );
            cpu_store_8bit( _environment, "CURRENTSL", scanline );
            break;

        default:
            CRITICAL_SCREEN_UNSUPPORTED( _screen_mode->id );
    }

    cpu_store_16bit( _environment, "CURRENTWIDTH", _environment->screenWidth );
    cpu_store_16bit( _environment, "CURRENTHEIGHT", _environment->screenHeight );
    cpu_store_8bit( _environment, "CURRENTTILES", _environment->screenTiles );
    _environment->screenTilesWidth = _environment->screenWidth / _environment->fontWidth;
    cpu_store_8bit( _environment, "CURRENTTILESWIDTH", _environment->screenTilesWidth );
    _environment->screenTilesHeight = _environment->screenHeight / _environment->fontHeight;
    cpu_store_8bit( _environment, "CURRENTTILESHEIGHT", _environment->screenTilesHeight );

    cpu_store_16bit( _environment, "CLIPX1", 0) ;
    cpu_store_16bit( _environment, "CLIPY2", 0) ;
    cpu_move_16bit( _environment, "CURRENTWIDTH", "CLIPX2");
    cpu_move_16bit( _environment, "CURRENTHEIGHT", "CLIPY2");

    variable_store_buffer( _environment, dli->name, dliListStart, ( dliListCurrent - dliListStart ), dli->absoluteAddress );

    if ( _screen_mode->bitmap ) {
        outline0("CLC" );
        outline1("LDA #<%s", dli->realName );
        outline1("ADC #%d", ( screenMemoryOffset & 0xff ) );
        outline0("STA TMPPTR" );
        outline1("LDA #>%s", dli->realName );
        outline1("ADC #%d", ( ( screenMemoryOffset >> 8 ) & 0xff ) );
        outline0("STA TMPPTR+1" );
        outline0("LDY #0" );

        outline0("LDA BITMAPADDRESS" );
        outline0("STA (TMPPTR),Y" );
        outline0("INY" );
        outline0("LDA BITMAPADDRESS+1" );
        outline0("STA (TMPPTR),Y" );

        if ( screenMemoryOffset2 ) {
            outline0("CLC" );
            outline1("LDA #<%s", dli->realName );
            outline1("ADC #%d", ( screenMemoryOffset2 & 0xff ) );
            outline0("STA TMPPTR" );
            outline1("LDA #>%s", dli->realName );
            outline1("ADC #%d", ( ( screenMemoryOffset2 >> 8 ) & 0xff ) );
            outline0("STA TMPPTR+1" );
            outline0("LDY #0" );

            outline0("CLC" );
            outline0("LDA BITMAPADDRESS" );
            outline1("ADC %d", ( currentHeight/2 ) * scanline );
            outline0("STA (TMPPTR),Y" );
            outline0("INY" );
            outline0("LDA BITMAPADDRESS+1" );
            outline1("ADC %d", ( currentHeight/2 ) * scanline );
            outline0("STA (TMPPTR),Y" );

        }
    } else {
        outline0("CLC" );
        outline1("LDA #<%s", dli->realName );
        outline1("ADC #%d", ( screenMemoryOffset & 0xff ) );
        outline0("STA TMPPTR" );
        outline1("LDA #>%s", dli->realName );
        outline1("ADC #%d", ( ( screenMemoryOffset >> 8 ) & 0xff ) );
        outline0("STA TMPPTR+1" );
        outline0("LDY #0" );

        outline0("LDA TEXTADDRESS" );
        outline0("STA (TMPPTR),Y" );
        outline0("INY" );
        outline0("LDA TEXTADDRESS+1" );
        outline0("STA (TMPPTR),Y" );

    }

    outline0("CLC" );
    outline1("LDA #<%s", dli->realName );
    outline1("ADC #%d", ( dliListStartOffset & 0xff ) );
    outline0("STA TMPPTR" );
    outline1("LDA #>%s", dli->realName );
    outline1("ADC #%d", ( ( dliListStartOffset >> 8 ) & 0xff ) );
    outline0("STA TMPPTR+1" );
    outline0("LDY #0" );

    outline1("LDA #<%s", dli->realName );
    outline0("STA (TMPPTR),Y" );
    outline0("INY" );
    outline1("LDA #>%s", dli->realName );
    outline0("STA (TMPPTR),Y" );

    cpu_store_8bit( _environment, "_PEN", 0x10 );
    cpu_store_8bit( _environment, "_PAPER", 0x00 );

    outline0("SEI" );
    outline1("LDA #<%s", dli->realName );
    outline0("STA $230" );
    outline1("LDA #>%s", dli->realName );
    outline0("STA $231" );
    outline0("CLI" );

}

void gtia_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {
    
    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors );

    if ( mode ) {
        gtia_screen_mode_enable( _environment, mode );
        // printf( "%d\n", mode->id);
        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );    
        _environment->currentMode = mode->id;
    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void gtia_bitmap_disable( Environment * _environment ) {

}

void gtia_tilemap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors );

    if ( mode ) {
        gtia_screen_mode_enable( _environment, mode );

        cpu_store_8bit( _environment, "_PEN", 0x01 );
        cpu_store_8bit( _environment, "_PAPER", 0x00 );

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );

        _environment->currentMode = mode->id;
    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void gtia_bitmap_at( Environment * _environment, char * _address ) {

}

void gtia_colormap_at( Environment * _environment, char * _address ) {

}

void gtia_textmap_at( Environment * _environment, char * _address ) {

}

void gtia_point_at_int( Environment * _environment, int _x, int _y ) {

    deploy( gtiavars, src_hw_gtia_vars_asm );
    deploy( plot, src_hw_gtia_plot_asm );
    
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

void gtia_point_at_vars( Environment * _environment, char *_x, char *_y ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy( gtiavars, src_hw_gtia_vars_asm );
    deploy( plot, src_hw_gtia_plot_asm );
    
    outline1("LDA %s", x->realName );
    outline0("STA PLOTX");
    outline1("LDA %s+1", x->realName );
    outline0("STA PLOTX+1");
    outline1("LDA %s", y->realName );
    outline0("STA PLOTY");
    outline0("LDA #1");
    outline0("STA PLOTM");
    outline0("JSR PLOT");

}

void gtia_point( Environment * _environment, char *_x, char *_y, char * _result ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );
    Variable * result = variable_retrieve( _environment, _result );

    deploy( gtiavars, src_hw_gtia_vars_asm );
    deploy( plot, src_hw_gtia_plot_asm );
    
    outline1("LDA %s", x->realName );
    outline0("STA PLOTX");
    outline1("LDA %s+1", x->realName );
    outline0("STA PLOTX+1");
    outline1("LDA %s", y->realName );
    outline0("STA PLOTY");
    outline0("LDA #3");
    outline0("STA PLOTM");
    outline0("JSR PLOT");
    outline0("LDA PLOTM");
    outline1("STA %s", result->realName);

}

void gtia_screen_on( Environment * _environment ) {

}

void gtia_screen_off( Environment * _environment ) {
    
}

void gtia_screen_rows( Environment * _environment, char * _rows ) {

}

void gtia_sprite_data_from( Environment * _environment, char * _sprite, char * _address ) {

}

void gtia_sprite_enable( Environment * _environment, char * _sprite ) {

}

void gtia_sprite_disable( Environment * _environment, char * _sprite ) {

}

void gtia_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

}

void gtia_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

}

void gtia_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

}

void gtia_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

}

void gtia_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

}

void gtia_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void gtia_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void gtia_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

}

void gtia_tiles_at( Environment * _environment, char * _address ) {

}

void gtia_vertical_scroll( Environment * _environment, char * _displacement ) {

}

void gtia_horizontal_scroll( Environment * _environment, char * _displacement ) {

}

void gtia_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline0("LDA #$00");
    outline0("STA TMPPTR");
    outhead1("%sfirst:", label );
    outline0("LDA $14");
    outhead1("%ssecond:", label );
    outline0("CMP $14");
    outline1("BEQ %ssecond", label);
    outline0("INC TMPPTR");
    outline0("LDA TMPPTR");
    outline1("CMP %s", _timing );
    outline1("BNE %sfirst", label );

}

void gtia_get_width( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTWIDTH" );
    outline1("STA %s", _result );
    outline0("LDA CURRENTWIDTH+1" );
    outline1("STA %s+1", _result );

}

void gtia_tiles_get_width( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILESWIDTH" );
    outline1("STA %s", _result );

}

void gtia_get_height( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTHEIGHT" );
    outline1("STA %s", _result );
    outline0("LDA CURRENTHEIGHT+1" );
    outline1("STA %s+1", _result );

}

void gtia_tiles_get( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILES" );
    outline1("STA %s", _result );

}

void gtia_tiles_get_height( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILESHEIGHT" );
    outline1("STA %s", _result );

}

void gtia_cls( Environment * _environment ) {
    
    deploy( cls, src_hw_gtia_cls_asm );

    outline0("LDA #$0");
    outline0("STA PATTERN");
    outline0("JSR CLS");

}

void gtia_clear( Environment * _environment, char * _pattern ) {
    
    deploy( cls, src_hw_gtia_cls_asm );

    outline1("LDA %s", _pattern );
    outline0("STA PATTERN");
    outline0("JSR CLS");

}

void gtia_scroll_text( Environment * _environment, int _direction ) {

    deploy( vScrollText, src_hw_gtia_vscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );

    outline0("JSR VSCROLLT");

}

void gtia_text( Environment * _environment, char * _text, char * _text_size ) {

    deploy( gtiavars, src_hw_gtia_vars_asm );
    deploy( vScrollText, src_hw_gtia_vscroll_text_asm );
    deploy( cls, src_hw_gtia_cls_asm );
    deploy( textEncodedAt, src_hw_gtia_text_at_asm );

    outline1("LDA %s", _text);
    outline0("STA TEXTPTR" );
    outline1("LDA %s+1", _text);
    outline0("STA TEXTPTR+1" );
    outline1("LDA %s", _text_size);
    outline0("STA TEXTSIZE" );

    if ( _environment->currentMode >= 2 && _environment->currentMode <= 7 ) {
        deploy( textEncodedAtText, src_hw_gtia_text_at_text_asm );
        outline0("JSR TEXTATTILEMODE");
    } else {
        deploy( textEncodedAtGraphic, src_hw_gtia_text_at_graphic_asm );
        outline0("JSR TEXTATBITMAPMODE");
    }

}

void gtia_initialization( Environment * _environment ) {

    deploy( gtiavars, src_hw_gtia_vars_asm );
    deploy( gtiastartup, src_hw_gtia_startup_asm );
    src_hw_chipset_mob_asm = src_hw_gtia_mob_asm;
    src_hw_chipset_mob_asm_len = src_hw_gtia_mob_asm_len;

    variable_import( _environment, "CURRENTWIDTH", VT_POSITION, 320 );
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION, 199  );
    variable_global( _environment, "CURRENTHEIGHT" );
    variable_import( _environment, "CURRENTTILES", VT_BYTE, 255 );
    variable_global( _environment, "CURRENTTILES" );
    variable_import( _environment, "CURRENTTILESWIDTH", VT_BYTE, 40 );
    variable_global( _environment, "CURRENTTILESWIDTH" );
    variable_import( _environment, "CURRENTTILESHEIGHT", VT_BYTE, 25 );
    variable_global( _environment, "CURRENTTILESHEIGHT" );
    variable_import( _environment, "FONTWIDTH", VT_BYTE, 8 );
    variable_global( _environment, "FONTWIDTH" );
    variable_import( _environment, "FONTHEIGHT", VT_BYTE, 8 );
    variable_global( _environment, "FONTHEIGHT" );

#ifdef __atarixl__
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC14, 1, 160, 192, 4, "Antic E (Graphics 15-XL computers only)"  );
#endif
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC13, 1, 160, 96, 4, "Graphics 7 (ANTIC D or 13)"  );
#ifdef __atarixl__
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC12, 1, 320, 192, 2, "Antic C (Graphics 14-XL computers only)"  );
#endif
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC15, 1, 320, 192, 1, "Graphics 8 (ANTIC F or 15)"  );
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC8, 1, 40, 24, 4, "Graphics 3 (ANTIC 8)" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC9, 1, 80, 48, 2, "Graphics 4 (ANTIC 9)"  );
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC10, 1, 80, 48, 4, "Graphics 5 (ANTIC A or 10)"  );
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC11, 1, 160, 96, 2, "Graphics 6 (ANTIC B or 11)"  );

    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC2, 0, 40, 24, 1, "Graphics Mode 0 (ANTIC 2)"  );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC6, 0, 20, 24, 4, "Graphics 1 (ANTIC 6)"  );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC7, 0, 20, 12, 4, "Graphics 2 (ANTIC 7)"  );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC3, 0, 40, 24, 4, "Antic 3"  );

#ifdef __atarixl__
    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC4, 0, 40, 24, 4, "Antic 4 (Graphics 12-XL computers only)"  );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC5, 0, 40, 24, 4, "Antic 5 (Graphics 13-XL computers only)"  );
#endif

    outline0("JSR GTIASTARTUP");

    variable_import( _environment, "CURRENTMODE", VT_BYTE, 0 );
    variable_global( _environment, "CURRENTMODE" );

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
    variable_import( _environment, "CLIPX2", VT_POSITION, 319 );
    variable_global( _environment, "CLIPX2" );
    variable_import( _environment, "CLIPY1", VT_POSITION, 0 );
    variable_global( _environment, "CLIPY1" );
    variable_import( _environment, "CLIPY2", VT_POSITION, 199 );
    variable_global( _environment, "CLIPY2" );

    gtia_tilemap_enable( _environment, 40, 24, 1 );

    _environment->currentMode = 2;

    gtia_cls( _environment );

    _environment->currentRgbConverterFunction = rgbConverterFunction;

}

void gtia_finalization( Environment * _environment ) {

}

void gtia_hscroll_line( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_gtia_hscroll_text_asm );

    Variable * y = variable_retrieve( _environment, "YCURSYS" );
    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );
    outline1("LDA %s", y->realName );
    outline0("STA CLINEY");

    outline0("JSR HSCROLLLT");

}

void gtia_hscroll_screen( Environment * _environment, int _direction ) {

    deploy( textHScroll, src_hw_gtia_hscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );

    outline0("JSR HSCROLLST");
}

void gtia_back( Environment * _environment ) {

    deploy( back, src_hw_gtia_back_asm );

    outline0("JSR BACK");

}

void gtia_cline( Environment * _environment, char * _characters ) {

    deploy( textCline, src_hw_gtia_cline_asm );
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
        // Graphics 3 (ANTIC 8)
        // This four-color graphics mode turns a split screen into 20 rows of 40 graphics cells or pixels. 
        // Each pixel is 8 x 8 or the size of a normal character. The data in each pixel is encoded as two bit pairs, 
        // four per byte. The four possible bit pair combinations 00, 01, 10, and 11 point to one of the four color registers. 
        // The bits 00 is assigned to the background color register and the rest refer to the three foreground color registers. 
        // When the CTIA/GTIA chip interprets the data for the four adjacent pixels stored within the byte, it refers to the color 
        // register encoded in the bit pattern to plot the color.
        case BITMAP_MODE_ANTIC8:
        // Graphics 5 (ANTIC A or 10)
        // This is the four color equivalent of GRAPHICS 4 sized pixels. The pixels are 4 x 4, but two bits are required to address 
        // the four color registers. With only four adjacent pixels encoded within a byte, the screen uses twice as much memory, 
        // about 1K.
        case BITMAP_MODE_ANTIC10:
        // Graphics 7 (ANTIC D or 13)
        // This is the four color equivalent to GRAPHICS mode 6. It is the finest resolution four color mode and naturally the
        // most popular. The color is encoded in two bit-pairs exactly the same way as in GRAPHICS 3. The memory requirements 
        // of course is much greater as there are 96 rows of 160 - 2 x 2 sized pixels. It requires 3840 bytes of screen memory
        // with another 104 bytes for the display list.
        case BITMAP_MODE_ANTIC13:
        // Antic E (Graphics 15-XL computers only)
        // This four-color, bit-mapped mode is sometimes known as BASIC 7 1/2. Its resolution is 160 x 192 or twice that of 
        // GRAPHIC 7. Each byte is divided into four pairs of bits. Like the character data in ANTIC 4, the bit pairs point to a
        // particular color register. The screen data, however, is not character data but individual bytes. The user has a lot
        // more control, but this mode uses a lot more memory, approximately
        case BITMAP_MODE_ANTIC14:
            return 2 + ( ( _width >> 2 ) * _height ) + 4;

        // Graphics 4 (ANTIC 9)
        // This is a two-color graphics mode with four times the resolution of GRAPHICS 3. The pixels are 4 x 4, and 48 rows of 80 
        // pixels fit on a full screen. A single bit is used to store each pixel's color register. A zero refers to the background 
        // color register and a one to the foreground color register. The mode is used primarily to conserve screen memory. 
        // Only one bit is used for the color, so eight adjacent pixels are encoded within one byte, and only half as much screen 
        // memory is needed for a display of similiar-sized pixels.
        case BITMAP_MODE_ANTIC9:
        // Graphics 6 (ANTIC B or 11)
        // This two color graphics mode has reasonably fine resolution. The 2 x 2 sized pixels allow 96 rows of 160 pixels to fit 
        // on a full screen. Although only a single bit is used to encode the color, screen memory still requires approximately 2K.
        case BITMAP_MODE_ANTIC11:
        // Graphics 8 (ANTIC F or 15)
        // This mode is definitely the finest resolution available on the Atari. Individual dot-sized pixels can be addressed in 
        // this one-color, two-luminance mode. There are 192 rows of 320 dots in the full screen mode. Graphics 8 is memory 
        // intensive; it takes 8K bytes (eight pixels/byte) to address an entire screen. The color scheme is quite similar to that 
        // in GRAPHICS mode 0. Color register #2 sets the background color. Color register #1 sets the luminance. Changing the color
        // in this register has no effect, but, this doesn't mean that you are limited to just one color.
        // Fortunately, the pixels are each one half of a color clock. It takes two pixels to span one color clock made up of
        // alternating columns of complementary colors. If the background is set to black, these columns consist of blue and 
        // green stripes. If only the odd-columned pixels are plotted, you get blue pixels. If only the odd-columned pixels 
        // are plotted, you get green pixels. And if pairs of adjacent pixels are plotted, you get white. So by cleverly 
        // staggering the pixel patterns, you can achieve three colors. This method is called artifacting. This all depends
        // on background color and luminance.
        case BITMAP_MODE_ANTIC15:
        // Antic C (Graphics 14-XL computers only)
        // This two-color, bit-mapped mode the eight bits correspond directly to the pixels on the screen. If a pixel is lit 
        // it receives its color information from color register #0, otherwise the color is set to the background color 
        // register #4. Each pixel is one scan line high and one color clock wide. This mode's advantages are that it 
        // only uses 4K of screen memory and doesn't have artifacting problems.
        case BITMAP_MODE_ANTIC12:
            return 2 + ( ( _width >> 3 ) * _height ) + 2;

        // Graphics Mode 0 (ANTIC 2)
        // This is the normal-sized character or text mode that the computer defaults to on start up. 
        // Being a character mode, screen memory consists of bytes that represent individual characters in either the 
        // ROM or a custom character set. ANTIC displays forty of these 8 x 8 sized characters on each of 
        // twenty-four lines. Graphics 0 is a 1 1/2 color mode. Color register #2 is used as the background color 
        // register. Color register #1 sets the luminance of the characters against the background. Setting the 
        // color has no effect. Bits within a character are turned on in pairs to produce the luminace color. 
        // Otherwise single bits tend to produce colored artifacts on the high resolution screen. These colors
        // depend on whether the computer has a CTIA or GTIA chip, and the color of the background.
        case TILEMAP_MODE_ANTIC2:

        // Graphics 1 (ANTIC 6)
        // This is one the expanded text modes. Each characters is 8 x 8 but the pixels are one color clock in 
        // width instead of the 1/2 color clock mode of Graphics 0 making the characters twice as wide. Only twenty 
        // characters fit on any line. A graphics 1 screen has twenty rows while the full screen mode has twenty-four 
        // rows of characters. The two high bits of each ATASCII character, that normally identify lowercase or 
        // inverse video text in Graphics 1, set the color register for the 64 character set. Decimal character
        // numbers 0-63 use color register zero, while those same 64 characters if given character numbers 64-127 
        // use color register #1. If you are typing from the Atari keyboard, the uppercase letters A-Z ATASCII 65-90
        // (Internal # 33-58) are assigned to color register zero, while the lowercase numbers 97-122 
        // (Internal # 97-122) are signed to register #1.
        case TILEMAP_MODE_ANTIC6:

        // Graphics 2 (ANTIC 7)
        // This text mode is basically the same as the previous mode except that each row of pixels is two scan lines high.
        // Thus 12 rows of 20 characters are displayed on a full screen. Only ten rows fit on a split screen.
        case TILEMAP_MODE_ANTIC7:

        // Antic 3
        // This rarely used text mode is sometimes called the lowercase descenders mode. Each of the forty characters per line
        // are ten scan lines high, but since each of the characters are only eight scan lines high, the lower two scan lines are
        // normally left empty. However, if you use the last quarter of the character set, the top two lines remain blank, 
        // allowing you to create lowercase characters with descenders.
        case TILEMAP_MODE_ANTIC3:

        // Antic 4 (Graphics 12-XL computers only)
        // This very powerful character graphics mode supports four colors while using relatively little screen memory (1 K). 
        // In addition its 4 x 8 sized characters have the same horizontal resolution as GRAPHICS 7, yet twice the vertical resolution.
        // A large number of games with colorful and detailed playfields use this mode. These characters differ considerably from 
        // ANTIC 6 (BASIC 2) characters, in that each character contains pixels of four different colors, not just a choice of one color
        // determined by the character number. Each byte in the character is broken into four bit pairs, each of which selects the color
        // register for the pixel. That is why the horizontal resolution is only four bits. A special character set generator is used
        // to form these characters.
        case TILEMAP_MODE_ANTIC4:

        // Antic 5 (Graphics 13-XL computers only)
        // This mode is essentially the same as ANTIC 4 except that each character is sixteen scan lines high. 
        // The character set data is still eight bytes high so ANTIC double plots each scan line.
        case TILEMAP_MODE_ANTIC5:
            break;
    }

    return 0;

}

static Variable * gtia_image_converter_bitmap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    // ignored on bitmap mode
    (void)!_transparent_color;

    image_converter_asserts( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    RGBi palette[MAX_PALETTE];

    int colorUsed = rgbi_extract_palette(_source, _width, _height, palette, MAX_PALETTE);

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

    int bufferSize = calculate_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_ANTIC9 );
    char * buffer = malloc ( bufferSize );

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

            for( i=0; i<colorUsed; ++i ) {
                if ( rgbi_equals_rgb( &palette[i], &rgb ) ) {
                    break;
                }
            }

            // printf("%d", i );

            // Calculate the offset starting from the tile surface area
            // and the bit to set.
            offset = (image_y *( _frame_width >> 3 ) ) + (image_x >> 3 );
            bitmask = 1 << ( 7 - (image_x & 0x7) );

            // If the pixes has enough luminance value, it must be 
            // considered as "on"; otherwise, it is "off".
            // int luminance = calculate_luminance(rgb);

            if ( i == 1 ) {
                *( buffer + offset + 2) |= bitmask;
            } else {
                *( buffer + offset + 2) &= ~bitmask;
            }

            _source += 3;

        }

        _source += ( _width - _frame_width ) * 3;

        // printf("\n" );

    }

    if ( colorUsed > 1 ) {
        *(buffer + 2 + ( ( _frame_width >> 3 ) * _frame_height ) + 1 ) = palette[1].index;
    } else {
        *(buffer + 2 + ( ( _frame_width >> 3 ) * _frame_height ) + 1 ) = 0;
    }

    if ( colorUsed > 0 ) {
        *(buffer + 2 + ( ( _frame_width >> 3 ) * _frame_height ) ) = palette[0].index;
    } else {
        *(buffer + 2 + ( ( _frame_width >> 3 ) * _frame_height ) ) = 0;
    }

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    return result;

}


static Variable * gtia_image_converter_multicolor_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    image_converter_asserts( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    RGBi * palette = malloc( MAX_PALETTE * sizeof(RGBi) );
    memset( palette, 0, MAX_PALETTE * sizeof(RGBi) );

    int colorUsed = rgbi_extract_palette(_source, _width, _height, palette, MAX_PALETTE);
    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = colorUsed;

    int i, j, k;

    // printf( "%p %d %d %d %d", _source, _width, _height, _frame_width, _frame_height );

    if ( ! commonPalette ) {

        if (colorUsed > 4) {
            // for( i=0; i<colorUsed; ++i) {
            //     printf("%i : %s\n", i, palette[i].description );
            // }

            CRITICAL_IMAGE_CONVERTER_TOO_COLORS( colorUsed );
        }

        if ( _flags & FLAG_OVERLAYED ) {
            rgbi_move( &palette[2], &palette[3] );
            rgbi_move( &palette[1], &palette[2] );
            rgbi_move( &palette[0], &palette[1] );
            rgbi_move( &SYSTEM_PALETTE[0], &palette[0] );
            palette[0].used = 1;
            ++colorUsed;
        }
        
        for( i=1; i<colorUsed; ++i ) {
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
            rgbi_move(&SYSTEM_PALETTE[colorIndex], &palette[i] );
            palette[i].used = 1;
            // printf("[*] %d) %d %2.2x%2.2x%2.2x\n", i, palette[i].index, palette[i].red, palette[i].green, palette[i].blue);
        }

        commonPalette = palette;
        lastUsedSlotInCommonPalette = colorUsed;
    
    } else {

        if (colorUsed > 4) {
            // for( i=0; i<colorUsed; ++i) {
            //     printf("%i : %s\n", i, palette[i].index );
            // }            
            CRITICAL_IMAGE_CONVERTER_TOO_COLORS( colorUsed );
        }

        if ( ( _flags & FLAG_OVERLAYED ) && ( palette[0].index != 0 ) ) {
            rgbi_move( &palette[2], &palette[3] );
            rgbi_move( &palette[1], &palette[2] );
            rgbi_move( &palette[0], &palette[1] );
            rgbi_move( &SYSTEM_PALETTE[0], &palette[0] );
            palette[0].used = 1;
            ++colorUsed;
        }

        // for (j = 0; j < lastUsedSlotInCommonPalette; ++j) {
        //     printf("[§] common %d) %d %2.2x%2.2x%2.2x\n", j, commonPalette[j].index, commonPalette[j].red, commonPalette[j].green, commonPalette[j].blue);
        // }

        for( i=1; i<colorUsed; ++i ) {
            // printf("[-] palette %d) %2.2x%2.2x%2.2x\n", i, palette[i].red, palette[i].green, palette[i].blue);
            for (j = 0; j < lastUsedSlotInCommonPalette; ++j) {
                // printf("[+] common %d) %d %2.2x%2.2x%2.2x\n", j, commonPalette[j].index, commonPalette[j].red, commonPalette[j].green, commonPalette[j].blue);
                if ( commonPalette[j].used ) {
                    int distance = rgbi_distance(&commonPalette[j], &palette[i]);
                    // printf("    (%d<->%d) >> %2.2x%2.2x%2.2x <-> %2.2x%2.2x%2.2x (%d)\n", j, i, commonPalette[j].red, commonPalette[j].green, commonPalette[j].blue, palette[i].red, palette[i].green, palette[i].blue, distance);
                    if (distance < 5 ) {
                        palette[i].used = 1;
                        // printf("    (-------) >> %d = %d) %d %2.2x%2.2x%2.2x\n", j, i, palette[i].index, palette[i].red, palette[i].green, palette[i].blue);
                        break;
                    }
                }
            }
            // printf("\n");
        }

        for( i=1; i<colorUsed; ++i ) {
            // printf("[*] %d) %d %2.2x%2.2x%2.2x\n", i, palette[i].index, palette[i].red, palette[i].green, palette[i].blue);
            if ( palette[i].used ) continue;
            int minDistance = 0xffff;
            int colorIndex = 0;
            for (j = 0; j < sizeof(SYSTEM_PALETTE)/sizeof(RGBi); ++j) {
                int distance = rgbi_distance(&SYSTEM_PALETTE[j], &palette[i]);
                // printf("%d <-> %d [%d] = %d [min = %d]\n", i, j, SYSTEM_PALETTE[j].index, distance, minDistance );
                if (distance < minDistance) {
                    // printf(" candidated...\n" );
                    for( k=0; k<lastUsedSlotInCommonPalette; ++k ) {
                        if ( commonPalette[k].index == SYSTEM_PALETTE[j].index ) {
                            // printf(" ...used!\n" );
                            break;
                        }
                    }
                    if ( k>=lastUsedSlotInCommonPalette ) {
                        // printf(" ...ok! (%d)\n", SYSTEM_PALETTE[j].index );
                        minDistance = distance;
                        colorIndex = j;
                    }
                }
            }
            rgbi_move(&SYSTEM_PALETTE[colorIndex], &commonPalette[lastUsedSlotInCommonPalette]);
            commonPalette[lastUsedSlotInCommonPalette].used = 1;
            ++lastUsedSlotInCommonPalette;
            // printf("#> %d) %d %2.2x%2.2x%2.2x\n", i, commonPalette[i].index, commonPalette[i].red, commonPalette[i].green, commonPalette[i].blue);
        }

        // for (j = 0; j < lastUsedSlotInCommonPalette; ++j) {
        //     printf("[@] common %d) %d %2.2x%2.2x%2.2x\n", j, commonPalette[j].index, commonPalette[j].red, commonPalette[j].green, commonPalette[j].blue);
        // }

    }

    memcpy( result->originalPalette, commonPalette, MAX_PALETTE * sizeof( RGBi ) );

    int bufferSize = calculate_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_ANTIC8 );
    
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

            // Calculate the offset starting from the tile surface area
            // and the bit to set.
            offset = (image_y * ( _frame_width >> 2 ) ) + (image_x>>2);

            int colorIndex = 0;

            int minDistance = 9999;
            for( int i=0; i<lastUsedSlotInCommonPalette; ++i ) {
                int distance = rgbi_distance(&commonPalette[i], &rgb );
                if ( distance < minDistance ) {
                    minDistance = distance;
                    colorIndex = i;
                }
            }

            if ( _environment->debugImageLoad ) {
                printf("%1.1x", colorIndex );
            }

            bitmask = colorIndex << (6 - ((image_x & 0x3) * 2));

            *(buffer + 2 + offset) |= bitmask;

            _source += 3;

        }

        _source += ( _width - _frame_width ) * 3;

        if ( _environment->debugImageLoad ) {
            printf("\n" );
        }
    }

    if ( _environment->debugImageLoad ) {
        printf("\n" );
    
        printf("PALETTE:\n" );
        if ( ( _flags & FLAG_OVERLAYED ) == 0 ) {
            printf("  background  (00) = %2.2x (%s)\n", commonPalette[0].index, commonPalette[0].description );
        } else {
            printf("  background  (00) = %2.2x (%s) [currently ignored since it can be overlayed]\n", commonPalette[0].index, commonPalette[0].description );
        }
        printf("  pen         (01) = %2.2x (%s)\n", commonPalette[1].index, commonPalette[1].description );
        printf("  pen         (10) = %2.2x (%s)\n", commonPalette[2].index, commonPalette[2].description );
        printf("  pen         (11) = %2.2x (%s)\n", commonPalette[3].index, commonPalette[3].description );
        printf("\n" );
        printf("\n" );
    }

    *(buffer + 2 + ( ( _frame_width >> 2 ) * _frame_height ) + 3 ) = commonPalette[3].index;
    *(buffer + 2 + ( ( _frame_width >> 2 ) * _frame_height ) + 2 ) = commonPalette[2].index;
    *(buffer + 2 + ( ( _frame_width >> 2 ) * _frame_height ) + 1 ) = commonPalette[1].index;
    *(buffer + 2 + ( ( _frame_width >> 2 ) * _frame_height ) ) = commonPalette[0].index;

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    return result;

}

Variable * gtia_image_converter( Environment * _environment, char * _data, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

    switch( _mode ) {
        // Graphics 3 (ANTIC 8)
        // This four-color graphics mode turns a split screen into 20 rows of 40 graphics cells or pixels. 
        // Each pixel is 8 x 8 or the size of a normal character. The data in each pixel is encoded as two bit pairs, 
        // four per byte. The four possible bit pair combinations 00, 01, 10, and 11 point to one of the four color registers. 
        // The bits 00 is assigned to the background color register and the rest refer to the three foreground color registers. 
        // When the CTIA/GTIA chip interprets the data for the four adjacent pixels stored within the byte, it refers to the color 
        // register encoded in the bit pattern to plot the color.
        case BITMAP_MODE_ANTIC8:
            return gtia_image_converter_multicolor_mode_standard( _environment, _data, _width, _height, _offset_x, _offset_y, _frame_width, _frame_height , _transparent_color, _flags );

        // Graphics 4 (ANTIC 9)
        // This is a two-color graphics mode with four times the resolution of GRAPHICS 3. The pixels are 4 x 4, and 48 rows of 80 
        // pixels fit on a full screen. A single bit is used to store each pixel's color register. A zero refers to the background 
        // color register and a one to the foreground color register. The mode is used primarily to conserve screen memory. 
        // Only one bit is used for the color, so eight adjacent pixels are encoded within one byte, and only half as much screen 
        // memory is needed for a display of similiar-sized pixels.
        case BITMAP_MODE_ANTIC9:
            return gtia_image_converter_bitmap_mode_standard( _environment, _data, _width, _height, _offset_x, _offset_y, _frame_width, _frame_height , _transparent_color, _flags );

        // Graphics 5 (ANTIC A or 10)
        // This is the four color equivalent of GRAPHICS 4 sized pixels. The pixels are 4 x 4, but two bits are required to address 
        // the four color registers. With only four adjacent pixels encoded within a byte, the screen uses twice as much memory, 
        // about 1K.
        case BITMAP_MODE_ANTIC10:
            return gtia_image_converter_multicolor_mode_standard( _environment, _data, _width, _height, _offset_x, _offset_y, _frame_width, _frame_height , _transparent_color, _flags );

        // Graphics 6 (ANTIC B or 11)
        // This two color graphics mode has reasonably fine resolution. The 2 x 2 sized pixels allow 96 rows of 160 pixels to fit 
        // on a full screen. Although only a single bit is used to encode the color, screen memory still requires approximately 2K.
        case BITMAP_MODE_ANTIC11:
            return gtia_image_converter_bitmap_mode_standard( _environment, _data, _width, _height, _offset_x, _offset_y, _frame_width, _frame_height , _transparent_color, _flags );

        // Graphics 7 (ANTIC D or 13)
        // This is the four color equivalent to GRAPHICS mode 6. It is the finest resolution four color mode and naturally the
        // most popular. The color is encoded in two bit-pairs exactly the same way as in GRAPHICS 3. The memory requirements 
        // of course is much greater as there are 96 rows of 160 - 2 x 2 sized pixels. It requires 3840 bytes of screen memory
        // with another 104 bytes for the display list.
        case BITMAP_MODE_ANTIC13:
            return gtia_image_converter_multicolor_mode_standard( _environment, _data, _width, _height, _offset_x, _offset_y, _frame_width, _frame_height , _transparent_color, _flags );

        // Graphics 8 (ANTIC F or 15)
        // This mode is definitely the finest resolution available on the Atari. Individual dot-sized pixels can be addressed in 
        // this one-color, two-luminance mode. There are 192 rows of 320 dots in the full screen mode. Graphics 8 is memory 
        // intensive; it takes 8K bytes (eight pixels/byte) to address an entire screen. The color scheme is quite similar to that 
        // in GRAPHICS mode 0. Color register #2 sets the background color. Color register #1 sets the luminance. Changing the color
        // in this register has no effect, but, this doesn't mean that you are limited to just one color.
        // Fortunately, the pixels are each one half of a color clock. It takes two pixels to span one color clock made up of
        // alternating columns of complementary colors. If the background is set to black, these columns consist of blue and 
        // green stripes. If only the odd-columned pixels are plotted, you get blue pixels. If only the odd-columned pixels 
        // are plotted, you get green pixels. And if pairs of adjacent pixels are plotted, you get white. So by cleverly 
        // staggering the pixel patterns, you can achieve three colors. This method is called artifacting. This all depends
        // on background color and luminance.
        case BITMAP_MODE_ANTIC15:
            return gtia_image_converter_bitmap_mode_standard( _environment, _data, _width, _height, _offset_x, _offset_y, _frame_width, _frame_height , _transparent_color, _flags );

        // The following five graphics modes have no equivalent in BASIC on older machine but if indicated do correspond to
        // an equivalent graphics mode on the newer XL models.

        // Antic C (Graphics 14-XL computers only)
        // This two-color, bit-mapped mode the eight bits correspond directly to the pixels on the screen. If a pixel is lit 
        // it receives its color information from color register #0, otherwise the color is set to the background color 
        // register #4. Each pixel is one scan line high and one color clock wide. This mode's advantages are that it 
        // only uses 4K of screen memory and doesn't have artifacting problems.
        case BITMAP_MODE_ANTIC12:
            return gtia_image_converter_bitmap_mode_standard( _environment, _data, _width, _height, _offset_x, _offset_y, _frame_width, _frame_height , _transparent_color, _flags );

        // Antic E (Graphics 15-XL computers only)
        // This four-color, bit-mapped mode is sometimes known as BASIC 7 1/2. Its resolution is 160 x 192 or twice that of 
        // GRAPHIC 7. Each byte is divided into four pairs of bits. Like the character data in ANTIC 4, the bit pairs point to a
        // particular color register. The screen data, however, is not character data but individual bytes. The user has a lot
        // more control, but this mode uses a lot more memory, approximately
        case BITMAP_MODE_ANTIC14:
            return gtia_image_converter_multicolor_mode_standard( _environment, _data, _width, _height, _offset_x, _offset_y, _frame_width, _frame_height , _transparent_color, _flags );

        // Graphics Mode 0 (ANTIC 2)
        // This is the normal-sized character or text mode that the computer defaults to on start up. 
        // Being a character mode, screen memory consists of bytes that represent individual characters in either the 
        // ROM or a custom character set. ANTIC displays forty of these 8 x 8 sized characters on each of 
        // twenty-four lines. Graphics 0 is a 1 1/2 color mode. Color register #2 is used as the background color 
        // register. Color register #1 sets the luminance of the characters against the background. Setting the 
        // color has no effect. Bits within a character are turned on in pairs to produce the luminace color. 
        // Otherwise single bits tend to produce colored artifacts on the high resolution screen. These colors
        // depend on whether the computer has a CTIA or GTIA chip, and the color of the background.
        case TILEMAP_MODE_ANTIC2:

        // Graphics 1 (ANTIC 6)
        // This is one the expanded text modes. Each characters is 8 x 8 but the pixels are one color clock in 
        // width instead of the 1/2 color clock mode of Graphics 0 making the characters twice as wide. Only twenty 
        // characters fit on any line. A graphics 1 screen has twenty rows while the full screen mode has twenty-four 
        // rows of characters. The two high bits of each ATASCII character, that normally identify lowercase or 
        // inverse video text in Graphics 1, set the color register for the 64 character set. Decimal character
        // numbers 0-63 use color register zero, while those same 64 characters if given character numbers 64-127 
        // use color register #1. If you are typing from the Atari keyboard, the uppercase letters A-Z ATASCII 65-90
        // (Internal # 33-58) are assigned to color register zero, while the lowercase numbers 97-122 
        // (Internal # 97-122) are signed to register #1.
        case TILEMAP_MODE_ANTIC6:

        // Graphics 2 (ANTIC 7)
        // This text mode is basically the same as the previous mode except that each row of pixels is two scan lines high.
        // Thus 12 rows of 20 characters are displayed on a full screen. Only ten rows fit on a split screen.
        case TILEMAP_MODE_ANTIC7:

        // Antic 3
        // This rarely used text mode is sometimes called the lowercase descenders mode. Each of the forty characters per line
        // are ten scan lines high, but since each of the characters are only eight scan lines high, the lower two scan lines are
        // normally left empty. However, if you use the last quarter of the character set, the top two lines remain blank, 
        // allowing you to create lowercase characters with descenders.
        case TILEMAP_MODE_ANTIC3:

        // Antic 4 (Graphics 12-XL computers only)
        // This very powerful character graphics mode supports four colors while using relatively little screen memory (1 K). 
        // In addition its 4 x 8 sized characters have the same horizontal resolution as GRAPHICS 7, yet twice the vertical resolution.
        // A large number of games with colorful and detailed playfields use this mode. These characters differ considerably from 
        // ANTIC 6 (BASIC 2) characters, in that each character contains pixels of four different colors, not just a choice of one color
        // determined by the character number. Each byte in the character is broken into four bit pairs, each of which selects the color
        // register for the pixel. That is why the horizontal resolution is only four bits. A special character set generator is used
        // to form these characters.
        case TILEMAP_MODE_ANTIC4:

        // Antic 5 (Graphics 13-XL computers only)
        // This mode is essentially the same as ANTIC 4 except that each character is sixteen scan lines high. 
        // The character set data is still eight bytes high so ANTIC double plots each scan line.
        case TILEMAP_MODE_ANTIC5:
            break;
    }

    CRITICAL_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

}

void gtia_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, int _frame_size, int _flags ) {

    // currently unused
    (void)!_flags;

    deploy( gtiavars, src_hw_gtia_vars_asm);
    deploy( putimage, src_hw_gtia_put_image_asm );

    outline1("LDA #$%2.2x", _flags );
    outline0("STA IMAGET" );
    outline1("LDA #<%s", _image );
    outline1("LDA #<%s", _image );
    outline0("STA TMPPTR" );
    outline1("LDA #>%s", _image );
    outline0("STA TMPPTR+1" );
    if ( _frame ) {
        outline0("CLC" );
        outline0("LDA TMPPTR" );
        outline0("ADC #2" );
        outline0("STA TMPPTR" );
        outline0("LDA TMPPTR+1" );
        outline0("ADC #0" );
        outline0("STA TMPPTR+1" );
        if ( strlen(_frame) == 0 ) {

        } else {
            outline1("LDA #<OFFSETS%4.4x", _frame_size );
            outline0("STA TMPPTR2" );
            outline1("LDA #>OFFSETS%4.4x", _frame_size );
            outline0("STA TMPPTR2+1" );
            outline0("CLC" );
            outline1("LDA %s", _frame );
            outline0("ASL" );
            outline0("TAY" );
            outline0("LDA TMPPTR" );
            outline0("ADC (TMPPTR2), Y" );
            outline0("STA TMPPTR" );
            outline0("INY" );
            outline0("LDA TMPPTR+1" );
            outline0("ADC (TMPPTR2), Y" );
            outline0("STA TMPPTR+1" );
        }
    }
    outline1("LDA %s", _x );
    outline0("STA IMAGEX" );
    outline1("LDA %s+1", _x );
    outline0("STA IMAGEX+1" );
    outline1("LDA %s", _y );
    outline0("STA IMAGEY" );
    outline1("LDA %s+1", _y );
    outline0("STA IMAGEY+1" );

    outline0("JSR PUTIMAGE");

}

void gtia_wait_vbl( Environment * _environment ) {

    deploy( vbl, src_hw_gtia_vbl_asm);

    outline0("JSR VBL");

}

Variable * gtia_new_image( Environment * _environment, int _width, int _height, int _mode ) {

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

void gtia_get_image( Environment * _environment, char * _image, char * _x, char * _y ) {

    deploy( gtiavars, src_hw_gtia_vars_asm);
    deploy( getimage, src_hw_gtia_get_image_asm );

    outline1("LDA #<%s", _image );
    outline1("LDA #<%s", _image );
    outline0("STA TMPPTR" );
    outline1("LDA #>%s", _image );
    outline0("STA TMPPTR+1" );
    outline1("LDA %s", _x );
    outline0("STA IMAGEX" );
    outline1("LDA %s+1", _x );
    outline0("STA IMAGEX+1" );
    outline1("LDA %s", _y );
    outline0("STA IMAGEY" );
    outline1("LDA %s+1", _y );
    outline0("STA IMAGEY+1" );

    outline0("JSR GETIMAGE");

}

void gtia_scroll( Environment * _environment, int _dx, int _dy ) {

}

#endif