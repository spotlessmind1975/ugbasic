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
void sprite_at( Environment * _environment, int _sprite, int _x, int _y ) {

    outline3("; SPRITE %d AT (%d,%d)", _sprite, _x, _y);

    char spriteString[MAX_TEMPORARY_STORAGE]; sprintf( spriteString, "#$%2.2x", _sprite );
    char yString[MAX_TEMPORARY_STORAGE]; sprintf( yString, "#$%2.2x", _y );
    
    Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
    variable_store( _environment, x->name, _x );

    vic2_sprite_at( _environment, spriteString, x->realName, yString );

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
void sprite_at_vars( Environment * _environment, char * _sprite, char * _x, char * _y ) {

    Variable * sprite = variable_retrieve( _environment, _sprite );

    Variable * x = variable_retrieve( _environment, _x );

    Variable * y = variable_retrieve( _environment, _y );

    outline3("; SPRITE %s AT (%s,%s)", sprite->name, x->name, y->name);

    vic2_sprite_at( _environment, sprite->realName, x->realName, y->realName );

}

