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
 * @brief Emit code for <strong>LOAD IMAGE(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 * @param _mode Mode to use to convert data
 */
/* <usermanual>
@keyword LOAD IMAGE

@english
The ''LOAD IMAGE'' command allows you to load an image and to convert it into 
an ''IMAGE''. The second parameter is the mode to use to convert 
the given data (by default, it is equal to current mode) 

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
Il comando ''LOAD IMAGE'' permette di caricare un file immagine, e di convertirlo
in una ''IMAGE''. Il secondo parametro è la modalità grafica da usare
per convertire il dato (per default, è il modo corrente).

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

@syntax = LOAD IMAGE( filename[,mode] )
@syntax = LOAD IMAGE( filename AS alias[,mode] )

@example starship = LOAD IMAGE("starship.png")
@example starship2 = LOAD IMAGE("starship.png" AS "starship2")
@example alienAt11 = LOAD IMAGE("alien.jpg",11)
@example alien2 = LOAD IMAGE("alien.jpg" AS "alien2",11)

@usedInExample image_loading_01.bas

@target all
</usermanual> */
Variable * image_load( Environment * _environment, char * _filename, char * _alias, int _mode, int _flags, int _transparent_color, int _background_color, int _bank_expansion ) {

    // First of all, we create a variable to store the image.
    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );

    // If the LOAD IMAGE is inside an ignored procedure,
    // we must avoid to do anything.
    if ( _environment->emptyProcedure ) {
        return result;
    }

    // LOAD IMAGE cannot be used on 10 liner competition.
    if ( _environment->tenLinerRulesEnforced ) {
        CRITICAL_10_LINE_RULES_ENFORCED( "LOAD IMAGE");
    }

    // LOAD IMAGE cannot be used inside sandbox.
    if ( _environment->sandbox ) {
        CRITICAL_SANDBOX_ENFORCED( "LOAD IMAGE");
    }

    // If the image loaded has been already loaded previously,
    // we must avoid to go ahead and return the very same
    // variable. Note that this works also if the image
    // has to be loaded from a mass storage.
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

    // No we are going to load the image from the PC.
    // Those variables will maintain the data of the original image.
    int width = 0;
    int height = 0;
    int depth = 0;

    // We must load the target dependent version of the images.
    char * lookedFilename = resource_load_asserts( _environment, _filename );

    // If present, we can calculate the effective size.
    FILE * lookedFileHandle = fopen( lookedFilename, "rb" );
    fseek( lookedFileHandle, 0, SEEK_END );
    long fileSize = ftell( lookedFileHandle );
    fclose( lookedFileHandle );

    // Now we can decode the image using the external library.
    unsigned char* source = stbi_load(lookedFilename, &width, &height, &depth, 0);

    // If we are unable to decode the iamge, we stop the compilation.
    if ( !source ) {
        CRITICAL_IMAGE_LOAD_UNKNOWN_FORMAT( _filename );
    }

    // If the image has to be post processed, we do it:
    //  - X FLIP
    if( _flags & FLAG_FLIP_X ) {
        source = image_flip_x( _environment, source, width, height, depth );
    }
    //  - Y FLIP
    if( _flags & FLAG_FLIP_Y ) {
        source = image_flip_y( _environment, source, width, height, depth );
    }

    // This is a workaround. In a previous release of ugBASIC, we must give
    // the color index to be used as transparency. If given, we active the
    // "FLAG TRANSPARENCY" during the conversion.
    if ( _transparent_color != -1 ) {
        _flags |= FLAG_TRANSPARENCY;
    }

    // ADI INFO
    adiline4("LI:%s:%s:%lx:%x", _filename, lookedFilename, fileSize, result->size );

    // Now we are able to convert the image from the original format to the
    // custom format of the target. This is a time efficient mode to store
    // the image, but not a space efficient (no compression is done).
    // Space efficiency can be applied after, if a bank is present.
    result = image_converter( _environment, source, width, height, depth, 0, 0, 0, 0, _mode, _transparent_color, _flags );

    // ADI INFO
    adiline1("LI2:%x", result->size );

    // We can now store the data of the image directly into the variable.
    result->originalBitmap = source;
    result->originalWidth = width;
    result->originalHeight = height;
    result->originalDepth = depth;

    // If a bank expasion has been requested, and there is at least one bank...
    if ( _bank_expansion && _environment->expansionBanks ) {

        if ( !_environment->compressionForbidden ) {

            // Try to compress the result of image conversion.
            // This means that the buffer will be compressed using MSC1
            // algorithm, up to 32 frequent sequences. The original size of
            // the buffer will be considered as "uncompressed" size.
            MSC1Compressor * compressor = msc1_create( 32 );
            result->uncompressedSize = result->size;
            MemoryBlock * output = msc1_compress( compressor, result->valueBuffer, result->uncompressedSize, &result->size );

            int temporary;
            MemoryBlock * outputCheck = msc1_uncompress( compressor, output, result->size, &temporary );

            if ( memcmp( outputCheck, result->valueBuffer, result->uncompressedSize ) != 0 ) {
                CRITICAL("Compression failed");
            }
            msc1_free( compressor );

            // If the compressed memory is greater than the original
            // size, we discard the compression and we will continue as
            // usual.
            if ( result->uncompressedSize < result->size ) {
                result->size = result->uncompressedSize;
                result->uncompressedSize = 0;
                free( output );
            } 
            // Otherwise, we can safely replace the original data
            // buffer with the compressed one.
            else {
                free( result->valueBuffer );
                result->valueBuffer = output;
            }

        }

        if ( ! banks_store( _environment, result, _bank_expansion ) ) {
            CRITICAL_EXPANSION_OUT_OF_MEMORY_LOADING( _filename );
        }

    // We can compress also if COMPRESSED flag is used.
    } else if ( _flags & FLAG_COMPRESSED && !_environment->compressionForbidden ) {

        // Try to compress the result of image conversion.
        // This means that the buffer will be compressed using MSC1
        // algorithm, up to 32 frequent sequences. The original size of
        // the buffer will be considered as "uncompressed" size.
        MSC1Compressor * compressor = msc1_create( 32 );
        result->uncompressedSize = result->size;
        MemoryBlock * output = msc1_compress( compressor, result->valueBuffer, result->uncompressedSize, &result->size );

        int temporary;
        MemoryBlock * outputCheck = msc1_uncompress( compressor, output, result->size, &temporary );
        if ( memcmp( outputCheck, result->valueBuffer, result->uncompressedSize ) != 0 ) {
            CRITICAL("Compression failed");
        }
        msc1_free( compressor );

        // If the compressed memory is greater than the original
        // size, we discard the compression and we will continue as
        // usual.
        // If the compressed memory is greater than the original
        // size, we discard the compression and we will continue as
        // usual.
        if ( result->uncompressedSize < result->size ) {
            result->size = result->uncompressedSize;
            result->uncompressedSize = 0;
            free( output );
        } 
        // Otherwise, we can safely replace the original data
        // buffer with the compressed one.
        else {
            result->valueBuffer = output;
            if ( ! banks_store( _environment, result, 1 ) ) {
                CRITICAL_EXPANSION_OUT_OF_MEMORY_LOADING( result->name );
            };
            free( result->valueBuffer );
            result->valueBuffer = NULL;
        }
        
    }

    // Loaded images are ALWAYS readonly!
    result->readonly = 1;

    // If the original file has been stored into a storage,
    // then we have to change something. Infact, the image
    // has not to be deployed directly in the executable
    // but only the space needed to storage the image.
    // Moreover, we must avoid to create multiple spaces:
    // it will be enough to store the maximum size of every
    // single image.

    // Storage * storage = _environment->storage;
    // FileStorage * fileStorage = NULL;

    // while( storage ) {

    //     fileStorage = storage->files;

    //     while( fileStorage ) {

    //         if ( strcmp( fileStorage->sourceName, _filename ) == 0 ) {
    //             break;
    //         }

    //         fileStorage = fileStorage->next;

    //     }

    //     if ( fileStorage ) {
    //         break;
    //     }

    //     storage = storage->next;

    // }

    // // If the file is stored into any storage memory...
    // if ( fileStorage ) {

    //     if ( ! _environment->storageTransientMemoryArea ) {
    //         _environment->storageTransientMemoryArea = variable_temporary( _environment, VT_BUFFER, "(temporary)" );
    //         variable_resize_buffer( _environment, _environment->storageTransientMemoryArea->name, result->size );
    //     }

    //     // If the variable has not been already allocated...
    //     if ( ! fileStorage->variable ) {

    //         // Allocate the variable
    //         fileStorage->variable = _environment->storageTransientMemoryArea;
    //         // The image is on the storage, really.
    //         result->onStorage = 1;
    //         // The memory should not be read only.
    //         result->readonly = 0;
    //     } else {
    //         if ( fileStorage->variable->size < result->size ) {
    //             variable_resize_buffer( _environment, _environment->storageTransientMemoryArea->name, result->size );
    //         }
    //     }

    //     fileStorage->content = result->valueBuffer;
    //     fileStorage->size = result->size;

    //     Variable * filename = variable_temporary( _environment, VT_STRING, "(filename)");
    //     variable_store_string( _environment, filename->name, fileStorage->targetName );

    //     // Retrieve the (runtime) address and size of the allocated space.
    //     Variable * address = variable_temporary( _environment, VT_ADDRESS, "(word) ");
    //     Variable * size = variable_temporary( _environment, VT_WORD, "(word) ");

    //     cpu_addressof_16bit( _environment, _environment->storageTransientMemoryArea->realName, address->realName  );
    //     cpu_store_16bit( _environment, size->realName, fileStorage->size );

    //     // Load the resource from the storage.
    //     dload( _environment, filename->name, NULL, address->name, size->name );

    // }

    // stbi_image_free(source);

    // Finally, we store the image as already loaded, in order
    // to avoid to load again and again and again...
    LoadedFile * loaded = malloc( sizeof( LoadedFile ) );
    loaded->next = first;
    loaded->variable = result;
    loaded->fileName = lookfor;
    _environment->loadedFiles = loaded;

    if ( _alias ) {
        const_define_numeric( _environment, _alias, UNIQUE_RESOURCE_ID );
    }

    return result;

}
