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
#include "../../libs/msc1.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>DLOAD(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 */
 /* <usermanual>
@keyword DLOAD

@english

The ''DLOAD'' command  load data from a mass storage (normally, a floppy disk) into 
the computer's memory. This data can be programs, numeric data, text, or any 
other information that has previously been saved to disk.

The ''DLOAD'' command was primarily used to load numeric data, text, or 
images for use within a program. Some games allowed you to save the current 
state of the game to a disk using ''DLOAD'' so you could resume playing 
at a later time. 

The syntax allows 
you to load a specific file (''filename'') starting from a specific ''offset'' 
within the file, towards a specific ''address'' in memory for a certain 
number of ''bytes''. Note that the behavior of this instruction strictly 
depends on the target where it is executed. It follows that not all options 
are necessarily available on every target.

The time it takes to load a file depended on the speed of the drive and 
the size of the file. Files loaded had to be in the correct format for 
the computer and the program using them. The amount of data that could 
be loaded was limited by the available RAM.

On the ''atari'' and ''atarixl'' target, it is not possible to omit
the number of bytes and the starting address.

On the ''c64'' and ''c128'' target, you cannot indicate
the offset and the size.

@italian

Il comando ''DLOAD'' carica dati da un archivio di massa (normalmente 
un floppy disk) nella memoria del computer. Questi dati possono 
essere programmi, dati numerici, testo o qualsiasi altra informazione 
precedentemente salvata su disco.

Il comando ''DLOAD'' era utilizzato principalmente per caricare dati 
numerici, testo o immagini da utilizzare all'interno di un programma. 
Alcuni giochi ti consentivano di salvare lo stato corrente del gioco 
su un disco utilizzando ''DLOAD'' in modo da poter riprendere a 
giocare in un secondo momento.

La sintassi ti consente di caricare un file specifico (''nomefile'') 
a partire da uno specifico ''offset'' all'interno del file, verso 
uno specifico ''indirizzo'' in memoria per un certo numero di 
''byte''. Il comportamento di questa istruzione dipende strettamente 
dal target in cui viene eseguita. Ne consegue che non tutte le 
opzioni sono necessariamente disponibili su ogni target.

Il tempo necessario per caricare un file dipende dalla velocità 
dell'unità e dalle dimensioni del file. I file caricati dovevano 
essere nel formato corretto per il computer e il programma che 
li utilizzava. La quantità di dati che potevano essere caricati 
era limitata dalla RAM disponibile.

Sul target ''atari'' e ''atarixl'', non è possibile omettere il 
numero di byte e l'indirizzo di partenza.

@syntax DLOAD filename [FROM offset] [TO address] [SIZE size]

@example DLOAD "test" TO finalAddress SIZE 16

@target c128

@seeAlso DLOAD ERROR

</usermanual> */
/* <usermanual>
@keyword DLOAD ERROR

@english

The ''DLOAD ERROR'' function lets you know whether the last 
''DLOAD'' instruction returned an error or not.

@italian

La funzione ''DLOAD ERROR'' consente di sapere se l'ultima istruzione 
''DLOAD'' ha dato errore o meno.

@syntax = DLOAD ERROR

@target c128

@seeAlso DLOAD

</usermanual> */

void dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _bank, char * _size ) {

    if ( _environment->tenLinerRulesEnforced ) {
        CRITICAL_10_LINE_RULES_ENFORCED( "DLOAD");
    }

    if ( _environment->sandbox ) {
        CRITICAL_SANDBOX_ENFORCED( "DLOAD");
    }

    if ( _offset ) {
        WARNING_DLOAD_IGNORED_OFFSET( _filename );
    }

    if ( _size ) {
        WARNING_DLOAD_IGNORED_SIZE( _filename );
    }

    c128_dload( _environment, _filename, _offset, _address, _size );

}
