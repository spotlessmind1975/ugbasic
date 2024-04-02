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

#if defined(__atari__) || defined(__atarixl__) || defined(__c64__) || defined(__c128__)

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
@target atari
@verified
</usermanual> */
void bank_uncompress_semi_var( Environment * _environment, int _bank, int _address1, char * _address2 ) {

    char * bankAddress = banks_get_address( _environment, _bank );
    Variable * realAddress = variable_temporary( _environment, VT_ADDRESS, "(ADDRESS)" );
    cpu_addressof_16bit( _environment, bankAddress, realAddress->realName );
    cpu_math_add_16bit_const( _environment, realAddress->realName, _address1, realAddress->realName );
    Variable * address2 = variable_retrieve_or_define( _environment, _address2, VT_ADDRESS, 0 );

    cpu_msc1_uncompress_indirect_direct( _environment, realAddress->realName, _address2 );

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
</usermanual> */
void bank_uncompress_vars( Environment * _environment, char * _bank, char * _address1, char * _address2 ) {

    Variable * bankAddress = banks_get_address_var( _environment, _bank );
    Variable * address1 = variable_retrieve_or_define( _environment, _address1, VT_ADDRESS, 0 );
    Variable * realAddress = variable_add( _environment, bankAddress->name, address1->name );
    Variable * address2 = variable_retrieve_or_define( _environment, _address2, VT_ADDRESS, 0 );

    cpu_msc1_uncompress_indirect_indirect( _environment, realAddress->name, address2->name );
    
}

#endif