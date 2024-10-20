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

The ''DO...LOOP'' command is used for repeatedly executing a
block of statements. It creates a loop, which is a sequence of 
statements that is executed repeatedly, forever (unless exits
using the ''EXIT'' keyword). You can nest ''DO LOOP''s within other 
loops, creating more complex control structures.

If you want to repeat the statements a set number of times, 
the ''FOR...NEXT'' statement is usually a better choice, 
while if you want to repeat for specific conditions, 
you should use the ''WHILE...WEND'' and ''REPEAT...UNTIL'' 
statements. 

It can be used, i.e., to ask the user to enter a choice and repeat 
the menu until the exit option is selected. If you want to exit a loop, 
make sure the exit condition of the loop 
is changed within the loop itself, otherwise you may create an 
infinite loop. If possible, avoid performing complex calculations 
within the exit condition, as they will be repeated with each iteration
of the loop.


@italian

Il comando ''DO...LOOP'' viene utilizzato per eseguire ripetutamente 
un blocco di istruzioni. Crea un ciclo, ovvero una sequenza di 
istruzioni che viene eseguita ripetutamente, per sempre (a meno che
non esca utilizzando la parola chiave ''EXIT''). Puoi annidare 
''DO LOOP'' all'interno di altri cicli, creando strutture di controllo 
più complesse.

Se vuoi ripetere le istruzioni un numero di volte stabilito, l'istruzione 
''FOR...NEXT'' è solitamente una scelta migliore, mentre se vuoi 
ripetere per condizioni specifiche, dovresti usare le istruzioni 
''WHILE... WEND'' e ''REPEAT...UNTIL''.

Può essere utilizzato, ad esempio, per chiedere all'utente di 
immettere una scelta e ripetere il menu finché non viene selezionata 
l'opzione di uscita. Se vuoi uscire da un ciclo, assicurati che 
la condizione di uscita del ciclo venga modificata all'interno 
del ciclo stesso, altrimenti potresti creare un ciclo infinito. 
Se possibile, evita di eseguire calcoli complessi all'interno 
della condizione di uscita, poiché verranno ripetuti a ogni 
iterazione del ciclo.

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

@seeAlso WHILE...WEND
@seeAlso REPEAT...UNTIL

@target all
</usermanual> */

/* <usermanual>
@keyword LOOP...END LOOP

@english

@italian

@syntax LOOP
@syntax   ... instructions ...
@syntax END LOOP

@example LOOP
@example   x = x + 1
@example END LOOP

@alias DO...LOOP

@target all
</usermanual> */

void begin_do_loop( Environment * _environment ) {

    begin_loop( _environment, 1 );

}
