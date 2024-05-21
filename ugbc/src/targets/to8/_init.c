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

extern char OUTPUT_FILE_TYPE_AS_STRING[][16];

void setup_embedded( Environment * _environment ) {

    _environment->embedded.cpu_fill_blocks = 1;
    _environment->embedded.cpu_fill = 1;
    _environment->embedded.cpu_math_div2_const_8bit = 1;
    _environment->embedded.cpu_math_mul_8bit_to_16bit = 1;
    _environment->embedded.cpu_math_div_8bit_to_8bit = 1;
    _environment->embedded.cpu_math_div2_const_8bit = 1;
    _environment->embedded.cpu_math_mul_16bit_to_32bit = 1;
    _environment->embedded.cpu_math_div_16bit_to_16bit = 1;
    _environment->embedded.cpu_math_div_32bit_to_16bit = 1;
    _environment->embedded.cpu_random = 1;
    _environment->embedded.cpu_mem_move = 1;
    _environment->embedded.cpu_hex_to_string = 1;
    _environment->embedded.cpu_msc1_uncompress = 1;
    _environment->embedded.cpu_string_sub = 1;
    _environment->embedded.cpu_bit_inplace = 1;
    _environment->embedded.cpu_bit_check_extended = 1;
    _environment->embedded.cpu_flip = 1;

}

void target_initialization( Environment * _environment ) {

    cpu6809_init( _environment );

    int * bankIds = NULL;
    int bankMax = 0;
    int bankCount = 0;

    if ( ! _environment->ramSize ) {
        _environment->ramSize = 256;
    }
    
    switch( _environment->ramSize ) {
        case 512:
            bankMax=31; /* 3...30 = 28 banks */
            break;
        case 256:
            bankMax=16; /* 3...15 = 13 banks */
            break;
        default:
            CRITICAL_INVALID_RAM_SIZE( _environment->ramSize );
            break;
    }

    bankIds = malloc( sizeof( int ) * bankMax );
    
    for( int i=3; i<bankMax; ++i ) {
        bankIds[i-3] = bankMax - ( i-3 ) - 1;
        ++bankCount;
    }

    banks_init_extended( _environment, bankIds, bankCount, BANK_SIZE );

    outhead1("BASE_SEGMENT EQU $%4.4x", 0x0100 * BASE_SEGMENT );

    // MEMORY_AREA_DEFINE( MAT_DIRECT, 0x8000, 0x9fff );

    variable_import( _environment, "EVERYSTATUS", VT_BYTE, 0 );
    variable_global( _environment, "EVERYSTATUS" );

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
    // outline0("LDS #$2FFF");
    
    deploy( vars, src_hw_to8_vars_asm);
    deploy( startup, src_hw_to8_startup_asm);
    // bank_define( _environment, "STRINGS", BT_STRINGS, 0x4200, NULL );

    outline0( "JSR TO8STARTUP" );

    setup_text_variables( _environment );

    ef936x_initialization( _environment );

    if ( _environment->tenLinerRulesEnforced ) {
        cpu_call( _environment, "VARINIT" );
        outline0("LDS #$2FFF");
        if ( _environment->tenLinerRulesEnforced ) {
            shell_injection( _environment );
        }
        outline0("LDS #$A000");
    }

    cpu_call( _environment, "VARINIT" );

}

void interleaved_instructions( Environment * _environment ) {

}