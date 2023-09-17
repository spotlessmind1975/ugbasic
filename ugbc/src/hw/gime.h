#ifndef __UGBC_GIME__
#define __UGBC_GIME__

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

#define COLOR_BLACK					0
#define COLOR_GREEN					COLOR_BLACK
#define COLOR_YELLOW				1
#define COLOR_BLUE					2
#define COLOR_RED					3
#define COLOR_WHITE					COLOR_YELLOW
#define COLOR_CYAN					COLOR_BLUE
#define COLOR_MAGENTA				COLOR_BLUE
#define COLOR_ORANGE				COLOR_BLUE

#define COLOR_VIOLET				COLOR_MAGENTA
#define COLOR_BROWN					COLOR_ORANGE
#define COLOR_LIGHT_RED				COLOR_ORANGE
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
#define COLOR_LIGHT_WHITE			COLOR_WHITE

#define DEFAULT_PEN_COLOR           COLOR_WHITE
#define DEFAULT_PAPER_COLOR         COLOR_BLACK

#define COLOR_COUNT                 4

#define TEXT_COLUMNS_COUNT          32
#define TEXT_ROWS_COUNT             16

#define TILEMAP_MODE_INTERNAL       0       // Alphanumeric Internal	32 × 16	2	512

#define BITMAP_MODE_DEFAULT     TILEMAP_MODE_INTERNAL
#define BITMAP_MODE_STANDARD    BITMAP_MODE_DEFAULT

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

#define SPRITE_COUNT               0
#define SPRITE_WIDTH               0
#define SPRITE_HEIGHT              0

#define SPRITE_FLAG_MULTICOLOR          0x0010
#define SPRITE_FLAG_MONOCOLOR           0x0000
#define SPRITE_FLAG_EXPAND_VERTICAL     0x0040
#define SPRITE_FLAG_COMPRESS_VERTICAL   0x0000
#define SPRITE_FLAG_EXPAND_HORIZONTAL   0x0080
#define SPRITE_FLAG_COMPRESS_HORIZONTAL 0x0000

#define IMAGE_WIDTH_SIZE                1
#define IMAGE_WIDTH_OFFSET              0
#define IMAGE_HEIGHT_SIZE               1
#define IMAGE_HEIGHT_OFFSET             1

int gime_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode );

void gime_initialization( Environment * _environment );
void gime_finalization( Environment * _environment );

void gime_back( Environment * _environment );
void gime_background_color( Environment * _environment, char * _index, char * _background_color );
void gime_border_color( Environment * _environment, char * _border_color );
void gime_collision( Environment * _environment, char * _sprite_mask, char * _result );
void gime_hit( Environment * _environment, char * _sprite_mask, char * _result );
void gime_next_raster( Environment * _environment );
void gime_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void gime_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void gime_sprite_common_color( Environment * _environment, char * _index, char * _common_color );
void gime_bitmap_enable( Environment * _environment, int _width, int _height, int _colors );
void gime_bitmap_disable( Environment * _environment );
void gime_bitmap_at( Environment * _environment, char * _address );
void gime_colormap_at( Environment * _environment, char * _address );
void gime_textmap_at( Environment * _environment, char * _address );
void gime_tiles_at( Environment * _environment, char * _address );
void gime_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height );

void gime_bank_select( Environment * _environment, int _bank );
void gime_enable_ecm( Environment * _environment );
void gime_disable_ecm( Environment * _environment );
void gime_enable_mcm( Environment * _environment );
void gime_disable_mcm( Environment * _environment );
void gime_screen_on( Environment * _environment );
void gime_screen_off( Environment * _environment );
void gime_screen_rows( Environment * _environment, char * _rows );
void gime_screen_columns( Environment * _environment, char * _columns );

void gime_sprite_data_from( Environment * _environment, char * _sprite, char * _address );
void gime_sprite_enable( Environment * _environment, char *_sprite );
void gime_sprite_disable( Environment * _environment, char * _sprite );
void gime_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y );
void gime_sprite_expand_vertical( Environment * _environment, char * _sprite );
void gime_sprite_expand_horizontal( Environment * _environment, char * _sprite );
void gime_sprite_compress_vertical( Environment * _environment, char * _sprite );
void gime_sprite_compress_horizontal( Environment * _environment, char * _sprite );
void gime_sprite_multicolor( Environment * _environment, char * _sprite );
void gime_sprite_monocolor( Environment * _environment, char * _sprite );
void gime_sprite_color( Environment * _environment, char * _sprite, char * _color );
void gime_vertical_scroll( Environment * _environment, char * _displacement );
void gime_horizontal_scroll( Environment * _environment, char * _displacement );

void gime_tiles_get( Environment * _environment, char * _result );
void gime_get_width( Environment * _environment, char * _result );
void gime_tiles_get_width( Environment * _environment, char * _result );
void gime_get_height( Environment * _environment, char * _result );
void gime_tiles_get_height( Environment * _environment, char * _result );

void gime_point_at_int( Environment * _environment, int _x, int _y );
void gime_point_at_vars( Environment * _environment, char *_x, char *_y );
void gime_point( Environment * _environment, char *_x, char *_y, char * _result );
void gime_cls( Environment * _environment );
void gime_scroll_text( Environment * _environment, int _direction );
void gime_hscroll_line( Environment * _environment, int _direction );
void gime_hscroll_screen( Environment * _environment, int _direction );
void gime_text( Environment * _environment, char * _text, char * _text_size );
void gime_cline( Environment * _environment, char * _characters );
void gime_scroll( Environment * _environment, int _dx, int _dy );

Variable * gime_get_raster_line( Environment * _environment );

Variable * gime_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags );
void gime_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
void gime_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
Variable * gime_new_image( Environment * _environment, int _width, int _height, int _mode );
void gime_get_image( Environment * _environment, char * _image, char * _x, char * _y, int _palette );

void gime_put_tile( Environment * _environment, char * _image, char * _x, char * _y );
void gime_put_tiles( Environment * _environment, char * _image, char * _x, char * _y, char *_w, char *_h );
void gime_move_tiles( Environment * _environment, char * _image, char * _x, char * _y );
void gime_use_tileset( Environment * _environment, char * _tileset );
void gime_tile_at( Environment * _environment, char * _x, char * _y, char * _result );
void gime_slice_image( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination );
int gime_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette );

#endif