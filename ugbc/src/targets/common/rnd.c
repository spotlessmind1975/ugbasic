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
 * @brief Return a random value 
 * 
 * @param _environment Current calling environment
 * @param _value Maximum value for the random value
 * @return Variable* The random value
 */
/* <usermanual>
@keyword RND

@english
The ''RND'' function generates integers at random, between zero and any number specified
in brackets. If your specified number is greater than zero, random numbers will be generated 
up to that maximum number. However, if you specify 0, then ''RND'' will return the last 
random value it generated. This is useful for debugging programs.

@italian
La funzione ''RND'' genera numeri interi casuali, compresi tra zero e qualsiasi numero 
specificato tra parentesi. Se il numero specificato è maggiore di zero, verranno generati 
numeri casuali fino a quel numero massimo. Tuttavia, se si specifica 0, ''RND'' restituirà 
l'ultimo valore casuale generato. Questo è utile per il debug dei programmi.

@syntax RND([max])

@example score = score + RND(100)

@usedInExample maths_rand_01.bas

@target all
</usermanual> */
Variable * rnd( Environment * _environment, char * _value ) {

    Variable * last_random = variable_temporary( _environment, VT_DWORD, "(last temporary for RND)");
    last_random->locked = 1;

    Variable * value = variable_retrieve( _environment, _value );

    Variable * result = random_value( _environment, value->type );

    Variable * bresult = variable_temporary( _environment, VT_BYTE, "(temporary for RND)");

    Variable * ignored = variable_temporary( _environment, value->type, "(ignored)");
    Variable * remainder = variable_temporary( _environment, value->type, "(remainder)");

    Variable * zero = variable_temporary( _environment, value->type, "(0)" );
    variable_store( _environment, zero->name, 0 );
    
    MAKE_LABEL

    char endLabel[MAX_TEMPORARY_STORAGE]; sprintf(endLabel, "%send", label );
    char lastRandomLabel[MAX_TEMPORARY_STORAGE]; sprintf(lastRandomLabel, "%slr", label );

    if_then( _environment, variable_compare( _environment, value->name, zero->name )->name );
        cpu_jump( _environment, lastRandomLabel );
    end_if_then( _environment );

    switch( VT_BITWIDTH( value->type ) ) {
        case 32:
            cpu_math_div_32bit_to_16bit( _environment, result->realName, value->realName, ignored->realName, remainder->realName, 0 );
            cpu_move_32bit( _environment, remainder->realName, result->realName );
            cpu_move_32bit( _environment, remainder->realName, last_random->realName );
            cpu_jump( _environment, endLabel );
            break;
        case 16:
            cpu_math_div_16bit_to_16bit( _environment, result->realName, value->realName, ignored->realName, remainder->realName, 0 );
            cpu_move_16bit( _environment, remainder->realName, result->realName );
            cpu_move_16bit( _environment, remainder->realName, last_random->realName );
            cpu_jump( _environment, endLabel );
            break;
        case 8:
            cpu_math_div_8bit_to_8bit( _environment, result->realName, value->realName, ignored->realName, remainder->realName, 0 );
            cpu_move_8bit( _environment, remainder->realName, result->realName );
            cpu_move_8bit( _environment, remainder->realName, last_random->realName );
            cpu_jump( _environment, endLabel );
            break;
        case 0:
            CRITICAL_RANDOM_UNSUPPORTED( _value, DATATYPE_AS_STRING[value->type] );
            break;
    }

    cpu_label( _environment, lastRandomLabel );

    variable_move( _environment, last_random->name, result->name );

    cpu_label( _environment, endLabel );
    
    return result;
}