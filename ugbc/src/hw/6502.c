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

#include "../ugbc.h"

#include <math.h>
#include <stddef.h>
#include <ctype.h>

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#if defined(__c64__) || defined(__plus4__) || defined(__atari__) || defined(__atarixl__) || defined(__vic20__) || defined(__c128__) || defined(__c64reu__)

void cpu6502_init( Environment * _environment ) {

}

void cpu6502_nop( Environment * _environment ) {
    
    outline0("NOP");

}
void cpu_ztoa( Environment * _environment ) {
    
    MAKE_LABEL

    inline( cpu_ztoa )

        outline1("BEQ %syes", label );
        outline0("LDA #0");
        outline1("JMP %s", label );
        outhead1("%syes:", label );
        outline0("LDA #$ff");
        outhead1("%s:", label );

    no_embedded( cpu_ztoa );

}

void cpu_ctoa( Environment * _environment ) {
    
    MAKE_LABEL

    inline( cpu_ctoa )

        outline1("BCS %syes", label );
        outline0("LDA #0");
        outline1("JMP %s", label );
        outhead1("%syes:", label );
        outline0("LDA #$ff");
        outhead1("%s:", label );

    no_embedded( cpu_ctoa );

}

void cpu6502_beq( Environment * _environment, char * _label ) {

     MAKE_LABEL

    inline( cpu_beq )

        outline1("BNE %s", label);
        outline1("JMP %s", _label);
        outline1("%s:", label);

    no_embedded( cpu_beq );

}

/**
 * @brief <i>CPU 6502</i>: emit code to make long conditional jump
 * 
 * @param _environment Current calling environment
 * @param _label Destination of the conditional jump.
 */
void cpu6502_bneq( Environment * _environment, char * _label ) {
    
    MAKE_LABEL

    inline( cpu_bneq )

        outline1("BEQ %s", label);
        outline1("JMP %s", _label);    
        outline1("%s:", label);

    no_embedded( cpu_bneq );

}

void cpu6502_bveq( Environment * _environment, char * _value, char * _label ) {

    inline( cpu_bveq )

        outline1("LDA %s", _value);
        cpu6502_beq( _environment,  _label );

    no_embedded( cpu_bveq );

}

void cpu6502_bvneq( Environment * _environment, char * _value, char * _label ) {

    inline( cpu_bvneq )

        outline1("LDA %s", _value);
        cpu6502_bneq( _environment,  _label );

    no_embedded( cpu_bvneq );

}

void cpu6502_label( Environment * _environment, char * _label ) {

    inline( cpu_label )

        outhead1("%s:", _label);

    no_embedded( cpu_label );

}

void cpu6502_peek( Environment * _environment, char * _address, char * _target ) {

    inline( cpu_peek )

        outline1("LDA %s", _address);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _address, "1") );
        outline0("STA TMPPTR+1");
        outline0("LDY #0");
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", _target);

    no_embedded( cpu_peek );

}

void cpu6502_poke( Environment * _environment, char * _address, char * _source ) {

    inline( cpu_poke )

        outline1("LDA %s", _address);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _address, "1") );
        outline0("STA TMPPTR+1");
        outline0("LDY #0");
        outline1("LDA %s", _source);
        outline0("STA (TMPPTR),Y");    

    no_embedded( cpu_poke );

}

void cpu6502_poke_const( Environment * _environment, char * _address, int _source ) {

    // inline( cpu_poke )

        outline1("LDA %s", _address);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _address, "1") );
        outline0("STA TMPPTR+1");
        outline0("LDY #0");
        outline1("LDA #$%2.2x", (unsigned char)(_source & 0xff));
        outline0("STA (TMPPTR),Y");    

    // no_embedded( cpu_poke );

}

void cpu6502_peekw( Environment * _environment, char * _address, char * _target ) {

    inline( cpu_peek )

        outline1("LDA %s", _address);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _address, "1") );
        outline0("STA TMPPTR+1");
        outline0("LDY #0");
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", _target);
        outline0("INY");
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", address_displacement( _environment, _target, "1" ) );

    no_embedded( cpu_peek );

}

void cpu6502_pokew( Environment * _environment, char * _address, char * _source ) {

    inline( cpu_poke )

        outline1("LDA %s", _address);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _address, "1") );
        outline0("STA TMPPTR+1");
        outline0("LDY #0");
        outline1("LDA %s", _source);
        outline0("STA (TMPPTR),Y");    
        outline0("LDY #1");
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline0("STA (TMPPTR),Y");    

    no_embedded( cpu_poke );

}

void cpu6502_pokew_const( Environment * _environment, char * _address, int _source ) {

    // inline( cpu_poke )

        outline1("LDA %s", _address);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _address, "1") );
        outline0("STA TMPPTR+1");
        outline0("LDY #0");
        outline1("LDA #$%2.2x", (unsigned char)(_source&0xff));
        outline0("STA (TMPPTR),Y");    
        outline0("LDY #1");
        outline1("LDA #$%2.2x", (unsigned char)((_source>>8)&0xff));
        outline0("STA (TMPPTR),Y");    

    // no_embedded( cpu_poke );

}

void cpu6502_peekd( Environment * _environment, char * _address, char * _target ) {

    inline( cpu_peek )

        outline1("LDA %s", _address);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _address, "1") );
        outline0("STA TMPPTR+1");
        outline0("LDY #0");
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", _target);
        outline0("INY");
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", address_displacement(_environment, _target, "1") );
        outline0("INY");
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", address_displacement(_environment, _target, "2") );
        outline0("INY");
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", address_displacement(_environment, _target, "3") );

    no_embedded( cpu_peek );

}

void cpu6502_poked( Environment * _environment, char * _address, char * _source ) {

    inline( cpu_poke )

        outline1("LDA %s", _address);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _address, "1") );
        outline0("STA TMPPTR+1");
        outline0("LDY #0");
        outline1("LDA %s", _source);
        outline0("STA (TMPPTR),Y");    
        outline0("INY");
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA (TMPPTR),Y");    
        outline0("INY");
        outline1("LDA %s", address_displacement(_environment, _source, "2") );
        outline0("STA (TMPPTR),Y");    
        outline0("INY");
        outline1("LDA %s", address_displacement(_environment, _source, "3") );
        outline0("STA (TMPPTR),Y");    

    no_embedded( cpu_poke );

}

void cpu6502_poked_const( Environment * _environment, char * _address, int _source ) {

    // inline( cpu_poke )

        outline1("LDA %s", _address);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _address, "1") );
        outline0("STA TMPPTR+1");
        outline0("LDY #0");
        outline1("LDA #$%2.2x", (unsigned char)(_source&0xff));
        outline0("STA (TMPPTR),Y");    
        outline0("INY");
        outline1("LDA #$%2.2x", (unsigned char)((_source>>8)&0xff));
        outline0("STA (TMPPTR),Y");    
        outline0("INY");
        outline1("LDA #$%2.2x", (unsigned char)((_source>>16)&0xff));
        outline0("STA (TMPPTR),Y");    
        outline0("INY");
        outline1("LDA #$%2.2x", (unsigned char)((_source>>24)&0xff));
        outline0("STA (TMPPTR),Y");    

    // no_embedded( cpu_poke );

}

/**
 * @brief <i>CPU 6502</i>: emit code to fill up a memory area
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
void cpu6502_fill_blocks( Environment * _environment, char * _address, char * _blocks, char * _pattern ) {

    MAKE_LABEL

    inline( cpu_fill_blocks )

        // Use the current bitmap address as starting address for filling routine.
        outline1("LDA %s", _address);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _address, "1") );
        outline0("STA TMPPTR+1");

        // Fill the bitmap with the given pattern.
        outline1("LDX %s", _blocks );
        outhead1("%sx:", label);
        outline0("LDY #0");
        outline1("LDA %s", _pattern );
        outhead1("%sy:", label);
        outline0("STA (TMPPTR),y");
        outline0("INY");
        outline1("BNE %sy", label);
        outline0("INC TMPPTR+1");
        outline0("DEX");
        outline1("BNE %sx", label);

    embedded( cpu_fill_blocks, src_hw_6502_cpu_fill_blocks_asm );

        outline1("LDA %s", _address);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _address, "1"));
        outline0("STA TMPPTR+1");
        outline1("LDX %s", _blocks );
        outline1("LDA %s", _pattern );

        outline0("JSR CPUFILLBLOCKS");

    done()

}

/**
 * @brief <i>CPU 6502</i>: emit code to fill up a memory area
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
void cpu6502_fill( Environment * _environment, char * _address, char * _bytes, int _bytes_width, char * _pattern ) {

    MAKE_LABEL

    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_6502_cpu_fill_asm );

        outline1("LDA %s", _address);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _address, "1"));
        outline0("STA TMPPTR+1");

        if ( _bytes_width == 8 ) {

            outline1("LDY %s", _bytes);
            outline1("LDA %s", _pattern);
            outline0("JSR CPUFILL8");

        } else {

            outline1("LDA %s", _bytes);
            outline0("STA MATHPTR0");
            outline1("LDA %s", address_displacement(_environment, _bytes, "1"));
            outline0("STA MATHPTR0+1");

            outline1("LDA %s", _pattern);
            outline0("JSR CPUFILL16");

        }

    done()

}

/**
 * @brief <i>CPU 6502</i>: emit code to fill up a memory area
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
void cpu6502_fill_size( Environment * _environment, char * _address, int _bytes, char * _pattern ) {

    MAKE_LABEL

    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_6502_cpu_fill_asm );

        outline1("LDA %s", _address);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _address, "1") );
        outline0("STA TMPPTR+1");
        if ( _bytes < 256 ) {
            outline1("LDX #$%2.2x", (unsigned char)( _bytes & 0xff ) );
            outline1("LDA %s", _pattern);
            outline0("JSR CPUFILL8");
        } else {
            outline1("LDA #$%2.2x", (unsigned char)( _bytes & 0xff ) );
            outline0("STA MATHPTR0");
            outline1("LDA #$%2.2x", ( unsigned char) ( ( _bytes >> 8 ) & 0xff ) );
            outline0("STA MATHPTR0+1");
            outline1("LDA %s", _pattern);
            outline0("JSR CPUFILL16");
        }

    done()

}

/**
 * @brief <i>CPU 6502</i>: emit code to fill up a memory area
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
void cpu6502_fill_size_value( Environment * _environment, char * _address, int _bytes, int _pattern ) {

    MAKE_LABEL

    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_6502_cpu_fill_asm );

        outline1("LDA %s", _address);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _address, "1") );
        outline0("STA TMPPTR+1");

        if ( _bytes < 256 ) {
            outline1("LDX #$%2.2x", (unsigned char)( _bytes & 0xff ) );
            outline1("LDA #$%2.2x", (unsigned char) (_pattern & 0xff ) );
            outline0("JSR CPUFILL8");
        } else {
            outline1("LDA #$%2.2x", (unsigned char)( _bytes & 0xff ) );
            outline0("STA MATHPTR0");
            outline1("LDA #$%2.2x", ( unsigned char) ( ( _bytes >> 8 ) & 0xff ) );
            outline0("STA MATHPTR0+1");
            outline1("LDA #$%2.2x", (unsigned char) (_pattern & 0xff ) );
            outline0("JSR CPUFILL16");
        }

    done()

}

/**
 * @brief <i>CPU 6502</i>: emit code to fill up a memory area
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
void cpu6502_fill_direct( Environment * _environment, char * _address, char * _bytes, char * _pattern ) {

    MAKE_LABEL

    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_6502_cpu_fill_asm );

        outline1("LDA #<%s", _address);
        outline0("STA TMPPTR");
        outline1("LDA #>%s", _address);
        outline0("STA TMPPTR+1");
        outline1("LDA %s", _bytes);
        outline0("STA MATHPTR0");
        outline1("LDA %s", address_displacement(_environment, _bytes, "1"));
        outline0("STA MATHPTR0+1");
        outline1("LDA %s", _pattern);
        outline0("JSR CPUFILL16");

    done()

}

/**
 * @brief <i>CPU 6502</i>: emit code to fill up a memory area
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
void cpu6502_fill_direct_size( Environment * _environment, char * _address, int _bytes, char * _pattern ) {

    MAKE_LABEL

    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_6502_cpu_fill_asm );

        outline1("LDA #<%s", _address);
        outline0("STA TMPPTR");
        outline1("LDA #>%s", _address);
        outline0("STA TMPPTR+1");

        if ( _bytes < 256 ) {
            outline1("LDX #$%2.2x", (unsigned char)( _bytes & 0xff ) );
            outline1("LDA %s", _pattern);
            outline0("JSR CPUFILL8");
        } else {
            outline1("LDA #$%2.2x", (unsigned char)( _bytes & 0xff ) );
            outline0("STA MATHPTR0");
            outline1("LDA #$%2.2x", ( unsigned char) ( ( _bytes >> 8 ) & 0xff ) );
            outline0("STA MATHPTR0+1");
            outline1("LDA %s", _pattern);
            outline0("JSR CPUFILL16");
        }

    done()

}

/**
 * @brief <i>CPU 6502</i>: emit code to fill up a memory area
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
void cpu6502_fill_direct_size_value( Environment * _environment, char * _address, int _bytes, int _pattern ) {

    MAKE_LABEL

    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_6502_cpu_fill_asm );

        outline1("LDA #<%s", _address);
        outline0("STA TMPPTR");
        outline1("LDA #>%s", _address);
        outline0("STA TMPPTR+1");

        if ( _bytes < 256 ) {
            outline1("LDX #$%2.2x", (unsigned char)( _bytes & 0xff ) );
            outline1("LDA #$%2.2x", ( _pattern & 0xff ) );
            outline0("JSR CPUFILL8");
        } else {
            outline1("LDA #$%2.2x", (unsigned char)( _bytes & 0xff ) );
            outline0("STA MATHPTR0");
            outline1("LDA #$%2.2x", ( unsigned char) ( ( _bytes >> 8 ) & 0xff ) );
            outline0("STA MATHPTR0+1");
            outline1("LDA #$%2.2x", (unsigned char) (_pattern & 0xff ) );
            outline1("LDA #$%2.2x", ( _pattern & 0xff ) );
            outline0("JSR CPUFILL16");
        }

    done()

}

/*****************************************************************************
 * 8 BIT MANIPULATION
 ****************************************************************************/

/**
 * @brief <i>CPU 6502</i>: emit code to move 8 bit
 * 
 * @param _environment Current calling environment
 * @param _source Source of movement
 * @param _destination Destination of movement
 */
void cpu6502_move_8bit( Environment * _environment, char *_source, char *_destination ) {

    inline( cpu_move_8bit )

        outline1("LDA %s", _source);
        outline1("STA %s", _destination);

    no_embedded( cpu_move_8bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to store 8 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void cpu6502_store_8bit( Environment * _environment, char *_destination, int _value ) {

    inline( cpu_store_8bit )

        outline1("LDA #$%2.2x", (_value & 0xff));
        outline1("STA %s", _destination);

    no_embedded( cpu_store_8bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to store a char
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void cpu6502_store_char( Environment * _environment, char *_destination, int _value ) {

    inline( cpu_store_char )

        if ( _value >=32 ) {
            outline1("LDA #'%c'", (_value & 0xff));
        } else {
            outline1("LDA #$%2.2x", (_value & 0xff));
        }
        outline1("STA %s", _destination);

    no_embedded( cpu_store_char )

}

/**
 * @brief <i>CPU 6502</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _positive Invert meaning of comparison
 */
void cpu6502_compare_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_8bit )

        outline1("LDA %s", _source);
        outline1("CMP %s", _destination);
        outline1("BNE %s", label);
        outline1("LDA #$%2.2x", 0xff*_positive );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("JMP %s_2", label);
        outhead1("%s:", label);
        outline1("LDA #$%2.2x", 0xff*(1-_positive) );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outhead1("%s_2:", label);

    no_embedded( cpu_compare_8bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _positive Invert meaning of comparison
 */
void cpu6502_compare_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_8bit )

        outline1("LDA %s", _source);
        outline1("CMP #$%2.2x", (unsigned char)( _destination & 0xff ) );
        outline1("BNE %s", label);
        outline1("LDA #$%2.2x", (unsigned char)( (0xff*_positive) & 0xff ) );
        outline1("STA %s", _other);
        outline1("JMP %s_2", label);
        outhead1("%s:", label);
        outline1("LDA #$%2.2x", (unsigned char)( (0xff*(1-_positive)) & 0xff )  );
        outline1("STA %s", _other);
        outhead1("%s_2:", label);

    no_embedded( cpu_compare_8bit )

}

void cpu6502_prepare_for_compare_and_branch_8bit( Environment * _environment, char *_source ) {

    MAKE_LABEL

    inline( cpu_compare_and_branch_8bit )

        outline1("LDA %s", _source);

    no_embedded( cpu_compare_and_branch_8bit )

}

void cpu6502_compare_and_branch_8bit( Environment * _environment, char *_source, char * _destination,  char *_label, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_and_branch_8bit )

        outline1("LDA %s", _source);
        outline1("CMP %s", _destination);
        if ( _positive ) {
            outline1("BNE %s", label);
        } else {
            outline1("BEQ %s", label);
        }
        outline1("JMP %s", _label);
        outhead1("%s:", label);

    no_embedded( cpu_compare_and_branch_8bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to compare two 8 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void cpu6502_compare_and_branch_8bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_and_branch_8bit_const )

        outline1("LDA %s", _source);
        outline1("CMP #$%2.2x", (unsigned char)(_destination&0xff));
        if ( _positive ) {
            outline1("BNE %s", label);
        } else {
            outline1("BEQ %s", label);
        }
        outline1("JMP %s", _label);
        outhead1("%s:", label);

    no_embedded( cpu_compare_and_branch_8bit_const )

}

/**
 * @brief <i>CPU 6502</i>: emit code to compare two 8 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void cpu6502_execute_compare_and_branch_8bit_const( Environment * _environment, int _destination,  char *_label, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_and_branch_8bit_const )

        outline1("CMP #$%2.2x", (unsigned char)(_destination & 0xff));
        if ( _positive ) {
            outline1("BNE %s", label);
        } else {
            outline1("BEQ %s", label);
        }
        outline1("JMP %s", _label);
        outhead1("%s:", label);

    no_embedded( cpu_compare_and_branch_8bit_const )

}

/**
 * @brief <i>CPU 6502</i>: emit code to compare two 8 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void cpu6502_compare_and_branch_char_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_and_branch_char_const )

        outline1("LDA %s", _source);
        outline1("CMP #'%c'", (unsigned char)(_destination&0xff));
        if ( _positive ) {
            outline1("BNE %s", label);
        } else {
            outline1("BEQ %s", label);
        }
        outline1("JMP %s", _label);
        outhead1("%s:", label);

    no_embedded( cpu_compare_and_branch_char_const )

}

/**
 * @brief <i>CPU 6502</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void cpu6502_less_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    inline( cpu_less_than_8bit )

        if ( _signed ) {
            outline1("LDA %s", _source);
            outline0("SEC" );
            outline1("SBC %s", _destination);
            outline1("BVC %sv0", label );
            outline0("EOR #$80" );
            outhead1("%sv0:", label );
            outline1("BMI %smi", label );
            if ( _equal ) {
                outline1("BEQ %smi", label );
            }
            outhead1("%spl:", label );
            outline0("LDA #0" );
            if ( _other ) {
                outline1("STA %s", _other);
            } else {
                outline1("STA %s", _destination);
            }
            outline1("JMP %sen", label );
            outhead1("%smi:", label );
            outline0("LDA #$ff" );
            if ( _other ) {
                outline1("STA %s", _other);
            } else {
                outline1("STA %s", _destination);
            }
            outhead1("%sen:", label);
        } else {
            outline1("LDA %s", _source);
            outline1("CMP %s", _destination );
            outline1("BCC %s", label);
            if ( _equal ) {
                outline1("BEQ %s", label);
            }
            outline0("LDA #0" );
            if ( _other ) {
                outline1("STA %s", _other);
            } else {
                outline1("STA %s", _destination);
            }
            outline1("JMP %s_2", label);
            outhead1("%s:", label);
            outline0("LDA #$FF" );
            if ( _other ) {
                outline1("STA %s", _other);
            } else {
                outline1("STA %s", _destination);
            }
            outhead1("%s_2:", label);
        }

    no_embedded( cpu6502_less_than_8bit )

}

void cpu6502_less_than_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    inline( cpu_less_than_8bit_const )

        if ( _signed ) {
            outline1("LDA %s", _source);
            outline0("SEC" );
            outline1("SBC #$%2.2x", ( _destination & 0xff ) );
            outline1("BVC %sv0", label );
            outline0("EOR #$80" );
            outhead1("%sv0:", label );
            outline1("BMI %smi", label );
            if ( _equal ) {
                outline1("BEQ %smi", label );
            }
            outhead1("%spl:", label );
            outline0("LDA #0" );
            outline1("STA %s", _other);
            outline1("JMP %sen", label );
            outhead1("%smi:", label );
            outline0("LDA #$ff" );
            outline1("STA %s", _other);
            outhead1("%sen:", label);
        } else {
            outline1("LDA %s", _source);
            outline1("CMP #$%2.2x", (unsigned char)( _destination & 0xff ) );
            outline1("BCC %s", label);
            if ( _equal ) {
                outline1("BEQ %s", label);
            }
            outline0("LDA #0" );
            outline1("STA %s", _other);
            outline1("JMP %s_2", label);
            outhead1("%s:", label);
            outline0("LDA #$FF" );
            outline1("STA %s", _other);
            outhead1("%s_2:", label);
        }

    no_embedded( cpu6502_less_than_8bit_const )

}

void cpu6502_less_than_and_branch_8bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _equal, int _signed ) {

    MAKE_LABEL

    inline( cpu_less_than_8bit_const )

        if ( _signed ) {
            outline1("LDA %s", _source);
            outline0("SEC" );
            outline1("SBC #$%2.2x", ( _destination & 0xff ) );
            outline1("BVC %sv0", label );
            outline0("EOR #$80" );
            outhead1("%sv0:", label );
            outline1("BMI %smi", label );
            if ( _equal ) {
                outline1("BEQ %smi", label );
            }
            outhead1("%spl:", label );
            outline1("JMP %sen", label );
            outhead1("%smi:", label );
            outline1("JMP %s", _label );
            outhead1("%sen:", label);
        } else {
            outline1("LDA %s", _source);
            outline1("CMP #$%2.2x", (unsigned char)( _destination & 0xff ) );
            outline1("BCC %s", label);
            if ( _equal ) {
                outline1("BEQ %s", label);
            }
            outline1("JMP %s_2", label);
            outhead1("%s:", label);
            outline1("JMP %s", _label);
            outhead1("%s_2:", label);
        }

    no_embedded( cpu6502_less_than_8bit_const )

}

/**
 * @brief <i>CPU 6502</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void cpu6502_greater_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    inline( cpu_greater_than_8bit )

        cpu6502_less_than_8bit( _environment, _source, _destination, _other, !_equal, _signed );
        if ( _other ) {
            cpu6502_not_8bit( _environment, _other, _other );
        } else {
            cpu6502_not_8bit( _environment, _destination, _destination );
        }

    no_embedded( cpu_greater_than_8bit )

}

void cpu6502_greater_than_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    inline( cpu_greater_than_8bit )

        cpu6502_less_than_8bit_const( _environment, _source, _destination, _other, !_equal, _signed );
        cpu6502_not_8bit( _environment, _other, _other );

    no_embedded( cpu_greater_than_8bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to add two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6502_math_add_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_add_8bit )

        outline0("CLC");
        outline1("LDA %s", _source);
        outline1("ADC %s", _destination);
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }

    no_embedded( cpu_math_add_8bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to add two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6502_math_add_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

    inline( cpu_math_add_8bit_const )

        outline0("CLC");
        outline1("LDA %s", _source);
        outline1("ADC #$%2.2x", ( _destination & 0xff ) );
        outline1("STA %s", _other);

    no_embedded( cpu_math_add_8bit_const )

}

/**
 * @brief <i>CPU 6502</i>: emit code to subtract two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to subtract
 * @param _destination Second value to subtract and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6502_math_sub_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {
 
    inline( cpu_math_add_8bit )

        outline0("SEC");
        outline1("LDA %s", _source);
        outline1("SBC %s", _destination);
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }

    no_embedded( cpu_math_add_8bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to double a 8 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6502_math_double_8bit( Environment * _environment, char *_source, char *_other, int _signed ) {

    inline( cpu_math_double_8bit )

        if ( _signed ) {
            outline1("LDA %s", _source);
            outline0("AND #$80");
            outline0("TAX");
            outline1("LDA %s", _source);
            outline0("ASL A");
            if ( _other ) {
                outline1("STA %s", _other);
                outline0("TXA");
                outline1("ORA %s", _other);
                outline1("STA %s", _other);
            } else {
                outline1("STA %s", _source);
                outline0("TXA");
                outline1("ORA %s", _source);
                outline1("STA %s", _source);
            }
        } else {
            outline1("LDA %s", _source);
            outline0("ASL A");
            if ( _other ) {
                outline1("STA %s", _other);
            } else {
                outline1("STA %s", _source);
            }
        }

    no_embedded( cpu_math_double_8bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to multiply two 8bit values in a 16 bit register
 * 
 * @param _environment Current calling environment
 * @param _source First value to multipy (8 bit)
 * @param _destination Second value to multipy (8 bit)
 * @param _other Destination address for result (16 bit)
 */
void cpu6502_math_mul_8bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _signed ) {

    MAKE_LABEL

    inline( cpu_math_mul_8bit_to_16bit )

        if ( _signed ) {
            outline1("LDA %s", _source );
            outline1("EOR %s", _destination );
            outline0("AND #$80" );
            outline0("PHA");
            outline1("LDA %s", _source );
            outline0("AND #$80" );
            outline1("BEQ %ssecond", label );
            outline0("CLC" );
            outline1("LDA %s", _source );
            outline0("EOR #$ff" );
            outline0("ADC #1" );
            outline0("STA MATHPTR0" );
            outhead1("%ssecond:", label );
            outline1("LDA %s", _destination );
            outline0("AND #$80" );
            outline1("BEQ %sthird", label );
            outline0("CLC" );
            outline1("LDA %s", _destination );
            outline0("EOR #$ff" );
            outline0("ADC #1" );
            outline0("STA MATHPTR1" );
            outhead1("%sthird:", label );

            outline0("LDA #0");
            outline0("LDX #8");
            outhead1("%sd1:", label);
            outline0("LSR MATHPTR1");
            outline1("BCC %s_2", label);
            outline0("CLC");
            outline0("ADC MATHPTR0");
            outline1("%s_2:", label);
            outline0("ROR A");
            outline1("ROR %s", _other);
            outline0("DEX" );
            outline1("BNE %sd1", label);
            outline1("STA %s", address_displacement(_environment, _other, "1") );

            outline0("PLA");
            outline0("AND #$80");
            outline1("BEQ %sdone", label);
            outline1("LDA %s", _other );
            outline0("EOR #$ff" );
            outline1("STA %s", _other );
            outline1("LDA %s", address_displacement(_environment, _other, "1") );
            outline0("EOR #$ff" );
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outline0("CLC" );
            outline1("LDA %s", _other );
            outline0("ADC #1" );
            outline1("STA %s", _other );
            outline1("LDA %s", address_displacement(_environment, _other, "1") );
            outline0("ADC #0" );
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outhead1("%sdone:", label );

        } else {
            outline0("LDA #0");
            outline0("LDX #8");
            outhead1("%sd1:", label);
            outline1("LSR %s", _destination);
            outline1("BCC %s_2", label);
            outline0("CLC");
            outline1("ADC %s", _source);
            outline1("%s_2:", label);
            outline0("ROR A");
            outline1("ROR %s", _other);
            outline0("DEX" );
            outline1("BNE %sd1", label);
            outline1("STA %s", address_displacement(_environment, _other, "1") );
        }

    embedded( cpu_math_mul_8bit_to_16bit, src_hw_6502_cpu_math_mul_8bit_to_16bit_asm )

        if ( _signed ) {
            outline1("LDA %s", _source);
            outline0("STA CPUMATHMUL8BITTO16BIT_SOURCE");
            outline1("LDA %s", _destination);
            outline0("STA CPUMATHMUL8BITTO16BIT_DESTINATION");
            outline0("JSR CPUMATHMUL8BITTO16BIT_SIGNED")
            outline0("LDA CPUMATHMUL8BITTO16BIT_OTHER");
            outline1("STA %s", _other);
            outline0("LDA CPUMATHMUL8BITTO16BIT_OTHER+1");
            outline1("STA %s", address_displacement(_environment, _other, "1"));
        } else {
            outline1("LDA %s", _source);
            outline0("STA CPUMATHMUL8BITTO16BIT_SOURCE");
            outline1("LDA %s", _destination);
            outline0("STA CPUMATHMUL8BITTO16BIT_DESTINATION");
            outline0("JSR CPUMATHMUL8BITTO16BIT")
            outline0("LDA CPUMATHMUL8BITTO16BIT_OTHER");
            outline1("STA %s", _other);
            outline0("LDA CPUMATHMUL8BITTO16BIT_OTHER+1");
            outline1("STA %s", address_displacement(_environment, _other, "1"));
        }

    done()
    
}

void cpu6502_math_div_8bit_to_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    inline( cpu_math_div_8bit_to_8bit )

        if ( _signed ) {
            outline1("LDA %s", _source );
            outline1("EOR %s", _destination );
            outline0("AND #$80" );
            outline0("PHA");
            outline1("LDA %s", _source );
            outline0("AND #$80" );
            outline1("BEQ %ssecond", label );
            outline0("CLC" );
            outline1("LDA %s", _source );
            outline0("EOR #$ff" );
            outline0("ADC #1" );
            outline0("STA MATHPTR0" );
            outhead1("%ssecond:", label );
            outline1("LDA %s", _destination );
            outline0("AND #$80" );
            outline1("BEQ %sthird", label );
            outline0("CLC" );
            outline1("LDA %s", _destination );
            outline0("EOR #$ff" );
            outline0("ADC #1" );
            outline0("STA MATHPTR1" );
            outhead1("%sthird:", label );

            outline0("LDA MATHPTR0" );
            outline1("STA %s", _other );
            outline0("LDA #0" );
            outline1("STA %s", _other_remainder );
            outline0("LDX #8");
            outhead1("%sL1:", label );
            outline1("ASL %s", _other );
            outline1("ROL %s", _other_remainder );
            outline1("LDA %s", _other_remainder );
            outline0("SEC" );
            outline0("SBC MATHPTR1" );
            outline0("TAY" );
            outline1("BCC %sL2", label );
            outline1("STY %s", _other_remainder );
            outline1("INC %s", _other );
            outhead1("%sL2:", label );
            outline0("DEX" );
            outhead1("BNE %sL1", label );

            outline0("PLA");
            outline0("AND #$80");
            outline1("BEQ %sdone", label);
            outline1("LDA %s", _other );
            outline0("EOR #$ff" );
            outline1("STA %s", _other );
            outline0("CLC" );
            outline1("LDA %s", _other );
            outline0("ADC #1" );
            outline1("STA %s", _other );
            outhead1("%sdone:", label );

        } else {
            outline1("LDA %s", _source );
            outline1("STA %s", _other );
            outline0("LDA #0" );
            outline1("STA %s", _other_remainder );
            outline0("LDX #8");
            outhead1("%sL1:", label );
            outline1("ASL %s", _other );
            outline1("ROL %s", _other_remainder );
            outline1("LDA %s", _other_remainder );
            outline0("SEC" );
            outline1("SBC %s", _destination );
            outline0("TAY" );
            outline1("BCC %sL2", label );
            outline1("STY %s", _other_remainder );
            outline1("INC %s", _other );
            outhead1("%sL2:", label );
            outline0("DEX" );
            outhead1("BNE %sL1", label );
        }
    
    embedded( cpu_math_div_8bit_to_8bit, src_hw_6502_cpu_math_div_8bit_to_8bit_asm )

        if ( _signed ) {
            outline1("LDA %s", _source);
            outline0("STA CPUMATHDIV8BITTO8BIT_SOURCE");
            outline1("LDA %s", _destination);
            outline0("STA CPUMATHDIV8BITTO8BIT_DESTINATION");
            outline0("JSR CPUMATHDIV8BITTO8BIT_SIGNED")
            outline0("LDA CPUMATHDIV8BITTO8BIT_OTHER");
            outline1("STA %s", _other);
            outline0("LDA CPUMATHDIV8BITTO8BIT_OTHER_REMAINDER");
            outline1("STA %s", _other_remainder);
        } else {
            outline1("LDA %s", _source);
            outline0("STA CPUMATHDIV8BITTO8BIT_SOURCE");
            outline1("LDA %s", _destination);
            outline0("STA CPUMATHDIV8BITTO8BIT_DESTINATION");
            outline0("JSR CPUMATHDIV8BITTO8BIT")
            outline0("LDA CPUMATHDIV8BITTO8BIT_OTHER");
            outline1("STA %s", _other);
            outline0("LDA CPUMATHDIV8BITTO8BIT_OTHER_REMAINDER");
            outline1("STA %s", _other_remainder);
        }

    done()

}

