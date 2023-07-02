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
 * @brief Return the width of a TILEMAP
 * 
 * @param _environment Current calling environment
 * @param _tileset tileset
 */
/* <usermanual>
@keyword TILEMAP WIDTH

@english
This function allows you to obtain the width of a given ''TILEMAP''. The width
is expressed in tiles

@italian
Questa funzione permette di ottenere la larghezza di una mappa di tile (''TILEMAP''). 
La larghezza è espressa in tessere.

@syntax = TILEMAP WIDTH([tilemap])

@example w = TILEMAP WIDTH( tilemap )

@target all
</usermanual> */
Variable * tilemap_get_width( Environment * _environment, char * _tilemap ) {

    Variable * tilemap = NULL;

    tilemap = variable_retrieve( _environment, _tilemap );
    if ( tilemap->type != VT_TILEMAP ) {
        CRITICAL_TILEMAP_WIDTH_NO_TILEMAP( _tilemap );
    }

    Variable * width = variable_temporary( _environment, VT_BYTE, "(width)");

    variable_store( _environment, width->name, tilemap->mapWidth );

    return width;

}

