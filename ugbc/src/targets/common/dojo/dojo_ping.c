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
@keyword PING

@english

The ''PING'' instruction allows you to check whether the server is active and 
whether communication is occurring correctly. It can be invoked without parameters, 
to check whether the connection is working, or with one or two parameters, to check 
whether the connection does not compromise the data transmitted. To check this, 
you need to know that the two parameters, if provided, will be used to compose the 
response. So, for example, by providing ''&H15'' and ''&H16'' as input parameters, 
the result obtained should be ''&H15162A2B'' (in the case of a "big endian" 
computer) or ''&2B2A1615'' (in the case of a "little endian" computer).

@italian

L'istruzione ''PING'' consente di verificare se il server è attivo e se la 
comunicazione avviene correttamente. Si può invocare senza parametri, per 
verificare se la connessione funziona, o con uno o due parametri, per verificare 
che la connessione non comprometta i dati trasmessi. Per verificarlo è necessario 
sapere che i due parametri,  se forniti, saranno utilizzati per comporre la risposta. 
Quindi, ad esempio, fornendo ''&H15'' e ''&H16'' come parametri in ingresso, il 
risultato ottenuto dovrà essere ''&H15162A2B'' (in caso di computer "big endian") oppure 
''&2B2A1615''  (in caso di computer "little endian").

@syntax [DOJO] PING[ ( [param1 [,param2] ] ) ]

@example response = PING( &H15, &H16 )
@example IF response = "15162A2B" OR response = "2B2A1615" THEN
@example     PRINT "Data transmission ok!"
@example ENDIF

@seeAlso DOJO PING

@target atari, coco
</usermanual> */

/* <usermanual>
@keyword DOJO PING

@english

@italian

@alias PING

@target atari, coco
</usermanual> */

Variable * dojo_ping( Environment * _environment, char * _param1, char * _param2 ) {

    MAKE_LABEL

    Variable * result = variable_temporary( _environment, VT_BYTE, "(ping ok)" );

    Variable * param1 = NULL;
    if ( _param1 ) {
        param1 = variable_retrieve_or_define( _environment, _param1, VT_BYTE, 0 );
    }
    Variable * param2 = NULL;
    if ( _param2 ) {
        param2 = variable_retrieve_or_define( _environment, _param2, VT_BYTE, 0 );
    }

    Variable * dword = variable_temporary( _environment, VT_DWORD, "(pinged)" );

    dojo_begin( _environment );
    dojo_put_request0( _environment, DOJO_CMD_PING, (param1)?param1->realName:NULL, (param2)?param2->realName:NULL, result->realName );
    cpu_compare_and_branch_8bit_const( _environment, result->realName, 0, label, 0 );
    dojo_partial( _environment );
    // wait_milliseconds( _environment, 500 );
    dojo_get_responsed( _environment, result->realName, dword->realName, NULL );

    cpu_label( _environment, label );
    dojo_end( _environment );

    cpu_move_8bit( _environment, result->realName, "DOJOERROR" );

    return dword;

}
