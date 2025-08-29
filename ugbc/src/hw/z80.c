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

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "cpu.h"

#include <math.h>

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#if defined(__zx__) || defined(__msx1__) || defined(__coleco__) || defined(__sc3000__) || defined(__sg1000__) || defined(__cpc__) || defined(__vg5000__) || defined(__c128z__) || defined(__vz200__)

void cpu_init( Environment * _environment ) {

    char duffDevice[38] = {
        // +00
        0x18, 0x00, 0xED, 0xA0, 0xED, 0xA0, 0xED, 0xA0,
        // +08
        0xED, 0xA0, 0xED, 0xA0, 0xED, 0xA0, 0xED, 0xA0,
        // +16
        0xED, 0xA0, 0xED, 0xA0, 0xED, 0xA0, 0xED, 0xA0,
        // +24
        0xED, 0xA0, 0xED, 0xA0, 0xED, 0xA0, 0xED, 0xA0,
        // +32
        0xED, 0xA0, 0xEA, 0x00, 0x00, 0xC9
    };

    variable_import( _environment, "DUFFDEVICEL0", VT_BUFFER, 36 );
    variable_global( _environment, "DUFFDEVICEL0" );
    variable_import( _environment, "DUFFDEVICEL1", VT_ADDRESS, 0 );
    variable_global( _environment, "DUFFDEVICEL1" );

    variable_retrieve( _environment, "DUFFDEVICEL0" )->readonly = 0;

    variable_store_buffer( _environment, "DUFFDEVICEL0", duffDevice, sizeof( duffDevice ), 0 );

    outline0( "LD HL, DUFFDEVICEL0");
    outline0( "LD DE, 35");
    outline0( "ADD HL, DE");
    outline0( "LD DE, DUFFDEVICEL0");
    outline0( "INC DE");
    outline0( "INC DE");
    outline0( "LD (HL), DE");

    variable_import( _environment, "CALLINDIRECTSAVEHL", VT_ADDRESS, 0 );
    variable_global( _environment, "CALLINDIRECTSAVEHL" );

    char callIndirect[3] = {
        // +00
        0xc3, 0x00, 0x00
    };

    variable_import( _environment, "CALLINDIRECT", VT_BUFFER, 3 );
    variable_global( _environment, "CALLINDIRECT" );

    variable_store_buffer( _environment, "CALLINDIRECT", callIndirect, sizeof( callIndirect ), 0 );
    variable_retrieve( _environment, "CALLINDIRECT" )->readonly = 0;

}

void cpu_nop( Environment * _environment ) {

    outline0("NOP");

}

void cpu_ztoa( Environment * _environment ) {

    inline( cpu_ztoa )

        MAKE_LABEL

        outline1("JR Z, %syes", label );
        outline0("LD A, 0");
        outline1("JP %s", label );
        outhead1("%syes:", label );
        outline0("LD A, $ff");
        outhead1("%s:", label );

    no_embedded( cpu_ztoa )

}

void cpu_ctoa( Environment * _environment ) {

    inline( cpu_ctoa )

        MAKE_LABEL

        outline1("JR C, %syes", label );
        outline0("LD A, 0");
        outline1("JP %s", label );
        outhead1("%syes:", label );
        outline0("LD A, $ff");
        outhead1("%s:", label );

    no_embedded( cpu_ctoa )

}

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
void cpu_beq( Environment * _environment, char * _label ) {

    inline( cpu_beq )

        outline1("JP Z, %s", _label);

    no_embedded( cpu_beq )

}

/**
 * @brief <i>Z80</i>: emit code to make long conditional jump

 * @param _environment Current calling environment
 * @param _label Destination of the conditional jump.
 */
void cpu_bneq( Environment * _environment, char * _label ) {

    inline( cpu_bneq )

        outline1("JP NZ, %s", _label);

    no_embedded( cpu_bneq )

}

void cpu_bveq( Environment * _environment, char * _value, char * _label ) {

    inline( cpu_bveq )

        outline1("LD A, (%s)", _value);
        outline0("CP 0");
        cpu_beq( _environment, _label );

    no_embedded( cpu_bneq )

}

void cpu_bvneq( Environment * _environment, char * _value, char * _label ) {

    inline( cpu_bvneq )

        outline1("LD A, (%s)", _value);
        outline0("CP 0");
        cpu_bneq( _environment, _label );

    no_embedded( cpu_bvneq )

}

void cpu_label( Environment * _environment, char * _label ) {
    outhead1("%s:", _label);
}

void cpu_peek( Environment * _environment, char * _address, char * _target ) {

    inline( cpu_peek )

        outline1("LD HL, (%s)", _address);
        outline0("LD A, (HL)");
        outline1("LD (%s), A", _target);

    no_embedded( cpu_peek )

}

void cpu_poke( Environment * _environment, char * _address, char * _source ) {

    inline( cpu_poke )

        outline1("LD A, (%s)", _source);
        outline1("LD HL, (%s)", _address);
        outline0("LD (HL), A");

    no_embedded( cpu_poke )

}

void cpu_poke_const( Environment * _environment, char * _address, int _source ) {

    // inline( cpu_poke )

        outline1("LD A, $%2.2x", (unsigned char)(_source&0xff));
        outline1("LD HL, (%s)", _address);
        outline0("LD (HL), A");

    // no_embedded( cpu_poke )

}

void cpu_peekw( Environment * _environment, char * _address, char * _target ) {

    inline( cpu_peek )

        outline1("LD HL, (%s)", _address);
        outline0("LD A, (HL)");
        outline1("LD (%s), A", _target);
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline1("LD (%s), A", address_displacement( _environment, _target, "1" ) );

    no_embedded( cpu_peek )

}

void cpu_pokew( Environment * _environment, char * _address, char * _source ) {

    inline( cpu_poke )

        outline1("LD A, (%s)", _source);
        outline1("LD HL, (%s)", _address);
        outline0("LD (HL), A");
        outline1("LD A, (%s)", address_displacement( _environment, _source, "1" ) );
        outline0("INC HL");
        outline0("LD (HL), A");

    no_embedded( cpu_poke )

}

void cpu_pokew_const( Environment * _environment, char * _address, int _source ) {

    // inline( cpu_poke )

        outline1("LD A, $%2.2x", (unsigned char)(_source&0xff));
        outline1("LD HL, (%s)", _address);
        outline0("LD (HL), A");
        outline1("LD A, $%2.2x", (unsigned char)((_source>>8)&0xff));
        outline0("INC HL");
        outline0("LD (HL), A");

    // no_embedded( cpu_poke )

}

void cpu_peekd( Environment * _environment, char * _address, char * _target ) {

    inline( cpu_peek )

        outline1("LD HL, (%s)", _address);
        outline0("LD A, (HL)");
        outline1("LD (%s), A", _target);
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline1("LD (%s), A", address_displacement( _environment, _target, "1" ) );
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline1("LD (%s), A", address_displacement( _environment, _target, "2" ) );
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline1("LD (%s), A", address_displacement( _environment, _target, "3" ) );

    no_embedded( cpu_peek )

}

void cpu_poked( Environment * _environment, char * _address, char * _source ) {

    inline( cpu_poke )

        outline1("LD A, (%s)", _source);
        outline1("LD HL, (%s)", _address);
        outline0("LD (HL), A");
        outline1("LD A, (%s)", address_displacement( _environment, _source, "1" ) );
        outline0("INC HL");
        outline0("LD (HL), A");
        outline1("LD A, (%s)", address_displacement( _environment, _source, "2" ) );
        outline0("INC HL");
        outline0("LD (HL), A");
        outline1("LD A, (%s)", address_displacement( _environment, _source, "3" ) );
        outline0("INC HL");
        outline0("LD (HL), A");

    no_embedded( cpu_poke )

}

void cpu_poked_const( Environment * _environment, char * _address, int _source ) {

    // inline( cpu_poke )

        outline1("LD A, $%2.2x", (unsigned char)(_source&0xff));
        outline1("LD HL, (%s)", _address);
        outline0("LD (HL), A");
        outline1("LD A, $%2.2x", (unsigned char)((_source>>8)&0xff));
        outline0("INC HL");
        outline0("LD (HL), A");
        outline1("LD A, $%2.2x", (unsigned char)((_source>>16)&0xff));
        outline0("INC HL");
        outline0("LD (HL), A");
        outline1("LD A, $%2.2x", (unsigned char)((_source>>24)&0xff));
        outline0("INC HL");
        outline0("LD (HL), A");

    // no_embedded( cpu_poke )

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
void cpu_fill_blocks( Environment * _environment, char * _address, char * _blocks, char * _pattern ) {

    inline( cpu_fill_blocks )

        MAKE_LABEL

        outline1("LD A, (%s)", _pattern);
        outline1("LD HL, (%s)", _address);
        outline0("LD (HL),A")
        outline0("LD E,L");
        outline0("LD D,H");
        outline0("INC DE");
        outline0("LD (DE),A")
        outline0("LD C,0");
        outline1("LD A, (%s)", _blocks);
        outline0("CP 0");
        outline1("JR Z, %sdone", label);
        outline0("DEC A");
        outline0("LD B,A");
        outline0("LDIR");

        outline1("LD A, (%s)", _pattern);
        outline0("LD (HL),A")
        outline0("LD E,L");
        outline0("LD D,H");
        outline0("INC DE");
        outline0("LD (DE),A")
        outline0("LD C,255");
        outline0("LD A,0");
        outline0("LD B,A");
        outline0("LDIR");
        outhead1("%sdone:", label);

    embedded( cpu_fill_blocks, src_hw_z80_cpu_fill_blocks_asm );

        outline1("LD A, (%s)", _blocks);
        outline0("LD B, A");
        outline1("LD A, (%s)", _pattern);
        outline1("LD HL, (%s)", _address);
        outline0("CALL CPUFILLBLOCKS");

    done(  )

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
void cpu_fill( Environment * _environment, char * _address, char * _bytes, int _bytes_width, char * _pattern ) {

    MAKE_LABEL

    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_z80_cpu_fill_asm );

        if ( _bytes_width == 8 ) {
            outline1("LD A, (%s)", _bytes);
            outline0("LD C, A");
        } else {
            outline1("LD A, (%s)", _bytes);
            outline0("LD C, A");
            outline1("LD A, (%s+1)", _bytes);
            outline0("LD B, A");
        }

        outline1("LD A, (%s)", _pattern);
        outline1("LD HL, (%s)", _address);

        if ( _bytes_width == 8 ) {
            outline0("CALL CPUFILL8");
        } else {
            outline0("CALL CPUFILL16");
        }

    done(  )
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
void cpu_fill_size( Environment * _environment, char * _address, int _bytes, char * _pattern ) {

    MAKE_LABEL

    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_z80_cpu_fill_asm );

        outline1("LD A, $%2.2x", (unsigned char) ( _bytes & 0xff ) );
        outline0("LD C, A");

        if ( _bytes < 256 ) {

        } else {
            outline1("LD A, $%2.2x", (unsigned char) ( ( _bytes >> 8 ) & 0xff ) );
            outline0("LD B, A");
        }

        outline1("LD A, (%s)", _pattern);
        outline1("LD HL, (%s)", _address);
        if ( _bytes < 256 ) {
            outline0("CALL CPUFILL8");
        } else {
            outline0("CALL CPUFILL16");
        }

    done(  )

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
void cpu_fill_size_value( Environment * _environment, char * _address, int _bytes, int _pattern ) {

    MAKE_LABEL

    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_z80_cpu_fill_asm );

        outline1("LD A, $%2.2x", (unsigned char) ( _bytes & 0xff ) );
        outline0("LD C, A");

        if ( _bytes < 256 ) {

        } else {
            outline1("LD A, $%2.2x", (unsigned char) ( ( _bytes >> 8 ) & 0xff ) );
            outline0("LD B, A");
        }

        outline1("LD A, $%2.2x", _pattern);
        outline1("LD HL, (%s)", _address);
        if ( _bytes < 256 ) {
            outline0("CALL CPUFILL8");
        } else {
            outline0("CALL CPUFILL16");
        }

    done(  )

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
void cpu_fill_direct( Environment * _environment, char * _address, char * _bytes, char * _pattern ) {

    MAKE_LABEL

    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_z80_cpu_fill_asm );

        outline1("LD A, (%s)", _bytes);
        outline0("LD C, A");
        outline1("LD A, (%s+1)", _bytes);
        outline0("LD B, A");
        outline1("LD A, (%s)", _pattern);
        outline1("LD HL, %s", _address);
        outline0("CALL CPUFILL16");

    done(  )

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
void cpu_fill_direct_size( Environment * _environment, char * _address, int _bytes, char * _pattern ) {

    MAKE_LABEL

    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_z80_cpu_fill_asm );

        outline1("LD A, $%2.2x", (unsigned char) ( _bytes & 0xff ) );
        outline0("LD C, A");

        if ( _bytes < 256 ) {

        } else {
            outline1("LD A, $%2.2x", (unsigned char) ( ( _bytes >> 8 ) & 0xff ) );
            outline0("LD B, A");
        }

        outline1("LD A, (%s)", _pattern);
        outline1("LD HL, %s", _address);
        if ( _bytes < 256 ) {
            outline0("CALL CPUFILL8");
        } else {
            outline0("CALL CPUFILL16");
        }

    done(  )

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
void cpu_fill_direct_size_value( Environment * _environment, char * _address, int _bytes, int _pattern ) {

    MAKE_LABEL
    
    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_z80_cpu_fill_asm );

        outline1("LD A, $%2.2x", (unsigned char) ( _bytes & 0xff ) );
        outline0("LD C, A");

        if ( _bytes < 256 ) {

        } else {
            outline1("LD A, $%2.2x", (unsigned char) ( ( _bytes >> 8 ) & 0xff ) );
            outline0("LD B, A");
        }

        outline1("LD A, $%2.2x", _pattern);
        outline1("LD HL, %s", _address);
        if ( _bytes < 256 ) {
            outline0("CALL CPUFILL8");
        } else {
            outline0("CALL CPUFILL16");
        }

    done(  )
    
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
void cpu_move_8bit( Environment * _environment, char *_source, char *_destination ) {
    
    inline( cpu_move_8bit )

        outline1("LD A, (%s)", _source);
        outline1("LD (%s), A", _destination);

    no_embedded( cpu_move_8bit )

}

/**
 * @brief <i>Z80</i>: emit code to store 8 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void cpu_store_8bit( Environment * _environment, char *_destination, int _value ) {

    inline( cpu_store_8bit )

        outline1("LD A, $%2.2x", ( _value & 0xff ) );
        outline1("LD (%s), A", _destination);

    no_embedded( cpu_store_8bit )

}

/**
 * @brief <i>Z80</i>: emit code to store 8 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void cpu_store_char( Environment * _environment, char *_destination, int _value ) {

    inline( cpu_store_char )

        outline1("LD A, '%c'", ( _value & 0xff ) );
        outline1("LD (%s), A", _destination);

    no_embedded( cpu_store_char )

}

void cpu_store_8bit_with_offset( Environment * _environment, char *_destination, int _value, int _offset ) {

    inline( cpu_store_8bit_with_offset )

        outline1("LD DE, %s", _destination);
        outline1("ADD DE, $%2.2x", ( _offset & 0xff ) );
        outline1("LD A, $%2.2x", ( _value & 0xff ) );
        outline0("LD (DE), A");

    no_embedded( cpu_store_8bit_with_offset )

}

void cpu_store_8bit_with_offset2( Environment * _environment, char *_destination, char * _offset, int _value ) {

    inline( cpu_store_8bit_with_offset2 )

        outline1("LD HL, %s", _destination);
        outline1("LD A, (%s)", _offset);
        outline0("LD E, A");
        outline0("LD D, 0");
        outline0("ADD HL, DE" );
        outline1("LD A, $%2.2x", ( _value & 0xff ) );
        outline0("LD (HL), A");

    no_embedded( cpu_store_8bit_with_offset2 )

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
void cpu_compare_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_8bit )

        outline1("LD HL, %s", _destination);
        outline1("LD A, (%s)", _source);
        outline0("CP (HL)");
        outline1("JP NZ, %s", label);
        outline1("LD A, $%2.2x", 0xff*_positive);
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline0("LD (HL), A");
        }
        outline1("JMP %sb2", label);
        outhead1("%s:", label);
        outline1("LD A, $%2.2x", 0xff*(1-_positive));
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline0("LD (HL), A");
        }
        outhead1("%sb2:", label);

    no_embedded( cpu_compare_8bit )

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
void cpu_compare_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_8bit )

        outline1("LD A, (%s)", _source);
        outline1("CP $%2.2x", _destination);
        outline1("JP NZ, %s", label);
        outline1("LD A, $%2.2x", 0xff*_positive);
        outline1("LD (%s), A", _other);
        outline1("JMP %sb2", label);
        outhead1("%s:", label);
        outline1("LD A, $%2.2x", 0xff*(1-_positive));
        outline1("LD (%s), A", _other);
        outhead1("%sb2:", label);

    no_embedded( cpu_compare_8bit )

}

void cpu_compare_and_branch_8bit( Environment * _environment, char *_source, char * _destination,  char *_label, int _positive ) {

    inline( cpu_compare_and_branch_8bit )

        MAKE_LABEL

        outline1("LD A, (%s)", _destination);
        outline0("LD B, A");
        outline1("LD A, (%s)", _source);
        outline1("CP B", _destination );
        if ( _positive ) {
            outline1("JP Z, %s", _label);
        } else {
            outline1("JP NZ, %s", _label);
        }

    no_embedded( cpu_compare_and_branch_8bit )

}

/**
 * @brief <i>Z80</i>: emit code to compare two 8 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void cpu_compare_and_branch_8bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

    inline( cpu_compare_and_branch_8bit_const )

        MAKE_LABEL

        outline1("LD A, (%s)", _source);
        outline1("CP $%2.2x", _destination );
        if ( _positive ) {
            outline1("JP Z, %s", _label);
        } else {
            outline1("JP NZ, %s", _label);
        }

    no_embedded( cpu_compare_and_branch_8bit_const )

}

/**
 * @brief <i>Z80</i>: emit code to compare two 8 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void cpu_prepare_for_compare_and_branch_8bit( Environment * _environment, char *_source ) {

    inline( cpu_compare_and_branch_8bit_const )

        outline1("LD A, (%s)", _source);

    no_embedded( cpu_compare_and_branch_8bit_const )

}

/**
 * @brief <i>Z80</i>: emit code to compare two 8 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void cpu_execute_compare_and_branch_8bit_const( Environment * _environment, int _destination,  char *_label, int _positive ) {

    inline( cpu_compare_and_branch_8bit_const )

        MAKE_LABEL

        outline1("CP $%2.2x", _destination );
        if ( _positive ) {
            outline1("JP Z, %s", _label);
        } else {
            outline1("JP NZ, %s", _label);
        }

    no_embedded( cpu_compare_and_branch_8bit_const )

}

/**
 * @brief <i>Z80</i>: emit code to compare two 8 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void cpu_compare_and_branch_char_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

    inline( cpu_compare_and_branch_8bit_const )

        MAKE_LABEL

        outline1("LD A, (%s)", _source);
        outline1("CP '%c'", _destination );
        if ( _positive ) {
            outline1("JP Z, %s", _label);
        } else {
            outline1("JP NZ, %s", _label);
        }

    no_embedded( cpu_compare_and_branch_8bit_const )

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
void cpu_less_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    inline( cpu_less_than_8bit )

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

    embedded( cpu_less_than_8bit, src_hw_z80_cpu_less_than_8bit_asm );

        if ( _signed ) {

            outline1("LD A, (%s)", _destination);
            outline0("LD B, A");
            outline1("LD A, (%s)", _source);
            if ( _equal ) {
                outline0("CALL CPULTE8S");
            } else {
                outline0("CALL CPULT8S");
            }
            if ( _other ) {
                outline1("LD (%s), A", _other);
            } else {
                outline1("LD (%s), A", _destination);
            }

        } else {

            outline1("LD A, (%s)", _destination);
            outline0("LD B, A");
            outline1("LD A, (%s)", _source);
            if ( _equal ) {
                outline0("CALL CPULTE8U");
            } else {
                outline0("CALL CPULT8U");
            }
            if ( _other ) {
                outline1("LD (%s), A", _other);
            } else {
                outline1("LD (%s), A", _destination);
            }

        }

    done(  )

}

void cpu_less_than_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    inline( cpu_less_than_8bit )

        if ( _signed ) {

            outline1("LD A, $%2.2x", ( _destination & 0xff ) );
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
            outline1("LD (%s), A", _other);
            outline1("JMP %sb2", label);
            outhead1("%strue:", label);
            outline0("LD A, $ff");
            outline1("LD (%s), A", _other);
            outhead1("%sb2:", label);

        } else {

            outline1("LD A, $%2.2x", ( _destination & 0xff ) );
            outline0("LD B, A");
            outline1("LD A, (%s)", _source);
            outline0("CP B");
            outline1("JR C, %s", label);
            if ( _equal ) {
                outline1("JR Z, %s", label);
            }
            outline0("LD A, 0");
            outline1("LD (%s), A", _other);
            outline1("JMP %sb2", label);
            outhead1("%s:", label);
            outline0("LD A, $ff");
            outline1("LD (%s), A", _other);
            outhead1("%sb2:", label);

        }

    embedded( cpu_less_than_8bit, src_hw_z80_cpu_less_than_8bit_asm );

        if ( _signed ) {

            outline1("LD A, $%2.2x", _destination);
            outline0("LD B, A");
            outline1("LD A, (%s)", _source);
            if ( _equal ) {
                outline0("CALL CPULTE8S");
            } else {
                outline0("CALL CPULT8S");
            }
            outline1("LD (%s), A", _other);

        } else {

            outline1("LD A, $%2.2x", _destination);
            outline0("LD B, A");
            outline1("LD A, (%s)", _source);
            if ( _equal ) {
                outline0("CALL CPULTE8U");
            } else {
                outline0("CALL CPULT8U");
            }
            outline1("LD (%s), A", _other);

        }

    done(  )

}

void cpu_less_than_and_branch_8bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _equal, int _signed ) {

    MAKE_LABEL

    inline( cpu_less_than_8bit )

        if ( _signed ) {

            outline1("LD A, $%2.2x", ( _destination & 0xff ) );
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
            outline1("JP %sb2", label);
            outhead1("%strue:", label);
            outline1("JP %s", _label);
            outhead1("%sb2:", label);

        } else {

            outline1("LD A, $%2.2x", ( _destination & 0xff ) );
            outline0("LD B, A");
            outline1("LD A, (%s)", _source);
            outline0("CP B");
            outline1("JR C, %s", label);
            if ( _equal ) {
                outline1("JR Z, %s", label);
            }
            outline1("JP %sb2", label);
            outhead1("%s:", label);
            outline1("JP %s", _label);
            outhead1("%sb2:", label);

        }

    embedded( cpu_less_than_8bit, src_hw_z80_cpu_less_than_8bit_asm );

        if ( _signed ) {

            outline1("LD A, $%2.2x", _destination);
            outline0("LD B, A");
            outline1("LD A, (%s)", _source);
            if ( _equal ) {
                outline0("CALL CPULTE8S");
            } else {
                outline0("CALL CPULT8S");
            }
            outline0("CP 0");
            outline1("JR Z, %sno", label);
            outline1("JP %s", _label);
            outhead1("%sno:", label);

        } else {

            outline1("LD A, $%2.2x", _destination);
            outline0("LD B, A");
            outline1("LD A, (%s)", _source);
            if ( _equal ) {
                outline0("CALL CPULTE8U");
            } else {
                outline0("CALL CPULT8U");
            }
            outline0("CP 0");
            outline1("JR Z, %sno", label);
            outline1("JP %s", _label);
            outhead1("%sno:", label);

        }

    done(  )

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
void cpu_greater_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    cpu_less_than_8bit( _environment, _source, _destination, _other, !_equal, _signed );
    if ( _other ) {
        cpu_not_8bit( _environment, _other, _other );
    } else {
        cpu_not_8bit( _environment, _destination, _destination );
    }

}

void cpu_greater_than_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    cpu_less_than_8bit_const( _environment, _source, _destination, _other, !_equal, _signed );
    cpu_not_8bit( _environment, _other, _other );

}

/**
 * @brief <i>Z80</i>: emit code to add two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu_math_add_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_add_8bit )

        outline0("LD B, 0" );
        outline1("LD A, (%s)", _source );
        outline0("LD B, A" );
        outline1("LD A, (%s)", _destination );
        outline0("ADD A, B" );
        if ( _other ) {
            outline1("LD (%s), A", _other );
        } else {
            outline1("LD (%s), A", _destination );
        }

    no_embedded( cpu_math_add_8bit )

}

void cpu_math_add_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

    inline( cpu_math_add_8bit )

        outline0("LD B, 0" );
        outline1("LD A, (%s)", _source );
        outline0("ADD A, B" );
        outline0("LD B, A" );
        outline1("LD A, $%2.2x", ( _destination & 0xff ) );
        outline0("ADD A, B" );
        outline1("LD (%s), A", _other );

    no_embedded( cpu_math_add_8bit )

}

/**
 * @brief <i>Z80</i>: emit code to subtract two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to subtract
 * @param _destination Second value to subtract and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu_math_sub_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_sub_8bit )

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

    no_embedded( cpu_math_add_8bit )

}

/**
 * @brief <i>Z80</i>: emit code to double a 8 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu_math_double_8bit( Environment * _environment, char *_source, char *_other, int _signed ) {

    inline( cpu_math_double_8bit )

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

    no_embedded( cpu_math_double_8bit )

}

/**
 * @brief <i>Z80</i>: emit code to multiply two 8bit values in a 16 bit register
 * 
 * @param _environment Current calling environment
 * @param _source First value to multipy (8 bit)
 * @param _destination Second value to multipy (8 bit)
 * @param _other Destination address for result (16 bit)
 */

void cpu_math_mul_8bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _signed ) {

    MAKE_LABEL

    inline( cpu_math_mul_8bit_to_16bit )

        if ( _signed ) {

            outline1("LD A, (%s)", _source );
            outline0("LD B, A" );
            outline1("LD A, (%s)", _destination );
            outline0("XOR A, B" );
            outline0("AND $80" );
            outline0("LD B, A" );
            outline0("PUSH B" );

            outline1("LD A, (%s)", _source );
            outline0("AND $80" );
            outline0("CP 0" );
            outline1("JR Z, %spositive", label );
            outline1("LD A, (%s)", _source );
            outline0("XOR $FF" );
            outline0("INC A" );
            outline1("JMP %sdone1", label );

            outhead1("%spositive:", label );
            outline1("LD A, (%s)", _source );

            outhead1("%sdone1:", label );
            outline0("LD H, A" );

            outline1("LD A, (%s)", _destination );
            outline0("AND $80" );
            outline0("CP 0" );
            outline1("JR Z, %spositive2", label );
            outline1("LD A, (%s)", _destination );
            outline0("XOR $FF" );
            outline0("INC A" );
            outline1("JMP %sdone2", label );
            outhead1("%spositive2:", label );
            outline1("LD A, (%s)", _destination );

            outhead1("%sdone2:", label );
            outline0("LD C, A" );

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
            outline0("POP B" );
            outline0("LD A, B" );
            outline0("AND $80" );
            outline0("CP 0" );
            outline1("JR Z,%snc", label );
            cpu_complement2_16bit( _environment, _other, NULL );
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

    embedded( cpu_math_mul_8bit_to_16bit, src_hw_z80_cpu_math_mul_8bit_to_16bit_asm );

        if ( _signed ) {

            outline1("LD A, (%s)", _destination);
            outline0("LD IYL, A");
            outline1("LD A, (%s)", _source);
            outline0("LD IXL, A");
            outline0("CALL CPUMUL8B8T16S");
            outline1("LD (%s), HL", _other);

        } else {

            outline1("LD A, (%s)", _destination);
            outline0("LD IYL, A");
            outline1("LD A, (%s)", _source);
            outline0("LD IXL, A");
            outline0("CALL CPUMUL8B8T16U");
            outline1("LD (%s), HL", _other);

        }

    done(  )

}

/**
 * @brief <i>Z80</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu_math_div2_const_8bit( Environment * _environment, char *_source, int _steps, int _signed, char * _remainder ) {

    inline( cpu_math_div2_const_8bit )

        MAKE_LABEL

        if ( _remainder ) {
            outline1("LD A, (%s)", _source );
            outline0("AND $1" );
            outline1("LD (%s), A", _remainder );
        }
        if ( _signed ) {
            outline1("LD A, (%s)", _source );
            outline0("AND $80" );
            outline0("PUSH AF" );
            outline0("CP 0" );
            outline1("JR Z, %spos", label );
            cpu_complement2_16bit( _environment, _source, _source );
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
            outline0("CP 0" );
            outline1("JR Z, %sdone", label );
            cpu_complement2_16bit( _environment, _source, _source );
            outhead1("%sdone:", label );
        } else {
            outline1("LD A, (%s)", _source );
            while( _steps ) {
                outline0("SRA A" );
                --_steps;
            }
            outline1("LD (%s), A", _source );
        }

    embedded( cpu_math_div2_const_8bit, src_hw_z80_cpu_math_div2_const_8bit_asm );

        if ( _remainder ) {
            outline1("LD A, (%s)", _source );
            outline0("AND $1" );
            outline1("LD (%s), A", _remainder );
        }
        outline1("LD A, (%s)", _source);
        outline0("LD B, A");
        outline1("LD A, $%2.2x", _steps);
        outline0("LD C, A");
        if ( _signed ) {
            outline0("CALL CPUDIV2CONST8S");
        } else {
            outline0("CALL CPUDIV2CONST8U");
        }
        outline0("LD A, B");
        outline1("LD (%s), A", _source);

    done( )

}

/**
 * @brief <i>Z80</i>: emit code to double for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 */
void cpu_math_mul2_const_8bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    inline( cpu_math_mul2_const_8bit )

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
            outline1("LD A, (%s)", _source );
            while( _steps ) {
                outline0("SLA A" );
                --_steps;
            }
            outline1("LD (%s), A", _source );
        }

    embedded( cpu_math_mul2_const_8bit, src_hw_z80_cpu_math_mul2_const_8bit_asm );

        outline1("LD A, (%s)", _source);
        outline0("LD B, A");
        outline1("LD A, $%2.2x", _steps);
        outline0("LD C, A");
        if ( _signed ) {
            outline0("CALL CPUMUL2CONST8S");
        } else {
            outline0("CALL CPUMUL2CONST8U");
        }
        outline0("LD A, B");
        outline1("LD (%s), A", _source);

    done( )

}

