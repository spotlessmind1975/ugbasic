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
    outline1("JMP %sb2", label);
    outhead1("%s:", label);
    outline1("JMP %s", _label);
    outhead1("%sb2:", label);

}

/**
 * @brief <i>Z80</i>: emit code to make long conditional jump

 * @param _environment Current calling environment
 * @param _label Destination of the conditional jump.
 */
void z80_bneq( Environment * _environment, char * _label ) {

    MAKE_LABEL

    outline1("JP NZ, %s", label);
    outline1("JMP %sb2", label);
    outhead1("%s:", label);
    outline1("JMP %s", _label);
    outhead1("%sb2:", label);

}

void z80_bveq( Environment * _environment, char * _value, char * _label ) {

    outline1("LD A, (%s)", _value);
    outline0("CP 0");
    z80_beq( _environment, _label );

}

void z80_bvneq( Environment * _environment, char * _value, char * _label ) {

    outline1("LD A, (%s)", _value);
    outline0("CP 0");
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
void z80_fill_blocks( Environment * _environment, char * _address, char * _blocks, char * _pattern ) {

    outline1("LD A,(%s)", _pattern);
    outline1("LD HL,(%s)", _address);
    outline0("LD (HL),A")
    outline0("LD E,L");
    outline0("LD D,H");
    outline0("INC DE");
    outline0("LD (DE),A")
    outline0("LD C,255");
    outline1("LD A,(%s)", _blocks);
    outline0("LD B,A");
    outline0("LDIR");

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
 * @param _bytes Number of bytes to fill
 * @param _pattern Pattern to use
 */
void z80_fill( Environment * _environment, char * _address, char * _bytes, char * _pattern ) {

    outline1("LD A,(%s)", _pattern);
    outline1("LD HL,(%s)", _address);
    outline0("LD (HL),A")
    outline0("LD E,L");
    outline0("LD D,H");
    outline0("INC DE");
    outline0("LD (DE),A")
    outline1("LD A,(%s)", _bytes);
    outline0("LD C,A");
    outline0("LD A,0");
    outline0("LD B,A");
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

void z80_store_8bit_with_offset( Environment * _environment, char *_destination, int _value, int _offset ) {

    outline1("LD A, $%2.2x", _offset);
    outline1("LD DE, %s", _destination);
    outline0("ADD DE,A");
    outline1("LD A, $%2.2x", _value);
    outline0("LD (DE), A");

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
    outline1("LD A, $%2.2x", 0xff*_positive);
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outline1("JMP %sb2", label);
    outhead1("%s:", label);
    outline1("LD A, $%2.2x", 0xff*(1-_positive));
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outhead1("%sb2:", label);

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
void z80_less_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        outline1("LD A, (%s)", _destination);
        outline0("LD B, A");
        outline1("LD A, (%s)", _source);
        outline0("SUB A, B");
        if ( _equal ) {
            outline1("JP  Z,%strue", label);
        }
        outline1("JP PO,%snoxor", label);
        outline0("XOR $80");
        outhead1("%snoxor:", label);
        outline1("JP M,%strue", label);
        outline1("JP PE,%sfalse", label);
        outhead1("%sfalse:", label);
        outline0("LD A, 0");
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline1("LD (%s), A", _destination);
        }
        outline1("JMP %sb2", label);
        outhead1("%strue:", label);
        outline0("LD A, $ff");
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline1("LD (%s), A", _destination);
        }
        outhead1("%sb2:", label);

    } else {

        outline1("LD A, (%s)", _destination);
        outline0("LD B, A");
        outline1("LD A, (%s)", _source);
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
        outline1("JMP %sb2", label);
        outhead1("%s:", label);
        outline0("LD A, $ff");
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline1("LD (%s), A", _destination);
        }
        outhead1("%sb2:", label);

    }

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
void z80_greater_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    z80_less_than_8bit( _environment, _source, _destination, _other, !_equal, _signed );
    if ( _other ) {
        z80_logical_not_8bit( _environment, _other, _other );
    } else {
        z80_logical_not_8bit( _environment, _destination, _destination );
    }

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
    outline1("LD A, (%s)", _destination );
    outline0("SUB A, B" );
    outline0("LD B, A" );
    outline1("LD A, (%s)", _source );
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
void z80_math_double_8bit( Environment * _environment, char *_source, char *_other, int _signed ) {

    if ( _signed ) {

        outline1("LD A, (%s)", _source );
        outline0("ADD A, A" );
        if ( _other ) {
            outline1("LD (%s), A", _other );
        } else {
            outline1("LD (%s), A", _source );
        }

    } else {
        outline1("LD A, (%s)", _source );
        outline0("ADD A, A" );
        if ( _other ) {
            outline1("LD (%s), A", _other );
        } else {
            outline1("LD (%s), A", _source );
        }
    }
}

/**
 * @brief <i>Z80</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void z80_math_div2_8bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {
        outline1("LD A, (%s)", _source );
        outline0("AND $80" );
        outline0("PUSH AF" );
        outline1("JR Z,%spos", label );
        outline1("LD A, (%s)", _source );
        outline0("XOR $FF" );
        outline0("ADC $1" );
        outline1("JMP %spos2", label );
        outhead1("%spos:", label );
        outline1("LD A, (%s)", _source );
        outhead1("%spos2:", label );
        while( _steps ) {
            outline0("SRA A" );
            --_steps;
        }
        outline1("LD (%s), A", _source );
        outline0("POP AF" );
        outline0("AND $80" );
        outline1("JR Z,%spos3", label );
        outline1("LD A, (%s)", _source );
        outline0("XOR $FF" );
        outline0("ADC $1" );
        outline1("LD (%s), A", _source );
        outhead1("%spos3:", label );
    } else {
        outline1("LD A, (%s)", _source );
        while( _steps ) {
            outline0("SRA A" );
            --_steps;
        }
        outline1("LD (%s), A", _source );
    }

}

/**
 * @brief <i>Z80</i>: emit code to multiply two 8bit values in a 16 bit register
 * 
 * @param _environment Current calling environment
 * @param _source First value to multipy (8 bit)
 * @param _destination Second value to multipy (8 bit)
 * @param _other Destination address for result (16 bit)
 */

