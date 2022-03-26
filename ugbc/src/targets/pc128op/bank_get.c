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
@keyword BANK

@english
This function returns the index of the currently used (expansion) bank.
In other words, if the computer has more memory areas than the 
normally addressable one, this function returns the one that is 
currently visible in the sharing space. 

Sharing space is a "window" of memory that starts at ''BANK ADDRESS 
(bank)'' and is ''BANK SIZE (bank)'' bytes long.

@italian
Questa funzione restituisce l'indice del banco (di espansione) 
attualmente utilizzato. In altri termini, se il computer dispone 
di più zone di memoria oltre quella normalmente indirizzabile, 
questa funzione restituisce quella che al momento è visibile 
nello spazio di condivisione. 

Lo spazio di condivisione è una "finestra" di memoria che inizia 
da ''BANK ADDRESS(bank)'' ed è lunga ''BANK SIZE(bank)'' bytes.

@syntax = BANK()

@example = BANK()

@target pc128op
</usermanual> */
Variable * bank_get( Environment * _environment ) {

    Variable * result = variable_temporary( _environment, VT_BYTE, "(bank number)" );

    outline0("LDA BANKSHADOW" );
    outline1("STA %s", result->realName );

    return result;
    
}
