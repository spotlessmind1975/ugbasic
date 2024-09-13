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
 * @brief Emit code for <strong>CIRCLE</strong> command
 * 
 * @param _environment Current calling environment
 * @param _x Abscissa of the center of the circle
 * @param _y Ordinate of the center of the circle
 * @param _r Radius of the circle 
 * @param _c Color to be used to draw circle
 */
/* <usermanual>
@keyword CIRCLE

@english
This command allows you to draw a circle with starting coordinates in ''(x,y)'' 
and radius ''r''. The color is indicated by the parameter ''c''. If the abscissa 
and/or ordinate is omitted, the last graphic position drawn will be used. In 
addition, the color can also be omitted and, if necessary, the last color set with the 
''PEN'' or ''INK'' command will be used. There is also another syntax, that can be used 
to draw ellipses: you can give both the radii ''rx'' and ''ry'' in the color determined 
by ''fq'' (see ''HIRES''). 

@italian
Questo comando consente di disegnare un cerchio avente coordinate di partenza in 
''(x,y)'' e raggio ''r''. Il colore viene indicato dal parametro ''c''. Se 
l'ascissa e/o l'ordinata viene omessa, sarà utilizzata l'ultima posizione grafica 
disegnata. In più, anche il colore può essere omesso e, nel caso, sarà utilizzato 
l'ultimo colore impostato con il comando ''PEN'' o ''INK''. Esiste anche un'altra 
sintassi che può essere utilizzata per disegnare ellissi: è possibile specificare sia i 
raggi ''rx'' che ''ry'' nel colore determinato da ''fq'' (vedere ''HIRES'').

@syntax CIRCLE [x], [y], r[, c]
@syntax CIRCLE x, y, rx, ry[, c]

@example CIRCLE 100,100,42
@example CIRCLE 100,100,21,42
@example CIRCLE ,,21,RED
@usedInExample graphics_position_01.bas
@usedInExample graphics_position_02.bas
@usedInExample graphics_shapes_02.bas

@target all
</usermanual> */
void circle( Environment * _environment, char * _x, char * _y, char * _r, char * _c, int _preserve_color ) {

    Variable * xCentre = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * yCentre = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    Variable * r = variable_retrieve_or_define( _environment, _r, VT_POSITION, 0 );

    Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
    variable_move( _environment, r->name, x->name );
    Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );
    variable_store( _environment, y->name, 0 );
    Variable * p = variable_temporary( _environment, VT_SWORD, "(p)" );

    plot( _environment, variable_add( _environment, x->name, xCentre->name )->name, variable_add( _environment, y->name, yCentre->name )->name, _c, 0 );
    plot( _environment, variable_sub( _environment, xCentre->name, x->name )->name, variable_add( _environment, y->name, yCentre->name )->name, _c, 0 );
    plot( _environment, variable_add( _environment, x->name, xCentre->name )->name, variable_sub( _environment, yCentre->name,  y->name )->name, _c, 0 );
    plot( _environment, variable_sub( _environment, xCentre->name, x->name )->name, variable_sub( _environment, yCentre->name,  y->name )->name, _c, 0 );
    
    variable_move( _environment, variable_complement_const( _environment, r->name, 1 )->name, p->name );

      begin_while( _environment );  
      begin_while_condition( _environment, variable_greater_than( _environment, x->name, y->name, 1 )->name );  

        if_then( _environment, variable_less_than_const( _environment, p->name, 0, 1 )->name );
            variable_move( _environment, variable_add( _environment, variable_sl_const( _environment, y->name, 1 )->name, p->name )->name, p->name );
            variable_increment( _environment, p->name );
        else_if_then_label( _environment );              
        else_if_then( _environment, NULL );              
            variable_decrement( _environment, x->name );
            variable_move( _environment, variable_add( _environment, variable_sl_const( _environment, y->name, 1 )->name, p->name )->name, p->name );
            variable_move( _environment, variable_sub( _environment, p->name, variable_sl_const( _environment, x->name, 1 )->name )->name, p->name );
            variable_increment( _environment, p->name );
        end_if_then( _environment );

        if_then( _environment, variable_less_than( _environment, x->name, y->name, 0 )->name );
            exit_loop( _environment, 0 );
        end_if_then( _environment );

        plot( _environment, variable_add( _environment, x->name, xCentre->name )->name, variable_add( _environment, y->name, yCentre->name )->name, _c, _preserve_color );
        plot( _environment, variable_sub( _environment, xCentre->name, x->name )->name, variable_add( _environment, y->name, yCentre->name )->name, _c, _preserve_color );
        plot( _environment, variable_add( _environment, x->name, xCentre->name )->name, variable_sub( _environment, yCentre->name,  y->name )->name, _c, _preserve_color );
        plot( _environment, variable_sub( _environment, xCentre->name, x->name )->name, variable_sub( _environment, yCentre->name,  y->name )->name, _c, _preserve_color );
          
        //if_then( _environment, variable_compare_not( _environment, x->name, y->name )->name );
            plot( _environment, variable_add( _environment, y->name, xCentre->name )->name, variable_add( _environment, x->name, yCentre->name )->name, _c, _preserve_color );
            plot( _environment, variable_sub( _environment, xCentre->name, y->name )->name, variable_add( _environment, x->name, yCentre->name )->name, _c, _preserve_color );
            plot( _environment, variable_add( _environment, y->name, xCentre->name )->name, variable_sub( _environment, yCentre->name,  x->name )->name, _c, _preserve_color );
            plot( _environment, variable_sub( _environment, xCentre->name, y->name )->name, variable_sub( _environment, yCentre->name,  x->name )->name, _c, _preserve_color );

        //end_if_then( _environment );

        variable_increment( _environment, y->name );
                  
    end_while( _environment );

}
