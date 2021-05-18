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
/* <usermanual>
@keyword TEXTMAP AT

@english
Set the starting address, in memory, for the textmap. The input parameter 
is decoded and declined according to the hardware limits. So it is not
said that exactly the given address is set.

@italian
Imposta l'indirizzo di partenza, in memoria, per la textmap. Il parametro 
di input viene decodificato e declinato in base ai limiti hardware. Quindi 
non è detto che sia impostato esattamente con l'indirizzo specificato.

@syntax TEXTMAP AT # [integer]

@example TEXTMAP AT #$0400

@target c64
</usermanual> */
void textmap_at( Environment * _environment, int _address ) {

    outline1("; TEXTMAP AT $%4.4x", _address);

    // Let's define the special variable bitmapAddress, and update
    // it with the requested value.
    // TODO: the textmap_address should be populated by a get_textmap_address() function!
    Variable * textAddress = variable_retrieve_or_define( _environment, "textmap_address", VT_ADDRESS, _address );
    variable_store( _environment, "textmap_address", ( ( _address >> 10 ) & 0x0f ) * 0x0400 );

    char addressString[MAX_TEMPORARY_STORAGE]; sprintf(addressString, "#$%2.2x", ( _address >> 8 ) & 0xff );

    vic2_textmap_at( _environment, addressString );

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
/* <usermanual>
@keyword TEXTMAP AT

@syntax TEXTMAP AT [expression]

@example TEXTMAP AT newTextmapAddress

@target c64
</usermanual> */
void textmap_at_var( Environment * _environment, char * _address ) {

    outline1("; TEXTMAP AT %s", _address);

    Variable * textAddress = variable_retrieve_or_define( _environment, "textAddress", VT_ADDRESS, 0x0400 );

    Variable * address = variable_retrieve( _environment, _address );

    char addressString[MAX_TEMPORARY_STORAGE]; sprintf(addressString, "%s+1", address->realName );

    vic2_textmap_at( _environment, addressString );

}

void text_encoded_at( Environment * _environment, char * _x, char * _y, char * _text, char * _encoding, char * _pen, char * _paper ) {

    Variable * text = variable_retrieve( _environment, _text );
    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );
    Variable * encoding = variable_retrieve( _environment, _encoding );
    Variable * pen = variable_retrieve( _environment, _pen );
    Variable * paper = variable_retrieve( _environment, _paper );
    Variable * textAddress = variable_retrieve( _environment, "textAddress" );
    Variable * tab = variable_retrieve( _environment, "windowT" );
    Variable * colormapAddress = variable_retrieve( _environment, "colormapAddress" );
    Variable * styles = variable_retrieve( _environment, "windowS" );
    Variable * ww = variable_retrieve( _environment, "windowWW" );

    char textString[MAX_TEMPORARY_STORAGE]; sprintf(textString, "%s+1", text->realName );

    MAKE_LABEL

    // $16-$17 : height
    // $18-$19 :    width
    // $20-$21 :    text address
    // $22-$23 :    screen base
    // $24 :    text size
    // $25 :    characters to skip
    // $d6 : y
    // $d3 : x

    vic2_get_height( _environment, "$16" );

    outline1("LDA %s", textString );
    outline0("STA $20");
    outline1("LDA %s+1", textString );
    outline0("STA $21");
    outline1("LDA %s", textAddress->realName );
    outline0("STA $22");
    outline1("LDA %s+1", textAddress->realName );
    outline0("STA $23");
    outline1("LDA %s", y->realName );
    outline0("STA $d6" );
    outline1("LDA %s", x->realName );
    outline0("STA $d3");
    outline1("LDA %s", text->realName );
    outline0("STA $24" );
    outline0("LDA #0" );
    outline0("STA $25" );
    outline1("LDA %s", colormapAddress->realName );
    outline0("STA $29");
    outline1("LDA %s+1", colormapAddress->realName );
    outline0("STA $2a");
    outline1("LDA %s", ww->realName );
    outline0("STA $2c");
    outline1("LDA %s", styles->realName );
    outline0("AND #$1" );
    outline1("BNE %sinverse", label );
    outline1("LDA %s", pen->realName );
    outline0("STA $2b");
    outline1("JMP %stext", label );
    outhead1("%sinverse:", label)
    outline1("LDA %s", paper->realName );
    outline0("STA $2b");
    outhead1("%stext:", label)

    if ( ! _environment->textEncodedAtDeployed ) {

        outline0("JMP lib_text_encoded_at_after");

        outhead0("lib_text_encoded_at:");
        outline0("SEI" ); // y
        outline0("LDX $d6" ); // y
        outline0("BEQ lib_text_encoded_at_skip" );
        outhead0("lib_text_encoded_at_loop1:" );
        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC $22");
        outline0("STA $22");
        outline0("LDA #0"); // width (hi)
        outline0("ADC $23");
        outline0("STA $23");
        outline0("DEX" );
        outline0("BNE lib_text_encoded_at_loop1" );

        outline0("LDX $d6" ); // y
        outhead0("lib_text_encoded_at_loopc1:" );
        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC $29");
        outline0("STA $29");
        outline0("LDA #0"); // width (hi)
        outline0("ADC $2a");
        outline0("STA $2a");
        outline0("DEX" );
        outline0("BNE lib_text_encoded_at_loopc1" );

        outhead0("lib_text_encoded_at_skip:" );
        outline0("CLC"); // x
        outline0("LDA $d3"); // x
        outline0("ADC $22");
        outline0("STA $22");
        outline0("LDA #0");
        outline0("ADC $23");
        outline0("STA $23");

        outline0("CLC"); // x
        outline0("LDA $d3"); // x
        outline0("ADC $29");
        outline0("STA $29");
        outline0("LDA #0");
        outline0("ADC $2a");
        outline0("STA $2a");

        outline0("LDX $24"); // size
        outline0("LDY #$0" );
        outhead0("lib_text_encoded_at_loop2:" );

        outline0("LDA $25" );
        outline0("BEQ lib_text_encoded_at_nskip_for_tab" );
        outline0("JMP lib_text_encoded_at_skip_for_tab" );
        outhead0("lib_text_encoded_at_nskip_for_tab:" );
        outline0("LDA ($20),Y");

        outline0("CMP #10");
        outline0("BCS lib_text_encoded_at_xcontrol_code");
        outline0("JMP lib_text_encoded_at_control_code");
        outhead0("lib_text_encoded_at_xcontrol_code:");

        outline0("CMP #32");
        outline0("BCS lib_text_encoded_at_xsp128");
        outline0("JMP lib_text_encoded_at_sp128");
        outhead0("lib_text_encoded_at_xsp128:")
        outline0("CMP #64");
        outline0("BCS lib_text_encoded_at_xsp0");
        outline0("JMP lib_text_encoded_at_sp0");
        outhead0("lib_text_encoded_at_xsp0:")
        outline0("CMP #96");
        outline0("BCS lib_text_encoded_at_xsm64");
        outline0("JMP lib_text_encoded_at_sm64");
        outhead0("lib_text_encoded_at_xsm64:")
        outline0("CMP #160");
        outline0("BCS lib_text_encoded_at_xsp64");
        outline0("JMP lib_text_encoded_at_sp64");
        outhead0("lib_text_encoded_at_xsp64:")
        outline0("CMP #192");
        outline0("BCS lib_text_encoded_at_x2sm64");
        outline0("JMP lib_text_encoded_at_sm64");
        outhead0("lib_text_encoded_at_x2sm64:")
        outline0("CMP #224");
        outline0("BCS lib_text_encoded_at_x2sm128");
        outline0("JMP lib_text_encoded_at_sm128");
        outhead0("lib_text_encoded_at_x2sm128:")
        outline0("JMP lib_text_encoded_at_sp0");

        outhead0("lib_text_encoded_at_sp64:");
        outline0("CLC"); // x
        outline0("ADC #64");
        outline0("JMP lib_text_encoded_at_sp0");
        outhead0("lib_text_encoded_at_sp128:");
        outline0("ADC #128");
        outline0("JMP lib_text_encoded_at_sp0");
        outhead0("lib_text_encoded_at_sm64:");
        outline0("SBC #63");
        outline0("JMP lib_text_encoded_at_sp0");
        outhead0("lib_text_encoded_at_sm128:");
        outline0("SBC #127");
        outline0("JMP lib_text_encoded_at_sp0");

        outhead0("lib_text_encoded_at_tab:");
        outline0("LDA $d3");
        outhead0("lib_text_encoded_at_tab2:");
        outline1("CMP %s", tab->realName); // tab spaces
        outline0("BCC lib_text_encoded_at_tab3");
        outline1("DEC %s", tab->realName); // tab spaces
        outline0("JMP lib_text_encoded_at_tab2");
        outhead0("lib_text_encoded_at_tab3:");
        outline0("CLC"); // x
        outline1("ADC %s", tab->realName); // tab spaces
        outline0("STA $25");
        outline0("JMP lib_text_encoded_at_next");

        outhead0("lib_text_encoded_at_control_code:")
        outline0("CMP #09");
        outline0("BEQ lib_text_encoded_at_tab");
        outline0("CMP #01");
        outline0("BEQ lib_text_encoded_at_pen");
        outline0("CMP #02");
        outline0("BEQ lib_text_encoded_at_paper");
        outline0("CMP #03");
        outline0("BEQ lib_text_encoded_at_cmove_prepare");
        outline0("CMP #04");
        outline0("BEQ lib_text_encoded_at_xat");
        outline0("JMP lib_text_encoded_at_next");
        outhead0("lib_text_encoded_at_xat:");
        outline0("JMP lib_text_encoded_at_at");

        outhead0("lib_text_encoded_at_pen:");
        outline0("INC $20");
        outline0("DEX");
        outline0("LDA $2c");
        outline0("AND #$2");
        outline0("BEQ lib_text_encoded_at_pen_disabled");
        outline0("LDA ($20), Y");
        outline0("STA $2b");
        outhead0("lib_text_encoded_at_pen_disabled:");
        outline0("INC $20");
        outline0("DEY");
        outline0("JMP lib_text_encoded_at_next");

        outhead0("lib_text_encoded_at_paper:");
        outline0("INC $20");
        outline0("DEX");
        outline0("LDA $2c");
        outline0("AND #$1");
        outline0("BEQ lib_text_encoded_at_paper_disabled");
        outline0("LDA ($20), Y");
        outline0("STA $d021");
        outline0("STA $d020");
        outhead0("lib_text_encoded_at_paper_disabled:");
        outline0("INC $20");
        outline0("DEY");
        outline0("JMP lib_text_encoded_at_next");

        outhead0("lib_text_encoded_at_cmove_prepare:");
        outline0("INC $20");
        outline0("DEX");
        outline0("LDA ($20), Y");
        outline0("STA $33");
        outline0("INC $20");
        outline0("DEX");
        outline0("LDA ($20), Y");
        outline0("STA $34");

        outhead0("lib_text_encoded_at_cmove:");
        outline0("CLC"); // x
        outline0("LDA $33");
        outline0("ADC $d3");
        outline0("CMP #$80");
        outline0("BCS lib_text_encoded_at_cmove_skipx");
        outline0("CMP #40");
        outline0("BCS lib_text_encoded_at_cmove_skipx");
        outline0("STA $d3");
        outline0("LDA $33");

        outline0("CMP #$80");
        outline0("BCC lib_text_encoded_at_cmove_addpx");

        outhead0("lib_text_encoded_at_cmove_subpx:")
        outline0("EOR #$FF"); // x
        outline0("CLC"); // x
        outline0("ADC #$1"); // x
        outline0("STA $33"); // x
        outline0("SEC"); // x
        outline0("LDA $22");
        outline0("SBC $33");
        outline0("STA $22");
        outline0("LDA $23"); // width (hi)
        outline0("SBC #0");
        outline0("STA $23");

        outline0("SEC"); // x
        outline0("LDA $29");
        outline0("SBC $33");
        outline0("STA $29");
        outline0("LDA $30"); // width (hi)
        outline0("SBC #0");
        outline0("STA $30");

        outline0("JMP lib_text_encoded_at_cmove_skipx");

        outhead0("lib_text_encoded_at_cmove_addpx:")

        outline0("CLC"); // x
        outline0("ADC $22");
        outline0("STA $22");
        outline0("LDA #0"); // width (hi)
        outline0("ADC $23");
        outline0("STA $23");
        outline0("JMP lib_text_encoded_at_cmove_skipx");

        outhead0("lib_text_encoded_at_cmove_skipx:");

        outline0("CLC"); // x
        outline0("LDA $34");
        outline0("ADC $d6");
        outline0("CMP #$80");
        outline0("BCS lib_text_encoded_at_cmove_skipy");
        outline0("CMP #26");
        outline0("BCS lib_text_encoded_at_cmove_skipy");
        outline0("STA $d6");

        outhead0("lib_text_encoded_at_cmove_addpy:");
        outline0("TXA");
        outline0("PHA");
        outline0("LDA $34");
        outline0("CMP #$80");
        outline0("BCC lib_text_encoded_at_cmove_loopyp");
        outline0("JMP lib_text_encoded_at_cmove_loopym");

        outhead0("lib_text_encoded_at_cmove_loopyp:")
        outline0("TAX");
        outhead0("lib_text_encoded_at_cmove_loopy:")

        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC $22");
        outline0("STA $22");
        outline0("LDA #0"); // width (hi)
        outline0("ADC $23");
        outline0("STA $23");

        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC $29");
        outline0("STA $29");
        outline0("LDA #0"); // width (hi)
        outline0("ADC $30");
        outline0("STA $30");

        outline0("DEX" );
        outline0("BNE lib_text_encoded_at_cmove_loopy" );
        outline0("PLA");
        outline0("TAX");
        outline0("JMP lib_text_encoded_at_cmove_skipy" );

        outhead0("lib_text_encoded_at_cmove_loopym:")
        outline0("EOR #$FF"); // x
        outline0("CLC"); // x
        outline0("ADC #$1"); // x
        outline0("STA $34"); // x
        outline0("TAX");
        outhead0("lib_text_encoded_at_cmove_loopy2:")

        outline0("SEC"); // x
        outline0("LDA $22"); // width (lo)
        outline0("SBC #40");
        outline0("STA $22");
        outline0("LDA $23"); // width (hi)
        outline0("SBC #0");
        outline0("STA $23");

        outline0("SEC"); // x
        outline0("LDA $29"); // width (lo)
        outline0("SBC #40");
        outline0("STA $29");
        outline0("LDA $30"); // width (hi)
        outline0("SBC #0");
        outline0("STA $30");

        outline0("DEX" );
        outline0("BNE lib_text_encoded_at_cmove_loopy2" );
        outline0("PLA");
        outline0("TAX");
        outline0("JMP lib_text_encoded_at_cmove_skipy" );

        outhead0("lib_text_encoded_at_cmove_skipy:");
        outline0("INC $20");
        outline0("DEY");
        outline0("JMP lib_text_encoded_at_next");

        outhead0("lib_text_encoded_at_at:");
        outline0("INC $20");
        outline0("DEX");
        outline0("LDA ($20), Y");
        outline0("SEC");
        outline0("SBC $d3");
        outline0("STA $33");
        outline0("INC $20");
        outline0("DEX");
        outline0("LDA ($20), Y");
        outline0("SEC");
        outline0("SBC $d6");
        outline0("STA $34");
        outhead0("JMP lib_text_encoded_at_cmove");

        outhead0("lib_text_encoded_at_sp0:");
        outline0("STA ($22),Y");
        outline0("LDA $2c");
        outline0("AND #$2");
        outline0("BEQ lib_text_encoded_at_nopen");
        outline0("LDA $2b");
        outline0("STA ($29),Y");
        outhead0("lib_text_encoded_at_nopen:");
        outline0("JMP lib_text_encoded_at_increment_x");

        outhead0("lib_text_encoded_at_skip_for_tab:");
        outline0("DEC $25");
        outline0("JMP lib_text_encoded_at_increment_x");

        outhead0("lib_text_encoded_at_increment_x:");
        outline0("INC $d3"); // x
        outline0("LDA $d3"); // x
        outline0("CMP #40"); // x
        outline0("BEQ lib_text_encoded_at_next2"); // x
        outline0("JMP lib_text_encoded_at_next"); // x
        outhead0("lib_text_encoded_at_next2:");
        outline0("LDA #0"); // x
        outline0("STA $d3"); // x
        outline0("INC $d6"); // y
        outline0("LDA $d6"); // y
        outline0("CMP #24"); // h

        outline0("BEQ lib_text_encoded_at_next3"); // x
        outline0("JMP lib_text_encoded_at_next"); // x
        outhead0("lib_text_encoded_at_next3:");

        text_vscroll_screen( _environment, -1 );

        outline0("DEC $d6"); // y
        outline0("SEC");
        outline0("LDA $22");
        outline0("SBC #40");
        outline0("STA $22");
        outline0("LDA $23");
        outline0("SBC #0");
        outline0("STA $23");

        outline0("SEC");
        outline0("LDA $29");
        outline0("SBC #40");
        outline0("STA $29");
        outline0("LDA $2a");
        outline0("SBC #0");
        outline0("STA $2a");

        outhead0("lib_text_encoded_at_next:");
        outline0("LDA $25");
        outline0("BEQ lib_text_encoded_at_xloop2");
        outline0("JMP lib_text_encoded_at_loop2");
        outhead0("lib_text_encoded_at_xloop2:");
        outline0("INY" );
        outline0("DEX" );
        outline0("BEQ lib_text_encoded_at_end" );
        outline0("JMP lib_text_encoded_at_loop2" );
        outline0("lib_text_encoded_at_end:" );
        outline0("SEI" ); // y
        outline0("RTS" );

        outhead0("lib_text_encoded_at_after:");

        _environment->textEncodedAtDeployed = 1;

    }

    outline0("JSR lib_text_encoded_at");
    
    outline0("LDA $d6" );
    outline1("STA %s", y->realName );
    outline0("LDA $d3");
    outline1("STA %s", x->realName );

}

