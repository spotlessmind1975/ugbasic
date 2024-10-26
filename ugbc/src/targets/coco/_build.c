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

    char commandLine[8*MAX_TEMPORARY_STORAGE];
    char executableName[MAX_TEMPORARY_STORAGE];
    char listingFileName[MAX_TEMPORARY_STORAGE];
    char binaryName[MAX_TEMPORARY_STORAGE];

    BUILD_SAFE_REMOVE( _environment, _environment->exeFileName );

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
        CRITICAL( "cannot create dsk file");
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

    if ( executableBinaryFileSize ) {
        char * originalBinaryFileContentPtr = originalBinaryFileContent + programExeSize;
        int blockSize = 0x2000;
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

    // 206	16	0

    sprintf( basFileName, "%sloader.bas", temporaryPath);
    fh = fopen( basFileName, "wb" );
    fprintf( fh, "1REM ugBASIC %s\n", UGBASIC_VERSION );
    fprintf( fh, "2DATA26,80,52,16,52,6,142,14,0,159,31,31\n" );
    fprintf( fh, "3DATA65,16,206,15,0,16,223,33,198,255,166\n" );
    fprintf( fh, "4DATA133,167,229,90,38,249,53,6,53,16,28\n" );
    fprintf( fh, "5DATA159,57,26,80,142,42,0,16,142,42,0\n" );
    fprintf( fh, "6DATA183,255,223,206,16,0,166,128,167,160\n" );
    fprintf( fh, "7DATA51,95,17,131,0,0,38,244,183,255,222\n" );
    fprintf( fh, "9DATA28,159,57\n" );
    fprintf( fh, "10FORA=&HE00 TO&HE44:READX:POKEA,X:NEXTA\n" );
    fprintf( fh, "11POKE27,12:POKE28,0:POKE29,12:POKE30,172\n");
    fprintf( fh, "12POKE31,13:POKE32,0:POKE33,13:POKE34,64:POKE35,13:POKE36,172\n" );
    fprintf( fh, "13POKE37,13:POKE38,172:POKE39,13:POKE40,250:EXEC3584:? \"WAIT\";\n" );
    for( int i=0; i<programDataCount; ++i ) {
        int lineNr = 14 + i*2;
        fprintf( fh, "%dLOADM\"P.%02d\":?\".\";\n", lineNr, i);
        lineNr = 15 + i*2;
        int address = 0x4d + i*32;
        int sizeHi = ( programDatsSize[i] >> 8 ) & 0xff;
        int sizeLo = ( programDatsSize[i] ) & 0xff;
        fprintf( fh, "%dPOKE3627,%d:POKE3633,%d:POKE3634,%d:EXEC3620\n", lineNr, address, sizeHi, sizeLo );
    }
    fprintf( fh, "90?\"*\";:LOADM\"P.\":?\".\":EXEC10752\n" );
    fclose( fh );

    // char executableName[MAX_TEMPORARY_STORAGE];
    // char listingFileName[MAX_TEMPORARY_STORAGE];
    char binaryName[MAX_TEMPORARY_STORAGE];
    // char originalFileName[MAX_TEMPORARY_STORAGE];

    // int fileSize = 0;
    // int standardSize = 0;
    // int ondemandSize = 0;
    // int blockSize = 0;
    // int blocks = 0;
    // int block = 0;
    // int remainSize = 0;

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

    sprintf( commandLine, "\"%s\" copy -2 \"%sprogram.exe\" \"%s,P\"",
        executableName, 
        temporaryPath, 
        _environment->exeFileName );
    if ( system_call( _environment,  commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n"); 
        printf("Please use option '-I' to install chain tool.\n\n");
    };

    sprintf( commandLine, "%sprogram.exe", temporaryPath);
    remove( commandLine );

    if ( programDataCount ) {
        for( int i=0; i<programDataCount; ++i ) {
            sprintf( commandLine, "\"%s\" copy -2 \"%sprogram.%03d\" \"%s,P.%02d\"",
                executableName, 
                temporaryPath,
                i, 
                _environment->exeFileName,
                i );
            if ( system_call( _environment,  commandLine ) ) {
                printf("The compilation of assembly program failed.\n\n"); 
                printf("Please use option '-I' to install chain tool.\n\n");
            };
            sprintf( commandLine, "%sprogram.%03d", temporaryPath, i);
            remove( commandLine );            
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
