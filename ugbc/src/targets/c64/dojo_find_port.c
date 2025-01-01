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

/* <usermanual>
@keyword FIND PORT

@english

The ''FIND PORT'' function is needed to find out a port where to send
message. To send a message, we need to know the address of that message 
port. A message box is identified by a unique identifier, called ''portId''. 
So the first useful operation is to find out the port id to use to
send the message. This is exactly the purpose of this function.

So basically three pieces of information are needed to identify that mailbox. 
First of all, you need an identifier that allows the user to be 
recognized by the DOJO server (''sessionId''). Secondly, you need to know 
the identifier of the user who owns that mailbox (''username''). Finally, 
it is essential to know the name of the application on whose behalf we are 
looking for the mailbox (''application'').

@italian

La funzione ''FIND PORT'' è necessaria per trovare una porta a cui 
inviare un messaggio. Per inviare un messaggio, dobbiamo conoscere 
l'indirizzo di quella porta del messaggio. Una casella di messaggio 
è identificata da un identificatore univoco, chiamato ''portId''.

Quindi la prima operazione utile è scoprire l'ID della porta da utilizzare
per inviare il messaggio. Questo è esattamente lo scopo di questa funzione.

Quindi fondamentalmente sono necessarie tre informazioni per 
identificare quella casella di posta. Innanzitutto, hai bisogno di un 
identificatore che consenta all'utente di essere riconosciuto dal server 
DOJO (''sessionId''). In secondo luogo, devi conoscere l'identificativo 
dell'utente che possiede quella casella di posta (''username''). 
Infine, è essenziale conoscere il nome dell'applicazione per conto 
della quale stiamo cercando la casella di posta (''application'').

@syntax port = FIND PORT( sessionId, username, application )

@example sessionId = LOGIN( "user", "password" )
@example port = FIND( sessionId, "user2", "testApp" )

@alias DOJO FIND PORT

@target c64
</usermanual> */

/* <usermanual>
@keyword DOJO FIND PORT

@english

@italian

@syntax port = DOJO FIND PORT( sessionId, username, application )

@example sessionId = DOJO LOGIN( "user", "password" )
@example port = DOJO FIND( sessionId, "user2", "testApp" )

@alias DOJO FIND PORT

@target c64
</usermanual> */

Variable * dojo_find_port( Environment * _environment, char * _session_id, char * _username, char * _application ) {

    Variable * sessionId = variable_retrieve( _environment, _session_id );

    Variable * username = variable_retrieve( _environment, _username );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size)" );

    Variable * application = variable_retrieve( _environment, _application );
    Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(address)" );
    Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size)" );

    Variable * result = variable_temporary( _environment, VT_DOJOKA, "(result)" );

    switch( username->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, username->realName, size->realName );
            cpu_addressof_16bit( _environment, username->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, username->realName, address->realName, size->realName );
            break;
    }

    switch( application->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, application->realName, size2->realName );
            cpu_addressof_16bit( _environment, application->realName, address2->realName );
            cpu_inc_16bit( _environment, address2->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, application->realName, address2->realName, size2->realName );
            break;
    }

    c64_dojo_find_port( _environment, sessionId->realName, address->realName, size->realName, address2->realName, size2->realName, result->realName );

    return result;

}
