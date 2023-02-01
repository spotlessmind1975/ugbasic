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
 * @brief Emit ASM code for <b>DRAW TILE ROW [y], [x1] TO [x2], [color]</b>
 * 
 * This function outputs a code that draws a line of tiles on a tilemap. 
 * 
 * @param _environment Current calling environment
 * @param _image Image to draw
 * @param _x Abscissa of the point to draw
 * @param _y Ordinate of the point
 */
/* <usermanual>
@keyword PUT TILE
</usermanual> */
void draw_tile_column( Environment * _environment, char * _tile, char * _x, char * _y1, char * _y2, char * _color ) {

    Variable * tile = variable_retrieve( _environment, _tile );
    Variable * x = variable_retrieve_or_define( _environment, _x, VT_BYTE, 0 );
    Variable * y1 = variable_retrieve_or_define( _environment, _y1, VT_BYTE, 0 );
    Variable * y2 = variable_retrieve_or_define( _environment, _y2, VT_BYTE, 0 );
    if ( _color ) {
        pen( _environment, _color );
    }

    Variable * index = variable_temporary( _environment, VT_BYTE, "(index for)" );
    Variable * tileHeight = tile_get_height( _environment, tile->name );
    Variable * last = variable_sub( _environment, y2->name, tileHeight->name );

    begin_for_step( _environment, index->name, y1->name, last->name, tileHeight->name );
        put_tile( _environment, tile->name, x->name, index->name, NULL, NULL );
    end_for( _environment );

    Variable * residual = variable_sub( _environment, y2->name, index->name );
    
    put_tile( _environment, tile->name, x->name, y2->name, NULL, residual->name );

}