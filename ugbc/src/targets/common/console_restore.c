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

    char offset[MAX_TEMPORARY_STORAGE];
    int displacement;

    if ( _number == _environment->activeConsole.id ) {
        return;
    }

    Variable * xcursys = variable_retrieve( _environment, "XCURSYS" );
    Variable * ycursys = variable_retrieve( _environment, "YCURSYS" );

    // -----------------------

    displacement = ( _environment->activeConsole.id * 8 ) + 6;

    sprintf( offset, "+%d", displacement++ );
    cpu_move_8bit( _environment, xcursys->realName, address_displacement( _environment, "CONSOLES", offset ) );
    sprintf( offset, "+%d", displacement++ );
    cpu_move_8bit( _environment, ycursys->realName, address_displacement( _environment, "CONSOLES", offset ) );

    memcpy( &_environment->activeConsole, &_environment->consoles[_number], sizeof( Console ) );

    displacement = ( _number * 8 );

    cpu_store_8bit( _environment, "CONSOLEID", _number );

    sprintf( offset, "+%d", displacement++ );
    cpu_move_8bit( _environment, address_displacement( _environment, "CONSOLES", offset ), "CONSOLEX1" );
    sprintf( offset, "+%d", displacement++ );
    cpu_move_8bit( _environment, address_displacement( _environment, "CONSOLES", offset ), "CONSOLEY1" );
    sprintf( offset, "+%d", displacement++ );
    cpu_move_8bit( _environment, address_displacement( _environment, "CONSOLES", offset ), "CONSOLEX2" );
    sprintf( offset, "+%d", displacement++ );
    cpu_move_8bit( _environment, address_displacement( _environment, "CONSOLES", offset ), "CONSOLEY2" );
    sprintf( offset, "+%d", displacement++ );
    cpu_move_8bit( _environment, address_displacement( _environment, "CONSOLES", offset ), "CONSOLEW" );
    sprintf( offset, "+%d", displacement++ );
    cpu_move_8bit( _environment, address_displacement( _environment, "CONSOLES", offset ), "CONSOLEH" );

    sprintf( offset, "+%d", displacement++ );
    cpu_move_8bit( _environment, address_displacement( _environment, "CONSOLES", offset ), xcursys->realName );
    sprintf( offset, "+%d", displacement++ );
    cpu_move_8bit( _environment, address_displacement( _environment, "CONSOLES", offset ), ycursys->realName );

    console_calculate_vars( _environment );

}

void console_restore_vars( Environment * _environment, char * _number ) {

    Variable * xcursys = variable_retrieve( _environment, "XCURSYS" );
    Variable * ycursys = variable_retrieve( _environment, "YCURSYS" );

    MAKE_LABEL
    
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(consoles)" );
    cpu_addressof_16bit( _environment, "CONSOLES", address->realName  );

    Variable * number = variable_retrieve_or_define( _environment, _number, VT_BYTE, 0 );
    char doNothingLabel[MAX_TEMPORARY_STORAGE]; sprintf( doNothingLabel, "%sconsole", label );
    char doNothingLabel2[MAX_TEMPORARY_STORAGE]; sprintf( doNothingLabel2, "%sconsole2", label );
    cpu_compare_and_branch_8bit_const( _environment, "CONSOLEID", 0xff, doNothingLabel2, 1 );
    cpu_compare_and_branch_8bit( _environment, number->realName, "CONSOLEID", doNothingLabel, 1 );

    Variable * actualNumber = variable_temporary( _environment, VT_BYTE, 0 );
    cpu_move_8bit( _environment, "CONSOLEID", actualNumber->realName );

    cpu_math_mul2_const_8bit( _environment, actualNumber->realName, 3, 0 );
    cpu_math_add_16bit_with_8bit( _environment, address->realName, actualNumber->realName, address->realName );
    cpu_math_add_16bit_const( _environment, address->realName, 6, address->realName );
    cpu_move_8bit_indirect( _environment, xcursys->realName, address->realName );

    cpu_move_8bit_indirect( _environment, xcursys->realName, address->realName );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect( _environment, ycursys->realName, address->realName );

    cpu_label( _environment, doNothingLabel2 );
    
    cpu_move_8bit( _environment, number->realName, "CONSOLEID" );
    cpu_addressof_16bit( _environment, "CONSOLES", address->realName  );

    cpu_move_8bit( _environment, "CONSOLEID", actualNumber->realName );
    cpu_math_mul2_const_8bit( _environment, actualNumber->realName, 3, 0 );
    cpu_math_add_16bit_with_8bit( _environment, address->realName, actualNumber->realName, address->realName );

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
    cpu_move_8bit_indirect2( _environment, address->realName, xcursys->realName );
    cpu_inc_16bit( _environment, address->realName );
    cpu_move_8bit_indirect2( _environment, address->realName, ycursys->realName );

    console_calculate_vars( _environment );

    cpu_label( _environment, doNothingLabel );

}
