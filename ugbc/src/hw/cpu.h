#ifndef __UGBC_CPU__
#define __UGBC_CPU__

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

void cpu_init( Environment * _environment );

void cpu_nop( Environment * _environment );
void cpu_ztoa( Environment * _environment );
void cpu_ctoa( Environment * _environment );
void cpu_beq( Environment * _environment, char * _label );
void cpu_bneq( Environment * _environment, char * _label );
void cpu_busy_wait( Environment * _environment, char * _timing );
void cpu_bveq( Environment * _environment, char * _value, char * _label );
void cpu_bvneq( Environment * _environment, char * _value, char * _label );
void cpu_combine_nibbles( Environment * _environment, char * _low_nibble, char * _hi_nibble, char * _byte );
void cpu_compare_16bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _positive );
void cpu_compare_16bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive );
void cpu_compare_32bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _positive );
void cpu_compare_32bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive );
void cpu_compare_nbit( Environment * _environment, char *_source, char *_destination,  char *_name, int _positive, int _bits );
void cpu_compare_nbit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive, int _bits );
void cpu_compare_8bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _positive );
void cpu_compare_8bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive );
void cpu_prepare_for_compare_and_branch_8bit( Environment * _environment, char *_source );
void cpu_compare_and_branch_8bit( Environment * _environment, char *_source, char * _destination,  char *_name, int _positive );
void cpu_compare_and_branch_8bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive );
void cpu_execute_compare_and_branch_8bit_const( Environment * _environment, int _destination,  char *_name, int _positive );
void cpu_compare_and_branch_16bit( Environment * _environment, char *_source, char * _destination,  char *_name, int _positive );
void cpu_compare_and_branch_16bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive );
void cpu_compare_and_branch_32bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive );
void cpu_compare_and_branch_char_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive );
void cpu_di( Environment * _environment );
void cpu_ei( Environment * _environment );
void cpu_inc( Environment * _environment, char * _variable );
void cpu_inc_16bit( Environment * _environment, char * _variable );
void cpu_inc_32bit( Environment * _environment, char * _variable );
void cpu_inc_nbit( Environment * _environment, char * _variable, int _bits );
void cpu_dec( Environment * _environment, char * _variable );
void cpu_dec_16bit( Environment * _environment, char * _variable );
void cpu_dec_32bit( Environment * _environment, char * _variable );
void cpu_dec_nbit( Environment * _environment, char * _variable, int _bits );
void cpu_less_than_nbit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _bits );
void cpu_less_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void cpu_less_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void cpu_less_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void cpu_less_than_nbit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _equal, int _bits );
void cpu_less_than_16bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _equal, int _signed );
void cpu_less_than_32bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _equal, int _signed );
void cpu_less_than_8bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _equal, int _signed );
void cpu_less_than_and_branch_8bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _equal, int _signed );
void cpu_greater_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void cpu_greater_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void cpu_greater_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void cpu_greater_than_nbit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _bits );
void cpu_greater_than_16bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _equal, int _signed );
void cpu_greater_than_32bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _equal, int _signed );
void cpu_greater_than_8bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _equal, int _signed );
void cpu_greater_than_nbit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _equal, int _bits );
void cpu_fill( Environment * _environment, char * _address, char * _bytes, int _bytes_width, char * _pattern );
void cpu_fill_size( Environment * _environment, char * _address, int _bytes, char * _pattern );
void cpu_fill_size_value( Environment * _environment, char * _address, int _bytes, int _pattern );
void cpu_fill_direct( Environment * _environment, char * _address, char * _blocks, char * _pattern );
void cpu_fill_direct_size( Environment * _environment, char * _address, int _bytes, char * _pattern );
void cpu_fill_direct_size_value( Environment * _environment, char * _address, int _bytes, int _pattern );
void cpu_fill_blocks( Environment * _environment, char * _address, char * _blocks, char * _pattern );
void cpu_halt( Environment * _environment );
void cpu_end( Environment * _environment );
void cpu_jump( Environment * _environment, char * _label );
void cpu_jump_indirect( Environment * _environment, char * _value );
void cpu_call_addr( Environment * _environment, int _address );
void cpu_call( Environment * _environment, char * _label );
void cpu_call_indirect( Environment * _environment, char * _value );
void cpu_set_asmio( Environment * _environment, int _asmio, int _value );
void cpu_set_asmio_indirect( Environment * _environment, int _asmio, char * _value );
void cpu_get_asmio_indirect( Environment * _environment, int _asmio, char * _value );
int cpu_register_decode( Environment * _environment, char * _register );
void cpu_pop( Environment * _environment );
void cpu_port_out( Environment * _environment, char * _port, char * _value );
void cpu_return( Environment * _environment );
void cpu_label( Environment * _environment, char * _label );
void cpu_limit_16bit( Environment * _environment, char * _variable, int _value );
void cpu_logical_and_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void cpu_logical_or_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void cpu_logical_not_8bit( Environment * _environment, char * _value, char * _result );
void cpu_and_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void cpu_and_8bit_const( Environment * _environment, char * _left, int _right, char * _result );
void cpu_or_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void cpu_or_8bit_const( Environment * _environment, char * _left, int _right, char * _result );
void cpu_xor_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void cpu_xor_8bit_const( Environment * _environment, char * _left, int _right, char * _result );
void cpu_not_8bit( Environment * _environment, char * _value, char * _result );
void cpu_swap_8bit( Environment * _environment, char * _left, char * _right );
void cpu_and_16bit( Environment * _environment, char * _left, char * _right, char * _result );
void cpu_or_16bit( Environment * _environment, char * _left, char * _right, char * _result );
void cpu_xor_16bit( Environment * _environment, char * _left, char * _right, char * _result );
void cpu_xor_16bit_const( Environment * _environment, char * _left, int _right, char * _result );
void cpu_not_16bit( Environment * _environment, char * _value, char * _result );
void cpu_swap_16bit( Environment * _environment, char * _left, char * _right );
void cpu_and_32bit( Environment * _environment, char * _left, char * _right, char * _result );
void cpu_or_32bit( Environment * _environment, char * _left, char * _right, char * _result );
void cpu_xor_32bit( Environment * _environment, char * _left, char * _right, char * _result );
void cpu_xor_32bit_const( Environment * _environment, char * _left, int _right, char * _result );
void cpu_not_32bit( Environment * _environment, char * _value, char * _result );
void cpu_swap_32bit( Environment * _environment, char * _left, char * _right );
void cpu_math_add_nbit( Environment * _environment, char *_source, char *_destination,  char *_name, int _bits );
void cpu_math_add_nbit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _bits );
void cpu_math_add_16bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu_math_add_16bit_const( Environment * _environment, char *_source, int _destination,  char *_name );
void cpu_math_add_16bit_with_16bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu_math_add_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu_math_add_32bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu_math_add_32bit_const( Environment * _environment, char *_source, int _destination,  char *_name );
void cpu_math_add_8bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu_math_add_8bit_const( Environment * _environment, char *_source, int _destination,  char *_name );
void cpu_math_and_const_16bit( Environment * _environment, char *_source, int _mask );
void cpu_math_and_const_32bit( Environment * _environment, char *_source, int _mask );
void cpu_math_and_const_8bit( Environment * _environment, char *_source, int _mask );
void cpu_math_complement_const_16bit( Environment * _environment, char *_source, int _value );
void cpu_math_complement_const_32bit( Environment * _environment, char *_source, int _value );
void cpu_math_complement_const_8bit( Environment * _environment, char *_source, int _value );
void cpu_math_div2_const_nbit( Environment * _environment, char *_source, int _value, int _bits, char * _remainder );
void cpu_math_div2_const_16bit( Environment * _environment, char *_source, int _value, int _signed, char * _remainder );
void cpu_math_div2_const_32bit( Environment * _environment, char *_source, int _value, int _signed, char * _remainder );
void cpu_math_div2_const_8bit( Environment * _environment, char *_source, int _value, int _signed, char * _remainder );
void cpu_math_double_16bit( Environment * _environment, char *_source, char *_name, int _signed );
void cpu_math_double_32bit( Environment * _environment, char *_source, char *_name, int _signed );
void cpu_math_double_8bit( Environment * _environment, char *_source, char *_name, int _signed );
void cpu_math_mul_nbit_to_nbit( Environment * _environment, char *_source, char *_destination,  char *_name, int _bits );
void cpu_math_mul_16bit_to_32bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _signed );
void cpu_math_mul_8bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _signed );
void cpu_math_div_nbit_to_nbit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _bits );
void cpu_math_div_32bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed );
void cpu_math_div_nbit_to_nbit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _bits );
void cpu_math_div_32bit_to_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed );
void cpu_math_div_16bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed );
void cpu_math_div_16bit_to_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed );
void cpu_math_div_8bit_to_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed );
void cpu_math_div_8bit_to_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed );
void cpu_math_mul2_const_nbit( Environment * _environment, char *_source, int _value, int _bits );
void cpu_math_mul2_const_16bit( Environment * _environment, char *_source, int _value, int _signed );
void cpu_math_mul2_const_32bit( Environment * _environment, char *_source, int _value, int _signed );
void cpu_math_mul2_const_8bit( Environment * _environment, char *_source, int _value, int _signed );
void cpu_math_sub_nbit( Environment * _environment, char *_source, char *_destination,  char *_name, int _bits );
void cpu_math_sub_16bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu_math_sub_32bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu_math_sub_8bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu_math_sub_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu_move_16bit( Environment * _environment, char *_source, char *_destination );
void cpu_addressof_16bit( Environment * _environment, char *_source, char *_destination );
void cpu_move_32bit( Environment * _environment, char *_source, char *_destination );
void cpu_move_8bit( Environment * _environment, char *_source, char *_destination );

