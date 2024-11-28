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

/* <usermanual>
@keyword ENVELOPE

@english

The ''ENVELOPE'' command is used to define the volume of a sound over 
time, or its envelope. In simpler terms, it allows you to create 
richer and more complex sound effects, by defining the initial phase 
in which the sound rapidly increases in volume, the phase in which 
the sound decreases in volume, the final phase in which the sound 
fades away until it disappears. The ''ENVELOPE'' command uses 
internal tone generators to create these effects. 

This command simulates different musical instruments, such as 
pianos, drums, sound effects, and more. It creates more complex 
and dynamic melodies and harmonies, and it can be used to 
create sound effects for games, such as explosions, 
gunshots, or ambient sounds.

@italian

Il comando ''ENVELOPE'' viene utilizzato per definire il volume 
di un suono nel tempo, o il suo envelope. In termini più semplici, 
consente di creare effetti sonori più ricchi e complessi, definendo 
la fase iniziale in cui il suono aumenta rapidamente di volume, la 
fase in cui il suono diminuisce di volume, la fase finale in cui 
il suono si affievolisce fino a scomparire. Il comando ''ENVELOPE''
utilizza generatori di toni interni per creare questi effetti.

Questo comando simula diversi strumenti musicali, come pianoforti, 
tamburi, effetti sonori e altro ancora. Crea melodie e armonie più 
complesse e dinamiche e può essere utilizzato per creare effetti 
sonori per i giochi, come esplosioni, spari o suoni ambientali.

@syntax ENVELOPE voice, attack, decay, sustain, release

@example ENVELOPE 1, 2, 11, 5, 0

</usermanual> */


void envelope( Environment * _environment, char * _voice, char * _attack, char * _decay, char * _sustain, char * _release ) {

    Variable * voice = variable_retrieve_or_define( _environment, _voice, VT_BYTE, 0x7 );
    Variable * attack = variable_retrieve_or_define( _environment, _attack, VT_BYTE, 0 );
    Variable * decay = variable_retrieve_or_define( _environment, _decay, VT_BYTE, 0 );
    Variable * sustain = variable_retrieve_or_define( _environment, _sustain, VT_BYTE, 0 );
    Variable * release = variable_retrieve_or_define( _environment, _release, VT_BYTE, 0 );

    sid_attack_decay_sustain_release( _environment, voice->realName, attack->realName, decay->realName, sustain->realName, release->realName );

}

#endif
