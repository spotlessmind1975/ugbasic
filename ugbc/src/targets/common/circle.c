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

void circle( Environment * _environment, char * _x, char * _y, char * _r, char * _c ) {

    if ( !_x ) {
        _x = variable_retrieve( _environment, "XGR" )->name;
    }

    if ( !_y ) {
        _y = variable_retrieve( _environment, "YGR" )->name;
    }

    Variable * xCentre = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * yCentre = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    Variable * r = variable_retrieve_or_define( _environment, _r, VT_POSITION, 0 );
    Variable * zero = variable_temporary( _environment, VT_POSITION, "0" );
    variable_store( _environment, zero->name, 0 );
    Variable * one = variable_temporary( _environment, VT_POSITION, "1" );
    variable_store( _environment, one->name, 1 );
    Variable * two = variable_temporary( _environment, VT_POSITION, "2" );
    variable_store( _environment, two->name, 2 );

    // int x = r, y = 0;

    Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
    variable_move( _environment, r->name, x->name );
    Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );
    variable_store( _environment, y->name, 0 );
    Variable * p = variable_temporary( _environment, VT_SWORD, "(p)" );

      
    // Printing the initial point on the axes 
    // after translation
    // printf("(%d, %d) ", x + x_centre, y + y_centre);
      
    //print( _environment, variable_add( _environment, x->name, xCentre->name )->name, 0 );
    //print_tab( _environment, 0 );
    //print( _environment, variable_add( _environment, y->name, yCentre->name )->name, 1 );
    plot( _environment, variable_add( _environment, x->name, xCentre->name )->name, variable_add( _environment, y->name, yCentre->name )->name, _c );
    //printf("(%d, %d) ", -x + x_centre, y + y_centre);
    plot( _environment, variable_sub( _environment, xCentre->name, x->name )->name, variable_add( _environment, y->name, yCentre->name )->name, _c );
    //printf("(%d, %d) ", x + x_centre, -y + y_centre);
    plot( _environment, variable_add( _environment, x->name, xCentre->name )->name, variable_sub( _environment, yCentre->name,  y->name )->name, _c );
    //printf("(%d, %d)\n", -x + x_centre, -y + y_centre);
    plot( _environment, variable_sub( _environment, xCentre->name, x->name )->name, variable_sub( _environment, yCentre->name,  y->name )->name, _c );

    // Initialising the value of P
    // int P = 1 - r;
    
    variable_move( _environment, variable_sub( _environment, one->name, r->name )->name, p->name );

    //while (x > y)
      begin_while( _environment );  
      begin_while_condition( _environment, variable_greater_than( _environment, x->name, y->name, 1 )->name );  

    //{ 

        // y++;

        variable_increment( _environment, y->name );
                  
        // Mid-point is inside or on the perimeter
        // if (P <= 0)
        if_then( _environment, variable_less_than( _environment, p->name, zero->name, 1 )->name );
            // P = P + 2*y + 1;
            variable_move( _environment, variable_add( _environment, variable_mul( _environment, two->name, y->name )->name, p->name )->name, p->name );
            variable_increment( _environment, p->name );
        // Mid-point is outside the perimeter
        // else
        else_if_then( _environment, NULL );              
        // {
            // x--;
            variable_decrement( _environment, x->name );
            // P = P + 2*y - 2*x + 1;
            variable_move( _environment, variable_add( _environment, variable_mul( _environment, two->name, y->name )->name, p->name )->name, p->name );
            variable_move( _environment, variable_sub( _environment, p->name, variable_mul( _environment, two->name, x->name )->name )->name, p->name );
            variable_increment( _environment, p->name );
        //}
        end_if_then( _environment );
          
        // All the perimeter points have already been printed
        // if (x < y)
        if_then( _environment, variable_less_than( _environment, x->name, y->name, 0 )->name );
            // break;
            exit_loop( _environment, 0 );
        end_if_then( _environment );
          
        // Printing the generated point and its reflection
        // in the other octants after translation
        //printf("(%d, %d) ", x + x_centre, y + y_centre);
        
        //print( _environment, variable_add( _environment, x->name, xCentre->name )->name, 0 );
        //print_tab( _environment, 0 );
        //print( _environment, variable_add( _environment, y->name, yCentre->name )->name, 1 );

        plot( _environment, variable_add( _environment, x->name, xCentre->name )->name, variable_add( _environment, y->name, yCentre->name )->name, _c );
        //printf("(%d, %d) ", -x + x_centre, y + y_centre);
        plot( _environment, variable_sub( _environment, xCentre->name, x->name )->name, variable_add( _environment, y->name, yCentre->name )->name, _c );
        //printf("(%d, %d) ", x + x_centre, -y + y_centre);
        plot( _environment, variable_add( _environment, x->name, xCentre->name )->name, variable_sub( _environment, yCentre->name,  y->name )->name, _c );
        //printf("(%d, %d)\n", -x + x_centre, -y + y_centre);
        plot( _environment, variable_sub( _environment, xCentre->name, x->name )->name, variable_sub( _environment, yCentre->name,  y->name )->name, _c );
          
        // If the generated point is on the line x = y then 
        // the perimeter points have already been printed
        // if (x != y)
        // {
        if_then( _environment, variable_compare_not( _environment, x->name, y->name )->name );
            //print( _environment, variable_add( _environment, x->name, xCentre->name )->name, 0 );
            //print_tab( _environment, 0 );
            //print( _environment, variable_add( _environment, y->name, yCentre->name )->name, 1 );
            plot( _environment, variable_add( _environment, y->name, xCentre->name )->name, variable_add( _environment, x->name, yCentre->name )->name, _c );
            //printf("(%d, %d) ", -x + x_centre, y + y_centre);
            plot( _environment, variable_sub( _environment, xCentre->name, y->name )->name, variable_add( _environment, x->name, yCentre->name )->name, _c );
            //printf("(%d, %d) ", x + x_centre, -y + y_centre);
            plot( _environment, variable_add( _environment, y->name, xCentre->name )->name, variable_sub( _environment, yCentre->name,  x->name )->name, _c );
            //printf("(%d, %d)\n", -x + x_centre, -y + y_centre);
            plot( _environment, variable_sub( _environment, xCentre->name, y->name )->name, variable_sub( _environment, yCentre->name,  x->name )->name, _c );

        end_if_then( _environment );

        //     printf("(%d, %d) ", y + x_centre, x + y_centre);
        //     printf("(%d, %d) ", -y + x_centre, x + y_centre);
        //     printf("(%d, %d) ", y + x_centre, -x + y_centre);
        //     printf("(%d, %d)\n", -y + x_centre, -x + y_centre);
        // }
    // } 
    end_while( _environment );

}
