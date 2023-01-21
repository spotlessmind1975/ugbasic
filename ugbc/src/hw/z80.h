#ifndef __UGBC_Z80__
#define __UGBC_Z80__

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

void z80_beq( Environment * _environment, char * _label );
void z80_bneq( Environment * _environment, char * _label );
void z80_busy_wait( Environment * _environment, char * _timing );
void z80_bveq( Environment * _environment, char * _value, char * _label );
void z80_bvneq( Environment * _environment, char * _value, char * _label );
void z80_di( Environment * _environment );
void z80_ei( Environment * _environment );
void z80_inc( Environment * _environment, char * _variable );
void z80_dec( Environment * _environment, char * _variable );
void z80_combine_nibbles( Environment * _environment, char * _low_nibble, char * _hi_nibble, char * _byte );
void z80_compare_16bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _positive );
void z80_compare_32bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _positive );
void z80_compare_8bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _positive );
void z80_compare_and_branch_16bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive );
void z80_compare_and_branch_32bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive );
void z80_compare_and_branch_8bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive );
void z80_less_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void z80_less_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void z80_less_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void z80_less_than_16bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _equal, int _signed );
void z80_less_than_32bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _equal, int _signed );
void z80_less_than_8bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _equal, int _signed );
void z80_greater_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void z80_greater_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void z80_greater_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void z80_fill( Environment * _environment, char * _address, char * _bytes, char * _pattern );
void z80_fill_size( Environment * _environment, char * _address, int _bytes, char * _pattern );
void z80_fill_size_value( Environment * _environment, char * _address, int _bytes, int _pattern );
void z80_fill_direct( Environment * _environment, char * _address, char * _bytes, char * _pattern );
void z80_fill_direct_size( Environment * _environment, char * _address, int _bytes, char * _pattern );
void z80_fill_direct_size_value( Environment * _environment, char * _address, int _bytes, int _pattern );
void z80_fill_blocks( Environment * _environment, char * _address, char * _blocks, char * _pattern );
void z80_halt( Environment * _environment );
void z80_end( Environment * _environment );
void z80_jump( Environment * _environment, char * _label );
void z80_call( Environment * _environment, char * _label );
void z80_return( Environment * _environment );
void z80_pop( Environment * _environment );
void z80_label( Environment * _environment, char * _label );
void z80_limit_16bit( Environment * _environment, char * _variable, int _value );
void z80_logical_and_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void z80_logical_or_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void z80_logical_not_8bit( Environment * _environment, char * _value, char * _result );
void z80_is_negative( Environment * _environment, char * _value, char * _result );
void z80_and_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void z80_or_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void z80_xor_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void z80_not_8bit( Environment * _environment, char * _value, char * _result );
void z80_swap_8bit( Environment * _environment, char * _left, char * _right );
void z80_and_16bit( Environment * _environment, char * _left, char * _right, char * _result );
void z80_or_16bit( Environment * _environment, char * _left, char * _right, char * _result );
void z80_xor_16bit( Environment * _environment, char * _left, char * _right, char * _result );
void z80_not_16bit( Environment * _environment, char * _value, char * _result );
void z80_swap_16bit( Environment * _environment, char * _left, char * _right );
void z80_and_32bit( Environment * _environment, char * _left, char * _right, char * _result );
void z80_or_32bit( Environment * _environment, char * _left, char * _right, char * _result );
void z80_xor_32bit( Environment * _environment, char * _left, char * _right, char * _result );
void z80_not_32bit( Environment * _environment, char * _value, char * _result );
void z80_swap_32bit( Environment * _environment, char * _left, char * _right );
void z80_math_add_16bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void z80_math_add_16bit_const( Environment * _environment, char *_source, int _destination,  char *_name );
void z80_math_add_16bit_with_16bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void z80_math_add_32bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void z80_math_add_32bit_const( Environment * _environment, char *_source, int _destination,  char *_name );
void z80_math_add_8bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void z80_math_add_8bit_const( Environment * _environment, char *_source, int _destination,  char *_name );
void z80_math_and_const_16bit( Environment * _environment, char *_source, int _mask );
void z80_math_and_const_32bit( Environment * _environment, char *_source, int _mask );
void z80_math_and_const_8bit( Environment * _environment, char *_source, int _mask );
void z80_math_complement_const_16bit( Environment * _environment, char *_source, int _value );
void z80_math_complement_const_32bit( Environment * _environment, char *_source, int _value );
void z80_math_complement_const_8bit( Environment * _environment, char *_source, int _value );
void z80_math_div2_8bit( Environment * _environment, char *_source, int _steps, int _signed );
void z80_math_div2_const_16bit( Environment * _environment, char *_source, int _value, int _signed );
void z80_math_div2_const_32bit( Environment * _environment, char *_source, int _value, int _signed );
void z80_math_div2_const_8bit( Environment * _environment, char *_source, int _value, int _signed );
void z80_math_double_16bit( Environment * _environment, char *_source, char *_name, int _signed );
void z80_math_double_32bit( Environment * _environment, char *_source, char *_name, int _signed );
void z80_math_double_8bit( Environment * _environment, char *_source, char *_name, int _signed );
void z80_math_mul_16bit_to_32bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _signed );
void z80_math_mul_8bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _signed );
void z80_math_mul2_const_16bit( Environment * _environment, char *_source, int _value, int _signed );
void z80_math_mul2_const_32bit( Environment * _environment, char *_source, int _value, int _signed );
void z80_math_mul2_const_8bit( Environment * _environment, char *_source, int _value, int _signed );
void z80_math_div_32bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed );
void z80_math_div_16bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed );
void z80_math_div_8bit_to_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed );
void z80_math_sub_16bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void z80_math_sub_32bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void z80_math_sub_8bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void z80_move_16bit( Environment * _environment, char *_source, char *_destination );
void z80_addressof_16bit( Environment * _environment, char *_source, char *_destination );
void z80_move_32bit( Environment * _environment, char *_source, char *_destination );
void z80_move_8bit( Environment * _environment, char *_source, char *_destination );
void z80_move_8bit_indirect_with_offset( Environment * _environment, char *_source, char *_destination, int _offset );
void z80_peek( Environment * _environment, char * _address, char * _target );
void z80_poke( Environment * _environment, char * _address, char * _value );
void z80_port_out( Environment * _environment, char * _port, char * _value );
void z80_random( Environment * _environment, char * _entropy );
void z80_random_16bit( Environment * _environment, char * _entropy, char * _result );
void z80_random_32bit( Environment * _environment, char * _entropy, char * _result );
void z80_random_8bit( Environment * _environment, char * _entropy, char * _result );
void z80_store_16bit( Environment * _environment, char *_source, int _value );
void z80_store_32bit( Environment * _environment, char *_source, int _value );
void z80_store_8bit( Environment * _environment, char *_source, int _value );
void z80_store_8bit_with_offset( Environment * _environment, char *_source, int _value, int _offset );
void z80_compare_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal );
void z80_compare_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal );
void z80_less_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal );
void z80_less_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal );
void z80_greater_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal );
void z80_greater_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal );
void z80_inc_16bit( Environment * _environment, char * _variable );
void z80_dec_16bit( Environment * _environment, char * _variable );
void z80_inc_32bit( Environment * _environment, char * _variable );
void z80_mem_move( Environment * _environment, char *_source, char *_destination,  char *_size );
void z80_mem_move_16bit( Environment * _environment, char *_source, char *_destination,  char *_size );
void z80_mem_move_direct( Environment * _environment, char *_source, char *_destination,  char *_size );
void z80_mem_move_size( Environment * _environment, char *_source, char *_destination, int _size );
void z80_mem_move_direct_size( Environment * _environment, char *_source, char *_destination, int _size );
void z80_mem_move_direct_indirect_size( Environment * _environment, char *_source, char *_destination, int _size );
void z80_math_add_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other );
void z80_math_sub_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other );
void z80_uppercase( Environment * _environment, char *_source, char *_size, char *_result );
void z80_lowercase( Environment * _environment, char *_source, char *_size, char *_result );
void z80_convert_string_into_16bit( Environment * _environment, char * _string, char * _len, char * _value );
void z80_fill_indirect( Environment * _environment, char * _address, char * _size, char * _pattern );
void z80_flip( Environment * _environment, char * _source, char * _size, char * _destination );
void z80_move_8bit_indirect( Environment * _environment, char *_source, char * _value );
void z80_move_8bit_indirect2( Environment * _environment, char *_source, char * _value );
void z80_move_8bit_indirect2_8bit( Environment * _environment, char * _value, char * _offset, char *_source );
void z80_move_16bit_indirect( Environment * _environment, char *_source, char * _value );
void z80_move_16bit_indirect2( Environment * _environment, char *_source, char * _value );
void z80_move_16bit_indirect2_8bit( Environment * _environment, char * _value, char * _offset, char *_source );
void z80_move_32bit_indirect( Environment * _environment, char *_source, char * _value );
void z80_move_32bit_indirect2( Environment * _environment, char *_source, char * _value );
void z80_bit_check( Environment * _environment, char *_value, int _position, char * _result, int _bitwidth );
void z80_bit_check_extended( Environment * _environment, char *_value, char * _position, char * _result, int _bitwidth );
void z80_number_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits, int _signed );
void z80_move_8bit_indirect_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset );
void z80_dsdefine( Environment * _environment, char * _string, char * _index );
void z80_dsalloc( Environment * _environment, char * _size, char * _index );
void z80_dsfree( Environment * _environment, char * _index );
void z80_dswrite( Environment * _environment, char * _index );
void z80_dsresize( Environment * _environment, char * _index, char * _size );
void z80_dsresize_size( Environment * _environment, char * _index, int _size );
void z80_dsgc( Environment * _environment );
void z80_dsdescriptor( Environment * _environment, char * _index, char * _address, char * _size );
void z80_move_8bit_indirect_with_offset( Environment * _environment, char *_source, char * _value, int _offset );
void z80_dsalloc_size( Environment * _environment, int _size, char * _index );
void z80_bits_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits );
void z80_hex_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits );
void z80_move_8bit_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset );
void z80_complement2_8bit( Environment * _environment, char * _source, char * _destination );
void z80_complement2_16bit( Environment * _environment, char * _source, char * _destination );
void z80_complement2_32bit( Environment * _environment, char * _source, char * _destination );
void z80_mobinit( Environment * _environment, char * _index, char *_x, char *_y, char *_draw);
void z80_mobshow( Environment * _environment, char * _index );
void z80_mobhide( Environment * _environment, char * _index );
void z80_mobat( Environment * _environment, char * _index, char *_x, char *_y );
void z80_mobrender( Environment * _environment, int _on_vbl );
void z80_mobcount( Environment * _environment, char * _index);
void z80_sqroot( Environment * _environment, char * _number, char * _result );
void z80_dstring_vars( Environment * _environment );
void z80_out( Environment * _environment, char * _port, char * _value );
void z80_in( Environment * _environment, char * _port, char * _value );

