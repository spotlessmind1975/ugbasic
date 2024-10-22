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

#include "../../../ugbc.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

#if defined(__c64__) || defined(__c64reu__) || defined(__c128__)

/**
 * @brief Emit code for <strong>SPRITE(...)</strong>
 * 
 * @param _environment Current calling environment
 * @param _image image to use as SPRITE
 */
 
/* <usermanual>
@keyword CSPRITE

@english

This statement allows you to define a composite sprite. Composite sprites are those 
sprites that are rendered by means of an overlay of hardware sprites. The definition 
corresponds to the transfer of graphic information from the graphic resource to the 
memory space of the machine's hardware. In practice, it is the moment in which the 
sprite is defined graphically, to be displayed.

The function accepts the ''name'' of a graphic resource, among those previously 
loaded. This must correspond to a single image: therefore it can be an image 
or a frame of an ''ATLAS'' or a ''SEQUENCE''. The system, in a completely 
automatic way, will convert the resource into graphic data compatible with the 
sprite format, decoding each color component with a separate sprite.

The command accepts a series of parameters, which can be added after the
name of the graphic resource. The ''EXPAND VERTICAL'' parameter allows you
to double the vertical dimensions, making each pixel occupy two or more 
vertical pixels. On the other hand, the ''COMPRESS VERTICAL'' command allows 
you to restore the original dimensions. The ''EXPAND HORIZONTAL'' parameter 
allows you to double the vertical dimensions, making each pixel occupy 
two or more vertical pixels. On the other hand, the ''COMPRESS HORIZONTAL'' 
command allows you to restore the original dimensions. Finally, it is possible 
to indicate one of the colors in the palette as "transparent", and therefore 
that it does not need to generate a hardware sprite. This can be useful where 
the graphic resource does not use the color black, which is the standard color 
to characterize the background. Due to the isomorphic nature of the language, 
not all flags are usable, or have an effect, on all targets that support sprites.

The function provides additional syntax, valid for redefining a sprite already 
defined. The purpose of such syntax is to modify the graphic information inherent 
to a sprite already defined previously, thus being able to dynamically replace the 
appearance of the sprite. In this case, it is necessary to provide a reference to 
the previously defined sprite (''previous''), and ensure that the graphic 
characteristics (such as the number of colors) are identical.

@italian

@syntax = CSPRITE ( name flags )
@syntax = CSPRITE ( name, previous flags )

@example spaceshift = CSPRITE( LOAD IMAGE( "spaceship.png" ) IGNORE COLOR GREEN )
@example alien = CSPRITE( LOAD IMAGE( "alien1.png" ) )
@example alien = CSPRITE( LOAD IMAGE( "alien2.png" ), alien )

@seeAlso SPRITE
@seeAlso MSPRITE

@target c64
@target c128
@target c64reu
</usermanual> */

Variable * csprite_init( Environment * _environment, char * _image, char * _sprite, int _flags ) {

    if ( _environment->deployed.msprite ) {
        CRITICAL_CANNOT_MIX_SPRITES_MSPRITES();
    }
    
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
        cpu_math_div2_const_8bit( _environment, spriteCount->realName, 4, 0 );
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

    int colorTransparency = COLOR_BLACK;

    if ( _flags & SPRITE_FLAG_TRANSPARENCY_COLOR ) {
        colorTransparency = _flags & 0x000f;
    }

    for (int i=0; i<image->originalColors; ++i ) {
        if ( image->originalPalette[i].index == colorTransparency ) continue;
        variable_move_naked( _environment, spriteCount->name, index->name );
        Variable * realImage = sprite_converter( _environment, image->originalBitmap, image->originalWidth, image->originalHeight, image->originalDepth, &image->originalPalette[i], _flags, 0, 0 );
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

    if ( _flags & SPRITE_FLAG_EXPAND_HORIZONTAL ) {
        sprite_expand_horizontal_var( _environment, result->name );
    } else {
        sprite_compress_horizontal_var( _environment, result->name );
    }

    if ( _flags & SPRITE_FLAG_EXPAND_VERTICAL) {
        sprite_expand_vertical_var( _environment, result->name );
    } else {
        sprite_compress_vertical_var( _environment, result->name );
    }

    return result;

}

#endif