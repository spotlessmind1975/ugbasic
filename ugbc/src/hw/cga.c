/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
 * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#if defined(__pccga__)

#include "../ugbc.h"
#include <math.h>

static RGBi SYSTEM_PALETTE[] = {
        {    0,    0,    0, 0xff,  0, "BLACK" },
        {    0,    0,  170, 0xff,  1, "DARK_BLUE" },
        {    0,  170,    0, 0xff,  2, "DARK_GREEN" },
        {    0,  170,  170, 0xff,  3, "DARK_CYAN" },
        {  170,    0,    0, 0xff,  4, "DARK_RED" },
        {  170,    0,  170, 0xff,  5, "DARK_MAGENTA" },
        {  170,   85,    0, 0xff,  6, "BROWN" },
        {  170,  170,  170, 0xff,  7, "LIGHT_GRAY" },
        {   85,   85,   85, 0xff,  8, "DARK_GRAY" },
        {   85,   85,  255, 0xff,  9, "LIGHT_BLUE" },
        {   85,  255,   85, 0xff, 10, "LIGHT_GREEN" },
        {   85,  255,  255, 0xff, 11, "LIGHT_CYAN" },
        {  255,   85,   85, 0xff, 12, "LIGHT_RED" },
        {  255,   85,  255, 0xff, 13, "LIGHT_MAGENTA" },
        {  255,  255,   85, 0xff, 14, "YELLOW" },
        {  255,  255,  255, 0xff, 15, "WHITE" }
};

static RGBi * commonPalette;
int lastUsedSlotInCommonPalette = 0;

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

RGBi * CGA_image_nearest_system_color( RGBi * _color ) {

    unsigned int minDistance = 0xffff;
    int colorIndex = 0;
    for (int j = 0; j < COLOR_COUNT; ++j) {
        int distance = rgbi_distance(&SYSTEM_PALETTE[j], _color);
        if ( _color->alpha < 255 ) {
            if ( rgbi_equals_rgb( &SYSTEM_PALETTE[j], _color ) ) {
                minDistance = 0;
                distance = 0;
                colorIndex = j;
            }
        } else {
            if ( SYSTEM_PALETTE[j].alpha < 255 ) {
                continue;
            }
            if (distance < minDistance) {
                minDistance = distance;
                colorIndex = j;
            }
        }
    }

    return &SYSTEM_PALETTE[colorIndex];

}

Variable * cga_collision( Environment * _environment, char * _sprite ) {

    Variable * sprite = variable_retrieve_or_define( _environment, _sprite, VT_BYTE, 0 );
    Variable * result = variable_temporary( _environment, VT_SBYTE, "(collision)" );

    deploy( sprite, src_hw_cga_sprites_asm );
    
    if ( ! _environment->hasGameLoop ) {
        outline0("CALL SPRITECOL");
    } else {
        outline0("CALL SPRITECOLNMI2");
    }

    outline1("LD (%s), A", result->realName )

    return result;
    
}

/**
 * @brief <i>CGA</i>: emit code to check for collision
 * 
 * This function can be used to issue code aimed at verifying if a sprite has 
 * had a collision with a tile. The result (0 = no collision, 0xff = 
 * collision occurred) is returned in the output variable.
 * *
 * @param _environment Current calling environment
 * @param _sprite_mask Sprite mask to use
 * @param _result Where to store the result
 */
void cga_hit( Environment * _environment, char * _sprite_mask, char * _result ) {

    //todo

}

/**
 * @brief <i>CGA</i>: emit code to change border color
 * 
 * This function can be used to issue code aimed at changing the
 * border color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _border_color Border color to use
 */
void cga_border_color( Environment * _environment, char * _border_color ) {

}

/**
 * @brief <i>CGA</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void cga_background_color( Environment * _environment, int _index, int _background_color ) {

    char value[MAX_TEMPORARY_STORAGE]; sprintf( value, "$%2.2x", _background_color );

    cga_background_color_vars( _environment, NULL, value );
    
}

/**
 * @brief <i>CGA</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void cga_background_color_vars( Environment * _environment, char * _index, char * _background_color ) {

}

/**
 * @brief <i>CGA</i>: emit code to change background color
 * 
 * This function can be used to issue code aimed at changing the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void cga_background_color_semivars( Environment * _environment, int _index, char * _background_color ) {

}

/**
 * @brief <i>CGA</i>: emit code to retrieve background color
 * 
 * This function can be used to issue code aimed at retrieving the
 * background color of the screen.
 * 
 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _background_color Background color to use
 */
