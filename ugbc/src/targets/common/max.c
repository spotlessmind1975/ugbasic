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
 * @brief Return the maximum value between two expressions
 * 
 * @param _environment Current calling environment
 * @param _source Source variable's name
 * @param _destination Destination variable's name
 * @return Variable* The maximum value of both
 */
/* <usermanual>
@keyword MAX

@english

The ''MAX'' function allows you to identify the greater of two values. If both terms 
are (numeric) constants, the evaluation is carried out at the time of compilation. Otherwise, the 
value is calculated at runtime. 

Where the data types are not identical, ugBASIC "promotes" the second term to the type 
of the first term. If the conversion is not possible, a specific error will be issued. 
The comparison of heterogeneous types is, in effect, a comparison of implicitly 
promoted types. In particular, static strings are always promoted to dynamic strings.

There is also a variant of the function that accepts a single parameter. In this case, 
the parameter must be an array, and is a synonym for the ''ARRAY MAX'' command.

@italian
La funzione ''MAX'' consente di identificare il maggiore tra due valori. Se entrambi i termini 
sono costanti (numeriche), la valutazione viene effettuata al momento della compilazione. 
Altrimenti, il valore viene calcolato in fase di esecuzione.

Laddove i tipi di dati non sono identici, ugBASIC "promuove" il secondo termine al tipo del
primo termine. Se la conversione non è possibile, verrà emesso un errore specifico. Il 
confronto tra tipi eterogenei è, in effetti, un confronto tra tipi promossi implicitamente. 
In particolare, le stringhe statiche vengono sempre promosse a stringhe dinamiche.

@syntax = MAX(#const1,#const2)
@syntax = MAX(val1,val2)
@syntax = MAX(string1,string2)
@syntax = MAX(array)

@example result = MAX( a, b )
@example DIM v(21) AS INTEGER
@example v(1) = 42: PRINT MAX( v ): ' it will be 42!

@usedInExample maths_relative_01.bas

</usermanual> */
Variable * maximum( Environment * _environment, char * _source, char * _destination ) {
    
    Variable * source = variable_retrieve( _environment, _source );
    Variable * target = variable_retrieve( _environment, _destination );

    if ( source->type == VT_STRING ) {
        source = variable_cast( _environment, _source, VT_DSTRING );
    }
    if ( target->type == VT_STRING ) {
        target = variable_cast( _environment, _destination, VT_DSTRING );
    }

    Variable * result = variable_temporary( _environment, source->type, "(result of MAX)");

    MAKE_LABEL

    char greaterThanLabel[MAX_TEMPORARY_STORAGE]; sprintf( greaterThanLabel, "%sl1", label );
    char endLabel[MAX_TEMPORARY_STORAGE]; sprintf( endLabel, "%sl2", label );

    Variable * compare = variable_greater_than( _environment, source->name, target->name, 1);

    cpu_bveq( _environment, compare->realName, greaterThanLabel );

    variable_move_naked( _environment, source->name, result->name );
    
    cpu_jump( _environment, endLabel );

    cpu_label( _environment, greaterThanLabel );

    variable_move_naked( _environment, target->name, result->name );
    
    cpu_label( _environment, endLabel );

    return result;
}

