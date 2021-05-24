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

extern char DATATYPE_AS_STRING[][16];

Variable * inkey( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_STRING, "(result of INKEY$)");

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, " " );
    char stringAddress[MAX_TEMPORARY_STORAGE]; sprintf( stringAddress, "%s+1", result->realName );

    variable_store_string(_environment, result->name, resultString );

    MAKE_LABEL

    Variable * pressed = variable_temporary( _environment, VT_BYTE, "(key pressed?)");
    Variable * key = variable_temporary( _environment, VT_BYTE, "(key pressed)");

    char noKeyPressedLabel[MAX_TEMPORARY_STORAGE]; sprintf(noKeyPressedLabel, "%snokeyPressed", label );
    char finishedLabel[MAX_TEMPORARY_STORAGE]; sprintf(finishedLabel, "%sfinished", label );

    c64_inkey( _environment, pressed->realName, key->realName );

    cpu_bveq( _environment, pressed->realName, noKeyPressedLabel );

    cpu_move_8bit_indirect_with_offset(_environment, key->realName, stringAddress, 0 );

    cpu_jump( _environment, finishedLabel );

    cpu_label( _environment, noKeyPressedLabel );

    cpu_store_8bit(_environment, result->realName, 0 );

    cpu_label( _environment, finishedLabel );
    
    return result;

}

Variable * scancode( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of SCANCODE)");

    Variable * pressed = variable_temporary( _environment, VT_BYTE, "(key pressed?)");

    c64_scancode( _environment, pressed->realName, result->realName );

    return result;

}

Variable * scanshift( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of SCANSHIFT)");

    c64_scanshift( _environment, result->realName );

    return result;

}

Variable * key_state( Environment * _environment, char * _scancode ) {

    Variable * s = variable_retrieve_or_define( _environment, _scancode, VT_BYTE, 0 );

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of KEY STATE)");

    Variable * key = scancode( _environment );

    return variable_compare( _environment, s->name, key->name );

}

Variable * keyshift( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of KEYSHIFT)");

    c64_keyshift( _environment, result->realName );

    return result;

}

Variable * clear_key( Environment * _environment ) {

    c64_clear_key( _environment );

}

void wait_key( Environment * _environment ) {

    MAKE_LABEL

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of SCANCODE)");

    Variable * pressed = variable_temporary( _environment, VT_BYTE, "(key pressed?)");

    char repeatLabel[MAX_TEMPORARY_STORAGE]; sprintf(repeatLabel, "%srepeat", label );

    cpu_label( _environment, repeatLabel );

    c64_scancode( _environment, pressed->realName, result->realName );

    cpu_bveq( _environment, pressed->realName, repeatLabel );

}

Variable * input_string( Environment * _environment, char * _size ) {

    MAKE_LABEL
    
    char repeatLabel[MAX_TEMPORARY_STORAGE]; sprintf(repeatLabel, "%srepeat", label );

    Variable * result = variable_temporary( _environment, VT_STRING, "(result of INPUT$)");
    Variable * offset = variable_temporary( _environment, VT_BYTE, "(offset inside INPUT$)");

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf(resultString, "%s+1", result->realName );

    Variable * size = variable_retrieve_or_define( _environment, _size, VT_BYTE, 0 );
    Variable * pressed = variable_temporary( _environment, VT_BYTE, "(key pressed?)");
    Variable * key = variable_temporary( _environment, VT_BYTE, "(key pressed)");

    cpu_store_8bit( _environment, offset->realName, 0 );

    cpu_move_8bit( _environment, size->realName, result->realName );

    cpu_label( _environment, repeatLabel );

    c64_inkey( _environment, pressed->realName, key->realName );

    cpu_bveq( _environment, pressed->realName, repeatLabel );
    cpu_bveq( _environment, key->realName, repeatLabel );

    cpu_move_8bit_indirect_with_offset2( _environment, key->realName, resultString, offset->realName );

    cpu_inc( _environment, offset->realName );

    cpu_compare_8bit( _environment, offset->realName, size->realName, pressed->realName, 1 );

    cpu_bveq( _environment, pressed->realName, repeatLabel );

    return result;

}

void input( Environment * _environment, char * _variable ) {

    MAKE_LABEL
    
    Variable * result = variable_retrieve_or_define( _environment, _variable, VT_WORD, 0 );

    char repeatLabel[MAX_TEMPORARY_STORAGE]; sprintf(repeatLabel, "%srepeat", label );
    char finishedLabel[MAX_TEMPORARY_STORAGE]; sprintf(finishedLabel, "%sfinished", label );

    Variable * temporary = variable_temporary( _environment, VT_STRING, "(temporary storage for input)");
    Variable * offset = variable_temporary( _environment, VT_BYTE, "(offset inside temporary storage)");

    char temporaryString[MAX_TEMPORARY_STORAGE]; sprintf(temporaryString, "%s+1", temporary->realName );

    Variable * enter = variable_temporary( _environment, VT_BYTE, "(enter)" );
    Variable * comma = variable_temporary( _environment, VT_BYTE, "(comma)" );
    Variable * size = variable_temporary( _environment, VT_BYTE, "(size max)" );
    Variable * pressed = variable_temporary( _environment, VT_BYTE, "(key pressed?)");
    Variable * key = variable_temporary( _environment, VT_BYTE, "(key pressed)");

    cpu_store_8bit( _environment, comma->realName, ',' );
    cpu_store_8bit( _environment, enter->realName, 13 );
    cpu_store_8bit( _environment, offset->realName, 0 );
    cpu_store_8bit( _environment, size->realName, 254 );

    cpu_label( _environment, repeatLabel );

    c64_inkey( _environment, pressed->realName, key->realName );

    cpu_bveq( _environment, pressed->realName, repeatLabel );
    cpu_bveq( _environment, key->realName, repeatLabel );

    cpu_compare_8bit( _environment, key->realName, comma->realName, pressed->realName, 1 );

    cpu_bvneq( _environment, pressed->realName, finishedLabel );

    cpu_compare_8bit( _environment, key->realName, enter->realName, pressed->realName, 1 );

    cpu_bvneq( _environment, pressed->realName, finishedLabel );

    cpu_move_8bit_indirect_with_offset2( _environment, key->realName, temporaryString, offset->realName );

    cpu_inc( _environment, offset->realName );

    cpu_compare_8bit( _environment, offset->realName, size->realName, pressed->realName, 1 );

    cpu_bveq( _environment, pressed->realName, repeatLabel );

    cpu_label( _environment, finishedLabel );

    cpu_move_8bit( _environment, offset->realName, temporary->realName );

    switch( VT_BITWIDTH( result->type ) ) {
        case 8:
        case 16:
        case 32:
            variable_move( _environment, variable_string_val( _environment, temporary->name )->name, result->name );
            break;
        case 0:
            switch( result->type ) {
                case VT_STRING:
                    variable_move_naked( _environment, temporary->name, result->name );
                    break;
                default:
                    CRITICAL_INPUT_UNSUPPORTED( _variable, DATATYPE_AS_STRING[result->type] );        
            }
    }

}
