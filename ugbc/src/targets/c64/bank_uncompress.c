/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit ASM code for instruction <b>BANK UNCOMPRESS ...</b>
 * 
 * This function outputs the ASM code to uncompress data from
 * a specific bank into the RAM.
 * 
 * @param _environment Current calling environment
 * @param _bank bank from uncompress from
 * @param _address1 address to uncompress from (0 based)
 * @param _address2 address to write to (RAM)
 */
/* <usermanual>
@keyword BANK UNCOMPRESS
@target c64
</usermanual> */
void bank_uncompress_semi_var( Environment * _environment, int _bank, int _address1, char * _address2 ) {

    outline0("; bank uncompress")
    Variable * previous = bank_get( _environment );
    bank_set( _environment, _bank );
    int realAddress = 0xC000 + ( _bank - 1 ) * BANK_SIZE + _address1;
    char realAddressAsString[MAX_TEMPORARY_STORAGE];
    sprintf(realAddressAsString, "$%4.4x", realAddress);
    cpu_msc1_uncompress_direct_direct( _environment, realAddressAsString, _address2 );
    bank_set_var( _environment, previous->name );
    outline0("; end bank uncompress")

}

/**
 * @brief Emit ASM code for instruction <b>BANK UNCOMPRESS ...</b>
 * 
 * This function outputs the ASM code to uncompress data from
 * a specific bank into the RAM.
 * 
 * @param _environment Current calling environment
 * @param _bank bank from uncompress from
 * @param _address1 address to uncompress from (0 based)
 * @param _address2 address to write to (RAM)
 */
/* <usermanual>
@keyword BANK UNCOMPRESS
@target c64
</usermanual> */
void bank_uncompress_vars( Environment * _environment, char * _bank, char * _address1, char * _address2 ) {

    outline0("; bank uncompress")
    Variable * previous = bank_get( _environment );
    bank_set_var( _environment, _bank );
    Variable * bankAddress = bank_get_address_var( _environment, _bank );
    Variable * address1 = variable_retrieve_or_define( _environment, _address1, VT_ADDRESS, 0 );
    Variable * realAddress = variable_add( _environment, bankAddress->name, address1->name );
    Variable * address2 = variable_retrieve_or_define( _environment, _address2, VT_ADDRESS, 0 );
    cpu_msc1_uncompress_indirect_indirect( _environment, realAddress->name, address2->name );
    bank_set_var( _environment, previous->name );
    outline0("; end bank uncompress")

}
