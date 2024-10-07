#ifndef __UGBC_SC61860__
#define __UGBC_SC61860__

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

#define VT_FLOAT_BITWIDTH( p ) \
        ( \
            VT_BW_24BIT( p, FT_FAST ) + \
            VT_BW_32BIT( p, FT_SINGLE ) \
        )

#define VT_FLOAT_NORMALIZED_BITWIDTH( p ) \
        ( \
            VT_BW_32BIT( p, FT_FAST ) + \
            VT_BW_32BIT( p, FT_SINGLE ) \
        )

#define VT_FLOAT_NORMALIZED_POW2_WIDTH( p ) \
        ( \
            VT_POW2_2( p, FT_FAST ) + \
            VT_POW2_2( p, FT_SINGLE ) \
        )

void sc61860_init( Environment * _environment );

void sc61860_ztoa( Environment * _environment );
void sc61860_ctoa( Environment * _environment );
void sc61860_beq( Environment * _environment, char * _label );
void sc61860_bneq( Environment * _environment, char * _label );
void sc61860_busy_wait( Environment * _environment, char * _timing );
void sc61860_bveq( Environment * _environment, char * _value, char * _label );
void sc61860_bvneq( Environment * _environment, char * _value, char * _label );
void sc61860_di( Environment * _environment );
void sc61860_ei( Environment * _environment );
void sc61860_inc( Environment * _environment, char * _variable );
void sc61860_dec( Environment * _environment, char * _variable );
void sc61860_combine_nibbles( Environment * _environment, char * _low_nibble, char * _hi_nibble, char * _byte );
void sc61860_compare_16bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _positive );
void sc61860_compare_16bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive );
void sc61860_compare_32bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _positive );
void sc61860_compare_32bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive );
void sc61860_compare_8bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _positive );
void sc61860_compare_8bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive );
void sc61860_compare_nbit( Environment * _environment, int _n, char *_source, char *_destination,  char *_name, int _positive );
void sc61860_compare_and_branch_8bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _positive );
void sc61860_compare_and_branch_16bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _positive );
void sc61860_compare_and_branch_16bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive );
void sc61860_compare_and_branch_32bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive );
void sc61860_prepare_for_compare_and_branch_8bit( Environment * _environment, char *_source );
void sc61860_execute_compare_and_branch_8bit_const( Environment * _environment, int _destination,  char *_name, int _positive );
void sc61860_compare_and_branch_8bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive );
void sc61860_compare_and_branch_char_const( Environment * _environment, char *_source, int _destination,  char *_name, int _positive );
void sc61860_less_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void sc61860_less_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void sc61860_less_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void sc61860_less_than_16bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _equal, int _signed );
void sc61860_less_than_32bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _equal, int _signed );
void sc61860_less_than_8bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _equal, int _signed );
void sc61860_less_than_and_branch_8bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _equal, int _signed );
void sc61860_greater_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void sc61860_greater_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void sc61860_greater_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal, int _signed );
void sc61860_greater_than_16bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _equal, int _signed );
void sc61860_greater_than_32bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _equal, int _signed );
void sc61860_greater_than_8bit_const( Environment * _environment, char *_source, int _destination,  char *_name, int _equal, int _signed );
void sc61860_fill( Environment * _environment, char * _address, char * _bytes, int _bytes_width, char * _pattern );
void sc61860_fill_size( Environment * _environment, char * _address, int _bytes, char * _pattern );
void sc61860_fill_size_value( Environment * _environment, char * _address, int _bytes, int _pattern );
void sc61860_fill_direct( Environment * _environment, char * _address, char * _bytes, char * _pattern );
void sc61860_fill_direct_size( Environment * _environment, char * _address, int _bytes, char * _pattern );
void sc61860_fill_direct_size_value( Environment * _environment, char * _address, int _bytes, int _pattern );
void sc61860_fill_blocks( Environment * _environment, char * _address, char * _blocks, char * _pattern );
void sc61860_halt( Environment * _environment );
void sc61860_end( Environment * _environment );
void sc61860_jump( Environment * _environment, char * _label );
void sc61860_jump_indirect( Environment * _environment, char * _value );
void sc61860_call_addr( Environment * _environment, int _label );
void sc61860_call( Environment * _environment, char * _label );
void sc61860_call_indirect( Environment * _environment, char * _value );
void sc61860_set_asmio( Environment * _environment, int _asmio, int _value );
void sc61860_set_asmio_indirect( Environment * _environment, int _asmio, char * _value );
void sc61860_get_asmio_indirect( Environment * _environment, int _asmio, char * _value );
int sc61860_register_decode( Environment * _environment, char * _register );
void sc61860_return( Environment * _environment );
void sc61860_pop( Environment * _environment );
void sc61860_label( Environment * _environment, char * _label );
void sc61860_limit_16bit( Environment * _environment, char * _variable, int _value );
void sc61860_logical_and_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void sc61860_logical_or_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void sc61860_logical_not_8bit( Environment * _environment, char * _value, char * _result );
void sc61860_and_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void sc61860_or_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void sc61860_xor_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void sc61860_xor_8bit_const( Environment * _environment, char * _left, int _right, char * _result );
void sc61860_not_8bit( Environment * _environment, char * _value, char * _result );
void sc61860_swap_8bit( Environment * _environment, char * _left, char * _right );
void sc61860_and_16bit( Environment * _environment, char * _left, char * _right, char * _result );
void sc61860_or_16bit( Environment * _environment, char * _left, char * _right, char * _result );
void sc61860_xor_16bit( Environment * _environment, char * _left, char * _right, char * _result );
void sc61860_xor_16bit_const( Environment * _environment, char * _left, int _right, char * _result );
void sc61860_not_16bit( Environment * _environment, char * _value, char * _result );
void sc61860_swap_16bit( Environment * _environment, char * _left, char * _right );
void sc61860_and_32bit( Environment * _environment, char * _left, char * _right, char * _result );
void sc61860_or_32bit( Environment * _environment, char * _left, char * _right, char * _result );
void sc61860_xor_32bit( Environment * _environment, char * _left, char * _right, char * _result );
void sc61860_xor_32bit_const( Environment * _environment, char * _left, int _right, char * _result );
void sc61860_not_32bit( Environment * _environment, char * _value, char * _result );
void sc61860_swap_32bit( Environment * _environment, char * _left, char * _right );
void sc61860_math_add_16bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void sc61860_math_add_16bit_const( Environment * _environment, char *_source, int _destination,  char *_name );
void sc61860_math_add_16bit_with_16bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void sc61860_math_add_32bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void sc61860_math_add_32bit_const( Environment * _environment, char *_source, int _destination,  char *_name );
void sc61860_math_add_8bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void sc61860_math_add_8bit_const( Environment * _environment, char *_source, int _destination,  char *_name );
void sc61860_math_and_const_16bit( Environment * _environment, char *_source, int _mask );
void sc61860_math_and_const_32bit( Environment * _environment, char *_source, int _mask );
void sc61860_math_and_const_8bit( Environment * _environment, char *_source, int _mask );
void sc61860_math_complement_const_16bit( Environment * _environment, char *_source, int _value );
void sc61860_math_complement_const_32bit( Environment * _environment, char *_source, int _value );
void sc61860_math_complement_const_8bit( Environment * _environment, char *_source, int _value );
void sc61860_math_div2_const_16bit( Environment * _environment, char *_source, int _value, int _signed );
void sc61860_math_div2_const_32bit( Environment * _environment, char *_source, int _value, int _signed );
void sc61860_math_div2_const_8bit( Environment * _environment, char *_source, int _value, int _signed );
void sc61860_math_double_16bit( Environment * _environment, char *_source, char *_name, int _signed );
void sc61860_math_double_32bit( Environment * _environment, char *_source, char *_name, int _signed );
void sc61860_math_double_8bit( Environment * _environment, char *_source, char *_name, int _signed );
void sc61860_math_mul_16bit_to_32bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _signed );
void sc61860_math_mul_8bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _signed );
void sc61860_math_mul2_const_16bit( Environment * _environment, char *_source, int _value, int _signed );
void sc61860_math_mul2_const_32bit( Environment * _environment, char *_source, int _value, int _signed );
void sc61860_math_mul2_const_8bit( Environment * _environment, char *_source, int _value, int _signed );
void sc61860_math_div_32bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed );
void sc61860_math_div_16bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed );
void sc61860_math_div_8bit_to_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed );
void sc61860_math_sub_16bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void sc61860_math_sub_32bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void sc61860_math_sub_8bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void sc61860_move_8bit( Environment * _environment, char *_source, char *_destination );
void sc61860_move_16bit( Environment * _environment, char *_source, char *_destination );
void sc61860_move_32bit( Environment * _environment, char *_source, char *_destination );

