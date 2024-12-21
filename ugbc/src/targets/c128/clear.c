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

/* <usermanual>
@keyword CLEAR

@english

The ''CLEAR'' command serves two purposes: the primary semantics of the ''CLEAR'' 
command is to re-initialize (integers) variables to their starting values. 
Which are usually zero but, of course, can be different from zero. At the moment, 
their starting value is equal to the assignment during the definition. Other data 
types (like FLOAT or BIT) are not re-initialized. This is especially useful at the
beginning of a program to ensure that there are no residual values from previous 
executions. 

The other semantics, which is expressed through the numeric parameter, is related to 
the space occupied by the strings. This space is fixed and is used as a sort of 
dynamic "heap". The numeric parameter provides, in fact, the maximum size allocated 
for the strings. This value is equivalent to assigning a value with the 
''DEFINE STRING SPACE'' pragma. Dynamic strings are reinitialized to empty strings
with this command, too. 

The criterion of the size given with this parameter should be to minimize the 
memory footprint in order to leave as much space as possible to the code and 
resources (which shares the same data area). In other words, assuming that the 
available space in the target is 32 KB, and the code and graphical resources 
occupies 20 KB, and that we choose to use the default value on the number of 
dynamic strings for the target (e.g. n=128), the maximum value to give to 
''CLEAR'' will be 32KB - 20KB - (4*n) = 11776 / 2 = 5.888 bytes.

@italian

Il comando ''CLEAR'' ha due scopi: la semantica primaria del comando ''CLEAR''
è quella di reinizializzare le variabili (intere) ai loro valori iniziali.
Che di solito sono zero ma, naturalmente, possono essere diversi da zero. 
Attualmente, il loro valore iniziale è uguale all'assegnazione durante la 
definizione. Altri tipi di dati (come FLOAT o BIT) non vengono reinizializzati. 
Ciò è particolarmente utile all'inizio di un programma per garantire che non 
vi siano valori residui da esecuzioni precedenti.

L'altra semantica, che è espressa tramite il parametro numerico, è relativa allo
spazio occupato dalle stringhe. Questo spazio è fisso e viene utilizzato come 
una sorta di "heap" dinamico. Il parametro numerico fornisce, infatti, la 
dimensione massima allocata per le stringhe. Questo valore equivale ad assegnare 
un valore con il pragma ''DEFINE STRING SPACE''. Anche le stringhe dinamiche 
vengono reinizializzate a stringhe vuote con questo comando.

Il criterio per la dimensione data con questo parametro dovrebbe essere quello 
di minimizzare l'ingombro di memoria per lasciare più spazio possibile per il codice e
le risorse (che condividono la stessa area dati). In altre parole, supponendo che
lo spazio disponibile nel target sia di 32 KB, e che il codice e le risorse grafiche
occupino 20 KB, e che scegliamo di usare il valore predefinito sul numero di
stringhe dinamiche per il target (ad esempio n=128), il valore massimo da dare a
''CLEAR'' sarà 32 KB - 20 KB - (4*n) = 11776 / 2 = 5.888 byte.

@syntax CLEAR size

@example CLEAR 2048

@alias CLR
</usermanual> */

/* <usermanual>
@keyword CLR

@syntax CLR size

@example CLR 2048

@alias CLEAR
</usermanual> */
void clear( Environment * _environment ) {

    cpu_call( _environment, "VARINITCLEAR" );

}
