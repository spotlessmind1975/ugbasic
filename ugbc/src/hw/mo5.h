#ifndef __UGBC_MO5__
#define __UGBC_MO5__

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

#define KEY_NONE					0xff
#define KEY_0					    0x0a
#define KEY_1						0x01
#define KEY_2						0x02
#define KEY_3						0x03
#define KEY_4						0x04
#define KEY_5						0x05
#define KEY_6						0x06
#define KEY_7						0x0d
#define KEY_8						0x0c
#define KEY_9						0x0b
#define KEY_A						0x10
#define KEY_ASTERISK				0x08
#define KEY_AT						0x00
#define KEY_B						0x31
#define KEY_C						0x2f
#define KEY_CLEAR					0x38
#define KEY_COLON					0x34
#define KEY_COMMA					0x33
#define KEY_COMMODORE				0x00
#define KEY_CONTROL					0x0f
#define KEY_CRSR_LEFT_RIGHT			0x00
#define KEY_CRSR_UP_DOWN			0x00
#define KEY_D						0x22
#define KEY_DELETE					0x38
#define KEY_E						0x12
#define KEY_EQUAL					0x00
#define KEY_F						0x23
#define KEY_F1						0x00
#define KEY_F2						0x00
#define KEY_F3						0x00
#define KEY_F4						0x00
#define KEY_F5						0x00
#define KEY_F6						0x00
#define KEY_F7						0x00
#define KEY_F8						0x00
#define KEY_G						0x24
#define KEY_H						0x25
#define KEY_HOME					0x1f
#define KEY_I						0x1a
#define KEY_INSERT					0x37
#define KEY_J						0x29
#define KEY_K						0x28
#define KEY_L						0x27
#define KEY_LEFT_ARROW				0x00
#define KEY_LEFT_SHIFT				0x00
#define KEY_M					    0x26
#define KEY_MINUS					0x00
#define KEY_N						0x2c
#define KEY_O						0x19
#define KEY_P						0x18
#define KEY_PERIOD					0x34
#define KEY_PLUS					0x00
#define KEY_POUND					0x00
#define KEY_Q						0x20
#define KEY_R						0x13
#define KEY_RETURN					0x0d
#define KEY_RIGHT_SHIFT				0x00
#define KEY_RUNSTOP					0x00
#define KEY_S						0x21
#define KEY_SEMICOLON				0x33
#define KEY_SLASH					0x00
#define KEY_SPACE					0x39
#define KEY_T						0x14
#define KEY_U						0x1b
#define KEY_UP_ARROW				0x00
#define KEY_V						0x30
#define KEY_W						0x2d
#define KEY_X						0x2e
#define KEY_Y						0x15
#define KEY_Z						0x11
#define KEY_BACKSLASH               0x16
#define KEY_SQUARE_OPEN             0x00
#define KEY_SQUARE_CLOSED           0x00
#define KEY_SEMICOMMA               0x00
#define KEY_QUOTE                   0x00
#define KEY_APIX                    0x00
#define KEY_DEAD                    0x00
#define KEY_SHIFT                   0x36
#define KEY_CTRL                    0x0f
#define KEY_GRAPH                   0x00
#define KEY_CAPS                    0x00
#define KEY_CODE                    0x00
#define KEY_ESC                     0x00
#define KEY_TAB                     0x00
#define KEY_STOP                    0xff
#define KEY_BS                      0x38
#define KEY_SELECT                  0x00
#define KEY_RET                     0x00
#define KEY_INS                     0x00
#define KEY_DEL                     0x38
#define KEY_LEFT                    0x1c
#define KEY_UP                      0x0e
#define KEY_DOWN                    0x2b
#define KEY_RIGHT                   0x1d
#define KEY_DIVISION                0x00

#define KEYBOARD_CONFIG_DEFAULT_SYNC       1

#define         JOY_COUNT           0
#define JOYSTICK_0					0
#define JOYSTICK_1					1
#define JOYSTICK_COUNT				0

