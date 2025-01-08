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

#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

extern char OUTPUT_FILE_TYPE_AS_STRING[][16];

static void apply_cartridge_header( Environment * _environment, char * _cartridge, long _size ) {

    // 0100-0103 — Entry point
    // After displaying the Nintendo logo, the built-in boot ROM jumps to the address $0100, 
    // which should then jump to the actual main program in the cartridge. Most commercial games 
    // fill this 4-byte area with a nop instruction followed by a jp $0150.

    // _cartridge[ 0x100 ] = 0x00; // NOP
    // _cartridge[ 0x101 ] = 0xc3; // JP $0150
    // _cartridge[ 0x102 ] = 0x50; // |
    // _cartridge[ 0x103 ] = 0x01; // |

    // 0104-0133 — Nintendo logo
    // This area contains a bitmap image that is displayed when the Game Boy is powered on. 
    // It must match the following (hexadecimal) dump, otherwise the boot ROM won’t allow 
    // the game to run:

    // char nintendoLogo[] = { 0xce, 0xed, 0x66, 0x66, 0xcc, 0x0d, 0x00, 0x0b, 
    //                         0x03, 0x73, 0x00, 0x83, 0x00, 0x0c, 0x00, 0x0d,
    //                         0x00, 0x08, 0x11, 0x1f, 0x88, 0x89, 0x00, 0x0e, 
    //                         0xdc, 0xcc, 0x6e, 0xe6, 0xdd, 0xdd, 0xd9, 0x99,
    //                         0xbb, 0xbb, 0x67, 0x63, 0x6e, 0x0e, 0xec, 0xcc, 
    //                         0xdd, 0xdc, 0x99, 0x9f, 0xbb, 0xb9, 0x33, 0x3e };
    // memcpy( &_cartridge[0x104], nintendoLogo, sizeof( nintendoLogo ) );

    // 0134-0143 — Title
    // These bytes contain the title of the game in upper case ASCII. If the title is 
    // less than 16 characters long, the remaining bytes should be padded with $00s.
    // Parts of this area actually have a different meaning on later cartridges, 
    // reducing the actual title size to 15 ($0134–$0142) or 11 ($0134–$013E) characters; 
    // see below.

    // int actualSizeForName = 11;

    // memset( &_cartridge[0x134], 0, actualSizeForName );
    // if ( _environment->program.name ) {
    //     strncpy( &_cartridge[0x134], strtoupper( _environment->program.name ), actualSizeForName);
    // } else {
    //     strncpy( &_cartridge[0x134], strtoupper( basename( _environment->exeFileName ) ), actualSizeForName );
    // }

    // 013F-0142 — Manufacturer code
    // In older cartridges these bytes were part of the Title (see above). In newer cartridges they 
    // contain a 4-character manufacturer code (in uppercase ASCII). The purpose of the manufacturer 
    // code is unknown.

    // _cartridge[0x13f] = 'U';
    // _cartridge[0x140] = 'G';
    // _cartridge[0x141] = 'B';
    // _cartridge[0x141] = 'S';

    // 0143 — CGB flag
    // In older cartridges this byte was part of the Title (see above). The CGB and later models interpret 
    // this byte to decide whether to enable Color mode (“CGB Mode”) or to fall back to monochrome 
    // compatibility mode (“Non-CGB Mode”).
    //
    // Typical values are:
    //
    // Value	Meaning
    // $80	The game supports CGB enhancements, but is backwards compatible with monochrome Game Boys
    // $C0	The game works on CGB only (the hardware ignores bit 6, so this really functions the same as $80)
    // Setting bit 7 will trigger a write of this register value to KEY0 register which sets the CPU mode.

    if ( _environment->currentMode == TILEMAP_MODE_BGB ) {
        _cartridge[0x143] = 0x00;
    } else {
        _cartridge[0x143] = 0x80;
    }

    // 0144–0145 — New licensee code
    // This area contains a two-character ASCII “licensee code” indicating the game’s publisher. It is 
    // only meaningful if the Old licensee is exactly $33 (which is the case for essentially all games 
    // made after the SGB was released); otherwise, the old code must be considered.

    // _cartridge[0x144] = 0x00;
    // _cartridge[0x145] = 0x00;

    // 014D — Header checksum
    // This byte contains an 8-bit checksum computed from the cartridge header bytes $0134–014C. 
    // The boot ROM computes the checksum as follows:

    unsigned char checksum = 0;
    for (unsigned short address = 0x0134; address <= 0x014c; address++) {
        checksum = checksum - (unsigned char) (_cartridge[address]) - 1;
    }

    _cartridge[0x14d] = checksum;

    // 014E-014F — Global checksum
    // These bytes contain a 16-bit (big-endian) checksum simply computed as the sum of all the bytes 
    // of the cartridge ROM (except these two checksum bytes).

    /* Update complement checksum */

    /* Update checksum */
    int chk = 0, i;
    _cartridge[0x14e] = 0;
    _cartridge[0x14f] = 0;
    for (i = 0; i < _size; ++i) {
        chk += (unsigned char) (_cartridge[i] );
    }
    _cartridge[0x14e] = (unsigned char) ((chk >> 8) & 0xff);
    _cartridge[0x14f] = (unsigned char) (chk & 0xff);
    
}