void z80_math_mul_8bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        outline1("LD A, (%s)", _source );
        outline0("AND $80" );
        outline0("LD B, A" );
        outline1("LD A, (%s)", _destination );
        outline0("AND $80" );
        outline0("XOR A, B" );
        outline0("PUSH AF" );

        outline1("LD A, (%s)", _source );
        outline0("AND $80" );
        outline1("JR Z, %spositive", label );
        outline1("LD A, (%s)", _source );
        outline0("XOR $FF" );
        outline0("INC A" );
        outline0("LD H, A" );
        outhead1("%spositive:", label );

        outline1("LD A, (%s)", _destination );
        outline0("AND $80" );
        outline1("JR Z, %spositive2", label );
        outline1("LD A, (%s)", _destination );
        outline0("XOR $FF" );
        outline0("INC A" );
        outline0("LD C, A" );
        outhead1("%spositive2:", label );

        outline0("LD E, A" );

        outline0("LD D,0");
        outline0("LD L,D");
        outline0("LD B,8");

        outhead1("%s:", label );
        outline0("ADD HL, HL" );
        outline1("JR NC,%sb2", label );
        outline0("ADD HL, DE" );

        outhead1("%sb2:", label );

        outline1("DJNZ %s", label );

        outline1("LD (%s), HL", _other );
        outline0("POP AF" );
        outline0("CMP $80" );
        outline1("JR Z,%snc", label );
        z80_complement2_16bit( _environment, _other, NULL );
        outhead1("%snc:", label );

    } else {

        outline1("LD A, (%s)", _source );
        outline0("LD H, A" );
        outline1("LD A, (%s)", _destination );
        outline0("LD E, A" );

        outline0("LD D,0");
        outline0("LD L,D");
        outline0("LD B,8");

        outhead1("%s:", label );
        outline0("ADD HL, HL" );
        outline1("JR NC,%sb2", label );
        outline0("ADD HL, DE" );

        outhead1("%sb2:", label );

        outline1("DJNZ %s", label );
        outline1("LD (%s), HL", _other );

    }

}

/**
 * @brief <i>Z80</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void z80_math_div2_const_8bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {
        outline1("LD A, (%s+1)", _source );
        outline0("AND $80" );
        outline0("PUSH AF" );
        outline1("JR Z, %spos", label );
        z80_complement2_16bit( _environment, _source, _source );
        outline1("JMP %spos2", label );
        outhead1("%spos:", label );
        outhead1("%spos2:", label );
        outline1("LD A, (%s)", _source );
        while( _steps ) {
            outline0("SRA A" );
            --_steps;
        }
        outline1("LD (%s), A", _source );
        outline0("POP AF" );
        outline0("AND $80" );
        outline1("JR Z, %sdone", label );
        z80_complement2_16bit( _environment, _source, _source );
        outhead1("%sdone:", label );
    } else {
        outline1("LD A, (%s)", _source );
        while( _steps ) {
            outline0("SRA A" );
            --_steps;
        }
        outline1("LD (%s), A", _source );
    }

}

/**
 * @brief <i>Z80</i>: emit code to double for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 */
void z80_math_mul2_const_8bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    if ( _signed ) {
        outline1("LD A, (%s)", _source );
        outline0("AND $80" );
        outline0("PUSH AF" );
        outline1("LD A, (%s)", _source );
        outline0("AND $7F" );
        while( _steps ) {
            outline0("SLA A" );
            --_steps;
        }
        outline0("LD B, A" );
        outline0("POP AF" );
        outline0("OR A, B" );
        outline1("LD (%s), A", _source );

    } else {
        outline0("; variable_mul2_const");
        outline1("LD A, (%s)", _source );
        while( _steps ) {
            outline0("SLA A" );
            --_steps;
        }
        outline1("LD (%s), A", _source );
    }

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

void z80_addressof_16bit( Environment * _environment, char *_source, char *_destination ) {
    
    outline1("LD HL, %s", _source );
    outline1("LD (%s), HL", _destination );

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
    outline1("LD A, $%2.2x", 0xff*_positive);
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outline1("JMP %sb2", label);
    outhead1("%s:", label);
    outline1("LD A, $%2.2x", 0xff*(1-_positive));
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outhead1("%sb2:", label);

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
void z80_less_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        outline1("LD HL, (%s)", _destination);
        outline1("LD DE, (%s)", _source);
        outline0("LD A, H" );
        outline0("XOR D" );
        outline1("JP M,%scmpgte2", label );
        outline0("SBC HL, DE" );
        outline1("JR NC,%scmpgte3", label );
        outhead1("%scmpgte1:", label ); 
        outline0("LD A, 0");
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline1("LD (%s), A", _destination);
        }
        outline1("JMP %send", label );
        outhead1("%scmpgte2:", label ); 
        outline0("BIT 7,D" );
        outline1("JR Z, %scmpgte1", label );
        outhead1("%scmpgte3:", label ); 
        outline0("LD A, $ff");
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline1("LD (%s), A", _destination);
        }
        outhead1("%send:", label ); 
        
    } else {

        outline1("LD A, (%s+1)", _destination);
        outline0("LD B, A");
        outline1("LD A, (%s+1)", _source);
        outline0("CP B");
        outline1("JR Z, %sl2", label);
        outline1("JR C, %s", label);
        outline1("JR %s_0", label);
        outhead1("%sl2:", label);
        outline1("LD A, (%s)", _destination);
        outline0("LD B, A");
        outline1("LD A, (%s)", _source);
        outline0("CP B");
        outline1("JR C, %s", label);
        if ( _equal ) {
            outline1("JR Z, %s", label);
        }
        outhead1("%s_0:", label);
        outline0("LD A, 0");
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline1("LD (%s), A", _destination);
        }
        outline1("JMP %sb2", label);
        outhead1("%s:", label);
        outline0("LD A, $ff");
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline1("LD (%s), A", _destination);
        }
        outhead1("%sb2:", label);


    }

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
void z80_greater_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    z80_less_than_16bit( _environment, _source, _destination, _other, !_equal, _signed );
    if ( _other ) {
        z80_logical_not_8bit( _environment, _other, _other );
    } else {
        z80_logical_not_8bit( _environment, _destination, _destination );
    }

}

