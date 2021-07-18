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
 * @brief Emit code for <strong>CLINE ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _characters Characters to remove
 */
/* <usermanual>
@keyword CLINE

@english
The ''CLINE'' command is used to clear the line currently occupied by the text 
cursor. If ''CLINE'' is followed by a number, then that number of characters
get cleared, starting from the current cursor position and leaving the cursor 
exactly where it is. 

@italian
Il comando ''CLINE'' viene utilizzato per cancellare la riga attualmente 
occupata dal cursore. Se ''CLINE'' è seguito da un numero, quel numero 
di caratteri sarà cancellato, a partire dalla posizione corrente del 
cursore e lasciando il cursore esattamente dove si trova.

@syntax CLINE {[expression]}

@example CLINE

@usedInExample texts_position_01.bas
@usedInExample texts_position_02.bas

@target c64
</usermanual> */
void cline( Environment * _environment, char * _characters ) {

    Variable * characters = NULL;
    if ( _characters ) {
        characters = variable_retrieve( _environment, _characters );
        outline1("LDA %s", characters->realName);
    } else {
        outline0("LDA #0");
    }
    outline0("STA $25");

    if ( !_environment->textClineDeployed ) {

        Variable * colormapAddress = variable_retrieve( _environment, "COLORMAPADDRESS" );
        Variable * TEXTADDRESS = variable_retrieve( _environment, "TEXTADDRESS" );
        Variable * x = variable_retrieve( _environment, "windowCX" );
        Variable * y = variable_retrieve( _environment, "windowCY" );

        outline0("JMP lib_cline_after");

        outline0("lib_cline:");
        outline1("LDA %s", x->realName );
        outline0("STA $30" );
        outline1("LDA %s", y->realName );
        outline0("STA $31");

        // Use the current bitmap address as starting address for filling routine.
        outline1("LDA %s", TEXTADDRESS->realName);
        outline0("STA COPYTEXTADDRESS");
        outline1("LDA %s+1", TEXTADDRESS->realName);
        outline0("STA COPYTEXTADDRESS+1");
        outline1("LDA %s", colormapAddress->realName );
        outline0("STA COPYCOLORMAPADDRESS");
        outline1("LDA %s+1", colormapAddress->realName );
        outline0("STA COPYCOLORMAPADDRESS+1");
 
        outline0("LDX $31" ); // y
        outline0("BEQ lib_cline_skip" );
        outhead0("lib_cline_loop1:" );
        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC COPYTEXTADDRESS");
        outline0("STA COPYTEXTADDRESS");
        outline0("LDA #0"); // width (hi)
        outline0("ADC COPYTEXTADDRESS+1");
        outline0("STA COPYTEXTADDRESS+1");
        outline0("DEX" );
        outline0("BNE lib_cline_loop1" );

        outline0("LDX $31" ); // y
        outhead0("lib_cline_loopc1:" );
        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC COPYCOLORMAPADDRESS");
        outline0("STA COPYCOLORMAPADDRESS");
        outline0("LDA #0"); // width (hi)
        outline0("ADC COPYCOLORMAPADDRESS+1");
        outline0("STA COPYCOLORMAPADDRESS+1");
        outline0("DEX" );
        outline0("BNE lib_cline_loopc1" );

        outhead0("lib_cline_skip:" );

        outline0("LDA $25");
        outline0("BEQ lib_cline_entire_line");

        outline0("CLC"); // x
        outline0("LDA $30"); // x
        outline0("ADC COPYTEXTADDRESS");
        outline0("STA COPYTEXTADDRESS");
        outline0("LDA #0");
        outline0("ADC COPYTEXTADDRESS+1");
        outline0("STA COPYTEXTADDRESS+1");

        outline0("CLC"); // x
        outline0("LDA $30"); // x
        outline0("ADC COPYCOLORMAPADDRESS");
        outline0("STA COPYCOLORMAPADDRESS");
        outline0("LDA #0");
        outline0("ADC COPYCOLORMAPADDRESS+1");
        outline0("STA COPYCOLORMAPADDRESS+1");

        outline0("LDX $25");
        outline0("LDY #0");


        outhead0("lib_cline_increment_x:");
        outline0("LDA #32");
        outline0("STA (COPYTEXTADDRESS),y");
        
        outline0("INC $30"); // x
        outline0("LDA $30"); // x
        outline0("CMP #40"); // x
        outline0("BNE lib_cline_next"); // x
        outline0("LDA #0"); // x
        outline0("STA $30"); // x
        outline0("INC $31"); // y
        outline0("LDA $31"); // y
        outline0("CMP #24"); // h
        outline0("BNE lib_cline_next"); // x

        text_vscroll_screen( _environment, -1 );

        outline0("DEC $31"); // y
        outline0("SEC");
        outline0("LDA COPYTEXTADDRESS");
        outline0("SBC #40");
        outline0("STA COPYTEXTADDRESS");
        outline0("LDA COPYTEXTADDRESS+1");
        outline0("SBC #0");
        outline0("STA COPYTEXTADDRESS+1");

        outline0("SEC");
        outline0("LDA COPYCOLORMAPADDRESS");
        outline0("SBC #40");
        outline0("STA COPYCOLORMAPADDRESS");
        outline0("LDA COPYCOLORMAPADDRESS+1");
        outline0("SBC #0");
        outline0("STA COPYCOLORMAPADDRESS+1");
 
        outline0("lib_cline_next:");
        outline0("INY");
        outline0("DEX");
        outline0("BNE lib_cline_increment_x");
        outline0("RTS");

        outhead0("lib_cline_entire_line:");

        outline0("LDY #0");

        outhead0("lib_cline_increment2_x:");

        outline0("LDA #32");
        outline0("STA (COPYTEXTADDRESS),y");
        
        outline0("INY"); // x
        outline0("INC $30"); // x
        outline0("LDA $30"); // x
        outline0("CMP #40"); // x
        outline0("BNE lib_cline_increment2_x"); // x
        outline0("RTS");

        outhead0("lib_cline_after:");

        _environment->textClineDeployed = 1;

    }

    outline0("JSR lib_cline");
    
}
