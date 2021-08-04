/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit code for <strong>LOAD(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 */
/* <usermanual>
@keyword LOAD

@english
The ''LOAD'' command allows you to load a generic binary file from the file system 
of the host system and use it, as a buffer, directly in the program. Loading occurs 
at compile time: there is no access to the target system's file system. If multiple 
uploads are made to the same file, a single buffer will still be generated.

An absolute starting address can be given: in that case, files will be loaded starting
from that position instead of the first free position available.

@italian
Il comando ''LOAD'' permette di caricare un generico file binario dal filesystem del sistema 
host e di utilizzarlo, come buffer, direttamente nel programma. Il caricamento avviene al 
momento della compilazione: non vi sono accessi al file system del sistema target. Se vengono 
svolti più caricamenti nel medesimo file, sarà comunque generato un singolo buffer.

Può essere dato un indirizzo assoluto: in tal caso, i file saranno caricati a partire
da quella posizione invece della prima posizione disponibile.

@syntax = LOAD([filename]{,[at]})

@example testo = LOAD("aiuto.txt")
@example schermata = LOAD("aiuto.txt", 0x8400)

@usedInExample buffers_definition_02.bas

@target all
</usermanual> */
Variable * load( Environment * _environment, char * _filename, int _at ) {

    LoadedFile * first = _environment->loadedFiles;
    while( first ) {
        if ( strcmp(_filename, first->fileName ) == 0 ) {
            return first->variable;
        }
        first = first->next;
    }

    Variable * result = variable_temporary( _environment, VT_BUFFER, "(buffer)" );
    
    FILE * file = fopen( _filename, "rb" );

    if ( !file ) {
        CRITICAL_LOAD_MISSING_FILE( _filename );
    }
    
    fseek( file, 0, SEEK_END );
    int size = ftell( file );
    fseek( file, 0, SEEK_SET );

    char * buffer = malloc( size );

    fread( buffer, size, 1, file );

    fclose( file );

    variable_store_buffer( _environment, result->name, buffer, size, _at );

    LoadedFile * loaded = malloc( sizeof( LoadedFile ) );
    loaded->next = first;
    loaded->variable = result;
    _environment->loadedFiles = loaded;

    return result;

}
