/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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

        if ( _environment->profileFileName && _environment->profileCycles ) {
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

    char * exeFileName = strdup( _environment->exeFileName );
    char * extension = strstr( exeFileName, ".d64" );
    if ( extension ) {
        * extension = 0;
    }
    int diskNumber = 1;

    D64Handle * handle = NULL;

    Storage * storage = _environment->storage;

    if ( !storage ) {
        char * storageFileName = generate_storage_filename( _environment, exeFileName, "d64", diskNumber );

        handle = d64_create( CBMDOS );
        d64_write_file( handle, "MAIN", FT_PRG, prgContent, prgSize );
        Bank * bank = _environment->expansionBanks;
        while( bank ) {
            int bankSize = bank->space - bank->remains;
            if ( ( d64_get_free_sectors( handle ) * 256 ) < bankSize ) {
                d64_output( handle, storageFileName );
                d64_free( handle );
                if ( _environment->outputGeneratedFiles ) {
                    printf( "%s\n", storageFileName );
                }
                ++diskNumber;
                storageFileName = generate_storage_filename( _environment, exeFileName, "d64", diskNumber );
                handle = d64_create( CBMDOS );
            }
            if ( bank->remains < bank->space ) {
                char bankFileName[MAX_TEMPORARY_STORAGE];
                sprintf( bankFileName, "BANK%d", ( bank->id - 1 ) );
                d64_write_file( handle, bankFileName, FT_SEQ, bank->data, bankSize );
            }
            bank = bank->next;
        }
        d64_output( handle, storageFileName );
        d64_free( handle );
        if ( _environment->outputGeneratedFiles ) {
            printf( "%s\n", storageFileName );
        }

    } else {

        char buffer[MAX_TEMPORARY_STORAGE];
        char filemask[MAX_TEMPORARY_STORAGE];
        strcpy( filemask, exeFileName );
        char * basePath = find_last_path_separator( filemask );
        if ( basePath ) {
            ++basePath;
            *basePath = 0;
            if ( storage->fileName ) {
                strcat( basePath, storage->fileName );
            } else {
                strcat( basePath, "disk" );
            }
        } else {
            if ( storage->fileName ) {
                strcpy( filemask, storage->fileName );
            } else {
                strcpy( filemask, "disk" );
            }
        }

        char * storageFileName = generate_storage_filename( _environment, filemask, "d64", diskNumber );
        
        int i=0;
        while( storage ) {
            handle = d64_create( CBMDOS );
            if ( i == 0 ) {
                d64_write_file( handle, "MAIN", FT_PRG, prgContent, prgSize );
            }
            FileStorage * fileStorage = storage->files;
            while( fileStorage ) {
                int size;
                char * buffer;
                if ( fileStorage->content && fileStorage->size ) {
                    size = fileStorage->size + 2;
                    buffer = malloc( size );
                    memset( buffer, 0, size );
                    memcpy( &buffer[2], fileStorage->content, fileStorage->size );
                } else {
                    FILE * file = fopen( fileStorage->sourceName, "rb" );
                    if ( !file ) {
                        CRITICAL_DLOAD_MISSING_FILE( fileStorage->sourceName );
                    }
                    fseek( file, 0, SEEK_END );
                    size = ftell( file );
                    fseek( file, 0, SEEK_SET );
                    buffer = malloc( size + 2 );
                    memset( buffer, 0, size + 2 );
                    (void)!fread( &buffer[2], size, 1, file );
                    fclose( file );
                    size += 2;
                }
                d64_write_file( handle, fileStorage->targetName, FT_PRG, buffer, size );
                fileStorage = fileStorage->next;
            }
            d64_output( handle, storageFileName );
            d64_free( handle );
            if ( _environment->outputGeneratedFiles ) {
                printf( "%s\n", storageFileName );
            }

            ++diskNumber;

            strcpy( filemask, exeFileName );
            char * basePath = find_last_path_separator( filemask );
            if ( basePath ) {
                ++basePath;
                *basePath = 0;
                if ( storage->fileName ) {
                    strcat( basePath, storage->fileName );
                } else {
                    strcat( basePath, "disk" );
                }
            } else {
                if ( storage->fileName ) {
                    strcpy( filemask, storage->fileName );
                } else {
                    strcpy( filemask, "disk" );
                }
            }
            storageFileName = generate_storage_filename( _environment, filemask, "d64", diskNumber );
            storage = storage->next;
            ++i;
        }        

        Bank * bank = _environment->expansionBanks;
        while( bank ) {
            int bankSize = bank->space - bank->remains;
            if ( ( d64_get_free_sectors( handle ) * 256 ) < bankSize ) {
                d64_output( handle, storageFileName );
                d64_free( handle );
                if ( _environment->outputGeneratedFiles ) {
                    printf( "%s\n", storageFileName );
                }
                ++diskNumber;
                storageFileName = generate_storage_filename( _environment, filemask, "d64", diskNumber );
                handle = d64_create( CBMDOS );
            }
            if ( bank->remains < bank->space ) {
                char bankFileName[MAX_TEMPORARY_STORAGE];
                sprintf( bankFileName, "BANK%d", ( bank->id - 1 ) );
                d64_write_file( handle, bankFileName, FT_SEQ, bank->data, bank->space - bank->remains );
            }
            bank = bank->next;
        }
        d64_output( handle, storageFileName );
        d64_free( handle );
        if ( _environment->outputGeneratedFiles ) {
            printf( "%s\n", storageFileName );
        }

    }

}

