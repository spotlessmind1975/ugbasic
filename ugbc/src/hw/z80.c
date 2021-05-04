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

#ifdef __zx__

/**
 * @brief <i>Z80</i>: emit code to make long conditional jump
 * 
 * This function outputs a code that guarantees an arbitrary distance jump 
 * with conditional check on equality. In fact, the opcode BEQ of the 
 * Z80 processor allows to make a jump of maximum +/- 128 bytes with 
 * respect to the address where the processor is at that moment. 
 * To overcome this problem, this function will make a conditional jump to
 * a very close location, which (in turn) will make an unconditional jump 
 * to the true destination.
 * 
 * @param _environment Current calling environment
 * @param _label Destination of the conditional jump.
 */
void z80_beq( Environment * _environment, char * _label ) {

    MAKE_LABEL

    outline1("JP Z, %s", label);
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline1("JMP %s", _label);
    outhead1("%s2:", label);

}

/**
 * @brief <i>Z80</i>: emit code to make long conditional jump

 * @param _environment Current calling environment
 * @param _label Destination of the conditional jump.
 */
void z80_bneq( Environment * _environment, char * _label ) {

    MAKE_LABEL

    outline1("JP NZ, %s", label);
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline1("JMP %s", _label);
    outhead1("%s2:", label);

}

void z80_bveq( Environment * _environment, char * _value, char * _label ) {

    outline1("LD A, (%s)", _value);
    z80_beq( _environment, _label );

}

void z80_bvneq( Environment * _environment, char * _value, char * _label ) {

    outline1("LD A, (%s)", _value);
    z80_bneq( _environment, _label );

}

void z80_label( Environment * _environment, char * _label ) {
    outhead1("%s:", _label);
}

void z80_peek( Environment * _environment, char * _address, char * _target ) {

    outline1("LD A, (%s)", _address);
    outline1("LD (%s), A", _target);

}

void z80_poke( Environment * _environment, char * _address, char * _source ) {

    outline1("LD A, (%s)", _source);
    outline1("LD (%s), A", _address);

}

/**
 * @brief <i>Z80</i>: emit code to fill up a memory area
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
void z80_fill( Environment * _environment, char * _address, char * _blocks, char * _pattern ) {

    outline1("LD A,(%s)", _pattern);
    outline1("LD HL,(%s)", _address);
    outline0("LD (HL),A")
    outline0("LD E,L");
    outline0("LD D,H");
    outline0("INC DE");
    outline0("LD (DE),A")
    outline0("LD C,255");
    outline1("LD B,%s", _blocks);
    outline0("LDIR");

}

/*****************************************************************************
 * 8 BIT MANIPULATION
 ****************************************************************************/

/**
 * @brief <i>Z80</i>: emit code to move 8 bit
 * 
 * @param _environment Current calling environment
 * @param _source Source of movement
 * @param _destination Destination of movement
 */
void z80_move_8bit( Environment * _environment, char *_source, char *_destination ) {
    
    outline1("LD A, (%s)", _source);
    outline1("LD (%s), A", _destination);

}

/**
 * @brief <i>Z80</i>: emit code to store 8 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void z80_store_8bit( Environment * _environment, char *_destination, int _value ) {

    outline1("LD A, $%2.2x", _value);
    outline1("LD (%s), A", _destination);

}

/**
 * @brief <i>Z80</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _positive Meaning of comparison
 */
void z80_compare_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s)", _destination);
    outline0("CP B");
    outline1("JP NZ, %s", label);
    outline1("LD A, %d", _positive);
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline1("LD A, %d", (1-_positive));
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outhead1("%s2:", label);

}

/**
 * @brief <i>Z80</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void z80_less_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s)", _destination);
    outline0("CP B");
    outline1("JR C, %s", label);
    if ( _equal ) {
        outline1("JR Z, %s", label);
    }
    outline0("LD A, 0");
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline0("LD A, 1");
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outhead1("%s2:", label);

}

/**
 * @brief <i>Z80</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void z80_greater_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s)", _destination);
    outline0("CP B");
    outline1("JR NC, %s", label);
    if ( !_equal ) {
        outline1("JR NZ, %s", label);
    }
    outline0("LD A, 0");
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline0("LD A, 1");
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outhead1("%s2:", label);

}

/**
 * @brief <i>Z80</i>: emit code to add two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void z80_math_add_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    outline0("LD B, 0" );
    outline1("LD A, (%s)", _source );
    outline0("ADD A, B" );
    outline0("LD B, A" );
    outline1("LD A, (%s)", _destination );
    outline0("ADD A, B" );
    if ( _other ) {
        outline1("LD (%s), A", _other );
    } else {
        outline1("LD (%s), A", _destination );
    }

}

/**
 * @brief <i>Z80</i>: emit code to subtract two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to subtract
 * @param _destination Second value to subtract and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void z80_math_sub_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    outline0("LD B, 0" );
    outline1("LD A, (%s)", _source );
    outline0("SUB A, B" );
    outline0("LD B, A" );
    outline1("LD A, (%s)", _destination );
    outline0("SUB A,B" );
    if ( _other ) {
        outline1("LD (%s), A", _other );
    } else {
        outline1("LD (%s), A", _destination );
    }

}

/**
 * @brief <i>Z80</i>: emit code to double a 8 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void z80_math_double_8bit( Environment * _environment, char *_source, char *_other ) {

    outline1("LD A, (%s)", _source );
    outline0("ADD A, A" );
    if ( _other ) {
        outline1("LD (%s), A", _other );
    } else {
        outline1("LD (%s), A", _source );
    }
}

/**
 * @brief <i>Z80</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void z80_math_div2_8bit( Environment * _environment, char *_source, int _steps ) {

    outline1("LD A, (%s)", _source );
    while( _steps ) {
        outline0("SRA A" );
        --_steps;
    }
    outline1("LD (%s), A", _source );

}

/**
 * @brief <i>Z80</i>: emit code to multiply two 8bit values in a 16 bit register
 * 
 * @param _environment Current calling environment
 * @param _source First value to multipy (8 bit)
 * @param _destination Second value to multipy (8 bit)
 * @param _other Destination address for result (16 bit)
 */

