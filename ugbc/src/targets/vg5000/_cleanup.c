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

void target_finalization( Environment * _environment ) {

    ef9345_finalization( _environment );

    if ( ! _environment->anyProtothread ) {
        outhead0("PROTOTHREADINIT:" );
        outline0("RET");
    }

}

// -------------------------------------------------------------------------
// CONVERT BINARY TO K7 TAPE FILE 
// -------------------------------------------------------------------------

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int convertbintok7(Environment * _environment)
{
    unsigned short start=0x3000;
    unsigned short size;
    unsigned short runaddr=0x3000;
    FILE *fr,*fw;
    char nome[12];
    char source[20];
    char destin[100];

    // Rename the output file into a temporary filename
    char temporaryFileName[MAX_TEMPORARY_STORAGE];
    sprintf(temporaryFileName, "%s.bin", get_temporary_filename( _environment ) );
    remove( temporaryFileName );
    rename( _environment->exeFileName, temporaryFileName );
    
    fr=fopen(temporaryFileName,"rb");
    if(!fr) 
    {   
        CRITICAL_CANNOT_OPEN_EXECUTABLE_FILE( temporaryFileName );
    }

    fr=fopen(temporaryFileName,"rb");

    strcpy(destin,_environment->exeFileName);
    fw=fopen(destin,"wb");

    fseek(fr, 0L, SEEK_END);
    size = ftell(fr);
    rewind(fr);

    unsigned char header[] = {
        0xd3, 0xd3, 0xd3, 0xd3, 0xd3, 0xd3, 0xd3, 0xd3,
        0xd3, 0xd3, 0x4d, 'm', 'a', 'i', 'n', 0x00,
        0x00, 0x00, 0x31, 0x30, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0xfb, 0x49, 0x00, 0x00, 0x00, 0x00,
        0x00, 0xd6, 0xd6, 0xd6, 0xd6, 0xd6, 0xd6, 0xd6, 
        0xd6, 0xd6, 0xd6
    };

    unsigned char basic[] = {
        0x00, 0x08, 0x4a, 0x0a, 0x00,
        0x9f, 0x31, 0x38, 0x39, 0x35,
        0x34, 0x3a, 0x00, 0x00, 0x00
    };

    int length = size + sizeof( basic );
    int checksum = 0;

    for( int i=0; i<sizeof(basic); ++i ) {
        checksum += basic[i];
    }

    for( int i=0; i<size; ++i ) {
        unsigned char c = (unsigned char) fgetc(fr);
        checksum += c;
    }

    header[28] = ( length & 0xff );
    header[29] = ( ( length>>8) & 0xff );
    header[30] = ( checksum & 0xff );
    header[31] = ( ( checksum >> 8 ) & 0xff );

    fwrite( header, sizeof( header ), 1, fw );
    fwrite( basic, sizeof( basic ), 1, fw );

    fseek( fr, 0, SEEK_SET );
    for( int i=0; i<size; ++i ) {
        unsigned char c = (unsigned char) fgetc(fr);
        fputc(c, fw);
    }
    fputc(0, fw);
    fputc(0, fw);
    fputc(0, fw);
    fputc(0, fw);
    fputc(0, fw);
    fputc(0, fw);
    fputc(0, fw);
    fputc(0, fw);
    fputc(0, fw);
    fputc(0, fw);
    fputc(0, fw);
    fputc(0, fw);
    fputc(0, fw);
    fputc(0, fw);
    fputc(0, fw);

    fclose(fr);
    fclose(fw);
    
    return 0;
}

void target_analysis( Environment * _environment ) {
    
}