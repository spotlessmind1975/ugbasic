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
Define the starting point of a game loop. A game loop is nothing more 
than an implicit loop, within which all the logic of the program (or
of the game) runs. The end point of a game loop can correspond to 
the end of the program or to the ''END GAMELOOP'' statement.

@italian
Definisce il punto di partenza di un loop di gioco. Un loop di 
gioco non è altro che un ciclo implicito, all'interno del quale 
tutta la logica del programma (o del gioco) viene eseguita. 
Il punto finale di un ciclo di gioco può corrispondere al termine
del programma o all'istruzione ''END GAMELOOP''. 

@syntax BEGIN GAMELOOP

@example BEGIN GAMELOOP

@target all
</usermanual> */
void begin_gameloop( Environment * _environment ) {

    outline0("; BEGIN GAMELOOP" );

    _environment->hasGameLoop = 1;

    // TODO: better management for uniqueness gameloops    
    cpu_label( _environment, "__ugbgameloop");
    
}

/**
 * @brief Emit ASM code for <b>END GAMELOOP</b>
 * 
 * This function is called to emit the code necessary to define the ending 
 * point of a game loop.
 * 
 * @pre A <b>BEGIN GAMELOOP</b> must be issued before use this function.
 * 
 * @param _environment Current calling environment
 * @throw EXIT_FAILURE "Cannot call END GAMELOOP without BEGIN GAMELOOP"
 */
/* <usermanual>
@keyword END GAMELOOP

@english
Define the ending point of a game loop.

@italian
Definisce il punto di arrivo di un loop di gioco.

@syntax END GAMELOOP

@example END GAMELOOP

@target all
</usermanual> */
void end_gameloop( Environment * _environment ) {
    if ( _environment->hasGameLoop ) {
        cpu_jump( _environment, "__ugbgameloop");    
        _environment->hasGameLoop = 0;
    } else {
        CRITICAL("Cannot call END GAMELOOP without BEGIN GAMELOOP");
    }
}

/**
 * @brief Emit source and configuration lines for game loops
 * 
 * This function can be called to generate all the definitions (on the source
 * file, on the configuration file and on any support file) necessary to 
 * implement the memory banks.
 * 
 * @param _environment Current calling environment
 */
void gameloop_cleanup( Environment * _environment ) {

    if ( _environment->hasGameLoop ) {
        end_gameloop( _environment );
    }
    
}

