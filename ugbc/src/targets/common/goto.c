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
 * @brief Emit ASM code for <b>GOTO [label]</b>
 * 
 * This function can be used to issue a code equivalent to the unconditional 
 * jump to an alphanumeric label, previously or subsequently defined, with 
 * the syntax of the labels.
 * 
 * @param _environment Current calling environment
 * @param _label Label where to jump to
 */
/* <usermanual>
@keyword GOTO

@english

The ''GOTO'' command is a statement that allows you to jump unconditionally 
to another part of the program. In practice, instead of executing the instructions 
in sequence, the program "jumps" directly to the line indicated by the ''GOTO'' command.

Despite its simplicity, indiscriminate use of the ''GOTO'' command can lead to several 
problems. It can make the code very difficult to follow and understand, creating 
so-called "spaghetti code". If a program contains many unconditional jumps, it can 
become very difficult to find the source of an error. Frequent use of ''GOTO'' tends to
create a poorly structured flow of control that is difficult to maintain.

The ugBASIC ​​offers more sophisticated and readable control structures, such as: 
''IF...THEN...ELSE'', ''FOR...NEXT'', ''DO...LOOP'', and so on. These structures make
the code clearer and make it easier to manage the flow of control.

In some specific cases, however, the use of ''GOTO'' can be justified, for example 
in very specific situations, a ''GOTO'' can be used to exit a nested loop more efficiently.
In some cases, a ''GOTO'' can be used to handle errors in the most direct way.
In general, it is advisable to avoid the use of ''GOTO'' and prefer more modern 
control structures. A well-structured and readable code is easier to maintain 
and to change over time.

@italian

Il comando ''GOTO'' è un'istruzione che consente di saltare incondizionatamente 
a un'altra parte del programma. In pratica, invece di eseguire le istruzioni 
in sequenza, il programma "salta" direttamente alla riga indicata dal comando 
''GOTO''.

Nonostante la sua semplicità, l'uso indiscriminato del comando ''GOTO'' può 
portare a diversi problemi. Può rendere il codice molto difficile da seguire 
e comprendere, creando il cosiddetto "codice spaghetti". Se un programma contiene 
molti salti incondizionati, può diventare molto difficile trovare la fonte di 
un errore. L'uso frequente di ''GOTO'' tende a creare un flusso di controllo 
mal strutturato che è difficile da mantenere.

L'ugBASIC offre strutture di controllo più sofisticate e leggibili, come: 
''IF...THEN...ELSE'', ''FOR...NEXT'', ''DO...LOOP'' e così via. Queste 
strutture rendono il codice più chiaro e facilitano la gestione del 
flusso di controllo.

In alcuni casi specifici, tuttavia, l'uso di ''GOTO'' può essere giustificato, 
ad esempio in situazioni molto specifiche, un ''GOTO'' può essere utilizzato 
per uscire da un ciclo annidato in modo più efficiente.

In alcuni casi, un ''GOTO'' può essere utilizzato per gestire gli errori 
nel modo più diretto. In generale, è consigliabile evitare l'uso di ''GOTO'' 
e preferire strutture di controllo più moderne. Un codice ben strutturato e 
leggibile è più facile da mantenere e da modificare nel tempo.

@syntax GOTO label

@example GOTO nuovaEtichetta

@usedInExample control_uncond_jumps_01.bas
@usedInExample control_uncond_jumps_02.bas
@usedInExample control_returning_01.bas
@usedInExample control_returning_02.bas

</usermanual> */
void goto_label( Environment * _environment, char * _label ) {

    label_referred_define_named( _environment, _label );

    cpu_jump( _environment, _label );

}

/**
 * @brief Emit ASM code for <b>GOTO [number]</b>
 * 
 * This function can be used to issue a code equivalent to the unconditional 
 * jump to an alphanumeric label, previously or subsequently defined, with 
 * the syntax of the labels.
 * 
 * @param _environment Current calling environment
 * @param _label Label where to jump to
 * 
 * @todo Dynamic GOTO (GOTO [expression])
 */
/* <usermanual>
@keyword GOTO

@syntax GOTO number

@example GOTO 42
</usermanual> */
void goto_number( Environment * _environment, int _number ) {

    label_referred_define_numeric( _environment, _number );

    char label[MAX_TEMPORARY_STORAGE]; sprintf( label, "_linenumber%d", _number );

    cpu_jump( _environment, label );

}
