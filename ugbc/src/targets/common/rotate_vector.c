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
 * @brief Emit ASM code to implement <strong>CREATE PATH</strong> command
 * 
 * @param _environment Current calling environment
 * @param _x Left abscissa of the line
 * @param _y Left ordinate of the line
 */
/* <usermanual>
@keyword ROTATE VECTOR

@english 

This command allows you to rotate a two-dimensional ''VECTOR'' by a given angle.

@italian

Questo comando consente di ruotare un vettore bidimensionale (''VECTOR'') di un certo angolo dato.

@syntax = ROTATE VECTOR( vector, angle )

@example DIM p AS VECTOR
@example    v = CREATE VECTOR( 10, 10 )
@example    v = ROTATE VECTOR( v, 1.57 )

</usermanual> */
 
Variable * rotate_vector( Environment * _environment, char * _v, char * _a ) {

    deploy_begin( rotate_vector );

        Variable * vector = variable_define( _environment, "rotatevector__vector", VT_VECTOR2, 0 );
        Variable * angle = variable_define( _environment, "rotatevector__angle", VT_FLOAT, 0 );

        Variable * x = vector_get_x( _environment, vector->name );
        Variable * y = vector_get_y( _environment, vector->name );

        Variable * ca = fp_cos( _environment, angle->name );
        Variable * sa = fp_sin( _environment, angle->name );

        Variable * xpca = variable_mul( _environment, x->name, ca->name );
        Variable * ypsa = variable_mul( _environment, y->name, sa->name );
        Variable * xpsa = variable_mul( _environment, x->name, sa->name );
        Variable * ypca = variable_mul( _environment, y->name, ca->name );

        cpu_move_16bit( _environment, variable_cast( _environment, variable_sub( _environment, xpca->name, ypsa->name)->name, VT_POSITION )->realName, vector->realName );
        cpu_move_16bit( _environment, variable_cast( _environment, variable_add( _environment, xpsa->name, ypca->name)->name, VT_POSITION )->realName, address_displacement( _environment, vector->realName, "2" ) );

        cpu_return( _environment );

    deploy_end( rotate_vector )

    Variable * vp = variable_retrieve( _environment, "rotatevector__vector" );
    Variable * ap = variable_retrieve( _environment, "rotatevector__angle" );

    Variable * v = variable_retrieve( _environment, _v );
    Variable * a = variable_retrieve_or_define( _environment, _a, VT_FLOAT, 0 );

    variable_move( _environment, v->name, vp->name );
    variable_move( _environment, a->name, ap->name );

    cpu_call( _environment, "lib_rotate_vector" );

    return vp;

}

