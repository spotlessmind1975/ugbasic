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
 * @brief Emit ASM code for <b>REPEAT ...</b>
 * 
 * This function outputs the code to implement the starting
 * point of a REPEAT...UNTIL loop.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword REPEAT...UNTIL

@english

The '''REPEAT...UNTIL'' command will repeatedly execute a block of code until a certain 
condition is met. In essence, it creates a loop that continues to repeat until a specific 
exit condition is met.

When you don't know exactly how many times you want to repeat a block of code, but you 
want to continue until a certain condition is met, this is the best command to use.
For example, to repeatedly prompt the user for input until they enter it correctly.
Another usage is to perform calculations that require multiple iterations, such as 
finding the square root of a number using the Newton-Raphson method.

Make sure the condition inside ''UNTIL'' can become true at some point, otherwise your 
program may end up in an infinite loop. If you need to execute a loop a large number 
of times, consider optimizing your code to improve performance.

@italian

Il comando '''REPEAT...UNTIL'' eseguirà ripetutamente un blocco di codice finché 
non viene soddisfatta una determinata condizione. In sostanza, crea un ciclo che 
continua a ripetersi finché non viene soddisfatta una specifica condizione di uscita.

Quando non sai esattamente quante volte vuoi ripetere un blocco di codice, ma vuoi 
continuare finché non viene soddisfatta una determinata condizione, questo è il 
comando migliore da usare. 

Ad esempio, per chiedere ripetutamente all'utente di immettere un input finché non 
lo inserisce correttamente. Un altro utilizzo è per eseguire calcoli che richiedono 
più iterazioni, come trovare la radice quadrata di un numero utilizzando il metodo 
Newton-Raphson.

Assicurati che la condizione all'interno di ''UNTIL'' possa diventare vera a un 
certo punto, altrimenti il ​​tuo programma potrebbe finire in un ciclo infinito. 
Se hai bisogno di eseguire un ciclo un gran numero di volte, prendi in considerazione 
l'ottimizzazione del tuo codice per migliorare le prestazioni.

@syntax REPEAT 
@syntax     ...
@syntax UNTIL expression 

@example REPEAT
@example   score = score + 1
@example UNTIL alive

@usedInExample control_loops_05.bas

@seeAlso DO...LOOP
@seeAlso WHILE...WEND
@seeAlso FOR...NEXT

</usermanual> */
void begin_repeat( Environment * _environment ) {

    MAKE_LABEL

    Loop * loop = malloc( sizeof( Loop ) );
    loop->label = strdup( label );
    loop->type = LT_REPEAT;
    loop->next = _environment->loops;
    _environment->loops = loop;

    unsigned char newLabel[MAX_TEMPORARY_STORAGE]; sprintf(newLabel, "%sbis", loop->label );

    if ( _environment->procedureName && _environment->protothread && ! _environment->protothreadForbid ) {
        yield( _environment );
    }

    cpu_label( _environment, loop->label );

}
