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

static RGBi SYSTEM_PALETTE[] = {
        { 0x00, 0x00, 0x00, 0xff, 0, "BLACK" },        
        { 0x00, 0x00, 0xff, 0xff, 1, "BLUE" },
        { 0x88, 0x00, 0x00, 0xff, 2, "RED" },
        { 0xff, 0x00, 0xff, 0xff, 3, "MAGENTA" },
        { 0x00, 0xcc, 0x00, 0xff, 4, "GREEN" },
        { 0xaa, 0xff, 0xe6, 0xff, 5, "CYAN" },
        { 0xee, 0xee, 0x77, 0xff, 6, "YELLOW" },
        { 0xff, 0xff, 0xff, 0xff, 7, "WHITE" }
};

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __pc1403__

static int rgbConverterFunction( int _red, int _green, int _blue ) {
    
    int value = ( ( ( _blue >> 4 ) & 0x0f ) << 8 ) |
            ( ( ( _green >> 4 ) & 0x0f ) << 4 ) |
            ( ( ( _red >> 4 ) & 0x0f ) );

    return value;

}

static void rgbConverterFunctionInverse( int _value, unsigned char* _red, unsigned char* _green, unsigned char* _blue ) {
    
    *_red = (unsigned char)( _value & 0xf ) << 4;
    *_green = (unsigned char)( _value & 0xf0 );
    *_blue = (unsigned char)( _value & 0xf00 ) >> 4;

}

void pc1403_joy( Environment * _environment, int _port, char * _value ) {

    // deploy( joystick, src_hw_pc1403_joystick_asm );

    switch ( _port ) {
        case 0:
            if ( _environment->joystickConfig.sync ) {
                // outline0("CALL JOYSTICKREAD0" );
            } else {
                // outline0("LD A, (JOYSTICK0)" );
            }
            if ( _environment->joystickConfig.values ) {
                // outline0("CALL JOYSTICKTSB" );
            }
            // outline1("LD (%s), A", _value);
            break;
        case 1:
            if ( _environment->joystickConfig.sync ) {
                // outline0("CALL JOYSTICKREAD1" );
            } else {
                // outline0("LD A, (JOYSTICK1)" );
            }
            if ( _environment->joystickConfig.values ) {
                // outline0("CALL JOYSTICKTSB" );
            }
            // outline1("LD (%s), A", _value);
            break;
    }

}

void pc1403_joy_vars( Environment * _environment, char * _port, char * _value ) {

    // deploy( joystick, src_hw_pc1403_joystick_asm );

    MAKE_LABEL

    // outline1("LD A, (%s)", _port);
    // outline0("CP 0");
    // outline1("JR NZ, %spt1", label );
    if ( _environment->joystickConfig.sync ) {
        // outline0("CALL JOYSTICKREAD0" );
    } else {
        // outline0("LD A, (JOYSTICK0)" );
    }
    if ( _environment->joystickConfig.values ) {
        // outline0("CALL JOYSTICKTSB" );
    }
    // outline1("LD (%s), A", _value);
    // outline1("JR %sptx", label );
    // outhead1("%spt1:", label);
    if ( _environment->joystickConfig.sync ) {
        // outline0("CALL JOYSTICKREAD1" );
    } else {
        // outline0("LD A, (JOYSTICK1)" );
    }
    if ( _environment->joystickConfig.values ) {
        // outline0("CALL JOYSTICKTSB" );
    }
    // outline1("LD (%s), A", _value);
    // outline1("JR %sptx", label );
    // outhead1("%sptx:", label);

}

void pc1403_inkey( Environment * _environment, char * _key ) {

    _environment->bitmaskNeeded = 1;

    // deploy( keyboard, src_hw_pc1403_keyboard_asm);

    // outline0("CALL INKEY");
    // outline1("LD (%s), A", _key);

}

void pc1403_wait_key( Environment * _environment, int _release ) {

    _environment->bitmaskNeeded = 1;

    // deploy( keyboard, src_hw_pc1403_keyboard_asm );

    if ( _release ) {
        // outline0("CALL WAITKEYRELEASE");
    } else {
        // outline0("CALL WAITKEY");
    }
   
}

