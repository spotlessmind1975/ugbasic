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
@keyword DRAW (instruction) 

The ''DRAW'' command allows you to draw line segments and rectangles 
on the screen, forming one of the basic building blocks for creating 
simple graphics. This command can be used to draw coordinate axes 
and data points, to create characters, environments, and objects, 
to draw windows, buttons, and other interface elements. 

It starts drawing from the coordinates ''(x1, y1)''
to arrive at the coordinates ''(x2, y2)'', using the color ''c''. 
The start or the final coordinates can be omitted: in this case, ugBASIC 
will draw, respectively, starting from the last drawn position and 
arriving at the last drawn position. If the color is omitted, the 
last color selected with the ''INK'' or ''PEN'' command will be used. 

The ''DRAW'' command offers several additional options to customize 
the drawing. After the color, that is optinal, you can put the letter
''B'' to draw a rectangle. The letters ''BF'' means that the
rectangle must be filled, too. Finally, the default line style is normally
"complete" but a 16 bit bitmask can be set with the ''SET LINE'' command.
You can also select the ''mode'' that can be ''PSET'' or ''PRESET''. If 
''PSET'' is used the line is drawn in the current foreground colour. 
If ''PRESET'', the line is drawn in the background colour.

The accuracy of the drawings is limited by the resolution of the screen,
and drawing many lines can slow down the program, especially on 8-bit computers.

@italian

Il comando ''DRAW'' consente di disegnare segmenti di linea e rettangoli 
sullo schermo, formando uno degli elementi di base per la creazione di 
semplici elementi grafici. Questo comando può essere utilizzato per disegnare 
assi di coordinate e punti dati, per creare personaggi, ambienti e oggetti, 
per disegnare finestre, pulsanti e altri elementi dell'interfaccia.

Inizia a disegnare dalle coordinate ''(x1, y1)'' per arrivare alle coordinate 
''(x2, y2)'', utilizzando il colore ''c''. Le coordinate di partenza o di 
arrivo possono essere omesse: in questo caso, ugBASIC disegnerà, 
rispettivamente, partendo dall'ultima posizione disegnata e arrivando 
all'ultima posizione disegnata. Se il colore viene omesso, 
verrà utilizzato l'ultimo colore selezionato con il comando 
''INK'' o ''PEN''.

Il comando ''DRAW'' offre diverse opzioni aggiuntive per personalizzare 
il disegno. Dopo il colore, che è facoltativo, puoi mettere la lettera 
''B'' per disegnare un rettangolo. Le lettere ''BF'' indicano che anche 
il rettangolo deve essere riempito. Infine, lo stile di linea predefinito 
è normalmente "completo", ma è possibile impostare una maschera di bit 
a 16 bit con il comando ''SET LINE''.

È anche possibile selezionare la ''mode'' che può essere ''PSET'' 
o ''PRESET''. Se si utilizza ''PSET'', la linea viene disegnata nel 
colore di primo piano corrente. Se ''PRESET'', la linea viene disegnata 
nel colore di sfondo.

La precisione dei disegni è limitata dalla risoluzione dello schermo 
e disegnare molte linee può rallentare il programma, specialmente 
su computer a 8 bit.

@syntax DRAW (x1,y1)-(x2,y2),c[,B[F]]
@syntax DRAW (x1,y1)-(x2,y2),c[,[mode]][,B[F]]
@syntax DRAW [x1], [y1] TO x2, y2[, c]
@syntax DRAW TO [y2],[y2][,c]

@usedInExample graphics_color_01.bas
@usedInExample graphics_lines_01.bas
@usedInExample graphics_shapes_01.bas
@usedInExample graphics_shapes_02.bas
@usedInExample graphics_shapes_03.bas

@alias LINE
@seeAlso BAR
@seeAlso BOX
@seeAlso SET LINE

@target all
</usermanual> */

