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
 * @brief Emit code for <strong>YIELD</strong>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword FORBID

@english

In some situations, it is necessary to ensure that a sequence of operations is executed 
atomically, without interruption. The ''FORBID'' instruction plays a crucial role 
in this way, offering the programmer a way to take full control of the system's execution, 
at least temporarily.

In simple terms, ''FORBID'' blocks any attempt by ugBASIC to pass execution from one task 
to another. This means that the task that called ''FORBID'' will continue to execute 
its code without interruption until a corresponding call to ''ALLOW'' is made. The ''FORBID''
ensures that a sequence of critical operations is executed indivisibly, 
without interference from other tasks. This gives the programmer granular control 
over the system's execution.

@italian

In alcune situazioni, è necessario garantire che una sequenza di operazioni venga 
eseguita in modo atomico, senza interruzioni. L'istruzione ''FORBID'' svolge un ruolo 
cruciale in questo senso, offrendo al programmatore un modo per assumere il pieno 
controllo dell'esecuzione del sistema, almeno temporaneamente.

In parole povere, ''FORBID'' blocca qualsiasi tentativo di ugBASIC di passare 
l'esecuzione da un task a un altro. Ciò significa che il task che ha chiamato 
''FORBID'' continuerà a eseguire il suo codice senza interruzioni finché non verrà 
effettuata una chiamata corrispondente a ''ALLOW''. ''FORBID'' assicura che 
una sequenza di operazioni critiche venga eseguita in modo indivisibile, 
senza interferenze da parte di altri task. Ciò fornisce al programmatore 
un controllo granulare sull'esecuzione del sistema.

@syntax FORBID

@example PARALLEL PROCEDURE test
@example    FORBID
@example    ' busy waiting, multitasking is suspended!
@example    FOR i=0 TO 1000: WAIT 1 MS : NEXT i
@example    ALLOW
@example END PROC

@target all
</usermanual> */
void forbid( Environment * _environment ) {

    _environment->anyProtothread = 1;

    if ( ! _environment->protothreadForbid ) {
        _environment->protothreadForbid = 1;
    } else {
        CRITICAL_MULTITASKING_ALREADY_FORBIDDEN();
    }

}

