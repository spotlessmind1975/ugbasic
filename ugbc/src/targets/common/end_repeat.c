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
 * @brief Emit ASM code for <b>... UNTIL [expression]</b>
 * 
 * This function outputs the code to implement the end of
 * a while loop, by defining the last point of the loop.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword REPEAT...UNTIL
</usermanual> */
void end_repeat( Environment * _environment, char * _expression ) {

    Loop * loop = _environment->loops;

    if ( ! loop ) {
        CRITICAL("UNTIL without REPEAT");
    }

    if ( loop->type != LT_REPEAT ) {
        CRITICAL("UNTIL outside a REPEAT loop");
    }

    _environment->loops = _environment->loops->next;

    Variable * expression = variable_retrieve_or_define( _environment, _expression, VT_BYTE, 0 );

    cpu_bveq( _environment,  expression->realName, loop->label );

};
