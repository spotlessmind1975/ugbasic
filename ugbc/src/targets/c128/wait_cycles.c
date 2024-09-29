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
 * @brief Emit ASM code for <b>WAIT # [integer] CYCLES</b>
 * 
 * This function outputs a code that engages the CPU in a busy wait.
 * 
 * @param _environment Current calling environment
 * @param _timing Number of cycles to wait
 */
/* <usermanual>
@keyword WAIT

@english

Pauses execution for a certain period of time. The ''WAIT'' statement can be 
accompanied by a suffix statement, which indicates the unit of measurement of
the time to wait. The suffix ''CYCLES'' can be used to indicate CPU cycles, 
''TICKS'' to indicate the number of vertical blanks at 50Hz (PAL) or 60Hz (NTSC),
and ''MS'' (''MILLISECONDS'') to indicate a number of milliseconds.

The pause is of the "busy" type, so the entire program is suspended, except for 
the timer-related mechanisms but including the multithreading mechanism. To 
avoid this, you can follow the instruction with the ''PARALLEL'' keyword, 
which allows parallel processes to continue executing while waiting for the time.

The ''PARALLEL'' keyword can only be used with waits related to ''CYCLES''.

@italian

Interrompe l'esecuzione per un certo periodo di tempo. L'istruzione ''WAIT'' può 
essere corredata da una istruzione suffisso, che si occupa di indicare l'unità di 
misura del tempo da attendere. Si può usare il suffisso ''CYCLES'' per indicare 
cicli di CPU, ''TICKS'' per indicare il numero di blank verticali a 50Hz (PAL) 
o 60Hz (NTSC), e ''MS'' (''MILLISECONDS'') per indicare un numero di millisecondi.

La pausa è di tipo "busy", quindi tutto il programma viene sospeso, ad esclusione 
dei meccanismi legati ai timer ma compreso il meccanismo di multithreading. Per 
evitarlo è possibile far seguire l'istruzione dalla parola chiave ''PARALLEL'', 
che consente di far proseguire l'esecuzione di processi paralleli mentre viene 
atteso il tempo.

La parola chiave ''PARALLEL'' può essere usata solo con attese legate ai ''CYCLES''.

@syntax WAIT cycles [CYCLES] [PARALLEL]
@syntax WAIT ticks TICK
@syntax WAIT ticks TICKS
@syntax WAIT time MILLISECOND
@syntax WAIT time MILLISECONDS
@syntax WAIT time MS

@example WAIT #42 CYCLES
@usedInExample control_uncond_jumps_01.bas
@usedInExample control_uncond_jumps_02.bas
@usedInExample control_returning_01.bas
@usedInExample control_returning_02.bas

@target all
</usermanual> */
void wait_cycles( Environment * _environment, int _timing, int _parallel ) {

    if ( _environment->protothread && _environment->procedureName && _parallel ) {

        if ( _environment->protothreadForbid ) {
            CRITICAL_MULTITASKING_FORBIDDEN();
        }

        char waitVariableName[MAX_TEMPORARY_STORAGE]; sprintf(waitVariableName, "%swaitms%d", _environment->procedureName, _environment->protothreadStep );

        ///////////
        memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayDimensionsEach[0] = _environment->protothreadConfig.count;
        ((struct _Environment *)_environment)->arrayDimensions = 1;
        variable_define( _environment, waitVariableName, VT_TARRAY, 0 );
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

        char timingString[MAX_TEMPORARY_STORAGE]; sprintf(timingString, "#$%2.2x", _timing );

        cpu6502_busy_wait( _environment, timingString );

    }

}

/**
 * @brief Emit ASM code for <b>WAIT [expression] CYCLES</b>
 * 
 * This function outputs a code that engages the CPU in a busy wait.
 * 
 * @param _environment Current calling environment
 * @param _timing Number of cycles to wait
 */
void wait_cycles_var( Environment * _environment, char * _timing, int _parallel ) {

    MAKE_LABEL

    Variable * timing = variable_retrieve( _environment, _timing );

    if ( _environment->protothread && _environment->procedureName && _parallel) {

        char waitVariableName[MAX_TEMPORARY_STORAGE]; sprintf(waitVariableName, "%swaitms%d", _environment->procedureName, _environment->protothreadStep );

        ///////////
        memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayDimensionsEach[0] = _environment->protothreadConfig.count;
        ((struct _Environment *)_environment)->arrayDimensions = 1;
        variable_define( _environment, waitVariableName, VT_TARRAY, 0 );
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

        cpu6502_busy_wait( _environment, timing->realName );

    }

}
