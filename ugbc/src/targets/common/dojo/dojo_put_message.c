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

 #include "../../../ugbc.h"
 
 extern char DATATYPE_AS_STRING[][16];
 
 Variable * dojo_put_message( Environment * _environment, char * _port, char * _channel, char * _message ) {
 
     MAKE_LABEL

     Variable * port = variable_retrieve( _environment, _port );
     Variable * channel = NULL;
     if ( _channel ) {
        channel = variable_retrieve_or_define( _environment, _channel, VT_BYTE, 0 );
     }
     Variable * message = variable_retrieve( _environment, _message );
     Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)");
     Variable * size = variable_temporary( _environment, VT_BYTE, "(size)");
     Variable * result = variable_temporary( _environment, VT_SBYTE, "(result)");
 
     if ( port->type != VT_DOJOKA ) {
        DOJO_PUT_MESSAGE_DOJOKA_REQUIRED( _port, DATATYPE_AS_STRING[port->type]);
     }

     switch( message->type ) {
        case VT_STRING: {            
            cpu_move_8bit( _environment, message->realName, size->realName );
            cpu_addressof_16bit( _environment, message->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            break;
        }
        case VT_DSTRING: {            
            cpu_dsdescriptor( _environment, message->realName, address->realName, size->realName );
            break;
        }
        default:
            DOJO_PUT_MESSAGE_STRING_REQUIRED( _message, DATATYPE_AS_STRING[message->type]);
            break;
    }     

    dojo_begin( _environment );
    dojo_put_requestds( _environment, DOJO_CMD_SELECT_PORT, NULL, NULL, port->realName, 4, result->realName );
    cpu_compare_and_branch_8bit_const( _environment, result->realName, 0, label, 0 );
    dojo_put_request( _environment, DOJO_CMD_PUT_MESSAGE, channel ? channel->realName : NULL, NULL, address->realName, size->realName, result->realName );
    cpu_compare_and_branch_8bit_const( _environment, result->realName, 0, label, 0 );
    dojo_get_response0( _environment, result->realName );
 
    cpu_label( _environment, label );
    dojo_end( _environment );

    cpu_move_8bit( _environment, result->realName, "DOJOERROR" );
    
    char labelReturn[MAX_TEMPORARY_STORAGE]; sprintf( labelReturn, "%srv", label );
    cpu_compare_and_branch_8bit_const( _environment, result->realName, 0, labelReturn, 1 );
    cpu_store_8bit( _environment, result->realName, 0xff );
    cpu_label( _environment, labelReturn );

    return result;
    
}
 