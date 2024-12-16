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

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sid_file.h"

/****************************************************************************
 * DATA TYPES 
 ****************************************************************************/

// The SID file header v1
// ======================

typedef struct _SIDFILEHeader {

  unsigned char magicID[4]; // 'PSID' or 'RSID'

  unsigned char version[2];

  unsigned char dataOffset[2];

  unsigned char loadAddress[2];

  unsigned char initAddress[2];

  unsigned char playAddress[2];

  unsigned char songs;

  unsigned char startSong;

  unsigned char speed[4];

  unsigned char name[32];
  unsigned char author[32];
  unsigned char released[32];

  unsigned char flags[2];

  unsigned char startPage;

  unsigned char pageLength;

  unsigned char secondSIDAddress;

  unsigned char thirdSIDAddres;

} SIDFILEHeader;

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

SIDFILE * sidFileRead( char * _filename ) {

    SIDFILE * result = NULL;

    FILE * fhandle = fopen( _filename, "rb" );

    if ( !fhandle ) {
        goto failed;
    }

    result = malloc( sizeof( SIDFILE ) );
    memset( result, 0, sizeof( SIDFILE ) );

    fseek( fhandle, 0, SEEK_END );
    int fileSize = ftell( fhandle );
    fseek( fhandle, 0, SEEK_SET );

    SIDFILEHeader * header = NULL;

    char signature[4];
    (void)!fread( signature, 4, 1, fhandle );

    // This is a four byte long ASCII character string containing the value
    // 0x50534944 or 0x52534944. 'RSID' (Real SID) denotes that the file strictly
    // requires a true Commodore-64 environment to run properly. 'PSID' files will
    // generally run trouble-free on older PlaySID and libsidplay1 based emulators,
    // too.

    if ( memcmp( signature, "RSID", 4 ) && memcmp( signature, "PSID", 4 ) ) {
        printf( "Signature wrong: %2.2x%2.2x%2.2x%2.2x\n", signature[0], signature[1], signature[2], signature[3] );
        goto failed;
    }

    header = malloc( sizeof( SIDFILEHeader ) );
    memset( header, 0, sizeof( SIDFILEHeader ) );

    fseek( fhandle, 0, SEEK_SET );
    (void)!fread( header, sizeof( SIDFILEHeader ), 1, fhandle );

    // RSID is based on PSIDv2NG with the following modifications:

    // magicID = RSID
    // version = 2, 3 and 4 only
    // loadAddress = 0 (reserved)
    // playAddress = 0 (reserved)
    // speed = 0 (reserved)
    // psidSpecific flag is called C64BASIC flag

    // The above fields MUST be checked and if any differ from the above then the
    // tune MUST be rejected. The definitions above will force tunes to contain
    // proper hardware configuration code and install valid interrupt handlers.

    // See section "The SID file environment" mentioned later in this document for the
    // default C64 power-on environment for each SID file format.

    // Available version number can be 0001, 0002, 0003 or 0004. Headers of version 2,
    // 3 and 4 provide additional fields. RSID and PSID v2NG files must have 0002,
    // 0003 or 0004 here.

    // This is the offset from the start of the file to the C64 binary data area.
    // Because of the fixed size of the header, this is either 0x0076 for version 1
    // and 0x007C for version 2, 3 and 4.

    int dataOffset = (header->dataOffset[0] << 8) | header->dataOffset[1];
    switch ( header->version[1] ) {
        case 1:
            if ( dataOffset != 0x76 ) {
                printf( "Data offset wrong: %2.2x\n", dataOffset );
                goto failed;
            }
            break;
        case 2:
        case 3:
        case 4:
            if ( dataOffset != 0x7c ) {
                printf( "Data offset wrong: %2.2x\n", dataOffset );
                goto failed;
            }
            break;
    }

    (void)!fseek( fhandle, dataOffset, SEEK_SET );

    // The C64 memory location where to put the C64 data. 0 means the data are in
    // original C64 binary file format, i.e. the first two bytes of the data contain
    // the little-endian load address (low byte, high byte). This must always be true
    // for RSID files. Furthermore, the actual load address must NOT be less than
    // $07E8 in RSID files.

    result->loadAddress = (header->loadAddress[0]<<8) | header->loadAddress[1];

    // You must be absolutely sure what to enter here. There is no way to detect
    // automatically whether the first two bytes in a C64 data file are meant to be a
    // load address or some arbitrary bytes of code or data. Unless your C64 file is
    // not a normal binary file and thus has no load address in front, you need not
    // enter anything else than 0 here. The SID tune will not play if you specify a
    // load address which is present in the C64 file already.

    if ( result->loadAddress == 0 ) {
        (void)!fread( &header->loadAddress[0], 2, 1, fhandle );
        result->loadAddress = (header->loadAddress[1]<<8) | header->loadAddress[0];
    }

    // Normal C64 binary data files have a load address in their first two bytes, so
    // they can be loaded to a pre-defined destination address by executing
    // LOAD"FILE",8,1, for instance. If a load address is explicitly specified in the
    // sidtune info file, some sidtune converters and utilities conjecture that the
    // C64 data don't have a load address in their first two bytes. Hence, the
    // explicit load address from the info file is moved in front of the C64 data to
    // create a valid C64 binary file which can be easily loaded on a C64, too. If
    // that C64 file were to be saved, it would contain two superfluous data bytes at
    // offset 2 if an original load address had been in the first two bytes of the
    // old file. This process of adding a duplicate load address can be repeated. The
    // file loader strips off the first two bytes (the used load address) and puts
    // the rest of the file contents (including the now obsolete load address at file
    // offset 2) into memory. If the new load address is the same than the old one
    // the two added bytes cause the whole data to be displaced by two bytes, which
    // most likely results in malfunctioning code. Also, superfluous bytes in memory
    // then can confuse disassemblers which start at the beginning of the file or
    // memory buffer.

    result->initAddress = (header->initAddress[0]<<8) | header->initAddress[1];

    // The start address of the machine code subroutine that initializes a song,
    // accepting the contents of the 8-bit 6510 Accumulator as the song number
    // parameter. 0 means the address is equal to the effective load address.

    if ( result->initAddress == 0 ) {
        result->initAddress = result->loadAddress;
    }

    // In RSID files initAddress must never point to a ROM area ($A000-$BFFF or
    // $D000-$FFFF) or be lower than $07E8. Also, if the C64 BASIC flag is set,
    // initAddress must be 0.

    if ( memcmp( signature, "RSID", 4 ) == 0 ) {
        if ( (result->initAddress >= 0xa000) && (result->initAddress <= 0xbfff) ) {
            printf( "RSID on ROM: %4.4x\n", result->initAddress );
            goto failed;
        }
        if ( (result->initAddress < 0x07e8) ) {
            printf( "RSID on ZERO PAGE: %4.4x\n", result->initAddress );
            goto failed;
        }
    }

    // The start address of the machine code subroutine that can be called frequently
    // to produce a continuous sound. 0 means the initialization subroutine is
    // expected to install an interrupt handler, which then calls the music player at
    // some place. This must always be true for RSID files.

    result->playAddress = (header->playAddress[0]<<8) | header->playAddress[1];

    // The number of songs (or sound effects) that can be initialized by calling the
    // init address. The minimum is 1. The maximum is 256.

    result->songs = header->songs;

    // The song number to be played by default. This value is optional. It often
    // specifies the first song you would hear upon starting the program is has been
    // taken from. It has a default of 1.

    result->startSong = header->startSong;

    // unsigned char speed[4];

    // This is a 32 bit big endian number.
    // For version 1 and 2 and for version 2NG, 3 and 4 with PlaySID specific flag
    // (+76) set, the 'speed' should be handled as follows:
    // Each bit in 'speed' specifies the speed for the corresponding tune number,
    // i.e. bit 0 specifies the speed for tune 1. If there are more than 32 tunes,
    // the speed specified for tune 32 is the same as tune 1, for tune 33 it is the
    // same as tune 2, etc.
    // For version 2NG, 3 and 4 with PlaySID specific flag (+76) cleared, the 'speed'
    // should be handled as follows:
    // Each bit in 'speed' specifies the speed for the corresponding tune number,
    // i.e. bit 0 specifies the speed for tune 1. If there are more than 32 tunes,
    // the speed specified for tune 32 is also used for all higher numbered tunes.
    // For all version counts:
    // A 0 bit specifies vertical blank interrupt (50Hz PAL, 60Hz NTSC), and a 1 bit
    // specifies CIA 1 timer interrupt (default 60Hz).
    // Surplus bits in 'speed' should be set to 0.
    // For RSID files 'speed' must always be set to 0.

    // unsigned char name[32];
    // unsigned char author[32];
    // unsigned char released[32];

    // These are 32 byte long ASCII character strings. Upon evaluating the header,
    // these fields may hold a character string of 32 bytes which is not zero
    // terminated. For less than 32 characters the string should be zero terminated.
    // The maximum number of available free characters is 32.

    // unsigned char flags[2];
    // unsigned char startPage;
    // unsigned char pageLength;
    // unsigned char secondSIDAddress;
    // unsigned char thirdSIDAddres;

    fileSize -= dataOffset;
    result->data = malloc( fileSize );
    memset( result->data, 0, fileSize );
    (void)!fread( result->data, fileSize, 1, fhandle );
    result->size = fileSize;
    
    free( header );

    return result;

failed:

    if ( fhandle ) {
        fclose( fhandle );
    }

    if ( header ) {
        free(header);
    }

    if ( result ) {
        free(result);
    }

    return NULL;
}

int sidFileSize( SIDFILE * _sid_file ) {
    return _sid_file->size;
}

unsigned char * sidFileData( SIDFILE * _sid_file ) {
    return _sid_file->data;
}

void sidfileFree( SIDFILE * _sid_file ) {

    free( _sid_file->data );
    free( _sid_file );

}