void text_vscroll_screen( Environment * _environment, int _direction ) {

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA $30" );

    if ( !_environment->textVScrollScreenDeployed ) {

        Variable * textAddress = variable_retrieve( _environment, "textAddress" );

        outline0("JMP text_vscroll_screen_after");

        outline0("text_vscroll_screen:");
        // Use the current bitmap address as starting address for filling routine.
        outline1("LDA %s", textAddress->realName);
        outline0("STA $25");
        outline1("LDA %s+1", textAddress->realName);
        outline0("STA $26");
        outline0("CLC");
        outline1("LDA %s", textAddress->realName);
        outline0("ADC #40");
        outline0("STA $27");
        outline1("LDA %s+1", textAddress->realName);
        outline0("STA $28");

        outline0("LDA $30");
        outline0("CMP #$80");
        outline0("BCC text_vscroll_screen_down");

        outhead0("text_vscroll_screen_up:");
        outline0("LDX #3" );
        outline0("LDY #0" );
        outhead0("text_vscroll_screen_up_yscroll:");
        outline0("LDA ($27),Y");
        outline0("STA ($25),Y");
        outline0("INY");
        outline0("BNE text_vscroll_screen_up_yscroll");
        outline0("INC $26");
        outline0("INC $28");
        outline0("CPX #1");
        outline0("BNE text_vscroll_screen_up_yscroll_next");
        outhead0("text_vscroll_screen_up_yscroll2:");
        outline0("LDA ($27),Y");
        outline0("STA ($25),Y");
        outline0("INY");
        outline0("CPY #232");
        outline0("BNE text_vscroll_screen_up_yscroll2");
        outhead0("text_vscroll_screen_up_yscroll_next:");
        outline0("DEX");
        outline0("BNE text_vscroll_screen_up_yscroll");
        outline0("LDY #192");
        outhead0("text_vscroll_screen_up_refill:");
        outline0("LDA #32");
        outline0("STA ($25),Y");
        outline0("INY");
        outline0("CPY #232");
        outline0("BNE text_vscroll_screen_up_refill");
        outline0("RTS");

        outhead0("text_vscroll_screen_down:");
        outline0("INC $26" );
        outline0("INC $28" );
        outline0("INC $26" );
        outline0("INC $28" );
        outline0("INC $26" );
        outline0("INC $28" );
        outline0("INC $26" );
        outline0("INC $28" );
        outline0("LDY #232");
        outhead0("text_vscroll_screen_down_yscroll3:");
        outline0("LDA ($25),Y");
        outline0("STA ($27),Y");
        outline0("DEY");
        outline0("CPY #255");
        outline0("BNE text_vscroll_screen_down_yscroll3");

        outline0("DEC $26" );
        outline0("DEC $28");
        outline0("LDX #4" );
        outline0("LDY #255");
        outhead0("text_vscroll_screen_down_yscroll4:");
        outline0("LDA ($25),Y");
        outline0("STA ($27),Y");
        outline0("DEY");
        outline0("CPY #255");
        outline0("BNE text_vscroll_screen_down_yscroll4");

        outline0("DEC $26");
        outline0("DEC $28");
        outline0("LDY #255");
        outline0("DEX");
        outline0("BNE text_vscroll_screen_down_yscroll4");
        outline0("RTS");

        outline0("text_vscroll_screen_after:");

        _environment->textVScrollScreenDeployed = 1;

    }

    outline0("JSR text_vscroll_screen");

}

