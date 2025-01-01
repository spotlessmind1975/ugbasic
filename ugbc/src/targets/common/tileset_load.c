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
@keyword LOAD TILESET

@english

The ''LOAD TILESET'' command allows you to load a tileset with the "Tiled TSX"
file format. Offset and other parameters will be calculated automatically
on the base of the file content.

The image will be converted into a way that can be efficiently drawn
on the screen. It could be converted into indexed palette, and can be
rescaled as well.

Since it is possible to load only one file of the same type at a time, it is necessary 
to be able to indicate an "alias" with which to exceed this limit. In this regard, there is also
the ''AS'' syntax, which allows you to load the same file several times but with different names.

@italian
Il comando ''LOAD TILESET'' permette di caricare un tileset con il formato file "Tiled TSX". 
L'offset e altri parametri verranno calcolati automaticamente sulla base del contenuto del file.

L'immagine verrà convertita in un modo che possa essere disegnata in modo efficiente
sullo schermo. Potrebbe essere convertita in una tavolozza indicizzata, e potrebbe essere
anche ridimensionata.

Dal momento in cui è possibile caricare un solo file dello stesso tipo alla volta, 
è necessario poter indicare un "alias" con cui superare questo limite. A tal riguardo 
esiste anche la sintassi ''AS'', che permette di caricare più volte lo stesso file 
ma con nomi diversi.

@syntax = LOAD TILESET( filename )
@syntax = LOAD TILESET( filename AS alias )

@example x = LOAD TILESET("dungeon.tsx")
@example x = LOAD TILESET("dungeon.tsx" AS "dungeon")

@target all
</usermanual> */
Variable * tileset_load( Environment * _environment, char * _filename, char * _alias, int _mode, int _flags, int _transparent_color, int _background_color, int _bank_expansion ) {

    Variable * final = variable_temporary( _environment, VT_IMAGES, 0 );

    if ( _environment->emptyProcedure ) {
        return final;
    }

    if ( _environment->tenLinerRulesEnforced ) {
        CRITICAL_10_LINE_RULES_ENFORCED( "LOAD TILESET");
    }

    if ( _environment->sandbox ) {
        CRITICAL_SANDBOX_ENFORCED( "LOAD TILESET");
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

    int width = 0;
    int height = 0;
    int depth = 0;

    char * lookedFilename = resource_load_asserts( _environment, _filename );

    TsxTileset * tileset = tsx_load( lookedFilename );

    final->originalTileset = tileset;
    
    if ( !tileset ) {
        CRITICAL_TILESET_LOAD_UNKNOWN_FORMAT( _filename );
    }

    if ( !tileset->image ) {
        CRITICAL_TILESET_LOAD_MISSING_IMAGE( _filename );
    }

    Variable * result[MAX_TEMPORARY_STORAGE];
    int x=0,y=0,z=0;
    int bufferSize = 0;

    TsxImage * tsxImage = tileset->image;

    char * filename = strdup( _filename );
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

    adiline1("LIS2:%x", bufferSize );

    char * buffer = malloc( bufferSize );
    char * ptr = buffer;
    ptr[0] = atlasDescriptor->count;
    ptr[1] = ( tileset->tilewidth & 0xff );
    ptr[2] = ( tileset->tilewidth >> 8 ) & 0xff;

    if ( ( result[0]->size * atlasDescriptor->count ) > 0xffff ) {
        CRITICAL_TILESET_LOAD_IMAGE_TOO_BIG( _filename );
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

    if ( _bank_expansion && _environment->expansionBanks ) {

        Bank * bank = _environment->expansionBanks;

        while( bank ) {
            if ( bank->remains > final->size ) {
                break;
            }
            bank = bank->next;
        } 

        if ( ! bank ) {
            CRITICAL_EXPANSION_OUT_OF_MEMORY_LOADING( _filename );
        }

        final->bankAssigned = bank->id;
        final->absoluteAddress = bank->address;
        final->residentAssigned = _bank_expansion;
        final->variableUniqueId = UNIQUE_RESOURCE_ID;
        memcpy( &bank->data[bank->address], final->valueBuffer, final->size );

        bank->address += final->size;
        bank->remains -= final->size;

        // Now we must calculate the effective size occupied by
        // memory block, when it will be uncompressed. It is needed
        // to have enough memory into the resident part of the
        // memory. If uncompressed size is zero, it means that
        // the memory block is not compressed -- so we can use the
        // size as well.
        // int realSize = final->uncompressedSize;
        // if ( realSize == 0 ) realSize = final->size;

        if ( _environment->maxExpansionBankSize[_bank_expansion] < final->frameSize ) {
            _environment->maxExpansionBankSize[_bank_expansion] = final->frameSize;
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
            CRITICAL_COMPRESSION_FAILED(_filename);
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
