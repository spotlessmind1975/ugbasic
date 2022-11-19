#ifndef __UGBC_CPC__
#define __UGBC_CPC__

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
 * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

#include "../ugbc.h"

#define KEY_NONE					64
#define KEY_0						'0'
#define KEY_1						'1'
#define KEY_2						'2'
#define KEY_3						'3'
#define KEY_4						'4'
#define KEY_5						'5'
#define KEY_6						'6'
#define KEY_7						'7'
#define KEY_8						'8'
#define KEY_9						'9'
#define KEY_A						'A'
#define KEY_ASTERISK				'*'
#define KEY_AT						'@'
#define KEY_B						'B'
#define KEY_C						'C'
#define KEY_CLEAR					0xf9
#define KEY_COLON					':'
#define KEY_COMMA					','
#define KEY_COMMODORE				0x00
#define KEY_CONTROL					0x00
#define KEY_CRSR_LEFT_RIGHT			0x00
#define KEY_CRSR_UP_DOWN			0x00
#define KEY_D						'D'
#define KEY_DELETE					0x90
#define KEY_E						'E'
#define KEY_EQUAL					'='
#define KEY_F						'F'
#define KEY_F1						0x00
#define KEY_F2						0x00
#define KEY_F3						0x00
#define KEY_F4						0x00
#define KEY_F5						0x00
#define KEY_F6						0x00
#define KEY_F7						0x00
#define KEY_F8						0x00
#define KEY_G						'G'
#define KEY_H						'H'
#define KEY_HOME					0x88
#define KEY_I						'I'
#define KEY_INSERT					0x89
#define KEY_J						'J'
#define KEY_K						'K'
#define KEY_L						'L'
#define KEY_LEFT_ARROW				0x91
#define KEY_LEFT_SHIFT				0x81
#define KEY_M						'M'
#define KEY_MINUS					'-'
#define KEY_N						'N'
#define KEY_O						'O'
#define KEY_P						'P'
#define KEY_PERIOD					'.'
#define KEY_PLUS					'+'
#define KEY_POUND					0x00
#define KEY_Q						'Q'
#define KEY_R						'R'
#define KEY_RETURN					0x0d
#define KEY_RIGHT_SHIFT				0x81
#define KEY_RUNSTOP					0x86
#define KEY_S						'S'
#define KEY_SEMICOLON				';'
#define KEY_SLASH					'/'
#define KEY_SPACE					' '
#define KEY_T						'T'
#define KEY_U						'U'
#define KEY_UP_ARROW				0x92
#define KEY_V						'V'
#define KEY_W						'W'
#define KEY_X						'X'
#define KEY_Y						'Y'
#define KEY_Z						'Z'
#define KEY_BACKSLASH                '\\'
#define KEY_SQUARE_OPEN              0x00
#define KEY_SQUARE_CLOSED            0x00
#define KEY_SEMICOMMA                ';'
#define KEY_QUOTE                    '"'
#define KEY_APIX                     0x00
#define KEY_DEAD                     0x00
#define KEY_SHIFT                    0x81
#define KEY_CTRL                     0x82
#define KEY_GRAPH                    0x83
#define KEY_CAPS                     0x84
#define KEY_CODE                     0x85
#define KEY_ESC                      0x27
#define KEY_TAB                      0x09
#define KEY_STOP                     0x86
#define KEY_BS                       0x08
#define KEY_SELECT                   0x87
#define KEY_RET                      0x0d
#define KEY_INS                      0x89
#define KEY_DEL                      0x90
#define KEY_LEFT                     0x91
#define KEY_UP                       0x92
#define KEY_DOWN                     0x93
#define KEY_RIGHT                    0x94
#define KEY_DIVISION                 '/'

#define INPUT_DEFAULT_SEPARATOR     ','
#define INPUT_DEFAULT_SIZE          32
#define INPUT_DEFAULT_CURSOR        0x60

#define SCREEN_CAPABILITIES         ( ( 1<<BITMAP_NATIVE ) )

