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
 * @brief Emit ASM implementation for <b>TEXT ENABLE</b> instruction
 * 
 * This function can be called to emit the code to enable text mode
 * on the target machine.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword TEXT ENABLE

@english
Enable the text mode.

@italian
Abilita la modalità testuale.

@syntax TEXT ENABLE

@example TEXT ENABLE

@target c64
</usermanual> */
void text_enable( Environment * _environment ) {
    
    bitmap_disable( _environment );

}

/**
 * @brief Emit ASM implementation for <b>TEXT DISABLE</b> instruction
 * 
 * This function can be called to emit the code to disable text mode
 * on the target machine.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword TEXT DISABLE

@english
Disable the text mode.

@italian
Disabilita la modalità testuale.

@syntax TEXT ENABLE

@example TEXT ENABLE

@target c64
</usermanual> */
void text_disable( Environment * _environment ) {
    
    bitmap_enable( _environment );
    
}

/*

text screen
	- TEXT ENABLE
	- SCREEN WIDTH
	- SCREEN HEIGHT

text window
	- 0 <= index <= WINDOW COUNT
	- 0 <= x <= SCREEN WIDTH = XWIND(index)
	- 0 <= y <= SCREEN HEIGHT = YWIND(index)
	- 1 <= width <= (SCREEN WIDTH - x) = WWIND(index)
	- 1 <= height <= (SCREEN HEIGHT - x) = HWIND(index)

by default:
text window 0 <-> text screen

windowX_x:	.res 1
windowX_y:	.res 1
windowX_w:	.res 1
windowX_h:	.res 1
windowX_cx:	.res 1
windowX_cy:	.res 1

*/

void setup_text_variables( Environment * _environment ) {

    variable_define( _environment, "windowX", VT_BYTE, 0 );
    variable_define( _environment, "windowY", VT_BYTE, 0 );                
    variable_define( _environment, "windowX2", VT_BYTE, (TEXT_COLUMNS_COUNT-1) );
    variable_define( _environment, "windowY2", VT_BYTE, (TEXT_ROWS_COUNT-1) );                
    variable_define( _environment, "windowCX", VT_BYTE, 0 );
    variable_define( _environment, "windowCY", VT_BYTE, 0 );
    variable_define( _environment, "windowPE", VT_COLOR, COLOR_BLACK );
    variable_define( _environment, "windowPA", VT_COLOR, COLOR_WHITE );
    variable_define( _environment, "windowE", VT_BYTE, 0 );
    variable_define( _environment, "windowS", VT_BYTE, 0 );
    variable_define( _environment, "windowW", VT_BYTE, 0 );
    variable_define( _environment, "windowT", VT_BYTE, 4 );
    variable_define( _environment, "windowWW", VT_BYTE, WW_PEN | WW_PAPER );
    variable_define( _environment, "TAB", VT_STRING, 0 );
    variable_store_string( _environment, "TAB", "\t");
    variable_define( _environment, "windowMX", VT_BYTE, 0 );
    variable_define( _environment, "windowMY", VT_BYTE, 0 );                

}

void text_locate( Environment * _environment, char * _x, char * _y ) {

    if ( _x ) {
        Variable * windowCX = variable_retrieve( _environment, "windowCX" );
        Variable * x = variable_retrieve_or_define( _environment, _x, VT_BYTE, 0 );
        variable_move( _environment, x->name, windowCX->name );
    }

    if ( _y ) {
        Variable * windowCY = variable_retrieve( _environment, "windowCY" );
        Variable * y = variable_retrieve_or_define( _environment, _y, VT_BYTE, 0 );
        variable_move( _environment, y->name, windowCY->name );
    }

}

void text_cmove_direct( Environment * _environment, int _dx, int _dy ) {

    if ( _dx ) {
        Variable * windowCX = variable_retrieve( _environment, "windowCX" );
        Variable * windowX = variable_retrieve( _environment, "windowX" );
        Variable * windowX2 = variable_retrieve( _environment, "windowX2" );
        Variable * dx = variable_temporary( _environment, VT_SBYTE, "(cmove hz)" );
        variable_store( _environment, dx->name, _dx );
        add_complex( _environment, windowCX->name, dx->name, windowX->name, windowX2->name );
    }

    if ( _dy ) {
        Variable * windowCY = variable_retrieve( _environment, "windowCY" );
        Variable * windowY = variable_retrieve( _environment, "windowY" );
        Variable * windowY2 = variable_retrieve( _environment, "windowY2" );
        Variable * dy = variable_temporary( _environment, VT_SBYTE, "(cmove vt)" );
        variable_store( _environment, dy->name, _dy );
        add_complex( _environment, windowCY->name, dy->name, windowY->name, windowY2->name );
    }

}

