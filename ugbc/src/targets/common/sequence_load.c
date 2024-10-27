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
@keyword LOAD SEQUENCE

@english

The ''LOAD SEQUENCE'' command allows you to load an set of images and to convert each one
into a ''SEQUENCE''. A Sequence is a set of set of images, numbered by 0 to sequence
count (vertically), and from 0 to frame count each (horizontally), which can be used individually with the PUT IMAGE 
command, referring to the corresponding frame and sequence.
The frames are cut out of the original image, using the size provided in the 
''FRAME SIZE (w, h)''. It should be noted that, for this reason, ''SEQUENCE'' images
must have a total of a size equal to an entire multiple of the size of the individual frame. 
It is also possible to indicate an offset from which you will have to start cutting the image 
(parameter ''ORIGIN(zx,zy)'') and one related to each individual cutout (''OFFSET (dx, dy)'').

So, the first parameter is the filename to parse. The command support a set of modern image
format, like JPEG baseline & progressive,
PNG 1/2/4/8/16-bit-per-channel, TGA, BMP (non-1bpp, non-RLE), PSD 
(composited view only, no extra channels, 8/16 bit-per-channel), 
GIF, HDR (radiance rgbE format), PIC (Softimage PIC) and PNM (PPM and PGM 
binary only) The image will be converted into a way that can be 
efficiently drawn on the screen. 

The second parameter is the mode to use to convert the given data (by default, it is 
equal to current mode) 

Since it is possible to load only one file of the same 
type at a time, it is necessary to be able to indicate an "alias" with 
which to exceed this limit. In this regard, there is also 
the ''AS'' syntax, which allows you to load the same file several 
times but with different names. 

A series of flags, separated by spaces, can be added at loading time 
to modify the behavior of ugBASIC.

The ''FLIP X'' flag allows you to flip the (entire) image horizontally,
before cutting and translating it into the native format. The same is true for the 
''FLIP Y'' command, which instead inverts the (entire) image vertically. 
There is also the ''FLIP XY'' (or ''FLIP YX'') parameter to act, 
simultaneously, on both directions.

The ''ROLL X'' flag allows you to SHIFT the (entire) image horizontally,
for the entire size of a frame, in order to generate intermediate
frames. The very same for ''ROLL Y'' command, which does the same
vertically. There is also the ''ROLL XY'' (or ''ROLL YX'') parameter to act, 
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

The (entire) image can be loaded as a transparent image (if the original
image has no transparency) using the keyword ''TRANSPARENCY'',
followe by an optional parameter that represent the color
to consider as transparent.

The (entire) image can be loaded as a transparent image (if the original
image has no transparency) using the keyword ''OPACITY'',
followe by an optional parameter that represent the color
to consider as pavement,.

The resulting ''SEQUENCE'' can be loaded directly into the expansion
memory using the ''BANKED'' keyword. The number represent
the shared resident to use as target for this image.
For some targets this is the default. If you want,
you can move the image onto the resident memory by
using the ''UNBANKED'' keyword.

Finally, if the image is not expected to change during gameplay, it can be marked 
with the ''READONLY'' attribute: in this case, the image will be stored 
in read-only memory, if available.

@italian

Il comando ''LOAD SEQUENCE'' consente di caricare un set di immagini come ''SEQUENCE''. 
Un ''SEQUENCE'' è un set di immagini, numerata per il conteggio di 0 a frame, che
può essere utilizzato individualmente con il comando PUT IMAGE, facendo riferimento 
al frame corrispondente. I frame vengono ritagliati dall'immagine originale, 
utilizzando le dimensioni fornite in ''FRAME SIZE (w, h) ''. Va notato che, 
per questo motivo, l'immagine intera originale deve avere un totale di una 
dimensione pari a un intero multiplo della dimensione del singolo frame.
È anche possibile indicare un offset da cui si dovrà iniziare a tagliare l'immagine
(parametro ''ORIGIN(zx,zy)'') e uno relativo a ogni singolo ritaglio (''OFFSET(dx,dy) '').