// void text_vscroll_line( Environment * _environment, int _direction ) {

//     Variable * y = variable_retrieve( _environment, "windowCY" );
//     outline1("LDA #$%2.2x", ( _direction & 0xff ) );
//     outline0("STA $30" );
//     outline1("LDA %s", y->realName );
//     outline0("STA $31");

//     if ( !_environment->textVScrollLineDeployed ) {

//         Variable * textAddress = variable_retrieve( _environment, "textAddress" );

//         outline0("JMP text_vscroll_line_after");

//         outline0("text_vscroll_line:");
//         // Use the current bitmap address as starting address for filling routine.
//         outline1("LDA %s", textAddress->realName);
//         outline0("STA $25");
//         outline1("LDA %s+1", textAddress->realName);
//         outline0("STA $26");
//         outline0("CLC");
//         outline1("LDA %s", textAddress->realName);
//         outline0("ADC #40");
//         outline0("STA $27");
//         outline1("LDA %s+1", textAddress->realName);
//         outline0("STA $28");

//         outline0("LDA #$6" );
//         outline0("STA $32" );
//         outline0("LDA $31" );

//         cpu6502_math_div_8bit_to_8bit( _environment, "$31", "$32", "$33", "$34" );

//         outline0("LDA #$0" );
//         outline0("LDX $34" );
//         outhead0("text_vscroll_line_ybase:");
//         outline0("ADC #40" );
//         outline0("DEX" );
//         outline0("BNE text_vscroll_line_ybase" );
//         outline0("STA $34" );

