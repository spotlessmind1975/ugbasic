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
 * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

#include "d64.h"

/****************************************************************************
 * DATA TYPES AND CONSTANTS
 ****************************************************************************/

// The various DOS version for each format.
D64DosVersion versionByFormat[] = {
    0x41,       // Original CBM DOS v2.6
    0x41,       // SpeedDOS+
    0x41,       // Professional DOS Initial
    0x41,       // Professional DOS Version 1/Prototype
    0x41,       // ProfDOS Release
    0x41,       // Dolphin-DOS 2.0/3.0 (35)
    0x41,       // Dolphin-DOS 2.0/3.0 (40)
    0x41,       // PrologicDOS 1541 (35)
    0x50,       // PrologicDOS 1541	(40)
    0x41,       // ProSpeed 1571 2.0 (35)
    0x50        // ProSpeed 1571 2.0 (40)
};

// The various DOS TYPE for each format.
unsigned char dosTypeByFormat[][3] = {
    "2A",       // Original CBM DOS v2.6
    "2A",       // SpeedDOS+
    "2A",       // Professional DOS Initial
    "2A",       // Professional DOS Version 1/Prototype
    "4A",       // ProfDOS Release
    "2A",       // Dolphin-DOS 2.0/3.0 (35)
    "2A",       // Dolphin-DOS 2.0/3.0 (40)
    "2A",       // PrologicDOS 1541 (35)
    "2P",       // PrologicDOS 1541	(40)
    "2A",       // ProSpeed 1571 2.0 (35)
    "2P"        // ProSpeed 1571 2.0 (40)
};

// This is the numer of sectors for each track.
int D64SectorsPerTrack[] = {
    // 1-17
    21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
    // 18-24
    19, 19, 19, 19, 19, 19, 19,
    // 25-30
    18, 18, 18, 18, 18, 18,
    // 31-35
    17, 17, 17, 17, 17,
    // 36-40
    17, 17, 17, 17, 17,
    // 41-42
    17, 17
};

// This is the starting offset (in memory) of each track.
int D64OffsetPerTrack[] = {
    // 1-8
    0x00000, 0x01500, 0x02A00, 0x03F00, 0x05400, 0x06900, 0x07E00, 0x09300,
    // 9-16
    0x0A800, 0x0BD00, 0x0D200, 0x0E700, 0x0FC00, 0x11100, 0x12600, 0x13B00,
    // 17-24
    0x15000, 0x16500, 0x17800, 0x18B00, 0x19E00, 0x1B100, 0x1C400, 0x1D700,
    // 25-32
    0x1EA00, 0x1FC00, 0x20E00, 0x22000, 0x23200, 0x24400, 0x25600, 0x26700,
    // 33-40
    0x27800, 0x28900, 0x29A00, 0x2AB00, 0x2BC00, 0x2CD00, 0x2DE00, 0x2EF00,
    // 41-42
    0x30000, 0x31100
};

/****************************************************************************
 * STATIC FUNCTIONS
 ****************************************************************************/

static void d64_free_sectors_on_bam( D64BAMEntry * _entry, D64Sector _sectors );
static void d64_free_sector_on_bam( D64BAMEntry * _entry, D64Sector _sector );

/**
 * @brief Calculate the offset (in bytes) for the given track and sector.
 * 
 * @param _track Number of the track (1..42)
 * @param _sector Number of the sector (0..21)
 * @return int The number of bytes of starting position
 */
static int d64_calculate_offset( D64Track _track, D64Sector _sector ) {

    int offset = 0;

    // Let's take the starting offset in memory for the given track.
    offset = D64OffsetPerTrack[_track-1];

    // Next, move ahead of 256 bytes for each sector.
    offset += _sector * sizeof( D64SectorData );

    return offset;

}

/**
 * @brief Calculate the offset (as sectors) for the given track and sector.
 * 
 * @param _track Number of the track (1..42)
 * @param _sector Number of the sector (0..21)
 * @return int The number of sectors of starting position
 */
