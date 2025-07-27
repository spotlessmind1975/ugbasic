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
@keyword COPPER STORE

@english

The ''COPPER WAIT'' instruction is an essential command. Unlike ''COPPER MOVE'' and 
''COPPER STORE'', which are used to modify values in memory, the ''COPPER WAIT'' instruction 
does not directly modify anything. Its primary purpose is to pause execution until the 
television's video brush reaches a specific position on the screen.

In other words, ''COPPER WAIT'' is a synchronization instruction, necessary to avoid 
flickering and visual artifacts: making hardware changes at the wrong time relative 
to the video scan can cause corrupted or unstable images.

Waiting for a specific location allows you to change colors, shift registers, or 
enable/disable hardware features exactly where and when needed, without the human eye 
perceiving the change as a "jump."

It is therefore possible to define areas of the screen with different color palettes or 
resolutions simply by waiting for the appropriate line with a ''WAIT'' command and then 
using a ''MOVE'' command to set the new parameters.

In short, ''COPPER WAIT'' is the heart of synchronization, allowing complex and dynamic 
changes on the display to be orchestrated in perfect harmony with the video signal flow, 
enabling otherwise impossible graphical effects.

@italian

L'istruzione ''COPPER WAIT'' è un comando essenziale. A differenza di ''COPPER MOVE'' e
''COPPER STORE'', che vengono utilizzate per modificare valori in memoria, l'istruzione 
''COPPER WAIT'' non modifica direttamente nulla. Il suo scopo principale è quello di mettere 
in pausa l'esecuzione finché il pennello video del televisore non raggiunge una posizione 
specifica sullo schermo.

In altre parole, ''COPPER WAIT'' è un'istruzione di sincronizzazione, necessaria per evitare
sfarfallio e artefatti visivi: apportare modifiche hardware al momento sbagliato rispetto 
alla scansione video può causare immagini corrotte o instabili.

L'attesa di una posizione specifica consente di modificare i colori, i registri a scorrimento o
attivare/disattivare le funzionalità hardware esattamente dove e quando necessario, senza 
che l'occhio umano percepisca la modifica come un "salto".

È quindi possibile definire aree dello schermo con diverse palette di colori o risoluzioni semplicemente
attendendo la riga appropriata con un comando ''WAIT'' e quindi utilizzando un comando ''MOVE''
per impostare i nuovi parametri.

In breve, ''COPPER WAIT'' è il cuore della sincronizzazione, consentendo di orchestrare 
cambiamenti complessi e dinamici sul display in perfetta armonia con il flusso del 
segnale video, consentendo effetti grafici altrimenti impossibili.

@syntax BEGIN COPPER
@syntax    COPPER WAIT 10
@syntax    COPPER STORE &H2c8, RED AS BYTE
@syntax    COPPER WAIT 30
@syntax    COPPER STORE &H2c8, BLUE AS BYTE
@syntax END COPPER

@alias WAIT
@seeAlso BEGIN COPPER...END COPPER

</usermanual> */

void copper_wait( Environment * _environment, int _line ) {

    if ( !_environment->insideCopperList ) {
        CRITICAL_COPPER_LIST_NOT_OPENED();
    }

    CopperInstruction * wait = malloc( sizeof( CopperInstruction ) );
    memset( wait, 0, sizeof( CopperInstruction ) );

    wait->operation = COP_WAIT;
    wait->param1 = _line;

    if ( _environment->copperList->first ) {
        CopperInstruction * actual = _environment->copperList->first;
        while( actual->next ) {
            actual = actual->next;
        }
        actual->next = wait;
    } else {
        _environment->copperList->first = wait;
    }

}
