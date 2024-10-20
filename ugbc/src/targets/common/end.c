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
 * @brief Emit ASM code for <b>END</b>
 * 
 * This function will stop completely everything.
 * 
 * @param _environment Current calling environment
 */
/* <usermanual>
@keyword END

@english

The ''END'' command is used to terminate the execution of a program. 
When the computer encounters this command, it stops executing 
subsequent instructions.

Generally, the ''END'' command is placed at the end of a program 
to indicate its conclusion. It can be used within the program to 
interrupt execution in a controlled manner, for example when a 
particular condition occurs.

When the ''END'' command is encountered, the computer stops
immediately execution, also interrupts are not served anymore.
This is different from the ''HALT'' command, which only suspends 
execution but not interrupts.

@italian

Il comando ''END'' viene utilizzato per terminare l'esecuzione 
di un programma. Quando il computer incontra questo comando, 
interrompe l'esecuzione delle istruzioni successive.

In genere, il comando ''END'' viene posizionato alla fine di 
un programma per indicarne la conclusione. Può essere utilizzato 
all'interno del programma per interrompere l'esecuzione 
in modo controllato, ad esempio quando si verifica una particolare 
condizione.

Quando viene incontrato il comando ''END'', il computer interrompe 
immediatamente l'esecuzione, inoltre gli interrupt non vengono 
più serviti. Questo è diverso dal comando ''HALT'', che sospende 
solo l'esecuzione ma non gli interrupt.

@syntax END

@example END

@seeAlso HALT

</usermanual> */
void end( Environment * _environment ) {

    cpu_end( _environment );
    
}