void text_cmove( Environment * _environment, char * _dx, char * _dy ) {

    if ( _dx ) {
        Variable * windowCX = variable_retrieve( _environment, "windowCX" );
        Variable * windowX = variable_retrieve( _environment, "windowX" );
        Variable * windowX2 = variable_retrieve( _environment, "windowX2" );
        Variable * dx = variable_retrieve_or_define( _environment, _dx, VT_SBYTE, 0 );
        add_complex( _environment, windowCX->name, dx->name, windowX->name, windowX2->name );
    }

    if ( _dy ) {
        Variable * windowCY = variable_retrieve( _environment, "windowCY" );
        Variable * windowY = variable_retrieve( _environment, "windowY" );
        Variable * windowY2 = variable_retrieve( _environment, "windowY2" );
        Variable * dy = variable_retrieve_or_define( _environment, _dy, VT_BYTE, 0 );
        add_complex( _environment, windowCY->name, dy->name, windowY->name, windowY2->name );
    }

}

void text_home( Environment * _environment ) {

    Variable * x = variable_retrieve( _environment, "windowCX" );
    Variable * y = variable_retrieve( _environment, "windowCY" );

    variable_store( _environment, x->name, 0 );
    variable_store( _environment, y->name, 0 );

}

void text_text( Environment * _environment, char * _text ) {

    Variable * text = variable_retrieve( _environment, _text );
    Variable * x = variable_retrieve( _environment, "windowCX" );
    Variable * y = variable_retrieve( _environment, "windowCY" );
    Variable * encoding = variable_retrieve( _environment, "windowE" );
    Variable * pen = variable_retrieve( _environment, "windowPE" );
    Variable * paper = variable_retrieve( _environment, "windowPA" );
    Variable * ww = variable_retrieve( _environment, "windowWW" );
    Variable * tab = variable_retrieve( _environment, "windowT" );

    text_encoded_at( _environment, x->name, y->name, text->name, encoding->name, pen->name, paper->name, ww->name, tab->name );
    
}

Variable * text_get_cmove( Environment * _environment, char * _x, char * _y ) {
    
    Variable * x = variable_retrieve_or_define( _environment, _x, VT_BYTE, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _x, VT_BYTE, 0 );

    Variable * result = variable_temporary( _environment, VT_STRING, 0 );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x3  " );
    char stringAddress[MAX_TEMPORARY_STORAGE]; sprintf( stringAddress, "%s+1", result->realName );

    variable_store_string(_environment, result->name, resultString );

    cpu_move_8bit_indirect_with_offset(_environment, x->realName, stringAddress, 1 );
    cpu_move_8bit_indirect_with_offset(_environment, y->realName, stringAddress, 2 );
        
    return result;

}

Variable * text_get_cmove_direct( Environment * _environment, int _x, int _y ) {
    
    Variable * result = variable_temporary( _environment, VT_STRING, 0 );

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, "\x3  " );
    char stringAddress[MAX_TEMPORARY_STORAGE]; sprintf( stringAddress, "%s+1", result->realName );

    variable_store_string(_environment, result->name, resultString );

    cpu_store_8bit_indirect_with_offset(_environment, stringAddress, (_x & 0xff), 1 );
    cpu_store_8bit_indirect_with_offset(_environment, stringAddress, (_y & 0xff), 2 );
        
    return result;

}


Variable * text_get_tab( Environment * _environment ) {
    
    Variable * tab = variable_retrieve( _environment, "TAB" );

    return tab;

}

void text_newline( Environment * _environment ) {

    MAKE_LABEL

    Variable * x = variable_retrieve( _environment, "windowCX" );
    Variable * y = variable_retrieve( _environment, "windowCY" );
    Variable * y2 = variable_retrieve( _environment, "windowY2" );

    cpu_store_8bit( _environment, x->realName, 0 );    

    Variable * result = variable_compare( _environment, y->name, y2->name );    

    char endLabel[MAX_TEMPORARY_STORAGE]; sprintf(endLabel, "%send", label);
    char scrollLabel[MAX_TEMPORARY_STORAGE]; sprintf(scrollLabel, "%sscroll", label);

    cpu_bvneq( _environment, result->realName, scrollLabel );

    cpu_inc( _environment, y->realName );

    cpu_jump( _environment, endLabel );

    cpu_label( _environment, scrollLabel );

    text_vscroll_screen( _environment, -1 );

    cpu_label( _environment, endLabel );

}

