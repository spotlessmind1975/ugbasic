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
 * @brief Emit ASM code for <b>DO ...</b>
 * 
 * This function outputs the code to implement the starting
 * point of a DO...LOOP loop.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword DO...LOOP

@english

Repeats a block of statements. Use a ''DO...LOOP'' structure when you want to repeat a set of statements an 
indefinite number of times, or until an ''EXIT'' control out of the loop. If you want to repeat the statements a set number of times, the ''FOR...NEXT'' 
statement is usually a better choice, while if you want to repeat for specific conditions, you should use
the ''WHILE...WEND'' and ''REPEAT...UNTIL'' statements. 

The ''DO...LOOP'' structure gives you less flexibility than the ''WHILE'' / ''UNTIL'' statements because you cannot decide whether to end the loop 
when a specific condition stops being ''TRUE'' or when it first becomes ''TRUE''. It also disallow you to 
test condition at either the start or the end of the loop. You can nest ''DO...LOOPS'' by putting one loop within another. You can also nest different kinds of control 
structures within each other. 

@italian

Ripete un blocco di istruzioni. Si usa una struttura ''DO...LOOP'' quando si desidera ripetere una serie di 
istruzioni un numero indefinito di volte o fino a quando un controllo ''EXIT'' esce dal ciclo. Se si vuol 
ripetere le istruzioni un determinato numero di volte, l'istruzione ''FOR...NEXT'' è solitamente una scelta
migliore, mentre se si vuol ripetere per condizioni specifiche, dovresti usare l'istruzione ''WHILE...WEND'
e ''REPEAT...UNTIL''.

La struttura ''DO...LOOP'' offre meno flessibilità rispetto alle istruzioni ''WHILE'' / ''UNTIL'' perché non 
è possibile decidere se terminare il ciclo quando una condizione specifica smette di essere ''TRUE'' o quando 
diventa per la prima volta ''TRUE''. Inoltre non consente di testare la condizione all'inizio o alla fine del
ciclo. Puoi annidare ''DO...LOOPS'' inserendo un loop all'interno di un altro. Puoi anche annidare diversi tipi
di strutture di controllo l'una nell'altra.

@syntax DO
@syntax   ... instructions ...
@syntax LOOP

@example DO
@example   x = x + 1
@example LOOP
@usedInExample control_loops_01.bas
@usedInExample control_loops_02.bas
@usedInExample control_loops_03.bas
@usedInExample control_loops_04.bas
@usedInExample control_loops_05.bas

@target all
</usermanual> */
void begin_do_loop( Environment * _environment ) {

    begin_loop( _environment, 1 );

}
