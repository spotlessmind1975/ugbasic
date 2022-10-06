/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
@keyword STORAGE...ENDSTORAGE

@english
This command can be used to start defining a mass storage. If the selected 
output corresponds to a mass memory (tape, disk, ...) then it will have the 
form described in this structure. It is possible to define more than one 
mass memory, and the executable will be inserted in the first of them.

@italian
Questo comando può essere utilizzato per iniziare la definizione di una 
memoria di massa. Se l'output selezionato corrisponde a una memoria di 
massa (nastro, disco, ...) allora avrà la forma descritta in questa 
struttura. E' possibile definire più di una memoria di massa, e 
l'eseguibile sarà inserito nel primo di essi.

@syntax STORAGE [name]
@syntax ...
@syntax ENDSTORAGE

@example STORAGE "dischetto"
@example ...
@example ENDSTORAGE

@usedInExample storage_example_01.bas

@target c64
</usermanual> */
void begin_storage( Environment * _environment, char * _name, char * _file_name ) {

    if ( _environment->currentStorage ) {
        CRITICAL_STORAGE_NESTED_UNSUPPORTED(_name);
    }

    Storage * storage = malloc( sizeof( Storage ) );
    storage->name = strdup( _name );
    if ( _file_name ) {
        storage->fileName = strdup( _file_name );
    }

    _environment->currentStorage = storage;

}
