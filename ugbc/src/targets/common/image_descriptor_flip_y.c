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

ImageDescriptor * image_descriptor_flip_y( Environment * _environment, ImageDescriptor * _source_image ) {

    ImageDescriptor * copy = malloc( sizeof( ImageDescriptor ) );
    memcpy( copy, _source_image, sizeof( ImageDescriptor ) );

    copy->next = NULL;

    copy->data = malloc( copy->size );
    memset( copy->data, 0, copy->size );

    copy->colors = malloc( sizeof( RGBi ) * copy->colorsCount );
    memcpy( copy->colors, _source_image->colors, sizeof( RGBi ) * copy->colorsCount );

    char * source = copy->data;

    int x,y;

    for( x=0; x<copy->width; ++x ) {
        for( y=0; y<( copy->height >> 1 ); ++y ) {
            char * pixel1r = source + ( y * copy->width * copy->depth ) + ( x * copy->depth );
            char * pixel1g = source + ( y * copy->width * copy->depth ) + ( x * copy->depth ) + 1;
            char * pixel1b = source + ( y * copy->width * copy->depth ) + ( x * copy->depth ) + 2;
            char * pixel1a;
            if ( copy->depth > 3 ) {
                pixel1b = source + ( y * copy->width * copy->depth ) + ( x * copy->depth ) + 3;
            }
            char * pixel2r = source + ( ( copy->height - y - 1) * copy->width * copy->depth ) + ( x * copy->depth );
            char * pixel2g = source + ( ( copy->height - y - 1) * copy->width * copy->depth ) + ( x * copy->depth ) + 1;
            char * pixel2b = source + ( ( copy->height - y - 1) * copy->width * copy->depth ) + ( x * copy->depth ) + 2;
            char * pixel2a;
            if ( copy->depth > 3 ) {
                pixel2b = source + ( ( copy->height - y - 1) * copy->width * copy->depth ) + ( x * copy->depth ) + 3;
            }
            
            char t;
            
            t = *pixel1r;
            *pixel1r = *pixel2r;
            *pixel2r = t;

            t = *pixel1g;
            *pixel1g = *pixel2g;
            *pixel2g = t;

            t = *pixel1b;
            *pixel1b = *pixel2b;
            *pixel2b = t;

            if ( copy->depth > 3 ) {
                t = *pixel1a;
                *pixel1a = *pixel2a;
                *pixel2a = t;
            }
            
        }
    }

    return copy;
    
}
