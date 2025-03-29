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

/****************************************************************************
 * INCLUDE SECTION 
 ****************************************************************************/

#include "../ugbc.h"

#include <math.h>

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#if defined(__gb__)

void sm83_init( Environment * _environment ) {

    // char duffDevice[38] = {
    //     // +00
    //     0x18, 0x00, 0xED, 0xA0, 0xED, 0xA0, 0xED, 0xA0,
    //     // +08
    //     0xED, 0xA0, 0xED, 0xA0, 0xED, 0xA0, 0xED, 0xA0,
    //     // +16
    //     0xED, 0xA0, 0xED, 0xA0, 0xED, 0xA0, 0xED, 0xA0,
    //     // +24
    //     0xED, 0xA0, 0xED, 0xA0, 0xED, 0xA0, 0xED, 0xA0,
    //     // +32
    //     0xED, 0xA0, 0xEA, 0x00, 0x00, 0xC9
    // };

    // variable_import( _environment, "DUFFDEVICEL0", VT_BUFFER, 36 );
    // variable_global( _environment, "DUFFDEVICEL0" );
    // variable_import( _environment, "DUFFDEVICEL1", VT_ADDRESS, 0 );
    // variable_global( _environment, "DUFFDEVICEL1" );

    // variable_retrieve( _environment, "DUFFDEVICEL0" )->readonly = 0;

    // variable_store_buffer( _environment, "DUFFDEVICEL0", duffDevice, sizeof( duffDevice ), 0 );

    // outline0( "LD HL, DUFFDEVICEL0");
    // outline0( "LD DE, 35");
    // outline0( "ADD HL, DE");
    // outline0( "LD DE, DUFFDEVICEL0");
    // outline0( "INC DE");
    // outline0( "INC DE");
    // outline0( "LD (HL), DE");

    variable_import( _environment, "IXR", VT_WORD, 0 );
    variable_global( _environment, "IXR" );
    variable_import( _environment, "IYR", VT_WORD, 0 );
    variable_global( _environment, "IYR" );

    variable_import( _environment, "IXLR", VT_BYTE, 0 );
    variable_global( _environment, "IXLR" );
    variable_import( _environment, "IXHR", VT_BYTE, 0 );
    variable_global( _environment, "IXHR" );
    variable_import( _environment, "IYLR", VT_BYTE, 0 );
    variable_global( _environment, "IYLR" );
    variable_import( _environment, "IYHR", VT_BYTE, 0 );
    variable_global( _environment, "IYHR" );

    variable_import( _environment, "HLS", VT_WORD, 0 );
    variable_global( _environment, "HLS" );
    variable_import( _environment, "FLAGS", VT_BYTE, 0 );
    variable_global( _environment, "FLAGS" );

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

    variable_import( _environment, "BCP", VT_WORD, 0 );
    variable_global( _environment, "BCP" );
    variable_import( _environment, "DEP", VT_WORD, 0 );
    variable_global( _environment, "DEP" );
    variable_import( _environment, "HLP", VT_WORD, 0 );
    variable_global( _environment, "HLP" );

}

void sm83_nop( Environment * _environment ) {

    outline0("NOP");

}

