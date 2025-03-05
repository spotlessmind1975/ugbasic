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
 
 void dojo_download_address( Environment * _environment, char * _app, char * _resource, char * _address ) {
 
    MAKE_LABEL

    Variable * app = variable_retrieve( _environment, _app );
    Variable * resource = variable_retrieve( _environment, _resource );
    Variable * result = variable_retrieve( _environment, _address );

    Variable * size = variable_temporary( _environment, VT_BYTE, "(size)");
    Variable * address = variable_retrieve( _environment, _address );
    Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size)");
    Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(size)");
    Variable * esito = variable_temporary( _environment, VT_BYTE, "(result)");

    Variable * dataSize = variable_temporary( _environment, VT_WORD, "(result)");

    if ( app->type != VT_DOJOKA ) {
        CRITICAL_DOJO_DOWNLOAD_DOJOKA_REQUIRED( _app, DATATYPE_AS_STRING[app->type]);
    }

    switch( resource->type ) {
        case VT_STRING: {            
            cpu_move_8bit( _environment, resource->realName, size2->realName );
            cpu_addressof_16bit( _environment, resource->realName, address2->realName );
            cpu_inc_16bit( _environment, address2->realName );
            break;
        }
        case VT_DSTRING: {            
            cpu_dsdescriptor( _environment, resource->realName, address2->realName, size2->realName );
            break;
        }
        default:
            CRITICAL_DOJO_DOWNLOAD_STRING_REQUIRED( _resource, DATATYPE_AS_STRING[resource->type]);
            break;
    }
        
    dojo_begin( _environment );
    dojo_put_requestds( _environment, DOJO_CMD_SELECT_APP, NULL, NULL, app->realName, 4, esito->realName );
    cpu_compare_and_branch_8bit_const( _environment, esito->realName, 0, label, 0 );
    dojo_put_request( _environment, DOJO_CMD_DOWNLOAD, NULL, NULL, address2->realName, size2->realName, esito->realName );
    cpu_compare_and_branch_8bit_const( _environment, esito->realName, 0, label, 0 );
    dojo_partial( _environment );
    dojo_get_response_size( _environment, esito->realName, dataSize->realName );
    dojo_get_response_payloadw( _environment, address->realName );
    dojo_end( _environment );

    cpu_label( _environment, label );

    cpu_move_8bit( _environment, esito->realName, "DOJOERROR" );
    
}
 