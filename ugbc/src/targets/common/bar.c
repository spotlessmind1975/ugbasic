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

#include "../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit ASM code to implement <strong>BAR</strong> command
 * 
 * @param _environment Current calling environment
 * @param _x1 Left abscissa of the box
 * @param _y1 Left ordinate of the box
 * @param _x2 Right abscissa of the box
 * @param _y2 Right ordinate of the box
 * @param _c Color to use for drawing the bar
 */
/* <usermanual>
@keyword BAR

@english

The ''BAR'' instruction will draw a filled rectangle on the screen, specifying the 
coordinates of its opposite corners. The ''x1'' and ''y1'' are the left top
coordinates, while the ''x2'' and ''y2'' are the right bottom coordinates.

The fill color could be the one predefined, or specified by additional parameter.
The start or the final coordinates can be omitted: in this case, ugBASIC will draw, 
respectively, starting from the last drawn position and arriving at the last drawn 
position.

Drawing (and filling) rectangles is a common operation in graphics. A dedicated command would 
make the code more concise and readable. Filled rectangles can be used to create buttons, 
text boxes, and other interface elements. The ''BAR'' command could be used as a basis 
for creating more complex shapes.

@italian

L'istruzione ''BAR'' disegnerà un rettangolo pieno sullo schermo, specificando 
le coordinate dei suoi angoli opposti. ''x1'' e ''y1'' sono le coordinate in alto 
a sinistra, mentre ''x2'' e ''y2'' sono le coordinate in basso a destra.
Il colore di riempimento potrebbe essere quello predefinito o specificato da un 
parametro aggiuntivo.

Le coordinate di inizio o fine possono essere omesse: in questo caso, ugBASIC disegnerà, 
rispettivamente, partendo dall'ultima posizione disegnata e arrivando all'ultima posizione
disegnata.

Disegnare (e riempire) rettangoli è un'operazione comune nella grafica. Un comando 
dedicato renderebbe il codice più conciso e leggibile. I rettangoli pieni possono 
essere utilizzati per creare pulsanti, caselle di testo e altri elementi 
dell'interfaccia. Il comando ''BAR'' potrebbe essere utilizzato come base per 
creare forme più complesse.

@syntax BAR [x1], [y1], [x2], [y2], [c]
@syntax BAR [x1], [y1] TO [x2], [y2]
@syntax BAR TO [x2], [y2][, c ]

@example BAR 10,10,100,100,WHITE
@example BAR TO 100,100
@example BAR ,10 TO ,100

@usedInExample graphics_lines_03.bas

@target all
</usermanual> */
void bar( Environment * _environment, char * _x0, char * _y0, char * _x1, char * _y1, char * _c, int _preserve_color ) {

    deploy_begin( bar );

        MAKE_LABEL

        Variable * x0 = variable_define( _environment, "bar__x0", VT_POSITION, 0 );
        Variable * y0 = variable_define( _environment, "bar__y0", VT_POSITION, 0 );
        Variable * x1 = variable_define( _environment, "bar__x1", VT_POSITION, 0 );
        Variable * y1 = variable_define( _environment, "bar__y1", VT_POSITION, 0 );
        Variable * c = variable_define( _environment, "bar__c", VT_COLOR, 0 );

        Variable * yOrdered = variable_less_than( _environment, y0->name, y1->name, 1 );
        Variable * y = variable_resident( _environment, VT_POSITION, "(y)" );
        
        char labelOrdered[MAX_TEMPORARY_STORAGE]; sprintf(labelOrdered, "%slo", label );

        cpu_bvneq( _environment, yOrdered->realName, labelOrdered );

        variable_move( _environment, y0->name, y->name );
        variable_move( _environment, y1->name, y0->name );
        variable_move( _environment, y->name, y1->name );

        cpu_label( _environment, labelOrdered );

        begin_for( _environment, y->name, y0->name, y1->name );
            draw( _environment, x0->name, y->name, x1->name, y->name, _c, _preserve_color );
        end_for( _environment );

    cpu_return( _environment );

    deploy_end( bar );

    Variable * x0 = variable_retrieve_or_define( _environment, _x0, VT_POSITION, 0 );
    Variable * y0 = variable_retrieve_or_define( _environment, _y0, VT_POSITION, 0 );
    Variable * x1 = variable_retrieve_or_define( _environment, _x1, VT_POSITION, 0 );
    Variable * y1 = variable_retrieve_or_define( _environment, _y1, VT_POSITION, 0 );
    Variable * c = NULL;
    if ( _c ) {
        c = variable_retrieve_or_define( _environment, _c, VT_COLOR, 0 );
    }

    Variable * dx0 = variable_retrieve( _environment, "bar__x0" );
    Variable * dy0 = variable_retrieve( _environment, "bar__y0" );
    Variable * dx1 = variable_retrieve( _environment, "bar__x1" );
    Variable * dy1 = variable_retrieve( _environment, "bar__y1" );
    Variable * dc = variable_retrieve( _environment, "bar__c" );

    variable_move( _environment, x0->name, dx0->name );
    variable_move( _environment, y0->name, dy0->name );
    variable_move( _environment, x1->name, dx1->name );
    variable_move( _environment, y1->name, dy1->name );

    if ( c ) {
        variable_move( _environment, c->name, dc->name );
    } else {
        variable_move( _environment, "PEN", dc->name );
    }

    cpu_call( _environment, "lib_bar");

}