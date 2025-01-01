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

    _environment->program.startingAddress = 0x3000;

    cpu6809_init( _environment );

    int * bankIds = NULL;
    int bankMax = 0;
    int bankCount = 0;

    switch( _environment->ramSize ) {
        case 512:
            bankMax=32; /* 0...31 = 32 banks */
            break;
        case 64:
            bankMax=4; /* 0...3 = 4 banks */
            break;
        case 0:
            bankMax=-1; 
            break;
        default:
            CRITICAL_INVALID_RAM_SIZE( _environment->ramSize );
            break;
    }

    if ( bankMax != -1 ) {

        bankIds = malloc( sizeof( int ) * bankMax );
        
        for( int i=0; i<bankMax; ++i ) {
            bankIds[i] = bankMax - ( i ) - 1;
            ++bankCount;
        }

        banks_init_extended( _environment, bankIds, bankCount, BANK_SIZE );

    }
    
    // MEMORY_AREA_DEFINE( MAT_DIRECT, 0x8000, 0x9fff );

    outhead1("BASE_SEGMENT EQU $%4.4x", 0x0100 * BASE_SEGMENT );
    
    variable_import( _environment, "BITMAPADDRESS", VT_ADDRESS, 0x0000 );
    variable_global( _environment, "BITMAPADDRESS" );
    variable_import( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0x0000 );
    variable_global( _environment, "COLORMAPADDRESS" );
    variable_import( _environment, "TEXTADDRESS", VT_ADDRESS, 0x0000 );
    variable_global( _environment, "TEXTADDRESS" );    
    variable_import( _environment, "EMPTYTILE", VT_TILE, 32 );
    variable_global( _environment, "EMPTYTILE" );    
    variable_import( _environment, "DATAPTR", VT_ADDRESS, 0 );
    variable_global( _environment, "DATAPTR" );

    bank_define( _environment, "VARIABLES", BT_VARIABLES, 0x5000, NULL );
    bank_define( _environment, "TEMPORARY", BT_TEMPORARY, 0x5100, NULL );
    variable_import( _environment, "FREE_STRING", VT_WORD, DSTRING_DEFAULT_SPACE );
    variable_global( _environment, "FREE_STRING" );    

    // outline0("ORG $3000");
    // outhead0("CODESTART");
    // outline0("LDS #$A000");

    deploy( vars, src_hw_mo5_vars_asm);
    deploy_deferred( startup, src_hw_mo5_startup_asm);
    // bank_define( _environment, "STRINGS", BT_STRINGS, 0x4200, NULL );

    outline0( "JSR MO5STARTUP" );

    setup_text_variables( _environment );

    ef936x_initialization( _environment );

    cpu_call( _environment, "VARINIT" );

    if ( _environment->tenLinerRulesEnforced ) {
        shell_injection( _environment );
        cpu_call( _environment, "VARINIT" );
    }

}

void interleaved_instructions( Environment * _environment ) {

}