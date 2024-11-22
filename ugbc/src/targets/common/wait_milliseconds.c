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
 * @brief Emit ASM code for <b>WAIT # [integer] MS</b>
 * 
 * This function outputs a code that engages the CPU in a busy wait.
 * 
 * @param _environment Current calling environment
 * @param _timing Number of cycles to wait
 */
void wait_milliseconds( Environment * _environment, int _timing ) {

    int timing = _timing / 20;

    if ( _environment->protothread && !_environment->protothreadForbid ) {

        MAKE_LABEL

        char waitVariableName[MAX_TEMPORARY_STORAGE]; sprintf(waitVariableName, "%swaitms%s", _environment->procedureName, label );
        char doneLabel[MAX_TEMPORARY_STORAGE]; sprintf(doneLabel, "%sdone%sstep", _environment->procedureName, label );

        ///////////
        memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayDimensionsEach[0] = _environment->protothreadConfig.count;
        ((struct _Environment *)_environment)->arrayDimensions = 1;
        variable_define( _environment, waitVariableName, VT_TARRAY, 0 );
        variable_array_type( _environment, waitVariableName, VT_WORD );
        ///////////

        variable_move_to_mt( _environment, variable_add_const( _environment, get_timer( _environment )->name, timing )->name, waitVariableName );

        begin_loop( _environment, 1 );
            Variable * result = variable_temporary( _environment, VT_WORD, "(temporary)" );
            variable_move_from_mt( _environment, waitVariableName, result->name );
            variable_compare_and_branch_const( _environment, 
                variable_greater_than( _environment,
                    get_timer( _environment )->name,
                    result->name,
                    1
                )->name, 0xff, doneLabel, 1 );
        end_loop( _environment, 1 );
      
        cpu_label( _environment, doneLabel );

    } else {

        wait_ticks( _environment, timing );

    }

}

/**
 * @brief Emit ASM code for <b>WAIT [expression] MILLISECONDS</b>
 * 
 * This function outputs a code that engages the CPU in a busy wait.
 * 
 * @param _environment Current calling environment
 * @param _timing Number of cycles to wait
 */
void wait_milliseconds_var( Environment * _environment, char * _timing ) {

    Variable * realTiming = variable_div_const( _environment, variable_retrieve( _environment, _timing )->name, 20, NULL );

    if ( _environment->protothread && !_environment->protothreadForbid ) {

        MAKE_LABEL

        char waitVariableName[MAX_TEMPORARY_STORAGE]; sprintf(waitVariableName, "%swaitms%s", _environment->procedureName, label );
        char doneLabel[MAX_TEMPORARY_STORAGE]; sprintf(doneLabel, "%sdone%sstep", _environment->procedureName, label );

        ///////////
        memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayDimensionsEach[0] = _environment->protothreadConfig.count;
        ((struct _Environment *)_environment)->arrayDimensions = 1;
        variable_define( _environment, waitVariableName, VT_TARRAY, 0 );
        variable_array_type( _environment, waitVariableName, VT_WORD );
        ///////////

        variable_move_to_mt( _environment, variable_add( _environment, get_timer( _environment )->name, realTiming->name )->name, waitVariableName );

        begin_loop( _environment, 1 );
            Variable * result = variable_temporary( _environment, VT_WORD, "(temporary)" );
            variable_move_from_mt( _environment, waitVariableName, result->name );
            variable_compare_and_branch_const( _environment, 
                variable_greater_than( _environment,
                    get_timer( _environment )->name,
                    result->name, 
                    1
                )->name, 0xff, doneLabel, 1 );
        end_loop( _environment, 1 );

        cpu_label( _environment, doneLabel );

    } else {

        wait_ticks_var( _environment, realTiming->name );

    }

}

