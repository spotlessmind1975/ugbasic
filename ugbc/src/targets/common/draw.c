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

void draw( Environment * _environment, char * _x1, char * _y1, char * _x2, char * _y2, char * _c ) {

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

}