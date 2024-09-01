#ifndef __RLE__
#define __RLE__

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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

/****************************************************************************
 * DECLARATIONS AND DEFINITIONS SECTION 
 ****************************************************************************/

typedef enum _RLECompressorState {

    /** Ready to compress */
    RLE_CS_READY = 0,

    /** Counting characters */
    RLE_CS_COUNTING = 1,

    /** Emit single / duplicate */
    RLE_CS_EMIT = 2,

    /** Emit single / duplicate and continue counting */
    RLE_CS_EMIT_CONTINUE = 3,

    /** End of compression */
    RLE_CS_END_OF_BLOCK = 4

} RLECompressorState;

typedef struct _RLECompressor {

    RLECompressorState     state;

} RLECompressor;

typedef unsigned char MemoryBlock;

RLECompressor *     rle_create( );
MemoryBlock *       rle_compress( RLECompressor * _rle, MemoryBlock * _input, int _size, int * _output_size );
MemoryBlock *       rle_uncompress( RLECompressor * _rle, MemoryBlock * _input, int _size, int * _output_size );
void                rle_free( RLECompressor * _rle );

#endif