//         outline1("LDA $30");
//         outline0("CMP #$80");
//         outline0("BCC text_vscroll_line_down");

//         outhead0("text_vscroll_line_up:");

//         outline0("LDX $33" );
//         outline0("LDY #0" );
//         outhead0("text_vscroll_line_yscroll:");
//         outline0("LDA ($27),Y");
//         outline0("STA ($25),Y");
//         outline0("INY");
//         outline0("BNE text_vscroll_line_yscroll");
//         outline0("INC $26");
//         outline0("INC $28");
//         outline0("CPX #1");
//         outline0("BNE text_vscroll_line_nextblock");
//         outhead0("text_vscroll_line_yscroll2:");
//         outline0("LDA ($27),Y");
//         outline0("STA ($25),Y");
//         outline0("INY");
//         outline0("CPY $34");
//         outline0("BNE text_vscroll_line_yscroll2");
//         outhead0("text_vscroll_line_nextblock:");
//         outline0("DEX");
//         outline0("BNE text_vscroll_line_yscroll");
//         outline0("RTS");

//         outhead0("text_vscroll_line_down:");
//         outline0("LDX #3" );
//         outline0("LDY #40" );
//         outhead0("text_vscroll_line_down_yscroll:");
//         outline0("LDA ($25),Y");
//         outline0("STA ($27),Y");
//         outline0("INY");
//         outline0("BNE text_vscroll_line_down_yscroll");
//         outline0("INC $26");
//         outline0("INC $28");
//         outline0("CPX #1");
//         outline0("BNE text_vscroll_line_down_nextblock");
//         outhead0(" text_vscroll_line_down_yscroll2:");
//         outline0("LDA ($27),Y");
//         outline0("STA ($25),Y");
//         outline0("INY");
//         outline0("CPY #232");
//         outline0("BNE  text_vscroll_line_down_yscroll2");
//         outhead0("text_vscroll_line_down_nextblock:");
//         outline0("DEX");
//         outline0("BNE text_vscroll_line_down_yscroll");
//         outline0("RTS");

