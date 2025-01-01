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
#include "../../libs/stb_image.h"

/****************************************************************************
 * CODE SECTION 
 ****************************************************************************/

static ImageDescriptor * cut_frame_from_atlas( Environment * _environment, AtlasDescriptor * _atlas, int _x, int _y ) {

    ImageDescriptor * frame = malloc( sizeof( ImageDescriptor ) );
    memset( frame, 0, sizeof( ImageDescriptor ) );

    frame->width = _atlas->frameWidth;
    frame->height = _atlas->frameHeight;
    frame->depth = _atlas->image->depth;

    frame->size = frame->width * frame->height * frame->depth;

    frame->data = malloc( frame->size );
    memset( frame->data, 0, frame->size );

    frame->colors = malloc( sizeof( RGBi ) * frame->colorsCount );
    memcpy( frame->colors, _atlas->image->colors, sizeof( RGBi ) * frame->colorsCount );
    frame->colorsCount = _atlas->image->colorsCount;
    
    char * source = _atlas->image->data + 
                        ( _atlas->originX * _atlas->image->depth ) +
                        ( _atlas->originY * _atlas->image->width * _atlas->image->depth ) +
                        ( ( _atlas->frameWidth + _atlas->offsetX ) * _atlas->image->depth * _x ) +
                        ( ( _atlas->frameHeight + _atlas->offsetY ) * _atlas->image->width * _atlas->image->depth * _y );

    char * destination = frame->data;

    int frameHeight = frame->height;

    while( frameHeight ) {
        memcpy( destination, source, frame->width * frame->depth );
        source += _atlas->image->width * frame->depth;
        destination += frame->width * frame->depth;
        --frameHeight;
    }

    return frame;

}

static ImageDescriptor * cut_frame_from_atlas_gif( Environment * _environment, AtlasDescriptor * _atlas, int _y ) {

    ImageDescriptor * frame = malloc( sizeof( ImageDescriptor ) );
    memset( frame, 0, sizeof( ImageDescriptor ) );

    frame->size = _atlas->frameWidth * _atlas->frameHeight * _atlas->image->depth;

    frame->data = malloc( frame->size );
    memset( frame->data, 0, frame->size );

    frame->width = _atlas->frameWidth;
    frame->height = _atlas->frameWidth;
    frame->depth = _atlas->image->depth;

    frame->colors = malloc( sizeof( RGBi ) * frame->colorsCount );
    memcpy( frame->colors, _atlas->image->colors, sizeof( RGBi ) * frame->colorsCount );
    frame->colorsCount = _atlas->image->colorsCount;
    
    char * source = _atlas->image->data + 
                        ( _atlas->originX * _atlas->image->depth ) +
                        ( _atlas->originY * _atlas->image->width * _atlas->image->depth ) +
                        ( ( ( _atlas->frameHeight + _atlas->offsetY ) * _atlas->image->width * _atlas->image->depth + 2 ) * _y );

    char * destination = frame->data;

    int frameHeight = frame->height;

    while( frameHeight ) {
        memcpy( destination, source, frame->width * frame->depth );
        source += frame->width * frame->depth;
        destination += frame->width * frame->depth;
        --frameHeight;
    }

    return frame;

}

