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

    if ( sfInfo.channels > 1 ) {
        CRITICAL_CANNOT_LOAD_STEREO_SAMPLES(_filename);
    }

    int effectiveLen = ( ( sfInfo.frames - 1 ) / 2 ) + 2;
    unsigned char * samplesBuffer = malloc( effectiveLen );
    memset( samplesBuffer, 0, effectiveLen );
    short sample0 = 0, sample1 = 0;
    for( int i = 0; i<sfInfo.frames; i+=2 ) {
        sf_read_short ( sndFile, &sample0, 1 );
        sf_read_short ( sndFile, &sample1, 1 );
        samplesBuffer[i>>1] = (unsigned char) 
            ( ( 8 + ( sample0 >> 12 ) ) ) |
            ( ( ( 8 + ( sample1 >> 12 ) ) ) << 4 )
            ;
    } 

    samplesBuffer[effectiveLen-1] = 0;
    
    variable_store_buffer( _environment, result->name, samplesBuffer, effectiveLen, 0 );

    sf_close( sndFile );

    return result;

}
