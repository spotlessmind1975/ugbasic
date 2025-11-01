#ifndef __UGBC_TED__
#define __UGBC_TED__

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
#define COLOR_DARK_WHITE			12 // GREY
#define COLOR_WHITE					1
#define COLOR_DARK_RED				2 // RED
#define COLOR_RED					2
#define COLOR_CYAN					3
#define COLOR_VIOLET				4
#define COLOR_DARK_GREEN			5 // GREEN
#define COLOR_GREEN					5
#define COLOR_DARK_BLUE				6 // BLUE
#define COLOR_BLUE					6
#define COLOR_YELLOW				7
#define COLOR_ORANGE				8
#define COLOR_BROWN					9
#define COLOR_LIGHT_RED				10
#define COLOR_DARK_GREY				11
#define COLOR_GREY					12
#define COLOR_LIGHT_GREEN			13
#define COLOR_LIGHT_BLUE			14
#define COLOR_LIGHT_GREY			15
#define COLOR_DARK_BLUE				6
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
#define COLOR_LIGHT_WHITE			COLOR_WHITE
#define COLOR_COUNT                 16

#define DEFAULT_PEN_COLOR           COLOR_WHITE
#define DEFAULT_PAPER_COLOR         COLOR_BLACK

#define TEXT_COLUMNS_COUNT          40
#define TEXT_ROWS_COUNT             25

#define BITMAP_MODE_STANDARD        2           // Standard Bitmap Mode     320 x 200 x 2
#define BITMAP_MODE_MULTICOLOR      3           // Multicolor Bitmap Mode   160 x 200 x 4

#define BITMAP_MODE_DEFAULT     BITMAP_MODE_STANDARD

#define TILEMAP_MODE_STANDARD       0           // Standard Character Mode        40 x 25 x 16
#define TILEMAP_MODE_MULTICOLOR     1           // Multicolor Character Mode      40 x 25 x 16
#define TILEMAP_MODE_EXTENDED       4           // Extended Background Color Mode 40 x 25 x 20

#define SPRITE_COUNT                0
#define SPRITE_WIDTH                0
#define SPRITE_HEIGHT               0

#define SPRITE_X_MIN                0
#define SPRITE_Y_MIN                0
#define SPRITE_X_MAX                0
#define SPRITE_Y_MAX                0

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

int ted_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode );

void ted_initialization( Environment * _environment );
void ted_finalization( Environment * _environment );

void ted_back( Environment * _environment );
void ted_background_color( Environment * _environment, int _index, int _background_color );
void ted_background_color_vars( Environment * _environment, char * _index, char * _background_color );
void ted_background_color_semivars( Environment * _environment, int _index, char * _background_color );
void ted_background_color_get_vars( Environment * _environment, char * _index, char * _background_color );
void ted_border_color( Environment * _environment, char * _border_color );
void ted_collision( Environment * _environment, char * _sprite_mask, char * _result );
void ted_hit( Environment * _environment, char * _sprite_mask, char * _result );
void ted_next_raster( Environment * _environment );
void ted_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void ted_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void ted_sprite_common_color( Environment * _environment, char * _index, char * _common_color );
void ted_bitmap_enable( Environment * _environment, int _width, int _height, int _colors );
void ted_bitmap_disable( Environment * _environment );
void ted_bitmap_at( Environment * _environment, char * _address );
void ted_colormap_at( Environment * _environment, char * _address );
void ted_textmap_at( Environment * _environment, char * _address );
void ted_charset_at( Environment * _environment, char * _address );
void ted_charset_uppercase( Environment * _environment );
void ted_charset_lowercase( Environment * _environment );
void ted_tiles_at( Environment * _environment, char * _address );
void ted_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height );

void ted_bank_select( Environment * _environment, int _bank );
void ted_screen_on( Environment * _environment );
void ted_screen_off( Environment * _environment );
void ted_screen_rows( Environment * _environment, char * _rows );
void ted_screen_columns( Environment * _environment, char * _columns );

