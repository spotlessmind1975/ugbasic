/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Return the sign of a variable
 * 
 * @param _environment Current calling environment
 * @param _value Value to calculate the sign
 * @return Variable* The sign of value
 */
/* <usermanual>
@keyword SGN

@english
The ''SGN'' function returns a value representing the sign of a number. The three possible results are these:

  * ''-1'' if the value is negative
  * ''1'' if the value is positive
  * ''0'' if the value is zero

@italian
La funzione ''SGN'' restituisce un valore che rappresenta il segno di un numero. 
I tre possibili risultati sono questi:

   * "-1" se il valore è negativo
   * "1" se il valore è positivo
   * "0" se il valore è zero

@syntax SGN([expression])

@example x = SNG(-42)

@usedInExample maths_signs_01.bas

@target all
</usermanual> */

Variable * sign( Environment * _environment, char * _value ) {
    Variable * value = variable_retrieve( _environment, _value );

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(result of SGN)");

    MAKE_LABEL

    char positiveLabel[MAX_TEMPORARY_STORAGE]; sprintf(positiveLabel, "%spos", label );
    char negativeLabel[MAX_TEMPORARY_STORAGE]; sprintf(negativeLabel, "%snev", label );
    char endLabel[MAX_TEMPORARY_STORAGE]; sprintf(endLabel, "%send", label );

    switch( VT_BITWIDTH( value->type ) ) {
        case 32:
        case 16:
        case 8:
            if ( VT_SIGNED( value->type ) ) {
                cpu_bit_check( _environment, value->realName, VT_BITWIDTH( value->type ) - 1, result->realName );
                cpu_bveq( _environment, result->realName, positiveLabel );

                cpu_label( _environment, negativeLabel );
                variable_store( _environment, result->name, VT_SIGN_8BIT(-1) );
                cpu_jump( _environment, endLabel );

                cpu_label( _environment, positiveLabel );
                variable_store( _environment, result->name, 1 );   
                
                cpu_label( _environment, endLabel );
            } else {
                variable_store( _environment, result->name, 1 );
            }
            break;
        case 0:
            CRITICAL_SGN_UNSUPPORTED( _value, DATATYPE_AS_STRING[value->type] );
            break;
    }

    return result;
}