#define JOY_UP              1
#define JOY_DOWN            2
#define JOY_LEFT            3
#define JOY_RIGHT           4
#define JOY_FIRE            2

#define JOYSTICK_CONFIG_DEFAULT_SYNC      1

#define INPUT_DEFAULT_SEPARATOR     ','
#define INPUT_DEFAULT_SIZE          32
#define INPUT_DEFAULT_CURSOR        0x60
#define INPUT_DEFAULT_RATE          16

#define SCREEN_CAPABILITIES         ( ( 1<<TILEMAP_NATIVE ) | ( 1<<BITMAP_NATIVE ) )

#define DEFAULT_PAINT_BUCKET_SIZE   512

#define BANK_COUNT          0
#define BANK_SIZE           16128

#define MAX_AUDIO_CHANNELS  1

#define BASE_SEGMENT        0xa7

#define EF936X_COMPONENT_BITMASK     0

void mo5_xpen( Environment * _environment, char * _destination );
void mo5_ypen( Environment * _environment, char * _destination );

void mo5_wait_key( Environment * _environment, int _release );
void mo5_wait_fire( Environment * _environment, int _port, int _release );
void mo5_wait_fire_semivar( Environment * _environment, char * _port, int _release );
void mo5_wait_key_or_fire( Environment * _environment, int _port, int _release );
void mo5_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release );
void mo5_key_state( Environment * _environment, char *_scancode, char * _result );
void mo5_scancode( Environment * _environment, char * _scacode );
void mo5_asciicode( Environment * _environment, char * _asciicode );
void mo5_inkey( Environment * _environment, char * _key );
void mo5_key_pressed( Environment * _environment, char *_scancode, char * _result );
void mo5_put_key(  Environment * _environment, char *_string, char * _size );

void mo5_scanshift( Environment * _environment, char * _shifts );
void mo5_keyshift( Environment * _environment, char * _shifts );
void mo5_clear_key( Environment * _environment );
void mo5_busy_wait( Environment * _environment, char * _timing );
int convertbintok7(Environment * _environment);
int convertbintok7_original(Environment * _environment);
void mo5_joystick_semivars( Environment * _environment, int _joystick, char * _result );
void mo5_joystick_vars( Environment * _environment, char * _joystick, char * _result );

void mo5_sys_call( Environment * _environment, int _destination );

void mo5_timer_set_status_on( Environment * _environment, char * _timer );
void mo5_timer_set_status_off( Environment * _environment, char * _timer );
void mo5_timer_set_counter( Environment * _environment, char * _timer, char * _counter );
void mo5_timer_set_init( Environment * _environment, char * _timer, char * _init );
void mo5_timer_set_address( Environment * _environment, char * _timer, char * _address );

void mo5_dojo_ready( Environment * _environment, char * _value );
void mo5_dojo_read_byte( Environment * _environment, char * _value );
void mo5_dojo_write_byte( Environment * _environment, char * _value );

void mo5_dojo_ping( Environment * _environment, char * _result );
void mo5_dojo_login( Environment * _environment, char * _name, char * _name_size, char * _password, char * _size, char * _unique_id );
void mo5_dojo_success( Environment * _environment, char * _id, char * _result );
void mo5_dojo_create_port( Environment * _environment, char * _session_id, char * _application, char * _size, char * _port_id );
void mo5_dojo_find_port( Environment * _environment, char * _session_id, char * _username, char * _size, char * _application, char * _application_size, char * _port_id );
void mo5_dojo_put_message( Environment * _environment, char * _port_id, char * _message, char * _size, char * _result );
void mo5_dojo_peek_message( Environment * _environment, char * _port_id, char * _result );
void mo5_dojo_get_message( Environment * _environment, char * _port_id, char * _result, char * _message );
void mo5_dojo_destroy_port( Environment * _environment, char * _port_id, char * _result );

#endif