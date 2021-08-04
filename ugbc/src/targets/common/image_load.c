/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
#define STB_IMAGE_IMPLEMENTATION
#include "../../stb_image.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>IMAGE LOAD(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _filename Filename to read into buffer
 * @param _mode Mode to use to convert data
 */
/* <usermanual>
@keyword IMAGE LOAD

@english
The ''IMAGE LOAD'' command allows you to load an image and to convert it into
a BUFFER. The second parameter is the mode to use to convert
the given data (by default, it is equal to current mode)

@italian
Il comando ''IMAGE LOAD'' permette di caricare un file immagine, e di convertirlo
in un BUFFER. Il secondo parametro è la modalità grafica da usare
per convertire il dato (per default, è il modo corrente).

@syntax = IMAGE LOAD([filename]{,[mode]})

@example starship = IMAGE LOAD("starship.png")
@example alienAt11 = IMAGE LOAD("alien.jpg",11)

@usedInExample image_loading_01.bas

@target all
</usermanual> */
Variable * image_load( Environment * _environment, char * _filename, int _mode ) {

    int width = 0;
    int height = 0;
    int depth = 3;

    FILE * file = fopen( _filename, "rb" );

    if ( !file ) {
        CRITICAL_IMAGE_LOAD_MISSING_FILE( _filename );
    }
    
    fclose( file );

    unsigned char* source = stbi_load(_filename, &width, &height, &depth, 0);

    if ( !source ) {
        CRITICAL_IMAGE_LOAD_UNKNOWN_FORMAT( _filename );
    }

    Variable * result = image_converter( _environment, source, width, height, _mode );

    stbi_image_free(source);

    return result;

}