void z80_math_mul_8bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    MAKE_LABEL

    outline1("LD H, (%s)", _source );
    outline1("LD A, (%s)", _destination );
    outline0("LD E, A" );

    outline0("LD D,0");
    outline0("LD L,D");
    outline0("LD B,8");

    outhead1("%s:", label );
    outline0("ADD HL, HL" );
    outline1("JR NC,%s2", label );
    outline0("ADD HL, DE" );

    outhead1("%s2:", label );

    outline1("DJNZ %s", label );
    outline1("LD (%s), HL", _other );

}

/**
 * @brief <i>Z80</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void z80_math_div2_const_8bit( Environment * _environment, char *_source, int _steps ) {

    outline1("LD A, (%s)", _source );
    while( _steps ) {
        outline0("SRA A" );
        --_steps;
    }
    outline1("LD (%s), A", _source );

}

/**
 * @brief <i>Z80</i>: emit code to double for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 */
void z80_math_mul2_const_8bit( Environment * _environment, char *_source, int _steps ) {

    outline1("LD A, (%s)", _source );
    while( _steps ) {
        outline0("SLA A" );
        --_steps;
    }
    outline1("LD (%s), A", _source );

}

/**
 * @brief <i>Z80</i>: emit code to calculate an 8 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void z80_math_complement_const_8bit( Environment * _environment, char *_source, int _value ) {

    outline1("LD A, $%2.2x", _value );
    outline1("SUB A, (%s)", _source );
    outline1("LD (%s), A", _source );

}

/**
 * @brief <i>Z80</i>: emit code to mask with "and" a value of 8 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void z80_math_and_const_8bit( Environment * _environment, char *_source, int _mask ) {

    outline1("LD A, (%s)", _source );
    outline1("AND $%2.2x", _mask );
    outline1("LD (%s), A", _source );

}

/*****************************************************************************
 * 16 BIT MANIPULATION
 ****************************************************************************/

/**
 * @brief <i>Z80</i>: emit code to move 16 bit
 * 
 * @param _environment Current calling environment
 * @param _source Source of movement
 * @param _destination Destination of movement
 */
void z80_move_16bit( Environment * _environment, char *_source, char *_destination ) {
    
    outline1("LD A, (%s)", _source );
    outline1("LD (%s), A", _destination );
    outline1("LD A, (%s+1)", _source );
    outline1("LD (%s+1), A", _destination );

}

/**
 * @brief <i>Z80</i>: emit code to store 16 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void z80_store_16bit( Environment * _environment, char *_destination, int _value ) {

    outline1("LD A, $%2.2x", _value & 0xff );
    outline1("LD (%s), A", _destination );
    outline1("LD A, $%2.2x", ( ( _value >> 8 ) & 0xff ) );
    outline1("LD (%s+1), A", _destination );

}

/**
 * @brief <i>Z80</i>: emit code to compare two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void z80_compare_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s)", _destination);
    outline0("CP B");
    outline1("JP NZ, %s", label);
    outline1("LD A, (%s+1)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s+1)", _destination);
    outline0("CP B");
    outline1("JP NZ, %s", label);
    outline1("LD A, %d", _positive);
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline1("LD A, %d", (1-_positive));
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outhead1("%s2:", label);

}

/**
 * @brief <i>Z80</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void z80_less_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal ) {

    MAKE_LABEL

    outline1("LD A, (%s+1)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s+1)", _destination);
    outline0("CP B");
    outline1("JR C, %s", label);
    outline1("LD A, (%s)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s)", _destination);
    outline0("CP B");
    outline1("JR C, %s", label);
    if ( _equal ) {
        outline1("JR Z, %s", label);
    }
    outline0("LD A, 0");
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline0("LD A, 1");
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outhead1("%s2:", label);

}

/**
 * @brief <i>Z80</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void z80_greater_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal ) {

    MAKE_LABEL

    outline1("LD A, (%s+1)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s+1)", _destination);
    outline0("CP B");
    outline1("JR NC, %s", label);
    outline1("LD A, (%s)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s)", _destination);
    outline0("CP B");
    outline1("JR NC, %s", label);
    if ( !_equal ) {
        outline1("JR NZ, %s", label);
    }
    outline0("LD A, 0");
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline0("LD A, 1");
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outhead1("%s2:", label);

}

/**
 * @brief <i>Z80</i>: emit code to add two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void z80_math_add_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    outline1("LD HL, (%s)", _source );
    outline1("LD DE, (%s)", _destination );
    outline0("ADD HL, DE" );
    if ( _other ) {
        outline1("LD (%s), HL", _other );
    } else {
        outline1("LD (%s), HL", _destination );
    }

}

/**
 * @brief <i>Z80</i>: emit code to double a 16 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void z80_math_double_16bit( Environment * _environment, char *_source, char *_other ) {
    
    outline1("LD DE, (%s)", _source );
    outline0("SLA E" );
    outline0("RL D" );
    if ( _other ) {
        outline1("LD (%s), DE", _other );
    } else {
        outline1("LD (%s), DE", _source );
    }

}

/**
 * @brief <i>Z80</i>: emit code to multiply two 16 bit values in a 32 bit register
 * 
 * @param _environment Current calling environment
 * @param _source First value to multipy (16 bit)
 * @param _destination Second value to multipy (16 bit)
 * @param _other Destination address for result (32 bit)
 */
