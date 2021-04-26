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
 * @brief Emit ASM implementation for <b>COLORMAP AT [int]x</b> instruction
 * 
 * This function allows you to set the starting address, in memory, for the 
 * colormap and it is the version that is used when the memory is given as a
 * direct number (i.e.: $2000). The input parameter is decoded and declined 
 * according to the hardware limits. So it is not said that exactly the 
 * given address is set.
 * 
 * On some machine calling this instruction will define the special variable:
 * 
 *  * `colormap_address` (VT_ADDRESS) - the starting address of colormap memory
 * 
 * @param _environment Current calling environment
 * @param _address Address to use
 */
/* <usermanual>
@keyword COLORMAP AT

@target zx
</usermanual> */
void colormap_at( Environment * _environment, int _address ) {

    outline1("; COLORMAP AT $%4.4x", _address);

    // Let's define the special variable and fill up with the value.
    Variable * colormap_address = variable_define( _environment, "colormap_address", VT_ADDRESS, _address );

    // TODO: colormap_address must be retrieved by a zx_get_colormap_address()

    variable_store( _environment, colormap_address->name, 0x5800 );

}

/**
 * @brief Emit ASM implementation for <b>COLORMAP AT [expression]</b> instruction
 * 
 * This function allows you to set the starting address, in memory, for the 
 * colormap and it is the version that is used when the memory is given as an
 * expression. The input parameter is decoded and declined according to the hardware
 * limits. So it is not said that exactly the given address is set.
 * 
 * On some machine calling this instruction will define the special variable:
 * 
 *  * `colormap_address` (VT_ADDRESS) - the starting address of colormap memory
 * 
 * @param _environment Current calling environment
 * @param _address Address to use
 */
void colormap_at_var( Environment * _environment, char * _address ) {

    outline1("; COLORMAP AT %s", _address);

    // Let's define the special variable and fill up with the value.
    // TODO: colormap_address must be retrieved by a zx_get_colormap_address()
    Variable * colormap_address = variable_define( _environment, "colormap_address", VT_ADDRESS, 0x5800 );
    Variable * address = variable_retrieve( _environment, _address );

    // variable_store( _environment, colormap_address->name, ( ( ( _address >> 10 ) & 0x0f ) * 0x0400 ) );

}

/**
 * @brief Emit ASM implementation for <b>COLORMAP CLEAR WITH [int]x ON [int]x</b> instruction
 * 
 * This function is called when you want to generate code that erases the entire color map, 
 * using a foreground and a background color. This function is useful if the color indices 
 * are given as integers.
 * 
 * @pre Bitmap must be enabled at least once with instruction <b>BITMAP ENABLE</b>.
 * 
 * @param _environment Current calling environment
 * @param _foreground Index of foreground color
 * @param _background Index of background color
 * @throw EXIT_FAILURE "COLORMAP CLEAR WITH xxx ON xxx needs BITMAP ENABLED"
 */
void colormap_clear_with( Environment * _environment, int _foreground, int _background ) {

    outline2("; COLORMAP CLEAR WITH $%2.2x AND $%2.2x", _foreground, _background );

    Variable * colormap_address = variable_retrieve( _environment, "colormap_address" );
    if ( ! colormap_address ) {
        CRITICAL( "COLORMAP CLEAR WITH xxx ON xxx needs BITMAP ENABLED");
    }

    Variable * value = variable_temporary( _environment, VT_BYTE, "(background + foreground)" );

    variable_store( _environment, value->name, ( ( _background & 0x07 ) << 3 ) | ( _foreground & 0x07 ) );

    z80_fill( _environment, colormap_address->realName, "3", value->realName );

    variable_reset( _environment );

}

/**
 * @brief Emit ASM implementation for <b>COLORMAP CLEAR WITH [expression] ON [expression]</b> instruction
 * 
 * This function is called when you want to generate code that erases the entire color map, 
 * using a foreground and a background color. This function is useful if the color indices 
 * are given as integers.
 * 
 * @pre Bitmap must be enabled at least once with instruction <b>BITMAP ENABLE</b>.
 * 
 * @param _environment Current calling environment
 * @param _foreground Expression for index of foreground color
 * @param _background Expression for index of background color
 * @throw EXIT_FAILURE "CRITICAL: COLORMAP CLEAR WITH xxx AND xxx needs BITMAP ENABLED"
 */
void colormap_clear_with_vars( Environment * _environment, char * _foreground, char * _background ) {

    outline2("; COLORMAP CLEAR WITH %s AND %s", _foreground, _background );

    Variable * colormap_address = variable_define( _environment, "colormap_address", VT_ADDRESS, 0x0400 );
    if ( ! colormap_address ) {
        CRITICAL( "COLORMAP CLEAR WITH xxx ON xxx needs BITMAP ENABLED");
    }

    Variable * foreground = variable_retrieve( _environment, _foreground );
    if ( ! foreground ) {
        // TODO: in general, missing variable is not an internal error but citing a variable without defining it.
        CRITICAL( "Internal error for COLORMAP CLEAR WITH xxx ON xxx");
    }

    Variable * background = variable_retrieve( _environment, _background );
    if ( ! background ) {
        CRITICAL( "Internal error for COLORMAP CLEAR WITH xxx ON xxx");
    }

    Variable * pattern = variable_temporary( _environment, VT_BYTE, "(pattern)" );
    
    outline1("LD A, (%s)", background->realName );
    outline0("RL A" );
    outline0("RL A" );
    outline0("RL A" );
    outline0("LD B, A" );
    outline1("LD A, (%s)", foreground->realName );
    outline0("AND $07" );
    outline0("OR B" );
    outline1("LD (%s), A", pattern->realName );

    z80_fill( _environment, colormap_address->realName, "3", pattern->realName );

    variable_reset( _environment );

}

/**
 * @brief Emit ASM implementation for <b>COLORMAP CLEAR</b> instruction
 * 
 * This function is called when you want to generate code that erases the entire color map, 
 * using the default foreground and background color.
 * 
 * @pre Bitmap must be enabled at least once with instruction <b>BITMAP ENABLE</b>.
 * 
 * @param _environment Current calling environment
 * @throw EXIT_FAILURE "CRITICAL: COLORMAP CLEAR WITH xxx AND xxx needs BITMAP ENABLED"
 */
void colormap_clear( Environment * _environment ) {

    outline0("; COLORMAP CLEAR WITH BLACK ON WHIKE");

    // Equals to: "COLORMAP CLEAR WITH 0 AND 1"
    colormap_clear_with( _environment, COLOR_WHITE, COLOR_BLACK );

}