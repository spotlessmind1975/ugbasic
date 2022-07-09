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

#include "msc1.h"

typedef struct _MSC1SequenceValue {

    MemoryBlock                 *   offset;

    struct _MSC1SequenceValue   *   next;

} MSC1SequenceValue;

typedef struct _MSC1Sequence {

    MemoryBlock                 value[4];
    int                         length;

    MSC1SequenceValue       *   first;
    int                         count;
    MemoryBlock             *   used;

    struct _MSC1Sequence    *   next;

} MSC1Sequence;

typedef struct _MSC1Sequences {

    MSC1Sequence            *   first;

    int                         count;

} MSC1Sequences;

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

MSC1Sequence * msc1_find_sequence( MSC1Sequences * _sequences, MemoryBlock * _literal, int _limit ) {

    // If sequences are presente, we look if the same 
    // sequence has been already stored inside the 
    // structure.
    MSC1Sequence * actual = NULL;

    if ( _sequences->first ) {
        // Give a look to find if the same (sub)sequence
        // has been stored before. Stop as soon as we
        // find it.
        actual = _sequences->first;
        while( actual ) {
            // printf("%2.2x%2.2x%2.2x%2.2x == %2.2x%2.2x%2.2x%2.2x ?\n", 
            //     _literal[0], _literal[1], _literal[2], _literal[3],
            //     actual->value[0], actual->value[1], actual->value[2], actual->value[3]
            // );

            if ( memcmp( _literal, actual->value, 4 ) == 0 ) {
                // printf( " --> ok!\n");
                break;
            }
            actual = actual->next;

            if ( _limit ) {
                --_limit;
                if ( !_limit) {
                    return NULL;
                }
            }

        }

    }

    return actual;

}

MSC1Sequences * msc1_generate_sequences( MemoryBlock * _input, int _size ) {

    // Initialize the list of sequences:
    //     SEQUENCES = <empty>
    MSC1Sequences * sequences = malloc( sizeof( MSC1Sequences ) );
    memset( sequences, 0, sizeof( MSC1Sequences ) );

    // We explore the input buffer in order to identify every
    // sequences of 4 chars. We skip by just 1 char, in order
    // to detect every subsequences:
    //
    //      INPUT:   A B C D E F G -> 
    //                  -> sequence: ABCD
    //                  -> sequence: BCDE
    //                  -> sequence: CDEF
    //                  -> sequence: DEFG
    //

    int i = 0;
    for( i=0; i<=(_size-4); ++i ) {

        // The position is stored inside this structure.
        MSC1SequenceValue * sequenceValue = malloc( sizeof( MSC1SequenceValue ) );
        memset( sequenceValue, 0, sizeof( MSC1SequenceValue ) );
        sequenceValue->offset = _input+i;

        // This is the (sub)sequence to check.
        MemoryBlock literal[4];
        memcpy( literal, sequenceValue->offset, 4 );

        // If sequences are presente, we look if the same 
        // sequence has been already stored inside the 
        // structure.
        MSC1Sequence * actual = msc1_find_sequence( sequences, literal, 0 );

        // (Sub)sequence has been found! So we must
        // register the position inside the input buffer.
        if ( actual ) {

            // We put it at the end of the already present
            // structures.
            if ( ! actual->first ) {
                actual->first = sequenceValue;
            } else {
                MSC1SequenceValue * actualValue = actual->first;
                while( actualValue ) {
                    if ( ! actualValue->next ) {
                        actualValue->next = sequenceValue;
                        break;
                    }
                    actualValue = actualValue->next;
                }
            }

            ++actual->count;

        } else {

            // (Sub)sequence has NOT been found! So we must
            // register the position inside the input buffer
            // as the first one.
            actual = malloc( sizeof( MSC1Sequence ) );
            memset( actual, 0, sizeof( MSC1Sequence ) );
            actual->length = 4;
            memcpy( actual->value, literal, 4 );
            actual->first = sequenceValue;
            actual->count = 1;

            if ( ! sequences->first ) {
                sequences->first = actual;
                sequences->count = 1;
            } else {
                actual->next = sequences->first;
                sequences->first = actual;
                ++sequences->count;
            }

        }

    }

    return sequences;

}

