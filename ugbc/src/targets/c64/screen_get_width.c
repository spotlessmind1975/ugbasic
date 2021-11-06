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
 * @brief Emit ASM code for <b>SCREEN WIDTH</b> or <b>WIDTH</b>
 * 
 * This function return the current screen width, in terms of pixels.
 * 
 * @param _environment Current calling environment
 * @return Variable* the current width
 */
/* <usermanual>
@keyword SCREEN WIDTH

@english
This function allows you to obtain the width of the current screen, expressed in pixels. 
The width depends on the currently selected graphics mode, and can change at runtime.

There is also a compile-level function for this keyword, which is called when the value 
is used to initialize a constant. In this case, the value is that taken from inspecting 
the instructions at the time of compilation.

It can also be abbreviated to the statement ''WIDTH''.

@italian
Questa funzione permette di ottenere la larghezza dello schermo corrente, 
espressa in pixel. La larghezza dipende dall'attuale modalità grafica 
selezionata, e può cambiare in sede di esecuzione.

Di questa parola chiave esiste anche una funzione a livello di compilazione, 
che viene richiamata quando il valore viene utilizzato per inizializzare una 
costante. In tal caso, il valore è quello desunto dall'ispezione delle 
istruzioni al momento della compilazione.

Da notare che può essere abbreviato anche con l'istruzione ''WIDTH''. 

@syntax = SCREEN WIDTH

@example currentWidth = SCREEN WIDTH

@usedInExample graphics_plot_01.bas
@usedInExample graphics_plot_02.bas
@usedInExample graphics_plot_03.bas

@target all
</usermanual> */
/* <usermanual>
@keyword WIDTH

@english
Alias for ''SCREEN WIDTH''.

@italian
Alias per ''SCREEN WIDTH''.

@seeAlso SCREEN WIDTH

@target all
</usermanual> */
Variable * screen_get_width( Environment * _environment ) {

    Variable * width = variable_temporary( _environment, VT_POSITION, "(result of get width)");

    MAKE_LABEL
    
    vic2_get_width( _environment, width->realName );

    return width;

}