void sc61860_move_8bit_signed_16bit_signed( Environment * _environment, char *_source, char *_destination );
void sc61860_move_8bit_signed_16bit_unsigned( Environment * _environment, char *_source, char *_destination );
void sc61860_move_8bit_unsigned_16bit_signed( Environment * _environment, char *_source, char *_destination );
void sc61860_move_8bit_unsigned_16bit_unsigned( Environment * _environment, char *_source, char *_destination );

void sc61860_move_8bit_signed_32bit_signed( Environment * _environment, char *_source, char *_destination );
void sc61860_move_8bit_signed_32bit_unsigned( Environment * _environment, char *_source, char *_destination );
void sc61860_move_8bit_unsigned_32bit_signed( Environment * _environment, char *_source, char *_destination );
void sc61860_move_8bit_unsigned_32bit_unsigned( Environment * _environment, char *_source, char *_destination );

void sc61860_move_16bit_signed_8bit_signed( Environment * _environment, char *_source, char *_destination );
void sc61860_move_16bit_signed_8bit_unsigned( Environment * _environment, char *_source, char *_destination );
void sc61860_move_16bit_unsigned_8bit_signed( Environment * _environment, char *_source, char *_destination );
void sc61860_move_16bit_unsigned_8bit_unsigned( Environment * _environment, char *_source, char *_destination );

void sc61860_move_16bit_signed_32bit_signed( Environment * _environment, char *_source, char *_destination );
void sc61860_move_16bit_signed_32bit_unsigned( Environment * _environment, char *_source, char *_destination );
void sc61860_move_16bit_unsigned_32bit_signed( Environment * _environment, char *_source, char *_destination );
void sc61860_move_16bit_unsigned_32bit_unsigned( Environment * _environment, char *_source, char *_destination );

void sc61860_move_32bit_signed_8bit_signed( Environment * _environment, char *_source, char *_destination );
void sc61860_move_32bit_signed_8bit_unsigned( Environment * _environment, char *_source, char *_destination );
void sc61860_move_32bit_unsigned_8bit_signed( Environment * _environment, char *_source, char *_destination );
void sc61860_move_32bit_unsigned_8bit_unsigned( Environment * _environment, char *_source, char *_destination );

void sc61860_move_32bit_signed_16bit_signed( Environment * _environment, char *_source, char *_destination );
void sc61860_move_32bit_signed_16bit_unsigned( Environment * _environment, char *_source, char *_destination );
void sc61860_move_32bit_unsigned_16bit_signed( Environment * _environment, char *_source, char *_destination );
void sc61860_move_32bit_unsigned_16bit_unsigned( Environment * _environment, char *_source, char *_destination );


void sc61860_move_nbit( Environment * _environment, int _n, char *_source, char *_destination );
void sc61860_addressof_16bit( Environment * _environment, char *_source, char *_destination );
void sc61860_move_8bit_indirect_with_offset( Environment * _environment, char *_source, char *_destination, int _offset );
void sc61860_peek( Environment * _environment, char * _address, char * _target );
void sc61860_poke( Environment * _environment, char * _address, char * _value );
void sc61860_peekw( Environment * _environment, char * _address, char * _target );
void sc61860_pokew( Environment * _environment, char * _address, char * _value );
void sc61860_peekd( Environment * _environment, char * _address, char * _target );
void sc61860_poked( Environment * _environment, char * _address, char * _value );
void sc61860_port_out( Environment * _environment, char * _port, char * _value );
void sc61860_random( Environment * _environment, char * _entropy );
void sc61860_random_16bit( Environment * _environment, char * _entropy, char * _result );
void sc61860_random_32bit( Environment * _environment, char * _entropy, char * _result );
void sc61860_random_8bit( Environment * _environment, char * _entropy, char * _result );
void sc61860_store_char( Environment * _environment, char *_source, int _value );
void sc61860_store_8bit( Environment * _environment, char *_source, int _value );
void sc61860_store_16bit( Environment * _environment, char *_source, int _value );
void sc61860_store_32bit( Environment * _environment, char *_source, int _value );
void sc61860_store_nbit( Environment * _environment, char *_source, int _n, int _value[] );
void sc61860_store_8bit_with_offset( Environment * _environment, char *_source, int _value, int _offset );
void sc61860_compare_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal );
void sc61860_compare_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal );
void sc61860_less_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal );
void sc61860_less_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal );
void sc61860_greater_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal );
void sc61860_greater_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal );
void sc61860_inc_16bit( Environment * _environment, char * _variable );
void sc61860_dec_16bit( Environment * _environment, char * _variable );
void sc61860_inc_32bit( Environment * _environment, char * _variable );
void sc61860_mem_move( Environment * _environment, char *_source, char *_destination,  char *_size );
void sc61860_mem_move_16bit( Environment * _environment, char *_source, char *_destination,  char *_size );
void sc61860_mem_move_direct( Environment * _environment, char *_source, char *_destination,  char *_size );
void sc61860_mem_move_direct2( Environment * _environment, char *_source, char *_destination,  char *_size );
void sc61860_mem_move_direct2_size( Environment * _environment, char *_source, char *_destination, int _size );
void sc61860_mem_move_size( Environment * _environment, char *_source, char *_destination, int _size );
void sc61860_mem_move_direct_size( Environment * _environment, char *_source, char *_destination, int _size );
void sc61860_mem_move_direct_indirect_size( Environment * _environment, char *_source, char *_destination, int _size );
void sc61860_mem_move_indirect_direct_size( Environment * _environment, char *_source, char *_destination, int _size );
void sc61860_math_add_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other );
void sc61860_math_sub_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other );
void sc61860_uppercase( Environment * _environment, char *_source, char *_size, char *_result );
void sc61860_lowercase( Environment * _environment, char *_source, char *_size, char *_result );
void sc61860_convert_string_into_8bit( Environment * _environment, char * _string, char * _len, char * _value );
void sc61860_convert_string_into_16bit( Environment * _environment, char * _string, char * _len, char * _value );
void sc61860_fill_indirect( Environment * _environment, char * _address, char * _size, char * _pattern, int _size_size );
void sc61860_flip( Environment * _environment, char * _source, char * _size, char * _destination );
void sc61860_move_8bit_indirect( Environment * _environment, char *_source, char * _value );
void sc61860_move_8bit_indirect2( Environment * _environment, char *_source, char * _value );
void sc61860_move_8bit_indirect2_8bit( Environment * _environment, char * _value, char * _offset, char *_source );
void sc61860_move_8bit_indirect2_16bit( Environment * _environment, char * _value, char * _offset, char *_source );
void sc61860_move_16bit_indirect( Environment * _environment, char *_source, char * _value );
void sc61860_move_16bit_indirect2( Environment * _environment, char *_source, char * _value );
void sc61860_move_16bit_indirect2_8bit( Environment * _environment, char * _value, char * _offset, char *_source );
void sc61860_move_32bit_indirect( Environment * _environment, char *_source, char * _value );
void sc61860_move_32bit_indirect2( Environment * _environment, char *_source, char * _value );
void sc61860_move_nbit_indirect( Environment * _environment, int _n, char *_source, char * _value );
void sc61860_move_nbit_indirect2( Environment * _environment, int _n, char *_source, char * _value );
void sc61860_bit_check( Environment * _environment, char *_value, int _position, char * _result, int _bitwidth );
void sc61860_bit_check_extended( Environment * _environment, char *_value, char * _position, char * _result, int _bitwidth );
void sc61860_bit_inplace_8bit( Environment * _environment, char * _value, int _position, int * _bit );
void sc61860_bit_inplace_8bit_extended_indirect( Environment * _environment, char * address, char * _position, char * _bit );
void sc61860_number_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits, int _signed );
void sc61860_move_8bit_indirect_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset );
void sc61860_dsdefine( Environment * _environment, char * _string, char * _index );
void sc61860_dsalloc( Environment * _environment, char * _size, char * _index );
void sc61860_dsfree( Environment * _environment, char * _index );
void sc61860_dswrite( Environment * _environment, char * _index );
void sc61860_dsresize( Environment * _environment, char * _index, char * _size );
void sc61860_dsresize_size( Environment * _environment, char * _index, int _size );
void sc61860_dsgc( Environment * _environment );
void sc61860_dsdescriptor( Environment * _environment, char * _index, char * _address, char * _size );
void sc61860_move_8bit_indirect_with_offset( Environment * _environment, char *_source, char * _value, int _offset );
void sc61860_dsalloc_size( Environment * _environment, int _size, char * _index );
void sc61860_bits_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits );
void sc61860_hex_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits );
void sc61860_move_8bit_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset );
void sc61860_complement2_8bit( Environment * _environment, char * _source, char * _destination );
void sc61860_complement2_16bit( Environment * _environment, char * _source, char * _destination );
void sc61860_complement2_32bit( Environment * _environment, char * _source, char * _destination );
void sc61860_sqroot( Environment * _environment, char * _number, char * _result );
void sc61860_dstring_vars( Environment * _environment );
void sc61860_out( Environment * _environment, char * _port, char * _value );
void sc61860_in( Environment * _environment, char * _port, char * _value );
void sc61860_out_direct( Environment * _environment, char * _port, char * _value );
void sc61860_in_direct( Environment * _environment, char * _port, char * _value );
void sc61860_string_sub( Environment * _environment, char * _source, char * _source_size, char * _pattern, char * _pattern_size, char * _destination, char * _destination_size );

