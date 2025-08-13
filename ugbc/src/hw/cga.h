#ifndef __UGBC_TMS9918__
#define __UGBC_TMS9918__

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

#include "../ugbc.h"

#define COLOR_TRANSPARENT			0x00
#define COLOR_BLACK					0x00
#define COLOR_DARK_WHITE			0x08 // DARK GRAY
#define COLOR_WHITE					0x0f
#define COLOR_LIGHT_WHITE			COLOR_WHITE
#define COLOR_DARK_RED				0x04
#define COLOR_RED					0x0c
#define COLOR_LIGHT_RED				COLOR_RED
#define COLOR_CYAN					0x0b
#define COLOR_VIOLET				0x0d // LIGHT MAGENTA
#define COLOR_DARK_GREEN			0x02
#define COLOR_GREEN					0x0a
#define COLOR_LIGHT_GREEN			COLOR_GREEN
#define COLOR_DARK_BLUE				0x01
#define COLOR_BLUE					0x09
#define COLOR_LIGHT_BLUE			COLOR_BLUE
#define COLOR_YELLOW				0x0e
#define COLOR_ORANGE				COLOR_LIGHT_RED
#define COLOR_BROWN					0x06
#define COLOR_DARK_GREY				COLOR_DARK_WHITE
#define COLOR_GREY					0x07
#define COLOR_LIGHT_GREY			COLOR_GREY
#define COLOR_MAGENTA				0x0d
#define COLOR_PURPLE				COLOR_VIOLET
#define COLOR_LAVENDER       		COLOR_VIOLET
#define COLOR_GOLD       			COLOR_YELLOW
#define COLOR_TURQUOISE       		COLOR_LIGHT_BLUE
#define COLOR_TAN       		    COLOR_BROWN
#define COLOR_YELLOW_GREEN       	COLOR_LIGHT_GREEN
#define COLOR_OLIVE_GREEN       	COLOR_GREEN
#define COLOR_PINK       			COLOR_LIGHT_RED
#define COLOR_PEACH       			COLOR_PINK
#define COLOR_COUNT                 16

#define DEFAULT_PEN_COLOR           COLOR_WHITE
#define DEFAULT_PAPER_COLOR         COLOR_BLACK

#define TEXT_COLUMNS_COUNT          40
#define TEXT_ROWS_COUNT             25

#define TILEMAP_MODE_40x25x2       0           // 40x25, 2 colors
#define TILEMAP_MODE_40x25x16      1           // 40x25, 16 colors
#define TILEMAP_MODE_80x25x2       2           // 80x25, 2 colors
#define TILEMAP_MODE_80x25x16      3           // 80x25, 16 colors
#define TILEMAP_MODE_STANDARD      TILEMAP_MODE_40x25x16

#define BITMAP_MODE_320x200x2      4           // 320x200, 2 colors
#define BITMAP_MODE_320x200x4      5           // 320x200, 4 colors
#define BITMAP_MODE_640x200x2      6           // 320x200, 2 colors
#define BITMAP_MODE_STANDARD       BITMAP_MODE_320x200x4

#define BITMAP_MODE_DEFAULT         BITMAP_MODE_STANDARD

#define SPRITE_COUNT                32
#define SPRITE_WIDTH                8
#define SPRITE_HEIGHT               8
#define SPRITE_X_MIN                0
#define SPRITE_Y_MIN                0
#define SPRITE_X_MAX                264
#define SPRITE_Y_MAX                200

#define SCREEN_SPRITE_RATIO_X       100
#define SCREEN_SPRITE_RATIO_Y       100
#define SCREEN_BORDER_X             0
#define SCREEN_BORDER_Y             0

#define IMAGE_WIDTH_SIZE                2
#define IMAGE_WIDTH_OFFSET              0
#define IMAGE_HEIGHT_SIZE               1
#define IMAGE_HEIGHT_OFFSET             2

#define DOUBLE_BUFFER_PAGE_0        0
#define DOUBLE_BUFFER_PAGE_1        1

// #define TILES_PADDING           8

int cga_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode );

void cga_initialization( Environment * _environment );
void cga_finalization( Environment * _environment );