void ted_sprite_data_from( Environment * _environment, char * _sprite, char * _address );
void ted_sprite_data_set( Environment * _environment, char * _sprite, char * _address );
void ted_sprite_enable( Environment * _environment, char *_sprite );
void ted_sprite_disable( Environment * _environment, char * _sprite );
void ted_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y );
void ted_sprite_expand_vertical( Environment * _environment, char * _sprite );
void ted_sprite_expand_horizontal( Environment * _environment, char * _sprite );
void ted_sprite_compress_vertical( Environment * _environment, char * _sprite );
void ted_sprite_compress_horizontal( Environment * _environment, char * _sprite );
void ted_sprite_multicolor( Environment * _environment, char * _sprite );
void ted_sprite_monocolor( Environment * _environment, char * _sprite );
void ted_sprite_color( Environment * _environment, char * _sprite, char * _color );
void ted_sprite_priority( Environment * _environment, char * _sprite, char * _priority );
void ted_vertical_scroll( Environment * _environment, char * _displacement );
void ted_horizontal_scroll( Environment * _environment, char * _displacement );
void ted_busy_wait( Environment * _environment, char * _timing );

void ted_tiles_get( Environment * _environment, char * _result );
void ted_get_width( Environment * _environment, char * _result );
void ted_get_height( Environment * _environment, char * _result );

void ted_pset_int( Environment * _environment, int _x, int _y, int *_c );
void ted_pset_vars( Environment * _environment, char *_x, char *_y, char *_c );
void ted_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result );
void ted_cls( Environment * _environment );
void ted_cls_box( Environment * _environment, char * _x1, char * _y1, char * _w, char * _h );
void ted_scroll_text( Environment * _environment, int _direction, int _overlap );
void ted_hscroll_line( Environment * _environment, int _direction, int _overlap );
void ted_hscroll_screen( Environment * _environment, int _direction, int _overlap );
void ted_text( Environment * _environment, char * _text, char * _text_size, int _raw );
void ted_scroll( Environment * _environment, int _dx, int _dy );

Variable * ted_get_raster_line( Environment * _environment );

int ted_image_size( Environment * _environment, int _width, int _height, int _mode );
Variable * ted_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags );
void ted_put_image( Environment * _environment, Resource * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _flags );
void ted_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
void ted_wait_vbl( Environment * _environment, char * _raster_line );
Variable * ted_new_image( Environment * _environment, int _width, int _height, int _mode );
Variable * ted_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode );
Variable * ted_new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode );
void ted_get_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _palette );

void ted_put_tile( Environment * _environment, char * _image, char * _x, char * _y );
void ted_put_tiles( Environment * _environment, char * _image, char * _x, char * _y, char *_w, char *_h );
void ted_move_tiles( Environment * _environment, char * _image, char * _x, char * _y );
void ted_use_tileset( Environment * _environment, char * _tileset );
void ted_tile_at( Environment * _environment, char * _x, char * _y, char * _result );

void ted_start( Environment * _environment, int _channel );
void ted_set_volume( Environment * _environment, int _channel, int _volume );
void ted_set_program( Environment * _environment, int _channel, int _program );
void ted_set_parameter( Environment * _environment, int _channel, int _parameter, int _value );
void ted_set_frequency( Environment * _environment, int _channel, int _frequency );
void ted_set_pitch( Environment * _environment, int _channel, int _pitch );
void ted_set_note( Environment * _environment, int _channel, int _note );
void ted_stop( Environment * _environment, int _channel );
void ted_set_duration( Environment * _environment, int _channel, int _duration );
void ted_wait_duration( Environment * _environment, int _channels );

void ted_start_var( Environment * _environment, char * _channel );
void ted_set_volume_semi_var( Environment * _environment, char * _channel, int _volume );
void ted_set_volume_vars( Environment * _environment, char * _channel, char * _volume );
void ted_set_program_semi_var( Environment * _environment, char * _channel, int _program );
void ted_set_frequency_vars( Environment * _environment, char * _channel, char * _frequency );
void ted_set_pitch_vars( Environment * _environment, char * _channel, char * _pitch );
void ted_set_note_vars( Environment * _environment, char * _channel, char * _note );
void ted_stop_vars( Environment * _environment, char * _channel );
void ted_set_duration_vars( Environment * _environment, char * _channel, char * _duration );
void ted_wait_duration_vars( Environment * _environment, char * _channel );

void ted_music( Environment * _environment, char * _music, int _size, int _loop );

void ted_slice_image( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination );
int ted_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette );
void ted_calculate_sequence_frame_offset( Environment * _environment, char * _offset, char * _sequence, char * _frame, int _frame_size, int _frame_count );
void ted_flip_image( Environment * _environment, Resource * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _direction );

void ted_screen( Environment * _environment, char * _x, char * _y, char * _c );

#endif