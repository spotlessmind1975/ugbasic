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

#if defined(__atari__) || defined(__atarixl__) || defined(__c64__) || defined(__c128__) || defined(__plus4__) || defined(__vic20__) || defined(__c16__)

/**
 * @brief Emit ASM code for instruction <b>BANK ...</b>
 * 
 * This function outputs the ASM code to set the current 
 * expansion bank index.
 * 
 * @param _environment Current calling environment
 * @param _bank Bank to select
 */
/* <usermanual>
@keyword BANK

@english

The ''BANK'' command allows you to change the currently selected bank. All 
operations that are performed on the banks, and that do not explicitly indicate 
the bank to operate on, work with the implicit bank, which is set by this command. 
The minimum bank number is zero (''0'') while the maximum is equal to ''BANK COUNT - 1''.

@italian

Il comando ''BANK'' permette di modificare il banco selezionato attualmente. Tutte
le operazioni che si svolgono sui banchi, e che non indicano espressamente il banco 
su cui operare, lavorano con il banco implicito, che viene impostato da questo comando.
Il numero minimo del banco è zero (''0'') mentre il massimo è pari a ''BANK COUNT - 1''.

@syntax BANK id

@example BANK #1

@seeAlso BANK COUNT (constant)
@target all
</usermanual> */
void bank_set( Environment * _environment, int _bank ) {

    variable_store( _environment, "GEORAMBANKSHADOW", _bank );
    
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
    
    variable_move( _environment, _bank, "GEORAMBANKSHADOW" );

}

#endif