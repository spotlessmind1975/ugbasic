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

#ifdef __d64__

void d64_xpen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF60");    
    outline1("STA %s", address_displacement(_environment, _destination, "1"));
    outline0("LDA #0");
    outline1("STA %s", _destination);

}

void d64_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF61");    
    outline1("STA %s", address_displacement(_environment, _destination, "1"));
    outline0("LDA #0");
    outline1("STA %s", _destination);
   
}

void d64_color_border( Environment * _environment, char * _color ) {

}

void d64_vscroll( Environment * _environment, int _displacement ) {

}

void d64_text_at( Environment * _environment, char * _text, char * _text_size, char * _pen, char * _paper ) {

}

void d64_cls( Environment * _environment, char * _pen, char * _paper ) {

}

void d64_inkey( Environment * _environment, char * _key ) {

    deploy( keyboard, src_hw_d64_keyboard_asm);

    outline0("JSR INKEY");
    outline1("STA %s", _key);

}

void d64_wait_key( Environment * _environment, int _release ) {

    deploy( keyboard, src_hw_d64_keyboard_asm );

    if ( _release ) {
        outline0("JSR WAITKEYRELEASE");
    } else {
        outline0("JSR WAITKEY");
    }
   
}

void d64_key_state( Environment * _environment, char *_scancode, char * _result ) {

    MAKE_LABEL

    deploy( keyboard, src_hw_d64_keyboard_asm );

    outline1("LDA %s", _scancode);
    outline0("JSR KEYSTATE");
    cpu_ctoa( _environment );

}

void d64_scancode( Environment * _environment, char * _result ) {

    deploy( keyboard, src_hw_d64_keyboard_asm);

    outline0("JSR SCANCODE");
    outline1("STA %s", _result );
   
}

void d64_asciicode( Environment * _environment, char * _result ) {

    deploy( keyboard, src_hw_d64_keyboard_asm);

    outline0("JSR ASCIICODE");
    outline1("STA %s", _result );
   
}

void d64_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    MAKE_LABEL

    deploy( keyboard, src_hw_d64_keyboard_asm );

    outline1("LDA %s", _scancode);
    outline0("JSR KEYPRESSED");
    cpu_ctoa( _environment );

}

void d64_scanshift( Environment * _environment, char * _shifts ) {

    d64_keyshift( _environment, _shifts );
    
}

void d64_keyshift( Environment * _environment, char * _shifts ) {

    MAKE_LABEL

    Variable * scancode = variable_temporary( _environment, VT_BYTE, "(scancode)" );

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result)");
    
    d64_scancode( _environment, scancode->realName );

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

void d64_clear_key( Environment * _environment ) {

    outline0("LDA #$0");
    outline0("LDX $35");
    outline0("STA ,X");

    outline0("LDA #$0");
    outline0("sta $87");

}

void d64_initialization( Environment * _environment ) {

}

int d64_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {
    
}

void d64_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

}

void d64_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {
    
}

void d64_back( Environment * _environment ) {

}

void d64_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline1("LDD %s", _timing );
    outline0("LDX $0112");
    outline0("LEAX D, X");
    outhead1("%sfirst", label );
    outline0("CMPX $0112");
    outline1("BGT %sfirst", label);
}

void d64_irq_at( Environment * _environment, char * _label ) {

    Variable * irq = variable_retrieve_or_define( _environment, "irq", VT_ADDRESS, 0 );

    outline0("LDA #$7e" );
    outline0("STA $010c" );
    outline0("LDX $010d" );
    outline1("STX %s", irq->realName );
    outline1("LDX #%s", _label );
    outline0("STX $010d" );
    
}

void d64_follow_irq( Environment * _environment ) {

    Variable * irq = variable_retrieve_or_define( _environment, "irq", VT_ADDRESS, 0 );

    outline1("LDX %s", irq->realName );
    outline0("PSHS X" );
    outline0("RTS" );
    
}

void d64_sys_call( Environment * _environment, int _destination ) {

    outline0("PSHS D");
    outline1("LDD #$%4.4x", _destination );
    outline0("STD SYSCALL0+1");
    outline0("PULS D");
    outline0("JSR SYSCALL");

}

void d64_timer_set_status_on( Environment * _environment, char * _timer ) {
    
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

void d64_timer_set_status_off( Environment * _environment, char * _timer ) {

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

void d64_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

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

void d64_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

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

void d64_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

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