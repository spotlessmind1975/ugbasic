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

void read_data_unsafe( Environment * _environment, char * _variable ) {

    Variable * variable;
    if ( variable_exists( _environment, _variable ) ) {
        variable = variable_retrieve( _environment, _variable );
    } else {
        variable = variable_define( _environment, _variable, _environment->defaultVariableType, 0 );
    }

    if ( VT_BITWIDTH( variable->type ) > 1 ) {
        outline0( "LDX DATAPTR" );
        switch( VT_BITWIDTH( variable->type ) ) {
            case 32:
                outline0( "LDD ,X++" );
                outline1( "STD %s", variable->realName );
                outline0( "LDD ,X++" );
                outline1( "STD %s", address_displacement( _environment, variable->realName, "2" ) );
                break;
            case 16:
                outline0( "LDD ,X++" );
                outline1( "STD %s", variable->realName );
                break;
            case 8:
                outline0( "LDA ,X+" );
                outline1( "STA %s", variable->realName );
                break;
        }
        outline0( "STX DATAPTR" );
    } else {
        
        MAKE_LABEL

        Variable * dataptr = variable_retrieve( _environment, "DATAPTR" );

        switch( VT_BITWIDTH( variable->type ) ) {
            case 32:
                cpu_inc_16bit( _environment, dataptr->realName );
                cpu_move_32bit_indirect2( _environment, dataptr->realName, variable->realName );
                cpu_inc_16bit( _environment, dataptr->realName );
                cpu_inc_16bit( _environment, dataptr->realName );
                cpu_inc_16bit( _environment, dataptr->realName );
                cpu_inc_16bit( _environment, dataptr->realName );
                break;
            case 16:
                cpu_inc_16bit( _environment, dataptr->realName );
                cpu_move_16bit_indirect2( _environment, dataptr->realName, variable->realName );
                cpu_inc_16bit( _environment, dataptr->realName );
                cpu_inc_16bit( _environment, dataptr->realName );
                break;
            case 8:
                cpu_inc_16bit( _environment, dataptr->realName );
                cpu_move_8bit_indirect2( _environment, dataptr->realName, variable->realName );
                cpu_inc_16bit( _environment, dataptr->realName );
                break;
            case 1:
                CRITICAL_READ_DATA_TYPE_NOT_SUPPORTED( _variable, DATATYPE_AS_STRING[variable->type] );
                break;
            case 0:
                switch( variable->type ) {
                    case VT_DSTRING: {
                        Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)" );
                        Variable * size = variable_temporary( _environment, VT_BYTE, "(size)" );
                        cpu_move_8bit_indirect2( _environment, dataptr->realName, size->realName );
                        cpu_inc_16bit( _environment, dataptr->realName );
                        cpu_dsfree( _environment, variable->realName );
                        cpu_dsalloc( _environment, size->realName, variable->realName );
                        cpu_dsdescriptor( _environment, variable->realName, address->realName, size->realName );
                        cpu_mem_move( _environment, dataptr->realName, address->realName, size->realName );
                        cpu_math_add_16bit_with_8bit( _environment, dataptr->realName, size->realName, dataptr->realName );
                        break;
                    }
                    default:
                        CRITICAL_READ_DATA_TYPE_NOT_SUPPORTED( _variable, DATATYPE_AS_STRING[variable->type] );
                }
                break;
        }


    }


}
