#ifndef __UGBC_PIA__
#define __UGBC_PIA__

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

#if defined(__d32__) || defined(__d64__)

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

    #define KEYBOARD_CONFIG_DEFAULT_SYNC       1

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

#elif defined(__coco__)

    #define KEY_NONE				   255
    #define KEY_AT						 0
    #define KEY_H						 1
    #define KEY_P						 2
    #define KEY_X						 3
    #define KEY_0						 4
    #define KEY_8						 6
    #define KEY_RETURN					 7

    #define KEY_A 						 8
    #define KEY_I						 9
    #define KEY_Q						10
    #define KEY_Y						11
    #define KEY_1						12
    #define KEY_9    					13

    #define KEY_B 						16
    #define KEY_J						17
    #define KEY_R						18
    #define KEY_Z						19
    #define KEY_2    					20
    #define KEY_COLON 					21

    #define KEY_C 						24
    #define KEY_K						25
    #define KEY_S						26
    #define KEY_UP						27
    #define KEY_3						28
    #define KEY_SEMICOMMA				29

    #define KEY_D 						32
    #define KEY_L						33
    #define KEY_T						34
    #define KEY_DOWN					35
    #define KEY_4						36
    #define KEY_COMMA				    37

    #define KEY_E 						40
    #define KEY_M						41
    #define KEY_U						42
    #define KEY_BS  					43
    #define KEY_LEFT  					43
    #define KEY_5				        44
    #define KEY_MINUS   		        45

    #define KEY_F 						48
    #define KEY_N						49
    #define KEY_V						50
    #define KEY_RIGHT					51
    #define KEY_6				        52
    #define KEY_PERIOD			        53

    #define KEY_G 						56
    #define KEY_O						57
    #define KEY_W						58
    #define KEY_SPACE				    59
    #define KEY_7			            60
    #define KEY_SLASH			        61

    #define KEY_ASTERISK				 0
    #define KEY_CLEAR					 0
    #define KEY_COMMODORE				 0
    #define KEY_CONTROL					 0
    #define KEY_CRSR_LEFT_RIGHT			 0
    #define KEY_CRSR_UP_DOWN			 0
    #define KEY_EQUAL					 0
    #define KEY_F1					  	 0
    #define KEY_F2						 0
    #define KEY_F3					 	 0
    #define KEY_F4						 0
    #define KEY_F5						 0
    #define KEY_F6						 0
    #define KEY_F7						 0
    #define KEY_F8						 0
    #define KEY_HOME					 0
    #define KEY_INSERT					 0
    #define KEY_LEFT_ARROW				 0
    #define KEY_LEFT_SHIFT				 0
    #define KEY_PLUS					 0
    #define KEY_POUND				 	 0
    #define KEY_RIGHT_SHIFT				 0
    #define KEY_RUNSTOP					 0
    #define KEY_UP_ARROW				 0
    #define KEY_BACKSLASH                0
    #define KEY_SQUARE_OPEN              0
    #define KEY_SQUARE_CLOSED            0
    #define KEY_QUOTE                    0
    #define KEY_APIX                     0
    #define KEY_DEAD                     0
    #define KEY_SHIFT                    0
    #define KEY_CTRL                     0
    #define KEY_GRAPH                    0
    #define KEY_CAPS                     0
    #define KEY_CODE                     0
    #define KEY_ESC                      0
    #define KEY_TAB                      0
    #define KEY_STOP                     0
    #define KEY_SELECT                   0
    #define KEY_RET                      0
    #define KEY_INS                      0
    #define KEY_DEL                      0
    #define KEY_DIVISION                 0
    #define KEY_DELETE                   0
    #define KEY_SEMICOLON				 0

    #define KEYBOARD_CONFIG_DEFAULT_SYNC       1

    #define         JOY_COUNT           2
    #define JOYSTICK_0					0
    #define JOYSTICK_1					1
    #define JOYSTICK_COUNT				2

    #define JOY_UP              0
    #define JOY_DOWN            1
    #define JOY_LEFT            2
    #define JOY_RIGHT           3
    #define JOY_FIRE            5

    #define JOYSTICK_CONFIG_DEFAULT_SYNC      1

    #define INPUT_DEFAULT_SEPARATOR     ','
    #define INPUT_DEFAULT_SIZE          32
    #define INPUT_DEFAULT_CURSOR        32
    #define INPUT_DEFAULT_RATE          16

