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
 * @brief Emit code for <strong>STORAGE ... ENDSTORAGE</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the storage
 */
/* <usermanual>
@keyword BEGIN STORAGE

@english

The ''BEGIN STORAGE'' allows to begin describing 
the content of a storage media. The syntax of this command
allows to define up to two parameter. The first parameter,
''name'', refers to the internal name of the storage.
The ''filename'', optional, will define the file name
that will contain the "image" of the storage. If omitted,
the program filename will be used, and an additional incremented
number will be appended, one for each storage media.


@italian
Il comando ''BEGIN STORAGE'' consente di iniziare a descrivere 
il contenuto di un supporto di memorizzazione. La sintassi di 
questo comando consente di definire fino a due parametri. Il 
primo parametro, ''name'', si riferisce al nome interno del 
supporto di memorizzazione. Il comando ''filename'', 
facoltativo, definirà il nome del file che conterrà l'"immagine" 
del supporto di memorizzazione. Se omesso, verrà utilizzato il 
nome del file del programma e verrà aggiunto un numero 
incrementato aggiuntivo, uno per ciascun supporto di 
memorizzazione.

@syntax BEGIN STORAGE [name] [AS filename]
@syntax STORAGE [name] [AS filename]

@example BEGIN STORAGE "dischetto"
@example ...
@example ENDSTORAGE

@usedInExample storage_example_01.bas

@alias STORAGE
@seeAlso ENDSTORAGE

@target atari c128 c64 c64reu coco coco3 cpc msx1 vic20 
</usermanual> */
void begin_storage( Environment * _environment, char * _name, char * _file_name ) {

    if ( _environment->currentStorage ) {
        CRITICAL_STORAGE_NESTED_UNSUPPORTED(_name);
    }

    Storage * storage = malloc( sizeof( Storage ) );
    memset( storage, 0, sizeof ( Storage ) );
    storage->name = strdup( _name );
    if ( _file_name ) {
        storage->fileName = strdup( _file_name );
    }

    _environment->currentStorage = storage;

}