static int d64_calculate_sectors( D64Track _track, D64Sector _sector ) {

    int offset = 0;

    // In order to calculate the starting position, expressed as sectors,
    // we need to sum up all the sectors of each track, from the first
    // to the one needed.
    for(int i=0; i<(_track-1); ++i ) {
        offset += D64SectorsPerTrack[i];
    }

    // Finally, we can sum the number
    offset += _sector;

    return offset;

}

/**
 * @brief Get the address in memory for the given data sector
 * 
 * @param _handle Handle of the disk image
 * @param _track Number of the track (1..42)
 * @param _sector Number of the sector (0..21)
 * @return D64SectorData* Address in memory of the data sector
 */
static D64SectorData * d64_get_sector( D64Handle * _handle, D64Track _track, D64Sector _sector ) {

    // Retrieve the offset in memory for the given track / sector,
    // given in bytes.
    int offset = d64_calculate_offset( _track, _sector );
    
    // printf("offset = %d\n", offset );

    // Return the address of the disk image in memory,
    // by using the calculated offset.
    return (D64SectorData *) &_handle->content[offset];

}

/**
 * @brief Set the BAM's entry as completely free
 * 
 * @param _entry Address of BAM's entry
 * @param _sectors Total sectors free for this track
 */
static void d64_free_sectors_on_bam( D64BAMEntry * _entry, D64Sector _sectors ) {

    // By default, sectors that are not eligible to be present
    // in a track are always occupied.
    _entry->bitmappedFree[0] = 0x0;
    _entry->bitmappedFree[1] = 0x0;
    _entry->bitmappedFree[2] = 0x0;

    // For each sector (0...(sectors-1)), we are going to put it as free.
    for( int i=0; i<_sectors; ++i ) {
        d64_free_sector_on_bam( _entry, i );
    }

}

/**
 * @brief Set the BAM's entry free for a specific sector
 * 
 * @param _entry Address to BAM's entry
 * @param _sector Sector to free (0...21)
 */
static void d64_free_sector_on_bam( D64BAMEntry * _entry, D64Sector _sector ) {

    // Let's calculate the offset and the bitmap for the given sector.
    int offset = _sector >> 3;
    int bitmap = 1 << ( _sector & 0x07 );

    // If the sector is already free...
    if ( ( _entry->bitmappedFree[offset] | (bitmap) ) == _entry->bitmappedFree[offset] ) {

        // ... we will do nothing.

    } else {

        // Put the sector as "free".
        _entry->bitmappedFree[offset] |= bitmap;

        // Increase the number of free sectors.
        ++_entry->freeSectors;

    }


}

/**
 * @brief Set the BAM's entry allocated for a specific sector
 * 
 * @param _entry Address to BAM's entry
 * @param _sector Sector to allocate (0...21)
 */
static void d64_allocate_sector_on_bam( D64BAMEntry * _entry, D64Sector _sector ) {

    // printf( "sector %d\n", _sector );
    // printf( "free sectors = %d\n", _entry->freeSectors );

    // If the sector has no more free sectors,
    // we move away.
    if ( _entry->freeSectors == 0 ) {
        return;
    }

    // Let's calculate the offset and the bitmap for the given sector.
    int offset = _sector >> 3;
    int bitmap = 1 << ( _sector & 0x07 );

    // printf( "offset = %d\n", offset );
    // printf( "bitmap = %2.2x\n", bitmap );
    // printf( "_entry->bitmappedFree[offset] & ~(bitmap) = %2.2x\n", _entry->bitmappedFree[offset] & ~(bitmap) );
    // printf( "_entry->bitmappedFree[offset] = %2.2x\n", _entry->bitmappedFree[offset] );

    // If the sector is already allocated...
    if ( ( _entry->bitmappedFree[offset] & ~(bitmap) ) == _entry->bitmappedFree[offset] ) {

        // Do nothing...

    } else {

        // Allocate the sector.
        _entry->bitmappedFree[offset] &= ~(bitmap);

        // Decrease the number of the free sectors.
        --_entry->freeSectors;
        
    }

}

