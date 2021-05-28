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
 * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../ugbc.h"

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#ifdef __zx__

void zx_color_border( Environment * _environment, char * _color ) {

    char port[MAX_TEMPORARY_STORAGE]; sprintf(port, "$%2.2x", PORT_COLOR_BORDER);

    z80_port_out( _environment, port, _color );

}

void zx_vscroll( Environment * _environment, int _displacement ) {

    outline1("LD A, $%2.2x", ( _displacement & 0xff ) );

    deploy( varsDeployed,"./ugbc/src/hw/zx/vars.asm" );
    deploy( vScrollDeployed,"./ugbc/src/hw/zx/vscroll.asm" );

    outline0("CALL VSCROLL");

}

void zx_text_at( Environment * _environment, char * _x, char * _y, char * _text, char * _text_size, char * _pen, char * _paper, char * _ww ) {

    deploy( varsDeployed,"./ugbc/src/hw/zx/vars.asm" );
    deploy( vScrollDeployed, "./ugbc/src/hw/zx/vscroll.asm" );
    deploy( textEncodedAtDeployed, "./ugbc/src/hw/zx/text_at.asm" );

    z80_move_8bit( _environment, _x, "XCURS");
    z80_move_8bit( _environment, _y, "YCURS");
    z80_move_8bit( _environment, _pen, "LOCALPEN");
    z80_move_8bit( _environment, _paper, "LOCALPAPER");
    z80_move_8bit( _environment, _ww, "LOCALWW");
    // z80_move_8bit( _environment, _tab, "TABCOUNT");

    outline1("LD A, (%s)", _text_size );
    outline0("LD C, A");
    outline0("LD B, 0");
    outline1("LD HL, (%s)", _text );
    outline0("CALL TEXTAT");

    z80_move_8bit( _environment, "XCURS", _x );
    z80_move_8bit( _environment, "YCURS", _y );

}

void zx_cls( Environment * _environment, char * _pen, char * _paper ) {

    deploy( varsDeployed,"./ugbc/src/hw/zx/vars.asm" );
    deploy( clsDeployed, "./ugbc/src/hw/zx/cls.asm" );

    if ( _pen ) {
        z80_move_8bit( _environment, _pen, "LOCALPEN");
    }
    if ( _paper ) {
        z80_move_8bit( _environment, _paper, "LOCALPAPER");
    }

    outline0("LD A, 0");
    outline0("CALL CLS");

}

#endif