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
 * @brief Emit ASM implementation for <b>BITMAP ENABLE</b> instruction
 * 
 * This function can be called to emit the code to enable bitmap graphics
 * on the target machine. Bitmap resolution and colors depends on hardware.
 * Enabling the bitmap also sets the starting address in memory, for those 
 * computers that have graphics mapped in memory.
 * 
 * On some machine calling this instruction will define two special variables:
 * 
 *  * `BITMAPADDRESS` (VT_ADDRESS) - the starting address of bitmap memory
 *  * `COLORMAPADDRESS` (VT_ADDRESS) - the starting address of color map memory
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword BITMAP ENABLE

@english

The ''BITMAP ENABLE' command is a fundamental tool, since it allows to
configure the graphics mode of the screen, that is, to define how data 
was displayed on the screen, determining aspects such as the number of 
horizontal and vertical pixels that make up the image on the screen, and
the color palette available for drawing images.

In 8-bit computers, memory was limited and processing power was much 
lower than modern computers. The ''BITMAP ENABLE'' allows you to optimize 
the use of resources by choosing the graphics mode best suited to the 
needs of the program and, at the same time, to generalize if the
program must be ported on other hardware.

Given the great variety of hardware that ugBASIC supports and the
isomorphic approach adopted, this commands can be used to require a
specific resolution, color depth and other characteristics in a
hardware independent way. 

In this regard, the following approach has been adopted. It is possible
to ask for specific chacteristics, such as height and width of the 
screen. However ugBASIC will choose the closest resolution, based 
on the hardware on which it will runs.

Likewise, if no type of resolution constraint is set, the best is offered.

To change resolution and colors, you can use the ''([width],[height],[colors])'', 
''([width],[height])'' or the ''([colors])'' syntax after ''BITMAP ENABLE'' command. 
So, if you omit a parameters, it means thatit is not important to set.

@italian

Il comando ''BITMAP ENABLE'' è uno strumento fondamentale, poiché consente 
di configurare la modalità grafica dello schermo, ovvero di definire come i 
dati sono stati visualizzati sullo schermo, determinando aspetti come il 
numero di pixel orizzontali e verticali che compongono l'immagine sullo 
schermo e la tavolozza dei colori disponibile per disegnare le immagini.

Nei computer a 8 bit, la memoria era limitata e la potenza di elaborazione 
era molto inferiore rispetto ai computer moderni. Il comando ''BITMAP ENABLE'' 
consente di ottimizzare l'uso delle risorse scegliendo la modalità grafica 
più adatta alle esigenze del programma e, allo stesso tempo, di generalizzare 
se il programma deve essere portato su altro hardware.

Data la grande varietà di hardware che ugBASIC supporta e l'approccio 
isomorfo adottato, questi comandi possono essere utilizzati per richiedere 
una risoluzione specifica, profondità di colore e altre caratteristiche in 
modo indipendente dall'hardware.

A questo proposito, è stato adottato il seguente approccio. È possibile richiedere
caratteristiche specifiche, come altezza e larghezza dello schermo. Tuttavia 
ugBASIC sceglierà la risoluzione più vicina, in base all'hardware su cui verrà eseguito.

Allo stesso modo, se non è impostato alcun tipo di vincolo di risoluzione, 
viene offerto il migliore. Per modificare la risoluzione e i colori, puoi usare 
la sintassi ''(width, height, colors)'', ''(width, height)'' o ''(colors) '' 
dopo il comando ''BITMAP ENABLE''. Quindi, se ometti un parametro, significa 
che non è importante impostarlo.

@syntax BITMAP ENABLE
@syntax BITMAP ENABLE (colors)
@syntax BITMAP ENABLE (width, height)
@syntax BITMAP ENABLE (width, height, colors)

@example BITMAP ENABLE
@example BITMAP ENABLE (320,200,16)
@example BITMAP ENABLE (160,200,2)

@usedInExample screens_resolution_01.bas

@seeAlso BITMAP DISABLE
@seeAlso TILEMAP ENABLE

@target c128
</usermanual> */
void bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    // Let's define the special variable bitmapAddress.
    Variable * bitmapAddress = variable_retrieve( _environment, "BITMAPADDRESS" );

    // Let's define the special variable colormapAddress.
    Variable * colormapAddress = variable_retrieve_or_define( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0x8400 );

    vic2_bitmap_enable( _environment, _width, _height, _colors );

}