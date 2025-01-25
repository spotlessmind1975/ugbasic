#ifndef __UGBC_ZX__
#define __UGBC_ZX__

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
#define COLOR_WHITE					7
#define COLOR_DARK_RED				2 // RED
#define COLOR_RED					2
#define COLOR_CYAN					5
#define COLOR_VIOLET				2 /* alias */
#define COLOR_DARK_GREEN			4 // GREEN
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
#define COLOR_DARK_WHITE			7 // GREY
#define COLOR_LIGHT_WHITE			COLOR_WHITE
#define COLOR_COUNT                 16

#define DEFAULT_PEN_COLOR           COLOR_BLACK
#define DEFAULT_PAPER_COLOR         COLOR_WHITE

#define PORT_COLOR_BORDER           254

#define TEXT_COLUMNS_COUNT          32
#define TEXT_ROWS_COUNT             24

#define KEY_NONE					0xff

#define KEY_BS                      0
#define KEY_Z                       1
#define KEY_X                       2
#define KEY_C                       3
#define KEY_V                       4

#define KEY_A                       5
#define KEY_S                       6
#define KEY_D                       7
#define KEY_F                       8
#define KEY_G                       9

#define KEY_Q                      10
#define KEY_W                      11
#define KEY_E                      12
#define KEY_R                      13
#define KEY_T                      14

#define KEY_1                      15
#define KEY_2                      16
#define KEY_3                      17
#define KEY_4                      18
#define KEY_5                      19

#define KEY_0                      20
#define KEY_9                      21
#define KEY_8                      22
#define KEY_7                      23
#define KEY_6                      24

#define KEY_P                      25
#define KEY_O                      26
#define KEY_I                      27
#define KEY_U                      28
#define KEY_Y                      29

#define KEY_RETURN                 30
#define KEY_L                      31
#define KEY_K                      32
#define KEY_J                      33
#define KEY_H                      34

#define KEY_SPACE                  35

#define KEY_M                      36
#define KEY_N                      37
#define KEY_B                      38

#define KEY_ASTERISK			    0
#define KEY_AT						0
#define KEY_CLEAR					0
#define KEY_COLON					0
#define KEY_COMMA					0
#define KEY_COMMODORE				0
#define KEY_CONTROL					0
#define KEY_CRSR_LEFT_RIGHT			0
#define KEY_CRSR_UP_DOWN			0
#define KEY_DELETE					0
#define KEY_EQUAL					0
#define KEY_F1						0
#define KEY_F2						0
#define KEY_F3						0
#define KEY_F4						0
#define KEY_F5						0
#define KEY_F6						0
#define KEY_F7						0
#define KEY_F8						0
#define KEY_HOME					0
#define KEY_INSERT					0
#define KEY_LEFT_ARROW				0
#define KEY_LEFT_SHIFT				0
#define KEY_MINUS					0
#define KEY_PERIOD					0
#define KEY_PLUS					0
#define KEY_POUND					0
#define KEY_RIGHT_SHIFT				0
#define KEY_RUNSTOP					0
#define KEY_SEMICOLON				0
#define KEY_SLASH					0
#define KEY_UP_ARROW				0
#define KEY_BACKSLASH               0
#define KEY_SQUARE_OPEN             0
#define KEY_SQUARE_CLOSED           0
#define KEY_SEMICOMMA               0
#define KEY_QUOTE                   0
#define KEY_APIX                    0
#define KEY_DEAD                    0
#define KEY_SHIFT                   0
#define KEY_CTRL                    0
#define KEY_GRAPH                   0
#define KEY_CAPS                    0
#define KEY_CODE                    0
#define KEY_ESC                     0
#define KEY_TAB                     0
#define KEY_STOP                    0
#define KEY_BS                      0
#define KEY_SELECT                  0
#define KEY_RET                     0
#define KEY_INS                     0
#define KEY_DEL                     0
#define KEY_LEFT                    KEY_A
#define KEY_UP                      KEY_W
#define KEY_DOWN                    KEY_S
#define KEY_RIGHT                   KEY_D
#define KEY_DIVISION                0

#define KEYBOARD_CONFIG_DEFAULT_SYNC       0

#define INPUT_DEFAULT_SEPARATOR     ','
#define INPUT_DEFAULT_SIZE          32
#define INPUT_DEFAULT_CURSOR        0x5f

#define SCREEN_CAPABILITIES         ( ( 1<<BITMAP_NATIVE ) )

#define DEFAULT_PAINT_BUCKET_SIZE   512

#define BANK_COUNT          1
#define BANK_SIZE           4096

#define BITMAP_MODE_STANDARD        1           // Standard Bitmap Mode     192 x 256 x 2
#define TILEMAP_MODE_STANDARD       0           // Standard Character Mode  32 x 25 x 8
#define BITMAP_MODE_DEFAULT         BITMAP_MODE_STANDARD

#define JOY_UP              0
#define JOY_DOWN            1
#define JOY_LEFT            2
#define JOY_RIGHT           3
#define JOY_FIRE            4

#define JOYSTICK_CONFIG_DEFAULT_SYNC      1

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

#define MAX_AUDIO_CHANNELS  1

#define IMAGE_WIDTH_SIZE                2
#define IMAGE_WIDTH_OFFSET              0
#define IMAGE_HEIGHT_SIZE               1
#define IMAGE_HEIGHT_OFFSET             2

#define DOUBLE_BUFFER_PAGE_0        0
#define DOUBLE_BUFFER_PAGE_1        1

int zx_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode );

void zx_initialization( Environment * _environment );
void zx_finalization( Environment * _environment );

