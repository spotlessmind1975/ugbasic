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

#if defined(__pc128op__) || defined(__mo5__) || defined(__to8__)

Variable * image_ref( Environment * _environment, char * _image ) {

    Variable * image = variable_retrieve( _environment, _image );

    Variable * imageRef = variable_temporary( _environment, VT_IMAGEREF, "(imageref)" );

    image->usedImage = 1;
    
    switch( image->type ) {
        case VT_IMAGE:
            if ( image->bankAssigned != -1 ) {

                // BASE

                outline1( "LDX #$%4.4x", image->absoluteAddress );
                outline1( "STX %s", imageRef->realName );

                // SIZE

                outline1( "LDD #$%4.4x", image->size );
                outline1( "STD %s+2", imageRef->realName );

                // BANK

                outline1( "LDA #$%2.2x", image->bankAssigned );
                outline1( "STA %s+4", imageRef->realName );

                // INFO

                outline1( "LDA #$%2.2x", 0x0f | ( (image->uncompressedSize>0) ? 0x40 : 0x00 ) );
                outline1( "STA %s+5", imageRef->realName );

                // RESIDENT

                char bankWindowName[MAX_TEMPORARY_STORAGE];
                sprintf( bankWindowName, "BANKWINDOW%2.2x", image->residentAssigned );

                outline1( "LDX #%s", bankWindowName );
                outline1( "STX %s+6", imageRef->realName );

                // TABLE1

                // outline1( "LDX #%soffsetframe", image->realName );
                // outline1( "STX %s+8", imageRef->realName );

                // TABLE2

                // outline1( "LDX #%soffsetsequence", image->realName );
                // outline1( "STX %s+10", imageRef->realName );

            } else {

                // BASE

                outline1( "LDX #%s", image->realName );
                outline1( "STX %s", imageRef->realName );

                // SIZE

                outline1( "LDD #$%4.4x", image->size );
                outline1( "STD %s+2", imageRef->realName );

                // BANK

                // outline1( "LDA #$%2.2x", image->bankAssigned );
                // outline1( "STA %s+4", imageRef->realName );

                // INFO

                outline1( "LDA #$%2.2x", 0X03 | ( (image->uncompressedSize>0) ? 0x40 : 0x00 ) );
                outline1( "STA %s+5", imageRef->realName );

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

                outline1( "LDX #$%4.4x", image->absoluteAddress );
                outline1( "STX %s", imageRef->realName );

                // SIZE

                outline1( "LDD #$%4.4x", image->frameSize );
                outline1( "STD %s+2", imageRef->realName );

                // BANK

                outline1( "LDA #$%2.2x", image->bankAssigned );
                outline1( "STA %s+4", imageRef->realName );

                // INFO

                outline1( "LDA #$%2.2x", 0X1f |( (image->uncompressedSize>0) ? 0x40 : 0x00 ) );
                outline1( "STA %s+5", imageRef->realName );

                // RESIDENT

                char bankWindowName[MAX_TEMPORARY_STORAGE];
                sprintf( bankWindowName, "BANKWINDOW%2.2x", image->residentAssigned );

                outline1( "LDX #%s", bankWindowName );
                outline1( "STX %s+6", imageRef->realName );

                // TABLE1

                outline1( "LDX #%soffsetframe", image->realName );
                outline1( "STX %s+8", imageRef->realName );

                // TABLE2

                // outline1( "LDX #%soffsetsequence", image->realName );
                // outline1( "STX %s+10", imageRef->realName );

            } else {

                // BASE

                outline1( "LDX #%s", image->realName );
                outline1( "STX %s", imageRef->realName );

                // SIZE

                outline1( "LDD #$%4.4x", image->frameSize );
                outline1( "STD %s+2", imageRef->realName );

                // BANK

                // outline1( "LDA #$%2.2x", image->bankAssigned );
                // outline1( "STA %s+4", imageRef->realName );

                // INFO

                outline1( "LDA #$%2.2x", 0x13 | ( (image->uncompressedSize>0) ? 0x40 : 0x00 ) );
                outline1( "STA %s+5", imageRef->realName );

                // RESIDENT

                // char bankWindowName[MAX_TEMPORARY_STORAGE];
                // sprintf( bankWindowName, "BANKWINDOW%2.2x", image->residentAssigned );

                // outline1( "LDX #%s", bankWindowName );
                // outline1( "STX %s+6", imageRef->realName );

                // TABLE1

                outline1( "LDX #%soffsetframe", image->realName );
                outline1( "STX %s+8", imageRef->realName );

                // TABLE2

                // outline1( "LDX #%soffsetsequence", image->realName );
                // outline1( "STX %s+10", imageRef->realName );

            }

            break;

        case VT_SEQUENCE:
            if ( image->bankAssigned != -1 ) {

                // BASE

                outline1( "LDX #$%4.4x", image->absoluteAddress );
                outline1( "STX %s", imageRef->realName );

                // SIZE

                outline1( "LDD #$%4.4x", image->frameSize );
                outline1( "STD %s+2", imageRef->realName );

                // BANK

                outline1( "LDA #$%2.2x", image->bankAssigned );
                outline1( "STA %s+4", imageRef->realName );

                // INFO

                outline1( "LDA #$%2.2x", 0x3f | ( (image->uncompressedSize>0) ? 0x40 : 0x00 ) );
                outline1( "STA %s+5", imageRef->realName );

                // RESIDENT

                char bankWindowName[MAX_TEMPORARY_STORAGE];
                sprintf( bankWindowName, "BANKWINDOW%2.2x", image->residentAssigned );

                outline1( "LDX #%s", bankWindowName );
                outline1( "STX %s+6", imageRef->realName );

                // TABLE1

                outline1( "LDX #%soffsetframe", image->realName );
                outline1( "STX %s+8", imageRef->realName );

                // TABLE2

                outline1( "LDX #%soffsetsequence", image->realName );
                outline1( "STX %s+10", imageRef->realName );

            } else {

                // BASE

                outline1( "LDX #%s", image->realName );
                outline1( "STX %s", imageRef->realName );

                // SIZE

                outline1( "LDD #$%4.4x", image->frameSize );
                outline1( "STD %s+2", imageRef->realName );

                // BANK

                // outline1( "LDA #$%2.2x", image->bankAssigned );
                // outline1( "STA %s+4", imageRef->realName );

                // INFO

                outline1( "LDA #$%2.2x", 0x33 |( (image->uncompressedSize>0) ? 0x40 : 0x00 ) );
                outline1( "STA %s+5", imageRef->realName );

                // RESIDENT

                // char bankWindowName[MAX_TEMPORARY_STORAGE];
                // sprintf( bankWindowName, "BANKWINDOW%2.2x", image->residentAssigned );

                // outline1( "LDX #%s", bankWindowName );
                // outline1( "STX %s+6", imageRef->realName );

                // TABLE1

                outline1( "LDX #%soffsetframe", image->realName );
                outline1( "STX %s+8", imageRef->realName );

                // TABLE2

                outline1( "LDX #%soffsetsequence", image->realName );
                outline1( "STX %s+10", imageRef->realName );

            }

            break;

        default:
            CRITICAL_IMAGEREF_ON_NON_IMAGE( _image );
    }


    return imageRef;

}

#endif
