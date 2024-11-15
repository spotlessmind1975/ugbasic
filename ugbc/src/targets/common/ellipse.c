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

@syntax ELLIPSE [x],[y],[rx],[ry][, c] 

@example ELLIPSE 100,100,42,21
@example ELLIPSE ,,10,20,RED
@usedInExample graphics_clip_01.bas
@usedInExample graphics_shapes_03.bas

@seeAlso CIRCLE

</usermanual> */
void ellipse( Environment * _environment, char * _x, char * _y, char * _rx, char * _ry, char * _c, int _preserve_color ) {

    deploy_begin( ellipse );

        Variable * xc = variable_define( _environment, "ellipse__xc", VT_POSITION, 0 );
        Variable * yc = variable_define( _environment, "ellipse__yc", VT_POSITION, 0 );
        Variable * rx = variable_define( _environment, "ellipse__rx", VT_POSITION, 0 );
        Variable * ry = variable_define( _environment, "ellipse__ry", VT_POSITION, 0 );
        Variable * c = variable_define( _environment, "ellipse__c", VT_POSITION, 0 );

        // forCondition
        Variable * forCondition = variable_temporary( _environment, VT_SBYTE, "(forCondition)" );

        // one
        Variable * one = variable_temporary( _environment, VT_POSITION, "(one)" );
        variable_store( _environment, one->name, 1 );
        // six
        Variable * six = variable_temporary( _environment, VT_POSITION, "(six)" );
        variable_store( _environment, six->name, 6 );

        // int a2 = a∗a
        Variable * a2 = variable_temporary( _environment, VT_POSITION, "(a2)" );
        variable_move( _environment, variable_mul( _environment, rx->name, rx->name )->name, a2->name );
        //  int b2 = b∗b
        Variable * b2 = variable_temporary( _environment, VT_POSITION, "(b2)" );
        variable_move( _environment, variable_mul( _environment, ry->name, ry->name )->name, b2->name );
        // int  fa2 = 4∗a2
        Variable * fa2 = variable_temporary( _environment, VT_POSITION, "(fa2)" );
        variable_move( _environment, variable_mul2_const( _environment, a2->name, 4 )->name, fa2->name );

        // int x
        // for ( x = 0
        Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
        variable_store( _environment, x->name, 0 );
        // int y
        // for ( y = b
        Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );
        variable_move( _environment, ry->name, y->name );
        // int sigma
        // for ( sigma = 2∗b2+a2∗(1−2∗b)
        Variable * sigma = variable_temporary( _environment, VT_POSITION, "(sigma)" );
        variable_move( _environment, 
                variable_add( _environment,
                    variable_mul2_const( _environment,
                        b2->name,
                        2
                        )->name,
                    variable_mul( _environment,
                        a2->name,
                        variable_sub( _environment,
                            one->name,
                            variable_mul2_const( _environment,
                                ry->name,
                                2
                            )->name
                        )->name
                    )->name              
                )->name,
                    sigma->name );

        MAKE_LABEL

        char forLabel1[MAX_TEMPORARY_STORAGE];
        sprintf( forLabel1, "%sfor1", label );
        char endForLabel1[MAX_TEMPORARY_STORAGE];
        sprintf( endForLabel1, "%sendfor1", label );

        cpu_label( _environment, forLabel1 );

        // for ( ; b2∗x <= a2∗y ; )
        variable_move( _environment, variable_less_than( _environment, 
            variable_mul( _environment, b2->name, x->name )->name,
            variable_mul( _environment, a2->name, y->name )->name,
            1 )->name, forCondition->name );

        cpu_compare_and_branch_8bit_const( _environment, forCondition->realName, 0x00, endForLabel1, 1 );

            // DrawPixel ( xc+x , yc+y ) ;
            plot( _environment, 
                variable_add( _environment, xc->name, x->name )->name, 
                variable_add( _environment, yc->name, y->name )->name, 
                c->name, 
                _preserve_color );

            // DrawPixel ( xc−x , yc+y ) ;
            plot( _environment, 
                variable_sub( _environment, xc->name, x->name )->name, 
                variable_add( _environment, yc->name, y->name )->name, 
                c->name, 
                _preserve_color );

            // DrawPixel ( xc+x , yc−y ) ;
            plot( _environment, 
                variable_add( _environment, xc->name, x->name )->name, 
                variable_sub( _environment, yc->name, y->name )->name, 
                c->name, 
                _preserve_color );

            // DrawPixel ( xc−x , yc−y ) ;
            plot( _environment, 
                variable_sub( _environment, xc->name, x->name )->name, 
                variable_sub( _environment, yc->name, y->name )->name, 
                c->name, 
                _preserve_color );

            ;

            // wait_key( _environment, 0 );

            // if ( sigma >= 0 )
            if_then( _environment, variable_greater_than_const( _environment, sigma->name, 0, 1 )->name );
                // sigma += fa2∗(1−y) ;
                variable_add_inplace_vars( _environment, 
                    sigma->name,
                    variable_mul( _environment,
                        fa2->name,
                        variable_sub( _environment,
                            one->name,
                            y->name)->name
                    )->name
                );

                // y−−;
                variable_decrement( _environment, y->name );

            end_if_then( _environment );

            // sig a += b2∗(4∗x+6);
            variable_add_inplace_vars( _environment, 
                sigma->name,
                variable_mul( _environment,
                    b2->name,
                    variable_add( _environment,
                        variable_mul2_const( _environment,
                            x->name,
                            4 )->name,
                        six->name
                        )->name
                )->name
            );

            // for ( ... x++)
            variable_increment( _environment, x->name );

            cpu_jump( _environment, forLabel1 );

        cpu_label( _environment, endForLabel1 );

        //////////////////////////////////////////////////////////////////////

        // int  fb2 = 4∗b2
        Variable * fb2 = variable_temporary( _environment, VT_POSITION, "(fb2)" );
        variable_move( _environment, variable_mul2_const( _environment, b2->name, 4 )->name, fb2->name );

        char forLabel2[MAX_TEMPORARY_STORAGE];
        sprintf( forLabel2, "%sfor2", label );
        char endForLabel2[MAX_TEMPORARY_STORAGE];
        sprintf( endForLabel2, "%sendfor2", label );

        // for( x=a
        variable_move( _environment, rx->name, x->name );

        // for( y=0
        variable_store( _environment, y->name, 0 );

        // for( sigma = 2∗a2+b2∗(1−2∗a )
        variable_move( _environment, 
                variable_add( _environment,
                    variable_mul2_const( _environment,
                        a2->name,
                        2
                        )->name,
                    variable_mul( _environment,
                        b2->name,
                        variable_sub( _environment,
                            one->name,
                            variable_mul2_const( _environment,
                                rx->name,
                                2
                            )->name
                        )->name
                    )->name              
                )->name,
                    sigma->name );

        cpu_label( _environment, forLabel2 );

        // for(  a2∗y <= b2∗x )
        variable_move( _environment, variable_less_than( _environment, 
            variable_mul( _environment, a2->name, y->name )->name,
            variable_mul( _environment, b2->name, x->name )->name,
            1 )->name, forCondition->name );

        cpu_compare_and_branch_8bit_const( _environment, forCondition->realName, 0x00, endForLabel2, 1 );

            // DrawPixel ( xc+x , yc+y ) ;
            plot( _environment, 
                variable_add( _environment, xc->name, x->name )->name, 
                variable_add( _environment, yc->name, y->name )->name, 
                c->name, 
                _preserve_color );

            // DrawPixel ( xc−x , yc+y ) ;
            plot( _environment, 
                variable_sub( _environment, xc->name, x->name )->name, 
                variable_add( _environment, yc->name, y->name )->name, 
                c->name, 
                _preserve_color );

            // DrawPixel ( xc+x , yc−y ) ;
            plot( _environment, 
                variable_add( _environment, xc->name, x->name )->name, 
                variable_sub( _environment, yc->name, y->name )->name, 
                c->name, 
                _preserve_color );

            // DrawPixel ( xc−x , yc−y ) ;
            plot( _environment, 
                variable_sub( _environment, xc->name, x->name )->name, 
                variable_sub( _environment, yc->name, y->name )->name, 
                c->name, 
                _preserve_color );

            ;

            // if ( sigma >= 0 )
            if_then( _environment, variable_greater_than_const( _environment, sigma->name, 0, 1 )->name );
                // sigma += fb2∗(1−x);
                variable_add_inplace_vars( _environment, 
                    sigma->name,
                    variable_mul( _environment,
                        fb2->name,
                        variable_sub( _environment,
                            one->name,
                            x->name)->name
                    )->name
                );

                // x−−;
                variable_decrement( _environment, x->name );

            end_if_then( _environment );

            // sigma += a2∗(4∗y+6);
            variable_add_inplace_vars( _environment, 
                sigma->name,
                variable_mul( _environment,
                    a2->name,
                    variable_add( _environment,
                        variable_mul2_const( _environment,
                            y->name,
                            4 )->name,
                        six->name
                        )->name
                )->name
            );

            // for ( ... y++)
            variable_increment( _environment, y->name );

        cpu_jump( _environment, forLabel2 );

        cpu_label( _environment, endForLabel2 );

        cpu_return( _environment );

    deploy_end( ellipse );

    Variable * xc = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * yc = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
    Variable * rx = variable_retrieve_or_define( _environment, _rx, VT_POSITION, 0 );
    Variable * ry = variable_retrieve_or_define( _environment, _ry, VT_POSITION, 0 );
    Variable * c = NULL;
    if ( _c ) {
        c = variable_retrieve_or_define( _environment, _c, VT_COLOR, 0 );
    }

    Variable * pxc = variable_retrieve( _environment, "ellipse__xc" );
    Variable * pyc = variable_retrieve( _environment, "ellipse__yc" );
    Variable * prx = variable_retrieve( _environment, "ellipse__rx" );
    Variable * pry = variable_retrieve( _environment, "ellipse__ry" );
    Variable * pc = variable_retrieve( _environment, "ellipse__c" );

    variable_move( _environment, xc->name, pxc->name );
    variable_move( _environment, yc->name, pyc->name );
    variable_move( _environment, rx->name, prx->name );
    variable_move( _environment, ry->name, pry->name );

    if ( c ) {
        variable_move( _environment, c->name, pc->name );
    } else {
        variable_move( _environment, "PEN", pc->name );
    }

    cpu_call( _environment, "lib_ellipse");

}
