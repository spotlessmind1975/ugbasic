#ifndef __UGBC_CPC__
#define __UGBC_CPC__

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
 * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

#include "../ugbc.h"

#define KEY_NONE					255
#define KEY_0						'0'
#define KEY_1						72
#define KEY_2						65
#define KEY_3						57
#define KEY_4						64
#define KEY_5						49
#define KEY_6						56
#define KEY_7						41
#define KEY_8						48
#define KEY_9						33
#define KEY_A						69
#define KEY_ASTERISK				0xfe
#define KEY_AT						0xfe
#define KEY_B						54
#define KEY_C						62
#define KEY_CLEAR					0xfe
#define KEY_COLON					0xfe
#define KEY_COMMA					38
#define KEY_COMMODORE				0xfe
#define KEY_CONTROL					23
#define KEY_CRSR_LEFT_RIGHT			0xfe
#define KEY_CRSR_UP_DOWN			0xfe
#define KEY_D						61
#define KEY_DELETE					24
#define KEY_E						58
#define KEY_EQUAL					0xfe
#define KEY_F						53
#define KEY_F1						0xfe
#define KEY_F2						0xfe
#define KEY_F3						0xfe
#define KEY_F4						0xfe
#define KEY_F5						0xfe
#define KEY_F6						0xfe
#define KEY_F7						0xfe
#define KEY_F8						0xfe
#define KEY_G					    52
#define KEY_H						44
#define KEY_HOME					0xfe
#define KEY_I						35
#define KEY_INSERT					0xfe
#define KEY_J						45
#define KEY_K						37
#define KEY_L						36
#define KEY_LEFT_ARROW				0xfe
#define KEY_LEFT_SHIFT				21
#define KEY_M						29
#define KEY_MINUS					0xfe
#define KEY_N						46
#define KEY_O						34
#define KEY_P						27
#define KEY_PERIOD					39
#define KEY_PLUS					32
#define KEY_POUND					0xfe
#define KEY_Q						69
#define KEY_R						50
#define KEY_RETURN					18
#define KEY_RIGHT_SHIFT				21
#define KEY_RUNSTOP					0xfe
#define KEY_S						60
#define KEY_SEMICOLON				0xfe
#define KEY_SLASH					0xfe
#define KEY_SPACE					47
#define KEY_T						51
#define KEY_U						42
#define KEY_UP_ARROW				8
#define KEY_V						5
#define KEY_W						71
#define KEY_X						63
#define KEY_Y						43
#define KEY_Z						59
#define KEY_BACKSLASH               19
#define KEY_SQUARE_OPEN             0xfe
#define KEY_SQUARE_CLOSED           0xfe
#define KEY_SEMICOMMA               0xfe
#define KEY_QUOTE                   0xfe
#define KEY_APIX                    0xfe
#define KEY_DEAD                    0xfe
#define KEY_SHIFT                   21
#define KEY_CTRL                    23
#define KEY_GRAPH                   0xfe
#define KEY_CAPS                    70
#define KEY_CODE                    0xfe
#define KEY_ESC                     66
#define KEY_TAB                     68
#define KEY_STOP                    0xfe
#define KEY_BS                      79
#define KEY_SELECT                  0xfe
#define KEY_RET                     0xfe
#define KEY_INS                     0xfe
#define KEY_DEL                     24
#define KEY_LEFT                    8
#define KEY_UP                      0
#define KEY_DOWN                    2
#define KEY_RIGHT                   1
#define KEY_DIVISION                0xfe

#define KEYBOARD_CONFIG_DEFAULT_SYNC       1

#define INPUT_DEFAULT_SEPARATOR     ','
#define INPUT_DEFAULT_SIZE          32
#define INPUT_DEFAULT_CURSOR        95
#define INPUT_DEFAULT_RATE          16
#define INPUT_DEFAULT_DELAY         16

#define SCREEN_CAPABILITIES         ( ( 1<<BITMAP_NATIVE ) )

#define JOY_COUNT           2

#define JOY_UP              0
#define JOY_DOWN            1
#define JOY_LEFT            2
#define JOY_RIGHT           3
#define JOY_FIRE            4

#define JOYSTICK_CONFIG_DEFAULT_SYNC      1

#define DEFAULT_PAINT_BUCKET_SIZE   1024

#define BANK_COUNT          0
#define BANK_SIZE           0

