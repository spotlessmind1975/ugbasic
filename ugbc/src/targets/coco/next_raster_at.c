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
 * @brief Emit ASM code for <b>NEXT RASTER AT [int] WITH [label]</b>
 * 
 * This function outputs a code that puts the raster routine on hold for the 
 * vertical raster to arrive at a new _position with the execution of a different 
 * code from the previous one. This function is particularly useful when the 
 * position is communicated is given as an integer.
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _position The vertical position to wait for
 */
/* <usermanual>
@keyword NEXT RASTER AT

@target coco
</usermanual> */
void next_raster_at_with( Environment * _environment, int _position, char * _label ) {

}

/**
 * @brief Emit ASM code for <b>NEXT RASTER AT [expresssion] WITH label</b>
 * 
 * This function outputs a code that puts the raster routine on hold for the 
 * vertical raster to arrive at a new _position with the execution of a different 
 * code from the previous one. This function is particularly useful when the 
 * position is communicated is given as an expression.
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _position The vertical position to wait for
 */
/* <usermanual>
@keyword NEXT RASTER AT
</usermanual> */
void next_raster_at_with_var( Environment * _environment, char * _position, char * _label ) {

}
