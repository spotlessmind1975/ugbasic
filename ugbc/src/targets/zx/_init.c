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

    variable_import( _environment, "BITMAPADDRESS", VT_ADDRESS, 0x4000 );
    variable_global( _environment, "BITMAPADDRESS" );
    variable_import( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0x5800 );
    variable_global( _environment, "COLORMAPADDRESS" );
    variable_import( _environment, "EMPTYTILE", VT_TILE, 32 );
    variable_global( _environment, "EMPTYTILE" );    
    variable_import( _environment, "USING", VT_BYTE, 0 );

    variable_import( _environment, "PLOTCPE", VT_BYTE, 0 );
    variable_global( _environment, "PLOTCPE" );    

    variable_import( _environment, "IMAGEX", VT_BYTE, 0 );
    variable_global( _environment, "IMAGEX" );    
    variable_import( _environment, "IMAGEY", VT_BYTE, 0 );
    variable_global( _environment, "IMAGEY" );    
    variable_import( _environment, "IMAGEY2", VT_BYTE, 0 );
    variable_global( _environment, "IMAGEY2" );    
    variable_import( _environment, "IMAGEW", VT_WORD, 0 );
    variable_global( _environment, "IMAGEW" );    
    variable_import( _environment, "IMAGEH", VT_BYTE, 0 );
    variable_global( _environment, "IMAGEH" );    
    variable_import( _environment, "IMAGEH2", VT_BYTE, 0 );
    variable_global( _environment, "IMAGEH2" );    
    variable_import( _environment, "IMAGEF", VT_BYTE, 0 );
    variable_global( _environment, "IMAGEF" );    
    variable_import( _environment, "IMAGET", VT_BYTE, 0 );
    variable_global( _environment, "IMAGET" );    

    variable_import( _environment, "IRQVECTOR", VT_BUFFER, 3 );
    variable_global( _environment, "IRQVECTOR" );   
    variable_import( _environment, "IRQVECTORREADY", VT_BYTE, 0 );
    variable_global( _environment, "IRQVECTORREADY" );   

    variable_import( _environment, "TICKSPERSECOND", VT_BYTE, 50 );
    variable_global( _environment, "TICKSPERSECOND" );

    bank_define( _environment, "VARIABLES", BT_VARIABLES, 0x5000, NULL );
    bank_define( _environment, "TEMPORARY", BT_TEMPORARY, 0x5100, NULL );

    variable_import( _environment, "DATAPTR", VT_ADDRESS, 0 );
    variable_global( _environment, "DATAPTR" );

    variable_import( _environment, "ZXTIMER", VT_WORD, 0 );
    variable_global( _environment, "ZXTIMER" );    

    variable_import( _environment, "SCANCODEREAD", VT_BUFFER, 16 );
    variable_global( _environment, "SCANCODEREAD" );

    variable_import( _environment, "KEYBOARDPRESSED", VT_BYTE, 0 );
    variable_global( _environment, "KEYBOARDPRESSED" );

    variable_import( _environment, "KEYBOARDACTUAL", VT_BYTE, 0xff );
    variable_global( _environment, "KEYBOARDACTUAL" );

    variable_import( _environment, "KEYBOARDELAPSED", VT_BYTE, 0 );
    variable_global( _environment, "KEYBOARDELAPSED" );

    variable_import( _environment, "KEYBOARDASFSTATE", VT_BYTE, 0 );
    variable_global( _environment, "KEYBOARDASFSTATE" );

    variable_import( _environment, "KEYBOARDQUEUEWPOS", VT_BYTE, 0 );
    variable_global( _environment, "KEYBOARDQUEUEWPOS" );

    variable_import( _environment, "KEYBOARDQUEUERPOS", VT_BYTE, 0 );
    variable_global( _environment, "KEYBOARDQUEUERPOS" );

    variable_import( _environment, "KEYBOARDQUEUE", VT_BUFFER, 10 );
    variable_global( _environment, "KEYBOARDQUEUE" );

    variable_import( _environment, "KEYBOARDINKEY", VT_BYTE, 0xff );
    variable_global( _environment, "KEYBOARDINKEY" );

    variable_import( _environment, "KEYBOARDSHIFT", VT_BYTE, 0 );
    variable_global( _environment, "KEYBOARDSHIFT" );

    variable_import( _environment, "DOJOERROR", VT_BYTE, 0 );
    variable_global( _environment, "DOJOERROR" );

    outhead0("org 32768");

    outhead0("CODESTART:");

    z80_init( _environment );

    deploy_deferred( startup, src_hw_zx_startup_asm);
    outline0("CALL ZXSTARTUP");

    cpu_call( _environment, "VARINIT" );
    outline0("CALL PROTOTHREADINIT" );
    outline0("CALL ZXSTARTUP2" );

    setup_text_variables( _environment );

    zx_initialization( _environment );

    if ( _environment->tenLinerRulesEnforced ) {
        shell_injection( _environment );
        cpu_call( _environment, "VARINIT" );
    }

}

void interleaved_instructions( Environment * _environment ) {

}