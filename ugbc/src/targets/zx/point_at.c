/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

    outline2("; POINT AT (%s,%s)", _x, _y);

    Variable * y = variable_retrieve( _environment, _y );
    Variable * x = variable_retrieve( _environment, _x );
    Variable * clipX1 = variable_retrieve( _environment, "CLIPX1" );
    Variable * clipX2 = variable_retrieve( _environment, "CLIPX2" );
    Variable * clipY1 = variable_retrieve( _environment, "CLIPY1" );
    Variable * clipY2 = variable_retrieve( _environment, "CLIPY2" );

    outline1( "LD A,(%s)", clipX1->realName );
    outline0( "LD B, A" );
    outline1( "LD A,(%s)", clipX2->realName );
    outline0( "LD D, A" );
    outline1( "LD A,(%s)", x->realName );
    outline0( "CMP B" );
    outline1( "JP C, %sclipped", label );
    outline0( "CMP D" );
    outline1( "JR Z, %snoclipped", label );
    outline1( "JP NC, %sclipped", label );
    outhead1( "%snoclipped:", label );
    outline1( "LD A,(%s)", clipY1->realName );
    outline0( "LD B, A" );
    outline1( "LD A,(%s)", clipY2->realName );
    outline0( "LD D, A" );
    outline1( "LD A,(%s)", y->realName );
    outline0( "CMP B" );
    outline1( "JP C, %sclipped", label );
    outline0( "CMP D" );
    outline1( "JR Z, %snoclipped2", label );
    outline1( "JP NC, %sclipped", label );
    outhead1( "%snoclipped2:", label );

    outline1( "LD A,(%s)", x->realName );
    outline0( "AND $7");
    outline0( "LD B, A");
    outline0( "LD A, $8");
    outline0( "SUB B");
    outline0( "LD B, A");
    outline0( "LD E, 1");
    outhead1( "%s:", label );
    outline0( "DEC B");
    outline1( "JR Z,%s_2", label);
    outline0( "SLA E");
    outline1( "JMP %s", label);
    outhead1( "%s_2:", label );

    outline1( "LD A,(%s)", y->realName );
    outline0( "LD B, A");
    outline1( "LD A,(%s)", x->realName );
    outline0( "LD C, A");

    outline0( "LD A,B");
    outline0( "AND %00000111");
    outline0( "OR %01000000");
    outline0( "LD H,A");
    outline0( "LD A,B");
    outline0( "RRA");
    outline0( "RRA");
    outline0( "RRA");
    outline0( "AND %00011000");
    outline0( "OR H");
    outline0( "LD H,A");
    outline0( "LD A,B");
    outline0( "RLA");
    outline0( "RLA");
    outline0( "AND %11100000");
    outline0( "LD L,A");
    outline0( "LD A,C");
    outline0( "RRA");
    outline0( "RRA");
    outline0( "RRA");
    outline0( "AND %00011111");
    outline0( "OR L");
    outline0( "LD L,A");

    outline0( "LD A,(HL)");
    outline0( "OR E");
    outline0( "LD (HL),A");

    outline1("LD HL,(%s)", x->realName );
    outline0("SRA H" );
    outline0("RR L" );
    outline0("SRA H" );
    outline0("RR L" );
    outline0("SRA H" );
    outline0("RR L" );
    outline0("LD DE,HL");

    outline1("LD HL,(%s)", y->realName );
    outline0("SLA L" );
    outline0("RL H" );
    outline0("SLA L" );
    outline0("RL H" );
    outline0("ADD HL,DE" );
    outline0("LD DE,(COLORMAPADDRESS)");
    outline0("ADD HL,DE" );
    outline0("LD A,(_PEN)" );
    outline0("LD B,A" );
    outline0("LD A,(HL)" );
    outline0("AND $f8" );
    outline0("OR A,B" );
    outline0("LD (HL),A" );

    outhead1( "%sclipped:", label );

}