void z80_protothread_loop( Environment * _environment );
void z80_protothread_register_at( Environment * _environment, char * _index, char * _label );
void z80_protothread_register( Environment * _environment, char * _label, char * _index );
void z80_protothread_unregister( Environment * _environment, char * _index );
void z80_protothread_save( Environment * _environment, char * _index, int _step );
void z80_protothread_restore( Environment * _environment, char * _index, char * _step );
void z80_protothread_set_state( Environment * _environment, char * _index, int _state );
void z80_protothread_get_state( Environment * _environment, char * _index, char * _state );
void z80_protothread_current( Environment * _environment, char * _current );
void z80_set_callback( Environment * _environment, char * _callback, char * _label );

void z80_msc1_uncompress_direct_direct( Environment * _environment, char * _input, char * _output );
void z80_msc1_uncompress_direct_indirect( Environment * _environment, char * _input, char * _output );
void z80_msc1_uncompress_indirect_direct( Environment * _environment, char * _input, char * _output );
void z80_msc1_uncompress_indirect_indirect( Environment * _environment, char * _input, char * _output );

#define cpu_beq( _environment,  _label  ) z80_beq( _environment,  _label  )
#define cpu_bneq( _environment,  _label  ) z80_beq( _environment,  _label  )
#define cpu_busy_wait( _environment,  _timing  ) z80_busy_wait( _environment,  _timing  )
#define cpu_bveq( _environment,  _value,  _label  ) z80_bveq( _environment,  _value,  _label  )
#define cpu_bvneq( _environment,  _value,  _label  ) z80_bvneq( _environment,  _value,  _label  )
#define cpu_combine_nibbles( _environment,  _low_nibble,  _hi_nibble,  _byte  ) z80_combine_nibbles( _environment,  _low_nibble,  _hi_nibble,  _byte  )
#define cpu_compare_16bit( _environment, _source, _destination, _name, _positive ) z80_compare_16bit( _environment, _source, _destination, _name, _positive )
#define cpu_compare_32bit( _environment, _source, _destination, _name, _positive ) z80_compare_32bit( _environment, _source, _destination, _name, _positive )
#define cpu_compare_8bit( _environment, _source, _destination, _name, _positive ) z80_compare_8bit( _environment, _source, _destination, _name, _positive )
#define cpu_compare_and_branch_16bit_const( _environment, _source, _destination, _name, _positive ) z80_compare_and_branch_16bit_const( _environment, _source, _destination, _name, _positive )
#define cpu_compare_and_branch_32bit_const( _environment, _source, _destination, _name, _positive ) z80_compare_and_branch_32bit_const( _environment, _source, _destination, _name, _positive )
#define cpu_compare_and_branch_8bit_const( _environment, _source, _destination, _name, _positive ) z80_compare_and_branch_8bit_const( _environment, _source, _destination, _name, _positive )
#define cpu_di( _environment  ) z80_di( _environment  )
#define cpu_ei( _environment  ) z80_ei( _environment  )
#define cpu_inc( _environment, _variable ) z80_inc( _environment, _variable );
#define cpu_dec( _environment, _variable ) z80_dec( _environment, _variable );
#define cpu_less_than_16bit( _environment, _source, _destination, _name, _equal, _signed ) z80_less_than_16bit( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_less_than_32bit( _environment, _source, _destination, _name, _equal, _signed  ) z80_less_than_32bit( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_less_than_8bit( _environment, _source, _destination, _name, _equal, _signed  ) z80_less_than_8bit( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_less_than_16bit_const( _environment, _source, _destination, _name, _equal, _signed ) z80_less_than_16bit_const( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_less_than_32bit_const( _environment, _source, _destination, _name, _equal, _signed  ) z80_less_than_32bit_const( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_less_than_8bit_const( _environment, _source, _destination, _name, _equal, _signed  ) z80_less_than_8bit_const( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_greater_than_16bit( _environment, _source, _destination, _name, _equal, _signed  ) z80_greater_than_16bit( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_greater_than_32bit( _environment, _source, _destination, _name, _equal, _signed  ) z80_greater_than_32bit( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_greater_than_8bit( _environment, _source, _destination, _name, _equal, _signed  ) z80_greater_than_8bit( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_fill( _environment,  _address,  _bytes,  _pattern  ) z80_fill( _environment,  _address, _bytes,  _pattern  )
#define cpu_fill_size( _environment,  _address,  _bytes,  _pattern  ) z80_fill_size( _environment,  _address, _bytes,  _pattern  )
#define cpu_fill_size_value( _environment,  _address,  _bytes,  _pattern  ) z80_fill_size_value( _environment,  _address, _bytes,  _pattern  )
#define cpu_fill_direct( _environment,  _address,  _bytes,  _pattern  ) z80_fill_direct( _environment,  _address, _bytes,  _pattern  )
#define cpu_fill_direct_size( _environment,  _address,  _bytes,  _pattern  ) z80_fill_direct_size( _environment,  _address, _bytes,  _pattern  )
#define cpu_fill_direct_size_value( _environment,  _address,  _bytes,  _pattern  ) z80_fill_direct_size_value( _environment,  _address, _bytes,  _pattern  )
#define cpu_fill_blocks( _environment,  _address,  _blocks,  _pattern  ) z80_fill_blocks( _environment,  _address,  _blocks,  _pattern  )
#define cpu_halt( _environment  ) z80_halt( _environment  )
#define cpu_end( _environment  ) z80_end( _environment  )
#define cpu_jump( _environment,  _label  ) z80_jump( _environment,  _label  )
#define cpu_call( _environment,  _label  ) z80_call( _environment,  _label  )
#define cpu_return( _environment ) z80_return( _environment  )
#define cpu_pop( _environment ) z80_pop( _environment  )
#define cpu_label( _environment,  _label  ) z80_label( _environment,  _label  )
#define cpu_limit_16bit( _environment,  _variable, _value  ) z80_limit_16bit( _environment,  _variable, _value  )
#define cpu_logical_and_8bit( _environment, _left, _right,  _result ) z80_logical_and_8bit( _environment, _left, _right,  _result )
#define cpu_logical_or_8bit( _environment, _left, _right,  _result ) z80_logical_or_8bit( _environment, _left, _right,  _result )
#define cpu_logical_not_8bit( _environment, _value,  _result ) z80_logical_not_8bit( _environment, _value,  _result )
#define cpu_is_negative( _environment, _value, _result ) z80_is_negative( _environment, _value, _result )
#define cpu_and_8bit( _environment, _left, _right,  _result ) z80_and_8bit( _environment, _left, _right,  _result )
#define cpu_or_8bit( _environment, _left, _right,  _result ) z80_or_8bit( _environment, _left, _right,  _result )
#define cpu_xor_8bit( _environment, _left, _right,  _result ) z80_xor_8bit( _environment, _left, _right,  _result )
#define cpu_not_8bit( _environment, _value,  _result ) z80_not_8bit( _environment, _value,  _result )
#define cpu_swap_8bit( _environment, _value,  _result ) z80_swap_8bit( _environment, _value,  _result )
#define cpu_and_16bit( _environment, _left, _right,  _result ) z80_and_16bit( _environment, _left, _right,  _result )
#define cpu_or_16bit( _environment, _left, _right,  _result ) z80_or_16bit( _environment, _left, _right,  _result )
#define cpu_xor_16bit( _environment, _left, _right,  _result ) z80_xor_16bit( _environment, _left, _right,  _result )
#define cpu_not_16bit( _environment, _value,  _result ) z80_not_16bit( _environment, _value,  _result )
#define cpu_swap_16bit( _environment, _value,  _result ) z80_swap_16bit( _environment, _value,  _result )
#define cpu_and_32bit( _environment, _left, _right,  _result ) z80_and_32bit( _environment, _left, _right,  _result )
#define cpu_or_32bit( _environment, _left, _right,  _result ) z80_or_32bit( _environment, _left, _right,  _result )
#define cpu_xor_32bit( _environment, _left, _right,  _result ) z80_xor_32bit( _environment, _left, _right,  _result )
#define cpu_not_32bit( _environment, _value,  _result ) z80_not_32bit( _environment, _value,  _result )
#define cpu_swap_32bit( _environment, _value,  _result ) z80_swap_32bit( _environment, _value,  _result )
#define cpu_math_add_16bit( _environment, _source, _destination,  _name  ) z80_math_add_16bit( _environment, _source, _destination,  _name  )
#define cpu_math_add_16bit_const( _environment, _source, _destination,  _name  ) z80_math_add_16bit_const( _environment, _source, _destination,  _name  )
#define cpu_math_add_16bit_with_16bit( _environment, _source, _destination,  _name  ) z80_math_add_16bit_with_16bit( _environment, _source, _destination,  _name  )
#define cpu_math_add_32bit( _environment, _source, _destination,  _name  ) z80_math_add_32bit( _environment, _source, _destination,  _name  )
#define cpu_math_add_32bit_const( _environment, _source, _destination,  _name  ) z80_math_add_32bit_const( _environment, _source, _destination,  _name  )
#define cpu_math_add_8bit( _environment, _source, _destination,  _name  ) z80_math_add_8bit( _environment, _source, _destination,  _name  )
#define cpu_math_add_8bit_const( _environment, _source, _destination,  _name  ) z80_math_add_8bit_const( _environment, _source, _destination,  _name  )
#define cpu_math_and_const_16bit( _environment, _source, _mask  ) z80_math_and_const_16bit( _environment, _source, _mask  )
#define cpu_math_and_const_32bit( _environment, _source, _mask  ) z80_math_and_const_32bit( _environment, _source, _mask  )
#define cpu_math_and_const_8bit( _environment, _source, _mask  ) z80_math_and_const_8bit( _environment, _source, _mask  )
#define cpu_math_complement_const_16bit( _environment, _source, _value  ) z80_math_complement_const_16bit( _environment, _source, _value  )
#define cpu_math_complement_const_32bit( _environment, _source, _value  ) z80_math_complement_const_32bit( _environment, _source, _value  )
#define cpu_math_complement_const_8bit( _environment, _source, _value  ) z80_math_complement_const_8bit( _environment, _source, _value  )
#define cpu_math_div2_8bit( _environment, _source, _steps, _signed  ) z80_math_div2_8bit( _environment, _source, _steps, _signed  )
#define cpu_math_div2_const_16bit( _environment, _source, _value, _signed  ) z80_math_div2_const_16bit( _environment, _source, _value, _signed  )
#define cpu_math_div2_const_32bit( _environment, _source, _value, _signed  ) z80_math_div2_const_32bit( _environment, _source, _value, _signed  )
#define cpu_math_div2_const_8bit( _environment, _source, _value, _signed  ) z80_math_div2_const_8bit( _environment, _source, _value, _signed  )
#define cpu_math_double_16bit( _environment, _source, _name, _signed  ) z80_math_double_16bit( _environment, _source, _name, _signed  )
#define cpu_math_double_32bit( _environment, _source, _name, _signed  ) z80_math_double_32bit( _environment, _source, _name, _signed  )
#define cpu_math_double_8bit( _environment, _source, _name, _signed  ) z80_math_double_8bit( _environment, _source, _name, _signed  )
#define cpu_math_mul_16bit_to_32bit( _environment, _source, _destination,  _name, _signed  ) z80_math_mul_16bit_to_32bit( _environment, _source, _destination,  _name, _signed  )
#define cpu_math_mul_8bit_to_16bit( _environment, _source, _destination,  _name, _signed  ) z80_math_mul_8bit_to_16bit( _environment, _source, _destination,  _name, _signed  )
#define cpu_math_mul2_const_16bit( _environment, _source, _value, _signed  ) z80_math_mul2_const_16bit( _environment, _source, _value, _signed  )
#define cpu_math_mul2_const_32bit( _environment, _source, _value, _signed  ) z80_math_mul2_const_32bit( _environment, _source, _value, _signed  )
#define cpu_math_mul2_const_8bit( _environment, _source, _value, _signed  ) z80_math_mul2_const_8bit( _environment, _source, _value, _signed  )
#define cpu_math_sub_16bit( _environment, _source, _destination,  _name  ) z80_math_sub_16bit( _environment, _source, _destination,  _name  )
#define cpu_math_sub_32bit( _environment, _source, _destination,  _name  ) z80_math_sub_32bit( _environment, _source, _destination,  _name  )
#define cpu_math_sub_8bit( _environment, _source, _destination,  _name  ) z80_math_sub_8bit( _environment, _source, _destination,  _name  )
#define cpu_move_16bit( _environment, _source, _destination  ) z80_move_16bit( _environment, _source, _destination  )
#define cpu_addressof_16bit( _environment, _source, _destination  ) z80_addressof_16bit( _environment, _source, _destination  )
#define cpu_move_32bit( _environment, _source, _destination  ) z80_move_32bit( _environment, _source, _destination  )
#define cpu_move_8bit( _environment, _source, _destination  ) z80_move_8bit( _environment, _source, _destination  )
#define cpu_peek( _environment,  _address,  _target  ) z80_peek( _environment,  _address,  _target  )
#define cpu_poke( _environment,  _address,  _value  ) z80_poke( _environment,  _address,  _value  )
#define cpu_random( _environment,  _entropy  ) z80_random( _environment,  _entropy  )
#define cpu_random_16bit( _environment,  _entropy,  _result  ) z80_random_16bit( _environment,  _entropy,  _result  )
#define cpu_random_32bit( _environment,  _entropy,  _result  ) z80_random_32bit( _environment,  _entropy,  _result  )
#define cpu_random_8bit( _environment,  _entropy,  _result  ) z80_random_8bit( _environment,  _entropy,  _result  )
#define cpu_store_16bit( _environment, _source, _value  ) z80_store_16bit( _environment, _source, _value  )
#define cpu_store_32bit( _environment, _source, _value  ) z80_store_32bit( _environment, _source, _value  )
#define cpu_store_8bit( _environment, _source, _value  ) z80_store_8bit( _environment, _source, _value  )
#define cpu_compare_memory( _environment, _source, _destination, _size, _result, _equal ) z80_compare_memory( _environment, _source, _destination, _size, _result, _equal )
#define cpu_compare_memory_size( _environment, _source, _destination, _size, _result, _equal ) z80_compare_memory_size( _environment, _source, _destination, _size, _result, _equal )
#define cpu_less_than_memory( _environment, _source, _destination, _size, _result, _equal ) z80_less_than_memory( _environment, _source, _destination,  _size, _result, _equal )
#define cpu_less_than_memory_size( _environment, _source, _destination, _size, _result, _equal ) z80_less_than_memory_size( _environment, _source, _destination,  _size, _result, _equal )
#define cpu_greater_than_memory( _environment, _source, _destination, _size, _result, _equal ) z80_greater_than_memory( _environment, _source, _destination, _size, _result, _equal )
#define cpu_greater_than_memory_size( _environment, _source, _destination, _size, _result, _equal ) z80_greater_than_memory_size( _environment, _source, _destination, _size, _result, _equal )
#define cpu_inc_16bit( _environment, _variable ) z80_inc_16bit( _environment, _variable )
#define cpu_dec_16bit( _environment, _variable ) z80_dec_16bit( _environment, _variable )
#define cpu_inc_32bit( _environment, _variable ) z80_inc_32bit( _environment, _variable )
#define cpu_mem_move( _environment, _source, _destination,  _size ) z80_mem_move( _environment, _source, _destination, _size )
#define cpu_mem_move_16bit( _environment, _source, _destination,  _size ) z80_mem_move_16bit( _environment, _source, _destination, _size )
#define cpu_mem_move_direct( _environment, _source, _destination,  _size ) z80_mem_move_direct( _environment, _source, _destination, _size )
#define cpu_mem_move_size( _environment, _source, _destination,  _size ) z80_mem_move_size( _environment, _source, _destination, _size )
#define cpu_mem_move_direct_size( _environment, _source, _destination,  _size ) z80_mem_move_direct_size( _environment, _source, _destination, _size )
#define cpu_mem_move_direct_indirect_size( _environment, _source, _destination,  _size ) z80_mem_move_direct_indirect_size( _environment, _source, _destination, _size )
#define cpu_math_add_16bit_with_8bit( _environment, _source, _destination, _other ) z80_math_add_16bit_with_8bit( _environment, _source, _destination, _other )
#define cpu_math_sub_16bit_with_8bit( _environment, _source, _destination, _other ) z80_math_sub_16bit_with_8bit( _environment, _source, _destination, _other )
#define cpu_uppercase( _environment, _source, _size, _result ) z80_uppercase( _environment, _source, _size, _result )
#define cpu_lowercase( _environment, _source, _size, _result ) z80_lowercase( _environment, _source, _size, _result )
#define cpu_convert_string_into_16bit( _environment, _string, _len, _value ) z80_convert_string_into_16bit( _environment, _string, _len, _value )
#define cpu_fill_indirect( _environment, _address, _size, _pattern ) z80_fill_indirect( _environment, _address, _size, _pattern )
#define cpu_flip( _environment, _source, _size, _destination ) z80_flip( _environment, _source, _size, _destination )
#define cpu_move_8bit_indirect( _environment, _source, _value ) z80_move_8bit_indirect( _environment, _source, _value )
#define cpu_move_8bit_indirect2( _environment, _source, _value ) z80_move_8bit_indirect2( _environment, _source, _value )
#define cpu_move_8bit_indirect2_8bit( _environment, _value, _offset, _source ) z80_move_8bit_indirect2_8bit(  _environment, _value, _offset, _source )
#define cpu_move_16bit_indirect( _environment, _source, _value ) z80_move_16bit_indirect( _environment, _source, _value )
#define cpu_move_16bit_indirect2( _environment, _source, _value ) z80_move_16bit_indirect2( _environment, _source, _value )
#define cpu_move_16bit_indirect2_8bit( _environment, _value, _offset, _source ) z80_move_16bit_indirect2_8bit(  _environment, _value, _offset, _source )
#define cpu_move_32bit_indirect( _environment, _source, _value ) z80_move_32bit_indirect( _environment, _source, _value )
#define cpu_move_32bit_indirect2( _environment, _source, _value ) z80_move_32bit_indirect2( _environment, _source, _value )
#define cpu_math_div_32bit_to_16bit( _environment, _source, _destination,  _other, _other_remainder, _signed  ) z80_math_div_32bit_to_16bit( _environment, _source, _destination, _other, _other_remainder, _signed )
#define cpu_math_div_16bit_to_16bit( _environment, _source, _destination,  _other, _other_remainder, _signed  ) z80_math_div_16bit_to_16bit( _environment, _source, _destination, _other, _other_remainder, _signed )
#define cpu_math_div_8bit_to_8bit( _environment, _source, _destination,   _other, _other_remainder, _signed  ) z80_math_div_8bit_to_8bit( _environment, _source, _destination,  _other, _other_remainder, _signed )
#define cpu_bit_check( _environment, _value, _position, _result, _bitwidth ) z80_bit_check( _environment, _value, _position, _result, _bitwidth )
#define cpu_number_to_string( _environment, _number, _string, _string_size, _bits, _signed ) z80_number_to_string( _environment, _number, _string, _string_size, _bits, _signed )
#define cpu_move_8bit_indirect_with_offset2( _environment, _source, _value, _offset ) z80_move_8bit_indirect_with_offset2( _environment, _source, _value, _offset )
#define cpu_store_8bit_with_offset( _environment, _source, _value, _offset ) z80_store_8bit_with_offset( _environment, _source, _value, _offset )
#define cpu_move_8bit_indirect_with_offset( _environment, _source, _destination, _offset ) z80_move_8bit_indirect_with_offset( _environment, _source, _destination, _offset )
#define cpu_dsdefine( _environment, _string, _index ) z80_dsdefine( _environment, _string, _index )
#define cpu_dsalloc( _environment, _size, _index ) z80_dsalloc( _environment, _size, _index )
#define cpu_dsfree( _environment, _index ) z80_dsfree( _environment, _index )
#define cpu_dswrite( _environment, _index ) z80_dswrite( _environment, _index )
#define cpu_dsresize( _environment, _index, _size ) z80_dsresize( _environment, _index, _size )
#define cpu_dsresize_size( _environment, _index, _size ) z80_dsresize_size( _environment, _index, _size )
#define cpu_dsgc( _environment ) z80_dsgc( _environment )
#define cpu_dsdescriptor( _environment, _index, _address, _size ) z80_dsdescriptor( _environment, _index, _address, _size )
#define cpu_dsalloc_size( _environment, _size, _index ) z80_dsalloc_size( _environment, _size, _index ) 
#define cpu_bit_check_extended( _environment, _value, _position, _result, _bitwidth ) z80_bit_check_extended( _environment, _value, _position, _result, _bitwidth )
#define cpu_bits_to_string( _environment, _number, _string, _string_size, _bits ) z80_bits_to_string( _environment, _number, _string, _string_size, _bits )
#define cpu_hex_to_string( _environment, _number, _string, _string_size, _bits ) z80_hex_to_string( _environment, _number, _string, _string_size, _bits )
#define cpu_move_8bit_with_offset2( _environment, _source, _value, _offset ) z80_move_8bit_with_offset2( _environment, _source, _value, _offset ) 
#define cpu_complement2_8bit( _environment, _source, _destination ) z80_complement2_8bit( _environment, _source, _destination )
#define cpu_complement2_16bit( _environment, _source, _destination ) z80_complement2_16bit( _environment, _source, _destination )
#define cpu_complement2_32bit( _environment, _source, _destination ) z80_complement2_32bit( _environment, _source, _destination )
#define cpu_set_callback( _environment, _callback, _label ) z80_set_callback( _environment, _callback, _label )
#define cpu_in( _environment, _port, _value ) z80_in( _environment, _port, _value )
#define cpu_out( _environment, _port, _value ) z80_out( _environment, _port, _value )

