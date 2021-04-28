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
 * This function outputs the code to implement the conditional jump.
 * 
 * @param _environment Current calling environment
 * @param _expression Expression with the true / false condition
 */
/* <usermanual>
@keyword ON ... GOTO ...

@english
Implement the conditional jump.

@italian
Implementa il salto condizionale.

@syntax ON [expression] GOTO [label1]{,[label2]{,[label3], ... } }

@example ON level GOTO level1, level2, level3

@target all
</usermanual> */
void on_goto( Environment * _environment, char * _expression ) {

    outline1( "; ON %s GOTO ...", _expression);

    MAKE_LABEL

    Variable * expression = variable_retrieve( _environment, _expression );
    if ( ! expression ) {
        CRITICAL("Internal error on ON ... GOTO ... ");
    }

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
 * indexed jump on forced jumps.
 * 
 * @param _environment Current calling environment
 */
void on_goto_index( Environment * _environment, char * _label ) {

    // TODO: Better management of conditional types and missing
    Conditional * conditional = _environment->conditionals;

    if ( ! conditional ) {
        CRITICAL("Syntax error on ON GOTO");
    }

    if ( conditional->type != CT_ON_GOTO ) {
        CRITICAL("ON ... GO");
    }

    Variable * index = variable_temporary( _environment, VT_BYTE, "(index)");

    variable_store( _environment, index->name, conditional->index );

    Variable * expression = variable_retrieve( _environment, conditional->expression->name );

    cpu_bveq( _environment, variable_compare( _environment, expression->name, index->name )->name, _label );

    ++conditional->index;

};

/**
 * @brief Emit ASM code for <b>... (of ON ... GOTO ...)</b>
 * 
 * This function outputs the code to implement any specific
 * indexed jump on forced jumps.
 * 
 * @param _environment Current calling environment
 */
void on_goto_end( Environment * _environment ) {

    // TODO: Better management of conditional types and missing
    Conditional * conditional = _environment->conditionals;

    if ( ! conditional ) {
        CRITICAL("Syntax error on ON GOTO");
    }

    if ( conditional->type != CT_ON_GOTO ) {
        CRITICAL("ON ... GO");
    }

    _environment->conditionals->expression->locked = 0;

    _environment->conditionals = _environment->conditionals->next;

    variable_reset( _environment );

};

/**
 * @brief Emit ASM code for <b>ON ... GOSUB ...</b>
 * 
 * This function outputs the code to implement the conditional jump.
 * 
 * @param _environment Current calling environment
 * @param _expression Expression with the true / false condition
 */
/* <usermanual>
@keyword ON ... GOSUB ...

@english
Implement the conditional jump.

@italian
Implementa il salto condizionale.

@syntax ON [expression] GOSUB [label1]{,[label2]{,[label3], ... } }

@example ON level GOSUB level1, level2, level3

@target all
</usermanual> */
void on_gosub( Environment * _environment, char * _expression ) {

    outline1( "; ON %s GOSUB ...", _expression);

    MAKE_LABEL

    Variable * expression = variable_retrieve( _environment, _expression );
    if ( ! expression ) {
        CRITICAL("Internal error on ON ... GOSUB ... ");
    }

    char newLabel[16]; sprintf(newLabel, "gosub%d", UNIQUE_ID );

    Conditional * conditional = malloc( sizeof( Conditional ) );
    conditional->label = strdup( newLabel );
    conditional->type = CT_ON_GOSUB;
    conditional->expression = variable_cast( _environment, expression->name, expression->type );
    conditional->expression->locked = 1;
    conditional->index = 1;
    conditional->next = _environment->conditionals;
    _environment->conditionals = conditional;

}

/**
 * @brief Emit ASM code for <b>... (of ON ... GOSUB ...)</b>
 * 
 * This function outputs the code to implement any specific
 * indexed jump on forced jumps.
 * 
 * @param _environment Current calling environment
 */
void on_gosub_index( Environment * _environment, char * _label ) {

    // TODO: Better management of conditional types and missing
    Conditional * conditional = _environment->conditionals;

    if ( ! conditional ) {
        CRITICAL("Syntax error on ON GOSUB");
    }

    if ( conditional->type != CT_ON_GOSUB ) {
        CRITICAL("ON ... GOSUB");
    }

    Variable * index = variable_temporary( _environment, VT_BYTE, "(index)");
    
    variable_store( _environment, index->name, conditional->index );

    Variable * expression = variable_retrieve( _environment, conditional->expression->name );

    char newLabel[16]; sprintf(newLabel, "%s%d", conditional->label, (conditional->index+1) );

    cpu_bvneq( _environment, variable_compare( _environment, expression->name, index->name )->name, newLabel );

    cpu_call( _environment, _label );

    char newLabel2[16]; sprintf(newLabel2, "%sfinal", conditional->label );

    cpu_jump( _environment, newLabel2 );

    cpu_label( _environment, newLabel );

    ++conditional->index;

};

/**
 * @brief Emit ASM code for <b>... (of ON ... GOSUB ...)</b>
 * 
 * This function outputs the code to implement any specific
 * indexed jump on forced jumps.
 * 
 * @param _environment Current calling environment
 */
void on_gosub_end( Environment * _environment ) {

    // TODO: Better management of conditional types and missing
    Conditional * conditional = _environment->conditionals;

    if ( ! conditional ) {
        CRITICAL("Syntax error on ON GOSUB");
    }

    if ( conditional->type != CT_ON_GOSUB ) {
        CRITICAL("ON ... GOSUB");
    }

    char newLabel2[16]; sprintf(newLabel2, "%sfinal", conditional->label );

    cpu_label( _environment, newLabel2 );

    _environment->conditionals->expression->locked = 0;

    _environment->conditionals = _environment->conditionals->next;

    variable_reset( _environment );

};