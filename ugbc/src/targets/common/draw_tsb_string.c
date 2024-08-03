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

        // 0 move one pixel to the right
        // 1 move one pixel up
        // 2 move in pixels down
        // 3 move one pixel to the left
        // 5 move one pixel to the right and draw a point
        // 6 move one pixel up
        // 7 move one pixel down
        // 8 move one pixel to the left
        // 9 finished figure

        // char drawStringLabel[MAX_TEMPORARY_STORAGE]; sprintf( drawStringLabel, "%sds", label );
        // char readParameterLabel[MAX_TEMPORARY_STORAGE]; sprintf( readParameterLabel, "%srp", label );
        // char readParameter2Label[MAX_TEMPORARY_STORAGE]; sprintf( readParameter2Label, "%srp2", label );
        // char readParameter3Label[MAX_TEMPORARY_STORAGE]; sprintf( readParameter3Label, "%srp3", label );

        // char moveCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( moveCommandLabel, "%smove", label );
        // char move2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( move2CommandLabel, "%smove2", label );
        // char move3CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( move3CommandLabel, "%smove3", label );
        // char move4CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( move4CommandLabel, "%smove4", label );
        // char move5CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( move5CommandLabel, "%smove5", label );
        // char updownCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( updownCommandLabel, "%supdown", label );
        // char updown2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( updown2CommandLabel, "%supdown2", label );
        // char upCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( upCommandLabel, "%sup", label );
        // char downCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( downCommandLabel, "%sdown", label );
        // char leftrightCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( leftrightCommandLabel, "%sleftright", label );
        // char leftright2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( leftright2CommandLabel, "%sleftright2", label );
        // char leftCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( leftCommandLabel, "%sleft", label );
        // char rightCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( rightCommandLabel, "%sright", label );
        // char up2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( up2CommandLabel, "%sup2", label );
        // char down2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( down2CommandLabel, "%sdown2", label );
        // char left2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( left2CommandLabel, "%sleft2", label );
        // char right2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( right2CommandLabel, "%sright2", label );
        // char blankCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( blankCommandLabel, "%sblank", label );
        // char doneCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( doneCommandLabel, "%sdone", label );
        // char done2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( done2CommandLabel, "%sdone2", label );
        // char drawCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( drawCommandLabel, "%sdraw", label );
        // char angleCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( angleCommandLabel, "%sangle", label );
        // char anglesCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( anglesCommandLabel, "%sangles", label );
        // char angles2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( angles2CommandLabel, "%sangles2", label );
        // char angle45CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( angle45CommandLabel, "%sa45", label );
        // char angle135CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( angle135CommandLabel, "%sa135", label );
        // char angle225CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( angle225CommandLabel, "%sa225", label );
        // char angle315CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( angle315CommandLabel, "%sa315", label );
        // char colorCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( colorCommandLabel, "%scol", label );
        // char scaleCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( scaleCommandLabel, "%sscale", label );
        // char rotateCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( rotateCommandLabel, "%srotate", label );
        // char rotate0CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( rotate0CommandLabel, "%srotate0", label );
        // char rotate90CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( rotate90CommandLabel, "%srotate90", label );
        // char rotate180CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( rotate180CommandLabel, "%srotate180", label );
        // char rotate270CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( rotate270CommandLabel, "%srotate270", label );
        // char noUpdateCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( noUpdateCommandLabel, "%snoupdate", label );

        // Variable * drawUCommandLetter = variable_retrieve( _environment, "DRAWUCOMMAND" );
        // Variable * drawDCommandLetter = variable_retrieve( _environment, "DRAWDCOMMAND" );
        // Variable * drawLCommandLetter = variable_retrieve( _environment, "DRAWLCOMMAND" );
        // Variable * drawRCommandLetter = variable_retrieve( _environment, "DRAWRCOMMAND" );
        // Variable * drawECommandLetter = variable_retrieve( _environment, "DRAWECOMMAND" );
        // Variable * drawFCommandLetter = variable_retrieve( _environment, "DRAWFCOMMAND" );
        // Variable * drawGCommandLetter = variable_retrieve( _environment, "DRAWGCOMMAND" );
        // Variable * drawHCommandLetter = variable_retrieve( _environment, "DRAWHCOMMAND" );

        // // Move to the start of routine
        // cpu_jump( _environment, drawStringLabel );

        // // ----------------------------[ SUBROUTINE: READ PARAMETER ]

        // // string -> (address, size)
        // Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)" );
        // Variable * size = variable_temporary( _environment, VT_BYTE, "(address)" );

        // // xxx, -> (paddress, psize)
        // Variable * paddress = variable_temporary( _environment, VT_ADDRESS, "(address)" );
        // Variable * psize = variable_temporary( _environment, VT_BYTE, "(size)" );
        // Variable * digit = variable_temporary( _environment, VT_BYTE, "(digit)" );
        // Variable * parameter = variable_temporary( _environment, VT_POSITION, "(parameter)" );
        // Variable * eos = variable_temporary( _environment, VT_BYTE, "(eos)" );

        // cpu_label( _environment, readParameterLabel );

        // // Take current address as starting of parameter
        // cpu_move_16bit( _environment, address->realName, paddress->realName );

        // // The parameter starts with a zero length.
        // cpu_store_8bit( _environment, psize->realName, 0 );

        // // Let's retrieve the parameter. We know that the parameter should end
        // // with a ',' so we are looking for that character, or for the end
        // // of the original string, as well -- note that the end of the string
        // // means end of the parameter itself.
        // begin_loop( _environment );

        //     // Exit if drawing string is ended
        //     cpu_compare_and_branch_8bit_const( _environment, size->realName, 0, readParameter2Label, 1 );

        //     // Exit from this loop if the letter is not a digit.
        //     cpu_move_8bit_indirect2( _environment, address->realName, digit->realName );
        //     cpu_dec( _environment, size->realName );
        //     cpu_inc_16bit( _environment, address->realName );
        //     cpu_greater_than_8bit_const( _environment, digit->realName, '9', eos->realName, 0, 0 );
        //     cpu_compare_and_branch_8bit_const( _environment, eos->realName, 0xff, readParameter3Label, 1 );
        //     cpu_less_than_8bit_const( _environment, digit->realName, '0', eos->realName, 0, 0 );
        //     cpu_compare_and_branch_8bit_const( _environment, eos->realName, 0xff, readParameter3Label, 1 );

        //     // Increment the length of the parameter, and move along the
        //     // drawing commands string
        //     cpu_inc( _environment, psize->realName );

        // end_loop( _environment );

        // cpu_label( _environment, readParameter3Label );
        // // cpu_dec_16bit( _environment, address->realName );
        // // cpu_inc( _environment, size->realName );
        // // If we arrived here, it means that we are able to read and decode
        // // the parameter as number.
        // cpu_label( _environment, readParameter2Label );
        // cpu_convert_string_into_16bit( _environment, paddress->realName, psize->realName, parameter->realName );

        // cpu_return( _environment );

        // // ------------------------------------ STARTING ROUTINE
        // cpu_label( _environment, drawStringLabel );

        // String with the drawing commands,
        Variable * string = variable_define( _environment, "drawstring__string", VT_DSTRING, 0 );

        // // Letter with command
        // Variable * command = variable_temporary( _environment, VT_BYTE, "(command)" );

        // // Next coordinates to move to.
        // Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
        // Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );

        // // Next delta coordinates.
        // Variable * dx = variable_temporary( _environment, VT_POSITION, "(dx)" );
        // Variable * dy = variable_temporary( _environment, VT_POSITION, "(dy)" );

        // // Next delta coordinates scaled
        // Variable * ds = variable_temporary( _environment, VT_POSITION, "(ds)" );

        // // Scale.
        // Variable * scale = variable_retrieve( _environment, "DRAWSCALE" );
        // Variable * four = variable_temporary( _environment, VT_BYTE, "(four)" );
        // variable_store( _environment, four->name, 4 );

        // // Angle
        // Variable * angle = variable_retrieve( _environment, "DRAWANGLE" );

        // // Is blank required?
        // Variable * blank = variable_temporary( _environment, VT_BYTE, "(blank)" );

        // // Position has not to be updated?
        // Variable * noUpdate = variable_temporary( _environment, VT_BYTE, "(noUpdate)" );

        // // Color to be used
        // Variable * c = variable_temporary( _environment, VT_COLOR, "(color)" );

        // // Retrieve the effective address of the string with the drawing commands.

        // variable_move( _environment, "PEN", c->name );

        // cpu_dsdescriptor( _environment, string->realName, address->realName, size->realName );

        // // ------------------------------------ FETCH AND DECODE LOOP
        // begin_loop( _environment );

        //     // Starting with current position on x and y
        //     variable_move( _environment, origin_resolution_relative_transform_x( _environment, NULL, 0 )->name, x->name );
        //     variable_move( _environment, origin_resolution_relative_transform_y( _environment, NULL, 0 )->name, y->name );

        //     // Are drawing commands ended? Exit fetch and decode loop.
        //     cpu_compare_and_branch_8bit_const( _environment, size->realName, 0, label, 1 );

        //     // Retrieve command letter.
        //     cpu_move_8bit_indirect2( _environment, address->realName, command->realName );
        //     cpu_dec( _environment, size->realName );
        //     cpu_inc_16bit( _environment, address->realName );

        //     // Is it 'M' ? -> MOVE
        //     cpu_compare_and_branch_char_const( _environment, command->realName, 'M', moveCommandLabel, 1 );

        //     // Is it 'L' ? -> LEFT
        //     cpu_compare_and_branch_8bit( _environment, command->realName, drawLCommandLetter->realName, leftCommandLabel, 1 );

        //     // Is it 'R' ? -> RIGHT
        //     cpu_compare_and_branch_8bit( _environment, command->realName, drawRCommandLetter->realName, rightCommandLabel, 1 );

        //     // Is it 'U' ? -> UP
        //     cpu_compare_and_branch_8bit( _environment, command->realName, drawUCommandLetter->realName, upCommandLabel, 1 );

        //     // Is it 'D' ? -> DOWN
        //     cpu_compare_and_branch_8bit( _environment, command->realName, drawDCommandLetter->realName, downCommandLabel, 1 );

        //     // Is it 'B' ? -> BLANK (next action)
        //     cpu_compare_and_branch_char_const( _environment, command->realName, 'B', blankCommandLabel, 1 );

        //     // Is it 'E' ? -> 45°
        //     cpu_compare_and_branch_8bit( _environment, command->realName, drawECommandLetter->realName, angleCommandLabel, 1 );

        //     // Is it 'F' ? -> 135°
        //     cpu_compare_and_branch_8bit( _environment, command->realName, drawFCommandLetter->realName, angleCommandLabel, 1 );

        //     // Is it 'G' ? -> 225°
        //     cpu_compare_and_branch_8bit( _environment, command->realName, drawGCommandLetter->realName, angleCommandLabel, 1 );

        //     // Is it 'H' ? -> 315°
        //     cpu_compare_and_branch_8bit( _environment, command->realName, drawHCommandLetter->realName, angleCommandLabel, 1 );

        //     // Is it 'C' ? -> change color
        //     cpu_compare_and_branch_char_const( _environment, command->realName, 'C', colorCommandLabel, 1 );

        //     // Is it 'S' ? -> scale
        //     cpu_compare_and_branch_char_const( _environment, command->realName, 'S', scaleCommandLabel, 1 );

        //     // Is it 'A' ? -> angle (rotate)
        //     cpu_compare_and_branch_char_const( _environment, command->realName, 'A', rotateCommandLabel, 1 );

        //     // Is it 'N' ? -> NO UPDATE (next action)
        //     cpu_compare_and_branch_char_const( _environment, command->realName, 'N', noUpdateCommandLabel, 1 );

        //     // No command was recognized: silently, move to the next character.
        //     cpu_jump( _environment, doneCommandLabel );

        //     // ----------------------------[ MOVE ]
        //     cpu_label( _environment, moveCommandLabel );

        //     cpu_call( _environment, readParameterLabel );

        //     cpu_move_16bit( _environment, parameter->realName, x->realName );

        //     cpu_call( _environment, readParameterLabel );

        //     cpu_move_16bit( _environment, parameter->realName, y->realName );

        //     // // Now we have to transform (x,y) into the effective
        //     // // reference system, based on ORIGIN and RESOLUTION keywords.
        //     // variable_move( _environment, origin_resolution_relative_transform_x( _environment, x->name, 0 )->name, x->name );
        //     // variable_move( _environment, origin_resolution_relative_transform_y( _environment, y->name, 0 )->name, y->name );

        //     cpu_jump( _environment, drawCommandLabel );

        //     // ----------------------------[ BLANK ]

        //     // Enable blanking (only for the next move instruction)
        //     cpu_label( _environment, blankCommandLabel );
        //     cpu_store_8bit( _environment, blank->realName, 0xff );
        //     cpu_jump( _environment, doneCommandLabel );

        //     // ----------------------------[ NO UPDATE ]

        //     // No update position (only for the next move instruction)
        //     cpu_label( _environment, noUpdateCommandLabel );
        //     cpu_store_8bit( _environment, noUpdate->realName, 0xff );
        //     cpu_jump( _environment, doneCommandLabel );

        //     // ----------------------------[ COLOR ]

        //     // Change color
        //     cpu_label( _environment, colorCommandLabel );
        //     cpu_call( _environment, readParameterLabel );
        //     variable_move( _environment, parameter->name, c->name );
        //     cpu_jump( _environment, done2CommandLabel );

        //     // ----------------------------[ SCALE ]

        //     // Change scale
        //     cpu_label( _environment, scaleCommandLabel );
        //     cpu_call( _environment, readParameterLabel );
        //     variable_move( _environment, parameter->name, scale->name );
        //     cpu_jump( _environment, done2CommandLabel );

        //     // ----------------------------[ ANGLE ]

        //     // Change angle
        //     cpu_label( _environment, rotateCommandLabel );
        //     cpu_call( _environment, readParameterLabel );
        //     variable_move( _environment, parameter->name, angle->name );
        //     cpu_compare_and_branch_8bit_const( _environment, angle->realName, 0, rotate0CommandLabel, 1 );
        //     cpu_compare_and_branch_8bit_const( _environment, angle->realName, 1, rotate90CommandLabel, 1 );
        //     cpu_compare_and_branch_8bit_const( _environment, angle->realName, 2, rotate180CommandLabel, 1 );
        //     cpu_compare_and_branch_8bit_const( _environment, angle->realName, 3, rotate270CommandLabel, 1 );

        //     cpu_label( _environment, rotate0CommandLabel );
        //     cpu_store_char( _environment, drawUCommandLetter->realName, 'U' );
        //     cpu_store_char( _environment, drawDCommandLetter->realName, 'D' );
        //     cpu_store_char( _environment, drawLCommandLetter->realName, 'L' );
        //     cpu_store_char( _environment, drawRCommandLetter->realName, 'R' );
        //     cpu_store_char( _environment, drawECommandLetter->realName, 'E' );
        //     cpu_store_char( _environment, drawFCommandLetter->realName, 'F' );
        //     cpu_store_char( _environment, drawGCommandLetter->realName, 'G' );
        //     cpu_store_char( _environment, drawHCommandLetter->realName, 'H' );
        //     cpu_jump( _environment, done2CommandLabel );

        //     cpu_label( _environment, rotate90CommandLabel );
        //     cpu_store_char( _environment, drawUCommandLetter->realName, 'L' );
        //     cpu_store_char( _environment, drawDCommandLetter->realName, 'R' );
        //     cpu_store_char( _environment, drawLCommandLetter->realName, 'D' );
        //     cpu_store_char( _environment, drawRCommandLetter->realName, 'U' );
        //     cpu_store_char( _environment, drawECommandLetter->realName, 'H' );
        //     cpu_store_char( _environment, drawFCommandLetter->realName, 'E' );
        //     cpu_store_char( _environment, drawGCommandLetter->realName, 'F' );
        //     cpu_store_char( _environment, drawHCommandLetter->realName, 'G' );
        //     cpu_jump( _environment, done2CommandLabel );

        //     cpu_label( _environment, rotate180CommandLabel );
        //     cpu_store_char( _environment, drawUCommandLetter->realName, 'D' );
        //     cpu_store_char( _environment, drawDCommandLetter->realName, 'U' );
        //     cpu_store_char( _environment, drawLCommandLetter->realName, 'R' );
        //     cpu_store_char( _environment, drawRCommandLetter->realName, 'L' );
        //     cpu_store_char( _environment, drawECommandLetter->realName, 'G' );
        //     cpu_store_char( _environment, drawFCommandLetter->realName, 'H' );
        //     cpu_store_char( _environment, drawGCommandLetter->realName, 'E' );
        //     cpu_store_char( _environment, drawHCommandLetter->realName, 'F' );
        //     cpu_jump( _environment, done2CommandLabel );

        //     cpu_label( _environment, rotate270CommandLabel );
        //     cpu_store_char( _environment, drawUCommandLetter->realName, 'R' );
        //     cpu_store_char( _environment, drawDCommandLetter->realName, 'L' );
        //     cpu_store_char( _environment, drawLCommandLetter->realName, 'U' );
        //     cpu_store_char( _environment, drawRCommandLetter->realName, 'D' );
        //     cpu_store_char( _environment, drawECommandLetter->realName, 'F' );
        //     cpu_store_char( _environment, drawFCommandLetter->realName, 'G' );
        //     cpu_store_char( _environment, drawGCommandLetter->realName, 'H' );
        //     cpu_store_char( _environment, drawHCommandLetter->realName, 'E' );
        //     cpu_jump( _environment, done2CommandLabel );

        //     cpu_jump( _environment, done2CommandLabel );

        //     // ----------------------------[ UP/DOWN ]
        //     cpu_label( _environment, upCommandLabel );
        //     cpu_label( _environment, downCommandLabel );

        //     cpu_call( _environment, readParameterLabel );

        //     // If we arrived here, it means that we are able to read and decode
        //     // the parameter as (negative) dy.
        //     cpu_label( _environment, up2CommandLabel );

        //     cpu_compare_and_branch_8bit_const( _environment, psize->realName, 0, updownCommandLabel, 1 );
        //     cpu_move_16bit( _environment, parameter->realName, dy->realName );
        //     cpu_jump( _environment, updown2CommandLabel );
        //     cpu_label( _environment, updownCommandLabel );
        //     cpu_store_8bit( _environment, dy->realName, 1 );
        //     cpu_jump( _environment, updown2CommandLabel );
        //     cpu_label( _environment, updown2CommandLabel );

        //     variable_move( _environment, origin_resolution_relative_transform_y( _environment, dy->name, 0 )->name, dy->name );

        //     variable_move( _environment, variable_mul( _environment, dy->name, scale->name )->name, dy->name );
        //     variable_move( _environment, variable_div( _environment, dy->name, four->name, NULL )->name, ds->name );

        //     cpu_compare_and_branch_8bit( _environment, command->realName, drawDCommandLetter->realName, down2CommandLabel, 1 );

        //     variable_move( _environment, 
        //         variable_sub( _environment, y->name, 
        //             ds->name
        //         )->name,
        //         y->name
        //                     );
        //     cpu_jump( _environment, drawCommandLabel );

        //     cpu_label( _environment, down2CommandLabel );
        //     variable_move( _environment, 
        //         variable_add( _environment, y->name, 
        //             ds->name
        //         )->name,
        //         y->name
        //     );
        //     cpu_jump( _environment, drawCommandLabel );

        //     // ----------------------------[ LEFT/RIGHT ]
        //     cpu_label( _environment, leftCommandLabel );
        //     cpu_label( _environment, rightCommandLabel );

        //     cpu_call( _environment, readParameterLabel );

        //     // If we arrived here, it means that we are able to read and decode
        //     // the parameter as (negative) dx.
        //     cpu_label( _environment, left2CommandLabel );
        //     cpu_compare_and_branch_8bit_const( _environment, psize->realName, 0, leftrightCommandLabel, 1 );
        //     cpu_move_16bit( _environment, parameter->realName, dx->realName );
        //     cpu_jump( _environment, leftright2CommandLabel );
        //     cpu_label( _environment, leftrightCommandLabel );
        //     cpu_store_8bit( _environment, dx->realName, 1 );
        //     cpu_jump( _environment, leftright2CommandLabel );
        //     cpu_label( _environment, leftright2CommandLabel );

        //     variable_move( _environment, origin_resolution_relative_transform_x( _environment, dx->name, 0 )->name, dx->name );

        //     variable_move( _environment, variable_mul( _environment, dx->name, scale->name )->name, dx->name );
        //     variable_move( _environment, variable_div( _environment, dx->name, four->name, NULL )->name, ds->name );

        //     cpu_compare_and_branch_8bit( _environment, command->realName, drawRCommandLetter->realName, right2CommandLabel, 1 );

        //     variable_move( _environment, 
        //         variable_sub( _environment, x->name, 
        //             ds->name
        //         )->name,
        //         x->name
        //     );
        //     cpu_jump( _environment, drawCommandLabel );

        //     cpu_label( _environment, right2CommandLabel );
        //     variable_move( _environment, 
        //         variable_add( _environment, x->name, 
        //             ds->name
        //         )->name,
        //         x->name
        //     );
        //     cpu_jump( _environment, drawCommandLabel );

        //     // ----------------------------[ ANGLE 45, 135, 225, 315 ]

        //     cpu_label( _environment, angleCommandLabel );

        //     cpu_call( _environment, readParameterLabel );

        //     cpu_compare_and_branch_8bit_const( _environment, psize->realName, 0, anglesCommandLabel, 1 );
        //     cpu_move_16bit( _environment, parameter->realName, dx->realName );
        //     cpu_jump( _environment, angles2CommandLabel );
        //     cpu_label( _environment, anglesCommandLabel );
        //     cpu_store_8bit( _environment, dx->realName, 1 );
        //     cpu_jump( _environment, angles2CommandLabel );
        //     cpu_label( _environment, angles2CommandLabel );

        //     variable_move( _environment, origin_resolution_relative_transform_x( _environment, dx->name, 0 )->name, dx->name );

        //     variable_move( _environment, variable_mul( _environment, dx->name, scale->name )->name, dx->name );
        //     variable_move( _environment, variable_div( _environment, dx->name, four->name, NULL )->name, ds->name );

        //     cpu_compare_and_branch_8bit( _environment, command->realName, drawECommandLetter->realName, angle45CommandLabel, 1 );

        //     cpu_compare_and_branch_8bit( _environment, command->realName, drawFCommandLetter->realName, angle135CommandLabel, 1 );

        //     cpu_compare_and_branch_8bit( _environment, command->realName, drawGCommandLetter->realName, angle225CommandLabel, 1 );

        //     cpu_compare_and_branch_8bit( _environment, command->realName, drawHCommandLetter->realName, angle315CommandLabel, 1 );

        //     cpu_label( _environment, angle45CommandLabel );
        //     variable_move( _environment, 
        //         variable_add( _environment, x->name, 
        //             ds->name
        //         )->name,
        //         x->name
        //     );
        //     variable_move( _environment, 
        //         variable_sub( _environment, y->name, 
        //             ds->name
        //         )->name,
        //         y->name
        //     );
        //     cpu_jump( _environment, drawCommandLabel );

        //     cpu_label( _environment, angle135CommandLabel );
        //     variable_move( _environment, 
        //         variable_add( _environment, x->name, 
        //             ds->name
        //         )->name,
        //         x->name
        //     );
        //     variable_move( _environment, 
        //         variable_add( _environment, y->name, 
        //             ds->name
        //         )->name,
        //         y->name
        //     );
        //     cpu_jump( _environment, drawCommandLabel );

        //     cpu_label( _environment, angle225CommandLabel );
        //     variable_move( _environment, 
        //         variable_sub( _environment, x->name, 
        //             ds->name
        //         )->name,
        //         x->name
        //     );
        //     variable_move( _environment, 
        //         variable_add( _environment, y->name, 
        //             ds->name
        //         )->name,
        //         y->name
        //     );
        //     cpu_jump( _environment, drawCommandLabel );

        //     cpu_label( _environment, angle315CommandLabel );
        //     variable_move( _environment, 
        //         variable_sub( _environment, x->name, 
        //             ds->name
        //         )->name,
        //         x->name
        //     );
        //     variable_move( _environment, 
        //         variable_sub( _environment, y->name, 
        //             ds->name
        //         )->name,
        //         y->name
        //     );
        //     cpu_jump( _environment, drawCommandLabel );

        //     // ----------------------------[ DRAW (or BLANK) ]
        //     cpu_label( _environment, drawCommandLabel );

        //     // If blank move has been requested, we avoid to draw anything.
        //     cpu_compare_and_branch_8bit_const( _environment, blank->realName, 0xff, move5CommandLabel, 1 );

        //     // Let's draw from the previous position to the current position.
        //     draw( _environment, 
        //         origin_resolution_relative_transform_x( _environment, NULL, 0 )->name, 
        //         origin_resolution_relative_transform_y( _environment, NULL, 0 )->name, 
        //         x->name, y->name, c->name, 0 );

        //     // Update current position (this is done also if nothing is drawn!)
        //     cpu_label( _environment, move5CommandLabel );

        //     // Avoid to not to draw again.
        //     cpu_store_8bit( _environment, blank->realName, 0 );

        //     // Avoid to update position if not requested
        //     cpu_compare_and_branch_8bit_const( _environment, noUpdate->realName, 0xff, done2CommandLabel, 1 );
        //     gr_locate( _environment, x->name, y->name );

        //     // Move to the next character of the drawing commands string.
        //     cpu_label( _environment, done2CommandLabel );
        //     cpu_store_8bit( _environment, noUpdate->realName, 0 );
        //     cpu_inc( _environment, size->realName );
        //     cpu_dec_16bit( _environment, address->realName );
        //     cpu_store_16bit( _environment, dx->realName, 0 );
        //     cpu_store_16bit( _environment, dy->realName, 0 );
        //     cpu_store_16bit( _environment, ds->realName, 0 );
        //     cpu_jump( _environment, doneCommandLabel );

        //     // Move to the next character of the drawing commands string.
        //     cpu_label( _environment, doneCommandLabel );

        // end_loop( _environment );
        // // ------------------------------------ FETCH AND DECODE LOOP (end)

        // cpu_label( _environment, label );
        // cpu_return( _environment );

    deploy_end( draw_tsb_string );

    Variable * string = variable_retrieve( _environment, _string );

    if ( ( string->type != VT_STRING ) && ( string->type != VT_DSTRING ) ) {
        CRITICAL_CANNOT_USE_DRAW_WITHOUT_STRING( _string );
    }

    if( string->type == VT_STRING ) {
        Variable * dstring = variable_temporary( _environment, VT_DSTRING, "(dstring)" );
        cpu_dsdefine( _environment, string->realName, dstring->realName );
        string = dstring;
    }

    Variable * parameter = variable_retrieve( _environment, "drawstring__string" );
    
    variable_move( _environment, string->name, parameter->name );
    cpu_call( _environment, "lib_draw_tsb_string");

}