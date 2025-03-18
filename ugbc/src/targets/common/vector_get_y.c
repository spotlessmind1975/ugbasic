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

/* <usermanual>
@keyword Y

@english 

This command allows you to retrieve the Y component of a vector, given as input.

@italian

Questo comando permette di recuperare la componente Y di un vettore, dato in ingresso. 

@syntax = Y( vector )

@example DIM p AS VECTOR
@example    v = CREATE VECTOR( 42, 21 )
@example    PRINT Y(v) : ' It prints 21

</usermanual> */

Variable * vector_get_y( Environment * _environment, char * _vector ) {

    Variable * vector = variable_retrieve( _environment, _vector );

    if ( vector->type != VT_VECTOR2 ) {
        CRITICAL_VECTOR_GET_Y_VECTOR_NEEDED( _vector );
    }

    Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );
    
    cpu_move_16bit( _environment, address_displacement( _environment, vector->realName, "2" ), y->realName );

    return y;

}