void sc61860_protothread_loop( Environment * _environment );
void sc61860_protothread_register_at( Environment * _environment, char * _index, char * _label );
void sc61860_protothread_register( Environment * _environment, char * _label, char * _index );
void sc61860_protothread_unregister( Environment * _environment, char * _index );
void sc61860_protothread_save( Environment * _environment, char * _index, int _step );
void sc61860_protothread_restore( Environment * _environment, char * _index, char * _step );
void sc61860_protothread_set_state( Environment * _environment, char * _index, int _state );
void sc61860_protothread_get_state( Environment * _environment, char * _index, char * _state );
void sc61860_protothread_current( Environment * _environment, char * _current );
void sc61860_set_callback( Environment * _environment, char * _callback, char * _label );

void sc61860_msc1_uncompress_direct_direct( Environment * _environment, char * _input, char * _output );
void sc61860_msc1_uncompress_direct_indirect( Environment * _environment, char * _input, char * _output );
void sc61860_msc1_uncompress_indirect_direct( Environment * _environment, char * _input, char * _output );
void sc61860_msc1_uncompress_indirect_indirect( Environment * _environment, char * _input, char * _output );

void sc61860_blit_initialize( Environment * _environment );
char*sc61860_blit_register_name( Environment * _environment, int _register );
int  sc61860_blit_alloc_register( Environment * _environment );
void sc61860_blit_free_register( Environment * _environment, int _register );
void sc61860_blit_finalize( Environment * _environment );

void sc61860_address_table_build( Environment * _environment, char * _table, int * _values, char *_address[], int _count );
void sc61860_address_table_lookup( Environment * _environment, char * _table, int _count );
void sc61860_address_table_call( Environment * _environment, char * _table, char * _value, char * _address );

// FAST FP (24 bit)

void sc61860_float_fast_from_double_to_int_array( Environment * _environment, double _value, int _result[] );
void sc61860_float_fast_to_string( Environment * _environment, char * _x, char * _string, char * _string_size );
void sc61860_float_fast_from_16( Environment * _environment, char * _value, char * _result, int _signed );
void sc61860_float_fast_from_8( Environment * _environment, char * _value, char * _result, int _signed );
void sc61860_float_fast_to_16( Environment * _environment, char * _value, char * _result, int _signed );
void sc61860_float_fast_to_8( Environment * _environment, char * _value, char * _result, int _signed );
void sc61860_float_fast_add( Environment * _environment, char * _x, char * _y, char * _result );
void sc61860_float_fast_sub( Environment * _environment, char * _x, char * _y, char * _result );
void sc61860_float_fast_mul( Environment * _environment, char * _x, char * _y, char * _result );
void sc61860_float_fast_div( Environment * _environment, char * _x, char * _y, char * _result );
void sc61860_float_fast_cmp( Environment * _environment, char * _x, char * _y, char * _result );
void sc61860_float_fast_sin( Environment * _environment, char * _angle, char * _result );
void sc61860_float_fast_cos( Environment * _environment, char * _angle, char * _result );
void sc61860_float_fast_sqr( Environment * _environment, char * _angle, char * _result );
void sc61860_float_fast_mod1( Environment * _environment, char * _angle, char * _result );
void sc61860_float_fast_neg( Environment * _environment, char * _value, char * _result );
void sc61860_float_fast_abs( Environment * _environment, char * _value, char * _result );
void sc61860_float_fast_tan( Environment * _environment, char * _value, char * _result );
void sc61860_float_fast_log( Environment * _environment, char * _value, char * _result );
void sc61860_float_fast_exp( Environment * _environment, char * _value, char * _result );

// SINGLE FP (32 bit) IEEE-754

void sc61860_float_single_from_double_to_int_array( Environment * _environment, double _value, int _result[] );
void sc61860_float_single_to_string( Environment * _environment, char * _x, char * _string, char * _string_size );
void sc61860_float_single_from_16( Environment * _environment, char * _value, char * _result, int _signed );
void sc61860_float_single_from_8( Environment * _environment, char * _value, char * _result, int _signed );
void sc61860_float_single_to_16( Environment * _environment, char * _value, char * _result, int _signed );
void sc61860_float_single_to_8( Environment * _environment, char * _value, char * _result, int _signed );
void sc61860_float_single_add( Environment * _environment, char * _x, char * _y, char * _result );
void sc61860_float_single_sub( Environment * _environment, char * _x, char * _y, char * _result );
void sc61860_float_single_mul( Environment * _environment, char * _x, char * _y, char * _result );
void sc61860_float_single_div( Environment * _environment, char * _x, char * _y, char * _result );
void sc61860_float_single_cmp( Environment * _environment, char * _x, char * _y, char * _result );
void sc61860_float_single_sin( Environment * _environment, char * _angle, char * _result );
void sc61860_float_single_cos( Environment * _environment, char * _angle, char * _result );
void sc61860_float_single_sqr( Environment * _environment, char * _angle, char * _result );
void sc61860_float_single_mod1( Environment * _environment, char * _angle, char * _result );
void sc61860_float_single_neg( Environment * _environment, char * _value, char * _result );
void sc61860_float_single_abs( Environment * _environment, char * _value, char * _result );
void sc61860_float_single_tan( Environment * _environment, char * _value, char * _result );
void sc61860_float_single_log( Environment * _environment, char * _value, char * _result );
void sc61860_float_single_exp( Environment * _environment, char * _value, char * _result );

