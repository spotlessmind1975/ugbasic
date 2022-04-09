#ifndef __UGBC_C128__
#define __UGBC_C128__

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

#define         JOY_COUNT           2

#define KEY_NONE					64
#define KEY_0						35
#define KEY_1						56
#define KEY_2						59
#define KEY_3						8
#define KEY_4						11
#define KEY_5						16
#define KEY_6						19
#define KEY_7						24
#define KEY_8						27
#define KEY_9						32
#define KEY_A						10
#define KEY_ASTERISK				49
#define KEY_AT						46
#define KEY_B						28
#define KEY_C						20
#define KEY_CLEAR					51
#define KEY_COLON					45
#define KEY_COMMA					47
#define KEY_COMMODORE				61
#define KEY_CONTROL					58
#define KEY_CRSR_LEFT_RIGHT			2
#define KEY_CRSR_UP_DOWN			7
#define KEY_D						18
#define KEY_DELETE					0
#define KEY_E						14
#define KEY_EQUAL					53
#define KEY_F						21
#define KEY_F1						4
#define KEY_F2						4
#define KEY_F3						5
#define KEY_F4						5
#define KEY_F5						6
#define KEY_F6						6
#define KEY_F7						3
#define KEY_F8						3
#define KEY_G						26
#define KEY_H						29
#define KEY_HOME					51
#define KEY_I						33
#define KEY_INSERT					0
#define KEY_J						34
#define KEY_K						37
#define KEY_L						42
#define KEY_LEFT_ARROW				57
#define KEY_LEFT_SHIFT				15
#define KEY_M						36
#define KEY_MINUS					43
#define KEY_N						39
#define KEY_O						38
#define KEY_P						41
#define KEY_PERIOD					44
#define KEY_PLUS					40
#define KEY_POUND					48
#define KEY_Q						62
#define KEY_R						17
#define KEY_RETURN					1
#define KEY_RIGHT_SHIFT				52
#define KEY_RUNSTOP					63
#define KEY_S						13
#define KEY_SEMICOLON				50
#define KEY_SLASH					55
#define KEY_SPACE					60
#define KEY_T						22
#define KEY_U						30
#define KEY_UP_ARROW				54
#define KEY_V						31
#define KEY_W						9
#define KEY_X						23
#define KEY_Y						25
#define KEY_Z						12
#define KEY_UP  					0
#define KEY_DOWN  					0
#define KEY_LEFT					0
#define KEY_RIGHT					0

#define INPUT_DEFAULT_SEPARATOR     ','
#define INPUT_DEFAULT_SIZE          32
#define INPUT_DEFAULT_CURSOR        185

#define SCREEN_CAPABILITIES         ( ( 1<<TILEMAP_NATIVE ) | ( 1<<BITMAP_NATIVE ) )

#define JOY_UP              0
#define JOY_DOWN            1
#define JOY_LEFT            2
#define JOY_RIGHT           3
#define JOY_FIRE            4

#define BANK_COUNT          0
#define BANK_SIZE           0

#define MAX_AUDIO_CHANNELS  3

void c128_xpen( Environment * _environment, char * _destination );
void c128_ypen( Environment * _environment, char * _destination );
void c128_inkey( Environment * _environment, char * _pressed, char * _key );
void c128_scancode( Environment * _environment, char * _pressed, char * _scacode );
void c128_key_pressed( Environment * _environment, char *_scancode, char * _result );
void c128_scanshift( Environment * _environment, char * _shifts );
void c128_keyshift( Environment * _environment, char * _shifts );
void c128_clear_key( Environment * _environment );

#endif