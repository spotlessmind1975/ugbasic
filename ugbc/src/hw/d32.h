#ifndef __UGBC_D32__
#define __UGBC_D32__

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
#define KEY_0                       0
#define KEY_8                       1
#define KEY_AT                      2
#define KEY_H                       3
#define KEY_P                       4
#define KEY_X                       5
#define KEY_RETURN                  6

#define KEY_1                       8
#define KEY_9                       9
#define KEY_A                      10
#define KEY_I                      11
#define KEY_Q                      12
#define KEY_Y                      13
#define KEY_CLEAR                  14

#define KEY_2                      16
#define KEY_ASTERISK               17
#define KEY_B                      18
#define KEY_J                      19
#define KEY_R                      20
#define KEY_Z                      21

#define KEY_3                      24
#define KEY_COMMA                  25
#define KEY_C                      26
#define KEY_K                      27
#define KEY_S                      28
#define KEY_UP                     29

#define KEY_4                      32
#define KEY_MINUS                  33
#define KEY_D                      34
#define KEY_L                      35
#define KEY_T                      36
#define KEY_DOWN                   37

#define KEY_5                      40

#define KEY_E                      42
#define KEY_M                      43
#define KEY_U                      44
#define KEY_LEFT                   45

#define KEY_6                      48
#define KEY_SLASH                  49
#define KEY_F                      50
#define KEY_N                      51
#define KEY_V                      52
#define KEY_RIGHT                  53

#define KEY_7                      56

#define KEY_G                      58
#define KEY_O                      59
#define KEY_W                      60
#define KEY_SPACE                  61

#define KEY_SHIFT                  63

#define KEY_COLON				    0
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
#define KEY_PERIOD					0
#define KEY_PLUS					0
#define KEY_POUND					0
#define KEY_RIGHT_SHIFT				0
#define KEY_RUNSTOP					0
#define KEY_SEMICOLON				0
#define KEY_UP_ARROW				0
#define KEY_BACKSLASH               0
#define KEY_SQUARE_OPEN             0
#define KEY_SQUARE_CLOSED           0
#define KEY_SEMICOMMA               0
#define KEY_QUOTE                   0
#define KEY_APIX                    0
#define KEY_DEAD                    0
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
#define KEY_DIVISION                0

#define         JOY_COUNT           2
#define JOYSTICK_0					0
#define JOYSTICK_1					1
#define JOYSTICK_COUNT				2

#define JOY_UP              0
#define JOY_DOWN            1
#define JOY_LEFT            2
#define JOY_RIGHT           3
#define JOY_FIRE            5

#define INPUT_DEFAULT_SEPARATOR     ','
#define INPUT_DEFAULT_SIZE          32
#define INPUT_DEFAULT_CURSOR        96
#define INPUT_DEFAULT_RATE          16

#define SCREEN_CAPABILITIES         ( ( 1<<TILEMAP_NATIVE ) | ( 1<<BITMAP_NATIVE ) )

#define DEFAULT_PAINT_BUCKET_SIZE   512

#define BANK_COUNT          1
#define BANK_SIZE           4096

#define MAX_AUDIO_CHANNELS  1

void d32_xpen( Environment * _environment, char * _destination );
void d32_ypen( Environment * _environment, char * _destination );

void d32_wait_key( Environment * _environment, int _release );
void d32_key_state( Environment * _environment, char *_scancode, char * _result );
void d32_scancode( Environment * _environment, char * _scacode );
void d32_asciicode( Environment * _environment, char * _asciicode );
void d32_inkey( Environment * _environment, char * _key );
void d32_key_pressed( Environment * _environment, char *_scancode, char * _result );
void d32_put_key(  Environment * _environment, char *_string, char * _size );

void d32_scanshift( Environment * _environment, char * _shifts );
void d32_keyshift( Environment * _environment, char * _shifts );
void d32_clear_key( Environment * _environment );
void d32_busy_wait( Environment * _environment, char * _timing );
void d32_irq_at( Environment * _environment, char * _label );
void d32_follow_irq( Environment * _environment );

void d32_sys_call( Environment * _environment, int _destination );

void d32_timer_set_status_on( Environment * _environment, char * _timer );
void d32_timer_set_status_off( Environment * _environment, char * _timer );
void d32_timer_set_counter( Environment * _environment, char * _timer, char * _counter );
void d32_timer_set_init( Environment * _environment, char * _timer, char * _init );
void d32_timer_set_address( Environment * _environment, char * _timer, char * _address );

#endif