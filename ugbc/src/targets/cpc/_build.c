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

    BUILD_TOOLCHAIN_Z88DK_EXEC( _environment, "cpc", executableName, listingFileName );

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
        rename( binaryName, _environment->listingFileName );
    }

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
        strcpy( p+1, "main." );
    } else {
        strcpy( diskName, "main." );
    }

    TRACE1( "exeFileName = %s", _environment->exeFileName );
    TRACE1( "diskName    = %s", diskName );

    sprintf( commandLine, "\"%s\" +cpc --org 256 --exec 256 --disk -b \"%s\" -o \"%s\" %s",
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
        strcpy( p, ".");
    } else {
        strcpy( binaryName, "main." );
    }
 
    system_remove_safe( _environment, binaryName );

}

void target_linkage_z88dk_appmake_patched( Environment * _environment ) {

    Storage * storage = _environment->storage;

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
        rename( binaryName, _environment->listingFileName );
    }

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

    char buffer[MAX_TEMPORARY_STORAGE];
    if ( storage ) {
        char filemask[MAX_TEMPORARY_STORAGE];
        strcpy( filemask, _environment->exeFileName );
        char * basePath = strrchr( filemask, PATH_SEPARATOR );
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
        // if ( !strstr( diskName, ".dsk" ) ) {
        //     strcat( diskName, ".dsk" );
        // }
    } else {
        strcpy( diskName, _environment->exeFileName );
        if ( !strstr( diskName, ".dsk") ) {
            strcat( diskName, ".dsk" );
        }
    }

    TRACE1( "exeFileName = %s", _environment->exeFileName );
    TRACE1( "diskName    = %s", diskName );

    if ( !storage ) {

        sprintf( commandLine, "\"%s\" +cpc --org 256 --exec 256 --disk -b \"%s\" -o \"%s\" %s",
            executableName,
            binaryName,
            diskName,
            pipes );

        if ( system_call( _environment,  commandLine ) ) {
            printf("The compilation of assembly program failed.\n\n");
            printf("Please use option '-I' to install chain tool.\n\n");
            return;
        }; 

        rename( diskName, _environment->exeFileName );

    } else {
        int i=0;
        char * additionalFiles = NULL;
        while( storage ) {
            additionalFiles = NULL;
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

            sprintf( commandLine, "\"%s\" +cpc --afile %s --org 256 --exec 256 --disk -b \"%s\" -o \"%s\" %s",
                executableName,
                additionalFiles,
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

            if ( storage ) {
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
                        strcat( basePath, "disk%d.atr" );
                    }
                } else {
                    if ( storage->fileName ) {
                        strcpy( filemask, storage->fileName );
                    } else {
                        strcpy( filemask, "disk%d.atr" );
                    }
                }
                sprintf( diskName, filemask, i );
                if ( !strstr( diskName, ".atr" ) ) {
                    strcat( diskName, ".atr" );
                }

            #ifdef _WIN32
                sprintf( commandLine, "del %s*.* %s", temporaryPath, pipes );
            #else
                sprintf( commandLine, "rm %s* %s", temporaryPath, pipes );
            #endif
                // system_call( _environment, commandLine );

            }

        }
    }

    // strcpy( diskName, _environment->asmFileName );
    // p = strrchr( diskName, '/' );
    // if ( !p ) {
    //     p = strrchr( diskName, '\\' );
    // }
    // if ( p ) {
    //     strcpy( p+1, "main.dsk" );
    // } else {
    //     strcpy( diskName, "main.dsk" );
    // }


    // strcpy( binaryName, _environment->asmFileName );
    // p = strstr( binaryName, ".asm" );
    // if ( p ) {
    //     strcpy( p, ".");
    // } else {
    //     strcpy( binaryName, "main." );
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
        strcpy( pipes, "2>nul");
    #else
        strcpy( pipes, "2>/dev/null");
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
