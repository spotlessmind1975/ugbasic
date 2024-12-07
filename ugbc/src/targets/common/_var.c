/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
        if ( ! variable->staticalInit && ! imported && ( variable->realName[0] != '_' ) ) {
            switch( variable->type ) {
                case VT_STRING:
                case VT_DSTRING:
                case VT_MSPRITE:
                case VT_SPRITE:
                case VT_DOJOKA:
                case VT_TILESET:
                case VT_TILES:
                case VT_BUFFER:
                case VT_IMAGE:
                case VT_IMAGES:
                case VT_SEQUENCE:
                case VT_TILEMAP:
                case VT_MUSIC:
                case VT_TARRAY:
                case VT_BLIT:
                case VT_FLOAT:
                    break;
                default:
                    if ( variable->value != 0 ) {
                        variable_store( _environment, variable->name, variable->initialValue );
                    }
            }
        }
        variable = variable->next;
    }

    cpu_label( _environment, "VARINITCLEAR" );
    variable = _environment->variables;
    while( variable ) {
        int imported = variable->imported;
        if ( _imported_too ) {
            imported = 0;
        }
        if ( ! variable->staticalInit && ! imported && ( variable->realName[0] == '_' ) ) {
            switch( variable->type ) {
                case VT_STRING:
                case VT_DSTRING:
                case VT_MSPRITE:
                case VT_DOJOKA:
                case VT_TILESET:
                case VT_TILES:
                case VT_BUFFER:
                case VT_IMAGE:
                case VT_IMAGES:
                case VT_SEQUENCE:
                case VT_TILEMAP:
                case VT_MUSIC:
                case VT_TARRAY:
                case VT_BLIT:
                case VT_FLOAT:
                    break;
                default:
                    if ( variable->value != 0 ) {
                        variable_store( _environment, variable->name, variable->initialValue );
                    }
            }
        }
        variable = variable->next;
    }

    cpu_return( _environment );

}

void generate_cgoto_address_table( Environment * _environment ) {

    if ( _environment->hasCGoto ) {

        int numericLabels = 0;
        Label * first = _environment->labels;
        while( first ) {
            if ( first->number ) {
                ++numericLabels;
            }
            first = first->next;
        }

        if ( numericLabels ) {

            int * values = malloc( numericLabels * sizeof( int ) );
            char ** address = malloc( numericLabels * sizeof( char * ) );

            int i = 0;
            first = _environment->labels;
            while( first ) {
                if ( first->number ) {
                    values[i] = first->number;
                    char lineNumber[MAX_TEMPORARY_STORAGE];
                    sprintf(lineNumber, "_linenumber%d", first->number );                    
                    address[i] = strdup( lineNumber );
                    ++i;
                }
                first = first->next;
            }

            cpu_address_table_build( _environment, "CGOTOADDRESS", values, address, numericLabels );

            cpu_address_table_lookup( _environment, "CGOTOADDRESS", numericLabels );

        }
    }

}

