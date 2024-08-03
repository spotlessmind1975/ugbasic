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

void begin_compilation( Environment * _environment ) {

    _environment->asmFile = fopen( _environment->asmFileName, "wt");
    if ( ! _environment->asmFile ) {
        fprintf(stderr, "Unable to open output file: %s\n", _environment->asmFileName );
        exit(EXIT_FAILURE);
    }

    if ( _environment->debuggerLabelsFileName ) {
        _environment->debuggerLabelsFile = fopen( _environment->debuggerLabelsFileName, "wt");
        if ( ! _environment->debuggerLabelsFile ) {
            fprintf(stderr, "Unable to open labels file: %s\n", _environment->debuggerLabelsFileName );
            exit(EXIT_FAILURE);
        }
    }

    target_initialization( _environment );

}

void setup_text_variables( Environment * _environment ) {

    variable_import( _environment, "XCURSYS", VT_SBYTE, 0 );
    variable_global( _environment, "XCURSYS" );
    variable_store( _environment, "XCURSYS", 0 );
    variable_import( _environment, "YCURSYS", VT_SBYTE, 0 );
    variable_global( _environment, "YCURSYS" );
    variable_store( _environment, "YCURSYS", 0 );
    variable_define( _environment, "PEN", VT_COLOR, DEFAULT_PEN_COLOR );
    variable_global( _environment, "PEN" );
    variable_define( _environment, "PAPER", VT_COLOR, DEFAULT_PAPER_COLOR );
    variable_global( _environment, "PAPER" );
    variable_define( _environment, "SBINK0", VT_COLOR, DEFAULT_PEN_COLOR );
    variable_global( _environment, "SBINK0" );
    variable_define( _environment, "SBINK1", VT_COLOR, DEFAULT_PEN_COLOR );
    variable_global( _environment, "SBINK1" );
    variable_define( _environment, "SBINK2", VT_COLOR, DEFAULT_PEN_COLOR );
    variable_global( _environment, "SBINK2" );
    variable_define( _environment, "SBINK3", VT_COLOR, DEFAULT_PEN_COLOR );
    variable_global( _environment, "SBINK3" );
    variable_import( _environment, "DRAWSCALE", VT_BYTE, 4 );
    variable_global( _environment, "DRAWSCALE" );
    variable_import( _environment, "DRAWANGLE", VT_BYTE, 0 );
    variable_global( _environment, "DRAWANGLE" );
    
    variable_import( _environment, "DRAWUCOMMAND", VT_CHAR, 'U' );
    variable_global( _environment, "DRAWUCOMMAND" );
    variable_import( _environment, "DRAWDCOMMAND", VT_CHAR, 'D' );
    variable_global( _environment, "DRAWDCOMMAND" );
    variable_import( _environment, "DRAWLCOMMAND", VT_CHAR, 'L' );
    variable_global( _environment, "DRAWLCOMMAND" );
    variable_import( _environment, "DRAWRCOMMAND", VT_CHAR, 'R' );
    variable_global( _environment, "DRAWRCOMMAND" );
    variable_import( _environment, "DRAWECOMMAND", VT_CHAR, 'E' );
    variable_global( _environment, "DRAWECOMMAND" );
    variable_import( _environment, "DRAWFCOMMAND", VT_CHAR, 'F' );
    variable_global( _environment, "DRAWFCOMMAND" );
    variable_import( _environment, "DRAWGCOMMAND", VT_CHAR, 'G' );
    variable_global( _environment, "DRAWGCOMMAND" );
    variable_import( _environment, "DRAWHCOMMAND", VT_CHAR, 'H' );
    variable_global( _environment, "DRAWHCOMMAND" );

    variable_import( _environment, "DRAWUDCOMMAND", VT_CHAR, 'x' );
    variable_global( _environment, "DRAWUDCOMMAND" );
    variable_import( _environment, "DRAWDDCOMMAND", VT_CHAR, 'x' );
    variable_global( _environment, "DRAWDDCOMMAND" );
    variable_import( _environment, "DRAWLDCOMMAND", VT_CHAR, 'x' );
    variable_global( _environment, "DRAWLDCOMMAND" );
    variable_import( _environment, "DRAWRDCOMMAND", VT_CHAR, 'x' );
    variable_global( _environment, "DRAWRDCOMMAND" );
    variable_import( _environment, "DRAWEDCOMMAND", VT_CHAR, 'x' );
    variable_global( _environment, "DRAWEDCOMMAND" );
    variable_import( _environment, "DRAWFDCOMMAND", VT_CHAR, 'x' );
    variable_global( _environment, "DRAWFDCOMMAND" );
    variable_import( _environment, "DRAWGDCOMMAND", VT_CHAR, 'x' );
    variable_global( _environment, "DRAWGDCOMMAND" );
    variable_import( _environment, "DRAWHDCOMMAND", VT_CHAR, 'x' );
    variable_global( _environment, "DRAWHDCOMMAND" );

    variable_define( _environment, "TAB", VT_STRING, 0 );
    variable_store_string( _environment, "TAB", "\t");
    variable_global( _environment, "TAB" );
    variable_import( _environment, "PROTOTHREADCT", VT_BYTE, 0 );
    variable_global( _environment, "PROTOTHREADCT" );
    variable_import( _environment, "CPURANDOM_SEED", VT_DWORD, 0xffeaff42 );
    variable_global( _environment, "CPURANDOM_SEED" );
    variable_import( _environment, "PLAYDURATION", VT_BYTE, 64 );
    variable_global( _environment, "PLAYDURATION" );
    variable_import( _environment, "PLAYOCTAVE", VT_BYTE, 2 );
    variable_global( _environment, "PLAYOCTAVE" );
    variable_import( _environment, "PLAYTEMPO", VT_BYTE, 2 );
    variable_global( _environment, "PLAYTEMPO" );
    variable_import( _environment, "PLAYVOLUME", VT_BYTE, 15 );
    variable_global( _environment, "PLAYVOLUME" );

    variable_import( _environment, "XCURSYS", VT_SBYTE, 0 );
    variable_global( _environment, "XCURSYS" );
    variable_import( _environment, "YCURSYS", VT_SBYTE, 0 );
    variable_global( _environment, "YCURSYS" );

    variable_import( _environment, "CONSOLEID", VT_SBYTE, 0xff );
    variable_global( _environment, "CONSOLEID" );

    variable_import( _environment, "CONSOLEX1", VT_SBYTE, 0 );
    variable_global( _environment, "CONSOLEX1" );
    variable_import( _environment, "CONSOLEY1", VT_SBYTE, 0 );
    variable_global( _environment, "CONSOLEY1" );
    variable_import( _environment, "CONSOLEX2", VT_SBYTE, 0 );
    variable_global( _environment, "CONSOLEX2" );
    variable_import( _environment, "CONSOLEY2", VT_SBYTE, 0 );
    variable_global( _environment, "CONSOLEY2" );
    variable_import( _environment, "CONSOLEW", VT_SBYTE, 0 );
    variable_global( _environment, "CONSOLEW" );
    variable_import( _environment, "CONSOLEH", VT_SBYTE, 0 );
    variable_global( _environment, "CONSOLEH" );
    variable_import( _environment, "CONSOLESL", VT_SWORD, 0 );
    variable_global( _environment, "CONSOLESL" );

    variable_import( _environment, "CONSOLES", VT_BUFFER, MAX_CONSOLES * 8 );
    variable_global( _environment, "CONSOLES" );
    variable_import( _environment, "CONSOLES2", VT_BUFFER, MAX_CONSOLES * 2 );
    variable_global( _environment, "CONSOLES2" );

}

