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
@keyword COPPER MOVE

@english

The primary purpose of the ''COPPER MOVE'' instruction is to move the 
value of a specific memory location or hardware register at a specific time, to
another memory location or hardware gister, and synchronized with the 
television's video display.

A copper list is a sequence of special instructions that the processor executes 
independently of the main execution. These instructions are programmed to execute 
in sync with the video signal, typically when the television's video display 
reaches a specific horizontal and vertical position on the screen.

The instruction acts as a "real-time controller" for various aspects of the 
hardware system, particularly those related to graphics. Essentially, it takes a 
value from a ''source'' and it writes it to a specific ''destination''.

The versatility of ''COPPER MOVE'' lies in its ability to manipulate the hardware 
registers that control critical aspects of the display.

@italian

Lo scopo principale dell'istruzione ''COPPER STORE'' è quello di modificare il 
valore di una specifica posizione di memoria o di un registro hardware in un momento 
specifico, sincronizzato con il display del televisore.

Una copper list è una sequenza di istruzioni speciali che il processore esegue indipendentemente 
dall'esecuzione principale. Queste istruzioni sono programmate per essere eseguite 
in sincronia con il segnale video, in genere quando il display del televisore raggiunge 
una specifica posizione orizzontale e verticale sullo schermo.

L'istruzione funge da "controller in tempo reale" per vari aspetti del sistema hardware, in 
particolare quelli relativi alla grafica. In sostanza, accetta un valore (un dato immediato) 
e lo scrive in una specifica destinazione.

La versatilità di ''COPPER STORE'' risiede nella sua capacità di manipolare i registri hardware 
che controllano gli aspetti critici del display.

@syntax COPPER MOVE source, destination AS datatype

@example BEGIN COPPER
@example    COPPER WAIT LINE 10
@example    COPPER MOVE &H2c8, &H2c7 AS BYTE
@example    COPPER WAIT LINE 30
@example    COPPER MOVE &H2c8, &H2c7 AS BYTE
@example END COPPER

@alias MOVE
@seeAlso BEGIN COPPER...END COPPER

</usermanual> */
/* <usermanual>
@keyword MOVE

@english

@italian

@syntax  MOVE source, destination AS datatype

@example BEGIN COPPER
@example    WAIT 10
@example    MOVE #&H2c8, #&H2c7 AS BYTE
@example    WAIT 30
@example    MOVE #&H2c8, #&H2c7 AS BYTE
@example END COPPER

@alias COPPER MOVE
</usermanual> */

extern char DATATYPE_AS_STRING[][16];

void copper_move( Environment * _environment, int _address1, int _address2, VariableType _variableType ) {

    if ( !_environment->insideCopperList ) {
        CRITICAL_COPPER_LIST_NOT_OPENED();
    }

    CopperInstruction * move = malloc( sizeof( CopperInstruction ) );
    memset( move, 0, sizeof( CopperInstruction ) );

    switch( _variableType ) {
        case VT_BYTE:
            move->operation = COP_MOVE_BYTE;
            break;
        case VT_WORD:
            move->operation = COP_MOVE_WORD;
            break;
        case VT_DWORD:
            move->operation = COP_MOVE_DWORD;
            break;
        default:
            CRITICAL_MOVE_WITH_NOT_ALLOWED_TYPE(DATATYPE_AS_STRING[_variableType]);
    }

    move->param1 = _address1;
    move->param2 = _address2;

    if ( _environment->copperList->first ) {
        CopperInstruction * actual = _environment->copperList->first;
        while( actual->next ) {
            actual = actual->next;
        }
        actual->next = move;
    } else {
        _environment->copperList->first = move;
    }

}
