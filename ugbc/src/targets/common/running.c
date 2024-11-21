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
 * @brief Emit code for <strong>RUN PARALLEL</strong>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword RUNNING

@english
This command lets you know if a thread is in a "running" state or not. A 
thread is in this state if it has started and has not yet finished its execution.
Moreover, it is possible to know if a specific procedure is running on a given
thread, by using the second syntax.

@italian
Questo comando permette di sapere se un thread si trova in uno stato di "running" o meno. 
Un thread è in tale stato se è iniziato e ancora non ha terminato la propria esecuzione.
Inoltre, è possibile sapere se una procedura specifica è in esecuzione su un dato thread, 
utilizzando la seconda sintassi.

@syntax = RUNNING(thread[,procedur])

@example IF NOT RUNNING(wheel) THEN
@example    wheel = SPAWN wheelManager
@example ENDIF
</usermanual> */
Variable * running( Environment * _environment, char * _thread_id, char * _procedure ) {

    _environment->anyProtothread = 1;

    if ( _environment->protothreadForbid ) {
        CRITICAL_MULTITASKING_FORBIDDEN();
    }

    MAKE_LABEL

    char protothreadLabel[MAX_TEMPORARY_STORAGE]; sprintf( protothreadLabel, "%srunning", label );

    Variable * threadId = variable_retrieve_or_define( _environment, _thread_id, VT_THREAD, 0 );
    Variable * state = variable_temporary( _environment, VT_THREAD, "(state)" );
    Variable * result = variable_temporary( _environment, VT_SBYTE, "(is running)" );

    variable_store( _environment, result->name, 0 );
    
    if ( _procedure ) {
        Variable * addressRegistered = variable_temporary( _environment, VT_ADDRESS, "(address)");
        cpu_protothread_get_address( _environment, threadId->realName, addressRegistered->realName );
        char procedureName[MAX_TEMPORARY_STORAGE]; sprintf( procedureName, "PROC%s", _procedure );
        Variable * addressProcedure = variable_temporary( _environment, VT_ADDRESS, "(address)");
        cpu_addressof_16bit( _environment, procedureName, addressProcedure->realName );
        cpu_compare_and_branch_8bit_const( _environment, variable_compare( _environment, addressRegistered->name, addressProcedure->name )->realName, 0x00, label, 1 );
    }

    cpu_protothread_get_state( _environment, threadId->realName, state->realName );
    variable_compare_and_branch_const( _environment, state->name, PROTOTHREAD_STATUS_RUNNING, protothreadLabel, 1 );
    variable_compare_and_branch_const( _environment, state->name, PROTOTHREAD_STATUS_YIELDED, protothreadLabel, 1 );
    variable_store( _environment, result->name, 0x00 );
    cpu_jump( _environment, label );
    cpu_label( _environment, protothreadLabel );
    variable_store( _environment, result->name, 0xff );
    cpu_label( _environment, label );

    return result;
    
}

