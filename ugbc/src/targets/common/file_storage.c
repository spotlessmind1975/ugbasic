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
 * @brief Emit code for <strong>FILE ... AS ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the storage
 */
/* <usermanual>
@keyword FILE...AS...

@english
This command can be used to move a file from the development computer 
to mass storage. The movement will take place exclusively in the mass 
memory generation phase.

@italian
Questo comando può essere utilizzato per spostare un file dal computer 
di sviluppo nella memoria di massa. Lo spostamento avverrà esclusivamente 
in fase di generazione della memoria di massa.

@syntax FILE [source] AS [target]

@example FILE "file/on/host/file.txt" AS "TEST"

@usedInExample storage_example_01.bas

@target c64
</usermanual> */
void file_storage( Environment * _environment, char * _source_name, char * _target_name ) {

    if ( !_environment->currentStorage ) {
        CRITICAL_STORAGE_NOT_OPENED();
    }

    FileStorage * fileStorage = malloc( sizeof( FileStorage ) );
    fileStorage->sourceName = strdup( _source_name );
    fileStorage->targetName = strdup( _target_name );

    FILE * file = fopen( _source_name, "rb" );
    if ( !file ) {
        CRITICAL_DLOAD_MISSING_FILE( _source_name );
    }
    fseek( file, 0, SEEK_END );
    int size = ftell( file );
    fseek( file, 0, SEEK_SET );
    fclose( file );
    fileStorage->size = size;

    fileStorage->next = _environment->currentStorage->files;
    _environment->currentStorage->files = fileStorage;

}
