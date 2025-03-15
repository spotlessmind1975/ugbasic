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

#if defined(__atari__) || defined(__atarixl__)

#include "../ugbc.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
        { 0x00, 0x00, 0x00, 0xff, 0x00, "BLACK", 0x00 },            //
        { 0xff, 0xff, 0xff, 0xff, 0x0f, "WHITE", 0x0f },            //
        { 0x90, 0x18, 0x29, 0xff, 0x24, "RED", 0x24 },              //
        { 0x8e, 0xff, 0xff, 0xff, 0xae, "CYAN", 0xae },             //
        { 0x77, 0x27, 0x93, 0xff, 0x64, "VIOLET", 0x64 },           //
        { 0x00, 0x82, 0x67, 0xff, 0xa2, "GREEN", 0xb6 },            //        
        { 0x51, 0x34, 0xae, 0xff, 0x74, "BLUE", 0x74 },             //
        { 0xee, 0xee, 0x77, 0xff, 0x1f, "YELLOW", 0x1f },           //
        { 0xaa, 0x7e, 0x00, 0xff, 0x29, "ORANGE", 0x29 },           //
        { 0x65, 0x3d, 0x00, 0xff, 0x24, "BROWN", 0x24 },            //
        { 0xd6, 0x60, 0x72, 0xff, 0x28, "LIGHT RED", 0x28 },        //
        { 0x3e, 0x3c, 0x3f, 0xff, 0x04, "DARK GREY", 0x04 },        //
        { 0x83, 0x7e, 0x85, 0xff, 0x08, "GREY", 0x08 },             //
        { 0x00, 0xc2, 0xab, 0xff, 0xba, "LIGHT GREEN", 0xba },      //
        { 0x7d, 0x56, 0xd6, 0xff, 0x76, "LIGHT BLUE", 0x76 },       //
        { 0xf3, 0xeb, 0xf8, 0xff, 0x0e, "LIGHT GREY", 0x0e },       //
        { 0xff, 0xab, 0xff, 0xff, 0x6d, "MAGENTA", 0x6d },          //
        { 0xe5, 0x89, 0xfd, 0xff, 0x6a, "LAVENDER", 0x6a },         //
        { 0xf5, 0xc5, 0x64, 0xff, 0x2c, "GOLD", 0x2c },             //
        { 0x8e, 0xff, 0xff, 0xff, 0xaf, "TURQUOISE", 0xaf },        //
        { 0x22, 0xb9, 0xdf, 0xff, 0xab, "TAN", 0xab },              //
        { 0x7f, 0x8e, 0x00, 0xff, 0x18, "YELLOW GREEN", 0x18 },     //
        { 0x36, 0x4f, 0x00, 0xff, 0x14, "OLIVE GREEN", 0x14 },      //
        { 0xff, 0xb6, 0x8c, 0xff, 0x3a, "PINK", 0x3c },             //
        { 0xf0, 0x93, 0x65, 0xff, 0x3b, "PEACH", 0x3b },            //
        { 0x8e, 0xff, 0xff, 0xff, 0xae, "CYAN", 0xae },             //
        { 0x00, 0x13, 0x5f, 0xff, 0x71, "DARK BLUE", 0x71 }         //
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

    switch( _environment->currentMode ) {
        case TILEMAP_MODE_ANTIC2:
        case TILEMAP_MODE_ANTIC6:
        case TILEMAP_MODE_ANTIC7:
                outline1("LDA %s", _border_color );
                outline0("STA $02c8");
            break;

        case BITMAP_MODE_ANTIC8:
        case BITMAP_MODE_ANTIC10:
        case BITMAP_MODE_ANTIC13:
            break;

        case BITMAP_MODE_ANTIC9:
        case BITMAP_MODE_ANTIC11:
        case BITMAP_MODE_ANTIC15:
        case BITMAP_MODE_ANTIC12:
        case BITMAP_MODE_ANTIC14:
        case TILEMAP_MODE_ANTIC3:
        case TILEMAP_MODE_ANTIC4:
        case TILEMAP_MODE_ANTIC5:
            break;
    }

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
 
    switch( _environment->currentMode ) {
        case TILEMAP_MODE_ANTIC2:
        case TILEMAP_MODE_ANTIC6:
        case TILEMAP_MODE_ANTIC7:
            break;

        case BITMAP_MODE_ANTIC8:
        case BITMAP_MODE_ANTIC10:
        case BITMAP_MODE_ANTIC13:
            outline1("LDA #$%2.2x", (unsigned char)(_background_color) );
            outline0("AND #$0f" );
            switch( _index ) {
                case 0:
                    outline0("STA $02C8" )
                    break;
                case 1:
                    outline0("STA $02C4" )
                    break;
                case 2:
                    outline0("STA $02C6" )
                    break;
                case 3:
                    outline0("STA $02C5" )
                    break;
            }
            break;

        case BITMAP_MODE_ANTIC9:
            outline1("LDA #$%2.2x", _background_color );
            outline0("AND #$0f" );
            outline0("STA $02C8" )
            break;

        case BITMAP_MODE_ANTIC11:
            outline1("LDA #$%2.2x", _background_color );
            outline0("AND #$0f" );
            outline0("STA $02C4" )
            break;

        case BITMAP_MODE_ANTIC15:
            outline1("LDA #$%2.2x", _background_color );
            outline0("AND #$0f" );
            switch( _index ) {
                case 0:
                    outline0("STA $02C5" )
                    break;
                case 1:
                    outline0("STA $02C6" )
                    break;
            }

        case TILEMAP_MODE_ANTIC4:
        case TILEMAP_MODE_ANTIC5:
            outline1("LDA #$%2.2x", _background_color );
            outline0("AND #$0f" );
            switch( _index ) {
                case 0:
                    outline0("STA $02C8" )
                    break;
                case 1:
                    outline0("STA $02C4" )
                    break;
                case 2:
                    outline0("STA $02C5" )
                    break;
                case 3:
                    outline0("STA $02C6" )
                    break;
            }
            break;

        case BITMAP_MODE_ANTIC12:
            outline1("LDA #$%2.2x", _background_color );
            outline0("AND #$0f" );
            switch( _index ) {
                case 0:
                    outline0("STA $02C6" )
                    break;
            }
            break;

        case BITMAP_MODE_ANTIC14:
            outline1("LDA #$%2.2x", _background_color );
            outline0("AND #$0f" );
            switch( _index ) {
                case 0:
                    outline0("STA $02C8" )
                    break;
                case 1:
                    outline0("STA $02C4" )
                    break;
                case 2:
                    outline0("STA $02C5" )
                    break;
                case 3:
                    outline0("STA $02C6" )
                    break;
            }
            break;

        case TILEMAP_MODE_ANTIC3:
            break;
    }


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
 
    MAKE_LABEL

    switch( _environment->currentMode ) {
        case TILEMAP_MODE_ANTIC2:
        case TILEMAP_MODE_ANTIC6:
        case TILEMAP_MODE_ANTIC7:
            break;

        case BITMAP_MODE_ANTIC8:
        case BITMAP_MODE_ANTIC10:
        case BITMAP_MODE_ANTIC13:
            outline1("LDA %s", _index);
            outline0("AND #$03");
            outline0("TAX");
            outline1("LDA %s", _background_color );
            outline0("AND #$0f" );
            outline0("CPX #0" );
            outline1("BNE %snc0", label );
            outline0("STA $02C8" )
            outline1("JMP %scdone", label )
            outhead1("%snc0:", label);
            outline0("CPX #1" );
            outline1("BNE %snc1", label );
            outline0("STA $02C4" )
            outline1("JMP %scdone", label )
            outhead1("%snc1:", label);
            outline0("CPX #2" );
            outline1("BNE %snc2", label );
            outline0("STA $02C6" )
            outline1("JMP %scdone", label )
            outhead1("%snc2:", label);
            outline0("STA $02C5")
            outhead1("%scdone:", label);
            break;

        case BITMAP_MODE_ANTIC9:
            outline1("LDA #$%2.2x", _background_color );
            outline0("AND #$0f" );
            outline0("STA $02C8" )
            break;

        case BITMAP_MODE_ANTIC11:
            outline1("LDA #$%2.2x", _background_color );
            outline0("AND #$0f" );
            outline0("STA $02C4" )
            break;

        case BITMAP_MODE_ANTIC15:
            outline1("LDA %s", _index);
            outline0("AND #$01");
            outline0("TAX");
            outline1("LDA %s", _background_color );
            outline0("AND #$0f" );
            outline0("CPX #0" );
            outline1("BNE %snc0", label );
            outline0("STA $02C5" )
            outline1("JMP %scdone", label )
            outhead1("%snc0:", label);
            outline0("STA $02C6")
            outhead1("%scdone:", label);
            break;

        case TILEMAP_MODE_ANTIC4:
        case TILEMAP_MODE_ANTIC5:
            outline1("LDA %s", _index);
            outline0("AND #$03");
            outline0("TAX");
            outline1("LDA %s", _background_color );
            outline0("AND #$0f" );
            outline0("CPX #0" );
            outline1("BNE %snc0", label );
            outline0("STA $02C8" )
            outline1("JMP %scdone", label )
            outhead1("%snc0:", label);
            outline0("CPX #1" );
            outline1("BNE %snc1", label );
            outline0("STA $02C4" )
            outline1("JMP %scdone", label )
            outhead1("%snc1:", label);
            outline0("CPX #2" );
            outline1("BNE %snc2", label );
            outline0("STA $02C6" )
            outline1("JMP %scdone", label )
            outhead1("%snc2:", label);
            outline0("STA $02C6")
            outhead1("%scdone:", label);
            break;

        case BITMAP_MODE_ANTIC12:
            outline1("LDA %s", _index);
            outline0("AND #$0f" );
            outline0("STA $02C6" )
            break;

        case BITMAP_MODE_ANTIC14:
            outline1("LDA %s", _index);
            outline0("AND #$03");
            outline0("TAX");
            outline1("LDA %s", _background_color );
            outline0("AND #$0f" );
            outline0("CPX #0" );
            outline1("BNE %snc0", label );
            outline0("STA $02C8" )
            outline1("JMP %scdone", label )
            outhead1("%snc0:", label);
            outline0("CPX #1" );
            outline1("BNE %snc1", label );
            outline0("STA $02C4" )
            outline1("JMP %scdone", label )
            outhead1("%snc1:", label);
            outline0("CPX #2" );
            outline1("BNE %snc2", label );
            outline0("STA $02C5" )
            outline1("JMP %scdone", label )
            outhead1("%snc2:", label);
            outline0("STA $02C6")
            outhead1("%scdone:", label);
            break;

        case TILEMAP_MODE_ANTIC3:
            break;
    }

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
 
    MAKE_LABEL

    switch( _environment->currentMode ) {
        case TILEMAP_MODE_ANTIC2:
        case TILEMAP_MODE_ANTIC6:
        case TILEMAP_MODE_ANTIC7:
            break;

        case BITMAP_MODE_ANTIC8:
        case BITMAP_MODE_ANTIC10:
        case BITMAP_MODE_ANTIC13:
            outline1("LDA #$%2.2x", _index);
            outline0("AND #$03");
            outline0("TAX");
            outline1("LDA %s", _background_color );
            outline0("AND #$0f" );
            outline0("CPX #0" );
            outline1("BNE %snc0", label );
            outline0("STA $02C8" )
            outline1("JMP %scdone", label )
            outhead1("%snc0:", label);
            outline0("CPX #1" );
            outline1("BNE %snc1", label );
            outline0("STA $02C4" )
            outline1("JMP %scdone", label )
            outhead1("%snc1:", label);
            outline0("CPX #2" );
            outline1("BNE %snc2", label );
            outline0("STA $02C6" )
            outline1("JMP %scdone", label )
            outhead1("%snc2:", label);
            outline0("STA $02C5")
            outhead1("%scdone:", label);
            break;

        case BITMAP_MODE_ANTIC9:
            outline1("LDA %s", _background_color );
            outline0("AND #$0f" );
            outline0("STA $02C8" )
            break;

        case BITMAP_MODE_ANTIC11:
            outline1("LDA %s", _background_color );
            outline0("AND #$0f" );
            outline0("STA $02C4" )
            break;

        case BITMAP_MODE_ANTIC15:
            outline1("LDA #$%2.2x", _index);
            outline0("AND #$01");
            outline0("TAX");
            outline1("LDA %s", _background_color );
            outline0("AND #$0f" );
            outline0("CPX #0" );
            outline1("BNE %snc0", label );
            outline0("STA $02C5" )
            outline1("JMP %scdone", label )
            outhead1("%snc0:", label);
            outline0("STA $02C6")
            outhead1("%scdone:", label);
            break;

        case TILEMAP_MODE_ANTIC4:
        case TILEMAP_MODE_ANTIC5:
            outline1("LDA #$%2.2x", _index);
            outline0("AND #$03");
            outline0("TAX");
            outline1("LDA %s", _background_color );
            outline0("AND #$0f" );
            outline0("CPX #0" );
            outline1("BNE %snc0", label );
            outline0("STA $02C8" )
            outline1("JMP %scdone", label )
            outhead1("%snc0:", label);
            outline0("CPX #1" );
            outline1("BNE %snc1", label );
            outline0("STA $02C4" )
            outline1("JMP %scdone", label )
            outhead1("%snc1:", label);
            outline0("CPX #2" );
            outline1("BNE %snc2", label );
            outline0("STA $02C6" )
            outline1("JMP %scdone", label )
            outhead1("%snc2:", label);
            outline0("STA $02C6")
            outhead1("%scdone:", label);
            break;

        case BITMAP_MODE_ANTIC12:
            outline1("LDA %s", _background_color );
            outline0("AND #$0f" );
            outline0("STA $02C6" )
            break;

        case BITMAP_MODE_ANTIC14:
            outline1("LDA #$%2.2x", _index);
            outline0("AND #$03");
            outline0("TAX");
            outline1("LDA %s", _background_color );
            outline0("AND #$0f" );
            outline0("CPX #0" );
            outline1("BNE %snc0", label );
            outline0("STA $02C8" )
            outline1("JMP %scdone", label )
            outhead1("%snc0:", label);
            outline0("CPX #1" );
            outline1("BNE %snc1", label );
            outline0("STA $02C4" )
            outline1("JMP %scdone", label )
            outhead1("%snc1:", label);
            outline0("CPX #2" );
            outline1("BNE %snc2", label );
            outline0("STA $02C5" )
            outline1("JMP %scdone", label )
            outhead1("%snc2:", label);
            outline0("STA $02C6")
            outhead1("%scdone:", label);
            break;

        case TILEMAP_MODE_ANTIC3:
            break;
    }

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
 
    MAKE_LABEL

    switch( _environment->currentMode ) {
        case TILEMAP_MODE_ANTIC2:
        case TILEMAP_MODE_ANTIC6:
        case TILEMAP_MODE_ANTIC7:
            outline0("LDA #0");
            break;

        case BITMAP_MODE_ANTIC8:
        case BITMAP_MODE_ANTIC10:
        case BITMAP_MODE_ANTIC13:
            outline1("LDA %s", _index);
            outline0("AND #$03");
            outline0("TAX");
            outline0("CPX #0" );
            outline1("BNE %snc0", label );
            outline0("LDA $02C8" )
            outline1("JMP %scdone", label )
            outhead1("%snc0:", label);
            outline0("CPX #1" );
            outline1("BNE %snc1", label );
            outline0("LDA $02C4" )
            outline1("JMP %scdone", label )
            outhead1("%snc1:", label);
            outline0("CPX #2" );
            outline1("BNE %snc2", label );
            outline0("LDA $02C6" )
            outline1("JMP %scdone", label )
            outhead1("%snc2:", label);
            outline0("LDA $02C5")
            outhead1("%scdone:", label);
            break;

        case BITMAP_MODE_ANTIC9:
            outline0("LDA $02C8" )
            break;

        case BITMAP_MODE_ANTIC11:
            outline0("LDA $02C4" )
            break;

        case BITMAP_MODE_ANTIC15:
            outline1("LDA %s", _index);
            outline0("AND #$01");
            outline0("TAX");
            outline0("CPX #0" );
            outline1("BNE %snc0", label );
            outline0("LDA $02C5" )
            outline1("JMP %scdone", label )
            outhead1("%snc0:", label);
            outline0("LDA $02C6")
            outhead1("%scdone:", label);
            break;

        case TILEMAP_MODE_ANTIC4:
        case TILEMAP_MODE_ANTIC5:
            outline1("LDA %s", _index);
            outline0("AND #$03");
            outline0("TAX");
            outline0("CPX #0" );
            outline1("BNE %snc0", label );
            outline0("LDA $02C8" )
            outline1("JMP %scdone", label )
            outhead1("%snc0:", label);
            outline0("CPX #1" );
            outline1("BNE %snc1", label );
            outline0("LDA $02C4" )
            outline1("JMP %scdone", label )
            outhead1("%snc1:", label);
            outline0("CPX #2" );
            outline1("BNE %snc2", label );
            outline0("LDA $02C5" )
            outline1("JMP %scdone", label )
            outhead1("%snc2:", label);
            outline0("LDA $02C6")
            outhead1("%scdone:", label);
            break;

        case BITMAP_MODE_ANTIC12:
            outline0("LDA $02C6" )
            break;

        case BITMAP_MODE_ANTIC14:
            outline1("LDA %s", _index);
            outline0("AND #$03");
            outline0("TAX");
            outline0("CPX #0" );
            outline1("BNE %snc0", label );
            outline0("LDA $02C8" )
            outline1("JMP %scdone", label )
            outhead1("%snc0:", label);
            outline0("CPX #1" );
            outline1("BNE %snc1", label );
            outline0("LDA $02C4" )
            outline1("JMP %scdone", label )
            outhead1("%snc1:", label);
            outline0("CPX #2" );
            outline1("BNE %snc2", label );
            outline0("LDA $02C5" )
            outline1("JMP %scdone", label )
            outhead1("%snc2:", label);
            outline0("LDA $02C6")
            outhead1("%scdone:", label);
            break;

        case TILEMAP_MODE_ANTIC3:
            break;
    }

    outline1("STA %s", _background_color );

}

