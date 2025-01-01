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
 * @brief Emit code for <strong>LOAD MUSIC(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 */
/* <usermanual>
@keyword LOAD MUSIC

@english

The ''LOAD MUSIC'' command allows you to load a music file from the file system 
of the host system and use it, as music, directly in the program. Loading occurs 
at compile time: there is no access to the target system's file system. If multiple 
uploads are made to the same file, a single buffer will still be generated. 

Since it is possible to upload only one file of the same type at a time, it is necessary 
to be able to indicate an "alias" with which to exceed this limit. In this regard, there is also 
the ''AS'' syntax, which allows you to load the same file several times but with different names. 

@italian

@syntax = LOAD MUSIC( filename )
@syntax = LOAD MUSIC( filename AS alias )

@example fugue = LOAD MUSIC("fugue.imf")
@example fugueAnotherCopy = LOAD MUSIC("fugue.imf" as "fugue2")

@target all
</usermanual> */
Variable * music_load( Environment * _environment, char * _filename, char * _alias, int _bank_expansion ) {

    Variable * final = variable_temporary( _environment, VT_MUSIC, 0 );

    if ( _environment->emptyProcedure ) {
        return final;
    }

    if ( _environment->tenLinerRulesEnforced ) {
        CRITICAL_10_LINE_RULES_ENFORCED( "LOAD MUSIC");
    }

    if ( _environment->sandbox ) {
        CRITICAL_SANDBOX_ENFORCED( "LOAD MUSIC");
    }

    LoadedFile * first = _environment->loadedFiles;
    char *lookfor = _filename;
    if ( _alias ) {
        lookfor = _alias;
    }
    while( first ) {
        if ( strcmp(lookfor, first->fileName ) == 0 ) {
            return first->variable;
        }
        first = first->next;
    }

    Variable * result = music_load_to_variable( _environment, _filename, _alias, _bank_expansion );

    LoadedFile * loaded = malloc( sizeof( LoadedFile ) );
    loaded->next = first;
    loaded->variable = result;
    loaded->fileName = lookfor;
    _environment->loadedFiles = loaded;

    if ( _alias ) {
        const_define_numeric( _environment, _alias, UNIQUE_ID );
    }
    
    result->readonly = 1;

    return result;

}
