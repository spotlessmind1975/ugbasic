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

/**
 * @brief Emit code for <strong>MOVE ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the procedure
 */
/* <usermanual>
@keyword MMOB

The instruction ''MMOB'' move a sprite on the screen. It is used to move the 
given ''sprite'' from a starting point with the coordinates ''sx,sy'' to a 
target point with the coordinates ''zx,zy''. The parameter ''gr'' sets the
display size of the sprite (and thus changes the basic setting in ''MOB SET''). 
The movement speed is set with ''sp'', with larger values making the sprite
move more slowly.

The shortened form (without the target specification ''zx,zy'') simply 
positions the sprite in question at the selected coordinate ''sx,sy''.

Like the Simons' Basic, 
sprites do not move independently of one another (in an interrupt), 
but only one after the other (one ''MMOB'' command controls one sprite, 
the next command the next sprite, etc.).

The size and speed settings should be entered in ''MOB SET''. Almost all sprite
related parameters are then collected there. The following values for are permitted: 
a ''0'' means 24×21 (normal), ''1'' means 48×21 (x-expanded), ''2'' means 24×42 (y-expanded),
and finally ''3'' means 48×42 (double size).

@english

@italian

@syntax 

@example 

</usermanual> */
void mmob( Environment * _environment, char * _sprite, char * _sx, char * _sy, char * _zx, char * _zy, char * _gr, char * _sp ) {

    MAKE_LABEL

    Variable * sprite = variable_retrieve( _environment, _sprite );

    if ( sprite->type != VT_SPRITE && sprite->type != VT_MSPRITE ) {
        CRITICAL_MMOB_NEEDS_SPRITE(_sprite);
    }

    // The parameter ''gr'' sets the
    // display size of the sprite (and thus changes the basic setting in ''MOB SET''). 
    // The following values ​​for are permitted: 
    // a ''0'' means 24×21 (normal), ''1'' means 48×21 (x-expanded), ''2'' means 24×42 (y-expanded),
    // and finally ''3'' means 48×42 (double size).

    if ( _gr ) {

        char yExpandedLabel[MAX_TEMPORARY_STORAGE]; sprintf( yExpandedLabel, "%sexpy", label );
        char nExpandedLabel[MAX_TEMPORARY_STORAGE]; sprintf( nExpandedLabel, "%sexpn", label );

        Variable * gr = variable_retrieve( _environment, _gr);
        Variable * tmp = variable_temporary( _environment, VT_BYTE, "(tmp)" );

        cpu_and_8bit_const( _environment, gr->realName, 0x01, tmp->realName );
        cpu_compare_and_branch_8bit_const( _environment, tmp->realName, 0, yExpandedLabel, 1 );
        sprite_expand_horizontal_var( _environment, _sprite );

        cpu_label( _environment, yExpandedLabel );
        cpu_and_8bit_const( _environment, gr->realName, 0x02, tmp->realName );
        cpu_compare_and_branch_8bit_const( _environment, tmp->realName, 0, nExpandedLabel, 1 );
        sprite_expand_vertical_var( _environment, _sprite );
        cpu_label( _environment, nExpandedLabel );

    }

    Variable * sx = variable_retrieve( _environment, _sx );
    Variable * sy = variable_retrieve( _environment, _sy );

    // The shortened form (without the target specification ''zx,zy'') simply 
    // positions the sprite in question at the selected coordinate ''sx,sy''.

    sprite_at_vars( _environment, sprite->name, sx->name, sy->name );

    if ( _zx && _zy ) {

        // The instruction ''MMOB'' move a sprite on the screen. It is used to move the 
        // given ''sprite'' from a starting point with the coordinates ''sx,sy'' to a 
        // target point with the coordinates ''zx,zy''. 
        // Like the Simons' Basic, 
        // sprites do not move independently of one another (in an interrupt), 
        // but only one after the other (one ''MMOB'' command controls one sprite, 
        // the next command the next sprite, etc.).

        Variable * zx = variable_retrieve( _environment, _zx );
        Variable * zy = variable_retrieve( _environment, _zy );

        Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
        Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );

        Variable * path = variable_temporary( _environment, VT_PATH, "(path)" );

        variable_move( _environment, create_path( _environment, sx->name, sy->name, zx->name, zy->name )->name, path->name );

        char loopLabel[MAX_TEMPORARY_STORAGE]; sprintf( loopLabel, "%sloop", label );
        char loopDoneLabel[MAX_TEMPORARY_STORAGE]; sprintf( loopDoneLabel, "%sdone", label );

        cpu_label( _environment, loopLabel );

            travel_path( _environment, path->name, x->name, y->name );

            sprite_at_vars( _environment, sprite->name, x->name, y->name );

            cpu_compare_and_branch_16bit_const( _environment, 
                variable_or( 
                    _environment,
                    variable_xor( _environment, x->name, zx->name )->name, 
                    variable_xor( _environment, y->name, zy->name )->name
                )->realName,
                0, loopDoneLabel, 1 );

                // The movement speed is set with ''sp'', with larger values making the sprite
                // move more slowly.

                if ( _sp ) {
                    Variable * sp = variable_retrieve( _environment, _sp );
                    wait_ticks_var( _environment, sp->name );
                } else {
                    wait_ticks( _environment, 1 );
                }

        cpu_jump( _environment, loopLabel );

        cpu_label( _environment, loopDoneLabel );

    }

}

