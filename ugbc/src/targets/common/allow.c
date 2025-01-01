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
@keyword ALLOW

@english

The ''ALLOW'' instruction is the opposite of the ''FORBID'' function. While ''FORBID''
completely blocks multitasking, ''ALLOW'' re-enables it, allowing ugBASIC to schedule 
again the execution of other tasks, passing the execution from one task to another 
according to its scheduling policy. If a ''PROCEDURE'' has previously called ''FORBID''
to assure exclusive access to the CPU, ''ALLOW'' returns control to the other procedures,
allowing other procedures to continue execution.

Note that this type of control is "static": in other words, compilation will stop if
the procedure that called ''FORBID'' subsequently wants to call a function that
would require multitasking to be active. The call to ''ALLOW'' will restore multitasking, 
and allow routines of this type to be called.

Once a procedure has finished executing a section of code that required exclusive access
to the processor, it should call ''ALLOW'' to allow other tasks to be executed.

If a task needs to wait for an event (for example, a signal), it can call ''ALLOW'' before 
entering a waiting state, allowing other tasks to execute their code while the waiting task 
is suspended.

Using ''FORBID'' and ''ALLOW'' in a balanced way is essential to achieve both good 
performance and correct synchronization between parallel procedures. In many cases, 
more sophisticated synchronization mechanisms, such as shared variables, could be used 
without completely disabling multitasking.

@italian
L'istruzione ''ALLOW'' è l'opposto della funzione ''FORBID''. Mentre ''FORBID'' 
blocca completamente il multitasking, ''ALLOW'' lo riattiva, consentendo a ugBASIC 
di pianificare nuovamente l'esecuzione di altri task, passando l'esecuzione da un 
task all'altro in base alla sua politica di pianificazione. Se una ''PROCEDURE'' 
ha precedentemente chiamato ''FORBID'' per garantire l'accesso esclusivo alla CPU, 
''ALLOW'' restituisce il controllo alle altre procedure, consentendo ad altre 
procedure di continuare l'esecuzione.

Nota che questo tipo di controllo è "statico": in altre parole, la compilazione 
si interromperà se la procedura che ha chiamato ''FORBID'' desidera successivamente 
chiamare una funzione che richiederebbe l'attivazione del multitasking. La chiamata
a ''ALLOW'' ripristinerà il multitasking e consentirà la chiamata di routine di 
questo tipo.

Una volta che una procedura ha terminato di eseguire una sezione di codice che
richiedeva l'accesso esclusivo al processore, dovrebbe chiamare ''ALLOW'' per
consentire l'esecuzione di altre attività.

Se un'attività deve attendere un evento (ad esempio, un segnale), può chiamare
''ALLOW'' prima di entrare in uno stato di attesa, consentendo ad altre attività 
di eseguire il loro codice mentre l'attività di attesa è sospesa.

Utilizzare ''FORBID'' e ''ALLOW'' in modo equilibrato è essenziale per ottenere
sia buone prestazioni che una corretta sincronizzazione tra procedure parallele.
In molti casi, meccanismi di sincronizzazione più sofisticati, come le variabili 
condivise, potrebbero essere utilizzati senza disabilitare completamente il 
multitasking.

@syntax ALLOW

@example PARALLEL PROCEDURE test
@example    FORBID
@example    ' busy waiting, multitasking is suspended!
@example    FOR i=0 TO 1000: WAIT 1 MS : NEXT i
@example    ALLOW
@example END PROC

@seeAlso FORBID

@target all
</usermanual> */
void allow( Environment * _environment ) {

    _environment->anyProtothread = 1;

    if ( _environment->protothreadForbid ) {
        _environment->protothreadForbid = 0;
    } else {
        CRITICAL_MULTITASKING_NOT_FORBIDDEN();
    }

}

