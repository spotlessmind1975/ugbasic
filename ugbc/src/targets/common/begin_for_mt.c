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

void begin_for_to_prepare_mt( Environment * _environment ) {

    MAKE_LABEL

    Loop * loop = malloc( sizeof( Loop ) );
    memset( loop, 0, sizeof( Loop ) );
    loop->label = strdup( label );
    loop->type = LT_FOR_MT;
    loop->next = _environment->loops;
    _environment->loops = loop;

    unsigned char beginForPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForPrepare, "%sprep", label );
    unsigned char beginForPrepareAfter[MAX_TEMPORARY_STORAGE]; sprintf(beginForPrepareAfter, "%sprepa", label );

    cpu_jump( _environment, beginForPrepareAfter );
    cpu_label( _environment, beginForPrepare );

}

void begin_for_step_prepare_mt( Environment * _environment, char * _from, char * _to, char * _step ) {

    Loop * loop = _environment->loops;

    Variable * from = variable_retrieve( _environment, _from );
    Variable * to = variable_retrieve( _environment, _to );

    // Calculate the maximum rappresentable size for the index, based on from and to.
    int maxType = VT_MAX_BITWIDTH_TYPE( from->type, to->type );

    if ( VT_SIGNED( from->type ) || VT_SIGNED( to->type ) ) {
        maxType = VT_SIGN( maxType );
    }

    Variable * step = NULL;
    Variable * stepResident = NULL;

    if ( ! _step ) {
        // In this version, the step is not given - by default, step = 1
        stepResident = variable_resident( _environment, maxType, "(step 1)" );
        variable_store( _environment, stepResident->name, 1 );
    } else {
        // In this version, the step is given
        step = variable_retrieve( _environment, _step );
        stepResident = variable_resident( _environment, maxType, "(step)" );
        variable_move( _environment, step->name, stepResident->name );
    }    

    if ( step ) {
        loop->step = step;
        loop->step->locked = 1;
    }

    loop->stepResident = stepResident;
    loop->stepResident->locked = 1;

}

void begin_for_from_mt( Environment * _environment, char * _index, char * _from, char * _to, char * _step ) {

    Loop * loop = _environment->loops;
    unsigned char beginForPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForPrepare, "%sprep", loop->label );
    unsigned char beginForPrepareAfter[MAX_TEMPORARY_STORAGE]; sprintf(beginForPrepareAfter, "%sprepa", loop->label );

    cpu_return( _environment );
    cpu_label( _environment, beginForPrepareAfter );

    // Retrieve index and extremes. 
    Variable * index = NULL;
    Variable * from = variable_retrieve( _environment, _from );
    Variable * to = variable_retrieve( _environment, _to );

    index = variable_retrieve( _environment, _index );

    if ( index->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( index->name );
    }

    // Calculate the maximum rappresentable size for the index, based on from and to.
    int maxType = VT_MAX_BITWIDTH_TYPE( from->type, to->type );

    if ( VT_SIGNED( from->type ) || VT_SIGNED( to->type ) ) {
        maxType = VT_SIGN( maxType );
    }

    Variable * step = NULL;
    Variable * stepResident = NULL;
    if ( ! _step ) {
        // In this version, the step is not given - by default, step = 1
        stepResident = variable_resident( _environment, maxType, "(step 1)" );
        variable_store( _environment, stepResident->name, 1 );
    } else {
        // In this version, the step is given
        step = variable_retrieve( _environment, _step );
        stepResident = variable_resident( _environment, maxType, "(step)" );
        variable_move( _environment, step->name, stepResident->name );
    }

    // Start by copying the from to index.
    parser_array_init( _environment );    
    parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
    variable_move_array( _environment, index->name, from->name );
    parser_array_cleanup( _environment );

    // --- --- --- START OF LOOP --- --- ---

    unsigned char beginFor[MAX_TEMPORARY_STORAGE]; sprintf(beginFor, "%sbf", loop->label );
    unsigned char assignStep[MAX_TEMPORARY_STORAGE]; sprintf(assignStep, "%sas", loop->label );
    unsigned char assignStepAfter[MAX_TEMPORARY_STORAGE]; sprintf(assignStepAfter, "%sasa", loop->label );
    cpu_label( _environment, beginFor );

    cpu_call( _environment, beginForPrepare );

    // Update the resident version of from and step at each loop.
    Variable * fromResident = variable_resident( _environment, from->type, "(from)" );
    variable_move( _environment, from->name, fromResident->name );
    if ( loop->step ) {
        cpu_jump( _environment, assignStepAfter );
        cpu_label( _environment, assignStep );
        variable_move( _environment, loop->step->name, loop->stepResident->name );
        cpu_return( _environment );
        cpu_label( _environment, assignStepAfter );
    }

    loop->from = from;
    loop->from->locked = 1;
    loop->fromResident = fromResident;
    loop->fromResident->locked = 1;
    _environment->loops = loop;

}

void begin_for_to_mt( Environment * _environment, char *_to ) {

    Variable * to = variable_retrieve( _environment, _to );
    Variable * toResident = variable_resident( _environment, to->type, "(to)" );

    // Update the resident version of to at each loop.
    variable_move( _environment, to->name, toResident->name );
    
    Loop * loop = _environment->loops;
    loop->to = to;
    loop->to->locked = 1;
    loop->to = toResident;
    loop->to->locked = 1;
}

void begin_for_identifier_mt( Environment * _environment, char * _index ) {

    Loop * loop = _environment->loops;

    Variable * index = variable_retrieve( _environment, _index );
    if ( index->type != VT_ARRAY ) {
        CRITICAL_NOT_ARRAY( index->name );
    }

    parser_array_init( _environment );
    parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
    Variable * value = variable_move_from_array( _environment, index->name );
    parser_array_cleanup( _environment );

    Variable * from = loop->fromResident;
    Variable * to = loop->toResident;
    Variable * step = loop->stepResident;

    unsigned char endFor[MAX_TEMPORARY_STORAGE]; sprintf(endFor, "%sbis", loop->label );

    Variable * isLastStep;

    // Finish the loop if the index is less than lower bound.
    isLastStep = variable_less_than( _environment, value->name, loop->from->name, 0 );
    cpu_bvneq( _environment, isLastStep->realName, endFor );

    // Finish the loop if the index is less than upper bound.
    isLastStep = variable_greater_than( _environment, value->name, loop->to->name, 0 );
    cpu_bvneq( _environment, isLastStep->realName, endFor );

    loop->index = index;

}