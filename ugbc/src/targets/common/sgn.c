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

The ''SGN'' function is a very simple but useful mathematical function. Its main 
function is to determine the sign of a number. In other words, ''SGN'' tells you 
whether a number is positive, negative, or zero. So, it returns 1 if number 
is positive, 0 if ''number'' is zero and -1 if ''number'' is negative.

You can use ''SGN'' inside an ''IF'' condition to perform different actions 
depending on the sign of a number, and in some cases, ''SGN'' can make your 
code more concise and readable.


@italian

La funzione ''SGN'' è una funzione matematica molto semplice ma utile. 
La sua funzione principale è determinare il segno di un numero. In altre 
parole, ''SGN'' ti dice se un numero è positivo, negativo o zero. Quindi, 
restituisce 1 se il ''number'' è positivo, 0 se ''number'' è zero e -1 se 
''number'' è negativo.

Puoi usare ''SGN'' all'interno di una condizione ''IF'' per eseguire azioni 
diverse a seconda del segno di un numero e, in alcuni casi, ''SGN'' può 
rendere il tuo codice più conciso e leggibile.

@syntax = SGN(number)

@example x = SNG(-42)

@usedInExample maths_signs_01.bas

</usermanual> */

Variable * sign( Environment * _environment, char * _value ) {
    Variable * value = variable_retrieve( _environment, _value );

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(result of SGN)");

    MAKE_LABEL

    char positiveLabel[MAX_TEMPORARY_STORAGE]; sprintf(positiveLabel, "%spos", label );
    char zeroLabel[MAX_TEMPORARY_STORAGE]; sprintf(zeroLabel, "%szero", label );
    char negativeLabel[MAX_TEMPORARY_STORAGE]; sprintf(negativeLabel, "%snev", label );
    char endLabel[MAX_TEMPORARY_STORAGE]; sprintf(endLabel, "%send", label );

    switch( VT_BITWIDTH( value->type ) ) {
        case 32:
        case 16:
        case 8:
            if ( VT_SIGNED( value->type ) ) {
                
                cpu_bveq( _environment, value->realName, zeroLabel );

                cpu_bit_check( _environment, value->realName, VT_BITWIDTH( value->type ) - 1, result->realName, VT_BITWIDTH( value->type ) );
                cpu_bveq( _environment, result->realName, positiveLabel );

                cpu_label( _environment, negativeLabel );
                variable_store( _environment, result->name, VT_SIGN_8BIT(-1) );
                cpu_jump( _environment, endLabel );

                cpu_label( _environment, zeroLabel );
                variable_store( _environment, result->name, 0 );
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

