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
in an array of images. Each image will be of ''[w]x[h]'' pixels. Offset
will be calculated automatically on the base of the original image.

The command support a set of modern image format, like:

  * JPEG baseline & progressive
  * PNG 1/2/4/8/16-bit-per-channel
  * TGA
  * BMP (non-1bpp, non-RLE)
  * PSD (composited view only, no extra channels, 8/16 bit-per-channel)
  * GIF
  * HDR (radiance rgbE format)
  * PIC (Softimage PIC)
  * PNM (PPM and PGM binary only)

The image will be converted into a way that can be efficiently drawn
on the screen. It could be converted into indexed palette, and can be
rescaled as well.

Since it is possible to load only one file of the same type at a time, it is necessary 
to be able to indicate an "alias" with which to exceed this limit. In this regard, there is also
the ''AS'' syntax, which allows you to load the same file several times but with different names.

@italian
Il comando ''IMAGES LOAD'' permette di caricare un'immagine e di convertirla
in una serie di immagini. Ogni immagine sarà di ''[w]x[h]'' pixel. Lo scostamentto
di ogni fotogramma è calcolato automaticamente sulla base dell'immagine originale. 

Il comando supporta una serie di formati moderni:

  * JPEG baseline & progressive
  * PNG 1/2/4/8/16-bit-per-canale
  * TGA
  * BMP (non-1bpp, non-RLE)
  * PSD (vista composita, nessun canale extra, 8/16 bit-per-canale)
  * GIF
  * HDR (formato radiance rgbE)
  * PIC (Softimage PIC)
  * PNM (solo formato binario PPM e PGM)

L'immagine verrà convertita in un modo che possa essere disegnata in modo efficiente
sullo schermo. Potrebbe essere convertita in una tavolozza indicizzata, e potrebbe essere
anche ridimensionata.

Dal momento in cui è possibile caricare un solo file dello stesso tipo alla volta, 
è necessario poter indicare un "alias" con cui superare questo limite. A tal riguardo 
esiste anche la sintassi ''AS'', che permette di caricare più volte lo stesso file 
ma con nomi diversi.

@syntax = IMAGES LOAD([filename]) FRAME SIZE ([w],[h])
@syntax = IMAGES LOAD([filename] AS [alias]) FRAME SIZE ([w],[h])

@example starship = IMAGES LOAD("starship.png") FRAME SIZE (8,8)
@example alienAt11 = IMAGES LOAD("alien.png") FRAME SIZE (16,16)
@example alien2 = IMAGES LOAD("alien.png" AS "alien2") FRAME SIZE (16,16)

@usedInExample images_loading_01.bas

@target all
</usermanual> */
Variable * images_load( Environment * _environment, char * _filename, char * _alias, int _mode, int _frame_width, int _frame_height, int _flags ) {

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
    int i,di,x=0,y=0;
    int bufferSize = 0;

    if( _flags & FLIP_X ) {
        source = image_flip_x( _environment, source, width, height );
        i = (hc*wc)-1;
        di = -1;
    } else {
        i = 0;
        di = 1;
    }
    if( _flags & FLIP_Y ) {
        source = image_flip_y( _environment, source, width, height );
    }

    for( y=0; y<height; y+=_frame_height ) {
        for( x=0; x<width; x+=_frame_width ) {
            result[i] = image_converter( _environment, source, width, height, x, y, _frame_width, _frame_height, _mode );
            bufferSize += result[i]->size;
            i += di;
        }
    }

    char * buffer = malloc( bufferSize + 2 );
    char * ptr = buffer;
    #if CPU_LITTLE_ENDIAN
        ptr[0] = bufferSize & 0xff;
        ptr[1] = ( bufferSize >> 8 ) & 0xff;
    #else
        ptr[0] = ( bufferSize >> 8 ) & 0xff;
        ptr[1] = bufferSize & 0xff;
    #endif

    offsetting_size_count( _environment, result[0]->size, wc*hc );

    ptr += 2;
    for(i=0; i<wc*hc; ++i ) {
        memcpy( ptr, result[i]->valueBuffer, result[i]->size );
        ptr += result[i]->size;
    }
    Variable * final = variable_temporary( _environment, VT_IMAGES, 0 );
    variable_store_buffer( _environment, final->name, buffer, bufferSize, 0 );
    final->frameSize = result[0]->size;
    final->frameCount = wc * hc;

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
