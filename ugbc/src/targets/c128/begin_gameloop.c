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
 * @brief Emit ASM code for <b>BEGIN GAMELOOP</b>
 * 
 * This function is called to emit the code necessary to define the starting 
 * point of a game loop. A game loop is nothing more than an implicit loop, 
 * within which all the logic of the program (or of the game) runs. 
 * The end point of a game loop can correspond to the end of the program 
 * or to the <b>END GAMELOOP</b> statement.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword BEGIN GAMELOOP

@english

The command ''BEGIN GAMELOOP'' define the starting point of the game loop.
A game loop is a fundamental concept in video game programming, especially
in simple video games like those for 8-bit computers. Think of the game 
loop as the heartbeat of a video game: it is a continuous cycle of actions 
that are constantly repeated, giving life to the gaming experience.

In simple terms, the game loop is an infinite loop in the game code that
takes care of: updating the game state, checking user input 
(button presses, joystick movement), updating the position of objects
on the screen, calculating collisions, managing enemy AI, and so on.

The game loop is the place where drawing everything that needs 
to be displayed on the screen, based on the current state of the 
game. In some platforms, it will implictly "sync" the activity with the
vertical blank, so the action inside the loop should be executed
in a single "frame" of game.

On an 8-bit computer, with limited resources, the game loop was often implemented
in a very simple way, as an infinite loop. The ''BEGIN GAMELOOP''...''END GAMELOOP''
instructions  create an infinite loop, so that the program would continue to 
execute the same instructions over and over again. Inside the loop, instructions 
were executed to update the game state, 
such as checking if a button had been pressed or if an enemy had moved.
After updating the state, a routine was called to draw everything 
on the screen. The program would return to the beginning of the loop, ready 
for the next iteration.

The game loop makes the game interactive, allowing the player to hit what 
is happening on the screen, continuously updating the state and redrawing 
the screen creates the illusion of movement and animation. A well-designed 
game loop ensures a smooth and responsive gameplay experience.

@italian

Il comando ''BEGIN GAMELOOP'' definisce il punto di partenza del game loop. 
Un game loop è un concetto fondamentale nella programmazione dei videogiochi, 
specialmente in videogiochi semplici come quelli per computer a 8 bit. 
Si pensi al game loop come al battito cardiaco di un videogioco: è un 
ciclo continuo di azioni che si ripetono costantemente, dando vita 
all'esperienza di gioco.

In parole povere, il game loop è un loop infinito nel codice di gioco 
che si occupa di: aggiornare lo stato del gioco, controllare l'input 
dell'utente (pressione dei pulsanti, movimento del joystick), aggiornare 
la posizione degli oggetti sullo schermo, calcolare le collisioni, 
gestire l'IA nemica e così via.

Il game loop è il luogo in cui disegnare tutto ciò che deve essere 
visualizzato sullo schermo, in base allo stato attuale del gioco. 
In alcune piattaforme, "sincronizza" implicitamente l'attività con 
il vertical blank, quindi l'azione all'interno del loop dovrebbe 
essere eseguita in un singolo "frame" di gioco.

Su un computer a 8 bit, con risorse limitate, il game loop veniva 
spesso implementato in modo molto semplice, come un loop infinito. 
Le istruzioni ''BEGIN GAMELOOP''...''END GAMELOOP'' creano un loop 
infinito, in modo che il programma continui a eseguire le stesse 
istruzioni più e più volte. All'interno del loop, venivano eseguite
istruzioni per aggiornare lo stato del gioco, come controllare 
se è stato premuto un pulsante o se un nemico si è mosso.

Dopo aver aggiornato lo stato, viene chiamata una routine per disegnare 
tutto sullo schermo. Il programma torna all'inizio del loop, pronto 
per l'iterazione successiva.

Il loop di gioco rende il gioco interattivo, consentendo al giocatore di
cogliere ciò che sta accadendo sullo schermo, aggiornando continuamente 
lo stato e ridisegnando lo schermo crea l'illusione di movimento e animazione. 
Un loop di gioco ben progettato garantisce un'esperienza di gioco fluida e reattiva.

@syntax BEGIN GAMELOOP

@example BEGIN GAMELOOP

@target all
</usermanual> */
void begin_gameloop( Environment * _environment ) {

    MAKE_LABEL

    Loop * loop = malloc( sizeof( Loop ) );
    memset( loop, 0, sizeof( Loop ) );
    loop->label = strdup( label );
    loop->type = LT_GAMELOOP;
    loop->next = _environment->loops;
    _environment->loops = loop;

    cpu_label( _environment, loop->label );
    
    _environment->hasGameLoop = 1;

}
