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
 * "COSÌ COM'È", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

#if defined( __coco__ ) || defined(__coco3__ )

int key_constant( Environment * _environment, int _key ) {

    if (  !_environment->keyboardConfig.sync ) {
        return _key;
    } else {
        switch( _key ) {
            case KEY_0: return KEY2_0;
            case KEY_1: return KEY2_1;
            case KEY_2: return KEY2_2;
            case KEY_3: return KEY2_3;
            case KEY_4: return KEY2_4;
            case KEY_5: return KEY2_5;
            case KEY_6: return KEY2_6;
            case KEY_7: return KEY2_7;
            case KEY_8: return KEY2_8;
            case KEY_9: return KEY2_9;
            case KEY_A: return KEY2_A;
            // case KEY_ASTERISK: return KEY2_ASTERISK;
            // case KEY_AT: return KEY2_AT;
            case KEY_B: return KEY2_B;
            case KEY_C: return KEY2_C;
            // case KEY_CLEAR: return KEY2_CLEAR;
            case KEY_COLON: return KEY2_COLON;
            case KEY_COMMA: return KEY2_COMMA;
            // case KEY_CONTROL: return KEY2_CONTROL;
            case KEY_D: return KEY2_D;
            // case KEY_DELETE: return KEY2_DELETE;
            case KEY_DOWN: return KEY2_DOWN;
            case KEY_E: return KEY2_E;
            case KEY_F: return KEY2_F;
            case KEY_G: return KEY2_G;
            case KEY_H: return KEY2_H;
            // case KEY_HOME: return KEY2_HOME;
            case KEY_I: return KEY2_I;
            // case KEY_INSERT: return KEY2_INSERT;
            case KEY_J: return KEY2_J;
            case KEY_K: return KEY2_K;
            case KEY_L: return KEY2_L;
            case KEY_LEFT: return KEY2_LEFT;
            // case KEY_LEFT_SHIFT: return KEY2_LEFT_SHIFT;
            case KEY_M: return KEY2_M;
            case KEY_MINUS: return KEY2_MINUS;
            case KEY_N: return KEY2_N;
            case KEY_O: return KEY2_O;
            case KEY_P: return KEY2_P;
            case KEY_PERIOD: return KEY2_PERIOD;
            // case KEY_PLUS: return KEY2_PLUS;
            case KEY_Q: return KEY2_Q;
            case KEY_R: return KEY2_R;
            // case KEY_RETURN: return KEY2_RETURN;
            case KEY_RIGHT: return KEY2_RIGHT;
            // case KEY_RIGHT_SHIFT: return KEY2_RIGHT_SHIFT;
            case KEY_S: return KEY2_S;
            // case KEY_SEMICOLON: return KEY2_SEMICOLON;
            // case KEY_SLASH: return KEY2_SLASH;
            case KEY_SPACE: return KEY2_SPACE;
            case KEY_T: return KEY2_T;
            case KEY_U: return KEY2_U;
            case KEY_UP: return KEY2_UP;
            // case KEY_UP_ARROW: return KEY2_UP_ARROW;
            case KEY_V: return KEY2_V;
            case KEY_W: return KEY2_W;
            case KEY_X: return KEY2_X;
            case KEY_Y: return KEY2_Y;
            case KEY_Z: return KEY2_Z;
            // case KEY_BACKSLASH: return KEY2_BACKSLASH;
            // case KEY_SQUARE_OPEN: return KEY2_SQUARE_OPEN;
            // case KEY_SQUARE_CLOSED: return KEY2_SQUARE_CLOSED;
            case KEY_SEMICOMMA: return KEY2_SEMICOMMA;
            // case KEY_QUOTE: return KEY2_QUOTE;
            // case KEY_APIX: return KEY2_APIX;
            // case KEY_DEAD: return KEY2_DEAD;
            // case KEY_SHIFT: return KEY2_SHIFT;
            // case KEY_CTRL: return KEY2_CTRL;
            // case KEY_GRAPH: return KEY2_GRAPH;
            // case KEY_CAPS: return KEY2_CAPS;
            // case KEY_CODE: return KEY2_CODE;
            // case KEY_ESC: return KEY2_ESC;
            // case KEY_TAB: return KEY2_TAB;
            // case KEY_STOP: return KEY2_STOP;
            // case KEY_BS: return KEY2_BS;
            // case KEY_SELECT: return KEY2_SELECT;
            // case KEY_RET: return KEY2_RET;
            // case KEY_INS: return KEY2_INS;
            // case KEY_DEL: return KEY2_DEL;
            // case KEY_DIVISION: return KEY2_DIVISION;
        }
        return KEY_NONE;
    }
}

