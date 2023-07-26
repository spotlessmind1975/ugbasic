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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>IMAGE(... FRAME ... SEQUENCE ...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _image IMAGES/SEQUENCE variable datatype
 * @param _frame Frame to extract
 * @param _sequence Sequence to extract, NULL if IMAGES
 */
/* <usermanual>
@keyword IMAGE

@english
The ''IMAGE'' command allows you to extract an image from a collection of images 
stored in an ''IMAGES'' or ''SEQUENCE'' variable. Note that extraction occurs at compile 
time: therefore, no extra resources are allocated in the compiled program. This command 
is intended for all those commands that need an image to function, but want to exploit a
graphic resource already loaded and optimized.

@italian
Il comando ''IMAGE'' consente di estrarre un'immagine da una raccolta di immagini 
memorizzate in una variabile ''IMAGES'' o ''SEQUENCE''. Si noti che l'estrazione 
avviene al momento della compilazione: pertanto, non viene allocata alcuna risorsa 
suppletiva nel programma compilato. Questo comando è inteso per tutti quei comandi 
che hanno bisogno di una immagine per poter funzionare, ma si vuole sfruttare una 
risorsa grafica già caricata e ottimizzata.

@syntax = IMAGE( [images] FRAME [x] )
@syntax = IMAGE( [sequence] SEQUENCE [x] FRAME [y] )

@example starship = IMAGE( LOAD IMAGES(("tiles.png") FRAME 1 )
@example starship = IMAGE( LOAD SEQUENCE(("tiles.png") SEQUENCE 1 FRAME 2 )

@target all
</usermanual> */
Variable * image_extract( Environment * _environment, char * _images, int _frame, int * _sequence ) {

    Variable * result = variable_temporary( _environment, VT_IMAGE, 0 );

    Variable * images = variable_retrieve( _environment, _images );

    if ( images->type != VT_IMAGES && images->type != VT_SEQUENCE ) {
        CRITICAL_IMAGE_EXTRACT_ON_NOT_IMAGES( _images );
    }

    int framesPerRow = images->originalWidth / images->frameWidth;
    int frame = _frame;
    int sequence = ( _sequence ) ? *_sequence : 0;
    char * destination = malloc( images->frameWidth * images->frameHeight * images->originalDepth );
    char * target = NULL;

    // printf( "framesPerRow = %d / %d = %d\n", images->originalWidth, images->frameWidth, framesPerRow );

    switch( images->type ) {
        case VT_IMAGES:
            target = image_extract_subimage( _environment, images->originalBitmap, images->originalWidth, images->originalHeight, images->frameWidth, images->frameHeight, frame % framesPerRow, frame / framesPerRow, images->originalDepth );
            break;
        case VT_SEQUENCE:
            target = image_extract_subimage( _environment, images->originalBitmap, images->originalWidth, images->originalHeight, images->frameWidth, images->frameHeight, frame, sequence, images->originalDepth );
            break;
    }

    // printf( "Before image extract = %d colors\n", images->originalColors );

    result->originalBitmap = target;
    result->originalWidth = images->frameWidth;
    result->originalHeight = images->frameHeight;
    result->originalDepth = images->originalDepth;
    result->originalColors = palette_extract( _environment, result->originalBitmap, result->originalWidth, result->originalHeight, result->originalDepth, 0 /* flags */, result->originalPalette );

    // printf( "After image extract = %d colors\n", result->originalColors );

    return result;

}
