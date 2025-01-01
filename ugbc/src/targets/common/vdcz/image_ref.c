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

#include "../../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

#if defined(__c128z__)

Variable * image_ref( Environment * _environment, char * _image ) {

    Variable * image = variable_retrieve( _environment, _image );

    Variable * imageRef = variable_temporary( _environment, VT_IMAGEREF, "(imageref)" );

    image->usedImage = 1;

    outline1( "LD IX, %s", imageRef->realName );

    switch( image->type ) {
        case VT_IMAGE:
            if ( image->bankAssigned != -1 ) {

                // BASE

                outline1( "LD HL, $%4.4x", image->absoluteAddress );
                outline0( "LD (IX), L" );
                outline0( "LD (IX+1), H" );

                // SIZE

                outline1( "LD HL, $%4.4x", image->frameSize );
                outline0( "LD (IX+2), L" );
                outline0( "LD (IX+3), H" );

                // BANK

                outline1( "LDA $%2.2x", image->bankAssigned );
                outline0( "LD (IX+4), A" );

                // INFO

                outline0( "LD A, $0f" );
                outline0( "LD (IX+5), A" );

                // RESIDENT

                char bankWindowName[MAX_TEMPORARY_STORAGE];
                sprintf( bankWindowName, "BANKWINDOW%2.2x", image->residentAssigned );
                outline1( "LD HL, %s", bankWindowName );
                outline0( "LD (IX+6), L" );
                outline0( "LD (IX+7), H" );
                
                // TABLE1

                // outline1( "LDX #%soffsetframe", image->realName );
                // outline1( "STX %s+8", imageRef->realName );

                // TABLE2

                // outline1( "LDX #%soffsetsequence", image->realName );
                // outline1( "STX %s+10", imageRef->realName );

            } else {

                // BASE

                outline1( "LD HL, %s", image->realName  );
                outline0( "LD (IX), L" );
                outline0( "LD (IX+1), H" );

                // SIZE

                outline1( "LD HL, $%4.4x", image->frameSize );
                outline0( "LD (IX+2), L" );
                outline0( "LD (IX+3), H" );

                // BANK

                // outline1( "LDA #$%4.4x", image->bankAssigned );
                // outline1( "STA %s+4", imageRef->realName );

                // INFO

                outline0( "LD A, $03" );
                outline0( "LD (IX+5), A" );

                // RESIDENT

                // char bankWindowName[MAX_TEMPORARY_STORAGE];
                // sprintf( bankWindowName, "BANKWINDOW%2.2x", image->residentAssigned );

                // outline1( "LDX #%s", bankWindowName );
                // outline1( "STX %s+6", imageRef->realName );

                // TABLE1

                // outline1( "LDX #%soffsetframe", image->realName );
                // outline1( "STX %s+8", imageRef->realName );

                // TABLE2

                // outline1( "LDX #%soffsetsequence", image->realName );
                // outline1( "STX %s+10", imageRef->realName );

            }

            break;

        case VT_IMAGES:
            if ( image->bankAssigned != -1 ) {

                // BASE

                outline1( "LD HL, #$%4.4x", image->absoluteAddress );
                outline0( "LD (IX), L" );
                outline0( "LD (IX+1), H" );

                // SIZE

                outline1( "LD HL, $%4.4x", image->frameSize );
                outline0( "LD (IX+2), L" );
                outline0( "LD (IX+3), H" );

                // BANK

                outline1( "LD A, $%2.2x", image->bankAssigned );
                outline0( "LD (IX+4), A" );

                // INFO

                outline0( "LD A, $0f" );
                outline0( "LD (IX+5), A" );

                // RESIDENT

                char bankWindowName[MAX_TEMPORARY_STORAGE];
                sprintf( bankWindowName, "BANKWINDOW%2.2x", image->residentAssigned );
                outline1( "LD HL, %s", bankWindowName );
                outline0( "LD (IX+6), L" );
                outline0( "LD (IX+7), H" );

                // TABLE1

                outline1( "LD HL, %soffsetframe", image->realName );
                outline0( "LD (IX+8), L" );
                outline0( "LD (IX+9), H" );

                // TABLE2

                // outline1( "LDX #%soffsetsequence", image->realName );
                // outline1( "STX %s+10", imageRef->realName );

            } else {

                // BASE

                outline1( "LD HL, %s", image->realName  );
                outline0( "LD (IX), L" );
                outline0( "LD (IX+1), H" );

                // SIZE

                outline1( "LD HL, $%4.4x", image->frameSize );
                outline0( "LD (IX+2), L" );
                outline0( "LD (IX+3), H" );

                // BANK

                // outline1( "LDA #$%4.4x", image->bankAssigned );
                // outline1( "STA %s+4", imageRef->realName );

                // INFO

                outline0( "LD A, $03" );
                outline0( "LD (IX+5), A" );

                // RESIDENT

                // char bankWindowName[MAX_TEMPORARY_STORAGE];
                // sprintf( bankWindowName, "BANKWINDOW%2.2x", image->residentAssigned );

                // outline1( "LDX #%s", bankWindowName );
                // outline1( "STX %s+6", imageRef->realName );

                // TABLE1

                outline1( "LD HL, %soffsetframe", image->realName );
                outline0( "LD (IX+8), L" );
                outline0( "LD (IX+9), H" );

                // TABLE2

                // outline1( "LDX #%soffsetsequence", image->realName );
                // outline1( "STX %s+10", imageRef->realName );

            }

            break;

        case VT_SEQUENCE:
            if ( image->bankAssigned != -1 ) {

                // BASE

                outline1( "LD HL, $%4.4x", image->absoluteAddress );
                outline0( "LD (IX), L" );
                outline0( "LD (IX+1), H" );

                // SIZE

                outline1( "LD HL, $%4.4x", image->frameSize );
                outline0( "LD (IX+2), L" );
                outline0( "LD (IX+3), H" );

                // BANK

                outline1( "LD A, $%2.2x", image->bankAssigned );
                outline0( "LD (IX+4), HL" );

                // INFO

                outline0( "LD A, $0f" );
                outline0( "LD (IX+5), A" );

                // RESIDENT

                char bankWindowName[MAX_TEMPORARY_STORAGE];
                sprintf( bankWindowName, "BANKWINDOW%2.2x", image->residentAssigned );
                outline1( "LD HL, %s", bankWindowName );
                outline0( "LD (IX+6), L" );
                outline0( "LD (IX+7), H" );

                // TABLE1

                outline1( "LD HL, %soffsetframe", image->realName );
                outline0( "LD (IX+8), L" );
                outline0( "LD (IX+8), H" );

                // TABLE2

                outline1( "LD HL, %soffsetsequence", image->realName );
                outline0( "LD (IX+8), L" );                
                outline0( "LD (IX+8), H" );                

            } else {

                // BASE

                outline1( "LD HL, %s", image->realName  );
                outline0( "LD (IX), L" );
                outline0( "LD (IX+1), H" );

                // SIZE

                outline1( "LD HL, #$%4.4x", image->frameSize );
                outline0( "LD (IX+2), L" );
                outline0( "LD (IX+3), H" );

                // BANK

                // outline1( "LDA #$%4.4x", image->bankAssigned );
                // outline1( "STA %s+4", imageRef->realName );

                // INFO

                outline0( "LD A, #$03" );
                outline0( "LD (IX+5), A" );

                // RESIDENT

                // char bankWindowName[MAX_TEMPORARY_STORAGE];
                // sprintf( bankWindowName, "BANKWINDOW%2.2x", image->residentAssigned );

                // outline1( "LDX #%s", bankWindowName );
                // outline1( "STX %s+6", imageRef->realName );

                // TABLE1

                outline1( "LD HL, #%soffsetframe", image->realName );
                outline0( "LD (IX+8), L" );
                outline0( "LD (IX+9), H" );

                // TABLE2

                outline1( "LD HL, #%soffsetsequence", image->realName );
                outline0( "LD (IX+8), L" );
                outline0( "LD (IX+9), H" );

            }

            break;

        default:
            CRITICAL_IMAGEREF_ON_NON_IMAGE( _image );
    }


    return imageRef;

}

#endif