void msc1_sort( MSC1Sequences * _sequences ) {

    // Loop until no swap will be done.
    int done = 0;
    while( ! done ) {

        done = 1;
        
        // Previous and actual node examinated.
        MSC1Sequence * previous = NULL;
        MSC1Sequence * actual = _sequences->first;

        // Until all nodes will be explored...
        while( actual ) {

            // No comparison is possibile if next node is missing.
            if ( ! actual->next ) {
                break;
            }

            // If the next node has a greater count, we have to
            // move it on the upper part of the list.
            if ( actual->count < actual->next->count ) {

                // We have do differentiate if we are swapping the
                // first node or any other node.
                MSC1Sequence * swapped = NULL;

                // Any other node...
                if ( previous ) {
                    swapped = actual->next->next;
                    previous->next = actual->next;
                    previous->next->next = actual;
                    actual->next = swapped;
                // First node...
                } else {
                    swapped = actual->next->next;
                    _sequences->first = actual->next;
                    _sequences->first->next = actual;
                    actual->next = swapped;
                }
                done = 0;
                break;
            } else {
                // Go ahead with the next node...
                previous = actual;
                actual = actual->next;
            }

        }

    }

}

void msc1_dump( MSC1Sequences * _sequences ) {

    printf( "%d SEQUENCES\n", _sequences->count );
    MSC1Sequence * actual = _sequences->first;

    while( actual ) {
        printf( "  %c%c%c%c = %d offsets\n", 
            actual->value[0], actual->value[1], 
            actual->value[2], actual->value[3], 
            actual->count );
        actual = actual->next;
    }

}

MSC1Compressor * msc1_create( int _maximum_repeated_sequences ) {

    MSC1Compressor * msc1 = malloc( sizeof( MSC1Compressor ) );
    
    memset( msc1, 0, sizeof( MSC1Compressor ) );

    msc1->maximumRepeatedSequences = _maximum_repeated_sequences;

    return msc1;

}

void msc1_echo_state( MSC1CompressorState _state, int _read, int _write, int _repeats, int _iliteral, char * _literal, char * _pointer, char *_wpointer, MSC1Sequence * _actual ) {

    switch( _state ) {

        // STARTING STATE
        case MSC1_CS_READY:
            printf( "MSC1_CS_READY");
            break;

        // STORING THE LITERAL
        case MSC1_CS_STORE:
            printf( "MSC1_CS_STORE");
            break;

        // MOVE THE READ POINTER FORWARD BY 1 CHARACTER
        case MSC1_CS_MOVE1:
            printf( "MSC1_CS_MOVE1");
            break;

        // EMIT LITERALS INSIDE THE STAGE AREA
        case MSC1_CS_LITERAL:
            printf( "MSC1_CS_LITERAL");
            break;

        // EMIT LITERAL FOR DUPLICATED PATTERN
        case MSC1_CS_LITERAL_DUPE:
            printf( "MSC1_CS_LITERAL_DUPE");
            break;

        // MOVE FORWARD BY 4 CHARACTERS
        case MSC1_CS_MOVE4:
            printf( "MSC1_CS_READY\n");
            break;

        // CHECK IF PATTERN IS STILL DUPLICATED
        case MSC1_CS_DUPE_STORE:
            printf( "MSC1_CS_DUPE_STORE");
            break;

        // MOVE FORWARD BY 4 CHARACTERS, AND COUNT THE REPETITIONS
        case MSC1_CS_DUPE_MOVE4:
            printf( "MSC1_CS_DUPE_MOVE4");
            break;

        // EMIT THE DUPLICATION COMMAND
        case MSC1_CS_DUPES:
            printf( "MSC1_CS_DUPES");
            break;

        case MSC1_CS_END_OF_BLOCK:
            printf( "MSC1_CS_END_OF_BLOCK");
            break;
    }

    printf(" rp=%4.4x  wp=%4.4x il=%d rep=%d\n", _read, _write, _iliteral, _repeats );
    printf(" LT=...%2.2x%2.2x%2.2x%2.2x  seq=%p  used=%p\n", *(_literal-3), *(_literal-2), *(_literal-1), *(_literal), _actual, (_actual)?(_actual->used):NULL );
    printf(" RP=...%2.2x%2.2x%2.2x%2.2x\n", *(_pointer-3), *(_pointer-2), *(_pointer-1), *(_pointer) );
    printf(" WP=...%2.2x%2.2x%2.2x%2.2x\n", *(_wpointer-4), *(_wpointer-3), *(_wpointer-2), *(_wpointer-1) );

}

