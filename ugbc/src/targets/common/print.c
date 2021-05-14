/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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

void print( Environment * _environment, char * _value, int _new_line ) {

    Variable * value = variable_retrieve_or_define( _environment, _value, VT_STRING, 0 );
    
    if ( value->type != VT_STRING ) {
        switch( VT_BITWIDTH( value->type ) ) {
            case 32:
            case 16:
            case 8: {

                Variable * tmp = variable_temporary( _environment, VT_STRING, "(temporary for PRINT)");
                variable_store_string( _environment, tmp->name, "          " );
                
                char tmpAddress[MAX_TEMPORARY_STORAGE]; sprintf(tmpAddress, "%s+1", tmp->realName);
                cpu_bits_to_string( _environment, value->realName, tmpAddress, tmp->realName, VT_BITWIDTH( value->type ) );

                value = tmp;
                
                break;
            }
            case 0:
                CRITICAL_PRINT_UNSUPPORTED( _value, DATATYPE_AS_STRING[value->type]);
        }
    }

    text_text( _environment, value->name );

    if ( _new_line ) {
        text_newline( _environment );
    }

}

void print_tab( Environment * _environment, int _new_line ) {

    text_tab( _environment );

    if ( _new_line ) {
        text_newline( _environment );
    }

}