/**
 * @brief <i>Z80</i>: emit code to calculate an 8 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void cpu_math_complement_const_8bit( Environment * _environment, char *_source, int _value ) {

    inline( cpu_math_complement_const_8bit )

        outline1("LD A, (%s)", _source );
        outline0("LD B, A" );
        outline1("LD A, $%2.2x", ( _value & 0xff ) );
        outline0("SUB A, B" );
        outline1("LD (%s), A", _source );

    no_embedded( cpu_math_complement_const_8bit )

}

/**
 * @brief <i>Z80</i>: emit code to mask with "and" a value of 8 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void cpu_math_and_const_8bit( Environment * _environment, char *_source, int _mask ) {

    inline( cpu_math_and_const_8bit )

        outline1("LD A, (%s)", _source );
        outline1("AND $%2.2x", _mask );
        outline1("LD (%s), A", _source );

    no_embedded( cpu_math_and_const_8bit )

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
void cpu_move_16bit( Environment * _environment, char *_source, char *_destination ) {
    
    inline( cpu_move_16bit )

        outline1("LD HL, (%s)", _source );
        outline1("LD (%s), HL", _destination );

    no_embedded( cpu_move_16bit )

}

void cpu_addressof_16bit( Environment * _environment, char *_source, char *_destination ) {
    
    inline( cpu_addressof_16bit )

        outline1("LD HL, %s", _source );
        outline1("LD (%s), HL", _destination );

    no_embedded( cpu_addressof_16bit )

}

/**
 * @brief <i>Z80</i>: emit code to store 16 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void cpu_store_16bit( Environment * _environment, char *_destination, int _value ) {

    inline( cpu_store_16bit )

        outline1("LD HL, $%4.4x", _value & 0xffff );
        outline1("LD (%s), HL", _destination );

    no_embedded( cpu_store_16bit )

}

/**
 * @brief <i>Z80</i>: emit code to compare two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu_compare_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_16bit )

        outline1("LD A, (%s)", _source);
        outline0("LD B, A");
        outline1("LD A, (%s)", _destination);
        outline0("CP B");
        outline1("JP NZ, %s", label);
        outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
        outline0("LD B, A");
        outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
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

    embedded( cpu_compare_16bit, src_hw_z80_cpu_compare_16bit_asm )

        outline1("LD HL, %s", _source);
        outline1("LD DE, %s", _destination);
        outline1("LD IX, $%4.4x", ( (0xff*_positive) << 8 ) | ( 0xff*(1-_positive)) );
        outline0("CALL CPUCOMPARE16");
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline1("LD (%s), A", _destination);
        }

    done( )

}

/**
 * @brief <i>Z80</i>: emit code to compare two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu_compare_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_16bit )

        outline1("LD A, (%s)", _source);
        outline0("LD B, A");
        outline1("LD A, $%2.2x", (unsigned char)(_destination&0xff));
        outline0("CP B");
        outline1("JP NZ, %s", label);
        outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
        outline0("LD B, A");
        outline1("LD A, $%2.2x", (unsigned char)((_destination>>8)&0xff));
        outline0("CP B");
        outline1("JP NZ, %s", label);
        outline1("LD A, $%2.2x", 0xff*_positive);
        outline1("LD (%s), A", _other);
        outline1("JMP %sb2", label);
        outhead1("%s:", label);
        outline1("LD A, $%2.2x", 0xff*(1-_positive));
        outline1("LD (%s), A", _other);
        outhead1("%sb2:", label);

    embedded( cpu_compare_16bit, src_hw_z80_cpu_compare_16bit_asm )

        outline1("LD HL, %s", _source);
        outline1("LD DE, $%4.4x", _destination);
        outline1("LD IX, $%4.4x", ( (0xff*_positive) << 8 ) | ( 0xff*(1-_positive)) );
        outline0("CALL CPUCOMPARE16CONST");
        outline1("LD (%s), A", _other);

    done( )

}

void cpu_compare_and_branch_16bit( Environment * _environment, char *_source, char *_destination,  char *_label, int _positive ) {

    inline( cpu_compare_and_branch_16bit )

        MAKE_LABEL

        outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
        outline0("LD B, A");
        outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
        outline0("CP B");
        outline1("JP NZ, %s", label);
        outline1("LD A, (%s)", _source);
        outline0("LD B, A");
        outline1("LD A, (%s)", _destination);
        outline0("CP B");
        outline1("JP NZ, %s", label);
        if ( _positive ) {
            outline1("JP %s", _label);
            outhead1("%s:", label );
        } else {
            outline1("JP %snot", label);
            outhead1("%s:", label );
            outline1("JP %s", _label);
            outhead1("%snot:", label );
        }

    no_embedded( cpu_compare_and_branch_16bit )

}

/**
 * @brief <i>Z80</i>: emit code to compare two 16 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void cpu_compare_and_branch_16bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

    inline( cpu_compare_and_branch_16bit_const )

        MAKE_LABEL

        outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
        outline1("CP $%2.2x", ( _destination >> 8 ) & 0xff );
        outline1("JP NZ, %s", label);
        outline1("LD A, (%s)", _source);
        outline1("CP $%2.2x", ( _destination & 0xff ) );
        outline1("JP NZ, %s", label);
        if ( _positive ) {
            outline1("JP %s", _label);
            outhead1("%s:", label );
        } else {
            outline1("JP %snot", label);
            outhead1("%s:", label );
            outline1("JP %s", _label);
            outhead1("%snot:", label );
        }

    no_embedded( cpu_compare_and_branch_16bit_const )

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
void cpu_less_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    inline( cpu_less_than_16bit )

        if ( _signed ) {

            outline1("LD HL, (%s)", _destination);
            outline1("LD DE, (%s)", _source);
            outline0("LD A, H" );
            outline0("XOR D" );
            outline1("JP M,%scmpgte2", label );
            outline0("SBC HL, DE" );
            if ( _equal ) {
                outline1("JR Z,%scmpgte3", label );
            } else {
                outline1("JR Z,%scmpgte1", label );
            }
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

            outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
            outline0("LD B, A");
            outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
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

    embedded( cpu_less_than_16bit, src_hw_z80_cpu_less_than_16bit_asm );

        if ( _signed ) {

            outline1("LD HL, (%s)", _destination);
            outline1("LD DE, (%s)", _source);
            if ( _equal ) {
                outline0("CALL CPULTE16S");
            } else {
                outline0("CALL CPULT16S");
            }
            if ( _other ) {
                outline1("LD (%s), A", _other);
            } else {
                outline1("LD (%s), A", _destination);
            }

        } else {

            outline1("LD HL, (%s)", _destination);
            outline1("LD DE, (%s)", _source);
            if ( _equal ) {
                outline0("CALL CPULTE16U");
            } else {
                outline0("CALL CPULT16U");
            }
            if ( _other ) {
                outline1("LD (%s), A", _other);
            } else {
                outline1("LD (%s), A", _destination);
            }

        }

    done(  )

}

void cpu_less_than_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    inline( cpu_less_than_16bit )

        if ( _signed ) {

            outline1("LD HL, $%4.4x", ( _destination & 0xffff ) );
            outline1("LD DE, (%s)", _source);
            outline0("LD A, H" );
            outline0("XOR D" );
            outline1("JP M,%scmpgte2", label );
            outline0("SBC HL, DE" );
            if ( _equal ) {
                outline1("JR Z,%scmpgte3", label );
            } else {
                outline1("JR Z,%scmpgte1", label );
            }        
            outline1("JR NC,%scmpgte3", label );
            outhead1("%scmpgte1:", label ); 
            outline0("LD A, 0");
            outline1("LD (%s), A", _other);
            outline1("JMP %send", label );
            outhead1("%scmpgte2:", label ); 
            outline0("BIT 7,D" );
            outline1("JR Z, %scmpgte1", label );
            outhead1("%scmpgte3:", label ); 
            outline0("LD A, $ff");
            outline1("LD (%s), A", _other);
            outhead1("%send:", label ); 
            
        } else {

            outline1("LD A, $%2.2x", ( ( _destination >> 8 ) & 0xff ) );
            outline0("LD B, A");
            outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
            outline0("CP B");
            outline1("JR Z, %sl2", label);
            outline1("JR C, %s", label);
            outline1("JR %s_0", label);
            outhead1("%sl2:", label);
            outline1("LD A, $%2.2x", ( _destination & 0xff ) );
            outline0("LD B, A");
            outline1("LD A, (%s)", _source);
            outline0("CP B");
            outline1("JR C, %s", label);
            if ( _equal ) {
                outline1("JR Z, %s", label);
            }
            outhead1("%s_0:", label);
            outline0("LD A, 0");
            outline1("LD (%s), A", _other);
            outline1("JMP %sb2", label);
            outhead1("%s:", label);
            outline0("LD A, $ff");
            outline1("LD (%s), A", _other);
            outhead1("%sb2:", label);

        }

    embedded( cpu_less_than_16bit, src_hw_z80_cpu_less_than_16bit_asm );

        if ( _signed ) {

            outline1("LD HL, $%4.4x", ( _destination & 0Xffff ) );
            outline1("LD DE, (%s)", _source);
            if ( _equal ) {
                outline0("CALL CPULTE16S");
            } else {
                outline0("CALL CPULT16S");
            }
            outline1("LD (%s), A", _other);

        } else {

            outline1("LD HL, $%4.4x", ( _destination & 0Xffff ) );
            outline1("LD DE, (%s)", _source);
            if ( _equal ) {
                outline0("CALL CPULTE16U");
            } else {
                outline0("CALL CPULT16U");
            }
            outline1("LD (%s), A", _other);

        }

    done(  )

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
void cpu_greater_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    cpu_less_than_16bit( _environment, _source, _destination, _other, !_equal, _signed );
    if ( _other ) {
        cpu_not_8bit( _environment, _other, _other );
    } else {
        cpu_not_8bit( _environment, _destination, _destination );
    }

}

void cpu_greater_than_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    cpu_less_than_16bit_const( _environment, _source, _destination, _other, !_equal, _signed );
    cpu_not_8bit( _environment, _other, _other );

}

/**
 * @brief <i>Z80</i>: emit code to add two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add (memory)
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu_math_add_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_add_16bit )

        outline1("LD HL, (%s)", _source );
        outline1("LD DE, (%s)", _destination );
        outline0("ADD HL, DE" );
        if ( _other ) {
            outline1("LD (%s), HL", _other );
        } else {
            outline1("LD (%s), HL", _destination );
        }

    no_embedded( cpu_math_add_16bit )

}

void cpu_math_add_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

    inline( cpu_math_add_16bit )

        outline1("LD HL, (%s)", _source );
        outline1("LD DE, $%4.4x", ( _destination & 0xffff ) );
        outline0("ADD HL, DE" );
        outline1("LD (%s), HL", _other );

    no_embedded( cpu_math_add_16bit )

}

void cpu_math_add_16bit_with_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_add_16bit_with_16bit )

        outline0("AND $0");
        outline1("LD HL, (%s)", _source );
        outline1("LD DE, %s", _destination );
        outline0("ADD HL, DE" );
        outline1("LD (%s), HL", _other );

    no_embedded( cpu_math_add_16bit_with_16bit )

}

/**
 * @brief <i>Z80</i>: emit code to double a 16 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu_math_double_16bit( Environment * _environment, char *_source, char *_other, int _signed ) {
    
    inline( cpu_math_double_16bit )

        outline1("LD DE, (%s)", _source );
        outline0("SLA E" );
        outline0("RL D" );
        if ( _other ) {
            outline1("LD (%s), DE", _other );
        } else {
            outline1("LD (%s), DE", _source );
        }

    no_embedded( cpu_math_double_16bit )

}

/**
 * @brief <i>Z80</i>: emit code to multiply two 16 bit values in a 32 bit register
 * 
 * @param _environment Current calling environment
 * @param _source First value to multipy (16 bit)
 * @param _destination Second value to multipy (16 bit)
 * @param _other Destination address for result (32 bit)
 */
void cpu_math_mul_16bit_to_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _signed ) {

    MAKE_LABEL

    inline( cpu_math_mul_16bit_to_32bit )

        if ( _signed ) {

            outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
            outline0("AND $80");
            outline0("LD B, A");
            outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
            outline0("AND $80");
            outline0("XOR A, B");
            outline0("PUSH AF");

            outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
            outline0("AND $80");
            outline0("PUSH AF");
            outline0("CP 0");
            outline1("JR Z,%spositive", label);
            cpu_complement2_16bit( _environment, _source, NULL );
            outhead1("%spositive:", label);

            outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
            outline0("AND $80");
            outline0("PUSH AF");
            outline0("CP 0");
            outline1("JR Z,%spositive2", label);
            cpu_complement2_16bit( _environment, _destination, NULL );
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
            outline1("LD (%s), BC", address_displacement( _environment, _other, "2" ) );

            outline0("POP AF" );
            outline1("JR Z, %srepositive", label );
            cpu_complement2_16bit( _environment, _destination, NULL );
            outhead1("%srepositive:", label);

            outline0("POP AF" );
            outline1("JR Z, %srepositive2", label );
            cpu_complement2_16bit( _environment, _source, NULL );
            outhead1("%srepositive2:", label);

            outline0("POP AF" );
            outline1("JR Z, %srepositive3", label );
            cpu_complement2_32bit( _environment, _other, NULL );
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
            outline1("LD (%s), BC", address_displacement( _environment, _other, "2" ) );

        }

    embedded( cpu_math_mul_16bit_to_32bit, src_hw_z80_cpu_math_mul_16bit_to_32bit_asm );

        if ( _signed ) {

            outline1("LD IX, (%s)", _source );
            outline1("LD IY, (%s)", _destination );
            outline0("CALL CPUMUL16B16T32S")
            outline1("LD (%s), HL", _other );
            outline1("LD (%s), BC", address_displacement( _environment, _other, "2" ) );

        } else {

            outline1("LD BC, (%s)", _source );
            outline1("LD DE, (%s)", _destination );
            outline0("CALL CPUMUL16B16T32U")
            outline1("LD (%s), HL", _other );
            outline1("LD (%s), BC", address_displacement( _environment, _other, "2" ) );

        }

    done(  )

}

void cpu_math_mul_nbit_to_nbit( Environment * _environment, char *_source, char *_destination,  char *_other, int _bits ) {

    MAKE_LABEL

    int i;

    char afterLabel[MAX_TEMPORARY_STORAGE]; sprintf( afterLabel, "%safter", label);
    char destination[MAX_TEMPORARY_STORAGE]; sprintf( destination, "CPUMATHMULNBITTONBIT%d_DESTINATION", (_bits>>3));
    char source[MAX_TEMPORARY_STORAGE]; sprintf( source, "CPUMATHMULNBITTONBIT%d_SOURCE", (_bits>>3));
    char other[MAX_TEMPORARY_STORAGE]; sprintf( other, "CPUMATHMULNBITTONBIT%d_OTHER", (_bits>>3));

    // no_inline( cpu_math_mul_nbit_to_nbit )

    // embedded( cpu_math_mul_nbit_to_nbit, src_hw_6502_cpu_math_mul_nbit_to_nbit_asm )

    if ( ! _environment->cpuOptimization.cpu_math_mul_nbit_to_nbit[_bits>>3] ) {

        outline1("JP %s", afterLabel );

        outhead2("CPUMATHMULNBITTONBIT%d_SOURCE: defs %d", _bits>>3, _bits>>3 );
        outhead2("CPUMATHMULNBITTONBIT%d_DESTINATION: defs %d", _bits>>3, _bits>>3 );
        outhead2("CPUMATHMULNBITTONBIT%d_OTHER: defs %d", _bits>>3, _bits>>3 );

        outhead1("CPUMATHMULNBITTONBIT%d:", _bits>>3);
        outhead0("LD A, $00");
        for( i=0; i<(_bits>>3); ++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
            outline1("LD (%s), A", address_displacement( _environment, other, offset ) );
        }
        outline1("LD C, $%2.2x", _bits );

        outhead1("CPUMATHMULNBITTONBIT%dL1:", _bits>>3);

        // The process of multiplying binary numbers is similar and easier to do than
        // decimal multiplication as binary numbers consist of only two digits which 
        // are 0 and 1. The method of multiplying binary numbers is given below. The 
        // same set of rules also apply to binary numbers with a decimal point. Let 
        // us take the example of multiplying (11101) and (1001). 
        // 
        // The decimal equivalent of (11101) is 29 and the decimal equivalent 
        // of (1001) is 9. Now let us multiply these numbers.

        // Step 1: Write down the multiplicand (11101) and the multiplier (1001)
        // one below the other in proper positions.

        char multiplyByBit0Label[MAX_TEMPORARY_STORAGE]; sprintf( multiplyByBit0Label, "%sb%dbit0", label, _bits>>3 );

        char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", (_bits>>3)-1 );

        outline1("LD A, (%s)", address_displacement( _environment, destination, offset ) );
        outline0("SRA A" );
        outline1("LD (%s), A", address_displacement( _environment, destination, offset ) );
        for( i=(_bits>>3)-2; i>-1; --i ) {
            sprintf( offset, "%d", i );
            outline1("LD A, (%s)", address_displacement( _environment, destination, offset ) );
            outline0("RR A" );
            outline1("LD (%s), A", address_displacement( _environment, destination, offset ) );
        }
        outline1("JR C, %sx", multiplyByBit0Label );
        outline1("JP %s", multiplyByBit0Label );
        outhead1("%sx:", multiplyByBit0Label );

        // Step 2: Multiply the rightmost digit or the least significant bit (LSB) 
        // of the multiplier (1) with all the digits of the multiplicand (11101).

        outline0("SCF" );
        outline0("CCF" );
        for( i=0; i<(_bits>>3); ++i ) {
            sprintf( offset, "%d", i );
            outline1("LD A, (%s)", address_displacement( _environment, source, offset ) );
            outline0("LD B, A" );
            outline1("LD A, (%s)", address_displacement( _environment, other, offset ) );
            outline0("ADC A, B" );
            outline1("LD (%s), A", address_displacement( _environment, other, offset ) );
        }

        // Step 3: Add a place holder of '0' or 'X' before multiplying the next 
        // higher order digit of the multiplier& with the multiplicand.

        outhead1("%s:", multiplyByBit0Label);

        outline0("SCF" );
        outline0("CCF" );
        outline1("LD A, (%s)", address_displacement( _environment, source, "0" ) );
        outline0("SLA A" );
        outline1("LD (%s), A", address_displacement( _environment, source, "0" ) );
        for( i=1; i<(_bits>>3); ++i ) {
            sprintf( offset, "%d", i );
            outline1("LD A, (%s)", address_displacement( _environment, source, offset ) );
            outline0("RL A" );
            outline1("LD (%s), A", address_displacement( _environment, source, offset ) );
        }

        // Step 4: Repeat the same process for all the next higher-order digits 
        // until we reach the most significant bit (MSB) which is the left-most 
        // digit of the multiplicand with the multiplier.

        outline0("DEC C" );
        outline0("LD A, C" );
        outline0("CP 0" );
        outline1("JP NZ, CPUMATHMULNBITTONBIT%dL1", (_bits>>3) );

        outline0("RET" );

        // Step 5: The product obtained in each row is called the partial product. 
        // Finally, add all the partial products. To add all the binary numbers 
        // use the rules of binary addition.

        // (The rules for binary addition are listed as follows: 0 + 0 = 0, 0 + 1 = 1, and 1 + 1 = 0, with a carryover of 1. So, 1 + 1 = 10 and 1 + 1 + 1 = 11 in the binary number system)
        outhead1("%s:", afterLabel );

    }

    for( i=0; i<(_bits>>3); ++i ) {
        char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
        outline1("LD A, (%s)", address_displacement( _environment, _source, offset ) );
        outline1("LD (%s), A", address_displacement( _environment, source, offset ) );
        outline1("LD A, (%s)", address_displacement( _environment, _destination, offset ) );
        outline1("LD (%s), A", address_displacement( _environment, destination, offset ) );
    }
    outline1("CALL CPUMATHMULNBITTONBIT%d", _bits >> 3 );
    for( i=0; i<(_bits>>3); ++i ) {
        char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
        outline1("LD A, (%s)", address_displacement( _environment, other, offset ) );
        if ( _other ) {
            outline1("LD (%s), A", address_displacement( _environment, _other, offset ) );
        } else {
            outline1("LD (%s), A", address_displacement( _environment, _destination, offset ) );
        }
    }

    // done()

}

void cpu_math_mul2_const_nbit( Environment * _environment, char *_source, int _steps, int _bits ) {

    int i;

    inline( cpu_math_mul2_const_nbit )

        char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", (_bits>>3)-1 );
        outline1("LD A, (%s)", address_displacement(_environment, _source, offset));
        outline0("AND $80");
        outline0("LD B, A");
        while( _steps ) {
            outline0("SCF")
            outline0("CCF");
            outline1("LD A, (%s)", address_displacement(_environment, _source, "0"));
            outline0("SLA A");
            outline1("LD (%s), A", address_displacement(_environment, _source, "0"));
            for( i=1; i<(_bits>>3); ++i ) {
                char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i);
                outline1("LD A, (%s)", address_displacement(_environment, _source, offset));
                outline0("RL A");
                outline1("LD (%s), A", address_displacement(_environment, _source, offset));
            }
            --_steps;
        }
        outline1("LD A, (%s)", address_displacement(_environment, _source, offset));
        outline0("OR B");
        outline1("LD (%s), A", address_displacement(_environment, _source, offset));

    no_embedded( cpu_math_mul2_const_nbit )

}