//         outline0("text_vscroll_screen_after:");

//         _environment->textVScrollDeployed = 1;

//     }

//     outline0("JSR text_vscroll_screen");

// }

void text_paper( Environment * _environment, char * _color ) {

    Variable * paper = variable_retrieve( _environment, "windowPA" );
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_BLACK );

    variable_move( _environment, color->name, paper->name );
    
    vic2_background_color( _environment, "#0", color->realName );
    vic2_border_color( _environment, color->realName );
    
}

void text_cls( Environment * _environment ) {

    if ( !_environment->textClsDeployed ) {

        Variable * textAddress = variable_retrieve( _environment, "textAddress" );

        outline0("JMP lib_text_cls_after");

        outline0("lib_text_cls:");
        // Use the current bitmap address as starting address for filling routine.
        outline1("LDA %s", textAddress->realName);
        outline0("STA $25");
        outline1("LDA %s+1", textAddress->realName);
        outline0("STA $26");
        outline0("LDX #3" );
        outline0("LDY #0" );
        outline0("LDA #32" );
        outhead0("lib_text_cls_yloop:");
        outline0("STA ($25),Y");
        outline0("INY");
        outline0("BNE lib_text_cls_yloop");
        outline0("INC $26");
        outline0("CPX #1");
        outline0("BNE lib_text_cls_next_block");
        outhead0("lib_text_cls_yloop2:");
        outline0("STA ($25),Y");
        outline0("INY");
        outline0("CPY #232");
        outline0("BNE lib_text_cls_yloop2");
        outhead0("lib_text_cls_next_block:");
        outline0("DEX");
        outline0("BNE lib_text_cls_yloop");
        outline0("RTS");

        outline0("lib_text_cls_after:");

        _environment->textClsDeployed = 1;

    }

    outline0("JSR lib_text_cls");
    
}

