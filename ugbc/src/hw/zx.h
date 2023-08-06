#ifndef __UGBC_ZX__
#define __UGBC_ZX__

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
#define COLOR_WHITE					7
#define COLOR_RED					2
#define COLOR_CYAN					5
#define COLOR_VIOLET				2 /* alias */
#define COLOR_GREEN					4
#define COLOR_BLUE					1  /* alias */
#define COLOR_YELLOW				6
#define COLOR_ORANGE				10 /* alias */
#define COLOR_BROWN					2 /* alias */
#define COLOR_LIGHT_RED				10 /* alias */
#define COLOR_DARK_GREY				0 /* alias */
#define COLOR_GREY					7 /* alias */
#define COLOR_LIGHT_GREEN			12 /* alias */
#define COLOR_LIGHT_BLUE			13 /* alias */
#define COLOR_LIGHT_GREY			15 /* alias */
#define COLOR_DARK_BLUE				3 /* alias */
#define COLOR_MAGENTA				3
#define COLOR_PURPLE				3 /* alias */
#define COLOR_LAVENDER       		3 /* alias */
#define COLOR_GOLD       			6 /* alias */
#define COLOR_TURQUOISE       		5 /* alias */
#define COLOR_TAN       		    5 /* alias */
#define COLOR_YELLOW_GREEN       	6 /* alias */
#define COLOR_OLIVE_GREEN       	4 /* alias */
#define COLOR_PINK       			2 /* alias */
#define COLOR_PEACH       			2 /* alias */
#define COLOR_LIGHT_WHITE			COLOR_WHITE
#define COLOR_COUNT                 16

#define DEFAULT_PEN_COLOR           COLOR_BLACK
#define DEFAULT_PAPER_COLOR         COLOR_WHITE

#define PORT_COLOR_BORDER           254

#define TEXT_COLUMNS_COUNT          32
#define TEXT_ROWS_COUNT             24

#define KEY_NONE					0x00
#define KEY_0						'0'
#define KEY_1						'1'
#define KEY_2						'2'
#define KEY_3						'3'
#define KEY_4						'4'
#define KEY_5						'5'
#define KEY_6						'6'
#define KEY_7						'7'
#define KEY_8						'8'
#define KEY_9						'9'
#define KEY_A						'A'
#define KEY_ASTERISK				'*'
#define KEY_AT						'@'
#define KEY_B						'B'
#define KEY_C						'C'
#define KEY_CLEAR					0xf9
#define KEY_COLON					':'
#define KEY_COMMA					','
#define KEY_COMMODORE				0x00
#define KEY_CONTROL					0x00
#define KEY_CRSR_LEFT_RIGHT			0x00
#define KEY_CRSR_UP_DOWN			0x00
#define KEY_D						'D'
#define KEY_DELETE					0x90
#define KEY_E						'E'
#define KEY_EQUAL					'='
#define KEY_F						'F'
#define KEY_F1						0x00
#define KEY_F2						0x00
#define KEY_F3						0x00
#define KEY_F4						0x00
#define KEY_F5						0x00
#define KEY_F6						0x00
#define KEY_F7						0x00
#define KEY_F8						0x00
#define KEY_G						'G'
#define KEY_H						'H'
#define KEY_HOME					0x88
#define KEY_I						'I'
#define KEY_INSERT					0x89
#define KEY_J						'J'
#define KEY_K						'K'
#define KEY_L						'L'
#define KEY_LEFT_ARROW				0x91
#define KEY_LEFT_SHIFT				0x81
#define KEY_M						'M'
#define KEY_MINUS					'-'
#define KEY_N						'N'
#define KEY_O						'O'
#define KEY_P						'P'
#define KEY_PERIOD					'.'
#define KEY_PLUS					'+'
#define KEY_POUND					0x00
#define KEY_Q						'Q'
#define KEY_R						'R'
#define KEY_RETURN					0x0d
#define KEY_RIGHT_SHIFT				0x81
#define KEY_RUNSTOP					0x86
#define KEY_S						'S'
#define KEY_SEMICOLON				';'
#define KEY_SLASH					'/'
#define KEY_SPACE					' '
#define KEY_T						'T'
#define KEY_U						'U'
#define KEY_UP_ARROW				0x92
#define KEY_V						'V'
#define KEY_W						'W'
#define KEY_X						'X'
#define KEY_Y						'Y'
#define KEY_Z						'Z'
#define KEY_BACKSLASH                '\\'
#define KEY_SQUARE_OPEN              0x00
#define KEY_SQUARE_CLOSED            0x00
#define KEY_SEMICOMMA                ';'
#define KEY_QUOTE                    '"'
#define KEY_APIX                     0x00
#define KEY_DEAD                     0x00
#define KEY_SHIFT                    0x81
#define KEY_CTRL                     0x82
#define KEY_GRAPH                    0x83
#define KEY_CAPS                     0x84
#define KEY_CODE                     0x85
#define KEY_ESC                      0x27
#define KEY_TAB                      0x09
#define KEY_STOP                     0x86
#define KEY_BS                       0x08
#define KEY_SELECT                   0x87
#define KEY_RET                      0x0d
#define KEY_INS                      0x89
#define KEY_DEL                      0x90
#define KEY_LEFT                     0x91
#define KEY_UP                       0x92
#define KEY_DOWN                     0x93
#define KEY_RIGHT                    0x94
#define KEY_DIVISION                 '/'

