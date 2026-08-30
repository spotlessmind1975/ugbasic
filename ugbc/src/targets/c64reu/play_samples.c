/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit ASM code for <b>PLAY SAMPLES</b>
 * 
 * This function emits a code capable of play samples
 * 
 * @param _environment Current calling environment
 * @param _channels channels to play off
 */
/* <usermanual>
@keyword PLAY SAMPLES
@target c64
</usermanual> */
void play_samples_var( Environment * _environment, char * _expr ) {

    deploy( play_samples, src_hw_c64reu_play_samples_asm);

    Variable * samples = variable_retrieve( _environment, _expr );

    if ( samples->type != VT_SAMPLES ) {
        CRITICAL_CANNOT_PLAY_SAMPLES_NOT_SAMPLES( _expr );
    }

    if ( samples->bankAssigned != -1 ) {

        outline1("LDA #$%2.2x", (unsigned char)(samples->absoluteAddress&0xff) );
        outline0("STA REUREUBASE" );
        outline1("LDA #$%2.2x", (unsigned char)((samples->absoluteAddress>>8)&0xff) );
        outline0("STA REUREUBASE+1" );
        outline1("LDA #$%2.2x", (unsigned char)(samples->bankAssigned) );
        outline0("STA REUREUBASE+2" );

        if ( samples->size < 256 ) {
            outline1("LDA #$%2.2x", (unsigned char)(samples->size&0xff) );
            outline0("STA REUTRANSLEN" );
            outline1("LDA #$%2.2x", (unsigned char)((samples->size>>8)&0xff) );
            outline0("STA REUTRANSLEN+1" );
        } else {
            outline0("LDA #$00");
            outline0("STA REUTRANSLEN" );
            outline0("LDA #$1" );
            outline0("STA REUTRANSLEN+1" );
        }

        outline1("LDA #<%s", samples->realName );
        outline0("STA REUC64BASE" );
        outline0("STA PLAYSAMPLESREUL1+1" );
        outline1("LDA #>%s", samples->realName );
        outline0("STA REUC64BASE+1" );
        outline0("STA PLAYSAMPLESREUL1+2" );
        outline0("JSR PLAYSAMPLESREU" );
    } else {
        outline1("LDA #<%s", samples->realName );
        outline0("STA PLAYSAMPLESL1+1" );
        outline1("LDA #>%s", samples->realName );
        outline0("STA PLAYSAMPLESL1+2" );
        outline0("JSR PLAYSAMPLES" );
    }

}
