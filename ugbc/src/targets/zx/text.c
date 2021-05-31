/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
 * "COSÌ COM'È", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit ASM code for <b>TEXTMAP AT [int]xx</b>
 * 
 * This function allows you to set the starting address, in memory, for the 
 * text and it is the version that is used when the memory is given as a
 * direct number (i.e.: $0400). The input parameter is decoded and declined 
 * according to the hardware limits. So it is not said that exactly the 
 * given address is set.
 * 
 * On some machine calling this instruction will define the special variable:
 * 
 *  * `TEXTADDRESS` (VT_ADDRESS) - the starting address of text memory
 * 
 * @param _environment Current calling environment
 * @param _address Address to use
 */
void textmap_at( Environment * _environment, int _address ) {

    outline1("; TEXTMAP AT $%4.4x (ignored)", _address);

}

/**
 * @brief Emit ASM code for <b>TEXTMAP AT [expression]</b>
 * 
 * This function allows you to set the starting address, in memory, for the 
 * text and it is the version that is used when the memory is given as an
 * expression. The input parameter is decoded and declined according to the 
 * hardware limits. So it is not said that exactly the given address is set.
 * 
 * On some machine calling this instruction will define the special variable:
 * 
 *  * `TEXTADDRESS` (VT_ADDRESS) - the starting address of text memory
 * 
 * @param _environment Current calling environment
 * @param _address Expression with address to use
 */
void textmap_at_var( Environment * _environment, char * _address ) {

    outline1("; TEXTMAP AT %s (ignored)", _address);

}

void text_encoded_at( Environment * _environment, char * _x, char * _y, char * _text, char * _pen, char * _paper, char * _ww  ) {

    Variable * text = variable_retrieve( _environment, _text );
    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );
    Variable * pen = variable_retrieve( _environment, _pen );
    Variable * paper = variable_retrieve( _environment, _paper );
    Variable * ww = variable_retrieve( _environment, _ww );

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");

    switch( text->type ) {
        case VT_STRING: {
            cpu_move_8bit( _environment, text->realName, size->realName );
            cpu_addressof_16bit( _environment, text->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            break;
        }
        case VT_DSTRING: {
            cpu_dsdescriptor( _environment, text->realName, address->realName, size->realName );
            break;
        }
    }

    zx_text_at( _environment, x->realName, y->realName, address->realName, size->realName, pen->realName, paper->realName, ww->realName );

}

Variable * text_get_pen( Environment * _environment, char * _color ) {
    
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_WHITE );

    Variable * result = variable_temporary( _environment, VT_DSTRING, 0 );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x1 " );

    variable_store_string(_environment, result->name, resultString );

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );

    cpu_move_8bit_with_offset(_environment, color->realName, address->realName, 1 );
        
    return result;

}

Variable * text_get_paper( Environment * _environment, char * _color ) {
    
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_BLACK );

    Variable * result = variable_temporary( _environment, VT_DSTRING, 0 );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x2 " );

    variable_store_string(_environment, result->name, resultString );

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );

    variable_store_string(_environment, result->name, resultString );

    cpu_move_8bit_with_offset(_environment, color->realName, address->realName, 1 );
        
    return result;

}


Variable * text_get_at( Environment * _environment, char * _x, char * _y ) {
    
    Variable * x = variable_retrieve_or_define( _environment, _x, VT_BYTE, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_BYTE, 0 );

    Variable * result = variable_temporary( _environment, VT_DSTRING, 0 );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x4  " );

    variable_store_string(_environment, result->name, resultString );

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );

    cpu_move_8bit_with_offset(_environment, x->realName, address->realName, 1 );
    cpu_move_8bit_with_offset(_environment, y->realName, address->realName, 2 );
        
    return result;

}

void text_vscroll_screen( Environment * _environment, int _direction ) {

    zx_vscroll( _environment, 8 * _direction );

}

