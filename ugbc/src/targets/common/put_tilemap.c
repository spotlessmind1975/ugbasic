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

void put_tilemap_vars( Environment * _environment, char * _tilemap, int _flags, char * _dx, char * _dy, char * _layer, char * _pad_frame ) {

    deploy_begin( put_tilemap );

        MAKE_LABEL

        // Labels
        char labelForLayers[MAX_TEMPORARY_STORAGE]; sprintf( labelForLayers, "%slayersf", label );
        char labelNextLayers[MAX_TEMPORARY_STORAGE]; sprintf( labelNextLayers, "%slayersn", label );
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

        // Local constants
        Variable * transparency = variable_temporary( _environment, VT_WORD, "(flags)" );
        variable_store( _environment, transparency->name, FLAG_TRANSPARENCY );

        // Parameters
        Variable * tilemapAddress = variable_define( _environment, "puttilemap__tilemap", VT_ADDRESS, 0 );
        Variable * tilesetAddress = variable_define( _environment, "puttilemap__tileset", VT_ADDRESS, 0 );
        Variable * dx = variable_define( _environment, "puttilemap__dx", VT_BYTE, 0 );
        Variable * dy = variable_define( _environment, "puttilemap__dy", VT_BYTE, 0 );
        Variable * layer = variable_define( _environment, "puttilemap__layer", VT_BYTE, 0 );
        Variable * flags = variable_define( _environment, "puttilemap__flags", VT_WORD, 0 );
        Variable * size = variable_define( _environment, "puttilemap__size", VT_WORD, 0 );
        Variable * deltaFrameRow = variable_define( _environment, "puttilemap__deltaFrameRow", VT_WORD, 0 );
        Variable * deltaFrameScreen = variable_define( _environment, "puttilemap__deltaFrameScreen", VT_WORD, 0 );
        Variable * mapWidth = variable_define( _environment, "puttilemap__mapWidth", VT_BYTE, 0 );
        Variable * frameWidth = variable_define( _environment, "puttilemap__frameWidth", VT_BYTE, 0 );
        Variable * frameHeight = variable_define( _environment, "puttilemap__frameHeight", VT_BYTE, 0 );
        Variable * padFrame = variable_define( _environment, "puttilemap__padFrame", VT_BYTE, 0 );
        Variable * mapLayers = variable_define( _environment, "puttilemap__mapLayers", VT_BYTE, 0 );
        Variable * offsetFrameRoutine = variable_define( _environment, "puttilemap__offsetFrameRoutine", VT_ADDRESS, 0 );

        // Local variables
        Variable * index = variable_temporary( _environment, VT_WORD, "(index)" );
        Variable * y = variable_temporary( _environment, VT_POSITION, "(y)" );
        Variable * x = variable_temporary( _environment, VT_POSITION, "(x)" );
        Variable * fx = variable_temporary( _environment, VT_BYTE, "(fx)" );
        Variable * frame = variable_temporary( _environment, VT_BYTE, "(frame)" );
        Variable * padding = variable_temporary( _environment, VT_BYTE, "(padding)" );
        Variable * padding2 = variable_temporary( _environment, VT_BYTE, "(padding2)" );
        Variable * layerIndex = variable_temporary( _environment, VT_BYTE, "(layerIndex)" );

        // Starting index from 0 (zero).
        variable_store( _environment, index->name, 0 );

        // Starting layer from 0 (zero).
        variable_store( _environment, layerIndex->name, 0 );

        // If a starting point has been given, we must increase the
        // index to match the first tile to draw.
        variable_move( _environment, variable_add( _environment, index->name, variable_mul( _environment, dy->name, mapWidth->name )->name )->name, index->name );
        variable_move( _environment, variable_add( _environment, index->name, dx->name )->name, index->name );

        // If a layer has been given, we must increate the index to match
        // the first tile of the layer to draw.
        variable_move( _environment, variable_add( _environment, index->name, variable_mul( _environment, layer->name, size->name )->name )->name, index->name );

        // *** Add index to the tile address
        cpu_math_add_16bit( _environment, tilemapAddress->realName, index->realName, tilemapAddress->realName );

        // For each layer (actually, a normal map has just one layer).
        // for( int layerIndex = 0; layerIndex < tilemap->mapLayers; ++layerIndex ) {
        cpu_label( _environment, labelForLayers );

            // If a specific layer is selected, we must point to that layer.
            // Let's start from the start of the screen.

            variable_store( _environment, y->name, 0 );

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

            // variable_store( _environment, fx->name, 0 );

            // If a delta position is given, the count of horizontal frames
            // drawed must be increased by delta position.

            variable_move( _environment, dx->name, fx->name );

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

            cpu_peek( _environment, tilemapAddress->realName, frame->realName );
            cpu_inc_16bit( _environment, tilemapAddress->realName );
            cpu_inc_16bit( _environment, index->realName );

            // In case the frame read from the map is 0xff, it means that that specific
            // frame has not to be drawn, so we exit from this frame drawing.

            cpu_compare_and_branch_8bit_const(  _environment, frame->realName, 0xff, labelExitFrame, 1 );

            // --- DRAW TILE --

            put_image_vars( _environment, tilesetAddress->name, x->name, y->name, NULL, NULL, frame->name, NULL,  flags->name );
            cpu_jump( _environment, labelDonePutImage );

            // --- DRAW PADDING TILE --

            cpu_label( _environment, labelPadding );
            put_image_vars( _environment, tilesetAddress->name, x->name, y->name, NULL, NULL, padFrame->name, NULL, flags->name );

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

            Variable * check = variable_less_than( _environment, fx->name, mapWidth->name, 0 );
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
                variable_add_inplace_vars( _environment, tilemapAddress->name, deltaFrameRow->name );
                variable_add_inplace_vars( _environment, index->name, deltaFrameRow->name );
            // }

            // Move to the next row to draw.

            variable_add_inplace_vars( _environment, y->name, frameHeight->name );

            // If we reach the limit of ther map size, we enable the vertical padding.
            
            check = variable_less_than( _environment, index->name, size->name, 0 );
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

            cpu_compare_and_branch_8bit_const( _environment, layer->realName, 0xff, labelNextLayers, 0 );

            cpu_inc( _environment, layerIndex->realName );
            cpu_compare_and_branch_8bit( _environment, layerIndex->realName, mapLayers->realName, labelNextLayers, 1 );

            // if ( deltaFrameScreen ) {
                variable_add_inplace_vars( _environment, tilemapAddress->name, deltaFrameScreen->name );
                variable_add_inplace_vars( _environment, index->name, deltaFrameScreen->name );
            // }

            // _flags = _flags | FLAG_TRANSPARENCY;
            variable_move( _environment, 
                    variable_or( _environment, flags->name, transparency->name )->name, 
                    flags->name
                );

            cpu_jump( _environment, labelForLayers );
        // }

        cpu_label( _environment, labelNextLayers );

        cpu_return( _environment );

        cpu_label( _environment, "_puttilemap__tilesetoffsetframe" );

        cpu_call_indirect( _environment, "_puttilemap__offsetFrameRoutine" );

        cpu_return( _environment );

    deploy_end( put_tilemap );

    Variable * ptilemap = variable_retrieve( _environment, _tilemap );
    if ( ptilemap->type != VT_TILEMAP ) {
        CRITICAL_CANNOT_PUT_TILEMAP_FOR_NON_TILEMAP( _tilemap );
    }
    Variable * vtilemap = variable_retrieve( _environment, "puttilemap__tilemap" );
    cpu_addressof_16bit( _environment, ptilemap->realName, vtilemap->realName );

    Variable * ptileset = variable_retrieve( _environment, ptilemap->tileset->name );
    Variable * vtileset = variable_retrieve( _environment, "puttilemap__tileset" );
    cpu_addressof_16bit( _environment, ptileset->realName, vtileset->realName );

    Variable * vdx = variable_retrieve( _environment, "puttilemap__dx" );
    if ( _dx ) {
        Variable * pdx = variable_retrieve( _environment, _dx );
        variable_move( _environment, pdx->name, vdx->name );
    } else {
        variable_store( _environment, vdx->name, 0 );
    }

    Variable * vdy = variable_retrieve( _environment, "puttilemap__dy" );
    if ( _dy ) {
        Variable * pdy = variable_retrieve( _environment, _dy );
        variable_move( _environment, pdy->name, vdy->name );
    } else {
        variable_store( _environment, vdy->name, 0 );
    }

    Variable * vlayer = variable_retrieve( _environment, "puttilemap__layer" );
    if ( _layer ) {
        Variable * player = variable_retrieve( _environment, _layer );
        variable_move( _environment, player->name, vlayer->name );
    } else {
        variable_store( _environment, vlayer->name, 0x80 );
    }

    Variable * vflags = variable_retrieve( _environment, "puttilemap__flags" );
    variable_store( _environment, vflags->name, _flags );

    Variable * vpadFrame = variable_retrieve( _environment, "puttilemap__padFrame" );
    if ( _pad_frame ) {
        Variable * ppadFrame = variable_retrieve( _environment, _pad_frame );
        variable_move( _environment, ppadFrame->name, vpadFrame->name );
    } else {
        variable_store( _environment, vpadFrame->name, 0 );
    }

    int sizeConst = ptilemap->mapWidth * ptilemap->mapHeight;
    Variable * vsize = variable_retrieve( _environment, "puttilemap__size" );
    variable_store( _environment, vsize->name, sizeConst );

    int screenWidthAsTilesConst = ( _environment->screenWidth / ptileset->frameWidth );
    int screenHeightAsTilesConst = ( _environment->screenHeight / ptileset->frameHeight );
    // int deltaFrameRow = tilemap->mapWidth > screenWidthAsTiles ? ( tilemap->mapWidth - screenWidthAsTiles ) : 0;
    int deltaFrameConst = ptilemap->mapWidth > screenWidthAsTilesConst ? ( ptilemap->mapWidth - screenWidthAsTilesConst ) : 0;
    Variable * vdeltaFrameRow = variable_retrieve( _environment, "puttilemap__deltaFrameRow" );
    variable_store( _environment, vdeltaFrameRow->name, deltaFrameConst );

    int deltaFrameScreenConst = sizeConst - ( ptilemap->mapWidth * screenHeightAsTilesConst );
    Variable * vdeltaFrameScreen = variable_retrieve( _environment, "puttilemap__deltaFrameScreen" );
    variable_store( _environment, vdeltaFrameScreen->name, deltaFrameScreenConst );

    Variable * vmapWidth = variable_retrieve( _environment, "puttilemap__mapWidth" );
    variable_store( _environment, vmapWidth->name, ptilemap->mapWidth );

    Variable * vframeWidth = variable_retrieve( _environment, "puttilemap__frameWidth" );
    variable_store( _environment, vframeWidth->name, ptileset->frameWidth );

    Variable * vframeHeight = variable_retrieve( _environment, "puttilemap__frameHeight" );
    variable_store( _environment, vframeHeight->name, ptileset->frameHeight );

    Variable * vmapLayers = variable_retrieve( _environment, "puttilemap__mapLayers" );
    variable_store( _environment, vmapLayers->name, ptileset->frameHeight );

    Variable * mapLayers = variable_temporary( _environment, VT_BYTE, "(mapLayers)" );
    if ( _layer ) {
        variable_store( _environment, mapLayers->name, 1 );
    } else {
        variable_store( _environment, mapLayers->name, ptilemap->mapLayers );
    }

    char labelForTileOffsetFrame[MAX_TEMPORARY_STORAGE]; sprintf( labelForTileOffsetFrame, "%soffsetframe", ptilemap->tileset->name );
    Variable * voffsetFrameRoutine = variable_retrieve( _environment, "puttilemap__offsetFrameRoutine" );
    cpu_addressof_16bit( _environment, labelForTileOffsetFrame, voffsetFrameRoutine->realName );
    
    cpu_call( _environment, "lib_put_tilemap" );

}

