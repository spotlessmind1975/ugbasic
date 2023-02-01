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
 * @brief Emit code for <strong>SET TAB ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _new_tab New tab count value
 */
/* <usermanual>
@keyword SET TAB

@english
The ''SET TAB'' command specifies the number of characters 
that the text cursor will move to the right when the next 
TAB$ is printed.

@italian
Il comando ''SET TAB'' specifica il numero di caratteri che
il cursore di testo sposterà a destra quando verrà stampato 
il successivo TAB $.

@syntax SET TAB [expression]

@example SET TAB 10

@usedInExample texts_position_08.bas

@target all
</usermanual> */
void text_set_tab( Environment * _environment, char * _new_tab ) {

    Variable * tab = variable_retrieve( _environment, "TABCOUNT" );
    Variable * new_tab = variable_retrieve_or_define( _environment, _new_tab, VT_BYTE, 4 );

    variable_move( _environment, new_tab->name, tab->name );
    
}
