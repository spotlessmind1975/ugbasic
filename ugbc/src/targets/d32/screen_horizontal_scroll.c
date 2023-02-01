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
 * @brief Emit ASM code for <b>SCREEN HORIZONTAL SCROLL [int]x</b>
 * 
 * This function outputs an assembly code capable of performing a 
 * hardware scroll of the screen. The scroll is always in the direction 
 * from right to left, so with a _displacement of 0 the screen is exactly as 
 * it would be without scrolling while with the value 7 you would have a scroll
 * of 7 pixels to left. This version is used when a direct integer is used.
 * 
 * @param _environment Current calling environment
 * @param _displacement Horizontal offset in pixels (0-7)
 */
/* <usermanual>
@keyword SCREEN HORIZONTAL SCROLL

@target d32
</usermanual> */
void screen_horizontal_scroll( Environment * _environment, int _displacement ) {

    

    char displacementString[MAX_TEMPORARY_STORAGE]; sprintf( displacementString, "#$%2.2x", _displacement );

    c6847_horizontal_scroll( _environment, displacementString );

}

/**
 * @brief Emit ASM code for <b>SCREEN HORIZONTAL SCROLL [expression[</b>
 * 
 * This function outputs an assembly code capable of performing a 
 * hardware scroll of the screen. The scroll is always in the direction 
 * from right to left, so with a _displacement of 0 the screen is exactly as 
 * it would be without scrolling while with the value 7 you would have a scroll
 * of 7 pixels to left. This version is used when an expression is used.
 * 
 * @param _environment Current calling environment
 * @param _displacement Horizontal offset in pixels (0-7)
 */
/* <usermanual>
@keyword SCREEN HORIZONTAL SCROLL
</usermanual> */
void screen_horizontal_scroll_var( Environment * _environment, char * _displacement ) {

    

    Variable * displacement = variable_retrieve( _environment, _displacement );

    c6847_horizontal_scroll( _environment, _displacement );

}
