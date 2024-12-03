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

/* <usermanual>
@keyword FILL (instruction)

@english

The ''FILL'' command allows you to fill the screen with a particular character.

@italian

Il comando ''FILL'' permette di riempire lo schermo con un carattere specifico.

@syntax FILL x,y,w,h,char,color

@example FILL 0, 0, COLUMNS / 2, ROWS / 2, ASC('A'), RED

@target all
</usermanual> */
void fill( Environment * _environment, char * _x, char * _y, char * _w, char * _h, char * _char, char * _color ) {

    MAKE_LABEL

    char topLabel[MAX_TEMPORARY_STORAGE]; sprintf( topLabel, "%stop", label );
    char lineLabel[MAX_TEMPORARY_STORAGE]; sprintf( lineLabel, "%sline", label );
    char edgeLabel[MAX_TEMPORARY_STORAGE]; sprintf( edgeLabel, "%sedge", label );
    char bottomLabel[MAX_TEMPORARY_STORAGE]; sprintf( bottomLabel, "%sbottom", label );

    Variable * x = variable_retrieve_or_define( _environment, _x, VT_BYTE, 0 );
    Variable * y = variable_retrieve_or_define( _environment, _y, VT_BYTE, 0 );
    Variable * w = variable_retrieve_or_define( _environment, _w, VT_BYTE, 0 );
    Variable * h = variable_retrieve_or_define( _environment, _h, VT_BYTE, 0 );
    Variable * c = variable_retrieve_or_define( _environment, _color, VT_COLOR, 0 );
    Variable * ch = variable_string_chr(_environment, variable_retrieve_or_define( _environment, _char, VT_BYTE, 0 )->name );

    Variable * i = variable_temporary( _environment, VT_BYTE, "(i)" );
    Variable * j = variable_temporary( _environment, VT_BYTE, "(j)" );

    pen( _environment, c->name );

    locate( _environment, x->name, y->name );
    variable_move( _environment, w->name, i->name );
    cpu_label( _environment, topLabel );
        print( _environment, ch->name, 0, 0 );
        variable_decrement( _environment, i->name );
        variable_compare_and_branch_const( _environment, i->name, 0, topLabel, 0 );
    print( _environment, NULL, 1, 0 );

    variable_move( _environment, h->name, j->name );
    variable_decrement( _environment, j->name );
    locate( _environment, x->name, NULL );
    cpu_label( _environment, lineLabel );
        variable_move( _environment, w->name, i->name );
        cpu_label( _environment, edgeLabel );
            print( _environment, ch->name, 0, 0 );
            variable_decrement( _environment, i->name );
            variable_compare_and_branch_const( _environment, i->name, 0, edgeLabel, 0 );
            print( _environment, NULL, 1, 0 );
        variable_decrement( _environment, j->name );
        variable_compare_and_branch_const( _environment, j->name, 0, lineLabel, 0 );

    locate( _environment, x->name, NULL );
    variable_move( _environment, w->name, i->name );
    cpu_label( _environment, bottomLabel );
        print( _environment, ch->name, 0, 0 );
        variable_decrement( _environment, i->name );
        variable_compare_and_branch_const( _environment, i->name, 0, bottomLabel, 0 );

    // The next two parameters specify the location of the top left corner of the frame: <zl> = line 
    // (value range 0 to 23) and <sp> = column (value range 0 to 38). 
    // The following two determine its size: <bt> = width (value range 2 to 40) and <ho> = height (value range 2 to 25). If one of these values ​​is exceeded or undershot, the interpreter reports a BAD MODE ERROR. A width or height of 1 is still possible, but is automatically increased to 2 because otherwise no box can be created. A width or height of 2 omits the edges and only outputs the corners. The last parameter (<f>) defines the color of the frames (value range: 0..15).

}