void sm83_ztoa( Environment * _environment ) {

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

void sm83_ctoa( Environment * _environment ) {

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
void sm83_beq( Environment * _environment, char * _label ) {

    inline( cpu_beq )

        outline1("JP Z, %s", _label);

    no_embedded( cpu_beq )

}

/**
 * @brief <i>Z80</i>: emit code to make long conditional jump

 * @param _environment Current calling environment
 * @param _label Destination of the conditional jump.
 */
void sm83_bneq( Environment * _environment, char * _label ) {

    inline( cpu_bneq )

        outline1("JP NZ, %s", _label);

    no_embedded( cpu_bneq )

}

void sm83_bveq( Environment * _environment, char * _value, char * _label ) {

    inline( cpu_bveq )

        outline1("LD A, (%s)", _value);
        outline0("CP 0");
        sm83_beq( _environment, _label );

    no_embedded( cpu_bneq )

}

void sm83_bvneq( Environment * _environment, char * _value, char * _label ) {

    inline( cpu_bvneq )

        outline1("LD A, (%s)", _value);
        outline0("CP 0");
        sm83_bneq( _environment, _label );

    no_embedded( cpu_bvneq )

}

void sm83_label( Environment * _environment, char * _label ) {
    outhead1("%s:", _label);
}

void sm83_peek( Environment * _environment, char * _address, char * _target ) {

    inline( cpu_peek )

        outline1("LD HL, (%s)", _address);
        outline0("LD A, (HL)");
        outline1("LD (%s), A", _target);

    no_embedded( cpu_peek )

}

void sm83_poke( Environment * _environment, char * _address, char * _source ) {

    inline( cpu_poke )

        outline1("LD A, (%s)", _source);
        outline1("LD HL, (%s)", _address);
        outline0("LD (HL), A");

    no_embedded( cpu_poke )

}

void sm83_poke_const( Environment * _environment, char * _address, int _source ) {

    // inline( cpu_poke )

        outline1("LD A, $%2.2x", _source);
        outline1("LD HL, (%s)", _address);
        outline0("LD (HL), A");

    // no_embedded( cpu_poke )

}

void sm83_peekw( Environment * _environment, char * _address, char * _target ) {

    inline( cpu_peek )

        outline1("LD HL, (%s)", _address);
        outline0("LD A, (HL)");
        outline1("LD (%s), A", _target);
        outline0("INC HL");
        outline0("LD A, (HL)");
        outline1("LD (%s), A", address_displacement( _environment, _target, "1" ) );

    no_embedded( cpu_peek )

}

void sm83_pokew( Environment * _environment, char * _address, char * _source ) {

    inline( cpu_poke )

        outline1("LD A, (%s)", _source);
        outline1("LD HL, (%s)", _address);
        outline0("LD (HL), A");
        outline1("LD A, (%s)", address_displacement( _environment, _source, "1" ) );
        outline0("INC HL");
        outline0("LD (HL), A");

    no_embedded( cpu_poke )

}

void sm83_pokew_const( Environment * _environment, char * _address, int _source ) {

    // inline( cpu_poke )

        outline1("LD A, (%s)", (unsigned char)(_source&0xff));
        outline1("LD HL, (%s)", _address);
        outline0("LD (HL), A");
        outline1("LD A, (%s)", (unsigned char)((_source>>8)&0xff));
        outline0("INC HL");
        outline0("LD (HL), A");

    // no_embedded( cpu_poke )

}

void sm83_peekd( Environment * _environment, char * _address, char * _target ) {

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

void sm83_poked( Environment * _environment, char * _address, char * _source ) {

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

void sm83_poked_const( Environment * _environment, char * _address, int _source ) {

    // inline( cpu_poke )

        outline1("LD A, (%s)", (unsigned char)((_source)&0xff));
        outline1("LD HL, (%s)", _address);
        outline0("LD (HL), A");
        outline1("LD A, (%s)", (unsigned char)((_source>>8)&0xff));
        outline0("INC HL");
        outline0("LD (HL), A");
        outline1("LD A, (%s)", (unsigned char)((_source>>16)&0xff));
        outline0("INC HL");
        outline0("LD (HL), A");
        outline1("LD A, (%s)", (unsigned char)((_source>>24)&0xff));
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
void sm83_fill_blocks( Environment * _environment, char * _address, char * _blocks, char * _pattern ) {

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
        outline0("CALL REPLACEMENT_LDIR");

        outline1("LD A, (%s)", _pattern);
        outline0("LD (HL),A")
        outline0("LD E,L");
        outline0("LD D,H");
        outline0("INC DE");
        outline0("LD (DE),A")
        outline0("LD C,255");
        outline0("LD A,0");
        outline0("LD B,A");
        outline0("CALL REPLACEMENT_LDIR");
        outhead1("%sdone:", label);

    embedded( cpu_fill_blocks, src_hw_sm83_cpu_fill_blocks_asm );

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
void sm83_fill( Environment * _environment, char * _address, char * _bytes, int _bytes_width, char * _pattern ) {

    MAKE_LABEL

    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_sm83_cpu_fill_asm );

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
void sm83_fill_size( Environment * _environment, char * _address, int _bytes, char * _pattern ) {

    MAKE_LABEL

    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_sm83_cpu_fill_asm );

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
void sm83_fill_size_value( Environment * _environment, char * _address, int _bytes, int _pattern ) {

    MAKE_LABEL

    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_sm83_cpu_fill_asm );

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
void sm83_fill_direct( Environment * _environment, char * _address, char * _bytes, char * _pattern ) {

    MAKE_LABEL

    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_sm83_cpu_fill_asm );

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
void sm83_fill_direct_size( Environment * _environment, char * _address, int _bytes, char * _pattern ) {

    MAKE_LABEL

    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_sm83_cpu_fill_asm );

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
void sm83_fill_direct_size_value( Environment * _environment, char * _address, int _bytes, int _pattern ) {

    MAKE_LABEL
    
    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_sm83_cpu_fill_asm );

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
void sm83_move_8bit( Environment * _environment, char *_source, char *_destination ) {
    
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
void sm83_store_8bit( Environment * _environment, char *_destination, int _value ) {

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
void sm83_store_char( Environment * _environment, char *_destination, int _value ) {

    inline( cpu_store_char )

        outline1("LD A, '%c'", ( _value & 0xff ) );
        outline1("LD (%s), A", _destination);

    no_embedded( cpu_store_char )

}

void sm83_store_8bit_with_offset( Environment * _environment, char *_destination, int _value, int _offset ) {

    inline( cpu_store_8bit_with_offset )

        outline1("LD DE, %s", _destination);
        outline1("ADD DE, $%2.2x", ( _offset & 0xff ) );
        outline1("LD A, $%2.2x", ( _value & 0xff ) );
        outline0("LD (DE), A");

    no_embedded( cpu_store_8bit_with_offset )

}

void sm83_store_8bit_with_offset2( Environment * _environment, char *_destination, char * _offset, int _value ) {

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
void sm83_compare_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

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
void sm83_compare_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _positive ) {

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

void sm83_compare_and_branch_8bit( Environment * _environment, char *_source, char * _destination,  char *_label, int _positive ) {

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
void sm83_compare_and_branch_8bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

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
void sm83_prepare_for_compare_and_branch_8bit( Environment * _environment, char *_source ) {

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
void sm83_execute_compare_and_branch_8bit_const( Environment * _environment, int _destination,  char *_label, int _positive ) {

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
void sm83_compare_and_branch_char_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

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
void sm83_less_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

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

    embedded( cpu_less_than_8bit, src_hw_sm83_cpu_less_than_8bit_asm );

        if ( _signed ) {

            outline1("LD A, (%s)", _destination);
            outline0("LD H, A");
            outline1("LD A, (%s)", _source);
            outline0("LD D, A");
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

void sm83_less_than_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

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

    embedded( cpu_less_than_8bit, src_hw_sm83_cpu_less_than_8bit_asm );

        if ( _signed ) {

            outline1("LD A, $%2.2x", _destination);
            outline0("LD H, A");
            outline1("LD A, (%s)", _source);
            outline0("LD D, A");
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

void sm83_less_than_and_branch_8bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _equal, int _signed ) {

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

    embedded( cpu_less_than_8bit, src_hw_sm83_cpu_less_than_8bit_asm );

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
void sm83_greater_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    sm83_less_than_8bit( _environment, _source, _destination, _other, !_equal, _signed );
    if ( _other ) {
        sm83_not_8bit( _environment, _other, _other );
    } else {
        sm83_not_8bit( _environment, _destination, _destination );
    }

}

void sm83_greater_than_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    sm83_less_than_8bit_const( _environment, _source, _destination, _other, !_equal, _signed );
    sm83_not_8bit( _environment, _other, _other );

}

/**
 * @brief <i>Z80</i>: emit code to add two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void sm83_math_add_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

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

void sm83_math_add_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

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
void sm83_math_sub_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

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
void sm83_math_double_8bit( Environment * _environment, char *_source, char *_other, int _signed ) {

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

void sm83_math_mul_8bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _signed ) {

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
            sm83_complement2_16bit( _environment, _other, NULL );
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

    embedded( cpu_math_mul_8bit_to_16bit, src_hw_sm83_cpu_math_mul_8bit_to_16bit_asm );

        if ( _signed ) {

            outline1("LD A, (%s)", _destination);
            outline0("LD (IYLR), A");
            outline1("LD A, (%s)", _source);
            outline0("LD (IXLR), A");
            outline0("CALL CPUMUL8B8T16S");
            outline1("LD (%s), HL", _other);

        } else {

            outline1("LD A, (%s)", _destination);
            outline0("LD (IYLR), A");
            outline1("LD A, (%s)", _source);
            outline0("LD (IXLR), A");
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
void sm83_math_div2_const_8bit( Environment * _environment, char *_source, int _steps, int _signed, char * _remainder ) {

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
            sm83_complement2_16bit( _environment, _source, _source );
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
            sm83_complement2_16bit( _environment, _source, _source );
            outhead1("%sdone:", label );
        } else {
            outline1("LD A, (%s)", _source );
            while( _steps ) {
                outline0("SRA A" );
                --_steps;
            }
            outline1("LD (%s), A", _source );
        }

    embedded( cpu_math_div2_const_8bit, src_hw_sm83_cpu_math_div2_const_8bit_asm );

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
void sm83_math_mul2_const_8bit( Environment * _environment, char *_source, int _steps, int _signed ) {

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

    embedded( cpu_math_mul2_const_8bit, src_hw_sm83_cpu_math_mul2_const_8bit_asm );

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
void sm83_math_complement_const_8bit( Environment * _environment, char *_source, int _value ) {

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
void sm83_math_and_const_8bit( Environment * _environment, char *_source, int _mask ) {

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
void sm83_move_16bit( Environment * _environment, char *_source, char *_destination ) {
    
    inline( cpu_move_16bit )

        outline1("LD HL, (%s)", _source );
        outline1("LD (%s), HL", _destination );

    no_embedded( cpu_move_16bit )

}

void sm83_addressof_16bit( Environment * _environment, char *_source, char *_destination ) {
    
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
void sm83_store_16bit( Environment * _environment, char *_destination, int _value ) {

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
void sm83_compare_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

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

    embedded( cpu_compare_16bit, src_hw_sm83_cpu_compare_16bit_asm )

        outline1("LD HL, %s", _source);
        outline1("LD DE, %s", _destination);
        outline1("LD A, $%2.2x", ( 0xff*(1-_positive)) );
        outline0("LD (IXLR), A" );
        outline1("LD A, $%2.2x", ( (0xff*_positive) ) );
        outline0("LD (IXHR), A" );
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
void sm83_compare_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _positive ) {

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

    embedded( cpu_compare_16bit, src_hw_sm83_cpu_compare_16bit_asm )

        outline1("LD HL, %s", _source);
        outline1("LD DE, $%4.4x", _destination);
        outline1("LD A, $%2.2x", ( 0xff*(1-_positive)) );
        outline0("LD (IXLR), A" );
        outline1("LD A, $%2.2x", ( (0xff*_positive) ) );
        outline0("LD (IXHR), A" );
        outline0("CALL CPUCOMPARE16CONST");
        outline1("LD (%s), A", _other);

    done( )

}

void sm83_compare_and_branch_16bit( Environment * _environment, char *_source, char *_destination,  char *_label, int _positive ) {

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
void sm83_compare_and_branch_16bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

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
void sm83_less_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    inline( cpu_less_than_16bit )

        if ( _signed ) {

            outline1("LD HL, (%s)", _source);
            outline0("LD D, H");
            outline0("LD E, L");
            outline1("LD HL, (%s)", _destination);
            outline0("LD A, H" );
            outline0("XOR D" );
            outline1("JP M,%scmpgte2", label );
            outline0("CALL SBC_HL_DE" );
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

    embedded( cpu_less_than_16bit, src_hw_sm83_cpu_less_than_16bit_asm );

        if ( _signed ) {

            outline1("LD HL, (%s)", _source);
            outline0("LD D, H");
            outline0("LD E, L");
            outline1("LD HL, (%s)", _destination);
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

            outline1("LD HL, (%s)", _source);
            outline0("LD D, H");
            outline0("LD E, L");
            outline1("LD HL, (%s)", _destination);
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

void sm83_less_than_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    inline( cpu_less_than_16bit )

        if ( _signed ) {

            outline1("LD HL, (%s)", _source);
            outline0("LD D, H");
            outline0("LD E, L");
            outline1("LD HL, $%4.4x", ( _destination & 0xffff ) );
            outline0("LD A, H" );
            outline0("XOR D" );
            outline1("JP M,%scmpgte2", label );
            outline0("CALL SBC_HL_DE" );
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

    embedded( cpu_less_than_16bit, src_hw_sm83_cpu_less_than_16bit_asm );

        if ( _signed ) {

            outline1("LD HL, (%s)", _source);
            outline0("LD D, H");
            outline0("LD E, L");
            outline1("LD HL, $%4.4x", ( _destination & 0Xffff ) );
            if ( _equal ) {
                outline0("CALL CPULTE16S");
            } else {
                outline0("CALL CPULT16S");
            }
            outline1("LD (%s), A", _other);

        } else {

            outline1("LD HL, (%s)", _source);
            outline0("LD D, H");
            outline0("LD E, L");
            outline1("LD HL, $%4.4x", ( _destination & 0Xffff ) );
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
void sm83_greater_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    sm83_less_than_16bit( _environment, _source, _destination, _other, !_equal, _signed );
    if ( _other ) {
        sm83_not_8bit( _environment, _other, _other );
    } else {
        sm83_not_8bit( _environment, _destination, _destination );
    }

}

void sm83_greater_than_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    sm83_less_than_16bit_const( _environment, _source, _destination, _other, !_equal, _signed );
    sm83_not_8bit( _environment, _other, _other );

}

/**
 * @brief <i>Z80</i>: emit code to add two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add (memory)
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void sm83_math_add_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_add_16bit )

        outline1("LD HL, (%s)", _destination);
        outline0("LD D, H");
        outline0("LD E, L");
        outline1("LD HL, (%s)", _source );
        outline0("ADD HL, DE" );
        if ( _other ) {
            outline1("LD (%s), HL", _other );
        } else {
            outline1("LD (%s), HL", _destination );
        }

    no_embedded( cpu_math_add_16bit )

}

void sm83_math_add_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

    inline( cpu_math_add_16bit )

        outline1("LD HL, (%s)", _source );
        outline1("LD DE, $%4.4x", ( _destination & 0xffff ) );
        outline0("ADD HL, DE" );
        outline1("LD (%s), HL", _other );

    no_embedded( cpu_math_add_16bit )

}

void sm83_math_add_16bit_with_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

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
void sm83_math_double_16bit( Environment * _environment, char *_source, char *_other, int _signed ) {
    
    inline( cpu_math_double_16bit )

        outline1("LD HL, (%s)", _source);
        outline0("SLA L" );
        outline0("RL H" );
        if ( _other ) {
            outline1("LD (%s), HL", _other );
        } else {
            outline1("LD (%s), HL", _source );
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
void sm83_math_mul_16bit_to_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _signed ) {

    MAKE_LABEL

    no_inline( cpu_math_mul_16bit_to_32bit )

    embedded( cpu_math_mul_16bit_to_32bit, src_hw_sm83_cpu_math_mul_16bit_to_32bit_asm );

        if ( _signed ) {

            outline1("LD HL, (%s)", _source );
            outline0("LD (IXR), HL" );
            outline1("LD HL, (%s)", _destination );
            outline0("LD (IYR), HL" );
            outline0("CALL CPUMUL16B16T32S")
            outline1("LD (%s), HL", _other );
            outline0("LD H, B");
            outline0("LD L, C");
            outline1("LD (%s), HL", address_displacement( _environment, _other, "2" ) );

        } else {

            outline1("LD HL, (%s)", _source );
            outline0("LD B, H");
            outline0("LD C, L");
            outline1("LD HL, (%s)", _destination);
            outline0("LD D, H");
            outline0("LD E, L");
            outline0("CALL CPUMUL16B16T32U")
            outline1("LD (%s), HL", _other );
            outline0("LD H, B");
            outline0("LD L, C");
            outline1("LD (%s), BC", address_displacement( _environment, _other, "2" ) );

        }

    done(  )

}

/**
 * @brief <i>Z80</i>: emit code to subtract two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to subtract
 * @param _destination Second value to subtract and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void sm83_math_sub_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_sub_16bit )

        outline1("LD HL, (%s)", _destination);
        outline0("LD D, H");
        outline0("LD E, L");
        outline1("LD HL, (%s)", _source );
        outline0("AND A" );
        outline0("CALL SBC_HL_DE" );
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
void sm83_math_complement_const_16bit( Environment * _environment, char *_source, int _value ) {

    inline( cpu_math_complement_const_16bit )

        outline1("LD HL, (%s)", _source);
        outline0("LD D, H");
        outline0("LD E, L");
        outline1("LD HL, $%4.4x", _value );
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
void sm83_math_div2_const_16bit( Environment * _environment, char *_source, int _steps, int _signed, char * _remainder ) {

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
            sm83_complement2_16bit( _environment, _source, _source );
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
            sm83_complement2_16bit( _environment, _source, _source );
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

    embedded( cpu_math_div2_const_16bit, src_hw_sm83_cpu_math_div2_const_16bit_asm )

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
void sm83_math_mul2_const_16bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    inline( cpu_math_mul2_const_16bit )

        MAKE_LABEL

        if ( _signed ) {
            outline1("LD A, (%s)", address_displacement(_environment, _source, "1") );
            outline0("AND $80" );
            outline0("PUSH AF" );
            outline0("CP 0" );
            outline1("JR Z, %spos", label );
            sm83_complement2_16bit( _environment, _source, _source );
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
            sm83_complement2_16bit( _environment, _source, _source );
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
void sm83_math_and_const_16bit( Environment * _environment, char *_source, int _mask ) {

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
void sm83_move_32bit( Environment * _environment, char *_source, char *_destination ) {

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
void sm83_store_32bit( Environment * _environment, char *_destination, int _value ) {

    inline( cpu_store_32bit )

        outline1("LD HL, $%4.4x", ( _value & 0xffff ) );
        outline1("LD (%s), HL", _destination );
        outline1("LD HL, $%2.2x", ( ( _value >> 16 ) & 0xffff ) );
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
void sm83_compare_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

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

    embedded( cpu_compare_32bit, src_hw_sm83_cpu_compare_32bit_asm )

        outline1("LD HL, %s", _source);
        outline1("LD DE, %s", _destination);
        outline1("LD A, $%2.2x", ( 0xff*(1-_positive)) );
        outline0("LD (IXLR), A" );
        outline1("LD A, $%2.2x", ( (0xff*_positive) ) );
        outline0("LD (IXHR), A" );
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
void sm83_compare_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _positive ) {

    no_inline( cpu_compare_32bit )

    embedded( cpu_compare_32bit, src_hw_sm83_cpu_compare_32bit_asm )

        outline1("LD HL, $%4.4x", (unsigned int)((_destination>>16)&0xffff));
        outline0("LD (IYR), HL");
        outline1("LD HL, $%4.4x", (unsigned int)(_destination&0xffff));
        outline0("LD E, L");
        outline0("LD D, H");
        outline1("LD HL, %s", _source);
        outline1("LD A, $%2.2x", ( 0xff*(1-_positive)) );
        outline0("LD (IXLR), A" );
        outline1("LD A, $%2.2x", ( (0xff*_positive) ) );
        outline0("LD (IXHR), A" );
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
void sm83_compare_and_branch_32bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

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
void sm83_less_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    no_inline( cpu_less_than_32bit )

    embedded( cpu_less_than_32bit, src_hw_sm83_cpu_less_than_32bit_asm );

        if ( _signed ) {

            outline1("LD DE, %s", _destination);
            outline1("LD HL, %s", _source);
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

            outline1("LD DE, %s", _destination);
            outline1("LD HL, %s", _source);
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

void sm83_less_than_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    no_inline( cpu_less_than_32bit )

    embedded( cpu_less_than_32bit, src_hw_sm83_cpu_less_than_32bit_asm );

        if ( _signed ) {

            outline1("LD DE, $%4.4x", ( ( _destination >> 16 ) & 0xffff ) );
            outline0("PUSH DE" );
            outline1("LD DE, $%4.4x", ( _destination & 0xffff ) );
            outline0("PUSH DE" );
            outline0("LD DE, SP" );
            // outline0("LD IY, DE" );
            outline1("LD HL, %s", _source);
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
            // outline0("LD IY, DE" );
            outline1("LD HL, %s", _source);
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

/**
 * @brief <i>Z80</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void sm83_greater_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    sm83_less_than_32bit( _environment, _source, _destination, _other, !_equal, _signed );
    if ( _other ) {
        sm83_not_8bit( _environment, _other, _other );
    } else {
        sm83_not_8bit( _environment, _destination, _destination );
    }

}

void sm83_greater_than_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    sm83_less_than_32bit_const( _environment, _source, _destination, _other, !_equal, _signed );
    sm83_not_8bit( _environment, _other, _other );

}

/**
 * @brief <i>Z80</i>: emit code to add two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void sm83_math_add_32bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_add_32bit )

        outline1("LD HL, (%s)", _destination);
        outline0("LD D, H");
        outline0("LD E, L");
        outline1("LD HL, (%s)", _source );
        outline0("CALL REPLACEMENT_EXX" );
        outline1("LD HL, (%s)", address_displacement(_environment, _destination, "2"));
        outline0("LD D, H");
        outline0("LD E, L");
        outline1("LD HL, (%s)", address_displacement(_environment, _source, "2") );
        outline0("CALL REPLACEMENT_EXX" );
        outline0("ADD HL, DE" );
        outline0("CALL REPLACEMENT_EXX" );
        outline0("CALL ADC_HL_DE" );
        outline0("CALL REPLACEMENT_EXX" );
        if ( _other ) {
            outline1("LD (%s), HL", _other );
            outline0("CALL REPLACEMENT_EXX" );
            outline1("LD (%s), HL", address_displacement( _environment, _other, "2" ) );
        } else {
            outline1("LD (%s), HL", _destination );
            outline0("CALL REPLACEMENT_EXX" );
            outline1("LD (%s), HL", address_displacement( _environment, _destination, "2" ) );
        }

    no_embedded( cpu_math_add_32bit )

}

void sm83_math_add_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

    inline( cpu_math_add_32bit_const )

        outline1("LD HL, (%s)", _source );
        outline1("LD DE, $%4.4x", ( _destination & 0xffff ) );
        outline0("CALL REPLACEMENT_EXX" );
        outline1("LD HL, (%s)", address_displacement(_environment, _source, "2") );
        outline1("LD DE, $%4.4x", ( ( _destination >> 16 ) & 0xffff ) );
        outline0("CALL REPLACEMENT_EXX" );
        outline0("ADD HL, DE" );
        outline0("CALL REPLACEMENT_EXX" );
        outline0("CALL ADC_HL_DE" );
        outline0("CALL REPLACEMENT_EXX" );
        outline1("LD (%s), HL", _other );
        outline0("CALL REPLACEMENT_EXX" );
        outline1("LD (%s), HL", address_displacement( _environment, _other, "2" ) );

    no_embedded( cpu_math_add_32bit_const )

}

/**
 * @brief <i>Z80</i>: emit code to double a 32 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 * @todo Not yet implemented
 */
void sm83_math_double_32bit( Environment * _environment, char *_source, char *_other, int _signed ) {

    inline( cpu_math_double_32bit )

        if ( _other ) {
            sm83_math_add_32bit( _environment, _source, _source, _other );
        } else {
            sm83_math_add_32bit( _environment, _source, _source, _source );
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
void sm83_math_sub_32bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_sub_32bit )

        MAKE_LABEL

        outline1("LD HL, (%s)", _destination);
        outline0("LD D, H");
        outline0("LD E, L");
        outline1("LD HL, (%s)", _source );
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
        outline0("CALL REPLACEMENT_EXX" );
        outline1("LD HL, (%s)", address_displacement(_environment, _destination, "2"));
        outline0("LD D, H");
        outline0("LD E, L");
        outline1("LD HL, (%s)", address_displacement(_environment, _source, "2") );
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
        outline0("CALL REPLACEMENT_EXX" );
        outline0("ADD HL, DE" );
        outline0("CALL REPLACEMENT_EXX" );
        outline0("CALL ADC_HL_DE" );
        outline0("CALL REPLACEMENT_EXX" );
        if ( _other ) {
            outline1("LD (%s), HL", _other );
            outline0("CALL REPLACEMENT_EXX" );
            outline1("LD (%s), HL", address_displacement( _environment, _other, "2" ) );
        } else {
            outline1("LD (%s), HL", _destination );
            outline0("CALL REPLACEMENT_EXX" );
            outline1("LD (%s), HL", address_displacement( _environment, _destination, "2" ) );
        }

    no_embedded( cpu_math_sub_32bit )

}

/**
 * @brief <i>Z80</i>: emit code to calculate a 32 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void sm83_math_complement_const_32bit( Environment * _environment, char *_source, int _value ) {

    inline( cpu_math_complement_const_32bit )

        outline1("LD HL, (%s)", _source);
        outline0("LD D, H");
        outline0("LD E, L");
        outline1("LD HL, $%4.4x", ( _value & 0xffff ) );
        outline0("LD A, E" );
        outline0("XOR $FF" );
        outline0("LD E, A" );
        outline0("LD A, D" );
        outline0("XOR $FF" );
        outline0("LD D, A" );
        outline0("INC DE" );
        outline0("CALL REPLACEMENT_EXX" );
        outline1("LD HL, (%s)", address_displacement(_environment, _source, "2"));
        outline0("LD D, H");
        outline0("LD E, L");
        outline1("LD HL, $%4.4x", ( ( _value >> 16 ) & 0xffff ) );
        outline0("LD A, E" );
        outline0("XOR $FF" );
        outline0("LD E, A" );
        outline0("LD A, D" );
        outline0("XOR $FF" );
        outline0("LD D, A" );
        outline0("INC DE" );
        outline0("CALL REPLACEMENT_EXX" );
        outline0("ADD HL, DE" );
        outline0("CALL REPLACEMENT_EXX" );
        outline0("CALL ADC_HL_DE" );
        outline0("CALL REPLACEMENT_EXX" );
        outline1("LD (%s), HL", _source );
        outline0("CALL REPLACEMENT_EXX" );
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
void sm83_math_div2_const_32bit( Environment * _environment, char *_source, int _steps, int _signed, char * _remainder ) {

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
            sm83_complement2_32bit( _environment, _source, _source );
            outline1("JMP %spos2", label );
            outhead1("%spos:", label );
            outhead1("%spos2:", label );
            outline1("LD HL, (%s)", _source);
            outline0("LD D, H");
            outline0("LD E, L");
            outline0("PUSH HL");
            outline1("LD HL, (%s)", address_displacement(_environment, _source, "2") );
            outline0("LD B, H");
            outline0("LD C, L");
            outline0("POP HL");
            while( _steps ) {
                outline0("SRA B" );
                outline0("RR C" );
                outline0("RR D" );
                outline0("RR E" );
                --_steps;
            }
            outline1("LD (%s),DE", _source );
            outline0("PUSH HL");
            outline0("LD H, B");
            outline0("LD L, C");
            outline1("LD (%s), HL", address_displacement(_environment, _source, "2") );
            outline0("POP HL");
            outline0("POP AF" );
            outline0("AND $80" );
            outline0("CP 0" );
            outline1("JR Z, %sdone", label );
            sm83_complement2_32bit( _environment, _source, _source );
            outhead1("%sdone:", label );
        } else {
            outline1("LD HL, (%s)", address_displacement(_environment, _source, "2") );
            outline0("LD BC, HL" );
            outline1("LD HL, (%s)", _source);
            while( _steps ) {
                outline0("SRA B" );
                outline0("RR C" );
                outline0("RR H" );
                outline0("RR L" );
                --_steps;
            }
            outline1("LD (%s), HL", _source );
            outline0("LD HL, BC");
            outline1("LD (%s), HL", address_displacement( _environment, _source, "2" ) );    
        }

    no_embedded( cpu_math_div2_const_32bit )

}

/**
 * @brief <i>Z80</i>: emit code to double for several times a 32 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 * @todo Not yet implemented
 */
void sm83_math_mul2_const_32bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    inline( cpu_math_mul2_const_32bit )

        MAKE_LABEL

        if ( _signed ) {
            outline1("LD A, (%s)", address_displacement(_environment, _source, "3") );
            outline0("AND $80" );
            outline0("CP 0" );
            outline0("PUSH AF" );
            outline1("JR Z, %spos", label );
            sm83_complement2_32bit( _environment, _source, _source );
            outline1("JMP %spos2", label );
            outhead1("%spos:", label );
            outhead1("%spos2:", label );
            outline1("LD HL, (%s)", address_displacement(_environment, _source, "2"));
            outline0("LD D, H");
            outline0("LD E, L");
            outline1("LD HL, (%s)", _source );
            while( _steps ) {
                outline0("SLA L" );
                outline0("RL H" );
                outline0("RL E" );
                outline0("RL D" );
                --_steps;
            }
            outline1("LD (%s), HL", _source );
            outline0("LD H, D");
            outline0("LD L, E");
            outline1("LD (%s), HL", address_displacement( _environment, _source, "2" ) );
            outline0("POP AF" );
            outline0("AND $80" );
            outline0("CP 0" );
            outline1("JR Z, %sdone", label );
            sm83_complement2_32bit( _environment, _source, _source );
            outhead1("%sdone:", label );
        } else {
            outline1("LD HL, (%s)", address_displacement(_environment, _source, "2"));
            outline0("LD D, H");
            outline0("LD E, L");
            outline1("LD HL, (%s)", _source );
            while( _steps ) {
                outline0("SLA L" );
                outline0("RL H" );
                outline0("RL D" );
                outline0("RL E" );
                --_steps;
            }
            outline1("LD (%s), HL", _source );
            outline0("LD H, D");
            outline0("LD L, E");
            outline1("LD (%s), HL", address_displacement( _environment, _source, "2" ) );
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
void sm83_math_and_const_32bit( Environment * _environment, char *_source, int _mask ) {

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
void sm83_combine_nibbles( Environment * _environment, char * _low_nibble, char * _hi_nibble, char * _byte ) {

    no_inline( cpu_combine_nibbles )

    embedded( cpu_combine_nibbles, src_hw_sm83_cpu_combine_nibbles_asm );

        outline1("LD A, (%s)", _hi_nibble );
        outline1("LD HL, %s", _low_nibble );
        outline1("LD DE, %s", _byte );
        outline0("CALL CPUCOMBINENIBBLES" );

    done( )

}

void sm83_jump( Environment * _environment, char * _label ) {

    outline1("jp %s", _label );

}

void sm83_call_addr( Environment * _environment, int _address ) {

    outline1("call $%4.4x", _address );

}

void sm83_call( Environment * _environment, char * _label ) {

    outline1("call %s", _label );

}

void sm83_call_indirect( Environment * _environment, char * _value ) {

    MAKE_LABEL

    char indirectLabel[MAX_TEMPORARY_STORAGE]; sprintf( indirectLabel, "%sindirect", label );

    outline0( "LD (CALLINDIRECTSAVEHL), HL" )
    outline1( "LD HL, (%s)", _value )
    outline0( "LD (CALLINDIRECT+1), HL" )
    outline0( "LD HL, (CALLINDIRECTSAVEHL)" )
    outline0( "CALL CALLINDIRECT" );

}

void sm83_jump_indirect( Environment * _environment, char * _value ) {

    outline1( "LD HL, (%s)", _value )
    outline0( "JP (HL)" );

}

int sm83_register_decode( Environment * _environment, char * _register ) {

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
        } else if ( strcmp( _register, "BC" ) == 0 ) {
            result = REGISTER_BC;
        } else if ( strcmp( _register, "DE" ) == 0 ) {
            result = REGISTER_DE;
        } else if ( strcmp( _register, "HL" ) == 0 ) {
            result = REGISTER_HL;
        } else if ( strcmp( _register, "(IXLR)" ) == 0 ) {
            result = REGISTER_IXL;
        } else if ( strcmp( _register, "(IXHR)" ) == 0 ) {
            result = REGISTER_IXH;
        } else if ( strcmp( _register, "(IYLR)" ) == 0 ) {
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

void sm83_set_asmio( Environment * _environment, int _asmio, int _value ) {

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
                outline0( "LD (IXLR), A" );
                outline0( "POP AF" );
                break;
            case REGISTER_IXH:
                outline0( "PUSH AF" );
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "LD (IXHR), A" );
                outline0( "POP AF" );
                break;
            case REGISTER_IYL:
                outline0( "PUSH AF" );
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "LD (IYLR), A" );
                outline0( "POP AF" );
                break;
            case REGISTER_IYH:
                outline0( "PUSH AF" );
                outline1( "LD A, $%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "LD (IYHR), A" );
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

void sm83_set_asmio_indirect( Environment * _environment, int _asmio, char * _value ) {

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
                outline0( "LD (IXLR), A" );
                outline0( "POP AF" );
                break;
            case REGISTER_IXH:
                outline0( "PUSH AF" );
                outline1( "LD A, (%s)", _value );
                outline0( "LD (IXHR), A" );
                outline0( "POP AF" );
                break;
            case REGISTER_IYL:
                outline0( "PUSH AF" );
                outline1( "LD A, (%s)", _value );
                outline0( "LD (IYLR), A" );
                outline0( "POP AF" );
                break;
            case REGISTER_IYH:
                outline0( "PUSH AF" );
                outline1( "LD A, (%s)", _value );
                outline0( "LD (IYHR), A" );
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

void sm83_get_asmio_indirect( Environment * _environment, int _asmio, char * _value ) {

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
                outline0( "LD A, (IXLR)" );
                outline1( "LD (%s), A", _value );
                outline0( "POP AF" );
                break;
            case REGISTER_IXH:
                outline0( "PUSH AF" );
                outline0( "LD A, (IXHR)" );
                outline1( "LD (%s), A", _value );
                outline0( "POP AF" );
                break;
            case REGISTER_IYL:
                outline0( "PUSH AF" );
                outline0( "LD A, (IYLR)" );
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

void sm83_return( Environment * _environment ) {

    outline0("RET" );

}

void sm83_pop( Environment * _environment ) {

    outline0("POP HL" );

}

void sm83_halt( Environment * _environment ) {

    MAKE_LABEL

    outhead1("%s:", label );
    outline1("jp %s", label );

}

void sm83_end( Environment * _environment ) {

    outline0("DI");
    outline0("HLT");

}

void sm83_random( Environment * _environment, char * _entropy ) {

    MAKE_LABEL

    inline( cpu_random )

        if ( _entropy ) {
            outline0("LD HL, (CPURANDOM_SEED)");
            outline0("LD B, (HL)");
            outline0("INC HL");
            outline0("LD A, (HL)");
            outline0("XOR B");
            outline1("LD HL, (%s)", _entropy);
            outline0("LD D, H");
            outline0("LD E, L");
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
            outline0("PUSH HL");
            outline1("LD HL, (%s)", _entropy);
            outline0("LD D, H");
            outline0("LD E, L");
            outline0("POP HL");
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

    embedded( cpu_random, src_hw_sm83_cpu_random_asm );
       
    done()


}

void sm83_random_8bit( Environment * _environment, char * _entropy, char * _result ) {

    sm83_random( _environment, _entropy );

    if ( _result ) {
        outline0("CALL CPURANDOM16" );
        outline0("LD A, H" );
        outline1("LD (%s), A", _result );
    }

}

void sm83_random_16bit( Environment * _environment, char * _entropy, char * _result ) {

    sm83_random( _environment, _entropy );

    if ( _result ) {
        outline0("CALL CPURANDOM16" );
        outline1("LD (%s), HL", _result );
    }

}

void sm83_random_32bit( Environment * _environment, char * _entropy, char * _result ) {

    sm83_random( _environment, _entropy );

    if ( _result ) {
        outline0("CALL CPURANDOM32" );
        outline1("LD (%s), HL", _result );
        outline1("LD (%s), BC", address_displacement( _environment, _result, "2" ) );
    }

}

void sm83_limit_16bit( Environment * _environment, char * _variable, int _value ) {

    MAKE_LABEL

    outline1( "LD A, (%s)", _variable );
    outline1( "CP $%2.2x", _value );
    outline1( "JR C, %s", label );
    outline1( "SUB $%2.2x", _value );
    outline1( "LD (%s), A", _variable );
    outhead1( "%s:", label );

}

void sm83_busy_wait( Environment * _environment, char * _timing ) {

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
void sm83_port_out( Environment * _environment, char * _port, char * _value ) {

    outline1("LD A, (%s)", _value );
    outline1("OUT (%s), A", _port );

}

void sm83_logical_and_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

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

void sm83_and_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD DE, %s", _right );
    outline0("LD A, (HL)" );
    outline0("LD B, A" );
    outline0("LD A, (DE)" );
    outline0("AND B" );
    outline1("LD (%s), A", _result );

}

void sm83_and_8bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _left );
    outline1("OR $%2.2x", _right );
    outline1("LD (%s), A", _result );

}

void sm83_and_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD DE, %s", _right );
    outline0("LD A, (HL)" );
    outline0("LD B, A" );
    outline0("LD A, (DE)" );
    outline0("AND B" );
    outline1("LD (%s), A", _result );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("LD B, A" );
    outline0("LD A, (DE)" );
    outline0("AND B" );
    outline1("LD (%s), A", address_displacement( _environment, _result, "1" ) );

}

void sm83_and_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD DE, %s", _right );
    outline0("LD A, (HL)" );
    outline0("LD B, A" );
    outline0("LD A, (DE)" );
    outline0("AND B" );
    outline1("LD (%s), A", _result );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("LD B, A" );
    outline0("LD A, (DE)" );
    outline0("AND B" );
    outline1("LD (%s), A", address_displacement( _environment, _result, "1" ) );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("LD B, A" );
    outline0("LD A, (DE)" );
    outline0("AND B" );
    outline1("LD (%s), A", address_displacement( _environment, _result, "2" ) );
    outline0("INC HL" );
    outline0("INC DE" );
    outline0("LD A, (HL)" );
    outline0("LD B, A" );
    outline0("LD A, (DE)" );
    outline0("AND B" );
    outline1("LD (%s), A", address_displacement( _environment, _result, "3" ) );

}

void sm83_logical_or_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

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

void sm83_or_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD A, (%s)", _right );
    outline0("LD B, A" );
    outline0("LD A, (HL)" );
    outline0("OR B" );
    outline1("LD (%s), A", _result );

}

void sm83_or_8bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _left );
    outline1("OR $%2.2x", _right );
    outline1("LD (%s), A", _result );

}


void sm83_or_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD A, (%s)", _right );
    outline0("LD B, A" );
    outline0("LD A, (HL)" );
    outline0("OR B" );
    outline1("LD (%s), A", _result );
    outline0("INC HL" );
    outline1("LD A, (%s)", address_displacement( _environment, _right, "1" ) );
    outline0("LD B, A" );
    outline0("LD A, (HL)" );
    outline0("OR B" );
    outline1("LD (%s), A", address_displacement( _environment, _result, "1" ) );
    outline0("INC HL" );

}

void sm83_or_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline1("LD A, (%s)", _right );
    outline0("LD B, A" );
    outline0("LD A, (HL)" );
    outline0("OR B" );
    outline1("LD (%s), A", _result );
    outline0("INC HL" );
    outline1("LD A, (%s)", address_displacement( _environment, _right, "1" ) );
    outline0("LD B, A" );
    outline0("LD A, (HL)" );
    outline0("OR B" );
    outline1("LD (%s), A", address_displacement( _environment, _result, "1" ) );
    outline0("INC HL" );
    outline1("LD A, (%s)", address_displacement( _environment, _right, "2" ) );
    outline0("LD B, A" );
    outline0("LD A, (HL)" );
    outline0("OR B" );
    outline1("LD (%s), A", address_displacement( _environment, _result, "2" ) );
    outline0("INC HL" );
    outline1("LD A, (%s)", address_displacement( _environment, _right, "3" ) );
    outline0("LD B, A" );
    outline0("LD A, (HL)" );
    outline0("OR B" );
    outline1("LD (%s), A", address_displacement( _environment, _result, "3" ) );

}

void sm83_xor_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _left );
    outline0("LD B, A" );
    outline1("LD A, (%s)", _right );
    outline0("XOR B" );
    outline1("LD (%s), A", _result );

}

void sm83_xor_8bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline0("LD A, (HL)" );
    outline1("XOR $%2.2x", (unsigned char)(_right&0xff) );
    outline1("LD (%s), A", _result );

}

void sm83_xor_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline0("LD A, (HL)" );
    outline0("LD B, A" );
    outline1("LD A, (%s)", _right );
    outline0("XOR B" );
    outline1("LD (%s), A", _result );
    outline0("INC HL" );
    outline0("LD A, (HL)" );
    outline0("LD B, A" );
    outline1("LD A, (%s)", address_displacement( _environment, _right, "1" ) );
    outline0("XOR B" );
    outline1("LD (%s), A", address_displacement( _environment, _result, "1" ) );
    outline0("INC HL" );

}

void sm83_xor_16bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

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


void sm83_xor_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LD HL, %s", _left );
    outline0("LD A, (HL)" );
    outline0("LD B, A" );
    outline1("LD A, (%s)", _right );
    outline0("XOR B" );
    outline1("LD (%s), A", _result );
    outline0("INC HL" );
    outline0("LD A, (HL)" );
    outline0("LD B, A" );
    outline1("LD A, (%s)", address_displacement( _environment, _right, "1" ) );
    outline0("XOR B" );
    outline1("LD (%s), A", address_displacement( _environment, _result, "1" ) );
    outline0("INC HL" );
    outline0("LD A, (HL)" );
    outline0("LD B, A" );
    outline1("LD A, (%s)", address_displacement( _environment, _right, "2" ) );
    outline0("XOR B" );
    outline1("LD (%s), A", address_displacement( _environment, _result, "2" ) );
    outline0("INC HL" );
    outline0("LD A, (HL)" );
    outline0("LD B, A" );
    outline1("LD A, (%s)", address_displacement( _environment, _right, "3" ) );
    outline0("XOR B" );
    outline1("LD (%s), A", address_displacement( _environment, _result, "3" ) );

}

void sm83_xor_32bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

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

void sm83_swap_8bit( Environment * _environment, char * _left, char * _right ) {

    no_inline( cpu_swap_8bit )

    embedded( cpu_swap_8bit, src_hw_sm83_cpu_swap_asm ) // it is not an error: swap 8/16/32 shares code

        outline1("LD HL, %s", _right );
        outline1("LD DE, %s", _left );
        outline0("LD B, 1" );
        outline0("CALL CPUSWAP" );

    done( )

}    

void sm83_swap_16bit( Environment * _environment, char * _left, char * _right ) {

    no_inline( cpu_swap_8bit )

    embedded( cpu_swap_8bit, src_hw_sm83_cpu_swap_asm ) // it is not an error: swap 8/16/32 shares code

        outline1("LD HL, %s", _right );
        outline1("LD DE, %s", _left );
        outline0("LD B, 2" );
        outline0("CALL CPUSWAP" );

    done( )

}

void sm83_swap_32bit( Environment * _environment, char * _left, char * _right ) {

    no_inline( cpu_swap_8bit )

    embedded( cpu_swap_8bit, src_hw_sm83_cpu_swap_asm ) // it is not an error: swap 8/16/32 shares code

        outline1("LD HL, %s", _right );
        outline1("LD DE, %s", _left );
        outline0("LD B, 4" );
        outline0("CALL CPUSWAP" );

    done( )
    
}

void sm83_logical_not_8bit( Environment * _environment, char * _value, char * _result ) {

    outline1("LD A, (%s)", _value );
    outline0("XOR $FF" );
    outline1("LD (%s), A", _result );

}

void sm83_not_8bit( Environment * _environment, char * _value, char * _result ) {

    outline1("LD A, (%s)", _value );
    outline0("XOR $FF" );
    outline1("LD (%s), A", _result );

}

void sm83_not_16bit( Environment * _environment, char * _value, char * _result ) {

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

void sm83_not_32bit( Environment * _environment, char * _value, char * _result ) {

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

void sm83_di( Environment * _environment ) {

    outline0("DI" );

}

void sm83_ei( Environment * _environment ) {

    outline0("EI" );

}

void sm83_inc( Environment * _environment, char * _variable ) {

    outline1("LD A, (%s)", _variable  );
    outline0("INC A" );
    outline1("LD (%s), A", _variable  );

}

void sm83_dec( Environment * _environment, char * _variable ) {

    outline1("LD A, (%s)", _variable  );
    outline0("DEC A" );
    outline1("LD (%s), A", _variable  );

}

void sm83_inc_16bit( Environment * _environment, char * _variable ) {

    outline1("LD HL, (%s)", _variable  );
    outline0("INC HL" );
    outline1("LD (%s), HL", _variable  );

}

void sm83_inc_32bit( Environment * _environment, char * _variable ) {

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

void sm83_dec_16bit( Environment * _environment, char * _variable ) {

    outline1("LD HL, (%s)", _variable  );
    outline0("DEC HL" );
    outline1("LD (%s), HL", _variable  );

}

void sm83_dec_32bit( Environment * _environment, char * _variable ) {

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

void sm83_mem_move( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    deploy( duff, src_hw_sm83_duff_asm );

    outline1("LD HL, (%s)", _destination);
    outline0("LD D, H");
    outline0("LD E, L");
    outline1("LD HL, (%s)", _source);
    outline1("LD A, (%s)", _size);
    outline0("LD C, A");
    outline0("LD B, 0");
    outline0("CALL DUFFDEVICE");

}

void sm83_mem_move_16bit( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    deploy( duff, src_hw_sm83_duff_asm );

    outline1("LD HL, (%s)", _destination);
    outline0("LD D, H");
    outline0("LD E, L");
    outline1("LD HL, (%s)", _size);
    outline0("LD BC, HL");
    outline1("LD HL, (%s)", _source);
    outline0("CALL DUFFDEVICE");

}

void sm83_mem_move_direct( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    deploy( duff, src_hw_sm83_duff_asm );

    outline1("LD HL, %s", _source);
    outline1("LD DE, %s", _destination);
    outline1("LD A, (%s)", _size);
    outline0("LD C, A");
    outline0("LD B, 0");
    outline0("CALL DUFFDEVICE");

}

void sm83_mem_move_direct2( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    deploy( duff, src_hw_sm83_duff_asm );

    outline1("LD HL, (%s)", _size);
    outline0("LD BC, HL");
    outline1("LD HL, (%s)", _source);
    outline1("LD DE, %s", _destination);
    outline0("CALL DUFFDEVICE");

}

void sm83_mem_move_direct2_size( Environment * _environment, char *_source, char *_destination,  int _size ) {

    deploy( duff, src_hw_sm83_duff_asm );

    outline1("LD HL, (%s)", _source);
    outline1("LD DE, %s", _destination);
    outline1("LD BC, $%4.4x", _size);
    outline0("CALL DUFFDEVICE");

}

void sm83_mem_move_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size > 0 ) {

        deploy( duff, src_hw_sm83_duff_asm );

        outline1("LD HL, (%s)", _destination);
        outline0("LD D, H");
        outline0("LD E, L");
        outline1("LD HL, (%s)", _source);
        outline1("LD A, $%2.2x", ( _size & 0xff ) );
        outline0("LD C, A");
        outline1("LD B, $%2.2x", ( _size >> 8 ) & 0xff );
        outline0("CALL DUFFDEVICE");

    }

}

void sm83_mem_move_direct_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size > 0 ) {

        deploy( duff, src_hw_sm83_duff_asm );

        outline1("LD HL, %s", _source);
        outline1("LD DE, %s", _destination);
        outline1("LD A, $%2.2x", ( _size & 0xff ) );
        outline0("LD C, A");
        outline1("LD B, $%2.2x", ( _size >> 8 ) & 0xff );
        outline0("CALL DUFFDEVICE");
    }

}

void sm83_mem_move_direct_indirect_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size ) {

        deploy( duff, src_hw_sm83_duff_asm );

        outline1("LD HL, (%s)", _destination);
        outline0("LD D, H");
        outline0("LD E, L");
        outline1("LD HL, %s", _source);
        outline1("LD A, $%2.2x", ( _size & 0xff ) );
        outline0("LD C, A");
        outline1("LD B, $%2.2x", ( _size >> 8 ) & 0xff );
        outline0("CALL DUFFDEVICE");
    }

}

void sm83_mem_move_indirect_direct_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size ) {

        deploy( duff, src_hw_sm83_duff_asm );

        outline1("LD HL, (%s)", _source);
        outline1("LD DE, %s", _destination);
        outline1("LD A, $%2.2x", ( _size & 0xff ) );
        outline0("LD C, A");
        outline1("LD B, $%2.2x", ( _size >> 8 ) & 0xff );
        outline0("CALL DUFFDEVICE");
    }

}

