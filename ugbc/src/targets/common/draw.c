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
 * @brief Emit ASM code to implement <strong>DRAW</strong> command
 * 
 * @param _environment Current calling environment
 * @param _x1 Left abscissa of the line
 * @param _y1 Left ordinate of the line
 * @param _x2 Right abscissa of the line
 * @param _y2 Right ordinate of the line
 * @param _c Color to use for drawing the line
 */
/* <usermanual>
@keyword DRAW

@english
This instruction draws aline on the screen, starting from the coordinates ''(x1, y1)''
to arrive at the coordinates ''(x2, y2)'', using the color ''c''. The start or the final
coordinates can be omitted: in this case, ugBASIC will draw, respectively, starting from 
the last drawn position and arriving at the last drawn position. If the color is 
omitted, the last color selected with the ''INK'' or ''PEN'' command will be used. 
Finally, the default line style is full but a 16 bit bitmask can be set with the ''SET LINE''
command.

@italian
Questa istruzione disegna un segmento di linea sullo schermo, a partire dalle coordinate ''(x1,y1)''
per arrivare alle coordinate ''(x2,y2)'', utilizzando il colore ''c''. Le coordinate di inizio o
quelle di fine possono essere omesse: in tal caso, ugBASIC disegnerà, rispettivamente, 
ùa partire dall'ultima posizione disegnata arrivando all'ultima posizione disegnata. 
Se il colore viene omesso sarà utilizzato l'ultimo colore selezionato con il comando ''INK'' 
oppure ''PEN'. Infine, lo stile della linea di default è pieno ma può essere impostata una 
bitmask di 16 bit con il comando ''SET LINE''.

@syntax DRAW { [x1] },{ [y1] } TO { [x2] },{ [x2] },{ [c] } 
@syntax DRAW { [x1] },{ [x1] } TO { [x1] },{ [x1] } 
@syntax DRAW TO { [x1] },{ [x1] },{ [c] } 
@syntax DRAW TO { [x1] },{ [x1] } 

@example DRAW 10,10 TO 100,100,WHITE
@example DRAW TO 100,100
@example DRAW ,10 TO ,100
@usedInExample graphics_color_01.bas
@usedInExample graphics_lines_01.bas
@usedInExample graphics_shapes_01.bas
@usedInExample graphics_shapes_02.bas
@usedInExample graphics_shapes_03.bas

@target all
</usermanual> */
void draw( Environment * _environment, char * _x0, char * _y0, char * _x1, char * _y1, char * _c ) {

    deploy_begin( draw );

        Variable * x0 = variable_retrieve_or_define( _environment, "draw__x0", VT_POSITION, 0 );
        Variable * y0 = variable_retrieve_or_define( _environment, "draw__y0", VT_POSITION, 0 );
        Variable * x1 = variable_retrieve_or_define( _environment, "draw__x1", VT_POSITION, 0 );
        Variable * y1 = variable_retrieve_or_define( _environment, "draw__y1", VT_POSITION, 0 );

        Variable * zero = variable_temporary( _environment, VT_POSITION, "(0)" );
        variable_store( _environment, zero->name, 0 );
        Variable * sixteen = variable_temporary( _environment, VT_BYTE, "(16)" );
        variable_store( _environment, sixteen->name, 16 );
        
        Variable * pattern = variable_retrieve( _environment, "LINE" );
        Variable * bit = variable_temporary( _environment, VT_BYTE, "(bit)" );
        Variable * fraction = variable_temporary( _environment, VT_POSITION, "(fraction)");
        Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
        Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );

        Variable * dx = variable_temporary( _environment, VT_POSITION, "(dx)");
        Variable * dy = variable_temporary( _environment, VT_POSITION, "(dy)");
        Variable * dx2 = variable_temporary( _environment, VT_POSITION, "(dx2)");
        Variable * dy2 = variable_temporary( _environment, VT_POSITION, "(dy2)");

        Variable * stepx = variable_temporary( _environment, VT_POSITION, "(stepx)");
        Variable * stepy = variable_temporary( _environment, VT_POSITION, "(stepy)");

        variable_move( _environment, x0->name, x->name );
        variable_move( _environment, y0->name, y->name );

        variable_move( _environment, variable_sub( _environment, x1->name, x0->name )->name, dx->name );
        
        variable_move( _environment, variable_sub( _environment, y1->name, y0->name )->name, dy->name );

        if_then( _environment, variable_less_than( _environment, dy->name, zero->name, 0 )->name );
            variable_move( _environment, variable_sub( _environment, zero->name, dy->name )->name, dy->name );
            variable_store( _environment, stepy->name, -1 );
        else_if_then_label( _environment );
        else_if_then( _environment, NULL );
        variable_store( _environment, stepy->name, 1 );
        end_if_then( _environment );
        if_then( _environment, variable_less_than( _environment, dx->name, zero->name, 0 )->name );
            variable_move( _environment, variable_sub( _environment, zero->name, dx->name )->name, dx->name );
            variable_store( _environment, stepx->name, -1 );
        else_if_then_label( _environment );
        else_if_then( _environment, NULL );
            variable_store( _environment, stepx->name, 1 );
        end_if_then( _environment );
        variable_move_naked( _environment, dy->name, dy2->name );
        dy2 = variable_mul2_const( _environment, dy2->name, 1 );
        variable_move_naked( _environment, dx->name, dx2->name );
        dx2 = variable_mul2_const( _environment, dx2->name, 1 );
        if_then( _environment, variable_bit( _environment, pattern->name, bit->name )->name );
            plot( _environment, x->name, y->name, _c );
        end_if_then( _environment );
        variable_increment( _environment, bit->name );
        if_then( _environment, variable_compare( _environment, bit->name, sixteen->name )->name );
            variable_store( _environment, bit->name, 0 );
        end_if_then( _environment );
        if_then( _environment, variable_greater_than( _environment, dx2->name, dy2->name, 0 )->name );
            variable_move( _environment, variable_sub( _environment, dy2->name, dx->name)->name, fraction->name);
            begin_while( _environment );
            begin_while_condition( _environment, variable_compare_not( _environment, x->name, x1->name )->name );
                variable_move( _environment, variable_add( _environment, x->name, stepx->name )->name, x->name );
                if_then( _environment, variable_greater_than( _environment, fraction->name, zero->name, 1 )->name );
                    variable_move( _environment, variable_add( _environment, y->name, stepy->name )->name, y->name );
                    variable_move( _environment, variable_sub( _environment, fraction->name, dx2->name )->name, fraction->name );
                end_if_then( _environment );
                variable_move( _environment, variable_add( _environment, fraction->name, dy2->name )->name, fraction->name );
                if_then( _environment, variable_bit( _environment, pattern->name, bit->name )->name );
                    plot( _environment, x->name, y->name, _c );
                end_if_then( _environment );
                variable_increment( _environment, bit->name );
                if_then( _environment, variable_compare( _environment, bit->name, sixteen->name )->name );
                    variable_store( _environment, bit->name, 0 );
                end_if_then( _environment );
            end_while( _environment );
        else_if_then_label( _environment );
        else_if_then( _environment, NULL );
            variable_move( _environment, variable_sub( _environment, dx2->name, dy->name)->name, fraction->name);
            begin_while( _environment );
            begin_while_condition( _environment, variable_compare_not( _environment, y->name, y1->name )->name );
                if_then( _environment, variable_greater_than( _environment, fraction->name, zero->name, 1 )->name );
                    variable_move( _environment, variable_add( _environment, x->name, stepx->name )->name, x->name );
                    variable_move( _environment, variable_sub( _environment, fraction->name, dy2->name )->name, fraction->name );
                end_if_then( _environment );
                variable_move( _environment, variable_add( _environment, y->name, stepy->name )->name, y->name );
                variable_move( _environment, variable_add( _environment, fraction->name, dx2->name )->name, fraction->name );
                if_then( _environment, variable_bit( _environment, pattern->name, bit->name )->name );
                    plot( _environment, x->name, y->name, _c );
                end_if_then( _environment );
                variable_increment( _environment, bit->name );
                if_then( _environment, variable_compare( _environment, bit->name, sixteen->name )->name );
                    variable_store( _environment, bit->name, 0 );
                end_if_then( _environment );
            end_while( _environment );
    end_if_then( _environment );

    cpu_return( _environment );

    deploy_end( draw );

    Variable * x0 = variable_retrieve_or_define( _environment, _x0, VT_POSITION, 0 );
    Variable * y0 = variable_retrieve_or_define( _environment, _y0, VT_POSITION, 0 );
    Variable * x1 = variable_retrieve_or_define( _environment, _x1, VT_POSITION, 0 );
    Variable * y1 = variable_retrieve_or_define( _environment, _y1, VT_POSITION, 0 );

    Variable * dx0 = variable_retrieve( _environment, "draw__x0" );
    Variable * dy0 = variable_retrieve( _environment, "draw__y0" );
    Variable * dx1 = variable_retrieve( _environment, "draw__x1" );
    Variable * dy1 = variable_retrieve( _environment, "draw__y1" );

    variable_move( _environment, x0->name, dx0->name );
    variable_move( _environment, y0->name, dy0->name );
    variable_move( _environment, x1->name, dx1->name );
    variable_move( _environment, y1->name, dy1->name );

    cpu_call( _environment, "lib_draw");

}