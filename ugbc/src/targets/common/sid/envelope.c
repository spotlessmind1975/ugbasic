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

void envelope( Environment * _environment, char * _voice, char * _attack, char * _decay, char * _sustain, char * _release ) {

    Variable * voice = variable_retrieve_or_define( _environment, _voice, VT_BYTE, 0x7 );
    Variable * attack = variable_retrieve_or_define( _environment, _attack, VT_BYTE, 0 );
    Variable * decay = variable_retrieve_or_define( _environment, _decay, VT_BYTE, 0 );
    Variable * sustain = variable_retrieve_or_define( _environment, _sustain, VT_BYTE, 0 );
    Variable * release = variable_retrieve_or_define( _environment, _release, VT_BYTE, 0 );

    sid_attack_decay_sustain_release( _environment, voice->realName, attack->realName, decay->realName, sustain->realName, release->realName );

}

#endif
