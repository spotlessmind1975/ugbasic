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
 
 Variable * dojo_get_message( Environment * _environment, char * _port, char * _channel ) {
 
    MAKE_LABEL

    Variable * port = variable_retrieve( _environment, _port );
    Variable * channel = NULL;
    if ( _channel ) {
        channel = variable_retrieve_or_define( _environment, _channel, VT_BYTE, 0 );
    }
    Variable * result = variable_temporary( _environment, VT_DSTRING, "(result)");
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size)");
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(size)");

    if ( port->type != VT_DOJOKA ) {
        DOJO_PEEK_MESSAGE_DOJOKA_REQUIRED( _port, DATATYPE_AS_STRING[port->type]);
    }

    dojo_put_requestds( _environment, DOJO_CMD_SELECT_PORT, NULL, NULL, port->realName, 4, result->realName );
    cpu_compare_and_branch_8bit_const( _environment, result->realName, 0, label, 0 );
    dojo_put_request0( _environment, DOJO_CMD_GET_MESSAGE, channel ? channel->realName : NULL, NULL, result->realName );
    cpu_compare_and_branch_8bit_const( _environment, result->realName, 0, label, 0 );
    dojo_get_response_size( _environment, result->realName, size->realName );
    cpu_dsalloc( _environment, size->realName, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address->realName, NULL );
    dojo_get_response_payload( _environment, address->realName );

    cpu_label( _environment, label );

    cpu_move_8bit( _environment, result->realName, "DOJOERROR" );

    return result;
    
}
 