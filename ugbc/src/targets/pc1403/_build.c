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

#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

extern char OUTPUT_FILE_TYPE_AS_STRING[][16];

void generate_bin( Environment * _environment ) {

    char commandLine[8*MAX_TEMPORARY_STORAGE];
    char executableName[MAX_TEMPORARY_STORAGE];
    char relName1[MAX_TEMPORARY_STORAGE];
    char relName2[MAX_TEMPORARY_STORAGE];
    char binaryName[MAX_TEMPORARY_STORAGE];
    char listingFileName[MAX_TEMPORARY_STORAGE];

    BUILD_SAFE_REMOVE( _environment, _environment->exeFileName );

    BUILD_TOOLCHAIN_ASXV5PXX_GET_EXECUTABLE_AS61860( _environment, executableName );

    BUILD_TOOLCHAIN_ASXV5PXX_EXEC( _environment, "pc1403", executableName );

    char * p;

    strcopy( relName1, _environment->asmFileName );
    p = strstr( relName1, ".asm" );
    if ( p ) {
        *(p+1) = 'r';
        *(p+2) = 'e';
        *(p+3) = 'l';
        *(p+4) = 0;
    }

    strcopy( relName2, _environment->exeFileName );
    p = strstr( relName2, ".ram" );
    if ( p ) {
        *(p+1) = 'r';
        *(p+2) = 'e';
        *(p+3) = 'l';
        *(p+4) = 0;
    }

	// @mv $(subst /exe/,/asm/,$(@:.ram=.rel)) $(@:.ram=.rel)

    BUILD_SAFE_MOVE( _environment, relName1, relName2 );

    strcopy( binaryName, _environment->exeFileName );
    p = strstr( binaryName, ".ram" );
    if ( p ) {
        *(p+1) = 'b';
        *(p+2) = 'i';
        *(p+3) = 'n';
        *(p+4) = 0;
    }

	// @$(ASLINK) -t $(@:.ram=.rel) >/dev/null 2>/dev/null

    BUILD_TOOLCHAIN_ASXV5PXX_GET_EXECUTABLE_ASLINK( _environment, executableName );

    char pipes[256];

    #ifdef _WIN32
        strcopy( pipes, ">nul 2>nul");
    #else
        strcopy( pipes, ">/dev/null 2>/dev/null");
    #endif

    sprintf( commandLine, "\"%s\" \"-t+%s\" -t \"%s\" %s",
        executableName,
        binaryName,
        relName2,
        pipes );
    if ( system_call( _environment,  commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n");
        printf("Please use option '-I' to install chain tool.\n\n");
        return;
    }; 

}

void generate_ram( Environment * _environment ) {

    char commandLine[8*MAX_TEMPORARY_STORAGE];
    char executableName[MAX_TEMPORARY_STORAGE];
    char binaryName[MAX_TEMPORARY_STORAGE];

    strcopy( binaryName, _environment->exeFileName );
    char * p = strstr( binaryName, ".ram" );
    if ( p ) {
        *(p+1) = 'b';
        *(p+2) = 'i';
        *(p+3) = 'n';
        *(p+4) = 0;
    }

	// @$(PC1403RAM) $(@:.ram=.bin) $(@) >/dev/null 2>/dev/null

    FILE * fin = fopen( binaryName, "rb" );
    FILE * fout = fopen( _environment->exeFileName, "wb" );

    while( !feof( fin ) ) {

        int header = (int)fgetc(fin);
        int size = (((int)fgetc(fin))<<8) + (((int)fgetc(fin)));
        int address = (((int)fgetc(fin))<<8) + (((int)fgetc(fin)));

        if ( header == 0 ) {
            char * content = malloc( size );
            memset( content, 0, size );
            if ( ! fread( content, 1, size, fin ) ) {
                perror( "Unable to read segment");
            }
            fwrite( content, 1, size, fout );
            free( content );
        }

    }

    fclose( fout );
    fclose( fin );

}

void target_linkage( Environment * _environment ) {

    switch( _environment->outputFileType ) {
        case OUTPUT_FILE_TYPE_RAM:
            generate_bin( _environment );
            generate_ram( _environment );
            break;
        default:
            CRITICAL_UNSUPPORTED_OUTPUT_FILE_TYPE( OUTPUT_FILE_TYPE_AS_STRING[_environment->outputFileType] );
    }

}

void target_cleanup( Environment * _environment ) {

    if ( _environment->exeFileName ) {

        char binFileName[MAX_TEMPORARY_STORAGE];

        remove( _environment->configurationFileName );
        remove( _environment->asmFileName );

        if ( _environment->analysis && _environment->listingFileName ) {
            target_analysis( _environment );
        }

    }
    
}