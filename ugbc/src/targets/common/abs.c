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
 * @brief Return the absolute value of a variable
 * 
 * @param _environment Current calling environment
 * @param _value Value to calculate the absolute value
 * @return Variable* The absolute value
 */
/* <usermanual>
@keyword ABS

@english
The function ''ABS'' can be used to convert arguments into a positive number. 
''ABS'' returns an absolute value of an integer or fractional number, paying 
no attention to whether that number is positive or negative, in other words, 
ignoring its sign.

@italian
La funzione ''ABS'' può essere utilizzata per convertire gli argomenti 
in un numero positivo. Restituisce un valore assoluto di un numero intero o 
frazionario, non tenendo in alcuna considerazione il fatto che quel numero 
sia positivo o negativo, in altre parole, ignorando il suo segno.

@syntax ABS([expression])

@example x = ABS(-1)

@usedInExample maths_abs_01.bas

@target all
</usermanual> */
Variable * absolute( Environment * _environment, char * _value ) {
    Variable * value = variable_retrieve( _environment, _value );

    Variable * result = variable_temporary( _environment, value->type, "(result of ABS)");

    MAKE_LABEL

    char positiveLabel[32]; sprintf(positiveLabel, "%spos", label );
    char negativeLabel[32]; sprintf(negativeLabel, "%snev", label );
    char endLabel[32]; sprintf(endLabel, "%send", label );

    switch( VT_BITWIDTH( value->type ) ) {
        case 32:
        case 16:
        case 8:
            if ( VT_SIGNED( value->type ) ) {
                cpu_bit_check( _environment, value->realName, VT_BITWIDTH( value->type ) - 1, result->realName );
                cpu_bveq( _environment, result->realName, positiveLabel );

                cpu_label( _environment, negativeLabel );
                result = variable_not( _environment, value->name );
                cpu_jump( _environment, endLabel );

                cpu_label( _environment, positiveLabel );
                variable_move( _environment, value->name, result->name );
                cpu_label( _environment, endLabel );

            } else {
                variable_move( _environment, value->name, result->name );
            }
            break;
        case 0:
            CRITICAL_ABS_UNSUPPORTED( _value, DATATYPE_AS_STRING[value->type] );
            break;
    }

    return result;
}

