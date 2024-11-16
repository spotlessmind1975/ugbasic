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
@keyword BEGIN STORAGE...END STORAGE

@english

The ''BEGIN STORAGE..END STORAGE'' allows to begin describing 
the content of a storage media. The syntax of this command
allows to define up to two parameter. The first parameter,
''name'', refers to the internal name of the storage.
The ''filename'', optional, will define the file name
that will contain the "image" of the storage. If omitted,
the program filename will be used, and an additional incremented
number will be appended, one for each storage media.

Note that, for some targets, a special toolchain is needed to
manage this keyword. In particular, for ''cpc'' target you need to 
install and use the correct version of the ''z88dk-appmake'' application. 
Starting from version 1.15.3 of ugBASIC, that is, since 
''BEGIN STORAGE'' was implemented for ''cpc'', it is necessary to use a 
patched version of the z88dk toolchain. The version that can be
obtained from the official release is not powerful enough to include 
external files in the disk image that is created for that target.

You can find out the empowered version looking for a fork of that project, 
or as a module inside ugBASIC. You should recompile it on a specific branch 
(''ugbasic'' branch, precisely). On ugBASIC website and on the UGBASIC-IDE
there is a precompiled version from that version, that can be directly
used.

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

Nota che per alcuni target è necessaria una toolchain speciale per
gestire questa parola chiave. In particolare, per il target ''cpc'' devi
installare e usare la versione corretta dell'applicazione ''z88dk-appmake''.
A partire dalla versione 1.15.3 di ugBASIC, ovvero, poiché
''BEGIN STORAGE'' è stato implementato per ''cpc'', si deve usare una
versione patchata della toolchain z88dk. La versione che può essere
ottenuta dalla release ufficiale non è abbastanza potente da includere
file esterni nell'immagine disco creata per quel target.

E' possibile trovare la versione migliorata cercando un fork di quel progetto,
o come modulo all'interno di ugBASIC. Dovresti ricompilarla su un ramo specifico
(ramo ''ugbasic'', per essere precisi). Sul sito web di ugBASIC e in UGBASIC-IDE
c'è una versione precompilata di quella versione, che può essere
utilizzata direttamente.

@syntax BEGIN STORAGE name [AS filename] ... END STORAGE
@syntax STORAGE name [AS filename] ... END STORAGE

@example BEGIN STORAGE "dischetto"
@example ...
@example ENDSTORAGE

@usedInExample storage_example_01.bas

@alias STORAGE...END STORAGE

@target atari c128 c64 c64reu coco coco3 cpc msx1 vic20 
</usermanual> */
/* <usermanual>
@keyword STORAGE...END STORAGE

@english

@italian

@syntax STORAGE name [AS filename] .. END STORAGE
@syntax STORAGE name [AS filename] .. END STORAGE

@example BEGIN STORAGE "dischetto"
@example ...
@example ENDSTORAGE

@usedInExample storage_example_01.bas

@alias BEGIN STORAGE...END STORAGE

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
