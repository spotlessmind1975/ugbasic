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

extern char DATATYPE_AS_STRING[][16];

/**
 * @brief Emit ASM code for <b>PUT TILEMAP [tilemap]</b>
 * 
 * This function outputs a code that draws an image on a bitmap. 
 * 
 * @param _environment Current calling environment
 * @param _tilemap Tilemap to draw
 */
/* <usermanual>
@keyword PUT TILEMAP

@english

@italian

@syntax PUT TILEMAP [tilemap]

@example PUT TILEMAP map

@target all
</usermanual> */

void put_tilemap( Environment * _environment, char * _tilemap, int _flags ) {

    MAKE_LABEL

    Variable * tilemap = variable_retrieve( _environment, _tilemap );

    if ( tilemap->type != VT_TILEMAP ) {
        CRITICAL_CANNOT_PUT_TILEMAP_FOR_NON_TILEMAP( _tilemap );
    }

    Variable * tileset = variable_retrieve( _environment, tilemap->tileset->name );

    int size = tilemap->mapWidth * tilemap->mapHeight;
    int screenWidthAsTiles = ( _environment->screenWidth / tileset->frameWidth );
    int deltaFrame = tilemap->mapWidth > screenWidthAsTiles ? ( tilemap->mapWidth - screenWidthAsTiles ) : 0;

    Variable * index = variable_temporary( _environment, VT_BYTE, "(index)" );

    variable_store( _environment, index->name, 0 );

    Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );
    Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
    Variable * fx = variable_temporary( _environment, VT_BYTE, "(fx)" );
    Variable * frame = variable_temporary( _environment, VT_BYTE, "(frame)" );

    variable_store( _environment, y->name, 0 );

    char labelLoopY[MAX_TEMPORARY_STORAGE]; sprintf( labelLoopY, "%sy", label );
    char labelLoopX[MAX_TEMPORARY_STORAGE]; sprintf( labelLoopX, "%sx", label );
    char labelExit[MAX_TEMPORARY_STORAGE]; sprintf( labelExit, "%se", label );
    char labelExitX[MAX_TEMPORARY_STORAGE]; sprintf( labelExitX, "%sex", label );

    cpu_label( _environment, labelLoopY );
    variable_store( _environment, x->name, 0 );
    variable_store( _environment, fx->name, 0 );
    cpu_label( _environment, labelLoopX );
    cpu_move_8bit_indirect2_8bit( _environment, tilemap->realName, index->realName, frame->realName );
    put_image( _environment, tileset->name, x->name, y->name, frame->name, NULL,  _flags );
    cpu_inc( _environment, index->realName );
    cpu_inc( _environment, fx->realName );
    variable_add_inplace( _environment, x->name, tileset->frameWidth );
    Variable * check = variable_less_than_const( _environment, fx->name, tilemap->mapWidth, 0 );
    cpu_compare_and_branch_8bit_const(  _environment, check->realName, 0x0, labelExitX, 1 );
    check = variable_less_than_const( _environment, x->name, _environment->screenWidth, 0 );
    cpu_compare_and_branch_8bit_const(  _environment, check->realName, 0xff, labelLoopX, 1 );
    cpu_label( _environment, labelExitX );
    if ( deltaFrame ) {
        variable_add_inplace( _environment, frame->name, deltaFrame );
    }
    variable_add_inplace( _environment, y->name, tileset->frameHeight );
    check = variable_less_than_const( _environment, index->name, size, 0 );
    cpu_compare_and_branch_8bit_const(  _environment, check->realName, 0x00, labelExit, 1 );
    check = variable_less_than_const( _environment, y->name, _environment->screenHeight, 0 );
    cpu_compare_and_branch_8bit_const(  _environment, check->realName, 0xff, labelLoopY, 1 );
    cpu_label( _environment, labelExit );

}