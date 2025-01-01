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

Variable * dojo_login( Environment * _environment, char * _name, char * _password ) {

    Variable * name = variable_retrieve( _environment, _name );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size)" );
    Variable * password = variable_retrieve( _environment, _password );
    Variable * address2 = variable_temporary( _environment, VT_ADDRESS, "(address2)" );
    Variable * size2 = variable_temporary( _environment, VT_BYTE, "(size2)" );
    Variable * result = variable_temporary( _environment, VT_DOJOKA, "(result)" );

    switch( name->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, name->realName, size->realName );
            cpu_addressof_16bit( _environment, name->realName, address->realName );
            cpu_inc_16bit( _environment, address->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, name->realName, address->realName, size->realName );
            break;
    }

    switch( password->type ) {
        case VT_STRING:
            cpu_move_8bit( _environment, password->realName, size2->realName );
            cpu_addressof_16bit( _environment, password->realName, address2->realName );
            cpu_inc_16bit( _environment, address2->realName );
            break;
        case VT_DSTRING:
            cpu_dsdescriptor( _environment, password->realName, address2->realName, size2->realName );
            break;
    }

    mo5_dojo_login( _environment, address->realName, size->realName, address2->realName, size2->realName, result->realName );

    return result;

}
