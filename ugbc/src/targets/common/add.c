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

/**
 * @brief Emit code for <strong>ADD x,y,a TO b</strong>
 * 
 * @param _environment Current calling environment
 * @param _variable Variable to operate on
 * @param _expression Expression to add to the variable
 * @param _limit_lower Lower limit
 * @param _limit_upper Upper limit
 */
/* <usermanual>
@keyword ADD

@english
The ''ADD'' command can be used to add the result of an expression to a whole number variable. 
It is the equivalent to make a ''variable=variable+expression'' but performs the addition 
faster. There is a more complex version of ''ADD'', which is ideal for handling certain 
loops much more quickly than the equivalent separate instructions. When those other 
parameters are included, ''ADD v,a,b TO t'' is the equivalent to the following lines:

  v=v+a
  IF v<b THEN v=t: ENDIF
  IF v>t THEN v=b: ENDIF

@italian
Il comando ''ADD'' può essere utilizzato per aggiungere il risultato di un'espressione 
a una variabile intera. È l'equivalente di ''variabile = variabile + espressione'' ma esegue 
l'addizione molto più velocemente. Esiste una versione più complessa di ''ADD'', ideale 
per gestire determinati loop molto più rapidamente rispetto alle istruzioni separate 
equivalenti. Quando questi altri parametri sono inclusi, il comando ''ADD v, a, b TO t'' 
è equivalente alle seguenti righe:

  v=v+a
  IF v<b THEN v=t: ENDIF
  IF v>t THEN v=b: ENDIF

@syntax ADD [variable],[expression]{,[lower] TO [upper]}

@example ADD x,42,1 TO 100
@example ADD y,10

@usedInExample maths_fast_02.bas

@target all
</usermanual> */
void add_complex_vars( Environment * _environment, char * _variable, char * _expression, char * _limit_lower, char * _limit_upper ) { 

    MAKE_LABEL

    char lessThanLabel[MAX_TEMPORARY_STORAGE]; sprintf( lessThanLabel, "%sl", label );
    char greaterThanLabel[MAX_TEMPORARY_STORAGE]; sprintf( greaterThanLabel, "%sg", label );
    char endLabel[MAX_TEMPORARY_STORAGE]; sprintf( endLabel, "%se", label );
    
    variable_add_inplace_vars( _environment, _variable, _expression );

    if ( _limit_lower ) {

        Variable * less = variable_less_than( _environment, _variable, _limit_lower, 0 );

        cpu_bveq( _environment, less->realName, greaterThanLabel );

        variable_move( _environment, _limit_upper, _variable );

        cpu_jump( _environment, endLabel );

        cpu_label( _environment, greaterThanLabel );

        if ( _limit_upper ) {

            Variable * greater = variable_greater_than( _environment, _variable, _limit_upper, 0 );

            cpu_bveq( _environment, greater->realName, endLabel );

            variable_move( _environment, _limit_lower, _variable );

        }
        
        cpu_label( _environment, endLabel );

    }

}

/**
 * @brief Emit code for <strong>ADD x,y,a TO b</strong>
 * 
 * @param _environment Current calling environment
 * @param _variable Variable to operate on
 * @param _expression Expression to add to the variable
 * @param _limit_lower Lower limit
 * @param _limit_upper Upper limit
 */
/* <usermanual>
@keyword ADD

@target all
</usermanual> */
void add_complex_mt( Environment * _environment, char * _variable, char * _expression, char * _limit_lower, char * _limit_upper ) { 

    ++((struct _Environment *)_environment)->arrayNestedIndex;
    memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
    ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
    ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex]] = strdup( "PROTOTHREADCT" );
    ++((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex];
    Variable * array = variable_retrieve( _environment, _variable );
    if ( array->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( _variable );
    }
    Variable * value = variable_move_from_array( _environment, array->name );
    --((struct _Environment *)_environment)->arrayNestedIndex;

    add_complex_vars( _environment, value->name, _expression, _limit_lower, _limit_upper );

    ++((struct _Environment *)_environment)->arrayNestedIndex;
    memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
    ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
    ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex]] = strdup( "PROTOTHREADCT" );
    ++((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex];
    array = variable_retrieve( _environment, _variable );
    if ( array->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( _variable );
    }
    variable_move_array( _environment, array->name, value->name );
    --((struct _Environment *)_environment)->arrayNestedIndex;

}

/**
 * @brief Emit code for <strong>ADD x,y,a TO b</strong>
 * 
 * @param _environment Current calling environment
 * @param _variable Variable to operate on
 * @param _expression Expression to add to the variable
 * @param _limit_lower Lower limit
 * @param _limit_upper Upper limit
 */
/* <usermanual>
@keyword ADD

@target all
</usermanual> */
void add_complex_array( Environment * _environment, char * _variable, char * _expression, char * _limit_lower, char * _limit_upper ) { 

    Variable * array = variable_retrieve( _environment, _variable );
    if ( array->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( _variable );
    }
    Variable * value = variable_move_from_array( _environment, array->name );

    add_complex_vars( _environment, value->name, _expression, _limit_lower, _limit_upper );

    variable_move_array( _environment, array->name, value->name );

}

/* <usermanual>
@keyword ADD
@target all
</usermanual> */
void add_complex( Environment * _environment, char * _variable, int _expression, int _limit_lower, int _limit_upper ) { 

    MAKE_LABEL

    char lessThanLabel[MAX_TEMPORARY_STORAGE]; sprintf( lessThanLabel, "%sl", label );
    char greaterThanLabel[MAX_TEMPORARY_STORAGE]; sprintf( greaterThanLabel, "%sg", label );
    char endLabel[MAX_TEMPORARY_STORAGE]; sprintf( endLabel, "%se", label );
    
    variable_add_inplace( _environment, _variable, _expression );

    Variable * less = variable_less_than_const( _environment, _variable, _limit_lower, 0 );

    cpu_bveq( _environment, less->realName, greaterThanLabel );

    variable_store( _environment, _variable, _limit_upper );

    cpu_jump( _environment, endLabel );

    cpu_label( _environment, greaterThanLabel );

    Variable * lesser = variable_less_than_const( _environment, _variable, _limit_upper, 1 );

    cpu_bvneq( _environment, lesser->realName, endLabel );

    variable_store( _environment, _variable, _limit_lower );

    cpu_label( _environment, endLabel );

}
