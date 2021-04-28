/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit ASM code for <b>SCREEN OFF</b>
 * 
 * This function outputs assembly code to turn off the screen.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword SCREEN OFF

@english
Turn off the screen.

@italian
Spegni lo schermo.

@syntax SCREEN OFF

@example SCREEN OFF

@target c64
</usermanual> */
void screen_off( Environment * _environment ) {

    outline0("; SCREEN OFF");

    vic2_screen_off( _environment );

}

/**
 * @brief Emit ASM code for <b>SCREEN ON</b>
 * 
 * This function outputs assembly code to turn on the screen.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword SCREEN ON

@english
Turn on the screen.

@italian
Riaccendi lo schermo.

@syntax SCREEN ON

@example SCREEN ON

@target c64
</usermanual> */
void screen_on( Environment * _environment ) {

    outline0("; SCREEN ON");

    vic2_screen_on( _environment );

}

/**
 * @brief Emit ASM code for <b>SCREEN ROWS [integer]</b>
 * 
 * This function changes the number of lines that can be displayed. 
 * Depending on the hardware, the effect can be different as different 
 * are the acceptable values. This version is the one called when an 
 * integer number of lines is given in the program.
 * 
 * @param _environment Current calling environment
 * @param _rows Number of rows
 */
/* <usermanual>
@keyword SCREEN ROWS

@english
Changes the number of lines that can be displayed. Depending 
on the hardware, the effect can be different as different 
are the acceptable values.

@italian
Modifica il numero di righe che possono essere visualizzate. A seconda
dell'hardware, l'effetto può essere diverso come diversi sono i valori 
accettabili.

@syntax SCREEN ROWS [integer]

@example SCREEN ROWS 24

@target c64
</usermanual> */
void screen_rows( Environment * _environment, int _rows ) {

    outline1("; SCREEN ROWS %d", _rows);

    char rowsString[16]; sprintf( rowsString, "#$%2.2x", _rows );

    vic2_screen_rows( _environment, rowsString );

}

/**
 * @brief Emit ASM code for <b>SCREEN ROWS [int]x</b>
 * 
 * This function changes the number of lines that can be displayed. 
 * Depending on the hardware, the effect can be different as different 
 * are the acceptable values. This version is the one called when an 
 * expression is given in the program.
 * 
 * @param _environment Current calling environment
 * @param _rows Number of rows
 */
/* <usermanual>
@keyword SCREEN ROWS

@syntax SCREEN ROWS [expression]

@example SCREEN ROWS newRows
</usermanual> */
void screen_rows_var( Environment * _environment, char * _rows ) {

    outline1("; SCREEN ROWS %s", _rows);

    Variable * rows = variable_retrieve( _environment, _rows );
    vic2_screen_rows( _environment, rows->realName );

}

/**
 * @brief Emit ASM code for <b>SCREEN VERTICAL SCROLL [integer]</b>
 * 
 * This function outputs an assembly code capable of performing a 
 * hardware scroll of the screen. The scroll is always in the direction 
 * from bottom to up, so with a _displacement of 0 the screen is exactly as 
 * it would be without scrolling while with the value 7 you would have a scroll
 * of 7 pixels upwards. This version is used when a direct integer is used.
 * 
 * @param _environment Current calling environment
 * @param _displacement Vertical offset in pixels (0-7)
 */
/* <usermanual>
@keyword SCREEN VERTICAL SCROLL

@english
Performs an hardware scroll of the screen. The scroll is always in 
the direction from bottom to up, so with a displacement of 0 the 
screen is exactly as it would be without scrolling while with the 
value 7 you would have a scroll of 7 pixels upwards.

@italian
Esegue uno scorrimento hardware dello schermo. Lo scorrimento è sempre
dal basso verso l'alto, quindi con uno spostamento di 0 lo schermo è 
esattamente come sarebbe senza scrolling, mentre con il valore 7 
si avrebbe uno scroll di 7 pixel verso l'alto.

@syntax SCREEN VERTICAL SCROLL [integer]

@example SCREEN VERTICAL SCROLL 3

@target c64
</usermanual> */
void screen_vertical_scroll( Environment * _environment, int _displacement ) {

    outline1("; SCREEN VERTICAL SCROLL %d", _displacement);

    char displacementString[16]; sprintf( displacementString, "#$%2.2x", _displacement );

    vic2_vertical_scroll( _environment, displacementString );

}

/**
 * @brief Emit ASM code for <b>SCREEN VERTICAL SCROLL [expression]</b>
 * 
 * This function outputs an assembly code capable of performing a 
 * hardware scroll of the screen. The scroll is always in the direction 
 * from bottom to up, so with a _displacement of 0 the screen is exactly as 
 * it would be without scrolling while with the value 7 you would have a scroll
 * of 7 pixels upwards. This version is used when an expression is used.
 * 
 * @param _environment Current calling environment
 * @param _displacement Vertical offset in pixels (0-7)
 */
/* <usermanual>
@keyword SCREEN VERTICAL SCROLL

@syntax SCREEN VERTICAL SCROLL [expression]

@example SCREEN VERTICAL SCROLL newScrolling
</usermanual> */
void screen_vertical_scroll_var( Environment * _environment, char * _displacement ) {

    outline1("; SCREEN VERTICAL SCROLL %s", _displacement );

    Variable * displacement = variable_retrieve( _environment, _displacement );

    vic2_vertical_scroll( _environment, displacement->realName );

}

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

@english
Performs an hardware scroll of the screen. The scroll is always in 
the direction from right to left, so with a displacement of 0 the 
screen is exactly as it would be without scrolling while with the 
value 7 you would have a scroll of 7 pixels to the left.

@italian
Esegue uno scorrimento hardware dello schermo. Lo scorrimento è sempre
a destra a sinistra, quindi con uno spostamento di 0 lo schermo è 
esattamente come sarebbe senza scrolling, mentre con il valore 7 
si avrebbe uno scroll di 7 pixel verso sinistra.

@syntax SCREEN HORIZONTAL SCROLL [integer]

@example SCREEN HORIZONTAL SCROLL 3

@target c64
</usermanual> */
void screen_horizontal_scroll( Environment * _environment, int _displacement ) {

    outline1("; SCREEN HORIZONTAL SCROLL %d", _displacement);

    char displacementString[16]; sprintf( displacementString, "#$%2.2x", _displacement );

    vic2_horizontal_scroll( _environment, displacementString );

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

@syntax SCREEN HORIZONTAL SCROLL [expression]

@example SCREEN HORIZONTAL SCROLL newDisplacement
</usermanual> */
void screen_horizontal_scroll_var( Environment * _environment, char * _displacement ) {

    outline1("; SCREEN HORIZONTAL SCROLL %s", _displacement);

    Variable * displacement = variable_retrieve( _environment, _displacement );

    vic2_horizontal_scroll( _environment, _displacement );

}

