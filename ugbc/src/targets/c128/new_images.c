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

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

/**
 * @brief Emit code for <strong>NEW IMAGE(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _width Width of the image, in pixel
 * @param _height Heigth of the image, in pixel
 * @param _mode Mode to use
 */
/* <usermanual>
@keyword NEW ATLAS

@english

The ''NEW ATLAS'' command allows you to define a memory area where you can 
store a set of images coming from the screen (with the ''GET IMAGE'' command), or 
from another graphic resource. 

The area must be defined by (constant) number of frames, (constant) width and 
(constant) height, expressed in pixels. The actual size, 
in terms of bytes of RAM, will depend on the graphics mode selected at the time. 

If it is not possible to define an image in that screen mode, a specific error will be issued.

@italian

Il comando ''NEW ATLAS'' permette di definire un'area di memoria dove poter 
memorizzare un insieme di immagini provenienti dallo schermo (con il comando ''GET IMAGE''), 
oppure da un'altra risorsa grafica. 

L'area deve essere definita per mezzo del numero di fotogrammi (costante), 
della larghezza (costante) e dell'altezza (costante), espressa in pixel. 

La dimensione effettiva, in termini di bytes in memoria, dipenderà dalla modalità grafica 
selezionata in quel momento. Se non è possibile definire una immagine in quella modalità, 
sarà emesso uno specifico errore.

@syntax = NEW ATLAS( frames, width, height )

@example background = NEW ATLAS(16, 32,32)

@alias NEW IMAGES

</usermanual> */

/* <usermanual>
@keyword NEW IMAGES
@alias NEW ATLAS
</usermanual> */

Variable * new_images( Environment * _environment, int _frames, int _width, int _height, int _mode ) {

    Variable * result = vic2_new_images( _environment, _frames, _width, _height, _mode );

    result->offsettingFrames = offsetting_size_count( _environment, result->frameSize, _frames );
    offsetting_add_variable_reference( _environment, result->offsettingFrames, result, 0 );

    return result;

}
