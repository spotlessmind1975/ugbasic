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

/**
 * @brief Emit ASM code for <b>POINT AT ([int]x,[int]x)</b>
 * 
 * This function outputs a code that draws a pixel on the screen in bitmap
 * mode on coordinates given explicitly and directly as integers. To do 
 * this, it calculates both the position in memory where it will draw and 
 * the offset within the byte, storing this information in the following 
 * special variables:
 * 
 * @pre Bitmap must be enabled at least once with instruction <b>BITMAP ENABLE</b>.
 * 
 * @param _environment Current calling environment
 * @param _x Abscissa of the point to draw
 * @param _y Ordinate of the point
 * @throw EXIT_FAILURE "CRITICAL: POINT AT (xxx,xxx) needs BITMAP ENABLE"
 */
/* <usermanual>
@keyword POINT AT

@target zx
</usermanual> */
void point_at( Environment * _environment, int _x, int _y ) {

    outline2("; POINT AT (%d,%d)", _x, _y);

    Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );
    Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );

    variable_store( _environment, x->name, _x );
    variable_store( _environment, y->name, _y );

    point_at_vars( _environment, x->name, y->name );

}

/**
 * @brief Emit ASM code for <b>POINT AT ([int]x,[int]x)</b>
 * 
 * This function outputs a code that draws a pixel on the screen in bitmap
 * mode on coordinates given explicitly and directly as integers. To do 
 * this, it calculates both the position in memory where it will draw and 
 * the offset within the byte, storing this information in the following 
 * special variables:
 * 
 * * `pen_address` - offset in memory that refers to the pixel to be modified
 * 
 * @pre Bitmap must be enabled at least once with instruction <b>BITMAP ENABLE</b>.
 * 
 * @param _environment Current calling environment
 * @param _x Expression with the abscissa of the point to draw
 * @param _y Expression with the ordinate of the point
 * @throw EXIT_FAILURE "CRITICAL: POINT AT (xxx,xxx) needs BITMAP ENABLE"
 */
void point_at_vars( Environment * _environment, char * _x, char * _y ) {

    MAKE_LABEL

    deploy( zxvars, src_hw_zx_vars_asm);
    deploy( plot, src_hw_zx_plot_asm );

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );

    outline1("LD A, (%s+1)", x->realName );
    outline0("CP 0");
    outline1("JR NZ, %s", label );
    outline1("LD A, (%s)", x->realName );
    outline0("LD H, A");
    outline1("LD A, (%s)", y->realName );
    outline0("LD L, A");
    outline0("CALL PLOT");
    outhead1("%s:", label );

}
