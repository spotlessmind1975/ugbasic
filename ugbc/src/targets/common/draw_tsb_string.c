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

void draw_tsb_string( Environment * _environment, char * _string, char * _x, char * _y, char * _c, int _preserve_color  ) {

    deploy_begin( draw_tsb_string );

        MAKE_LABEL

        char drawStringLabel[MAX_TEMPORARY_STORAGE]; sprintf( drawStringLabel, "%sds", label );

        char move5CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( move5CommandLabel, "%smv5", label );
        char doneCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( doneCommandLabel, "%sdone", label );
        char upCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( upCommandLabel, "%sup", label );
        char downCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( downCommandLabel, "%sdown", label );
        char upDCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( upDCommandLabel, "%supd", label );
        char downDCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( downDCommandLabel, "%sdownd", label );
        char leftCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( leftCommandLabel, "%sleft", label );
        char rightCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( rightCommandLabel, "%sright", label );
        char leftDCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( leftDCommandLabel, "%sleftd", label );
        char rightDCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( rightDCommandLabel, "%srightd", label );
        char drawCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( drawCommandLabel, "%sdraw", label );
        char angleCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( angleCommandLabel, "%sangle", label );
        char angles2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( angles2CommandLabel, "%sangles2", label );
        char angle45CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( angle45CommandLabel, "%sa45", label );
        char angle135CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( angle135CommandLabel, "%sa135", label );
        char angle225CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( angle225CommandLabel, "%sa225", label );
        char angle315CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( angle315CommandLabel, "%sa315", label );
        char angleDCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( angleDCommandLabel, "%sangled", label );

        Variable * drawUCommandLetter = variable_retrieve( _environment, "DRAWUCOMMAND" );
        Variable * drawDCommandLetter = variable_retrieve( _environment, "DRAWDCOMMAND" );
        Variable * drawLCommandLetter = variable_retrieve( _environment, "DRAWLCOMMAND" );
        Variable * drawRCommandLetter = variable_retrieve( _environment, "DRAWRCOMMAND" );
        Variable * drawECommandLetter = variable_retrieve( _environment, "DRAWECOMMAND" );
        Variable * drawFCommandLetter = variable_retrieve( _environment, "DRAWFCOMMAND" );
        Variable * drawGCommandLetter = variable_retrieve( _environment, "DRAWGCOMMAND" );
        Variable * drawHCommandLetter = variable_retrieve( _environment, "DRAWHCOMMAND" );
        Variable * drawUDCommandLetter = variable_retrieve( _environment, "DRAWUDCOMMAND" );
        Variable * drawDDCommandLetter = variable_retrieve( _environment, "DRAWDDCOMMAND" );
        Variable * drawLDCommandLetter = variable_retrieve( _environment, "DRAWLDCOMMAND" );
        Variable * drawRDCommandLetter = variable_retrieve( _environment, "DRAWRDCOMMAND" );
        Variable * drawEDCommandLetter = variable_retrieve( _environment, "DRAWEDCOMMAND" );
        Variable * drawFDCommandLetter = variable_retrieve( _environment, "DRAWFDCOMMAND" );
        Variable * drawGDCommandLetter = variable_retrieve( _environment, "DRAWGDCOMMAND" );
        Variable * drawHDCommandLetter = variable_retrieve( _environment, "DRAWHDCOMMAND" );

        // Move to the start of routine
        cpu_jump( _environment, drawStringLabel );

        // ----------------------------[ SUBROUTINE: READ PARAMETER ]

        // string -> (address, size)
        Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)" );
        Variable * size = variable_temporary( _environment, VT_BYTE, "(address)" );

        // xxx, -> (paddress, psize)
        Variable * paddress = variable_temporary( _environment, VT_ADDRESS, "(address)" );
        Variable * psize = variable_temporary( _environment, VT_BYTE, "(size)" );

        // ------------------------------------ STARTING ROUTINE
        cpu_label( _environment, drawStringLabel );

        // String with the drawing commands,
        Variable * string = variable_define( _environment, "drawstring__string", VT_DSTRING, 0 );

        // Color to be used
        Variable * color = variable_define( _environment, "drawstring__color", VT_COLOR, 0 );

        // Starting position
        Variable * startingX = variable_define( _environment, "drawstring__x", VT_POSITION, 0 );
        Variable * startingY = variable_define( _environment, "drawstring__y", VT_POSITION, 0 );

        // Letter with command
        Variable * command = variable_temporary( _environment, VT_BYTE, "(command)" );

        // Next coordinates to move to.
        Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
        Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );

        // Next delta coordinates.
        Variable * dx = variable_temporary( _environment, VT_POSITION, "(dx)" );
        Variable * dy = variable_temporary( _environment, VT_POSITION, "(dy)" );

        // Next delta coordinates scaled
        Variable * ds = variable_temporary( _environment, VT_POSITION, "(ds)" );

        // Scale.
        Variable * scale = variable_retrieve( _environment, "DRAWSCALE" );

        // Is blank required?
        Variable * blank = variable_temporary( _environment, VT_BYTE, "(blank)" );

        cpu_dsdescriptor( _environment, string->realName, address->realName, size->realName );

        gr_locate( _environment, startingX->name, startingY->name );
        // Take starting x and y
        variable_move( _environment, startingX->name, x->name );
        variable_move( _environment, startingY->name, y->name );

        // ------------------------------------ FETCH AND DECODE LOOP
        begin_do_loop( _environment );

            variable_store( _environment, blank->name, 0xff );

            // Are drawing commands ended? Exit fetch and decode loop.
            cpu_compare_and_branch_8bit_const( _environment, size->realName, 0, label, 1 );

            // Retrieve command letter.
            cpu_move_8bit_indirect2( _environment, address->realName, command->realName );
            cpu_dec( _environment, size->realName );
            cpu_inc_16bit( _environment, address->realName );

            // Is it '3' ? -> LEFT
            cpu_compare_and_branch_8bit( _environment, command->realName, drawLCommandLetter->realName, leftCommandLabel, 1 );

            // Is it '0' ? -> RIGHT
            cpu_compare_and_branch_8bit( _environment, command->realName, drawRCommandLetter->realName, rightCommandLabel, 1 );

            // Is it '1' ? -> UP
            cpu_compare_and_branch_8bit( _environment, command->realName, drawUCommandLetter->realName, upCommandLabel, 1 );

            // Is it '2' ? -> DOWN
            cpu_compare_and_branch_8bit( _environment, command->realName, drawDCommandLetter->realName, downCommandLabel, 1 );

            // Is it '8' ? -> LEFT & DRAW
            cpu_compare_and_branch_8bit( _environment, command->realName, drawLDCommandLetter->realName, leftDCommandLabel, 1 );

            // Is it '5' ? -> RIGHT & DRAW
            cpu_compare_and_branch_8bit( _environment, command->realName, drawRDCommandLetter->realName, rightDCommandLabel, 1 );

            // Is it '6' ? -> UP & DRAW
            cpu_compare_and_branch_8bit( _environment, command->realName, drawUDCommandLetter->realName, upDCommandLabel, 1 );

            // Is it '7' ? -> DOWN & DRAW
            cpu_compare_and_branch_8bit( _environment, command->realName, drawDDCommandLetter->realName, downDCommandLabel, 1 );

            // Is it '3*' ? -> 45°
            cpu_compare_and_branch_8bit( _environment, command->realName, drawECommandLetter->realName, angleCommandLabel, 1 );

            // Is it '0*' ? -> 135°
            cpu_compare_and_branch_8bit( _environment, command->realName, drawFCommandLetter->realName, angleCommandLabel, 1 );

            // Is it '1*' ? -> 225°
            cpu_compare_and_branch_8bit( _environment, command->realName, drawGCommandLetter->realName, angleCommandLabel, 1 );

            // Is it '2*' ? -> 315°
            cpu_compare_and_branch_8bit( _environment, command->realName, drawHCommandLetter->realName, angleCommandLabel, 1 );

            // Is it '8*' ? -> 45°
            cpu_compare_and_branch_8bit( _environment, command->realName, drawEDCommandLetter->realName, angleDCommandLabel, 1 );

            // Is it '5*' ? -> 135°
            cpu_compare_and_branch_8bit( _environment, command->realName, drawFDCommandLetter->realName, angleDCommandLabel, 1 );

            // Is it '6*' ? -> 225°
            cpu_compare_and_branch_8bit( _environment, command->realName, drawGDCommandLetter->realName, angleDCommandLabel, 1 );

            // Is it '7*' ? -> 315°
            cpu_compare_and_branch_8bit( _environment, command->realName, drawHDCommandLetter->realName, angleDCommandLabel, 1 );

            // Is it '9' ? -> end
            cpu_compare_and_branch_8bit_const( _environment, command->realName, '9', label, 1 );

            // No command was recognized: silently, move to the next character.
            cpu_jump( _environment, doneCommandLabel );

            // ----------------------------[ UP ]
            cpu_label( _environment, upDCommandLabel );
            variable_store( _environment, blank->name, 0 );
            cpu_label( _environment, upCommandLabel );

            cpu_store_8bit( _environment, dy->realName, 1 );

            variable_move( _environment, origin_resolution_relative_transform_y( _environment, dy->name, 0 )->name, dy->name );
            variable_move( _environment, variable_mul( _environment, dy->name, scale->name )->name, ds->name );

            variable_move( _environment, 
                variable_sub( _environment, y->name, 
                    ds->name
                )->name,
                y->name
                            );
            cpu_jump( _environment, drawCommandLabel );

            // ----------------------------[ DOWN ]
            cpu_label( _environment, downDCommandLabel );
            variable_store( _environment, blank->name, 0 );
            cpu_label( _environment, downCommandLabel );

            cpu_store_8bit( _environment, dy->realName, 1 );

            variable_move( _environment, origin_resolution_relative_transform_y( _environment, dy->name, 0 )->name, dy->name );
            variable_move( _environment, variable_mul( _environment, dy->name, scale->name )->name, ds->name );

            variable_move( _environment, 
                variable_add( _environment, y->name, 
                    ds->name
                )->name,
                y->name
            );
            cpu_jump( _environment, drawCommandLabel );

            // ----------------------------[ LEFT ]
            cpu_label( _environment, leftDCommandLabel );
            variable_store( _environment, blank->name, 0 );
            cpu_label( _environment, leftCommandLabel );

            cpu_store_8bit( _environment, dx->realName, 1 );

            variable_move( _environment, origin_resolution_relative_transform_x( _environment, dx->name, 0 )->name, dx->name );
            variable_move( _environment, variable_mul( _environment, dx->name, scale->name )->name, ds->name );

            variable_move( _environment, 
                variable_sub( _environment, x->name, 
                    ds->name
                )->name,
                x->name
            );
            cpu_jump( _environment, drawCommandLabel );

            // ----------------------------[ RIGHT ]
            cpu_label( _environment, rightDCommandLabel );
            variable_store( _environment, blank->name, 0 );
            cpu_label( _environment, rightCommandLabel );

            cpu_store_8bit( _environment, dx->realName, 1 );

            variable_move( _environment, origin_resolution_relative_transform_x( _environment, dx->name, 0 )->name, dx->name );
            variable_move( _environment, variable_mul( _environment, dx->name, scale->name )->name, ds->name );

            variable_move( _environment, 
                variable_add( _environment, x->name, 
                    ds->name
                )->name,
                x->name
            );
            cpu_jump( _environment, drawCommandLabel );

            // ----------------------------[ ANGLE 45, 135, 225, 315 ]

            cpu_label( _environment, angleDCommandLabel );
            variable_store( _environment, blank->name, 0 );
            cpu_label( _environment, angleCommandLabel );

            cpu_store_8bit( _environment, dx->realName, 1 );
            cpu_store_8bit( _environment, dy->realName, 1 );

            variable_move( _environment, origin_resolution_relative_transform_x( _environment, dx->name, 0 )->name, dx->name );
            variable_move( _environment, variable_mul( _environment, dx->name, scale->name )->name, ds->name );

            cpu_compare_and_branch_8bit( _environment, command->realName, drawFCommandLetter->realName, angle45CommandLabel, 1 );

            cpu_compare_and_branch_8bit( _environment, command->realName, drawGCommandLetter->realName, angle135CommandLabel, 1 );

            cpu_compare_and_branch_8bit( _environment, command->realName, drawECommandLetter->realName, angle225CommandLabel, 1 );

            cpu_compare_and_branch_8bit( _environment, command->realName, drawHCommandLetter->realName, angle315CommandLabel, 1 );

            cpu_label( _environment, angle45CommandLabel );
            variable_move( _environment, 
                variable_add( _environment, x->name, 
                    ds->name
                )->name,
                x->name
            );
            variable_move( _environment, 
                variable_sub( _environment, y->name, 
                    ds->name
                )->name,
                y->name
            );
            cpu_jump( _environment, drawCommandLabel );

            cpu_label( _environment, angle135CommandLabel );
            variable_move( _environment, 
                variable_add( _environment, x->name, 
                    ds->name
                )->name,
                x->name
            );
            variable_move( _environment, 
                variable_add( _environment, y->name, 
                    ds->name
                )->name,
                y->name
            );
            cpu_jump( _environment, drawCommandLabel );

            cpu_label( _environment, angle225CommandLabel );
            variable_move( _environment, 
                variable_sub( _environment, x->name, 
                    ds->name
                )->name,
                x->name
            );
            variable_move( _environment, 
                variable_add( _environment, y->name, 
                    ds->name
                )->name,
                y->name
            );
            cpu_jump( _environment, drawCommandLabel );

            cpu_label( _environment, angle315CommandLabel );
            variable_move( _environment, 
                variable_sub( _environment, x->name, 
                    ds->name
                )->name,
                x->name
            );
            variable_move( _environment, 
                variable_sub( _environment, y->name, 
                    ds->name
                )->name,
                y->name
            );
            cpu_jump( _environment, drawCommandLabel );

            // ----------------------------[ DRAW (or BLANK) ]
            cpu_label( _environment, drawCommandLabel );

            // If blank move has been requested, we avoid to draw anything.
            cpu_compare_and_branch_8bit_const( _environment, blank->realName, 0xff, move5CommandLabel, 1 );

            // Let's draw from the previous position to the current position.
            draw( _environment, 
                origin_resolution_relative_transform_x( _environment, NULL, 0 )->name, 
                origin_resolution_relative_transform_y( _environment, NULL, 0 )->name, 
                x->name, y->name, color->name, _preserve_color );

            // Update current position (this is done also if nothing is drawn!)
            cpu_label( _environment, move5CommandLabel );
            gr_locate( _environment, x->name, y->name );

            // Move to the next character of the drawing commands string.
            // cpu_inc( _environment, size->realName );
            // cpu_dec_16bit( _environment, address->realName );
            cpu_store_16bit( _environment, dx->realName, 0 );
            cpu_store_16bit( _environment, dy->realName, 0 );
            cpu_store_16bit( _environment, ds->realName, 0 );

            // Move to the next character of the drawing commands string.
            cpu_label( _environment, doneCommandLabel );

        end_do_loop( _environment );
        // ------------------------------------ FETCH AND DECODE LOOP (end)

        cpu_label( _environment, label );
        cpu_return( _environment );

    deploy_end( draw_tsb_string );

    Variable * string = variable_retrieve( _environment, _string );
    Variable * c = variable_retrieve_or_define( _environment, _c, VT_COLOR, 0 );
    Variable * startX = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
    Variable * startY = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );

    if ( ( string->type != VT_STRING ) && ( string->type != VT_DSTRING ) ) {
        CRITICAL_CANNOT_USE_DRAW_WITHOUT_STRING( _string );
    }

    if( string->type == VT_STRING ) {
        Variable * dstring = variable_temporary( _environment, VT_DSTRING, "(dstring)" );
        cpu_dsdefine( _environment, string->realName, dstring->realName );
        string = dstring;
    }

    Variable * parameter = variable_retrieve( _environment, "drawstring__string" );
    Variable * colorParameter = variable_retrieve( _environment, "drawstring__color" );
    Variable * StartXParameter = variable_retrieve( _environment, "drawstring__x" );
    Variable * StartYParameter = variable_retrieve( _environment, "drawstring__y" );
    
    variable_move( _environment, string->name, parameter->name );
    variable_move( _environment, c->name, colorParameter->name );
    variable_move( _environment, startX->name, StartXParameter->name );
    variable_move( _environment, startY->name, StartYParameter->name );
    cpu_call( _environment, "lib_draw_tsb_string");

}