void cpu6502_math_div_8bit_to_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    inline( cpu_math_div_8bit_to_8bit )

        if ( _signed ) {
            outline1("LDA %s", _source );
            outline1("EOR #$%2.2x", _destination );
            outline0("AND #$80" );
            outline0("PHA");
            outline1("LDA %s", _source );
            outline0("AND #$80" );
            outline1("BEQ %ssecond", label );
            outline0("CLC" );
            outline1("LDA %s", _source );
            outline0("EOR #$ff" );
            outline0("ADC #1" );
            outline0("STA MATHPTR0" );
            outhead1("%ssecond:", label );
            outline1("LDA #$%2.2x", _destination );
            outline0("AND #$80" );
            outline1("BEQ %sthird", label );
            outline0("CLC" );
            outline1("LDA #$%2.2x", _destination );
            outline0("EOR #$ff" );
            outline0("ADC #1" );
            outline0("STA MATHPTR1" );
            outhead1("%sthird:", label );

            outline0("LDA MATHPTR0" );
            outline1("STA %s", _other );
            outline0("LDA #0" );
            outline1("STA %s", _other_remainder );
            outline0("LDX #8");
            outhead1("%sL1:", label );
            outline1("ASL %s", _other );
            outline1("ROL %s", _other_remainder );
            outline1("LDA %s", _other_remainder );
            outline0("SEC" );
            outline0("SBC MATHPTR1" );
            outline0("TAY" );
            outline1("BCC %sL2", label );
            outline1("STY %s", _other_remainder );
            outline1("INC %s", _other );
            outhead1("%sL2:", label );
            outline0("DEX" );
            outhead1("BNE %sL1", label );

            outline0("PLA");
            outline0("AND #$80");
            outline1("BEQ %sdone", label);
            outline1("LDA %s", _other );
            outline0("EOR #$ff" );
            outline1("STA %s", _other );
            outline0("CLC" );
            outline1("LDA %s", _other );
            outline0("ADC #1" );
            outline1("STA %s", _other );
            outhead1("%sdone:", label );

        } else {
            outline1("LDA %s", _source );
            outline1("STA %s", _other );
            outline0("LDA #0" );
            outline1("STA %s", _other_remainder );
            outline0("LDX #8");
            outhead1("%sL1:", label );
            outline1("ASL %s", _other );
            outline1("ROL %s", _other_remainder );
            outline1("LDA %s", _other_remainder );
            outline0("SEC" );
            outline1("SBC #$%2.2x", _destination );
            outline0("TAY" );
            outline1("BCC %sL2", label );
            outline1("STY %s", _other_remainder );
            outline1("INC %s", _other );
            outhead1("%sL2:", label );
            outline0("DEX" );
            outhead1("BNE %sL1", label );
        }
    
    embedded( cpu_math_div_8bit_to_8bit, src_hw_6502_cpu_math_div_8bit_to_8bit_asm )

        if ( _signed ) {
            outline1("LDA %s", _source);
            outline0("STA CPUMATHDIV8BITTO8BIT_SOURCE");
            outline1("LDA #$%2.2x", _destination);
            outline0("STA CPUMATHDIV8BITTO8BIT_DESTINATION");
            outline0("JSR CPUMATHDIV8BITTO8BIT_SIGNED")
            outline0("LDA CPUMATHDIV8BITTO8BIT_OTHER");
            outline1("STA %s", _other);
            outline0("LDA CPUMATHDIV8BITTO8BIT_OTHER_REMAINDER");
            outline1("STA %s", _other_remainder);
        } else {
            outline1("LDA %s", _source);
            outline0("STA CPUMATHDIV8BITTO8BIT_SOURCE");
            outline1("LDA #$%2.2x", _destination);
            outline0("STA CPUMATHDIV8BITTO8BIT_DESTINATION");
            outline0("JSR CPUMATHDIV8BITTO8BIT")
            outline0("LDA CPUMATHDIV8BITTO8BIT_OTHER");
            outline1("STA %s", _other);
            outline0("LDA CPUMATHDIV8BITTO8BIT_OTHER_REMAINDER");
            outline1("STA %s", _other_remainder);
        }

    done()

}

/**
 * @brief <i>CPU 6502</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6502_math_div2_const_8bit( Environment * _environment, char *_source, int _steps, int _signed, char *_remainder ) {

    inline( cpu_math_div2_const_8bit )

        if ( _signed ) {
            if ( _remainder ) {
                outline1("LDA %s", _source);
                outline0("AND #$01" );
                outline1("STA %s", _remainder);
            }
            outline1("LDA %s", _source);
            outline0("AND #$80" );
            outline0("TAX");
            while( _steps ) {
                outline0("CLC");
                outline1("ROR %s", _source);
                --_steps;
            }
            outline0("TXA");
            outline1("ORA %s", _source);
            outline1("STA %s", _source);
        } else {
            if ( _remainder ) {
                outline1("LDA %s", _source);
                outline0("AND #$01" );
                outline1("STA %s", _remainder);
            }
            while( _steps ) {
                outline0("CLC");
                outline1("ROR %s", _source);
                --_steps;
            }
        }

    embedded( cpu_math_div2_const_8bit, src_hw_6502_cpu_math_div2_const_8bit_asm )

        if ( _remainder ) {
            outline1("LDA %s", _source);
            outline0("AND #$01" );
            outline1("STA %s", _remainder);
        }
        if ( _signed ) {
            outline1("LDA %s", _source);
            outline1("LDX #$%2.2x", _steps );
            outline0("JSR CPUMATHDIV2CONST8BIT_SIGNED")
            outline1("STA %s", _source);
        } else {
            outline1("LDA %s", _source);
            outline1("LDX #$%2.2x", _steps );
            outline0("JSR CPUMATHDIV2CONST8BIT")
            outline1("STA %s", _source);
        }

    done()

}

/**
 * @brief <i>CPU 6502</i>: emit code to double for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 */
void cpu6502_math_mul2_const_8bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    inline( cpu_math_mul2_const_8bit )

        if ( _signed ) {
            outline1("LDA %s", _source);
            outline0("AND #$80" );
            outline0("TAX");
            while( _steps ) {
                outline0("CLC");
                outline1("ASL %s", _source);
                --_steps;
            }
            outline0("TXA");
            outline1("ORA %s", _source);
            outline1("STA %s", _source);
        } else {
            while( _steps ) {
                outline0("CLC");
                outline1("ASL %s", _source);
                --_steps;
            }
        }

    embedded( cpu_math_mul2_const_8bit, src_hw_6502_cpu_math_mul2_const_8bit_asm )

        if ( _signed ) {
            outline1("LDA %s", _source);
            outline1("LDX #$%2.2x", _steps );
            outline0("JSR CPUMATHMUL2CONST8BIT_SIGNED")
            outline1("STA %s", _source);
        } else {
            outline1("LDA %s", _source);
            outline1("LDX #$%2.2x", _steps );
            outline0("JSR CPUMATHMUL2CONST8BIT")
            outline1("STA %s", _source);
        }

    done()

}

/**
 * @brief <i>CPU 6502</i>: emit code to calculate an 8 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void cpu6502_math_complement_const_8bit( Environment * _environment, char *_source, int _value ) {

    inline( cpu_math_complement_const_8bit )

        outline0("SEC");
        outline1("LDA #$%2.2x", ( _value & 0xff ) );
        outline1("SBC %s", _source);
        outline1("STA %s", _source );

    no_embedded( cpu_math_complement_const_8bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to mask with "and" a value of 8 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void cpu6502_math_and_const_8bit( Environment * _environment, char *_source, int _mask ) {

    inline( cpu_math_and_const_8bit )

        outline1("LDA %s", _source);
        outline1("AND #$%2.2x", (_mask & 0xff));
        outline1("STA %s", _source);

    no_embedded( cpu_math_and_const_8bit )

}

/*****************************************************************************
 * 16 BIT MANIPULATION
 ****************************************************************************/

/**
 * @brief <i>CPU 6502</i>: emit code to move 16 bit
 * 
 * @param _environment Current calling environment
 * @param _source Source of movement
 * @param _destination Destination of movement
 */
void cpu6502_move_16bit( Environment * _environment, char *_source, char *_destination ) {

    inline( cpu_move_16bit )

        outline1("LDA %s", _source);
        outline1("STA %s", _destination);
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("STA %s", address_displacement(_environment, _destination, "1"));

    no_embedded( cpu_move_16bit )

}

void cpu6502_addressof_16bit( Environment * _environment, char *_source, char *_destination ) {

    inline( cpu_move_16bit )

        outline1("LDA #<%s", _source);
        outline1("STA %s", _destination);
        outline1("LDA #>%s", _source);
        outline1("STA %s", address_displacement(_environment, _destination, "1"));

    no_embedded( cpu_move_16bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to store 16 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void cpu6502_store_16bit( Environment * _environment, char *_destination, int _value ) {

    inline( cpu_store_16bit )

        outline1("LDA #$%2.2x", ( _value & 0xff ) );
        outline1("STA %s", _destination);
        outline1("LDA #$%2.2x", ( ( _value >> 8 ) & 0xff ) );
        outline1("STA %s", address_displacement(_environment, _destination, "1"));

    no_embedded( cpu_store_16bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to compare two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _positive Invert meaning of comparison
 */
void cpu6502_compare_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_16bit )

        outline1("LDA %s", _source);
        outline1("CMP %s", _destination);
        outline1("BNE %s", label);
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("CMP %s", address_displacement(_environment, _destination, "1"));
        outline1("BNE %s", label);
        outline1("LDA #$%2.2x", ( _positive ) ? 0xff : 0x00  );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("JMP %s_2", label);
        outhead1("%s:", label);
        outline1("LDA #$%2.2x", ( _positive ) ? 0x00 : 0xff );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outhead1("%s_2:", label);

    no_embedded( cpu_compare_16bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to compare two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _positive Invert meaning of comparison
 */
void cpu6502_compare_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_16bit )

        outline1("LDA %s", _source);
        outline1("CMP #$%2.2x", (unsigned char)( _destination & 0xff ) );
        outline1("BNE %s", label);
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("CMP #$%2.2x", (unsigned char)( ( _destination >> 8 ) & 0xff ) );
        outline1("BNE %s", label);
        outline1("LDA #$%2.2x", ( _positive ) ? 0xff : 0x00  );
        outline1("STA %s", _other);
        outline1("JMP %s_2", label);
        outhead1("%s:", label);
        outline1("LDA #$%2.2x", ( _positive ) ? 0x00 : 0xff );
        outline1("STA %s", _other);
        outhead1("%s_2:", label);

    no_embedded( cpu_compare_16bit )

}

void cpu6502_compare_and_branch_16bit( Environment * _environment, char *_source, char * _destination,  char *_label, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_and_branch_16bit )

        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("CMP %s", address_displacement(_environment, _destination, "1"));
        outline1("BNE %s", label);
        outline1("LDA %s", _source);
        outline1("CMP %s", _destination);
        outline1("BNE %s", label);
        if ( _positive ) {
            outline1("JMP %s", _label);
            outhead1("%s:", label);
        } else {
            outline1("JMP %snot", label);
            outhead1("%s:", label);
            outline1("JMP %s", _label);
            outhead1("%snot:", label);
        }

    no_embedded( cpu_compare_and_branch_16bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to compare two 16 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void cpu6502_compare_and_branch_16bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_and_branch_16bit_const )

        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("CMP #$%2.2x", (unsigned char)(( _destination >> 8 ) & 0xff ));
        outline1("BNE %s", label);
        outline1("LDA %s", _source);
        outline1("CMP #$%2.2x", (unsigned char)( _destination & 0xff ) );
        outline1("BNE %s", label);
        if ( _positive ) {
            outline1("JMP %s", _label);
            outhead1("%s:", label);
        } else {
            outline1("JMP %snot", label);
            outhead1("%s:", label);
            outline1("JMP %s", _label);
            outhead1("%snot:", label);
        }

    no_embedded( cpu_compare_and_branch_16bit_const )

}

/**
 * @brief <i>CPU 6502</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void cpu6502_less_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    inline( cpu_less_than_16bit )

        if ( _signed ) {

            outline0("SEC");
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline1("SBC %s", address_displacement(_environment, _destination, "1") );
            outline1("BVC %sLABEL1", label);
            outline0("EOR #$80" );
            outhead1("%sLABEL1:", label );
            outline1("BMI %sLABEL4", label );
            outline1("BVC %sLABEL2", label );
            outline0("EOR #$80" );
            outhead1("%sLABEL2:", label );
            outline1("BNE %sLABEL3", label );
            outline1("LDA %s", _source );
            outline1("SBC %s", _destination );
            if ( _equal ) {
                outline1("BEQ %sLABEL4", label );
            }
            outline1("BCC %sLABEL4", label );
            outhead1("%sLABEL3:", label );
            outline0("LDA #0" );
            if ( _other ) {
                outline1("STA %s", _other);
            } else {
                outline1("STA %s", _destination);
            }
            outline1("JMP %sen", label );
            outhead1("%sLABEL4:", label );
            outline0("LDA #$ff" );
            if ( _other ) {
                outline1("STA %s", _other);
            } else {
                outline1("STA %s", _destination);
            }
            outhead1("%sen:", label);
        } else {
            outline1("LDA %s", address_displacement(_environment, _source, "1"));
            outline1("CMP %s", address_displacement(_environment, _destination, "1") );
            outline1("BEQ %s_1", label);
            outline1("BCC %s", label);
            outline1("BCS %s_0", label);
            outhead1("%s_1:", label);
            outline1("LDA %s", _source);
            outline1("CMP %s", _destination );
            if ( _equal ) {
                outline1("BEQ %s", label);
            }
            outline1("BCC %s", label);
            outhead1("%s_0:", label);
            outline0("LDA #0" );
            if ( _other ) {
                outline1("STA %s", _other);
            } else {
                outline1("STA %s", _destination);
            }
            outline1("JMP %s_2", label);
            outhead1("%s:", label);
            outline0("LDA #$FF" );
            if ( _other ) {
                outline1("STA %s", _other);
            } else {
                outline1("STA %s", _destination);
            }
            outhead1("%s_2:", label);
        }

    no_embedded( cpu_less_than_16bit )

}

void cpu6502_less_than_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    inline( cpu_less_than_16bit_const )

        if ( _signed ) {

            outline0("SEC");
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline1("SBC #$%2.2x", ( ( _destination >> 8 ) & 0xff ) );
            outline1("BVC %sLABEL1", label);
            outline0("EOR #$80" );
            outhead1("%sLABEL1:", label );
            outline1("BMI %sLABEL4", label );
            outline1("BVC %sLABEL2", label );
            outline0("EOR #$80" );
            outhead1("%sLABEL2:", label );
            outline1("BNE %sLABEL3", label );
            outline1("LDA %s", _source );
            outline1("SBC #$%2.2x", ( _destination & 0xff ) );
            if ( _equal ) {
                outline1("BEQ %sLABEL4", label );
            }
            outline1("BCC %sLABEL4", label );
            outhead1("%sLABEL3:", label );
            outline0("LDA #0" );
            outline1("STA %s", _other);
            outline1("JMP %sen", label );
            outhead1("%sLABEL4:", label );
            outline0("LDA #$ff" );
            outline1("STA %s", _other);
            outhead1("%sen:", label);
        } else {
            outline1("LDA %s", address_displacement(_environment, _source, "1"));
            outline1("CMP #$%2.2x", (unsigned char)( ( _destination >> 8 ) & 0xff ) );
            outline1("BEQ %s_1", label);
            outline1("BCC %s", label);
            outline1("BCS %s_0", label);
            outhead1("%s_1:", label);
            outline1("LDA %s", _source);
            outline1("CMP #$%2.2x", (unsigned char)( _destination & 0xff ) );
            if ( _equal ) {
                outline1("BEQ %s", label);
            }
            outline1("BCC %s", label);
            outhead1("%s_0:", label);
            outline0("LDA #0" );
            outline1("STA %s", _other);
            outline1("JMP %s_2", label);
            outhead1("%s:", label);
            outline0("LDA #$FF" );
            outline1("STA %s", _other);
            outhead1("%s_2:", label);
        }

    no_embedded( cpu_less_than_16bit_const )

}

/**
 * @brief <i>CPU 6502</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void cpu6502_greater_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    inline( cpu_greater_than_16bit )

        cpu6502_less_than_16bit( _environment, _source, _destination, _other, !_equal, _signed );
        if ( _other ) {
            cpu6502_not_8bit( _environment, _other, _other );
        } else {
            cpu6502_not_8bit( _environment, _destination, _destination );
        }

    no_embedded( cpu_greater_than_16bit )

}

void cpu6502_greater_than_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    inline( cpu_greater_than_16bit )

        cpu6502_less_than_16bit_const( _environment, _source, _destination, _other, !_equal, _signed );
        cpu6502_not_8bit( _environment, _other, _other );

    no_embedded( cpu_greater_than_16bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to add two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6502_math_add_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_add_16bit )

        outline0("CLC");
        outline1("LDA %s", _source);
        outline1("ADC %s", _destination);
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("ADC %s", address_displacement(_environment, _destination, "1"));
        if ( _other ) {
            outline1("STA %s", address_displacement(_environment, _other, "1"));
        } else {
            outline1("STA %s", address_displacement(_environment, _destination, "1"));
        }

    no_embedded( cpu_math_add_16bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to add two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6502_math_add_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

    inline( cpu_math_add_16bit_const )

        outline0("CLC");
        outline1("LDA %s", _source);
        outline1("ADC #$%2.2x", ( _destination & 0xff ) );
        outline1("STA %s", _other);
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("ADC #$%2.2x", ( ( _destination >> 8 ) & 0xff ) );
        outline1("STA %s", address_displacement(_environment, _other, "1"));

    no_embedded( cpu_math_add_16bit_const )

}

/**
 * @brief <i>CPU 6502</i>: emit code to add two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6502_math_add_16bit_with_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_add_16bit_with_16bit )

        outline0("CLC");
        outline1("LDA %s", _source);
        outline1("ADC #<%s", _destination);
        outline1("STA %s", _other);
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("ADC #>%s", _destination);
        outline1("STA %s", address_displacement(_environment, _other, "1"));

    no_embedded( cpu_math_add_16bit_with_16bit )
    
}

void cpu6502_math_add_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_add_16bit_with_8bit )

        outline0("CLC");
        outline1("LDA %s", _source);
        outline1("ADC %s", _destination);
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline0("ADC #$0");
        if ( _other ) {
            outline1("STA %s", address_displacement(_environment, _other, "1"));
        } else {
            outline1("STA %s", address_displacement(_environment, _destination, "1"));
        }

    no_embedded( cpu_math_add_16bit_with_8bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to double a 16 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6502_math_double_16bit( Environment * _environment, char *_source, char *_other, int _signed ) {

    inline( cpu_math_double_16bit )

        outline1("LDA %s", _source);
        outline0("ASL A");
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _source);
        }
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline0("ROL A");
        if ( _other ) {
            outline1("STA %s", address_displacement(_environment, _other, "1"));
        } else {
            outline1("STA %s", address_displacement(_environment, _source, "1"));
        }

    no_embedded( cpu_math_double_16bit )

    
}

/**
 * @brief <i>CPU 6502</i>: emit code to multiply two 16 bit values in a 32 bit register
 * 
 * @param _environment Current calling environment
 * @param _source First value to multipy (16 bit)
 * @param _destination Second value to multipy (16 bit)
 * @param _other Destination address for result (32 bit)
 */
void cpu6502_math_mul_16bit_to_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _signed ) {

    MAKE_LABEL

    inline( cpu_math_mul_16bit_to_32bit )

        if ( _signed ) {

            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline1("EOR %s", address_displacement(_environment, _destination, "1") );
            outline0("AND #$80" );
            outline0("PHA");

            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("AND #$80" );
            outline1("BEQ %ssecond", label );
            outline0("CLC" );
            outline1("LDA %s", _source );
            outline0("EOR #$ff" );
            outline0("STA MATHPTR0" );
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("EOR #$ff" );
            outline0("STA MATHPTR1" );
            outline0("CLC" );
            outline0("LDA MATHPTR0" );
            outline0("ADC #1" );
            outline0("STA MATHPTR0" );
            outline0("LDA MATHPTR1" );
            outline0("ADC #0" );
            outline0("STA MATHPTR1" );        
            outline1("JMP %ssecond2", label );
            outhead1("%ssecond:", label );
            outline1("LDA %s", _source );
            outline0("STA MATHPTR0");
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("STA MATHPTR1");
            outline1("JMP %ssecond2", label );

            outhead1("%ssecond2:", label );
            outline1("LDA %s", address_displacement(_environment, _destination, "1") );
            outline0("AND #$80" );
            outline1("BEQ %sthird", label );
            outline0("CLC" );
            outline1("LDA %s", _destination );
            outline0("EOR #$ff" );
            outline0("STA MATHPTR2" );
            outline1("LDA %s", address_displacement(_environment, _destination, "1") );
            outline0("EOR #$ff" );
            outline0("STA MATHPTR3" );
            outline0("CLC" );
            outline0("LDA MATHPTR2" );
            outline0("ADC #1" );
            outline0("STA MATHPTR2" );
            outline0("LDA MATHPTR3" );
            outline0("ADC #0" );
            outline0("STA MATHPTR3" );        
            outline1("JMP %sthird2", label );
            outhead1("%sthird:", label );
            outline1("LDA %s", _destination );
            outline0("STA MATHPTR2");
            outline1("LDA %s", address_displacement(_environment, _destination, "1") );
            outline0("STA MATHPTR3");
            outline1("JMP %sthird2", label );

            outhead1("%sthird2:", label );
            outline0("LDA #$00");
            outline0("STA MATHPTR4");
            outline0("STA MATHPTR5");
            outline0("STA MATHPTR6");
            outline0("STA MATHPTR7");
            outline0("LDX #$10");

            outhead1("%s:", label);
            outline0("LSR MATHPTR1");
            outline0("ROR MATHPTR0");
            outline1("BCC %s_2", label);
            outline0("LDA MATHPTR6");
            outline0("CLC");
            outline0("ADC MATHPTR2");
            outline0("STA MATHPTR6");
            outline0("LDA MATHPTR7");
            outline0("ADC MATHPTR3");

            outhead1("%s_2:", label);
            outline0("ROR");
            outline0("STA MATHPTR7");
            outline0("ROR MATHPTR6");
            outline0("ROR MATHPTR5");
            outline0("ROR MATHPTR4");
            outline0("DEX");
            outline1("BNE %s", label);

            outline0("LDA MATHPTR4");
            outline1("STA %s", _other );
            outline0("LDA MATHPTR5");
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outline0("LDA MATHPTR6");
            outline1("STA %s", address_displacement(_environment, _other, "2") );
            outline0("LDA MATHPTR7");
            outline1("STA %s", address_displacement(_environment, _other, "3") );

            outline0("PLA");
            outline0("AND #$80");
            outline1("BEQ %sdone", label);
            outline1("LDA %s", _other );
            outline0("EOR #$ff" );
            outline1("STA %s", _other );
            outline1("LDA %s", address_displacement(_environment, _other, "1") );
            outline0("EOR #$ff" );
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outline1("LDA %s", address_displacement(_environment, _other, "2") );
            outline0("EOR #$ff" );
            outline1("STA %s", address_displacement(_environment, _other, "2") );
            outline1("LDA %s", address_displacement(_environment, _other, "3") );
            outline0("EOR #$ff" );
            outline1("STA %s", address_displacement(_environment, _other, "3") );
            outline0("CLC" );
            outline1("LDA %s", _other );
            outline0("ADC #1" );
            outline1("STA %s", _other );
            outline1("LDA %s", address_displacement(_environment, _other, "1") );
            outline0("ADC #0" );
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outline1("LDA %s", address_displacement(_environment, _other, "2") );
            outline0("ADC #0" );
            outline1("STA %s", address_displacement(_environment, _other, "2") );
            outline1("LDA %s", address_displacement(_environment, _other, "3") );
            outline0("ADC #0" );
            outline1("STA %s", address_displacement(_environment, _other, "3") );
            outhead1("%sdone:", label );


        } else {

            outline1("LDA %s", _source );
            outline0("STA MATHPTR0");
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("STA MATHPTR1");
            outline1("LDA %s", _destination );
            outline0("STA MATHPTR2");
            outline1("LDA %s", address_displacement(_environment, _destination, "1") );
            outline0("STA MATHPTR3");

            outline0("LDA #$00");
            outline0("STA MATHPTR4");
            outline0("STA MATHPTR5");
            outline0("STA MATHPTR6");
            outline0("STA MATHPTR7");
            outline0("LDX #$10");

            outhead1("%s:", label);
            outline0("LSR MATHPTR1");
            outline0("ROR MATHPTR0");
            outline1("BCC %s_2", label);
            outline0("LDA MATHPTR6");
            outline0("CLC");
            outline0("ADC MATHPTR2");
            outline0("STA MATHPTR6");
            outline0("LDA MATHPTR7");
            outline0("ADC MATHPTR3");

            outhead1("%s_2:", label);
            outline0("ROR");
            outline0("STA MATHPTR7");
            outline0("ROR MATHPTR6");
            outline0("ROR MATHPTR5");
            outline0("ROR MATHPTR4");
            outline0("DEX");
            outline1("BNE %s", label);

            outline0("LDA MATHPTR4");
            outline1("STA %s", _other );
            outline0("LDA MATHPTR5");
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outline0("LDA MATHPTR6");
            outline1("STA %s", address_displacement(_environment, _other, "2") );
            outline0("LDA MATHPTR7");
            outline1("STA %s", address_displacement(_environment, _other, "3") );

        }

     embedded( cpu_math_mul_16bit_to_32bit, src_hw_6502_cpu_math_mul_16bit_to_32bit_asm )

        if ( _signed ) {
            outline1("LDA %s", _source );
            outline0("STA CPUMATHMUL16BITTO32BIT_SOURCE");
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("STA CPUMATHMUL16BITTO32BIT_SOURCE+1");
            outline1("LDA %s", _destination );
            outline0("STA CPUMATHMUL16BITTO32BIT_DESTINATION");
            outline1("LDA %s", address_displacement(_environment, _destination, "1") );
            outline0("STA CPUMATHMUL16BITTO32BIT_DESTINATION+1");            
            outline0("JSR CPUMATHMUL16BITTO32BIT_SIGNED");
            outline0("LDA CPUMATHMUL16BITTO32BIT_OTHER");
            outline1("STA %s", _other );
            outline0("LDA CPUMATHMUL16BITTO32BIT_OTHER+1");
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outline0("LDA CPUMATHMUL16BITTO32BIT_OTHER+2");
            outline1("STA %s", address_displacement(_environment, _other, "2") );
            outline0("LDA CPUMATHMUL16BITTO32BIT_OTHER+3");
            outline1("STA %s", address_displacement(_environment, _other, "3") );
        } else {
            outline1("LDA %s", _source );
            outline0("STA CPUMATHMUL16BITTO32BIT_SOURCE");
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("STA CPUMATHMUL16BITTO32BIT_SOURCE+1");
            outline1("LDA %s", _destination );
            outline0("STA CPUMATHMUL16BITTO32BIT_DESTINATION");
            outline1("LDA %s", address_displacement(_environment, _destination, "1") );
            outline0("STA CPUMATHMUL16BITTO32BIT_DESTINATION+1");            
            outline0("JSR CPUMATHMUL16BITTO32BIT");
            outline0("LDA CPUMATHMUL16BITTO32BIT_OTHER");
            outline1("STA %s", _other );
            outline0("LDA CPUMATHMUL16BITTO32BIT_OTHER+1");
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outline0("LDA CPUMATHMUL16BITTO32BIT_OTHER+2");
            outline1("STA %s", address_displacement(_environment, _other, "2") );
            outline0("LDA CPUMATHMUL16BITTO32BIT_OTHER+3");
            outline1("STA %s", address_displacement(_environment, _other, "3") );
        }

    done()

}

