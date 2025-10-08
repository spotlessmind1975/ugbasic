/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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

void target_initialization( Environment * _environment ) {

    _environment->program.startingAddress = 0x080e;

    cpu_init( _environment );

    if ( _environment->tenLinerRulesEnforced ) {
        MEMORY_AREA_DEFINE( MAT_DIRECT, 0xc000, 0xcfff );
    }
    /*MEMORY_AREA_DEFINE( MAT_RAM, 0xe000, 0xff00 );*/

    int bankCount = 0;
    int * bankIds = NULL;
    int bankSize = 0x4000;

    // 512 kB	0–31	$00–$1f
    // 1024 kB	0–63	$00–$3f
    // 2048 kB	0–127	$00–$7f
    // 4096 kB	0–255	$00–$ff

    switch( _environment->ramSize ) {
        case 512:
            bankCount = 32;
            break;
        case 1024:
            bankCount = 64;
            break;
        case 2048:
            bankCount = 128;
            break;
        case 4096:
            bankCount = 256;
            break;
        default:
            bankCount = 0;
            break;
    }

    if ( bankCount ) {
        bankIds = malloc( sizeof( int ) * bankCount );
        
        for( int i=0; i<bankCount; ++i ) {
            bankIds[i] = bankCount-i-1;
        }

        _environment->compressionForbidden = 1;

        banks_init_extended( _environment, bankIds, bankCount, bankSize );
    }

    _environment->audioConfig.async = 1;

    if ( _environment->tenLinerRulesEnforced ) {
        Variable * source = variable_retrieve( _environment, "SHELL_SOURCE" );
        if ( _environment->memoryAreas ) {
            memory_area_assign( _environment->memoryAreas, source );
        }
    }

    variable_import( _environment, "BITMAPADDRESS", VT_ADDRESS, 0xa000 );
    variable_global( _environment, "BITMAPADDRESS" );
    variable_import( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0xd800 );
    variable_global( _environment, "COLORMAPADDRESS" );
    variable_import( _environment, "TEXTADDRESS", VT_ADDRESS, 0x8400 );
    variable_global( _environment, "TEXTADDRESS" );    
    variable_import( _environment, "EMPTYTILE", VT_TILE, 32 );
    variable_global( _environment, "EMPTYTILE" );    
    variable_import( _environment, "DATAPTR", VT_ADDRESS, 0 );
    variable_global( _environment, "DATAPTR" );

    variable_import( _environment, "GEORAMBANKSHADOW", VT_BYTE, 0 );
    variable_global( _environment, "GEORAMBANKSHADOW" );

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

    // outhead0(".segment \"BASIC\"");
    // outline0(".byte $01,$08,$0b,$08,$00,$00,$9e,$32,$30,$36,$31,$00,$00,$00" );
    // outhead0(".segment \"CODE\"");
    // outline0("NOP");
    // outline0("NOP");

    outhead0("CODESTART:");
    
    deploy_preferred( vars, src_hw_c64_vars_asm);

    setup_text_variables( _environment );

    deploy_preferred( startup, src_hw_c64_startup_asm);
    cpu_call( _environment, "C64STARTUP" );

    vic2_initialization( _environment );
    sid_initialization( _environment );

    cpu_call( _environment, "VARINIT" );

    if ( _environment->tenLinerRulesEnforced ) {
        shell_injection( _environment );

        cpu_call( _environment, "VARINIT" );

    }

}


void interleaved_instructions( Environment * _environment ) {

}