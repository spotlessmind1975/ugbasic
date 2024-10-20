/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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

/**
 * @brief Emit ASM code for <b>FLIP IMAGE X/Y/XY/YX [image]</b>
 * 
 * This function outputs a code that flip an image
 * 
 * @param _environment Current calling environment
 * @param _image Image to draw
 */
/* <usermanual>
@keyword FLIP IMAGE
@target coco
</usermanual> */ 
void flip_image_vars( Environment * _environment, char * _image, char * _frame, char * _sequence, char * _direction ) {

    if ( _environment->emptyProcedure ) {
        return;
    }

    Variable * image = variable_retrieve( _environment, _image );

    if ( image->bankAssigned != -1 ) {
        CRITICAL_CANNOT_FLIP_BANKED_IMAGE( _image );
    }
    
    Resource * resource = build_resource_for_sequence( _environment, _image, _frame, _sequence );

    Variable * frame = NULL;
    if ( _frame) {
        frame = variable_retrieve_or_define( _environment, _frame, VT_BYTE, 0 );
    }
    Variable * sequence = NULL;
    if ( _sequence) {
        sequence = variable_retrieve_or_define( _environment, _sequence, VT_BYTE, 0 );
    }

    switch( resource->type ) {
        case VT_SEQUENCE:
            if ( !sequence ) {
                if ( !frame ) {
                    c6847_flip_image( _environment, resource, "", "", image->frameSize, image->frameCount, _direction );
                } else {
                    c6847_flip_image( _environment, resource, "", frame->realName, image->frameSize, image->frameCount, _direction );
                }
            } else {
                if ( !frame ) {
                    c6847_flip_image( _environment, resource, "", sequence->realName, image->frameSize, image->frameCount, _direction );
                } else {
                    c6847_flip_image( _environment, resource, frame->realName, sequence->realName, image->frameSize, image->frameCount, _direction );
                }
            }
            break;
        case VT_IMAGES:
            if ( !frame ) {
                c6847_flip_image( _environment, resource, "", NULL, image->frameSize, 0, _direction );
            } else {
                c6847_flip_image( _environment, resource, frame->realName, NULL, image->frameSize, 0, _direction );
            }
            break;
        case VT_IMAGE:
        case VT_TARRAY:
            c6847_flip_image( _environment, resource, NULL, NULL, 0, 0, _direction );
            break;
        default:
            CRITICAL_FLIP_IMAGE_UNSUPPORTED( _image, DATATYPE_AS_STRING[image->type] );
    }

    
}
