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
 * @brief Emit code for <strong>LOCATE ...,...</strong>
 * 
 * @param _environment Current calling environment
 * @param _x Column to locate to
 * @param _y Row to locate to
 */
/* <usermanual>
@keyword LOCATE

@english
The ''LOCATE'' command moves the text cursor to specific coordinates, 
and this new location sets the start position for all subsequent 
text printing until commanded otherwise. 

All screen positions are measured in “text coordinates”, which are 
measured in units of one printed character on screen, with the 
x-coordinate controlling the horizontal position and the 
y-coordinate referring to the vertical. 

The top left-hand corner of the screen has coordinates of 0,0 
whereas text coordinates of 15,10 refer to a position 15 characters 
from the left-hand edge of the screen and 10 characters from the top.

The range of these coordinates will depend on the size of your character 
set and the dimensions of the display area allocated, known as a “window”. 

All coordinate measurements are taken using text coordinates relative to 
the current window. If you try and print something outside of these 
limits, an error will be generated or the screen will be automatically
scrolled down.

The current screen is automatically treated as a window, so there is no 
need to "open" one.

@italian
Il comando ''LOCATE'' sposta il cursore del testo su coordinate specifiche,
e questa nuova posizione definisce la posizione iniziale per tutti i successivi
comandi di stampa testo fino a quando non viene comandato diversamente.

Tutte le posizioni dello schermo sono misurate in "coordinate di testo", che sono
misurate in unità di un carattere stampato sullo schermo, con la coordinata x 
che controlla la posizione orizzontale e la coordinata y riferita alla
posizione verticale.

L'angolo in alto a sinistra dello schermo ha coordinate 0,0
mentre le coordinate di testo di 15,10 si riferiscono a una posizione di 15 caratteri
dal bordo sinistro dello schermo e 10 caratteri dall'alto.

L'intervallo di queste coordinate dipenderà dalle dimensioni del carattere
e le dimensioni dell'area di visualizzazione assegnata, denominata "finestra".

Tutte le misurazioni di coordinate vengono effettuate utilizzando le coordinate 
di  testo relative a la finestra corrente. Provare a stampare qualcosa al di fuori di questi
limiti verrà generato un errore o la schermata verrà automaticamente
fatta scorrere verso il basso.

La schermata corrente viene automaticamente trattata come una finestra, quindi non c'è
bisogno di "aprirne" una.

@syntax LOCATE {[x]},{[y]}

@example LOCATE 15,0
@example LOCATE ,20

@usedInExample texts_position_01.bas
@usedInExample texts_position_02.bas

@seeAlso AT$
@seeAlso CMOVE
@target all
</usermanual> */
void locate( Environment * _environment, char * _x, char * _y ) {

    if ( _x ) {
        Variable * windowCX = variable_retrieve( _environment, "XCURSYS" );
        Variable * x = variable_retrieve_or_define( _environment, _x, VT_BYTE, 0 );
        variable_move( _environment, x->name, windowCX->name );
    }

    if ( _y ) {
        Variable * windowCY = variable_retrieve( _environment, "YCURSYS" );
        Variable * y = variable_retrieve_or_define( _environment, _y, VT_BYTE, 0 );
        variable_move( _environment, y->name, windowCY->name );
    }

}