void gtia_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {

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

void console_calculate( Environment * _environment ) {

    int consoleSA = 0x4000;
    int consoleWB = _environment->activeConsole.width * _environment->currentModeBW;
    int consoleHB = _environment->activeConsole.height * 8;

    cpu_store_16bit( _environment, "CONSOLESA", consoleSA );
    cpu_store_8bit( _environment, "CONSOLEWB", consoleWB );
    cpu_store_8bit( _environment, "CONSOLEHB", consoleHB );

}

void console_calculate_vars( Environment * _environment ) {

    if ( _environment->currentMode >= 2 && _environment->currentMode <= 7 ) {
        outline0( "JSR CONSOLECALCULATE" );
    }

}

void console_update_width_in_bytes( Environment * _environment ) {

    cpu_math_sub_8bit( _environment, "CURRENTTILESWIDTH", "CONSOLEW", "CONSOLESL" );
    cpu_math_sub_8bit( _environment, "CONSOLESL", "CONSOLEX1", "CONSOLESL" );
    cpu_inc( _environment, "CONSOLESL" );

    switch( _environment->currentMode ) {
        case BITMAP_MODE_ANTIC8:
        case BITMAP_MODE_ANTIC10:
        case BITMAP_MODE_ANTIC13:
            cpu_math_mul2_const_8bit( _environment, "CONSOLESL", 1, 0  );
            break;        

        case BITMAP_MODE_ANTIC9:
        case BITMAP_MODE_ANTIC11: 
        case BITMAP_MODE_ANTIC15:
        case BITMAP_MODE_ANTIC12:
        case BITMAP_MODE_ANTIC14:
            break;
            
        case TILEMAP_MODE_ANTIC2:
        case TILEMAP_MODE_ANTIC6:
        case TILEMAP_MODE_ANTIC7:
        case TILEMAP_MODE_ANTIC3:
        case TILEMAP_MODE_ANTIC4:
        case TILEMAP_MODE_ANTIC5:
            break;
        default:
            CRITICAL_SCREEN_UNSUPPORTED( _environment->currentMode );
    }

}


int gtia_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

    int i;
    int screenMemoryOffset = 0;
    int screenMemoryOffset2 = 0;
    int currentHeight = 0;
    int scanline = 0;
    int dliListStartOffset;
    int screenMemoryAddress2 = 0;

    cpu_store_8bit( _environment, "_PEN", _environment->defaultPenColor );
    cpu_store_8bit( _environment, "_PAPER", _environment->defaultPaperColor );

    deploy( gtiavars, src_hw_gtia_vars_asm );
    
    outline1( "; enabling mode %d", _screen_mode->id );

    unsigned char * dliListStart = malloc( DLI_COUNT ), * dliListCurrent = dliListStart;
    
    Variable * dli = variable_retrieve_or_define( _environment, "DLI", VT_BUFFER, 0 );

    _environment->fontWidth = 8;
    _environment->fontHeight = 8;

    _environment->screenShades = 256;
    _environment->screenTiles = 255;
    _environment->currentMode = _screen_mode->id;

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

            // 8	3	4	8	40	10	240
            if ( _environment->frameBufferStart > ( FRAME_BUFFER_ADDRESS - 240 ) ) {
                _environment->frameBufferStart = ( FRAME_BUFFER_ADDRESS - 240 );
            }
            _environment->frameBufferStart = ( _environment->frameBufferStart >> 8 ) << 8;

            _environment->screenWidth = 40;
            _environment->screenHeight = 24;
            _environment->screenColors = 4;
            _environment->currentModeBW = 2;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 72	\Display ANTIC mode 8 (BASIC 3) 64+8
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            // DLI_LMS( dliListCurrent, 8, 0xA000 );
            DLI_LMS_VHSCROLL( dliListCurrent, 8, _environment->frameBufferStart );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<23; ++i ) {
                // 8	\Display ANTIC mode 8 for second mode line
                DLI_MODE_VHSCROLL( dliListCurrent, 8 );
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

            // 9	4	2	4	80	10	480
            if ( _environment->frameBufferStart > ( FRAME_BUFFER_ADDRESS - 480 ) ) {
                _environment->frameBufferStart = ( FRAME_BUFFER_ADDRESS - 480 );
            }
            _environment->frameBufferStart = ( _environment->frameBufferStart >> 8 ) << 8;

            _environment->screenWidth = 80;
            _environment->screenHeight = 48;
            _environment->screenColors = 2;
            _environment->currentModeBW = 1;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 72	\Display ANTIC mode 9 (BASIC 3) 64+9
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            // DLI_LMS( dliListCurrent, 9, 0xA000 );
            DLI_LMS_VHSCROLL( dliListCurrent, 9, _environment->frameBufferStart );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<47; ++i ) {
                // 8	\Display ANTIC mode 9 for second mode line
                DLI_MODE_VHSCROLL( dliListCurrent, 9 );
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

            // A	5	4	4	80	20	960
            if ( _environment->frameBufferStart > ( FRAME_BUFFER_ADDRESS - 960 ) ) {
                _environment->frameBufferStart = ( FRAME_BUFFER_ADDRESS - 960 );
            }
            _environment->frameBufferStart = ( _environment->frameBufferStart >> 8 ) << 8;

            _environment->screenWidth = 80;
            _environment->screenHeight = 48;
            _environment->screenColors = 4;
             _environment->currentModeBW = 2;
           // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 74	\Display ANTIC mode 10 (BASIC 5) 64+10
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            // DLI_LMS( dliListCurrent, 10, 0xA000 );
            DLI_LMS_VHSCROLL( dliListCurrent, 10, _environment->frameBufferStart );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<47; ++i ) {
                // 8	\Display ANTIC mode 10 for second mode line
                DLI_MODE_VHSCROLL( dliListCurrent, 10 );
            }

            DLI_IRQ( dliListCurrent, 10 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=0xA000 - (dliListCurrent - dliListStart) - 16
            DLI_JVB( dliListCurrent, _environment->frameBufferStart - (dliListCurrent - dliListStart) - 16 );
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

            // B	6	2	2	160	20	1920
            if ( _environment->frameBufferStart > ( FRAME_BUFFER_ADDRESS - 1920 ) ) {
                _environment->frameBufferStart = ( FRAME_BUFFER_ADDRESS - 1920 );
            }
            _environment->frameBufferStart = ( _environment->frameBufferStart >> 8 ) << 8;

            _environment->screenWidth = 160;
            _environment->screenHeight = 96;
            _environment->screenColors = 2;
            _environment->currentModeBW = 1;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 75	\Display ANTIC mode 11 (BASIC 8) 64+11
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            // DLI_LMS( dliListCurrent, 11, 0xA000 );
            DLI_LMS_VHSCROLL( dliListCurrent, 11, _environment->frameBufferStart );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<95; ++i ) {
                // 8	\Display ANTIC mode 11 for second mode line
                DLI_MODE_VHSCROLL( dliListCurrent, 11 );
            }

            DLI_IRQ( dliListCurrent, 11 );

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

            // D	7	4	2	160	40	3840
            if ( _environment->frameBufferStart > ( FRAME_BUFFER_ADDRESS - 3840 ) ) {
                _environment->frameBufferStart = ( FRAME_BUFFER_ADDRESS - 3840 );
            }
            _environment->frameBufferStart = ( _environment->frameBufferStart >> 8 ) << 8;

            _environment->screenWidth = 160;
            _environment->screenHeight = 96;
            _environment->screenColors = 4;
            _environment->currentModeBW = 2;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 77	\Display ANTIC mode 13 (BASIC 7) 64+13
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            // DLI_LMS( dliListCurrent, 13, 0xA000 );
            DLI_LMS_VHSCROLL( dliListCurrent, 13, _environment->frameBufferStart );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<96; ++i ) {
                // 8	\Display ANTIC mode 13 for second mode line
                DLI_MODE_VHSCROLL( dliListCurrent, 13 );
            }

            DLI_IRQ( dliListCurrent, 13 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=0xA000 - (dliListCurrent - dliListStart) - 16
            DLI_JVB( dliListCurrent, _environment->frameBufferStart - (dliListCurrent - dliListStart) );
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

            // F	8	2	1	320	40	7680
            if ( _environment->frameBufferStart > ( FRAME_BUFFER_ADDRESS - 7680 ) ) {
                _environment->frameBufferStart = ( FRAME_BUFFER_ADDRESS - 7680 );
            }
            _environment->frameBufferStart = ( _environment->frameBufferStart >> 8 ) << 8;

            _environment->screenWidth = 320;
            _environment->screenHeight = 192;
            _environment->screenColors = 2;
            _environment->currentModeBW = 1;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 81	\Display ANTIC mode 15 (BASIC 7) 64+15
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            // DLI_LMS( dliListCurrent, 15, 0xA000 );
            DLI_LMS_VHSCROLL( dliListCurrent, 15, _environment->frameBufferStart );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<96; ++i ) {
                // 8	\Display ANTIC mode 15 for second mode line
                DLI_MODE_VHSCROLL( dliListCurrent, 15 );
            }

            screenMemoryAddress2 = _environment->frameBufferStart + 4096;

            _environment->frameBufferStart2 = screenMemoryAddress2;
            
            DLI_LMS_VHSCROLL( dliListCurrent, 15,  screenMemoryAddress2 );

            screenMemoryOffset2 = dliListCurrent - dliListStart - 2;

            for( i=0; i<94; ++i ) {
                // 8	\Display ANTIC mode 15 for second mode line
                DLI_MODE_VHSCROLL( dliListCurrent, 15 );
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
        // 160x192, 2 colors
        case BITMAP_MODE_ANTIC12:

            // C	none	2	1	160	20	3840
            if ( _environment->frameBufferStart > ( FRAME_BUFFER_ADDRESS - 3840 ) ) {
                _environment->frameBufferStart = ( FRAME_BUFFER_ADDRESS - 3840 );
            }
            _environment->frameBufferStart = ( _environment->frameBufferStart >> 8 ) << 8;

            _environment->screenWidth = 160;
            _environment->screenHeight = 192;
            _environment->screenColors = 2;
            _environment->currentModeBW = 1;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 76	\Display ANTIC mode 12 64+12
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            // DLI_LMS( dliListCurrent, 12, 0xA000 );
            DLI_LMS( dliListCurrent, 12, _environment->frameBufferStart );

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

            scanline = 20;
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 20 );
            cpu_store_8bit( _environment, "CURRENTSL", scanline );
            break;

        // Antic E (Graphics 15-XL computers only)
        // This four-color, bit-mapped mode is sometimes known as BASIC 7 1/2. Its resolution is 160 x 192 or twice that of 
        // GRAPHIC 7. Each byte is divided into four pairs of bits. Like the character data in ANTIC 4, the bit pairs point to a
        // particular color register. The screen data, however, is not character data but individual bytes. The user has a lot
        // more control, but this mode uses a lot more memory, approximately
        // 160x192, 4 colors
        case BITMAP_MODE_ANTIC14:

            // E	none	4	1	160	40	7680
            if ( _environment->frameBufferStart > ( FRAME_BUFFER_ADDRESS - 7680 ) ) {
                _environment->frameBufferStart = ( FRAME_BUFFER_ADDRESS - 7680 );
            }
            _environment->frameBufferStart = ( _environment->frameBufferStart >> 8 ) << 8;

            _environment->screenWidth = 160;
            _environment->screenHeight = 192;
            _environment->screenColors = 4;
            _environment->currentModeBW = 2;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 76	\Display ANTIC mode 12 64+14
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            // DLI_LMS( dliListCurrent, 14, 0xA000 );
            DLI_LMS_VHSCROLL( dliListCurrent, 14, _environment->frameBufferStart );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for( i=1; i<191; ++i ) {
                // 8	\Display ANTIC mode 15 for second mode line
                DLI_MODE_VHSCROLL( dliListCurrent, 14 );
            }

            DLI_IRQ( dliListCurrent, 14 );

            // 65	\JVB-Jump and wait for Vertical Blank
            // 32	|to display list address which starts
            // 156	/at 32+256*156=0xA000 - (dliListCurrent - dliListStart) - 16
            DLI_JVB( dliListCurrent, dli->absoluteAddress );
            dliListStartOffset = dliListCurrent - dliListStart - 2;

            scanline = 10;
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 20 );
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

            // 2	0	2	8	40	40	960
            if ( _environment->frameBufferStart > ( FRAME_BUFFER_ADDRESS - 960 ) ) {
                _environment->frameBufferStart = ( FRAME_BUFFER_ADDRESS - 960 );
            }
            _environment->frameBufferStart = ( _environment->frameBufferStart >> 8 ) << 8;

            _environment->screenWidth = 40 * _environment->fontWidth;
            _environment->screenHeight = 24 * _environment->fontHeight;
            _environment->screenColors = 2;
            _environment->currentModeBW = 1;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 66	\Display ANTIC mode 2 (BASIC 0) 64+2
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            // DLI_LMS( dliListCurrent, 2, 40000 );
            DLI_LMS_VHSCROLL( dliListCurrent, 2, _environment->frameBufferStart );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for(i=1; i<24; ++i ) {
                // 2	\Display ANTIC mode 2 for second mode line
                DLI_MODE_VHSCROLL( dliListCurrent, 2 );
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

            // 6	1	5	8	20	20	480
            if ( _environment->frameBufferStart > ( FRAME_BUFFER_ADDRESS - 480 ) ) {
                _environment->frameBufferStart = ( FRAME_BUFFER_ADDRESS - 480 );
            }
            _environment->frameBufferStart = ( _environment->frameBufferStart >> 8 ) << 8;

            _environment->screenWidth = 20 * _environment->fontWidth;
            _environment->screenHeight = 24 * _environment->fontHeight;
            _environment->screenColors = 2;
            _environment->currentModeBW = 1;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 66	\Display ANTIC mode 2 (BASIC 0) 64+2
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            // DLI_LMS( dliListCurrent, 6, 40000 );
            DLI_LMS_VHSCROLL( dliListCurrent, 6, _environment->frameBufferStart );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for(i=1; i<23; ++i ) {
                // 2	\Display ANTIC mode 2 for second mode line
                DLI_MODE_VHSCROLL( dliListCurrent, 6 );
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

            // 7	2	5	16	20	20	240
            if ( _environment->frameBufferStart > ( FRAME_BUFFER_ADDRESS - 240 ) ) {
                _environment->frameBufferStart = ( FRAME_BUFFER_ADDRESS - 240 );
            }
            _environment->frameBufferStart = ( _environment->frameBufferStart >> 8 ) << 8;

            _environment->screenWidth = 20 * _environment->fontWidth;
            _environment->screenHeight = 12 * _environment->fontHeight;
            _environment->screenColors = 2;
            _environment->currentModeBW = 1;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 71	\Display ANTIC mode 2 (BASIC 0) 64+7
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            // DLI_LMS( dliListCurrent, 7, 40000 );
            DLI_LMS_VHSCROLL( dliListCurrent, 7, _environment->frameBufferStart );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for(i=1; i<11; ++i ) {
                // 2	\Display ANTIC mode 2 for second mode line
                DLI_MODE_VHSCROLL( dliListCurrent, 7 );
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

            // 3	none	2	10	40	40	760
            if ( _environment->frameBufferStart > ( FRAME_BUFFER_ADDRESS - 760 ) ) {
                _environment->frameBufferStart = ( FRAME_BUFFER_ADDRESS - 760 );
            }
            _environment->frameBufferStart = ( _environment->frameBufferStart >> 8 ) << 8;

            _environment->screenWidth = 40 * _environment->fontWidth;
            _environment->screenHeight = 24 * _environment->fontHeight;
            _environment->screenColors = 2;
            _environment->currentModeBW = 1;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 66	\Display ANTIC mode 2 (BASIC 0) 64+2
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            // DLI_LMS( dliListCurrent, 3, 40000 );
            DLI_LMS_VHSCROLL( dliListCurrent, 3, _environment->frameBufferStart );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for(i=1; i<23; ++i ) {
                // 2	\Display ANTIC mode 2 for second mode line
                DLI_MODE_VHSCROLL( dliListCurrent, 3 );
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

            // 4	none	4	8	40	40	960
            if ( _environment->frameBufferStart > ( FRAME_BUFFER_ADDRESS - 960 ) ) {
                _environment->frameBufferStart = ( FRAME_BUFFER_ADDRESS - 960 );
            }
            _environment->frameBufferStart = ( _environment->frameBufferStart >> 8 ) << 8;

            _environment->screenWidth = 20 * _environment->fontWidth;
            _environment->screenHeight = 24 * _environment->fontHeight;
            _environment->screenColors = 4;
            _environment->currentModeBW = 2;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 66	\Display ANTIC mode 2 (BASIC 0) 64+2
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            // DLI_LMS( dliListCurrent, 4, 40000 );
            DLI_LMS_VHSCROLL( dliListCurrent, 4, _environment->frameBufferStart );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for(i=1; i<23; ++i ) {
                // 2	\Display ANTIC mode 2 for second mode line
                DLI_MODE_VHSCROLL( dliListCurrent, 4 );
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

            // 5	none	4	16	40	40	480
            if ( _environment->frameBufferStart > ( FRAME_BUFFER_ADDRESS - 480 ) ) {
                _environment->frameBufferStart = ( FRAME_BUFFER_ADDRESS - 480 );
            }
            _environment->frameBufferStart = ( _environment->frameBufferStart >> 8 ) << 8;

            _environment->screenWidth = 20 * _environment->fontWidth;
            _environment->screenHeight = 24 * _environment->fontHeight;
            _environment->screenColors = 4;
            _environment->currentModeBW = 2;
            // 112	Blank 8 scan lines to provide for overscan
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 112
            DLI_BLANK( dliListCurrent, 8 );
            // 66	\Display ANTIC mode 2 (BASIC 0) 64+2
            // 64	|Screen memory starts at
            // 156	/64+156*256 =40000
            // DLI_LMS( dliListCurrent, 5, 40000 );
            DLI_LMS_VHSCROLL( dliListCurrent, 5, _environment->frameBufferStart );

            screenMemoryOffset = dliListCurrent - dliListStart - 2;

            for(i=1; i<23; ++i ) {
                // 2	\Display ANTIC mode 2 for second mode line
                DLI_MODE_VHSCROLL( dliListCurrent, 5 );
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

    _environment->screenTilesWidth = _environment->screenWidth / _environment->fontWidth;
    _environment->screenTilesHeight = _environment->screenHeight / _environment->fontHeight;
    _environment->consoleTilesWidth = _environment->screenTilesWidth;
    _environment->consoleTilesHeight = _environment->screenTilesHeight;

    cpu_store_16bit( _environment, "CURRENTWIDTH", _environment->screenWidth );
    cpu_store_16bit( _environment, "CURRENTHEIGHT", _environment->screenHeight );
    cpu_move_16bit( _environment, "CURRENTWIDTH", "RESOLUTIONX" );
    cpu_move_16bit( _environment, "CURRENTHEIGHT", "RESOLUTIONY" );
    cpu_store_8bit( _environment, "CURRENTTILES", _environment->screenTiles );
    cpu_store_8bit( _environment, "CURRENTTILESWIDTH", _environment->screenTilesWidth );
    cpu_store_8bit( _environment, "CURRENTTILESHEIGHT", _environment->screenTilesHeight );
    int consoleX1 = 0;
    if ( _environment->lmarginAtariBasicEnabled && _environment->currentMode == TILEMAP_MODE_ANTIC2 ) {
        consoleX1 = 2;
    }
    cpu_store_8bit( _environment, "CONSOLEX1", consoleX1 );
    cpu_store_8bit( _environment, "CONSOLEY1", 0 );
    cpu_store_8bit( _environment, "CONSOLEX2", _environment->consoleTilesWidth-1 );
    cpu_store_8bit( _environment, "CONSOLEY2", _environment->consoleTilesHeight-1 );
    cpu_store_8bit( _environment, "CONSOLEW", _environment->consoleTilesWidth );
    cpu_store_8bit( _environment, "CONSOLEH", _environment->consoleTilesHeight );

    cpu_store_16bit( _environment, "ORIGINX", 0) ;
    cpu_store_16bit( _environment, "ORIGINY", 0) ;

    cpu_store_16bit( _environment, "CLIPX1", 0) ;
    cpu_store_16bit( _environment, "CLIPX2", _environment->screenWidth-1 );
    cpu_store_16bit( _environment, "CLIPY1", 0) ;
    cpu_store_16bit( _environment, "CLIPY2", _environment->screenHeight-1 );

    cpu_store_16bit( _environment, "TEXTADDRESS", _environment->frameBufferStart );
    cpu_store_16bit( _environment, "BITMAPADDRESS", _environment->frameBufferStart );

    // dli->absoluteAddress = 0xA000 - (dliListCurrent - dliListStart) - 16;

    variable_store_buffer( _environment, dli->name, dliListStart, ( dliListCurrent - dliListStart ), dli->absoluteAddress );

    if ( _screen_mode->bitmap ) {
        outline0("CLC" );
        outline1("LDA #<%s", dli->realName );
        outline1("ADC #$%2.2x", ( screenMemoryOffset & 0xff ) );
        outline0("STA TMPPTR" );
        outline1("LDA #>%s", dli->realName );
        outline1("ADC #$%2.2x", ( ( screenMemoryOffset >> 8 ) & 0xff ) );
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
            outline1("ADC #$%2.2x", ( screenMemoryOffset2 & 0xff ) );
            outline0("STA TMPPTR" );
            outline1("LDA #>%s", dli->realName );
            outline1("ADC #$%2.2x", ( ( screenMemoryOffset2 >> 8 ) & 0xff ) );
            outline0("STA TMPPTR+1" );
            outline0("LDY #0" );

            outline0("CLC" );
            outline1("LDA #$%2.2x", ( screenMemoryAddress2 & 0xff ) );
            outline0("STA (TMPPTR),Y" );
            outline0("INY" );
            outline1("LDA #$%2.2x", ( screenMemoryAddress2 >> 8 ) & 0xff );
            outline0("STA (TMPPTR),Y" );

        }
    } else {
        outline0("CLC" );
        outline1("LDA #<%s", dli->realName );
        outline1("ADC #$%2.2x", ( screenMemoryOffset & 0xff ) );
        outline0("STA TMPPTR" );
        outline1("LDA #>%s", dli->realName );
        outline1("ADC #$%2.2x", ( ( screenMemoryOffset >> 8 ) & 0xff ) );
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
    outline1("ADC #$%2.2x", ( dliListStartOffset & 0xff ) );
    outline0("STA TMPPTR" );
    outline1("LDA #>%s", dli->realName );
    outline1("ADC #$%2.2x", ( ( dliListStartOffset >> 8 ) & 0xff ) );
    outline0("STA TMPPTR+1" );
    outline0("LDY #0" );

    // outline1("LDA #<%s", dli->realName );
    outline0("LDA #<DLI" );
    outline0("STA (TMPPTR),Y" );
    outline0("INY" );
    // outline1("LDA #>%s", dli->realName );
    outline0("LDA #>DLI" );
    outline0("STA (TMPPTR),Y" );

    cpu_mem_move_direct_size( _environment, dli->realName, "DLI", dli->size );

    outline0("SEI" );
    outline0("LDA #<DLI" );
    outline0("STA $230" );
    outline0("LDA #>DLI" );
    outline0("STA $231" );
    outline0("CLI" );

    if ( _environment->vestigialConfig.palettePreserve ) {
        outline0("LDA #$0");
        outline0("STA PALETTEPRESERVEUSED");
        outline0("STA LASTCOLOR");
    }

    outline0("JSR GTIAAFTERINIT");

}

void gtia_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {
    
    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors, 8, 8 );

    if ( mode ) {
        gtia_screen_mode_enable( _environment, mode );
        // printf( "%d\n", mode->id);
        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );    
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 0 );
        _environment->currentMode = mode->id;
        _environment->currentTileMode = 0;
    } else {
        WARNING_SCREEN_MODE( -1 );
    }

}

void gtia_bitmap_disable( Environment * _environment ) {

}

void gtia_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors, _tile_width, _tile_height );

    if ( mode ) {
        gtia_screen_mode_enable( _environment, mode );

        cpu_store_8bit( _environment, "_PEN", _environment->defaultPenColor );
        cpu_store_8bit( _environment, "_PAPER", _environment->defaultPaperColor );

        cpu_store_8bit( _environment, "CURRENTMODE", mode->id );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", 1 );

        _environment->currentMode = mode->id;
        _environment->currentTileMode = 1;
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

void gtia_pset_int( Environment * _environment, int _x, int _y, int *_c ) {

    deploy_deferred( gtiavarsGraphic, src_hw_gtia_vars_graphics_asm );
    deploy( gtiapreproc, src_hw_gtia__preproc_asm );
    deploy( plot, src_hw_gtia_plot_asm );
    
    outline1("LDA %2.2x", (_x & 0xff ) );
    outline0("STA PLOTX");
    outline1("LDA %2.2x", ( ( _x >> 8 ) & 0xff ) );
    outline0("STA PLOTX+1");
    outline1("LDA %2.2x", ( _y & 0xff ) );
    outline0("STA PLOTY");
    if ( _c ) {
        outline1("LDA #$%2.2x", ( *_c & 0xff ) );
    } else {
        Variable * c = variable_retrieve( _environment, "PEN" );
        outline1("LDA %s", c->realName );
    }
    outline0("STA PLOTCPE");
    outline0("LDA #1");
    outline0("STA PLOTM");
    outline0("JSR PLOT");

}

void gtia_pset_vars( Environment * _environment, char *_x, char *_y, char *_c ) {

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    Variable * c;
    
    if ( _c ) {
        c = variable_retrieve_or_define( _environment, _c, VT_COLOR, 0 );
    } else {
        c = variable_retrieve( _environment, "PEN" );
    }

    deploy_deferred( gtiavarsGraphic, src_hw_gtia_vars_graphics_asm );
    deploy( gtiapreproc, src_hw_gtia__preproc_asm );
    deploy( plot, src_hw_gtia_plot_asm );
    
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
    outline1("LDA %s", c->realName);
    outline0("STA PLOTCPE");
    outline0("LDA #1");
    outline0("STA PLOTM");
    outline0("JSR PLOT");

}

void gtia_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );
    Variable * result = variable_retrieve( _environment, _result );

    deploy_deferred( gtiavarsGraphic, src_hw_gtia_vars_graphics_asm );
    deploy( gtiapreproc, src_hw_gtia__preproc_asm );
    deploy( plot, src_hw_gtia_plot_asm );
    
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

void gtia_screen_on( Environment * _environment ) {

}

void gtia_screen_off( Environment * _environment ) {
    
}

void gtia_screen_rows( Environment * _environment, char * _rows ) {

}

void gtia_screen_columns( Environment * _environment, char * _columns ) {

}

void gtia_sprite_data_from( Environment * _environment, char * _sprite, char * _address ) {

}

void gtia_sprite_data_set( Environment * _environment, char * _sprite, char * _address ) {

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

void gtia_sprite_priority( Environment * _environment, char * _sprite, char * _priority ) {

}

void gtia_tiles_at( Environment * _environment, char * _address ) {

}

void gtia_vertical_scroll( Environment * _environment, char * _displacement ) {

    outline1("LDY %s", _displacement );
    outline0("LDA #<YSCROLLOFFSET" );
    outline0("STA TMPPTR" );
    outline0("LDA #>YSCROLLOFFSET" );
    outline0("STA TMPPTR+1" );
    outline0("LDA (TMPPTR),Y" );
    outline0("STA $D405" );

}

void gtia_horizontal_scroll( Environment * _environment, char * _displacement ) {

    outline1("LDY %s", _displacement );
    outline0("LDA #<XSCROLLOFFSET" );
    outline0("STA TMPPTR" );
    outline0("LDA #>XSCROLLOFFSET" );
    outline0("STA TMPPTR+1" );
    outline0("LDA (TMPPTR),Y" );
    outline0("STA $D404" );

}

void gtia_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline1("LDA %s", _timing );
    outline0("STA TMPPTR");
    outline1("LDA %s", address_displacement(_environment, _timing, "1") );
    outline0("STA TMPPTR+1");
    outhead1("%sfirst:", label );
    outline0("LDA $14");
    outhead1("%ssecond:", label );
    outline0("CMP $14");
    outline1("BEQ %ssecond", label);
    outline0("DEC TMPPTR");
    outline0("LDA TMPPTR");
    outline0("CMP #$FF");
    outline1("BNE %sfirst", label);
    outline0("DEC TMPPTR+1");
    outline0("LDA TMPPTR+1");
    outline0("CMP #$FF");
    outline1("BNE %sfirst", label);
    outline1("%sthird:", label);

}

void gtia_get_width( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTWIDTH" );
    outline1("STA %s", _result );
    outline0("LDA CURRENTWIDTH+1" );
    outline1("STA %s", address_displacement(_environment, _result, "1") );

}

void gtia_get_height( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTHEIGHT" );
    outline1("STA %s", _result );
    outline0("LDA CURRENTHEIGHT+1" );
    outline1("STA %s", address_displacement(_environment, _result, "1") );

}

void gtia_tiles_get( Environment * _environment, char *_result ) {

    outline0("LDA CURRENTTILES" );
    outline1("STA %s", _result );

}

void gtia_cls( Environment * _environment ) {
    
    deploy( cls, src_hw_gtia_cls_asm );

    outline0("LDA #$0");
    outline0("STA PATTERN");
    outline0("JSR CLS");

}

void gtia_cls_box( Environment * _environment, char * _x1, char * _y1, char * _w, char * _h ) {
    
    deploy( clsBox, src_hw_gtia_cls_box_asm );

    outline1("LDA %s", _x1);
    outline0("STA IMAGEX");
    outline1("LDA %s", address_displacement( _environment, _x1, "1" ) );
    outline0("STA IMAGEX+1");
    outline1("LDA %s", _y1);
    outline0("STA IMAGEY");
    outline1("LDA %s", _w);
    outline0("STA IMAGEW");
    outline1("LDA %s", address_displacement( _environment, _w, "1" ) );
    outline0("STA IMAGEW+1");
    outline1("LDA %s", _h);
    outline0("STA IMAGEH");
    outline0("JSR CLSBOX");

}

void gtia_clear( Environment * _environment, char * _pattern ) {
    
    deploy( cls, src_hw_gtia_cls_asm );

    outline1("LDA %s", _pattern );
    outline0("STA PATTERN");
    outline0("JSR CLS");

}

void gtia_scroll_text( Environment * _environment, int _direction, int _overlap ) {

    deploy_preferred( vScrollText, src_hw_gtia_vscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );
    outline1("LDA #$%2.2x", ( _overlap & 0xff ) );
    outline0("STA PORT" );

    outline0("JSR VSCROLLT");

}

void gtia_text( Environment * _environment, char * _text, char * _text_size, int _raw ) {

    deploy( gtiavars, src_hw_gtia_vars_asm );
    deploy_deferred( gtiavarsGraphic, src_hw_gtia_vars_graphics_asm );
    deploy_preferred( vScrollText, src_hw_gtia_vscroll_text_asm );
    deploy( cls, src_hw_gtia_cls_asm );
    deploy( textEncodedAt, src_hw_gtia_text_at_asm );

    outline1("LDA %s", _text);
    outline0("STA TEXTPTR" );
    outline1("LDA %s", address_displacement(_environment, _text, "1"));
    outline0("STA TEXTPTR+1" );
    outline1("LDA %s", _text_size);
    outline0("STA TEXTSIZE" );

    if ( _raw ) {
        if ( _environment->currentMode >= 2 && _environment->currentMode <= 7 ) {
            deploy( gtiapreproc, src_hw_gtia__preproc_asm );
            deploy( textEncodedAtTextRaw, src_hw_gtia_text_at_text_raw_asm );
            outline0("JSR TEXTATTILEMODERAW");
        } else {
            deploy( gtiapreproc, src_hw_gtia__preproc_asm );
            deploy( textEncodedAtGraphicRaw, src_hw_gtia_text_at_graphic_raw_asm );
            outline0("JSR TEXTATBITMAPMODERAW");
        }
    } else {
        if ( _environment->currentMode >= 2 && _environment->currentMode <= 7 ) {
            deploy( gtiapreproc, src_hw_gtia__preproc_asm );
            deploy( textEncodedAtText, src_hw_gtia_text_at_text_asm );
            outline0("JSR TEXTATTILEMODE");
        } else {
            deploy( gtiapreproc, src_hw_gtia__preproc_asm );
            deploy( textEncodedAtGraphic, src_hw_gtia_text_at_graphic_asm );
            outline0("JSR TEXTATBITMAPMODE");
        }
    }

}

void gtia_initialization( Environment * _environment ) {

    _environment->vestigialConfig.palettePreserve = 1;
    
    deploy_preferred( gtiavars, src_hw_gtia_vars_asm );
    deploy_preferred( gtiastartup, src_hw_gtia_startup_asm );

    variable_import( _environment, "CURRENTWIDTH", VT_POSITION, 320 );
    variable_global( _environment, "CURRENTWIDTH" );
    variable_import( _environment, "CURRENTHEIGHT", VT_POSITION, 199  );
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

#ifdef __atarixl__
    //SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC14, 1, 160, 192, 4, 8, 8, "Antic E (Graphics 15-XL computers only)"  );
#endif
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC13, 1, 160, 96, 4, 8, 8, "Graphics 7 (ANTIC D or 13)"  );
#ifdef __atarixl__
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC15, 1, 320, 192, 1, 8, 8, "Graphics 8 (ANTIC F or 15)"  );
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC12, 1, 160, 192, 2, 8, 8, "Antic C (Graphics 14-XL computers only)"  );
#endif
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC8, 1, 40, 24, 4, 8, 8, "Graphics 3 (ANTIC 8)" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC9, 1, 80, 48, 2, 8, 8, "Graphics 4 (ANTIC 9)"  );
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC10, 1, 80, 48, 4, 8, 8, "Graphics 5 (ANTIC A or 10)"  );
    SCREEN_MODE_DEFINE( BITMAP_MODE_ANTIC11, 1, 160, 96, 2, 8, 8, "Graphics 6 (ANTIC B or 11)"  );

    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC2, 0, 40, 24, 1, 8, 8, "Graphics Mode 0 (ANTIC 2)"  );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC6, 0, 20, 24, 4, 8, 8, "Graphics 1 (ANTIC 6)"  );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC7, 0, 20, 12, 4, 8, 8, "Graphics 2 (ANTIC 7)"  );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC3, 0, 40, 24, 4, 8, 8, "Antic 3"  );

