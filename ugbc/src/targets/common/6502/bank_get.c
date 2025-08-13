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

#if defined(__atari__) || defined(__atarixl__) || defined(__c64__) || defined(__c128__) || defined(__plus4__) || defined(__vic20__) || defined(__c16__)

/**
 * @brief Emit ASM code for instruction <b>= BANK( )</b>
 * 
 * This function outputs the ASM code to get the current 
 * expansion bank index.
 * 
 * @param _environment Current calling environment
 * @return Current number of the bank selected
 */
/* <usermanual>
@keyword BANK (function)

@english

The ''BANK'' function allows you to know the currently selected bank. All 
operations that are performed on the banks, and that do not explicitly indicate 
the bank to operate on, work with this implicit bank. 

@italian

La funzione ''BANK'' consente di conoscere il banco di memoria attualmente 
selezionato. Tutte le operazioni che vengono eseguite sui banchi e che non 
indicano esplicitamente la banca su cui operare, funzionano con questo banco 
implicito.

@syntax = BANK()

@example x = BANK()

@seeAlso BANK
@target all
</usermanual> */
Variable * bank_get( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_BYTE, "(bank number)" );

    variable_store( _environment, result->name, 0 );

    return result;
    
}

#endif