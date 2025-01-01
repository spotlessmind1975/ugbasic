/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit code for <strong>GR LOCATE</strong> command.
 * 
 * @param _environment Current calling environment
 * @param _x Abscissa of current graphic location
 * @param _y Ordinate of current graphic location
 */
/* <usermanual>
@keyword GR LOCATE

@english

The ''GR LOCATE'' allows you to position the graphics cursor in a specific position on the screen, 
thus preparing the ground for subsequent drawing operations, such as printing text, drawing lines 
or shapes.

Before drawing lines, rectangles, or other shapes, you must position the graphics cursor at the
starting point of the shape. By combining ''GR LOCATE'' with other graphics commands, you can 
create animations by moving objects around the screen.

Obviously, the coordinate system and screen size depend on the graphics mode selected with the
''BITMAP ENABLE'' or ''SCREEN'' commands. The ugBASIC offers other graphics functions, such as 
''PLOT'' for drawing points, ''LINE'' for drawing lines, and many more.

@italian

''GR LOCATE'' consente di posizionare il cursore grafico in una posizione specifica sullo 
schermo, preparando così il terreno per le successive operazioni di disegno, 
come la stampa di testo, il disegno di linee o forme.

Prima di disegnare linee, rettangoli o altre forme, è necessario posizionare il cursore 
grafico nel punto di partenza della forma. Combinando ''GR LOCATE'' con altri comandi 
grafici, è possibile creare animazioni spostando gli oggetti sullo schermo.

Ovviamente, il sistema di coordinate e le dimensioni dello schermo dipendono dalla modalità 
grafica selezionata con i comandi ''BITMAP ENABLE'' o ''SCREEN''. ugBASIC offre altre 
funzioni grafiche, come ''PLOT'' per disegnare punti, ''LINE'' per disegnare linee e molte 
altre.

@syntax GR LOCATE [x], [y]

@example GR LOCATE 100,10

@usedInExample graphics_clip_01.bas
@usedInExample graphics_position_01.bas
@usedInExample graphics_shapes_02.bas
</usermanual> */

void gr_locate( Environment * _environment, char * _x, char * _y ) {

    if ( _x ) {
        Variable * x = variable_retrieve( _environment, _x );
        if ( x->origin ) {
            Variable * xgr = variable_retrieve( _environment, "XGR" );
            variable_move( _environment, x->origin->name, xgr->name );
        } else {
            if ( x->reflected ) {
                Variable * xgr = variable_retrieve( _environment, "XGR" );
                variable_move( _environment, x->name, xgr->name );
            } else {
                Variable * xgr = variable_retrieve( _environment, "XGR" );
                if ( x->initializedByConstant ) {
                    variable_store( _environment, xgr->name, x->value );
                } else {
                    variable_move( _environment, x->name, xgr->name );
                }
            }
        }
    }

    if ( _y ) {
        Variable * y = variable_retrieve( _environment, _y );
        if ( y->origin ) {
            Variable * ygr = variable_retrieve( _environment, "YGR" );
            variable_move( _environment, y->origin->name, ygr->name );
        } else {
            if ( y->reflected ) {
                Variable * ygr = variable_retrieve( _environment, "YGR" );
                variable_move( _environment, y->name, ygr->name );
            } else {
                Variable * ygr = variable_retrieve( _environment, "YGR" );
                if ( y->initializedByConstant ) {
                    variable_store( _environment, ygr->name, y->value );
                } else {
                    variable_move( _environment, y->name, ygr->name );
                }
            }
        }
    }

}
