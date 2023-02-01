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
 * @brief Emit ASM code for <b>SHOOT ...</b>
 * 
 * This function emits a code capable of play a shoot sound.
 * 
 * @param _environment Current calling environment
 * @param _channels channels to play on
 */
/* <usermanual>
@keyword SHOOT

@english
This command makes the computer emit an shoot-like sound. It is possible to indicate 
on which voices the system should emit the sound. If omitted, it will be issued on all.

@italian
Questo comando fa emettere al computer un suono simile a un colpo. E' possibile
indicare su quali voci il sistema dovrà emettere il suono. Se omesso, sarà emesso su tutte.

@syntax SHOOT {ON #[channel]}

@example SHOOT
@example SHOOT ON %001

@target sc3000
</usermanual> */
void shoot( Environment * _environment, int _channels ) {

    sn76489_set_program( _environment, _channels, IMF_INSTRUMENT_GUNSHOT );
    sn76489_start( _environment, _channels );
    sn76489_set_frequency( _environment, _channels, 1000 );

}