#elif defined(__coco3__)

    #define KEY_NONE				   255
    #define KEY_AT						 0
    #define KEY_H						 1
    #define KEY_P						 2
    #define KEY_X						 3
    #define KEY_0						 4
    #define KEY_8						 6
    #define KEY_RETURN					 7

    #define KEY_A 						 8
    #define KEY_I						 9
    #define KEY_Q						10
    #define KEY_Y						11
    #define KEY_1						12
    #define KEY_9    					13

    #define KEY_B 						16
    #define KEY_J						17
    #define KEY_R						18
    #define KEY_Z						19
    #define KEY_2    					20
    #define KEY_COLON 					21

    #define KEY_C 						24
    #define KEY_K						25
    #define KEY_S						26
    #define KEY_UP						27
    #define KEY_3						28
    #define KEY_SEMICOMMA				29

    #define KEY_D 						32
    #define KEY_L						33
    #define KEY_T						34
    #define KEY_DOWN					35
    #define KEY_4						36
    #define KEY_COMMA				    37

    #define KEY_E 						40
    #define KEY_M						41
    #define KEY_U						42
    #define KEY_BS  					43
    #define KEY_LEFT  					43
    #define KEY_5				        44
    #define KEY_MINUS   		        45

    #define KEY_F 						48
    #define KEY_N						49
    #define KEY_V						50
    #define KEY_RIGHT					51
    #define KEY_6				        52
    #define KEY_PERIOD			        53

    #define KEY_G 						56
    #define KEY_O						57
    #define KEY_W						58
    #define KEY_SPACE				    59
    #define KEY_7			            60
    #define KEY_SLASH			        61

    #define KEY_ASTERISK				 0
    #define KEY_CLEAR					 0
    #define KEY_COMMODORE				 0
    #define KEY_CONTROL					 0
    #define KEY_CRSR_LEFT_RIGHT			 0
    #define KEY_CRSR_UP_DOWN			 0
    #define KEY_EQUAL					 0
    #define KEY_F1					  	 0
    #define KEY_F2						 0
    #define KEY_F3					 	 0
    #define KEY_F4						 0
    #define KEY_F5						 0
    #define KEY_F6						 0
    #define KEY_F7						 0
    #define KEY_F8						 0
    #define KEY_HOME					 0
    #define KEY_INSERT					 0
    #define KEY_LEFT_ARROW				 0
    #define KEY_LEFT_SHIFT				 0
    #define KEY_PLUS					 0
    #define KEY_POUND				 	 0
    #define KEY_RIGHT_SHIFT				 0
    #define KEY_RUNSTOP					 0
    #define KEY_UP_ARROW				 0
    #define KEY_BACKSLASH                0
    #define KEY_SQUARE_OPEN              0
    #define KEY_SQUARE_CLOSED            0
    #define KEY_QUOTE                    0
    #define KEY_APIX                     0
    #define KEY_DEAD                     0
    #define KEY_SHIFT                    0
    #define KEY_CTRL                     0
    #define KEY_GRAPH                    0
    #define KEY_CAPS                     0
    #define KEY_CODE                     0
    #define KEY_ESC                      0
    #define KEY_TAB                      0
    #define KEY_STOP                     0
    #define KEY_SELECT                   0
    #define KEY_RET                      0
    #define KEY_INS                      0
    #define KEY_DEL                      0
    #define KEY_DIVISION                 0
    #define KEY_DELETE                   0
    #define KEY_SEMICOLON				 0

    #define KEYBOARD_CONFIG_DEFAULT_SYNC       1

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
    #define INPUT_DEFAULT_CURSOR        127
    #define INPUT_DEFAULT_RATE          16

#endif

#define KEY2_NONE				     0
#define KEY2_AT					    '@'
#define KEY2_H						'H'
#define KEY2_P						'P'
#define KEY2_X						'X'
#define KEY2_0						'0'
#define KEY2_8						'8'
#define KEY2_RETURN					 13

#define KEY2_A 						'A'
#define KEY2_I						'I'
#define KEY2_Q						'Q'
#define KEY2_Y						'Y'
#define KEY2_1						'1'
#define KEY2_9    					'9'

