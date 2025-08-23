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

#include "../../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

#if defined(__c64__) || defined(__c64reu__) || defined(__c128__)

/**
 * @brief Emit code for <strong>FLASH</strong>
 */
 
/* <usermanual>
@keyword FLASH

@english

The ''FLASH'' command is designed to create a flashing effect by automatically 
alternating color values ​​at a specific memory address, which can be a hardware 
register or a video memory cell. This command is useful for creating dynamic 
visual effects that run in parallel with program execution.

The main command syntax specifies the effect number (up to 4 can be configured, 
from 0 to 3), and a sequence of pairs: number of frames and color tone, separated 
by a comma. An extended syntax allows you to specify the address to which the 
timed values ​​are to be written. If this address is omitted, the standard address 
associated with the effect number will be used, which in turn depends on the 
chipset the program is running on:

 * ''atari'', ''atarixl'': 0 = &H02C4, 1 = &H02C5, 2 = &H02C6, 3 = &H02C7

 * ''c64'', ''c128'', ''c64reu'': 0 = &HD021, 1 = &HD022, 2 = &HD023, 3 = &HD024

 * ''vic20'': 0..3 = &H900F

 * ''c128z'': 0..3 = &H900F

 * ''cpc'': 0..3 = palette 0..3

Note that on the VIC20, the first two effects are bound to the high and low nibbles of the address specified, respectively.

@italian

@syntax FLASH index, color, timer, color, timer[, color[, ...]] [ON address]

@example FLASH 0, 20, RED, 10, BLUE
@example FLASH 0, 20, RED, 10, BLUE ON $d021

@target c64
@target c128
@target c64reu
</usermanual> */

void flash( Environment * _environment, char * _index, char * _register ) {

    Variable * idx = variable_retrieve_or_define( _environment, _index, VT_BYTE, 0 );
    Variable * reg = NULL;
    if ( _register ) {
        reg = variable_retrieve_or_define( _environment, _register, VT_ADDRESS, 0xd021 );
    }

    vic2_flash_begin( _environment, idx->realName, reg!=NULL?reg->realName:NULL );

    int i = 0;

    while( i < _environment->flashVarsIndex ) {
        Variable * timer = variable_retrieve_or_define( _environment, _environment->flashVars[i], VT_BYTE, 0 );
        ++i;
        if ( !timer ) {
            break;
        }
        Variable * color = variable_retrieve_or_define( _environment, _environment->flashVars[i], VT_COLOR, COLOR_BLACK );
        if ( !color ) {
            break;
        }
        ++i;
        vic2_flash_register( _environment, idx->realName, timer->realName, color->realName );
    }

    vic2_flash_end( _environment );

}

void flash_off( Environment * _environment, char * _index ) {

    Variable * idx = variable_retrieve_or_define( _environment, _index, VT_BYTE, 0 );

    vic2_flash_off( _environment, idx->realName );

}

#endif