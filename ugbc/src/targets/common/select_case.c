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
 * @brief Emit ASM code for <b>SELECT CASE ... {PASSING}</b>
 * 
 * This function outputs the code to implement a structured conditional 
 * jump. This implementation assumes that an expression passed as a parameter
 * can be compared to various expressions that will given after. If the
 * expression is equal to the this, it execute the instructions that follows,
 * until a "CASE" or an "ENDSELECT" is reached. Otherwise, it jumps directly 
 * to the next CASE statement (or CASE ELSE, if present).
 * 
 * Since the compiler acts with a single pass, 
 * it is necessary to keep the information on the last used label. 
 * For this purpose, the label where it will jump will be inserted 
 * in the stack, so that it is defined at the moment when the ENDSELECT 
 * instruction will be examined.
 * 
 * @param _environment Current calling environment
 * @param _expression Expression with the true / false condition
 */
/* <usermanual>
@keyword SELECT CASE...CASE...CASE ELSE...ENDSELECT

@english

The ''SELECT CASE'' command is part of the ''SELECT CASE...END SELECT'' structure.
It allows you to execute different blocks of code depending on the value of a
variable or expression. In practice, it is like having a series of "cases" and 
the program executes the code corresponding to the case that occurs.

The ''expression'' is evaluated at the beginning of the control block,
and its value is compared to the values specified in the cases.
Each ''CASE'' represents a possible value or a range of values
of the expression. Inside each case, you insert the instructions that 
will be executed if the value of the expression matches that case.
The ''CASE ELSE'' is optional, and it is executed if no previous 
case is true. In 8-bit computers, the semantics of ''SELECT CASE'' are
closely tied to data representation. Because registers and variables were 
often limited to 8 bits, the values that could be compared in cases are
integers between 0 and 255, also if ugBASIC supports any integer type
Anyway, it allows the expression to be compared to any integer value but,
due to the 8-bit limitation, the range of values that could be 
compared should be limited, to be effective, in terms of performances. 

Using ''SELECT CASE'' makes code clearer and easier to understand 
than a series of nested ''IF...THEN...ELSE'' statements. It can
be more efficient than a series of ''IF...THEN...ELSE'' statements.

@italian

Il comando ''SELECT CASE'' fa parte della struttura 
''SELECT CASE...END SELECT''. Consente di eseguire diversi blocchi di 
codice a seconda del valore di una variabile o espressione. In pratica, 
è come avere una serie di "casi" e il programma esegue il codice 
corrispondente al caso che si verifica.

L'espressione viene valutata all'inizio del blocco di controllo e 
il suo valore viene confrontato con i valori specificati nei casi.
Ogni ''CASE'' rappresenta un possibile valore o un intervallo di 
valori dell'espressione. All'interno di ogni caso, inserisci le 
istruzioni che verranno eseguite se il valore dell'espressione 
corrisponde a quel caso.

Il ''CASE ELSE'' è facoltativo e viene eseguito se nessun caso
precedente è vero. Nei computer a 8 bit, la semantica di 
''SELECT CASE'' è strettamente legata alla rappresentazione dei 
dati. Poiché registri e variabili erano spesso limitati a 8 bit, 
i valori che potevano essere confrontati in casi sono interi tra 
0 e 255, anche se ugBASIC supporta qualsiasi tipo di intero. In 
ogni caso, consente di confrontare l'espressione con qualsiasi 
valore intero ma, a causa della limitazione a 8 bit, l'intervallo
di valori che potevano essere confrontati dovrebbe essere limitato, 
per essere efficace, in termini di prestazioni.

L'utilizzo di ''SELECT CASE'' rende il codice più chiaro e 
facile da capire rispetto a una serie di istruzioni ''IF...THEN...ELSE'' 
annidate. Può essere più efficiente di una serie di istruzioni ''IF...THEN...ELSE''.

@syntax SELECT CASE expression
@syntax    CASE value1:
@syntax       ...
@syntax    CASE value2:
@syntax       ...
@syntax    ...
@syntax    [ CASE ELSE ]
@syntax       ...
@syntax ENDSELECT

@example SELECT CASE number
@example   CASE 1
@example      PRINT "one!"
@example   CASE 2
@example      PRINT "two!"
@example   CASE ELSE
@example      PRINT "neither!"
@example ENDSELCT

@usedInExample control_case_01.bas

@seeAlso CASE
@seeAlso CASE ELSE
@seeAlso ENDSELECT

@target all
</usermanual> */
void select_case( Environment * _environment, char * _expression ) {

    MAKE_LABEL

    Variable * expression = variable_retrieve_or_define( _environment, _expression, VT_BYTE, 0 );

    Conditional * conditional = malloc( sizeof( Conditional ) );
    memset( conditional, 0, sizeof( Conditional ) );
    conditional->label = strdup( label );
    conditional->type = CT_SELECT_CASE;

    conditional->expression = variable_cast( _environment, expression->name, expression->type );
    conditional->expression->locked = 1;
    conditional->next = _environment->conditionals;
    _environment->conditionals = conditional;

}
