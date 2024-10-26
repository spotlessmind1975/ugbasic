/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit code for <strong>(IMAGES)#[...]</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 * @param _mode Mode to use to convert data
 */
Variable * images_load_from_buffer( Environment * _environment, char * _buffer, int _buffer_size ) {

    Variable * final = variable_temporary( _environment, VT_IMAGES, 0 );

    if ( _environment->emptyProcedure ) {
        return final;
    }

    int frames = _buffer[0];

    int frame_width = 0;
    int frame_height = 0;

    IMAGE_GET_WIDTH( _buffer, 3, frame_width );
    IMAGE_GET_HEIGHT( _buffer, 3, frame_height );

    int size = image_size( _environment, frame_width, frame_height );
    
    if ( ( size * frames ) > 0xffff ) {
        CRITICAL_IMAGES_LOAD_IMAGE_BUFFER_TOO_BIG( );
    }

    final->offsettingFrames = offsetting_size_count( _environment, size, frames );
    offsetting_add_variable_reference( _environment, final->offsettingFrames, final, 0 );

    variable_store_buffer( _environment, final->name, _buffer, _buffer_size, 0 );
    final->frameWidth = frame_width;
    final->frameHeight = frame_height;
    final->frameSize = size;
    final->frameCount = frames;

    final->readonly = 1;

    return final;

}
