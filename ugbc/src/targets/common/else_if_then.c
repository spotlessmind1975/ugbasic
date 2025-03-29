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
 * @brief Emit ASM code for <b>... ELSE [IF] ...</b>
 * 
 * This function outputs the code to implement the alternative for a
 * conditional if.
 * 
 * @param _environment Current calling environment
 * @param _expression Expression with the true / false condition
 */
void else_if_then_label( Environment * _environment ) {

    Conditional * conditional = _environment->conditionals;

    if ( ! conditional ) {
        CRITICAL_ELSE_WITHOUT_IF();
    }

    if ( conditional->type != CT_IF ) {
        CRITICAL_ELSE_WITHOUT_IF();
    }

    char endifLabel[MAX_TEMPORARY_STORAGE]; sprintf(endifLabel, "%sf", conditional->label );
    char elseLabel[MAX_TEMPORARY_STORAGE]; sprintf(elseLabel, "%se%d", conditional->label, conditional->index );

    cpu_jump( _environment, endifLabel );

    cpu_label( _environment, elseLabel );
    
}

/**
 * @brief Emit ASM code for <b>... ELSE [IF] ...</b>
 * 
 * This function outputs the code to implement the alternative for a
 * conditional if.
 * 
 * @param _environment Current calling environment
 * @param _expression Expression with the true / false condition
 */
void else_if_then( Environment * _environment, char * _expression ) {

    

    Conditional * conditional = _environment->conditionals;

    if ( ! conditional ) {
        CRITICAL_ELSE_WITHOUT_IF();
    }

    if ( conditional->type != CT_IF ) {
        CRITICAL_ELSE_WITHOUT_IF();
    }

    char endifLabel[MAX_TEMPORARY_STORAGE]; sprintf(endifLabel, "%sf", conditional->label );
    char elseLabel[MAX_TEMPORARY_STORAGE]; sprintf(elseLabel, "%se%d", conditional->label, conditional->index );

    ++conditional->index;
    sprintf(elseLabel, "%se%d", conditional->label, conditional->index );
    
    if ( ! _expression ) {

        // cpu_bvneq( _environment, conditional->expression->realName, endifLabel );

    } else {

        Variable * expression = variable_retrieve_or_define( _environment, _expression, VT_BYTE, 0 );

        conditional->expression->locked = 0;
        conditional->expression = variable_cast( _environment, expression->name, expression->type );
        conditional->expression->locked = 1;

        cpu_bveq( _environment, expression->realName, elseLabel );

    }
    
}
