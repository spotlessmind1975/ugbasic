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
 * @brief Emit code for <strong>PLOT</strong>
 * 
 * Emit code to draw a pixel at a given point.
 * 
 * @param _environment Current calling environment
 * @param _x Abscissa of the pixel.
 * @param _y Coordinate of the pixel.
 * @param _c Color of the pixel.
 */
/* <usermanual>
@keyword PLOT

@english

The ''PLOT'' command allows you to draw individual points on the screen, laying 
the foundation for creating more complex shapes such as lines or rectangles.
The origin (0,0) is usually located in the upper left corner of the screen, but can
be changed using ''ORIGIN'' command. The coordinates increase to the right (for x) 
and down (for y), at least if the y axis is inverted using always the ''ORIGIN''.
If the color is not provided, the default color is the one set with the last 
''INK'' / ''PEN'' command. It is possible to omit one or both coordinates, 
and ugBASIC will use the last one used, which is stored in the ''XGR'' and ''YGR'' variables.

The ''PLOT'' command is the starting point for any drawing. By drawing a series 
of points close together, you can create the illusion of a line. By combining lines, 
you can create geometric shapes such as rectangles, triangles, and circles.
By sequentially changing the coordinates of points, you can create rudimentary animations,

The accuracy of your drawings is limited by your screen resolution, and drawing a large 
number of points can be slow, especially on less powerful computers. The ugBASIC
language offers commands to draw lines, rectangles, and circles more efficiently, 
but ''PLOT'' is the foundation.

@italian

Il comando ''PLOT'' consente di disegnare singoli punti sullo schermo, gettando 
le basi per la creazione di forme più complesse come linee o rettangoli.
L'origine (0,0) si trova solitamente nell'angolo in alto a sinistra dello schermo, 
ma può essere modificata utilizzando il comando ''ORIGIN''. Le coordinate aumentano 
verso destra (per x) e verso il basso (per y), almeno se l'asse y è invertito 
utilizzando sempre ''ORIGIN''. Se il colore non è specificato, il colore predefinito 
è quello impostato con l'ultimo comando ''INK'' / ''PEN''. È possibile omettere una 
o entrambe le coordinate e ugBASIC utilizzerà l'ultima utilizzata, che è memorizzata 
nelle variabili ''XGR'' e ''YGR''.

Il comando ''PLOT'' è il punto di partenza per qualsiasi disegno. Disegnando una 
serie di punti ravvicinati, è possibile creare l'illusione di una linea. Combinando 
le linee, puoi creare forme geometriche come rettangoli, triangoli e cerchi.
Modificando in sequenza le coordinate dei punti, puoi creare animazioni rudimentali. 
La precisione dei tuoi disegni è limitata dalla risoluzione dello schermo e 
disegnare un gran numero di punti può essere lento, specialmente su computer 
meno potenti. Il linguaggio ugBASIC offre comandi per disegnare linee, rettangoli 
e cerchi in modo più efficiente, ma ''PLOT'' è la base.

@syntax PLOT [x], [y][, color]

@example PLOT 42, 42
@example PLOT 100, 100, RED

@usedInExample contrib_sierpinski3.bas

@target c128
 </usermanual> */

/* <usermanual>
@keyword POINT AT

@english

@italian

@syntax POINT AT ( [x], [y] )

@example POINT AT ( 42, 42 )

@usedInExample contrib_sierpinski3.bas

</usermanual> */

void plot( Environment * _environment, char * _x, char * _y, char *_c, int _preserve_color ) {

    vic2_pset_vars( _environment, _x, _y, _c );

    if ( _c && !_preserve_color ) {
        pen( _environment, _c );
    }

}