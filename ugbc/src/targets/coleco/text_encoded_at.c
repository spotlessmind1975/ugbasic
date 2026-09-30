/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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

void text_encoded( Environment * _environment, char * _text, char * _pen, char * _paper, int _raw  ) {

    Variable * text = variable_retrieve( _environment, _text );
    Variable * pen = variable_retrieve( _environment, _pen );
    Variable * paper = variable_retrieve( _environment, _paper );

    if ( text->type != VT_DSTRING ) {

        switch( text->type ) {
            case VT_STRING: {
                tms9918_text( _environment, address_displacement( _environment, text->realName, "1" ), text->realName, _raw );
                break;
            }
            case VT_CHAR: {
                tms9918_text( _environment, text->realName, NULL, _raw );
                break;
            }
        }

    } else {

        Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
        Variable * size = variable_temporary( _environment, VT_BYTE, "(size of DSTRING)");

        cpu_dsdescriptor( _environment, text->realName, address->realName, size->realName );
        
        tms9918_text( _environment, cpu_addressin( _environment, address->realName ), size->realName, _raw );

    }

}
