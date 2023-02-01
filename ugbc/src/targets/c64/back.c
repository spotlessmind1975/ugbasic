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

/**
 * @brief Emit ASM code to fill background color
 * 
 * This function can be called to fill the screen background with the given
 * color. Depending on the mode selected (TILEMAP vs BITMAP) it can fill
 * the screen in a different way.
 * 
 * @param _environment Current calling environment
 * @param _color Index of color to use to fill the screen
 */
/* <usermanual>
@keyword COLOR BACK

@english
Fills the screen with the indicated color. The modified color is the background color,
which is set as if the ''PAPER'' command had been issued. Depending on the active mode 
(''TILEMAP'' or ''BITMAP'') the behavior of the filling can be different, depending 
on the target computer.

@italian
Riempie lo schermo con il colore indicato. Il colore modificato è quello di sfondo, che
viene impostato come se si fosse dato il comando ''PAPER''. A seconda della modalità attiva
(''TILEMAP'' o ''BITMAP'') il comportamento del riempimento può essere diverso, 
a seconda del computer target.

@syntax COLOR BACK [color]

@example COLOR BACK RED
@example COLOR BACK WHITE

@seeAlso COLOR BACKGROUND
@usedInExample graphics_color_01.bas

@target c64

</usermanual> */
void back( Environment * _environment, char * _color ) {

    paper( _environment, _color );

    vic2_back( _environment );

}
