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
 * @brief Emit code for <strong>PAPER ...</strong> command
 * 
 * @param _environment Current calling environment
 * @param _color Color to use for the paper
 */
/* <usermanual>
@keyword PAPER (instruction)

@english

The ''PAPER'' command define the background color of the screen. Imagine having a blank sheet of
paper to draw on: with ''PAPER'', you can choose the color of this sheet, turning it into a colored 
sheet, lined or squared, depending on your preferences and the capabilities of your computer.

The parameter ''color'' is represented  by a value in the available colors, from 0 to maximum 
(''PAPER COLORS''). For the very specific reasons, each color is encoded by a literal constant,
like ''WHITE'' or ''YELLOW''. Those constants will be replaced by proper color index or
values, depending on the hardware. Obviously, you can directly put the numeric value
for the color, but you have to know the underlying encoding of the colors.

By combining the background color (defined with ''PAPER'') with the color of the text or lines 
(defined with ''PEN''), you can create interesting visual effects and improve the readability 
of your programs. You can also use ''PAPER'' to create colored backgrounds that simulate 
different environments, such as a starry sky, a green meadow or a blue ocean. In simple games, 
''PAPER'' allows you to define the game background, creating a more immersive atmosphere.

So the graphics capabilities of the ''PAPER'' command are closely tied to the capabilities of
the target running the program. The resolution of the screen affected the quality of the colors displayed. 
On lower-resolution screens, colors could appear less sharp. Some systems offers a wider color 
gamut and more flexibility in defining colors. Others use a limited color palette could result 
in some uniformity in the colors available. In some target you can define your own palettes, 
so there is no guarantee that the constants and values are the same. 

You can use the ''DEFAULT'' constant to use the default paper color for
the considered target, again if no color replacement has been done.

@italian

Il comando ''PAPER'' definisce il colore di sfondo dello schermo. Immagina di avere un 
foglio bianco su cui disegnare: con ''PAPER'' puoi scegliere il colore di questo foglio, 
trasformandolo in un foglio colorato, a righe o a quadretti, a seconda delle tue preferenze 
e delle capacità del tuo computer.

Il parametro ''color'' è rappresentato da un valore nei colori disponibili, da 0 al massimo 
(''PAPER COLORS''). Per motivi molto specifici, ogni colore è codificato da una costante 
letterale, come ''WHITE'' o ''YELLOW''. Tali costanti saranno sostituite da un indice o 
valori di colore appropriati, a seconda dell'hardware. Ovviamente, puoi inserire 
direttamente il valore numerico per il colore, ma devi conoscere la codifica sottostante 
dei colori.

Combinando il colore di sfondo (definito con ''PAPER'') con il colore del testo o delle 
linee (definiti con ''PEN''), puoi creare interessanti effetti visivi e migliorare la 
leggibilità dei tuoi programmi. Puoi anche usare ''PAPER'' per creare sfondi colorati 
che simulano diversi ambienti, come un cielo stellato, un prato verde o un oceano blu. 
Nei giochi semplici, ''PAPER'' ti consente di definire lo sfondo del gioco, 
creando un'atmosfera più immersiva.

Quindi le capacità grafiche del comando ''PAPER'' sono strettamente legate alle capacità
del target che esegue il programma. La risoluzione dello schermo ha influenzato la qualità 
dei colori visualizzati. Su schermi a bassa risoluzione, i colori potrebbero apparire meno nitidi. 
Alcuni sistemi offrono una gamma di colori più ampia e maggiore flessibilità nella 
definizione dei colori. Altri utilizzano una tavolozza di colori limitata che potrebbe 
comportare una certa uniformità nei colori disponibili. In alcuni target puoi definire 
le tue tavolozze, quindi non c'è garanzia che le costanti e i valori siano gli stessi.

Puoi usare la costante ''DEFAULT'' per usare il colore della carta predefinito 
per il target considerato, sempre se non è stata effettuata alcuna sostituzione del colore.

@syntax PAPER color

@example PAPER GREEN
@example PAPER colore

@UsedInExample texts_options_01.bas
@UsedInExample texts_options_02.bas

@seeAlso PEN (instruction)
@seeAlso PAPER (function)

</usermanual> */
void paper( Environment * _environment, char * _color ) {

    Variable * paper = variable_retrieve( _environment, "PAPER" );
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_BLACK );

    vic2_background_color_vars( _environment, "#0", color->realName );

    variable_move( _environment, color->name, paper->name );
    // vic2_border_color( _environment, color->realName );
    
}