void cga_back( Environment * _environment );
void cga_background_color( Environment * _environment, int _index, int _background_color );
void cga_background_color_vars( Environment * _environment, char * _index, char * _background_color );
void cga_background_color_semivars( Environment * _environment, int _index, char * _background_color );
void cga_colors_vars( Environment * _environment, char * _foreground_color, char * _background_color );
void cga_background_color_get_vars( Environment * _environment, char * _index, char * _background_color );
void cga_border_color( Environment * _environment, char * _border_color );
Variable * cga_collision( Environment * _environment, char * _sprite );
void cga_hit( Environment * _environment, char * _sprite_mask, char * _result );
void cga_next_raster( Environment * _environment );
void cga_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void cga_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void cga_sprite_common_color( Environment * _environment, char * _index, char * _common_color );
void cga_bitmap_enable( Environment * _environment, int _width, int _height, int _colors );
void cga_bitmap_disable( Environment * _environment );
void cga_bitmap_at( Environment * _environment, char * _address );
void cga_colormap_at( Environment * _environment, char * _address );
void cga_textmap_at( Environment * _environment, char * _address );
void cga_tiles_at( Environment * _environment, char * _address );
void cga_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height );

void cga_bank_select( Environment * _environment, int _bank );
void cga_screen_on( Environment * _environment );
void cga_screen_off( Environment * _environment );
void cga_screen_rows( Environment * _environment, char * _rows );
void cga_screen_columns( Environment * _environment, char * _columns );

void cga_sprite_data_from( Environment * _environment, char * _sprite, char * _image );
void cga_sprite_data_set( Environment * _environment, char * _sprite, char * _image );
void cga_sprite_enable( Environment * _environment, char *_sprite );
void cga_sprite_disable( Environment * _environment, char * _sprite );
void cga_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y );
void cga_sprite_expand_vertical( Environment * _environment, char * _sprite );
void cga_sprite_expand_horizontal( Environment * _environment, char * _sprite );
void cga_sprite_compress_vertical( Environment * _environment, char * _sprite );
void cga_sprite_compress_horizontal( Environment * _environment, char * _sprite );
void cga_sprite_multicolor( Environment * _environment, char * _sprite );
void cga_sprite_monocolor( Environment * _environment, char * _sprite );
void cga_sprite_color( Environment * _environment, char * _sprite, char * _color );
void cga_sprite_priority( Environment * _environment, char * _sprite, char * _priority );
void cga_vertical_scroll( Environment * _environment, char * _displacement );
void cga_horizontal_scroll( Environment * _environment, char * _displacement );
void cga_busy_wait( Environment * _environment, char * _timing );

void cga_tiles_get( Environment * _environment, char * _result );
void cga_get_width( Environment * _environment, char * _result );
void cga_get_height( Environment * _environment, char * _result );

void cga_pset_int( Environment * _environment, int _x, int _y, int *_c );
void cga_pset_vars( Environment * _environment, char *_x, char *_y, char *_c );
void cga_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result );
void cga_cls( Environment * _environment );
void cga_cls_box( Environment * _environment, char * _x1, char * _y1, char * _w, char * _h );
void cga_scroll_text( Environment * _environment, int _direction, int _overlap );
void cga_hscroll_line( Environment * _environment, int _direction, int _overlap );
void cga_hscroll_screen( Environment * _environment, int _direction, int _overlap );
void cga_text( Environment * _environment, char * _text, char * _text_size, int _raw );
void cga_cline( Environment * _environment, char * _characters );
void cga_scroll( Environment * _environment, int _dx, int _dy );

void cga_calculate_sequence_frame_offset( Environment * _environment, char * _offset, char * _sequence, char * _frame, int _frame_size, int _frame_count );

Variable * cga_get_raster_line( Environment * _environment );

int cga_image_size( Environment * _environment, int _width, int _height, int _mode );
Variable * cga_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags );
Variable * cga_sprite_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, RGBi * _color, int _x_slot, int _y_slot );
void cga_put_image( Environment * _environment, Resource * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _flags );
void cga_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
void cga_wait_vbl( Environment * _environment );
Variable * cga_new_image( Environment * _environment, int _width, int _height, int _mode );
Variable * cga_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode );
Variable * cga_new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode );
void cga_get_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _palette );

void cga_put_tile( Environment * _environment, char * _image, char * _x, char * _y );
void cga_put_tiles( Environment * _environment, char * _image, char * _x, char * _y, char *_w, char *_h );
void cga_move_tiles( Environment * _environment, char * _image, char * _x, char * _y );
void cga_use_tileset( Environment * _environment, char * _tileset );
void cga_tile_at( Environment * _environment, char * _x, char * _y, char *_result );

void cga_move_memory_video( Environment * _environment, char * _from, char * _to, char * _size );
void cga_move_video_memory( Environment * _environment, char * _from, char * _to, char * _size );
void cga_move_video_video( Environment * _environment, char * _from, char * _to, char * _size );

typedef void (*Tms9918SliceImageFunction)(Environment *, char *, char *, char *, int, int, char *);

void cga_slice_image_copy( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination );
void cga_slice_image_extract( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination );
int cga_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette );
void cga_flip_image( Environment * _environment, Resource * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _direction );

void cga_screen( Environment * _environment, char * _x, char * _y, char * _c );

#endif