/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
    char binaryName[MAX_TEMPORARY_STORAGE];
    char originalFileName[MAX_TEMPORARY_STORAGE];

    if (  _environment->outputFileType != OUTPUT_FILE_TYPE_DSK && _environment->outputFileType != OUTPUT_FILE_TYPE_BIN ) {
        CRITICAL_UNSUPPORTED_OUTPUT_FILE_TYPE( OUTPUT_FILE_TYPE_AS_STRING[_environment->outputFileType] )
    }

    BUILD_SAFE_REMOVE( _environment, _environment->exeFileName );

    if ( _environment->outputFileType == OUTPUT_FILE_TYPE_DSK ) {
        strcpy( originalFileName, _environment->exeFileName );
        strcpy( binaryName, _environment->exeFileName );
        char * p = strstr( binaryName, ".dsk" );
        if ( p ) {
            strcpy( p, ".bin" );
        }
        strcpy( _environment->exeFileName, binaryName );
    }

    BUILD_TOOLCHAIN_ASM6809_GET_EXECUTABLE( _environment, executableName );

    BUILD_TOOLCHAIN_ASM6809_GET_LISTING_FILE( _environment, listingFileName );

    BUILD_TOOLCHAIN_ASM6809EXEC( _environment, "-C", 0x2A00, executableName, listingFileName );

    if ( _environment->outputFileType == OUTPUT_FILE_TYPE_DSK ) {
        strcpy( _environment->exeFileName, originalFileName );
        BUILD_TOOLCHAIN_DECB_GET_EXECUTABLE( _environment, executableName );
        BUILD_TOOLCHAIN_DECB( _environment, executableName, binaryName );
        BUILD_SAFE_REMOVE( _environment, binaryName );
    }

    if ( _environment->listingFileName ) {

        if ( _environment->profileFileName && _environment->profileCycles ) {
            if ( _environment->executerFileName ) {
                sprintf(executableName, "%s", _environment->executerFileName );
            } else if( access( "run6809.exe", F_OK ) == 0 ) {
                sprintf(executableName, "%s", "run6809.exe" );
            } else {
                sprintf(executableName, "%s", "run6809" );
            }

            sprintf( commandLine, "\"%s\" -i \"%s\" -R 2800 -C -l 0 \"%s\" -p \"%s\" %d",
                executableName,
                _environment->listingFileName,
                _environment->exeFileName,
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

void target_cleanup( Environment * _environment ) {

    remove( _environment->asmFileName );

    if ( _environment->analysis && _environment->listingFileName ) {
        target_analysis( _environment );
    }

}
