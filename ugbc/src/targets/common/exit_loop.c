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
 * @brief Emit ASM code for <b>EXIT</b>
 * 
 * This function out of the loop. Optionally, the programmer can
 * give the number of loops to jump out.
 * 
 * @param _environment Current calling environment
 * @param _number Number of loops to exit.
 */
/* <usermanual>
@keyword EXIT

@english

The ''EXIT'' command is used to stop execution of a specific block of code
and transfer control of the program to the first statement following that block.
It is often used inside ''FOR...NEXT'', ''WHILE...WEND'', or ''DO...LOOP'' loops 
to terminate the loop prematurely when a certain condition is met. The optional parameter
''number'' specifies the number of inner blocks you want to exit. If missing,
the implicit value is 1.

The command is useful to exit when an error or unexpected condition occurs, and it
can be used to end the code block and handle the error appropriately. In some cases, 
using ''EXIT'' can make your code more efficient by avoiding executing unnecessary 
statements. ''EXIT'' allows you to create more complex control flows and make dynamic decisions 
during program execution.  Excessive use of ''EXIT'', however,
can make your code more difficult to read and maintain.

@italian

Il comando ''EXIT'' viene utilizzato per interrompere l'esecuzione di un blocco 
di codice specifico e trasferire il controllo del programma alla prima istruzione 
successiva a tale blocco.

Viene spesso utilizzato all'interno dei cicli ''FOR...NEXT'', ''WHILE...WEND'' o
''DO...LOOP'' per terminare il ciclo prematuramente quando viene soddisfatta 
una determinata condizione. Il parametro facoltativo ''number'' specifica il numero 
di blocchi interni da cui si desidera uscire. Se manca, il valore implicito è 1. 
Il comando è utile per uscire quando si verifica un errore o una condizione 
imprevista e può essere utilizzato per terminare il blocco di codice e gestire 
l'errore in modo appropriato. In alcuni casi, l'utilizzo di ''EXIT'' può rendere 
il codice più efficiente evitando di eseguire istruzioni non necessarie. ''EXIT'' 
consente di creare flussi di controllo più complessi e di prendere decisioni 
dinamiche durante l'esecuzione del programma. L'uso eccessivo di ''EXIT'' 
può rendere il codice più difficile da leggere e gestire.

@syntax EXIT [number]

@example EXIT
@example EXIT 2

@usedInExample control_loops_02.bas
@usedInExample control_loops_03.bas

@target all
</usermanual> */
void exit_loop( Environment * _environment, int _number ) {

    

    Loop * loop = _environment->loops;

    if ( ! loop ) {
        CRITICAL_EXIT_WITHOUT_LOOP();
    }

    if ( _number ) {
        --_number;
    }

    while( _number-- ) {
        loop = loop->next;

        if ( ! loop ) {
            CRITICAL_EXIT_WITHOUT_ENOUGH_LOOP();
        }
    }

    unsigned char newLabel[MAX_TEMPORARY_STORAGE]; sprintf(newLabel, "%sbis", loop->label );

    cpu_jump( _environment, newLabel );

}
