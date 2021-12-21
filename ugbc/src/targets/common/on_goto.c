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
 * @brief Emit ASM code for <b>ON ... GOTO ...</b>
 * 
 * This function outputs the code to implement the conditional jump by
 * expression.
 * 
 * @param _environment Current calling environment
 * @param _expression Expression with the true / false condition
 */
/* <usermanual>
@keyword ON...GOTO

@english
This command is used to force a unconditional jump to a pre-defined position when a 
specific expression is calculated. The choice is done against several positions,
and it depends on what value is held by the expression at the time it is spotted.

To work properly, the expression must have a value from 1 up to the number of 
the highest possible destination. If the expression has a value of 0 or 
greater than the highest possibile destination, no jump will be performed.

@italian
Questo comando viene utilizzato per forzare un salto incondizionato a una
posizione predefinita, calcolata da un'espressione. La scelta è tra le posizioni
elencate, e dipende dal valore dell'espressione al momento in cui viene 
calcolata.

Per funzionare correttamente, l'espressione deve avere un valore compreso 
tra 1 e il numero di destinazioni. Se l'espressione ha un valore di 0 o
maggiore della destinazione più alta possibile, non sarà eseguito alcun salto.

@syntax ON [expression] GOTO [label1] {, [label2] {, [label3], ... }}

@example ON level GOTO level1, level2, level3
@usedInExample control_by_expression_02.bas

@target all
</usermanual> */
void on_goto( Environment * _environment, char * _expression ) {

    

    MAKE_LABEL

    Variable * expression = variable_retrieve( _environment, _expression );

    Conditional * conditional = malloc( sizeof( Conditional ) );
    conditional->label = strdup( label );
    conditional->type = CT_ON_GOTO;
    conditional->expression = variable_cast( _environment, expression->name, expression->type );
    conditional->expression->locked = 1;
    conditional->index = 1;
    conditional->next = _environment->conditionals;
    _environment->conditionals = conditional;

}

/**
 * @brief Emit ASM code for <b>... (of ON ... GOTO ...)</b>
 * 
 * This function outputs the code to implement any specific
 * indexed jump on forced jumps by expression.
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to
 */
void on_goto_index( Environment * _environment, char * _label ) {

    Conditional * conditional = _environment->conditionals;

    if ( ! conditional ) {
        CRITICAL("Syntax error on ON GOTO");
    }

    if ( conditional->type != CT_ON_GOTO ) {
        CRITICAL("ON ... GO");
    }

    Variable * index = variable_resident( _environment, VT_BYTE, "(index)");

    variable_store( _environment, index->name, conditional->index );

    Variable * expression = variable_retrieve( _environment, conditional->expression->name );

    cpu_bvneq( _environment, variable_compare( _environment, expression->name, index->name )->realName, _label );

    ++conditional->index;

};

/**
 * @brief Emit ASM code for <b>... (of ON ... GOTO ...)</b>
 * 
 * This function outputs the code to implement any specific
 * indexed jump on forced jumps by expression.
 * 
 * @param _environment Current calling environment
 * @param _number Line number to jump to
 */
void on_goto_number( Environment * _environment, int _number ) {

    char label[MAX_TEMPORARY_STORAGE]; sprintf( label, "_linenumber%d", _number );

    on_goto_index( _environment, label );

};

/**
 * @brief Emit ASM code for <b>... (of ON ... GOTO ...)</b>
 * 
 * This function outputs the code to implement the ending
 * of unconditional jump by expression.
 * 
 * @param _environment Current calling environment
 */
void on_goto_end( Environment * _environment ) {

    Conditional * conditional = _environment->conditionals;

    if ( ! conditional ) {
        CRITICAL("Syntax error on ON GOTO");
    }

    if ( conditional->type != CT_ON_GOTO ) {
        CRITICAL("ON ... GO");
    }

    _environment->conditionals->expression->locked = 0;

    _environment->conditionals = _environment->conditionals->next;

};