/**
 * @brief Allocate a specific sector
 * 
 * @param _handle Handle to current disk image
 * @param _track Track to allocate
 * @param _sector Sector to allocate
 */
static void d64_allocate_sector( D64Handle * _handle, D64Track _track, D64Sector _sector ) {

    // Retrieve the sector with the BAM.
    D64SectorBAM * bam = (D64SectorBAM *) d64_get_sector( _handle, D64_BAM_TRACK, D64_BAM_SECTOR );

    // If a track more than 35, we must use the correct BAM
    // based on the Disk Image format.
    if ( _track > 35 ) {

        switch( _handle->format ) {
            case SPEEDDOS40:
                d64_allocate_sector_on_bam( &bam->entriesSpeedDOS[_track-36], _sector );
                break;

            case PROFESSIONALDOS40:
            case PROFESSIONALDOS40B:
                d64_allocate_sector_on_bam( &bam->entriesSpeedDOS[_track-36], _sector );
                break;

            case DOLPHINDOS40:
                d64_allocate_sector_on_bam( &bam->entriesDolphinDOS[_track-36], _sector );
                break;

            case PROLOGICDOS40:
                d64_allocate_sector_on_bam( &bam->prologic.entriesPrologicDOS[_track-36], _sector );
                break;

            case PROSPEED40:
                d64_allocate_sector_on_bam( &bam->entriesSpeedDOS[_track-36], _sector );
                break;

            default:
                // We cannot allocate!
                return;
        }

    } else {
        // Allocate using standard BAM.
        d64_allocate_sector_on_bam( &bam->entries[_track-1], _sector );
    }

}

/**
 * @brief Find a free sector on the disk image.
 * 
 * @param _handle Handle to the disk image
 * @param _track Track with the free sector (1...42)
 * @param _sector Free sector (0...21)
 */
static void d64_find_free_sector( D64Handle * _handle, D64Track * _track, D64Sector * _sector ) {

    // printf( "d64_find_free_sector\n" );

    // A 0/0 result means "no free sector available".
    *_track = 0;
    *_sector = 0;

    // Retrieve the sector with the BAM.
    D64SectorBAM * bam = (D64SectorBAM *) d64_get_sector( _handle, D64_BAM_TRACK, D64_BAM_SECTOR );

    // This will contain the BAM entry with the free sector.
    D64BAMEntry * entry;

    _handle->lastUsedTrack = 17;

    // We are going to examinate tracks from 1 to the maximum number.
    while( _handle->lastUsedTrack != 0 ) {

        // printf( " > track %d\n", i );

        // With tracks greater of 35 we have to use the extension
        // of the BAM based on disk's format.
        if ( _handle->lastUsedTrack > 35 ) {

            switch( _handle->format ) {
                case SPEEDDOS40:
                case PROFESSIONALDOS40:
                case PROFESSIONALDOS40B:
                case PROSPEED40:
                    entry = &bam->entriesSpeedDOS[_handle->lastUsedTrack-36];
                    break;

                case DOLPHINDOS40:
                    entry = &bam->entriesDolphinDOS[_handle->lastUsedTrack-36];
                    break;

                case PROLOGICDOS40:
                    entry = &bam->prologic.entriesPrologicDOS[_handle->lastUsedTrack-36];
                    break;

                default:
                    // No free sectors available!
                    return;
            }

        } else {
            entry = &bam->entries[_handle->lastUsedTrack-1];
        }

        // printf( " > free sectors = %d\n", entry->freeSectors );

        // A fast check if free sectors are available.
        if ( entry->freeSectors > 0 ) {
            // A detailed check to find out the correct sector
            // must be executed.
            int sector = 0;
            for( int j=0; j<D64SectorsPerTrack[_handle->lastUsedTrack-1]; ++j ) {
                // printf( " > sector = %d\n", j );
                // Let's calculate the offset and the bitmap for the given sector.
                int offset = sector >> 3;
                int bitmap = 1 << ( sector & 0x07 ); 
                // printf( " > offset, bitmap = %2.2x %2.2x\n", offset, bitmap );
                // If the bit is set, the sector is free.
                if ( ( entry->bitmappedFree[offset] & bitmap ) == bitmap ) {
                    // printf( "found %2.2x %2.2x\n", offset, bitmap );
                    *_track = _handle->lastUsedTrack;
                    *_sector = sector;
                    return;
                }
                sector += 10;
                sector = sector % D64SectorsPerTrack[_handle->lastUsedTrack-1];
            }
        }
        
        --_handle->lastUsedTrack;

        if ( _handle->lastUsedTrack == 0 ) {
            _handle->lastUsedTrack = _handle->tracks;
        }

        if ( _handle->lastUsedTrack == 17 ) {
            _handle->lastUsedTrack = 0;
        }

    }
}

