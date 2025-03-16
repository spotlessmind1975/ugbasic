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
@keyword CREATE VECTOR

@english 

This command allows you to generate a ''VECTOR'' variable, i.e.
a datatype that represents a two-dimensional geometric vector.

@italian

Questo comando consente di generare una variabile di tipo ''VECTOR'',
cioè un tipo di dato che rappresenta un vettore geometrico bidimensionale.

@syntax = CREATE VECTOR( x0, y0 )

@example DIM p AS VECTOR
@example    v = CREATE VECTOR( 10, 10 )

</usermanual> */
 
Variable * create_vector( Environment * _environment, char * _x, char * _y ) {

    deploy_begin( create_vector );

        Variable * vector = variable_define( _environment, "createvector__vector", VT_VECTOR, 0 );

        Variable * x = variable_define( _environment, "createvector__x", VT_POSITION, 0 );
        Variable * y = variable_define( _environment, "createvector__y", VT_POSITION, 0 );

        cpu_move_16bit( _environment, x->realName, vector->realName );
        cpu_move_16bit( _environment, y->realName, address_displacement( _environment, vector->realName, "2" ) );

        cpu_return( _environment );

    deploy_end( create_vector )

    Variable * xp = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * yp = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );

    Variable * vector = variable_retrieve( _environment, "createvector__vector" );

    Variable * x = variable_retrieve( _environment, "createvector__x" );
    Variable * y = variable_retrieve( _environment, "createvector__y" );
    
    variable_move( _environment, xp->name, x->name );
    variable_move( _environment, yp->name, y->name );

    cpu_call( _environment, "lib_create_vector" );

    return vector;

}

