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

The ''SQR'' command (short for "square root") is a mathematical function that
is used to calculate the square root of a number. In other words, given a number
''x'', the command ''SQR(x)'' returns the number that, when multiplied by itself, 
gives the result ''x''.

The ''SQR'' command has many applications in programming: it is used in any 
calculation that requires the calculation of the square root, such as in the 
Pythagorean theorem. The square root is present in many physics formulas, 
such as in the calculation of velocity. It is used also to calculate the 
lengths of segments or areas of geometric figures, and in many statistical 
calculations, such as in the calculation of standard deviation.

The square root of a negative number is not defined in real numbers. If you 
try to calculate the square root of a negative number, the result is indefinite.
Moreover, the function is defined in the integer numbers domain.

@italian

Il comando ''SQR'' (abbreviazione di "square root") è una funzione matematica 
utilizzata per calcolare la radice quadrata di un numero. In altre parole, 
dato un numero ''x'', il comando ''SQR(x)'' restituisce il numero che, 
moltiplicato per se stesso, dà il risultato ''x''.

Il comando ''SQR'' ha molte applicazioni nella programmazione: viene utilizzato 
in qualsiasi calcolo che richieda il calcolo della radice quadrata, come nel 
teorema di Pitagora. La radice quadrata è presente in molte formule fisiche, 
come nel calcolo della velocità. Viene anche utilizzata per calcolare le 
lunghezze di segmenti o aree di figure geometriche e in molti calcoli statistici, 
come nel calcolo della deviazione standard.

La radice quadrata di un numero negativo non è definita nei numeri reali. 
Se si tenta di calcolare la radice quadrata di un numero negativo, 
il risultato è indefinito. Inoltre, la funzione è definita nel dominio
nei numeri interi.

@syntax = SQR(expression)

@example PRINT SNG(81)

@usedInExample maths_sqr_01.bas

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
        case 8: {
            Variable * value16 = variable_cast( _environment, value->name, VT_WORD );
            cpu_sqroot( _environment, value16->realName, result->realName );
            break;
        }
        case 0:
            CRITICAL_SGN_UNSUPPORTED( _value, DATATYPE_AS_STRING[value->type] );
            break;
    }

    return result;
}