void text_hscroll_line( Environment * _environment, int _direction ) {

    Variable * y = variable_retrieve( _environment, "windowCY" );
    outline1("LD A, (%s)", y->realName );
    outline0("LD B, A" );
    outline1("LD A, $%2.2x", ( _direction & 0xff ) );

    if ( !_environment->textHScrollLineDeployed ) {

        Variable * bitmapAddress = variable_retrieve( _environment, "BITMAPADDRESS" );

        outline0("JMP lib_text_hscroll_line_after");

        outhead0("lib_text_hscroll_line:" );
        outline1("LD HL, (%s)", bitmapAddress->realName );
        outline0("LD DE, 32");
        outhead0("lib_text_hscroll_line_ypos:");
        outline0("ADC HL, DE");
        outline0("DEC B");
        outline0("JP NZ,lib_text_hscroll_line_ypos");
        outline0("LD DE, HL");

        outline0("CP $80");
        outline0("JP C, lib_text_hscroll_line_right");

        outhead0("lib_text_hscroll_line_left:");
        outline0("LD A, 0" );
        outline0("LD C, A" );
        outhead0("lib_text_hscroll_line_left3:");
        outline0("LD A, 0" );
        outline0("LD B, A" );
        outline0("LD HL, DE" );
        outhead0("lib_text_hscroll_line_left2:");
        outline0("RL (HL)");
        outline0("INC HL");
        outline0("INC B");
        outline0("LD A,B");
        outline0("CP 32");
        outline0("JP NZ,lib_text_hscroll_line_right2");
        outline0("INC C");
        outline0("LD A,B");
        outline0("CP 8");
        outline0("JP NZ,lib_text_hscroll_line_right3");
        outline0("RET")

        outhead0("lib_text_hscroll_line_right:");
        outline0("LD A, 8" );
        outline0("LD C, A" );
        outhead0("lib_text_hscroll_line_right3:");
        outline0("LD A, 32" );
        outline0("LD B, A" );
        outline0("LD HL, DE" );
        outhead0("lib_text_hscroll_line_right2:");
        outline0("RR (HL)");
        outline0("INC HL");
        outline0("DEC B");
        outline0("JP NZ,lib_text_hscroll_line_right2");
        outline0("DEC C");
        outline0("JP NZ,lib_text_hscroll_line_right3");
        outline0("RET")

        outhead0("lib_text_hscroll_line_after:");

        _environment->textHScrollLineDeployed = 1;

    }

    outline0("CALL lib_text_hscroll_line");
    
}

void text_hscroll_screen( Environment * _environment, int _direction ) {

    outline1("LD A, $%2.2x", ( _direction & 0xff ) );

    if ( !_environment->textHScrollScreenDeployed ) {

        Variable * bitmapAddress = variable_retrieve( _environment, "BITMAPADDRESS" );

        outline0("JMP lib_text_hscroll_screen_after");

        outhead0("lib_text_hscroll_screen:" );
        outline0("CP $80");
        outline0("JP C, lib_text_hscroll_screen_right");

        outhead0("lib_text_hscroll_screen_left:");
        outline0("LD A, 0" );
        outline0("LD D, A" );
        outhead0("lib_text_hscroll_screen_left4:");
        outline0("LD A, 0" );
        outline0("LD C, A" );
        outhead0("lib_text_hscroll_screen_left3:");
        outline0("LD A, 0" );
        outline0("LD B, A" );
        outline1("LD HL, (%s)", bitmapAddress->realName );
        outhead0("lib_text_hscroll_screen_left2:");
        outline0("RL (HL)");
        outline0("INC HL");
        outline0("INC B");
        outline0("LD A,B");
        outline0("CP 32");
        outline0("JP NZ,lib_text_hscroll_screen_right2");
        outline0("INC C");
        outline0("LD A,B");
        outline0("CP 8");
        outline0("JP NZ,lib_text_hscroll_screen_right3");
        outline0("DEC D");
        outline0("LD A,D");
        outline0("CP 192");
        outline0("JP NZ,lib_text_hscroll_screen_right4");
        outline0("RET")

        outhead0("lib_text_hscroll_screen_right:");
        outline0("LD A, 192" );
        outline0("LD D, A" );
        outhead0("lib_text_hscroll_screen_right4:");
        outline0("LD A, 8" );
        outline0("LD C, A" );
        outhead0("lib_text_hscroll_screen_right3:");
        outline0("LD A, 32" );
        outline0("LD B, A" );
        outline1("LD HL, (%s)", bitmapAddress->realName );
        outhead0("lib_text_hscroll_screen_right2:");
        outline0("RR (HL)");
        outline0("INC HL");
        outline0("DEC B");
        outline0("JP NZ,lib_text_hscroll_screen_right2");
        outline0("DEC C");
        outline0("JP NZ,lib_text_hscroll_screen_right3");
        outline0("DEC D");
        outline0("JP NZ,lib_text_hscroll_screen_right4");
        outline0("RET")

        outhead0("lib_text_hscroll_screen_after:");

        _environment->textHScrollScreenDeployed = 1;

    }

    outline0("CALL lib_text_hscroll_screen");
    
}

void text_cline( Environment * _environment, char * _characters ) {

   
}

void cls( Environment * _environment ) {

    zx_cls( _environment, NULL, NULL );

}

/**
 * @brief Emit ASM implementation for <b>TEXT ENABLE</b> instruction
 * 
 * This function can be called to emit the code to enable text mode
 * on the target machine.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword TILEMAP ENABLE

@english
Enable the tilemap mode.

@italian
Abilita la modalità a tiles.

@syntax TILEMAP ENABLE

@example TILEMAP ENABLE

@target zx
</usermanual> */
void tilemap_enable( Environment * _environment, int _width, int _height, int _colors ) {
    
     bitmap_disable( _environment );

}
