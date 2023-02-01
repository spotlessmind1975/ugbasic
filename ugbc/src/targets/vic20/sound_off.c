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
 * @brief Emit ASM code for <b>SOUND OFF</b>
 * 
 * This function emits a code capable of stop play on specific channels
 * 
 * @param _environment Current calling environment
 * @param _channels channels to play off
 */
/* <usermanual>
@keyword SOUND OFF

@english
This command allows you to stop the play on all channels or specific channels.

@italian
Questo comando permette di interrompere il suono su tutti i canali o su canali specifici.

@syntax SOUND OFF {ON #channels}

@example SOUND OFF
@example SOUND OFF ON #%001

@target c64
</usermanual> */
void sound_off( Environment * _environment, int _channels ) {

    vic1_stop( _environment, _channels );

}

/**
 * @brief Emit ASM code for <b>SOUND OFF ...</b>
 * 
 * This function emits a code capable of stop play on specific channels.
 * 
 * @param _environment Current calling environment
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword SOUND OFF

@syntax SOUND OFF {ON [channels]}

@example SOUND OFF
@example SOUND OFF ON primaVoce

@target c64
</usermanual> */
void sound_off_var( Environment * _environment, char * _channels ) {

    if ( _channels ) {
        Variable * channels = variable_retrieve_or_define( _environment, _channels, VT_WORD, 0x07 );
        vic1_stop_vars( _environment, channels->realName );
    } else {
        vic1_stop_vars( _environment, NULL );
    }

}
