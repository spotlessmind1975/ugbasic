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
@keyword IMAGES (storage)

@english
The ''IMAGES'' command, inserted inside a ''BEGIN STORAGE'' - ''ENDSTORAGE'' block, 
allows you to define the content of the mass storage element as an set of images. The basic 
syntax requires indicating the name of the ''source'' file that will be converted
and inserted into the medium. If you don't want to use the same name, you can indicate 
an alias (''AS target'').

@italian
Il comando ''IMAGES'', inserita all'interno di un blocco ''BEGIN STORAGE'' - 
''ENDSTORAGE'', permette di definire il contenuto dell'elemento di memorizzazione
di massa come una serie di immagini. La sintassi di base prevede di indicare il nome del file 
sorgente che sarà convertito e inserito nel supporto. Se non si vuole utilizzare 
lo stesso nome, è possibile indicare un alias (''AS target'').

@syntax IMAGES source [AS target] FRAME SIZE(width, height)

@example IMAGES "examples/data.png" FRAME SIZE(16, 16)
@example IMAGES "sprites.bmp" AS "sprites.dat" FRAME SIZE(16, 16)

@usedInExample storage_example_03.bas

@target all
@verified
</usermanual> */
Variable * images_storage( Environment * _environment, char * _source_name, char * _target_name, int _mode, int _frame_width, int _frame_height, int _flags, int _transparent_color, int _background_color, int _bank_expansion, int _origin_x, int _origin_y, int _offset_x, int _offset_y ) {

    file_storage( _environment, _source_name, _target_name );

    Variable * final = variable_temporary( _environment, VT_IMAGES, 0 );

    int width = 0;
    int height = 0;
    int depth = 0;

    char * lookedFilename = resource_load_asserts( _environment, _source_name );

    long fileSize = file_get_size( _environment, lookedFilename );

    int frames = 0;
    unsigned char * originalSource, * source;
    int layout_mode = 0;

    if ( stbi_is_animated_gif( lookedFilename ) ) {
        if ( _origin_x || _origin_y ) {
            CRITICAL_IMAGES_LOAD_INVALID_ORIGIN_WITH_GIF( _source_name );            
        }
        if ( _offset_x || _offset_y ) {
            CRITICAL_IMAGES_LOAD_INVALID_OFFSET_WITH_GIF( _source_name );            
        }        
        source = stbi_xload(lookedFilename, &width, &height, &frames);
        depth = 4;
        layout_mode = 1;
    } else {
        if ( _frame_height < 0 || _frame_width < 0 ) {
            CRITICAL_IMAGES_LOAD_INVALID_AUTO_WITHOUT_GIF( _source_name );            
        }
        source = stbi_load(lookedFilename, &width, &height, &depth, 0);
        frames = 0;
        layout_mode = 0;
    }

    source += ( ( _origin_y * width ) + _origin_x ) * depth;
    width -= _origin_x;
    height -= _origin_y;

    originalSource = source;

    if ( _frame_width < 0 ) {
        _frame_width = width;
    }

    if ( _frame_height < 0 ) {
        _frame_height = height;
    }

    if ( !source ) {
        CRITICAL_IMAGE_LOAD_UNKNOWN_FORMAT( _source_name );
    }

    if ( width % _frame_width ) {
        CRITICAL_IMAGES_LOAD_INVALID_FRAME_WIDTH( _frame_width );
    }

    if ( height % _frame_height ) {
        CRITICAL_IMAGES_LOAD_INVALID_FRAME_HEIGHT( _frame_height );
    }

    int bufferSize = 0;
    int realFramesCount;
    int i;
    Variable * firstImage = NULL;
    Variable * lastImage = NULL;

    if ( layout_mode == 0 ) {

        int wc = ( width / (_frame_width+_offset_x) );
        int hc = ( height / (_frame_height+_offset_y) );
        int a = 1;
        frames = wc*hc;

        int i,di,x=0,y=0,z=0;

        if( _flags & FLAG_ROLL_X ) {
            a = ((_frame_width+_offset_x) - 1);
        }

        realFramesCount = (a*hc*wc);
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

        for( z=0; z<a; ++z ) {
            for( y=0; y<height; y+=(_frame_height+_offset_y) ) {
                for( x=0; x<width; x+=(_frame_width+_offset_x) ) {
                    Variable * partial = image_converter( _environment, source, width, height, depth, x, y, _frame_width, _frame_height, _mode, _transparent_color, _flags );
                    if ( ! firstImage && ! lastImage ) {
                        firstImage = partial;
                        lastImage = firstImage;
                    } else {
                        lastImage->next = partial;
                        lastImage = lastImage->next;
                    }
                    bufferSize += partial->size;
                    i += di;
                }
            }
            if( _flags & FLAG_ROLL_X ) {
                if ( _flags & FLAG_FLIP_X ) {
                    source = image_roll_x_left( _environment, source, width, height );
                } else {
                    source = image_roll_x_right( _environment, source, width, height );
                }
            }
        }

    } else {

        int z;

        // if( _flags & FLAG_ROLL_X ) {
        //     a = (_frame_width - 1);
        // }

        realFramesCount = frames;
        i = 0;
        
        // if( _flags & FLAG_FLIP_X ) {
        //     source = image_flip_x( _environment, source, width, height, depth );
        // }
        // if( _flags & FLAG_FLIP_Y ) {
        //     source = image_flip_y( _environment, source, width, height, depth );
        // }

        if ( _transparent_color != -1 ) {
            _flags |= FLAG_TRANSPARENCY;
        }

        for( z=0; z<frames; ++z ) {
            // for( y=0; y<height; y+=_frame_height ) {
            //     for( x=0; x<width; x+=_frame_width ) {
                    Variable * partial = image_converter( _environment, source, width, height, depth, 0, 0, _frame_width, _frame_height, _mode, _transparent_color, _flags );
                    if ( ! firstImage && ! lastImage ) {
                        firstImage = partial;
                        lastImage = firstImage;
                    } else {
                        lastImage->next = partial;
                        lastImage = lastImage->next;
                    }
                    bufferSize += partial->size;
                    ++i;
                    source += (width*height*depth)+2;
            //     }
            // }
            // if( _flags & FLAG_ROLL_X ) {
            //     if ( _flags & FLAG_FLIP_X ) {
            //         source = image_roll_x_left( _environment, source, width, height );
            //     } else {
            //         source = image_roll_x_right( _environment, source, width, height );
            //     }
            // }
        }

        // Number of frames is returned through frames parameter.
        // The delay for each frame is a 2 bytes little endian unsigned integer.
        // All frames are given in RGBA format.
        // All frames have the same width and height returned through x, y parameters.
        // A single image buffer (with no delay info) is returned for non-gif files and for gifs that have 1 frame.
        // The loading skips an y-flip check stb_image does.

    }

    bufferSize += 3;

    char * buffer = malloc( bufferSize );
    char * ptr = buffer;
    ptr[0] = frames;
    ptr[1] = ( _frame_width & 0xff );
    ptr[2] = ( _frame_width >> 8 ) & 0xff;

    if ( ( firstImage->size * realFramesCount ) > 0xffff ) {
        CRITICAL_IMAGES_LOAD_IMAGE_TOO_BIG( _source_name );
    }

    final->offsettingFrames = offsetting_size_count( _environment, firstImage->size, realFramesCount );
    offsetting_add_variable_reference( _environment, final->offsettingFrames, final, 0 );

    ptr += 3;
    lastImage = firstImage;
    for(i=0; i<realFramesCount; ++i ) {
        memcpy( ptr, lastImage->valueBuffer, lastImage->size );
        ptr += lastImage->size;
        lastImage = lastImage->next;
    }
    variable_store_buffer( _environment, final->name, buffer, bufferSize, 0 );

    lastImage = firstImage;
    for(i=0; i<realFramesCount; ++i ) {
        variable_temporary_remove( _environment, lastImage->name );
        lastImage = lastImage->next;
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

    lastImage = firstImage;
    for(i=0; i<realFramesCount; ++i ) {
        variable_temporary_remove( _environment, lastImage->name );
        lastImage = lastImage->next;
    }

    _environment->currentFileStorage->size = final->size;
    _environment->currentFileStorage->content = final->valueBuffer;

    return final;
    
}
