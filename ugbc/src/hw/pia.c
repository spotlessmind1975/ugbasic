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

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#if defined(__coco__) || defined(__coco3__) || defined(__d32__) || defined(__d64__)

void pia_inkey( Environment * _environment, char * _key ) {

    _environment->bitmaskNeeded = 1;

    if ( _environment->keyboardConfig.sync ) {
        deploy( scancode, src_hw_pia_scancode_asm);
        outline0("JSR SCANCODE");
        outline0("LDA KEYPRESS");
        outline1("STA %s", _key);
    } else {
        deploy( keyboard, src_hw_pia_keyboard_asm);
        outline0("JSR INKEY");
        outline1("STA %s", _key);
    }


}

void pia_wait_key( Environment * _environment, int _release ) {

    _environment->bitmaskNeeded = 1;

    if ( _environment->keyboardConfig.sync ) {
        deploy( scancode, src_hw_pia_scancode_asm);
    } else {
        deploy( keyboard, src_hw_pia_keyboard_asm );
    }

    if ( _release ) {
        outline0("JSR WAITKEYRELEASE");
    } else {
        outline0("JSR WAITKEY");
    }
   
}

void pia_wait_key_or_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_pia_joystick_asm );
    if ( _environment->keyboardConfig.sync ) {
        deploy( scancode, src_hw_pia_scancode_asm);
    } else {
        deploy( keyboard, src_hw_pia_keyboard_asm );
    }
    
    deploy( wait_key_or_fire, src_hw_pia_wait_key_or_fire_asm );

    if ( _port == -1 ) {
        outline0("JSR WAITKEYFIRE");
    } else {
        outline1("LDA #$%2.2x", _port );
        outline0("JSR WAITKEYFIREA");
    }
   
}

void pia_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_pia_joystick_asm );
    if ( _environment->keyboardConfig.sync ) {
        deploy( scancode, src_hw_pia_scancode_asm);
    } else {
        deploy( keyboard, src_hw_pia_keyboard_asm );
    }
    
    deploy( wait_key_or_fire, src_hw_pia_wait_key_or_fire_asm );

    if ( ! _port ) {
        outline0("JSR WAITKEYFIRE");
    } else {
        outline1("LDA %s", _port );
        outline0("JSR WAITKEYFIREA");
    }
   
}

void pia_wait_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_pia_joystick_asm );

    if ( _port == -1 ) {
        outline0("JSR WAITFIRE");
    } else {
        outline1("LDA #$%2.2x", _port );
        outline0("JSR WAITFIREA");
    }
   
}

void pia_wait_fire_semivar( Environment * _environment, char * _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_pia_joystick_asm );

    if ( !_port ) {
        outline0("JSR WAITFIRE");
    } else {
        outline1("LDA %s", _port );
        outline0("JSR WAITFIREAA");
    }
   
}

void pia_key_state( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    if ( _environment->keyboardConfig.sync ) {
        deploy( scancode, src_hw_pia_scancode_asm);
        outline1("LDA %s", _scancode);
        outline0("JSR KEYSTATE");
        outline1("STA %s", _result);
    } else {
        deploy( keyboard, src_hw_pia_keyboard_asm );
        outline1("LDA %s", _scancode);
        outline0("JSR KEYSTATE");
        cpu_ctoa( _environment );
        outline1("STA %s", _result);        
    }

}

void pia_scancode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    if ( _environment->keyboardConfig.sync ) {
        deploy( scancode, src_hw_pia_scancode_asm);
        outline0("JSR SCANCODE");
        outline0("LDA KEYPRESS");
        outline1("STA %s", _result );
    } else {
        deploy( keyboard, src_hw_pia_keyboard_asm );
        outline0("JSR SCANCODE");
        outline1("STA %s", _result );
    }
   
}

void pia_asciicode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    if ( _environment->keyboardConfig.sync ) {
        deploy( scancode, src_hw_pia_scancode_asm);
        outline0("JSR SCANCODE");
        outline0("LDA KEYPRESS");
        outline1("STA %s", _result );
    } else {
        deploy( keyboard, src_hw_pia_keyboard_asm );
        outline0("JSR ASCIICODE");
        outline1("STA %s", _result );
    }

}

void pia_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    if ( _environment->keyboardConfig.sync ) {
        deploy( scancode, src_hw_pia_scancode_asm);
        outline1("LDA %s", _scancode);
        outline0("JSR KEYPRESSED");
        outline1("STA %s", _result);        
    } else {
        deploy( keyboard, src_hw_pia_keyboard_asm );
        outline1("LDA %s", _scancode);
        outline0("JSR KEYPRESSED");
        cpu_ctoa( _environment );
        outline1("STA %s", _result);        
    }

}


void pia_scanshift( Environment * _environment, char * _shifts ) {

    pia_keyshift( _environment, _shifts );
    
}

void pia_keyshift( Environment * _environment, char * _shifts ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_pia_keyboard_asm );

    if ( _environment->keyboardConfig.sync ) {
        deploy( scancode, src_hw_pia_scancode_asm);
    } else {
        deploy( keyboard, src_hw_pia_keyboard_asm );
        outline0("JSR KEYSHIFT" );
        outline1("STA %s", _shifts );
    }

}

void pia_clear_key( Environment * _environment ) {

    _environment->bitmaskNeeded = 1;

    if ( _environment->keyboardConfig.sync ) {

    } else {
        deploy( keyboard, src_hw_pia_keyboard_asm );
        outline0("JSR CLEARKEY");
    }

}

void pia_put_key(  Environment * _environment, char *_string, char * _size ) {

    if ( _environment->keyboardConfig.sync ) {
        
    } else {
        deploy( keyboard, src_hw_pia_keyboard_asm );
        outline1("LDX %s", _string );
        outline1("LDB %s", _size );
        outline0("JSR PUTKEY" );
    }

}

#endif