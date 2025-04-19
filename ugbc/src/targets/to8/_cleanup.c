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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

void target_prepare_finalization( Environment * _environment ) {

}

void target_finalization( Environment * _environment ) {

    ef936x_finalization( _environment );

    deploy( vars2, src_hw_to8_vars2_asm);

    if ( ! _environment->deployed.pc128audio ) {
        cpu_label( _environment, "PC128OPAUDIOSTARTUP" );
        outline0( "RTS" );
    }

    if ( ! _environment->deployed.scancode ) {
        cpu_label( _environment, "KBDMANAGER" );
        outline0( "RTS" );
    }

   if ( _environment->dataSegment ) {
        outhead0( "DATAPREPARATION" );
        outline0( "LDD #DATAFIRSTSEGMENT" );
        outline0( "STD DATAPTR" );
        outline0( "RTS" );
    } else {
        outhead0( "DATAPREPARATION" );
        outline0( "RTS" );
    }

}

// -------------------------------------------------------------------------
// CONVERT BINARY TO K7 TAPE FILE 
// FOR THOMSON MO6 / PC128 OLIVETTI PRODEST
// 
// This code was originally present in the repository 
// "PC 128 Olivetti Prodest (Thomson MO6) tools collection"
// https://github.com/dinoflorenzi/MO5
//
// Code courtesy of Dino Florenzi (https://github.com/dinoflorenzi)
// Adapted by Marco Spedaletti for ugBASIC
// -------------------------------------------------------------------------

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int frmt( Environment * _environment, char * ptr, char size,char* out)
{
	memset(out,0x20,11);
	char * point=".";
	int k=0,i=0;
		int p=strcspn(ptr,point);
		if(p==size-1||p>8||size>12||p==0)
		{
    		CRITICAL_BUILD_INVALID_FILENAME_K7(ptr);
		}
		for(i=0;i<size;i++)
		{
			if(i==p)
			k+=(8-p);
			else
			{
		      out[k]=ptr[i];
		      k++;
			}
			
		}
		return 0;
}

/* http://dcmoto.free.fr/documentation/moniteur-mo5-casst/moniteur-mo5-casst_src.txt */
static unsigned char blk[257];
static void new_blk(int type) 
{
    blk[0] = type;                  /* set type ok k7 block: 0=file-name, 1=file-data, 0xFF=end-of-file */
    blk[1] = 0;                     /* len = 0 */
    blk[256] = 0;                   /* checksum = 0 */
}
static void out_blk(FILE *f) 
{
    static unsigned char hdr[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0x3c,0x5a}; /* k7 block-header */
    int pos = 2 + blk[1];	    /* get checksum pos */
    blk[1] = pos;		    /* update block len */
    blk[pos] = 256 - blk[256];      /* complement checksum */
    fwrite(hdr, sizeof(hdr), 1, f); /* write block header */
    fwrite(blk, pos+1, 1, f);       /* then block content */
    new_blk(blk[0]);                /* prepare a new block of the same kind */
}

static void write_byte(FILE *f, int byte) 
{
    blk[256] += (unsigned char)byte;/* update checksum */
    blk[2 + blk[1]++] = byte;       /* update index & store byte */
    if(254 == blk[1]) out_blk(f);   /* when block is full, write it */
}
static void write_word(FILE *f, int word) 
{
    write_byte(f, word >> 8);
    write_byte(f, word & 255);
}
static void write_bytes(FILE *f, void *array, int len) 
{
    unsigned char *ptr = array;
    size_t cnt = len;
    while(cnt--) write_byte(f, *ptr++);
}

/////////////////////////////////////////////////////////////