void generate_reu( Environment * _environment ) {

    FILE * prgHandle = fopen(_environment->exeFileName, "rb");
    fseek( prgHandle, 0, SEEK_END );
    int prgSize = ftell( prgHandle );
    fseek( prgHandle, 0, SEEK_SET );
    unsigned char * prgContent = malloc( prgSize );
    (void)!fread( prgContent, prgSize, 1, prgHandle );
    fclose( prgHandle );

    remove(_environment->exeFileName);

    char * exeFileName = strdup( _environment->exeFileName );
    char * extension = strstr( exeFileName, ".reu" );
    if ( extension ) {
        * extension = 0;
    }
    int diskNumber = 1;

    D64Handle * handle = NULL;

    Storage * storage = _environment->storage;

    if ( !storage ) {
        char * storageFileName = generate_storage_filename( _environment, exeFileName, "d64", diskNumber );      
        FILE * reuHandle = fopen( _environment->exeFileName, "wb" );
        for( int i=0; i<_environment->ramSize * 1024; ++i ) {
            fputc( 0, reuHandle );
        }
        fseek( reuHandle, 0, SEEK_SET );
        handle = d64_create( CBMDOS );
        d64_write_file( handle, "MAIN", FT_PRG, prgContent, prgSize );
        Bank * bank = _environment->expansionBanks;
        while( bank ) {
            if ( bank->remains < bank->space ) {
                int bankSize = bank->space - bank->remains;
                fseek( reuHandle, ( bank->id - 1 ) * bank->space, SEEK_SET );
                fwrite( bank->data, 1, bankSize, reuHandle );
            }
            bank = bank->next;
        }
        d64_output( handle, storageFileName );
        d64_free( handle );
        if ( _environment->outputGeneratedFiles ) {
            printf( "%s\n", storageFileName );
        }
        fclose( reuHandle );
        if ( _environment->outputGeneratedFiles ) {
            printf( "%s\n", _environment->exeFileName );
        }
    } else {
        char buffer[MAX_TEMPORARY_STORAGE];
        char filemask[MAX_TEMPORARY_STORAGE];
        strcpy( filemask, exeFileName );
        char * basePath = find_last_path_separator( filemask );
        if ( basePath ) {
            ++basePath;
            *basePath = 0;
            if ( storage->fileName ) {
                strcat( basePath, storage->fileName );
            } else {
                strcat( basePath, "disk" );
            }
        } else {
            if ( storage->fileName ) {
                strcpy( filemask, storage->fileName );
            } else {
                strcpy( filemask, "disk" );
            }
        }

        char * storageFileName = generate_storage_filename( _environment, filemask, "d64", diskNumber );
        
        int i=0;
        while( storage ) {
            handle = d64_create( CBMDOS );
            if ( i == 0 ) {
                d64_write_file( handle, "MAIN", FT_PRG, prgContent, prgSize );
            }
            FileStorage * fileStorage = storage->files;
            while( fileStorage ) {
                int size;
                char * buffer;
                if ( fileStorage->content && fileStorage->size ) {
                    size = fileStorage->size + 2;
                    buffer = malloc( size );
                    memset( buffer, 0, size );
                    memcpy( &buffer[2], fileStorage->content, fileStorage->size );
                } else {
                    FILE * file = fopen( fileStorage->sourceName, "rb" );
                    if ( !file ) {
                        CRITICAL_DLOAD_MISSING_FILE( fileStorage->sourceName );
                    }
                    fseek( file, 0, SEEK_END );
                    size = ftell( file );
                    fseek( file, 0, SEEK_SET );
                    buffer = malloc( size + 2 );
                    memset( buffer, 0, size + 2 );
                    (void)!fread( &buffer[2], size, 1, file );
                    fclose( file );
                    size += 2;
                }
                d64_write_file( handle, fileStorage->targetName, FT_PRG, buffer, size );
                fileStorage = fileStorage->next;
            }
            d64_output( handle, storageFileName );
            d64_free( handle );
            if ( _environment->outputGeneratedFiles ) {
                printf( "%s\n", storageFileName );
            }

            ++diskNumber;

            strcpy( filemask, exeFileName );
            char * basePath = find_last_path_separator( filemask );
            if ( basePath ) {
                ++basePath;
                *basePath = 0;
                if ( storage->fileName ) {
                    strcat( basePath, storage->fileName );
                } else {
                    strcat( basePath, "disk" );
                }
            } else {
                if ( storage->fileName ) {
                    strcpy( filemask, storage->fileName );
                } else {
                    strcpy( filemask, "disk" );
                }
            }
            storageFileName = generate_storage_filename( _environment, filemask, "d64", diskNumber );
            storage = storage->next;
            ++i;
        }        

        FILE * reuHandle = fopen( _environment->exeFileName, "wb" );
        for( int i=0; i<_environment->ramSize * 1024; ++i ) {
            fputc( 0, reuHandle );
        }
        fseek( reuHandle, 0, SEEK_SET );
        Bank * bank = _environment->expansionBanks;
        while( bank ) {
            if ( bank->remains < bank->space ) {
                int bankSize = bank->space - bank->remains;
                fseek( reuHandle, ( bank->id - 1 ) * bank->space, SEEK_SET );
                fwrite( bank->data, 1, bankSize, reuHandle );
            }
            bank = bank->next;
        }
        fclose( reuHandle );
        if ( _environment->outputGeneratedFiles ) {
            printf( "%s\n", _environment->exeFileName );
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
        case OUTPUT_FILE_TYPE_D64:
            generate_prg( _environment );
            generate_d64( _environment );
            break;
        case OUTPUT_FILE_TYPE_REU:
            generate_prg( _environment );
            generate_reu( _environment );
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
