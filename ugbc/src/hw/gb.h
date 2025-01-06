#ifndef __UGBC_GB__
#define __UGBC_GB__

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
 * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

#include "../ugbc.h"

#define KEY_NONE					255

#define KEY_0                         0
#define KEY_1                         1
#define KEY_2                         2
#define KEY_3                         3
#define KEY_4                         4
#define KEY_5                         5
#define KEY_6                         6
#define KEY_7                         7
#define KEY_8                         8
#define KEY_9                         9
#define KEY_MINUS                    10
#define KEY_EQUAL                    11
#define KEY_BACKSLASH                12
#define KEY_SQUARE_OPEN              13
#define KEY_SQUARE_CLOSE             14
#define KEY_SEMICOLON                15
#define KEY_QUOTE                    16
// ~
// <
// >
// ?
// $00
#define KEY_A                        22
#define KEY_B                        23
#define KEY_C                        24
#define KEY_D                        25
#define KEY_E                        26
#define KEY_F                        27
#define KEY_G                        28
#define KEY_H                        29
#define KEY_I                        30
#define KEY_J                        31
#define KEY_K                        32
#define KEY_L                        33
#define KEY_M                        34
#define KEY_N                        35
#define KEY_O                        36
#define KEY_P                        37
#define KEY_Q                        38
#define KEY_R                        39
#define KEY_S                        40
#define KEY_T                        41
#define KEY_U                        42
#define KEY_V                        43
#define KEY_W                        44
#define KEY_X                        45
#define KEY_Y                        46
#define KEY_Z                        47
// 48: 81
// 49: 82
// 50: 83
// 51: 84
// 52: 85
// 53: f1
// 54: f2
// 55: f3
// 56: f4
// 57: f5
#define KEY_ESC                      58
#define KEY_TAB                      59
// 60: 86
#define KEY_BS                       61
// 62: 87
#define KEY_RETURN                   63
#define KEY_SPACE                    64
// 65: 88
// 66: 89
// 67: 90
// 68: 91
// 69: 92
// 70: 93
// 71: 94
#define KEY_ASTERISK                 72
#define KEY_PLUS                     73
    // DB "/", "0", "1", "2", "3", "4"
    // DB "5", "6", ",", "8", "9", "-", "7", "."
#define KEY_PERIOD                   87 
    // DB $ff


#define KEY_AT						  0
#define KEY_COMMODORE				  0
#define KEY_CONTROL					  0
#define KEY_CRSR_LEFT_RIGHT			  0
#define KEY_CRSR_UP_DOWN			  0
#define KEY_DELETE					  0
#define KEY_F1						  0
#define KEY_F2						  0
#define KEY_F3						  0
#define KEY_F4						  0
#define KEY_F5						  0
#define KEY_F6						  0
#define KEY_F7						  0
#define KEY_F8						  0
#define KEY_HOME					  0
#define KEY_INSERT					  0
#define KEY_LEFT_ARROW				  0
#define KEY_LEFT_SHIFT				  0
#define KEY_POUND					  0
#define KEY_RIGHT_SHIFT				  0
#define KEY_RUNSTOP					  0
#define KEY_UP_ARROW				  0
#define KEY_SEMICOMMA                 0
#define KEY_APIX                      0
#define KEY_DEAD                      0
#define KEY_SHIFT                     0
#define KEY_CTRL                      0
#define KEY_GRAPH                     0
#define KEY_CAPS                      0
#define KEY_CODE                      0
#define KEY_STOP                      0
#define KEY_SELECT                    0
#define KEY_INS                       0
#define KEY_DEL                       0
#define KEY_LEFT                      0
#define KEY_UP                        0
#define KEY_DOWN                      0
#define KEY_RIGHT                     0
#define KEY_DIVISION                  0
#define KEY_CLEAR                     0
#define KEY_COLON                     0
#define KEY_COMMA                     0
#define KEY_SLASH                     0

#define KEYBOARD_CONFIG_DEFAULT_SYNC       0

#define INPUT_DEFAULT_SEPARATOR     ','
#define INPUT_DEFAULT_SIZE          32
#define INPUT_DEFAULT_CURSOR        95
#define INPUT_DEFAULT_RATE          16
#define INPUT_DEFAULT_DELAY         64

#define SCREEN_CAPABILITIES         ( ( 1<<TILEMAP_NATIVE ) | ( 1<<BITMAP_NATIVE ) )

#define DEFAULT_PAINT_BUCKET_SIZE   512

#define BANK_COUNT          1
#define BANK_SIZE           4096

#define JOY_COUNT           2

