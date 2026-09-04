/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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

#include <stdio.h>
#include <sndfile.h>

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

Variable * samples_load_to_variable( Environment * _environment, char * _filename, char * _alias, int _bank_expansion ) {

    Variable * result = variable_temporary( _environment, VT_SAMPLES, "(samples)");

    // SNDFILE*  sf_open    (const char *path, int mode, SF_INFO *sfinfo) ;
    // The sf_open() function opens the sound file at the specified path. The filename is byte encoded, 
    // but may be utf-8 on Linux, while on Mac OS X it will use the filesystem character set. 
    // On Windows, there is also a Windows specific sf_wchar_open() that takes a UTF16_BE encoded filename.

    SF_INFO sfInfo;
    memset( &sfInfo, 0, sizeof(SF_INFO) );
    SNDFILE * sndFile = sf_open( _filename, SFM_READ, &sfInfo) ;

    if ( !sndFile ) {
        CRITICAL_CANNOT_LOAD_SAMPLES(_filename);
    }

    int effectiveLen = ( ( sfInfo.frames  - 1 ) / 2 ) + 2;
    
    FILE * fh = fopen("samples.pcm", "wb");

    unsigned char * samplesBuffer = malloc( effectiveLen );
    memset( samplesBuffer, 0, effectiveLen );
    short * sample = malloc( sizeof( short ) * sfInfo.channels );
    short sample0 = 0, sample1 = 0;
    for( int i = 0; i<sfInfo.frames; i+=2 ) {
        
        sf_readf_short ( sndFile, sample, 1 );

        long sample0 = 0;
        for( int j=0; j<sfInfo.channels; ++j ) {
            sample0 += sample[j];
        }
        sample0 = sample0 / sfInfo.channels;
        short sample0s = (short) sample0;

        fwrite(&sample0, 2, 1, fh );

        sf_readf_short ( sndFile, sample, 1 );

        long sample1 = 0;
        for( int j=0; j<sfInfo.channels; ++j ) {
            sample1 += sample[j];
        }
        sample1 = sample1 / sfInfo.channels;

        short sample1s = (short) sample1;
        fwrite(&sample1s, 2, 1, fh );

        samplesBuffer[i>>1] = (unsigned char) 
            ( ( 8 + ( sample0 >> 12 ) ) ) |
            ( ( ( 8 + ( sample1 >> 12 ) ) ) << 4 )
            ;
        if ( samplesBuffer[i>>1] == 0 ) {
            samplesBuffer[i>>1] = 0x11;
        }
    } 

    fclose( fh );

    samplesBuffer[effectiveLen-1] = 0;
    
    variable_store_buffer( _environment, result->name, samplesBuffer, effectiveLen, 0 );

    sf_close( sndFile );

    return result;

}