/**
 * @brief Allocate an retrieve the address of a directory's entry
 * 
 * @param _handle Handle of the disk image
 * @return D64DirectoryEntry* Address of the directory's entry
 */
static D64DirectoryEntry * d64_allocate_directory_entry( D64Handle * _handle ) {

    // The directory entry address to return.
    D64DirectoryEntry * value = NULL;

    // Retrieve the sector with the BAM.
    D64SectorBAM * bam = (D64SectorBAM *) d64_get_sector( _handle, D64_BAM_TRACK, D64_BAM_SECTOR );

    // Retrieve the (first) sector with directory.
    D64SectorDirectory * directory = (D64SectorDirectory *) d64_get_sector( _handle, bam->firstDirectoryTrack, bam->firstDirectorySector );

    // Take note of the index into the directory's entries.
    int directoryIndex = 0;

    do {

        // Retrieve the address of the directory's entry.
        value = &directory->entries[directoryIndex];
        
        // If the file type value is not DEL (0), it means that
        // the entry is used. So we must go ahead to the next entry.
        if ( value->attribute.type != DEL ) {

            // Reset the address.
            value = NULL;

            // Move to the next index
            ++directoryIndex;

            // If we reached the end of the directory's sector...
            if ( directoryIndex == 8 ) {

                // Restart from the beginning.
                directoryIndex = 0;

                // If the current track and sector for the first entry
                // is 0/0 it means we need to allocate another sector
                // for the directory.
                if ( directory->entries[0].track == 0 && directory->entries[0].sector == 0 ) {

                    // Find out the next free sector to use.
                    D64Track track;
                    D64Sector sector;
                    d64_find_free_sector( _handle, &track, &sector );

                    // Allocate the sector.
                    d64_allocate_sector( _handle, track, sector );

                    // Set the track and sector on the directory's entry.
                    directory->entries[0].track = track;
                    directory->entries[0].sector = sector;
                }

                // Move to the next directory sector.
                directory = (D64SectorDirectory *) d64_get_sector( _handle, directory->entries[0].track, directory->entries[0].sector );
            }
        }

    } while( value == NULL );

    return value;

}

/**
 * @brief Set the track / sector with an error
 * 
 * @param _handle Handle to the disk image
 * @param _track Number of the track (1..42)
 * @param _sector Number of the sector (0..21)
 * @param _error_code Error code to use
 */
static void d64_write_error( D64Handle * _handle, D64Track _track, D64Sector _sector, D64ErrorCode _error_code ) {

    // If the memory for storing errors is not allocated,
    // it will be allocated.
    if ( !_handle->errors ) {
        // Memory needed is of 1 byte for each sector.
        _handle->errorsSize = sizeof( _handle->sectors ) * sizeof( D64ErrorCode );
        _handle->errors = malloc( _handle->errorsSize );
        memset( _handle->errors, NO_ERROR, sizeof( _handle->sectors ) * sizeof( D64ErrorCode ) );
    }

    // Calculate the offset (in sectors) for the given track/sector.
    int offsetAsSectors = d64_calculate_sectors( _track, _sector );

    // Update the error code.
    _handle->errors[offsetAsSectors] = _error_code;

}

