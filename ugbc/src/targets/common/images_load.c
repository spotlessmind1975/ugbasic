/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
Il comando ''LOAD IMAGES'' permette di caricare un'immagine e di convertirla
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

@syntax = LOAD IMAGES([filename]) FRAME SIZE ([w],[h])
@syntax = LOAD IMAGES([filename] AS [alias]) FRAME SIZE ([w],[h])

@example starship = LOAD IMAGES("starship.png") FRAME SIZE (8,8)
@example alienAt11 = LOAD IMAGES("alien.png") FRAME SIZE (16,16)
@example alien2 = LOAD IMAGES("alien.png" AS "alien2") FRAME SIZE (16,16)

@usedInExample images_loading_01.bas

@target all
</usermanual> */
Variable * images_load( Environment * _environment, char * _filename, char * _alias, int _mode, int _frame_width, int _frame_height, int _flags, int _transparent_color, int _background_color, int _bank_expansion ) {

    Variable * final = variable_temporary( _environment, VT_IMAGES, 0 );

    if ( _environment->emptyProcedure ) {
        return final;
    }

    if ( _environment->tenLinerRulesEnforced ) {
        CRITICAL_10_LINE_RULES_ENFORCED( "LOAD IMAGES");
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

    FILE * lookedFileHandle = fopen( lookedFilename, "rb" );
    fseek( lookedFileHandle, 0, SEEK_END );
    long fileSize = ftell( lookedFileHandle );
    fclose( lookedFileHandle );

    int frames = 0;
    unsigned char * originalSource, * source;
    int layout_mode = 0;

    if ( stbi_is_animated_gif( lookedFilename ) ) {
        source = stbi_xload(lookedFilename, &width, &height, &frames);
        depth = 4;
        layout_mode = 1;
    } else {
        if ( _frame_height < 0 || _frame_width < 0 ) {
            CRITICAL_IMAGES_LOAD_INVALID_AUTO_WITHOUT_GIF( _filename );            
        }
        source = stbi_load(lookedFilename, &width, &height, &depth, 0);
        frames = 0;
        layout_mode = 0;
    }

    originalSource = source;

    if ( _frame_width < 0 ) {
        _frame_width = width;
    }

    if ( _frame_height < 0 ) {
        _frame_height = height;
    }

    if ( !source ) {
        CRITICAL_IMAGE_LOAD_UNKNOWN_FORMAT( _filename );
    }

    if ( width % _frame_width ) {
        CRITICAL_IMAGES_LOAD_INVALID_FRAME_WIDTH( _frame_width );
    }

    if ( height % _frame_height ) {
        CRITICAL_IMAGES_LOAD_INVALID_FRAME_HEIGHT( _frame_height );
    }

    adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_STANDARD );

    int bufferSize = 0;
    int realFramesCount;
    int i;
    Variable * result[MAX_TEMPORARY_STORAGE];

    if ( layout_mode == 0 ) {

        int wc = ( width / _frame_width );
        int hc = ( height / _frame_height );
        int a = 1;
        frames = wc*hc;

        int i,di,x=0,y=0,z=0;

        if( _flags & FLAG_ROLL_X ) {
            a = (_frame_width - 1);
        }

        realFramesCount = (a*hc*wc);
        i = 0;
        di = 1;

        adiline5("LIS:%s:%s:%2.2x:%2.2x:%lx", _filename, lookedFilename, realFramesCount, wc, fileSize );

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
            for( y=0; y<height; y+=_frame_height ) {
                for( x=0; x<width; x+=_frame_width ) {
                    result[i] = image_converter( _environment, source, width, height, depth, x, y, _frame_width, _frame_height, _mode, _transparent_color, _flags );
                    bufferSize += result[i]->size;
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
        
        adiline5("LIS:%s:%s:%2.2x:%2.2x:%lx", _filename, lookedFilename, realFramesCount, realFramesCount, fileSize );

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
                    result[i] = image_converter( _environment, source, width, height, depth, 0, 0, _frame_width, _frame_height, _mode, _transparent_color, _flags );
                    bufferSize += result[i]->size;
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

    adiline1("LIS2:%x", bufferSize );

    char * buffer = malloc( bufferSize );
    char * ptr = buffer;
    ptr[0] = frames;
    ptr[1] = ( _frame_width & 0xff );
    ptr[2] = ( _frame_width >> 8 ) & 0xff;

    if ( ( result[0]->size * realFramesCount ) > 0xffff ) {
        CRITICAL_IMAGES_LOAD_IMAGE_TOO_BIG( _filename );
    }

    offsetting_size_count( _environment, result[0]->size, realFramesCount );

    ptr += 3;
    for(i=0; i<realFramesCount; ++i ) {
        memcpy( ptr, result[i]->valueBuffer, result[i]->size );
        ptr += result[i]->size;
    }
    variable_store_buffer( _environment, final->name, buffer, bufferSize, 0 );
    final->originalBitmap = originalSource;
    final->originalWidth = width;
    final->originalHeight = height;
    final->originalDepth = depth;
    final->originalColors = palette_extract( _environment, final->originalBitmap, final->originalWidth, final->originalHeight, final->originalDepth, _flags, final->originalPalette );
    final->frameWidth = _frame_width;
    final->frameHeight = _frame_height;
    final->frameSize = result[0]->size;
    final->frameCount = realFramesCount;

    for(i=0; i<realFramesCount; ++i ) {
        variable_temporary_remove( _environment, result[i]->name );
    }

    // stbi_image_free(source);

    if ( _bank_expansion && _environment->expansionBanks ) {

        // // Try to compress the result of image conversion.
        // // This means that the buffer will be compressed using MSC1
        // // algorithm, up to 32 frequent sequences. The original size of
        // // the buffer will be considered as "uncompressed" size.
        // MSC1Compressor * compressor = msc1_create( 32 );
        // final->uncompressedSize = final->size;
        // MemoryBlock * output = msc1_compress( compressor, final->valueBuffer, final->uncompressedSize, &final->size );

        // int temporary;
        // MemoryBlock * outputCheck = msc1_uncompress( compressor, output, final->size, &temporary );
        // if ( memcmp( outputCheck, final->valueBuffer, final->uncompressedSize ) != 0 ) {
        //     CRITICAL("Compression failed");
        // }
        // msc1_free( compressor );
        // // printf( "%s: %d bytes -> %d bytes\n", _filename, final->uncompressedSize, final->size );
        // // If the compressed memory is greater than the original
        // // size, we discard the compression and we will continue as
        // // usual.
        // if ( final->uncompressedSize < final->size ) {
        //     final->size = final->uncompressedSize;
        //     final->uncompressedSize = 0;
        //     free( output );
        // } 
        // // Otherwise, we can safely replace the original data
        // // buffer with the compressed one.
        // else {
        //     free( final->valueBuffer );
        //     final->valueBuffer = output;
        // }

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

    } else if ( _flags & FLAG_COMPRESSED ) {

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