void z80_math_mul_16bit_to_32bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    MAKE_LABEL

    outline1("LD BC, (%s)", _source );
    outline1("LD DE, (%s)", _destination );
    outline0("LD A, C" );
    outline0("LD C, B" );
    outline0("LD HL, 0" );
    outline0("LD B, 16" );
    outhead1("%s:", label );
    outline0("ADD HL, HL" );
    outline0("RLA " );
    outline0("RL C" );
    outline1("JR NC,%s2", label );
    outline0("ADD HL, DE" );
    outline0("ADC A, 0" );
    outline1("JP NC,%s2", label );
    outline0("INC C" );
    outhead1("%s2:", label );
    outline1("DJNZ %s", label );
    outline0("LD B, C" );
    outline0("LD C, A" );
    outline1("LD (%s), BC", _other );
    outline1("LD (%s+2), HL", _other );

}

/**
 * @brief <i>Z80</i>: emit code to subtract two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to subtract
 * @param _destination Second value to subtract and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void z80_math_sub_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    outline1("LD HL, (%s)", _source );
    outline1("LD DE, (%s)", _destination );
    outline0("SUB HL, DE" );
    if ( _other ) {
        outline1("LD (%s), HL", _other );
    } else {
        outline1("LD (%s), HL", _destination );
    }

}

/**
 * @brief <i>Z80</i>: emit code to calculate a 16 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void z80_math_complement_const_16bit( Environment * _environment, char *_source, int _value ) {

    outline1("LD HL, $%4.4x", _value );
    outline1("SUB HL, (%s)", _source );
    outline1("LD (%s), A", _source );

}

/**
 * @brief <i>Z80</i>: emit code to halves for several times a 16 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void z80_math_div2_const_16bit( Environment * _environment, char *_source, int _steps ) {

    outline1("LD HL, (%s)", _source );
    outline0("LD AF, HL" );
    while( _steps ) {
        outline0("SRA A" );
        outline0("RR F" );
        --_steps;
    }
    outline0("LD HL, AF" );
    outline1("LD (%s), HL", _source );

}

/**
 * @brief <i>Z80</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void z80_math_mul2_const_16bit( Environment * _environment, char *_source, int _steps ) {

    outline1("LD HL, (%s)", _source );
    outline0("LD AF, HL" );
    while( _steps ) {
        outline0("SLA A" );
        outline0("RL F" );
        --_steps;
    }
    outline0("LD HL, AF" );
    outline1("LD (%s), HL", _source );

}

/**
 * @brief <i>Z80</i>: emit code to mask with "and" a value of 16 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void z80_math_and_const_16bit( Environment * _environment, char *_source, int _mask ) {

    outline1("LD HL, (%s)", _source );
    outline0("LD AF, HL" );
    outline1("AND $%4.4x", _mask );
    outline0("LD HL, AF" );
    outline1("LD (%s), HL", _source );

}

/*****************************************************************************
 * 32 BIT MANIPULATION
 ****************************************************************************/

/**
 * @brief <i>Z80</i>: emit code to move 32 bit
 * 
 * @param _environment Current calling environment
 * @param _source Source of movement
 * @param _destination Destination of movement
 */
void z80_move_32bit( Environment * _environment, char *_source, char *_destination ) {

    outline1("LD A, (%s)", _source );
    outline1("LD (%s), A", _destination );
    outline1("LD A, (%s+1)", _source );
    outline1("LD (%s+1), A", _destination );
    outline1("LD A, (%s+2)", _source );
    outline1("LD (%s+2), A", _destination );
    outline1("LD A, (%s+3)", _source );
    outline1("LD (%s+3), A", _destination );

}

