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

#if defined(__atari__) || defined(__atarixl__)

#include "../ugbc.h"

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

void atari_xpen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $0234");    
    outline1("STA %s", _destination);
    outline0("LDA #0");    
    outline1("STA _%s", address_displacement(_environment, _destination, "1"));
    outhead1("%s:", label );

}

void atari_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $235");
    outline1("STA %s", _destination);    
    outline0("LDA #0");
    outline1("STA %s", address_displacement(_environment, _destination, "1"));    
   
}

void atari_inkey( Environment * _environment, char * _key ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_atari_keyboard_asm);

    outline0("JSR INKEY");
    outline1("STA %s", _key);

}

void atari_wait_key( Environment * _environment, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_atari_keyboard_asm );

    if ( _release ) {
        outline0("JSR WAITKEYRELEASE");
    } else {
        outline0("JSR WAITKEY");
    }
   
}

void atari_wait_key_or_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_atari_joystick_asm );
    deploy( keyboard, src_hw_atari_keyboard_asm );
    deploy( wait_key_or_fire, src_hw_atari_wait_key_or_fire_asm );

    if ( _port == -1 ) {
        outline0("JSR WAITKEYFIRE");
    } else {
        outline1("LDX #%2.2x", _port );
        outline0("JSR WAITKEYFIREX");
    }
   
}

void atari_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_atari_joystick_asm );
    deploy( keyboard, src_hw_atari_keyboard_asm );
    deploy( wait_key_or_fire, src_hw_atari_wait_key_or_fire_asm );

    if ( ! _port ) {
        outline0("JSR WAITKEYFIRE");
    } else {
        outline1("LDX %s", _port );
        outline0("JSR WAITKEYFIREX");
    }
   
}

void atari_wait_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_atari_joystick_asm );

    if ( _port == -1 ) {
        outline0("JSR WAITFIRE");
    } else {
        outline1("LDX #$%2.2x", (unsigned char)(_port&0xff) );
        outline0("JSR WAITFIREX");
    }
   
}

void atari_wait_fire_semivar( Environment * _environment, char * _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    deploy( joystick, src_hw_atari_joystick_asm );

    if ( !_port ) {
        outline0("JSR WAITFIRE");
    } else {
        outline1("LDX %s", _port );
        outline0("JSR WAITFIREX");
    }
   
}

void atari_key_state( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    deploy( keyboard, src_hw_atari_keyboard_asm );

    outline1("LDX %s", _scancode);
    outline0("JSR KEYSTATE");
    cpu_ctoa( _environment );
    outline1("STA %s", _result);

}

void atari_scancode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_atari_keyboard_asm);

    outline0("JSR SCANCODE");
    outline1("STA %s", _result );
   
}

void atari_asciicode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_atari_keyboard_asm);

    outline0("JSR ASCIICODE");
    outline1("STA %s", _result );
   
}

void atari_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    MAKE_LABEL

    deploy( keyboard, src_hw_atari_keyboard_asm );

    outline1("LDX %s", _scancode);
    outline0("JSR KEYPRESSED");
    cpu_ctoa( _environment );
    outline1("STA %s", _result);

}


void atari_scanshift( Environment * _environment, char * _shifts ) {

    MAKE_LABEL

    outline0("LDA #0" );
    outline1("STA %s", _shifts );

    outline0("LDA $02F2" );
    outline0("AND #$40");
    outline1("BNE %snokey", label );

    outline0("LDA #3" );
    outline1("STA %s", _shifts );
   
    outhead1("%snokey:", label );

}

void atari_keyshift( Environment * _environment, char * _shifts ) {

    _environment->bitmaskNeeded = 1;

    deploy( keyboard, src_hw_atari_keyboard_asm );

    outline0("JSR KEYSHIFT" );
    outline1("STA %s", _shifts );

}

void atari_clear_key( Environment * _environment ) {

    deploy( keyboard, src_hw_atari_keyboard_asm );

    outline0("JSR CLEARKEY");
   
}

void atari_sys_call( Environment * _environment, int _destination ) {

    outline1("JSR $%4.4x", _destination);

}

void atari_timer_set_status_on( Environment * _environment, char * _timer ) {
    
    deploy( timer, src_hw_6502_timer_asm);

    if ( _timer ) {
        outline1("LDX %s", _timer );
    } else {
        outline0("LDX #0" );
    }
    outline0("LDY #$1" );
    outline0("JSR TIMERSETSTATUS" );

}

