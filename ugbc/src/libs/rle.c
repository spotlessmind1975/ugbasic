/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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

#include "rle.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

RLECompressor * rle_create( ) {

    RLECompressor * rle = malloc( sizeof( RLECompressor ) );
    
    memset( rle, 0, sizeof( RLECompressor ) );

    return rle;

}

void rle_echo_state( RLECompressor * _rle, char _current, int _count ) {

    switch( _rle->state ) {

        // STARTING STATE
        case RLE_CS_READY:

            printf( "RLE_CS_READY:");

            break;

        // COUNTING THE CHARS
        case RLE_CS_COUNTING:

            printf( "RLE_CS_COUNTING:");

            break;

        case RLE_CS_EMIT:

            printf( "RLE_CS_EMIT:");

            break;

        // EMIT LITERALS INSIDE THE STAGE AREA
        case RLE_CS_EMIT_CONTINUE:

            printf( "RLE_CS_EMIT_CONTINUE:");

            break;

    }

    printf( "current = 0x%2.2x, count = %d\n", (unsigned char) _current, (unsigned char) _count );

}

MemoryBlock * rle_compress( RLECompressor * _rle, MemoryBlock * _input, int _size, int * _output_size ) {

    // Read pointer, move to the start of the area to compress.
    MemoryBlock * pointer = _input, * endPointer = pointer + _size;

    // Write pointer to a cleared area.
    MemoryBlock * output = malloc( 3 * _size + 1 ), * wpointer = output;
    memset( output, 0, _size );

    char current = 0;
    int count = 0;

    // Loop until the ASF is finished.
    while( _rle->state != RLE_CS_END_OF_BLOCK ) {

        // printf( "INPUT: 0x%4.4x:0x%2.2x\n", (int) (pointer - _input), (unsigned char) *pointer );

        switch( _rle->state ) {

            // STARTING STATE
            case RLE_CS_READY:

                // First of all, if we reach the end of memory
                // to be compressed, we pass into the final
                // state and the compression will end.
                if ( pointer == endPointer ) {
                    _rle->state = RLE_CS_END_OF_BLOCK;
                }
                // Copy the literal pointed by the read pointer
                // into the stage area, to be able to be used
                // to detect frequent patterns.
                else {
                    current = *pointer;
                    count = 1;
                    _rle->state = RLE_CS_COUNTING;
                }

                break;

            // COUNTING THE CHARS
            case RLE_CS_COUNTING:

                // Move forward by 1 byte.
                ++pointer;

                // If the end of the memory is reached,
                // we must emit the literal up to now.
                if ( pointer == endPointer ) {
                    _rle->state = RLE_CS_EMIT;
                    break;
                }

                // If the character is different from the
                // actual, we have to emit the element.
                if ( *pointer != current ) {
                    _rle->state = RLE_CS_EMIT;
                    break;
                }

                ++count;

                // If we reached the limit of the duplicate
                // representation, we have to emit the
                // element and to continue,
                // Note: we use 254 since 255 is used as
                // control character.
                if ( count == 254 ) {
                    _rle->state = RLE_CS_EMIT_CONTINUE;
                    break;
                }

                break;

            case RLE_CS_EMIT:

                // We emit the element and return to initial state.

                if ( count > 3 ) {
                    *wpointer = 0xff;
                    ++wpointer;
                    *wpointer = count;
                    ++wpointer;
                    *wpointer = current;
                    ++wpointer;
                    // printf( "OUTPUT: 0x%4.4x:0xff 0x%2.2x 0x%2.2x\n", (int) ( wpointer - output ),  (unsigned char) count, (unsigned char) current );
                } else {
                    while( count ) {
                        if ( (unsigned char) current == 0xff ) {
                            *wpointer = 0xff;
                            ++wpointer;
                            // printf( "OUTPUT: 0x%4.4x:0xff (escape)\n",  (int) ( wpointer - output ) );
                        }
                        *wpointer = current;
                        ++wpointer;
                        // printf( "OUTPUT: 0x%4.4x:0x%2.2x\n", (int) ( wpointer - output ), (unsigned char) current );
                        --count;
                    }
                }
                count = 0;
                _rle->state = RLE_CS_READY;
                break;

            // EMIT LITERALS INSIDE THE STAGE AREA
            case RLE_CS_EMIT_CONTINUE:

                // We emit the element and return to counting.
                *wpointer = 0xff;
                ++wpointer;
                *wpointer = count;
                ++wpointer;
                *wpointer = current;
                ++wpointer;

                // printf( "OUTPUT: 0x%4.4x:0xff 0x%2.2x 0x%2.2x\n", (int) ( wpointer - output ), (unsigned char) count, (unsigned char) current );

                count = 0;
                _rle->state = RLE_CS_COUNTING;
                break;

        }

        // rle_echo_state( _rle, current, count );

    }

    *wpointer = 0xfe;
    ++wpointer;

    *_output_size = (wpointer - output);

    // printf( "\n\n" );

    return output;

}

void rle_free( RLECompressor * _rle ) {

    free( _rle );

}

MemoryBlock * rle_uncompress( RLECompressor * _rle, MemoryBlock * _input, int _size, int * _output_size ) {

    // We allocate (precautiously) a memory block of 200
    // times the input buffer.
    *_output_size = 200 * _size;
    MemoryBlock * output = malloc( *_output_size );

    // This is the currently token examinated from
    // the input stream.
	MemoryBlock token;

    // Read pointer .   
	MemoryBlock * pointer = _input;

    // Write pointer.
	MemoryBlock * wpointer = output;

    int done = 0;

    // Loop through the entire input stream.
	do {

        // Take the current token from the input stream
        // and move to the next element of the stream.
		token = *pointer;
		++pointer;

        // A token of zero (0xfe) means "end of block".
        // Nothing must be done.
		if (token == 0xfe) {
            // printf( "EOB\n");
            done = 1;
		}

        // If the value of token is 0xff...
		else if (token == 0xff) {

            // Read the next.
            token = *pointer;
            ++pointer;

            // If it is 0xff, it means that is 0xff, actually!
            if ( token == 0xff ) {
                *wpointer = 0xff;
                ++wpointer;
                // printf( "0xff (literal, 2 bytes)\n");
            } 
            
            // Otherwise, we will output the duplications.
            else {

                int count = token;
                // Read the next.
                token = *pointer;
                ++pointer;

                // printf( "%d x 0x%2.2x (literal)\n", (unsigned char) count, (unsigned char) token);
                while( count ) {
                    *wpointer = token;
                    ++wpointer;
                    --count;
                }

            }

        }

        // Output the token "as is"
		else {
            *wpointer = token;
            ++wpointer;
            // printf( "0x%2.2x (literal, 1 byte)\n", (unsigned char) token);
		}

	} while (!done);

    *_output_size = (wpointer - output);

	return output;
}