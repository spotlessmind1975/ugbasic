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

/**
 * @brief Emit ASM code for <b>FOR ...</b>
 * 
 * This function outputs the code to implement the starting
 * point of a FOR...NEXT loop
 * 
 * @param _environment Current calling environment
 * @param _index Variable to use as index
 * @param _from Starting value
 * @param _to Ending value
 */
/* <usermanual>
@keyword FOR...NEXT

@english

The ''FOR...NEXT''  is a basic tool for executing a block of code a 
specified number of times. It is a control structure that creates a 
loop, which is a segment of code that is repeated until a certain 
condition is met. Once inside the loop, the index used to loop
can be read and modified by the program as if it is a normal variable.

Normally, the index counter is increased by 1 unit at every turn of a 
''FOR...NEXT'' loop. When the current value exceeds that of the last 
number specified, the loop is terminated. ''STEP'' is used to 
change the size of increase in the index value.

The ''FOR...NEXT'' loop is ideal for performing the same operation 
a specific number of times. It can be used to create tables of 
values, such as a multiplication table. It is often used in 
algorithms that require repeated calculations, such as calculating 
the factorial of a number. Generally speaking, you can use the
''FOR...NEXT'' when you know the number of iterations in advance,
want to perform a sequence of operations repetitively and you
need a simple and effective control structure.

@italian

''FOR...NEXT'' è uno strumento di base per eseguire un blocco 
di codice un numero di volte specificato. È una struttura di 
controllo che crea un ciclo, ovvero un segmento di codice 
che viene ripetuto finché non viene soddisfatta una determinata 
condizione. Una volta all'interno del ciclo, l'indice utilizzato 
per il ciclo può essere letto e modificato dal programma come 
se fosse una variabile normale.

Normalmente, il contatore dell'indice viene aumentato di 1 unità 
a ogni giro di un ciclo ''FOR...NEXT''. Quando il valore corrente 
supera quello dell'ultimo numero specificato, il ciclo viene terminato. 
''STEP'' viene utilizzato per modificare la dimensione dell'aumento 
del valore dell'indice.

Il ciclo ''FOR...NEXT'' è ideale per eseguire la stessa operazione
un numero di volte specifico. Può essere utilizzato per creare 
tabelle di valori, come una tabella di moltiplicazione. Viene spesso
utilizzato in algoritmi che richiedono calcoli ripetuti, come il 
calcolo del fattoriale di un numero. In generale, è possibile 
utilizzare ''FOR...NEXT'' quando si conosce in anticipo il numero
di iterazioni, si desidera eseguire una sequenza di operazioni 
in modo ripetitivo e si necessita di una struttura di controllo
semplice ed efficace.

@syntax FOR var = start TO end [ STEP increment ]
@syntax    ...
@syntax NEXT [var]

@example i = 0
@example FOR i = 1 TO 100 STEP 2
@example    PRINT i
@example NEXT

@usedInExample control_controlled_01.bas
@usedInExample control_controlled_02.bas

@seeAlso DO...LOOP
@seeAlso WHILE...WEND
@seeAlso REPEAT...UNTIL

</usermanual> */

void begin_for_prepare( Environment * _environment ) {

    MAKE_LABEL

    Loop * loop = malloc( sizeof( Loop ) );
    memset( loop, 0, sizeof( Loop ) );
    loop->label = strdup( label );
    loop->type = LT_FOR;
    loop->next = _environment->loops;
    _environment->loops = loop;

    unsigned char beginForPrepareAfter[MAX_TEMPORARY_STORAGE]; sprintf(beginForPrepareAfter, "%sprepa", label );

    cpu_jump( _environment, beginForPrepareAfter );

}

void begin_for_from_prepare( Environment * _environment ) {

    Loop * loop = _environment->loops;

    unsigned char beginForFromPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForFromPrepare, "%sprepfrom", loop->label );

    cpu_label( _environment, beginForFromPrepare );

}

