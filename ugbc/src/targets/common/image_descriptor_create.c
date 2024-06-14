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
#include "../../libs/stb_image.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

ImageDescriptor * image_descriptor_create( Environment * _environment, char * _filename, int _flags ) {

    ImageDescriptor * result = malloc( sizeof( ImageDescriptor ) );
    memset( result, 0, sizeof( ImageDescriptor ) );

    // We must load the target dependent version of the images.
    char * lookedFilename = resource_load_asserts( _environment, _filename );

    // If present, we can calculate the effective size.
    result->fileSize = file_get_size( _environment, lookedFilename );

    // Now we can decode the image using the external library.
    result->data = stbi_load( lookedFilename, &result->width, &result->height, &result->depth, 0 );
    result->size = result->width * result->height * result->depth;
    result->colors = malloc_palette( MAX_PALETTE );
    result->colorsCount = MAX_PALETTE;
    result->colorsCount = rgbi_extract_palette( _environment, result->data, result->width, result->height, result->depth, result->colors, result->colorsCount, 1 );

    // If we are unable to decode the image, we stop the compilation.
    if ( !result->data ) {
        CRITICAL_IMAGE_LOAD_UNKNOWN_FORMAT( _filename );
    }

    // If the image has to be post processed, we do it:
    //  - X FLIP
    if( _flags & FLAG_FLIP_X ) {
        result = image_descriptor_flip_x( _environment, result );
    }
    //  - Y FLIP
    if( _flags & FLAG_FLIP_Y ) {
        result = image_descriptor_flip_y( _environment, result );
    }

    // ADI INFO
    adiline4("LI:%s:%s:%x:%x", _filename, lookedFilename, result->fileSize, result->size );

    return result;

}
