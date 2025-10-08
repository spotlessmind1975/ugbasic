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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

extern char DATATYPE_AS_STRING[][16];

/**
 * @brief Emit code for <strong>SERIAL READ datatype</strong>
 * 
 * @param _environment Current calling environment
 */

/* <usermanual>
@keyword SERIAL READ

@target cocob

</usermanual> */

Variable * serial_read_type( Environment * _environment, VariableType _datatype, int _big_endian ) {

    Variable * data = variable_temporary( _environment, _datatype, "(data)" );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size)" );

    switch( VT_BITWIDTH( data->type ) ) {
        case 32: 
        case 16: 
        case 8: {            
            cpu_store_8bit( _environment, size->realName, VT_BITWIDTH( data->type ) >> 3 );
            cpu_addressof_16bit( _environment, data->realName, address->realName );
            break;
        }
        default:
        case 0: {
            CRITICAL_SERIAL_READ_UNSUPPORTED( DATATYPE_AS_STRING[_datatype]);
            break;
        }
    }

    cocob_serial_read( _environment, address->realName, size->realName );

    if ( !_big_endian ) {
        switch( VT_BITWIDTH( data->type ) ) {
            case 32: 
                cpu_swap_8bit( _environment, data->realName, address_displacement( _environment, data->realName, "3" ) );
                cpu_swap_8bit( _environment, address_displacement( _environment, data->realName, "1" ), address_displacement( _environment, data->realName, "2" ) );
                break;
            case 16: 
                cpu_swap_8bit( _environment, data->realName, address_displacement( _environment, data->realName, "1" ) );
                break;
            case 8:
                break;
        }
    }
    
    return data;

}
