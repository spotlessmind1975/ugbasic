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
These commands implement a multiple conditional jump. It is a question 
of verifying whether a given expression, supplied as first, is equal 
to the various expressions that will be gradually registered through 
the ''CASE'' statement. If they are, the code following the CASE statement 
will be executed. Otherwise, we will move on.

If the ''CASE ELSE'' statement is given, it will be executed if there is no 
other match. It follows that it must be placed last.

The code executed is always and only the one between the ''CASE'' that satisfies 
the condition and the next one (or the ''CASE ELSE''). The code on ''CASE ELSE''
will be execute always and only if other matches fail.

@italian
Questi comandi implementano un salto condizionato multiplo. Si tratta di verificare
se una data espressione, fornita come prima, è pari alle varie espressioni che 
saranno via via censite tramite l'istruzione ''CASE''. In caso lo siano, sarà eseguito 
il codice che segue all'istruzione ''CASE''. Altrimenti si passerà oltre.

Se viene indicata l'istruzione ''CASE ELSE'', questa sarà eseguita se non vi sono 
altre corrispondenze. Ne consegue che dovrà essere posta per ultima. 

Il codice eseguito è sempre e soltanto quello tra il ''CASE'' che soddisfa la 
condizione e il successivo (o il ''CASE ELSE'').

@syntax SELECT CASE [expression] : CASE [match1] : ... {: CASE [match2] : ... } { : CASE ELSE : .... } : ENDSELECT

@example SELECT CASE number
@example   CASE 1
@example      PRINT "one!"
@example   CASE 2
@example      PRINT "two!"
@example   CASE ELSE
@example      PRINT "neither!"
@example ENDSELCT

@usedInExample control_case_01.bas

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