void cpc_wait_key( Environment * _environment, int _release );
void cpc_wait_fire( Environment * _environment, int _port, int _release );
void cpc_wait_fire_semivar( Environment * _environment, char * _port, int _release );
void cpc_wait_key_or_fire( Environment * _environment, int _port, int _release );
void cpc_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release );
void cpc_key_state( Environment * _environment, char *_scancode, char * _result );
void cpc_scancode( Environment * _environment, char * _scacode );
void cpc_asciicode( Environment * _environment, char * _asciicode );
void cpc_inkey( Environment * _environment, char * _key );
void cpc_key_pressed( Environment * _environment, char *_scancode, char * _result );

void cpc_scanshift( Environment * _environment, char * _shifts );
void cpc_keyshift( Environment * _environment, char * _shifts );
void cpc_clear_key( Environment * _environment );
void cpc_put_key(  Environment * _environment, char *_string, char * _size );

void cpc_joy( Environment * _environment, int _port, char * _value );
void cpc_joy_vars( Environment * _environment, char * _port, char * _value );


#define COLOR_BLACK					0x14
#define COLOR_DARK_BLUE				0x04 // BLUE
#define COLOR_BLUE					0x04
#define COLOR_LIGHT_BLUE			0x15
#define COLOR_DARK_RED				0x1c // RED
#define COLOR_RED					0x1c
#define COLOR_LIGHT_RED				0x0c
#define COLOR_MAGENTA				0x18
#define COLOR_MAUVE 				0x1d
#define COLOR_PURPLE				0x05
#define COLOR_LIGHT_MAGENTA			0x0d
#define COLOR_DARK_GREEN			0x16 // GREEN
#define COLOR_GREEN					0x16
#define COLOR_LIGHT_GREEN			0x12
#define COLOR_CYAN					0x06
#define COLOR_DARK_CYAN				0x06
#define COLOR_YELLOW				0x1e
#define COLOR_PASTEL_BLUE			0x1f
#define COLOR_ORANGE				0x0e
#define COLOR_PINK       			0x07
#define COLOR_PASTEL_MAGENTA		0x0f
#define COLOR_SEA_GREEN			    0x02
#define COLOR_LIGHT_CYAN		    0x13
#define COLOR_LIME      		    0x1a
#define COLOR_PASTEL_GREEN    	    0x19
#define COLOR_PASTEL_CYAN    	    0x1b
#define COLOR_LIGHT_YELLOW    	    0x0a
#define COLOR_PASTEL_YELLOW   	    0x03
#define COLOR_DARK_WHITE			0x00 // WHITE
#define COLOR_WHITE					0x00
#define COLOR_LIGHT_WHITE   	    0x0b

// 57h	Sky Blue	0 50 100	#0080FF	0/128/255

#define COLOR_VIOLET				COLOR_PURPLE
#define COLOR_BROWN					COLOR_RED
#define COLOR_DARK_GREY				COLOR_BLACK
#define COLOR_GREY					COLOR_WHITE
#define COLOR_LIGHT_GREY			COLOR_WHITE
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
#define TEXT_ROWS_COUNT             24

#define BITMAP_MODE_GRAPHIC0        0           // "Mode 0" 160×200 pixels with 16 colors
#define BITMAP_MODE_GRAPHIC1        1           // "Mode 1" 320×200 pixels with 4 colors
#define BITMAP_MODE_GRAPHIC2        2           // "Mode 2" 640×200 pixels with 2 colors
#define BITMAP_MODE_GRAPHIC3        3           // "Mode 3" 160×200 pixels with 4 colors (2bpp) (this is not an official mode, but rather a side-effect of the hardware)

#define BITMAP_MODE_DEFAULT     BITMAP_MODE_GRAPHIC2
#define BITMAP_MODE_STANDARD    BITMAP_MODE_DEFAULT

#define SPRITE_COUNT                0
#define SPRITE_WIDTH                0
#define SPRITE_HEIGHT               0

#define SPRITE_X_MIN                0
#define SPRITE_Y_MIN                0
#define SPRITE_X_MAX                0
#define SPRITE_Y_MAX                0

#define SCREEN_SPRITE_RATIO_X       100
#define SCREEN_SPRITE_RATIO_Y       100
#define SCREEN_BORDER_X             0
#define SCREEN_BORDER_Y             0

#define IMAGE_WIDTH_SIZE                2
#define IMAGE_WIDTH_OFFSET              0
#define IMAGE_HEIGHT_SIZE               1
#define IMAGE_HEIGHT_OFFSET             2

#define DOUBLE_BUFFER_PAGE_0        0
#define DOUBLE_BUFFER_PAGE_1        1

#define MAX_AUDIO_CHANNELS  3 /* 4 channel is noise! */

