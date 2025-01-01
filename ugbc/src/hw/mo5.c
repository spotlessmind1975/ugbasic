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

#include "../ugbc.h"
#include <math.h>

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __mo5__

void mo5_xpen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF60");    
    outline1("STA %s", address_displacement(_environment, _destination, "1"));
    outline0("LDA #0");
    outline1("STA %s", _destination);

}

void mo5_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF61");    
    outline1("STA %s", address_displacement(_environment, _destination, "1"));
    outline0("LDA #0");
    outline1("STA %s", _destination);
   
}

void mo5_color_border( Environment * _environment, char * _color ) {

}

void mo5_vscroll( Environment * _environment, int _displacement ) {

}

void mo5_text_at( Environment * _environment, char * _text, char * _text_size, char * _pen, char * _paper ) {

}

void mo5_cls( Environment * _environment, char * _pen, char * _paper ) {

}

void mo5_inkey( Environment * _environment, char * _key ) {

   _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_mo5_keyboard_asm);

    outline0("JSR INKEY");
    outline1("STA %s", _key);

}

void mo5_wait_key( Environment * _environment, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_mo5_keyboard_asm );

    if ( _release ) {
        outline0("JSR WAITKEYRELEASE");
    } else {
        outline0("JSR WAITKEY");
    }
   
}

void mo5_wait_key_or_fire( Environment * _environment, int _port, int _release ) {

    mo5_wait_key( _environment, _release );
   
}

void mo5_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release ) {

    mo5_wait_key( _environment, _release );
   
}

void mo5_wait_fire( Environment * _environment, int _port, int _release ) {

}

void mo5_wait_fire_semivar( Environment * _environment, char * _port, int _release ) {

}

void mo5_key_state( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy( keyboard, src_hw_mo5_keyboard_asm );

    outline1("LDA %s", _scancode);
    outline0("JSR KEYSTATE");
    cpu_ctoa( _environment );
    outline1("STA %s", _result);

}

void mo5_scancode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_mo5_keyboard_asm);

    outline0("JSR SCANCODE");
    outline1("STA %s", _result );
   
}

void mo5_asciicode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_mo5_keyboard_asm);

    outline0("JSR ASCIICODE");
    outline1("STA %s", _result );
   
}

void mo5_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy( keyboard, src_hw_mo5_keyboard_asm );

    outline1("LDA %s", _scancode);
    outline0("JSR KEYPRESSED");
    cpu_ctoa( _environment );
    outline1("STA %s", _result);

}


void mo5_scanshift( Environment * _environment, char * _shifts ) {

    mo5_keyshift( _environment, _shifts );
    
}

void mo5_keyshift( Environment * _environment, char * _shifts ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_mo5_keyboard_asm );

    outline0("JSR KEYSHIFT" );
    outline1("STA %s", _shifts );

}

void mo5_clear_key( Environment * _environment ) {

}

void mo5_initialization( Environment * _environment ) {

}

int mo5_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {
    
}

void mo5_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

}

void mo5_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {
    
}

void mo5_back( Environment * _environment ) {

}

void mo5_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline1("LDD %s", _timing );
    outline0("LDX MO5TIMER");
    outline0("LEAX D, X");
    outhead1("%sfirst", label );
    outline0("CMPX MO5TIMER");
    outline1("BGT %sfirst", label);
}

void mo5_joystick_semivars( Environment * _environment, int _joystick, char * _result ) {

    cpu_store_8bit( _environment, _result, 0 );

}

void mo5_joystick_vars( Environment * _environment, char * _joystick, char * _result ) {

    cpu_store_8bit( _environment, _result, 0 );

}

void mo5_sys_call( Environment * _environment, int _destination ) {

    _environment->sysCallUsed = 1;

    outline0("PSHS D");
    outline1("LDD #$%4.4x", _destination );
    outline0("STD SYSCALL0+1");
    outline0("PULS D");
    outline0("JSR SYSCALL");

}

void mo5_timer_set_status_on( Environment * _environment, char * _timer ) {
    
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

void mo5_timer_set_status_off( Environment * _environment, char * _timer ) {

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

void mo5_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

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

void mo5_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

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

void mo5_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

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

void mo5_put_key(  Environment * _environment, char *_string, char * _size ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_mo5_keyboard_asm);

    outline1("LDX %s", _string );
    outline1("LDB %s", _size );
    outline0("JSR PUTKEY" );

}


void mo5_dojo_ready( Environment * _environment, char * _value ) {

}

void mo5_dojo_read_byte( Environment * _environment, char * _value ) {

}

void mo5_dojo_write_byte( Environment * _environment, char * _value ) {

}

void mo5_dojo_login( Environment * _environment, char * _username, char * _size, char * _password, char * _password_size, char * _session_id ) {

}

void mo5_dojo_success( Environment * _environment, char * _id, char * _result ) {

}

void mo5_dojo_create_port( Environment * _environment, char * _session_id, char * _application, char * _size, char * _port_id ) {

}

void mo5_dojo_destroy_port( Environment * _environment, char * _port_id, char * _result ) {

}

void mo5_dojo_find_port( Environment * _environment, char * _session_id, char * _username, char * _size, char * _application, char * _application_size, char * _public_id ) {

}

void mo5_dojo_put_message( Environment * _environment, char * _port_id, char * _message, char * _size, char * _result ) {

}

void mo5_dojo_peek_message( Environment * _environment, char * _port_id, char * _result ) {

}

void mo5_dojo_get_message( Environment * _environment, char * _port_id, char * _result, char * _message ) {

}

void mo5_dojo_ping( Environment * _environment, char * _result ) {

}

#endif