#define JOY_COUNT           2

#define JOY_UP              0
#define JOY_DOWN            1
#define JOY_LEFT            2
#define JOY_RIGHT           3
#define JOY_FIRE            4

#define BANK_COUNT          0
#define BANK_SIZE           0

void cpc_inkey( Environment * _environment, char * _pressed, char * _key );
void cpc_scancode( Environment * _environment, char * _pressed, char * _scacode );
void cpc_scanshift( Environment * _environment, char * _shifts );
void cpc_keyshift( Environment * _environment, char * _shifts );
void cpc_key_pressed( Environment * _environment, char *_scancode, char * _result );
void cpc_clear_key( Environment * _environment );
void cpc_irq_at( Environment * _environment, char * _label );
void cpc_follow_irq( Environment * _environment );
void cpc_joy( Environment * _environment, char * _port, char * _value );


#define COLOR_BLACK					0x14
#define COLOR_BLUE					0x04
#define COLOR_LIGHT_BLUE			0x15
#define COLOR_RED					0x1c
#define COLOR_MAGENTA				0x18
#define COLOR_MAUVE 				0x1d
#define COLOR_LIGHT_RED				0x0c
#define COLOR_PURPLE				0x05
#define COLOR_LIGHT_MAGENTA			0x0d
#define COLOR_GREEN					0x16
#define COLOR_CYAN					0x06
#define COLOR_DARK_CYAN				0x06
#define COLOR_YELLOW				0x1e
#define COLOR_WHITE					0x00
#define COLOR_PASTEL_BLUE			0x1f
#define COLOR_ORANGE				0x0e
#define COLOR_PINK       			0x07
#define COLOR_PASTEL_MAGENTA		0x0f
#define COLOR_LIGHT_GREEN			0x12
#define COLOR_SEA_GREEN			    0x02
#define COLOR_LIGHT_CYAN		    0x13
#define COLOR_LIME      		    0x1a
#define COLOR_PASTEL_GREEN    	    0x19
#define COLOR_PASTEL_CYAN    	    0x1b
#define COLOR_LIGHT_YELLOW    	    0x0a
#define COLOR_PASTEL_YELLOW   	    0x03
#define COLOR_LIGHT_WHITE   	    0x0b

// 57h	Sky Blue	0 50 100	#0080FF	0/128/255

#define COLOR_VIOLET				COLOR_PURPLE
#define COLOR_BROWN					COLOR_RED
#define COLOR_DARK_GREY				COLOR_BLACK
#define COLOR_GREY					COLOR_BLACK
#define COLOR_LIGHT_GREY			COLOR_WHITE
#define COLOR_DARK_BLUE				COLOR_BLUE
#define COLOR_LAVENDER       		COLOR_VIOLET
#define COLOR_GOLD       			COLOR_YELLOW
#define COLOR_TURQUOISE       		COLOR_LIGHT_BLUE
#define COLOR_TAN       		    COLOR_BROWN
#define COLOR_YELLOW_GREEN       	COLOR_YELLOW
#define COLOR_OLIVE_GREEN       	COLOR_PASTEL_GREEN
#define COLOR_PEACH       			COLOR_PINK
#define COLOR_COUNT                 16

#define DEFAULT_PEN_COLOR           COLOR_WHITE
#define DEFAULT_PAPER_COLOR         COLOR_BLACK

#define TEXT_COLUMNS_COUNT          20
#define TEXT_ROWS_COUNT             25

#define BITMAP_MODE_GRAPHIC0        0           // "Mode 0" 160×200 pixels with 16 colors
#define BITMAP_MODE_GRAPHIC1        1           // "Mode 1" 320×200 pixels with 4 colors
#define BITMAP_MODE_GRAPHIC2        2           // "Mode 2" 640×200 pixels with 2 colors
#define BITMAP_MODE_GRAPHIC3        3           // "Mode 3" 160×200 pixels with 4 colors (2bpp) (this is not an official mode, but rather a side-effect of the hardware)

