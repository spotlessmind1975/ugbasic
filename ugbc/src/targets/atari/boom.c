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
 * @brief Emit ASM code for <b>BOOM ...</b>
 * 
 * This function emits a code capable of play a explosion-like sound.
 * 
 * @param _environment Current calling environment
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword BOOM

@english
This command makes the computer emit an explosion-like sound. It is possible to indicate 
the duration of sound effect and on which voices the system should emit the sound. If omitted, it will be issued on all.

Note that the execution of the effect can be synchronous or asynchronous, depending on the target. 
Synchronous execution means that the program will wait for the effect to complete before returning; 
on the contrary, asynchronous execution requires the program to continue executing subsequent instructions.

The behavior can be modified by the ''DEFINE AUDIO SYNC'' and ''DEFINE AUDIO ASYNC'' 
pragmas, which however may not be available for the target in question.

@italian
Questo comando fa emettere al computer un suono simile a una esplosione. E' possibile
indicare la durata dell'effetto e su quali voci il sistema dovrà emettere il suono. Se omesso, sarà emesso su tutte.

Da notare che l'esecuzione dell'effetto può essere sincrono o asincrono, a seconda
del target. L'esecuzione sincrona implica che il programma attenderà che l'effetto
si completi prima di tornare; al contrario, l'esecuzione asincrona prevede che il
programma continui ad eseguire le successive istruzioni.

Il comportamento può essere modificato dai pragma ''DEFINE AUDIO SYNC'' e 
''DEFINE AUDIO ASYNC'', che tuttavia potrebbe non essere disponibile per 
il target in oggetto.

@syntax BOOM [#duration [MS]] [ON #channel]
@syntax BOOM [duration [MS]] [ON channel]

@example BOOM 1000 MS
@example BOOM 100 MS ON %001

@target atari
</usermanual> */
void boom( Environment * _environment, int _duration, int _channels ) {

    pokey_set_program( _environment, _channels, IMF_INSTRUMENT_EXPLOSION );
    pokey_start( _environment, _channels );
    pokey_set_frequency( _environment, _channels, 1000 );

    long durationInTicks = ( _duration / 20 ) & 0xff;

    pokey_set_duration( _environment, _channels, durationInTicks );

    if ( ! _environment->audioConfig.async ) {
        pokey_wait_duration( _environment, _channels );
    }

}

/**
 * @brief Emit ASM code for <b>BOOM ...</b>
 * 
 * This function emits a code capable of play a explosion-like sound.
 * 
 * @param _environment Current calling environment
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword BOOM

@target atari
</usermanual> */
void boom_var( Environment * _environment, char * _duration, char * _channels ) {

    if ( _channels ) {
        Variable * channels = variable_retrieve_or_define( _environment, _channels, VT_WORD, 0x07 );
        pokey_start_var( _environment, channels->realName );
        pokey_set_program_semi_var( _environment, channels->realName, IMF_INSTRUMENT_EXPLOSION );
        if ( _duration ) {
            Variable * duration = variable_retrieve_or_define( _environment, _duration, VT_WORD, 0x07 );
            cpu_math_div2_const_16bitnvironment, duration->realName, 4, 0 );
            sid_set_duration_vars( _environment, channels->realName, duration->realName );
        } else {
            sid_set_duration_vars( _environment, channels->realName, "TICKSPERSECOND" );
        }
        if ( ! _environment->audioConfig.async ) {
            sid_wait_duration_vars( _environment, channels->realName );
        }
    } else {
        pokey_start_var( _environment, NULL );
        pokey_set_program_semi_var( _environment, NULL, IMF_INSTRUMENT_EXPLOSION );
        if ( _duration ) {
            Variable * duration = variable_retrieve_or_define( _environment, _duration, VT_WORD, 0x07 );
            cpu_math_div2_const_16bitnvironment, duration->realName, 4, 0 );
            sid_set_duration_vars( _environment, NULL, duration->realName );
        } else {
            sid_set_duration_vars( _environment, NULL, "TICKSPERSECOND" );
        }
        if ( ! _environment->audioConfig.async ) {
            sid_wait_duration_vars( _environment, NULL );
        }
    }


}

