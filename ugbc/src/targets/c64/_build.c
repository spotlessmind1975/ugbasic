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

void generate_prg( Environment * _environment ) {

    char commandLine[8*MAX_TEMPORARY_STORAGE];
    char executableName[MAX_TEMPORARY_STORAGE];
    char listingFileName[MAX_TEMPORARY_STORAGE];

    BUILD_SAFE_REMOVE( _environment, _environment->exeFileName );

    BUILD_TOOLCHAIN_CC65_GET_EXECUTABLE( _environment, executableName );

    BUILD_TOOLCHAIN_CC65_GET_LISTING_FILE( _environment, listingFileName );

    BUILD_TOOLCHAIN_CC65_EXEC( _environment, "c64", executableName, listingFileName, "" );

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

            sprintf( commandLine, "\"%s\" -X 0000 -R 080d -l 07ff \"%s\" -u \"%s\" -p \"%s\" %d",
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

void generate_d64( Environment * _environment ) {

    FILE * prgHandle = fopen(_environment->exeFileName, "rb");
    fseek( prgHandle, 0, SEEK_END );
    int prgSize = ftell( prgHandle );
    fseek( prgHandle, 0, SEEK_SET );
    unsigned char * prgContent = malloc( prgSize );
    (void)!fread( prgContent, prgSize, 1, prgHandle );
    fclose( prgHandle );

    remove(_environment->exeFileName);

    Storage * storage = _environment->storage;

    if ( !storage ) {
        D64Handle * handle = d64_create( CBMDOS );
        d64_write_file( handle, "MAIN", PRG, prgContent, prgSize );
        d64_output( handle, _environment->exeFileName );
        d64_free( handle );
    } else {
        int i=0;
        while( storage ) {
            D64Handle * handle = d64_create( CBMDOS );
            if ( i == 0 ) {
                d64_write_file( handle, "MAIN", PRG, prgContent, prgSize );
            }
            FileStorage * fileStorage = storage->files;
            while( fileStorage ) {
                FILE * file = fopen( fileStorage->sourceName, "rb" );
                if ( !file ) {
                    CRITICAL_DLOAD_MISSING_FILE( fileStorage->sourceName );
                }
                fseek( file, 0, SEEK_END );
                int size = ftell( file );
                fseek( file, 0, SEEK_SET );
                char * buffer;
                if ( size > 255 ) {
                    buffer = malloc( size + 3 );
                    buffer[0] = 1;
                    buffer[1] = (size & 0xff);
                    buffer[2] = ((size>>8) & 0xff);
                    (void)!fread( &buffer[3], size, 1, file );
                    size += 3;
                } else {
                    buffer = malloc( size + 2 );
                    buffer[0] = 0;
                    buffer[1] = (size & 0xff);
                    (void)!fread( &buffer[2], size, 1, file );
                    size += 2;
                }
                fclose( file );
                d64_write_file( handle, fileStorage->targetName, PRG, buffer, size );
                fileStorage = fileStorage->next;
            }
            char buffer[MAX_TEMPORARY_STORAGE];
            char filemask[MAX_TEMPORARY_STORAGE];
            strcpy( filemask, _environment->exeFileName );
            char * basePath = strrchr( filemask, PATH_SEPARATOR );
            if ( basePath ) {
                ++basePath;
                *basePath = 0;
                if ( storage->fileName ) {
                    strcat( basePath, storage->fileName );
                } else {
                    strcat( basePath, "disk%d.d64" );
                }
            } else {
                if ( storage->fileName ) {
                    strcpy( filemask, storage->fileName );
                } else {
                    strcpy( filemask, "disk%d.d64" );
                }
            }
            sprintf( buffer, filemask, i );
            if ( !strstr( buffer, ".d64" ) ) {
                strcat( buffer, ".d64" );
            }
            d64_output( handle, buffer );
            d64_free( handle );
            storage = storage->next;
            ++i;
        }        
    }

}

/**
 * @brief Convert C64's assembly to executable
 * 
 * @param _environment 
 */
void target_linkage( Environment * _environment ) {

    switch( _environment->outputFileType ) {
        case OUTPUT_FILE_TYPE_PRG:
            generate_prg( _environment );
            break;
        case OUTPUT_FILE_TYPE_D64:
            generate_prg( _environment );
            generate_d64( _environment );
            break;
        default:
            CRITICAL_UNSUPPORTED_OUTPUT_FILE_TYPE( OUTPUT_FILE_TYPE_AS_STRING[_environment->outputFileType] );
    }

}

void target_cleanup( Environment * _environment ) {

    remove( _environment->configurationFileName );
    remove( _environment->asmFileName );

    if ( _environment->analysis && _environment->listingFileName ) {
        target_analysis( _environment );
    }

}