/**
 * @brief <i>Z80</i>: emit code to store 32 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void z80_store_32bit( Environment * _environment, char *_destination, int _value ) {

    outline1("LD A, $%2.2x", ( _value & 0xff ) );
    outline1("LD (%s), A", _destination );
    outline1("LD A, $%2.2x", ( ( _value >> 8 ) & 0xff ) );
    outline1("LD (%s+1), A", _destination );
    outline1("LD A, $%2.2x", ( ( _value >> 16 ) & 0xff ) );
    outline1("LD (%s+2), A", _destination );
    outline1("LD A, $%2.2x", ( ( _value >> 24 ) & 0xff ) );
    outline1("LD (%s+3), A", _destination );

}

/**
 * @brief <i>Z80</i>: emit code to compare two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _positive Meaning of comparison
 */
void z80_compare_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s)", _destination);
    outline0("CP B");
    outline1("JP NZ, %s", label);
    outline1("LD A, (%s+1)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s+1)", _destination);
    outline0("CP B");
    outline1("JP NZ, %s", label);
    outline1("LD A, (%s+2)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s+2)", _destination);
    outline0("CP B");
    outline1("JP NZ, %s", label);
    outline1("LD A, (%s+3)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s+3)", _destination);
    outline0("CP B");
    outline1("JP NZ, %s", label);
    outline1("LD A, %d", _positive);
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline1("LD A, %d", (1-_positive));
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outhead1("%s2:", label);

}

/**
 * @brief <i>Z80</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void z80_less_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal ) {

    MAKE_LABEL

    outline1("LD A, (%s+3)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s+3)", _destination);
    outline0("CP B");
    outline1("JR C, %s", label);
    outline1("LD A, (%s+2)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s+2)", _destination);
    outline0("CP B");
    outline1("JR C, %s", label);
    outline1("LD A, (%s+1)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s+1)", _destination);
    outline0("CP B");
    outline1("JR C, %s", label);
    outline1("LD A, (%s)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s)", _destination);
    outline0("CP B");
    outline1("JR C, %s", label);
    if ( _equal ) {
        outline1("JR Z, %s", label);
    }
    outline0("LD A, 0");
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline0("LD A, 1");
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outhead1("%s2:", label);

}

/**
 * @brief <i>Z80</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void z80_greater_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal ) {

    MAKE_LABEL

    outline1("LD A, (%s+3)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s+3)", _destination);
    outline0("CP B");
    outline1("JR NC, %s", label);
    outline1("LD A, (%s+2)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s+2)", _destination);
    outline0("CP B");
    outline1("JR NC, %s", label);
    outline1("LD A, (%s+1)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s+1)", _destination);
    outline0("CP B");
    outline1("JR NC, %s", label);
    outline1("LD A, (%s)", _source);
    outline0("LD B, A");
    outline1("LD A, (%s)", _destination);
    outline0("CP B");
    outline1("JR NC, %s", label);
    if ( !_equal ) {
        outline1("JR NZ, %s", label);
    }
    outline0("LD A, 0");
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline0("LD A, 1");
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outhead1("%s2:", label);

}

/**
 * @brief <i>Z80</i>: emit code to add two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void z80_math_add_32bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    outline1("LD HL, (%s)", _source );
    outline1("LD DE, (%s)", _destination );
    outline0("EXX" );
    outline1("LD HL, (%s+2)", _source );
    outline1("LD DE, (%s+2)", _destination );
    outline0("ADD HL, DE" );
    outline0("EXX" );
    outline0("ADD HL, DE" );
    outline0("EXX" );
    if ( _other ) {
        outline1("LD (%s), HL", _other );
        outline1("LD (%s+2), DE", _other );
    } else {
        outline1("LD (%s), HL", _destination );
        outline1("LD (%s+2), DE", _destination );
    }

}

/**
 * @brief <i>Z80</i>: emit code to double a 32 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 * @todo Not yet implemented
 */
void z80_math_double_32bit( Environment * _environment, char *_source, char *_other ) {

    // TODO: z80_math_double_32bit

}

/**
 * @brief <i>Z80</i>: emit code to subtract two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to subtract
 * @param _destination Second value to subtract and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void z80_math_sub_32bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    outline1("LD HL, (%s)", _source );
    outline1("LD DE, (%s)", _destination );
    outline0("EXX" );
    outline1("LD HL, (%s+2)", _source );
    outline1("LD DE, (%s+2)", _destination );
    outline0("SUB HL, DE" );
    outline0("EXX" );
    outline0("SUB HL, DE" );
    outline0("EXX" );
    if ( _other ) {
        outline1("LD (%s), HL", _other );
        outline1("LD (%s+2), DE", _other );
    } else {
        outline1("LD (%s), HL", _destination );
        outline1("LD (%s+2), DE", _destination );
    }

}

/**
 * @brief <i>Z80</i>: emit code to calculate a 32 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void z80_math_complement_const_32bit( Environment * _environment, char *_source, int _value ) {

    outline1("LD HL, $%4.4x", ( (_value & 0xffff ) ) );
    outline1("LD DE, $%4.4x", ( ( ( _value >> 16 ) & 0xffff ) ) );
    outline0("EXX" );
    outline1("LD HL, (%s)", _source );
    outline1("LD DE, (%s+2)", _source );
    outline0("SUB HL, DE" );
    outline0("EXX" );
    outline0("SUB HL, DE" );
    outline0("EXX" );
    outline1("LD (%s), HL", _source );
    outline1("LD (%s+2), DE", _source );

}

/**
 * @brief <i>Z80</i>: emit code to halves for several times a 32 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void z80_math_div2_const_32bit( Environment * _environment, char *_source, int _steps ) {

    outline1("ld de,(%s)", _source );
    outline1("ld bc,(%s+2)", _source );
    outline0("SRA B" );
    outline0("RR C" );
    outline0("RR D" );
    outline0("RR E" );

}

/**
 * @brief <i>Z80</i>: emit code to double for several times a 32 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 * @todo Not yet implemented
 */
