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

extern char OUTPUT_FILE_TYPE_AS_STRING[][16];

void target_linkage( Environment * _environment ) {

    char commandLine[8*MAX_TEMPORARY_STORAGE];
    char executableName[MAX_TEMPORARY_STORAGE];
    char listingFileName[MAX_TEMPORARY_STORAGE];

    BUILD_SAFE_REMOVE( _environment, _environment->exeFileName );

    BUILD_CHECK_FILETYPE(_environment, OUTPUT_FILE_TYPE_PRG)

    BUILD_TOOLCHAIN_CC65_GET_EXECUTABLE( _environment, executableName );

    BUILD_TOOLCHAIN_CC65_GET_LISTING_FILE( _environment, listingFileName );

    BUILD_TOOLCHAIN_CC65_EXEC( _environment, "c128", executableName, listingFileName, "" );

    char objectFileName[MAX_TEMPORARY_STORAGE];
    strcpy( objectFileName, _environment->asmFileName );
    char * p = strstr(objectFileName, ".asm");
    if ( p ) {
        strcpy( p, ".o" );
        remove( objectFileName );
    }

    if ( _environment->listingFileName ) {

        if ( _environment->profileFileName ) {
            if ( _environment->executerFileName ) {
                sprintf(executableName, "%s", _environment->executerFileName );
            } else if( access( "run6502.exe", F_OK ) == 0 ) {
                sprintf(executableName, "%s", "run6502.exe" );
            } else {
                sprintf(executableName, "%s", "run6502" );
            }

            sprintf( commandLine, "\"%s\" -X 0000 -R 1c0d -l 1bff \"%s\" -u \"%s\" -p \"%s\" %d",
                executableName,
                _environment->exeFileName,
                _environment->listingFileName,
                _environment->profileFileName,
                _environment->profileCycles ? _environment->profileCycles : 1000000
                );

            if ( system_call( _environment,  commandLine ) ) {
                printf("The profiling of assembly program failed.\n\n");
                return;
            }; 

        }
    
    }

}

void target_finalize( Environment * _environment ) {

}

void target_cleanup( Environment * _environment ) {

    remove( _environment->configurationFileName );
    remove( _environment->asmFileName );

    if ( _environment->analysis && _environment->listingFileName ) {
        target_analysis( _environment );
    }

}
