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
 * @brief Emit ASM implementation for <b>COLORMAP CLEAR WITH [int] ON [int]</b> instruction
 * 
 * This function is called when you want to generate code that erases the entire color map, 
 * using a foreground and a background color. This function is useful if the color indices 
 * are given as integers.
 * 
 * @pre Bitmap must be enabled at least once with instruction <b>BITMAP ENABLE</b>.
 * 
 * @param _environment Current calling environment
 * @param _foreground Index of foreground color
 * @param _background Index of background color
 * @throw EXIT_FAILURE "COLORMAP CLEAR WITH xxx ON xxx needs BITMAP ENABLED"
 */
/* <usermanual>
@keyword COLORMAP CLEAR

@english
Erase the entire color map, using a foreground and a background color.

@italian
Cancella l'intera mappa dei colori, utilizzando un colore di primo piano 
e uno di sfondo.

@syntax COLORMAP CLEAR WITH # [integer] ON # [integer]

@example COLORMAP CLEAR WITH #$0 ON #$1

@seeAlso BITMAP ENABLE

@target c128
</usermanual> */
void colormap_clear_with( Environment * _environment, int _foreground, int _background ) {

    

    Variable * colormapAddress = variable_retrieve_or_define( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0x8400 );

    char value[MAX_TEMPORARY_STORAGE]; sprintf(value, "#$%2.2x", ( ( _foreground & 0x0f ) << 4 ) | ( _background & 0x0f ));
    
    cpu_fill_blocks( _environment, colormapAddress->realName, "#$04", value );

}

/**
 * @brief Emit ASM implementation for <b>COLORMAP CLEAR WITH [expression] ON [expression]</b> instruction
 * 
 * This function is called when you want to generate code that erases the entire color map, 
 * using a foreground and a background color. This function is useful if the color indices 
 * are given as integers.
 * 
 * @pre Bitmap must be enabled at least once with instruction <b>BITMAP ENABLE</b>.
 * 
 * @param _environment Current calling environment
 * @param _foreground Expression for index of foreground color
 * @param _background Expression for index of background color
 * @throw EXIT_FAILURE "CRITICAL: COLORMAP CLEAR WITH xxx AND xxx needs BITMAP ENABLED"
 */
/* <usermanual>
@keyword COLORMAP CLEAR

@syntax COLORMAP CLEAR WITH [expression] ON [expression]

@example COLORMAP CLEAR WITH YELLOW ON RED
</usermanual> */
void colormap_clear_with_vars( Environment * _environment, char * _foreground, char * _background ) {

    

    Variable * colormapAddress = variable_retrieve_or_define( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0x8400 );
    if ( ! colormapAddress ) {
        CRITICAL( "COLORMAP CLEAR WITH xxx ON xxx needs BITMAP ENABLED");
    }

    Variable * foreground = variable_retrieve( _environment, _foreground );

    Variable * background = variable_retrieve( _environment, _background );

    cpu6502_combine_nibbles( _environment, background->realName, foreground->realName, "$24" );

    cpu_fill_blocks( _environment, colormapAddress->realName, "#$04", "$24" );

}

/**
 * @brief Emit ASM implementation for <b>COLORMAP CLEAR</b> instruction
 * 
 * This function is called when you want to generate code that erases the entire color map, 
 * using the default foreground and background color.
 * 
 * @pre Bitmap must be enabled at least once with instruction <b>BITMAP ENABLE</b>.
 * 
 * @param _environment Current calling environment
 * @throw EXIT_FAILURE "CRITICAL: COLORMAP CLEAR WITH xxx AND xxx needs BITMAP ENABLED"
 */
/* <usermanual>
@keyword COLORMAP CLEAR

@syntax COLORMAP CLEAR

@example COLORMAP CLEAR
</usermanual> */
void colormap_clear( Environment * _environment ) {

    // Equals to: "COLORMAP CLEAR WITH 0 AND 1"
    colormap_clear_with( _environment, COLOR_WHITE, COLOR_BLACK );

}