void generate_gb( Environment * _environment ) {

    char commandLine[8*MAX_TEMPORARY_STORAGE];
    char executableName[MAX_TEMPORARY_STORAGE];
    char binaryName[MAX_TEMPORARY_STORAGE];
    char binaryNameDefinitive[MAX_TEMPORARY_STORAGE];
    char listingFileName[MAX_TEMPORARY_STORAGE];

    BUILD_SAFE_REMOVE( _environment, _environment->exeFileName );

    BUILD_TOOLCHAIN_Z88DK_GET_EXECUTABLE_Z80ASM( _environment, executableName );

    BUILD_TOOLCHAIN_Z88DK_GET_LISTING_FILE( _environment, listingFileName );

    BUILD_TOOLCHAIN_Z88DK_EXEC( _environment, "gb", executableName, listingFileName, "gbz80" );

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
        strcat( p, "_code.bin");
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
        strcat( p, "_data.bin");
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

    strcpy( binaryNameDefinitive, _environment->exeFileName );
    p = strrstr( binaryName, ".gb" );
    if ( p ) {
        *p = 0;
        --p;
        strcat( p, ".bin");
    }
    BUILD_SAFE_MOVE( _environment, binaryName, binaryNameDefinitive );

    BUILD_TOOLCHAIN_Z88DK_GET_EXECUTABLE_APPMAKE( _environment, executableName );

    char pipes[256];

    #ifdef _WIN32
        strcpy( pipes, ">nul 2>nul");
    #else
        strcpy( pipes, ">/dev/null 2>/dev/null");
    #endif

    sprintf( commandLine, "\"%s\" +gb -b \"%s\" %s",
        executableName,
        binaryNameDefinitive,
        pipes );

    if ( system_call( _environment,  commandLine ) ) {
        printf("The compilation of assembly program failed.\n\n");
        printf("Please use option '-I' to install chain tool.\n\n");
        return;
    }; 

    char * cartridge;
    binaryFile = fopen( _environment->exeFileName, "rb" );
    fseek( binaryFile, 0, SEEK_END );
    size = ftell( binaryFile );
    cartridge = malloc( size );
    fseek( binaryFile, 0, SEEK_SET );
    (void)!fread( cartridge, size, 1, binaryFile );
    fclose( binaryFile );

    apply_cartridge_header( _environment, cartridge, size );

    binaryFile = fopen( _environment->exeFileName, "wb" );
    fwrite( cartridge, size, 1, binaryFile );
    fclose( binaryFile );

//     strcpy( binaryName, _environment->asmFileName );
//     p = strstr( binaryName, ".asm" );
//     if ( p ) {
//         strcat( p, "_data_user.bin");
//     }
//     remove(binaryName);

//     strcpy( binaryName, _environment->asmFileName );
//     p = strstr( binaryName, ".asm" );
//     if ( p ) {
//         strcat( p, "_code_user.bin");
//     }
//     remove(binaryName);

// }

// void generate_rom( Environment * _environment ) {

//     char commandLine[8*MAX_TEMPORARY_STORAGE];
//     char executableName[MAX_TEMPORARY_STORAGE];
//     char binaryName[MAX_TEMPORARY_STORAGE];
//     char listingFileName[MAX_TEMPORARY_STORAGE];

//     char * p;

//     strcpy( binaryName, _environment->asmFileName );
//     p = strstr( binaryName, ".asm" );
//     if ( p ) {
//         *p = 0;
//         --p;
//         strcat( p, ".bin");
//     }

//     BUILD_TOOLCHAIN_Z88DK_GET_EXECUTABLE_APPMAKE( _environment, executableName );

//     char pipes[256];

//     #ifdef _WIN32
//         strcpy( pipes, ">nul 2>nul");
//     #else
//         strcpy( pipes, ">/dev/null 2>/dev/null");
//     #endif

//     sprintf( commandLine, "\"%s\" +msxrom -b \"%s\" %s",
//         executableName,
//         binaryName,
//         pipes );

//     p = strstr( binaryName, ".bin" );
//     if ( p ) {
//         *(p+1) = 'r';
//         *(p+2) = 'o';
//         *(p+3) = 'm';
//     }

//     if ( system_call( _environment,  commandLine ) ) {
//         printf("The compilation of assembly program failed.\n\n");
//         printf("Please use option '-I' to install chain tool.\n\n");
//         return;
//     }; 

//     remove( _environment->exeFileName );

//     BUILD_SAFE_MOVE( _environment, binaryName, _environment->exeFileName );

//     char symbolName[MAX_TEMPORARY_STORAGE];
//     strcpy( symbolName, _environment->exeFileName );
//     p = strstr( symbolName, ".rom" );
//     if ( p ) {
//         *p = 0;
//         --p;
//         strcat( p, ".sym");

//         strcpy( binaryName, _environment->asmFileName );
//         p = strstr( binaryName, ".asm" );
//         if ( p ) {
//             *p = 0;
//             --p;
//             strcat( p, ".sym");
//             BUILD_SAFE_MOVE( _environment, binaryName, symbolName );
//         }
//     }

//     if ( _environment->listingFileName ) {
//         strcpy( binaryName, _environment->asmFileName );
//         p = strstr( binaryName, ".asm" );
//         if ( p ) {
//             *p = 0;
//             --p;
//             strcat( p, ".lis");
//             BUILD_SAFE_MOVE( _environment, binaryName, _environment->listingFileName );
//         }

//         if ( _environment->profileFileName && _environment->profileCycles ) {
//             strcpy( binaryName, _environment->profileFileName );
//             if ( _environment->executerFileName ) {
//                 sprintf(executableName, "%s", _environment->executerFileName );
//             } else if( access( "runz80.exe", F_OK ) == 0 ) {
//                 sprintf(executableName, "%s", "runz80.exe" );
//             } else {
//                 sprintf(executableName, "%s", "runz80" );
//             }

//             sprintf( commandLine, "\"%s\" -m -p \"%s\" %d -l 4000 \"%s\" -R 4010 -u \"%s\" \"%s\"",
//                 executableName,
//                 binaryName,
//                 _environment->profileCycles ? _environment->profileCycles : 1000000,
//                 _environment->exeFileName,
//                 _environment->listingFileName,
//                 pipes );

//             if ( system_call( _environment,  commandLine ) ) {
//                 printf("The profiling of assembly program failed.\n\n");
//                 return;
//             }; 

//         }

//     }

//     strcpy( binaryName, _environment->asmFileName );
//     p = strstr( binaryName, ".asm" );
//     if ( p ) {
//         strcat( p, "_data_user.bin");
//     }
//     remove(binaryName);

//     strcpy( binaryName, _environment->asmFileName );
//     p = strstr( binaryName, ".asm" );
//     if ( p ) {
//         strcat( p, "_code_user.bin");
//     }
//     remove(binaryName);

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
void target_linkage( Environment * _environment ) {

    switch( _environment->outputFileType ) {
        case OUTPUT_FILE_TYPE_GB:
            generate_gb( _environment );
            break;
        default:
            CRITICAL_UNSUPPORTED_OUTPUT_FILE_TYPE( OUTPUT_FILE_TYPE_AS_STRING[_environment->outputFileType] );
    }

}
