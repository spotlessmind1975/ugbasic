/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
#include "../../stb_image.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>IMAGE LOAD(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 * @param _mode Mode to use to convert data
 */
/* <usermanual>
@keyword IMAGES LOAD

@english
The ''IMAGES LOAD'' command allows you to load an image and to convert
in an array of images. Each image will be of [w]x[h] pixels. Offset
will be calculated automatically on the base of the original image.

@italian
Il comando ''IMAGES LOAD'' permette di caricare un'immagine e di convertirla
in una serie di immagini. Ogni immagine sarà di [w]x[h] pixel. Lo scostamentto
di ogni fotogramma è calcolato automaticamente sulla base dell'immagine originale. 

@syntax = IMAGES LOAD([filename]) FRAME SIZE ([w],[h])

@example starship = IMAGES LOAD("starship.png") FRAME SIZE (8,8)
@example alienAt11 = IMAGES LOAD("alien.png") FRAME SIZE (16,16)

@usedInExample images_loading_01.bas

@target all
</usermanual> */
Variable * images_load( Environment * _environment, char * _filename, char * _alias, int _mode, int _frame_width, int _frame_height ) {

    LoadedFile * first = _environment->loadedFiles;
    char *lookfor = _filename;
    if ( _alias ) {
        lookfor = _alias;
    }
    while( first ) {
        if ( strcmp(lookfor, first->fileName ) == 0 ) {
            return first->variable;
        }
        first = first->next;
    }

    int width = 0;
    int height = 0;
    int depth = 3;

    char * lookedFilename = image_load_asserts( _environment, _filename );

    unsigned char* source = stbi_load(lookedFilename, &width, &height, &depth, 0);

    if ( !source ) {
        CRITICAL_IMAGE_LOAD_UNKNOWN_FORMAT( _filename );
    }

    if ( width % _frame_width ) {
        CRITICAL_IMAGES_LOAD_INVALID_FRAME_WIDTH( _frame_width );
    }

    if ( height % _frame_height ) {
        CRITICAL_IMAGES_LOAD_INVALID_FRAME_HEIGHT( _frame_height );
    }

    int wc = ( width / _frame_width );
    int hc = ( height / _frame_height );

    Variable * result[MAX_TEMPORARY_STORAGE];
    int i=0,x=0,y=0;
    int bufferSize = 0;
    for( y=0; y<height; y+=_frame_height ) {
        for( x=0; x<width; x+=_frame_width ) {
            result[i] = image_converter( _environment, source, width, height, x, y, _frame_width, _frame_height, _mode );
            bufferSize += result[i]->size;
            ++i;
        }
    }

    char * buffer = malloc( bufferSize );
    char * ptr = buffer;
    for(i=0; i<wc*hc; ++i ) {
        memcpy( ptr, result[i]->valueBuffer, result[i]->size );
        ptr += result[i]->size;
    }
    Variable * final = variable_temporary( _environment, VT_IMAGES, 0 );

    variable_store_buffer( _environment, final->name, buffer, bufferSize, 0 );

    for(i=0; i<wc*hc; ++i ) {
        variable_temporary_remove( _environment, result[i]->name );
    }

    stbi_image_free(source);

    LoadedFile * loaded = malloc( sizeof( LoadedFile ) );
    loaded->next = first;
    loaded->variable = final;
    loaded->fileName = lookfor;
    _environment->loadedFiles = loaded;

    return final;

}