/**
 * @brief Update the fields of the directory's entry
 * 
 * @param _entry Address of the directory entry
 * @param _filename Name of the file
 * @param _type Type of the file
 * @param _firstTrack Track of the first data sector
 * @param _firstSector Sector of the first data sector
 * @param _size_sectors Size of the file, in sectors
 */
static void d64_write_directory_entry( D64DirectoryEntry * _entry, unsigned char * _filename, D64FileType _type, D64Track _firstTrack, D64Sector _firstSector, int _size_sectors ) {

    // Update the track/sector to 0/0.
    _entry->track = 0;
    _entry->sector = 0;

    // Update the attribute.
    _entry->attribute.type = _type;
    _entry->attribute.unused = 0;
    _entry->attribute.saveReplacement = 0;
    _entry->attribute.lockedFlag = 0;
    _entry->attribute.closedFlag = 1;

    // Update the first sector track/sector.
    _entry->trackFirstSector = _firstTrack;
    _entry->sectorFirstSector = _firstSector;

    // Update the filename.
    memset( _entry->filename, 0xa0, 16 );
    for( int i=0,c=strlen( _filename ) > 16 ? 16 : strlen( _filename ); i<c; ++i ) {
        _entry->filename[i] = toupper(_filename[i]);
    }
    
    // Currently, REL files are not supported.
    _entry->trackFirstSectorREL = 0;
    _entry->sectorFirstSectorREL = 0;
    _entry->lengthREL = 0;

    // _entry->unused[6];

    // Update the size in sectors
    _entry->sizeSectors = _size_sectors;

}

/**
 * @brief Format a D64 image disk
 * 
 * @param _handle Handle to the disk image
 */
static void d64_format( D64Handle * _handle ) {
    
    // Free the actual disk image's content.
    if ( _handle->content ) {
        free( _handle->content );
    }

    // Based on the disk image format, the number of tracks
    // will be different.
    switch( _handle->format ) {
            
        // Original CBM DOS v2.6	35	$0f $0f	"2A"	$41/'A'
        case CBMDOS:
        // Professional DOS Initial	35	$0f $0f	"2A"	$41/'A'
        case PROFESSIONALDOS35:
        // Dolphin-DOS 2.0/3.0	35	$0f $0f	"2A"	$41/'A'
        case DOLPHINDOS35:
        // PrologicDOS 1541	35	$0f $0f	"2A"	$41/'A'
        case PROLOGICDOS35:
        // ProSpeed 1571 2.0	35	$0f $0f	"2A"	$41/'A'
        case PROSPEED35:
            _handle->tracks = 35;
            break;

        // SpeedDOS+	40	$0f $0f	"2A"	$41/'A'
        case SPEEDDOS40:
        // Professional DOS Version 1/Prototype	40	$0f $0f	"2A"	$41/'A'
        case PROFESSIONALDOS40:
        // ProfDOS Release	40	$0f $0f	"4A"	$41/'A'
        case PROFESSIONALDOS40B:
        // Dolphin-DOS 2.0/3.0	40	$0d $0f	"2A"	$41/'A'
        case DOLPHINDOS40:
        // PrologicDOS 1541	40	$0f $0f	"2P"	$50/'P'
        case PROLOGICDOS40:
        // ProSpeed 1571 2.0	40	$0f $0f	"2P"	$50/'P'
        case PROSPEED40:
            _handle->tracks = 40;
            break;

    }

    // The real disk size is the first position of the
    // last track + 1.
    _handle->contentSize = D64OffsetPerTrack[_handle->tracks];

    // Calculate the effective number of sectors.
    _handle->sectors = d64_calculate_sectors( _handle->tracks + 1, 1 );

    // Allocate the memory space for the disk image.
    // printf( "ALLOCATING %d bytes\n", _handle->contentSize );

    _handle->content = malloc( _handle->contentSize );
    memset( _handle->content, 0, _handle->contentSize );

    // printf( "MALLOC %p\n", _handle->content );

    // Retrieve the sector with the BAM.
    D64SectorBAM * bam = (D64SectorBAM *) d64_get_sector( _handle, D64_BAM_TRACK, D64_BAM_SECTOR );

    // Set the first track/sector for the directory sector.
    bam->firstDirectoryTrack = D64_DIRECTORY_TRACK;
    bam->firstDirectorySector = D64_DIRECTORY_SECTOR;

    // Set the DOS version accordingly with the format.
    d64_set_dos_version( _handle, versionByFormat[_handle->format] );

    // Set the free sectors on BAM for each track.
    for( int i=0; i<_handle->tracks; ++i ) {
        d64_free_sectors_on_bam( &bam->entries[i], D64SectorsPerTrack[i] );
    }

    // Set the default disk name
    d64_set_disk_name( _handle, "UGBASIC" );

    // Set the default disk id
    d64_set_disk_id( _handle, 0xa0a0 );

    // Set the dos type based on format
    d64_set_dos_type( _handle, dosTypeByFormat[_handle->format] );

    bam->unused5 = 0x00;
    bam->unused3 = 0xa0;

    _handle->lastUsedTrack = 17;

}