void z80_math_mul2_const_32bit( Environment * _environment, char *_source, int _steps ) {

}

/**
 * @brief <i>Z80</i>: emit code to mask with "and" a value of 32 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 * @todo Not yet implemented
 */
void z80_math_and_const_32bit( Environment * _environment, char *_source, int _mask ) {

    // TODO: z80_math_and_const_32bit

}

/**
 * @brief <i>Z80</i>: emit code to combine nibbles
 * 
 * @todo Not yet implemented
 */
void z80_combine_nibbles( Environment * _environment, char * _low_nibble, char * _hi_nibble, char * _byte ) {

    // TODO: z80_combine_nibbles

}

void z80_jump( Environment * _environment, char * _label ) {

    outline1("jp %s", _label );

}

void z80_call( Environment * _environment, char * _label ) {

    outline1("call %s", _label );

}

void z80_return( Environment * _environment ) {

    outline0("RET" );

}

void z80_pop( Environment * _environment ) {

    outline0("POP IX" );

}

void z80_halt( Environment * _environment ) {

    MAKE_LABEL

    outhead1("%s:", label );
    outline1("jp %s", label );

}

void z80_random( Environment * _environment, char * _seed, char * _entropy ) {

    outline1("LD HL, (%s)", _seed);
    outline0("LD B, (HL)");
    outline0("INC HL");
    outline0("LD A, (HL)");
    outline0("XOR B");
    outline1("LD DE, (%s)", _entropy);
    // outline0("LD B, H");
    outline0("LD C, L");
    outline0("ADD HL, HL");
    outline0("RL E");
    outline0("RL D");
    outline0("ADD HL, DE");
    outline0("RL E");
    outline0("RL D");
    outline0("INC L");
    outline0("ADD HL, BC");
    outline1("LD (%s), HL", _seed);
    outline1("LD HL, (%s+2)", _seed);
    outline0("ADD HL, DE");
    outline1("LD (%s+1), HL", _seed);
    outline0("EX DE, HL");
    outline1("LD HL, (%s)", _seed);
    outline1("LD DE, (%s)", _entropy);
    outline0("ADD HL, HL");
    outline0("RL C");
    outline0("RL B");
    outline1("LD (%s+1), BC", _seed);
    outline0("SBC A, A");
    outline0("AND %11000101");
    outline0("XOR L");
    outline0("LD L, A");
    outline1("LD (%s+1), HL", _seed);
    outline0("EX DE, HL");
    outline0("ADD HL, BC");

}

void z80_random_8bit( Environment * _environment, char * _seed, char * _entropy, char * _result ) {

    z80_random( _environment, _seed, _entropy );

    outline1("LD (%s), H", _result );

}

void z80_random_16bit( Environment * _environment, char * _seed, char * _entropy, char * _result ) {

    z80_random( _environment, _seed, _entropy );

    outline1("LD (%s), HL", _result );

}

void z80_random_32bit( Environment * _environment, char * _seed, char * _entropy, char * _result ) {

    z80_random( _environment, _seed, _entropy );

    outline1("LD (%s), HL", _result );
    outline1("LD (%s+2), BC", _result );

}

void z80_limit_16bit( Environment * _environment, char * _variable, int _value ) {

    MAKE_LABEL

    outline1( "LD A, (%s)", _variable );
    outline1( "CP $%2.2x", _value );
    outline1( "JR C, %s", label );
    outline1( "SUB $%2.2x", _value );
    outline1( "LD (%s), A", _variable );
    outhead1( "%s:", label );

}

void z80_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline1("LD A, %s", _timing );
    outhead1("%s:", label );
    outline0("DEC A");
    outline1("JR NZ, %s", label);

}

/**
 * @brief <i>Z80</i>: emit code to send one byte throught a I/O port
 * 
 * @param _environment Current calling environment
 * @param _port Port to connect
 * @param _value Value to send
 */
void z80_port_out( Environment * _environment, char * _port, char * _value ) {

    outline1("LD A, (%s)", _value );
    outline1("OUT (%s), A", _port );

}

void z80_logical_and_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _left );
    outline1("JR Z, %s", label );
    outline1("LD A, (%s)", _right );
    outline1("JR Z, %s", label );
    outline0("LD A, 1" );
    outline1("LD (%s), A", _result );
    outline1("JMP %s2", label );
    outhead1("%s:", label );
    outline0("LD A, 0" );
    outline1("LD (%s), A", _result );
    outhead1("%s2:", label );


}