#define JOY_UP              0
#define JOY_DOWN            1
#define JOY_LEFT            2
#define JOY_RIGHT           3
#define JOY_FIRE            4

#define JOYSTICK_CONFIG_DEFAULT_SYNC      1

#define MAX_AUDIO_CHANNELS  3

#define COLOR_TRANSPARENT			0x00
#define COLOR_BLACK					0x00
#define COLOR_DARK_WHITE			0x0e // GREY
#define COLOR_WHITE					0x01
#define COLOR_LIGHT_WHITE			COLOR_WHITE
#define COLOR_DARK_RED				0x06 // BROWN
#define COLOR_RED					0x08
#define COLOR_LIGHT_RED				0x09
#define COLOR_CYAN					0x07
#define COLOR_VIOLET				0x0d
#define COLOR_DARK_GREEN			0x02 // GREEN
#define COLOR_GREEN					0x02
#define COLOR_LIGHT_GREEN			0x03
#define COLOR_DARK_BLUE				0x04
#define COLOR_BLUE					0x07
#define COLOR_LIGHT_BLUE			0x05
#define COLOR_YELLOW				0x0b
#define COLOR_ORANGE				0x09
#define COLOR_BROWN					0x06
#define COLOR_DARK_GREY				0x0e
#define COLOR_GREY					0x0e
#define COLOR_LIGHT_GREY			0x0e
#define COLOR_MAGENTA				0x0d
#define COLOR_PURPLE				COLOR_VIOLET
#define COLOR_LAVENDER       		COLOR_VIOLET
#define COLOR_GOLD       			0x0a
#define COLOR_TURQUOISE       		COLOR_LIGHT_BLUE
#define COLOR_TAN       		    COLOR_BROWN
#define COLOR_YELLOW_GREEN       	0x03
#define COLOR_OLIVE_GREEN       	0x0c
#define COLOR_PINK       			COLOR_LIGHT_RED
#define COLOR_PEACH       			COLOR_PINK
#define COLOR_COUNT                 16

#define DEFAULT_PEN_COLOR           COLOR_WHITE
#define DEFAULT_PAPER_COLOR         COLOR_BLACK

#define TEXT_COLUMNS_COUNT          40
#define TEXT_ROWS_COUNT             25

#define TILEMAP_MODE_BGB            0                       // BGB
#define TILEMAP_MODE_CGB            1                       // CGB
#define TILEMAP_MODE_STANDARD       TILEMAP_MODE_BGB        // BGB

#define BITMAP_MODE_STANDARD        TILEMAP_MODE_STANDARD
#define BITMAP_MODE_DEFAULT         TILEMAP_MODE_STANDARD

#define SPRITE_COUNT                32
#define SPRITE_WIDTH                8
#define SPRITE_HEIGHT               8
#define SPRITE_X_MIN                0
#define SPRITE_Y_MIN                0
#define SPRITE_X_MAX                264
#define SPRITE_Y_MAX                200

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

void gb_wait_vbl( Environment * _environment, char * _raster_line );
void gb_screen_on_off( Environment * _environment, int _on_off );

void gb_wait_key( Environment * _environment, int _release );
void gb_wait_fire( Environment * _environment, int _port, int _release );
void gb_wait_fire_semivar( Environment * _environment, char * _port, int _release );
void gb_wait_key_or_fire( Environment * _environment, int _port, int _release );
void gb_wait_key_or_fire_semivar( Environment * _environment, char * _port, int _release );

void gb_key_state( Environment * _environment, char *_scancode, char * _result );
void gb_scancode( Environment * _environment, char * _scacode );
void gb_asciicode( Environment * _environment, char * _asciicode );
void gb_inkey( Environment * _environment, char * _key );
void gb_key_pressed( Environment * _environment, char *_scancode, char * _result );
void gb_put_key(  Environment * _environment, char *_string, char * _size );

void gb_scanshift( Environment * _environment, char * _shifts );
void gb_keyshift( Environment * _environment, char * _shifts );
void gb_clear_key( Environment * _environment );
void gb_joy( Environment * _environment, int _port, char * _result );
void gb_joy_vars( Environment * _environment, char * _port, char * _result );

void gb_sys_call( Environment * _environment, int _destination );

void gb_timer_set_status_on( Environment * _environment, char * _timer );
void gb_timer_set_status_off( Environment * _environment, char * _timer );
void gb_timer_set_counter( Environment * _environment, char * _timer, char * _counter );
void gb_timer_set_init( Environment * _environment, char * _timer, char * _init );
void gb_timer_set_address( Environment * _environment, char * _timer, char * _address );
void gb_dload( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size );
void gb_dsave( Environment * _environment, char * _filename, char * _offset, char * _address, char * _size );