/**
 * @brief <i>Z80</i>: emit code to add two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add (memory)
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void z80_math_add_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    outline0("; z80_math_add_16bit");
    outline1("LD HL, (%s)", _source );
    outline1("LD DE, (%s)", _destination );
    outline0("ADD HL, DE" );
    if ( _other ) {
        outline1("LD (%s), HL", _other );
    } else {
        outline1("LD (%s), HL", _destination );
    }

}

void z80_math_add_16bit_with_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    outline0("; z80_math_add_16bit");
    outline1("LD HL, (%s)", _source );
    outline1("LD DE, %s", _destination );
    outline0("ADD HL, DE" );
    outline1("LD (%s), HL", _other );

}

/**
 * @brief <i>Z80</i>: emit code to double a 16 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void z80_math_double_16bit( Environment * _environment, char *_source, char *_other, int _signed ) {
    
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
void z80_math_mul_16bit_to_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        outline1("LD A, (%s+1)", _source);
        outline0("AND $80");
        outline0("LD B, A");
        outline1("LD A, (%s+1)", _destination);
        outline0("AND $80");
        outline0("XOR A, B");
        outline0("PUSH AF");

        outline1("LD A, (%s+1)", _source);
        outline0("AND $80");
        outline0("PUSH AF");
        outline1("JR Z,%spositive", label);
        z80_complement2_16bit( _environment, _source, NULL );
        outhead1("%spositive:", label);

        outline1("LD A, (%s+1)", _destination);
        outline0("AND $80");
        outline0("PUSH AF");
        outline1("JR Z,%spositive2", label);
        z80_complement2_16bit( _environment, _destination, NULL );
        outhead1("%spositive2:", label);

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
        outline1("JR NC,%sb2", label );
        outline0("ADD HL, DE" );
        outline0("ADC A, 0" );
        outline1("JP NC,%sb2", label );
        outline0("INC C" );
        outhead1("%sb2:", label );
        outline1("DJNZ %s", label );
        outline0("LD B, C" );
        outline0("LD C, A" );
        outline1("LD (%s), HL", _other );
        outline1("LD (%s+2), BC", _other );

        outline0("POP AF" );
        outline1("JR Z, %srepositive", label );
        z80_complement2_16bit( _environment, _destination, NULL );
        outhead1("%srepositive:", label);

        outline0("POP AF" );
        outline1("JR Z, %srepositive2", label );
        z80_complement2_16bit( _environment, _source, NULL );
        outhead1("%srepositive2:", label);

        outline0("POP AF" );
        outline1("JR Z, %srepositive3", label );
        z80_complement2_16bit( _environment, _other, NULL );
        outhead1("%srepositive3:", label);

    } else {

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
        outline1("JR NC,%sb2", label );
        outline0("ADD HL, DE" );
        outline0("ADC A, 0" );
        outline1("JP NC,%sb2", label );
        outline0("INC C" );
        outhead1("%sb2:", label );
        outline1("DJNZ %s", label );
        outline0("LD B, C" );
        outline0("LD C, A" );
        outline1("LD (%s), HL", _other );
        outline1("LD (%s+2), BC", _other );

    }

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
void z80_math_div2_const_16bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {
        outline1("LD A, (%s+1)", _source );
        outline0("AND $80" );
        outline0("PUSH AF" );
        outline1("JR Z, %spos", label );
        z80_complement2_16bit( _environment, _source, _source );
        outline1("JMP %spos2", label );
        outhead1("%spos:", label );
        outhead1("%spos2:", label );
        outline1("LD HL, (%s)", _source );
        while( _steps ) {
            outline0("SRA H" );
            outline0("RR L" );
            --_steps;
        }
        outline1("LD (%s), HL", _source );
        outline0("POP AF" );
        outline0("AND $80" );
        outline1("JR Z, %sdone", label );
        z80_complement2_16bit( _environment, _source, _source );
        outhead1("%sdone:", label );
    } else {
        outline1("LD HL, (%s)", _source );
        while( _steps ) {
            outline0("SRA H" );
            outline0("RR L" );
            --_steps;
        }
        outline1("LD (%s), HL", _source );
        
    }

}

/**
 * @brief <i>Z80</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void z80_math_mul2_const_16bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {
        outline1("LD A, (%s+1)", _source );
        outline0("AND $80" );
        outline0("PUSH AF" );
        outline1("JR Z, %spos", label );
        z80_complement2_16bit( _environment, _source, _source );
        outline1("JMP %spos2", label );
        outhead1("%spos:", label );
        outhead1("%spos2:", label );
        outline1("LD HL, (%s)", _source );
        while( _steps ) {
            outline0("SLA L" );
            outline0("RL H" );
            --_steps;
        }
        outline1("LD (%s), HL", _source );
        outline0("POP AF" );
        outline0("AND $80" );
        outline1("JR Z, %sdone", label );
        z80_complement2_16bit( _environment, _source, _source );
        outhead1("%sdone:", label );
    } else {
        outline1("LD HL, (%s)", _source );
        while( _steps ) {
            outline0("SLA L" );
            outline0("RL H" );
            --_steps;
        }
        outline1("LD (%s), HL", _source );
    }

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
    outline1("LD A, $%2.2x", 0xff*_positive);
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outline1("JMP %s_2", label);
    outhead1("%s:", label);
    outline1("LD A, $%2.2x", 0xff*(1-_positive));
    if ( _other ) {
        outline1("LD (%s), A", _other);
    } else {
        outline1("LD (%s), A", _destination);
    }
    outhead1("%s_2:", label);

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
void z80_less_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        outline1("LD IX, %s", _source);
        outline1("LD IY, %s", _destination);
        outline0("LD B, (IX+3)");
        outline0("LD A, B");
        outline0("AND $80");
        outline1("JR NZ,%sNEGM1", label);
        outline0("BIT 7,(IY+3)");
        outline1("JR NZ,%sdone", label);
        outline0("LD A, B");
        outline0("CP (IY+3)");
        outline1("JR NZ,%sdone", label);
        outline0("LD A, (IX+2)");
        outline0("CP (IY+2)");
        outline1("JR NZ,%sdone", label);
        outline0("LD A, (IX+1)");
        outline0("CP (IY+1)");
        outline1("JR NZ,%sdone", label);
        outline0("LD A, (IX)");
        outline0("CP (IY)");
        outline1("JMP %sdone", label);
        outhead1("%sNEGM1:", label);
        outline0("XOR (IY+3)");
        outline0("RLA");
        outline1("JR C,%sdone", label);
        outline0("LD A, B");
        outline0("CP (IY+3)");
        outline1("JR NZ,%sdone", label);
        outline0("LD A, (IX+2)");
        outline0("CP (IY+2)");
        outline1("JR NZ,%sdone", label);
        outline0("LD A, (IX+1)");
        outline0("CP (IY+1)");
        outline1("JR NZ,%sdone", label);
        outline0("LD A, (IX)");
        outline0("CP (IY)");
        outline1("JMP %sdone", label);
        outhead1("%sdone:", label);
        if ( _equal ) {
            outline1("JR Z,%smi", label);
        }
        outline1("JR C,%smi", label);
        outhead1("%spl:", label);
        outline0("LD A, 0");
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline1("LD (%s), A", _destination);
        }
        outline1("JMP %sdone2", label);
        outhead1("%smi:", label);
        outline0("LD A, $ff");
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline1("LD (%s), A", _destination);
        }
        outline1("JMP %sdone2", label);
        outhead1("%sdone2:", label);

    } else {

        outline1("LD A, (%s+3)", _source);
        outline0("LD B, A");
        outline1("LD A, (%s+3)", _destination);
        outline0("CP B");
        outline1("JR Z, %s_2", label);
        outline1("JR C, %s", label);
        outline1("JR %s_ok", label);
        outhead1("%s_2:", label);
        outline1("LD A, (%s+2)", _source);
        outline0("LD B, A");
        outline1("LD A, (%s+2)", _destination);
        outline0("CP B");
        outline1("JR Z, %s_1", label);
        outline1("JR C, %s", label);
        outline1("JR %s_ok", label);
        outhead1("%s_1:", label);
        outline1("LD A, (%s+1)", _source);
        outline0("LD B, A");
        outline1("LD A, (%s+1)", _destination);
        outline0("CP B");
        outline1("JR Z, %s_0", label);
        outline1("JR C, %s", label);
        outline1("JR %s_ok", label);
        outhead1("%s_0:", label);
        outline1("LD A, (%s)", _source);
        outline0("LD B, A");
        outline1("LD A, (%s)", _destination);
        outline0("CP B");
        outline1("JR C, %s", label);
        if ( _equal ) {
            outline1("JR Z, %s", label);
        }
        outhead1("%s_ok:", label);
        outline0("LD A, $ff");
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline1("LD (%s), A", _destination);
        }
        outline1("JMP %s_xx", label);
        outhead1("%s:", label);
        outline0("LD A, $0");
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline1("LD (%s), A", _destination);
        }
        outhead1("%s_xx:", label);


    }

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
void z80_greater_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    z80_less_than_32bit( _environment, _source, _destination, _other, !_equal, _signed );
    if ( _other ) {
        z80_logical_not_8bit( _environment, _other, _other );
    } else {
        z80_logical_not_8bit( _environment, _destination, _destination );
    }

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
    outline0("EXX" );
    outline0("ADD HL, DE" );
    outline0("EXX" );
    outline0("ADC HL, DE" );
    outline0("EXX" );
    if ( _other ) {
        outline1("LD (%s), HL", _other );
        outline0("EXX" );
        outline1("LD (%s+2), HL", _other );
    } else {
        outline1("LD (%s), HL", _destination );
        outline0("EXX" );
        outline1("LD (%s+2), HL", _destination );
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
void z80_math_double_32bit( Environment * _environment, char *_source, char *_other, int _signed ) {

    if ( _other ) {
        z80_math_add_32bit( _environment, _source, _source, _other );
    } else {
        z80_math_add_32bit( _environment, _source, _source, _source );
    }

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
void z80_math_div2_const_32bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {
        outline1("LD A, (%s+3)", _source );
        outline0("AND $80" );
        outline0("PUSH AF" );
        outline1("JR Z, %spos", label );
        z80_complement2_32bit( _environment, _source, _source );
        outline1("JMP %spos2", label );
        outhead1("%spos:", label );
        outhead1("%spos2:", label );
        outline1("LD DE,(%s)", _source );
        outline1("LD BC,(%s+2)", _source );
        while( _steps ) {
            outline0("SRA B" );
            outline0("RR C" );
            outline0("RR D" );
            outline0("RR E" );
            --_steps;
        }
        outline1("LD (%s),DE", _source );
        outline1("LD (%s+2),BC", _source );
        outline0("POP AF" );
        outline0("AND $80" );
        outline1("JR Z, %sdone", label );
        z80_complement2_32bit( _environment, _source, _source );
        outhead1("%sdone:", label );
    } else {
        outline1("LD DE,(%s)", _source );
        outline1("LD BC,(%s+2)", _source );
        while( _steps ) {
            outline0("SRA B" );
            outline0("RR C" );
            outline0("RR D" );
            outline0("RR E" );
            --_steps;
        }
        outline1("LD (%s),DE", _source );
        outline1("LD (%s+2),BC", _source );    }

}

/**
 * @brief <i>Z80</i>: emit code to double for several times a 32 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 * @todo Not yet implemented
 */
