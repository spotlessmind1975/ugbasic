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

@target mo5
</usermanual> */
void colormap_clear_with( Environment * _environment, int _foreground, int _background ) {

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
</usermanual> */
void colormap_clear_with_vars( Environment * _environment, char * _foreground, char * _background ) {

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
</usermanual> */
void colormap_clear( Environment * _environment ) {

}