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
    char binaryName[MAX_TEMPORARY_STORAGE];
    char listingFileName[MAX_TEMPORARY_STORAGE];

    BUILD_CHECK_FILETYPE(_environment, OUTPUT_FILE_TYPE_TAP)

    BUILD_SAFE_REMOVE( _environment, _environment->exeFileName );

    BUILD_TOOLCHAIN_Z88DK_GET_EXECUTABLE_Z80ASM( _environment, executableName );

    BUILD_TOOLCHAIN_Z88DK_GET_LISTING_FILE( _environment, listingFileName );

    BUILD_TOOLCHAIN_Z88DK_EXEC( _environment, "zx", executableName, listingFileName );

    strcpy( binaryName, _environment->asmFileName );
    char * p = strstr( binaryName, ".asm" );
    if ( p ) {
        *(p+1) = 'b';
        *(p+2) = 'i';
        *(p+3) = 'n';
    }

    BUILD_TOOLCHAIN_Z88DK_GET_EXECUTABLE_APPMAKE( _environment, executableName );

    char pipes[256];

    #ifdef _WIN32
        strcpy( pipes, ">nul 2>nul");
    #else
        strcpy( pipes, ">/dev/null 2>/dev/null");
    #endif

    sprintf( commandLine, "\"%s\" +zx --org 32768 -b \"%s\"",
        executableName,
        binaryName );

    p = strstr( binaryName, ".bin" );
    if ( p ) {
        *(p+1) = 't';
        *(p+2) = 'a';
        *(p+3) = 'p';
    }

    if ( system_call( _environment,  commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n");
        printf("Please use option '-I' to install chain tool.\n\n");
        return;
    }; 

    system_remove_safe( _environment, _environment->exeFileName );

    rename( binaryName, _environment->exeFileName );

    if ( _environment->listingFileName ) {
        TRACE1( "  listing file = %s", _environment->listingFileName );
        strcpy( binaryName, _environment->asmFileName );
        TRACE1( "  binary file = %s", binaryName );
        p = strstr( binaryName, ".asm" );
        if ( p ) {
            *p = 0;
            --p;
            strcat( p, ".lis");
            TRACE2( "  rename %s to %s", binaryName, _environment->listingFileName );
            rename( binaryName, _environment->listingFileName );
        }

        if ( _environment->profileFileName && _environment->profileCycles ) {

            char binaryName2[MAX_TEMPORARY_STORAGE];
            strcpy( binaryName2, _environment->asmFileName );
            char * p = strstr( binaryName2, ".asm" );
            if ( p ) {
                *(p+1) = 'b';
                *(p+2) = 'i';
                *(p+3) = 'n';
            }

            strcpy( binaryName, _environment->profileFileName );
            if ( _environment->executerFileName ) {
                sprintf(executableName, "%s", _environment->executerFileName );
            } else if( access( "runz80.exe", F_OK ) == 0 ) {
                sprintf(executableName, "%s", "runz80.exe" );
            } else {
                sprintf(executableName, "%s", "runz80" );
            }

            sprintf( commandLine, "\"%s\" -c -p \"%s\" %d -l 8000 \"%s\" -R 8000 -u \"%s\" \"%s\"",
                executableName,
                binaryName,
                _environment->profileCycles ? _environment->profileCycles : 1000000,
                binaryName2,
                _environment->listingFileName,
                pipes );

            if ( system_call( _environment,  commandLine ) ) {
                printf("The profiling of assembly program failed.\n\n");
                return;
            }; 

        }

    }

}

void target_cleanup( Environment * _environment ) {

    if ( _environment->exeFileName ) {

        char binFileName[MAX_TEMPORARY_STORAGE];

        strcpy( binFileName, _environment->exeFileName );
        char * p = strrchr( binFileName, '.' );
        memcpy( p, ".bin", 4 );

        remove( _environment->configurationFileName );
        remove( binFileName );
        remove( _environment->asmFileName );

        if ( _environment->analysis && _environment->listingFileName ) {
            target_analysis( _environment );
        }

    }
    
}