void sm83_compare_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD A, (%s)", _size);
    outline0("CP 0");
    outline1("JR Z, %sequal", label);
    outline0("LD C, A");
    outline1("LD HL, (%s)", _destination);
    outline0("LD D, H");
    outline0("LD E, L");
    outline1("LD HL, (%s)", _source);
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

void sm83_compare_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD HL, (%s)", _destination);
    outline0("LD D, H");
    outline0("LD E, L");
    outline1("LD HL, (%s)", _source);
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

void sm83_less_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD HL, (%s)", _destination);
    outline0("LD D, H");
    outline0("LD E, L");
    outline1("LD HL, (%s)", _source);
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

void sm83_less_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD HL, (%s)", _destination);
    outline0("LD D, H");
    outline0("LD E, L");
    outline1("LD HL, (%s)", _source);
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

void sm83_greater_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD HL, (%s)", _destination);
    outline0("LD D, H");
    outline0("LD E, L");
    outline1("LD HL, (%s)", _source);
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

void sm83_greater_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("LD HL, (%s)", _destination);
    outline0("LD D, H");
    outline0("LD E, L");
    outline1("LD HL, (%s)", _source);
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

void sm83_math_add_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

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

void sm83_math_sub_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    outline1("LD HL, (%s)", _source );
    outline0("LD DE, 0" );
    outline1("LD A, (%s)", _destination );
    outline0("LD E, A" );
    outline0("CALL SBC_HL_DE" );
    if ( _other ) {
        outline1("LD (%s), HL", _other );
    } else {
        outline1("LD (%s), HL", _destination );
    }

}

