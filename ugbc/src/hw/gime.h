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

#define RGB2GIME( r, g, b )     ( ( (r/64) & 0x02 ) << (5-1) ) | ( ( (g/64) & 0x02 ) << (4-1) ) | ( ( (b/64) & 0x02 ) << (3-1) ) | ( ( (r/64) & 0x01 ) << 2 ) | ( ( (g/64) & 0x01 ) << 1 ) | ( ( (b/64) & 0x01 ) )

#define COLOR_BLACK					RGB2GIME( 0x00, 0x00, 0x00 )
#define COLOR_BLUE					RGB2GIME( 0x00, 0x00, 0x80 )
#define COLOR_LIGHT_BLUE			RGB2GIME( 0x00, 0x00, 0xff )
#define COLOR_RED					RGB2GIME( 0x80, 0x00, 0x00 )
#define COLOR_MAGENTA				RGB2GIME( 0x80, 0x00, 0x80 )
#define COLOR_MAUVE 				RGB2GIME( 0x80, 0x40, 0x80 )
#define COLOR_LIGHT_RED				RGB2GIME( 0xff, 0x00, 0x00 )
#define COLOR_PURPLE				RGB2GIME( 0x80, 0x00, 0x80 )
#define COLOR_LIGHT_MAGENTA			RGB2GIME( 0xff, 0x00, 0xff )
#define COLOR_GREEN					RGB2GIME( 0x00, 0x80, 0x00 ) 
#define COLOR_CYAN					RGB2GIME( 0x00, 0x80, 0x80 ) 
#define COLOR_DARK_CYAN				RGB2GIME( 0x00, 0x40, 0x40 ) 
#define COLOR_YELLOW				RGB2GIME( 0x80, 0x80, 0x00 ) 
#define COLOR_WHITE					RGB2GIME( 0x80, 0x80, 0x80 ) 
#define COLOR_PASTEL_BLUE			RGB2GIME( 0xa7, 0xc7, 0xe7 ) 
#define COLOR_ORANGE				RGB2GIME( 0xff, 0xa5, 0x00 ) 
#define COLOR_PINK       			RGB2GIME( 0xff, 0xc0, 0xcb ) 
#define COLOR_PASTEL_MAGENTA		RGB2GIME( 0xff, 0x00, 0xff )
#define COLOR_LIGHT_GREEN			RGB2GIME( 0x00, 0xf0, 0x00 )
#define COLOR_SEA_GREEN			    RGB2GIME( 0x00, 0xf0, 0x20 )
#define COLOR_LIGHT_CYAN		    RGB2GIME( 0x00, 0xff, 0xff ) 

#define COLOR_LIME      		    RGB2GIME( 0xcc, 0xff, 0x00 ) 
#define COLOR_PASTEL_GREEN    	    COLOR_LIGHT_GREEN
#define COLOR_PASTEL_CYAN    	    COLOR_LIGHT_CYAN
#define COLOR_LIGHT_YELLOW    	    RGB2GIME( 0xf0, 0xf0, 0x00 ) 
#define COLOR_PASTEL_YELLOW   	    COLOR_LIGHT_YELLOW
#define COLOR_LIGHT_WHITE   	    RGB2GIME( 0xff, 0xff, 0xff ) 

#define COLOR_VIOLET				COLOR_PURPLE
#define COLOR_BROWN					COLOR_RED
#define COLOR_DARK_GREY				COLOR_BLACK
#define COLOR_GREY					COLOR_BLACK
#define COLOR_LIGHT_GREY			COLOR_WHITE
#define COLOR_DARK_BLUE				COLOR_BLUE
#define COLOR_LAVENDER       		COLOR_VIOLET
#define COLOR_GOLD       			COLOR_YELLOW
#define COLOR_TURQUOISE       		COLOR_LIGHT_BLUE
#define COLOR_TAN       		    COLOR_BROWN
#define COLOR_YELLOW_GREEN       	COLOR_YELLOW
#define COLOR_OLIVE_GREEN       	COLOR_PASTEL_GREEN
#define COLOR_PEACH       			COLOR_PINK
#define COLOR_COUNT                 64

#define DEFAULT_PEN_COLOR           COLOR_WHITE
#define DEFAULT_PAPER_COLOR         COLOR_BLACK

#define TEXT_COLUMNS_COUNT          40
#define TEXT_ROWS_COUNT             25

#define TILEMAP_MODE( x )       (0x00 | ( x & 0x0f ) )
#define BITMAP2_MODE( x )       (0x40 | ( x & 0x1f ) )
#define BITMAP4_MODE( x )       (0x60 | ( x & 0x1f ) )
#define BITMAP16_MODE( x )       (0xe0 | ( x & 0x1f ) )

