#ifndef __UGBC_C128Z__
#define __UGBC_C128Z__

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

#define KEY_NONE					64
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
#define KEY_ASTERISK				0xff
#define KEY_AT						0xff
#define KEY_B						54
#define KEY_C						62
#define KEY_CLEAR					0xff
#define KEY_COLON					0xff
#define KEY_COMMA					38
#define KEY_COMMODORE				0xff
#define KEY_CONTROL					23
#define KEY_CRSR_LEFT_RIGHT			0xff
#define KEY_CRSR_UP_DOWN			0xff
#define KEY_D						61
#define KEY_DELETE					24
#define KEY_E						58
#define KEY_EQUAL					0xff
#define KEY_F						53
#define KEY_F1						0xff
#define KEY_F2						0xff
#define KEY_F3						0xff
#define KEY_F4						0xff
#define KEY_F5						0xff
#define KEY_F6						0xff
#define KEY_F7						0xff
#define KEY_F8						0xff
#define KEY_G					    52
#define KEY_H						44
#define KEY_HOME					0xff
#define KEY_I						35
#define KEY_INSERT					0xff
#define KEY_J						45
#define KEY_K						37
#define KEY_L						36
#define KEY_LEFT_ARROW				0xff
#define KEY_LEFT_SHIFT				21
#define KEY_M						29
#define KEY_MINUS					0xff
#define KEY_N						46
#define KEY_O						34
#define KEY_P						27
#define KEY_PERIOD					39
#define KEY_PLUS					32
#define KEY_POUND					0xff
#define KEY_Q						69
#define KEY_R						50
#define KEY_RETURN					18
#define KEY_RIGHT_SHIFT				21
#define KEY_RUNSTOP					0xff
#define KEY_S						60
#define KEY_SEMICOLON				0xff
#define KEY_SLASH					0xff
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
#define KEY_SQUARE_OPEN             0xff
#define KEY_SQUARE_CLOSED           0xff
#define KEY_SEMICOMMA               0xff
#define KEY_QUOTE                   0xff
#define KEY_APIX                    0xff
#define KEY_DEAD                    0xff
#define KEY_SHIFT                   21
#define KEY_CTRL                    23
#define KEY_GRAPH                   0xff
#define KEY_CAPS                    70
#define KEY_CODE                    0xff
#define KEY_ESC                     66
#define KEY_TAB                     68
#define KEY_STOP                    0xff
#define KEY_BS                      79
#define KEY_SELECT                  0xff
#define KEY_RET                     0xff
#define KEY_INS                     0xff
#define KEY_DEL                     24
#define KEY_LEFT                    16
#define KEY_UP                      8
#define KEY_DOWN                    2
#define KEY_RIGHT                   1
#define KEY_DIVISION                0xff

#define INPUT_DEFAULT_SEPARATOR     ','
#define INPUT_DEFAULT_SIZE          32
#define INPUT_DEFAULT_CURSOR        0x60

#define SCREEN_CAPABILITIES         ( ( 1<<BITMAP_NATIVE ) )

#define JOY_COUNT           2

#define JOY_UP              0
#define JOY_DOWN            1
#define JOY_LEFT            2
#define JOY_RIGHT           3
#define JOY_FIRE            4

#define BANK_COUNT          0
#define BANK_SIZE           0

#define MAX_AUDIO_CHANNELS  3

void c128z_inkey( Environment * _environment, char * _pressed, char * _key );
void c128z_scancode( Environment * _environment, char * _pressed, char * _scacode );
void c128z_scanshift( Environment * _environment, char * _shifts );
void c128z_keyshift( Environment * _environment, char * _shifts );
void c128z_key_pressed( Environment * _environment, char *_scancode, char * _result );
void c128z_clear_key( Environment * _environment );
void c128z_irq_at( Environment * _environment, char * _label );
void c128z_follow_irq( Environment * _environment );
void c128z_joy( Environment * _environment, int _port, char * _value );
void c128z_joy_vars( Environment * _environment, char * _port, char * _value );

void c128z_initialization( Environment * _environment );
void c128z_finalization( Environment * _environment );

void c128z_sys_call( Environment * _environment, int _destination );

#endif