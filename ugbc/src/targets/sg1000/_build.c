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

    BUILD_TOOLCHAIN_Z88DK_EXEC( _environment, "sc3000", executableName, listingFileName, "z80" );

    char * p;

    if ( _environment->listingFileName ) {
        strcopy( binaryName, _environment->asmFileName );
        p = strstr( binaryName, ".asm" );
        if ( p ) {
            *(p+1) = 'l';
            *(p+2) = 'i';
            *(p+3) = 's';
            *(p+4) = 0;
        }
        TRACE2( "  renaming %s to %s", binaryName, _environment->listingFileName );
        BUILD_SAFE_MOVE( _environment, binaryName, _environment->listingFileName );
    }

    strcopy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *(p+1) = 'o';
        *(p+2) = 0;
    }
    remove(binaryName);

    strcopy( binaryName, _environment->asmFileName );
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

    strcopy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *p = 0;
        --p;
        strcat( p, ".bin");
    }

    binaryFile = fopen( binaryName, "wb" );
    fwrite( part, size, 1, binaryFile );
    fclose( binaryFile );

    strcopy( binaryName, _environment->asmFileName );
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

    strcopy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *p = 0;
        --p;
        strcat( p, ".bin");
    }

    binaryFile = fopen( binaryName, "a+b" );
    fwrite( part, size, 1, binaryFile );
    fclose( binaryFile );

    BUILD_SAFE_MOVE( _environment, binaryName, _environment->exeFileName );

    strcopy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        strcat( p, "_data_user.bin");
    }
    remove(binaryName);

    strcopy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        strcat( p, "_code_user.bin");
    }
    remove(binaryName);

}


void target_cleanup( Environment * _environment ) {

    if ( _environment->exeFileName ) {
        char binFileName[MAX_TEMPORARY_STORAGE];

        strcopy( binFileName, _environment->exeFileName );
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
