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

void generate_bin( Environment * _environment ) {

    char exeFileName[8*MAX_TEMPORARY_STORAGE];
    char commandLine[8*MAX_TEMPORARY_STORAGE];
    char executableName[MAX_TEMPORARY_STORAGE];
    char listingFileName[MAX_TEMPORARY_STORAGE];
    char binaryName[MAX_TEMPORARY_STORAGE];

    BUILD_SAFE_REMOVE( _environment, _environment->exeFileName );

    strcpy( exeFileName, _environment->exeFileName );

    strcpy( binaryName, _environment->exeFileName );
    char * p = strstr( binaryName, ".dsk" );
    if ( p ) {
        strcpy( p, ".bin" );
    }
    strcpy( _environment->exeFileName, binaryName );

    BUILD_TOOLCHAIN_ASM6809_GET_EXECUTABLE( _environment, executableName );

    BUILD_TOOLCHAIN_ASM6809_GET_LISTING_FILE( _environment, listingFileName );

    BUILD_TOOLCHAIN_ASM6809EXEC( _environment, "-C", 0x2A00, executableName, listingFileName );

    if ( _environment->listingFileName ) {

        if ( _environment->profileFileName && _environment->profileCycles ) {
            if ( _environment->executerFileName ) {
                sprintf(executableName, "%s", _environment->executerFileName );
            } else if( access( "run6809.exe", F_OK ) == 0 ) {
                sprintf(executableName, "%s", "run6809.exe" );
            } else {
                sprintf(executableName, "%s", "run6809" );
            }

            sprintf( commandLine, "\"%s\" -i \"%s\" -R 2800 -C -l 0 \"%s\" -p \"%s\" %d",
                executableName,
                _environment->listingFileName,
                _environment->exeFileName,
                _environment->profileFileName,
                _environment->profileCycles ? _environment->profileCycles : 1000000
                );

            if ( system_call( _environment,  commandLine ) ) {
                printf("The profiling of assembly program failed.\n\n");
                return;
            }; 

        }
    
    }

    strcpy( _environment->exeFileName, exeFileName );

}

