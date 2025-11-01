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

#ifdef __coco3__

void coco3_xpen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF60");    
    outline1("STA %s", address_displacement(_environment, _destination, "1"));
    outline0("LDA #0");
    outline1("STA %s", _destination);

}

void coco3_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $FF61");    
    outline1("STA %s", address_displacement(_environment, _destination, "1"));
    outline0("LDA #0");
    outline1("STA %s", _destination);
   
}

void coco3_color_border( Environment * _environment, char * _color ) {

}

void coco3_vscroll( Environment * _environment, int _displacement ) {

}

void coco3_text_at( Environment * _environment, char * _text, char * _text_size, char * _pen, char * _paper ) {

}

void coco3_cls( Environment * _environment, char * _pen, char * _paper ) {

}

void coco3_initialization( Environment * _environment ) {

}

int coco3_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {
    
}

void coco3_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

}

void coco3_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {
    
}

void coco3_back( Environment * _environment ) {

}

void coco3_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline1("LDD %s", _timing );
    outline0("LDX COCO3TIMER");
    outline0("LEAX D, X");
    outhead1("%sfirst", label );
    outline0("CMPX COCO3TIMER");
    outline1("BGT %sfirst", label);
}

void coco3_sys_call( Environment * _environment, int _destination ) {

    _environment->sysCallUsed = 1;

    outline0("PSHS D");
    outline1("LDD #$%4.4x", _destination );
    outline0("STD SYSCALL0+1");
    outline0("PULS D");
    outline0("JSR SYSCALL");

}

void coco3_timer_set_status_on( Environment * _environment, char * _timer ) {
    
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

void coco3_timer_set_status_off( Environment * _environment, char * _timer ) {

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

void coco3_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

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

void coco3_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

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

void coco3_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

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

void coco3_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    deploy_preferred( dcommon, src_hw_coco3_dcommon_asm);
    deploy_preferred( dload, src_hw_coco3_dload_asm);

    MAKE_LABEL
    
    Variable * filename = variable_retrieve( _environment, _filename );
    Variable * tnaddress = variable_temporary( _environment, VT_ADDRESS, "(address of target_name)");
    Variable * tnsize = variable_temporary( _environment, VT_BYTE, "(size of target_name)");

    Variable * address = NULL;
    if ( _address ) {
        address = variable_retrieve( _environment, _address );
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

    outline1("LDB %s", tnsize->realName);
    outline0("CLRA");
    outline0("TFR D, U");
    outline1("LDX %s", tnaddress->realName);

    if ( address ) {

        outline1("LDY %s", address->realName);

    }

    outline0("JSR COCO3DLOAD");

}

void coco3_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    deploy_preferred( dcommon, src_hw_coco3_dcommon_asm);
    deploy_preferred( dsave, src_hw_coco3_dsave_asm);

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

    outline1("LDB %s", tnsize->realName);
    outline0("CLRA");
    outline0("TFR D, U");
    outline1("LDX %s", tnaddress->realName);

    if ( address ) {

        outline1("LDY %s", address->realName);

    }

    if ( size ) {

        outline1("LDU %s", size->realName);

    }

    outline0("JSR COCO3DSAVE");

}


void coco3_serial_read( Environment * _environment, char * _address, char * _size ) {

    deploy( serial, src_hw_coco3_serial_asm);

    outline1( "LDX %s", _address );
    outline1( "LDB %s", _size );
    outline0( "JSR SERIALREAD" );

}

void coco3_serial_write( Environment * _environment, char * _address, char * _size, char * _result ) {

    deploy( serial, src_hw_coco3_serial_asm);

    outline1( "LDX %s", _address );
    outline1( "LDB %s", _size );
    outline0( "JSR SERIALWRITE" );
    outline1( "STB %s", _result );

}

void coco3_fujinet_set_device( Environment * _environment, int _device_id ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);

    cpu_store_8bit( _environment, "FUJINETDEVICEID", _device_id );

}

void coco3_fujinet_set_device_var( Environment * _environment, char * _device_id ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);

    cpu_move_8bit( _environment, _device_id, "FUJINETDEVICEID" );

}

void coco3_fujinet_get_bytes_waiting( Environment * _environment, char * _bytes_waiting ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);

    cpu_move_16bit( _environment, "FUJINETBYTESWAITING", _bytes_waiting );

}

void coco3_fujinet_is_connected( Environment * _environment, char * _is_connected ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);

    cpu_move_8bit( _environment, "FUJINETCONNECTED", _is_connected );

}

void coco3_fujinet_get_error( Environment * _environment, char * _error ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);

    cpu_move_8bit( _environment, "FUJINETERRORCODE", _error );

}

