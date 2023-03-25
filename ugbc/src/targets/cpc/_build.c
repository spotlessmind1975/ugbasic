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

    char commandLine[2*MAX_TEMPORARY_STORAGE];
    char executableName[MAX_TEMPORARY_STORAGE];
    char binaryName[MAX_TEMPORARY_STORAGE];
    char diskName[MAX_TEMPORARY_STORAGE];
    char listingFileName[MAX_TEMPORARY_STORAGE];
    char binaryName2[MAX_TEMPORARY_STORAGE];
    
    BUILD_CHECK_FILETYPE(_environment, OUTPUT_FILE_TYPE_DSK)

    BUILD_SAFE_REMOVE( _environment, _environment->exeFileName );

    BUILD_TOOLCHAIN_Z88DK_GET_EXECUTABLE_Z80ASM( _environment, executableName );

    BUILD_TOOLCHAIN_Z88DK_GET_LISTING_FILE( _environment, listingFileName );

    BUILD_TOOLCHAIN_Z88DK_EXEC( _environment, "cpc", executableName, listingFileName );

    char * p;

    strcpy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *(p+1) = 'o';
        *(p+2) = 0;
    }
    system_remove_safe( _environment, binaryName );

    BUILD_TOOLCHAIN_Z88DK_GET_EXECUTABLE_APPMAKE( _environment, executableName );

    char pipes[256];

    #ifdef _WIN32
        strcpy( pipes, ">nul 2>nul");
    #else
        strcpy( pipes, ">/dev/null 2>/dev/null");
    #endif

    strcpy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *(p+1) = 'b';
        *(p+2) = 'i';
        *(p+3) = 'n';
        *(p+4) = 0;
    }

    strcpy( binaryName2, _environment->asmFileName );
    p = strrchr( binaryName2, '/' );
    if ( !p ) {
        p = strrchr( binaryName2, '\\' );
    }
    if ( p ) {
        strcpy( p+1, "main.bin" );
    } else {
        strcpy( binaryName2, "main.bin" );
    }

    strcpy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *(p+1) = 'b';
        *(p+2) = 'i';
        *(p+3) = 'n';
        *(p+4) = 0;
    }

    system_remove_safe( _environment, binaryName2 );

    TRACE2( "  renaming %s to %s", binaryName, binaryName2 );
    
    rename( binaryName, binaryName2 );

    strcpy( binaryName, _environment->asmFileName );
    p = strrchr( binaryName, '/' );
    if ( !p ) {
        p = strrchr( binaryName, '\\' );
    }
    if ( p ) {
        strcpy( p+1, "main.bin" );
    } else {
        strcpy( binaryName, "main.bin" );
    }

    system_remove_safe( _environment, _environment->exeFileName );

    strcpy( diskName, _environment->exeFileName );
    p = strrchr( diskName, '/' );
    if ( !p ) {
        p = strrchr( diskName, '\\' );
    }
    if ( p ) {
        strcpy( p+1, "main.com" );
    } else {
        strcpy( diskName, "main.com" );
    }

    TRACE1( "exeFileName = %s", _environment->exeFileName );
    TRACE1( "diskName    = %s", diskName );

    sprintf( commandLine, "\"%s\" +cpc --org 4608 --exec 4608 --disk -b \"%s\" -o \"%s\" %s",
        executableName,
        binaryName,
        diskName,
        pipes );

    if ( system_call( _environment,  commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n");
        printf("Please use option '-I' to install chain tool.\n\n");
        return;
    }; 

    system_remove_safe( _environment, diskName );

    strcpy( diskName, _environment->asmFileName );
    p = strrchr( diskName, '/' );
    if ( !p ) {
        p = strrchr( diskName, '\\' );
    }
    if ( p ) {
        strcpy( p+1, "main.dsk" );
    } else {
        strcpy( diskName, "main.dsk" );
    }

    rename( diskName, _environment->exeFileName );

    strcpy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        strcat( p, ".bin");
    } else {
        strcpy( binaryName, "main.bin" );
    }
 
    system_remove_safe( _environment, binaryName );

}

void target_cleanup( Environment * _environment ) {

    if ( _environment->exeFileName ) {
        char binFileName[MAX_TEMPORARY_STORAGE];

        strcpy( binFileName, _environment->exeFileName );
        char * p = strrchr( binFileName, '.' );
        memcpy( p, ".bin", 4 );

        remove( binFileName );
        remove( _environment->asmFileName );

        if ( _environment->analysis && _environment->listingFileName ) {
            target_analysis( _environment );
        }

    }

}