static void addFileEntry( FILE * _handle, char * _filename, int _file_type ) {

    // k7.AddRange(SynchroTO);
    char synchroTO[] = { 0xdc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x3c };
    fwrite(&synchroTO[0], sizeof(synchroTO), 1, _handle);

    // k7.Add(0x00); // type de bloc entête
    char blockType = 0;
    fwrite(&blockType, 1, 1, _handle);

    // k7.Add(0x14); // longueur
    char blockLen = 0x14;
    fwrite(&blockLen, 1, 1, _handle);
    // byte checksum = 0x14;
    unsigned char checksum = 0x14;

    // Nom du fichier complété au besoin par des espaces.
    // string basename = Path.GetFileNameWithoutExtension(filename).ToUpper();
    // char filename[16];
    // frmt( _filename, strlen(_filename), filename);

    for( int i=0; i<11; ++i ) {
        // k7.Add((byte)basename[i]);
        fwrite(&_filename[i], 1, 1, _handle);
        checksum += _filename[i];
    }

    // k7.Add((byte)fileType); // type de fichier
    char fileType = _file_type;
    fwrite(&fileType, 1, 1, _handle);
    checksum += fileType;

    // k7.Add(0x00);
    char zero = 0;
    fwrite(&zero, 1, 1, _handle);

    // k7.Add(0xff);
    char ff = 0xff;
    fwrite(&ff, 1, 1, _handle);
    checksum += 0xff;

    for ( int i=0; i<6; ++i ) {
        // k7.Add(0x00);
        fwrite(&zero, 1, 1, _handle);
    }

    // k7.Add(checksum);
    fwrite(&checksum, 1, 1, _handle);

}

static int addFileData( FILE * _handle, unsigned char _bytes[], int _size, int _offset ) {

    // int length = bytes.Length - offset;
    int length = _size - _offset;

    if (length > 0xdf) {
        length = 0xdf;
    }

    // k7.AddRange(SynchroTO);
    char synchroTO[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x3c };
    fwrite(&synchroTO[0], sizeof(synchroTO), 1, _handle);

    // k7.Add(0x01); // type de bloc fichier
    char blockType = 1;
    fwrite(&blockType, 1, 1, _handle);
    
    // byte checksum = (byte)0x01;
    unsigned char checksum = 0x01;

    // k7.Add((byte)length); // longueur
    char blockLen = length;
    fwrite(&blockLen, 1, 1, _handle);
    // checksum += (byte)length;
    checksum += length;

    for (int i=_offset; i<_offset+length; i++) {
        // k7.Add(bytes[i]); // données
        fwrite(&_bytes[i], 1, 1, _handle);
        checksum += _bytes[i];
    }

    // k7.Add(checksum);
    fwrite(&checksum, 1, 1, _handle);

    return length;
}

enum ThomsonFileType
{
    BASIC_PRG = 0,
    BASIC_DAT = 1,
    ASM_PRG = 2,
    TEXT = 3
};

static void addBinaryFile( FILE * _handle, char * _filename, int _address, char * _bytes, int _size ) {

    addFileEntry( _handle, _filename, ASM_PRG );

    unsigned char * fileData = malloc( _size + 10 );

    fileData[0] = 0x00;
    fileData[1] = (_size >> 8);
    fileData[2] = (_size & 0xff);
    fileData[3] = (_address >> 8);
    fileData[4] = (_address & 0xff);
    for (int i=0; i<_size; i++) {
        fileData[i+5] = _bytes[i];
    }
    fileData[_size+5] = 0xff;
    fileData[_size+6] = 0x00;
    fileData[_size+7] = 0x00;
    fileData[_size+8] = (_address >> 8);
    fileData[_size+9] = (_address & 0xff);
    for (int i=0; i<_size+10;) {
        i += addFileData( _handle, fileData, (_size+10), i);
    }
    // end of file
    // k7.AddRange(SynchroTO);
    char synchroTO[] = { 0xdc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x3c };
    fwrite(&synchroTO[0], sizeof(synchroTO), 1, _handle);

    // k7.Add(0xff); // type de bloc fin
    char blockType = 0xff;
    fwrite(&blockType, 1, 1, _handle);

    // k7.Add(0x00); // longueur
    char blockLen = 0;
    fwrite(&blockLen, 1, 1, _handle);

    // k7.Add(0xff); // checksum
    char checksum = 0xff;
    fwrite(&checksum, 1, 1, _handle);
}

