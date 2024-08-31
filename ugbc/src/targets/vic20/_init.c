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

void target_initialization( Environment * _environment ) {

    _environment->program.startingAddress = 0x2001;

    cpu6502_init( _environment );

    banks_init( _environment );
    
    _environment->audioConfig.async = 1;
    
    // MEMORY_AREA_DEFINE( MAT_DIRECT, 0x0400, 0x0fff );

    variable_import( _environment, "BITMAPADDRESS", VT_ADDRESS, 0x1000 );
    variable_global( _environment, "BITMAPADDRESS" );
    variable_import( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0x9400 );
    variable_global( _environment, "COLORMAPADDRESS" );
    variable_import( _environment, "TEXTADDRESS", VT_ADDRESS, 0x1000 );
    variable_global( _environment, "TEXTADDRESS" );    
    variable_import( _environment, "EMPTYTILE", VT_TILE, 32 );
    variable_global( _environment, "EMPTYTILE" );    

    variable_import( _environment, "DATAPTR", VT_ADDRESS, 0 );
    variable_global( _environment, "DATAPTR" );

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
    // outline0(".byte $01, $12, $0B, $12, $00, $00, $9E, $38, $31, $39, $32, $00, $00, $00, $00");
    // outhead0(".segment \"CODE\"");

    outhead0("CODESTART:");

    setup_text_variables( _environment );

    vic1_initialization( _environment );

    deploy_deferred( startup, src_hw_vic20_startup_asm);
    cpu_call( _environment, "VIC20STARTUP" );

    cpu_call( _environment, "VARINIT" );

    if ( _environment->tenLinerRulesEnforced ) {
        shell_injection( _environment );
        cpu_call( _environment, "VARINIT" );
    }

}

void interleaved_instructions( Environment * _environment ) {

}