void gb_dojo_ready( Environment * _environment, char * _value );
void gb_dojo_read_byte( Environment * _environment, char * _value );
void gb_dojo_write_byte( Environment * _environment, char * _value );

void gb_dojo_ping( Environment * _environment, char * _result );
void gb_dojo_login( Environment * _environment, char * _name, char * _name_size, char * _password, char * _size, char * _unique_id );
void gb_dojo_success( Environment * _environment, char * _id, char * _result );
void gb_dojo_create_port( Environment * _environment, char * _session_id, char * _application, char * _size, char * _port_id );
void gb_dojo_find_port( Environment * _environment, char * _session_id, char * _username, char * _size, char * _application, char * _application_size, char * _port_id );
void gb_dojo_put_message( Environment * _environment, char * _port_id, char * _message, char * _size, char * _result );
void gb_dojo_peek_message( Environment * _environment, char * _port_id, char * _result );
void gb_dojo_get_message( Environment * _environment, char * _port_id, char * _result, char * _message );
void gb_dojo_destroy_port( Environment * _environment, char * _port_id, char * _result );

void gb_initialization( Environment * _environment );
void gb_finalization( Environment * _environment );

int gb_screen_mode_enable( Environment * _environment, ScreenMode * _screen_mode );

void gb_back( Environment * _environment );
void gb_background_color( Environment * _environment, int _index, int _background_color );
void gb_background_color_vars( Environment * _environment, char * _index, char * _background_color );
void gb_background_color_semivars( Environment * _environment, int _index, char * _background_color );
void gb_colors_vars( Environment * _environment, char * _foreground_color, char * _background_color );
void gb_background_color_get_vars( Environment * _environment, char * _index, char * _background_color );
void gb_border_color( Environment * _environment, char * _border_color );
Variable * gb_collision( Environment * _environment, char * _sprite );
void gb_hit( Environment * _environment, char * _sprite_mask, char * _result );
void gb_next_raster( Environment * _environment );
void gb_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void gb_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void gb_sprite_common_color( Environment * _environment, char * _index, char * _common_color );
void gb_bitmap_enable( Environment * _environment, int _width, int _height, int _colors );
void gb_bitmap_disable( Environment * _environment );
void gb_bitmap_at( Environment * _environment, char * _address );
void gb_colormap_at( Environment * _environment, char * _address );
void gb_textmap_at( Environment * _environment, char * _address );
void gb_tiles_at( Environment * _environment, char * _address );
void gb_tilemap_enable( Environment * _environment, int _width, int _height, int _colors, int _tile_width, int _tile_height );
void gb_fade( Environment * _environment, char * _ticks );

void gb_bank_select( Environment * _environment, int _bank );
void gb_screen_on( Environment * _environment );
void gb_screen_off( Environment * _environment );
void gb_screen_rows( Environment * _environment, char * _rows );
void gb_screen_columns( Environment * _environment, char * _columns );

void gb_sprite_data_from( Environment * _environment, char * _sprite, char * _address );
void gb_sprite_data_set( Environment * _environment, char * _sprite, char * _address );
void gb_sprite_enable( Environment * _environment, char *_sprite );
void gb_sprite_disable( Environment * _environment, char * _sprite );
void gb_sprite_at( Environment * _environment, char * _sprite, char * _x, char * _y );
void gb_sprite_expand_vertical( Environment * _environment, char * _sprite );
void gb_sprite_expand_horizontal( Environment * _environment, char * _sprite );
void gb_sprite_compress_vertical( Environment * _environment, char * _sprite );
void gb_sprite_compress_horizontal( Environment * _environment, char * _sprite );
void gb_sprite_multicolor( Environment * _environment, char * _sprite );
void gb_sprite_monocolor( Environment * _environment, char * _sprite );
void gb_sprite_color( Environment * _environment, char * _sprite, char * _color );
void gb_sprite_priority( Environment * _environment, char * _sprite, char * _priority );
void gb_vertical_scroll( Environment * _environment, char * _displacement );
void gb_horizontal_scroll( Environment * _environment, char * _displacement );
void gb_busy_wait( Environment * _environment, char * _timing );

void gb_tiles_get( Environment * _environment, char * _result );
void gb_get_width( Environment * _environment, char * _result );
void gb_get_height( Environment * _environment, char * _result );

