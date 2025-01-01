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

The command accepts an additional keyword, ''LOOP'', which allows you to indicate that
the piece of music must be played without ever ending playback: ugBASIC will make it 
start again from the beginning, once playback has finished.

Finally, the command accepts the indication of the ''format'' in which the music is stored
in the variable. This specification is necessary only if the audio file was not loaded 
by the ''LOAD MUSIC'' command. The ''LOAD MUSIC'' command takes care of converting one 
of the supported formats into the internal (''IAF'') ugBASIC format. However, 
ugBASIC can play formats compatible with your audio hardware. In this case, by specifying
the format in which the data is prepared, it is possible to follow up on this request.

Each target has a specific list of supported audio formats.

@italian

Il comando ''MUSIC'' avvia un brano musicale dalla variabile music. Questa musica 
verrà riprodotta indipendentemente dal tuo programma, senza influenzarlo minimamente.

Normalmente è possibile memorizzare diversi arrangiamenti completi. Ad ogni composizione 
viene assegnata la propria variabile musicale individuale.

Il sistema musicale è intelligente e sospenderà automaticamente la musica per la 
durata di eventuali effetti sonori successivi sul canale corrente. Una volta terminato 
il suono, la melodia verrà riavviata dalla posizione precedente.

Il comando accetta una keyword aggiuntiva, LOOP, che permette di indicare che il brano 
musicale deve essere suonato senza mai terminare la riproduzione: ugBASIC lo farà 
ricominciare dall'inizio, una volta terminata la riproduzione.

Infine, il comando accetta l'indicazione del formato (''format'') in cui la musica è memorizzata 
nella variabile. Questa specifica è necessaria solo ed unicamente se il file audio
non è stato caricato dal comando LOAD MUSIC. Il comando LOAD MUSIC si occupa di 
convertire uno dei formati supportati nel formato interno di ugBASIC. Tuttavia, ugBASIC
è in grado di riprodurre formati compatibili con l'hardware audio. In tal caso, 
specificando il formato con cui sono preparati i dati, è possibile dar seguito 
a tale richiesta.

Ogni target ha uno specifico elenco di formati audio supportati.

@syntax MUSIC [LOOP] music [format]
@syntax MUSIC music [format] [LOOP]

@example MUSIC fugue
@example MUSIC backmusic LOOP
@example MUSIC soundtrack PSG

@target c128
</usermanual> */
void music_var( Environment * _environment, char * _music, int _loop, int _music_type ) {

    if ( _environment->emptyProcedure ) {
        return;
    }

    Variable * music = variable_retrieve( _environment, _music );

    if ( _music_type == MUSIC_TYPE_AUTO ) {

        if ( music->type != VT_MUSIC ) {
            CRITICAL_CANNOT_MUSIC( _music );
        }

        sid_start( _environment, 0xff );
        sid_music( _environment, music->realName, music->size, _loop );

    }
    
}

/* <usermanual>
@keyword MUSIC PAUSE

@english

The ''MUSIC PAUSE'' command allows you to temporarily suspend the performance of a piece of music. 
The suspension is carried out either by interrupting the execution of the notes and by setting 
the volume to zero. The music can be reactivated using the command ''MUSIC RESUME''.

@italian

Il comando ''MUSIC PAUSE'' permette di sospendere temporaneamente l'esecuzione di un brano musicale.
La sospensione è svolta sia interrompendo l'esecuzione delle note che ponendo il volume a zero. 
La musica potrà essere riattivata utilizzando il comando ''MUSIC RESUME''.

@syntax MUSIC PAUSE

@example MUSIC PAUSE: WAIT KEY: MUSIC RESUME

@target c128
</usermanual> */
void music_pause( Environment * _environment ) {
    
    deploy( music, src_hw_sid_music_asm );

    variable_store( _environment, "SIDMUSICPAUSE", 0xff );
    volume( _environment, 0, 0x7 );

}

/* <usermanual>
@keyword MUSIC RESUME

@english

The ''MUSIC RESUME'' command allows you to resume a suspended performance of a piece of music. 
The music can be suspended using the command ''MUSIC PAUSE''.

@italian

Il comando ''MUSIC RESUME'' permette di riprendere l'esecuzione di un brano musicale.
La musica viene sospesa dal comando ''MUSIC PAUSE''.

@syntax MUSIC RESUME

@example MUSIC PAUSE: WAIT KEY: MUSIC RESUME

@target c128
</usermanual> */
void music_resume( Environment * _environment ) {

    deploy( music, src_hw_sid_music_asm );

    variable_store( _environment, "SIDMUSICPAUSE", 0x0 );
    volume( _environment, 255, 0x7 );

}

/* <usermanual>
@keyword MUSIC STOP

@english

The ''MUSIC STOP'' command allows you to halt definitively the performance of a piece of music. 

@italian

Il comando ''MUSIC STOP'' permette di fermare in modo definitivo l'esecuzione di un brano musicale.

@syntax MUSIC STOP

@example MUSIC STOP

@target c128
</usermanual> */
void music_stop( Environment * _environment ) {

    deploy( music, src_hw_sid_music_asm );

    variable_store( _environment, "SIDMUSICLOOP", 0x0 );
    variable_store( _environment, "SIDMUSICREADY", 0x0 );
    volume( _environment, 0, 0x7 );

}

/* <usermanual>
@keyword MUSIC SEEK

@english

The ''MUSIC SEEK'' command allows you to move the reproduction to a specific position.

@italian

Il comando ''MUSIC SEEK'' permette di spostare l'esecuzione a una posizione specifica.

@syntax MUSIC SEEK position

@example MUSIC SEEK 42

@target c128
</usermanual> */
void music_seek_var( Environment * _environment, char * _position ) {

    deploy( music, src_hw_sid_music_asm );

    Variable * position = variable_retrieve_or_define( _environment, _position, VT_WORD, 0 );

    cpu_move_8bit( _environment, address_displacement( _environment, position->realName, "1" ), "SN76489BLOCKS" );
    cpu_move_8bit( _environment, position->realName, "SIDLASTBLOCK" );

}

