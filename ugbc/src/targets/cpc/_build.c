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

// This version of target linkage should be used in presence of an unpatched
// z88dk, like the one we have actually on 1.15.2 and below. Note that this
// version is unable to manage STORAGE keyword -- so we must stop if this keyword
// is used.
void target_linkage_z88dk_appmake_unpatched( Environment * _environment ) {

    if ( _environment->storage ) {
        CRITICAL_STORAGE_NOT_AVAILABLE();
    }

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

    BUILD_TOOLCHAIN_Z88DK_EXEC( _environment, "cpc", executableName, listingFileName, "z80" );

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
    system_remove_safe( _environment, binaryName );

    BUILD_TOOLCHAIN_Z88DK_GET_EXECUTABLE_APPMAKE( _environment, executableName );

    char pipes[256];

    #ifdef _WIN32
        strcopy( pipes, ">nul 2>nul");
    #else
        strcopy( pipes, ">/dev/null 2>/dev/null");
    #endif

    strcopy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *(p+1) = 'b';
        *(p+2) = 'i';
        *(p+3) = 'n';
        *(p+4) = 0;
    }

    strcopy( binaryName2, _environment->asmFileName );
    p = strrchr( binaryName2, '/' );
    if ( !p ) {
        p = strrchr( binaryName2, '\\' );
    }
    if ( p ) {
        strcopy( p+1, "main.bin" );
    } else {
        strcopy( binaryName2, "main.bin" );
    }

    strcopy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *(p+1) = 'b';
        *(p+2) = 'i';
        *(p+3) = 'n';
        *(p+4) = 0;
    }

    system_remove_safe( _environment, binaryName2 );

    TRACE2( "  renaming %s to %s", binaryName, binaryName2 );
    
    BUILD_SAFE_MOVE( _environment, binaryName, binaryName2 );

    strcopy( binaryName, _environment->asmFileName );
    p = strrchr( binaryName, '/' );
    if ( !p ) {
        p = strrchr( binaryName, '\\' );
    }
    if ( p ) {
        strcopy( p+1, "main.bin" );
    } else {
        strcopy( binaryName, "main.bin" );
    }

    system_remove_safe( _environment, _environment->exeFileName );

    strcopy( diskName, _environment->exeFileName );
    p = strrchr( diskName, '/' );
    if ( !p ) {
        p = strrchr( diskName, '\\' );
    }
    if ( p ) {
        strcopy( p+1, "main." );
    } else {
        strcopy( diskName, "main." );
    }

    TRACE1( "exeFileName = %s", _environment->exeFileName );
    TRACE1( "diskName    = %s", diskName );

    sprintf( commandLine, "\"%s\" +cpc --org %d --exec %d --disk -b \"%s\" -o \"%s\" %s",
        executableName,
        _environment->program.startingAddress,
        _environment->program.startingAddress,
        binaryName,
        diskName,
        pipes );

    if ( system_call( _environment,  commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n");
        printf("Please use option '-I' to install chain tool.\n\n");
        return;
    }; 

    system_remove_safe( _environment, diskName );

    strcopy( diskName, _environment->asmFileName );
    p = strrchr( diskName, '/' );
    if ( !p ) {
        p = strrchr( diskName, '\\' );
    }
    if ( p ) {
        strcopy( p+1, "main.dsk" );
    } else {
        strcopy( diskName, "main.dsk" );
    }

    BUILD_SAFE_MOVE( _environment, diskName, _environment->exeFileName );

    strcopy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        strcopy( p, ".");
    } else {
        strcopy( binaryName, "main." );
    }
 
    system_remove_safe( _environment, binaryName );

}