void cpu_move_8bit_signed_16bit_signed( Environment * _environment, char *_source, char *_destination );
void cpu_move_8bit_signed_16bit_unsigned( Environment * _environment, char *_source, char *_destination );
void cpu_move_8bit_unsigned_16bit_signed( Environment * _environment, char *_source, char *_destination );
void cpu_move_8bit_unsigned_16bit_unsigned( Environment * _environment, char *_source, char *_destination );

void cpu_move_8bit_signed_32bit_signed( Environment * _environment, char *_source, char *_destination );
void cpu_move_8bit_signed_32bit_unsigned( Environment * _environment, char *_source, char *_destination );
void cpu_move_8bit_unsigned_32bit_signed( Environment * _environment, char *_source, char *_destination );
void cpu_move_8bit_unsigned_32bit_unsigned( Environment * _environment, char *_source, char *_destination );

void cpu_move_16bit_signed_8bit_signed( Environment * _environment, char *_source, char *_destination );
void cpu_move_16bit_signed_8bit_unsigned( Environment * _environment, char *_source, char *_destination );
void cpu_move_16bit_unsigned_8bit_signed( Environment * _environment, char *_source, char *_destination );
void cpu_move_16bit_unsigned_8bit_unsigned( Environment * _environment, char *_source, char *_destination );