// 12 -> 4 bit (0..15)
// 0000 xxxx

#define TILEMAP_MODE_32X24      TILEMAP_MODE( 0 )       // Alphanumeric 32 columns x 24 rows
#define TILEMAP_MODE_32X25      TILEMAP_MODE( 1 )       // Alphanumeric 32 columns x 25 rows
#define TILEMAP_MODE_32X28      TILEMAP_MODE( 2 )       // Alphanumeric 32 columns x 28 rows
#define TILEMAP_MODE_40X24      TILEMAP_MODE( 3 )       // Alphanumeric 40 columns x 24 rows
#define TILEMAP_MODE_40X25      TILEMAP_MODE( 4 )       // Alphanumeric 40 columns x 25 rows
#define TILEMAP_MODE_40X28      TILEMAP_MODE( 5 )       // Alphanumeric 40 columns x 28 rows
#define TILEMAP_MODE_64X24      TILEMAP_MODE( 6 )       // Alphanumeric 64 columns x 24 rows
#define TILEMAP_MODE_64X25      TILEMAP_MODE( 7 )       // Alphanumeric 64 columns x 25 rows
#define TILEMAP_MODE_64X28      TILEMAP_MODE( 8 )       // Alphanumeric 64 columns x 28 rows
#define TILEMAP_MODE_80X24      TILEMAP_MODE( 9 )       // Alphanumeric 80 columns x 24 rows
#define TILEMAP_MODE_80X25      TILEMAP_MODE( 10 )      // Alphanumeric 80 columns x 25 rows
#define TILEMAP_MODE_80X28      TILEMAP_MODE( 11 )      // Alphanumeric 80 columns x 28 rows

// 18 -> 5 bit (0..32)
// 010y yyyy

#define BITMAP_MODE_128x192x2       BITMAP2_MODE( 0 )   // Graphic 128x192x2
#define BITMAP_MODE_128x200x2       BITMAP2_MODE( 1 )   // Graphic 128x200x2
#define BITMAP_MODE_128x225x2       BITMAP2_MODE( 2 )   // Graphic 128x225x2

#define BITMAP_MODE_160x192x2       BITMAP2_MODE( 3 )   // Graphic 160x192x2
#define BITMAP_MODE_160x200x2       BITMAP2_MODE( 4 )   // Graphic 160x200x2
#define BITMAP_MODE_160x225x2       BITMAP2_MODE( 5 )   // Graphic 160x225x2

#define BITMAP_MODE_256x192x2       BITMAP2_MODE( 6 )   // Graphic 256x192x2
#define BITMAP_MODE_256x200x2       BITMAP2_MODE( 7 )   // Graphic 256x200x2
#define BITMAP_MODE_256x225x2       BITMAP2_MODE( 8 )   // Graphic 256x225x2

#define BITMAP_MODE_320x192x2       BITMAP2_MODE( 9 )   // Graphic 320x192x2
#define BITMAP_MODE_320x200x2       BITMAP2_MODE( 10 )  // Graphic 320x200x2
#define BITMAP_MODE_320x225x2       BITMAP2_MODE( 11 )  // Graphic 320x225x2

#define BITMAP_MODE_512x192x2       BITMAP2_MODE( 12 )  // Graphic 512x192x2
#define BITMAP_MODE_512x200x2       BITMAP2_MODE( 13 )  // Graphic 512x200x2
#define BITMAP_MODE_512x225x2       BITMAP2_MODE( 14 )  // Graphic 512x225x2

#define BITMAP_MODE_640x192x2       BITMAP2_MODE( 15 )  // Graphic 640x192x2
#define BITMAP_MODE_640x200x2       BITMAP2_MODE( 16 )  // Graphic 640x200x2
#define BITMAP_MODE_640x225x2       BITMAP2_MODE( 17 )  // Graphic 640x225x2

// 24 -> 5 bit (0..32)
// 011y yyyy

#define BITMAP_MODE_64x192x4        BITMAP4_MODE( 0 )   // Graphic 64x192x4
#define BITMAP_MODE_64x200x4        BITMAP4_MODE( 1 )   // Graphic 64x200x4
#define BITMAP_MODE_64x225x4        BITMAP4_MODE( 2 )   // Graphic 64x225x4

#define BITMAP_MODE_80x192x4        BITMAP4_MODE( 3 )   // Graphic 80x192x4
#define BITMAP_MODE_80x200x4        BITMAP4_MODE( 4 )   // Graphic 80x200x4
#define BITMAP_MODE_80x225x4        BITMAP4_MODE( 5 )   // Graphic 80x225x4

