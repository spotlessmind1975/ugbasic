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
 * @brief Return the height of a TILEMAP
 * 
 * @param _environment Current calling environment
 * @param _tileset tileset
 */
/* <usermanual>
@keyword TILEMAP AT

@english
This function allows to know which is the tile present in a tilemap, 
given the coordinates of the tile itself. If the tilemap has more than
one layer, the first layer will be returned. If you need to retrieve the
tile of a different level, you have to indicate the layer with the ''LAYER'' 
keyword.

@italian
Questa funzione permette di conoscere quale sia il tile di una mappa, 
date le coordinate del tile stesso. Se la mappa ha più di un livello, 
verrà restituito il primo livello. Se si deve recuperare il tile 
di un livello diverso, si deve indicare con la parola chiave ''LAYER''.

@syntax = TILEMAP [LAYER layer] map AT([x],[y])

@example tile = TILEMAP map AT(0,0)
@example tile = TILEMAP map LAYER 2 AT(0,0)

@target all
</usermanual> */
Variable * tilemap_at( Environment * _environment, char * _tilemap, char * _x, char * _y, char * _layer ) {

    Variable * tilemap = NULL;
    Variable * x = NULL;
    Variable * y = NULL;
    Variable * layer = NULL;
    Variable * frame = variable_temporary( _environment, VT_BYTE, "(frame)" );

    tilemap = variable_retrieve( _environment, _tilemap );
    if ( tilemap->type != VT_TILEMAP ) {
        CRITICAL_TILEMAP_HEIGHT_NO_TILEMAP( _tilemap );
    }

    Variable * width = variable_temporary( _environment, VT_BYTE, "(width)" );
    variable_store( _environment, width->name, tilemap->mapWidth );
    Variable * height = NULL;
    if ( _layer ) {
        height = variable_temporary( _environment, VT_BYTE, "(height)" );
        variable_store( _environment, height->name, tilemap->mapHeight );
    }

    x = variable_retrieve_or_define( _environment, _x, VT_BYTE, 0 );
    y = variable_retrieve_or_define( _environment, _y, VT_BYTE, 0 );
    if ( _layer ) {
        layer = variable_retrieve_or_define( _environment, _layer, VT_BYTE, 0 );
    }

    Variable * mul = variable_mul( _environment, width->name, y->name );
    Variable * offset = variable_add( _environment, mul->name, x->name );
    if ( layer ) {
        Variable * mul2 = variable_mul( _environment, width->name, height->name );
        Variable * mul3 = variable_mul( _environment, mul2->name, layer->name );
        variable_move( _environment, variable_add( _environment, mul3->name, offset->name )->name, offset->name );
    }
    cpu_move_8bit_indirect2_16bit( _environment, tilemap->realName, offset->realName, frame->realName );

    return frame;

}

