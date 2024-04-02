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

#if defined(__atari__) || defined(__atarixl__) || defined(__c64__)

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
@keyword BANK COUNT

@english
This function returns the number of (expansion) banks available.
If the computer has more memory areas than the 
normally addressable one, this function returns the number of banks. 
Each bank is a Sharing space with a "window" of memory that starts at ''BANK ADDRESS 
(bank)'' and is ''BANK SIZE (bank)'' bytes long.

@italian
Questa funzione restituisce il numero di banchi (di espansione) disponibili. 
Se il computer ha più aree di memoria di quelle normalmente indirizzabili, questa 
funzione restituisce il numero di banchi. Ogni banco è uno spazio di condivisione con 
una "finestra" di memoria che inizia da "BANK ADDRESS" ed è lunga "BANK SIZE" in byte.

@syntax = BANK COUNT

@example IF BANK COUNT > 0 THEN 
@example    PRINT "there are banks!"
@example ENDIF

@usedInExample expansion_bank_01.bas
@usedInExample expansion_bank_02.bas
@usedInExample expansion_bank_03.bas
@usedInExample expansion_bank_04.bas
@usedInExample expansion_bank_05.bas

@target atari
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
