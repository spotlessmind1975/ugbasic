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

void begin_for_prepare_mt( Environment * _environment ) {

    MAKE_LABEL

    Loop * loop = malloc( sizeof( Loop ) );
    memset( loop, 0, sizeof( Loop ) );
    loop->label = strdup( label );
    loop->type = LT_FOR_MT;
    loop->next = _environment->loops;
    _environment->loops = loop;

    unsigned char beginForPrepareAfter[MAX_TEMPORARY_STORAGE]; sprintf(beginForPrepareAfter, "%sprepa", label );

    cpu_jump( _environment, beginForPrepareAfter );

}

void begin_for_from_prepare_mt( Environment * _environment ) {

    Loop * loop = _environment->loops;

    unsigned char beginForFromPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForFromPrepare, "%sprepfrom", loop->label );

    cpu_label( _environment, beginForFromPrepare );

}

void begin_for_from_assign_mt( Environment * _environment, char * _from ) {

    Loop * loop = _environment->loops;

    Variable * from = variable_retrieve( _environment, _from );
    Variable * fromResident = variable_resident( _environment, VT_ARRAY, "(from)" );
    _environment->arrayDimensionsEach[0] = _environment->protothreadConfig.count;
    _environment->arrayDimensions = 1;
    variable_array_type( _environment, fromResident->name, from->type );

    parser_array_init( _environment );    
    parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
    variable_move_array( _environment, fromResident->name, from->name );
    parser_array_cleanup( _environment );

    cpu_return( _environment );

    loop->from = from;
    loop->from->locked = 1;
    loop->fromResident = fromResident;
    loop->fromResident->locked = 1;

    loop->to = NULL;

}

void begin_for_to_prepare_mt( Environment * _environment ) {

    Loop * loop = _environment->loops;

    unsigned char beginForToPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForToPrepare, "%sprepto", loop->label );

    cpu_label( _environment, beginForToPrepare );

}

void begin_for_to_assign_mt( Environment * _environment, char * _to ) {

    Loop * loop = _environment->loops;
    Variable * to = variable_retrieve( _environment, _to );

    Variable * toResident = variable_resident( _environment, VT_ARRAY, "(to)" );
    _environment->arrayDimensionsEach[0] = _environment->protothreadConfig.count;
    _environment->arrayDimensions = 1;
    variable_array_type( _environment, toResident->name, to->type );

    parser_array_init( _environment );    
    parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
    variable_move_array( _environment, toResident->name, to->name );
    parser_array_cleanup( _environment );

    cpu_return( _environment );

    loop->to = to;
    loop->to->locked = 1;
    loop->toResident = toResident;
    loop->toResident->locked = 1;

}

void begin_for_step_prepare_mt( Environment * _environment ) {

    Loop * loop = _environment->loops;

    unsigned char beginForStepPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForStepPrepare, "%sprepstep", loop->label );

    cpu_label( _environment, beginForStepPrepare );

}

void begin_for_step_assign_mt( Environment * _environment, char * _step ) {

    Loop * loop = _environment->loops;
    Variable * step = NULL;

    Variable * from = loop->from;
    Variable * to = loop->to;

    // Calculate the maximum rappresentable size for the index, based on from and to.
    int maxType = VT_MAX_BITWIDTH_TYPE( from->type, to->type );

    Variable * stepResident = NULL;
    if ( _step ) {
        step = variable_retrieve( _environment, _step );
        if ( VT_SIGNED( from->type ) || VT_SIGNED( to->type ) || VT_SIGNED( step->type ) ) {
            maxType = VT_SIGN( maxType );
        }

        // In this version, the step is given
        stepResident = variable_resident( _environment, VT_ARRAY, "(to)" );
        _environment->arrayDimensionsEach[0] = _environment->protothreadConfig.count;
        _environment->arrayDimensions = 1;
        variable_array_type( _environment, stepResident->name, step->type );

        parser_array_init( _environment );    
        parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
        variable_move_array( _environment, stepResident->name, step->name );
        parser_array_cleanup( _environment );

        if ( step ) {
            loop->step = step;
            loop->step->locked = 1;
        }
    } else {

        if ( VT_SIGNED( from->type ) || VT_SIGNED( to->type ) ) {
            maxType = VT_SIGN( maxType );
        }
        // In this version, the step is not given - by default, step = 1
        step = variable_temporary( _environment, _environment->defaultVariableType, "(step 1)" );
        variable_store( _environment, step->name, 1 );

        stepResident = variable_resident( _environment, VT_ARRAY, "(to)" );
        _environment->arrayDimensionsEach[0] = _environment->protothreadConfig.count;
        _environment->arrayDimensions = 1;
        variable_array_type( _environment, stepResident->name, _environment->defaultVariableType );

        parser_array_init( _environment );    
        parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
        variable_move_array( _environment, stepResident->name, step->name );
        parser_array_cleanup( _environment );
    }

    loop->stepResident = stepResident;
    loop->stepResident->locked = 1;

    cpu_return( _environment );

    if ( step ) {
        loop->step = step;
        loop->step->locked = 1;
    }
    loop->stepResident = stepResident;
    loop->stepResident->locked = 1;

}

