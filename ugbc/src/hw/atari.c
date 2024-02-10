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

void atari_inkey( Environment * _environment, char * _pressed, char * _key ) {

    MAKE_LABEL

    deploy( scancode, src_hw_atari_scancode_asm);

    outline0("JSR INKEY");

    outline1("STX %s", _pressed );
    outline1("STA %s", _key );

}

void atari_scancode( Environment * _environment, char * _pressed, char * _scancode ) {

    MAKE_LABEL

    deploy( scancode, src_hw_atari_scancode_asm);

    outline0("JSR SCANCODE");

    outline1("STX %s", _pressed );
    outline1("STY %s", _scancode );

}

void atari_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    deploy( scancode, src_hw_atari_scancode_asm);

    MAKE_LABEL

    Variable * temp = variable_temporary( _environment, VT_BYTE, "(pressed)" );

    outline0("JSR SCANCODEWITHDELAY");

    outline1("STY %s", temp->realName );    

    char nokeyLabel[MAX_TEMPORARY_STORAGE];
    sprintf( nokeyLabel, "%slabel", label );
    
    cpu_compare_8bit( _environment, temp->realName, _scancode,  temp->realName, 1 );
    cpu_compare_and_branch_8bit_const( _environment, temp->realName, 0, nokeyLabel, 1 );
    cpu_store_8bit( _environment, _result, 0xff );
    cpu_jump( _environment, label );
    cpu_label( _environment, nokeyLabel );
    cpu_store_8bit( _environment, _result, 0x00 );
    cpu_label( _environment, label );

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


    MAKE_LABEL

    outline0("LDA #0" );
    outline1("STA %s", _shifts );

    outline0("LDA $02F2" );
    outline0("AND #$40");
    outline1("BNE %snoshifts", label );

    outline0("LDA #3" );
    outline1("STA %s", _shifts );
   
    outhead1("%snoshifts:", label );

    outline0("LDA $02BE" );
    outline0("AND #$40");
    outline1("BEQ %snocaps", label );

    outline1("LDA %s", _shifts);
    outline0("ORA #4");
    outline1("STA %s", _shifts);

    outhead1("%snocaps:", label );

    outline0("LDA $02BE" );
    outline0("AND #$80");
    outline1("BEQ %snoctrl", label );

    outline1("LDA %s", _shifts);
    outline0("ORA #8");
    outline1("STA %s", _shifts);

    outhead1("%snoctrl:", label );

}

void atari_clear_key( Environment * _environment ) {

    outline0("LDA #$FF");
    outline0("STA $02F2");
   
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

#endif