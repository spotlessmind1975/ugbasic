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

#ifdef __vic20__

#include "../ugbc.h"

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

void vic20_xpen( Environment * _environment, char * _destination ) {

    // MAKE_LABEL

    // outline0("LDA $D013");    
    // outline0("ASL" );
    // outline1("STA %s", _destination);
    // outline1("BCC %s", label );
    // outline0("LDA #1");    
    // outline1("STA _%s", address_displacement(_environment, _destination, "1"));
    // outhead1("%s:", label );

}

void vic20_ypen( Environment * _environment, char * _destination ) {

    // MAKE_LABEL

    // outline0("LDA $d014");
    // outline1("STA %s", _destination);    
    // outline0("LDA #0");
    // outline1("STA %s", address_displacement(_environment, _destination, "1"));    
   
}

void vic20_inkey( Environment * _environment, char * _pressed, char * _key ) {

    MAKE_LABEL

    outline0("LDA #$0");
    outline1("STA %s", _pressed );
    outline0("LDA #$0");
    outline1("STA %s", _key );

    outline0("LDX $c6");
    outline0("CPX #$0");
    outline1("BEQ %snokey", label );

    outline0("LDA $0277" );
    outline0("CMP #$FF");
    outline1("BEQ %snopetscii", label );
    outline1("STA %s", _key );
    outline0("LDA #$FF");
    outline1("STA %s", _pressed );

    outline0("LDX #0");
    outhead1("%sclkeys:", label);
    outline0("LDA $0278,X" );
    outline0("STA $0277,X" );
    outline0("INX");
    outline0("CPX $c6");
    outline1("BNE %sclkeys", label);
    outline0("DEC $c6");

    outline1("JMP %snokey", label );

    outhead1("%snopetscii:", label );
    outline0("LDA #0");
    outline1("STA %s", _key );
    outhead1("%snokey:", label );
   
}

void vic20_wait_key_or_fire( Environment * _environment, int _port, int _release ) {

}

void vic20_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release ) {

}

void vic20_wait_fire( Environment * _environment, int _port, int _release ) {

}

void vic20_wait_fire_semivar( Environment * _environment, char * _port, int _release ) {

}

void vic20_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

    MAKE_LABEL

    outline0("LDA #$0");
    outline1("STA %s", _pressed );
    outline0("LDA #$40");
    outline1("STA %s", _scancode );

    outline0("LDY $c5");
    outline0("CPY #$40");
    outline1("BEQ %snokey", label );

    outline1("STY %s", _scancode );
    outline0("LDA #$ff");
    outline1("STA %s", _pressed );

    outhead1("%snokey:", label );
   
}

void vic20_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    MAKE_LABEL

    char nokeyLabel[MAX_TEMPORARY_STORAGE];
    sprintf( nokeyLabel, "%slabel", label );
    
    Variable * temp = variable_temporary( _environment, VT_BYTE, "(pressed)" );

    vic20_scancode( _environment, temp->realName, _result );
    cpu_compare_8bit( _environment, _result, _scancode,  temp->realName, 1 );
    cpu_compare_and_branch_8bit_const( _environment, temp->realName, 0, nokeyLabel, 1 );
    cpu_store_8bit( _environment, _result, 0xff );
    cpu_jump( _environment, label );
    cpu_label( _environment, nokeyLabel );
    cpu_store_8bit( _environment, _result, 0x00 );
    cpu_label( _environment, label );

}

void vic20_scanshift( Environment * _environment, char * _shifts ) {

    // // 653	
    // // Shift key indicator. Bits:
    // // Bit #0: 1 = One or more of left Shift, right Shift or Shift Lock is currently being pressed or locked.
    // // Bit #1: 1 = Commodore is currently being pressed.
    // // Bit #2: 1 = Control is currently being pressed.
    // // NO SHIFT (0) - if no SHIFT key pressed;
    // // LEFT SHIFT (1) - if the left SHIFT pressed;
    // // RIGHT SHIFT (2) - if the right SHIFT pressed;
    // // BOTH SHIFTS (3) - if both keys pressed.

    // MAKE_LABEL

    // outline0("LDA #0");
    // outline1("STA %s", _shifts);
    // outline0("LDA #$10");
    // outline0("STA $DC00");
    // outline0("LDA $DC01");
    // outline0("AND #$80");
    // outline1("BNE %snoleft", label);
    // outline0("LDA #1");
    // outline1("STA %s", _shifts);
    // outhead1("%snoleft:", label );

    // outline0("LDA #$20");
    // outline0("STA $DC00");
    // outline0("LDA $DC01");
    // outline0("AND #$10");
    // outline1("BNE %snoright", label);
    // outline1("LDA %s", _shifts);
    // outline0("ORA #2");
    // outline1("STA %s", _shifts);
    // outhead1("%snoright:", label );

}

