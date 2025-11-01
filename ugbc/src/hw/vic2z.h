#ifndef __UGBC_VIC2Z__
#define __UGBC_VIC2Z__

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
#define COLOR_RED					2
#define COLOR_CYAN					3
#define COLOR_VIOLET				4
#define COLOR_GREEN					5
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

#define IMAGE_WIDTH_SIZE                2
#define IMAGE_WIDTH_OFFSET              0
#define IMAGE_HEIGHT_SIZE               1
#define IMAGE_HEIGHT_OFFSET             2

#define DEFAULT_PEN_COLOR           COLOR_WHITE
#define DEFAULT_PAPER_COLOR         COLOR_BLACK

#define TEXT_COLUMNS_COUNT          40
#define TEXT_ROWS_COUNT             25

#define BITMAP_MODE_STANDARD        2           // Standard Bitmap Mode     320 x 200 x 2
#define BITMAP_MODE_MULTICOLOR      3           // Multicolor Bitmap Mode   160 x 200 x 4
#define BITMAP_MODE_AH              5           // Advanced HiRes           320 x 200 x 16 (w/l)
#define BITMAP_MODE_AIFLI	        6           
#define BITMAP_MODE_ASSLACE         7
#define BITMAP_MODE_ECI             8
#define BITMAP_MODE_IAFLI           9
#define BITMAP_MODE_IH	           10
#define BITMAP_MODE_MRFLI          11
#define BITMAP_MODE_MUCSUFLI       12
#define BITMAP_MODE_MUCSUH         13
#define BITMAP_MODE_MUFLI          14
#define BITMAP_MODE_MUIFLI         15
#define BITMAP_MODE_NUFLI          16
#define BITMAP_MODE_NUIFLI         17
#define BITMAP_MODE_SH             18
#define BITMAP_MODE_SHFLI          19
#define BITMAP_MODE_SHI	           20
#define BITMAP_MODE_SHIFLI         21
#define BITMAP_MODE_SHIFXL         22
#define BITMAP_MODE_UFLI           23
#define BITMAP_MODE_UIFLI          24
#define BITMAP_MODE_TRIFLI         25
#define BITMAP_MODE_XFLI           26
#define BITMAP_MODE_XIFLI          27
#define BITMAP_MODE_FLI            28
#define BITMAP_MODE_HCB	           29
#define BITMAP_MODE_IFLI           30
#define BITMAP_MODE_MUCSU          31
#define BITMAP_MODE_MCI            32
#define BITMAP_MODE_MEGATEXT       33
#define BITMAP_MODE_PRS            34

#define BITMAP_MODE_DEFAULT     BITMAP_MODE_STANDARD

#define TILEMAP_MODE_STANDARD       0           // Standard Character Mode        40 x 25 x 16
#define TILEMAP_MODE_MULTICOLOR     1           // Multicolor Character Mode      40 x 25 x 16
#define TILEMAP_MODE_EXTENDED       4           // Extended Background Color Mode 40 x 25 x 20

#define SPRITE_COUNT                8
#define SPRITE_WIDTH                24
#define SPRITE_HEIGHT               21
#define SPRITE_X_MIN                0
#define SPRITE_Y_MIN                0
#define SPRITE_X_MAX                366
#define SPRITE_Y_MAX                255

#define SCREEN_SPRITE_RATIO_X       200
#define SCREEN_SPRITE_RATIO_Y       100
#define SCREEN_BORDER_X             23
#define SCREEN_BORDER_Y             50

#define DOUBLE_BUFFER_PAGE_0        0
#define DOUBLE_BUFFER_PAGE_1        1

int vic2z_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode );

void vic2z_initialization( Environment * _environment );
void vic2z_finalization( Environment * _environment );

