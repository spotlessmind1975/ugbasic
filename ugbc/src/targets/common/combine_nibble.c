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

/**
 * @brief Emit code for <strong>COMBINE NIBBLE</strong>
 * 
 * @param _environment 
 */
/* <usermanual>
@keyword COMBINE NIBBLE

@english
The command ''COMBINE NIBBLE'' allows you to combine two variables that 
contains a 4 bit value (nibble) into a single 8 bit value. The first
value is the high nibble.

@italian
Il comando ''COMBINE NIBBLE'' consente di combinare due variabili che 
contengono un valore a 4 bit (nibble) in un unico valore a 8 bit.
Il primo valore è quello del nibble più significativo.

@syntax = COMBINE NIBBLE( value1, value2 )

@example b = COMBINE NIBBLE( 8, 8 )

@target all
</usermanual> */
Variable * combine_nibble_vars( Environment * _environment, char * _low, char * _high ) {

    Variable * low = variable_retrieve_or_define( _environment, _low, VT_BYTE, 0 );
    Variable * high = variable_retrieve_or_define( _environment, _high, VT_BYTE, 0 );
    Variable * byte = variable_temporary( _environment, VT_BYTE, "(byte)" );

    cpu_combine_nibbles( _environment, low->realName, high->realName, byte->realName );

    return byte;

}
