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

#include "../../ugbc.h"
#include "../../libs/stb_image.h"
#include "../../libs/msc1.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>(IMAGE)#[...]</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 * @param _mode Mode to use to convert data
 */
/* <usermanual>
@keyword IMAGE from buffer

@english
The ''(IMAGE)#[...]'' command allows you to load an image from a buffer.

@italian
Il comando ''(IMAGE)#[...]'' permette di caricare una immagine da un buffer.

@syntax = (IMAGE)#[hexadecimal string]

@example starship = (IMAGE)#[100010100010ff20ff20...ffff]

@target all
</usermanual> */
Variable * image_load_from_buffer( Environment * _environment, char * _buffer, int _buffer_size ) {

    // First of all, we create a variable to store the image.
    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );

    // If the LOAD IMAGE is inside an ignored procedure,
    // we must avoid to do anything.
    if ( _environment->emptyProcedure ) {
        return result;
    }

    variable_store_buffer( _environment, result->name, _buffer, _buffer_size, 0 );

    int width = 0;
    int height = 0;

    IMAGE_GET_WIDTH( _buffer, 0, width );
    IMAGE_GET_HEIGHT( _buffer, 0, height );

    // We can now store the data of the image directly into the variable.
    result->originalBitmap = NULL;
    result->originalWidth = width;
    result->originalHeight = height;
    result->originalDepth = 0;

    // Loaded images are ALWAYS readonly!
    result->readonly = 1;

    return result;

}