void pc1403_wait_key_or_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    // deploy( joystick, src_hw_pc1403_joystick_asm );
    // deploy( keyboard, src_hw_pc1403_keyboard_asm );
    // deploy( wait_key_or_fire, src_hw_pc1403_wait_key_or_fire_asm );

    if ( _port == -1 ) {
        // outline0("CALL WAITKEYFIRE");
    } else {
        // outline1("LD A, %2.2x", _port );
        // outline0("CALL WAITKEYFIREA");
    }
   
}

void pc1403_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    // deploy( joystick, src_hw_pc1403_joystick_asm );
    // deploy( keyboard, src_hw_pc1403_keyboard_asm );
    // deploy( wait_key_or_fire, src_hw_pc1403_wait_key_or_fire_asm );

    if ( !_port ) {
        // outline0("CALL WAITKEYFIRE");
    } else {
        // outline1("LD A, (%s)", _port );
        // outline0("CALL WAITKEYFIREA");
    }
   
}

void pc1403_wait_fire( Environment * _environment, int _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    // deploy( joystick, src_hw_pc1403_joystick_asm );

    if ( _port == -1 ) {
        // outline0("CALL WAITFIRE");
    } else {
        // outline1("LD A, $%2.2x", _port );
        // outline0("CALL WAITKEYFIREA");
    }
   
}

void pc1403_wait_fire_semivar( Environment * _environment, char * _port, int _release ) {

    _environment->bitmaskNeeded = 1;

    // deploy( joystick, src_hw_pc1403_joystick_asm );

    if ( ! _port ) {
        // outline0("CALL WAITFIRE");
    } else {
        // outline1("LD A, (%s)", _port );
        // outline0("CALL WAITKEYFIREA");
    }
   
}

void pc1403_key_state( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    // deploy( keyboard, src_hw_pc1403_keyboard_asm );

    // outline1("LD A, (%s)", _scancode);
    // outline0("CALL KEYSTATE");
    cpu_ctoa( _environment );
    // outline1("LD (%s), A", _result);

}

void pc1403_scancode( Environment * _environment, char * _result ) {

    _environment->bitmaskNeeded = 1;

    // deploy( keyboard, src_hw_pc1403_keyboard_asm);

    // outline0("CALL SCANCODE");
    // outline1("LD (%s), A", _result );
   
}

void pc1403_asciicode( Environment * _environment, char * _result ) {

    // deploy( keyboard, src_hw_pc1403_keyboard_asm);

    // outline0("CALL ASCIICODE");
    // outline1("LD A, (%s)", _result );
   
}

void pc1403_key_pressed( Environment * _environment, char *_scancode, char * _result ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    // deploy( keyboard, src_hw_pc1403_keyboard_asm );

    // outline1("LD A, (%s)", _scancode);
    // outline0("CALL KEYPRESSED");
    cpu_ctoa( _environment );
    // outline1("LD (%s), A", _result);

}


void pc1403_scanshift( Environment * _environment, char * _shifts ) {

    pc1403_keyshift( _environment, _shifts );


}

void pc1403_keyshift( Environment * _environment, char * _shifts ) {

    _environment->bitmaskNeeded = 1;

    // deploy( keyboard, src_hw_pc1403_keyboard_asm );

    // outline0("CALL KEYSHIFT" );
    // outline1("LD (%s), A", _shifts );

}

void pc1403_clear_key( Environment * _environment ) {

    _environment->bitmaskNeeded = 1;

    // deploy( keyboard, src_hw_pc1403_keyboard_asm );

    // outline0("CALL CLEARKEY" );

}


void pc1403_irq_at( Environment * _environment, char * _label ) {

    // Variable * irq = variable_retrieve_or_define( _environment, "irq", VT_ADDRESS, 0 );

    // outline0("DI" );
    // outline0("LD A, $c3" );
    // outline0("LD ($FD9F), A" );
    // outline1("LD HL, %s", _label );
    // outline0("LD ($FDA0), HL" );
    // outline0("EI" );
    
}

void pc1403_follow_irq( Environment * _environment ) {

    // Variable * irq = variable_retrieve_or_define( _environment, "irq", VT_ADDRESS, 0 );

    // // outline1("LD HL, (%s)", irq->realName );
    // // outline0("JP (HL)" );
    
    // outline0("RET" );

}

void pc1403_sys_call( Environment * _environment, int _destination ) {

    outline1("CALL 0x%4.4x", _destination );

}

