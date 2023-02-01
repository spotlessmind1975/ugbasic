/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
 * ENDIF (or ELSE, if present). Otherwise, the following code will be 
 * executed (up to ENDIF). Since the compiler acts with a single pass, 
 * it is necessary to keep the information on the last used label. 
 * For this purpose, the label where it will jump will be inserted 
 * in the stack, so that it is defined at the moment when the ENDIF 
 * instruction will be examined.
 * 
 * @param _environment Current calling environment
 * @param _expression Expression with the true / false condition
 */
/* <usermanual>
@keyword IF...THEN...ELSE...ENDIF

@english
Implement a conditional jump. This implementation assumes that
an expression passed as a parameter is 0 (for false) and not 
zero (for true). In this case, if the expression is zero, it 
jumps directly to the statement following the corresponding 
''ENDIF'' (or ''ELSE'', if present). Otherwise, the following 
code will be executed (up to ''ENDIF'' or ''ELSE'').

@italian
Implementa il salto condizionato. Questa implementazione presuppone che
un'espressione passata come parametro è 0 (per falso) e non
zero (per vero). In questo caso, se l'espressione è zero, esso
salta direttamente all'istruzione che segue il corrispondente
''ENDIF'' (oppure ''ELSE'', se presente). In caso contrario, 
verrà eseguito il codice seguente (fino a ''ENDIF'').

@syntax IF [ expression ] THEN : ... : { ELSE : ... : } ENDIF
@syntax IF [ expression ] THEN : ... : { ELSEIF : ... : { ELSEIF : ... : } } ELSE : ... : ENDIF

@example IF ( x == 42 ) THEN : x = 0 : ELSE : x = 1 : ENDIF
@example IF ( x == 42 ) THEN : x = 0 : ELSE IF y == 0 THEN : y = 42 : ELSE : x = 1 : ENDIF
@example IF ( x == 42 ) THEN
@example   x = 0
@example ELSE IF y == 0 THEN
@example   y = 42
@example ELSE
@example   x = 1
@example ENDIF

@usedInExample control_returning_01.bas
@usedInExample control_returning_02.bas
@usedInExample control_popping_91.bas

@target all
</usermanual> */
void if_then( Environment * _environment, char * _expression ) {

    

    MAKE_LABEL

    Variable * expression = variable_retrieve_or_define( _environment, _expression, VT_BYTE, 0 );

    Conditional * conditional = malloc( sizeof( Conditional ) );
    memset( conditional, 0, sizeof( Conditional ) );
    conditional->label = strdup( label );
    conditional->type = CT_IF;

    conditional->expression = variable_cast( _environment, expression->name, expression->type );
    conditional->expression->locked = 1;
    conditional->next = _environment->conditionals;
    _environment->conditionals = conditional;

    char thenLabel[MAX_TEMPORARY_STORAGE]; sprintf(thenLabel, "%st", label );
    char elseLabel[MAX_TEMPORARY_STORAGE]; sprintf(elseLabel, "%se%d", conditional->label, conditional->index );

    cpu_bveq( _environment, expression->realName, elseLabel );

    cpu_label( _environment, thenLabel );

}