#define BITMAP_MODE_128x192x4       BITMAP4_MODE( 6 )   // Graphic 128x192x4
#define BITMAP_MODE_128x200x4       BITMAP4_MODE( 7 )   // Graphic 128x200x4
#define BITMAP_MODE_128x225x4       BITMAP4_MODE( 8 )   // Graphic 128x225x4

#define BITMAP_MODE_160x192x4       BITMAP4_MODE( 9 )   // Graphic 160x192x4
#define BITMAP_MODE_160x200x4       BITMAP4_MODE( 10 )  // Graphic 160x200x4
#define BITMAP_MODE_160x225x4       BITMAP4_MODE( 11 )  // Graphic 160x225x4

#define BITMAP_MODE_256x192x4       BITMAP4_MODE( 12 )  // Graphic 256x192x4
#define BITMAP_MODE_256x200x4       BITMAP4_MODE( 13 )  // Graphic 256x200x4
#define BITMAP_MODE_256x225x4       BITMAP4_MODE( 14 )  // Graphic 256x225x4

#define BITMAP_MODE_320x192x4       BITMAP4_MODE( 15 )  // Graphic 320x192x4
#define BITMAP_MODE_320x200x4       BITMAP4_MODE( 16 )  // Graphic 320x200x4
#define BITMAP_MODE_320x225x4       BITMAP4_MODE( 17 )  // Graphic 320x225x4

#define BITMAP_MODE_512x192x4       BITMAP4_MODE( 18 )  // Graphic 512x192x4
#define BITMAP_MODE_512x200x4       BITMAP4_MODE( 19 )  // Graphic 512x200x4
#define BITMAP_MODE_512x225x4       BITMAP4_MODE( 20 )  // Graphic 512x225x4

#define BITMAP_MODE_640x192x4       BITMAP4_MODE( 21 )  // Graphic 640x192x4
#define BITMAP_MODE_640x200x4       BITMAP4_MODE( 22 )  // Graphic 640x200x4
#define BITMAP_MODE_640x225x4       BITMAP4_MODE( 23 )  // Graphic 640x225x4

// 18 -> 5 bit (0..32)
// 111y yyyy

#define BITMAP_MODE_64x192x16       BITMAP16_MODE( 0 )  // Graphic 64x192x16
#define BITMAP_MODE_64x200x16       BITMAP16_MODE( 1 )  // Graphic 64x200x16
#define BITMAP_MODE_64x225x16       BITMAP16_MODE( 2 )  // Graphic 64x225x16

#define BITMAP_MODE_80x192x16       BITMAP16_MODE( 3 )  // Graphic 80x192x16
#define BITMAP_MODE_80x200x16       BITMAP16_MODE( 4 )  // Graphic 80x200x16
#define BITMAP_MODE_80x225x16       BITMAP16_MODE( 5 )  // Graphic 80x225x16

#define BITMAP_MODE_128x192x16      BITMAP16_MODE( 6 )  // Graphic 128x192x16
#define BITMAP_MODE_128x200x16      BITMAP16_MODE( 7 )  // Graphic 128x200x16
#define BITMAP_MODE_128x225x16      BITMAP16_MODE( 8 )  // Graphic 128x225x16

#define BITMAP_MODE_160x192x16      BITMAP16_MODE( 9 )   // Graphic 160x192x16
#define BITMAP_MODE_160x200x16      BITMAP16_MODE( 10 )  // Graphic 160x200x16
#define BITMAP_MODE_160x225x16      BITMAP16_MODE( 11 )  // Graphic 160x225x16

#define BITMAP_MODE_256x192x16      BITMAP16_MODE( 12 )  // Graphic 256x192x16
#define BITMAP_MODE_256x200x16      BITMAP16_MODE( 13 )  // Graphic 256x200x16
#define BITMAP_MODE_256x225x16      BITMAP16_MODE( 14 )  // Graphic 256x225x16

#define BITMAP_MODE_320x192x16      BITMAP16_MODE( 15 )  // Graphic 320x192x16
#define BITMAP_MODE_320x200x16      BITMAP16_MODE( 16 )  // Graphic 320x200x16
#define BITMAP_MODE_320x225x16      BITMAP16_MODE( 17 )  // Graphic 320x225x16

#define BITMAP_MODE_DEFAULT     BITMAP_MODE_128x192x2
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
void gime_background_color_get_vars( Environment * _environment, char * _index, char * _background_color );
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