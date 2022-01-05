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
 * @brief Emit ASM code for <b>CASE ELSE</b>
 * 
 * This function outputs the code when other comparisons fails
 * 
 * @param _environment Current calling environment
 * @param _expression Expression with the true / false condition
 */
/* <usermanual>
@keyword SELECT CASE...CASE...CASE ELSE...ENDSELECT

@target all
</usermanual> */
void case_else( Environment * _environment ) {

    Conditional * conditional = _environment->conditionals;

    if ( ! conditional ) {
        CRITICAL("CASE ELSE without SELECT CASE");
    }

    if ( conditional->type != CT_SELECT_CASE ) {
        CRITICAL("CASE ELSE outside SELECT CASE");
    }

    char endselectLabel[MAX_TEMPORARY_STORAGE]; sprintf(endselectLabel, "%sf", conditional->label );

    if ( conditional->index > 0 ) {
        cpu_jump( _environment, endselectLabel );
    }

    char elseLabel[MAX_TEMPORARY_STORAGE]; sprintf(elseLabel, "%se%d", conditional->label, conditional->index );

    cpu_label( _environment, elseLabel );

}
