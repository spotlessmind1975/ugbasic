/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit ASM code for <b>MUSIC ...</b>
 * 
 * This function emits a code capable of play a music.
 * 
 * @param _environment Current calling environment
 * @param _music music to play
 */
/* <usermanual>
@keyword MUSIC

@english

The ''MUSIC'' command starts a piece of music from the music variable. This
music will be played independently of your program, without affecting it in the
slightest.

Normally, it's possible to store several complete arrangements.
Each composition is assigned its own individual music variable. 

The music system is intelligent, and will automatically suspend your music for the
duration of any subsequent sound effects on the current channel. When the sound has
finished, your tune will be restarted from its previous position.

@italian

Il comando ''MUSIC'' avvia un brano musicale dalla variabile music. Questa musica 
verrà riprodotta indipendentemente dal tuo programma, senza influenzarlo minimamente.

Normalmente è possibile memorizzare diversi arrangiamenti completi. Ad ogni composizione 
viene assegnata la propria variabile musicale individuale.

Il sistema musicale è intelligente e sospenderà automaticamente la musica per la 
durata di eventuali effetti sonori successivi sul canale corrente. Una volta terminato 
il suono, la melodia verrà riavviata dalla posizione precedente.

@syntax MUSIC music

@example MUSIC fugue

@target c128
</usermanual> */
void music_var( Environment * _environment, char * _music, int _loop ) {

    Variable * music = variable_retrieve( _environment, _music );

    if ( music->type != VT_MUSIC ) {
        CRITICAL_CANNOT_MUSIC( _music );
    }

    sid_start( _environment, 0xff );
    sid_music( _environment, music->realName, music->size, _loop );

}

