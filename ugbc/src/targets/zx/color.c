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

/**
 * @brief Emit ASM code for instruction <b>COLOR BORDER [int]x</b>
 * 
 * This function outputs the ASM code to change the border color, where 
 * the command is invoked with a direct integer value.
 * 
 * @param _environment Current calling environment
 * @param _color Index color to use.
 */
/* <usermanual>
@keyword COLOR BORDER

@target zx
</usermanual> */
void color_border( Environment * _environment, int _color ) {
    
    outline1("; COLOR BORDER %2.2x", _color);

    char port[16]; sprintf(port, "$%2.2x", PORT_COLOR_BORDER);
    char color[16]; sprintf(color, "$%2.2x", _color);

    z80_port_out( _environment, port, color );

}

/**
 * @brief Emit ASM code for instruction <b>COLOR BORDER [expression]</b>
 * 
 * This function outputs the ASM code to change the border color, where 
 * the command is invoked with an expression.
 * 
 * @param _environment Current calling environment
 * @param _color Variable with the expression.
 */
void color_border_var( Environment * _environment, char * _color ) {

    outline1("; COLOR BORDER %s", _color);

    // Safety check -- expression must exists (it should be always true)
    Variable * color = variable_retrieve( _environment, _color );
    if ( ! color ) {
        CRITICAL("Internal error on COLOR BORDER");
    }

    char port[16]; sprintf(port, "$%2.2x", PORT_COLOR_BORDER);

    z80_port_out( _environment, port, color->realName );

}

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
    
    outline2("; COLOR BACKGROUND $%2.2x TO $%2.2x (ignored)", _index, _background_color);

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

    outline2("; COLOR BACKGROUND %s TO %s (ignored)", _index, _background_color);

}

/**
 * @brief Emit ASM code for instruction <b>COLOR SPRITE [int]x TO [int]x</b>
 * 
 * This function outputs the ASM code to change the common sprite color, among 
 * those available. It should be used where the command is invoked with integers.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the common color to set
 * @param _common_color Index of the color to use
 */
void color_sprite( Environment * _environment, int _index, int _common_color ) {

    outline2("; COLOR SPRITE $%2.2x TO $%2.2x (ignore)", _index, _common_color);

}

/**
 * @brief Emit ASM code for instruction <b>COLOR SPRITE [expression] TO [expression]</b>
 * 
 * This function outputs the ASM code to change the common sprite color, among 
 * those available. It should be used where the command is invoked with expressions.
 * 
 * @param _environment Current calling environment
 * @param _index Expression with the index of common color to set
 * @param _common_color Expression with the index of the color to use
 */
void color_sprite_vars( Environment * _environment, char * _index, char * _common_color ) {

    outline2("; COLOR SPRITE %s TO %s (ignore)", _index, _common_color);

}