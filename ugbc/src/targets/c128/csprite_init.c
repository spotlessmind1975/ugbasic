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

@target c128
</usermanual> */
Variable * csprite_init( Environment * _environment, char * _image, char * _sprite, int _flags ) {

    Variable * index;
    Variable * startIndex;
    Variable * result = variable_temporary( _environment, VT_SPRITE, "(sprite index)" );   

    Variable * spriteCount;

    if ( _sprite ) {
        outline0("; ---------------------------vvvvvvvv");
        index = variable_retrieve_or_define( _environment, _sprite, VT_SPRITE, 0 );   
        startIndex = variable_temporary( _environment, VT_SPRITE, "(sprite index)" );
        cpu_move_8bit( _environment, index->realName, startIndex->realName );
        cpu_math_and_const_8bit( _environment, startIndex->realName, 0x0f );
        spriteCount = variable_temporary( _environment, VT_SPRITE, "(sprite index)" );
        cpu_move_8bit( _environment, index->realName, spriteCount->realName );
        cpu_math_div2_8bit( _environment, spriteCount->realName, 4, 0 );
        cpu_math_and_const_8bit( _environment, spriteCount->realName, 0x0f );
        cpu_math_sub_8bit( _environment, spriteCount->realName, startIndex->realName, spriteCount->realName );
        cpu_move_8bit( _environment, startIndex->realName, index->realName );
        cpu_move_8bit( _environment, startIndex->realName, spriteCount->realName );
        outline0("; ---------------------------^^^^^^^^^^");
    } else {
        index = variable_temporary( _environment, VT_SPRITE, "(sprite index)" );   
        startIndex = variable_temporary( _environment, VT_SPRITE, "(sprite index)" );
        spriteCount = variable_retrieve( _environment, "SPRITECOUNT" );
        variable_move_naked( _environment, spriteCount->name, startIndex->name );
    }

    Variable * image = variable_retrieve( _environment, _image );

    int i = 0;

    for (i=0; i<image->originalColors; ++i ) {
        if ( image->originalPalette[i].index == COLOR_BLACK ) continue;
        variable_move_naked( _environment, spriteCount->name, index->name );
        Variable * realImage = sprite_converter( _environment, image->originalBitmap, image->originalWidth, image->originalHeight, image->originalDepth, &image->originalPalette[i], _flags );
        vic2_sprite_data_from( _environment, index->name, realImage->name );
        cpu_inc( _environment, spriteCount->realName );
        cpu_inc( _environment, index->realName );
    }

    cpu_combine_nibbles( _environment, startIndex->realName, index->realName, result->realName );

    if ( _flags & SPRITE_FLAG_MULTICOLOR) {
        sprite_multicolor_var( _environment, result->name );
    } else {
        sprite_monocolor_var( _environment, result->name );
    }

    if ( _flags & SPRITE_FLAG_EXPAND_VERTICAL) {
        sprite_expand_horizontal_var( _environment, result->name );
    } else {
        sprite_compress_horizontal_var( _environment, result->name );
    }

    if ( _flags & SPRITE_FLAG_EXPAND_HORIZONTAL) {
        sprite_expand_vertical_var( _environment, result->name );
    } else {
        sprite_compress_vertical_var( _environment, result->name );
    }

    return result;

}
