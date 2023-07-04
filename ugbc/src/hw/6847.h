#ifndef __UGBC_6847__
#define __UGBC_6847__

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
#define TILEMAP_MODE_EXTERNAL       1       // Alphanumeric External	32 × 16	2	512

#define TILEMAP_MODE_SEMIGRAPHICS4  2       // Semigraphics 4	        64 × 32	8	512
#define TILEMAP_MODE_SEMIGRAPHICS6  3       // Semigraphics 6	        64 × 48	4	512
#define TILEMAP_MODE_SEMIGRAPHICS8  4       // Semigraphics 8	        64 × 64	2	2048
#define TILEMAP_MODE_SEMIGRAPHICS12  5       // Semigraphics 12	        64 × 96	1	3072
#define TILEMAP_MODE_SEMIGRAPHICS24  6       // Semigraphics 24	        64 × 192	1	6144

#define BITMAP_MODE_COLOR1          7       // Color Graphics 1	64 × 64	4	1024
#define BITMAP_MODE_RESOLUTION1     8       // Resolution Graphics 1	128 × 64	1 + Black	1024
#define BITMAP_MODE_COLOR2          9       // Color Graphics 2	128 × 64	4	2048
#define BITMAP_MODE_RESOLUTION2	    10       // Resolution Graphics 2 128 × 96	1 + Black	1536
#define BITMAP_MODE_COLOR3          11       // Color Graphics 3	128 × 96	4	3072
#define BITMAP_MODE_RESOLUTION3     12      // Resolution Graphics 3	128 × 192	1 + Black	3072
#define BITMAP_MODE_COLOR6          13      // Color Graphics 6	128 × 192	4	6144
#define BITMAP_MODE_RESOLUTION6     14      // Resolution Graphics 6	256 × 192	1 + Black	6144

#define BITMAP_MODE_DEFAULT     BITMAP_MODE_RESOLUTION6

#define SPRITE_COUNT                0
#define SPRITE_WIDTH                0
#define SPRITE_HEIGHT               0
#define SPRITE_X_MIN                0
#define SPRITE_Y_MIN                0
#define SPRITE_X_MAX                0
#define SPRITE_Y_MAX                0

#define SCREEN_BORDER_X             0
#define SCREEN_BORDER_Y             0

// (2) SAM_Vx are three pairs of addresses (V0-V2), and poking any value to
// EVEN addresses sets bit Vx off (0) in Video Display Generator (VDG)
// circuitry. Poking a value to ODD addresses sets bit on (1) in VDG circuit.

#define SAM_V0_CLR outline0("STA $FFC0")
#define SAM_V0_SET outline0("STA $FFC1")
#define SAM_V1_CLR outline0("STA $FFC2")
#define SAM_V1_SET outline0("STA $FFC3")
#define SAM_V2_CLR outline0("STA $FFC4")
#define SAM_V2_SET outline0("STA $FFC5")

#define SAM_F0_CLR outline0("STA $FFC6")
#define SAM_F0_SET outline0("STA $FFC7")
#define SAM_F1_CLR outline0("STA $FFC8")
#define SAM_F1_SET outline0("STA $FFC9")
#define SAM_F2_CLR outline0("STA $FFCA")
#define SAM_F2_SET outline0("STA $FFCB")
#define SAM_F3_CLR outline0("STA $FFCC")
#define SAM_F3_SET outline0("STA $FFCD")
#define SAM_F4_CLR outline0("STA $FFCE")
#define SAM_F4_SET outline0("STA $FFCF")
#define SAM_F5_CLR outline0("STA $FFD0")
#define SAM_F5_SET outline0("STA $FFD1")
#define SAM_F6_CLR outline0("STA $FFD2")
#define SAM_F6_SET outline0("STA $FFD3")

#define GM0_SET     outline0("LDA $FF22"); outline0("ORA #$10"); outline0("STA $FF22");
#define GM0_CLR     outline0("LDA $FF22"); outline0("ANDA #$EF"); outline0("STA $FF22");
#define GM1_SET     outline0("LDA $FF22"); outline0("ORA #$20"); outline0("STA $FF22");
#define GM1_CLR     outline0("LDA $FF22"); outline0("ANDA #$DF"); outline0("STA $FF22");
#define GM2_SET     outline0("LDA $FF22"); outline0("ORA #$40"); outline0("STA $FF22");
#define GM2_CLR     outline0("LDA $FF22"); outline0("ANDA #$BF"); outline0("STA $FF22");

#define CSS_SET     outline0("LDA $FF22"); outline0("ORA #$08"); outline0("STA $FF22");
#define CSS_CLR     outline0("LDA $FF22"); outline0("ANDA #$F7"); outline0("STA $FF22");

// (3) These registers work with $FF22 for setting modes, and should match up

#define VDG_GRAPH  outline0("LDA $FF22"); outline0("ORA #$80"); outline0("STA $FF22");  
#define VDG_TEXT   outline0("LDA $FF22"); outline0("ANDA #$7f"); outline0("STA $FF22");  

