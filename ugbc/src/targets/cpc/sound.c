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

@target cpc
</usermanual> */
void sound( Environment * _environment, int _freq, int _delay, int _channels ) {

    //Registers 0 and 1 operate together to form channel A's final pitch. The eight least significant bits are sent
    //to register 0 and the four most significant bits are sent to register 1. The output frequency is equal to the
    //IC's incoming clock frequency divided by 16 and then further divided by the number written to the course and
    //fine pitch registers, so the higher the number written to these, the lower the pitch. For example, if a 
    //frequency of 1KHz was required and the IC's clock frequency was 1MHz, a total division rate of 1000 would
    //be needed. The sound generator itself divides by 16 so the course and fine pitch registers must provide a 
    //further division by 62.5 (due to the fact that 1000/16 is 62.5). A division rate of 62 or 63 will be
    //accurate enough, since the registers can only store whole numbers. Therefore, 62 or 63 would be written
    //to register 0 and 0 would be written to register 1.

    int chipsetFrequency = ( 4000000 / _freq ) / 16;

    ay8910_start( _environment, _channels );
    ay8910_set_frequency( _environment, _channels, chipsetFrequency );
    if ( _delay ) {
        ay8910_set_duration( _environment, _channels, _delay / 50 /* approx! */ );
        ay8910_wait_duration( _environment, _channels );
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

@target cpc
</usermanual> */
void sound_vars( Environment * _environment, char * _freq, char * _delay, char * _channels ) {

    Variable * freq = variable_retrieve_or_define( _environment, _freq, VT_WORD, 440 );

    Variable * cpuFrequency = variable_temporary( _environment, VT_DWORD, "(chipsetFrequency)" );
    variable_store( _environment, cpuFrequency->name, 4000000 );
    Variable * sixteen = variable_temporary( _environment, VT_WORD, "(16)" );
    variable_store( _environment, sixteen->name, 16 );
    
    Variable * chipsetFrequency = variable_div( _environment, 
                            variable_div( _environment,
                                cpuFrequency->name,
                                freq->name,
                                NULL
                            )->name,
                            sixteen->name,
                            NULL
                            );

    if ( _channels ) {
        Variable * channels = variable_retrieve_or_define( _environment, _channels, VT_WORD, 0x07 );
        ay8910_start_var( _environment, channels->realName );
        ay8910_set_frequency_vars( _environment, channels->realName, chipsetFrequency->realName );
        if ( _delay ) {
            Variable * delay = variable_retrieve_or_define( _environment, _delay, VT_WORD, 0 );
            Variable * delayScaled = variable_sl_const( _environment, delay->name, 6 /* approx! */ );
            ay8910_set_duration_vars( _environment, channels->realName, delayScaled->realName );
            ay8910_wait_duration_vars( _environment, channels->realName );
        }        
    } else {
        ay8910_start_var( _environment, NULL );
        ay8910_set_frequency_vars( _environment, NULL, chipsetFrequency->realName );
        if ( _delay ) {
            Variable * delay = variable_retrieve_or_define( _environment, _delay, VT_WORD, 0 );
            Variable * delayScaled = variable_sl_const( _environment, delay->name, 6 /* approx! */ );
            ay8910_set_duration_vars( _environment, NULL, delayScaled->realName );
            ay8910_wait_duration_vars( _environment, NULL );
        }        
    }

}