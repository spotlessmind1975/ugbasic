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

extern char DATATYPE_AS_STRING[][16];

/**
 * @brief Emit ASM code for <b>RASTER LINE</b>
 * 
 * This function outputs a code that retrieve the current raster line.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword RASTER LINE

@english
The ''RASTER LINE'' keyword gives the current raster line, or the
current vertical position of a raster beam. A raster beam is a beam 
of electrons or light that systematically scans an area, moving from 
left to right and top to bottom, like the lines that form an image 
on a cathode ray tube or CRT television. This movement creates a grid 
of points of light, called pixels, that together form the complete image.

Imagine painting a picture with a brush. The brush moves from left to 
right and then down a line, repeating this movement until the entire 
surface is covered. The brush in this case represents the raster beam.
The raster line indicates the vertical position of the raster beam 
at any given time. The values range of this position varies on the various
targets, and if a PAL or NTSC system is in use.

Having access to the the raster line can help optimize rendering, 
animation, and image processing algorithms. If you experience display 
problems, such as distorted lines or flickering images, analyzing 
raster lines can help pinpoint the cause. Many applications, such 
as video games and 3D graphics software, require precise control 
of the raster beam to create complex visual effects.

@italian
La parola chiave ''RASTER LINE'' indica la linea raster corrente, 
o la posizione verticale corrente di un raggio raster. Un raggio 
raster è un raggio di elettroni o luce che scansiona sistematicamente 
un'area, muovendosi da sinistra a destra e dall'alto verso il basso, 
come le linee che formano un'immagine su un tubo a raggi catodici o 
un televisore CRT. Questo movimento crea una griglia di punti di 
luce, chiamati pixel, che insieme formano l'immagine completa.

Immagina di dipingere un quadro con un pennello. Il pennello si
muove da sinistra a destra e poi lungo una linea, ripetendo questo
movimento fino a coprire l'intera superficie. In questo caso, il 
pennello rappresenta il raggio raster.

La linea raster indica la posizione verticale del raggio raster in 
un dato momento. Il range di valori di questa posizione variano sui vari 
target e se è in uso un sistema PAL o NTSC.

Avere accesso alla linea raster può aiutare a ottimizzare gli algoritmi 
di rendering, animazione ed elaborazione delle immagini. Se riscontri 
problemi di visualizzazione, come linee distorte o immagini tremolanti, 
l'analisi delle linee raster può aiutare a individuare la causa. 
Molte applicazioni, come i videogiochi e i software di grafica 3D, 
richiedono un controllo preciso del raggio raster per creare effetti 
visivi complessi.

@syntax = RASTER LINE

@example randomScore = RASTER LINE

@target c128
</usermanual> */
Variable * get_raster_line( Environment * _environment ) {

    return vic2_get_raster_line( _environment );

}