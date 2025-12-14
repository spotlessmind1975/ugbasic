#ifndef __UGBC_PCCGA__
#define __UGBC_PCCGA__

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

// _1	2
// _2	8
// _3	3
// _4	13
// _5	12
// _6	1
// _7	10
// _8	14
// _9	4
// _0	5
// _#	9
// _*	6

#define KEY_NONE					0
#define KEY_0						11
#define KEY_1						2
#define KEY_2						3
#define KEY_3						4
#define KEY_4						5
#define KEY_5						6
#define KEY_6						7
#define KEY_7						8
#define KEY_8						9
#define KEY_9						10
#define KEY_A						30
#define KEY_ASTERISK				0xff
#define KEY_AT						0xff
#define KEY_B						48
#define KEY_C						46
#define KEY_CLEAR					0xff
#define KEY_COLON					0xff
#define KEY_COMMA					51
#define KEY_COMMODORE				0xff
#define KEY_CONTROL					29
#define KEY_CRSR_LEFT_RIGHT			0xff
#define KEY_CRSR_UP_DOWN			0xff
#define KEY_D						32
#define KEY_DELETE					83
#define KEY_E						18
#define KEY_EQUAL					0xff
#define KEY_F						33
#define KEY_F1						59
#define KEY_F2						60
#define KEY_F3						61
#define KEY_F4						62
#define KEY_F5						63
#define KEY_F6						64
#define KEY_F7						65
#define KEY_F8						66
#define KEY_G						34
#define KEY_H						35
#define KEY_HOME					71
#define KEY_I						23
#define KEY_INSERT					82
#define KEY_J						36
#define KEY_K						37
#define KEY_L						38
#define KEY_LEFT_ARROW				0xff
#define KEY_LEFT_SHIFT				42
#define KEY_M						50
#define KEY_MINUS					53
#define KEY_N						49
#define KEY_O						24
#define KEY_P						25
#define KEY_PERIOD					52
#define KEY_PLUS					27
#define KEY_POUND					0xff
#define KEY_Q						16
#define KEY_R						19
#define KEY_RETURN					28
#define KEY_RIGHT_SHIFT				54
#define KEY_RUNSTOP					0xff
#define KEY_S						31
#define KEY_SEMICOLON				0xff
#define KEY_SLASH					0xff
#define KEY_SPACE					57
#define KEY_T						20
#define KEY_U						22
#define KEY_UP_ARROW				0xff
#define KEY_V						47
#define KEY_W						17
#define KEY_X						45
#define KEY_Y						21
#define KEY_Z						44
#define KEY_BACKSLASH               41
#define KEY_SQUARE_OPEN             0xff
#define KEY_SQUARE_CLOSED           0xff
#define KEY_SEMICOMMA               0xff
#define KEY_QUOTE                   0xff
#define KEY_APIX                    0xff
#define KEY_DEAD                    0xff
#define KEY_SHIFT                   0xff
#define KEY_CTRL                    29
#define KEY_GRAPH                   0xff
#define KEY_CAPS                    58
#define KEY_CODE                    0xff
#define KEY_ESC                     1
#define KEY_TAB                     15
#define KEY_STOP                    0xff
#define KEY_BS                      14
#define KEY_SELECT                  0xff
#define KEY_RET                     0xff
#define KEY_INS                     82
#define KEY_DEL                     83
#define KEY_LEFT                    75
#define KEY_UP                      72
#define KEY_DOWN                    80
#define KEY_RIGHT                   77
#define KEY_DIVISION                0xff

#define KEYBOARD_CONFIG_DEFAULT_SYNC       1

#define INPUT_DEFAULT_SEPARATOR     ','
#define INPUT_DEFAULT_SIZE          32
#define INPUT_DEFAULT_CURSOR        0x60

#define SCREEN_CAPABILITIES         ( ( 1<<TILEMAP_NATIVE ) | ( 1<<BITMAP_NATIVE ) )

#define JOY_COUNT           2

#define JOY_UP              0
#define JOY_DOWN            2
#define JOY_LEFT            3
#define JOY_RIGHT           1
#define JOY_FIRE            6

#define JOYSTICK_CONFIG_DEFAULT_SYNC      1

#define DEFAULT_PAINT_BUCKET_SIZE   64

#define BANK_COUNT          0
#define BANK_SIZE           0
#define BANK_BASE_ADDRESS   0

#define MAX_AUDIO_CHANNELS  3

#define DSTRING_DEFAULT_COUNT           255
#define DSTRING_DEFAULT_SPACE           1024

void pccga_wait_fire( Environment * _environment, int _port, int _release );
void pccga_wait_fire_semivar( Environment * _environment, char * _port, int _release );
void pccga_wait_key_or_fire( Environment * _environment, int _port, int _release );
void pccga_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release );
void pccga_inkey( Environment * _environment, char * _pressed, char * _key );
void pccga_scancode( Environment * _environment, char * _scacode );
void pccga_asciicode( Environment * _environment, char * _scacode );
void pccga_scanshift( Environment * _environment, char * _shifts );
void pccga_key_state( Environment * _environment, char *_scancode, char * _result );
void pccga_keyshift( Environment * _environment, char * _shifts );
void pccga_key_pressed( Environment * _environment, char *_scancode, char * _result );
void pccga_clear_key( Environment * _environment );
void pccga_joy( Environment * _environment, int _port, char * _value );
void pccga_joy_vars( Environment * _environment, char * _port, char * _value );
void pccga_wait_key( Environment * _environment, int _release );

void pccga_sys_call( Environment * _environment, int _destination );

void pccga_timer_set_status_on( Environment * _environment, char * _timer );
void pccga_timer_set_status_off( Environment * _environment, char * _timer );
void pccga_timer_set_counter( Environment * _environment, char * _timer, char * _counter );
void pccga_timer_set_init( Environment * _environment, char * _timer, char * _init );
void pccga_timer_set_address( Environment * _environment, char * _timer, char * _address );

#endif