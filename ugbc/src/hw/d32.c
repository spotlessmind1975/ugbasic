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

#include "../ugbc.h"
#include <math.h>

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __d32__

void d32_xpen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF60");    
    outline1("STA %s+1", _destination);
    outline0("LDA #0");
    outline1("STA %s", _destination);

}

void d32_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF61");    
    outline1("STA %s+1", _destination);
    outline0("LDA #0");
    outline1("STA %s", _destination);
   
}

void d32_color_border( Environment * _environment, char * _color ) {

}

void d32_vscroll( Environment * _environment, int _displacement ) {

}

void d32_text_at( Environment * _environment, char * _text, char * _text_size, char * _pen, char * _paper ) {

}

void d32_cls( Environment * _environment, char * _pen, char * _paper ) {

}

void d32_inkey( Environment * _environment, char * _pressed, char * _key ) {

    MAKE_LABEL

    d32_scancode( _environment, _pressed, _key );

    outline1("LDA %s", _pressed );
    outline0("CMPA #0" );
    outline1("BEQ %sskip", label );
    outline1("LDA %s", _key );
    outline0("ANDA #$80" );
    outline0("CMPA #0" );
    outline1("BNE %snoascii", label );
    outline1("LDA %s", _key );
    outline0("CMPA $011d" );
    outline1("BNE %sdifferent", label );
    outline0("INC $011f" );
    outline0("LDB $011f" );
    outline0("CMPB #$7f" );
    outline1("BEQ %sascii", label );
    outline0("LDA #0" );
    outline1("STA %s", _pressed );
    outline1("JMP %sdone", label );
    outhead1("%snoascii", label );
    outline0("LDA #0" );
    outline1("STA %s", _key );
    outline1("JMP %sdone", label );
    outhead1("%sdifferent", label );
    outline0("STA $011d" );
    outhead1("%sascii", label );
    outline0("LDB #0" );
    outline0("STB $011f" );
    outline1("JMP %sdone", label );
    outhead1("%sskip", label );
    outline0("LDA #0" );
    outline0("STA $011d" );
    outhead1("%sdone", label );

}

void d32_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

    MAKE_LABEL

    deploy( scancode, src_hw_d32_scancode_asm );

    outline0("LDA #0" );
    outline1("STA %s", _pressed );
    outline1("STA %s", _scancode );

    outline0("JSR SCANCODE" );
    outline0("CMPA #0" );
    outline1("BEQ %snokey", label );
    outline1("STA %s", _scancode );
    outline0("LDA #$FF" );
    outline1("STA %s", _pressed );
    outhead1("%snokey", label );

}

void d32_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    MAKE_LABEL

    char nokeyLabel[MAX_TEMPORARY_STORAGE];
    sprintf( nokeyLabel, "%slabel", label );
    
    Variable * temp = variable_temporary( _environment, VT_BYTE, "(pressed)" );

    d32_scancode( _environment, temp->realName, _result );
    cpu_compare_8bit( _environment, _result, _scancode,  temp->realName, 1 );
    cpu_compare_and_branch_8bit_const( _environment, temp->realName, 0, nokeyLabel, 1 );
    cpu_store_8bit( _environment, _result, 0xff );
    cpu_return( _environment );
    cpu_label( _environment, nokeyLabel );
    cpu_store_8bit( _environment, _result, 0x00 );
    cpu_return( _environment );

}

void d32_scanshift( Environment * _environment, char * _shifts ) {

    d32_keyshift( _environment, _shifts );
    
}

void d32_keyshift( Environment * _environment, char * _shifts ) {

    MAKE_LABEL

    Variable * pressed = variable_temporary( _environment, VT_BYTE, "(pressed)" );
    Variable * scancode = variable_temporary( _environment, VT_BYTE, "(scancode)" );

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result)");
    
    d32_scancode( _environment, pressed->realName, scancode->realName );

    outline1("LDA %s", result->realName );
    outline1("CMPA #$%2.2x", (unsigned char) KEY_SHIFT);
    outline0("BEQ %sshift");
    outline0("LDA #0");
    outline1("STA %s", _shifts);
    outline1("JMP %sdone", label );
    outhead1("%sshift", label);
    outline0("LDA #3");
    outline1("STA %s", _shifts);
    outline1("JMP %sdone", label );
    outhead1("%sdone", label );


}

void d32_clear_key( Environment * _environment ) {

    outline0("LDA #$0");
    outline0("LDX $35");
    outline0("STA ,X");

    outline0("LDA #$0");
    outline0("sta $87");

}

void d32_initialization( Environment * _environment ) {

}

int d32_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {
    
}

void d32_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

}

void d32_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {
    
}

void d32_back( Environment * _environment ) {

}

void d32_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline1("LDD %s", _timing );
    outline0("LDX $0112");
    outline0("LEAX D, X");
    outhead1("%sfirst", label );
    outline0("CMPX $0112");
    outline1("BGT %sfirst", label);
}

void d32_irq_at( Environment * _environment, char * _label ) {

    Variable * irq = variable_retrieve_or_define( _environment, "irq", VT_ADDRESS, 0 );

    outline0("LDA #$7e" );
    outline0("STA $010c" );
    outline0("LDX $010d" );
    outline1("STX %s", irq->realName );
    outline1("LDX #%s", _label );
    outline0("STX $010d" );
    
}

void d32_follow_irq( Environment * _environment ) {

    Variable * irq = variable_retrieve_or_define( _environment, "irq", VT_ADDRESS, 0 );

    outline1("LDX %s", irq->realName );
    outline0("PSHS X" );
    outline0("RTS" );
    
}
#endif