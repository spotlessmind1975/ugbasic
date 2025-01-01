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
 * @brief Emit code for <strong>KILL ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _handle Identifier of the thread
 */
/* <usermanual>
@keyword KILL

@english

The ''KILL'' command terminates the execution of a thread, 
thereby stopping its execution and returning it to a "terminated" 
state. This command occurs regardless of what the thread is doing; 
therefore, it can cause processes or procedures to fail. Any 
thread can be killed at any time, as long as it is active. 
If a thread is not active, killing it will have no effect.
You can interrupt a set of threads contained in an array 
by supplying the array name.

@italian

Il comando ''KILL'' termina l'esecuzione di un thread, fermandone 
così l'esecuzione e riportandolo allo stato "terminato". Questo 
comando si verifica indipendentemente da ciò che sta facendo il 
thread; pertanto, può causare il fallimento di processi o p
rocedure. Qualsiasi thread può essere terminato in qualsiasi 
momento, purché sia ​​attivo. Se un thread non è attivo, 
terminarlo non avrà alcun effetto. E' possibile interrompere 
un insieme di thread contenuti in un array fornendo il nome dell'array.

@syntax KILL id[,id[,...]]

@example KILL handleThread

</usermanual> */
void kill_procedure( Environment * _environment, char * _handle ) {

    MAKE_LABEL

    Variable * threadId = variable_retrieve( _environment, _handle );

    if ( threadId->type != VT_THREAD ) {
        CRITICAL_CANNOT_KILL_NOT_THREADID( _handle );
    }

    if ( _environment->protothreadForbid ) {
        CRITICAL_MULTITASKING_FORBIDDEN();
    }
    
    _environment->anyProtothread = 1;

    cpu_protothread_set_state( _environment, threadId->realName, PROTOTHREAD_STATUS_ENDED );
    cpu_protothread_unregister( _environment, threadId->realName );

}

