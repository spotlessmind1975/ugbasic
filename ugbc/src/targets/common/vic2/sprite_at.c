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
@keyword SPRITE AT (command)

@english

With the ''SPRITE AT'' action you can indicate the position where the sprite will 
be placed. The positioning will happen instantly, and the sprite will be drawn in 
that position as soon as the video raster line reaches that position. Note that the
position is indicated in sprites coordinates, and not in pixels: it follows that it
is necessary to carry out the appropriate proportions using the constants (percentiles) 
''SCREEN SPRITE RATIO X'' and ''SCREEN SPRITE RATIO Y''. 

Additionally, the video screen may have a border around the area actually accessible 
to the graphics chipset: as a result, a hardware sprite positioned with a coordinate
that falls within the border may not be visible. To remedy this problem, and ensure 
that the sprite is visible, it is necessary to start from the positions induced 
by the ''SCREEN BORDER X'' and ''SCREEN BORDER Y'' coordinates.

Finally, please note that the keyword to use is only ''AT'', which must therefore be
prefixed by the ''SPRITE'' keyword and the sprite index. It is possible to 
juxtapose multiple ''AT'' instructions but, obviously, the processor speed is such 
that only the last one that counts will be the one that counts.

@italian

Con il comando ''SPRITE AT'' si può indicare la posizione a cui andrà posizionato 
lo sprite. Il posizionamento avverrà istantaneamente, e lo sprite sarà disegnato 
in quella posizione non appena la linea del raster video raggiungerà quella posizione.
Da notare che la posizione è indicata in coordinate sprites, e non in pixel: ne 
consegue che è necessario svolgere le opportune proporzioni usando le costanti 
(percentili) ''SCREEN SPRITE RATIO X'' e ''SCREEN SPRITE RATIO Y''.

Inoltre, lo schermo video potrebbe avere un bordo intorno alla zona effettivamente 
accessibile al chipset grafico: ne consegue che uno sprite hardware posizionato 
con una coordinata che ricada nel bordo potrebbe non essere visibile. Per rimediare 
al problema, ed essere sicuri che lo sprite sia visibile, è necessario partire 
dalle posizioni indotte dalle coordinate SCREEN BORDER X e SCREEN BORDER Y.

Infine, si fa presente che la parola chiave da usare è solo ''AT'', che andrà quindi 
fatta precedere alla parola chiave ''SPRITE'' e all'indice dello sprite. 

E' possibile giustapporre più istruzioni ''AT'' ma, ovviamente, la velocità 
del processore è tale per cui l'unica che conta sarà l'ultima.

@syntax SPRITE index AT (x1, y1) [command [command ...]]

@example SPRITE #1 AT ( #100, #100 )

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
void sprite_at( Environment * _environment, int _sprite, int _x, int _y ) {

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
void sprite_at_vars( Environment * _environment, char * _sprite, char * _x, char * _y ) {

    vic2_sprite_at( _environment, _sprite, _x, _y );

}

#endif