#ifndef __UGBC_EF9345__
#define __UGBC_EF9345__

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
 * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

#include "../ugbc.h"

#define COLOR_BLACK					0x00
#define COLOR_RED					0x01
#define COLOR_GREEN					0x02
#define COLOR_YELLOW				0x03
#define COLOR_BLUE					0x04
#define COLOR_MAGENTA				0x05
#define COLOR_CYAN					0x06
#define COLOR_WHITE					0x07

#define COLOR_VIOLET				COLOR_MAGENTA
#define COLOR_ORANGE				COLOR_RED
#define COLOR_BROWN					COLOR_RED
#define COLOR_LIGHT_RED				COLOR_RED
#define COLOR_DARK_GREY				COLOR_BLACK
#define COLOR_GREY					COLOR_WHITE
#define COLOR_LIGHT_GREEN			COLOR_GREEN
#define COLOR_LIGHT_BLUE			COLOR_BLUE
#define COLOR_LIGHT_GREY			COLOR_WHITE
#define COLOR_DARK_BLUE				COLOR_BLUE
#define COLOR_PURPLE				COLOR_VIOLET
#define COLOR_LAVENDER       		COLOR_VIOLET
#define COLOR_GOLD       			COLOR_YELLOW
#define COLOR_TURQUOISE       		COLOR_LIGHT_BLUE
#define COLOR_TAN       		    COLOR_BROWN
#define COLOR_YELLOW_GREEN       	COLOR_YELLOW
#define COLOR_OLIVE_GREEN       	COLOR_GREEN
#define COLOR_PINK       			COLOR_LIGHT_RED
#define COLOR_PEACH       			COLOR_PINK
#define COLOR_COUNT                 8

#define DEFAULT_PEN_COLOR           COLOR_WHITE
#define DEFAULT_PAPER_COLOR         COLOR_BLACK

#define TEXT_COLUMNS_COUNT          40
#define TEXT_ROWS_COUNT             25

#define TILEMAP_MODE_STANDARD       0           // Text Mode

#define BITMAP_MODE_DEFAULT     TILEMAP_MODE_STANDARD

#define SPRITE_COUNT                0
#define SPRITE_WIDTH                0
#define SPRITE_HEIGHT               0
#define SPRITE_X_MIN                0
#define SPRITE_Y_MIN                0
#define SPRITE_X_MAX                0
#define SPRITE_Y_MAX                0

#define SCREEN_BORDER_X             0
#define SCREEN_BORDER_Y             0

#define SPRITE_FLAG_MULTICOLOR          0x0010
#define SPRITE_FLAG_MONOCOLOR           0x0000
#define SPRITE_FLAG_EXPAND_VERTICAL     0x0040
#define SPRITE_FLAG_COMPRESS_VERTICAL   0x0000
#define SPRITE_FLAG_EXPAND_HORIZONTAL   0x0080
#define SPRITE_FLAG_COMPRESS_HORIZONTAL 0x0000

#define IMAGE_WIDTH_SIZE                2
#define IMAGE_WIDTH_OFFSET              0
#define IMAGE_HEIGHT_SIZE               1
#define IMAGE_HEIGHT_OFFSET             2

int ef9345_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode );

void ef9345_initialization( Environment * _environment );
void ef9345_finalization( Environment * _environment );

void ef9345_back( Environment * _environment );
void ef9345_background_color( Environment * _environment, int _index, int _background_color );
void ef9345_background_color_vars( Environment * _environment, char * _index, char * _background_color );
void ef9345_background_color_semivars( Environment * _environment, int _index, char * _background_color );
void ef9345_colors_vars( Environment * _environment, char * _foreground_color, char * _background_color );
void ef9345_background_color_get_vars( Environment * _environment, char * _index, char * _background_color );
void ef9345_border_color( Environment * _environment, char * _border_color );
Variable * ef9345_collision( Environment * _environment, char * _sprite );
void ef9345_hit( Environment * _environment, char * _sprite_mask, char * _result );
void ef9345_next_raster( Environment * _environment );
void ef9345_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void ef9345_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void ef9345_sprite_common_color( Environment * _environment, char * _index, char * _common_color );
void ef9345_bitmap_enable( Environment * _environment, int _width, int _height, int _colors );
void ef9345_bitmap_disable( Environment * _environment );
void ef9345_bitmap_at( Environment * _environment, char * _address );
void ef9345_colormap_at( Environment * _environment, char * _address );
void ef9345_textmap_at( Environment * _environment, char * _address );
void ef9345_tiles_at( Environment * _environment, char * _address );
void ef9345_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height );

