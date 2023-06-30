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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

extern char DATATYPE_AS_STRING[][16];

/**
 * @brief Return the width of a TILE on a TILESET
 * 
 * @param _environment Current calling environment
 * @param _tileset tileset
 */
/* <usermanual>
@keyword TILE WIDTH

@english
This function allows you to obtain the width of a given ''TILE'' or a given
set of ''TILES''. The width is expressed in tiles. If the parameter is a
``TILESET``, this is the width of a single tile.

@italian
Questa funzione permette di ottenere la larghezza della tile (''TILE'') 
o delle tiles (''TILES'') date, espressa in tiles. Se il parametro è un
''TILESET'', questa sarà la larghezza di una singola tessera.

@syntax = TILE WIDTH([tile])
@syntax = TILE WIDTH([tileset])

@example starshipWidth = TILE WIDTH( LOAD TILE("starship.png") )
@example singleTileWidth = TILE WIDTH(LOAD TILESET("tileset.tsx"))

@target all
</usermanual> */
Variable * tileset_tile_get_width( Environment * _environment, char * _tileset ) {

    Variable * tileset = NULL;

    tileset = variable_retrieve( _environment, _tileset );
    if ( tileset->type != VT_IMAGES || tileset->originalTileset == NULL ) {
        CRITICAL_TILE_WIDTH_NO_TILESET( _tileset );
    }

    Variable * width = variable_temporary( _environment, VT_BYTE, "(class)");

    variable_store( _environment, width->name, tileset->frameWidth );

    return width;

}

