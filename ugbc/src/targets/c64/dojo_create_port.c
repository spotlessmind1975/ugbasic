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
@keyword CREATE PORT

@english

The ''CREATE PORT'' function create a message port where receive messages.
The ''sessionId'' parameter is the same one that returned the call to 
''LOGIN'' function, and identifies the working session at that moment. 
The ''application'' parameter represents, instead, the name of the 
application or functionality with which you want to associate this 
message port.

The message port (mailbox) is owned by the user but also by each 
individual application or application functionality. Therefore, 
it is possible to define more than one mailbox (i.e., a port) for a
single user, as long as each of them is identified by a different 
application code.

@italian

La funzione ''CREATE PORT'' crea una porta messaggi in cui 
ricevere messaggi. Il parametro ''sessionId'' è lo stesso che ha 
restituito la chiamata alla funzione ''LOGIN'' e identifica la 
sessione di lavoro in quel momento.

Il parametro ''application'' rappresenta, invece, il nome 
dell'applicazione o della funzionalità a cui si desidera associare 
questa porta messaggi.

La porta messaggi (mailbox) è di proprietà dell'utente ma anche 
di ogni singola applicazione o funzionalità dell'applicazione. 
Pertanto, è possibile definire più di una casella di posta 
(ovvero una porta) per un singolo utente, purché ciascuna di 
esse sia identificata da un codice applicazione diverso.

@syntax = CREATE PORT( sessionId, application )

@example sessionId = LOGIN( "user", "password" )
@example port = CREATE PORT( sessionId, "testApp" )

@alias DOJO CREATE PORT

@target c64
</usermanual> */

/* <usermanual>
@keyword DOJO CREATE PORT

@english

@italian

@syntax = DOJO CREATE PORT( sessionId, application )

@example sessionId = DOJO LOGIN( "user", "password" )
@example port = DOJO CREATE PORT( sessionId, "testApp" )

@alias CREATE PORT

@target c64
</usermanual> */

Variable * dojo_create_port( Environment * _environment, char * _session_id, char * _application ) {

    Variable * sessionId = variable_retrieve( _environment, _session_id );

    Variable * application = variable_retrieve( _environment, _application );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size)" );

    Variable * result = variable_temporary( _environment, VT_DOJOKA, "(result)" );

    switch( application->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, application->realName, size->realName );
            cpu_addressof_16bit( _environment, application->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, application->realName, address->realName, size->realName );
            break;
    }

    c64_dojo_create_port( _environment, sessionId->realName, address->realName, size->realName, result->realName );

    return result;

}