#define cpu_ztoa( _environment ) sc61860_ztoa( _environment )
#define cpu_ctoa( _environment ) sc61860_ctoa( _environment )
#define cpu_beq( _environment,  _label  ) sc61860_beq( _environment,  _label  )
#define cpu_bneq( _environment,  _label  ) sc61860_beq( _environment,  _label  )
#define cpu_busy_wait( _environment,  _timing  ) sc61860_busy_wait( _environment,  _timing  )
#define cpu_bveq( _environment,  _value,  _label  ) sc61860_bveq( _environment,  _value,  _label  )
#define cpu_bvneq( _environment,  _value,  _label  ) sc61860_bvneq( _environment,  _value,  _label  )
#define cpu_combine_nibbles( _environment,  _low_nibble,  _hi_nibble,  _byte  ) sc61860_combine_nibbles( _environment,  _low_nibble,  _hi_nibble,  _byte  )
#define cpu_compare_16bit( _environment, _source, _destination, _name, _positive ) sc61860_compare_16bit( _environment, _source, _destination, _name, _positive )
#define cpu_compare_16bit_const( _environment, _source, _destination, _name, _positive ) sc61860_compare_16bit_const( _environment, _source, _destination, _name, _positive )
#define cpu_compare_32bit( _environment, _source, _destination, _name, _positive ) sc61860_compare_32bit( _environment, _source, _destination, _name, _positive )
#define cpu_compare_32bit_const( _environment, _source, _destination, _name, _positive ) sc61860_compare_32bit_const( _environment, _source, _destination, _name, _positive )
#define cpu_compare_8bit( _environment, _source, _destination, _name, _positive ) sc61860_compare_8bit( _environment, _source, _destination, _name, _positive )
#define cpu_compare_8bit_const( _environment, _source, _destination, _name, _positive ) sc61860_compare_8bit_const( _environment, _source, _destination, _name, _positive )
#define cpu_compare_nbit( _environment, _n, _source, _destination, _name, _positive ) sc61860_compare_nbit( _environment, _n, _source, _destination, _name, _positive )
#define cpu_compare_and_branch_8bit( _environment, _source, _destination, _name, _positive ) sc61860_compare_and_branch_8bit( _environment, _source, _destination, _name, _positive )
#define cpu_compare_and_branch_16bit( _environment, _source, _destination, _name, _positive ) sc61860_compare_and_branch_16bit( _environment, _source, _destination, _name, _positive )
#define cpu_compare_and_branch_16bit_const( _environment, _source, _destination, _name, _positive ) sc61860_compare_and_branch_16bit_const( _environment, _source, _destination, _name, _positive )
#define cpu_compare_and_branch_32bit_const( _environment, _source, _destination, _name, _positive ) sc61860_compare_and_branch_32bit_const( _environment, _source, _destination, _name, _positive )
#define cpu_prepare_for_compare_and_branch_8bit( _environment, _source ) sc61860_prepare_for_compare_and_branch_8bit( _environment, _source )
#define cpu_execute_compare_and_branch_8bit_const( _environment, _destination, _name, _positive ) sc61860_execute_compare_and_branch_8bit_const( _environment, _destination, _name, _positive )
#define cpu_compare_and_branch_8bit_const( _environment, _source, _destination, _name, _positive ) sc61860_compare_and_branch_8bit_const( _environment, _source, _destination, _name, _positive )
#define cpu_compare_and_branch_char_const( _environment, _source, _destination, _name, _positive ) sc61860_compare_and_branch_char_const( _environment, _source, _destination, _name, _positive )
#define cpu_di( _environment  ) sc61860_di( _environment  )
#define cpu_ei( _environment  ) sc61860_ei( _environment  )
#define cpu_inc( _environment, _variable ) sc61860_inc( _environment, _variable );
#define cpu_dec( _environment, _variable ) sc61860_dec( _environment, _variable );
#define cpu_less_than_16bit( _environment, _source, _destination, _name, _equal, _signed ) sc61860_less_than_16bit( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_less_than_32bit( _environment, _source, _destination, _name, _equal, _signed  ) sc61860_less_than_32bit( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_less_than_8bit( _environment, _source, _destination, _name, _equal, _signed  ) sc61860_less_than_8bit( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_less_than_16bit_const( _environment, _source, _destination, _name, _equal, _signed ) sc61860_less_than_16bit_const( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_less_than_32bit_const( _environment, _source, _destination, _name, _equal, _signed  ) sc61860_less_than_32bit_const( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_less_than_8bit_const( _environment, _source, _destination, _name, _equal, _signed  ) sc61860_less_than_8bit_const( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_less_than_and_branch_8bit_const( _environment, _source, _destination, _label, _equal, _signed  ) sc61860_less_than_and_branch_8bit_const( _environment, _source, _destination, _label, _equal, _signed  )
#define cpu_greater_than_16bit( _environment, _source, _destination, _name, _equal, _signed  ) sc61860_greater_than_16bit( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_greater_than_32bit( _environment, _source, _destination, _name, _equal, _signed  ) sc61860_greater_than_32bit( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_greater_than_8bit( _environment, _source, _destination, _name, _equal, _signed  ) sc61860_greater_than_8bit( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_greater_than_16bit_const( _environment, _source, _destination, _name, _equal, _signed  ) sc61860_greater_than_16bit_const( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_greater_than_32bit_const( _environment, _source, _destination, _name, _equal, _signed  ) sc61860_greater_than_32bit_const( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_greater_than_8bit_const( _environment, _source, _destination, _name, _equal, _signed  ) sc61860_greater_than_8bit_const( _environment, _source, _destination, _name, _equal, _signed  )
#define cpu_fill( _environment,  _address,  _bytes, _bytes_width, _pattern  ) sc61860_fill( _environment,  _address, _bytes, _bytes_width, _pattern  )
#define cpu_fill_size( _environment,  _address,  _bytes,  _pattern  ) sc61860_fill_size( _environment,  _address, _bytes,  _pattern  )
#define cpu_fill_size_value( _environment,  _address,  _bytes,  _pattern  ) sc61860_fill_size_value( _environment,  _address, _bytes,  _pattern  )
#define cpu_fill_direct( _environment,  _address,  _bytes,  _pattern  ) sc61860_fill_direct( _environment,  _address, _bytes,  _pattern  )
#define cpu_fill_direct_size( _environment,  _address,  _bytes,  _pattern  ) sc61860_fill_direct_size( _environment,  _address, _bytes,  _pattern  )
#define cpu_fill_direct_size_value( _environment,  _address,  _bytes,  _pattern  ) sc61860_fill_direct_size_value( _environment,  _address, _bytes,  _pattern  )
#define cpu_fill_blocks( _environment,  _address,  _blocks,  _pattern  ) sc61860_fill_blocks( _environment,  _address,  _blocks,  _pattern  )
#define cpu_halt( _environment  ) sc61860_halt( _environment  )
#define cpu_end( _environment  ) sc61860_end( _environment  )
#define cpu_jump( _environment,  _label  ) sc61860_jump( _environment,  _label  )
#define cpu_jump_indirect( _environment, _value ) sc61860_jump_indirect( _environment, _value )
#define cpu_call_addr( _environment,  _label  ) sc61860_call_addr( _environment,  _label  )
#define cpu_call( _environment,  _label  ) sc61860_call( _environment,  _label  )
#define cpu_call_indirect( _environment,  _value  ) sc61860_call_indirect( _environment,  _value  )
#define cpu_set_asmio( _environment, _asmio, _value ) sc61860_set_asmio( _environment, _asmio, _value )
#define cpu_set_asmio_indirect( _environment, _asmio, _value ) sc61860_set_asmio_indirect( _environment, _asmio, _value )
#define cpu_get_asmio_indirect( _environment, _asmio, _value ) sc61860_get_asmio_indirect( _environment, _asmio, _value )
#define cpu_register_decode( _environment, _register ) sc61860_register_decode( _environment, _register )
#define cpu_return( _environment ) sc61860_return( _environment  )
#define cpu_pop( _environment ) sc61860_pop( _environment  )
#define cpu_label( _environment,  _label  ) sc61860_label( _environment,  _label  )
#define cpu_limit_16bit( _environment,  _variable, _value  ) sc61860_limit_16bit( _environment,  _variable, _value  )
#define cpu_logical_and_8bit( _environment, _left, _right,  _result ) sc61860_logical_and_8bit( _environment, _left, _right,  _result )
#define cpu_logical_or_8bit( _environment, _left, _right,  _result ) sc61860_logical_or_8bit( _environment, _left, _right,  _result )
#define cpu_logical_not_8bit( _environment, _value,  _result ) sc61860_logical_not_8bit( _environment, _value,  _result )
#define cpu_and_8bit( _environment, _left, _right,  _result ) sc61860_and_8bit( _environment, _left, _right,  _result )
#define cpu_or_8bit( _environment, _left, _right,  _result ) sc61860_or_8bit( _environment, _left, _right,  _result )
#define cpu_xor_8bit( _environment, _left, _right,  _result ) sc61860_xor_8bit( _environment, _left, _right,  _result )
#define cpu_xor_8bit_const( _environment, _left, _right,  _result ) sc61860_xor_8bit_const( _environment, _left, _right,  _result )
#define cpu_not_8bit( _environment, _value,  _result ) sc61860_not_8bit( _environment, _value,  _result )
#define cpu_swap_8bit( _environment, _value,  _result ) sc61860_swap_8bit( _environment, _value,  _result )
#define cpu_and_16bit( _environment, _left, _right,  _result ) sc61860_and_16bit( _environment, _left, _right,  _result )
#define cpu_or_16bit( _environment, _left, _right,  _result ) sc61860_or_16bit( _environment, _left, _right,  _result )
#define cpu_xor_16bit( _environment, _left, _right,  _result ) sc61860_xor_16bit( _environment, _left, _right,  _result )
#define cpu_xor_16bit_const( _environment, _left, _right,  _result ) sc61860_xor_16bit_const( _environment, _left, _right,  _result )
#define cpu_not_16bit( _environment, _value,  _result ) sc61860_not_16bit( _environment, _value,  _result )
#define cpu_swap_16bit( _environment, _value,  _result ) sc61860_swap_16bit( _environment, _value,  _result )
#define cpu_and_32bit( _environment, _left, _right,  _result ) sc61860_and_32bit( _environment, _left, _right,  _result )
#define cpu_or_32bit( _environment, _left, _right,  _result ) sc61860_or_32bit( _environment, _left, _right,  _result )
#define cpu_xor_32bit( _environment, _left, _right,  _result ) sc61860_xor_32bit( _environment, _left, _right,  _result )
#define cpu_xor_32bit_const( _environment, _left, _right,  _result ) sc61860_xor_32bit_const( _environment, _left, _right,  _result )
#define cpu_not_32bit( _environment, _value,  _result ) sc61860_not_32bit( _environment, _value,  _result )
#define cpu_swap_32bit( _environment, _value,  _result ) sc61860_swap_32bit( _environment, _value,  _result )
#define cpu_math_add_16bit( _environment, _source, _destination,  _name  ) sc61860_math_add_16bit( _environment, _source, _destination,  _name  )
#define cpu_math_add_16bit_const( _environment, _source, _destination,  _name  ) sc61860_math_add_16bit_const( _environment, _source, _destination,  _name  )
#define cpu_math_add_16bit_with_16bit( _environment, _source, _destination,  _name  ) sc61860_math_add_16bit_with_16bit( _environment, _source, _destination,  _name  )
#define cpu_math_add_32bit( _environment, _source, _destination,  _name  ) sc61860_math_add_32bit( _environment, _source, _destination,  _name  )
#define cpu_math_add_32bit_const( _environment, _source, _destination,  _name  ) sc61860_math_add_32bit_const( _environment, _source, _destination,  _name  )
#define cpu_math_add_8bit( _environment, _source, _destination,  _name  ) sc61860_math_add_8bit( _environment, _source, _destination,  _name  )
#define cpu_math_add_8bit_const( _environment, _source, _destination,  _name  ) sc61860_math_add_8bit_const( _environment, _source, _destination,  _name  )
#define cpu_math_and_const_16bit( _environment, _source, _mask  ) sc61860_math_and_const_16bit( _environment, _source, _mask  )
#define cpu_math_and_const_32bit( _environment, _source, _mask  ) sc61860_math_and_const_32bit( _environment, _source, _mask  )
#define cpu_math_and_const_8bit( _environment, _source, _mask  ) sc61860_math_and_const_8bit( _environment, _source, _mask  )
#define cpu_math_complement_const_16bit( _environment, _source, _value  ) sc61860_math_complement_const_16bit( _environment, _source, _value  )
#define cpu_math_complement_const_32bit( _environment, _source, _value  ) sc61860_math_complement_const_32bit( _environment, _source, _value  )
#define cpu_math_complement_const_8bit( _environment, _source, _value  ) sc61860_math_complement_const_8bit( _environment, _source, _value  )
#define cpu_math_div2_const_16bit( _environment, _source, _value, _signed  ) sc61860_math_div2_const_16bit( _environment, _source, _value, _signed  )
#define cpu_math_div2_const_32bit( _environment, _source, _value, _signed  ) sc61860_math_div2_const_32bit( _environment, _source, _value, _signed  )
#define cpu_math_div2_const_8bit( _environment, _source, _value, _signed  ) sc61860_math_div2_const_8bit( _environment, _source, _value, _signed  )
#define cpu_math_double_16bit( _environment, _source, _name, _signed  ) sc61860_math_double_16bit( _environment, _source, _name, _signed  )
#define cpu_math_double_32bit( _environment, _source, _name, _signed  ) sc61860_math_double_32bit( _environment, _source, _name, _signed  )
#define cpu_math_double_8bit( _environment, _source, _name, _signed  ) sc61860_math_double_8bit( _environment, _source, _name, _signed  )
#define cpu_math_mul_16bit_to_32bit( _environment, _source, _destination,  _name, _signed  ) sc61860_math_mul_16bit_to_32bit( _environment, _source, _destination,  _name, _signed  )
#define cpu_math_mul_8bit_to_16bit( _environment, _source, _destination,  _name, _signed  ) sc61860_math_mul_8bit_to_16bit( _environment, _source, _destination,  _name, _signed  )
#define cpu_math_mul2_const_16bit( _environment, _source, _value, _signed  ) sc61860_math_mul2_const_16bit( _environment, _source, _value, _signed  )
#define cpu_math_mul2_const_32bit( _environment, _source, _value, _signed  ) sc61860_math_mul2_const_32bit( _environment, _source, _value, _signed  )
#define cpu_math_mul2_const_8bit( _environment, _source, _value, _signed  ) sc61860_math_mul2_const_8bit( _environment, _source, _value, _signed  )
#define cpu_math_sub_16bit( _environment, _source, _destination,  _name  ) sc61860_math_sub_16bit( _environment, _source, _destination,  _name  )
#define cpu_math_sub_32bit( _environment, _source, _destination,  _name  ) sc61860_math_sub_32bit( _environment, _source, _destination,  _name  )
#define cpu_math_sub_8bit( _environment, _source, _destination,  _name  ) sc61860_math_sub_8bit( _environment, _source, _destination,  _name  )
#define cpu_move_8bit( _environment, _source, _destination  ) sc61860_move_8bit( _environment, _source, _destination  )
#define cpu_move_16bit( _environment, _source, _destination  ) sc61860_move_16bit( _environment, _source, _destination  )
#define cpu_move_32bit( _environment, _source, _destination  ) sc61860_move_32bit( _environment, _source, _destination  )

