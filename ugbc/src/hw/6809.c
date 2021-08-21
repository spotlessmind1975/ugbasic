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

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../ugbc.h"

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#if defined(__d32__)

/**
 * @brief <i>CPU 6809</i>: emit code to make long conditional jump
 * 
 * This function outputs a code that guarantees an arbitrary distance jump 
 * with conditional check on equality. In fact, the opcode BEQ of the 
 * CPU 6809 processor allows to make a jump of maximum +/- 128 bytes with 
 * respect to the address where the processor is at that moment. 
 * To overcome this problem, this function will make a conditional jump to
 * a very close location, which (in turn) will make an unconditional jump 
 * to the true destination.
 * 
 * @param _environment Current calling environment
 * @param _label Destination of the conditional jump.
 */
void cpu6809_beq( Environment * _environment, char * _label ) {
    
}

/**
 * @brief <i>CPU 6809</i>: emit code to make long conditional jump
 * 
 * @param _environment Current calling environment
 * @param _label Destination of the conditional jump.
 */
void cpu6809_bneq( Environment * _environment, char * _label ) {
    
}

void cpu6809_bveq( Environment * _environment, char * _value, char * _label ) {

}

void cpu6809_bvneq( Environment * _environment, char * _value, char * _label ) {

}

void cpu6809_label( Environment * _environment, char * _label ) {

}

void cpu6809_peek( Environment * _environment, char * _address, char * _target ) {

}

