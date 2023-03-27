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

    outline0("LD HL, (SC3000TIMER)");
    outline0("LD DE, HL");
    outhead1("%s:", label);
    outline0("LD HL, (SC3000TIMER)");
    outline0("SBC HL, DE");
    outline0("INC HL");
    outline0("LD A, H");
    outline1("CP $%2.2x", (_timing >> 8) );
    outline1("JR Z, %s1", label );
    outline1("JR C, %s", label );
    outhead1("%s1:", label);
    outline0("LD A, L");
    outline1("CP $%2.2x", (_timing & 0xff) );
    outline1("JR Z, %s2", label );
    outline1("JR C, %s", label );
    outhead1("%s2:", label);

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

    Variable * timing = variable_retrieve( _environment, _timing );
    
    outline0("LD HL, (SC3000TIMER)");
    outline0("LD DE, HL");
    outhead1("%s:", label);
    outline0("LD HL, (SC3000TIMER)");
    outline0("SBC HL, DE");
    outline0("INC HL");
    outline1("LD A, (%s+1)", timing->realName);
    outline0("LD B, A");
    outline0("LD A, H");
    outline0("CP B" );
    outline1("JR Z, %s1", label );
    outline1("JR C, %s", label );
    outhead1("%s1:", label);
    outline1("LD A, (%s)", timing->realName);
    outline0("LD B, A");
    outline0("LD A, L");
    outline0("CP B" );
    outline1("JR Z, %s2", label );
    outline1("JR C, %s", label );
    outhead1("%s2:", label);

}
