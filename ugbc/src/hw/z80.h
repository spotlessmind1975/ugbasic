#ifndef __UGBC_CPU6502__
#define __UGBC_CPU6502__

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
void z80_less_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal );
void z80_less_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal );
void z80_less_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal );
void z80_greater_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal );
void z80_greater_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal );
void z80_greater_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_name, int _equal );
void z80_fill( Environment * _environment, char * _address, char * _blocks, char * _pattern );
void z80_halt( Environment * _environment );
void z80_jump( Environment * _environment, char * _label );
void z80_call( Environment * _environment, char * _label );
void z80_return( Environment * _environment );
void z80_pop( Environment * _environment );
void z80_label( Environment * _environment, char * _label );
void z80_limit_16bit( Environment * _environment, char * _variable, int _value );
void z80_logical_and_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void z80_logical_or_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void z80_logical_not_8bit( Environment * _environment, char * _value, char * _result );
void z80_math_add_16bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void z80_math_add_32bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void z80_math_add_8bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void z80_math_and_const_16bit( Environment * _environment, char *_source, int _mask );
void z80_math_and_const_32bit( Environment * _environment, char *_source, int _mask );
void z80_math_and_const_8bit( Environment * _environment, char *_source, int _mask );
void z80_math_complement_const_16bit( Environment * _environment, char *_source, int _value );
void z80_math_complement_const_32bit( Environment * _environment, char *_source, int _value );
void z80_math_complement_const_8bit( Environment * _environment, char *_source, int _value );
void z80_math_div2_8bit( Environment * _environment, char *_source, int _steps );
void z80_math_div2_const_16bit( Environment * _environment, char *_source, int _value );
void z80_math_div2_const_32bit( Environment * _environment, char *_source, int _value );
void z80_math_div2_const_8bit( Environment * _environment, char *_source, int _value );
void z80_math_double_16bit( Environment * _environment, char *_source, char *_name );
void z80_math_double_32bit( Environment * _environment, char *_source, char *_name );
void z80_math_double_8bit( Environment * _environment, char *_source, char *_name );
void z80_math_mul_16bit_to_32bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void z80_math_mul_8bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void z80_math_mul2_const_16bit( Environment * _environment, char *_source, int _value );
void z80_math_mul2_const_32bit( Environment * _environment, char *_source, int _value );
void z80_math_mul2_const_8bit( Environment * _environment, char *_source, int _value );
void z80_math_sub_16bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void z80_math_sub_32bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void z80_math_sub_8bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void z80_move_16bit( Environment * _environment, char *_source, char *_destination );
void z80_move_32bit( Environment * _environment, char *_source, char *_destination );
void z80_move_8bit( Environment * _environment, char *_source, char *_destination );
void z80_peek( Environment * _environment, char * _address, char * _target );
void z80_poke( Environment * _environment, char * _address, char * _value );
void z80_port_out( Environment * _environment, char * _port, char * _value );
void z80_random( Environment * _environment, char * _seed, char * _entropy );
void z80_random_16bit( Environment * _environment, char * _seed, char * _entropy, char * _result );
void z80_random_32bit( Environment * _environment, char * _seed, char * _entropy, char * _result );
void z80_random_8bit( Environment * _environment, char * _seed, char * _entropy, char * _result );
void z80_store_16bit( Environment * _environment, char *_source, int _value );
void z80_store_32bit( Environment * _environment, char *_source, int _value );
void z80_store_8bit( Environment * _environment, char *_source, int _value );
void z80_mem_move_displacement(  Environment * _environment, char *_source, char *_destination, char * _displacement, char *_size );
void z80_compare_memory(  Environment * _environment, char *_source, char *_destination, char * _displacement, char *_size, char * _result, int _equal );
void z80_less_than_memory(  Environment * _environment, char *_source, char *_destination, char * _displacement, char *_size, char * _result, int _equal );
void z80_greater_than_memory(  Environment * _environment, char *_source, char *_destination, char * _displacement, char *_size, char * _result, int _equal );

