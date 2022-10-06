/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit ASM code for <b>VOLUME OFF</b>
 * 
 * This function emits a code capable to turn off the volume.
 * 
 * @param _environment Current calling environment
 * @param _channels channels to mute
 */
/* <usermanual>
@keyword VOLUME OFF

@english
This command allows you to mute the audio. 
In general, you can mute the overall audio, or each individual voice.

@italian
Questo comando permette di silenziare l'audio generato.
In generale è possibile silenziare l'audio complessivo, oppure quello di ogni
singola voce.

@syntax VOLUME OFF {ON #[channels]}

@example VOLUME OFF
@example VOLUME OFF ON #%001

@target coleco
</usermanual> */
void volume_off( Environment * _environment, int _channels ) {

    sn76489_set_volume( _environment, 0, _channels );

}

/**
 * @brief Emit ASM code for <b>VOLUME OFF</b>
 * 
 * This function emits a code capable to mute the audio generated.
 * 
 * @param _environment Current calling environment
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword VOLUME OFF

@syntax VOLUME OFF {ON [channels]}

@example VOLUME OFF ON voice1

@target coleco
</usermanual> */
void volume_off_var( Environment * _environment, char * _channels ) {

    if ( _channels ) {
        Variable * channels = variable_retrieve_or_define( _environment, _channels, VT_WORD, 0x07 );
        sn76489_set_volume_semi_var( _environment, channels->realName, 0 );
    } else {
        sn76489_set_volume_semi_var( _environment, NULL, 0 );
    }

}