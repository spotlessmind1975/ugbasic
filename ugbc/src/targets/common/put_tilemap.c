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

void put_tilemap( Environment * _environment, char * _tilemap, int _flags, char * _dx, char * _dy, char * _layer, int _padding_tile ) {

    MAKE_LABEL

    outline0("; put_tilemap" );

    Variable * tilemap = variable_retrieve( _environment, _tilemap );
    Variable * dx = NULL;
    Variable * dy = NULL;
    Variable * layer = NULL;

    if ( _dx ) {
        dx = variable_retrieve_or_define( _environment, _dx, VT_BYTE, 0 );
    }
    
    if ( _dy ) {
        dy = variable_retrieve_or_define( _environment, _dy, VT_BYTE, 0 );
    }

    if ( _layer ) {
        layer = variable_retrieve( _environment, _layer );
    }

    if ( tilemap->type != VT_TILEMAP ) {
        CRITICAL_CANNOT_PUT_TILEMAP_FOR_NON_TILEMAP( _tilemap );
    }

    Variable * tileset = variable_retrieve( _environment, tilemap->tileset->name );

    int size = tilemap->mapWidth * tilemap->mapHeight;
    int screenWidthAsTiles = ( _environment->screenWidth / tileset->frameWidth );
    int screenHeightAsTiles = ( _environment->screenHeight / tileset->frameHeight );
    int deltaFrameRow = tilemap->mapWidth > screenWidthAsTiles ? ( tilemap->mapWidth - screenWidthAsTiles ) : 0;
    int deltaFrameScreen = size - ( tilemap->mapWidth * screenHeightAsTiles );

    Variable * index = NULL;

    if ( tilemap->size > 255 ) {
        index = variable_temporary( _environment, VT_WORD, "(index)" );
    } else {
        index = variable_temporary( _environment, VT_BYTE, "(index)" );
    }

    variable_store( _environment, index->name, 0 );

    if ( dx && dy ) {
        Variable * mapWidth = variable_temporary( _environment, VT_BYTE, "(map width)");
        variable_store( _environment, mapWidth->name, tilemap->mapWidth );
        index = variable_add( _environment, index->name, variable_mul( _environment, dy->name, mapWidth->name )->name );
        index = variable_add( _environment, index->name, dx->name );
    }

    Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );
    Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
    Variable * fx = variable_temporary( _environment, VT_BYTE, "(fx)" );
    Variable * frame = variable_temporary( _environment, VT_BYTE, "(frame)" );
    Variable * padding = variable_temporary( _environment, VT_BYTE, "(padding)" );
    Variable * padding2 = variable_temporary( _environment, VT_BYTE, "(padding2)" );
    Variable * padFrame = variable_temporary( _environment, VT_BYTE, "(pad frame)" );

    variable_store( _environment, padFrame->name, _padding_tile );

    for( int layerIndex = 0; layerIndex < tilemap->mapLayers; ++layerIndex ) {

        if ( _layer ) {
            Variable * sizeSize = variable_temporary( _environment, VT_WORD, "(size)");
            variable_store( _environment, sizeSize->name, size );
            index = variable_add( _environment, index->name, variable_mul( _environment, layer->name, sizeSize->name )->name );
        }

        variable_store( _environment, y->name, 0 );

        char labelLoopY[MAX_TEMPORARY_STORAGE]; sprintf( labelLoopY, "%sy%4.4x", label, layerIndex );
        char labelLoopX[MAX_TEMPORARY_STORAGE]; sprintf( labelLoopX, "%sx%4.4x", label, layerIndex );
        char labelExit[MAX_TEMPORARY_STORAGE]; sprintf( labelExit, "%se%4.4x", label, layerIndex );
        char labelExitX[MAX_TEMPORARY_STORAGE]; sprintf( labelExitX, "%sex%4.4x", label, layerIndex );
        char labelExitX2[MAX_TEMPORARY_STORAGE]; sprintf( labelExitX2, "%sexx%4.4x", label, layerIndex );
        char labelPadding[MAX_TEMPORARY_STORAGE]; sprintf( labelPadding, "%spad%4.4x", label, layerIndex );
        char labelPadding2[MAX_TEMPORARY_STORAGE]; sprintf( labelPadding2, "%spady%4.4x", label, layerIndex );
        char labelDonePutImage[MAX_TEMPORARY_STORAGE]; sprintf( labelDonePutImage, "%sdop%4.4x", label, layerIndex );
        char labelExitFrame[MAX_TEMPORARY_STORAGE]; sprintf( labelExitFrame, "%sfr%4.4x", label, layerIndex );
        char labelSkipFxCheck[MAX_TEMPORARY_STORAGE]; sprintf( labelSkipFxCheck, "%sskipx%4.4x", label, layerIndex );
        char labelSkipIndexCheck[MAX_TEMPORARY_STORAGE]; sprintf( labelSkipIndexCheck, "%sskipy%4.4x", label, layerIndex );

        variable_store( _environment, padding2->name, 0 );

        cpu_label( _environment, labelLoopY );
        variable_store( _environment, x->name, 0 );
        variable_store( _environment, fx->name, 0 );
        variable_move( _environment, dx->name, fx->name );
        variable_store( _environment, padding->name, 0 );
        cpu_label( _environment, labelLoopX );
        cpu_compare_and_branch_8bit_const(  _environment, padding->realName, 1, labelPadding, 1 );
        if ( tilemap->size > 255 ) {
            cpu_move_8bit_indirect2_16bit( _environment, tilemap->realName, index->realName, frame->realName );
            cpu_inc_16bit( _environment, index->realName );
        } else {
            cpu_move_8bit_indirect2_8bit( _environment, tilemap->realName, index->realName, frame->realName );
            cpu_inc( _environment, index->realName );
        }
        cpu_compare_and_branch_8bit_const(  _environment, padding2->realName, 1, labelPadding, 1 );
        cpu_compare_and_branch_8bit_const(  _environment, frame->realName, 0xff, labelExitFrame, 1 );
        put_image( _environment, tileset->name, x->name, y->name, frame->name, NULL,  _flags );
        cpu_jump( _environment, labelDonePutImage );
        cpu_label( _environment, labelPadding );
        put_image( _environment, tileset->name, x->name, y->name, padFrame->name, NULL,  _flags );
        cpu_label( _environment, labelDonePutImage );
        cpu_label( _environment, labelExitFrame );
        cpu_inc( _environment, fx->realName );
        variable_add_inplace( _environment, x->name, tileset->frameWidth );
        cpu_compare_and_branch_8bit_const(  _environment, padding->realName, 1, labelSkipFxCheck, 1 );
        Variable * check = variable_less_than_const( _environment, fx->name, tilemap->mapWidth, 0 );
        cpu_compare_and_branch_8bit_const(  _environment, check->realName, 0x0, labelExitX, 1 );
        cpu_label( _environment, labelSkipFxCheck );
        check = variable_less_than_const( _environment, x->name, ( _environment->screenWidth), 0 );
        cpu_compare_and_branch_8bit_const(  _environment, check->realName, 0xff, labelLoopX, 1 );
        cpu_jump( _environment, labelExitX2 );
        cpu_label( _environment, labelExitX );
        variable_store( _environment, padding->name, 1 );
        cpu_jump( _environment, labelSkipFxCheck );
        cpu_label( _environment, labelExitX2 );
        variable_store( _environment, padding->name, 0 );
        if ( deltaFrameRow ) {
            variable_add_inplace( _environment, index->name, deltaFrameRow );
        }
        variable_add_inplace( _environment, y->name, tileset->frameHeight );
        check = variable_less_than_const( _environment, index->name, tilemap->size, 0 );
        cpu_compare_and_branch_8bit_const(  _environment, check->realName, 0x00, labelPadding2, 1 );
        cpu_label( _environment, labelSkipIndexCheck );
        check = variable_less_than_const( _environment, y->name, (_environment->screenHeight ), 0 );
        cpu_compare_and_branch_8bit_const(  _environment, check->realName, 0xff, labelLoopY, 1 );
        cpu_jump( _environment, labelExit );
        cpu_label( _environment, labelPadding2 );
        variable_store( _environment, padding2->name, 1 );
        cpu_jump( _environment, labelSkipIndexCheck );
        cpu_label( _environment, labelExit );

        if ( _layer ) {
            break;
        }
        if ( deltaFrameScreen ) {
            variable_add_inplace( _environment, index->name, deltaFrameScreen );
        }

        _flags = _flags | FLAG_TRANSPARENCY;

    }

}