void z80_math_mul2_const_32bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {
        outline1("LD A, (%s+3)", _source );
        outline0("AND $80" );
        outline0("PUSH AF" );
        outline1("JR Z, %spos", label );
        z80_complement2_32bit( _environment, _source, _source );
        outline1("JMP %spos2", label );
        outhead1("%spos:", label );
        outhead1("%spos2:", label );
        outline1("LD HL, (%s)", _source );
        outline1("LD DE, (%s+2)", _source );
        while( _steps ) {
            outline0("SLA L" );
            outline0("RL H" );
            outline0("RL E" );
            outline0("RL D" );
            --_steps;
        }
        outline1("LD (%s), HL", _source );
        outline1("LD (%s+2), DE", _source );
        outline0("POP AF" );
        outline0("AND $80" );
        outline1("JR Z, %sdone", label );
        z80_complement2_32bit( _environment, _source, _source );
        outhead1("%sdone:", label );
    } else {
        outline1("LD HL, (%s)", _source );
        outline1("LD DE, (%s+2)", _source );
        while( _steps ) {
            outline0("SLA L" );
            outline0("RL H" );
            outline0("RL D" );
            outline0("RL E" );
            --_steps;
        }
        outline1("LD (%s), HL", _source );
        outline1("LD (%s+2), DE", _source );
    }

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

void z80_end( Environment * _environment ) {

    outline0("DI");
    outline0("HLT");

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

    outline0("LD A, H" );
    outline1("LD (%s), A", _result );

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
    outline0("CMP 0" );
    outline1("JR Z, %s", label );
    outline1("LD A, (%s)", _right );
    outline0("CMP 0" );
    outline1("JR Z, %s", label );
    outline0("LD A, $ff" );
    outline1("LD (%s), A", _result );
    outline1("JMP %s_2", label );
    outhead1("%s:", label );
    outline0("LD A, 0" );
    outline1("LD (%s), A", _result );
    outhead1("%s_2:", label );


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
    outline0("LD A, $ff" );
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

void z80_inc_32bit( Environment * _environment, char * _variable ) {

    MAKE_LABEL

    outline1("LD HL, (%s)", _variable  );
    outline0("INC HL" );
    outline1("LD (%s), HL", _variable  );
    outline0("LD A, L"  );
    outline0("CMP 0"  );
    outline1("JR NZ, %s", label  );
    outline0("LD A, h"  );
    outline0("CMP 0"  );
    outline1("JR NZ, %s", label  );
    outline1("LD HL, (%s+2)", _variable  );
    outline0("INC HL" );
    outline1("LD (%s+2), HL", _variable  );
    outhead1("%s:", label  );

}

void z80_dec_16bit( Environment * _environment, char * _variable ) {

    outline1("LD HL, (%s)", _variable  );
    outline0("DEC HL" );
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

void z80_mem_move_direct( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    outline1("LD HL,%s", _source);
    outline1("LD DE,%s", _destination);
    outline1("LD A, (%s)", _size);
    outline0("LD C, A");
    outline0("LD B, 0");
    outline0("LDIR");

}

void z80_mem_move_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    outline1("LD HL,(%s)", _source);
    outline1("LD DE,(%s)", _destination);
    outline1("LD A, $%2.2x", _size);
    outline0("LD C, A");
    outline0("LD B, 0");
    outline0("LDIR");

}

void z80_mem_move_direct_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    outline1("LD HL,%s", _source);
    outline1("LD DE,%s", _destination);
    outline1("LD A, $%2.2x", _size);
    outline0("LD C, A");
    outline0("LD B, 0");
    outline0("LDIR");

}

void z80_mem_move_direct_indirect_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    outline1("LD HL,%s", _source);
    outline1("LD DE,(%s)", _destination);
    outline1("LD A, $%2.2x", _size);
    outline0("LD C, A");
    outline0("LD B, 0");
    outline0("LDIR");

}

