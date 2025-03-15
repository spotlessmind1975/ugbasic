#ifndef __UGBC_VIC1__
#define __UGBC_VIC1__

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
#define COLOR_WHITE					1
#define COLOR_DARK_RED				2 // RED
#define COLOR_RED					2
#define COLOR_CYAN					3
#define COLOR_VIOLET				4
#define COLOR_DARK_GREEN			5 // GREEN
#define COLOR_GREEN					5
#define COLOR_BLUE					6
#define COLOR_YELLOW				7	
#define COLOR_ORANGE				COLOR_YELLOW
#define COLOR_BROWN					COLOR_RED
#define COLOR_LIGHT_RED				COLOR_RED
#define COLOR_DARK_GREY				COLOR_BLUE
#define COLOR_GREY					COLOR_CYAN
#define COLOR_LIGHT_GREEN			COLOR_GREEN
#define COLOR_LIGHT_BLUE		 	COLOR_BLUE
#define COLOR_LIGHT_GREY			COLOR_WHITE
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
#define COLOR_DARK_WHITE			COLOR_WHITE
#define COLOR_LIGHT_WHITE			COLOR_WHITE
#define COLOR_COUNT                 8

#define DEFAULT_PEN_COLOR           COLOR_WHITE
#define DEFAULT_PAPER_COLOR         COLOR_BLACK

#define TEXT_COLUMNS_COUNT          22
#define TEXT_ROWS_COUNT             23

#define BITMAP_MODE_STANDARD        1           // Standard Bitmap Mode     128 x 64 x 8
#define BITMAP_MODE_EXTENDED        2           // Extended Bitmap Mode     128 x 128 x 8

#define BITMAP_MODE_DEFAULT     BITMAP_MODE_STANDARD

#define TILEMAP_MODE_STANDARD       0           // Standard Character Mode        22 x 23 x 8

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

#define IMAGE_WIDTH_SIZE                1
#define IMAGE_WIDTH_OFFSET              0
#define IMAGE_HEIGHT_SIZE               1
#define IMAGE_HEIGHT_OFFSET             1

#define DOUBLE_BUFFER_PAGE_0        0
#define DOUBLE_BUFFER_PAGE_1        1

int vic1_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode );

void vic1_initialization( Environment * _environment );
void vic1_finalization( Environment * _environment );

void vic1_back( Environment * _environment );
void vic1_background_color( Environment * _environment, int _index, int _background_color );
void vic1_background_color_vars( Environment * _environment, char * _index, char * _background_color );
void vic1_background_color_semivars( Environment * _environment, int _index, char * _background_color );
void vic1_background_color_get_vars( Environment * _environment, char * _index, char * _background_color );
void vic1_border_color( Environment * _environment, char * _border_color );
void vic1_collision( Environment * _environment, char * _sprite_mask, char * _result );
void vic1_hit( Environment * _environment, char * _sprite_mask, char * _result );
void vic1_next_raster( Environment * _environment );
void vic1_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void vic1_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void vic1_sprite_common_color( Environment * _environment, char * _index, char * _common_color );
void vic1_bitmap_enable( Environment * _environment, int _width, int _height, int _colors );
void vic1_bitmap_disable( Environment * _environment );
void vic1_bitmap_at( Environment * _environment, char * _address );
void vic1_colormap_at( Environment * _environment, char * _address );
void vic1_textmap_at( Environment * _environment, char * _address );
void vic1_tiles_at( Environment * _environment, char * _address );
void vic1_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height );

void vic1_bank_select( Environment * _environment, int _bank );
void vic1_screen_on( Environment * _environment );
void vic1_screen_off( Environment * _environment );
void vic1_screen_rows( Environment * _environment, char * _rows );
void vic1_screen_columns( Environment * _environment, char * _columns );

void vic1_sprite_data_from( Environment * _environment, char * _sprite, char * _address );
void vic1_sprite_data_set( Environment * _environment, char * _sprite, char * _address );
void vic1_sprite_enable( Environment * _environment, char *_sprite );
void vic1_sprite_disable( Environment * _environment, char * _sprite );
void vic1_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y );
void vic1_sprite_expand_vertical( Environment * _environment, char * _sprite );
void vic1_sprite_expand_horizontal( Environment * _environment, char * _sprite );
void vic1_sprite_compress_vertical( Environment * _environment, char * _sprite );
void vic1_sprite_compress_horizontal( Environment * _environment, char * _sprite );
void vic1_sprite_multicolor( Environment * _environment, char * _sprite );
void vic1_sprite_monocolor( Environment * _environment, char * _sprite );
void vic1_sprite_color( Environment * _environment, char * _sprite, char * _color );
void vic1_sprite_priority( Environment * _environment, char * _sprite, char * _priority );
void vic1_vertical_scroll( Environment * _environment, char * _displacement );
void vic1_horizontal_scroll( Environment * _environment, char * _displacement );
void vic1_busy_wait( Environment * _environment, char * _timing );

