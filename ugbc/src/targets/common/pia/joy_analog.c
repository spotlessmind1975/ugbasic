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

#if defined(__coco__) || defined(__coco3__) || defined(__d32__) || defined(__d64__)

Variable * joyx_vars( Environment * _environment, char * _port ) {

    MAKE_LABEL

    deploy( joystick, src_hw_pia_joystick_asm );

    Variable * port = variable_retrieve_or_define( _environment, _port, VT_BYTE, 0 );
    Variable * result = variable_temporary( _environment, VT_SBYTE, "(result of JOY)" );

    outline1("LDB %s", port->realName);
    outline0("STB <PORT");
    outline0("JSR JOYX");
    outline0("SUBA #31");
    outline1("STA %s", result->realName);

    return result;
    
}

Variable * joyx( Environment * _environment, int _port ) {

    MAKE_LABEL

    deploy( joystick, src_hw_pia_joystick_asm );

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(result of JOY)" );

    outline1("LDB #$%2.2x", _port);
    outline0("STB <PORT");
    outline0("JSR JOYX");
    outline0("SUBA #31");
    outline1("STA %s", result->realName);

    return result;
    
}

Variable * joyy_vars( Environment * _environment, char * _port ) {

    MAKE_LABEL

    deploy( joystick, src_hw_pia_joystick_asm );

    Variable * port = variable_retrieve_or_define( _environment, _port, VT_BYTE, 0 );
    Variable * result = variable_temporary( _environment, VT_SBYTE, "(result of JOY)" );

    outline1("LDB %s", port->realName);
    outline0("STB <PORT");
    outline0("JSR JOYY");
    outline0("SUBA #31");
    outline1("STA %s", result->realName);

    return result;
    
}

Variable * joyy( Environment * _environment, int _port ) {

    MAKE_LABEL

    deploy( joystick, src_hw_pia_joystick_asm );

    Variable * result = variable_temporary( _environment, VT_SBYTE, "(result of JOY)" );

    outline1("LDB #$%2.2x", _port);
    outline0("STB <PORT");
    outline0("JSR JOYY");
    outline0("SUBA #31");
    outline1("STA %s", result->realName);
    
    return result;
    
}

#endif

