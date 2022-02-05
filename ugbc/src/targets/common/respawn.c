/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit code for <strong>SPAWN ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the procedure
 */
/* <usermanual>
@keyword RESPAWN

@english
This keyword will restart a (finished) (parallel) procedure. 

@italian
Questa parola chiave fa ricominciare una funzione terminata,
affinché sia eseguita in parallelo.

@syntax RESPAWN [name][{[parameter],{[parameter],....}}]

@example RESPAWN factorialHandle(42)

@target all
</usermanual> */
Variable * respawn_procedure( Environment * _environment, char * _name ) {

    MAKE_LABEL

    Variable * threadId = variable_retrieve( _environment, _name );
    Variable * threadState = variable_temporary( _environment, VT_BYTE, "(current thread state)" );

    if ( threadId->type != VT_THREAD ) {
        CRITICAL_CANNOT_RESPAWN_NOT_THREADID( _name );
    }
    
    _environment->anyProtothread = 1;

    char doNothingLabel[MAX_TEMPORARY_STORAGE]; sprintf(doNothingLabel, "%snothing", label );

    cpu_protothread_get_state( _environment, threadId->realName, threadState->realName );
    cpu_compare_and_branch_8bit_const( _environment, threadState->realName, PROTOTHREAD_STATUS_ENDED, doNothingLabel, 0 );
    cpu_protothread_set_state( _environment, threadId->realName, PROTOTHREAD_STATUS_WAITING );
    
    cpu_label( _environment, doNothingLabel );

    return threadId;

}

