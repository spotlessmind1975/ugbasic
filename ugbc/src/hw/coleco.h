#ifndef __UGBC_COLECO__
#define __UGBC_COLECO__

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

#define KEY_NONE					64
#define KEY_0						'0'
#define KEY_1						'1'
#define KEY_2						'2'
#define KEY_3						'3'
#define KEY_4						'4'
#define KEY_5						'5'
#define KEY_6						'6'
#define KEY_7						'7'
#define KEY_8						'8'
#define KEY_9						'9'
#define KEY_A						'A'
#define KEY_ASTERISK				'*'
#define KEY_AT						'@'
#define KEY_B						'B'
#define KEY_C						'C'
#define KEY_CLEAR					0xf9
#define KEY_COLON					':'
#define KEY_COMMA					','
#define KEY_COMMODORE				0x00
#define KEY_CONTROL					0x00
#define KEY_CRSR_LEFT_RIGHT			0x00
#define KEY_CRSR_UP_DOWN			0x00
#define KEY_D						'D'
#define KEY_DELETE					0x90
#define KEY_E						'E'
#define KEY_EQUAL					'='
#define KEY_F						'F'
#define KEY_F1						0x00
#define KEY_F2						0x00
#define KEY_F3						0x00
#define KEY_F4						0x00
#define KEY_F5						0x00
#define KEY_F6						0x00
#define KEY_F7						0x00
#define KEY_F8						0x00
#define KEY_G						'G'
#define KEY_H						'H'
#define KEY_HOME					0x88
#define KEY_I						'I'
#define KEY_INSERT					0x89
#define KEY_J						'J'
#define KEY_K						'K'
#define KEY_L						'L'
#define KEY_LEFT_ARROW				0x91
#define KEY_LEFT_SHIFT				0x81
#define KEY_M						'M'
#define KEY_MINUS					'-'
#define KEY_N						'N'
#define KEY_O						'O'
#define KEY_P						'P'
#define KEY_PERIOD					'.'
#define KEY_PLUS					'+'
#define KEY_POUND					0x00
#define KEY_Q						'Q'
#define KEY_R						'R'
#define KEY_RETURN					0x0d
#define KEY_RIGHT_SHIFT				0x81
#define KEY_RUNSTOP					0x86
#define KEY_S						'S'
#define KEY_SEMICOLON				';'
#define KEY_SLASH					'/'
#define KEY_SPACE					' '
#define KEY_T						'T'
#define KEY_U						'U'
#define KEY_UP_ARROW				0x92
#define KEY_V						'V'
#define KEY_W						'W'
#define KEY_X						'X'
#define KEY_Y						'Y'
#define KEY_Z						'Z'
#define KEY_BACKSLASH                '\\'
#define KEY_SQUARE_OPEN              0x00
#define KEY_SQUARE_CLOSED            0x00
#define KEY_SEMICOMMA                ';'
#define KEY_QUOTE                    '"'
#define KEY_APIX                     0x00
#define KEY_DEAD                     0x00
#define KEY_SHIFT                    0x81
#define KEY_CTRL                     0x82
#define KEY_GRAPH                    0x83
#define KEY_CAPS                     0x84
#define KEY_CODE                     0x85
#define KEY_ESC                      0x27
#define KEY_TAB                      0x09
#define KEY_STOP                     0x86
#define KEY_BS                       0x08
#define KEY_SELECT                   0x87
#define KEY_RET                      0x0d
#define KEY_INS                      0x89
#define KEY_DEL                      0x90
#define KEY_LEFT                     0x91
#define KEY_UP                       0x92
#define KEY_DOWN                     0x93
#define KEY_RIGHT                    0x94
#define KEY_DIVISION                 '/'

#define INPUT_DEFAULT_SEPARATOR     ','
#define INPUT_DEFAULT_SIZE          32
#define INPUT_DEFAULT_CURSOR        0x60

#define SCREEN_CAPABILITIES         ( ( 1<<TILEMAP_NATIVE ) | ( 1<<BITMAP_NATIVE ) )

#define JOY_COUNT           2

#define JOY_UP              0
#define JOY_DOWN            2
#define JOY_LEFT            3
#define JOY_RIGHT           1
#define JOY_FIRE            4

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
void coleco_joy( Environment * _environment, char * _port, char * _value );

#endif