void cga_background_color_get_vars( Environment * _environment, char * _index, char * _background_color ) {

}

/**
 * @brief <i>CGA</i>: emit code to change common sprite's color 
 * 
 * This function can be used to issue code aimed at changing the
 * common color of the sprites.

 * @param _environment Current calling environment
 * @param _index Index of the background color
 * @param _common_color Index of the color to use
 */
void cga_sprite_common_color( Environment * _environment, char * _index, char * _common_color ) {

}

/**
 * @brief <i>CGA</i>: emit code to set raster irq
 * 
 * This function outputs assembly code needed to initialize a raster routine. 
 * In other words, asynchronously and in parallel with the execution of the 
 * main program, the routine starting from the label provided will be executed
 * when the vertical brush on the screen reaches the value of _position. 
 * This function is particularly useful when the position is communicated 
 * is given as an integer.
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _positionlo The vertical position to wait for (bits 7..0)
 * @param _positionhi The vertical position to wait for (bit 8)
 */
void cga_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

/**
 * @brief <i>CGA</i>: emit code to wait for next raster irq
 * 
 * This function outputs assembly code needed to wait for the
 * next raster. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 *
 */
void cga_next_raster( Environment * _environment ) {

}

/**
 * @brief <i>CGA</i>: emit code to wait for next raster irq at different position
 * 
 * This function outputs assembly code needed to wait for the
 * next raster on a different position with a different code to
 * execute. Meanwhile, the execution of the main code will resume 
 * where it left off.
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _positionlo The vertical position to wait for (bits 7..0)
 * @param _positionhi The vertical position to wait for (bit 8)
 */
void cga_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi ) {

}

void cga_bank_select( Environment * _environment, int _bank ) {
    
}

int cga_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode ) {

}

void console_calculate( Environment * _environment ) {

}

void console_calculate_vars( Environment * _environment ) {

}

void cga_bitmap_enable( Environment * _environment, int _width, int _height, int _colors ) {

}

void cga_bitmap_disable( Environment * _environment ) {

}

void cga_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height ) {

}

void cga_bitmap_at( Environment * _environment, char * _address ) {

}

void cga_colormap_at( Environment * _environment, char * _address ) {

}

void cga_textmap_at( Environment * _environment, char * _address ) {

}

void cga_pset_int( Environment * _environment, int _x, int _y, int *_c ) {

}

void cga_pset_vars( Environment * _environment, char *_x, char *_y, char *_c ) {

}

void cga_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result ) {

}

void cga_screen_on( Environment * _environment ) {

}

void cga_screen_off( Environment * _environment ) {

}

void cga_screen_rows( Environment * _environment, char * _rows ) {

}

void cga_screen_columns( Environment * _environment, char * _columns ) {

}

void cga_sprite_data_set( Environment * _environment, char * _sprite, char * _address ) {

}

void cga_sprite_data_from( Environment * _environment, char * _sprite, char * _image ) {

}

void cga_sprite_enable( Environment * _environment, char * _sprite ) {

}

void cga_sprite_disable( Environment * _environment, char * _sprite ) {

}

void cga_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y ) {

}

void cga_sprite_expand_vertical( Environment * _environment, char * _sprite ) {

}

void cga_sprite_expand_horizontal( Environment * _environment, char * _sprite ) {

}

void cga_sprite_compress_vertical( Environment * _environment, char * _sprite ) {

}

void cga_sprite_compress_horizontal( Environment * _environment, char * _sprite ) {

}

void cga_sprite_multicolor( Environment * _environment, char * _sprite ) {

}

void cga_sprite_monocolor( Environment * _environment, char * _sprite ) {

}

void cga_sprite_color( Environment * _environment, char * _sprite, char * _color ) {

}

void cga_sprite_priority( Environment * _environment, char * _sprite, char * _priority ) {

}

void cga_tiles_at( Environment * _environment, char * _address ) {

}

void cga_vertical_scroll( Environment * _environment, char * _displacement ) {

}

void cga_horizontal_scroll( Environment * _environment, char * _displacement ) {

}

void cga_busy_wait( Environment * _environment, char * _timing ) {

}

void cga_get_width( Environment * _environment, char *_result ) {

}

