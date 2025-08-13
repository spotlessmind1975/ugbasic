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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

#if defined(__plus4__) || defined(__c16__)

void textmap_at( Environment * _environment, int _address ) {

    

    // Let's define the special variable bitmapAddress, and update
    // it with the requested value.
    Variable * TEXTADDRESS = variable_retrieve( _environment, "TEXTADDRESS" );
    variable_store( _environment, TEXTADDRESS->realName, ( ( _address >> 10 ) & 0x0f ) * 0x8400 );

    char addressString[MAX_TEMPORARY_STORAGE]; sprintf(addressString, "#$%2.2x", ( _address >> 8 ) & 0xff );

    ted_textmap_at( _environment, addressString );

}

void textmap_at_var( Environment * _environment, char * _address ) {

    

    Variable * TEXTADDRESS = variable_retrieve( _environment, "TEXTADDRESS" );
    Variable * address = variable_retrieve( _environment, _address );

    variable_move( _environment, address->name, TEXTADDRESS->name );

    char addressString[MAX_TEMPORARY_STORAGE]; sprintf(addressString, "%s", address_displacement(_environment, address->realName, "1") );

    ted_textmap_at( _environment, addressString );

}

#endif