void cpu_move_16bit_signed_32bit_signed( Environment * _environment, char *_source, char *_destination );
void cpu_move_16bit_signed_32bit_unsigned( Environment * _environment, char *_source, char *_destination );
void cpu_move_16bit_unsigned_32bit_signed( Environment * _environment, char *_source, char *_destination );
void cpu_move_16bit_unsigned_32bit_unsigned( Environment * _environment, char *_source, char *_destination );

void cpu_move_32bit_signed_8bit_signed( Environment * _environment, char *_source, char *_destination );
void cpu_move_32bit_signed_8bit_unsigned( Environment * _environment, char *_source, char *_destination );
void cpu_move_32bit_unsigned_8bit_signed( Environment * _environment, char *_source, char *_destination );
void cpu_move_32bit_unsigned_8bit_unsigned( Environment * _environment, char *_source, char *_destination );

void cpu_move_32bit_signed_16bit_signed( Environment * _environment, char *_source, char *_destination );
void cpu_move_32bit_signed_16bit_unsigned( Environment * _environment, char *_source, char *_destination );
void cpu_move_32bit_unsigned_16bit_signed( Environment * _environment, char *_source, char *_destination );
void cpu_move_32bit_unsigned_16bit_unsigned( Environment * _environment, char *_source, char *_destination );

