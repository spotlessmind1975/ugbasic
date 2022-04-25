#ifndef __UGBC_PC128OP__
#define __UGBC_PC128OP__

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

#define KEY_NONE					0xff
#define KEY_0						0x3c
#define KEY_1						0x5e
#define KEY_2						0x4e
#define KEY_3						0x3e
#define KEY_4						0x2e
#define KEY_5						0x1e
#define KEY_6						0x0e
#define KEY_7						0x0c
#define KEY_8						0x1c
#define KEY_9						0x2c
#define KEY_A						0x5a
#define KEY_ASTERISK				0x58
#define KEY_AT						0x30
#define KEY_B						0x44
#define KEY_C						0x64
#define KEY_CLEAR					0xf9
#define KEY_COLON					0x00
#define KEY_COMMA					0x00
#define KEY_COMMODORE				0x00
#define KEY_CONTROL					0x6a
#define KEY_CRSR_LEFT_RIGHT			0x00
#define KEY_CRSR_UP_DOWN			0x00
#define KEY_D						0x36
#define KEY_DELETE					0xf9
#define KEY_DOWN                    0x42
#define KEY_E						0x3a
#define KEY_EQUAL					0x00
#define KEY_F						0x26
#define KEY_F1						0x00
#define KEY_F2						0x00
#define KEY_F3						0x00
#define KEY_F4						0x00
#define KEY_F5						0x00
#define KEY_F6						0x00
#define KEY_F7						0x00
#define KEY_F8						0x00
#define KEY_G						0x16
#define KEY_H						0x06
#define KEY_HOME					0x22
#define KEY_I						0x18
#define KEY_INSERT					0x12
#define KEY_J						0x04
#define KEY_K						0x14
#define KEY_L						0x24
#define KEY_LEFT                    0x52
#define KEY_LEFT_ARROW				0x00
#define KEY_LEFT_SHIFT				0xfe
#define KEY_M						0x34
#define KEY_MINUS					0x4c
#define KEY_N						0x00
#define KEY_O						0x28
#define KEY_P						0x38
#define KEY_PERIOD					0x20
#define KEY_PLUS					0x5c
#define KEY_POUND					0x00
#define KEY_Q						0x56
#define KEY_R						0x2a
#define KEY_RETURN					0x68
#define KEY_RIGHT					0x32
#define KEY_RIGHT_SHIFT				0xfe
#define KEY_RUNSTOP					0x00
#define KEY_S						0x46
#define KEY_SEMICOLON				0x00
#define KEY_SLASH					0x48
#define KEY_SPACE					0x40
#define KEY_T						0x1a
#define KEY_U						0x08
#define KEY_UP						0x62
#define KEY_UP_ARROW				0x62
#define KEY_V						0x54
#define KEY_W						0x60
#define KEY_X						0x50
#define KEY_Y						0x0a
#define KEY_Z						0x4a
#define KEY_BACKSLASH                0x00
#define KEY_SQUARE_OPEN              0x00
#define KEY_SQUARE_CLOSED            0x00
#define KEY_SEMICOMMA                0x00
#define KEY_QUOTE                    0x00
#define KEY_APIX                     0x10
#define KEY_DEAD                     0x00
#define KEY_SHIFT                    0x70
#define KEY_CTRL                     0x00
#define KEY_GRAPH                    0x00
#define KEY_CAPS                     0x00
#define KEY_CODE                     0x00
#define KEY_ESC                      0x00
#define KEY_TAB                      0x00
#define KEY_STOP                     0x6E
#define KEY_BS                       0xf9
#define KEY_SELECT                   0x00
#define KEY_RET                      0x0d
#define KEY_INS                      0x00
#define KEY_DEL                      0xf9
#define KEY_DIVISION                 KEY_SLASH

#define         JOY_COUNT           2
#define JOYSTICK_0					0
#define JOYSTICK_1					1
#define JOYSTICK_COUNT				2

#define JOY_UP              1
#define JOY_DOWN            2
#define JOY_LEFT            3
#define JOY_RIGHT           4
#define JOY_FIRE            2

#define INPUT_DEFAULT_SEPARATOR     ','
#define INPUT_DEFAULT_SIZE          32
#define INPUT_DEFAULT_CURSOR        0x60

#define SCREEN_CAPABILITIES         ( ( 1<<TILEMAP_NATIVE ) | ( 1<<BITMAP_NATIVE ) )

#define BANK_COUNT                  6
#define BANK_SIZE                   16384

#define MAX_AUDIO_CHANNELS  1

void pc128op_xpen( Environment * _environment, char * _destination );
void pc128op_ypen( Environment * _environment, char * _destination );
void pc128op_inkey( Environment * _environment, char * _pressed, char * _key );
void pc128op_scancode( Environment * _environment, char * _pressed, char * _scacode );
void pc128op_scanshift( Environment * _environment, char * _shifts );
void pc128op_keyshift( Environment * _environment, char * _shifts );
void pc128op_key_pressed( Environment * _environment, char *_scancode, char * _result );
void pc128op_clear_key( Environment * _environment );
void pc128op_busy_wait( Environment * _environment, char * _timing );
void pc128op_irq_at( Environment * _environment, char * _label );
void pc128op_follow_irq( Environment * _environment );
int pc128op_convertbintok7_original(Environment * _environment);
void pc128op_joystick( Environment * _environment, char * _joystick, char * _result );

#endif