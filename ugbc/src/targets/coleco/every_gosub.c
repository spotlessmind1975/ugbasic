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
 * @brief Emit ASM code for <b>EVERY ... TICKS GOSUB ...</b>
 * 
 * @param _environment Current calling environment
 * @param _label Label to jump to when vertical raster reach the value given
 * @param _position The vertical position to wait for
 */
/* <usermanual>
@keyword EVERY...GOSUB

@english
Define the call of a subroutine at regular intervals, without 
interfering with the main program. You must specifying the length of time 
between every call, measured in TICKS. The ugBASIC branches to the 
subroutine EVERY ''value''/''TICKS PER SECONDS'' seconds.

Note that the subroutine execution 
time should be less than the interval time, or the main program timings 
will be affected. 

There are 8 delay timers from 0 to 7 which can be specified with ''timer''. 
If omitted ''timer'' defaults to 0. In the case of parallel task has 0 the 
highest and 8 the lowest priority.

With ''EVERY OFF'' and ''EVERY ON'' you can disable or enable the timed
calls. Subroutines run as long as the main loop / program runs, even the 
main programm is paused. It is important to know or realise that 
low-priority-subroutines which occurs simultanously to higher-priority-subroutines 
are not lost. Their task remains or handled again after finishing the higher-prio interrupt.

@italian
Introduce la chiamata di una subroutine a intervalli regolari, senza interferire 
con il programma principale. È necessario specificare l'intervallo di tempo tra
ogni chiamata, misurato in ''TICKS''. Il compilatore ugBASIC passa alla subroutine 
ogni ''value''/''TICKS PER SECOND'' secondi.

Si noti che il tempo di esecuzione della subroutine dovrebbe essere inferiore al 
tempo dell'intervallo, altrimenti i tempi del programma principale verranno influenzati. 

Vi sono 8 timer di ritardo da 0 a 7 che possono essere specificati con ''timer''. 
Se omesso, il valore predefinito ''timer'' è 0. Nel caso di attività parallela, 
0 ha la priorità più alta e 8 la priorità più bassa.

Con ''EVERY OFF'' e ''EVERY ON'' è possibile disabilitare o abilitare le chiamate 
temporizzate. Le subroutine vengono eseguite finché viene eseguito il 
ciclo/programma principale, anche se il programma principale è in pausa. 
È importante sapere o realizzare che le subroutine a bassa priorità che si 
verificano contemporaneamente alle subroutine a priorità più alta non vanno perse. 
Il loro compito rimane o viene gestito nuovamente dopo aver terminato 
l'interruzione con priorità più alta.

@syntax EVERY value[,timer] TICKS GOSUB label

@example EVERY 50 TICKS GOSUB 100
@example EVERY 50,2 TICKS GOSUB label

@usedInExample control_periodic_01.bas
@usedInExample control_periodic_03.bas

@target coleco
</usermanual> */

void every_ticks_gosub( Environment * _environment, char * _timing, char * _label, char * _timer ) {

    Variable * timing = variable_retrieve_or_define( _environment, _timing, VT_WORD, 0 );
    Variable * timer = NULL;
    char * timerRealName = NULL;
    if ( _timer ) {
        timer = variable_retrieve_or_define( _environment, _timer, VT_BYTE, 0 );
        timerRealName = timer->realName;
    }

    coleco_timer_set_address( _environment, timerRealName, _label );
    coleco_timer_set_counter( _environment, timerRealName, NULL );
    coleco_timer_set_init( _environment, timerRealName, timing->realName );

}