void z80_compare_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _size);
    outline0("CP 0");
    outline1("JR Z, %sequal", label);
    outline0("LD C, A");
    outline1("LD HL,(%s)", _source);
    outline1("LD DE,(%s)", _destination);
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
    outhead1("%sequal:", label );
    outline1("LD A, %d", _equal ? 255 : 0 );
    outline1("LD (%s), A", _result );
    outline1("JMP %sfinal", label );
    outhead1("%sdiff:", label );
    outline1("LD A, %d", _equal ? 0 : 255 );
    outline1("LD (%s), A", _result );
    outhead1("%sfinal:", label );

}

void z80_compare_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD HL,(%s)", _source);
    outline1("LD DE,(%s)", _destination);
    outline1("LD A, $%2.2x", _size);
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
    outline1("LD A, %d", _equal ? 255 : 0 );
    outline1("LD (%s), A", _result );
    outline1("JMP %sfinal", label );
    outhead1("%sdiff:", label );
    outline1("LD A, %d", _equal ? 0 : 255 );
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
    outline0("LD A, $ff" );
    outline1("LD (%s), A", _result );
    outline1("JMP %sfinal", label );
    outhead1("%sdiff:", label );
    outline0("LD A, 0" );
    outline1("LD (%s), A", _result );
    outhead1("%sfinal:", label );

}

void z80_less_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD HL,(%s)", _source);
    outline1("LD DE,(%s)", _destination);
    outline1("LD A, $%2.2x", _size);
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
    outline0("LD A, $ff" );
    outline1("LD (%s), A", _result );
    outline1("JMP %sfinal", label );
    outhead1("%sdiff:", label );
    outline0("LD A, 0" );
    outline1("LD (%s), A", _result );
    outhead1("%sfinal:", label );

}

void z80_greater_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD HL,(%s)", _destination);
    outline1("LD DE,(%s)", _source);
    outline1("LD A, (%s)", _size);
    outline0("LD C, A");
    outhead1("%s:", label );
    outline0("LD A, (HL)");
    outline0("LD B, A");
    outline0("LD A, (DE)");
    outline0("CP B");
    if ( !_equal ) {
        outline1("JR Z, %sdiff", label);
    }
    outline1("JR C, %sdiff", label);
    outline0("INC DE");
    outline0("INC HL");
    outline0("DEC C");
    outline1("JR NZ, %s", label);
    outline1("LD A, %d", _equal ? 255 : 0 );
    outline1("LD (%s), A", _result );
    outline1("JMP %sfinal", label );
    outhead1("%sdiff:", label );
    outline1("LD A, %d", _equal ? 0 : 255 );
    outline1("LD (%s), A", _result );
    outhead1("%sfinal:", label );

}

void z80_greater_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD HL,(%s)", _destination);
    outline1("LD DE,(%s)", _source);
    outline1("LD A, $%2.2x", _size);
    outline0("LD C, A");
    outhead1("%s:", label );
    outline0("LD A, (HL)");
    outline0("CP (DE)");
    if ( ! _equal ) {
        outline1("JR Z, %sdiff", label);
    }
    outline1("JR C, %sdiff", label);
    outline0("INC DE");
    outline0("INC HL");
    outline0("DEC C");
    outline1("JR NZ, %s", label);
    outline1("LD A, %d", _equal ? 255 : 0 );
    outline1("LD (%s), A", _result );
    outline1("JMP %sfinal", label );
    outhead1("%sdiff:", label );
    outline1("LD A, %d", _equal ? 0 : 255 );
    outline1("LD (%s), A", _result );
    outhead1("%sfinal:", label );

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

    outline0("CP 97");
    outline1("JR C, %snext", label);

    outline0("CP 122");
    outline1("JR NC, %snext", label);

    outline0("SUB A, 32");
    outline0("LD (DE), A" );

    outhead1("%snext:", label );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("DEC C" );
    outline0("LD A, C" );
    outline0("CP 0" );
    outline1("JR NZ, %supper", label);

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

    outline0("CP 65");
    outline1("JR C, %snext", label);

    outline0("CP 90");
    outline1("JR NC, %snext", label);

    outline0("ADC A, 32");
    outline0("LD (DE), A" );

    outhead1("%snext:", label );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("DEC C" );
    outline0("LD A, C" );
    outline0("CP 0" );
    outline1("JR NZ, %slower", label);

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

void z80_flip( Environment * _environment, char * _source, char * _size, char * _destination ) {

    MAKE_LABEL

    outline1("LD HL, (%s)", _size);
    outline0("LD H, 0");
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
    outline1("LD A, (%s)", _source);
    outline0("LD (DE), A");

}

void z80_move_8bit_indirect_with_offset( Environment * _environment, char *_source, char * _value, int _offset ) {

    outline1("LD HL, (%s)", _value);
    outline1("LD DE, $%2.2x", ( _offset & 0xff ) );
    outline0("ADD HL, DE" );
    outline1("LD A, (%s)", _source);
    outline0("LD (HL), A");

}

void z80_move_8bit_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

    outline1("LD HL, (%s)", _value);
    outline1("LD DE, (%s)", _offset );
    outline0("ADD HL, DE" );
    outline1("LD A, (%s)", _source);
    outline0("LD (HL), A");

}

void z80_move_8bit_with_offset( Environment * _environment, char *_source, char * _value, int _offset ) {

    outline1("LD HL, %s", _value);
    outline1("LD DE, $%2.2x", ( _offset & 0xff ) );
    outline0("ADD HL, DE" );
    outline1("LD A, (%s)", _source);
    outline0("LD (HL), A");

}

void z80_move_8bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    outline1("LD DE, (%s)", _value);
    outline0("LD A, (DE)");
    outline1("LD (%s), A", _source);

}

void z80_move_16bit_indirect( Environment * _environment, char *_source, char * _value ) {

    outline1("LD DE, (%s)", _value);
    outline1("LD HL, (%s)", _source);
    outline0("LD A, L");
    outline0("LD (DE), A");
    outline0("INC DE");
    outline0("LD A, H");
    outline0("LD (DE), A");

}

void z80_move_16bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    outline1("LD DE, (%s)", _value);
    outline0("LD A, (DE)");
    outline1("LD (%s), A", _source);
    outline0("INC DE");
    outline0("LD A, (DE)");
    outline1("LD (%s+1), A", _source);

}

void z80_move_32bit_indirect( Environment * _environment, char *_source, char * _value ) {

    outline1("LD DE, (%s)", _value);
    outline1("LD HL, (%s)", _source);
    outline0("LD (DE), HL");
    outline0("INC DE");
    outline0("INC DE");
    outline1("LD HL, (%s+2)", _source);
    outline0("LD (DE), HL");

}

void z80_move_32bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    outline1("LD DE, (%s)", _value);
    outline0("LD HL, (DE)");
    outline1("LD (%s), HL", _source);
    outline0("INC DE");
    outline0("INC DE");
    outline0("LD HL, (DE)");
    outline1("LD (%s+2), HL", _source);

}

