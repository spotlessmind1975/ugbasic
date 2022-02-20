#ifndef __UGBC_GTIA__
#define __UGBC_GTIA__

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

#define COLOR_BLACK					0x00
#define COLOR_WHITE					0x0f
#define COLOR_RED					0x48
#define COLOR_VIOLET				0x44
#define COLOR_GREEN					0xa2
#define COLOR_BLUE					0x62
#define COLOR_YELLOW				0xda
#define COLOR_ORANGE				0x2a
#define COLOR_BROWN					0x14
#define COLOR_LIGHT_RED				0x4f
#define COLOR_DARK_GREY				0x04
#define COLOR_GREY					0x08
#define COLOR_LIGHT_GREEN			0xa8
#define COLOR_LIGHT_BLUE			0x68
#define COLOR_LIGHT_GREY			0x0b
#define COLOR_MAGENTA				0x1e
#define COLOR_PURPLE				COLOR_VIOLET
#define COLOR_LAVENDER       		0x55
#define COLOR_GOLD       			0xd6
#define COLOR_TURQUOISE       		0x78
#define COLOR_TAN       		    0x65
#define COLOR_YELLOW_GREEN       	0xaa
#define COLOR_OLIVE_GREEN       	0xa6
#define COLOR_PINK       			0x3a
#define COLOR_PEACH       			0x38
#define COLOR_CYAN					0x6a
#define COLOR_DARK_BLUE				0x60

#define DEFAULT_PEN_COLOR           COLOR_WHITE
#define DEFAULT_PAPER_COLOR         COLOR_BLACK

#define TEXT_COLUMNS_COUNT          40
#define TEXT_ROWS_COUNT             24

// Graphics 3 (ANTIC 8)
// This four-color graphics mode turns a split screen into 20 rows of 40 graphics cells or pixels. 
// Each pixel is 8 x 8 or the size of a normal character. The data in each pixel is encoded as two bit pairs, 
// four per byte. The four possible bit pair combinations 00, 01, 10, and 11 point to one of the four color registers. 
// The bits 00 is assigned to the background color register and the rest refer to the three foreground color registers. 
// When the CTIA/GTIA chip interprets the data for the four adjacent pixels stored within the byte, it refers to the color 
// register encoded in the bit pattern to plot the color.
#define BITMAP_MODE_ANTIC8          8       // 40x20, 4 colors

// Graphics 4 (ANTIC 9)
// This is a two-color graphics mode with four times the resolution of GRAPHICS 3. The pixels are 4 x 4, and 48 rows of 80 
// pixels fit on a full screen. A single bit is used to store each pixel's color register. A zero refers to the background 
// color register and a one to the foreground color register. The mode is used primarily to conserve screen memory. 
// Only one bit is used for the color, so eight adjacent pixels are encoded within one byte, and only half as much screen 
// memory is needed for a display of similiar-sized pixels.
#define BITMAP_MODE_ANTIC9          9       // 80x48, 2 colors

// Graphics 5 (ANTIC A or 10)
// This is the four color equivalent of GRAPHICS 4 sized pixels. The pixels are 4 x 4, but two bits are required to address 
// the four color registers. With only four adjacent pixels encoded within a byte, the screen uses twice as much memory, 
// about 1K.
#define BITMAP_MODE_ANTIC10         10       // 80x48, 4 colors

// Graphics 6 (ANTIC B or 11)
// This two color graphics mode has reasonably fine resolution. The 2 x 2 sized pixels allow 96 rows of 160 pixels to fit 
// on a full screen. Although only a single bit is used to encode the color, screen memory still requires approximately 2K.
#define BITMAP_MODE_ANTIC11         11       // 160x96, 2 colors

// Graphics 7 (ANTIC D or 13)
// This is the four color equivalent to GRAPHICS mode 6. It is the finest resolution four color mode and naturally the
// most popular. The color is encoded in two bit-pairs exactly the same way as in GRAPHICS 3. The memory requirements 
// of course is much greater as there are 96 rows of 160 - 2 x 2 sized pixels. It requires 3840 bytes of screen memory
// with another 104 bytes for the display list.
#define BITMAP_MODE_ANTIC13         13       // 160x96, 4 colors

// Graphics 8 (ANTIC F or 15)
// This mode is definitely the finest resolution available on the Atari. Individual dot-sized pixels can be addressed in 
// this one-color, two-luminance mode. There are 192 rows of 320 dots in the full screen mode. Graphics 8 is memory 
// intensive; it takes 8K bytes (eight pixels/byte) to address an entire screen. The color scheme is quite similar to that 
// in GRAPHICS mode 0. Color register #2 sets the background color. Color register #1 sets the luminance. Changing the color
// in this register has no effect, but, this doesn't mean that you are limited to just one color.
// Fortunately, the pixels are each one half of a color clock. It takes two pixels to span one color clock made up of
// alternating columns of complementary colors. If the background is set to black, these columns consist of blue and 
// green stripes. If only the odd-columned pixels are plotted, you get blue pixels. If only the odd-columned pixels 
// are plotted, you get green pixels. And if pairs of adjacent pixels are plotted, you get white. So by cleverly 
// staggering the pixel patterns, you can achieve three colors. This method is called artifacting. This all depends
// on background color and luminance.
#define BITMAP_MODE_ANTIC15         15       // 320x192, 4 colors

