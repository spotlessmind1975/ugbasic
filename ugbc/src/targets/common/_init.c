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
    variable_define( _environment, "DRAWSCALE", VT_BYTE, 4 );
    variable_global( _environment, "DRAWSCALE" );
    variable_define( _environment, "DRAWANGLE", VT_BYTE, 0 );
    variable_global( _environment, "DRAWANGLE" );
    variable_define( _environment, "DRAWUCOMMAND", VT_CHAR, 'U' );
    variable_global( _environment, "DRAWUCOMMAND" );
    variable_define( _environment, "DRAWDCOMMAND", VT_CHAR, 'D' );
    variable_global( _environment, "DRAWDCOMMAND" );
    variable_define( _environment, "DRAWLCOMMAND", VT_CHAR, 'L' );
    variable_global( _environment, "DRAWLCOMMAND" );
    variable_define( _environment, "DRAWRCOMMAND", VT_CHAR, 'R' );
    variable_global( _environment, "DRAWRCOMMAND" );
    variable_define( _environment, "DRAWECOMMAND", VT_CHAR, 'E' );
    variable_global( _environment, "DRAWECOMMAND" );
    variable_define( _environment, "DRAWFCOMMAND", VT_CHAR, 'F' );
    variable_global( _environment, "DRAWFCOMMAND" );
    variable_define( _environment, "DRAWGCOMMAND", VT_CHAR, 'G' );
    variable_global( _environment, "DRAWGCOMMAND" );
    variable_define( _environment, "DRAWHCOMMAND", VT_CHAR, 'H' );
    variable_global( _environment, "DRAWHCOMMAND" );
    variable_define( _environment, "windowE", VT_BYTE, 0 );
    variable_global( _environment, "windowE" );
    variable_define( _environment, "windowS", VT_BYTE, 0 );
    variable_global( _environment, "windowS" );
    variable_define( _environment, "windowW", VT_BYTE, 0 );
    variable_global( _environment, "windowW" );
    variable_define( _environment, "TAB", VT_STRING, 0 );
    variable_store_string( _environment, "TAB", "\t");
    variable_global( _environment, "TAB" );
    variable_define( _environment, "windowMX", VT_SBYTE, 0 );
    variable_global( _environment, "windowMX" );
    variable_define( _environment, "windowMY", VT_SBYTE, 0 );                
    variable_global( _environment, "windowMY" );
    variable_import( _environment, "PROTOTHREADCT", VT_BYTE, 0 );
    variable_global( _environment, "PROTOTHREADCT" );
    variable_import( _environment, "CPURANDOM_SEED", VT_DWORD, 0xffffffff );
    variable_global( _environment, "CPURANDOM_SEED" );
    variable_define( _environment, "PLAYDURATION", VT_BYTE, 64 );
    variable_global( _environment, "PLAYDURATION" );
    variable_define( _environment, "PLAYOCTAVE", VT_BYTE, 2 );
    variable_global( _environment, "PLAYOCTAVE" );
    variable_define( _environment, "PLAYTEMPO", VT_BYTE, 2 );
    variable_global( _environment, "PLAYTEMPO" );
    variable_define( _environment, "PLAYVOLUME", VT_BYTE, 15 );
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

    console_init( _environment );

}