/**
 * @brief <i>Z80</i>: emit code to subtract two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to subtract
 * @param _destination Second value to subtract and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu_math_sub_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_sub_16bit )

        outline1("LD HL, (%s)", _source );
        outline1("LD DE, (%s)", _destination );
        outline0("AND A" );
        outline0("SBC HL, DE" );
        if ( _other ) {
            outline1("LD (%s), HL", _other );
        } else {
            outline1("LD (%s), HL", _destination );
        }

    no_embedded( cpu_math_sub_16bit )

}

/**
 * @brief <i>Z80</i>: emit code to calculate a 16 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void cpu_math_complement_const_16bit( Environment * _environment, char *_source, int _value ) {

    inline( cpu_math_complement_const_16bit )

        outline1("LD HL, $%4.4x", _value );
        outline1("LD DE, (%s)", _source );
        outline0("LD A, E" );
        outline0("XOR $FF" );
        outline0("LD E, A" );
        outline0("LD A, D" );
        outline0("XOR $FF" );
        outline0("LD D, A" );
        outline0("INC DE" );
        outline0("ADD HL, DE" );
        outline1("LD (%s), HL", _source );

    no_embedded( cpu_math_complement_const_16bit )

}

/**
 * @brief <i>Z80</i>: emit code to halves for several times a 16 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu_math_div2_const_16bit( Environment * _environment, char *_source, int _steps, int _signed, char * _remainder ) {

    inline( cpu_math_div2_const_16bit )

        MAKE_LABEL

        if ( _remainder ) {
            outline1("LD A, (%s)", _source );
            outline0("AND $1" );
            outline1("LD (%s), A", _remainder );
        }
        if ( _signed ) {
            outline1("LD A, (%s)", address_displacement(_environment, _source, "1") );
            outline0("AND $80" );
            outline0("CP 0" );
            outline0("PUSH AF" );
            outline1("JR Z, %spos", label );
            cpu_complement2_16bit( _environment, _source, _source );
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
            outline0("CP 0" );
            outline1("JR Z, %sdone", label );
            cpu_complement2_16bit( _environment, _source, _source );
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

    embedded( cpu_math_div2_const_16bit, src_hw_z80_cpu_math_div2_const_16bit_asm )

        if ( _remainder ) {
            outline1("LD A, (%s)", _source );
            outline0("AND $1" );
            outline1("LD (%s), A", _remainder );
        }
        if ( _signed ) {
            if ( _steps ) {
                outline1("LD HL, (%s)", _source );
                outline1("LD A, $%2.2x", _steps );
                outline0("LD C, A" );
                outline0("CALL CPUDIV2CONST16S" );
                outline1("LD (%s), HL", _source );
            }
        } else {
            if ( _steps ) {
                outline1("LD HL, (%s)", _source );
                outline1("LD A, $%2.2x", _steps );
                outline0("LD C, A" );
                outline0("CALL CPUDIV2CONST16U" );
                outline1("LD (%s), HL", _source );
            }
            
        }

    done( )

}

/**
 * @brief <i>Z80</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu_math_mul2_const_16bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    inline( cpu_math_mul2_const_16bit )

        MAKE_LABEL

        if ( _signed ) {
            outline1("LD A, (%s)", address_displacement(_environment, _source, "1") );
            outline0("AND $80" );
            outline0("PUSH AF" );
            outline0("CP 0" );
            outline1("JR Z, %spos", label );
            cpu_complement2_16bit( _environment, _source, _source );
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
            outline0("CP 0" );
            outline1("JR Z, %sdone", label );
            cpu_complement2_16bit( _environment, _source, _source );
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

    no_embedded( cpu_math_mul2_const_16bit )

}

/**
 * @brief <i>Z80</i>: emit code to mask with "and" a value of 16 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void cpu_math_and_const_16bit( Environment * _environment, char *_source, int _mask ) {

    inline( cpu_math_and_const_16bit )

        outline1("LD A, (%s)", _source );
        outline1("AND $%2.2x", ( _mask & 0xff ) );
        outline1("LD (%s), A", _source );
        outline1("LD A, (%s)", address_displacement(_environment, _source, "1") );
        outline1("AND $%2.2x", ( ( _mask >> 8 ) & 0xff ) );
        outline1("LD (%s), A", address_displacement(_environment, _source, "1") );

    no_embedded( cpu_math_and_const_16bit )

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
void cpu_move_32bit( Environment * _environment, char *_source, char *_destination ) {

    inline( cpu_move_32bit )

        outline1("LD A, (%s)", _source );
        outline1("LD (%s), A", _destination );
        outline1("LD A, (%s)", address_displacement(_environment, _source, "1") );
        outline1("LD (%s), A", address_displacement(_environment, _destination, "1") );
        outline1("LD A, (%s)", address_displacement(_environment, _source, "2") );
        outline1("LD (%s), A", address_displacement(_environment, _destination, "2") );
        outline1("LD A, (%s)", address_displacement(_environment, _source, "3") );
        outline1("LD (%s), A", address_displacement(_environment, _destination, "3") );

    no_embedded( cpu_move_32bit )

}

/**
 * @brief <i>Z80</i>: emit code to store 32 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void cpu_store_32bit( Environment * _environment, char *_destination, int _value ) {

    inline( cpu_store_32bit )

        outline1("LD HL, $%4.4x", ( _value & 0xffff ) );
        outline1("LD (%s), HL", _destination );
        outline1("LD HL, $%4.4x", ( ( _value >> 16 ) & 0xffff ) );
        outline1("LD (%s), HL", address_displacement(_environment, _destination, "2") );

    no_embedded( cpu_move_32bit )

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
void cpu_compare_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

    inline( cpu_compare_32bit )

        MAKE_LABEL

        outline1("LD A, (%s)", _source);
        outline0("LD B, A");
        outline1("LD A, (%s)", _destination);
        outline0("CP B");
        outline1("JP NZ, %s", label);
        outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
        outline0("LD B, A");
        outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
        outline0("CP B");
        outline1("JP NZ, %s", label);
        outline1("LD A, (%s)", address_displacement(_environment, _source, "2"));
        outline0("LD B, A");
        outline1("LD A, (%s)", address_displacement(_environment, _destination, "2"));
        outline0("CP B");
        outline1("JP NZ, %s", label);
        outline1("LD A, (%s)", address_displacement(_environment, _source, "3"));
        outline0("LD B, A");
        outline1("LD A, (%s)", address_displacement(_environment, _destination, "3"));
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

    embedded( cpu_compare_32bit, src_hw_z80_cpu_compare_32bit_asm )

        outline1("LD HL, %s", _source);
        outline1("LD DE, %s", _destination);
        outline1("LD IX, $%4.4x", ( (0xff*_positive) << 8 ) | ( 0xff*(1-_positive)) );
        outline0("CALL CPUCOMPARE32");
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline1("LD (%s), A", _destination);
        }

    done( )
    
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
void cpu_compare_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _positive ) {

    inline( cpu_compare_32bit )

        MAKE_LABEL

        outline1("LD A, (%s)", _source);
        outline0("LD B, A");
        outline1("LD A, $%2.2x", (unsigned char)(_destination & 0xff));
        outline0("CP B");
        outline1("JP NZ, %s", label);
        outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
        outline0("LD B, A");
        outline1("LD A, $%2.2x", (unsigned char)((_destination>>8) & 0xff));
        outline0("CP B");
        outline1("JP NZ, %s", label);
        outline1("LD A, (%s)", address_displacement(_environment, _source, "2"));
        outline0("LD B, A");
        outline1("LD A, $%2.2x", (unsigned char)((_destination>>16) & 0xff));
        outline0("CP B");
        outline1("JP NZ, %s", label);
        outline1("LD A, (%s)", address_displacement(_environment, _source, "3"));
        outline0("LD B, A");
        outline1("LD A, $%2.2x", (unsigned char)((_destination>>24) & 0xff));
        outline0("CP B");
        outline1("JP NZ, %s", label);
        outline1("LD A, $%2.2x", 0xff*_positive);
        outline1("LD (%s), A", _other);
        outline1("JMP %s_2", label);
        outhead1("%s:", label);
        outline1("LD A, $%2.2x", 0xff*(1-_positive));
        outline1("LD (%s), A", _other);
        outhead1("%s_2:", label);

    embedded( cpu_compare_32bit, src_hw_z80_cpu_compare_32bit_asm )

        outline1("LD HL, %s", _source);
        outline1("LD DE, $%4.4x", (unsigned int)(_destination&0xffff));
        outline1("LD IY, $%4.4x", (unsigned int)((_destination>>16)&0xffff));
        outline1("LD IX, $%4.4x", ( (0xff*_positive) << 8 ) | ( 0xff*(1-_positive)) );
        outline0("CALL CPUCOMPARE32CONST");
        outline1("LD (%s), A", _other);

    done( )
    
}

/**
 * @brief <i>Z80</i>: emit code to compare two 32 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void cpu_compare_and_branch_32bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

    inline( cpu_compare_and_branch_32bit_const )

        MAKE_LABEL

        outline1("LD A, (%s)", address_displacement(_environment, _source, "3"));
        outline1("CP $%2.2x", ( _destination >> 24 ) & 0xff );
        outline1("JP NZ, %s", label);
        outline1("LD A, (%s)", address_displacement(_environment, _source, "2"));
        outline1("CP $%2.2x", ( _destination >> 16 ) & 0xff );
        outline1("JP NZ, %s", label);
        outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
        outline1("CP $%2.2x", ( _destination >> 8 ) & 0xff );
        outline1("JP NZ, %s", label);
        outline1("LD A, (%s)", _source);
        outline1("CP $%2.2x", ( _destination & 0xff ) );
        outline1("JP NZ, %s", label);

        if ( _positive ) {
            outline1("JP %s", _label);
            outhead1("%s:", label );
        } else {
            outline1("JP %snot", label);
            outhead1("%s:", label );
            outline1("JP %s", _label);
            outhead1("%snot:", label );
        }

    no_embedded( cpu_compare_and_branch_32bit_const )

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
void cpu_less_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    inline( cpu_less_than_32bit )

        if ( _signed ) {

            outline1("LD IX, %s", _source);
            outline1("LD IY, %s", _destination);
            outline0("LD B, (IX+3)");
            outline0("LD A, B");
            outline0("AND $80");
            outline0("CP 0" );
            outline1("JR NZ,%sNEGM1", label);
            outline0("BIT 7, (IY+3)");
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

            outline1("LD A, (%s)", address_displacement(_environment, _source, "3"));
            outline0("LD B, A");
            outline1("LD A, (%s)", address_displacement(_environment, _destination, "3"));
            outline0("CP B");
            outline1("JR Z, %s_2", label);
            outline1("JR C, %s", label);
            outline1("JR %s_ok", label);
            outhead1("%s_2:", label);
            outline1("LD A, (%s)", address_displacement(_environment, _source, "2"));
            outline0("LD B, A");
            outline1("LD A, (%s)", address_displacement(_environment, _destination, "2"));
            outline0("CP B");
            outline1("JR Z, %s_1", label);
            outline1("JR C, %s", label);
            outline1("JR %s_ok", label);
            outhead1("%s_1:", label);
            outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
            outline0("LD B, A");
            outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
            outline0("CP B");
            outline1("JR Z, %s_0", label);
            outline1("JR C, %s", label);
            outline1("JR %s_ok", label);
            outhead1("%s_0:", label);
            outline1("LD A, (%s)", _source);
            outline0("LD B, A");
            outline1("LD A, (%s)", _destination);
            outline0("CP B");
            if ( _equal ) {
                outline1("JR Z, %s_ok", label);
            } else {
                outline1("JR Z, %s", label);
            }
            outline1("JR C, %s", label);
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

    embedded( cpu_less_than_32bit, src_hw_z80_cpu_less_than_32bit_asm );

        if ( _signed ) {

            outline1("LD IY, %s", _destination);
            outline1("LD IX, %s", _source);
            if ( _equal ) {
                outline0("CALL CPULTE32S");
            } else {
                outline0("CALL CPULT32S");
            }
            if ( _other ) {
                outline1("LD (%s), A", _other);
            } else {
                outline1("LD (%s), A", _destination);
            }

        } else {

            outline1("LD IY, %s", _destination);
            outline1("LD IX, %s", _source);
            if ( _equal ) {
                outline0("CALL CPULTE32U");
            } else {
                outline0("CALL CPULT32U");
            }
            if ( _other ) {
                outline1("LD (%s), A", _other);
            } else {
                outline1("LD (%s), A", _destination);
            }

        }

    done(  )


}

void cpu_less_than_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    inline( cpu_less_than_32bit )

        if ( _signed ) {

            // outline1("LD IX, %s", _source);
            // outline1("LD IY, %s", _destination);
            // outline0("LD B, (IX+3)");
            // outline0("LD A, B");
            // outline0("AND $80");
            // outline1("JR NZ,%sNEGM1", label);
            // outline0("BIT 7, (IY+3)");
            // outline1("JR NZ,%sdone", label);
            // outline0("LD A, B");
            // outline0("CP (IY+3)");
            // outline1("JR NZ,%sdone", label);
            // outline0("LD A, (IX+2)");
            // outline0("CP (IY+2)");
            // outline1("JR NZ,%sdone", label);
            // outline0("LD A, (IX+1)");
            // outline0("CP (IY+1)");
            // outline1("JR NZ,%sdone", label);
            // outline0("LD A, (IX)");
            // outline0("CP (IY)");
            // outline1("JMP %sdone", label);
            // outhead1("%sNEGM1:", label);
            // outline0("XOR (IY+3)");
            // outline0("RLA");
            // outline1("JR C,%sdone", label);
            // outline0("LD A, B");
            // outline0("CP (IY+3)");
            // outline1("JR NZ,%sdone", label);
            // outline0("LD A, (IX+2)");
            // outline0("CP (IY+2)");
            // outline1("JR NZ,%sdone", label);
            // outline0("LD A, (IX+1)");
            // outline0("CP (IY+1)");
            // outline1("JR NZ,%sdone", label);
            // outline0("LD A, (IX)");
            // outline0("CP (IY)");
            // outline1("JMP %sdone", label);
            // outhead1("%sdone:", label);
            // if ( _equal ) {
            //     outline1("JR Z,%smi", label);
            // }
            // outline1("JR C,%smi", label);
            // outhead1("%spl:", label);
            // outline0("LD A, 0");
            // if ( _other ) {
            //     outline1("LD (%s), A", _other);
            // } else {
            //     outline1("LD (%s), A", _destination);
            // }
            // outline1("JMP %sdone2", label);
            // outhead1("%smi:", label);
            // outline0("LD A, $ff");
            // if ( _other ) {
            //     outline1("LD (%s), A", _other);
            // } else {
            //     outline1("LD (%s), A", _destination);
            // }
            // outline1("JMP %sdone2", label);
            // outhead1("%sdone2:", label);

        } else {

            outline1("LD A, (%s)", address_displacement(_environment, _source, "3"));
            outline0("LD B, A");
            outline1("LD A, $%2.2x", ( ( _destination >> 24 ) && 0xff ) );
            outline0("CP B");
            outline1("JR Z, %s_2", label);
            outline1("JR C, %s", label);
            outline1("JR %s_ok", label);
            outhead1("%s_2:", label);
            outline1("LD A, (%s)", address_displacement(_environment, _source, "2"));
            outline0("LD B, A");
            outline1("LD A, $%2.2x", ( ( _destination >> 16 ) && 0xff ) );
            outline0("CP B");
            outline1("JR Z, %s_1", label);
            outline1("JR C, %s", label);
            outline1("JR %s_ok", label);
            outhead1("%s_1:", label);
            outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
            outline0("LD B, A");
            outline1("LD A, $%2.2x", ( ( _destination >> 8 ) && 0xff ) );
            outline0("CP B");
            outline1("JR Z, %s_0", label);
            outline1("JR C, %s", label);
            outline1("JR %s_ok", label);
            outhead1("%s_0:", label);
            outline1("LD A, (%s)", _source);
            outline0("LD B, A");
            outline1("LD A, $%2.2x", ( _destination && 0xff ) );
            outline0("CP B");
            outline1("JR C, %s", label);
            if ( _equal ) {
                outline1("JR Z, %s", label);
            }
            outhead1("%s_ok:", label);
            outline0("LD A, $ff");
            outline1("LD (%s), A", _other);
            outline1("JMP %s_xx", label);
            outhead1("%s:", label);
            outline0("LD A, $0");
            outline1("LD (%s), A", _other);
            outhead1("%s_xx:", label);

        }

    embedded( cpu_less_than_32bit, src_hw_z80_cpu_less_than_32bit_asm );

        if ( _signed ) {

            outline1("LD DE, $%4.4x", ( ( _destination >> 16 ) & 0xffff ) );
            outline0("PUSH DE" );
            outline1("LD DE, $%4.4x", ( _destination & 0xffff ) );
            outline0("PUSH DE" );
            outline0("LD DE, SP" );
            outline0("LD IY, DE" );
            outline1("LD IX, %s", _source);
            if ( _equal ) {
                outline0("CALL CPULTE32S");
            } else {
                outline0("CALL CPULT32S");
            }
            outline1("LD (%s), A", _other);
            outline0("POP DE" );
            outline0("POP DE" );

        } else {

            outline1("LD DE, $%4.4x", ( ( _destination >> 16 ) & 0xffff ) );
            outline0("PUSH DE" );
            outline1("LD DE, $%4.4x", ( _destination & 0xffff ) );
            outline0("PUSH DE" );
            outline0("LD DE, SP" );
            outline0("LD IY, DE" );
            outline1("LD IX, %s", _source);
            if ( _equal ) {
                outline0("CALL CPULTE32U");
            } else {
                outline0("CALL CPULT32U");
            }
            outline1("LD (%s), A", _other);
            outline0("POP DE" );
            outline0("POP DE" );
            
        }

    done(  )

}

void cpu_less_than_nbit( Environment * _environment, char *_source, char * _destination,  char *_other, int _equal, int _bits ) {

    MAKE_LABEL

    int i;

    inline( cpu_less_than_nbit )

        if ( _equal ) {

            cpu_compare_nbit( _environment, _source, _destination, _other, 1, _bits );

            if ( _other ) {
                outline1("LD A, (%s)", _other);
            } else {
                outline1("LD A, (%s)", _destination);
            }

            outline0("CP 0" );
            outline1("JR Z, %sless", label );
            outline1("JP %sdone", label );
            outhead1("%sless:", label );

        }

        for( i=(_bits>>3)-1; i>-1; --i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf(offset, "%d", i );
            outline1("LD A, (%s)", address_displacement(_environment, _destination, offset ) );
            outline0("LD B, A");
            outline1("LD A, (%s)", address_displacement(_environment, _source, offset ) );
            outline0("CP B");
            outline2("JR Z, %snext%dx", label, i );
            outline1("JP C, %sbga", label );
            outline1("JP %sagb", label );
            outhead2("%snext%dx:", label, i );
        }

        outhead1("%sbga:", label );
        outline0("LD A, 0xff" );
        outline1("LD (%s), A", _other );
        outline1("JR %sdone", label );

        outhead1("%sagb:", label );
        outline0("LD A, 0x00" );
        outline1("LD (%s), A", _other );
        outline1("JR %sdone", label );

        outhead1("%sdone:", label );

    no_embedded( cpu_less_than_nbit_const )

}

void cpu_less_than_nbit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _bits ) {

    MAKE_LABEL

    int i;

    inline( cpu_less_than_nbit_const )

        if ( _equal ) {

            cpu_compare_nbit_const( _environment, _source, _destination, _other, 1, _bits );

            outline1("LD A, (%s)", _other);
            outline0("CP 0" );
            outline1("JR Z, %sless", label );
            outline1("JP %sdone", label );
            outhead1("%sless:", label );

        }

        for( i=(_bits>>3)-2; i>-1; --i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf(offset, "%d", i );
            outline1("LD B, $%2.2x", (unsigned char)((_destination>>(i*8))&0xff) );
            outline1("LD A, (%s)", address_displacement(_environment, _source, offset ) );
            outline0("CP B");
            outline2("JR Z, %snext%dx", label, i );
            outline1("JP C, %sbga", label );
            outline1("JP %sagb", label );
            outhead2("%snext%dx:", label, i );
        }

        outhead1("%sbga:", label );
        outline0("LD A, 0xff" );
        outline1("LD (%s), A", _other );
        outline1("JR %sdone", label );

        outhead1("%sagb:", label );
        outline0("LD A, 0x00" );
        outline1("LD (%s), A", _other );
        outline1("JR %sdone", label );

        outhead1("%sdone:", label );

    no_embedded( cpu_less_than_nbit_const )

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
void cpu_greater_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    cpu_less_than_32bit( _environment, _source, _destination, _other, !_equal, _signed );
    if ( _other ) {
        cpu_not_8bit( _environment, _other, _other );
    } else {
        cpu_not_8bit( _environment, _destination, _destination );
    }

}

void cpu_greater_than_nbit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _bits ) {

    inline( cpu_greater_than_nbit )

        cpu_less_than_nbit( _environment, _source, _destination, _other, !_equal, _bits );
        if ( _other ) {
            cpu_not_8bit( _environment, _other, _other );
        } else {
            cpu_not_8bit( _environment, _destination, _destination );
        }

    no_embedded( cpu_greater_than_nbit )

}

void cpu_greater_than_nbit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _bits ) {

    inline( cpu_greater_than_nbit )

        cpu_less_than_nbit_const( _environment, _source, _destination, _other, !_equal, _bits );
        cpu_not_8bit( _environment, _other, _other );

    no_embedded( cpu_greater_than_nbit )

}

void cpu_greater_than_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    cpu_less_than_32bit_const( _environment, _source, _destination, _other, !_equal, _signed );
    cpu_not_8bit( _environment, _other, _other );

}

/**
 * @brief <i>Z80</i>: emit code to add two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu_math_add_32bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_add_32bit )

        outline1("LD HL, (%s)", _source );
        outline1("LD DE, (%s)", _destination );
        outline0("EXX" );
        outline1("LD HL, (%s)", address_displacement(_environment, _source, "2") );
        outline1("LD DE, (%s)", address_displacement(_environment, _destination, "2") );
        outline0("EXX" );
        outline0("ADD HL, DE" );
        outline0("EXX" );
        outline0("ADC HL, DE" );
        outline0("EXX" );
        if ( _other ) {
            outline1("LD (%s), HL", _other );
            outline0("EXX" );
            outline1("LD (%s), HL", address_displacement( _environment, _other, "2" ) );
        } else {
            outline1("LD (%s), HL", _destination );
            outline0("EXX" );
            outline1("LD (%s), HL", address_displacement( _environment, _destination, "2" ) );
        }

    no_embedded( cpu_math_add_32bit )

}

void cpu_math_add_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

    inline( cpu_math_add_32bit_const )

        outline1("LD HL, (%s)", _source );
        outline1("LD DE, $%4.4x", ( _destination & 0xffff ) );
        outline0("EXX" );
        outline1("LD HL, (%s)", address_displacement(_environment, _source, "2") );
        outline1("LD DE, $%4.4x", ( ( _destination >> 16 ) & 0xffff ) );
        outline0("EXX" );
        outline0("ADD HL, DE" );
        outline0("EXX" );
        outline0("ADC HL, DE" );
        outline0("EXX" );
        outline1("LD (%s), HL", _other );
        outline0("EXX" );
        outline1("LD (%s), HL", address_displacement( _environment, _other, "2" ) );

    no_embedded( cpu_math_add_32bit_const )

}

void cpu_math_add_nbit( Environment * _environment, char *_source, char *_destination,  char *_other, int _bits ) {

    inline( cpu_math_add_nbit )

        outline0("SCF");
        outline0("CCF");
        for( int i=0; i<(_bits>>3); ++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
            outline1("LD A, (%s)", address_displacement(_environment, _source, offset));
            outline0("LD B, A");
            outline1("LD A, (%s)", address_displacement(_environment, _destination, offset));
            outline0("ADC A, B");
            if ( _other ) {
                outline1("LD (%s), A", address_displacement(_environment, _other, offset));
            } else {
                outline1("LD (%s), A", address_displacement(_environment, _destination, offset));
            }
        }
    no_embedded( cpu_math_add_nbit )

}

/**
 * @brief <i>Z80</i>: emit code to double a 32 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 * @todo Not yet implemented
 */
void cpu_math_double_32bit( Environment * _environment, char *_source, char *_other, int _signed ) {

    inline( cpu_math_double_32bit )

        if ( _other ) {
            cpu_math_add_32bit( _environment, _source, _source, _other );
        } else {
            cpu_math_add_32bit( _environment, _source, _source, _source );
        }

    no_embedded( cpu_math_double_32bit )

}

/**
 * @brief <i>Z80</i>: emit code to subtract two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to subtract
 * @param _destination Second value to subtract and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu_math_sub_32bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_sub_32bit )

        MAKE_LABEL

        outline1("LD HL, (%s)", _source );
        outline1("LD DE, (%s)", _destination );
        outline0("LD A, E" );
        outline0("XOR $FF" );
        outline0("LD E, A" );
        outline0("LD A, D" );
        outline0("XOR $FF" );
        outline0("LD D, A" );
        outline0("INC DE" );
        outline0("LD A, D" );
        outline0("OR E" );
        outline0("PUSH AF" );
        outline0("EXX" );
        outline1("LD HL, (%s)", address_displacement(_environment, _source, "2") );
        outline1("LD DE, (%s)", address_displacement(_environment, _destination, "2") );
        outline0("LD A, E" );
        outline0("XOR $FF" );
        outline0("LD E, A" );
        outline0("LD A, D" );
        outline0("XOR $FF" );
        outline0("LD D, A" );
        outline0("POP AF" );
        outline0("CP 0" );
        outline1("JR NZ, %snoincde", label );
        outline0("INC DE" );
        outline1("%snoincde:", label );
        outline0("EXX" );
        outline0("ADD HL, DE" );
        outline0("EXX" );
        outline0("ADC HL, DE" );
        outline0("EXX" );
        if ( _other ) {
            outline1("LD (%s), HL", _other );
            outline0("EXX" );
            outline1("LD (%s), HL", address_displacement( _environment, _other, "2" ) );
        } else {
            outline1("LD (%s), HL", _destination );
            outline0("EXX" );
            outline1("LD (%s), HL", address_displacement( _environment, _destination, "2" ) );
        }

    no_embedded( cpu_math_sub_32bit )

}

void cpu_math_sub_nbit( Environment * _environment, char *_source, char *_destination,  char *_other, int _bits ) {

    inline( cpu_math_sub_nbit )

        outline0("SCF");
        outline0("CCF");
        for( int i=0; i<(_bits)>>3; ++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
            outline1("LD A, (%s)", address_displacement(_environment, _destination, offset));
            outline0("LD B, A");
            outline1("LD A, (%s)", address_displacement(_environment, _source, offset));
            outline0("SBC A, B");
            if ( _other ) {
                outline1("LD (%s), A", address_displacement(_environment, _other, offset));
            } else {
                outline1("LD (%s), A", address_displacement(_environment, _destination, offset));
            }
        }

    no_embedded( cpu_math_sub_nbit )

}

/**
 * @brief <i>Z80</i>: emit code to calculate a 32 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void cpu_math_complement_const_32bit( Environment * _environment, char *_source, int _value ) {

    inline( cpu_math_complement_const_32bit )

        outline1("LD HL, $%4.4x", ( _value & 0xffff ) );
        outline1("LD DE, (%s)", _source );
        outline0("LD A, E" );
        outline0("XOR $FF" );
        outline0("LD E, A" );
        outline0("LD A, D" );
        outline0("XOR $FF" );
        outline0("LD D, A" );
        outline0("INC DE" );
        outline0("EXX" );
        outline1("LD HL, $%4.4x", ( ( _value >> 16 ) & 0xffff ) );
        outline1("LD DE, (%s)", address_displacement(_environment, _source, "2") );
        outline0("LD A, E" );
        outline0("XOR $FF" );
        outline0("LD E, A" );
        outline0("LD A, D" );
        outline0("XOR $FF" );
        outline0("LD D, A" );
        outline0("INC DE" );
        outline0("EXX" );
        outline0("ADD HL, DE" );
        outline0("EXX" );
        outline0("ADC HL, DE" );
        outline0("EXX" );
        outline1("LD (%s), HL", _source );
        outline0("EXX" );
        outline1("LD (%s), HL", address_displacement( _environment, _source, "2" ) );

    no_embedded( cpu_math_complement_const_32bit )

}

/**
 * @brief <i>Z80</i>: emit code to halves for several times a 32 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu_math_div2_const_32bit( Environment * _environment, char *_source, int _steps, int _signed, char * _remainder ) {

    inline( cpu_math_div2_const_32bit )

        MAKE_LABEL

        if ( _remainder ) {
            outline1("LD A, (%s)", _source );
            outline0("AND $1" );
            outline1("LD (%s), A", _remainder );
        }
        if ( _signed ) {
            outline1("LD A, (%s)", address_displacement(_environment, _source, "3") );
            outline0("AND $80" );
            outline0("CP 0" );
            outline0("PUSH AF" );
            outline1("JR Z, %spos", label );
            cpu_complement2_32bit( _environment, _source, _source );
            outline1("JMP %spos2", label );
            outhead1("%spos:", label );
            outhead1("%spos2:", label );
            outline1("LD DE, (%s)", _source );
            outline1("LD BC, (%s)", address_displacement(_environment, _source, "2") );
            while( _steps ) {
                outline0("SRA B" );
                outline0("RR C" );
                outline0("RR D" );
                outline0("RR E" );
                --_steps;
            }
            outline1("LD (%s),DE", _source );
            outline1("LD (%s),BC", address_displacement( _environment, _source, "2" ) );
            outline0("POP AF" );
            outline0("AND $80" );
            outline0("CP 0" );
            outline1("JR Z, %sdone", label );
            cpu_complement2_32bit( _environment, _source, _source );
            outhead1("%sdone:", label );
        } else {
            outline1("LD DE, (%s)", _source );
            outline1("LD BC, (%s)", address_displacement(_environment, _source, "2") );
            while( _steps ) {
                outline0("SRA B" );
                outline0("RR C" );
                outline0("RR D" );
                outline0("RR E" );
                --_steps;
            }
            outline1("LD (%s), DE", _source );
            outline1("LD (%s), BC", address_displacement( _environment, _source, "2" ) );    
        }

    no_embedded( cpu_math_div2_const_32bit )

}

void cpu_math_div2_const_nbit( Environment * _environment, char *_source, int _steps, int _bits, char * _remainder ) {

    inline( cpu_math_div2_const_nbit )

        MAKE_LABEL

        if ( _remainder ) {
            outline1("LD A, (%s)", _source);
            outline0("AND $01" );
            outline1("LD (%s), A", _remainder);
        }
        char offsetMsb[MAX_TEMPORARY_STORAGE]; sprintf( offsetMsb, "%d", (_bits>>3)-1 );

        outline1("LD A, (%s)", address_displacement(_environment, _source, offsetMsb));
        outline0("AND $80");
        outline0("LD B, A");
        outline0("CP $80");
        outline1("JP NZ, %snocomplement", label );
        cpu_complement2_nbit( _environment, _source, _source, _bits );
        outhead1("%snocomplement:", label );
        while( _steps ) {
            outline0("SCF");
            outline0("CCF");
            outline1("LD A, (%s)", address_displacement(_environment, _source, offsetMsb));
            outline0("SRA A");
            outline1("LD (%s), A", address_displacement(_environment, _source, offsetMsb));
            for( int i=(_bits>>3)-2; i>-1; --i ) {
                char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
                outline1("LD A, (%s)", address_displacement(_environment, _source, offset));
                outline0("RR A");
                outline1("LD (%s), A", address_displacement(_environment, _source, offset));
            }
            --_steps;
        }
        outline0("LD A, B");
        outline0("CP $80");
        outline1("JP NZ, %snocomplement2", label );
        cpu_complement2_nbit( _environment, _source, _source, _bits );
        outhead1("%snocomplement2:", label );

    no_embedded( cpu_math_div2_const_nbit )

}

/**
 * @brief <i>Z80</i>: emit code to double for several times a 32 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 * @todo Not yet implemented
 */
void cpu_math_mul2_const_32bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    inline( cpu_math_mul2_const_32bit )

        MAKE_LABEL

        if ( _signed ) {
            outline1("LD A, (%s)", address_displacement(_environment, _source, "3") );
            outline0("AND $80" );
            outline0("CP 0" );
            outline0("PUSH AF" );
            outline1("JR Z, %spos", label );
            cpu_complement2_32bit( _environment, _source, _source );
            outline1("JMP %spos2", label );
            outhead1("%spos:", label );
            outhead1("%spos2:", label );
            outline1("LD HL, (%s)", _source );
            outline1("LD DE, (%s)", address_displacement(_environment, _source, "2") );
            while( _steps ) {
                outline0("SLA L" );
                outline0("RL H" );
                outline0("RL E" );
                outline0("RL D" );
                --_steps;
            }
            outline1("LD (%s), HL", _source );
            outline1("LD (%s), DE", address_displacement( _environment, _source, "2" ) );
            outline0("POP AF" );
            outline0("AND $80" );
            outline0("CP 0" );
            outline1("JR Z, %sdone", label );
            cpu_complement2_32bit( _environment, _source, _source );
            outhead1("%sdone:", label );
        } else {
            outline1("LD HL, (%s)", _source );
            outline1("LD DE, (%s)", address_displacement(_environment, _source, "2") );
            while( _steps ) {
                outline0("SLA L" );
                outline0("RL H" );
                outline0("RL D" );
                outline0("RL E" );
                --_steps;
            }
            outline1("LD (%s), HL", _source );
            outline1("LD (%s), DE", address_displacement( _environment, _source, "2" ) );
        }

    no_embedded( cpu_math_mul2_const_32bit )
    
}

/**
 * @brief <i>Z80</i>: emit code to mask with "and" a value of 32 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 * @todo Not yet implemented
 */
void cpu_math_and_const_32bit( Environment * _environment, char *_source, int _mask ) {

    inline( cpu_math_and_const_32bit )

        outline1("LD A, (%s)", _source );
        outline1("AND $%2.2x", ( _mask & 0xff ) );
        outline1("LD (%s), A", _source );
        outline1("LD A, (%s)", address_displacement(_environment, _source, "1") );
        outline1("AND $%2.2x", ( ( _mask >> 8 ) & 0xff ) );
        outline1("LD (%s), A", address_displacement(_environment, _source, "1") );
        outline1("LD A, (%s)", address_displacement(_environment, _source, "2") );
        outline1("AND $%2.2x", ( ( _mask >> 16 ) & 0xff ) );
        outline1("LD (%s), A", address_displacement(_environment, _source, "2") );
        outline1("LD A, (%s)", address_displacement(_environment, _source, "3") );
        outline1("AND $%2.2x", ( ( _mask >> 24 ) & 0xff ) );
        outline1("LD (%s), A", address_displacement(_environment, _source, "3") );

    no_embedded( cpu_math_and_const_32bit )

}

/**
 * @brief <i>Z80</i>: emit code to combine nibbles
 * 
 * @todo Not yet implemented
 */
void cpu_combine_nibbles( Environment * _environment, char * _low_nibble, char * _hi_nibble, char * _byte ) {

    no_inline( cpu_combine_nibbles )

    embedded( cpu_combine_nibbles, src_hw_z80_cpu_combine_nibbles_asm );

        outline1("LD A, (%s)", _low_nibble );
        outline1("LD HL, %s", _hi_nibble );
        outline1("LD DE, %s", _byte );
        outline0("CALL CPUCOMBINENIBBLES" );

    done( )

}

void cpu_jump( Environment * _environment, char * _label ) {

    outline1("jp %s", _label );

}

void cpu_call_addr( Environment * _environment, int _address ) {

    outline1("call $%4.4x", _address );

}

void cpu_call( Environment * _environment, char * _label ) {

    outline1("call %s", _label );

}

void cpu_call_indirect( Environment * _environment, char * _value ) {

    MAKE_LABEL

    char indirectLabel[MAX_TEMPORARY_STORAGE]; sprintf( indirectLabel, "%sindirect", label );

    outline0( "LD (CALLINDIRECTSAVEHL), HL" )
    outline1( "LD HL, (%s)", _value )
    outline0( "LD (CALLINDIRECT+1), HL" )
    outline0( "LD HL, (CALLINDIRECTSAVEHL)" )
    outline0( "CALL CALLINDIRECT" );

}

void cpu_jump_indirect( Environment * _environment, char * _value ) {

    outline1( "LD HL, (%s)", _value )
    outline0( "JP (HL)" );

}

int cpu_register_decode( Environment * _environment, char * _register ) {

    Z80Register result = REGISTER_NONE;

    if ( !_environment->emptyProcedure ) {

        if ( strcmp( _register, "A" ) == 0 ) {
            result = REGISTER_A;
        } else if ( strcmp( _register, "B" ) == 0 ) {
            result = REGISTER_B;
        } else if ( strcmp( _register, "C" ) == 0 ) {
            result = REGISTER_C;
        } else if ( strcmp( _register, "D" ) == 0 ) {
            result = REGISTER_D;
        } else if ( strcmp( _register, "E" ) == 0 ) {
            result = REGISTER_E;
        } else if ( strcmp( _register, "H" ) == 0 ) {
            result = REGISTER_H;
        } else if ( strcmp( _register, "L" ) == 0 ) {
            result = REGISTER_L;
        } else if ( strcmp( _register, "F" ) == 0 ) {
            if ( !_environment->emptyProcedure ) {
                CRITICAL_UNSETTABLE_CPU_REGISTER( _register );
            }
            // result = REGISTER_F;
        } else if ( strcmp( _register, "I" ) == 0 ) {
            if ( !_environment->emptyProcedure ) {
                CRITICAL_UNSETTABLE_CPU_REGISTER( _register );
            }
            // result = REGISTER_I;
        } else if ( strcmp( _register, "R" ) == 0 ) {
            if ( !_environment->emptyProcedure ) {
                CRITICAL_UNSETTABLE_CPU_REGISTER( _register );
            }
            // result = REGISTER_R;
        } else if ( strcmp( _register, "SP" ) == 0 ) {
            if ( !_environment->emptyProcedure ) {
                CRITICAL_UNSETTABLE_CPU_REGISTER( _register );
            }
            // result = REGISTER_SP;
        } else if ( strcmp( _register, "PC" ) == 0 ) {
            if ( !_environment->emptyProcedure ) {
                CRITICAL_UNSETTABLE_CPU_REGISTER( _register );
            }
            // result = REGISTER_PC;
        } else if ( strcmp( _register, "IX" ) == 0 ) {
            result = REGISTER_IX;
        } else if ( strcmp( _register, "IY" ) == 0 ) {
            result = REGISTER_IY;
        } else if ( strcmp( _register, "AF" ) == 0 ) {
            if ( !_environment->emptyProcedure ) {
                CRITICAL_UNSETTABLE_CPU_REGISTER( _register );
            }
            // result = REGISTER_AF;
        } else if ( strcmp( _register, "BC" ) == 0 ) {
            result = REGISTER_BC;
        } else if ( strcmp( _register, "DE" ) == 0 ) {
            result = REGISTER_DE;
        } else if ( strcmp( _register, "HL" ) == 0 ) {
            result = REGISTER_HL;
        } else if ( strcmp( _register, "IXL" ) == 0 ) {
            result = REGISTER_IXL;
        } else if ( strcmp( _register, "IXH" ) == 0 ) {
            result = REGISTER_IXH;
        } else if ( strcmp( _register, "IYL" ) == 0 ) {
            result = REGISTER_IYL;
        } else if ( strcmp( _register, "IYH" ) == 0 ) {
            result = REGISTER_IYH;
        } else if ( strcmp( _register, "CARRY" ) == 0 ) {
            result = REGISTER_CARRY;
        } else if ( strcmp( _register, "ZERO" ) == 0 ) {
            result = REGISTER_ZERO;
        } else if ( strcmp( _register, "HLA" ) == 0 ) {
            result = REGISTER_HLA;
        } else {

        }

    }

    return (int)result;

}

