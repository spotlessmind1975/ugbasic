#ifndef __UGBC_COLECO__
#define __UGBC_COLECO__

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
#define KEY_0						5
#define KEY_1						2
#define KEY_2						8
#define KEY_3						3
#define KEY_4						13
#define KEY_5						12
#define KEY_6						1
#define KEY_7						10
#define KEY_8						14
#define KEY_9						4
#define KEY_A						0xff
#define KEY_ASTERISK				6
#define KEY_AT						0xff
#define KEY_B						0xff
#define KEY_C						0xff
#define KEY_CLEAR					0xff
#define KEY_COLON					0xff
#define KEY_COMMA					0xff
#define KEY_COMMODORE				0xff
#define KEY_CONTROL					0xff
#define KEY_CRSR_LEFT_RIGHT			0xff
#define KEY_CRSR_UP_DOWN			0xff
#define KEY_D						0xff
#define KEY_DELETE					0xff
#define KEY_E						0xff
#define KEY_EQUAL					0xff
#define KEY_F						0xff
#define KEY_F1						0xff
#define KEY_F2						0xff
#define KEY_F3						0xff
#define KEY_F4						0xff
#define KEY_F5						0xff
#define KEY_F6						0xff
#define KEY_F7						0xff
#define KEY_F8						0xff
#define KEY_G						0xff
#define KEY_H						0xff
#define KEY_HOME					0xff
#define KEY_I						0xff
#define KEY_INSERT					0xff
#define KEY_J						0xff
#define KEY_K						0xff
#define KEY_L						0xff
#define KEY_LEFT_ARROW				0xff
#define KEY_LEFT_SHIFT				0xff
#define KEY_M						0xff
#define KEY_MINUS					0xff
#define KEY_N						0xff
#define KEY_O						0xff
#define KEY_P						0xff
#define KEY_PERIOD					0xff
#define KEY_PLUS					0xff
#define KEY_POUND					0xff
#define KEY_Q						0xff
#define KEY_R						0xff
#define KEY_RETURN					0xff
#define KEY_RIGHT_SHIFT				0xff
#define KEY_RUNSTOP					0xff
#define KEY_S						0xff
#define KEY_SEMICOLON				0xff
#define KEY_SLASH					0xff
#define KEY_SPACE					0xff
#define KEY_T						0xff
#define KEY_U						0xff
#define KEY_UP_ARROW				0xff
#define KEY_V						0xff
#define KEY_W						0xff
#define KEY_X						0xff
#define KEY_Y						0xff
#define KEY_Z						0xff
#define KEY_BACKSLASH               0xff
#define KEY_SQUARE_OPEN             0xff
#define KEY_SQUARE_CLOSED           0xff
#define KEY_SEMICOMMA               0xff
#define KEY_QUOTE                   0xff
#define KEY_APIX                    0xff
#define KEY_DEAD                    0xff
#define KEY_SHIFT                   0xff
#define KEY_CTRL                    0xff
#define KEY_GRAPH                   0xff
#define KEY_CAPS                    0xff
#define KEY_CODE                    0xff
#define KEY_ESC                     0xff
#define KEY_TAB                     0xff
#define KEY_STOP                    0xff
#define KEY_BS                      0xff
#define KEY_SELECT                  0xff
#define KEY_RET                     0xff
#define KEY_INS                     0xff
#define KEY_DEL                     0xff
#define KEY_LEFT                    0xff
#define KEY_UP                      0xff
#define KEY_DOWN                    0xff
#define KEY_RIGHT                   0xff
#define KEY_DIVISION                0xff

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

#define BANK_COUNT          0
#define BANK_SIZE           0

#define MAX_AUDIO_CHANNELS  3

void coleco_inkey( Environment * _environment, char * _pressed, char * _key );
void coleco_scancode( Environment * _environment, char * _pressed, char * _scacode );
void coleco_scanshift( Environment * _environment, char * _shifts );
void coleco_keyshift( Environment * _environment, char * _shifts );
void coleco_key_pressed( Environment * _environment, char *_scancode, char * _result );
void coleco_clear_key( Environment * _environment );
void coleco_irq_at( Environment * _environment, char * _label );
void coleco_follow_irq( Environment * _environment );
void coleco_joy( Environment * _environment, int _port, char * _value );
void coleco_joy_vars( Environment * _environment, char * _port, char * _value );

void coleco_sys_call( Environment * _environment, int _destination );

#endif