#define BITMAP_MODE_DEFAULT     BITMAP_MODE_GRAPHIC2

#define SPRITE_COUNT                0
#define SPRITE_WIDTH                0
#define SPRITE_HEIGHT               0

#define SPRITE_X_MIN                0
#define SPRITE_Y_MIN                0
#define SPRITE_X_MAX                0
#define SPRITE_Y_MAX                0

#define SCREEN_BORDER_X             0
#define SCREEN_BORDER_Y             0

#define SPRITE_FLAG_MULTICOLOR          0x0010
#define SPRITE_FLAG_MONOCOLOR           0x0000
#define SPRITE_FLAG_EXPAND_VERTICAL     0x0040
#define SPRITE_FLAG_COMPRESS_VERTICAL   0x0000
#define SPRITE_FLAG_EXPAND_HORIZONTAL   0x0080
#define SPRITE_FLAG_COMPRESS_HORIZONTAL 0x0000

#define MAX_AUDIO_CHANNELS  3

// IN r,(C)/OUT (C),r instructions: Bits b15-b8 come from the B register, 
// bits b7-b0 come from r 
// IN A,(n)/OUT (n),A instructions: Bits b15-b8 come from the A register, 
// bits b7-b0 come from n 
// Listed below are the internal hardware devices and the bit fields to 
// which they respond. In the table:
// - means this bit is ignored, 0 means the bit must be set to 0 for the 
// hardware device to respond, 1 means the bit must be set to 1 for the hardware device to respond. r1 and r0 mean a bit used to define a register

// Hardware device	Address	Read/Write	b15	b14	b13	b12	b11	b10	b9	b8
// Gate-Array	&7f	Write Only	0	1	-	-	-	-	-	-

// RAM Configuration	&7f	Write Only	0	-	-	-	-	-	-	-
#define CPC_GA_MASK( mask, value ) \
                            outline0( "LD B, $7F" ) \
                            outline0( "IN C, (C)" ); \
                            outline0( "LD A, C" ); \
                            outline1( "AND A, $%2.2x", (unsigned char) ~( (unsigned char) mask & 0xff ) ); \
                            outline1( "OR A, $%2.2x", (unsigned char) ( (unsigned char) value & 0xff ) ); \
                            outline0( "LD C, A" ); \
                            outline0( "OUT (C), C" );

// CRTC	&BC-&BF	Read/Write	-	0	-	-	-	-	r1	r0
// ROM select	&DF	Write only	-	-	0	-	-	-	-	-
// Printer port	&EF	Write only	-	-	-	0	-	-	-	-
// 8255 PPI	&F4-&F7	Read/Write	-	-	-	-	0	-	r1	r0
// Expansion Peripherals	&F8-&FB	Read/Write	-	-	-	-	-	0	-	-


// #define TILES_PADDING           8

int cpc_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode );

void cpc_initialization( Environment * _environment );
void cpc_finalization( Environment * _environment );

void cpc_back( Environment * _environment );
void cpc_background_color( Environment * _environment, int _index, int _background_color );
void cpc_background_color_vars( Environment * _environment, char * _index, char * _background_color );
void cpc_background_color_semivars( Environment * _environment, int _index, char * _background_color );
void cpc_colors_vars( Environment * _environment, char * _foreground_color, char * _background_color );
void cpc_background_color_get_vars( Environment * _environment, char * _index, char * _background_color );
void cpc_border_color( Environment * _environment, char * _border_color );
Variable * cpc_collision( Environment * _environment, char * _sprite );
void cpc_hit( Environment * _environment, char * _sprite_mask, char * _result );
void cpc_next_raster( Environment * _environment );
void cpc_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void cpc_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void cpc_sprite_common_color( Environment * _environment, char * _index, char * _common_color );
void cpc_bitmap_enable( Environment * _environment, int _width, int _height, int _colors );
void cpc_bitmap_disable( Environment * _environment );
void cpc_bitmap_at( Environment * _environment, char * _address );
void cpc_colormap_at( Environment * _environment, char * _address );
void cpc_textmap_at( Environment * _environment, char * _address );
void cpc_tiles_at( Environment * _environment, char * _address );
void cpc_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height );