Quindi, il primo parametro è il nome file da analizzare. Il comando supporta
un set formati moderni, come JPEG Baseline & Progressive,
PNG 1/2/4/8/16-bit-per-channel, TGA, BMP (non-1bpp, non-rle), PSD
(Vista composita solo, nessun canale extra, 8/16 bit-per-channel),
GIF, HDR (formato radiante RGBE), foto (softimage pic) e PNM (PPM e PGM
Solo binario) l'immagine verrà convertita in un modo che può essere
disegnato in modo efficiente sullo schermo.

Il secondo parametro è la modalità da utilizzare per convertire i dati forniti 
(per impostazione predefinita, è uguale alla modalità corrente)

Poiché è possibile caricare solo un file dello stesso nome alla volta, è necessario 
essere in grado di indicare un "alias" con che per superare questo limite. 
A questo proposito, c'è anche La sintassi ''AS'', che consente di caricare lo 
stesso file diverse volte ma con nomi diversi.

Una serie di flag, separate da spazi, può essere aggiunta al momento del caricamento
Per modificare il comportamento di ugBASIC.

Il flag ''FLIP X '' consente di capovolgere l'intera immagine in orizzontale, prima
di tagliarla e tradurla nel formato nativo. Lo stesso vale per il flag ''FLIP Y'',
che invece inverte l'intera immagine in verticale. Vi è anche il flag ''FLIP XY'' 
(o ''FLIP XY'') per agire, contemporaneamente, su entrambe le direzioni.

Il flag ''ROLL X'' consente di spostare l'intera immagine in orizzontale,
per l'intera dimensione di un frame, per generare i fotogrammi intercalari.
Lo stesso per il flag ''ROLL Y'', che fa lo stesso verticalmente, e
''ROLL XY '' (o ''ROLL YX'') per  agire, contemporaneamente, su entrambe le
 direzioni.

Il flag "COMPRESSED" consente di comprimere l'immagine, se possibile. La 
compressione è un meccanismo di risparmio spaziale, in cui i dati nativi 
dell'immagine sono rappresentati in una forma più compatta, così che
ugBASIC sia in grado di convertirsi rapidamente al momento appropriato.

La flag "ORVERLAYED" può essere utilizzata sui sistemi con una tavolozza
di pochi colori, per indicare quale di essi deve essere preservato,
durante la fase di disegno, per avere l'effetto di trasparenza.

Il flag "EXACT" consente di bypassare il rilevamento automatico
della tavolozza, optando per la rappresentazione dei colori precisa.