void begin_for_from_assign( Environment * _environment, char * _from ) {

    Loop * loop = _environment->loops;

    Variable * from = variable_retrieve( _environment, _from );
    Variable * fromResident = variable_resident( _environment, from->type, "(from)" );

    variable_move( _environment, from->name, fromResident->name );

    cpu_return( _environment );

    loop->from = from;
    loop->from->locked = 1;
    loop->fromResident = fromResident;
    loop->fromResident->locked = 1;

    loop->to = NULL;

}

void begin_for_to_prepare( Environment * _environment ) {

    Loop * loop = _environment->loops;

    unsigned char beginForToPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForToPrepare, "%sprepto", loop->label );

    cpu_label( _environment, beginForToPrepare );

}

void begin_for_to_assign( Environment * _environment, char * _to ) {

    Loop * loop = _environment->loops;
    Variable * to = variable_retrieve( _environment, _to );
    Variable * toResident = variable_resident( _environment, to->type, "(to)" );

    variable_move( _environment, to->name, toResident->name );

    cpu_return( _environment );

    loop->to = to;
    loop->to->locked = 1;
    loop->toResident = toResident;
    loop->toResident->locked = 1;

}

void begin_for_step_prepare( Environment * _environment ) {

    Loop * loop = _environment->loops;

    unsigned char beginForStepPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForStepPrepare, "%sprepstep", loop->label );

    cpu_label( _environment, beginForStepPrepare );

}

void begin_for_step_assign( Environment * _environment, char * _step ) {

    Loop * loop = _environment->loops;

    Variable * from = loop->from;
    Variable * to = loop->to;

    // Calculate the maximum rappresentable size for the index, based on from and to.
    int maxType = VT_MAX_BITWIDTH_TYPE( from->type, to->type );

    Variable * stepResident = NULL;
    if ( _step ) {
        Variable * step = variable_retrieve( _environment, _step );
        if ( VT_SIGNED( from->type ) || VT_SIGNED( to->type ) || VT_SIGNED( step->type ) ) {
            maxType = VT_SIGN( maxType );
        }
        // In this version, the step is given
        stepResident = variable_resident( _environment, maxType, "(step)" );
        variable_move( _environment, step->name, stepResident->name );
        loop->step = step;
        loop->step->locked = 1;
    } else {
        if ( VT_SIGNED( from->type ) || VT_SIGNED( to->type ) ) {
            maxType = VT_SIGN( maxType );
        }
        // In this version, the step is not given - by default, step = 1
        stepResident = variable_resident( _environment, maxType, "(step 1)" );
        variable_store( _environment, stepResident->name, 1 );
    }

    loop->stepResident = stepResident;
    loop->stepResident->locked = 1;

    cpu_return( _environment );

}

