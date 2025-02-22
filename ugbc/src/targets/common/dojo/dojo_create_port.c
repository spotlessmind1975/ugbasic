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
@keyword DOJO CREATE PORT

@english


@italian

Questa istruzione permette di aprire una connessione sulla periferica selezionata. 
Il paralmetro ''url'' dovrà contenere la specifica del dispositivo, nel formato 
''N:PROTO://[HOSTNAME]:PORT/PATH/.../''. Il parametro mode, se indicato, specifica 
la modalità secondo lo standard FujiNet (''4''=lettura, ''8''=scrittura, 
''12''=lettura/scrittura, ''13''=POST, e così via). Il parametro ''trans'' indica 
la modalità di traduzione dei cosiddetti "fine linea" da applicare ai dati in arrivo 
(''0''=nessuna, ''1''=CR, ''2''=LF, ''3''=CRLF, ''4''=Pet). Questo comando può essere 
usato anche come una funzione, per ottenere l'eventuale codice di errore, se di interesse.

@syntax FUJINET OPEN url, mode , trans
@syntax = FUJINET OPEN ( url, mode , trans )

@example IF FUJINET OPEN ( "telnet://localhost", 4, 0 ) THEN: PRINT "Opened!": ENDIF

@target coco
</usermanual> */

Variable * dojo_create_port( Environment * _environment ) {

    MAKE_LABEL

    Variable * dojoHandle = variable_temporary( _environment, VT_DOJOKA, "(dojo handle)" );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(unique id)" );

    dojo_begin( _environment );
    dojo_put_request0( _environment, DOJO_CMD_CREATE_PORT, NULL, NULL, result->realName );
    cpu_compare_and_branch_8bit_const( _environment, result->realName, 0, label, 0 );
    dojo_partial( _environment );
    dojo_get_responsed( _environment, result->realName, dojoHandle->realName, NULL );

    cpu_label( _environment, label );
    dojo_end( _environment );

    cpu_move_8bit( _environment, result->realName, "DOJOERROR" );

    return dojoHandle;

}