void z80_math_div_32bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        outline1("LD A, (%s+3)", _source);
        outline0("AND $80");
        outline0("PUSH AF");
        outline1("JR Z,%spositive", label);
        z80_complement2_32bit( _environment, _source, NULL );
        outhead1("%spositive:", label);
        outline1("LD A, (%s+1)", _destination);
        outline0("AND $80");
        outline0("PUSH AF");
        outline1("JR Z,%spositive2", label);
        z80_complement2_16bit( _environment, _destination, NULL );
        outhead1("%spositive2:", label);

        outline1("LD HL, %s", _source);
        outline0("LD IX, (HL)");
        outline0("INC HL");
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline0("LD C, A");
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline1("LD DE, (%s)", _destination);

        outline0("LD HL, 0");
        outline0("LD B, 32");
        outhead1("%sloop:", label);
        outline0("ADD IX, IX");
        outline0("RL C");
        outline0("RLA");
        outline0("ADC HL, HL");
        outline1("JR C, %soverflow", label);
        outline0("SBC HL, DE");
        outline1("JR NC, %ssetbit", label);
        outline0("ADD HL, DE");
        outline1("DJNZ %sloop", label);
        outline1("JMP %send", label);
        outhead1("%soverflow:", label);
        outline0("OR A");
        outline0("SBC HL, DE");
        outhead1("%ssetbit:", label);
        outline0("INC IXL");
        outline1("DJNZ %sloop", label);
        outhead1("%send:", label);
        outline1("LD (%s), HL", _other_remainder);
        outline1("LD HL, %s", _other);
        outline0("LD (HL), IX");
        outline0("INC HL");
        outline0("INC HL");
        outline0("INC HL");
        outline0("LD (HL), A");
        outline0("DEC HL");
        outline0("LD C, (HL)");

        outline0("POP AF");
        outline0("CMP $80");
        outline1("JR NZ, %srepositive", label);
        z80_complement2_16bit( _environment, _destination, NULL );
        outhead1("%srepositive:", label);
        outline0("POP AF");
        outline0("CMP $80");
        outline1("JR NZ, %srepositive2", label );
        z80_complement2_32bit( _environment, _source, NULL );
        outhead1("%srepositive2:", label);

    } else {

        outline1("LD HL, %s", _source);
        outline0("LD IX, (HL)");
        outline0("INC HL");
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline0("LD C, A");
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline1("LD DE, (%s)", _destination);

        outline0("LD HL, 0");
        outline0("LD B, 32");
        outhead1("%sloop:", label);
        outline0("ADD IX, IX");
        outline0("RL C");
        outline0("RLA");
        outline0("ADC HL, HL");
        outline1("JR C, %soverflow", label);
        outline0("SBC HL, DE");
        outline1("JR NC, %ssetbit", label);
        outline0("ADD HL, DE");
        outline1("DJNZ %sloop", label);
        outline1("JMP %send", label);
        outhead1("%soverflow:", label);
        outline0("OR A");
        outline0("SBC HL, DE");
        outhead1("%ssetbit:", label);
        outline0("INC IXL");
        outline1("DJNZ %sloop", label);
        outhead1("%send:", label);
        outline1("LD (%s), HL", _other_remainder);
        outline1("LD HL, %s", _other);
        outline0("LD (HL), IX");
        outline0("INC HL");
        outline0("INC HL");
        outline0("INC HL");
        outline0("LD (HL), A");
        outline0("DEC HL");
        outline0("LD C, (HL)");

    }
 
}

void z80_math_div_16bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        outline1("LD A, (%s+3)", _source);
        outline0("AND $80");
        outline0("PUSH AF");
        outline1("JR Z,%spositive", label);
        z80_complement2_32bit( _environment, _source, NULL );
        outhead1("%spositive:", label);
        outline1("LD A, (%s+1)", _destination);
        outline0("AND $80");
        outline0("PUSH AF");
        outline1("JR Z,%spositive2", label);
        z80_complement2_16bit( _environment, _destination, NULL );
        outhead1("%spositive2:", label);

        outline1("LD HL, %s", _source);
        outline0("LD A, (HL)");
        outline0("LD C, A");
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline1("LD DE, (%s)", _destination);

        outline0("LD HL, 0");
        outline0("LD B, 16");
        outhead1("%sloop:", label );
        outline0("SLL C");
        outline0("RLA");
        outline0("ADC HL, HL");
        outline0("SBC HL, DE");
        outline0("JR NC, $+4");
        outline0("ADD HL, DE");
        outline0("DEC C");
        outline1("DJNZ %sloop", label);
        outline1("LD (%s), HL", _other_remainder);
        outline1("LD DE, %s", _other);
        outline0("LD B, A");
        outline0("LD A, C");
        outline0("LD (DE), A");
        outline0("INC DE");
        outline0("LD A, B");
        outline0("LD (DE), A");

        outline0("POP AF");
        outline0("CMP $80");
        outline1("JR NZ, %srepositive", label);
        z80_complement2_16bit( _environment, _destination, NULL );
        outhead1("%srepositive:", label);
        outline0("POP AF");
        outline0("CMP $80");
        outline1("JR NZ, %srepositive2", label );
        z80_complement2_32bit( _environment, _source, NULL );
        outhead1("%srepositive2:", label);

    } else {

        outline1("LD HL, %s", _source);
        outline0("LD A, (HL)");
        outline0("LD C, A");
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline1("LD DE, (%s)", _destination);

        outline0("LD HL, 0");
        outline0("LD B, 16");
        outhead1("%sloop:", label );
        outline0("SLL C");
        outline0("RLA");
        outline0("ADC HL, HL");
        outline0("SBC HL, DE");
        outline0("JR NC, $+4");
        outline0("ADD HL, DE");
        outline0("DEC C");
        outline1("DJNZ %sloop", label);
        outline1("LD (%s), HL", _other_remainder);
        outline1("LD DE, %s", _other);
        outline0("LD B, A");
        outline0("LD A, C");
        outline0("LD (DE), A");
        outline0("INC DE");
        outline0("LD A, B");
        outline0("LD (DE), A");

    }
    
}

