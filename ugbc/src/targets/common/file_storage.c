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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>FILE ... AS ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the storage
 */
/* <usermanual>
@keyword FILE (storage)

@english

The ''FILE'' command, inserted inside a ''BEGIN STORAGE'' - ''ENDSTORAGE'' block, 
allows you to define the content of the mass storage element. The basic syntax requires 
indicating the name of the ''source'' file that will be inserted into the medium. 
If you don't want to use the same name, you can indicate an alias (''AS target'').

@italian
Il comando ''FILE'', inserite all'interno di un blocco ''BEGIN STORAGE'' - 
''ENDSTORAGE'', permette di definire il contenuto dell'elemento di memorizzazione
di massa. La sintassi di base prevede di indicare il nome del file sorgente che 
sarà inserito nel supporto. Se non si vuole utilizzare lo stesso nome, è possibile 
indicare un alias (''AS target'').

@syntax FILE source [AS target]

@example FILE "examples/data.dat"
@example FILE "sprites.png" AS "sprites.dat"

@usedInExample storage_example_01.bas

@seeAlso BEGIN STORAGE
@target all
</usermanual> */
void file_storage( Environment * _environment, char * _source_name, char * _target_name ) {

    if ( !_environment->currentStorage ) {
        CRITICAL_STORAGE_NOT_OPENED();
    }

    FileStorage * fileStorage = malloc( sizeof( FileStorage ) );
    memset( fileStorage, 0, sizeof ( FileStorage ) );

    fileStorage->sourceName = strdup( _source_name );
    if ( _target_name ) {
        fileStorage->targetName = strdup( _target_name );
    } else {
        fileStorage->targetName = basename( _source_name );
    }

    FILE * file = fopen( _source_name, "rb" );
    if ( !file ) {
        CRITICAL_DLOAD_MISSING_FILE( _source_name );
    }
    fseek( file, 0, SEEK_END );
    int size = ftell( file );
    fseek( file, 0, SEEK_SET );
    fclose( file );
    fileStorage->size = size;

    if ( ! _environment->currentStorage->files ) {
        _environment->currentStorage->files = fileStorage;
    } else {
        FileStorage * first = _environment->currentStorage->files;
        while( first->next ) {
            first = first->next;
        }
        first->next = fileStorage;
        
    }

}