void cpu_set_asmio( Environment * _environment, int _asmio, int _value ) {

    if ( IS_REGISTER( _asmio ) ) {

        MAKE_LABEL

        Z80Register reg = (Z80Register) _asmio;

        switch ( reg ) {
            case REGISTER_NONE:
                CRITICAL_UNKNOWN_CPU_REGISTER( );
                break;
            case REGISTER_F:
            case REGISTER_I:
            case REGISTER_R:
            case REGISTER_SP:
            case REGISTER_PC:
            case REGISTER_AF:
                break;
            case REGISTER_A:
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                break;
            case REGISTER_B:
                outline0( "PUSH AF" );
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "LD B, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_C:
                outline0( "PUSH AF" );
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "LD C, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_D:
                outline0( "PUSH AF" );
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "LD D, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_E:
                outline0( "PUSH AF" );
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "LD E, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_H:
                outline0( "PUSH AF" );
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "LD H, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_L:
                outline0( "PUSH AF" );
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "LD L, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_IX:
                outline1( "LD IX, $%4.4x", (unsigned short)(_value & 0xffff) );
                break;
            case REGISTER_IY:
                outline1( "LD IY, $%4.4x", (unsigned short)(_value & 0xffff) );
                break;
            case REGISTER_BC:
                outline0( "PUSH HL" );
                outline1( "LD HL, $%4.4x", (unsigned short)(_value & 0xffff) );
                outline0( "LD BC, HL" );
                outline0( "POP HL" );
                break;
            case REGISTER_DE:
                outline0( "PUSH HL" );
                outline1( "LD HL, $%4.4x", (unsigned short)(_value & 0xffff) );
                outline0( "LD DE, HL" );
                outline0( "POP HL" );
                break;
            case REGISTER_HL:
                outline1( "LD HL, $%4.4x", (unsigned short)(_value & 0xffff) );
                break;
            case REGISTER_IXL:
                outline0( "PUSH AF" );
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "LD IXL, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_IXH:
                outline0( "PUSH AF" );
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "LD IXH, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_IYL:
                outline0( "PUSH AF" );
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "LD IYL, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_IYH:
                outline0( "PUSH AF" );
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "LD IYH, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_CARRY:
                outline0( "PUSH AF" );
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "CP 0" );
                outline1( "JR Z, %snoc", label );
                outline0( "LD A, $1" );
                outline0( "SRL A" );
                outline1( "JP %sdone", label );
                outhead1( "%snoc:", label );
                outline0( "SRL A" );
                outhead1( "%sdone:", label );
                outline0( "POP AF" );
                break;
            case REGISTER_ZERO:
                outline0( "PUSH AF" );
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "CP 0" );
                outline0( "POP AF" );
                break;
            case REGISTER_HLA:
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                outline1( "LD HL, $%4.4x", (unsigned char)((_value >> 8 ) & 0xffff ) );
                break;
        }

    } else {

        Z80Stack stk = (Z80Stack) _asmio;

        switch ( stk ) {
            case STACK_NONE:
                break;
            case STACK_BYTE:
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "PUSH A" );
                break;
            case STACK_WORD:
                outline1( "LD HL, $%4.4x", (unsigned short)(_value & 0xffff) );
                outline0( "PUSH HL" );
                break;
            case STACK_DWORD:
                outline1( "LD HL, $%4.4x", (unsigned short)(_value & 0xffff) );
                outline0( "PUSH HL" );
                outline1( "LD HL, $%4.4x", (unsigned short)((_value>>16) & 0xffff) );
                outline0( "PUSH HL" );
                break;
        }

    }

}

void cpu_set_asmio_indirect( Environment * _environment, int _asmio, char * _value ) {

    if ( IS_REGISTER( _asmio ) ) {

        MAKE_LABEL

        Z80Register reg = (Z80Register) _asmio;

        switch ( reg ) {
            case REGISTER_NONE:
                CRITICAL_UNKNOWN_CPU_REGISTER( );
                break;
            case REGISTER_F:
            case REGISTER_I:
            case REGISTER_R:
            case REGISTER_SP:
            case REGISTER_PC:
            case REGISTER_AF:
                break;
            case REGISTER_A:
                outline1( "LD A, (%s)", _value );
                break;
            case REGISTER_B:
                outline0( "PUSH AF" );
                outline1( "LD A, (%s)", _value );
                outline0( "LD B, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_C:
                outline0( "PUSH AF" );
                outline1( "LD A, (%s)", _value );
                outline0( "LD C, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_D:
                outline0( "PUSH AF" );
                outline1( "LD A, (%s)", _value );
                outline0( "LD D, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_E:
                outline0( "PUSH AF" );
                outline1( "LD A, (%s)", _value );
                outline0( "LD E, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_H:
                outline0( "PUSH AF" );
                outline1( "LD A, (%s)", _value );
                outline0( "LD H, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_L:
                outline0( "PUSH AF" );
                outline1( "LD A, (%s)", _value );
                outline0( "LD L, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_IX:
                outline1( "LD IX, (%s)", _value );
                break;
            case REGISTER_IY:
                outline1( "LD IY, (%s)", _value );
                break;
            case REGISTER_BC:
                outline0( "PUSH HL" );
                outline1( "LD HL, (%s)", _value );
                outline0( "LD BC, HL" );
                outline0( "POP HL" );
                break;
            case REGISTER_DE:
                outline0( "PUSH HL" );
                outline1( "LD HL, (%s)", _value );
                outline0( "LD DE, HL" );
                outline0( "POP HL" );
                break;
            case REGISTER_HL:
                outline1( "LD HL, (%s)", _value );
                break;
            case REGISTER_IXL:
                outline0( "PUSH AF" );
                outline1( "LD A, (%s)", _value );
                outline0( "LD IXL, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_IXH:
                outline0( "PUSH AF" );
                outline1( "LD A, (%s)", _value );
                outline0( "LD IXH, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_IYL:
                outline0( "PUSH AF" );
                outline1( "LD A, (%s)", _value );
                outline0( "LD IYL, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_IYH:
                outline0( "PUSH AF" );
                outline1( "LD A, (%s)", _value );
                outline0( "LD IYH, A" );
                outline0( "POP AF" );
                break;
            case REGISTER_CARRY:
                outline0( "PUSH AF" );
                outline1( "LD A, (%s)", _value );
                outline0( "CP 0" );
                outline1( "JR Z, %snoc", label );
                outline0( "LD A, $1" );
                outline0( "SRL A" );
                outline1( "JP %sdone", label );
                outhead1( "%snoc:", label );
                outline0( "SRL A" );
                outhead1( "%sdone:", label );
                outline0( "POP AF" );
                break;
            case REGISTER_ZERO:
                outline0( "PUSH AF" );
                outline1( "LD A, (%s)", _value );
                outline0( "CP 0" );
                outline0( "POP AF" );
                break;
            case REGISTER_HLA:
                outline1( "LD A, (%s)", address_displacement( _environment, _value, "2" ) );
                outline0( "LD H, A" );
                outline1( "LD A, (%s)", address_displacement( _environment, _value, "1" ) );
                outline0( "LD L, A" );
                outline1( "LD A, (%s)", _value );
                break;
        }

    } else {

        Z80Stack stk = (Z80Stack) _asmio;

        switch ( stk ) {
            case STACK_NONE:
                break;
            case STACK_BYTE:
                outline1( "LD A, (%s)", _value );
                outline0( "PUSH A" );
                break;
            case STACK_WORD:
                outline1( "LD HL, (%s)", _value );
                outline0( "PUSH HL" );
                break;
            case STACK_DWORD:
                outline1( "LD HL, (%s)", address_displacement( _environment, _value, "0" ) );
                outline0( "PUSH HL" );
                outline1( "LD HL, (%s)", address_displacement( _environment, _value, "2" ) );
                outline0( "PUSH HL" );
                break;
        }

    }

}

void cpu_get_asmio_indirect( Environment * _environment, int _asmio, char * _value ) {

    if ( IS_REGISTER( _asmio ) ) {

        MAKE_LABEL

        Z80Register reg = (Z80Register) _asmio;

        switch ( reg ) {
            case REGISTER_NONE:
                CRITICAL_UNKNOWN_CPU_REGISTER( );
                break;
            case REGISTER_F:
            case REGISTER_I:
            case REGISTER_R:
            case REGISTER_SP:
            case REGISTER_PC:
            case REGISTER_AF:
                break;
            case REGISTER_A:
                outline1( "LD (%s), A", _value );
                break;
            case REGISTER_B:
                outline0( "PUSH AF" );
                outline0( "LD A, B" );
                outline1( "LD (%s), A", _value );
                outline0( "POP AF" );
                break;
            case REGISTER_C:
                outline0( "PUSH AF" );
                outline0( "LD A, C" );
                outline1( "LD (%s), A", _value );
                outline0( "POP AF" );
                break;
            case REGISTER_D:
                outline0( "PUSH AF" );
                outline0( "LD A, D" );
                outline1( "LD (%s), A", _value );
                outline0( "POP AF" );
                break;
            case REGISTER_E:
                outline0( "PUSH AF" );
                outline0( "LD A, E" );
                outline1( "LD (%s), A", _value );
                outline0( "POP AF" );
                break;
            case REGISTER_H:
                outline0( "PUSH AF" );
                outline0( "LD A, H" );
                outline1( "LD (%s), A", _value );
                outline0( "POP AF" );
                break;
            case REGISTER_L:
                outline0( "PUSH AF" );
                outline0( "LD A, L" );
                outline1( "LD (%s), A", _value );
                outline0( "POP AF" );
                break;
            case REGISTER_IX:
                outline1( "LD (%s), IX", _value );
                break;
            case REGISTER_IY:
                outline1( "LD (%s), IY", _value );
                break;
            case REGISTER_BC:
                outline0( "PUSH HL" );
                outline0( "LD HL, BC" );
                outline1( "LD (%s), HL", _value );
                outline0( "POP HL" );
                break;
            case REGISTER_DE:
                outline0( "PUSH HL" );
                outline0( "LD HL, DE" );
                outline1( "LD (%s), HL", _value );
                outline0( "POP HL" );
                break;
            case REGISTER_HL:
                outline1( "LD (%s), HL", _value );
                break;
            case REGISTER_IXL:
                outline0( "PUSH AF" );
                outline0( "LD A, IXL" );
                outline1( "LD (%s), A", _value );
                outline0( "POP AF" );
                break;
            case REGISTER_IXH:
                outline0( "PUSH AF" );
                outline0( "LD A, IXH" );
                outline1( "LD (%s), A", _value );
                outline0( "POP AF" );
                break;
            case REGISTER_IYL:
                outline0( "PUSH AF" );
                outline0( "LD A, IYL" );
                outline1( "LD (%s), A", _value );
                outline0( "POP AF" );
                break;
            case REGISTER_IYH:
                outline0( "PUSH AF" );
                outline0( "LD A, IYH" );
                outline1( "LD (%s), A", _value );
                outline0( "POP AF" );
                break;
            case REGISTER_CARRY:
                outline0( "PUSH AF" );
                outline1( "JR NC, %snoc", label );
                outline0( "LD A, $1" );
                outline1( "LD (%s), A", _value );
                outline1( "JP %sdone", label );
                outhead1( "%snoc:", label );
                outline0( "LD A, $0" );
                outline1( "LD (%s), A", _value );
                outhead1( "%sdone:", label );
                outline0( "POP AF" );
                break;
            case REGISTER_ZERO:
                outline0( "PUSH AF" );
                outline1( "JR NZ, %snoz", label );
                outline0( "LD A, $1" );
                outline1( "LD (%s), A", _value );
                outline1( "JP %sdone", label );
                outhead1( "%snoz:", label );
                outline0( "LD A, $0" );
                outline1( "LD (%s), A", _value );
                outhead1( "%sdone:", label );
                outline0( "POP AF" );
                break;
            case REGISTER_HLA:
                outline1( "LD (%s), A", _value );
                outline0( "LD A, L" );
                outline1( "LD (%s), A", address_displacement( _environment, _value, "1" ) );
                outline0( "LD A, H" );
                outline1( "LD (%s), A", address_displacement( _environment, _value, "2" ) );
                break;
        }

    } else {

        Z80Stack stk = (Z80Stack) _asmio;

        switch ( stk ) {
            case STACK_NONE:
                break;
            case STACK_BYTE:
                outline0( "POP AF" );
                outline1( "LD (%s), A", _value );
                break;
            case STACK_WORD:
                outline0( "POP HL" );
                outline1( "LD (%s), HL", _value );
                break;
            case STACK_DWORD:
                outline0( "POP HL" );
                outline1( "LD (%s), HL", address_displacement( _environment, _value, "0" ) );
                outline0( "POP HL" );
                outline1( "LD (%s), HL", address_displacement( _environment, _value, "2" ) );
                break;
        }

    }

}

void cpu_return( Environment * _environment ) {

    outline0("RET" );

}

void cpu_pop( Environment * _environment ) {

    outline0("POP IX" );

}

void cpu_halt( Environment * _environment ) {

    MAKE_LABEL

    outhead1("%s:", label );
    outline1("jp %s", label );

}

void cpu_end( Environment * _environment ) {

    outline0("DI");
    outline0("HLT");

}

void cpu_random( Environment * _environment, char * _entropy ) {

    MAKE_LABEL

    inline( cpu_random )

        if ( _entropy ) {
            outline0("LD HL, (CPURANDOM_SEED)");
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
            outline0("LD (CPURANDOM_SEED), HL");
            outline0("LD HL, (CPURANDOM_SEED+2)");
            outline0("ADD HL, DE");
            outline0("LD (CPURANDOM_SEED+1), HL");
            outline0("EX DE, HL");
            outline0("LD HL, (CPURANDOM_SEED)");
            outline1("LD DE, (%s)", _entropy);
            outline0("ADD HL, HL");
            outline0("RL C");
            outline0("RL B");
            outline0("LD (CPURANDOM_SEED+1), BC");
            outline0("SBC A, A");
            outline0("AND %11000101");
            outline0("XOR L");
            outline0("LD L, A");
            outline0("LD (CPURANDOM_SEED+1), HL");
            outline0("EX DE, HL");
            outline0("ADD HL, BC");
        }

    embedded( cpu_random, src_hw_z80_cpu_random_asm );
       
    done()


}

void cpu_random_8bit( Environment * _environment, char * _entropy, char * _result ) {

    cpu_random( _environment, _entropy );

    if ( _result ) {
        outline0("CALL CPURANDOM16" );
        outline0("LD A, H" );
        outline1("LD (%s), A", _result );
    }

}

void cpu_random_16bit( Environment * _environment, char * _entropy, char * _result ) {

    cpu_random( _environment, _entropy );

    if ( _result ) {
        outline0("CALL CPURANDOM16" );
        outline1("LD (%s), HL", _result );
    }

}

void cpu_random_32bit( Environment * _environment, char * _entropy, char * _result ) {

    cpu_random( _environment, _entropy );

    if ( _result ) {
        outline0("CALL CPURANDOM32" );
        outline1("LD (%s), HL", _result );
        outline1("LD (%s), BC", address_displacement( _environment, _result, "2" ) );
    }

}

void cpu_limit_16bit( Environment * _environment, char * _variable, int _value ) {

    MAKE_LABEL

    outline1( "LD A, (%s)", _variable );
    outline1( "CP $%2.2x", _value );
    outline1( "JR C, %s", label );
    outline1( "SUB $%2.2x", _value );
    outline1( "LD (%s), A", _variable );
    outhead1( "%s:", label );

}

void cpu_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _timing );
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
void cpu_port_out( Environment * _environment, char * _port, char * _value ) {

    outline1("LD A, (%s)", _value );
    outline1("OUT (%s), A", _port );

}

void cpu_logical_and_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

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

void cpu_and_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD IX, %s", _right );
    outline1("LD DE, %s", _result );
    outline0("LD A, (HL)" );
    outline0("AND (IX)" );
    outline0("LD (DE), A" );

}

void cpu_and_8bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _left );
    outline1("AND $%2.2x", _right );
    outline1("LD (%s), A", _result );

}

void cpu_and_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD IX, %s", _right );
    outline1("LD DE, %s", _result );
    outline0("LD A, (HL)" );
    outline0("AND (IX)" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("AND (IX+1)" );
    outline0("LD (DE), A" );

}

void cpu_and_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD IX, %s", _right );
    outline1("LD DE, %s", _result );
    outline0("LD A, (HL)" );
    outline0("AND (IX)" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("AND (IX+1)" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("AND (IX+2)" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("AND (IX+3)" );
    outline0("LD (DE), A" );

}

void cpu_logical_or_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _left );
    outline1("JR NZ, %sd1", label );
    outline1("LD A, (%s)", _right );
    outline1("JR NZ, %sd1", label );
    outhead1("%s0:", label );
    outline0("LD A, 0" );
    outline1("LD (%s), A", _result );
    outline1("JMP %sx", label );
    outhead1("%sd1:", label );
    outline0("LD A, $ff" );
    outline1("LD (%s), A", _result );
    outhead1("%sx:", label );

}

void cpu_or_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD IX, %s", _right );
    outline1("LD DE, %s", _result );
    outline0("LD A, (HL)" );
    outline0("OR (IX)" );
    outline0("LD (DE), A" );

}

void cpu_or_8bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _left );
    outline1("OR $%2.2x", _right );
    outline1("LD (%s), A", _result );

}


void cpu_or_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD IX, %s", _right );
    outline1("LD DE, %s", _result );
    outline0("LD A, (HL)" );
    outline0("OR (IX)" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("OR (IX+1)" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );

}

void cpu_or_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD IX, %s", _right );
    outline1("LD DE, %s", _result );
    outline0("LD A, (HL)" );
    outline0("OR (IX)" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("OR (IX+1)" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("OR (IX+2)" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("OR (IX+3)" );
    outline0("LD (DE), A" );

}

void cpu_xor_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD IX, %s", _right );
    outline1("LD DE, %s", _result );
    outline0("LD A, (HL)" );
    outline0("XOR (IX)" );
    outline0("LD (DE), A" );

}

void cpu_xor_8bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD DE, %s", _result );
    outline0("LD A, (HL)" );
    outline1("XOR $%2.2x", (unsigned char)(_right&0xff) );
    outline0("LD (DE), A" );

}

void cpu_xor_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD IX, %s", _right );
    outline1("LD DE, %s", _result );
    outline0("LD A, (HL)" );
    outline0("XOR (IX)" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("XOR (IX+1)" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );

}

void cpu_xor_16bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD DE, %s", _result );
    outline0("LD A, (HL)" );
    outline1("XOR $%2.2x", (unsigned char)((_right) & 0xff) );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline1("XOR $%2.2x", (unsigned char)((_right>>8) & 0xff) );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );

}


void cpu_xor_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD IX, %s", _right );
    outline1("LD DE, %s", _result );
    outline0("LD A, (HL)" );
    outline0("XOR (IX)" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("XOR (IX+1)" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("XOR (IX+2)" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("XOR (IX+3)" );
    outline0("LD (DE), A" );

}

void cpu_xor_32bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD DE, %s", _result );
    outline0("LD A, (HL)" );
    outline1("XOR $%2.2x", (unsigned char)(_right & 0xff ) );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline1("XOR $%2.2x", (unsigned char)((_right>>8) & 0xff ) );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline1("XOR $%2.2x", (unsigned char)((_right>>16) & 0xff ) );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline1("XOR $%2.2x", (unsigned char)((_right>>24) & 0xff ) );
    outline0("LD (DE), A" );

}

void cpu_swap_8bit( Environment * _environment, char * _left, char * _right ) {

    no_inline( cpu_swap_8bit )

    embedded( cpu_swap_8bit, src_hw_z80_cpu_swap_asm ) // it is not an error: swap 8/16/32 shares code

        outline1("LD HL, %s", _right );
        outline1("LD DE, %s", _left );
        outline0("LD B, 1" );
        outline0("CALL CPUSWAP" );

    done( )

}    

void cpu_swap_16bit( Environment * _environment, char * _left, char * _right ) {

    no_inline( cpu_swap_8bit )

    embedded( cpu_swap_8bit, src_hw_z80_cpu_swap_asm ) // it is not an error: swap 8/16/32 shares code

        outline1("LD HL, %s", _right );
        outline1("LD DE, %s", _left );
        outline0("LD B, 2" );
        outline0("CALL CPUSWAP" );

    done( )

}

void cpu_swap_32bit( Environment * _environment, char * _left, char * _right ) {

    no_inline( cpu_swap_8bit )

    embedded( cpu_swap_8bit, src_hw_z80_cpu_swap_asm ) // it is not an error: swap 8/16/32 shares code

        outline1("LD HL, %s", _right );
        outline1("LD DE, %s", _left );
        outline0("LD B, 4" );
        outline0("CALL CPUSWAP" );

    done( )
    
}

void cpu_logical_not_8bit( Environment * _environment, char * _value, char * _result ) {

    outline1("LD A, (%s)", _value );
    outline0("XOR $FF" );
    outline1("LD (%s), A", _result );

}

void cpu_not_8bit( Environment * _environment, char * _value, char * _result ) {

    outline1("LD A, (%s)", _value );
    outline0("XOR $FF" );
    outline1("LD (%s), A", _result );

}

void cpu_not_16bit( Environment * _environment, char * _value, char * _result ) {

    outline1("LD HL, %s", _value );
    outline1("LD DE, %s", _result );
    outline0("LD A, (HL)" );
    outline0("XOR $FF" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("XOR $FF" );
    outline0("LD (DE), A" );

}

void cpu_not_32bit( Environment * _environment, char * _value, char * _result ) {

    outline1("LD HL, %s", _value );
    outline1("LD DE, %s", _result );
    outline0("LD A, (HL)" );
    outline0("XOR $FF" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("XOR $FF" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("XOR $FF" );
    outline0("LD (DE), A" );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("XOR $FF" );
    outline0("LD (DE), A" );

}

void cpu_di( Environment * _environment ) {

    outline0("DI" );

}

void cpu_ei( Environment * _environment ) {

    outline0("EI" );

}

void cpu_inc( Environment * _environment, char * _variable ) {

    outline1("LD A, (%s)", _variable  );
    outline0("INC A" );
    outline1("LD (%s), A", _variable  );

}

void cpu_dec( Environment * _environment, char * _variable ) {

    outline1("LD A, (%s)", _variable  );
    outline0("DEC A" );
    outline1("LD (%s), A", _variable  );

}

void cpu_inc_16bit( Environment * _environment, char * _variable ) {

    outline1("LD HL, (%s)", _variable  );
    outline0("INC HL" );
    outline1("LD (%s), HL", _variable  );

}

void cpu_inc_32bit( Environment * _environment, char * _variable ) {

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
    outline1("LD HL, (%s)", address_displacement(_environment, _variable, "2")  );
    outline0("INC HL" );
    outline1("LD (%s), HL", address_displacement( _environment, _variable, "2" )  );
    outhead1("%s:", label  );

}

void cpu_inc_nbit( Environment * _environment, char * _variable, int _bits ) {

    MAKE_LABEL

    inline( cpu_inc_nbit )

        for( int i=0; i<(_bits>>3);++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf(offset, "%d", i );
            outline1("LD A, (%s)", address_displacement(_environment, _variable, offset ) );
            outline0("INC A");
            outline1("LD (%s), A", address_displacement(_environment, _variable, offset ) );
            outline1("JP NZ, %s", label );
        }
        outhead1("%s:", label );

    no_embedded( cpu_inc_nbit )

}

void cpu_dec_16bit( Environment * _environment, char * _variable ) {

    outline1("LD HL, (%s)", _variable  );
    outline0("DEC HL" );
    outline1("LD (%s), HL", _variable  );

}

void cpu_dec_32bit( Environment * _environment, char * _variable ) {

    MAKE_LABEL

    outline1("LD HL, (%s)", _variable  );
    outline0("DEC HL" );
    outline1("LD (%s), HL", _variable  );
    outline0("LD A, L" );
    outline0("AND H" );
    outline0("CP $FF" );
    outline1("JR NZ, %s", label );
    outline1("LD HL, (%s)", _variable  );
    outline0("DEC HL" );
    outline1("LD (%s), HL", _variable  );
    outhead1("%s:", label );

}

void cpu_dec_nbit( Environment * _environment, char * _variable, int _bits ) {

    MAKE_LABEL

    inline( cpu_dec_32bit )

        for( int i=0; i<(_bits>>3); ++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
            outline1("LD A, (%s)", address_displacement(_environment, _variable, offset) );
            outline0("DEC A" );
            outline1("LD (%s), A", address_displacement(_environment, _variable, offset) );
            outline0("CP $FF" );
            outline1("JP NZ, %s", label );
        }
        outhead1("%s:", label );

    no_embedded( cpu_dec_32bit )

}

void cpu_mem_move( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    deploy( duff, src_hw_z80_duff_asm );

    outline1("LD HL, (%s)", _source);
    outline1("LD DE, (%s)", _destination);
    outline1("LD A, (%s)", _size);
    outline0("LD C, A");
    outline0("LD B, 0");
    outline0("CALL DUFFDEVICE");

}

void cpu_mem_move_16bit( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    deploy( duff, src_hw_z80_duff_asm );

    outline1("LD HL, (%s)", _source);
    outline1("LD DE, (%s)", _destination);
    outline1("LD BC, (%s)", _size);
    outline0("CALL DUFFDEVICE");

}

void cpu_mem_move_direct( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    deploy( duff, src_hw_z80_duff_asm );

    outline1("LD HL, %s", _source);
    outline1("LD DE, %s", _destination);
    outline1("LD A, (%s)", _size);
    outline0("LD C, A");
    outline0("LD B, 0");
    outline0("CALL DUFFDEVICE");

}

void cpu_mem_move_direct2( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    deploy( duff, src_hw_z80_duff_asm );

    outline1("LD HL, (%s)", _source);
    outline1("LD DE, %s", _destination);
    outline1("LD BC, (%s)", _size);
    outline0("CALL DUFFDEVICE");

}

void cpu_mem_move_direct2_size( Environment * _environment, char *_source, char *_destination,  int _size ) {

    deploy( duff, src_hw_z80_duff_asm );

    outline1("LD HL, (%s)", _source);
    outline1("LD DE, %s", _destination);
    outline1("LD BC, $%4.4x", _size);
    outline0("CALL DUFFDEVICE");

}

void cpu_mem_move_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size > 0 ) {

        deploy( duff, src_hw_z80_duff_asm );

        outline1("LD HL, (%s)", _source);
        outline1("LD DE, (%s)", _destination);
        outline1("LD A, $%2.2x", ( _size & 0xff ) );
        outline0("LD C, A");
        outline1("LD B, $%2.2x", ( _size >> 8 ) & 0xff );
        outline0("CALL DUFFDEVICE");

    }

}

void cpu_mem_move_direct_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size > 0 ) {

        deploy( duff, src_hw_z80_duff_asm );

        outline1("LD HL, %s", _source);
        outline1("LD DE, %s", _destination);
        outline1("LD A, $%2.2x", ( _size & 0xff ) );
        outline0("LD C, A");
        outline1("LD B, $%2.2x", ( _size >> 8 ) & 0xff );
        outline0("CALL DUFFDEVICE");
    }

}

void cpu_mem_move_direct_indirect_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size ) {

        deploy( duff, src_hw_z80_duff_asm );

        outline1("LD HL, %s", _source);
        outline1("LD DE, (%s)", _destination);
        outline1("LD A, $%2.2x", ( _size & 0xff ) );
        outline0("LD C, A");
        outline1("LD B, $%2.2x", ( _size >> 8 ) & 0xff );
        outline0("CALL DUFFDEVICE");
    }

}

void cpu_mem_move_indirect_direct_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size ) {

        deploy( duff, src_hw_z80_duff_asm );

        outline1("LD HL, (%s)", _source);
        outline1("LD DE, %s", _destination);
        outline1("LD A, $%2.2x", ( _size & 0xff ) );
        outline0("LD C, A");
        outline1("LD B, $%2.2x", ( _size >> 8 ) & 0xff );
        outline0("CALL DUFFDEVICE");
    }

}

void cpu_compare_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _size);
    outline0("CP 0");
    outline1("JR Z, %sequal", label);
    outline0("LD C, A");
    outline1("LD HL, (%s)", _source);
    outline1("LD DE, (%s)", _destination);
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
    outline1("LD A, $%2.2x", _equal ? 255 : 0 );
    outline1("LD (%s), A", _result );
    outline1("JMP %sfinal", label );
    outhead1("%sdiff:", label );
    outline1("LD A, $%2.2x", _equal ? 0 : 255 );
    outline1("LD (%s), A", _result );
    outhead1("%sfinal:", label );

}

void cpu_compare_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD HL, (%s)", _source);
    outline1("LD DE, (%s)", _destination);
    outline1("LD A, $%2.2x", ( _size & 0xff ) );
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
    outline1("LD A, $%2.2x", _equal ? 255 : 0 );
    outline1("LD (%s), A", _result );
    outline1("JMP %sfinal", label );
    outhead1("%sdiff:", label );
    outline1("LD A, $%2.2x", _equal ? 0 : 255 );
    outline1("LD (%s), A", _result );
    outhead1("%sfinal:", label );

}

void cpu_less_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD HL, (%s)", _source);
    outline1("LD DE, (%s)", _destination);
    outline1("LD A, (%s)", _size);
    outline0("LD C, A");
    outhead1("%s:", label );
    outline0("LD A, (DE)");
    outline0("LD B, A");
    outline0("LD A, (HL)");
    outline0("CP B");
    if ( _equal ) {
        outline1("JR Z, %seq", label);
    }
    outline1("JR NC, %sdiff", label);
    if ( ! _equal ) {
        outline1("JR Z, %sdiff", label);
    }
    outhead1("%seq:", label );
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

void cpu_less_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD HL, (%s)", _source);
    outline1("LD DE, (%s)",_destination);
    outline1("LD A, $%2.2x", ( _size & 0xff ) );
    outline0("LD C, A");
    outhead1("%s:", label );
    outline0("LD A, (DE)");
    outline0("LD B, A");
    outline0("LD A, (HL)");
    outline0("CP B");
    if ( _equal ) {
        outline1("JR Z, %seq", label);
    }
    outline1("JR NC, %sdiff", label);
    if ( ! _equal ) {
        outline1("JR Z, %sdiff", label);
    }
    outhead1("%seq:", label );
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

void cpu_greater_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD HL, (%s)", _source);
    outline1("LD DE, (%s)", _destination);
    outline1("LD A, (%s)", _size);
    outline0("LD C, A");
    outhead1("%s:", label );
    outline0("LD A, (DE)");
    outline0("LD B, A");
    outline0("LD A, (HL)");
    outline0("CP B");
    if ( !_equal ) {
        outline1("JR Z, %sdiff", label);
    }
    outline1("JR C, %sdiff", label);
    outline0("INC DE");
    outline0("INC HL");
    outline0("DEC C");
    outline1("JR NZ, %s", label);
    outline1("LD A, $%2.2x", 255 );
    outline1("LD (%s), A", _result );
    outline1("JMP %sfinal", label );
    outhead1("%sdiff:", label );
    outline1("LD A, $%2.2x", 0 );
    outline1("LD (%s), A", _result );
    outhead1("%sfinal:", label );

}

void cpu_greater_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD HL, (%s)", _source);
    outline1("LD DE, (%s)", _destination);
    outline1("LD A, $%2.2x", ( _size & 0xff ) );
    outline0("LD C, A");
    outhead1("%s:", label );
    outline0("LD A, (DE)");
    outline0("LD B, A");
    outline0("LD A, (HL)");
    outline0("CP B");
    if ( ! _equal ) {
        outline1("JR Z, %sdiff", label);
    }
    outline1("JR C, %sdiff", label);
    outline0("INC DE");
    outline0("INC HL");
    outline0("DEC C");
    outline1("JR NZ, %s", label);
    outline1("LD A, $%2.2x", 255 );
    outline1("LD (%s), A", _result );
    outline1("JMP %sfinal", label );
    outhead1("%sdiff:", label );
    outline1("LD A, $%2.2x", 0 );
    outline1("LD (%s), A", _result );
    outhead1("%sfinal:", label );

}

void cpu_math_add_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

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

void cpu_math_sub_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    outline1("LD HL, (%s)", _source );
    outline0("LD DE, 0" );
    outline1("LD A, (%s)", _destination );
    outline0("LD E, A" );
    outline0("SBC HL, DE" );
    if ( _other ) {
        outline1("LD (%s), HL", _other );
    } else {
        outline1("LD (%s), HL", _destination );
    }

}

