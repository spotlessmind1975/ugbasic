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
#include "../../libs/stb_image.h"
#include "../../libs/msc1.h"
#include "../../libs/tsx.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>LOAD TILESERT(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 * @param _mode Mode to use to convert data
 */
/* <usermanual>
@keyword TILESET (storage)

@english
The ''TILESET'' command, inserted inside a ''BEGIN STORAGE'' - ''ENDSTORAGE'' block, 
allows you to define the content of the mass storage element as a tileset. The basic 
syntax requires indicating the name of the ''source'' file that will be converted
and inserted into the medium. If you don't want to use the same name, you can indicate 
an alias (''AS target'').

@italian
Il comando ''TILESET'', inserita all'interno di un blocco ''BEGIN STORAGE'' - 
''ENDSTORAGE'', permette di definire il contenuto dell'elemento di memorizzazione
di massa come "tileset". La sintassi di base prevede di indicare il nome del file 
sorgente che sarà convertito e inserito nel supporto. Se non si vuole utilizzare 
lo stesso nome, è possibile indicare un alias (''AS target'').

@syntax TILESET source [AS dest]

@example TILESET "tiles.tsx" AS "tiles"

@target all
</usermanual> */
Variable * tileset_storage( Environment * _environment, char * _source_name, char * _target_name, int _mode, int _flags, int _transparent_color, int _background_color, int _bank_expansion ) {

    file_storage( _environment, _source_name, _target_name );

    Variable * final = variable_temporary( _environment, VT_IMAGES, 0 );

    int width = 0;
    int height = 0;
    int depth = 0;

    char * lookedFilename = resource_load_asserts( _environment, _source_name );

    TsxTileset * tileset = tsx_load( lookedFilename );

    final->originalTileset = tileset;
    
    if ( !tileset ) {
        CRITICAL_TILESET_LOAD_UNKNOWN_FORMAT( _source_name );
    }

    if ( !tileset->image ) {
        CRITICAL_TILESET_LOAD_MISSING_IMAGE( _source_name );
    }

    Variable * result[MAX_TEMPORARY_STORAGE];
    int i,di,x=0,y=0,z=0;
    int bufferSize = 0;

    TsxImage * tsxImage = tileset->image;

    char * filename = strdup( _source_name );
    char * filenameWithPath = malloc( 1024 );
    memset( filenameWithPath, 0, 1024 );
    char * separator = strrchr( filename, '/' );
    if ( separator ) {
        *(separator+1) = 0;
        strcpy( filenameWithPath, filename );
    }
    strcat( filenameWithPath, tsxImage->source );

    AtlasDescriptor * atlasDescriptor = atlas_descriptor_create( _environment, filenameWithPath, _flags, tileset->margin, tileset->margin, tileset->tilewidth, tileset->tileheight, tileset->spacing, tileset->spacing );

    ImageDescriptor * frame = atlasDescriptor->frames;
    for( int i=0; i<atlasDescriptor->count; ++i ) {
        result[i] = image_converter( _environment, frame->data, frame->width, frame->height, frame->depth, 0, 0, tileset->tilewidth, tileset->tileheight, _mode, _transparent_color, _flags );
        bufferSize += result[i]->size;
        frame = frame->next;
    }

    bufferSize += 3;

    char * buffer = malloc( bufferSize );
    char * ptr = buffer;
    ptr[0] = atlasDescriptor->count;
    ptr[1] = ( tileset->tilewidth & 0xff );
    ptr[2] = ( tileset->tilewidth >> 8 ) & 0xff;

    if ( ( result[0]->size * atlasDescriptor->count ) > 0xffff ) {
        CRITICAL_TILESET_LOAD_IMAGE_TOO_BIG( _source_name );
    }

    final->offsettingFrames = offsetting_size_count( _environment, result[0]->size, atlasDescriptor->count );
    offsetting_add_variable_reference( _environment, final->offsettingFrames, final, 0 );

    ptr += 3;
    for(int i=0; i<atlasDescriptor->count; ++i ) {
        memcpy( ptr, result[i]->valueBuffer, result[i]->size );
        ptr += result[i]->size;
    }
    variable_store_buffer( _environment, final->name, buffer, bufferSize, 0 );
    final->originalBitmap = atlasDescriptor->image->data;
    final->originalWidth = atlasDescriptor->image->width;
    final->originalHeight = atlasDescriptor->image->height;
    final->originalDepth = atlasDescriptor->image->depth;
    final->originalColors = atlasDescriptor->image->colorsCount;
    memcpy( final->originalPalette, atlasDescriptor->image->colors, MAX_PALETTE * sizeof( RGBi ) );
    final->frameWidth = tileset->tilewidth;
    final->frameHeight = tileset->tileheight;
    final->firstGid = tileset->firstgid;
    final->frameSize = result[0]->size;
    final->frameCount = atlasDescriptor->count;

    for(int i=0; i<atlasDescriptor->count; ++i ) {
        variable_temporary_remove( _environment, result[i]->name );
    }

    // stbi_image_free(source);

    if ( ( _flags & FLAG_COMPRESSED ) && !_environment->compressionForbidden ) {

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
            CRITICAL_COMPRESSION_FAILED(_source_name);
        }
        msc1_free( compressor );
        // printf( "%s: %d bytes -> %d bytes\n", _filename, final->uncompressedSize, final->size );
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
            free( final->valueBuffer );
            final->valueBuffer = output;
        }
        final->residentAssigned = 1;
        _environment->maxExpansionBankSize[1] = BANK_SIZE;

    }

    _environment->currentFileStorage->size = final->size;
    _environment->currentFileStorage->content = final->valueBuffer;

    return final;

}
