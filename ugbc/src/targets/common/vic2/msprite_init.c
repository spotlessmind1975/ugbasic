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
@keyword MSPRITE

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