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

ImageDescriptor * image_descriptor_roll_x_left( Environment * _environment, ImageDescriptor * _source_image ) {

    ImageDescriptor * copy = malloc( sizeof( ImageDescriptor ) );
    memcpy( copy, _source_image, sizeof( ImageDescriptor ) );

    copy->next = NULL;

    copy->data = malloc( copy->size );
    memset( copy->data, 0, copy->size );

    copy->colors = malloc( sizeof( RGBi ) * copy->colorsCount );
    memcpy( copy->colors, _source_image->colors, sizeof( RGBi ) * copy->colorsCount );

    char * source = copy->data;

    int x,y;

    for( y=0; y<copy->height; ++y ) {

        unsigned char * pixel2r = source + ( y * copy->width * 3 );
        unsigned char * pixel2g = source + ( y * copy->width * 3 ) + 1;
        unsigned char * pixel2b = source + ( y * copy->width * 3 ) + 2;        

        unsigned char r, g, b;
        
        r = *pixel2r;
        g = *pixel2g;
        b = *pixel2b;

        for( x=0; x<copy->width-2; ++x ) {
            unsigned char * pixel1r = source + ( y * copy->width * 3 ) + ( (x+1) * 3 );
            unsigned char * pixel1g = source + ( y * copy->width * 3 ) + ( (x+1) * 3 ) + 1;
            unsigned char * pixel1b = source + ( y * copy->width * 3 ) + ( (x+1) * 3 ) + 2;
            unsigned char * pixel2r = source + ( y * copy->width * 3 ) + ( (x) * 3 );
            unsigned char * pixel2g = source + ( y * copy->width * 3 ) + ( (x) * 3 ) + 1;
            unsigned char * pixel2b = source + ( y * copy->width * 3 ) + ( (x) * 3 ) + 2;
            
            // printf( "%d,%d : %2.2x%2.2x%2.2x -> %2.2x%2.2x%2.2x\n", y, x, (unsigned char) *pixel2r, (unsigned char) *pixel2g, (unsigned char) *pixel2b, (unsigned char) *pixel1r, (unsigned char) *pixel1g, (unsigned char) *pixel1b );

            *pixel2r = (unsigned char) *pixel1r;
            *pixel2g = (unsigned char) *pixel1g;
            *pixel2b = (unsigned char) *pixel1b;

        }

        unsigned char * pixel1r = source + ( y * copy->width * 3 ) + ( (copy->width-1) * 3 );
        unsigned char * pixel1g = source + ( y * copy->width * 3 ) + ( (copy->width-1) * 3 ) + 1;
        unsigned char * pixel1b = source + ( y * copy->width * 3 ) + ( (copy->width-1) * 3 ) + 2;

        *pixel1r = r;
        *pixel1g = g;
        *pixel1b = b;
    }

    // f = fopen("/tmp/picture2.bin", "wb" );
    // fwrite( source, copy->width * copy->height * 3, 1, f );
    // fclose( f );

    return copy;
    
}
