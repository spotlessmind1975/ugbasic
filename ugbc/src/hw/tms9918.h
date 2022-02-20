#ifndef __UGBC_TMS9918__
#define __UGBC_TMS9918__

/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

#define VDP_R0          0x80
#define VDP_R1          0x81
#define VDP_RNAME       0x82
#define VDP_RCOLORTABLE 0x83
#define VDP_RPATTERN    0x84
#define VDP_RSPRITEA    0x85
#define VDP_RSPRITEP    0x86
#define VDP_RCOLOR      0x87

#define WVDP( r, v ) \
    outline1("LD A, $%2.2x", r ); \
    outline0("LD E, A" ); \
    outline1("LD A, $%2.2x", v ); \
    outline0("CALL VDPSETREG" );
#define WVDP_R0( v )            WVDP( VDP_R0, v )
#define WVDP_R1( v )            WVDP( VDP_R1, v )
#define WVDP_RNAME( v )         WVDP( VDP_RNAME, v )
#define WVDP_RCOLORTABLE( v )   WVDP( VDP_RCOLORTABLE, v )
#define WVDP_RPATTERN( v )      WVDP( VDP_RPATTERN, v )
#define WVDP_RSPRITEA( v )      WVDP( VDP_RSPRITEA, v )
#define WVDP_RSPRITEP( v )      WVDP( VDP_RSPRITEP, v )
#define WVDP_RCOLOR( v )        WVDP( VDP_RCOLOR, v )

#define COLOR_BLACK					0x01
#define COLOR_WHITE					0x0f
#define COLOR_RED					0x08
#define COLOR_CYAN					0x07
#define COLOR_VIOLET				0x0d
#define COLOR_GREEN					0x02
#define COLOR_BLUE					0x07
#define COLOR_YELLOW				0x0b
#define COLOR_ORANGE				0x09
#define COLOR_BROWN					0x06
#define COLOR_LIGHT_RED				0x09
#define COLOR_DARK_GREY				0x0e
#define COLOR_GREY					0x0e
#define COLOR_LIGHT_GREEN			0x03
#define COLOR_LIGHT_BLUE			0x05
#define COLOR_LIGHT_GREY			0x0e
#define COLOR_DARK_BLUE				0x04
#define COLOR_MAGENTA				0x0d
#define COLOR_PURPLE				COLOR_VIOLET
#define COLOR_LAVENDER       		COLOR_VIOLET
#define COLOR_GOLD       			0x0a
#define COLOR_TURQUOISE       		COLOR_LIGHT_BLUE
#define COLOR_TAN       		    COLOR_BROWN
#define COLOR_YELLOW_GREEN       	0x03
#define COLOR_OLIVE_GREEN       	0x0c
#define COLOR_PINK       			COLOR_LIGHT_RED
#define COLOR_PEACH       			COLOR_PINK
#define COLOR_COUNT                 16

#define DEFAULT_PEN_COLOR           COLOR_WHITE
#define DEFAULT_PAPER_COLOR         COLOR_BLACK

#define TEXT_COLUMNS_COUNT          40
#define TEXT_ROWS_COUNT             25

#define TILEMAP_MODE_STANDARD       0           // Text Mode
#define TILEMAP_MODE_GRAPHIC1       1           // Graphics I Mode
#define BITMAP_MODE_GRAPHIC2        2           // Graphics II Mode
#define BITMAP_MODE_MULTICOLOR      3           // Multicolor Mode

#define BITMAP_MODE_DEFAULT     BITMAP_MODE_GRAPHIC2

#define SPRITE_COUNT                32
#define SPRITE_WIDTH                8
#define SPRITE_HEIGHT               8

#define SPRITE_FLAG_MULTICOLOR          0x0010
#define SPRITE_FLAG_MONOCOLOR           0x0000
#define SPRITE_FLAG_EXPAND_VERTICAL     0x0040
#define SPRITE_FLAG_COMPRESS_VERTICAL   0x0000
#define SPRITE_FLAG_EXPAND_HORIZONTAL   0x0080
#define SPRITE_FLAG_COMPRESS_HORIZONTAL 0x0000

int tms9918_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode );

void tms9918_initialization( Environment * _environment );
void tms9918_finalization( Environment * _environment );

