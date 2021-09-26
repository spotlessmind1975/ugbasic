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

void target_initialization( Environment * _environment ) {

    MEMORY_AREA_DEFINE( MAT_DIRECT, 0xc000, 0xcfff );

    variable_import( _environment, "BITMAPADDRESS", VT_ADDRESS );
    variable_global( _environment, "BITMAPADDRESS" );
    variable_import( _environment, "COLORMAPADDRESS", VT_ADDRESS );
    variable_global( _environment, "COLORMAPADDRESS" );
    variable_import( _environment, "TEXTADDRESS", VT_ADDRESS );
    variable_global( _environment, "TEXTADDRESS" );    
    variable_import( _environment, "EMPTYTILE", VT_BYTE );
    variable_global( _environment, "EMPTYTILE" );    

    bank_define( _environment, "VARIABLES", BT_VARIABLES, 0x5000, NULL );
    bank_define( _environment, "TEMPORARY", BT_TEMPORARY, 0x5100, NULL );
    variable_import( _environment, "FREE_STRING", VT_WORD );
    variable_global( _environment, "FREE_STRING" );    

    if ( !_environment->configurationFileName ) {
        _environment->configurationFileName = tmpnam(NULL);
    }

    _environment->configurationFile = fopen( _environment->configurationFileName, "wt");

    if ( ! _environment->configurationFile ) {
        fprintf(stderr, "Unable to open configuration file: %s\n", _environment->configurationFileName ? _environment->configurationFileName : "(temporary)" );
        exit(EXIT_FAILURE);
    }

    linker_setup( _environment );

    deploy( vars, src_hw_c64_vars_asm);
    outhead0(".segment \"CODE\"");
    variable_define( _environment, "stringsAddress", VT_ADDRESS, 0x4200 );
    variable_global( _environment, "stringsAddress" );
    bank_define( _environment, "STRINGS", BT_STRINGS, 0x4200, NULL );
    variable_define( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0xD800 );
    variable_global( _environment, "COLORMAPADDRESS" );

    setup_text_variables( _environment );

    vic2_initialization( _environment );

}

void target_linkage( Environment * _environment ) {

    char commandLine[MAX_TEMPORARY_STORAGE];
    char executableName[32];
    
    if( access( "cc65\\bin\\cl65.exe", F_OK ) == 0 ) {
        sprintf(executableName, "%s", "cc65\\bin\\cl65.exe" );
    } else {
        sprintf(executableName, "%s", "cl65" );
    }

    sprintf( commandLine, "%s -g -Ln main.lbl -l main.lst -o %s -u __EXEHDR__ -t c64 -C %s %s",
        executableName,
        _environment->exeFileName, 
        _environment->configurationFileName, 
        _environment->asmFileName );

    if ( system( commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n");
        printf("Please use option '-I' to install chain tool.\n\n");
    }; 

}