void sm83_uppercase( Environment * _environment, char *_source, char *_size, char *_result ) {

    MAKE_LABEL

    if ( _result ) {
        outline1("LD HL, (%s)", _result);
        outline0("LD D, H");
        outline0("LD E, L");
    } else {
        outline1("LD HL, (%s)", _source);
        outline0("LD D, H");
        outline0("LD E, L");
    }
    outline1("LD A, (%s)", _size);
    outline0("LD C, A" );
    outline1("LD HL, (%s)", _source );
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

void sm83_lowercase( Environment * _environment, char *_source, char *_size, char *_result ) {

    MAKE_LABEL

    if ( _result ) {
        outline1("LD HL, (%s)", _result);
        outline0("LD D, H");
        outline0("LD E, L");
    } else {
        outline1("LD HL, (%s)", _source);
        outline0("LD D, H");
        outline0("LD E, L");
    }
    outline1("LD A, (%s)", _size);
    outline0("LD C, A" );
    outline1("LD HL, (%s)", _source );
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

void sm83_convert_string_into_8bit( Environment * _environment, char * _string, char * _len, char * _value ) {

    Variable * temp = variable_temporary( _environment, VT_WORD, "(temp)" );

    sm83_convert_string_into_16bit( _environment, _string, _len, temp->realName );

    sm83_move_8bit( _environment, temp->realName, _value );
  
}

void sm83_convert_string_into_16bit( Environment * _environment, char * _string, char * _len, char * _value ) {

    MAKE_LABEL

    outline0("LD HL, 0" );
    outline0("LD (IXR), HL" );
    outline1("LD A, (%s)", _len );
    outline0("LD (IXR), A" );

    outline0("LD A, 0" );
    outline1("LD (%s), A", _value );
    outline1("LD (%s+1), A", _value );

    outline1("LD HL, (%s)", _string );

    outhead1("%srepeat:", label );

    outline0("LD A, (HL)" );
    outline0("CP $40" );
    outline1("JP NC, %send", label);
    outline0("CP $30" );
    outline1("JP C, %send", label);
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
    outline0("CALL ADC_HL_DE" );
    outline0("CALL ADC_HL_BC" );
    outline1("LD (%s), HL", _value );
    outline0("POP HL" );


    // MULT x 10

    outline0("INC HL" );
    outline0("PUSH HL" );
    outline0("LD HL, (IXR)" );
    outline0("DEC HL" );
    outline0("LD (IXR), HL" );
    outline0("POP HL" );
    outline0("LD A, 0" );
    outline0("PUSH HL" );
    outline0("LD HL, (IXR)" );
    outline0("CP L" );
    outline0("POP HL" );
    outline1("JR Z,%send", label );

    outline0("PUSH HL" );

    outline0("PUSH HL" );
    outline1("LD HL, (%s)", _value );
    outline0("LD D, H");
    outline0("LD E, L");
    outline0("POP HL" );

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

void sm83_fill_indirect( Environment * _environment, char * _address, char * _size, char * _pattern, int _size_size ) {

    MAKE_LABEL

    // Use the current bitmap address as starting address for filling routine.
    outline1("LD HL, (%s)", _address );
    outline0("LD D, H");
    outline0("LD E, L");
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

void sm83_flip( Environment * _environment, char * _source, char * _size, char * _destination ) {

    no_inline( cpu_flip )

    embedded( cpu_flip, src_hw_sm83_cpu_flip_asm );

        outline1("LD HL, (%s)", _destination );
        outline0("LD D, H");
        outline0("LD E, L");
        outline1("LD HL, (%s)", _source);
        outline1("LD A, (%s)", _size);
        outline0("CALL CPUFLIP");

    done(  )

}

void sm83_move_8bit_indirect( Environment * _environment, char *_source, char * _value ) {

    outline1("LD HL, (%s)", _value );
    outline0("LD D, H");
    outline0("LD E, L");
    outline1("LD A, (%s)", _source);
    outline0("LD (DE), A");

}

void sm83_move_8bit_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

    outline1("LD HL, %s", _value);
    outline1("LD A, (%s)", _offset );
    outline0("LD E, A" );
    outline0("LD D, 0" );
    outline0("ADD HL, DE" );
    outline1("LD A, (%s)", _source);
    outline0("LD (HL), A");

}

void sm83_move_8bit_indirect_with_offset( Environment * _environment, char *_source, char * _value, int _offset ) {

    outline1("LD HL, (%s)", _value);
    outline1("LD DE, $%2.2x", ( _offset & 0xff ) );
    outline0("ADD HL, DE" );
    outline1("LD A, (%s)", _source);
    outline0("LD (HL), A");

}

void sm83_move_8bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    outline1("LD HL, (%s)", _value );
    outline0("LD D, H");
    outline0("LD E, L");
    outline0("LD A, (DE)");
    outline1("LD (%s), A", _source);

}

void sm83_move_8bit_indirect2_8bit( Environment * _environment, char * _value, char * _offset, char *_source ) {

    outline1("LD HL, %s", _value);
    outline1("LD A, (%s)", _offset);
    outline0("LD E, A");
    outline0("LD A, 0");
    outline0("LD D, A");
    outline0("ADD HL, DE");
    outline0("LD A, (HL)");
    outline1("LD (%s), A", _source );

}

void sm83_move_8bit_indirect2_16bit( Environment * _environment, char * _value, char * _offset, char *_source ) {

    outline1("LD HL, (%s)", _offset );
    outline0("LD D, H");
    outline0("LD E, L");
    outline1("LD HL, %s", _value);
    outline0("ADD HL, DE");
    outline0("LD A, (HL)");
    outline1("LD (%s), A", _source );

}

void sm83_move_16bit_indirect( Environment * _environment, char *_source, char * _value ) {

    outline1("LD HL, (%s)", _value );
    outline0("LD D, H");
    outline0("LD E, L");
    outline1("LD HL, (%s)", _source);
    outline0("LD A, L");
    outline0("LD (DE), A");
    outline0("INC DE");
    outline0("LD A, H");
    outline0("LD (DE), A");

}

void sm83_move_16bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    outline1("LD HL, (%s)", _value );
    outline0("LD D, H");
    outline0("LD E, L");
    outline0("LD A, (DE)");
    outline1("LD (%s), A", _source);
    outline0("INC DE");
    outline0("LD A, (DE)");
    outline1("LD (%s), A", address_displacement(_environment, _source, "1"));

}

void sm83_move_16bit_indirect2_8bit( Environment * _environment, char * _value, char * _offset, char *_source ) {

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

void sm83_move_32bit_indirect( Environment * _environment, char *_source, char * _value ) {

    outline1("LD HL, (%s)", _value );
    outline0("LD D, H");
    outline0("LD E, L");
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

void sm83_move_nbit_indirect( Environment * _environment, int _n, char *_source, char * _value ) {

    outline1("LD HL, (%s)", _value );
    outline0("LD D, H");
    outline0("LD E, L");

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

void sm83_move_32bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    outline1("LD HL, (%s)", _value );
    outline0("LD D, H");
    outline0("LD E, L");
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

void sm83_move_nbit_indirect2( Environment * _environment, int _n, char * _value, char *_source ) {

    outline1("LD HL, (%s)", _value );
    outline0("LD D, H");
    outline0("LD E, L");

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

void sm83_math_div_32bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        outline1("LD A, (%s)", address_displacement(_environment, _source, "3"));
        outline0("AND $80");
        outline0("CP 0" );
        outline0("PUSH AF");
        outline1("JR Z,%spositive", label);
        sm83_complement2_32bit( _environment, _source, NULL );
        outhead1("%spositive:", label);
        outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
        outline0("AND $80");
        outline0("CP 0" );
        outline0("PUSH AF");
        outline1("JR Z,%spositive2", label);
        sm83_complement2_16bit( _environment, _destination, NULL );
        outhead1("%spositive2:", label);

        outline1("LD A, (%s)", _destination);
        outline0("LD E, A");
        outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
        outline0("LD D, A");
        outline0("PUSH HL");
        outline1("LD HL, (%s)", _source);
        outline0("LD (IXR), HL");
        outline0("POP HL");
        outline1("LD A, (%s)", address_displacement(_environment, _source, "2"));
        outline0("LD C, A");
        outline1("LD A, (%s)", address_displacement(_environment, _source, "3"));

        outline0("LD HL, 0");
        outline0("LD B, 32");
        outhead1("%sdiv32a:", label);

        outline0("PUSH HL");
        outline0("LD HL, (IXR)");
        outline0("ADD HL, HL");
        outline0("LD (IXR), HL");
        outline0("POP HL");
        
        outline0("RL C");
        outline0("RLA");
        outline0("CALL ADC_HL_HL");
        outline1("JR C, %sdiv32ov", label);
        outline0("CALL SBC_HL_DE");
        outline1("JR NC, %sdiv32setbit", label);
        outline0("ADD HL, DE");
        outline1("DJNZ %sdiv32a", label);
        outline1("JR %sdiv32end", label);
        outhead1("%sdiv32ov:", label);
        outline0("OR A");
        outline0("CALL SBC_HL_DE");
        outhead1("%sdiv32setbit:", label);
        outline0("PUSH HL");
        outline0("LD HL, (IXR)");
        outline0("INC HL");
        outline0("LD (IXR), HL");
        outline0("POP HL");
        outline1("DJNZ %sdiv32a", label);
        outhead1("%sdiv32end:", label);

        outline1("LD (%s), A", address_displacement(_environment, _other, "3"));
        outline0("LD A, C" );
        outline1("LD (%s), A", address_displacement(_environment, _other, "2"));

        outline0("PUSH HL");
        outline0("LD HL, (IXR)");
        outline1("LD (%s), HL", _other);
        outline0("POP HL");

        outline0("LD A, L");
        outline1("LD (%s), A", _other_remainder);
        outline0("LD A, H");
        outline1("LD (%s), A", address_displacement(_environment, _other_remainder, "1"));

        outline0("POP AF");
        outline0("LD B, A");
        outline0("CMP $80");
        outline1("JR NZ, %srepositive", label);
        sm83_complement2_16bit( _environment, _destination, NULL );
        outhead1("%srepositive:", label);
        outline0("POP AF");
        outline0("LD C, A");
        outline0("CMP $80");
        outline1("JR NZ, %srepositive2", label );
        sm83_complement2_32bit( _environment, _source, NULL );
        outhead1("%srepositive2:", label);
        outline0("LD A, B");
        outline0("XOR C");
        outline0("AND $80");
        outline0("CP $80");
        outline1("JR NZ, %srepositive3", label );
        sm83_complement2_32bit( _environment, _other, NULL );
        outhead1("%srepositive3:", label);

    } else {

	    outline1("LD HL, (%s)", _source);
	    outline0("LD (IXR), HL");
	    outline1("LD HL, (%s)", address_displacement(_environment, _source, "2"));
	    outline0("LD A, L");
	    outline0("LD C, A");
	    outline0("LD A, H");

        outline0("PUSH HL");
        outline1("LD HL, (%s)", _destination );
        outline0("LD D, H");
        outline0("LD E, L");
        outline0("POP HL");

	    outline0("LD HL, 0");
        outline0("LD B, 32");
        outhead1("%sloop1:", label);

        outline0("PUSH HL");
        outline0("LD HL, (IXR)");
        outline0("ADD HL, HL");
        outline0("LD (IXR), HL");
        outline0("POP HL");

        outline0("RL C");
        outline0("RLA");
        outline0("CALL ADC_HL_HL");
        outline1("JR C, %sloop2", label);
        outline0("CALL SBC_HL_DE");
        outline1("JR NC, %sloop3", label);
        outline0("ADD HL, DE");
        outline1("DJNZ %sloop1", label);
        outline1("JR %sdone", label);
        outhead1("%sloop2:", label);
        outline0("OR A");
        outline0("CALL SBC_HL_DE");
        outhead1("%sloop3:", label);
        outline0("PUSH HL");
        outline0("LD HL, (IXR)");
        outline0("INC HL");
        outline0("LD (IXR), HL");
        outline0("POP HL");
        outline1("DJNZ %sloop1", label);
        outhead1("%sdone:", label);

	    outline1("LD (%s), HL", _other_remainder);
	    outline0("LD H, A");
	    outline0("LD A, C");
	    outline0("LD L, C");
	    outline1("LD (%s), HL", _other);
	    outline0("LD HL, (IXR)");
	    outline1("LD (%s), HL", _other);

    }
 
}

void sm83_math_div_32bit_to_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        int destination = abs(_destination);

        outline1("LD A, (%s)", address_displacement(_environment, _source, "3"));
        outline0("AND $80");
        outline0("CP 0" );
        outline0("PUSH AF");
        outline1("JR Z,%spositive", label);
        sm83_complement2_32bit( _environment, _source, NULL );
        outhead1("%spositive:", label);

        outline1("LD DE, $%4.4x", destination);

        outline1("LD HL, (%s)", _source);
        outline0("LD (IXR), HL");

        outline1("LD A, (%s)", address_displacement(_environment, _source, "2"));
        outline0("LD C, A");
        outline1("LD A, (%s)", address_displacement(_environment, _source, "3"));

        outline0("LD HL, 0");
        outline0("LD B, 32");
        outhead1("%sdiv32a:", label);

        outline0("PUSH HL");
        outline0("LD HL, (IXR)");
        outline0("ADD HL, HL");
        outline0("LD (IXR), HL");
        outline0("POP HL");

        outline0("RL C");
        outline0("RLA");
        outline0("CALL ADC_HL_HL");
        outline1("JR C, %sdiv32ov", label);
        outline0("CALL SBC_HL_DE");
        outline1("JR NC, %sdiv32setbit", label);
        outline0("ADD HL, DE");
        outline1("DJNZ %sdiv32a", label);
        outline1("JR %sdiv32end", label);
        outhead1("%sdiv32ov:", label);
        outline0("OR A");
        outline0("CALL SBC_HL_DE");
        outhead1("%sdiv32setbit:", label);
        outline0("PUSH HL");
        outline0("LD HL, (IXR)");
        outline0("INC HL");
        outline0("LD (IXR), HL");
        outline0("POP HL");
        outline1("DJNZ %sdiv32a", label);
        outhead1("%sdiv32end:", label);

        outline1("LD (%s), A", address_displacement(_environment, _other, "3"));
        outline0("LD A, C" );
        outline1("LD (%s), A", address_displacement(_environment, _other, "2"));

        outline0("PUSH HL");
        outline0("LD HL, (IXR)");
        outline1("LD (%s), HL", _other);
        outline0("POP HL");

        outline0("LD A, L");
        outline1("LD (%s), A", _other_remainder);
        outline0("LD A, H");
        outline1("LD (%s), A", address_displacement(_environment, _other_remainder, "1"));

        outline1("LD B, $%2.2x", (_destination < 0) ? 0x80 : 0x00 );
        outhead1("%srepositive:", label);
        outline0("POP AF");
        outline0("LD C, A");
        outline0("CMP $80");
        outline1("JR NZ, %srepositive2", label );
        sm83_complement2_32bit( _environment, _source, NULL );
        outhead1("%srepositive2:", label);
        outline0("LD A, B");
        outline0("XOR C");
        outline0("AND $80");
        outline0("CP $80");
        outline1("JR NZ, %srepositive3", label );
        sm83_complement2_32bit( _environment, _other, NULL );
        outhead1("%srepositive3:", label);

    } else {

	    outline1("LD HL, (%s)", _source);
	    outline0("LD (IXR), HL");
	    outline1("LD HL, (%s)", address_displacement(_environment, _source, "2"));
	    outline0("LD A, L");
	    outline0("LD C, A");
	    outline0("LD A, H");
	    outline1("LD DE, $%4.4x", _destination);

	    outline0("LD HL, 0");
        outline0("LD B, 32");
        outhead1("%sloop1:", label);

        outline0("PUSH HL");
        outline0("LD HL, (IXR)");
        outline0("ADD HL, HL");
        outline0("LD (IXR), HL");
        outline0("POP HL");

        outline0("RL C");
        outline0("RLA");
        outline0("CALL ADC_HL_HL");
        outline1("JR C, %sloop2", label);
        outline0("CALL SBC_HL_DE");
        outline1("JR NC, %sloop3", label);
        outline0("ADD HL, DE");
        outline1("DJNZ %sloop1", label);
        outline1("JR %sdone", label);
        outhead1("%sloop2:", label);
        outline0("OR A");
        outline0("CALL SBC_HL_DE");
        outhead1("%sloop3:", label);
        outline0("PUSH AF");
        outline0("LD A, (IXR)");
        outline0("INC A");
        outline0("LD (IXR), A");
        outline0("POP AF");
        outline1("DJNZ %sloop1", label);
        outhead1("%sdone:", label);

	    outline1("LD (%s), HL", _other_remainder);
	    outline0("LD H, A");
	    outline0("LD A, C");
	    outline0("LD L, C");
	    outline1("LD (%s), HL", _other);
	    outline0("LD HL, (IXR)");
	    outline1("LD (%s), HL", _other);

    }
 
}

void sm83_math_div_16bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
        outline0("AND $80");
        outline0("CP 0" );
        outline0("PUSH AF");
        outline1("JR Z,%spositive", label);
        sm83_complement2_16bit( _environment, _source, NULL );
        outhead1("%spositive:", label);
        outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
        outline0("AND $80");
        outline0("CP 0" );
        outline0("PUSH AF");
        outline1("JR Z,%spositive2", label);
        sm83_complement2_16bit( _environment, _destination, NULL );
        outhead1("%spositive2:", label);

        outline1("LD HL, %s", _source);
        outline0("LD A, (HL)");
        outline0("LD C, A");
        outline0("INC HL");
        outline0("LD A, (HL)");

        outline0("PUSH HL");
        outline1("LD HL, (%s)", _destination);
        outline0("LD D, H");
        outline0("LD E, L");
        outline0("POP HL");

        outline0("LD HL, 0");
        outline0("LD B, 16");
        outhead1("%sloop:", label );
        // outline0("SLL C");
        outline0("SCF");
        outline0("RL C");
        outline0("RLA");
        outline0("CALL ADC_HL_HL");
        outline0("CALL SBC_HL_DE");
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
        sm83_complement2_16bit( _environment, _destination, NULL );
        outhead1("%srepositive:", label);
        outline0("POP AF");
        outline0("LD C, A");
        outline0("CMP $80");
        outline1("JR NZ, %srepositive2", label );
        sm83_complement2_16bit( _environment, _source, NULL );
        outhead1("%srepositive2:", label);
        outline0("LD A, B");
        outline0("XOR C");
        outline0("AND $80");
        outline0("CP $80");
        outline1("JR NZ, %srepositive3", label );
        sm83_complement2_16bit( _environment, _other, NULL );
        outhead1("%srepositive3:", label);

    } else {

        outline1("LD HL, %s", _source);
        outline0("LD A, (HL)");
        outline0("LD C, A");
        outline0("INC HL");
        outline0("LD A, (HL)");

        outline0("PUSH HL");
        outline1("LD HL, (%s)", _destination);
        outline0("LD D, H");
        outline0("LD E, L");
        outline0("POP HL");

        outline0("LD HL, 0");
        outline0("LD B, 16");
        outhead1("%sloop:", label );
        // outline0("SLL C");
        outline0("SCF");
        outline0("RL C");
        outline0("RLA");
        outline0("CALL ADC_HL_HL");
        outline0("CALL SBC_HL_DE");
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

void sm83_math_div_16bit_to_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        int destination = abs(_destination);

        outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
        outline0("AND $80");
        outline0("CP 0" );
        outline0("PUSH AF");
        outline1("JR Z,%spositive", label);
        sm83_complement2_16bit( _environment, _source, NULL );
        outhead1("%spositive:", label);
        // outline1("LD A, $%2.2x", (unsigned char)( (_destination>>8) & 0xff));
        // outline0("AND $80");
        // outline0("CP 0" );
        // outline0("PUSH AF");
        // outline1("JR Z,%spositive2", label);
        // sm83_complement2_16bit( _environment, _destination, NULL );
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
        // outline0("SLL C");
        outline0("SCF");
        outline0("RL C");
        outline0("RLA");
        outline0("CALL ADC_HL_HL");
        outline0("CALL SBC_HL_DE");
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
        // sm83_complement2_16bit( _environment, _destination, NULL );
        outhead1("%srepositive:", label);
        outline0("POP AF");
        outline0("LD C, A");
        outline0("CMP $80");
        outline1("JR NZ, %srepositive2", label );
        sm83_complement2_16bit( _environment, _source, NULL );
        outhead1("%srepositive2:", label);
        outline0("LD A, B");
        outline0("XOR C");
        outline0("AND $80");
        outline0("CP $80");
        outline1("JR NZ, %srepositive3", label );
        sm83_complement2_16bit( _environment, _other, NULL );
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
        // outline0("SLL C");
        outline0("SCF");
        outline0("RL C");
        outline0("RLA");
        outline0("CALL ADC_HL_HL");
        outline0("CALL SBC_HL_DE");
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

void sm83_math_div_8bit_to_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

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

void sm83_math_div_8bit_to_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed ) {

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

void sm83_bit_check( Environment * _environment, char *_value, int _position, char * _result, int _bitwidth ) {

    no_inline( cpu_bit_check_extended )

    embedded( cpu_bit_check_extended, src_hw_sm83_cpu_bit_check_extended_asm );

        outline1("LD DE, %s", _value);
        outline1("LD A, $%2.2x", _position );
        outline0("CALL CPUBITCHECKEXTENDED" );

        if ( _result ) {
            outline1("LD (%s), A", _result);
        }

    done( )

}

void sm83_bit_check_extended( Environment * _environment, char *_value, char * _position, char * _result, int _bitwidth ) {

    MAKE_LABEL

    no_inline( cpu_bit_check_extended )

    embedded( cpu_bit_check_extended, src_hw_sm83_cpu_bit_check_extended_asm );

        outline1("LD DE, %s", _value);
        outline1("LD A, (%s)", _position );
        outline0("CALL CPUBITCHECKEXTENDED" );

        if ( _result ) {
            outline1("LD (%s), A", _result);
        }

    done( )
    
}

void sm83_bit_inplace_8bit( Environment * _environment, char * _value, int _position, int * _bit ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    no_inline( cpu_bit_inplace )

    embedded( cpu_bit_inplace, src_hw_sm83_cpu_bit_inplace_asm );

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

void sm83_bit_inplace_8bit_extended_indirect( Environment * _environment, char * _address, char * _position, char * _bit ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    no_inline( cpu_bit_inplace )

    embedded( cpu_bit_inplace, src_hw_sm83_cpu_bit_inplace_asm );

        if ( _bit ) {
            outline1("LD A, (%s)", _bit );
            outline0("CP $0" );
            outline1("JR Z, %s", label );
            outline0("LD A, 1" );;
            outline0("SRL A" );
            outhead1("%s:", label );
        }
        outline1("LD HL, (%s)", _address);
        outline0("LD D, H");
        outline0("LD E, L");
        outline1("LD A, (%s)", _position);
        outline0("CALL CPUBITINPLACE");

    done( )

}

void sm83_number_to_string_vars( Environment * _environment ) {

    variable_import( _environment, "N2DINV", VT_BUFFER, 8 );
    variable_import( _environment, "N2DBUF", VT_BUFFER, 20 );
    variable_import( _environment, "N2DEND", VT_BUFFER, 1 );

}

void sm83_number_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits, int _signed ) {

    MAKE_LABEL
        
    deploy_with_vars( numberToString, src_hw_sm83_number_to_string_asm, sm83_number_to_string_vars );

    switch( _bits ) {
        case 8:
            if ( _signed ) {
                outline1("LD A, (%s)", _number);
                outline0("AND $80");
                outline0("LD (IXHR), A");
                outline0("CP 0");
                outline1("JR Z, %sp81", label);
                outline1("LD A, (%s)", _number);
                outline0("XOR $FF");
                outline0("ADC $1");
                outline1("JP %sp82", label);
                outhead1("%sp81:", label);
                outline1("LD A, (%s)", _number);
                outhead1("%sp82:", label);
            } else {
                outline0("LD A, 0" );
                outline0("LD (IXHR), A");
                outline1("LD A, (%s)", _number);
            }
            outline0("CALL N2D8");
            break;
        case 16:
            outline1("LD HL, (%s)", _number);
            if ( _signed ) {
                outline0("LD A, H");
                outline0("AND $80");
                outline0("LD (IXHR), A");
                outline0("CP 0");
                outline1("JR Z, %sp161", label);
                outline0("LD A, H");
                outline0("XOR $FF");
                outline0("LD H, A");
                outline0("LD A, L");
                outline0("XOR $FF");
                outline0("LD L, A");
                outline0("LD DE, 1" );
                outline0("ADD HL, DE" );
                outline0("LD DE, 0" );
                outline1("JP %sp162", label);
                outhead1("%sp161:", label);
                outline1("LD HL, (%s)", _number);
                outhead1("%sp162:", label);
            } else {
                outline0("LD A, 0" );
                outline0("LD (IXHR), A");
            }
            outline0("LD (IXR), HL");
            outline0("CALL N2D16");
            break;
        case 32:
            outline1("LD HL, (%s)", _number);
            outline0("PUSH HL");
            outline1("LD HL, (%s)", address_displacement(_environment, _number, "2"));
            outline0("LD D, H");
            outline0("LD E, L");
            outline0("POP HL");

            if ( _signed ) {
                outline0("LD A, D");
                outline0("AND $80");
                outline0("LD (IXHR), A");
                outline0("CP 0");
                outline1("JR Z, %sp321", label);
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
                outline0("AND A");
                outline0("INC HL");
                outline0("LD A, L");
                outline0("OR H");
                outline1("JR NZ, %sp322", label);
                outline0("INC DE");
                outline1("JP %sp322", label);
                outhead1("%sp321:", label);
                outline1("LD HL, (%s)", _number);
                outline0("PUSH HL");
                outline1("LD HL, (%s)", address_displacement(_environment, _number, "2"));
                outline0("LD D, H");
                outline0("LD E, L");
                outline0("POP HL");
                outhead1("%sp322:", label);
            } else {
                outline0("LD B, 0" );
                outline0("PUSH BC");
            }
            outline0("CALL N2D32");
            break;
        default:
            CRITICAL_DEBUG_UNSUPPORTED( _number, "unknown");
    }

    outline0("PUSH HL");
    outline1("LD HL, (%s)", _string);
    outline0("LD D, H");
    outline0("LD E, L");
    outline0("POP HL");

    outline0("LD A, (IXHR)");
    outline0("CP 0");
    outline1("JR Z, %spos", label);
    outline0("LD A, '-'");
    outline0("LD (DE), A");
    outline0("INC DE");
    outline0("INC C");
    outhead1("%spos:", label);
    outline0("LD A, C");
    outline1("LD (%s), A", _string_size);
    outline0("CALL REPLACEMENT_LDIR");

}

void sm83_bits_to_string_vars( Environment * _environment ) {

    variable_import( _environment, "BINSTRBUF", VT_BUFFER, 32 );
    
}

void sm83_bits_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits ) {

    deploy_with_vars( bitsToString,src_hw_sm83_bits_to_string_asm, sm83_bits_to_string_vars );

    switch( _bits ) {
        case 32:
            outline0("PUSH HL");
            outline1("LD HL, (%s)", address_displacement(_environment, _number, "2"));
            outline0("LD B, H");
            outline0("LD B, L");
            outline0("POP HL");
            outline0("PUSH HL");
            outline1("LD HL, (%s)", _number);
            outline0("LD D, H");
            outline0("LD E, L");
            outline0("POP HL");
            break;
        case 16:
            outline0("LD BC, 0" );
            outline0("PUSH HL");
            outline1("LD HL, (%s)", _number);
            outline0("LD D, H");
            outline0("LD E, L");
            outline0("POP HL");
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

    outline0("PUSH HL");
    outline1("LD HL, (%s)", _string);
    outline0("LD D, H");
    outline0("LD E, L");
    outline0("POP HL");

    outline1("LD A, $%2.2x", ( (_bits) & 0xff ) );
    outline0("LD C, A");
    outline0("LD B, 0");
    outline0("CALL REPLACEMENT_LDIR");

    outline1("LD A, $%2.2x", ( _bits & 0xff ) );
    outline1("LD HL, %s", _string_size );
    outline0("LD (HL), A" );

}

void sm83_hex_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits ) {

    MAKE_LABEL

    inline( cpu_hex_to_string )

    embedded( cpu_hex_to_string, src_hw_sm83_cpu_hex_to_string_asm );

        outline1("LD A, $%2.2x", _bits);
        outline0("LD (IXLR), A");

        switch( _bits ) {
            case 8:
                outline1("LD A, (%s)", _number );
                outline0("LD L, A" );
                outline0("LD H, 0" );
                outline0("PUSH HL");
                outline1("LD HL, (%s)", _string );
                outline0("LD D, H" );
                outline0("LD E, L" );
                outline0("POP HL");

                outline0("CALL H2STRING" );
                break;
            case 16:

                outline1("LD HL, (%s)", _number );
                outline0("PUSH HL");
                outline1("LD HL, (%s)", _string );
                outline0("LD D, H" );
                outline0("LD E, L" );
                outline0("POP HL");

                outline0("CALL H2STRING" );
                break;

            case 32:

                outline1("LD HL, (%s)", address_displacement(_environment, _number, "2") );
                outline0("PUSH HL");
                outline1("LD HL, (%s)", _string );
                outline0("LD D, H" );
                outline0("LD E, L" );
                outline0("POP HL");

                outline0("CALL H2STRING" );

                outline1("LD HL, (%s)", _number );
                outline0("PUSH HL");
                outline1("LD HL, (%s)", _string );
                outline0("LD D, H" );
                outline0("LD E, L" );
                outline0("POP HL");
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

void sm83_dsdefine( Environment * _environment, char * _string, char * _index ) {

    deploy( dstring,src_hw_sm83_dstring_asm );

    outline1( "LD HL, %s", _string );
    outline0( "CALL DSDEFINE" );
    outline0( "LD A, B" );
    outline1( "LD (%s), A", _index );
    
}

void sm83_dsalloc( Environment * _environment, char * _size, char * _index ) {

    deploy( dstring,src_hw_sm83_dstring_asm );

    outline1( "LD A, (%s)", _size );
    outline0( "LD C, A" );
    outline0( "CALL DSALLOC" );
    outline0( "LD A, B" );
    outline1( "LD (%s), A", _index );

}

void sm83_dsalloc_size( Environment * _environment, int _size, char * _index ) {

    deploy( dstring,src_hw_sm83_dstring_asm );

    outline1( "LD A, $%2.2x", ( _size & 0xff ) );
    outline0( "LD C, A" );
    outline0( "CALL DSALLOC" );
    outline0( "LD A, B" );
    outline1( "LD (%s), A", _index );

}

void sm83_dsfree( Environment * _environment, char * _index ) {

    deploy( dstring,src_hw_sm83_dstring_asm );

    outline1( "LD A, (%s)", _index );
    outline0( "LD B, A" );
    outline0( "CALL DSFREE" );

}

void sm83_dswrite( Environment * _environment, char * _index ) {

    deploy( dstring,src_hw_sm83_dstring_asm );

    outline1( "LD A, (%s)", _index );
    outline0( "LD B, A" );
    outline0( "CALL DSWRITE" );

}

void sm83_dsresize( Environment * _environment, char * _index, char * _resize ) {

    deploy( dstring,src_hw_sm83_dstring_asm );

    outline1( "LD A, (%s)", _index );
    outline0( "LD B, A" );
    outline1( "LD A, (%s)", _resize );
    outline0( "LD C, A" );
    outline0( "CALL DSRESIZE" );

}

void sm83_dsresize_size( Environment * _environment, char * _index, int _resize ) {

    deploy( dstring,src_hw_sm83_dstring_asm );

    outline1( "LD A, (%s)", _index );
    outline0( "LD B, A" );
    outline1( "LD A, $%2.2x", ( _resize & 0xff ) );
    outline0( "LD C, A" );
    outline0( "CALL DSRESIZE" );

}

void sm83_dsgc( Environment * _environment ) {

    deploy( dstring,src_hw_sm83_dstring_asm );

    outline0( "CALL DSGC" );

}

void sm83_dsinit( Environment * _environment ) {

    deploy( dstring,src_hw_sm83_dstring_asm );

    outline0( "CALL DSINIT" );

}

void sm83_dsdescriptor( Environment * _environment, char * _index, char * _address, char * _size ) {

    deploy( dstring,src_hw_sm83_dstring_asm );

    if ( _address || _size ) {
        outline1( "LD A, (%s)", _index );
        outline0( "LD B, A" );
        outline0( "CALL DSDESCRIPTOR" );
        outline0( "LD HL, (IXR)" );
        if ( _size ) {
            outline0( "LD A, (HL)" );
            outline1( "LD (%s), A", _size );
        }
        if ( _address ) {
            outline0( "INC HL" );
            outline0( "LD A, (HL)" );
            outline1( "LD (%s), A", _address );
            outline0( "INC HL" );
            outline0( "LD A, (HL)" );
            outline1( "LD (%s), A", address_displacement(_environment, _address, "1") );
        }
    }

}

void sm83_move_8bit_indirect_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

    outline1("LD HL, (%s)", _value);
    outline1("LD A, (%s)", _offset );
    outline0("LD E, A" );
    outline0("LD A, 0" );
    outline0("LD D, A" );
    outline0("ADD HL, DE" );
    outline1("LD A, (%s)", _source);
    outline0("LD (HL), A");

}

void sm83_complement2_8bit( Environment * _environment, char * _source, char * _destination ) {
    outline1( "LD A, (%s)", _source );
    outline0( "XOR $FF" );
    if ( _destination ) {
        outline1( "LD (%s), A", _destination );        
    } else {
        outline1( "LD (%s), A", _source );        
    }
    if ( _destination ) {
        sm83_inc( _environment, _destination );
    } else {
        sm83_inc( _environment, _source );
    }
}

void sm83_complement2_16bit( Environment * _environment, char * _source, char * _destination ) {
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
        sm83_inc_16bit( _environment, _destination );
    } else {
        sm83_inc_16bit( _environment, _source );
    }
}