// The following five graphics modes have no equivalent in BASIC on older machine but if indicated do correspond to
// an equivalent graphics mode on the newer XL models.

// Antic C (Graphics 14-XL computers only)
// This two-color, bit-mapped mode the eight bits correspond directly to the pixels on the screen. If a pixel is lit 
// it receives its color information from color register #0, otherwise the color is set to the background color 
// register #4. Each pixel is one scan line high and one color clock wide. This mode's advantages are that it 
// only uses 4K of screen memory and doesn't have artifacting problems.
#define BITMAP_MODE_ANTIC12         12       // 320x192, 2 colors

// Antic E (Graphics 15-XL computers only)
// This four-color, bit-mapped mode is sometimes known as BASIC 7 1/2. Its resolution is 160 x 192 or twice that of 
// GRAPHIC 7. Each byte is divided into four pairs of bits. Like the character data in ANTIC 4, the bit pairs point to a
// particular color register. The screen data, however, is not character data but individual bytes. The user has a lot
// more control, but this mode uses a lot more memory, approximately
#define BITMAP_MODE_ANTIC14         14       // 160x192, 4 colors

// Graphics Mode 0 (ANTIC 2)
// This is the normal-sized character or text mode that the computer defaults to on start up. 
// Being a character mode, screen memory consists of bytes that represent individual characters in either the 
// ROM or a custom character set. ANTIC displays forty of these 8 x 8 sized characters on each of 
// twenty-four lines. Graphics 0 is a 1 1/2 color mode. Color register #2 is used as the background color 
// register. Color register #1 sets the luminance of the characters against the background. Setting the 
// color has no effect. Bits within a character are turned on in pairs to produce the luminace color. 
// Otherwise single bits tend to produce colored artifacts on the high resolution screen. These colors
// depend on whether the computer has a CTIA or GTIA chip, and the color of the background.
#define TILEMAP_MODE_ANTIC2         2       // 40x24, 1 color

// Graphics 1 (ANTIC 6)
// This is one the expanded text modes. Each characters is 8 x 8 but the pixels are one color clock in 
// width instead of the 1/2 color clock mode of Graphics 0 making the characters twice as wide. Only twenty 
// characters fit on any line. A graphics 1 screen has twenty rows while the full screen mode has twenty-four 
// rows of characters. The two high bits of each ATASCII character, that normally identify lowercase or 
// inverse video text in Graphics 1, set the color register for the 64 character set. Decimal character
// numbers 0-63 use color register zero, while those same 64 characters if given character numbers 64-127 
// use color register #1. If you are typing from the Atari keyboard, the uppercase letters A-Z ATASCII 65-90
// (Internal # 33-58) are assigned to color register zero, while the lowercase numbers 97-122 
// (Internal # 97-122) are signed to register #1.
#define TILEMAP_MODE_ANTIC6         6       // 20x24, 4 color

// Graphics 2 (ANTIC 7)
// This text mode is basically the same as the previous mode except that each row of pixels is two scan lines high.
// Thus 12 rows of 20 characters are displayed on a full screen. Only ten rows fit on a split screen.
#define TILEMAP_MODE_ANTIC7         7       // 20x12, 4 color

// Antic 3
// This rarely used text mode is sometimes called the lowercase descenders mode. Each of the forty characters per line
// are ten scan lines high, but since each of the characters are only eight scan lines high, the lower two scan lines are
// normally left empty. However, if you use the last quarter of the character set, the top two lines remain blank, 
// allowing you to create lowercase characters with descenders.
#define TILEMAP_MODE_ANTIC3         3       // 40x24, 4 color

// Antic 4 (Graphics 12-XL computers only)
// This very powerful character graphics mode supports four colors while using relatively little screen memory (1 K). 
// In addition its 4 x 8 sized characters have the same horizontal resolution as GRAPHICS 7, yet twice the vertical resolution.
// A large number of games with colorful and detailed playfields use this mode. These characters differ considerably from 
// ANTIC 6 (BASIC 2) characters, in that each character contains pixels of four different colors, not just a choice of one color
// determined by the character number. Each byte in the character is broken into four bit pairs, each of which selects the color
// register for the pixel. That is why the horizontal resolution is only four bits. A special character set generator is used
// to form these characters.
#define TILEMAP_MODE_ANTIC4         4       // 20x24, 4 color

// Antic 5 (Graphics 13-XL computers only)
// This mode is essentially the same as ANTIC 4 except that each character is sixteen scan lines high. 
// The character set data is still eight bytes high so ANTIC double plots each scan line.
#define TILEMAP_MODE_ANTIC5         5       // 20x24, 4 color

