#ifndef __UGBASIC_D64__
#define __UGBASIC_D64__

/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <ctype.h>

/****************************************************************************
 * DATA TYPES AND STRUCTURES
 ****************************************************************************/

// Quoted from: https://vice-emu.sourceforge.io/vice_17.html

// 17.5 The D64 disk image format

// The advantage with using the 35 track D64 format, regardless of error bytes, 
// is that it can be converted directly back to a 1541 disk by either using the 
// proper cable and software on the PC, or send it down to the C64 and writing 
// it back to a 1541. It is the best documented format since it is also native 
// to the C64, with many books explaining the disk layout and the internals of the 1541.

// First and foremost we have D64, which is basically a sector-for-sector copy
// of a 1540/1541 disk. There are several versions of these which I will cover 
// shortly. The standard D64 is a 174848 byte file comprised of 256 byte 
// sectors arranged in 35 tracks with a varying number of sectors per track 
// for a total of 683 sectors. Track counting starts at 1, not 0, and goes 
// up to 35. Sector counting starts at 0, not 1, for the first sector, 
// therefore a track with 21 sectors will go from 0 to 20.
//
// The original media (a 5.25" disk) has the tracks laid out in circles, 
// with track 1 on the very outside of the disk (closest to the sides) to track 
// 35 being on the inside of the disk (closest to the inner hub ring). 
//
// Commodore, in their infinite wisdom, varied the number of sectors per track 
// and data densities across the disk to optimize available storage, resulting in 
// the chart below. It shows the sectors/track for a standard D64. Since the 
// outside diameter of a circle is the largest (versus closer to the center), 
// the outside tracks have the largest amount of storage.
// Tracks 36-40 apply to 40- and 42-track images only.
// Tracks 41-42 apply to 42-track images only.

// The directory track should be contained totally on track 18. 
// Sectors 1-18 contain the entries and sector 0 contains the BAM 
// (Block Availability Map) and disk name/ID. Since the directory is 
// only 18 sectors large (19 less one for the BAM), and each sector can 
// contain only 8 entries (32 bytes per entry), the maximum number of 
// directory entries is 18 * 8 = 144. The first directory sector is always 
// 18/1, even though the t/s pointer at 18/0 (first two bytes) might point 
// somewhere else. It then follows the same chain structure as a normal 
// file, using a sector interleave of 3. This makes the chain links go 18/1, 
// 18/4, 18/7 etc.

// Note that you can extend the directory off of track 18, but only when reading 
// the disk or image. Attempting to write to a directory sector not on track 18 
// will cause directory corruption. Each directory sector has the following 
// layout (18/1 partial dump):

// Used to represent the number of the track (1...42)
typedef unsigned char D64Track;

// Used to represent the number of the sector (1...35) or 
// total number of sectors, as well.
typedef unsigned char D64Sector;

// Used to represent the actual dos version for the disk.
typedef unsigned char D64DosVersion;

// Used to respresent a 1-byte length (0...255)
typedef unsigned char D64ByteLength;

// Used to respresent a 2-byte length (0...65535)
typedef unsigned short D64WordLength;

// Each filetype has its own unique properties, but most follow one simple structure. 
// The first file sector is pointed to by the directory and follows a t/s chain, 
// until the track value reaches $00. When this happens, the value in the sector 
// link location indicates how much of the sector is used. For example, the 
// following chain indicates a file 6 sectors long, and ends when we encounter the 
// $00/$34 chain. At this point the last sector occupies from bytes $02-$34.
typedef enum _D64FileType {

    // 0000	0	DEL
    DEL = 0,

    // 0001	1	SEQ
    SEQ = 1,

    // 0010	2	PRG
    PRG = 2,

    // 0011	3	USR
    USR = 3,

    // 0100	4	REL
    REL = 4

} D64FileType;