void text_cline( Environment * _environment, char * _characters ) {

    Variable * characters = NULL;
    if ( _characters ) {
        characters = variable_retrieve( _environment, _characters );
        outline1("LDA %s", characters->realName);
    } else {
        outline0("LDA #0");
    }
    outline0("STA $25");

    if ( !_environment->textClineDeployed ) {

        Variable * colormapAddress = variable_retrieve( _environment, "colormapAddress" );
        Variable * textAddress = variable_retrieve( _environment, "textAddress" );
        Variable * x = variable_retrieve( _environment, "windowCX" );
        Variable * y = variable_retrieve( _environment, "windowCY" );

        outline0("JMP lib_text_cline_after");

        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");

        outline0("lib_text_cline:");
        outline1("LDA %s", x->realName );
        outline0("STA $30" );
        outline1("LDA %s", y->realName );
        outline0("STA $31");

        // Use the current bitmap address as starting address for filling routine.
        outline1("LDA %s", textAddress->realName);
        outline0("STA $22");
        outline1("LDA %s+1", textAddress->realName);
        outline0("STA $23");
        outline1("LDA %s", colormapAddress->realName );
        outline0("STA $29");
        outline1("LDA %s+1", colormapAddress->realName );
        outline0("STA $2a");
 
        outline0("LDX $31" ); // y
        outline0("BEQ lib_text_cline_skip" );
        outhead0("lib_text_cline_loop1:" );
        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC $22");
        outline0("STA $22");
        outline0("LDA #0"); // width (hi)
        outline0("ADC $23");
        outline0("STA $23");
        outline0("DEX" );
        outline0("BNE lib_text_cline_loop1" );

        outline0("LDX $31" ); // y
        outhead0("lib_text_cline_loopc1:" );
        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC $29");
        outline0("STA $29");
        outline0("LDA #0"); // width (hi)
        outline0("ADC $2a");
        outline0("STA $2a");
        outline0("DEX" );
        outline0("BNE lib_text_cline_loopc1" );

        outhead0("lib_text_cline_skip:" );

        outline0("LDA $25");
        outline0("BEQ lib_text_cline_entire_line");

        outline0("CLC"); // x
        outline0("LDA $30"); // x
        outline0("ADC $22");
        outline0("STA $22");
        outline0("LDA #0");
        outline0("ADC $23");
        outline0("STA $23");

        outline0("CLC"); // x
        outline0("LDA $30"); // x
        outline0("ADC $29");
        outline0("STA $29");
        outline0("LDA #0");
        outline0("ADC $2a");
        outline0("STA $2a");

        outline0("LDX $25");
        outline0("LDY #0");


        outhead0("lib_text_cline_increment_x:");
        outline0("LDA #32");
        outline0("STA ($22),y");
        
        outline0("INC $30"); // x
        outline0("LDA $30"); // x
        outline0("CMP #40"); // x
        outline0("BNE lib_text_cline_next"); // x
        outline0("LDA #0"); // x
        outline0("STA $30"); // x
        outline0("INC $31"); // y
        outline0("LDA $31"); // y
        outline0("CMP #24"); // h
        outline0("BNE lib_text_cline_next"); // x

        text_vscroll_screen( _environment, -1 );

        outline0("DEC $31"); // y
        outline0("SEC");
        outline0("LDA $22");
        outline0("SBC #40");
        outline0("STA $22");
        outline0("LDA $23");
        outline0("SBC #0");
        outline0("STA $23");

        outline0("SEC");
        outline0("LDA $29");
        outline0("SBC #40");
        outline0("STA $29");
        outline0("LDA $2a");
        outline0("SBC #0");
        outline0("STA $2a");
 
        outline0("lib_text_cline_next:");
        outline0("INY");
        outline0("DEX");
        outline0("BNE lib_text_cline_increment_x");
        outline0("RTS");

        outhead0("lib_text_cline_entire_line:");

        outline0("LDY #0");

        outhead0("lib_text_cline_increment2_x:");

        outline0("LDA #32");
        outline0("STA ($22),y");
        
        outline0("INY"); // x
        outline0("INC $30"); // x
        outline0("LDA $30"); // x
        outline0("CMP #40"); // x
        outline0("BNE lib_text_cline_increment2_x"); // x
        outline0("RTS");

        outhead0("lib_text_cline_after:");

        _environment->textClineDeployed = 1;

    }

    outline0("JSR lib_text_cline");
    
}

