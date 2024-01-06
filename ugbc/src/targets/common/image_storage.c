/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>IMAGE ... AS ...</strong>
 * 
 * @param _environment Current calling environment
 * @param _name Name of the storage
 */
/* <usermanual>
@keyword IMAGE (storage)

@english
The ''IMAGE'' command, inserted inside a ''BEGIN STORAGE'' - ''ENDSTORAGE'' block, 
allows you to define the content of the mass storage element as an image. The basic 
syntax requires indicating the name of the ''source'' file that will be converted
and inserted into the medium. If you don't want to use the same name, you can indicate 
an alias (''AS target'').

@italian
Il comando ''IMAGE'', inserita all'interno di un blocco ''BEGIN STORAGE'' - 
''ENDSTORAGE'', permette di definire il contenuto dell'elemento di memorizzazione
di massa come "immagine". La sintassi di base prevede di indicare il nome del file 
sorgente che sarà convertito e inserito nel supporto. Se non si vuole utilizzare 
lo stesso nome, è possibile indicare un alias (''AS target'').

@syntax IMAGE source [AS target]

@example IMAGE "examples/data.png"
@example IMAGE "sprites.bmp" AS "sprites.dat"

@usedInExample storage_example_02.bas

@target all
@verified
</usermanual> */
void image_storage( Environment * _environment, char * _source_name, char * _target_name ) {

    file_storage( _environment, _source_name, _target_name );

    // No we are going to load the image from the PC.
    // Those variables will maintain the data of the original image.
    int width = 0;
    int height = 0;
    int depth = 0;

    // We must load the target dependent version of the images.
    char * lookedFilename = resource_load_asserts( _environment, _source_name );

    // If present, we can calculate the effective size.
    FILE * lookedFileHandle = fopen( lookedFilename, "rb" );
    fseek( lookedFileHandle, 0, SEEK_END );
    long fileSize = ftell( lookedFileHandle );
    fclose( lookedFileHandle );

    // Now we can decode the image using the external library.
    unsigned char* source = stbi_load(lookedFilename, &width, &height, &depth, 0);

    // If we are unable to decode the iamge, we stop the compilation.
    if ( !source ) {
        CRITICAL_IMAGE_LOAD_UNKNOWN_FORMAT( _source_name );
    }

    // Now we are able to convert the image from the original format to the
    // custom format of the target. This is a time efficient mode to store
    // the image, but not a space efficient (no compression is done).
    // Space efficiency can be applied after, if a bank is present.
    Variable * result = image_converter( _environment, source, width, height, depth, 0, 0, 0, 0, _environment->currentMode, 0 /* _transparent_color */, 0 /* flags */ );

    _environment->currentFileStorage->size = result->size;
    _environment->currentFileStorage->content = result->valueBuffer;

    variable_delete( _environment, result->name );
    
}
