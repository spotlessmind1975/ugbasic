/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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

#include "../../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

#if defined(__vic20__)

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
Enable the sprite given (by its number). If the number is omitted, 
all sprites will be enabled.

@italian
Abilita lo sprite (per numero). Se il numero è omesso, abilita
tutti gli sprite.

@syntax SPRITE # [integer] ENABLE

@example SPRITE #1 ENABLE

@alias SPRITE ON
</usermanual> */
/* <usermanual>
@keyword SPRITE ON

@english
Enable the sprite, alias of ''SPRITE ENABLE''.

@italian
Abilita lo sprite, alias di ''SPRITE ENABLE''.

@syntax SPRITE # [integer] ON

@example SPRITE #1 ON

@alias SPRITE ENABLE
</usermanual> */
void sprite_enable( Environment * _environment, int _sprite ) {

    

    char spriteString[MAX_TEMPORARY_STORAGE]; sprintf( spriteString, "#$%2.2x", _sprite );

    vic1_sprite_enable( _environment, spriteString );

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
/* <usermanual>
@keyword SPRITE ON

@syntax SPRITE [expression] ON

@example SPRITE starship ON
</usermanual> */
void sprite_enable_var( Environment * _environment, char * _sprite ) {

    

    Variable * sprite = variable_retrieve( _environment, _sprite );

    vic1_sprite_enable( _environment, sprite->realName );

}

#endif
