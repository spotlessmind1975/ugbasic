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
@keyword MSPRITE (function)

@english

This statement allows you to define a multiplexed sprite. These objects are 
managed entirely by ugBASIC, and using ''SPRITE'' as usual. A multiplexed 
sprite is a composition of composite sprite where each element of the 
composition is done by using a virtual sprite that, in turns, use a 
real (hardware) sprite.

sprites where images are cropped, the size of a multiplexed sprite is taken 
directly from the image data, and it is rounded to the underlying hardware 
size (so a 32x32 monochromatic image as above will be converted into 4 
hardware sprites of 24x21 pixels). So, if the hardware sprites cannot 
be resized, a part of the area inside these sprites is wasted, and 
that you need more than one sprite to represent a large image.

The maximum of eight hardware sprites therefore imposes a strict limit
to the number of such objects you can display on a horizontal line. 
The total width of the objects must not exceed:
24*8=192 pixels (for monochrome sprites)
16*4=96 pixels (for two colors sprites)
16*2=48 pixels (for four colors sprites)
16*1=24 pixels (for eight colors sprites)

If you try to ignore this limitation, you won't get an error message, 
but your multiplexed sprite will not be displayed on the screen. So 
it's vital to ensure that the above restriction is respected.

The function accepts the ''name'' of a graphic resource, among those previously 
loaded. This must correspond to a single image: therefore it can be an image 
or a frame of an ''ATLAS'' or a ''SEQUENCE''. The system, in a completely 
automatic way, will convert the resource into graphic data compatible with the 
sprite format.

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

@syntax = MSPRITE ( name flags )
@syntax = MSPRITE ( name, previous flags )

@example spaceshift = MSPRITE( LOAD IMAGE( "spaceship.png" ) IGNORE COLOR GREEN )
@example alien = MSPRITE( LOAD IMAGE( "alien1.png" ) )
@example alien = MSPRITE( LOAD IMAGE( "alien2.png" ), alien )

@seeAlso CSPRITE
@seeAlso SPRITE

@target c64
@target c128
@target c64reu
</usermanual> */