void tms9918_back( Environment * _environment );
void tms9918_background_color( Environment * _environment, int _index, int _background_color );
void tms9918_background_color_vars( Environment * _environment, char * _index, char * _background_color );
void tms9918_background_color_semivars( Environment * _environment, int _index, char * _background_color );
void tms9918_background_color_get_vars( Environment * _environment, char * _index, char * _background_color );
void tms9918_border_color( Environment * _environment, char * _border_color );
Variable * tms9918_collision( Environment * _environment, char * _sprite );
void tms9918_hit( Environment * _environment, char * _sprite_mask, char * _result );
void tms9918_next_raster( Environment * _environment );
void tms9918_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void tms9918_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void tms9918_sprite_common_color( Environment * _environment, char * _index, char * _common_color );
void tms9918_bitmap_enable( Environment * _environment, int _width, int _height, int _colors );
void tms9918_bitmap_disable( Environment * _environment );
void tms9918_bitmap_at( Environment * _environment, char * _address );
void tms9918_colormap_at( Environment * _environment, char * _address );
void tms9918_textmap_at( Environment * _environment, char * _address );
void tms9918_tiles_at( Environment * _environment, char * _address );
void tms9918_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height );

void tms9918_bank_select( Environment * _environment, int _bank );
void tms9918_enable_ecm( Environment * _environment );
void tms9918_disable_ecm( Environment * _environment );
void tms9918_enable_mcm( Environment * _environment );
void tms9918_disable_mcm( Environment * _environment );
void tms9918_screen_on( Environment * _environment );
void tms9918_screen_off( Environment * _environment );
void tms9918_screen_rows( Environment * _environment, char * _rows );
void tms9918_screen_columns( Environment * _environment, char * _columns );

void tms9918_sprite_data_from( Environment * _environment, char * _sprite, char * _image );
void tms9918_sprite_enable( Environment * _environment, char *_sprite );
void tms9918_sprite_disable( Environment * _environment, char * _sprite );
void tms9918_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y );
void tms9918_sprite_expand_vertical( Environment * _environment, char * _sprite );
void tms9918_sprite_expand_horizontal( Environment * _environment, char * _sprite );
void tms9918_sprite_compress_vertical( Environment * _environment, char * _sprite );
void tms9918_sprite_compress_horizontal( Environment * _environment, char * _sprite );
void tms9918_sprite_multicolor( Environment * _environment, char * _sprite );
void tms9918_sprite_monocolor( Environment * _environment, char * _sprite );
void tms9918_sprite_color( Environment * _environment, char * _sprite, char * _color );
void tms9918_vertical_scroll( Environment * _environment, char * _displacement );
void tms9918_horizontal_scroll( Environment * _environment, char * _displacement );
void tms9918_busy_wait( Environment * _environment, char * _timing );

void tms9918_tiles_get( Environment * _environment, char * _result );
void tms9918_get_width( Environment * _environment, char * _result );
void tms9918_tiles_get_width( Environment * _environment, char * _result );
void tms9918_get_height( Environment * _environment, char * _result );
void tms9918_tiles_get_height( Environment * _environment, char * _result );

void tms9918_point_at_int( Environment * _environment, int _x, int _y );
void tms9918_point_at_vars( Environment * _environment, char *_x, char *_y );
void tms9918_point( Environment * _environment, char *_x, char *_y, char * _result );
void tms9918_cls( Environment * _environment );
void tms9918_scroll_text( Environment * _environment, int _direction );
void tms9918_hscroll_line( Environment * _environment, int _direction );
void tms9918_hscroll_screen( Environment * _environment, int _direction );
void tms9918_text( Environment * _environment, char * _text, char * _text_size );
void tms9918_cline( Environment * _environment, char * _characters );
void tms9918_scroll( Environment * _environment, int _dx, int _dy );

Variable * tms9918_get_raster_line( Environment * _environment );

Variable * tms9918_image_converter( Environment * _environment, char * _data, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags );
Variable * tms9918_sprite_converter( Environment * _environment, char * _data, int _width, int _height, RGBi * _color );
void tms9918_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, int _frame_size, int _flags );
void tms9918_wait_vbl( Environment * _environment );
Variable * tms9918_new_image( Environment * _environment, int _width, int _height, int _mode );
void tms9918_get_image( Environment * _environment, char * _image, char * _x, char * _y );

void tms9918_put_tile( Environment * _environment, char * _image, char * _x, char * _y );
void tms9918_put_tiles( Environment * _environment, char * _image, char * _x, char * _y, char *_w, char *_h );
void tms9918_move_tiles( Environment * _environment, char * _image, char * _x, char * _y );
void tms9918_use_tileset( Environment * _environment, char * _tileset );
void tms9918_tile_at( Environment * _environment, char * _x, char * _y, char *_result );

void tms9918_move_memory_video( Environment * _environment, char * _from, char * _to, char * _size );
void tms9918_move_video_memory( Environment * _environment, char * _from, char * _to, char * _size );
void tms9918_move_video_video( Environment * _environment, char * _from, char * _to, char * _size );

#endif