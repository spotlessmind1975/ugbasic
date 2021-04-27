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

void cpu6502_beq( Environment * _environment, char * _label );
void cpu6502_busy_wait( Environment * _environment, char * _timing );
void cpu6502_bveq( Environment * _environment, char * _value, char * _label );
void cpu6502_combine_nibbles( Environment * _environment, char * _low_nibble, char * _hi_nibble, char * _byte );
void cpu6502_compare_16bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu6502_compare_32bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu6502_compare_8bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu6502_fill( Environment * _environment, char * _address, char * _blocks, char * _pattern );
void cpu6502_halt( Environment * _environment );
void cpu6502_jump( Environment * _environment, char * _label );
void cpu6502_call( Environment * _environment, char * _label );
void cpu6502_pop( Environment * _environment );
void cpu6502_return( Environment * _environment );
void cpu6502_label( Environment * _environment, char * _label );
void cpu6502_limit_16bit( Environment * _environment, char * _variable, int _value );
void cpu6502_logical_and_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void cpu6502_logical_or_8bit( Environment * _environment, char * _left, char * _right, char * _result );
void cpu6502_math_add_16bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu6502_math_add_32bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu6502_math_add_8bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu6502_math_and_const_16bit( Environment * _environment, char *_source, int _mask );
void cpu6502_math_and_const_32bit( Environment * _environment, char *_source, int _mask );
void cpu6502_math_and_const_8bit( Environment * _environment, char *_source, int _mask );
void cpu6502_math_complement_const_16bit( Environment * _environment, char *_source, int _value );
void cpu6502_math_complement_const_32bit( Environment * _environment, char *_source, int _value );
void cpu6502_math_complement_const_8bit( Environment * _environment, char *_source, int _value );
void cpu6502_math_div2_8bit( Environment * _environment, char *_source, int _steps );
void cpu6502_math_div2_const_16bit( Environment * _environment, char *_source, int _value );
void cpu6502_math_div2_const_32bit( Environment * _environment, char *_source, int _value );
void cpu6502_math_div2_const_8bit( Environment * _environment, char *_source, int _value );
void cpu6502_math_double_16bit( Environment * _environment, char *_source, char *_name );
void cpu6502_math_double_32bit( Environment * _environment, char *_source, char *_name );
void cpu6502_math_double_8bit( Environment * _environment, char *_source, char *_name );
void cpu6502_math_mul_16bit_to_32bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu6502_math_mul_8bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu6502_math_mul2_const_16bit( Environment * _environment, char *_source, int _value );
void cpu6502_math_mul2_const_32bit( Environment * _environment, char *_source, int _value );
void cpu6502_math_mul2_const_8bit( Environment * _environment, char *_source, int _value );
void cpu6502_math_sub_16bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu6502_math_sub_32bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu6502_math_sub_8bit( Environment * _environment, char *_source, char *_destination,  char *_name );
void cpu6502_move_16bit( Environment * _environment, char *_source, char *_destination );
void cpu6502_move_32bit( Environment * _environment, char *_source, char *_destination );
void cpu6502_move_8bit( Environment * _environment, char *_source, char *_destination );
void cpu6502_peek( Environment * _environment, char * _address, char * _target );
void cpu6502_poke( Environment * _environment, char * _address, char * _value );
void cpu6502_random( Environment * _environment, char * _seed, char * _entropy );
void cpu6502_random_16bit( Environment * _environment, char * _seed, char * _entropy, char * _result );
void cpu6502_random_32bit( Environment * _environment, char * _seed, char * _entropy, char * _result );
void cpu6502_random_8bit( Environment * _environment, char * _seed, char * _entropy, char * _result );
void cpu6502_store_16bit( Environment * _environment, char *_source, int _value );
void cpu6502_store_32bit( Environment * _environment, char *_source, int _value );
void cpu6502_store_8bit( Environment * _environment, char *_source, int _value );

