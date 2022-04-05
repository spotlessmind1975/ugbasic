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
The ''CLS'' command clears the screen, setting it (possibly) to a given background color. 
The clearing occurs with respect to the selected mode, so it will be a "pixel by pixel" 
clearing (if in bitmap mode) or "tile by tile" (if in tile mode). In the second case, the 
value of the ''EMPTYTILE'' variable will be used, possibly overridden.

@italian
Il comando ''CLS'' cancella lo schermo, impostandolo (eventualmente) a un dato colore
di sfondo. La cancellazione avviene rispetto alla modalità selezionata, quindi sarà una 
cancellazione "pixel per pixel" (se in modalità bitmap) oppure "tile per tile" (se in 
modalità tile). Nel secondo caso, sarà utilizzato il valore della variabile ''EMPTYTILE'', 
eventualmente prevalorizzato.

@syntax CLS
@syntax CLS [color]

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

