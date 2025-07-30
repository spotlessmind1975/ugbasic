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
@keyword BEGIN COPPER...END COPPER

@english

The ''BEGIN COPPER'' and the ''END COPPER'' instructions are fundamental commands 
used in programming hardware that interacts directly with a TV's video signal. 
Their primary purpose is to isolate and delimit a block of instructions (called a
"Copper list") that must be executed in close synchronization with the TV's video 
brush.

Think of the TV screen as a canvas on which a painter is drawing. This "painter" is 
the video brush, a beam of electrons that slides across the screen's surface to paint 
the image. This process occurs very quickly, line by line, from top to bottom and from 
left to right.

The ''BEGIN COPPER'' and ''END COPPER'' instructions allow you to delimit a list of 
operations that will be performed while the video brush is drawing a specific portion 
of the screen. When the program executes a list of instructions between ''BEGIN COPPER''
and ''END COPPER'', it waits for the video brush to reach a specific position (specified 
within the list) before executing the next instruction. This allows you to "paint" graphic 
effects exactly at the desired time and location on the screen, avoiding flickering or 
visual artifacts.

Operations in a copper list can include doing nothing (''COPPER NOP''), waiting for a 
specific position (''COPPER WAIT LINE''), or modifying a specific memory location 
(''COPPER MOVE'').

The main advantage of this synchronization is the ability to create complex and fluid 
graphic effects that would be difficult or impossible to achieve with normal CPU 
programming, which is less precise in controlling video timing.

In summary, ''BEGIN COPPER'' and ''END COPPER'' are essential to fully exploit the 
capabilities of dedicated graphics hardware systems, enabling granular and timed 
control of the video generation process to achieve high-quality visual results.

@italian

Le istruzioni ''BEGIN COPPER'' ed ''END COPPER'' sono comandi fondamentali, 
utilizzati nell'ambito della programmazione per hardware che interagisce 
direttamente con il segnale video di una TV. Il loro scopo principale è 
quello di isolare e delimitare un blocco di istruzioni (chiamato 
"lista copper" o "copper list") che devono essere eseguite in stretta 
sincronizzazione con il pennello video della TV.

Immagina lo schermo della TV come una tela su cui un pittore sta disegnando. 
Questo "pittore" è il pennello video, un fascio di elettroni che scorre 
sulla superficie dello schermo per disegnare l'immagine. Questo processo 
avviene molto rapidamente, riga per riga, dall'alto verso il basso e da 
sinistra a destra.

Con le istruzioni ''BEGIN COPPER'' ed ''END COPPER'' è possibile delimitare 
un elenco di operazioni che saranno eseguite mentre il pennello video sta 
disegnando una specifica parte dello schermo. Quando il programma esegue una 
lista di istruzioni tra ''BEGIN COPPER'' ed ''END COPPER'', questo attende 
che il pennello video raggiunga una determinata posizione (specificata 
all'interno della lista stessa) prima di eseguire l'istruzione successiva. 
Questo permette di "dipingere" effetti grafici esattamente nel momento e nel 
punto desiderato sullo schermo, evitando sfarfallii o artefatti visivi.

Le operazioni previste in una lista copper possono includere il non fare nulla 
(''COPPER NOP''), l'attesa di una specifica posizione (''COPPER WAIT LINE'') o la 
modifca di una specifica locazione di memoria (''COPPER MOVE'').

Il vantaggio principale di questa sincronizzazione è la possibilità di creare 
effetti grafici complessi e fluidi che sarebbero difficili o impossibili da 
realizzare con una normale programmazione della CPU, che è meno precisa nel 
controllo dei tempi video.

In sintesi, ''BEGIN COPPER'' ed ''END COPPER'' sono essenziali per sfruttare 
appieno le capacità di sistemi hardware dedicati alla grafica, consentendo 
un controllo granulare e temporizzato del processo di generazione video per 
ottenere risultati visivi di alta qualità.

@syntax BEGIN COPPER [name]
@syntax    ...
@syntax END COPPER

@alias BEGIN COPPER...ENDCOPPER
@alias COPPER...ENDCOPPER

</usermanual> */
/* <usermanual>
@keyword COPPER...END COPPER

@english

@italian

@alias BEGIN COPPER...END COPPER

</usermanual> */
/* <usermanual>
@keyword BEGIN COPPER...ENDCOPPER

@english

@italian

@alias BEGIN COPPER...END COPPER

</usermanual> */
/* <usermanual>
@keyword COPPER...END COPPER

@english

@italian

@alias BEGIN COPPER...END COPPER

</usermanual> */

void begin_copper( Environment * _environment, char * _name ) {

    if ( _environment->insideCopperList ) {
        CRITICAL_NESTED_COPPER_LIST_NOT_ALLOWED();
    }

    CopperList * existing = find_copper_list( _environment, _name );

    if ( existing ) {
        CRITICAL_COPPER_LIST_ALREADY_DEFINED();
    }

    _environment->insideCopperList = 1;

    CopperList * newCopperList = malloc( sizeof( CopperList ) );
    memset( newCopperList, 0, sizeof( CopperList ) );
    
    if ( _name ) {
        newCopperList->name = strdup( _name );
    }

    newCopperList->next = _environment->copperList;
    _environment->copperList = newCopperList;

}
