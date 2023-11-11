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

    Variable * tilemap = variable_retrieve( _environment, _tilemap );
    Variable * dx = variable_temporary( _environment, VT_BYTE, "(dx)");
    Variable * dy = variable_temporary( _environment, VT_BYTE, "(dy)");
    Variable * givenLayer = variable_temporary( _environment, VT_BYTE, "(layer)");

    variable_store( _environment, dx->name, 0 );
    variable_store( _environment, dy->name, 0 );
    variable_store( _environment, givenLayer->name, 0xff );

    if ( tilemap->type != VT_TILEMAP ) {
        CRITICAL_CANNOT_PUT_TILEMAP_FOR_NON_TILEMAP( _tilemap );
    }

    Variable * tileset = variable_retrieve( _environment, tilemap->tileset->name );

    int sizeConst = tilemap->mapWidth * tilemap->mapHeight;
    Variable * size = variable_temporary( _environment, VT_WORD, "(size)");
    variable_store( _environment, size->name, sizeConst );
    
    int screenWidthAsTilesConst = ( _environment->screenWidth / tileset->frameWidth );
    int screenHeightAsTilesConst = ( _environment->screenHeight / tileset->frameHeight );
    // int deltaFrameRow = tilemap->mapWidth > screenWidthAsTiles ? ( tilemap->mapWidth - screenWidthAsTiles ) : 0;
    int deltaFrameConst = tilemap->mapWidth > screenWidthAsTilesConst ? ( tilemap->mapWidth - screenWidthAsTilesConst ) : 0;
    Variable * deltaFrameRow = variable_temporary( _environment, VT_WORD, "(deltaFrameRow)");
    variable_store( _environment, deltaFrameRow->name, deltaFrameConst );
    int deltaFrameScreenConst = sizeConst - ( tilemap->mapWidth * screenHeightAsTilesConst );
    Variable * deltaFrameScreen = variable_temporary( _environment, VT_WORD, "(deltaFrameScreen)");
    variable_store( _environment, deltaFrameScreen->name, deltaFrameScreenConst );
    Variable * mapWidth = variable_temporary( _environment, VT_BYTE, "(map width)");
    variable_store( _environment, mapWidth->name, tilemap->mapWidth );

    Variable * frameWidth = variable_temporary( _environment, VT_BYTE, "(frameWidth)");
    variable_store( _environment, frameWidth->name, tileset->frameWidth );
    Variable * frameHeight = variable_temporary( _environment, VT_BYTE, "(frameHeight)");
    variable_store( _environment, frameHeight->name, tileset->frameHeight );
    
    Variable * index = NULL;

    index = variable_temporary( _environment, VT_WORD, "(index)" );

    // Starting index from 0 (zero).

    variable_store( _environment, index->name, 0 );

    // If a starting point has been given, we must increase the
    // index to match the first tile to draw.

    if ( _dx ) {
        Variable * pdx = variable_retrieve_or_define( _environment, _dx, VT_BYTE, 0 );
        variable_move( _environment, pdx->name, dx->name );
    }
    
    if ( _dy ) {
        Variable * pdy = variable_retrieve_or_define( _environment, _dy, VT_BYTE, 0 );
        variable_move( _environment, pdy->name, dy->name );
    }

    index = variable_add( _environment, index->name, variable_mul( _environment, dy->name, mapWidth->name )->name );
    index = variable_add( _environment, index->name, dx->name );

    if ( _layer ) {
        Variable * player = variable_retrieve_or_define( _environment, _layer, VT_BYTE, 0 );
        variable_move( _environment, player->name, givenLayer->name );
        variable_move( _environment, variable_add( _environment, index->name, variable_mul( _environment, givenLayer->name, size->name )->name )->name, index->name );
    }

    Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );
    Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
    Variable * fx = variable_temporary( _environment, VT_BYTE, "(fx)" );
    Variable * frame = variable_temporary( _environment, VT_BYTE, "(frame)" );
    Variable * padding = variable_temporary( _environment, VT_BYTE, "(padding)" );
    Variable * padding2 = variable_temporary( _environment, VT_BYTE, "(padding2)" );
    Variable * padFrame = variable_temporary( _environment, VT_BYTE, "(pad frame)" );

    if ( _padding_tile ) {
        Variable * paddingTile = variable_retrieve( _environment, _padding_tile );
        variable_move( _environment, paddingTile->name, padFrame->name );
    }

    // For each layer (actually, a normal map has just one layer).

    // for( int layerIndex = 0; layerIndex < tilemap->mapLayers; ++layerIndex ) {
    char labelForLayers[MAX_TEMPORARY_STORAGE]; sprintf( labelForLayers, "%slayersf", label );
    char labelNextLayers[MAX_TEMPORARY_STORAGE]; sprintf( labelNextLayers, "%slayersn", label );
    Variable * mapLayers = variable_temporary( _environment, VT_BYTE, "(mapLayers)" );
    variable_store( _environment, mapLayers->name, tilemap->mapLayers );
    Variable * layerIndex = variable_temporary( _environment, VT_BYTE, "(layerIndex)" );
    variable_store( _environment, layerIndex->name, 0 );

    cpu_label( _environment, labelForLayers );

    cpu_compare_and_branch_8bit( _environment, layerIndex->realName, mapLayers->realName, labelNextLayers, 1 );

    // If a specific layer is selected, we must point to that layer.

        // Let's start from the start of the screen.

        variable_store( _environment, y->name, 0 );

        char labelLoopY[MAX_TEMPORARY_STORAGE]; sprintf( labelLoopY, "%sy", label );
        char labelLoopX[MAX_TEMPORARY_STORAGE]; sprintf( labelLoopX, "%sx", label );
        char labelExit[MAX_TEMPORARY_STORAGE]; sprintf( labelExit, "%se", label );
        char labelExitX[MAX_TEMPORARY_STORAGE]; sprintf( labelExitX, "%sex", label );
        char labelExitX2[MAX_TEMPORARY_STORAGE]; sprintf( labelExitX2, "%sexx", label );
        char labelPadding[MAX_TEMPORARY_STORAGE]; sprintf( labelPadding, "%spad", label );
        char labelPadding2[MAX_TEMPORARY_STORAGE]; sprintf( labelPadding2, "%spady", label );
        char labelDonePutImage[MAX_TEMPORARY_STORAGE]; sprintf( labelDonePutImage, "%sdop", label );
        char labelExitFrame[MAX_TEMPORARY_STORAGE]; sprintf( labelExitFrame, "%sfr", label );
        char labelSkipFxCheck[MAX_TEMPORARY_STORAGE]; sprintf( labelSkipFxCheck, "%sskipx", label );
        char labelSkipIndexCheck[MAX_TEMPORARY_STORAGE]; sprintf( labelSkipIndexCheck, "%sskipy", label );

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

        cpu_move_8bit_indirect2_16bit( _environment, tilemap->realName, index->realName, frame->realName );
        cpu_inc_16bit( _environment, index->realName );

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

        variable_add_inplace_vars( _environment, x->name, frameWidth->name );

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

        variable_add_inplace_vars( _environment, y->name, frameHeight->name );

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

        cpu_compare_and_branch_8bit_const( _environment, givenLayer->realName, 0xff, labelNextLayers, 0 );

        cpu_inc( _environment, layerIndex->realName );

        // if ( deltaFrameScreen ) {
            variable_add_inplace_vars( _environment, index->name, deltaFrameScreen->name );
        // }

        _flags = _flags | FLAG_TRANSPARENCY;

        cpu_jump( _environment, labelForLayers );
    // }

    cpu_label( _environment, labelNextLayers );

}

