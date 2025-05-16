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

#if !(defined(__pc128op__) || defined(__mo5__) || defined(__to8__))

/**
 * @brief Emit code for <strong>FADE</strong>
 */

/* <usermanual>
@keyword FADE IN

@english

The ''FADE IN'' command is a fundamental tool for creating smooth visual 
transitions, allowing you to gradually modulate the visibility of elements. 

This command, in its basic form ''FADE IN'', triggers a fade-in. If an element
was previously invisible or partially transparent, this command will gradually 
make it more opaque until it reaches its full visibility. 

Again, the speed of the transition is usually governed by preset parameters. 
An interesting variant of the ''FADE IN'' command appears in the syntax 
''FADE IN'' palette, which finds application in scenarios where color management 
is done via palettes, typically in low-resolution graphic contexts or with a 
limited number of available colors. Instead of acting on opacity, this command 
initiates a gradual transition between an initial color palette and the specified 
palette, making the image emerge through a progressive transformation of its colors. 

It is possible to combine this palette-based fade with a specific time duration 
using the syntax ''PERIOD time'', where time defines the time frame within which 
the color transition from the initial palette to the desired one must be 
completed. Finally, for direct control over the duration of the opacity-based 
fade-in, the form ''FADE IN PERIOD time'' is used. 
In this syntax, the time parameter specifies the duration of the animation, 
determining the speed at which the element transitions from invisibility (or 
partial transparency) to full visibility. 

Using these different forms command allows you to precisely orchestrate 
visual transition effects, contributing significantly to the quality and 
fluidity of the user experience in interactive applications.

@italian

Il comando ''FADE IN'' è uno strumento fondamentale per creare transizioni 
visive fluide, consentendo di modulare gradualmente la visibilità degli elementi.

Questo comando, nella sua forma base ''FADE IN'', attiva una dissolvenza in entrata. Se un elemento
era precedentemente invisibile o parzialmente trasparente, questo comando lo renderà gradualmente
più opaco fino a raggiungere la sua piena visibilità.

Anche in questo caso, la velocità della transizione è solitamente regolata da parametri preimpostati.
Un'interessante variante del comando ''FADE IN'' appare nella sintassi
''palette FADE IN'', che trova applicazione in scenari in cui la gestione del colore
viene effettuata tramite palette, tipicamente in contesti grafici a bassa risoluzione o con un
numero limitato di colori disponibili. Invece di agire sull'opacità, questo comando
avvia una transizione graduale tra una palette di colori iniziale e quella specificata, facendo emergere l'immagine attraverso una progressiva trasformazione dei suoi colori.

È possibile combinare questa dissolvenza basata sulla palette con una durata temporale specifica
utilizzando la sintassi ''PERIOD time'', dove ''time'' definisce l'intervallo di tempo entro il quale
deve essere completata la transizione di colore dalla palette iniziale a quella desiderata. Infine, per un controllo diretto sulla durata della dissolvenza in entrata basata sull'opacità,
viene utilizzata la sintassi ''FADE IN PERIOD time''.
In questa sintassi, il parametro time specifica la durata dell'animazione,
determinando la velocità con cui l'elemento passa dall'invisibilità (o
dalla trasparenza parziale) alla piena visibilità.

L'utilizzo di queste diverse forme di comando consente di orchestrare con precisione
gli effetti di transizione visiva, contribuendo in modo significativo alla qualità e
alla fluidità dell'esperienza utente nelle applicazioni interattive.

@syntax FADE IN [palette] [PERIOD time]

@example FADE IN
@example FADE IN PERIOD 10

@seeAlso FADE OUT
@target atari
@target atarixl
@target pc128op
@target mo5
@target to8
</usermanual> */

void fade_in( Environment * _environment, char * _period ) {

}

#endif