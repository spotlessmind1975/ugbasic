/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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

/**
 * @brief Emit ASM code for instruction <b>BANK READ ...</b>
 * 
 * This function outputs the ASM code to read data from
 * a specific bank into the RAM.
 * 
 * @param _environment Current calling environment
 * @param _bank bank from read from
 * @param _address1 address to read from (0 based)
 * @param _address2 address to write to (RAM)
 * @param _size size of memory to read/write
 */
/* <usermanual>
@keyword BANK READ

@english
This instruction can be used to read a number of bytes from an 
out-of-memory bank in main memory. You must therefore indicate 
one of the available banks, the memory address from which you 
want to copy (the $0000 implies the beginning of the bank), 
the size in bytes and finally the destination address, 
which will be the RAM memory.

@italian
Questa istruzione può essere utilizzata per leggere un certo
numero di byte da un banco fuori memoria nella memoria centrale.
Si deve quindi indicare uno dei banchi disponibili, l'indirizzo
di memoria dal quale si vuole copiare (lo $0000 implica l'inizio
del banco), la dimensione in byte ed infine l'indirizzo di
destinazione, che sarà la memoria RAM.

@syntax BANK READ [bank] FROM [address1] TO [address2] SIZE [size]

@example BANK READ 1 FROM $0100 TO $2000 SIZE 128

@target pc128op
</usermanual> */
void bank_read_semi_var( Environment * _environment, int _bank, int _address1, char * _address2, int _size ) {

    outline0("; bank read")
    Variable * previous = bank_get( _environment );
    bank_set( _environment, _bank );
    int realAddress = 0x6000 + _address1;
    char realAddressAsString[MAX_TEMPORARY_STORAGE];
    sprintf(realAddressAsString, "$%4.4x", realAddress);
    cpu_mem_move_direct_size( _environment, realAddressAsString, _address2, _size );
    bank_set_var( _environment, previous->name );
    outline0("; end bank read")

}

/**
 * @brief Emit ASM code for instruction <b>BANK READ ...</b>
 * 
 * This function outputs the ASM code to read data from
 * a specific bank into the RAM.
 * 
 * @param _environment Current calling environment
 * @param _bank bank from read from
 * @param _address1 address to read from (0 based)
 * @param _address2 address to write to (RAM)
 * @param _size size of memory to read/write
 */
/* <usermanual>
@keyword BANK READ

@english
This instruction can be used to read a number of bytes from an 
out-of-memory bank in main memory. You must therefore indicate 
one of the available banks, the memory address from which you 
want to copy (the $0000 implies the beginning of the bank), 
the size in bytes and finally the destination address, 
which will be the RAM memory.

@italian
Questa istruzione può essere utilizzata per leggere un certo
numero di byte da un banco fuori memoria nella memoria centrale.
Si deve quindi indicare uno dei banchi disponibili, l'indirizzo
di memoria dal quale si vuole copiare (lo $0000 implica l'inizio
del banco), la dimensione in byte ed infine l'indirizzo di
destinazione, che sarà la memoria RAM.

@syntax BANK READ [bank] FROM [address1] TO [address2] SIZE [size]

@example BANK READ 1 FROM $0100 TO $2000 SIZE 128

@target pc128op
</usermanual> */
void bank_read_vars( Environment * _environment, char * _bank, char * _address1, char * _address2, char * _size ) {

    outline0("; bank read")
    Variable * previous = bank_get( _environment );
    bank_set_var( _environment, _bank );
    Variable * bankAddress = bank_get_address_var( _environment, _bank );
    Variable * address1 = variable_retrieve_or_define( _environment, _address1, VT_ADDRESS, 0 );
    Variable * realAddress = variable_add( _environment, bankAddress->name, address1->name );
    Variable * address2 = variable_retrieve_or_define( _environment, _address2, VT_ADDRESS, 0 );
    mmove_memory_memory( _environment, realAddress->name, address2->name, _size );
    bank_set_var( _environment, previous->name );
    outline0("; end bank read")

}