void cpu6502_math_div_16bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    inline( cpu_math_div_16bit_to_16bit )

        if ( _signed ) {

            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline1("EOR %s", address_displacement(_environment, _destination, "1") );
            outline0("AND #$80" );
            outline0("PHA");

            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("AND #$80" );
            outline1("BEQ %ssecond", label );
            outline0("CLC" );
            outline1("LDA %s", _source );
            outline0("EOR #$ff" );
            outline0("STA MATHPTR0" );
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("EOR #$ff" );
            outline0("STA MATHPTR1" );
            outline0("CLC" );
            outline0("LDA MATHPTR0" );
            outline0("ADC #1" );
            outline0("STA MATHPTR0" );
            outline0("LDA MATHPTR1" );
            outline0("ADC #0" );
            outline0("STA MATHPTR1" );        
            outline1("JMP %ssecond2", label );
            outhead1("%ssecond:", label );
            outline1("LDA %s", _source );
            outline0("STA MATHPTR0");
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("STA MATHPTR1");
            outline1("JMP %ssecond2", label );

            outhead1("%ssecond2:", label );
            outline1("LDA %s", address_displacement(_environment, _destination, "1") );
            outline0("AND #$80" );
            outline1("BEQ %sthird", label );
            outline0("CLC" );
            outline1("LDA %s", _destination );
            outline0("EOR #$ff" );
            outline0("STA MATHPTR2" );
            outline1("LDA %s", address_displacement(_environment, _destination, "1") );
            outline0("EOR #$ff" );
            outline0("STA MATHPTR3" );
            outline0("CLC" );
            outline0("LDA MATHPTR2" );
            outline0("ADC #1" );
            outline0("STA MATHPTR2" );
            outline0("LDA MATHPTR3" );
            outline0("ADC #0" );
            outline0("STA MATHPTR3" );        
            outline1("JMP %sthird2", label );
            outhead1("%sthird:", label );
            outline1("LDA %s", _destination );
            outline0("STA MATHPTR2");
            outline1("LDA %s", address_displacement(_environment, _destination, "1") );
            outline0("STA MATHPTR3");
            outline1("JMP %sthird2", label );

            outhead1("%sthird2:", label );

            outline0("LDA MATHPTR0" );
            outline1("STA %s", _other );
            outline0("LDA MATHPTR1" );
            outline1("STA %s", address_displacement(_environment, _other, "1") );

            outline0("LDA #0" );
            outline1("STA %s", _other_remainder );
            outline1("STA %s", address_displacement(_environment, _other_remainder, "1") );
            outline0("LDX #16" );
            outhead1("%sL1:", label );
            outline1("ASL %s", _other );
            outline1("ROL %s", address_displacement(_environment, _other, "1") );
            outline1("ROL %s", _other_remainder );
            outline1("ROL %s", address_displacement(_environment, _other_remainder, "1") );
            outline1("LDA %s", _other_remainder );
            outline0("SEC" );
            outline0("SBC MATHPTR2" );
            outline0("TAY" );
            outline1("LDA %s", address_displacement(_environment, _other_remainder, "1") );
            outline0("SBC MATHPTR3" );
            outline1("BCC %sL2", label );
            outline1("STA %s", address_displacement(_environment, _other_remainder, "1") );
            outline1("STY %s", _other_remainder );
            outline1("INC %s", _other );
            outhead1("%sL2:", label );
            outline0("DEX" );
            outhead1("BNE %sL1", label );        

            outline0("PLA");
            outline0("AND #$80");
            outline1("BEQ %sdone", label);
            outline1("LDA %s", _other );
            outline0("EOR #$ff" );
            outline1("STA %s", _other );
            outline1("LDA %s", address_displacement(_environment, _other, "1") );
            outline0("EOR #$ff" );
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outline0("CLC" );
            outline1("LDA %s", _other );
            outline0("ADC #1" );
            outline1("STA %s", _other );
            outline1("LDA %s", address_displacement(_environment, _other, "1") );
            outline0("ADC #0" );
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outhead1("%sdone:", label );
                    
        } else {
            outline1("LDA %s", _source );
            outline1("STA %s", _other );
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline1("STA %s", address_displacement(_environment, _other, "1") );

            outline0("LDA #0" );
            outline1("STA %s", _other_remainder );
            outline1("STA %s", address_displacement(_environment, _other_remainder, "1") );
            outline0("LDX #16" );
            outhead1("%sL1:", label );
            outline1("ASL %s", _other );
            outline1("ROL %s", address_displacement(_environment, _other, "1") );
            outline1("ROL %s", _other_remainder );
            outline1("ROL %s", address_displacement(_environment, _other_remainder, "1") );
            outline1("LDA %s", _other_remainder );
            outline0("SEC" );
            outline1("SBC %s", _destination );
            outline0("TAY" );
            outline1("LDA %s", address_displacement(_environment, _other_remainder, "1") );
            outline1("SBC %s", address_displacement(_environment, _destination, "1") );
            outline1("BCC %sL2", label );
            outline1("STA %s", address_displacement(_environment, _other_remainder, "1") );
            outline1("STY %s", _other_remainder );
            outline1("INC %s", _other );
            outhead1("%sL2:", label );
            outline0("DEX" );
            outhead1("BNE %sL1", label );
        }

    embedded( cpu_math_div_16bit_to_16bit, src_hw_6502_cpu_math_div_16bit_to_16bit_asm )

        if ( _signed ) {
            outline1("LDA %s", _source );
            outline0("STA CPUMATHDIV16BITTO16BIT_SOURCE");
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("STA CPUMATHDIV16BITTO16BIT_SOURCE+1");
            outline1("LDA %s", _destination );
            outline0("STA CPUMATHDIV16BITTO16BIT_DESTINATION");
            outline1("LDA %s", address_displacement(_environment, _destination, "1") );
            outline0("STA CPUMATHDIV16BITTO16BIT_DESTINATION+1");            
            outline0("JSR CPUMATHDIV16BITTO16BIT_SIGNED");
            outline0("LDA CPUMATHDIV16BITTO16BIT_OTHER");
            outline1("STA %s", _other );
            outline0("LDA CPUMATHDIV16BITTO16BIT_OTHER+1");
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outline0("LDA CPUMATHDIV16BITTO16BIT_OTHER_REMAINDER");
            outline1("STA %s", _other_remainder );
            outline0("LDA CPUMATHDIV16BITTO16BIT_OTHER_REMAINDER+1");
            outline1("STA %s", address_displacement(_environment, _other_remainder, "1") );
        } else {
            outline1("LDA %s", _source );
            outline0("STA CPUMATHDIV16BITTO16BIT_SOURCE");
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("STA CPUMATHDIV16BITTO16BIT_SOURCE+1");
            outline1("LDA %s", _destination );
            outline0("STA CPUMATHDIV16BITTO16BIT_DESTINATION");
            outline1("LDA %s", address_displacement(_environment, _destination, "1") );
            outline0("STA CPUMATHDIV16BITTO16BIT_DESTINATION+1");            
            outline0("JSR CPUMATHDIV16BITTO16BIT");
            outline0("LDA CPUMATHDIV16BITTO16BIT_OTHER");
            outline1("STA %s", _other );
            outline0("LDA CPUMATHDIV16BITTO16BIT_OTHER+1");
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outline0("LDA CPUMATHDIV16BITTO16BIT_OTHER_REMAINDER");
            outline1("STA %s", _other_remainder );
            outline0("LDA CPUMATHDIV16BITTO16BIT_OTHER_REMAINDER+1");
            outline1("STA %s", address_displacement(_environment, _other_remainder, "1") );
        }

    done()

}

void cpu6502_math_div_16bit_to_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    inline( cpu_math_div_16bit_to_16bit )

        if ( _signed ) {

            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline1("EOR #$%2.2x", (unsigned char)((_destination>>8)&0xff) );
            outline0("AND #$80" );
            outline0("PHA");

            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("AND #$80" );
            outline1("BEQ %ssecond", label );
            outline0("CLC" );
            outline1("LDA %s", _source );
            outline0("EOR #$ff" );
            outline0("STA MATHPTR0" );
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("EOR #$ff" );
            outline0("STA MATHPTR1" );
            outline0("CLC" );
            outline0("LDA MATHPTR0" );
            outline0("ADC #1" );
            outline0("STA MATHPTR0" );
            outline0("LDA MATHPTR1" );
            outline0("ADC #0" );
            outline0("STA MATHPTR1" );        
            outline1("JMP %ssecond2", label );
            outhead1("%ssecond:", label );
            outline1("LDA %s", _source );
            outline0("STA MATHPTR0");
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("STA MATHPTR1");
            outline1("JMP %ssecond2", label );

            outhead1("%ssecond2:", label );
            outline1("LDA #$%2.2x", (unsigned char)((_destination>>8)&0xff) );
            outline0("AND #$80" );
            outline1("BEQ %sthird", label );
            outline0("CLC" );
            outline1("LDA #$%2.2x", (unsigned char)((_destination)&0xff) );
            outline0("EOR #$ff" );
            outline0("STA MATHPTR2" );
            outline1("LDA #$%2.2x", (unsigned char)((_destination>>8)&0xff) );
            outline0("EOR #$ff" );
            outline0("STA MATHPTR3" );
            outline0("CLC" );
            outline0("LDA MATHPTR2" );
            outline0("ADC #1" );
            outline0("STA MATHPTR2" );
            outline0("LDA MATHPTR3" );
            outline0("ADC #0" );
            outline0("STA MATHPTR3" );        
            outline1("JMP %sthird2", label );
            outhead1("%sthird:", label );
            outline1("LDA #$%2.2x", (unsigned char)((_destination)&0xff) );
            outline0("STA MATHPTR2");
            outline1("LDA #$%2.2x", (unsigned char)((_destination>>8)&0xff) );
            outline0("STA MATHPTR3");
            outline1("JMP %sthird2", label );

            outhead1("%sthird2:", label );

            outline0("LDA MATHPTR0" );
            outline1("STA %s", _other );
            outline0("LDA MATHPTR1" );
            outline1("STA %s", address_displacement(_environment, _other, "1") );

            outline0("LDA #0" );
            outline1("STA %s", _other_remainder );
            outline1("STA %s", address_displacement(_environment, _other_remainder, "1") );
            outline0("LDX #16" );
            outhead1("%sL1:", label );
            outline1("ASL %s", _other );
            outline1("ROL %s", address_displacement(_environment, _other, "1") );
            outline1("ROL %s", _other_remainder );
            outline1("ROL %s", address_displacement(_environment, _other_remainder, "1") );
            outline1("LDA %s", _other_remainder );
            outline0("SEC" );
            outline0("SBC MATHPTR2" );
            outline0("TAY" );
            outline1("LDA %s", address_displacement(_environment, _other_remainder, "1") );
            outline0("SBC MATHPTR3" );
            outline1("BCC %sL2", label );
            outline1("STA %s", address_displacement(_environment, _other_remainder, "1") );
            outline1("STY %s", _other_remainder );
            outline1("INC %s", _other );
            outhead1("%sL2:", label );
            outline0("DEX" );
            outhead1("BNE %sL1", label );        

            outline0("PLA");
            outline0("AND #$80");
            outline1("BEQ %sdone", label);
            outline1("LDA %s", _other );
            outline0("EOR #$ff" );
            outline1("STA %s", _other );
            outline1("LDA %s", address_displacement(_environment, _other, "1") );
            outline0("EOR #$ff" );
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outline0("CLC" );
            outline1("LDA %s", _other );
            outline0("ADC #1" );
            outline1("STA %s", _other );
            outline1("LDA %s", address_displacement(_environment, _other, "1") );
            outline0("ADC #0" );
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outhead1("%sdone:", label );
                    
        } else {
            outline1("LDA %s", _source );
            outline1("STA %s", _other );
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline1("STA %s", address_displacement(_environment, _other, "1") );

            outline0("LDA #0" );
            outline1("STA %s", _other_remainder );
            outline1("STA %s", address_displacement(_environment, _other_remainder, "1") );
            outline0("LDX #16" );
            outhead1("%sL1:", label );
            outline1("ASL %s", _other );
            outline1("ROL %s", address_displacement(_environment, _other, "1") );
            outline1("ROL %s", _other_remainder );
            outline1("ROL %s", address_displacement(_environment, _other_remainder, "1") );
            outline1("LDA %s", _other_remainder );
            outline0("SEC" );
            outline1("SBC #$%2.2x", (unsigned char)((_destination)&0xff) );
            outline0("TAY" );
            outline1("LDA %s", address_displacement(_environment, _other_remainder, "1") );
            outline1("SBC #$%2.2x", (unsigned char)((_destination>>8)&0xff) );
            outline1("BCC %sL2", label );
            outline1("STA %s", address_displacement(_environment, _other_remainder, "1") );
            outline1("STY %s", _other_remainder );
            outline1("INC %s", _other );
            outhead1("%sL2:", label );
            outline0("DEX" );
            outhead1("BNE %sL1", label );
        }

    embedded( cpu_math_div_16bit_to_16bit, src_hw_6502_cpu_math_div_16bit_to_16bit_asm )

        if ( _signed ) {
            outline1("LDA %s", _source );
            outline0("STA CPUMATHDIV16BITTO16BIT_SOURCE");
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("STA CPUMATHDIV16BITTO16BIT_SOURCE+1");
            outline1("LDA #$%2.2x", (unsigned char)((_destination)&0xff) );
            outline0("STA CPUMATHDIV16BITTO16BIT_DESTINATION");
            outline1("LDA #$%2.2x", (unsigned char)((_destination>>8)&0xff) );
            outline0("STA CPUMATHDIV16BITTO16BIT_DESTINATION+1");            
            outline0("JSR CPUMATHDIV16BITTO16BIT_SIGNED");
            outline0("LDA CPUMATHDIV16BITTO16BIT_OTHER");
            outline1("STA %s", _other );
            outline0("LDA CPUMATHDIV16BITTO16BIT_OTHER+1");
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outline0("LDA CPUMATHDIV16BITTO16BIT_OTHER_REMAINDER");
            outline1("STA %s", _other_remainder );
            outline0("LDA CPUMATHDIV16BITTO16BIT_OTHER_REMAINDER+1");
            outline1("STA %s", address_displacement(_environment, _other_remainder, "1") );
        } else {
            outline1("LDA %s", _source );
            outline0("STA CPUMATHDIV16BITTO16BIT_SOURCE");
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("STA CPUMATHDIV16BITTO16BIT_SOURCE+1");
            outline1("LDA #$%2.2x", (unsigned char)((_destination)&0xff) );
            outline0("STA CPUMATHDIV16BITTO16BIT_DESTINATION");
            outline1("LDA #$%2.2x", (unsigned char)((_destination>>8)&0xff) );
            outline0("STA CPUMATHDIV16BITTO16BIT_DESTINATION+1");            
            outline0("JSR CPUMATHDIV16BITTO16BIT");
            outline0("LDA CPUMATHDIV16BITTO16BIT_OTHER");
            outline1("STA %s", _other );
            outline0("LDA CPUMATHDIV16BITTO16BIT_OTHER+1");
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outline0("LDA CPUMATHDIV16BITTO16BIT_OTHER_REMAINDER");
            outline1("STA %s", _other_remainder );
            outline0("LDA CPUMATHDIV16BITTO16BIT_OTHER_REMAINDER+1");
            outline1("STA %s", address_displacement(_environment, _other_remainder, "1") );
        }

    done()

}

/**
 * @brief <i>CPU 6502</i>: emit code to subtract two 16 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to subtract
 * @param _destination Second value to subtract and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6502_math_sub_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_sub_16bit )

        outline0("SEC");
        outline1("LDA %s", _source);
        outline1("SBC %s", _destination);
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("SBC %s", address_displacement(_environment, _destination, "1"));
        if ( _other ) {
            outline1("STA %s", address_displacement(_environment, _other, "1"));
        } else {
            outline1("STA %s", address_displacement(_environment, _destination, "1"));
        }

    no_embedded( cpu_math_sub_16bit )

}

void cpu6502_math_sub_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_sub_16bit_with_8bit )

        outline0("SEC");
        outline1("LDA %s", _source);
        outline1("SBC %s", _destination);
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline0("SBC #$0");
        if ( _other ) {
            outline1("STA %s", address_displacement(_environment, _other, "1"));
        } else {
            outline1("STA %s", address_displacement(_environment, _destination, "1"));
        }

    no_embedded( cpu6502_math_sub_16bit_with_8bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to calculate a 16 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void cpu6502_math_complement_const_16bit( Environment * _environment, char *_source, int _value ) {

    inline( cpu_math_complement_const_16bit )

        outline0("SEC");
        outline1("LDA #$%2.2x", ( _value & 0xff ) );
        outline1("SBC %s", _source);
        outline1("STA %s", _source );
        outline1("LDA #$%2.2x", ( ( _value >> 8 ) & 0xff ) );
        outline1("SBC %s", address_displacement(_environment, _source, "1"));
        outline1("STA %s", address_displacement(_environment, _source, "1") );

    no_embedded( cpu_math_complement_const_16bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to halves for several times a 16 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6502_math_div2_const_16bit( Environment * _environment, char *_source, int _steps, int _signed, char * _remainder ) {

    inline( cpu_math_div2_const_16bit )

        if ( _signed ) {
            if ( _remainder ) {
                outline1("LDA %s", _source);
                outline0("AND #$01" );
                outline1("STA %s", _remainder);
            }
            outline1("LDA %s", address_displacement(_environment, _source, "1"));
            outline0("AND #$80" );
            outline0("TAX")
            while( _steps ) {
                outline0("CLC");
                outline1("LSR %s", address_displacement(_environment, _source, "1"));
                outline1("ROR %s", _source);
                --_steps;
            }
            outline0("TXA")
            outline1("ORA %s", address_displacement(_environment, _source, "1"));
            outline1("STA %s", address_displacement(_environment, _source, "1"));
        } else {
            if ( _remainder ) {
                outline1("LDA %s", _source);
                outline0("AND #$01" );
                outline1("STA %s", _remainder);
            }
            while( _steps ) {
                outline0("CLC");
                outline1("LSR %s", address_displacement(_environment, _source, "1"));
                outline1("ROR %s", _source);
                --_steps;
            }
        }

    no_embedded( cpu_math_div2_const_16bit )


}

/**
 * @brief <i>CPU 6502</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6502_math_mul2_const_16bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    inline( cpu_math_mul2_const_16bit )

        if ( _signed ) {
            outline1("LDA %s", address_displacement(_environment, _source, "1"));
            outline0("AND #$80" );
            outline0("TAX")
            while( _steps ) {
                outline0("CLC");
                outline1("ASL %s", _source);
                outline1("ROL %s", address_displacement(_environment, _source, "1"));
                --_steps;
            }
            outline0("TXA")
            outline1("ORA %s", address_displacement(_environment, _source, "1"));
            outline1("STA %s", address_displacement(_environment, _source, "1"));
        } else {
            while( _steps ) {
                outline0("CLC");
                outline1("ASL %s", _source);
                outline1("ROL %s", address_displacement(_environment, _source, "1"));
                --_steps;
            }
        }

    no_embedded( cpu_math_mul2_const_16bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to mask with "and" a value of 16 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void cpu6502_math_and_const_16bit( Environment * _environment, char *_source, int _mask ) {

    inline( cpu_math_and_const_16bit )

        outline1("LDA %s", _source);
        outline1("AND #$%2.2x", (_mask & 0xff ) );
        outline1("STA %s", _source);
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("AND #$%2.2x", ((_mask>>8) & 0xff ));
        outline1("STA %s", address_displacement(_environment, _source, "1"));

    no_embedded( cpu_math_and_const_16bit )

}

/*****************************************************************************
 * 32 BIT MANIPULATION
 ****************************************************************************/

/**
 * @brief <i>CPU 6502</i>: emit code to move 32 bit
 * 
 * @param _environment Current calling environment
 * @param _source Source of movement
 * @param _destination Destination of movement
 */
void cpu6502_move_32bit( Environment * _environment, char *_source, char *_destination ) {

    inline( cpu_move_32bit )

        outline1("LDA %s", _source);
        outline1("STA %s", _destination);
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("STA %s", address_displacement(_environment, _destination, "1"));
        outline1("LDA %s", address_displacement(_environment, _source, "2"));
        outline1("STA %s", address_displacement(_environment, _destination, "2"));
        outline1("LDA %s", address_displacement(_environment, _source, "3"));
        outline1("STA %s", address_displacement(_environment, _destination, "3"));

    no_embedded( cpu_move_32bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to store 32 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void cpu6502_store_32bit( Environment * _environment, char *_destination, int _value ) {

    inline( cpu_store_32bit )

        outline1("LDA #$%2.2x", ( _value & 0xff ) );
        outline1("STA %s", _destination);
        outline1("LDA #$%2.2x", ( ( _value >> 8 ) & 0xff ) );
        outline1("STA %s", address_displacement(_environment, _destination, "1"));
        outline1("LDA #$%2.2x", ( ( _value >> 16 ) & 0xff ) );
        outline1("STA %s", address_displacement(_environment, _destination, "2"));
        outline1("LDA #$%2.2x", ( ( _value >> 24 ) & 0xff ) );
        outline1("STA %s", address_displacement(_environment, _destination, "3"));

    no_embedded( cpu_store_32bit )

}

void cpu6502_math_div_32bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    inline( cpu_math_div_32bit_to_16bit )

        outline1("LDA %s", _source );
        outline0("STA MATHPTR4");
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA MATHPTR5");
        outline1("LDA %s", address_displacement(_environment, _source, "2") );
        outline0("STA MATHPTR2");
        outline1("LDA %s", address_displacement(_environment, _source, "3") );
        outline0("STA MATHPTR3" );

        outline1("LDA %s", _destination );
        outline0("STA MATHPTR0");
        outline1("LDA %s", address_displacement(_environment, _destination, "1") );
        outline0("STA MATHPTR1" );

        outhead1("%sSTART:", label );
        outline0("SEC" );
        outline0("LDA MATHPTR2" );
        outline0("SBC MATHPTR0" );
        outline0("LDA MATHPTR3" );
        outline0("SBC MATHPTR1 " );
        outline1("BCS %soflo", label );
        outline0("LDX #$11" );
        outhead1("%sloop:", label)

        outline0("ROL MATHPTR4");
        outline0("ROL MATHPTR5");
        outline0("DEX" );
        outline1("BEQ %send", label );

        outline0("ROL MATHPTR2" );
        outline0("ROL MATHPTR3" );
        outline0("STA MATHPTR7" );
        outline0("ROL MATHPTR8" ); // <<--- forse MATHPTR7
        outline0("SEC" );
        outline0("LDA MATHPTR2" );
        outline0("SBC MATHPTR0" );
        outline0("STA MATHPTR6" );
        outline0("LDA MATHPTR3" );
        outline0("SBC MATHPTR1" );
        outline0("TAY" );
        outline0("LDA MATHPTR8" ); // <<--- forse MATHPTR8
        outline0("SBC #0" );
        outline1("BCC %sloop", label )
        outline0("LDA MATHPTR6");
        outline0("STA MATHPTR2");
        outline0("STY MATHPTR3" );
        outline1("JMP %sloop", label );

        outhead1("%soflo:", label );
        outline0("LDA #$ff" );
        outline0("STA MATHPTR2" );
        outline0("STA MATHPTR3" );
        outline0("STA MATHPTR4" );
        outline0("STA MATHPTR5" );
        outhead1("%send:", label );

        outline0("LDA MATHPTR4");
        outline1("STA %s", _other );
        outline0("LDA MATHPTR5");
        outline1("STA %s", address_displacement(_environment, _other, "1") );
        outline0("LDA MATHPTR2");
        outline1("STA %s", _other_remainder );
        outline0("LDA MATHPTR3");
        outline1("STA %s", address_displacement(_environment, _other_remainder, "1") );

    embedded( cpu_math_div_32bit_to_16bit, src_hw_6502_cpu_math_div_32bit_to_16bit_asm )

        outline1("LDA %s", _source );
        outline0("STA MATHPTR4");
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA MATHPTR5");
        outline1("LDA %s", address_displacement(_environment, _source, "2") );
        outline0("STA MATHPTR2");
        outline1("LDA %s", address_displacement(_environment, _source, "3") );
        outline0("STA MATHPTR3" );
        outline1("LDA %s", _destination );
        outline0("STA MATHPTR0");
        outline1("LDA %s", address_displacement(_environment, _destination, "1") );
        outline0("STA MATHPTR1" );
        outline0("JSR CPUMATHDIV32BITTO16BIT" );
        outline0("LDA MATHPTR4");
        outline1("STA %s", _other );
        outline0("LDA MATHPTR5");
        outline1("STA %s", address_displacement(_environment, _other, "1") );
        outline0("LDA MATHPTR2");
        outline1("STA %s", _other_remainder );
        outline0("LDA MATHPTR3");
        outline1("STA %s", address_displacement(_environment, _other_remainder, "1") );

    done()

}

void cpu6502_math_div_32bit_to_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    inline( cpu_math_div_32bit_to_16bit )

        outline1("LDA %s", _source );
        outline0("STA MATHPTR4");
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA MATHPTR5");
        outline1("LDA %s", address_displacement(_environment, _source, "2") );
        outline0("STA MATHPTR2");
        outline1("LDA %s", address_displacement(_environment, _source, "3") );
        outline0("STA MATHPTR3" );

        outline1("LDA #$%2.2x", (unsigned char)((_destination)&0xff) );
        outline0("STA MATHPTR0");
        outline1("LDA #$%2.2x", (unsigned char)((_destination>>8)&0xff) );
        outline0("STA MATHPTR1" );

        outhead1("%sSTART:", label );
        outline0("SEC" );
        outline0("LDA MATHPTR2" );
        outline0("SBC MATHPTR0" );
        outline0("LDA MATHPTR3" );
        outline0("SBC MATHPTR1 " );
        outline1("BCS %soflo", label );
        outline0("LDX #$11" );
        outhead1("%sloop:", label)

        outline0("ROL MATHPTR4");
        outline0("ROL MATHPTR5");
        outline0("DEX" );
        outline1("BEQ %send", label );

        outline0("ROL MATHPTR2" );
        outline0("ROL MATHPTR3" );
        outline0("STA MATHPTR7" );
        outline0("ROL MATHPTR8" ); // <<--- forse MATHPTR7
        outline0("SEC" );
        outline0("LDA MATHPTR2" );
        outline0("SBC MATHPTR0" );
        outline0("STA MATHPTR6" );
        outline0("LDA MATHPTR3" );
        outline0("SBC MATHPTR1" );
        outline0("TAY" );
        outline0("LDA MATHPTR8" ); // <<--- forse MATHPTR8
        outline0("SBC #0" );
        outline1("BCC %sloop", label )
        outline0("LDA MATHPTR6");
        outline0("STA MATHPTR2");
        outline0("STY MATHPTR3" );
        outline1("JMP %sloop", label );

        outhead1("%soflo:", label );
        outline0("LDA #$ff" );
        outline0("STA MATHPTR2" );
        outline0("STA MATHPTR3" );
        outline0("STA MATHPTR4" );
        outline0("STA MATHPTR5" );
        outhead1("%send:", label );

        outline0("LDA MATHPTR4");
        outline1("STA %s", _other );
        outline0("LDA MATHPTR5");
        outline1("STA %s", address_displacement(_environment, _other, "1") );
        outline0("LDA MATHPTR2");
        outline1("STA %s", _other_remainder );
        outline0("LDA MATHPTR3");
        outline1("STA %s", address_displacement(_environment, _other_remainder, "1") );

    embedded( cpu_math_div_32bit_to_16bit, src_hw_6502_cpu_math_div_32bit_to_16bit_asm )

        outline1("LDA %s", _source );
        outline0("STA MATHPTR4");
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA MATHPTR5");
        outline1("LDA %s", address_displacement(_environment, _source, "2") );
        outline0("STA MATHPTR2");
        outline1("LDA %s", address_displacement(_environment, _source, "3") );
        outline0("STA MATHPTR3" );
        outline1("LDA #$%2.2x", (unsigned char)((_destination)&0xff) );
        outline0("STA MATHPTR0");
        outline1("LDA #$%2.2x", (unsigned char)((_destination>>8)&0xff) );
        outline0("STA MATHPTR1" );
        outline0("JSR CPUMATHDIV32BITTO16BIT" );
        outline0("LDA MATHPTR4");
        outline1("STA %s", _other );
        outline0("LDA MATHPTR5");
        outline1("STA %s", address_displacement(_environment, _other, "1") );
        outline0("LDA MATHPTR2");
        outline1("STA %s", _other_remainder );
        outline0("LDA MATHPTR3");
        outline1("STA %s", address_displacement(_environment, _other_remainder, "1") );

    done()

}

/**
 * @brief <i>CPU 6502</i>: emit code to compare two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _positive Meaning of comparison
 */
void cpu6502_compare_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_32bit )

        outline1("LDA %s", _source);
        outline1("CMP %s", _destination);
        outline1("BNE %s", label);
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("CMP %s", address_displacement(_environment, _destination, "1"));
        outline1("BNE %s", label);
        outline1("LDA %s", address_displacement(_environment, _source, "2"));
        outline1("CMP %s", address_displacement(_environment, _destination, "2"));
        outline1("BNE %s", label);
        outline1("LDA %s", address_displacement(_environment, _source, "3"));
        outline1("CMP %s", address_displacement(_environment, _destination, "3"));
        outline1("BNE %s", label);
        outline1("LDA #$%2.2x", 0xff*_positive);
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("JMP %s_2", label);
        outhead1("%s:", label);
        outline1("LDA #$%2.2x", 0xff*(1-_positive));
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outhead1("%s_2:", label);
    
    no_embedded( cpu_compare_32bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to compare two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _positive Meaning of comparison
 */
void cpu6502_compare_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_32bit )

        outline1("LDA %s", _source);
        outline1("CMP #$%2.2x", (unsigned char) ( _destination & 0xff ) );
        outline1("BNE %s", label);
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("CMP #$%2.2x", (unsigned char) ( ( _destination >> 8 ) & 0xff ) );
        outline1("BNE %s", label);
        outline1("LDA %s", address_displacement(_environment, _source, "2"));
        outline1("CMP #$%2.2x", (unsigned char) ( ( _destination >> 16 ) & 0xff ) );
        outline1("BNE %s", label);
        outline1("LDA %s", address_displacement(_environment, _source, "3"));
        outline1("CMP #$%2.2x", (unsigned char) ( ( _destination >> 24 ) & 0xff ) );
        outline1("BNE %s", label);
        outline1("LDA #$%2.2x", 0xff*_positive);
        outline1("STA %s", _other);
        outline1("JMP %s_2", label);
        outhead1("%s:", label);
        outline1("LDA #$%2.2x", 0xff*(1-_positive));
        outline1("STA %s", _other);
        outhead1("%s_2:", label);
    
    no_embedded( cpu_compare_32bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to compare two 32 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void cpu6502_compare_and_branch_32bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_and_branch_32bit_const )

        outline1("LDA %s", address_displacement(_environment, _source, "3"));
        outline1("CMP #$%2.2x", (unsigned char)( _destination >> 24 ) & 0xff );
        outline1("BNE %s", label);
        outline1("LDA %s", address_displacement(_environment, _source, "2"));
        outline1("CMP #$%2.2x", (unsigned char)( _destination >> 16 ) & 0xff );
        outline1("BNE %s", label);
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("CMP #$%2.2x", (unsigned char)( _destination >> 8 ) & 0xff );
        outline1("BNE %s", label);
        outline1("LDA %s", _source);
        outline1("CMP #$%2.2x", (unsigned char)( _destination & 0xff ) );
        outline1("BNE %s", label);
        if ( _positive ) {
            outline1("JMP %s", _label);
            outhead1("%s:", label);
        } else {
            outline1("JMP %snot", label);
            outhead1("%s:", label);
            outline1("JMP %s", _label);
            outhead1("%snot:", label);
        }

    no_embedded( cpu_compare_and_branch_32bit_const )

}

/**
 * @brief <i>CPU 6502</i>: emit code to compare two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void cpu6502_less_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    inline( cpu_less_than_32bit )

        if ( _equal ) {

            cpu6502_compare_32bit( _environment, _source, _destination, _other,  1 );

            if ( _other ) {
                outline1("LDA %s", _other);
            } else {
                outline1("LDA %s", _destination);
            }

            outline1("BEQ %sless", label );
            outline1("JMP %sdone", label );
            outhead1("%sless:", label );

        }

        if ( _signed ) {
            outline1("LDA %s", _source);
            outline1("CMP %s", _destination);
            outline1("LDA %s", address_displacement(_environment, _source, "1"));
            outline1("SBC %s", address_displacement(_environment, _destination, "1"));
            outline1("LDA %s", address_displacement(_environment, _source, "2"));
            outline1("SBC %s", address_displacement(_environment, _destination, "2"));
            outline1("LDA %s", address_displacement(_environment, _source, "3"));
            outline1("SBC %s", address_displacement(_environment, _destination, "3"));
            outline1("BVC %sv0", label );
            outline0("EOR #$80" );
            outhead1("%sv0:", label );
            outline1("BMI %smi", label );
            outhead1("%spl:", label );
            outline0("LDA #$00" );
            if ( _other ) {
                outline1("STA %s", _other);
            } else {
                outline1("STA %s", _destination);
            }
            outline1("JMP %sen", label );
            outhead1("%smi:", label );
            outline0("LDA #$FF" );
            if ( _other ) {
                outline1("STA %s", _other);
            } else {
                outline1("STA %s", _destination);
            }
            outhead1("%sen:", label);

        } else {
            outline1("LDA %s", address_displacement(_environment, _source, "3"));
            outline1("CMP %s", address_displacement(_environment, _destination, "3") );
            outline1("BEQ %s_1a", label);
            outline1("BCC %s", label);
            outline1("BCS %s_0", label);
            outhead1("%s_1a:", label);
            outline1("LDA %s", address_displacement(_environment, _source, "2"));
            outline1("CMP %s", address_displacement(_environment, _destination, "2") );
            outline1("BEQ %s_1", label);
            outline1("BCC %s", label);
            outline1("BCS %s_0", label);
            outhead1("%s_1:", label);
            outline1("LDA %s", address_displacement(_environment, _source, "1"));
            outline1("CMP %s", address_displacement(_environment, _destination, "1") );
            outline1("BEQ %s_1b", label);
            outline1("BCC %s", label);
            outline1("BCS %s_0", label);
            outhead1("%s_1b:", label);
            outline1("LDA %s", _source);
            outline1("CMP %s", _destination );
            outline1("BCC %s", label);
            outline1("BCS %s_0", label);
            outhead1("%s_0:", label);
            outline0("LDA #0" );
            if ( _other ) {
                outline1("STA %s", _other);
            } else {
                outline1("STA %s", _destination);
            }
            outline1("JMP %s_2", label);
            outhead1("%s:", label);
            outline0("LDA #$FF" );
            if ( _other ) {
                outline1("STA %s", _other);
            } else {
                outline1("STA %s", _destination);
            }
            outhead1("%s_2:", label);
        }

        if ( _equal ) {

            outhead1("%sdone:", label );

        }

    no_embedded( cpu_less_than_32bit )

}

void cpu6502_less_than_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    inline( cpu_less_than_32bit_const )

        if ( _signed ) {

            if ( _equal ) {

                cpu6502_compare_32bit_const( _environment, _source, _destination, _other,  1 );
    
                if ( _other ) {
                    outline1("LDA %s", _other);
                } else {
                    outline1("LDA %s", _destination);
                }
    
                outline1("BEQ %sless", label );
                outline1("JMP %sdone", label );
                outhead1("%sless:", label );
    
            }
    
            outline1("LDA %s", _source);
            outline1("CMP #$%2.2x", (unsigned char)( _destination & 0xff ) );
            outline1("LDA %s", address_displacement(_environment, _source, "1"));
            outline1("SBC #$%2.2x", (unsigned char)( ( _destination >> 8 ) & 0xff ) );
            outline1("LDA %s", address_displacement(_environment, _source, "2"));
            outline1("SBC #$%2.2x", (unsigned char)( ( _destination >> 16 ) & 0xff ) );
            outline1("LDA %s", address_displacement(_environment, _source, "3"));
            outline1("SBC #$%2.2x", (unsigned char)( ( _destination >> 24 ) & 0xff ) );
            outline1("BVC %sv0", label );
            outline0("EOR #$80" );
            outhead1("%sv0:", label );
            outline1("BMI %smi", label );
            outhead1("%spl:", label );
            outline0("LDA #$00" );
            outline1("STA %s", _other);
            outline1("JMP %sen", label );
            outhead1("%smi:", label );
            outline0("LDA #$ff" );
            outline1("STA %s", _other);
            outhead1("%sen:", label);

            if ( _equal ) {

                outhead1("%sdone:", label );
    
            }

        } else {
            outline1("LDA %s", address_displacement(_environment, _source, "3"));
            outline1("CMP #$%2.2x", (unsigned char)( ( _destination >> 24 ) & 0xff ) );
            outline1("BEQ %s_1a", label);
            outline1("BCC %s", label);
            outline1("BCS %s_0", label);
            outhead1("%s_1a:", label);
            outline1("LDA %s", address_displacement(_environment, _source, "2"));
            outline1("CMP #$%2.2x", (unsigned char)( ( _destination >> 16 ) & 0xff ) );
            outline1("BEQ %s_1", label);
            outline1("BCC %s", label);
            outline1("BCS %s_0", label);
            outhead1("%s_1:", label);
            outline1("LDA %s", address_displacement(_environment, _source, "1"));
            outline1("CMP #$%2.2x", (unsigned char)( ( _destination >> 8 ) & 0xff ) );
            outline1("BEQ %s_1b", label);
            outline1("BCC %s", label);
            outline1("BCS %s_0", label);
            outhead1("%s_1b:", label);
            outline1("LDA %s", _source);
            outline1("CMP #$%2.2x", (unsigned char)( _destination & 0xff ) );
            if ( _equal ) {
                outline1("BEQ %s", label);
            }
            outhead1("%s_0:", label);
            outline0("LDA #0" );
            outline1("STA %s", _other);
            outline1("JMP %s_2", label);
            outhead1("%s:", label);
            outline0("LDA #$FF" );
            outline1("STA %s", _other);
            outhead1("%s_2:", label);
        }

    no_embedded( cpu_less_than_32bit_const )

}

/**
 * @brief <i>CPU 6502</i>: emit code to compare two 8 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 * @param _equal True if equal
 */