void cga_tiles_get( Environment * _environment, char *_result ) {

}

void cga_get_height( Environment * _environment, char *_result ) {

}

void cga_cls( Environment * _environment ) {
    
}

void cga_cls_box( Environment * _environment, char * _x1, char * _y1, char * _w, char * _h ) {
    
}

void cga_scroll_text( Environment * _environment, int _direction, int _overlap ) {

}

void cga_text( Environment * _environment, char * _text, char * _text_size, int _raw ) {

}

void cga_initialization( Environment * _environment ) {

}

void cga_finalization( Environment * _environment ) {

}

void cga_hscroll_line( Environment * _environment, int _direction, int _overlap ) {

}

void cga_hscroll_screen( Environment * _environment, int _direction, int _overlap ) {

}

void cga_back( Environment * _environment ) {

}

void cga_cline( Environment * _environment, char * _characters ) {

}

int cga_image_size( Environment * _environment, int _width, int _height, int _mode ) {

}

static int calculate_images_size( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

}

static int calculate_sequence_size( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

}

Variable * cga_sprite_converter( Environment * _environment, char * _source, int _width, int _height, int _depth, RGBi * _color, int _slot_x, int _slot_y ) {

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );

    return result;

}

Variable * cga_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags ) {

    return cga_new_image( _environment, 8, 8, BITMAP_MODE_GRAPHIC2 );

}

void cga_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags ) {

}

void cga_put_image( Environment * _environment, Resource * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _flags ) {

}

void cga_wait_vbl( Environment * _environment ) {

}

Variable * cga_new_image( Environment * _environment, int _width, int _height, int _mode ) {

    Variable * result = variable_temporary( _environment, VT_IMAGE, "(new image)" );

    return result;

}

Variable * cga_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

    Variable * result = variable_temporary( _environment, VT_IMAGES, "(new images)" );

    return result;

}

Variable * cga_new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode ) {

    Variable * result = variable_temporary( _environment, VT_SEQUENCE, "(new sequence)" );

    return result;

}

void cga_get_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _palette ) {

}

void cga_scroll( Environment * _environment, int _dx, int _dy ) {

}

void cga_put_tile( Environment * _environment, char * _tile, char * _x, char * _y ) {

}

void cga_move_tiles( Environment * _environment, char * _tile, char * _x, char * _y ) {

}

void cga_put_tiles( Environment * _environment, char * _tile, char * _x, char * _y, char *_w, char *_h ) {

}

void cga_tile_at( Environment * _environment, char * _x, char * _y, char *_result ) {

}

void cga_use_tileset( Environment * _environment, char * _tileset ) {

}

Variable * cga_get_raster_line( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_WORD, "(raster line)" );

    variable_store( _environment, result->name, 0 );

    return result;
    
}

void cga_move_memory_video( Environment * _environment, char * _from, char * _to, char * _size ) {

}

void cga_move_video_memory( Environment * _environment, char * _from, char * _to, char * _size ) {

}

void cga_colors_vars( Environment * _environment, char * _foreground_color, char * _background_color ) {

}

void cga_slice_image( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination ) {

}

void cga_slice_image_copy( Environment * _environment, char * _image,  char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination ) {

}

void cga_slice_image_extract( Environment * _environment, char * _image,  char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination ) {

}

int cga_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette ) {

    int paletteColorCount = rgbi_extract_palette(_environment, _data, _width, _height, _depth, _palette, MAX_PALETTE, ( ( _flags & FLAG_EXACT ) ? 0 : 1 ) /* sorted */);

    memcpy( _palette, palette_match( _palette, paletteColorCount, SYSTEM_PALETTE, sizeof(SYSTEM_PALETTE) / sizeof(RGBi) ), paletteColorCount * sizeof( RGBi ) );

    int uniquePaletteCount = 0;

    memcpy( _palette, palette_remove_duplicates( _palette, paletteColorCount, &uniquePaletteCount ), paletteColorCount * sizeof( RGBi ) );

    return uniquePaletteCount;

}

void cga_calculate_sequence_frame_offset( Environment * _environment, char * _offset, char * _sequence, char * _frame, int _frame_size, int _frame_count ) {

}

void cga_flip_image( Environment * _environment, Resource * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _direction ) {

}

void cga_screen( Environment * _environment, char * _x, char * _y, char * _c ) {

}

#endif