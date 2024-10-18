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

/* <usermanual>
@keyword CASE

@english

The ''CASE'' command is part of ''SELECT...ENDSELECT'' construct. Each ''CASE'' 
represents a possible value of the expression. After each case, you can insert 
the statements that will be executed if the value of the expression matches that case.
The code will be executed up to the ''ENDSELECT'' instruction, another ''CASE''
instruction and, finally, when a ''CASE ELSE'' is matched.

@italian

Il comando ''CASE'' fa parte del costrutto ''SELECT...ENDSELECT''. Ogni ''CASE'' 
rappresenta un possibile valore dell'espressione. Dopo ogni caso, puoi inserire 
le istruzioni che verranno eseguite se il valore dell'espressione corrisponde 
a quel caso. Il codice verrà eseguito fino all'istruzione ''ENDSELECT'', 
un'altra istruzione ''CASE'' e, infine, quando viene trovato un ''CASE ELSE''.

@syntax CASE value

@example SELECT CASE answer
@example    CASE 42
@example       PRINT "The answer!"
@example    CASE ELSE
@example       PRINT "I am still thinking..."
@example ENDSELECT

@seeAlso SELECT CASE
@seeAlso CASE ELSE
@seeAlso ENDSELECT

</usermanual> */
void case_equals_label( Environment * _environment ) {

    Conditional * conditional = _environment->conditionals;

    if ( ! conditional ) {
        CRITICAL_CASE_WITHOUT_SELECT_CASE();
    }

    if ( conditional->type != CT_SELECT_CASE ) {
        CRITICAL_CASE_WITHOUT_SELECT_CASE();
    }

    char endselectLabel[MAX_TEMPORARY_STORAGE]; sprintf(endselectLabel, "%sf", conditional->label );
    char elseLabel[MAX_TEMPORARY_STORAGE]; sprintf(elseLabel, "%se%d", conditional->label, conditional->index );

    if ( conditional->index > 0 ) {
        cpu_jump( _environment, endselectLabel );
    }

    cpu_label( _environment, elseLabel );

}

/**
 * @brief Emit ASM code for <b>CASE ...</b>
 * 
 * This function outputs the code to implement a single comparison of a 
 * structured conditional jump. 
 * 
 * @param _environment Current calling environment
 * @param _expression Expression with the true / false condition
 */
/* <usermanual>
@keyword SELECT CASE...CASE...CASE ELSE...ENDSELECT

@target all
</usermanual> */
void case_equals_var( Environment * _environment, char * _value ) {

    Conditional * conditional = _environment->conditionals;

    if ( ! conditional ) {
        CRITICAL_CASE_WITHOUT_SELECT_CASE();
    }

    if ( conditional->type != CT_SELECT_CASE ) {
        CRITICAL_CASE_WITHOUT_SELECT_CASE();
    }

    Variable * value = variable_retrieve_or_define( _environment, _value, VT_BYTE, 0 );

    char thenLabel[MAX_TEMPORARY_STORAGE]; sprintf(thenLabel, "%st%d", conditional->label, conditional->index );
    char elseLabel[MAX_TEMPORARY_STORAGE]; sprintf(elseLabel, "%se%d", conditional->label, conditional->index );

    ++conditional->index;
    sprintf(elseLabel, "%se%d", conditional->label, conditional->index );

    Variable * result = variable_compare( _environment, conditional->expression->name, value->name );

    cpu_bveq( _environment, result->realName, elseLabel );

    cpu_label( _environment, thenLabel );

}

/**
 * @brief Emit ASM code for <b>CASE ...</b>
 * 
 * This function outputs the code to implement a single comparison of a 
 * structured conditional jump. 
 * 
 * @param _environment Current calling environment
 * @param _expression Expression with the true / false condition
 */
/* <usermanual>
@keyword SELECT CASE...CASE...CASE ELSE...ENDSELECT

@target all
</usermanual> */
void case_equals( Environment * _environment, int _value ) {

    Conditional * conditional = _environment->conditionals;

    if ( ! conditional ) {
        CRITICAL_CASE_WITHOUT_SELECT_CASE();
    }

    if ( conditional->type != CT_SELECT_CASE ) {
        CRITICAL_CASE_WITHOUT_SELECT_CASE();
    }

    char thenLabel[MAX_TEMPORARY_STORAGE]; sprintf(thenLabel, "%st%d", conditional->label, conditional->index );
    char elseLabel[MAX_TEMPORARY_STORAGE]; sprintf(elseLabel, "%se%d", conditional->label, conditional->index );

    Variable * result = variable_temporary( _environment, VT_BYTE, "(comparing)");

    ++conditional->index;
    sprintf(elseLabel, "%se%d", conditional->label, conditional->index );

    switch( VT_BITWIDTH( conditional->expression->type ) ) {
        case 8:
            cpu_compare_and_branch_8bit_const( _environment, conditional->expression->realName, _value, elseLabel, 0 );
            break;
        case 16:
            cpu_compare_and_branch_16bit_const( _environment, conditional->expression->realName, _value, elseLabel, 0 );
            break;
        case 32:
            cpu_compare_and_branch_32bit_const( _environment, conditional->expression->realName, _value, elseLabel, 0 );
            break;
        default:
            CRITICAL_CANNOT_COMPARE_WITH_CASE( conditional->expression->name );
    }

    cpu_label( _environment, thenLabel );

}