/////////////////////////////////////////////////////////////

int convertbintok7(Environment * _environment)
{
    unsigned short start=0x8100;
    unsigned short size;
    unsigned short runaddr=0x8100;
    FILE *fr,*fw;
    char nome[12];
    char source[20];
    char destin[100];

    // Rename the output file into a temporary filename
    char temporaryFileName[MAX_TEMPORARY_STORAGE];
    sprintf(temporaryFileName, "%s.bin", get_temporary_filename( _environment ) );
    remove( temporaryFileName );
    BUILD_SAFE_MOVE( _environment, _environment->exeFileName, temporaryFileName );
    
    fr=fopen(temporaryFileName,"rb");
    if(!fr) 
    {   
        CRITICAL_CANNOT_OPEN_EXECUTABLE_FILE( temporaryFileName );
    }

    if(frmt( _environment, "main.exe",strlen("main.exe"),nome))
    {
        CRITICAL_BUILD_INVALID_FILENAME_K7("main.exe");
    }

    unsigned char file_type[]={0x02,0x00,0x00}; /* binary k7 file */

    strcopy(destin,_environment->exeFileName);
    fw=fopen(destin,"wb");

    addBinaryFile( fw, "loader  bin", 0xdeff, data_to8_loader_bin, data_to8_loader_bin_len );

    fr=fopen(temporaryFileName,"rb");
    fseek(fr, 0L, SEEK_END);
    size = ftell(fr);
    rewind(fr);
    char * fileContent = malloc( size );
    (void)!fread( fileContent, 1, size, fr );
    fclose( fr );

    addBinaryFile( fw, nome, 0x6400, fileContent, size );

    // new_blk(0); /* k7 block 0: file name + type */
    // write_bytes(fw, &nome[0], sizeof(nome)-1); /* file name */
    // write_bytes(fw, &file_type[0], 3); /* file type */
    // out_blk(fw); /* done with block 0 */
    
    // new_blk(1); /* k7 block 1: content of file */
    // write_byte(fw, 0); /* binary chunk */
    // write_word(fw, size); /* size of chunk */
    // write_word(fw, start); /* load address */
    // for (int i=0;i<size;i++)
    // {
    //     unsigned char byt;
    //     (void)!fread(&byt,1,1,fr);
    //     write_byte(fw, byt); /* data */
    // }
    
    // write_byte(fw, 0xff); /* execution chunk */
    // write_word(fw, 0x0000); /* len = 0 */
    // write_word(fw, runaddr); /* exec address */
    // out_blk(fw); /* done with k7 block 1 */
    // new_blk(0xff); /* k7 block 0xff : end of k7 file */
    // out_blk(fw); /* done with it */

    Bank * bank = _environment->expansionBanks;

    while( bank ) {

        if ( bank->address ) {

            char bankNumber[MAX_TEMPORARY_STORAGE];
            sprintf( bankNumber, "bank%2.2x  dat", ( bank->id ) );

            addBinaryFile( fw, bankNumber, 0xa000, bank->data, bank->address );

        }
    
        bank = bank->next;

    }

    Storage * storage = _environment->storage;

    if ( storage ) {

        FileStorage * fileStorage = storage->files;

        while( fileStorage ) {

            char bankNumber[MAX_TEMPORARY_STORAGE];
            sprintf( bankNumber, "%8sdat", fileStorage->targetName );

            int size = 0;
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

            addBinaryFile( fw, bankNumber, 0xa000, buffer, size );

            fileStorage = fileStorage->next;

        }
    
        storage = storage->next;

    }
    
    fclose(fw);

    remove(temporaryFileName);

    return 0;
}

void target_analysis( Environment * _environment ) {
    
}