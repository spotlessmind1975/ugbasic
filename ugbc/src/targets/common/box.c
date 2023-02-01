/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit ASM code to implement <strong>BOX</strong> command
 * 
 * @param _environment Current calling environment
 * @param _x1 Left abscissa of the box
 * @param _y1 Left ordinate of the box
 * @param _x2 Right abscissa of the box
 * @param _y2 Right ordinate of the box
 * @param _c Color to use for drawing the box
 */
/* <usermanual>
@keyword BOX

@english
This instruction draws a rectangle on the screen, starting from the coordinates ''(x1, y1)''
to arrive at the coordinates ''(x2, y2)'', using the color ''c''. The start or the final
coordinates can be omitted: in this case, ugBASIC will draw, respectively, starting from 
the last drawn position and arriving at the last drawn position. If the color is 
omitted, the last color selected with the ''INK'' or ''PEN'' command will be used. 
Finally, the default line style is full but a 16 bit bitmask can be set with the ''SET LINE''
command.

@italian
Questa istruzione disegna un rettangolo sullo schermo, a partire dalle coordinate ''(x1,y1)''
per arrivare alle coordinate ''(x2,y2)'', utilizzando il colore ''c''. Le coordinate di inizio o
quelle di fine possono essere omesse: in tal caso, ugBASIC disegnerà, rispettivamente, 
ùa partire dall'ultima posizione disegnata arrivando all'ultima posizione disegnata. 
Se il colore viene omesso sarà utilizzato l'ultimo colore selezionato con il comando ''INK'' 
oppure ''PEN'. Infine, lo stile della linea di default è pieno ma può essere impostata una 
bitmask di 16 bit con il comando ''SET LINE''.

@syntax BOX { [x1] },{ [y1] } TO { [x2] },{ [x2] },{ [c] } 
@syntax BOX { [x1] },{ [x1] } TO { [x1] },{ [x1] } 
@syntax BOX TO { [x1] },{ [x1] },{ [c] } 
@syntax BOX TO { [x1] },{ [x1] } 

@example BOX 10,10 TO 100,100,WHITE
@example BOX TO 100,100
@example BOX ,10 TO ,100
@usedInExample graphics_lines_02.bas

@target all
</usermanual> */
void box( Environment * _environment, char * _x1, char * _y1, char * _x2, char * _y2, char * _c ) {

    draw( _environment, _x1, _y1, _x2, _y1, _c );
    draw( _environment, _x1, _y1, _x1, _y2, _c );
    draw( _environment, _x1, _y2, _x2, _y2, _c );
    draw( _environment, _x2, _y1, _x2, _y2, _c );

}