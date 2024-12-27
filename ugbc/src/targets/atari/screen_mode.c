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
 * @brief Emit ASM code for <b>SCREEN [mode]</b>
 * 
 * This function outputs assembly code to change the current mode.
 * 
 * @param _environment Current calling environment
 * @param _mode Mode to change to
 */
void screen_mode( Environment * _environment, int _mode ) {

    if ( _environment->graphicsAtariBasicEnabled ) {

        switch( _mode ) {

            // The modes are of two main types: pure graphics modes and text modes. The first three 
            // modes--GRAPHICS 0, 1, and 2--are text modes. When you switch on an ATARI with a 
            // BASIC cartridge plugged in, it defaults to GRAPHICS 0. GRAPHICS 0 has 24 horizontal rows of
            // up to 40 characters each on the screen. (If you've counted only 38 characters, it's because 
            // the left margin is pre-adjusted to allow for TVs which overscan, or cut off the left edge of 
            // the screen image.) GRAPHICS 1 and 2 display larger-size characters. GRAPHICS 1 characters are the 
            // same height as those in GRAPHICS 0, but are twice as wide. GRAPHICS 2 characters are not only twice as 
            // wide, but also twice as tall.

            case 0:
                _mode = TILEMAP_MODE_ANTIC2;
                break;
            case 1:
                _mode = TILEMAP_MODE_ANTIC6;
                break;
            case 2:
                _mode = TILEMAP_MODE_ANTIC7;
                break;

            // The graphics modes generally used for creating pictures are GRAPHICS 3 through 8 (3 through 11 
            // on GTIA machines). GRAPHICS 3 through 8 are mixed modes. That is, they are combinations of text and 
            // graphics modes. For example, type GRAPHICS 3 into the ATARI. You'll see a black screen with a small 
            // blue rectangle at the bottom. That rectangle is called the text window. Although the upper part of the 
            // screen is a graphics mode for drawing pictures, the text window is a section of GRAPHICS 0 for displaying text. 
            // Think of it as the term implies: a "wall" of GRAPHICS 3 with a "window" of GRAPHICS 0.

            case 3: case 19:
                _mode = BITMAP_MODE_ANTIC8;
                break;
            case 4: case 20:
                _mode = BITMAP_MODE_ANTIC9;
                break;
            case 5: case 21:
                _mode = BITMAP_MODE_ANTIC10;
                break;
            case 6: case 22:
                _mode = BITMAP_MODE_ANTIC11;
                break;
            case 7: case 23:
                _mode = BITMAP_MODE_ANTIC13;
                break;
            case 8: case 24:
                _mode = BITMAP_MODE_ANTIC15;
                break;

        }

    }
    
    ScreenMode * mode = find_screen_mode_by_id( _environment, _mode );

    if ( mode ) {
        gtia_screen_mode_enable( _environment, mode );    

        _environment->currentMode = mode->id;
        _environment->currentTileMode = mode->bitmap ? 0 : 1;

        cpu_store_8bit( _environment, "CURRENTMODE", _environment->currentMode );
        cpu_store_8bit( _environment, "CURRENTTILEMODE", _environment->currentTileMode );

    } else {
        WARNING_SCREEN_MODE( _mode );
    }

}

void screen_type_color_set( Environment * _environment, int _type, int _color_set ) {

    if ( _type == 0 ) {
        tilemap_enable( _environment, 0, 0, 0, 0, 0 );
    } else {
        bitmap_enable( _environment, 0, 0, 0 );
    }

}