void cpu6809_poke( Environment * _environment, char * _address, char * _source ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to fill up a memory area
 * 
 * This function can be used to output a piece of code that fills a given 
 * memory area with a given pattern (pattern size: 1 byte). The starting 
 * address must be contained in a variable, while the area must be a multiple 
 * of 256 bytes.
 * 
 * @param _environment Current calling environment
 * @param _address Starting address
 * @param _blocks Number of 256 bytes blocks to fill
 * @param _pattern Pattern to use
 */
void cpu6809_fill_blocks( Environment * _environment, char * _address, char * _blocks, char * _pattern ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to fill up a memory area
 * 
 * This function can be used to output a piece of code that fills a given 
 * memory area with a given pattern (pattern size: 1 byte). The starting 
 * address must be contained in a variable, while the area must be a multiple 
 * of 256 bytes.
 * 
 * @param _environment Current calling environment
 * @param _address Starting address
 * @param _bytes Number of bytes to fill
 * @param _pattern Pattern to use
 */
void cpu6809_fill( Environment * _environment, char * _address, char * _bytes, char * _pattern ) {

}

/*****************************************************************************
 * 8 BIT MANIPULATION
 ****************************************************************************/

/**
 * @brief <i>CPU 6809</i>: emit code to move 8 bit
 * 
 * @param _environment Current calling environment
 * @param _source Source of movement
 * @param _destination Destination of movement
 */
void cpu6809_move_8bit( Environment * _environment, char *_source, char *_destination ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to store 8 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void cpu6809_store_8bit( Environment * _environment, char *_destination, int _value ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _positive Invert meaning of comparison
 */
void cpu6809_compare_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void cpu6809_less_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void cpu6809_greater_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to add two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6809_math_add_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to subtract two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to subtract
 * @param _destination Second value to subtract and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6809_math_sub_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to double a 8 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6809_math_double_8bit( Environment * _environment, char *_source, char *_other, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6809_math_div2_8bit( Environment * _environment, char *_source, int _steps, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to multiply two 8bit values in a 16 bit register
 * 
 * @param _environment Current calling environment
 * @param _source First value to multipy (8 bit)
 * @param _destination Second value to multipy (8 bit)
 * @param _other Destination address for result (16 bit)
 */
void cpu6809_math_mul_8bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _signed ) {

}

void cpu6809_math_div_8bit_to_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6809_math_div2_const_8bit( Environment * _environment, char *_source, int _steps, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to double for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 */
void cpu6809_math_mul2_const_8bit( Environment * _environment, char *_source, int _steps, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to calculate an 8 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void cpu6809_math_complement_const_8bit( Environment * _environment, char *_source, int _value ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to mask with "and" a value of 8 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void cpu6809_math_and_const_8bit( Environment * _environment, char *_source, int _mask ) {

}

/*****************************************************************************
 * 16 BIT MANIPULATION
 ****************************************************************************/

/**
 * @brief <i>CPU 6809</i>: emit code to move 16 bit
 * 
 * @param _environment Current calling environment
 * @param _source Source of movement
 * @param _destination Destination of movement
 */
void cpu6809_move_16bit( Environment * _environment, char *_source, char *_destination ) {

}

void cpu6809_addressof_16bit( Environment * _environment, char *_source, char *_destination ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to store 16 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void cpu6809_store_16bit( Environment * _environment, char *_destination, int _value ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to compare two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _positive Invert meaning of comparison
 */
void cpu6809_compare_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void cpu6809_less_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void cpu6809_greater_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to add two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6809_math_add_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to add two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6809_math_add_16bit_with_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

}

void cpu6809_math_add_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to double a 16 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6809_math_double_16bit( Environment * _environment, char *_source, char *_other, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to multiply two 16 bit values in a 32 bit register
 * 
 * @param _environment Current calling environment
 * @param _source First value to multipy (16 bit)
 * @param _destination Second value to multipy (16 bit)
 * @param _other Destination address for result (32 bit)
 */
void cpu6809_math_mul_16bit_to_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _signed ) {

}

void cpu6809_math_div_16bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to subtract two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to subtract
 * @param _destination Second value to subtract and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6809_math_sub_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

}

void cpu6809_math_sub_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to calculate a 16 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void cpu6809_math_complement_const_16bit( Environment * _environment, char *_source, int _value ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to halves for several times a 16 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6809_math_div2_const_16bit( Environment * _environment, char *_source, int _steps, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6809_math_mul2_const_16bit( Environment * _environment, char *_source, int _steps, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to mask with "and" a value of 16 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void cpu6809_math_and_const_16bit( Environment * _environment, char *_source, int _mask ) {

}

/*****************************************************************************
 * 32 BIT MANIPULATION
 ****************************************************************************/

/**
 * @brief <i>CPU 6809</i>: emit code to move 32 bit
 * 
 * @param _environment Current calling environment
 * @param _source Source of movement
 * @param _destination Destination of movement
 */
void cpu6809_move_32bit( Environment * _environment, char *_source, char *_destination ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to store 32 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void cpu6809_store_32bit( Environment * _environment, char *_destination, int _value ) {

}

void cpu6809_math_div_32bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to compare two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _positive Meaning of comparison
 */
void cpu6809_compare_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to compare two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void cpu6809_less_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void cpu6809_greater_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to add two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6809_math_add_32bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to double a 32 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6809_math_double_32bit( Environment * _environment, char *_source, char *_other, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to subtract two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to subtract
 * @param _destination Second value to subtract and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6809_math_sub_32bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to calculate a 32 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void cpu6809_math_complement_const_32bit( Environment * _environment, char *_source, int _value ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to halves for several times a 32 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6809_math_div2_const_32bit( Environment * _environment, char *_source, int _steps, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to double for several times a 32 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 */
void cpu6809_math_mul2_const_32bit( Environment * _environment, char *_source, int _steps, int _signed ) {

}

/**
 * @brief <i>CPU 6809</i>: emit code to mask with "and" a value of 32 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void cpu6809_math_and_const_32bit( Environment * _environment, char *_source, int _mask ) {

}

void cpu6809_combine_nibbles( Environment * _environment, char * _low_nibble, char * _hi_nibble, char * _byte ) {

}

void cpu6809_jump( Environment * _environment, char * _label ) {

}

void cpu6809_call( Environment * _environment, char * _label ) {

}

void cpu6809_return( Environment * _environment ) {

}

void cpu6809_pop( Environment * _environment ) {

}

void cpu6809_halt( Environment * _environment ) {

}

void cpu6809_end( Environment * _environment ) {

}

void cpu6809_random( Environment * _environment, char * _seed, char * _entropy ) {

}

void cpu6809_random_8bit( Environment * _environment, char * _seed, char * _entropy, char * _result ) {

}

void cpu6809_random_16bit( Environment * _environment, char * _seed, char * _entropy, char * _result ) {

}

void cpu6809_random_32bit( Environment * _environment, char * _seed, char * _entropy, char * _result ) {

}

void cpu6809_limit_16bit( Environment * _environment, char * _variable, int _value ) {

}

void cpu6809_busy_wait( Environment * _environment, char * _timing ) {

}

void cpu6809_logical_and_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

}

void cpu6809_logical_or_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

}

void cpu6809_logical_not_8bit( Environment * _environment, char * _value, char * _result ) {

}

void cpu6809_di( Environment * _environment ) {

}

void cpu6809_ei( Environment * _environment ) {

}

void cpu6809_inc( Environment * _environment, char * _variable ) {

}

void cpu6809_inc_16bit( Environment * _environment, char * _variable ) {

}

void cpu6809_inc_32bit( Environment * _environment, char * _variable ) {

}

void cpu6809_dec( Environment * _environment, char * _variable ) {

}

void cpu6809_dec_16bit( Environment * _environment, char * _variable ) {

}

void cpu6809_mem_move( Environment * _environment, char *_source, char *_destination,  char *_size ) {

}

void cpu6809_mem_move_direct( Environment * _environment, char *_source, char *_destination,  char *_size ) {

}

void cpu6809_mem_move_size( Environment * _environment, char *_source, char *_destination, int _size ) {

}

void cpu6809_mem_move_direct_size( Environment * _environment, char *_source, char *_destination, int _size ) {

}

void cpu6809_mem_move_direct_with_offset_size( Environment * _environment, char *_source, int _offset, char *_destination, int _size ) {

}

void cpu6809_mem_move_direct_indirect_size( Environment * _environment, char *_source, char *_destination, int _size ) {

}

void cpu6809_mem_move_displacement(  Environment * _environment, char *_source, char *_destination, char * _displacement, char *_size ) {

}

void cpu6809_compare_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

}

void cpu6809_compare_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {
    
}

void cpu6809_less_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

}

void cpu6809_less_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

}

void cpu6809_greater_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

}

void cpu6809_greater_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

}

void cpu6809_store_8bit_indirect( Environment * _environment, char *_source, int _value ) {

}

void cpu6809_store_8bit_indirect_with_offset( Environment * _environment, char *_source, int _value, int _offset ) {

}


void cpu6809_move_8bit_indirect( Environment * _environment, char *_source, char * _value ) {
}

void cpu6809_move_8bit_indirect_with_offset( Environment * _environment, char *_source, char * _value, int _offset ) {
}

void cpu6809_move_8bit_with_offset( Environment * _environment, char *_source, char * _value, int _offset ) {

}

void cpu6809_move_8bit_indirect_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

}

void cpu6809_move_8bit_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

}

void cpu6809_move_8bit_indirect2( Environment * _environment, char * _value, char *_source ) {

}

void cpu6809_move_16bit_indirect( Environment * _environment, char *_source, char * _value ) {

}

void cpu6809_move_16bit_indirect2( Environment * _environment, char * _value, char *_source ) {

}

void cpu6809_move_32bit_indirect( Environment * _environment, char *_source, char * _value ) {

}

void cpu6809_move_32bit_indirect2( Environment * _environment, char * _value, char *_source ) {

}

void cpu6809_uppercase( Environment * _environment, char *_source, char *_size, char *_result ) {

}

void cpu6809_lowercase( Environment * _environment, char *_source, char *_size, char *_result ) {


}

void cpu6809_convert_upto_24bit_bcd( Environment * _environment, char * _source, char * _dest, int _bits ) {

}

void cpu6809_convert_bcd_to_digits( Environment * _environment, char * _source, char * _dest ) {

}

void cpu6809_convert_string_into_16bit( Environment * _environment, char * _string, char * _len, char * _value ) {

}

void cpu6809_fill_indirect( Environment * _environment, char * _address, char * _size, char * _pattern ) {

}

void cpu6809_flip( Environment * _environment, char * _source, char * _size, char * _destination ) {
}

void cpu6809_bit_check( Environment * _environment, char * _value, int _position, char *_result ) {

}

void cpu6809_bit_check_extended( Environment * _environment, char * _value, char * _position, char *_result ) {
}

void cpu6809_number_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits, int _signed ) {
}

void cpu6809_bits_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits ) {

}

void cpu6809_dsdefine( Environment * _environment, char * _string, char * _index ) {
    
}

void cpu6809_dsalloc( Environment * _environment, char * _size, char * _index ) {

}

void cpu6809_dsalloc_size( Environment * _environment, int _size, char * _index ) {

}

void cpu6809_dsfree( Environment * _environment, char * _index ) {

}

void cpu6809_dswrite( Environment * _environment, char * _index ) {

}

void cpu6809_dsresize( Environment * _environment, char * _index, char * _resize ) {

}

void cpu6809_dsresize_size( Environment * _environment, char * _index, int _resize ) {

}

void cpu6809_dsgc( Environment * _environment ) {

}

void cpu6809_dsdescriptor( Environment * _environment, char * _index, char * _address, char * _size ) {

}

void cpu6809_store_8bit_with_offset( Environment * _environment, char *_destination, int _value, int _offset ) {

}

void cpu6809_complement2_8bit( Environment * _environment, char * _source, char * _destination ) {

}

void cpu6809_complement2_16bit( Environment * _environment, char * _source, char * _destination ) {

}

void cpu6809_complement2_32bit( Environment * _environment, char * _source, char * _destination ) {

}

char * src_hw_chipset_mob_asm;
unsigned int src_hw_chipset_mob_asm_len;

void cpu6809_mobinit( Environment * _environment, char * _index, char *_x, char *_y,  char *_draw) {

}

void cpu6809_mobshow( Environment * _environment, char * _index ) {

}

void cpu6809_mobhide( Environment * _environment, char * _index ) {

}

void cpu6809_mobat( Environment * _environment, char * _index, char *_x, char *_y ) {

}

void cpu6809_mobrender( Environment * _environment, int _on_vbl ) {

}

void cpu6809_sqroot( Environment * _environment, char * _number, char * _result ) {

}


#endif