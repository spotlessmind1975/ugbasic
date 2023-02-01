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
 * @brief Emit ASM code for <b>SOUND ...</b>
 * 
 * This function emits a code capable of play a frequency for a certain amount of time
 * on specific channels
 * 
 * @param _environment Current calling environment
 * @param _freq frequency to play
 * @param _delay delay of frequency
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword SOUND

@english
This command allows you to play a certain frequency, for a certain time and on certain 
channels. The command has a number of variations. First, you can omit the channel. 
In this case, the sound will be played on all channels (or on those enabled by the 
''VOICES''/''CHANNELS'' command). Then you can omit the duration, in which case the sound will 
continue to play while the next instruction is executed. Duration is expressed
in milliseconds.

@italian
Questo comando permette di suonare una certa frequenza, per un certo tempo e su certi 
canali. Il comando ha una serie di varianti. In primo luogo, è possibile omettere il 
canale. In tal caso, il suono sarà suonato su tutti i canali (oppure su quelli abilitati 
dal comando ''VOICES''/''CHANNELS''). Poi è possibile omettere la durata, e in tal caso il suono 
continuerà ad essere suonato mentre viene eseguita l'istruzione successiva. La durata è
espressa in millisecondi.

@syntax SOUND #[freq] {, #[duration] {ON #[channels]}}

@example SOUND #440
@example SOUND #440, #250
@example SOUND #440, #250 ON #%001

@target sg1000
</usermanual> */
void sound( Environment * _environment, int _freq, int _delay, int _channels ) {

    outline0("; sn76489_start");
    sn76489_start( _environment, _channels );
    outline0("; sn76489_set_frequency");
    sn76489_set_frequency( _environment, _channels, _freq );
    if ( _delay ) {
        outline0("; wait_milliseconds");
        wait_milliseconds( _environment, _delay );
    }

}

/**
 * @brief Emit ASM code for <b>SOUND ...</b>
 * 
 * This function emits a code capable of play a frequency for a certain amount of time
 * on specific channels
 * 
 * @param _environment Current calling environment
 * @param _freq frequency to play
 * @param _delay delay of frequency
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword SOUND

@syntax SOUND [freq] {, [duration] {ON [channels]}}

@example SOUND laDiesis
@example SOUND solMaggiore, breve
@example SOUND solMaggiore, lunga ON primaVoce

@target sg1000
</usermanual> */
void sound_vars( Environment * _environment, char * _freq, char * _delay, char * _channels ) {

    Variable * freq = variable_retrieve_or_define( _environment, _freq, VT_WORD, 440 );
    if ( _channels ) {
        Variable * channels = variable_retrieve_or_define( _environment, _channels, VT_WORD, 0x07 );
        sn76489_start_var( _environment, channels->realName );
        sn76489_set_frequency_vars( _environment, channels->realName, freq->realName );
    } else {
        sn76489_start_var( _environment, NULL );
        sn76489_set_frequency_vars( _environment, NULL, freq->realName );
    }
    if ( _delay ) {
        wait_milliseconds_var( _environment, _delay );
    }

}