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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

extern char OUTPUT_FILE_TYPE_AS_STRING[][16];

void target_linkage( Environment * _environment ) {

    char commandLine[8*MAX_TEMPORARY_STORAGE];
    char executableName[MAX_TEMPORARY_STORAGE];
    char listingFileName[MAX_TEMPORARY_STORAGE];
    char binaryName[MAX_TEMPORARY_STORAGE];
    char originalFileName[MAX_TEMPORARY_STORAGE];

    if (  _environment->outputFileType != OUTPUT_FILE_TYPE_DSK && _environment->outputFileType != OUTPUT_FILE_TYPE_BIN ) {
        CRITICAL_UNSUPPORTED_OUTPUT_FILE_TYPE( OUTPUT_FILE_TYPE_AS_STRING[_environment->outputFileType] )
    }

    BUILD_SAFE_REMOVE( _environment, _environment->exeFileName );

    if ( _environment->outputFileType == OUTPUT_FILE_TYPE_DSK ) {
        strcpy( originalFileName, _environment->exeFileName );
        strcpy( binaryName, _environment->exeFileName );
        char * p = strstr( binaryName, ".dsk" );
        if ( p ) {
            strcpy( p, ".bin" );
        }
        strcpy( _environment->exeFileName, binaryName );
    }

    BUILD_TOOLCHAIN_ASM6809_GET_EXECUTABLE( _environment, executableName );

    BUILD_TOOLCHAIN_ASM6809_GET_LISTING_FILE( _environment, listingFileName );

    BUILD_TOOLCHAIN_ASM6809EXEC( _environment, "-C", 0x2A00, executableName, listingFileName );

    if ( _environment->outputFileType == OUTPUT_FILE_TYPE_DSK ) {

        int fileSize = 0;
        int standardSize = 0;
        int ondemandSize = 0;
        int blockSize = 0;
        int blocks = 0;
        int block = 0;
        int remainSize = 0;

        strcpy( _environment->exeFileName, originalFileName );

        BUILD_TOOLCHAIN_DECB_GET_EXECUTABLE( _environment, executableName );

        FILE * fh = fopen( binaryName, "rb" );
        if ( fh ) {
            fseek( fh, 0, SEEK_END );
            fileSize = ftell( fh );
            fclose( fh );
        } else {
            CRITICAL( "cannot create dsk file");
        }

        if ( fileSize < 22016 ) {
            
            standardSize = fileSize - 10;
            ondemandSize = 0;
            blockSize = 4096;
            blocks = 0;
            remainSize = 0;

        } else {

            standardSize = 22016;
            ondemandSize = fileSize - standardSize - 10;
            blockSize = 4096;
            blocks = ( ondemandSize / blockSize ) + 1;
            remainSize = ondemandSize - ( ( blocks - 1 ) * blockSize ) - 5;

        }

        int programExeSize = 5 + standardSize + 5;

        char * programExe = malloc( programExeSize );
        memset( programExe, 0, programExeSize );
        fh = fopen( binaryName, "rb" );
        if ( !fh ) {
            CRITICAL( "cannot create dsk file");
        }        
        (void)!fread( &programExe[0], 1, standardSize + 5, fh );
        programExe[1] = standardSize >> 8;
        programExe[2] = standardSize & 0xff;
        memcpy( &programExe[standardSize + 5], &data_coco_footer_bin[0], data_coco_footer_bin_len );

        int programBlockSize = 5 + blockSize + 5;
        char * programBlocks = malloc( programBlockSize * blocks );
        memset( &programBlocks[0], 0, programBlockSize * blocks );

        for( int block; block < blocks; ++block ) {

            memcpy( &programBlocks[block * programBlockSize], &data_coco_header_bin[0], data_coco_header_bin_len );

            if ( block < ( blocks - 1 ) ) {
                (void)!fread( &programBlocks[block * programBlockSize + data_coco_header_bin_len], 1, blockSize, fh );
                memcpy( &programBlocks[block * programBlockSize + data_coco_header_bin_len + blockSize], &data_coco_footer_bin[0], data_coco_footer_bin_len );
            } else {
                (void)!fread( &programBlocks[block * programBlockSize + data_coco_header_bin_len], 1, remainSize + 5, fh );
                programBlocks[block * programBlockSize + 1] = ( remainSize + 5 ) >> 8;
                programBlocks[block * programBlockSize + 2] = ( remainSize + 5 ) & 0xff;
                memcpy( &programBlocks[block * programBlockSize + data_coco_header_bin_len + remainSize + 5], &data_coco_footer_bin[0], data_coco_footer_bin_len );
            }

        }

        fclose( fh );

        sprintf( commandLine, "\"%s\" dskini \"%s\"", executableName, originalFileName );
        if ( system_call( _environment,  commandLine ) ) {
            printf("The compilation of assembly program failed.\n\n");
            printf("Please use option '-I' to install chain tool.\n\n");
        };

        char * loaderBas = malloc( MAX_TEMPORARY_STORAGE * 100 );

        strcpy( loaderBas, "1 REM ugBASIC loader\n" );
        strcat( loaderBas, "2 REM --[ PROLOGUE ]--\n" );
        strcat( loaderBas, "3 DATA 26,80,52,16,52,6,142,14,0,159,31,31\n" );
        strcat( loaderBas, "4 DATA 65,16,206,15,0,16,223,33,198,255,166\n" );
        strcat( loaderBas, "5 DATA 133,167,229,90,38,249,53,6,53,16,28\n" );
        strcat( loaderBas, "6 DATA 159,57,26,80,142,42,0,16,142,42,0\n" );
        strcat( loaderBas, "7 DATA 183,255,223,206,16,0,166,128,167,160\n" );
        strcat( loaderBas, "8 DATA 51,95,17,131,0,0,38,244,183,255,222\n" );
        strcat( loaderBas, "9 DATA 28,159,57\n" );
        strcat( loaderBas, "11FORA=&HE00 TO &HE44:READX:POKEA,X:NEXTA\n" );
        strcat( loaderBas, "12REM --[ MAIN ]--\n" );
        strcat( loaderBas, "13CLEAR 999: PRINT \"LOADING, PLEASE WAIT\";\n" );

        for( block = 0; block < blocks; ++block ) {

            int lineNr = 14 + block*2;
            char line[MAX_TEMPORARY_STORAGE];
            sprintf( line, "%dLOADM\"PROGRAM.%03d\":PRINT\".\";\n", lineNr, block);
            strcat( loaderBas, line );

            lineNr = 15 + block*2;
            int address = 128 + block*16;
            sprintf( line, "%dPOKE 3627, %d: EXEC 3620\n", lineNr, address);
            strcat( loaderBas, line );

        }

        strcat( loaderBas, "90EXEC 3584: PRINT \"...\";: LOADM\"PROGRAM.EXE\": PRINT \"...\": EXEC\n");

        char tempFileName[MAX_TEMPORARY_STORAGE];
        sprintf( tempFileName, "loader.bas" );
        
        fh = fopen( tempFileName, "wb" );
        fwrite( loaderBas, 1, strlen(loaderBas), fh );
        fclose( fh );
        
        sprintf( commandLine, "\"%s\" copy -0 -t \"%s\" \"%s,LOADER.BAS\"",
            executableName, 
            tempFileName, 
            originalFileName );
        if ( system_call( _environment,  commandLine ) ) {
            printf("The compilation of assembly program failed.\n\n"); 
            printf("Please use option '-I' to install chain tool.\n\n");
        };

        sprintf( tempFileName, "program.exe" );

        fh = fopen( tempFileName, "wb" );
        fwrite( programExe, 1, programExeSize, fh );
        fclose( fh );
        
        sprintf( commandLine, "\"%s\" copy -2 \"%s\" \"%s,PROGRAM.EXE\"",
            executableName, 
            tempFileName, 
            originalFileName );
        if ( system_call( _environment,  commandLine ) ) {
            printf("The compilation of assembly program failed.\n\n"); 
            printf("Please use option '-I' to install chain tool.\n\n");
        };

        for( block = 0; block < blocks; ++block ) {

            sprintf( tempFileName, "program.%03d", block );

            fh = fopen( tempFileName, "wb" );
            fwrite( &programBlocks[block * programBlockSize], 1, ( block < ( blocks - 1 ) ) ? programBlockSize : ( remainSize + 15 ), fh );
            fclose( fh );
            
            sprintf( commandLine, "\"%s\" copy -2 \"%s\" \"%s,PROGRAM.%03d\"",
                executableName, 
                tempFileName, 
                originalFileName,
                block );
            if ( system_call( _environment,  commandLine ) ) {
                printf("The compilation of assembly program failed.\n\n"); 
                printf("Please use option '-I' to install chain tool.\n\n");
            };

        }

        BUILD_SAFE_REMOVE( _environment, binaryName );
        BUILD_SAFE_REMOVE( _environment, tempFileName );
    
    }

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

void target_cleanup( Environment * _environment ) {

    remove( _environment->asmFileName );

    if ( _environment->analysis && _environment->listingFileName ) {
        target_analysis( _environment );
    }

}