// This structure will take care of the attribute for the single file.
typedef struct _D64Attribute {

    // Bits	Description
    // 0-3	The actual file type (D64FileType)
    // Values 5-15 are illegal, but if used will produce very strange results. 
    // The 1541 is inconsistent in how it treats these bits. Some routines use 
    // all 4 bits, others ignore bit 3, resulting in values from 0-7.
    unsigned char     type:4;

    // 4	Unused
    unsigned char     unused:1;

    // 5	Used only during SAVE-@ replacement
    unsigned char     saveReplacement:1;

    // 6	Locked flag (Set produces ">" locked files)
    unsigned char     lockedFlag:1;

    // 7	Closed flag (Not set produces "*", or "splat" files)
    unsigned char     closedFlag:1;

} D64Attribute;

// This structure will describe a single entry of the directory.
typedef struct _D64DirectoryEntry {

    // The first two bytes of the sector ($12/$04) indicate the location of the next 
    // track/sector of the directory (18/4). If the track is set to $00, then it is 
    // the last sector of the directory. It is possible, however unlikely, that the
    // directory may *not* be competely on track 18 (some disks do exist like this). 
    // Just follow the chain anyhow.
    // When the directory is done, the track value will be $00. The sector link 
    // should contain a value of $FF, meaning the whole sector is allocated, but 
    // the actual value doesn't matter. The drive will return all the available 
    // entries anyways.
    // Track/Sector location of next directory sector ($00 $00 if not the first 
    // entry in the sector)
    D64Track        track;
    D64Sector       sector;

    // File's attribute
    D64Attribute     attribute;

    // Track/sector location of first sector of file
    D64Track        trackFirstSector;
    D64Sector       sectorFirstSector;

    // 16 character filename (in PETASCII, padded with $A0)
    unsigned char   filename[16];

    // Track/Sector location of first side-sector block (REL file only)
    D64Track        trackFirstSectorREL;
    D64Sector       sectorFirstSectorREL;

    // $17	REL file record length (REL file only, max. value 254)
    D64ByteLength   lengthREL;

    // $18-$1D	Unused (except with GEOS disks)
    unsigned char   unused[6];

    // $1E-$1F	File size in sectors, low/high byte order ($1E+$1F*256). 
    // The approx. filesize in bytes is <= #sectors * 254
    D64WordLength   sizeSectors;

} D64DirectoryEntry;

// This structure will allow to store the content of a directory sector.
typedef struct _D64Directory {
    
    // Entries of directory.
    D64DirectoryEntry       entries[8];

} D64SectorDirectory;

// This structure can be used to store the content of a data sector.
typedef struct _D64SectorData {

    // Reference to the next track / sector. If this is the last
    // data sector, the track will be set to zero (0) and sector
    // will store the number of bytes used in this sector.
    D64Track        track;
    D64Sector       sector;

    // The data.
    unsigned char   data[254];

} D64SectorData;

// The DISK ID.
typedef unsigned short D64DiskId;

// Files, on a standard 1541, are stored using an interleave of 10. Assuming a starting 
// track/sector of 17/0, the chain would run 17/0, 17/10, 17/20, 17/8, 17/18, etc.

// 17.5.1 Non-Standard & Long Directories
// Most Commdore floppy disk drives use a single dedicated directory track where all
// filenames are stored. This limits the number of files stored on a disk based on
// the number of sectors on the directory track. There are some disk images that contain
// more files than would normally be allowed. This requires extending the directory off
// the default directory track by changing the last directory sector pointer to a new
// track, allocating the new sectors in the BAM, and manually placing (or moving existing)
// file entries there. The directory of an extended disk can be read and the files that
// reside there can be loaded without problems on a real drive. However, this is still a 
// very dangerous practice as writing to the extended portion of the directory will cause
// directory corruption in the non-extended part. Many of the floppy drives core ROM 
// routines ignore the track value that the directory is on and assume the default 
// directory track for operations.

// To explain: assume that the directory has been extended from track 18 to track 
// 19/6 and that the directory is full except for a few slots on 19/6. When saving 
// a new file, the drive DOS will find an empty file slot at 19/6 offset $40 and 
// correctly write the filename and a few other things into this slot. When the 
// file is done being saved the final file information will be written to 18/6 
// offset $40 instead of 19/6 causing some directory corruption to the entry at 
// 18/6. Also, the BAM entries for the sectors occupied by the new file will 
// not be saved and the new file will be left as a SPLAT (*) file.