void begin_for_identifier( Environment * _environment, char * _index ) {

    Loop * loop = _environment->loops;

    unsigned char beginForPrepareAfter[MAX_TEMPORARY_STORAGE]; sprintf(beginForPrepareAfter, "%sprepa", loop->label );
    unsigned char beginForFromPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForFromPrepare, "%sprepfrom", loop->label );
    unsigned char beginForToPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForToPrepare, "%sprepto", loop->label );
    unsigned char beginForStepPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForStepPrepare, "%sprepstep", loop->label );

    cpu_label( _environment, beginForPrepareAfter );

    cpu_call( _environment, beginForFromPrepare );
    cpu_call( _environment, beginForToPrepare );
    cpu_call( _environment, beginForStepPrepare );

    Variable * index = NULL;
    if ( variable_exists( _environment, _index ) ) {
        index = variable_retrieve( _environment, _index );
    } else {
        index = variable_retrieve_or_define( _environment, _index, _environment->defaultVariableType, 0 );
    }

    Variable * from = loop->fromResident;
    Variable * to = loop->toResident;
    Variable * step = loop->stepResident;

    unsigned char beginFor[MAX_TEMPORARY_STORAGE]; sprintf(beginFor, "%sbf", loop->label );
    unsigned char backwardFor[MAX_TEMPORARY_STORAGE]; sprintf(backwardFor, "%sback", loop->label );
    unsigned char forwardFor[MAX_TEMPORARY_STORAGE]; sprintf(forwardFor, "%sforw", loop->label );
    unsigned char continueFor[MAX_TEMPORARY_STORAGE]; sprintf(continueFor, "%scont", loop->label );
    unsigned char endFor[MAX_TEMPORARY_STORAGE]; sprintf(endFor, "%sbis", loop->label );

    Variable * isLastStep;

    variable_move( _environment, loop->fromResident->name, index->name );

    cpu_label( _environment, beginFor );

    cpu_bvneq( _environment, variable_greater_than_const( _environment, loop->stepResident->name, 0, 0)->realName, forwardFor );

    cpu_jump( _environment, backwardFor );

    cpu_label( _environment, forwardFor );

    // Finish the loop if the index is less than lower bound.
    isLastStep = variable_less_than( _environment, index->name, loop->fromResident->name, 0 );
    cpu_bvneq( _environment, isLastStep->realName, endFor );

    // Finish the loop if the index is less than upper bound.
    isLastStep = variable_greater_than( _environment, index->name, loop->toResident->name, 0 );
    cpu_bvneq( _environment, isLastStep->realName, endFor );

    cpu_jump( _environment, continueFor );

    cpu_label( _environment, backwardFor );

    // Finish the loop if the index is less than lower bound.
    isLastStep = variable_greater_than( _environment, index->name, loop->fromResident->name, 0 );
    cpu_bvneq( _environment, isLastStep->realName, endFor );

    // Finish the loop if the index is less than upper bound.
    isLastStep = variable_less_than( _environment, index->name, loop->toResident->name, 0 );
    cpu_bvneq( _environment, isLastStep->realName, endFor );

    cpu_label( _environment, continueFor );

    loop->index = index;

}

void begin_for( Environment * _environment, char * _index, char * _from, char * _to ) {

    Variable * index = NULL;

    Variable * from = variable_retrieve( _environment, _from );
    Variable * to = variable_retrieve( _environment, _to );

    int maxType = VT_MAX_BITWIDTH_TYPE( from->type, to->type );

    if ( VT_SIGNED( from->type ) || VT_SIGNED( to->type ) ) {
        maxType = VT_SIGN( maxType );
    }

    Variable * step = variable_resident( _environment, maxType, "(step 1)" );

    if ( variable_exists( _environment, _index ) ) {
        index = variable_retrieve( _environment, _index );
    } else {
        index = variable_retrieve_or_define( _environment, _index, maxType, 0 );
    }

    Variable * toResident = variable_resident( _environment, index->type, "(resident to)" );
    variable_move( _environment, to->name, toResident->name );
    
    variable_store( _environment, step->name, 1 );
    
    MAKE_LABEL

    Loop * loop = malloc( sizeof( Loop ) );
    memset( loop, 0, sizeof( Loop ) );
    loop->label = strdup( label );
    loop->type = LT_FOR;
    loop->next = _environment->loops;
    loop->index = index;
    loop->from = from;
    loop->from->locked = 1;
    loop->fromResident = from;
    loop->fromResident->locked = 1;
    loop->to = to;
    loop->to->locked = 1;
    loop->toResident = to;
    loop->toResident->locked = 1;
    if ( step ) {
        loop->step = step;
        loop->step->locked = 1;
    }
    loop->stepResident = step;
    loop->stepResident->locked = 1;
    loop->statical = 1;
    _environment->loops = loop;

    variable_move( _environment, from->name, index->name );

    unsigned char beginFor[MAX_TEMPORARY_STORAGE]; sprintf(beginFor, "%sbf", loop->label );
    unsigned char endFor[MAX_TEMPORARY_STORAGE]; sprintf(endFor, "%sbis", loop->label );

    cpu_label( _environment, beginFor );

    Variable * isLastStep = variable_greater_than( _environment, index->name, loop->to->name, 0 );

    cpu_bvneq( _environment, isLastStep->realName, endFor );

}
