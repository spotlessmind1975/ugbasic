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

#ifdef __pc128op__

void pc128op_xpen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF60");    
    outline1("STA %s+1", _destination);
    outline0("LDA #0");
    outline1("STA %s", _destination);

}

void pc128op_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF61");    
    outline1("STA %s+1", _destination);
    outline0("LDA #0");
    outline1("STA %s", _destination);
   
}

void pc128op_color_border( Environment * _environment, char * _color ) {

}

void pc128op_vscroll( Environment * _environment, int _displacement ) {

}

void pc128op_text_at( Environment * _environment, char * _text, char * _text_size, char * _pen, char * _paper ) {

}

void pc128op_cls( Environment * _environment, char * _pen, char * _paper ) {

}

void pc128op_inkey( Environment * _environment, char * _pressed, char * _key ) {

    MAKE_LABEL

    pc128op_scancode( _environment, _pressed, _key );

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
    outhead1("%sskip", label );
    outline0("LDA #0" );
    outline0("STA $011d" );
    outhead1("%sdone", label );
}

void pc128op_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

    MAKE_LABEL

    deploy( scancode, src_hw_pc128op_scancode_asm );

    outline0("LDA #0" );
    outline1("STA %s", _pressed );
    outline1("STA %s", _scancode );

    outline0("SWI" );
    outline0("fcb 10" );
    outline0("TFR B,A" );
    outline1("BEQ %snokey", label );
    outline1("STA %s", _scancode );
    outline0("LDA #$FF" );
    outline1("STA %s", _pressed );
    outhead1("%snokey", label );

}

void pc128op_scanshift( Environment * _environment, char * _shifts ) {

    pc128op_keyshift( _environment, _shifts );
    
}

void pc128op_keyshift( Environment * _environment, char * _shifts ) {

    MAKE_LABEL

    Variable * pressed = variable_temporary( _environment, VT_BYTE, "(pressed)" );
    Variable * scancode = variable_temporary( _environment, VT_BYTE, "(scancode)" );

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result)");
    
    pc128op_scancode( _environment, pressed->realName, scancode->realName );

}

void pc128op_clear_key( Environment * _environment ) {

}

void pc128op_initialization( Environment * _environment ) {

}

int pc128op_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {
    
}

void pc128op_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

}

void pc128op_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {
    
}

void pc128op_back( Environment * _environment ) {

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

void pc128op_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline1("LDD %s", _timing );
    outline0("LDX PC128TIMER");
    outline0("LEAX D, X");
    outhead1("%sfirst", label );
    outline0("CMPX PC128TIMER");
    outline1("BGT %sfirst", label);
}

void pc128op_irq_at( Environment * _environment, char * _label ) {

    outline1("LDX #%s", _label );
    outline0("STX PC128IRQN" );
    
}

void pc128op_follow_irq( Environment * _environment ) {

    outline0("JMP [PC128IRQO]" );
    
}
#endif