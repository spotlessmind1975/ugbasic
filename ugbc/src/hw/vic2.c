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

#ifdef __c64__

#include "../ugbc.h"
#include "6502.h"

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
void vic2_collision( Environment * _environment, char * _sprite_mask, char * _result ) {

    // Generate unique label for ASM code.
    MAKE_LABEL

    // Check for collision using VIC-II registers
    outline0("LDA $D01E");
    outline1("AND %s", _sprite_mask);
    cpu6502_beq(_environment, label);

    outline0("LDA #$1");
    outline1("STA %s", _result);
    outline1("JMP %s_2", label);

    outhead1("%s:", label);
    outline0("LDA #0");
    outline1("STA %s", _result);
    outhead1("%s_2:", label);

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
void vic2_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

    // Generate unique label for ASM code.
    MAKE_LABEL

    // Check for collision using VIC-II registers
    outline0("LDA $D01F");
    outline1("AND %s", _sprite_mask);
    cpu6502_beq(_environment, label);

    outline0("LDA #$1");
    outline1("STA %s", _result);
    outline1("JMP %s_2", label);

    outhead1("%s:", label);
    outline0("LDA #0");
    outline1("STA %s", _result);
    outhead1("%s_2:", label);

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
void vic2_border_color( Environment * _environment, char * _border_color ) {

    outline1("LDA %s", _border_color );
    outline0("AND #$0f" );
    outline0("STA $D020");

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
void vic2_background_color( Environment * _environment, char * _index, char * _background_color ) {
 
    outline1("LDA %s", _index);
    outline0("AND #$03");
    outline0("TAX");
    outline1("LDA %s", _background_color );
    outline0("AND #$0f" );
    outline0("STA $d021,X");
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
void vic2_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {
 
    outline1("LDA %s", _index);
    outline0("AND #$03");
    outline0("TAX");
    outline1("LDA %s", _common_color );
    outline0("AND #$0f" );
    outline0("STA $D025,X" );

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
void vic2_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

    MAKE_LABEL

    outline0("LDA #%01111111"); // switch off CIA-1
    outline0("STA $DC0D");
    outline0("AND $D011");
    outline0("STA $D011");
    outline0("LDA $DC0D"); // acknowledge CIA-1
    outline0("LDA $DD0D"); // acknowledge CIA-2
    outline1("LDA #<%s", _label);
    outline0("STA $0314");
    outline1("LDA #>%s", _label);
    outline0("STA $0315");
    outline0("LDA #%00000001"); // enable raster interrupt signals from VIC
    outline0("STA $D01A");
    outline1("LDA %s", _positionlo );
    outline0("STA $D012");
    outline1("LDA %s", _positionhi );
    outline0("AND #%00000001" );
    cpu6502_beq(_environment, label);
    outline0("LDA $D011" );
    outline0("AND #%01111111" );
    outline0("ORA #%10000000" );
    outline0("STA $D011");
    outline1("JMP %s_2", label );
    outhead1("%s:", label );
    outline0("LDA $D011" );
    outline0("AND #%01111111" );
    outline0("STA $D011");
    outhead1("%s_2:", label );
    outline0("CLI");

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
void vic2_next_raster( Environment * _environment ) {

    outline0("ASL $D019"); // acknowledge
    outline0("JMP $EA31"); // KERNAL's standard interrupt service routine

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
void vic2_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

    MAKE_LABEL

    outline1("LDA %s", _positionlo);
    outline0("STA $D012");
    outline1("LDA %s", _positionhi );
    outline0("AND #%00000001" );
    cpu6502_beq(_environment, label);
    outline0("LDA $D011" );
    outline0("AND #%01111111" );
    outline0("ORA #%10000000" );
    outline0("STA $D011");
    outline1("JMP %s_2", label );
    outhead1("%s:", label );
    outline0("LDA $D011" );
    outline0("AND #%01111111" );
    outline0("STA $D011");
    outhead1("%s_2:", label );
    outline1("LDA #<%s", _label);
    outline0("STA $0314");
    outline1("LDA #>%s", _label);
    outline0("STA $0315");

    vic2_next_raster( _environment );

}

/**
 * @brief <i>VIC-II</i>: emit code to enable ECM
 * 
 * @param _environment Current calling environment
 */
void vic2_enable_ecm( Environment * _environment ) {

    outline0("; ENABLE ECM");

    outline0("LDA $D011" );
    outline0("ORA #%01000000");
    outline0("STA $D011" );
}

/**
 * @brief <i>VIC-II</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void vic2_disable_ecm( Environment * _environment ) {

    outline0("; DISABLE ECM");

    outline0("LDA $D011" );
    outline0("AND #%10111111");
    outline0("STA $D011" );
}

/**
 * @brief <i>VIC-II</i>: emit code to enable MCM
 * 
 * @param _environment Current calling environment
 */
void vic2_enable_mcm( Environment * _environment ) {

    outline0("; ENABLE MCM");

    outline0("LDA $D016" );
    outline0("ORA #%00001000");
    outline0("STA $D016" );
}

/**
 * @brief <i>VIC-II</i>: emit code to disable ECM
 * 
 * @param _environment Current calling environment
 */
void vic2_disable_mcm( Environment * _environment ) {
    outline0("; DISABLE MCM");
    outline0("LDA $D016" );
    outline0("AND #%11110111");
    outline0("STA $D016" );
}

void vic2_bank_select( Environment * _environment, int _bank ) {
    outline1("; BANK %d", _bank);
    outline0("LDA $DD00" );
    outline0("AND #%11111100");
    outline1("ORA #%2.2x", ( ~_bank ) & 0x03 );
    outline0("STA $DD00" );
}

void vic2_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 1, _width, _height, _colors );

    Variable * colormapAddress = variable_retrieve( _environment, "COLORMAPADDRESS" );

    switch( mode->id ) {
        case BITMAP_MODE_STANDARD:
            // This fix is necessary to set the starting address of the bitmap 
            // to $A000 (which is an address available on C=64).
            outline0("LDA $D018" );
            outline0("AND #%11110111");
            outline0("ORA #%00001000" );
            outline0("STA $D018" );

            // Let's enable monocolor graphics!
            outline0("LDA $D011" );
            outline0("ORA #%00100000");
            outline0("STA $D011" );
            outline0("LDA $D016" );
            outline0("AND #%11101111");
            outline0("STA $D016" );

            cpu_store_16bit( _environment, colormapAddress->realName, 0x8400 );

            break;
        case BITMAP_MODE_MULTICOLOR:
            // This fix is necessary to set the starting address of the bitmap 
            // to $A000 (which is an address available on C=64) instead of the 
            // address $8000.
            outline0("LDA $D018" );
            outline0("AND #%11110111");
            outline0("ORA #%00001000" );
            outline0("STA $D018" );

            // Let's enable multicolor graphics!
            outline0("LDA $D011" );
            outline0("ORA #%00100000");
            outline0("STA $D011" );
            outline0("LDA $D016" );
            outline0("ORA #%00010000");
            outline0("STA $D016" );

            cpu_store_16bit( _environment, colormapAddress->realName, 0x8400 );
            
            break;
        default:
            CRITICAL_SCREEN_MODE_BITMAP_UNSUPPORTED( mode->description );
    }


}

void vic2_bitmap_disable( Environment * _environment ) {

    Variable * colormapAddress = variable_retrieve( _environment, "COLORMAPADDRESS" );

    // Let's disable graphics!
    outline0("LDA $D011" );
    outline0("AND #%11011111");
    outline0("STA $D011" );
    outline0("LDA $D016" );
    outline0("AND #%11101111");
    outline0("STA $D016" );

    cpu_store_16bit( _environment, colormapAddress->realName, 0xd800 );

}

void vic2_tilemap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    ScreenMode * mode = find_screen_mode_by_suggestion( _environment, 0, _width, _height, _colors );

    Variable * colormapAddress = variable_retrieve( _environment, "COLORMAPADDRESS" );

    switch( mode->id ) {
        case TILEMAP_MODE_STANDARD:
            // Let's disable graphics!
            outline0("LDA $D011" );
            outline0("AND #%11011111");
            outline0("STA $D011" );
            outline0("LDA $D016" );
            outline0("AND #%11101111");
            outline0("STA $D016" );

            // This fix is necessary to reset the lookup for rom character.
            outline0("LDA $D018" );
            outline0("AND #%11110111");
            outline0("STA $D018" );

            cpu_store_16bit( _environment, colormapAddress->realName, 0xd800 );

            break;
        case TILEMAP_MODE_MULTICOLOR:
            // Let's disable graphics!
            outline0("LDA $D011" );
            outline0("AND #%11011111");
            outline0("STA $D011" );
            outline0("LDA $D016" );
            outline0("ORA #%00010000");
            outline0("STA $D016" );

            // This fix is necessary to reset the lookup for rom character.
            outline0("LDA $D018" );
            outline0("AND #%11110111");
            outline0("STA $D018" );

            cpu_store_16bit( _environment, colormapAddress->realName, 0xd800 );

            break;
        case TILEMAP_MODE_EXTENDED:
            // Let's disable graphics!
            outline0("LDA $D011" );
            outline0("AND #%11011111");
            outline0("ORA #%01000000");
            outline0("STA $D011" );
            outline0("LDA $D016" );
            outline0("AND #%11101111");
            outline0("STA $D016" );

            // This fix is necessary to reset the lookup for rom character.
            outline0("LDA $D018" );
            outline0("AND #%11110111");
            outline0("STA $D018" );
            
            cpu_store_16bit( _environment, colormapAddress->realName, 0xd800 );

            break;
        default:
            CRITICAL_SCREEN_MODE_TILEMAP_UNSUPPORTED( mode->description );
    }


}

void vic2_bitmap_at( Environment * _environment, char * _address ) {

    outline1("LDA %s", _address );
    outline0("LSR");
    outline0("LSR");
    outline0("LSR");
    outline0("LSR");
    outline0("LSR");
    outline0("LSR");
    outline0("AND #%00000001");
    outline0("ASL" );
    outline0("ASL" );
    outline0("ASL" );
    outline0("STA $22" );
    outline0("LDA $D018" );
    outline0("AND #%11110111");
    outline0("ORA $22" );
    outline0("STA $D018" );

}

void vic2_colormap_at( Environment * _environment, char * _address ) {

    // Create a unique variabled for ASM code.
    MAKE_LABEL

    // Let's check if we are in ECM mode.
    outline0("LDA $D011");
    outline0("BIT #%00100000");
    cpu6502_beq(_environment, label);

    // Change the colormap address that is the text address.
    vic2_textmap_at( _environment, _address );

    // If not, we are unable to change the colormap address.
    outline1("%s:", label);


}

void vic2_textmap_at( Environment * _environment, char * _address ) {

    // Create a unique variabled for ASM code.
    MAKE_LABEL

    outline1("LDA %s", _address );
    outline0("LSR");
    outline0("LSR");
    outline0("AND #$0f");
    outline0("ASL");
    outline0("ASL");
    outline0("ASL");
    outline0("ASL");
    outline0("STA $22");
    outline0("LDA $D018");
    outline0("AND #%00001111");
    outline0("ORA $22" );
    outline0("STA $D018");

}

void vic2_point_at_int( Environment * _environment, int _x, int _y ) {

    deploy( vic2varsDeployed, "./ugbc/src/hw/vic2/vars.asm" );
    deploy( plotDeployed, "./ugbc/src/hw/vic2/plot.asm" );
    
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

void vic2_point_at_vars( Environment * _environment, char *_x, char *_y ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    deploy( vic2varsDeployed, "./ugbc/src/hw/vic2/vars.asm" );
    deploy( plotDeployed, "./ugbc/src/hw/vic2/plot.asm" );
    
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

void vic2_point( Environment * _environment, char *_x, char *_y, char * _result ) {

    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );
    Variable * result = variable_retrieve( _environment, _result );

    deploy( vic2varsDeployed, "./ugbc/src/hw/vic2/vars.asm" );
    deploy( plotDeployed, "./ugbc/src/hw/vic2/plot.asm" );
    
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

void vic2_screen_on( Environment * _environment ) {

    outline0("LDA $D011" );
    outline0("ORA #%00010000");
    outline0("STA $D011" );

}

void vic2_screen_off( Environment * _environment ) {
    
    outline0("LDA $D011" );
    outline0("AND #%11101111");
    outline0("STA $D011" );

}

void vic2_screen_rows( Environment * _environment, char * _rows ) {

    MAKE_LABEL

    outline1("LDA %s", _rows);
    outline0("CMP #24");
    outline1("BEQ %s", label);
    outline0("LDA $D011" );
    outline0("ORA #%00001000");
    outline0("STA $D011" );
    outline1("JMP %s_2", label);
    outhead1("%s:", label );
    outline0("LDA $D011" );
    outline0("AND #%11110111");
    outline0("STA $D011" );
    outline1("JMP %s_2", label);
    outhead1("%s_2:", label );

}

void vic2_sprite_data_from( Environment * _environment, char * _sprite, char * _address ) {

    outline1("LDA %s", _address );
    outline0("LSR"  );
    outline0("LSR"  );
    outline0("LSR"  );
    outline0("LSR"  );
    outline0("LSR"  );
    outline0("LSR"  );
    outline0("LSR"  );
    outline1("LDX %s", _sprite );
    outline0("STA $07F8, X" );

}

void vic2_sprite_enable( Environment * _environment, char * _sprite ) {

    _environment->bitmaskNeeded = 1;

    outline0("LDA $D015" );
    outline1("LDX %s", _sprite );
    outline0("ORA BITMASK,X");
    outline0("STA $D015" );

}

void vic2_sprite_disable( Environment * _environment, char * _sprite ) {

    outline0("LDA $D015" );
    outline1("LDX %s", _sprite );
    outline0("AND BITMASKN,X");
    outline0("STA $D015" );

}

void vic2_sprite_position( Environment * _environment, char * _sprite, char * _x, char * _y ) {

    MAKE_LABEL

    _environment->bitmaskNeeded = 1;
    
    outline1("LDA %s", _sprite );
    outline0("ASL A" );
    outline0("TAX");
    outline1("LDA %s", _x);
    outline0("STA $D000, X");
    outline1("LDA %s+1", _x);
    outline1("BEQ %s", label);
    outline0("LDA $D010");
    outline0("ORA BITMASK,X");
    outline0("STA $D010" );
    outline1("JMP %s_2", label);
    outhead1("%s:", label);
    outline0("LDA $D010");
    outline0("AND BITMASKN,X");
    outline0("STA $D010" );
    outhead1("%s_2:", label);
    outline0("INX");
    outline1("LDA %s", _y);
    outline0("STA $D000, X");
    outline1("LDA %s+1", _y);

}

void vic2_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

    outline1("LDX %s", _sprite);
    outline0("LDA $D017" );
    outline0("ORA BITMASK,X");
    outline0("STA $D017" );

}

void vic2_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

    outline1("LDX %s", _sprite );
    outline0("LDA $D01D" );
    outline0("ORA BITMASK,X");
    outline0("STA $D01D" );

}

void vic2_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

    outline1("LDX _%s", _sprite );
    outline0("LDA $D017" );
    outline0("AND BITMASKN,X");
    outline0("STA $D017" );

}

