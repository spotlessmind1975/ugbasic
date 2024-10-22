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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>LOAD TILE(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 * @param _mode Mode to use to convert data
 */
/* <usermanual>
@keyword LOAD TILE

@english

The ''LOAD TILE'' command allows you to load an image and to convert it into 
an ''TILE'', that is a format that will be converted into a way that can be efficiently drawn 
on the screen using the tiles. The second parameter is the mode to use to convert 
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

The ''ROLL X'' flag allows you to SHIFT the (entire) image horizontally,
for the entire size of a frame, in order to generate intermediate
frames. The very same for ''ROLL Y'' command, which does the same
vertically. There is also the ''ROLL XY'' (or ''ROLL YX'') parameter to act, 
simultaneously, on both directions.

@italian

Il comando ''LOAD TILE'' consente di caricare un'immagine e convertirla in
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

Il flag ''ROLL X'' consente di spostare l'intera immagine in orizzontale,
per l'intera dimensione di un frame, per generare i fotogrammi intercalari.
Lo stesso per il flag ''ROLL Y'', che fa lo stesso verticalmente, e
''ROLL XY '' (o ''ROLL YX'') per  agire, contemporaneamente, su entrambe le
 direzioni.

Il flag ''COMPRESSED'' consente di comprimere l'immagine, se
possibile. La compressione è un meccanismo di risparmio di spazio, in cui i dati nativi dell'immagine sono rappresentati in una forma più compatta, che
ugBASIC sarà in grado di convertire rapidamente in grafica al momento opportuno.

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

@syntax = LOAD TILE( filename [AS alias][,mode] ) [fl] 
@syntax     fl : [FLIP X] [FLIP Y] [FLIP XY] [FLIP YX] 
@syntax     fl : [ROLL X] [ROLL Y] [ROLL XY] [ROLL YX] 

@example starship = LOAD TILE("starship.png")
@example starship2 = LOAD TILE("starship.png" AS "starship2")
@example alienAt11 = LOAD TILE("alien.jpg",11)
@example alien2 = LOAD TILE("alien.jpg" AS "alien2",11)

@alias TILE LOAD
</usermanual> */

/* <usermanual>
@keyword TILE LOAD
@alias LOAD TILE
</usermanual> */

Variable * tile_load( Environment * _environment, char * _filename, int _flags, char * _tileset, int _index ) {

    Variable * tileset = NULL;

    if ( _tileset ) {
        tileset = variable_retrieve( _environment, _tileset );
        if ( tileset->type != VT_TILESET ) {
            CRITICAL_TILE_LOAD_ON_NON_TILESET( _tileset );
        }
        if ( ! _environment->tilesets[tileset->value] ) {
            CRITICAL_TILE_LOAD_ON_NON_TILESET( _tileset );
        }
    }

    if ( _environment->tenLinerRulesEnforced ) {
        CRITICAL_10_LINE_RULES_ENFORCED( "LOAD TILE");
    }
    
    if ( _environment->sandbox ) {
        CRITICAL_SANDBOX_ENFORCED( "LOAD TITLE");
    }

    int width = 0;
    int height = 0;
    int depth = 0;

    char * lookedFilename = resource_load_asserts( _environment, _filename );

    adiline2("LT:%s:%s", _filename, lookedFilename );

    unsigned char* source = stbi_load(lookedFilename, &width, &height, &depth, 0);

    if ( !source ) {
        CRITICAL_TILE_LOAD_UNKNOWN_FORMAT( _filename );
    }

    if ( width != 8 ) {
        CRITICAL_TILE_INVALID_WIDTH( width );
    }

    if ( height != 8 ) {
        CRITICAL_TILE_INVALID_HEIGHT( height );
    }

    if( _flags & FLAG_FLIP_X ) {
        source = image_flip_x( _environment, source, width, height, depth );
    }
    if( _flags & FLAG_FLIP_Y ) {
        source = image_flip_y( _environment, source, width, height, depth );
    }

    Variable * index = variable_temporary( _environment, VT_TILE, "(tile index)" );

    Variable * realImage = image_converter( _environment, source, 8, 8, depth, 0, 0, 8, 8, BITMAP_MODE_DEFAULT, 0, _flags );

    stbi_image_free(source);

    TileDescriptors * descriptors;

    if ( tileset ) {
        descriptors = _environment->tilesets[tileset->value];
    } else {
        if ( ! _environment->descriptors ) {
            _environment->descriptors = malloc( sizeof( TileDescriptors ) );
            _environment->descriptors->count = 0;
            _environment->descriptors->first = 1;
            _environment->descriptors->firstFree = _environment->descriptors->first;
            _environment->descriptors->lastFree = 128;
        }
        descriptors = _environment->descriptors;
    }

    int tile = _index;

    if ( tile == -1 ) {
        tile = tile_allocate( descriptors, realImage->valueBuffer + IMAGE_WIDTH_SIZE + IMAGE_HEIGHT_SIZE );
    } else {
        memcpy( descriptors->data[tile].data, realImage->valueBuffer + IMAGE_WIDTH_SIZE + IMAGE_HEIGHT_SIZE, 8 );
        descriptors->descriptor[tile] = calculate_tile_descriptor( &descriptors->data[tile] );
    }

    if ( tile == -1 ) {
        CRITICAL_CANNOT_ALLOCATE_MORE_TILE();
    }    

    cpu_store_8bit( _environment, index->realName, tile );

    variable_delete( _environment, realImage->name );

    return index;

}
