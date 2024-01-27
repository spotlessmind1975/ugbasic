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
#include "../../libs/msc1.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>IMAGE ... AS ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the storage
 */
/* <usermanual>
@keyword SEQUENCE (storage)

@english
The ''SEQUENCE'' command, inserted inside a ''BEGIN STORAGE'' - ''ENDSTORAGE'' block, 
allows you to define the content of the mass storage element as a sequence of images. The basic 
syntax requires indicating the name of the ''source'' file that will be converted
and inserted into the medium. If you don't want to use the same name, you can indicate 
an alias (''AS target'').

@italian
Il comando ''SEQUENCE'', inserita all'interno di un blocco ''BEGIN STORAGE'' - 
''ENDSTORAGE'', permette di definire il contenuto dell'elemento di memorizzazione
di massa come una sequenza di immagini. La sintassi di base prevede di indicare il nome del file 
sorgente che sarà convertito e inserito nel supporto. Se non si vuole utilizzare 
lo stesso nome, è possibile indicare un alias (''AS target'').

@syntax SEQUENCE source [AS target] FRAME SIZE (widh, height)

@example SEQUENCE "examples/data.png" FRAME SIZE (32, 32)
@example SEQUENCE "sprites.bmp" AS "sprites.dat" FRAME SIZE (32, 32)

@usedInExample storage_example_03.bas

@target all
@verified
</usermanual> */
Variable * sequence_storage( Environment * _environment, char * _source_name, char * _target_name, int _mode, int _frame_width, int _frame_height, int _flags, int _transparent_color, int _background_color, int _bank_expansion ) {

    file_storage( _environment, _source_name, _target_name );

    Variable * final = variable_temporary( _environment, VT_SEQUENCE, 0 );

    int width = 0;
    int height = 0;
    int depth = 0;

    char * lookedFilename = resource_load_asserts( _environment, _source_name );

    FILE * lookedFileHandle = fopen( lookedFilename, "rb" );
    fseek( lookedFileHandle, 0, SEEK_END );
    long fileSize = ftell( lookedFileHandle );
    fclose( lookedFileHandle );

    unsigned char* source = stbi_load(lookedFilename, &width, &height, &depth, 0);

    if ( !source ) {
        CRITICAL_IMAGE_LOAD_UNKNOWN_FORMAT( _source_name );
    }

    if ( width % _frame_width ) {
        CRITICAL_SEQUENCE_LOAD_INVALID_FRAME_WIDTH( _frame_width );
    }

    if ( height % _frame_height ) {
        CRITICAL_SEQUENCE_LOAD_INVALID_FRAME_HEIGHT( _frame_height );
    }

    int wc = ( width / _frame_width );
    int hc = ( height / _frame_height );

    Variable * result[MAX_TEMPORARY_STORAGE];
    int i,di,x=0,y=0,z=0;
    int bufferSize = 0;

    int realFramesCount = (hc*wc);
    i = 0;
    di = 1;

    if( _flags & FLAG_FLIP_X ) {
        source = image_flip_x( _environment, source, width, height, depth );
    }
    if( _flags & FLAG_FLIP_Y ) {
        source = image_flip_y( _environment, source, width, height, depth );
    }

    if ( _transparent_color != -1 ) {
        _flags |= FLAG_TRANSPARENCY;
    }

    int base = ( 3*width*height ) - 6;
    for( y=0; y<height; y+=_frame_height ) {
        for( x=0; x<width; x+=_frame_width ) {
            result[i] = image_converter( _environment, source, width, height, depth, x, y, _frame_width, _frame_height, _mode, _transparent_color, _flags );
            bufferSize += result[i]->size;
            i += di;
        }
    }

    bufferSize += 3;

    char * buffer = malloc( bufferSize );
    char * ptr = buffer;
    ptr[0] = wc*1;
    ptr[1] = _frame_width;
    ptr[2] = hc;

    if ( ( result[0]->size * wc ) > 0xffff ) {
        CRITICAL_SEQUENCE_LOAD_IMAGE_TOO_BIG( _source_name );
    }

    final->offsettingFrames = offsetting_size_count( _environment, result[0]->size, wc );
    offsetting_add_variable_reference( _environment, final->offsettingFrames, final, 0 );

    if ( ( wc*result[0]->size ) > 0xffff ) {
        CRITICAL_SEQUENCE_LOAD_IMAGE_TOO_BIG( _source_name );
    }

    final->offsettingSequences = offsetting_size_count( _environment, wc*result[0]->size, hc );
    offsetting_add_variable_reference( _environment, final->offsettingSequences, final, 1 );

    ptr += 3;
    for(int i=0;i<hc;++i) {
        for(i=0; i<realFramesCount; ++i ) {
            memcpy( ptr, result[i]->valueBuffer, result[i]->size );
            ptr += result[i]->size;
        }
    }
    variable_store_buffer( _environment, final->name, buffer, bufferSize, 0 );
    final->originalBitmap = source;
    final->originalWidth = width;
    final->originalHeight = height;
    final->originalDepth = depth;
    final->originalColors = palette_extract( _environment, final->originalBitmap, final->originalWidth, final->originalHeight, final->originalDepth, _flags, final->originalPalette );
    final->frameSize = result[0]->size;
    final->frameCount = wc;

    for(i=0; i<realFramesCount; ++i ) {
        variable_temporary_remove( _environment, result[i]->name );
    }

    // stbi_image_free(source);

    if ( _flags & FLAG_COMPRESSED ) {

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
