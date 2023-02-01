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
 * @brief Emit code for <strong>CLINE ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _characters Characters to remove
 */
/* <usermanual>
@keyword CLINE

@english
The ''CLINE'' command is used to clear the line currently occupied by the text 
cursor. If ''CLINE'' is followed by a number, then that number of characters
get cleared, starting from the current cursor position and leaving the cursor 
exactly where it is. 

@italian
Il comando ''CLINE'' viene utilizzato per cancellare la riga attualmente 
occupata dal cursore. Se ''CLINE'' è seguito da un numero, quel numero 
di caratteri sarà cancellato, a partire dalla posizione corrente del 
cursore e lasciando il cursore esattamente dove si trova.

@syntax CLINE {[expression]}

@example CLINE

@usedInExample texts_position_01.bas
@usedInExample texts_position_02.bas

@target c128
</usermanual> */
void cline( Environment * _environment, char * _characters ) {

    if ( _characters ) {
        Variable * characters = NULL;
        characters = variable_retrieve( _environment, _characters );
        vic2_cline( _environment, characters->realName );
    } else {
        vic2_cline( _environment, NULL );
    }

}