void z80_logical_or_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _left );
    outline1("JR NZ, %s1", label );
    outline1("LD A, (%s)", _right );
    outline1("JR NZ, %s1", label );
    outhead1("%s0:", label );
    outline0("LD A, 0" );
    outline1("LD (%s), A", _result );
    outline1("JMP %sx", label );
    outhead1("%s1:", label );
    outline0("LD A, 1" );
    outline1("LD (%s), A", _result );
    outhead1("%sx:", label );

}

void z80_logical_not_8bit( Environment * _environment, char * _value, char * _result ) {

    outline1("LD A, (%s)", _value );
    outline0("XOR $FF" );
    outline1("LD (%s), A", _result );

}

void z80_di( Environment * _environment ) {

    outline0("DI" );

}

void z80_ei( Environment * _environment ) {

    outline0("EI" );

}

void z80_inc( Environment * _environment, char * _variable ) {

    outline1("LD A, (%s)", _variable  );
    outline0("INC A" );
    outline1("LD (%s), A", _variable  );

}

void z80_dec( Environment * _environment, char * _variable ) {

    outline1("LD A, (%s)", _variable  );
    outline0("DEC A" );
    outline1("LD (%s), A", _variable  );

}

void z80_inc_16bit( Environment * _environment, char * _variable ) {

    outline1("LD HL, (%s)", _variable  );
    outline0("INC HL" );
    outline1("LD (%s), HL", _variable  );

}

void z80_mem_move( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    outline1("LD HL,(%s)", _source);
    outline1("LD DE,(%s)", _destination);
    outline1("LD A, (%s)", _size);
    outline0("LD C, A");
    outline0("LD B, 0");
    outline0("LDIR");

}

void z80_mem_move_displacement(  Environment * _environment, char *_source, char *_destination, char * _displacement, char *_size ) {

    outline1("LD HL,(%s)", _source);
    outline1("LD DE,(%s)", _destination);
    outline1("ADD DE,(%s)", _size);
    outline1("LD C,%s", _size);
    outline0("LD B, 0");
    outline0("LDIR");

}

void z80_compare_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD HL,(%s)", _source);
    outline1("LD DE,(%s)", _destination);
    outline1("LD A, (%s)", _size);
    outline0("LD C, A");
    outhead1("%s:", label );
    outline0("LD A, (HL)");
    outline0("LD B, A");
    outline0("LD A, (DE)");
    outline0("CP B");
    outline1("JR NZ, %sdiff", label);
    outline0("INC DE");
    outline0("INC HL");
    outline0("DEC C");
    outline1("JR NZ, %s", label);
    outline1("LD A, %d", _equal ? 1 : 0 );
    outline1("LD (%s), A", _result );
    outline1("JMP %sfinal", label );
    outhead1("%sdiff:", label );
    outline1("LD A, %d", _equal ? 1 : 0 );
    outline1("LD (%s), A", _result );
    outhead1("%sfinal:", label );

}

void z80_less_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD HL,(%s)", _source);
    outline1("LD DE,(%s)", _destination);
    outline1("LD A, (%s)", _size);
    outline0("LD C, A");
    outhead1("%s:", label );
    outline0("LD A, (HL)");
    outline1("JR NC, %sdiff", label);
    if ( ! _equal ) {
        outline1("JR Z, %sdiff", label);
    }
    outline0("INC DE");
    outline0("INC HL");
    outline0("DEC C");
    outline1("JR NZ, %s", label);
    outline0("LD A, 1" );
    outline1("LD (%s), A", _result );
    outline1("JMP %sfinal", label );
    outhead1("%sdiff:", label );
    outline0("LD A, 0" );
    outline1("LD (%s), A", _result );
    outhead1("%sfinal:", label );

}

void z80_greater_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD HL,(%s)", _source);
    outline1("LD DE,(%s)", _destination);
    outline1("LD A, (%s)", _size);
    outline0("LD C, A");
    outhead1("%s:", label );
    outline0("LD A, (HL)");
    outline0("CP (DE)");
    outline1("JR C, %sdiff", label);
    if ( ! _equal ) {
        outline1("JR Z, %sdiff", label);
    }
    outline0("INC DE");
    outline0("INC HL");
    outline0("DEC C");
    outline1("JR NZ, %s", label);
    outline1("LD A, %d", _equal ? 1 : 0 );
    outline1("LD (%s), A", _result );
    outline1("JMP %sfinal", label );
    outhead1("%sdiff:", label );
    outline1("LD A, %d", _equal ? 1 : 0 );
    outline1("LD (%s), A", _result );
    outhead1("%sfinal:", label );

}

void z80_store_8bit_indirect( Environment * _environment, char *_source, int _value ) {

    outline1("LD HL,(%s)", _source);
    outline1("LD A, $%2.2x", (_value & 0xff));
    outline0("LD (HL), A" );

}

