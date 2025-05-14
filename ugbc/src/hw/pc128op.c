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

#ifdef __pc128op__

void pc128op_xpen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF60");    
    outline1("STA %s", address_displacement(_environment, _destination, "1"));
    outline0("LDA #0");
    outline1("STA %s", _destination);

}

void pc128op_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF61");    
    outline1("STA %s", address_displacement(_environment, _destination, "1"));
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

void pc128op_inkey( Environment * _environment, char * _key ) {

    _environment->bitmaskNeeded = 1;
    _environment->keyboardFullSupport = 1;

    deploy_preferred( keyboard, src_hw_pc128op_keyboard_asm);

    outline0("JSR INKEY");
    outline1("STA %s", _key);

}

void pc128op_wait_key( Environment * _environment, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy_preferred( keyboard, src_hw_pc128op_keyboard_asm );

    if ( _release ) {
        outline0("JSR WAITKEYRELEASE");
    } else {
        outline0("JSR WAITKEY");
    }
   
}

void pc128op_wait_key_or_fire( Environment * _environment, int _port, int _release ) {

    pc128op_wait_key( _environment, _release );
   
}

void pc128op_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release ) {

    pc128op_wait_key( _environment, _release );
   
}

void pc128op_wait_fire( Environment * _environment, int _port, int _release ) {

    if ( _environment->joystickConfig.notEmulated ) {

    } else {
        
        _environment->bitmaskNeeded = 1;

        deploy_preferred( keyboard, src_hw_pc128op_keyboard_asm );
        deploy( joystick, src_hw_pc128op_joystick_asm );

        if ( _port == -1 ) {
            outline0("JSR WAITFIRE");
        } else {
            outline1("LDA #$%2.2x", (unsigned char)(_port&0xff) );
            outline0("JSR WAITFIREX");
        }
    }

}

void pc128op_wait_fire_semivar( Environment * _environment, char * _port, int _release ) {

    if ( _environment->joystickConfig.notEmulated ) {

    } else {
        
        _environment->bitmaskNeeded = 1;

        deploy_preferred( keyboard, src_hw_pc128op_keyboard_asm );
        deploy( joystick, src_hw_pc128op_joystick_asm );

        if ( !_port ) {
            outline0("JSR WAITFIRE");
        } else {
            outline1("LDA %s", _port );
            outline0("JSR WAITFIREX");
        }
    }

}

void pc128op_key_state( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy_preferred( keyboard, src_hw_pc128op_keyboard_asm );

    outline1("LDA %s", _scancode);
    outline0("JSR KEYSTATE");
    cpu_ctoa( _environment );
    outline1("STA %s", _result);

}

void pc128op_scancode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    deploy_preferred( keyboard, src_hw_pc128op_keyboard_asm);

    outline0("JSR SCANCODE");
    outline1("STA %s", _result );
   
}

void pc128op_asciicode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;
    _environment->keyboardFullSupport = 1;

    deploy_preferred( keyboard, src_hw_pc128op_keyboard_asm);

    outline0("JSR ASCIICODE");
    outline1("STA %s", _result );
   
}

void pc128op_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy_preferred( keyboard, src_hw_pc128op_keyboard_asm );

    outline1("LDA %s", _scancode);
    outline0("JSR KEYPRESSED");
    cpu_ctoa( _environment );
    outline1("STA %s", _result);

}


void pc128op_scanshift( Environment * _environment, char * _shifts ) {

    pc128op_keyshift( _environment, _shifts );
    
}

void pc128op_keyshift( Environment * _environment, char * _shifts ) {

    _environment->bitmaskNeeded = 1;
    _environment->keyboardFullSupport = 1;

    deploy_preferred( keyboard, src_hw_pc128op_keyboard_asm );

    outline0("JSR KEYSHIFT" );
    outline1("STA %s", _shifts );

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

void pc128op_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline1("LDD %s", _timing );
    outline0("LDX PC128TIMER");
    outline0("LEAX D, X");
    outhead1("%sfirst", label );
    interleaved_instructions( _environment );
    outline0("CMPX PC128TIMER");
    outline1("BGT %sfirst", label);
}

void pc128op_joystick( Environment * _environment, int _joystick, char * _result ) {

    if ( _environment->joystickConfig.notEmulated ) {
        cpu_store_8bit( _environment, _result, 0 );
    } else {
        
        _environment->bitmaskNeeded = 1;

        deploy_preferred( keyboard, src_hw_pc128op_keyboard_asm );
        deploy( joystick, src_hw_pc128op_joystick_asm );

        outline1("LDA #$%2.2x", _joystick);
        outline0("JSR JOYSTICK");
        outline1("STA %s", _result);

    }

}

void pc128op_joystick_semivars( Environment * _environment, char * _joystick, char * _result ) {

    if ( _environment->joystickConfig.notEmulated ) {
        cpu_store_8bit( _environment, _result, 0 );
    } else {
        
        _environment->bitmaskNeeded = 1;

        deploy_preferred( keyboard, src_hw_pc128op_keyboard_asm );
        deploy( joystick, src_hw_pc128op_joystick_asm );

        outline1("LDA %s", _joystick);
        outline0("JSR JOYSTICK");
        outline1("STA %s", _result);

    }

}

void pc128op_sys_call( Environment * _environment, int _destination ) {

    _environment->sysCallUsed = 1;

    outline0("PSHS D");
    outline1("LDD #$%4.4x", _destination );
    outline0("STD SYSCALL0+1");
    outline0("PULS D");
    outline0("JSR SYSCALL");
    
}

void pc128op_timer_set_status_on( Environment * _environment, char * _timer ) {
    
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

void pc128op_timer_set_status_off( Environment * _environment, char * _timer ) {

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

void pc128op_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

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

void pc128op_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

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

void pc128op_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

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

void pc128op_put_key(  Environment * _environment, char *_string, char * _size ) {

    _environment->bitmaskNeeded = 1;

    deploy_preferred( keyboard, src_hw_pc128op_keyboard_asm);

    outline1("LDX %s", _string );
    outline1("LDB %s", _size );
    outline0("JSR PUTKEY" );

}

void pc128op_dload( Environment * _environment, char * _address, char * _bank, char * _size ) {

    deploy_preferred( duff, src_hw_6809_duff_asm );
    deploy_preferred( msc1, src_hw_6809_msc1_asm );
    deploy_preferred( bank, src_hw_pc128op_bank_asm );        
    deploy( dload, src_hw_pc128op_dload_asm);

    if ( _bank ) {
        outline1("LDA %s", _bank );
    } else {
        outline0("CLRA" );
    }
    outline1("LDX %s", _address );
    outline1("LDU %s", _size );
    outline0("JSR DLOAD" );

}

#endif