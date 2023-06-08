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
 * @brief Emit ASM code for <b>PEEK(...)</b>
 * 
 * This function outputs valid code to retrieve a byte from memory, 
 * and returns it as a temporary variable. This version is valid 
 * for use where the location to be read is an expression
 * 
 * @param _environment Current calling environment
 * @param _location Expression with the location to read from.
 * @return Variable* Temporary variable with the content of the location (1 byte).
 */
/* <usermanual>
@keyword PEEK

@english
Retrieve a byte from memory, and returns it.

@italian
Recupera un byte dalla memoria e restituiscilo.

@syntax = PEEK( [expression] )

@example memory = PEEK( location )

@target c64

</usermanual> */
Variable * peek_var( Environment * _environment, char * _location ) {

    outline1("; PEEK(%s)", _location);

    Variable * location = variable_retrieve( _environment, _location );

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result)" );

    cpu6502_peek( _environment, location->realName, result->realName );

    return result;

}