void vic2_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

    outline1("LDX %s", _sprite );
    outline0("LDA $D01D" );
    outline0("AND BITMASKN,X");
    outline0("STA $D01D" );

}

void vic2_sprite_multicolor( Environment * _environment, char * _sprite ) {

    outline1("LDX %s", _sprite );
    outline0("LDA $D01C" );
    outline0("ORA BITMASK,X");
    outline0("STA $D01C" );

}

void vic2_sprite_monocolor( Environment * _environment, char * _sprite ) {

    outline1("LDX %s", _sprite );
    outline0("LDA $D01C" );
    outline0("AND BITMASKN, X");
    outline0("STA $D01C" );

}

void vic2_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

    outline1("LDX %s", _sprite);
    outline1("LDA %s", _color);
    outline0("AND #$0f" );
    outline0("STA D027, X" );

}

void vic2_tiles_at( Environment * _environment, char * _address ) {

    outline1("LDA %s", _address);
    outline0("LSR");
    outline0("LSR");
    outline0("LSR");
    outline0("AND #$07");
    outline0("ASL");
    outline0("STA $22");
    outline0("LDA $D018");
    outline0("AND #%00001111");
    outline0("ORA $22");
    outline0("STA $D018");

}

void vic2_vertical_scroll( Environment * _environment, char * _displacement ) {

    outline0("LDA $D011" );
    outline0("AND #%11111000");
    outline1("ORA %s", _displacement );
    outline0("STA $D011" );

}