void vic1_tiles_get( Environment * _environment, char * _result );
void vic1_get_width( Environment * _environment, char * _result );
void vic1_get_height( Environment * _environment, char * _result );

void vic1_pset_int( Environment * _environment, int _x, int _y, int *_c );
void vic1_pset_vars( Environment * _environment, char *_x, char *_y, char *_p );
void vic1_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result );
void vic1_cls( Environment * _environment );
void vic1_cls_box( Environment * _environment, char * _x1, char * _y1, char * _w, char * _h );
void vic1_scroll_text( Environment * _environment, int _direction, int _overlap );
void vic1_hscroll_line( Environment * _environment, int _direction, int _overlap );
void vic1_hscroll_screen( Environment * _environment, int _direction, int _overlap );
void vic1_text( Environment * _environment, char * _text, char * _text_size, int _raw );
void vic1_cline( Environment * _environment, char * _characters );
void vic1_scroll( Environment * _environment, int _dx, int _dy );

Variable * vic1_get_raster_line( Environment * _environment );

int vic1_image_size( Environment * _environment, int _width, int _height, int _mode );
Variable * vic1_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags );
void vic1_put_image( Environment * _environment, Resource * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _flags );
void vic1_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
void vic1_wait_vbl( Environment * _environment );
Variable * vic1_new_image( Environment * _environment, int _width, int _height, int _mode );
Variable * vic1_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode );
Variable * vic1_new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode );
void vic1_get_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _palette );

void vic1_put_tile( Environment * _environment, char * _image, char * _x, char * _y );
void vic1_put_tiles( Environment * _environment, char * _image, char * _x, char * _y, char *_w, char *_h );
void vic1_move_tiles( Environment * _environment, char * _image, char * _x, char * _y );
void vic1_use_tileset( Environment * _environment, char * _tileset );
void vic1_tile_at( Environment * _environment, char * _x, char * _y, char * _result );

void vic1_start( Environment * _environment, int _channel );
void vic1_set_volume( Environment * _environment, int _channel, int _volume );
void vic1_set_program( Environment * _environment, int _channel, int _program );
void vic1_set_parameter( Environment * _environment, int _channel, int _parameter, int _value );
void vic1_set_frequency( Environment * _environment, int _channel, int _frequency );
void vic1_set_pitch( Environment * _environment, int _channel, int _pitch );
void vic1_set_note( Environment * _environment, int _channel, int _note );
void vic1_stop( Environment * _environment, int _channel );
void vic1_set_duration( Environment * _environment, int _channel, int _duration );
void vic1_wait_duration( Environment * _environment, int _channels );

void vic1_start_var( Environment * _environment, char * _channel );
void vic1_set_volume_semi_var( Environment * _environment, char * _channel, int _volume );
void vic1_set_volume_vars( Environment * _environment, char * _channel, char * _volume );
void vic1_set_program_semi_var( Environment * _environment, char * _channel, int _program );
void vic1_set_frequency_vars( Environment * _environment, char * _channel, char * _frequency );
void vic1_set_pitch_vars( Environment * _environment, char * _channel, char * _pitch );
void vic1_set_note_vars( Environment * _environment, char * _channel, char * _note );
void vic1_stop_vars( Environment * _environment, char * _channel );
void vic1_set_duration_vars( Environment * _environment, char * _channel, char * _duration );
void vic1_wait_duration_vars( Environment * _environment, char * _channel );

void vic1_music( Environment * _environment, char * _music, int _size, int _loop );

void vic1_slice_image( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination );
int vic1_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette );
void vic1_calculate_sequence_frame_offset( Environment * _environment, char * _offset, char * _sequence, char * _frame, int _frame_size, int _frame_count );

void vic1_screen( Environment * _environment, char * _x, char * _y, char * _c );

#endif