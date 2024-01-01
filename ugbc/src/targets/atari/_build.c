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

#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

#include "../../../data/atari/dos25_bootcode.c"
#include "../../../data/atari/dos25_dos_sys.c"
#include "../../../data/atari/dos25_dup_sys.c"

extern char OUTPUT_FILE_TYPE_AS_STRING[][16];

void generate_xex( Environment * _environment ) {

    char commandLine[8*MAX_TEMPORARY_STORAGE];
    char executableName[MAX_TEMPORARY_STORAGE];
    char listingFileName[MAX_TEMPORARY_STORAGE];

    BUILD_SAFE_REMOVE( _environment, _environment->exeFileName );

    BUILD_TOOLCHAIN_CC65_GET_EXECUTABLE( _environment, executableName );

    BUILD_TOOLCHAIN_CC65_GET_LISTING_FILE( _environment, listingFileName );

    BUILD_TOOLCHAIN_CC65_EXEC( _environment, "atari", executableName, listingFileName, "" );

    if ( _environment->listingFileName ) {

        if ( _environment->profileFileName && _environment->profileCycles ) {
            if ( _environment->executerFileName ) {
                sprintf(executableName, "%s", _environment->executerFileName );
            } else if( access( "run6502.exe", F_OK ) == 0 ) {
                sprintf(executableName, "%s", "run6502.exe" );
            } else {
                sprintf(executableName, "%s", "run6502" );
            }

            sprintf( commandLine, "\"%s\" -c atari -X 0000 -R 2000 -l 1ffa \"%s\" -u \"%s\" -p \"%s\" %d",
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

static void autorun_atr( Environment * _environment, char * _atr_image, char * _filename ) {

    int i, j;

    FILE * diskIn = fopen( _atr_image, "rb" );

    if (diskIn == NULL) {
        return;
    }

    fseek( diskIn, 0, SEEK_END );
    int diskSize = ftell( diskIn );
    fseek( diskIn, 0, SEEK_SET );

    char * disk = malloc( diskSize );

    if (disk == NULL) {
        return;
    }

    if (fread( disk, 1, diskSize, diskIn) != diskSize ) {
        return;
    };

    fclose(diskIn);

    int found = 0;
    for (i = 0; i < diskSize; ++i) {
        for (j = 0; j < 11; ++j) {
            if (disk[i+j] != _filename[j]) {
                break;
            }
        }
        if (j == 11) {
            memcpy(&disk[i], "AUTORUN SYS", 11);
            i += 11;
            found = 1;
        }
    }

    FILE * diskOut = fopen( _atr_image, "wb" );

    if ( diskOut == NULL ) {

        return;
    }

    fwrite( disk, 1, diskSize, diskOut );

    fclose(diskOut);

}

void generate_atr( Environment * _environment ) {

    char dir2AtrExecutableName[MAX_TEMPORARY_STORAGE];
    BUILD_TOOLCHAIN_DIR2ATR_GET_EXECUTABLE( _environment, dir2AtrExecutableName );

    Storage * storage = _environment->storage;

    char temporaryPath[MAX_TEMPORARY_STORAGE];
    strcpy( temporaryPath, _environment->temporaryPath );
    strcat( temporaryPath, " " );
    temporaryPath[strlen(temporaryPath)-1] = PATH_SEPARATOR;

    char bootCodeFilename[MAX_TEMPORARY_STORAGE];
    sprintf( bootCodeFilename, "%sBOOTCODE", temporaryPath );

    remove( bootCodeFilename );

    strcat( temporaryPath, "atr" );
#ifdef _WIN32
    mkdir( temporaryPath );
#else
    mkdir( temporaryPath, 0777 );
#endif
    strcat( temporaryPath, " " );
    temporaryPath[strlen(temporaryPath)-1] = PATH_SEPARATOR;

    char pipes[256];
    #ifdef _WIN32
        strcpy( pipes, ">nul 2>nul");
    #else
        strcpy( pipes, ">/dev/null 2>/dev/null");
    #endif

    char commandLine[8*MAX_TEMPORARY_STORAGE];
#ifdef _WIN32
    sprintf( commandLine, "del %s*.* %s", temporaryPath, pipes );
#else
    sprintf( commandLine, "rm %s* %s", temporaryPath, pipes );
#endif
    system_call( _environment, commandLine );

    char mainFilename[MAX_TEMPORARY_STORAGE];
    sprintf( mainFilename, "%sMAIN.EXE", temporaryPath );

    char dos25Filename[MAX_TEMPORARY_STORAGE];
    sprintf( dos25Filename, "%sDOS.SYS", temporaryPath );

    char dup25Filename[MAX_TEMPORARY_STORAGE];
    sprintf( dup25Filename, "%sDUP.SYS", temporaryPath );

    char atrFileName[MAX_TEMPORARY_STORAGE];
    strcpy( atrFileName, _environment->exeFileName );
    char * p = strstr( atrFileName, ".atr" );
    if ( !p ) {
        strcat( atrFileName, ".atr");
    }

    rename( _environment->exeFileName, mainFilename );

    FILE * fileOut;

    fileOut = fopen( bootCodeFilename, "wb" );
    if ( fileOut ) {
        fwrite( dos25_bootcode, 1, sizeof( dos25_bootcode ), fileOut );
        fclose( fileOut );
    }

    fileOut = fopen( dos25Filename, "wb" );
    if ( fileOut ) {
        fwrite( dos25_dos_sys, 1, sizeof( dos25_dos_sys ), fileOut );
        fclose( fileOut );
    }

    fileOut = fopen( dup25Filename, "wb" );
    if ( fileOut ) {
        fwrite( dos25_dup_sys, 1, sizeof( dos25_dup_sys ), fileOut );
        fclose( fileOut );
    }

    if ( !storage ) {
        BUILD_TOOLCHAIN_DIR2ATR( _environment, dir2AtrExecutableName, bootCodeFilename, temporaryPath, atrFileName, pipes );
        autorun_atr( _environment, atrFileName, "MAIN    EXE" );
    } else {
        int i=0;
        while( storage ) {
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
                buffer = malloc( size );
                (void)!fread( &buffer[0], size, 1, file );
                fclose( file );
                char dataFilename[8*MAX_TEMPORARY_STORAGE];
                sprintf( dataFilename, "%s%s", temporaryPath, fileStorage->targetName );
                fileOut = fopen( dataFilename, "wb" );
                if ( fileOut ) {
                    fwrite( buffer, 1, size, fileOut );
                    fclose(fileOut );
                }
                fileStorage = fileStorage->next;
            }
            char buffer[MAX_TEMPORARY_STORAGE];
            char filemask[MAX_TEMPORARY_STORAGE];
            strcpy( filemask, _environment->exeFileName );
            char * basePath = find_last_path_separator( filemask );
            if ( basePath ) {
                ++basePath;
                *basePath = 0;
                if ( storage->fileName ) {
                    strcat( basePath, storage->fileName );
                } else {
                    strcat( basePath, "disk%d.atr" );
                }
            } else {
                if ( storage->fileName ) {
                    strcpy( filemask, storage->fileName );
                } else {
                    strcpy( filemask, "disk%d.atr" );
                }
            }
            sprintf( buffer, filemask, i );
            if ( !strstr( buffer, ".atr" ) ) {
                strcat( buffer, ".atr" );
            }
            BUILD_TOOLCHAIN_DIR2ATR( _environment, dir2AtrExecutableName, bootCodeFilename, temporaryPath, buffer, pipes );
            if ( i == 0 ) {
                autorun_atr( _environment, buffer, "MAIN    EXE" );
            }
            storage = storage->next;
            ++i;

        #ifdef _WIN32
            sprintf( commandLine, "del %s*.* %s", temporaryPath, pipes );
        #else
            sprintf( commandLine, "rm %s* %s", temporaryPath, pipes );
        #endif
            system_call( _environment, commandLine );

        }
    }

#ifdef _WIN32
    sprintf( commandLine, "del %s*.* %s", temporaryPath, pipes );
#else
    sprintf( commandLine, "rm %s* %s", temporaryPath, pipes );
#endif
    system_call( _environment, commandLine );

    remove( bootCodeFilename );

}

/**
 * @brief Convert C64's assembly to executable
 * 
 * @param _environment 
 */
void target_linkage( Environment * _environment ) {

    switch( _environment->outputFileType ) {
        case OUTPUT_FILE_TYPE_XEX:
            generate_xex( _environment );
            break;
        case OUTPUT_FILE_TYPE_ATR:
            generate_xex( _environment );
            generate_atr( _environment );
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
