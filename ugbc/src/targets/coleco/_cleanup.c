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

void target_prepare_finalization( Environment * _environment ) {

    if ( _environment->deployed.timer ) {
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
    }

    if ( _environment->deployed.tiles ) {

    } else {
        variable_delete( _environment, "TILEX" );
        variable_delete( _environment, "TILEY" );
        variable_delete( _environment, "TILEX2" );
        variable_delete( _environment, "TILET" );
        variable_delete( _environment, "TILEW" );
        variable_delete( _environment, "TILEH" );
        variable_delete( _environment, "TILEW2" );
        variable_delete( _environment, "TILEH2" );
        variable_delete( _environment, "TILEA" );
        variable_delete( _environment, "TILEO" );
    }

    if ( _environment->deployed.blitimage ) {

    } else {
        variable_delete( _environment, "BLITIMAGEBLITTINGADDR" );
        variable_delete( _environment, "BLITTMPPTR" );
        variable_delete( _environment, "BLITTMPPTR2" );
    }

    if ( _environment->deployed.sliceimageextract ) {

    } else {
        variable_delete( _environment, "SLICEX" );
        variable_delete( _environment, "SLICEY" );
        variable_delete( _environment, "SLICEDTARGET" );
    }

}

void target_finalization( Environment * _environment ) {

    tms9918_finalization( _environment );
    sn76489z_finalization( _environment );

    outhead0("section data_user");
    outhead0("LASTVAR: db $42");
    outhead0("section code_user");

    if ( ! _environment->anyProtothread ) {
        outhead0("PROTOTHREADINIT:" );
        outline0("RET");
    }

    outhead0("VARINIT2:");

    outhead0("if (LASTVAR) < ( 1024 - 128 )"); 
    outline0("LD HL, CODEEND");
    outline0("LD DE, $7030");
    outline0("LD BC, LASTVAR - $7030 + 1" );
    outline0("LDIR" );
    outhead0("endif"); 
    outline0("RET");

    outhead0("CODEEND:");

}

void target_analysis( Environment * _environment ) {
    
}