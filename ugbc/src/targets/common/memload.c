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
@keyword MEMLOAD

@english

The ''MEMLOAD'' instruction fetches a memory area with a specified length 
(see ''MEMLEN'') from a previously specified address in an expansion memory
(see ''MEMPOS'') and stores it at an equally specified address on the target
computer (see ''MEMOR''). The command takes into account the settings for the 
transfer type (see ''MEMCONT'') and for the autoload of the address and 
counting registers (see ''MEMRESTORE'').

@italian

L'istruzione ''MEMLOAD'' recupera un'area di memoria con una lunghezza 
specificata (vedere ''MEMLEN'') da un indirizzo precedentemente specificato in una 
memoria di espansione (vedere ''MEMPOS'') e la memorizza in un indirizzo ugualmente 
specificato sul computer di destinazione (vedere ''MEMOR''). Il comando tiene 
conto delle impostazioni per il tipo di trasferimento (vedere ''MEMCONT'') e per il 
caricamento automatico dei registri di indirizzo e conteggio (vedere ''MEMRESTORE'').

@syntax MEMLOAD

@example MEMLOAD

@usedInExample tsb_memload.bas

@seeAlso MEMLEN
@seeAlso MEMPOS
@seeAlso MEMOR
@seeAlso MEMCONT
@seeAlso MEMRESTORE
@seeAlso MEMSAVE
@seeAlso MEMSAVE
@seeAlso BANK READ

</usermanual> */

void memload( Environment * _environment ) {

    Variable * bank = variable_retrieve_or_define( _environment, "MEMBANK", VT_BYTE, 0 );
    Variable * address1 = variable_retrieve_or_define( _environment, "MEMPOS", VT_ADDRESS, 0 );
    Variable * address2 = variable_retrieve_or_define( _environment, "MEMOR", VT_ADDRESS, 0 );
    Variable * size = variable_retrieve_or_define( _environment, "MEMLEN", VT_WORD, 0 );

    bank_read_vars( _environment, bank->name, address1->name, address2->name, size->name );
    
}
