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
 * @brief Emit ASM code for <b>SCREEN TILES WIDTH</b> or <b>TILES WIDTH</b>
 * 
 * This function return the current screen width, in terms of tiles.
 * 
 * @param _environment Current calling environment
 * @return Variable* the current width
 */
/* <usermanual>
@keyword SCREEN TILES WIDTH

@english
This function allows you to obtain the width of the current screen, expressed in tiles. 
A tile is a box of pixels that can be addressed elementary by a specific screen code.
Normally, it is used in "text mode", since each box is a character. 
The width depends on the currently selected graphics mode, and it can change at runtime.

There is also a compile-level function for this keyword, which is called when the value 
is used to initialize a constant. In this case, the value is that taken from inspecting 
the instructions at the time of compilation.

It can also be abbreviated to the statement ''TILES WIDTH''.

@italian
Questa funzione permette di ottenere la larghezza dello schermo corrente, 
espressa in tile. Il tile è un box di pixel che può essere individuato in modo elementare,
per mezzo di uno specifico codice schermo. Normalmente, è usato nella "modalità testo",
dato che ogni box rappresenta un carattere. La larghezza dipende dall'attuale modalità grafica 
selezionata, e può cambiare in sede di esecuzione.

Di questa parola chiave esiste anche una funzione a livello di compilazione, 
che viene richiamata quando il valore viene utilizzato per inizializzare una 
costante. In tal caso, il valore è quello desunto dall'ispezione delle 
istruzioni al momento della compilazione.

Da notare che può essere abbreviato anche con l'istruzione ''TILES WIDTH''. 

@syntax = SCREEN TILES WIDTH

@example currentWidth = SCREEN TILES WIDTH

@target all
</usermanual> */
/* <usermanual>
@keyword TILES WIDTH

@english
Alias for ''SCREEN TILES WIDTH''.

@italian
Alias per ''SCREEN TILES WIDTH''.

@seeAlso SCREEN TILES WIDTH

@target all
</usermanual> */
Variable * screen_tiles_get_width( Environment * _environment ) {

    Variable * width = variable_temporary( _environment, VT_BYTE, "(result of get tiles width)");

    MAKE_LABEL
    
    vic2_tiles_get_width( _environment, width->realName );

    return width;

}
