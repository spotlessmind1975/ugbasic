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
 * @brief Emit code for <strong>USE TILESET xxx</strong>
 * 
 * @param _environment Current calling environment
 * @param _tileset tileset to use
 */
/* <usermanual>
@keyword USE TILESET

@english
The ''USE TILESET'' command allows you to change the current active tileset.

@italian
Il comando ''USE TILESET'' permette di cambiare il tileset attivo.

@syntax USE TILESET tileset

@example USE TILESET schema1

@target atari
</usermanual> */
void use_tileset( Environment * _environment, char * _tileset ) {

    Variable * tileset = variable_retrieve( _environment, _tileset );
    if ( tileset->type != VT_TILESET ) {
        CRITICAL_USE_TILESET_ON_NON_TILESET( _tileset );
    }
    if ( ! _environment->tilesets[tileset->value] ) {
        CRITICAL_USE_TILESET_ON_NON_TILESET( _tileset );
    }

    tms9918_use_tileset( _environment, tileset->realName );

}