void cpu_move_nbit( Environment * _environment, int _n, char *_source, char *_destination );
void cpu_peek( Environment * _environment, char * _address, char * _target );
void cpu_poke( Environment * _environment, char * _address, char * _value );
void cpu_poke_const( Environment * _environment, char * _address, int _value );
void cpu_peekw( Environment * _environment, char * _address, char * _target );
void cpu_pokew( Environment * _environment, char * _address, char * _value );
void cpu_pokew_const( Environment * _environment, char * _address, int _value );
void cpu_peekd( Environment * _environment, char * _address, char * _target );
void cpu_poked( Environment * _environment, char * _address, char * _value );
void cpu_poked_const( Environment * _environment, char * _address, int _value );
void cpu_random( Environment * _environment, char * _entropy );
void cpu_random_16bit( Environment * _environment, char * _entropy, char * _result );
void cpu_random_32bit( Environment * _environment, char * _entropy, char * _result );
void cpu_random_8bit( Environment * _environment, char * _entropy, char * _result );
void cpu_store_char( Environment * _environment, char *_source, int _value );
void cpu_store_8bit( Environment * _environment, char *_source, int _value );
void cpu_store_16bit( Environment * _environment, char *_source, int _value );
void cpu_store_32bit( Environment * _environment, char *_source, int _value );
void cpu_store_nbit( Environment * _environment, char *_source, int _n, int _value[] );
void cpu_mem_move( Environment * _environment, char *_source, char *_destination,  char *_size );
void cpu_mem_move_16bit( Environment * _environment, char *_source, char *_destination,  char *_size );
void cpu_mem_move_direct( Environment * _environment, char *_source, char *_destination,  char *_size );
void cpu_mem_move_direct2( Environment * _environment, char *_source, char *_destination,  char *_size );
void cpu_mem_move_direct2_size( Environment * _environment, char *_source, char *_destination, int _size );
void cpu_mem_move_size( Environment * _environment, char *_source, char *_destination, int _size );
void cpu_mem_move_direct_size( Environment * _environment, char *_source, char *_destination, int _size );
void cpu_mem_move_direct_indirect_size( Environment * _environment, char *_source, char *_destination, int _size );
void cpu_mem_move_indirect_direct_size( Environment * _environment, char *_source, char *_destination, int _size );
void cpu_compare_memory( Environment * _environment, char *_source, char *_destination, char *_size, char *_result, int _equal );
void cpu_compare_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char *_result, int _equal );
void cpu_less_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char *_result, int _equal );
void cpu_less_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char *_result, int _equal );
void cpu_greater_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char *_result, int _equal );
void cpu_greater_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char *_result, int _equal );
void cpu_uppercase( Environment * _environment, char *_source, char *_size, char *_result );
void cpu_lowercase( Environment * _environment, char *_source, char *_size, char *_result );
void cpu_convert_string_into_8bit( Environment * _environment, char * _string, char * _len, char * _value );
void cpu_convert_string_into_16bit( Environment * _environment, char * _string, char * _len, char * _value );
void cpu_fill_indirect( Environment * _environment, char * _address, char * _size, char * _pattern, int _size_size );
void cpu_flip_8bit( Environment * _environment, char * _source, char * _destination );
void cpu_flip( Environment * _environment, char * _source, char * _size, char * _destination );
void cpu_move_8bit_indirect( Environment * _environment, char *_source, char * _value );
void cpu_move_8bit_indirect2( Environment * _environment, char * _value, char *_source );
void cpu_move_8bit_indirect2_8bit( Environment * _environment, char * _value, char * _offset, char *_source );
void cpu_move_8bit_indirect2_16bit( Environment * _environment, char * _value, char * _offset, char *_source );
void cpu_move_16bit_indirect( Environment * _environment, char *_source, char * _value );
void cpu_move_16bit_indirect2( Environment * _environment, char * _value, char *_source );
void cpu_move_16bit_indirect2_8bit( Environment * _environment, char * _value, char *_source, char * _index );
void cpu_move_32bit_indirect( Environment * _environment, char *_source, char * _value );
void cpu_move_32bit_indirect2( Environment * _environment, char * _value, char *_source );
void cpu_move_nbit_indirect( Environment * _environment, int _n, char *_source, char * _value );
void cpu_move_nbit_indirect2( Environment * _environment, int _n, char *_source, char * _value );
void cpu_bit_check( Environment * _environment, char * _value, int _position, char *_result, int _bitwidth );
void cpu_bit_check_extended( Environment * _environment, char * _value, char * _position, char *_result, int _bitwidth );
void cpu_bit_inplace_8bit( Environment * _environment, char * _value, int _position, int * _bit );
void cpu_bit_inplace_8bit_extended_indirect( Environment * _environment, char * address, char * _position, char * _bit );
void cpu_number_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits, int _Signed );
void cpu_bits_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits, char * _zero, char * _one );
void cpu_hex_to_string( Environment * _environment, char * _number, char * _string, char * _size, int _separator );
void cpu_hex_to_string_calc_string( Environment * _environment, char * _size, int _separator, char * _string_size );
void cpu_hex_to_string_calc_string_size( Environment * _environment, int _size, int _separator, char * _string_size );
void cpu_move_8bit_indirect_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset );
void cpu_dsdefine( Environment * _environment, char * _string, char * _index );
void cpu_dsalloc( Environment * _environment, char * _size, char * _index );
void cpu_dsfree( Environment * _environment, char * _index );
void cpu_dswrite( Environment * _environment, char * _index );
void cpu_dsresize( Environment * _environment, char * _index, char * _size );
void cpu_dsresize_size( Environment * _environment, char * _index, int _size );
void cpu_dsassign( Environment * _environment, char * _original, char * _copy );
void cpu_dsgc( Environment * _environment );
void cpu_dsinit( Environment * _environment );
void cpu_dsdescriptor( Environment * _environment, char * _index, char * _address, char * _size );
void cpu_move_8bit_indirect_with_offset( Environment * _environment, char *_source, char * _value, int _offset );
void cpu_move_8bit_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset );
void cpu_store_8bit_with_offset( Environment * _environment, char *_destination, int _value, int _offset );
void cpu_store_8bit_with_offset2( Environment * _environment, char *_destination, char * _offset, int _value  );
void cpu_dsalloc_size( Environment * _environment, int _size, char * _index );
void cpu_complement2_8bit( Environment * _environment, char * _source, char * _destination );
void cpu_complement2_16bit( Environment * _environment, char * _source, char * _destination );
void cpu_complement2_32bit( Environment * _environment, char * _source, char * _destination );
void cpu_complement2_nbit( Environment * _environment, char * _source, char * _destination, int _bits );
void cpu_sqroot( Environment * _environment, char * _number, char * _result );
void cpu_dstring_vars( Environment * _environment );
void cpu_set_callback( Environment * _environment, char * _callback, char * _label );
void cpu_out( Environment * _environment, char * _port, char * _value );
void cpu_in( Environment * _environment, char * _port, char * _value );
void cpu_out_direct( Environment * _environment, char * _port, char * _value );
void cpu_in_direct( Environment * _environment, char * _port, char * _value );
void cpu_string_sub( Environment * _environment, char * _source, char * _source_size, char * _pattern, char * _pattern_size, char * _destination, char * _destination_size );