void pc1403_timer_set_status_on( Environment * _environment, char * _timer ) {
    
    // deploy( timer, src_hw_z80_timer_asm);

    if ( _timer ) {
        // outline1("LD A, (%s)", _timer );
        // outline0("LD A, B" );
    } else {
        // outline0("LD B, 0" );
    }
    // outline0("LD A, 1" );
    // outline0("LD C, A" );
    // outline0("CALL TIMERSETSTATUS" );

}

void pc1403_timer_set_status_off( Environment * _environment, char * _timer ) {

    // deploy( timer, src_hw_z80_timer_asm);

    if ( _timer ) {
        // outline1("LD A, (%s)", _timer );
        // outline0("LD A, B" );
    } else {
        // outline0("LD B, 0" );
    }
    // outline0("LD A, 0" );
    // outline0("LD C, A" );
    // outline0("CALL TIMERSETSTATUS" );


}

void pc1403_timer_set_counter( Environment * _environment, char * _timer, char * _counter ) {

    // deploy( timer, src_hw_z80_timer_asm);

    if ( _counter ) {
        // outline1("LD A, (%s)", _counter );
        // outline0("LD IXL, A" );
        // outline1("LD A, (%s)", address_displacement( _environment, _counter, "1" ) );
        // outline0("LD IXH, A" );
    } else {
        // outline0("LD IX, 0" );
    }
    if ( _timer ) {
        // outline1("LD A, (%s)", _timer );
        // outline0("LD B, A" );
    } else {
        // outline0("LD B, 0" );
    }
    // outline0("CALL TIMERSETCOUNTER" );

}

void pc1403_timer_set_init( Environment * _environment, char * _timer, char * _init ) {

    // deploy( timer, src_hw_z80_timer_asm);

    if ( _init ) {
        // outline1("LD A, (%s)", _init );
        // outline0("LD IXL, A" );
        // outline1("LD A, (%s)", address_displacement( _environment, _init, "1" ) );
        // outline0("LD IXH, A" );
    } else {
        // outline0("LD IX, 0" );
    }
    if ( _timer ) {
        // outline1("LD A, (%s)", _timer );
        // outline0("LD B, A" );
    } else {
        // outline0("LD B, 0" );
    }
    // outline0("CALL TIMERSETINIT" );

}

void pc1403_timer_set_address( Environment * _environment, char * _timer, char * _address ) {

    // deploy( timer, src_hw_z80_timer_asm);

    if ( _address ) {
        // outline1("LD HL, %s", _address );
        // outline0("LD A, L" );
        // outline0("LD IXL, A" );
        // outline0("LD A, H" );
        // outline0("LD IXH, A" );
    } else {
        // outline0("LD IX, 0" );
    }
    if ( _timer ) {
        // outline1("LD A, (%s)", _timer );
        // outline0("LD B, A" );
    } else {
        // outline0("LD B, 0" );
    }
    // outline0("CALL TIMERSETADDRESS" );

}

void pc1403_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    // deploy( dcommon, src_hw_pc1403_dcommon_asm );
    // deploy( dload, src_hw_pc1403_dload_asm );

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

    // outline1("LD HL, (%s)", tnaddress->realName);
    // outline1("LD A, (%s)", tnsize->realName);
    // outline0("LD B, A");

    if ( address ) {

        // outline1("LD DE, (%s)", address->realName);

    }

    // outline0("CALL PC1403DLOAD");

}

void pc1403_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size ) {

    // deploy( dcommon, src_hw_pc1403_dcommon_asm );
    // deploy( dsave, src_hw_pc1403_dsave_asm );

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

    // outline1("LD HL, (%s)", tnaddress->realName);
    // outline1("LD A, (%s)", tnsize->realName);
    // outline0("LD B, A");

    if ( address ) {

        // outline1("LD DE, (%s)", address->realName);

    }

    if ( size ) {

        // outline1("LD IX, (%s)", size->realName);

    }

    // outline0("CALL PC1403DSAVE");

}


void pc1403_put_key(  Environment * _environment, char *_string, char * _size ) {

    _environment->bitmaskNeeded = 1;

    // deploy( keyboard, src_hw_pc1403_keyboard_asm);

    // outline1("LD HL, (%s)", _string );
    // outline1("LD A, (%s)", _size );
    // outline0("LD C, A" );
    // outline0("CALL PUTKEY" );

}

void pc1403_dojo_ready( Environment * _environment, char * _value ) {

}

