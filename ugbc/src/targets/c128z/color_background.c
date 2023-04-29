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
 * @brief Emit ASM code for instruction <b>COLOR BACKGROUND [int] TO [int]x</b>
 * 
 * This function outputs the ASM code to change the background color, among 
 * those available. It should be used where the command is invoked with a 
 * direct integer value.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Index of the color to use
 */
void color_background( Environment * _environment, int _index, int _background_color ) {
    
}

/**
 * @brief Emit ASM code for instruction <b>COLOR BACKGROUND [expression] TO [expression]</b>
 * 
 * This function outputs the ASM code to change the background color, among 
 * those available. It should be used where the command is invoked with expressions.
 * 
 * @param _environment Current calling environment
 * @param _index Expression with the index of the background color
 * @param _background_color Expression with the index of the color to use
 */
void color_background_vars( Environment * _environment, char * _index, char * _background_color ) {

}