#define cpu_beq( _environment,  _label  ) cpu6502_beq( _environment,  _label  )
#define cpu_busy_wait( _environment,  _timing  ) cpu6502_busy_wait( _environment,  _timing  )
#define cpu_bveq( _environment,  _value,  _label  ) cpu6502_bveq( _environment,  _value,  _label  )
#define cpu_combine_nibbles( _environment,  _low_nibble,  _hi_nibble,  _byte  ) cpu6502_combine_nibbles( _environment,  _low_nibble,  _hi_nibble,  _byte  )
#define cpu_compare_16bit( _environment, _source, _destination,  _name  ) cpu6502_compare_16bit( _environment, _source, _destination,  _name  )
#define cpu_compare_32bit( _environment, _source, _destination,  _name  ) cpu6502_compare_32bit( _environment, _source, _destination,  _name  )
#define cpu_compare_8bit( _environment, _source, _destination,  _name  ) cpu6502_compare_8bit( _environment, _source, _destination,  _name  )
#define cpu_fill( _environment,  _address,  _blocks,  _pattern  ) cpu6502_fill( _environment,  _address,  _blocks,  _pattern  )
#define cpu_halt( _environment  ) cpu6502_halt( _environment  )
#define cpu_jump( _environment,  _label  ) cpu6502_jump( _environment,  _label  )
#define cpu_call( _environment,  _label  ) cpu6502_call( _environment,  _label  )
#define cpu_return( _environment  ) cpu6502_return( _environment )
#define cpu_pop( _environment  ) cpu6502_pop( _environment )
#define cpu_label( _environment,  _label  ) cpu6502_label( _environment,  _label  )
#define cpu_limit_16bit( _environment,  _variable, _value  ) cpu6502_limit_16bit( _environment,  _variable, _value  )
#define cpu_logical_and_8bit( _environment, _left, _right,  _result ) cpu6502_logical_and_8bit( _environment, _left, _right,  _result )
#define cpu_logical_or_8bit( _environment, _left, _right,  _result ) cpu6502_logical_or_8bit( _environment, _left, _right,  _result )
#define cpu_math_add_16bit( _environment, _source, _destination,  _name  ) cpu6502_math_add_16bit( _environment, _source, _destination,  _name  )
#define cpu_math_add_32bit( _environment, _source, _destination,  _name  ) cpu6502_math_add_32bit( _environment, _source, _destination,  _name  )
#define cpu_math_add_8bit( _environment, _source, _destination,  _name  ) cpu6502_math_add_8bit( _environment, _source, _destination,  _name  )
#define cpu_math_and_const_16bit( _environment, _source, _mask  ) cpu6502_math_and_const_16bit( _environment, _source, _mask  )
#define cpu_math_and_const_32bit( _environment, _source, _mask  ) cpu6502_math_and_const_32bit( _environment, _source, _mask  )
#define cpu_math_and_const_8bit( _environment, _source, _mask  ) cpu6502_math_and_const_8bit( _environment, _source, _mask  )
#define cpu_math_complement_const_16bit( _environment, _source, _value  ) cpu6502_math_complement_const_16bit( _environment, _source, _value  )
#define cpu_math_complement_const_32bit( _environment, _source, _value  ) cpu6502_math_complement_const_32bit( _environment, _source, _value  )
#define cpu_math_complement_const_8bit( _environment, _source, _value  ) cpu6502_math_complement_const_8bit( _environment, _source, _value  )
#define cpu_math_div2_8bit( _environment, _source, _steps  ) cpu6502_math_div2_8bit( _environment, _source, _steps  )
#define cpu_math_div2_const_16bit( _environment, _source, _value  ) cpu6502_math_div2_const_16bit( _environment, _source, _value  )
#define cpu_math_div2_const_32bit( _environment, _source, _value  ) cpu6502_math_div2_const_32bit( _environment, _source, _value  )
#define cpu_math_div2_const_8bit( _environment, _source, _value  ) cpu6502_math_div2_const_8bit( _environment, _source, _value  )
#define cpu_math_double_16bit( _environment, _source, _name  ) cpu6502_math_double_16bit( _environment, _source, _name  )
#define cpu_math_double_32bit( _environment, _source, _name  ) cpu6502_math_double_32bit( _environment, _source, _name  )
#define cpu_math_double_8bit( _environment, _source, _name  ) cpu6502_math_double_8bit( _environment, _source, _name  )
#define cpu_math_mul_16bit_to_32bit( _environment, _source, _destination,  _name  ) cpu6502_math_mul_16bit_to_32bit( _environment, _source, _destination,  _name  )
#define cpu_math_mul_8bit_to_16bit( _environment, _source, _destination,  _name  ) cpu6502_math_mul_8bit_to_16bit( _environment, _source, _destination,  _name  )
#define cpu_math_mul2_const_16bit( _environment, _source, _value  ) cpu6502_math_mul2_const_16bit( _environment, _source, _value  )
#define cpu_math_mul2_const_32bit( _environment, _source, _value  ) cpu6502_math_mul2_const_32bit( _environment, _source, _value  )
#define cpu_math_mul2_const_8bit( _environment, _source, _value  ) cpu6502_math_mul2_const_8bit( _environment, _source, _value  )
#define cpu_math_sub_16bit( _environment, _source, _destination,  _name  ) cpu6502_math_sub_16bit( _environment, _source, _destination,  _name  )
#define cpu_math_sub_32bit( _environment, _source, _destination,  _name  ) cpu6502_math_sub_32bit( _environment, _source, _destination,  _name  )
#define cpu_math_sub_8bit( _environment, _source, _destination,  _name  ) cpu6502_math_sub_8bit( _environment, _source, _destination,  _name  )
#define cpu_move_16bit( _environment, _source, _destination  ) cpu6502_move_16bit( _environment, _source, _destination  )
#define cpu_move_32bit( _environment, _source, _destination  ) cpu6502_move_32bit( _environment, _source, _destination  )
#define cpu_move_8bit( _environment, _source, _destination  ) cpu6502_move_8bit( _environment, _source, _destination  )
#define cpu_peek( _environment,  _address,  _target  ) cpu6502_peek( _environment,  _address,  _target  )
#define cpu_poke( _environment,  _address,  _value  ) cpu6502_poke( _environment,  _address,  _value  )
#define cpu_random( _environment,  _seed,  _entropy  ) cpu6502_random( _environment,  _seed,  _entropy  )
#define cpu_random_16bit( _environment,  _seed,  _entropy,  _result  ) cpu6502_random_16bit( _environment,  _seed,  _entropy,  _result  )
#define cpu_random_32bit( _environment,  _seed,  _entropy,  _result  ) cpu6502_random_32bit( _environment,  _seed,  _entropy,  _result  )
#define cpu_random_8bit( _environment,  _seed,  _entropy,  _result  ) cpu6502_random_8bit( _environment,  _seed,  _entropy,  _result  )
#define cpu_store_16bit( _environment, _source, _value  ) cpu6502_store_16bit( _environment, _source, _value  )
#define cpu_store_32bit( _environment, _source, _value  ) cpu6502_store_32bit( _environment, _source, _value  )
#define cpu_store_8bit( _environment, _source, _value  ) cpu6502_store_8bit( _environment, _source, _value  )

#endif