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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

extern char DATATYPE_AS_STRING[][16];

/**
 * @brief Return the square root of a variable
 * 
 * @param _environment Current calling environment
 * @param _value Value to calculate the square root
 * @return Variable* The square root of value
 */
/* <usermanual>
@keyword SQR

@english
The ''SQR'' function returns a value representing the square root of a number.

@italian
La funzione ''SQR'' restituisce un valore che rappresenta la radice quadrata di un numero.

@syntax SQR([expression])

@example x = SNG(81)

@usedInExample maths_sqr_01.bas

@target all
</usermanual> */

Variable * sqroot( Environment * _environment, char * _value ) {
    Variable * value = variable_retrieve_or_define( _environment, _value, VT_WORD, 0 );

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of SQR)");

    switch( VT_BITWIDTH( value->type ) ) {
        case 32:
            CRITICAL_SQR_UNSUPPORTED( _value, DATATYPE_AS_STRING[value->type] );
        case 16:
            // if ( VT_SIGNED( value->type ) ) {
            //     CRITICAL_SQR_UNSUPPORTED( _value, DATATYPE_AS_STRING[value->type] );
            // }
            cpu_sqroot( _environment, value->realName, result->realName );
            break;
        case 8:
            CRITICAL_SQR_UNSUPPORTED( _value, DATATYPE_AS_STRING[value->type] );
            break;
        case 0:
            CRITICAL_SGN_UNSUPPORTED( _value, DATATYPE_AS_STRING[value->type] );
            break;
    }

    return result;
}