void z80_math_add_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    outline1("LD HL, (%s)", _source );
    outline0("LD DE, 0" );
    outline1("LD A, (%s)", _destination );
    outline0("LD E, A" );
    outline0("ADD HL, DE" );
    if ( _other ) {
        outline1("LD (%s), HL", _other );
    } else {
        outline1("LD (%s), HL", _destination );
    }

}

void z80_math_sub_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    outline1("LD HL, (%s)", _source );
    outline0("LD DE, 0" );
    outline1("LD A, (%s)", _destination );
    outline0("LD E, A" );
    outline0("SUB HL, DE" );
    if ( _other ) {
        outline1("LD (%s), HL", _other );
    } else {
        outline1("LD (%s), HL", _destination );
    }

}

void z80_uppercase( Environment * _environment, char *_source, char *_size, char *_result ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _size);
    outline0("LD C, A" );
    outline1("LD HL, (%s)", _source );
    if ( _result ) {
        outline1("LD DE, (%s)", _result );
    } else {
        outline1("LD DE, (%s)", _source );
    }
    outhead1("%supper:", label );
    outline0("LD A, (HL)" );
    
    outline0("CP 65");
    outline1("JR NC, %snext", label);
    outline1("JR NZ, %snext", label);

    outline0("CP 90");
    outline1("JR C, %snext", label);

    outline0("SUB A, 32");
    outline0("LD (DE), A" );

    outhead1("%snext:", label );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("DEC C" );
    outline0("CP 0" );
    outline1("JR Z, %supper", label);

}

void z80_lowercase( Environment * _environment, char *_source, char *_size, char *_result ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _size);
    outline0("LD C, A" );
    outline1("LD HL, (%s)", _source );
    if ( _result ) {
        outline1("LD DE, (%s)", _result );
    } else {
        outline1("LD DE, (%s)", _source );
    }
    outhead1("%slower:", label );
    outline0("LD A, (HL)" );
    
    outline0("CP 97");
    outline1("JR NC, %snext", label);
    outline1("JR NZ, %snext", label);

    outline0("CP 122");
    outline1("JR C, %snext", label);

    outline0("SUB A, 32");
    outline0("LD (DE), A" );

    outhead1("%snext:", label );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("DEC C" );
    outline0("CP 0" );
    outline1("JR Z, %slower", label);

}

void z80_convert_upto_24bit_bcd( Environment * _environment, char * _source, char * _dest, int _bits ) {

    MAKE_LABEL

    outline1("LD HL, (%s)", _source );
    outline1("LD A, (%s+2)", _source );
    outline0("LD E, A" );

    outline0("LD C,E");
    outline0("PUSH HL");
    outline0("POP IX");
    outline0("LD HL,1");
    outline0("LD D,H");
    outline0("LD E,H");
    outline1("LD B,%d", _bits );

    outhead1("%sFIND1:", label );

    outline0("ADD IX,IX");
    outline0("RL C");
    outline1("JR C,%sNEXTBIT", label );
    outline1("DJNZ %sFIND1", label );

    outline0("RES 0,L");
    outline1("JMP %send", label );

    outhead1("%sDBLLOOP:", label );
    
    outline0("LD A,L");
    outline0("ADD A,A");
    outline0("DAA");
    outline0("LD L,A");
    outline0("LD A,H");
    outline0("ADC A,A");
    outline0("DAA");
    outline0("LD H,A");
    outline0("LD A,E");
    outline0("ADC A,A");
    outline0("DAA");
    outline0("LD E,A");
    outline0("LD A,D");
    outline0("ADC A,A");
    outline0("DAA");
    outline0("LD D,A");
    outline0("ADD IX,IX");
    outline0("RL C");
    outline1("JR NC,%sNEXTBIT", label );
    outline0("SET 0,L");
    outhead1("%sNEXTBIT:", label );
    
    outline1("DJNZ %sDBLLOOP", label );
    outline1("JMP %send", label );

    outhead1("%send:", label );
    outline1("LD DE, (%s+1)", _dest );
    outline1("LD HL, (%s)", _dest );

}

