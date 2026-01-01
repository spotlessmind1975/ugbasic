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

    deploy_preferred( bank, src_hw_c128z_bank_asm );

    outline1("LD HL, $%4.4x", (unsigned char) ( _address1 & 0xffff ) );
    outline1("LD DE, %s", _address2 );

    switch( _size ) {
        case 1:
            outline1("LD A, $%2.2x", _bank );
            outline0("CALL BANKREAD1");
            _environment->bankAccessOptimization.read1 = 1;
            break;
        case 2:
            outline1("LD A, $%2.2x", _bank );
            outline0("CALL BANKREAD2");
            _environment->bankAccessOptimization.read2 = 1;
            break;
        case 4:
            outline1("LD A, $%2.2x", _bank );
            outline0("CALL BANKREAD4");
            _environment->bankAccessOptimization.read4 = 1;
            break;
        default:
            outline1("LD BC, $%4.4x", (unsigned short) (_size&0xffff) );
            outline0("CALL BANKREAD");
            break;

    }
    outline0("; end bank read");

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

    deploy_preferred( bank, src_hw_c128z_bank_asm );

    Variable * bank = variable_retrieve_or_define( _environment, _bank, VT_BYTE, 0 );
    Variable * address1 = variable_retrieve_or_define( _environment, _address1, VT_ADDRESS, 0 );
    Variable * address2 = variable_retrieve_or_define( _environment, _address2, VT_ADDRESS, 0 );
    Variable * size = variable_retrieve_or_define( _environment, _size, VT_WORD, 0 );

    outline1("LD HL, (%s)", address1->realName );
    outline1("LD DE, (%s)", address2->realName );
    outline1("LD BC, (%s)", size->realName );
    outline1("LD A, (%s)", bank->realName );
    outline0("CALL BANKREAD");

    outline0("; end bank read");

}

void bank_read_vars_direct( Environment * _environment, char * _bank, char * _address1, char * _address2, char * _size ) {

    deploy_preferred( bank, src_hw_c128z_bank_asm );

    Variable * bank = variable_retrieve_or_define( _environment, _bank, VT_BYTE, 0 );
    Variable * address1 = variable_retrieve_or_define( _environment, _address1, VT_ADDRESS, 0 );
    Variable * address2 = variable_retrieve_or_define( _environment, _address2, VT_ADDRESS, 0 );
    Variable * size = variable_retrieve_or_define( _environment, _size, VT_WORD, 0 );

    outline1("LD HL, (%s)", address1->realName );
    outline1("LD DE, %s", address2->realName );
    outline1("LD BC, (%s)", size->realName );
    outline1("LD A, (%s)", bank->realName );
    outline0("CALL BANKREAD");

    outline0("; end bank read");

}

void bank_read_vars_direct_size( Environment * _environment, char * _bank, char * _address1, char * _address2, int _size ) {

    deploy_preferred( bank, src_hw_c128z_bank_asm );

    Variable * bank = variable_retrieve_or_define( _environment, _bank, VT_BYTE, 0 );
    Variable * address1 = variable_retrieve_or_define( _environment, _address1, VT_ADDRESS, 0 );
    Variable * address2 = variable_retrieve( _environment, _address2 );

    outline1("LD HL, (%s)", address1->realName );

    outline1("LD DE, %s", address2->realName );

    switch( _size ) {
        case 1:
            outline1("LD A, (%s)", bank->realName );
            outline0("CALL BANKREAD1");
            _environment->bankAccessOptimization.read1 = 1;
            break;
        case 2:
            outline1("LD A, (%s)", bank->realName );
            outline0("CALL BANKREAD2");
            _environment->bankAccessOptimization.read2 = 1;
            break;
        case 4:
            outline1("LD A, (%s)", bank->realName );
            outline0("CALL BANKREAD4");
            _environment->bankAccessOptimization.read4 = 1;
            break;
        default:
            outline1("LD BC, $%4.4x", (unsigned short) ( _size & 0xffff ) );
            outline1("LD A, (%s)", bank->realName );
            outline0("CALL BANKREAD");
            _environment->bankAccessOptimization.readn = 1;
            break;

    }
    outline0("; end bank read");

}

void bank_read_vars_bank_direct_size( Environment * _environment, int _bank, char * _address1, char * _address2, int _size ) {

    deploy_preferred( bank, src_hw_c128z_bank_asm );

    Variable * address1 = variable_retrieve_or_define( _environment, _address1, VT_ADDRESS, 0 );
    Variable * address2 = variable_retrieve_or_define( _environment, _address2, VT_ADDRESS, 0 );

    outline1("LD HL, (%s)", address1->realName );
    outline1("LD DE, %s", address2->realName );

    switch( _size ) {
        case 1:
            outline1("LD A, $%2.2x", _bank );
            outline0("CALL BANKREAD1");
            _environment->bankAccessOptimization.read1 = 1;
            break;
        case 2:
            outline1("LD A, $%2.2x", _bank );
            outline0("CALL BANKREAD2");
            _environment->bankAccessOptimization.read2 = 1;
            break;
        case 4:
            outline1("LD A, $%2.2x", _bank );
            outline0("CALL BANKREAD4");
            _environment->bankAccessOptimization.read4 = 1;
            break;
        default:
            outline1("LD BC, $%4.4x", (unsigned short) ( _size & 0xffff ) );
            outline1("LD A, $%2.2x", _bank );
            outline0("CALL BANKREAD");
            _environment->bankAccessOptimization.readn = 1;
            break;

    }
    outline0("; end bank read");

}