#ifdef __atarixl__
    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC4, 0, 40, 24, 4, 8, 8, "Antic 4 (Graphics 12-XL computers only)"  );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_ANTIC5, 0, 40, 24, 4, 8, 8, "Antic 5 (Graphics 13-XL computers only)"  );
#endif

    outline0("JSR GTIASTARTUP");
    outline0("JSR GTIAUDCCHAR");

    variable_import( _environment, "CURRENTMODE", VT_BYTE, 0 );
    variable_global( _environment, "CURRENTMODE" );
    variable_import( _environment, "CURRENTTILEMODE", VT_BYTE, 1 );
    variable_global( _environment, "CURRENTTILEMODE" );

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

    variable_import( _environment, "ORIGINX", VT_POSITION, 0 );
    variable_global( _environment, "ORIGINX" );
    variable_import( _environment, "ORIGINY", VT_POSITION, 0 );
    variable_global( _environment, "ORIGINY" );

    variable_import( _environment, "RESOLUTIONX", VT_POSITION, 0 );
    variable_global( _environment, "RESOLUTIONX" );
    variable_import( _environment, "RESOLUTIONY", VT_POSITION, 0 );
    variable_global( _environment, "RESOLUTIONY" );

    _environment->currentMode = 2;
    _environment->currentTileMode = 1;

    _environment->currentRgbConverterFunction = rgbConverterFunction;
