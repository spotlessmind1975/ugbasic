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
 * @brief Emit ASM code to implement <strong>TRAVEL PATH</strong> command
 * 
 * @param _environment Current calling environment
 * @param _p Path
 * @param _x1 Left abscissa of the line
 * @param _y1 Left ordinate of the line
 */
/* <usermanual>
@keyword TRAVEL

The ''TRAVEL'' command allows you to move an entity (for example, a character in a video 
game, a robot in a simulated environment, or a cursor on a map) from a starting point to 
a destination point, following a previous created ''PATH''. The coordinates of the 
starting point and of the destination point are given using the ''CREATE PATH'' command.
So, this command will update a pair of variables (''x'',''y'') with the next point. 
Optionally, you can give a multiplier factor (''times''), in order to move more than one pixel
at a time. By adding the ''CLAMP'' keyword, the increment of the coordinate variables 
will be limited to the coordinates of the destination point.

The command uses the Bresenham algorithm to calculate the sequence of intermediate 
coordinates that define the most efficient path between the starting point and the 
destination point. The Bresenham algorithm is particularly suitable for drawing 
straight lines on discrete grids (such as pixel grids), ensuring an optimized path in 
terms of steps. In other words, the entity is moved along the calculated path, 
updating its coordinates at each step. The speed of the movement can be controlled by 
the ''times'' parameter. If the speed is not specified, a value of 1 is implicit considered.

The Bresenham algorithm is efficient and ensures an optimized path, but produces straight 
paths. In scenarios where more complex paths are required (e.g. with curves or obstacles), 
more advanced pathfinding algorithms may be needed. 

@italian

Il comando ''TRAVEL'' consente di spostare un'entità (ad esempio, un personaggio in un videogioco, un robot in un ambiente simulato o un cursore su una mappa) da un punto di partenza a un punto di destinazione, seguendo un ''PATH'' creato in precedenza. Le coordinate del punto di partenza e del punto di destinazione vengono fornite utilizzando il comando ''CREATE PATH''.
Quindi, questo comando aggiornerà una coppia di variabili (''x'',''y'') con il punto successivo.
Facoltativamente, è possibile fornire un fattore moltiplicatore (''times''), per spostare più di un pixel
alla volta.

Il comando utilizza l'algoritmo di Bresenham per calcolare la sequenza di coordinate intermedie che definiscono il percorso più efficiente tra il punto di partenza e il punto di destinazione. L'algoritmo di Bresenham è particolarmente adatto per disegnare linee rette su griglie discrete (come le griglie di pixel), garantendo un percorso ottimizzato in termini di passaggi. In altre parole, l'entità viene spostata lungo il percorso calcolato,
aggiornando le sue coordinate a ogni passo. La velocità del movimento può essere controllata dal
parametro ''times''. Se la velocità non è specificata, viene implicitamente considerato un 
valore pari a 1. Aggiungendo la parola chiave ''CLAMP'', l'incremento delle variabili coordinate 
sarà limitato alle coordinate del punto di destinazione.

L'algoritmo di Bresenham è efficiente e garantisce un percorso ottimizzato, ma produce percorsi
retti. In scenari in cui sono richiesti percorsi più complessi (ad esempio con curve o ostacoli),
potrebbero essere necessari algoritmi di pathfinding più avanzati.

@syntax TRAVEL path TO x, y [BY times] [CLAMP]

</usermanual> */