/****************************************************************************
 * PUBLIC FUNCTIONS
 ****************************************************************************/
/**
 * @brief Set the DOS version for the given disk image
 * 
 * @param _handle Handle of the disk image
 * @param _version Version to set
 */
void d64_set_dos_version( D64Handle * _handle, D64DosVersion _version ) {

    // Retrieve the sector with the BAM.
    D64SectorBAM * bam = (D64SectorBAM *) d64_get_sector( _handle, D64_BAM_TRACK, D64_BAM_SECTOR );

    // Assign the given DOS version to the disk.
    bam->dosVersion = _version;

}

/**
 * @brief Set the disk name for the given disk image
 * 
 * @param _handle Handle of the disk image
 * @param _disk_name Name of the disk
 */
void d64_set_disk_name( D64Handle * _handle, unsigned char * _disk_name ) {

    // Retrieve the sector with the BAM.
    D64SectorBAM * bam = (D64SectorBAM *) d64_get_sector( _handle, D64_BAM_TRACK, D64_BAM_SECTOR );

    // Put the name on the disk based on the format.
    switch( _handle->format ) {
        case PROLOGICDOS35:
        case PROLOGICDOS40:
            break;
        default:
            memset( bam->standard.diskName, 0xa0, 16 );
            memcpy( bam->standard.diskName, _disk_name, strlen( _disk_name ) > 16 ? 16 : strlen( _disk_name ) );
            bam->standard.unused2[0] = 0xa0;
            bam->standard.unused2[1] = 0xa0;
            break;
    }

}

/**
 * @brief Set the disk id for the given disk image
 * 
 * @param _handle Handle of the disk image
 * @param _disk_id DISK ID
 */
void d64_set_disk_id( D64Handle * _handle, D64DiskId _disk_id ) {

    // Retrieve the sector with the BAM.
    D64SectorBAM * bam = (D64SectorBAM *) d64_get_sector( _handle, D64_BAM_TRACK, D64_BAM_SECTOR );

    // Put the disk id on the disk based on the format.
    switch( _handle->format ) {
        case PROLOGICDOS35:
        case PROLOGICDOS40:
            break;
        default:
            memcpy( &bam->standard.diskId, &_disk_id, sizeof( D64DiskId ) );
            break;
    }

}

/**
 * @brief Set the DOS Type for the given disk image
 * 
 * @param _handle Handle of the disk image
 * @param _dos_type DOS Type
 */
void d64_set_dos_type( D64Handle * _handle, unsigned char * _dos_type ) {

    // Retrieve the sector with the BAM.
    D64SectorBAM * bam = (D64SectorBAM *) d64_get_sector( _handle, D64_BAM_TRACK, D64_BAM_SECTOR );

    // Put the DOS Type on the disk
    memcpy( bam->dosType, _dos_type, 2 );

}

