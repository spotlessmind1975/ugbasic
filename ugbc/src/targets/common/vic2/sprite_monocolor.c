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
 * @brief Emit ASM code for <b>SPRITE [int] MONOCOLOR</b>
 * 
 * This function emits a code capable of enabling monocolor for a given sprite.
 * The index of sprite is given as direct integer.
 * 
 * @param _environment Current calling environment
 * @param _sprite Index of the sprite for which enable monocolor (0...7)
 */
/* <usermanual>
@keyword SPRITE MONOCOLOR (command)

@english

With the ''SPRITE MONOCOLOR'' command you can set the sprite 
as monochrome.

Note that the keyword to use is only ''MONOCOLOR'', which must therefore 
be preceded by the keyword ''SPRITE'' and the sprite index. You can put multiple 
''MONOCOLOR'' statements together, but of course this will have no effect.

@italian

Con il comando ''SPRITE MONOCOLOR'' puoi impostare lo sprite come
monocromatico.

Si noti che la parola chiave da usare è solo ''MONOCOLOR'', che deve 
quindi essere preceduta dalla parola chiave ''SPRITE'' e dall'indice sprite. 
È possibile accostare più istruzioni ''MONOCOLOR'' ma, ovviamente, 
ciò non sortirà effetti.

@syntax SPRITE index MONOCOLOR [command [command ...]]

@example SPRITE ship MONOCOLOR

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
void sprite_monocolor( Environment * _environment, int _sprite ) {

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

    vic2_sprite_monocolor( _environment, _sprite );

}

#endif