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

#if defined(__coco__) || defined(__coco3__) || defined(__d32__) || defined(__d64__) || \
    defined(__cocob__) || defined(__coco3b__) || defined(__d32b__) || defined(__d64b__)

Variable * joy_vars( Environment * _environment, char * _port ) {

    MAKE_LABEL

    deploy( joystick, src_hw_pia_joystick_asm );

    Variable * port = variable_retrieve_or_define( _environment, _port, VT_BYTE, 0 );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of JOY)" );

    outline1("LDA %s", port->realName);
    outline1("BNE %spt1", label );
    if ( _environment->joystickConfig.sync ) {
        outline0("JSR JOYSTICKREAD0");
    } else {
        outline0("LDA JOYSTICK0");
    }
    if ( _environment->joystickConfig.values ) {
        outline0("JSR JOYSTICKTSB" );
    }
    outline1("STA %s", result->realName);
    outline1("JMP %sptx", label);
    outhead1("%spt1", label);
    if ( _environment->joystickConfig.sync ) {
        outline0("JSR JOYSTICKREAD1");
    } else {
        outline0("LDA JOYSTICK1");
    }
    if ( _environment->joystickConfig.values ) {
        outline0("JSR JOYSTICKTSB" );
    }
    outline1("STA %s", result->realName);
    outhead1("%sptx", label);

    return result;

}

Variable * joy( Environment * _environment, int _port ) {

    MAKE_LABEL

    deploy( joystick, src_hw_pia_joystick_asm );

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of JOY)" );

    switch( _port ) {
        case 0:
            if ( _environment->joystickConfig.sync ) {
                outline0("JSR JOYSTICKREAD0");
            } else {
                outline0("LDA JOYSTICK0");
            }
            if ( _environment->joystickConfig.values ) {
                outline0("JSR JOYSTICKTSB" );
            }            
            outline1("STA %s", result->realName);
            break;
        case 1:
            if ( _environment->joystickConfig.sync ) {
                outline0("JSR JOYSTICKREAD1");
            } else {
                outline0("LDA JOYSTICK1");
            }
            if ( _environment->joystickConfig.values ) {
                outline0("JSR JOYSTICKTSB" );
            }            
            outline1("STA %s", result->realName);
            break;
    }

    return result;

}

#endif