/**
 * @brief Create a new D64 disk image 
 * 
 * @param _format Format of the disk image
 * @return D64Handle* Handle of the disk image
 */
D64Handle * d64_create( D64Format _format ) {

    // Allocate the handle.
    D64Handle * handle = malloc( sizeof( D64Handle ) );
    memset( handle, 0, sizeof( D64Handle ) );

    // Update and format the disk image
    handle->format = _format;
    d64_format( handle );

    return handle;

}

/**
 * @brief Write a block of memory on a file on the D64 disk image
 * 
 * @param _handle Handle to the disk image
 * @param _filename Name of the file to write
 * @param _type Type of the file to write
 * @param _buffer Buffer to write
 * @param _size Size to write (in bytes)
 */
void d64_write_file( D64Handle * _handle, unsigned char * _filename, D64FileType _type, unsigned char * _buffer, int _size ) {

    // Track and sector number of the first sector data.
    D64Track firstTrack = 0;
    D64Sector firstSector = 0;

    // Size of the file (in sectors)
    D64WordLength sectors = 0;

    // Current track and sector.
    D64Track track = 0;
    D64Sector sector = 0;

    // Pointer of the buffer to write
    unsigned char * buffer = _buffer;

    // Sectors
    D64SectorData * sectorData = NULL;
    D64SectorData * previous = NULL;

    // Repeat the process until the buffer has been written.
    while( _size ) {

        // Increment the number of total sectors.
        ++sectors;

        // If there is a previous data sector, we must
        // update its t/s fields with the values found.
        if ( previous ) {
            previous->track = track;
            previous->sector = sector;
            // printf( "(previous updated)\n" );
        }

        // Find out a free t/s sector.
        d64_find_free_sector( _handle, &track, &sector );

        // Allocate the free t/s sector.
        d64_allocate_sector( _handle, track, sector );

        // If the first track has not been setted, the
        // one found is the first track.
        if ( firstTrack == 0 ) {
            firstTrack = track;
            firstSector = sector;
            // printf( "(first t/s updated)\n" );
        }

        // Save the previous sector, if any.
        previous = sectorData;

        // Retrieve the sector data with the given t/s.
        sectorData = (D64SectorData *) d64_get_sector( _handle, track, sector );

        // printf( "SECTOR AT %p (%p)\n", sectorData, &sectorData->data[0] );

        // If the size is less or equal 254, we can put it entirely
        // in the (final) sector.
        if ( _size <= 254 ) {

            // printf( "FILL UP TO %d bytes\n", _size );

            // Set the effective size on the "sector" field.
            sectorData->track = 0;
            sectorData->sector = _size;

            // Copy the memory on the sector data.
            memcpy( &sectorData->data[0], buffer, _size );

            _size = 0;

        } else {

            // printf( "FILL UP TO [254] bytes\n" );

            // Copy a 254 bytes segment.
            memcpy( &sectorData->data[0], buffer, 254 );

            buffer += 254;
            _size -= 254;

        }

    }

    // If there is a previous data sector, we must
    // update its t/s fields with the values found.
    if ( previous ) {
        previous->track = track;
        previous->sector = sector;
        // printf( "(previous updated)\n" );
    }
    
    // Allocate a new directory's entry.
    D64DirectoryEntry * entry = d64_allocate_directory_entry( _handle );

    // Update the directory's entry.
    d64_write_directory_entry( entry, _filename, _type, firstTrack, firstSector, sectors );
    
}

/**
 * @brief Free the disk image resources
 * 
 * @param _handle Handle to disk image
 */
void d64_free( D64Handle * _handle ) {

    free( _handle->errors );
    free( _handle->content );
    free( _handle );

}

void d64_output( D64Handle * _handle, unsigned char * _filename ) {

    remove( _filename );

    FILE * fHandle = fopen( _filename, "wb" );
    fwrite( _handle->content, _handle->contentSize, 1, fHandle );
    if ( _handle->errors ) {
        fwrite( _handle->errors, _handle->errorsSize, 1, fHandle );
    }
    fclose( fHandle );

}