void sm83_complement2_32bit( Environment * _environment, char * _source, char * _destination ) {
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
        sm83_inc_32bit( _environment, _destination );
    } else {
        sm83_inc_32bit( _environment, _source );
    }
}

void sm83_sqroot( Environment * _environment, char * _number, char * _result ) {

    deploy( sqr, src_hw_sm83_sqr_asm );

    outline1("LD HL, (%s)", _number );

    outline0("CALL SQROOT" );

    outline1("LD (%s),A", _result );

}

void sm83_dstring_vars( Environment * _environment ) {

    int count = _environment->dstring.count == 0 ? DSTRING_DEFAULT_COUNT : _environment->dstring.count;
    int space = _environment->dstring.space == 0 ? DSTRING_DEFAULT_SPACE : _environment->dstring.space;

#if !defined(__vg5000__) && !defined(__cpc__) && !defined(__c128z__) && !defined(__zx__)
    outhead0("section data" );
#endif
    outhead1("stringscount =                  %d", count );
    outhead1("stringsspace =                  %d", space );
    outhead0("MAXSTRINGS:                   DB stringscount" );
    outhead0("DESCRIPTORS:                  DEFS stringscount*4, $00" );
    outhead0("WORKING:                      DEFS stringsspace, $00" );
    outhead0("TEMPORARY:                    DEFS stringsspace, $00" );
    outhead0("FREE_STRING:                  DW (stringsspace-1)" );
#if !defined(__vg5000__) && !defined(__cpc__) && !defined(__c128z__) && !defined(__zx__)
    outhead0("section code" );
#endif

}

