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
@keyword MEMSAVE

@english

The ''MEMSAVE'' instruction stores a previously defined memory area of the
computer (see ''MEMOR'') of a defined length (see ''MEMLEN'') at an equally 
defined address in an expansion memory (see ''MEMPOS''). The command takes 
into account the settings for the transfer type (see ''MEMCONT'') and for 
the autoload of the address and count registers (see ''MEMRESTORE'').

@italian

L'istruzione ''MEMSAVE'' memorizza un'area di memoria del computer definita 
in precedenza (vedere ''MEMOR'') di una lunghezza definita (vedere ''MEMLEN'') 
a un indirizzo ugualmente definito in una memoria di espansione (vedere ''MEMPOS''). 
Il comando tiene conto delle impostazioni per il tipo di trasferimento (vedere 
''MEMCONT'') e per il caricamento automatico dei registri di indirizzo e conteggio 
(vedere ''MEMRESTORE'').

@syntax MEMSAVE

@example MEMSAVE

@usedInExample tsb_memload.bas

@seeAlso MEMLEN
@seeAlso MEMPOS
@seeAlso MEMOR
@seeAlso MEMCONT
@seeAlso MEMRESTORE
@seeAlso MEMLOAD
@seeAlso MEMDEF
@seeAlso BANK WRITE

</usermanual> */

void memsave( Environment * _environment ) {

    Variable * bank = variable_retrieve_or_define( _environment, "MEMBANK", VT_BYTE, 0 );
    Variable * address1 = variable_retrieve_or_define( _environment, "MEMOR", VT_ADDRESS, 0 );
    Variable * address2 = variable_retrieve_or_define( _environment, "MEMPOS", VT_ADDRESS, 0 );
    Variable * size = variable_retrieve_or_define( _environment, "MEMLEN", VT_WORD, 0 );

    bank_write_vars( _environment, bank->name, address1->name, address2->name, size->name );

}
