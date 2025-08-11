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
</usermanual> */
void begin_gameloop( Environment * _environment ) {

    MAKE_LABEL

    Loop * loop = malloc( sizeof( Loop ) );
    memset( loop, 0, sizeof( Loop ) );
    loop->label = strdup( label );
    loop->type = LT_GAMELOOP;
    loop->next = _environment->loops;
    _environment->loops = loop;

    _environment->hasGameLoop = 1;

    char labelEnd[MAX_TEMPORARY_STORAGE];
    sprintf( labelEnd, "%send", loop->label  );

    // outline1("LD HL, %s", loop->label );
    // outline0("CALL SET_GAMELOOP_HOOK");
    // outline1("JP %s", labelEnd );

    cpu_label( _environment, loop->label );

}