/* <usermanual>
@keyword LINE

@english

@italian

@syntax LINE [x1], [y1] TO x2, y2[, c]
@syntax LINE TO x2, y2[, c]
@syntax LINE (x1,y1) - (x2,y2)[,mode]

@example LINE 10,10 TO 100,100,WHITE
@example LINE TO 100,100

@usedInExample graphics_color_01.bas
@usedInExample graphics_lines_01.bas
@usedInExample graphics_shapes_01.bas
@usedInExample graphics_shapes_02.bas
@usedInExample graphics_shapes_03.bas

@alias DRAW (instruction)

</usermanual> */
void draw( Environment * _environment, char * _x0, char * _y0, char * _x1, char * _y1, char * _c, int _preserve_color ) {

    deploy_begin( draw );

        Variable * x0 = variable_define( _environment, "draw__x0", VT_POSITION, 0 );
        Variable * y0 = variable_define( _environment, "draw__y0", VT_POSITION, 0 );
        Variable * x1 = variable_define( _environment, "draw__x1", VT_POSITION, 0 );
        Variable * y1 = variable_define( _environment, "draw__y1", VT_POSITION, 0 );
        Variable * c = variable_define( _environment, "draw__c", VT_COLOR, 0 );

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

        variable_store( _environment, bit->name, 0 );

        variable_move( _environment, x0->name, x->name );
        variable_move( _environment, y0->name, y->name );

        variable_move( _environment, variable_sub( _environment, x1->name, x0->name )->name, dx->name );
        
        variable_move( _environment, variable_sub( _environment, y1->name, y0->name )->name, dy->name );

        if_then( _environment, variable_less_than_const( _environment, dy->name, 0, 0 )->name );
            variable_move( _environment, variable_complement_const( _environment, dy->name, 0 )->name, dy->name );
            variable_store( _environment, stepy->name, -1 );
        else_if_then_label( _environment );
        else_if_then( _environment, NULL );
        variable_store( _environment, stepy->name, 1 );
        end_if_then( _environment );
        if_then( _environment, variable_less_than_const( _environment, dx->name, 0, 0 )->name );
            variable_move( _environment, variable_complement_const( _environment, dx->name, 0 )->name, dx->name );
            variable_store( _environment, stepx->name, -1 );
        else_if_then_label( _environment );
        else_if_then( _environment, NULL );
            variable_store( _environment, stepx->name, 1 );
        end_if_then( _environment );
        variable_move_naked( _environment, dy->name, dy2->name );
        dy2 = variable_sl_const( _environment, dy2->name, 1 );
        variable_move_naked( _environment, dx->name, dx2->name );
        dx2 = variable_sl_const( _environment, dx2->name, 1 );
        if ( _environment->lineNeeded ) {
            if_then( _environment, variable_bit( _environment, pattern->name, bit->name )->name );
        }        
               plot( _environment, x->name, y->name, c->name, _preserve_color );
        if ( _environment->lineNeeded ) {
            end_if_then( _environment );
        }
        variable_increment( _environment, bit->name );
        if_then( _environment, variable_compare_const( _environment, bit->name, 16 )->name );
            variable_store( _environment, bit->name, 0 );
        end_if_then( _environment );
        if_then( _environment, variable_greater_than( _environment, dx2->name, dy2->name, 0 )->name );
            variable_move( _environment, variable_sub( _environment, dy2->name, dx->name)->name, fraction->name);
            begin_while( _environment );
            begin_while_condition( _environment, variable_compare_not( _environment, x->name, x1->name )->name );
                variable_move( _environment, variable_add( _environment, x->name, stepx->name )->name, x->name );
                if_then( _environment, variable_greater_than_const( _environment, fraction->name, 0, 1 )->name );
                    variable_move( _environment, variable_add( _environment, y->name, stepy->name )->name, y->name );
                    variable_move( _environment, variable_sub( _environment, fraction->name, dx2->name )->name, fraction->name );
                end_if_then( _environment );
                variable_move( _environment, variable_add( _environment, fraction->name, dy2->name )->name, fraction->name );
                if ( _environment->lineNeeded ) {
                    if_then( _environment, variable_bit( _environment, pattern->name, bit->name )->name );
                }
                        plot( _environment, x->name, y->name, c->name, _preserve_color );
                if ( _environment->lineNeeded ) {
                    end_if_then( _environment );
                }
                variable_increment( _environment, bit->name );
                if_then( _environment, variable_compare_const( _environment, bit->name, 16 )->name );
                    variable_store( _environment, bit->name, 0 );
                end_if_then( _environment );
            end_while( _environment );
        else_if_then_label( _environment );
        else_if_then( _environment, NULL );
            variable_move( _environment, variable_sub( _environment, dx2->name, dy->name)->name, fraction->name);
            begin_while( _environment );
            begin_while_condition( _environment, variable_compare_not( _environment, y->name, y1->name )->name );
                if_then( _environment, variable_greater_than_const( _environment, fraction->name, 0, 1 )->name );
                    variable_move( _environment, variable_add( _environment, x->name, stepx->name )->name, x->name );
                    variable_move( _environment, variable_sub( _environment, fraction->name, dy2->name )->name, fraction->name );
                end_if_then( _environment );
                variable_move( _environment, variable_add( _environment, y->name, stepy->name )->name, y->name );
                variable_move( _environment, variable_add( _environment, fraction->name, dx2->name )->name, fraction->name );
                if ( _environment->lineNeeded ) {
                    if_then( _environment, variable_bit( _environment, pattern->name, bit->name )->name );
                }
                       plot( _environment, x->name, y->name, c->name, _preserve_color );
                if ( _environment->lineNeeded ) {
                    end_if_then( _environment );
                }
                variable_increment( _environment, bit->name );
                if_then( _environment, variable_compare_const( _environment, bit->name, 16 )->name );
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
    Variable * c = NULL;
    if ( _c ) {
        c = variable_retrieve_or_define( _environment, _c, VT_COLOR, 0 );
    }

    Variable * dx0 = variable_retrieve( _environment, "draw__x0" );
    Variable * dy0 = variable_retrieve( _environment, "draw__y0" );
    Variable * dx1 = variable_retrieve( _environment, "draw__x1" );
    Variable * dy1 = variable_retrieve( _environment, "draw__y1" );
    Variable * dc = variable_retrieve( _environment, "draw__c" );

    variable_move( _environment, x0->name, dx0->name );
    variable_move( _environment, y0->name, dy0->name );
    variable_move( _environment, x1->name, dx1->name );
    variable_move( _environment, y1->name, dy1->name );

    if ( c ) {
        variable_move( _environment, c->name, dc->name );
    } else {
        variable_move( _environment, "PEN", dc->name );
    }

    cpu_call( _environment, "lib_draw");

}