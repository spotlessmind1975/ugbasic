#ifndef __UGBC_PC1403__
#define __UGBC_PC1403__

/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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

#define KEY_NONE					255

#define KEY_0                         0
#define KEY_1                         1
#define KEY_2                         2
#define KEY_3                         3
#define KEY_4                         4
#define KEY_5                         5
#define KEY_6                         6
#define KEY_7                         7
#define KEY_8                         8
#define KEY_9                         9
#define KEY_MINUS                    10
#define KEY_EQUAL                    11
#define KEY_BACKSLASH                12
#define KEY_SQUARE_OPEN              13
#define KEY_SQUARE_CLOSE             14
#define KEY_SEMICOLON                15
#define KEY_QUOTE                    16
// ~
// <
// >
// ?
// $00
#define KEY_A                        22
#define KEY_B                        23
#define KEY_C                        24
#define KEY_D                        25
#define KEY_E                        26
#define KEY_F                        27
#define KEY_G                        28
#define KEY_H                        29
#define KEY_I                        30
#define KEY_J                        31
#define KEY_K                        32
#define KEY_L                        33
#define KEY_M                        34
#define KEY_N                        35
#define KEY_O                        36
#define KEY_P                        37
#define KEY_Q                        38
#define KEY_R                        39
#define KEY_S                        40
#define KEY_T                        41
#define KEY_U                        42
#define KEY_V                        43
#define KEY_W                        44
#define KEY_X                        45
#define KEY_Y                        46
#define KEY_Z                        47
// 48: 81
// 49: 82
// 50: 83
// 51: 84
// 52: 85
// 53: f1
// 54: f2
// 55: f3
// 56: f4
// 57: f5
#define KEY_ESC                      58
#define KEY_TAB                      59
// 60: 86
#define KEY_BS                       61
// 62: 87
#define KEY_RETURN                   63
#define KEY_SPACE                    64
// 65: 88
// 66: 89
// 67: 90
// 68: 91
// 69: 92
// 70: 93
// 71: 94
#define KEY_ASTERISK                 72
#define KEY_PLUS                     73
    // DB "/", "0", "1", "2", "3", "4"
    // DB "5", "6", ",", "8", "9", "-", "7", "."
#define KEY_PERIOD                   87 
    // DB $ff


#define KEY_AT						  0
#define KEY_COMMODORE				  0
#define KEY_CONTROL					  0
#define KEY_CRSR_LEFT_RIGHT			  0
#define KEY_CRSR_UP_DOWN			  0
#define KEY_DELETE					  0
#define KEY_F1						  0
#define KEY_F2						  0
#define KEY_F3						  0
#define KEY_F4						  0
#define KEY_F5						  0
#define KEY_F6						  0
#define KEY_F7						  0
#define KEY_F8						  0
#define KEY_HOME					  0
#define KEY_INSERT					  0
#define KEY_LEFT_ARROW				  0
#define KEY_LEFT_SHIFT				  0
#define KEY_POUND					  0
#define KEY_RIGHT_SHIFT				  0
#define KEY_RUNSTOP					  0
#define KEY_UP_ARROW				  0
#define KEY_SEMICOMMA                 0
#define KEY_APIX                      0
#define KEY_DEAD                      0
#define KEY_SHIFT                     0
#define KEY_CTRL                      0
#define KEY_GRAPH                     0
#define KEY_CAPS                      0
#define KEY_CODE                      0
#define KEY_STOP                      0
#define KEY_SELECT                    0
#define KEY_INS                       0
#define KEY_DEL                       0
#define KEY_LEFT                      0
#define KEY_UP                        0
#define KEY_DOWN                      0
#define KEY_RIGHT                     0
#define KEY_DIVISION                  0
#define KEY_CLEAR                     0
#define KEY_COLON                     0
#define KEY_COMMA                     0
#define KEY_SLASH                     0

#define KEYBOARD_CONFIG_DEFAULT_SYNC       0

#define INPUT_DEFAULT_SEPARATOR     ','
#define INPUT_DEFAULT_SIZE          32
#define INPUT_DEFAULT_CURSOR        95
#define INPUT_DEFAULT_RATE          16
#define INPUT_DEFAULT_DELAY         64

#define SCREEN_WIDTH                120
#define SCREEN_HEIGHT                 8

#define SCREEN_CAPABILITIES         ( ( 1<<TILEMAP_NATIVE ) | ( 1<<BITMAP_NATIVE ) )

#define DEFAULT_PAINT_BUCKET_SIZE   512

#define BANK_COUNT          1
#define BANK_SIZE           4096

#define JOY_COUNT           2

#define JOY_UP              0
#define JOY_DOWN            1
#define JOY_LEFT            2
#define JOY_RIGHT           3
#define JOY_FIRE            4

#define JOYSTICK_CONFIG_DEFAULT_SYNC      1

#define MAX_AUDIO_CHANNELS  3

#define BITMAP_MODE_STANDARD        1           // Standard Bitmap Mode
#define TILEMAP_MODE_STANDARD       0           // (emulated) Standard Character Mode
#define BITMAP_MODE_DEFAULT         BITMAP_MODE_STANDARD