// Attempts to validate the disk will result in those files residing off the directory
// track to not be allocated in the BAM, and could also send the drive into an endless
// loop. The default directory track is assumed for all sector reads when validating 
// so if the directory goes to 19/6, then the validate code will read 18/6 instead. 
// If 18/6 is part of the normal directory chain then the validate routine will
// loop endlessly.

// 17.5.2 BAM layout
// The layout of the BAM area (sector 18/0) is a bit more complicated...
// Note: The BAM entries for SPEED, DOLPHIN and ProLogic DOS use the same layout as 
// standard BAM entries. One of the interesting things from the BAM sector is the byte 
// at offset $02, the DOS version byte. If it is set to anything other than $41 or $00, 
// then we have what is called "soft write protection". Any attempt to write to the disk 
// will return the "DOS Version" error code 73 ,"CBM DOS V 2.6 1541". 
// The 1541 is simply telling you that it thinks the disk format version is incorrect. 
// This message will normally come up when you first turn on the 1541 and read the 
// error channel. If you write a $00 or a $41 into 1541 memory location $00FF 
// (for device 0), then you can circumvent this type of write-protection, and change the
// DOS version back to what it should be.

// The BAM entries require a bit (no pun intended) more of a breakdown. 
typedef struct _D64BAMEntry {

    // The first byte ($12) is the number of free sectors on that track.
    D64ByteLength       freeSectors;

    // The next three bytes represent the bitmap of which sectors 
    // are used/free. Since it is 3 bytes (8 bits/byte) we have 24 bits of storage. 
    // Remember that at most, each track only has 21 sectors, so there are a 
    // few unused bits.
    // These entries must be viewed in binary to make any sense. 
    // In order to make any sense from the binary notation, flip the bits around.
    //
    //             111111 11112222
    //  01234567 89012345 67890123
    //  --------------------------
    //  11100000 00000000 00000000
    //
    // If we are on the first track, we have 21 sectors, and only use up to
    // the bit 20 position. If a bit is on (1), the sector is free. 
    // Therefore, track 1 has sectors 0, 1 and 2 free, all the rest are used.
    // Any leftover bits that refer to sectors that don't exist, like bits 21-23 
    // in the above example, are set to allocated.
    unsigned char       bitmappedFree[3]; // 1 = free, 0 = occupied

} D64BAMEntry;

typedef struct _D64BAM {

    // Track/Sector location of the first directory sector (should be set
    // to 18/1 but it doesn't matter, and don't trust what is there, always 
    // go to 18/1 for first directory entry)
    D64Track        firstDirectoryTrack;
    D64Sector       firstDirectorySector;

    // Disk DOS version type (see note below) $41 ("A")
    D64DosVersion   dosVersion;

    // Unused
    unsigned char   unused;

    // BAM entries for each track, in groups of four bytes per track, 
    // starting on track 1 (see below for more details)
    D64BAMEntry     entries[35];

    union {

        struct {

            // Disk Name (padded with $A0)
            // PrologicDOS stored them right after the existing BAM entries from $90-A3.
            // PrologicDOS also moves the disk label and ID forward from the standard location of 
            // $90 to $A4.
            unsigned char   diskName[16];

            // Filled with $A0
            unsigned char   unused2[2];

            // Disk ID
            D64DiskId       diskId;

        } standard;

        struct {

            D64BAMEntry entriesPrologicDOS[5];

        } prologic;

    };

    // Usually $A0
    unsigned char   unused3;

    // DOS type, usually "2A"
    unsigned char   dosType[2];

    // Filled with $A0
    unsigned char   unused4[4];

    // Unused ($00)
    unsigned char   unused5;

    // For DOLPHIN DOS track 36-40 BAM entries, otherwise unused ($00)
    D64BAMEntry     entriesDolphinDOS[5];

    // For SPEED DOS track 36-40 BAM entries, otherwise unused ($00)
    D64BAMEntry     entriesSpeedDOS[5];

    // Unused ($00)
    unsigned char   unused6[44];

} D64SectorBAM;