void atari_timer_set_status_off( Environment * _environment, char * _timer ) {

    deploy( timer, src_hw_6502_timer_asm);

    if ( _timer ) {
        outline1("LDX %s", _timer );
    } else {
        outline0("LDX #0" );
    }
    outline0("LDY #$0" );
    outline0("JSR TIMERSETSTATUS" );

}

void atari_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

    deploy( timer, src_hw_6502_timer_asm);

    if ( _timer ) {
        outline1("LDX %s", _timer );
    } else {
        outline0("LDX #0" );
    }
    if ( _counter ) {
        outline1("LDA %s", _counter );
    } else {
        outline0("LDA #0" );
    }
    outline0("STA MATHPTR2");
    if ( _counter ) {
        outline1("LDA %s", address_displacement( _environment, _counter, "1" ) );
    }
    outline0("STA MATHPTR3");
    outline0("JSR TIMERSETCOUNTER" );

}

void atari_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

    deploy( timer, src_hw_6502_timer_asm);

    if ( _timer ) {
        outline1("LDX %s", _timer );
    } else {
        outline0("LDX #0" );
    }
    outline1("LDA %s", _init );
    outline0("STA MATHPTR2");
    outline1("LDA %s", address_displacement( _environment, _init, "1" ) );
    outline0("STA MATHPTR3");
    outline0("JSR TIMERSETINIT" );

}

void atari_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

    deploy( timer, src_hw_6502_timer_asm);

    if ( _timer ) {
        outline1("LDX %s", _timer );
    } else {
        outline0("LDX #0" );
    }
    outline1("LDA #<%s", _address );
    outline0("STA MATHPTR2");
    outline1("LDA #>%s", _address );
    outline0("STA MATHPTR3");
    outline0("JSR TIMERSETADDRESS" );

}

void atari_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    deploy( dcommon, src_hw_atari_dcommon_asm );
    deploy( dload, src_hw_atari_dload_asm );

    MAKE_LABEL
    
    Variable * filename = variable_retrieve( _environment, _filename );
    Variable * tnaddress = variable_temporary( _environment, VT_ADDRESS, "(address of target_name)");
    Variable * tnsize = variable_temporary( _environment, VT_BYTE, "(size of target_name)");

    Variable * address = NULL;
    if ( _address ) {
        address = variable_retrieve( _environment, _address );
    }
    Variable * size = NULL;
    if ( _size ) {
        size = variable_retrieve( _environment, _size );
    }
    Variable * offset = NULL;
    if ( _offset ) {
        offset = variable_retrieve( _environment, _offset );
    }

    switch( filename->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, filename->realName, tnsize->realName );
            cpu_addressof_16bit( _environment, filename->realName, tnaddress->realName );
            cpu_inc_16bit( _environment, tnaddress->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, filename->realName, tnaddress->realName, tnsize->realName );
            break;
    }

    outline1("LDA %s", tnaddress->realName);
    outline0("STA TMPPTR");
    outline1("LDA %s", address_displacement(_environment, tnaddress->realName, "1"));
    outline0("STA TMPPTR+1");
    outline1("LDA %s", tnsize->realName);
    outline0("STA MATHPTR0");

    if ( address ) {

        outline1("LDA %s", address->realName);
        outline0("STA TMPPTR2");
        outline1("LDA %s", address_displacement(_environment, address->realName, "1"));
        outline0("STA TMPPTR2+1");

    }

    if ( size ) {

        outline1("LDA %s", size->realName);
        outline0("STA MATHPTR4");
        outline1("LDA %s", address_displacement(_environment, size->realName, "1"));
        outline0("STA MATHPTR5");

    } else {

        outline0("LDA #$ff");
        outline0("STA MATHPTR4");
        outline0("STA MATHPTR5");

    }

    if ( offset ) {

        outline1("LDA %s", offset->realName);
        outline0("STA MATHPTR6");
        outline1("LDA %s", address_displacement(_environment, offset->realName, "1"));
        outline0("STA MATHPTR7");

    } else {

        outline0("LDA #0");
        outline0("STA MATHPTR6");
        outline0("STA MATHPTR7");

    }

    outline0("JSR ATARIDLOAD");

}