void coco3_fujinet_is_ready( Environment * _environment, char * _ready ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);

    cpu_call( _environment, "FUJINETREADY" );
    outline1( "STA %s", _ready );
    
}

void coco3_fujinet_open( Environment * _environment, char * _url, char * _size, char * _mode, char * _trans, char * _result ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);

    if ( _mode ) {
        outline1( "LDA %s", _mode );
    } else {
        outline0( "LDA #0" );
    }
    if ( _trans ) {
        outline1( "LDB %s", _trans );
    } else {
        outline0( "LDB #0" );
    }
    outline0( "TFR D, U" );
    outline1( "LDY %s", _url );
    outline1( "LDB %s", _size );

    cpu_call( _environment, "FUJINETOPEN" );

    if ( _result ) {
        outline1( "STA %s", _result );
    }

}

void coco3_fujinet_close( Environment * _environment ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);

    cpu_call( _environment, "FUJINETCLOSE" );

}

void coco3_fujinet_get_status( Environment * _environment ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);

    cpu_call( _environment, "FUJINETGETSTATUS" );
    
}

void coco3_fujinet_read( Environment * _environment, char * _buffer, char * _size ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);

    outline1( "LDY %s", _buffer );
    outline1( "LDB %s", _size );

    cpu_call( _environment, "FUJINETREAD" );

}

void coco3_fujinet_write( Environment * _environment, char * _buffer, char * _size, char * _result ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);

    outline1( "LDY %s", _buffer );
    outline1( "LDB %s", _size );

    cpu_call( _environment, "FUJINETWRITE" );

    if ( _result ) {
        outline1( "STA %s", _result );
    }
    
}

void coco3_fujinet_set_channel_mode( Environment * _environment, int _mode, char * _result ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);

    outline1( "LDB #$%2.2x", (unsigned char)(_mode&0xff) );

    cpu_call( _environment, "FUJINETSETCHANNELMODE" );

    if ( _result ) {
        outline1( "STA %s", _result );
    }

}

void coco3_fujinet_set_channel_mode_var( Environment * _environment, char * _mode, char * _result ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);

    outline1( "LDB %s", _mode );

    cpu_call( _environment, "FUJINETSETCHANNELMODE" );

    if ( _result ) {
        outline1( "STA %s", _result );
    }

}

void coco3_fujinet_parse_json( Environment * _environment, char * _result ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);

    cpu_call( _environment, "FUJINETPARSEJSON" );

    if ( _result ) {
        outline1( "STA %s", _result );
    }
    
}

void coco3_fujinet_json_query( Environment * _environment, char * _query, char * _size ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);

    outline1( "LDY %s", _query );
    outline1( "LDB %s", _size );

    cpu_call( _environment, "FUJINETSETJSONQUERY" );

}

void coco3_fujinet_login( Environment * _environment, char * _login, char * _size ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);

    outline1( "LDY %s", _login );
    outline1( "LDB %s", _size );
    
    cpu_call( _environment, "FUJINETLOGIN" );

}

void coco3_fujinet_password( Environment * _environment, char * _password, char * _size ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);

    outline1( "LDY %s", _password );
    outline1( "LDB %s", _size );
    
    cpu_call( _environment, "FUJINETPASSWORD" );

}

void coco3_dojo_serial_get_response0( Environment * _environment, char * _status ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( dojo, src_hw_coco3_dojo_asm);

    outline0( "JSR DOJOSERIALGETRESPONSE0" );
    if ( _status ) {
        outline1( "STA %s", _status );
    }
    
}

void coco3_dojo_serial_get_response( Environment * _environment, char * _status, char * _address, char * _size ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( dojo, src_hw_coco3_dojo_asm);

    outline1( "LDY %s", _address );

    outline0( "JSR DOJOSERIALGETRESPONSE" );
    if ( _status ) {
        outline1( "STA %s", _status );
    }
    if ( _size ) {
        outline1( "STB %S", _size );
    }

}

void coco3_dojo_serial_get_responsed( Environment * _environment, char * _status, char * _data, char * _size ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( dojo, src_hw_coco3_dojo_asm);

    outline1( "LDY #%s", _data );

    outline0( "JSR DOJOSERIALGETRESPONSE" );
    if ( _status ) {
        outline1( "STA %s", _status );
    }
    if ( _size ) {
        outline1( "STB %S", _size );
    }

}

void coco3_dojo_serial_get_response_size( Environment * _environment, char * _status, char * _size ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( dojo, src_hw_coco3_dojo_asm);

    outline0( "JSR DOJOSERIALGETRESPONSE0" );
    if ( _status ) {
        outline1( "STA %s", _status );
    }
    if ( _size ) {
        outline1( "STB %s", _size );
    }

}

