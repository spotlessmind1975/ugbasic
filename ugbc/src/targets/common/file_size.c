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
@keyword FILE SIZE

@english

The command ''FILE SIZE'' allows you to know the size of the file previously inserted 
into a storage. The parameter is the name of the file that has been inserted into 
the storage.

@italian

Il comando ''FILE SIZE'' consente di conoscere la dimensione del file inserito, 
in precedenza, in uno storage. Il parametro è il nome del file che è stato inserito 
all'interno dello storage.

@syntax = FILE SIZE( target )

@example x = FILE SIZE( "file.dat" )

@alias FILESIZE
@alias FSIZE
@target all
</usermanual> */

/* <usermanual>
@keyword FILESIZE

@english

@italian

@syntax = FILESIZE( target )

@example x = FILESIZE( "file.dat" )

@alias FILE SIZE
@alias FSIZE
@target all
</usermanual> */

/* <usermanual>
@keyword FSIZE

@english

@italian

@syntax = FSIZE( target )

@example x = FSIZE( "file.dat" )

@alias FILESIZE
@alias FILE SIZE
@target all
</usermanual> */

int file_size( Environment * _environment, char * _target_name ) {

    Storage * storage = _environment->storage;

    int i=0;
    while( storage ) {
        FileStorage * fileStorage = storage->files;
        while( fileStorage ) {
            if ( strcmp( _target_name, fileStorage->targetName ) == 0 ) {
                return fileStorage->size;
            }
            fileStorage = fileStorage->next;
        }
        storage = storage->next;
    }

    CRITICAL_FILE_SIZE_ON_MISSING_FILE( _target_name );

}