AtlasDescriptor * atlas_descriptor_create( Environment * _environment, char * _filename, int _flags, int _image_origin_x, int _image_origin_y, int _frame_width, int _frame_height, int _frame_offset_x, int _frame_offset_y ) {

    AtlasDescriptor * result = malloc( sizeof( AtlasDescriptor ) );
    memset( result, 0, sizeof( AtlasDescriptor ) );

    result->originX = _image_origin_x;
    result->originY = _image_origin_y;
    result->offsetX = _frame_offset_x;
    result->offsetY = _frame_offset_y;

    result->image = malloc( sizeof( ImageDescriptor ) );
    memset( result->image, 0, sizeof( ImageDescriptor ) );

    char * lookedFilename = resource_load_asserts( _environment, _filename );

    result->image->fileSize = file_get_size( _environment, lookedFilename );

    result->count = 0;
    int layout_mode = 0;

    if ( stbi_is_animated_gif( lookedFilename ) ) {
        if ( _image_origin_x || _image_origin_y ) {
            CRITICAL_IMAGES_LOAD_INVALID_ORIGIN_WITH_GIF( _filename );            
        }
        if ( _frame_offset_x || _frame_offset_y ) {
            CRITICAL_IMAGES_LOAD_INVALID_OFFSET_WITH_GIF( _filename );            
        }
        result->image->data = stbi_xload(lookedFilename, &result->image->width, &result->image->height, &result->count);
        result->image->depth = 4;
        result->frameWidth = result->image->width;
        result->frameHeight = result->image->height;
        result->horizontal = 1;
        result->vertical = result->count;
        layout_mode = 1;
    } else {
        if ( _frame_height < 0 || _frame_width < 0 ) {
            CRITICAL_IMAGES_LOAD_INVALID_AUTO_WITHOUT_GIF( _filename );            
        }
        result->image->data = stbi_load(lookedFilename, &result->image->width, &result->image->height, &result->image->depth, 0);
        result->count = 0;
        result->frameWidth = _frame_width;
        result->frameHeight = _frame_height;
        result->horizontal = 0; // ( ( result->image->width - result->originX) / (result->frameWidth+result->offsetX) ) + 1;
        int w = result->image->width - result->originX;
        while ( w >= result->frameWidth ) {
            ++result->horizontal;
            w -= result->frameWidth;
            w -= result->offsetX;
        }
        result->vertical = 0 ; // ( ( result->image->height - result->originY) / (result->frameHeight+result->offsetY) );
        int h = result->image->height - result->originY;
        while ( h >= result->frameHeight ) {
            ++result->vertical;
            h -= result->frameHeight;
            h -= result->offsetY;
        }
        layout_mode = 0;
    }

    if ( !result->image->data ) {
        CRITICAL_IMAGE_LOAD_UNKNOWN_FORMAT( _filename );
    }

    result->image->size = result->image->width * result->image->height * result->image->depth;
    result->image->colors = malloc_palette( MAX_PALETTE );
    result->image->colorsCount = MAX_PALETTE;
    result->image->colorsCount = rgbi_extract_palette( _environment, result->image->data, result->image->width, result->image->height, result->image->depth, result->image->colors, result->image->colorsCount, 1 );

    result->count = result->horizontal * result->vertical;

    adiline3("BMP:%4.4x:%4.4x:%2.2x", _frame_width, _frame_height, BITMAP_MODE_STANDARD );

    if ( layout_mode == 0 ) {

        int a = 1;

        int i,di,x=0,y=0,z=0;

        if( _flags & FLAG_ROLL_X ) {
            a = (result->frameWidth - 1);
        }

        i = 0;
        di = 1;

        adiline5("LIS:%s:%s:%2.2x:%2.2x:%x", _filename, lookedFilename, result->count, result->horizontal, result->image->fileSize );

        if( _flags & FLAG_FLIP_X ) {
            result->image = image_descriptor_flip_x( _environment, result->image );
        }

        if( _flags & FLAG_FLIP_Y ) {
            result->image = image_descriptor_flip_y( _environment, result->image );
        }

        // if ( _transparent_color != -1 ) {
        //     _flags |= FLAG_TRANSPARENCY;
        // }

        for( z=0; z<a; ++z ) {
            for( y=0; y<result->vertical; ++y ) {
                for( x=0; x<result->horizontal; ++x ) {
                    ImageDescriptor * frame = cut_frame_from_atlas( _environment, result, x, y );
                    if ( result->frames ) {
                        ImageDescriptor * actual = result->frames;
                        while( actual->next ) {
                            actual = actual->next;
                        };
                        actual->next = frame;
                    } else {
                        result->frames = frame;
                    }
                    i += di;
                }
            }
            if( _flags & FLAG_ROLL_X ) {
                if ( _flags & FLAG_FLIP_X ) {
                    result->image = image_descriptor_roll_x_left( _environment, result->image );
                } else {
                    result->image = image_descriptor_roll_x_right( _environment, result->image );
                }
            }
        }

    } else {

        int z;

        adiline5("LIS:%s:%s:%2.2x:%2.2x:%x", _filename, lookedFilename, result->count, result->horizontal, result->image->fileSize );

        // if( _flags & FLAG_FLIP_X ) {
        //     source = image_flip_x( _environment, source, width, height, depth );
        // }
        // if( _flags & FLAG_FLIP_Y ) {
        //     source = image_flip_y( _environment, source, width, height, depth );
        // }

        // if ( _transparent_color != -1 ) {
        //     _flags |= FLAG_TRANSPARENCY;
        // }

        for( z=0; z<result->count; ++z ) {
            ImageDescriptor * frame = cut_frame_from_atlas_gif( _environment, result, z );
            if ( result->frames ) {
                ImageDescriptor * actual = result->frames;
                while( actual->next ) {
                    actual = actual->next;
                };
                actual->next = frame;
            } else {
                result->frames = frame;
            }
        }

    }

    return result;

}
