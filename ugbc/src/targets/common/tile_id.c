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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>TILE ID(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _tileset Tileset
 * @param _id Tile id
 */
/* <usermanual>
@keyword TILE ID

@english
This function allows you retrieve the (numeric) identification, given the
symbolic name of the tile. Note that this information is available only 
at the time of compilation: therefore, the parameter with the tile 
identifier must be a constant.

@italian
Questa funzione permette di recuperare l'identificativo (numerico), dato dal 
nome simbolico della tile. Da notare che questa informazione è disponibile 
solo al momento della compilazione: quindi il parametro con l'identificativo 
della tessera deve essere una costante.

@syntax = TILE ID(tileset, name)

@example myTile = TILE ID(tileset, name_my_tile)

@usedInExample tileset_example_02.bas

@target all
@verified
</usermanual> */
int tile_id( Environment * _environment, char * _tileset, char * _id ) {

    if ( _environment->emptyProcedure ) 
        return 0;

    Variable * tileset = NULL;

    tileset = variable_retrieve( _environment, _tileset );
    if ( tileset->type != VT_IMAGES || tileset->originalTileset == NULL ) {
        CRITICAL_TILE_ID_NO_TILESET( _tileset );
    }

    return find_frame_by_type( _environment, tileset->originalTileset, tileset->name, _id );

}