void begin_for_identifier_mt( Environment * _environment, char * _index ) {

    Loop * loop = _environment->loops;

    unsigned char beginForPrepareAfter[MAX_TEMPORARY_STORAGE]; sprintf(beginForPrepareAfter, "%sprepa", loop->label );
    unsigned char beginForFromPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForFromPrepare, "%sprepfrom", loop->label );
    unsigned char beginForToPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForToPrepare, "%sprepto", loop->label );
    unsigned char beginForStepPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForStepPrepare, "%sprepstep", loop->label );

    cpu_label( _environment, beginForPrepareAfter );

    cpu_call( _environment, beginForFromPrepare );
    cpu_call( _environment, beginForToPrepare );
    cpu_call( _environment, beginForStepPrepare );

    Variable * index = variable_retrieve( _environment, _index );

    loop->index = index;

    Variable * from = loop->fromResident;
    Variable * to = loop->toResident;
    Variable * step = loop->stepResident;

    unsigned char beginFor[MAX_TEMPORARY_STORAGE]; sprintf(beginFor, "%sbf", loop->label );
    unsigned char backwardFor[MAX_TEMPORARY_STORAGE]; sprintf(backwardFor, "%sback", loop->label );
    unsigned char forwardFor[MAX_TEMPORARY_STORAGE]; sprintf(forwardFor, "%sforw", loop->label );
    unsigned char continueFor[MAX_TEMPORARY_STORAGE]; sprintf(continueFor, "%scont", loop->label );
    unsigned char endFor[MAX_TEMPORARY_STORAGE]; sprintf(endFor, "%sbis", loop->label );

    Variable * isLastStep;

    parser_array_init( _environment );    
    parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
    Variable * fromValue = variable_move_from_array( _environment, loop->fromResident->name );
    parser_array_cleanup( _environment );

    parser_array_init( _environment );    
    parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
    variable_move_array( _environment, index->name, fromValue->name );
    parser_array_cleanup( _environment );

    cpu_label( _environment, beginFor );

    parser_array_init( _environment );    
    parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
    Variable * indexValue = variable_move_from_array( _environment, loop->index->name );
    parser_array_cleanup( _environment );

    parser_array_init( _environment );    
    parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
    Variable * stepValue = variable_move_from_array( _environment, loop->stepResident->name );
    parser_array_cleanup( _environment );

    parser_array_init( _environment );    
    parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
    fromValue = variable_move_from_array( _environment, loop->fromResident->name );
    parser_array_cleanup( _environment );

    parser_array_init( _environment );    
    parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
    Variable * toValue = variable_move_from_array( _environment, loop->toResident->name );
    parser_array_cleanup( _environment );

    cpu_bvneq( _environment, variable_greater_than_const( _environment, stepValue->name, 0, 0)->realName, forwardFor );

    cpu_jump( _environment, backwardFor );

    cpu_label( _environment, forwardFor );

    // Finish the loop if the index is less than lower bound.
    isLastStep = variable_less_than( _environment, indexValue->name, fromValue->name, 0 );
    cpu_bvneq( _environment, isLastStep->realName, endFor );

    // Finish the loop if the index is less than upper bound.
    isLastStep = variable_greater_than( _environment, indexValue->name, toValue->name, 0 );
    cpu_bvneq( _environment, isLastStep->realName, endFor );

    cpu_jump( _environment, continueFor );

    cpu_label( _environment, backwardFor );

    // Finish the loop if the index is less than lower bound.
    isLastStep = variable_greater_than( _environment, indexValue->name, fromValue->name, 0 );
    cpu_bvneq( _environment, isLastStep->realName, endFor );

    // Finish the loop if the index is less than upper bound.
    isLastStep = variable_less_than( _environment, indexValue->name, toValue->name, 0 );
    cpu_bvneq( _environment, isLastStep->realName, endFor );

    cpu_label( _environment, continueFor );

}

/////////////////////////////////////////////////