// IN r,(C)/OUT (C),r instructions: Bits b15-b8 come from the B register, 
// bits b7-b0 come from r 
// IN A, (n)/OUT (n),A instructions: Bits b15-b8 come from the A register, 
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
                            outline0( "LD A, (GAVALUE)" ); \
                            outline1( "AND A, $%2.2x", (unsigned char) ~( (unsigned char) mask & 0xff ) ); \
                            outline1( "OR A, $%2.2x", (unsigned char) ( (unsigned char) value & 0xff ) ); \
                            outline0( "LD (GAVALUE), A" ); \
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
void cpc_fade( Environment * _environment, char * _ticks );

void cpc_bank_select( Environment * _environment, int _bank );
void cpc_screen_on( Environment * _environment );
void cpc_screen_off( Environment * _environment );
void cpc_screen_rows( Environment * _environment, char * _rows );
void cpc_screen_columns( Environment * _environment, char * _columns );

void cpc_sprite_data_from( Environment * _environment, char * _sprite, char * _address );
void cpc_sprite_data_set( Environment * _environment, char * _sprite, char * _address );
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
void cpc_sprite_priority( Environment * _environment, char * _sprite, char * _priority );
void cpc_vertical_scroll( Environment * _environment, char * _displacement );
void cpc_horizontal_scroll( Environment * _environment, char * _displacement );
void cpc_busy_wait( Environment * _environment, char * _timing );

void cpc_tiles_get( Environment * _environment, char * _result );
void cpc_get_width( Environment * _environment, char * _result );
void cpc_get_height( Environment * _environment, char * _result );

void cpc_pset_int( Environment * _environment, int _x, int _y, int *_c );
void cpc_pset_vars( Environment * _environment, char *_x, char *_y, char *_c );
void cpc_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result );
void cpc_cls( Environment * _environment );
void cpc_scroll_text( Environment * _environment, int _direction, int _overlap );
void cpc_hscroll_line( Environment * _environment, int _direction, int _overlap );
void cpc_hscroll_screen( Environment * _environment, int _direction, int _overlap );
void cpc_text( Environment * _environment, char * _text, char * _text_size, int _raw );
void cpc_cline( Environment * _environment, char * _characters );
void cpc_scroll( Environment * _environment, int _dx, int _dy );

Variable * cpc_get_raster_line( Environment * _environment );

int cpc_image_size( Environment * _environment, int _width, int _height, int _mode );
Variable * cpc_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags );
Variable * cpc_sprite_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, RGBi * _color );
void cpc_put_image( Environment * _environment, Resource * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _flags );
void cpc_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
void cpc_wait_vbl( Environment * _environment, char * _raster_line );
Variable * cpc_new_image( Environment * _environment, int _width, int _height, int _mode );
Variable * cpc_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode );
Variable * cpc_new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode );
void cpc_get_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _palette );

void cpc_put_tile( Environment * _environment, char * _image, char * _x, char * _y );
void cpc_put_tiles( Environment * _environment, char * _image, char * _x, char * _y, char *_w, char *_h );
void cpc_move_tiles( Environment * _environment, char * _image, char * _x, char * _y );
void cpc_use_tileset( Environment * _environment, char * _tileset );
void cpc_tile_at( Environment * _environment, char * _x, char * _y, char *_result );

void cpc_move_memory_video( Environment * _environment, char * _from, char * _to, char * _size );
void cpc_move_video_memory( Environment * _environment, char * _from, char * _to, char * _size );
void cpc_move_video_video( Environment * _environment, char * _from, char * _to, char * _size );

typedef void (*CpcSliceImageFunction)(Environment *, char *, char *, char *, int, int, char *);

void cpc_slice_image_copy( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination );
void cpc_slice_image_extract( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination );
void cpc_sys_call( Environment * _environment, int _destination );
int cpc_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette );
void cpc_calculate_sequence_frame_offset( Environment * _environment, char * _offset, char * _sequence, char * _frame, int _frame_size, int _frame_count );

void cpc_timer_set_status_on( Environment * _environment, char * _timer );
void cpc_timer_set_status_off( Environment * _environment, char * _timer );
void cpc_timer_set_counter( Environment * _environment, char * _timer, char * _counter );
void cpc_timer_set_init( Environment * _environment, char * _timer, char * _init );
void cpc_timer_set_address( Environment * _environment, char * _timer, char * _address );
void cpc_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size );
void cpc_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size );
void cpc_flip_image( Environment * _environment, Resource * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _direction );

#endif