void cpu_uppercase( Environment * _environment, char *_source, char *_size, char *_result ) {

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
    outline1("JP %sdone", label );

    outhead1("%snext:", label );
    outline0("LD (DE), A" );
    outhead1("%sdone:", label );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("DEC C" );
    outline0("LD A, C" );
    outline0("CP 0" );
    outline1("JR NZ, %supper", label);

}

void cpu_lowercase( Environment * _environment, char *_source, char *_size, char *_result ) {

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

    outline0("CP 91");
    outline1("JR NC, %snext", label);

    outline0("ADC A, 31");
    outline0("LD (DE), A" );
    outline1("JP %sdone", label );
    outhead1("%snext:", label );
    outline0("LD (DE), A" );
    outhead1("%sdone:", label );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("DEC C" );
    outline0("LD A, C" );
    outline0("CP 0" );
    outline1("JR NZ, %slower", label);

}

void cpu_convert_string_into_8bit( Environment * _environment, char * _string, char * _len, char * _value ) {

    Variable * temp = variable_temporary( _environment, VT_WORD, "(temp)" );

    cpu_convert_string_into_16bit( _environment, _string, _len, temp->realName );

    cpu_move_8bit( _environment, temp->realName, _value );
  
}

void cpu_convert_string_into_16bit( Environment * _environment, char * _string, char * _len, char * _value ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _len );
    outline0("LD IX, 0" );
    outline0("LD IXL, A" );

    outline0("LD A, 0" );
    outline1("LD (%s), A", _value );
    outline1("LD (%s+1), A", _value );

    outline1("LD HL, (%s)", _string );

    outhead1("%srepeat:", label );

    outline0("LD A, (HL)" );
    outline0("CP $40" );
    outline1("JR NC, %send", label);
    outline0("CP $30" );
    outline1("JR C, %send", label);
    outline0("SBC A, $30" );

    outline0("PUSH AF" );
    outline1("LD A, (%s)", address_displacement(_environment, _value, "1") );
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

void cpu_fill_indirect( Environment * _environment, char * _address, char * _size, char * _pattern, int _size_size ) {

    MAKE_LABEL

    // Use the current bitmap address as starting address for filling routine.
    outline1("LD DE, (%s)", _address);
    outline1("LD HL, (%s)", _pattern);

    // Fill the bitmap with the given pattern.
    if ( _size_size >= 16 ) {
        outline1("LD A, (%s)", _size);
        outline0("LD C, A" );
        outline1("LD A, (%s+1)", _size);
        outline0("LD B, A" );
        outhead1("%sx:", label);
        outline0("LD A, (HL)");
        outline0("LD (DE),A");
        outline0("INC DE");
        outline0("DEC BC");
        outline0("LD A, B");
        outline0("OR C");
        outline1("JR NZ,%sx", label);
    } else {
        outline1("LD A, (%s)", _size);
        outline0("LD C, A" );
        outhead1("%sx:", label);
        outline0("LD A, (HL)");
        outline0("LD (DE),A");
        outline0("INC DE");
        outline0("DEC C");
        outline1("JR NZ,%sx", label);
    }

}

void cpu_flip( Environment * _environment, char * _source, char * _size, char * _destination ) {

    no_inline( cpu_flip )

    embedded( cpu_flip, src_hw_z80_cpu_flip_asm );

        outline1("LD HL, (%s)", _source);
        outline1("LD DE, (%s)", _destination);
        outline1("LD A, (%s)", _size);
        outline0("CALL CPUFLIP");

    done(  )

}

void cpu_move_8bit_indirect( Environment * _environment, char *_source, char * _value ) {

    outline1("LD DE, (%s)", _value);
    outline1("LD A, (%s)", _source);
    outline0("LD (DE), A");

}

void cpu_move_8bit_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

    outline1("LD HL, %s", _value);
    outline1("LD A, (%s)", _offset );
    outline0("LD E, A" );
    outline0("LD D, 0" );
    outline0("ADD HL, DE" );
    outline1("LD A, (%s)", _source);
    outline0("LD (HL), A");

}

void cpu_move_8bit_indirect_with_offset( Environment * _environment, char *_source, char * _value, int _offset ) {

    outline1("LD HL, (%s)", _value);
    outline1("LD DE, $%2.2x", ( _offset & 0xff ) );
    outline0("ADD HL, DE" );
    outline1("LD A, (%s)", _source);
    outline0("LD (HL), A");

}

void cpu_move_8bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    outline1("LD DE, (%s)", _value);
    outline0("LD A, (DE)");
    outline1("LD (%s), A", _source);

}

void cpu_move_8bit_indirect2_8bit( Environment * _environment, char * _value, char * _offset, char *_source ) {

    outline1("LD HL, %s", _value);
    outline1("LD A, (%s)", _offset);
    outline0("LD E, A");
    outline0("LD D, 0");
    outline0("ADD HL, DE");
    outline0("LD A, (HL)");
    outline1("LD (%s), A", _source );

}

void cpu_move_8bit_indirect2_16bit( Environment * _environment, char * _value, char * _offset, char *_source ) {

    outline1("LD HL, %s", _value);
    outline1("LD DE, (%s)", _offset);
    outline0("ADD HL, DE");
    outline0("LD A, (HL)");
    outline1("LD (%s), A", _source );

}

void cpu_move_16bit_indirect( Environment * _environment, char *_source, char * _value ) {

    outline1("LD DE, (%s)", _value);
    outline1("LD HL, (%s)", _source);
    outline0("LD A, L");
    outline0("LD (DE), A");
    outline0("INC DE");
    outline0("LD A, H");
    outline0("LD (DE), A");

}

void cpu_move_16bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    outline1("LD DE, (%s)", _value);
    outline0("LD A, (DE)");
    outline1("LD (%s), A", _source);
    outline0("INC DE");
    outline0("LD A, (DE)");
    outline1("LD (%s), A", address_displacement(_environment, _source, "1"));

}

void cpu_move_16bit_indirect2_8bit( Environment * _environment, char * _value, char * _offset, char *_source ) {

    outline1("LD HL, %s", _value);
    outline1("LD A, (%s)", _offset);
    outline0("LD E, A");
    outline0("LD A, 0");
    outline0("LD D, A");
    outline0("ADD HL, DE");
    outline0("ADD HL, DE");
    outline0("LD A, (HL)");
    outline1("LD (%s), A", _source );
    outline0("INC HL");
    outline0("LD A, (HL)");
    outline1("LD (%s), A", address_displacement(_environment, _source, "1") );

}

void cpu_move_32bit_indirect( Environment * _environment, char *_source, char * _value ) {

    outline1("LD DE, (%s)", _value);
    outline1("LD HL, (%s)", _source);
    outline0("LD A, L");
    outline0("LD (DE), A");
    outline0("INC DE");
    outline0("LD A, H");
    outline0("LD (DE), A");
    outline0("INC DE");
    outline1("LD HL, (%s)", address_displacement(_environment, _source, "2"));
    outline0("LD A, L");
    outline0("LD (DE), A");
    outline0("INC DE");
    outline0("LD A, H");
    outline0("LD (DE), A");
    outline0("INC DE");

}

void cpu_move_nbit_indirect( Environment * _environment, int _n, char *_source, char * _value ) {

    outline1("LD DE, (%s)", _value);

    char step[MAX_TEMPORARY_STORAGE];
    char step2[MAX_TEMPORARY_STORAGE];

    int stepIndex = 0;
    while( _n ) {
        sprintf( step, "%d", stepIndex );
        sprintf( step2, "%d", stepIndex+2 );
        if ( _n >= 32 ) {
            outline1("LD HL, (%s)", address_displacement(_environment, _source, step));
            outline0("LD A, L");
            outline0("LD (DE), A");
            outline0("INC DE");
            outline0("LD A, H");
            outline0("LD (DE), A");
            outline0("INC DE");
            outline1("LD HL, (%s)", address_displacement(_environment, _source, step2));
            outline0("LD A, L");
            outline0("LD (DE), A");
            outline0("INC DE");
            outline0("LD A, H");
            outline0("LD (DE), A");
            outline0("INC DE");
            stepIndex += 4;
            _n -= 32;
        } else {
            switch( _n ) {
                case 32: case 31: case 30: case 29:
                case 28: case 27: case 26: case 25:
                    outline1("LD HL, (%s)", address_displacement(_environment, _source, step));
                    outline0("LD A, L");
                    outline0("LD (DE), A");
                    outline0("INC DE");
                    outline0("LD A, H");
                    outline0("LD (DE), A");
                    outline0("INC DE");
                    outline1("LD HL, (%s)", address_displacement(_environment, _source, step2));
                    outline0("LD A, L");
                    outline0("LD (DE), A");
                    outline0("INC DE");
                    outline0("LD A, H");
                    outline0("LD (DE), A");
                    outline0("INC DE");
                    break;
                case 24: case 23: case 22: case 21:
                case 20: case 19: case 18: case 17:
                    outline1("LD HL, (%s)", address_displacement(_environment, _source, step));
                    outline0("LD A, L");
                    outline0("LD (DE), A");
                    outline0("INC DE");
                    outline0("LD A, H");
                    outline0("LD (DE), A");
                    outline0("INC DE");
                    outline1("LD A, (%s)", address_displacement(_environment, _source, step2));
                    outline0("LD (DE), A");
                    outline0("INC DE");
                    break;
                case 16: case 15: case 14: case 13:
                case 12: case 11: case 10: case 9:
                    outline1("LD HL, (%s)", address_displacement(_environment, _source, step));
                    outline0("LD A, L");
                    outline0("LD (DE), A");
                    outline0("INC DE");
                    outline0("LD A, H");
                    outline0("LD (DE), A");
                    outline0("INC DE");
                    break;
                case 8: case 7: case 6: case 5:
                case 4: case 3: case 2: case 1:
                    outline1("LD A, (%s)", address_displacement(_environment, _source, step));
                    outline0("LD (DE), A");
                    outline0("INC DE");
                    break;
            }
            _n = 0;
        }
    }
}

void cpu_move_32bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    outline1("LD DE, (%s)", _value);
    outline0("LD A, (DE)");
    outline0("LD L, A");
    outline0("INC DE");
    outline0("LD A, (DE)");
    outline0("LD H, A");
    outline0("INC DE");
    outline1("LD (%s), HL", _source);
    outline0("LD A, (DE)");
    outline0("LD L, A");
    outline0("INC DE");
    outline0("LD A, (DE)");
    outline0("LD H, A");
    outline0("INC DE");
    outline1("LD (%s), HL", address_displacement( _environment, _source, "2" ) );

}

void cpu_move_nbit_indirect2( Environment * _environment, int _n, char * _value, char *_source ) {

    outline1("LD DE, (%s)", _value);

    char step[MAX_TEMPORARY_STORAGE];
    char step2[MAX_TEMPORARY_STORAGE];

    int stepIndex = 0;
    while( _n ) {
        sprintf( step, "%d", stepIndex );
        sprintf( step2, "%d", stepIndex+2 );
        if ( _n >= 32 ) {
            outline0("LD A, (DE)");
            outline0("LD L, A");
            outline0("INC DE");
            outline0("LD A, (DE)");
            outline0("LD H, A");
            outline0("INC DE");
            outline1("LD (%s), HL", address_displacement( _environment, _source, step ) );
            outline0("LD A, (DE)");
            outline0("LD L, A");
            outline0("INC DE");
            outline0("LD A, (DE)");
            outline0("LD H, A");
            outline0("INC DE");
            outline1("LD (%s), HL", address_displacement( _environment, _source, step2 ) );
            stepIndex += 4;
            _n -= 32;
        } else {
            switch( _n ) {
                case 32: case 31: case 30: case 29:
                case 28: case 27: case 26: case 25:
                    outline0("LD A, (DE)");
                    outline0("LD L, A");
                    outline0("INC DE");
                    outline0("LD A, (DE)");
                    outline0("LD H, A");
                    outline0("INC DE");
                    outline1("LD (%s), HL", address_displacement( _environment, _source, step ) );
                    outline0("LD A, (DE)");
                    outline0("LD L, A");
                    outline0("INC DE");
                    outline0("LD A, (DE)");
                    outline0("LD H, A");
                    outline0("INC DE");
                    outline1("LD (%s), HL", address_displacement( _environment, _source, step2 ) );
                    break;
                case 24: case 23: case 22: case 21:
                case 20: case 19: case 18: case 17:
                    outline0("LD A, (DE)");
                    outline0("LD L, A");
                    outline0("INC DE");
                    outline0("LD A, (DE)");
                    outline0("LD H, A");
                    outline0("INC DE");
                    outline1("LD (%s), HL", address_displacement( _environment, _source, step ) );
                    outline0("LD A, (DE)");
                    outline0("INC DE");
                    outline1("LD (%s), A", address_displacement( _environment, _source, step2 ) );
                    break;
                case 16: case 15: case 14: case 13:
                case 12: case 11: case 10: case 9:
                    outline0("LD A, (DE)");
                    outline0("LD L, A");
                    outline0("INC DE");
                    outline0("LD A, (DE)");
                    outline0("LD H, A");
                    outline0("INC DE");
                    outline1("LD (%s), HL", address_displacement( _environment, _source, step ) );
                    break;
                case 8: case 7: case 6: case 5:
                case 4: case 3: case 2: case 1:
                    outline0("LD A, (DE)");
                    outline0("INC DE");
                    outline1("LD (%s), A", address_displacement( _environment, _source, step ) );
                    break;
            }
            _n = 0;
        }
    }

}

void cpu_math_div_32bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        outline1("LD A, (%s)", address_displacement(_environment, _source, "3"));
        outline0("AND $80");
        outline0("CP 0" );
        outline0("PUSH AF");
        outline1("JR Z,%spositive", label);
        cpu_complement2_32bit( _environment, _source, NULL );
        outhead1("%spositive:", label);
        outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
        outline0("AND $80");
        outline0("CP 0" );
        outline0("PUSH AF");
        outline1("JR Z,%spositive2", label);
        cpu_complement2_16bit( _environment, _destination, NULL );
        outhead1("%spositive2:", label);

        // outline1("LD HL, %s", _source);
        // outline0("LD A, (HL)");
        // outline0("PUSH AF");
        // outline0("POP IX");
        // outline0("INC HL");
        // outline0("INC HL");
        // outline0("LD A, (HL)");
        // outline0("LD C, A");
        // outline0("INC HL");
        // outline0("LD A, (HL)");
        // outline1("LD DE, (%s)", _destination);

        // outline0("LD HL, 0");
        // outline0("LD B, 32");
        // outhead1("%sloop:", label);
        // outline0("ADD IX, IX");
        // outline0("RL C");
        // outline0("RLA");
        // outline0("ADC HL, HL");
        // outline1("JR C, %soverflow", label);
        // outline0("SBC HL, DE");
        // outline1("JR NC, %ssetbit", label);
        // outline0("ADD HL, DE");
        // outline1("DJNZ %sloop", label);
        // outline1("JMP %send", label);
        // outhead1("%soverflow:", label);
        // outline0("OR A");
        // outline0("SBC HL, DE");
        // outhead1("%ssetbit:", label);
        // outline0("INC IXL");
        // outline1("DJNZ %sloop", label);
        // outhead1("%send:", label);
        // outline1("LD (%s), HL", _other_remainder);
        // outline1("LD HL, %s", _other);
        // outline0("PUSH AF");
        // outline0("PUSH IX");
        // outline0("POP AF");
        // outline0("LD (HL), A");
        // outline0("POP AF");
        // outline0("INC HL");
        // outline0("INC HL");
        // outline0("INC HL");
        // outline0("LD (HL), A");
        // outline0("DEC HL");
        // outline0("LD C, (HL)");

        outline1("LD A, (%s)", _destination);
        outline0("LD E, A");
        outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
        outline0("LD D, A");
        outline1("LD IX, (%s)", _source);
        outline1("LD A, (%s)", address_displacement(_environment, _source, "2"));
        outline0("LD C, A");
        outline1("LD A, (%s)", address_displacement(_environment, _source, "3"));

        outline0("LD HL, 0");
        outline0("LD B, 32");
        outhead1("%sdiv32a:", label);
        outline0("ADD IX, IX");
        outline0("RL C");
        outline0("RLA");
        outline0("ADC HL, HL");
        outline1("JR C, %sdiv32ov", label);
        outline0("SBC HL, DE");
        outline1("JR NC, %sdiv32setbit", label);
        outline0("ADD HL, DE");
        outline1("DJNZ %sdiv32a", label);
        outline1("JR %sdiv32end", label);
        outhead1("%sdiv32ov:", label);
        outline0("OR A");
        outline0("SBC HL, DE");
        outhead1("%sdiv32setbit:", label);
        outline0("INC IX");
        outline1("DJNZ %sdiv32a", label);
        outhead1("%sdiv32end:", label);

        outline1("LD (%s), A", address_displacement(_environment, _other, "3"));
        outline0("LD A, C" );
        outline1("LD (%s), A", address_displacement(_environment, _other, "2"));
        outline1("LD (%s), IX", _other);
        outline0("LD A, L");
        outline1("LD (%s), A", _other_remainder);
        outline0("LD A, H");
        outline1("LD (%s), A", address_displacement(_environment, _other_remainder, "1"));

        outline0("POP AF");
        outline0("LD B, A");
        outline0("CMP $80");
        outline1("JR NZ, %srepositive", label);
        cpu_complement2_16bit( _environment, _destination, NULL );
        outhead1("%srepositive:", label);
        outline0("POP AF");
        outline0("LD C, A");
        outline0("CMP $80");
        outline1("JR NZ, %srepositive2", label );
        cpu_complement2_32bit( _environment, _source, NULL );
        outhead1("%srepositive2:", label);
        outline0("LD A, B");
        outline0("XOR C");
        outline0("AND $80");
        outline0("CP $80");
        outline1("JR NZ, %srepositive3", label );
        cpu_complement2_32bit( _environment, _other, NULL );
        outhead1("%srepositive3:", label);

    } else {

        // outline1("LD HL, %s", _source);
        // outline0("LD A, (HL)");
        // outline0("PUSH AF");
        // outline0("POP IX");
        // outline0("INC HL");
        // outline0("INC HL");
        // outline0("LD A, (HL)");
        // outline0("LD C, A");
        // outline0("INC HL");
        // outline0("LD A, (HL)");
        // outline1("LD DE, (%s)", _destination);

        // outline0("LD HL, 0");
        // outline0("LD B, 32");
        // outhead1("%sloop:", label);
        // outline0("ADD IX, IX");
        // outline0("RL C");
        // outline0("RLA");
        // outline0("ADC HL, HL");
        // outline1("JR C, %soverflow", label);
        // outline0("SBC HL, DE");
        // outline1("JR NC, %ssetbit", label);
        // outline0("ADD HL, DE");
        // outline1("DJNZ %sloop", label);
        // outline1("JMP %send", label);
        // outhead1("%soverflow:", label);
        // outline0("OR A");
        // outline0("SBC HL, DE");
        // outhead1("%ssetbit:", label);
        // outline0("INC IXL");
        // outline1("DJNZ %sloop", label);
        // outhead1("%send:", label);
        // outline1("LD (%s), HL", _other_remainder);
        // outline1("LD HL, %s", _other);
        // outline0("PUSH AF");
        // outline0("PUSH IX");
        // outline0("POP AF");
        // outline0("LD (HL), A");
        // outline0("POP AF");
        // outline0("INC HL");
        // outline0("INC HL");
        // outline0("INC HL");
        // outline0("LD (HL), A");
        // outline0("DEC HL");
        // outline0("LD C, (HL)");
        // ; IN:	ACIX=dividend, DE=divisor
        // ; OUT:	ACIX=quotient, DE=divisor, HL=remainder, B=0

	    outline1("LD HL, (%s)", _source);
	    outline0("LD IX, HL");
	    outline1("LD HL, (%s)", address_displacement(_environment, _source, "2"));
	    outline0("LD A, L");
	    outline0("LD C, A");
	    outline0("LD A, H");
	    outline1("LD DE, (%s)", _destination);

	    outline0("LD HL, 0");
        outline0("LD B, 32");
        outhead1("%sloop1:", label);
        outline0("ADD IX, IX");
        outline0("RL C");
        outline0("RLA");
        outline0("ADC HL, HL");
        outline1("JR C, %sloop2", label);
        outline0("SBC HL, DE");
        outline1("JR NC, %sloop3", label);
        outline0("ADD HL, DE");
        outline1("DJNZ %sloop1", label);
        outline1("JR %sdone", label);
        outhead1("%sloop2:", label);
        outline0("OR A");
        outline0("SBC HL, DE");
        outhead1("%sloop3:", label);
        outline0("INC IXL");
        outline1("DJNZ %sloop1", label);
        outhead1("%sdone:", label);

	    outline1("LD (%s), HL", _other_remainder);
	    outline0("LD H, A");
	    outline0("LD A, C");
	    outline0("LD L, C");
	    outline1("LD (%s), HL", _other);
	    outline0("LD HL, IX");
	    outline1("LD (%s), HL", _other);

    }
 
}

void cpu_math_div_nbit_to_nbit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _bits ) {

    MAKE_LABEL

    int i;

    inline( cpu_math_div_nbit_to_nbit )

        char afterLabel[MAX_TEMPORARY_STORAGE]; sprintf( afterLabel, "%safter", label );
        char skipLabel[MAX_TEMPORARY_STORAGE]; sprintf( skipLabel, "%sskip", label );
        char skip2Label[MAX_TEMPORARY_STORAGE]; sprintf( skip2Label, "%sskipb", label );
        char skip3Label[MAX_TEMPORARY_STORAGE]; sprintf( skip3Label, "%sskipc", label );
        char skip4Label[MAX_TEMPORARY_STORAGE]; sprintf( skip4Label, "%sskipd", label );
        char quotient[MAX_TEMPORARY_STORAGE]; sprintf( quotient, "CPUMATHDIVNBITTONBIT%d_QUOTIENT", _bits >> 3 );
        char divisor[MAX_TEMPORARY_STORAGE]; sprintf( divisor, "CPUMATHDIVNBITTONBIT%d_DIVISOR", _bits >> 3 );
        char dividend[MAX_TEMPORARY_STORAGE]; sprintf( dividend, "CPUMATHDIVNBITTONBIT%d_DIVIDEND", _bits >> 3 );
        char result1[MAX_TEMPORARY_STORAGE]; sprintf( result1, "CPUMATHDIVNBITTONBIT%d_RESULT1", _bits >> 3 );
        char result2[MAX_TEMPORARY_STORAGE]; sprintf( result2, "CPUMATHDIVNBITTONBIT%d_RESULT2", _bits >> 3 );
        char k[MAX_TEMPORARY_STORAGE]; sprintf( k, "CPUMATHDIVNBITTONBIT%d_K", _bits >> 3 );

        if ( ! _environment->cpuOptimization.cpu_math_div_nbit_to_nbit[_bits>>3] ) {

            cpu_jump( _environment, afterLabel );

            outhead2("%s: defs %d", quotient, _bits>>3 );
            outhead2("%s: defs %d", divisor, _bits>>3 );
            outhead2("%s: defs %d", dividend, _bits>>3 );
            outhead1("%s: db 0", k );
            outhead1("%s: db 0", result1 );
            outhead1("%s: db 0", result2 );

            // public static long div(long dividend, long divisor) {
            //     long quotient = 0;

            outhead1("CPUMATHDIVNBITTONBIT%d:", _bits>>3);
            outhead0("LD A, $00");
            for( i=0; i<(_bits>>3); ++i ) {
                char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
                outline1("LD (%s), A", address_displacement( _environment, quotient, offset ) );
            }

            //     int k = 0;
            cpu_store_8bit( _environment, k, 0 );

            //     while (divisor <= dividend && divisor > 0) {

            cpu_label( _environment, label );
            cpu_less_than_nbit( _environment, divisor, dividend, result1, 1, _bits );
            cpu_greater_than_nbit_const( _environment, divisor, 0, result2, 0, _bits );
            cpu_and_8bit( _environment, result1, result2, result1 );
            cpu_compare_and_branch_8bit_const( _environment, result1, 0, skipLabel, 1 );

            //         divisor <<= 1;

            cpu_math_mul2_const_nbit( _environment, divisor, 1, _bits );

            //         k++;

            cpu_inc( _environment, k );

            //     }

            cpu_jump( _environment, label );

            cpu_label( _environment, skipLabel );

            //     while (k-- > 0) {

            cpu_greater_than_8bit_const( _environment, k, 0, result1, 0, 1 );
            cpu_dec( _environment, k );
            cpu_compare_and_branch_8bit_const( _environment, result1, 0, skip2Label, 1 );

            //         divisor >>= 1;

            cpu_math_div2_const_nbit( _environment, divisor, 1, _bits, NULL );

            //         if (divisor <= dividend) {
            cpu_less_than_nbit( _environment, divisor, dividend, result1, 1, _bits );
            cpu_compare_and_branch_8bit_const( _environment, result1, 0, skip3Label, 1 );

            //             dividend -= divisor;

            cpu_math_sub_nbit( _environment, dividend, divisor, dividend, _bits );

            //             quotient = (quotient << 1) + 1;
            cpu_math_mul2_const_nbit( _environment, quotient, 1, _bits );
            cpu_inc_nbit( _environment, quotient, _bits );

            //         }
            cpu_jump( _environment, skip4Label );
            cpu_label( _environment, skip3Label );
            //         else quotient <<= 1;
            cpu_math_mul2_const_nbit( _environment, quotient, 1, _bits );
            cpu_label( _environment, skip4Label );
            cpu_jump( _environment, skipLabel );

            //     }
            cpu_label( _environment, skip2Label );
            //     return quotient;
            cpu_return( _environment );

            cpu_label( _environment, afterLabel );

        }

        for( i=0; i<(_bits>>3); ++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
            outline1("LD A, (%s)", address_displacement( _environment, _source, offset ) );
            outline1("LD (%s), A", address_displacement( _environment, dividend, offset ) );
            outline1("LD A, (%s)", address_displacement( _environment, _destination, offset ) );
            outline1("LD (%s), A", address_displacement( _environment, divisor, offset ) );
        }
        outline1("CALL CPUMATHDIVNBITTONBIT%d", _bits>>3);

        for( i=0; i<(_bits>>3); ++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
            if ( _other ) {
                outline1("LD A, (%s)", address_displacement( _environment, quotient, offset ) );
                outline1("LD (%s), A", address_displacement( _environment, _other, offset ) );
            } else {
                outline1("LD A, (%s)", address_displacement( _environment, quotient, offset ) );
                outline1("LD (%s), A", address_displacement( _environment, _destination, offset ) );            
            }
        }

        // }
    no_embedded( cpu_math_div_nbit_to_nbit )

}

void cpu_math_div_32bit_to_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        int destination = abs(_destination);

        outline1("LD A, (%s)", address_displacement(_environment, _source, "3"));
        outline0("AND $80");
        outline0("CP 0" );
        outline0("PUSH AF");
        outline1("JR Z,%spositive", label);
        cpu_complement2_32bit( _environment, _source, NULL );
        outhead1("%spositive:", label);
        // outline1("LD A, $%2.2x", (unsigned char)( (_destination >> 8 ) & 0xff ));
        // outline0("AND $80");
        // outline0("CP 0" );
        // outline0("PUSH AF");
        // outline1("JR Z,%spositive2", label);
        // cpu_complement2_16bit( _environment, _destination, NULL );
        // outhead1("%spositive2:", label);

        // outline1("LD HL, %s", _source);
        // outline0("LD A, (HL)");
        // outline0("PUSH AF");
        // outline0("POP IX");
        // outline0("INC HL");
        // outline0("INC HL");
        // outline0("LD A, (HL)");
        // outline0("LD C, A");
        // outline0("INC HL");
        // outline0("LD A, (HL)");
        // outline1("LD DE, (%s)", _destination);

        // outline0("LD HL, 0");
        // outline0("LD B, 32");
        // outhead1("%sloop:", label);
        // outline0("ADD IX, IX");
        // outline0("RL C");
        // outline0("RLA");
        // outline0("ADC HL, HL");
        // outline1("JR C, %soverflow", label);
        // outline0("SBC HL, DE");
        // outline1("JR NC, %ssetbit", label);
        // outline0("ADD HL, DE");
        // outline1("DJNZ %sloop", label);
        // outline1("JMP %send", label);
        // outhead1("%soverflow:", label);
        // outline0("OR A");
        // outline0("SBC HL, DE");
        // outhead1("%ssetbit:", label);
        // outline0("INC IXL");
        // outline1("DJNZ %sloop", label);
        // outhead1("%send:", label);
        // outline1("LD (%s), HL", _other_remainder);
        // outline1("LD HL, %s", _other);
        // outline0("PUSH AF");
        // outline0("PUSH IX");
        // outline0("POP AF");
        // outline0("LD (HL), A");
        // outline0("POP AF");
        // outline0("INC HL");
        // outline0("INC HL");
        // outline0("INC HL");
        // outline0("LD (HL), A");
        // outline0("DEC HL");
        // outline0("LD C, (HL)");

        outline1("LD DE, $%4.4x", destination);
        outline1("LD IX, (%s)", _source);
        outline1("LD A, (%s)", address_displacement(_environment, _source, "2"));
        outline0("LD C, A");
        outline1("LD A, (%s)", address_displacement(_environment, _source, "3"));

        outline0("LD HL, 0");
        outline0("LD B, 32");
        outhead1("%sdiv32a:", label);
        outline0("ADD IX, IX");
        outline0("RL C");
        outline0("RLA");
        outline0("ADC HL, HL");
        outline1("JR C, %sdiv32ov", label);
        outline0("SBC HL, DE");
        outline1("JR NC, %sdiv32setbit", label);
        outline0("ADD HL, DE");
        outline1("DJNZ %sdiv32a", label);
        outline1("JR %sdiv32end", label);
        outhead1("%sdiv32ov:", label);
        outline0("OR A");
        outline0("SBC HL, DE");
        outhead1("%sdiv32setbit:", label);
        outline0("INC IX");
        outline1("DJNZ %sdiv32a", label);
        outhead1("%sdiv32end:", label);

        outline1("LD (%s), A", address_displacement(_environment, _other, "3"));
        outline0("LD A, C" );
        outline1("LD (%s), A", address_displacement(_environment, _other, "2"));
        outline1("LD (%s), IX", _other);
        outline0("LD A, L");
        outline1("LD (%s), A", _other_remainder);
        outline0("LD A, H");
        outline1("LD (%s), A", address_displacement(_environment, _other_remainder, "1"));

        // outline0("POP AF");
        outline1("LD B, $%2.2x", (_destination < 0) ? 0x80 : 0x00 );
        // outline0("CMP $80");
        // outline1("JR NZ, %srepositive", label);
        // cpu_complement2_16bit( _environment, _destination, NULL );
        outhead1("%srepositive:", label);
        outline0("POP AF");
        outline0("LD C, A");
        outline0("CMP $80");
        outline1("JR NZ, %srepositive2", label );
        cpu_complement2_32bit( _environment, _source, NULL );
        outhead1("%srepositive2:", label);
        outline0("LD A, B");
        outline0("XOR C");
        outline0("AND $80");
        outline0("CP $80");
        outline1("JR NZ, %srepositive3", label );
        cpu_complement2_32bit( _environment, _other, NULL );
        outhead1("%srepositive3:", label);

    } else {

        // outline1("LD HL, %s", _source);
        // outline0("LD A, (HL)");
        // outline0("PUSH AF");
        // outline0("POP IX");
        // outline0("INC HL");
        // outline0("INC HL");
        // outline0("LD A, (HL)");
        // outline0("LD C, A");
        // outline0("INC HL");
        // outline0("LD A, (HL)");
        // outline1("LD DE, (%s)", _destination);

        // outline0("LD HL, 0");
        // outline0("LD B, 32");
        // outhead1("%sloop:", label);
        // outline0("ADD IX, IX");
        // outline0("RL C");
        // outline0("RLA");
        // outline0("ADC HL, HL");
        // outline1("JR C, %soverflow", label);
        // outline0("SBC HL, DE");
        // outline1("JR NC, %ssetbit", label);
        // outline0("ADD HL, DE");
        // outline1("DJNZ %sloop", label);
        // outline1("JMP %send", label);
        // outhead1("%soverflow:", label);
        // outline0("OR A");
        // outline0("SBC HL, DE");
        // outhead1("%ssetbit:", label);
        // outline0("INC IXL");
        // outline1("DJNZ %sloop", label);
        // outhead1("%send:", label);
        // outline1("LD (%s), HL", _other_remainder);
        // outline1("LD HL, %s", _other);
        // outline0("PUSH AF");
        // outline0("PUSH IX");
        // outline0("POP AF");
        // outline0("LD (HL), A");
        // outline0("POP AF");
        // outline0("INC HL");
        // outline0("INC HL");
        // outline0("INC HL");
        // outline0("LD (HL), A");
        // outline0("DEC HL");
        // outline0("LD C, (HL)");
        // ; IN:	ACIX=dividend, DE=divisor
        // ; OUT:	ACIX=quotient, DE=divisor, HL=remainder, B=0

	    outline1("LD HL, (%s)", _source);
	    outline0("LD IX, HL");
	    outline1("LD HL, (%s)", address_displacement(_environment, _source, "2"));
	    outline0("LD A, L");
	    outline0("LD C, A");
	    outline0("LD A, H");
	    outline1("LD DE, $%4.4x", _destination);

	    outline0("LD HL, 0");
        outline0("LD B, 32");
        outhead1("%sloop1:", label);
        outline0("ADD IX, IX");
        outline0("RL C");
        outline0("RLA");
        outline0("ADC HL, HL");
        outline1("JR C, %sloop2", label);
        outline0("SBC HL, DE");
        outline1("JR NC, %sloop3", label);
        outline0("ADD HL, DE");
        outline1("DJNZ %sloop1", label);
        outline1("JR %sdone", label);
        outhead1("%sloop2:", label);
        outline0("OR A");
        outline0("SBC HL, DE");
        outhead1("%sloop3:", label);
        outline0("INC IXL");
        outline1("DJNZ %sloop1", label);
        outhead1("%sdone:", label);

	    outline1("LD (%s), HL", _other_remainder);
	    outline0("LD H, A");
	    outline0("LD A, C");
	    outline0("LD L, C");
	    outline1("LD (%s), HL", _other);
	    outline0("LD HL, IX");
	    outline1("LD (%s), HL", _other);

    }
 
}

