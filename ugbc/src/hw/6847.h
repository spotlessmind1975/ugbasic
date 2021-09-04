#ifndef __UGBC_6847__
#define __UGBC_6847__

/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
#define COLOR_COUNT                 16

#define TEXT_COLUMNS_COUNT          32
#define TEXT_ROWS_COUNT             16

#define TILEMAP_MODE_INTERNAL       0       // Alphanumeric Internal	32 × 16	2	512
#define TILEMAP_MODE_EXTERNAL       1       // Alphanumeric External	32 × 16	2	512
#define TILEMAP_MODE_SEMIGRAPHICS4  2       // Semigraphics 4	        64 × 32	8	512
#define TILEMAP_MODE_SEMIGRAPHICS6  3       // Semigraphics 6	        64 × 48	4	512

#define BITMAP_MODE_COLOR1          4       // Color Graphics 1	64 × 64	4	1024
#define BITMAP_MODE_RESOLUTION1     5       // Resolution Graphics 1	128 × 64	1 + Black	1024
#define BITMAP_MODE_COLOR2          6       // Color Graphics 2	128 × 64	4	2048
#define BITMAP_MODE_RESOLUTION2	    7       // Resolution Graphics 2 128 × 96	1 + Black	1536
#define BITMAP_MODE_COLOR3          8       // Color Graphics 3	128 × 96	4	3072
#define BITMAP_MODE_RESOLUTION3     9       // Resolution Graphics 3	128 × 192	1 + Black	3072
#define BITMAP_MODE_COLOR6          10      // Color Graphics 6	128 × 192	4	6144
#define BITMAP_MODE_RESOLUTION6     11      // Resolution Graphics 6	256 × 192	1 + Black	614

int c6847_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode );

void c6847_initialization( Environment * _environment );

void c6847_back( Environment * _environment );
void c6847_background_color( Environment * _environment, char * _index, char * _background_color );
void c6847_border_color( Environment * _environment, char * _border_color );
void c6847_collision( Environment * _environment, char * _sprite_mask, char * _result );
void c6847_hit( Environment * _environment, char * _sprite_mask, char * _result );
void c6847_next_raster( Environment * _environment );
void c6847_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void c6847_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void c6847_sprite_common_color( Environment * _environment, char * _index, char * _common_color );
void c6847_bitmap_enable( Environment * _environment, int _width, int _height, int _colors );
void c6847_bitmap_disable( Environment * _environment );
void c6847_bitmap_at( Environment * _environment, char * _address );
void c6847_colormap_at( Environment * _environment, char * _address );
void c6847_textmap_at( Environment * _environment, char * _address );
void c6847_tiles_at( Environment * _environment, char * _address );
void c6847_tilemap_enable( Environment * _environment, int _width, int _height, int _colors );

void c6847_bank_select( Environment * _environment, int _bank );
void c6847_enable_ecm( Environment * _environment );
void c6847_disable_ecm( Environment * _environment );
void c6847_enable_mcm( Environment * _environment );
void c6847_disable_mcm( Environment * _environment );
void c6847_screen_on( Environment * _environment );
void c6847_screen_off( Environment * _environment );
void c6847_screen_rows( Environment * _environment, char * _rows );

void c6847_sprite_data_from( Environment * _environment, char * _sprite, char * _address );
void c6847_sprite_enable( Environment * _environment, char *_sprite );
void c6847_sprite_disable( Environment * _environment, char * _sprite );
void c6847_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y );
void c6847_sprite_expand_vertical( Environment * _environment, char * _sprite );
void c6847_sprite_expand_horizontal( Environment * _environment, char * _sprite );
void c6847_sprite_compress_vertical( Environment * _environment, char * _sprite );
void c6847_sprite_compress_horizontal( Environment * _environment, char * _sprite );
void c6847_sprite_multicolor( Environment * _environment, char * _sprite );
void c6847_sprite_monocolor( Environment * _environment, char * _sprite );
void c6847_sprite_color( Environment * _environment, char * _sprite, char * _color );
void c6847_vertical_scroll( Environment * _environment, char * _displacement );
void c6847_horizontal_scroll( Environment * _environment, char * _displacement );
void c6847_busy_wait( Environment * _environment, char * _timing );

void c6847_get_width( Environment * _environment, char * _result );
void c6847_get_height( Environment * _environment, char * _result );

void c6847_point_at_int( Environment * _environment, int _x, int _y );
void c6847_point_at_vars( Environment * _environment, char *_x, char *_y );
void c6847_point( Environment * _environment, char *_x, char *_y, char * _result );
void c6847_cls( Environment * _environment );
void c6847_scroll_text( Environment * _environment, int _direction );
void c6847_hscroll_line( Environment * _environment, int _direction );
void c6847_hscroll_screen( Environment * _environment, int _direction );
void c6847_text_at( Environment * _environment, char * _x, char * _y, char * _text, char * _text_size, char * _pen, char *_ww );
void c6847_cline( Environment * _environment, char * _characters );

Variable * c6847_image_converter( Environment * _environment, char * _data, int _width, int _height, int _mode );
void c6847_put_image( Environment * _environment, char * _image, char * _x, char * _y );

#endif