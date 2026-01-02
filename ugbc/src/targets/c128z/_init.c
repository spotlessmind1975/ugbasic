/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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

    _environment->program.startingAddress = 0x1c2f;

    // MEMORY_AREA_DEFINE( MAT_RAM, 0xd000, 0xdff0 );

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

    // _environment->audioConfig.async = 1;

    variable_import( _environment, "EVERYCOUNTER", VT_WORD, 0 );
    variable_global( _environment, "EVERYCOUNTER" );
    variable_import( _environment, "EVERYTIMING", VT_WORD, 0 );
    variable_global( _environment, "EVERYTIMING" );

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

    variable_import( _environment, "C128ZTIMER", VT_WORD, 0 );
    variable_global( _environment, "C128ZTIMER" );    
    variable_import( _environment, "C128ZTIMER2", VT_WORD, 0 );
    variable_global( _environment, "C128ZTIMER2" );    

    variable_import( _environment, "IRQVECTOR", VT_BUFFER, 3 );
    variable_global( _environment, "IRQVECTOR" );   
    variable_import( _environment, "IRQVECTORREADY", VT_BYTE, 0 );
    variable_global( _environment, "IRQVECTORREADY" );   

    variable_import( _environment, "TICKSPERSECOND", VT_BYTE, 0 );
    variable_global( _environment, "TICKSPERSECOND" );   

    variable_import( _environment, "PLOTCPE", VT_BYTE, 0 );
    variable_global( _environment, "PLOTCPE" );   

    variable_import( _environment, "KBDCHAR", VT_BYTE, 0 );
    variable_global( _environment, "KBDCHAR" );

    variable_import( _environment, "DATAPTR", VT_ADDRESS, 0 );
    variable_global( _environment, "DATAPTR" );

    variable_import( _environment, "DOJOERROR", VT_BYTE, 0 );
    variable_global( _environment, "DOJOERROR" );

    variable_import( _environment, "GEORAMBANKSHADOW", VT_BYTE, 0 );
    variable_global( _environment, "GEORAMBANKSHADOW" );
    variable_import( _environment, "GEORAMSWAPSHADOW", VT_BYTE, 0 );
    variable_global( _environment, "GEORAMSWAPSHADOW" );
    variable_import( _environment, "GEORAMPAGESHADOW", VT_BYTE, 0 );
    variable_global( _environment, "GEORAMPAGESHADOW" );

    variable_import( _environment, "JFIRELATCH", VT_WORD, 0 );
    variable_global( _environment, "JFIRELATCH" );

    bank_define( _environment, "VARIABLES", BT_VARIABLES, 0x5000, NULL );
    bank_define( _environment, "TEMPORARY", BT_TEMPORARY, 0x5100, NULL );

    // outhead0("SECTION code_user");
    // outhead0("ORG $1BFF");
    // deploy_inplace( startup, src_hw_c128z_startup_asm);
    // deploy_deferred( startup, src_hw_c128z_startup2_asm);

    outhead0("CODESTART:")

   cpu_init( _environment );

    // outline0("CALL VARINIT2");
    cpu_call( _environment, "VARINIT" );
    outline0("CALL C128ZSTARTUP2");
    outline0("CALL PROTOTHREADINIT" );

    setup_text_variables( _environment );

    vdcz_initialization( _environment );
    sidz_initialization( _environment );
    
    outline0("CALL C128ZSTARTUP");

    if ( _environment->tenLinerRulesEnforced ) {
        shell_injection( _environment );
        cpu_call( _environment, "VARINIT" );
    }

}

void interleaved_instructions( Environment * _environment ) {

}