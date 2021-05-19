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
 *  * `textmap_address` (VT_ADDRESS) - the starting address of text memory
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
 *  * `textmap_address` (VT_ADDRESS) - the starting address of text memory
 * 
 * @param _environment Current calling environment
 * @param _address Expression with address to use
 */
void textmap_at_var( Environment * _environment, char * _address ) {

    outline1("; TEXTMAP AT %s (ignored)", _address);

}

void text_encoded_at( Environment * _environment, char * _x, char * _y, char * _text, char * _encoding, char * _pen, char * _paper ) {

    Variable * text = variable_retrieve( _environment, _text );
    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );
    Variable * pen = variable_retrieve( _environment, _pen );
    Variable * paper = variable_retrieve( _environment, _paper );
    Variable * tab = variable_retrieve( _environment, "TAB" );
    Variable * ww = variable_retrieve( _environment, "windowWW" );

    Variable * localpen = variable_define( _environment, "localpen", VT_COLOR, COLOR_BLACK );
    Variable * localpaper = variable_define( _environment, "localpaper", VT_COLOR, COLOR_WHITE );

    variable_move_naked( _environment, pen->name, localpen->name );
    variable_move_naked( _environment, paper->name, localpaper->name );

    outline1("LD A, (%s)", y->realName );
    outline0("LD D, A" );
    outline1("LD A, (%s)", x->realName );
    outline0("LD E, A" );
    outline1("LD A, (%s)", text->realName );
    outline0("LD C, A" );
    outline0("LD B, 0" );
    outline1("LD HL, (%s+1)", text->realName );
    
    if ( ! _environment->textEncodedAtDeployed ) {

        Variable * colormapAddress = variable_retrieve( _environment, "colormapAddress" );
        Variable * bitmapAddress = variable_retrieve( _environment, "bitmapAddress" );

        outline0("JMP text_encoded_at_after" );

        outhead0("text_encoded_at:");
        outline0("LD A, (HL)");
        outline0("INC HL");
        outline0("CP 6");
        outline0("JP C, text_encoded_at_control_code");
        outline0("CP 32");
        outline0("JP C, text_encoded_at");
        outline0("PUSH DE");
        outline0("PUSH HL");
        outline0("PUSH BC");
        outline0("CALL text_encoded_at_pc");
        outline0("POP BC");
        outline0("POP HL");
        outline0("POP DE");
        outline0("INC E");
        outline0("LD A, E");
        outline0("CP 32");
        outline0("JP C, text_encoded_at_next_column");
        outline0("LD E, 0");
        outline0("INC D");
        outline0("LD A, D");
        outline0("CP 24");
        outline0("JP C, text_encoded_at_next_column");

        outhead0("text_encoded_at_scroll_screen:");
        outline0("DEC D");

        outline0("PUSH DE");
        outline0("PUSH HL");
        outline0("PUSH BC");

        text_vscroll_screen( _environment, -1 );

        outline0("POP BC");
        outline0("POP HL");
        outline0("POP DE");
        outline0("JMP text_encoded_at_next_column");

        outhead0("text_encoded_at_control_code:");
        outline0("CP 9");
        outline0("JP Z, text_encoded_at_tab");
        outline0("CP 1");
        outline0("JP Z, text_encoded_at_pen");
        outline0("CP 2");
        outline0("JP Z, text_encoded_at_paper");
        outline0("CP 3");
        outline0("JP Z, text_encoded_at_cmove");
        outline0("CP 4");
        outline0("JP Z, text_encoded_at_at");
        outline0("JMP text_encoded_at_next_column");

        outhead0("text_encoded_at_tab:");
        outline0("LD A, E");
        outhead0("text_encoded_at_tab_repeat:");
        outline1("LD A, (%s)", tab->realName);
        outline0("LD B, A");
        outline0("SBC A, B");
        outline0("JP M, text_encoded_at_tab_next");
        outline0("JMP text_encoded_at_tab_repeat");
        outhead0("text_encoded_at_tab_next:");
        outline0("ADD A, B");
        outline0("ADD A, E");
        outline0("LD E, A");
        outline0("CP 32");
        outline0("JP C, text_encoded_at_next_column");
        outline0("LD E, 0");
        outline0("INC D");
        outline0("CP 24");
        outline0("JP C, text_encoded_at_next_column");
        outline0("JMP text_encoded_at_scroll_screen");

        outhead0("text_encoded_at_pen:");
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline1("LD (%s), A", localpen->realName);        
        outline0("JMP text_encoded_at_next_column");

        outhead0("text_encoded_at_paper:");
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline1("LD (%s), A", localpaper->realName);        
        outline0("JMP text_encoded_at_next_column");

        outhead0("text_encoded_at_at:");
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline0("LD E, A");   
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline0("LD D, A");   
        outline0("JMP text_encoded_at_next_column");

        outhead0("text_encoded_at_cmove:");
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline0("ADD A, E");   
        outline0("LD E, A");
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline0("ADD A, D");   
        outline0("LD D, A");
        outline0("JMP text_encoded_at_next_column");

        outhead0("text_encoded_at_next_column:");
        outline0("DEC C");
        outline0("RET Z");
        outline0("JP text_encoded_at");

        outhead0("text_encoded_at_pc:");
        outline0("PUSH AF" );
        outline0("PUSH DE" );
        outline0("LD HL, $5800" );
        outline0("LD A, D" );
        outline0("CP 0" );
        outline0("JP Z, text_encoded_at_row");
        outhead0("text_encoded_at_pc2:");
        outline0("ADD HL, 32" );
        outline0("DEC D" );
        outline0("JP NZ, text_encoded_at_pc2");
        outhead0("text_encoded_at_row:");
        outline0("LD A, E" );
        outline0("ADD HL, A" );
        outline0("POP DE" );
        outline0("LD A, (HL)" );
        outline0("AND $38" );
        outline0("LD B, A" );
        outline1("LD A, (%s)", ww->realName );
        outline0("AND 1" );
        outline0("JP Z, text_encoded_at_pc3");
        outline1("LD A, (%s)", localpaper->realName );
        outline0("SLA A" );
        outline0("SLA A" );
        outline0("SLA A" );
        outline0("LD B, A" );
        outhead0("text_encoded_at_pc3:");
        outline1("LD A, (%s)", ww->realName );
        outline0("AND 2" );
        outline0("JP Z, text_encoded_at_pc4");
        outline1("LD A, (%s)", localpen->realName );
        outline0("AND $07" );
        outline0("JMP text_encoded_at_pc5");
        outhead0("text_encoded_at_pc4:");
        outline0("LD A, (HL)" );
        outline0("AND $07" );
        outhead0("text_encoded_at_pc5:");
        outline0("OR A, B" );
        outline0("LD (HL), A" );

        outline0("POP AF" );
        outline0("LD HL, $3C00" );
        outline0("LD B,0" );
        outline0("LD C, A" );
        outline0("SLA C" );
        outline0("RL B" );
        outline0("SLA C" );
        outline0("RL B" );
        outline0("SLA C" );
        outline0("RL B" );
        outline0("ADD HL, BC");
        outline0("CALL text_encoded_at_gc");
        outline0("LD B,8");
        outhead0("text_encoded_at_l1:");
        outline0("LD A,(HL)");
        outline0("LD (DE),A");
        outline0("INC HL");
        outline0("INC D");
        outline0("DJNZ text_encoded_at_l1");
        outline0("RET");
        outhead0("text_encoded_at_gc:");    
        outline0("LD A,D");
        outline0("AND %00000111");
        outline0("RRA");
        outline0("RRA");
        outline0("RRA");
        outline0("RRA");
        outline0("OR E");
        outline0("LD E,A");
        outline0("LD A,D");
        outline0("AND %00011000");
        outline0("OR %01000000");
        outline0("LD D,A");
        outline0("RET");

        _environment->textEncodedAtDeployed = 1;

        outhead0("text_encoded_at_after:");
    }

    outline0("CALL text_encoded_at");
    outline0("LD A, D" );
    outline1("LD (%s), A", y->realName );
    outline0("LD A, E" );
    outline1("LD (%s), A", x->realName );

}

