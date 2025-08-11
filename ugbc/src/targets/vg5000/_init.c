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

   cpu_init( _environment );

    // MEMORY_AREA_DEFINE( MAT_RAM, 0xd000, 0xdff0 );

    banks_init( _environment );

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

    variable_import( _environment, "EMPTYTILE", VT_TILE, 32 );
    variable_global( _environment, "EMPTYTILE" );    
    variable_import( _environment, "USING", VT_BYTE, 0 );

    variable_import( _environment, "COPYOFCOLORMAPADDRESS", VT_ADDRESS, 0x0000 );
    variable_global( _environment, "COPYOFCOLORMAPADDRESS" );
    variable_import( _environment, "COPYOFTEXTADDRESS", VT_ADDRESS, 0x0000 );
    variable_global( _environment, "COPYOFTEXTADDRESS" );    
    variable_import( _environment, "COPYOFTILESADDRESS", VT_ADDRESS, 0x0000 );
    variable_global( _environment, "COPYOFTILESADDRESS" );    

    variable_import( _environment, "VDPDATAPORTREAD", VT_BYTE, 0x98 );
    variable_global( _environment, "VDPDATAPORTREAD" );

    variable_import( _environment, "VDPDATAPORTWRITE", VT_BYTE, 0x98 );
    variable_global( _environment, "VDPDATAPORTWRITE" );

    variable_import( _environment, "VDPCONTROLPORTREAD", VT_BYTE, 0x99 );
    variable_global( _environment, "VDPCONTROLPORTREAD" );

    variable_import( _environment, "VDPCONTROLPORTWRITE", VT_BYTE, 0x99 );
    variable_global( _environment, "VDPCONTROLPORTWRITE" );

    variable_import( _environment, "ISRSVC2", VT_BUFFER, 3 );
    variable_global( _environment, "ISRSVC2" );

    variable_import( _environment, "DATAPTR", VT_ADDRESS, 0 );
    variable_global( _environment, "DATAPTR" );

    variable_import( _environment, "BANKSHADOW", VT_BYTE, 0 );

    for( int i=0; i<MAX_RESIDENT_SHAREDS; ++i ) {
        if ( _environment->maxExpansionBankSize[i] ) {
            
            char variableName[MAX_TEMPORARY_STORAGE];

            sprintf( variableName, "BANKWINDOW%2.2x", i);
            variable_import( _environment, variableName, VT_BUFFER, _environment->maxExpansionBankSize[i] );
            variable_global( _environment, variableName );

            sprintf( variableName, "BANKWINDOWID%2.2x", i);
            variable_import( _environment, variableName, VT_WORD, 0xffff );
            variable_global( _environment, variableName );
        }
    } 
    
    bank_define( _environment, "VARIABLES", BT_VARIABLES, 0x5000, NULL );
    bank_define( _environment, "TEMPORARY", BT_TEMPORARY, 0x5100, NULL );

    outhead0("ORG $4A0A");
    outhead0("CODESTART:")
    
    cpu_call( _environment, "VARINIT" );
    outline0("CALL PROTOTHREADINIT" );

    deploy_deferred( startup, src_hw_vg5000_startup_asm);

    outline0("CALL VG5000STARTUP" );

    if ( _environment->tenLinerRulesEnforced ) {
        shell_injection( _environment );
        cpu_call( _environment, "VARINIT" );
    }

    setup_text_variables( _environment );

    ef9345_initialization( _environment );

}

void interleaved_instructions( Environment * _environment ) {

}