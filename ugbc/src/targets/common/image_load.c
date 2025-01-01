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
#include "../../libs/rle.h"

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

The command support a set of modern image format, like JPEG baseline & progressive,
PNG 1/2/4/8/16-bit-per-channel, TGA, BMP (non-1bpp, non-RLE), PSD 
(composited view only, no extra channels, 8/16 bit-per-channel), 
GIF, HDR (radiance rgbE format), PIC (Softimage PIC) and PNM (PPM and PGM 
binary only) The image will be converted into a way that can be 
efficiently drawn on the screen. 

Since it is possible to load only one file of the same 
type at a time, it is necessary to be able to indicate an "alias" with 
which to exceed this limit. In this regard, there is also 
the ''AS'' syntax, which allows you to load the same file several 
times but with different names. 

A series of flags, separated by spaces, can be added at loading time 
to modify the behavior of ugBASIC.

The ''FLIP X'' flag allows you to flip the image horizontally,
before translating it into the native format. The same is true for the 
''FLIP Y'' command, which instead inverts the image vertically. 
There is also the ''FLIP XY'' (or ''FLIP YX'') parameter to act, 
simultaneously, on both directions.

The ''COMPRESSED'' flag allows you to compress the image, if 
possible. Compression is a space-saving mechanism, in which the 
native data of the image is represented in a more compact form, 
which ugBASIC will be able to quickly convert into graphics at 
the appropriate time.

The ''OVERLAYED'' flag can be used on systems with a palette 
of few colors, to indicate which of them must be preserved 
during the drawing phase, to have the transparency effect.

The ''EXACT'' flag allows you to bypass the automatic detection 
of the palette, opting for the representation of the colors 
according to what is contained in it.

The image can be loaded as a transparent image (if the original
image has no transparency) using the keyword ''TRANSPARENCY'',
followe by an optional parameter that represent the color
to consider as transparent.

The image can be loaded as a transparent image (if the original
image has no transparency) using the keyword ''OPACITY'',
followe by an optional parameter that represent the color
to consider as pavement,.

The image can be loaded directly into the expansion
memory using the BANKED keyword. The number represent
the shared resident to use as target for this image.
For some targets this is the default. If you want,
you can move the image onto the resident memory by
using the ''UNBANKED'' keyword.

Finally, if the image is not expected to change during gameplay, it can be marked 
with the ''READONLY'' attribute: in this case, the image will be stored 
in read-only memory, if available.

@italian

Il comando ''LOAD IMAGE'' consente di caricare un'immagine e convertirla in
una ''IMAGE''. Il secondo parametro è la modalità da utilizzare per convertire
i dati forniti (per impostazione predefinita, è uguale alla modalità corrente)

Il comando supporta un set di formati immagine moderni, come JPEG baseline e progressivo,
PNG 1/2/4/8/16 bit per canale, TGA, BMP (non 1bpp, non RLE), PSD
(solo vista composita, nessun canale extra, 8/16 bit per canale),
GIF, HDR (formato radiance rgbE), PIC (Softimage PIC) e PNM (solo PPM e PGM
binary). L'immagine verrà convertita in un modo che può essere
disegnata in modo efficiente sullo schermo.

Poiché è possibile caricare un solo file dello stesso
tipo alla volta, è necessario poter indicare un "alias" con
il quale superare questo limite. A questo proposito, esiste anche
la sintassi ''AS'', che consente di caricare più volte lo stesso
file ma con nomi diversi.

Una serie di flag, separati da spazi, possono essere aggiunti in fase di caricamento
per modificare il comportamento di ugBASIC.

Il flag ''FLIP X'' consente di capovolgere l'immagine orizzontalmente,
prima di tradurla nel formato nativo. Lo stesso vale per il
comando ''FLIP Y'', che invece inverte l'immagine verticalmente.
Esiste anche il parametro ''FLIP XY'' (o ''FLIP YX'') per agire,
contemporaneamente, su entrambe le direzioni.

Il flag ''COMPRESSED'' consente di comprimere l'immagine, se
possibile. La compressione è un meccanismo di risparmio di spazio, in cui i dati nativi dell'immagine sono rappresentati in una forma più compatta, che
ugBASIC sarà in grado di convertire rapidamente in grafica al momento opportuno.

