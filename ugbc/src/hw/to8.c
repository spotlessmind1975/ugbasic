/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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

#ifdef __to8__

void to8_xpen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF60");    
    outline1("STA %s", address_displacement(_environment, _destination, "1"));
    outline0("LDA #0");
    outline1("STA %s", _destination);

}

void to8_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF61");    
    outline1("STA %s", address_displacement(_environment, _destination, "1"));
    outline0("LDA #0");
    outline1("STA %s", _destination);
   
}

void to8_color_border( Environment * _environment, char * _color ) {

}

void to8_vscroll( Environment * _environment, int _displacement ) {

}

void to8_text_at( Environment * _environment, char * _text, char * _text_size, char * _pen, char * _paper ) {

}

void to8_cls( Environment * _environment, char * _pen, char * _paper ) {

}

void to8_inkey( Environment * _environment, char * _pressed, char * _key ) {

    deploy_preferred( scancode, src_hw_to8_scancode_asm );

    MAKE_LABEL

    outline0("JSR INKEY" );
    outline1("STB %s", _key );
    outline1("STA %s", _pressed );
}

void to8_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

    MAKE_LABEL

    deploy_preferred( scancode, src_hw_to8_scancode_asm );

    outline0("JSR SCANCODE" );
    outline1("STB %s", _scancode );
    outline1("STA %s", _pressed );

}

void to8_scanshift( Environment * _environment, char * _shifts ) {

    to8_keyshift( _environment, _shifts );
    
}

void to8_keyshift( Environment * _environment, char * _shifts ) {

    MAKE_LABEL

    Variable * pressed = variable_temporary( _environment, VT_BYTE, "(pressed)" );
    Variable * scancode = variable_temporary( _environment, VT_BYTE, "(scancode)" );

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result)");
    
    to8_scancode( _environment, pressed->realName, scancode->realName );

}

void to8_clear_key( Environment * _environment ) {

}

void to8_initialization( Environment * _environment ) {

}

int to8_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {
    
}

void to8_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

}

void to8_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {
    
}

void to8_back( Environment * _environment ) {

}

void to8_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline1("LDD %s", _timing );
    outline0("LDX TO8TIMER");
    outline0("LEAX D, X");
    outhead1("%sfirst", label );
    interleaved_instructions( _environment );
    outline0("CMPX TO8TIMER");
    outline1("BGT %sfirst", label);
}

void to8_irq_at( Environment * _environment, char * _label ) {

    outline1("LDX #%s", _label );
    outline0("STX PC128IRQN" );
    
}

void to8_follow_irq( Environment * _environment ) {

    outline0("JMP [PC128IRQO]" );
    
}

void to8_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    MAKE_LABEL

    deploy_preferred( scancode, src_hw_to8_scancode_asm );

    outline1("LDA %s", _scancode );
    outline0("JSR KEYPRESSED");
    outline1("BEQ %snopressed", label );
    outline0("LDA #$ff" );
    outline1("STA %s", _result );
    outline1("BRA %sfinish", label );
    outhead1("%snopressed", label );
    outline0("LDA #0" );
    outline1("STA %s", _result );
    outhead1("%sfinish", label );

}

void to8_joystick_semivars( Environment * _environment, char * _joystick, char * _result ) {

    MAKE_LABEL

    deploy( joystick, src_hw_to8_joystick_asm );

    outline1("LDA %s", _joystick );
    outline0("JSR JOYSTICK");
    outline1("STA %s", _result );

}

void to8_joystick( Environment * _environment, int _joystick, char * _result ) {

    MAKE_LABEL

    deploy( joystick, src_hw_to8_joystick_asm );

    outline1("LDA #$%2.2x", _joystick );
    outline0("JSR JOYSTICK");
    outline1("STA %s", _result );

}

void to8_sys_call( Environment * _environment, int _destination ) {

    outline0("PSHS D");
    outline1("LDD #$%4.4x", _destination );
    outline0("STD SYSCALL0+1");
    outline0("PULS D");
    outline0("JSR SYSCALL");

}

void to8_timer_set_status_on( Environment * _environment, char * _timer ) {
    
    deploy( timer, src_hw_6809_timer_asm);

    if ( _timer ) {
        outline1("LDB %s", _timer );
    } else {
        outline0("LDB #0" );
    }
    outline0("LDA #$1" );
    outline0("STA <MATHPTR0" );
    outline0("JSR TIMERSETSTATUS" );

}

void to8_timer_set_status_off( Environment * _environment, char * _timer ) {

    deploy( timer, src_hw_6809_timer_asm);

    if ( _timer ) {
        outline1("LDB %s", _timer );
    } else {
        outline0("LDB #0" );
    }
    outline0("LDA #$0" );
    outline0("STA <MATHPTR0" );
    outline0("JSR TIMERSETSTATUS" );

}

void to8_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

    deploy( timer, src_hw_6809_timer_asm);

    if ( _counter ) {
        outline1("LDD %s", _counter );
    } else {
        outline0("LDD #0" );
    }
    outline0("STD <MATHPTR2");
    if ( _timer ) {
        outline1("LDB %s", _timer );
    } else {
        outline0("LDB #0" );
    }
    outline0("JSR TIMERSETCOUNTER" );

}

void to8_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

    deploy( timer, src_hw_6809_timer_asm);

    outline1("LDD %s", _init );
    outline0("STD <MATHPTR2");
    if ( _timer ) {
        outline1("LDB %s", _timer );
    } else {
        outline0("LDB #0" );
    }
    outline0("JSR TIMERSETINIT" );

}

void to8_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

    deploy( timer, src_hw_6809_timer_asm);

    outline1("LDD #%s", _address );
    outline0("STD <MATHPTR2");
    if ( _timer ) {
        outline1("LDB %s", _timer );
    } else {
        outline0("LDB #0" );
    }
    outline0("JSR TIMERSETADDRESS" );

}

#endif