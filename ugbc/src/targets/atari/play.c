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
 * @brief Emit ASM code for <b>PLAY ...</b>
 * 
 * This function emits a code capable of play a note for a certain amount of time
 * on specific channels
 * 
 * @param _environment Current calling environment
 * @param _note note to play
 * @param _delay delay of playing
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword PLAY

@english
This command allows you to play a certain note, for a certain time and on certain 
channels. The command has a number of variations. First, you can omit the channel. 
In this case, the sound will be played on all channels (or on those enabled by the 
''VOICES''/''CHANNELS'' command). Then you can omit the duration, in which case the sound will 
continue to play while the next instruction is executed. Duration is expressed
in milliseconds.

@italian
Questo comando permette di suonare una certa nota, per un certo tempo e su certi 
canali. Il comando ha una serie di varianti. In primo luogo, è possibile omettere il 
canale. In tal caso, il suono sarà suonato su tutti i canali (oppure su quelli abilitati 
dal comando ''VOICES''/''CHANNELS''). Poi è possibile omettere la durata, e in tal caso il suono 
continuerà ad essere suonato mentre viene eseguita l'istruzione successiva. La durata è
espressa in millisecondi.

@syntax PLAY #[note] {, #[duration] {ON #[channels]}}

@example PLAY #32
@example PLAY #24, #250
@example PLAY #60, #1250 ON #%001

@target atari
</usermanual> */
void play( Environment * _environment, int _note, int _delay, int _channels ) {

    pokey_start( _environment, _channels );
    pokey_set_note( _environment, _channels, _note );
    if ( _delay ) {
        wait_milliseconds( _environment, _delay );
    }

}

/**
 * @brief Emit ASM code for <b>PLAY ...</b>
 * 
 * This function emits a code capable of play a note for a certain amount of time
 * on specific channels
 * 
 * @param _environment Current calling environment
 * @param _note note to play
 * @param _delay delay of playing
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword PLAY

@syntax PLAY [note] {, [duration] {ON [channels]}}

@example PLAY laDiesis
@example PLAY solMaggiore, breve
@example PLAY solMaggiore, lunga ON primaVoce

@target atari
</usermanual> */
void play_vars( Environment * _environment, char * _note, char * _delay, char * _channels ) {

    Variable * note = variable_retrieve_or_define( _environment, _note, VT_BYTE, 42 );
    if ( _channels ) {
        Variable * channels = variable_retrieve_or_define( _environment, _channels, VT_WORD, 0x07 );
        pokey_start_var( _environment, channels->realName );
        pokey_set_note_vars( _environment, channels->realName, note->realName );
    } else {
        pokey_start_var( _environment, NULL );
        pokey_set_note_vars( _environment, NULL, note->realName );
    }
    if ( _delay ) {
        wait_milliseconds_var( _environment, _delay );
    }

}