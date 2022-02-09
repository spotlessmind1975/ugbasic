/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
 * @brief Emit code for <strong>SPRITE(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _image image to use as SPRITE
 */
/* <usermanual>
@keyword SPRITE

@english
The ''SPRITE'' command allows you to define an (hardware) movable object. 
In order to be used, you must have loaded the image. 

@italian
Il comando ''SPRITE'' permette di definire un oggetto mobile (hardware). 
Per poter essere utilizzato è necessario aver caricato l'immagine da utilizzare. 

@syntax = SPRITE([image])

@example starship = SPRITE(LOAD IMAGE("starship.png"))

@usedInExample sprite_example_01.bas

@target sg1000
</usermanual> */
Variable * sprite_init( Environment * _environment, char * _image, char * _sprite ) {

    Variable * index;
    Variable * image = variable_retrieve( _environment, _image );
    Variable * spriteCount = variable_retrieve( _environment, "SPRITECOUNT" );

    if ( _sprite ) {
        index = variable_retrieve_or_define( _environment, _sprite, VT_SPRITE, 0 );
    } else {
        index = variable_temporary( _environment, VT_SPRITE, "(sprite index)" );
        variable_move_naked( _environment, spriteCount->name, index->name );
        cpu_inc( _environment, spriteCount->realName );
    }

    tms9918_sprite_data_from( _environment, index->name, image->name );

    return index;

}