#define cpu_beq( _environment,  _label  ) z80_beq( _environment,  _label  )
#define cpu_bneq( _environment,  _label  ) z80_beq( _environment,  _label  )
#define cpu_busy_wait( _environment,  _timing  ) z80_busy_wait( _environment,  _timing  )
#define cpu_bveq( _environment,  _value,  _label  ) z80_bveq( _environment,  _value,  _label  )
#define cpu_bvneq( _environment,  _value,  _label  ) z80_bveq( _environment,  _value,  _label  )
#define cpu_combine_nibbles( _environment,  _low_nibble,  _hi_nibble,  _byte  ) z80_combine_nibbles( _environment,  _low_nibble,  _hi_nibble,  _byte  )
#define cpu_compare_16bit( _environment, _source, _destination, _name, _positive ) z80_compare_16bit( _environment, _source, _destination, _name, _positive )
#define cpu_compare_32bit( _environment, _source, _destination, _name, _positive ) z80_compare_32bit( _environment, _source, _destination, _name, _positive )
#define cpu_compare_8bit( _environment, _source, _destination, _name, _positive ) z80_compare_8bit( _environment, _source, _destination, _name, _positive )
#define cpu_di( _environment  ) z80_di( _environment  )
#define cpu_ei( _environment  ) z80_ei( _environment  )
#define cpu_inc( _environment, _variable ) z80_inc( _environment, _variable );
#define cpu_dec( _environment, _variable ) z80_dec( _environment, _variable );
#define cpu_less_than_16bit( _environment, _source, _destination, _name, _equal ) z80_less_than_16bit( _environment, _source, _destination, _name, _equal )
#define cpu_less_than_32bit( _environment, _source, _destination, _name, _equal ) z80_less_than_32bit( _environment, _source, _destination, _name, _equal )
#define cpu_less_than_8bit( _environment, _source, _destination, _name, _equal ) z80_less_than_8bit( _environment, _source, _destination, _name, _equal )
#define cpu_greater_than_16bit( _environment, _source, _destination, _name, _equal ) z80_greater_than_16bit( _environment, _source, _destination, _name, _equal )
#define cpu_greater_than_32bit( _environment, _source, _destination, _name, _equal ) z80_greater_than_32bit( _environment, _source, _destination, _name, _equal )
#define cpu_greater_than_8bit( _environment, _source, _destination, _name, _equal ) z80_greater_than_8bit( _environment, _source, _destination, _name, _equal )
#define cpu_fill( _environment,  _address,  _blocks,  _pattern  ) z80_fill( _environment,  _address,  _blocks,  _pattern  )
#define cpu_halt( _environment  ) z80_halt( _environment  )
#define cpu_jump( _environment,  _label  ) z80_jump( _environment,  _label  )
#define cpu_call( _environment,  _label  ) z80_call( _environment,  _label  )
#define cpu_return( _environment ) z80_return( _environment  )
#define cpu_pop( _environment ) z80_pop( _environment  )
#define cpu_label( _environment,  _label  ) z80_label( _environment,  _label  )
#define cpu_limit_16bit( _environment,  _variable, _value  ) z80_limit_16bit( _environment,  _variable, _value  )
#define cpu_logical_and_8bit( _environment, _left, _right,  _result ) z80_logical_and_8bit( _environment, _left, _right,  _result )
#define cpu_logical_or_8bit( _environment, _left, _right,  _result ) z80_logical_or_8bit( _environment, _left, _right,  _result )
#define cpu_logical_not_8bit( _environment, _value,  _result ) z80_logical_not_8bit( _environment, _value,  _result )
#define cpu_math_add_16bit( _environment, _source, _destination,  _name  ) z80_math_add_16bit( _environment, _source, _destination,  _name  )
#define cpu_math_add_32bit( _environment, _source, _destination,  _name  ) z80_math_add_32bit( _environment, _source, _destination,  _name  )
#define cpu_math_add_8bit( _environment, _source, _destination,  _name  ) z80_math_add_8bit( _environment, _source, _destination,  _name  )
#define cpu_math_and_const_16bit( _environment, _source, _mask  ) z80_math_and_const_16bit( _environment, _source, _mask  )
#define cpu_math_and_const_32bit( _environment, _source, _mask  ) z80_math_and_const_32bit( _environment, _source, _mask  )
#define cpu_math_and_const_8bit( _environment, _source, _mask  ) z80_math_and_const_8bit( _environment, _source, _mask  )
#define cpu_math_complement_const_16bit( _environment, _source, _value  ) z80_math_complement_const_16bit( _environment, _source, _value  )
#define cpu_math_complement_const_32bit( _environment, _source, _value  ) z80_math_complement_const_32bit( _environment, _source, _value  )
#define cpu_math_complement_const_8bit( _environment, _source, _value  ) z80_math_complement_const_8bit( _environment, _source, _value  )
#define cpu_math_div2_8bit( _environment, _source, _steps  ) z80_math_div2_8bit( _environment, _source, _steps  )
#define cpu_math_div2_const_16bit( _environment, _source, _value  ) z80_math_div2_const_16bit( _environment, _source, _value  )
#define cpu_math_div2_const_32bit( _environment, _source, _value  ) z80_math_div2_const_32bit( _environment, _source, _value  )
#define cpu_math_div2_const_8bit( _environment, _source, _value  ) z80_math_div2_const_8bit( _environment, _source, _value  )
#define cpu_math_double_16bit( _environment, _source, _name  ) z80_math_double_16bit( _environment, _source, _name  )
#define cpu_math_double_32bit( _environment, _source, _name  ) z80_math_double_32bit( _environment, _source, _name  )
#define cpu_math_double_8bit( _environment, _source, _name  ) z80_math_double_8bit( _environment, _source, _name  )
#define cpu_math_mul_16bit_to_32bit( _environment, _source, _destination,  _name  ) z80_math_mul_16bit_to_32bit( _environment, _source, _destination,  _name  )
#define cpu_math_mul_8bit_to_16bit( _environment, _source, _destination,  _name  ) z80_math_mul_8bit_to_16bit( _environment, _source, _destination,  _name  )
#define cpu_math_mul2_const_16bit( _environment, _source, _value  ) z80_math_mul2_const_16bit( _environment, _source, _value  )
#define cpu_math_mul2_const_32bit( _environment, _source, _value  ) z80_math_mul2_const_32bit( _environment, _source, _value  )
#define cpu_math_mul2_const_8bit( _environment, _source, _value  ) z80_math_mul2_const_8bit( _environment, _source, _value  )
#define cpu_math_sub_16bit( _environment, _source, _destination,  _name  ) z80_math_sub_16bit( _environment, _source, _destination,  _name  )
#define cpu_math_sub_32bit( _environment, _source, _destination,  _name  ) z80_math_sub_32bit( _environment, _source, _destination,  _name  )
#define cpu_math_sub_8bit( _environment, _source, _destination,  _name  ) z80_math_sub_8bit( _environment, _source, _destination,  _name  )
#define cpu_move_16bit( _environment, _source, _destination  ) z80_move_16bit( _environment, _source, _destination  )
#define cpu_move_32bit( _environment, _source, _destination  ) z80_move_32bit( _environment, _source, _destination  )
#define cpu_move_8bit( _environment, _source, _destination  ) z80_move_8bit( _environment, _source, _destination  )
#define cpu_peek( _environment,  _address,  _target  ) z80_peek( _environment,  _address,  _target  )
#define cpu_poke( _environment,  _address,  _value  ) z80_poke( _environment,  _address,  _value  )
#define cpu_random( _environment,  _seed,  _entropy  ) z80_random( _environment,  _seed,  _entropy  )
#define cpu_random_16bit( _environment,  _seed,  _entropy,  _result  ) z80_random_16bit( _environment,  _seed,  _entropy,  _result  )
#define cpu_random_32bit( _environment,  _seed,  _entropy,  _result  ) z80_random_32bit( _environment,  _seed,  _entropy,  _result  )
#define cpu_random_8bit( _environment,  _seed,  _entropy,  _result  ) z80_random_8bit( _environment,  _seed,  _entropy,  _result  )
#define cpu_store_16bit( _environment, _source, _value  ) z80_store_16bit( _environment, _source, _value  )
#define cpu_store_32bit( _environment, _source, _value  ) z80_store_32bit( _environment, _source, _value  )
#define cpu_store_8bit( _environment, _source, _value  ) z80_store_8bit( _environment, _source, _value  )
#define cpu_mem_move_displacement( _environment, _source, _destination, _displacement, _size ) z80_mem_move_displacement( _environment, _source, _destination, _displacement, _size )
#define cpu_compare_memory( _environment, _source, _destination, _size, _result, _equal ) z80_compare_memory( _environment, _source, _destination, _size, _result, _equal )
#define cpu_less_than_memory( _environment, _source, _destination, _displacement, _size, _result, _equal ) z80_less_than_memory( _environment, _source, _destination, _displacement, _size, _result, _equal )
#define cpu_greater_than_memory( _environment, _source, _destination, _displacement, char *_size, char * _result, int _equal ) z80_greater_than_memory( _environment, _source, _destination, _size, _result, _equal )

#endif