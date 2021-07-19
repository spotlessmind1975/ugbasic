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

#ifdef __plus4__

#include "../ugbc.h"
#include "6502.h"

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

void ted_collision( Environment * _environment, char * _sprite_mask, char * _result ) {

}

void ted_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

}

/**
 * @brief <i>TED</i>: emit code to change border color
 * 
 * This function can be used to issue code aimed at changing the
 * border color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _border_color Border color to use
 */
void ted_border_color( Environment * _environment, char * _border_color ) {

    outline1("LDA %s", _border_color );
    outline0("AND #$0f" );
    outline0("STA $FF19");

}

/**
 * @brief <i>TED</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void ted_background_color( Environment * _environment, char * _index, char * _background_color ) {
 
    outline1("LDA %s", _index);
    outline0("AND #$03");
    outline0("TAX");
    outline1("LDA %s", _background_color );
    outline0("AND #$0f" );
    outline0("STA $FF15,X");
}

void ted_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {

}

/**
 * @brief <i>TED</i>: emit code to set raster irq
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
void ted_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

    MAKE_LABEL

    outline0("SEI");
    outline1("LDA #<%s", _label);
    outline0("STA $0314");
    outline1("LDA #>%s", _label);
    outline0("STA $0315");
    outline0("LDA #%00000010");
    outline0("STA $FF0A");
    outline1("LDA %s", _positionlo );
    outline0("STA $FF0B");
    outline1("LDA %s", _positionhi );
    outline0("AND #%00000001" );
    cpu6502_beq(_environment, label);
    outline0("LDA $FF0A" );
    outline0("AND #%01111111" );
    outline0("ORA #%10000000" );
    outline0("STA $FF0A");
    outhead1("%s:", label );
    outline0("CLI");

}

/**
 * @brief <i>TED</i>: emit code to wait for next raster irq
 * 
 * This function outputs assembly code needed to wait for the
 * next raster. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 *
 */
void ted_next_raster( Environment * _environment ) {

    outline0("ASL $FF09"); // acknowledge
    outline0("JMP $FCB3"); // KERNAL's standard interrupt service routine

}

