#ifndef __UGBC_VDCZ__
#define __UGBC_VDCZ__

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

#define COLOR_BLACK					0
#define COLOR_DARK_WHITE			14 // GREY
#define COLOR_WHITE					15
#define COLOR_LIGHT_WHITE			COLOR_WHITE
#define COLOR_DARK_RED				8 // RED
#define COLOR_RED					8
#define COLOR_LIGHT_RED				9
#define COLOR_CYAN					6
#define COLOR_VIOLET				10
#define COLOR_DARK_GREEN			4 // GREEN
#define COLOR_GREEN					4
#define COLOR_LIGHT_GREEN			5
#define COLOR_DARK_BLUE				2 // BLUE
#define COLOR_BLUE					2
#define COLOR_LIGHT_BLUE			3
#define COLOR_YELLOW				12
#define COLOR_ORANGE				COLOR_RED
#define COLOR_BROWN					COLOR_RED
#define COLOR_DARK_GREY				1
#define COLOR_GREY					14
#define COLOR_LIGHT_GREY			14
#define COLOR_MAGENTA				COLOR_RED
#define COLOR_PURPLE				COLOR_VIOLET
#define COLOR_LAVENDER       		COLOR_VIOLET
#define COLOR_GOLD       			COLOR_YELLOW
#define COLOR_TURQUOISE       		COLOR_LIGHT_BLUE
#define COLOR_TAN       		    COLOR_BROWN
#define COLOR_YELLOW_GREEN       	COLOR_YELLOW
#define COLOR_OLIVE_GREEN       	COLOR_GREEN
#define COLOR_PINK       			COLOR_LIGHT_RED
#define COLOR_PEACH       			COLOR_PINK
#define COLOR_COUNT                 16

#define IMAGE_WIDTH_SIZE                2
#define IMAGE_WIDTH_OFFSET              0
#define IMAGE_HEIGHT_SIZE               1
#define IMAGE_HEIGHT_OFFSET             2

#define DEFAULT_PEN_COLOR           COLOR_WHITE
#define DEFAULT_PAPER_COLOR         COLOR_BLACK

#define TEXT_COLUMNS_COUNT          40
#define TEXT_ROWS_COUNT             25

#define BITMAP_MODE_STANDARD        1           // Standard Bitmap Mode         640 x 200 x 2
#define BITMAP_MODE_MULTICOLOR      2           // Standard Multicolor Mode     640 x 176 x 16
#define BITMAP_MODE_STANDARD_INT    5           // Interlaced Bitmap Mode       640 x 400 x 2
#define BITMAP_MODE_MULTICOLOR_INT  6           // Interlaced Multicolor Mode   640 x 352 x 16

#define BITMAP_MODE_DEFAULT     BITMAP_MODE_STANDARD

#define TILEMAP_MODE_STANDARD       0           // Standard Character Mode      80 x 25 x 16

#define SPRITE_COUNT                0
#define SPRITE_WIDTH                0
#define SPRITE_HEIGHT               0
#define SPRITE_X_MIN                0
#define SPRITE_Y_MIN                0
#define SPRITE_X_MAX                366
#define SPRITE_Y_MAX                255

#define SCREEN_SPRITE_RATIO_X       100
#define SCREEN_SPRITE_RATIO_Y       100
#define SCREEN_BORDER_X             0
#define SCREEN_BORDER_Y             0

#define DOUBLE_BUFFER_PAGE_0        0
#define DOUBLE_BUFFER_PAGE_1        1

int vdcz_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode );

void vdcz_initialization( Environment * _environment );
void vdcz_finalization( Environment * _environment );

void vdcz_back( Environment * _environment );
void vdcz_background_color( Environment * _environment, int _index, int _background_color );
void vdcz_background_color_vars( Environment * _environment, char * _index, char * _background_color );
void vdcz_background_color_semivars( Environment * _environment, int _index, char * _background_color );
void vdcz_background_color_get_vars( Environment * _environment, char * _index, char * _background_color );
void vdcz_border_color( Environment * _environment, char * _border_color );
Variable * vdcz_collision( Environment * _environment, char * _sprite );
void vdcz_hit( Environment * _environment, char * _sprite_mask, char * _result );
void vdcz_next_raster( Environment * _environment );
void vdcz_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void vdcz_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void vdcz_sprite_common_color( Environment * _environment, char * _index, char * _common_color );
void vdcz_bitmap_enable( Environment * _environment, int _width, int _height, int _colors );
void vdcz_bitmap_disable( Environment * _environment );
void vdcz_bitmap_at( Environment * _environment, char * _address );
void vdcz_colormap_at( Environment * _environment, char * _address );
void vdcz_textmap_at( Environment * _environment, char * _address );
void vdcz_tiles_at( Environment * _environment, char * _address );
void vdcz_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height );

