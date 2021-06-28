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

void draw( Environment * _environment, char * _x0, char * _y0, char * _x1, char * _y1, char * _c ) {

    Variable * zero = variable_temporary( _environment, VT_POSITION, "(0)" );
    variable_store( _environment, zero->name, 0 );
    Variable * sixteen = variable_temporary( _environment, VT_BYTE, "(16)" );
    variable_store( _environment, sixteen->name, 16 );
    
    Variable * pattern = variable_retrieve( _environment, "LINE" );
    Variable * bit = variable_temporary( _environment, VT_BYTE, "(bit)" );
    Variable * fraction = variable_temporary( _environment, VT_POSITION, "(fraction)");
    Variable * x0 = variable_retrieve_or_define( _environment, _x0, VT_POSITION, 0 );
    Variable * y0 = variable_retrieve_or_define( _environment, _y0, VT_POSITION, 0 );
    Variable * x1 = variable_retrieve_or_define( _environment, _x1, VT_POSITION, 0 );
    Variable * y1 = variable_retrieve_or_define( _environment, _y1, VT_POSITION, 0 );
    Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
    Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );

    // int dx, dy;
    Variable * dx = variable_temporary( _environment, VT_POSITION, "(dx)");
    Variable * dy = variable_temporary( _environment, VT_POSITION, "(dy)");
    Variable * dx2 = variable_temporary( _environment, VT_POSITION, "(dx2)");
    Variable * dy2 = variable_temporary( _environment, VT_POSITION, "(dy2)");

    // int stepx, stepy;
    Variable * stepx = variable_temporary( _environment, VT_POSITION, "(stepx)");
    Variable * stepy = variable_temporary( _environment, VT_POSITION, "(stepy)");

    variable_move( _environment, x0->name, x->name );
    variable_move( _environment, y0->name, y->name );

    // dx = x1 - x0;
    variable_move( _environment, variable_sub( _environment, x1->name, x0->name )->name, dx->name );
    
    // dy = y1 - y0;
    variable_move( _environment, variable_sub( _environment, y1->name, y0->name )->name, dy->name );

    // if (dy < 0)
    // {
    if_then( _environment, variable_less_than( _environment, dy->name, zero->name, 0 )->name );
    //     dy = -dy;
        variable_move( _environment, variable_sub( _environment, zero->name, dy->name )->name, dy->name );
    //     stepy = -1;
        variable_store( _environment, stepy->name, -1 );
    // }
    else_if_then( _environment, NULL );
    // else
    // {
    //     stepy = 1;
        variable_store( _environment, stepy->name, 1 );
    // }
    end_if_then( _environment );
    // if (dx < 0)
    // {
    if_then( _environment, variable_less_than( _environment, dx->name, zero->name, 0 )->name );
    //     dx = -dx;
        variable_move( _environment, variable_sub( _environment, zero->name, dx->name )->name, dx->name );
    //     stepx = -1;
        variable_store( _environment, stepx->name, -1 );
    // }
    else_if_then( _environment, NULL );
    // else
    // {
    //     stepx = 1;
        variable_store( _environment, stepx->name, 1 );
    // }
    end_if_then( _environment );
    // dy <<= 1; /* dy is now 2*dy */
    variable_move_naked( _environment, dy->name, dy2->name );
    variable_mul2_const( _environment, dy2->name, 1 );
    // dx <<= 1; /* dx is now 2*dx */
    variable_move_naked( _environment, dx->name, dx2->name );
    variable_mul2_const( _environment, dx2->name, 1 );
    // if ((0 <= x0) && (x0 < RDim) && (0 <= y0) && (y0 < RDim))
    //     theRaster[x0][y0] = 1;
    if_then( _environment, variable_bit( _environment, pattern->name, bit->name )->name );
        // cout << "(" << x << "," << y << ")\n";
        plot( _environment, x->name, y->name, _c );
    end_if_then( _environment );
    variable_increment( _environment, bit->name );
    if_then( _environment, variable_compare( _environment, bit->name, sixteen->name )->name );
        variable_store( _environment, bit->name, 0 );
    end_if_then( _environment );
    // 16 if (dx > dy)
    // {
    if_then( _environment, variable_greater_than( _environment, dx2->name, dy2->name, 0 )->name );
    //     int fraction = dy - (dx >> 1);
        variable_move( _environment, variable_sub( _environment, dy2->name, dx->name)->name, fraction->name);
    //     while (x0 != x1)
    //     {
        begin_while( _environment );
        begin_while_condition( _environment, variable_compare_not( _environment, x->name, x1->name )->name );
    //         x0 += stepx;
            variable_move( _environment, variable_add( _environment, x->name, stepx->name )->name, x->name );
    //         if (fraction >= 0)
    //         {
            if_then( _environment, variable_greater_than( _environment, fraction->name, zero->name, 1 )->name );
    //             y0 += stepy;
                variable_move( _environment, variable_add( _environment, y->name, stepy->name )->name, y->name );
    //             fraction -= dx;
                variable_move( _environment, variable_sub( _environment, fraction->name, dx2->name )->name, fraction->name );
    //         }
            end_if_then( _environment );
    //         fraction += dy;
            variable_move( _environment, variable_add( _environment, fraction->name, dy2->name )->name, fraction->name );
    //         if ((0 <= x0) && (x0 < RDim) && (0 <= y0) && (y0 < RDim))
    //             theRaster[x0][y0] = 1;
            if_then( _environment, variable_bit( _environment, pattern->name, bit->name )->name );
                // cout << "(" << x << "," << y << ")\n";
                plot( _environment, x->name, y->name, _c );
            end_if_then( _environment );
            variable_increment( _environment, bit->name );
            if_then( _environment, variable_compare( _environment, bit->name, sixteen->name )->name );
                variable_store( _environment, bit->name, 0 );
            end_if_then( _environment );
    //     }
        end_while( _environment );
    // }
    else_if_then( _environment, NULL );
    // else
    // {
    //     int fraction = dx - (dy >> 1);
        variable_move( _environment, variable_sub( _environment, dx2->name, dy->name)->name, fraction->name);
    //     while (y0 != y1)
    //     {
        begin_while( _environment );
        begin_while_condition( _environment, variable_compare_not( _environment, y->name, y1->name )->name );
    //         if (fraction >= 0)
    //         {
            if_then( _environment, variable_greater_than( _environment, fraction->name, zero->name, 1 )->name );
    //             17 x0 += stepx;
                variable_move( _environment, variable_add( _environment, x->name, stepx->name )->name, x->name );
    //             fraction -= dy;
                variable_move( _environment, variable_sub( _environment, fraction->name, dy2->name )->name, fraction->name );
    //         }
            end_if_then( _environment );
    //         y0 += stepy;
            variable_move( _environment, variable_add( _environment, y->name, stepy->name )->name, y->name );
    //         fraction += dx;
            variable_move( _environment, variable_add( _environment, fraction->name, dx2->name )->name, fraction->name );
    //         if ((0 <= x0) && (x0 < RDim) && (0 <= y0) && (y0 < RDim))
    //             theRaster[x0][y0] = 1;
            if_then( _environment, variable_bit( _environment, pattern->name, bit->name )->name );
                // cout << "(" << x << "," << y << ")\n";
                plot( _environment, x->name, y->name, _c );
            end_if_then( _environment );
            variable_increment( _environment, bit->name );
            if_then( _environment, variable_compare( _environment, bit->name, sixteen->name )->name );
                variable_store( _environment, bit->name, 0 );
            end_if_then( _environment );
    //     }
        end_while( _environment );
    // }
    end_if_then( _environment );



