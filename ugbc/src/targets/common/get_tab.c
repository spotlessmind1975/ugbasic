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
 * @brief Emit code for <strong>TAB$</strong>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword TAB$

@english
The ''TAB$'' function returns a special control character called ''TAB'', 
which carries the ASCII code of ''9''. When this character is printed, 
the text cursor is automatically moved to the next tabulated column 
setting (tab) to the right. The default setting for this is four
characters, which can be changed using ''[[SET TAB]]''. 


@italian
La funzione ''TAB$'' restituisce un carattere di controllo speciale 
chiamato "TAB", che contiene il codice ASCII 9. Quando questo carattere
viene stampato, il cursore del testo viene automaticamente spostato 
alla successiva impostazione della colonna tabulata (tabulazione) 
a destra. L'impostazione predefinita per questo è di quattro caratteri,
che può essere modificata utilizzando il comando ''[[SET TAB]]''.

@syntax = TAB$

@example PRINT TAB$

@usedInExample texts_position_08.bas

@target all
</usermanual> */
Variable * get_tab( Environment * _environment ) {
    
    Variable * tab = variable_retrieve( _environment, "TAB" );

    return tab;

}
