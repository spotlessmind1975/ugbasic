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

Inside a ''BEGIN STORAGE...END STORAGE'' block, the ''FILE'' command plays 
a crucial role in the process of embedding external data directly into the 
storage medium you are defining while compiling your program. Imagine you 
want to include a set of configuration data or any other static file 
directly into your program's storage medium, the ''FILE'' command allows 
you to do just that.

The basic syntax is to indicate the name of the source file that will be 
inserted into the media. If you do not want to use the same name, you can 
indicate an alias (''AS target'').

The addition of the ''CSV OF type'' statement is a powerful feature that 
allows you to include Comma Separated Values (CSV) files and specify the 
data type of each column. Instead of treating the CSV file as a simple 
block of bytes (as the ''FILE'' statement alone would), the compiler will 
parse the contents of the CSV file and convert it into a more structured 
internal representation that is ready for use by your program. The kind
of structure will be described by the datatype ''type''.

@italian
All'interno di un blocco ''BEGIN STORAGE...END STORAGE'', il comando 
''FILE'' svolge un ruolo cruciale nel processo di inserimento di dati 
esterni direttamente nel supporto di memorizzazione che si sta definendo 
durante la compilazione del programma. Immaginate di voler includere un set
di dati di configurazione o qualsiasi altro file statico direttamente nel 
supporto di memorizzazione del programma: il comando ''FILE'' vi permette 
di fare proprio questo.

La sintassi di base consiste nell'indicare il nome del file sorgente che 
verrà inserito nel supporto. Se non si desidera utilizzare lo stesso nome, 
è possibile indicare un alias (''AS target'').

L'aggiunta dell'istruzione ''CSV OF type'' è una potente funzionalità che 
consente di includere file con valori separati da virgola (CSV) e di 
specificare il tipo di dati di ciascuna colonna. Invece di trattare il 
file CSV come un semplice blocco di byte (come farebbe la sola istruzione 
''FILE''), il compilatore analizzerà il contenuto del file CSV e lo 
convertirà in una rappresentazione interna più strutturata, pronta per l'uso 
da parte del programma. Il tipo di struttura sarà descritto dal tipo 
di dati ''type''.

@syntax FILE source [AS target] [CSV OF type]

@example FILE "examples/data.dat"
@example FILE "sprites.png" AS "sprites.dat"
@example FILE "examples/data.csv" CSV OF BYTE
@example BEGIN TYPE point
@example     x AS POSITION
@example     x AS POSITION
@example END TYPE point
@example FILE "examples/structure.csv" CSV OF point

@usedInExample storage_example_01.bas

@seeAlso BEGIN STORAGE
@target all
</usermanual> */
void file_storage( Environment * _environment, char * _source_name, char * _target_name, FileStorageFormat _format, VariableType _type ) {

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

    switch( _format ) {
        case FSF_BINARY: {
            FILE * file = fopen( _source_name, "rb" );
            if ( !file ) {
                CRITICAL_DLOAD_MISSING_FILE( _source_name );
            }
            fseek( file, 0, SEEK_END );
            int size = ftell( file );
            fseek( file, 0, SEEK_SET );
            fclose( file );
            fileStorage->size = size;
            break;
        }
        case FSF_CSV: {
            int size, count;
            fileStorage->content = file_read_csv( _environment, _source_name, _type, &size, &count );
            fileStorage->size = size;
            break;
        }
    }

    if ( ! _environment->currentStorage->files ) {
        _environment->currentStorage->files = fileStorage;
    } else {
        FileStorage * first = _environment->currentStorage->files;
        while( first->next ) {
            first = first->next;
        }
        first->next = fileStorage;
    }

    _environment->currentFileStorage = fileStorage;

}
