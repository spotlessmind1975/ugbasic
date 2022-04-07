/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
#include "../../lib/stb_image.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>TILE ... BELONG TO ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _tile Tile to check
 * @param _tiles Tiles to check
 */
/* <usermanual>
@keyword TILE BELONG TO

@english
The ''TILE ... BELONG TO ... '' command allows you to check if a certain ''TILE'' belongs 
to the set of tiles that make up a TILES. In general, ''TILES'' are made up of multiple 
simple tiles and, when drawn, actually occupy multiple tiles. This command allows you to 
make distinctions.

@italian
Il comando ''TILE ... BELONG TO ...'' permette di verificare se un determinato ''TILE'' 
appartiene all'insieme dei tiles che compongono un ''TILES''. In generale, i ''TILES''
sono formati da più tile semplici e, quando vengono disegnati, occupano effettivamente 
più tile. Questo comando consente di effettuare distinzioni.

@syntax = TILE [tile] BELONG TO [tiles]

@example = tile BELONG TO multitiles

@target all
</usermanual> */
Variable * tile_belong( Environment * _environment, char * _tile, char * _tiles ) {

    MAKE_LABEL

    outhead1("%sbelong:", label );

    Variable * tile = variable_retrieve_or_define( _environment, _tile, VT_TILE, 0 );
    Variable * tiles = variable_retrieve_or_define( _environment, _tiles, VT_TILES, 0 );

    Variable * curTile = variable_temporary( _environment, VT_BYTE, "(tile)" ); 
    cpu_move_8bit( _environment, tile->realName, curTile->realName );

    Variable * minTile = variable_cast( _environment, tile_get_first( _environment, _tiles )->name, VT_WORD ); 
    Variable * tileWidth = tile_get_width( _environment, _tiles ); 
    Variable * tileHeight = tile_get_height( _environment, _tiles ); 
    Variable * maxTile = variable_mul( _environment, tileWidth->name, tileHeight->name ); 

    variable_add_inplace_vars( _environment, maxTile->name, minTile->name );

    return variable_and( _environment, 
                            variable_greater_than( _environment, curTile->name, minTile->name, 1 )->name,
                            variable_less_than( _environment, curTile->name, maxTile->name, 1 )->name
                            );       

}