void gb_pset_int( Environment * _environment, int _x, int _y, int *_c );
void gb_pset_vars( Environment * _environment, char *_x, char *_y, char *_c );
void gb_pget_color_vars( Environment * _environment, char *_x, char *_y, char * _result );
void gb_cls( Environment * _environment );
void gb_scroll_text( Environment * _environment, int _direction, int _overlap );
void gb_hscroll_line( Environment * _environment, int _direction, int _overlap );
void gb_hscroll_screen( Environment * _environment, int _direction, int _overlap );
void gb_text( Environment * _environment, char * _text, char * _text_size, int _raw );
void gb_cline( Environment * _environment, char * _characters );
void gb_scroll( Environment * _environment, int _dx, int _dy );

Variable * gb_get_raster_line( Environment * _environment );

int gb_image_size( Environment * _environment, int _width, int _height, int _mode );
Variable * gb_image_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, int _offset_x, int _offset_y, int _frame_width, int _frame_height, int _mode, int _transparent_color, int _flags );
Variable * gb_sprite_converter( Environment * _environment, char * _data, int _width, int _height, int _depth, RGBi * _color, int _slot_x, int _slot_y );
void gb_put_image( Environment * _environment, Resource * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _flags );
void gb_blit_image( Environment * _environment, char * _sources[], int _source_count, char * _blit, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _flags );
void gb_wait_vbl( Environment * _environment, char * _raster_line );
Variable * gb_new_image( Environment * _environment, int _width, int _height, int _mode );
Variable * gb_new_images( Environment * _environment, int _frames, int _width, int _height, int _mode );
Variable * gb_new_sequence( Environment * _environment, int _sequences, int _frames, int _width, int _height, int _mode );
void gb_get_image( Environment * _environment, char * _image, char * _x, char * _y, char * _frame, char * _sequence, int _frame_size, int _frame_count, int _palette );

void gb_put_tile( Environment * _environment, char * _image, char * _x, char * _y );
void gb_put_tiles( Environment * _environment, char * _image, char * _x, char * _y, char *_w, char *_h );
void gb_move_tiles( Environment * _environment, char * _image, char * _x, char * _y );
void gb_use_tileset( Environment * _environment, char * _tileset );
void gb_tile_at( Environment * _environment, char * _x, char * _y, char *_result );

void gb_move_memory_video( Environment * _environment, char * _from, char * _to, char * _size );
void gb_move_video_memory( Environment * _environment, char * _from, char * _to, char * _size );
void gb_move_video_video( Environment * _environment, char * _from, char * _to, char * _size );

typedef void (*CpcSliceImageFunction)(Environment *, char *, char *, char *, int, int, char *);

void gb_slice_image_copy( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination );
void gb_slice_image_extract( Environment * _environment, char * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _destination );
void gb_sys_call( Environment * _environment, int _destination );
int gb_palette_extract( Environment * _environment, char * _data, int _width, int _height, int _depth, int _flags, RGBi * _palette );
void gb_calculate_sequence_frame_offset( Environment * _environment, char * _offset, char * _sequence, char * _frame, int _frame_size, int _frame_count );

void gb_flip_image( Environment * _environment, Resource * _image, char * _frame, char * _sequence, int _frame_size, int _frame_count, char * _direction );

void gb_start( Environment * _environment, int _channel );
void gb_set_volume( Environment * _environment, int _channel, int _volume );
void gb_set_program( Environment * _environment, int _channel, int _program );
void gb_set_parameter( Environment * _environment, int _channel, int _parameter, int _value );
void gb_set_frequency( Environment * _environment, int _channel, int _frequency );
void gb_set_pitch( Environment * _environment, int _channel, int _pitch );
void gb_set_note( Environment * _environment, int _channel, int _note );
void gb_stop( Environment * _environment, int _channel );
void gb_set_duration( Environment * _environment, int _channel, int _duration );
void gb_wait_duration( Environment * _environment, int _channel );

void gb_start_var( Environment * _environment, char * _channel );
void gb_set_volume_semi_var( Environment * _environment, char * _channel, int _volume );
void gb_set_volume_vars( Environment * _environment, char * _channel, char * _volume );
void gb_set_program_semi_var( Environment * _environment, char * _channel, int _program );
void gb_set_frequency_vars( Environment * _environment, char * _channel, char * _frequency );
void gb_set_pitch_vars( Environment * _environment, char * _channel, char * _pitch );
void gb_set_note_vars( Environment * _environment, char * _channel, char * _note );
void gb_stop_vars( Environment * _environment, char * _channel );
void gb_set_duration_vars( Environment * _environment, char * _channel, char * _duration );
void gb_wait_duration_vars( Environment * _environment, char * _channel );

void gb_music( Environment * _environment, char * _music, int _size, int _loop );

#endif