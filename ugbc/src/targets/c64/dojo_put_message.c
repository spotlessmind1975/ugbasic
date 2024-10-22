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
@keyword PUT MESSAGE

@english

The ''PUT MESSAGE'' allows to put a message on a specific port. This is a statement, 
not a function. It follows that we cannot know if the statement was successful. 
This does not really represent a limitation, for the simple fact that the statement 
will always be successful: if the program on the other side of the port is not available,
for some reason, the message will be preserved by the DOJO server, and it will be 
delivered at the first available moment.

@italian

''PUT MESSAGE'' consente di mettere un messaggio su una porta specifica. 
Questa è un'istruzione, non una funzione. Ne consegue che non possiamo 
sapere se l'istruzione ha avuto successo.

Questo non rappresenta realmente una limitazione, per il semplice fatto 
che l'istruzione avrà sempre successo: se il programma dall'altra parte 
della porta non è disponibile, per qualche motivo, il messaggio verrà 
conservato dal server DOJO e verrà consegnato al primo momento disponibile.

@syntax PUT MESSAGE portId, string

@example sessionId = LOGIN( "user", "password" )
@example port = FIND( sessionId, "user2", "testApp" )
@example PUT MESSAGE port, "hello!"

@alias DOJO PUT MESSAGE

@target c64
</usermanual> */

/* <usermanual>
@keyword DOJO PUT MESSAGE

@english

@italian

@syntax DOJO PUT MESSAGE portId, string

@example sessionId = DOJO LOGIN( "user", "password" )
@example port = DOJO FIND( sessionId, "user2", "testApp" )
@example DOJO PUT MESSAGE port, "hello!"

@alias PUT MESSAGE

@target c64
</usermanual> */

Variable * dojo_put_message( Environment * _environment, char * _port_id, char * _message ) {

    Variable * portId = variable_retrieve( _environment, _port_id );

    Variable * message = variable_retrieve( _environment, _message );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size)" );

    Variable * result = variable_temporary( _environment, VT_DOJOKA, "(result)" );

    switch( message->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, message->realName, size->realName );
            cpu_addressof_16bit( _environment, message->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, message->realName, address->realName, size->realName );
            break;
    }

    c64_dojo_put_message( _environment, portId->realName, address->realName, size->realName, result->realName );

    return result;

}