void cpu_protothread_vars( Environment * _environment );
void cpu_protothread_loop( Environment * _environment );
void cpu_protothread_register_at( Environment * _environment, char * _index, char * _label );
void cpu_protothread_register( Environment * _environment, char * _label, char * _index );
void cpu_protothread_unregister( Environment * _environment, char * _index );
void cpu_protothread_save( Environment * _environment, char * _index, int _step );
void cpu_protothread_restore( Environment * _environment, char * _index, char * _step );
void cpu_protothread_set_state( Environment * _environment, char * _index, int _state );
void cpu_protothread_get_state( Environment * _environment, char * _index, char * _state );
void cpu_protothread_current( Environment * _environment, char * _current );
void cpu_protothread_get_address( Environment * _environment, char * _index, char * _address );

void cpu_msc1_uncompress_direct_direct( Environment * _environment, char * _input, char * _output );
void cpu_msc1_uncompress_direct_indirect( Environment * _environment, char * _input, char * _output );
void cpu_msc1_uncompress_indirect_direct( Environment * _environment, char * _input, char * _output );
void cpu_msc1_uncompress_indirect_indirect( Environment * _environment, char * _input, char * _output );

void cpu_blit_initialize( Environment * _environment );
char*cpu_blit_register_name( Environment * _environment, int _register );
int  cpu_blit_alloc_register( Environment * _environment );
void cpu_blit_free_register( Environment * _environment, int _register );
void cpu_blit_finalize( Environment * _environment );