void cpu6502_greater_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    inline( cpu_greater_than_32bit )

        cpu6502_less_than_32bit( _environment, _source, _destination, _other, !_equal, _signed );
        if ( _other ) {
            cpu6502_not_8bit( _environment, _other, _other );
        } else {
            cpu6502_not_8bit( _environment, _destination, _destination );
        }

    no_embedded( cpu_greater_than_32bit )

}

void cpu6502_greater_than_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    inline( cpu_greater_than_32bit )

        cpu6502_less_than_32bit_const( _environment, _source, _destination, _other, !_equal, _signed );
        cpu6502_not_8bit( _environment, _other, _other );

    no_embedded( cpu_greater_than_32bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to add two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to add
 * @param _destination Second value to add and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6502_math_add_32bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_add_32bit )

        outline0("CLC");
        outline1("LDA %s", _source);
        outline1("ADC %s", _destination);
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("ADC %s", address_displacement(_environment, _destination, "1"));
        if ( _other ) {
            outline1("STA %s", address_displacement(_environment, _other, "1"));
        } else {
            outline1("STA %s", address_displacement(_environment, _destination, "1"));
        }
        outline1("LDA %s", address_displacement(_environment, _source, "2"));
        outline1("ADC %s", address_displacement(_environment, _destination, "2"));
        if ( _other ) {
            outline1("STA %s", address_displacement(_environment, _other, "2"));
        } else {
            outline1("STA %s", address_displacement(_environment, _destination, "2"));
        }
        outline1("LDA %s", address_displacement(_environment, _source, "3"));
        outline1("ADC %s", address_displacement(_environment, _destination, "3"));
        if ( _other ) {
            outline1("STA %s", address_displacement(_environment, _other, "3"));
        } else {
            outline1("STA %s", address_displacement(_environment, _destination, "3"));
        }

    no_embedded( cpu_math_add_32bit )

}

void cpu6502_math_add_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

    inline( cpu_math_add_32bit_const )

        outline0("CLC");
        outline1("LDA %s", _source);
        outline1("ADC #$%2.2x", ( _destination & 0xff ) );
        outline1("STA %s", _other);
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("ADC #$%2.2x", ( ( _destination >> 8 ) & 0xff ) );
        outline1("STA %s", address_displacement(_environment, _other, "1"));
        outline1("LDA %s", address_displacement(_environment, _source, "2"));
        outline1("ADC #$%2.2x", ( ( _destination >> 16 ) & 0xff ) );
        outline1("STA %s", address_displacement(_environment, _other, "2"));
        outline1("LDA %s", address_displacement(_environment, _source, "3"));
        outline1("ADC #$%2.2x", ( ( _destination >> 24 ) & 0xff ) );
        outline1("STA %s", address_displacement(_environment, _other, "3"));

    no_embedded( cpu_math_add_32bit_const )

}


/**
 * @brief <i>CPU 6502</i>: emit code to double a 32 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6502_math_double_32bit( Environment * _environment, char *_source, char *_other, int _signed ) {

    inline( cpu_math_double_32bit )

        outline1("LDA %s", _source);
        outline0("ASL A");
        if ( _other ) {
            outline1("STA %s", _source);
        } else {
            outline1("STA %s", _source);
        }
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline0("ROL A");
        if ( _other ) {
            outline1("STA %s", address_displacement(_environment, _source, "1"));
        } else {
            outline1("STA %s", address_displacement(_environment, _source, "1"));
        }
        outline1("LDA %s", address_displacement(_environment, _source, "2"));
        outline0("ROL A");
        if ( _other ) {
            outline1("STA %s", address_displacement(_environment, _source, "2"));
        } else {
            outline1("STA %s", address_displacement(_environment, _source, "2"));
        }
        outline1("LDA %s", address_displacement(_environment, _source, "3"));
        outline0("ROL A");
        if ( _other ) {
            outline1("STA %s", address_displacement(_environment, _source, "3"));
        } else {
            outline1("STA %s", address_displacement(_environment, _source, "3"));
        }

    no_embedded( cpu_math_double_32bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to subtract two 32 bit values
 * 
 * @param _environment Current calling environment
 * @param _source First value to subtract
 * @param _destination Second value to subtract and destination address for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6502_math_sub_32bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_sub_32bit )

        outline0("SEC");
        outline1("LDA %s", _source);
        outline1("SBC %s", _destination);
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("SBC %s", address_displacement(_environment, _destination, "1"));
        if ( _other ) {
            outline1("STA %s", address_displacement(_environment, _other, "1"));
        } else {
            outline1("STA %s", address_displacement(_environment, _destination, "1"));
        }
        outline1("LDA %s", address_displacement(_environment, _source, "2"));
        outline1("SBC %s", address_displacement(_environment, _destination, "2"));
        if ( _other ) {
            outline1("STA %s", address_displacement(_environment, _other, "2"));
        } else {
            outline1("STA %s", address_displacement(_environment, _destination, "2"));
        }
        outline1("LDA %s", address_displacement(_environment, _source, "3"));
        outline1("SBC %s", address_displacement(_environment, _destination, "3"));
        if ( _other ) {
            outline1("STA %s", address_displacement(_environment, _other, "3"));
        } else {
            outline1("STA %s", address_displacement(_environment, _destination, "3"));
        }

    no_embedded( cpu_math_sub_32bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to calculate a 32 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void cpu6502_math_complement_const_32bit( Environment * _environment, char *_source, int _value ) {

    inline( cpu_math_complement_const_32bit )

        outline0("SEC");
        outline1("LDA #$%2.2x", ( _value & 0xff ) );
        outline1("SBC %s", _source);
        outline1("STA %s", _source );
        outline1("LDA #$%2.2x", ( ( _value >> 8 ) & 0xff ) );
        outline1("SBC %s", address_displacement(_environment, _source, "1"));
        outline1("STA %s", address_displacement(_environment, _source, "1") );
        outline1("LDA #$%2.2x", ( ( _value >> 16 ) & 0xff ) );
        outline1("SBC %s", address_displacement(_environment, _source, "2"));
        outline1("STA %s", address_displacement(_environment, _source, "2") );
        outline1("LDA #$%2.2x", ( ( _value >> 24 ) & 0xff ) );
        outline1("SBC %s", address_displacement(_environment, _source, "3"));
        outline1("STA %s", address_displacement(_environment, _source, "3") );

    no_embedded( cpu_math_complement_const_32bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to halves for several times a 32 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6502_math_div2_const_32bit( Environment * _environment, char *_source, int _steps, int _signed, char * _remainder ) {

    inline( cpu_math_div2_const_32bit )

        if ( _signed ) {
            if ( _remainder ) {
                outline1("LDA %s", _source);
                outline0("AND #$01" );
                outline1("STA %s", _remainder);
            }
            outline1("LDA %s", address_displacement(_environment, _source, "3"));
            outline0("AND #$80");
            outline0("TAX");
            while( _steps ) {
                outline0("CLC");
                outline1("LSR %s", address_displacement(_environment, _source, "3"));
                outline1("ROR %s", address_displacement(_environment, _source, "2"));
                outline1("ROR %s", address_displacement(_environment, _source, "1"));
                outline1("ROR %s", _source);
                --_steps;
            }
            outline0("TXA");
            outline1("ORA %s", address_displacement(_environment, _source, "3"));
            outline1("STA %s", address_displacement(_environment, _source, "3"));
        } else {
            if ( _remainder ) {
                outline1("LDA %s", _source);
                outline0("AND #$01" );
                outline1("STA %s", _remainder);
            }
            while( _steps ) {
                outline0("CLC");
                outline1("LSR %s", address_displacement(_environment, _source, "3"));
                outline1("ROR %s", address_displacement(_environment, _source, "2"));
                outline1("ROR %s", address_displacement(_environment, _source, "1"));
                outline1("ROR %s", _source);
                --_steps;
            }
        }

    no_embedded( cpu_math_div2_const_32bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to double for several times a 32 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 */
void cpu6502_math_mul2_const_32bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    inline( cpu_math_mul2_const_32bit )

        if ( _signed ) {
            outline1("LDA %s", address_displacement(_environment, _source, "3"));
            outline0("AND #$80");
            outline0("TAX");
            while( _steps ) {
                outline0("CLC");
                outline1("ASL %s", _source);
                outline1("ROL %s", address_displacement(_environment, _source, "1"));
                outline1("ROL %s", address_displacement(_environment, _source, "2"));
                outline1("ROL %s", address_displacement(_environment, _source, "3"));
                --_steps;
            }
            outline0("TXA");
            outline1("ORA %s", address_displacement(_environment, _source, "3"));
            outline1("STA %s", address_displacement(_environment, _source, "3"));
        } else {
            while( _steps ) {
                outline0("CLC");
                outline1("ASL %s", _source);
                outline1("ROL %s", address_displacement(_environment, _source, "1"));
                outline1("ROL %s", address_displacement(_environment, _source, "2"));
                outline1("ROL %s", address_displacement(_environment, _source, "3"));
                --_steps;
            }
        }

    no_embedded( cpu_math_mul2_const_32bit )

}

/**
 * @brief <i>CPU 6502</i>: emit code to mask with "and" a value of 32 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void cpu6502_math_and_const_32bit( Environment * _environment, char *_source, int _mask ) {

    inline( cpu_math_and_const_32bit )

        outline1("LDA %s", _source);
        outline1("AND #$%2.2x", (_mask & 0xff ) );
        outline1("STA %s", _source);
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline1("AND #$%2.2x", ((_mask>>8) & 0xff ));
        outline1("STA %s", address_displacement(_environment, _source, "1"));
        outline1("LDA %s", address_displacement(_environment, _source, "2"));
        outline1("AND #$%2.2x", ((_mask>>16) & 0xff ) );
        outline1("STA %s", address_displacement(_environment, _source, "2"));
        outline1("LDA %s", address_displacement(_environment, _source, "3"));
        outline1("AND #$%2.2x", ((_mask>>24) & 0xff ));
        outline1("STA %s", address_displacement(_environment, _source, "3"));

    no_embedded( cpu_math_and_const_32bit )

}

void cpu6502_combine_nibbles( Environment * _environment, char * _low_nibble, char * _hi_nibble, char * _byte ) {

    inline( cpu_combine_nibbles )

        outline1("LDA %s", _hi_nibble);
        outline0("ASL");
        outline0("ASL");
        outline0("ASL");
        outline0("ASL");
        outline1("ORA %s", _low_nibble);
        outline1("STA %s", _byte);

    no_embedded( cpu_combine_nibbles )

}

/**
 * @brief <i>CPU cpu6502</i>: emit code to store n bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _n bits to store (>32)
 * @param _value[] Value to store (segmented in 32 bit each)
 */
void cpu6502_move_nbit( Environment * _environment, int _n, char * _source, char *_destination ) {

    int i = 0;
    while( _n ) {
        char sourceAddress[MAX_TEMPORARY_STORAGE]; sprintf( sourceAddress, "%s+%d", _source, i*4 );
        char destinationAddress[MAX_TEMPORARY_STORAGE]; sprintf( destinationAddress, "%s+%d", _destination, i*4 );
        if ( _n <= 32 ) {
            switch( _n ) {
                case 1: case 2: case 3: case 4:
                case 5: case 6: case 7: case 8:
                    cpu6502_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
                case 9: case 10: case 11: case 12:
                case 13: case 14: case 15: case 16:
                    cpu6502_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu6502_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
                case 17: case 18: case 19: case 20:
                case 21: case 22: case 23: case 24:
                    cpu6502_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu6502_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    cpu6502_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
                case 25: case 26: case 27: case 28:
                case 29: case 30: case 31: case 32:
                default:
                    cpu6502_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu6502_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    cpu6502_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+3 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
                    cpu6502_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
            }
            _n = 0;
        } else {
            cpu6502_move_8bit( _environment, sourceAddress, destinationAddress );
            sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
            cpu6502_move_8bit( _environment, sourceAddress, destinationAddress );
            sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
            cpu6502_move_8bit( _environment, sourceAddress, destinationAddress );
            sprintf( sourceAddress, "%s+%d", _source, i*4+3 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
            cpu6502_move_8bit( _environment, sourceAddress, destinationAddress );
            _n -= 32;
        }
        ++i;
    }

}


void cpu6502_jump( Environment * _environment, char * _label ) {

    inline( cpu_jump )

        outline1("JMP %s", _label );

    no_embedded( cpu_jump )

}

void cpu6502_call_addr( Environment * _environment, int _address ) {

    outline1("JSR $%4.4x", _address );

}

void cpu6502_call( Environment * _environment, char * _label ) {

    inline( cpu_call )

        outline1("JSR %s", _label );

    no_embedded( cpu_call )

}

void cpu6502_call_indirect( Environment * _environment, char * _value ) {


    inline( cpu_call_indirect )

        MAKE_LABEL

        char indirectLabel[MAX_TEMPORARY_STORAGE]; sprintf( indirectLabel, "%sindirect", label );

        cpu6502_jump( _environment, label );
        cpu6502_label( _environment, indirectLabel );
        // We must use self-modifying code in order to avoid
        // a 6502/6510 bug when using indirect addressing.
        outline0( "JMP $0000" );
        cpu6502_label( _environment, label );
        outline0( "PHA" );
        outline1( "LDA %s", _value );
        outline1( "STA %s", address_displacement( _environment, indirectLabel, "1" ) );
        outline1( "LDA %s", address_displacement( _environment, _value, "1" ) );
        outline1( "STA %s", address_displacement( _environment, indirectLabel, "2" ) );
        outline0( "PLA" );
        cpu6502_call( _environment, indirectLabel );

    no_embedded( cpu_call_indirect )

}

void cpu6502_jump_indirect( Environment * _environment, char * _value ) {


    inline( cpu_jump_indirect )

        MAKE_LABEL

        char indirectLabel[MAX_TEMPORARY_STORAGE]; sprintf( indirectLabel, "%sindirect", label );

        cpu6502_jump( _environment, label );
        cpu6502_label( _environment, indirectLabel );
        // We must use self-modifying code in order to avoid
        // a 6502/6510 bug when using indirect addressing.
        outline0( "JMP $0000" );
        cpu6502_label( _environment, label );
        outline0( "PHA" );
        outline1( "LDA %s", _value );
        outline1( "STA %s", address_displacement( _environment, indirectLabel, "1" ) );
        outline1( "LDA %s", address_displacement( _environment, _value, "1" ) );
        outline1( "STA %s", address_displacement( _environment, indirectLabel, "2" ) );
        outline0( "PLA" );
        cpu6502_jump( _environment, indirectLabel );

    no_embedded( cpu_jump_indirect )

}

int cpu6502_register_decode( Environment * _environment, char * _register ) {

    CPU6502Register result = REGISTER_NONE;

    if ( !_environment->emptyProcedure ) {

        if ( strcmp( _register, "PC" ) == 0 ) {
            if ( !_environment->emptyProcedure ) {
                CRITICAL_UNSETTABLE_CPU_REGISTER( _register );
            }
            result = REGISTER_PC;
        } else if ( strcmp( _register, "S" ) == 0 ) {
            if ( !_environment->emptyProcedure ) {
                CRITICAL_UNSETTABLE_CPU_REGISTER( _register );
            }
            result = REGISTER_S;
        } else if ( strcmp( _register, "A" ) == 0 ) {
            result = REGISTER_A;
        } else if ( strcmp( _register, "X" ) == 0 ) {
            result = REGISTER_X;
        } else if ( strcmp( _register, "Y" ) == 0 ) {
            result = REGISTER_Y;
        } else if ( strcmp( _register, "XY" ) == 0 ) {
            result = REGISTER_XY;
        } else if ( strcmp( _register, "YX" ) == 0 ) {
            result = REGISTER_XY;
        } else if ( strcmp( _register, "CARRY" ) == 0 ) {
            result = REGISTER_CARRY;
        } else {
            int i, c;
            char * comma = strchr( _register, ',' );
            if ( !comma ) {
                for( i=0, c=strlen(_register); i<c; ++i ) {
                    if ( !isdigit( _register[i] ) )
                        break;
                }
                if ( i >= c ) {
                    return (int)REGISTER_PAGE_ZERO | ( atoi( _register ) & 0xff );
                }
            } else {
                *comma = 0;
                for( i=0, c=strlen(_register); i<c; ++i ) {
                    if ( !isdigit( _register[i] ) )
                        break;
                }
                if ( i >= c ) {
                    return (int)REGISTER_PAGE_ZERO2 | ( atoi( _register ) & 0xff );
                }
            }
        }

    }
    
    return (int)result;

}

void cpu6502_set_asmio( Environment * _environment, int _asmio, int _value ) {

    if ( IS_REGISTER( _asmio ) ) {

        CPU6502Register reg = (CPU6502Register) _asmio;

        switch ( reg ) {
            case REGISTER_NONE:
                CRITICAL_UNKNOWN_CPU_REGISTER( );
                break;
            case REGISTER_PC:
            case REGISTER_S:
                break;
            case REGISTER_A:
                outline1( "LDA #$%2.2x", (unsigned char)(_value & 0xff ) );
                break;
            case REGISTER_X:
                outline1( "LDX #$%2.2x", (unsigned char)(_value & 0xff ) );
                break;
            case REGISTER_Y:
                outline1( "LDY #$%2.2x", (unsigned char)(_value & 0xff ) );
                break;
            case REGISTER_XY:
                outline1( "LDY #$%2.2x", (unsigned char)(_value & 0xff ) );
                outline1( "LDX #$%2.2x", (unsigned char)((_value>>8) & 0xff ) );
                break;
            case REGISTER_YX:
                outline1( "LDX #$%2.2x", (unsigned char)(_value & 0xff ) );
                outline1( "LDY #$%2.2x", (unsigned char)((_value>>8) & 0xff ) );
                break;
            case REGISTER_AXY:
                outline1( "LDY #$%2.2x", (unsigned char)(_value & 0xff ) );
                outline1( "LDX #$%2.2x", (unsigned char)((_value>>8) & 0xff ) );
                outline1( "LDA #$%2.2x", (unsigned char)((_value>>16) & 0xff ) );
                break;
            case REGISTER_CARRY:
                if ( _value ) {
                    outline0( "SEC" );
                } else {
                    outline0( "CLC" );
                }
                break;
            case REGISTER_ZERO:
                if ( _value ) {
                    outline0( "LDA #1" );
                } else {
                    outline0( "LDA #0" );
                }
                break;
        }

    } else if ( IS_PAGE_ZERO( _asmio ) ) {

        outline1( "LDA #$%2.2x", (unsigned char)(_value & 0xff ) );
        outline1( "STA #$%2.2x", (unsigned char)(_asmio & 0xff ) );

    } else if ( IS_PAGE_ZERO2( _asmio ) ) {

        outline1( "LDA #$%2.2x", (unsigned char)(_value & 0xff ) );
        outline1( "STA #$%2.2x", (unsigned char)(_asmio & 0xff ) );
        outline1( "LDA #$%2.2x", (unsigned char)((_value>>8) & 0xff ) );
        outline1( "STA #$%2.2x", (unsigned char)((_asmio+1) & 0xff ) );

    } else {

        CPU6502Stack stk = (CPU6502Stack) _asmio;

        switch ( stk ) {
            case STACK_NONE:
                break;
            case STACK_BYTE:
                outline1( "LDA #$%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "PHA" );
                break;
            case STACK_WORD:
                outline1( "LDA #$%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "PHA" );
                outline1( "LDA #$%2.2x", (unsigned char)(( _value >> 8 ) & 0xff ) );
                outline0( "PHA" );
                break;
            case STACK_DWORD:
                outline1( "LDA #$%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "PHA" );
                outline1( "LDA #$%2.2x", (unsigned char)(( _value >> 8 ) & 0xff ) );
                outline0( "PHA" );
                outline1( "LDA #$%2.2x", (unsigned char)(( _value >> 16 ) & 0xff ) );
                outline0( "PHA" );
                outline1( "LDA #$%2.2x", (unsigned char)(( _value >> 24 ) & 0xff ) );
                outline0( "PHA" );
                break;
        }

    }

}

void cpu6502_set_asmio_indirect( Environment * _environment, int _asmio, char * _value ) {

    if ( IS_REGISTER( _asmio ) ) {

        MAKE_LABEL

        CPU6502Register reg = (CPU6502Register) _asmio;

        switch ( reg ) {
            case REGISTER_NONE:
                CRITICAL_UNKNOWN_CPU_REGISTER( );
                break;
            case REGISTER_PC:
            case REGISTER_S:
                break;
            case REGISTER_A:
                outline1( "LDA %s", _value );
                break;
            case REGISTER_X:
                outline1( "LDX %s", _value );
                break;
            case REGISTER_Y:
                outline1( "LDY %s", _value );
                break;
            case REGISTER_XY:
                outline1( "LDY %s", _value );
                outline1( "LDX %s", address_displacement( _environment, _value, "1" ) );
                break;
            case REGISTER_YX:
                outline1( "LDX %s", _value );
                outline1( "LDY %s", address_displacement( _environment, _value, "1" ) );
                break;
            case REGISTER_AXY:
                outline1( "LDY %s", _value );
                outline1( "LDX %s", address_displacement( _environment, _value, "1" ) );
                outline1( "LDA %s", address_displacement( _environment, _value, "2" ) );
                break;
            case REGISTER_CARRY:
                outline0( "PHA");
                outline1( "LDA %s", _value );
                outline1( "BEQ %szero", label );
                outline0( "SEC" );
                outline1( "JMP %sdone", label );
                outhead1( "%szero:", label );
                outline0( "CLC" );
                outhead1( "%sdone:", label );
                outline0( "PLA");
                break;
            case REGISTER_ZERO:
                outline1( "LDA %s", _value );
                break;
        }

    } else if ( IS_PAGE_ZERO( _asmio ) ) {

        outline1( "LDA %s", _value );
        outline1( "STA #$%2.2x", (unsigned char)(_asmio & 0xff ) );

    } else if ( IS_PAGE_ZERO2( _asmio ) ) {

        outline1( "LDA %s", _value );
        outline1( "STA #$%2.2x", (unsigned char)(_asmio & 0xff ) );
        outline1( "LDA %s", address_displacement( _environment, _value, "1" ) );
        outline1( "STA #$%2.2x", (unsigned char)((_asmio+1) & 0xff ) );

    } else {

        CPU6502Stack stk = (CPU6502Stack) _asmio;

        switch ( stk ) {
            case STACK_NONE:
                break;
            case STACK_BYTE:
                outline1( "LDA %s", address_displacement(_environment, _value, "0") );
                outline0( "PHA" );
                break;
            case STACK_WORD:
                outline1( "LDA %s", address_displacement(_environment, _value, "0") );
                outline0( "PHA" );
                outline1( "LDA %s", address_displacement(_environment, _value, "1") );
                outline0( "PHA" );
                break;
            case STACK_DWORD:
                outline1( "LDA %s", address_displacement(_environment, _value, "0") );
                outline0( "PHA" );
                outline1( "LDA %s", address_displacement(_environment, _value, "1") );
                outline0( "PHA" );
                outline1( "LDA %s", address_displacement(_environment, _value, "2") );
                outline0( "PHA" );
                outline1( "LDA %s", address_displacement(_environment, _value, "3") );
                outline0( "PHA" );
                break;
        }

    }

}

void cpu6502_get_asmio_indirect( Environment * _environment, int _asmio, char * _value ) {

    if ( IS_REGISTER( _asmio ) ) {

        MAKE_LABEL

        CPU6502Register reg = (CPU6502Register) _asmio;

        switch ( reg ) {
            case REGISTER_NONE:
                CRITICAL_UNKNOWN_CPU_REGISTER( );
                break;
            case REGISTER_PC:
            case REGISTER_S:
                break;
            case REGISTER_A:
                outline1( "STA %s", _value );
                break;
            case REGISTER_X:
                outline1( "STX %s", _value );
                break;
            case REGISTER_Y:
                outline1( "STY %s", _value );
                break;
            case REGISTER_XY:
                outline1( "STY %s", _value );
                outline1( "STX %s", address_displacement( _environment, _value, "1" ) );
                break;
            case REGISTER_YX:
                outline1( "STX %s", _value );
                outline1( "STY %s", address_displacement( _environment, _value, "1" ) );
                break;
            case REGISTER_AXY:
                outline1( "STY %s", _value );
                outline1( "STX %s", address_displacement( _environment, _value, "1" ) );
                outline1( "STA %s", address_displacement( _environment, _value, "2" ) );
                break;
            case REGISTER_CARRY:
                outline0( "PHA" );
                outline1( "BCS %sset", label );
                outline0( "LDA #$0" );
                outline1( "STA %s", _value );
                outline1( "JMP %sdone", label );
                outhead1( "%sset:", label );
                outhead1( "%sdone:", label );
                outline0( "LDA #$1" );
                outline1( "STA %s", _value );
                outline0( "PLA" );
                break;
            case REGISTER_ZERO:
                outline0( "PHA" );
                outline1( "BEQ %sset", label );
                outline0( "LDA #$0" );
                outline1( "STA %s", _value );
                outline1( "JMP %sdone", label );
                outhead1( "%sset:", label );
                outhead1( "%sdone:", label );
                outline0( "LDA #$1" );
                outline1( "STA %s", _value );
                outline0( "PLA" );
                break;
        }

    } else if ( IS_PAGE_ZERO( _asmio ) ) {

        outline1( "LDA #$%2.2x", (unsigned char)(_asmio & 0xff ) );
        outline1( "STA %s", _value );

    } else if ( IS_PAGE_ZERO2( _asmio ) ) {

        outline1( "LDA #$%2.2x", (unsigned char)(_asmio & 0xff ) );
        outline1( "STA %s", _value );
        outline1( "LDA #$%2.2x", (unsigned char)((_asmio+1) & 0xff ) );
        outline1( "STA %s", address_displacement( _environment, _value, "1" ) );

    } else {

        CPU6502Stack stk = (CPU6502Stack) _asmio;

        switch ( stk ) {
            case STACK_NONE:
                break;
            case STACK_BYTE:
                outline0( "PLA" );
                outline1( "STA %s", address_displacement(_environment, _value, "0") );
                break;
            case STACK_WORD:
                outline0( "PLA" );
                outline1( "STA %s", address_displacement(_environment, _value, "1") );
                outline0( "PLA" );
                outline1( "STA %s", address_displacement(_environment, _value, "0") );
                break;
            case STACK_DWORD:
                outline0( "PLA" );
                outline1( "STA %s", address_displacement(_environment, _value, "3") );
                outline0( "PLA" );
                outline1( "STA %s", address_displacement(_environment, _value, "2") );
                outline0( "PLA" );
                outline1( "STA %s", address_displacement(_environment, _value, "1") );
                outline0( "PLA" );
                outline1( "STA %s", address_displacement(_environment, _value, "0") );
                break;
        }

    }

}


void cpu6502_return( Environment * _environment ) {

    inline( cpu_return )

        outline0("RTS" );

    no_embedded( cpu_return )

}

void cpu6502_pop( Environment * _environment ) {

    inline( cpu_pop )

        outline0("PLA" );
        outline0("PLA" );

    no_embedded( cpu_return )

}

void cpu6502_halt( Environment * _environment ) {

    MAKE_LABEL

    inline( cpu_halt )

        outhead1("%s:", label );
        outline1("JMP %s", label);

    no_embedded( cpu_halt )

}

void cpu6502_end( Environment * _environment ) {

    inline( cpu_end )

        outline0("SEI");
        cpu6502_halt( _environment );

    no_embedded( cpu_end )

}

void cpu6502_random( Environment * _environment, char * _entropy ) {

    MAKE_LABEL

    inline( cpu_random )

        if ( _entropy ) {
            outhead1("%s:", label);
            outline0("ASL CPURANDOM_SEED");
            outline0("ROL CPURANDOM_SEED+1");
            outline0("ROL CPURANDOM_SEED+2");
            outline0("ROL CPURANDOM_SEED+3");
            outline1("BCC %sxx2", label);
            outline0("LDA CPURANDOM_SEED");
            outline1("EOR %s", _entropy)
            outline0("STA CPURANDOM_SEED");
            outline0("LDA CPURANDOM_SEED+1");
            outline0("EOR #$1D");
            outline0("STA CPURANDOM_SEED+1" );
            outline0("LDA CPURANDOM_SEED+2" );
            outline0("EOR #$C1" );
            outline0("STA CPURANDOM_SEED+2" );
            outline0("LDA CPURANDOM_SEED+3" );
            outline0("EOR #$04" );
            outline0("STA CPURANDOM_SEED+3" );
            outhead1("%sxx2:", label);
        }

    embedded( cpu_random, src_hw_6502_cpu_random_asm );

       
    done()

}

void cpu6502_random_8bit( Environment * _environment, char * _entropy, char * _result ) {

    inline( cpu_random_8bit )

        cpu6502_random( _environment, _entropy );

        if ( _result ) {
            outline1("LDA %s", _entropy );
            outline0("STA CPURANDOM_ENTROPY" );
            outline0("JSR CPURANDOM16" );
            outline0("LDA CPURANDOM_SEED" );
            outline1("STA %s", _result );
        }

    no_embedded( cpu_random_8bit );

}

void cpu6502_random_16bit( Environment * _environment, char * _entropy, char * _result ) {

    inline( cpu_random_16bit )

        cpu6502_random( _environment, _entropy );

        if ( _result ) {
            outline1("LDA %s", _entropy );
            outline0("STA CPURANDOM_ENTROPY" );
            outline0("JSR CPURANDOM16" );
            outline0("LDA CPURANDOM_SEED" );
            outline1("STA %s", _result );
            outline0("LDA CPURANDOM_SEED+1" );
            outline1("STA %s", address_displacement(_environment, _result, "1") );
        }

    no_embedded( cpu_random_8bit );

}

void cpu6502_random_32bit( Environment * _environment, char * _entropy, char * _result ) {

    inline( cpu_random_32bit )

        cpu6502_random( _environment, _entropy );

        if ( _result ) {
            outline1("LDA %s", _entropy );
            outline0("STA CPURANDOM_ENTROPY" );
            outline0("JSR CPURANDOM32" );
            outline0("LDA CPURANDOM_SEED" );
            outline1("STA %s", _result );
            outline0("LDA CPURANDOM_SEED+1" );
            outline1("STA %s", address_displacement(_environment, _result, "1") );
            outline0("LDA CPURANDOM_SEED+2" );
            outline1("STA %s", address_displacement(_environment, _result, "2") );
            outline0("LDA CPURANDOM_SEED+3" );
            outline1("STA %s", address_displacement(_environment, _result, "3") );
        }

    no_embedded( cpu_random_32bit );

}

void cpu6502_limit_16bit( Environment * _environment, char * _variable, int _value ) {

    MAKE_LABEL

    inline( cpu_limit_16bit )

        outline0( "LDA #$0" );
        outline1( "STA %s", address_displacement(_environment, _variable, "1") );
        outline1( "LDA %s", _variable );
        outline1( "CMP #$%2.2x", (unsigned char)(_value & 0xff ) );
        outline1( "BCC %s", label );
        outline1( "SBC #$%2.2x", (unsigned char)(_value & 0xff ) );
        outline1( "STA %s", _variable );
        outhead1( "%s:", label );

    no_embedded( cpu6502_limit_16bit )

}

void cpu6502_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    inline( cpu_busy_wait )

        outline1("LDX %s", _timing );
        outhead1("%s:", label );
        outline0("DEX");
        outline1("BNE %s", label);

    no_embedded( cpu_busy_wait )

}

void cpu6502_logical_and_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    inline( cpu_logical_and_8bit )

        outline1("LDA %s", _left );
        outhead1("BEQ %s", label );
        outline1("LDA %s", _right );
        outline1("BEQ %s", label);
        outline0("LDA #$FF");
        outline1("STA %s", _result);
        outline1("JMP %s_2", label);
        outhead1("%s:", label);
        outline0("LDA #0");
        outline1("STA %s", _result);
        outhead1("%s_2:", label);

    no_embedded( cpu_logical_and_8bit )

}

void cpu6502_and_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    inline( cpu_and_8bit )

        outline1("LDA %s", _left );
        outline1("AND %s", _right );
        outline1("STA %s", _result);

    no_embedded( cpu_and_8bit )

}

void cpu6502_and_8bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    MAKE_LABEL

    inline( cpu_and_8bit_const )

        outline1("LDA %s", _left );
        outline1("AND #$%2.2x", _right );
        outline1("STA %s", _result);

    no_embedded( cpu_and_8bit_const )

}


