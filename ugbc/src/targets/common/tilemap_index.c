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

/* <usermanual>
@keyword TILEMAP INDEX

@english
This command allows you to obtain the index of the TILEMAP, with a given
layer, column and row.

@italian
Questo comando permette di ricavare l'indice della TILEMAP, per un dato
layer, colonna e riga

@syntax = TILEMAP INDEX( [column], [row] )
@syntax = TILEMAP INDEX( [column], [row], [layer] )

@example index = TILEMAP INDEX( 0, 0 )
@example index = TILEMAP INDEX( 0, 0, 1 )

@target all
</usermanual> */
Variable * tilemap_index_vars( Environment * _environment, char * _tilemap, char * _column, char * _row, char * _layer  ) {

    MAKE_LABEL

    Variable * tilemap = NULL;
    Variable * column = NULL;
    Variable * row = NULL;
    Variable * layer = NULL;

    if ( _column ) {
        column = variable_retrieve( _environment, _column );
    }
    
    if ( _row ) {
        row = variable_retrieve( _environment, _row );
    }

    if ( _layer ) {
        layer = variable_retrieve( _environment, _layer );
    }

    tilemap = variable_retrieve( _environment, _tilemap );
    if ( tilemap->type != VT_TILEMAP ) {
        CRITICAL_TILEMAP_INDEX_INVALID_TILEMAP( _tilemap );
    }

    Variable * tileset = variable_retrieve( _environment, tilemap->tileset->name );

    int size = tilemap->mapWidth * tilemap->mapHeight;

    Variable * index = NULL;

    if ( tilemap->size > 255 ) {
        index = variable_temporary( _environment, VT_WORD, "(index)" );
    } else {
        index = variable_temporary( _environment, VT_BYTE, "(index)" );
    }

    variable_store( _environment, index->name, 0 );

    if ( row && column ) {
        Variable * mapWidth = variable_temporary( _environment, VT_BYTE, "(map width)");
        variable_store( _environment, mapWidth->name, tilemap->mapWidth );
        index = variable_add( _environment, index->name, variable_mul( _environment, row->name, mapWidth->name )->name );
        index = variable_add( _environment, index->name, column->name );
    }

    if ( layer ) {
        Variable * sizeSize = variable_temporary( _environment, VT_WORD, "(size)");
        variable_store( _environment, sizeSize->name, size );
        index = variable_add( _environment, index->name, variable_mul( _environment, layer->name, sizeSize->name )->name );
    }

    Variable * frame = variable_temporary( _environment, VT_BYTE, "(frame)" );

    if ( tilemap->size > 255 ) {
        cpu_move_8bit_indirect2_16bit( _environment, tilemap->realName, index->realName, frame->realName );
    } else {
        cpu_move_8bit_indirect2_8bit( _environment, tilemap->realName, index->realName, frame->realName );
    }

    return frame;

}

