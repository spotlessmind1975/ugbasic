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
 * @brief Emit ASM code for <b>SPRITE [int] DATA FROM [int]</b>
 * 
 * This function emits a code capable of setting the starting address of the 
 * sprite _sprite to the value _address. This version is suitable when direct 
 * value is used.
 * 
 * @param _environment Current calling environment
 * @param _sprite Index of the sprite to define (0...7)
 * @param _address Address where the sprite data begins from
 */
void sprite_data_from( Environment * _environment, int _sprite, int _address ) {

    outline2("; SPRITE %d DATA FROM $%4.4x (ignored)", _sprite, _address);

}

/**
 * @brief Emit ASM code for <b>SPRITE [expression] DATA FROM [expression]</b>
 * 
 * This function emits a code capable of setting the starting address of the 
 * sprite _sprite to the value _address. This version is suitable when expressions
 * are used.
 * 
 * @param _environment Current calling environment
 * @param _sprite Expression with the index of the sprite to define (0...7)
 * @param _address Expression with the address where the sprite data begins from
 */
void sprite_data_from_vars( Environment * _environment, char * _sprite, char * _address ) {

    outline2("; SPRITE %s DATA FROM %s (ignored)", _sprite, _address);

}

/**
 * @brief Emit ASM code for <b>SPRITE [int] ENABLE</b>
 * 
 * This function emits a code capable of enable the sprite _sprite.
 * This version is suitable when direct integer are used.
 * 
 * @param _environment Current calling environment
 * @param _sprite Index of the sprite to enable (0...7)
 */
void sprite_enable( Environment * _environment, int _sprite ) {

    outline1("; SPRITE %d ENABLE (ignored)", _sprite);

}

/**
 * @brief Emit ASM code for <b>SPRITE [expression] ENABLE</b>
 * 
 * This function emits a code capable of enable the sprite _sprite.
 * This version is suitable when an expression is used. 
 * 
 * @param _environment Current calling environment
 * @param _sprite Expression with the index of the sprite to enable (0...7)
 */
void sprite_enable_var( Environment * _environment, char * _sprite ) {

    outline1("; SPRITE %s ENABLE (ignored)", _sprite);

}

/**
 * @brief Emit ASM code for <b>SPRITE [int] DISABLE</b>
 * 
 * This function emits a code capable of disable the sprite _sprite.
 * This version is suitable when direct integer are used.
 * 
 * @param _environment Current calling environment
 * @param _sprite Index of the sprite to disable (0...7)
 */
void sprite_disable( Environment * _environment, int _sprite ) {

    outline1("; SPRITE %d DISABLE (ignored)", _sprite);

}

/**
 * @brief Emit ASM code for <b>SPRITE [expression] DISABLE</b>
 * 
 * This function emits a code capable of disable the sprite _sprite.
 * This version is suitable when an expression is used. 
 * 
 * @param _environment Current calling environment
 * @param _sprite Expression with the index of the sprite to disable (0...7)
 */
void sprite_disable_var( Environment * _environment, char * _sprite ) {

    outline1("; SPRITE %s DISABLE (ignored)", _sprite);

}

/**
 * @brief Emit ASM code for <b>SPRITE [int] AT ([int],[int])</b>
 * 
 * This function emits a code capable of position a sprite to the (x,y)
 * on the screen. This version is suitable when an integer number 
 * is used. 
 * 
 * @param _environment Current calling environment
 * @param _sprite Index of the sprite to position (0...7)
 * @param _x The abscissa of the sprite
 * @param _y The ordinate of the sprite
 */
void sprite_position( Environment * _environment, int _sprite, int _x, int _y ) {

    outline3("; SPRITE %d AT (%d,%d) (ignored)", _sprite, _x, _y);

}

