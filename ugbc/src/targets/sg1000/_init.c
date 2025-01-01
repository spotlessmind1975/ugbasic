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

    // MEMORY_AREA_DEFINE( MAT_RAM, 0xd000, 0xdff0 );

    _environment->audioConfig.async = 1;

    _environment->dstring.count = 16;
    _environment->dstring.space = 128;
    
    variable_import( _environment, "PPIKEYBOARD", VT_BYTE, 0 );
    variable_global( _environment, "PPIKEYBOARD" );   

    variable_import( _environment, "VDP60HZ", VT_BYTE, 0 );
    variable_global( _environment, "VDP60HZ" );   

    variable_import( _environment, "IRQVECTOR", VT_BUFFER, 3 );
    variable_global( _environment, "IRQVECTOR" );   
    variable_import( _environment, "IRQVECTORREADY", VT_BYTE, 0 );
    variable_global( _environment, "IRQVECTORREADY" );   

    variable_import( _environment, "TIMERRUNNING", VT_BYTE, 0 );
    variable_global( _environment, "TIMERRUNNING" );
    variable_import( _environment, "TIMERSTATUS", VT_BYTE, 0 );
    variable_global( _environment, "TIMERSTATUS" );
    variable_import( _environment, "TIMERCOUNTER", VT_BUFFER, 16 );
    variable_global( _environment, "TIMERCOUNTER" );
    variable_import( _environment, "TIMERINIT", VT_BUFFER, 16 );
    variable_global( _environment, "TIMERINIT" );
    variable_import( _environment, "TIMERADDRESS", VT_BUFFER, 16 );
    variable_global( _environment, "TIMERADDRESS" );

    variable_import( _environment, "TICKSPERSECOND", VT_BYTE, 0 );
    variable_global( _environment, "TICKSPERSECOND" );

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

    variable_import( _environment, "SG1000TIMER", VT_WORD, 0 );
    variable_global( _environment, "SG1000TIMER" );   

    variable_import( _environment, "FPSCRAP", VT_BUFFER, 16 );
    variable_global( _environment, "FPSCRAP" );

    variable_import( _environment, "DATAPTR", VT_ADDRESS, 0 );
    variable_global( _environment, "DATAPTR" );

    variable_import( _environment, "SN76489TIMER", VT_BUFFER, 6 );
    variable_global( _environment, "SN76489TIMER" );    

    bank_define( _environment, "VARIABLES", BT_VARIABLES, 0x5000, NULL );
    bank_define( _environment, "TEMPORARY", BT_TEMPORARY, 0x5100, NULL );

    outhead0("SECTION code_user");
    outhead0("ORG $0000");
    outhead0("SECTION data_user");
    outhead0("ORG $C000");
    outhead0("SECTION code_user");

    deploy_inplace(startup,src_hw_sg1000_startup_asm);
    deploy_deferred(startup,src_hw_sg1000_startup2_asm);

    outhead0("CODESTART:")
    
    outline0("CALL VARINIT2");
    cpu_call( _environment, "VARINIT" );

    z80_init( _environment );

    outline0("CALL PROTOTHREADINIT" );
    outline0("CALL SG1000STARTUP");
    outline0("CALL SG1000STARTUP2");

    setup_text_variables( _environment );
    
    tms9918_initialization( _environment );
    sn76489z_initialization( _environment );

    outline0("call	CheckIf60Hz");
    outline0("ld		(VDP60HZ),a				; save it, 00/01 = 50/60 Hz		");

    z80_compare_and_branch_8bit_const( _environment, "LASTVAR", 0x42, "CODESTARTRUN", 1 );

    Variable * outOfMemoryMessage = variable_define( _environment, "OOM", VT_STRING, 0 );
    variable_store_string( _environment, outOfMemoryMessage->name, "OOM" );
    print( _environment, outOfMemoryMessage->name, 1, 0 );

    cpu_halt( _environment );

    outhead0("CODESTARTRUN:")

    if ( _environment->tenLinerRulesEnforced ) {
        shell_injection( _environment );
        cpu_call( _environment, "VARINIT" );
    }

}

void interleaved_instructions( Environment * _environment ) {

}