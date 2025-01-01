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

The ''SOUND'' command add a touch of interactivity and liveliness to your programs. Simply put, 
the ''SOUND'' command allows you to generate sounds directly from your computer. You can
give just the frequency (to start an infinite sound) or a frequency followed by a duration.
You can play multiple sounds by concatenating frequencies or frequencies and durations.

By combining several ''SOUND'' commands with different frequencies and durations, you 
can compose short melodies. For example, you can make a sound play when the user presses 
a button or reaches a goal in the game. You can simulate the sounds of explosions, 
gunshots, or any other effect you want. 

This command allows you to handle multiple audio channels at the same time, if the
target has them, allowing you to create more complex sounds. The waveform of the sound 
generated can vary depending on the available hardware.

@italian

Il comando ''SOUND'' aggiunge un tocco di interattività e vivacità ai tuoi programmi. 
In parole povere, il comando ''SOUND'' ti consente di generare suoni direttamente 
dal tuo computer. Puoi fornire solo la frequenza (per avviare un suono infinito) o 
una frequenza seguita da una durata. Puoi riprodurre più suoni concatenando 
frequenze o frequenze e durate.

Combinando più comandi ''SOUND'' con frequenze e durate diverse, puoi comporre brevi 
melodie. Ad esempio, puoi far riprodurre un suono quando l'utente preme un pulsante 
o raggiunge un obiettivo nel gioco. Puoi simulare i suoni di esplosioni, spari 
o qualsiasi altro effetto desideri.

Questo comando ti consente di gestire più canali audio contemporaneamente, se 
il bersaglio li ha, consentendoti di creare suoni più complessi. La forma d'onda 
del suono generato può variare a seconda dell'hardware disponibile.

@syntax SOUND f1[,d1][;f1[,d2][;...]] [ON channels]

@example SOUND #440
@example SOUND la;do;mi;sol
@example SOUND #440, #250 ON #%001

@target c128
</usermanual> */
void sound( Environment * _environment, int _freq, int _delay, int _channels ) {

    sid_start( _environment, _channels );
    sid_set_program( _environment, _channels, IMF_INSTRUMENT_GLOCKENSPIEL );
    sid_set_frequency( _environment, _channels, _freq );
    if ( _delay ) {
        sid_set_duration( _environment, _channels, _delay / 20 /* approx! */ );
        sid_wait_duration( _environment, _channels );        
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
void sound_vars( Environment * _environment, char * _freq, char * _delay, char * _channels ) {

    Variable * freq = variable_retrieve_or_define( _environment, _freq, VT_WORD, 440 );
    if ( _channels ) {
        Variable * channels = variable_retrieve_or_define( _environment, _channels, VT_WORD, 0x07 );
        sid_start_var( _environment, channels->realName );
        sid_set_program_semi_var( _environment, channels->realName, IMF_INSTRUMENT_GLOCKENSPIEL );
        sid_set_frequency_vars( _environment, channels->realName, freq->realName );
        if ( _delay ) {
            Variable * delay = variable_retrieve_or_define( _environment, _delay, VT_WORD, 0 );
            Variable * durationInTicks = variable_div_const( _environment, delay->name, 20, NULL );
            sid_set_duration_vars( _environment, channels->realName, durationInTicks->realName );
            sid_wait_duration_vars( _environment, channels->realName );
        }
    } else {
        sid_start_var( _environment, NULL );
        sid_set_program_semi_var( _environment, _channels, IMF_INSTRUMENT_GLOCKENSPIEL );
        sid_set_frequency_vars( _environment, NULL, freq->realName );
        if ( _delay ) {
            Variable * delay = variable_retrieve_or_define( _environment, _delay, VT_WORD, 0 );
            Variable * durationInTicks = variable_div_const( _environment, delay->name, 20, NULL );
            sid_set_duration_vars( _environment, NULL, durationInTicks->realName );
            sid_wait_duration_vars( _environment, NULL );
        }
    }

}