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

#include "../../../ugbc.h"

#if defined(__pc128op__) || defined(__mo5__)

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

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

int convertbintok7(Environment * _environment)
{
    unsigned short start=_environment->program.startingAddress;
    unsigned short size;
    unsigned short runaddr=_environment->program.startingAddress;
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

    if(frmt(_environment, "main.exe",strlen("main.exe"),nome))
    {
        CRITICAL_BUILD_INVALID_FILENAME_K7("main.exe");
    }

    unsigned char file_type[]={0x02,0x00,0x00}; /* binary k7 file */

    fr=fopen(temporaryFileName,"rb");

    strcpy(destin,_environment->exeFileName);
    fw=fopen(destin,"wb");

    fseek(fr, 0L, SEEK_END);
    size = ftell(fr);
    rewind(fr);

    new_blk(0); /* k7 block 0: file name + type */
    write_bytes(fw, &nome[0], sizeof(nome)-1); /* file name */
    write_bytes(fw, &file_type[0], 3); /* file type */
    out_blk(fw); /* done with block 0 */
    
    new_blk(1); /* k7 block 1: content of file */
    write_byte(fw, 0); /* binary chunk */
    write_word(fw, size); /* size of chunk */
    write_word(fw, start); /* load address */
    for (int i=0;i<size;i++)
    {
        unsigned char byt;
        (void)!fread(&byt,1,1,fr);
        write_byte(fw, byt); /* data */
    }
    
    write_byte(fw, 0xff); /* execution chunk */
    write_word(fw, 0x0000); /* len = 0 */
    write_word(fw, runaddr); /* exec address */
    out_blk(fw); /* done with k7 block 1 */
    new_blk(0xff); /* k7 block 0xff : end of k7 file */
    out_blk(fw); /* done with it */

    Bank * bank = _environment->expansionBanks;

    while( bank ) {

        if ( bank->address ) {

            char bankNumber[MAX_TEMPORARY_STORAGE];
            sprintf( bankNumber, "bank%2.2x  dat", ( bank->id ) );

            new_blk(0); /* k7 block 0: file name + type */
            write_bytes(fw, bankNumber, 11); /* file name */
            write_bytes(fw, &file_type[0], 3); /* file type */
            out_blk(fw); /* done with block 0 */

            new_blk(1); /* k7 block 2: content of file */
            write_byte(fw, 0); /* binary chunk */
            write_word(fw, bank->address); /* size of chunk */
            write_word(fw, start); /* load address */
            for (int i=0;i<bank->address;i++)
            {
                unsigned char byt = bank->data[i];
                write_byte(fw, byt); /* data */
            }
            
            out_blk(fw); /* done with k7 block 1 */

        }
    
        new_blk(0xff); /* k7 block 0xff : end of k7 file */
        out_blk(fw); /* done with it */

        bank = bank->next;

    }

    Storage * storage = _environment->storage;

    if ( storage ) {

        FileStorage * fileStorage = storage->files;

        while( fileStorage ) {

            char bankNumber[MAX_TEMPORARY_STORAGE];
            strcpy( bankNumber, fileStorage->targetName );

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

            new_blk(0); /* k7 block 0: file name + type */
            write_bytes(fw, bankNumber, 11); /* file name */
            write_bytes(fw, &file_type[0], 3); /* file type */
            out_blk(fw); /* done with block 0 */

            new_blk(1); /* k7 block 2: content of file */
            write_byte(fw, 0); /* binary chunk */
            write_word(fw, size); /* size of chunk */
            write_word(fw, 0x6000); /* load address */
            for (int i=0;i<size;i++)
            {
                unsigned char byt = buffer[i];
                write_byte(fw, byt); /* data */
            }
            
            out_blk(fw); /* done with k7 block 1 */

            fileStorage = fileStorage->next;

        }
    
        storage = storage->next;

    }

    new_blk(0xff); /* k7 block 0xff : end of k7 file */
    out_blk(fw); /* done with it */

}

#endif