void vic20_keyshift( Environment * _environment, char * _shifts ) {

    // // On the same way, KEY SHIFT is used to report the current status of those keys 
    // // which cannot be detected by either INKEY$ or SCANCODE because they do not 
    // // carry the relevant codes. These control keys cannot be tested individually, or a test can be set up for any combination of such keys pressed together. A single call to the KEY SHIFT function can test for all eventualities, by examining a bit map in the following format:

    // MAKE_LABEL

    // outline0("LDA #0");
    // outline1("STA %s", _shifts);
    // outline0("LDA #$10");
    // outline0("STA $DC00");
    // outline0("LDA $DC01");
    // outline0("AND #$80");
    // outline1("BNE %snoleft", label);
    // outline0("LDA #1");
    // outline1("STA %s", _shifts);
    // outhead1("%snoleft:", label );

    // outline0("LDA #$20");
    // outline0("STA $DC00");
    // outline0("LDA $DC01");
    // outline0("AND #$10");
    // outline1("BNE %snoright", label);
    // outline1("LDA %s", _shifts);
    // outline0("ORA #2");
    // outline1("STA %s", _shifts);
    // outhead1("%snoright:", label );

    // outline0("LDA $028D");
    // outline0("AND #$01");
    // outline1("BEQ %snocaps", label);
    // outline1("LDA %s", _shifts);
    // outline0("ORA #4");
    // outline1("STA %s", _shifts);
    // outhead1("%snocaps:", label );

    // outline0("LDA $028D");
    // outline0("AND #$04");
    // outline1("BEQ %snocontrol", label);
    // outline1("LDA %s", _shifts);
    // outline0("ORA #8");
    // outline1("STA %s", _shifts);
    // outhead1("%snocontrol:", label );

    // outline0("LDA $028D");
    // outline0("AND #$02");
    // outline1("BEQ %snoalt", label);
    // outline1("LDA %s", _shifts);
    // outline0("ORA #$30");
    // outline1("STA %s", _shifts);
    // outhead1("%snoalt:", label );

}

void vic20_clear_key( Environment * _environment ) {

    // outline0("LDA #$0");
    // outline0("STA $c6");
   
}

void vic20_sys_call( Environment * _environment, int _destination ) {

    _environment->sysCallUsed = 1;

    outline0("PHA" );
    outline1("LDA #$%2.2x", (_destination & 0xff ) );
    outline0("STA SYSCALL0+1");
    outline1("LDA #$%2.2x", ((_destination>>8) & 0xff ) );
    outline0("STA SYSCALL0+2");
    outline0("PLA" );
    outline0("JSR SYSCALL");

}

void vic20_timer_set_status_on( Environment * _environment, char * _timer ) {
    
    deploy( timer, src_hw_6502_timer_asm);

    if ( _timer ) {
        outline1("LDX %s", _timer );
    } else {
        outline0("LDX #0" );
    }
    outline0("LDY #$1" );
    outline0("JSR TIMERSETSTATUS" );

}

void vic20_timer_set_status_off( Environment * _environment, char * _timer ) {

    deploy( timer, src_hw_6502_timer_asm);

    if ( _timer ) {
        outline1("LDX %s", _timer );
    } else {
        outline0("LDX #0" );
    }
    outline0("LDY #$0" );
    outline0("JSR TIMERSETSTATUS" );

}

void vic20_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

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

void vic20_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

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

void vic20_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

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

void vic20_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    _environment->sysCallUsed = 1;

    deploy( dload, src_hw_vic20_dload_asm);

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

    outline0("JSR VIC20DLOAD");

}

void vic20_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    _environment->sysCallUsed = 1;

    deploy( dsave, src_hw_vic20_dsave_asm);

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

    outline0("JSR VIC20DSAVE");

}

void vic20_put_key(  Environment * _environment, char *_string, char * _size ) {

    MAKE_LABEL

    _environment->bitmaskNeeded = 1;

    outline1("LDA %s", _string );
    outline0("STA TMPPTR" );
    outline1("LDA %s", address_displacement( _environment, _string, "1" ) );
    outline0("STA TMPPTR+1" );

    outline0("LDY #0");
    outline0("LDX $c6");
    outhead1("%sputkey:", label);
    outline0("LDA (TMPPTR),Y" );
    outline0("STA $0277,X" );
    outline0("INY");
    outline0("INX");
    outline1("CPY %s", _size );
    outline1("BNE %sputkey", label);
    outline0("STX $c6");

}
#endif