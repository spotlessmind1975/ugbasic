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

#ifdef __atari__

#include "../ugbc.h"
#include "6502.h"

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
void gtia_background_color( Environment * _environment, char * _index, char * _background_color ) {
 
    outline1("LDA %s", _index);
    outline0("AND #$03");
    outline0("TAX");
    outline1("LDA %s", _background_color );
    outline0("AND #$0f" );
    outline0("STA $02C5,X")

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

static int gtia_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    int i;
    int screenMemoryOffset = 0;
    int screenMemoryOffset2 = 0;
    int currentHeight = 0;
    int scanline = 0;
    int dliListStartOffset;

    deploy( gtiavarsDeployed, "./ugbc/src/hw/gtia/vars.asm" );
    
    unsigned char * dliListStart = malloc( DLI_COUNT ), * dliListCurrent = dliListStart;
    
    Variable * dli = variable_retrieve_or_define( _environment, "DLI", VT_BUFFER, 0 );

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
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 72	\Display ANTIC mode 8 (BASIC 3) 64+8
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 8, 0x9000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<23; ++i ) {
                // 8	\Display ANTIC mode 8 for second mode line
                DLI_MODE( dliListCurrent, 8 );
            }

            DLI_IRQ( dliListCurrent, 8 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=39968
            DLI_JVB( dliListCurrent, 39968 );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            currentHeight = 24;
            scanline = 10;
            cpu_store_16bit( _environment, "CURRENTWIDTH", 40 );
            cpu_store_16bit( _environment, "CURRENTHEIGHT", currentHeight );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 40 );
            break;        

        // Graphics 4 (ANTIC 9)
        // This is a two-color graphics mode with four times the resolution of GRAPHICS 3. The pixels are 4 x 4, and 48 rows of 80 
        // pixels fit on a full screen. A single bit is used to store each pixel's color register. A zero refers to the background 
        // color register and a one to the foreground color register. The mode is used primarily to conserve screen memory. 
        // Only one bit is used for the color, so eight adjacent pixels are encoded within one byte, and only half as much screen 
        // memory is needed for a display of similiar-sized pixels.
        // 80x48, 2 colors
        case BITMAP_MODE_ANTIC9:
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 72	\Display ANTIC mode 9 (BASIC 3) 64+9
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 9, 0x9000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<47; ++i ) {
                // 8	\Display ANTIC mode 9 for second mode line
                DLI_MODE( dliListCurrent, 9 );
            }

            DLI_IRQ( dliListCurrent, 9 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=39968
            DLI_JVB( dliListCurrent, 39968 );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            currentHeight = 48;
            scanline = 10;
            cpu_store_16bit( _environment, "CURRENTWIDTH", 80 );
            cpu_store_16bit( _environment, "CURRENTHEIGHT", currentHeight );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 40 );
            break;

        // Graphics 5 (ANTIC A or 10)
        // This is the four color equivalent of GRAPHICS 4 sized pixels. The pixels are 4 x 4, but two bits are required to address 
        // the four color registers. With only four adjacent pixels encoded within a byte, the screen uses twice as much memory, 
        // about 1K.
        // 80x48, 4 colors
        case BITMAP_MODE_ANTIC10:
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 74	\Display ANTIC mode 10 (BASIC 5) 64+10
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 10, 0x9000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<47; ++i ) {
                // 8	\Display ANTIC mode 10 for second mode line
                DLI_MODE( dliListCurrent, 10 );
            }

            DLI_IRQ( dliListCurrent, 10 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=39968
            DLI_JVB( dliListCurrent, 39968 );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            currentHeight = 48;
            scanline = 20;
            cpu_store_16bit( _environment, "CURRENTWIDTH", 80 );
            cpu_store_16bit( _environment, "CURRENTHEIGHT", currentHeight );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 40 );
            break;

        // Graphics 6 (ANTIC B or 11)
        // This two color graphics mode has reasonably fine resolution. The 2 x 2 sized pixels allow 96 rows of 160 pixels to fit 
        // on a full screen. Although only a single bit is used to encode the color, screen memory still requires approximately 2K.
        // 160x96, 2 colors
        case BITMAP_MODE_ANTIC11: 
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 75	\Display ANTIC mode 11 (BASIC 8) 64+11
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 11, 0x9000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<95; ++i ) {
                // 8	\Display ANTIC mode 11 for second mode line
                DLI_MODE( dliListCurrent, 11 );
            }

            DLI_IRQ( dliListCurrent, 10 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=39968
            DLI_JVB( dliListCurrent, 39968 );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            currentHeight = 96;
            scanline = 20;
            cpu_store_16bit( _environment, "CURRENTWIDTH", 160 );
            cpu_store_16bit( _environment, "CURRENTHEIGHT", 96 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 40 );
        break;

        // Graphics 7 (ANTIC D or 13)
        // This is the four color equivalent to GRAPHICS mode 6. It is the finest resolution four color mode and naturally the
        // most popular. The color is encoded in two bit-pairs exactly the same way as in GRAPHICS 3. The memory requirements 
        // of course is much greater as there are 96 rows of 160 - 2 x 2 sized pixels. It requires 3840 bytes of screen memory
        // with another 104 bytes for the display list.
        // 160x96, 4 colors
        case BITMAP_MODE_ANTIC13:
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 77	\Display ANTIC mode 13 (BASIC 7) 64+13
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 13, 0x9000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<95; ++i ) {
                // 8	\Display ANTIC mode 13 for second mode line
                DLI_MODE( dliListCurrent, 13 );
            }

            DLI_IRQ( dliListCurrent, 13 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=39968
            DLI_JVB( dliListCurrent, 39968 );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            currentHeight = 96;
            scanline = 40;
            cpu_store_16bit( _environment, "CURRENTWIDTH", 160 );
            cpu_store_16bit( _environment, "CURRENTHEIGHT", currentHeight );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 40 );
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
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 81	\Display ANTIC mode 15 (BASIC 7) 64+15
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 15, 0x9000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<96; ++i ) {
                // 8	\Display ANTIC mode 15 for second mode line
                DLI_MODE( dliListCurrent, 15 );
            }

            DLI_LMS( dliListCurrent, 15, 0x9000 + 40 * 96 );

            screenMemoryOffset2 = dliListCurrent - dliListStart - 2;

            for( i=0; i<95; ++i ) {
                // 8	\Display ANTIC mode 15 for second mode line
                DLI_MODE( dliListCurrent, 15 );
            }

            DLI_IRQ( dliListCurrent, 15 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=39968
            DLI_JVB( dliListCurrent, 39968 );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            currentHeight = 192;
            scanline = 40;
            cpu_store_16bit( _environment, "CURRENTWIDTH", 320 );
            cpu_store_16bit( _environment, "CURRENTHEIGHT", currentHeight );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 40 );
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
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 76	\Display ANTIC mode 12 64+12
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 12, 0x9000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<191; ++i ) {
                // 8	\Display ANTIC mode 15 for second mode line
                DLI_MODE( dliListCurrent, 12 );
            }

            DLI_IRQ( dliListCurrent, 12 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=39968
            DLI_JVB( dliListCurrent, 39968 );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            currentHeight = 192;
            scanline = 40;
            cpu_store_16bit( _environment, "CURRENTWIDTH", 320 );
            cpu_store_16bit( _environment, "CURRENTHEIGHT", currentHeight );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 40 );
            break;

        // Antic E (Graphics 15-XL computers only)
        // This four-color, bit-mapped mode is sometimes known as BASIC 7 1/2. Its resolution is 160 x 192 or twice that of 
        // GRAPHIC 7. Each byte is divided into four pairs of bits. Like the character data in ANTIC 4, the bit pairs point to a
        // particular color register. The screen data, however, is not character data but individual bytes. The user has a lot
        // more control, but this mode uses a lot more memory, approximately
        // 160x192, 4 colors
        case BITMAP_MODE_ANTIC14:
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 76	\Display ANTIC mode 12 64+14
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            DLI_LMS( dliListCurrent, 14, 0x9000 );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<191; ++i ) {
                // 8	\Display ANTIC mode 15 for second mode line
                DLI_MODE( dliListCurrent, 14 );
            }

            DLI_IRQ( dliListCurrent, 14 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=39968
            DLI_JVB( dliListCurrent, 39968 );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            currentHeight = 192;
            scanline = 20;
            cpu_store_16bit( _environment, "CURRENTWIDTH", 160 );
            cpu_store_16bit( _environment, "CURRENTHEIGHT", currentHeight );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 40 );
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
            // 156	/at 32+256*156=39968
            DLI_JVB( dliListCurrent, 39968 );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            cpu_store_16bit( _environment, "CURRENTWIDTH", 40 );
            cpu_store_16bit( _environment, "CURRENTHEIGHT", 24 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 152 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 192 );
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
            // 156	/at 32+256*156=39968
            DLI_JVB( dliListCurrent, 39968 );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            cpu_store_16bit( _environment, "CURRENTWIDTH", 20 );
            cpu_store_16bit( _environment, "CURRENTHEIGHT", 24 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 204 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 224 );
            break;

        // Graphics 2 (ANTIC 7)
        // This text mode is basically the same as the previous mode except that each row of pixels is two scan lines high.
        // Thus 12 rows of 20 characters are displayed on a full screen. Only ten rows fit on a split screen.
        // 20x12, 4 color
        case TILEMAP_MODE_ANTIC7:
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
            // 156	/at 32+256*156=39968
            DLI_JVB( dliListCurrent, 39968 );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            cpu_store_16bit( _environment, "CURRENTWIDTH", 20 );
            cpu_store_16bit( _environment, "CURRENTHEIGHT", 12 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 204 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 224 );
            break;

        // Antic 3
        // This rarely used text mode is sometimes called the lowercase descenders mode. Each of the forty characters per line
        // are ten scan lines high, but since each of the characters are only eight scan lines high, the lower two scan lines are
        // normally left empty. However, if you use the last quarter of the character set, the top two lines remain blank, 
        // allowing you to create lowercase characters with descenders.
        // 40x24, 4 color
        case TILEMAP_MODE_ANTIC3:
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
            // 156	/at 32+256*156=39968
            DLI_JVB( dliListCurrent, 39968 );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            cpu_store_16bit( _environment, "CURRENTWIDTH", 40 );
            cpu_store_16bit( _environment, "CURRENTHEIGHT", 24 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 152 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 192 );
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
            // 156	/at 32+256*156=39968
            DLI_JVB( dliListCurrent, 39968 );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            cpu_store_16bit( _environment, "CURRENTWIDTH", 40 );
            cpu_store_16bit( _environment, "CURRENTHEIGHT", 24 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 152 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 192 );
        break;

        // Antic 5 (Graphics 13-XL computers only)
        // This mode is essentially the same as ANTIC 4 except that each character is sixteen scan lines high. 
        // The character set data is still eight bytes high so ANTIC double plots each scan line.
        // 20x24, 4 color  
        case TILEMAP_MODE_ANTIC5:
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
            // 156	/at 32+256*156=39968
            DLI_JVB( dliListCurrent, 39968 );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            cpu_store_16bit( _environment, "CURRENTWIDTH", 40 );
            cpu_store_16bit( _environment, "CURRENTHEIGHT", 24 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 152 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 192 );
            break;

        default:
            CRITICAL_SCREEN_MODE_BITMAP_UNSUPPORTED( _screen_mode->description );
    }

    cpu_store_16bit( _environment, "CLIPX1", 0) ;
    cpu_store_16bit( _environment, "CLIPY2", 0) ;
    cpu_move_16bit( _environment, "CURRENTWIDTH", "CLIPX2");
    cpu_move_16bit( _environment, "CURRENTHEIGHT", "CLIPY2");

    variable_store_buffer( _environment, dli->name, dliListStart, ( dliListCurrent - dliListStart ) );

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

    outline1("LDA %s", dli->realName );
    outline0("STA (TMPPTR),Y" );
    outline0("INY" );
    outline1("LDA %s+1", dli->realName );
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

    gtia_screen_mode_enable( _environment, mode );

    cpu_store_8bit( _environment, "CURRENTMODE", mode->id );

}

