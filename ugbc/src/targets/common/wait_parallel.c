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
 * @brief Emit code for <strong>WAIT PARALLEL ...</strong>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword WAIT PARALLEL

@english

The ''WAIT PARALLEL'' command allows you to wait for the completion 
of a previously running mandatory thread. In order for the thread 
to be considered completed, it must reach the last statement of 
the parallel procedure, or have executed the ''EXIT PROCEDURE'' command.

@italian

Il comando ''WAIT PARALLEL'' permette di attendere il completamento di 
un thread obbligatorio in esecuzione in precedenza. Affinché il thread 
possa considerarsi completato deve raggiungere l'ultima istruzione della 
procedura parallela, oppure aver eseguito il comando ''EXIT PROCEDURE''.

@syntax WAIT PARALLEL id

@example WAIT PARALLEL exampleThread

</usermanual> */
void wait_parallel( Environment * _environment, char * _thread ) {

    _environment->anyProtothread = 1;

    if ( _environment->protothreadForbid ) {
        CRITICAL_MULTITASKING_FORBIDDEN();
    }

    if ( ! _environment->procedureName ) {
        CRITICAL_WAIT_PARALLEL_CANNOT_BE_CALLED_OUTSIDE_PROCEDURE();
    }

    yield( _environment );

    MAKE_LABEL

    char protothreadLabel[MAX_TEMPORARY_STORAGE]; sprintf(protothreadLabel, "%spt%d", _environment->procedureName, _environment->protothreadStep );

    Variable * thread = variable_retrieve_or_define( _environment, _thread, VT_THREAD, 0 );
    Variable * state = variable_temporary( _environment, VT_THREAD, "(state)" );
    Variable * endedState = variable_temporary( _environment, VT_BYTE, "(ended state)" );
    variable_store( _environment, endedState->name, PROTOTHREAD_STATUS_ENDED );

    cpu_protothread_get_state( _environment, thread->realName, state->realName );
    cpu_bvneq( _environment, variable_compare( _environment, state->name, endedState->name )->realName, protothreadLabel );

    cpu_protothread_save( _environment, "PROTOTHREADCT", ( _environment->protothreadStep - 1 ) );
    cpu_protothread_set_state( _environment, "PROTOTHREADCT", PROTOTHREAD_STATUS_WAITING );
    cpu_return( _environment );
    cpu_label( _environment, protothreadLabel );
    cpu_protothread_set_state( _environment, "PROTOTHREADCT", PROTOTHREAD_STATUS_RUNNING );

    ++_environment->protothreadStep;
    
}
