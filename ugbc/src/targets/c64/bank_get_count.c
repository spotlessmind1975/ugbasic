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

#include "../../ugbc.h"

#if defined(__c64__)

/**
 * @brief Emit ASM code for instruction <b>= BANK COUNT</b>
 * 
 * This function outputs the ASM code to get the resident
 * memory number of banks.
 * 
 * @param _environment Current calling environment
 * @return Current number of banks present.
 */
/* <usermanual>
@keyword BANK COUNT (constant)

@english

This function returns the number of expanded memory banks available to the program. 
Depending on the target, this number can range from zero to the actual number of banks.

@italian

Questa funzione restituisce il numero di banchi di memoria espansa, disponibili per 
il programma. A seconda del target, questo numero può andare da zero al numero 
effettivo di banchi. 

@syntax = BANK COUNT

@example IF BANK COUNT > 0 THEN 
@example    PRINT "there are banks!"
@example ENDIF

@usedInExample expansion_bank_01.bas
@usedInExample expansion_bank_02.bas
@usedInExample expansion_bank_03.bas
@usedInExample expansion_bank_04.bas
@usedInExample expansion_bank_05.bas

@seeAlso BANK
@seeAlso BANK ADDRESS
@target all
</usermanual> */
Variable * bank_get_count( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_BYTE, "(bank count)" );

    int bankCount = 0;
    Bank * bank = _environment->expansionBanks;
    while( bank ) {
        ++bankCount;
        bank = bank->next;
    }

    variable_store( _environment, result->name, bankCount );

    return result;
    
}

#endif
