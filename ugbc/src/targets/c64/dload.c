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
The ''DLOAD'' command allows you to load a file, present on the target file system, 
directly into memory as a string. The string destination is required because 
the file size cannot be known in advance. It follows that, at the moment, 
it is possible to upload files with a maximum size of 128/256 characters, 
depending on the target.

@italian
Il comando ''DLOAD'' permette di caricare un file, presente sul file system target, 
direttamente in memoria come stringa. La destinazione stringa è necessaria perché 
non è possibile conoscere, in anticipo, la dimensione del file. Ne consegue che, 
al momento, è possibile caricare file di dimensioni massime pari a 128/256 
caratteri, a seconda del target.

@syntax = DLOAD([filename])

@example testo = LOAD("aiuto.txt")

@usedInExample storage_example_01.bas

@target all
</usermanual> */
Variable * dload( Environment * _environment, char * _target_name ) {

    if ( _environment->tenLinerRulesEnforced ) {
        CRITICAL_10_LINE_RULES_ENFORCED( "DLOAD");
    }

    Variable * target_name = variable_retrieve_or_define( _environment, _target_name, VT_DSTRING, 0 );
    Variable * result = variable_temporary( _environment, VT_DSTRING, "(result of DLOAD)");

    char resultString[MAX_TEMPORARY_STORAGE]; sprintf( resultString, " " );

    variable_store_string(_environment, result->name, resultString );

    c64_dload( _environment, target_name->realName, result->realName );

    return result;

}