void sm83_protothread_vars( Environment * _environment ) {

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


void sm83_protothread_loop( Environment * _environment ) {

    deploy_with_vars( protothread, src_hw_sm83_protothread_asm, cpu_protothread_vars );

    outline0("CALL PROTOTHREADLOOP" );

}

void sm83_protothread_register_at( Environment * _environment, char * _index, char * _label ) {

    deploy_with_vars( protothread, src_hw_sm83_protothread_asm, cpu_protothread_vars );

    outline1("LD HL, %s", _label );
    outline1("LD A, (%s)", _index );
    outline0("LD B, A");

    outline0("CALL PROTOTHREADREGAT" );

}

void sm83_protothread_register( Environment * _environment, char * _label, char * _index ) {

    deploy_with_vars( protothread, src_hw_sm83_protothread_asm, cpu_protothread_vars );

    outline1("LD HL, %s", _label );

    outline0("CALL PROTOTHREADREG" );

    outline0("LD A, B" );
    outline1("LD (%s), A", _index );

}

void sm83_protothread_unregister( Environment * _environment, char * _index ) {

    deploy_with_vars( protothread, src_hw_sm83_protothread_asm, cpu_protothread_vars );

    outline1("LD A, (%s)", _index );
    outline0("LD B, A" );

    outline0("CALL PROTOTHREADUNREG" );

}

void sm83_protothread_save( Environment * _environment, char * _index, int _step ) {

    deploy_with_vars( protothread, src_hw_sm83_protothread_asm, cpu_protothread_vars );

    outline1("LD A, (%s)", _index );
    outline0("LD B, A" );
    outline1("LD A, $%2.2x", ( _step & 0xff ) );

    outline0("CALL PROTOTHREADSAVE" );

}

void sm83_protothread_restore( Environment * _environment, char * _index, char * _step ) {

    deploy_with_vars( protothread, src_hw_sm83_protothread_asm, cpu_protothread_vars );

    outline1("LD A, (%s)", _index );
    outline0("LD B, A" );

    outline0("CALL PROTOTHREADRESTORE" );

    outline1("LD (%s), A", _step );
    
}

void sm83_protothread_set_state( Environment * _environment, char * _index, int _state ) {

    deploy_with_vars( protothread, src_hw_sm83_protothread_asm, cpu_protothread_vars );

    outline1("LD A, (%s)", _index );
    outline0("LD B, A" );
    outline1("LD A, $%2.2x", ( _state & 0xff ) );

    outline0("CALL PROTOTHREADSETSTATE" );

}

void sm83_protothread_get_state( Environment * _environment, char * _index, char * _state ) {

    deploy_with_vars( protothread, src_hw_sm83_protothread_asm, cpu_protothread_vars );

    outline1("LD A, (%s)", _index );
    outline0("LD B, A" );

    outline0("CALL PROTOTHREADGETSTATE" );

    outline1("LD (%s), A", _state );

}

void sm83_protothread_get_address( Environment * _environment, char * _index, char * _address ) {

    deploy_with_vars( protothread, src_hw_sm83_protothread_asm, cpu_protothread_vars );

    outline1("LD A, (%s)", _index );
    outline0("LD B, A" );

    outline0("CALL PROTOTHREADGETADDRESS" );

    outline1("LD (%s), HL", _address );

}

void sm83_protothread_current( Environment * _environment, char * _current ) {

    deploy_with_vars( protothread, src_hw_sm83_protothread_asm, cpu_protothread_vars );

    outline0("LD A, (PROTOTHREADCT)" );
    outline1("LD (%s), A", _current );

}

void sm83_set_callback( Environment * _environment, char * _callback, char * _label ) {

    outline1("LD DE, %s", _label );
    outline1("LD HL, %s", _callback );
    outline0("INC HL" );
    outline0("LD (HL), E" );
    outline0("INC HL" );
    outline0("LD (HL), D" );

}

void sm83_msc1_uncompress_direct_direct( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_sm83_msc1_asm );

        outline1("LD HL, %s", _input);
        outline1("LD DE, %s", _output);
        outline0("CALL MSC1UNCOMPRESS");

    done()

}