void cpu6502_and_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    inline( cpu_and_16bit )

        outline1("LDA %s", _left );
        outline1("AND %s", _right );
        outline1("STA %s", _result);
        outline1("LDA %s", address_displacement(_environment, _left, "1") );
        outline1("AND %s", address_displacement(_environment, _right, "1") );
        outline1("STA %s", address_displacement(_environment, _result, "1"));

    no_embedded( cpu_and_16bit )

}

void cpu6502_and_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    inline( cpu_and_16bit )

        outline1("LDA %s", _left );
        outline1("AND %s", _right );
        outline1("STA %s", _result);
        outline1("LDA %s", address_displacement(_environment, _left, "1") );
        outline1("AND %s", address_displacement(_environment, _right, "1") );
        outline1("STA %s", address_displacement(_environment, _result, "1"));
        outline1("LDA %s", address_displacement(_environment, _left, "2") );
        outline1("AND %s", address_displacement(_environment, _right, "2") );
        outline1("STA %s", address_displacement(_environment, _result, "2"));
        outline1("LDA %s", address_displacement(_environment, _left, "3") );
        outline1("AND %s", address_displacement(_environment, _right, "3") );
        outline1("STA %s", address_displacement(_environment, _result, "3"));

    no_embedded( cpu_and_8bit )

}

void cpu6502_logical_or_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    inline( cpu_logical_or_8bit )

        outline1("LDA %s", _left );
        outhead1("BNE %sd1", label );
        outline1("LDA %s", _right );
        outline1("BNE %sd1", label);
        outline1("JMP %s0", label);
        outhead1("%sd1:", label);
        outline0("LDA #$FF");
        outline1("STA %s", _result);
        outline1("JMP %sx", label);
        outhead1("%s0:", label);
        outline0("LDA #0");
        outline1("STA %s", _result);
        outhead1("%sx:", label);

    no_embedded( cpu_logical_or_8bit )

}

void cpu6502_or_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    inline( cpu_or_8bit )

        outline1("LDA %s", _left );
        outline1("ORA %s", _right );
        outline1("STA %s", _result);

    no_embedded( cpu_or_8bit )

}

void cpu6502_or_8bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    MAKE_LABEL

    inline( cpu_or_8bit_const )

        outline1("LDA %s", _left );
        outline1("ORA #$%2.2x", _right );
        outline1("STA %s", _result);

    no_embedded( cpu_or_8bit_const )

}

void cpu6502_or_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    inline( cpu_or_16bit )

        outline1("LDA %s", _left );
        outline1("ORA %s", _right );
        outline1("STA %s", _result);
        outline1("LDA %s", address_displacement(_environment, _left, "1") );
        outline1("ORA %s", address_displacement(_environment, _right, "1") );
        outline1("STA %s", address_displacement(_environment, _result, "1"));

    no_embedded( cpu_or_16bit )

}

void cpu6502_or_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    inline( cpu_or_32bit )

        outline1("LDA %s", _left );
        outline1("ORA %s", _right );
        outline1("STA %s", _result);
        outline1("LDA %s", address_displacement(_environment, _left, "1") );
        outline1("ORA %s", address_displacement(_environment, _right, "1") );
        outline1("STA %s", address_displacement(_environment, _result, "1"));
        outline1("LDA %s", address_displacement(_environment, _left, "2") );
        outline1("ORA %s", address_displacement(_environment, _right, "2") );
        outline1("STA %s", address_displacement(_environment, _result, "2"));
        outline1("LDA %s", address_displacement(_environment, _left, "3") );
        outline1("ORA %s", address_displacement(_environment, _right, "3") );
        outline1("STA %s", address_displacement(_environment, _result, "3"));

    no_embedded( cpu_or_32bit )

}

void cpu6502_xor_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    inline( cpu_xor_8bit )

        outline1("LDA %s", _left );
        outline1("EOR %s", _right );
        outline1("STA %s", _result);

    no_embedded( cpu_xor_8bit )

}

void cpu6502_xor_8bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    MAKE_LABEL

    inline( cpu_xor_8bit )

        outline1("LDA %s", _left );
        outline1("EOR #$%2.2x", _right );
        outline1("STA %s", _result);

    no_embedded( cpu_xor_8bit )

}

void cpu6502_xor_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    inline( cpu_xor_16bit )

        outline1("LDA %s", _left );
        outline1("EOR %s", _right );
        outline1("STA %s", _result);
        outline1("LDA %s", address_displacement(_environment, _left, "1") );
        outline1("EOR %s", address_displacement(_environment, _right, "1") );
        outline1("STA %s", address_displacement(_environment, _result, "1"));

    no_embedded( cpu_xor_16bit )

}

void cpu6502_xor_16bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    MAKE_LABEL

    inline( cpu_xor_16bit )

        outline1("LDA %s", _left );
        outline1("EOR #$%2.2x", (unsigned char)(_right&0xff) );
        outline1("STA %s", _result);
        outline1("LDA %s", address_displacement(_environment, _left, "1") );
        outline1("EOR #$%2.2x", (unsigned char)((_right>>8)&0xff) );
        outline1("STA %s", address_displacement(_environment, _result, "1"));

    no_embedded( cpu_xor_16bit )

}

void cpu6502_xor_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    inline( cpu_xor_32bit )

        outline1("LDA %s", _left );
        outline1("EOR %s", _right );
        outline1("STA %s", _result);
        outline1("LDA %s", address_displacement(_environment, _left, "1") );
        outline1("EOR %s", address_displacement(_environment, _right, "1") );
        outline1("STA %s", address_displacement(_environment, _result, "1"));
        outline1("LDA %s", address_displacement(_environment, _left, "2") );
        outline1("EOR %s", address_displacement(_environment, _right, "2") );
        outline1("STA %s", address_displacement(_environment, _result, "2"));
        outline1("LDA %s", address_displacement(_environment, _left, "3") );
        outline1("EOR %s", address_displacement(_environment, _right, "3") );
        outline1("STA %s", address_displacement(_environment, _result, "3"));

    no_embedded( cpu_xor_32bit )

}

void cpu6502_xor_32bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    MAKE_LABEL

    inline( cpu_xor_32bit )

        outline1("LDA %s", _left );
        outline1("EOR #$%2.2x", (unsigned char)(_right&0xff) );
        outline1("STA %s", _result);
        outline1("LDA %s", address_displacement(_environment, _left, "1") );
        outline1("EOR #$%2.2x", (unsigned char)((_right>>8)&0xff) );
        outline1("STA %s", address_displacement(_environment, _result, "1"));
        outline1("LDA %s", address_displacement(_environment, _left, "2") );
        outline1("EOR #$%2.2x", (unsigned char)((_right>>16)&0xff) );
        outline1("STA %s", address_displacement(_environment, _result, "2"));
        outline1("LDA %s", address_displacement(_environment, _left, "3") );
        outline1("EOR #$%2.2x", (unsigned char)((_right>>24)&0xff) );
        outline1("STA %s", address_displacement(_environment, _result, "3"));

    no_embedded( cpu_xor_32bit )

}

void cpu6502_swap_8bit( Environment * _environment, char * _left, char * _right ) {

    MAKE_LABEL

    inline( cpu_swap_8bit )

        outline1("LDA %s", _left );
        outline0("PHA" );
        outline1("LDA %s", _right );
        outline1("STA %s", _left );
        outline0("PLA" );
        outline1("STA %s", _right);

    no_embedded( cpu_swap_8bit )

}

void cpu6502_swap_16bit( Environment * _environment, char * _left, char * _right ) {

    MAKE_LABEL

    no_inline( cpu_swap_16bit )

    embedded( cpu_swap_16bit, src_hw_6502_cpu_swap_asm );

        outline0("LDY #1" );
        outline1("LDA #>%s", _left );
        outline0("STA TMPPTR+1" );
        outline1("LDA #<%s", _left );
        outline0("STA TMPPTR" );
        outline1("LDA #>%s", _right );
        outline0("STA TMPPTR2+1" );
        outline1("LDA #<%s", _right );
        outline0("STA TMPPTR2" );
        outline0("JSR CPUSWAP" );

    done( )

}

void cpu6502_swap_32bit( Environment * _environment, char * _left, char * _right ) {

    MAKE_LABEL

    no_inline( cpu_swap_16bit ) // it is not an error, swap 16/32 share code

    embedded( cpu_swap_16bit, src_hw_6502_cpu_swap_asm );

        outline0("LDY #3" );
        outline1("LDA #>%s", _left );
        outline0("STA TMPPTR+1" );
        outline1("LDA #<%s", _left );
        outline0("STA TMPPTR" );
        outline1("LDA #>%s", _right );
        outline0("STA TMPPTR2+1" );
        outline1("LDA #<%s", _right );
        outline0("STA TMPPTR2" );
        outline0("JSR CPUSWAP" );

    done( )

}

void cpu6502_logical_not_8bit( Environment * _environment, char * _value, char * _result ) {

    MAKE_LABEL

    inline( cpu_logical_not_8bit )

        outline1("LDA %s", _value );
        outline0("EOR #$FF" );
        outline1("STA %s", _result );

    no_embedded( cpu_logical_not_8bit )

}

void cpu6502_not_8bit( Environment * _environment, char * _value, char * _result ) {

    MAKE_LABEL

    inline( cpu_not_8bit )

        outline1("LDA %s", _value );
        outline0("EOR #$FF" );
        outline1("STA %s", _result );

    no_embedded( cpu_not_8bit )

}

void cpu6502_not_16bit( Environment * _environment, char * _value, char * _result ) {

    MAKE_LABEL

    inline( cpu_not_16bit )

        outline1("LDA %s", _value );
        outline0("EOR #$FF" );
        outline1("STA %s", _result );
        outline1("LDA %s", address_displacement(_environment, _value, "1") );
        outline0("EOR #$FF" );
        outline1("STA %s", address_displacement(_environment, _result, "1") );

    no_embedded( cpu_not_16bit )

}

void cpu6502_not_32bit( Environment * _environment, char * _value, char * _result ) {

    MAKE_LABEL

    inline( cpu_not_32bit )

        outline1("LDA %s", _value );
        outline0("EOR #$FF" );
        outline1("STA %s", _result );
        outline1("LDA %s", address_displacement(_environment, _value, "1") );
        outline0("EOR #$FF" );
        outline1("STA %s", address_displacement(_environment, _result, "1") );
        outline1("LDA %s", address_displacement(_environment, _value, "2") );
        outline0("EOR #$FF" );
        outline1("STA %s", address_displacement(_environment, _result, "2") );
        outline1("LDA %s", address_displacement(_environment, _value, "3") );
        outline0("EOR #$FF" );
        outline1("STA %s", address_displacement(_environment, _result, "3") );

    no_embedded( cpu_not_32bit )

}

void cpu6502_di( Environment * _environment ) {

    inline( cpu_di )

        outline0("SEI" );

    no_embedded( cpu_di )

}

void cpu6502_ei( Environment * _environment ) {

    inline( cpu_ei )

        outline0("CLI" );

    no_embedded( cpu_di )

}

void cpu6502_inc( Environment * _environment, char * _variable ) {

    inline( cpu_inc )

        outline1("INC %s", _variable );

    no_embedded( cpu_inc )

}

void cpu6502_inc_16bit( Environment * _environment, char * _variable ) {

    MAKE_LABEL

    inline( cpu_inc_16bit )

        outline1("INC %s", _variable );
        outline1("BNE %s", label );
        outline1("INC %s", address_displacement(_environment, _variable, "1") );
        outhead1("%s:", label );

    no_embedded( cpu_inc_16bit )

}

void cpu6502_inc_32bit( Environment * _environment, char * _variable ) {

    MAKE_LABEL

    inline( cpu_inc_32bit )

        outline1("INC %s", _variable );
        outline1("BNE %s", label );
        outline1("INC %s", address_displacement(_environment, _variable, "1") );
        outline1("BNE %s", label );
        outline1("INC %s", address_displacement(_environment, _variable, "2") );
        outline1("BNE %s", label );
        outline1("INC %s", address_displacement(_environment, _variable, "3") );
        outhead1("%s:", label );

    no_embedded( cpu_inc_32bit )

}

void cpu6502_dec( Environment * _environment, char * _variable ) {

    inline( cpu_dec )

        outline1("DEC %s", _variable );

    no_embedded( cpu_dec )

}

void cpu6502_dec_16bit( Environment * _environment, char * _variable ) {

    MAKE_LABEL

    inline( cpu_dec_16bit )

        outline1("DEC %s", _variable );
        outline1("LDA %s", _variable );
        outline0("CMP #$FF" );
        outline1("BNE %s", label );
        outline1("DEC %s", address_displacement(_environment, _variable, "1") );
        outhead1("%s:", label );

    no_embedded( cpu_dec_16bit )

}

void cpu6502_dec_32bit( Environment * _environment, char * _variable ) {

    MAKE_LABEL

    inline( cpu_dec_32bit )

        outline1("DEC %s", _variable );
        outline1("LDA %s", _variable );
        outline0("CMP #$FF" );
        outline1("BNE %s", label );
        outline1("DEC %s", address_displacement(_environment, _variable, "1") );
        outline1("LDA %s", address_displacement(_environment, _variable, "1") );
        outline0("CMP #$FF" );
        outline1("BNE %s", label );
        outline1("DEC %s", address_displacement(_environment, _variable, "2") );
        outline1("LDA %s", address_displacement(_environment, _variable, "2") );
        outline0("CMP #$FF" );
        outline1("BNE %s", label );
        outline1("DEC %s", address_displacement(_environment, _variable, "3") );
        outline1("LDA %s", address_displacement(_environment, _variable, "3") );
        outhead1("%s:", label );

    no_embedded( cpu_dec_32bit )

}

void cpu6502_mem_move( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    MAKE_LABEL

    inline( cpu_mem_move )

        outline1("LDY %s", _size );
        outline1("BEQ %sdone", label );
        outline0("LDY #$0" );
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        outline1("LDA %s", address_displacement(_environment, _destination, "1") );
        outline0("STA TMPPTR2+1" );
        outline1("LDA %s", _destination );
        outline0("STA TMPPTR2" );
        outhead1("%s:", label );
        outline0("LDA (TMPPTR), Y" );
        outline0("STA (TMPPTR2), Y" );
        outline0("INY" );
        outline1("CPY %s", _size );
        outline1("BNE %s", label );
        outhead1("%sdone:", label );

    embedded( cpu_mem_move, src_hw_6502_cpu_mem_move_asm );

        deploy( duff, src_hw_6502_duff_asm );
        
        outline1("LDX %s", _size );
        outline0("STX MATHPTR0" );
        outline0("LDX #$0" );
        outline0("STX MATHPTR1" );
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        outline1("LDA %s", address_displacement(_environment, _destination, "1") );
        outline0("STA TMPPTR2+1" );
        outline1("LDA %s", _destination );
        outline0("STA TMPPTR2" );
        outline0("JSR DUFFDEVICE" );

    done()

}

void cpu6502_mem_move_16bit( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    MAKE_LABEL

    no_inline( cpu_mem_move )

    embedded( cpu_mem_move, src_hw_6502_cpu_mem_move_asm );

        deploy( duff, src_hw_6502_duff_asm );

        outline1("LDX %s", _size );
        outline0("STX MATHPTR0" );
        outline1("LDX %s", address_displacement(_environment, _size, "1") );
        outline0("STX MATHPTR1" );
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        outline1("LDA %s", address_displacement(_environment, _destination, "1") );
        outline0("STA TMPPTR2+1" );
        outline1("LDA %s", _destination );
        outline0("STA TMPPTR2" );
        outline0("JSR DUFFDEVICE" );

    done()

}

void cpu6502_mem_move_direct( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    MAKE_LABEL

    inline( cpu_mem_move ) // special case

        outline1("LDY %s", _size );
        outline1("BEQ %sdone", label );
        outline0("LDY #$0" );
        outline1("LDA #>%s", _source );
        outline0("STA TMPPTR+1" );
        outline1("LDA #<%s", _source );
        outline0("STA TMPPTR" );
        outline1("LDA #>%s", _destination );
        outline0("STA TMPPTR2+1" );
        outline1("LDA #<%s", _destination );
        outline0("STA TMPPTR2" );
        outhead1("%s:", label );
        outline0("LDA (TMPPTR), Y" );
        outline0("STA (TMPPTR2), Y" );
        outline0("INY" );
        outline1("CPY %s", _size );
        outline1("BNE %s", label );
        outhead1("%sdone:", label );

    embedded( cpu_mem_move, src_hw_6502_cpu_mem_move_asm );

        deploy( duff, src_hw_6502_duff_asm );

        outline1("LDX %s", _size );
        outline0("STX MATHPTR0" );
        outline0("LDX #$0" );
        outline0("STX MATHPTR1" );
        outline1("LDA #>%s", _source );
        outline0("STA TMPPTR+1" );
        outline1("LDA #<%s", _source );
        outline0("STA TMPPTR" );
        outline1("LDA #>%s", _destination );
        outline0("STA TMPPTR2+1" );
        outline1("LDA #<%s", _destination );
        outline0("STA TMPPTR2" );
        outline0("JSR DUFFDEVICE" );

    done()

}

void cpu6502_mem_move_direct2_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    MAKE_LABEL

    inline( cpu_mem_move ) // special case

        outline1("LDA #$%2.2x", ( _size >> 8 ) & 0xff );
        outline0("STA MATHPTR1" );
        outline1("LDA #$%2.2x", _size & 0xff );
        outline0("STA MATHPTR0" );
        outline0("ORA MATHPTR1" );
        outline1("BEQ %sdone", label );
        outline0("LDY #$0" );
        outline1("LDA %s+1", _source );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        outline1("LDA #>%s", _destination );
        outline0("STA TMPPTR2+1" );
        outline1("LDA #<%s", _destination );
        outline0("STA TMPPTR2" );
        outhead1("%s:", label );
        outline0("LDA (TMPPTR), Y" );
        outline0("STA (TMPPTR2), Y" );
        outline0("INC TMPPTR" );
        outline1("BNE %sadd1", label );
        outline0("INC TMPPTR+1" );
        outhead1("%sadd1:", label );
        outline0("INC TMPPTR2" );
        outline1("BNE %sadd2", label );
        outline0("INC TMPPTR2+1" );
        outhead1("%sadd2:", label );
        outline0("DEC MATHPTR0" );
        outline1("BNE %sctr", label );
        outline0("DEC MATHPTR1" );
        outhead1("%sctr:", label );
        outline0("LDA MATHPTR0" );
        outline0("ORA MATHPTR1" );
        outline1("BNE %s:", label );
        outhead1("%sdone:", label );

    embedded( cpu_mem_move, src_hw_6502_cpu_mem_move_asm );

        deploy( duff, src_hw_6502_duff_asm );

        outline1("LDA #$%2.2x", ( _size >> 8 ) & 0xff );
        outline0("STA MATHPTR1" );
        outline1("LDA #$%2.2x", _size & 0xff );
        outline0("STA MATHPTR0" );
        outline1("LDA %s+1", _source );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        outline1("LDA #>%s", _destination );
        outline0("STA TMPPTR2+1" );
        outline1("LDA #<%s", _destination );
        outline0("STA TMPPTR2" );
        outline0("JSR DUFFDEVICE" );

    done()

}

void cpu6502_mem_move_direct2( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    MAKE_LABEL

    inline( cpu_mem_move ) // special case

        outline1("LDA %s+1", _size );
        outline0("STA MATHPTR1" );
        outline1("LDA %s", _size );
        outline0("STA MATHPTR0" );
        outline0("ORA MATHPTR1" );
        outline1("BEQ %sdone", label );
        outline0("LDY #$0" );
        outline1("LDA %s+1", _source );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        outline1("LDA #>%s", _destination );
        outline0("STA TMPPTR2+1" );
        outline1("LDA #<%s", _destination );
        outline0("STA TMPPTR2" );
        outhead1("%s:", label );
        outline0("LDA (TMPPTR), Y" );
        outline0("STA (TMPPTR2), Y" );
        outline0("INC TMPPTR" );
        outline1("BNE %sadd1", label );
        outline0("INC TMPPTR+1" );
        outhead1("%sadd1:", label );
        outline0("INC TMPPTR2" );
        outline1("BNE %sadd2", label );
        outline0("INC TMPPTR2+1" );
        outhead1("%sadd2:", label );
        outline0("DEC MATHPTR0" );
        outline1("BNE %sctr", label );
        outline0("DEC MATHPTR1" );
        outhead1("%sctr:", label );
        outline0("LDA MATHPTR0" );
        outline0("ORA MATHPTR1" );
        outline1("BNE %s:", label );
        outhead1("%sdone:", label );

    embedded( cpu_mem_move, src_hw_6502_cpu_mem_move_asm );

        deploy( duff, src_hw_6502_duff_asm );

        outline1("LDA %s+1", _size );
        outline0("STA MATHPTR1" );
        outline1("LDA %s", _size );
        outline0("STA MATHPTR0" );
        outline1("LDA %s+1", _source );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        outline1("LDA #>%s", _destination );
        outline0("STA TMPPTR2+1" );
        outline1("LDA #<%s", _destination );
        outline0("STA TMPPTR2" );
        outline0("JSR DUFFDEVICE" );

    done()

}

void cpu6502_mem_move_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size ) {

        MAKE_LABEL

        inline( cpu_mem_move )

            outline0("LDY #$0" );
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("STA TMPPTR+1" );
            outline1("LDA %s", _source );
            outline0("STA TMPPTR" );
            outline1("LDA %s", address_displacement(_environment, _destination, "1") );
            outline0("STA TMPPTR2+1" );
            outline1("LDA %s", _destination );
            outline0("STA TMPPTR2" );
            outhead1("%s:", label );
            outline0("LDA (TMPPTR), Y" );
            outline0("STA (TMPPTR2), Y" );
            outline0("INY" );
            outline1("CPY #$%2.2x", (_size & 0xff ) );
            outline1("BNE %s", label );

        embedded( cpu_mem_move, src_hw_6502_cpu_mem_move_asm );

            deploy( duff, src_hw_6502_duff_asm );

            outline1("LDX #$%2.2X", (_size & 0xff ) );
            outline0("STX MATHPTR0" );
            outline1("LDX #$%2.2X", ( _size >> 8 ) & 0xff );
            outline0("STX MATHPTR1" );
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("STA TMPPTR+1" );
            outline1("LDA %s", _source );
            outline0("STA TMPPTR" );
            outline1("LDA %s", address_displacement(_environment, _destination, "1") );
            outline0("STA TMPPTR2+1" );
            outline1("LDA %s", _destination );
            outline0("STA TMPPTR2" );
            outline0("JSR DUFFDEVICE" );

        done()
    }

}

void cpu6502_mem_move_direct_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size ) {

        MAKE_LABEL

        inline( cpu_mem_move )

            if ( _size <= 0xff ) {

                outline0("LDY #$0" );
                outline1("LDA #>%s", _source );
                outline0("STA TMPPTR+1" );
                outline1("LDA #<%s", _source );
                outline0("STA TMPPTR" );
                outline1("LDA #>%s", _destination );
                outline0("STA TMPPTR2+1" );
                outline1("LDA #<%s", _destination );
                outline0("STA TMPPTR2" );
                outhead1("%s:", label );
                outline0("LDA (TMPPTR), Y" );
                outline0("STA (TMPPTR2), Y" );
                outline0("INY" );
                outline1("CPY #$%2.2x", (_size & 0xff ) );
                outline1("BNE %s", label );

            } else {

                outline0("LDX #$0" );
                outline0("LDY #$0" );
                outline1("LDA #>(%s)", _source );
                outline0("STA TMPPTR+1" );
                outline1("LDA #<(%s)", _source );
                outline0("STA TMPPTR" );
                outline1("LDA #>(%s)", _destination );
                outline0("STA TMPPTR2+1" );
                outline1("LDA #<(%s)", _destination );
                outline0("STA TMPPTR2" );
                outhead1("%s:", label );
                outline0("LDA (TMPPTR), Y" );
                outline0("STA (TMPPTR2), Y" );
                outline0("INY" );
                outline0("CPY #$ff" );
                outline1("BNE %s", label );
                outline0("CLC" );
                outline0("LDA TMPPTR" );
                outline0("ADC #$FF" );
                outline0("STA TMPPTR" );
                outline0("LDA TMPPTR+1" );
                outline0("ADC #0" );
                outline0("STA TMPPTR+1" );
                outline0("CLC" );
                outline0("LDA TMPPTR2" );
                outline0("ADC #$FF" );
                outline0("STA TMPPTR2" );
                outline0("LDA TMPPTR2+1" );
                outline0("ADC #0" );
                outline0("STA TMPPTR2+1" );
                outline0("LDY #0" );
                outline1("CPX #$%2.2x", ( ( ( _size >> 8 ) & 0xff ) ) - 1 );
                outline1("BEQ %se", label );
                outline0("INX" );
                outline1("JMP %s", label );
                outhead1("%se:", label );
                outhead1("%sfinal:", label );
                outline0("LDA (TMPPTR), Y" );
                outline0("STA (TMPPTR2), Y" );
                outline0("INY" );
                outline1("CPY #$%2.2x", _size - ( ( ( ( _size >> 8 ) & 0xff ) ) ) * 0xff );
                outline1("BNE %sfinal", label );
            
            }

        embedded( cpu_mem_move, src_hw_6502_cpu_mem_move_asm );

            deploy( duff, src_hw_6502_duff_asm );

            outline1("LDX #$%2.2X", (_size & 0xff ) );
            outline0("STX MATHPTR0" );
            outline1("LDX #$%2.2X", ( _size >> 8 ) & 0xff );
            outline0("STX MATHPTR1" );
            outline1("LDA #>(%s)", _source );
            outline0("STA TMPPTR+1" );
            outline1("LDA #<(%s)", _source );
            outline0("STA TMPPTR" );
            outline1("LDA #>(%s)", _destination );
            outline0("STA TMPPTR2+1" );
            outline1("LDA #<(%s)", _destination );
            outline0("STA TMPPTR2" );
            outline0("JSR DUFFDEVICE" );

        done()

    }

}

void cpu6502_mem_move_direct_indirect_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size ) {

        MAKE_LABEL

        inline( cpu_mem_move )

            if ( _size <= 0xff ) {

                outline0("LDY #$0" );
                outline1("LDA #>%s", _source );
                outline0("STA TMPPTR+1" );
                outline1("LDA #<%s", _source );
                outline0("STA TMPPTR" );
                outline1("LDA %s", address_displacement(_environment, _destination, "1") );
                outline0("STA TMPPTR2+1" );
                outline1("LDA %s", _destination );
                outline0("STA TMPPTR2" );
                outhead1("%s:", label );
                outline0("LDA (TMPPTR), Y" );
                outline0("STA (TMPPTR2), Y" );
                outline0("INY" );
                outline1("CPY #$%2.2x", (_size & 0xff ) );
                outline1("BNE %s", label );

            } else {

                outline0("LDX #$0" );
                outline0("LDY #$0" );
                outline1("LDA #>%s", _source );
                outline0("STA TMPPTR+1" );
                outline1("LDA #<%s", _source );
                outline0("STA TMPPTR" );
                outline1("LDA %s", address_displacement(_environment, _destination, "1") );
                outline0("STA TMPPTR2+1" );
                outline1("LDA %s", _destination );
                outline0("STA TMPPTR2" );
                outhead1("%s:", label );
                outline0("LDA (TMPPTR), Y" );
                outline0("STA (TMPPTR2), Y" );
                outline0("INY" );
                outline0("CPY #$ff" );
                outline1("BNE %s", label );
                outline0("CLC" );
                outline0("LDA TMPPTR" );
                outline0("ADC #$FF" );
                outline0("STA TMPPTR" );
                outline0("LDA TMPPTR+1" );
                outline0("ADC #0" );
                outline0("STA TMPPTR+1" );
                outline0("CLC" );
                outline0("LDA TMPPTR2" );
                outline0("ADC #$FF" );
                outline0("STA TMPPTR2" );
                outline0("LDA TMPPTR2+1" );
                outline0("ADC #0" );
                outline0("STA TMPPTR2+1" );
                outline0("LDY #0" );
                outline1("CPX #$%2.2x", ( ( ( _size >> 8 ) & 0xff ) ) - 1 );
                outline1("BEQ %se", label );
                outline0("INX" );
                outline1("JMP %s", label );
                outhead1("%se:", label );
                outhead1("%sfinal:", label );
                outline0("LDA (TMPPTR), Y" );
                outline0("STA (TMPPTR2), Y" );
                outline0("INY" );
                outline1("CPY #$%2.2x", _size - ( ( ( ( _size >> 8 ) & 0xff ) ) ) * 0xff );
                outline1("BNE %sfinal", label );
            
            }

        embedded( cpu_mem_move, src_hw_6502_cpu_mem_move_asm );

            deploy( duff, src_hw_6502_duff_asm );

            outline1("LDX #$%2.2X", (_size & 0xff ) );
            outline0("STX MATHPTR0" );
            outline1("LDX #$%2.2X", ( _size >> 8 ) & 0xff );
            outline0("STX MATHPTR1" );
            outline1("LDA #>%s", _source );
            outline0("STA TMPPTR+1" );
            outline1("LDA #<%s", _source );
            outline0("STA TMPPTR" );
            outline1("LDA %s", address_displacement(_environment, _destination, "1") );
            outline0("STA TMPPTR2+1" );
            outline1("LDA %s", _destination );
            outline0("STA TMPPTR2" );
            outline0("JSR DUFFDEVICE" );

        done()

    }

}

