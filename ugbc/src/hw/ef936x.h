#ifndef __UGBC_EF936X__
#define __UGBC_EF936X__

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

#if defined(__pc128op__) || defined(__to8__)

    #define COLOR_BLACK					0
    #define COLOR_WHITE					1
    #define COLOR_DARK_RED			    2 // RED
    #define COLOR_RED					2
    #define COLOR_CYAN					3
    #define COLOR_VIOLET				4
    #define COLOR_DARK_GREEN		    5 // GREEN
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
    #define COLOR_DARK_WHITE			COLOR_GREY
    #define COLOR_LIGHT_WHITE			COLOR_WHITE
    #define COLOR_COUNT                 16

#elif defined(__mo5__)

    #define COLOR_BLACK					0
    #define COLOR_DARK_RED				1 // RED
    #define COLOR_RED					1
    #define COLOR_DARK_GREEN			2 // GREEN
    #define COLOR_GREEN					2
    #define COLOR_YELLOW				3
    #define COLOR_BLUE					4
    #define COLOR_VIOLET				5
    #define COLOR_CYAN					6
    #define COLOR_DARK_WHITE			7 // WHITE
    #define COLOR_WHITE					7
    #define COLOR_GREY					8
    #define COLOR_OLD_ROSE  			9
    #define COLOR_LIGHT_GREEN			10
    #define COLOR_SAND      			11
    #define COLOR_SKY_BLUE  			12
    #define COLOR_LIGHT_MAGENTA			13
    #define COLOR_LIGHT_CYAN			14
    #define COLOR_ORANGE    			15

    #define COLOR_BROWN					COLOR_SAND

    #define COLOR_LIGHT_RED				COLOR_OLD_ROSE
    #define COLOR_DARK_GREY				COLOR_GREY
    #define COLOR_LIGHT_BLUE			COLOR_SKY_BLUE
    #define COLOR_LIGHT_GREY			COLOR_GREY
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
    #define COLOR_MAGENTA       		COLOR_LIGHT_MAGENTA
    #define COLOR_LIGHT_WHITE			COLOR_WHITE

    #define COLOR_COUNT                 16

#endif

#define DEFAULT_PEN_COLOR           COLOR_WHITE
#define DEFAULT_PAPER_COLOR         COLOR_BLACK

#define BITMAP_MODE_40_COLUMN       0
#define BITMAP_MODE_80_COLUMN       1
#define BITMAP_MODE_BITMAP_4        2
#define BITMAP_MODE_BITMAP_16       3
#define BITMAP_MODE_PAGE            4

#define BITMAP_MODE_DEFAULT     BITMAP_MODE_BITMAP_4
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

#define IMAGE_WIDTH_SIZE                2
#define IMAGE_WIDTH_OFFSET              0
#define IMAGE_HEIGHT_SIZE               1
#define IMAGE_HEIGHT_OFFSET             2

#define TEXT_COLUMNS_COUNT          40
#define TEXT_ROWS_COUNT             25

#define DOUBLE_BUFFER_PAGE_0        0
#define DOUBLE_BUFFER_PAGE_1        1

int ef936x_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode );

void ef936x_initialization( Environment * _environment );
void ef936x_finalization( Environment * _environment );

void ef936x_back( Environment * _environment );
void ef936x_background_color( Environment * _environment, int _index, int _background_color );
void ef936x_background_color_semivars( Environment * _environment, int _index, char * _background_color );
void ef936x_background_color_vars( Environment * _environment, char * _index, char * _background_color );
void ef936x_background_color_get_vars( Environment * _environment, char * _index, char * _background_color );
void ef936x_border_color( Environment * _environment, char * _border_color );
void ef936x_collision( Environment * _environment, char * _sprite_mask, char * _result );
void ef936x_hit( Environment * _environment, char * _sprite_mask, char * _result );
void ef936x_next_raster( Environment * _environment );
void ef936x_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void ef936x_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void ef936x_sprite_common_color( Environment * _environment, char * _index, char * _common_color );
void ef936x_bitmap_enable( Environment * _environment, int _width, int _height, int _colors );
void ef936x_bitmap_disable( Environment * _environment );
void ef936x_bitmap_at( Environment * _environment, char * _address );
void ef936x_colormap_at( Environment * _environment, char * _address );
void ef936x_textmap_at( Environment * _environment, char * _address );
void ef936x_tiles_at( Environment * _environment, char * _address );
void ef936x_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height );

