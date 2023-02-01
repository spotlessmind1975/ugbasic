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
 * @brief Emit code for <strong>ELLIPSE</strong> command
 * 
 * @param _environment Current calling environment
 * @param _x Abscissa of the center of the ellipse
 * @param _y Ordinate of the center of the ellipse
 * @param _rx Horizontal radius of the ellipse
 * @param _ry Vertical radius of the ellipse
 * @param _c Color to be used to draw ellipse
 */
/* <usermanual>
@keyword ELLIPSE

@english
This command allows you to draw an ellipse with starting coordinates in ''(x,y)'' 
and radius ''rx'' for the horizontal component and ''ry'' for the vertical component. 
The color is indicated by the parameter ''c''. If the abscissa 
and/or ordinate is omitted, the last graphic position drawn will be used. In 
addition, the color can also be omitted and, if necessary, the last color set with the 
''PEN'' or ''INK'' command will be used.

@italian
Questo comando consente di disegnare una ellisse avente coordinate di partenza in 
''(x,y)'' e raggio orizzontale ''rx'' mentre avrà raggio verticale ''ry''. 
Il colore viene indicato dal parametro ''c''. Se 
l'ascissa e/o l'ordinata viene omessa, sarà utilizzata l'ultima posizione grafica 
disegnata. In più, anche il colore può essere omesso e, nel caso, sarà utilizzato 
l'ultimo colore impostato con il comando ''PEN'' o ''INK''.

@syntax ELLIPSE { [x] },{ [y] },[rx],[ry],[c] 
@syntax ELLIPSE { [x] },{ [y] },[rx],[ry] 

@example ELLIPSE 100,100,42,21
@example ELLIPSE ,,10,20,RED
@usedInExample graphics_clip_01.bas
@usedInExample graphics_shapes_03.bas

@target all
</usermanual> */
void ellipse( Environment * _environment, char * _x, char * _y, char * _rx, char * _ry, char * _c ) {

    Variable * six = variable_temporary( _environment, VT_POSITION, "(6)");
    variable_store( _environment, six->name, 6 );
    Variable * four = variable_temporary( _environment, VT_POSITION, "(4)");
    variable_store( _environment, four->name, 4 );
    Variable * two = variable_temporary( _environment, VT_POSITION, "(2)");
    variable_store( _environment, two->name, 2 );
    Variable * one = variable_temporary( _environment, VT_POSITION, "(1)");
    variable_store( _environment, one->name, 1 );
    Variable * zero = variable_temporary( _environment, VT_POSITION, "(0)");
    variable_store( _environment, zero->name, 0 );

    Variable * xCentre = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * yCentre = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    Variable * a = variable_retrieve_or_define( _environment, _rx, VT_POSITION, 0);
    Variable * b = variable_retrieve_or_define( _environment, _ry, VT_POSITION, 0);

    Variable * a2 = variable_temporary( _environment, VT_POSITION, "(a2)");
    Variable * b2 = variable_temporary( _environment, VT_POSITION, "(b2)");
    Variable * fa2 = variable_temporary( _environment, VT_POSITION, "(fa2)");
    Variable * fb2 = variable_temporary( _environment, VT_POSITION, "(fb2)");

    variable_move( _environment, variable_mul( _environment, a->name, a->name )->name, a2->name );
    variable_move( _environment, variable_mul( _environment, b->name, b->name )->name, b2->name );
    variable_move( _environment, variable_mul( _environment, four->name, a2->name )->name, fa2->name );
    variable_move( _environment, variable_mul( _environment, four->name, b2->name )->name, fb2->name );

    Variable * x = variable_temporary( _environment, VT_POSITION, "(x)");
    Variable * y = variable_temporary( _environment, VT_POSITION, "(y)");
    Variable * sigma = variable_temporary( _environment, VT_POSITION, "(sigma)");

    variable_store( _environment, x->name, 0 );
    variable_move( _environment, b->name, y->name );
    variable_move( _environment, 
        variable_add( _environment,
            variable_mul( _environment, two->name, b2->name )->name,
            variable_mul( _environment, 
                a2->name, 
                variable_sub( _environment, one->name, variable_mul( _environment, two->name, b->name )->name )->name 
            )->name
        )->name, 
        sigma->name );

    begin_while( _environment );
    begin_while_condition( _environment, 
        variable_less_than( _environment, 
            variable_mul( _environment, b2->name, x->name )->name,
            variable_mul( _environment, a2->name, y->name )->name,
            1
            )->name
    );

        plot( _environment, variable_add( _environment, x->name, xCentre->name )->name, variable_add( _environment, y->name, yCentre->name )->name, _c );
        plot( _environment, variable_sub( _environment, xCentre->name, x->name )->name, variable_add( _environment, y->name, yCentre->name )->name, _c );
        plot( _environment, variable_add( _environment, x->name, xCentre->name )->name, variable_sub( _environment, yCentre->name,  y->name )->name, _c );
        plot( _environment, variable_sub( _environment, xCentre->name, x->name )->name, variable_sub( _environment, yCentre->name,  y->name )->name, _c );

        if_then( _environment, variable_greater_than( _environment, sigma->name, zero->name, 1 ) ->name );
        variable_move( _environment,
            variable_add( _environment, 
                sigma->name,
                variable_mul( _environment,
                    fa2->name,
                    variable_sub( _environment, one->name, y->name )->name 
                )->name
            )->name,
            sigma->name
        );

        variable_decrement( _environment, y->name );
        end_if_then( _environment );

        variable_move( _environment,
            variable_add( _environment, 
                sigma->name,
                variable_mul( _environment,
                    b2->name,
                    variable_add( _environment, 
                        variable_mul( _environment, four->name, x->name )->name,
                        six->name
                    )->name 
                )->name 
            )->name,
            sigma->name
        );

        variable_increment( _environment, x->name );
    end_while( _environment );

    variable_move( _environment, a->name, x->name );
    variable_store( _environment, y->name, 0 );
    variable_move( _environment, 
        variable_add( _environment,
            variable_mul( _environment, two->name, a2->name )->name,
            variable_mul( _environment, 
                b2->name, 
                variable_sub( _environment, one->name, variable_mul( _environment, two->name, a->name )->name )->name 
            )->name
        )->name, 
        sigma->name );

    begin_while( _environment );
    begin_while_condition( _environment, 
        variable_less_than( _environment, 
            variable_mul( _environment, a2->name, y->name )->name,
            variable_mul( _environment, b2->name, x->name )->name,
            1
            )->name
    );

        plot( _environment, variable_add( _environment, x->name, xCentre->name )->name, variable_add( _environment, y->name, yCentre->name )->name, _c );
        plot( _environment, variable_sub( _environment, xCentre->name, x->name )->name, variable_add( _environment, y->name, yCentre->name )->name, _c );
        plot( _environment, variable_add( _environment, x->name, xCentre->name )->name, variable_sub( _environment, yCentre->name,  y->name )->name, _c );
        plot( _environment, variable_sub( _environment, xCentre->name, x->name )->name, variable_sub( _environment, yCentre->name,  y->name )->name, _c );

        if_then( _environment, variable_greater_than( _environment, sigma->name, zero->name, 1 ) ->name );
        variable_move( _environment,
            variable_add( _environment, 
                sigma->name,
                variable_mul( _environment,
                    fb2->name,
                    variable_sub( _environment, one->name, x->name )->name 
                )->name
            )->name,
            sigma->name
        );

        variable_decrement( _environment, x->name );
        end_if_then( _environment );

        variable_move( _environment,
            variable_add( _environment, 
                sigma->name,
                variable_mul( _environment,
                    a2->name,
                    variable_add( _environment, 
                        variable_mul( _environment, four->name, y->name )->name,
                        six->name
                    )->name 
                )->name 
            )->name,
            sigma->name
        );

        variable_increment( _environment, y->name );
    end_while( _environment );

}
