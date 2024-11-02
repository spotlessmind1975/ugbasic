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
 * @brief Emit ASM code to implement <strong>TRAVEL PATH</strong> command
 * 
 * @param _environment Current calling environment
 * @param _p Path
 * @param _x1 Left abscissa of the line
 * @param _y1 Left ordinate of the line
 */
/* <usermanual>
@keyword TRAVEL PATH

@italian

@syntax TRAVEL PATH path TO x, y

</usermanual> */

void travel_path( Environment * _environment, char * _p, char * _x, char * _y ) {

    deploy_begin( travel_path );

        Variable * path = variable_define( _environment, "travelpath__path", VT_PATH, 0 );

        Variable * xout = variable_define( _environment, "travelpath__xout", VT_POSITION, 0 );
        Variable * yout = variable_define( _environment, "travelpath__yout", VT_POSITION, 0 );

        Variable * fraction = variable_temporary( _environment, VT_POSITION, "(fraction)");
        Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
        Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );
        Variable * dx = variable_temporary( _environment, VT_POSITION, "(dx2)");
        Variable * dy = variable_temporary( _environment, VT_POSITION, "(dy2)");
        Variable * dx2 = variable_temporary( _environment, VT_POSITION, "(dx2)");
        Variable * dy2 = variable_temporary( _environment, VT_POSITION, "(dy2)");
        Variable * stepx = variable_temporary( _environment, VT_POSITION, "(stepx)");
        Variable * stepy = variable_temporary( _environment, VT_POSITION, "(stepy)");

        cpu_move_16bit( _environment, path->realName, x->realName );
        cpu_move_16bit( _environment, address_displacement( _environment, path->realName, "2" ), y->realName );
        cpu_move_16bit( _environment, address_displacement( _environment, path->realName, "4" ), dx2->realName );
        cpu_move_16bit( _environment, address_displacement( _environment, path->realName, "6" ), dy2->realName );
        cpu_move_16bit( _environment, address_displacement( _environment, path->realName, "8" ), stepx->realName );
        cpu_move_16bit( _environment, address_displacement( _environment, path->realName, "10" ), stepy->realName );
        cpu_move_16bit( _environment, address_displacement( _environment, path->realName, "12" ), fraction->realName );

        if_then( _environment, variable_less_than_const( _environment, fraction->name, 0, 0 )->name );
    #if CPU_BIG_ENDIAN
            cpu_and_8bit_const( _environment, fraction->realName, 0x7f, fraction->realName );
    #else
            cpu_and_8bit_const( _environment, address_displacement( _environment, fraction->realName, "1" ), 0x7f, address_displacement( _environment, fraction->realName, "1" ) );
    #endif
            variable_move( _environment, variable_add( _environment, x->name, stepx->name )->name, x->name );
            if_then( _environment, variable_greater_than_const( _environment, fraction->name, 0, 1 )->name );
                variable_move( _environment, variable_add( _environment, y->name, stepy->name )->name, y->name );
                variable_move( _environment, variable_sub( _environment, fraction->name, dx2->name )->name, fraction->name );
            end_if_then( _environment );
            variable_move( _environment, variable_add( _environment, fraction->name, dy2->name )->name, fraction->name );
    #if CPU_BIG_ENDIAN
            cpu_or_8bit_const( _environment, fraction->realName, 0x80, fraction->realName );
    #else
            cpu_or_8bit_const( _environment, address_displacement( _environment, fraction->realName, "1" ), 0x80, address_displacement( _environment, fraction->realName, "1" ) );
    #endif            
        else_if_then_label( _environment );
        else_if_then( _environment, NULL );
            if_then( _environment, variable_greater_than_const( _environment, fraction->name, 0, 1 )->name );
                variable_move( _environment, variable_add( _environment, x->name, stepx->name )->name, x->name );
                variable_move( _environment, variable_sub( _environment, fraction->name, dy2->name )->name, fraction->name );
            end_if_then( _environment );
            variable_move( _environment, variable_add( _environment, y->name, stepy->name )->name, y->name );
            variable_move( _environment, variable_add( _environment, fraction->name, dx2->name )->name, fraction->name );
        end_if_then( _environment );

        cpu_move_16bit( _environment, x->realName, path->realName );
        cpu_move_16bit( _environment, y->realName, address_displacement( _environment, path->realName, "2" ) );
        cpu_move_16bit( _environment, dx2->realName, address_displacement( _environment, path->realName, "4" ) );
        cpu_move_16bit( _environment, dy2->realName, address_displacement( _environment, path->realName, "6" ) );
        cpu_move_16bit( _environment, stepx->realName, address_displacement( _environment, path->realName, "8" ) );
        cpu_move_16bit( _environment, stepy->realName, address_displacement( _environment, path->realName, "10" ) );
        cpu_move_16bit( _environment, fraction->realName, address_displacement( _environment, path->realName, "12" ) );

        cpu_move_16bit( _environment, x->realName, xout->realName );
        cpu_move_16bit( _environment, y->realName, yout->realName );

        cpu_return( _environment );

    deploy_end( travel_path )

    Variable * p = variable_retrieve( _environment, _p );
    Variable * x = variable_retrieve( _environment, _x );
    Variable * y = variable_retrieve( _environment, _y );

    Variable * path = variable_retrieve( _environment, "travelpath__path" );
    Variable * xout = variable_retrieve( _environment, "travelpath__xout" );
    Variable * yout = variable_retrieve( _environment, "travelpath__yout" );

    variable_move( _environment, p->name, path->name );

    cpu_call( _environment, "lib_travel_path" );

    variable_move( _environment, path->name, p->name );
    variable_move( _environment, xout->name, x->name );
    variable_move( _environment, yout->name, y->name );

}