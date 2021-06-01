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

#include "../ugbc.h"

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __zx__

void zx_color_border( Environment * _environment, char * _color ) {

    char port[MAX_TEMPORARY_STORAGE]; sprintf(port, "$%2.2x", PORT_COLOR_BORDER);

    z80_port_out( _environment, port, _color );

}

void zx_vscroll( Environment * _environment, int _displacement ) {

    outline1("LD A, $%2.2x", ( _displacement & 0xff ) );

    deploy( varsDeployed,"./ugbc/src/hw/zx/vars.asm" );
    deploy( vScrollDeployed,"./ugbc/src/hw/zx/vscroll.asm" );

    outline0("CALL VSCROLL");

}

void zx_text_at( Environment * _environment, char * _x, char * _y, char * _text, char * _text_size, char * _pen, char * _paper, char * _ww ) {

    deploy( varsDeployed,"./ugbc/src/hw/zx/vars.asm" );
    deploy( vScrollDeployed, "./ugbc/src/hw/zx/vscroll.asm" );
    deploy( textEncodedAtDeployed, "./ugbc/src/hw/zx/text_at.asm" );

    z80_move_8bit( _environment, _x, "XCURS");
    z80_move_8bit( _environment, _y, "YCURS");
    z80_move_8bit( _environment, _pen, "_PEN");
    z80_move_8bit( _environment, _paper, "_PAPER");
    z80_move_8bit( _environment, _ww, "LOCALWW");
    // z80_move_8bit( _environment, _tab, "TABCOUNT");

    outline1("LD A, (%s)", _text_size );
    outline0("LD C, A");
    outline0("LD B, 0");
    outline1("LD HL, (%s)", _text );
    outline0("CALL TEXTAT");

    z80_move_8bit( _environment, "XCURS", _x );
    z80_move_8bit( _environment, "YCURS", _y );

}

void zx_cls( Environment * _environment, char * _pen, char * _paper ) {

    deploy( varsDeployed,"./ugbc/src/hw/zx/vars.asm" );
    deploy( clsDeployed, "./ugbc/src/hw/zx/cls.asm" );

    if ( _pen ) {
        z80_move_8bit( _environment, _pen, "_PEN");
    }
    if ( _paper ) {
        z80_move_8bit( _environment, _paper, "_PAPER");
    }

    outline0("CALL CLS");

}

void zx_inkey( Environment * _environment, char * _pressed, char * _key ) {

    MAKE_LABEL

    outline0("LD A, 0");
    outline1("LD (%s), A", _pressed );
    outline1("LD (%s), A", _key );
    outline0("LD A, ($5C08)");
    outline0("CP 13");
    outline1("JR Z, %snokey", label );
    outline1("LD (%s), a", _key );
    outline0("LD A, $FF");
    outline1("LD (%s), A", _pressed );
    outline0("LD A, 13");
    outline0("LD ($5C08), A");
    outhead1("%snokey:", label );
   
}

void zx_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

    MAKE_LABEL

    deploy( scancodeDeployed, "./ugbc/src/hw/zx/scancode.asm" );

    outline0("LD A, 0");
    outline1("LD (%s), A", _scancode );
    outline1("LD (%s), A", _pressed );
    outline0("CALL SCANCODE");
    outline0("CP 0");
    outline1("JR Z,%snokey", label);
    outline1("LD (%s), A", _scancode );
    outline0("LD A, $FF");
    outline1("LD (%s), A", _pressed );
    outhead1("%snokey:", label );
   
}

void zx_scanshift( Environment * _environment, char * _shifts ) {

    // 653	
    // Shift key indicator. Bits:
    // Bit #0: 1 = One or more of left Shift, right Shift or Shift Lock is currently being pressed or locked.
    // Bit #1: 1 = Commodore is currently being pressed.
    // Bit #2: 1 = Control is currently being pressed.
    // NO SHIFT (0) - if no SHIFT key pressed;
    // LEFT SHIFT (1) - if the left SHIFT pressed;
    // RIGHT SHIFT (2) - if the right SHIFT pressed;
    // BOTH SHIFTS (3) - if both keys pressed.

    MAKE_LABEL

    deploy( scancodeDeployed, "./ugbc/src/hw/zx/scancode.asm" );

    outline0("CALL SCANCODE");
    outline0("CP $f1");
    outline1("JR NZ,%snokey", label);
    outline0("LD A, $03");
    outline1("LD (%s), A", _shifts );
    outhead1("%snokey:", label );

}

void zx_keyshift( Environment * _environment, char * _shifts ) {

    // On the same way, KEY SHIFT is used to report the current status of those keys 
    // which cannot be detected by either INKEY$ or SCANCODE because they do not 
    // carry the relevant codes. These control keys cannot be tested individually, or a test can be set up for any combination of such keys pressed together. A single call to the KEY SHIFT function can test for all eventualities, by examining a bit map in the following format:

    MAKE_LABEL

    deploy( scancodeDeployed, "./ugbc/src/hw/zx/scancode.asm" );

    outline0("CALL SCANCODE");
    outline0("CP $f1");
    outline1("JR NZ,%snokey", label);
    outline0("LD A, $03");
    outline1("LD (%s), A", _shifts );
    outhead1("%snokey:", label );

}

void zx_clear_key( Environment * _environment ) {

}

void zx_initialization( Environment * _environment ) {

    SCREEN_MODE_DEFINE( BITMAP_MODE_STANDARD, 1, 192, 256, 2, "Standard Bitmap Mode" );
    SCREEN_MODE_DEFINE( TILEMAP_MODE_STANDARD, 0, 32, 25, 8, "(emulated) Standard Character Mode" );

}

void zx_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

}

void zx_tilemap_enable( Environment * _environment, int _width, int _height, int _colors ) {
    
}

#endif