void atari_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    deploy( dcommon, src_hw_atari_dcommon_asm );
    deploy( dsave, src_hw_atari_dsave_asm );

    MAKE_LABEL
    
    Variable * filename = variable_retrieve( _environment, _filename );
    Variable * tnaddress = variable_temporary( _environment, VT_ADDRESS, "(address of target_name)");
    Variable * tnsize = variable_temporary( _environment, VT_BYTE, "(size of target_name)");

    Variable * address = NULL;
    if ( _address ) {
        address = variable_retrieve( _environment, _address );
    }
    Variable * size = NULL;
    if ( _size ) {
        size = variable_retrieve( _environment, _size );
    }
    Variable * offset = NULL;
    if ( _offset ) {
        offset = variable_retrieve( _environment, _offset );
    }

    switch( filename->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, filename->realName, tnsize->realName );
            cpu_addressof_16bit( _environment, filename->realName, tnaddress->realName );
            cpu_inc_16bit( _environment, tnaddress->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, filename->realName, tnaddress->realName, tnsize->realName );
            break;
    }

    outline1("LDA %s", tnaddress->realName);
    outline0("STA TMPPTR");
    outline1("LDA %s", address_displacement(_environment, tnaddress->realName, "1"));
    outline0("STA TMPPTR+1");
    outline1("LDA %s", tnsize->realName);
    outline0("STA MATHPTR0");

    if ( address ) {

        outline1("LDA %s", address->realName);
        outline0("STA TMPPTR2");
        outline1("LDA %s", address_displacement(_environment, address->realName, "1"));
        outline0("STA TMPPTR2+1");

    }

    if ( size ) {

        outline1("LDA %s", size->realName);
        outline0("STA MATHPTR4");
        outline1("LDA %s", address_displacement(_environment, size->realName, "1"));
        outline0("STA MATHPTR5");

    } else {

        outline0("LDA #$00");
        outline0("STA MATHPTR4");
        outline0("STA MATHPTR5");

    }

    if ( offset ) {

        outline1("LDA %s", offset->realName);
        outline0("STA MATHPTR6");
        outline1("LDA %s", address_displacement(_environment, offset->realName, "1"));
        outline0("STA MATHPTR7");

    } else {

        outline0("LDA #0");
        outline0("STA MATHPTR6");
        outline0("STA MATHPTR7");

    }

    outline0("JSR ATARIDSAVE");

}

void atari_put_key(  Environment * _environment, char *_string, char * _size ) {

    outline1("LDA %s", _string );
    outline0("STA TMPPTR" );
    outline1("LDA %s", address_displacement( _environment, _string, "1" ) );
    outline0("STA TMPPTR+1" );
    outline1("LDX %s", _size );
    outline0("JSR PUTKEY" );

}

void atari_serial_read( Environment * _environment, char * _address, char * _size ) {

    deploy( serial, src_hw_atari_serial_asm);

    outline1( "LDA %s", _address );
    outline0( "STA TMPPTR" );
    outline1( "LDA %s", address_displacement( _environment, _address, "1" ) );
    outline0( "STA TMPPTR+1" );
    outline1( "LDA %s", _size );
    outline0( "STA MATHPTR1" );
    outline0( "JSR SERIALREAD" );

}

void atari_serial_write( Environment * _environment, char * _address, char * _size, char * _result ) {

    deploy( serial, src_hw_atari_serial_asm);

    outline1( "LDA %s", _address );
    outline0( "STA TMPPTR" );
    outline1( "LDA %s", address_displacement( _environment, _address, "1" ) );
    outline0( "STA TMPPTR+1" );
    outline1( "LDA %s", _size );
    outline0( "STA MATHPTR1" );
    outline0( "JSR SERIALWRITE" );

}

void atari_fujinet_set_device( Environment * _environment, int _device_id ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( fujinet, src_hw_atari_fujinet_asm);

    cpu_store_8bit( _environment, "FUJINETDEVICEID", _device_id );

}

void atari_fujinet_set_device_var( Environment * _environment, char * _device_id ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( fujinet, src_hw_atari_fujinet_asm);

    cpu_move_8bit( _environment, _device_id, "FUJINETDEVICEID" );

}

void atari_fujinet_get_bytes_waiting( Environment * _environment, char * _bytes_waiting ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( fujinet, src_hw_atari_fujinet_asm);

    cpu_move_16bit( _environment, "FUJINETBYTESWAITING", _bytes_waiting );

}

