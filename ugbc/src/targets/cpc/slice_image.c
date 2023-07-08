/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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

extern char DATATYPE_AS_STRING[][16];

/* <usermanual>
@keyword SLICE IMAGE

@english

@italian

@syntax SLICE IMAGE [image] AT [x],[y]

@example SLICE IMAGE airplane TO plane

@target all

</usermanual> */
void slice_image( Environment * _environment, char * _image, char * _frame, char * _sequence, char * _destination ) {

    Variable * image = variable_retrieve( _environment, _image );
    Variable * destination = variable_retrieve( _environment, _destination );
    Variable * frame = NULL;
    if ( _frame) {
        frame = variable_retrieve_or_define( _environment, _frame, VT_BYTE, 0 );
    }
    Variable * sequence = NULL;
    if ( _sequence) {
        sequence = variable_retrieve_or_define( _environment, _sequence, VT_BYTE, 0 );
    }

    CpcSliceImageFunction cpc_slice_image = NULL;;
    if ( 
            ! _environment->sliceImageX && ! _environment->sliceImageY
            ) {
        cpc_slice_image = cpc_slice_image_copy;
    } else {
        cpc_slice_image = cpc_slice_image_extract;
    }

    switch( image->type ) {
        case VT_SEQUENCE:
            if ( !sequence ) {
                if ( !frame ) {
                    cpc_slice_image( _environment, image->realName, "", "", image->frameSize, image->frameCount, destination->realName );
                } else {
                    cpc_slice_image( _environment, image->realName, frame->realName, "", image->frameSize, image->frameCount, destination->realName );
                }
            } else {
                if ( !frame ) {
                    cpc_slice_image( _environment, image->realName, "", sequence->realName, image->frameSize, image->frameCount, destination->realName );
                } else {
                    cpc_slice_image( _environment, image->realName, frame->realName, sequence->realName, image->frameSize, image->frameCount, destination->realName );
                }
            }
            break;
        case VT_IMAGES:
            if ( !frame ) {
                cpc_slice_image( _environment, image->realName, "", NULL, image->frameSize, 0, destination->realName );
            } else {
                cpc_slice_image( _environment, image->realName, frame->realName, NULL, image->frameSize, 0, destination->realName );
            }
            break;
        case VT_IMAGE:
            cpc_slice_image( _environment, image->realName, NULL, NULL, 0, 0, destination->realName );
            break;
        default:
            CRITICAL_SLICE_IMAGE_UNSUPPORTED( _image, DATATYPE_AS_STRING[image->type] );
    }
    
}