void finalize_text_variables( Environment * _environment ) {

    if ( _environment->deployed.draw_string ) {
        variable_export( _environment, "DRAWSCALE", VT_BYTE, 4 );
        variable_export( _environment, "DRAWANGLE", VT_BYTE, 0 );
        variable_export( _environment, "DRAWUCOMMAND", VT_CHAR, 'U' );
        variable_export( _environment, "DRAWDCOMMAND", VT_CHAR, 'D' );
        variable_export( _environment, "DRAWLCOMMAND", VT_CHAR, 'L' );
        variable_export( _environment, "DRAWRCOMMAND", VT_CHAR, 'R' );
        variable_export( _environment, "DRAWECOMMAND", VT_CHAR, 'E' );
        variable_export( _environment, "DRAWFCOMMAND", VT_CHAR, 'F' );
        variable_export( _environment, "DRAWGCOMMAND", VT_CHAR, 'G' );
        variable_export( _environment, "DRAWHCOMMAND", VT_CHAR, 'H' );

        variable_export( _environment, "DRAWUDCOMMAND", VT_CHAR, 'x' );
        variable_export( _environment, "DRAWDDCOMMAND", VT_CHAR, 'x' );
        variable_export( _environment, "DRAWLDCOMMAND", VT_CHAR, 'x' );
        variable_export( _environment, "DRAWRDCOMMAND", VT_CHAR, 'x' );
        variable_export( _environment, "DRAWEDCOMMAND", VT_CHAR, 'x' );
        variable_export( _environment, "DRAWFDCOMMAND", VT_CHAR, 'x' );
        variable_export( _environment, "DRAWGDCOMMAND", VT_CHAR, 'x' );
        variable_export( _environment, "DRAWHDCOMMAND", VT_CHAR, 'x' );

        variable_export( _environment, "DRAWSCALE", VT_BYTE, 4 );
        variable_export( _environment, "DRAWANGLE", VT_BYTE, 0 );

    }

    if ( _environment->deployed.draw_tsb_string ) {
        variable_export( _environment, "DRAWSCALE", VT_BYTE, 4 );
        variable_export( _environment, "DRAWANGLE", VT_BYTE, 0 );
        variable_export( _environment, "DRAWUCOMMAND", VT_CHAR, '1' );
        variable_store( _environment, "DRAWUCOMMAND", '1' );
        variable_export( _environment, "DRAWDCOMMAND", VT_CHAR, '2' );
        variable_store( _environment, "DRAWDCOMMAND", '2' );
        variable_export( _environment, "DRAWLCOMMAND", VT_CHAR, '3' );
        variable_store( _environment, "DRAWLCOMMAND", '3' );
        variable_export( _environment, "DRAWRCOMMAND", VT_CHAR, '0' );
        variable_store( _environment, "DRAWRCOMMAND", '0' );
        variable_export( _environment, "DRAWECOMMAND", VT_CHAR, 'x' );
        variable_store( _environment, "DRAWECOMMAND", 'x' );
        variable_export( _environment, "DRAWFCOMMAND", VT_CHAR, 'x' );
        variable_store( _environment, "DRAWFCOMMAND", 'x' );
        variable_export( _environment, "DRAWGCOMMAND", VT_CHAR, 'x' );
        variable_store( _environment, "DRAWGCOMMAND", 'x' );
        variable_export( _environment, "DRAWHCOMMAND", VT_CHAR, 'x' );
        variable_store( _environment, "DRAWHCOMMAND", 'x' );

        variable_export( _environment, "DRAWUDCOMMAND", VT_CHAR, '6' );
        variable_store( _environment, "DRAWUDCOMMAND", '6' );
        variable_export( _environment, "DRAWDDCOMMAND", VT_CHAR, '7' );
        variable_store( _environment, "DRAWDDCOMMAND", '7' );
        variable_export( _environment, "DRAWLDCOMMAND", VT_CHAR, '8' );
        variable_store( _environment, "DRAWLDCOMMAND", '8' );
        variable_export( _environment, "DRAWRDCOMMAND", VT_CHAR, '0' );
        variable_store( _environment, "DRAWRDCOMMAND", '0' );
        variable_export( _environment, "DRAWEDCOMMAND", VT_CHAR, 'x' );
        variable_store( _environment, "DRAWEDCOMMAND", 'x' );
        variable_export( _environment, "DRAWFDCOMMAND", VT_CHAR, 'x' );
        variable_store( _environment, "DRAWFDCOMMAND", 'x' );
        variable_export( _environment, "DRAWGDCOMMAND", VT_CHAR, 'x' );
        variable_store( _environment, "DRAWGDCOMMAND", 'x' );
        variable_export( _environment, "DRAWHDCOMMAND", VT_CHAR, 'x' );
        variable_store( _environment, "DRAWHDCOMMAND", 'x' );

        variable_export( _environment, "DRAWSCALE", VT_BYTE, 1 );
        variable_store( _environment, "DRAWSCALE", 1 );
        variable_export( _environment, "DRAWANGLE", VT_BYTE, 0 );
        variable_store( _environment, "DRAWANGLE", 0 );

    }

    if ( _environment->deployed.play_string ) {
        variable_export( _environment, "PLAYDURATION", VT_BYTE, 64 );
        variable_export( _environment, "PLAYOCTAVE", VT_BYTE, 2 );
        variable_export( _environment, "PLAYTEMPO", VT_BYTE, 2 );
        variable_export( _environment, "PLAYVOLUME", VT_BYTE, 15 );
    }

}