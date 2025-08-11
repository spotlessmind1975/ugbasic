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

/* <usermanual>
@keyword EVERY...CALL

@english

The ''EVERY'' allows to execute a procedure at specified intervals of time. 
It is especially useful for creating animations, handling real-time events, 
and simulating dynamic behavior in your programs. You can give the
''value'' as number of ticks to wait for triggering the call, and
''timer'' to select a specific timer (up to 8 timers are present).

It allows you to create smooth animations by moving objects on the 
screen at regular intervals, and it is essential for managing real-time 
events, such as character movement, object collisions, and keyboard input management.
It can be used also to simulate physical or biological phenomena that evolve 
over time., or to create dynamic visual effects, such as sparks, explosions, 
or screen transitions.

The speed at which ''EVERY'' commands execute depends on the frame 
rate of your computer, and from the parameter ''value'' given. A 
higher frame rate means that actions will be executed more frequently,
while an higher ''value'' means that actions will be executed less frequently.

Note that the procedure execution time should be less than the interval time, 
or the main program timings will be affected!

There are 8 delay timers from 0 to 7 which can be specified with ''timer''. 
If omitted ''timer'' defaults to 0. In the case of parallel task has 0 the 
highest and 8 the lowest priority.

With ''EVERY OFF'' and ''EVERY ON'' you can disable or enable the timed 
calls. Procedures run as long as the main loop / program runs, even the 
main programm is paused. It is important to know or realise that 
low-priority-procedures which occurs simultanously to higher-priority-procedures 
are not lost. Their task remains or handled again after finishing the higher-prio interrupt.

Important: the meaning of this command is not altered by ''OPTION CALL'' pragma,
so this will always work like a ''CALL'' command and never as an unconditional
jump to a label (''GOTO'').

@italian

''EVERY'' consente di eseguire azioni a intervalli di tempo specificati.
È particolarmente utile per creare animazioni, gestire eventi in tempo 
reale e simulare comportamenti dinamici nei tuoi programmi. Puoi dare ''value'' 
come numero di tick da attendere per l'attivazione della chiamata e ''timer'' 
per selezionare un timer specifico (sono presenti fino a 8 timer).

Ti consente di creare animazioni fluide spostando oggetti sullo schermo a 
intervalli regolari ed è essenziale per gestire eventi in tempo reale, come 
il movimento dei personaggi, le collisioni di oggetti e la gestione dell'input 
da tastiera. Può anche essere utilizzato per simulare fenomeni fisici o biologici 
che si evolvono nel tempo, o per creare effetti visivi dinamici, come scintille, 
esplosioni o transizioni dello schermo.

La velocità con cui vengono eseguiti i comandi ''EVERY'' dipende dal frame rate 
del tuo computer e dal parametro ''value'' fornito. Un frame rate più alto significa
che le azioni saranno eseguite più frequentemente, mentre un ''valore'' più alto 
significa che le azioni saranno eseguite meno frequentemente.

Nota che il tempo di esecuzione della procedura dovrebbe essere inferiore al 
tempo di intervallo, altrimenti i tempi del programma principale saranno 
influenzati!

Ci sono 8 timer di ritardo da 0 a 7 che possono essere specificati con ''timer''.
Se omesso, ''timer'' è impostato di default su 0. Nel caso di attività parallele, 
0 ha la priorità più alta e 8 la priorità più bassa.

Con ''EVERY OFF'' e ''EVERY ON'' puoi disabilitare o abilitare le chiamate 
temporizzate. Le procedure vengono eseguite finché il ciclo/programma principale 
è in esecuzione, anche il programma principale è in pausa. È importante sapere
o realizzare che le procedure a bassa priorità che si verificano simultaneamente 
a procedure a priorità più alta non vengono perse. Il loro compito rimane o viene
gestito di nuovo dopo aver terminato l'interruzione a priorità più alta.

Importante: il significato di questo comando non viene alterato dalla direttiva 
''OPTION CALL'', quindi si tratta sempre di un ''GOSUB'' e non di un ''GOTO''!

@syntax EVERY value[,timer] TICKS CALL identifier

@example EVERY 50 TICKS CALL changeBorderColor
@example EVERY 50,2 TICKS CALL changeBorderColor

@usedInExample control_periodic_02.bas
@usedInExample control_periodic_03.bas

@seeAlso AFTER...GOSUB
@seeAlso EVERY ON
@seeAlso EVERY OFF
@target pccga
</usermanual> */
void every_ticks_call( Environment * _environment, char * _timing, char * _name, char * _timer ) {

    Procedure * procedure = _environment->procedures;

    while( procedure ) {
        if ( strcmp( procedure->name, _name ) == 0 ) {
            break;
        }
        procedure = procedure->next;
    }

    if ( !procedure ) {
        CRITICAL_PROCEDURE_MISSING(_name);
    }

    if ( procedure->protothread ) {
        CRITICAL_PARALLEL_PROCEDURE_CANNOT_BE_CALLED(_name);
    }

    Variable * timing = variable_retrieve_or_define( _environment, _timing, VT_WORD, 0 );
    Variable * timer = NULL;
    char * timerRealName = NULL;
    if ( _timer ) {
        timer = variable_retrieve_or_define( _environment, _timer, VT_BYTE, 0 );
        timerRealName = timer->realName;
    }

    pccga_timer_set_address( _environment, timerRealName, procedure->realName );
    pccga_timer_set_counter( _environment, timerRealName, timing->realName );
    pccga_timer_set_init( _environment, timerRealName, timing->realName );

}

