/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit ASM code for <b>GET IMAGE [image] AT [int],[int]</b>
 * 
 * This function outputs a code that save an image from a bitmap. 
 * 
 * @param _environment Current calling environment
 * @param _image Image to draw
 * @param _x Abscissa of the point to draw
 * @param _y Ordinate of the point
 */
/* <usermanual>
@keyword GET IMAGE

@english

The purpose of the ''GET IMAGE'' command is to store the contents of the screen 
in a variable. The first syntax is where the programmer provides the coordinates 
of the rectangle to be stored. This syntax will store only the bitmap of the
image. You need to give the ''G'' option if you want to store color component,
too.

The second, instead, only requires the point from which to start storing the image,
whose dimensions are implicitly obtained from the variable. The color component
is acquired implictly. The ''GET IMAGE'' syntax is the only one that supports 
''ATLAS'' and ''SEQUENCE'' version, so you can acquire a single frame from the screen.

@italian

Lo scopo del comando ''GET IMAGE'' è di memorizzare il contenuto dello schermo in una 
variabile. La prima sintassi è quella in cui il programmatore fornisce le coordinate 
del rettangolo da memorizzare. Questa sintassi memorizzerà solo la bitmap dell'immagine. 
Devi dare l'opzione ''G'' se vuoi memorizzare anche la componente colore.

La seconda, invece, richiede solo il punto da cui iniziare a memorizzare l'immagine, 
le cui dimensioni sono ricavate implicitamente dalla variabile. La componente colore 
è acquisita implicitamente. La sintassi ''GET IMAGE'' è l'unica che supporta la 
versione ''ATLAS'' e ''SEQUENCE'', quindi puoi acquisire un singolo fotogramma 
dallo schermo.

@syntax GET IMAGE var FROM [x], [y]
@syntax GET (x1,y1) - (x2,y2), var[, G]

@example background = NEW IMAGE(16, 16)
@example GET IMAGE background FROM 0, 0

@seeAlso GET BITMAP

</usermanual> */
/* <usermanual>
@keyword GET BITMAP

@english

The purpose of the ''GET BITMAP'' command is to store the contents of the screen 
in a variable, just the bitmap component so without color component. The syntax 
requires the point from which to start storing the image, whose dimensions are 
implicitly obtained from the variable. This command ssupports ''ATLAS'' and 
''SEQUENCE'' version, so you can acquire a single frame from the screen.

@italian

Lo scopo del comando ''GET BITMAP'' è di memorizzare il contenuto dello schermo
in una variabile, solo la componente bitmap quindi senza componente colore. La sintassi
richiede il punto da cui iniziare a memorizzare l'immagine, le cui dimensioni sono
implicitamente ottenute dalla variabile. Questo comando supporta la versione ''ATLAS'' e
''SEQUENCE'', quindi è possibile acquisire un singolo fotogramma dallo schermo.

@syntax GET BITMAP var FROM [x], [y]

@example background = NEW IMAGE(16, 16)
@example GET BITMAP background FROM 0, 0

@seeAlso GET IMAGE

</usermanual> */
void get_image( Environment * _environment, char * _image, char * _x1, char * _y1, char * _x2, char * _y2, char * _frame, char * _sequence, int _palette ) {

    Variable * image = variable_retrieve( _environment, _image );
    Variable * x1 = variable_retrieve_or_define( _environment, _x1, VT_POSITION, 0 );
    Variable * y1 = variable_retrieve_or_define( _environment, _y1, VT_POSITION, 0 );

    if ( _x2 && _y2 ) {
        get_image_overwrite_size( _environment, _image, _x1, _y1, _x2, _y2 );
    }

    Variable * frame = NULL;
    if ( _frame) {
        frame = variable_retrieve_or_define( _environment, _frame, VT_BYTE, 0 );
    }
    Variable * sequence = NULL;
    if ( _sequence) {
        sequence = variable_retrieve_or_define( _environment, _sequence, VT_BYTE, 0 );
    }

    switch( image->type ) {
        case VT_SEQUENCE:
            if ( !sequence ) {
                if ( !frame ) {
                    tms9918_get_image( _environment, image->realName, x1->realName, y1->realName, "", "", image->frameSize, image->frameCount, _palette );
                } else {
                    tms9918_get_image( _environment, image->realName, x1->realName, y1->realName, frame->realName, "", image->frameSize, image->frameCount, _palette );
                }
            } else {
                if ( !frame ) {
                    tms9918_get_image( _environment, image->realName, x1->realName, y1->realName, "", sequence->realName, image->frameSize, image->frameCount, _palette );
                } else {
                    tms9918_get_image( _environment, image->realName, x1->realName, y1->realName, frame->realName, sequence->realName, image->frameSize, image->frameCount, _palette );
                }
            }
            break;
        case VT_IMAGES:
            if ( !frame ) {
                tms9918_get_image( _environment, image->realName, x1->realName, y1->realName, "", NULL, image->frameSize, 0, _palette );
            } else {
                tms9918_get_image( _environment, image->realName, x1->realName, y1->realName, frame->realName, NULL, image->frameSize, 0, _palette );
            }
            break;
        case VT_IMAGE:
        case VT_TARRAY:
            tms9918_get_image( _environment, image->realName, x1->realName, y1->realName, NULL, NULL, 0, 0, _palette );
            break;
        default:
            CRITICAL_PUT_IMAGE_UNSUPPORTED( _image, DATATYPE_AS_STRING[image->type] );
    }

}
