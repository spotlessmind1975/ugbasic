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
 * @brief Emit ASM code for <b>PUT IMAGE [image] AT [int],[int]</b>
 * 
 * This function outputs a code that draws an image on a bitmap. 
 * 
 * @param _environment Current calling environment
 * @param _image Image to draw
 * @param _x Abscissa of the point to draw
 * @param _y Ordinate of the point
 */
void put_image( Environment * _environment, char * _image, char * _x1, char * _y1, char * _x2, char * _y2, char * _frame, char * _sequence, int _flags ) {

    // If flag transparency is requested, we save the actual background into the
    // TRANSPARENCYSTAGEAREA image.
    if ( ( _flags & FLAG_TRANSPARENCY ) && variable_exists( _environment, "TRANSPARENCYSTAGEAREA" ) ) {
        Variable * image = variable_retrieve( _environment, _image );
        if ( _environment->transparencyMemorySize < image->size ) {
            _environment->transparencyMemorySize = image->size;
        }
        Variable * transparencyStageArea = variable_retrieve( _environment, "TRANSPARENCYSTAGEAREA" );
        transparencyStageArea->valueBuffer = malloc(1);
        transparencyStageArea->assigned = 1;
        transparencyStageArea->temporary = 1;
        switch( image->type ) {
            case VT_IMAGE:
                cpu_mem_move_direct_size( _environment, image->realName, "TRANSPARENCYSTAGEAREA", 3 );
                break;
            case VT_IMAGES:
            case VT_SEQUENCE:
                cpu_mem_move_direct_size( _environment, address_displacement( _environment, image->realName, "3" ), "TRANSPARENCYSTAGEAREA", 3 );
                break;
        }
        get_image( _environment, "TRANSPARENCYSTAGEAREA", _x1, _y1, _x2, _y2, NULL, NULL, 0 );
    }

    // Next, we ask to draw with the transparency. Currently, if TRANSPARENCYSTAGEAREA
    // is used, the drawing will occur on the TRANSPARENCYSTAGEAREA area and not
    // on the screen.
    Variable * flags = variable_temporary( _environment, VT_WORD, "(flags)" );
    variable_store( _environment, flags->name, _flags );
    put_image_vars( _environment, _image, _x1, _y1, _x2, _y2, _frame, _sequence, flags->name );

    // Finally, we update effectively the screen, but not using PALETTE (that has been
    // already updated by the previous PUT IMAGE) and the transparency (since it has
    // been already done off-screen).
    if ( ( _flags & FLAG_TRANSPARENCY ) && variable_exists( _environment, "TRANSPARENCYSTAGEAREA" ) ) {
        variable_store( _environment, flags->name, ( _flags & ~FLAG_TRANSPARENCY ) & ~FLAG_WITH_PALETTE );
        put_image_vars( _environment, "TRANSPARENCYSTAGEAREA", _x1, _y1, _x2, _y2, NULL, NULL, flags->name );
    }
}