Variable * msprite_init( Environment * _environment, char * _image, char * _sprite, int _flags ) {

    if ( _environment->deployed.sprite ) {
        CRITICAL_CANNOT_MIX_SPRITES_MSPRITES();
    }

    Variable * index;
    Variable * startIndex;
    Variable * spriteCount;
    Variable * result = variable_temporary( _environment, VT_MSPRITE, "(sprite index)" );   

    index = variable_temporary( _environment, VT_MSPRITE, "(sprite index)" );   
    spriteCount = variable_retrieve( _environment, "SPRITECOUNT" );
    startIndex = variable_temporary( _environment, VT_MSPRITE, "(sprite index)" );

    if ( _sprite ) {
        Variable * original = variable_retrieve_or_define( _environment, _sprite, VT_MSPRITE, 0 );   
        cpu_move_8bit( _environment, original->realName, startIndex->realName );
        cpu_move_8bit( _environment, original->realName, result->realName );
    } else {
        cpu_move_8bit( _environment, spriteCount->realName, startIndex->realName );
        cpu_move_8bit( _environment, spriteCount->realName, result->realName );
    }

    Variable * image = variable_retrieve( _environment, _image );

    //                   +---+------------- width in sprites (00 = 1, 01 = 2, 10 = 3, 11 = 4)
    //                   |   |   +---+----- height in sprites (00 = 1, 01 = 2, 10 = 3, 11 = 4)
    //                   |   |   |   |
    // +---+---+---+---+---+---+---+---+ +---+---+---+---+---+---+---+---+
    // | M | c | c | c | x | x | y | y | | n | n | n | n | n | n | n | n |
    // +---+---+---+---+---+---+---+---+ +---+---+---+---+---+---+---+---+
    // +-+---+---+---------------------+ +-------------------------------+
    //   |   |   |   | (VT_MSPRITE+1)                    (VT_MSPRITE+0)
    //   |   |   |   |
    //   |   +---+---+-- number of colors
    //   +-------------- multicolor (0 = no / 1 = yes) [UNUSED]

    int y_slots = 1 + ( (image->originalHeight-1) / 21 );
    int x_slots = 0;
    // if ( _flags & SPRITE_FLAG_MULTICOLOR) {
    //     x_slots = ( (image->originalWidth-1) / 12 ) + 1;
    // } else {
        x_slots = ( (image->originalWidth-1) / 24 ) + 1;
    // }

    int colorTransparency = COLOR_BLACK;

    if ( _flags & SPRITE_FLAG_TRANSPARENCY_COLOR ) {
        colorTransparency = _flags & 0x000f;
    }

    int c_slots = 0;
    for (int i=0; i<image->originalColors; ++i ) {
        if ( image->originalPalette[i].index == colorTransparency ) continue;
        ++c_slots;
        for (int y=0; y<y_slots; ++y ) {
            for (int x=0; x<x_slots; ++x ) {
                
                cpu_move_8bit( _environment, startIndex->realName, index->realName );
                Variable * realImage = sprite_converter( _environment, image->originalBitmap, image->originalWidth, image->originalHeight, image->originalDepth, &image->originalPalette[i], _flags, x, y );
                vic2_sprite_data_from( _environment, index->name, realImage->name );

                // if ( _flags & SPRITE_FLAG_MULTICOLOR) {
                //     sprite_multicolor_var( _environment, index->name );
                //     outline1("LDA %s", address_displacement( _environment, index->realName, "1" ) );
                //     outline0("ORA #%10000000" )
                //     outline1("STA %s", address_displacement( _environment, index->realName, "1" ) );
                // } else {
                    // sprite_monocolor_var( _environment, index->name );
                //     outline1("LDA %s", address_displacement( _environment, index->realName, "1" ) );
                //     outline0("AND #%01111111" )
                //     outline1("STA %s", address_displacement( _environment, index->realName, "1" ) );
                // }

                // if ( _flags & SPRITE_FLAG_EXPAND_HORIZONTAL ) {
                //     sprite_expand_horizontal_var( _environment, index->name );
                // } else {
                //     sprite_compress_horizontal_var( _environment, index->name );
                // }

                // if ( _flags & SPRITE_FLAG_EXPAND_VERTICAL ) {
                //     sprite_expand_vertical_var( _environment, index->name );
                // } else {
                //     sprite_expand_vertical_var( _environment, index->name );
                // }

                if ( ! _sprite ) {
                    cpu_inc( _environment, spriteCount->realName );
                }
                cpu_inc( _environment, startIndex->realName );
                cpu_inc( _environment, index->realName );
            }
        }
    }

    //                   +---+------------- width in sprites (00 = 1, 01 = 2, 10 = 3, 11 = 4)
    //                   |   |   +---+----- height in sprites (00 = 1, 01 = 2, 10 = 3, 11 = 4)
    //                   |   |   |   |
    // +---+---+---+---+---+---+---+---+ +---+---+---+---+---+---+---+---+
    // | M | c | c | c | x | x | y | y | | n | n | n | n | n | n | n | n |
    // +---+---+---+---+---+---+---+---+ +---+---+---+---+---+---+---+---+
    // +-+---+---+---------------------+ +-------------------------------+
    //   |   |   |   | (VT_MSPRITE+1)                    (VT_MSPRITE+0)
    //   |   |   |   |
    //   |   +---+---+-- number of colors
    //   +-------------- multicolor (0 = no / 1 = yes) [unused]

    outline1("LDA #$%2.2x", ( (y_slots-1) & 0x03 ) | ( ( (x_slots-1) & 0x03 ) << 2 ) | ( ( (c_slots-1) & 0x07 ) << 4 ) | ( ( _flags & SPRITE_FLAG_MULTICOLOR ) ? 0x80 : 0x00) );
    outline1("STA %s", address_displacement( _environment, result->realName, "1" ) );

    return result;

}

#endif