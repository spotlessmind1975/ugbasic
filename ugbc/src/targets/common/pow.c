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
 * @brief Emit code to raise a variable to a given variable
 * 
 * This function allows you to emit a code that raise a variable
 * to a given variable.
 * 
 * @pre _base and _exponential variables must exist
 * 
 * @param _environment Current calling environment
 * @param _base Base variable's name
 * @param _exponential Exponential variable's name
 * @return Variable* The result of calculation
 */
/* <usermanual>
@keyword POW

@english
The ''POW'' instruction is short for "power" and is used to calculate the
power of a number. In other words, it allows you to raise a base number 
to a certain exponent. It multiplies the base by itself a number of times 
equal to the exponent. For example, ''POW(2, 3)'' means to multiply 2 
by itself 3 times: ''2 * 2 * 2''. The variables used for the base and 
exponent must be integer. So can be computationally expensive for very large 
exponents. In some cases, there may be more efficient algorithms 
for calculating powers.

@italian
L'istruzione ''POW'' è l'abbreviazione di "power" (potenza) e viene 
utilizzata per calcolare la potenza di un numero. In altre parole, 
consente di elevare un numero di base a un certo esponente. Moltiplica 
la base per se stessa un numero di volte pari all'esponente. Ad esempio, 
''POW(2, 3)'' significa moltiplicare 2 per se stesso 3 volte: ''2 * 2 * 2''. 
Le variabili utilizzate per la base e l'esponente devono essere intere. 
Quindi può essere computazionalmente costoso per esponenti molto grandi. 
In alcuni casi, potrebbero esserci algoritmi più efficienti per 
calcolare le potenze.

@syntax = POW( base, exponent )
@syntax = base ^ exponent

@example pitagora = POW(a,2) + b^2 + POW(c,2)

@usedInExample maths_example_01.bas

@target all
@verified
</usermanual> */

Variable * powering( Environment * _environment, char * _base, char * _exponential ) {

    Variable * base = variable_retrieve( _environment, _base );
    Variable * exponential = variable_retrieve_or_define( _environment, _exponential, VT_SWORD, 0 );

    Variable * result, * temporary;

    switch( base->type ) {
        case VT_SBYTE:
        case VT_BYTE:
        case VT_SWORD:
        case VT_WORD:
        case VT_POSITION:
        case VT_FLOAT:
            break;
        default:
            CRITICAL_POW_UNSUPPORTED( _base, DATATYPE_AS_STRING[base->type]);
    }

    switch( exponential->type ) {
        case VT_SBYTE:
        case VT_BYTE:
        case VT_SWORD:
        case VT_WORD:
        case VT_POSITION:
            break;
        default:
            CRITICAL_POW_UNSUPPORTED( _exponential, DATATYPE_AS_STRING[exponential->type]);
    }

    MAKE_LABEL

    char endLabel[MAX_TEMPORARY_STORAGE]; sprintf(endLabel, "%send", label);

    Variable * counter = variable_cast( _environment, exponential->name, VT_BYTE );
    switch( VT_BITWIDTH( base->type ) ) {
        case 16:
            result = variable_temporary( _environment, VT_SIGNED( base->type ) ? VT_SDWORD : VT_DWORD, "(result of pow)");
            temporary = variable_temporary( _environment, VT_SIGNED( base->type ) ? VT_SDWORD : VT_DWORD, "(result of pow)");
            variable_store( _environment, result->name, 1 );
            cpu_bveq( _environment, counter->realName, endLabel );
            cpu_label( _environment, label );
            #ifdef CPU_BIG_ENDIAN
                {
                    char resultRealName[MAX_TEMPORARY_STORAGE]; sprintf( resultRealName, "%s", address_displacement(_environment, result->realName, "2") );
                    cpu_math_mul_16bit_to_32bit( _environment, base->realName, resultRealName, temporary->realName, VT_SIGNED( base->type ) );
                }
            #else
                cpu_math_mul_16bit_to_32bit( _environment, base->realName, result->realName, temporary->realName, VT_SIGNED( base->type ) );
            #endif
            cpu_move_32bit( _environment, temporary->realName, result->realName );
            cpu_dec( _environment, counter->realName );
            cpu_bvneq( _environment, counter->realName, label );
            cpu_label( _environment, endLabel );
            break;
        case 8:
            result = variable_temporary( _environment, VT_SIGNED( base->type ) ? VT_SWORD : VT_WORD, "(result of pow)");
            temporary = variable_temporary( _environment, VT_SIGNED( base->type ) ? VT_SDWORD : VT_DWORD, "(result of pow)");
            variable_store( _environment, result->name, 1 );
            cpu_bveq( _environment, counter->realName, endLabel );
            cpu_label( _environment, label );
            #ifdef CPU_BIG_ENDIAN
                {
                    char resultRealName[MAX_TEMPORARY_STORAGE]; sprintf( resultRealName, "%s", address_displacement(_environment, result->realName, "1") );
                    cpu_math_mul_8bit_to_16bit( _environment, base->realName, resultRealName, temporary->realName, VT_SIGNED( base->type ) );
                }
            #else
                cpu_math_mul_8bit_to_16bit( _environment, base->realName, result->realName, temporary->realName, VT_SIGNED( base->type ) );
            #endif
            cpu_move_16bit( _environment, temporary->realName, result->realName );
            cpu_dec( _environment, counter->realName );
            cpu_bvneq( _environment, counter->realName, label );
            cpu_label( _environment, endLabel );
            break;
        case 0: {
            switch( base->type ) {
                case VT_FLOAT: {
                    result = variable_temporary( _environment, VT_FLOAT, "(result of pow)");
                    temporary = variable_temporary( _environment, VT_FLOAT, "(result of pow)");
                    variable_store_float( _environment, result->name, 1 );
                    cpu_bveq( _environment, counter->realName, endLabel );
                    cpu_label( _environment, label );
                    switch( base->precision ) {
                        case FT_FAST:
                            cpu_float_fast_mul( _environment, base->realName, result->realName, temporary->realName );
                            break;
                        case FT_SINGLE:
                            cpu_float_single_mul( _environment, base->realName, result->realName, temporary->realName );
                            break;
                        default:
                            CRITICAL_CANNOT_CAST( DATATYPE_AS_STRING[base->type], "FLOAT" );
                    }
                    variable_move( _environment, temporary->name, result->name );
                    cpu_dec( _environment, counter->realName );
                    cpu_bvneq( _environment, counter->realName, label );
                    cpu_label( _environment, endLabel );
                    break;
                }
                default:
                    CRITICAL_POW_UNSUPPORTED( _exponential, DATATYPE_AS_STRING[base->type]);
            }
        }
    }
    return result;
}