void sm83_msc1_uncompress_direct_indirect( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_sm83_msc1_asm );

        outline1("LD HL, (%s)", _output );
        outline0("LD D, H" );
        outline0("LD E, L" );
        outline1("LD HL, %s", _input);
        outline0("CALL MSC1UNCOMPRESS");

    done()

}

void sm83_msc1_uncompress_indirect_direct( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_sm83_msc1_asm );

        outline1("LD HL, (%s)", _input);
        outline1("LD DE, %s", _output);
        outline0("CALL MSC1UNCOMPRESS");

    done()

}

void sm83_msc1_uncompress_indirect_indirect( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_sm83_msc1_asm );

        outline1("LD HL, (%s)", _output );
        outline0("LD D, H" );
        outline0("LD E, L" );
        outline1("LD HL, (%s)", _input);
        outline0("CALL MSC1UNCOMPRESS");

    done()

}

void sm83_out( Environment * _environment, char * _port, char * _value ) {

    outline1("LD HL, (%s)", _port );
    outline0("LD BC, HL" );
    outline1("LD A, (%s)", _value );
    outline0("OUT (C), A" );

}

void sm83_in( Environment * _environment, char * _port, char * _value ) {

    outline1("LD HL, (%s)", _port );
    outline0("LD BC, HL" );
    outline0("IN A, (C)" );
    outline1("LD (%s), A", _value );
        
}

void sm83_out_direct( Environment * _environment, char * _port, char * _value ) {

    outline1("LD A, (%s)", _value );
    outline1("LD BC, %s", _port );
    outline0("OUT (C), A" );

}

void sm83_in_direct( Environment * _environment, char * _port, char * _value ) {

    outline1("LD BC, %s", _port );
    outline0("IN A, (C)" );
    outline1("LD (%s), A", _value );
        
}

void sm83_string_sub( Environment * _environment, char * _source, char * _source_size, char * _pattern, char * _pattern_size, char * _destination, char * _destination_size ) {
    
    MAKE_LABEL

    inline( cpu_string_sub )

    embedded( cpu_string_sub, src_hw_sm83_cpu_string_sub_asm );

        outline1("LD HL, (%s)", _pattern);
        outline0("LD (IXR), HL");
        
        outline1("LD A, (%s)", _source);
        outline0("LD L, A");
        outline1("LD A, (%s)", address_displacement(_environment, _source, "1"));
        outline0("LD H, A");
        outline1("LD A, (%s)", _source_size);
        outline0("LD (IYLR), A");

        outline1("LD A, (%s)", _pattern_size);
        outline0("LD (IYHR), A");

        outline1("LD A, (%s)", _destination);
        outline0("LD E, A");
        outline1("LD A, (%s)", address_displacement(_environment, _destination, "1"));
        outline0("LD D, A");

        outline0("CALL CPUSTRINGSUB");

        outline0("LD A, (IYLR)");
        outline1("LD (%s), A", _destination_size);

    done()
}

static char SM83_BLIT_REGISTER[][2] = {
    "L",
    "H",
    "E",
    "D"
};

#define SM83_BLII_REGISTER_COUNT ( sizeof( SM83_BLIT_REGISTER ) / 2 )

void sm83_blit_initialize( Environment * _environment ) {

    _environment->blit.freeRegisters = 0;
    _environment->blit.usedMemory = 0;

    // outline0("; sm83_blit_initialize");

    outline0("PUSH HL");
    outline0("PUSH DE");

}

void sm83_blit_finalize( Environment * _environment ) {

    // outline0("; sm83_blit_finalize");

    _environment->blit.freeRegisters = 0;
    _environment->blit.usedMemory = 0;

    outline0("POP DE");
    outline0("POP HL");
    
}

char * sm83_blit_register_name(  Environment * _environment, int _register ) {
    
    if ( _register < SM83_BLII_REGISTER_COUNT ) {
        return &SM83_BLIT_REGISTER[_register][0];
    } else {
        return &SM83_BLIT_REGISTER[ (_register & 0xff00) >> 8][0];
    }
}

int sm83_blit_alloc_register(  Environment * _environment ) {

    int reg = 0;

    for( reg = 0; reg < SM83_BLII_REGISTER_COUNT; ++reg ) {
        int registerMask = ( 0x01 << reg );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( ! isRegisterUsed ) {
            _environment->blit.freeRegisters |= registerMask;
            // printf( "sm83_blit_alloc_register() %4.4x -> $%4.4x\n", _environment->blit.freeRegisters, reg );
            // outline1("; sm83_blit_alloc_register = %d", reg );
            return reg;
        }
    }

    int location = _environment->blit.usedMemory++;

    if ( location > 0xff ) {
        CRITICAL_BLIT_ALLOC_MEMORY_EXHAUSTED( );
    }

    for( reg = 0; reg < SM83_BLII_REGISTER_COUNT; ++reg ) {
        int registerMask = ( 0x10 << reg );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( ! isRegisterUsed ) {
            outline1( "LD A, %s", &SM83_BLIT_REGISTER[reg][0] );
            outline2( "LD (%sbs+$%2.2x), A",  _environment->blit.realName, location );
            _environment->blit.freeRegisters |= registerMask;
            // printf( "sm83_blit_alloc_register() -> %4.4x $%4.4x\n", _environment->blit.freeRegisters, ( ( reg << 8 ) | location ) );
            // outline1("; sm83_blit_alloc_register = %d", ( ( (reg+1) << 8 ) | location ) );
            return ( ( (reg+1) << 8 ) | location );
        }
    }

    CRITICAL_BLIT_ALLOC_REGISTER_EXHAUSTED( );

}

