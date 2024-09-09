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

extern char DATATYPE_AS_STRING[][16];

/**
 * @brief Emit code for <strong>INPUT...</strong> instruction
 * 
 * @param _environment Current calling environment
 * @param _variable Variable where to store the input
 * @param _default_type Type of variable to input
 */

/* <usermanual>
@keyword INPUT

@english

The ''INPUT'' provides a standard way of entering information into one or more variables. 
There are two possible formats for this instruction. 

The first require that the programmer enters a list of variables directly as a list. 
Each variable must be separated by a comma. A question mark will be automatically displayed 
at the current cursor position.

The second needs a string as the first parameter. The string will be used as a prompt 
before entering information. When a semicolon ('';'') is used after the text output to
the user, a question mark (''?'') is added to the output. When a comma ('','') 
is used, no question mark is added.

When you execute one of these commands, ugBASIC will wait to enter the required
information from the keyboard. Each variable must be matched by a single value from the user. 
These values must be of the same type as the original variables, and they should
be separated by commas.

If a string is specified (e.g., ''name$''), anything the user 
enters before pressing the 'return' key will be accepted. If a numeric variable 
(e.g., 'age') is specified, the user must enter a number. If any non-numeric key 
is entered, the value 0 will be returned.

The optional semi-colon '';'' at the end the variables list specifies that the 
text cursor will not be affected by the ''INPUT'' instruction, and it will retain its 
original position after the data has been entered, instead of moving to the next line,
following the enter key.

Note that the separator character can be changed by using the ''DEFINE INPUT SEPARATOR''
command, by giving the ASCII code value to use instead of the default (comma). Moreover,
the size of the input buffer can be changed using the ''DEFINE INPUT SIZE'' instruction.
Finally, the character used as cursor can be changed using the ''DEFINE INPUT CURSOR'' 
instruction.

@italian

@syntax INPUT var1 [, var2 [, ..]] [;]
@syntax INPUT [prompt;] [var1] [, var2 [, ..]] [;]
@syntax INPUT [prompt,] [var1] [, var2 [, ..]] [;]

@example INPUT age
@example INPUT "what is your name"; name$
@example INPUT "digit a number [0-9]:", number

@usedInExample control_case_01.bas
@target all
@verified
</usermanual> */
void input( Environment * _environment, char * _variable, VariableType _default_type ) {

    MAKE_LABEL
    
    Variable * result = variable_retrieve_or_define( _environment, _variable, _default_type, 0 );

    char repeatLabel[MAX_TEMPORARY_STORAGE]; sprintf(repeatLabel, "%srepeat", label );
    char finishedLabel[MAX_TEMPORARY_STORAGE]; sprintf(finishedLabel, "%sfinished", label );
    char doneLabel[MAX_TEMPORARY_STORAGE]; sprintf(doneLabel, "%sdone", label );
    char backspaceLabel[MAX_TEMPORARY_STORAGE]; sprintf(backspaceLabel, "%sbackspace", label );

    Variable * temporary = variable_temporary( _environment, VT_DSTRING, "(temporary storage for input)");
    Variable * offset = variable_temporary( _environment, VT_BYTE, "(offset inside temporary storage)");

    Variable * enter = variable_temporary( _environment, VT_CHAR, "(enter)" );
    Variable * comma = variable_temporary( _environment, VT_CHAR, "(comma)" );
    Variable * space = variable_temporary( _environment, VT_CHAR, "(space)" );
    Variable * underscore = variable_temporary( _environment, VT_CHAR, "(underscore)" );
    Variable * backspace = variable_temporary( _environment, VT_CHAR, "(backspace)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size max)" );
    Variable * pressed = variable_temporary( _environment, VT_BYTE, "(key pressed?)");
    Variable * key = variable_temporary( _environment, VT_CHAR, "(key pressed)");
    Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)" );

    cpu_store_8bit( _environment, enter->realName, 13 );
    cpu_store_8bit( _environment, offset->realName, 0 );
    cpu_store_8bit( _environment, backspace->realName, 20 );
    cpu_store_8bit( _environment, space->realName, 32 );
    cpu_store_8bit( _environment, zero->realName, 0 );

    if ( _environment->lineInput ) {
        cpu_store_8bit( _environment, comma->realName, 13 );
    } else {
        cpu_store_8bit( _environment, comma->realName, _environment->inputConfig.separator == 0 ? INPUT_DEFAULT_SEPARATOR : _environment->inputConfig.separator );
    }

    cpu_store_8bit( _environment, size->realName, _environment->inputConfig.size == 0 ? INPUT_DEFAULT_SIZE : _environment->inputConfig.size );
    cpu_store_8bit( _environment, underscore->realName, _environment->inputConfig.cursor == 0 ? INPUT_DEFAULT_CURSOR : _environment->inputConfig.cursor );

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
    cpu_dsfree( _environment, temporary->realName );
    cpu_dsalloc( _environment, size->realName, temporary->realName );
    cpu_dsdescriptor( _environment, temporary->realName, address->realName, pressed->realName );

    cpu_label( _environment, repeatLabel );

    print( _environment, underscore->name, 0 );
    cmove_direct( _environment, -1, 0 );

    c64_inkey( _environment, key->realName );

    cpu_bveq( _environment, key->realName, repeatLabel );

    cpu_compare_8bit( _environment, key->realName, backspace->realName, pressed->realName, 1 );

    cpu_bvneq( _environment, pressed->realName, backspaceLabel );

    cpu_compare_8bit( _environment, key->realName, comma->realName, pressed->realName, 1 );

    cpu_bvneq( _environment, pressed->realName, finishedLabel );

    cpu_compare_8bit( _environment, key->realName, enter->realName, pressed->realName, 1 );

    cpu_bvneq( _environment, pressed->realName, finishedLabel );

    print( _environment, key->name, 0 );

    cpu_move_8bit_indirect_with_offset2( _environment, key->realName, address->realName, offset->realName );

    cpu_inc( _environment, offset->realName );

    cpu_compare_8bit( _environment, offset->realName, size->realName, pressed->realName, 1 );

    cpu_bveq( _environment, pressed->realName, repeatLabel );

    cpu_jump( _environment, finishedLabel );

    cpu_label( _environment, backspaceLabel );

    cpu_compare_8bit( _environment, offset->realName, zero->realName, pressed->realName, 1 );
    
    cpu_bvneq( _environment, pressed->realName, repeatLabel );

    cpu_dec( _environment, offset->realName );

    print( _environment, space->name, 0 );

    cmove_direct( _environment, -2, 0 );

    print( _environment, space->name, 0 );

    cmove_direct( _environment, -1, 0 );
    
    cpu_jump( _environment, repeatLabel );

    cpu_label( _environment, finishedLabel );

    print( _environment, space->name, 0 );
    cmove_direct( _environment, -1, 0 );
    
    cpu_compare_8bit( _environment, comma->realName, enter->realName, pressed->realName, 1 );
    cpu_bveq( _environment, pressed->realName, doneLabel );

    print_newline( _environment );

    cpu_label( _environment, doneLabel );

    cpu_dsresize( _environment, temporary->realName, offset->realName );

    switch( VT_BITWIDTH( result->type ) ) {
        case 8:
        case 16:
        case 32:
            variable_move( _environment, variable_string_val( _environment, temporary->name )->name, result->name );
            break;
        case 0:
            switch( result->type ) {
                case VT_DSTRING:
                    variable_move_naked( _environment, temporary->name, result->name );
                    break;
                default:
                    CRITICAL_INPUT_UNSUPPORTED( _variable, DATATYPE_AS_STRING[result->type] );        
            }
    }

}