void coco3_dojo_serial_get_response_payload( Environment * _environment, char * _address ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( dojo, src_hw_coco3_dojo_asm);

    outline1( "LDY %s", _address );

    outline0( "JSR DOJOSERIALGETRESPONSEPAYLOAD" );

}

void coco3_dojo_serial_get_response_payloadd( Environment * _environment, char * _data ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( dojo, src_hw_coco3_dojo_asm);

    outline1( "LDY #%s", _data );

    outline0( "JSR DOJOSERIALGETRESPONSEPAYLOAD" );

}

void coco3_dojo_serial_put_request0( Environment * _environment, int _command, char * _param1, char * _param2, char * _result ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( dojo, src_hw_coco3_dojo_asm);

    if ( _param1 ) {
        outline1( "LDA %s", _param1 );
    } else {
        outline0( "LDA #0" );
    }
    if ( _param2 ) {
        outline1( "LDB %s", _param2 );
    } else {
        outline0( "LDB #0" );
    }
    outline0( "TFR D, U" );
    outline1( "LDA #$%2.2x", _command );
    outline0( "JSR DOJOSERIALPUTREQUEST0" );
    if ( _result ) {
        outline1( "STA %s", _result );
    }

}

void coco3_dojo_serial_put_request( Environment * _environment, int _command, char * _param1, char * _param2, char * _address, char * _size, char * _result ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( dojo, src_hw_coco3_dojo_asm);

    if ( _param1 ) {
        outline1( "LDA %s", _param1 );
    } else {
        outline0( "LDA #0" );
    }
    if ( _param2 ) {
        outline1( "LDB %s", _param2 );
    } else {
        outline0( "LDB #0" );
    }
    outline0( "TFR D, U" );
    outline1( "LDA #$%2.2x", _command );
    outline1( "LDB %s", _size );
    outline1( "LDY %s", _address );
    outline0( "JSR DOJOSERIALPUTREQUEST" );
    if ( _result ) {
        outline1( "STA %s", _result );
    }

}

void coco3_dojo_serial_put_requestd( Environment * _environment, int _command, char * _param1, char * _param2, char * _data, char * _size, char * _result ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( dojo, src_hw_coco3_dojo_asm);

    if ( _param1 ) {
        outline1( "LDA %s", _param1 );
    } else {
        outline0( "LDA #0" );
    }
    if ( _param2 ) {
        outline1( "LDB %s", _param2 );
    } else {
        outline0( "LDB #0" );
    }
    outline0( "TFR D, U" );
    outline1( "LDA #$%2.2x", _command );
    outline1( "LDB %s", _size );
    outline1( "LDY #%s", _data );
    outline0( "JSR DOJOSERIALPUTREQUEST" );
    if ( _result ) {
        outline1( "STA %s", _result );
    }

}

void coco3_dojo_serial_put_requestds( Environment * _environment, int _command, char * _param1, char * _param2, char * _data, int _size, char * _result ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( dojo, src_hw_coco3_dojo_asm);

    if ( _param1 ) {
        outline1( "LDA %s", _param1 );
    } else {
        outline0( "LDA #0" );
    }
    if ( _param2 ) {
        outline1( "LDB %s", _param2 );
    } else {
        outline0( "LDB #0" );
    }
    outline0( "TFR D, U" );
    outline1( "LDA #$%2.2x", _command );
    outline1( "LDB #$%2.2x", (unsigned char)(_size&0xff) );
    outline1( "LDY #%s", _data );
    outline0( "JSR DOJOSERIALPUTREQUEST" );
    if ( _result ) {
        outline1( "STA %s", _result );
    }

}

/////////////////////////////////

void coco3_dojo_fujinet_get_response0( Environment * _environment, char * _status ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);
    deploy( dojo_fujinet, src_hw_coco3_dojo_fujinet_asm);

    outline0( "JSR DOJOFUJINETGETRESPONSE0" );
    if ( _status ) {
        outline1( "STA %s", _status );
    }
    
}

void coco3_dojo_fujinet_get_response( Environment * _environment, char * _status, char * _address, char * _size ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);
    deploy( dojo_fujinet, src_hw_coco3_dojo_fujinet_asm);

    outline1( "LDY %s", _address );

    outline0( "JSR DOJOFUJINETGETRESPONSE" );
    if ( _status ) {
        outline1( "STA %s", _status );
    }
    if ( _size ) {
        outline1( "STB %S", _size );
    }

}

void coco3_dojo_fujinet_get_responsed( Environment * _environment, char * _status, char * _data, char * _size ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);
    deploy( dojo_fujinet, src_hw_coco3_dojo_fujinet_asm);

    outline1( "LDY #%s", _data );

    outline0( "JSR DOJOFUJINETGETRESPONSE" );
    if ( _status ) {
        outline1( "STA %s", _status );
    }
    if ( _size ) {
        outline1( "STB %S", _size );
    }

}

