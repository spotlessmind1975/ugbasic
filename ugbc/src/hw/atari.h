#ifndef __UGBC_ATARI__
#define __UGBC_ATARI__

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

#define         JOY_COUNT           4
#define JOYSTICK_0					0
#define JOYSTICK_1					1
#define JOYSTICK_2					2
#define JOYSTICK_3					3
#define JOYSTICK_COUNT				4

#define JOY_UP              1
#define JOY_DOWN            2
#define JOY_LEFT            3
#define JOY_RIGHT           4
#define JOY_FIRE            0

#define KEY_NONE						255
#define KEY_L						0
#define KEY_J						1
#define KEY_SEMICOMMA				2
#define KEY_K						5
#define KEY_PLUS						6
#define KEY_ASTERISK					7
#define KEY_O						8
#define KEY_P						10
#define KEY_U						11
#define KEY_RETURN					12
#define KEY_I						13
#define KEY_MINUS					14
#define KEY_EQUAL					15
#define KEY_V						16
#define KEY_C						18
#define KEY_B						21
#define KEY_X						22
#define KEY_Z						23
#define KEY_4						24
#define KEY_3						26
#define KEY_6						27
#define KEY_ESC						28
#define KEY_5						29
#define KEY_2						30
#define KEY_1						31
#define KEY_COMMA					32
#define KEY_SPACE					33
#define KEY_PERIOD					31
#define KEY_N						35
#define KEY_M						37
#define KEY_SLASH					38
#define KEY_INV						39
#define KEY_R						40
#define KEY_E						42
#define KEY_Y						43
#define KEY_TAB						44
#define KEY_T						45
#define KEY_W						46
#define KEY_Q						47
#define KEY_9						48
#define KEY_0						50
#define KEY_7						51
#define KEY_DEL						52
#define KEY_8						53
#define KEY_LESS_THAN				54
#define KEY_GREATER_THAN				55
#define KEY_F						56
#define KEY_H						57
#define KEY_D						58
#define KEY_CAP						60
#define KEY_G						61
#define KEY_S						62
#define KEY_A						63
#define KEY_F1						0 // ?
#define KEY_F2						0 // ?
#define KEY_F3						0 // ?
#define KEY_F4						0 // ?
#define KEY_F5						0 // ?
#define KEY_F6						0 // ?
#define KEY_F7						0 // ?
#define KEY_F8						0 // ?
#define KEY_AT						0 // ?
#define KEY_CLEAR                   0 // ?
#define KEY_COLON                   0 // ?
#define KEY_COMMODORE               0 // ?
#define KEY_CONTROL                 0 // ?
#define KEY_CRSR_LEFT_RIGHT         0 // ?
#define KEY_CRSR_UP_DOWN            0 // ?
#define KEY_DELETE                  0 // ?
#define KEY_HOME                    0 // ?
#define KEY_INSERT                  0 // ?
#define KEY_LEFT_ARROW              0 // ?
#define KEY_UP_ARROW                0 // ?
#define KEY_POUND                   0 // ?
#define KEY_RUNSTOP                 0 // ?
#define KEY_SEMICOLON               0 // ?

#define INPUT_DEFAULT_SEPARATOR     ','
#define INPUT_DEFAULT_SIZE          32
#define INPUT_DEFAULT_CURSOR        0x0a

#define SCREEN_CAPABILITIES         ( ( 1<<TILEMAP_NATIVE ) | ( 1<<BITMAP_NATIVE ) )

#define BANK_COUNT          0
#define BANK_SIZE           0

void atari_xpen( Environment * _environment, char * _destination );
void atari_ypen( Environment * _environment, char * _destination );
void atari_inkey( Environment * _environment, char * _pressed, char * _key );
void atari_scancode( Environment * _environment, char * _pressed, char * _scacode );
void atari_key_pressed( Environment * _environment, char *_scancode, char * _result );
void atari_scanshift( Environment * _environment, char * _shifts );
void atari_keyshift( Environment * _environment, char * _shifts );
void atari_clear_key( Environment * _environment );

#endif