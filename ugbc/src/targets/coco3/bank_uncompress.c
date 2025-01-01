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
void bank_uncompress_semi_var( Environment * _environment, int _bank, int _address1, char * _address2 ) {

    deploy_preferred( duff, src_hw_6809_msc1_asm );
    deploy_preferred( msc1, src_hw_6809_msc1_asm );
    deploy_preferred( bank, src_hw_coco3_bank_asm );

    int realAddress = 0xc000 + _address1;

    // outline0("; bank uncompress (1)")
    // Variable * previous = bank_get( _environment );
    // bank_set( _environment, _bank );
    // int realAddress = 0x6000 + _address1;
    // char realAddressAsString[MAX_TEMPORARY_STORAGE];
    // sprintf(realAddressAsString, "$%4.4x", realAddress);
    // cpu_msc1_uncompress_direct_direct( _environment, realAddressAsString, _address2 );
    // bank_set_var( _environment, previous->name );
    // outline0("; end bank uncompress (1)")

    outline0("; bank uncompress")
    outline1("LDA #$%2.2x", _bank );
    outline1("LDX #$%4.4x", realAddress );
    outline1("LDY #%s", _address2 );
    outline0("JSR BANKUNCOMPRESS");
    outline0("; end bank uncompress");

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
void bank_uncompress_vars( Environment * _environment, char * _bank, char * _address1, char * _address2 ) {

}
