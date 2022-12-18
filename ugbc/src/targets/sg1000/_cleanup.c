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

void target_finalization( Environment * _environment ) {

    tms9918_finalization( _environment );
    sn76489_finalization( _environment );

    outhead0("section data_user");
    outhead0("LASTVAR: db $42");
    outhead0("section code_user");

    if ( ! _environment->anyProtothread ) {
        outhead0("PROTOTHREADINIT:" );
        outline0("RET");
    }

    outhead0("VARINIT2:");

    outhead0("if (LASTVAR) < ( 2048 - 128 )"); 
    outline0("LD HL, CODEEND");
    outline0("LD DE, $C000");
    outline0("LD BC, LASTVAR - $C000 + 1" );
    outline0("LDIR" );
    outhead0("endif"); 
    outline0("RET");

    outhead0("CODEEND:");

}

void target_analysis( Environment * _environment ) {
    
}