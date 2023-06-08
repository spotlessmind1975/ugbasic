/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
#include <math.h>

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/* <usermanual>
@keyword TAN

@english
This function will calculate the tangent value of an angle. It is the ratio 
of the opposite side and the adjacent side of the angle in consideration in 
a right-angled triangle.

@italian
Questa funzione calcolerà il valore della tangente di un angolo. È il rapporto 
tra il lato opposto e il lato adiacente dell'angolo considerato in un triangolo 
rettangolo.

@syntax = TAN([angle])

@example x = TAN(0)

@usedInExample float_tan.bas

@target all
</usermanual> */
Variable * fp_tan( Environment * _environment, char * _angle ) {

    Variable * angle = variable_retrieve_or_define( _environment, _angle, VT_FLOAT, 0 );
    Variable * result = variable_temporary( _environment, VT_FLOAT, "(tan)");

    switch( result->precision ) {
        case FT_FAST:
            if ( _environment->floatType.angle == FT_DEGREE ) {
                Variable * pi = variable_temporary( _environment, VT_FLOAT, "(float)" );
                variable_store_float( _environment, pi->name, M_PI );
                Variable * d180 = variable_temporary( _environment, VT_FLOAT, "(d180)" );
                variable_store_float( _environment, d180->name, 180.0 );
                Variable * radianAngle = variable_temporary( _environment, VT_FLOAT, "(tan)");
                cpu_float_fast_mul( _environment, angle->realName, pi->realName, radianAngle->realName );
                cpu_float_fast_div( _environment, radianAngle->realName, d180->realName, radianAngle->realName );
                cpu_float_fast_tan( _environment, radianAngle->realName, result->realName );
            } else {
                cpu_float_fast_tan( _environment, angle->realName, result->realName );
            }
            break;
        case FT_SINGLE:
            if ( _environment->floatType.angle == FT_DEGREE ) {
                Variable * pi = variable_temporary( _environment, VT_FLOAT, "(float)" );
                variable_store_float( _environment, pi->name, M_PI );
                Variable * d180 = variable_temporary( _environment, VT_FLOAT, "(d180)" );
                variable_store_float( _environment, d180->name, 180.0 );
                Variable * radianAngle = variable_temporary( _environment, VT_FLOAT, "(tan)");
                cpu_float_single_mul( _environment, angle->realName, pi->realName, radianAngle->realName );
                cpu_float_single_div( _environment, radianAngle->realName, d180->realName, radianAngle->realName );
                cpu_float_single_tan( _environment, radianAngle->realName, result->realName );
            } else {
                cpu_float_single_tan( _environment, angle->realName, result->realName );
            }
            break;
    }

    return result;

}
