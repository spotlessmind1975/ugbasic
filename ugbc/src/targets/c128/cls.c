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

#include "../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>CLS</strong>
 * 
 * @param _environment Current calling environment
 * @param _paper Color to use to clear the screen (NULL = default one)
 */
/* <usermanual>
@keyword CLS

@english

The ''CLS'' command is used to clear the screen and return the cursor to the
upper left corner. In other words, ''CLS'' clears the screen, eliminating 
everything that was previously printed. 

Before printing new data to the screen, it is often useful to use ''CLS'' to
have a clean and tidy space. In combination with other instructions, 
''CLS'' can be used to create simple animations by erasing and redrawing 
elements on the screen. It allows you to update the user interface without 
leaving traces of previous operations.

The CLS command is generally very fast to execute and can also be used 
in graphics mode to clear the entire drawing area. It also has
the ability to set a default background color, if possible. The clearing 
occurs with respect to the selected mode, so it will be a "pixel by pixel" 
clearing (if in bitmap mode) or "tile by tile" (if in tile mode). In the 
second case, the value of the ''EMPTYTILE'' variable will be used, 
possibly overridden

@italian

Il comando ''CLS'' viene utilizzato per cancellare lo schermo e riportare
il cursore nell'angolo in alto a sinistra. In altre parole, ''CLS'' cancella 
lo schermo, eliminando tutto ciò che era stato stampato in precedenza.

Prima di stampare nuovi dati sullo schermo, è spesso utile usare ''CLS'' 
per avere uno spazio pulito e ordinato. In combinazione con altre istruzioni, 
''CLS'' può essere utilizzato per creare semplici animazioni cancellando e 
ridisegnando elementi sullo schermo. Consente di aggiornare l'interfaccia 
utente senza lasciare tracce delle operazioni precedenti.

Il comando CLS è generalmente molto veloce da eseguire e può essere 
utilizzato anche in modalità grafica per cancellare l'intera area di 
disegno. Ha anche la possibilità di impostare un colore di sfondo predefinito, 
se possibile. La cancellazione avviene rispetto alla modalità selezionata, 
quindi sarà una cancellazione "pixel per pixel" (se in modalità bitmap) o 
"tile per tile" (se in modalità tile). Nel secondo caso, verrà utilizzato 
il valore della variabile ''EMPTYTILE'', eventualmente sovrascritto

@syntax CLS
@syntax CLS color

@example CLS
@example CLS WHITE

@usedInExample texts_position_01.bas
@usedInExample texts_position_02.bas

@target c128
</usermanual> */
void cls( Environment * _environment, char * _paper ) {

    if ( _paper ) {
        paper( _environment, _paper );
    }

    vic2_cls( _environment );
    
}

