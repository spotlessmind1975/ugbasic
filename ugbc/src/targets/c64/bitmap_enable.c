/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
Enable bitmap graphics on the target machine. Bitmap resolution and colors depends on hardware.
Enabling the bitmap also sets the starting address in memory, for those computers that have 
graphics mapped in memory. 

Given the great variety of hardware that ugBASIC supports and the isomorphic approach adopted, 
this commands can be used to require a specific resolution, color depth and other characteristics in a
hardware independent way. 

In this regard, the following approach has been adopted. It is possible to ask for specific 
chacteristics, such as height and width of the screen. However ugBASIC will choose the closest 
resolution, based on the hardware on which it will runs.

Likewise, if no type of resolution constraint is set, the best is offered.

To change resolution and colors, you can use the ''([width],[height],[colors])'', ''([width],[height])'' 
or the ''([colors])'' syntax after ''BITMAP ENABLE'' command. So, if you omit a parameters, it means that
it is not important to set.

@italian
Abilita la grafica bitmap sulla macchina di destinazione. La risoluzione e i colori dipendono 
dall'hardware. L'abilitazione della bitmap imposta anche l'indirizzo iniziale in memoria, 
per quei computer che hanno la grafica mappata in memoria.

Data la grande varietà di hardware che ugBASIC supporta e l'approccio isomorfo adottato,
questi comandi possono essere utilizzati per richiedere una specifica risoluzione, profondità
di colore e altre caratteristiche in a modo indipendente dall'hardware.

A tal riguardo è stato adottato il seguente approccio. E' possibile richiedere specifiche
caratteristiche, come l'altezza e la larghezza dello schermo. Tuttavia ugBASIC sceglierà il più vicino
risoluzione, in base all'hardware su cui verrà eseguito.

Allo stesso modo, se non viene impostato alcun tipo di vincolo di risoluzione, viene offerto il meglio.

Per cambiare risoluzione e colori, puoi usare le sintassi ''([width],[height],[colors])'', ''([width],[height])''
o ''([colors])'' dopo il comando ''BITMAP ENABLE''. Quindi, omettendo un parametro, significa che non è 
importante impostarlo.

@syntax BITMAP ENABLE { ([width],[height]{,[colors]}) }
@syntax BITMAP ENABLE { ([colors]) }

@example BITMAP ENABLE
@example BITMAP ENABLE (320,200,16)
@example BITMAP ENABLE (160,200,2)
@usedInExample screens_resolution_01.bas

@seeAlso BITMAP DISABLE
@seeAlso TILEMAP ENABLE

@target c64

</usermanual> */
void bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

    // Let's define the special variable bitmapAddress.
    Variable * bitmapAddress = variable_retrieve( _environment, "BITMAPADDRESS" );

    // Let's define the special variable colormapAddress.
    Variable * colormapAddress = variable_retrieve_or_define( _environment, "COLORMAPADDRESS", VT_ADDRESS, 0x8400 );

    outline0("; BITMAP ENABLE");

    vic2_bitmap_enable( _environment, _width, _height, _colors );

}