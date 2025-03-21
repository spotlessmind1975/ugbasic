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
 * @brief Emit code for <strong>LOAD TILEMAP(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 * @param _mode Mode to use to convert data
 */
/* <usermanual>
@keyword TILEMAP (storage)

@english
The ''TILEMAP'' command, inserted inside a ''BEGIN STORAGE'' - ''ENDSTORAGE'' block, 
allows you to define the content of the mass storage element as a tilemap. The basic 
syntax requires indicating the name of the ''source'' file that will be converted
and inserted into the medium. If you don't want to use the same name, you can indicate 
an alias (''AS target'').

@italian
Il comando ''TILEMAP'', inserita all'interno di un blocco ''BEGIN STORAGE'' - 
''ENDSTORAGE'', permette di definire il contenuto dell'elemento di memorizzazione
di massa come "tilemap". La sintassi di base prevede di indicare il nome del file 
sorgente che sarà convertito e inserito nel supporto. Se non si vuole utilizzare 
lo stesso nome, è possibile indicare un alias (''AS target'').

@syntax TILEMAP source [AS target]

@example TILEMAP "dungeon.tmx" AS "dungeon"

@target all
</usermanual> */
Variable * tilemap_storage( Environment * _environment, char * _source_name, char * _target_name, int _mode, int _flags, int _transparent_color, int _background_color, int _bank_expansion ) {

    file_storage( _environment, _source_name, _target_name, FSF_BINARY, 0 );

    Variable * final = variable_temporary( _environment, VT_TILEMAP, 0 );

    int width = 0;
    int height = 0;
    int depth = 0;

    char * lookedFilename = resource_load_asserts( _environment, _source_name );

    TmxMap * tilemap = tmx_load( lookedFilename );

    final->originalTilemap = tilemap;
    
    if ( !tilemap ) {
        CRITICAL_TILEMAP_LOAD_UNKNOWN_FORMAT( _source_name );
    }

    if ( !tilemap->layers ) {
        CRITICAL_TILEMAP_LOAD_MISSING_LAYER( _source_name );
    }

    if ( !tilemap->tilesets ) {
        CRITICAL_TILEMAP_LOAD_MISSING_TILESET( _source_name );
    }

    TsxTileset * tileset = tilemap->tilesets;

    if ( !tileset->source ) {
        CRITICAL_TILEMAP_SOURCE_MISSING( _source_name );
    }

    // while( tileset ) {
        if ( final->tileset ) {
            CRITICAL_TILEMAP_LOAD_ONLY_ONE_TILESET( _source_name );
        }
        char * tilesetFileName = strdup( lookedFilename );
        char * tilesetFileNameWithPath = malloc( MAX_TEMPORARY_STORAGE );
        memset( tilesetFileNameWithPath, 0, MAX_TEMPORARY_STORAGE );
        char * separator = strrchr( tilesetFileName, '/' );
        if ( separator ) {
            *(separator+1) = 0;
            strcpy( tilesetFileNameWithPath, tilesetFileName );
        }
        strcat( tilesetFileNameWithPath, tileset->source );
        lookedFilename = resource_load_asserts( _environment, tilesetFileNameWithPath );
        Variable * tilesetVar = tileset_load( _environment, lookedFilename, NULL, _mode, _flags, _transparent_color, _background_color, _bank_expansion );
        tilesetVar->firstGid = tileset->firstgid;
        // tileset = tileset->next;
    // }

    char * tilesetData = tilesetVar->valueBuffer;
    int tilesetSize = tilesetVar->size;

    TmxLayer * layer = tilemap->layers;

    while( layer ) {
        // if ( final->valueBuffer ) {
        //     CRITICAL_TILEMAP_LOAD_ONLY_ONE_LAYER( _filename );
        // }
        int size = layer->width * layer->height;
        char * mapData = NULL;
        if ( final->valueBuffer ) {
            if ( final->size != size ) {
                CRITICAL_TILEMAP_LOAD_ONLY_SAME_SIZE_LAYER( _source_name );
            }
            mapData = realloc( final->valueBuffer, final->size + size );
            final->valueBuffer = mapData;
            mapData += final->size;
        } else {
            mapData = malloc( size );
            final->valueBuffer = mapData;
        }
        memset( mapData, 0, size );
        for(int i=0; i<size; ++i ) {
            if ( layer->data[i] >= tilesetVar->firstGid ) {
                mapData[i] = ((unsigned char)layer->data[i]) - (tilesetVar->firstGid);
            } else {
                mapData[i] = 0xff;
            }
        }
        final->size += size;
        final->mapWidth = layer->width;
        final->mapHeight = layer->height;
        ++final->mapLayers;
        layer = layer->next;
    }

    char * tilemapData = final->valueBuffer;
    int tilemapSize = final->size;

    int screenWidthAsTilesConst = ( _environment->screenWidth / tilesetVar->frameWidth );
    int screenHeightAsTilesConst = ( _environment->screenHeight / tilesetVar->frameHeight );
    int deltaFrameConst = final->mapWidth > screenWidthAsTilesConst ? ( final->mapWidth - screenWidthAsTilesConst ) : 0;
    int sizeConst = final->mapWidth * final->mapHeight;
    int deltaFrameScreenConst = sizeConst - ( final->mapWidth * screenHeightAsTilesConst );
    int mapWidth = final->mapWidth;
    int frameWidth = tilesetVar->frameWidth;
    int frameHeight = tilesetVar->frameHeight;
    int mapLayers = final->mapLayers;
    int frameSize = tilesetVar->frameSize;

    // +-----+---+---------------------------------------+
    // |   0 | 2 | Offset to tileset                     |
    // +-----+---+---------------------------------------+
    // |  +2 | 1 | Screen width as tiles                 |
    // +-----+---+---------------------------------------+
    // |  +3 | 1 | Screen height as tiles                |
    // +-----+---+---------------------------------------+
    // |  +4 | 1 | Delta frame                           |
    // +-----+---+---------------------------------------+
    // |  +5 | 2 | Size (w x h)                          |
    // +-----+---+---------------------------------------+
    // |  +7 | 2 | Delta Frame Screen                    |
    // +-----+---+---------------------------------------+
    // |  +9 | 1 | Map width                             |
    // +-----+---+---------------------------------------+
    // | +10 | 1 | Frame width                           |
    // +-----+---+---------------------------------------+
    // | +11 | 1 | Frame height                          |
    // +-----+---+---------------------------------------+
    // | +12 | 1 | Map layers                            |
    // +-----+---+---------------------------------------+
    // | +13 | 2 | Frame size                            |
    // +-----+---+---------------------------------------+
    // | +15 |                                           |
    // +-----+-------------------------------------------+
    //
    // 1) TILEMAP
    // 2) TILESET

    int size = tilesetSize + tilemapSize + 15;
    char * data = malloc( tilesetSize + tilemapSize + 15 );

#ifdef CPU_BIG_ENDIAN
    data[1] = ( tilemapSize & 0xff );
    data[0] = ( ( tilemapSize >> 8 ) & 0xff );
#else
    data[0] = ( tilemapSize & 0xff );
    data[1] = ( ( tilemapSize >> 8 ) & 0xff );
#endif

    // printf( " tilemapSize = %d (%4.4x)\n", tilemapSize, tilemapSize );

    data[2] = ( screenWidthAsTilesConst & 0xff );

    // printf( " screenWidthAsTilesConst = %d (%2.2x)\n", screenWidthAsTilesConst, screenWidthAsTilesConst );

    data[3] = ( screenHeightAsTilesConst & 0xff );

    // printf( " screenHeightAsTilesConst = %d (%2.2x)\n", screenHeightAsTilesConst, screenHeightAsTilesConst );

    data[4] = ( deltaFrameConst & 0xff );

    // printf( " deltaFrameConst = %d (%2.2x)\n", deltaFrameConst, deltaFrameConst );

#ifdef CPU_BIG_ENDIAN
    data[6] = ( sizeConst & 0xff );
    data[5] = ( ( sizeConst >> 8 ) & 0xff );
#else
    data[5] = ( sizeConst & 0xff );
    data[6] = ( ( sizeConst >> 8 ) & 0xff );
#endif

    // printf( " sizeConst = %d (%2.2x)\n", sizeConst, sizeConst );

#ifdef CPU_BIG_ENDIAN
    data[8] = ( deltaFrameScreenConst & 0xff );
    data[7] = ( ( deltaFrameScreenConst >> 8 ) & 0xff );
#else
    data[7] = ( deltaFrameScreenConst & 0xff );
    data[8] = ( ( deltaFrameScreenConst >> 8 ) & 0xff );
#endif

    // printf( " deltaFrameScreenConst = %d (%2.2x)\n", deltaFrameScreenConst, deltaFrameScreenConst );

    data[9] = ( mapWidth & 0xff );

    // printf( " mapWidth = %d (%2.2x)\n", mapWidth, mapWidth );

    data[10] = ( frameWidth & 0xff );

    // printf( " frameWidth = %d (%2.2x)\n", frameWidth, frameWidth );

    data[11] = ( frameHeight & 0xff );

    // printf( " frameHeight = %d (%2.2x)\n", frameHeight, frameHeight );

    data[12] = ( mapLayers & 0xff );

    // printf( " mapLayers = %d (%2.2x)\n", mapLayers, mapLayers );

#ifdef CPU_BIG_ENDIAN
    data[14] = ( frameSize & 0xff );
    data[13] = ( ( frameSize >> 8 ) & 0xff );
#else
    data[13] = ( frameSize & 0xff );
    data[14] = ( ( frameSize >> 8 ) & 0xff );
#endif

    // printf( " frameSize = %d (%4.4x)\n", frameSize, frameSize );

    memcpy( &data[15], tilemapData, tilemapSize );
    memcpy( &data[15+tilemapSize], tilesetData, tilesetSize );

    _environment->currentFileStorage->size = size;
    _environment->currentFileStorage->content = data;

    // printf( "size tileset = %d\n", tilesetSize );

    // printf( "size total = %d\n", size );

    variable_temporary_remove( _environment, tilesetVar->name );

    return final;

}
