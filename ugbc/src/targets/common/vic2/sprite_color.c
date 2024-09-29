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
@keyword SPRITE COLOR (command)

@english

With the ''SPRITE COLOR'' command you can indicate the specific color in which 
the sprite will be drawn. The color is specific to this sprite, and different 
from the (possible) colors shared by all sprites, which can be changed by the 
''COLOR SPRITE'' command.

Note that the keyword to use is only ''COLOR'', which must therefore be preceded 
by the ''SPRITE'' keyword and the sprite index. It is possible to put multiple 
''COLOR'' instructions side by side, but obviously the processor speed is 
such that only the last one will be the one that counts.

@italian

Con il comando ''SPRITE COLOR'' puoi indicare il colore specifico in cui verrà 
disegnato lo sprite. Il colore è quello specifico per questo sprite, e diverso 
dagli (eventuali) colori condivisi da tutti gli sprite, che possono essere 
modificati dal comando ''COLOR SPRITE''.

Si noti che la parola chiave da usare è solo ''COLOR'', che deve quindi essere 
preceduta dalla parola chiave ''SPRITE'' e dall'indice sprite. È possibile 
accostare più istruzioni ''COLOR'' ma, ovviamente, la velocità del processore 
è tale che solo l'ultima sarà quella che conta.

@syntax SPRITE index COLOR color1 [command [command ...]]

@example SPRITE ship COLOR WHITE

@seeAlso SPRITE (function)
@seeAlso SPRITE
@seeAlso COLOR SPRITE

@target c64
@target c64reu
@target c128
@target msx1
@target coleco
@target sc3000
@target sg1000
</usermanual> */
void sprite_color( Environment * _environment, int _sprite, int _color ) {

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

    vic2_sprite_color( _environment, _sprite, _color );

}

#endif