/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
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
#include "../../libs/msc1.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>LOAD IMAGE(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 * @param _mode Mode to use to convert data
 */
/* <usermanual>
@keyword LOAD IMAGES

@english
The ''LOAD IMAGES'' command allows you to load an image and to convert 
in an array of images. Each image will be of ''[w]x[h]'' pixels. The 
offset of each frame is automatically calculated based on the original 
image, with the possible addition of an offset equal to ''(dx,dy)'' 
with the use of the keyword ''OFFSET''. It is possible to start 
cropping images from the ''(x,y)'' position using the ''ORIGIN'' keyword.

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
Il comando ''LOAD IMAGES'' permette di caricare un'immagine e di convertirla
in una serie di immagini. Ogni immagine sarà di ''[w]x[h]'' pixel. Lo scostamentto
di ogni fotogramma è calcolato automaticamente sulla base dell'immagine originale,
con l'eventuale aggiunta di uno scostamento pari a ''(dx,dy)'' con l'uso della
parola chiave ''OFFSET''. E' possibile far partire il ritaglio delle immagini
dalla posizione ''(x,y)'' utilizando la parola chiave ''ORIGIN''.

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

@syntax = LOAD IMAGES(filename) FRAME SIZE (w,h) [ OFFSET(dx,dy) [ ORIGIN(x,y) ] ]
@syntax = LOAD IMAGES(filename AS alias) FRAME SIZE (w,h) [ OFFSET(dx,dy) [ ORIGIN(x,y) ] ]

@example starship = LOAD IMAGES("starship.png") FRAME SIZE (8,8)
@example alienAt11 = LOAD IMAGES("alien.png") FRAME SIZE (16,16) OFFSET(1,1)
@example alien2 = LOAD IMAGES("alien.png" AS "alien2") FRAME SIZE (16,16) OFFSET(1,1) ORIGIN(1,1)

@usedInExample images_loading_01.bas

@target all
</usermanual> */
Variable * images_load( Environment * _environment, char * _filename, char * _alias, int _mode, int _frame_width, int _frame_height, int _flags, int _transparent_color, int _background_color, int _bank_expansion, int _origin_x, int _origin_y, int _offset_x, int _offset_y ) {

    printf( "-> %s\n", _filename );
    
    Variable * final = variable_temporary( _environment, VT_IMAGES, 0 );

    if ( _environment->emptyProcedure ) {
        return final;
    }

    if ( _environment->tenLinerRulesEnforced ) {
        CRITICAL_10_LINE_RULES_ENFORCED( "LOAD IMAGES");
    }

    if ( _environment->sandbox ) {
        CRITICAL_SANDBOX_ENFORCED( "LOAD IMAGES");
    }

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

    AtlasDescriptor * atlasDescriptor = atlas_descriptor_create( _environment, _filename, _flags, _origin_x, _origin_y, _frame_width, _frame_height, _offset_x, _offset_y );

    adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_STANDARD );

    int bufferSize = 0;
    Variable * firstImage = NULL;
    Variable * lastImage = NULL;

    Variable * partial;
    ImageDescriptor * frame = atlasDescriptor->frames;
    for(int i=0; i<atlasDescriptor->count; ++i ) {
        partial = image_converter( _environment, frame->data, frame->width, frame->height, frame->depth, 0, 0, frame->width, frame->height, _mode, _transparent_color, _flags );
        if ( !firstImage && !lastImage ) {
            firstImage = partial;
            lastImage = firstImage;
        } else {
            lastImage->next = partial;
            lastImage = lastImage->next;
        }
        frame = frame->next;
    }

    bufferSize += partial->size;

    bufferSize += 3;

    adiline1("LIS2:%x", bufferSize );

    char * buffer = malloc( bufferSize );
    char * ptr = buffer;
    ptr[0] = atlasDescriptor->count;
    ptr[1] = ( _frame_width & 0xff );
    ptr[2] = ( _frame_width >> 8 ) & 0xff;

    if ( ( firstImage->size * atlasDescriptor->count ) > 0xffff ) {
        CRITICAL_IMAGES_LOAD_IMAGE_TOO_BIG( _filename );
    }

    final->offsettingFrames = offsetting_size_count( _environment, firstImage->size, atlasDescriptor->count );
    offsetting_add_variable_reference( _environment, final->offsettingFrames, final, 0 );

    ptr += 3;
    lastImage = firstImage;
    for(int i=0; i<atlasDescriptor->count; ++i ) {
        memcpy( ptr, lastImage->valueBuffer, lastImage->size );
        ptr += lastImage->size;
        lastImage = lastImage->next;
    }
    variable_store_buffer( _environment, final->name, buffer, bufferSize, 0 );
    final->originalBitmap = atlasDescriptor->image->data;
    final->originalWidth = atlasDescriptor->image->width;
    final->originalHeight = atlasDescriptor->image->height;
    final->originalDepth = atlasDescriptor->image->depth;
    final->originalColors = atlasDescriptor->image->colorsCount;
    memcpy( final->originalPalette, atlasDescriptor->image->colors, MAX_PALETTE * sizeof( RGBi ) );
    final->frameWidth = _frame_width;
    final->frameHeight = _frame_height;
    final->frameSize = firstImage->size;
    final->frameCount = atlasDescriptor->count;

    lastImage = firstImage;
    for(int i=0; i<atlasDescriptor->count; ++i ) {
        variable_temporary_remove( _environment, lastImage->name );
        lastImage = lastImage->next;
    }

    // stbi_image_free(source);

    if ( _bank_expansion && _environment->expansionBanks ) {

        if ( ! banks_store( _environment, final, _bank_expansion ) ) {
            CRITICAL_EXPANSION_OUT_OF_MEMORY_LOADING( _filename );
        }

    } else if ( ( _flags & FLAG_COMPRESSED ) && !_environment->compressionForbidden ) {

        // Try to compress the result of image conversion.
        // This means that the buffer will be compressed using MSC1
        // algorithm, up to 32 frequent sequences. The original size of
        // the buffer will be considered as "uncompressed" size.
        MSC1Compressor * compressor = msc1_create( 32 );
        final->uncompressedSize = final->size;
        MemoryBlock * output = msc1_compress( compressor, final->valueBuffer, final->uncompressedSize, &final->size );

        int temporary;
        MemoryBlock * outputCheck = msc1_uncompress( compressor, output, final->size, &temporary );
        if ( memcmp( outputCheck, final->valueBuffer, final->uncompressedSize ) != 0 ) {
            CRITICAL("Compression failed");
        }
        msc1_free( compressor );

        // If the compressed memory is greater than the original
        // size, we discard the compression and we will continue as
        // usual.
        // If the compressed memory is greater than the original
        // size, we discard the compression and we will continue as
        // usual.
        if ( final->uncompressedSize < final->size ) {
            final->size = final->uncompressedSize;
            final->uncompressedSize = 0;
            free( output );
        } 
        // Otherwise, we can safely replace the original data
        // buffer with the compressed one.
        else {
            final->valueBuffer = output;
            if ( ! banks_store( _environment, final, 1 ) ) {
                CRITICAL_EXPANSION_OUT_OF_MEMORY_LOADING( _filename );
            };
            free( final->valueBuffer );
            final->valueBuffer = NULL;
        }

    }

    LoadedFile * loaded = malloc( sizeof( LoadedFile ) );
    loaded->next = first;
    loaded->variable = final;
    loaded->fileName = lookfor;
    _environment->loadedFiles = loaded;

    if ( _alias ) {
        const_define_numeric( _environment, _alias, UNIQUE_RESOURCE_ID );
    }

    final->readonly = 1;

    return final;

}