void gtia_bitmap_disable( Environment * _environment ) {

}

void gtia_tilemap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors );

    gtia_screen_mode_enable( _environment, mode );

    cpu_store_8bit( _environment, "_PEN", 0x01 );
    cpu_store_8bit( _environment, "_PAPER", 0x00 );

    cpu_store_8bit( _environment, "CURRENTMODE", mode->id );

}

void gtia_bitmap_at( Environment * _environment, char * _address ) {

}

void gtia_colormap_at( Environment * _environment, char * _address ) {

}

void gtia_textmap_at( Environment * _environment, char * _address ) {

}

void gtia_point_at_int( Environment * _environment, int _x, int _y ) {

    deploy( gtiavarsDeployed, "./ugbc/src/hw/gtia/vars.asm" );
    deploy( plotDeployed, "./ugbc/src/hw/gtia/plot.asm" );
    
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

    deploy( gtiavarsDeployed, "./ugbc/src/hw/gtia/vars.asm" );
    deploy( plotDeployed, "./ugbc/src/hw/gtia/plot.asm" );
    
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

    deploy( gtiavarsDeployed, "./ugbc/src/hw/gtia/vars.asm" );
    deploy( plotDeployed, "./ugbc/src/hw/gtia/plot.asm" );
    
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

void gtia_get_height( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTHEIGHT" );
    outline1("STA %s", _result );
    outline0("LDA CURRENTHEIGHT+1" );
    outline1("STA %s+1", _result );

}

void gtia_cls( Environment * _environment ) {
    
    deploy( clsDeployed, "./ugbc/src/hw/gtia/cls.asm" );

    outline0("LDA #$0");
    outline0("STA TMPPTR");
    outline0("JSR CLS");

}

void gtia_clear( Environment * _environment, char * _pattern ) {
    
    deploy( clsDeployed, "./ugbc/src/hw/gtia/cls.asm" );

    outline1("LDA %s", _pattern );
    outline0("STA TMPPTR");
    outline0("JSR CLS");

}

void gtia_scroll_text( Environment * _environment, int _direction ) {

    deploy( vScrollTextDeployed, "./ugbc/src/hw/gtia/vscroll_text.asm" );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );

    outline0("JSR VSCROLLT");

}

