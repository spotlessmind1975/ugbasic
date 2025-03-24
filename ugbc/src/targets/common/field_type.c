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

void field_type( Environment * _environment, char * _name, VariableType _datatype ) {

    if ( !_environment->currentType ) {
        CRITICAL_CANNOT_DEFINE_OUTSIDE_TYPE(_name);
    }

    if ( VT_BITWIDTH( _datatype ) == 0 ) {
        CRITICAL_CANNOT_USE_DATATYPE_IN_TYPE(_name);
    }

    Field * field = malloc( sizeof( Field ) );
    memset( field, 0, sizeof( Field ) );

    int currentOffset = 0;
    Field * current = _environment->currentType->first;
    Field * last = NULL;
    if ( current ) {
        while( current ) {
            currentOffset = current->offset + (VT_BITWIDTH( current->type ) >> 3);
            last = current;
            current = current->next;
        }
    }

    field->name = strdup( _name );
    field->type = _datatype;
    field->offset = currentOffset;

    _environment->currentType->size = currentOffset +  (VT_BITWIDTH( field->type ) >> 3);

    if ( last ) {
        last->next = field;
    } else {
        _environment->currentType->first = field;
    }

}
