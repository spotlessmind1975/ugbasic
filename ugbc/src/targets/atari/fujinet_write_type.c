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

/* <usermanual>
@keyword FUJINET WRITE
</usermanual> */
void fujinet_write_type( Environment * _environment, char * _data, VariableType _type ) {

    Variable * data;
    if ( _type == 0 ) {
        data = variable_retrieve( _environment, _data );
    } else {
        data = variable_retrieve_or_define( _environment, _data, _type, 0 );
    }
    Variable * result = variable_temporary( _environment, VT_BYTE, "(result)" );
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
        case 0: {
            switch( data->type ) {
                case VT_STRING: {            
                    cpu_move_8bit( _environment, data->realName, size->realName );
                    cpu_addressof_16bit( _environment, data->realName, address->realName );
                    cpu_inc_16bit( _environment, address->realName );
                    break;
                }
                case VT_DSTRING: {            
                    cpu_dsdescriptor( _environment, data->realName, address->realName, size->realName );
                    break;
                }
                default:
                    CRITICAL_SERIAL_WRITE_UNSUPPORTED( _data, DATATYPE_AS_STRING[data->type]);
                    break;
            }            
            break;
        }
        default:
            CRITICAL_SERIAL_WRITE_UNSUPPORTED( _data, DATATYPE_AS_STRING[data->type]);
            break;
    }

    atari_fujinet_write( _environment, address->realName, size->realName );

}
