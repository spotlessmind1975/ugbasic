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

        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");
        outline0("NOP");

        outhead0("lib_text_encoded_at:");
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

        outline0("CMP #09");
        outline0("BEQ lib_text_encoded_at_tab");

        outline0("CMP #01");
        outline0("BEQ lib_text_encoded_at_pen");

        outline0("CMP #02");
        outline0("BEQ lib_text_encoded_at_paper");

        outline0("CMP #32");
        outline0("BCC lib_text_encoded_at_sp128");
        outline0("CMP #64");
        outline0("BCC lib_text_encoded_at_sp0");
        outline0("CMP #96");
        outline0("BCC lib_text_encoded_at_sm64");
        outline0("CMP #160");
        outline0("BCC lib_text_encoded_at_sp64");
        outline0("CMP #192");
        outline0("BCC lib_text_encoded_at_sm64");
        outline0("CMP #224");
        outline0("BCC lib_text_encoded_at_sm128");
        outline0("JMP lib_text_encoded_at_sp0");
        outhead0("lib_text_encoded_at_sp64:");
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
        outline0("STA $25");
        outline0("TXA");
        outline0("ADC $25");
        outline0("TAX");
        outline0("JMP lib_text_encoded_at_increment_x");

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
        outline0("JMP lib_text_encoded_at_increment_x");

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
        outline0("JMP lib_text_encoded_at_increment_x");

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
        outline0("BNE lib_text_encoded_at_next"); // x
        outline0("LDA #0"); // x
        outline0("STA $d3"); // x
        outline0("INC $d6"); // y
        outline0("LDA $d6"); // y
        outline0("CMP #24"); // h
        outline0("BNE lib_text_encoded_at_next"); // x

        text_vscroll( _environment );

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
        outline0("INY" );
        outline0("DEX" );
        outline0("BEQ lib_text_encoded_at_end" );
        outline0("JMP lib_text_encoded_at_loop2" );
        outline0("lib_text_encoded_at_end:" );
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

void text_vscroll( Environment * _environment ) {

    if ( !_environment->textVScrollDeployed ) {

        Variable * textAddress = variable_retrieve( _environment, "textAddress" );

        outline0("JMP text_vscroll_after");

        outline0("text_vscroll:");
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
        outline0("LDX #3" );
        outline0("LDY #0" );
        outhead0("lib_text_encoded_at_yscroll:");
        outline0("LDA ($27),Y");
        outline0("STA ($25),Y");
        outline0("INY");
        outline0("BNE lib_text_encoded_at_yscroll");
        outline0("INC $26");
        outline0("INC $28");
        outline0("CPX #1");
        outline0("BNE lib_text_encoded_at_nextblock");
        outhead0("lib_text_encoded_at_yscroll2:");
        outline0("LDA ($27),Y");
        outline0("STA ($25),Y");
        outline0("INY");
        outline0("CPY #232");
        outline0("BNE lib_text_encoded_at_yscroll2");
        outhead0("lib_text_encoded_at_nextblock:");
        outline0("DEX");
        outline0("BNE lib_text_encoded_at_yscroll");
        outline0("LDY #192");
        outhead0("lib_text_encoded_at_refill:");
        outline0("LDA #32");
        outline0("STA ($25),Y");
        outline0("INY");
        outline0("CPY #232");
        outline0("BNE lib_text_encoded_at_refill");
        outline0("RTS");

        outline0("text_vscroll_after:");

        _environment->textVScrollDeployed = 1;

    }

    outline0("JSR text_vscroll");

}

void text_paper( Environment * _environment, char * _color ) {

    Variable * paper = variable_retrieve( _environment, "windowPA" );
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_BLACK );

    variable_move( _environment, color->name, paper->name );
    
    vic2_background_color( _environment, "#0", color->realName );
    vic2_border_color( _environment, color->realName );
    
}