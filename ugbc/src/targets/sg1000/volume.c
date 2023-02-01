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
 * @brief Emit ASM code for <b>VOLUME ...</b>
 * 
 * This function emits a code capable to change the volume 
 * of the audio generated.
 * 
 * @param _environment Current calling environment
 * @param _volume volume to play
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword VOLUME

@english
This command allows you to change the volume at which the audio is generated. 
In general, you can change the overall audio, or that of each individual voice.

@italian
Questo comando permette di modificare il volume con cui l'audio viene generato.
In generale è possibile modificare l'audio complessivo, oppure quello di ogni
singola voce.

@syntax VOLUME #[value] {ON #[channels]}

@example VOLUME #255
@example VOLUME #0 ON #%001

@target coleco
</usermanual> */
void volume( Environment * _environment, int _volume, int _channels ) {

    sn76489_set_volume( _environment, _volume/16, _channels );

}

/**
 * @brief Emit ASM code for <b>VOLUME ...</b>
 * 
 * This function emits a code capable to change the volume 
 * of the audio generated.
 * 
 * @param _environment Current calling environment
 * @param _volume volume to play
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword VOLUME

@syntax VOLUME [volume] {ON [channels]}

@example VOLUME massimo
@example VOLUME zero ON voice1

@target coleco
</usermanual> */
void volume_vars( Environment * _environment, char * _volume, char * _channels ) {

    Variable * volume = variable_retrieve_or_define( _environment, _volume, VT_BYTE, 255 );
    if ( _channels ) {
        Variable * channels = variable_retrieve_or_define( _environment, _channels, VT_WORD, 0x07 );
        sn76489_set_volume_vars( _environment, channels->realName, volume->realName );
    } else {
        sn76489_set_volume_vars( _environment, NULL, volume->realName );
    }

}