void cpu_math_div_nbit_to_nbit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _bits ) {

    MAKE_LABEL

    int i;
    
    inline( cpu_math_div_nbit_to_nbit )

        char afterLabel[MAX_TEMPORARY_STORAGE]; sprintf( afterLabel, "%safter", label );
        char data[MAX_TEMPORARY_STORAGE]; sprintf( data, "CPUMATHDIVNBITTONBITCONST%d_DATA", _bits >> 3 );

        if ( ! _environment->cpuOptimization.cpu_math_div_nbit_to_nbit_const[_bits>>3] ) {

            cpu_jump( _environment, afterLabel );

            outhead2("%s: defs %d", data, _bits>>3 );

            cpu_label( _environment, afterLabel );
            
        }

        for( i=0; i<(_bits>>3); ++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
            outline1("LD A, $%2.2x", (unsigned char)( (_destination >> (i*8)) & 0xff ) );
            outline1("LD (%s), A", address_displacement( _environment, data, offset ) );
        }
        cpu_math_div_nbit_to_nbit( _environment, _source, data, _other, _other_remainder, _bits );

        // }
    no_embedded( cpu_math_div_nbit_to_nbit )

}

void cpu_math_div_16bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
        outline0("AND $80");
        outline0("CP 0" );
        outline0("PUSH AF");
        outline1("JR Z,%spositive", label);
        cpu_complement2_16bit( _environment, _source, NULL );
        outhead1("%spositive:", label);
        outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
        outline0("AND $80");
        outline0("CP 0" );
        outline0("PUSH AF");
        outline1("JR Z,%spositive2", label);
        cpu_complement2_16bit( _environment, _destination, NULL );
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
        outline0("LD B, A");
        outline0("CMP $80");
        outline1("JR NZ, %srepositive", label);
        cpu_complement2_16bit( _environment, _destination, NULL );
        outhead1("%srepositive:", label);
        outline0("POP AF");
        outline0("LD C, A");
        outline0("CMP $80");
        outline1("JR NZ, %srepositive2", label );
        cpu_complement2_16bit( _environment, _source, NULL );
        outhead1("%srepositive2:", label);
        outline0("LD A, B");
        outline0("XOR C");
        outline0("AND $80");
        outline0("CP $80");
        outline1("JR NZ, %srepositive3", label );
        cpu_complement2_16bit( _environment, _other, NULL );
        outhead1("%srepositive3:", label);

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

void cpu_math_div_16bit_to_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        int destination = abs(_destination);

        outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
        outline0("AND $80");
        outline0("CP 0" );
        outline0("PUSH AF");
        outline1("JR Z,%spositive", label);
        cpu_complement2_16bit( _environment, _source, NULL );
        outhead1("%spositive:", label);
        // outline1("LD A, $%2.2x", (unsigned char)( (_destination>>8) & 0xff));
        // outline0("AND $80");
        // outline0("CP 0" );
        // outline0("PUSH AF");
        // outline1("JR Z,%spositive2", label);
        // cpu_complement2_16bit( _environment, _destination, NULL );
        // outhead1("%spositive2:", label);

        outline1("LD HL, %s", _source);
        outline0("LD A, (HL)");
        outline0("LD C, A");
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline1("LD DE, $%4.4x", destination);

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

        // outline0("POP AF");
        outline1("LD B, $%2.2x", _destination < 0 ? 0x80 : 0x00 );
        // outline0("CMP $80");
        // outline1("JR NZ, %srepositive", label);
        // cpu_complement2_16bit( _environment, _destination, NULL );
        outhead1("%srepositive:", label);
        outline0("POP AF");
        outline0("LD C, A");
        outline0("CMP $80");
        outline1("JR NZ, %srepositive2", label );
        cpu_complement2_16bit( _environment, _source, NULL );
        outhead1("%srepositive2:", label);
        outline0("LD A, B");
        outline0("XOR C");
        outline0("AND $80");
        outline0("CP $80");
        outline1("JR NZ, %srepositive3", label );
        cpu_complement2_16bit( _environment, _other, NULL );
        outhead1("%srepositive3:", label);

    } else {

        outline1("LD HL, %s", _source);
        outline0("LD A, (HL)");
        outline0("LD C, A");
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline1("LD DE, $%4.4x", _destination);

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

void cpu_math_div_8bit_to_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

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
        outline0("CP 0" );
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
        outline0("CP 0" );
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
        outline0("AND A");
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
        outline0("CP 0" );
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

void cpu_math_div_8bit_to_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        outline1("LD A, (%s)", _source );
        outline0("LD B, A" );
        outline1("LD A, $%2.2x", _destination );
        outline0("XOR A, B" );
        outline0("AND $80" );
        outline0("PUSH AF" );
        outline1("LD A, (%s)", _source );
        outline0("AND $80" );
        outline0("CP 0" );
        outline1("JR Z,%spos", label );
        outline1("LD A, (%s)", _source );
        outline0("XOR $FF" );
        outline0("ADC $1" );
        outline1("JMP %spos2", label );
        outhead1("%spos:", label );
        outline1("LD A, (%s)", _source );
        outhead1("%spos2:", label );
        outline0("LD D, A");
        
        outline1("LD A, $%2.2x", _destination );
        outline0("AND $80" );
        outline0("CP 0" );
        outline1("JR Z,%sposx", label );
        outline1("LD A, $%2.2x", _destination );
        outline0("XOR $FF" );
        outline0("ADC $1" );
        outline1("JMP %sposx2", label );
        outhead1("%sposx:", label );
        outline1("LD A, $%2.2x", _destination );
        outhead1("%sposx2:", label );
        outline0("LD E, A");

        outline0("XOR A");
        outline0("AND A");
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
        outline0("CP 0" );
        outline1("JR Z,%spos3", label );
        outline1("LD A, (%s)", _other );
        outline0("XOR $FF" );
        outline0("ADC $1" );
        outline1("LD (%s), A", _other );
        outhead1("%spos3:", label );
        
    } else {

        outline1("LD A, (%s)", _source);
        outline0("LD D, A");
        outline1("LD A, $%2.2x", _destination);
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

void cpu_bit_check( Environment * _environment, char *_value, int _position, char * _result, int _bitwidth ) {

    no_inline( cpu_bit_check_extended )

    embedded( cpu_bit_check_extended, src_hw_z80_cpu_bit_check_extended_asm );

        outline1("LD DE, %s", _value);
        outline1("LD A, $%2.2x", _position );
        outline0("CALL CPUBITCHECKEXTENDED" );

        if ( _result ) {
            outline1("LD (%s), A", _result);
        }

    done( )

}

void cpu_bit_check_extended( Environment * _environment, char *_value, char * _position, char * _result, int _bitwidth ) {

    MAKE_LABEL

    no_inline( cpu_bit_check_extended )

    embedded( cpu_bit_check_extended, src_hw_z80_cpu_bit_check_extended_asm );

        outline1("LD DE, %s", _value);
        outline1("LD A, (%s)", _position );
        outline0("CALL CPUBITCHECKEXTENDED" );

        if ( _result ) {
            outline1("LD (%s), A", _result);
        }

    done( )
    
}

void cpu_bit_inplace_8bit( Environment * _environment, char * _value, int _position, int * _bit ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    no_inline( cpu_bit_inplace )

    embedded( cpu_bit_inplace, src_hw_z80_cpu_bit_inplace_asm );

        if ( _bit ) {
            if ( * _bit ) {
                outline0("LD A, $ff" );
            } else {
                outline0("LD A, $0" );
            }
            outline0("SRL A" );
        }
        outline1("LD DE, %s", _value );
        outline1("LD A, $%2.2x", _position);
        outline0("CALL CPUBITINPLACE");

    done( )

}

void cpu_bit_inplace_8bit_extended_indirect( Environment * _environment, char * _address, char * _position, char * _bit ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    no_inline( cpu_bit_inplace )

    embedded( cpu_bit_inplace, src_hw_z80_cpu_bit_inplace_asm );

        if ( _bit ) {
            outline1("LD A, (%s)", _bit );
            outline0("CP $0" );
            outline1("JR Z, %s", label );
            outline0("LD A, 1" );;
            outline0("SRL A" );
            outhead1("%s:", label );
        }
        outline1("LD DE, (%s)", _address );
        outline1("LD A, (%s)", _position);
        outline0("CALL CPUBITINPLACE");

    done( )

}

void cpu_number_to_string_vars( Environment * _environment ) {

    variable_import( _environment, "N2DINV", VT_BUFFER, _environment->numberConfig.maxBytes );
    variable_import( _environment, "N2DBUF", VT_BUFFER, _environment->numberConfig.maxDigits );
    variable_import( _environment, "N2DEND", VT_BUFFER, 1 );

}

void cpu_number_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits, int _signed ) {

    MAKE_LABEL
        
    deploy_with_vars( numberToString, src_hw_z80_number_to_string_asm, cpu_number_to_string_vars );

    outline0("LD IXH, 0");
    switch( _bits ) {
        case 8:
            outline1("LD A, (%s)", _number);
            outline0("LD (N2DINV), A");
            if ( _signed ) {
                outline0("AND $80");
                outline0("CP 0");
                outline1("JR Z, %sp81", label);
                cpu_complement2_8bit( _environment, "N2DINV", NULL );
                outline0("LD IXH, 0xff");
                outhead1("%sp81:", label);
            }
            outline0("CALL N2D8");
            break;
        case 16:
            outline1("LD HL, (%s)", _number);
            outline0("LD (N2DINV), HL");
            if ( _signed ) {
                outline0("LD A, H");
                outline0("AND $80");
                outline0("CP 0");
                outline1("JR Z, %sp81", label);
                cpu_complement2_16bit( _environment, "N2DINV", NULL );
                outline0("LD IXH, 0xff");
                outhead1("%sp81:", label);
            }
            outline0("CALL N2D16");
            break;
        case 32:
            outline1("LD HL, (%s)", _number);
            outline0("LD (N2DINV), HL");
            outline1("LD HL, (%s)", address_displacement(_environment, _number, "2"));
            outline0("LD (N2DINV+2), HL");
            if ( _signed ) {
                outline0("LD A, H");
                outline0("AND $80");
                outline0("CP 0");
                outline1("JR Z, %sp81", label);
                cpu_complement2_32bit( _environment, "N2DINV", NULL  );
                outline0("LD IXH, 0xff");
                outhead1("%sp81:", label);
            }
            outline0("CALL N2D32");
            break;
        case 0:
            CRITICAL_DEBUG_UNSUPPORTED( _number, "unknown");
        default:
            cpu_mem_move_direct_size( _environment, _number, "N2DINV", _bits >> 3 );
            if ( _signed ) {
                outline1("LD A, (N2DINV+%d)", (_bits >> 3)-1 );
                outline0("AND $80");
                outline0("CP 0");
                outline1("JP Z, %sp81", label);
                cpu_complement2_nbit( _environment, "N2DINV", NULL, _bits  );
                outline0("LD IXH, 0xff");
                outhead1("%sp81:", label);
            }
            outline0("CALL N2STRING");
            break;
    }

    outline1("LD DE, (%s)", _string);
    outline0("LD A, IXH");
    outline0("CP 0");
    outline1("JR Z, %spos", label);
    outline0("LD A, '-'");
    outline0("LD (DE), A");
    outline0("INC DE");
    outline0("INC C");
    outhead1("%spos:", label);
    outline0("LD A, C");
    outline1("LD (%s), A", _string_size);
    outline0("LDIR");

}

void cpu_bits_to_string_vars( Environment * _environment ) {

    variable_import( _environment, "BINSTRBUF", VT_BUFFER, 32 );
    
}

void cpu_bits_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits ) {

    deploy_with_vars( bitsToString,src_hw_z80_bits_to_string_asm, cpu_bits_to_string_vars );

    switch( _bits ) {
        case 32:
            outline1("LD BC, (%s)", address_displacement(_environment, _number, "2") );
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

    outline1("LD A, $%2.2x", ( _bits & 0xff ) );
    outline0("CALL BINSTR");
    
    outline1("LD DE, (%s)", _string);
    outline1("LD A, $%2.2x", ( (_bits) & 0xff ) );
    outline0("LD C, A");
    outline0("LD B, 0");
    outline0("LDIR");

    outline1("LD A, $%2.2x", ( _bits & 0xff ) );
    outline1("LD HL, %s", _string_size );
    outline0("LD (HL), A" );

}

void cpu_hex_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits ) {

    MAKE_LABEL

    inline( cpu_hex_to_string )

    embedded( cpu_hex_to_string, src_hw_z80_cpu_hex_to_string_asm );

        outline1("LD A, $%2.2x", _bits);
        outline0("LD IXL, A");

        switch( _bits ) {
            case 8:
                outline1("LD A, (%s)", _number );
                outline0("LD L, A" );
                outline0("LD H, 0" );
                outline1("LD DE, (%s)", _string );

                outline0("CALL H2STRING" );
                break;
            case 16:

                outline1("LD HL, (%s)", _number );
                outline1("LD DE, (%s)", _string );

                outline0("CALL H2STRING" );
                break;

            case 32:

                outline1("LD HL, (%s)", address_displacement(_environment, _number, "2") );
                outline1("LD DE, (%s)", _string );

                outline0("CALL H2STRING" );

                outline1("LD HL, (%s)", _number );
                outline1("LD DE, (%s)", _string );
                outline0("INC DE" );
                outline0("INC DE" );
                outline0("INC DE" );
                outline0("INC DE" );

                outline0("CALL H2STRING" );
                break;

        }

        outline1("LD A, $%2.2x", ( _bits >> 2 ) );
        outline1("LD (%s), A", _string_size );

    done()

}


void cpu_dsdefine( Environment * _environment, char * _string, char * _index ) {

    deploy( dstring,src_hw_z80_dstring_asm );

    outline1( "LD HL, %s", _string );
    outline0( "CALL DSDEFINE" );
    outline0( "LD A, B" );
    outline1( "LD (%s), A", _index );
    
}

void cpu_dsalloc( Environment * _environment, char * _size, char * _index ) {

    deploy( dstring,src_hw_z80_dstring_asm );

    outline1( "LD A, (%s)", _size );
    outline0( "LD C, A" );
    outline0( "CALL DSALLOC" );
    outline0( "LD A, B" );
    outline1( "LD (%s), A", _index );

}

void cpu_dsalloc_size( Environment * _environment, int _size, char * _index ) {

    deploy( dstring,src_hw_z80_dstring_asm );

    outline1( "LD A, $%2.2x", ( _size & 0xff ) );
    outline0( "LD C, A" );
    outline0( "CALL DSALLOC" );
    outline0( "LD A, B" );
    outline1( "LD (%s), A", _index );

}

void cpu_dsfree( Environment * _environment, char * _index ) {

    deploy( dstring,src_hw_z80_dstring_asm );

    outline1( "LD A, (%s)", _index );
    outline0( "LD B, A" );
    outline0( "CALL DSFREE" );

}

void cpu_dswrite( Environment * _environment, char * _index ) {

    deploy( dstring,src_hw_z80_dstring_asm );

    outline1( "LD A, (%s)", _index );
    outline0( "LD B, A" );
    outline0( "CALL DSWRITE" );

}

void cpu_dsresize( Environment * _environment, char * _index, char * _resize ) {

    deploy( dstring,src_hw_z80_dstring_asm );

    outline1( "LD A, (%s)", _index );
    outline0( "LD B, A" );
    outline1( "LD A, (%s)", _resize );
    outline0( "LD C, A" );
    outline0( "CALL DSRESIZE" );

}

void cpu_dsresize_size( Environment * _environment, char * _index, int _resize ) {

    deploy( dstring,src_hw_z80_dstring_asm );

    outline1( "LD A, (%s)", _index );
    outline0( "LD B, A" );
    outline1( "LD A, $%2.2x", ( _resize & 0xff ) );
    outline0( "LD C, A" );
    outline0( "CALL DSRESIZE" );

}

void cpu_dsgc( Environment * _environment ) {

    deploy( dstring,src_hw_z80_dstring_asm );

    outline0( "CALL DSGC" );

}

void cpu_dsinit( Environment * _environment ) {

    deploy( dstring,src_hw_z80_dstring_asm );

    outline0( "CALL DSINIT" );

}

void cpu_dsdescriptor( Environment * _environment, char * _index, char * _address, char * _size ) {

    deploy( dstring,src_hw_z80_dstring_asm );

    if ( _address || _size ) {
        outline1( "LD A, (%s)", _index );
        outline0( "LD B, A" );
        outline0( "CALL DSDESCRIPTOR" );
        if ( _size ) {
            outline0( "LD A, (IX)" );
            outline1( "LD (%s), A", _size );
        }
        if ( _address ) {
            outline0( "LD A, (IX+1)" );
            outline1( "LD (%s), A", _address );
            outline0( "LD A, (IX+2)" );
            outline1( "LD (%s), A", address_displacement(_environment, _address, "1") );
        }
    }

}

void cpu_move_8bit_indirect_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

    outline1("LD HL, (%s)", _value);
    outline1("LD A, (%s)", _offset );
    outline0("LD E, A" );
    outline0("LD A, 0" );
    outline0("LD D, A" );
    outline0("ADD HL, DE" );
    outline1("LD A, (%s)", _source);
    outline0("LD (HL), A");

}

void cpu_complement2_8bit( Environment * _environment, char * _source, char * _destination ) {
    outline1( "LD A, (%s)", _source );
    outline0( "XOR $FF" );
    if ( _destination ) {
        outline1( "LD (%s), A", _destination );        
    } else {
        outline1( "LD (%s), A", _source );        
    }
    if ( _destination ) {
        cpu_inc( _environment, _destination );
    } else {
        cpu_inc( _environment, _source );
    }
}

void cpu_complement2_16bit( Environment * _environment, char * _source, char * _destination ) {
    outline1( "LD A, (%s)", _source );
    outline0( "XOR $FF" );
    if ( _destination ) {
        outline1( "LD (%s), A", _destination );        
    } else {
        outline1( "LD (%s), A", _source );        
    }
    outline1( "LD A, (%s)", address_displacement(_environment, _source, "1") );
    outline0( "XOR $FF" );
    if ( _destination ) {
        outline1( "LD (%s), A", address_displacement(_environment, _destination, "1") );        
    } else {
        outline1( "LD (%s), A", address_displacement(_environment, _source, "1") );        
    }
    if ( _destination ) {
        cpu_inc_16bit( _environment, _destination );
    } else {
        cpu_inc_16bit( _environment, _source );
    }
}

void cpu_complement2_32bit( Environment * _environment, char * _source, char * _destination ) {
    outline1( "LD A, (%s)", _source );
    outline0( "XOR $FF" );
    if ( _destination ) {
        outline1( "LD (%s), A", _destination );        
    } else {
        outline1( "LD (%s), A", _source );        
    }
    outline1( "LD A, (%s)", address_displacement(_environment, _source, "1") );
    outline0( "XOR $FF" );
    if ( _destination ) {
        outline1( "LD (%s), A", address_displacement(_environment, _destination, "1") );        
    } else {
        outline1( "LD (%s), A", address_displacement(_environment, _source, "1") );        
    }
    outline1( "LD A, (%s)", address_displacement(_environment, _source, "2") );
    outline0( "XOR $FF" );
    if ( _destination ) {
        outline1( "LD (%s), A", address_displacement(_environment, _destination, "2") );        
    } else {
        outline1( "LD (%s), A", address_displacement(_environment, _source, "2") );        
    }
    outline1( "LD A, (%s)", address_displacement(_environment, _source, "3") );
    outline0( "XOR $FF" );
    if ( _destination ) {
        outline1( "LD (%s), A", address_displacement(_environment, _destination, "3") );        
    } else {
        outline1( "LD (%s), A", address_displacement(_environment, _source, "3") );        
    } 
    if ( _destination ) {
        cpu_inc_32bit( _environment, _destination );
    } else {
        cpu_inc_32bit( _environment, _source );
    }
}

void cpu_complement2_nbit( Environment * _environment, char * _source, char * _destination, int _bits ) {

    for( int i=0; i<(_bits>>3); ++i ) {
        char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
        outline1( "LD A, (%s)", address_displacement(_environment, _source, offset) );
        outline0( "XOR $FF" );
        if ( _destination ) {
            outline1( "LD (%s), A", address_displacement(_environment, _destination, "1") );
        } else {
            outline1( "LD (%s), A", address_displacement(_environment, _source, "1") );
        }
    }
    if ( _destination ) {
        cpu_inc_nbit( _environment, _destination, _bits );
    } else {
        cpu_inc_nbit( _environment, _source, _bits );
    }

}

void cpu_sqroot( Environment * _environment, char * _number, char * _result ) {

    deploy( sqr, src_hw_z80_sqr_asm );

    outline1("LD HL, (%s)", _number );

    outline0("CALL SQROOT" );

    outline1("LD (%s),A", _result );

}

void cpu_dstring_vars( Environment * _environment ) {

    int count = _environment->dstring.count == 0 ? DSTRING_DEFAULT_COUNT : _environment->dstring.count;
    int space = _environment->dstring.space == 0 ? DSTRING_DEFAULT_SPACE : _environment->dstring.space;

#if !defined(__vg5000__) && !defined(__cpc__) && !defined(__c128z__) && !defined(__zx__) && !defined(__vz200__)
    outhead0("section data_user" );
#endif
    outhead1("stringscount =                  %d", count );
    outhead1("stringsspace =                  %d", space );
    outhead0("MAXSTRINGS:                   DB stringscount" );
    outhead0("DESCRIPTORS:                  DEFS stringscount*4" );
    outhead0("WORKING:                      DEFS stringsspace" );
    outhead0("TEMPORARY:                    DEFS stringsspace" );
    outhead0("FREE_STRING:                  DW (stringsspace-1)" );
#if !defined(__vg5000__) && !defined(__cpc__) && !defined(__c128z__) && !defined(__zx__) && !defined(__vz200__)
    outhead0("section code_user" );
#endif

}

void cpu_protothread_vars( Environment * _environment ) {

    int count = _environment->protothreadConfig.count;

    variable_import( _environment, "PROTOTHREADLC", VT_BUFFER, count );
    // outhead1("PROTOTHREADLC:      DEFS        %d", count );
    variable_import( _environment, "PROTOTHREADST", VT_BUFFER, count );
    // outhead1("PROTOTHREADST:      DEFS        %d", count );
    variable_import( _environment, "PROTOTHREADCT", VT_BYTE, 0 );
    // outhead0("PROTOTHREADCT:      DEFB        0" );
    variable_import( _environment, "PROTOTHREADLOOP", VT_BUFFER, 1 + count * 8 );
    variable_import( _environment, "PROTOTHREADCOUNT", VT_BYTE, count );

}


void cpu_protothread_loop( Environment * _environment ) {

    deploy_with_vars( protothread, src_hw_z80_protothread_asm, cpu_protothread_vars );

    outline0("CALL PROTOTHREADLOOP" );

}

void cpu_protothread_register_at( Environment * _environment, char * _index, char * _label ) {

    deploy_with_vars( protothread, src_hw_z80_protothread_asm, cpu_protothread_vars );

    outline1("LD HL, %s", _label );
    outline1("LD A, (%s)", _index );
    outline0("LD B, A");

    outline0("CALL PROTOTHREADREGAT" );

}

void cpu_protothread_register( Environment * _environment, char * _label, char * _index ) {

    deploy_with_vars( protothread, src_hw_z80_protothread_asm, cpu_protothread_vars );

    outline1("LD HL, %s", _label );

    outline0("CALL PROTOTHREADREG" );

    outline0("LD A, B" );
    outline1("LD (%s), A", _index );

}

void cpu_protothread_unregister( Environment * _environment, char * _index ) {

    deploy_with_vars( protothread, src_hw_z80_protothread_asm, cpu_protothread_vars );

    outline1("LD A, (%s)", _index );
    outline0("LD B, A" );

    outline0("CALL PROTOTHREADUNREG" );

}

void cpu_protothread_save( Environment * _environment, char * _index, int _step ) {

    deploy_with_vars( protothread, src_hw_z80_protothread_asm, cpu_protothread_vars );

    outline1("LD A, (%s)", _index );
    outline0("LD B, A" );
    outline1("LD A, $%2.2x", ( _step & 0xff ) );

    outline0("CALL PROTOTHREADSAVE" );

}

void cpu_protothread_restore( Environment * _environment, char * _index, char * _step ) {

    deploy_with_vars( protothread, src_hw_z80_protothread_asm, cpu_protothread_vars );

    outline1("LD A, (%s)", _index );
    outline0("LD B, A" );

    outline0("CALL PROTOTHREADRESTORE" );

    outline1("LD (%s), A", _step );
    
}

void cpu_protothread_set_state( Environment * _environment, char * _index, int _state ) {

    deploy_with_vars( protothread, src_hw_z80_protothread_asm, cpu_protothread_vars );

    outline1("LD A, (%s)", _index );
    outline0("LD B, A" );
    outline1("LD A, $%2.2x", ( _state & 0xff ) );

    outline0("CALL PROTOTHREADSETSTATE" );

}

void cpu_protothread_get_state( Environment * _environment, char * _index, char * _state ) {

    deploy_with_vars( protothread, src_hw_z80_protothread_asm, cpu_protothread_vars );

    outline1("LD A, (%s)", _index );
    outline0("LD B, A" );

    outline0("CALL PROTOTHREADGETSTATE" );

    outline1("LD (%s), A", _state );

}

void cpu_protothread_get_address( Environment * _environment, char * _index, char * _address ) {

    deploy_with_vars( protothread, src_hw_z80_protothread_asm, cpu_protothread_vars );

    outline1("LD A, (%s)", _index );
    outline0("LD B, A" );

    outline0("CALL PROTOTHREADGETADDRESS" );

    outline1("LD (%s), DE", _address );

}

void cpu_protothread_current( Environment * _environment, char * _current ) {

    deploy_with_vars( protothread, src_hw_z80_protothread_asm, cpu_protothread_vars );

    outline0("LD A, (PROTOTHREADCT)" );
    outline1("LD (%s), A", _current );

}

void cpu_set_callback( Environment * _environment, char * _callback, char * _label ) {

    outline1("LD DE, %s", _label );
    outline1("LD HL, %s", _callback );
    outline0("INC HL" );
    outline0("LD (HL), E" );
    outline0("INC HL" );
    outline0("LD (HL), D" );

}

void cpu_msc1_uncompress_direct_direct( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_z80_msc1_asm );

        outline1("LD HL, %s", _input);
        outline1("LD DE, %s", _output);
        outline0("CALL MSC1UNCOMPRESS");

    done()

}

void cpu_msc1_uncompress_direct_indirect( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_z80_msc1_asm );

        outline1("LD HL, %s", _input);
        outline1("LD DE, (%s)", _output);
        outline0("CALL MSC1UNCOMPRESS");

    done()

}

void cpu_msc1_uncompress_indirect_direct( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_z80_msc1_asm );

        outline1("LD HL, (%s)", _input);
        outline1("LD DE, %s", _output);
        outline0("CALL MSC1UNCOMPRESS");

    done()

}

void cpu_msc1_uncompress_indirect_indirect( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_z80_msc1_asm );

        outline1("LD HL, (%s)", _input);
        outline1("LD DE, (%s)", _output);
        outline0("CALL MSC1UNCOMPRESS");

    done()

}

void cpu_out( Environment * _environment, char * _port, char * _value ) {

    outline1("LD A, (%s)", _value );
    outline1("LD BC, (%s)", _port );
    outline0("OUT (C), A" );

}

void cpu_in( Environment * _environment, char * _port, char * _value ) {

    outline1("LD BC, (%s)", _port );
    outline0("IN A, (C)" );
    outline1("LD (%s), A", _value );
        
}