void ef9345_bank_select( Environment * _environment, int _bank );
void ef9345_enable_ecm( Environment * _environment );
void ef9345_disable_ecm( Environment * _environment );
void ef9345_enable_mcm( Environment * _environment );
void ef9345_disable_mcm( Environment * _environment );
void ef9345_screen_on( Environment * _environment );
void ef9345_screen_off( Environment * _environment );
void ef9345_screen_rows( Environment * _environment, char * _rows );
void ef9345_screen_columns( Environment * _environment, char * _columns );

void ef9345_sprite_data_from( Environment * _environment, char * _sprite, char * _image );
void ef9345_sprite_enable( Environment * _environment, char *_sprite );
void ef9345_sprite_disable( Environment * _environment, char * _sprite );
void ef9345_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y );
void ef9345_sprite_expand_vertical( Environment * _environment, char * _sprite );
void ef9345_sprite_expand_horizontal( Environment * _environment, char * _sprite );
void ef9345_sprite_compress_vertical( Environment * _environment, char * _sprite );
void ef9345_sprite_compress_horizontal( Environment * _environment, char * _sprite );
void ef9345_sprite_multicolor( Environment * _environment, char * _sprite );
void ef9345_sprite_monocolor( Environment * _environment, char * _sprite );
void ef9345_sprite_color( Environment * _environment, char * _sprite, char * _color );
void ef9345_vertical_scroll( Environment * _environment, char * _displacement );
void ef9345_horizontal_scroll( Environment * _environment, char * _displacement );
void ef9345_busy_wait( Environment * _environment, char * _timing );

void ef9345_tiles_get( Environment * _environment, char * _result );
void ef9345_get_width( Environment * _environment, char * _result );
void ef9345_tiles_get_width( Environment * _environment, char * _result );
void ef9345_get_height( Environment * _environment, char * _result );
void ef9345_tiles_get_height( Environment * _environment, char * _result );

void ef9345_point_at_int( Environment * _environment, int _x, int _y );
void ef9345_point_at_vars( Environment * _environment, char *_x, char *_y );
void ef9345_point( Environment * _environment, char *_x, char *_y, char * _result );
void ef9345_cls( Environment * _environment );
void ef9345_scroll_text( Environment * _environment, int _direction );
void ef9345_hscroll_line( Environment * _environment, int _direction );
void ef9345_hscroll_screen( Environment * _environment, int _direction );
void ef9345_text( Environment * _environment, char * _text, char * _text_size );
void ef9345_cline( Environment * _environment, char * _characters );
void ef9345_scroll( Environment * _environment, int _dx, int _dy );

Variable * ef9345_get_raster_line( Environment * _environment );

Variable * ef9345_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags );
Variable * ef9345_sprite_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, RGBi * _color );
void ef9345_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
void ef9345_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
void ef9345_wait_vbl( Environment * _environment );
Variable * ef9345_new_image( Environment * _environment, int _width, int _height, int _mode );
void ef9345_get_image( Environment * _environment, char * _image, char * _x, char * _y, int _palette );

void ef9345_put_tile( Environment * _environment, char * _image, char * _x, char * _y );
void ef9345_put_tiles( Environment * _environment, char * _image, char * _x, char * _y, char *_w, char *_h );
void ef9345_move_tiles( Environment * _environment, char * _image, char * _x, char * _y );
void ef9345_use_tileset( Environment * _environment, char * _tileset );
void ef9345_tile_at( Environment * _environment, char * _x, char * _y, char *_result );

void ef9345_move_memory_video( Environment * _environment, char * _from, char * _to, char * _size );
void ef9345_move_video_memory( Environment * _environment, char * _from, char * _to, char * _size );
void ef9345_move_video_video( Environment * _environment, char * _from, char * _to, char * _size );

#endif