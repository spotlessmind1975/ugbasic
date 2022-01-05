/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

void variable_on_memory_init( Environment * _environment, int _imported_too ) {

    int i=0;

    cpu_label( _environment, "VARINIT" );

    Variable * variable = _environment->variables;
    while( variable ) {
        int imported = variable->imported;
        if ( _imported_too ) {
            imported = 0;
        }
        if ( ! variable->staticalInit && ! imported ) {
            switch( variable->type ) {
                case VT_STRING:
                case VT_DSTRING:
                case VT_MOB:
                case VT_BUFFER:
                case VT_IMAGE:
                case VT_IMAGES:
                case VT_ARRAY:
                    break;
                default:
                    variable_store( _environment, variable->name, variable->value );
            }
        }
        variable = variable->next;
    }

    cpu_return( _environment );

}