void ef936x_bank_select( Environment * _environment, int _bank );
void ef936x_screen_on( Environment * _environment );
void ef936x_screen_off( Environment * _environment );
void ef936x_screen_rows( Environment * _environment, char * _rows );
void ef936x_screen_columns( Environment * _environment, char * _columns );

void ef936x_sprite_data_from( Environment * _environment, char * _sprite, char * _address );
void ef936x_sprite_data_set( Environment * _environment, char * _sprite, char * _address );
void ef936x_sprite_enable( Environment * _environment, char *_sprite );
void ef936x_sprite_disable( Environment * _environment, char * _sprite );
void ef936x_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y );
void ef936x_sprite_expand_vertical( Environment * _environment, char * _sprite );
void ef936x_sprite_expand_horizontal( Environment * _environment, char * _sprite );
void ef936x_sprite_compress_vertical( Environment * _environment, char * _sprite );
void ef936x_sprite_compress_horizontal( Environment * _environment, char * _sprite );
void ef936x_sprite_multicolor( Environment * _environment, char * _sprite );
void ef936x_sprite_monocolor( Environment * _environment, char * _sprite );
void ef936x_sprite_color( Environment * _environment, char * _sprite, char * _color );
void ef936x_sprite_priority( Environment * _environment, char * _sprite, char * _priority );
void ef936x_vertical_scroll( Environment * _environment, char * _displacement );
void ef936x_horizontal_scroll( Environment * _environment, char * _displacement );

void ef936x_tiles_get( Environment * _environment, char * _result );
void ef936x_get_width( Environment * _environment, char * _result );
void ef936x_get_height( Environment * _environment, char * _result );

void ef936x_pset_int( Environment * _environment, int _x, int _y, int *_c );
void ef936x_pset_vars( Environment * _environment, char *_x, char *_y, char *_c );
void ef936x_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result );
void ef936x_cls( Environment * _environment );
void ef936x_cls_box( Environment * _environment, char * _x1, char * _y1, char * _w, char * _h );
void ef936x_scroll_text( Environment * _environment, int _direction, int _overlap );
void ef936x_hscroll_line( Environment * _environment, int _direction, int _overlap );
void ef936x_hscroll_screen( Environment * _environment, int _direction, int _overlap );
void ef936x_text( Environment * _environment, char * _text, char * _text_size, int _raw );
void ef936x_cline( Environment * _environment, char * _characters );
void ef936x_scroll( Environment * _environment, int _dx, int _dy );

Variable * ef936x_get_raster_line( Environment * _environment );

int ef936x_image_size( Environment * _environment, int _width, int _height, int _mode );
Variable * ef936x_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags );
void ef936x_put_image( Environment * _environment, Resource * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _flags );
void ef936x_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
Variable * ef936x_new_image( Environment * _environment, int _width, int _height, int _mode );
Variable * ef936x_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode );
Variable * ef936x_new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode );
void ef936x_get_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _palette );

void ef936x_calculate_sequence_frame_offset( Environment * _environment, char * _offset, char * _sequence, char * _frame, int _frame_size, int _frame_count );
void ef936x_calculate_sequence_frame_offset_regy( Environment * _environment, char * _sequence, char * _frame, int _frame_size, int _frame_count );

void ef936x_put_tile( Environment * _environment, char * _image, char * _x, char * _y );
void ef936x_put_tiles( Environment * _environment, char * _image, char * _x, char * _y, char *_w, char *_h );
void ef936x_move_tiles( Environment * _environment, char * _image, char * _x, char * _y );
void ef936x_use_tileset( Environment * _environment, char * _tileset );
void ef936x_tile_at( Environment * _environment, char * _x, char * _y, char * _result );

void ef936x_slice_image( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination );
int ef936x_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette );
void ef936x_flip_image( Environment * _environment, Resource * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _direction );

#endif