void generate_dsk( Environment * _environment ) {

    // Let's cut the executable file into multiple segments.
    // The name of the binary is equal to the disk file name,
    // but with a different extension.
    char originalBinaryFile[MAX_TEMPORARY_STORAGE];
    strcpy( originalBinaryFile, _environment->exeFileName );
    char * p = strstr( originalBinaryFile, ".dsk" );
    if ( p ) {
        strcpy( p, ".bin" );
    }

    // Calculate the effective size.
    FILE * fh = fopen( originalBinaryFile, "rb" );
    int executableBinaryFileSize = 0;
    if ( fh ) {
        fseek( fh, 0, SEEK_END );
        executableBinaryFileSize = ftell( fh );
        fclose( fh );
    } else {
        CRITICAL_BUILD_CANNOT_READ_EXECUTABLE_FOR_DSK( _environment->exeFileName, originalBinaryFile );
    }

    // The LOADM command is able to read a limited size of binary file.
    // So we are going to split the original file as follows:
    // | $2a00 ............. $4d00 ... $4e00 ........ $xx00 .....
    // +---------------------+---------+---------+....+---------+
    // |   PROGRAM.EXE       | P01.DAT | P02.DAT |....| P0n.DAT |
    // +---------------------+---------+---------+....+---------+
    //

    executableBinaryFileSize -= 5;
    char * originalBinaryFileContent = malloc( executableBinaryFileSize );
    fh = fopen( originalBinaryFile, "rb" );
    (void)!fread( originalBinaryFileContent, 1, 5, fh);
    (void)!fread( originalBinaryFileContent, 1, executableBinaryFileSize, fh);
    fclose( fh );

    int programExeSize = 0x4d00 - _environment->program.startingAddress;
    if ( executableBinaryFileSize < programExeSize ) {
        programExeSize = executableBinaryFileSize;
    }
    char * programExe = malloc( programExeSize );
    memcpy( programExe, originalBinaryFileContent, programExeSize );
    executableBinaryFileSize -= programExeSize;

    char * programDats[MAX_TEMPORARY_STORAGE];
    int programDatsSize[MAX_TEMPORARY_STORAGE];
    int programDataCount = 0;

    int blockSize = 0x2000;
    if ( executableBinaryFileSize ) {
        char * originalBinaryFileContentPtr = originalBinaryFileContent + programExeSize;
        while( executableBinaryFileSize ) {
            if ( blockSize > executableBinaryFileSize ) {
                blockSize = executableBinaryFileSize;
                executableBinaryFileSize = blockSize;
            }
            programDats[programDataCount] = malloc( blockSize );
            programDatsSize[programDataCount] = blockSize;
            memcpy( programDats[programDataCount], originalBinaryFileContentPtr, blockSize );
            executableBinaryFileSize -= blockSize;
            originalBinaryFileContentPtr += blockSize;
            ++programDataCount;
        }
    }

    blockSize = 0x2000;

    char temporaryPath[MAX_TEMPORARY_STORAGE];
    strcpy( temporaryPath, _environment->temporaryPath );
    strcat( temporaryPath, " " );
    temporaryPath[strlen(temporaryPath)-1] = PATH_SEPARATOR;

    char outputFileName[MAX_TEMPORARY_STORAGE*2];

    // Now we are going to write down the effective files, that must
    // have the LOADM format, as follows:
    //
    // +------------+--------------....--------------+---------------+
    // |  PREAMBLE  |              DATA              |    POSTAMBLE  |
    // +------------+--------------....--------------+---------------+
    // |00|LEN |LOAD| .............................. |FF|00|00| EXEC |
    // +------------+--------------....--------------+---------------+
    // 

    sprintf( outputFileName, "%sprogram.exe", temporaryPath);
    fh = fopen( outputFileName, "wb" );
    fputc( 0x00, fh );
    fputc( programExeSize >> 8, fh );
    fputc( programExeSize & 0xff, fh );
    fputc( _environment->program.startingAddress >> 8, fh );
    fputc( _environment->program.startingAddress & 0xff, fh );
    fwrite( programExe, 1, programExeSize, fh );
    fputc( 0xff, fh );
    fputc( 0x00, fh );
    fputc( 0x00, fh );
    fputc( _environment->program.startingAddress >> 8, fh );
    fputc( _environment->program.startingAddress & 0xff, fh );
    fclose( fh );

    if ( programDataCount ) {
        for( int i=0; i<programDataCount; ++i ) {

            // The dat files will be loaded to a fixed position,
            // because they will be copied under ROM bank
            // using the LOADER.BAS.
            //
            // +------------+--------------....--------------+--------------+
            // |  PREAMBLE  |              DATA              |    POSTAMBLE |
            // +------------+--------------....--------------+--------------+
            // |00|LEN |3000| .............................. |FF|00|00|00|00|
            // +------------+--------------....--------------+--------------+

            sprintf( outputFileName, "%sprogram.%03d", temporaryPath, i);
            fh = fopen( outputFileName, "wb" );
            fputc( 0x00, fh );
            fputc( programDatsSize[i] >> 8, fh );
            fputc( programDatsSize[i] & 0xff, fh );
            fputc( 0x2a, fh );
            fputc( 0x00, fh );
            fwrite( programDats[i], 1, programDatsSize[i], fh );
            fputc( 0xff, fh );
            fputc( 0x00, fh );
            fputc( 0x00, fh );
            fputc( 0x00, fh );
            fputc( 0x00, fh );
            fclose( fh );

        }
    }

    // Now we are going to create the BASIC loader.

    char basFileName[MAX_TEMPORARY_STORAGE];

    sprintf( basFileName, "%sloader.bas", temporaryPath);
    fh = fopen( basFileName, "wb" );
    fprintf( fh, "1 REM ugBASIC loader\n" );
    fprintf( fh, "2 REM --[ PROLOGUE ]--\n" );
    fprintf( fh, "3 DATA  26, 80, 52, 16, 52,  6,142, 14\n");
    fprintf( fh, "4 DATA   0,191,  0, 31, 31, 65, 16,206\n");
    fprintf( fh, "5 DATA  15,  0, 16,255,  0, 33,198,255\n");
    fprintf( fh, "6 DATA 166,133,167,229, 90, 38,249, 53\n");
    fprintf( fh, "7 DATA   6, 53, 16, 28,159, 57, 26, 80\n");
    fprintf( fh, "8 DATA 206, 16,  0,142, 42,  0, 16,142\n");
    fprintf( fh, "9 DATA  42,  0,183,255,223,166,128,167\n");
    fprintf( fh, "10DATA 160, 51, 95, 17,131,  0,  0, 38\n");
    fprintf( fh, "11DATA 244,183,255,222, 28,159, 57, 26\n");
    fprintf( fh, "12DATA  80,206, 16,  0,142, 42,  0, 16\n");
    fprintf( fh, "13DATA 142,192,  0,183,255,223,134,  0\n");
    fprintf( fh, "14DATA 183,255,166,166,128,167,160, 51\n");
    fprintf( fh, "15DATA  95, 17,131,  0,  0, 38,244,134\n");
    fprintf( fh, "16DATA  62,183,255,166,183,255,222, 28\n");
    fprintf( fh, "17DATA 159, 57,  0\n" );
    fprintf( fh, "18FORA=&HE00 TO &HE71:READX:POKEA,X:NEXTA\n" );
    fprintf( fh, "19REM --[ MAIN ]--\n" );
    fprintf( fh, "20CLEAR 999: EXEC &HE00: PRINT \"LOADING, PLEASE WAIT\";\n" );

    int lineNr = 21;

    Bank * bank = _environment->expansionBanks;
    while( bank ) {
        int bankSize = bank->space - bank->remains;
        if ( bankSize ) {
            char line[MAX_TEMPORARY_STORAGE];

            if ( bankSize > blockSize ) {
                fprintf( fh, "%dLOADM\"BANK0.%03d\":PRINT\".\";\n", lineNr, bank->id);
                ++lineNr;

                fprintf( fh, "%dPOKE &HE51, &HC0: POKE &HE57, %d: EXEC &HE47\n", lineNr, bank->id);
                ++lineNr;

                fprintf( fh, "%dLOADM\"BANK1.%03d\":PRINT\".\";\n", lineNr, bank->id);
                ++lineNr;

                fprintf( fh, "%dPOKE &HE51, &HD0: EXEC &HE47\n", lineNr);
                ++lineNr;

            } else {
                fprintf( fh, "%dEXEC &HE46: LOADM\"BANK0.%03d\":PRINT\".\";\n", lineNr, bank->id);
                ++lineNr;

                fprintf( fh, "%dPOKE &HE51, &HC0: POKE &HE57, %d: EXEC &HE47\n", lineNr, bank->id);
                ++lineNr;

            }

        }
        bank = bank->next;
    }

    for( int i=0; i<programDataCount; ++i ) {
        fprintf( fh, "%dLOADM\"PROGRAM.%03d\":?\".\";\n", lineNr, i);
        ++lineNr;
        int address = 0x4d + i*32;
        int sizeHi = ( programDatsSize[i] >> 8 ) & 0xff;
        int sizeLo = ( programDatsSize[i] ) & 0xff;
        fprintf( fh, "%dPOKE3632,%d:POKE3625,%d:POKE3626,%d:EXEC3620\n", lineNr, address, sizeHi, sizeLo );
        ++lineNr;
    }
    fprintf( fh, "90PRINT \"...\";: LOADM\"PROGRAM.EXE\": PRINT \"...\": EXEC\n" );
    fclose( fh );

    char binaryName[MAX_TEMPORARY_STORAGE];

    char executableName[MAX_TEMPORARY_STORAGE];
    BUILD_TOOLCHAIN_DECB_GET_EXECUTABLE( _environment, executableName );

    strcpy( binaryName, _environment->exeFileName );
    Storage * storage = _environment->storage;
    char buffer[MAX_TEMPORARY_STORAGE];
    if ( storage ) {
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
        sprintf( buffer, filemask, 0 );
        if ( !strstr( buffer, ".dsk" ) ) {
            strcat( buffer, ".dsk" );
        }
        _environment->exeFileName = strdup( buffer );
    } else {
        strcpy( binaryName, _environment->exeFileName );
        char * p = strstr( binaryName, ".bin" );
        if ( p ) {
            strcpy( p, ".dsk" );
        }
        _environment->exeFileName = strdup( binaryName );
    }

    char commandLine[8*MAX_TEMPORARY_STORAGE];
    remove( _environment->exeFileName );
    sprintf( commandLine, "\"%s\" dskini \"%s\"", executableName, _environment->exeFileName );
    if ( system_call( _environment,  commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n");
        printf("Please use option '-I' to install chain tool.\n\n");
    };

    sprintf( commandLine, "\"%s\" copy -0 -t \"%s\" \"%s,LOADER.BAS\"",
        executableName, 
        basFileName, 
        _environment->exeFileName );
    if ( system_call( _environment,  commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n"); 
        printf("Please use option '-I' to install chain tool.\n\n");
    };

    remove( basFileName );

    sprintf( commandLine, "\"%s\" copy -2 \"%sprogram.exe\" \"%s,PROGRAM.EXE\"",
        executableName, 
        temporaryPath, 
        _environment->exeFileName );
    if ( system_call( _environment,  commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n"); 
        printf("Please use option '-I' to install chain tool.\n\n");
    };

    if ( programDataCount ) {
        for( int i=0; i<programDataCount; ++i ) {
            sprintf( commandLine, "\"%s\" copy -2 \"%sprogram.%03d\" \"%s,PROGRAM.%03d\"",
                executableName, 
                temporaryPath,
                i, 
                _environment->exeFileName,
                i );
            if ( system_call( _environment,  commandLine ) ) {
                printf("The compilation of assembly program failed.\n\n"); 
                printf("Please use option '-I' to install chain tool.\n\n");
            };
        }
    }

    if ( !storage ) {

    } else {
        strcpy( buffer, _environment->exeFileName );
        int i=0;
        while( storage ) {
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
                    buffer = malloc( size + 2 );
                    memset( buffer, 0, size + 2 );
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
                sprintf( commandLine, "\"%s\" copy -1 -b \"%s\" \"%s,%s\"",
                    executableName, 
                    dataFilename, 
                    _environment->exeFileName,
                    fileStorage->targetName );
                if ( system_call( _environment,  commandLine ) ) {
                    printf("The compilation of assembly program failed.\n\n"); 
                    printf("Please use option '-I' to install chain tool.\n\n");
                };

                remove( dataFilename );
                fileStorage = fileStorage->next;
            }

            storage = storage->next;
            ++i;

            if ( storage ) {

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
                sprintf( buffer, filemask, i );
                if ( !strstr( buffer, ".dsk" ) ) {
                    strcat( buffer, ".dsk" );
                }
                remove( buffer );
                sprintf( commandLine, "\"%s\" dskini \"%s\"", executableName, buffer );
                if ( system_call( _environment,  commandLine ) ) {
                    printf("The compilation of assembly program failed.\n\n");
                    printf("Please use option '-I' to install chain tool.\n\n");
                };

            }

        }

    }

    bank = _environment->expansionBanks;
    while( bank ) {
        int bankSize = bank->space - bank->remains;
        if ( bankSize > 0 ) {
            int effectiveSize = blockSize > bankSize ? bankSize : blockSize;
            char bankFileName[MAX_TEMPORARY_STORAGE];
            sprintf( bankFileName, "%sbank0.%03d", temporaryPath, bank->id );
            fh = fopen( bankFileName, "wb" );
            fputc( 0, fh );
            fputc( (unsigned char) ( ( effectiveSize >> 8 ) & 0xff ), fh );
            fputc( (unsigned char) ( ( effectiveSize ) & 0xff ), fh );
            fputc( 0x2a, fh );
            fputc( 0x00, fh );
            fwrite( &bank->data[0], 1, effectiveSize, fh );
            fputc( 0xff, fh );
            fputc( 0x00, fh );
            fputc( 0x00, fh );
            fputc( 0x2a, fh );
            fputc( 0x00, fh );
            fputc( 0x00, fh );
            fclose( fh );

            sprintf( commandLine, "\"%s\" copy -2 \"%sbank0.%03d\" \"%s,BANK0.%03d\"",
                executableName, 
                temporaryPath, 
                bank->id,
                _environment->exeFileName,
                bank->id );
            if ( system_call( _environment,  commandLine ) ) {
                printf("The compilation of assembly program failed.\n\n"); 
                printf("Please use option '-I' to install chain tool.\n\n");
                exit(0);
            };

            if ( bankSize > blockSize ) {
                effectiveSize = bankSize - blockSize;
                sprintf( bankFileName, "%sbank1.%03d", temporaryPath, bank->id );
                fh = fopen( bankFileName, "wb" );
                fputc( 0, fh );
                fputc( (unsigned char) ( ( effectiveSize >> 8 ) & 0xff ), fh );
                fputc( (unsigned char) ( ( effectiveSize ) & 0xff ), fh );
                fputc( 0x2a, fh );
                fputc( 0x00, fh );
                fwrite( &bank->data[blockSize], 1, bankSize - blockSize, fh );
                fputc( 0xff, fh );
                fputc( 0x00, fh );
                fputc( 0x00, fh );
                fputc( 0x2a, fh );
                fputc( 0x00, fh );
                fputc( 0x00, fh );
                fclose( fh );
                sprintf( commandLine, "\"%s\" copy -2 \"%sbank1.%03d\" \"%s,BANK1.%03d\"",
                    executableName, 
                    temporaryPath, 
                    bank->id,
                    _environment->exeFileName,
                    bank->id );
                if ( system_call( _environment,  commandLine ) ) {
                    printf("The compilation of assembly program failed.\n\n"); 
                    printf("Please use option '-I' to install chain tool.\n\n");
                    exit(0);
                };

            }

        }

        bank = bank->next;

    }

    remove( originalBinaryFile );

}

void target_linkage( Environment * _environment ) {

    switch( _environment->outputFileType ) {
        case OUTPUT_FILE_TYPE_BIN:
            generate_bin( _environment );
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

    remove( _environment->asmFileName );

    if ( _environment->analysis && _environment->listingFileName ) {
        target_analysis( _environment );
    }

}
