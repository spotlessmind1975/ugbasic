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
 * @brief Emit ASM code for <b>EXIT PROC IF</b>
 * 
 * This function out of the current procedure on condition.
 * 
 * @param _environment Current calling environment
 * @param _expression Expression to check
 */
/* <usermanual>
@keyword EXIT PROCEDURE IF

@english

The ''EXIT PROCEDURE IF'' command is used to stop execution of a specific procedure,
and transfer control of the program to the first statement following the calling
of that procedure, in case an expression is true.''TRUE''

The command is useful to exit when an error or unexpected condition occurs, and it
can be used to end the procedure and handle the error appropriately. In some cases, 
using ''EXIT PROCEDURE IF'' can make your code more efficient by avoiding executing unnecessary 
statements. ''EXIT PROCEDURE IF'' allows you to create more complex control flows and
make dynamic decisions  during program execution.  Excessive use of ''EXIT PROCEDURE IF'', however,
can make your code more difficult to read and maintain.

@italian

Il comando ''EXIT PROCEDURE IF'' viene utilizzato per interrompere l'esecuzione 
di una procedura specifica e trasferire il controllo del programma alla prima 
istruzione successiva alla chiamata di tale procedura, nel caso la condizione
indicata sia ''TRUE''.

Il comando è utile per uscire quando si verifica un errore o una condizione imprevista,
e può essere utilizzato per terminare la procedura e gestire l'errore in modo appropriato.
In alcuni casi, l'utilizzo di ''EXIT PROCEDURE IF'' può rendere il codice più efficiente 
evitando di eseguire istruzioni non necessarie. ''EXIT PROCEDURE IF'' consente di creare 
flussi di controllo più complessi e prendere decisioni dinamiche durante l'esecuzione 
del programma. Tuttavia, un utilizzo eccessivo di ''EXIT PROCEDURE IF'' può rendere il 
codice più difficile da leggere e gestire.

@syntax EXIT PROCEDURE IF expression

@example PROCEDURE test[ x AS INTEGER ]
@example    EXIT PROCEDURE IF x > 10
@example    PRINT "X is less or equal to 10"
@example END PROC

@alias EXIT PROC IF

</usermanual> */

/* <usermanual>
@keyword EXIT PROC IF

@english

@italian

@syntax EXIT PROC IF expression

@example EXIT PROC IF

@usedInExample procedures_jumping_02.bas

@alias EXIT PROCEDURE IF

</usermanual> */

/* <usermanual>
@keyword EXIT PROCEDURE WITH...IF

@english

The ''EXIT PROCEDURE WITH...IF'' command is used to stop execution of a specific function,
and transfer control of the program to the first statement following the calling
of that procedure, giving back a value in case an expression is true.''TRUE''

The command is useful to exit when an error or unexpected condition occurs, and it
can be used to end the procedure and handle the error appropriately. In some cases, 
using ''EXIT PROCEDURE WITH...IF'' can make your code more efficient by avoiding executing unnecessary 
statements. ''EXIT PROCEDURE WITH...IF'' allows you to create more complex control flows and
make dynamic decisions  during program execution.  Excessive use of ''EXIT PROCEDURE WITH...IF'', however,
can make your code more difficult to read and maintain.

@italian

Il comando ''EXIT PROCEDURE WITH...IF'' viene utilizzato per interrompere l'esecuzione 
di una funzione specifica e trasferire il controllo del programma alla prima 
istruzione successiva alla chiamata di tale procedura, restituendo un valore,
nel caso la condizione indicata sia ''TRUE''.

Il comando è utile per uscire quando si verifica un errore o una condizione imprevista,
e può essere utilizzato per terminare la procedura e gestire l'errore in modo appropriato.
In alcuni casi, l'utilizzo di ''EXIT PROCEDURE WITH...IF'' può rendere il codice più efficiente 
evitando di eseguire istruzioni non necessarie. ''EXIT PROCEDURE WITH...IF'' consente di creare 
flussi di controllo più complessi e prendere decisioni dinamiche durante l'esecuzione 
del programma. Tuttavia, un utilizzo eccessivo di ''EXIT PROCEDURE WITH...IF'' può rendere il 
codice più difficile da leggere e gestire.

@syntax EXIT PROCEDURE WITH value IF expression

@example PROCEDURE test[ x AS INTEGER ]
@example    EXIT PROCEDURE WITH 0 IF x > 10
@example    PRINT "X is less or equal to 10"
@example    RETURN 1
@example END PROC

@alias EXIT PROC IF

</usermanual> */

/* <usermanual>
@keyword EXIT PROC WITH...IF

@english

@italian

@syntax EXIT PROC WITH value IF expression

@example PROCEDURE test[ x AS INTEGER ]
@example    EXIT PROC WITH 0 IF x > 10
@example    PRINT "X is less or equal to 10"
@example    RETURN 1
@example END PROC

@alias EXIT PROC WITH...IF

</usermanual> */

void exit_proc_if( Environment * _environment, char * _expression, char * _value ) {

    MAKE_LABEL

    Variable * expression = variable_retrieve( _environment, _expression );

    cpu_bveq( _environment,  expression->realName, label );

    if ( _value ) {
        return_procedure( _environment, _value );
    } else {
        cpu_return( _environment );
    }

    cpu_label( _environment, label );

}