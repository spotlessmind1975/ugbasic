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
@keyword DESTROY PORT

@english

The ''DESTROY PORT'' instruction destroy a message port that is not more
needed. The ''portId'' parameter is the same one that returned the call to 
''CREATE PORT'' function, and identifies the working port at that moment. 

@italian

L'istruzione ''DESTROY PORT'' distrugge una porta messaggio che non è 
più necessaria. Il parametro ''portId'' è lo stesso che ha restituito 
la chiamata alla funzione ''CREATE PORT'' e identifica la porta funzionante 
in quel momento.

@syntax DESTROY PORT portId

@example sessionId = LOGIN( "user", "password" )
@example port = CREATE PORT( sessionId, "testApp" )
@example DESTROY PORT port

@alias DOJO DESTROY PORT

@target c64
</usermanual> */

/* <usermanual>
@keyword DOJO DESTROY PORT

@english

@italian

@syntax DESTROY PORT portId

@example sessionId = DOJO LOGIN( "user", "password" )
@example port = DOJO CREATE PORT( sessionId, "testApp" )
@example DOJO DESTROY PORT port

@alias DOJO DESTROY PORT

@target c64
</usermanual> */

Variable * dojo_destroy_port( Environment * _environment, char * _port_id ) {

    Variable * portId = variable_retrieve( _environment, _port_id );

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(result)" );

    c64_dojo_destroy_port( _environment, portId->realName, result->realName );

    return result;

}
