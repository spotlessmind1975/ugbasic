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
 * @brief Emit ASM code for <b>SPRITE [int] COMPRESS HORIZONTAL</b>
 * 
 * This function emits a code capable of compressing horizontally a given sprite.
 * The index of sprite is given as a direct integer.
 * 
 * @param _environment Current calling environment
 * @param _sprite Index of the sprite to compress horizontally (0...7)
 */
/* <usermanual>
@keyword SPRITE COMPRESS HORIZONTAL (command)

@english

With the ''SPRITE COMPRESS HORIZONTAL'' command you can compress the sprite 
horizontally, so that it is effectively one pixel on the screen for every 
pixel of the sprite.

Note that the keyword to use is only ''COMPRESS HORIZONTAL'', which must therefore 
be preceded by the keyword ''SPRITE'' and the sprite index. You can put multiple 
''COMPRESS HORIZONTAL'' statements together, but of course this will have no effect.

@italian

Con il comando ''SPRITE COMPRESS HORIZONTAL'' puoi comprimere orizzontalmente 
lo sprite, in modo che effettivamente valga un pixel sullo schermo per ogni 
pixel dello sprite.

Si noti che la parola chiave da usare è solo ''COMPRESS HORIZONTAL'', che deve 
quindi essere preceduta dalla parola chiave ''SPRITE'' e dall'indice sprite. 
È possibile accostare più istruzioni ''COMPRESS HORIZONTAL'' ma, ovviamente, 
ciò non sortirà effetti.

@syntax SPRITE index COMPRESS HORIZONTAL [command [command ...]]

@example SPRITE ship COMPRESS HORIZONTAL

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
void sprite_compress_horizontal( Environment * _environment, int _sprite ) {
    
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

    vic2_sprite_compress_horizontal( _environment, _sprite );

}

#endif