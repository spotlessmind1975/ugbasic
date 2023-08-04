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

/**
 * @brief Emit ASM code for <b>WAIT # [integer] TICKS</b>
 * 
 * This function outputs a code that engages the CPU in a busy wait.
 * 
 * @param _environment Current calling environment
 * @param _timing Number of cycles to wait
 */
void wait_ticks( Environment * _environment, int _timing ) {

    MAKE_LABEL

    outline1("LD HL, $%4.4x", _timing);
    outhead1("%srepeat:", label);
    outline0("LD A, 0");
    outline0("LD BC, $DC08");
    outline0("OUT (C), A");
    outline0("IN A, (C)");
    outhead1("%s:", label);
    outline0("IN A, (C)");
    outline0("CP 1");
    outline1("JR C, %s", label);
    outline0("DEC HL");
    outline0("LD A, L");
    outline0("OR H");
    outline1("JR NZ, %srepeat", label);

}

/**
 * @brief Emit ASM code for <b>WAIT [expression] TICKS</b>
 * 
 * This function outputs a code that engages the CPU in a busy wait.
 * 
 * @param _environment Current calling environment
 * @param _timing Number of cycles to wait
 */
void wait_ticks_var( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    Variable * timing = variable_retrieve_or_define( _environment, _timing, VT_WORD, 0 );
    
    outline1("LD HL, (%s)", timing->realName);
    outhead1("%srepeat:", label);
    outline0("LD A, 0");
    outline0("LD BC, $DC08");
    outline0("OUT (C), A");
    outline0("IN A, (C)");
    outhead1("%s:", label);
    outline0("IN A, (C)");
    outline0("CP 1");
    outline1("JR C, %s", label);
    outline0("DEC HL");
    outline0("LD A, L");
    outline0("OR H");
    outline1("JR NZ, %srepeat", label);

}
