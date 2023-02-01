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
 * @brief Emit code for <strong>TILE HEIGHT(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _image Image to measure.
 * @return The height of the image, in pixels
 */
/* <usermanual>
@keyword TILE HEIGHT

@target cpc
</usermanual> */
Variable * tile_get_height( Environment * _environment, char * _tile ) {

    Variable * tile = variable_retrieve( _environment, _tile );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(tile height)" );

    if ( tile->type == VT_TILE ) {
        cpu_store_8bit( _environment, result->realName, 1 );
    } else if ( tile->type == VT_TILES ) {
        outline1("LD A, (%s+2)", tile->realName );
        outline1("LD (%s), A", result->realName );
    } else {
        CRITICAL_NOT_TILE( _tile );
    }

    return result;

}