#if defined(__atari__)
    _environment->frameBufferStart = 0xbf00; // 256 byte boundary alignment
#else
    _environment->frameBufferStart = 0xbf00; // 256 byte boundary alignment
#endif

    gtia_tilemap_enable( _environment, 40, 24, 1, 8, 8 );

    if (_environment->vestigialConfig.clsImplicit ) {
        gtia_cls( _environment );
    }

}

void gtia_finalization( Environment * _environment ) {

    if (_environment->vestigialConfig.clsImplicit ) {
        deploy( cls, src_hw_gtia_cls_asm );
    }

}

void gtia_hscroll_line( Environment * _environment, int _direction, int _overlap ) {

    deploy_preferred( textHScroll, src_hw_gtia_hscroll_text_asm );

    Variable * y = variable_retrieve( _environment, "YCURSYS" );
    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );
    outline1("LDA #$%2.2x", ( _overlap & 0xff ) );
    outline0("STA PORT" );
    outline1("LDA %s", y->realName );
    outline0("STA CLINEY");

    outline0("JSR HSCROLLLT");

}

void gtia_hscroll_screen( Environment * _environment, int _direction, int _overlap ) {

    deploy_preferred( textHScroll, src_hw_gtia_hscroll_text_asm );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );
    outline1("LDA #$%2.2x", ( _overlap & 0xff ) );
    outline0("STA PORT" );

    outline0("JSR HSCROLLST");
}

