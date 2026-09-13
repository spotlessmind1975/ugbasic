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
// #include <sndfile.h>
#define DR_FLAC_IMPLEMENTATION
#include "../../libs/dr_flac.h"

#define DR_MP3_IMPLEMENTATION
#include "../../libs/dr_mp3.h"

#define DR_WAV_IMPLEMENTATION
#include "../../libs/dr_wav.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

static Variable * samples_load_mp3_to_variable( Environment * _environment, char * _filename, char * _alias, int _bank_expansion ) {

    drmp3 mp3;
    if (!drmp3_init_file(&mp3, _filename, NULL)) {
        return NULL;
    }

    Variable * result = variable_temporary( _environment, VT_SAMPLES, "(samples)");

    result->frequency = mp3.sampleRate;

    int pcmCount = drmp3_get_pcm_frame_count(&mp3);
    int effectiveLen = ( ( pcmCount - 1 ) / 2 ) + 2;

    unsigned char * samplesBuffer = malloc( effectiveLen );
    memset( samplesBuffer, 0, effectiveLen );
    short * sample = malloc( sizeof( short ) * mp3.channels );
    short sample0 = 0, sample1 = 0;
    for( int i = 0; i<pcmCount; i+=2 ) {
        
        drmp3_read_pcm_frames_s16(&mp3, 1, sample);

        long sample0 = 0;
        for( int j=0; j<mp3.channels; ++j ) {
            sample0 += sample[j];
        }
        sample0 = sample0 / mp3.channels;
        short sample0s = (short) sample0;

        drmp3_read_pcm_frames_s16(&mp3, 1, sample);

        long sample1 = 0;
        for( int j=0; j<mp3.channels; ++j ) {
            sample1 += sample[j];
        }
        sample1 = sample1 / mp3.channels;

        short sample1s = (short) sample1;

        samplesBuffer[i>>1] = (unsigned char) 
            ( ( 8 + ( sample0 >> 12 ) ) ) |
            ( ( ( 8 + ( sample1 >> 12 ) ) ) << 4 )
            ;
        if ( samplesBuffer[i>>1] == 0 ) {
            samplesBuffer[i>>1] = 0x11;
        }
    } 

    samplesBuffer[effectiveLen-1] = 0;
    
    variable_store_buffer( _environment, result->name, samplesBuffer, effectiveLen, 0 );

    drmp3_uninit( &mp3 );

    return result;

}

static Variable * samples_load_flac_to_variable( Environment * _environment, char * _filename, char * _alias, int _bank_expansion ) {

    drflac* pFlac = drflac_open_file(_filename, NULL);
    if (pFlac == NULL) {
        return NULL;
    }

    Variable * result = variable_temporary( _environment, VT_SAMPLES, "(samples)");

    result->frequency = pFlac->sampleRate;

    int pcmCount = pFlac->totalPCMFrameCount;
    int effectiveLen = ( ( pcmCount - 1 ) / 2 ) + 2;

    unsigned char * samplesBuffer = malloc( effectiveLen );
    memset( samplesBuffer, 0, effectiveLen );
    short * sample = malloc( sizeof( short ) * pFlac->channels );
    short sample0 = 0, sample1 = 0;
    for( int i = 0; i<pcmCount; i+=2 ) {
        
        drflac_read_pcm_frames_s16(pFlac, 1, sample);

        long sample0 = 0;
        for( int j=0; j<pFlac->channels; ++j ) {
            sample0 += sample[j];
        }
        sample0 = sample0 / pFlac->channels;
        short sample0s = (short) sample0;

        drflac_read_pcm_frames_s16(pFlac, 1, sample);

        long sample1 = 0;
        for( int j=0; j<pFlac->channels; ++j ) {
            sample1 += sample[j];
        }
        sample1 = sample1 / pFlac->channels;

        short sample1s = (short) sample1;

        samplesBuffer[i>>1] = (unsigned char) 
            ( ( 8 + ( sample0 >> 12 ) ) ) |
            ( ( ( 8 + ( sample1 >> 12 ) ) ) << 4 )
            ;
        if ( samplesBuffer[i>>1] == 0 ) {
            samplesBuffer[i>>1] = 0x11;
        }
    } 

    samplesBuffer[effectiveLen-1] = 0;
    
    variable_store_buffer( _environment, result->name, samplesBuffer, effectiveLen, 0 );

    drflac_close( pFlac );

    return result;

}

static Variable * samples_load_wav_to_variable( Environment * _environment, char * _filename, char * _alias, int _bank_expansion ) {

    drwav wav;
    if (!drwav_init_file(&wav, _filename, NULL)) {
        return NULL;
    }

    Variable * result = variable_temporary( _environment, VT_SAMPLES, "(samples)");

    result->frequency = wav.sampleRate;

    int pcmCount = wav.totalPCMFrameCount;
    int effectiveLen = ( ( pcmCount - 1 ) / 2 ) + 2;

    unsigned char * samplesBuffer = malloc( effectiveLen );
    memset( samplesBuffer, 0, effectiveLen );
    short * sample = malloc( sizeof( short ) * wav.channels );
    short sample0 = 0, sample1 = 0;
    for( int i = 0; i<pcmCount; i+=2 ) {
        
        drwav_read_pcm_frames_s16(&wav, 1, sample);

        long sample0 = 0;
        for( int j=0; j<wav.channels; ++j ) {
            sample0 += sample[j];
        }
        sample0 = sample0 / wav.channels;
        short sample0s = (short) sample0;

        drwav_read_pcm_frames_s16(&wav, 1, sample);

        long sample1 = 0;
        for( int j=0; j<wav.channels; ++j ) {
            sample1 += sample[j];
        }
        sample1 = sample1 / wav.channels;

        short sample1s = (short) sample1;

        samplesBuffer[i>>1] = (unsigned char) 
            ( ( 8 + ( sample0 >> 12 ) ) ) |
            ( ( ( 8 + ( sample1 >> 12 ) ) ) << 4 )
            ;
        if ( samplesBuffer[i>>1] == 0 ) {
            samplesBuffer[i>>1] = 0x11;
        }
    } 

    samplesBuffer[effectiveLen-1] = 0;
    
    variable_store_buffer( _environment, result->name, samplesBuffer, effectiveLen, 0 );

    drwav_uninit( &wav );

    return result;

}

Variable * samples_load_to_variable( Environment * _environment, char * _filename, char * _alias, int _bank_expansion ) {

    Variable * result = samples_load_mp3_to_variable( _environment, _filename, _alias, _bank_expansion );

    if ( !result ) {
        result = samples_load_flac_to_variable( _environment, _filename, _alias, _bank_expansion );
    }

    if ( !result ) {
        result = samples_load_wav_to_variable( _environment, _filename, _alias, _bank_expansion );
    }

    if ( ! result ) {
        CRITICAL_CANNOT_LOAD_SAMPLES(_filename);
    }

    return result;

}
