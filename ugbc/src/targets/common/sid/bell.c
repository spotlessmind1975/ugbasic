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

#include "../../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

#if defined(__c128__) || defined(__c64__) || defined(__c64reu__)

/**
 * @brief Emit ASM code for <b>BELL ...</b>
 * 
 * This function emits a code capable of play a bell sound
 * 
 * @param _environment Current calling environment
 * @param _pitch frequency to play
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword BELL

@english

The ''BELL'' command makes the computer emit a sound, usually a short beep, 
through the internal speaker or audio chipset. This sound serves as an 
acoustic signal to the user, indicating that an action has been completed, 
reporting an error, or simply to attract attention. 

It can be used alone, or specifying characteristics of the sound to be produced.
When you use ''BELL'' with parameters, ugBASIC generates a sine wave with the 
frequency specified by the ''value'', and of ''duration'' length. 
The higher the value, the higher the pitch. The greater ''duration'', the
greater time the sound will last.

The ability to specify the frequency opens up many creative possibilities: by combining 
several ''BELL'' commands with different frequencies, you can create short melodies;
you could simulate the sounds of explosions, pops, or other effects, depending on 
the frequency and duration of the sound; you can create specific beeps to indicate 
different conditions or events in your program.

The supported frequency range may vary depending on the hardware of target computer.
Typically, the duration of the sound produced by ''BELL'' is short and can be 
controlled by another, additional, parameter. Moreover, you can select a specific
channel for audio output.

Executing the command may or may not interrupt program execution, depending on the 
setting of ''DEFINE AUDIO SYNC''. Not all targets support all settings (synchronous 
and asynchronous).

@italian
Il comando ''BELL'' fa sì che il computer emetta un suono, solitamente un 
breve segnale acustico, tramite l'altoparlante interno o il chipset audio. 
Questo suono funge da segnale acustico per l'utente, indicando che un'azione 
è stata completata, segnalando un errore o semplicemente per attirare l'attenzione.

Può essere utilizzato da solo o specificando le caratteristiche del suono da produrre.
Quando si utilizza ''BELL'' con parametri, ugBASIC genera un'onda sinusoidale con la
frequenza specificata dal ''valore'' e di lunghezza ''duration''. Più alto è il valore, 
più alto è il tono. Maggiore è la ''duration'', maggiore sarà la durata del suono.

La possibilità di specificare la frequenza apre molte possibilità creative: 
combinando diversi comandi ''BELL'' con frequenze diverse, è possibile creare 
brevi melodie; è possibile simulare i suoni di esplosioni, scoppi o altri effetti, 
a seconda della frequenza e della durata del suono; è possibile creare segnali 
acustici specifici per indicare diverse condizioni o eventi nel programma.

La gamma di frequenza supportata può variare a seconda dell'hardware del computer 
di destinazione. In genere, la durata del suono prodotto da ''BELL'' è breve e 
può essere controllata da un altro parametro aggiuntivo. Inoltre, è possibile 
selezionare un canale specifico per l'uscita audio.

L'esecuzione del comando può interrompere o meno l'esecuzione del programma, 
a seconda dell'impostazione di DEFINE AUDIO SYNC. Non tutti i target supportano 
tutte le impostazioni (sincrone e asincrone).

@syntax BELL
@syntax BELL note
@syntax BELL note, duration
@syntax BELL note, duration ON channels

@example BELL 42
@example BELL #42 ON #%001

@target c128
</usermanual> */
void bell( Environment * _environment, int _note, int _duration, int _channels ) {

    sid_start( _environment, _channels );
    sid_set_program( _environment, _channels, IMF_INSTRUMENT_GLOCKENSPIEL );
    sid_set_note( _environment, _channels, _note );

    long durationInTicks = ( _duration / 20 ) & 0xff;

    sid_set_duration( _environment, _channels, durationInTicks );

    if ( ! _environment->audioConfig.async ) {
        sid_wait_duration( _environment, _channels );
    }

}

/**
 * @brief Emit ASM code for <b>BELL ...</b>
 * 
 * This function emits a code capable of play a bell-like sound.
 * 
 * @param _environment Current calling environment
 * @param _pitch frequency to play
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword BELL

@target c128
</usermanual> */
void bell_vars( Environment * _environment, char * _note, char * _duration, char * _channels ) {

    Variable * note = variable_retrieve_or_define( _environment, _note, VT_WORD, 42 );
    if ( _channels ) {
        Variable * channels = variable_retrieve_or_define( _environment, _channels, VT_WORD, 0x07 );
        sid_start_var( _environment, channels->realName );
        sid_set_program_semi_var( _environment, channels->realName, IMF_INSTRUMENT_GLOCKENSPIEL );
        sid_set_note_vars( _environment, channels->realName, note->realName );
        if ( _duration ) {
            Variable * duration = variable_retrieve_or_define( _environment, _duration, VT_WORD, 0x07 );
            Variable * durationInTicks = variable_div_const( _environment, duration->name, 20, NULL );
            sid_set_duration_vars( _environment, channels->realName, durationInTicks->realName );
        } else {
            sid_set_duration_vars( _environment, channels->realName, NULL );
        }
        if ( ! _environment->audioConfig.async ) {
            sid_wait_duration_vars( _environment, channels->realName );
        }              
    } else {
        sid_start_var( _environment, NULL );
        sid_set_program_semi_var( _environment, NULL, IMF_INSTRUMENT_GLOCKENSPIEL );
        sid_set_note_vars( _environment, NULL, note->realName );
        if ( _duration ) {
            Variable * duration = variable_retrieve_or_define( _environment, _duration, VT_WORD, 0x07 );
            Variable * durationInTicks = variable_div_const( _environment, duration->name, 20, NULL );
            sid_set_duration_vars( _environment, NULL, durationInTicks->realName );
        } else {
            sid_set_duration_vars( _environment, NULL, NULL );
        }
        if ( ! _environment->audioConfig.async ) {
            sid_wait_duration_vars( _environment, NULL );
        }          
    }

}

#endif