void vic2z_back( Environment * _environment );
void vic2z_background_color( Environment * _environment, int _index, int _background_color );
void vic2z_background_color_vars( Environment * _environment, char * _index, char * _background_color );
void vic2z_background_color_semivars( Environment * _environment, int _index, char * _background_color );
void vic2z_background_color_get_vars( Environment * _environment, char * _index, char * _background_color );
void vic2z_border_color( Environment * _environment, char * _border_color );
Variable * vic2z_collision( Environment * _environment, char * _sprite );
void vic2z_hit( Environment * _environment, char * _sprite_mask, char * _result );
void vic2z_next_raster( Environment * _environment );
void vic2z_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void vic2z_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void vic2z_sprite_common_color( Environment * _environment, char * _index, char * _common_color );
void vic2z_bitmap_enable( Environment * _environment, int _width, int _height, int _colors );
void vic2z_bitmap_disable( Environment * _environment );
void vic2z_bitmap_at( Environment * _environment, char * _address );
void vic2z_colormap_at( Environment * _environment, char * _address );
void vic2z_textmap_at( Environment * _environment, char * _address );
void vic2z_tiles_at( Environment * _environment, char * _address );
void vic2z_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height );

void vic2z_bank_select( Environment * _environment, int _bank );
void vic2z_screen_on( Environment * _environment );
void vic2z_screen_off( Environment * _environment );
void vic2z_screen_rows( Environment * _environment, char * _rows );
void vic2z_screen_columns( Environment * _environment, char * _columns );

void vic2z_sprite_data_from( Environment * _environment, char * _sprite, char * _address );
void vic2z_sprite_data_set( Environment * _environment, char * _sprite, char * _address );
void vic2z_sprite_enable( Environment * _environment, char *_sprite );
void vic2z_sprite_disable( Environment * _environment, char * _sprite );
void vic2z_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y );
void vic2z_sprite_expand_vertical( Environment * _environment, char * _sprite );
void vic2z_sprite_expand_horizontal( Environment * _environment, char * _sprite );
void vic2z_sprite_compress_vertical( Environment * _environment, char * _sprite );
void vic2z_sprite_compress_horizontal( Environment * _environment, char * _sprite );
void vic2z_sprite_multicolor( Environment * _environment, char * _sprite );
void vic2z_sprite_monocolor( Environment * _environment, char * _sprite );
void vic2z_sprite_color( Environment * _environment, char * _sprite, char * _color );
void vic2z_sprite_priority( Environment * _environment, char * _sprite, char * _priority );
void vic2z_vertical_scroll( Environment * _environment, char * _displacement );
void vic2z_horizontal_scroll( Environment * _environment, char * _displacement );
void vic2z_busy_wait( Environment * _environment, char * _timing );

void vic2z_tiles_get( Environment * _environment, char * _result );
void vic2z_get_width( Environment * _environment, char * _result );
void vic2z_get_height( Environment * _environment, char * _result );

void vic2z_pset_int( Environment * _environment, int _x, int _y, int *_c );
void vic2z_pset_vars( Environment * _environment, char *_x, char *_y, char *_c );
void vic2z_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result );
void vic2z_cls( Environment * _environment );
void vic2z_cls_box( Environment * _environment, char * _x1, char * _y1, char * _w, char * _h );
void vic2z_scroll_text( Environment * _environment, int _direction, int _overlap );
void vic2z_hscroll_line( Environment * _environment, int _direction, int _overlap );
void vic2z_hscroll_screen( Environment * _environment, int _direction, int _overlap );
void vic2z_text( Environment * _environment, char * _text, char * _text_size, int _raw );
void vic2z_cline( Environment * _environment, char * _characters );
void vic2z_scroll( Environment * _environment, int _dx, int _dy );

Variable * vic2z_get_raster_line( Environment * _environment );

Variable * vic2z_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags );
Variable * vic2z_sprite_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, RGBi * _color, int _flags );
void vic2z_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _flags );
void vic2z_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
void vic2z_wait_vbl( Environment * _environment );
Variable * vic2z_new_image( Environment * _environment, int _width, int _height, int _mode );
Variable * vic2z_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode );
Variable * vic2z_new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode );
void vic2z_get_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _palette );

void vic2z_put_tile( Environment * _environment, char * _image, char * _x, char * _y );
void vic2z_put_tiles( Environment * _environment, char * _image, char * _x, char * _y, char *_w, char *_h );
void vic2z_move_tiles( Environment * _environment, char * _image, char * _x, char * _y );
void vic2z_use_tileset( Environment * _environment, char * _tileset );
void vic2z_tile_at( Environment * _environment, char * _x, char * _y, char * _result );

void vic2z_slice_image( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination );

#endif