void z80_convert_bcd_to_digits( Environment * _environment, char * _source, char * _dest ) {

    MAKE_LABEL

    outline1("LD DE, (%s)", _dest );
    outline0("DEC DE" );

    outline0("LD IX, 0");
    outline1("LD A, (%s+2)", _source);
    outline0("SRA A");
    outline0("SRA A");
    outline0("SRA A");
    outline0("SRA A");
    outline0("AND $0F");
    outline1("JR Z,%sd0", label);
    outline0("INC IX");
    outline0("ADC A, 48");
    outline0("INC DE");
    outline0("LD (DE),A");
    outhead1("%sd0:", label);
    outline1("LD A,(%s+2)", _source);
    outline0("AND $0F");
    outline1("JR NZ,%sd1a", label);
    outline0("INC IX");
    outline0("DEC IX");
    outline1("JR Z, %sd1", label);
    outline0("INC IX");
    outhead1("%sd1a:", label);
    outline0("ADC A, 48");
    outline0("INC DE");
    outline0("LD (DE), A");

    outhead1("%sd1:", label);
    outline1("LD A, (%s+1)", _source);
    outline0("SRA A");
    outline0("SRA A");
    outline0("SRA A");
    outline0("SRA A");
    outline0("AND $0F");
    outline1("JR NZ,%sd2a", label);
    outline0("INC IX");
    outline0("DEC IX");
    outline1("JR Z,%sd2", label);
    outline0("INC IX");
    outhead1("%sd2a:", label);
    outline0("ADC A, 48");
    outline0("INC DE");
    outline0("LD (DE), A");

    outhead1("%sd2:", label);
    outline1("LD A, (%s+1)", _source);
    outline0("AND $0F");
    outline1("JR NZ,%sd3a", label);
    outline0("INC IX");
    outline0("DEC IX");
    outline1("JR Z,%sd3", label);
    outline0("INC IX");
    outhead1("%sd3a:", label);
    outline0("ADC A, 48");
    outline0("INC DE");
    outline0("LD (DE), A");

    outhead1("%sd3:", label);
    outline1("LD A, (%s)", _source);
    outline0("SRA A");
    outline0("SRA A");
    outline0("SRA A");
    outline0("SRA A");
    outline0("AND $0F");
    outline1("JR NZ,%sd4a", label);
    outline0("INC IX");
    outline0("DEC IX");
    outline1("JR Z,%sd4", label);
    outline0("INC IX");
    outhead1("%sd4a:", label);
    outline0("ADC A, 48");
    outline0("INC DE");
    outline0("LD (DE), A");

    outhead1("%sd4:", label);
    outline1("LD A,(%s)", _source);
    outline0("AND $0F");
    outline0("ADC A, 48");
    outline0("INC DE");
    outline0("LD (DE), A");

    outline0("INC DE" );
    outline0("LD A, IXL" );
    outline1("LD (%s-1), A", _dest );

}

void z80_convert_string_into_16bit( Environment * _environment, char * _string, char * _len, char * _value ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _len );
    outline0("LD IX, 0" );
    outline0("LD IXL, A" );

    outline0("LD A, 0" );
    outline1("LD (%s), A", _value );

    outline1("LD HL, (%s)", _string );

    outhead1("%srepeat:", label );

    outline0("LD A, (HL)" );
    outline0("CP $39" );
    outline1("JR NC, %send", label);
    outline0("CP $30" );
    outline1("JR C, %send", label);
    outline0("SBC A, $30" );

    outline0("PUSH AF" );
    outline1("LD A, (%s+1)", _value );
    outline0("LD B, A"  );
    outline1("LD A, (%s)", _value );
    outline0("LD C, A" );
    outline0("POP AF" );
    outline0("LD E, A" );
    outline0("LD D, 0" );
    outline0("PUSH HL" );
    outline0("LD HL, 0" );
    outline0("ADC HL, DE" );
    outline0("ADC HL, BC" );
    outline1("LD (%s), HL", _value );
    outline0("POP HL" );


    // MULT x 10

    outline0("INC HL" );
    outline0("DEC IX" );
    outline0("LD A, 0" );
    outline0("CP IXL" );
    outline1("JR Z,%send", label );

    outline0("PUSH HL" );

    outline1("LD DE, (%s)", _value );
    outline0("LD A, 10" );
    outline0("LD B, 8" );
    outline0("LD HL, 0" );
    outline0("ADD HL, HL" );
    outline0("RLCA" );
    outline0("JR NC,$+3" );
    outline0("ADD HL, DE" );
    outline0("DJNZ $-5" );
    outline1("LD (%s), HL", _value );

    outline0("POP HL" );

    outline1("JMP %srepeat", label );

    outhead1("%send:", label );
  
}

void z80_fill_indirect( Environment * _environment, char * _address, char * _size, char * _pattern ) {

    MAKE_LABEL

    // Use the current bitmap address as starting address for filling routine.
    outline1("LD DE, (%s)", _address);
    outline1("LD HL, (%s)", _pattern);

    // Fill the bitmap with the given pattern.
    outline1("LD A, (%s)", _size);
    outline0("LD C, A" );
    outhead1("%sx:", label);
    outline0("LD A, (HL)");
    outline0("LD (DE),A");
    outline0("DEC C");
    outline1("JR NZ,%sx", label);

}

void z80_flip( Environment * _environment, char * _source, char * _size, char * _destination ) {

    MAKE_LABEL

    outline1("LD HL, %s", _size);
    outline1("LD DE, (%s)", _destination);
    outline0("ADC HL, DE");
    outline0("LD DE, HL");

    outline1("LD HL, (%s)", _source);
    
    outline0("DEC DE");

    outhead1("%sx:", label);
    outline0("LD A, (HL)");
    outline0("LD (DE), A");
    outline0("DEC DE");
    outline0("INC HL");
    outline0("DEC C");
    outline1("JR NZ,%sx", label);

}

void z80_move_8bit_indirect( Environment * _environment, char *_source, char * _value ) {

    outline1("LD DE, (%s)", _value);
    outline1("LD A, %s", _source);
    outline0("LD (DE), A");

}

void z80_move_8bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    outline1("LD DE, (%s)", _value);
    outline0("LD A, (DE)");
    outline1("LD (%s), A", _source);

}

#endif