void text_hscroll_line( Environment * _environment, int _direction ) {

    Variable * y = variable_retrieve( _environment, "windowCY" );
    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA $26" );
    outline1("LDA %s", y->realName );
    outline0("STA $31");

    if ( !_environment->textHScrollLineDeployed ) {

        Variable * colormapAddress = variable_retrieve( _environment, "colormapAddress" );
        Variable * textAddress = variable_retrieve( _environment, "textAddress" );

        outline0("JMP lib_text_hscroll_line_after");

        outhead0("lib_text_hscroll_line:" );

        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");

        // Use the current bitmap address as starting address for filling routine.
        outline1("LDA %s", textAddress->realName);
        outline0("STA $22");
        outline1("LDA %s+1", textAddress->realName);
        outline0("STA $23");
        outline1("LDA %s", colormapAddress->realName );
        outline0("STA $29");
        outline1("LDA %s+1", colormapAddress->realName );
        outline0("STA $2a");
 
        outline0("LDX $31" ); // y
        outline0("BEQ lib_text_hscroll_line_skip" );
        outhead0("lib_text_hscroll_line_loop1:" );
        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC $22");
        outline0("STA $22");
        outline0("LDA #0"); // width (hi)
        outline0("ADC $23");
        outline0("STA $23");
        outline0("DEX" );
        outline0("BNE lib_text_hscroll_line_loop1" );

        outline0("LDX $31" ); // y
        outhead0("lib_text_hscroll_line_loopc1:" );
        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC $29");
        outline0("STA $29");
        outline0("LDA #0"); // width (hi)
        outline0("ADC $2a");
        outline0("STA $2a");
        outline0("DEX" );
        outline0("BNE lib_text_hscroll_line_loopc1" );

        outhead0("lib_text_hscroll_line_skip:");
        outline0("LDA $22");
        outline0("STA $24");
        outline0("LDA $23");
        outline0("STA $25");

        outline0("CLC");
        outline0("LDA #1");
        outline0("ADC $24");
        outline0("STA $24");
        outline0("LDA #0");
        outline0("ADC $25");
        outline0("STA $25");

        outline0("LDA $26");
        outline0("CMP #$80");
        outline0("BCC lib_text_hscroll_line_right");

        outhead0("lib_text_hscroll_line_left:");
        outline0("LDY #0");
        outhead0("lib_text_hscroll_line_left_loop:");
        outline0("LDA ($24),Y");
        outline0("STA ($22),Y");
        outline0("INY");
        outline0("CPY #39");
        outline0("BNE lib_text_hscroll_line_left_loop");
        outline0("LDA #32");
        outline0("STA ($22),Y");
        outline0("RTS");

        outhead0("lib_text_hscroll_line_right:");
        outline0("CLC");
        outline0("LDA #1");
        outline0("ADC $24");
        outline0("STA $24");
        outline0("LDA #0");
        outline0("ADC $25");
        outline0("STA $25");
        outline0("LDY #40");
        outhead0("lib_text_hscroll_line_right_loop:");
        outline0("LDA ($22),Y");
        outline0("STA ($24),Y");
        outline0("DEY");
        outline0("CPY #0");
        outline0("BNE lib_text_hscroll_line_right_loop");
        outline0("LDA #32");
        outline0("STA ($24),Y");
        outline0("RTS");

        outhead0("lib_text_hscroll_line_after:");

        _environment->textHScrollLineDeployed = 1;

    }

    outline0("JSR lib_text_hscroll_line");
    
}