void gtia_back( Environment * _environment ) {

    deploy( gtiapreproc, src_hw_gtia__preproc_asm );
    deploy( back, src_hw_gtia_back_asm );

    outline0("JSR BACK");

}

void gtia_cline( Environment * _environment, char * _characters ) {

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

    if ( _environment->currentMode >= 2 && _environment->currentMode <= 7 ) {
        deploy( textCline, src_hw_gtia_cline_text_asm );
        outline0("JSR CLINE");
    } else {
        deploy( textClineGraphic, src_hw_gtia_cline_graphic_asm );
        outline0("JSR CLINEG");
    }

}

int gtia_image_size( Environment * _environment, int _width, int _height, int _mode ) {

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
            return 3 + ( ( _width >> 2 ) * _height ) + 4;

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
            return 3 + ( ( _width >> 3 ) * _height ) + 2;

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

static int calculate_images_size( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

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
            return 3 + ( 3 + ( ( _width >> 2 ) * _height ) + 4 ) * _frames;

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
            return 3 + ( 3 + ( ( _width >> 3 ) * _height ) + 2 ) * _frames;

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

static int calculate_sequence_size( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

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
            return 3 + ( ( 3 + ( ( _width >> 2 ) * _height ) + 4 ) * _frames ) * _sequences;

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
            return 3 + ( ( 3 + ( ( _width >> 3 ) * _height ) + 2 ) * _frames ) * _sequences;

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

static Variable * gtia_image_converter_bitmap_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    // ignored on bitmap mode
    (void)!_transparent_color;

    image_converter_asserts_free_height( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    if ( _environment->freeImageWidth ) {
        if ( _width % 8 ) {
            _width = ( ( ( _width - 1 ) / 8 ) - 1 ) * 8;
        }
        if ( _frame_width % 8 ) {
            _frame_width = ( ( ( _frame_width - 1 ) / 8 ) - 1 ) * 8;
        }
    }

    RGBi * palette = malloc_palette( MAX_PALETTE );
    
    int paletteColorCount = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    if (paletteColorCount > 2) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( paletteColorCount );
    }

    int i, j, k;

    if ( ! commonPalette ) {

        commonPalette = palette_match( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
        commonPalette = palette_remove_duplicates( commonPalette, paletteColorCount, &paletteColorCount );

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

        RGBi * newPalette = palette_match( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
        newPalette = palette_remove_duplicates( newPalette, paletteColorCount, &paletteColorCount );
        adilinepalette( "CPM1:%d", paletteColorCount, newPalette );

        int mergedCommonPalette = 0;

        commonPalette = palette_merge( commonPalette, lastUsedSlotInCommonPalette, newPalette, paletteColorCount, &mergedCommonPalette );

        if ( _transparent_color & 0x0f0000 ) {
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, mergedCommonPalette );
        }
        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, mergedCommonPalette, 2 );
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

    int bufferSize = gtia_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_ANTIC9 );

    adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_ANTIC9 );

    adilinebeginbitmap("BMD");

    char * buffer = malloc ( bufferSize );

    // Position of the pixel in the original image
    int image_x, image_y;
    
    // Position of the pixel, in terms of tiles
    int tile_x, tile_y;
    
    // Position of the pixel, in terms of offset and bitmask
    int offset, bitmask;

    int colorIndex;

    // Color of the pixel to convert
    RGBi rgb;

    *(buffer) = (_frame_width & 0xff);
    *(buffer+1) = ( _frame_width >> 8 ) & 0xff;
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

            if ( rgb.alpha < 255 ) {
                colorIndex = 0;
            } else {
                int minDistance = 9999;
                for( int i=(_transparent_color); i<lastUsedSlotInCommonPalette; ++i ) {
                    int distance = rgbi_distance(&commonPalette[i], &rgb );
                    if ( distance < minDistance ) {
                        minDistance = distance;
                        colorIndex = i;
                    }
                }
            }

            adilinepixel(colorIndex);

            // printf("%d", i );

            // Calculate the offset starting from the tile surface area
            // and the bit to set.
            offset = (image_y *( _frame_width >> 3 ) ) + (image_x >> 3 );
            bitmask = 1 << ( 7 - (image_x & 0x7) );

            if ( colorIndex == 1 ) {
                *( buffer + offset + 3) |= bitmask;
                // printf( "%1.1x", commonPalette[1].index );
            } else {
                *( buffer + offset + 3) &= ~bitmask;
                // printf( "%1.1x", commonPalette[0].index );
            }

            _source += _depth;

        }

        // printf( "\n" );

        _source += ( _width - _frame_width ) * _depth;

        // printf("\n" );

    }

    // printf( "\n\n\n" );

    adilineendbitmap();

    if ( lastUsedSlotInCommonPalette > 1 ) {
        *(buffer + 3 + ( ( _frame_width >> 3 ) * _frame_height ) + 1 ) = palette[1].index;
    } else {
        *(buffer + 3 + ( ( _frame_width >> 3 ) * _frame_height ) + 1 ) = 0xff;
    }

    if ( lastUsedSlotInCommonPalette > 0 ) {
        *(buffer + 3 + ( ( _frame_width >> 3 ) * _frame_height ) ) = palette[0].index;
    } else {
        *(buffer + 3 + ( ( _frame_width >> 3 ) * _frame_height ) ) = 0xff;
    }

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    return result;

}


