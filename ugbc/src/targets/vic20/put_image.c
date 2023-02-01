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

/**
 * @brief Emit ASM code for <b>PUT IMAGE [image] AT [int],[int]</b>
 * 
 * This function outputs a code that draws an image on a bitmap. 
 * 
 * @param _environment Current calling environment
 * @param _image Image to draw
 * @param _x Abscissa of the point to draw
 * @param _y Ordinate of the point
 */
/* <usermanual>
@keyword PUT IMAGE
</usermanual> */
void put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _flags ) {

    Variable * image = variable_retrieve( _environment, _image );
    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    Variable * frame = NULL;
    if ( _frame) {
        frame = variable_retrieve_or_define( _environment, _frame, VT_BYTE, 0 );
    }
    Variable * sequence = NULL;
    if ( _sequence) {
        sequence = variable_retrieve_or_define( _environment, _sequence, VT_BYTE, 0 );
    }

    switch( image->type ) {
        case VT_SEQUENCE:
           if ( !sequence ) {
                if ( !frame ) {
                    vic1_put_image( _environment, image->realName, x->realName, y->realName, "", "", image->frameSize, image->frameCount, _flags );
                } else {
                    vic1_put_image( _environment, image->realName, x->realName, y->realName, frame->realName, "", image->frameSize, image->frameCount, _flags );
                }
            } else {
                if ( !frame ) {
                    vic1_put_image( _environment, image->realName, x->realName, y->realName, "", sequence->realName, image->frameSize, image->frameCount, _flags );
                } else {
                    vic1_put_image( _environment, image->realName, x->realName, y->realName, frame->realName, sequence->realName, image->frameSize, image->frameCount, _flags );
                }
            }
            break;
        case VT_IMAGES:
            if ( !frame ) {
                vic1_put_image( _environment, image->realName, x->realName, y->realName, "", NULL, image->frameSize, 0, _flags );
            } else {
                vic1_put_image( _environment, image->realName, x->realName, y->realName, frame->realName, NULL, image->frameSize, 0, _flags );
            }
            break;
        case VT_IMAGE:
            vic1_put_image( _environment, image->realName, x->realName, y->realName, NULL, NULL, 0, 0, _flags );
            break;
        default:
            CRITICAL_PUT_IMAGE_UNSUPPORTED( _image, DATATYPE_AS_STRING[image->type] );
    }


}