Variable * text_get_pen( Environment * _environment, char * _color ) {
    
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_WHITE );

    Variable * result = variable_temporary( _environment, VT_STRING, 0 );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\xf " );
    char stringAddress[MAX_TEMPORARY_STORAGE]; sprintf( stringAddress, "%s+1", result->realName );

    variable_store_string(_environment, result->name, resultString );

    cpu_move_8bit_indirect_with_offset(_environment, color->realName, stringAddress, 1 );
        
    return result;

}

Variable * text_get_paper( Environment * _environment, char * _color ) {
    
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_BLACK );

    Variable * result = variable_temporary( _environment, VT_STRING, 0 );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x10 " );
    char stringAddress[MAX_TEMPORARY_STORAGE]; sprintf( stringAddress, "%s+1", result->realName );

    variable_store_string(_environment, result->name, resultString );

    cpu_move_8bit_indirect_with_offset(_environment, color->realName, stringAddress, 1 );
        
    return result;

}


Variable * text_get_at( Environment * _environment, char * _x, char * _y ) {
    
    Variable * x = variable_retrieve_or_define( _environment, _x, VT_BYTE, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_BYTE, 0 );

    Variable * result = variable_temporary( _environment, VT_STRING, 0 );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x16  " );
    char stringAddress[MAX_TEMPORARY_STORAGE]; sprintf( stringAddress, "%s+1", result->realName );

    variable_store_string(_environment, result->name, resultString );

    cpu_move_8bit_indirect_with_offset(_environment, x->realName, stringAddress, 1 );
    cpu_move_8bit_indirect_with_offset(_environment, y->realName, stringAddress, 2 );
        
    return result;

}