#endif


#if defined( __d32__ ) || defined(__d64__ )

int key_constant( Environment * _environment, int _key ) {

    if (  !_environment->keyboardConfig.sync ) {
        return _key;
    } else {
        switch( _key ) {
            case KEY_0: return KEY2_0;
            case KEY_1: return KEY2_1;
            case KEY_2: return KEY2_2;
            case KEY_3: return KEY2_3;
            case KEY_4: return KEY2_4;
            case KEY_5: return KEY2_5;
            case KEY_6: return KEY2_6;
            case KEY_7: return KEY2_7;
            case KEY_8: return KEY2_8;
            case KEY_9: return KEY2_9;
            case KEY_A: return KEY2_A;
            // case KEY_ASTERISK: return KEY2_ASTERISK;
            // case KEY_AT: return KEY2_AT;
            case KEY_B: return KEY2_B;
            case KEY_C: return KEY2_C;
            // case KEY_CLEAR: return KEY2_CLEAR;
            // case KEY_COLON: return KEY2_COLON;
            case KEY_COMMA: return KEY2_COMMA;
            // case KEY_CONTROL: return KEY2_CONTROL;
            case KEY_D: return KEY2_D;
            // case KEY_DELETE: return KEY2_DELETE;
            case KEY_DOWN: return KEY2_DOWN;
            case KEY_E: return KEY2_E;
            case KEY_F: return KEY2_F;
            case KEY_G: return KEY2_G;
            case KEY_H: return KEY2_H;
            // case KEY_HOME: return KEY2_HOME;
            case KEY_I: return KEY2_I;
            // case KEY_INSERT: return KEY2_INSERT;
            case KEY_J: return KEY2_J;
            case KEY_K: return KEY2_K;
            case KEY_L: return KEY2_L;
            case KEY_LEFT: return KEY2_LEFT;
            // case KEY_LEFT_SHIFT: return KEY2_LEFT_SHIFT;
            case KEY_M: return KEY2_M;
            case KEY_MINUS: return KEY2_MINUS;
            case KEY_N: return KEY2_N;
            case KEY_O: return KEY2_O;
            case KEY_P: return KEY2_P;
            //case KEY_PERIOD: return KEY2_PERIOD;
            // case KEY_PLUS: return KEY2_PLUS;
            case KEY_Q: return KEY2_Q;
            case KEY_R: return KEY2_R;
            // case KEY_RETURN: return KEY2_RETURN;
            case KEY_RIGHT: return KEY2_RIGHT;
            // case KEY_RIGHT_SHIFT: return KEY2_RIGHT_SHIFT;
            case KEY_S: return KEY2_S;
            // case KEY_SEMICOLON: return KEY2_SEMICOLON;
            // case KEY_SLASH: return KEY2_SLASH;
            case KEY_SPACE: return KEY2_SPACE;
            case KEY_T: return KEY2_T;
            case KEY_U: return KEY2_U;
            case KEY_UP: return KEY2_UP;
            // case KEY_UP_ARROW: return KEY2_UP_ARROW;
            case KEY_V: return KEY2_V;
            case KEY_W: return KEY2_W;
            case KEY_X: return KEY2_X;
            case KEY_Y: return KEY2_Y;
            case KEY_Z: return KEY2_Z;
            // case KEY_BACKSLASH: return KEY2_BACKSLASH;
            // case KEY_SQUARE_OPEN: return KEY2_SQUARE_OPEN;
            // case KEY_SQUARE_CLOSED: return KEY2_SQUARE_CLOSED;
            //case KEY_SEMICOMMA: return KEY2_SEMICOMMA;
            // case KEY_QUOTE: return KEY2_QUOTE;
            // case KEY_APIX: return KEY2_APIX;
            // case KEY_DEAD: return KEY2_DEAD;
            // case KEY_SHIFT: return KEY2_SHIFT;
            // case KEY_CTRL: return KEY2_CTRL;
            // case KEY_GRAPH: return KEY2_GRAPH;
            // case KEY_CAPS: return KEY2_CAPS;
            // case KEY_CODE: return KEY2_CODE;
            // case KEY_ESC: return KEY2_ESC;
            // case KEY_TAB: return KEY2_TAB;
            // case KEY_STOP: return KEY2_STOP;
            // case KEY_BS: return KEY2_BS;
            // case KEY_SELECT: return KEY2_SELECT;
            // case KEY_RET: return KEY2_RET;
            // case KEY_INS: return KEY2_INS;
            // case KEY_DEL: return KEY2_DEL;
            // case KEY_DIVISION: return KEY2_DIVISION;
        }
        return KEY_NONE;
    }
}

#endif
