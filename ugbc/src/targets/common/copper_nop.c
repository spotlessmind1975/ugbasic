/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
@keyword COPPER NOP

@english

The primary purpose of the ''COPPER NOP'' instruction is to wait some time
doing nothing during copper list execution, and synchronized with the television's 
video display.

A copper list is a sequence of special instructions that the processor executes 
independently of the main execution. These instructions are programmed to execute 
in sync with the video signal, typically when the television's video display 
reaches a specific horizontal and vertical position on the screen.

@italian

Lo scopo principale dell'istruzione "COPPER NOP" è di attendere un certo tempo
senza fare nulla durante l'esecuzione della Copper List, sincronizzandosi con il display
video del televisore.

Una Copper List è una sequenza di istruzioni speciali che il processore esegue
indipendentemente dall'esecuzione principale. Queste istruzioni sono programmate per essere eseguite
in sincronia con il segnale video, in genere quando il display
video del televisore raggiunge una specifica posizione orizzontale e verticale sullo schermo.

@syntax COPPER NOP

@example BEGIN COPPER
@example    COPPER WAIT LINE 10
@example    COPPER MOVE &H2c8, &H2c7 AS BYTE
@example    COPPER NOP
@example    COPPER MOVE &H2c8, &H2c7 AS BYTE
@example END COPPER

@alias NOP
@seeAlso BEGIN COPPER...END COPPER

</usermanual> */
void copper_nop( Environment * _environment ) {

    if ( !_environment->insideCopperList ) {
        CRITICAL_COPPER_LIST_NOT_OPENED();
    }

    CopperInstruction * nop = malloc( sizeof( CopperInstruction ) );
    memset( nop, 0, sizeof( CopperInstruction ) );

    nop->operation = COP_NOP;

    if ( _environment->copperList->first ) {
        CopperInstruction * actual = _environment->copperList->first;
        while( actual->next ) {
            actual = actual->next;
        }
        actual->next = nop;
    } else {
        _environment->copperList->first = nop;
    }

}
