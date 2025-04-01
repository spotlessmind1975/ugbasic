#ifndef __UGBC_VZ200__
#define __UGBC_VZ200__

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
#define KEY_0						'0'
#define KEY_1						72
#define KEY_2						65
#define KEY_3						57
#define KEY_4						64
#define KEY_5						49
#define KEY_6						56
#define KEY_7						41
#define KEY_8						48
#define KEY_9						33
#define KEY_A						69
#define KEY_ASTERISK				0xfe
#define KEY_AT						0xfe
#define KEY_B						54
#define KEY_C						62
#define KEY_CLEAR					0xfe
#define KEY_COLON					0xfe
#define KEY_COMMA					38
#define KEY_COMMODORE				0xfe
#define KEY_CONTROL					23
#define KEY_CRSR_LEFT_RIGHT			0xfe
#define KEY_CRSR_UP_DOWN			0xfe
#define KEY_D						61
#define KEY_DELETE					24
#define KEY_E						58
#define KEY_EQUAL					0xfe
#define KEY_F						53
#define KEY_F1						0xfe
#define KEY_F2						0xfe
#define KEY_F3						0xfe
#define KEY_F4						0xfe
#define KEY_F5						0xfe
#define KEY_F6						0xfe
#define KEY_F7						0xfe
#define KEY_F8						0xfe
#define KEY_G					    52
#define KEY_H						44
#define KEY_HOME					0xfe
#define KEY_I						35
#define KEY_INSERT					0xfe
#define KEY_J						45
#define KEY_K						37
#define KEY_L						36
#define KEY_LEFT_ARROW				0xfe
#define KEY_LEFT_SHIFT				21
#define KEY_M						29
#define KEY_MINUS					0xfe
#define KEY_N						46
#define KEY_O						34
#define KEY_P						27
#define KEY_PERIOD					39
#define KEY_PLUS					32
#define KEY_POUND					0xfe
#define KEY_Q						69
#define KEY_R						50
#define KEY_RETURN					18
#define KEY_RIGHT_SHIFT				21
#define KEY_RUNSTOP					0xfe
#define KEY_S						60
#define KEY_SEMICOLON				0xfe
#define KEY_SLASH					0xfe
#define KEY_SPACE					47
#define KEY_T						51
#define KEY_U						42
#define KEY_UP_ARROW				8
#define KEY_V						5
#define KEY_W						71
#define KEY_X						63
#define KEY_Y						43
#define KEY_Z						59
#define KEY_BACKSLASH               19
#define KEY_SQUARE_OPEN             0xfe
#define KEY_SQUARE_CLOSED           0xfe
#define KEY_SEMICOMMA               0xfe
#define KEY_QUOTE                   0xfe
#define KEY_APIX                    0xfe
#define KEY_DEAD                    0xfe
#define KEY_SHIFT                   21
#define KEY_CTRL                    23
#define KEY_GRAPH                   0xfe
#define KEY_CAPS                    70
#define KEY_CODE                    0xfe
#define KEY_ESC                     66
#define KEY_TAB                     68
#define KEY_STOP                    0xfe
#define KEY_BS                      79
#define KEY_SELECT                  0xfe
#define KEY_RET                     0xfe
#define KEY_INS                     0xfe
#define KEY_DEL                     24
#define KEY_LEFT                    8
#define KEY_UP                      0
#define KEY_DOWN                    2
#define KEY_RIGHT                   1
#define KEY_DIVISION                0xfe

#define KEYBOARD_CONFIG_DEFAULT_SYNC       1

#define INPUT_DEFAULT_SEPARATOR     ','
#define INPUT_DEFAULT_SIZE          32
#define INPUT_DEFAULT_CURSOR        95
#define INPUT_DEFAULT_RATE          16
#define INPUT_DEFAULT_DELAY         16

#define SCREEN_CAPABILITIES         ( ( 1<<BITMAP_NATIVE ) )

#define JOY_COUNT           2

#define JOY_UP              0
#define JOY_DOWN            1
#define JOY_LEFT            2
#define JOY_RIGHT           3
#define JOY_FIRE            4

#define JOYSTICK_CONFIG_DEFAULT_SYNC      1

#define DEFAULT_PAINT_BUCKET_SIZE   1024

#define BANK_COUNT          0
#define BANK_SIZE           0

#define MAX_AUDIO_CHANNELS      1

void vz200_wait_key( Environment * _environment, int _release );
void vz200_wait_fire( Environment * _environment, int _port, int _release );
void vz200_wait_fire_semivar( Environment * _environment, char * _port, int _release );
void vz200_wait_key_or_fire( Environment * _environment, int _port, int _release );
void vz200_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release );
void vz200_key_state( Environment * _environment, char *_scancode, char * _result );
void vz200_scancode( Environment * _environment, char * _scacode );
void vz200_asciicode( Environment * _environment, char * _asciicode );
void vz200_inkey( Environment * _environment, char * _key );
void vz200_key_pressed( Environment * _environment, char *_scancode, char * _result );

void vz200_scanshift( Environment * _environment, char * _shifts );
void vz200_keyshift( Environment * _environment, char * _shifts );
void vz200_clear_key( Environment * _environment );
void vz200_put_key(  Environment * _environment, char *_string, char * _size );

void vz200_joy( Environment * _environment, int _port, char * _value );
void vz200_joy_vars( Environment * _environment, char * _port, char * _value );

void vz200_timer_set_status_on( Environment * _environment, char * _timer );
void vz200_timer_set_status_off( Environment * _environment, char * _timer );
void vz200_timer_set_counter( Environment * _environment, char * _timer, char * _counter );
void vz200_timer_set_init( Environment * _environment, char * _timer, char * _init );
void vz200_timer_set_address( Environment * _environment, char * _timer, char * _address );
void vz200_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size );
void vz200_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size );
void vz200_flip_image( Environment * _environment, Resource * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _direction );
void vz200_sys_call( Environment * _environment, int _destination );

#endif