void pc1403_dojo_read_byte( Environment * _environment, char * _value ) {

}

void pc1403_dojo_write_byte( Environment * _environment, char * _value ) {

}

void pc1403_dojo_login( Environment * _environment, char * _username, char * _size, char * _password, char * _password_size, char * _session_id ) {

}

void pc1403_dojo_success( Environment * _environment, char * _id, char * _result ) {

}

void pc1403_dojo_create_port( Environment * _environment, char * _session_id, char * _application, char * _size, char * _port_id ) {

}

void pc1403_dojo_destroy_port( Environment * _environment, char * _port_id, char * _result ) {

}

void pc1403_dojo_find_port( Environment * _environment, char * _session_id, char * _username, char * _size, char * _application, char * _application_size, char * _public_id ) {

}

void pc1403_dojo_put_message( Environment * _environment, char * _port_id, char * _message, char * _size, char * _result ) {

}

void pc1403_dojo_peek_message( Environment * _environment, char * _port_id, char * _result ) {

}

void pc1403_dojo_get_message( Environment * _environment, char * _port_id, char * _result, char * _message ) {

}

void pc1403_dojo_ping( Environment * _environment, char * _result ) {

}


void console_calculate( Environment * _environment ) {

    int consoleSA = 0x0c00;
    int consoleWB = _environment->activeConsole.width;
    int consoleHB = _environment->activeConsole.height * 8;

    cpu_store_16bit( _environment, "CONSOLESA", consoleSA );
    cpu_store_8bit( _environment, "CONSOLEWB", consoleWB );
    cpu_store_8bit( _environment, "CONSOLEHB", consoleHB );

}

void console_calculate_vars( Environment * _environment ) {

    // outline0( "JSR CONSOLECALCULATE" );

}

