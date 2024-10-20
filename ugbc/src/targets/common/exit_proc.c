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
 * @brief Emit code for <strong>POP PROC / EXIT PROC</strong>
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword EXIT PROCEDURE

@english

The ''EXIT PROCEDURE'' command is used to stop execution of a specific procedure,
and transfer control of the program to the first statement following the calling
of that procedure. 

The command is useful to exit when an error or unexpected condition occurs, and it
can be used to end the procedure and handle the error appropriately. In some cases, 
using ''EXIT PROCEDURE'' can make your code more efficient by avoiding executing unnecessary 
statements. ''EXIT PROCEDURE'' allows you to create more complex control flows and
make dynamic decisions  during program execution.  Excessive use of ''EXIT PROCEDURE'', however,
can make your code more difficult to read and maintain.

@italian

Il comando ''EXIT PROCEDURE'' viene utilizzato per interrompere l'esecuzione 
di una procedura specifica e trasferire il controllo del programma alla prima 
istruzione successiva alla chiamata di tale procedura.

Il comando è utile per uscire quando si verifica un errore o una condizione imprevista,
e può essere utilizzato per terminare la procedura e gestire l'errore in modo appropriato.
In alcuni casi, l'utilizzo di ''EXIT PROCEDURE'' può rendere il codice più efficiente 
evitando di eseguire istruzioni non necessarie. ''EXIT PROCEDURE'' consente di creare 
flussi di controllo più complessi e prendere decisioni dinamiche durante l'esecuzione 
del programma. Tuttavia, un utilizzo eccessivo di ''EXIT PROCEDURE'' può rendere il 
codice più difficile da leggere e gestire.

@syntax EXIT PROCEDURE

@example PROCEDURE test[ x AS INTEGER ]
@example    IF x > 10 THEN EXIT PROCEDURE
@example       PRINT "X is less or equal to 10"
@example    ENDIF
@example END PROC

@alias POP PROCEDURE
@alias EXIT PROC

</usermanual> */

/* <usermanual>
@keyword POP PROCEDURE

@english

@italian

@syntax POP PROCEDURE

@example POP PROCEDURE

@usedInExample procedures_jumping_02.bas

@alias EXIT PROCEDURE
@alias EXIT PROC
</usermanual> */

/* <usermanual>
@keyword EXIT PROC

@english

@italian

@syntax EXIT PROC

@example EXIT PROC

@usedInExample procedures_jumping_02.bas

@alias POP PROCEDURE
@alias EXIT PROCEDURE

</usermanual> */

void exit_procedure( Environment * _environment ) {

    cpu_return( _environment );
    
}