#define cpu_move_8bit_signed_16bit_signed(  _environment, _source, _destination ) sc61860_move_8bit_signed_16bit_signed(  _environment, _source, _destination )
#define cpu_move_8bit_signed_16bit_unsigned(  _environment, _source, _destination ) sc61860_move_8bit_signed_16bit_unsigned(  _environment, _source, _destination )
#define cpu_move_8bit_unsigned_16bit_signed(  _environment, _source, _destination ) sc61860_move_8bit_unsigned_16bit_signed(  _environment, _source, _destination )
#define cpu_move_8bit_unsigned_16bit_unsigned(  _environment, _source, _destination ) sc61860_move_8bit_unsigned_16bit_unsigned(  _environment, _source, _destination )

#define cpu_move_8bit_signed_32bit_signed(  _environment, _source, _destination ) sc61860_move_8bit_signed_32bit_signed(  _environment, _source, _destination )
#define cpu_move_8bit_signed_32bit_unsigned(  _environment, _source, _destination ) sc61860_move_8bit_signed_32bit_unsigned(  _environment, _source, _destination )
#define cpu_move_8bit_unsigned_32bit_signed(  _environment, _source, _destination ) sc61860_move_8bit_unsigned_32bit_signed(  _environment, _source, _destination )
#define cpu_move_8bit_unsigned_32bit_unsigned(  _environment, _source, _destination ) sc61860_move_8bit_unsigned_32bit_unsigned(  _environment, _source, _destination )

#define cpu_move_16bit_signed_8bit_signed(  _environment, _source, _destination ) sc61860_move_16bit_signed_8bit_signed(  _environment, _source, _destination )
#define cpu_move_16bit_signed_8bit_unsigned(  _environment, _source, _destination ) sc61860_move_16bit_signed_8bit_unsigned(  _environment, _source, _destination )
#define cpu_move_16bit_unsigned_8bit_signed(  _environment, _source, _destination ) sc61860_move_16bit_unsigned_8bit_signed(  _environment, _source, _destination )
#define cpu_move_16bit_unsigned_8bit_unsigned(  _environment, _source, _destination ) sc61860_move_16bit_unsigned_8bit_unsigned(  _environment, _source, _destination )

