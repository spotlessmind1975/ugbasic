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

#if defined(__c64__) || defined(__c64reu__) || defined(__c128__)

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
@keyword SPRITE DISABLE (command)

@english

With the ''SPRITE DISABLE'' command you can disable (hide) the sprite, 
so that it will not be drawn anymore.

Note that the keyword to use is only ''DISABLE'', which must therefore 
be preceded by the keyword ''SPRITE'' and the sprite index. You can put multiple 
''DISABLE'' statements together, but of course this will have no effect.

@italian

Con il comando ''SPRITE DISABLE'' puoi disabilitare (nascondere) lo sprite, in
modo che non venga più disegnato.

Nota che la parola chiave da usare è solo ''DISABLE'', che deve quindi essere 
preceduta dalla parola chiave ''SPRITE'' e dall'indice dello sprite. Puoi mettere 
insieme più istruzioni ''DISABLE'', ma ovviamente questo non avrà alcun effetto.

@syntax SPRITE index DISABLE [command [command ...]]

@example SPRITE ship DISABLE

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
@keyword SPRITE OFF (command)

@english

Alias for ''SPRITE DISABLE''.

@italian

Alias per ''SPRITE DISABLE''.

@syntax SPRITE index OFF [command [command ...]]

@example SPRITE ship OFF

@target c64
@target c64reu
@target c128
@target msx1
@target coleco
@target sc3000
@target sg1000
</usermanual> */

void sprite_disable( Environment * _environment, int _sprite ) {

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

    vic2_sprite_disable( _environment, _sprite );

}

#endif