L'immagine (intera) può essere caricata come un'immagine trasparente (se l'originale
L'immagine non ha trasparenza) usando la parola chiave ''TRANSPARENCY'',
seguire da un parametro opzionale che rappresenta il colore
considerare trasparente.

L'immagine (intera) può essere caricata come un'immagine trasparente (se l'originale
L'immagine non ha trasparenza) usando la parola chiave ''OPACITY'',
seguire da un parametro opzionale che rappresenta il colore
considerare come pavimentazione,.

La ''SEQUENCE'' risultante può essere caricata direttamente nell'espansione
memoria utilizzando la parola chiave ''BANK''. Il numero rappresenta
il blocco residente condiviso, da utilizzare come target per questa 
immagine. Per alcuni target questo è il flag predefinito. Si può cambiare
tale impostazione usando la parola chiave ''UNBANKED''.

Infine, se l'immagine non dovesse cambiare durante il gameplay, può 
essere contrassegnata con l'attributo "READONLY": in questo caso, 
l'immagine verrà memorizzata Nella memoria di sola lettura, se disponibile.

@syntax = LOAD SEQUENCE( filename [AS alias][,mode] ) frame [ORIGIN(dx,dy)] [fl] [tr] [op] [bg] [bk] [READONLY]
@syntax = LOAD SEQUENCE( filename [AS alias][,mode] ) frame [fl] [tr] [op] [bg] [bk] [READONLY]
@syntax     frame : [ FRAME SIZE(w, h) [OFFSET(dx,dy)] [ORIGIN(zx, zy)] | FRAME AUTO]
@syntax     fl : [FLIP X] [FLIP Y] [FLIP XY] [FLIP YX] 
@syntax          [COMPRESSED] [OVERLAYED] [EXACT]
@syntax          [ROLL X] [ROLL Y] [ROLL XY] [ROLL YX]
@syntax     tr : [TRANSPARENCY | TRANSPARENCY color]
@syntax     op : [OPACITY | OPACITY color]
@syntax     bg : [BACKGROUND color]
@syntax     bk : [UNBANKED | BANKED | BANKED(number)]

@example starship = LOAD SEQUENCE("starship.png") FRAME SIZE (16, 16)
@example starship2 = LOAD SEQUENCE("starship.png" AS "starship2") FRAME SIZE (32, 32) OFFSET(2,2)
@example alienAt11 = LOAD SEQUENCE("alien.jpg",11) FRAME SIZE AUTO
@example alien2 = LOAD SEQUENCE("alien.jpg" AS "alien2",11) FRAME SIZE(8,8) TRANSPARENCY

@alias STRIP LOAD
</usermanual> */

/* <usermanual>
@keyword STRIP LOAD
@alias LOAD SEQUENCE
</usermanual> */

Variable * sequence_load( Environment * _environment, char * _filename, char * _alias, int _mode, int _frame_width, int _frame_height, int _flags, int _transparent_color, int _background_color, int _bank_expansion, int _origin_x, int _origin_y, int _offset_x, int _offset_y ) {

    Variable * final = variable_temporary( _environment, VT_SEQUENCE, 0 );

    if ( _environment->emptyProcedure ) {
        return final;
    }

    if ( _environment->tenLinerRulesEnforced ) {
        CRITICAL_10_LINE_RULES_ENFORCED( "LOAD SEQUENCE");
    }

    if ( _environment->sandbox ) {
        CRITICAL_SANDBOX_ENFORCED( "LOAD SEQUENCE");
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

    int bufferSize = 0;
    Variable * firstImage = NULL;
    Variable * lastImage = NULL;

    ImageDescriptor * frame = atlasDescriptor->frames;
    for(int i=0; i<atlasDescriptor->count; ++i) {
        Variable * partial = image_converter( _environment, frame->data, frame->width, frame->height, frame->depth, 0, 0, frame->width, frame->height, _mode, _transparent_color, _flags );
        if ( ! firstImage && ! lastImage ) {
            firstImage = partial;
            lastImage = partial;
        } else {
            lastImage->next = partial;
            lastImage = lastImage->next;
        }
        bufferSize += partial->size;
        frame = frame->next;
    }

    bufferSize += 3;

    adiline1("LS2:%x", bufferSize );

    char * buffer = malloc( bufferSize );
    char * ptr = buffer;
    ptr[0] = atlasDescriptor->horizontal;
    ptr[1] = _frame_width;
    ptr[2] = atlasDescriptor->horizontal;

    if ( ( firstImage->size * atlasDescriptor->horizontal ) > 0xffff ) {
        CRITICAL_SEQUENCE_LOAD_IMAGE_TOO_BIG( _filename );
    }

    final->offsettingFrames = offsetting_size_count( _environment, firstImage->size, atlasDescriptor->horizontal );
    offsetting_add_variable_reference( _environment, final->offsettingFrames, final, 0 );

    final->offsettingSequences = offsetting_size_count( _environment, atlasDescriptor->horizontal*firstImage->size, atlasDescriptor->vertical );
    offsetting_add_variable_reference( _environment, final->offsettingSequences, final, 1 );

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
    final->frameSize = firstImage->size;
    final->frameCount = atlasDescriptor->horizontal;

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
            CRITICAL_COMPRESSION_FAILED(_filename);
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