static Variable * gtia_image_converter_multicolor_mode_standard( Environment * _environment, char * _source, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _transparent_color, int _flags ) {

    // ignored on bitmap mode
    (void)!_transparent_color;

    image_converter_asserts_free_height( _environment, _width, _height, _offset_x, _offset_y, &_frame_width, &_frame_height );

    if ( _environment->freeImageWidth ) {
        if ( _width % 8 ) {
            _width = ( ( ( _width - 1 ) / 8 ) - 1 ) * 8;
        }
        if ( _frame_width % 8 ) {
            _frame_width = ( ( ( _frame_width - 1 ) / 8 ) - 1 ) * 8;
        }
    }

    RGBi * palette = malloc_palette( MAX_PALETTE );
    
    int paletteColorCount = rgbi_extract_palette(_environment, _source, _width, _height, _depth, palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    if (paletteColorCount > 4) {
        CRITICAL_IMAGE_CONVERTER_TOO_COLORS( paletteColorCount );
    }

    int i, j, k;

    if ( ! commonPalette ) {

        commonPalette = palette_match( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
        commonPalette = palette_remove_duplicates( commonPalette, paletteColorCount, &paletteColorCount );

        if ( _transparent_color & 0x0f0000 ) {
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, paletteColorCount );
        }
        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, paletteColorCount, 4 );
            paletteColorCount = 4;
        }

        lastUsedSlotInCommonPalette = paletteColorCount;
        adilinepalette( "CPM1:%d", paletteColorCount, commonPalette );

    } else {

        RGBi * newPalette = palette_match( palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) );
        newPalette = palette_remove_duplicates( newPalette, paletteColorCount, &paletteColorCount );
        adilinepalette( "CPM1:%d", paletteColorCount, newPalette );

        int mergedCommonPalette = 0;

        commonPalette = palette_merge( commonPalette, lastUsedSlotInCommonPalette, newPalette, paletteColorCount, &mergedCommonPalette );

        if ( _transparent_color & 0x0f0000 ) {
            commonPalette = palette_promote_color_as_background( _transparent_color & 0xff, commonPalette, mergedCommonPalette );
        }
        if ( _transparent_color & 0xf00000 ) {
            commonPalette = palette_promote_color_as_foreground( ( _transparent_color >> 8 ) & 0xff, commonPalette, mergedCommonPalette, 4 );
            mergedCommonPalette = 4;
        }

        lastUsedSlotInCommonPalette = mergedCommonPalette;
        if ( lastUsedSlotInCommonPalette > 4 ) {
            lastUsedSlotInCommonPalette = 4;
        }
        adilinepalette( "CPM2:%d", lastUsedSlotInCommonPalette, commonPalette );

    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );
    result->originalColors = lastUsedSlotInCommonPalette;
    memcpy( result->originalPalette, commonPalette, lastUsedSlotInCommonPalette * sizeof( RGBi ) );

    int bufferSize = gtia_image_size( _environment, _frame_width, _frame_height, BITMAP_MODE_ANTIC8 );
    
    adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_ANTIC8 );

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

    *(buffer) = (_frame_width & 0xff);
    *(buffer+1) = (_frame_width >> 8 ) & 0xff;
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

            // Calculate the offset starting from the tile surface area
            // and the bit to set.
            offset = (image_y * ( _frame_width >> 2 ) ) + (image_x>>2);

            int colorIndex = 0;

            if ( rgb.alpha < 255 ) {
                colorIndex = 0;
            } else {
                int minDistance = 9999;
                for( int i=(_transparent_color); i<lastUsedSlotInCommonPalette; ++i ) {
                    int distance = rgbi_distance(&commonPalette[i], &rgb );
                    if ( distance < minDistance ) {
                        minDistance = distance;
                        colorIndex = i;
                    }
                }
            }

            if ( _environment->debugImageLoad ) {
                printf("%1.1x", colorIndex );
            }

            adilinepixel(colorIndex);

            bitmask = colorIndex << (6 - ((image_x & 0x3) * 2));

            *(buffer + 3 + offset) |= bitmask;

            _source += _depth;

        }

        _source += ( _width - _frame_width ) * _depth;

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

    adilineendbitmap();

    *(buffer + 3 + ( ( _frame_width >> 2 ) * _frame_height ) ) = commonPalette[0].index;

    if ( lastUsedSlotInCommonPalette > 1 ) {
        *(buffer + 3 + ( ( _frame_width >> 2 ) * _frame_height ) + 1 ) = commonPalette[1].index;
    } else {
        *(buffer + 3 + ( ( _frame_width >> 2 ) * _frame_height ) + 1 ) = 0xff;
    }

    if ( lastUsedSlotInCommonPalette > 2 ) {
        *(buffer + 3 + ( ( _frame_width >> 2 ) * _frame_height ) + 2 ) = commonPalette[2].index;
    } else {
        *(buffer + 3 + ( ( _frame_width >> 2 ) * _frame_height ) + 2 ) = 0xff;
    }

    if ( lastUsedSlotInCommonPalette > 3 ) {
        *(buffer + 3 + ( ( _frame_width >> 2 ) * _frame_height ) + 3 ) = commonPalette[3].index;
    } else {
        *(buffer + 3 + ( ( _frame_width >> 2 ) * _frame_height ) + 3 ) = 0xff;
    }

    variable_store_buffer( _environment, result->name, buffer, bufferSize, 0 );

    return result;

}

