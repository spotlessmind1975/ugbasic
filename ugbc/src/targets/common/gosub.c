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
 * @brief Emit ASM code for <b>GOSUB [label]</b>
 * 
 * This function can be used to issue a code equivalent to a unconditional 
 * jump to an alphanumeric label, previously or subsequently defined, with 
 * the syntax of the labels, saving the calling address.
 * 
 * @param _environment Current calling environment
 * @param _label Label where to jump to
 */
/* <usermanual>
@keyword GOSUB

@english

The ''GOSUB'' command allows you to "jump" to a specific part of the program,
execute a set of instructions and then return exactly to the point where 
you started. 

It allows you to break a program into smaller, more manageable 
blocks of code, improving readability and maintenance. A subroutine can be called 
multiple times from different parts of the program, avoiding rewriting the same 
code multiple times. It helps organize the flow of the program, making it clearer 
and easier to follow. 

While ''GOTO'' allows an unconditional jump to any line of the program, 
''GOSUB'' is more structured and allows a return to the starting point. 
In general, ''GOSUB'' is considered a more powerful and flexible tool than 
''GOTO'', as it allows for better organization of the code.

It is possible to nest subroutines, but it is important to make sure that 
each ''GOSUB'' has its corresponding ''RETURN''. So, a common mistake is to 
forget to put ''RETURN'' at the end of a subroutine, causing unpredictable 
behavior of the program.

Subroutines are often implemented through functions and procedures, which 
offer more advanced functionality and more rigorous management of
variable scope.

@italian

Il comando ''GOSUB'' consente di "saltare" a una parte specifica del programma, 
eseguire una serie di istruzioni e quindi tornare esattamente al punto di partenza.

Consente di suddividere un programma in blocchi di codice più piccoli e gestibili, 
migliorandone la leggibilità e la manutenzione. Una subroutine può essere chiamata 
più volte da diverse parti del programma, evitando di riscrivere lo stesso codice 
più volte. Aiuta a organizzare il flusso del programma, rendendolo più chiaro e 
facile da seguire.

Mentre ''GOTO'' consente un salto incondizionato a qualsiasi riga del programma, 
''GOSUB'' è più strutturato e consente di tornare al punto di partenza.
In generale, ''GOSUB'' è considerato uno strumento più potente e flessibile 
di ''GOTO'', poiché consente una migliore organizzazione del codice.

È possibile annidare le subroutine, ma è importante assicurarsi che ogni ''GOSUB'' 
abbia il suo ''RETURN'' corrispondente. Quindi, un errore comune è dimenticare 
di mettere ''RETURN'' alla fine di una subroutine, causando un comportamento 
imprevedibile del programma.

Le subroutine sono spesso implementate tramite funzioni e procedure, che 
offrono funzionalità più avanzate e una gestione più rigorosa dell'ambito 
delle variabili.

@syntax GOSUB label

@example GOSUB leggiTasti

@usedInExample control_returning_01.bas
@usedInExample control_returning_02.bas

@seeAlso RETURN
@seeAlso POP

</usermanual> */
void gosub_label( Environment * _environment, char * _label ) {

    label_referred_define_named( _environment, _label );

    cpu_call( _environment, _label );

}

/**
 * @brief Emit ASM code for <b>GOSUB [number]</b>
 * 
 * This function can be used to issue a code equivalent to a unconditional 
 * jump to a numeric label, previously or subsequently defined, with 
 * the syntax of the labels, saving the calling address.
 * 
 * @param _environment Current calling environment
 * @param _label Label where to jump to
 */
void gosub_number( Environment * _environment, int _number ) {

    label_referred_define_numeric( _environment, _number );

    char label[MAX_TEMPORARY_STORAGE]; sprintf( label, "_linenumber%d", _number );

    cpu_call( _environment, label );

}