void cpu_out_direct( Environment * _environment, char * _port, char * _value ) {

    outline1("LD A, (%s)", _value );
    outline1("LD BC, %s", _port );
    outline0("OUT (C), A" );

}

void cpu_in_direct( Environment * _environment, char * _port, char * _value ) {

    outline1("LD BC, %s", _port );
    outline0("IN A, (C)" );
    outline1("LD (%s), A", _value );
        
}

void cpu_string_sub( Environment * _environment, char * _source, char * _source_size, char * _pattern, char * _pattern_size, char * _destination, char * _destination_size ) {
    
    MAKE_LABEL

    inline( cpu_string_sub )

    embedded( cpu_string_sub, src_hw_z80_cpu_string_sub_asm );

        outline1("LD A, (%s)", _source);
        outline0("LD L, A");
        outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
        outline0("LD H, A");
        outline1("LD A, (%s)", _source_size);
        outline0("LD IYL, A");

        outline1("LD A, (%s)", _pattern);
        outline0("LD IXL, A");
        outline1("LD A, (%s)", address_displacement(_environment, _pattern, "1"));
        outline0("LD IXH, A");
        outline1("LD A, (%s)", _pattern_size);
        outline0("LD IYH, A");

        outline1("LD A, (%s)", _destination);
        outline0("LD E, A");
        outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
        outline0("LD D, A");

        outline0("CALL CPUSTRINGSUB");

        outline0("LD A, IYL");
        outline1("LD (%s), A", _destination_size);

    done()
}

static char Z80_BLIT_REGISTER[][2] = {
    "L",
    "H",
    "E",
    "D"
};

#define Z80_BLIT_REGISTER_COUNT ( sizeof( Z80_BLIT_REGISTER ) / 2 )

void cpu_blit_initialize( Environment * _environment ) {

    _environment->blit.freeRegisters = 0;
    _environment->blit.usedMemory = 0;

    // outline0("; cpu_blit_initialize");

    outline0("PUSH HL");
    outline0("PUSH DE");

}

void cpu_blit_finalize( Environment * _environment ) {

    // outline0("; cpu_blit_finalize");

    _environment->blit.freeRegisters = 0;
    _environment->blit.usedMemory = 0;

    outline0("POP DE");
    outline0("POP HL");
    
}

char * cpu_blit_register_name(  Environment * _environment, int _register ) {
    
    if ( _register < Z80_BLIT_REGISTER_COUNT ) {
        return &Z80_BLIT_REGISTER[_register][0];
    } else {
        return &Z80_BLIT_REGISTER[ (_register & 0xff00) >> 8][0];
    }
}

int cpu_blit_alloc_register(  Environment * _environment ) {

    int reg = 0;

    for( reg = 0; reg < Z80_BLIT_REGISTER_COUNT; ++reg ) {
        int registerMask = ( 0x01 << reg );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( ! isRegisterUsed ) {
            _environment->blit.freeRegisters |= registerMask;
            // printf( "cpu_blit_alloc_register() %4.4x -> $%4.4x\n", _environment->blit.freeRegisters, reg );
            // outline1("; cpu_blit_alloc_register = %d", reg );
            return reg;
        }
    }

    int location = _environment->blit.usedMemory++;

    if ( location > 0xff ) {
        CRITICAL_BLIT_ALLOC_MEMORY_EXHAUSTED( );
    }

    for( reg = 0; reg < Z80_BLIT_REGISTER_COUNT; ++reg ) {
        int registerMask = ( 0x10 << reg );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( ! isRegisterUsed ) {
            outline1( "LD A, %s", &Z80_BLIT_REGISTER[reg][0] );
            outline2( "LD (%sbs+$%2.2x), A",  _environment->blit.realName, location );
            _environment->blit.freeRegisters |= registerMask;
            // printf( "cpu_blit_alloc_register() -> %4.4x $%4.4x\n", _environment->blit.freeRegisters, ( ( reg << 8 ) | location ) );
            // outline1("; cpu_blit_alloc_register = %d", ( ( (reg+1) << 8 ) | location ) );
            return ( ( (reg+1) << 8 ) | location );
        }
    }

    CRITICAL_BLIT_ALLOC_REGISTER_EXHAUSTED( );

}

void cpu_blit_free_register(  Environment * _environment, int _register ) {

    // outline1("; cpu_blit_free_register = %d", _register );

    // printf( "cpu_blit_free_register($%4.4x)\n", _register );

    int location = _register & 0xff;
    int reg;

    if ( _register < Z80_BLIT_REGISTER_COUNT ) {
        int registerMask = ( 0x01 << _register );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( isRegisterUsed ) {
            _environment->blit.freeRegisters &= ~registerMask;
            return;
        } else {
            CRITICAL_BLIT_INVALID_FREE_REGISTER( _environment->blit.name, _register );
        }
    } else {
        int registerMask = 0x10 << ( ( ( _register >> 8 ) & 0xff ) - 1 );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( isRegisterUsed ) {
            outline2( "LD A, (%sbs+$%2.2x)",  _environment->blit.realName, location );
            outline1( "LD %s, A", &Z80_BLIT_REGISTER[reg][0] );
            _environment->blit.freeRegisters &= ~registerMask;
            return;
        }
    }

    CRITICAL_BLIT_INVALID_FREE_REGISTER( _environment->blit.name, _register );

}

/**
 * @brief <i>CPU Z80</i>: emit code to store n bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _n bits to store (>32)
 * @param _value[] Value to store (segmented in 32 bit each)
 */
