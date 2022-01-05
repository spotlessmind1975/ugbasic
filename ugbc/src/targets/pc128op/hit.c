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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit ASM code for <b>= HIT([int]x)</b>
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with a tile. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable. This function
 * is used when a direct integer is used.
 * 
 * @param _environment Current calling environment
 * @param _sprite Integer with the bitmask of the sprites
 * @return Variable* Temporary variable with the result of hit (0 = no 
 *                      hit, 1 = hit occurred)
 */
/* <usermanual>
@keyword HIT

@target pc128op
</usermanual> */
Variable * hit_to( Environment * _environment, int _sprite ) {

    FUNCTION_STUB( VT_BYTE )

}

/**
 * @brief Emit ASM code for <b>= HIT([expression])</b>
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a hit with another sprite. The result (0 = no collision, 1 = 
 * collision occurred) is returned in the output variable. This function
 * is used when an expression is used.
 * 
 * @param _environment Current calling environment
 * @param _sprite Expression with the bitmask of the sprites
 * @return Variable* Temporary variable with the result of hit (0 = no 
 *                      hit, 1 = hit occurred)
 */
/* <usermanual>
@keyword HIT
</usermanual> */
Variable * hit_to_vars( Environment * _environment, char * _sprite ) {

    FUNCTION_STUB( VT_BYTE )

}

