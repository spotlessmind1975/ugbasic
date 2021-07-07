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