/**
 * @brief Emit ASM code for <b>SPRITE [expression] AT ([expression],[expression])</b>
 * 
 * This function emits a code capable of position a sprite to the (x,y)
 * on the screen. This version is suitable when an expression
 * is used. 
 * 
 * @param _environment Current calling environment
 * @param _sprite Expression with the index of the sprite to position (0...7)
 * @param _x Expression with the abscissa of the sprite
 * @param _y Expression with the ordinate of the sprite
 */
void sprite_position_vars( Environment * _environment, char * _sprite, char * _x, char * _y ) {

    outline3("; SPRITE %s AT (%s,%s) (ignored)", _sprite, _x, _y);

}

/**
 * @brief Emit ASM code for <b>SPRITE [int] EXPAND VERTICAL</b>
 * 
 * This function emits a code capable of expanding vertically a given sprite.
 * The index of sprite is given as a direct integer.
 * 
 * @param _environment Current calling environment
 * @param _sprite Index of the sprite to expand vertically (0...7)
 */
void sprite_expand_vertical( Environment * _environment, int _sprite ) {

    outline1("; SPRITE %d EXPAND VERTICAL (ignored)", _sprite);

}

/**
 * @brief Emit ASM code for <b>SPRITE [expression] EXPAND VERTICAL</b>
 * 
 * This function emits a code capable of expanding vertically a given sprite.
 * The index of sprite is given as an expression.
 * 
 * @param _environment Current calling environment
 * @param _sprite Expression with the index of the sprite to expand vertically (0...7)
 */
void sprite_expand_vertical_var( Environment * _environment, char * _sprite ) {

    outline1("; SPRITE %s EXPAND VERTICAL (ignored)", _sprite);

}

/**
 * @brief Emit ASM code for <b>SPRITE [int] CPMPRESS VERTICAL</b>
 * 
 * This function emits a code capable of compressing vertically a given sprite.
 * The index of sprite is given as a direct integer.
 * 
 * @param _environment Current calling environment
 * @param _sprite Index of the sprite to compress vertically (0...7)
 */
void sprite_compress_vertical( Environment * _environment, int _sprite ) {

    outline1("; SPRITE %d COMPRESS VERTICAL (ignored)", _sprite);

}

/**
 * @brief Emit ASM code for <b>SPRITE [expression] COMPRESS VERTICAL</b>
 * 
 * This function emits a code capable of compressing vertically a given sprite.
 * The index of sprite is given as an expression.
 * 
 * @param _environment Current calling environment
 * @param _sprite Expression with the index of the sprite to compress vertically (0...7)
 */
void sprite_compress_vertical_var( Environment * _environment, char * _sprite ) {

    outline1("; SPRITE %s COMPRESS VERTICAL (ignored)", _sprite);

}

/**
 * @brief Emit ASM code for <b>SPRITE [int] EXPAND HORIZONTAL</b>
 * 
 * This function emits a code capable of expanding horizontally a given sprite.
 * The index of sprite is given as a direct integer.
 * 
 * @param _environment Current calling environment
 * @param _sprite Index of the sprite to expand horizontally (0...7)
 */
void sprite_expand_horizontal( Environment * _environment, int _sprite ) {

    outline1("; SPRITE %d EXPAND HORIZONTAL (ignored)", _sprite);

}

/**
 * @brief Emit ASM code for <b>SPRITE [expression] EXPAND HORIZONTAL</b>
 * 
 * This function emits a code capable of expanding horizontally a given sprite.
 * The index of sprite is given as an expression.
 * 
 * @param _environment Current calling environment
 * @param _sprite Expression with the index of the sprite to expand horizontally (0...7)
 */
void sprite_expand_horizontal_var( Environment * _environment, char * _sprite ) {

    outline1("; SPRITE %s EXPAND HORIZONTAL (ignored)", _sprite);

}

/**
 * @brief Emit ASM code for <b>SPRITE [int] COMPRESS HORIZONTAL</b>
 * 
 * This function emits a code capable of compressing horizontally a given sprite.
 * The index of sprite is given as a direct integer.
 * 
 * @param _environment Current calling environment
 * @param _sprite Index of the sprite to compress horizontally (0...7)
 */
