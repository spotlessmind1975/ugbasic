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

    MEMORY_AREA_DEFINE( MAT_DIRECT, 0xc000, 0xcfff );
    MEMORY_AREA_DEFINE( MAT_RAM, 0xe000, 0xff00 );

    if ( _environment->tenLinerRulesEnforced ) {
        Variable * source = variable_retrieve( _environment, "SHELL_SOURCE" );
        if ( _environment->memoryAreas ) {
            memory_area_assign( _environment->memoryAreas, source );
        }
    }

    variable_import( _environment, "EVERYSTATUS", VT_BYTE, 0 );
    variable_global( _environment, "EVERYSTATUS" );

    variable_import( _environment, "BITMAPADDRESS", VT_ADDRESS, 0xa000 );
    variable_global( _environment, "BITMAPADDRESS" );
    variable_import( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0xd800 );
    variable_global( _environment, "COLORMAPADDRESS" );
    variable_import( _environment, "TEXTADDRESS", VT_ADDRESS, 0x8400 );
    variable_global( _environment, "TEXTADDRESS" );    
    variable_import( _environment, "EMPTYTILE", VT_TILE, 32 );
    variable_global( _environment, "EMPTYTILE" );    

    bank_define( _environment, "VARIABLES", BT_VARIABLES, 0x5000, NULL );
    bank_define( _environment, "TEMPORARY", BT_TEMPORARY, 0x5100, NULL );
    variable_import( _environment, "FREE_STRING", VT_WORD, DSTRING_DEFAULT_SPACE );
    variable_global( _environment, "FREE_STRING" );    
    
    if ( !_environment->configurationFileName ) {
        char configurationFileName[MAX_TEMPORARY_STORAGE];
        sprintf( configurationFileName, "%s.cfg", get_temporary_filename( _environment ) );
        _environment->configurationFileName = strdup(configurationFileName);
    }

    _environment->configurationFile = fopen( _environment->configurationFileName, "wt");

    if ( ! _environment->configurationFile ) {
        fprintf(stderr, "Unable to open configuration file: %s\n", _environment->configurationFileName ? _environment->configurationFileName : "(temporary)" );
        exit(EXIT_FAILURE);
    }

    outhead0(".segment \"BASIC\"");
    outline0(".byte $01,$08,$0b,$08,$00,$00,$9e,$32,$30,$36,$31,$00,$00,$00" );
    outhead0(".segment \"CODE\"");
    outline0("NOP");
    outline0("NOP");
    deploy( vars, src_hw_c64_vars_asm);

    setup_text_variables( _environment );

    deploy( startup, src_hw_c64_startup_asm);
    cpu_call( _environment, "C64STARTUP" );

    vic2_initialization( _environment );
    sid_initialization( _environment );

    if ( _environment->tenLinerRulesEnforced ) {
        shell_injection( _environment );
    }

    cpu_call( _environment, "VARINIT" );
    
}

void target_linkage( Environment * _environment ) {

    char commandLine[8*MAX_TEMPORARY_STORAGE];
    char executableName[MAX_TEMPORARY_STORAGE];
    
    if ( _environment->outputFileType != OUTPUT_FILE_TYPE_PRG ) {
        CRITICAL_UNSUPPORTED_OUTPUT_FILE_TYPE( OUTPUT_FILE_TYPE_AS_STRING[_environment->outputFileType] );
    }

    if ( _environment->compilerFileName ) {
        sprintf(executableName, "%s", _environment->compilerFileName );
    } else if( access( "cc65\\bin\\cl65.exe", F_OK ) == 0 ) {
        sprintf(executableName, "%s", "cc65\\bin\\cl65.exe" );
    } else {
        sprintf(executableName, "%s", "cl65" );
    }

    char listingFileName[MAX_TEMPORARY_STORAGE];
    memset( listingFileName, 0, MAX_TEMPORARY_STORAGE );
    if ( _environment->listingFileName ) {
        sprintf( listingFileName, "-l \"%s\"", _environment->listingFileName );
    } else {
        strcpy( listingFileName, "" );
    }

    remove( _environment->exeFileName );
    
    sprintf( commandLine, "\"%s\" -g -Ln main.lbl %s -o \"%s\" -t c64 -C \"%s\" \"%s\"",
        executableName,
        listingFileName,
        _environment->exeFileName, 
        _environment->configurationFileName, 
        _environment->asmFileName );

    if ( system_call( _environment,  commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n");
        printf("Please use option '-I' to install chain tool.\n\n");
    }; 

}

void interleaved_instructions( Environment * _environment ) {

}