void pc1403_initialization( Environment * _environment ) {

    // deploy( tms9918vars, src_hw_tms9918_vars_asm );
    // deploy( tms9918startup, src_hw_tms9918_startup_asm );

    // variable_import( _environment, "CURRENTWIDTH", VT_POSITION, 256 );
    // variable_global( _environment, "CURRENTWIDTH" );
    // variable_import( _environment, "CURRENTHEIGHT", VT_POSITION, 192  );
    // variable_global( _environment, "CURRENTHEIGHT" );
    // variable_import( _environment, "CURRENTTILES", VT_BYTE, 255 );
    // variable_global( _environment, "CURRENTTILES" );
    // variable_import( _environment, "CURRENTTILESWIDTH", VT_SBYTE, 40 );
    // variable_global( _environment, "CURRENTTILESWIDTH" );
    // variable_import( _environment, "CURRENTTILESWIDTHX8", VT_WORD, 320 );
    // variable_global( _environment, "CURRENTTILESWIDTHX8" );
    // variable_import( _environment, "CURRENTTILESHEIGHT", VT_SBYTE, 24 );
    // variable_global( _environment, "CURRENTTILESHEIGHT" );
    // variable_import( _environment, "FONTWIDTH", VT_BYTE, 8 );
    // variable_global( _environment, "FONTWIDTH" );
    // variable_import( _environment, "FONTHEIGHT", VT_BYTE, 8 );
    // variable_global( _environment, "FONTHEIGHT" );
    // variable_import( _environment, "SPRITEADDRESS", VT_ADDRESS, 0x0000 );
    // variable_global( _environment, "SPRITEADDRESS" );    
    // variable_import( _environment, "SPRITEAADDRESS", VT_ADDRESS, 0x1000 );
    // variable_global( _environment, "SPRITEAADDRESS" );    
    // variable_import( _environment, "TEXTADDRESS", VT_ADDRESS, 0x1800 );
    // variable_global( _environment, "TEXTADDRESS" );    
    // variable_import( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0x3800 );
    // variable_global( _environment, "COLORMAPADDRESS" );    
    // variable_import( _environment, "PATTERNADDRESS", VT_ADDRESS, 0x0000 );
    // variable_global( _environment, "PATTERNADDRESS" );    
    // variable_import( _environment, "PALETTE", VT_BUFFER, 16 );
    // variable_global( _environment, "PALETTE" ); 

    // char defaultPalette[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    // variable_store_buffer( _environment, "PALETTE", &defaultPalette[0], 16, 0 );

    // SCREEN_MODE_DEFINE( TILEMAP_MODE_STANDARD, 0, 40, 24, 20, 6, 8, "Text Mode" );
    // SCREEN_MODE_DEFINE( BITMAP_MODE_GRAPHIC2, 0, 32, 24, 16, 8, 8, "Graphic II" );
    // SCREEN_MODE_DEFINE( TILEMAP_MODE_GRAPHIC1, 0, 32, 24, 16, 8, 8, "Graphic I" );

    // SCREEN_MODE_DEFINE( BITMAP_MODE_GRAPHIC2, 1, 256, 192, 16, 8, 8, "Graphic II" );
    // SCREEN_MODE_DEFINE( BITMAP_MODE_MULTICOLOR, 1, 256, 192, 16, 8, 8, "Multicolor" );
 
    // outline0("CALL TMS9918STARTUP");

    // variable_import( _environment, "XGR", VT_POSITION, 0 );
    // variable_global( _environment, "XGR" );
    // variable_import( _environment, "YGR", VT_POSITION, 0 );
    // variable_global( _environment, "YGR" );
    // variable_import( _environment, "LINE", VT_WORD, (unsigned short)(0xffff) );
    // variable_global( _environment, "LINE" );

    // variable_import( _environment, "CLIPX1", VT_POSITION, 0 );
    // variable_global( _environment, "CLIPX1" );
    // variable_import( _environment, "CLIPX2", VT_POSITION, 255 );
    // variable_global( _environment, "CLIPX2" );
    // variable_import( _environment, "CLIPY1", VT_POSITION, 0 );
    // variable_global( _environment, "CLIPY1" );
    // variable_import( _environment, "CLIPY2", VT_POSITION, 191 );
    // variable_global( _environment, "CLIPY2" );

    // variable_import( _environment, "ORIGINX", VT_POSITION, 0 );
    // variable_global( _environment, "ORIGINX" );
    // variable_import( _environment, "ORIGINY", VT_POSITION, 0 );
    // variable_global( _environment, "ORIGINY" );

    // variable_import( _environment, "RESOLUTIONX", VT_POSITION, 0 );
    // variable_global( _environment, "RESOLUTIONX" );
    // variable_import( _environment, "RESOLUTIONY", VT_POSITION, 0 );
    // variable_global( _environment, "RESOLUTIONY" );
    
    // variable_import( _environment, "TABCOUNT", VT_BYTE, 4 );
    // variable_global( _environment, "TABCOUNT" );

    // variable_import( _environment, "CLINEX", VT_BYTE, 0 );
    // variable_global( _environment, "CLINEX" );

    // variable_import( _environment, "CLINEY", VT_BYTE, 0 );
    // variable_global( _environment, "CLINEY" );

    // variable_import( _environment, "PLOTCPE", VT_BYTE, 0 );
    // variable_global( _environment, "PLOTCPE" );

    // variable_import( _environment, "TABSTODRAW", VT_BYTE, 0 );
    // variable_global( _environment, "TABSTODRAW" );

    // variable_import( _environment, "CURRENTMODE", VT_BYTE, 0 );
    // variable_global( _environment, "CURRENTMODE" );
    // variable_import( _environment, "CURRENTTILEMODE", VT_BYTE, 1 );
    // variable_global( _environment, "CURRENTTILEMODE" );

    // variable_import( _environment, "SPRITECOUNT", VT_SPRITE, 0 );
    // variable_global( _environment, "SPRITECOUNT" );

    // variable_import( _environment, "SPRITEXY", VT_BUFFER, SPRITE_COUNT * 2 );
    // variable_global( _environment, "SPRITEXY" );

    // variable_import( _environment, "TILEX", VT_BYTE, 0 );
    // variable_global( _environment, "TILEX" );
    // variable_import( _environment, "TILEY", VT_BYTE, 0 );
    // variable_global( _environment, "TILEY" );
    // variable_import( _environment, "TILEX2", VT_BYTE, 0 );
    // variable_global( _environment, "TILEX2" );
    // variable_import( _environment, "TILET", VT_BYTE, 0 );
    // variable_global( _environment, "TILET" );
    // variable_import( _environment, "TILEW", VT_BYTE, 0 );
    // variable_global( _environment, "TILEW" );
    // variable_import( _environment, "TILEH", VT_BYTE, 0 );
    // variable_global( _environment, "TILEH" );
    // variable_import( _environment, "TILEW2", VT_BYTE, 0 );
    // variable_global( _environment, "TILEW2" );
    // variable_import( _environment, "TILEH2", VT_BYTE, 0 );
    // variable_global( _environment, "TILEH2" );
    // variable_import( _environment, "TILEA", VT_BYTE, 0 );
    // variable_global( _environment, "TILEA" );
    // variable_import( _environment, "TILEO", VT_WORD, 0 );
    // variable_global( _environment, "TILEO" );

    // variable_import( _environment, "XSCROLLPOS", VT_BYTE, 0 );
    // variable_global( _environment, "XSCROLLPOS" );
    // variable_import( _environment, "YSCROLLPOS", VT_BYTE, 0 );
    // variable_global( _environment, "YSCROLLPOS" );
    // variable_import( _environment, "XSCROLL", VT_BYTE, 0 );
    // variable_global( _environment, "XSCROLL" );
    // variable_import( _environment, "YSCROLL", VT_BYTE, 0 );
    // variable_global( _environment, "YSCROLL" );
    // variable_import( _environment, "DIRECTION", VT_BYTE, 0 );
    // variable_global( _environment, "DIRECTION" );

    // variable_import( _environment, "ONSCROLLUP", VT_BUFFER, 3 );
    // variable_global( _environment, "ONSCROLLUP" );

    // variable_import( _environment, "ONSCROLLDOWN", VT_BUFFER, 3 );
    // variable_global( _environment, "ONSCROLLDOWN" );

    // variable_import( _environment, "ONSCROLLLEFT", VT_BUFFER, 3 );
    // variable_global( _environment, "ONSCROLLLEFT" );

    // variable_import( _environment, "ONSCROLLRIGHT", VT_BUFFER, 3 );
    // variable_global( _environment, "ONSCROLLRIGHT" );

    // variable_import( _environment, "IMAGEF", VT_BYTE, 0 );
    // variable_global( _environment, "IMAGEF" );

    // variable_import( _environment, "IMAGET", VT_BYTE, 0 );
    // variable_global( _environment, "IMAGET" );

    // variable_import( _environment, "IMAGEY", VT_BYTE, 0 );
    // variable_global( _environment, "IMAGEY" );

    // variable_import( _environment, "BLITIMAGEBLITTINGADDR", VT_ADDRESS, 0 );
    // variable_global( _environment, "BLITIMAGEBLITTINGADDR" );
    // variable_import( _environment, "BLITTMPPTR", VT_ADDRESS, 0 );
    // variable_global( _environment, "BLITTMPPTR" );
    // variable_import( _environment, "BLITTMPPTR2", VT_ADDRESS, 0 );
    // variable_global( _environment, "BLITTMPPTR2" );

    // #if __coleco__
    //     variable_import( _environment, "VDP_HOOK", VT_BUFFER, 10 );
    //     variable_global( _environment, "VDP_HOOK" );
    // #endif

    // variable_import( _environment, "VBLFLAG", VT_BYTE, 0 );
    // variable_global( _environment, "VBLFLAG" ); 
    // variable_import( _environment, "VDPINUSE", VT_BYTE, 0 );
    // variable_global( _environment, "VDPINUSE" );

    // variable_import( _environment, "SLICEX", VT_POSITION, 0 );
    // variable_global( _environment, "SLICEX" );
    // variable_import( _environment, "SLICEY", VT_POSITION, 0 );
    // variable_global( _environment, "SLICEY" );
    // variable_import( _environment, "SLICEDTARGET", VT_POSITION, 0 );
    // variable_global( _environment, "SLICEDTARGET" );

    // variable_import( _environment, "CONSOLESA", VT_ADDRESS, 0x0 );
    // variable_global( _environment, "CONSOLESA" );
    // variable_import( _environment, "CONSOLEHB", VT_BYTE, 0x0 );
    // variable_global( _environment, "CONSOLEHB" );
    // variable_import( _environment, "CONSOLEWB", VT_BYTE, 0x0 );
    // variable_global( _environment, "CONSOLEWB" );

    // tms9918_tilemap_enable( _environment, 40, 24, 1, 8, 8 );

    font_descriptors_init( _environment, 0 );
    
    _environment->currentRgbConverterFunction = rgbConverterFunction;
    _environment->screenShades = 16;

}

#endif