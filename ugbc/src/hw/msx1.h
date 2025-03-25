#ifndef __UGBC_MSX1__
#define __UGBC_MSX1__

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

#define SCREEN_CAPABILITIES         ( ( 1<<TILEMAP_NATIVE ) | ( 1<<BITMAP_NATIVE ) )

#define DEFAULT_PAINT_BUCKET_SIZE   512

#define BANK_COUNT          1
#define BANK_SIZE           4096
#define BANK_BASE_ADDRESS   0

#define JOY_COUNT           2

#define JOY_UP              0
#define JOY_DOWN            1
#define JOY_LEFT            2
#define JOY_RIGHT           3
#define JOY_FIRE            4

#define JOYSTICK_CONFIG_DEFAULT_SYNC      1

#define MAX_AUDIO_CHANNELS  3

void msx1_wait_key( Environment * _environment, int _release );
void msx1_wait_fire( Environment * _environment, int _port, int _release );
void msx1_wait_fire_semivar( Environment * _environment, char * _port, int _release );
void msx1_wait_key_or_fire( Environment * _environment, int _port, int _release );
void msx1_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release );
void msx1_key_state( Environment * _environment, char *_scancode, char * _result );
void msx1_scancode( Environment * _environment, char * _scacode );
void msx1_asciicode( Environment * _environment, char * _asciicode );
void msx1_inkey( Environment * _environment, char * _key );
void msx1_key_pressed( Environment * _environment, char *_scancode, char * _result );
void msx1_put_key(  Environment * _environment, char *_string, char * _size );

void msx1_scanshift( Environment * _environment, char * _shifts );
void msx1_keyshift( Environment * _environment, char * _shifts );
void msx1_clear_key( Environment * _environment );
void msx1_joy( Environment * _environment, int _port, char * _result );
void msx1_joy_vars( Environment * _environment, char * _port, char * _result );

void msx1_sys_call( Environment * _environment, int _destination );

void msx1_timer_set_status_on( Environment * _environment, char * _timer );
void msx1_timer_set_status_off( Environment * _environment, char * _timer );
void msx1_timer_set_counter( Environment * _environment, char * _timer, char * _counter );
void msx1_timer_set_init( Environment * _environment, char * _timer, char * _init );
void msx1_timer_set_address( Environment * _environment, char * _timer, char * _address );
void msx1_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size );
void msx1_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size );

#endif