void text_hscroll_screen( Environment * _environment, int _direction ) {

    outline1("LDA #$%2.2x", ( _direction & 0xff ) );
    outline0("STA $26" );

    if ( !_environment->textHScrollScreenDeployed ) {

        Variable * colormapAddress = variable_retrieve( _environment, "colormapAddress" );
        Variable * textAddress = variable_retrieve( _environment, "textAddress" );

        outline0("JMP lib_text_hscroll_screen_after");

        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");

        outline0("lib_text_hscroll_screen:");

        // Use the current bitmap address as starting address for filling routine.
        outline1("LDA %s", textAddress->realName);
        outline0("STA $22");
        outline1("LDA %s+1", textAddress->realName);
        outline0("STA $23");
        outline1("LDA %s", colormapAddress->realName );
        outline0("STA $29");
        outline1("LDA %s+1", colormapAddress->realName );
        outline0("STA $2a");
 
        outline0("LDX #24" ); // y

        outline0("LDA $22");
        outline0("STA $24");
        outline0("LDA $23");
        outline0("STA $25");

        outline0("CLC");
        outline0("LDA #1");
        outline0("ADC $24");
        outline0("STA $24");
        outline0("LDA #0");
        outline0("ADC $25");
        outline0("STA $25");

        outhead0("lib_text_hscroll_screen_loop:")
        outline0("LDA $26");
        outline0("CMP #$80");
        outline0("BCC lib_text_hscroll_screen_right");

        outhead0("lib_text_hscroll_screen_left:");
        outline0("LDY #0");
        outhead0("lib_text_hscroll_screen_left_loop:");
        outline0("LDA ($24),Y");
        outline0("STA ($22),Y");
        outline0("INY");
        outline0("CPY #39");
        outline0("BNE lib_text_hscroll_screen_left_loop");
        outline0("LDA #32");
        outline0("STA ($22),Y");
        outline0("JMP lib_text_hscroll_screen_next_line");

        outhead0("lib_text_hscroll_screen_right:");
        outline0("CLC");
        outline0("LDA #1");
        outline0("ADC $24");
        outline0("STA $24");
        outline0("LDA #0");
        outline0("ADC $25");
        outline0("STA $25");
        outline0("LDY #40");
        outhead0("lib_text_hscroll_screen_right_loop:");
        outline0("LDA ($22),Y");
        outline0("STA ($24),Y");
        outline0("DEY");
        outline0("CPY #0");
        outline0("BNE lib_text_hscroll_screen_right_loop");
        outline0("LDA #32");
        outline0("STA ($24),Y");

        outhead0("lib_text_hscroll_screen_next_line:")

        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC $22");
        outline0("STA $22");
        outline0("LDA #0"); // width (hi)
        outline0("ADC $23");
        outline0("STA $23");

        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC $24");
        outline0("STA $24");
        outline0("LDA #0"); // width (hi)
        outline0("ADC $25");
        outline0("STA $25");

        outline0("DEX");
        outline0("BNE lib_text_hscroll_screen_loop");
        outline0("RTS");

        outhead0("lib_text_hscroll_screen_after:");

        _environment->textHScrollScreenDeployed = 1;

    }

    outline0("JSR lib_text_hscroll_screen");
    
}

Variable * text_get_pen( Environment * _environment, char * _color ) {
    
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_WHITE );

    Variable * result = variable_temporary( _environment, VT_STRING, 0 );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x1 " );
    char stringAddress[MAX_TEMPORARY_STORAGE]; sprintf( stringAddress, "%s+1", result->realName );

    variable_store_string(_environment, result->name, resultString );

    cpu_move_8bit_indirect_with_offset(_environment, color->realName, stringAddress, 1 );
        
    return result;

}

Variable * text_get_paper( Environment * _environment, char * _color ) {
    
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_BLACK );

    Variable * result = variable_temporary( _environment, VT_STRING, 0 );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x2 " );
    char stringAddress[MAX_TEMPORARY_STORAGE]; sprintf( stringAddress, "%s+1", result->realName );

    variable_store_string(_environment, result->name, resultString );

    cpu_move_8bit_indirect_with_offset(_environment, color->realName, stringAddress, 1 );
        
    return result;

}


Variable * text_get_at( Environment * _environment, char * _x, char * _y ) {
    
    Variable * x = variable_retrieve_or_define( _environment, _x, VT_BYTE, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_BYTE, 0 );

    Variable * result = variable_temporary( _environment, VT_STRING, 0 );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x4  " );
    char stringAddress[MAX_TEMPORARY_STORAGE]; sprintf( stringAddress, "%s+1", result->realName );

    variable_store_string(_environment, result->name, resultString );

    cpu_move_8bit_indirect_with_offset(_environment, x->realName, stringAddress, 1 );
    cpu_move_8bit_indirect_with_offset(_environment, y->realName, stringAddress, 2 );
        
    return result;

}