void sm83_blit_free_register(  Environment * _environment, int _register ) {

    // outline1("; sm83_blit_free_register = %d", _register );

    // printf( "sm83_blit_free_register($%4.4x)\n", _register );

    int location = _register & 0xff;
    int reg;

    if ( _register < SM83_BLII_REGISTER_COUNT ) {
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
            outline1( "LD %s, A", &SM83_BLIT_REGISTER[reg][0] );
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
void sm83_store_nbit( Environment * _environment, char *_destination, int _n, int _value[] ) {

    int i = 0;
    while( _n ) {
        char destinationAddress[MAX_TEMPORARY_STORAGE]; sprintf( destinationAddress, "%s+%d", _destination, i*4 );
        if ( _n <= 32 ) {
            switch( _n ) {
                case 1: case 2: case 3: case 4:
                case 5: case 6: case 7: case 8:
                    sm83_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff>>(8-_n)) ) );
                    break;
                case 9: case 10: case 11: case 12:
                case 13: case 14: case 15: case 16:
                    sm83_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sm83_store_8bit( _environment, destinationAddress, ( _value[i+1] & (0xff>>(16-_n)) ) );
                    break;
                case 17: case 18: case 19: case 20:
                case 21: case 22: case 23: case 24:
                    sm83_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sm83_store_8bit( _environment, destinationAddress, ( _value[i+1] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    sm83_store_8bit( _environment, destinationAddress, ( _value[i+2] & (0xff>>(24-_n)) ) );
                    break;
                case 25: case 26: case 27: case 28:
                case 29: case 30: case 31: case 32:
                default:
                    sm83_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sm83_store_8bit( _environment, destinationAddress, ( _value[i+1] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    sm83_store_8bit( _environment, destinationAddress, ( _value[i+2] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
                    sm83_store_8bit( _environment, destinationAddress, ( _value[i+3] & (0xff>>(32-_n)) ) );
                    break;
            }
            _n = 0;
        } else {
            sm83_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
            sm83_store_8bit( _environment, destinationAddress, ( _value[i+1] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
            sm83_store_8bit( _environment, destinationAddress, ( _value[i+2] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
            sm83_store_8bit( _environment, destinationAddress, ( _value[i+3] & (0xff>>(32-_n)) ) );
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
void sm83_move_nbit( Environment * _environment, int _n, char * _source, char *_destination ) {

    int i = 0;
    while( _n ) {
        char sourceAddress[MAX_TEMPORARY_STORAGE]; sprintf( sourceAddress, "%s+%d", _source, i*4 );
        char destinationAddress[MAX_TEMPORARY_STORAGE]; sprintf( destinationAddress, "%s+%d", _destination, i*4 );
        if ( _n <= 32 ) {
            switch( _n ) {
                case 1: case 2: case 3: case 4:
                case 5: case 6: case 7: case 8:
                    sm83_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
                case 9: case 10: case 11: case 12:
                case 13: case 14: case 15: case 16:
                    sm83_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sm83_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
                case 17: case 18: case 19: case 20:
                case 21: case 22: case 23: case 24:
                    sm83_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sm83_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    sm83_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
                case 25: case 26: case 27: case 28:
                case 29: case 30: case 31: case 32:
                default:
                    sm83_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sm83_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    sm83_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+3 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
                    sm83_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
            }
            _n = 0;
        } else {
            sm83_move_8bit( _environment, sourceAddress, destinationAddress );
            sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
            sm83_move_8bit( _environment, sourceAddress, destinationAddress );
            sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
            sm83_move_8bit( _environment, sourceAddress, destinationAddress );
            sprintf( sourceAddress, "%s+%d", _source, i*4+3 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
            sm83_move_8bit( _environment, sourceAddress, destinationAddress );
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
void sm83_compare_nbit( Environment * _environment, int _n, char *_source, char *_destination,  char *_name, int _positive ) {

    MAKE_LABEL

    char differentLabel[MAX_TEMPORARY_STORAGE];
    sprintf( differentLabel, "%sdifferent:", label );

    int i = 0;
    while( _n ) {
        char sourceAddress[MAX_TEMPORARY_STORAGE]; sprintf( sourceAddress, "%s+%d", _source, i*4 );
        char destinationAddress[MAX_TEMPORARY_STORAGE]; sprintf( destinationAddress, "%s+%d", _destination, i*4 );
        if ( _n <= 32 ) {
            switch( _n ) {
                case 1: case 2: case 3: case 4:
                case 5: case 6: case 7: case 8:
                    sm83_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sm83_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    break;
                case 9: case 10: case 11: case 12:
                case 13: case 14: case 15: case 16:
                    sm83_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sm83_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sm83_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sm83_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    break;
                case 17: case 18: case 19: case 20:
                case 21: case 22: case 23: case 24:
                    sm83_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sm83_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sm83_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sm83_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    sm83_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sm83_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    break;
                case 25: case 26: case 27: case 28:
                case 29: case 30: case 31: case 32:
                default:
                    sm83_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sm83_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    sm83_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sm83_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    sm83_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sm83_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+3 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
                    sm83_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
                    sm83_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
                    break;
            }
            _n = 0;
        } else {
            sm83_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
            sm83_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
            sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
            sm83_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
            sm83_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
            sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
            sm83_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
            sm83_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
            sprintf( sourceAddress, "%s+%d", _source, i*4+3 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
            sm83_compare_8bit( _environment, sourceAddress, destinationAddress, _name, _positive );
            sm83_compare_and_branch_8bit_const( _environment, _name, 0, differentLabel, _positive );
            _n -= 32;
        }
        ++i;
    }

    outline1("LD A, $%2.2x", _positive * 0xff );
    outline1("LD (%s), A", _name );
    outline1("JP %sdone", label );

    outhead0(differentLabel);
    outline1("LD A, $%2.2x", (1-_positive) * 0xff );
    outline1("LD (%s), A", _name );

    outhead1("%sdone:", label );
    
}

//                  [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]      [8]      [9]
// FAST	    (24)	seeeeeee mmmmmmmm mmmmmmmm

void sm83_float_fast_from_double_to_int_array( Environment * _environment, double _value, int _result[] ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_fast_from_double_to_int_array" );

}

//
//                  [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]      [8]      [9]
// SINGLE	(32)  	seeeeeee emmmmmmm mmmmmmmm mmmmmmmm
//

void sm83_float_single_from_double_to_int_array( Environment * _environment, double _value, int _result[] ) {
    
    CRITICAL_UNIMPLEMENTED( "sm83_float_single_from_double_to_int_array" );

}

//
//                  [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]      [8]      [9]
// EXTENDED (80)	seeeeeee eeeeeeee mmmmmmmm mmmmmmmm mmmmmmmm mmmmmmmm mmmmmmmm mmmmmmmm mmmmmmmm mmmmmmmm
//

void sm83_float_double_from_double_to_int_array( Environment * _environment, double _value, int _result[] ) {
    
    CRITICAL_UNIMPLEMENTED( "sm83_float_double_from_double_to_int_array" );

}

void sm83_float_fast_to_string( Environment * _environment, char * _x, char * _string, char * _string_size ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_fast_to_string" );

}

void sm83_float_single_to_string( Environment * _environment, char * _x, char * _string, char * _string_size ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_single_to_string" );

}

void sm83_float_double_to_string( Environment * _environment, char * _x, char * _string, char * _string_size ) {
    
    CRITICAL_UNIMPLEMENTED( "sm83_float_double_to_string" );

}

void sm83_float_fast_from_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    CRITICAL_UNIMPLEMENTED( "sm83_float_fast_from_16" );

}

void sm83_float_fast_from_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    CRITICAL_UNIMPLEMENTED( "sm83_float_fast_from_8" );

}

void sm83_float_fast_to_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    CRITICAL_UNIMPLEMENTED( "sm83_float_fast_to_16" );

}

void sm83_float_fast_to_8( Environment * _environment, char * _value, char * _result, int _signed ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_fast_to_8" );
    
}

void sm83_float_fast_add( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_fast_add" );

}

void sm83_float_fast_sub( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_fast_sub" );

}

void sm83_float_fast_mul( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_fast_mul" );

}

void sm83_float_fast_div( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_fast_div" );

}

void sm83_float_fast_cmp( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_fast_cmp" );

}

void sm83_float_fast_sin( Environment * _environment, char * _angle, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_fast_sin" );

}

void sm83_float_fast_cos( Environment * _environment, char * _angle, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_fast_cos" );

}

void sm83_float_fast_tan( Environment * _environment, char * _angle, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_fast_tan" );

}

void sm83_float_fast_sqr( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_fast_sqr" );

}

void sm83_float_fast_mod1( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_fast_mod1" );

}

void sm83_float_fast_neg( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_fast_neg" );

}

void sm83_float_single_from_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    CRITICAL_UNIMPLEMENTED( "sm83_float_single_from_16" );

}

void sm83_float_single_from_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    CRITICAL_UNIMPLEMENTED( "sm83_float_single_from_8" );

}


void sm83_float_single_to_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    CRITICAL_UNIMPLEMENTED( "sm83_float_single_to_16" );

}

void sm83_float_single_to_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    CRITICAL_UNIMPLEMENTED( "sm83_float_single_to_8" );

}

void sm83_float_single_add( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_single_add" );

}

void sm83_float_single_sub( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_single_sub" );

}

void sm83_float_single_mul( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_single_mul" );

}

void sm83_float_single_div( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_single_div" );

}

void sm83_float_single_cmp( Environment * _environment, char * _x, char * _y, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_single_cmp" );

}

void sm83_float_single_neg( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_single_neg" );

}

void sm83_float_single_sin( Environment * _environment, char * _angle, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_single_sin" );

}

void sm83_float_single_cos( Environment * _environment, char * _angle, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_single_cos" );

}

void sm83_float_single_tan( Environment * _environment, char * _angle, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_single_tan" );

}

void sm83_float_single_sqr( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_single_sqr" );

}

void sm83_float_single_mod1( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED( "sm83_float_single_mod1" );

}

void sm83_address_table_build( Environment * _environment, char * _table, int * _values, char *_address[], int _count ) {

    outhead1("%s:", _table );
    for( int i=0; i<_count; ++i ) {
        outline2("DEFW $%4.4x, %s", _values[i], _address[i] );
    }

}

void sm83_address_table_lookup( Environment * _environment, char * _table, int _count ) {

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

void sm83_address_table_call( Environment * _environment, char * _table, char * _value, char * _address ) {

    outline0("PUSH HL");
    outline1("LD HL, (%s)", _value );
    outline0("LD D, H" );
    outline0("LD E, L" );
    outline0("POP HL");
    outline1("CALL LOOKFOR%s", _table );
    outline0("PUSH HL");
    outline0("LD H, D" );
    outline0("LD L, E" );
    outline1("LD (%s), HL", _address );
    outline0("POP HL");

}

void sm83_move_8bit_signed_16bit_signed( Environment * _environment, char *_source, char *_destination ) {

    outline1("LD HL, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("ADD A, A" );
    outline0("SBC A" );
    outline0("LD (HL), A" );

}

void sm83_move_8bit_signed_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("ADD A, A" );
    outline0("SBC A" );
    outline0("LD (HL), A" );

}

void sm83_move_8bit_unsigned_16bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD A, 0" );
    outline0("LD (HL), A" );

}

void sm83_move_8bit_unsigned_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD A, 0" );
    outline0("LD (HL), A" );

}

void sm83_move_8bit_signed_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("ADD A, A" );
    outline0("SBC A" );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD (HL), A" );

}

void sm83_move_8bit_signed_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("ADD A, A" );
    outline0("SBC A" );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD (HL), A" );

}

void sm83_move_8bit_unsigned_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD A, 0" );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD A, 0" );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD A, 0" );
    outline0("LD (HL), A" );

}
void sm83_move_8bit_unsigned_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){
    
    outline1("LD HL, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD A, 0" );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD A, 0" );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD A, 0" );
    outline0("LD (HL), A" );

}

void sm83_move_16bit_signed_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, (%s)", _source );
    outline0("LD A, L" );
    outline1("LD (%s), A", _destination );

}
void sm83_move_16bit_signed_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, (%s)", _source );
    outline0("LD A, L" );
    outline1("LD (%s), A", _destination );

}
void sm83_move_16bit_unsigned_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, (%s)", _source );
    outline0("LD A, L" );
    outline1("LD (%s), A", _destination );

}
void sm83_move_16bit_unsigned_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, (%s)", _source );
    outline0("LD A, L" );
    outline1("LD (%s), A", _destination );

}

void sm83_move_16bit_signed_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline1("LD A, (%s)", address_displacement( _environment, _source, "1" ) );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("ADD A, A" );
    outline0("SBC A" );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD (HL), A" );

}

void sm83_move_16bit_signed_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline1("LD A, (%s)", address_displacement( _environment, _source, "1" ) );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("ADD A, A" );
    outline0("SBC A" );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD (HL), A" );

}

void sm83_move_16bit_unsigned_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline1("LD A, (%s)", address_displacement( _environment, _source, "1" ) );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD A, 0" );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD (HL), A" );

}
void sm83_move_16bit_unsigned_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, %s", _destination );
    outline1("LD A, (%s)", _source );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline1("LD A, (%s)", address_displacement( _environment, _source, "1" ) );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD A, 0" );
    outline0("LD (HL), A" );
    outline0("INC HL" );
    outline0("LD (HL), A" );

}

void sm83_move_32bit_signed_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD A, (%s)", _source );
    outline1("LD (%s), A", _destination );

}
void sm83_move_32bit_signed_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD A, (%s)", _source );
    outline1("LD (%s), A", _destination );

}
void sm83_move_32bit_unsigned_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD A, (%s)", _source );
    outline1("LD (%s), A", _destination );

}
void sm83_move_32bit_unsigned_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD A, (%s)", _source );
    outline1("LD (%s), A", _destination );

}

void sm83_move_32bit_signed_16bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, (%s)", _source );
    outline1("LD (%s), HL", _destination );

}

void sm83_move_32bit_signed_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, (%s)", _source );
    outline1("LD (%s), HL", _destination );

}

void sm83_move_32bit_unsigned_16bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LD HL, (%s)", _source );
    outline1("LD (%s), HL", _destination );

}

void sm83_move_32bit_unsigned_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){
    
    outline1("LD HL, (%s)", _source );
    outline1("LD (%s), HL", _destination );

}

void sm83_float_fast_log( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED("LOG");

}

void sm83_float_single_log( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED("LOG");

}

void sm83_float_fast_exp( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED("EXP");

}

void sm83_float_single_exp( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED("EXP");

}


#endif