void cpc_bank_select( Environment * _environment, int _bank );
void cpc_enable_ecm( Environment * _environment );
void cpc_disable_ecm( Environment * _environment );
void cpc_enable_mcm( Environment * _environment );
void cpc_disable_mcm( Environment * _environment );
void cpc_screen_on( Environment * _environment );
void cpc_screen_off( Environment * _environment );
void cpc_screen_rows( Environment * _environment, char * _rows );
void cpc_screen_columns( Environment * _environment, char * _columns );

void cpc_sprite_data_from( Environment * _environment, char * _sprite, char * _image );
void cpc_sprite_enable( Environment * _environment, char *_sprite );
void cpc_sprite_disable( Environment * _environment, char * _sprite );
void cpc_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y );
void cpc_sprite_expand_vertical( Environment * _environment, char * _sprite );
void cpc_sprite_expand_horizontal( Environment * _environment, char * _sprite );
void cpc_sprite_compress_vertical( Environment * _environment, char * _sprite );
void cpc_sprite_compress_horizontal( Environment * _environment, char * _sprite );
void cpc_sprite_multicolor( Environment * _environment, char * _sprite );
void cpc_sprite_monocolor( Environment * _environment, char * _sprite );
void cpc_sprite_color( Environment * _environment, char * _sprite, char * _color );
void cpc_vertical_scroll( Environment * _environment, char * _displacement );
void cpc_horizontal_scroll( Environment * _environment, char * _displacement );
void cpc_busy_wait( Environment * _environment, char * _timing );

void cpc_tiles_get( Environment * _environment, char * _result );
void cpc_get_width( Environment * _environment, char * _result );
void cpc_tiles_get_width( Environment * _environment, char * _result );
void cpc_get_height( Environment * _environment, char * _result );
void cpc_tiles_get_height( Environment * _environment, char * _result );

void cpc_point_at_int( Environment * _environment, int _x, int _y );
void cpc_point_at_vars( Environment * _environment, char *_x, char *_y );
void cpc_point( Environment * _environment, char *_x, char *_y, char * _result );
void cpc_cls( Environment * _environment );
void cpc_scroll_text( Environment * _environment, int _direction );
void cpc_hscroll_line( Environment * _environment, int _direction );
void cpc_hscroll_screen( Environment * _environment, int _direction );
void cpc_text( Environment * _environment, char * _text, char * _text_size );
void cpc_cline( Environment * _environment, char * _characters );
void cpc_scroll( Environment * _environment, int _dx, int _dy );

Variable * cpc_get_raster_line( Environment * _environment );

Variable * cpc_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags );
Variable * cpc_sprite_converter( Environment * _environment, char * _data, int _width, int _height, RGBi * _color );
void cpc_put_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
void cpc_wait_vbl( Environment * _environment );
Variable * cpc_new_image( Environment * _environment, int _width, int _height, int _mode );
void cpc_get_image( Environment * _environment, char * _image, char * _x, char * _y );

void cpc_put_tile( Environment * _environment, char * _image, char * _x, char * _y );
void cpc_put_tiles( Environment * _environment, char * _image, char * _x, char * _y, char *_w, char *_h );
void cpc_move_tiles( Environment * _environment, char * _image, char * _x, char * _y );
void cpc_use_tileset( Environment * _environment, char * _tileset );
void cpc_tile_at( Environment * _environment, char * _x, char * _y, char *_result );

void cpc_move_memory_video( Environment * _environment, char * _from, char * _to, char * _size );
void cpc_move_video_memory( Environment * _environment, char * _from, char * _to, char * _size );
void cpc_move_video_video( Environment * _environment, char * _from, char * _to, char * _size );

#endif