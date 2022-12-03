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
 * "COSÌ COM'È", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

Variable * joy_vars( Environment * _environment, char * _port ) {

    MAKE_LABEL

    Variable * port = variable_retrieve_or_define( _environment, _port, VT_BYTE, 0 );
    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of JOY)" );

// To read the joystick inputs, a VIC 20 program will firstly set the ports
// to input mode by setting the DDR to 0. Then the values of the switches can
// be read by the program. VIA #2 is also used for reading the keyboard. Setting
// the DDR can mess up the keyscan rather badly. So VIC 20 programs will make
// sure that they restore the DDR to the original condition.

    outline0("SEI" );
    // outline0("LDA #%11000011" );
    // outline0("STA $9113" );
    // outline0("LDA #%01111111" );
    // outline0("STA $9122" );
    outline0("LDA $9111" );
    outline0("ORA $9120" );
    outline0("EOR #$FF" );
    outline0("AND #%10111100" );
    outline1("STA %s", result->realName );
    // outline0("LDA #%11111111" );
    // outline0("STA $9122" );
    outline0("CLI" );

    return result;

}

Variable * joy( Environment * _environment, int _port ) {

    MAKE_LABEL

    Variable * result = variable_temporary( _environment, VT_BYTE, "(result of JOY)" );

// To read the joystick inputs, a VIC 20 program will firstly set the ports
// to input mode by setting the DDR to 0. Then the values of the switches can
// be read by the program. VIA #2 is also used for reading the keyboard. Setting
// the DDR can mess up the keyscan rather badly. So VIC 20 programs will make
// sure that they restore the DDR to the original condition.

    outline0("SEI" );
    // outline0("LDA #%11000011" );
    // outline0("STA $9113" );
    // outline0("LDA #%01111111" );
    // outline0("STA $9122" );
    outline0("LDA $9111" );
    outline0("ORA $9120" );
    outline0("EOR #$FF" );
    outline0("AND #%10111100" );
    outline1("STA %s", result->realName );
    // outline0("LDA #%11111111" );
    // outline0("STA $9122" );
    outline0("CLI" );

    return result;

}