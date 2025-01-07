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
@keyword MEMPOS

@english

The ''MEMPOS'' instruction tells to an expansion memory management which 
address (''address'') and which bank (''bank')  should be affected 
by the data transfer (start or destination address of the transfer).

@italian

L'istruzione ''MEMPOS'' indica a un gestore di memoria di espansione quale 
indirizzo (''address'') e quale banco (''bank') devono essere interessati 
dal trasferimento dati (indirizzo di inizio o di destinazione del trasferimento).

@syntax MEMPOS address, bank

@example MEMPOS 1000, 0

@usedInExample tsb_memload.bas

@seeAlso MEMLEN
@seeAlso MEMOR
@seeAlso MEMCONT
@seeAlso MEMRESTORE
@seeAlso MEMLOAD
@seeAlso MEMSAVE

</usermanual> */

void mempos( Environment * _environment, char * _address, char * _bank ) {

    Variable * membank = variable_retrieve_or_define( _environment, "MEMBANK", VT_BYTE, 0 );
    Variable * mempos = variable_retrieve_or_define( _environment, "MEMPOS", VT_ADDRESS, 0 );
    Variable * bank = variable_retrieve_or_define( _environment, _bank, VT_BYTE, 0 );
    Variable * address = variable_retrieve_or_define( _environment, _address, VT_ADDRESS, 0 );

    variable_move( _environment, address->name, mempos->name );
    variable_move( _environment, bank->name, membank->name );

}
