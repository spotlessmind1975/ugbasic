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
@keyword MEMCONT

@english

The ''MEMCONT'' instruction uses ''param'' to specify how expansion memory
will use registers. A value of 0 causes the registers for both sides of the 
transfer to automatically increment after each byte. The value 1 locks 
the expansion memory register, only the computer register continues to 
count (good for quickly deleting memory areas). The value 2 locks the computer address 
and only allows the expansion memory side to continue to count. The value 3 locks both sides
of the transfer.

@italian

L'istruzione ''MEMCONT'' usa ''param'' per specificare come la memoria di espansione
utilizzerà i registri. Un valore di 0 fa sì che i registri per entrambi i lati del
trasferimento vengano automaticamente incrementati dopo ogni byte. Il valore 1 blocca
il registro della memoria di espansione, solo il registro del computer continua a
contare (utile per riempire rapidamente le aree di memoria). Il valore 2 blocca 
l'indirizzo del computer e consente solo al lato della memoria di espansione di 
continuare a contare. Il valore 3 blocca entrambi i lati del trasferimento.

@syntax MEMCONT param

@example MEMCONT 1

@usedInExample tsb_memload.bas

@seeAlso MEMLEN
@seeAlso MEMPOS
@seeAlso MEMCONT
@seeAlso MEMRESTORE
@seeAlso MEMLOAD
@seeAlso MEMSAVE
@seeAlso MEMDEF

</usermanual> */

void memcont( Environment * _environment, char * _param ) {

    Variable * memcont = variable_retrieve_or_define( _environment, "MEMCONT", VT_BYTE, 0 );

    Variable * param = variable_retrieve_or_define( _environment, _param, VT_BYTE, 0 );

    variable_move( _environment, param->name, memcont->name );
    
}
