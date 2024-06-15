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
@keyword IMAGE (storage)

@english
The ''IMAGE'' command, inserted inside a ''BEGIN STORAGE'' - ''ENDSTORAGE'' block, 
allows you to define the content of the mass storage element as an image. The basic 
syntax requires indicating the name of the ''source'' file that will be converted
and inserted into the medium. If you don't want to use the same name, you can indicate 
an alias (''AS target'').

@italian
Il comando ''IMAGE'', inserita all'interno di un blocco ''BEGIN STORAGE'' - 
''ENDSTORAGE'', permette di definire il contenuto dell'elemento di memorizzazione
di massa come "immagine". La sintassi di base prevede di indicare il nome del file 
sorgente che sarà convertito e inserito nel supporto. Se non si vuole utilizzare 
lo stesso nome, è possibile indicare un alias (''AS target'').

@syntax IMAGE source [AS target]

@example IMAGE "examples/data.png"
@example IMAGE "sprites.bmp" AS "sprites.dat"

@usedInExample storage_example_02.bas

@target all
@verified
</usermanual> */
Variable * image_storage( Environment * _environment, char * _source_name, char * _target_name, int _mode, int _flags, int _transparent_color, int _background_color, int _bank_expansion ) {

    file_storage( _environment, _source_name, _target_name );

    // No we are going to load the image from the PC.
    // Those variables will maintain the data of the original image.

    ImageDescriptor * imageDescriptor = image_descriptor_create( _environment, _source_name, _flags );

    // This is a workaround. In a previous release of ugBASIC, we must give
    // the color index to be used as transparency. If given, we active the
    // "FLAG TRANSPARENCY" during the conversion.
    if ( _transparent_color != -1 ) {
        _flags |= FLAG_TRANSPARENCY;
    }

    // Now we are able to convert the image from the original format to the
    // custom format of the target. This is a time efficient mode to store
    // the image, but not a space efficient (no compression is done).
    // Space efficiency can be applied after, if a bank is present.
    Variable * result = image_converter( _environment, imageDescriptor->data, imageDescriptor->width, imageDescriptor->height, imageDescriptor->depth, 0, 0, 0, 0, _mode, _transparent_color, _flags );

    if ( ( _flags & FLAG_COMPRESSED ) && !_environment->compressionForbidden ) {

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
        result->residentAssigned = 1;
        _environment->maxExpansionBankSize[1] = BANK_SIZE;

    }

    _environment->currentFileStorage->size = result->size;
    _environment->currentFileStorage->content = result->valueBuffer;

    return result;
        
}