void target_linkage_z88dk_appmake_patched( Environment * _environment ) {

    Storage * storage = _environment->storage;

    char temporaryPath[MAX_TEMPORARY_STORAGE];
    strcopy( temporaryPath, _environment->temporaryPath );
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

    BUILD_TOOLCHAIN_Z88DK_EXEC( _environment, "cpc", executableName, listingFileName, "z80" );

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
    system_remove_safe( _environment, binaryName );

    BUILD_TOOLCHAIN_Z88DK_GET_EXECUTABLE_APPMAKE( _environment, executableName );

    char pipes[256];

    #ifdef _WIN32
        strcopy( pipes, ">nul 2>nul");
    #else
        strcopy( pipes, ">/dev/null 2>/dev/null");
    #endif

    strcopy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *(p+1) = 'b';
        *(p+2) = 'i';
        *(p+3) = 'n';
        *(p+4) = 0;
    }

    strcopy( binaryName2, _environment->asmFileName );
    p = strrchr( binaryName2, '/' );
    if ( !p ) {
        p = strrchr( binaryName2, '\\' );
    }
    if ( p ) {
        strcopy( p+1, "main.bin" );
    } else {
        strcopy( binaryName2, "main.bin" );
    }

    strcopy( binaryName, _environment->asmFileName );
    p = strstr( binaryName, ".asm" );
    if ( p ) {
        *(p+1) = 'b';
        *(p+2) = 'i';
        *(p+3) = 'n';
        *(p+4) = 0;
    }

    system_remove_safe( _environment, binaryName2 );

    TRACE2( "  renaming %s to %s", binaryName, binaryName2 );
    
    BUILD_SAFE_MOVE( _environment, binaryName, binaryName2 );

    strcopy( binaryName, _environment->asmFileName );
    p = strrchr( binaryName, '/' );
    if ( !p ) {
        p = strrchr( binaryName, '\\' );
    }
    if ( p ) {
        strcopy( p+1, "main.bin" );
    } else {
        strcopy( binaryName, "main.bin" );
    }

    system_remove_safe( _environment, _environment->exeFileName );

    char buffer[MAX_TEMPORARY_STORAGE];
    if ( storage ) {
        char filemask[MAX_TEMPORARY_STORAGE];
        strcopy( filemask, _environment->exeFileName );
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
                strcopy( filemask, storage->fileName );
            } else {
                strcopy( filemask, "disk%d.dsk" );
            }
        }
        sprintf( diskName, filemask, 0 );
        // if ( !strstr( diskName, ".dsk" ) ) {
        //     strcat( diskName, ".dsk" );
        // }
        if ( !strstr( diskName, ".dsk" ) ) {
            strcat( diskName, ".dsk" );
        }        
    } else {
        strcopy( diskName, _environment->exeFileName );
        if ( !strstr( diskName, ".dsk") ) {
            strcat( diskName, ".dsk" );
        }
    }

    TRACE1( "exeFileName = %s", _environment->exeFileName );
    TRACE1( "diskName    = %s", diskName );

    if ( !storage ) {

        sprintf( commandLine, "\"%s\" +cpc --org %d --exec %d --disk --blockname \"%s\" -b \"%s\" -o \"%s\" %s",
            executableName,
            _environment->program.startingAddress,
            _environment->program.startingAddress,
            basename(binaryName),
            binaryName,
            diskName,
            pipes );

        if ( system_call( _environment,  commandLine ) ) {
            printf("The compilation of assembly program failed.\n\n");
            printf("Please use option '-I' to install chain tool.\n\n");
            return;
        }; 

        BUILD_SAFE_MOVE( _environment, diskName, _environment->exeFileName );
        if ( _environment->outputGeneratedFiles ) {
            printf( "%s\n", _environment->exeFileName );
        }
    } else {
        int i=0;
        char * additionalFiles = NULL;
        while( storage ) {
            additionalFiles = NULL;
            FileStorage * fileStorage = storage->files;
            while( fileStorage ) {
                int size;
                char * buffer;

                if ( fileStorage->content && fileStorage->size ) {
                    size = fileStorage->size + 2;
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
                    strcat( additionalFiles, "," );
                    strcat( additionalFiles, dataFilename );
                } else {
                    additionalFiles = strdup( dataFilename );
                }
                fileStorage = fileStorage->next;
            }

            sprintf( commandLine, "\"%s\" +cpc --afile %s --org %d --exec %d --disk --blockname \"%s\" -b \"%s\" -o \"%s\" %s",
                executableName,
                additionalFiles,
                _environment->program.startingAddress,
                _environment->program.startingAddress,
                basename( binaryName ),
                binaryName,
                diskName,
                pipes );

            if ( system_call( _environment,  commandLine ) ) {
                printf("The compilation of assembly program failed.\n\n");
                printf("Please use option '-I' to install chain tool.\n\n");
                return;
            }; 

            storage = storage->next;
            ++i;

            if ( _environment->outputGeneratedFiles ) {
                printf( "%s\n", diskName );
            }

            if ( storage ) {
                char buffer[MAX_TEMPORARY_STORAGE];
                char filemask[MAX_TEMPORARY_STORAGE];
                strcopy( filemask, _environment->exeFileName );
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
                        strcopy( filemask, storage->fileName );
                    } else {
                        strcopy( filemask, "disk%d.dsk" );
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
                // system_call( _environment, commandLine );

            }

        }
    }

    // strcopy( diskName, _environment->asmFileName );
    // p = strrchr( diskName, '/' );
    // if ( !p ) {
    //     p = strrchr( diskName, '\\' );
    // }
    // if ( p ) {
    //     strcopy( p+1, "main.dsk" );
    // } else {
    //     strcopy( diskName, "main.dsk" );
    // }


    // strcopy( binaryName, _environment->asmFileName );
    // p = strstr( binaryName, ".asm" );
    // if ( p ) {
    //     strcopy( p, ".");
    // } else {
    //     strcopy( binaryName, "main." );
    // }
 
    // system_remove_safe( _environment, binaryName );

}

void target_linkage( Environment * _environment ) {

    char commandLine[2*MAX_TEMPORARY_STORAGE];
    char executableName[MAX_TEMPORARY_STORAGE];
    char version[MAX_TEMPORARY_STORAGE];
    BUILD_TOOLCHAIN_Z88DK_GET_EXECUTABLE_APPMAKE( _environment, executableName );

    char pipes[256];

    #ifdef _WIN32
        strcopy( pipes, "2>nul");
    #else
        strcopy( pipes, "2>/dev/null");
    #endif

    sprintf( commandLine, "\"%s\" +cpc %s", executableName, pipes );

    FILE * fp = popen (commandLine, "r" );
    if ( fp ) {
        (void)!fgets( version, MAX_ARRAY_DIMENSIONS, fp );
        pclose(fp);

        if ( strstr( version, "bin2cpc-ugbasic") != NULL ) {
            target_linkage_z88dk_appmake_patched( _environment );
        } else {
            target_linkage_z88dk_appmake_unpatched( _environment );
        }
    }

}

void target_cleanup( Environment * _environment ) {

    if ( _environment->exeFileName ) {
        char binFileName[MAX_TEMPORARY_STORAGE];

        strcopy( binFileName, _environment->exeFileName );
        char * p = strrchr( binFileName, '.' );
        memcpy( p, ".bin", 4 );

        remove( binFileName );
        remove( _environment->asmFileName );

        if ( _environment->analysis && _environment->listingFileName ) {
            target_analysis( _environment );
        }

    }

}
