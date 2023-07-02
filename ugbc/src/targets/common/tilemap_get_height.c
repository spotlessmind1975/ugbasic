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
@keyword TILEMAP HEIGHT

@english
This function allows you to obtain the height of a given ''TILEMAP''. The height
is expressed in tiles

@italian
Questa funzione permette di ottenere l'altezza di una mappa di tile (''TILEMAP''). 
L'altezza è espressa in tessere.

@syntax = TILEMAP HEIGHT([tilemap])

@example starshipHeight = TILEMAP HEIGHT( tilemap )

@target all
</usermanual> */
Variable * tilemap_get_height( Environment * _environment, char * _tilemap ) {

    Variable * tilemap = NULL;

    tilemap = variable_retrieve( _environment, _tilemap );
    if ( tilemap->type != VT_TILEMAP ) {
        CRITICAL_TILEMAP_HEIGHT_NO_TILEMAP( _tilemap );
    }

    Variable * height = variable_temporary( _environment, VT_BYTE, "(height)");

    variable_store( _environment, height->name, tilemap->mapHeight );

    return height;

}