MemoryBlock * msc1_compress( MSC1Compressor * _msc1, MemoryBlock * _input, int _size, int * _output_size ) {

    // Read pointer, move to the start of the area to compress.
    MemoryBlock * pointer = _input, * endPointer = pointer + _size;

    // Write pointer to a cleared area.
    MemoryBlock * output = malloc( 10 * _size ), * wpointer = output;
    memset( output, 0, _size );

    // Extract all 4 characters sequences from the input,
    // and sort them in order to have the most frequent first.
    MSC1Sequences * sequences = msc1_generate_sequences( _input, _size );
    msc1_sort( sequences );
    // msc1_dump( sequences );

    MSC1Sequence * actual = NULL;
    MemoryBlock literal[128];
    memset( literal, 0, 128 );
    int iliteral = 0;
    int repeats = 0;

    // Loop until the ASF is finished.
    while( _msc1->state != MSC1_CS_END_OF_BLOCK ) {

        // msc1_echo_state( _msc1->state, (pointer-_input), (wpointer-output), repeats, iliteral, &literal[iliteral], pointer, wpointer, actual );
        // printf("\n");

        switch( _msc1->state ) {

            // STARTING STATE
            case MSC1_CS_READY:

                // First of all, if we reach the end of memory
                // to be compressed, we pass into the final
                // state and the compression will end.
                if ( pointer == endPointer ) {
                    _msc1->state = MSC1_CS_END_OF_BLOCK;
                    break;
                }

                // Else, if no frequent pattern has been reached,
                // we can start to store the literal from the
                // input.
                else if ( ! actual ) {
                    iliteral = 0;
                    memset( literal, 0, 128 );
                    _msc1->state = MSC1_CS_STORE;
                }

                // // Else if the frequent pattern has been reached
                // // but not emitted yet on the output, then we
                // // can write out it.
                // else if ( ! actual->used ) {
                //     _msc1->state = MSC1_CS_LITERAL_DUPE;
                // } 

                // Finally if the frequent pattern has been reached
                // and it has been emitted (before) then we can
                // count and emit the repetitions.
                else {
                    _msc1->state = MSC1_CS_DUPE_STORE;
                }
                break;

            // STORING THE LITERAL
            case MSC1_CS_STORE:

                // Copy the literal pointed by the read pointer
                // into the stage area, to be able to be used
                // to detect frequent patterns.
                literal[iliteral] = *pointer;
                _msc1->state = MSC1_CS_MOVE1;
                break;

            // MOVE THE READ POINTER FORWARD BY 1 CHARACTER
            case MSC1_CS_MOVE1:

                // Increment the read pointer and the
                // size of the stage area.
                ++iliteral;
                ++pointer;

                // If the end of the memory is reached,
                // we must emit the literal up to now.
                if ( pointer == endPointer ) {
                    _msc1->state = MSC1_CS_LITERAL;
                    break;
                }

                // Until we reach at least 4 characters,
                // we can only store the character sequence.
                if ( iliteral < 4 ) {
                    _msc1->state = MSC1_CS_STORE;
                    break;
                }

                // If we reach the limit of the stage area,
                // we need to emit the literals and start
                // over in collecting characters.
                if ( iliteral == 127 ) {
                    _msc1->state = MSC1_CS_LITERAL;
                    break;
                }

                // Since there are at least 4 characters, we can
                // look if the last 4 characters belongs to the
                // more frequent special sequences.
                actual = msc1_find_sequence( sequences, &literal[iliteral-4], _msc1->maximumRepeatedSequences );

                // If the sequence cannot be found, we can go on
                // and try to continue to store the literals into
                // the stage area.
                if ( ! actual ) {
                    _msc1->state = MSC1_CS_STORE;
                    break;
                } 
                
                // Otherwise, we can skip the sequence and go on in
                // emitting literals from stage area.
                else {
                    _msc1->state = MSC1_CS_LITERAL;
                    break;
                }
                break;

            // EMIT LITERALS INSIDE THE STAGE AREA
            case MSC1_CS_LITERAL:

                // If we are emitting the literal from stage area
                // because we find out a frequent pattern...
                if ( actual ) {

                    // If the pattern is distant more than 1023
                    // bytes from the output byte, we must
                    // regenerate the pattern.
                    if( actual->used && ( wpointer - actual->used ) > 1024 ) {
                        actual->used = NULL;
                    }

                    // Write the number of symbols and,
                    // following, the literals themselves.
                    *wpointer = iliteral;
                    ++wpointer;
                    memcpy( wpointer, literal, iliteral );
                    wpointer += ( iliteral );

                    if ( ! actual->used ) {
                        actual->used = ( wpointer - 4 );
                    }

                } 
                
                // ... else we are emitting literals because
                // the size of stage area has been filled up.
                else {
                    // Write the number of symbols and,
                    // following, the literats themselves.
                    *wpointer = iliteral;
                    ++wpointer;
                    memcpy( wpointer, literal, iliteral );
                    wpointer += iliteral;
                }

                // Move to the initial state.
                _msc1->state = MSC1_CS_READY;
                break;

            // // EMIT LITERAL FOR DUPLICATED PATTERN
            // case MSC1_CS_LITERAL_DUPE:

            //     // Write the number of symbols and,
            //     // following, the literats themselves.
            //     *wpointer = 4;
            //     ++wpointer;
            //     memcpy( wpointer, &literal[iliteral - 4], 4 );
                
            //     // Register the last pattern pointer,
            //     // to be used to calculate offset.
            //     actual->used = wpointer;

            //     wpointer += 4;

            //     // Move to the next state
            //     _msc1->state = MSC1_CS_DUPE_MOVE4;
            //     break;

            // MOVE FORWARD BY 4 CHARACTERS
            case MSC1_CS_MOVE4:

                pointer += 4;
                _msc1->state = MSC1_CS_READY;
                break;

            // CHECK IF PATTERN IS STILL DUPLICATED
            case MSC1_CS_DUPE_STORE:

                // If the input memory block is finished,
                // we must emit the new literal.
                if ( ( pointer + 4 ) >= endPointer ) {
                    _msc1->state = MSC1_CS_DUPES;
                    break;
                }

                // If the pattern is duplicated, we can move forward
                // by 4 characters (and increment the repetitions).
                if ( memcmp( pointer, &literal[iliteral-4], 4 ) == 0 ) {

                    // Increment the repetitions.
                    ++repeats;

                    _msc1->state = MSC1_CS_DUPE_MOVE4;
                    break;
                } 
                
                // The repetition is ended, we can emit the 
                // duplicate definition.
                else {

                    _msc1->state = MSC1_CS_DUPES;
                    break;
                }

                break;

            // MOVE FORWARD BY 4 CHARACTERS, AND COUNT THE REPETITIONS
            case MSC1_CS_DUPE_MOVE4:

                // Move forward by 4 characters.
                pointer += 4;

                // If the input memory block is finished,
                // we must return back by 4 characters and
                // emit the duplication command.
                if ( pointer >= endPointer ) {
                    pointer -= 4;
                    _msc1->state = MSC1_CS_DUPES;
                    break;
                }

                // If there are 32 repetitions, we must
                // emit the duplication command.
                if ( repeats == 32 ) {
                    _msc1->state = MSC1_CS_DUPES;
                    break;
                }

                // Continue to count the repetition.
                _msc1->state = MSC1_CS_DUPE_STORE;
                break;

            // EMIT THE DUPLICATION COMMAND
            case MSC1_CS_DUPES:

                // If there is at least one repetition,
                // we can emit the relative command.
                if ( repeats > 0 ) {
                    MemoryBlock token1 = 0x80 | ( ( repeats & 0x1f ) << 2 ) | ( ( ( wpointer - actual->used + 2 ) >> 8 ) & 0x03 );
                    MemoryBlock token2 = ( ( ( wpointer - actual->used + 2 ) ) & 0xff );
                    *wpointer++ = token1;
                    *wpointer++ = token2;
                }
                if ( repeats == 32 ) {
                    repeats = 0;
                    _msc1->state = MSC1_CS_DUPE_STORE;
                } else {
                    repeats = 0;
                    actual = NULL;
                    _msc1->state = MSC1_CS_READY;
                }
                break;
            case MSC1_CS_END_OF_BLOCK:
                break;
        }

    }

    *wpointer = 0x00;
    ++wpointer;

    *_output_size = (wpointer - output);

    return output;

}

