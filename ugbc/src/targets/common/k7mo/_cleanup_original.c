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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

#if defined(__pc128op__) || defined(__mo5__)

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

static unsigned int sum=0;
static unsigned char chk=0;
static unsigned short l;
static int nblock;
static int rest;
static int cnt=0;
static int frmt( Environment * _environment, char * ptr, char size,char* out)
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

// FIX #173
#if ( defined(__BYTE_ORDER) && __BYTE_ORDER == __BIG_ENDIAN ) || \
    defined(__BIG_ENDIAN__) || \
    defined(__ARMEB__) || \
    defined(__THUMBEB__) || \
    defined(__AARCH64EB__) || \
    defined(_MIBSEB) || defined(__MIBSEB) || defined(__MIBSEB__)

	static void swapen(unsigned short *num)
	{
		return *num;
	}

#else

	static void swapen(unsigned short *num)
	{
	unsigned short swapped;
	swapped = (*num>>8) | (*num<<8);
	*num=swapped;
	}

#endif

static void crc ( unsigned char * data, int l,unsigned int   * old)
{ 

   cnt+=l;
	for (int i= 0;i<l;i++)
	{
	(*old)+=data[i];

	}
}

static unsigned char cmpl(unsigned int n)
{
	return 0x100- ((unsigned char)n);
}

int convertbintok7_original(Environment * _environment)
{
	// if(argc==1)
	// {
	// 	printf("Missing arguments !!!!!!\n"
	// 	"bin2k7 source pc128_filename K7_filename\n"
	// 	"load and exec address is set to &H0000.\n"
	// 	"Use offset to load to any address. EX: LOADM\"CASS:\",&H6000 will load starting to &H6000\n"
	// 	);
	// 	return -1;
	// }
	unsigned short start=0x3000;
	unsigned short size;
	unsigned short runaddr=0x3000;
	FILE *fr,*fw;
	char nome[12];
	char nomecod[12];
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
		// printf("source file not found!!!!");
		// return -1;
	}

	if(frmt(_environment, "main.exe",strlen("main.exe"),nome))
	{
		CRITICAL_BUILD_INVALID_FILENAME_K7("main.exe");
	}

	unsigned char byt;
	unsigned short l;
	unsigned char h[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0x3c,0x5a};
    unsigned char h1[]={1,0,0};
    unsigned char h2[]={1,0};
	unsigned char n[]={0x00,0x10};
	unsigned char n1[]={0x02,0x00,0x00};
	unsigned char end[]={0xff,0x02,0x00};
	unsigned char z=0;
	unsigned char u=1;
	unsigned char preend[]={0xff,0x00,0x00};
	fr=fopen(temporaryFileName,"rb");
	// if(argv[3]==NULL)
	// {
		strcopy(destin,_environment->exeFileName);
		// strcat(destin,".K7");
	// }
	// else
	// strcopy(destin,argv[3]);
	fw=fopen(destin,"wb");
	fseek(fr, 0L, SEEK_END);
    size = ftell(fr);
    l=size;
    nblock=floor((size+12)/254);
    // printf("n blocks: %d\n",nblock);
    // printf("size: %d\n",size);
    rest=size+12-nblock*254;

	// Fix #187
	unsigned char restByte = (unsigned char)rest;
    
    rewind(fr);
    swapen(&size);
    swapen(&start);
    swapen(&runaddr);
	fwrite(&h,sizeof(h),1,fw);
	fwrite(&n,sizeof(n),1,fw);
	fwrite(&nome,sizeof(nome)-1,1,fw);
	fwrite(&n1,3,1,fw);
	crc(nome,11,&sum);
	crc(n1,1,&sum);
	
	chk=cmpl(sum);
	sum=0;
	cnt=0;
	fwrite(&chk,1,1,fw);
	fwrite(&h,sizeof(h),1,fw);
	if(nblock>0)
	{
    	fwrite(&h1,sizeof(h1),1,fw);
	}
	else
	{
			fwrite(&u,sizeof(u),1,fw);
			// Fix #187
	        fwrite(&restByte,1,1,fw);
	        fwrite(&z,sizeof(z),1,fw);
	}
	cnt++;
	fwrite(&size,sizeof(size),1,fw);
	fwrite(&start,sizeof(start),1,fw);
	crc((unsigned char *)&size,sizeof(size),&sum);
	crc((unsigned char *)&start,sizeof(start),&sum);
	for (int i=0;i<l;i++)
	{
		if(cnt>253)
		{
			nblock--;
			chk=cmpl(sum);
			sum=0;
			//printf("%d\n",chk);
	    	fwrite(&chk,1,1,fw);
			fwrite(&h,sizeof(h),1,fw);
			if(nblock>0)
			fwrite(&h2,sizeof(h2),1,fw);
			else
			{
					fwrite(&u,sizeof(u),1,fw);
					// Fix #187
					fwrite(&restByte,1,1,fw);
				    // printf("*****\n");
			}
			cnt=0;
		    
		}
		(void)!fread(&byt,1,1,fr);
		crc(&byt,1,&sum);
		fwrite(&byt,1,1,fw);
	}
		crc((unsigned char *)&preend,3,&sum);
		fwrite(&preend,3,1,fw);
		crc((unsigned char *)&runaddr,2,&sum);
		fwrite(&runaddr,2,1,fw);
		chk=cmpl(sum);
		sum=0;
		fwrite(&chk,1,1,fw);
		fwrite(&h,sizeof(h),1,fw);
		fwrite(&end,sizeof(end),1,fw);
		// printf("chk %x rest %x block %d\n",chk,rest,nblock);
		
	fclose(fr);
	fclose(fw);
	
    remove(temporaryFileName);

	return 0;
}

#endif