void gtia_text_at( Environment * _environment, char * _x, char * _y, char * _text, char * _text_size, char * _pen, char *_ww ) {

    deploy( gtiavarsDeployed, "./ugbc/src/hw/gtia/vars.asm" );
    deploy( vScrollTextDeployed, "./ugbc/src/hw/gtia/vscroll_text.asm" );
    deploy( textEncodedAtDeployed, "./ugbc/src/hw/gtia/text_at.asm" );

    outline1("LDA %s", _text);
    outline0("STA TEXTPTR" );
    outline1("LDA %s+1", _text);
    outline0("STA TEXTPTR+1" );
    outline0("LDA TEXTADDRESS" );
    outline0("STA COPYOFTEXTADDRESS" );
    outline0("LDA TEXTADDRESS+1" );
    outline0("STA COPYOFTEXTADDRESS+1" );
    outline1("LDA %s", _x );
    outline0("STA XCURSYS" );
    outline1("LDA %s", _y );
    outline0("STA YCURSYS" );
    outline1("LDA %s", _text_size);
    outline0("STA TEXTSIZE" );
    outline0("LDA #0" );
    outline0("STA TABSTODRAW" );
    outline0("LDA COLORMAPADDRESS" );
    outline0("STA COPYOFCOLORMAPADDRESS" );
    outline0("LDA COLORMAPADDRESS+1" );
    outline0("STA COPYOFCOLORMAPADDRESS+1" );
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

void gtia_initialization( Environment * _environment ) {

    deploy( vicstartupDeployed, "./ugbc/src/hw/gtia/startup.asm" );

    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC15, 1, 320, 192, 1, "Graphics 8 (ANTIC F or 15)"  );
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC8, 1, 40, 24, 4, "Graphics 3 (ANTIC 8)" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC9, 1, 80, 48, 2, "Graphics 4 (ANTIC 9)"  );
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC10, 1, 80, 48, 4, "Graphics 5 (ANTIC A or 10)"  );
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC11, 1, 160, 96, 2, "Graphics 6 (ANTIC B or 11)"  );
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC13, 1, 160, 96, 4, "Graphics 7 (ANTIC D or 13)"  );
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC14, 1, 160, 192, 4, "Antic E (Graphics 15-XL computers only)"  );
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC12, 1, 320, 192, 4, "Antic C (Graphics 14-XL computers only)"  );

    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC2, 0, 40, 24, 1, "Graphics Mode 0 (ANTIC 2)"  );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC6, 0, 20, 24, 4, "Graphics 1 (ANTIC 6)"  );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC7, 0, 20, 12, 4, "Graphics 2 (ANTIC 7)"  );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC3, 0, 40, 24, 4, "Antic 3"  );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC4, 0, 40, 24, 4, "Antic 4 (Graphics 12-XL computers only)"  );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC5, 0, 40, 24, 4, "Antic 5 (Graphics 13-XL computers only)"  );

    outline0("JSR GTIASTARTUP");

    variable_import( _environment, "CURRENTMODE", VT_BYTE );
    variable_global( _environment, "CURRENTMODE" );
    variable_import( _environment, "CURRENTWIDTH", VT_POSITION );
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION );
    variable_global( _environment, "CURRENTHEIGHT" );

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

    gtia_cls( _environment );

}

void gtia_hscroll_line( Environment * _environment, int _direction ) {

    deploy( textHScrollDeployed, "./ugbc/src/hw/gtia/hscroll_text.asm" );

    Variable * y = variable_retrieve( _environment, "windowCY" );
    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );
    outline1("LDA %s", y->realName );
    outline0("STA CLINEY");

    outline0("JSR HSCROLLLT");

}

void gtia_hscroll_screen( Environment * _environment, int _direction ) {

    deploy( textHScrollDeployed, "./ugbc/src/hw/gtia/hscroll_text.asm" );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );

    outline0("JSR HSCROLLST");
}

void gtia_back( Environment * _environment ) {

    deploy( backDeployed, "./ugbc/src/hw/gtia/back.asm" );

    outline0("JSR BACK");

}

void gtia_cline( Environment * _environment, char * _characters ) {

    deploy( textClineDeployed, "./ugbc/src/hw/gtia/cline.asm" );
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

#endif