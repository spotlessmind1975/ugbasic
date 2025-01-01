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

/**
 * @brief Emit code for <strong>CONSOLE</strong>
 * 
 * @param _environment 
 */
/* <usermanual>
@keyword CONSOLE SAVE

@english
The command ''CONSOLE SAVE'' allows you to save the constraints of the given 
console.

@italian
Il comando ''CONSOLE SAVE'' permette di ripristinare i vincoli della console 
data.

@syntax CONSOLE SAVE number

@example CONSOLE SAVE 2

@target all
</usermanual> */
void console_save( Environment * _environment, int _number ) {

    char offset[MAX_TEMPORARY_STORAGE];

    int displacement = ( _number * 8 );

    _environment->activeConsole.id = _number;

    memcpy( &_environment->consoles[_number], &_environment->activeConsole, sizeof( Console ) );

    cpu_store_8bit( _environment, "CONSOLEID", _number );

    sprintf( offset, "+%d", displacement++ );
    cpu_move_8bit( _environment, "CONSOLEX1", address_displacement( _environment, "CONSOLES", offset ) );
    sprintf( offset, "+%d", displacement++ );
    cpu_move_8bit( _environment, "CONSOLEY1", address_displacement( _environment, "CONSOLES", offset ) );
    sprintf( offset, "+%d", displacement++ );
    cpu_move_8bit( _environment, "CONSOLEX2", address_displacement( _environment, "CONSOLES", offset ) );
    sprintf( offset, "+%d", displacement++ );
    cpu_move_8bit( _environment, "CONSOLEY2", address_displacement( _environment, "CONSOLES", offset ) );
    sprintf( offset, "+%d", displacement++ );
    cpu_move_8bit( _environment, "CONSOLEW", address_displacement( _environment, "CONSOLES", offset ) );
    sprintf( offset, "+%d", displacement++ );
    cpu_move_8bit( _environment, "CONSOLEH", address_displacement( _environment, "CONSOLES", offset ) );
    sprintf( offset, "+%d", displacement++ );
    Variable * xcursys = variable_retrieve( _environment, "XCURSYS" );
    cpu_move_8bit( _environment, xcursys->realName, address_displacement( _environment, "CONSOLES", offset ) );
    sprintf( offset, "+%d", displacement++ );
    Variable * ycursys = variable_retrieve( _environment, "YCURSYS" );
    cpu_move_8bit( _environment, ycursys->realName, address_displacement( _environment, "CONSOLES", offset ) );

}

void console_save_vars( Environment * _environment, char * _number ) {
    
    Variable * xcursys = variable_retrieve( _environment, "XCURSYS" );
    Variable * ycursys = variable_retrieve( _environment, "YCURSYS" );

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(consoles)" );
    cpu_addressof_16bit( _environment, "CONSOLES", address->realName  );

    Variable * number = variable_retrieve_or_define( _environment, _number, VT_BYTE, 0 );
    cpu_move_8bit( _environment, number->realName, "CONSOLEID" );
    Variable * displacement = variable_temporary( _environment, VT_BYTE, "(displacement)" );

    cpu_move_8bit( _environment, "CONSOLEID", displacement->realName );
    cpu_math_mul2_const_8bit( _environment, displacement->realName, 3, 0 );
    cpu_math_add_16bit_with_8bit( _environment, address->realName, displacement->realName, address->realName );

    cpu_move_8bit_indirect( _environment, "CONSOLEX1", address->realName );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect( _environment, "CONSOLEY1", address->realName );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect( _environment, "CONSOLEX2", address->realName );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect( _environment, "CONSOLEY2", address->realName );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect( _environment, "CONSOLEW", address->realName );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect( _environment, "CONSOLEH", address->realName );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect( _environment, xcursys->realName, address->realName );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect( _environment, ycursys->realName, address->realName );

}
