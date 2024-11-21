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
 * @brief Emit code for <strong>SUSPEND ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the procedure
 */
/* <usermanual>
@keyword SUSPEND

@english

This statement can be used to temporarily suspend the execution of a 
thread. The thread will stop executing until it receives the ''CONTINUE''
command. When queried with the ''RUNNING'' function, the thread will 
be reported as "not running".

@italian

Questa istruzione può essere utilizzata per sospendere temporaneamente 
l'esecuzione di un thread. Il thread interromperà la propria esecuzione 
fino al ricevimento del comando ''CONTINUE''. Se interrogato con la 
funzione ''RUNNING'', il thread risulterà "non in esecuzione".

@syntax SUSPEND thread

@example handle = SPAWN moveShip
@example SUSPEND handle

@target all
</usermanual> */
void suspend_vars( Environment * _environment, char * _thread ) {

    MAKE_LABEL

    Variable * threadId = variable_temporary( _environment, VT_THREAD, "(thread)");

    char doNothingLabel[MAX_TEMPORARY_STORAGE]; sprintf( doNothingLabel, "%snothing", label );

    Variable * status = variable_temporary( _environment, VT_BYTE, "(status)" );

    cpu_protothread_get_state( _environment, "PROTOTHREADCT", status->realName );

    cpu_compare_and_branch_8bit_const( _environment, status->realName, PROTOTHREAD_STATUS_RUNNING, doNothingLabel, 0 );

    cpu_protothread_set_state( _environment, threadId->realName, PROTOTHREAD_STATUS_PAUSED );

    cpu_label( _environment, doNothingLabel );
    
}