void atari_fujinet_is_connected( Environment * _environment, char * _is_connected ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( fujinet, src_hw_atari_fujinet_asm);

    cpu_move_8bit( _environment, "FUJINETCONNECTED", _is_connected );

}

void atari_fujinet_get_error( Environment * _environment, char * _error ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( fujinet, src_hw_atari_fujinet_asm);

    cpu_move_8bit( _environment, "FUJINETERRORCODE", _error );

}

void atari_fujinet_is_ready( Environment * _environment, char * _ready ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( fujinet, src_hw_atari_fujinet_asm);

    cpu_call( _environment, "FUJINETREADY" );
    outline1( "STA %s", _ready );
    
}

void atari_fujinet_open( Environment * _environment, char * _url, char * _size, char * _mode, char * _trans, char * _result ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( fujinet, src_hw_atari_fujinet_asm);

    outline1( "LDA %s", _mode );
    outline0( "STA MATHPTR3" );
    outline1( "LDA %s", _trans );
    outline0( "STA MATHPTR4" );
    outline1( "LDA %s", _url );
    outline0( "STA TMPPTR2" );
    outline1( "LDA %s", address_displacement( _environment, _url, "1" ) );
    outline0( "STA TMPPTR2+1" );
    outline1( "LDA %s", _size );
    outline0( "STA MATHPTR2" );

    cpu_call( _environment, "FUJINETOPEN" );

    outline1( "STA %s", _result );

}

void atari_fujinet_close( Environment * _environment ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( fujinet, src_hw_atari_fujinet_asm);

    cpu_call( _environment, "FUJINETCLOSE" );

}

void atari_fujinet_get_status( Environment * _environment ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( fujinet, src_hw_atari_fujinet_asm);

    cpu_call( _environment, "FUJINETGETSTATUS" );
    
}

void atari_fujinet_read( Environment * _environment, char * _buffer, char * _size ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( fujinet, src_hw_atari_fujinet_asm);

    outline1( "LDA %s", _buffer );
    outline0( "STA TMPPTR2" );
    outline1( "LDA %s", address_displacement( _environment, _buffer, "1" ) );
    outline0( "STA TMPPTR2+1" );
    outline1( "LDA %s", _size );
    outline0( "STA MATHPTR2" );

    cpu_call( _environment, "FUJINETREAD" );

}

void atari_fujinet_write( Environment * _environment, char * _buffer, char * _size, char * _result ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( fujinet, src_hw_atari_fujinet_asm);

    outline1( "LDA %s", _buffer );
    outline0( "STA TMPPTR2" );
    outline1( "LDA %s", address_displacement( _environment, _buffer, "1" ) );
    outline0( "STA TMPPTR2+1" );
    outline1( "LDA %s", _size );
    outline0( "STA MATHPTR2" );

    cpu_call( _environment, "FUJINETWRITE" );

    outline1( "STA %s", _result );
    
}

void atari_fujinet_set_channel_mode( Environment * _environment, int _mode, char * _result ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( fujinet, src_hw_atari_fujinet_asm);

    outline1( "LDA #$%2.2x", (unsigned char)(_mode & 0xff ) );
    outline0( "STA MATHPTR2" );

    cpu_call( _environment, "FUJINETSETCHANNELMODE" );

    outline1( "STA %s", _result );

}

void atari_fujinet_set_channel_mode_var( Environment * _environment, char * _mode, char * _result ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( fujinet, src_hw_atari_fujinet_asm);

    outline1( "LDA %s", _mode );
    outline0( "STA MATHPTR2" );

    cpu_call( _environment, "FUJINETSETCHANNELMODE" );

    outline1( "STA %s", _result );

}

void atari_fujinet_parse_json( Environment * _environment, char * _result ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( fujinet, src_hw_atari_fujinet_asm);

    cpu_call( _environment, "FUJINETPARSEJSON" );

    outline1( "STA %s", _result );
    
}

void atari_fujinet_json_query( Environment * _environment, char * _query, char * _size ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( fujinet, src_hw_atari_fujinet_asm);

    outline1( "LDA %s", _query );
    outline0( "STA TMPPTR2" );
    outline1( "LDA %s", address_displacement( _environment, _query, "1" ) );
    outline0( "STA TMPPTR2+1" );
    outline1( "LDA %s", _size );
    outline0( "STA MATHPTR2" );

    cpu_call( _environment, "FUJINETSETJSONQUERY" );

}

