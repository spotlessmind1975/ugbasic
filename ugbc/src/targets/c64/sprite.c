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
/* <usermanual>
    @keyword SPRITE DATA FROM
    
    @english
    Set the starting address of the sprite's graphical data.

    @italian
    Imposta l'indirizzo iniziale dei dati grafici dello sprite.

    @syntax SPRITE # [integer] DATA FROM # [integer]

    @example SPRITE #$1 DATA FROM #$0800

    @target c64

 </usermanual> */
void sprite_data_from( Environment * _environment, int _sprite, int _address ) {

    outline2("; SPRITE %d DATA FROM $%4.4x", _sprite, _address);

    char spriteString[16]; sprintf(spriteString, "#$%2.2x", _sprite );
    char addressString[16]; sprintf(addressString, "#$%2.2x", (unsigned char)( _address / 0x40 ) );

    vic2_sprite_data_from( _environment, spriteString, addressString );

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
/* <usermanual>
    @keyword SPRITE DATA FROM
    
    @syntax SPRITE [expression] DATA FROM [expression]

    @example SPRITE starship DATA FROM starshipGraphicalData

    @target c64

 </usermanual> */
void sprite_data_from_vars( Environment * _environment, char * _sprite, char * _address ) {

    outline2("; SPRITE %s DATA FROM %s", _sprite, _address);

    Variable * sprite = variable_retrieve( _environment, _sprite );
    if ( ! sprite ) {
        CRITICAL("Internal error on SPRITE [expression] DATA FROM [expression]");
    }

    Variable * address = variable_retrieve( _environment, _address );
    if ( ! address ) {
        CRITICAL("Internal error on SPRITE [expression] DATA FROM [expression]");
    }

    vic2_sprite_data_from( _environment, sprite->realName, address->realName );

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
/* <usermanual>
    @keyword SPRITE ENABLE
    
    @english
    Enable the sprite.

    @italian
    Abilita lo sprite.

    @syntax SPRITE # [integer] ENABLE

    @example SPRITE #1 ENABLE

    @target c64

 </usermanual> */
void sprite_enable( Environment * _environment, int _sprite ) {

    outline1("; SPRITE %d ENABLE", _sprite);

    char spriteString[16]; sprintf( spriteString, "#$%2.2x", _sprite );

    vic2_sprite_enable( _environment, spriteString );

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
/* <usermanual>
    @keyword SPRITE ENABLE
    
    @syntax SPRITE [expression] ENABLE

    @example SPRITE starship ENABLE

 </usermanual> */
void sprite_enable_var( Environment * _environment, char * _sprite ) {

    outline1("; SPRITE %s ENABLE", _sprite);

    Variable * sprite = variable_retrieve( _environment, _sprite );
    if ( ! sprite ) {
        CRITICAL("Internal error on SPRITE [expression] DATA FROM [expression]");
    }

    vic2_sprite_enable( _environment, sprite->realName );

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
/* <usermanual>
    @keyword SPRITE DISABLE
    
    @english
    Disable the sprite.

    @italian
    Disabilita lo sprite.

    @syntax SPRITE # [integer] DISABLE

    @example SPRITE #1 DISABLE

    @target c64

 </usermanual> */
void sprite_disable( Environment * _environment, int _sprite ) {

    outline1("; SPRITE %d DISABLE", _sprite);

    char spriteString[16]; sprintf( spriteString, "#$%2.2x", _sprite );

    vic2_sprite_disable( _environment, spriteString );

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
/* <usermanual>
    @keyword SPRITE DISABLE
    
    @syntax SPRITE [expression] DISABLE

    @example SPRITE starship DISABLE

 </usermanual> */
void sprite_disable_var( Environment * _environment, char * _sprite ) {

    _environment->bitmaskNeeded = 1;
    
    Variable * sprite = variable_retrieve( _environment, _sprite );
    if ( ! sprite ) {
        CRITICAL("Internal error on SPRITE [expression] DISABLE");
    }

    vic2_sprite_disable( _environment, sprite->realName );

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
/* <usermanual>
    @keyword SPRITE AT
    
    @english
    Position a sprite to the (x,y) on the screen.
    
    @italian
    Posiziona uno sprite sullo schermo alla posizione (x,y).

    @syntax SPRITE # [integer] AT ( # [integer], # [integer] )

    @example SPRITE #1 AT ( #42, #42 )

    @target c64

 </usermanual> */
void sprite_position( Environment * _environment, int _sprite, int _x, int _y ) {

    outline3("; SPRITE %d AT (%d,%d)", _sprite, _x, _y);

    char spriteString[16]; sprintf( spriteString, "#$%2.2x", _sprite );
    char yString[16]; sprintf( yString, "#$%2.2x", _y );
    
    Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
    variable_store( _environment, x->name, _x );

    vic2_sprite_position( _environment, spriteString, x->realName, yString );

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
/* <usermanual>
    @keyword SPRITE AT
    
    @syntax SPRITE [expression] AT ( [expression], [expression] )

    @example SPRITE starship AT ( starshipX, starshipY )

 </usermanual> */
void sprite_position_vars( Environment * _environment, char * _sprite, char * _x, char * _y ) {

    Variable * sprite = variable_retrieve( _environment, _sprite );
    if ( ! sprite ) {
        CRITICAL("Internal error on SPRITE [expression] AT ([expression],[expression])");
    }

    Variable * x = variable_retrieve( _environment, _x );
    if ( ! x ) {
        CRITICAL("Internal error on SPRITE [expression] AT ([expression],[expression])");
    }

    Variable * y = variable_retrieve( _environment, _y );
    if ( ! y ) {
        CRITICAL("Internal error on SPRITE [expression] AT ([expression],[expression])");
    }

    outline3("; SPRITE %s AT (%s,%s)", sprite->name, x->name, y->name);

    vic2_sprite_position( _environment, sprite->realName, x->realName, y->realName );

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
/* <usermanual>
    @keyword SPRITE EXPAND
    
    @english
    Expand a given sprite, vertically or horizontally,
    
    @italian
    Espande un dato sprite, verticalmente oppure orizzontalmente.

    @syntax SPRITE # [integer] EXPAND VERTICAL

    @example SPRITE #1 EXPAND VERTICAL

    @target c64

 </usermanual> */
void sprite_expand_vertical( Environment * _environment, int _sprite ) {

    outline1("; SPRITE %d EXPAND VERTICAL", _sprite);

    char spriteString[16]; sprintf( spriteString, "#$%2.2x", _sprite );

    vic2_sprite_expand_vertical( _environment, spriteString );

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
/* <usermanual>
    @keyword SPRITE EXPAND
    
    @syntax SPRITE [expression] EXPAND VERTICAL

    @example SPRITE sharship EXPAND VERTICAL

    @target c64

 </usermanual> */
void sprite_expand_vertical_var( Environment * _environment, char * _sprite ) {

    outline1("; SPRITE %s EXPAND VERTICAL", _sprite);

    _environment->bitmaskNeeded = 1;
    
    Variable * sprite = variable_retrieve( _environment, _sprite );
    if ( ! sprite ) {
        CRITICAL("Internal error on SPRITE [expression] EXPAND VERTICAL");
    }

    vic2_sprite_expand_vertical( _environment, sprite->realName );

}

/**
 * @brief Emit ASM code for <b>SPRITE [int] COMPRESS VERTICAL</b>
 * 
 * This function emits a code capable of compressing vertically a given sprite.
 * The index of sprite is given as a direct integer.
 * 
 * @param _environment Current calling environment
 * @param _sprite Index of the sprite to compress vertically (0...7)
 */
/* <usermanual>
    @keyword SPRITE COMPRESS
    
    @english
    Compress a given sprite, vertically or horizontally,
    
    @italian
    Comprime un dato sprite, verticalmente oppure orizzontalmente.

    @syntax SPRITE # [integer] COMPRESS VERTICAL

    @example SPRITE #1 COMPRESS VERTICAL

    @target c64

 </usermanual> */
void sprite_compress_vertical( Environment * _environment, int _sprite ) {

    outline1("; SPRITE %d COMPRESS VERTICAL", _sprite);

    char spriteString[16]; sprintf( spriteString, "#$%2.2x", _sprite );

    vic2_sprite_compress_vertical( _environment, spriteString );

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
/* <usermanual>
    @keyword SPRITE COMPRESS
    
    @syntax SPRITE [expression] COMPRESS VERTICAL

    @example SPRITE #1 COMPRESS VERTICAL

    @target c64

 </usermanual> */
void sprite_compress_vertical_var( Environment * _environment, char * _sprite ) {

    _environment->bitmaskNeeded = 1;
    
    Variable * sprite = variable_retrieve( _environment, _sprite );
    if ( ! sprite ) {
        CRITICAL("Internal error on SPRITE [expression] COMPRESS VERTICAL");
    }

    vic2_sprite_compress_vertical( _environment, sprite->realName );

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
/* <usermanual>
    @keyword SPRITE EXPAND
    
    @syntax SPRITE # [integer] EXPAND HORIZONTAL

    @example SPRITE #1 EXPAND HORIZONTAL

    @target c64

 </usermanual> */
void sprite_expand_horizontal( Environment * _environment, int _sprite ) {

    outline1("; SPRITE %d EXPAND HORIZONTAL", _sprite);

    char spriteString[16]; sprintf( spriteString, "#$%2.2x", _sprite );

    vic2_sprite_expand_horizontal( _environment, spriteString );

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
/* <usermanual>
    @keyword SPRITE EXPAND
    
    @syntax SPRITE [expression] EXPAND HORIZONTAL

    @example SPRITE starship EXPAND HORIZONTAL

    @target c64

 </usermanual> */
void sprite_expand_horizontal_var( Environment * _environment, char * _sprite ) {

    outline1("; SPRITE %s EXPAND HORIZONTAL", _sprite);

    _environment->bitmaskNeeded = 1;
    
    Variable * sprite = variable_retrieve( _environment, _sprite );
    if ( ! sprite ) {
        CRITICAL("Internal error on SPRITE [expression] EXPAND HORIZONTAL");
    }

    vic2_sprite_expand_horizontal( _environment, sprite->realName );

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
/* <usermanual>
    @keyword SPRITE COMPRESS
    
    @syntax SPRITE # [integer] COMPRESS HORIZONTAL

    @example SPRITE #1 COMPRESS HORIZONTAL

    @target c64

 </usermanual> */
void sprite_compress_horizontal( Environment * _environment, int _sprite ) {
    
    outline1("; SPRITE %d COMPRESS HORIZONTAL", _sprite);

    char spriteString[16]; sprintf( spriteString, "#$%2.2x", _sprite );

    vic2_sprite_compress_horizontal( _environment, spriteString );

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
/* <usermanual>
    @keyword SPRITE COMPRESS
    
    @syntax SPRITE [expression] COMPRESS HORIZONTAL

    @example SPRITE starship COMPRESS HORIZONTAL

    @target c64

 </usermanual> */
void sprite_compress_horizontal_var( Environment * _environment, char * _sprite ) {

    outline1("; SPRITE %s COMPRESS HORIZONTAL", _sprite);

    _environment->bitmaskNeeded = 1;
    
    Variable * sprite = variable_retrieve( _environment, _sprite );
    if ( ! sprite ) {
        CRITICAL("Internal error on SPRITE [expression] COMPRESS HORIZONTAL");
    }

    vic2_sprite_compress_horizontal( _environment, sprite->realName );

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
/* <usermanual>
    @keyword SPRITE MULTICOLOR
    
    @english
    Enable multicolor for sprite.
    
    @italian
    Abilita il multicolor per lo sprite dato.

    @syntax SPRITE # [integer] MULTICOLOR

    @example SPRITE #1 MULTICOLOR

    @target c64

 </usermanual> */
void sprite_multicolor( Environment * _environment, int _sprite ) {

    outline1("; SPRITE %d MULTICOLOR", _sprite);

    char spriteString[16]; sprintf( spriteString, "#$%2.2x", _sprite );

    vic2_sprite_multicolor( _environment, spriteString );

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
/* <usermanual>
    @keyword SPRITE MULTICOLOR
    
    @syntax SPRITE [expression] MULTICOLOR

    @example SPRITE starship MULTICOLOR

    @target c64

 </usermanual> */
void sprite_multicolor_var( Environment * _environment, char * _sprite ) {

    outline1("; SPRITE %s MULTICOLOR", _sprite);

    _environment->bitmaskNeeded = 1;
    
    Variable * sprite = variable_retrieve( _environment, _sprite );
    if ( ! sprite ) {
        CRITICAL("Internal error on SPRITE [expression] MULTICOLOR");
    }

    vic2_sprite_multicolor( _environment, sprite->realName );

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
/* <usermanual>
    @keyword SPRITE MONOCOLOR
    
    @english
    Disable multicolor for sprite.
    
    @italian
    Disabilita il multicolor per lo sprite dato.

    @syntax SPRITE # [integer] MONOCOLOR

    @example SPRITE #1 MONOCOLOR

    @target c64

 </usermanual> */
void sprite_monocolor( Environment * _environment, int _sprite ) {

    outline1("; SPRITE %d MONOCOLOR", _sprite);

    char spriteString[16]; sprintf( spriteString, "#$%2.2x", _sprite );

    vic2_sprite_monocolor( _environment, spriteString );

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
/* <usermanual>
    @keyword SPRITE MONOCOLOR
    
    @syntax SPRITE [expression] MONOCOLOR

    @example SPRITE starship MONOCOLOR

    @target c64

 </usermanual> */
void sprite_monocolor_var( Environment * _environment, char * _sprite ) {

    outline1("; SPRITE %s MULTICOLOR", _sprite);

    _environment->bitmaskNeeded = 1;
    
    Variable * sprite = variable_retrieve( _environment, _sprite );
    if ( ! sprite ) {
        CRITICAL("Internal error on SPRITE [expression] MONOCOLOR");
    }

    vic2_sprite_monocolor( _environment, sprite->realName );

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
/* <usermanual>
    @keyword SPRITE COLOR
    
    @english
    Change specific color for a given sprite.
    
    @italian
    Cambia il colore specifico per un dato sprite.

    @syntax SPRITE # [integer] COLOR # [integer]

    @example SPRITE #1 COLOR #2

    @target c64

 </usermanual> */
void sprite_color( Environment * _environment, int _sprite, int _color ) {

    outline2("; COLOR SPRITE %d TO %2.2x", _sprite, _color);

    char spriteString[16]; sprintf(spriteString, "#$%2.2x", _sprite );
    char colorString[16]; sprintf(colorString, "#$%2.2x", _color );

    vic2_sprite_color( _environment, spriteString, colorString );

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
/* <usermanual>
    @keyword SPRITE COLOR
    
    @syntax SPRITE [expression] COLOR [expression]

    @example SPRITE #1 COLOR YELLOW

    @target c64

 </usermanual> */
void sprite_color_vars( Environment * _environment, char * _sprite, char * _color ) {

    outline2("; COLOR SPRITE %s TO %s", _sprite, _color);

    Variable * sprite = variable_retrieve( _environment, _sprite );
    if ( ! sprite ) {
        CRITICAL("Internal error on SPRITE [expression] COLOR [expression]");
    }

    Variable * color = variable_retrieve( _environment, _color );
    if ( ! color ) {
        CRITICAL("Internal error on SPRITE [expression] COLOR [expression]");
    }

    vic2_sprite_color( _environment, sprite->realName, color->realName );

}