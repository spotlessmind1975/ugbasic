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

extern char OUTPUT_FILE_TYPE_AS_STRING[][16];

void setup_embedded( Environment * _environment ) {

    _environment->embedded.cpu_fill_blocks = 1;
    _environment->embedded.cpu_fill = 1;
    _environment->embedded.cpu_math_div2_8bit = 1;
    _environment->embedded.cpu_math_mul_8bit_to_16bit = 1;
    _environment->embedded.cpu_math_div_8bit_to_8bit = 1;
    _environment->embedded.cpu_math_div2_const_8bit = 1;
    _environment->embedded.cpu_math_mul2_const_8bit = 1;
    _environment->embedded.cpu_math_mul_16bit_to_32bit = 1;
    _environment->embedded.cpu_math_div_16bit_to_16bit = 1;
    _environment->embedded.cpu_math_div_32bit_to_16bit = 1;
    _environment->embedded.cpu_random = 1;
    _environment->embedded.cpu_mem_move = 1;
    _environment->embedded.cpu_uppercase = 1;
    _environment->embedded.cpu_lowercase = 1;

}

void target_initialization( Environment * _environment ) {

    variable_import( _environment, "EVERYSTATUS", VT_BYTE );
    variable_global( _environment, "EVERYSTATUS" );

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
    variable_define( _environment, "bitmap_enabled", VT_BYTE, 0 );
    variable_global( _environment, "bitmap_enabled" );
    variable_define( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0x5800 );
    variable_global( _environment, "COLORMAPADDRESS" );

    setup_text_variables( _environment );

    zx_initialization( _environment );

}

void target_linkage( Environment * _environment ) {

    char commandLine[2*MAX_TEMPORARY_STORAGE];
    char executableName[MAX_TEMPORARY_STORAGE];
    char binaryName[64];
    char listingFileName[64];
    
    if ( _environment->outputFileType != OUTPUT_FILE_TYPE_TAP ) {
        CRITICAL_UNSUPPORTED_OUTPUT_FILE_TYPE( OUTPUT_FILE_TYPE_AS_STRING[_environment->outputFileType] );
    }

    if ( _environment->compilerFileName ) {
        sprintf(executableName, "\"%s\"", _environment->compilerFileName );
    } else if( access( "z88dk\\z88dk\\bin\\z88dk-z80asm.exe", F_OK ) == 0 ) {
        sprintf(executableName, "%s", "z88dk\\z88dk\\bin\\z88dk-z80asm.exe" );
    } else {
        sprintf(executableName, "%s", "z88dk-z80asm" );
    }

    if ( _environment->listingFileName ) {
        sprintf( listingFileName, "-l" );
    } else {
        strcpy( listingFileName, "" );
    }

    sprintf( commandLine, "%s %s -b %s",
        executableName,
        listingFileName,
        _environment->asmFileName );

    if ( system( commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n");
        printf("Please use option '-I' to install chain tool.\n\n");
        return;
    }; 

    strcpy( binaryName, _environment->asmFileName );
    char * p = strstr( binaryName, ".asm" );
    if ( p ) {
        *(p+1) = 'b';
        *(p+2) = 'i';
        *(p+3) = 'n';
    }

    if ( _environment->appMakerFileName ) {
        sprintf(executableName, "\"%s\"", _environment->appMakerFileName );
    } else if( access( "z88dk\\z88dk\\bin\\z88dk-appmake.exe", F_OK ) == 0 ) {
        sprintf(executableName, "%s", "z88dk\\z88dk\\bin\\z88dk-appmake.exe" );
    } else {
        sprintf(executableName, "%s", "z88dk-appmake" );
    }

    sprintf( commandLine, "%s +zx --org 32768 -b %s",
        executableName,
        binaryName );

    p = strstr( binaryName, ".bin" );
    if ( p ) {
        *(p+1) = 't';
        *(p+2) = 'a';
        *(p+3) = 'p';
    }

    if ( system( commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n");
        printf("Please use option '-I' to install chain tool.\n\n");
        return;
    }; 

    rename( binaryName, _environment->exeFileName );

}