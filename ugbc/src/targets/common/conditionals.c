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
 * @brief Emit ASM code for <b>IF ... THEN ...</b>
 * 
 * This function outputs the code to implement the conditional jump. This 
 * implementation assumes that an expression passed as a parameter is 0 
 * (for false) and not zero (for true). In this case, if the expression 
 * is zero, it jumps directly to the statement following the corresponding 
 * ENDIF. Otherwise, the following code will be executed (up to ENDIF). 
 * Since the compiler acts with a single pass, it is necessary to keep 
 * the information on the last used label. For this purpose, the label 
 * where it will jump will be inserted in the stack, so that it is 
 * defined at the moment when the ENDIF instruction will be examined.
 * 
 * @param _environment Current calling environment
 * @param _expression Expression with the true / false condition
 */
/* <usermanual>
@keyword IF ... THEN

@english
Implement the conditional jump. This implementation assumes that
an expression passed as a parameter is 0 (for false) and not 
zero (for true). In this case, if the expression is zero, it 
jumps directly to the statement following the corresponding 
ENDIF. Otherwise, the following code will be executed (up to 
ENDIF).

@italian
Implementa il salto condizionale. Questa implementazione presuppone che
un'espressione passata come parametro è 0 (per falso) e non
zero (per vero). In questo caso, se l'espressione è zero, esso
salta direttamente all'istruzione che segue il corrispondente
ENDIF. In caso contrario, verrà eseguito il codice seguente (fino a
ENDIF).

@syntax IF [ expression ] THEN

@example IF ( x == 42 ) THEN

@target all
</usermanual> */
void if_then( Environment * _environment, char * _expression ) {

    outline1( "; IF %s THEN ...", _expression);

    MAKE_LABEL

    Variable * expression = variable_retrieve( _environment, _expression );
    if ( ! expression ) {
        CRITICAL("Internal error on IF ... THEN ... ");
    }

    cpu_bveq( _environment, expression->realName, label );

    Conditional * conditional = malloc( sizeof( Conditional ) );
    conditional->label = strdup( label );

    conditional->expression = variable_cast( _environment, expression->name, expression->type );
    conditional->expression->locked = 1;
    conditional->next = _environment->conditionals;
    _environment->conditionals = conditional;

}

/**
 * @brief Emit ASM code for <b>ENDIF</b>
 * 
 * This function outputs the code to implement the end of
 * conditional jump, by defining the last label present
 * into the stack.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword ENDIF

@english
Implement the end of conditional jump.

@italian
Implementa la fine di un salto condizionale.

@syntax ENDIF

@example IF ( x == 42 ) THEN x = 0: ENDIF

@target all
</usermanual> */
void end_if_then( Environment * _environment ) {

    // TODO: Better management of conditional types and missing
    Conditional * conditional = _environment->conditionals;

    _environment->conditionals->expression->locked = 0;

    _environment->conditionals = _environment->conditionals->next;

    cpu_label( _environment, conditional->label );

};

/**
 * @brief Emit ASM code for <b>... ELSE ...</b>
 * 
 * This function outputs the code to implement the alternative for a
 * conditional jump.
 * 
 * @param _environment Current calling environment
 * @param _expression Expression with the true / false condition
 */
/* <usermanual>
@keyword IF ... THEN

@syntax IF [ expression ] THEN ... ELSE ...

@example IF ( x == 42 ) THEN x = 21 ELSE x = 84

@target all
</usermanual> */
void else_if_then( Environment * _environment, char * _expression ) {

    outline1( "; IF %s THEN ... ELSE ...", _expression);

    MAKE_LABEL

    if ( ! _expression ) {
        cpu_bvneq( _environment, _environment->conditionals->expression->realName, _environment->conditionals->label );
    } else {

        Variable * expression = variable_retrieve( _environment, _expression );
        if ( ! expression ) {
            CRITICAL("Internal error on IF ... THEN ... ELSE ... ");
        }

        if ( ! _environment->conditionals ) {
            CRITICAL("Missing IF for ELSE");
        }

        _environment->conditionals->expression->locked = 0;
        _environment->conditionals->expression = variable_cast( _environment, expression->name, expression->type );
        _environment->conditionals->expression->locked = 1;

        cpu_bvneq( _environment, expression->realName, _environment->conditionals->label );

    }
}
