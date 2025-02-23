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

#include "../../../ugbc.h"
 
extern char DATATYPE_AS_STRING[][16];

/* <usermanual>
@keyword CREATE PORT

@english

The ''CREATE PORT'' statement creates a communication port on the DOJO server, which allows you to send and 
receive messages. Each port has 256 independent communication channels, on which you can send and receive 
messages. This statement returns a unique port identifier, which can be communicated to the user via the 
''PRINT'' command and used as a 32-bit number. For this reason, the code contains 8 hexadecimal digits. 
The identifier must be used to open a connection via the ''OPEN PORT'' command, in case you want to reuse 
the connection at a later time or to coordinate the participants in a communication.

@italian

L'istruzione ''CREATE PORT'' consente di creare una porta di comunicazione sul server DOJO, che consente di 
inviare e ricevere messaggi. Ogni porta dispone di 256 canali di comunicazione indipendenti, sui quali è 
possibile inviare e ricevere messaggi. Questa istruzione restituisce un i dentificativo univoco della porta, 
che può essere comunicato all'utente per mezzo del comando ''PRINT'' e usato come un numero di 32 bit. 
Per questa ragione il codice contiene 8 cifre esadecimali. L'identificativo dovrà essere utilizzato per aprire
una connessione tramite il comando OPEN PORT, laddove si voglia riutilizzare la connessione in un secondo 
tempo o per coordinare i partecipanti a una comunicazione.

@syntax [DOJO] CREATE PORT [()]

@example handle = CREATE PORT

@alias DOJO CREATE PORT

@seeAlso OPEN PORT

@target atari, coco
</usermanual> */

/* <usermanual>
@keyword DOJO CREATE PORT

@english

@italian

@alias CREATE PORT

@target atari, coco
</usermanual> */

Variable * dojo_create_port( Environment * _environment ) {

    MAKE_LABEL

    Variable * dojoHandle = variable_temporary( _environment, VT_DOJOKA, "(dojo handle)" );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(unique id)" );

    dojo_begin( _environment );
    dojo_put_request0( _environment, DOJO_CMD_CREATE_PORT, NULL, NULL, result->realName );
    cpu_compare_and_branch_8bit_const( _environment, result->realName, 0, label, 0 );
    dojo_partial( _environment );
    // wait_milliseconds( _environment, 500 );
    dojo_get_responsed( _environment, result->realName, dojoHandle->realName, NULL );

    cpu_label( _environment, label );
    dojo_end( _environment );

    cpu_move_8bit( _environment, result->realName, "DOJOERROR" );

    return dojoHandle;

}