/*
    Variable * x1 = variable_retrieve_or_define( _environment, _x1, VT_POSITION, 0 );
    Variable * y1 = variable_retrieve_or_define( _environment, _y1, VT_POSITION, 0 );
    Variable * x2 = variable_retrieve_or_define( _environment, _x2, VT_POSITION, 0 );
    Variable * y2 = variable_retrieve_or_define( _environment, _y2, VT_POSITION, 0 );
    Variable * pattern = variable_retrieve( _environment, "LINE" );
    Variable * bit = variable_temporary( _environment, VT_BYTE, "(bit)" );
    Variable * m_new = variable_temporary( _environment, VT_POSITION, "(m_new)" );
    Variable * slope_error_new = variable_temporary( _environment, VT_POSITION, "(slope_error_new)" );
    Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
    Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );
    Variable * zero = variable_temporary( _environment, VT_POSITION, "(0)" );
    Variable * sixteen = variable_temporary( _environment, VT_BYTE, "(16)" );

    variable_store( _environment, zero->name, 0 );
    variable_store( _environment, bit->name, 0 );
    variable_store( _environment, sixteen->name, 16 );

    if_then( _environment, variable_compare( _environment, x1->name, x2->name )->name );
        variable_move( _environment, x1->name, x->name );
        begin_for( _environment, y->name, y1->name, y2->name );

            if_then( _environment, variable_bit( _environment, pattern->name, bit->name )->name );
                // cout << "(" << x << "," << y << ")\n";
                plot( _environment, x->name, y->name, _c );
            end_if_then( _environment );

            variable_increment( _environment, bit->name );
            if_then( _environment, variable_compare( _environment, bit->name, sixteen->name )->name );
                variable_store( _environment, bit->name, 0 );
            end_if_then( _environment );

        end_for( _environment );
    else_if_then( _environment, NULL );

        // int m_new = 2 * (y2 - y1);
        variable_move( _environment, variable_mul2_const( _environment, variable_sub( _environment, y2->name, y1->name)->name , 1 )->name, m_new->name );

        // int slope_error_new = m_new - (x2 - x1);
        variable_move( _environment, variable_sub( _environment, m_new->name, variable_sub( _environment, x2->name, x1->name)->name )->name, slope_error_new->name );

    // for (int x = x1, y = y1; x <= x2; x++)
    //   {
        variable_move( _environment, y1->name, y->name );
        begin_for( _environment, x->name, x1->name, x2->name );

            if_then( _environment, variable_bit( _environment, pattern->name, bit->name )->name );
                // cout << "(" << x << "," << y << ")\n";
                plot( _environment, x->name, y->name, _c );
            end_if_then( _environment );

            variable_increment( _environment, bit->name );
            if_then( _environment, variable_compare( _environment, bit->name, sixteen->name )->name );
                variable_store( _environment, bit->name, 0 );
            end_if_then( _environment );

            // Add slope to increment angle formed
            // slope_error_new += m_new;
            variable_move( _environment, variable_add( _environment, slope_error_new->name, m_new->name)->name, slope_error_new->name );

            // Slope error reached limit, time to
            // increment y and update slope error.
            // if (slope_error_new >= 0)
            // {
            if_then( _environment, variable_greater_than( _environment, slope_error_new->name, zero->name, 1 )->name );
                // y++;
                variable_increment( _environment, y->name );
                // slope_error_new  -= 2 * (x2 - x1);
                variable_move( _environment, variable_sub( _environment, slope_error_new->name, variable_mul2_const( _environment, variable_sub( _environment, x2->name, x1->name )->name, 1 )->name )->name, slope_error_new->name );
            // }
            end_if_then( _environment );
        // }
        end_for( _environment );
    end_if_then( _environment );
*/
}