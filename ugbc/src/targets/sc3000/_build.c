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
    char binaryName[MAX_TEMPORARY_STORAGE];
    char listingFileName[MAX_TEMPORARY_STORAGE];

    BUILD_CHECK_FILETYPE(_environment, OUTPUT_FILE_TYPE_ROM)

    BUILD_SAFE_REMOVE( _environment, _environment->exeFileName );

    BUILD_TOOLCHAIN_Z88DK_GET_EXECUTABLE_Z80ASM( _environment, executableName );

    BUILD_TOOLCHAIN_Z88DK_GET_LISTING_FILE( _environment, listingFileName );

    BUILD_TOOLCHAIN_Z88DK_EXEC( _environment, "sc3000", executableName, listingFileName );

    char pipes[256];

    #ifdef _WIN32
        strcpy( pipes, ">nul 2>nul");
    #else
        strcpy( pipes, ">/dev/null 2>/dev/null");
    #endif

    strcpy( binaryName, _environment->asmFileName );
    char * p = strstr( binaryName, ".asm" );
    if ( p ) {
        *(p+1) = 'o';
        *(p+2) = 0;
    }
    remove(binaryName);

    strcpy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *p = 0;
        --p;
        strcat( p, "_code_user.bin");
    }

    FILE * binaryFile = fopen( binaryName, "rb" );
    fseek( binaryFile, 0, SEEK_END );
    long size = ftell( binaryFile );
    fseek( binaryFile, 0, SEEK_SET );
    char * part = malloc( size );
    (void)!fread( part, size, 1, binaryFile );
    fclose( binaryFile );

    strcpy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *p = 0;
        --p;
        strcat( p, ".bin");
    }

    binaryFile = fopen( binaryName, "wb" );
    fwrite( part, size, 1, binaryFile );
    fclose( binaryFile );

    strcpy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *p = 0;
        --p;
        strcat( p, "_data_user.bin");
    }

    binaryFile = fopen( binaryName, "rb" );
    fseek( binaryFile, 0, SEEK_END );
    size = ftell( binaryFile );
    fseek( binaryFile, 0, SEEK_SET );
    part = malloc( size );
    (void)!fread( part, size, 1, binaryFile );
    fclose( binaryFile );

    strcpy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *p = 0;
        --p;
        strcat( p, ".bin");
    }

    binaryFile = fopen( binaryName, "a+b" );
    fwrite( part, size, 1, binaryFile );
    fclose( binaryFile );

    remove( _environment->exeFileName );

    rename( binaryName, _environment->exeFileName );

    if ( _environment->listingFileName ) {
        strcpy( binaryName, _environment->asmFileName );
        p = strstr( binaryName, ".asm" );
        if ( p ) {
            *p = 0;
            --p;
            strcat( p, ".lis");
            rename( binaryName, _environment->listingFileName );
        }

        if ( _environment->profileFileName ) {
            strcpy( binaryName, _environment->profileFileName );
            if ( _environment->executerFileName ) {
                sprintf(executableName, "%s", _environment->executerFileName );
            } else if( access( "runz80.exe", F_OK ) == 0 ) {
                sprintf(executableName, "%s", "runz80.exe" );
            } else {
                sprintf(executableName, "%s", "runz80" );
            }

            sprintf( commandLine, "\"%s\" -c -p \"%s\" %d -l 0000 \"%s\" -R 0000 -u \"%s\" \"%s\"",
                executableName,
                binaryName,
                _environment->profileCycles ? _environment->profileCycles : 1000000,
                _environment->exeFileName,
                _environment->listingFileName,
                pipes );

            if ( system_call( _environment,  commandLine ) ) {
                printf("The profiling of assembly program failed.\n\n");
                return;
            }; 

        }

    }

    strcpy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        strcat( p, "_data_user.bin");
    }
    remove(binaryName);

    strcpy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        strcat( p, "_code_user.bin");
    }
    remove(binaryName);

}

void target_finalize( Environment * _environment ) {

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