// (4) Default screen mode is semigraphic-4
// (5) Mode correspondence between the SAM and the VDG:
// Mode VDG Settings SAM
// A/G GM2 GM1 GM0 V2/V1/V0 Desc. RAM used
// x,y,clrs in hex(dec)
// Internal alphanumeric 0 X X 0 0 0 0 32x16 ( 5x7 pixel ch)
// External alphanumeric 0 X X 1 0 0 0 32x16 (8x12 pixel ch)
// Semigraphic-4 0 X X 0 0 0 0 32x16 ch, 64x32 pixels
// Semigraphic-6 0 X X 1 0 0 0 64x48 pixels
// Full graphic 1-C 1 0 0 0 0 0 1 64x64x4 $400(1024)
// Full graphic 1-R 1 0 0 1 0 0 1 128x64x2 $400(1024)
// Full graphic 2-C 1 0 1 0 0 1 0 128x64x4 $800(2048)
// Full graphic 2-R 1 0 1 1 0 1 1 128x96x2 $600(1536)
// Full graphic 3-C 1 1 0 0 1 0 0 128x96x4 $C00(3072)
// Full graphic 3-R 1 1 0 1 1 0 1 128x192x2 $C00(3072)
// Full graphic 6-C 1 1 1 0 1 1 0 128x192x4 $1800(6144)
// Full graphic 6-R 1 1 1 1 1 1 0 256x192x2 $1800(6144)
// Direct memory access X X X X 1 1 1
// (6) Notes:
// - The graphic modes with -C are 4 color, -R is 2 color.
// - 2 color mode - 8 pixels per byte (each bit denotes on/off)
// 4 color mode - 4 pixels per byte (each 2 bits denotes color)
// - CSS (in FF22) is the color select bit:
// Color set 0: 0 = black, 1 = green for -R modes
// 00 = green, 01 = yellow for -C modes
// 10 = blue, 11 = red for -C modes
// Color set 1: 0 = black, 1 = buff for -R modes
// Color Computer 1/2/3 Hardware Programming, Chris Lomont, v0.82
// 71
// 00 = buff, 01 = cyan, for -C modes
// 10 = magenta, 11 = orange for -C modes
// In semigraphic-4 mode, each byte is a char or 4 pixels:
// bit 7 = 0 -> text char in following 7 bits
// bit 7 = 1 -> graphic: 3 bit color code, then 4 bits for 4 quads of color
// colors 000-cyan, yellow, blue, red, buff, cyan, magenta, orange=111
// quad bits orientation UL, UR, LL, LR
// In semigraphic-6 mode, each byte is 6 pixels:
// bit 7-6 = C1-C0 color from 4 color sets above
// bit 5-0 = 6 pixels in 2x3 block, each on/off
// TODO - orientation
// Example: To set 6-C color set 0, lda #$E0, sta in $FF22, $FFC3, $FFC5
// To return to text mode, clra, sta in $FF22, $FFC2, $FFC4
// (7) In the CoCo 3, The SAM is mostly CoCo 1/2 compatible Write-Only registers

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

int c6847_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode );

void c6847_initialization( Environment * _environment );
void c6847_finalization( Environment * _environment );

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
void c6847_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height );

void c6847_bank_select( Environment * _environment, int _bank );
void c6847_enable_ecm( Environment * _environment );
void c6847_disable_ecm( Environment * _environment );
void c6847_enable_mcm( Environment * _environment );
void c6847_disable_mcm( Environment * _environment );
void c6847_screen_on( Environment * _environment );
void c6847_screen_off( Environment * _environment );
void c6847_screen_rows( Environment * _environment, char * _rows );
void c6847_screen_columns( Environment * _environment, char * _columns );

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

void c6847_tiles_get( Environment * _environment, char * _result );
void c6847_get_width( Environment * _environment, char * _result );
void c6847_tiles_get_width( Environment * _environment, char * _result );
void c6847_get_height( Environment * _environment, char * _result );
void c6847_tiles_get_height( Environment * _environment, char * _result );

void c6847_point_at_int( Environment * _environment, int _x, int _y );
void c6847_point_at_vars( Environment * _environment, char *_x, char *_y );
void c6847_point( Environment * _environment, char *_x, char *_y, char * _result );
void c6847_cls( Environment * _environment );
void c6847_scroll_text( Environment * _environment, int _direction );
void c6847_hscroll_line( Environment * _environment, int _direction );
void c6847_hscroll_screen( Environment * _environment, int _direction );
void c6847_text( Environment * _environment, char * _text, char * _text_size );
void c6847_cline( Environment * _environment, char * _characters );
void c6847_scroll( Environment * _environment, int _dx, int _dy );

Variable * c6847_get_raster_line( Environment * _environment );

Variable * c6847_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags );
void c6847_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
void c6847_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
Variable * c6847_new_image( Environment * _environment, int _width, int _height, int _mode );
void c6847_get_image( Environment * _environment, char * _image, char * _x, char * _y, int _palette );

void c6847_put_tile( Environment * _environment, char * _image, char * _x, char * _y );
void c6847_put_tiles( Environment * _environment, char * _image, char * _x, char * _y, char *_w, char *_h );
void c6847_move_tiles( Environment * _environment, char * _image, char * _x, char * _y );
void c6847_use_tileset( Environment * _environment, char * _tileset );
void c6847_tile_at( Environment * _environment, char * _x, char * _y, char * _result );
void c6847_slice_image( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination );

#endif