void atari_fujinet_login( Environment * _environment, char * _login, char * _size ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( fujinet, src_hw_atari_fujinet_asm);

    outline1( "LDA %s", _login );
    outline0( "STA TMPPTR2" );
    outline1( "LDA %s", address_displacement( _environment, _login, "1" ) );
    outline0( "STA TMPPTR2+1" );
    outline1( "LDA %s", _size );
    outline0( "STA MATHPTR2" );
    
    cpu_call( _environment, "FUJINETLOGIN" );

}

void atari_fujinet_password( Environment * _environment, char * _password, char * _size ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( fujinet, src_hw_atari_fujinet_asm);

    outline1( "LDA %s", _password );
    outline0( "STA TMPPTR2" );
    outline1( "LDA %s", address_displacement( _environment, _password, "1" ) );
    outline0( "STA TMPPTR2+1" );
    outline1( "LDA %s", _size );
    outline0( "STA MATHPTR0" );
    
    cpu_call( _environment, "FUJINETPASSWORD" );

}

void atari_dojo_serial_get_response0( Environment * _environment, char * _status ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( dojo, src_hw_atari_dojo_asm);

    outline0( "JSR DOJOSERIALGETRESPONSE0" );
    if ( _status ) {
        outline1( "STA %s", _status );
    }
    
}

void atari_dojo_serial_get_response( Environment * _environment, char * _status, char * _address, char * _size ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( dojo, src_hw_atari_dojo_asm);

    outline1( "LDA %s", _address );
    outline0( "STA TMPPTR2" );
    outline1( "LDA %s", address_displacement( _environment, _address, "1" ) );
    outline0( "STA TMPPTR2+1" );

    outline0( "JSR DOJOSERIALGETRESPONSE" );
    if ( _status ) {
        outline1( "STA %s", _status );
    }
    if ( _size ) {
        outline1( "STX %S", _size );
    }

}

void atari_dojo_serial_get_responsed( Environment * _environment, char * _status, char * _data, char * _size ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( dojo, src_hw_atari_dojo_asm);

    outline1( "LDA #<%s", _data );
    outline0( "STA TMPPTR2" );
    outline1( "LDA #>%s", _data );
    outline0( "STA TMPPTR2+1" );

    outline0( "JSR DOJOSERIALGETRESPONSE" );
    if ( _status ) {
        outline1( "STA %s", _status );
    }
    if ( _size ) {
        outline1( "STX %S", _size );
    }

}

void atari_dojo_serial_put_request0( Environment * _environment, int _command, char * _param1, char * _param2, char * _result ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( dojo, src_hw_atari_dojo_asm);

    outline1( "LDA #%2.2x", _command );
    if ( _param1 ) {
        outline1( "LDX %s", _param1 );
    } else {
        outline0( "LDX #0" );
    }
    if ( _param2 ) {
        outline1( "LDY %s", _param2 );
    } else {
        outline0( "LDY #0" );
    }
    outline0( "JSR DOJOSERIALPUTREQUEST0" );
    if ( _result ) {
        outline1( "STA %s", _result );
    }

}

void atari_dojo_serial_put_request( Environment * _environment, int _command, char * _param1, char * _param2, char * _data, char * _size, char * _result ) {

    deploy( serial, src_hw_atari_serial_asm);
    deploy( dojo, src_hw_atari_dojo_asm);

    outline1( "LDA %s", _size );
    outline0( "STA MATHPTR0" );
    outline1( "LDA %s", _data );
    outline0( "STA TMPPTR2" );
    outline1( "LDA %s", address_displacement( _environment, _data, "1" ) );
    outline0( "STA TMPPTR2+1" );

    outline1( "LDA %2.2x", _command );
    if ( _param1 ) {
        outline1( "LDX %s", _param1 );
    } else {
        outline0( "LDX #0" );
    }
    if ( _param2 ) {
        outline1( "LDY %s", _param2 );
    } else {
        outline0( "LDY #0" );
    }
    outline0( "JSR DOJOSERIALPUTREQUEST" );
    if ( _result ) {
        outline1( "STA %s", _result );
    }

}

#endif