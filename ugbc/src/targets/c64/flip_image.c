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

extern char DATATYPE_AS_STRING[][16];

/**
 * @brief Emit ASM code for <b>FLIP IMAGE X/Y/XY/YX [image]</b>
 * 
 * This function outputs a code that flip an image
 * 
 * @param _environment Current calling environment
 * @param _image Image to draw
 */
 /* <usermanual>
@keyword FLIP IMAGE

@english
This command allows you to flip an image on the same image,
along the X axis or the Y axis.
The programmer can flip a single image (''IMAGE''), a 
frame of a series of images (''IMAGES'') or a frame of a pose of a 
sequence of images (''SEQUENCES''). In all cases the syntax changes 
slightly.

It is possible to flip an image either programmatically, directly indicating
the ''X'' or ''Y'' direction, or by delegating these operations to the 
value of a variable. In this case, this value will be preceded by the 
''DIRECTION'' keyword. Acceptable values are ''1'' for the horizontal 
direction, ''2'' for the vertical direction, ''3'' for both directions.

@italian
Questa capovolge una immagine.
Il programmatore può capovolgere una singola immagine 
(''IMAGE''), un frame di una serie di immagini (''IMAGES'') oppure 
un frame di una posa di una sequenza di immagini (''SEQUENCES''). 
In tutti i casi la sintassi cambia leggermente.

E' possibile capovolgere una immagine sia in modo programmatico, indicando
direttamente la direzione ''X'' oppure ''Y'', oppure delegando tale operazioni al
valore di una variabile. In tal caso, tale valore andrà previsso dalla
parola chiave ''DIRECTION''.

I valori accettabili sono ''1'' per la direzione orizzontale, ''2'' per
quella verticale, ''3'' per entrambe le direzioni.

@syntax FLIP IMAGE resource [X|Y|XY|YX]
@syntax FLIP IMAGE resource FRAME frame [X|Y|XY|YX]
@syntax FLIP IMAGE resource SEQUENCE sequence FRAME frame [X|Y|XY|YX]
@syntax FLIP [X|Y|XY|YX] IMAGE resource
@syntax FLIP [X|Y|XY|YX] IMAGE resource FRAME frame
@syntax FLIP [X|Y|XY|YX] IMAGE resource SEQUENCE sequence FRAME frame
@syntax FLIP IMAGE resource DIRECTION direction
@syntax FLIP IMAGE resource FRAME frame DIRECTION direction
@syntax FLIP IMAGE resource SEQUENCE sequence FRAME frame DIRECTION direction
@syntax FLIP DIRECTION direction IMAGE resource
@syntax FLIP DIRECTION direction IMAGE resource FRAME frame
@syntax FLIP DIRECTION direction IMAGE resource SEQUENCE sequence FRAME frame

@example FLIP X IMAGE object

@target c64
</usermanual> */
void flip_image_vars( Environment * _environment, char * _image, char * _frame, char * _sequence, char * _direction ) {

    if ( _environment->emptyProcedure ) {
        return;
    }

    Variable * image = variable_retrieve( _environment, _image );

    if ( image->bankAssigned != -1 ) {
        CRITICAL_CANNOT_FLIP_BANKED_IMAGE( _image );
    }
    
    Resource * resource = build_resource_for_sequence( _environment, _image, _frame, _sequence );

    Variable * frame = NULL;
    if ( _frame) {
        frame = variable_retrieve_or_define( _environment, _frame, VT_BYTE, 0 );
    }
    Variable * sequence = NULL;
    if ( _sequence) {
        sequence = variable_retrieve_or_define( _environment, _sequence, VT_BYTE, 0 );
    }

    switch( resource->type ) {
        case VT_SEQUENCE:
            if ( !sequence ) {
                if ( !frame ) {
                    vic2_flip_image( _environment, resource, "", "", image->frameSize, image->frameCount, _direction );
                } else {
                    vic2_flip_image( _environment, resource, "", frame->realName, image->frameSize, image->frameCount, _direction );
                }
            } else {
                if ( !frame ) {
                    vic2_flip_image( _environment, resource, "", sequence->realName, image->frameSize, image->frameCount, _direction );
                } else {
                    vic2_flip_image( _environment, resource, frame->realName, sequence->realName, image->frameSize, image->frameCount, _direction );
                }
            }
            break;
        case VT_IMAGES:
            if ( !frame ) {
                vic2_flip_image( _environment, resource, "", NULL, image->frameSize, 0, _direction );
            } else {
                vic2_flip_image( _environment, resource, frame->realName, NULL, image->frameSize, 0, _direction );
            }
            break;
        case VT_IMAGE:
        case VT_TARRAY:
            vic2_flip_image( _environment, resource, NULL, NULL, 0, 0, _direction );
            break;
        default:
            CRITICAL_FLIP_IMAGE_UNSUPPORTED( _image, DATATYPE_AS_STRING[image->type] );
    }

    
}
