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
#include "../../libs/msc1.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

 /* <usermanual>
@keyword CHAIN

@english

The ''CHAIN'' ​​command is a powerful tool used to load and execute another ugBASIC 
program from mass storage (such as a floppy disk), terminating the current program. 
This feature is useful on computers with limited memory, as it allows large 
applications to be broken down into smaller, more manageable modules or programs 
that can be "chained" together. Using ''CHAIN'' ​​allows you to create complex 
programs that would otherwise not fit entirely into the available RAM.

The ''CHAIN'' ​​command syntax requires a ''filename'', which should represent the binary 
file located on the mass storage device. It is therefore not the name of the BASIC source
file. When this instruction is executed, the current program is overwritten with the 
loaded one and executed from the beginning.

Therefore, the ugBASIC program to be called with the ''CHAIN'' ​​command must first be 
compiled into the specified binary format. Only then should this compiled file be 
inserted into the ''STORAGE'' definition, and the symbolic name can be used to 
load the program.

Finally, it is important to note that the program to be loaded must also use the 
''CHAIN'' ​​command or, alternatively, use the ''DEFINE CHAIN'' ​​directive at the 
head of the program.

@italian

Il comando ''CHAIN'' è un potente strumento utilizzato per caricare ed eseguire un 
altro programma ugBASIC dalla memoria di massa (come un disco floppy), terminando 
l'esecuzione del programma corrente. Questa funzionalità è utile nei computer con 
memoria limitata, in quanto consente di suddividere grandi applicazioni in moduli 
o programmi più piccoli e gestibili, che potevano essere "incatenati" tra loro. 
L'uso di ''CHAIN'' permette di creare programmi complessi che non avrebbero potuto 
essere caricati interamente nella RAM disponibile. 

La sintassi del comando ''CHAIN'' prevede un ''filename'', che dovrebbe rappresentare 
il file binario che si trova sul sistema di memorizzazione di massa. Non è, quindi, 
il nome del file BASIC. Quando questa istruzione viene eseguita, il programma 
corrente viene sovrascritto con quello caricato, e viene eseguito dall'inizio.

Ne consegue che il programma BASIC da richiamare con il comando ''CHAIN'' va, prima 
di tutto, compilato nel formato binario specifico. Solo in seguito tale file 
compilato andrà inserito all'interno della definizione dello STORAGE, e il nome 
simbolico potrà essere utilizzato per caricare il programma.

E' importante, infine, notare che il programma che andrà caricato dovrà utilizzare 
anch'esso il comando ''CHAIN'' oppure, in alternativa, usare la direttiva 
''DEFINE CHAIN'' in testa al programma.

@syntax CHAIN filename

@example CHAIN "t1"

@target atari
@target c64
@target c128
@target cpc
</usermanual> */
void chain( Environment * _environment, char * _filename ) {

    if ( _environment->emptyProcedure ) {
        return;
    }

    atari_chain( _environment, _filename );

}