#define cpu_move_16bit_signed_32bit_signed(  _environment, _source, _destination ) sc61860_move_16bit_signed_32bit_signed(  _environment, _source, _destination )
#define cpu_move_16bit_signed_32bit_unsigned(  _environment, _source, _destination ) sc61860_move_16bit_signed_32bit_unsigned(  _environment, _source, _destination )
#define cpu_move_16bit_unsigned_32bit_signed(  _environment, _source, _destination ) sc61860_move_16bit_unsigned_32bit_signed(  _environment, _source, _destination )
#define cpu_move_16bit_unsigned_32bit_unsigned(  _environment, _source, _destination ) sc61860_move_16bit_unsigned_32bit_unsigned(  _environment, _source, _destination )

#define cpu_move_32bit_signed_8bit_signed(  _environment, _source, _destination ) sc61860_move_32bit_signed_8bit_signed(  _environment, _source, _destination )
#define cpu_move_32bit_signed_8bit_unsigned(  _environment, _source, _destination ) sc61860_move_32bit_signed_8bit_unsigned(  _environment, _source, _destination )
#define cpu_move_32bit_unsigned_8bit_signed(  _environment, _source, _destination ) sc61860_move_32bit_unsigned_8bit_signed(  _environment, _source, _destination )
#define cpu_move_32bit_unsigned_8bit_unsigned(  _environment, _source, _destination ) sc61860_move_32bit_unsigned_8bit_unsigned(  _environment, _source, _destination )

#define cpu_move_32bit_signed_16bit_signed(  _environment, _source, _destination ) sc61860_move_32bit_signed_16bit_signed(  _environment, _source, _destination )
#define cpu_move_32bit_signed_16bit_unsigned(  _environment, _source, _destination ) sc61860_move_32bit_signed_16bit_unsigned(  _environment, _source, _destination )
#define cpu_move_32bit_unsigned_16bit_signed(  _environment, _source, _destination ) sc61860_move_32bit_unsigned_16bit_signed(  _environment, _source, _destination )
#define cpu_move_32bit_unsigned_16bit_unsigned(  _environment, _source, _destination ) sc61860_move_32bit_unsigned_16bit_unsigned(  _environment, _source, _destination )