void text_tab( Environment * _environment ) {

    Variable * tab = variable_retrieve( _environment, "TAB" );

    text_text( _environment, tab->name );
    
}

void text_set_tab( Environment * _environment, char * _new_tab ) {

    Variable * tab = variable_retrieve( _environment, "windowT" );
    Variable * new_tab = variable_retrieve_or_define( _environment, _new_tab, VT_BYTE, 4 );

    variable_move( _environment, new_tab->name, tab->name );
    
}

void text_at( Environment * _environment, char * _x, char * _y, char * _text ) {

    text_locate( _environment, _x, _y );

    text_text( _environment, _text );
    
}

void text_pen( Environment * _environment, char * _color ) {

    Variable * pen = variable_retrieve( _environment, "windowPE" );
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_BLACK );

    variable_move( _environment, color->name, pen->name );
    
}

void use_ansi( Environment * _environment ) {

    setup_text_variables( _environment );

    Variable * encoding = variable_retrieve( _environment, "windowE" );

    variable_store( _environment, encoding->name, 1 );
    
}

void use_specific( Environment * _environment ) {

    setup_text_variables( _environment );

    Variable * encoding = variable_retrieve( _environment, "windowE" );

    variable_store( _environment, encoding->name, 0 );
    
}

void text_inverse( Environment * _environment, int _value ) {

    setup_text_variables( _environment );

    Variable * inverse = variable_retrieve( _environment, "windowS" );

    variable_store( _environment, inverse->name, _value );
    
}

void text_shade( Environment * _environment, int _value ) {

    setup_text_variables( _environment );

    Variable * shade = variable_retrieve( _environment, "windowS" );

    variable_store( _environment, shade->name, _value );
    
}

void text_under( Environment * _environment, int _value ) {

    setup_text_variables( _environment );

    Variable * under = variable_retrieve( _environment, "windowS" );

    variable_store( _environment, under->name, _value );
    
}

void text_writing( Environment * _environment, char * _mode, char * _parts ) {

    setup_text_variables( _environment );

    Variable * ww = variable_retrieve( _environment, "windowWW" );
    Variable * mode = variable_retrieve_or_define( _environment, _mode, VT_BYTE, WRITING_REPLACE );
    Variable * parts = variable_retrieve_or_define( _environment, _parts, VT_BYTE, WRITING_NORMAL );

    variable_move( _environment, mode->name, ww->name );
    cpu_math_mul2_const_8bit( _environment, ww->realName, 4  );
    cpu_math_add_8bit( _environment, ww->realName, parts->realName, ww->realName );
    
}

void text_center( Environment * _environment, char * _string ) {

    setup_text_variables( _environment );

    Variable * x = variable_retrieve( _environment, "windowX" );
    Variable * y = variable_retrieve( _environment, "windowCY" );
    Variable * x2 = variable_retrieve( _environment, "windowX2" );
    Variable * y2 = variable_retrieve( _environment, "windowY2" );
    Variable * string = variable_retrieve( _environment, _string );

    Variable * w = variable_sub( _environment, variable_sub( _environment, x2->name, x->name )->name, variable_string_len( _environment, _string)->name );
    variable_div2_const( _environment, w->name, 1 );

    text_at( _environment, w->name, y->name, string->name );

}

Variable * text_get_xcurs( Environment * _environment ) {
    
    return variable_retrieve( _environment, "windowCX");

}

Variable * text_get_ycurs( Environment * _environment ) {
    
    return variable_retrieve( _environment, "windowCY");

}

void text_memorize( Environment * _environment ) {

    setup_text_variables( _environment );

    Variable * x = variable_retrieve( _environment, "windowCX" );
    Variable * y = variable_retrieve( _environment, "windowCY" );
    Variable * mx = variable_retrieve( _environment, "windowMX" );
    Variable * my = variable_retrieve( _environment, "windowMY" );

    variable_move_naked( _environment, x->name, mx->name );
    variable_move_naked( _environment, y->name, my->name );

}

void text_remember( Environment * _environment ) {

    outline0("; text_remember");
    
    setup_text_variables( _environment );

    Variable * x = variable_retrieve( _environment, "windowCX" );
    Variable * y = variable_retrieve( _environment, "windowCY" );
    Variable * mx = variable_retrieve( _environment, "windowMX" );
    Variable * my = variable_retrieve( _environment, "windowMY" );

    variable_move_naked( _environment, mx->name, x->name );
    variable_move_naked( _environment, my->name, y->name );
    variable_store( _environment, mx->name, 0 );
    variable_store( _environment, my->name, 0 );

}
