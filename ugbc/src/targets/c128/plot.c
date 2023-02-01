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
The ''PLOT'' instruction allows you to draw a point on the screen, at 
the ''(x, y)'' coordinate and with any color. If the color is not 
provided, the default color is the one set with the last ''INK'' / ''PEN'' command.

It is possible to omit one or both coordinates, and ugBASIC will use the last one used, 
which is stored in the ''XGR'' and ''YGR'' variables.

@italian
L'istruzione ''PLOT'' consente di disegnare un punto sullo schermo, alla 
coordinata ''(x,y)'' e con l'eventuale colore. Se il colore non viene fornito, 
il colore di default è quello impostato con l'ultimo comando ''INK'' / ''PEN''.

E' possibile omettere una o entrambe le coordinate, e ugBASIC utilizzerà l'ultima 
usata, che viene stoccata nelle variabili ''XGR'' e ''YGR''.

@syntax PLOT [x], [y] {, [color]}

@example PLOT 42, 42
@example PLOT 100, 100, RED

@usedInExample contrib_sierpinski3.bas

@target c128
 </usermanual> */

void plot( Environment * _environment, char * _x, char * _y, char *_c ) {

    if ( _c ) {
        pen( _environment, _c );
    }

    vic2_point_at_vars( _environment, _x, _y );

}