void msc1_free( MSC1Compressor * _msc1 ) {

    free( _msc1 );

}

MemoryBlock * msc1_uncompress( MSC1Compressor * _msc1, MemoryBlock * _input, int _size, int * _output_size ) {

    // We allocate (precautiously) a memory block of ten
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

    // Loop through the entire input stream.
	do {

        // Take the current token from the input stream
        // and move to the next element of the stream.
		token = *pointer;
		++pointer;

        // A token of zero (0) means "end of block".
        // Nothing must be done.
		if (token == 0) {
            // printf( "rp=%4.4x - EOB\n", (pointer - _input) );
		}

        // If the upper bit of the token is clear,
        // it means that there is a literal block
        // to emit on the output stream.
		else if ((token & 0x80) == 0x00) {

            // Take the number of literals (1...127),
            // and copy from the pointer to the output.
			int count = token & 0x7f;

            // Check if (re)allocation is needed and,
            // in that case, we reallocate the memory 
            // block with a double size.
            if ( ((wpointer-output)+count) > *_output_size ) {
                *_output_size = (*_output_size)<<1;
                int reallocOffset = wpointer - output;
                // printf( "reallocating %d bytes\n", *_output_size );
                output = realloc( output, *_output_size );
                wpointer = output + reallocOffset;
            }

            // printf( "rp=%4.4x - LITERAL %d characters\n", (pointer - _input), count );
            // printf( "   ... %4.4x %2.2x %2.2x %2.2x %2.2x > %4.4x %2.2x %2.2x %2.2x %2.2x \n", 
            //     (unsigned int)(pointer-_input), (pointer)[0], (pointer)[1], (pointer)[2], (pointer)[3],
            //     (unsigned int)(wpointer-output), (wpointer)[0], (wpointer)[1], (wpointer)[2], (wpointer)[3] );

			memcpy(wpointer, pointer, count);
			wpointer += count;
            pointer += count;

		}

        // If the most significant bit is setted,
        // we must output the repetition on the
        // output stream.
		else if ((token & 0x80) == 0x80) {

            // Take the number of repetitions.
            int repetitions = (token & 0x7f) >> 2;

            // Extract the offset.
			MemoryBlock tmp = *pointer;
			++pointer;
			int offset = tmp | ((token & 0x03) << 8);

            // If repetitions is zero then repetitions
            // will be 32 times.
			if (repetitions == 0) repetitions = 32;

            // printf( "rp=%4.4x - DUPES %d times from %4.4x\n", (unsigned int)(pointer-_input), repetitions, offset );
            // printf( "   ... %4.4x %2.2x %2.2x %2.2x %2.2x > %4.4x %2.2x %2.2x %2.2x %2.2x \n", 
            //     (unsigned int)(pointer-_input-offset), (pointer-offset)[0], (pointer-offset)[1], (pointer-offset)[2], (pointer-offset)[3],
            //     (unsigned int)(wpointer-output), (wpointer)[0], (wpointer)[1], (wpointer)[2], (wpointer)[3] );

            MemoryBlock * sourcePointer = pointer - offset;

            // Repeat the sequence from input stream
            // to the output stream.
            while( repetitions ) {
                for( int j=0; j<4; ++j ) {

                    *wpointer = *(sourcePointer+j);

                    ++wpointer;

                    // Check if (re)allocation is needed and,
                    // in that case, we reallocate the memory 
                    // block with a double size.
                    if ( (wpointer-output) > *_output_size ) {
                        *_output_size = (*_output_size)<<1;
                        int reallocOffset = wpointer - output;
                        // printf( "reallocating %d bytes\n", *_output_size );
                        output = realloc( output, *_output_size );
                        wpointer = output + reallocOffset;
                    }
                }
                --repetitions;
            }

		}
	} while (token);

    *_output_size = (wpointer - output);

	return output;
}