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
@keyword LOGIN

@english

The ''LOGIN'' function will allow to connect with a DOJO server. On DOJO 
servers there is no different process between registration and access 
to the systems: this is because, in fact, it is unlikely that the user's 
situation has persisted on the retrocomputers. It follows that, at the 
first attempt to access, there will also be contextual registration of the 
user; after the first access, each subsequent access must have the same 
credentials, and there is no way to change them, at least with actual 
version of the DOJO protocol.

The ''LOGIN'' function return a ''sessionId'', to be used on other 
commands / functions. To verify that the operation has taken place, 
the ''SUCCESS''() function must be used. If ''SUCCESS(...)'' returns 
a ''TRUE'' result, then the login process was successful; if it returns a 
''FALSE'' result, then the process must be considered failed for some 
reason (the username may have already been used, or the credentials are 
incorrect, and so on).

@italian

La funzione ''LOGIN'' consente di connettersi a un server DOJO. Sui server 
DOJO non c'è un processo diverso tra registrazione e login ai sistemi: 
questo perché, di fatto, è improbabile che la situazione dell'utente sia
persistente sui retrocomputer. Ne consegue che, al primo tentativo di login, 
vi sarà anche una contestuale registrazione dell'utente; dopo il primo login, 
ogni login successivo dovrà avere le stesse credenziali, e non c'è modo di 
cambiarle, almeno con la versione attuale del protocollo DOJO.

La funzione ''LOGIN'' restituisce un ''sessionId'', da utilizzare su altri 
comandi / funzioni. Per verificare che l'operazione abbia avuto luogo,
deve essere utilizzata la funzione ''SUCCESS''(). Se ''SUCCESS(...)'' 
restituisce un risultato ''TRUE'', allora il processo di login è andato 
a buon fine; se restituisce un risultato ''FALSE'', allora il processo deve 
essere considerato fallito per qualche ragione (il nome utente potrebbe essere 
già stato utilizzato, o le credenziali potrebbero essere errate, e così via).

@syntax = LOGIN( username, password )

@example sessionId = LOGIN( "user", "password" )

@alias DOJO LOGIN

@target c64
</usermanual> */

/* <usermanual>
@keyword DOJO LOGIN

@english

@italian

@syntax = DOJO CREATE PORT( sessionId, application )

@example sessionId = DOJO LOGIN( "user", "password" )

@alias LOGIN

@target c64
</usermanual> */

Variable * dojo_login( Environment * _environment, char * _name, char * _password ) {

    Variable * name = variable_retrieve( _environment, _name );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size)" );
    Variable * password = variable_retrieve( _environment, _password );
    Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(address2)" );
    Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size2)" );
    Variable * result = variable_temporary( _environment, VT_DOJOKA, "(result)" );

    switch( name->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, name->realName, size->realName );
            cpu_addressof_16bit( _environment, name->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, name->realName, address->realName, size->realName );
            break;
    }

    switch( password->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, password->realName, size2->realName );
            cpu_addressof_16bit( _environment, password->realName, address2->realName );
            cpu_inc_16bit( _environment, address2->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, password->realName, address2->realName, size2->realName );
            break;
    }

    c64_dojo_login( _environment, address->realName, size->realName, address2->realName, size2->realName, result->realName );

    return result;

}
