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
 * @brief Emit ASM code for <b>BLIT IMAGE [image] AT [int],[int]</b>
 * 
 * This function outputs a code that draws an image on a bitmap. 
 * 
 * @param _environment Current calling environment
 * @param _image Image to draw
 * @param _x Abscissa of the point to draw
 * @param _y Ordinate of the point
 */
/* <usermanual>
@keyword BLIT IMAGE
</usermanual> */
void blit_image( Environment * _environment, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _flags ) {

    char * sources[MAX_TEMPORARY_STORAGE];

    Variable * image;
    VariableType vtImage = VT_BYTE;

    int i = 0;
    for(i=0; i<_environment->blit.sourceCount; ++i ) {
        image = variable_retrieve( _environment, _environment->blit.sources[i] );
        if ( vtImage == VT_BYTE ) {
            vtImage = image->type;
        }
        if ( image->type != vtImage ) {
            CRITICAL_BLIT_CANNOT_MIX_IMAGE_TYPES( _environment->blit.sources[i] );
        }
        if ( image ) {
            sources[i] = strdup( image->realName );
        }
    }

    Variable * blit = variable_retrieve( _environment, _blit );
    if ( blit->type != VT_BLIT ) {
        CRITICAL_BLIT_CANNOT_BLIT( _blit );
    }

    char blitLabel[MAX_TEMPORARY_STORAGE]; sprintf( blitLabel, "_%sblit", _blit );
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

    switch( vtImage ) {
        case VT_SEQUENCE:
            if ( !sequence ) {
                if ( !frame ) {
                    gime_blit_image( _environment, sources, _environment->blit.sourceCount, blitLabel, x->realName, y->realName, "", "", image->frameSize, image->frameCount, _flags );
                } else {
                    gime_blit_image( _environment, sources, _environment->blit.sourceCount, blitLabel, x->realName, y->realName, frame->realName, "", image->frameSize, image->frameCount, _flags );
                }
            } else {
                if ( !frame ) {
                    gime_blit_image( _environment, sources, _environment->blit.sourceCount, blitLabel, x->realName, y->realName, "", sequence->realName, image->frameSize, image->frameCount, _flags );
                } else {
                    gime_blit_image( _environment, sources, _environment->blit.sourceCount, blitLabel, x->realName, y->realName, frame->realName, sequence->realName, image->frameSize, image->frameCount, _flags );
                }
            }
            break;
        case VT_IMAGES:
            if ( !frame ) {
                gime_blit_image( _environment, sources, _environment->blit.sourceCount, blitLabel, x->realName, y->realName, "", NULL, image->frameSize, 0, _flags );
            } else {
                gime_blit_image( _environment, sources, _environment->blit.sourceCount, blitLabel, x->realName, y->realName, frame->realName, NULL, image->frameSize, 0, _flags );
            }
            break;
        case VT_IMAGE:
            gime_blit_image( _environment, sources, _environment->blit.sourceCount, blitLabel, x->realName, y->realName, NULL, NULL, 0, 0, _flags );
            break;
        default:
            CRITICAL_BLIT_IMAGE_UNSUPPORTED( image->name, DATATYPE_AS_STRING[image->type] );
    }

    _environment->blit.sourceCount = 0;

}