void cpu6502_mem_move_indirect_direct_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size ) {

        MAKE_LABEL

        no_inline( cpu_mem_move )

        embedded( cpu_mem_move, src_hw_6502_cpu_mem_move_asm );

            deploy( duff, src_hw_6502_duff_asm );

            outline1("LDX #$%2.2X", (_size & 0xff ) );
            outline0("STX MATHPTR0" );
            outline1("LDX #$%2.2X", ( _size >> 8 ) & 0xff );
            outline0("STX MATHPTR1" );
            outline1("LDA %s", _source );
            outline0("STA TMPPTR+1" );
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("STA TMPPTR" );
            outline1("LDA #>%s", _destination );
            outline0("STA TMPPTR2+1" );
            outline1("LDA #<%s", _destination );
            outline0("STA TMPPTR2" );
            outline0("JSR DUFFDEVICE" );

        done()

    }

}

void cpu6502_compare_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {
    
    MAKE_LABEL

    inline( cpu_compare_memory )

        outline1("LDA %s", _size );
        outline1("BEQ %sequal", label );
        outline0("LDY #$0" );
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        outline1("LDA %s", address_displacement(_environment, _destination, "1") );
        outline0("STA TMPPTR2+1" );
        outline1("LDA %s", _destination );
        outline0("STA TMPPTR2" );
        outhead1("%sloop:", label );
        outline0("LDA (TMPPTR2), Y" );
        outline0("CMP (TMPPTR), Y" );
        outline1("BNE %sdiff", label );
        outline0("INY" );
        outline1("CPY %s", _size );
        outline1("BNE %sloop", label );
        outhead1("%sequal:", label );
        outline1("LDA #%d", _equal ? 255 : 0 );
        outline1("STA %s", _result );
        outline1("JMP %sfinal", label );
        outhead1("%sdiff:", label );
        outline1("LDA #%d", _equal ? 0 : 255 );
        outline1("STA %s", _result );
        outhead1("%sfinal:", label );

    no_embedded( cpu_compare_memory )
    
}

void cpu6502_compare_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {
    
    MAKE_LABEL

    inline( cpu_compare_memory_size )

        outline0("LDY #$0" );
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        outline1("LDA %s", address_displacement(_environment, _destination, "1") );
        outline0("STA TMPPTR2+1" );
        outline1("LDA %s", _destination );
        outline0("STA TMPPTR2" );
        outhead1("%sloop:", label );
        outline0("LDA (TMPPTR2), Y" );
        outline0("CMP (TMPPTR), Y" );
        outline1("BNE %sdiff", label );
        outline0("INY" );
        outline1("CPY #$%2.2x", _size );
        outline1("BNE %sloop", label );
        outline1("LDA #%d", _equal ? 255 : 0 );
        outline1("STA %s", _result );
        outline1("JMP %sfinal", label );
        outhead1("%sdiff:", label );
        outline1("LDA #%d", _equal ? 0 : 255 );
        outline1("STA %s", _result );
        outhead1("%sfinal:", label );

    no_embedded( cpu_compare_memory_size )

}

void cpu6502_less_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {
    
    MAKE_LABEL

    inline( cpu_less_than_memory )

        outline0("LDY #$0" );
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        outline1("LDA %s", address_displacement(_environment, _destination, "1") );
        outline0("STA TMPPTR2+1" );
        outline1("LDA %s", _destination );
        outline0("STA TMPPTR2" );    
        outhead1("%sloop:", label );
        outline0("LDA (TMPPTR2), Y" );
        outline0("CMP (TMPPTR), Y" );
        if ( ! _equal ) {
            outline1("BEQ %sfalse", label);
        }
        outline1("BCS %strue", label);
        outline0("INY" );
        outline1("CPY %s", _size );
        outline1("BNE %sloop", label );
        outhead1("%sfalse:", label );
        outline0("LDA #0" );
        outline1("STA %s", _result );
        outline1("JMP %sfinal", label );
        outhead1("%strue:", label );
        outline0("LDA #$FF" );
        outline1("STA %s", _result );
        outhead1("%sfinal:", label );

    no_embedded( cpu_less_than_memory )

}

void cpu6502_less_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {
    
    MAKE_LABEL

    inline( cpu_less_than_memory_size )

        outline0("LDY #$0" );
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        outline1("LDA %s", address_displacement(_environment, _destination, "1") );
        outline0("STA TMPPTR2+1" );
        outline1("LDA %s", _destination );
        outline0("STA TMPPTR2" );    
        outhead1("%sloop:", label );
        outline0("LDA (TMPPTR2), Y" );
        outline0("CMP (TMPPTR), Y" );
        if ( ! _equal ) {
            outline1("BEQ %sfalse", label);
        }
        outline1("BCS %strue", label);
        outline0("INY" );
        outline1("CPY #$%2.2x", _size );
        outline1("BNE %sloop", label );
        outhead1("%sfalse:", label );
        outline0("LDA #0" );
        outline1("STA %s", _result );
        outline1("JMP %sfinal", label );
        outhead1("%strue:", label );
        outline0("LDA #$FF" );
        outline1("STA %s", _result );
        outhead1("%sfinal:", label );

    no_embedded( cpu_less_than_memory_size )

}

void cpu6502_greater_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {
    
    MAKE_LABEL

    inline( cpu_greater_than_memory )

        outline0("LDY #$0" );
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        outline1("LDA %s", address_displacement(_environment, _destination, "1") );
        outline0("STA TMPPTR2+1" );
        outline1("LDA %s", _destination );
        outline0("STA TMPPTR2" );    
        outhead1("%sloop:", label );
        outline0("LDA (TMPPTR), Y" );
        outline0("CMP (TMPPTR2), Y" );
        if ( ! _equal ) {
            outline1("BEQ %sfalse", label);
        }
        outline1("BCC %sfalse", label);
        outline0("INY" );
        outline1("CPY %s", _size );
        outline1("BNE %sloop", label );
        outhead1("%strue:", label );
        outline0("LDA #$FF" );
        outline1("STA %s", _result );
        outline1("JMP %sfinal", label );
        outhead1("%sfalse:", label );
        outline0("LDA #0" );
        outline1("STA %s", _result );
        outhead1("%sfinal:", label );

    no_embedded( cpu_greater_than_memory )

}

void cpu6502_greater_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {
    
    MAKE_LABEL

    inline( cpu_greater_than_memory_size )

        outline0("LDY #$0" );
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        outline1("LDA %s", address_displacement(_environment, _destination, "1") );
        outline0("STA TMPPTR2+1" );
        outline1("LDA %s", _destination );
        outline0("STA TMPPTR2" );    
        outhead1("%sloop:", label );
        outline0("LDA (TMPPTR), Y" );
        outline0("CMP (TMPPTR2), Y" );
        if ( ! _equal ) {
            outline1("BEQ %sfalse", label);
        }
        outline1("BCC %sfalse", label);
        outline0("INY" );
        outline1("CPY #$%2.2x", _size );
        outline1("BNE %sloop", label );
        outhead1("%strue:", label );
        outline0("LDA #$FF" );
        outline1("STA %s", _result );
        outline1("JMP %sfinal", label );
        outhead1("%sfalse:", label );
        outline0("LDA #0" );
        outline1("STA %s", _result );
        outhead1("%sfinal:", label );

    no_embedded( cpu_greater_than_memory_size )

}

void cpu6502_move_8bit_indirect( Environment * _environment, char *_source, char * _value ) {

    inline( cpu_move_8bit_indirect )

        outline1("LDA %s", _value);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _value, "1"));
        outline0("STA TMPPTR+1");
        outline1("LDA %s", _source);
        outline0("LDY #$0" );
        outline0("STA (TMPPTR),Y");

    no_embedded( cpu_move_8bit_indirect )

}

void cpu6502_move_8bit_indirect_with_offset( Environment * _environment, char *_source, char * _value, int _offset ) {

    inline( cpu_move_8bit_with_offset )

        outline1("LDA %s", _value);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _value, "1"));
        outline0("STA TMPPTR+1");
        outline1("LDA %s", _source);
        outline1("LDY #$%2.2x", (_offset & 0xff ) );
        outline0("STA (TMPPTR),Y");

    no_embedded( cpu_move_8bit_with_offset )

}

void cpu6502_move_8bit_indirect_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

    inline( cpu_move_8bit_indirect_with_offset2 )

        outline1("LDA %s", _value);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _value, "1"));
        outline0("STA TMPPTR+1");
        outline1("LDA %s", _source);
        outline1("LDY %s", _offset );
        outline0("STA (TMPPTR),Y");

    no_embedded( cpu_move_8bit_indirect_with_offset2 )

}

void cpu6502_move_8bit_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

    inline( cpu_move_8bit_with_offset2 )

        outline1("LDA #<%s", _value);
        outline0("STA TMPPTR");
        outline1("LDA #>%s", _value);
        outline0("STA TMPPTR+1");
        outline1("LDA %s", _source);
        outline1("LDY %s", _offset );
        outline0("STA (TMPPTR),Y");

    no_embedded( cpu_move_8bit_with_offset2 )

}

void cpu6502_move_8bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    inline( cpu_move_8bit_indirect2 )

        outline1("LDA %s", _value);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _value, "1"));
        outline0("STA TMPPTR+1");
        outline0("LDY #$0" );
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", _source);

    no_embedded( cpu_move_8bit_with_offset2 )

}

void cpu6502_move_16bit_indirect( Environment * _environment, char *_source, char * _value ) {

    inline( cpu_move_16bit_indirect )

        outline1("LDA %s", _value);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _value, "1"));
        outline0("STA TMPPTR+1");
        outline1("LDA %s", _source);
        outline0("LDY #$0" );
        outline0("STA (TMPPTR),Y");
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline0("LDY #$1" );
        outline0("STA (TMPPTR),Y");

    no_embedded( cpu_move_16bit_indirect )

}

void cpu6502_move_16bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    inline( cpu_move_16bit_indirect2 )

        outline1("LDA %s", _value);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _value, "1"));
        outline0("STA TMPPTR+1");
        outline0("LDY #$0" );
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", _source);
        outline0("LDY #$1" );
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", address_displacement(_environment, _source, "1"));

    no_embedded( cpu_move_16bit_indirect2 )

}

void cpu6502_move_16bit_indirect2_8bit( Environment * _environment, char * _value, char * _index, char *_source ) {

    inline( cpu_move_16bit_indirect2_8bit )

        outline1("LDA #<%s", _value);
        outline0("STA TMPPTR");
        outline1("LDA #>%s", _value);
        outline0("STA TMPPTR+1");
        outline1("LDA %s", _index );
        outline0("ASL");
        outline0("TAY");
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", _source);
        outline0("INY" );
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", address_displacement(_environment, _source, "1"));

    no_embedded( cpu_move_16bit_indirect2_8bit )

}

void cpu6502_move_32bit_indirect( Environment * _environment, char *_source, char * _value ) {

    inline( cpu_move_32bit_indirect )

        outline1("LDA %s", _value);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _value, "1"));
        outline0("STA TMPPTR+1");
        outline1("LDA %s", _source);
        outline0("LDY #$0" );
        outline0("STA (TMPPTR),Y");
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline0("LDY #$1" );
        outline0("STA (TMPPTR),Y");
        outline1("LDA %s", address_displacement(_environment, _source, "2"));
        outline0("LDY #$2" );
        outline0("STA (TMPPTR),Y");
        outline1("LDA %s", address_displacement(_environment, _source, "2"));
        outline0("LDY #$3" );
        outline0("STA (TMPPTR),Y");

    no_embedded( cpu_move_32bit_indirect )

}

void cpu6502_move_32bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    inline( cpu_move_32bit_indirect2 )

        outline1("LDA %s", _value);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _value, "1"));
        outline0("STA TMPPTR+1");
        outline0("LDY #$0" );
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", _source);
        outline0("LDY #$1" );
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", address_displacement(_environment, _source, "1"));
        outline0("LDY #$2" );
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", address_displacement(_environment, _source, "2"));
        outline0("LDY #$3" );
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", address_displacement(_environment, _source, "3"));

    no_embedded( cpu_move_32bit_indirect2 )

}

void cpu6502_move_nbit_indirect( Environment * _environment, int _n, char *_source, char * _value ) {

    outline1("LDA %s", _value);
    outline0("STA TMPPTR");
    outline1("LDA %s", address_displacement(_environment, _value, "1"));
    outline0("STA TMPPTR+1");

    char step[MAX_TEMPORARY_STORAGE];
    char step1[MAX_TEMPORARY_STORAGE];
    char step2[MAX_TEMPORARY_STORAGE];
    char step3[MAX_TEMPORARY_STORAGE];

    int stepIndex = 0;
    while( _n ) {
        sprintf( step, "%d", stepIndex );
        sprintf( step1, "%d", stepIndex+1 );
        sprintf( step2, "%d", stepIndex+2 );
        sprintf( step3, "%d", stepIndex+3 );
        if ( _n >= 32 ) {
            outline1("LDA %s", address_displacement(_environment, _source, step));
            outline1("LDY #$%2.2x", stepIndex );
            outline0("STA (TMPPTR),Y");
            outline1("LDA %s", address_displacement(_environment, _source, step1));
            outline1("LDY #$%2.2x", stepIndex + 1 );
            outline0("STA (TMPPTR),Y");
            outline1("LDA %s", address_displacement(_environment, _source, step2));
            outline1("LDY #$%2.2x", stepIndex + 2 );
            outline0("STA (TMPPTR),Y");
            outline1("LDA %s", address_displacement(_environment, _source, step3));
            outline1("LDY #$%2.2x", stepIndex + 3 );
            outline0("STA (TMPPTR),Y");            
            stepIndex += 4;
            _n -= 32;
        } else {
            switch( _n ) {
                case 32: case 31: case 30: case 29:
                case 28: case 27: case 26: case 25:
                    outline1("LDA %s", address_displacement(_environment, _source, step));
                    outline1("LDY #$%2.2x", stepIndex );
                    outline0("STA (TMPPTR),Y");
                    outline1("LDA %s", address_displacement(_environment, _source, step1));
                    outline1("LDY #$%2.2x", stepIndex + 1 );
                    outline0("STA (TMPPTR),Y");
                    outline1("LDA %s", address_displacement(_environment, _source, step2));
                    outline1("LDY #$%2.2x", stepIndex + 2 );
                    outline0("STA (TMPPTR),Y");
                    outline1("LDA %s", address_displacement(_environment, _source, step3));
                    outline1("LDY #$%2.2x", stepIndex + 3 );
                    outline0("STA (TMPPTR),Y");            
                    break;
                case 24: case 23: case 22: case 21:
                case 20: case 19: case 18: case 17:
                    outline1("LDA %s", address_displacement(_environment, _source, step));
                    outline1("LDY #$%2.2x", stepIndex );
                    outline0("STA (TMPPTR),Y");
                    outline1("LDA %s", address_displacement(_environment, _source, step1));
                    outline1("LDY #$%2.2x", stepIndex + 1 );
                    outline0("STA (TMPPTR),Y");
                    outline1("LDA %s", address_displacement(_environment, _source, step2));
                    outline1("LDY #$%2.2x", stepIndex + 2 );
                    outline0("STA (TMPPTR),Y");
                    break;
                case 16: case 15: case 14: case 13:
                case 12: case 11: case 10: case 9:
                    outline1("LDA %s", address_displacement(_environment, _source, step));
                    outline1("LDY #$%2.2x", stepIndex );
                    outline0("STA (TMPPTR),Y");
                    outline1("LDA %s", address_displacement(_environment, _source, step1));
                    outline1("LDY #$%2.2x", stepIndex + 1 );
                    outline0("STA (TMPPTR),Y");
                    break;
                case 8: case 7: case 6: case 5:
                case 4: case 3: case 2: case 1:
                    outline1("LDA %s", address_displacement(_environment, _source, step));
                    outline1("LDY #$%2.2x", stepIndex );
                    outline0("STA (TMPPTR),Y");
                    break;
            }
            _n = 0;
        }
    }
}

void cpu6502_move_nbit_indirect2( Environment * _environment, int _n, char * _value, char *_source ) {
   
    outline1("LDA %s", _value);
    outline0("STA TMPPTR");
    outline1("LDA %s", address_displacement(_environment, _value, "1"));
    outline0("STA TMPPTR+1");

    char step[MAX_TEMPORARY_STORAGE];
    char step1[MAX_TEMPORARY_STORAGE];
    char step2[MAX_TEMPORARY_STORAGE];
    char step3[MAX_TEMPORARY_STORAGE];

    int stepIndex = 0;
    while( _n ) {
        sprintf( step, "%d", stepIndex );
        sprintf( step1, "%d", stepIndex+1 );
        sprintf( step2, "%d", stepIndex+2 );
        sprintf( step3, "%d", stepIndex+3 );
        if ( _n >= 32 ) {
            outline1("LDY #$%2.2x", stepIndex );
            outline0("LDA (TMPPTR),Y");
            outline1("STA %s", address_displacement(_environment, _source, step));
            outline1("LDY #$%2.2x", stepIndex + 1 );
            outline0("LDA (TMPPTR),Y");
            outline1("STA %s", address_displacement(_environment, _source, step1));
            outline1("LDY #$%2.2x", stepIndex + 2 );
            outline0("LDA (TMPPTR),Y");
            outline1("STA %s", address_displacement(_environment, _source, step2));
            outline1("LDY #$%2.2x", stepIndex + 3 );
            outline0("LDA (TMPPTR),Y");
            outline1("STA %s", address_displacement(_environment, _source, step3));
            stepIndex += 4;
            _n -= 32;
        } else {
            switch( _n ) {
                case 32: case 31: case 30: case 29:
                case 28: case 27: case 26: case 25:
                    outline1("LDY #$%2.2x", stepIndex );
                    outline0("LDA (TMPPTR),Y");
                    outline1("STA %s", address_displacement(_environment, _source, step));
                    outline1("LDY #$%2.2x", stepIndex + 1 );
                    outline0("LDA (TMPPTR),Y");
                    outline1("STA %s", address_displacement(_environment, _source, step1));
                    outline1("LDY #$%2.2x", stepIndex + 2 );
                    outline0("LDA (TMPPTR),Y");
                    outline1("STA %s", address_displacement(_environment, _source, step2));
                    outline1("LDY #$%2.2x", stepIndex + 3 );
                    outline0("LDA (TMPPTR),Y");
                    outline1("STA %s", address_displacement(_environment, _source, step3));
                    break;
                case 24: case 23: case 22: case 21:
                case 20: case 19: case 18: case 17:
                    outline1("LDY #$%2.2x", stepIndex );
                    outline0("LDA (TMPPTR),Y");
                    outline1("STA %s", address_displacement(_environment, _source, step));
                    outline1("LDY #$%2.2x", stepIndex + 1 );
                    outline0("LDA (TMPPTR),Y");
                    outline1("STA %s", address_displacement(_environment, _source, step1));
                    outline1("LDY #$%2.2x", stepIndex + 2 );
                    outline0("LDA (TMPPTR),Y");
                    outline1("STA %s", address_displacement(_environment, _source, step2));
                    break;
                case 16: case 15: case 14: case 13:
                case 12: case 11: case 10: case 9:
                    outline1("LDY #$%2.2x", stepIndex );
                    outline0("LDA (TMPPTR),Y");
                    outline1("STA %s", address_displacement(_environment, _source, step));
                    outline1("LDY #$%2.2x", stepIndex + 1 );
                    outline0("LDA (TMPPTR),Y");
                    outline1("STA %s", address_displacement(_environment, _source, step1));
                    break;
                case 8: case 7: case 6: case 5:
                case 4: case 3: case 2: case 1:
                    outline1("LDY #$%2.2x", stepIndex );
                    outline0("LDA (TMPPTR),Y");
                    outline1("STA %s", address_displacement(_environment, _source, step));
                    break;
            }
            _n = 0;
        }
    }

}


void cpu6502_move_8bit_indirect2_8bit( Environment * _environment, char * _value, char * _offset, char *_source ) {

    inline( cpu_move_8bit_indirect2_8bit )

        outline1("LDA #<%s", _value);
        outline0("STA TMPPTR");
        outline1("LDA #>%s", _value);
        outline0("STA TMPPTR+1");
        outline1("LDY %s", _offset );
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", _source);

    no_embedded( cpu_move_8bit_indirect2_8bit )

}

void cpu6502_move_8bit_indirect2_16bit( Environment * _environment, char * _value, char * _offset, char *_source ) {

    inline( cpu_move_8bit_indirect2_16bit )

        outline0("CLC");
        outline1("LDA #<%s", _value);
        outline1("ADC %s", address_displacement( _environment, _offset, "0" ) );
        outline0("STA TMPPTR");
        outline1("LDA #>%s", _value);
        outline1("ADC %s", address_displacement( _environment, _offset, "1" ) );
        outline0("STA TMPPTR+1");
        outline0("LDY #0" );
        outline0("LDA (TMPPTR),Y");
        outline1("STA %s", _source);

    no_embedded( cpu_move_8bit_indirect2_16bit )

}

void cpu6502_uppercase( Environment * _environment, char *_source, char *_size, char *_result ) {

    MAKE_LABEL

    inline( cpu_uppercase )

        outline0("LDY #$0" );
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        if ( _result ) {
            outline1("LDA %s", address_displacement(_environment, _result, "1") );
            outline0("STA TMPPTR2+1" );
            outline1("LDA %s", _result );
            outline0("STA TMPPTR2" );
        } else {
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("STA TMPPTR2+1" );
            outline1("LDA %s", _source );
            outline0("STA TMPPTR2" );
        }
        outhead1("%supper:", label );
        outline0("LDA (TMPPTR), Y" );
        
        outline0("CMP #65");
        outline1("BCC %snext", label);

        outline0("CMP #90");
        outline1("BCS %snext", label);

        outline0("CLC");
        outline0("ADC #128");

        outhead1("%snext:", label );
        outline0("STA (TMPPTR2), Y" );
        outline0("INY" );
        outline1("CPY %s", _size );
        outline1("BNE %supper", label );

    embedded( cpu_uppercase, src_hw_6502_cpu_uppercase_asm );

        outline1("LDX %s", _size );
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        if ( _result ) {
            outline1("LDA %s", address_displacement(_environment, _result, "1") );
            outline0("STA TMPPTR2+1" );
            outline1("LDA %s", _result );
            outline0("STA TMPPTR2" );
        } else {
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("STA TMPPTR2+1" );
            outline1("LDA %s", _source );
            outline0("STA TMPPTR2" );
        }
        outline0("JSR CPUUPPERCASE" );

    done()
}

void cpu6502_lowercase( Environment * _environment, char *_source, char *_size, char *_result ) {

    MAKE_LABEL

    inline( cpu_lowercase )

        outline0("LDY #$0" );
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        if ( _result ) {
            outline1("LDA %s", address_displacement(_environment, _result, "1") );
            outline0("STA TMPPTR2+1" );
            outline1("LDA %s", _result );
            outline0("STA TMPPTR2" );
        } else {
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("STA TMPPTR2+1" );
            outline1("LDA %s", _source );
            outline0("STA TMPPTR2" );
        }
        outhead1("%slower:", label );
        outline0("LDA (TMPPTR), Y" );
        
        outline0("CMP #193");
        outline1("BCC %snext", label);

        outline0("CMP #218");
        outline1("BCS %snext", label);

        outline0("SEC");
        outline0("SBC #128");

        outhead1("%snext:", label );
        outline0("STA (TMPPTR2), Y" );
        outline0("INY" );
        outline1("CPY %s", _size );
        outline1("BNE %slower", label );

    embedded( cpu_lowercase, src_hw_6502_cpu_lowercase_asm );

        outline1("LDX %s", _size );
        outline1("LDA %s", address_displacement(_environment, _source, "1") );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        if ( _result ) {
            outline1("LDA %s", address_displacement(_environment, _result, "1") );
            outline0("STA TMPPTR2+1" );
            outline1("LDA %s", _result );
            outline0("STA TMPPTR2" );
        } else {
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("STA TMPPTR2+1" );
            outline1("LDA %s", _source );
            outline0("STA TMPPTR2" );
        }
        outline0("JSR CPULOWERCASE" );

    done()

}

void cpu6502_convert_string_into_8bit( Environment * _environment, char * _string, char * _len, char * _value ) {

    MAKE_LABEL

    no_inline( cpu_convert_string_into_16bit )

    embedded( cpu_convert_string_into_16bit, src_hw_6502_cpu_convert_string_into_16bit_asm );

        outline1("LDA %s", address_displacement(_environment, _string, "1") );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _string  );
        outline0("STA TMPPTR" );
        outline1("LDX %s", _len );
        outline0("JSR CPUCONVERTSTRINGINTO16BIT" );
        outline0("LDA CPUCONVERTSTRINGINTO16BIT_VALUE" );
        outline1("STA %s", _value );

    done()

}

void cpu6502_convert_string_into_16bit( Environment * _environment, char * _string, char * _len, char * _value ) {

    MAKE_LABEL

    inline( cpu_convert_string_into_16bit )

        outline0("LDA #$0" );
        outline1("STA %s", _value );
        outline1("STA %s", address_displacement(_environment, _value, "1") );

        outline1("LDA %s", address_displacement(_environment, _string, "1") );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _string  );
        outline0("STA TMPPTR" );

        outline0("LDY #$0"); // mine

        outhead1("%srepeat:", label );

        outline0("LDA (TMPPTR),Y" );
        outline0("CMP #$39" );
        outline1("BCS %send", label);
        outline0("CMP #$30" );
        outline1("BCC %send", label);
        outline0("SBC #$30" );

        outline0("CLC");
        outline1("ADC %s", _value);
        outline1("STA %s", _value);
        outline0("LDA #$0");
        outline1("ADC %s", address_displacement(_environment, _value, "1"));
        outline1("STA %s", address_displacement(_environment, _value, "1"));

        outline1("LDA %s", address_displacement(_environment, _value, "1") );
        outline0("STA TMPPTR2+1" );
        outline1("LDA %s", _value  );
        outline0("STA TMPPTR2" );

        outline0("INY");
        outline1("CPY %s", _len );
        outline1("BEQ %send", label );

        outline0("LDA TMPPTR2" );
        outline1("STA %s", _value );
        outline0("LDA TMPPTR2+1" );
        outline1("STA %s", address_displacement(_environment, _value, "1") );
        outline1("ASL %s", _value );
        outline1("ROL %s", address_displacement(_environment, _value, "1") );
        outline1("ASL %s", _value );
        outline1("ROL %s", address_displacement(_environment, _value, "1") );
        outline0("CLC" );
        outline0("LDA TMPPTR2" );
        outline1("ADC %s", _value );
        outline1("STA %s", _value );
        outline0("LDA TMPPTR2+1" );
        outline1("ADC %s", address_displacement(_environment, _value, "1") );
        outline1("STA %s", address_displacement(_environment, _value, "1") );
        outline1("ASL %s", _value );
        outline1("ROL %s", address_displacement(_environment, _value, "1") );

        outline1("JMP %srepeat", label );

        outhead1("%send:", label );

    embedded( cpu_convert_string_into_16bit, src_hw_6502_cpu_convert_string_into_16bit_asm );

        outline1("LDA %s", address_displacement(_environment, _string, "1") );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _string  );
        outline0("STA TMPPTR" );
        outline1("LDX %s", _len );
        outline0("JSR CPUCONVERTSTRINGINTO16BIT" );
        outline0("LDA CPUCONVERTSTRINGINTO16BIT_VALUE" );
        outline1("STA %s", _value );
        outline0("LDA CPUCONVERTSTRINGINTO16BIT_VALUE+1" );
        outline1("STA %s", address_displacement(_environment, _value, "1") );

    done()
}

void cpu6502_fill_indirect( Environment * _environment, char * _address, char * _size, char * _pattern, int _size_size ) {

    MAKE_LABEL

    no_inline( cpu_fill )

    embedded( cpu_fill, src_hw_6502_cpu_fill_asm );

        outline1("LDA %s", _address);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _address, "1"));
        outline0("STA TMPPTR+1");

        if ( _size_size >= 16 ) {
            outline1("LDA %s", _size);
            outline0("STA MATHPTR0");
            outline1("LDA %s", address_displacement(_environment, _size, "1"));
            outline0("STA MATHPTR0+1");
        }

        outline1("LDA %s", _pattern);
        outline0("STA TMPPTR2");
        outline1("LDA %s", address_displacement(_environment, _pattern, "1"));
        outline0("STA TMPPTR2+1");
        outline0("LDY #0");
        outline0("LDA (TMPPTR2),Y");

        if ( _size_size >= 16 ) {
            outline0("JSR CPUFILL16");
        } else {
            outline1("LDX %s", _size);
            outline0("JSR CPUFILL8");
        }

    done()

}

void cpu6502_flip( Environment * _environment, char * _source, char * _size, char * _destination ) {

    no_inline( cpu_flip )

    embedded( cpu_flip, src_hw_6502_cpu_flip_asm );

        outline1("LDA %s", _source);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline0("STA TMPPTR+1");

        outline1("LDA %s", _destination);
        outline0("STA TMPPTR2");
        outline1("LDA %s", address_displacement(_environment, _destination, "1"));
        outline0("STA TMPPTR2+1");

        outline1("LDA %s", _size);
        outline0("JSR CPUFLIP");

    done( )

}

void cpu6502_bit_check( Environment * _environment, char * _value, int _position, char *_result, int _bitwidth ) {

    no_inline( cpu_bit_check_extended )

    embedded( cpu_bit_check_extended, src_hw_6502_cpu_bit_check_extended_asm );

        outline1("LDA #<%s", _value);
        outline0("STA TMPPTR");
        outline1("LDA #>%s", _value );
        outline0("STA TMPPTR+1");
        outline1("LDA #$%2.2x", _position );
        outline0("JSR CPUBITCHECKEXTENDED" );

        if ( _result ) {
            outline1("STA %s", _result);
        }

    done( )

}

void cpu6502_bit_check_extended( Environment * _environment, char * _value, char * _position, char *_result, int _bitwidth ) {

    MAKE_LABEL

    no_inline( cpu_bit_check_extended )

    embedded( cpu_bit_check_extended, src_hw_6502_cpu_bit_check_extended_asm );

        outline1("LDA #<%s", _value);
        outline0("STA TMPPTR");
        outline1("LDA #>%s", _value );
        outline0("STA TMPPTR+1");
        outline1("LDA %s", _position );
        outline0("JSR CPUBITCHECKEXTENDED" );

        if ( _result ) {
            outline1("STA %s", _result);
        }

    done( )

}

void cpu6502_bit_inplace_8bit( Environment * _environment, char * _value, int _position, int * _bit ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    no_inline( cpu_bit_inplace )

    embedded( cpu_bit_inplace, src_hw_6502_cpu_bit_inplace_asm );

        if ( !_bit ) {
            outline0("PHA");
        }
        outline1("LDA #<%s", _value);
        outline0("STA TMPPTR");
        outline1("LDA #>%s", _value );
        outline0("STA TMPPTR+1");
        if ( _bit ) {
            if ( *_bit ) {
                outline0("SEC");
            } else {
                outline0("CLC");
            }
        } else {
            outline0("PLA");
            outline0("ROR");
        }
        outline1("LDA #$%2.2x", _position);
        outline0("JSR CPUBITINPLACE");

    done( )

}

