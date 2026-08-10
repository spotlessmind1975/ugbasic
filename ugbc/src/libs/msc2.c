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

#include "msc2.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

MSC2Compressor * msc2_create( MemoryBlock * _origin, int _origin_size ) {

    MSC2Compressor * msc2 = malloc( sizeof( MSC2Compressor ) );
    
    memset( msc2, 0, sizeof( MSC2Compressor ) );

    msc2->origin = _origin;
    msc2->origin_size = _origin_size;

    return msc2;

}

MemoryBlock * msc2_compress( MSC2Compressor * _msc2, MemoryBlock * _target, int * _output_size ) {

    MemoryBlock * result = malloc( 3 * _msc2->origin_size );

    memset( result, 0, 3 * _msc2->origin_size );

    int actualSize = _msc2->origin_size;

    MemoryBlock * o = _msc2->origin;
    MemoryBlock * t = _target;
    MemoryBlock * r = result;

    int conteggio = 0;

    _msc2->state = MSC2_CS_START;

    while( actualSize ) {

        switch( _msc2->state ) {
            case MSC2_CS_START:

                // printf( "START[%d:%d:%d]: %2.2x -> %2.2x\n", (int)( o - _msc2->origin ), (int)( t - _target ), (int)( r - result ), (unsigned char)*o, (unsigned char)*t );

                if ( *t == 0xff ) {
                    _msc2->state = MSC2_CS_EMIT_FF1;
                } else if ( *o == *t ) {
                    _msc2->state = MSC2_CS_INCREMENT1;
                } else if ( *o != *t ) {
                    _msc2->state = MSC2_CS_EMIT_TARGET1;
                }
                break;

            case MSC2_CS_INCREMENT1:
        
                ++conteggio;

                ++o; ++t; --actualSize;;

                // printf( "INCREMENT1[%d:%d:%d]: (%d) %2.2x -> %2.2x\n", (int)( o - _msc2->origin ), (int)( t - _target ), (int)( r - result ), conteggio, (unsigned char)*o, (unsigned char)*t );

                if ( *t == 0xff ) {
                    _msc2->state = MSC2_CS_EMIT_FF2;
                } else if ( (*o != *t) ) {
                    _msc2->state = MSC2_CS_EMIT_TARGET2;
                } else {
                    _msc2->state = MSC2_CS_INCREMENT2;
                }
                break;

            case MSC2_CS_INCREMENT2:
        
                ++conteggio;

                ++o; ++t; --actualSize;;

                // printf( "INCREMENT2[%d:%d:%d]: (%d) %2.2x -> %2.2x\n", (int)( o - _msc2->origin ), (int)( t - _target ), (int)( r - result ), conteggio, (unsigned char)*o, (unsigned char)*t );

                if ( (*o != *t) || (conteggio == 255) ) {
                    _msc2->state = MSC2_CS_EMIT_COUNT;
                }

                break;

            case MSC2_CS_EMIT_COUNT:

                // printf( "EMIT COUNT[%d:%d:%d]: ff%d\n", (int)( o - _msc2->origin ), (int)( t - _target ), (int)( r - result ), conteggio );

                *r = 0xff; ++r;
                *r = conteggio; ++r;                
                _msc2->state = MSC2_CS_EMIT_TARGET1;
                break;

            case MSC2_CS_EMIT_TARGET1:

                // printf( "EMIT TARGET1[%d:%d:%d]: %2.2x\n", (int)( o - _msc2->origin ), (int)( t - _target ), (int)( r - result ), (unsigned char) *t );
                                
                conteggio = 0;
                *r = *t; ++r;
                ++o; ++t; --actualSize;;
                _msc2->state = MSC2_CS_START;                
                break;

            case MSC2_CS_EMIT_TARGET2:

                // printf( "EMIT TARGET2[%d:%d:%d]: %2.2x%2.2x\n", (int)( o - _msc2->origin ), (int)( t - _target ), (int)( r - result ), (unsigned char) *(t-1), (unsigned char) *t );
                
                *r = *(t-1); ++r;
                
                conteggio = 0;
                *r = *t; ++r;
                ++o; ++t; --actualSize;;
                _msc2->state = MSC2_CS_START;                
                break;

            case MSC2_CS_EMIT_FF1:

                // printf( "EMIT FF1[%d:%d:%d]\n", (int)( o - _msc2->origin ), (int)( t - _target ), (int)( r - result ) );

                *r = 0xff; ++r;
                *r = 0x00; ++r;
                *r = 0xff; ++r;
                ++o; ++t; --actualSize;;
                
                _msc2->state = MSC2_CS_START;                
                break;

            case MSC2_CS_EMIT_FF2:

                // printf( "EMIT FF2[%d:%d:%d]: %2.2xff\n", (int)( o - _msc2->origin ), (int)( t - _target ), (int)( r - result ), (unsigned char)*t );

                *r = *t; ++r;
                ++o; ++t; --actualSize;;
                
                conteggio = 0;
                *r = 0xff; ++r;
                *r = 0x00; ++r;
                *r = 0xff; ++r;
                ++o; ++t; --actualSize;;
                _msc2->state = MSC2_CS_START;                
                break;

        }

    }

    *_output_size = (r - result);

    return result;

}

MemoryBlock * msc2_uncompress( MSC2Compressor * _msc2, MemoryBlock * _output, int _output_size ) {

    MemoryBlock * result = malloc( _msc2->origin_size );

    memcpy( result, _msc2->origin, _msc2->origin_size );

    int actualSize = _output_size;

    MemoryBlock * o = _output;
    MemoryBlock * r = result;

    int conteggio = 0;

    _msc2->state = MSC2_US_START;

    while( actualSize ) {

        switch( _msc2->state ) {
            case MSC2_US_START:

                // printf( "START[%d:%d]: o = %2.2x\n", (int)(o-_output), (int)(r-result), (unsigned char) *o );

                if ( *o == 0xff ) {
                    _msc2->state = MSC2_US_SKIP;
                } else {
                    _msc2->state = MSC2_US_EMIT;
                }
                break;

            case MSC2_US_SKIP:

                ++o; --actualSize;

                conteggio = (int) *o;
                
                // printf( "SKIP[%d:%d]: conteggio = %d\n", (int)(o-_output), (int)(r-result), conteggio );

                ++o; --actualSize;

                r += conteggio;

                _msc2->state = MSC2_US_EMIT;

                break;

            case MSC2_US_EMIT:

                // printf( "EMIT[%d:%d]: o = %2.2x\n", (int)(o-_output), (int)(r-result), *o );

                *r = *o; ++r;

                ++o; --actualSize;

                _msc2->state = MSC2_US_START;
                break;

        }

    }

    return result;

}

void msc2_free( MSC2Compressor * _msc2 ) {
    
    free( _msc2 );

}