#define cpu_move_nbit( _environment, _n, _source, _destination  ) sc61860_move_nbit( _environment, _n, _source, _destination )
#define cpu_addressof_16bit( _environment, _source, _destination  ) sc61860_addressof_16bit( _environment, _source, _destination  )
#define cpu_peek( _environment,  _address,  _target  ) sc61860_peek( _environment,  _address,  _target  )
#define cpu_poke( _environment,  _address,  _value  ) sc61860_poke( _environment,  _address,  _value  )
#define cpu_peekw( _environment,  _address,  _target  ) sc61860_peekw( _environment,  _address,  _target  )
#define cpu_pokew( _environment,  _address,  _value  ) sc61860_pokew( _environment,  _address,  _value  )
#define cpu_peekd( _environment,  _address,  _target  ) sc61860_peekd( _environment,  _address,  _target  )
#define cpu_poked( _environment,  _address,  _value  ) sc61860_poked( _environment,  _address,  _value  )
#define cpu_random( _environment,  _entropy  ) sc61860_random( _environment,  _entropy  )
#define cpu_random_16bit( _environment,  _entropy,  _result  ) sc61860_random_16bit( _environment,  _entropy,  _result  )
#define cpu_random_32bit( _environment,  _entropy,  _result  ) sc61860_random_32bit( _environment,  _entropy,  _result  )
#define cpu_random_8bit( _environment,  _entropy,  _result  ) sc61860_random_8bit( _environment,  _entropy,  _result  )
#define cpu_store_char( _environment, _source, _value  ) sc61860_store_char( _environment, _source, _value  )
#define cpu_store_8bit( _environment, _source, _value  ) sc61860_store_8bit( _environment, _source, _value  )
#define cpu_store_16bit( _environment, _source, _value  ) sc61860_store_16bit( _environment, _source, _value  )
#define cpu_store_32bit( _environment, _source, _value  ) sc61860_store_32bit( _environment, _source, _value  )
#define cpu_store_nbit( _environment, _source, _n, _value  ) sc61860_store_nbit( _environment, _source, _n, _value  )
#define cpu_compare_memory( _environment, _source, _destination, _size, _result, _equal ) sc61860_compare_memory( _environment, _source, _destination, _size, _result, _equal )
#define cpu_compare_memory_size( _environment, _source, _destination, _size, _result, _equal ) sc61860_compare_memory_size( _environment, _source, _destination, _size, _result, _equal )
#define cpu_less_than_memory( _environment, _source, _destination, _size, _result, _equal ) sc61860_less_than_memory( _environment, _source, _destination,  _size, _result, _equal )
#define cpu_less_than_memory_size( _environment, _source, _destination, _size, _result, _equal ) sc61860_less_than_memory_size( _environment, _source, _destination,  _size, _result, _equal )
#define cpu_greater_than_memory( _environment, _source, _destination, _size, _result, _equal ) sc61860_greater_than_memory( _environment, _source, _destination, _size, _result, _equal )
#define cpu_greater_than_memory_size( _environment, _source, _destination, _size, _result, _equal ) sc61860_greater_than_memory_size( _environment, _source, _destination, _size, _result, _equal )
#define cpu_inc_16bit( _environment, _variable ) sc61860_inc_16bit( _environment, _variable )
#define cpu_dec_16bit( _environment, _variable ) sc61860_dec_16bit( _environment, _variable )
#define cpu_inc_32bit( _environment, _variable ) sc61860_inc_32bit( _environment, _variable )
#define cpu_mem_move( _environment, _source, _destination,  _size ) sc61860_mem_move( _environment, _source, _destination, _size )
#define cpu_mem_move_16bit( _environment, _source, _destination,  _size ) sc61860_mem_move_16bit( _environment, _source, _destination, _size )
#define cpu_mem_move_direct( _environment, _source, _destination,  _size ) sc61860_mem_move_direct( _environment, _source, _destination, _size )
#define cpu_mem_move_direct2( _environment, _source, _destination,  _size ) sc61860_mem_move_direct2( _environment, _source, _destination, _size )
#define cpu_mem_move_direct2_size( _environment, _source, _destination,  _size ) sc61860_mem_move_direct2_size( _environment, _source, _destination, _size )
#define cpu_mem_move_size( _environment, _source, _destination,  _size ) sc61860_mem_move_size( _environment, _source, _destination, _size )
#define cpu_mem_move_direct_size( _environment, _source, _destination,  _size ) sc61860_mem_move_direct_size( _environment, _source, _destination, _size )
#define cpu_mem_move_direct_indirect_size( _environment, _source, _destination,  _size ) sc61860_mem_move_direct_indirect_size( _environment, _source, _destination, _size )
#define cpu_mem_move_indirect_direct_size( _environment, _source, _destination,  _size ) sc61860_mem_move_indirect_direct_size( _environment, _source, _destination, _size )
#define cpu_math_add_16bit_with_8bit( _environment, _source, _destination, _other ) sc61860_math_add_16bit_with_8bit( _environment, _source, _destination, _other )
#define cpu_math_sub_16bit_with_8bit( _environment, _source, _destination, _other ) sc61860_math_sub_16bit_with_8bit( _environment, _source, _destination, _other )
#define cpu_uppercase( _environment, _source, _size, _result ) sc61860_uppercase( _environment, _source, _size, _result )
#define cpu_lowercase( _environment, _source, _size, _result ) sc61860_lowercase( _environment, _source, _size, _result )
#define cpu_convert_string_into_8bit( _environment, _string, _len, _value ) sc61860_convert_string_into_8bit( _environment, _string, _len, _value )
#define cpu_convert_string_into_16bit( _environment, _string, _len, _value ) sc61860_convert_string_into_16bit( _environment, _string, _len, _value )
#define cpu_fill_indirect( _environment, _address, _size, _pattern, _size_size ) sc61860_fill_indirect( _environment, _address, _size, _pattern, _size_size )
#define cpu_flip( _environment, _source, _size, _destination ) sc61860_flip( _environment, _source, _size, _destination )
#define cpu_move_8bit_indirect( _environment, _source, _value ) sc61860_move_8bit_indirect( _environment, _source, _value )
#define cpu_move_8bit_indirect2( _environment, _source, _value ) sc61860_move_8bit_indirect2( _environment, _source, _value )
#define cpu_move_8bit_indirect2_8bit( _environment, _value, _offset, _source ) sc61860_move_8bit_indirect2_8bit(  _environment, _value, _offset, _source )
#define cpu_move_8bit_indirect2_16bit( _environment, _value, _offset, _source ) sc61860_move_8bit_indirect2_16bit(  _environment, _value, _offset, _source )
#define cpu_move_16bit_indirect( _environment, _source, _value ) sc61860_move_16bit_indirect( _environment, _source, _value )
#define cpu_move_16bit_indirect2( _environment, _source, _value ) sc61860_move_16bit_indirect2( _environment, _source, _value )
#define cpu_move_16bit_indirect2_8bit( _environment, _value, _offset, _source ) sc61860_move_16bit_indirect2_8bit(  _environment, _value, _offset, _source )
#define cpu_move_32bit_indirect( _environment, _source, _value ) sc61860_move_32bit_indirect( _environment, _source, _value )
#define cpu_move_32bit_indirect2( _environment, _source, _value ) sc61860_move_32bit_indirect2( _environment, _source, _value )
#define cpu_move_nbit_indirect( _environment, _n, _source, _value ) sc61860_move_nbit_indirect( _environment, _n, _source, _value )
#define cpu_move_nbit_indirect2( _environment, _n, _source, _value ) sc61860_move_nbit_indirect2( _environment, _n, _source, _value )
#define cpu_math_div_32bit_to_16bit( _environment, _source, _destination,  _other, _other_remainder, _signed  ) sc61860_math_div_32bit_to_16bit( _environment, _source, _destination, _other, _other_remainder, _signed )
#define cpu_math_div_16bit_to_16bit( _environment, _source, _destination,  _other, _other_remainder, _signed  ) sc61860_math_div_16bit_to_16bit( _environment, _source, _destination, _other, _other_remainder, _signed )
#define cpu_math_div_8bit_to_8bit( _environment, _source, _destination,   _other, _other_remainder, _signed  ) sc61860_math_div_8bit_to_8bit( _environment, _source, _destination,  _other, _other_remainder, _signed )
#define cpu_bit_check( _environment, _value, _position, _result, _bitwidth ) sc61860_bit_check( _environment, _value, _position, _result, _bitwidth )
#define cpu_bit_inplace_8bit( _environment, _value, _position, _bit ) sc61860_bit_inplace_8bit( _environment, _value, _position, _bit );
#define cpu_bit_inplace_8bit_extended_indirect( _environment, _address, _position, _bit ) sc61860_bit_inplace_8bit_extended_indirect( _environment, _address, _position, _bit );
#define cpu_number_to_string( _environment, _number, _string, _string_size, _bits, _signed ) sc61860_number_to_string( _environment, _number, _string, _string_size, _bits, _signed )
#define cpu_move_8bit_indirect_with_offset2( _environment, _source, _value, _offset ) sc61860_move_8bit_indirect_with_offset2( _environment, _source, _value, _offset )
#define cpu_store_8bit_with_offset( _environment, _source, _value, _offset ) sc61860_store_8bit_with_offset( _environment, _source, _value, _offset )
#define cpu_move_8bit_indirect_with_offset( _environment, _source, _destination, _offset ) sc61860_move_8bit_indirect_with_offset( _environment, _source, _destination, _offset )
#define cpu_dsdefine( _environment, _string, _index ) sc61860_dsdefine( _environment, _string, _index )
#define cpu_dsalloc( _environment, _size, _index ) sc61860_dsalloc( _environment, _size, _index )
#define cpu_dsfree( _environment, _index ) sc61860_dsfree( _environment, _index )
#define cpu_dswrite( _environment, _index ) sc61860_dswrite( _environment, _index )
#define cpu_dsresize( _environment, _index, _size ) sc61860_dsresize( _environment, _index, _size )
#define cpu_dsresize_size( _environment, _index, _size ) sc61860_dsresize_size( _environment, _index, _size )
#define cpu_dsgc( _environment ) sc61860_dsgc( _environment )
#define cpu_dsdescriptor( _environment, _index, _address, _size ) sc61860_dsdescriptor( _environment, _index, _address, _size )
#define cpu_dsalloc_size( _environment, _size, _index ) sc61860_dsalloc_size( _environment, _size, _index ) 
#define cpu_bit_check_extended( _environment, _value, _position, _result, _bitwidth ) sc61860_bit_check_extended( _environment, _value, _position, _result, _bitwidth )
#define cpu_bits_to_string( _environment, _number, _string, _string_size, _bits ) sc61860_bits_to_string( _environment, _number, _string, _string_size, _bits )
#define cpu_hex_to_string( _environment, _number, _string, _string_size, _bits ) sc61860_hex_to_string( _environment, _number, _string, _string_size, _bits )
#define cpu_move_8bit_with_offset2( _environment, _source, _value, _offset ) sc61860_move_8bit_with_offset2( _environment, _source, _value, _offset ) 
#define cpu_complement2_8bit( _environment, _source, _destination ) sc61860_complement2_8bit( _environment, _source, _destination )
#define cpu_complement2_16bit( _environment, _source, _destination ) sc61860_complement2_16bit( _environment, _source, _destination )
#define cpu_complement2_32bit( _environment, _source, _destination ) sc61860_complement2_32bit( _environment, _source, _destination )
#define cpu_set_callback( _environment, _callback, _label ) sc61860_set_callback( _environment, _callback, _label )
#define cpu_in( _environment, _port, _value ) sc61860_in( _environment, _port, _value )
#define cpu_out( _environment, _port, _value ) sc61860_out( _environment, _port, _value )
#define cpu_in_direct( _environment, _port, _value ) sc61860_in_direct( _environment, _port, _value )
#define cpu_out_direct( _environment, _port, _value ) sc61860_out_direct( _environment, _port, _value )
#define cpu_string_sub( _environment, _source, _source_size, _pattern, _pattern_size, _destination, _destination_size ) sc61860_string_sub( _environment, _source, _source_size, _pattern, _pattern_size, _destination, _destination_size );

#define cpu_sqroot( _environment, _number, _result ) sc61860_sqroot( _environment, _number, _result )
#define cpu_dstring_vars( _environment ) sc61860_dstring_vars( _environment )

#define cpu_protothread_vars( _environment ) sc61860_protothread_vars( _environment )
#define cpu_protothread_loop( _environment ) sc61860_protothread_loop( _environment )
#define cpu_protothread_register( _environment, _label, _index ) sc61860_protothread_register( _environment, _label, _index )
#define cpu_protothread_register_at( _environment, _index, _label ) sc61860_protothread_register_at( _environment, _index, _label )
#define cpu_protothread_unregister(_environment, _index ) sc61860_protothread_unregister(_environment, _index )
#define cpu_protothread_save( _environment, _index, _step ) sc61860_protothread_save( _environment, _index, _step )
#define cpu_protothread_restore( _environment, _index, _step ) sc61860_protothread_restore( _environment, _index, _step )
#define cpu_protothread_set_state( _environment, _index, _state ) sc61860_protothread_set_state( _environment, _index, _state )
#define cpu_protothread_get_state( _environment, _index, _state ) sc61860_protothread_get_state( _environment, _index, _state )
#define cpu_protothread_current( _environment, _current ) sc61860_protothread_current( _environment, _current )

#define cpu_msc1_uncompress_direct_direct( _environment, _input, _output ) sc61860_msc1_uncompress_direct_direct( _environment, _input, _output )
#define cpu_msc1_uncompress_direct_indirect( _environment, _input, _output ) sc61860_msc1_uncompress_direct_indirect( _environment, _input, _output )
#define cpu_msc1_uncompress_indirect_direct( _environment, _input, _output ) sc61860_msc1_uncompress_indirect_direct( _environment, _input, _output )
#define cpu_msc1_uncompress_indirect_indirect( _environment, _input, _output ) sc61860_msc1_uncompress_indirect_indirect( _environment, _input, _output )