Variable * travel_path( Environment * _environment, char * _p, char * _x, char * _y, char * _times, char * _limited ) {

    deploy_begin( travel_path );

        MAKE_LABEL
        char loopLabel[ MAX_TEMPORARY_STORAGE ]; sprintf( loopLabel, "%stimes", label );
        char unlimitedLabel[ MAX_TEMPORARY_STORAGE ]; sprintf( unlimitedLabel, "%sunlimited", label );
        char doneLabel[ MAX_TEMPORARY_STORAGE ]; sprintf( doneLabel, "%sdone", label );

        Variable * path = variable_define( _environment, "travelpath__path", VT_PATH, 0 );

        Variable * xout = variable_define( _environment, "travelpath__xout", VT_POSITION, 0 );
        Variable * yout = variable_define( _environment, "travelpath__yout", VT_POSITION, 0 );

        Variable * times = variable_define( _environment, "travelpath__times", VT_BYTE, 0 );
        Variable * limited = variable_define( _environment, "travelpath__limited", VT_SBYTE, 0 );
        Variable * check = variable_temporary( _environment, VT_SBYTE, "(stepx)");

        Variable * fraction = variable_temporary( _environment, VT_POSITION, "(fraction)");
        Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
        Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );
        Variable * dx = variable_temporary( _environment, VT_SBYTE, "(dx2)");
        Variable * dy = variable_temporary( _environment, VT_SBYTE, "(dy2)");
        Variable * dx2 = variable_temporary( _environment, VT_SBYTE, "(dx2)");
        Variable * dy2 = variable_temporary( _environment, VT_SBYTE, "(dy2)");
        Variable * stepx = variable_temporary( _environment, VT_SBYTE, "(stepx)");
        Variable * stepy = variable_temporary( _environment, VT_SBYTE, "(stepy)");
        Variable * x1 = variable_temporary( _environment, VT_POSITION, "(x1)" );
        Variable * y1 = variable_temporary( _environment, VT_POSITION, "(y1)" );

        cpu_move_16bit( _environment, path->realName, x->realName );
        cpu_move_16bit( _environment, address_displacement( _environment, path->realName, "2" ), y->realName );
        cpu_move_8bit( _environment, address_displacement( _environment, path->realName, "4" ), dx2->realName );
        cpu_move_8bit( _environment, address_displacement( _environment, path->realName, "5" ), dy2->realName );
        cpu_move_8bit( _environment, address_displacement( _environment, path->realName, "6" ), stepx->realName );
        cpu_move_8bit( _environment, address_displacement( _environment, path->realName, "7" ), stepy->realName );
        cpu_move_8bit( _environment, address_displacement( _environment, path->realName, "8" ), fraction->realName );
        cpu_move_16bit( _environment, address_displacement( _environment, path->realName, "10" ), x1->realName );
        cpu_move_16bit( _environment, address_displacement( _environment, path->realName, "12" ), y1->realName );

        cpu_store_8bit( _environment, check->realName, 0 );

        cpu_label( _environment, loopLabel );

        cpu_compare_and_branch_8bit_const( _environment, limited->realName, 0, unlimitedLabel, 1 );

        variable_move( _environment,
            variable_and( _environment, 
                variable_compare( _environment, x->name, x1->name )->name,
                variable_compare( _environment, y->name, x1->name )->name
            )->name, check->name );
        cpu_compare_and_branch_8bit_const( _environment, check->realName, 0xff, doneLabel, 1 );

        cpu_label( _environment, unlimitedLabel );

        if_then( _environment, variable_greater_than( _environment, dx2->name, dy2->name, 0 )->name );
            variable_move( _environment, variable_add( _environment, x->name, stepx->name )->name, x->name );
            if_then( _environment, variable_greater_than_const( _environment, fraction->name, 0, 1 )->name );
                variable_move( _environment, variable_add( _environment, y->name, stepy->name )->name, y->name );
                variable_move( _environment, variable_sub( _environment, fraction->name, dx2->name )->name, fraction->name );
            end_if_then( _environment );
            variable_move( _environment, variable_add( _environment, fraction->name, dy2->name )->name, fraction->name );
        else_if_then_label( _environment );
        else_if_then( _environment, NULL );
            if_then( _environment, variable_greater_than_const( _environment, fraction->name, 0, 1 )->name );
                variable_move( _environment, variable_add( _environment, x->name, stepx->name )->name, x->name );
                variable_move( _environment, variable_sub( _environment, fraction->name, dy2->name )->name, fraction->name );
            end_if_then( _environment );
            variable_move( _environment, variable_add( _environment, y->name, stepy->name )->name, y->name );
            variable_move( _environment, variable_add( _environment, fraction->name, dx2->name )->name, fraction->name );
        end_if_then( _environment );

        cpu_dec( _environment, times->realName );
        cpu_compare_and_branch_8bit_const( _environment, times->realName, 0, loopLabel, 0 );

        cpu_label( _environment, doneLabel );

        cpu_move_16bit( _environment, x->realName, path->realName );
        cpu_move_16bit( _environment, y->realName, address_displacement( _environment, path->realName, "2" ) );
        cpu_move_8bit( _environment, dx2->realName, address_displacement( _environment, path->realName, "4" ) );
        cpu_move_8bit( _environment, dy2->realName, address_displacement( _environment, path->realName, "5" ) );
        cpu_move_8bit( _environment, stepx->realName, address_displacement( _environment, path->realName, "6" ) );
        cpu_move_8bit( _environment, stepy->realName, address_displacement( _environment, path->realName, "7" ) );
        cpu_move_8bit( _environment, fraction->realName, address_displacement( _environment, path->realName, "8" ) );

        cpu_move_16bit( _environment, x->realName, xout->realName );
        cpu_move_16bit( _environment, y->realName, yout->realName );

        outline0("; pippero");
        cpu_move_8bit( _environment, check->realName, limited->realName );

        cpu_return( _environment );

    deploy_end( travel_path )

    Variable * p = variable_retrieve( _environment, _p );
    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    Variable * path = variable_retrieve( _environment, "travelpath__path" );
    Variable * xout = variable_retrieve( _environment, "travelpath__xout" );
    Variable * yout = variable_retrieve( _environment, "travelpath__yout" );
    Variable * ptimes = variable_retrieve( _environment, "travelpath__times" );
    Variable * plimited = variable_retrieve( _environment, "travelpath__limited" );

    variable_move( _environment, p->name, path->name );
    if ( _times ) {
        Variable * times = variable_retrieve( _environment, _times );
        if ( times->initializedByConstant ) {
            variable_store( _environment, ptimes->name, times->value );
        } else {
            variable_move( _environment, times->name, ptimes->name );
        }
    } else {
        variable_store( _environment, ptimes->name, 1 );
    }

    Variable * limited;
    if ( _limited ) {
        limited = variable_retrieve_or_define( _environment, _limited, VT_SBYTE, 0 );
        variable_move( _environment, limited->name, plimited->name );
    } else {
        limited = variable_temporary( _environment, VT_SBYTE, "(limited)" );
        variable_store( _environment, plimited->name, 0 );
    }

    cpu_call( _environment, "lib_travel_path" );

    variable_move( _environment, path->name, p->name );
    variable_move( _environment, xout->name, x->name );
    variable_move( _environment, yout->name, y->name );
    variable_move( _environment, plimited->name, limited->name );

    return limited;

}