/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
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
#include "../../libs/stb_image.h"
#include "../../libs/msc1.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>LOAD IMAGE(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 * @param _mode Mode to use to convert data
 */

/* <usermanual>
@keyword LOAD MOVIE

@english

@italian

@syntax = LOAD MOVIE( filename[, filename[, filename]]) [bk]
@syntax     bk : [UNBANKED | BANKED | BANKED(number)]

@example starship = LOAD MOVIE("starship00.png","starship01.png","starship02.png")
@example alien = LOAD MOVIE("alien.mp4")

@alias LOAD MOVIE
@alias MOVIE LOAD

@target all
</usermanual> */

/* <usermanual>
@keyword MOVIE LOAD
@alias LOAD MOVIE
@target all
</usermanual> */

Variable * movie_load( Environment * _environment, ParamsMovieLoad _params ) {

    Variable * final = variable_temporary( _environment, VT_MOVIE, 0 );

    if ( _environment->emptyProcedure ) {
        return final;
    }

    if ( _environment->tenLinerRulesEnforced ) {
        CRITICAL_10_LINE_RULES_ENFORCED( "LOAD MOVIE");
    }

    if ( _environment->sandbox ) {
        CRITICAL_SANDBOX_ENFORCED( "LOAD MOVIE");
    }

    int bufferSize = 0;
    Variable * firstImage = NULL;
    Variable * lastImage = NULL;

    Variable * partial;
    for(int i=0; i<_params.filenamesCount; ++i ) {

        ImageDescriptor * imageDescriptor = image_descriptor_create( _environment, _params.filenames[i], 0 /*_flags*/ );

        // Now we are able to convert the image from the original format to the
        // custom format of the target. This is a time efficient mode to store
        // the image, but not a space efficient (no compression is done).
        // Space efficiency can be applied after, if a bank is present.
        partial = image_converter( _environment, imageDescriptor->data, imageDescriptor->width, imageDescriptor->height, imageDescriptor->depth, 0, 0, 0, 0, _params.mode, 0, 0 );

        if ( !firstImage && !lastImage ) {
            firstImage = partial;
            lastImage = firstImage;
        } else {
            lastImage->next = partial;
            lastImage = lastImage->next;
        }
        bufferSize += partial->size;
    }

    bufferSize += 3;

    adiline1("LIS2:%x", bufferSize );

    char * buffer = malloc( bufferSize );
    char * ptr = buffer;
    ptr[0] = _params.filenamesCount;
    ptr[1] = ( partial->originalWidth & 0xff );
    ptr[2] = ( partial->originalHeight >> 8 ) & 0xff;

    ptr += 3;
    lastImage = firstImage;
    for(int i=0; i<_params.filenamesCount; ++i ) {
        memcpy( ptr, lastImage->valueBuffer, lastImage->size );
        ptr += lastImage->size;
        lastImage = lastImage->next;
    }

    variable_store_buffer( _environment, final->name, buffer, bufferSize, 0 );

    lastImage = firstImage;
    for(int i=0; i<_params.filenamesCount; ++i ) {
        variable_temporary_remove( _environment, lastImage->name );
        lastImage = lastImage->next;
    }

    _environment->disableMemoryAreas = 0;
    
    if ( _params.bank_expansion && _environment->expansionBanks ) {

        if ( ! banks_store( _environment, final, _params.bank_expansion ) ) {
            CRITICAL_EXPANSION_OUT_OF_MEMORY_LOADING( _params.filenames[0] );
        }

    }

    final->readonly = 1;

    return final;

}
