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

/**
 * @brief Emit ASM code for <b>= RANDOM</b>
 * 
 * This function outputs a code suitable for calculating a random value, 
 * the range of which depends on the type of data passed as a parameter:
 * 
 * - `VT_BYTE` (<b>BYTE</b>) : 0...255
 * - `VT_COLOR` (<b>COLOR</b>) : 0...15
 * - `VT_WORD` (<b>WORD</b>) : 0...65.535
 * - `VT_ADDRESS` (<b>ADDRESS</b>) : 0...65.535
 * - `VT_POSITION` (<b>POSITION</b>) : 0...65.535
 * - `VT_DWORD` (<b>DWORD</b>) : 0...4.294.967.295
 * 
 * The random value is passed back into a temporary variable.
 * 
 * @param _environment Current calling environment
 * @param _type Type of random number to generate
 * @return Variable* The random value calculated
 */
/* <usermanual>
@keyword RANDOM

@target atari
</usermanual> */
Variable * random_value( Environment * _environment, VariableType _type ) {

    Variable * seed = variable_retrieve( _environment, "CPURANDOM_SEED" );

    Variable * result = variable_temporary( _environment, _type, "(random value)" );

    switch( VT_BITWIDTH( _type ) ) {
        case 8:
            cpu6502_random_8bit( _environment, seed->realName, "$14", result->realName );
            break;
        case 16:
            cpu6502_random_16bit( _environment, seed->realName, "$14", result->realName );
            break;
        case 32:
            cpu6502_random_32bit( _environment, seed->realName, "$14", result->realName );
            break;
    }

    return result;

}