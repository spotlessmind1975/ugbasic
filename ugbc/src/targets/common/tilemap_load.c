/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
@keyword LOAD TILEMAP

@english

@italian

@syntax = LOAD TILEMAP([filename])

@example x = LOAD TILEMAP("dungeon.tmx")

@target all
</usermanual> */
Variable * tilemap_load( Environment * _environment, char * _filename, char * _alias, int _mode, int _flags, int _transparent_color, int _background_color, int _bank_expansion ) {

    MAKE_LABEL

    Variable * final = variable_temporary( _environment, VT_TILEMAP, 0 );

    if ( _environment->emptyProcedure ) {
        return final;
    }

    if ( _environment->tenLinerRulesEnforced ) {
        CRITICAL_10_LINE_RULES_ENFORCED( "LOAD TILEMAP");
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

    TmxMap * tilemap = tmx_load( lookedFilename );

    final->originalTilemap = tilemap;
    
    if ( !tilemap ) {
        CRITICAL_TILEMAP_LOAD_UNKNOWN_FORMAT( _filename );
    }

    if ( !tilemap->layers ) {
        CRITICAL_TILEMAP_LOAD_MISSING_LAYER( _filename );
    }

    if ( !tilemap->tilesets ) {
        CRITICAL_TILEMAP_LOAD_MISSING_TILESET( _filename );
    }

    TsxTileset * tileset = tilemap->tilesets;

    while( tileset ) {
        if ( final->tileset ) {
            CRITICAL_TILEMAP_LOAD_ONLY_ONE_TILESET( _filename );
        }
        char name[MAX_TEMPORARY_STORAGE]; sprintf( name, "%stileset", label );        
        final->tileset = variable_define( _environment, name, VT_IMAGES, 0 );
        char * tilesetFileName = strdup( lookedFilename );
        char * tilesetFileNameWithPath = malloc( MAX_TEMPORARY_STORAGE );
        memset( tilesetFileNameWithPath, 0, MAX_TEMPORARY_STORAGE );
        char * separator = strrchr( tilesetFileName, '/' );
        if ( separator ) {
            *(separator+1) = 0;
            strcpy( tilesetFileNameWithPath, tilesetFileName );
        }
        strcat( tilesetFileNameWithPath, tileset->source );
        variable_direct_assign( _environment, final->tileset->name, tileset_load( _environment, tilesetFileNameWithPath, NULL, _mode, _flags, _transparent_color, _background_color, _bank_expansion )->name );
        final->tileset->firstGid = tileset->firstgid;
        tileset = tileset->next;
    }

    TmxLayer * layer = tilemap->layers;

    while( layer ) {
        // if ( final->valueBuffer ) {
        //     CRITICAL_TILEMAP_LOAD_ONLY_ONE_LAYER( _filename );
        // }
        int size = layer->width * layer->height;
        char * mapData = NULL;
        if ( final->valueBuffer ) {
            if ( final->size != size ) {
                CRITICAL_TILEMAP_LOAD_ONLY_SAME_SIZE_LAYER( _filename );
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
            if ( layer->data[i] >= final->tileset->firstGid ) {
                mapData[i] = ((unsigned char)layer->data[i]) - (final->tileset->firstGid);
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
