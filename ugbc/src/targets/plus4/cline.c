/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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

@target plus4
</usermanual> */
void cline( Environment * _environment, char * _characters ) {

    Variable * characters = NULL;
    if ( _characters ) {
        characters = variable_retrieve( _environment, _characters );
        outline1("LDA %s", characters->realName);
    } else {
        outline0("LDA #0");
    }
    outline0("STA CHARACTERS");

    if ( !_environment->deployed.textCline ) {

        Variable * colormapAddress = variable_retrieve( _environment, "COLORMAPADDRESS" );
        Variable * TEXTADDRESS = variable_retrieve( _environment, "TEXTADDRESS" );
        Variable * x = variable_retrieve( _environment, "XCURSYS" );
        Variable * y = variable_retrieve( _environment, "YCURSYS" );

        outline0("JMP lib_cline_after");

        outline0("lib_cline:");
        outline1("LDA %s", x->realName );
        outline0("STA CLINEX" );
        outline1("LDA %s", y->realName );
        outline0("STA CLINEY");

        // Use the current bitmap address as starting address for filling routine.
        outline1("LDA %s", TEXTADDRESS->realName);
        outline0("STA COPYOFTEXTADDRESS");
        outline1("LDA %s", address_displacement(_environment, TEXTADDRESS->realName, "1"));
        outline0("STA COPYOFTEXTADDRESS+1");
        outline1("LDA %s", colormapAddress->realName );
        outline0("STA COPYOFCOLORMAPADDRESS");
        outline1("LDA %s", address_displacement(_environment, colormapAddress->realName, "1") );
        outline0("STA COPYOFCOLORMAPADDRESS+1");
 
        outline0("LDX CLINEY" ); // y
        outline0("BEQ lib_cline_skip" );
        outhead0("lib_cline_loop1:" );
        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC COPYOFTEXTADDRESS");
        outline0("STA COPYOFTEXTADDRESS");
        outline0("LDA #0"); // width (hi)
        outline0("ADC COPYOFTEXTADDRESS+1");
        outline0("STA COPYOFTEXTADDRESS+1");
        outline0("DEX" );
        outline0("BNE lib_cline_loop1" );

        outline0("LDX CLINEY" ); // y
        outhead0("lib_cline_loopc1:" );
        outline0("CLC"); // x
        outline0("LDA #40"); // width (lo)
        outline0("ADC COPYOFCOLORMAPADDRESS");
        outline0("STA COPYOFCOLORMAPADDRESS");
        outline0("LDA #0"); // width (hi)
        outline0("ADC COPYOFCOLORMAPADDRESS+1");
        outline0("STA COPYOFCOLORMAPADDRESS+1");
        outline0("DEX" );
        outline0("BNE lib_cline_loopc1" );

        outhead0("lib_cline_skip:" );

        outline0("LDA CHARACTERS");
        outline0("BEQ lib_cline_entire_line");

        outline0("CLC"); // x
        outline0("LDA CLINEX"); // x
        outline0("ADC COPYOFTEXTADDRESS");
        outline0("STA COPYOFTEXTADDRESS");
        outline0("LDA #0");
        outline0("ADC COPYOFTEXTADDRESS+1");
        outline0("STA COPYOFTEXTADDRESS+1");

        outline0("CLC"); // x
        outline0("LDA CLINEX"); // x
        outline0("ADC COPYOFCOLORMAPADDRESS");
        outline0("STA COPYOFCOLORMAPADDRESS");
        outline0("LDA #0");
        outline0("ADC COPYOFCOLORMAPADDRESS+1");
        outline0("STA COPYOFCOLORMAPADDRESS+1");

        outline0("LDX CHARACTERS");
        outline0("LDY #0");


        outhead0("lib_cline_increment_x:");
        outline0("LDA #32");
        outline0("STA (COPYOFTEXTADDRESS),y");
        
        outline0("INC CLINEX"); // x
        outline0("LDA CLINEX"); // x
        outline0("CMP #40"); // x
        outline0("BNE lib_cline_next"); // x
        outline0("LDA #0"); // x
        outline0("STA CLINEX"); // x
        outline0("INC CLINEY"); // y
        outline0("LDA CLINEY"); // y
        outline0("CMP #24"); // h
        outline0("BNE lib_cline_next"); // x

        text_vscroll_screen( _environment, -1 );

        outline0("DEC CLINEY"); // y
        outline0("SEC");
        outline0("LDA COPYOFTEXTADDRESS");
        outline0("SBC #40");
        outline0("STA COPYOFTEXTADDRESS");
        outline0("LDA COPYOFTEXTADDRESS+1");
        outline0("SBC #0");
        outline0("STA COPYOFTEXTADDRESS+1");

        outline0("SEC");
        outline0("LDA COPYOFCOLORMAPADDRESS");
        outline0("SBC #40");
        outline0("STA COPYOFCOLORMAPADDRESS");
        outline0("LDA COPYOFCOLORMAPADDRESS+1");
        outline0("SBC #0");
        outline0("STA COPYOFCOLORMAPADDRESS+1");
 
        outline0("lib_cline_next:");
        outline0("INY");
        outline0("DEX");
        outline0("BNE lib_cline_increment_x");
        outline0("RTS");

        outhead0("lib_cline_entire_line:");

        outline0("LDY #0");

        outhead0("lib_cline_increment2_x:");

        outline0("LDA #32");
        outline0("STA (COPYOFTEXTADDRESS),y");
        
        outline0("INY"); // x
        outline0("INC CLINEX"); // x
        outline0("LDA CLINEX"); // x
        outline0("CMP #40"); // x
        outline0("BNE lib_cline_increment2_x"); // x
        outline0("RTS");

        outhead0("lib_cline_after:");

        _environment->deployed.textCline = 1;

    }

    outline0("JSR lib_cline");
    
}
