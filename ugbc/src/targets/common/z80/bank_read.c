/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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

#if defined(__c128z__) || defined(__msx1__) || defined(__coleco__) || defined(__cpc__) || defined(__sc3000__) || defined(__sg1000__) || defined(__vg5000__) || defined(__zx__)

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
void bank_read_semi_var( Environment * _environment, int _bank, int _address1, char * _address2, int _size ) {

    char * bankAddress = banks_get_address( _environment, _bank );
    Variable * realAddress = variable_temporary( _environment, VT_ADDRESS, "(ADDRESS)" );
    variable_store( _environment, realAddress->realName, 0 );
    cpu_math_add_16bit( _environment, realAddress->realName, bankAddress, realAddress->realName );
    cpu_math_add_16bit_const( _environment, realAddress->realName, _address1, realAddress->realName );

    cpu_mem_move_indirect_direct_size( _environment, realAddress->realName, _address2, _size );

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
void bank_read_vars( Environment * _environment, char * _bank, char * _address1, char * _address2, char * _size ) {

    Variable * bankAddress = banks_get_address_var( _environment, _bank );
    Variable * address1 = variable_retrieve_or_define( _environment, _address1, VT_ADDRESS, 0 );
    Variable * realAddress = variable_add( _environment, bankAddress->name, address1->name );
    Variable * address2 = variable_retrieve_or_define( _environment, _address2, VT_ADDRESS, 0 );
    Variable * size = variable_retrieve_or_define( _environment, _size, VT_WORD, 0 );

    cpu_mem_move( _environment, realAddress->realName, address2->realName, size->realName );

}

void bank_read_vars_direct( Environment * _environment, char * _bank, char * _address1, char * _address2, char * _size ) {

    Variable * bankAddress = banks_get_address_var( _environment, _bank );
    Variable * address1 = variable_retrieve_or_define( _environment, _address1, VT_ADDRESS, 0 );
    Variable * realAddress = variable_add( _environment, bankAddress->name, address1->name );
    Variable * size = variable_retrieve_or_define( _environment, _size, VT_WORD, 0 );
    Variable * address2 = variable_retrieve_or_define( _environment, _address2, VT_ADDRESS, 0 );

    cpu_mem_move_direct2( _environment, realAddress->realName, address2->realName, size->realName );

}

void bank_read_vars_direct_size( Environment * _environment, char * _bank, char * _address1, char * _address2, int _size ) {

    Variable * bankAddress = banks_get_address_var( _environment, _bank );
    Variable * address1 = variable_retrieve_or_define( _environment, _address1, VT_ADDRESS, 0 );
    Variable * realAddress = variable_add( _environment, bankAddress->name, address1->name );
    Variable * address2 = variable_retrieve_or_define( _environment, _address2, VT_ADDRESS, 0 );

    cpu_mem_move_direct2_size( _environment, realAddress->realName, address2->realName, _size );

}

void bank_read_vars_bank_direct_size( Environment * _environment, int _bank, char * _address1, char * _address2, int _size ) {

    char * bankAddress = banks_get_address( _environment, _bank );
    Variable * address1 = variable_retrieve_or_define( _environment, _address1, VT_ADDRESS, 0 );
    Variable * realAddress = variable_add( _environment, bankAddress, address1->name );
    Variable * address2 = variable_retrieve_or_define( _environment, _address2, VT_ADDRESS, 0 );

    cpu_mem_move_direct2_size( _environment, realAddress->realName, address2->realName, _size );

}

#endif