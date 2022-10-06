#ifndef __MSC1__
#define __MSC1__

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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

/****************************************************************************
 * DECLARATIONS AND DEFINITIONS SECTION 
 ****************************************************************************/

typedef enum _MSC1CompressorState {

    /** Ready to compress */
    MSC1_CS_READY = 0,

    /** Store literal */
    MSC1_CS_STORE = 1,

    /** Move 1 forward */
    MSC1_CS_MOVE1 = 2,

    /** Emit literal */
    MSC1_CS_LITERAL = 3,

    /** Emit literal dupe */
    MSC1_CS_LITERAL_DUPE = 4,

    /** Move forward by 4 */
    MSC1_CS_MOVE4 = 5,

    /** Store dupe */
    MSC1_CS_DUPE_STORE = 6,

    /** Move forward by 4 */
    MSC1_CS_DUPE_MOVE4 = 7,

    /** Emit dupes */
    MSC1_CS_DUPES = 8,

    /** End of block */
    MSC1_CS_END_OF_BLOCK = 9

} MSC1CompressorState;

typedef struct _MSC1Compressor {

    MSC1CompressorState     state;

    int                     maximumRepeatedSequences;

} MSC1Compressor;

typedef unsigned char MemoryBlock;

MSC1Compressor *    msc1_create( int _maximum_repeated_sequences );
MemoryBlock *       msc1_compress( MSC1Compressor * _msc1, MemoryBlock * _input, int _size, int * _output_size );
MemoryBlock *       msc1_uncompress( MSC1Compressor * _msc1, MemoryBlock * _input, int _size, int * _output_size );
void                msc1_free( MSC1Compressor * _msc1 );

#endif