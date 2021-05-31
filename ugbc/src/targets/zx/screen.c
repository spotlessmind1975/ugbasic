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
void screen_off( Environment * _environment ) {

    outline0("; SCREEN OFF (ignored)");

}

/**
 * @brief Emit ASM code for <b>SCREEN ON</b>
 * 
 * This function outputs assembly code to turn on the screen.
 * 
 * @param _environment Current calling environment
 */
void screen_on( Environment * _environment ) {

    outline0("; SCREEN ON (ignored)");

}

/**
 * @brief Emit ASM code for <b>SCREEN ROWS [int]x</b>
 * 
 * This function changes the number of lines that can be displayed. 
 * Depending on the hardware, the effect can be different as different 
 * are the acceptable values. This version is the one called when an 
 * integer number of lines is given in the program.
 * 
 * @param _environment Current calling environment
 * @param _rows Number of rows
 */
void screen_rows( Environment * _environment, int _rows ) {

    outline1("; SCREEN ROWS %d (ignored)", _rows);

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
void screen_rows_var( Environment * _environment, char * _rows ) {

    outline1("; SCREEN ROWS %s (ignored)", _rows);

}

/**
 * @brief Emit ASM code for <b>SCREEN VERTICAL SCROLL [int]x</b>
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
void screen_vertical_scroll( Environment * _environment, int _displacement ) {

    outline1("; SCREEN VERTICAL SCROLL %d (ignored)", _displacement);

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
void screen_vertical_scroll_var( Environment * _environment, char * _displacement ) {

    outline1("; SCREEN VERTICAL SCROLL %s (ignored)", _displacement );

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
void screen_horizontal_scroll( Environment * _environment, int _displacement ) {

    outline1("; SCREEN HORIZONTAL SCROLL %d (ignored)", _displacement);

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
void screen_horizontal_scroll_var( Environment * _environment, char * _displacement ) {

    outline1("; SCREEN HORIZONTAL SCROLL %s (ignored)", _displacement);
   
}

Variable * screen_get_width( Environment * _environment ) {

    MAKE_LABEL

    Variable * width = variable_temporary( _environment, VT_POSITION, "(result of get width)");

    Variable * bitmap_enabled = variable_retrieve( _environment, "bitmap_enabled" );

    char bitmapEnabledLabel[MAX_TEMPORARY_STORAGE]; sprintf(bitmapEnabledLabel, "%senabled", label );
    char endLabel[MAX_TEMPORARY_STORAGE]; sprintf(endLabel, "%send", label );

    cpu_bvneq( _environment, bitmap_enabled->realName, bitmapEnabledLabel );
    
    variable_store( _environment, width->name, 32 );

    cpu_jump( _environment, endLabel );

    cpu_label( _environment, bitmapEnabledLabel );

    variable_store( _environment, width->name, 256 );

    cpu_label( _environment, endLabel );

    return width;

}

Variable * screen_get_height( Environment * _environment ) {

    MAKE_LABEL

    Variable * height = variable_temporary( _environment, VT_POSITION, "(result of get height)");

    variable_store( _environment, height->name, 192 );
   
    Variable * bitmap_enabled = variable_retrieve( _environment, "bitmap_enabled" );

    char bitmapEnabledLabel[MAX_TEMPORARY_STORAGE]; sprintf(bitmapEnabledLabel, "%senabled", label );
    char endLabel[MAX_TEMPORARY_STORAGE]; sprintf(endLabel, "%send", label );

    cpu_bvneq( _environment, bitmap_enabled->realName, bitmapEnabledLabel );
    
    variable_store( _environment, height->name, 20 );

    cpu_jump( _environment, endLabel );

    cpu_label( _environment, bitmapEnabledLabel );

    variable_store( _environment, height->name, 192 );

    cpu_label( _environment, endLabel );

    return height;

}

void paper( Environment * _environment, char * _color ) {

    Variable * paper = variable_retrieve( _environment, "PAPER" );
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_BLACK );

    variable_move( _environment, color->name, paper->name );
    
    zx_color_border( _environment, color->realName );
    
}