extern char * src_hw_chipset_mob_asm;
extern unsigned int src_hw_chipset_mob_asm_len;

#define cpu_mobinit( _environment, _index, _x, _y, _draw ) z80_mobinit( _environment, _index, _x, _y, _draw )
#define cpu_mobshow( _environment, _index ) z80_mobshow( _environment, _index )
#define cpu_mobhide( _environment, _index ) z80_mobhide( _environment, _index )
#define cpu_mobat( _environment, _index, _x, _y ) z80_mobat( _environment, _index, _x, _y )
#define cpu_mobrender( _environment, _on_vbl ) z80_mobrender( _environment, _on_vbl )
#define cpu_mobcount( _environment, _index ) z80_mobcount( _environment, _index )
#define cpu_sqroot( _environment, _number, _result ) z80_sqroot( _environment, _number, _result )
#define cpu_dstring_vars( _environment ) z80_dstring_vars( _environment )

#define cpu_protothread_vars( _environment ) z80_protothread_vars( _environment )
#define cpu_protothread_loop( _environment ) z80_protothread_loop( _environment )
#define cpu_protothread_register( _environment, _label, _index ) z80_protothread_register( _environment, _label, _index )
#define cpu_protothread_register_at( _environment, _index, _label ) z80_protothread_register_at( _environment, _index, _label )
#define cpu_protothread_unregister(_environment, _index ) z80_protothread_unregister(_environment, _index )
#define cpu_protothread_save( _environment, _index, _step ) z80_protothread_save( _environment, _index, _step )
#define cpu_protothread_restore( _environment, _index, _step ) z80_protothread_restore( _environment, _index, _step )
#define cpu_protothread_set_state( _environment, _index, _state ) z80_protothread_set_state( _environment, _index, _state )
#define cpu_protothread_get_state( _environment, _index, _state ) z80_protothread_get_state( _environment, _index, _state )
#define cpu_protothread_current( _environment, _current ) z80_protothread_current( _environment, _current )

#define cpu_msc1_uncompress_direct_direct( _environment, _input, _output ) z80_msc1_uncompress_direct_direct( _environment, _input, _output )
#define cpu_msc1_uncompress_direct_indirect( _environment, _input, _output ) z80_msc1_uncompress_direct_indirect( _environment, _input, _output )
#define cpu_msc1_uncompress_indirect_direct( _environment, _input, _output ) z80_msc1_uncompress_indirect_direct( _environment, _input, _output )
#define cpu_msc1_uncompress_indirect_indirect( _environment, _input, _output ) z80_msc1_uncompress_indirect_indirect( _environment, _input, _output )

#define     CPU_LITTLE_ENDIAN      1

#endif