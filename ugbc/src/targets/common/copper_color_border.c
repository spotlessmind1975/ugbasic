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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>BEGIN COPPER</strong>
 * 
 * @param _environment Current calling environment
 */

 /* <usermanual>
@keyword COPPER COLOR BORDER

@english

The ''COPPER COLOR BORDER'' command is a fundamental instruction used 
in copper lists to dynamically change the color of the screen border, 
where present. The copper list is a sequence of instructions executed 
synchronized with the raster stream (the monitor's horizontal scanning 
of the screen line).

When a ''COPPER COLOR BORDER'' instruction is encountered in the copper 
list, the processor directly writes the color value to the hardware 
border color register of the target graphics chip (which will vary 
depending on the target computer). This color change occurs 
instantaneously and with pixel-level precision, based on the position 
of the raster beam on the screen at the time the instruction is 
executed.

@italian

Il comando ''COPPER COLOR BORDER'' è un'istruzione fondamentale 
utilizzata nelle copper list per modificare dinamicamente il colore 
del bordo dello schermo, laddove sia presente. La copper list è una 
sequenza di istruzioni eseguite in modo sincronizzato con il flusso del 
raster (la scansione orizzontale della linea dello schermo da parte 
del monitor).

Quando un'istruzione ''COPPER COLOR BORDER'' viene incontrata nella 
copper list, il processore scrive direttamente il valore del colore 
nel registro hardware del colore del bordo del chip grafico di 
riferimento (che sarà diverso a seconda del computer target). Questo 
cambiamento di colore avviene istantaneamente e con una precisione al 
singolo pixel, in base alla posizione del raster beam sullo schermo nel 
momento in cui l'istruzione viene eseguita.

@syntax BEGIN COPPER
@syntax    COPPER WAIT LINE 10
@syntax    COPPER COLOR BORDER RED
@syntax    COPPER WAIT LINE 30
@syntax    COPPER COLOR BORDER BLUE
@syntax END COPPER

@seeAlso BEGIN COPPER...END COPPER

</usermanual> */

void copper_color_border( Environment * _environment, int _color ) {

    if ( !_environment->insideCopperList ) {
        CRITICAL_COPPER_LIST_NOT_OPENED();
    }

    CopperInstruction * color = malloc( sizeof( CopperInstruction ) );
    memset( color, 0, sizeof( CopperInstruction ) );

    color->operation = COP_COLOR_BORDER;
    color->param1 = _color;

    if ( _environment->copperList->first ) {
        CopperInstruction * actual = _environment->copperList->first;
        while( actual->next ) {
            actual = actual->next;
        }
        actual->next = color;
    } else {
        _environment->copperList->first = color;
    }

}
