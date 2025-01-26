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
@keyword MEMRESTORE

@english

The ''MEMRESTORE'' instruction uses ''param'' to control the automatic reloading 
of the transfer registers, after a transfer. The value 0 means "do not reload" and 
leaves all registers at the last value reached during the transfer. A valure of
1 resets all transfer registers to the values set before the transfer. In addition, 
by setting the bit 7 in the ''param'' it ensures, under ''c64reu'' taqget, that the 
accesses in the IO area are made to the color RAM and not to the RAM below.

@italian

L'istruzione ''MEMRESTORE'' utilizza ''param'' per controllare il ripristino automatico
dei registri di trasferimento. Un valore di 0 significa "non ripristinare" e
lascia tutti i registri all'ultimo valore raggiunto durante il trasferimento. Un valore di
1 reinizializza tutti i record di trasferimento dei valori fissati prima del trasferimento. Inoltre,
posse a 1 il bit 7 in ''param'' garantisce, sul target ''c64reu'', che
L'accesso alla zona di IO sia svolto sulla RAM colore e non sulla RAM sottostqnte.

@syntax MEMRESTORE param

@example MEMRESTORE 129

@usedInExample tsb_memload.bas

@seeAlso MEMLEN
@seeAlso MEMPOS
@seeAlso MEMCONT
@seeAlso MEMRESTORE
@seeAlso MEMLOAD
@seeAlso MEMSAVE
@seeAlso MEMDEF

</usermanual> */

void memrestore( Environment * _environment, char * _param ) {

    Variable * memrestore = variable_retrieve_or_define( _environment, "MEMRESTORE", VT_BYTE, 0 );

    Variable * param = variable_retrieve_or_define( _environment, _param, VT_BYTE, 0 );

    variable_move( _environment, param->name, memrestore->name );
    
}