// 17.5.3 Variations on the D64 layout
// These are some variations of the D64 layout:

// 1. Standard 35 track layout but with 683 error bytes added on to the end 
//    of the file. Each byte of the error info corresponds to a single sector 
//    stored in the D64, indicating if the sector on the original disk 
//    contained an error. The first byte is for track 1/0, and the last byte is
//    for track 35/16.

// 2. A 40 track layout, following the same layout as a 35 track disk, but with 
//    5 extra tracks. These contain 17 sectors each, like tracks 31-35. Some 
//    of the PC utilities do allow you to create and work with these files. 
//    This can also have error bytes attached like variant #1.

// 3. A 42 track layout, with two extra tracks of 17 sectors each. This is 
//    extremely uncommon, since real drives often have problems with accessing 
//    these tracks, software that uses them is very rare.

// 4. The Commodore 128 allowed for "auto-boot" disks. With this, t/s 1/0 
//    holds a specific byte sequence which the computer recognizes as boot code.

typedef enum _D64Variants {

    // 35 track, no errors	174848
    TRACKS35 = 0,

    // 1. Standard 35 track layout but with 683 error bytes added on to the end 
    //    of the file. Each byte of the error info corresponds to a single sector 
    //    stored in the D64, indicating if the sector on the original disk 
    //    contained an error. The first byte is for track 1/0, and the last byte is
    //    for track 35/16.

    // 35 track, 683 error bytes	175531
    TRACKS35ERRORS = 1,

    // 2. A 40 track layout, following the same layout as a 35 track disk, but with 
    //    5 extra tracks. These contain 17 sectors each, like tracks 31-35. Some 
    //    of the PC utilities do allow you to create and work with these files. 
    //    This can also have error bytes attached like variant #1.

    // 40 track, no errors	196608
    TRACKS40 = 2,

    // 40 track, 768 error bytes	197376
    TRACKS40ERRORS = 3,

    // 3. A 42 track layout, with two extra tracks of 17 sectors each. This is 
    //    extremely uncommon, since real drives often have problems with accessing 
    //    these tracks, software that uses them is very rare.

    // 42 track, no errors	205312
    TRACKS42 = 4,

    // 42 track, 802 error bytes	206114
    TRACKS42ERRORS = 5

    // 4. The Commodore 128 allowed for "auto-boot" disks. With this, t/s 1/0 
    //    holds a specific byte sequence which the computer recognizes as boot code.

} D64Variants;

// The following table (provided by Wolfgang Moser) outlines the differences between the 
// standard 1541 DOS and the various "speeder" DOS's that exist. The 'header 7/8' category
// is the 'fill bytes' as the end of the sector header of a real 1541 disk.

typedef enum _D64Format {

    // Original CBM DOS v2.6	35	$0f $0f	"2A"	$41/'A'
    CBMDOS = 0,

    // *SpeedDOS+	40	$0f $0f	"2A"	$41/'A'
    SPEEDDOS40 = 1,
    
    // Professional DOS Initial	35	$0f $0f	"2A"	$41/'A'
    PROFESSIONALDOS35 = 2,

    // Professional DOS Version 1/Prototype	40	$0f $0f	"2A"	$41/'A'
    PROFESSIONALDOS40 = 3,

    // ProfDOS Release	40	$0f $0f	"4A"	$41/'A'
    PROFESSIONALDOS40B = 4,

    // Dolphin-DOS 2.0/3.0	35	$0f $0f	"2A"	$41/'A'
    DOLPHINDOS35 = 5,

    // Dolphin-DOS 2.0/3.0	40	$0d $0f	"2A"	$41/'A'
    DOLPHINDOS40 = 6,

    // PrologicDOS 1541	35	$0f $0f	"2A"	$41/'A'
    PROLOGICDOS35 = 7,

    // PrologicDOS 1541	40	$0f $0f	"2P"	$50/'P'
    PROLOGICDOS40 = 8,

    // ProSpeed 1571 2.0	35	$0f $0f	"2A"	$41/'A'
    PROSPEED35 = 9,

    // ProSpeed 1571 2.0	40	$0f $0f	"2P"	$50/'P'
    PROSPEED40 = 10

} D64Format;