void sprite_compress_horizontal( Environment * _environment, int _sprite ) {
    
    outline1("; SPRITE %d COMPRESS HORIZONTAL (ignored)", _sprite);

}

/**
 * @brief Emit ASM code for <b>SPRITE [int] COMPRESS HORIZONTAL</b>
 * 
 * This function emits a code capable of compressing horizontally a given sprite.
 * The index of sprite is given as a direct integer.
 * 
 * @param _environment Current calling environment
 * @param _sprite Index of the sprite to compress horizontally (0...7)
 */
void sprite_compress_horizontal_var( Environment * _environment, char * _sprite ) {

    outline1("; SPRITE %s COMPRESS HORIZONTAL (ignored)", _sprite);

}

/**
 * @brief Emit ASM code for <b>SPRITE [int] MULTICOLOR</b>
 * 
 * This function emits a code capable of enabling multicolor for a given sprite.
 * The index of sprite is given as a direct integer.
 * 
 * @param _environment Current calling environment
 * @param _sprite Index of the sprite for which enable multicolor (0...7)
 */
void sprite_multicolor( Environment * _environment, int _sprite ) {

    outline1("; SPRITE %d MULTICOLOR (ignored)", _sprite);

}

/**
 * @brief Emit ASM code for <b>SPRITE [expression] MULTICOLOR</b>
 * 
 * This function emits a code capable of enabling multicolor for a given sprite.
 * The index of sprite is given as an expression.
 * 
 * @param _environment Current calling environment
 * @param _sprite Expression with index of the sprite for which enable multicolor (0...7)
 */
void sprite_multicolor_var( Environment * _environment, char * _sprite ) {

    outline1("; SPRITE %s MULTICOLOR (ignored)", _sprite);

}

/**
 * @brief Emit ASM code for <b>SPRITE [int] MONOCOLOR</b>
 * 
 * This function emits a code capable of enabling monocolor for a given sprite.
 * The index of sprite is given as direct integer.
 * 
 * @param _environment Current calling environment
 * @param _sprite Index of the sprite for which enable monocolor (0...7)
 */
void sprite_monocolor( Environment * _environment, int _sprite ) {

    outline1("; SPRITE %d MONOCOLOR (ignored)", _sprite);

}

/**
 * @brief Emit ASM code for <b>SPRITE [expression] MONOCOLOR</b>
 * 
 * This function emits a code capable of enabling monocolor for a given sprite.
 * The index of sprite is given as expression.
 * 
 * @param _environment Current calling environment
 * @param _sprite Expression with index of the sprite for which enable monocolor (0...7)
 */
void sprite_monocolor_var( Environment * _environment, char * _sprite ) {

    outline1("; SPRITE %s MULTICOLOR (ignored)", _sprite);

}

/**
 * @brief Emit ASM code for instruction <b>SPRITE [int] COLOR [int]</b>
 * 
 * This function emits a code capable of changing the specific color
 * for a given sprite.
 * 
 * @param _environment Current calling environment
 * @param _sprite Index of the sprite for which to change color
 * @param _color Index of the color
 */
void sprite_color( Environment * _environment, int _sprite, int _color ) {

    outline2("; COLOR SPRITE %d TO %2.2x (ignored)", _sprite, _color);

}

/**
 * @brief Emit ASM code for instruction <b>SPRITE [int] COLOR [int]</b>
 * 
 * This function emits a code capable of changing the specific color
 * for a given sprite.
 * 
 * @param _environment Current calling environment
 * @param _sprite Expression with the index of the sprite for which to change color
 * @param _color Expression with the index of the color
 */
void sprite_color_vars( Environment * _environment, char * _sprite, char * _color ) {

    outline2("; COLOR SPRITE %s TO %s (ignored)", _sprite, _color);

}