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
 * @brief Emit code for <strong>CONSOLE</strong>
 * 
 * @param _environment 
 */
/* <usermanual>
@keyword CONSOLE RESTORE

@english
The command ''CONSOLE RESTORE'' allows you to restore the constraints of the given 
console, previously saved with the command ''CONSOLE SAVE''.

@italian
Il comando ''CONSOLE RESTORE'' permette di ripristinare i vincoli della console 
data, e salvati in precedenza con il comando ''CONSOLE SAVE''.

@syntax CONSOLE RESTORE number

@example CONSOLE RESTORE 2

@target all
</usermanual> */
/* <usermanual>
@keyword CONSOLE USE

@english
Alias for ''CONSOLE RESTORE''.

@italian
Alias per ''CONSOLE RESTORE''.

@syntax CONSOLE USE number

@example CONSOLE USE 2

@target all
</usermanual> */
void console_restore( Environment * _environment, int _number ) {

    memcpy( &_environment->activeConsole, &_environment->consoles[_number], sizeof( Console ) );

    char offset[MAX_TEMPORARY_STORAGE];

    int value = ( _number * 8 );

    sprintf( offset, "+%d", value++ );
    cpu_move_8bit( _environment, address_displacement( _environment, "CONSOLES", offset ), "CONSOLEX1" );
    sprintf( offset, "+%d", value++ );
    cpu_move_8bit( _environment, address_displacement( _environment, "CONSOLES", offset ), "CONSOLEY1" );
    sprintf( offset, "+%d", value++ );
    cpu_move_8bit( _environment, address_displacement( _environment, "CONSOLES", offset ), "CONSOLEX2" );
    sprintf( offset, "+%d", value++ );
    cpu_move_8bit( _environment, address_displacement( _environment, "CONSOLES", offset ), "CONSOLEY2" );
    sprintf( offset, "+%d", value++ );
    cpu_move_8bit( _environment, address_displacement( _environment, "CONSOLES", offset ), "CONSOLEW" );
    sprintf( offset, "+%d", value++ );
    cpu_move_8bit( _environment, address_displacement( _environment, "CONSOLES", offset ), "CONSOLEH" );

    sprintf( offset, "+%d", value++ );
    cpu_move_8bit( _environment, address_displacement( _environment, "CONSOLES", offset ), "XCURSYS" );
    sprintf( offset, "+%d", value++ );
    cpu_move_8bit( _environment, address_displacement( _environment, "CONSOLES", offset ), "YCURSYS" );

    console_calculate_vars( _environment );

}

void console_restore_vars( Environment * _environment, char * _number ) {

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(consoles)" );
    cpu_addressof_16bit( _environment, "CONSOLES", address->realName  );

    if ( _number ) {
        Variable * number = variable_retrieve_or_define( _environment, _number, VT_BYTE, 0 );
        cpu_math_mul2_const_8bit( _environment, number->realName, 3, 0 );
        cpu_math_add_16bit_with_8bit( _environment, address->realName, number->realName, address->realName );
    }

    cpu_move_8bit_indirect2( _environment, address->realName, "CONSOLEX1" );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect2( _environment, address->realName, "CONSOLEY1" );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect2( _environment, address->realName, "CONSOLEX2" );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect2( _environment, address->realName, "CONSOLEY2" );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect2( _environment, address->realName, "CONSOLEW" );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect2( _environment, address->realName, "CONSOLEH" );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect2( _environment, address->realName, "XCURSYS" );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect2( _environment, address->realName, "YCURSYS" );

    console_calculate_vars( _environment );

}
