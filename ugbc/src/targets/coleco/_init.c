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
#include <libgen.h>

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

extern char OUTPUT_FILE_TYPE_AS_STRING[][16];

void target_initialization( Environment * _environment ) {

    // MEMORY_AREA_DEFINE( MAT_RAM, 0xd000, 0xdff0 );

    _environment->audioConfig.async = 1;

    _environment->dstring.count = 32;
    _environment->dstring.space = 128;

    variable_import( _environment, "BITMAPADDRESS", VT_ADDRESS, 0x0000 );
    variable_global( _environment, "BITMAPADDRESS" );
    variable_import( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0x0000 );
    variable_global( _environment, "COLORMAPADDRESS" );
    variable_import( _environment, "TEXTADDRESS", VT_ADDRESS, 0x0000 );
    variable_global( _environment, "TEXTADDRESS" );    
    variable_import( _environment, "TILESADDRESS", VT_ADDRESS, 0x0000 );
    variable_global( _environment, "TILESADDRESS" );    
    variable_import( _environment, "EMPTYTILE", VT_TILE, 32 );
    variable_global( _environment, "EMPTYTILE" );    
    variable_import( _environment, "USING", VT_BYTE, 0 );

    variable_import( _environment, "COPYOFBITMAPADDRESS", VT_ADDRESS, 0x0000 );
    variable_global( _environment, "COPYOFBITMAPADDRESS" );
    variable_import( _environment, "COPYOFCOLORMAPADDRESS", VT_ADDRESS, 0x0000 );
    variable_global( _environment, "COPYOFCOLORMAPADDRESS" );
    variable_import( _environment, "COPYOFTEXTADDRESS", VT_ADDRESS, 0x0000 );
    variable_global( _environment, "COPYOFTEXTADDRESS" );    
    variable_import( _environment, "COPYOFTILESADDRESS", VT_ADDRESS, 0x0000 );
    variable_global( _environment, "COPYOFTILESADDRESS" );    

    variable_import( _environment, "VDPDATAPORTREAD", VT_BYTE, 0xbe );
    variable_global( _environment, "VDPDATAPORTREAD" );

    variable_import( _environment, "VDPDATAPORTWRITE", VT_BYTE, 0xbe );
    variable_global( _environment, "VDPDATAPORTWRITE" );

    variable_import( _environment, "VDPCONTROLPORTREAD", VT_BYTE, 0xbf );
    variable_global( _environment, "VDPCONTROLPORTREAD" );

    variable_import( _environment, "VDPCONTROLPORTWRITE", VT_BYTE, 0xbf );
    variable_global( _environment, "VDPCONTROLPORTWRITE" );

    variable_import( _environment, "CONTROLLER_BUFFER", VT_BUFFER, 12 );
    variable_global( _environment, "CONTROLLER_BUFFER" );    

    variable_import( _environment, "COLECOTIMER", VT_WORD, 0 );
    variable_global( _environment, "COLECOTIMER" );    

    variable_import( _environment, "IRQVECTOR", VT_BUFFER, 3 );
    variable_global( _environment, "IRQVECTOR" );   
    variable_import( _environment, "IRQVECTORREADY", VT_BYTE, 0 );
    variable_global( _environment, "IRQVECTORREADY" );   

    variable_import( _environment, "TICKSPERSECOND", VT_BYTE, 0 );
    variable_global( _environment, "TICKSPERSECOND" );   

    variable_import( _environment, "JOYSTICK0", VT_BYTE, 0 );
    variable_global( _environment, "JOYSTICK0" );   

    variable_import( _environment, "JOYSTICK1", VT_BYTE, 0 );
    variable_global( _environment, "JOYSTICK1" );   

    variable_import( _environment, "DATAPTR", VT_ADDRESS, 0 );
    variable_global( _environment, "DATAPTR" );

    variable_import( _environment, "SN76489TIMER", VT_BUFFER, 6 );
    variable_global( _environment, "SN76489TIMER" );    

    variable_import( _environment, "DOJOERROR", VT_BYTE, 0 );
    variable_global( _environment, "DOJOERROR" );
    
    bank_define( _environment, "VARIABLES", BT_VARIABLES, 0x5000, NULL );
    bank_define( _environment, "TEMPORARY", BT_TEMPORARY, 0x5100, NULL );

    // outhead0("SECTION code_user");
    // outhead0("ORG $8000");
    // outhead0("SECTION data_user");
    // outhead0("ORG $7030");
    // outhead0("SECTION code_user");

    // // DB       0AAh,055h       ;Cartridge present:  Colecovision logo
    // // outline0("DEFB $aa, $55");
    // // ;DB       055h,0AAh       ;Cartridge present:  skip logo, Colecovision logo
    // outline0("DEFB $55, $aa");
    // // DW       0000           ;Pointer to the sprite name table
    // outline0("DEFW $0000");
    // // DW       0000           ;Pointer to the sprite order table
    // outline0("DEFW $0000");
    // // DW       0000           ;Pointer to the working buffer for WR_SPR_NM_TBL
    // outline0("DEFW $0000");
    // // DW       CONTROLLER_BUFFER ;Pointer to the hand controller input areas
    // outline0("DEFW CONTROLLER_BUFFER");
    // // DW       START      ;Entry point to the user program
    // outline0("DEFW CODESTART");

    deploy_preferred( startup, src_hw_coleco_startup_asm);
    deploy_preferred( startup2, src_hw_coleco_startup2_asm);

    outhead0("CODESTART:")
    outline0("LD SP, $73b8");

    outline0("CALL VARINIT2");
    cpu_call( _environment, "VARINIT" );
    outline0("CALL COLECOSTARTUP2");

    z80_init( _environment );

    outline0("CALL PROTOTHREADINIT" );

    setup_text_variables( _environment );

    outline0("CALL $1f7f");

    tms9918_initialization( _environment );
    sn76489z_initialization( _environment );

    z80_compare_and_branch_8bit_const( _environment, "LASTVAR", 0x42, "CODESTARTRUN", 1 );

    Variable * outOfMemoryMessage = variable_define( _environment, "OOM", VT_STRING, 0 );
    variable_store_string( _environment, outOfMemoryMessage->name, "OOM" );
    print( _environment, outOfMemoryMessage->name, 1, _environment->printRaw );

    cpu_halt( _environment );

    outhead0("CODESTARTRUN:")
    outline0("CALL COLECOSTARTUP");

    if ( _environment->tenLinerRulesEnforced ) {
        shell_injection( _environment );
        cpu_call( _environment, "VARINIT" );
    }

}

void interleaved_instructions( Environment * _environment ) {

}