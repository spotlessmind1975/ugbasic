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
    char binaryName[MAX_TEMPORARY_STORAGE];
    char listingFileName[MAX_TEMPORARY_STORAGE];

    BUILD_SAFE_REMOVE( _environment, _environment->exeFileName );

    BUILD_TOOLCHAIN_Z88DK_GET_EXECUTABLE_Z80ASM( _environment, executableName );

    BUILD_TOOLCHAIN_Z88DK_GET_LISTING_FILE( _environment, listingFileName );

    BUILD_TOOLCHAIN_Z88DK_EXEC( _environment, "msx1", executableName, listingFileName, "z80" );

    char * p;

    if ( _environment->listingFileName ) {
        strcpy( binaryName, _environment->asmFileName );
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

    strcpy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *(p+1) = 'o';
        *(p+2) = 0;
    }
    system_remove_safe( _environment, binaryName );

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

void generate_rom( Environment * _environment ) {

    char commandLine[8*MAX_TEMPORARY_STORAGE];
    char executableName[MAX_TEMPORARY_STORAGE];
    char binaryName[MAX_TEMPORARY_STORAGE];
    char listingFileName[MAX_TEMPORARY_STORAGE];

    char * p;

    strcpy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *p = 0;
        --p;
        strcat( p, ".bin");
    }

    BUILD_TOOLCHAIN_Z88DK_GET_EXECUTABLE_APPMAKE( _environment, executableName );

    char pipes[256];

    #ifdef _WIN32
        strcpy( pipes, "");
    #else
        strcpy( pipes, "");
    #endif

    sprintf( commandLine, "\"%s\" +msxrom -b \"%s\" %s",
        executableName,
        binaryName,
        pipes );

    p = strstr( binaryName, ".bin" );
    if ( p ) {
        *(p+1) = 'r';
        *(p+2) = 'o';
        *(p+3) = 'm';
    }

    if ( system_call( _environment,  commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n");
        printf("Please use option '-I' to install chain tool.\n\n");
        return;
    }; 

    remove( _environment->exeFileName );

    BUILD_SAFE_MOVE( _environment, binaryName, _environment->exeFileName );

    char symbolName[MAX_TEMPORARY_STORAGE];
    strcpy( symbolName, _environment->exeFileName );
    p = strstr( symbolName, ".rom" );
    if ( p ) {
        *p = 0;
        --p;
        strcat( p, ".sym");

        strcpy( binaryName, _environment->asmFileName );
        p = strstr( binaryName, ".asm" );
        if ( p ) {
            *p = 0;
            --p;
            strcat( p, ".sym");
            BUILD_SAFE_MOVE( _environment, binaryName, symbolName );
        }
    }

    if ( _environment->listingFileName ) {
        strcpy( binaryName, _environment->asmFileName );
        p = strstr( binaryName, ".asm" );
        if ( p ) {
            *p = 0;
            --p;
            strcat( p, ".lis");
            BUILD_SAFE_MOVE( _environment, binaryName, _environment->listingFileName );
        }

        if ( _environment->profileFileName && _environment->profileCycles ) {
            strcpy( binaryName, _environment->profileFileName );
            if ( _environment->executerFileName ) {
                sprintf(executableName, "%s", _environment->executerFileName );
            } else if( access( "runz80.exe", F_OK ) == 0 ) {
                sprintf(executableName, "%s", "runz80.exe" );
            } else {
                sprintf(executableName, "%s", "runz80" );
            }

            sprintf( commandLine, "\"%s\" -m -p \"%s\" %d -l 4000 \"%s\" -R 4010 -u \"%s\" \"%s\"",
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

void generate_dsk( Environment * _environment ) {

    Storage * storage = _environment->storage;

    char pipes[256];

    #ifdef _WIN32
        strcpy( pipes, ">nul 2>nul");
    #else
        strcpy( pipes, ">/dev/null 2>/dev/null");
    #endif

    char temporaryPath[MAX_TEMPORARY_STORAGE];
    strcpy( temporaryPath, _environment->temporaryPath );
    strcat( temporaryPath, " " );
    temporaryPath[strlen(temporaryPath)-1] = PATH_SEPARATOR;
    strcat( temporaryPath, "dsk" );
#ifdef _WIN32
    mkdir( temporaryPath );
#else
    mkdir( temporaryPath, 0777 );
#endif
    strcat( temporaryPath, " " );
    temporaryPath[strlen(temporaryPath)-1] = PATH_SEPARATOR;

    char commandLine[8*MAX_TEMPORARY_STORAGE];
    char executableName[MAX_TEMPORARY_STORAGE];
    char binaryName[MAX_TEMPORARY_STORAGE];
    char binaryName2[MAX_TEMPORARY_STORAGE];
    char listingFileName[MAX_TEMPORARY_STORAGE];
    char diskToolsExecutableName[MAX_TEMPORARY_STORAGE];

    #ifdef _WIN32
        sprintf( commandLine, "del /f /q %s*.* %s", temporaryPath, pipes );
    #else
        sprintf( commandLine, "rm %s* %s", temporaryPath, pipes );
    #endif
        system_call( _environment, commandLine );

    char * p;

    strcpy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *p = 0;
        --p;
        strcat( p, ".bin");
    }

    strcpy( binaryName2, _environment->asmFileName );
    p = strstr( binaryName2, ".asm" );
    if ( p ) {
        *p = 0;
        --p;
        strcat( p, ".bi2");
    }

    BUILD_TOOLCHAIN_Z88DK_GET_EXECUTABLE_APPMAKE( _environment, executableName );

    sprintf( commandLine, "\"%s\" +msx -b \"%s\" -o \"%s\" --org 33024 %s",
        executableName,
        binaryName,
        binaryName2,
        pipes );
    if ( system_call( _environment,  commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n");
        printf("Please use option '-I' to install chain tool.\n\n");
        return;
    }; 

    remove( binaryName );

    strcpy( binaryName, _environment->exeFileName );
    p = strstr( binaryName, ".dsk" );
    if ( p ) {
        *p = 0;
        --p;
        strcat( p, ".bin");
    }

    BUILD_SAFE_MOVE( _environment, binaryName2, binaryName );

    BUILD_TOOLCHAIN_DSKTOOLS_GET_EXECUTABLE( _environment, diskToolsExecutableName );

    if ( !storage ) {

        sprintf( commandLine, "\"%s\" \"%s\" \"%s\" %s",
            diskToolsExecutableName,
            _environment->exeFileName,
            binaryName,
            pipes );
        if ( system_call( _environment,  commandLine ) ) {
            printf("The compilation of assembly program failed.\n\n");
            printf("Please use option '-I' to install chain tool.\n\n");
            return;
        }; 
        
        if ( _environment->outputGeneratedFiles ) {
            printf( "%s\n", _environment->exeFileName );
        }

    } else {

        char diskName[MAX_TEMPORARY_STORAGE];
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
                strcat( basePath, "disk%d.dsk" );
            }
        } else {
            if ( storage->fileName ) {
                strcpy( filemask, storage->fileName );
            } else {
                strcpy( filemask, "disk%d.dsk" );
            }
        }
        sprintf( diskName, filemask, 0 );
        if ( !strstr( diskName, ".dsk" ) ) {
            strcat( diskName, ".dsk" );
        }

        int i=0;
        char * additionalFiles = NULL;
        while( storage ) {
            additionalFiles = NULL;
            FileStorage * fileStorage = storage->files;
            while( fileStorage ) {
                int size;
                char * buffer;

                if ( fileStorage->content && fileStorage->size ) {
                    size = fileStorage->size;
                    buffer = malloc( size );
                    memset( buffer, 0, size );
                    memcpy( buffer, fileStorage->content, fileStorage->size );
                } else {
                    FILE * file = fopen( fileStorage->sourceName, "rb" );
                    if ( !file ) {
                        CRITICAL_DLOAD_MISSING_FILE( fileStorage->sourceName );
                    }
                    fseek( file, 0, SEEK_END );
                    size = ftell( file );
                    fseek( file, 0, SEEK_SET );
                    buffer = malloc( size );
                    memset( buffer, 0, size );
                    (void)!fread( buffer, size, 1, file );
                    fclose( file );
                }
                char dataFilename[MAX_TEMPORARY_STORAGE];
                sprintf( dataFilename, "%s%s", temporaryPath, fileStorage->targetName );
                FILE * fileOut = fopen( dataFilename, "wb" );
                if ( fileOut ) {
                    fwrite( buffer, 1, size, fileOut );
                    fclose(fileOut );
                }
                if ( additionalFiles ) {
                    additionalFiles = realloc( additionalFiles, strlen(additionalFiles) + strlen( dataFilename ) + 3 );
                    strcat( additionalFiles, " " );
                    strcat( additionalFiles, dataFilename );
                } else {
                    additionalFiles = strdup( dataFilename );
                }
                fileStorage = fileStorage->next;
            }

            sprintf( commandLine, "\"%s\" \"%s\" \"%s\" %s %s",
                diskToolsExecutableName,
                diskName,
                binaryName,
                additionalFiles,
                pipes );
            if ( system_call( _environment,  commandLine ) ) {
                printf("The compilation of assembly program failed.\n\n");
                printf("Please use option '-I' to install chain tool.\n\n");
                return;
            }; 

            if ( _environment->outputGeneratedFiles ) {
                printf( "%s\n", diskName );
            }

            storage = storage->next;
            ++i;

            if ( storage ) {
                strcpy( filemask, _environment->exeFileName );
                char * basePath = find_last_path_separator( filemask );
                if ( basePath ) {
                    ++basePath;
                    *basePath = 0;
                    if ( storage->fileName ) {
                        strcat( basePath, storage->fileName );
                    } else {
                        strcat( basePath, "disk%d.dsk" );
                    }
                } else {
                    if ( storage->fileName ) {
                        strcpy( filemask, storage->fileName );
                    } else {
                        strcpy( filemask, "disk%d.dsk" );
                    }
                }
                sprintf( diskName, filemask, i );
                if ( !strstr( diskName, ".dsk" ) ) {
                    strcat( diskName, ".dsk" );
                }

            #ifdef _WIN32
                sprintf( commandLine, "del /f /q %s*.* %s", temporaryPath, pipes );
            #else
                sprintf( commandLine, "rm %s* %s", temporaryPath, pipes );
            #endif
                system_call( _environment, commandLine );

            } 

        }

    }

    remove( binaryName );

}

void target_linkage( Environment * _environment ) {

    switch( _environment->outputFileType ) {
        case OUTPUT_FILE_TYPE_ROM:
            generate_bin( _environment );
            generate_rom( _environment );
            break;
        case OUTPUT_FILE_TYPE_DSK:
            generate_bin( _environment );
            generate_dsk( _environment );
            break;
        default:
            CRITICAL_UNSUPPORTED_OUTPUT_FILE_TYPE( OUTPUT_FILE_TYPE_AS_STRING[_environment->outputFileType] );
    }

}

void target_cleanup( Environment * _environment ) {

    if ( _environment->exeFileName ) {

        char binFileName[MAX_TEMPORARY_STORAGE];

        // strcpy( binFileName, _environment->exeFileName );
        // char * p = strrchr( binFileName, '.' );
        // memcpy( p, ".bin", 4 );

        remove( _environment->configurationFileName );
        // remove( binFileName );
        remove( _environment->asmFileName );

        if ( _environment->analysis && _environment->listingFileName ) {
            target_analysis( _environment );
        }

    }
    
}