void vdcz_bank_select( Environment * _environment, int _bank );
void vdcz_screen_on( Environment * _environment );
void vdcz_screen_off( Environment * _environment );
void vdcz_screen_rows( Environment * _environment, char * _rows );
void vdcz_screen_columns( Environment * _environment, char * _columns );

void vdcz_sprite_data_from( Environment * _environment, char * _sprite, char * _address );
void vdcz_sprite_data_set( Environment * _environment, char * _sprite, char * _address );
void vdcz_sprite_enable( Environment * _environment, char *_sprite );
void vdcz_sprite_disable( Environment * _environment, char * _sprite );
void vdcz_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y );
void vdcz_sprite_expand_vertical( Environment * _environment, char * _sprite );
void vdcz_sprite_expand_horizontal( Environment * _environment, char * _sprite );
void vdcz_sprite_compress_vertical( Environment * _environment, char * _sprite );
void vdcz_sprite_compress_horizontal( Environment * _environment, char * _sprite );
void vdcz_sprite_multicolor( Environment * _environment, char * _sprite );
void vdcz_sprite_monocolor( Environment * _environment, char * _sprite );
void vdcz_sprite_color( Environment * _environment, char * _sprite, char * _color );
void vdcz_sprite_priority( Environment * _environment, char * _sprite, char * _priority );
void vdcz_vertical_scroll( Environment * _environment, char * _displacement );
void vdcz_horizontal_scroll( Environment * _environment, char * _displacement );
void vdcz_busy_wait( Environment * _environment, char * _timing );

void vdcz_tiles_get( Environment * _environment, char * _result );
void vdcz_get_width( Environment * _environment, char * _result );
void vdcz_get_height( Environment * _environment, char * _result );

void vdcz_pset_int( Environment * _environment, int _x, int _y, int *_c );
void vdcz_pset_vars( Environment * _environment, char *_x, char *_y, char *_c );
void vdcz_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result );
void vdcz_cls( Environment * _environment );
void vdcz_cls_box( Environment * _environment, char * _x1, char * _y1, char * _w, char * _h );
void vdcz_scroll_text( Environment * _environment, int _direction, int _overlap );
void vdcz_hscroll_line( Environment * _environment, int _direction, int _overlap );
void vdcz_hscroll_screen( Environment * _environment, int _direction, int _overlap );
void vdcz_text( Environment * _environment, char * _text, char * _text_size, int _raw );
void vdcz_cline( Environment * _environment, char * _characters );
void vdcz_scroll( Environment * _environment, int _dx, int _dy );

Variable * vdcz_get_raster_line( Environment * _environment );

int vdcz_image_size( Environment * _environment, int _width, int _height, int _mode );
Variable * vdcz_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags );
Variable * vdcz_sprite_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, RGBi * _color, int _flags );
void vdcz_put_image( Environment * _environment, Resource * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _flags );
void vdcz_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
void vdcz_wait_vbl( Environment * _environment, char * _raster_line );
Variable * vdcz_new_image( Environment * _environment, int _width, int _height, int _mode );
Variable * vdcz_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode );
Variable * vdcz_new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode );
void vdcz_get_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _palette );

void vdcz_put_tile( Environment * _environment, char * _image, char * _x, char * _y );
void vdcz_put_tiles( Environment * _environment, char * _image, char * _x, char * _y, char *_w, char *_h );
void vdcz_move_tiles( Environment * _environment, char * _image, char * _x, char * _y );
void vdcz_use_tileset( Environment * _environment, char * _tileset );
void vdcz_tile_at( Environment * _environment, char * _x, char * _y, char * _result );

void vdcz_slice_image( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination );
int vdcz_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette );
void vdcz_calculate_sequence_frame_offset( Environment * _environment, char * _offset, char * _sequence, char * _frame, int _frame_size, int _frame_count );

void vdcz_screen( Environment * _environment, char * _x, char * _y, char * _c );

#endif