void cpu6502_bit_inplace_8bit_extended_indirect( Environment * _environment, char * _address, char * _position, char * _bit ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    no_inline( cpu_bit_inplace )

    embedded( cpu_bit_inplace, src_hw_6502_cpu_bit_inplace_asm );

        if ( !_bit ) {
            outline0("PHA");
        }
        outline1("LDA %s", _address);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement( _environment, _address, "1" ) );
        outline0("STA TMPPTR+1");
        if ( _bit ) {
            outline1("LDA %s", _bit);
        } else {
            outline0("PLA");
        }
        outline1("BEQ %s", label);
        outline0("SEC");
        outhead1("%s:", label);
        outline1("LDA %s", _position);
        outline0("JSR CPUBITINPLACE");

    done( )

}

void cpu6502_number_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits, int _signed ) {

    MAKE_LABEL

    deploy( numberToString, src_hw_6502_number_to_string_asm );

    outline1("LDA %s", _string );
    outline0("STA TMPPTR");
    outline1("LDA %s", address_displacement(_environment, _string, "1") );
    outline0("STA TMPPTR+1");

    outline0("LDA #0");
    outline0("STA MATHPTR3");
    outline0("STA MATHPTR2");
    outline0("STA MATHPTR1");
    outline0("STA MATHPTR0");
    outline0("STA MATHPTR4");

    switch( _bits ) {
        case 32:
            outline1("LDA %s", address_displacement(_environment, _number, "3") );
            if ( _signed ) {
                outline0("AND #$80");
                outline0("STA MATHPTR4");
                outline1("LDA %s", address_displacement(_environment, _number, "3") );
            }
            outline0("STA MATHPTR3");
            outline1("LDA %s", address_displacement(_environment, _number, "2") );
            outline0("STA MATHPTR2");
        case 16:
            outline1("LDA %s", address_displacement(_environment, _number, "1") );
            if ( _signed && _bits == 16 ) {
                outline0("AND #$80");
                outline0("STA MATHPTR4");
                outline1("LDA %s", address_displacement(_environment, _number, "1") );
            }
            outline0("STA MATHPTR1");
        case 8:
            outline1("LDA %s", _number );    
            if ( _signed && _bits == 8 ) {
                outline0("AND #$80");
                outline0("STA MATHPTR4");
                outline1("LDA %s", _number );
            }
            outline0("STA MATHPTR0");
    }

    outline0("LDA MATHPTR4");
    outline0("AND #$80" );
    outline1("BEQ %spositive", label );

    switch( _bits ) {
        case 32:
            outline0("LDA MATHPTR3" );
            outline0("EOR #$ff" );
            outline0("STA MATHPTR3" );
            outline0("LDA MATHPTR2" );
            outline0("EOR #$ff" );
            outline0("STA MATHPTR2" );
        case 16:
            outline0("LDA MATHPTR1" );
            outline0("EOR #$ff" );
            outline0("STA MATHPTR1" );
        case 8:
            outline0("LDA MATHPTR0" );
            outline0("EOR #$ff" );
            outline0("STA MATHPTR0" );
    }

    outline0("CLC" );
    outline0("LDA #$01" );
    outline0("ADC MATHPTR0" );
    outline0("STA MATHPTR0" );
    outline0("LDA #$00" );
    outline0("ADC MATHPTR1" );
    outline0("STA MATHPTR1" );
    outline0("LDA #$00" );
    outline0("ADC MATHPTR2" );
    outline0("STA MATHPTR2" );
    outline0("LDA #$00" );
    outline0("ADC MATHPTR3" );
    outline0("STA MATHPTR3" );

    outhead1("%spositive:", label );
    outline1("LDA #$%2.2X", _bits );
    outline0("STA MATHPTR5");

    outline0("JSR N2STRING");

    outline0("LDA MATHPTR5" );
    outline1("STA %s", _string_size);

}

void cpu6502_bits_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits ) {

    MAKE_LABEL

    deploy( bitsToString, src_hw_6502_bits_to_string_asm );

    outline1("LDA #<%s", _number);
    outline0("STA TMPPTR");
    outline1("LDA #>%s", _number);
    outline0("STA TMPPTR+1");
    outline1("LDA %s", _string);
    outline0("STA TMPPTR2");
    outline1("LDA %s+1", _string);
    outline0("STA TMPPTR2+1");

    outline1("LDA #$%2.2x", _bits);
    outline1("STA %s", _string_size);
    outline0("JSR BINTOSTR");

}

void cpu6502_hex_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits ) {

    MAKE_LABEL

    inline( cpu_hex_to_string )

    embedded( cpu_hex_to_string, src_hw_6502_cpu_hex_to_string_asm );

        outline1("LDX #$%2.2x", ( _bits >> 3 ) );
        outline1("LDA #<%s", _number );
        outline0("STA TMPPTR" );
        outline1("LDA #>%s", _number );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _string );
        outline0("STA TMPPTR2" );
        outline1("LDA %s", address_displacement(_environment, _string, "1") );
        outline0("STA TMPPTR2+1" );
        
        outline0("JSR H2STRING" );

        outline1("LDX #$%2.2x", ( _bits >> 2 ) );
        outline1("STX %s", _string_size );

    done()
}

void cpu6502_dsdefine( Environment * _environment, char * _string, char * _index ) {

    deploy( dstring, src_hw_6502_dstring_asm );

    outline1( "LDA #<%s", _string );
    outline0( "STA DSADDRLO" );
    outline1( "LDA #>%s", _string );
    outline0( "STA DSADDRHI" );
    outline0( "JSR DSDEFINE" );
    outline1( "STX %s", _index );
    
}

void cpu6502_dsalloc( Environment * _environment, char * _size, char * _index ) {

    deploy( dstring, src_hw_6502_dstring_asm );

    outline1( "LDA %s", _size );
    outline0( "STA DSSIZE" );
    outline0( "JSR DSALLOC" );
    outline1( "STX %s", _index );

}

void cpu6502_dsalloc_size( Environment * _environment, int _size, char * _index ) {

    deploy( dstring, src_hw_6502_dstring_asm );

    outline1( "LDA #$%2.2x", _size );
    outline0( "STA DSSIZE" );
    outline0( "JSR DSALLOC" );
    outline1( "STX %s", _index );

}

void cpu6502_dsfree( Environment * _environment, char * _index ) {

    deploy( dstring, src_hw_6502_dstring_asm );

    outline1( "LDX %s", _index );
    outline0( "JSR DSFREE" );

}

void cpu6502_dswrite( Environment * _environment, char * _index ) {

    deploy( dstring, src_hw_6502_dstring_asm );

    outline1( "LDX %s", _index );
    outline0( "JSR DSWRITE" );

}

void cpu6502_dsresize( Environment * _environment, char * _index, char * _resize ) {

    deploy( dstring, src_hw_6502_dstring_asm );

    outline1( "LDX %s", _index );
    outline1( "LDA %s", _resize );
    outline0( "STA DSSIZE" );
    outline0( "JSR DSRESIZE" );

}

void cpu6502_dsresize_size( Environment * _environment, char * _index, int _resize ) {

    deploy( dstring,src_hw_6502_dstring_asm );

    outline1( "LDX %s", _index );
    outline1( "LDA #$%2.2x", _resize );
    outline0( "STA DSSIZE" );
    outline0( "JSR DSRESIZE" );

}

void cpu6502_dsgc( Environment * _environment ) {

    deploy( dstring,src_hw_6502_dstring_asm );

    outline0( "JSR DSGC" );

}

void cpu6502_dsinit( Environment * _environment ) {

    deploy( dstring,src_hw_6502_dstring_asm );

    outline0( "JSR DSINIT" );

}

void cpu6502_dsdescriptor( Environment * _environment, char * _index, char * _address, char * _size ) {

    deploy( dstring,src_hw_6502_dstring_asm );

    if ( _address || _size ) {
        outline1( "LDX %s", _index );
        outline0( "JSR DSDESCRIPTOR" );
        if ( _address ) {
            outline0( "LDA DSADDRLO" );
            outline1( "STA %s", _address );
            outline0( "LDA DSADDRHI" );
            outline1( "STA %s", address_displacement(_environment, _address, "1") );
        }
        if ( _size ) {
            outline0( "LDA DSSIZE" );
            outline1( "STA %s", _size );
        }
    }

}

void cpu6502_store_8bit_with_offset( Environment * _environment, char *_destination, int _value, int _offset ) {

    outline1("LDY #$%2.2x", _offset);
    outline1("LDA #<%s", _destination);
    outline0("STA TMPPTR");
    outline1("LDA #>%s", _destination);
    outline0("STA TMPPTR+1");
    outline1("LDA #$%2.2x", _value);
    outline0("STA (TMPPTR),Y");

}

void cpu6502_store_8bit_with_offset2( Environment * _environment, char *_destination, char * _offset, int _value ) {

    outline1("LDY %s", _offset);
    outline1("LDA #<%s", _destination);
    outline0("STA TMPPTR");
    outline1("LDA #>%s", _destination);
    outline0("STA TMPPTR+1");
    outline1("LDA #$%2.2x", _value);
    outline0("STA (TMPPTR),Y");

}

void cpu6502_complement2_8bit( Environment * _environment, char * _source, char * _destination ) {
    outline1( "LDA %s", _source );
    outline0( "EOR #$FF" );
    if ( _destination ) {
        outline1( "STA %s", _destination );
    } else {
        outline1( "STA %s", _source );
    }
    if ( _destination ) {
        cpu6502_inc( _environment, _destination );
    } else {
        cpu6502_inc( _environment, _source );
    }
}

void cpu6502_complement2_16bit( Environment * _environment, char * _source, char * _destination ) {
    outline1( "LDA %s", _source );
    outline0( "EOR #$FF" );
    if ( _destination ) {
        outline1( "STA %s", _destination );
    } else {
        outline1( "STA %s", _source );
    }
    outline1( "LDA %s", address_displacement(_environment, _source, "1") );
    outline0( "EOR #$FF" );
    if ( _destination ) {
        outline1( "STA %s", address_displacement(_environment, _destination, "1") );
    } else {
        outline1( "STA %s", address_displacement(_environment, _source, "1") );
    }
    if ( _destination ) {
        cpu6502_inc_16bit( _environment, _destination );
    } else {
        cpu6502_inc_16bit( _environment, _source );
    }
}

void cpu6502_complement2_32bit( Environment * _environment, char * _source, char * _destination ) {
    outline1( "LDA %s", _source );
    outline0( "EOR #$FF" );
    if ( _destination ) {
        outline1( "STA %s", _destination );
    } else {
        outline1( "STA %s", _source );
    }
    outline1( "LDA %s", address_displacement(_environment, _source, "1") );
    outline0( "EOR #$FF" );
    if ( _destination ) {
        outline1( "STA %s", address_displacement(_environment, _destination, "1") );
    } else {
        outline1( "STA %s", address_displacement(_environment, _source, "1") );
    }
    outline1( "LDA %s", address_displacement(_environment, _source, "2") );
    outline0( "EOR #$FF" );
    if ( _destination ) {
        outline1( "STA %s", address_displacement(_environment, _destination, "2") );
    } else {
        outline1( "STA %s", address_displacement(_environment, _source, "2") );
    }
    outline1( "LDA %s", address_displacement(_environment, _source, "3") );
    outline0( "EOR #$FF" );
    if ( _destination ) {
        outline1( "STA %s", address_displacement(_environment, _destination, "3") );
    } else {
        outline1( "STA %s", address_displacement(_environment, _source, "3") );
    }
    if ( _destination ) {
        cpu6502_inc_32bit( _environment, _destination );
    } else {
        cpu6502_inc_32bit( _environment, _source );
    }

}

void cpu6502_sqroot( Environment * _environment, char * _number, char * _result ) {

    deploy( sqr, src_hw_6502_sqr_asm );

    outline1("LDA %s", _number );
    outline0("STA Numberl" );
    outline1("LDA %s", address_displacement(_environment, _number, "1") );
    outline0("STA Numberh" );

    outline0("JSR SQROOT" );

    outline0("LDA Root" );
    outline1("STA %s", _result );

}

void emit_segment_if_enough_space( Environment * _environment, int _space ) {
    MemoryArea * actual = _environment->memoryAreas;
    int id = 0;
    while( actual ) {
        if ( actual->size > _space ) {
            outhead1(".segment \"MA%3.3x\"", id );
            actual->size -= _space;
            break;
        }
        actual = actual->next;
        ++id;
    }
}

void cpu6502_dstring_vars( Environment * _environment ) {

    int count = _environment->dstring.count == 0 ? DSTRING_DEFAULT_COUNT : _environment->dstring.count;
    int space = _environment->dstring.space == 0 ? DSTRING_DEFAULT_SPACE : _environment->dstring.space;

    emit_segment_if_enough_space( _environment, 1 );
    outhead1("stringscount =                 %d", count );
    outhead1("stringsspace =                 %d", space );
    outhead0("MAXSTRINGS:                   .BYTE stringscount" );
    outhead0(".segment \"CODE\"" );

    emit_segment_if_enough_space( _environment, count );
    outhead0("DESCRIPTORS_STATUS:           .RES stringscount,0" );
    outhead0(".segment \"CODE\"" );

    emit_segment_if_enough_space( _environment, count );
    outhead0("DESCRIPTORS_ADDRESS_LO:       .RES stringscount,0" );
    outhead0(".segment \"CODE\"" );

    emit_segment_if_enough_space( _environment, count );
    outhead0("DESCRIPTORS_ADDRESS_HI:       .RES stringscount,0" );
    outhead0(".segment \"CODE\"" );

    emit_segment_if_enough_space( _environment, count );
    outhead0("DESCRIPTORS_SIZE:             .RES stringscount,0" );
    outhead0(".segment \"CODE\"" );

    emit_segment_if_enough_space( _environment, space );
    outhead0("WORKING:                      .RES stringsspace,0" );
    outhead0(".segment \"CODE\"" );

    emit_segment_if_enough_space( _environment, space );
    outhead0("TEMPORARY:                    .RES stringsspace,0" );
    outhead0(".segment \"CODE\"" );

    emit_segment_if_enough_space( _environment, 2 );
    outhead0("FREE_STRING:                  .WORD (stringsspace-1)" );
    outhead0(".segment \"CODE\"" );


}

void cpu6502_protothread_vars( Environment * _environment ) {

    int count = _environment->protothreadConfig.count;

    outhead1("PROTOTHREADLC:      .RES        %d,0", count );
    outhead1("PROTOTHREADST:      .RES        %d,0", count );
    outhead0("PROTOTHREADCT:      .BYTE       0" );
    outhead0("PROTOTHREADLOOP:");

    for( int i=0; i<count; ++i ) {
        outline1("LDX #%d", i );
        outline0("STX PROTOTHREADCT" );
        outline0("JSR PROTOTHREADVOID" );
    }

    outline0("RTS" );
    
}

void cpu6502_protothread_loop( Environment * _environment ) {

    deploy_with_vars( protothread, src_hw_6502_protothread_asm, cpu_protothread_vars );

    outline0("JSR PROTOTHREADLOOP" );

}

void cpu6502_protothread_register_at( Environment * _environment, char * _index, char * _label ) {

    deploy_with_vars( protothread, src_hw_6502_protothread_asm, cpu_protothread_vars );

    outline1("LDA #<%s", _label );
    outline0("STA TMPPTR" );
    outline1("LDA #>%s", _label );
    outline0("STA TMPPTR+1" );
    outline1("LDY %s", _index );

    outline0("JSR PROTOTHREADREGAT" );

}

void cpu6502_protothread_register( Environment * _environment, char * _label, char * _index ) {

    deploy_with_vars( protothread, src_hw_6502_protothread_asm, cpu_protothread_vars );

    outline1("LDA #<%s", _label );
    outline0("STA TMPPTR" );
    outline1("LDA #>%s", _label );
    outline0("STA TMPPTR+1" );

    outline0("JSR PROTOTHREADREG" );

    outline1("STY %s", _index );

}

void cpu6502_protothread_unregister( Environment * _environment, char * _index ) {

    deploy_with_vars( protothread, src_hw_6502_protothread_asm, cpu_protothread_vars );

    outline1("LDY %s", _index );

    outline0("JSR PROTOTHREADUNREG" );

}

void cpu6502_protothread_save( Environment * _environment, char * _index, int _step ) {

    deploy_with_vars( protothread, src_hw_6502_protothread_asm, cpu_protothread_vars );

    outline1("LDY %s", _index );
    outline1("LDX #$%2.2x", _step );

    outline0("JSR PROTOTHREADSAVE" );

}

void cpu6502_protothread_restore( Environment * _environment, char * _index, char * _step ) {

    deploy_with_vars( protothread, src_hw_6502_protothread_asm, cpu_protothread_vars );

    outline1("LDY %s", _index );

    outline0("JSR PROTOTHREADRESTORE" );

    outline1("STX %s", _step );
    
}

void cpu6502_protothread_set_state( Environment * _environment, char * _index, int _state ) {

    deploy_with_vars( protothread, src_hw_6502_protothread_asm, cpu_protothread_vars );

    outline1("LDY %s", _index );
    outline1("LDX #$%2.2x", _state );

    outline0("JSR PROTOTHREADSETSTATE" );

}

void cpu6502_protothread_get_state( Environment * _environment, char * _index, char * _state ) {

    deploy_with_vars( protothread, src_hw_6502_protothread_asm, cpu_protothread_vars );

    outline1("LDY %s", _index );

    outline0("JSR PROTOTHREADGETSTATE" );

    outline1("STX %s", _state );

}

void cpu6502_protothread_current( Environment * _environment, char * _current ) {

    deploy_with_vars( protothread, src_hw_6502_protothread_asm, cpu_protothread_vars );

    outline0("LDX PROTOTHREADCT" );
    outline1("STX %s", _current );

}

void cpu6502_protothread_get_address( Environment * _environment, char * _index, char * _address ) {

    deploy_with_vars( protothread, src_hw_6502_protothread_asm, cpu_protothread_vars );

    outline1("LDY %s", _index );

    outline0("JSR PROTOTHREADGETADDRESS" );

    outline0("LDA TMPPTR" );
    outline1("STA %s", _address );
    outline0("LDA TMPPTR+1" );
    outline1("STA %s", address_displacement( _environment, _address, "1" ) );

}

void cpu6502_set_callback( Environment * _environment, char * _callback, char * _label ) {

        outline1("LDA #<(%s)", address_displacement(_environment, _callback, "1"));
        outline0("STA TMPPTR");
        outline1("LDA #>(%s)", address_displacement(_environment, _callback, "1"));
        outline0("STA TMPPTR+1");
        outline0("LDY #0");
        outline1("LDA #<%s", _label);
        outline0("STA (TMPPTR), Y");
        outline0("INY");
        outline1("LDA #>%s", _label);
        outline0("STA (TMPPTR), Y");

}

void cpu6502_msc1_uncompress_direct_direct( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_6502_msc1_asm );

        outline1("LDA #<%s", _input);
        outline0("STA TMPPTR");
        outline1("LDA #>%s", _input);
        outline0("STA TMPPTR+1");
        outline1("LDA #<%s", _output);
        outline0("STA TMPPTR2");
        outline1("LDA #>%s", _output);
        outline0("STA TMPPTR2+1");

        outline0("JSR MSC1UNCOMPRESS");

    done()

}

void cpu6502_msc1_uncompress_direct_indirect( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_6502_msc1_asm );

        outline1("LDA #<%s", _input);
        outline0("STA TMPPTR");
        outline1("LDA #>%s", _input);
        outline0("STA TMPPTR+1");
        outline1("LDA %s", _output);
        outline0("STA TMPPTR2");
        outline1("LDA %s", address_displacement(_environment, _output, "1"));
        outline0("STA TMPPTR2+1");

        outline0("JSR MSC1UNCOMPRESS");

    done()

}

void cpu6502_msc1_uncompress_indirect_direct( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_6502_msc1_asm );

        outline1("LDA %s", _input);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _input, "1"));
        outline0("STA TMPPTR+1");
        outline1("LDA #<%s", _output);
        outline0("STA TMPPTR2");
        outline1("LDA #>%s", _output);
        outline0("STA TMPPTR2+1");

        outline0("JSR MSC1UNCOMPRESS");

    done()

}

void cpu6502_msc1_uncompress_indirect_indirect( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_6502_msc1_asm );

        outline1("LDA %s", _input);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _input, "1"));
        outline0("STA TMPPTR+1");
        outline1("LDA %s", _output);
        outline0("STA TMPPTR2");
        outline1("LDA %s", address_displacement(_environment, _output, "1"));
        outline0("STA TMPPTR2+1");

        outline0("JSR MSC1UNCOMPRESS");

    done()

}

void cpu6502_out( Environment * _environment, char * _port, char * _value ) {

}

void cpu6502_in( Environment * _environment, char * _port, char * _value ) {
    
}

void cpu6502_out_direct( Environment * _environment, char * _port, char * _value ) {

}

void cpu6502_in_direct( Environment * _environment, char * _port, char * _value ) {
    
}

void cpu6502_string_sub( Environment * _environment, char * _source, char * _source_size, char * _pattern, char * _pattern_size, char * _destination, char * _destination_size ) {
    
    MAKE_LABEL

    inline( cpu_string_sub )

    embedded( cpu_string_sub, src_hw_6502_cpu_string_sub_asm );

        outline1("LDA %s", _source);
        outline0("STA TMPPTR");
        outline1("LDA %s", address_displacement(_environment, _source, "1"));
        outline0("STA TMPPTR+1");
        outline1("LDA %s", _source_size);
        outline0("STA MATHPTR0");
        outline1("LDA %s", _pattern);
        outline0("STA TMPPTR2");
        outline1("LDA %s", address_displacement(_environment, _pattern, "1"));
        outline0("STA TMPPTR2+1");
        outline1("LDA %s", _pattern_size);
        outline0("STA MATHPTR1");
        outline1("LDA %s", _destination);
        outline0("STA MATHPTR4");
        outline1("LDA %s", address_displacement(_environment, _destination, "1"));
        outline0("STA MATHPTR4+1");

        outline0("JSR CPUSTRINGSUB");

        outline0("LDA MATHPTR2");
        outline1("STA %s", _destination_size);

    done()
}

static char CPU6502_BLIT_REGISTER[][9] = {
    "BLITR0",
    "BLITR1",
    "BLITR2",
    "BLITR3"
};

#define CPU6502_BLIT_REGISTER_COUNT ( sizeof( CPU6502_BLIT_REGISTER ) / 9 )

void cpu6502_blit_initialize( Environment * _environment ) {

    _environment->blit.freeRegisters = 0;
    _environment->blit.usedMemory = 0;

}

void cpu6502_blit_finalize( Environment * _environment ) {

    _environment->blit.freeRegisters = 0;
    _environment->blit.usedMemory = 0;

}

char * cpu6502_blit_register_name(  Environment * _environment, int _register ) {
    
    if ( _register < CPU6502_BLIT_REGISTER_COUNT ) {
        return &CPU6502_BLIT_REGISTER[_register][0];
    } else {
        return &CPU6502_BLIT_REGISTER[ (_register & 0xff00) >> 8][0];
    }
}

int cpu6502_blit_alloc_register(  Environment * _environment ) {

    int reg = 0;

    for( reg = 0; reg < CPU6502_BLIT_REGISTER_COUNT; ++reg ) {
        int registerMask = ( 0x01 << reg );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( ! isRegisterUsed ) {
            _environment->blit.freeRegisters |= registerMask;
            // printf( "cpu6502_blit_alloc_register() %4.4x -> $%4.4x\n", _environment->blit.freeRegisters, reg );
            return reg;
        }
    }

    int location = _environment->blit.usedMemory++;

    if ( location > 0xff ) {
        CRITICAL_BLIT_ALLOC_MEMORY_EXHAUSTED( );
    }

    for( reg = 0; reg < CPU6502_BLIT_REGISTER_COUNT; ++reg ) {
        int registerMask = ( 0x10 << reg );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( ! isRegisterUsed ) {
            outline1( "LDA %s", &CPU6502_BLIT_REGISTER[reg][0] );
            outline2( "STA %sbs+$%2.2x",  _environment->blit.realName, location );
            _environment->blit.freeRegisters |= registerMask;
            // printf( "cpu6502_blit_alloc_register() -> %4.4x $%4.4x\n", _environment->blit.freeRegisters, ( ( reg << 8 ) | location ) );
            return ( ( (reg+1) << 8 ) | location );
        }
    }

    CRITICAL_BLIT_ALLOC_REGISTER_EXHAUSTED( );

}

void cpu6502_blit_free_register(  Environment * _environment, int _register ) {

    // printf( "cpu6502_blit_free_register($%4.4x)\n", _register );

    int location = _register & 0xff;
    int reg;

    if ( _register < CPU6502_BLIT_REGISTER_COUNT ) {
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
            outline2( "LDA (%sbs+$%2.2x)",  _environment->blit.realName, location );
            outline1( "LDA %s", &CPU6502_BLIT_REGISTER[reg][0] );
            _environment->blit.freeRegisters &= ~registerMask;
            return;
        }
    }

    CRITICAL_BLIT_INVALID_FREE_REGISTER( _environment->blit.name, _register );

}

/**
 * @brief <i>CPU 6502</i>: emit code to store n bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _n bits to store (>32)
 * @param _value[] Value to store (segmented in 32 bit each)
 */