#define DOUBLE_BUFFER_PAGE_0    0
#define DOUBLE_BUFFER_PAGE_1    0
#define SPRITE_COUNT            0
#define SCREEN_SPRITE_RATIO_X   0
#define SCREEN_SPRITE_RATIO_Y   0
#define SPRITE_HEIGHT           0
#define SCREEN_BORDER_X         0
#define SCREEN_BORDER_Y         0
#define SPRITE_WIDTH            0
#define SPRITE_X_MIN            0
#define SPRITE_Y_MIN            0
#define SPRITE_X_MAX            0
#define SPRITE_Y_MAX            0

#define COLOR_TRANSPARENT			0x00
#define COLOR_BLACK					0x01
#define COLOR_DARK_WHITE			0x0e // GREY
#define COLOR_WHITE					0x0f
#define COLOR_LIGHT_WHITE			COLOR_WHITE
#define COLOR_DARK_RED				0x06 // BROWN
#define COLOR_RED					0x08
#define COLOR_LIGHT_RED				0x09
#define COLOR_CYAN					0x07
#define COLOR_VIOLET				0x0d
#define COLOR_DARK_GREEN			0x02 // GREEN
#define COLOR_GREEN					0x02
#define COLOR_LIGHT_GREEN			0x03
#define COLOR_DARK_BLUE				0x04
#define COLOR_BLUE					0x07
#define COLOR_LIGHT_BLUE			0x05
#define COLOR_YELLOW				0x0b
#define COLOR_ORANGE				0x09
#define COLOR_BROWN					0x06
#define COLOR_DARK_GREY				0x0e
#define COLOR_GREY					0x0e
#define COLOR_LIGHT_GREY			0x0e
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

#define DEFAULT_PEN_COLOR           COLOR_BLACK
#define DEFAULT_PAPER_COLOR         COLOR_WHITE

#define IMAGE_WIDTH_SIZE        1
#define IMAGE_WIDTH_OFFSET      0
#define IMAGE_HEIGHT_SIZE       1
#define IMAGE_HEIGHT_OFFSET     0

void pc1403_initialization( Environment * _environment );

void pc1403_wait_key( Environment * _environment, int _release );
void pc1403_wait_fire( Environment * _environment, int _port, int _release );
void pc1403_wait_fire_semivar( Environment * _environment, char * _port, int _release );
void pc1403_wait_key_or_fire( Environment * _environment, int _port, int _release );
void pc1403_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release );
void pc1403_key_state( Environment * _environment, char *_scancode, char * _result );
void pc1403_scancode( Environment * _environment, char * _scacode );
void pc1403_asciicode( Environment * _environment, char * _asciicode );
void pc1403_inkey( Environment * _environment, char * _key );
void pc1403_key_pressed( Environment * _environment, char *_scancode, char * _result );
void pc1403_put_key(  Environment * _environment, char *_string, char * _size );

void pc1403_scanshift( Environment * _environment, char * _shifts );
void pc1403_keyshift( Environment * _environment, char * _shifts );
void pc1403_clear_key( Environment * _environment );
void pc1403_irq_at( Environment * _environment, char * _label );
void pc1403_follow_irq( Environment * _environment );
void pc1403_joy( Environment * _environment, int _port, char * _result );
void pc1403_joy_vars( Environment * _environment, char * _port, char * _result );

void pc1403_sys_call( Environment * _environment, int _destination );

void pc1403_timer_set_status_on( Environment * _environment, char * _timer );
void pc1403_timer_set_status_off( Environment * _environment, char * _timer );
void pc1403_timer_set_counter( Environment * _environment, char * _timer, char * _counter );
void pc1403_timer_set_init( Environment * _environment, char * _timer, char * _init );
void pc1403_timer_set_address( Environment * _environment, char * _timer, char * _address );
void pc1403_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size );
void pc1403_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size );

void pc1403_cls( Environment * _environment );
void pc1403_pset_int( Environment * _environment, int _x, int _y, int *_c );
void pc1403_pset_vars( Environment * _environment, char *_x, char *_y, char *_c );
void pc1403_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result );

void pc1403_dojo_ready( Environment * _environment, char * _value );
void pc1403_dojo_read_byte( Environment * _environment, char * _value );
void pc1403_dojo_write_byte( Environment * _environment, char * _value );

void pc1403_dojo_ping( Environment * _environment, char * _result );
void pc1403_dojo_login( Environment * _environment, char * _name, char * _name_size, char * _password, char * _size, char * _unique_id );
void pc1403_dojo_success( Environment * _environment, char * _id, char * _result );
void pc1403_dojo_create_port( Environment * _environment, char * _session_id, char * _application, char * _size, char * _port_id );
void pc1403_dojo_find_port( Environment * _environment, char * _session_id, char * _username, char * _size, char * _application, char * _application_size, char * _port_id );
void pc1403_dojo_put_message( Environment * _environment, char * _port_id, char * _message, char * _size, char * _result );
void pc1403_dojo_peek_message( Environment * _environment, char * _port_id, char * _result );
void pc1403_dojo_get_message( Environment * _environment, char * _port_id, char * _result, char * _message );
void pc1403_dojo_destroy_port( Environment * _environment, char * _port_id, char * _result );

#endif