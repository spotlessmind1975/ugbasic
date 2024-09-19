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
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or °_.
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

#ifdef __c64reu__

#include "../ugbc.h"

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

void c64reu_xpen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $D013");    
    outline0("ASL" );
    outline1("STA %s", _destination);
    outline1("BCC %s", label );
    outline0("LDA #1");    
    outline1("STA _%s", address_displacement(_environment, _destination, "1"));
    outhead1("%s:", label );

}

void c64reu_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $d014");
    outline1("STA %s", _destination);    
    outline0("LDA #0");
    outline1("STA %s", address_displacement(_environment, _destination, "1"));    
   
}

void c64reu_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    _environment->sysCallUsed = 1;

    deploy( dload, src_hw_c64reu_dload_asm);

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
        outline0("LDA #0");
        outline0("STA MATHPTR1");

    }

    outline0("JSR C64REUDLOAD");

}

void c64reu_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    _environment->sysCallUsed = 1;

    deploy( dsave, src_hw_c64reu_dsave_asm);

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
        outline0("LDA #0");
        outline0("STA MATHPTR1");

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

    outline0("JSR C64REUDSAVE");

}

void c64reu_sys_call( Environment * _environment, int _destination ) {

    _environment->sysCallUsed = 1;

    outline0("PHA");
    outline1("LDA #$%2.2x", (_destination & 0xff ) );
    outline0("STA SYSCALL0+1");
    outline1("LDA #$%2.2x", ((_destination>>8) & 0xff ) );
    outline0("STA SYSCALL0+2");
    outline0("PLA");
    outline0("JSR SYSCALL");

}

void c64reu_timer_set_status_on( Environment * _environment, char * _timer ) {
    
    deploy( timer, src_hw_6502_timer_asm);

    if ( _timer ) {
        outline1("LDX %s", _timer );
    } else {
        outline0("LDX #0" );
    }
    outline0("LDY #$1" );
    outline0("JSR TIMERSETSTATUS" );

}

void c64reu_timer_set_status_off( Environment * _environment, char * _timer ) {

    deploy( timer, src_hw_6502_timer_asm);

    if ( _timer ) {
        outline1("LDX %s", _timer );
    } else {
        outline0("LDX #0" );
    }
    outline0("LDY #$0" );
    outline0("JSR TIMERSETSTATUS" );

}

void c64reu_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

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

void c64reu_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

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

void c64reu_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

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

void c64reu_dojo_ready( Environment * _environment, char * _value ) {

    deploy( dojo, src_hw_c64reu_dojo_asm);

    outline0("JSR DOJOISREADY" );
    cpu_ztoa(_environment);
    outline1("STA %s", _value );

}

void c64reu_dojo_read_byte( Environment * _environment, char * _value ) {

    deploy( dojo, src_hw_c64reu_dojo_asm);

    outline0("JSR DOJOREADBYTE" );
    outline1("STA %s", _value );

}

void c64reu_dojo_write_byte( Environment * _environment, char * _value ) {

    deploy( dojo, src_hw_c64reu_dojo_asm);

    outline1("LDA %s", _value );
    outline0("JSR DOJOWRITEBYTE" );

}

void c64reu_dojo_login( Environment * _environment, char * _username, char * _size, char * _password, char * _password_size, char * _session_id ) {

    deploy( dojo, src_hw_c64reu_dojo_asm);

    outline1("LDA #<%s", _session_id );
    outline0("STA DOJOCURRENTKAPTR" );
    outline1("LDA #>%s", _session_id );
    outline0("STA DOJOCURRENTKAPTR+1" );
    outline1("LDA %s", _username );
    outline0("STA TMPPTR" );
    outline1("LDA %s", address_displacement( _environment, _username, "1" ) );
    outline0("STA TMPPTR+1" );
    outline1("LDX %s", _size );
    outline1("LDA %s", _password );
    outline0("STA TMPPTR2" );
    outline1("LDA %s", address_displacement( _environment, _password, "1" ) );
    outline0("STA TMPPTR2+1" );
    outline1("LDY %s", _password_size );
    outline0("JSR DOJOLOGIN" );

}

void c64reu_dojo_success( Environment * _environment, char * _id, char * _result ) {

    deploy( dojo, src_hw_c64reu_dojo_asm);

    outline1("LDA #<%s", _id );
    outline0("STA TMPPTR" );
    outline1("LDA #>%s", _id );
    outline0("STA TMPPTR+1" );
    outline0("JSR DOJOSUCCESS" );
    cpu_ctoa( _environment );
    outline1("STA %s", _result );

}

