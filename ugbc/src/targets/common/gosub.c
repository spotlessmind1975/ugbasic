/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
Do an unconditional jump to an alphanumeric label, previously or 
subsequently defined, with the syntax of the labels. When a ''RETURN''
is encountered, the execution will continue to the instruction next
to this one.

@italian
Effettua un salto incondizionato a un'etichetta, definita in precedenza o
successivamente. Quando si incontrerà il comando ''RETURN'', l'esecuzione
continuerà all'istruzione successiva a qeusta.

@syntax GOSUB [label]

@example GOSUB leggiTasti

@target all

@seeAlso RETURN
@seeAlso POP
@usedInExample control_returning_01.bas
@usedInExample control_returning_02.bas

</usermanual> */
void gosub_label( Environment * _environment, char * _label ) {

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
/* <usermanual>
@keyword GOSUB

@syntax GOSUB [number]

@example GOSUB 42

</usermanual> */
void gosub_number( Environment * _environment, int _number ) {

    char label[MAX_TEMPORARY_STORAGE]; sprintf( label, "_linenumber%d", _number );

    cpu_call( _environment, label );

}
