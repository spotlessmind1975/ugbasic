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
 * @brief Emit ASM code for <b>... NEXT</b>
 * 
 * This function outputs the code to implement the end of
 * a for...next loop, by defining the last point of the loop.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword FOR...NEXT
</usermanual> */

void end_for( Environment * _environment ) {

    Loop * loop = _environment->loops;

    if ( ! loop ) {
        CRITICAL("NEXT WITHOUT FOR");
    }

    if ( loop->type != LT_FOR ) {
        CRITICAL("NEXT outside a FOR loop");
    }

    unsigned char beginFor[MAX_TEMPORARY_STORAGE]; sprintf(beginFor, "%sbf", loop->label );
    unsigned char endFor[MAX_TEMPORARY_STORAGE]; sprintf(endFor, "%sbis", loop->label );

    Variable * incrementedIndex = variable_add( _environment, loop->index->name, loop->step->name );

    variable_move_naked( _environment, incrementedIndex->name, loop->index->name );

    cpu_jump( _environment, beginFor );

    cpu_label( _environment, endFor );

    loop->index->locked = 0;
    loop->to->locked = 0;
    if ( loop->step ) {
        loop->step->locked = 0;
    }
    if ( loop->zero ) {
        loop->zero->locked = 0;
    }

    _environment->loops = _environment->loops->next;

};