/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
    _environment->embedded.cpu_hex_to_string = 1;

}

void target_initialization( Environment * _environment ) {

    // MEMORY_AREA_DEFINE( MAT_RAM, 0xd000, 0xdff0 );

    _environment->dstring.count = 16;
    _environment->dstring.space = 128;

    variable_import( _environment, "EVERYSTATUS", VT_BYTE, 0 );
    variable_global( _environment, "EVERYSTATUS" );

    variable_import( _environment, "BITMAPADDRESS", VT_ADDRESS, 0xc000 );
    variable_global( _environment, "BITMAPADDRESS" );
    variable_import( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0xc000 );
    variable_global( _environment, "COLORMAPADDRESS" );
    variable_import( _environment, "TEXTADDRESS", VT_ADDRESS, 0xc000 );
    variable_global( _environment, "TEXTADDRESS" );    
    variable_import( _environment, "TILESADDRESS", VT_ADDRESS, 0xc000 );
    variable_global( _environment, "TILESADDRESS" );    
    variable_import( _environment, "EMPTYTILE", VT_TILE, 32 );
    variable_global( _environment, "EMPTYTILE" );    
    variable_import( _environment, "USING", VT_BYTE, 0 );

    variable_import( _environment, "COPYOFBITMAPADDRESS", VT_ADDRESS, 0xc000 );
    variable_global( _environment, "COPYOFBITMAPADDRESS" );
    variable_import( _environment, "COPYOFCOLORMAPADDRESS", VT_ADDRESS, 0xc000 );
    variable_global( _environment, "COPYOFCOLORMAPADDRESS" );
    variable_import( _environment, "COPYOFTEXTADDRESS", VT_ADDRESS, 0xc000 );
    variable_global( _environment, "COPYOFTEXTADDRESS" );    
    variable_import( _environment, "COPYOFTILESADDRESS", VT_ADDRESS, 0xc000 );
    variable_global( _environment, "COPYOFTILESADDRESS" );    

    variable_import( _environment, "CPCTIMER", VT_WORD, 0 );
    variable_global( _environment, "CPCTIMER" );    

    variable_import( _environment, "IRQVECTOR", VT_BUFFER, 3 );
    variable_global( _environment, "IRQVECTOR" );   
    variable_import( _environment, "IRQVECTORREADY", VT_BYTE, 0 );
    variable_global( _environment, "IRQVECTORREADY" );   

    bank_define( _environment, "VARIABLES", BT_VARIABLES, 0x5000, NULL );
    bank_define( _environment, "TEMPORARY", BT_TEMPORARY, 0x5100, NULL );

    // outhead0("SECTION code_user");
    outhead0("ORG $1200");
    // outhead0("SECTION data_user");
    // outhead0("ORG $7030");
    // outhead0("SECTION code_user");

    deploy( startup, src_hw_cpc_startup_asm);

    outhead0("CODESTART:")
    outline0("LD SP, $8000");

    // outline0("CALL VARINIT2");
    outline0("CALL VARINIT");
    outline0("CALL PROTOTHREADINIT" );

    cpc_initialization( _environment );
    ay8910_initialization( _environment );
    
    setup_text_variables( _environment );

    outline0("CALL CPCSTARTUP");

    if ( _environment->tenLinerRulesEnforced ) {
        shell_injection( _environment );
    }

}

void target_linkage( Environment * _environment ) {

    char commandLine[2*MAX_TEMPORARY_STORAGE];
    char executableName[MAX_TEMPORARY_STORAGE];
    char binaryName[MAX_TEMPORARY_STORAGE];
    char diskName[MAX_TEMPORARY_STORAGE];
    char listingFileName[MAX_TEMPORARY_STORAGE];
    char binaryName2[MAX_TEMPORARY_STORAGE];
    
    if ( _environment->outputFileType != OUTPUT_FILE_TYPE_DSK ) {
        CRITICAL_UNSUPPORTED_OUTPUT_FILE_TYPE( OUTPUT_FILE_TYPE_AS_STRING[_environment->outputFileType] );
    }

    if ( _environment->compilerFileName ) {
        sprintf(executableName, "%s", _environment->compilerFileName );
    } else if( access( "z88dk-z80asm.exe", F_OK ) == 0 ) {
        sprintf(executableName, "%s", "z88dk-z80asm.exe" );
    } else {
        sprintf(executableName, "%s", "z88dk-z80asm" );
    }

    if ( _environment->listingFileName ) {
        sprintf( listingFileName, "-l" );
    } else {
        strcpy( listingFileName, "" );
    }

    sprintf( commandLine, "\"%s\" %s -D__cpc__ -b \"%s\"",
        executableName,
        listingFileName,
        _environment->asmFileName );

    if ( system_call( _environment,  commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n");
        printf("Please use option '-I' to install chain tool.\n\n");
        return;
    }; 

    strcpy( binaryName, _environment->asmFileName );
    char * p = strstr( binaryName, ".asm" );
    if ( p ) {
        *(p+1) = 'o';
        *(p+2) = 0;
    }
    remove(binaryName);

    if ( _environment->appMakerFileName ) {
        sprintf(executableName, "%s", _environment->appMakerFileName );
    } else if( access( "z88dk-appmake.exe", F_OK ) == 0 ) {
        sprintf(executableName, "%s", "z88dk-appmake.exe" );
    } else {
        sprintf(executableName, "%s", "z88dk-appmake" );
    }

    char pipes[256];

    #ifdef _WIN32
        strcpy( pipes, ">nul 2>nul");
    #else
        strcpy( pipes, ">/dev/null 2>/dev/null");
    #endif

    strcpy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *(p+1) = 'b';
        *(p+2) = 'i';
        *(p+3) = 'n';
        *(p+4) = 0;
    }

    strcpy( binaryName2, _environment->asmFileName );
    p = strrchr( binaryName2, '/' );
    if ( !p ) {
        p = strrchr( binaryName2, '\\' );
    }
    if ( p ) {
        strcat( p+1, "main.bin" );
    }

    strcpy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *(p+1) = 'b';
        *(p+2) = 'i';
        *(p+3) = 'n';
        *(p+4) = 0;
    }

    rename( binaryName, binaryName2 );
    strcpy( binaryName, binaryName2 );

    strcpy( diskName, _environment->asmFileName );
    p = strstr( diskName, ".asm" );
    if ( p ) {
        *(p+1) = 'd';
        *(p+2) = 's';
        *(p+3) = 'k';
        *(p+4) = 0;
    }

    sprintf( commandLine, "\"%s\" +cpc --org $1200 --disk -b \"%s\" -o \"%s\" %s",
        executableName,
        binaryName,
        diskName,
        pipes );

    if ( system_call( _environment,  commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n");
        printf("Please use option '-I' to install chain tool.\n\n");
        return;
    }; 

    remove( _environment->exeFileName );

    rename( diskName, _environment->exeFileName );

    strcpy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        strcat( p, ".bin");
    }
 
   remove(binaryName);

}

void interleaved_instructions( Environment * _environment ) {

}