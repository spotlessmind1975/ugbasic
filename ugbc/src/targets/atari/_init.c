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
    _environment->embedded.cpu_msc1_uncompress = 1;

}

void target_initialization( Environment * _environment ) {

    // MEMORY_AREA_DEFINE( MAT_RAM, 0xb000, 0xbfff );

    variable_import( _environment, "EVERYSTATUS", VT_BYTE, 0 );
    variable_global( _environment, "EVERYSTATUS" );

    variable_import( _environment, "BITMAPADDRESS", VT_ADDRESS, 0xa000 );
    variable_global( _environment, "BITMAPADDRESS" );
    variable_import( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0x0000  );
    variable_global( _environment, "COLORMAPADDRESS" );
    variable_import( _environment, "TEXTADDRESS", VT_ADDRESS, 0xa000 );
    variable_global( _environment, "TEXTADDRESS" );    
    variable_import( _environment, "EMPTYTILE", VT_TILE, 32 );
    variable_global( _environment, "EMPTYTILE" );    

    bank_define( _environment, "VARIABLES", BT_VARIABLES, 0x8000, NULL );
    bank_define( _environment, "TEMPORARY", BT_TEMPORARY, 0x8100, NULL );
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

    outhead0(".include \"atari.inc\"");
    outhead0(".segment \"CODE\"");
    outhead0(".proc MAINENTRY");

    deploy( vars, src_hw_atari_vars_asm);

    bank_define( _environment, "STRINGS", BT_STRINGS, 0x4200, NULL );
    variable_define( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0xD800 );
    variable_global( _environment, "COLORMAPADDRESS" );

    setup_text_variables( _environment );

    antic_initialization( _environment );
    gtia_initialization( _environment );
    pokey_initialization( _environment );
    
    if ( _environment->tenLinerRulesEnforced ) {
        shell_injection( _environment );
    }
    
    cpu_call( _environment, "VARINIT" );

}


void interleaved_instructions( Environment * _environment ) {

}