#define INPUT_DEFAULT_SEPARATOR     ','
#define INPUT_DEFAULT_SIZE          32
#define INPUT_DEFAULT_CURSOR        0x5f

#define SCREEN_CAPABILITIES         ( ( 1<<BITMAP_NATIVE ) )

#define BANK_COUNT          0
#define BANK_SIZE           0

#define BITMAP_MODE_STANDARD        1           // Standard Bitmap Mode     192 x 256 x 2
#define TILEMAP_MODE_STANDARD       0           // Standard Character Mode  32 x 25 x 8
#define BITMAP_MODE_DEFAULT         BITMAP_MODE_STANDARD

#define JOY_UP              0
#define JOY_DOWN            0
#define JOY_LEFT            0
#define JOY_RIGHT           0
#define JOY_FIRE            0

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

#define MAX_AUDIO_CHANNELS  1

#define IMAGE_WIDTH_SIZE                1
#define IMAGE_WIDTH_OFFSET              0
#define IMAGE_HEIGHT_SIZE               1
#define IMAGE_HEIGHT_OFFSET             1

int zx_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode );

void zx_initialization( Environment * _environment );
void zx_finalization( Environment * _environment );

void zx_color_border( Environment * _environment, char * _color );
void zx_bitmap_enable( Environment * _environment, int _width, int _height, int _colors );
void zx_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height );
void zx_vscroll( Environment * _environment, int _displacement );
void zx_text( Environment * _environment, char * _text, char * _text_size );
void zx_cls( Environment * _environment, char * _pen, char * _paper );
void zx_inkey( Environment * _environment, char * _pressed, char * _key );
void zx_scancode( Environment * _environment, char * _pressed, char * _scacode );
void zx_key_pressed( Environment * _environment, char *_scancode, char * _result );
void zx_scanshift( Environment * _environment, char * _shifts );
void zx_keyshift( Environment * _environment, char * _shifts );
void zx_clear_key( Environment * _environment );
void zx_back( Environment * _environment );
void zx_scroll( Environment * _environment, int _dx, int _dy );
void zx_screen_rows( Environment * _environment, char * _rows );
void zx_screen_columns( Environment * _environment, char * _columns );

void zx_irq_at( Environment * _environment, char * _label );
void zx_follow_irq( Environment * _environment );

Variable * zx_get_raster_line( Environment * _environment );

#define         JOY_COUNT           0

Variable * zx_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags );
void zx_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
void zx_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
Variable * zx_new_image( Environment * _environment, int _width, int _height, int _mode );
void zx_get_image( Environment * _environment, char * _image, char * _x, char * _y,  int _palette );

void zx_put_tile( Environment * _environment, char * _image, char * _x, char * _y );
void zx_put_tiles( Environment * _environment, char * _image, char * _x, char * _y, char *_w, char *_h );
void zx_move_tiles( Environment * _environment, char * _image, char * _x, char * _y );
void zx_use_tileset( Environment * _environment, char * _tileset );
void zx_tile_at( Environment * _environment, char * _x, char * _y, char * _result );

void zx_sys_call( Environment * _environment, int _destination );
int zx_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette );

#endif