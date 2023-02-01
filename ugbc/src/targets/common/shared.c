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
 * @brief Manage variable as "global"
 * 
 * @param _environment 
 */
/* <usermanual>
@keyword SHARED

@english
This keyword sets up a list of variables of a procedure that can be accessed from absolutely 
anywhere in your program.

There is a facility of using strings in procedure definitions. 
As with disc names, the "wild card" characters ''*'' and ''?'' can also 
be included. In this case, the ''*'' character is used to mean "match this 
with any list of characters in the variable name, until the next control 
character is reached", and the ''?'' character means "match this with any 
single character in the variable name". 

''GLOBAL'' or ''SHARED'' should be employed before the first use of the 
variable. Only strings may be used for this technique.

@italian
Questa parola chiave imposta un elenco di variabili della procedura a cui è possibile 
accedere da qualsiasi punto del programma. Prima del primo 
utilizzo della variabile è necessario utilizzare ''GLOBAL'' o ''SHARED''.

C'è la possibilità di usare le stringhe nelle definizioni delle procedure.
Come per i nomi dei file, possono essere inclusi anche i caratteri "jolly" 
''*'' e ''?''. In questo caso, il carattere ''*'' viene utilizzato per 
indicare "corrisponde a un qualsiasi elenco di caratteri nel nome della 
variabile, fino a quando non viene raggiunto il carattere di controllo 
successivo", e il carattere ''?''" significa "abbinalo a qualsiasi 
carattere singolo nel nome della variabile". Solo le stringhe possono 
essere utilizzate con questa tecnica.

@syntax SHARED [expression]{, [expression]{,[expression], ...}}

@example SHARED test
@example SHARED "a*", b, "*c"

@usedInExample procedures_global_01.bas
@usedInExample procedures_global_02.bas

@target all
</usermanual> */
void shared( Environment * _environment ) {

    if ( !_environment->procedureName ) {
        CRITICAL_SHARED_ONLY_IN_PROCEDURES();
    }

    int i = 0;
    for( i=0; i<_environment->parameters; ++i ) {
        variable_global( _environment, _environment->parametersEach[i] );
    }
    _environment->parameters = 0;
}
