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
 * @brief Emit code for <strong>LOAD MUSIC(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 */
/* <usermanual>
@keyword LOAD MUSIC

@english

@italian

@syntax = LOAD MUSIC([filename])
@syntax = LOAD MUSIC([filename] AS [alias])

@example fugue = LOAD MUSIC("fugue.imf")
@example fugueAnotherCopy = LOAD MUSIC("fugue.imf" as "fugue2")

@target all
</usermanual> */
Variable * music_load( Environment * _environment, char * _filename, char * _alias, int _bank_expansion ) {

    if ( _environment->tenLinerRulesEnforced ) {
        CRITICAL_10_LINE_RULES_ENFORCED( "LOAD MUSIC");
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

    Variable * result = variable_temporary( _environment, VT_MUSIC, "(buffer)" );
    
    FILE * file = fopen( _filename, "rb" );

    if ( !file ) {
        CRITICAL_LOAD_MISSING_FILE( _filename );
    }
    
    fseek( file, 0, SEEK_END );
    int size = ftell( file );
    fseek( file, 0, SEEK_SET );

    char * buffer = malloc( size );

    (void)!fread( buffer, size, 1, file );

    fclose( file );

    if ( _bank_expansion && _environment->expansionBanks ) {

        Bank * bank = _environment->expansionBanks;

        while( bank ) {
            if ( bank->remains > result->size ) {
                break;
            }
            bank = bank->next;
        } 

        if ( ! bank ) {
            CRITICAL_EXPANSION_OUT_OF_MEMORY_LOADING( _filename );
        }

        result->bankAssigned = bank->id;
        result->absoluteAddress = bank->address;
        result->residentAssigned = _bank_expansion;
        result->variableUniqueId = UNIQUE_RESOURCE_ID;
        memcpy( &bank->data[bank->address], result->valueBuffer, result->size );

        bank->address += result->size;
        bank->remains -= result->size;
        if ( _environment->maxExpansionBankSize[_bank_expansion] < result->size ) {
            _environment->maxExpansionBankSize[_bank_expansion] = result->size;
        }

    }

    variable_store_buffer( _environment, result->name, buffer, size, 0 );

    LoadedFile * loaded = malloc( sizeof( LoadedFile ) );
    loaded->next = first;
    loaded->variable = result;
    loaded->fileName = lookfor;
    _environment->loadedFiles = loaded;

    if ( _alias ) {
        const_define_numeric( _environment, _alias, UNIQUE_ID );
    }
    
    return result;

}
