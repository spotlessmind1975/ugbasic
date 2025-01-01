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
@keyword SPRITE (function)

@english

This function can be used to define a hardware sprite. The first parameter must 
be a monochrome graphics resource, while the second parameter (optional) can be 
the identifier of an already defined sprite. If the second parameter is omitted, 
the sprite will be created using a new identifier.

A sprite declaration can be followed by one or more optional flags that serve 
to better describe the desired characteristics of the sprite.

With the ''MULTICOLOR'' flag you can indicate that the sprite is defined by more 
than one color. Depending on the video chipset considered, this can mean up to 
4 colors instead of the single color. The opposite is given by the ''MONOCOLOR'' 
flag, which defines a monochrome sprite.

The ''EXPAND VERTICAL'' flag allows you to increase the height of the sprite 
and, depending on the video chipset considered, each pixel of the sprite will 
be drawn with more pixels on the screen. The opposite is obtained with the 
''COMPRESS VERTICAL'' flag.

The ''EXPAND HORIZONTAL'' flag allows you to increase the width of the 
sprite and, depending on the video chipset considered, each pixel of the 
sprite will be drawn with more pixels on the screen. The opposite is 
obtained with the ''COMPRESS HORIZONTAL'' flag.

The last flag is ''IGNORE COLOR'', which allows you to indicate the color to be
considered as transparency (that is: ignored).

Please note that defining a sprite allows you to change its appearance 
dynamically, and therefore allows you to perform (for example) animations. 
This redefinition should be understood as synchronous, and therefore the 
program should be written to ensure the appropriate timing, in order to 
avoid flickering.

@italian

Questa funzione può essere usata per definire uno sprite hardware. Il primo 
parametro deve essere una risorsa grafica monocromatica, mentre il secondo 
parametro (opzionale) può essere l'identificativo di uno sprite già definito. 
Se il secondo parametro viene omesso, lo sprite sarà creato utilizzando un nuovo
identificativo.

La dichiarazione di uno sprite può essere seguita da uno o più flag, opzionali, 
che servono a descrivere meglio le caratteristiche desiderate dello sprite.

Con il flag ''MULTICOLOR'' si può indicare che lo sprite è definito da più di 
un colore. A seconda del chipset video considerato, questo può significare 
fino a 4 colori invece che il singolo colore. Il contrario è dato dal flag 
''MONOCOLOR'', che definisce uno sprite monocromatico. 

Il flag ''EXPAND VERTICAL'' permette di incrementare l'altezza dello sprite 
e, a seconda del chipset video considerato, ogni pixel dello sprite sarà 
disegnato con più pixel sullo schermo. Il contrario lo si ottiene con il 
flag ''COMPRESS VERTICAL''.

Il flag ''EXPAND HORIZONTAL'' permette di incrementare la larghezza dello 
sprite e, a seconda del chipset video considerato, ogni pixel dello sprite 
sarà disegnato con più pixel sullo schermo. Il contrario lo si ottiene con 
il flag ''COMPRESS HORIZONTAL''.

L'ultimo flag è ''IGNORE COLOR'', che consente di indicare il colore da 
considerare come trasparenza (cioè: ignorato).

Si fa presente che la definizione di uno sprite consente di cambiare il suo 
aspetto dinamicamente, e quindi permette di effettuare (ad esempio) animazioni. 
Tale ridefinizione va intesa come sincrona, e quindi il programma dovrebbe 
essere scritto per garantire le opportune temporizzazioni, al fine di 
evitare flickering.

@syntax = SPRITE( resource ) flags
@syntax = SPRITE( resource, old ) flags

@example ship = SPRITE( imageShip ) IGNORE BLACK

@seeAlso SPRITE

@target c64
@target c64reu
@target c128
@target msx1
@target coleco
@target sc3000
@target sg1000
</usermanual> */
Variable * sprite_init( Environment * _environment, char * _image, char * _sprite, int _flags ) {

    if ( _environment->deployed.msprite ) {
        CRITICAL_CANNOT_MIX_SPRITES_MSPRITES();
    }

    Variable * index;

    if ( _sprite ) {

        index = variable_retrieve_or_define( _environment, _sprite, VT_SPRITE, 0 );

    } else {

        Variable * spriteCount = variable_retrieve( _environment, "SPRITECOUNT" );
        index = variable_temporary( _environment, VT_SPRITE, "(sprite index)" );
        variable_move_naked( _environment, spriteCount->name, index->name );
        cpu_inc( _environment, spriteCount->realName );

    }

    Variable * image = variable_retrieve( _environment, _image );

    Variable * realImage = sprite_converter( _environment, image->originalBitmap, image->originalWidth, image->originalHeight, image->originalDepth, NULL, _flags, 0, 0 );

    if ( _flags & SPRITE_FLAG_MULTICOLOR) {
        sprite_multicolor_var( _environment, index->name );
    } else {
        sprite_monocolor_var( _environment, index->name );
    }
    
    vic2_sprite_data_from( _environment, index->name, realImage->name );

    if ( _flags & SPRITE_FLAG_EXPAND_VERTICAL) {
        sprite_expand_horizontal_var( _environment, index->name );
    } else {
        sprite_compress_horizontal_var( _environment, index->name );
    }

    if ( _flags & SPRITE_FLAG_EXPAND_HORIZONTAL) {
        sprite_expand_vertical_var( _environment, index->name );
    } else {
        sprite_compress_vertical_var( _environment, index->name );
    }

    return index;

}

#endif