void c64reu_dojo_create_port( Environment * _environment, char * _session_id, char * _application, char * _size, char * _port_id ) {

    deploy( dojo, src_hw_c64reu_dojo_asm);

    outline1("LDA #<%s", _port_id );
    outline0("STA DOJOCURRENTKAPTR" );
    outline1("LDA #>%s", _port_id );
    outline0("STA DOJOCURRENTKAPTR+1" );
    outline1("LDA %s", _application );
    outline0("STA TMPPTR" );
    outline1("LDA %s", address_displacement( _environment, _application, "1" ) );
    outline0("STA TMPPTR+1" );
    outline1("LDX %s", _size );
    outline1("LDA #<%s", _session_id );
    outline0("STA TMPPTR2" );
    outline1("LDA #>%s", _session_id );
    outline0("STA TMPPTR2+1" );
    outline0("JSR DOJOCREATEPORT" );

}

void c64reu_dojo_destroy_port( Environment * _environment, char * _port_id, char * _result ) {

    deploy( dojo, src_hw_c64reu_dojo_asm);

    outline1("LDA #<%s", _port_id );
    outline0("STA TMPPTR" );
    outline1("LDA #>%s", _port_id );
    outline0("STA TMPPTR+1" );
    outline0("JSR DOJODESTROYPORT" );
    cpu_ctoa( _environment );
    outline1("STA %s", _result );

}

void c64reu_dojo_find_port( Environment * _environment, char * _session_id, char * _username, char * _size, char * _application, char * _application_size, char * _public_id ) {

    deploy( dojo, src_hw_c64reu_dojo_asm);

    outline1("LDA #<%s", _session_id );
    outline0("STA DOJOCURRENTKAPTR" );
    outline1("LDA #>%s", _session_id );
    outline0("STA DOJOCURRENTKAPTR+1" );
    outline1("LDA #<%s", _public_id );
    outline0("STA DOJOCURRENTKAPTR2" );
    outline1("LDA #>%s", _public_id );
    outline0("STA DOJOCURRENTKAPTR2+1" );
    outline1("LDA %s", _username );
    outline0("STA TMPPTR" );
    outline1("LDA %s", address_displacement( _environment, _username, "1" ) );
    outline0("STA TMPPTR+1" );
    outline1("LDX %s", _size );

    outline1("LDA %s", _application );
    outline0("STA TMPPTR2" );
    outline1("LDA %s", address_displacement( _environment, _application, "1" ) );
    outline0("STA TMPPTR2+1" );
    outline1("LDY %s", _application_size );
    outline0("JSR DOJOFINDPORT" );

}

void c64reu_dojo_put_message( Environment * _environment, char * _port_id, char * _message, char * _size, char * _result ) {

    deploy( dojo, src_hw_c64reu_dojo_asm);

    outline1("LDA %s", _message );
    outline0("STA TMPPTR" );
    outline1("LDA %s", address_displacement( _environment, _message, "1" ) );
    outline0("STA TMPPTR+1" );
    outline1("LDX %s", _size );

    outline1("LDA #<%s", _port_id );
    outline0("STA TMPPTR2" );
    outline1("LDA #>%s", _port_id );
    outline0("STA TMPPTR2+1" );
    outline0("JSR DOJOPUTMESSAGE" );
    cpu_ctoa( _environment );
    outline1("STA %s", _result );

}

void c64reu_dojo_peek_message( Environment * _environment, char * _port_id, char * _result ) {

    deploy( dojo, src_hw_c64reu_dojo_asm);

    outline1("LDA #<%s", _port_id );
    outline0("STA TMPPTR" );
    outline1("LDA #>%s", _port_id );
    outline0("STA TMPPTR+1" );
    outline0("JSR DOJOPEEKMESSAGE" );
    cpu_ctoa( _environment );
    outline1("STA %s", _result );

}

void c64reu_dojo_get_message( Environment * _environment, char * _port_id, char * _result, char * _message ) {

    deploy( dojo, src_hw_c64reu_dojo_asm);

    outline1("LDA #<%s", _port_id );
    outline0("STA TMPPTR2" );
    outline1("LDA #>%s", _port_id );
    outline0("STA TMPPTR2+1" );
    outline0("JSR DOJOGETMESSAGE" );
    cpu_ctoa( _environment );
    outline1("STA %s", _result );
    outline1("STX %s", _message );

}

void c64reu_dojo_ping( Environment * _environment, char * _result ) {

    deploy( dojo, src_hw_c64reu_dojo_asm);

    outline0("JSR DOJOPING" );
    cpu_ctoa( _environment );
    outline1("STA %s", _result );

}

#endif