void z80_math_div_8bit_to_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        outline1("LD A, (%s)", _source );
        outline0("LD B, A" );
        outline1("LD A, (%s)", _destination );
        outline0("XOR A, B" );
        outline0("AND $80" );
        outline0("PUSH AF" );
        outline1("LD A, (%s)", _source );
        outline0("AND $80" );
        outline1("JR Z,%spos", label );
        outline1("LD A, (%s)", _source );
        outline0("XOR $FF" );
        outline0("ADC $1" );
        outline1("JMP %spos2", label );
        outhead1("%spos:", label );
        outline1("LD A, (%s)", _source );
        outhead1("%spos2:", label );
        outline0("LD D, A");
        
        outline1("LD A, (%s)", _destination );
        outline0("AND $80" );
        outline1("JR Z,%sposx", label );
        outline1("LD A, (%s)", _destination );
        outline0("XOR $FF" );
        outline0("ADC $1" );
        outline1("JMP %sposx2", label );
        outhead1("%sposx:", label );
        outline1("LD A, (%s)", _destination );
        outhead1("%sposx2:", label );
        outline0("LD E, A");

        outline0("XOR A");
        outline0("LD B, 8");
        outhead1("%sloop:", label);

        outline0("SLA D");
        outline0("RLA");
        outline0("CP E");
        outline0("JR C, $+4");
        outline0("SUB E");
        outline0("INC D");
        outline1("DJNZ %sloop", label );

        outline1("LD (%s), A", _other_remainder);
        outline0("LD A, D");
        outline1("LD (%s), A", _other);

        outline0("POP AF" );
        outline0("AND $80" );
        outline1("JR Z,%spos3", label );
        outline1("LD A, (%s)", _other );
        outline0("XOR $FF" );
        outline0("ADC $1" );
        outline1("LD (%s), A", _other );
        outhead1("%spos3:", label );
        
    } else {

        outline1("LD A, (%s)", _source);
        outline0("LD D, A");
        outline1("LD A, (%s)", _destination);
        outline0("LD E, A");

        outline0("XOR A");
        outline0("LD B, 8");
        outhead1("%sloop:", label);

        outline0("SLA D");
        outline0("RLA");
        outline0("CP E");
        outline0("JR C, $+4");
        outline0("SUB E");
        outline0("INC D");
        outline1("DJNZ %sloop", label );

        outline1("LD (%s), A", _other_remainder);
        outline0("LD A, D");
        outline1("LD (%s), A", _other);

    }
}

void z80_bit_check( Environment * _environment, char *_value, int _position, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _value);
    switch( _position ) {
        case 31: case 30: case 29: case 28: case 27: case 26: case 25: case 24: 
            outline0("INC HL");
        case 23: case 22: case 21: case 20: case 19: case 18: case 17: case 16:
            outline0("INC HL");
        case 15: case 14: case 13: case 12: case 11: case 10: case 9: case 8:
            outline0("INC HL");
        case 7:  case 6:  case 5:  case 4:  case 3:  case 2:  case 1: case 0:
            outline0("LD A, (HL)");
            break;
    }
    outline1("BIT $%1.1x, A", ( _position & 0x07 ) );
    outline1("JR Z, %szero", label);
    outline0("LD A, $ff");
    outline1("LD (%s), A", _result);
    outline1("JMP %sdone", label);
    outhead1("%szero:", label);
    outline0("LD A, 0");
    outline1("LD (%s), A", _result);
    outhead1("%sdone:", label);

}

void z80_bit_check_extended( Environment * _environment, char *_value, char * _position, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _value);
    outline1("LD A, (%s)", _position);
    outline0("SRA A");
    outline0("SRA A");
    outline0("SRA A");
    outline0("CP 3");
    outline1("JR Z,%s_3", label );
    outline0("CP 2");
    outline1("JR Z,%s_2", label );
    outline0("CP 1");
    outline1("JR Z,%s_1", label );
    outline1("JMP %send", label );
    outhead1("%s_3:", label );
    outline0("INC HL" );
    outhead1("%s_2:", label );
    outline0("INC HL" );
    outhead1("%s_1:", label );
    outline0("INC HL" );
    outhead1("%send:", label );
    outline0("LD A, (HL)" );

    outline0("PUSH AF" );
    outline1("LD A, (%s)", _position);
    outline0("AND $07" );
    outline0("LD B, 1");
    outline0("CP 0");
    outline1("JR Z, %sdone2", label);
    outhead1("%sloop2:", label);
    outline0("SLA B");
    outline0("DEC A");
    outline1("JR NZ, %sloop2", label);
    outhead1("%sdone2:", label);
    outline0("POP AF" );

    outline0("AND A, B" );
    outline1("JR Z, %szero", label);
    outline0("LD A, $ff");
    outline1("LD (%s), A", _result);
    outline1("JMP %sdone", label);
    outhead1("%szero:", label);
    outline0("LD A, 0");
    outline1("LD (%s), A", _result);
    outhead1("%sdone:", label);

}

void z80_number_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits, int _signed ) {

    MAKE_LABEL
    
    deploy( numberToStringDeployed, src_hw_z80_number_to_string_asm );

    switch( _bits ) {
        case 8:
            outline1("LD A,(%s)", _number);
            if ( _signed ) {
                outline0("AND $80");
                outline0("LD B, A");
                outline1("JR Z, %sp8", label);
                outline0("XOR $FF");
                outline0("ADC $1");
                outhead1("%sp8:", label);
            }
            outline0("CALL N2D8");
            break;
        case 16:
            outline1("LD HL,(%s)", _number);
            if ( _signed ) {
                outline0("LD A, H");
                outline0("AND $80");
                outline0("LD B, A");
                outline1("JR Z, %sp16", label);
                outline0("LD A, H");
                outline0("XOR $FF");
                outline0("LD H, A");
                outline0("LD A, L");
                outline0("XOR $FF");
                outline0("LD L, A");
                outline0("LD DE, 1" );
                outline0("ADD HL, DE" );
                outline0("LD DE, 0" );
                outhead1("%sp16:", label);
            }
            outline0("CALL N2D16");
            break;
        case 32:
            outline1("LD HL,(%s)", _number);
            outline1("LD DE,(%s+2)", _number);
            if ( _signed ) {
                outline0("LD A, D");
                outline0("AND $80");
                outline0("LD B, A");
                outline1("JR Z, %sp32", label);
                outline0("LD A, D");
                outline0("XOR $FF");
                outline0("LD D, A");
                outline0("LD A, E");
                outline0("XOR $FF");
                outline0("LD E, A");
                outline0("LD A, H");
                outline0("XOR $FF");
                outline0("LD H, A");
                outline0("LD A, L");
                outline0("XOR $FF");
                outline0("LD L, A");
                outline0("EXX" );
                outline0("LD HL, 1" );
                outline0("LD DE, 0" );
                outline0("ADD HL, DE" );
                outline0("EXX" );
                outline0("ADD HL, DE" );
                outline0("EXX" );
                outhead1("%sp16:", label);
            }
            outline0("CALL N2D32");
            break;
        default:
            CRITICAL_DEBUG_UNSUPPORTED( _number, "unknown");
    }

    outline1("LD DE, (%s)", _string);
    outline0("LD A,C");
    outline1("LD (%s), A", _string_size);
    outline0("LDIR");

}

void z80_bits_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits ) {

    deploy( bitsToStringDeployed,src_hw_z80_bits_to_string_asm );

    switch( _bits ) {
        case 32:
            outline1("LD BC, (%s+2)", _number );
            outline1("LD DE, (%s)", _number );
            break;
        case 16:
            outline0("LD BC, 0" );
            outline1("LD DE, (%s)", _number );
            break;
        case 8:        
            outline0("LD BC, 0" );
            outline0("LD D, 0" );
            outline1("LD A, (%s)", _number );
            outline0("LD E, A" );
            outline0("LD A, 0" );
            break;
    }

    outline1("LD A, $%2.2x", _bits );
    outline0("CALL BINSTR");
    
    outline1("LD DE,(%s)", _string);
    outline1("LD A, $%2.2x", (_bits+1) );
    outline0("LD C, A");
    outline0("LD B, 0");
    outline0("LDIR");

    outline1("LD A, $%2.2x", _bits );
    outline1("LD HL, %s", _string_size );
    outline0("LD (HL), A" );

}

