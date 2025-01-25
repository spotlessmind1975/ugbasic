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
@keyword SPRITE PRIORITY (command)

@english

With the ''SPRITE PRIORITY'' command you can indicate if the sprite
has a priority in respect of characters.

Note that the keyword to use is only ''PRIORITY'', which must therefore 
be preceded by the ''SPRITE'' keyword and the sprite index. It is possible 
to put multiple ''PRIORITY'' instructions side by side, but obviously the 
processor speed is such that only the last one will be the one that counts.

@italian

Con il comando ''SPRITE PRIORITY'' puoi indicare se lo sprite
ha una priorità rispetto ai caratteri.

Nota che la parola chiave da usare è solo ''PRIORITY'', che deve quindi 
essere preceduta dalla parola chiave ''SPRITE'' e dall'indice dello sprite. 
È possibile mettere più istruzioni ''PRIORITY'' una accanto all'altra, 
ma ovviamente la velocità del processore è tale che solo l'ultima sarà 
quella che conta.

@syntax SPRITE index PRIORITY priority [command [command ...]]

@example SPRITE ship PRIORITY 1

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
void sprite_priority( Environment * _environment, int _sprite, int _priority ) {

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
void sprite_priority_vars( Environment * _environment, char * _sprite, char * _priority ) {

    vic2_sprite_priority( _environment, _sprite, _priority );

}

#endif