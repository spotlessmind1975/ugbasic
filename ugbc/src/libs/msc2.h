#ifndef __MSC2__
#define __MSC2__

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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

/****************************************************************************
 * DECLARATIONS AND DEFINITIONS SECTION 
 ****************************************************************************/

typedef unsigned char MemoryBlock;

typedef enum _MSC2CompressorState {

    MSC2_CS_START        = 0,
    MSC2_CS_INCREMENT1   = 1,
    MSC2_CS_INCREMENT2   = 2,
    MSC2_CS_EMIT_COUNT   = 3,
    MSC2_CS_EMIT_TARGET1 = 4,
    MSC2_CS_EMIT_TARGET2 = 5,
    MSC2_CS_EMIT_FF1     = 6,
    MSC2_CS_EMIT_FF2     = 7,

    MSC2_US_START        = 8,
    MSC2_US_SKIP         = 9,
    MSC2_US_EMIT         = 10

} MSC2CompressorState;

typedef struct _MSC2Compressor {

    MSC2CompressorState     state;

    MemoryBlock *           origin;
    int                     origin_size;

} MSC2Compressor;

MSC2Compressor *    msc2_create( MemoryBlock * _origin, int _origin_size );
MemoryBlock *       msc2_compress( MSC2Compressor * _msc2, MemoryBlock * _target, int * _output_size );
MemoryBlock *       msc2_uncompress( MSC2Compressor * _msc2, MemoryBlock * _output, int _output_size );
void                msc2_free( MSC2Compressor * _msc2 );

#endif