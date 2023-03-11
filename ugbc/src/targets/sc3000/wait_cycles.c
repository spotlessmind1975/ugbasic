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
 * @brief Emit ASM code for <b>WAIT [int] CYCLES</b>
 * 
 * This function outputs a code that engages the CPU in a busy wait.
 * 
 * @param _environment Current calling environment
 * @param _timing Number of cycles to wait
 */
/* <usermanual>
@keyword WAIT

@target sc3000
</usermanual> */
void wait_cycles( Environment * _environment, int _timing, int _parallel ) {

    if ( _environment->protothread && _environment->procedureName && _parallel ) {

        char waitVariableName[MAX_TEMPORARY_STORAGE]; sprintf(waitVariableName, "%swaitms%d", _environment->procedureName, _environment->protothreadStep );

        ///////////
        memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayDimensionsEach[0] = _environment->protothreadConfig.count;
        ((struct _Environment *)_environment)->arrayDimensions = 1;
        variable_define( _environment, waitVariableName, VT_ARRAY, 0 );
        variable_array_type( _environment, waitVariableName, VT_WORD );
        ///////////

        variable_store_array_const( _environment, waitVariableName, _timing );

        yield( _environment );

        char protothreadLabel[MAX_TEMPORARY_STORAGE]; sprintf(protothreadLabel, "%spt%d", _environment->procedureName, _environment->protothreadStep );
        
        variable_decrement_mt( _environment, waitVariableName );
        Variable * result = variable_temporary( _environment, VT_WORD, "(temporary)" );
        variable_move_from_mt( _environment, waitVariableName, result->name );
        variable_compare_and_branch_const( _environment, result->name, 0,  protothreadLabel, 1 );

        cpu_protothread_save( _environment, "PROTOTHREADCT", ( _environment->protothreadStep - 1 ) );
        cpu_protothread_set_state( _environment, "PROTOTHREADCT", PROTOTHREAD_STATUS_YIELDED );
        cpu_return( _environment );

        cpu_label( _environment, protothreadLabel );
        cpu_protothread_set_state( _environment, "PROTOTHREADCT", PROTOTHREAD_STATUS_RUNNING );

        ++_environment->protothreadStep;

    } else {
    
        char timingString[MAX_TEMPORARY_STORAGE]; sprintf(timingString, "$%2.2x", _timing );

        z80_busy_wait( _environment, timingString );

    }

}

/**
 * @brief Emit ASM code for <b>WAIT [int] CYCLES</b>
 * 
 * This function outputs a code that engages the CPU in a busy wait.
 * 
 * @param _environment Current calling environment
 * @param _timing Number of cycles to wait
 */
void wait_cycles_var( Environment * _environment, char * _timing, int _parallel ) {

    Variable * timing = variable_retrieve( _environment, _timing );
    
    if ( _environment->protothread && _environment->procedureName && _parallel) {

        char waitVariableName[MAX_TEMPORARY_STORAGE]; sprintf(waitVariableName, "%swaitms%d", _environment->procedureName, _environment->protothreadStep );

        ///////////
        memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayDimensionsEach[0] = _environment->protothreadConfig.count;
        ((struct _Environment *)_environment)->arrayDimensions = 1;
        variable_define( _environment, waitVariableName, VT_ARRAY, 0 );
        variable_array_type( _environment, waitVariableName, VT_WORD );
        ///////////

        variable_move_to_mt( _environment, _timing, waitVariableName );

        yield( _environment );

        char protothreadLabel[MAX_TEMPORARY_STORAGE]; sprintf(protothreadLabel, "%spt%d", _environment->procedureName, _environment->protothreadStep );
        
        variable_decrement_mt( _environment, waitVariableName );
        Variable * result = variable_temporary( _environment, VT_WORD, "(temporary)" );
        variable_move_from_mt( _environment, waitVariableName, result->name );
        variable_compare_and_branch_const( _environment, result->name, 0,  protothreadLabel, 1 );

        cpu_protothread_save( _environment, "PROTOTHREADCT", ( _environment->protothreadStep - 1 ) );
        cpu_protothread_set_state( _environment, "PROTOTHREADCT", PROTOTHREAD_STATUS_YIELDED );
        cpu_return( _environment );

        cpu_label( _environment, protothreadLabel );
        cpu_protothread_set_state( _environment, "PROTOTHREADCT", PROTOTHREAD_STATUS_RUNNING );

        ++_environment->protothreadStep;


    } else {

        z80_busy_wait( _environment, timing->realName );

    }

}
