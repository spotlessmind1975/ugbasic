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
 * @brief Emit code for <strong>= CMOVE(...,...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _x Column to locate to
 * @param _y Row to locate to
 */
/* <usermanual>
@keyword CMOVE (function)

@english

The ''CMOVE$'' function can be used to generate a string that moves the text cursor a 
pre-set distance away from its current position. The command is followed by a pair 
of variables that represent the width and height of the required offset, and these 
values are added to the current cursor coordinates. Like ''LOCATE'', either of the
coordinates can be omitted, as long as the comma is positioned correctly. An additional 
technique is to use negative values as well as positive offsets.

@italian

The ''CMOVE$'' function can be used to generate a string that moves the text cursor
a preset distance from its current position. The command is followed by a pair of 
variables representing the width and height of the requested offset, and these values 
​​are added to the current cursor coordinates. Like ''LOCATE'', both coordinates can be 
omitted, as long as the comma is correctly positioned. Another technique is to use 
negative values ​​and positive offsets.

@syntax = CMOVE$( x, y )

@example PRINT CMOVE$(10,10)

@usedInExample texts_position_04.bas

@seeAlso CMOVE (instruction)
@target all
</usermanual> */
Variable * get_cmove( Environment * _environment, char * _x, char * _y ) {
    
    Variable * x = variable_retrieve_or_define( _environment, _x, VT_BYTE, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_BYTE, 0 );

    Variable * result = variable_temporary( _environment, VT_DSTRING, "(get_cmove)" );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(get_cmove)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(get_cmove)" );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x3  " );

    variable_store_string(_environment, result->name, resultString );
    cpu_dswrite( _environment, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );

    cpu_move_8bit_indirect_with_offset(_environment, x->realName, address->realName, 1 );
    cpu_move_8bit_indirect_with_offset(_environment, y->realName, address->realName, 2 );
        
    return result;

}

Variable * get_cmove_direct( Environment * _environment, int _x, int _y ) {
    
    Variable * result = variable_temporary( _environment, VT_DSTRING, 0 );
    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(get_cmove)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(get_cmove)" );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x3  " );

    variable_store_string(_environment, result->name, resultString );
    cpu_dswrite( _environment, result->realName );
    cpu_dsdescriptor( _environment, result->realName, address->realName, size->realName );

    Variable * tmp = variable_temporary( _environment, VT_BYTE, "(get_cmove)" );
    cpu_store_8bit( _environment, tmp->realName, ( _x & 0xff ) );
    cpu_move_8bit_indirect_with_offset( _environment, tmp->realName, address->realName, 1 );
    cpu_store_8bit( _environment, tmp->realName, ( _y & 0xff ) );
    cpu_move_8bit_indirect_with_offset( _environment, tmp->realName, address->realName, 2 );
        
    return result;

}

