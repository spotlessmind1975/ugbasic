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

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_d64_keyboard_asm);

    outline0("JSR INKEY");
    outline1("STA %s", _key);

}

void d64_wait_key( Environment * _environment, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_d64_keyboard_asm );

    if ( _release ) {
        outline0("JSR WAITKEYRELEASE");
    } else {
        outline0("JSR WAITKEY");
    }
   
}

void d64_wait_key_or_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_d64_joystick_asm );
    deploy( keyboard, src_hw_d64_keyboard_asm );
    deploy( wait_key_or_fire, src_hw_d64_wait_key_or_fire_asm );

    outline0("JSR WAITKEYFIRE");
   
}

void d64_wait_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_d64_joystick_asm );

    outline0("JSR WAITFIRE");
   
}

void d64_key_state( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy( keyboard, src_hw_d64_keyboard_asm );

    outline1("LDA %s", _scancode);
    outline0("JSR KEYSTATE");
    cpu_ctoa( _environment );
    outline1("STA %s", _result);

}

void d64_scancode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_d64_keyboard_asm);

    outline0("JSR SCANCODE");
    outline1("STA %s", _result );
   
}

void d64_asciicode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_d64_keyboard_asm);

    outline0("JSR ASCIICODE");
    outline1("STA %s", _result );
   
}

void d64_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy( keyboard, src_hw_d64_keyboard_asm );

    outline1("LDA %s", _scancode);
    outline0("JSR KEYPRESSED");
    cpu_ctoa( _environment );
    outline1("STA %s", _result);

}


void d64_scanshift( Environment * _environment, char * _shifts ) {

    d64_keyshift( _environment, _shifts );
    
}

void d64_keyshift( Environment * _environment, char * _shifts ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_d64_keyboard_asm );

    outline0("JSR KEYSHIFT" );
    outline1("STA %s", _shifts );


}

void d64_clear_key( Environment * _environment ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_d64_keyboard_asm );

    outline0("JSR CLEARKEY");

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

    _environment->sysCallUsed = 1;

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

void d64_put_key(  Environment * _environment, char *_string, char * _size ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_d64_keyboard_asm);

    outline1("LDX %s", _string );
    outline1("LDB %s", _size );
    outline0("JSR PUTKEY" );


}

void d64_dojo_ready( Environment * _environment, char * _value ) {

}

void d64_dojo_read_byte( Environment * _environment, char * _value ) {

}

void d64_dojo_write_byte( Environment * _environment, char * _value ) {

}

void d64_dojo_login( Environment * _environment, char * _username, char * _size, char * _password, char * _password_size, char * _session_id ) {

}

void d64_dojo_success( Environment * _environment, char * _id, char * _result ) {

}

void d64_dojo_create_port( Environment * _environment, char * _session_id, char * _application, char * _size, char * _port_id ) {

}

void d64_dojo_destroy_port( Environment * _environment, char * _port_id, char * _result ) {

}

void d64_dojo_find_port( Environment * _environment, char * _session_id, char * _username, char * _size, char * _application, char * _application_size, char * _public_id ) {

}

void d64_dojo_put_message( Environment * _environment, char * _port_id, char * _message, char * _size, char * _result ) {

}

void d64_dojo_peek_message( Environment * _environment, char * _port_id, char * _result ) {

}

void d64_dojo_get_message( Environment * _environment, char * _port_id, char * _result, char * _message ) {

}

void d64_dojo_ping( Environment * _environment, char * _result ) {

}

#endif