void z80_dsdefine( Environment * _environment, char * _string, char * _index ) {

    deploy( dstringDeployed,src_hw_z80_dstring_asm );

    outline1( "LD HL, %s", _string );
    outline0( "CALL DSDEFINE" );
    outline0( "LD A, B" );
    outline1( "LD (%s), A", _index );
    
}

void z80_dsalloc( Environment * _environment, char * _size, char * _index ) {

    deploy( dstringDeployed,src_hw_z80_dstring_asm );

    outline1( "LD A, (%s)", _size );
    outline0( "LD C, A" );
    outline0( "CALL DSALLOC" );
    outline0( "LD A, B" );
    outline1( "LD (%s), A", _index );

}

void z80_dsalloc_size( Environment * _environment, int _size, char * _index ) {

    deploy( dstringDeployed,src_hw_z80_dstring_asm );

    outline1( "LD A, $%2.2x", _size );
    outline0( "LD C, A" );
    outline0( "CALL DSALLOC" );
    outline0( "LD A, B" );
    outline1( "LD (%s), A", _index );

}

void z80_dsfree( Environment * _environment, char * _index ) {

    deploy( dstringDeployed,src_hw_z80_dstring_asm );

    outline1( "LD A, (%s)", _index );
    outline0( "LD B, A" );
    outline0( "CALL DSFREE" );

}

void z80_dswrite( Environment * _environment, char * _index ) {

    deploy( dstringDeployed,src_hw_z80_dstring_asm );

    outline1( "LD A, (%s)", _index );
    outline0( "LD B, A" );
    outline0( "CALL DSWRITE" );

}

void z80_dsresize( Environment * _environment, char * _index, char * _resize ) {

    deploy( dstringDeployed,src_hw_z80_dstring_asm );

    outline1( "LD A, (%s)", _index );
    outline0( "LD B, A" );
    outline1( "LD A, (%s)", _resize );
    outline0( "LD C, A" );
    outline0( "CALL DSRESIZE" );

}

void z80_dsresize_size( Environment * _environment, char * _index, int _resize ) {

    deploy( dstringDeployed,src_hw_z80_dstring_asm );

    outline1( "LD A, (%s)", _index );
    outline0( "LD B, A" );
    outline1( "LD A, $%2.2x", _resize );
    outline0( "LD C, A" );
    outline0( "CALL DSRESIZE" );

}

void z80_dsgc( Environment * _environment ) {

    deploy( dstringDeployed,src_hw_z80_dstring_asm );

    outline0( "CALL DSGC" );

}

void z80_dsdescriptor( Environment * _environment, char * _index, char * _address, char * _size ) {

    deploy( dstringDeployed,src_hw_z80_dstring_asm );

    outline1( "LD A, (%s)", _index );
    outline0( "LD B, A" );
    outline0( "CALL DSDESCRIPTOR" );
    outline0( "LD A, (IX)" );
    outline1( "LD (%s), A", _size );
    outline0( "LD A, (IX+1)" );
    outline1( "LD (%s), A", _address );
    outline0( "LD A, (IX+2)" );
    outline1( "LD (%s+1), A", _address );

}

void z80_move_8bit_indirect_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

    outline1("LD HL, (%s)", _value);
    outline1("LD DE, (%s)", _offset );
    outline0("ADD HL, DE" );
    outline1("LD A, (%s)", _source);
    outline0("LD (HL), A");

}

void z80_complement2_8bit( Environment * _environment, char * _source, char * _destination ) {
    outline1( "LD A, (%s)", _source );
    outline0( "XOR $FF" );
    outline0( "INC A" );        
    if ( _destination ) {
        outline1( "LD (%s), A", _destination );        
    } else {
        outline1( "LD (%s), A", _source );        
    }
    if ( _destination ) {
        z80_inc( _environment, _destination );
    } else {
        z80_inc( _environment, _source );
    }
}

void z80_complement2_16bit( Environment * _environment, char * _source, char * _destination ) {
    outline1( "LD A, (%s)", _source );
    outline0( "XOR $FF" );
    if ( _destination ) {
        outline1( "LD (%s), A", _destination );        
    } else {
        outline1( "LD (%s), A", _source );        
    }
    outline1( "LD A, (%s+1)", _source );
    outline0( "XOR $FF" );
    if ( _destination ) {
        outline1( "LD (%s+1), A", _destination );        
    } else {
        outline1( "LD (%s+1), A", _source );        
    }
    if ( _destination ) {
        z80_inc_16bit( _environment, _destination );
    } else {
        z80_inc_16bit( _environment, _source );
    }
}

void z80_complement2_32bit( Environment * _environment, char * _source, char * _destination ) {
    outline1( "LD A, (%s)", _source );
    outline0( "XOR $FF" );
    if ( _destination ) {
        outline1( "LD (%s), A", _destination );        
    } else {
        outline1( "LD (%s), A", _source );        
    }
    outline1( "LD A, (%s+1)", _source );
    outline0( "XOR $FF" );
    if ( _destination ) {
        outline1( "LD (%s+1), A", _destination );        
    } else {
        outline1( "LD (%s+1), A", _source );        
    }
    outline1( "LD A, (%s+2)", _source );
    outline0( "XOR $FF" );
    if ( _destination ) {
        outline1( "LD (%s+2), A", _destination );        
    } else {
        outline1( "LD (%s+2), A", _source );        
    }
    outline1( "LD A, (%s+3)", _source );
    outline0( "XOR $FF" );
    if ( _destination ) {
        outline1( "LD (%s+3), A", _destination );        
    } else {
        outline1( "LD (%s+3), A", _source );        
    } 
    if ( _destination ) {
        z80_inc_32bit( _environment, _destination );
    } else {
        z80_inc_32bit( _environment, _source );
    }
}


char * src_hw_chipset_mob_asm;
unsigned int src_hw_chipset_mob_asm_len;

void z80_mobinit( Environment * _environment, char * _index, char *_x, char *_y,  char *_draw) {


}

void z80_mobshow( Environment * _environment, char * _index ) {

}

void z80_mobhide( Environment * _environment, char * _index ) {

}

void z80_mobat( Environment * _environment, char * _index, char *_x, char *_y ) {

}

void z80_mobrender( Environment * _environment, int _on_vbl ) {

}

void z80_sqroot( Environment * _environment, char * _number, char * _result ) {

    deploy( sqrDeployed, src_hw_z80_sqr_asm );

    outline1("LD HL,(%s)", _number );

    outline0("CALL SQROOT" );

    outline1("LD (%s),A", _result );

}

#endif