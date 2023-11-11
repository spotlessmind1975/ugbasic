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

The command ''PUT TILEMAP'' can be used to draw a map on the screen. Note how the same map draws the
same way on different screens. The map is however within the available screen size. If the 
map is bigger than the screen, the comamnd only draws a part of the map. To scroll the map you 
can use the ''FROM'' parameter with the offsets (in terms of tiles) starting from which the map will 
have to be drawn on the screen.

@italian

@syntax PUT TILEMAP resource [ FROM x, y ]

@example PUT TILEMAP map

@target all
</usermanual> */

void put_tilemap_vars( Environment * _environment, char * _tilemap, int _flags, char * _dx, char * _dy, char * _layer, char * _padding_tile ) {

    MAKE_LABEL

    Variable * paddingTile = NULL;
    if ( _padding_tile ) {
        paddingTile = variable_retrieve( _environment, _padding_tile );
    }
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

    int sizeConst = tilemap->mapWidth * tilemap->mapHeight;
    Variable * size = variable_temporary( _environment, VT_WORD, "(size)");
    variable_store( _environment, size->name, sizeConst );
    
    int screenWidthAsTiles = ( _environment->screenWidth / tileset->frameWidth );
    int screenHeightAsTiles = ( _environment->screenHeight / tileset->frameHeight );
    // int deltaFrameRow = tilemap->mapWidth > screenWidthAsTiles ? ( tilemap->mapWidth - screenWidthAsTiles ) : 0;
    int deltaFrameConst = tilemap->mapWidth > screenWidthAsTiles ? ( tilemap->mapWidth - screenWidthAsTiles ) : 0;
    Variable * deltaFrameRow = variable_temporary( _environment, VT_WORD, "(deltaFrameRow)");
    variable_store( _environment, deltaFrameRow->name, deltaFrameConst );
    int deltaFrameScreen = sizeConst - ( tilemap->mapWidth * screenHeightAsTiles );

    Variable * index = NULL;

    if ( tilemap->size > 255 ) {
        index = variable_temporary( _environment, VT_WORD, "(index)" );
    } else {
        index = variable_temporary( _environment, VT_BYTE, "(index)" );
    }

    // Starting index from 0 (zero).

    variable_store( _environment, index->name, 0 );

    // If a starting point has been given, we must increase the
    // index to match the first tile to draw.

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

    // Set up the padding tile.

    if ( paddingTile ) {
        variable_move( _environment, paddingTile->name, padFrame->name );
    }

    // For each layer (actually, a normal map has just one layer).

    for( int layerIndex = 0; layerIndex < tilemap->mapLayers; ++layerIndex ) {

        // If a specific layer is selected, we must point to that layer.

        if ( _layer ) {
            // Variable * sizeSize = variable_temporary( _environment, VT_WORD, "(size)");
            // variable_store( _environment, sizeSize->name, size );
            variable_move( _environment, variable_add( _environment, index->name, variable_mul( _environment, layer->name, size->name )->name )->name, index->name );
        }

        // Let's start from the start of the screen.

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

        // Disable vertical padding.

        variable_store( _environment, padding2->name, 0 );

        // --------------------------------------------------------------------------
        // Y loop
        // --------------------------------------------------------------------------

        cpu_label( _environment, labelLoopY );

        // Let's start from the left from the screen.

        variable_store( _environment, x->name, 0 );

        // Set the count of frames drawed on the horizontal
        // line to zero (0).

        variable_store( _environment, fx->name, 0 );

        // If a delta position is given, the count of horizontal frames
        // drawed must be increased by delta position.

        if ( dx ) {
            variable_move( _environment, dx->name, fx->name );
        }

        // Disable horizontal padding.

        variable_store( _environment, padding->name, 0 );

        // --------------------------------------------------------------------------
        // Begin X loop
        // --------------------------------------------------------------------------

        cpu_label( _environment, labelLoopX );

        // If the horizontal padding is enabled, we must skip to draw the padding tile.

        cpu_compare_and_branch_8bit_const(  _environment, padding->realName, 1, labelPadding, 1 );

        // If the vertical padding is enabled, we must skip to draw the padding tile.

        cpu_compare_and_branch_8bit_const(  _environment, padding2->realName, 1, labelPadding, 1 );

        // Take the tile from the map and increase the index.

        if ( tilemap->size > 255 ) {
            cpu_move_8bit_indirect2_16bit( _environment, tilemap->realName, index->realName, frame->realName );
            cpu_inc_16bit( _environment, index->realName );
        } else {
            cpu_move_8bit_indirect2_8bit( _environment, tilemap->realName, index->realName, frame->realName );
            cpu_inc( _environment, index->realName );
        }

        // In case the frame read from the map is 0xff, it means that that specific
        // frame has not to be drawn, so we exit from this frame drawing.

        cpu_compare_and_branch_8bit_const(  _environment, frame->realName, 0xff, labelExitFrame, 1 );

        // --- DRAW TILE --

        put_image( _environment, tileset->name, x->name, y->name, NULL, NULL, frame->name, NULL,  _flags );
        cpu_jump( _environment, labelDonePutImage );

        // --- DRAW PADDING TILE --

        cpu_label( _environment, labelPadding );
        put_image( _environment, tileset->name, x->name, y->name, NULL, NULL, padFrame->name, NULL,  _flags );

        // From here and ahead, we drawed the tile so we must calculate the
        // next conditions and actions to do. We arrive here both if we drawed
        // a TILE, a PADDING TILE or if we skipped the drawing.

        cpu_label( _environment, labelDonePutImage ); cpu_label( _environment, labelExitFrame );

        // Increase the horizontal frames drawed count.

        cpu_inc( _environment, fx->realName );

        // Increase the next X position to draw to.

        variable_add_inplace( _environment, x->name, tileset->frameWidth );

        // If the horizontal padding is enabled, we must move to the skip fx check,
        // since the horizontal padding is enabled by reaching the horizontal limit.

        cpu_compare_and_branch_8bit_const(  _environment, padding->realName, 1, labelSkipFxCheck, 1 );

        // We must check if the horizontal limit is reached. In this case, we must
        // enable horizontal padding by moving to the specific routine.

        Variable * check = variable_less_than_const( _environment, fx->name, tilemap->mapWidth, 0 );
        cpu_compare_and_branch_8bit_const(  _environment, check->realName, 0x0, labelExitX, 1 );

        // Both if the horizontal limit has been reached or not, we must check if the
        // screen limit has been reached. If the screen limit has not been reached,
        // we must repeat the X loop. Otherwise, we exit from the X loop.

        cpu_label( _environment, labelSkipFxCheck );
        check = variable_less_than_const( _environment, x->name, ( _environment->screenWidth), 0 );
        cpu_compare_and_branch_8bit_const(  _environment, check->realName, 0xff, labelLoopX, 1 );
        cpu_jump( _environment, labelExitX2 );

        // --- ENABLE HORIZONTAL PADDING ---
        cpu_label( _environment, labelExitX );
        variable_store( _environment, padding->name, 1 );
        cpu_jump( _environment, labelSkipFxCheck );

        // --------------------------------------------------------------------------
        // End X loop
        // --------------------------------------------------------------------------

        cpu_label( _environment, labelExitX2 );

        // Disable horizontal padding.

        variable_store( _environment, padding->name, 0 );

        // If the screen is narrower than the map, we must move ahead the
        // index by the calculated delta frame row.

        // if ( deltaFrameRow > 0 ) {
            variable_add_inplace_vars( _environment, index->name, deltaFrameRow->name );
        // }

        // Move to the next row to draw.

        variable_add_inplace( _environment, y->name, tileset->frameHeight );

        // If we reach the limit of ther map size, we enable the vertical padding.
        
        check = variable_less_than_const( _environment, index->name, tilemap->size, 0 );
        cpu_compare_and_branch_8bit_const(  _environment, check->realName, 0x00, labelPadding2, 1 );

        // Both if the vertical padding is enabled or not, we must check if the
        // screen vertical limit has been reached. If not, we repeat the Y loop.

        cpu_label( _environment, labelSkipIndexCheck );
        check = variable_less_than_const( _environment, y->name, (_environment->screenHeight ), 0 );
        cpu_compare_and_branch_8bit_const(  _environment, check->realName, 0xff, labelLoopY, 1 );
        cpu_jump( _environment, labelExit );

        // --- ENABLE VERTICAL PADDING ---
        cpu_label( _environment, labelPadding2 );
        variable_store( _environment, padding2->name, 1 );
        cpu_jump( _environment, labelSkipIndexCheck );

        // --------------------------------------------------------------------------
        // End Y loop
        // --------------------------------------------------------------------------

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

void put_tilemap_inline( Environment * _environment, char * _tilemap, int _flags, char * _dx, char * _dy, char * _layer, int _padding_tile ) {

    MAKE_LABEL

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

    // Starting index from 0 (zero).

    variable_store( _environment, index->name, 0 );

    // If a starting point has been given, we must increase the
    // index to match the first tile to draw.

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

    // Set up the padding tile.

    variable_store( _environment, padFrame->name, _padding_tile );

    // For each layer (actually, a normal map has just one layer).

    for( int layerIndex = 0; layerIndex < tilemap->mapLayers; ++layerIndex ) {

        // If a specific layer is selected, we must point to that layer.

        if ( _layer ) {
            Variable * sizeSize = variable_temporary( _environment, VT_WORD, "(size)");
            variable_store( _environment, sizeSize->name, size );
            variable_move( _environment, variable_add( _environment, index->name, variable_mul( _environment, layer->name, sizeSize->name )->name )->name, index->name );
        }

        // Let's start from the start of the screen.

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

        // Disable vertical padding.

        variable_store( _environment, padding2->name, 0 );

        // --------------------------------------------------------------------------
        // Y loop
        // --------------------------------------------------------------------------

        cpu_label( _environment, labelLoopY );

        // Let's start from the left from the screen.

        variable_store( _environment, x->name, 0 );

        // Set the count of frames drawed on the horizontal
        // line to zero (0).

        variable_store( _environment, fx->name, 0 );

        // If a delta position is given, the count of horizontal frames
        // drawed must be increased by delta position.

        if ( dx ) {
            variable_move( _environment, dx->name, fx->name );
        }

        // Disable horizontal padding.

        variable_store( _environment, padding->name, 0 );

        // --------------------------------------------------------------------------
        // Begin X loop
        // --------------------------------------------------------------------------

        cpu_label( _environment, labelLoopX );

        // If the horizontal padding is enabled, we must skip to draw the padding tile.

        cpu_compare_and_branch_8bit_const(  _environment, padding->realName, 1, labelPadding, 1 );

        // If the vertical padding is enabled, we must skip to draw the padding tile.

        cpu_compare_and_branch_8bit_const(  _environment, padding2->realName, 1, labelPadding, 1 );

        // Take the tile from the map and increase the index.

        if ( tilemap->size > 255 ) {
            cpu_move_8bit_indirect2_16bit( _environment, tilemap->realName, index->realName, frame->realName );
            cpu_inc_16bit( _environment, index->realName );
        } else {
            cpu_move_8bit_indirect2_8bit( _environment, tilemap->realName, index->realName, frame->realName );
            cpu_inc( _environment, index->realName );
        }

        // In case the frame read from the map is 0xff, it means that that specific
        // frame has not to be drawn, so we exit from this frame drawing.

        cpu_compare_and_branch_8bit_const(  _environment, frame->realName, 0xff, labelExitFrame, 1 );

        // --- DRAW TILE --

        put_image( _environment, tileset->name, x->name, y->name, NULL, NULL, frame->name, NULL,  _flags );
        cpu_jump( _environment, labelDonePutImage );

        // --- DRAW PADDING TILE --

        cpu_label( _environment, labelPadding );
        put_image( _environment, tileset->name, x->name, y->name, NULL, NULL, padFrame->name, NULL,  _flags );

        // From here and ahead, we drawed the tile so we must calculate the
        // next conditions and actions to do. We arrive here both if we drawed
        // a TILE, a PADDING TILE or if we skipped the drawing.

        cpu_label( _environment, labelDonePutImage ); cpu_label( _environment, labelExitFrame );

        // Increase the horizontal frames drawed count.

        cpu_inc( _environment, fx->realName );

        // Increase the next X position to draw to.

        variable_add_inplace( _environment, x->name, tileset->frameWidth );

        // If the horizontal padding is enabled, we must move to the skip fx check,
        // since the horizontal padding is enabled by reaching the horizontal limit.

        cpu_compare_and_branch_8bit_const(  _environment, padding->realName, 1, labelSkipFxCheck, 1 );

        // We must check if the horizontal limit is reached. In this case, we must
        // enable horizontal padding by moving to the specific routine.

        Variable * check = variable_less_than_const( _environment, fx->name, tilemap->mapWidth, 0 );
        cpu_compare_and_branch_8bit_const(  _environment, check->realName, 0x0, labelExitX, 1 );

        // Both if the horizontal limit has been reached or not, we must check if the
        // screen limit has been reached. If the screen limit has not been reached,
        // we must repeat the X loop. Otherwise, we exit from the X loop.

        cpu_label( _environment, labelSkipFxCheck );
        check = variable_less_than_const( _environment, x->name, ( _environment->screenWidth), 0 );
        cpu_compare_and_branch_8bit_const(  _environment, check->realName, 0xff, labelLoopX, 1 );
        cpu_jump( _environment, labelExitX2 );

        // --- ENABLE HORIZONTAL PADDING ---
        cpu_label( _environment, labelExitX );
        variable_store( _environment, padding->name, 1 );
        cpu_jump( _environment, labelSkipFxCheck );

        // --------------------------------------------------------------------------
        // End X loop
        // --------------------------------------------------------------------------

        cpu_label( _environment, labelExitX2 );

        // Disable horizontal padding.

        variable_store( _environment, padding->name, 0 );

        // If the screen is narrower than the map, we must move ahead the
        // index by the calculated delta frame row.

        if ( deltaFrameRow > 0 ) {
            variable_add_inplace( _environment, index->name, deltaFrameRow );
        }

        // Move to the next row to draw.

        variable_add_inplace( _environment, y->name, tileset->frameHeight );

        // If we reach the limit of ther map size, we enable the vertical padding.
        
        check = variable_less_than_const( _environment, index->name, tilemap->size, 0 );
        cpu_compare_and_branch_8bit_const(  _environment, check->realName, 0x00, labelPadding2, 1 );

        // Both if the vertical padding is enabled or not, we must check if the
        // screen vertical limit has been reached. If not, we repeat the Y loop.

        cpu_label( _environment, labelSkipIndexCheck );
        check = variable_less_than_const( _environment, y->name, (_environment->screenHeight ), 0 );
        cpu_compare_and_branch_8bit_const(  _environment, check->realName, 0xff, labelLoopY, 1 );
        cpu_jump( _environment, labelExit );

        // --- ENABLE VERTICAL PADDING ---
        cpu_label( _environment, labelPadding2 );
        variable_store( _environment, padding2->name, 1 );
        cpu_jump( _environment, labelSkipIndexCheck );

        // --------------------------------------------------------------------------
        // End Y loop
        // --------------------------------------------------------------------------

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