void cpu_store_nbit( Environment * _environment, char *_destination, int _n, int _value[] ) {

    int i = 0;
    while( _n ) {
        char destinationAddress[MAX_TEMPORARY_STORAGE]; sprintf( destinationAddress, "%s+%d", _destination, i*4 );
        if ( _n <= 32 ) {
            switch( _n ) {
                case 1: case 2: case 3: case 4:
                case 5: case 6: case 7: case 8:
                    cpu_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff>>(8-_n)) ) );
                    break;
                case 9: case 10: case 11: case 12:
                case 13: case 14: case 15: case 16:
                    cpu_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu_store_8bit( _environment, destinationAddress, ( _value[i+1] & (0xff>>(16-_n)) ) );
                    break;
                case 17: case 18: case 19: case 20:
                case 21: case 22: case 23: case 24:
                    cpu_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu_store_8bit( _environment, destinationAddress, ( _value[i+1] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    cpu_store_8bit( _environment, destinationAddress, ( _value[i+2] & (0xff>>(24-_n)) ) );
                    break;
                case 25: case 26: case 27: case 28:
                case 29: case 30: case 31: case 32:
                default:
                    cpu_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu_store_8bit( _environment, destinationAddress, ( _value[i+1] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    cpu_store_8bit( _environment, destinationAddress, ( _value[i+2] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
                    cpu_store_8bit( _environment, destinationAddress, ( _value[i+3] & (0xff>>(32-_n)) ) );
                    break;
            }
            _n = 0;
        } else {
            cpu_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
            cpu_store_8bit( _environment, destinationAddress, ( _value[i+1] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
            cpu_store_8bit( _environment, destinationAddress, ( _value[i+2] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
            cpu_store_8bit( _environment, destinationAddress, ( _value[i+3] & (0xff>>(32-_n)) ) );
            _n -= 32;
        }
        ++i;
    }

}

/**
 * @brief <i>CPU Z80</i>: emit code to store n bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _n bits to store (>32)
 * @param _value[] Value to store (segmented in 32 bit each)
 */
void cpu_move_nbit( Environment * _environment, int _n, char * _source, char *_destination ) {

    int i = 0;
    while( _n ) {
        char sourceAddress[MAX_TEMPORARY_STORAGE]; sprintf( sourceAddress, "%s+%d", _source, i*4 );
        char destinationAddress[MAX_TEMPORARY_STORAGE]; sprintf( destinationAddress, "%s+%d", _destination, i*4 );
        if ( _n <= 32 ) {
            switch( _n ) {
                case 1: case 2: case 3: case 4:
                case 5: case 6: case 7: case 8:
                    cpu_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
                case 9: case 10: case 11: case 12:
                case 13: case 14: case 15: case 16:
                    cpu_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
                case 17: case 18: case 19: case 20:
                case 21: case 22: case 23: case 24:
                    cpu_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    cpu_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
                case 25: case 26: case 27: case 28:
                case 29: case 30: case 31: case 32:
                default:
                    cpu_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    cpu_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+3 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
                    cpu_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
            }
            _n = 0;
        } else {
            cpu_move_8bit( _environment, sourceAddress, destinationAddress );
            sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
            cpu_move_8bit( _environment, sourceAddress, destinationAddress );
            sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
            cpu_move_8bit( _environment, sourceAddress, destinationAddress );
            sprintf( sourceAddress, "%s+%d", _source, i*4+3 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
            cpu_move_8bit( _environment, sourceAddress, destinationAddress );
            _n -= 32;
        }
        ++i;
    }

}

/**
 * @brief <i>CPU Z80</i>: emit code to compare n bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _n bits to store (>32)
 * @param _value[] Value to store (segmented in 32 bit each)
 */
void cpu_compare_nbit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive, int _bits ) {

    MAKE_LABEL

    inline( cpu_compare_nbit )

        for( int i=0; i<(_bits>>3); ++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
            outline1("LD A, (%s)", address_displacement(_environment, _source, offset));
            outline0("LD B, A" );
            outline1("LD A, (%s)", address_displacement(_environment, _destination, offset));
            outline0("CP B");
            outline1("JP NZ, %s", label);
        }
        outline1("LD A, $%2.2x", 0xff*_positive);
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline1("LD (%s), A", _destination);
        }
        outline1("JP %s_2", label);
        outhead1("%s:", label);
        outline1("LD A, $%2.2x", 0xff*(1-_positive));
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline1("LD (%s), A", _destination);
        }
        outhead1("%s_2:", label);
    
    no_embedded( cpu_compare_nbit )

}

void cpu_compare_nbit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _positive, int _bits ) {

    MAKE_LABEL

    inline( cpu_compare_nbit )

        for( int i=0; i<(_bits>>3); ++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
            outline1("LD A, (%s)", address_displacement(_environment, _source, offset));
            outline1("LD B, $%2.2x", (unsigned char)((_destination>>(i*8))&0xff));
            outline0("CP B");
            outline1("JP NZ, %s", label);
        }
        outline1("LD A, $%2.2x", 0xff*_positive);
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline1("LD (%s), A", _destination);
        }
        outline1("JP %s_2", label);
        outhead1("%s:", label);
        outline1("LD A, $%2.2x", 0xff*(1-_positive));
        if ( _other ) {
            outline1("LD (%s), A", _other);
        } else {
            outline1("LD (%s), A", _destination);
        }
        outhead1("%s_2:", label);
    
    no_embedded( cpu_compare_nbit )

}

//                  [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]      [8]      [9]
// FAST	    (24)	seeeeeee mmmmmmmm mmmmmmmm

void cpu_float_fast_from_double_to_int_array( Environment * _environment, double _value, int _result[] ) {

    double value = 0.0;
    double integral = 0.0;
    double fractional = 0.0;
    int sign = 0;
    int left = 0;
    int right[2];
    int steps = 0;
    int exp = 0;
    int mantissa_bits = 16;

    memset( &right[0], 0, sizeof( int ) * 2 );

    // Step 1: Determine Sign
    // If the number is positive, then the sign bit will be 0. If the number is negative, then the sign bit 
    // will be 1. For the number zero, both positive and negative zero are possible, and these are considered 
    // different values (a quirk of using sign bits).

    if ( _value >= 0 ) {
        sign = 0;
    } else {
        sign = 1;
    }

    value = fabs( _value );

    // Step 2: Convert the Integral Portion to Unsigned Binary
    // Convert the integral portion of the floating-point value to unsigned binary (not two's complement). 
    // The integral portion is the part of the number before the decimal point. For example, if the 
    // number to convert is -0.75, then 0 is the integral portion, and it's unsigned binary representation 
    // is simply 0. As another example, if the number to convert is 127.99, then the integral portion would 
    // be 127, and it's unsigned binary representation is 1111111.

    fractional = modf(value, &integral);

    left = (unsigned int) integral;

    // Step 3: Convert the Fractional Portion to Binary
    // The fractional portion of the number must also be converted to binary, though the conversion process 
    // is much different from what you're used to. The algorithm you'll used is based on performing repeated 
    // multiplications by 2, and then checking if the result is >= 1.0. If the result is >= 1.0, then a 1 is 
    // recorded for the binary fractional component, and the leading 1 is chopped of the result. If the 
    // result is < 1.0, then a 0 is recorded for the binary fractional component, and the result is kept 
    // as-is. The recorded builds are built-up left-to-right. The result keeps getting chained along in this 
    // way until one of the following is true:
    //  - The result is exactly 1.0
    //  - 23 iterations of this process have occurred; i.e. the final converted binary value holds 23 bits
    // With the first possible terminating condition (the result is exactly 1.0), this means that the fractional 
    // component has been represented without any loss of precision. With the second possible terminating 
    // condition (23 iterations have passed), this means that we ran out of bits in the final result, which 
    // can never exceed 23. In this case, precision loss occurs (an unfortunate consequence of using a finite
    // number of bits).

    while( ( fractional != 1.0 ) && ( steps < mantissa_bits ) ) {

        // printf("%f %d %2.2x %2.2x\n", fractional, steps, (unsigned char) right[0], (unsigned char) right[1] );

        right[1] = right[1] << 1;
        right[0] = right[0] << 1;
        if ( ( right[1] & 0x100 )  ) {
            right[0] = right[0] | 0x1;
        }
        right[1] = right[1] & 0xff;
        right[0] = right[0] & 0xff;

        fractional = fractional * 2;

        if ( fractional >= 1.0 ) {
            right[1] |= 1;
            fractional = modf(fractional, &integral);
        }

        ++steps;

    }

    // Step 4: Normalize the Value via Adjusting the Exponent
    // A trick to encode an extra bit is to make it so that the binary scientific representation is always 
    // of the form 1.XXXX * 2YYYY. That is, a 1 always leads, so there is no need to explicitly encode it. 
    // In order to encode this properly, we need to move the decimal point to a position where it is 
    // immediately after the first 1, and then record exactly how we moved it. To see this in action, consider 
    // again the example of 0.75, which is encoded in binary as such (not IEEE-754 notation):
    // 0.11
    // In order to make the decimal point be after the first 1, we will need to move it one position to the right, like so:
    // 1.1
    // Most importantly, we need to record that we moved the decimal point by one position to the right. 
    // Moves to the right result in negative exponents, and moves to the left result in positive exponents. 
    // In this case, because we moved the decimal point one position to the right, the recorded exponent should be -1.
    // As another example, consider the following binary floating point representation (again, not IEEE-754):
    // 1111111.11100
    // In this case, we need to move the decimal point six positions to the left to make this begin with a single 1, like so:
    // 1.11111111100
    // Because this moves six positions to the left, the recorded exponent should be 6.

    int mantissa_high_bit = 0x80000000 >> ( 32 - mantissa_bits);
    int mantissa_mask = 0xffffffff >> ( 32 - mantissa_bits);

    if ( left == 0 ) {

        if ( value != 0 ) {

            while( left == 0 ) {

                // printf("exp = %d left = %2.2x right = %2.2x %2.2x\n", exp, (unsigned char) left, (unsigned char) right[0], (unsigned char) right[1] );

                if ( ! right[0] && ! right[1] && ! right[2] ) {
                    left = 0x1;
                }

                if ( right[0] & 0x80 ) {
                    left = 0x1;
                }

                right[0] = right[0] << 1;
                right[1] = right[1] << 1;
                if ( ( right[1] & 0x100 )) {
                    right[0] = right[0] | 0x1;
                }
                right[0] = right[0] & 0xff;
                right[1] = right[1] & 0xff;

                --exp;
            }

        } else {

            exp = -63;
            
        }

        // printf("exp = %d left = %2.2x right = %2.2x %2.2x\n", exp, (unsigned char) left, (unsigned char) right[0], (unsigned char) right[1] );

    } else {

        while( left ) {

            // printf("left = %8.8x right = %2.2x %2.2x\n", left, (unsigned char) right[0], (unsigned char) right[1] );

            if ( ( right[0] & 0x01 ) ) {
                right[1] = right[1] | 0x100;
            }
            right[0] = right[0] >> 1;
            right[1] = right[1] >> 1;
            if ( left & 0x1 ) {
                right[0] = right[0] | 0x80;
            }
            left = left >> 1;
            ++exp;
        }
        --exp;
        left = 1;
        right[1] = right[1] << 1;
        right[0] = right[0] << 1;
        if ( right[1] & 0x100 ) {
            right[0] = right[0] | 0x01;
        }
        right[1] = right[1] & 0xff;
        right[0] = right[0] & 0xff;
        
    }

    // Step 5: Add Bias to the Exponent
    // Internally, IEEE-754 values store their exponents in an unsigned representation, which may seem odd considering that 
    // the exponent can be negative. Negative exponents are accomodated by using a biased representation, wherein a 
    // pre-set number is always subtracted from the given unsigned number. Because the given unsigned number may be less 
    // than this number, this allows for negative values to be effectively encoded without resorting to two's complement. 
    // Specifically, for the binary32 representation, the number 127 will be subtracted from anything encoded in the 
    // exponent field of the IEEE-754 number. As such, in this step, we need to add 127 to the normalized exponent value 
    // from the previous step.

    exp += 63;

    // printf("exp = %2.2x\n", exp );

    // Step 6: Convert the Biased Exponent to Unsigned Binary
    // The biased exponent value from the previous step must be converted into unsigned binary, using the usual process.
    // The result must be exactly 8 bits. It should not be possible to need more than 8 bits. If fewer than 8 bits are 
    // needed in this conversion process, then leading zeros must be added to the front of the result to produce an 
    // 8-bit value.

    exp = exp & 0xff;

    // printf("exp = %2.2x\n", exp );

    // Step 7: Determine the Final Bits for the Mantissa
    // After step 4, there are a bunch of bits after the normalized decimal point. These bits will become the 
    // mantissa (note that we ignore the bits to the left of the decimal point - normalization allows us to do this, 
    // because it should always be just a 1). We need exactly 23 mantissa bits. If less than 23 mantissa bits follow the 
    // decimal point, and the algorithm in step 3 ended with a result that wasn't 1.0, then follow the algorithm in step 3 
    // until we can fill enough bits. If that's still not enough (eventually reaching 1.0 before we had enough bits, or 
    // perhaps it had ended with 1.0 already), then the right side can be padded with zeros until 23 bits is reached.
    // If there are more than 23 bits after the decimal point in step 4, then these extra bits are simply cutoff from the 
    // right. For example, if we had 26 bits to the right of the decimal point, then the last three would need to be cutoff 
    // to get us to 23 bits. Note that in this case we will necessarily lose some precision.

    // Step 8: Put it All Together
    // The sign bit from step 1 will be the first bit of the final result. The next 8 bits will be from the exponent from 
    // step 6. The last 23 bits will be from the mantissa from step 7. The result will be a 32-bit number encoded in 
    // IEEE-754 binary32 format, assuming no mistakes were made in the process.

    //                  [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]      [8]      [9]
    // FAST	    (24)	seeeeeee mmmmmmmm mmmmmmmm

    _result[0] = ( sign << 7 ) | ( exp & 0x7f );
    _result[1] = ( right[0] );
    _result[2] = ( right[1] );

    // printf( "%2.2x %2.2x %2.2x\n", _result[0], _result[1], _result[2] );

}

//
//                  [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]      [8]      [9]
// SINGLE	(32)  	seeeeeee emmmmmmm mmmmmmmm mmmmmmmm
//

void cpu_float_single_from_double_to_int_array( Environment * _environment, double _value, int _result[] ) {
    
    double value = 0.0;
    double integral = 0.0;
    double fractional = 0.0;
    int sign = 0;
    int left = 0;
    int right[3];
    int steps = 0;
    int exp = 0;
    int mantissa_bits = 23;

    memset( &right[0], 0, sizeof( int ) * 3 );

    // Step 1: Determine Sign
    // If the number is positive, then the sign bit will be 0. If the number is negative, then the sign bit 
    // will be 1. For the number zero, both positive and negative zero are possible, and these are considered 
    // different values (a quirk of using sign bits).

    if ( _value >= 0 ) {
        sign = 0;
    } else {
        sign = 1;
    }

    value = fabs( _value );

    // Step 2: Convert the Integral Portion to Unsigned Binary
    // Convert the integral portion of the floating-point value to unsigned binary (not two's complement). 
    // The integral portion is the part of the number before the decimal point. For example, if the 
    // number to convert is -0.75, then 0 is the integral portion, and it's unsigned binary representation 
    // is simply 0. As another example, if the number to convert is 127.99, then the integral portion would 
    // be 127, and it's unsigned binary representation is 1111111.

    fractional = modf(value, &integral);

    left = (unsigned int) integral;

    // Step 3: Convert the Fractional Portion to Binary
    // The fractional portion of the number must also be converted to binary, though the conversion process 
    // is much different from what you're used to. The algorithm you'll used is based on performing repeated 
    // multiplications by 2, and then checking if the result is >= 1.0. If the result is >= 1.0, then a 1 is 
    // recorded for the binary fractional component, and the leading 1 is chopped of the result. If the 
    // result is < 1.0, then a 0 is recorded for the binary fractional component, and the result is kept 
    // as-is. The recorded builds are built-up left-to-right. The result keeps getting chained along in this 
    // way until one of the following is true:
    //  - The result is exactly 1.0
    //  - 23 iterations of this process have occurred; i.e. the final converted binary value holds 23 bits
    // With the first possible terminating condition (the result is exactly 1.0), this means that the fractional 
    // component has been represented without any loss of precision. With the second possible terminating 
    // condition (23 iterations have passed), this means that we ran out of bits in the final result, which 
    // can never exceed 23. In this case, precision loss occurs (an unfortunate consequence of using a finite
    // number of bits).

    while( ( fractional != 1.0 ) && ( steps < mantissa_bits ) ) {

        // printf("%f %d %2.2x %2.2x %2.2x\n", fractional, steps, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2] );

        right[2] = right[2] << 1;
        right[1] = right[1] << 1;
        right[0] = right[0] << 1;
        if ( ( right[2] & 0x100 )  ) {
            right[1] = right[1] | 0x1;
        }
        if ( ( right[1] & 0x100 )  ) {
            right[0] = right[0] | 0x1;
        }
        right[2] = right[2] & 0xff;
        right[1] = right[1] & 0xff;
        right[0] = right[0] & 0x7f;

        fractional = fractional * 2;

        if ( fractional >= 1.0 ) {
            right[2] |= 1;
            fractional = modf(fractional, &integral);
        }

        ++steps;

    }

    // Step 4: Normalize the Value via Adjusting the Exponent
    // A trick to encode an extra bit is to make it so that the binary scientific representation is always 
    // of the form 1.XXXX * 2YYYY. That is, a 1 always leads, so there is no need to explicitly encode it. 
    // In order to encode this properly, we need to move the decimal point to a position where it is 
    // immediately after the first 1, and then record exactly how we moved it. To see this in action, consider 
    // again the example of 0.75, which is encoded in binary as such (not IEEE-754 notation):
    // 0.11
    // In order to make the decimal point be after the first 1, we will need to move it one position to the right, like so:
    // 1.1
    // Most importantly, we need to record that we moved the decimal point by one position to the right. 
    // Moves to the right result in negative exponents, and moves to the left result in positive exponents. 
    // In this case, because we moved the decimal point one position to the right, the recorded exponent should be -1.
    // As another example, consider the following binary floating point representation (again, not IEEE-754):
    // 1111111.11100
    // In this case, we need to move the decimal point six positions to the left to make this begin with a single 1, like so:
    // 1.11111111100
    // Because this moves six positions to the left, the recorded exponent should be 6.

    int mantissa_high_bit = 0x80000000 >> ( 32 - mantissa_bits);
    int mantissa_mask = 0xffffffff >> ( 32 - mantissa_bits);

    if ( left == 0 ) {

        if ( value != 0 ) {

            while( left == 0 ) {

                // printf("exp = %d left = %2.2x right = %2.2x %2.2x %2.2x\n", exp, (unsigned char) left, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2] );

                if ( right[0] & 0x40 ) {
                    left = 0x1;
                }

                right[0] = right[0] << 1;
                right[1] = right[1] << 1;
                right[2] = right[2] << 1;
                if ( ( right[1] & 0x100 )) {
                    right[0] = right[0] | 0x1;
                }
                if ( ( right[2] & 0x100 )) {
                    right[1] = right[1] | 0x1;
                }
                right[0] = right[0] & 0x7f;
                right[1] = right[1] & 0xff;
                right[2] = right[2] & 0xff;

                --exp;
            }

        } else {

            exp = -127;

        }

        // printf("exp = %d left = %2.2x right = %2.2x %2.2x %2.2x\n", exp, (unsigned char) left, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2] );

    } else {

        while( left ) {

            // printf("left = %8.8x right = %2.2x %2.2x %2.2x\n", left, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2] );

            if ( ( right[0] & 0x01 ) ) {
                right[1] = right[1] | 0x100;
            }
            if ( ( right[1] & 0x01 ) ) {
                right[2] = right[2] | 0x100;
            }
            right[0] = right[0] >> 1;
            right[1] = right[1] >> 1;
            // right[2] = right[2] >> 1;
            if ( left & 0x1 ) {
                right[0] = right[0] | 0x40;
            }
            left = left >> 1;
            ++exp;
        }
        --exp;
        left = 1;
        right[2] = right[2] << 1;
        right[1] = right[1] << 1;
        right[0] = right[0] << 1;
        if ( right[2] & 0x100 ) {
            right[1] = right[1] | 0x01;
        }
        if ( right[1] & 0x100 ) {
            right[0] = right[0] | 0x01;
        }
        right[2] = right[2] & 0xff;
        right[1] = right[1] & 0xff;
        right[0] = right[0] & 0x7f;
        
    }

    // Step 5: Add Bias to the Exponent
    // Internally, IEEE-754 values store their exponents in an unsigned representation, which may seem odd considering that 
    // the exponent can be negative. Negative exponents are accomodated by using a biased representation, wherein a 
    // pre-set number is always subtracted from the given unsigned number. Because the given unsigned number may be less 
    // than this number, this allows for negative values to be effectively encoded without resorting to two's complement. 
    // Specifically, for the binary32 representation, the number 127 will be subtracted from anything encoded in the 
    // exponent field of the IEEE-754 number. As such, in this step, we need to add 127 to the normalized exponent value 
    // from the previous step.

    exp += 127;

    // printf("exp = %2.2x\n", exp );

    // Step 6: Convert the Biased Exponent to Unsigned Binary
    // The biased exponent value from the previous step must be converted into unsigned binary, using the usual process.
    // The result must be exactly 8 bits. It should not be possible to need more than 8 bits. If fewer than 8 bits are 
    // needed in this conversion process, then leading zeros must be added to the front of the result to produce an 
    // 8-bit value.

    exp = exp & 0xff;

    // printf("exp = %2.2x\n", exp );

    // Step 7: Determine the Final Bits for the Mantissa
    // After step 4, there are a bunch of bits after the normalized decimal point. These bits will become the 
    // mantissa (note that we ignore the bits to the left of the decimal point - normalization allows us to do this, 
    // because it should always be just a 1). We need exactly 23 mantissa bits. If less than 23 mantissa bits follow the 
    // decimal point, and the algorithm in step 3 ended with a result that wasn't 1.0, then follow the algorithm in step 3 
    // until we can fill enough bits. If that's still not enough (eventually reaching 1.0 before we had enough bits, or 
    // perhaps it had ended with 1.0 already), then the right side can be padded with zeros until 23 bits is reached.
    // If there are more than 23 bits after the decimal point in step 4, then these extra bits are simply cutoff from the 
    // right. For example, if we had 26 bits to the right of the decimal point, then the last three would need to be cutoff 
    // to get us to 23 bits. Note that in this case we will necessarily lose some precision.

    // Step 8: Put it All Together
    // The sign bit from step 1 will be the first bit of the final result. The next 8 bits will be from the exponent from 
    // step 6. The last 23 bits will be from the mantissa from step 7. The result will be a 32-bit number encoded in 
    // IEEE-754 binary32 format, assuming no mistakes were made in the process.

    //                  [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]      [8]      [9]
    // SINGLE	(32)  	seeeeeee emmmmmmm mmmmmmmm mmmmmmmm

    _result[3] = ( sign << 7 ) | ( ( exp >> 1 ) & 0x7f );
    _result[2] = ( ( exp & 0x01 ) << 7 ) | ( right[0] );
    _result[1] = ( right[1] );
    _result[0] = ( right[2] );

    // printf( "%2.2x %2.2x %2.2x %2.2x\n", _result[0], _result[1], _result[2], _result[3] );

}

//
//                  [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]      [8]      [9]
// EXTENDED (80)	seeeeeee eeeeeeee mmmmmmmm mmmmmmmm mmmmmmmm mmmmmmmm mmmmmmmm mmmmmmmm mmmmmmmm mmmmmmmm
//

void cpu_float_double_from_double_to_int_array( Environment * _environment, double _value, int _result[] ) {
    
}

void cpu_float_fast_to_string( Environment * _environment, char * _x, char * _string, char * _string_size ) {

    MAKE_LABEL

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_mul16, src_hw_z80_fp_mul16_asm );
    deploy( fp_fast_mul, src_hw_z80_fp_fast_mul_asm );
    deploy( fp_fast_pow10_lut, src_hw_z80_fp_fast_pow10_lut_asm );
    deploy( fp_format_str, src_hw_z80_fp_format_str_asm );
    deploy( fp_fast_to_string, src_hw_z80_fp_fast_to_string_asm );

    // ;converts a 24-bit float to a string

    // ;Inputs:
    // ;   AHL is the float to convert

    outline1( "LD A, (%s)", address_displacement( _environment, _x, "+2" ) );
    outline0( "LD L, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _x, "+1" ) );
    outline0( "LD H, A" );
    outline1( "LD A, (%s)", _x );

    // ;   DE points to where to write the string
    outline1( "LD DE, (%s)", _string );

    outline0( "CALL FPFASTTOA" );

    // ;Output:
    // ;   HL pointing to the string
    outline0( "PUSH HL" );
    outline0( "POP DE" );
    outhead1( "%s:", label );
    outline0( "LD A, (DE)" );
    outline0( "CP 0" );
    outline1( "JR Z, %sdone", label );
    outline0( "INC DE" );
    outline0( "INC C" );
    outline1( "JR %s", label );
    outhead1( "%sdone:", label );
    outline0( "LD A, C" );
    outline1( "LD (%s), A", _string_size );

    // ;Destroys:
    // ;   A,DE,BC
    // ;Notes:
    // ;   Uses up to 12 bytes to store the string

}

void cpu_float_single_to_string( Environment * _environment, char * _x, char * _string, char * _string_size ) {

    MAKE_LABEL

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_pushpop, src_hw_z80_fp_pushpop_asm );
    deploy( fp_c_times_bde, src_hw_z80_fp_c_times_bde_asm );
    deploy( fp_mul24_stack_based, src_hw_z80_fp_mul24_stack_based_asm );
    deploy( fp_single_pow10_lut, src_hw_z80_fp_single_pow10_lut_asm );
    deploy( fp_single_mul, src_hw_z80_fp_single_mul_asm );
    deploy( fp_mov4, src_hw_z80_fp_mov4_asm );
    deploy( fp_common_str, src_hw_z80_fp_common_str_asm );
    deploy( fp_format_str, src_hw_z80_fp_format_str_asm );
    deploy( fp_single_to_string, src_hw_z80_fp_single_to_string_asm );

    // ;converts a 32-bit float to a string

    // ;Inputs:
    // ;   HL points to the input float
    // ;   BC points to where the string gets written.

    outline1( "LD HL, %s", _x );

    outline1( "LD BC, (%s)", _string );

    outline0( "CALL FPSINGLETOA" );

    // ;Output:
    // ;   HL pointing to the string
    outline0( "PUSH HL" );
    outline0( "POP DE" );
    outhead1( "%s:", label );
    outline0( "LD A, (DE)" );
    outline0( "CP 0" );
    outline1( "JR Z, %sdone", label );
    outline0( "INC DE" );
    outline0( "INC C" );
    outline1( "JR %s", label );
    outhead1( "%sdone:", label );
    outline0( "LD A, C" );
    outline1( "LD (%s), A", _string_size );

}

void cpu_float_double_to_string( Environment * _environment, char * _x, char * _string, char * _string_size ) {
    
}

void cpu_float_fast_from_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_fast_from_16, src_hw_z80_fp_fast_from_16_asm );

    outline1( "LD HL, (%s)", _value );
    if ( _signed ) {
        outline0( "CALL FPFASTFROM16S");
    } else {
        outline0( "CALL FPFASTFROM16U");
    }
    outline1( "LD (%s), A", _result );
    outline0( "LD A, H" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    outline0( "LD A, L" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void cpu_float_fast_from_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_fast_from_8, src_hw_z80_fp_fast_from_8_asm );

    outline1( "LD A, (%s)", _value );
    if ( _signed ) {
        outline0( "CALL FPFASTFROM8S");
    } else {
        outline0( "CALL FPFASTFROM8U");
    }
    outline1( "LD (%s), A", _result );
    outline0( "LD A, H" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    outline0( "LD A, L" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void cpu_float_fast_to_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_fast_to_16, src_hw_z80_fp_fast_to_16_asm );

    outline1( "LD A, (%s)", address_displacement( _environment, _value, "+2" ) );
    outline0( "LD L, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _value, "+1" ) );
    outline0( "LD H, A" );
    outline1( "LD A, (%s)", _value );
    if ( _signed ) {
        outline0( "CALL FPFASTTOS16");
    } else {
        outline0( "CALL FPFASTTOU16");
    }
    outline1( "LD (%s), HL", _result );

}

void cpu_float_fast_to_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_fast_to_8, src_hw_z80_fp_fast_to_8_asm );

    outline1( "LD A, (%s)", address_displacement( _environment, _value, "+2" ) );
    outline0( "LD L, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _value, "+1" ) );
    outline0( "LD H, A" );
    outline1( "LD A, (%s)", _value );
    if ( _signed ) {
        outline0( "CALL FPFASTTOS8");
    } else {
        outline0( "CALL FPFASTTOU8");
    }
    outline1( "LD (%s), A", _result );

}

void cpu_float_fast_add( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_fast_add, src_hw_z80_fp_fast_add_asm );

    outline1( "LD A, (%s)", address_displacement( _environment, _y, "+2" ) );
    outline0( "LD E, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _y, "+1" ) );
    outline0( "LD D, A" );
    outline1( "LD A, (%s)", _y );
    outline0( "LD C, A" );

    outline1( "LD A, (%s)", address_displacement( _environment, _x, "+2" ) );
    outline0( "LD L, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _x, "+1" ) );
    outline0( "LD H, A" );
    outline1( "LD A, (%s)", _x );
    outline0( "CALL FPFASTADD");
    outline1( "LD (%s), A", _result );
    outline0( "LD A, H" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    outline0( "LD A, L" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void cpu_float_fast_sub( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_fast_add, src_hw_z80_fp_fast_add_asm );
    deploy( fp_fast_sub, src_hw_z80_fp_fast_sub_asm );

    outline1( "LD A, (%s)", address_displacement( _environment, _y, "+2" ) );
    outline0( "LD E, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _y, "+1" ) );
    outline0( "LD D, A" );
    outline1( "LD A, (%s)", _y );
    outline0( "LD C, A" );

    outline1( "LD A, (%s)", address_displacement( _environment, _x, "+2" ) );
    outline0( "LD L, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _x, "+1" ) );
    outline0( "LD H, A" );
    outline1( "LD A, (%s)", _x );
    outline0( "CALL FPFASTSUB");
    outline1( "LD (%s), A", _result );
    outline0( "LD A, H" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    outline0( "LD A, L" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void cpu_float_fast_mul( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_mul16, src_hw_z80_fp_mul16_asm );
    deploy( fp_fast_mul, src_hw_z80_fp_fast_mul_asm );

    outline1( "LD A, (%s)", address_displacement( _environment, _y, "+2" ) );
    outline0( "LD E, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _y, "+1" ) );
    outline0( "LD D, A" );
    outline1( "LD A, (%s)", _y );
    outline0( "LD C, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _x, "+2" ) );
    outline0( "LD L, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _x, "+1" ) );
    outline0( "LD H, A" );
    outline1( "LD A, (%s)", _x );
    outline0( "CALL FPFASTMUL");
    outline1( "LD (%s), A", _result );
    outline0( "LD A, H" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    outline0( "LD A, L" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void cpu_float_fast_div( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_fast_div, src_hw_z80_fp_fast_div_asm );

    outline1( "LD A, (%s)", address_displacement( _environment, _y, "+2" ) );
    outline0( "LD E, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _y, "+1" ) );
    outline0( "LD D, A" );
    outline1( "LD A, (%s)", _y );
    outline0( "LD C, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _x, "+2" ) );
    outline0( "LD L, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _x, "+1" ) );
    outline0( "LD H, A" );
    outline1( "LD A, (%s)", _x );
    outline0( "CALL FPFASTDIV");
    outline1( "LD (%s), A", _result );
    outline0( "LD A, H" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    outline0( "LD A, L" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void cpu_float_fast_cmp( Environment * _environment, char * _x, char * _y, char * _result ) {

    MAKE_LABEL

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_fast_add, src_hw_z80_fp_fast_add_asm );
    deploy( fp_fast_sub, src_hw_z80_fp_fast_sub_asm );
    deploy( fp_fast_cmp, src_hw_z80_fp_fast_cmp_asm );

    outline1( "LD A, (%s)", address_displacement( _environment, _y, "+2" ) );
    outline0( "LD E, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _y, "+1" ) );
    outline0( "LD D, A" );
    outline1( "LD A, (%s)", _y );
    outline0( "LD C, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _x, "+2" ) );
    outline0( "LD L, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _x, "+1" ) );
    outline0( "LD H, A" );
    outline1( "LD A, (%s)", _x );
    outline0( "CALL FPFASTCMP");

    outline1( "JR Z, %sequal", label );
    outline1( "JR C, %sless", label );
    outline0( "LD A, 1" );
    outline1( "LD (%s), A", _result );
    outline1( "JP %sdone", label );
    outhead1( "%sequal:", label );
    outline0( "LD A, 0" );
    outline1( "LD (%s), A", _result );
    outline1( "JP %sdone", label );
    outhead1( "%sless:", label );
    outline0( "LD A, $ff" );
    outline1( "LD (%s), A", _result );
    outline1( "JP %sdone", label );
    outhead1( "%sdone:", label );

}

void cpu_float_fast_sin( Environment * _environment, char * _angle, char * _result ) {

    MAKE_LABEL

    deploy( fp_mul16, src_hw_z80_fp_mul16_asm );
    deploy( fp_fast_add, src_hw_z80_fp_fast_add_asm );
    deploy( fp_fast_sub, src_hw_z80_fp_fast_sub_asm );
    deploy( fp_fast_mod1, src_hw_z80_fp_fast_mod1_asm );
    deploy( fp_fast_sin, src_hw_z80_fp_fast_sin_asm );
    deploy( fp_fast_mul, src_hw_z80_fp_fast_mul_asm );
    deploy( fp_fast_sqr, src_hw_z80_fp_fast_sqr_asm );
    deploy( fp_fast_cos, src_hw_z80_fp_fast_cos_asm );     
    deploy( fp_fast_div, src_hw_z80_fp_fast_div_asm );

    outline1( "LD A, (%s)", address_displacement( _environment, _angle, "+2" ) );
    outline0( "LD L, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _angle, "+1" ) );
    outline0( "LD H, A" );
    outline1( "LD A, (%s)", _angle );

    outline0( "CALL FPFASTSIN");

    outline1( "LD (%s), A", _result );
    outline0( "LD A, H" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    outline0( "LD A, L" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void cpu_float_fast_cos( Environment * _environment, char * _angle, char * _result ) {

    MAKE_LABEL

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_mul16, src_hw_z80_fp_mul16_asm );
    deploy( fp_fast_add, src_hw_z80_fp_fast_add_asm );
    deploy( fp_fast_sub, src_hw_z80_fp_fast_sub_asm );
    deploy( fp_fast_mod1, src_hw_z80_fp_fast_mod1_asm );
    deploy( fp_fast_mul, src_hw_z80_fp_fast_mul_asm );
    deploy( fp_fast_sqr, src_hw_z80_fp_fast_sqr_asm );
    deploy( fp_fast_sin, src_hw_z80_fp_fast_cos_asm );
    deploy( fp_fast_cos, src_hw_z80_fp_fast_sin_asm );

    outline1( "LD A, (%s)", address_displacement( _environment, _angle, "+2" ) );
    outline0( "LD L, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _angle, "+1" ) );
    outline0( "LD H, A" );
    outline1( "LD A, (%s)", _angle );
    
    outline0( "CALL FPFASTCOS");

    outline1( "LD (%s), A", _result );
    outline0( "LD A, H" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    outline0( "LD A, L" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void cpu_float_fast_tan( Environment * _environment, char * _angle, char * _result ) {

    MAKE_LABEL

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_fast_add, src_hw_z80_fp_fast_add_asm );
    deploy( fp_fast_tan, src_hw_z80_fp_fast_tan_asm );
    deploy( fp_fast_sin, src_hw_z80_fp_fast_sin_asm );
    deploy( fp_fast_cos, src_hw_z80_fp_fast_cos_asm );     
    deploy( fp_fast_div, src_hw_z80_fp_fast_div_asm );
    deploy( fp_fast_mod1, src_hw_z80_fp_fast_mod1_asm );
    deploy( fp_fast_add, src_hw_z80_fp_fast_add_asm );
    deploy( fp_fast_sub, src_hw_z80_fp_fast_sub_asm );
    deploy( fp_fast_sqr, src_hw_z80_fp_fast_sqr_asm );

    outline1( "LD A, (%s)", address_displacement( _environment, _angle, "+2" ) );
    outline0( "LD L, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _angle, "+1" ) );
    outline0( "LD H, A" );
    outline1( "LD A, (%s)", _angle );

    outline0( "CALL FPFASTTAN");

    outline1( "LD (%s), A", _result );
    outline0( "LD A, H" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    outline0( "LD A, L" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void cpu_float_fast_sqr( Environment * _environment, char * _value, char * _result ) {

    MAKE_LABEL

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_mul16, src_hw_z80_fp_mul16_asm );
    deploy( fp_fast_mul, src_hw_z80_fp_fast_mul_asm );
    deploy( fp_fast_sqr, src_hw_z80_fp_fast_sqr_asm );

    outline1( "LD A, (%s)", address_displacement( _environment, _value, "+2" ) );
    outline0( "LD L, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _value, "+1" ) );
    outline0( "LD H, A" );
    outline1( "LD A, (%s)", _value );
    
    outline0( "CALL FPFASTSQR");

    outline1( "LD (%s), A", _result );
    outline0( "LD A, H" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    outline0( "LD A, L" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void cpu_float_fast_mod1( Environment * _environment, char * _value, char * _result ) {

    MAKE_LABEL

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_fast_mod1, src_hw_z80_fp_fast_mod1_asm );

    outline1( "LD A, (%s)", address_displacement( _environment, _value, "+2" ) );
    outline0( "LD L, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _value, "+1" ) );
    outline0( "LD H, A" );
    outline1( "LD A, (%s)", _value );
    
    outline0( "CALL FPFASTMOD1");

    outline1( "LD (%s), A", _result );
    outline0( "LD A, H" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    outline0( "LD A, L" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void cpu_float_fast_neg( Environment * _environment, char * _value, char * _result ) {

    MAKE_LABEL

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_fast_neg, src_hw_z80_fp_fast_neg_asm );

    outline1( "LD A, (%s)", address_displacement( _environment, _value, "+2" ) );
    outline0( "LD L, A" );
    outline1( "LD A, (%s)", address_displacement( _environment, _value, "+1" ) );
    outline0( "LD H, A" );
    outline1( "LD A, (%s)", _value );
    
    outline0( "CALL FPFASTNEG");

    outline1( "LD (%s), A", _result );
    outline0( "LD A, H" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    outline0( "LD A, L" );
    outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void cpu_float_single_from_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_pushpop, src_hw_z80_fp_pushpop_asm );
    deploy( fp_single_from_16, src_hw_z80_fp_single_from_16_asm );

    outline1( "LD HL, (%s)", _value );
    outline1( "LD BC, %s", _result );
    if ( _signed ) {
        outline0( "CALL FPSINGLEFROM16S");
    } else {
        outline0( "CALL FPSINGLEFROM16U");
    }

}

void cpu_float_single_from_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_single_from_8, src_hw_z80_fp_single_from_8_asm );

    outline1( "LD A, (%s)", _value );
    outline1( "LD BC, %s", _result );
    if ( _signed ) {
        outline0( "CALL FPSINGLEFROM8S");
    } else {
        outline0( "CALL FPSINGLEFROM8U");
    }

}


void cpu_float_single_to_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_single_to_16, src_hw_z80_fp_single_to_16_asm );

    outline1( "LD HL, %s", _value );
    if ( _signed ) {
        outline0( "CALL FPSINGLETO16S");
    } else {
        outline0( "CALL FPSINGLETO16U");
    }
    outline1( "LD (%s), HL", _result );

}

void cpu_float_single_to_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_single_to_8, src_hw_z80_fp_single_to_8_asm );

    outline1( "LD HL, %s", _value );
    if ( _signed ) {
        outline0( "CALL FPSINGLETO8S");
    } else {
        outline0( "CALL FPSINGLETO8U");
    }
    outline1( "LD (%s), A", _result );

}

void cpu_float_single_add( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_pushpop, src_hw_z80_fp_pushpop_asm );
    deploy( fp_single_add, src_hw_z80_fp_single_add_asm );

    outline1( "LD DE, %s", _y );
    outline1( "LD HL, %s", _x );
    outline1( "LD BC, %s", _result );
    outline0( "CALL FPSINGLEADD");
    
}

void cpu_float_single_sub( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_pushpop, src_hw_z80_fp_pushpop_asm );
    deploy( fp_single_sub, src_hw_z80_fp_single_sub_asm );
    deploy( fp_single_add, src_hw_z80_fp_single_add_asm );

    outline1( "LD DE, %s", _y );
    outline1( "LD HL, %s", _x );
    outline1( "LD BC, %s", _result );
    outline0( "CALL FPSINGLESUB");
    
}

void cpu_float_single_mul( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_pushpop, src_hw_z80_fp_pushpop_asm );
    deploy( fp_c_times_bde, src_hw_z80_fp_c_times_bde_asm );
    deploy( fp_mul24_stack_based, src_hw_z80_fp_mul24_stack_based_asm );
    deploy( fp_single_mul, src_hw_z80_fp_single_mul_asm );

    outline1( "LD DE, %s", _y );
    outline1( "LD HL, %s", _x );
    outline1( "LD BC, %s", _result );
    outline0( "CALL FPSINGLEMUL");
    
}

void cpu_float_single_div( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_pushpop, src_hw_z80_fp_pushpop_asm );
    deploy( fp_div24_24, src_hw_z80_fp_div24_24_asm );
    deploy( fp_single_div, src_hw_z80_fp_single_div_asm );

    outline1( "LD DE, %s", _y );
    outline1( "LD HL, %s", _x );
    outline1( "LD BC, %s", _result );
    outline0( "CALL FPSINGLEDIV");
    
}

void cpu_float_single_cmp( Environment * _environment, char * _x, char * _y, char * _result ) {

    MAKE_LABEL

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_pushpop, src_hw_z80_fp_pushpop_asm );
    deploy( fp_single_sub, src_hw_z80_fp_single_sub_asm );
    deploy( fp_single_cmp, src_hw_z80_fp_single_cmp_asm );

    outline1( "LD DE, %s", _y );
    outline1( "LD HL, %s", _x );
    outline0( "CALL FPSINGLECMP");

    outline1( "JR Z, %sequal", label );
    outline1( "JR C, %sless", label );
    outline0( "LD A, 1" );
    outline1( "LD (%s), A", _result );
    outline1( "JP %sdone", label );
    outhead1( "%sequal:", label );
    outline0( "LD A, 0" );
    outline1( "LD (%s), A", _result );
    outline1( "JP %sdone", label );
    outhead1( "%sless:", label );
    outline0( "LD A, $ff" );
    outline1( "LD (%s), A", _result );
    outline1( "JP %sdone", label );
    outhead1( "%sdone:", label );

}

void cpu_float_single_neg( Environment * _environment, char * _value, char * _result ) {

    // MAKE_LABEL

    // deploy( fp_single_sub, src_hw_z80_fp_single_sub_asm );
    // deploy( fp_single_mod1, src_hw_z80_fp_single_mod1_asm );
    // deploy( fp_single_sin, src_hw_z80_fp_single_sin_asm );
    // deploy( fp_single_mul, src_hw_z80_fp_single_mul_asm );
    // deploy( fp_single_sqr, src_hw_z80_fp_single_sqr_asm );
    // deploy( fp_single_cos, src_hw_z80_fp_single_cos_asm );     
    // deploy( fp_single_div, src_hw_z80_fp_single_div_asm );

    // outline1( "LD A, (%s)", address_displacement( _environment, _angle, "+2" ) );
    // outline0( "LD L, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _angle, "+1" ) );
    // outline0( "LD H, A" );
    // outline1( "LD A, (%s)", _angle );

    // outline0( "CALL FPFSINGLESIN");

    // outline1( "LD (%s), A", _result );
    // outline0( "LD A, H" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // outline0( "LD A, L" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void cpu_float_single_sin( Environment * _environment, char * _angle, char * _result ) {

    MAKE_LABEL

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_c_times_bde, src_hw_z80_fp_c_times_bde_asm );
    deploy( fp_mul24_stack_based, src_hw_z80_fp_mul24_stack_based_asm );
    deploy( fp_single_vars, src_hw_z80_fp_single_vars_asm );
    deploy( fp_single_sin, src_hw_z80_fp_single_sin_asm );
    deploy( fp_single_cos, src_hw_z80_fp_single_cos_asm );
    deploy( fp_single_sub, src_hw_z80_fp_single_sub_asm );
    deploy( fp_single_mul, src_hw_z80_fp_single_mul_asm );
    deploy( fp_single_add, src_hw_z80_fp_single_add_asm );
    deploy( fp_single_neg, src_hw_z80_fp_single_neg_asm );
    deploy( fp_single_mod1, src_hw_z80_fp_single_mod1_asm );
    deploy( fp_single_abs, src_hw_z80_fp_single_abs_asm );
    deploy( fp_single_horner_step, src_hw_z80_fp_single_horner_step_asm );

    outline1( "LD HL, %s", _angle );
    outline1( "LD BC, %s", _result );
    outline0( "CALL FPSINGLESIN");
    // outline0( "LD A, (HL)" );
    // outline1( "LD (%s), A", _result );
    // outline0( "INC HL" );
    // outline0( "LD A, (HL)" );
    // outline1( "LD (%s), A", _result );
    // outline0( "INC HL" );
    // outline0( "LD A, (HL)" );
    // outline1( "LD (%s), A", _result );
    // outline0( "INC HL" );
    // outline0( "LD A, (HL)" );
    // outline1( "LD (%s), A", _result );
    // outline0( "INC HL" );

}

void cpu_float_single_cos( Environment * _environment, char * _angle, char * _result ) {

    MAKE_LABEL

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_c_times_bde, src_hw_z80_fp_c_times_bde_asm );
    deploy( fp_mul24_stack_based, src_hw_z80_fp_mul24_stack_based_asm );
    deploy( fp_mov4, src_hw_z80_fp_mov4_asm );
    deploy( fp_single_vars, src_hw_z80_fp_single_vars_asm );
    deploy( fp_single_sin, src_hw_z80_fp_single_sin_asm );
    deploy( fp_single_cos, src_hw_z80_fp_single_cos_asm );
    deploy( fp_single_sub, src_hw_z80_fp_single_sub_asm );
    deploy( fp_single_mul, src_hw_z80_fp_single_mul_asm );
    deploy( fp_single_add, src_hw_z80_fp_single_add_asm );
    deploy( fp_single_neg, src_hw_z80_fp_single_neg_asm );
    deploy( fp_single_mod1, src_hw_z80_fp_single_mod1_asm );
    deploy( fp_single_abs, src_hw_z80_fp_single_abs_asm );
    deploy( fp_single_horner_step, src_hw_z80_fp_single_horner_step_asm );

    outline1( "LD HL, %s", _angle );
    outline1( "LD BC, %s", _result );
    outline0( "CALL FPSINGLECOS");
    outline0( "LD A, (HL)" );
    outline1( "LD (%s), A", _result );
    outline0( "INC HL" );
    outline0( "LD A, (HL)" );
    outline1( "LD (%s), A", _result );
    outline0( "INC HL" );
    outline0( "LD A, (HL)" );
    outline1( "LD (%s), A", _result );
    outline0( "INC HL" );
    outline0( "LD A, (HL)" );
    outline1( "LD (%s), A", _result );
    outline0( "INC HL" );

}

void cpu_float_single_tan( Environment * _environment, char * _angle, char * _result ) {

    MAKE_LABEL

    deploy( fp_vars, src_hw_z80_fp_vars_asm );
    deploy( fp_c_times_bde, src_hw_z80_fp_c_times_bde_asm );
    deploy( fp_mul24_stack_based, src_hw_z80_fp_mul24_stack_based_asm );
    deploy( fp_single_vars, src_hw_z80_fp_single_vars_asm );
    deploy( fp_single_sin, src_hw_z80_fp_single_sin_asm );
    deploy( fp_single_cos, src_hw_z80_fp_single_cos_asm );
    deploy( fp_single_div, src_hw_z80_fp_single_div_asm );
    deploy( fp_single_sin, src_hw_z80_fp_single_tan_asm );
    deploy( fp_single_tan, src_hw_z80_fp_single_tan_asm );
    deploy( fp_single_neg, src_hw_z80_fp_single_neg_asm );
    deploy( fp_single_sub, src_hw_z80_fp_single_sub_asm );
    deploy( fp_single_mul, src_hw_z80_fp_single_mul_asm );
    deploy( fp_single_add, src_hw_z80_fp_single_add_asm );
    deploy( fp_single_mod1, src_hw_z80_fp_single_mod1_asm );
    deploy( fp_single_abs, src_hw_z80_fp_single_abs_asm );
    deploy( fp_single_horner_step, src_hw_z80_fp_single_horner_step_asm );


    outline1( "LD HL, %s", _angle );
    outline1( "LD BC, %s", _result );
    outline0( "CALL FPSINGLETAN");
    // outline0( "LD A, (HL)" );
    // outline1( "LD (%s), A", _result );
    // outline0( "INC HL" );
    // outline0( "LD A, (HL)" );
    // outline1( "LD (%s), A", _result );
    // outline0( "INC HL" );
    // outline0( "LD A, (HL)" );
    // outline1( "LD (%s), A", _result );
    // outline0( "INC HL" );
    // outline0( "LD A, (HL)" );
    // outline1( "LD (%s), A", _result );
    // outline0( "INC HL" );

}

void cpu_float_single_sqr( Environment * _environment, char * _value, char * _result ) {

    // MAKE_LABEL

    // deploy( fp_single_mul, src_hw_z80_fp_single_mul_asm );
    // deploy( fp_single_sqr, src_hw_z80_fp_single_sqr_asm );

    // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+2" ) );
    // outline0( "LD L, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+1" ) );
    // outline0( "LD H, A" );
    // outline1( "LD A, (%s)", _value );
    
    // outline0( "CALL FPsingleSQR");

    // outline1( "LD (%s), A", _result );
    // outline0( "LD A, H" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // outline0( "LD A, L" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void cpu_float_single_mod1( Environment * _environment, char * _value, char * _result ) {

    // MAKE_LABEL

    // deploy( fp_single_mod1, src_hw_z80_fp_single_mod1_asm );

    // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+2" ) );
    // outline0( "LD L, A" );
    // outline1( "LD A, (%s)", address_displacement( _environment, _value, "+1" ) );
    // outline0( "LD H, A" );
    // outline1( "LD A, (%s)", _value );
    
    // outline0( "CALL FPsingleMOD1");

    // outline1( "LD (%s), A", _result );
    // outline0( "LD A, H" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+1" ) );
    // outline0( "LD A, L" );
    // outline1( "LD (%s), A", address_displacement( _environment, _result, "+2" ) );

}

void cpu_address_table_build( Environment * _environment, char * _table, int * _values, char *_address[], int _count ) {

    outhead1("%s:", _table );
    for( int i=0; i<_count; ++i ) {
        outline2("DEFW $%4.4x, %s", _values[i], _address[i] );
    }

}

void cpu_address_table_lookup( Environment * _environment, char * _table, int _count ) {

    outhead1("LOOKFOR%s:", _table );
    if ( _count ) {
        outline1("LD HL, %s", _table );
        outline0("LD C, 0" );
        outhead1("LOOKFOR%sL1:", _table );
        outline0("LD A, (HL)" );
        outline0("INC HL" );
        outline0("LD B, A" );
        outline0("LD A, E" );
        outline0("CP B" );
        outline1("JR NZ, LOOKFOR%sNEXT3", _table );
        outline0("LD A, (HL)" );
        outline0("INC HL" );
        outline0("LD B, A" );
        outline0("LD A, D" );
        outline0("CP B" );
        outline1("JR NZ, LOOKFOR%sNEXT2", _table );
        outline0("LD A, (HL)" );
        outline0("INC HL" );
        outline0("LD E, A" );
        outline0("LD A, (HL)" );
        outline0("INC HL" );
        outline0("LD D, A" );
        outline0("RET" );
        outhead1("LOOKFOR%sNEXT3:", _table );
        outline0("INC HL" );
        outhead1("LOOKFOR%sNEXT2:", _table );
        outline0("INC HL" );
        outline0("INC HL" );
        outline0("INC C" );
        outline0("LD A, C" );
        outline1("CP $%4.4x", (_count+1) );
        outline1("JR NZ, LOOKFOR%sL1", _table );
    }
    outline0("RET" );

}

void cpu_address_table_call( Environment * _environment, char * _table, char * _value, char * _address ) {

    outline1("LD DE, (%s)", _value );
    outline1("CALL LOOKFOR%s", _table );
    outline1("LD (%s), DE", _address );

}

void cpu_move_8bit_signed_16bit_signed( Environment * _environment, char *_source, char *_destination ) {

    outline1("LD DE, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("ADD A, A" );
    outline0("SBC A" );
    outline0("LD (DE), A" );

}

void cpu_move_8bit_signed_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD DE, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("ADD A, A" );
    outline0("SBC A" );
    outline0("LD (DE), A" );

}

void cpu_move_8bit_unsigned_16bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD DE, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD A, 0" );
    outline0("LD (DE), A" );

}

void cpu_move_8bit_unsigned_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD DE, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD A, 0" );
    outline0("LD (DE), A" );

}

void cpu_move_8bit_signed_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD DE, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("ADD A, A" );
    outline0("SBC A" );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD (DE), A" );

}

void cpu_move_8bit_signed_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD DE, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("ADD A, A" );
    outline0("SBC A" );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD (DE), A" );

}

void cpu_move_8bit_unsigned_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD DE, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD A, 0" );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD A, 0" );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD A, 0" );
    outline0("LD (DE), A" );

}
void cpu_move_8bit_unsigned_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){
    
    outline1("LD DE, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD A, 0" );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD A, 0" );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD A, 0" );
    outline0("LD (DE), A" );

}

void cpu_move_16bit_signed_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, (%s)", _source );
    outline0("LD A, L" );
    outline1("LD (%s), A", _destination );

}
void cpu_move_16bit_signed_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, (%s)", _source );
    outline0("LD A, L" );
    outline1("LD (%s), A", _destination );

}
void cpu_move_16bit_unsigned_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, (%s)", _source );
    outline0("LD A, L" );
    outline1("LD (%s), A", _destination );

}
void cpu_move_16bit_unsigned_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, (%s)", _source );
    outline0("LD A, L" );
    outline1("LD (%s), A", _destination );

}

void cpu_move_16bit_signed_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD DE, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline1("LD A, (%s)", address_displacement( _environment, _source, "1" ) );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("ADD A, A" );
    outline0("SBC A" );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD (DE), A" );

}

void cpu_move_16bit_signed_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD DE, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline1("LD A, (%s)", address_displacement( _environment, _source, "1" ) );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("ADD A, A" );
    outline0("SBC A" );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD (DE), A" );

}

void cpu_move_16bit_unsigned_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD DE, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline1("LD A, (%s)", address_displacement( _environment, _source, "1" ) );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD A, 0" );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD (DE), A" );

}
void cpu_move_16bit_unsigned_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD DE, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline1("LD A, (%s)", address_displacement( _environment, _source, "1" ) );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD A, 0" );
    outline0("LD (DE), A" );
    outline0("INC DE" );
    outline0("LD (DE), A" );

}

void cpu_move_32bit_signed_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD A, (%s)", _source );
    outline1("LD (%s), A", _destination );

}
void cpu_move_32bit_signed_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD A, (%s)", _source );
    outline1("LD (%s), A", _destination );

}
void cpu_move_32bit_unsigned_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD A, (%s)", _source );
    outline1("LD (%s), A", _destination );

}
void cpu_move_32bit_unsigned_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD A, (%s)", _source );
    outline1("LD (%s), A", _destination );

}

void cpu_move_32bit_signed_16bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, (%s)", _source );
    outline1("LD (%s), HL", _destination );

}

void cpu_move_32bit_signed_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, (%s)", _source );
    outline1("LD (%s), HL", _destination );

}

void cpu_move_32bit_unsigned_16bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, (%s)", _source );
    outline1("LD (%s), HL", _destination );

}

void cpu_move_32bit_unsigned_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){
    
    outline1("LD HL, (%s)", _source );
    outline1("LD (%s), HL", _destination );

}

void cpu_float_fast_log( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED("LOG");

}

void cpu_float_single_log( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED("LOG");

}

void cpu_float_fast_exp( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED("EXP");

}

void cpu_float_single_exp( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED("EXP");

}


#endif