void text_vscroll_screen( Environment * _environment, int _direction ) {

    outline1("LD A, $%2.2x", ( _direction & 0xff ) );

    if ( !_environment->textVScrollScreenDeployed ) {

        Variable * bitmapAddress = variable_retrieve_or_define( _environment, "bitmapAddress", VT_ADDRESS, 0x4000 );

        outline0("JMP text_vscroll_screen_after");

        outline0("text_vscroll_screen:");
        outline0("CP $80");
        outline0("JP C, text_vscroll_screen_down");

        outline0("text_vscroll_screen_up:");
        outline0("LD DE, 6112" );
        outline1("LD HL, (%s)", bitmapAddress->realName );
        outline0("ADD HL, DE" );
        outline0("PUSH HL" );
        outline0("LD DE, 6144" );
        outline1("LD HL, (%s)", bitmapAddress->realName );
        outline0("ADD HL, DE" );
        outline0("LD DE, HL" );
        outline0("POP HL" );
        outline0("LD BC, 6112")
        outline0("LDDR")
        outline0("RET")

        outline0("text_vscroll_screen_down:");
        outline1("LD HL, (%s)", bitmapAddress->realName );
        outline0("PUSH HL" );
        outline0("POP DE" );
        outline1("LD HL, (%s)", bitmapAddress->realName );
        outline0("LD DE, 32" );
        outline0("ADD HL, DE" );
        outline0("LD BC, 6112")
        outline0("LDIR")
        outline0("RET")

        outhead0("text_vscroll_screen_after:");

        _environment->textVScrollScreenDeployed = 1;

    }

    outline0("CALL text_vscroll_screen");

}

void text_hscroll_line( Environment * _environment, int _direction ) {

    Variable * y = variable_retrieve( _environment, "windowCY" );
    outline1("LD A, (%s)", y->realName );
    outline0("LD B, A" );
    outline1("LD A, $%2.2x", ( _direction & 0xff ) );

    if ( !_environment->textHScrollLineDeployed ) {

        Variable * bitmapAddress = variable_retrieve( _environment, "bitmapAddress" );

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

        Variable * bitmapAddress = variable_retrieve( _environment, "bitmapAddress" );

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

void text_cls( Environment * _environment ) {

    if ( !_environment->textClsDeployed ) {

        Variable * bitmapAddress = variable_retrieve( _environment, "bitmapAddress" );

        outline0("JMP lib_text_cls_after");

        outline0("lib_text_cls:");

        outline0("LD A, 0" );
        outline1("LD HL, (%s)", bitmapAddress->realName );
        outline0("LD (HL), A" );
        outline0("LD DE, 1" );
        outline1("LD HL, (%s)", bitmapAddress->realName );
        outline0("ADD HL, DE" );
        outline0("LD DE, HL" );
        outline1("LD HL, (%s)", bitmapAddress->realName );
        outline0("LD BC, 6144")
        outline0("LDIR")

        outline0("lib_text_cls_after:");

        _environment->textClsDeployed = 1;

    }

    outline0("CALL lib_text_cls");
    
}

void text_paper( Environment * _environment, char * _color ) {

    Variable * paper = variable_retrieve( _environment, "windowPA" );
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_BLACK );

    variable_move( _environment, color->name, paper->name );
    
    zx_color_border( _environment, color->realName );
    
}
