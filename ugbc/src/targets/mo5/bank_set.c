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

#include "../../ugbc.h"

/**
 * @brief Emit ASM code for instruction <b>BANK ...</b>
 * 
 * This function outputs the ASM code to set the current 
 * expansion bank index.
 * 
 * @param _environment Current calling environment
 * @param _bank Bank to select
 */
void bank_set( Environment * _environment, int _bank ) {

    int realBank = 0;
    if ( _bank < 32 && _bank > 0 ) {
        // Then bits b6 b5 b4 b1 b0 at $A7CB 
        // allows selecting one 16k bank out of 32.
        realBank = ( ( _bank & 0xfc ) << 2 ) | ( _bank & 0x03 );
        // but beware that to get access to it at $B000-$EFFF 
        // (basic-rom space), you should set b2 of $A7CB 
        // (and b3 to allow writing onto it).
        realBank = realBank | 0x0c;
    } else {
        realBank = 0x00;
    }
    outline1("LDA #$%2.2x", realBank  );
    // outline0("STA BANKSHADOW" );
    outline0("STA $A7CB" );
    
}

/**
 * @brief Emit ASM code for instruction <b>BANK ...</b>
 * 
 * This function outputs the ASM code to set the current 
 * expansion bank index.
 * 
 * @param _environment Current calling environment
 * @param _bank Bank to select
 */
void bank_set_var( Environment * _environment, char * _bank ) {

    Variable * bank = variable_retrieve_or_define( _environment, _bank, VT_BYTE, 0 );

    MAKE_LABEL

    char doneLabel[MAX_TEMPORARY_STORAGE]; sprintf( doneLabel, "%sdone", label );

    outline1("LDA %s", bank->realName  );
    outline1("BLT %s", label  );
    outline0("CMPA #31"  );
    outline1("BGT %s", label  );
    // outline0("STA BANKSHADOW" );
    outline0("ANDA #$FC"  );
    outline0("LSLA"  );
    outline0("LSLA"  );
    outline1("LDB %s", bank->realName  );
    outline0("ANDB #$03"  );
    outline0("ORB #$0C"  );
    outline0("STA <MATHPTR0" );
    outline0("ORB <MATHPTR0" );
    outline0("STB <MATHPTR0" );
    outline0("LDB <MATHPTR0" );
    outline0("STB $A7CB" );
    outline1("JMP %s", doneLabel );
    outhead1("%s", label );
    outline0("LDA #$00" );
    outline0("STA $A7CB" );
    
}
