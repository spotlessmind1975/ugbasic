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
 * @brief Emit ASM code for <b>POKE</b>
 * 
 * @param _environment Current calling environment
 * @param _address Expression with the location to write to.
 * @param _value Expression to write.
 */
/* <usermanual>
@keyword POKE

@english
Store a byte to memory.

@italian
Memorizza un byte nella memoria.

@syntax POKE address, value

@example POKE 32768, 2

@target all

</usermanual> */
void poke_var( Environment * _environment, char * _address, char * _value ) {

    Variable * address = variable_retrieve_or_define( _environment, _address, VT_ADDRESS, 0 );

    Variable * realValue = variable_temporary( _environment, VT_BYTE, "(byte)" );

    Variable * value = NULL;

    if ( variable_exists( _environment, _value ) ) {
        value = variable_retrieve( _environment, _value );
    } else {
        value = variable_temporary( _environment, VT_BYTE, "(byte)" );
    }

    variable_move( _environment, value->name, realValue->name );

    cpu_poke( _environment, address->realName, realValue->realName );

}

/* <usermanual>
@keyword POKEW

@english
Store a word to memory.

@italian
Memorizza due byte (una word) nella memoria.

@syntax POKEW address, value

@example POKEW 32768, 1500

@target all
</usermanual> */

void pokew_var( Environment * _environment, char * _address, char * _value ) {

    Variable * address = variable_retrieve_or_define( _environment, _address, VT_ADDRESS, 0 );

    Variable * realValue = variable_temporary( _environment, VT_WORD, "(word)" );

    Variable * value = NULL;

    if ( variable_exists( _environment, _value ) ) {
        value = variable_retrieve( _environment, _value );
    } else {
        value = variable_temporary( _environment, VT_WORD, "(word)" );
    }

    variable_move( _environment, value->name, realValue->name );

    cpu_pokew( _environment, address->realName, realValue->realName );

}

/* <usermanual>
@keyword POKED

@english
Store a double word to memory.

@italian
Memorizza quattro byte (una double word) nella memoria.

@syntax POKED address, value

@example POKED 32768, 15002348

@target all
</usermanual> */

void poked_var( Environment * _environment, char * _address, char * _value ) {

    Variable * address = variable_retrieve_or_define( _environment, _address, VT_ADDRESS, 0 );

    Variable * realValue = variable_temporary( _environment, VT_DWORD, "(dword)" );

    Variable * value = NULL;

    if ( variable_exists( _environment, _value ) ) {
        value = variable_retrieve( _environment, _value );
    } else {
        value = variable_temporary( _environment, VT_DWORD, "(dword)" );
    }

    variable_move( _environment, value->name, realValue->name );

    cpu_poked( _environment, address->realName, realValue->realName );

}