Variable * gtia_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

    switch( _mode ) {
        // Graphics 3 (ANTIC 8)
        // This four-color graphics mode turns a split screen into 20 rows of 40 graphics cells or pixels. 
        // Each pixel is 8 x 8 or the size of a normal character. The data in each pixel is encoded as two bit pairs, 
        // four per byte. The four possible bit pair combinations 00, 01, 10, and 11 point to one of the four color registers. 
        // The bits 00 is assigned to the background color register and the rest refer to the three foreground color registers. 
        // When the CTIA/GTIA chip interprets the data for the four adjacent pixels stored within the byte, it refers to the color 
        // register encoded in the bit pattern to plot the color.
        case BITMAP_MODE_ANTIC8:
            return gtia_image_converter_multicolor_mode_standard( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height , _transparent_color, _flags );

        // Graphics 4 (ANTIC 9)
        // This is a two-color graphics mode with four times the resolution of GRAPHICS 3. The pixels are 4 x 4, and 48 rows of 80 
        // pixels fit on a full screen. A single bit is used to store each pixel's color register. A zero refers to the background 
        // color register and a one to the foreground color register. The mode is used primarily to conserve screen memory. 
        // Only one bit is used for the color, so eight adjacent pixels are encoded within one byte, and only half as much screen 
        // memory is needed for a display of similiar-sized pixels.
        case BITMAP_MODE_ANTIC9:
            return gtia_image_converter_bitmap_mode_standard( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height , _transparent_color, _flags );

        // Graphics 5 (ANTIC A or 10)
        // This is the four color equivalent of GRAPHICS 4 sized pixels. The pixels are 4 x 4, but two bits are required to address 
        // the four color registers. With only four adjacent pixels encoded within a byte, the screen uses twice as much memory, 
        // about 1K.
        case BITMAP_MODE_ANTIC10:
            return gtia_image_converter_multicolor_mode_standard( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height , _transparent_color, _flags );

        // Graphics 6 (ANTIC B or 11)
        // This two color graphics mode has reasonably fine resolution. The 2 x 2 sized pixels allow 96 rows of 160 pixels to fit 
        // on a full screen. Although only a single bit is used to encode the color, screen memory still requires approximately 2K.
        case BITMAP_MODE_ANTIC11:
            return gtia_image_converter_bitmap_mode_standard( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height , _transparent_color, _flags );

        // Graphics 7 (ANTIC D or 13)
        // This is the four color equivalent to GRAPHICS mode 6. It is the finest resolution four color mode and naturally the
        // most popular. The color is encoded in two bit-pairs exactly the same way as in GRAPHICS 3. The memory requirements 
        // of course is much greater as there are 96 rows of 160 - 2 x 2 sized pixels. It requires 3840 bytes of screen memory
        // with another 104 bytes for the display list.
        case BITMAP_MODE_ANTIC13:
            return gtia_image_converter_multicolor_mode_standard( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height , _transparent_color, _flags );

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
            return gtia_image_converter_bitmap_mode_standard( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height , _transparent_color, _flags );

        // The following five graphics modes have no equivalent in BASIC on older machine but if indicated do correspond to
        // an equivalent graphics mode on the newer XL models.

        // Antic C (Graphics 14-XL computers only)
        // This two-color, bit-mapped mode the eight bits correspond directly to the pixels on the screen. If a pixel is lit 
        // it receives its color information from color register #0, otherwise the color is set to the background color 
        // register #4. Each pixel is one scan line high and one color clock wide. This mode's advantages are that it 
        // only uses 4K of screen memory and doesn't have artifacting problems.
        case BITMAP_MODE_ANTIC12:
            return gtia_image_converter_bitmap_mode_standard( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height , _transparent_color, _flags );

        // Antic E (Graphics 15-XL computers only)
        // This four-color, bit-mapped mode is sometimes known as BASIC 7 1/2. Its resolution is 160 x 192 or twice that of 
        // GRAPHIC 7. Each byte is divided into four pairs of bits. Like the character data in ANTIC 4, the bit pairs point to a
        // particular color register. The screen data, however, is not character data but individual bytes. The user has a lot
        // more control, but this mode uses a lot more memory, approximately
        case BITMAP_MODE_ANTIC14:
            return gtia_image_converter_multicolor_mode_standard( _environment, _data, _width, _height, _depth, _offset_x, _offset_y, _frame_width, _frame_height , _transparent_color, _flags );

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

    WARNING_IMAGE_CONVERTER_UNSUPPORTED_MODE( _mode );

    return gtia_new_image( _environment, 8, 8, BITMAP_MODE_ANTIC13 );

}

static void gtia_load_image_address_to_other_register( Environment * _environment, char * _register, char * _source, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

    outline1("LDA #<%s", _source );
    outline1("STA %s", _register );
    outline1("LDA #>%s", _source );
    outline1("STA %s", address_displacement(_environment, _register, "1") );

    if ( _sequence ) {

        outline0("CLC" );
        outline1("LDA %s", _register );
        outline0("ADC #3" );
        outline1("STA %s", _register );
        outline1("LDA %s", address_displacement(_environment, _register, "1") );
        outline0("ADC #0" );
        outline1("STA %s", address_displacement(_environment, _register, "1") );
        if ( strlen(_sequence) == 0 ) {

        } else {
            outline1("LDA #<OFFSETS%4.4x", _frame_size * _frame_count );
            outline0("STA MATHPTR0" );
            outline1("LDA #>OFFSETS%4.4x", _frame_size * _frame_count );
            outline0("STA MATHPTR0+1" );
            outline0("CLC" );
            outline1("LDA %s", _sequence );
            outline0("ASL" );
            outline0("TAY" );
            outline1("LDA %s", _register );
            outline0("ADC (MATHPTR0), Y" );
            outline1("STA %s", _register );
            outline0("INY" );
            outline1("LDA %s", address_displacement(_environment, _register, "1") );
            outline0("ADC (MATHPTR0), Y" );
            outline1("STA %s", address_displacement(_environment, _register, "1") );
        }

        if ( _frame ) {
            if ( strlen(_frame) == 0 ) {

            } else {
                outline1("LDA #<OFFSETS%4.4x", _frame_size );
                outline0("STA MATHPTR0" );
                outline1("LDA #>OFFSETS%4.4x", _frame_size );
                outline0("STA MATHPTR0+1" );
                outline0("CLC" );
                outline1("LDA %s", _frame );
                outline0("ASL" );
                outline0("TAY" );
                outline1("LDA %s", _register );
                outline0("ADC (MATHPTR0), Y" );
                outline1("STA %s", _register );
                outline0("INY" );
                outline1("LDA %s", address_displacement(_environment, _register, "1") );
                outline0("ADC (MATHPTR0), Y" );
                outline1("STA %s", address_displacement(_environment, _register, "1") );
            }
        }

    } else {

        if ( _frame ) {
            outline0("CLC" );
            outline1("LDA %s", _register );
            outline0("ADC #3" );
            outline1("STA %s", _register );
            outline1("LDA %s", address_displacement(_environment, _register, "1") );
            outline0("ADC #0" );
            outline1("STA %s", address_displacement(_environment, _register, "1") );
            if ( strlen(_frame) == 0 ) {

            } else {
                outline1("LDA #<OFFSETS%4.4x", _frame_size );
                outline0("STA MATHPTR0" );
                outline1("LDA #>OFFSETS%4.4x", _frame_size );
                outline0("STA MATHPTR0+1" );
                outline0("CLC" );
                outline1("LDA %s", _frame );
                outline0("ASL" );
                outline0("TAY" );
                outline1("LDA %s", _register );
                outline0("ADC (MATHPTR0), Y" );
                outline1("STA %s", _register );
                outline0("INY" );
                outline1("LDA %s", address_displacement(_environment, _register, "1") );
                outline0("ADC (MATHPTR0), Y" );
                outline1("STA %s", address_displacement(_environment, _register, "1") );
            }
        }

    }

}


