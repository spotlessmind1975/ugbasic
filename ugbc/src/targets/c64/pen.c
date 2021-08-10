/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit code for <strong>PEN ...</strong> command
 * 
 * @param _environment Current calling environment
 * @param _color Color to use for the pen
 */
/* <usermanual>
@keyword PEN

@english
The ''PEN'' command sets the colour of the text displayed in the current
window, when followed by the colour index number of your choice. 
The default setting of the pen colour is index number ''DEFAULT PEN'', 
and alternative colours may be selected from one of up to ''PEN COLORS'' 
choices, depending on the current graphics mode.

@italian
Il comando "PEN" imposta il colore del testo visualizzato nella finestra 
corrente, quando seguito dal numero di indice del colore scelto. 
L'impostazione predefinita del colore della penna è il numero di indice
''DEFAULT PEN'', e colori alternativi possono essere selezionati 
da una delle scelte fino a "PEN COLORS", a seconda della modalità 
grafica corrente.

@syntax PEN [expression]

@example PEN 4
@example PEN (esempio)

@UsedInExample texts_options_01.bas
@UsedInExample texts_options_02.bas

@target all
</usermanual> */

void pen( Environment * _environment, char * _color ) {

    Variable * pen = variable_retrieve( _environment, "PEN" );
    Variable * color = variable_retrieve_or_define( _environment, _color, VT_COLOR, COLOR_BLACK );

    variable_move( _environment, color->name, pen->name );
    
}