void vic2_horizontal_scroll( Environment * _environment, char * _displacement ) {

    outline0("LDA $D016" );
    outline0("AND #%11111000");
    outline1("ORA %s", _displacement );
    outline0("STA $D016" );

}

void vic2_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline0("LDA #$00");
    outline0("STA $22");
    outhead1("%sfirst:", label );
    outline0("LDA #$01");
    outhead1("%ssecond:", label );
    outline0("CMP $D012");
    outline1("BNE %ssecond", label);
    outhead1("%sthird:", label );
    outline0("CMP $D012");
    outline1("BEQ %sthird", label);
    outline0("INC $22");
    outline0("LDA $22");
    outline1("CMP %s", _timing );
    outline1("BNE %sfirst", label );

}

void vic2_get_width( Environment * _environment, char *_result ) {

    MAKE_LABEL

    outline0("LDA $D011" );
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

void vic2_get_height( Environment * _environment, char *_result ) {

    MAKE_LABEL

    outline0("LDA $D011" );
    outline0("AND #%00100000");
    outline1("BNE %sbitmap", label );
    outhead1("%stext:", label );
    outline0("LDA $D011" );
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

void vic2_cls( Environment * _environment ) {
    
    deploy( clsDeployed, "./ugbc/src/hw/vic2/cls.asm" );

    outline0("JSR CLS");

}

void vic2_scroll_text( Environment * _environment, int _direction ) {

    deploy( vScrollTextDeployed, "./ugbc/src/hw/vic2/vscroll_text.asm" );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA $30" );

    outline0("JSR VSCROLLT");

}

void vic2_text_at( Environment * _environment, char * _x, char * _y, char * _text, char * _text_size, char * _pen, char *_ww ) {

    deploy( vic2varsDeployed, "./ugbc/src/hw/vic2/vars.asm" );
    deploy( vScrollTextDeployed, "./ugbc/src/hw/vic2/vscroll_text.asm" );
    deploy( textEncodedAtDeployed, "./ugbc/src/hw/vic2/text_at.asm" );

    outline1("LDA %s", _text);
    outline0("STA $20" );
    outline1("LDA %s+1", _text);
    outline0("STA $21" );
    outline0("LDA TEXTADDRESS" );
    outline0("STA $22" );
    outline0("LDA TEXTADDRESS+1" );
    outline0("STA $23" );
    outline1("LDA %s", _x );
    outline0("STA $d3" );
    outline1("LDA %s", _y );
    outline0("STA $d6" );
    outline1("LDA %s", _text_size);
    outline0("STA $24" );
    outline0("LDA #0" );
    outline0("STA $25" );
    outline0("LDA COLORMAPADDRESS" );
    outline0("STA $29" );
    outline0("LDA COLORMAPADDRESS+1" );
    outline0("STA $2a" );
    outline1("LDA %s", _ww );
    outline0("STA $2c" );
    outline1("LDA %s", _pen );
    outline0("STA $2b" );
    outline0("LDA _PAPER" );
    outline0("STA $2d" );

    outline0("JSR TEXTAT");

    outline0("LDA $d6" );
    outline1("STA %s", _y );
    outline0("LDA $d3");
    outline1("STA %s", _x );

}

void vic2_initialization( Environment * _environment ) {

    deploy( vicstartupDeployed, "./ugbc/src/hw/vic2/startup.asm" );

    SCREEN_MODE_DEFINE( BITMAP_MODE_STANDARD, 1, 320, 200, 2, "Standard Bitmap Mode" );
    SCREEN_MODE_DEFINE( BITMAP_MODE_MULTICOLOR, 1, 160, 200, 4, "Multicolor Bitmap Mode"  );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_STANDARD, 0, 40, 25, 2, "Standard Character Mode" );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_MULTICOLOR, 0, 40, 25, 16, "Multicolor Character Mode" );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_EXTENDED, 0, 40, 25, 20, "Extended Multicolor Character Mode" );

    outline0("JSR VIC2STARTUP");

    vic2_cls( _environment );

}

void vic2_hscroll_line( Environment * _environment, int _direction ) {

    deploy( textHScrollDeployed, "./ugbc/src/hw/vic2/hscroll_text.asm" );

    Variable * y = variable_retrieve( _environment, "windowCY" );
    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA $26" );
    outline1("LDA %s", y->realName );
    outline0("STA $31");

    outline0("JSR HSCROLLLT");

}

void vic2_hscroll_screen( Environment * _environment, int _direction ) {

    deploy( textHScrollDeployed, "./ugbc/src/hw/vic2/hscroll_text.asm" );

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA $26" );

    outline0("JSR HSCROLLST");
}


#endif