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

#include "../../ugbc.h"

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
@target c64
</usermanual> */
void bank_write_vars( Environment * _environment, char * _address1, char * _bank, char * _address2, char * _size ) {

    deploy_preferred( duff, src_hw_6809_duff_asm );
    deploy_preferred( msc1, src_hw_6809_msc1_asm );
    deploy_preferred( bank, src_hw_coco3_bank_asm );

    Variable * bank = variable_retrieve_or_define( _environment, _bank, VT_BYTE, 0 );
    Variable * address1 = variable_retrieve_or_define( _environment, _address1, VT_ADDRESS, 0 );
    Variable * address2 = variable_retrieve_or_define( _environment, _address2, VT_ADDRESS, 0 );
    Variable * size = variable_retrieve_or_define( _environment, _size, VT_WORD, 0 );

    outline1("LDY %s", address1->realName );
    outline1("LDX %s", address2->realName );
    outline1("LDA %s", bank->realName );
    outline1("LDU %s", size->realName );
    outline0("JSR BANKREAD");

    outline0("; end bank read");
    
}

void bank_write_vars_bank_direct_size( Environment * _environment, char * _address1, int _bank, char * _address2, int _size ) {

    deploy_preferred( duff, src_hw_6809_duff_asm );
    deploy_preferred( msc1, src_hw_6809_msc1_asm );
    deploy_preferred( bank, src_hw_coco3_bank_asm );

    Variable * address1 = variable_retrieve_or_define( _environment, _address1, VT_ADDRESS, 0 );
    Variable * address2 = variable_retrieve_or_define( _environment, _address2, VT_ADDRESS, 0 );

    outline1("LDY #%s", address1->realName );
    outline1("LDX %s", address2->realName );
    outline1("LDA #$%2.2x", _bank );

    switch( _size ) {
        case 1:
            outline0("JSR BANKWRITE1");
            break;
        case 2:
            outline0("JSR BANKWRITE2");
            break;
        case 4:
            outline0("JSR BANKWRITE4");
            break;
        default:
            outline1("LDU #$%4.4x", _size );
            outline0("JSR BANKWRITE");
            break;

    }
    outline0("; end bank read");    
}
