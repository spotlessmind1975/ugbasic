#ifndef __UGBC_VIC2__
#define __UGBC_VIC2__

/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
 * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

#include "../ugbc.h"

#define COLOR_BLACK					0
#define COLOR_WHITE					1
#define COLOR_RED					2
#define COLOR_CYAN					3
#define COLOR_VIOLET				4
#define COLOR_GREEN					5
#define COLOR_BLUE					6
#define COLOR_YELLOW				7
#define COLOR_ORANGE				8
#define COLOR_BROWN					9
#define COLOR_LIGHT_RED				10
#define COLOR_DARK_GREY				11
#define COLOR_GREY					12
#define COLOR_LIGHT_GREEN			13
#define COLOR_LIGHT_BLUE			14
#define COLOR_LIGHT_GREY			15
#define COLOR_DARK_BLUE				6
#define COLOR_MAGENTA				COLOR_RED
#define COLOR_PURPLE				COLOR_VIOLET
#define COLOR_LAVENDER       		COLOR_VIOLET
#define COLOR_GOLD       			COLOR_YELLOW
#define COLOR_TURQUOISE       		COLOR_LIGHT_BLUE
#define COLOR_TAN       		    COLOR_BROWN
#define COLOR_YELLOW_GREEN       	COLOR_YELLOW
#define COLOR_OLIVE_GREEN       	COLOR_GREEN
#define COLOR_PINK       			COLOR_LIGHT_RED
#define COLOR_PEACH       			COLOR_PINK
#define COLOR_COUNT                 16


void vic2_background_color( Environment * _environment, char * _index, char * _background_color );
void vic2_border_color( Environment * _environment, char * _border_color );
void vic2_collision( Environment * _environment, char * _sprite_mask, char * _result );
void vic2_hit( Environment * _environment, char * _sprite_mask, char * _result );
void vic2_next_raster( Environment * _environment );
void vic2_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void vic2_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void vic2_sprite_common_color( Environment * _environment, char * _index, char * _common_color );
void vic2_bitmap_enable( Environment * _environment );
void vic2_bitmap_disable( Environment * _environment );
void vic2_bitmap_at( Environment * _environment, char * _address );
void vic2_colormap_at( Environment * _environment, char * _address );
void vic2_textmap_at( Environment * _environment, char * _address );
void vic2_tiles_at( Environment * _environment, char * _address );

void vic2_bank_select( Environment * _environment, int _bank );
void vic2_enable_ecm( Environment * _environment );
void vic2_disable_ecm( Environment * _environment );
void vic2_enable_mcm( Environment * _environment );
void vic2_disable_mcm( Environment * _environment );
void vic2_screen_on( Environment * _environment );
void vic2_screen_off( Environment * _environment );
void vic2_screen_rows( Environment * _environment, char * _rows );

void vic2_sprite_data_from( Environment * _environment, char * _sprite, char * _address );
void vic2_sprite_enable( Environment * _environment, char *_sprite );
void vic2_sprite_disable( Environment * _environment, char * _sprite );
void vic2_sprite_position( Environment * _environment, char * _sprite, char * _x, char * _y );
void vic2_sprite_expand_vertical( Environment * _environment, char * _sprite );
void vic2_sprite_expand_horizontal( Environment * _environment, char * _sprite );
void vic2_sprite_compress_vertical( Environment * _environment, char * _sprite );
void vic2_sprite_compress_horizontal( Environment * _environment, char * _sprite );
void vic2_sprite_multicolor( Environment * _environment, char * _sprite );
void vic2_sprite_monocolor( Environment * _environment, char * _sprite );
void vic2_sprite_color( Environment * _environment, char * _sprite, char * _color );
void vic2_xpen( Environment * _environment, char * _destination );
void vic2_ypen( Environment * _environment, char * _destination );
void vic2_vertical_scroll( Environment * _environment, char * _displacement );
void vic2_horizontal_scroll( Environment * _environment, char * _displacement );
void vic2_busy_wait( Environment * _environment, char * _timing );

void vic2_text_at( Environment * _environment, char * _x, char * _y, char * _text, char * _size );
void vic2_get_width( Environment * _environment, char * _result );
void vic2_get_height( Environment * _environment, char * _result );

void vic2_point_at_int( Environment * _environment, int _x, int _y );
void vic2_point_at_vars( Environment * _environment, char *_x, char *_y );

#endif