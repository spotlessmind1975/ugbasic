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

#include "../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>PEN ...</strong> command
 * 
 * @param _environment Current calling environment
 * @param _color Color to use for the pen
 */
/* <usermanual>
@keyword PEN (instrucion)

@english

The ''PEN'' command define the color that will be used to draw lines, shapes, or write text 
on the screen. In practice, it is like choosing the color of a pen or marker before you 
start drawing. Depending on the hardware capabilities of the computer, the range of colors 
available could be limited or very large. Some systems used predefined color palettes, 
while others allowed you to define your own colors.

In order to be isomorphic, the ''color'' parameter repesents a value in the available 
colors, from 0 to maximum (''PEN COLORS''). For the very specific reasons, each color is encoded by a literal constant,
like ''WHITE'' or ''YELLOW''. Those constants will be replaced by proper color index or
values, depending on the hardware. Obviously, you can directly put the numeric value
for the color, but you have to know the underlying encoding of the colors.

So the graphics capabilities of the ''PEN'' command are closely tied to the capabilities of
the target running the program. The resolution of the screen affected the quality of the colors displayed. 
On lower-resolution screens, colors could appear less sharp. Some systems offers a wider color 
gamut and more flexibility in defining colors. Others use a limited color palette could result 
in some uniformity in the colors available. In some target you can define your own palettes, 
so there is no guarantee that the constants and values are the same. 

You can use the ''DEFAULT'' constant to use the default pen color for
the considered target, again if no color replacement has been done.

@italian

Il comando ''PEN'' definisce il colore che verrà utilizzato per disegnare linee, forme o scrivere
testo sullo schermo. In pratica, è come scegliere il colore di una penna o di un pennarello prima 
di iniziare a disegnare. A seconda delle capacità hardware del computer, la gamma di colori 
disponibili potrebbe essere limitata o molto ampia. Alcuni sistemi utilizzavano tavolozze di 
colori predefinite, mentre altri consentivano di definire i propri colori.

Per essere isomorfo, il parametro ''color'' rappresenta un valore nelle tonalità di colore disponibili. 
Per queste ragioni molto specifiche, ogni colore è codificato da una costante letterale, come ''WHITE'' 
o ''YELLOW''. Tali costanti saranno sostituite da un indice o valori di colore appropriati, a seconda 
dell'hardware. Ovviamente, si può inserire direttamente il valore numerico per il colore, ma si deve
conoscere la codifica sottostante dei colori.

Quindi le capacità grafiche del comando ''PEN'' sono strettamente legate alle capacità del target 
che esegue il programma. La risoluzione dello schermo influenzava la qualità dei colori visualizzati. 
Su schermi a bassa risoluzione, i colori potrebbero apparire meno nitidi. Alcuni sistemi offrono 
una gamma di colori più ampia e maggiore flessibilità nella definizione dei colori. Altri utilizzano
una tavolozza di colori limitata che potrebbe comportare una certa uniformità nei colori disponibili. 
In alcuni target puoi definire le tue tavolozze, quindi non c'è garanzia che le costanti e i valori 
siano gli stessi.

Si può usare la costante ''DEFAULT'' per usare il colore penna predefinito per il target 
considerato, sempre se non è stata effettuata alcuna sostituzione di colore.

@syntax PEN color

@example PEN 4
@example PEN esempio

@UsedInExample texts_options_01.bas
@UsedInExample texts_options_02.bas

@alias INK
@seeAlso PAPER (instruction)
</usermanual> */

void pen( Environment * _environment, char * _color ) {

    Variable * pen = variable_retrieve( _environment, "PEN" );
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_BLACK );

    variable_move( _environment, color->name, pen->name );
   
}