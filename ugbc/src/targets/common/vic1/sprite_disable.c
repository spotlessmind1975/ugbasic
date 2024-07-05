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
Disable the sprite (by its number). If the number is omitted, all sprites
will be disable.

@italian
Disabilita lo sprite (per numero). Se il numero viene omesso,
tutti gli sprite saranno disabilitati.

@syntax SPRITE #number DISABLE
@syntax SPRITE DISABLE

@example SPRITE #1 DISABLE

@alias SPRITE OFF
</usermanual> */
/* <usermanual>
@keyword SPRITE OFF

@english
Disable the sprite, alias di ''SPRITE DISABLE''.

@italian
Disabilita lo sprite, alias di ''SPRITE DISABLE''.

@syntax SPRITE #number OFF
@syntax SPRITE OFF

@example SPRITE #1 OFF

@alias SPRITE DISABLE
</usermanual> */

void sprite_disable( Environment * _environment, int _sprite ) {

    

    char spriteString[MAX_TEMPORARY_STORAGE]; sprintf( spriteString, "#$%2.2x", _sprite );

    vic1_sprite_disable( _environment, spriteString );

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

@syntax SPRITE sprite DISABLE

@example SPRITE starship DISABLE
</usermanual> */
/* <usermanual>
@keyword SPRITE OFF

@syntax SPRITE sprite OFF

@example SPRITE starship OFF
</usermanual> */
void sprite_disable_var( Environment * _environment, char * _sprite ) {

    _environment->bitmaskNeeded = 1;
    
    Variable * sprite = variable_retrieve( _environment, _sprite );

    vic1_sprite_disable( _environment, sprite->realName );

}

#endif
