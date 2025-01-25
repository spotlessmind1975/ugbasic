/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit code for <strong>ANIMATE ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the procedure
 */
/* <usermanual>
@keyword ANIMATE

@english

The ''ANIMATE'' command allows you to activate a specific animation at the current 
position, or at one indicated in the command. If an animation is already active, 
it will be abruptly interrupted and the indicated one will be started

@italian

Il comando ''ANIMATE'' permette di attivare una specifica animazione nella posizione 
attuale, oppure in una indicata nel comando. Se è già attiva una animazione, la stessa 
sarà interrotta bruscamente e sarà fatta partire quella indicata.

@syntax ANIMATE prefix WITH anim [AT x, y]

@example flyingAirplane := LOAD ATLAS("airplane.png") FRAME SIZE (16, 16)
@example ANIMATION BOUNCE anim WITH flyingAirplane USING airplane
@example ANIMATE airplane WITH anim AT 20, 20
@example DO: RUN PARALLEL: LOOP

@target all
</usermanual> */
void animate_semivars( Environment * _environment, char * _prefix, char * _anim, char * _x, char * _y ) {

#if defined(__gb__)
    return;
#endif

    char prefixAnimation[MAX_TEMPORARY_STORAGE]; sprintf( prefixAnimation, "%sAnimation", _prefix );

    if ( ! variable_exists( _environment, prefixAnimation ) ) {
        CRITICAL_CANNOT_USE_ANIMATE_WITHOUT_ANIMATION(_prefix);
    }

    Variable * prefixAnimationVar = variable_retrieve( _environment, prefixAnimation );

    if ( prefixAnimationVar->type != VT_THREAD ) {
        CRITICAL_CANNOT_USE_ANIMATE_WITHOUT_ANIMATION(_prefix);
    }

    if ( _x ) {
        Variable * x = variable_retrieve_or_define( _environment, _x, VT_POSITION, 0 );
        char prefixX[MAX_TEMPORARY_STORAGE]; sprintf( prefixX, "%sX", _prefix );
        Variable * prefixXVar = variable_retrieve( _environment, prefixX );
        variable_move( _environment, x->name, prefixXVar->name );
    }

    if ( _y ) {
        Variable * y = variable_retrieve_or_define( _environment, _y, VT_POSITION, 0 );
        char prefixY[MAX_TEMPORARY_STORAGE]; sprintf( prefixY, "%sY", _prefix );
        Variable * prefixYVar = variable_retrieve( _environment, prefixY );
        variable_move( _environment, y->name, prefixYVar->name );
    }

    MAKE_LABEL

    char skipKillLabel[MAX_TEMPORARY_STORAGE]; sprintf( skipKillLabel, "%sskip", label );
    cpu_compare_and_branch_8bit_const( _environment, prefixAnimationVar->realName, 0xff, skipKillLabel, 1 );

    // KILL playerAnimation
    kill_procedure( _environment, prefixAnimationVar->name );

    cpu_label( _environment, skipKillLabel );

    // playerAnimation = SPAWN animPlayerPunch
    variable_move( _environment, spawn_procedure( _environment, _anim, 0 )->name, prefixAnimationVar->name );

    run_parallel( _environment );

}

