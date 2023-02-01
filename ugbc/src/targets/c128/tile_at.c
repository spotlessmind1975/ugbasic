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

/**
 * @brief Emit code for <strong>TILE AT</strong>
 * 
 * @param _environment Current calling environment
 * @param _x tile abscissa
 * @param _y tile ordinate
 * @return The tile present in that position
 */
/* <usermanual>
@keyword TILE AT

@english
This function allows you to know which is the tile drawn at a certain position
on the tilemap. Since it is possible to draw both single ''TILE'' and ''TILES'', 
the information on the drawn tile is not, automatically, the identifier of a 
TILES but it is the single tile of which it is formed. To know if the tile belongs to a
group of tiles it is necessary to use the ''TILES BELONG'' function.

@italian
Questa funzione permette di conoscere qual è il tile disegnato a una certa posizione 
sulla tilemap. Siccome è possibile disegnare sia singoli ''TILE'' che ''TILES'', 
l'informazione sul tile disegnato non è, automaticamente, l'identificatore di un 
''TILES'' ma è il singolo tile di cui è formato. Per sapere se il tile appartiene 
a un gruppo di tiles è necessario utilizzare la funzione ''TILES BELONG''.

@syntax = TILE AT([x],[y])

@example tile = TILE AT( 10,10 )

@target c128
</usermanual> */
Variable * tile_at( Environment * _environment, char * _x, char * _y ) {

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    Variable * result = variable_temporary( _environment, VT_TILE, "(tileAt)");
    
    vic2_tile_at( _environment, x->realName, y->realName, result->realName );

    return result;

}