// Note: There are also clones of SpeedDOS that exist, such as RoloDOS and DigiDOS. 
// Both are just a change of the DOS startup string.

// 17.5.4 Error codes
// Here is the meaning of the error bytes added onto the end of any extended D64. 
// The CODE is the same as that generated by the 1541 drive controller... it reports 
// these numbers, not the error code we usually see when an error occurs.
// Some of what comes below is taken from Immers/Neufeld book "Inside Commodore DOS". 
// Note the descriptions are not completely accurate as to what the drive DOS is 
// actually doing to seek/read/decode/write sectors, but serve as simple examples only. The "type" field is where the error usually occurs, whether it's searching for any SYNC mark, any header ID, any valid header, or reading a sector.
// These first errors are "seek" errors, where the disk controller is simply 
// reading headers and looking at descriptor bytes, checksums, format ID's and 
// reporting what errors it sees. These errors do *not* necessarily apply to the 
// exact sector being looked for. This fact makes duplication of these errors 
// very unreliable.

typedef enum _D64ErrorCode {

    // $01	00	N/A	*	No error.
    // Code : $01 Error : 00 Type : N/A Message : No error.
    // Self explanatory. No errors were detected in the reading and decoding of the sector.
    NO_ERROR = 1,

    // $02	20	Seek	*	Header block not found / Header descriptor byte not found
    // Code : $02 Error : 20 Type : Seek Message : Header descriptor byte not found (HEX $08, GCR $52)
    // Each sector is preceeded by an 8-byte GCR header block, which starts with the 
    // value $52 (GCR). If this value is not found after 90 attempts, this error is 
    // generated. Basically, what a track has is SYNC marks, and possibly valid data blocks,
    // but no valid header descriptors.
    // Code : $02 Error : 20 Type : Seek Message : Header block not found
    // This error can be reported again when searching for the correct header block. 
    // An image of the header is built and searched for, but not found after 90 read 
    // attempts. Note the difference from the first occurance. The first one only 
    // searches for a valid ID, not the whole header.  Note that error 20 occurs twice 
    // during this phase. The first time is when a header ID is being searched for, 
    // the second is when the proper header pattern for the sector being searched for 
    // is not found.
    HEADER_BLOCK_NOT_FOUND = 2,

    // $03	21	Seek	*	No SYNC sequence found
    // Code : $03 Error : 21 Type : Seek Message : No SYNC sequence found.
    // Each sector data block and header block are preceeded by SYNC marks. 
    // If *no* sync sequence is found within 20 milliseconds (only ~1/10 of a disk 
    // rotation!) then this error is generated. This error used to mean the entire 
    // track is bad, but it does not have to be the case. Only a small area of the 
    // track needs to be without a SYNC mark and this error will be generated.
    // Converting this error to a D64 is very problematic because it depends on where 
    // the physical head is on the disk when a read attempt is made. If it is on valid 
    // header/sectors then it won't occur. If it happens over an area without SYNC 
    // marks, it will happen.
    NO_SYNC_SEQUENCE_FOUND = 3,

    // $09	27	Seek	*	Checksum error in header block
    // Code : $09 Error : 27 Type : Seek Message : Checksum error in header block
    // The header block contains a checksum value, calculated by XOR'ing the TRACK, 
    // SECTOR, ID1 and ID2 values. If this checksum is wrong, this error is generated.
    CHECKSUM_ERROR_HEADER_BLOCK = 9,
    
    // $0B	29	Seek	*	Disk sector ID mismatch
    // Code : $0B Error : 29 Type : Seek Message : Disk sector ID mismatch
    // The ID's from the header block of the currently read sector are compared 
    // against the ones from the low-level header of 18/0. If there is a mismatch, 
    // this error is generated.
    DISK_SECTOR_ID_MISMATCH = 11,

    //////////////

    // From this point on, all the errors apply to the specific sector you are looking 
    // for. If a read passed all the previous checks, then we are at the sector 
    // being searched for. Note that the entire sector is read before these errors are
    // detected. Therefore the data, checksum and off bytes are available.

    // $04	22	Read	*	Data descriptor byte not found
    // Code : $04 Error : 22 Type : Read Message : Data descriptor byte not found (HEX $07, GCR $55)
    // Each sector data block is preceeded by the value $07, the "data block" descriptor.
    // If this value is not there, this error is generated. Each encoded sector has actually 260 bytes. First is the descriptor byte, then follows the 256 bytes of data, a checksum, and two "off" bytes.
    DATA_DESCRIPTOR_BYTE_NOT_FOUND = 4,

    // $05	23	Read	*	Checksum error in data block
    // Code : $05 Error : 23 Type : Read Message : Checksum error in data block
    // The checksum of the data read of the disk is calculated, and compared against the 
    // one stored at the end of the sector. If there's a discrepancy, this error is 
    // generated.
    CHECKSUM_ERROR_DATA_BLOCK = 5,

    // $06	24	Write		Write verify on format (never occurs on 1541)
    // Code : $06 Error : 24 Type : Write Message : Write verify (on format)
    // Once the GCR-encoded sector is written out, the drive waits for the sector to
    // come around again and verifies the whole 325-byte GCR block. Any errors 
    // encountered will generate this error.
    WRITE_VERIFY_ON_FORMAT = 6,

    // $07	25	Write		Write verify error
    // Code : $07 Error : 25 Type : Write Message : Write verify error
    // Once the GCR-encoded sector is written out, the drive waits for the sector to
    // come around again and verifies the whole 325-byte GCR block. Any errors 
    // encountered will generate this error.
    WRITE_VERIFY_ERROR = 7,

    // $08	26	Write		Write protect on
    // Code : $08 Error : 26 Type : Write Message : Write protect on
    // Self explanatory. Remove the write-protect tab, and try again.
    WRITE_PROTECT_ON = 8,

    // $0A	28	Write		Write error (never occurs on 1541)
    // Code : $0A Error : 28 Type : Write Message : Write error
    // In actual fact, this error never occurs, but it is included for completeness.
    // This is not an error at all, but it gets reported when the read of a sector is ok.

    WRITE_ERROR = 10,

    // Codes $0 and $C to $E are unused and never occur.
    
    // $0F	74	Read		Drive Not Ready (no disk in drive or no device 1)
    // Code : $0F Error : 74 Type : Read Message : Drive Not Ready (no disk in drive or no device 1)
    // These errors only apply when writing to a disk. I don't see the usefulness 
    // of having these as they cannot be present when only *reading* a disk.
    DRIVE_NOT_READY = 16

} D64ErrorCode;