/**
 * @brief <i>TED</i>: emit code to wait for next raster irq at different position
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
void ted_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

    MAKE_LABEL

    outline1("LDA %s", _positionlo );
    outline0("STA $FF0B");
    outline1("LDA %s", _positionhi );
    outline0("AND #%00000001" );
    cpu6502_beq(_environment, label);
    outline0("LDA $FF0A" );
    outline0("AND #%01111111" );
    outline0("ORA #%10000000" );
    outline0("STA $FF0A");
    outhead1("%s:", label );
    outline1("LDA #<%s", _label);
    outline0("STA $0314");
    outline1("LDA #>%s", _label);
    outline0("STA $0315");

    ted_next_raster( _environment );

}

void ted_enable_ecm( Environment * _environment ) {

}

void ted_disable_ecm( Environment * _environment ) {

}

void ted_enable_mcm( Environment * _environment ) {

}

void ted_disable_mcm( Environment * _environment ) {

}

void ted_bank_select( Environment * _environment, int _bank ) {

}

void ted_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors );

    Variable * colormapAddress = variable_retrieve( _environment, "COLORMAPADDRESS" );

    switch( mode->id ) {
        case BITMAP_MODE_STANDARD:
            // Enable graphics.
            outline0("LDA $FF06" );
            outline0("ORA #%00100000");
            outline0("STA $FF06" );

            // Let's enable monocolor graphics!
            outline0("LDA $FF07" );
            outline0("AND #%11101111");
            outline0("STA $FF07" );

            cpu_store_16bit( _environment, colormapAddress->realName, 0xA000-0x0400 );

            break;
        case BITMAP_MODE_MULTICOLOR:
            // Enable graphics.
            outline0("LDA $FF06" );
            outline0("ORA #%00100000");
            outline0("STA $FF06" );

            // Let's enable multicolor graphics!
            outline0("LDA $FF07" );
            outline0("ORA #%00010000");
            outline0("STA $FF07" );

            cpu_store_16bit( _environment, colormapAddress->realName, 0xA000-0x0400 );
            
            break;
        default:
            CRITICAL_SCREEN_MODE_BITMAP_UNSUPPORTED( mode->description );
    }

    cpu_store_8bit( _environment, "_PEN", 0x10 );
    cpu_store_8bit( _environment, "_PAPER", 0x00 );

}

void ted_bitmap_disable( Environment * _environment ) {

    Variable * colormapAddress = variable_retrieve( _environment, "COLORMAPADDRESS" );

    // Let's disable graphics!
    outline0("LDA $FF06" );
    outline0("AND #%11011111");
    outline0("STA $FF06" );

    cpu_store_16bit( _environment, colormapAddress->realName, 0xd800 );

}

void ted_tilemap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors );

    Variable * colormapAddress = variable_retrieve( _environment, "COLORMAPADDRESS" );

    switch( mode->id ) {
        case TILEMAP_MODE_STANDARD:
            // Let's disable graphics (and extended color)!
            outline0("LDA $FF06" );
            outline0("AND #%10011111");
            outline0("STA $FF06" );

            cpu_store_16bit( _environment, colormapAddress->realName, 0xA000 );

            break;
        case TILEMAP_MODE_MULTICOLOR:
        case TILEMAP_MODE_EXTENDED:
            // Let's disable graphics and enable extended color!
            outline0("LDA $FF06" );
            outline0("AND #%11011111");
            outline0("ORA #%01000000");
            outline0("STA $FF06" );

            cpu_store_16bit( _environment, colormapAddress->realName, 0xA000 );
            break;
        default:
            CRITICAL_SCREEN_MODE_TILEMAP_UNSUPPORTED( mode->description );
    }

    cpu_store_8bit( _environment, "_PEN", 0x01 );
    cpu_store_8bit( _environment, "_PAPER", 0x00 );

}

void ted_bitmap_at( Environment * _environment, char * _address ) {

}

void ted_colormap_at( Environment * _environment, char * _address ) {

}

void ted_textmap_at( Environment * _environment, char * _address ) {

}

void ted_point_at_int( Environment * _environment, int _x, int _y ) {

    deploy( tedvarsDeployed, "./ugbc/src/hw/ted/vars.asm" );
    deploy( plotDeployed, "./ugbc/src/hw/ted/plot.asm" );
    
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

void ted_point_at_vars( Environment * _environment, char *_x, char *_y ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy( tedvarsDeployed, "./ugbc/src/hw/ted/vars.asm" );
    deploy( plotDeployed, "./ugbc/src/hw/ted/plot.asm" );
    
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

void ted_point( Environment * _environment, char *_x, char *_y, char * _result ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );
    Variable * result = variable_retrieve( _environment, _result );

    deploy( tedvarsDeployed, "./ugbc/src/hw/ted/vars.asm" );
    deploy( plotDeployed, "./ugbc/src/hw/ted/plot.asm" );
    
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

void ted_screen_on( Environment * _environment ) {

}

void ted_screen_off( Environment * _environment ) {
    
}

void ted_screen_rows( Environment * _environment, char * _rows ) {

    MAKE_LABEL

    outline1("LDA %s", _rows);
    outline0("CMP #24");
    outline1("BEQ %s", label);
    outline0("LDA $FF06" );
    outline0("ORA #%00001000");
    outline0("STA $FF06" );
    outline1("JMP %s_2", label);
    outhead1("%s:", label );
    outline0("LDA $FF06" );
    outline0("AND #%11110111");
    outline0("STA $FF06" );
    outline1("JMP %s_2", label);
    outhead1("%s_2:", label );

}

void ted_sprite_data_from( Environment * _environment, char * _sprite, char * _address ) {

}

void ted_sprite_enable( Environment * _environment, char * _sprite ) {

}

void ted_sprite_disable( Environment * _environment, char * _sprite ) {

}

void ted_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

}

void ted_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

}

void ted_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

}

void ted_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

}

void ted_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

}

void ted_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void ted_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void ted_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

}

void ted_tiles_at( Environment * _environment, char * _address ) {

}

void ted_vertical_scroll( Environment * _environment, char * _displacement ) {

    outline0("LDA $FF06" );
    outline0("AND #%11111000");
    outline1("ORA %s", _displacement );
    outline0("STA $FF06" );

}

void ted_horizontal_scroll( Environment * _environment, char * _displacement ) {

    outline0("LDA $FF07" );
    outline0("AND #%11111000");
    outline1("ORA %s", _displacement );
    outline0("STA $FF07" );

}

void ted_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline0("LDA #$00");
    outline0("STA TMPPTR");
    outhead1("%sfirst:", label );
    outline0("LDA #$01");
    outhead1("%ssecond:", label );
    outline0("CMP $FF1D");
    outline1("BNE %ssecond", label);
    outhead1("%sthird:", label );
    outline0("CMP $FF1D");
    outline1("BEQ %sthird", label);
    outline0("INC TMPPTR");
    outline0("LDA TMPPTR");
    outline1("CMP %s", _timing );
    outline1("BNE %sfirst", label );

}

void ted_get_width( Environment * _environment, char *_result ) {

    MAKE_LABEL

    outline0("LDA $FF06" );
    outline0("AND #%00100000");
    outline1("BNE %sbitmap", label );
    outhead1("%stext:", label );
    outline0("LDA #40" );
    outline1("STA %s", _result );
    outline0("LDA #0" );
    outline1("STA %s+1", _result );
    outline1("JMP %send", label );
    outhead1("%sbitmap:", label );
    outline0("LDA #$40" );
    outline1("STA %s", _result );
    outline0("LDA #$1" );
    outline1("STA %s+1", _result );
    outhead1("%send:", label );

}

void ted_get_height( Environment * _environment, char *_result ) {

    MAKE_LABEL

    outline0("LDA $FF06" );
    outline0("AND #%00100000");
    outline1("BNE %sbitmap", label );
    outhead1("%stext:", label );
    outline0("LDA $FF06" );
    outline0("AND #%00001000");
    outline1("BNE %s_25", label );
    outline0("LDA #24" );
    outline1("STA %s", _result );
    outline0("LDA #0" );
    outline1("STA %s+1", _result );
    outline1("JMP %send", label );
    outhead1("%s_25:", label );
    outline0("LDA #25" );
    outline1("STA %s", _result );
    outline0("LDA #0" );
    outline1("STA %s+1", _result );
    outline1("JMP %send", label );
    outhead1("%sbitmap:", label );
    outline0("LDA #200" );
    outline1("STA %s", _result );
    outline0("LDA #0" );
    outline1("STA %s+1", _result );
    outhead1("%send:", label );

}

void ted_cls( Environment * _environment ) {
    
    deploy( clsDeployed, "./ugbc/src/hw/ted/cls.asm" );

    outline0("JSR CLS");

}

void ted_scroll_text( Environment * _environment, int _direction ) {

    deploy( vScrollTextDeployed, "./ugbc/src/hw/ted/vscroll_text.asm" );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );

    outline0("JSR VSCROLLT");

}

void ted_text_at( Environment * _environment, char * _x, char * _y, char * _text, char * _text_size, char * _pen, char *_ww ) {

    deploy( tedvarsDeployed, "./ugbc/src/hw/ted/vars.asm" );
    deploy( vScrollTextDeployed, "./ugbc/src/hw/ted/vscroll_text.asm" );
    deploy( textEncodedAtDeployed, "./ugbc/src/hw/ted/text_at.asm" );

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

void ted_initialization( Environment * _environment ) {

    deploy( vicstartupDeployed, "./ugbc/src/hw/ted/startup.asm" );

    SCREEN_MODE_DEFINE( BITMAP_MODE_STANDARD, 1, 320, 200, 2, "Standard Bitmap Mode" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_MULTICOLOR, 1, 160, 200, 4, "Multicolor Bitmap Mode"  );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_STANDARD, 0, 40, 25, 2, "Standard Character Mode" );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_EXTENDED, 0, 40, 25, 20, "Extended Multicolor Character Mode" );

    outline0("JSR TEDSTARTUP");

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

    ted_cls( _environment );

}

void ted_hscroll_line( Environment * _environment, int _direction ) {

    deploy( textHScrollDeployed, "./ugbc/src/hw/ted/hscroll_text.asm" );

    Variable * y = variable_retrieve( _environment, "windowCY" );
    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );
    outline1("LDA %s", y->realName );
    outline0("STA CLINEY");

    outline0("JSR HSCROLLLT");

}

void ted_hscroll_screen( Environment * _environment, int _direction ) {

    deploy( textHScrollDeployed, "./ugbc/src/hw/ted/hscroll_text.asm" );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA DIRECTION" );

    outline0("JSR HSCROLLST");
}

void ted_back( Environment * _environment ) {

    deploy( backDeployed, "./ugbc/src/hw/ted/back.asm" );

    outline0("JSR BACK");

}

#endif