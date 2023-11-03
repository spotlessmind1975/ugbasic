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

/* <usermanual>
@keyword DRAW (program)

@english

The ''DRAW'' command allows to draw on the SCREEN. The parameter is either a 
string constant, or a string variable, containing a set of the draw 
subcommands. Usually the first action of any drawing is to move 
to the start point. 

''M x,y'' means move to the co−ordinates given by ''x,y''.
If you wanto to move to a point, it is usually a good idea to make a "blank" move, 
that is move without drawing or lifting the pencil off the paper. 

If you do not you may get unwanted lines on your drawing, you can use the letter ''B''.
Any drawing instruction following the ''B'' will be a blank line. BMx,y means move to 
the ''x,y'' without drawing. Having decided the start point, you may now move up (U), 
down (D), right (R), or Left (L) by as many pixels as you like. The sequence 
U20/R20/D20/L20/ will cause drawing a square. 

@italian

Il comando ''DRAW'' consente di disegnare sullo schermo. Il parametro è una costante 
stringa o una variabile stringa contenente un insieme di sottocomandi. Di solito 
la prima azione di qualsiasi disegno è spostarsi al punto iniziale.

''M x,y'' significa spostarsi verso le coordinate date da ''x,y''. Se ci si vuole spostare
verso un punto, di solito è una buona idea fare una mossa senza scrivere, cioè 
muoversi senza disegnare o sollevare la matita dal foglio.

In caso contrario si potrebbero ottenere linee indesiderate sullo schermo. Si può utilizzare 
la lettera ''B''. Qualsiasi istruzione di disegno che segue la ''B'' sarà priva di effetti
di disegno. ''BMx,y'' significa spostarsi su ''x,y'' senza disegnare.

Dopo aver deciso il punto iniziale, ci si può spostare in alto (''U''), in basso (''D''), 
a destra (''R'') o a sinistra (''L'') di quanti pixel si desidera. La sequenza 
U20/R20/D20/L20/ causerà il disegno di un quadrato.

@syntax DRAW instructions

@example DRAW "BM0,0;R10;U10;L10;D10"

@target all
</usermanual> */
void draw_string( Environment * _environment, char * _string ) {

    deploy_begin( draw_string );

        MAKE_LABEL

        char moveCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( moveCommandLabel, "%smove", label );
        char move2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( move2CommandLabel, "%smove2", label );
        char move3CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( move3CommandLabel, "%smove3", label );
        char move4CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( move4CommandLabel, "%smove4", label );
        char move5CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( move5CommandLabel, "%smove5", label );
        char updownCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( updownCommandLabel, "%supdown", label );
        char updown2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( updown2CommandLabel, "%supdown2", label );
        char upCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( upCommandLabel, "%sup", label );
        char downCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( downCommandLabel, "%sdown", label );
        char leftrightCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( leftrightCommandLabel, "%sleftright", label );
        char leftright2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( leftright2CommandLabel, "%sleftright2", label );
        char leftCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( leftCommandLabel, "%sleft", label );
        char rightCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( rightCommandLabel, "%sright", label );
        char up2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( up2CommandLabel, "%sup2", label );
        char down2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( down2CommandLabel, "%sdown2", label );
        char left2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( left2CommandLabel, "%sleft2", label );
        char right2CommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( right2CommandLabel, "%sright2", label );
        char blankCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( blankCommandLabel, "%sblank", label );
        char doneCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( doneCommandLabel, "%sdone", label );
        char drawCommandLabel[MAX_TEMPORARY_STORAGE]; sprintf( drawCommandLabel, "%sdraw", label );

        // String with the drawing commands,
        Variable * string = variable_define( _environment, "drawstring__string", VT_DSTRING, 0 );

        // string -> (address, size)
        Variable * address = variable_temporary( _environment, VT_ADDRESS, "(address)" );
        Variable * size = variable_temporary( _environment, VT_BYTE, "(address)" );

        // Letter with command
        Variable * command = variable_temporary( _environment, VT_BYTE, "(command)" );
        // Letter with parameter
        Variable * parameter = variable_temporary( _environment, VT_BYTE, "(character)" );

        // xxx, -> (paddress, psize)
        Variable * paddress = variable_temporary( _environment, VT_ADDRESS, "(address)" );
        Variable * psize = variable_temporary( _environment, VT_BYTE, "(size)" );

        // Next coordinates to move to.
        Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
        Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );

        // Next delta coordinates.
        Variable * dx = variable_temporary( _environment, VT_POSITION, "(dx)" );
        Variable * dy = variable_temporary( _environment, VT_POSITION, "(dy)" );

        // Is blank required?
        Variable * blank = variable_temporary( _environment, VT_BYTE, "(blank)" );

        // Retrieve the effective address of the string with the drawing commands.
        cpu_dsdescriptor( _environment, string->realName, address->realName, size->realName );

        // ------------------------------------ FETCH AND DECODE LOOP
        begin_loop( _environment );

            // Are drawing commands ended? Exit fetch and decode loop.
            cpu_compare_and_branch_8bit_const( _environment, size->realName, 0, label, 1 );

            // Retrieve command letter.
            cpu_move_8bit_indirect2( _environment, address->realName, command->realName );
            cpu_dec( _environment, size->realName );

            // Is it 'M' ? -> MOVE
            cpu_compare_and_branch_8bit_const( _environment, command->realName, 'M', moveCommandLabel, 1 );

            // Is it 'L' ? -> LEFT
            cpu_compare_and_branch_8bit_const( _environment, command->realName, 'L', leftCommandLabel, 1 );

            // Is it 'R' ? -> RIGHT
            cpu_compare_and_branch_8bit_const( _environment, command->realName, 'R', rightCommandLabel, 1 );

            // Is it 'U' ? -> UP
            cpu_compare_and_branch_8bit_const( _environment, command->realName, 'U', upCommandLabel, 1 );

            // Is it 'D' ? -> DOWN
            cpu_compare_and_branch_8bit_const( _environment, command->realName, 'D', downCommandLabel, 1 );

            // Is it 'B' ? -> BLANK (next action)
            cpu_compare_and_branch_8bit_const( _environment, command->realName, 'B', blankCommandLabel, 1 );

            // No command was recognized: silently, move to the next character.
            cpu_jump( _environment, doneCommandLabel );

            // ----------------------------[ MOVE ]
            cpu_label( _environment, moveCommandLabel );

            // Move to the next character, that should be the first digit of x position.
            cpu_inc_16bit( _environment, address->realName );

            // Move the current string address to the starting address of x parameter.
            cpu_move_16bit( _environment, address->realName, paddress->realName );

            // The parameter starts with a zero length.
            cpu_store_8bit( _environment, psize->realName, 0 );

            // Let's retrieve the parameter. We know that the parameter should end
            // with a ',' so we are looking for that character, or for the end
            // of the original string, as well -- note that the end of the string
            // means end of the command itself.
            begin_loop( _environment );

                // Exit if drawing string is ended
                cpu_compare_and_branch_8bit_const( _environment, size->realName, 0, label, 1 );

                // Exit from this loop if the letter read is a comma. 
                cpu_move_8bit_indirect2( _environment, address->realName, parameter->realName );
                cpu_dec( _environment, size->realName );
                cpu_compare_and_branch_8bit_const( _environment, parameter->realName, ',', move2CommandLabel, 1 );

                // Increment the length of the parameter, and move along the
                // drawing commands string
                cpu_inc( _environment, psize->realName );
                cpu_inc_16bit( _environment, address->realName );

            end_loop( _environment );

            // If we arrived here, it means that we are able to read and decode
            // the parameter as x position.
            cpu_label( _environment, move2CommandLabel );
            cpu_convert_string_into_16bit( _environment, paddress->realName, psize->realName, x->realName );

            // Let's retrieve the second parameter. We know that the parameter should end
            // with a ';' of with the end of the string, so we are looking for that character, 
            // or for the end of the original string, as well.

            cpu_inc_16bit( _environment, address->realName );
            cpu_move_16bit( _environment, address->realName, paddress->realName );
            cpu_store_8bit( _environment, psize->realName, 0 );

            begin_loop( _environment );

                // Exit from this loop if the string ended. 
                cpu_compare_and_branch_8bit_const( _environment, size->realName, 0, move3CommandLabel, 1 );

                // Exit from this loop if the letter read is a semi-comma
                cpu_move_8bit_indirect2( _environment, address->realName, parameter->realName );
                cpu_dec( _environment, size->realName );
                cpu_compare_and_branch_8bit_const( _environment, parameter->realName, ';', move3CommandLabel, 1 );

                cpu_inc( _environment, psize->realName );

                cpu_inc_16bit( _environment, address->realName );

            end_loop( _environment );

            // If we arrived here, it means that we are able to read and decode
            // the parameter as y position.
            cpu_label( _environment, move3CommandLabel );
            cpu_convert_string_into_16bit( _environment, paddress->realName, psize->realName, y->realName );

            // Now we have to transform (x,y) into the effective
            // reference system, based on ORIGIN and RESOLUTION keywords.
            variable_move( _environment, origin_resolution_relative_transform_x( _environment, x->name, 0 )->name, x->name );
            variable_move( _environment, origin_resolution_relative_transform_y( _environment, y->name, 0 )->name, y->name );

            cpu_jump( _environment, drawCommandLabel );

            // ----------------------------[ BLANK ]

            // Enable blanking (only for the next move instruction)
            cpu_label( _environment, blankCommandLabel );
            cpu_store_8bit( _environment, blank->realName, 0xff );
            cpu_jump( _environment, doneCommandLabel );

            // ----------------------------[ UP/DOWN ]
            cpu_label( _environment, upCommandLabel );
            cpu_label( _environment, downCommandLabel );

            // Let's retrieve the parameter. We know that the parameter should end
            // with a ';' of with the end of the string, so we are looking for that character, 
            // or for the end of the original string, as well.

            cpu_inc_16bit( _environment, address->realName );
            cpu_move_16bit( _environment, address->realName, paddress->realName );
            cpu_store_8bit( _environment, psize->realName, 0 );

            begin_loop( _environment );

                cpu_compare_and_branch_8bit_const( _environment, size->realName, 0, up2CommandLabel, 1 );

                // Exit from this loop if the letter read is a semi-comma or the string ended. 
                cpu_move_8bit_indirect2( _environment, address->realName, parameter->realName );
                cpu_dec( _environment, size->realName );
                cpu_compare_and_branch_8bit_const( _environment, parameter->realName, ';', up2CommandLabel, 1 );

                cpu_inc( _environment, psize->realName );

                cpu_inc_16bit( _environment, address->realName );

            end_loop( _environment );

            // If we arrived here, it means that we are able to read and decode
            // the parameter as (negative) dy.
            cpu_label( _environment, up2CommandLabel );

            cpu_compare_and_branch_8bit_const( _environment, psize->realName, 0, updownCommandLabel, 1 );
            cpu_convert_string_into_16bit( _environment, paddress->realName, psize->realName, dy->realName );
            cpu_jump( _environment, updown2CommandLabel );
            cpu_label( _environment, updownCommandLabel );
            cpu_store_8bit( _environment, dy->realName, 1 );
            cpu_jump( _environment, updown2CommandLabel );
            cpu_label( _environment, updown2CommandLabel );
            variable_move( _environment, origin_resolution_relative_transform_y( _environment, NULL, 0 )->name, y->name );
            variable_move( _environment, origin_resolution_relative_transform_y( _environment, dy->name, 0 )->name, dy->name );

            cpu_compare_and_branch_8bit_const( _environment, command->realName, 'D', down2CommandLabel, 1 );

            variable_move( _environment, 
                variable_sub( _environment, y->name, dy->name )->name,
                y->name
            );
            cpu_jump( _environment, drawCommandLabel );

            cpu_label( _environment, down2CommandLabel );
            variable_move( _environment, 
                variable_add( _environment, y->name, dy->name )->name,
                y->name
            );
            cpu_jump( _environment, drawCommandLabel );

            // ----------------------------[ LEFT/RIGHT ]
            cpu_label( _environment, leftCommandLabel );
            cpu_label( _environment, rightCommandLabel );

            // Let's retrieve the parameter. We know that the parameter should end
            // with a ';' of with the end of the string, so we are looking for that character, 
            // or for the end of the original string, as well.

            cpu_inc_16bit( _environment, address->realName );
            cpu_move_16bit( _environment, address->realName, paddress->realName );
            cpu_store_8bit( _environment, psize->realName, 0 );

            begin_loop( _environment );

                // Exit from this loop if the string ended. 
                cpu_compare_and_branch_8bit_const( _environment, size->realName, 0, left2CommandLabel, 1 );

                // Exit from this loop if the letter read is a semi-comma
                cpu_move_8bit_indirect2( _environment, address->realName, parameter->realName );
                cpu_dec( _environment, size->realName );
                cpu_compare_and_branch_8bit_const( _environment, parameter->realName, ';', left2CommandLabel, 1 );

                cpu_inc( _environment, psize->realName );

                cpu_inc_16bit( _environment, address->realName );

            end_loop( _environment );

            // If we arrived here, it means that we are able to read and decode
            // the parameter as (negative) dx.
            cpu_label( _environment, left2CommandLabel );
            cpu_compare_and_branch_8bit_const( _environment, psize->realName, 0, leftrightCommandLabel, 1 );
            cpu_convert_string_into_16bit( _environment, paddress->realName, psize->realName, dx->realName );
            cpu_jump( _environment, leftright2CommandLabel );
            cpu_label( _environment, leftrightCommandLabel );
            cpu_store_8bit( _environment, dx->realName, 1 );
            cpu_jump( _environment, leftright2CommandLabel );
            cpu_label( _environment, leftright2CommandLabel );

            variable_move( _environment, origin_resolution_relative_transform_x( _environment, NULL, 0 )->name, x->name );
            variable_move( _environment, origin_resolution_relative_transform_x( _environment, dx->name, 0 )->name, dx->name );

            cpu_compare_and_branch_8bit_const( _environment, command->realName, 'R', right2CommandLabel, 1 );

            variable_move( _environment, 
                variable_sub( _environment, x->name, dx->name )->name,
                x->name
            );
            cpu_jump( _environment, drawCommandLabel );

            cpu_label( _environment, right2CommandLabel );
            variable_move( _environment, 
                variable_add( _environment, x->name, dx->name )->name,
                x->name
            );
            cpu_jump( _environment, drawCommandLabel );

            cpu_label( _environment, drawCommandLabel );

            // If blank move has been requested, we avoid to draw anything.
            cpu_compare_and_branch_8bit_const( _environment, blank->realName, 0xff, move5CommandLabel, 1 );

            // Let's draw from the previous position to the current position.
            draw( _environment, 
                origin_resolution_relative_transform_x( _environment, NULL, 0 )->name, 
                origin_resolution_relative_transform_y( _environment, NULL, 0 )->name, 
                x->name, y->name, NULL );

            // Update current position (this is done also if nothing is drawn!)
            cpu_label( _environment, move5CommandLabel );
            gr_locate( _environment, x->name, y->name );

            // Avoid to not to draw again.
            cpu_store_8bit( _environment, blank->realName, 0 );
            cpu_jump( _environment, doneCommandLabel );

            // Move to the next character of the drawing commands string.
            cpu_label( _environment, doneCommandLabel );
            cpu_inc_16bit( _environment, address->realName );

        end_loop( _environment );
        // ------------------------------------ FETCH AND DECODE LOOP (end)

        cpu_label( _environment, label );
        cpu_return( _environment );

        // The ''DRAW'' command allows to draw on the SCREEN. The parameter is either a 
        // string constant, or a string variable, containing a set of the draw 
        // subcommands. Usually the first action of any drawing is to move 
        // to the start point. 

        // ''M x,y'' means move to the co−ordinates given by ''x,y''.
        // If you wanto to move to a point, it is usually a good idea to make a "blank" move, 
        // that is move without drawing or lifting the pencil off the paper. 

        // If you do not you may get unwanted lines on your drawing, you can use the letter ''B''.
        // Any drawing instruction following the ''B'' will be a blank line. BMx,y means move to 
        // the ''x,y'' without drawing. Having decided the start point, you may now move up (U), 
        // down (D), right (R), or Left (L) by as many pixels as you like. The sequence 
        // U20/R20/D20/L20/ will cause drawing a square. 

    deploy_end( draw_string );

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
    cpu_call( _environment, "lib_draw_string");

}