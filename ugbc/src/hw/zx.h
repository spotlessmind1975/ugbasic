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
#define COLOR_BLUE					3  /* alias */
#define COLOR_YELLOW				6
#define COLOR_ORANGE				2 /* alias */
#define COLOR_BROWN					2 /* alias */
#define COLOR_LIGHT_RED				2 /* alias */
#define COLOR_DARK_GREY				0 /* alias */
#define COLOR_GREY					7 /* alias */
#define COLOR_LIGHT_GREEN			4 /* alias */
#define COLOR_LIGHT_BLUE			5 /* alias */
#define COLOR_LIGHT_GREY			7 /* alias */
#define COLOR_DARK_BLUE				3 /* alias */
#define COLOR_MAGENTA				3
#define COLOR_PURPLE				2 /* alias */
#define COLOR_LAVENDER       		2 /* alias */
#define COLOR_GOLD       			6 /* alias */
#define COLOR_TURQUOISE       		5 /* alias */
#define COLOR_TAN       		    5 /* alias */
#define COLOR_YELLOW_GREEN       	6 /* alias */
#define COLOR_OLIVE_GREEN       	4 /* alias */
#define COLOR_PINK       			2 /* alias */
#define COLOR_PEACH       			2 /* alias */
#define COLOR_COUNT                 16

#define DEFAULT_PEN_COLOR           COLOR_BLACK
#define DEFAULT_PAPER_COLOR         COLOR_WHITE

#define PORT_COLOR_BORDER           254

#define TEXT_COLUMNS_COUNT          32
#define TEXT_ROWS_COUNT             24

#define KEY_NONE					64
#define KEY_0						35
#define KEY_1						56
#define KEY_2						59
#define KEY_3						8
#define KEY_4						11
#define KEY_5						16
#define KEY_6						19
#define KEY_7						24
#define KEY_8						27
#define KEY_9						32
#define KEY_A						10
#define KEY_ASTERISK				49
#define KEY_AT						46
#define KEY_B						28
#define KEY_C						20
#define KEY_CLEAR					51
#define KEY_COLON					45
#define KEY_COMMA					47
#define KEY_COMMODORE				61
#define KEY_CONTROL					58
#define KEY_CRSR_LEFT_RIGHT			2
#define KEY_CRSR_UP_DOWN			7
#define KEY_D						18
#define KEY_DELETE					0
#define KEY_E						14
#define KEY_EQUAL					53
#define KEY_F						21
#define KEY_F1						4
#define KEY_F2						4
#define KEY_F3						5
#define KEY_F4						5
#define KEY_F5						6
#define KEY_F6						6
#define KEY_F7						3
#define KEY_F8						3
#define KEY_G						26
#define KEY_H						29
#define KEY_HOME					51
#define KEY_I						33
#define KEY_INSERT					0
#define KEY_J						34
#define KEY_K						37
#define KEY_L						42
#define KEY_LEFT_ARROW				57
#define KEY_LEFT_SHIFT				15
#define KEY_M						36
#define KEY_MINUS					43
#define KEY_N						39
#define KEY_O						38
#define KEY_P						41
#define KEY_PERIOD					44
#define KEY_PLUS					40
#define KEY_POUND					48
#define KEY_Q						62
#define KEY_R						17
#define KEY_RETURN					1
#define KEY_RIGHT_SHIFT				52
#define KEY_RUNSTOP					63
#define KEY_S						13
#define KEY_SEMICOLON				50
#define KEY_SLASH					55
#define KEY_SPACE					60
#define KEY_T						22
#define KEY_U						30
#define KEY_UP_ARROW				54
#define KEY_V						31
#define KEY_W						9
#define KEY_X						23
#define KEY_Y						25
#define KEY_Z						12
#define KEY_BACKSLASH                128
#define KEY_SQUARE_OPEN              129
#define KEY_SQUARE_CLOSED            130
#define KEY_SEMICOMMA                131
#define KEY_QUOTE                    132
#define KEY_APIX                     133
#define KEY_DEAD                     134
#define KEY_SHIFT                    135
#define KEY_CTRL                     136
#define KEY_GRAPH                    137
#define KEY_CAPS                     138
#define KEY_CODE                     139
#define KEY_ESC                      140
#define KEY_TAB                      141
#define KEY_STOP                     142
#define KEY_BS                       143
#define KEY_SELECT                   144
#define KEY_RET                      145
#define KEY_INS                      146
#define KEY_DEL                      147
#define KEY_LEFT                     148
#define KEY_UP                       149
#define KEY_DOWN                     150
#define KEY_RIGHT                    151
#define KEY_DIVISION                 154

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

Variable * zx_get_raster_line( Environment * _environment );

#define         JOY_COUNT           0

Variable * zx_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags );
void zx_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
Variable * zx_new_image( Environment * _environment, int _width, int _height, int _mode );
void zx_get_image( Environment * _environment, char * _image, char * _x, char * _y,  int _palette );

void zx_put_tile( Environment * _environment, char * _image, char * _x, char * _y );
void zx_put_tiles( Environment * _environment, char * _image, char * _x, char * _y, char *_w, char *_h );
void zx_move_tiles( Environment * _environment, char * _image, char * _x, char * _y );
void zx_use_tileset( Environment * _environment, char * _tileset );
void zx_tile_at( Environment * _environment, char * _x, char * _y, char * _result );

#endif