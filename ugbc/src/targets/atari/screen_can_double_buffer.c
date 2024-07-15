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

/**
 * @brief Emit ASM code for <b>CAN DOUBLE BUFFER</b>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword CAN DOUBLE BUFFER

@english

The ''CAN DOUBLE BUFFER'' function will return ''TRUE'' if the double buffering functionality
is available, for the actual screen mode / video chipset.

@italian

La funzione ''CAN DOUBLE BUFFER'' restituità ''TRUE''se la funzionalità di double buffering
è disponibile, per l'attuale modalità video / chipset video.

@syntax = CAN DOUBLE BUFFER

@example IF CAN DOUBLE BUFFER THEN: DOUBLE BUFFER ON : ENDIF

@target all
</usermanual> */
Variable * screen_can_double_buffer( Environment * _environment ) {

    Variable * false = variable_temporary( _environment, VT_SBYTE, "(false)" );

    variable_store( _environment, false->realName, 0 );

    return false;

}

