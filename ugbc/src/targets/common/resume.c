/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit code for <strong>RESUME ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the procedure
 */
/* <usermanual>
@keyword RESUME

@english

This statement can be used to resume execution of a previously suspended 
thread. If applied to a thread that is not running, is running, or 
is waiting for a condition to continue execution, this will have no effect.

@italian

Questa istruzione può essere utilizzata per riprendere l'esecuzione di 
un thread sospeso in precedenza. Se applicato a un thread non in 
esecuzione, in esecuzione o in attesa di una condizione per continuare 
l'esecuzione, questo non comporterà alcun effetto.

@syntax RESUME thread

@example handle = SPAWN moveShip
@example SUSPEND handle
@example RUN PARALLEL
@example RESUME handle

@target all
</usermanual> */
void resume_vars( Environment * _environment, char * _thread ) {

    MAKE_LABEL

    Variable * threadId = variable_retrieve( _environment, _thread );

    char doNothingLabel[MAX_TEMPORARY_STORAGE]; sprintf( doNothingLabel, "%snothing", label );

    Variable * status = variable_temporary( _environment, VT_BYTE, "(status)" );

    cpu_protothread_get_state( _environment, threadId->realName, status->realName );

    cpu_compare_and_branch_8bit_const( _environment, status->realName, PROTOTHREAD_STATUS_PAUSED, doNothingLabel, 0 );

    cpu_protothread_set_state( _environment, threadId->realName, PROTOTHREAD_STATUS_RUNNING );

    cpu_label( _environment, doNothingLabel );
        
}

