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

    variable_import( _environment, "BITMAPADDRESS", VT_ADDRESS );
    variable_global( _environment, "BITMAPADDRESS" );
    variable_import( _environment, "COLORMAPADDRESS", VT_ADDRESS );
    variable_global( _environment, "COLORMAPADDRESS" );
    variable_import( _environment, "EMPTYTILE", VT_BYTE );
    variable_global( _environment, "EMPTYTILE" );    

    bank_define( _environment, "VARIABLES", BT_VARIABLES, 0x5000, NULL );
    bank_define( _environment, "TEMPORARY", BT_TEMPORARY, 0x5100, NULL );
    variable_import( _environment, "FREE_STRING", VT_WORD );
    variable_global( _environment, "FREE_STRING" );    

    outhead0("org 32768");
    variable_define( _environment, "stringsAddress", VT_ADDRESS, 0xa000 );
    variable_global( _environment, "stringsAddress" );
    variable_define( _environment, "bitmap_enabled", VT_BYTE, 0 );
    variable_global( _environment, "bitmap_enabled" );
    variable_define( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0x5800 );
    variable_global( _environment, "COLORMAPADDRESS" );

    setup_text_variables( _environment );

    zx_initialization( _environment );

}

void target_linkage( Environment * _environment ) {

    char commandLine[MAX_TEMPORARY_STORAGE];
    char executableName[64];
    char binaryName[64];
    
    if( access( "z88dk\\z88dk\\bin\\z88dk-z80asm.exe", F_OK ) == 0 ) {
        sprintf(executableName, "%s", "z88dk\\z88dk\\bin\\z88dk-z80asm.exe" );
    } else {
        sprintf(executableName, "%s", "z88dk-z80asm" );
    }

    sprintf( commandLine, "%s -l -b %s",
        executableName,
        _environment->asmFileName );
    system( commandLine ); 

    if ( system( commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n");
        printf("Please use option '-I' to install chain tool.\n\n");
        return;
    }; 

    strcpy( binaryName, _environment->exeFileName );
    char * p = strstr( binaryName, ".tap" );
    if ( p ) {
        *(p+1) = 'b';
        *(p+2) = 'i';
        *(p+3) = 'n';
    }

    if( access( "z88dk\\z88dk\\bin\\z88dk-appmake.exe", F_OK ) == 0 ) {
        sprintf(executableName, "%s", "z88dk\\z88dk\\bin\\z88dk-appmake.exe" );
    } else {
        sprintf(executableName, "%s", "z88dk-appmake" );
    }

    sprintf( commandLine, "%s +zx --org 32768 -b %s",
        executableName,
       binaryName );

    if ( system( commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n");
        printf("Please use option '-I' to install chain tool.\n\n");
        return;
    }; 

}