void cpu_address_table_build( Environment * _environment, char * _table, int * _values, char *_address[], int _count );
void cpu_address_table_lookup( Environment * _environment, char * _table, int _count );
void cpu_address_table_call( Environment * _environment, char * _table, char * _value, char * _address );

// FAST FP (24 bit)

void cpu_float_fast_from_double_to_int_array( Environment * _environment, double _value, int _result[] );
void cpu_float_fast_from_int_array_to_double( Environment * _environment, int _value[], double * _result );
void cpu_float_fast_to_string( Environment * _environment, char * _x, char * _string, char * _string_size );
void cpu_float_fast_from_16( Environment * _environment, char * _value, char * _result, int _signed );
void cpu_float_fast_from_8( Environment * _environment, char * _value, char * _result, int _signed );
void cpu_float_fast_to_16( Environment * _environment, char * _value, char * _result, int _signed );
void cpu_float_fast_to_8( Environment * _environment, char * _value, char * _result, int _signed );
void cpu_float_fast_add( Environment * _environment, char * _x, char * _y, char * _result );
void cpu_float_fast_sub( Environment * _environment, char * _x, char * _y, char * _result );
void cpu_float_fast_mul( Environment * _environment, char * _x, char * _y, char * _result );
void cpu_float_fast_div( Environment * _environment, char * _x, char * _y, char * _result );
void cpu_float_fast_cmp( Environment * _environment, char * _x, char * _y, char * _result );
void cpu_float_fast_sin( Environment * _environment, char * _angle, char * _result );
void cpu_float_fast_cos( Environment * _environment, char * _angle, char * _result );
void cpu_float_fast_tan( Environment * _environment, char * _angle, char * _result );
void cpu_float_fast_log( Environment * _environment, char * _value, char * _result );
void cpu_float_fast_exp( Environment * _environment, char * _value, char * _result );

// SINGLE FP (32 bit) IEEE-754

void cpu_float_single_from_double_to_int_array( Environment * _environment, double _value, int _result[] );
void cpu_float_single_from_int_array_to_double( Environment * _environment, int _value[], double * _result );
void cpu_float_single_to_string( Environment * _environment, char * _x, char * _string, char * _string_size );
void cpu_float_single_from_16( Environment * _environment, char * _value, char * _result, int _signed );
void cpu_float_single_from_8( Environment * _environment, char * _value, char * _result, int _signed );
void cpu_float_single_to_16( Environment * _environment, char * _value, char * _result, int _signed );
void cpu_float_single_to_8( Environment * _environment, char * _value, char * _result, int _signed );
void cpu_float_single_add( Environment * _environment, char * _x, char * _y, char * _result );
void cpu_float_single_sub( Environment * _environment, char * _x, char * _y, char * _result );
void cpu_float_single_mul( Environment * _environment, char * _x, char * _y, char * _result );
void cpu_float_single_div( Environment * _environment, char * _x, char * _y, char * _result );
void cpu_float_single_cmp( Environment * _environment, char * _x, char * _y, char * _result );
void cpu_float_single_sin( Environment * _environment, char * _angle, char * _result );
void cpu_float_single_cos( Environment * _environment, char * _angle, char * _result );
void cpu_float_single_tan( Environment * _environment, char * _angle, char * _result );
void cpu_float_single_log( Environment * _environment, char * _value, char * _result );
void cpu_float_single_exp( Environment * _environment, char * _value, char * _result );

void cpu_f32add( char * _x, char * _y, char * _result );
void cpu_f32div( char * _x, char * _y, char * _result );
void cpu_f32exp( char * _x, char * _result );
void cpu_f32ln( char * _x, char * _result );
void cpu_f32log10( char * _x, char * _result );
void cpu_f32mul( char * _x, char * _y, char * _result );
void cpu_f32sub( char * _x, char * _y, char * _result );

void cpu_encrypt( Environment * _environment, char * _data, char * _data_size, char * _key, char * _key_size, char * _output );
void cpu_decrypt( Environment * _environment, char * _data, char * _data_size, char * _key, char * _key_size, char * _output, char * _result );

#endif