#define BITMAP_MODE_DEFAULT     BITMAP_MODE_ANTIC11

#define COLOR_COUNT         255

#define SPRITE_COUNT                8
#define SPRITE_WIDTH                8
#define SPRITE_HEIGHT               -1

int gtia_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode );

void gtia_initialization( Environment * _environment );
void gtia_finalization( Environment * _environment );

void gtia_back( Environment * _environment );
void gtia_clear( Environment * _environment, char * _pattern );
void gtia_background_color( Environment * _environment, int _index, int _background_color );
void gtia_background_color_vars( Environment * _environment, char * _index, char * _background_color );
void gtia_background_color_semivars( Environment * _environment, int _index, char * _background_color );
void gtia_background_color_get_vars( Environment * _environment, char * _index, char * _background_color );
void gtia_border_color( Environment * _environment, char * _border_color );
void gtia_collision( Environment * _environment, char * _sprite_mask, char * _result );
void gtia_hit( Environment * _environment, char * _sprite_mask, char * _result );
void gtia_sprite_common_color( Environment * _environment, char * _index, char * _common_color );
void gtia_bitmap_enable( Environment * _environment, int _width, int _height, int _colors );
void gtia_bitmap_disable( Environment * _environment );
void gtia_bitmap_at( Environment * _environment, char * _address );
void gtia_colormap_at( Environment * _environment, char * _address );
void gtia_textmap_at( Environment * _environment, char * _address );
void gtia_tiles_at( Environment * _environment, char * _address );
void gtia_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height );

void gtia_bank_select( Environment * _environment, int _bank );
void gtia_enable_ecm( Environment * _environment );
void gtia_disable_ecm( Environment * _environment );
void gtia_enable_mcm( Environment * _environment );
void gtia_disable_mcm( Environment * _environment );
void gtia_screen_on( Environment * _environment );
void gtia_screen_off( Environment * _environment );
void gtia_screen_rows( Environment * _environment, char * _rows );
void gtia_screen_columns( Environment * _environment, char * _columns );

void gtia_sprite_data_from( Environment * _environment, char * _sprite, char * _address );
void gtia_sprite_enable( Environment * _environment, char *_sprite );
void gtia_sprite_disable( Environment * _environment, char * _sprite );
void gtia_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y );
void gtia_sprite_expand_vertical( Environment * _environment, char * _sprite );
void gtia_sprite_expand_horizontal( Environment * _environment, char * _sprite );
void gtia_sprite_compress_vertical( Environment * _environment, char * _sprite );
void gtia_sprite_compress_horizontal( Environment * _environment, char * _sprite );
void gtia_sprite_multicolor( Environment * _environment, char * _sprite );
void gtia_sprite_monocolor( Environment * _environment, char * _sprite );
void gtia_sprite_color( Environment * _environment, char * _sprite, char * _color );
void gtia_vertical_scroll( Environment * _environment, char * _displacement );
void gtia_horizontal_scroll( Environment * _environment, char * _displacement );
void gtia_busy_wait( Environment * _environment, char * _timing );

void gtia_tiles_get( Environment * _environment, char * _result );
void gtia_get_width( Environment * _environment, char * _result );
void gtia_tiles_get_width( Environment * _environment, char * _result );
void gtia_get_height( Environment * _environment, char * _result );
void gtia_tiles_get_height( Environment * _environment, char * _result );

void gtia_point_at_int( Environment * _environment, int _x, int _y );
void gtia_point_at_vars( Environment * _environment, char *_x, char *_y );
void gtia_point( Environment * _environment, char *_x, char *_y, char * _result );
void gtia_cls( Environment * _environment );
void gtia_scroll_text( Environment * _environment, int _direction );
void gtia_hscroll_line( Environment * _environment, int _direction );
void gtia_hscroll_screen( Environment * _environment, int _direction );
void gtia_text( Environment * _environment, char * _text, char * _text_size );
void gtia_cline( Environment * _environment, char * _characters );
void gtia_scroll( Environment * _environment, int _dx, int _dy );

Variable * gtia_image_converter( Environment * _environment, char * _data, int _width, int _height, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags );
void gtia_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, int _frame_size, int _flags );
void gtia_wait_vbl( Environment * _environment );
Variable * gtia_new_image( Environment * _environment, int _width, int _height, int _mode );
void gtia_get_image( Environment * _environment, char * _image, char * _x, char * _y );

Variable * gtia_get_raster_line( Environment * _environment );

void gtia_put_tile( Environment * _environment, char * _image, char * _x, char * _y );
void gtia_put_tiles( Environment * _environment, char * _image, char * _x, char * _y, char *_w, char *_h );
void gtia_move_tiles( Environment * _environment, char * _image, char * _x, char * _y );
void gtia_use_tileset( Environment * _environment, char * _tileset );
void gtia_tile_at( Environment * _environment, char * _x, char * _y, char * _result );

#endif