// This is the opaque type used to represent a D64 disk image.
typedef struct _D64Handle {

    // Disk's format
    D64Format           format;

    // Number of tracks in the disk (35, 40, 42)
    D64Track            tracks;

    // Total numer of sectors
    D64Sector           sectors;

    // Raw disk data
    unsigned char   *   content;

    // Raw disk data size
    int                 contentSize;

    // Errors data (NULL if missing)
    D64ErrorCode    *   errors;

    // Errors data size
    int                 errorsSize;

    // 
    D64Track            lastUsedTrack;

} D64Handle;

#define         D64_BAM_TRACK               18
#define         D64_BAM_SECTOR               0
#define         D64_DIRECTORY_TRACK         18
#define         D64_DIRECTORY_SECTOR         1

/****************************************************************************
 * FUNCTION DECLARATION
 ****************************************************************************/

D64Handle *         d64_create( D64Format _format );
void                d64_set_dos_version( D64Handle * _handle, D64DosVersion _version );
void                d64_set_disk_name( D64Handle * _handle, unsigned char * _disk_name );
void                d64_set_disk_id( D64Handle * _handle, D64DiskId _disk_id );
void                d64_set_dos_type( D64Handle * _handle, unsigned char * _dos_type );
void                d64_write_file( D64Handle * _handle, unsigned char * _filename, D64FileType _type, unsigned char * _buffer, int _size );
void                d64_output( D64Handle * _handle, unsigned char * _filename );
void                d64_free( D64Handle * _handle );

#endif