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
 * @brief Emit ASM code for <b>... NEXT</b>
 * 
 * This function outputs the code to implement the end of
 * a for...next loop, by defining the last point of the loop.
 * 
 * @param _environment Current calling environment
 */
void end_for_identifier( Environment * _environment, char * _index ) {

    Variable * index = variable_retrieve( _environment, _index );
    
    Loop * loop = _environment->loops;

    if ( ! loop ) {
        CRITICAL_NEXT_WITHOUT_FOR();
    }

    if ( loop->type != LT_FOR && loop->type != LT_FOR_MT ) {
        CRITICAL_NEXT_WITHOUT_FOR();
    }

    if ( strcmp( loop->index->name, index->name ) ) {
        CRITICAL_WRONG_NEXT_INDEX(_index);
    }

    end_for( _environment );

}

void end_for( Environment * _environment ) {

    Loop * loop = _environment->loops;

    if ( ! loop ) {
        CRITICAL_NEXT_WITHOUT_FOR();
    }

    if ( loop->type != LT_FOR && loop->type != LT_FOR_MT ) {
        CRITICAL_NEXT_WITHOUT_FOR();
    }

    unsigned char beginForFromPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForFromPrepare, "%sprepfrom", loop->label );
    unsigned char beginForToPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForToPrepare, "%sprepto", loop->label );
    unsigned char beginForStepPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForStepPrepare, "%sprepstep", loop->label );

    unsigned char assignStep[MAX_TEMPORARY_STORAGE]; sprintf(assignStep, "%sas", loop->label );

    Variable * step = loop->stepResident;

    unsigned char beginFor[MAX_TEMPORARY_STORAGE]; sprintf(beginFor, "%sbf", loop->label );
    unsigned char endFor[MAX_TEMPORARY_STORAGE]; sprintf(endFor, "%sbis", loop->label );
    unsigned char beginForPrepare[MAX_TEMPORARY_STORAGE]; sprintf(beginForPrepare, "%sprep", loop->label );

    if ( !loop->statical ) {
        cpu_call( _environment, beginForFromPrepare );
        cpu_call( _environment, beginForToPrepare );
        cpu_call( _environment, beginForStepPrepare );
    }

    if ( loop->type == LT_FOR ) {

        variable_add_inplace_vars( _environment, loop->index->name, step->name );

        if ( !VT_SIGNED( loop->index->type ) ) {
            variable_compare_and_branch_const( _environment, loop->index->name, 0, endFor, 1 );
        }

        Variable * isLastStep = variable_compare( _environment, loop->index->name, loop->fromResident->name );
        cpu_bvneq( _environment, isLastStep->realName, endFor );

    } else {
        parser_array_init( _environment );
        parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
        Variable * array = variable_retrieve( _environment, loop->index->name );
        if ( array->type != VT_TARRAY ) {
            CRITICAL_NOT_ARRAY( loop->index->name );
        }
        Variable * value = variable_move_from_array( _environment, loop->index->name );
        parser_array_cleanup( _environment );

        parser_array_init( _environment );    
        parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
        Variable * stepValue = variable_move_from_array( _environment, loop->stepResident->name );
        parser_array_cleanup( _environment );

        parser_array_init( _environment );    
        parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
        Variable * fromValue = variable_move_from_array( _environment, loop->fromResident->name );
        parser_array_cleanup( _environment );        

        variable_add_inplace_vars( _environment, value->name, stepValue->name );

        parser_array_init( _environment );
        parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
        array = variable_retrieve( _environment, loop->index->name );
        if ( array->type != VT_TARRAY ) {
            CRITICAL_NOT_ARRAY( loop->index->name );
        }
        variable_move_array( _environment, loop->index->name, value->name );
        parser_array_cleanup( _environment );

        if ( !VT_SIGNED( value->type ) ) {
            variable_compare_and_branch_const( _environment, value->name, 0, endFor, 1 );
        }

        Variable * isLastStep = variable_compare( _environment, value->name, fromValue->name );
        cpu_bvneq( _environment, isLastStep->realName, endFor );

    }

    if ( _environment->procedureName && _environment->protothread && ! _environment->protothreadForbid ) {
        yield( _environment );
    }
    
    cpu_jump( _environment, beginFor );

    cpu_label( _environment, endFor );

    if ( loop->to ) {
        loop->to->locked = 0;
    }
    if ( loop->from ) {
        loop->from->locked = 0;
    }
    if ( loop->step ) {
        loop->step->locked = 0;
    }
    if ( loop->zero ) {
        loop->zero->locked = 0;
    }
    if ( loop->toResident ) {
        loop->toResident->locked = 0;
    }
    if ( loop->fromResident ) {
        loop->fromResident->locked = 0;
    }
    if ( loop->stepResident ) {
        loop->stepResident->locked = 0;
    }

    _environment->loops = _environment->loops->next;

};