static void gtia_load_image_address_to_register( Environment * _environment, char * _register, Resource * _source, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

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

void gtia_put_image( Environment * _environment, Resource * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _flags ) {

    deploy( gtiavars, src_hw_gtia_vars_asm);
    deploy_deferred( gtiavarsGraphic, src_hw_gtia_vars_graphics_asm );
    deploy( gtiapreproc, src_hw_gtia__preproc_asm );
    deploy( putimage, src_hw_gtia_put_image_asm );

    if ( _frame_size ) {
        gtia_load_image_address_to_register( _environment, "TMPPTR", _image, _sequence, _frame, _frame_size, _frame_count );
    }

    outline1("LDA %s", _x );
    outline0("STA IMAGEX" );
    outline1("LDA %s", address_displacement(_environment, _x, "1") );
    outline0("STA IMAGEX+1" );
    outline1("LDA %s", _y );
    outline0("STA IMAGEY" );
    outline1("LDA %s", address_displacement(_environment, _y, "1") );
    outline0("STA IMAGEY+1" );
    if ( strchr( _flags, '#' ) ) {
        outline1("LDA #(%s)&255", _flags+1 );
        outline0("STA IMAGEF" );
        outline1("LDA #((%s)>>8)&255", _flags+1 );
        outline0("STA IMAGET" );
    } else {
        outline1("LDA %s", _flags );
        outline0("STA IMAGEF" );
        outline1("LDA %s", address_displacement(_environment, _flags, "1") );
        outline0("STA IMAGET" );
    }

    outline0("JSR PUTIMAGE");

}

void gtia_put_tile( Environment * _environment, char * _tile, char * _x, char * _y ) {

    deploy( gtiavars, src_hw_gtia_vars_asm);
    deploy_deferred( gtiavarsGraphic, src_hw_gtia_vars_graphics_asm );
    deploy( tiles, src_hw_gtia_tiles_asm );

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


void gtia_move_tiles( Environment * _environment, char * _tile, char * _x, char * _y ) {

    Variable * tile = variable_retrieve( _environment, _tile );
    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy( gtiavars, src_hw_gtia_vars_asm);
    deploy_deferred( gtiavarsGraphic, src_hw_gtia_vars_graphics_asm );
    deploy( tiles, src_hw_gtia_tiles_asm );

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

void gtia_calculate_sequence_frame_offset( Environment * _environment, char * _offset, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

    outline0("LDA #0");
    outline1("STA %s", _offset );
    outline1("STA %s", address_displacement(_environment, _offset, "1") );

    if ( _sequence ) {

        outline0("CLC" );
        outline1("LDA %s", _offset );
        outline0("ADC #3" );
        outline1("STA %s", _offset );
        outline1("LDA %s", address_displacement(_environment, _offset, "1") );
        outline0("ADC #0" );
        outline1("STA %s", address_displacement(_environment, _offset, "1") );
        if ( strlen(_sequence) == 0 ) {

        } else {
            outline1("LDA #<OFFSETS%4.4x", _frame_size * _frame_count );
            outline0("STA MATHPTR0" );
            outline1("LDA #>OFFSETS%4.4x", _frame_size * _frame_count );
            outline0("STA MATHPTR1" );
            outline0("CLC" );
            outline1("LDA %s", _sequence );
            outline0("ASL" );
            outline0("TAY" );
            outline1("LDA %s", _offset );
            outline0("ADC (MATHPTR0), Y" );
            outline1("STA %s", _offset );
            outline0("INY" );
            outline1("LDA %s", address_displacement(_environment, _offset, "1") );
            outline0("ADC (MATHPTR0), Y" );
            outline1("STA %s", address_displacement(_environment, _offset, "1") );
        }

        if ( _frame ) {
            if ( strlen(_frame) == 0 ) {

            } else {
                outline1("LDA #<OFFSETS%4.4x", _frame_size );
                outline0("STA MATHPTR0" );
                outline1("LDA #>OFFSETS%4.4x", _frame_size );
                outline0("STA MATHPTR1" );
                outline0("CLC" );
                outline1("LDA %s", _frame );
                outline0("ASL" );
                outline0("TAY" );
                outline1("LDA %s", _offset );
                outline0("ADC (MATHPTR0), Y" );
                outline1("STA %s", _offset );
                outline0("INY" );
                outline1("LDA %s", address_displacement(_environment, _offset, "1") );
                outline0("ADC (MATHPTR0), Y" );
                outline1("STA %s", address_displacement(_environment, _offset, "1") );
            }
        }

    } else {

        if ( _frame ) {
            outline0("CLC" );
            outline1("LDA %s", _offset );
            outline0("ADC #3" );
            outline1("STA %s", _offset );
            outline1("LDA %s", address_displacement(_environment, _offset, "1") );
            outline0("ADC #0" );
            outline1("STA %s", address_displacement(_environment, _offset, "1") );
            if ( strlen(_frame) == 0 ) {

            } else {
                outline1("LDA #<OFFSETS%4.4x", _frame_size );
                outline0("STA MATHPTR0" );
                outline1("LDA #>OFFSETS%4.4x", _frame_size );
                outline0("STA MATHPTR0+1" );
                outline0("CLC" );
                outline1("LDA %s", _frame );
                outline0("ASL" );
                outline0("TAY" );
                outline1("LDA %s", _offset );
                outline0("ADC (MATHPTR0), Y" );
                outline1("STA %s", _offset );
                outline0("INY" );
                outline1("LDA %s", address_displacement(_environment, _offset, "1") );
                outline0("ADC (MATHPTR0), Y" );
                outline1("STA %s", address_displacement(_environment, _offset, "1") );
            }
        }

    }

}

void gtia_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

    deploy( gtiavars, src_hw_gtia_vars_asm);
    deploy_deferred( gtiavarsGraphic, src_hw_gtia_vars_graphics_asm );
    deploy( gtiapreproc, src_hw_gtia__preproc_asm );
    deploy( blitimage, src_hw_gtia_blit_image_asm );

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
        resource.isAddress = 0;
        gtia_load_image_address_to_register( _environment, "BLITTMPPTR", &resource, _sequence, _frame, _frame_size, _frame_count );
    } else {
        outline0( "LDA #$0" );
        outline0( "STA BLITTMPPTR" );
        outline0( "STA BLITTMPPTR+1" );
    }

    if ( _source_count > 1 ) {
        Resource resource;
        resource.realName = strdup( _sources[0] );
        resource.type = VT_IMAGE;
        resource.isAddress = 0;
        gtia_load_image_address_to_register( _environment, "BLITTMPPTR2", &resource, _sequence, _frame, _frame_size, _frame_count );
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

void gtia_put_tiles( Environment * _environment, char * _tile, char * _x, char * _y, char *_w, char *_h ) {

    deploy( gtiavars, src_hw_gtia_vars_asm);
    deploy( tiles, src_hw_gtia_tiles_asm );

    outline1("LDA %s", _tile );
    outline0("STA TILET" );
    outline1("LDA %s", _x );
    outline0("STA TILEX" );
    outline1("LDA %s", _y );
    outline0("STA TILEY" );
    outline1("LDA %s", address_displacement(_environment, _tile, "1") );
    outline0("STA TILEW" );
    outline1("LDA %s", address_displacement(_environment, _tile, "2") );
    outline0("STA TILEH" );

    outline0("JSR PUTTILE");

}

void gtia_tile_at( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy( gtiavars, src_hw_gtia_vars_asm);
    deploy_deferred( gtiavarsGraphic, src_hw_gtia_vars_graphics_asm );
    deploy( tiles, src_hw_gtia_tiles_asm );

    outline1("LDA %s", _x );
    outline0("STA TILEX" );
    outline1("LDA %s", _y );
    outline0("STA TILEY" );

    outline0("JSR TILEAT");

    outline0("LDA TILET" );
    outline1("STA %s", _result );

}

void gtia_use_tileset( Environment * _environment, char * _tileset ) {

    deploy( gtiavars, src_hw_gtia_vars_asm);
    deploy( tiles, src_hw_gtia_tiles_asm );

    outline1("LDA %s", _tileset );

    outline0("JSR USETILESET");

}

void gtia_wait_vbl( Environment * _environment, char * _raster_line ) {

    deploy( vbl, src_hw_gtia_vbl_asm);

    if ( _raster_line ) {
        Variable * raster_line = variable_retrieve_or_define( _environment, _raster_line, VT_BYTE, 255 );
        outline1( "LDX %s", raster_line->realName );
    } else {
        outline0( "LDX #0" );
    }
    outline0("JSR VBL");

}

Variable * gtia_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    int size = gtia_image_size( _environment, _width, _height, _mode );

    if ( ! size ) {
        CRITICAL_NEW_IMAGE_UNSUPPORTED_MODE( _mode );
    }

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(new image)" );

    char * buffer = malloc ( size );
    memset( buffer, 0, size );

    *(buffer) = (_width & 0xff);
    *(buffer+1) = (_width >> 8 ) & 0xff;
    *(buffer+2) = _height;

    result->valueBuffer = buffer;
    result->size = size;

    return result;

}

Variable * gtia_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

    int size = calculate_images_size( _environment, _frames, _width, _height, _mode );
    int frameSize = gtia_image_size( _environment, _width, _height, _mode );

    if ( ! size ) {
        CRITICAL_NEW_IMAGES_UNSUPPORTED_MODE( _mode );
    }

    Variable * result = variable_temporary( _environment, VT_IMAGES, "(new images)" );

    char * buffer = malloc ( size );
    memset( buffer, 0, size );

    *(buffer) = _frames;
    *(buffer+1) = ( _width & 0xff );
    *(buffer+2) = ( _width >> 8 ) & 0xff;
    for( int i=0; i<_frames; ++i ) {
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

Variable * gtia_new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

    int size2 = calculate_sequence_size( _environment, _sequences, _frames, _width, _height, _mode );
    int size = calculate_images_size( _environment, _frames, _width, _height, _mode );
    int frameSize = gtia_image_size( _environment, _width, _height, _mode );

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
    result->size = size2;
    result->frameCount = _frames;

    return result;

}

void gtia_get_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _palette ) {

    deploy( gtiavars, src_hw_gtia_vars_asm);
    deploy_deferred( gtiavarsGraphic, src_hw_gtia_vars_graphics_asm );
    deploy( getimage, src_hw_gtia_get_image_asm );

    gtia_load_image_address_to_other_register( _environment, "TMPPTR", _image, _sequence, _frame, _frame_size, _frame_count );

    outline1("LDA %s", _x );
    outline0("STA IMAGEX" );
    outline1("LDA %s", address_displacement(_environment, _x, "1") );
    outline0("STA IMAGEX+1" );
    outline1("LDA %s", _y );
    outline0("STA IMAGEY" );
    outline1("LDA %s", address_displacement(_environment, _y, "1") );
    outline0("STA IMAGEY+1" );
    outline1("LDA #$%2.2x", _palette );
    outline0("STA IMAGET" );

    outline0("JSR GETIMAGE");

}

void gtia_scroll( Environment * _environment, int _dx, int _dy ) {

    deploy( gtiavars, src_hw_gtia_vars_asm);
    deploy_deferred( gtiavarsGraphic, src_hw_gtia_vars_graphics_asm );
    deploy( scroll, src_hw_gtia_scroll_asm);
    deploy_preferred( textHScroll, src_hw_gtia_hscroll_text_asm );
    deploy_preferred( vScrollText, src_hw_gtia_vscroll_text_asm );

    outline1("LDA #$%2.2x", (unsigned char)(_dx&0xff) );
    outline0("STA MATHPTR0" );
    outline1("LDA #$%2.2x", (unsigned char)(_dy&0xff) );
    outline0("STA MATHPTR1" );
    outline0("JSR SCROLL");

}

Variable * gtia_get_raster_line( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_BYTE, "(raster line)" );

    cpu_move_8bit( _environment, "$D40B", result->realName );
    variable_sl_const( _environment, result->name, 1 );

    return result;
    
}

void gtia_slice_image( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination ) {

}

int gtia_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette ) {

    int paletteColorCount = rgbi_extract_palette(_environment, _data, _width, _height, _depth, _palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    memcpy( _palette, palette_match( _palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) ), paletteColorCount * sizeof( RGBi ) );

    int uniquePaletteCount = 0;

    memcpy( _palette, palette_remove_duplicates( _palette, paletteColorCount, &uniquePaletteCount ), paletteColorCount * sizeof( RGBi ) );

    return uniquePaletteCount;

}

void gtia_flip_image( Environment * _environment, Resource * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _direction ) {

    deploy( gtiavars, src_hw_gtia_vars_asm);
    deploy_deferred( gtiavarsGraphic, src_hw_gtia_vars_graphics_asm );

    if ( strcmp( _direction, "#FLIPIMAGEDIRECTION0001" ) == 0 || strcmp( _direction, "#FLIPIMAGEDIRECTION0003" ) == 0 ) {
        gtia_load_image_address_to_register( _environment, "TMPPTR", _image, _sequence, _frame, _frame_size, _frame_count );
        deploy( flipimagex, src_hw_gtia_flip_image_x_asm );
        outline0("JSR FLIPIMAGEX");
    } else {
        
        MAKE_LABEL

        gtia_load_image_address_to_register( _environment, "TMPPTR", _image, _sequence, _frame, _frame_size, _frame_count );
        deploy( flipimagex, src_hw_gtia_flip_image_x_asm );
        outline1("LDA %s", _direction );
        outline1("AND #$%2.2x", FLAG_FLIP_X );
        outline1("BEQ %s", label );
        outline0("JSR FLIPIMAGEX");
        outhead1("%s:", label );

    }
    
    if ( strcmp( _direction, "#FLIPIMAGEDIRECTION0002" ) == 0 || strcmp( _direction, "#FLIPIMAGEDIRECTION0003" ) == 0 ) {
        gtia_load_image_address_to_register( _environment, "TMPPTR", _image, _sequence, _frame, _frame_size, _frame_count );
        deploy( flipimagey, src_hw_gtia_flip_image_y_asm );
        outline0("JSR FLIPIMAGEY");
    } else {
        
        MAKE_LABEL

        gtia_load_image_address_to_register( _environment, "TMPPTR", _image, _sequence, _frame, _frame_size, _frame_count );
        deploy( flipimagey, src_hw_gtia_flip_image_y_asm );
        outline1("LDA %s", _direction );
        outline1("AND #$%2.2x", FLAG_FLIP_Y );
        outline1("BEQ %s", label );
        outline0("JSR FLIPIMAGEY");
        outhead1("%s:", label );

    }

}

void gtia_fade( Environment * _environment, char * _ticks ) {

    deploy( gtiavars, src_hw_gtia_vars_asm);
    deploy_deferred( gtiavarsGraphic, src_hw_gtia_vars_graphics_asm );
    deploy( gtiapreproc, src_hw_gtia__preproc_asm );
    deploy( fade, src_hw_gtia_fade_asm );

    outline0( "SEI" );
    outline0( "LDA #0" );
    outline0( "STA FADESTEP" );
    outline1( "LDA %s", _ticks );
    outline0( "STA FADEDURATION" );
    outline0( "STA FADERESETDURATION" );
    outline1( "LDA %s", address_displacement( _environment, _ticks, "1" ) );
    outline0( "STA FADEDURATION+1" );
    outline0( "STA FADERESETDURATION+1" );
    outline0( "CLI" );

}

void gtia_screen( Environment * _environment, char * _x, char * _y, char * _c ) {

    deploy( gtiavars, src_hw_gtia_vars_asm);
    deploy( screen, src_hw_gtia_screen_asm);

    outline1( "LDA %s", _x );
    outline0( "STA MATHPTR1" );
    outline1( "LDA %s", _y );
    outline0( "STA MATHPTR0" );
    outline0( "JSR SCREEN" );
    outline1( "STA %s", _c );

}

#endif