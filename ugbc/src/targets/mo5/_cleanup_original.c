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
    		CRITICAL("abort");
			// printf("incompatible string\nplease use *******.*** format\n");
			// return -1;
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

