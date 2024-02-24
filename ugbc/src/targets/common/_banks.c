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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

void banks_init_extended( Environment * _environment, int * _allowed, int _allowed_count ) {
    
    for(int i=0; i<_allowed_count; ++i) {
        Bank * bank = malloc( sizeof( Bank ) );
        bank->address = 0x0;
        bank->filename = NULL;
        bank->id = _allowed[i];
        char bankName[MAX_TEMPORARY_STORAGE]; sprintf( bankName, "BANK%2.2x", _allowed[i] );
        bank->name = strdup( bankName );
        bank->type = BT_EXPANSION;
        bank->remains = BANK_SIZE;
        bank->space = BANK_SIZE;
        bank->next = _environment->expansionBanks;
        bank->data = malloc( BANK_SIZE );
        memset( bank->data, 0, BANK_SIZE );
        _environment->expansionBanks = bank;
        _environment->maxExpansionBankSize[i+1] = 0;
    }

}

void banks_init( Environment * _environment ) {
    
    for(int i=-1; i<BANK_COUNT; ++i) {
        Bank * bank = malloc( sizeof( Bank ) );
        bank->address = 0x0;
        bank->filename = NULL;
        bank->id = i+1;
        char bankName[MAX_TEMPORARY_STORAGE]; sprintf( bankName, "BANK%2.2x", i+1 );
        bank->name = strdup( bankName );
        bank->type = BT_EXPANSION;
        bank->remains = BANK_SIZE;
        bank->space = BANK_SIZE;
        bank->next = _environment->expansionBanks;
        bank->data = malloc( BANK_SIZE );
        memset( bank->data, 0, BANK_SIZE );
        _environment->expansionBanks = bank;
        _environment->maxExpansionBankSize[i+1] = 0;
    }

}

char * banks_get_address( Environment * _environment, int _bank ) {
    
    Bank * bank = _environment->expansionBanks;

    while( bank ) {
        if ( bank->id == _bank ) {
            break;
        }
        bank = bank->next;
    } 

    if ( ! bank ) {
        CRITICAL_OUT_OF_BANKS( );
    }

    return bank->name;

}

Variable * banks_get_address_var( Environment * _environment, char * _bank ) {

    Variable * bank = variable_retrieve_or_define( _environment, _bank, VT_BYTE, 0 );
    Variable * bankAddress = variable_temporary( _environment, VT_ADDRESS, "(address)" );

    cpu_address_table_call( _environment, "EXPBANKS", bank->realName, bankAddress->realName );

    return bankAddress;
 
}

int banks_store( Environment * _environment, Variable * _variable, int _resident ) {

    Bank * bank = _environment->expansionBanks;

    while( bank ) {
        if ( bank->remains > _variable->size ) {
            break;
        }
        bank = bank->next;
    } 

    if ( ! bank ) {
        return 0;
    }

    _variable->bankAssigned = bank->id;
    _variable->absoluteAddress = bank->address;
    _variable->residentAssigned = _resident;
    _variable->variableUniqueId = UNIQUE_RESOURCE_ID;
    memcpy( &bank->data[bank->address], _variable->valueBuffer, _variable->size );

    bank->address += _variable->size;
    bank->remains -= _variable->size;

    // Now we must calculate the effective size occupied by
    // memory block, when it will be uncompressed. It is needed
    // to have enough memory into the resident part of the
    // memory. If uncompressed size is zero, it means that
    // the memory block is not compressed -- so we can use the
    // size as well.

    if ( _variable->uncompressedSize ) {
        if ( _environment->maxExpansionBankSize[_resident] < _variable->uncompressedSize ) {
            _environment->maxExpansionBankSize[_resident] = _variable->uncompressedSize;
        }
    } else if ( _variable->frameSize ) {
        if ( _environment->maxExpansionBankSize[_resident] < _variable->frameSize ) {
            _environment->maxExpansionBankSize[_resident] = _variable->frameSize;
        }
    }

    return 1;

}
