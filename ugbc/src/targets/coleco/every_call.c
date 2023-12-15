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

/* <usermanual>
@keyword EVERY...CALL

@english
Define the call of a procedure at regular intervals, without 
interfering with the main program. You must specifying the length of time 
between every call, measured in TICKS. 

Note that the procedure execution 
time should be less than the interval time, or the main program timings 
will be affected. After a procedure has been entered, the 
''EVERY'' system is automatically disabled. This means that, 
in order to call this feature continuously, an ''EVERY ON'' command 
must be inserted into a subroutine before the final RETURN statement.

@italian
Definisce una chiamata a una procedura a intervalli regolari, senza
interferire con il programma principale. È necessario specificare il
periodo di tempo tra ogni chiamata, misurata in TICKS.

Si fa notare che la durata dell'esecuzione della procedura dovrebbe essere 
inferiore al tempo dell'intervallo indicato, altrimenti le temporizzazioni 
del programma principale ne risentiranno. 

Dopo essere entrati nella procedura, il sistema disabilita la chiamata
periodica. Ciò significa che, per richiamare questa funzione in modo continuo,
è necessario invocare il comando ''EVERY ON'' prima dell'istruzione ''RETURN'' finale.

@syntax EVERY value TICKS CALL identifier

@example EVERY 50 TICKS CALL changeBorderColor

@usedInExample control_periodic_02.bas

@target coleco
</usermanual> */
void every_ticks_call( Environment * _environment, char * _timing, char * _label, char * _timer ) {

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

