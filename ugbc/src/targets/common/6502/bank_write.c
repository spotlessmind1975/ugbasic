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

#if defined(__atari__) || defined(__atarixl__) || defined(__c64__) || defined(__c128__) || defined(__plus4__) || defined(__vic20__)

/**
 * @brief Emit ASM code for instruction <b>BANK WRITE ...</b>
 * 
 * This function outputs the ASM code to write data from the
 * RAM to a specific bank.
 * 
 * @param _environment Current calling environment
 * @param _bank bank to write to
 * @param _address1 address to read from (RAM)
 * @param _address2 address to write to (0 based)
 * @param _size size of memory to read/write
 */
/* <usermanual>
@keyword BANK WRITE

@english

This instruction can be used to write a number of bytes to an 
out-of-memory bank from main memory. You must therefore indicate 
one of the available banks, the memory address from which you 
want to copy, the size in bytes and finally the destination 
address (the $0000 implies the beginning of the bank), 
which will be the bank memory.

@italian

Questa istruzione può essere utilizzata per scrivere un certo
numero di byte in un banco fuori memoria, provenienti dalla memoria centrale.
Si deve quindi indicare uno dei banchi disponibili, l'indirizzo
di memoria nel quale si vuole copiare il dato (lo $0000 implica l'inizio
del banco), la dimensione in byte ed infine l'indirizzo di
sorgente, che sarà la memoria RAM.

@syntax BANK WRITE bank FROM address1 TO address2 SIZE size

@example BANK WRITE 1 FROM $0100 TO $2000 SIZE 128

@seeAlso MEMSAVE

@target all
</usermanual> */

void bank_write_vars( Environment * _environment, char * _address1, char * _bank, char * _address2, char * _size ) {

    outline4("; bank write( ..., %s, %s, %s, %s)", _address1, _bank, _address2, _size );
    // Variable * previous = bank_get( _environment );
    // bank_set_var( _environment, _bank );
    Variable * bankAddress = banks_get_address_var( _environment, _bank );
    Variable * address1 = variable_retrieve_or_define( _environment, _address1, VT_ADDRESS, 0 );
    Variable * address2 = variable_retrieve_or_define( _environment, _address2, VT_ADDRESS, 0 );
    Variable * realAddress = variable_add( _environment, bankAddress->name, address2->name );
    mmove_memory_memory( _environment, address1->name, realAddress->name, _size );
    // bank_set_var( _environment, previous->name );
    outline0("; end bank write")
    
}

void bank_write_vars_direct( Environment * _environment, char * _address1, char * _bank, char * _address2, char * _size ) {

    outline0("; bank write")
    Variable * address1 = variable_retrieve( _environment, _address1 );
    Variable * effectiveAddress = variable_temporary( _environment, VT_ADDRESS, "(effectiveAddress)");
    cpu_addressof_16bit( _environment, address1->realName, effectiveAddress->realName );
    bank_write_vars( _environment, effectiveAddress->name, _bank, _address2, _size );
    outline0("; end bank write")

}

void bank_write_vars_bank_direct_size( Environment * _environment, char * _address1, int _bank, char * _address2, int _size ) {

    outline0("; bank write")
    Variable * address1 = variable_retrieve( _environment, _address1 );
    Variable * effectiveAddress = variable_temporary( _environment, VT_ADDRESS, "(effectiveAddress)");
    Variable * bank = variable_temporary( _environment, VT_WORD, "(bank)");
    Variable * size = variable_temporary( _environment, VT_WORD, "(size)");
    cpu_addressof_16bit( _environment, address1->realName, effectiveAddress->realName );
    variable_store( _environment, bank->name, _bank );
    variable_store( _environment, size->name, _size );
    bank_write_vars( _environment, effectiveAddress->name, bank->name, _address2, size->name );
    outline0("; end bank write")
    
}

#endif