Il flag ''OVERLAYED'' può essere utilizzato su sistemi con una tavolozza
di pochi colori, per indicare quali di essi devono essere conservati
durante la fase di disegno, per avere l'effetto trasparenza.

Il flag ''EXACT'' consente di bypassare il rilevamento automatico
della tavolozza, optando per la rappresentazione dei colori
in base a ciò che è contenuto in essa.

L'immagine può essere caricata come immagine trasparente (se l'immagine originale
non ha trasparenza) utilizzando la parola chiave ''TRANSPARENCY'',
seguita da un parametro opzionale che rappresenta il colore
da considerare come trasparente.

L'immagine può essere caricata come immagine trasparente (se l'immagine originale non ha trasparenza) usando la parola chiave ''OPACITY'',
seguita da un parametro opzionale che rappresenta il colore
da considerare come pavimentazione.

L'immagine può essere caricata direttamente nella memoria di espansione
usando la parola chiave BANKED. Il numero rappresenta
il residente condiviso da usare come target per questa immagine.
Per alcuni target questa è l'impostazione predefinita. Se vuoi,
puoi spostare l'immagine nella memoria residente
usando la parola chiave ''UNBANKED''.

Infine, se non è previsto che l'immagine cambi durante il gioco, può essere contrassegnata
con l'attributo ''READONLY'': in questo caso, l'immagine verrà archiviata
nella memoria di sola lettura, se disponibile.

@syntax = LOAD IMAGE( filename [AS alias][,mode] ) [fl] [tr] [op] [bg] [bk] [READONLY]
@syntax     fl : [FLIP X] [FLIP Y] [FLIPXY] [FLIPYX] 
@syntax          [COMPRESSED] [OVERLAYED] [EXACT]
@syntax     tr : [TRANSPARENCY | TRANSPARENCY color]
@syntax     op : [OPACITY | OPACITY color]
@syntax     bg : [BACKGROUND color]
@syntax     bk : [UNBANKED | BANKED | BANKED(number)]

@example starship = LOAD IMAGE("starship.png")
@example starship2 = LOAD IMAGE("starship.png" AS "starship2")
@example alienAt11 = LOAD IMAGE("alien.jpg",11)
@example alien2 = LOAD IMAGE("alien.jpg" AS "alien2",11)

@usedInExample image_loading_01.bas

@alias IMAGE LOAD
</usermanual> */

/* <usermanual>
@keyword IMAGE LOAD
@alias LOAD IMAGE
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
    ImageDescriptor * imageDescriptor = image_descriptor_create( _environment, _filename, _flags );

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
    result = image_converter( _environment, imageDescriptor->data, imageDescriptor->width, imageDescriptor->height, imageDescriptor->depth, 0, 0, 0, 0, _mode, _transparent_color, _flags );

    // ADI INFO
    adiline1("LI2:%x", result->size );

    // We can now store the data of the image directly into the variable.
    result->originalBitmap = imageDescriptor->data;
    result->originalWidth = imageDescriptor->width;
    result->originalHeight = imageDescriptor->height;
    result->originalDepth = imageDescriptor->depth;

#ifdef __c128__

    if (!_environment->compressionForbidden&&_environment->enableRle) {

        // Try to compress the result of image conversion.
        // This means that the buffer will be compressed using RLE
        // algorithm. The original size of the buffer will be considered
        // as "uncompressed" size.
        RLECompressor * compressor = rle_create( );
        result->uncompressedSize = result->size;
        MemoryBlock * output = rle_compress( compressor, result->valueBuffer, result->uncompressedSize, &result->size );

        int temporary;
        MemoryBlock * outputCheck = rle_uncompress( compressor, output, result->size, &temporary );

        if ( memcmp( outputCheck, result->valueBuffer, result->uncompressedSize ) != 0 ) {
            CRITICAL_COMPRESSION_FAILED(_filename);
        }
        rle_free( compressor );

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
            result->compression = CMP_RLE;
        }

    }

#endif
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
                CRITICAL_COMPRESSION_FAILED(_filename);
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
            CRITICAL_COMPRESSION_FAILED(_filename);
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