#define KEY2_B 						'8'
#define KEY2_J						'J'
#define KEY2_R						'R'
#define KEY2_Z						'Z'
#define KEY2_2    					'2'
#define KEY2_COLON 					','

#define KEY2_C 						'C'
#define KEY2_K						'K'
#define KEY2_S						'S'
#define KEY2_UP						0xfa
#define KEY2_3						'3'
#define KEY2_SEMICOMMA				';'

#define KEY2_D 						'D'
#define KEY2_L						'L'
#define KEY2_T						'T'
#define KEY2_DOWN					0xfb
#define KEY2_4						'4'
#define KEY2_COMMA				    ','

#define KEY2_E 						'E'
#define KEY2_M						'M'
#define KEY2_U						'U'
#define KEY2_BS  					0x08
#define KEY2_LEFT  					0xfc
#define KEY2_5				        '5'
#define KEY2_MINUS   		        '-'

#define KEY2_F 						'F'
#define KEY2_N						'N'
#define KEY2_V						'V'
#define KEY2_RIGHT					0xfd
#define KEY2_6				        '6'
#define KEY2_PERIOD			        '.'

#define KEY2_G 						'G'
#define KEY2_O						'O'
#define KEY2_W						'W'
#define KEY2_SPACE				    32
#define KEY2_7			            '7'
#define KEY2_SLASH			        '/'

#define KEY2_ASTERISK				'*'
#define KEY2_CLEAR					 0
#define KEY2_COMMODORE				 0
#define KEY2_CONTROL				 0
#define KEY2_CRSR_LEFT_RIGHT		 0
#define KEY2_CRSR_UP_DOWN			 0
#define KEY2_EQUAL					 0
#define KEY2_F1					  	 0
#define KEY2_F2						 0
#define KEY2_F3					 	 0
#define KEY2_F4						 0
#define KEY2_F5						 0
#define KEY2_F6						 0
#define KEY2_F7						 0
#define KEY2_F8						 0
#define KEY2_HOME					 0
#define KEY2_INSERT					 0
#define KEY2_LEFT_ARROW				 0
#define KEY2_LEFT_SHIFT				 0
#define KEY2_PLUS					 0
#define KEY2_POUND				 	 0
#define KEY2_RIGHT_SHIFT				 0
#define KEY2_RUNSTOP					 0
#define KEY2_UP_ARROW				 0
#define KEY2_BACKSLASH                0
#define KEY2_SQUARE_OPEN              0
#define KEY2_SQUARE_CLOSED            0
#define KEY2_QUOTE                    0
#define KEY2_APIX                     0
#define KEY2_DEAD                     0
#define KEY2_SHIFT                    0
#define KEY2_CTRL                     0
#define KEY2_GRAPH                    0
#define KEY2_CAPS                     0
#define KEY2_CODE                     0
#define KEY2_ESC                      0
#define KEY2_TAB                      0
#define KEY2_STOP                     0
#define KEY2_SELECT                   0
#define KEY2_RET                      0
#define KEY2_INS                      0
#define KEY2_DEL                      0
#define KEY2_DIVISION                 0
#define KEY2_DELETE                   0
#define KEY2_SEMICOLON				 0

#define JOYSTICK_CONFIG_DEFAULT_SYNC      1

void pia_wait_key( Environment * _environment, int _release );
void pia_wait_fire( Environment * _environment, int _port, int _release );
void pia_wait_fire_semivar( Environment * _environment, char * _port, int _release );
void pia_wait_key_or_fire( Environment * _environment, int _port, int _release );
void pia_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release );
void pia_key_state( Environment * _environment, char *_scancode, char * _result );
void pia_scancode( Environment * _environment, char * _scacode );
void pia_asciicode( Environment * _environment, char * _asciicode );
void pia_inkey( Environment * _environment, char * _key );
void pia_key_pressed( Environment * _environment, char *_scancode, char * _result );

void pia_scanshift( Environment * _environment, char * _shifts );
void pia_keyshift( Environment * _environment, char * _shifts );
void pia_clear_key( Environment * _environment );
void pia_put_key(  Environment * _environment, char *_string, char * _size );

#endif
