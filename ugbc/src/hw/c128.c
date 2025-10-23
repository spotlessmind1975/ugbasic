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

#ifdef __c128__

#include "../ugbc.h"

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

void c128_xpen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $D013");    
    outline0("ASL" );
    outline1("STA %s", _destination);
    outline1("BCC %s", label );
    outline0("LDA #1");    
    outline1("STA _%s", address_displacement(_environment, _destination, "1"));
    outhead1("%s:", label );

}

void c128_ypen( Environment * _environment, char * _destination ) {

    MAKE_LABEL

    outline0("LDA $d014");
    outline1("STA %s", _destination);    
    outline0("LDA #0");
    outline1("STA %s", address_displacement(_environment, _destination, "1"));    
   
}


void c128_sys_call( Environment * _environment, int _destination ) {

    _environment->sysCallUsed = 1;

    deploy_preferred( syscall, src_hw_c128_syscall_asm);

    outline0("PHA");
    outline1("LDA #$%2.2x", (_destination & 0xff ) );
    outline0("STA SYSCALL0+1");
    outline1("LDA #$%2.2x", ((_destination>>8) & 0xff ) );
    outline0("STA SYSCALL0+2");
    outline0("PLA");
    outline0("JSR SYSCALL");

}

void c128_timer_set_status_on( Environment * _environment, char * _timer ) {
    
    deploy( timer, src_hw_6502_timer_asm);

    if ( _timer ) {
        outline1("LDX %s", _timer );
    } else {
        outline0("LDX #0" );
    }
    outline0("LDY #$1" );
    outline0("JSR TIMERSETSTATUS" );

}

void c128_timer_set_status_off( Environment * _environment, char * _timer ) {

    deploy( timer, src_hw_6502_timer_asm);

    if ( _timer ) {
        outline1("LDX %s", _timer );
    } else {
        outline0("LDX #0" );
    }
    outline0("LDY #$0" );
    outline0("JSR TIMERSETSTATUS" );

}

void c128_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

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

void c128_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

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

void c128_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

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

void c128_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    _environment->sysCallUsed = 1;

    deploy_preferred( syscall, src_hw_c128_syscall_asm);
    deploy_preferred( dcommon, src_hw_c128_dcommon_asm);
    deploy_preferred( dload, src_hw_c128_dload_asm);

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
    outline0("STA DCOMMONP1");
    outline1("LDA %s", address_displacement(_environment, tnaddress->realName, "1"));
    outline0("STA DCOMMONP1+1");
    outline1("LDA %s", tnsize->realName);
    outline0("STA DCOMMON0");

    if ( address ) {

        outline1("LDA %s", address->realName);
        outline0("STA DCOMMONP2");
        outline1("LDA %s", address_displacement(_environment, address->realName, "1"));
        outline0("STA DCOMMONP2+1");
        outline0("LDA #0");
        outline0("STA DCOMMON1");

    }

    outline0("JSR C128DLOAD");

}

void c128_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    _environment->sysCallUsed = 1;

    deploy_preferred( syscall, src_hw_c128_syscall_asm);
    deploy_preferred( dcommon, src_hw_c128_dcommon_asm);
    deploy_preferred( dsave, src_hw_c128_dsave_asm);

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
    outline0("STA DCOMMONP1");
    outline1("LDA %s", address_displacement(_environment, tnaddress->realName, "1"));
    outline0("STA DCOMMONP1+1");
    outline1("LDA %s", tnsize->realName);
    outline0("STA DCOMMON0");

    if ( address ) {

        outline1("LDA %s", address->realName);
        outline0("STA DCOMMONP2");
        outline1("LDA %s", address_displacement(_environment, address->realName, "1"));
        outline0("STA DCOMMONP2+1");
        outline0("LDA #0");
        outline0("STA DCOMMON1");

    }

    if ( size ) {

        outline1("LDA %s", size->realName);
        outline0("STA DCOMMON4");
        outline1("LDA %s", address_displacement(_environment, size->realName, "1"));
        outline0("STA DCOMMON5");

    } else {

        outline0("LDA #$ff");
        outline0("STA DCOMMON4");
        outline0("STA DCOMMON5");

    }

    outline0("JSR C128DSAVE");

}

void c128_chain( Environment * _environment, char * _filename ) {

    _environment->sysCallUsed = 1;
    _environment->chainUsed = 1;

    deploy_preferred( syscall, src_hw_c128_syscall_asm);
    deploy_preferred( dcommon, src_hw_c128_dcommon_asm );
    deploy_preferred( dload, src_hw_c128_dload_asm );
    deploy_preferred( chain, src_hw_c128_chain_asm );

    Variable * filename = variable_retrieve( _environment, _filename );
    Variable * tnaddress = variable_temporary( _environment, VT_ADDRESS, "(address of target_name)");
    Variable * tnsize = variable_temporary( _environment, VT_BYTE, "(size of target_name)");

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
    outline0("STA DCOMMONP1");
    outline1("LDA %s", address_displacement(_environment, tnaddress->realName, "1"));
    outline0("STA DCOMMONP1+1");
    outline1("LDA %s", tnsize->realName);
    outline0("STA DCOMMON0");
    outline0("JMP CHAIN");

}

#endif