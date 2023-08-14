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
 * @brief Emit ASM code for instruction <b>= BANK ADDRESS( )</b>
 * 
 * This function outputs the ASM code to get the resident
 * memory address for the given bank.
 * 
 * @param _environment Current calling environment
 * @param _bank Bank to get address of
 * @return Current address of the bank selected
 */
/* <usermanual>
@keyword BANK ADDRESS
</usermanual> */
Variable * bank_get_address( Environment * _environment, int _bank ) {

    Variable * result = variable_temporary( _environment, VT_ADDRESS, "(bank address)" );

    int address = 0xf000 + ( BANK_SIZE * ( _bank - 1 ) );

    outline1("LD HL, $%4.4x", address);
    outline1("LD (%s), L", result->realName );
    outline1("LD (%s+1), H", result->realName );

    return result;
    
}

/**
 * @brief Emit ASM code for instruction <b>= BANK ADDRESS( )</b>
 * 
 * This function outputs the ASM code to get the resident
 * memory address for the given bank.
 * 
 * @param _environment Current calling environment
 * @param _bank Bank to get address of
 * @return Current address of the bank selected
 */
/* <usermanual>
@keyword BANK ADDRESS
</usermanual> */
Variable * bank_get_address_var( Environment * _environment, char * _bank ) {

    MAKE_LABEL

    Variable * result = variable_temporary( _environment, VT_ADDRESS, "(bank address)" );
    Variable * bank = variable_temporary( _environment, VT_BYTE, "(bank number)" );

    int address = 0xebff;

    outline1("LD HL, $%4.4x", address);

    outline1("LD A, (%s)", bank->realName );
    outline0("DEC A" );
    outline1("JR Z, %sbgaf", label );

    outhead1("%sbga:", label );
    outline1("LD DE, $%4.4x", BANK_SIZE );
    outline0("ADD HL, DE" );
    outline0("DEC A" );
    outline1("JR NZ, %sbga", label );

    outhead1("%sbgaf:", label );
    outline1("LD (%s), HL", result->realName );

    return result;
    
}
