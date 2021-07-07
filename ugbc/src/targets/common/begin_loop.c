/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
This instruction define a loop, or a list of statements that will be executed forever.
''DO'' acts as the starting position while ''LOOP'' the endig one.

@italian
Questa istruzione definisce un "loop" cioè un elenco di istruzioni che saranno
eseguite per sempre. La parola chiave ''DO'' indica il punto di innesto del
loop mentre la parola ''LOOP'' l'ultima istruzione del loop.

@syntax DO : ... : LOOP
@syntax DO
@syntax   ...
@syntax LOOP

@example DO : x = x + 1 : LOOP
@usedInExample control_loops_01.bas
@usedInExample control_loops_02.bas
@usedInExample control_loops_03.bas
@usedInExample control_loops_04.bas
@usedInExample control_loops_05.bas

@target all
</usermanual> */
void begin_loop( Environment * _environment ) {

    outline0( "; DO ... ");

    MAKE_LABEL

    Loop * loop = malloc( sizeof( Loop ) );
    memset( loop, 0, sizeof( Loop ) );
    loop->label = strdup( label );
    loop->type = LT_DO;
    loop->next = _environment->loops;
    _environment->loops = loop;

    cpu_label( _environment, loop->label );

}
