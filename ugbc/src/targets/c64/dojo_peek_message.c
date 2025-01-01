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
@keyword PEEK MESSAGE

@english

The ''PEEK MESSAGE'' function can be used to wait for a message on a DOJO port.
The function returns ''FALSE'' if the the message port is empty. On the contrary, 
if it returns ''TRUE'', it is possible to fetch the message using the 
''GET MESSAGE'' command. 

Note that the message port behaves like a queue, that is, the first message 
that is inserted is the first that is retrieved. Therefore, if a program sends three
messages in a row to the attention of the port of another, the receiving program 
will receive the three messages in the same order.
Obviously, if several programs do the same thing, the messages will be 
interspersed but, in the end, they will be in the same order.

@italian

La funzione ''PEEK MESSAGE'' può essere utilizzata per attendere un messaggio 
su una porta DOJO. La funzione restituisce ''FALSE'' se la porta del messaggio 
è vuota. Al contrario, se restituisce ''TRUE'', il messaggio può essere 
recuperato utilizzando il comando ''GET MESSAGE''.

Nota che la porta del messaggio agisce come una coda, il che significa che il 
primo messaggio inserito è il primo a essere recuperato. Pertanto, se un 
programma invia tre messaggi di seguito all'attenzione della porta di un altro 
programma, il programma ricevente riceverà i tre messaggi nello stesso ordine. 
Naturalmente, se più programmi fanno la stessa cosa, i messaggi saranno 
intervallati, ma alla fine saranno nello stesso ordine.

@syntax = PEEK MESSAGE( portId )

@example sessionId = LOGIN( "user", "password" )
@example port = FIND( sessionId, "user2", "testApp" )
@example IF PEEK MESSAGE( port ) THEN
@example    PRINT "A message is arrived!"
@example ENDIF

@alias DOJO PEEK MESSAGE

@target c64
</usermanual> */

/* <usermanual>
@keyword DOJO PEEK MESSAGE

@english

@italian

@syntax = DOJO PEEK MESSAGE( portId )

@example sessionId = DOJO LOGIN( "user", "password" )
@example port = DOJO FIND( sessionId, "user2", "testApp" )
@example IF DOJO PEEK MESSAGE( port ) THEN
@example    PRINT "A message is arrived!"
@example ENDIF

@alias PEEK MESSAGE

@target c64
</usermanual> */

Variable * dojo_peek_message( Environment * _environment, char * _port_id ) {

    Variable * portId = variable_retrieve( _environment, _port_id );

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(result)" );

    c64_dojo_peek_message( _environment, portId->realName, result->realName );

    return result;

}
