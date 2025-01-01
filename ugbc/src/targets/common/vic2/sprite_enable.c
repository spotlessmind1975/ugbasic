/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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

#if defined(__c64__) || defined(__c64reu__) || defined(__c128__)

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
@keyword SPRITE ENABLE (command)

@english

With the ''SPRITE ENABLE'' command you can enable (show) the sprite, 
so that it will be drawn.

Note that the keyword to use is only ''ENABLE'', which must therefore 
be preceded by the keyword ''SPRITE'' and the sprite index. You can put multiple 
''ENABLE'' statements together, but of course this will have no effect.

@italian

Con il comando ''SPRITE ENABLE'' puoi abilitare (mostrare) lo sprite, in
modo che non venga più disegnato.

Nota che la parola chiave da usare è solo ''ENABLE'', che deve quindi essere 
preceduta dalla parola chiave ''SPRITE'' e dall'indice dello sprite. Puoi mettere 
insieme più istruzioni ''ENABLE'', ma ovviamente questo non avrà alcun effetto.

@syntax SPRITE index ENABLE [command [command ...]]

@example SPRITE ship ENABLE

@seeAlso SPRITE (function)
@seeAlso SPRITE

@target c64
@target c64reu
@target c128
@target msx1
@target coleco
@target sc3000
@target sg1000
</usermanual> */
/* <usermanual>
@keyword SPRITE ON (command)

@english

@italian

@syntax SPRITE index ON [command [command ...]]

@example SPRITE ship ON

@target c64
@target c64reu
@target c128
@target msx1
@target coleco
@target sc3000
@target sg1000
</usermanual> */
void sprite_enable( Environment * _environment, int _sprite ) {

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

    vic2_sprite_enable( _environment, _sprite );

}

#endif