void coco3_dojo_fujinet_get_response_size( Environment * _environment, char * _status, char * _size ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);
    deploy( dojo_fujinet, src_hw_coco3_dojo_fujinet_asm);

    outline0( "JSR DOJOFUJINETGETRESPONSE0" );
    if ( _status ) {
        outline1( "STA %s", _status );
    }
    if ( _size ) {
        outline1( "STB %s", _size );
    }

}

void coco3_dojo_fujinet_get_response_payload( Environment * _environment, char * _address ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);
    deploy( dojo_fujinet, src_hw_coco3_dojo_fujinet_asm);

    outline1( "LDY %s", _address );

    outline0( "JSR DOJOFUJINETGETRESPONSEPAYLOAD" );

}

void coco3_dojo_fujinet_get_response_payloadd( Environment * _environment, char * _data ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);
    deploy( dojo_fujinet, src_hw_coco3_dojo_fujinet_asm);

    outline1( "LDY #%s", _data );

    outline0( "JSR DOJOFUJINETGETRESPONSEPAYLOAD" );

}

void coco3_dojo_fujinet_put_request0( Environment * _environment, int _command, char * _param1, char * _param2, char * _result ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);
    deploy( dojo_fujinet, src_hw_coco3_dojo_fujinet_asm);

    if ( _param1 ) {
        outline1( "LDA %s", _param1 );
    } else {
        outline0( "LDA #0" );
    }
    if ( _param2 ) {
        outline1( "LDB %s", _param2 );
    } else {
        outline0( "LDB #0" );
    }
    outline0( "TFR D, U" );
    outline1( "LDA #$%2.2x", _command );
    outline0( "JSR DOJOFUJINETPUTREQUEST0" );
    if ( _result ) {
        outline0( "LDA #0" );
        outline1( "STA %s", _result );
    }

}

void coco3_dojo_fujinet_put_request( Environment * _environment, int _command, char * _param1, char * _param2, char * _address, char * _size, char * _result ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);
    deploy( dojo_fujinet, src_hw_coco3_dojo_fujinet_asm);

    if ( _param1 ) {
        outline1( "LDA %s", _param1 );
    } else {
        outline0( "LDA #0" );
    }
    if ( _param2 ) {
        outline1( "LDB %s", _param2 );
    } else {
        outline0( "LDB #0" );
    }
    outline0( "TFR D, U" );
    outline1( "LDA #$%2.2x", _command );
    outline1( "LDB %s", _size );
    outline1( "LDY %s", _address );
    outline0( "JSR DOJOFUJINETPUTREQUEST" );
    if ( _result ) {
        outline0( "LDA #0" );
        outline1( "STA %s", _result );
    }

}

void coco3_dojo_fujinet_put_requestd( Environment * _environment, int _command, char * _param1, char * _param2, char * _data, char * _size, char * _result ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);
    deploy( dojo_fujinet, src_hw_coco3_dojo_fujinet_asm);

    if ( _param1 ) {
        outline1( "LDA %s", _param1 );
    } else {
        outline0( "LDA #0" );
    }
    if ( _param2 ) {
        outline1( "LDB %s", _param2 );
    } else {
        outline0( "LDB #0" );
    }
    outline0( "TFR D, U" );
    outline1( "LDA #$%2.2x", _command );
    outline1( "LDB %s", _size );
    outline1( "LDY #%s", _data );
    outline0( "JSR DOJOFUJINETPUTREQUEST" );
    if ( _result ) {
        outline0( "LDA #0" );
        outline1( "STA %s", _result );
    }

}

void coco3_dojo_fujinet_put_requestds( Environment * _environment, int _command, char * _param1, char * _param2, char * _data, int _size, char * _result ) {

    deploy( serial, src_hw_coco3_serial_asm);
    deploy( fujinet, src_hw_coco3_fujinet_asm);
    deploy( dojo_fujinet, src_hw_coco3_dojo_fujinet_asm);

    if ( _param1 ) {
        outline1( "LDA %s", _param1 );
    } else {
        outline0( "LDA #0" );
    }
    if ( _param2 ) {
        outline1( "LDB %s", _param2 );
    } else {
        outline0( "LDB #0" );
    }
    outline0( "TFR D, U" );
    outline1( "LDA #$%2.2x", _command );
    outline1( "LDB #$%2.2x", (unsigned char)(_size&0xff) );
    outline1( "LDY #%s", _data );
    outline0( "JSR DOJOFUJINETPUTREQUEST" );
    if ( _result ) {
        outline0( "LDA #0" );
        outline1( "STA %s", _result );
    }

}

#endif