#define cpu_blit_initialize( _environment ) sc61860_blit_initialize( _environment )
#define cpu_blit_register_name( _environment, _register ) sc61860_blit_register_name( _environment, _register )
#define cpu_blit_alloc_register( _environment ) sc61860_blit_alloc_register( _environment )
#define cpu_blit_free_register( _environment, _register ) sc61860_blit_free_register( _environment, _register )
#define cpu_blit_finalize( _environment ) sc61860_blit_finalize( _environment )

#define cpu_address_table_build( _environment, _table, _values, _address, _count ) sc61860_address_table_build( _environment, _table, _values, _address, _count )
#define cpu_address_table_lookup( _environment, _table, _count ) sc61860_address_table_lookup( _environment, _table, _count )
#define cpu_address_table_call( _environment, _table, _value, _address ) sc61860_address_table_call( _environment, _table,  _value, _address )

#define cpu_float_fast_from_double_to_int_array( _environment, _value, _result ) sc61860_float_fast_from_double_to_int_array( _environment, _value, _result )
#define cpu_float_single_from_double_to_int_array( _environment, _value, _result ) sc61860_float_single_from_double_to_int_array( _environment, _value, _result )

#define cpu_float_fast_to_string( _environment, _x, _string, _string_size ) sc61860_float_fast_to_string( _environment, _x, _string, _string_size ) 
#define cpu_float_single_to_string( _environment, _x, _string, _string_size ) sc61860_float_single_to_string( _environment, _x, _string, _string_size ) 

#define cpu_float_fast_from_16( _environment, _value, _result, _signed ) sc61860_float_fast_from_16( _environment, _value, _result, _signed ) 
#define cpu_float_single_from_16( _environment, _value, _result, _signed ) sc61860_float_single_from_16( _environment, _value, _result, _signed ) 

#define cpu_float_fast_from_8( _environment, _value, _result, _signed ) sc61860_float_fast_from_8( _environment, _value, _result, _signed ) 
#define cpu_float_single_from_8( _environment, _value, _result, _signed ) sc61860_float_single_from_8( _environment, _value, _result, _signed ) 

#define cpu_float_fast_to_16( _environment, _value, _result, _signed ) sc61860_float_fast_to_16( _environment, _value, _result, _signed ) 
#define cpu_float_single_to_16( _environment, _value, _result, _signed ) sc61860_float_single_to_16( _environment, _value, _result, _signed ) 

#define cpu_float_fast_to_8( _environment, _value, _result, _signed ) sc61860_float_fast_to_8( _environment, _value, _result, _signed ) 
#define cpu_float_single_to_8( _environment, _value, _result, _signed ) sc61860_float_single_to_8( _environment, _value, _result, _signed ) 

#define cpu_float_fast_add( _environment, _source, _destination, _result ) sc61860_float_fast_add( _environment, _source, _destination, _result ) 
#define cpu_float_single_add( _environment, _source, _destination, _result ) sc61860_float_single_add( _environment, _source, _destination, _result ) 

#define cpu_float_fast_sub( _environment, _source, _destination, _result ) sc61860_float_fast_sub( _environment, _source, _destination, _result ) 
#define cpu_float_single_sub( _environment, _source, _destination, _result ) sc61860_float_single_sub( _environment, _source, _destination, _result ) 

#define cpu_float_fast_mul( _environment, _source, _destination, _result ) sc61860_float_fast_mul( _environment, _source, _destination, _result ) 
#define cpu_float_single_mul( _environment, _source, _destination, _result ) sc61860_float_single_mul( _environment, _source, _destination, _result ) 

#define cpu_float_fast_div( _environment, _source, _destination, _result ) sc61860_float_fast_div( _environment, _source, _destination, _result ) 
#define cpu_float_single_div( _environment, _source, _destination, _result ) sc61860_float_single_div( _environment, _source, _destination, _result ) 

#define cpu_float_fast_cmp( _environment, _source, _destination, _result ) sc61860_float_fast_cmp( _environment, _source, _destination, _result ) 
#define cpu_float_single_cmp( _environment, _source, _destination, _result ) sc61860_float_single_cmp( _environment, _source, _destination, _result ) 

#define cpu_float_fast_sin( _environment, _angle, _result ) sc61860_float_fast_sin( _environment, _angle, _result ) 
#define cpu_float_single_sin( _environment, _angle, _result ) sc61860_float_single_sin( _environment, _angle, _result ) 

#define cpu_float_fast_cos( _environment, _angle, _result ) sc61860_float_fast_cos( _environment, _angle, _result ) 
#define cpu_float_single_cos( _environment, _angle, _result ) sc61860_float_single_cos( _environment, _angle, _result ) 

#define cpu_float_fast_sqr( _environment, _value, _result ) sc61860_float_fast_sqr( _environment, _value, _result ) 
#define cpu_float_single_sqr( _environment, _value, _result ) sc61860_float_single_sqr( _environment, _value, _result ) 

#define cpu_float_fast_mod1( _environment, _value, _result ) sc61860_float_fast_mod1( _environment, _value, _result ) 
#define cpu_float_single_mod1( _environment, _value, _result ) sc61860_float_single_mod1( _environment, _value, _result ) 

#define cpu_float_fast_neg( _environment, _value, _result ) sc61860_float_fast_neg( _environment, _value, _result ) 
#define cpu_float_single_neg( _environment, _value, _result ) sc61860_float_single_neg( _environment, _value, _result ) 

#define cpu_float_fast_abs( _environment, _value, _result ) sc61860_float_fast_abs( _environment, _value, _result ) 
#define cpu_float_single_abs( _environment, _value, _result ) sc61860_float_single_abs( _environment, _value, _result ) 

#define cpu_float_fast_tan( _environment, _value, _result ) sc61860_float_fast_tan( _environment, _value, _result ) 
#define cpu_float_single_tan( _environment, _value, _result ) sc61860_float_single_tan( _environment, _value, _result ) 

#define cpu_float_fast_log( _environment, _value, _result ) sc61860_float_fast_log( _environment, _value, _result ) 
#define cpu_float_single_log( _environment, _value, _result ) sc61860_float_single_log( _environment, _value, _result ) 

#define cpu_float_fast_exp( _environment, _value, _result ) sc61860_float_fast_exp( _environment, _value, _result ) 
#define cpu_float_single_exp( _environment, _value, _result ) sc61860_float_single_exp( _environment, _value, _result ) 

#define     CPU_LITTLE_ENDIAN      1
#define     REGISTER_BASE           0x1000
#define     IS_REGISTER(x)          ((x & REGISTER_BASE) == REGISTER_BASE)

typedef enum _SC61860Register {

    REGISTER_NONE   =   REGISTER_BASE | 0,

    REGISTER_A      =   REGISTER_BASE | 1,
    REGISTER_B      =   REGISTER_BASE | 2,
    REGISTER_C      =   REGISTER_BASE | 3,
    REGISTER_D      =   REGISTER_BASE | 4,
    REGISTER_E      =   REGISTER_BASE | 5,
    REGISTER_H      =   REGISTER_BASE | 6, 
    REGISTER_L      =   REGISTER_BASE | 7, 
    REGISTER_F      =   REGISTER_BASE | 8, 
    REGISTER_I      =   REGISTER_BASE | 9, 
    REGISTER_R      =   REGISTER_BASE | 10,
    REGISTER_SP     =   REGISTER_BASE | 11,
    REGISTER_PC     =   REGISTER_BASE | 12,
    REGISTER_IX     =   REGISTER_BASE | 13,
    REGISTER_IY     =   REGISTER_BASE | 14,
    REGISTER_AF     =   REGISTER_BASE | 15,
    REGISTER_BC     =   REGISTER_BASE | 16,
    REGISTER_DE     =   REGISTER_BASE | 17,
    REGISTER_HL     =   REGISTER_BASE | 18,
    REGISTER_IXL    =   REGISTER_BASE | 19,
    REGISTER_IXH    =   REGISTER_BASE | 20,
    REGISTER_IYL    =   REGISTER_BASE | 21,
    REGISTER_IYH    =   REGISTER_BASE | 22,
    REGISTER_HLA    =   REGISTER_BASE | 23,

    REGISTER_CARRY  =   REGISTER_BASE | 24,
    REGISTER_ZERO  =   REGISTER_BASE | 25

} SC61860Register;

typedef enum _SC61860Stack {

    STACK_NONE      =   0,
    STACK_BYTE      =   1,
    STACK_WORD      =   2,
    STACK_DWORD     =   3

} SC61860Stack;

#endif