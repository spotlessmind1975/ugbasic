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
#include "../../libs/msc1.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>DLOAD(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 */
void dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _bank, char * _size ) {

    if ( _bank ) {
        deploy_preferred( duff, src_hw_6809_duff_asm );
        deploy_preferred( msc1, src_hw_6809_msc1_asm );
        deploy_preferred( bank, src_hw_pc128op_bank_asm );        
    }

    if ( _environment->tenLinerRulesEnforced ) {
        CRITICAL_10_LINE_RULES_ENFORCED( "DLOAD");
    }

    if ( _environment->sandbox ) {
        CRITICAL_SANDBOX_ENFORCED( "DLOAD");
    }

    if ( _filename ) {
        WARNING_DLOAD_IGNORED_FILENAME( _filename );
    }

    if ( _offset ) {
        WARNING_DLOAD_IGNORED_OFFSET( _filename );
    }

    Variable * address = variable_retrieve_or_define( _environment, _address, VT_ADDRESS, 0 );
    Variable * size = variable_retrieve_or_define( _environment, _size, VT_WORD, 0 );    
    Variable * bank = NULL;

    if ( _bank ) {
        bank = variable_retrieve_or_define( _environment, _bank, VT_BYTE, 0 );    
    }

    pc128op_dload( _environment, address->realName, _bank?bank->realName:NULL, size->realName );

}
