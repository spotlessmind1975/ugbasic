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
given the coordinates of the tile itself.

@italian
Questa funzione permette di conoscere quale sia il tile di una mappa, 
date le coordinate del tile stesso.

@syntax = TILEMAP map AT([x],[y])

@example tile = TILEMAP map AT(0,0)

@target all
</usermanual> */
Variable * tilemap_at( Environment * _environment, char * _tilemap, char * _x, char * _y ) {

    Variable * tilemap = NULL;
    Variable * x = NULL;
    Variable * y = NULL;
    Variable * frame = variable_temporary( _environment, VT_BYTE, "(frame)" );

    tilemap = variable_retrieve( _environment, _tilemap );
    if ( tilemap->type != VT_TILEMAP ) {
        CRITICAL_TILEMAP_HEIGHT_NO_TILEMAP( _tilemap );
    }

    Variable * width = variable_temporary( _environment, VT_BYTE, "(height)" );
    variable_store( _environment, width->name, tilemap->mapWidth );

    x = variable_retrieve_or_define( _environment, _x, VT_WORD, 0 );
    y = variable_retrieve_or_define( _environment, _y, VT_WORD, 0 );

    Variable * offset = variable_add( _environment, variable_mul( _environment, width->name, y->name )->name, x->name );

    cpu_move_8bit_indirect2_16bit( _environment, tilemap->realName, offset->realName, frame->realName );

    return frame;

}

