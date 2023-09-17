/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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

void input( Environment * _environment, char * _variable, VariableType _default_type ) {

    MAKE_LABEL
    
    Variable * result = variable_retrieve_or_define( _environment, _variable, _default_type, 0 );

    char repeatLabel[MAX_TEMPORARY_STORAGE]; sprintf(repeatLabel, "%srepeat", label );
    char skipColorChangeLabel[MAX_TEMPORARY_STORAGE]; sprintf(skipColorChangeLabel, "%sskipcc", label );
    char finishedLabel[MAX_TEMPORARY_STORAGE]; sprintf(finishedLabel, "%sfinished", label );
    char backspaceLabel[MAX_TEMPORARY_STORAGE]; sprintf(backspaceLabel, "%sbackspace", label );

    Variable * temporary = variable_temporary( _environment, VT_DSTRING, "(temporary storage for input)");
    Variable * offset = variable_temporary( _environment, VT_BYTE, "(offset inside temporary storage)");

    Variable * enter = variable_temporary( _environment, VT_CHAR, "(enter)" );
    Variable * comma = variable_temporary( _environment, VT_CHAR, "(comma)" );
    Variable * space = variable_temporary( _environment, VT_CHAR, "(space)" );
    Variable * underscore = variable_temporary( _environment, VT_CHAR, "(underscore)" );
    Variable * underscoreTimer = variable_temporary( _environment, VT_BYTE, "(underscore timer)" );
    Variable * backspace = variable_temporary( _environment, VT_CHAR, "(backspace)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size max)" );
    Variable * pressed = variable_temporary( _environment, VT_BYTE, "(key pressed?)");
    Variable * key = variable_temporary( _environment, VT_CHAR, "(key pressed)");
    Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)" );

    cpu_store_8bit( _environment, enter->realName, 13 );
    cpu_store_8bit( _environment, offset->realName, 0 );
    cpu_store_8bit( _environment, backspace->realName, 8 );
    cpu_store_8bit( _environment, space->realName, 32 );
    cpu_store_8bit( _environment, zero->realName, 0 );

    cpu_store_8bit( _environment, comma->realName, _environment->inputConfig.separator == 0 ? INPUT_DEFAULT_SEPARATOR : _environment->inputConfig.separator );
    cpu_store_8bit( _environment, size->realName, _environment->inputConfig.size == 0 ? INPUT_DEFAULT_SIZE : _environment->inputConfig.size );
    cpu_store_8bit( _environment, underscore->realName, _environment->inputConfig.cursor == 0 ? INPUT_DEFAULT_CURSOR : _environment->inputConfig.cursor );
    cpu_store_8bit( _environment, underscoreTimer->realName, 143 );
    cpu_store_8bit( _environment, "KBDRATE", ( _environment->inputConfig.rate == 0 ? INPUT_DEFAULT_RATE : _environment->inputConfig.rate ) );
    // cpu_store_8bit( _environment, "KBDDELAY", _environment->inputConfig.delay == 0 ? INPUT_DEFAULT_DELAY : _environment->inputConfig.delay );

    Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address of DSTRING)");
    cpu_dsfree( _environment, temporary->realName );
    cpu_dsalloc( _environment, size->realName, temporary->realName );
    cpu_dsdescriptor( _environment, temporary->realName, address->realName, pressed->realName );

    cpu_label( _environment, repeatLabel );

    // It would be advisable to implement a cursor as similar as possible to the system one 
    // for the COCO target. The cursor blink routine is disassembled in Color BASIC Unravelled ... 
    // there's a frame countdown timer ... something like 11-12 frames the color gets switched 
    // to the next one ... and the characters drawn are 128, then 144, then 160, then 176, 
    // and wrapping around to 128 after drawing character 240:

    cpu_dec( _environment, underscoreTimer->realName );
    cpu_compare_and_branch_8bit_const( _environment, underscoreTimer->realName, 0, skipColorChangeLabel, 0 );
    add_complex( _environment, underscore->name, 16, 143, 224 );
    cpu_store_8bit( _environment, underscoreTimer->realName, 128 );
    cpu_label( _environment, skipColorChangeLabel );

    print( _environment, underscore->name, 0 );
    cmove_direct( _environment, -1, 0 );

    coco3_inkey( _environment, pressed->realName, key->realName );

    cpu_bveq( _environment, pressed->realName, repeatLabel );
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