void zx_color_border( Environment * _environment, char * _color );
void zx_bitmap_enable( Environment * _environment, int _width, int _height, int _colors );
void zx_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height );
void zx_vscroll( Environment * _environment, int _displacement, int _overlap );
void zx_text( Environment * _environment, char * _text, char * _text_size, int _raw );
void zx_cls( Environment * _environment, char * _pen, char * _paper );

void zx_wait_key( Environment * _environment, int _release );
void zx_wait_fire( Environment * _environment, int _port, int _release );
void zx_wait_fire_semivar( Environment * _environment, char * _port, int _release );
void zx_wait_key_or_fire( Environment * _environment, int _port, int _release );
void zx_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release );
void zx_key_state( Environment * _environment, char *_scancode, char * _result );
void zx_scancode( Environment * _environment, char * _scacode );
void zx_asciicode( Environment * _environment, char * _asciicode );
void zx_inkey( Environment * _environment, char * _key );
void zx_key_pressed( Environment * _environment, char *_scancode, char * _result );
void zx_put_key(  Environment * _environment, char *_string, char * _size );

void zx_scanshift( Environment * _environment, char * _shifts );
void zx_keyshift( Environment * _environment, char * _shifts );
void zx_clear_key( Environment * _environment );
void zx_back( Environment * _environment );
void zx_scroll( Environment * _environment, int _dx, int _dy );
void zx_screen_rows( Environment * _environment, char * _rows );
void zx_screen_columns( Environment * _environment, char * _columns );

Variable * zx_get_raster_line( Environment * _environment );

#define         JOY_COUNT           0

int zx_image_size( Environment * _environment, int _width, int _height, int _mode );
Variable * zx_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags );
void zx_put_image( Environment * _environment, Resource * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _flags );
void zx_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
Variable * zx_new_image( Environment * _environment, int _width, int _height, int _mode );
Variable * zx_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode );
Variable * zx_new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode );
void zx_get_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count,  int _palette );

void zx_sprite_data_from( Environment * _environment, char * _sprite, char * _address );
void zx_sprite_data_set( Environment * _environment, char * _sprite, char * _address );
void zx_sprite_enable( Environment * _environment, char *_sprite );
void zx_sprite_disable( Environment * _environment, char * _sprite );
void zx_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y );
void zx_sprite_expand_vertical( Environment * _environment, char * _sprite );
void zx_sprite_expand_horizontal( Environment * _environment, char * _sprite );
void zx_sprite_compress_vertical( Environment * _environment, char * _sprite );
void zx_sprite_compress_horizontal( Environment * _environment, char * _sprite );
void zx_sprite_multicolor( Environment * _environment, char * _sprite );
void zx_sprite_monocolor( Environment * _environment, char * _sprite );
void zx_sprite_color( Environment * _environment, char * _sprite, char * _color );
void zx_sprite_priority( Environment * _environment, char * _sprite, char * _priority );
void zx_vertical_scroll( Environment * _environment, char * _displacement );
void zx_horizontal_scroll( Environment * _environment, char * _displacement );
void zx_busy_wait( Environment * _environment, char * _timing );

void zx_put_tile( Environment * _environment, char * _image, char * _x, char * _y );
void zx_put_tiles( Environment * _environment, char * _image, char * _x, char * _y, char *_w, char *_h );
void zx_move_tiles( Environment * _environment, char * _image, char * _x, char * _y );
void zx_use_tileset( Environment * _environment, char * _tileset );
void zx_tile_at( Environment * _environment, char * _x, char * _y, char * _result );

void zx_slice_image( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination );
void zx_sys_call( Environment * _environment, int _destination );
int zx_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette );
void zx_hscroll_line( Environment * _environment, int _direction, int _overlap );
void zx_hscroll_screen( Environment * _environment, int _direction, int _overlap );

void zx_timer_set_status_on( Environment * _environment, char * _timer );
void zx_timer_set_status_off( Environment * _environment, char * _timer );
void zx_timer_set_counter( Environment * _environment, char * _timer, char * _counter );
void zx_timer_set_init( Environment * _environment, char * _timer, char * _init );
void zx_timer_set_address( Environment * _environment, char * _timer, char * _address );
void zx_calculate_sequence_frame_offset( Environment * _environment, char * _offset, char * _sequence, char * _frame, int _frame_size, int _frame_count );

void zx_dojo_ready( Environment * _environment, char * _value );
void zx_dojo_read_byte( Environment * _environment, char * _value );
void zx_dojo_write_byte( Environment * _environment, char * _value );

void zx_dojo_ping( Environment * _environment, char * _result );
void zx_dojo_login( Environment * _environment, char * _name, char * _name_size, char * _password, char * _size, char * _unique_id );
void zx_dojo_success( Environment * _environment, char * _id, char * _result );
void zx_dojo_create_port( Environment * _environment, char * _session_id, char * _application, char * _size, char * _port_id );
void zx_dojo_find_port( Environment * _environment, char * _session_id, char * _username, char * _size, char * _application, char * _application_size, char * _port_id );
void zx_dojo_put_message( Environment * _environment, char * _port_id, char * _message, char * _size, char * _result );
void zx_dojo_peek_message( Environment * _environment, char * _port_id, char * _result );
void zx_dojo_get_message( Environment * _environment, char * _port_id, char * _result, char * _message );
void zx_dojo_destroy_port( Environment * _environment, char * _port_id, char * _result );

void zx_joystick_semivars( Environment * _environment, char * _joystick, char * _result );
void zx_joystick( Environment * _environment, int _joystick, char * _result );

#endif