void cpu6502_store_nbit( Environment * _environment, char *_destination, int _n, int _value[] ) {

    int i = 0;
    while( _n ) {
        char destinationAddress[MAX_TEMPORARY_STORAGE]; sprintf( destinationAddress, "%s+%d", _destination, i*4 );
        if ( _n <= 32 ) {
            switch( _n ) {
                case 1: case 2: case 3: case 4:
                case 5: case 6: case 7: case 8:
                    cpu6502_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff>>(8-_n)) ) );
                    break;
                case 9: case 10: case 11: case 12:
                case 13: case 14: case 15: case 16:
                    cpu6502_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu6502_store_8bit( _environment, destinationAddress, ( _value[i+1] & (0xff>>(16-_n)) ) );
                    break;
                case 17: case 18: case 19: case 20:
                case 21: case 22: case 23: case 24:
                    cpu6502_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu6502_store_8bit( _environment, destinationAddress, ( _value[i+1] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    cpu6502_store_8bit( _environment, destinationAddress, ( _value[i+2] & (0xff>>(24-_n)) ) );
                    break;
                case 25: case 26: case 27: case 28:
                case 29: case 30: case 31: case 32:
                default:
                    cpu6502_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu6502_store_8bit( _environment, destinationAddress, ( _value[i+1] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    cpu6502_store_8bit( _environment, destinationAddress, ( _value[i+2] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
                    cpu6502_store_8bit( _environment, destinationAddress, ( _value[i+3] & (0xff>>(32-_n)) ) );
                    break;
            }
            _n = 0;
        } else {
            cpu6502_store_8bit( _environment, destinationAddress, ( _value[i] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
            cpu6502_store_8bit( _environment, destinationAddress, ( _value[i+1] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
            cpu6502_store_8bit( _environment, destinationAddress, ( _value[i+2] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
            cpu6502_store_8bit( _environment, destinationAddress, ( _value[i+3] & (0xff>>(32-_n)) ) );
            _n -= 32;
        }
        ++i;
    }


}

//
//                  [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]      [8]      [9]
// SINGLE	(32)  	seeeeeee emmmmmmm mmmmmmmm mmmmmmmm
//

void cpu6502_float_fast_from_double_to_int_array( Environment * _environment, double _value, int _result[] ) {
    cpu6502_float_single_from_double_to_int_array( _environment, _value, _result );
}

// const double sonda = 1.0;

void cpu6502_float_single_from_double_to_int_array( Environment * _environment, double _value, int _result[] ) {
    
    double value = 0.0;
    double integral = 0.0;
    double fractional = 0.0;
    int sign = 0;
    int left = 0;
    int right[3];
    int steps = 0;
    int exp = 0;
    int mantissa_bits = 23;
    int mantissaScaled = 0;

    // printf("------------------\nVALUE = %f\n", _value );

    memset( &_result[0], 0, sizeof( int ) * 4 );
    memset( &right[0], 0, sizeof( int ) * 3 );

    if ( _value != 0.0 ) {

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

        // if ( _value == sonda ) {
        //     printf("============================\n" );
        //     printf("value = %f, left = %d, integral = %f, fractional = %f\n", value, left, integral, fractional );
        // }

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

        if ( fractional != 0.0 ) {

            if ( fractional != 1.0 ) {
                exp = -1;
            } else {
                exp = -2;
            }
        
            // mantissaScaled = 1;

            // if ( _value == sonda ) {
            //     printf("%d-) exp = %d right = %2.2x %2.2x %2.2x fractional = %f\n", steps, exp, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2], fractional );
            // }

            // fractional = fractional * 2;

            // if ( fractional > 1.0 ) {
                // fractional = modf(fractional, &integral);
                // printf("%d!) exp = %d right = %2.2x %2.2x %2.2x fractional = %f\n", steps, exp, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2], fractional );
                // ++steps;
            // } else {
            //     fractional = fractional / 2;
            // }

            while( ( fractional != 1.0 ) && ( steps < mantissa_bits ) ) {

                fractional = fractional * 2;

                if ( fractional != 1.0 ) {

                    if ( fractional > 1.0 ) {
                        right[2] |= 1;
                        fractional = modf(fractional, &integral);
                    }

                    ++steps;

                    // if ( _value == sonda ) {
                    //     printf("%d) exp = %d right = %2.2x %2.2x %2.2x fractional = %f\n", steps, exp, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2], fractional );
                    // }

                    // if (  ( fractional != 1.0 ) && ( steps < mantissa_bits )  ) {

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
                        right[0] = right[0] & 0xff;

                    // }

                }

            }

            // if ( _value == sonda ) {
            //     printf("%d*) exp = %d right = %2.2x %2.2x %2.2x fractional = %f\n", steps, exp, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2], fractional );
            // }

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

            if ( value != 0 && !mantissaScaled ) {

                while( left == 0 ) {

                    // if ( _value == sonda ) {
                    //     printf("a) exp = %d left = %2.2x right = %2.2x %2.2x %2.2x fractional = %f\n", exp, (unsigned char) left, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2], fractional );
                    // }

                    if ( ! right[0] && ! right[1] && ! right[2] ) {
                        left = 0x1;
                    }

                    if ( right[0] & 0x80 ) {
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
                    right[0] = right[0] & 0xff;
                    right[1] = right[1] & 0xff;
                    right[2] = right[2] & 0xff;

                    --exp;
                }

            } else {

                //            exp = -1;

            }

            // if ( _value == sonda ) {
            //     printf("ax) exp = %d left = %2.2x right = %2.2x %2.2x %2.2x\n", exp, (unsigned char) left, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2] );
            // }

            while( left ) {

                // if ( _value == sonda ) {
                //     printf("ay) left = %8.8x right = %2.2x %2.2x %2.2x\n", left, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2] );
                // }

                if ( ( right[0] & 0x01 ) ) {
                    right[1] = right[1] | 0x100;
                }
                if ( ( right[1] & 0x01 ) ) {
                    right[2] = right[2] | 0x100;
                }
                right[0] = right[0] >> 1;
                right[1] = right[1] >> 1;
                right[2] = right[2] >> 1;

                // IEEE-754
                // if ( ( left & 0x1 ) && left != 1 ) {
                if ( ( left & 0x1 ) ) {
                    right[0] = right[0] | 0x80;
                }
                left = left >> 1;

                if( left ) {
                    exp = exp + 1;
                }

            }

            // IEEE-754
            // ++exp;

        } else {

            if ( left > 1 ) {
                while( left > 1 ) {

                    // if ( _value == sonda ) {
                    //     printf("bx) exp = %d left = %8.8x right = %2.2x %2.2x %2.2x\n", exp, left, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2] );
                    // }

                    if ( ( right[0] & 0x01 ) ) {
                        right[1] = right[1] | 0x100;
                    }
                    if ( ( right[1] & 0x01 ) ) {
                        right[2] = right[2] | 0x100;
                    }
                    right[0] = right[0] >> 1;
                    right[1] = right[1] >> 1;
                    right[2] = right[2] >> 1;
                    if ( ( left & 0x1 ) ) {
                        right[0] = right[0] | 0x80;
                    }
                    left = left >> 1;
                    ++exp;
                }

                // ++exp;

            }

            if ( !sign ) {
                --exp;
            }

            if ( integral == 1.0 && !sign ) {
                --exp;
            }

            // if ( _value == sonda ) {
            //     printf("bx*) exp = %d left = %8.8x right = %2.2x %2.2x %2.2x\n", exp, left, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2] );
            // }
        
        }

        // Step 5: Add Bias to the Exponent
        // Internally, IEEE-754 values store their exponents in an unsigned representation, which may seem odd considering that 
        // the exponent can be negative. Negative exponents are accomodated by using a biased representation, wherein a 
        // pre-set number is always subtracted from the given unsigned number. Because the given unsigned number may be less 
        // than this number, this allows for negative values to be effectively encoded without resorting to two's complement. 
        // Specifically, for the binary32 representation, the number 127 will be subtracted from anything encoded in the 
        // exponent field of the IEEE-754 number. As such, in this step, we need to add 127 to the normalized exponent value 
        // from the previous step.

        // IEEE-754
        // exp += 127;
        exp += 129;

        // if ( _value == sonda ) {
        //     printf("exp = %2.2x\n", exp );
        // }

        // Step 6: Convert the Biased Exponent to Unsigned Binary
        // The biased exponent value from the previous step must be converted into unsigned binary, using the usual process.
        // The result must be exactly 8 bits. It should not be possible to need more than 8 bits. If fewer than 8 bits are 
        // needed in this conversion process, then leading zeros must be added to the front of the result to produce an 
        // 8-bit value.

        exp = exp & 0xff;

        // if ( _value == sonda ) {
        //     printf("exp = %d\n", exp );
        // }

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

        // IEEE-754 format
        // _result[0] = ( sign << 7 ) | ( exp >> 1 );
        // _result[1] = ( ( exp & 0x01 ) << 7 ) | ( right[0] >> 1 );
        // _result[2] = ( ( right[0] & 0x01 ) << 7 ) | ( right[1] >> 1 );
        // _result[3] = ( ( right[1] & 0x01 ) << 7 ) | ( right[2] >> 1 );

        // WOZNIAK format
        _result[0] = exp;
        _result[1] = ( ( sign & 0x01 ) << 7 ) | ( right[0] >> 1 );
        _result[2] = ( ( right[0] & 0x01 ) << 7 ) | ( right[1] >> 1 );
        _result[3] = ( ( right[1] & 0x01 ) << 7 ) | ( right[2] >> 1 );

    }

    // if ( _value == sonda ) {
    //     printf( "--------------> %f %2.2x %2.2x %2.2x %2.2x\n\n", _value, _result[0], _result[1], _result[2], _result[3] );
    // }
    
}
void cpu6502_float_fast_from_int_array_to_double( Environment * _environment, int _value[], double * _result ) {
    cpu6502_float_single_from_int_array_to_double( _environment,  _value, _result );
}

void cpu6502_float_single_from_int_array_to_double( Environment * _environment, int _value[], double * _result ) {
    
    // printf( "  value = %2.2x%2.2x%2.2x%2.2x\n", _value[0], _value[1], _value[2], _value[3] );

    // IEEE-754
    // int sign = ( ( _value[0] & 0x80 ) ? -1 : 1 );
    int sign = ( ( _value[1] & 0x80 ) ? -1 : 1 );

    // IEEE-754
    // int exp = ( ( _value[0] << 1 ) & 0xff ) | ( ( _value[1] & 0x80 ) ? 0x01 : 0x00 );
    // exp = exp - 127;
    int exp = _value[0] & 0xff;
    exp = exp - 128;

    // printf( "  exp      = %d\n", exp );

    int mantissa = ( (( _value[1] & 0x7f ) << 16) | (_value[2] << 8 ) | _value[3] ) << 1;

    // printf( "  mantissa = %6.6x\n", mantissa );

    // IEEE-754
    // *_result = 0 * sign;
    if ( mantissa == 0 ) {
        *_result = 2.0 * sign;
    } else {
        *_result = 1.0 * sign;
    }

    double step = 0.5;

    for( int i=0; i<24; ++i ) {
        // printf( "  %i) %f ->", i, *_result );
        // IEEE-754
        // if ( mantissa & 0x800000 ) {
        if ( mantissa & 0x400000 ) {
            *_result += (sign * step);
        }
        // printf( "  %f\n", *_result );
        step = step / 2;
        mantissa = mantissa & 0x3fffff;
        mantissa = mantissa << 1;
    }

    if ( exp > 0 ) {

        for( int i=0; i<exp; ++i ) {
            // printf( "  x %i) %f ->", i, *_result );
            *_result = *_result * 2;
            // printf( " %f\n", *_result );
        }

    } else if ( exp < 0 ) {

        exp = -exp;

        for( int i=0; i<exp; ++i ) {
            // printf( "  x %i) %f ->", i, *_result );
            *_result = *_result / 2;
            // printf( " %f\n", *_result );
        }

    }
    
}

void cpu6502_float_fast_to_string( Environment * _environment, char * _x, char * _string, char * _string_size ) {
    cpu6502_float_single_to_string( _environment, _x, _string, _string_size );
}

void cpu6502_float_single_to_string( Environment * _environment, char * _x, char * _string, char * _string_size ) {

    MAKE_LABEL

    deploy( fp_vars, src_hw_6502_fp_routines_asm );

    outline1( "LDA %s", address_displacement( _environment, _x, "0" ) );
    outline0( "STA X1" );
    outline1( "LDA %s", address_displacement( _environment, _x, "1" ) );
    outline0( "STA M1" );
    outline1( "LDA %s", address_displacement( _environment, _x, "2" ) );
    outline0( "STA M1+1" );
    outline1( "LDA %s", address_displacement( _environment, _x, "3" ) );
    outline0( "STA M1+2" );

    outline1( "LDA %s", address_displacement( _environment, _string, "0" ) );
    outline0( "STA TMPPTR" );
    outline1( "LDA %s", address_displacement( _environment, _string, "1" ) );
    outline0( "STA TMPPTR+1" );
    outline0( "LDA #$0" );
    outline0( "STA TMPPTR2" );

    outline0( "JSR BEGIN" );

    outline0( "LDA TMPPTR2" );
    outline1( "STA %s", _string_size );
    
    // outline0( "JSR FIX" );

    // Variable * number = variable_temporary( _environment, VT_WORD, "(number) ");
    // outline0( "LDA M1" );
    // outline1( "STA %s", address_displacement( _environment, number->realName, "1") );
    // outline0( "LDA M1+1" );
    // outline1( "STA %s", address_displacement( _environment, number->realName, "0") );

    // cpu6502_number_to_string( _environment, number->realName, _string, _string_size, 16, 1 );

}

void cpu6502_float_fast_from_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    cpu6502_float_single_from_8( _environment, _value, _result, _signed );
}

void cpu6502_float_single_from_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    MAKE_LABEL

    deploy( fp_vars, src_hw_6502_fp_routines_asm );

    if ( _signed ) {
        outline1( "LDA %s", address_displacement( _environment, _value, "0" ) );
        outline0( "AND #$80" );
        outline1( "BEQ %s", label );
        outline0( "LDA #$ff" );
        outline1( "JMP %sdone", label );
        outhead1( "%s:", label );
        outline0( "LDA #$0" );
        outline1( "JMP %sdone", label );
        outhead1( "%sdone:", label );
    } else {
        outline0( "LDA #$0" );
    }
    outline0( "STA M1" );
    outline1( "LDA %s", address_displacement( _environment, _value, "0" ) );
    outline0( "STA M1+1" );
    outline0( "JSR FLOAT");
    outline0( "LDA X1" );
    outline1( "STA %s", address_displacement( _environment, _result, "0" ) );
    outline0( "LDA M1" );
    outline1( "STA %s", address_displacement( _environment, _result, "1" ) );
    outline0( "LDA M1+1" );
    outline1( "STA %s", address_displacement( _environment, _result, "2" ) );
    outline0( "LDA M1+2" );
    outline1( "STA %s", address_displacement( _environment, _result, "3" ) );

}

void cpu6502_float_fast_from_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    cpu6502_float_single_from_16( _environment, _value, _result, _signed );
}

void cpu6502_float_single_from_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    deploy( fp_vars, src_hw_6502_fp_routines_asm );

    outline1( "LDA %s", address_displacement( _environment, _value, "1" ) );
    outline0( "STA M1" );
    outline1( "LDA %s", address_displacement( _environment, _value, "0" ) );
    outline0( "STA M1+1" );
    outline0( "JSR FLOAT");
    outline0( "LDA X1" );
    outline1( "STA %s", address_displacement( _environment, _result, "0" ) );
    outline0( "LDA M1" );
    outline1( "STA %s", address_displacement( _environment, _result, "1" ) );
    outline0( "LDA M1+1" );
    outline1( "STA %s", address_displacement( _environment, _result, "2" ) );
    outline0( "LDA M1+2" );
    outline1( "STA %s", address_displacement( _environment, _result, "3" ) );

}

void cpu6502_float_fast_to_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    cpu6502_float_single_to_8( _environment, _value, _result, _signed );
}

void cpu6502_float_single_to_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    (int)_signed;

    deploy( fp_vars, src_hw_6502_fp_routines_asm );

    outline1( "LDA %s", address_displacement( _environment, _value, "0" ) );
    outline0( "STA X1" );
    outline1( "LDA %s", address_displacement( _environment, _value, "1" ) );
    outline0( "STA M1" );
    outline1( "LDA %s", address_displacement( _environment, _value, "2" ) );
    outline0( "STA M1+1" );
    outline1( "LDA %s", address_displacement( _environment, _value, "3" ) );
    outline0( "STA M1+2" );
    outline0( "JSR FIX" );
    outline0( "LDA M1+1" );
    outline1( "STA %s", _result );

}

void cpu6502_float_fast_to_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    cpu6502_float_single_to_16( _environment, _value, _result, _signed );
}

void cpu6502_float_single_to_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    (int)_signed;

    deploy( fp_vars, src_hw_6502_fp_routines_asm );

    outline1( "LDA %s", address_displacement( _environment, _value, "0" ) );
    outline0( "STA X1" );
    outline1( "LDA %s", address_displacement( _environment, _value, "1" ) );
    outline0( "STA M1" );
    outline1( "LDA %s", address_displacement( _environment, _value, "2" ) );
    outline0( "STA M1+1" );
    outline1( "LDA %s", address_displacement( _environment, _value, "3" ) );
    outline0( "STA M1+2" );
    outline0( "JSR FIX" );
    outline0( "LDA M1" );
    outline1( "STA %s", address_displacement( _environment, _result, "1" ) );
    outline0( "LDA M1+1" );
    outline1( "STA %s", address_displacement( _environment, _result, "0" ) );

}

void cpu6502_float_fast_sub( Environment * _environment, char * _x, char * _y, char * _result ) {
    cpu6502_float_single_sub( _environment, _x, _y, _result );
}

void cpu6502_float_single_sub( Environment * _environment, char * _x, char * _y, char * _result ) {
    
    deploy( fp_vars, src_hw_6502_fp_routines_asm );

    outline1( "LDA %s", address_displacement( _environment, _y, "0" ) );
    outline0( "STA X1" );
    outline1( "LDA %s", address_displacement( _environment, _y, "1" ) );
    outline0( "STA M1" );
    outline1( "LDA %s", address_displacement( _environment, _y, "2" ) );
    outline0( "STA M1+1" );
    outline1( "LDA %s", address_displacement( _environment, _y, "3" ) );
    outline0( "STA M1+2" );

    outline1( "LDA %s", address_displacement( _environment, _x, "0" ) );
    outline0( "STA X2" );
    outline1( "LDA %s", address_displacement( _environment, _x, "1" ) );
    outline0( "STA M2" );
    outline1( "LDA %s", address_displacement( _environment, _x, "2" ) );
    outline0( "STA M2+1" );
    outline1( "LDA %s", address_displacement( _environment, _x, "3" ) );
    outline0( "STA M2+2" );

    outline0( "JSR FSUB");

    outline0( "LDA X1" );
    outline1( "STA %s", address_displacement( _environment, _result, "0" ) );
    outline0( "LDA M1" );
    outline1( "STA %s", address_displacement( _environment, _result, "1" ) );
    outline0( "LDA M1+1" );
    outline1( "STA %s", address_displacement( _environment, _result, "2" ) );
    outline0( "LDA M1+2" );
    outline1( "STA %s", address_displacement( _environment, _result, "3" ) );

}

void cpu6502_float_fast_add( Environment * _environment, char * _x, char * _y, char * _result ) {
    cpu6502_float_single_add( _environment, _x, _y, _result );
}

void cpu6502_float_single_add( Environment * _environment, char * _x, char * _y, char * _result ) {
    
    deploy( fp_vars, src_hw_6502_fp_routines_asm );

    outline1( "LDA %s", address_displacement( _environment, _x, "0" ) );
    outline0( "STA X1" );
    outline1( "LDA %s", address_displacement( _environment, _x, "1" ) );
    outline0( "STA M1" );
    outline1( "LDA %s", address_displacement( _environment, _x, "2" ) );
    outline0( "STA M1+1" );
    outline1( "LDA %s", address_displacement( _environment, _x, "3" ) );
    outline0( "STA M1+2" );

    outline1( "LDA %s", address_displacement( _environment, _y, "0" ) );
    outline0( "STA X2" );
    outline1( "LDA %s", address_displacement( _environment, _y, "1" ) );
    outline0( "STA M2" );
    outline1( "LDA %s", address_displacement( _environment, _y, "2" ) );
    outline0( "STA M2+1" );
    outline1( "LDA %s", address_displacement( _environment, _y, "3" ) );
    outline0( "STA M2+2" );

    outline0( "JSR FADD");

    outline0( "LDA X1" );
    outline1( "STA %s", address_displacement( _environment, _result, "0" ) );
    outline0( "LDA M1" );
    outline1( "STA %s", address_displacement( _environment, _result, "1" ) );
    outline0( "LDA M1+1" );
    outline1( "STA %s", address_displacement( _environment, _result, "2" ) );
    outline0( "LDA M1+2" );
    outline1( "STA %s", address_displacement( _environment, _result, "3" ) );

}

void cpu6502_float_fast_cmp( Environment * _environment, char * _x, char * _y, char * _result ) {
    cpu6502_float_single_cmp( _environment, _x, _y, _result );
}

void cpu6502_float_single_cmp( Environment * _environment, char * _x, char * _y, char * _result ) {
    
    MAKE_LABEL

    deploy( fp_vars, src_hw_6502_fp_routines_asm );

    outline1( "LDA %s", address_displacement( _environment, _x, "0" ) );
    outline0( "STA X1" );
    outline1( "LDA %s", address_displacement( _environment, _x, "1" ) );
    outline0( "STA M1" );
    outline1( "LDA %s", address_displacement( _environment, _x, "2" ) );
    outline0( "STA M1+1" );
    outline1( "LDA %s", address_displacement( _environment, _x, "3" ) );
    outline0( "STA M1+2" );

    outline1( "LDA %s", address_displacement( _environment, _y, "0" ) );
    outline0( "STA X2" );
    outline1( "LDA %s", address_displacement( _environment, _y, "1" ) );
    outline0( "STA M2" );
    outline1( "LDA %s", address_displacement( _environment, _y, "2" ) );
    outline0( "STA M2+1" );
    outline1( "LDA %s", address_displacement( _environment, _y, "3" ) );
    outline0( "STA M2+2" );

    outline0( "JSR FCMP");

    outline1( "STA %s", _result );

}

void cpu6502_float_fast_mul( Environment * _environment, char * _x, char * _y, char * _result ) {
    cpu6502_float_single_mul( _environment, _x, _y, _result );
}

void cpu6502_float_single_mul( Environment * _environment, char * _x, char * _y, char * _result ) {
    
    MAKE_LABEL
    
    deploy( fp_vars, src_hw_6502_fp_routines_asm );

    outline1( "LDA %s", address_displacement( _environment, _x, "0" ) );
    outline0( "STA X1" );
    outline1( "LDA %s", address_displacement( _environment, _x, "1" ) );
    outline0( "STA M1" );
    outline1( "LDA %s", address_displacement( _environment, _x, "2" ) );
    outline0( "STA M1+1" );
    outline1( "LDA %s", address_displacement( _environment, _x, "3" ) );
    outline0( "STA M1+2" );

    outline1( "LDA %s", address_displacement( _environment, _y, "0" ) );
    outline0( "STA X2" );
    outline1( "LDA %s", address_displacement( _environment, _y, "1" ) );
    outline0( "STA M2" );
    outline1( "LDA %s", address_displacement( _environment, _y, "2" ) );
    outline0( "STA M2+1" );
    outline1( "LDA %s", address_displacement( _environment, _y, "3" ) );
    outline0( "STA M2+2" );

    outline0( "JSR FMUL");

    outline0( "LDA X1" );
    outline1( "STA %s", address_displacement( _environment, _result, "0" ) );
    outline0( "LDA M1" );
    outline1( "STA %s", address_displacement( _environment, _result, "1" ) );
    outline0( "LDA M1+1" );
    outline1( "STA %s", address_displacement( _environment, _result, "2" ) );
    outline0( "LDA M1+2" );
    outline1( "STA %s", address_displacement( _environment, _result, "3" ) );

}

void cpu6502_float_fast_div( Environment * _environment, char * _x, char * _y, char * _result ) {
    cpu6502_float_single_div( _environment, _x, _y, _result );
}

void cpu6502_float_single_div( Environment * _environment, char * _x, char * _y, char * _result ) {
    
    MAKE_LABEL
    
    deploy( fp_vars, src_hw_6502_fp_routines_asm );

    outline1( "LDA %s", address_displacement( _environment, _y, "0" ) );
    outline0( "STA X1" );
    outline1( "LDA %s", address_displacement( _environment, _y, "1" ) );
    outline0( "STA M1" );
    outline1( "LDA %s", address_displacement( _environment, _y, "2" ) );
    outline0( "STA M1+1" );
    outline1( "LDA %s", address_displacement( _environment, _y, "3" ) );
    outline0( "STA M1+2" );

    outline1( "LDA %s", address_displacement( _environment, _x, "0" ) );
    outline0( "STA X2" );
    outline1( "LDA %s", address_displacement( _environment, _x, "1" ) );
    outline0( "STA M2" );
    outline1( "LDA %s", address_displacement( _environment, _x, "2" ) );
    outline0( "STA M2+1" );
    outline1( "LDA %s", address_displacement( _environment, _x, "3" ) );
    outline0( "STA M2+2" );

    outline0( "JSR FDIV");

    outline0( "LDA X1" );
    outline1( "STA %s", address_displacement( _environment, _result, "0" ) );
    outline0( "LDA M1" );
    outline1( "STA %s", address_displacement( _environment, _result, "1" ) );
    outline0( "LDA M1+1" );
    outline1( "STA %s", address_displacement( _environment, _result, "2" ) );
    outline0( "LDA M1+2" );
    outline1( "STA %s", address_displacement( _environment, _result, "3" ) );

}

void cpu6502_float_fast_sin( Environment * _environment, char * _angle, char * _result ) {
    cpu6502_float_single_sin( _environment, _angle, _result );
}

void cpu6502_float_single_sin( Environment * _environment, char * _angle, char * _result ) {
    
    MAKE_LABEL
    
    deploy( fp_vars, src_hw_6502_fp_routines_asm );

    outline1( "LDA %s", address_displacement( _environment, _angle, "0" ) );
    outline0( "STA X1" );
    outline1( "LDA %s", address_displacement( _environment, _angle, "1" ) );
    outline0( "STA M1" );
    outline1( "LDA %s", address_displacement( _environment, _angle, "2" ) );
    outline0( "STA M1+1" );
    outline1( "LDA %s", address_displacement( _environment, _angle, "3" ) );
    outline0( "STA M1+2" );

    outline0( "JSR FSIN");

    outline0( "LDA X1" );
    outline1( "STA %s", address_displacement( _environment, _result, "0" ) );
    outline0( "LDA M1" );
    outline1( "STA %s", address_displacement( _environment, _result, "1" ) );
    outline0( "LDA M1+1" );
    outline1( "STA %s", address_displacement( _environment, _result, "2" ) );
    outline0( "LDA M1+2" );
    outline1( "STA %s", address_displacement( _environment, _result, "3" ) );

}

void cpu6502_float_fast_log( Environment * _environment, char * _value, char * _result ) {
    cpu6502_float_single_log( _environment, _value, _result );
}

void cpu6502_float_single_log( Environment * _environment, char * _value, char * _result ) {
    
    MAKE_LABEL
    
    deploy( fp_vars, src_hw_6502_fp_routines_asm );

    outline1( "LDA %s", address_displacement( _environment, _value, "0" ) );
    outline0( "STA X1" );
    outline1( "LDA %s", address_displacement( _environment, _value, "1" ) );
    outline0( "STA M1" );
    outline1( "LDA %s", address_displacement( _environment, _value, "2" ) );
    outline0( "STA M1+1" );
    outline1( "LDA %s", address_displacement( _environment, _value, "3" ) );
    outline0( "STA M1+2" );

    outline0( "JSR FPLOG");

    outline0( "LDA X1" );
    outline1( "STA %s", address_displacement( _environment, _result, "0" ) );
    outline0( "LDA M1" );
    outline1( "STA %s", address_displacement( _environment, _result, "1" ) );
    outline0( "LDA M1+1" );
    outline1( "STA %s", address_displacement( _environment, _result, "2" ) );
    outline0( "LDA M1+2" );
    outline1( "STA %s", address_displacement( _environment, _result, "3" ) );

}

void cpu6502_float_fast_exp( Environment * _environment, char * _value, char * _result ) {
    cpu6502_float_single_exp( _environment, _value, _result );
}

void cpu6502_float_single_exp( Environment * _environment, char * _value, char * _result ) {
    
    MAKE_LABEL
    
    deploy( fp_vars, src_hw_6502_fp_routines_asm );

    outline1( "LDA %s", address_displacement( _environment, _value, "0" ) );
    outline0( "STA X1" );
    outline1( "LDA %s", address_displacement( _environment, _value, "1" ) );
    outline0( "STA M1" );
    outline1( "LDA %s", address_displacement( _environment, _value, "2" ) );
    outline0( "STA M1+1" );
    outline1( "LDA %s", address_displacement( _environment, _value, "3" ) );
    outline0( "STA M1+2" );

    outline0( "JSR FPEXP");

    outline0( "LDA X1" );
    outline1( "STA %s", address_displacement( _environment, _result, "0" ) );
    outline0( "LDA M1" );
    outline1( "STA %s", address_displacement( _environment, _result, "1" ) );
    outline0( "LDA M1+1" );
    outline1( "STA %s", address_displacement( _environment, _result, "2" ) );
    outline0( "LDA M1+2" );
    outline1( "STA %s", address_displacement( _environment, _result, "3" ) );

}

void cpu6502_float_fast_cos( Environment * _environment, char * _angle, char * _result ) {
    cpu6502_float_single_cos( _environment, _angle, _result );
}

void cpu6502_float_single_cos( Environment * _environment, char * _angle, char * _result ) {
    
    MAKE_LABEL
    
    deploy( fp_vars, src_hw_6502_fp_routines_asm );

    outline1( "LDA %s", address_displacement( _environment, _angle, "0" ) );
    outline0( "STA X1" );
    outline1( "LDA %s", address_displacement( _environment, _angle, "1" ) );
    outline0( "STA M1" );
    outline1( "LDA %s", address_displacement( _environment, _angle, "2" ) );
    outline0( "STA M1+1" );
    outline1( "LDA %s", address_displacement( _environment, _angle, "3" ) );
    outline0( "STA M1+2" );

    outline0( "JSR FCOS");

    outline0( "LDA X1" );
    outline1( "STA %s", address_displacement( _environment, _result, "0" ) );
    outline0( "LDA M1" );
    outline1( "STA %s", address_displacement( _environment, _result, "1" ) );
    outline0( "LDA M1+1" );
    outline1( "STA %s", address_displacement( _environment, _result, "2" ) );
    outline0( "LDA M1+2" );
    outline1( "STA %s", address_displacement( _environment, _result, "3" ) );

}

void cpu6502_float_fast_tan( Environment * _environment, char * _angle, char * _result ) {
    cpu6502_float_single_tan( _environment, _angle, _result );
}

void cpu6502_float_single_tan( Environment * _environment, char * _angle, char * _result ) {
    
    MAKE_LABEL
    
    deploy( fp_vars, src_hw_6502_fp_routines_asm );

    outline1( "LDA %s", address_displacement( _environment, _angle, "0" ) );
    outline0( "STA X1" );
    outline1( "LDA %s", address_displacement( _environment, _angle, "1" ) );
    outline0( "STA M1" );
    outline1( "LDA %s", address_displacement( _environment, _angle, "2" ) );
    outline0( "STA M1+1" );
    outline1( "LDA %s", address_displacement( _environment, _angle, "3" ) );
    outline0( "STA M1+2" );

    outline0( "JSR FTAN");

    outline0( "LDA X1" );
    outline1( "STA %s", address_displacement( _environment, _result, "0" ) );
    outline0( "LDA M1" );
    outline1( "STA %s", address_displacement( _environment, _result, "1" ) );
    outline0( "LDA M1+1" );
    outline1( "STA %s", address_displacement( _environment, _result, "2" ) );
    outline0( "LDA M1+2" );
    outline1( "STA %s", address_displacement( _environment, _result, "3" ) );

}

void cpu6502_address_table_build( Environment * _environment, char * _table, int * _values, char *_address[], int _count ) {

    outhead1("%s:", _table );
    for( int i=0; i<_count; ++i ) {
        outline2(".word $%4.4x, %s", _values[i], _address[i] );
    }

}

void cpu6502_address_table_lookup( Environment * _environment, char * _table, int _count ) {

    outhead1("LOOKFOR%s:", _table );
    if ( _count ) {
        outline1("LDA #<%s", _table );
        outline0("STA MATHPTR2" );
        outline1("LDA #>%s", _table );
        outline0("STA MATHPTR2+1" );
        outline0("LDY #0" );
        outhead1("LOOKFOR%sL1:", _table );
        outline0("LDA (MATHPTR2), Y" );
        outline0("CMP MATHPTR0" );
        outline1("BNE LOOKFOR%sNEXT3", _table );
        outline0("INY" );
        outline0("LDA (MATHPTR2), Y" );
        outline0("CMP MATHPTR1" );
        outline1("BNE LOOKFOR%sNEXT2", _table );
        outline0("INY" );
        outline0("LDA (MATHPTR2), Y" );
        outline0("STA MATHPTR0" );
        outline0("INY" );
        outline0("LDA (MATHPTR2), Y" );
        outline0("STA MATHPTR1" );
        outline0("RTS" );
        outhead1("LOOKFOR%sNEXT3:", _table );
        outline0("INY" );
        outhead1("LOOKFOR%sNEXT2:", _table );
        outline0("INY" );
        outline0("INY" );
        outline1("CPY #$%2.2x", (_count+1) * 4 );
        outline1("BNE LOOKFOR%sL1", _table );
    }
    outline0("RTS" );

}

void cpu6502_address_table_call( Environment * _environment, char * _table, char * _value, char * _address ) {

    outline1("LDA %s", _value );
    outline0("STA MATHPTR0" );
    outline1("LDA %s", address_displacement( _environment, _value, "1" ) );
    outline0("STA MATHPTR1" );
    outline1("JSR LOOKFOR%s", _table );
    outline0("LDA MATHPTR0" );
    outline1("STA %s", _address );
    outline0("LDA MATHPTR1" );
    outline1("STA %s", address_displacement( _environment, _address, "1" ) );

}

void cpu6502_move_8bit_signed_16bit_signed( Environment * _environment, char *_source, char *_destination ) {

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );
    outline0("LDA #$7F" );
    outline1("CMP %s", _destination );
    outline0("SBC #$7F" );
    outline1("STA %s", address_displacement( _environment, _destination, "1" ) );

}

void cpu6502_move_8bit_signed_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );
    outline0("LDA #$7F" );
    outline1("CMP %s", _destination );
    outline0("SBC #$7F" );
    outline1("STA %s", address_displacement( _environment, _destination, "1" ) );

}

void cpu6502_move_8bit_unsigned_16bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );
    outline0("LDA #0" );
    outline1("STA %s", address_displacement( _environment, _destination, "1" ) );

}

void cpu6502_move_8bit_unsigned_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );
    outline0("LDA #0" );
    outline1("STA %s", address_displacement( _environment, _destination, "1" ) );

}

void cpu6502_move_8bit_signed_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );
    outline0("LDA #$7F" );
    outline1("CMP %s", _destination );
    outline0("SBC #$7F" );
    outline1("STA %s", address_displacement( _environment, _destination, "1" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "2" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "3" ) );

}

void cpu6502_move_8bit_signed_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );
    outline0("LDA #$7F" );
    outline1("CMP %s", _destination );
    outline0("SBC #$7F" );
    outline1("STA %s", address_displacement( _environment, _destination, "1" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "2" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "3" ) );

}

void cpu6502_move_8bit_unsigned_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );
    outline0("LDA #0" );
    outline1("STA %s", address_displacement( _environment, _destination, "1" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "2" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "3" ) );

}
void cpu6502_move_8bit_unsigned_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){
    
    outline1("LDA %s", _source );
    outline1("STA %s", _destination );
    outline0("LDA #0" );
    outline1("STA %s", address_displacement( _environment, _destination, "1" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "2" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "3" ) );

}

void cpu6502_move_16bit_signed_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );

}
void cpu6502_move_16bit_signed_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );

}
void cpu6502_move_16bit_unsigned_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );

}
void cpu6502_move_16bit_unsigned_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );

}

void cpu6502_move_16bit_signed_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );
    outline1("LDA %s", address_displacement( _environment, _source, "1" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "1" ) );
    outline0("LDA #$7F" );
    outline1("CMP %s", address_displacement( _environment, _destination, "1" ) );
    outline0("SBC #$7F" );
    outline1("STA %s", address_displacement( _environment, _destination, "2" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "3" ) );

}

void cpu6502_move_16bit_signed_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){


    outline1("LDA %s", _source );
    outline1("STA %s", _destination );
    outline1("LDA %s", address_displacement( _environment, _source, "1" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "1" ) );
    outline0("LDA #$7F" );
    outline1("CMP %s", address_displacement( _environment, _destination, "1" ) );
    outline0("SBC #$7F" );
    outline1("STA %s", address_displacement( _environment, _destination, "2" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "3" ) );

}

void cpu6502_move_16bit_unsigned_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );
    outline1("LDA %s", address_displacement( _environment, _source, "1" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "1" ) );
    outline0("LDA #0" );
    outline1("STA %s", address_displacement( _environment, _destination, "2" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "3" ) );

}
void cpu6502_move_16bit_unsigned_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );
    outline1("LDA %s", address_displacement( _environment, _source, "1" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "1" ) );
    outline0("LDA #0" );
    outline1("STA %s", address_displacement( _environment, _destination, "2" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "3" ) );

}

void cpu6502_move_32bit_signed_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );
    outline0("LDA #0" );
    outline1("STA %s", address_displacement( _environment, _destination, "1" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "2" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "3" ) );

}
void cpu6502_move_32bit_signed_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );

}
void cpu6502_move_32bit_unsigned_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );

}
void cpu6502_move_32bit_unsigned_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );

}

void cpu6502_move_32bit_signed_16bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );
    outline1("LDA %s", address_displacement( _environment, _source, "1" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "1" ) );

}

void cpu6502_move_32bit_signed_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );
    outline1("LDA %s", address_displacement( _environment, _source, "1" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "1" ) );

}

void cpu6502_move_32bit_unsigned_16bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("LDA %s", _source );
    outline1("STA %s", _destination );
    outline1("LDA %s", address_displacement( _environment, _source, "1" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "1" ) );

}

void cpu6502_move_32bit_unsigned_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){
    
    outline1("LDA %s", _source );
    outline1("STA %s", _destination );
    outline1("LDA %s", address_displacement( _environment, _source, "1" ) );
    outline1("STA %s", address_displacement( _environment, _destination, "1" ) );
   
}

#endif