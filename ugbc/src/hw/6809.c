/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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
#include <time.h>
#include <math.h>

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#if defined(__d32__) || defined(__d64__) || defined(__pc128op__) || defined(__mo5__) || defined(__coco__)

/* output code that is the best "JUMP" version between "small" and "long" branch.
   LBRA and LBSR are transformed into JMP and JSR respectively. */
#define B(code, label)                                                       \
do { /* x-y+128<0 or 127-x+y<0 */                                            \
    outline2("IF (((128+%s-(*+2))|(127-%s+(*+2)))&0x8000)",(label),(label)); \
    if(!strcmp(#code,"RA")) {                                                \
        outline1("JMP %s", (label));                                         \
    } else if(!strcmp(#code,"SR")) {                                         \
        outline1("JSR %s", (label));                                         \
    } else {                                                                 \
        outline2("LB%s %s", #code, (label));                                 \
    }                                                                        \
    outline0("ELSE");                                                        \
    outline2("B%s %s", #code, (label));                                      \
    outline0("ENDIF");                                                       \
} while(0)

/* Helper for 8/16 bits comparison */
static void cpu6809_compare( Environment * _environment, char *_source, char *_destination,  char *_other, int _positive, int _bits) {
    char REG = _bits==16 ? 'X' : 'A';

    MAKE_LABEL

    outline0("CLRB");
    outline2("LD%c %s",  REG, _source);
    outline2("CMP%c %s", REG, _destination);

    if(_positive) {
        outline1("BNE %s", label);
        outline0("DECB");
    } else {
        outline1("BEQ %s", label);
        outline0("DECB");
    }

    outhead1("%s", label );
    outline1("STB %s", _other ? _other : _destination );
}
static void cpu6809_less_than( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed, int _bits) {
    char REG = _bits==16 ? 'X' : 'A';

    MAKE_LABEL

    outline0("CLRB");
    outline2("LD%c %s",  REG, _source);
    outline2("CMP%c %s", REG, _destination);

    if ( _signed ) {
        if ( _equal ) {
            outline1("BGT %s", label);
        } else {
            outline1("BGE %s", label);
        }
    } else {
        if ( _equal ) {
            outline1("BHI %s", label);
        } else {
            outline1("BHS %s", label);
        }
    }

    outline0("DECB");
    outhead1("%s", label );
    outline1("STB %s", _other ? _other : _destination);
}

static void cpu6809_less_than_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed, int _bits) {
    char REG = _bits==16 ? 'X' : 'A';

    MAKE_LABEL

    outline0("CLRB");
    outline2("LD%c %s",  REG, _source);
    outline2("CMP%c #$%4.4x", REG, _destination);

    if ( _signed ) {
        if ( _equal ) {
            outline1("BGT %s", label);
        } else {
            outline1("BGE %s", label);
        }
    } else {
        if ( _equal ) {
            outline1("BHI %s", label);
        } else {
            outline1("BHS %s", label);
        }
    }

    outline0("DECB");
    outhead1("%s", label );
    outline1("STB %s", _other );
}

static void cpu6809_greater_than( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed, int _bits ) {
    char REG = _bits==16 ? 'X' : 'A';

    MAKE_LABEL

    outline0("CLRB");
    outline2("LD%c %s",  REG, _source);
    outline2("CMP%c %s", REG, _destination);
    if ( _signed ) {
        if ( _equal ) {
            outline1("BLT %s", label);
        } else {
            outline1("BLE %s", label);
        }
    } else {
        if ( _equal ) {
            outline1("BLO %s", label);
        } else {
            outline1("BLS %s", label);
        }
    }

    outline0("DECB");
    outhead1("%s", label );
    outline1("STB %s", _other ? _other : _destination );
}

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

    inline( cpu_beq )

        B(EQ, _label);

    no_embedded( cpu_beq )

}

/**
 * @brief <i>CPU 6809</i>: emit code to make long conditional jump
 *
 * @param _environment Current calling environment
 * @param _label Destination of the conditional jump.
 */
void cpu6809_bneq( Environment * _environment, char * _label ) {

    inline( cpu_bneq )

        B(NE, _label);

    no_embedded( cpu_bneq )

}

void cpu6809_bveq( Environment * _environment, char * _value, char * _label ) {

    inline( cpu_bveq )

        outline1("LDB %s", _value);
        B(EQ, _label);

    no_embedded( cpu_bveq )

}

void cpu6809_bvneq( Environment * _environment, char * _value, char * _label ) {

    inline( cpu_bveq )

        outline1("LDB %s", _value);
        B(NE, _label);

    no_embedded( cpu_bvneq )

}

void cpu6809_label( Environment * _environment, char * _label ) {

    inline( cpu_label )

        outhead1("%s", _label);

    no_embedded( cpu_label )

}

void cpu6809_peek( Environment * _environment, char * _address, char * _target ) {

    inline( cpu_peek )

        outline1("LDB [%s]", _address);
        outline1("STB %s", _target);

    no_embedded( cpu_peek )

}

void cpu6809_poke( Environment * _environment, char * _address, char * _source ) {

    inline( cpu_poke )

        outline1("LDB %s", _source );
        outline1("STB [%s]", _address);

    no_embedded( cpu_poke )

}

/**
 * @brief <i>CPU 6809</i>: emit code to fill up a memory area
 *
 * This function can be used to output a piece of code that fills a given
 * memory area with a given <PATTERN (<PATTERN size: 1 byte). The starting
 * address must be contained in a variable, while the area must be a multiple
 * of 256 bytes.
 *
 * @param _environment Current calling environment
 * @param _address Starting address
 * @param _blocks Number of 256 bytes blocks to fill
 * @param _<PATTERN <PATTERN to use
 */
void cpu6809_fill_blocks( Environment * _environment, char * _address, char * _blocks, char * _pattern ) {

    inline( cpu_fill_blocks )

        MAKE_LABEL

        outline1("LDY %s", _blocks);
        outline0("TFR Y,D");
        outline0("LEAY D,Y");
        outline1("LDA %s", _pattern );
        outline1("LDX %s", _address);
        outhead1("%s", label);
        outline0("LDB #$7f");
        outhead1("%sinner", label);
        outline0("STA B,X");
        outline0("DECB");
        outline0("CMPB #$ff");
        outline1("BNE %sinner", label);
        outline0("LEAX 127,X");
        outline0("LEAX 1,X");
        outline0("LEAY -1,Y");
        outline0("CMPY #$0");
        outline1("BNE %s", label);

    embedded( cpu_fill_blocks, src_hw_6809_cpu_fill_blocks_asm );

        outline1("LDY %s", _blocks);
        outline0("TFR Y,D");
        outline0("LEAY D,Y");
        outline1("LDA %s", _pattern );
        outline1("LDX %s", _address);
        outline0("JSR CPUFILLBLOCKS");

    done(  )

}

/**
 * @brief <i>CPU 6809</i>: emit code to fill up a memory area
 *
 * This function can be used to output a piece of code that fills a given
 * memory area with a given <PATTERN (<PATTERN size: 1 byte). The starting
 * address must be contained in a variable, while the area must be a multiple
 * of 256 bytes.
 *
 * @param _environment Current calling environment
 * @param _address Starting address
 * @param _bytes Number of bytes to fill
 * @param _<PATTERN <PATTERN to use
 */
void cpu6809_fill( Environment * _environment, char * _address, char * _bytes, char * _pattern ) {

    inline( cpu_fill )

        MAKE_LABEL

        outline1("LDB %s", _bytes);
        outline0("LDA #0");
        outline0("LEAY D,Y");
        outline1("LDA %s", _pattern );
        outline1("LDX %s", _address);
        outhead1("%s", label);
        outhead1("%sinner", label);
        outline0("DECB");
        outline0("STA B,X");
        outline0("CMPB #$ff");
        outline1("BNE %sinner", label);

    embedded( cpu_fill, src_hw_6809_cpu_fill_asm );

        outline1("LDB %s", _bytes);
        outline0("LDA #0");
        outline0("LEAY D,Y");
        outline1("LDA %s", _pattern );
        outline1("LDX %s", _address);
        outline0("JSR CPUFILL");

    done( )

}

/**
 * @brief <i>CPU 6809</i>: emit code to fill up a memory area
 *
 * This function can be used to output a piece of code that fills a given
 * memory area with a given <PATTERN (<PATTERN size: 1 byte). The starting
 * address must be contained in a variable, while the area must be a multiple
 * of 256 bytes.
 *
 * @param _environment Current calling environment
 * @param _address Starting address
 * @param _bytes Number of bytes to fill
 * @param _<PATTERN <PATTERN to use
 */
void cpu6809_fill_size( Environment * _environment, char * _address, int _bytes, char * _pattern ) {

    inline( cpu_fill )

        MAKE_LABEL

        outline1("LDB #$%2.2x", _bytes);
        outline0("LDA #0");
        outline0("LEAY D,Y");
        outline1("LDA %s", _pattern );
        outline1("LDX %s", _address);
        outhead1("%s", label);
        outhead1("%sinner", label);
        outline0("DECB");
        outline0("STA B,X");
        outline0("CMPB #$ff");
        outline1("BNE %sinner", label);

    embedded( cpu_fill, src_hw_6809_cpu_fill_asm );

        outline1("LDB #$%2.2x", _bytes);
        outline0("LDA #0");
        outline0("LEAY D,Y");
        outline1("LDA %s", _pattern );
        outline1("LDX %s", _address);
        outline0("JSR CPUFILL");

    done( )

}

/**
 * @brief <i>CPU 6809</i>: emit code to fill up a memory area
 *
 * This function can be used to output a piece of code that fills a given
 * memory area with a given <PATTERN (<PATTERN size: 1 byte). The starting
 * address must be contained in a variable, while the area must be a multiple
 * of 256 bytes.
 *
 * @param _environment Current calling environment
 * @param _address Starting address
 * @param _bytes Number of bytes to fill
 * @param _<PATTERN <PATTERN to use
 */
void cpu6809_fill_size_value( Environment * _environment, char * _address, int _bytes, int _pattern ) {

    inline( cpu_fill )

        MAKE_LABEL

        outline1("LDB #$%2.2x", _bytes);
        outline0("LDA #0");
        outline0("LEAY D,Y");
        outline1("LDA #$%2.2x", _pattern );
        outline1("LDX %s", _address);
        outhead1("%s", label);
        outhead1("%sinner", label);
        outline0("DECB");
        outline0("STA B,X");
        outline0("CMPB #$ff");
        outline1("BNE %sinner", label);

    embedded( cpu_fill, src_hw_6809_cpu_fill_asm );

        outline1("LDB #$%2.2x", _bytes);
        outline0("LDA #0");
        outline0("LEAY D,Y");
        outline1("LDA #$%2.2x", _pattern );
        outline1("LDX %s", _address);
        outline0("JSR CPUFILL");

    done( )

}

/**
 * @brief <i>CPU 6809</i>: emit code to fill up a memory area
 *
 * This function can be used to output a piece of code that fills a given
 * memory area with a given <PATTERN (<PATTERN size: 1 byte). The starting
 * address must be contained in a variable, while the area must be a multiple
 * of 256 bytes.
 *
 * @param _environment Current calling environment
 * @param _address Starting address
 * @param _bytes Number of bytes to fill
 * @param _<PATTERN <PATTERN to use
 */
void cpu6809_fill_direct( Environment * _environment, char * _address, char * _bytes, char * _pattern ) {

    inline( cpu_fill )

        MAKE_LABEL

        outline1("LDB %s", _bytes);
        outline0("LDA #0");
        outline0("LEAY D,Y");
        outline1("LDA %s", _pattern );
        outline1("LDX #%s", _address);
        outhead1("%s", label);
        outhead1("%sinner", label);
        outline0("DECB");
        outline0("STA B,X");
        outline0("CMPB #$ff");
        outline1("BNE %sinner", label);

    embedded( cpu_fill, src_hw_6809_cpu_fill_asm );

        outline1("LDB %s", _bytes);
        outline0("LDA #0");
        outline0("LEAY D,Y");
        outline1("LDA %s", _pattern );
        outline1("LDX #%s", _address);
        outline0("JSR CPUFILL");

    done( )

}

/**
 * @brief <i>CPU 6809</i>: emit code to fill up a memory area
 *
 * This function can be used to output a piece of code that fills a given
 * memory area with a given <PATTERN (<PATTERN size: 1 byte). The starting
 * address must be contained in a variable, while the area must be a multiple
 * of 256 bytes.
 *
 * @param _environment Current calling environment
 * @param _address Starting address
 * @param _bytes Number of bytes to fill
 * @param _<PATTERN <PATTERN to use
 */
void cpu6809_fill_direct_size( Environment * _environment, char * _address, int _bytes, char * _pattern ) {

    inline( cpu_fill )

        MAKE_LABEL

        outline1("LDB #$%2.2x", _bytes);
        outline0("LDA #0");
        outline0("LEAY D,Y");
        outline1("LDA %s", _pattern );
        outline1("LDX #%s", _address);
        outhead1("%s", label);
        outhead1("%sinner", label);
        outline0("DECB");
        outline0("STA B,X");
        outline0("CMPB #$ff");
        outline1("BNE %sinner", label);

    embedded( cpu_fill, src_hw_6809_cpu_fill_asm );

        outline1("LDB #$%2.2x", _bytes);
        outline0("LDA #0");
        outline0("LEAY D,Y");
        outline1("LDA %s", _pattern );
        outline1("LDX #%s", _address);
        outline0("JSR CPUFILL");

    done( )

}

/**
 * @brief <i>CPU 6809</i>: emit code to fill up a memory area
 *
 * This function can be used to output a piece of code that fills a given
 * memory area with a given <PATTERN (<PATTERN size: 1 byte). The starting
 * address must be contained in a variable, while the area must be a multiple
 * of 256 bytes.
 *
 * @param _environment Current calling environment
 * @param _address Starting address
 * @param _bytes Number of bytes to fill
 * @param _<PATTERN <PATTERN to use
 */
void cpu6809_fill_direct_size_value( Environment * _environment, char * _address, int _bytes, int _pattern ) {

    inline( cpu_fill )

        MAKE_LABEL

        outline1("LDB #$%2.2x", _bytes);
        outline0("LDA #0");
        outline0("LEAY D,Y");
        outline1("LDA #$%2.2x", _pattern );
        outline1("LDX #%s", _address);
        outhead1("%s", label);
        outhead1("%sinner", label);
        outline0("DECB");
        outline0("STA B,X");
        outline0("CMPB #$ff");
        outline1("BNE %sinner", label);

    embedded( cpu_fill, src_hw_6809_cpu_fill_asm );

        outline1("LDB #$%2.2x", _bytes);
        outline0("LDA #0");
        outline0("LEAY D,Y");
        outline1("LDA #$%2.2x", _pattern );
        outline1("LDX #%s", _address);
        outline0("JSR CPUFILL");

    done( )

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

    inline( cpu_move_8bit )

        outline1("LDB %s", _source);
        outline1("STB %s", _destination);

    no_embedded( cpu_move_8bit )

}

/**
 * @brief <i>CPU 6809</i>: emit code to store 8 bit
 *
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void cpu6809_store_8bit( Environment * _environment, char *_destination, int _value ) {

    inline( cpu_store_8bit )

    if(_value) {
        outline1("LDB #$%2.2x" , _value );
        outline1("STB %s", _destination );
    } else {
        // make A=0 as much as possible
        outline0("CLRA");
        outline1("STA %s", _destination );
    }
        
    no_embedded( cpu_move_8bit )

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

    inline( cpu_compare_8bit )

        cpu6809_compare(_environment,_source, _destination, _other, _positive, 8);

    no_embedded( cpu_compare_8bit )

}

/**
 * @brief <i>CPU 6809</i>: emit code to compare two 8 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void cpu6809_compare_and_branch_8bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

    inline( cpu_compare_and_branch_8bit_const )

        outline1("LDB %s", _source);
        outline1("CMPB #$%2.2x", _destination);
        if ( _positive ) {
            B(EQ, _label);
        } else {
            B(NE, _label);
        }

    no_embedded( cpu_compare_and_branch_8bit_const )

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

    inline( cpu_less_than_8bit )

        cpu6809_less_than(_environment, _source, _destination, _other, _equal, _signed, 8);

    no_embedded( cpu_less_than_8bit )

}

void cpu6809_less_than_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    inline( cpu_less_than_8bit_const )

        cpu6809_less_than_const(_environment, _source, _destination, _other, _equal, _signed, 8);

    no_embedded( cpu_less_than_8bit_const )

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

    inline( cpu_greater_than_8bit )

        cpu6809_greater_than(_environment, _source, _destination, _other, _equal, _signed, 8);

    no_embedded( cpu_greater_than_8bit )

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

    inline( cpu_math_add_8bit )

        outline1("LDB %s", _source);
        outline1("ADDB %s", _destination);
        outline1("STB %s", _other ? _other : _destination);

    no_embedded( cpu_math_add_8bit )

}

void cpu6809_math_add_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

    inline( cpu_math_add_8bit )

        outline1("LDB %s", _source);
        outline1("ADDB #$%2.2x", ( _destination & 0xff ) );
        outline1("STB %s", _other );

    no_embedded( cpu_math_add_8bit )

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

    inline( cpu_math_sub_8bit )

        outline1("LDB %s", _source);
        outline1("SUBB %s", _destination);
        outline1("STB %s", _other ? _other : _destination);

    no_embedded( cpu_math_sub_8bit )

}

/**
 * @brief <i>CPU 6809</i>: emit code to double a 8 bit value
 *
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6809_math_double_8bit( Environment * _environment, char *_source, char *_other, int _signed ) {

    inline( cpu_math_sub_8bit )

        outline1("LDB %s", _source);
        outline0("ASLB");
        outline1("STB %s", _other ? _other : _source);

    no_embedded( cpu_math_sub_8bit )

}

/**
 * @brief <i>CPU 6809</i>: emit code to halves for several times a 8 bit value
 *
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6809_math_div2_8bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    inline( cpu_math_div2_8bit )

        MAKE_LABEL

        if ( _signed ) {
            outline0("LDA #0");
            outline0("STA <MATHPTR0");
            outline1("LDA %s", _source);
            outline0("AND #$80");
            outline1("BEQ %spos", label);
            outline0("LDA #1");
            outline0("STA <MATHPTR0");
            outline0("EORA #$FF");
            outline0("ADDA #1");
            outhead1("%spos", label);
        } else {
            outline1("LDA %s", _source);
        }
        outline1("LDB #$%2.2x", _steps);
        outline0("CMPB #0");
        outline1("BEQ %sdone", label);
        outhead1("%sloop", label);
        outline0("ASRA");
        outline0("DECB");
        outline0("CMPB #0");
        outline1("BNE %sloop", label);
        outhead1("%sdone", label);
        if ( _signed ) {
            outline0("PSHS A");
            outline0("LDA <MATHPTR0");
            outline1("BEQ %spos2", label);
            outline0("PULS A");
            outline0("EORA #$FF");
            outline0("ADDA #1");
            outhead1("%spos2", label);
        }
        outline1("STA %s", _source);

    embedded( cpu_math_div2_8bit, src_hw_6809_cpu_math_div2_8bit_asm );

        outline1("LDB %s", _source);
        outline1("LDA #$%2.2x", _steps);
        if ( _signed ) {
            outline0("JSR CPUMATHDIV28BIT_SIGNED");
        } else {
            outline0("JSR CPUMATHDIV28BIT");
        }
        outline1("STB %s", _source);

    done( )

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

    inline( cpu_math_mul_8bit_to_16bit )

        MAKE_LABEL

        if ( _signed ) {

            outline0("LDA #0" );
            outline0("STA <MATHPTR0" );
            outline1("LDA %s", _source );
            outline1("EORA %s", _destination );
            outline0("ANDA #$80" );
            outline1("BEQ %ssamesign", label );
            outline0("STA <MATHPTR0" );
            outhead1("%ssamesign", label );

            outline1("LDA %s", _source );
            outline0("ANDA #$80" );
            outline1("BEQ %spositive1", label );
            outline1("LDA %s", _source );
            outline0("EORA #$FF" );
            outline0("ADDA #1" );
            outline1("JMP %spositive1b", label );

            outhead1("%spositive1", label );
            outline1("LDA %s", _source );
            outhead1("%spositive1b", label );
            outline1("LDB %s", _destination );
            outline0("ANDB #$80" );
            outline1("BEQ %spositive2", label );
            outline1("LDB %s", _destination );
            outline0("EORB #$FF" );
            outline0("ADDB #1" );
            outline1("JMP %spositive2b", label );

            outhead1("%spositive2", label );
            outline1("LDB %s", _destination );
            outhead1("%spositive2b", label );
        } else {
            outline1("LDA %s", _source );
            outline1("LDB %s", _destination );
        }

        outline0("MUL" );

        outline1("STD %s", _other );

        if ( _signed ) {
            outline0("LDA <MATHPTR0" );
            outline0("CMPA #0" );
            outline1("BEQ %sdone", label );
            outline1("LDD %s", _other );
            outline0("EORA #$FF" );
            outline0("EORB #$FF" );
            outline0("ADDD #1" );
            outline1("STD %s", _other );
            outhead1("%sdone", label );
        }

    embedded( cpu_math_mul_8bit_to_16bit, src_hw_6809_cpu_math_mul_8bit_to_16bit_asm );

        outline1("LDB %s", _source );
        outline1("LDA %s", _destination );
        if ( _signed ) {
            outline0("JSR CPUMATHMUL8BITTO16BIT_SIGNED" );
        } else {
            outline0("MUL" );
        }
        outline1("STD %s", _other );

    done( )

}

void cpu6809_math_div_8bit_to_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    inline( cpu_math_div_8bit_to_8bit )

        MAKE_LABEL
        outline0("LDX #$0");
        outline1("LDA %s", _destination);
        if ( _signed ) {
            outline0("ANDA #$80");
            outline0("CMPA #$0");
            outline1("BEQ %spos1", label);
            outline0("LDX #$1");
            outline1("LDA %s", _destination);
            outline0("EORA #$FF");
            outline0("ADDA #$1");
            outline0("STA <TMPPTR");
            outline1("JMP %sdone1", label);
            outhead1("%spos1", label );
            outline0("STA <TMPPTR");
            outline1("JMP %sdone1", label);
            outhead1("%sdone1", label );
        } else {
            outline0("STA <TMPPTR");
        }
        outline1("LDA %s", _source);
        if ( _signed ) {
            outline0("ANDA #$80");
            outline0("CMPA #$0");
            outline1("BEQ %spos2", label);
            outline0("LDX #$1");
            outline1("LDA %s", _source);
            outline0("EORA #$FF");
            outline0("ADDA #$1");
            outline0("STA <TMPPTR+1");
            outline1("JMP %sdone2", label);
            outhead1("%spos2", label );
            outline0("STA <TMPPTR+1");
            outline1("JMP %sdone2", label);
            outhead1("%sdone2", label );
        } else {
            outline0("STA <TMPPTR+1");
        }
        outhead1("%spos", label );
        outline0("LDA #$8");
        outline1("STA %s", _other_remainder);
        outline0("LDA #$0" );
        outline0("LDB <TMPPTR+1" );
        outhead1("%sdivide", label );
        outline0("ASLB" );
        outline0("ROLA" );
        outline0("CMPA <TMPPTR");
        outline1("BCS %schkcnt", label );
        outline0("SUBA <TMPPTR" );
        outline0("INCB" );
        outhead1("%schkcnt", label );
        outline1("DEC %s", _other_remainder );
        outline1("BNE %sdivide", label );
        outline1("STB %s", _other );
        outline0("CMPX #$1");
        outline1("BNE %sdone", label);
        outline0("ADDA 1" );
        outhead1("%sdone", label );
        outline1("STA %s", _other_remainder );

    embedded( cpu_math_div_8bit_to_8bit, src_hw_6809_cpu_math_div_8bit_to_8bit_asm );

        outline1("LDB %s", _source);
        outline1("LDA %s", _destination);
        if ( _signed ) {
            outline0("JSR CPUMATHDIV8BITTO8BIT_SIGNED");
        } else {
            outline0("JSR CPUMATHDIV8BITTO8BIT");
        }
        outline1("STA %s", _other_remainder);
        outline1("STB %s", _other);

    done( )

}

/**
 * @brief <i>CPU 6809</i>: emit code to halves for several times a 8 bit value
 *
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6809_math_div2_const_8bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    inline( cpu_math_div2_8bit )

        MAKE_LABEL

        if ( _signed ) {
            outline0("LDA #0");
            outline0("STA <MATHPTR0");
            outline1("LDA %s", _source);
            outline0("ANDA #$80");
            outline1("BEQ %spos", label);
            outline0("EORA #$FF");
            outline0("ADDA #1");
            outline0("LDA #1");
            outline0("STA <MATHPTR0");
            outhead1("%spos", label);
        }
        outline1("LDA %s", _source);
        outline1("LDB #$%2.2x", _steps);
        outline0("CMPB #0");
        outline1("BEQ %sdone", label);
        outhead1("%sloop", label);
        outline0("ASRA");
        outline0("DECB");
        outline0("CMPB #0");
        outline1("BNE %sloop", label);
        outhead1("%sdone", label);
        if ( _signed ) {
            outline0("LDA <MATHPTR0");
            outline1("BEQ %spos2", label);
            outline0("EORA #$FF");
            outline0("ADDA #1");
            outhead1("%spos2", label);
        }
        outline1("STA %s", _source);

    embedded( cpu_math_div2_8bit, src_hw_6809_cpu_math_div2_8bit_asm );

        outline1("LDB %s", _source);
        outline1("LDA #$%2.2x", _steps);
        if ( _signed ) {
            outline0("JSR CPUMATHDIV28BIT_SIGNED");
        } else {
            outline0("JSR CPUMATHDIV28BIT");
        }
        outline1("STB %s", _source);

    done( )
}

/**
 * @brief <i>CPU 6809</i>: emit code to double for several times a 8 bit value
 *
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 */
void cpu6809_math_mul2_const_8bit( Environment * _environment, char *_source, int _steps, int _signed ) {
    int i;
    
    inline( cpu_math_mul2_const_8bit )

        outline1("LDB %s", _source );           
        for(i=0; i<_steps; ++i) {
            outline0("LSLB" );
        }
        outline1("STB %s", _source );

    no_embedded( cpu_math_mul2_const_8bit );

}

/**
 * @brief <i>CPU 6809</i>: emit code to calculate an 8 bit complement of a number
 *
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void cpu6809_math_complement_const_8bit( Environment * _environment, char *_source, int _value ) {

    inline( cpu_math_complement_const_8bit )

        outline1("LDB #$%2.2x", _value);
        outline1("SUBB %s", _source);
        outline1("STB %s", _source);

    no_embedded( cpu_math_complement_const_8bit )

}

/**
 * @brief <i>CPU 6809</i>: emit code to mask with "and" a value of 8 bit
 *
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void cpu6809_math_and_const_8bit( Environment * _environment, char *_source, int _mask ) {

    inline( cpu_math_and_const_8bit )

        outline1("LDB %s", _source);
        outline1("ANDB %2.2x", _mask);
        outline1("STB %s", _source);

    no_embedded( cpu_math_and_const_8bit )

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

    inline( cpu_move_16bit )

        outline1("LDD %s", _source);
        outline1("STD %s", _destination);

    no_embedded( cpu_move_16bit )

}

void cpu6809_addressof_16bit( Environment * _environment, char *_source, char *_destination ) {

    inline( cpu_addressof_16bit )

        outline1("LDD #%s", _source);
        outline1("STD %s", _destination);

    no_embedded( cpu_addressof_16bit )

}

/**
 * @brief <i>CPU 6809</i>: emit code to store 16 bit
 *
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void cpu6809_store_16bit( Environment * _environment, char *_destination, int _value ) {

    inline( cpu_store_16bit )

        outline1("LDD #$%4.4x", (unsigned int)( _value & 0xffff ) );
        outline1("STD %s", _destination );

    no_embedded( cpu_store_16bit )

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

    inline( cpu_compare_16bit )

        cpu6809_compare( _environment, _source, _destination, _other, _positive, 16 );

    no_embedded( cpu_compare_16bit )

}

/**
 * @brief <i>CPU 6809</i>: emit code to compare two 8 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void cpu6809_compare_and_branch_16bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

    inline( cpu_compare_and_branch_16bit_const )

        outline1("LDX %s", _source);
        outline1("CMPX #$%4.4x", _destination);
        if ( _positive ) {
            B(EQ, _label);
        } else {
            B(NE, _label);
        }

    no_embedded( cpu_compare_and_branch_16bit_const )

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

    inline( cpu_less_than_16bit )

        cpu6809_less_than( _environment, _source, _destination,  _other, _equal, _signed, 16 );

    no_embedded( cpu_compare_16bit )

}

void cpu6809_less_than_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    inline( cpu_less_than_16bit_const )

        cpu6809_less_than_const( _environment, _source, _destination,  _other, _equal, _signed, 16 );

    no_embedded( cpu_compare_16bit )

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

    inline( cpu_greater_than_16bit )

        cpu6809_greater_than( _environment, _source, _destination,  _other, _equal, _signed, 16 );

    no_embedded( cpu_greater_than_16bit )

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

    inline( cpu_math_add_16bit )

        // this way has more affinity with peephole optimizations
        outline1("LDD %s", _destination);
        outline1("ADDD %s", _source);
        outline1("STD %s", _other ? _other : _destination);

    no_embedded( cpu_math_add_16bit )

}

void cpu6809_math_add_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

    inline( cpu_math_add_16bit_const )

        // this way has more affinity with peephole optimizations
        outline1("LDD #$%4.4x", ( _destination & 0xffff ) );
        outline1("ADDD %s", _source);
        outline1("STD %s", _other );

    no_embedded( cpu_math_add_16bit )

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

    inline( cpu_math_add_16bit_with_16bit )

        outline1("LDD %s", _source);
        outline1("ADDD #%s", _destination);
        outline1("STD %s", _other ? _other : _destination);
        
    no_embedded( cpu_math_add_16bit_with_16bit )

}

void cpu6809_math_add_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_add_16bit_with_8bit )

        outline1("LDX %s", _source);
        outline1("LDB %s", _destination);
        outline0("ABX");
        outline1("STX %s", _other ? _other : _destination );

    no_embedded( cpu_math_add_16bit_with_8bit )

}

/**
 * @brief <i>CPU 6809</i>: emit code to double a 16 bit value
 *
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6809_math_double_16bit( Environment * _environment, char *_source, char *_other, int _signed ) {

    inline( cpu_math_double_16bit )

        if(_other) {
            outline1("LDD %s", _source);
            outline0("LSLB");
            outline0("ROLA");
            outline1("STD %s", _other);
        } else {
            outline1("LSL %s", address_displacement(_environment, _source, "1"));
            outline1("ROL %s",   _source);
        }

    no_embedded( cpu_math_double_16bit )

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

    inline( cpu_math_mul_16bit_to_32bit )

        MAKE_LABEL

        if ( _signed ) {
            outline0("LDA #0" );
            outline0("STA <TMPPTR" );
            outline1("LDA %s", _source );
            outline1("EORA %s", _destination );
            outline0("ANDA #$80" );
            outline1("BEQ %ssamesign", label );
            outline0("STA <TMPPTR" );
            outhead1("%ssamesign", label );

            outline1("LDA %s", _source );
            outline0("ANDA #$80" );
            outline1("BEQ %spos1", label );
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("EORA #$FF" );
            outline0("STA <MATHPTR1" );
            outline1("LDA %s", _source );
            outline0("EORA #$FF" );
            outline0("STA <MATHPTR0" );
            outline0("LDX <MATHPTR0" );
            outline0("LEAX 1,X" );
            outline0("STX <MATHPTR0" );
            outline1("JMP %sdone1", label );
            outhead1("%spos1", label );
            outline1("LDX %s", _source );
            outline0("STX <MATHPTR0" );
            outhead1("%sdone1", label );

            outline1("LDA %s", _destination );
            outline0("ANDA #$80" );
            outline1("BEQ %spos2", label );
            outline1("LDA %s", address_displacement(_environment, _destination, "1") );
            outline0("EORA #$FF" );
            outline0("STA <MATHPTR3" );
            outline1("LDA %s", _destination );
            outline0("EORA #$FF" );
            outline0("STA <MATHPTR2" );
            outline0("LDX <MATHPTR2" );
            outline0("LEAX 1,X" );
            outline0("STX <MATHPTR2" );
            outline1("JMP %sdone2", label );
            outhead1("%spos2", label );
            outline1("LDX %s", _destination );
            outline0("STX <MATHPTR2" );
            outhead1("%sdone2", label );
        } else {
            outline1("LDD %s", _source );
            outline0("STD <MATHPTR0" );
            outline1("LDD %s", _destination );
            outline0("STD <MATHPTR2" );
        }
        outline0("LDA <MATHPTR0" );
        outline0("LDB <MATHPTR2" );
        outline0("MUL");
        outline1("STD %s", _other );

        outline0("LDA <MATHPTR1" );
        outline0("LDB <MATHPTR3" );
        outline0("MUL" );
        outline1("STD %s", address_displacement(_environment, _other, "2") );

        outline0("LDA <MATHPTR1" );
        outline0("LDB <MATHPTR2" );
        outline0("MUL" );
        outline0("TFR D, X" );

        outline0("LDA <MATHPTR0" );
        outline0("LDB <MATHPTR3" );
        outline0("MUL" );
        outline0("LEAX D, X" );

        outline0("TFR X, D" );

        outline1("ADDB %s", address_displacement(_environment, _other, "2") );
        outline1("STB %s", address_displacement(_environment, _other, "2") );

        outline1("ADDA %s", address_displacement(_environment, _other, "1") );
        outline1("STA %s", address_displacement(_environment, _other, "1") );

        if ( _signed ) {
            outline0("LDA <TMPPTR" );
            outline0("CMPA #0" );
            outline1("BEQ %sdonex", label );
            outline1("LDA %s", _other );
            outline0("EORA #$FF" );
            outline1("STA %s", _other );
            outline1("LDA %s", address_displacement(_environment, _other, "1") );
            outline0("EORA #$FF" );
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outline1("LDA %s", address_displacement(_environment, _other, "2") );
            outline0("EORA #$FF" );
            outline1("STA %s", address_displacement(_environment, _other, "2") );
            outline1("LDA %s", address_displacement(_environment, _other, "3") );
            outline0("EORA #$FF" );
            outline1("STA %s", address_displacement(_environment, _other, "3") );
            outline1("LDA %s", address_displacement(_environment, _other, "3") );
            outline0("ADDA #1" );
            outline1("STA %s", address_displacement(_environment, _other, "3") );
            outline1("LDA %s", address_displacement(_environment, _other, "2") );
            outline0("ADDA #0" );
            outline1("STA %s", address_displacement(_environment, _other, "2") );
            outline1("LDA %s", address_displacement(_environment, _other, "1") );
            outline0("ADDA #0" );
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outline1("LDA %s", _other );
            outline0("ADDA #0" );
            outline1("STA %s", _other );
            outhead1("%sdonex", label );
        }

    embedded( cpu_math_mul_16bit_to_32bit, src_hw_6809_cpu_math_mul_16bit_to_32bit_asm );

        outline1("LDD %s", _destination );
        outline1("LDX %s", _source );

        if ( _signed ) {
            outline0("JSR CPUMATHMUL16BITTO32BIT_SIGNED" );
        } else {
            outline0("JSR CPUMATHMUL16BITTO32BIT" );
        }

        outline1("STX %s", _other );
        outline1("STD %s", address_displacement(_environment, _other, "2") );

    done( )

}

void cpu6809_math_div_16bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    inline( cpu_math_div_16bit_to_16bit )

        MAKE_LABEL

        if ( _signed ) {

            outline1("LDA %s", _source );
            outline1("EORA %s", _destination );
            outline0("ANDA #$80" );
            outline0("PSHS A");

            outline1("LDA %s", _source );
            outline0("ANDA #$80" );
            outline1("BEQ %ssecond", label );
            outline0("ANDCC #$FE" );
            outline1("LDA %s", _source );
            outline0("EORA #$ff" );
            outline0("STA <MATHPTR0" );
            outline1("LDA %s", address_displacement(_environment, _source, "1") );
            outline0("EORA #$ff" );
            outline0("STA <MATHPTR1" );
            outline0("ANDCC #$FE" );
            outline0("LDD <MATHPTR0" );
            outline0("ADDD #1" );
            outline0("STD <MATHPTR0" );
            outline1("JMP %ssecond2", label );
            outhead1("%ssecond", label );
            outline1("LDD %s", _source );
            outline0("STD <MATHPTR0");
            outline1("JMP %ssecond2", label );

            outhead1("%ssecond2", label );
            outline1("LDA %s", address_displacement(_environment, _destination, "1") );
            outline0("ANDA #$80" );
            outline1("BEQ %sthird", label );
            outline0("ANDCC #$FE" );
            outline1("LDA %s", _destination );
            outline0("EORA #$ff" );
            outline0("STA <MATHPTR2" );
            outline1("LDA %s", address_displacement(_environment, _destination, "1") );
            outline0("EORA #$ff" );
            outline0("STA <MATHPTR3" );
            outline0("ANDCC #$FE" );
            outline0("LDD <MATHPTR2" );
            outline0("ADDD #1" );
            outline0("STD <MATHPTR2" );
            outline1("JMP %sthird2", label );
            outhead1("%sthird", label );
            outline1("LDD %s", _destination );
            outline0("STD <MATHPTR2");
            outline1("JMP %sthird2", label );

            outhead1("%sthird2", label );

            outline0("LDX <MATHPTR0" );
            outline0("LDY <MATHPTR2" );

            outhead1("%sDIVXY", label);
            outline0("PSHS Y,X,D,CC" );
            outline0("LDB #$10" );
            outline0("PSHS B" );
            outline0("CLRB" );
            outline0("CLRA" );
            outhead1("%sDIVLP", label);
            outline0("ASL 5,S" );
            outline0("ROL 4,S" );
            outline0("ROLB" );
            outline0("ROLA" );
            outline0("CMPD 6,S" );
            outline1("BLO %sDIVLT", label );
            outline0("SUBD 6,S" );
            outline0("INC 5,S" );
            outhead1("%sDIVLT", label);
            outline0("DEC ,S" );
            outline1("BNE %sDIVLP", label );
            outline0("STD 6,S" );
            outline0("LEAS 1,S" );
            outline0("PULS Y,X,D,CC" );

            outline1("STX %s", _other );
            outline1("STY %s", _other_remainder );

            outline0("PULS A");
            outline0("ANDA #$80");
            outline1("BEQ %sdone", label);
            outline1("LDA %s", _other );
            outline0("EORA #$ff" );
            outline1("STA %s", _other );
            outline1("LDA %s", address_displacement(_environment, _other, "1") );
            outline0("EORA #$ff" );
            outline1("STA %s", address_displacement(_environment, _other, "1") );
            outline0("ANDCC #$FE" );
            outline1("LDD %s", _other );
            outline0("ADDD #1" );
            outline1("STD %s", _other );
            outhead1("%sdone", label );

        } else {

            outline1("LDX %s", _source );
            outline1("LDY %s", _destination );
            outhead1("%sDIVXY", label);
            outline0("PSHS Y,X,D,CC" );
            outline0("LDB #$10" );
            outline0("PSHS B" );
            outline0("CLRB" );
            outline0("CLRA" );
            outhead1("%sDIVLP", label);
            outline0("ASL 5,S" );
            outline0("ROL 4,S" );
            outline0("ROLB" );
            outline0("ROLA" );
            outline0("CMPD 6,S" );
            outline1("BLO %sDIVLT", label );
            outline0("SUBD 6,S" );
            outline0("INC 5,S" );
            outhead1("%sDIVLT", label);
            outline0("DEC ,S" );
            outline1("BNE %sDIVLP", label );
            outline0("STD 6,S" );
            outline0("LEAS 1,S" );
            outline0("PULS Y,X,D,CC" );
            outline1("STX %s", _other );
            outline1("STY %s", _other_remainder );
        }

    embedded( cpu_math_div_16bit_to_16bit, src_hw_6809_cpu_math_div_16bit_to_16bit_asm );

        outline1("LDD %s", _source );
        outline1("LDX %s", _destination );
        if ( _signed ) {
            outline0("JSR CPUMATHDIV16BITTO16BIT_SIGNED" );
        } else {
            outline0("JSR CPUMATHDIV16BITTO16BIT" );
        }
        outline1("STX %s", _other_remainder );
        outline1("STD %s", _other );

    done( )

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

    inline( cpu_math_sub_16bit )

        outline1("LDD %s", _source );
        outline1("SUBD %s", _destination);
        outline1("STD %s", _other ? _other : _destination );

    no_embedded( cpu_math_sub_16bit );

}

void cpu6809_math_sub_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_sub_16bit_with_8bit )

        outline1("LDD %s", _source );
        outline1("SUBB %s", _destination);
        outline0("SBCA #0");
        outline1("STD %s", _other ? _other : _destination );

    no_embedded( cpu_math_sub_16bit_with_8bit );

}

/**
 * @brief <i>CPU 6809</i>: emit code to calculate a 16 bit complement of a number
 *
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void cpu6809_math_complement_const_16bit( Environment * _environment, char *_source, int _value ) {

    inline( cpu_math_complement_const_16bit )

        outline1("LDD #$%2.2x", _value);
        outline1("SUBD %s", _source );
        outline1("STD %s", _source);

    no_embedded( cpu_math_complement_const_16bit );

}

/**
 * @brief <i>CPU 6809</i>: emit code to halves for several times a 16 bit value
 *
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6809_math_div2_const_16bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    inline( cpu_math_div2_const_16bit )

        MAKE_LABEL

        if ( _signed ) {

            outline1("LDA %s", _source);
            outline0("ANDA #$80");
            outline1("BEQ %spos", label );

            outline1("LDD %s", _source );
            outline0("ANDCC #$FE" );
            outline0("EORA #$FF" );
            outline0("EORB #$FF" );
            outline0("ADDD #1" );

            outline1("JMP %sdone", label );

            outhead1("%spos", label );
            outline1("LDD %s", _source );

            outhead1("%sdone", label );

            outline1("LDX #$%2.2x", _steps );
            outhead1("%sloop", label );
            outline0("ANDCC #$FE" );
            outline0("ASRA" );
            outline0("RORB" );
            outline0("LEAX -1, X");
            outline0("CMPX #0");
            outline1("BNE %sloop", label );

            outline0("STD <MATHPTR0");

            outline1("LDA %s", _source);
            outline0("ANDA #$80");
            outline1("BEQ %spos2", label );

            outline0("LDD <MATHPTR0");
            outline0("ANDCC #$FE" );
            outline0("EORA #$FF" );
            outline0("EORB #$FF" );
            outline0("ADDD #1" );

            outline1("JMP %sdone2", label );

            outhead1("%spos2", label );
            outline0("LDD <MATHPTR0");
            outhead1("%sdone2", label );
            outline1("STD %s", _source );

        } else {

            outline1("LDD %s", _source );
            outline1("LDX #$%2.2x", _steps );
            outhead1("%sloop", label );
            outline0("ANDCC #$FE" );
            outline0("ASRA" );
            outline0("RORB" );
            outline0("LEAX -1, X");
            outline0("CMPX #0");
            outline1("BNE %sloop", label );
            outline1("STD %s", _source );

        }

    embedded( cpu_math_div2_const_16bit, src_hw_6809_cpu_math_div2_const_16bit_asm );

        outline1("LDD %s", _source );
        outline1("LDX #$%2.2x", _steps );

        if ( _signed ) {
            outline0("JSR CPUMATHDIV2CONST16BIT_SIGNED");
        } else {
            outline0("JSR CPUMATHDIV2CONST16BIT");
        }
        outline1("STD %s", _source );

    done( )

}

/**
 * @brief <i>CPU 6809</i>: emit code to halves for several times a 8 bit value
 *
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6809_math_mul2_const_16bit( Environment * _environment, char *_source, int _steps, int _signed ) {
    int i;

    inline( cpu_math_mul2_const_16bit )


        outline1("LDD %s", _source );           
        for(i=0; i<_steps; ++i) {
            outline0("LSLB" );
            outline0("ROLA" );
        }
        outline1("STD %s", _source );

    no_embedded( cpu_math_mul2_const_16bit );

}

/**
 * @brief <i>CPU 6809</i>: emit code to mask with "and" a value of 16 bit
 *
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void cpu6809_math_and_const_16bit( Environment * _environment, char *_source, int _mask ) {

    inline( cpu_math_and_const_16bit )

        outline1("LDD %s", _source );
        outline1("ANDA #$%2.2x", ( _mask >> 8 ) & 0xff );
        outline1("ANDB #$%2.2x", ( _mask & 0xff ) );
        outline1("STD %s", _source );

    no_embedded( cpu_math_and_const_16bit );

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

    inline( cpu_move_32bit )

        outline1("LDD %s", _source );
        outline1("STD %s", _destination );
        outline1("LDD %s", address_displacement(_environment, _source, "2") );
        outline1("STD %s", address_displacement(_environment, _destination, "2") );

    no_embedded( cpu_move_32bit );

}

/**
 * @brief <i>CPU 6809</i>: emit code to store 32 bit
 *
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void cpu6809_store_32bit( Environment * _environment, char *_destination, int _value ) {

    inline( cpu_store_32bit )

        outline1("LDD #$%4.4x", ( _value >> 16 ) & 0xffff );
        outline1("STD %s", _destination );
        if((( _value >> 16 ) & 0xffff) != ( _value & 0xffff ))
        outline1("LDD #$%4.4x", ( _value & 0xffff ) );
        outline1("STD %s", address_displacement(_environment, _destination, "2") );

    no_embedded( cpu_store_32bit );

}

void cpu6809_math_div_32bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    CRITICAL_UNIMPLEMENTED("cpu6809_math_div_32bit_to_16bit");

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

    inline( cpu_compare_32bit )

        MAKE_LABEL

        char sourceEffective[MAX_TEMPORARY_STORAGE]; sprintf(sourceEffective, "%s", address_displacement(_environment, _source, "2") );
        char destinationEffective[MAX_TEMPORARY_STORAGE]; sprintf(destinationEffective, "%s", address_displacement(_environment, _source, "2") );

        if ( _positive ) {

            cpu6809_compare_16bit( _environment, _source, _destination, _other, _positive );

            outline1("LDB %s", _other );
            outline1("BEQ %sdone", label );

            cpu6809_compare_16bit( _environment, sourceEffective, destinationEffective, _other, _positive );

        } else {

            cpu6809_compare_16bit( _environment, _source, _destination, _other, _positive );

            outline1("LDB %s", _other );
            outline1("BNE %sdone", label );

            cpu6809_compare_16bit( _environment, sourceEffective, destinationEffective, _other, _positive );

        }

        outhead1("%sdone", label );

    no_embedded( cpu_compare_32bit )

}

/**
 * @brief <i>CPU 6809</i>: emit code to compare two 32 bit values and jump if they are equal/different
 * 
 * @param _environment Current calling environment
 * @param _source First value to compare
 * @param _destination Second value to compare
 * @param _label Where to jump
 * @param _positive Invert meaning of comparison
 */
void cpu6809_compare_and_branch_32bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _positive ) {

    MAKE_LABEL

    inline( cpu_compare_and_branch_32bit_const )

        outline1("LDX %s", _source);
        outline1("CMPX #$%4.4x", ( ( _destination >> 16 ) & 0xffff ) );
        if ( _positive ) {
            B(NE, label);
        } else {
            B(EQ, label);
        }
        outline1("LDX %s", address_displacement(_environment, _source, "2"));
        outline1("CMPX #$%4.4x", ( _destination & 0xffff ) );
        if ( _positive ) {
            B(EQ, _label);
        } else {
            B(NE, _label);
        }
        outhead1("%s", label);

    no_embedded( cpu_compare_and_branch_32bit_const )

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

    inline( cpu_less_than_32bit )

        MAKE_LABEL

        outline0("CLRA");
        outline1("LDX %s", _source);
        outline1("CMPX %s", _destination);
        outline1("BNE %shigh", label);
        outline1("LDX %s", address_displacement(_environment, _source, "2"));
        outline1("CMPX %s", address_displacement(_environment, _destination, "2"));
        outhead1("%shigh", label );

        if ( _signed ) {
            if ( _equal ) {
                outline1("BGT %sdone", label);
            } else {
                outline1("BGE %sdone", label);
            }
        } else {
            if ( _equal ) {
                outline1("BHI %sdone", label);
            } else {
                outline1("BHS %sdone", label);
            }
        }
        outline0("DECA");
        outhead1("%sdone", label );
        outline1("STA %s", _other ? _other : _destination );

    no_embedded( cpu_less_than_32bit )


}

void cpu6809_less_than_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    inline( cpu_less_than_32bit_const )

        MAKE_LABEL

        outline0("CLRA");
        outline1("LDX %s", _source);
        outline1("CMPX #$%4.4x", ( ( _destination >> 16 ) & 0xffff ) );
        outline1("BNE %shigh", label);
        outline1("LDX %s", address_displacement(_environment, _source, "2"));
        outline1("CMPX  #$%4.4x", ( _destination & 0xffff ) );
        outhead1("%shigh", label );

        if ( _signed ) {
            if ( _equal ) {
                outline1("BGT %sdone", label);
            } else {
                outline1("BGE %sdone", label);
            }
        } else {
            if ( _equal ) {
                outline1("BHI %sdone", label);
            } else {
                outline1("BHS %sdone", label);
            }
        }
        outline0("DECA");
        outhead1("%sdone", label );
        outline1("STA %s", _other );

    no_embedded( cpu_less_than_32bit_const )


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

    inline( cpu_greater_than_32bit )

        MAKE_LABEL

        outline0("CLRB");
        outline1("LDX %s", _source);
        outline1("CMPX %s", _destination);
        outline1("BNE %shigh", label);
        outline1("LDX %s", address_displacement(_environment, _source, "2"));
        outline1("CMPX %s", address_displacement(_environment, _destination, "2"));
        outhead1("%shigh", label );

        if ( _signed ) {
            if ( _equal ) {
                outline1("BLT %sdone", label);
            } else {
                outline1("BLE %sdone", label);
            }
        } else {
            if ( _equal ) {
                outline1("BLO %sdone", label);
            } else {
                outline1("BLS %sdone", label);
            }
        }

        outline0("DECB");
        outhead1("%sdone", label );
        outline1("STB %s", _other ? _other : _destination );

    no_embedded( cpu_greater_than_32bit )

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

    inline( cpu_math_add_32bit )

        MAKE_LABEL

        outline1("LDD %s", address_displacement(_environment, _source, "2"));
        outline1("LDX #%s", _destination);
        outline0("ADDD 2,X");
        if ( _other ) {
            outline1("STD %s", address_displacement(_environment, _other, "2"));
        } else {
            outline0("STD 2,X");
        }
        outline1("LDD %s", _source);
        outline0("ADCB 1,X");
        outline0("ADCA ,X");
        outline1("STD %s", _other ? _other : ",X" );

    no_embedded( cpu_math_add_32bit )

}

void cpu6809_math_add_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

    inline( cpu_math_add_32bit_const )

        MAKE_LABEL

        outline1("LDD %s", address_displacement(_environment, _source, "2"));
        outline1("LDX #$%4.4x", ( _destination & 0xffff ) );
        outline0("LEAX D,X");
        outline1("STD %s", address_displacement(_environment, _other, "2"));
        outline1("LDD %s", _source);
        outline1("LDX #$%4.4x", ( ( _destination >> 16 ) & 0xffff ) );
        outline0("LEAX D,X");
        outline1("STD %s", _other ? _other : ",X" );

    no_embedded( cpu_math_add_32bit_const )

}

/**
 * @brief <i>CPU 6809</i>: emit code to double a 32 bit value
 *
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6809_math_double_32bit( Environment * _environment, char *_source, char *_other, int _signed ) {

    inline( cpu_math_double_32bit )

        if(_other) {
            outline1("LDD %s", address_displacement(_environment, _source, "2"));
            outline0("LSLB");
            outline0("ROLA");
            outline1("STD %s", address_displacement(_environment, _other, "2"));
            outline1("LDD %s", _source);
            outline0("ROLB");
            outline0("ROLA");
            outline1("STD %s", _other);
        } else {
            outline1("LSL %s", address_displacement(_environment, _source, "3"));
            outline1("ROL %s", address_displacement(_environment, _source, "2"));
            outline1("ROL %s", address_displacement(_environment, _source, "1"));
            outline1("ROL %s",   _source);
        }

    no_embedded( cpu_math_double_32bit )

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

    inline( cpu_math_sub_32bit )

        outline1("LDD %s", address_displacement(_environment, _source, "2"));
        outline1("LDX #%s", _destination);
        outline0("SUBD 2,X");
        if ( _other ) {
            outline1("STD %s", address_displacement(_environment, _other, "2"));
        } else {
            outline0("STD 2,X");
        }
        outline1("LDD %s", _source);
        outline0("SBCB 1,X");
        outline0("SBCA ,X");
        outline1("STD %s", _other ? _other : ",X");
        
    no_embedded( cpu_math_sub_32bit )

}

/**
 * @brief <i>CPU 6809</i>: emit code to calculate a 32 bit complement of a number
 *
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void cpu6809_math_complement_const_32bit( Environment * _environment, char *_source, int _value ) {

    inline( cpu_math_complement_const_32bit )

        outline1("LDX #%s", _source);
        outline1("LDD #$%4.4x", ( _value ) & 0xffff );
        outline0("SUBD 2,X");
        outline0("STD 2,X");
        outline1("LDD #$%4.4x", ( _value>>16 ) & 0xffff );
        outline0("SBCB 1,X");
        outline0("SBCA ,X");
        outline0("STD ,X");

    no_embedded( cpu_math_complement_const_32bit )

}

/**
 * @brief <i>CPU 6809</i>: emit code to halves for several times a 32 bit value
 *
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6809_math_div2_const_32bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    inline( cpu_math_div2_const_32bit )

        MAKE_LABEL

        if ( _signed ) {

            outline1("LDA %s", _source);
            outline0("ANDA #$80");
            outline1("BEQ %spos", label );

            outline1("LDD %s", address_displacement(_environment, _source, "2") );
            outline0("ANDCC #$FE" );
            outline0("EORA #$FF" );
            outline0("EORB #$FF" );
            outline0("STD <MATHPTR2" );
            outline1("LDD %s", _source );
            outline0("ANDCC #$FE" );
            outline0("EORA #$FF" );
            outline0("EORB #$FF" );
            outline0("STD <MATHPTR0" );
            outline0("LDD <MATHPTR2" );
            outline0("ANDCC #$FE" );
            outline0("ADDD #1" );
            outline0("STD <MATHPTR2" );
            outline0("LDD <MATHPTR0" );
            outline0("ADDD #0" );
            outline0("STD <MATHPTR0" );

            outline1("JMP %sdone", label );

            outhead1("%spos", label );
            outline1("LDD %s", _source );
            outline0("STD <MATHPTR0" );
            outline1("LDD %s", address_displacement(_environment, _source, "2") );
            outline0("STD <MATHPTR2" );

            outhead1("%sdone", label );

            outline1("LDX #$%2.2x", _steps );
            outhead1("%sloop", label );
            outline0("ANDCC #$FE" );
            outline0("ASR <MATHPTR0" );
            outline0("ROR <MATHPTR1" );
            outline0("ROR <MATHPTR2" );
            outline0("ROR <MATHPTR3" );
            outline0("LEAX -1, X");
            outline0("CMPX #0");
            outline1("BNE %sloop", label );

            outline1("LDA %s", _source);
            outline0("ANDA #$80");
            outline1("BEQ %spos2", label );

            outline0("ANDCC #$FE" );
            outline0("LDD <MATHPTR2" );
            outline0("EORA #$FF" );
            outline0("EORB #$FF" );
            outline0("STD <MATHPTR2" );
            outline0("LDD <MATHPTR0" );
            outline0("EORA #$FF" );
            outline0("EORB #$FF" );
            outline0("STD <MATHPTR0" );

            outline0("ANDCC #$FE" );
            outline0("LDD <MATHPTR2" );
            outline0("ADDD #1" );
            outline1("STD %s", address_displacement(_environment, _source, "2") );
            outline0("LDD <MATHPTR0" );
            outline0("ADDD #0" );
            outline1("STD %s", _source );

            outline1("JMP %sdone2", label );

            outhead1("%spos2", label );
            outline0("LDD <MATHPTR3" );
            outline1("STD %s", address_displacement(_environment, _source, "3") );
            outline0("LDD <MATHPTR2" );
            outline1("STD %s", address_displacement(_environment, _source, "2") );
            outline0("LDD <MATHPTR1" );
            outline1("STD %s", address_displacement(_environment, _source, "1") );
            outline0("LDD <MATHPTR0" );
            outline1("STD %s", _source );
            outhead1("%sdone2", label );

        } else {

            outline1("LDD %s", _source );
            outline0("STD <MATHPTR0" );
            outline1("LDD %s", address_displacement(_environment, _source, "2") );
            outline0("STD <MATHPTR2" );

            outhead1("%sdone", label );

            outline1("LDX #$%2.2x", _steps );
            outhead1("%sloop", label );
            outline0("ANDCC #$FE" );
            outline0("LSR <MATHPTR0" );
            outline0("ROR <MATHPTR1" );
            outline0("ROR <MATHPTR2" );
            outline0("ROR <MATHPTR3" );
            outline0("LEAX -1, X");
            outline0("CMPX #0");
            outline1("BNE %sloop", label );

            outline0("LDD <MATHPTR2" );
            outline1("STD %s", address_displacement(_environment, _source, "2") );
            outline0("LDD <MATHPTR0" );
            outline1("STD %s", _source );

        }

    no_embedded( cpu_math_div2_const_32bit )

}

/**
 * @brief <i>CPU 6809</i>: emit code to double for several times a 32 bit value
 *
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 */
void cpu6809_math_mul2_const_32bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    inline( cpu_math_mul2_const_32bit )

        MAKE_LABEL

        if ( _signed ) {

            outline1("LDA %s", _source);
            outline0("ANDA #$80");
            outline1("BEQ %spos", label );

            outline1("LDD %s", address_displacement(_environment, _source, "2") );
            outline0("ANDCC #$FE" );
            outline0("EORA #$FF" );
            outline0("EORB #$FF" );
            outline0("STD <MATHPTR2" );
            outline1("LDD %s", _source );
            outline0("ANDCC #$FE" );
            outline0("EORA #$FF" );
            outline0("EORB #$FF" );
            outline0("STD <MATHPTR0" );
            outline0("LDD <MATHPTR2" );
            outline0("ANDCC #$FE" );
            outline0("ADDD #1" );
            outline0("STD <MATHPTR2" );
            outline0("LDD <MATHPTR0" );
            outline0("ADDD #0" );
            outline0("STD <MATHPTR0" );

            outline1("JMP %sdone", label );

            outhead1("%spos", label );
            outline1("LDD %s", _source );
            outline0("STD <MATHPTR0" );
            outline1("LDD %s", address_displacement(_environment, _source, "2") );
            outline0("STD <MATHPTR2" );

            outhead1("%sdone", label );

            outline1("LDX #$%2.2x", _steps );
            outhead1("%sloop", label );
            outline0("ANDCC #$FE" );
            outline0("LSL <MATHPTR3" );
            outline0("ROL <MATHPTR2" );
            outline0("ROL <MATHPTR1" );
            outline0("ROL <MATHPTR0" );
            outline0("LEAX -1, X");
            outline0("CMPX #0");
            outline1("BNE %sloop", label );

            outline1("LDA %s", _source);
            outline0("ANDA #$80");
            outline1("BEQ %spos2", label );

            outline0("ANDCC #$FE" );
            outline0("LDD <MATHPTR2" );
            outline0("EORA #$FF" );
            outline0("EORB #$FF" );
            outline0("STD <MATHPTR2" );
            outline0("LDD <MATHPTR0" );
            outline0("EORA #$FF" );
            outline0("EORB #$FF" );
            outline0("STD <MATHPTR0" );

            outline0("ANDCC #$FE" );
            outline0("LDD <MATHPTR2" );
            outline0("ADDD #1" );
            outline1("STD %s", address_displacement(_environment, _source, "2") );
            outline0("LDD <MATHPTR0" );
            outline0("ADDD #0" );
            outline1("STD %s", _source );

            outline1("JMP %sdone2", label );

            outhead1("%spos2", label );
            outline0("LDD <MATHPTR3" );
            outline1("STD %s", address_displacement(_environment, _source, "3") );
            outline0("LDD <MATHPTR2" );
            outline1("STD %s", address_displacement(_environment, _source, "2") );
            outline0("LDD <MATHPTR1" );
            outline1("STD %s", address_displacement(_environment, _source, "1") );
            outline0("LDD <MATHPTR0" );
            outline1("STD %s", _source );
            outhead1("%sdone2", label );

        } else {

            outline1("LDD %s", _source );
            outline0("STD <MATHPTR0" );
            outline1("LDD %s", address_displacement(_environment, _source, "2") );
            outline0("STD <MATHPTR2" );

            outhead1("%sdone", label );

            outline1("LDX #$%2.2x", _steps );
            outhead1("%sloop", label );
            outline0("ANDCC #$FE" );
            outline0("LSL <MATHPTR3" );
            outline0("ROL <MATHPTR2" );
            outline0("ROL <MATHPTR1" );
            outline0("ROL <MATHPTR0" );
            outline0("LEAX -1, X");
            outline0("CMPX #0");
            outline1("BNE %sloop", label );

            outline0("LDD <MATHPTR2" );
            outline1("STD %s", address_displacement(_environment, _source, "2") );
            outline0("LDD <MATHPTR0" );
            outline1("STD %s", _source );

        }

    no_embedded( cpu_math_mul2_const_32bit )

}

/**
 * @brief <i>CPU 6809</i>: emit code to mask with "and" a value of 32 bit
 *
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void cpu6809_math_and_const_32bit( Environment * _environment, char *_source, int _mask ) {

    inline( cpu_math_and_const_32bit )

        outline1("LDX #%s", _source );
        if(_mask & 0xffff0000) {
            outline0("LDD ,X");
            outline1("ANDA #$%2.2x", ( _mask >> 24 ) & 0xff );
            outline1("ANDB #$%2.2x", ( _mask >> 16 ) & 0xff );
        } else {
            outline0("LDD #0");
        }
        outline0("STD ,X");
        if(_mask & 0x0000ffff) {
            outline0("LDD 2,X");
            outline1("ANDA #$%2.2x", ( _mask >> 8 ) & 0xff );
            outline1("ANDB #$%2.2x", ( _mask >> 0 ) & 0xff );
        } else {
            outline0("LDD #0");
        }
        outline0("STD 2,X");

    no_embedded( cpu_math_and_const_32bit )

}

void cpu6809_combine_nibbles( Environment * _environment, char * _low_nibble, char * _hi_nibble, char * _byte ) {

    inline( cpu_combine_nibbles )

        outline1("LDB %s", _low_nibble);
        outline1("STB %s", _byte);
        outline1("LDB %s", _hi_nibble);
        outline0("LSLB");
        outline0("LSLB");
        outline0("LSLB");
        outline0("LSLB");
        outline1("ORB %s", _byte);
        outline1("STB %s", _byte);

    no_embedded( cpu_combine_nibbles )

}

void cpu6809_jump( Environment * _environment, char * _label ) {

    inline( cpu_jump )

        B(RA, _label );

    no_embedded( cpu_jump )

}

void cpu6809_call( Environment * _environment, char * _label ) {

    inline( cpu_call )

        B(SR, _label );

    no_embedded( cpu_jump )

}

void cpu6809_return( Environment * _environment ) {

    inline( cpu_return )

        outline0( "RTS" );

    no_embedded( cpu_return )

}

void cpu6809_pop( Environment * _environment ) {

    inline( cpu_pop )

        outline0( "LEAS 2,S" );

    no_embedded( cpu_pop )

}

void cpu6809_halt( Environment * _environment ) {

    inline( cpu_halt )

        MAKE_LABEL

        outline0( "; HALT" );
        outhead1("%s", label );
        B(RA, label);

    no_embedded( cpu_halt )

}

void cpu6809_end( Environment * _environment ) {

    inline( cpu_end )

        outline0( "ANDCC #$6f" );
        cpu6809_halt( _environment );

    no_embedded( cpu_end )

}

void cpu6809_random( Environment * _environment, char * _entropy ) {

    inline( cpu_random )

        MAKE_LABEL

        srand( time( NULL ) );

        if ( _entropy ) {
            outline0("LDD CPURANDOM_SEED");
            outline0("ASLB");
            outline0("ASLB");
            outline0("ROLA");
            outline0("ADDD CPURANDOM_SEED+2");
            outline0("LSR CPURANDOM_SEED");
            outline0("ROR CPURANDOM_SEED+1");
            outline0("ASLB");
            outline0("ROLA");
            outline1("ADDA %s", _entropy);
            outline0("ASLB");
            outline0("ROLA");
            outline0("ASLB");
            outline0("ROLA");
            outline0("ADDD CPURANDOM_SEED+1");
            outline0("STD CPURANDOM_SEED+1");
        }

    embedded( cpu_random, src_hw_6809_cpu_random_asm );

        if ( _entropy ) {
            outline1( "LDB %s", _entropy );
            outline0( "STB <PATTERN" );
            outline0( "JSR CPURANDOM" );
        }

    done( )

}

void cpu6809_random_8bit( Environment * _environment, char * _entropy, char * _result ) {

    cpu6809_random( _environment, _entropy );

    if ( _result ) {
        outline0("LDB CPURANDOM_SEED+3");
        outline1("STB %s", _result );
    }

}

void cpu6809_random_16bit( Environment * _environment, char * _entropy, char * _result ) {

    cpu6809_random( _environment, _entropy );

    if ( _result ) {
        outline0("LDD CPURANDOM_SEED+2");
        outline1("STD %s", _result );
    }

}

void cpu6809_random_32bit( Environment * _environment, char * _entropy, char * _result ) {

    cpu6809_random( _environment, _entropy );

    if ( _result ) {
        outline0("LDD CPURANDOM_SEED");
        outline1("STD %s", _result );
        outline0("LDD CPURANDOM_SEED+2");
        outline1("STD %s", address_displacement(_environment, _result, "2") );
    }

}

void cpu6809_limit_16bit( Environment * _environment, char * _variable, int _value ) {

    inline( cpu_limit_16bit )

        MAKE_LABEL

        outline0( "LDA #$0" );
        outline1( "STA %s", _variable );
        outline1( "LDA %s", address_displacement(_environment, _variable, "1") );
        outline1( "CMPA #$%2.2x", _value );
        outline1( "BCC %s", label );
        outline1( "SUBA #$%2.2x", _value );
        outline1( "STA %s", _variable );
        outhead1( "%s", label );

    no_embedded( cpu_limit_16bit )

}

void cpu6809_busy_wait( Environment * _environment, char * _timing ) {

    inline( cpu_busy_wait )

        MAKE_LABEL

        outline1("LDA %s", _timing );
        outhead1("%s", label );
        outline0("DECA");
        outline1("BNE %s", label);

    no_embedded( cpu_busy_wait )

}

void cpu6809_logical_and_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    inline( cpu_logical_and_8bit )

        MAKE_LABEL

        outline1("LDB %s", _left );
        outline1("BEQ %s", label );
        outline1("LDB %s", _right );
        outline1("BEQ %s", label );
        outline0("LDB #$FF");
        outhead1("%s", label);
        outline1("STB %s", _result);

    no_embedded( cpu_logical_and_8bit )

}

void cpu6809_and_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    inline( cpu_and_8bit )

        MAKE_LABEL

        outline1("LDB %s", _right );
        outline1("ANDB %s", _left );
        outline1("STB %s", _result);

    no_embedded( cpu_and_8bit )

}

void cpu6809_and_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    inline( cpu_and_16bit )

        MAKE_LABEL

        outline1("LDD %s", _right );
        outline1("ANDA %s", _left );
        outline1("ANDB %s", address_displacement(_environment, _left, "1") );
        outline1("STD %s", _result);

    no_embedded( cpu_and_16bit )

}

void cpu6809_and_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    inline( cpu_and_32bit )

        MAKE_LABEL

        outline1("LDD %s", _left );
        outline1("ANDA %s", _right );
        outline1("ANDB %s", address_displacement(_environment, _right, "1") );
        outline1("STD %s", _result);
        outline1("LDD %s", address_displacement(_environment, _left, "2") );
        outline1("ANDA %s", address_displacement(_environment, _right, "2") );
        outline1("ANDB %s", address_displacement(_environment, _right, "3") );
        outline1("STD %s", address_displacement(_environment, _result, "2"));

    no_embedded( cpu_and_16bit )

}

void cpu6809_logical_or_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    inline( cpu_logical_or_8bit )

        MAKE_LABEL

        outline1("LDB %s", _left );
        outline1("ORB %s", _right );
        outline1("BEQ %s", label);
        outline0("LDB #$FF");
        outhead1("%s", label);
        outline1("STB %s", _result);

    no_embedded( cpu_logical_or_8bit )

}

void cpu6809_or_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    inline( cpu_or_8bit )

        MAKE_LABEL

        outline1("LDB %s", _right );
        outline1("ORB %s", _left );
        outline1("STB %s", _result);

    no_embedded( cpu_or_8bit )

}

void cpu6809_or_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    inline( cpu_or_16bit )

        MAKE_LABEL

        outline1("LDD %s", _left );
        outline1("ORA %s", _right );
        outline1("ORB %s", address_displacement(_environment, _right, "1") );
        outline1("STD %s", _result);

    no_embedded( cpu_or_16bit )

}

void cpu6809_or_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    inline( cpu_or_32bit )

        MAKE_LABEL

        outline1("LDD %s", _left );
        outline1("ORA %s", _right );
        outline1("ORB %s", address_displacement(_environment, _right, "1") );
        outline1("STD %s", _result);
        outline1("LDD %s", address_displacement(_environment, _left, "2") );
        outline1("ORA %s", address_displacement(_environment, _right, "2") );
        outline1("ORB %s", address_displacement(_environment, _right, "3") );
        outline1("STD %s", address_displacement(_environment, _result, "2"));

    no_embedded( cpu_or_32bit )

}

void cpu6809_xor_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    inline( cpu_xor_8bit )

        MAKE_LABEL

        outline1("LDB %s", _right );
        outline1("XOR %s", _left );
        outline1("STB %s", _result);

    no_embedded( cpu_xor_8bit )

}

void cpu6809_xor_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    inline( cpu_xor_16bit )

        MAKE_LABEL

        outline1("LDD %s", _left );
        outline1("EORA %s", _right );
        outline1("EORB %s", address_displacement(_environment, _right, "1") );
        outline1("STD %s", _result);

    no_embedded( cpu_xor_16bit )

}

void cpu6809_xor_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    inline( cpu_xor_32bit )

        MAKE_LABEL

        outline1("LDD %s", _left );
        outline1("EORA %s", _right );
        outline1("EORB %s", address_displacement(_environment, _right, "1") );
        outline1("STD %s", _result);
        outline1("LDD %s", address_displacement(_environment, _left, "2") );
        outline1("EORA %s", address_displacement(_environment, _right, "2") );
        outline1("EORB %s", address_displacement(_environment, _right, "3") );
        outline1("STD %s", address_displacement(_environment, _result, "2"));

    no_embedded( cpu_xor_32bit )

}

void cpu6809_swap_8bit( Environment * _environment, char * _left, char * _right ) {

    inline( cpu_swap_8bit )

        MAKE_LABEL

        outline1("LDA %s", _right );
        outline1("LDB %s", _left );
        outline1("STA %s", _left );
        outline1("STB %s", _right );

    no_embedded( cpu_swap_8bit )

}

void cpu6809_swap_16bit( Environment * _environment, char * _left, char * _right ) {

    inline( cpu_swap_16bit )

        MAKE_LABEL

        outline1("LDD %s", _right );
        outline1("LDU %s", _left );
        outline1("STD %s", _left );
        outline1("STU %s", _right );

    no_embedded( cpu_swap_16bit )

}

void cpu6809_swap_32bit( Environment * _environment, char * _left, char * _right  ) {

    inline( cpu_swap_32bit )

        MAKE_LABEL

        outline1("LDD %s", _right );
        outline1("LDU %s", _left );
        outline1("STD %s", _left );
        outline1("STU %s", _right );

        outline1("LDD %s", address_displacement(_environment, _right, "2") );
        outline1("LDU %s", address_displacement(_environment, _left, "2") );
        outline1("STD %s", address_displacement(_environment, _left, "2") );
        outline1("STU %s", address_displacement(_environment, _right, "2") );

    no_embedded( cpu_swap_32bit )

}

void cpu6809_logical_not_8bit( Environment * _environment, char * _value, char * _result ) {

    inline( cpu_logical_not_8bit )

        outline1("LDB %s", _value );
        outline0("COMA" );
        outline1("STB %s", _result );

    no_embedded( cpu_logical_not_8bit )

}

void cpu6809_not_8bit( Environment * _environment, char * _value, char * _result ) {

    inline( cpu_not_8bit )

        outline1("LDB %s", _value );
        outline0("COMB" );
        outline1("STB %s", _result );

    no_embedded( cpu_not_8bit )

}

void cpu6809_not_16bit( Environment * _environment, char * _value, char * _result ) {

    inline( cpu_not_16bit )

        outline1("LDD %s", _value );
        outline0("COMA" );
        outline0("COMB" );
        outline1("STD %s", _result );

    no_embedded( cpu_not_16bit )

}

void cpu6809_not_32bit( Environment * _environment, char * _value, char * _result ) {

    inline( cpu_not_32bit )

        outline1("LDD %s", _value );
        outline0("COMA" );
        outline0("COMB" );
        outline1("STD %s", _result );
        outline1("LDD %s", address_displacement(_environment, _value, "2") );
        outline0("COMA" );
        outline0("COMB" );
        outline1("STD %s", address_displacement(_environment, _result, "2") );

    no_embedded( cpu_not_32bit )

}

void cpu6809_di( Environment * _environment ) {

}

void cpu6809_ei( Environment * _environment ) {

}

void cpu6809_inc( Environment * _environment, char * _variable ) {

    inline( cpu_inc )

        outline1("INC %s", _variable );

    no_embedded( cpu_inc )

}

void cpu6809_inc_16bit( Environment * _environment, char * _variable ) {

    inline( cpu_inc_16bit )

        // 16 cycles all times, but extra possibilites for peephole
        // outline0("LDD #1" );
        // outline1("ADDD %s", _variable );
        // outline1("STD %s", _variable );

        MAKE_LABEL

        // 10 cycles 255 times out of 256 and 17 one out of 256
        outline1("INC %s", address_displacement(_environment, _variable, "1"));
        outline1("BNE %s", label);
        outline1("INC %s", _variable);
        outhead1("%s", label)

    no_embedded( cpu_inc_16bit )

}

void cpu6809_inc_32bit( Environment * _environment, char * _variable ) {

    inline( cpu_inc_32bit )

        // outline1("LDD %s", address_displacement(_environment, _variable, "2") );
        // outline0("ADDD #1" );
        // outline1("STD %s", address_displacement(_environment, _variable, "2") );
        // outline1("LDD %s", _variable );
        // outline0("ADCB #0" );
        // outline0("ADCA #0" );
        // outline1("STD %s", _variable );

        MAKE_LABEL

        outline1("INC %s", address_displacement(_environment, _variable, "3"));
        outline1("BNE %s", label);
        outline1("INC %s", address_displacement(_environment, _variable, "2"));
        outline1("BNE %s", label);
        outline1("INC %s", address_displacement(_environment, _variable, "1"));
        outline1("BNE %s", label);
        outline1("INC %s", _variable);
        outhead1("%s", label)

    no_embedded( cpu_inc_32bit )

}

void cpu6809_dec( Environment * _environment, char * _variable ) {

    inline( cpu_dec )

        outline1("DEC %s", _variable );

    no_embedded( cpu_dec )

}

void cpu6809_dec_16bit( Environment * _environment, char * _variable ) {

    inline( cpu_dec_16bit )

        outline1("LDD %s", _variable );
        outline0("SUBD #1" );
        outline1("STD %s", _variable );

    no_embedded( cpu_dec_16bit )

}

void cpu6809_mem_move( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    inline( cpu_mem_move )

        MAKE_LABEL

        outline1("LDB %s", _size );
        outline1("BEQ %sdone", label );

        outline1("LDY %s", _source );
        outline1("LDX %s", _destination );

        outline0("ANDB #$80" );
        outline1("BEQ %sloop2", label );
        outline0("LDB #$7F" );
        outline0("DECB" );
        outhead1("%s", label );
        outline0("LDA B,Y" );
        outline0("STA B,X" );
        outline0("DECB" );
        outline0("CMPB #$FF" );
        outline1("BNE %s", label );
        outline0("LEAY 127,Y" );
        outline0("LEAX 127,X" );
        outline0("LEAY 1,Y" );
        outline0("LEAX 1,X" );

        outhead1("%sloop2", label );
        outline1("LDB %s", _size );
        outline0("ANDB #$7F" );
        outline1("BEQ %sdone", label );
        outline0("DECB" );
        outhead1("%s_2", label );
        outline0("LDA B,Y" );
        outline0("STA B,X" );
        outline0("DECB" );
        outline0("CMPB #$FF" );
        outline1("BNE %s_2", label );
        outhead1("%sdone", label );

    embedded( cpu_mem_move, src_hw_6809_cpu_mem_move_asm )

        outline0("LDA #0" );
        outline1("LDB %s", _size );
        outline0("TFR D, U" );
        outline1("LDY %s", _source );
        outline1("LDX %s", _destination );
        outline0("JSR CPUMEMMOVE" );

    done( )

}

void cpu6809_mem_move_16bit( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    inline( cpu_mem_move )

        CRITICAL( "Inline cpu6809_mem_move_16bit is not available!");

    embedded( cpu_mem_move, src_hw_6809_cpu_mem_move_asm )

        outline1("LDD %s", _size );
        outline0("TFR D, U" );
        outline1("LDY %s", _source );
        outline1("LDX %s", _destination );
        outline0("JSR CPUMEMMOVE" );

    done( )

}

void cpu6809_mem_move_direct( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    inline( cpu_mem_move )

        MAKE_LABEL

        outline1("LDB %s", _size );
        outline1("BEQ %sdone", label );

        outline1("LDY #%s", _source );
        outline1("LDX #%s", _destination );

        outline0("ANDA #$80" );
        outline1("BEQ %sloop2", label );
        outline0("LDB #$7F" );
        outline0("DECB" );
        outhead1("%s", label );
        outline0("LDA B,Y" );
        outline0("STA B,X" );
        outline0("DECB" );
        outline0("CMPB #$FF" );
        outline1("BNE %s", label );
        outline0("LEAY 127,Y" );
        outline0("LEAX 127,X" );
        outline0("LEAY 1,Y" );
        outline0("LEAX 1,X" );

        outhead1("%sloop2", label );
        outline1("LDB %s", _size );
        outline0("ANDA #$7F" );
        outline1("BEQ %sdone", label );
        outline0("DECB" );
        outhead1("%s_2", label );
        outline0("LDA B,Y" );
        outline0("STA B,X" );
        outline0("DECB" );
        outline0("CMPB #$FF" );
        outline1("BNE %s_2", label );
        outhead1("%sdone", label );

    embedded( cpu_mem_move, src_hw_6809_cpu_mem_move_asm )

        outline0("LDA #0" );
        outline1("LDB %s", _size );
        outline0("TFR D, U" );
        outline1("LDY #%s", _source );
        outline1("LDX #%s", _destination );
        outline0("JSR CPUMEMMOVE" );

    done( )

}

void cpu6809_mem_move_direct2( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    inline( cpu_mem_move )

        MAKE_LABEL

        outline1("LDU %s", _size );
        outline0("CMPU #$0" );
        outline1("BEQ %sdone", label );

        outline1("LDY %s", _source );
        outline1("LDX #%s", _destination );

        outhead1("%s", label );
        outline0("LDA ,Y+" );
        outline0("STA ,X+" );
        outline0("LEAU -1, U" );
        outline0("CMPU #$0" );
        outline1("BNE %s", label );

    embedded( cpu_mem_move, src_hw_6809_cpu_mem_move_asm )

        outline1("LDU %s", _size );
        outline1("LDY %s", _source );
        outline1("LDX #%s", _destination );
        outline0("JSR CPUMEMMOVE" );

    done( )

}

void cpu6809_mem_move_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    inline( cpu_mem_move )

        MAKE_LABEL

        if ( _size ) {

            outline1("LDY %s", _source );
            outline1("LDX %s", _destination );

            if ( _size >= 0x7f ) {

                outline0("LDB #$7F" );
                outline0("DECB" );
                outhead1("%s", label );
                outline0("LDA B,Y" );
                outline0("STA B,X" );
                outline0("DECB" );
                outline0("CMPB #$FF" );
                outline1("BNE %s", label );
                outline0("LEAY 127,Y" );
                outline0("LEAX 127,X" );
                outline0("LEAY 1,Y" );
                outline0("LEAX 1,X" );

                _size -= 0x7f;

            }

            if ( _size ) {

                outline1("LDB #$%2.2x", ( _size & 0xff ) );
                outline0("DECB" );
                outhead1("%s_2", label );
                outline0("LDA B,Y" );
                outline0("STA B,X" );
                outline0("DECB" );
                outline0("CMPB #$FF" );
                outline1("BNE %s_2", label );

            }

        }

    embedded( cpu_mem_move, src_hw_6809_cpu_mem_move_asm )

        outline1("LDU #$%4.4x", _size );
        outline1("LDY %s", _source );
        outline1("LDX %s", _destination );
        outline0("JSR CPUMEMMOVE" );

    done( )

}

void cpu6809_mem_move_direct_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    inline( cpu_mem_move )

        MAKE_LABEL

        if ( _size ) {

            outline1("LDY #%s", _source );
            outline1("LDX #%s", _destination );

            if ( _size >= 0x7f ) {

                outline0("LDB #$7F" );
                outline0("DECB" );
                outhead1("%s", label );
                outline0("LDA B,Y" );
                outline0("STA B,X" );
                outline0("DECB" );
                outline0("CMPB #$FF" );
                outline1("BNE %s", label );
                outline0("LEAY 127,Y" );
                outline0("LEAX 127,X" );
                outline0("LEAY 1,Y" );
                outline0("LEAX 1,X" );

                _size -= 0x7f;

            }

            if ( _size ) {

                outline1("LDB #$%2.2x", ( _size & 0xff ) );
                outline0("DECB" );
                outhead1("%s_2", label );
                outline0("LDA B,Y" );
                outline0("STA B,X" );
                outline0("DECB" );
                outline0("CMPB #$FF" );
                outline1("BNE %s_2", label );

            }

        }

    embedded( cpu_mem_move, src_hw_6809_cpu_mem_move_asm )

        outline1("LDU #$%4.4x", _size );
        outline1("LDY #%s", _source );
        outline1("LDX #%s", _destination );
        outline0("JSR CPUMEMMOVE" );

    done( )

}

void cpu6809_mem_move_direct_indirect_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    inline( cpu_mem_move )

        MAKE_LABEL

        if ( _size ) {

            outline1("LDY #%s", _source );
            outline1("LDX %s", _destination );

            if ( _size >= 0x7f ) {

                outline0("LDB #$7F" );
                outline0("DECB" );
                outhead1("%s", label );
                outline0("LDA B,Y" );
                outline0("STA B,X" );
                outline0("DECB" );
                outline0("CMPB #$FF" );
                outline1("BNE %s", label );
                outline0("LEAY 127,Y" );
                outline0("LEAX 127,X" );
                outline0("LEAY 1,Y" );
                outline0("LEAX 1,X" );

                _size -= 0x7f;

            }

            if ( _size ) {

                outline1("LDB #$%2.2x", ( _size & 0xff ) );
                outline0("DECB" );
                outhead1("%s_2", label );
                outline0("LDA B,Y" );
                outline0("STA B,X" );
                outline0("DECB" );
                outline0("CMPB #$FF" );
                outline1("BNE %s_2", label );

            }

        }

    embedded( cpu_mem_move, src_hw_6809_cpu_mem_move_asm )

        outline1("LDU #$%4.4x", _size );
        outline1("LDY #%s", _source );
        outline1("LDX %s", _destination );
        outline0("JSR CPUMEMMOVE" );

    done( )

}

void cpu6809_compare_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    inline( cpu_compare_memory )

        MAKE_LABEL

        outline1("LDA %s", _size );
        outline1("BEQ %sequal", label );

        outline1("LDY %s", _source );
        outline1("LDX %s", _destination );

        outline1("LDA %s", _size );
        outline0("ANDA #$80" );
        outline1("BEQ %ssecond", label );

        outhead1("%sfirst", label );
        outline0("LDA #0" );
        outhead1("%sloop", label );
        outline0("LDB A,X" );
        outline0("CMPB A,Y" );
        outline1("BNE %sdiff", label );
        outline0("ADDA #1" );
        outline0("CMPA #$7F" );
        outline1("BNE %sloop", label );
        outline0("LEAY 127,Y" );
        outline0("LEAX 127,X" );
        outline0("LEAY 1,Y" );
        outline0("LEAX 1,X" );

        outhead1("%ssecond", label );
        outline1("LDA %s", _size );
        outline0("ANDA #$7f" );
        outline0("STA <MATHPTR0" );
        outline0("LDA #0" );
        outhead1("%sloop2", label );
        outline0("LDB A,X" );
        outline0("CMPB A,Y" );
        outline1("BNE %sdiff", label );
        outline0("ADDA #1" );
        outline0("CMPA <MATHPTR0" );
        outline1("BNE %sloop2", label );

        outhead1("%sequal", label );
        outline1("LDA #$%2.2x", _equal ? 0xff : 0x00 );
        outline1("STA %s", _result );
        outline1("JMP %sfinal", label );

        outhead1("%sdiff", label );
        outline1("LDA #$%2.2x", _equal ? 0x00 : 0xff );
        outline1("STA %s", _result );
        outhead1("%sfinal", label );

    no_embedded( cpu_compare_memory )

}

void cpu6809_compare_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    inline( cpu_compare_memory_size )

        MAKE_LABEL

        if ( _size ) {

            outline1("LDY %s", _source );
            outline1("LDX %s", _destination );

            if ( _size >= 0x7f ) {

                outhead1("%sfirst", label );
                outline0("LDA #0" );
                outhead1("%sloop", label );
                outline0("LDB A,X" );
                outline0("CMPB A,Y" );
                outline1("BNE %sdiff", label );
                outline0("ADDA #1" );
                outline0("CMPA #$7F" );
                outline1("BNE %sloop", label );
                outline0("LEAY 127,Y" );
                outline0("LEAX 127,X" );
                outline0("LEAY 1,Y" );
                outline0("LEAX 1,X" );

                _size -= 0x7f;

            }

            if ( _size ) {

                outhead1("%ssecond", label );
                outline1("LDA #$%2.2x", _size );
                outline0("STA <MATHPTR0" );
                outline0("LDA #0" );
                outhead1("%sloop2", label );
                outline0("LDB A,X" );
                outline0("CMPB A,Y" );
                outline1("BNE %sdiff", label );
                outline0("ADDA #1" );
                outline0("CMPA <MATHPTR0" );
                outline1("BNE %sloop2", label );

            }

            outhead1("%sequal", label );
            outline1("LDA #$%2.2x", _equal ? 0xff : 0x00 );
            outline1("STA %s", _result );
            outline1("JMP %sfinal", label );

            outhead1("%sdiff", label );
            outline1("LDA #$%2.2x", _equal ? 0x00 : 0xff );
            outline1("STA %s", _result );
            outhead1("%sfinal", label );

        }

    no_embedded( cpu_compare_memory_soze )

}

void cpu6809_less_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    inline( cpu_less_than_memory )

        MAKE_LABEL

        outline1("LDA %s", _size );
        outline1("BEQ %sequal", label );

        outline1("LDY %s", _destination );
        outline1("LDX %s", _source );

        outline1("LDA %s", _size );
        outline0("ANDA #$80" );
        outline1("BEQ %ssecond", label );

        outhead1("%sfirst", label );
        outline0("LDA #0" );
        outhead1("%sloop", label );
        outline0("LDB A,X" );
        outline0("CMPB A,Y" );
        if ( _equal ) {
            outline1("BHI %sdiff", label);
        } else {
            outline1("BHS %sdiff", label);
        }
        outline0("ADDA #1" );
        outline0("CMPA #$7F" );
        outline1("BNE %sloop", label );
        outline0("LEAY 127,Y" );
        outline0("LEAX 127,X" );
        outline0("LEAY 1,Y" );
        outline0("LEAX 1,X" );

        outhead1("%ssecond", label );
        outline1("LDA %s", _size );
        outline0("ANDA #$7f" );
        outline0("STA <MATHPTR0" );
        outline0("LDA #0" );
        outhead1("%sloop2", label );
        outline0("LDB A,X" );
        outline0("CMPB A,Y" );
        if ( _equal ) {
            outline1("BHI %sdiff", label);
        } else {
            outline1("BHS %sdiff", label);
        }
        outline0("ADDA #1" );
        outline0("CMPA <MATHPTR0" );
        outline1("BNE %sloop2", label );

        outhead1("%sequal", label );
        outline0("LDA #$FF");
        outline1("STA %s", _result );
        outline1("JMP %sfinal", label );

        outhead1("%sdiff", label );
        outline0("LDA #$0");
        outline1("STA %s", _result );
        outhead1("%sfinal", label );

    no_embedded( cpu_less_than_memory )

}

void cpu6809_less_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    inline( cpu_less_than_memory_size )

        MAKE_LABEL

        if ( _size ) {

            outline1("LDY %s", _destination );
            outline1("LDX %s", _source );

            if ( _size >= 0x7f ) {

                outhead1("%sfirst", label );
                outline0("LDA #0" );
                outhead1("%sloop", label );
                outline0("LDB A,X" );
                outline0("CMPB A,Y" );
                if ( _equal ) {
                    outline1("BHI %sdiff", label);
                } else {
                    outline1("BHS %sdiff", label);
                }
                outline0("ADDA #1" );
                outline0("CMPA #$7F" );
                outline1("BNE %sloop", label );
                outline0("LEAY 127,Y" );
                outline0("LEAX 127,X" );
                outline0("LEAY 1,Y" );
                outline0("LEAX 1,X" );

                _size -= 0x7f;

            }

            if ( _size ) {

                outhead1("%ssecond", label );
                outline1("LDA #$%2.2x", _size );
                outline0("STA <MATHPTR0" );
                outline0("LDA #0" );
                outhead1("%sloop2", label );
                outline0("LDB A,X" );
                outline0("CMPB A,Y" );
                if ( _equal ) {
                    outline1("BHI %sdiff", label);
                } else {
                    outline1("BHS %sdiff", label);
                }
                outline0("ADDA #1" );
                outline0("CMPA <MATHPTR0" );
                outline1("BNE %sloop2", label );

            }

            outhead1("%sequal", label );
            outline0("LDA #$FF");
            outline1("STA %s", _result );
            outline1("JMP %sfinal", label );

            outhead1("%sdiff", label );
            outline0("LDA #$0");
            outline1("STA %s", _result );
            outhead1("%sfinal", label );

        }

    no_embedded( cpu_less_than_memory_size )

}

void cpu6809_greater_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    inline( cpu_greater_than_memory )

        MAKE_LABEL

        outline1("LDA %s", _size );
        outline1("BEQ %sequal", label );

        outline1("LDY %s", _destination );
        outline1("LDX %s", _source );

        outline1("LDA %s", _size );
        outline0("ANDA #$80" );
        outline1("BEQ %ssecond", label );

        outhead1("%sfirst", label );
        outline0("LDA #0" );
        outhead1("%sloop", label );
        outline0("LDB A,X" );
        outline0("CMPB A,Y" );
        if ( _equal ) {
            outline1("BLO %sdiff", label);
        } else {
            outline1("BLS %sdiff", label);
        }
        outline0("ADDA #1" );
        outline0("CMPA #$7F" );
        outline1("BNE %sloop", label );
        outline0("LEAY 127,Y" );
        outline0("LEAX 127,X" );
        outline0("LEAY 1,Y" );
        outline0("LEAX 1,X" );

        outhead1("%ssecond", label );
        outline1("LDA %s", _size );
        outline0("ANDA #$7f" );
        outline0("STA <MATHPTR0" );
        outline0("LDA #0" );
        outhead1("%sloop2", label );
        outline0("LDB A,X" );
        outline0("CMPB A,Y" );
        if ( _equal ) {
            outline1("BLO %sdiff", label);
        } else {
            outline1("BLS %sdiff", label);
        }
        outline0("ADDA #1" );
        outline0("CMPA <MATHPTR0" );
        outline1("BNE %sloop2", label );

        outhead1("%sequal", label );
        outline0("LDA #$FF");
        outline1("STA %s", _result );
        outline1("JMP %sfinal", label );

        outhead1("%sdiff", label );
        outline0("LDA #$0");
        outline1("STA %s", _result );
        outhead1("%sfinal", label );

    no_embedded( cpu_greater_than_memory )

}

void cpu6809_greater_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    inline( cpu_greater_than_memory_size )

        MAKE_LABEL

        if ( _size ) {

            outline1("LDY %s", _destination );
            outline1("LDX %s", _source );

            if ( _size >= 0x7f ) {

                outhead1("%sfirst", label );
                outline0("LDA #0" );
                outhead1("%sloop", label );
                outline0("LDB A,X" );
                outline0("CMPB A,Y" );
                if ( _equal ) {
                    outline1("BLO %sdiff", label);
                } else {
                    outline1("BLS %sdiff", label);
                }
                outline0("ADDA #1" );
                outline0("CMPA #$7F" );
                outline1("BNE %sloop", label );
                outline0("LEAY 127,Y" );
                outline0("LEAX 127,X" );

                _size -= 0x7f;

            }

            if ( _size ) {

                outhead1("%ssecond", label );
                outline1("LDA #$%2.2x", _size );
                outline0("STA <MATHPTR0" );
                outline0("LDA #0" );
                outhead1("%sloop2", label );
                outline0("LDB A,X" );
                outline0("CMPB A,Y" );
                if ( _equal ) {
                    outline1("BLO %sdiff", label);
                } else {
                    outline1("BLS %sdiff", label);
                }
                outline0("ADDA #1" );
                outline0("CMPA <MATHPTR0" );
                outline1("BNE %sloop2", label );

            }

            outhead1("%sequal", label );
            outline0("LDA #$FF");
            outline1("STA %s", _result );
            outline1("JMP %sfinal", label );

            outhead1("%sdiff", label );
            outline0("LDA #$0");
            outline1("STA %s", _result );
            outhead1("%sfinal", label );

        }

    no_embedded( cpu_greater_than_memory_size )

}

void cpu6809_move_8bit_indirect( Environment * _environment, char *_source, char * _value ) {

    inline( cpu_move_8bit_indirect )

        outline1("LDB %s", _source);
        outline1("STB [%s]", _value);

    no_embedded( cpu_move_8bit_indirect )

}

void cpu6809_move_8bit_indirect_with_offset( Environment * _environment, char *_source, char * _value, int _offset ) {

    inline( cpu_move_8bit_with_offset )

        outline1("LDB %s", _source);
        outline1("LDX %s", _value);
        outline1("STB %d,X", _offset );

    no_embedded( cpu_move_8bit_with_offset )

}

void cpu6809_move_8bit_indirect_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

    inline( cpu_move_8bit_indirect_with_offset2 )

        MAKE_LABEL

        outline1("LDA %s", _source);
        outline1("LDX %s", _value);
        outline1("LDB %s", _offset);
        outline0("ABX");
        outline0("STA ,X");

    no_embedded( cpu_move_8bit_indirect_with_offset2 )

}

void cpu6809_move_8bit_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

    inline( cpu_move_8bit_with_offset2 )

        MAKE_LABEL

        outline1("LDX %s", _value);

        outline1("LDA %s", _offset);
        outline0("ANDA #$80");
        outline1("BEQ %ssimple", label);

        outline0("LEAX 127,X" );
        outline0("LEAX 1,X" );
        outline1("LDA %s", _offset);
        outline0("ANDA #$7f");
        outline0("LEAX A,X" );
        outline1("JMP %sdone", label);

        outhead1("%ssimple", label);
        outline1("LDA %s", _offset);
        outline0("ANDA #$7f");
        outline0("LEAX A,X" );

        outhead1("%sdone", label);

        outline1("LDA %s", _source);
        outline0("STA ,X");

    no_embedded( cpu_move_8bit_indirect_with_offset2 )

}

void cpu6809_move_8bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    inline( cpu_move_8bit_indirect2 )

        MAKE_LABEL

        outline1("LDB [%s]", _value);
        outline1("STB %s", _source );

    no_embedded( cpu_move_8bit_indirect_with_offset2 )

}

void cpu6809_move_8bit_indirect2_8bit( Environment * _environment, char * _value, char * _offset, char *_source ) {

    inline( cpu_move_8bit_indirect2_8bit )

        MAKE_LABEL

        outline1("LDX #%s", _value);
        outline0("LDA #$0");
        outline1("LDB %s", _offset);
        outline0("LEAX D,X");
        outline0("LDA ,X");
        outline1("STA %s", _source);

    no_embedded( cpu_move_8bit_indirect2_8bit )

}

void cpu6809_move_16bit_indirect( Environment * _environment, char *_source, char * _value ) {

    inline( cpu_move_16bit_indirect )

        MAKE_LABEL

        outline1("LDD %s", _source);
        outline1("STD [%s]", _value);

    no_embedded( cpu_move_16bit_indirect )

}

void cpu6809_move_16bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    inline( cpu_move_16bit_indirect2 )

        MAKE_LABEL

        outline1("LDD [%s]", _value);
        outline1("STD %s", _source );

    no_embedded( cpu_move_16bit_indirect2 )

}

void cpu6809_move_16bit_indirect2_8bit( Environment * _environment, char * _value, char * _offset, char *_source ) {

    inline( cpu_move_16bit_indirect2_8bit )

        MAKE_LABEL

        outline1("LDX #%s", _value);
        outline0("LDA #$0");
        outline1("LDB %s", _offset);
        outline0("LEAX D,X");
        outline0("LEAX D,X");
        outline0("LDD ,X");
        outline1("STD %s", _source);

    no_embedded( cpu_move_8bit_indirect2_8bit )

}

void cpu6809_move_32bit_indirect( Environment * _environment, char *_source, char * _value ) {

    inline( cpu_move_32bit_indirect )

        MAKE_LABEL

        outline1("LDX %s", _value);
        outline0("LDD ,X");
        outline1("STD %s", _source );
        outline0("LDD 2,X");
        outline1("STD %s", address_displacement(_environment, _source, "2") );

    no_embedded( cpu_move_32bit_indirect )

}

void cpu6809_move_32bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    inline( cpu_move_32bit_indirect2 )

        MAKE_LABEL

        outline1("LDX %s", _value);
        outline0("LDD ,X");
        outline1("STD %s", _source );
        outline0("LDD 2,X");
        outline1("STD %s", address_displacement(_environment, _source, "2") );

    no_embedded( cpu_move_32bit_indirect2 )

}

void cpu6809_uppercase( Environment * _environment, char *_source, char *_size, char *_result ) {

    inline( cpu_uppercase )

        MAKE_LABEL

        outline1("LDA %s ", _size );
        B(EQ, label);
        outline1("LDX %s", _source );
        if ( _result ) {
            outline1("LDU %s", _result );
        } else {
            outline1("LDU %s", _source );
        }
        outhead1("%supper", label );
        outline0("LDB ,X+" );

        outline0("CMPB #97");
        outline1("BLO %snext", label);

        outline0("CMPB #122");
        outline1("BHI %snext", label);

        outline0("SUBB #32");

        outhead1("%snext", label );
        outline0("STB ,U+" );
        outline0("DECA" );
        outline1("BNE %supper", label );

        outhead1("%s", label );

    no_embedded( cpu_uppercase )


}

void cpu6809_lowercase( Environment * _environment, char *_source, char *_size, char *_result ) {

    inline( cpu_lowercase )

        MAKE_LABEL

        outline1("LDA %s ", _size );
        B(EQ, label);
        outline1("LDX %s", _source );
        if ( _result ) {
            outline1("LDU %s", _result );
        } else {
            outline1("LDU %s", _source );
        }
        outhead1("%supper", label );
        outline0("LDB ,X+" );

        outline0("CMPB #65");
        outline1("BLO %snext", label);

        outline0("CMPB #90");
        outline1("BHI %snext", label);

        outline0("ADDB #32");

        outhead1("%snext", label );
        outline0("STB ,U+" );
        outline0("DECA" );
        outline1("BNE %supper", label );

        outhead1("%s", label );

    no_embedded( cpu_lowercase )

}

void cpu6809_convert_string_into_16bit( Environment * _environment, char * _string, char * _len, char * _value ) {

    inline( cpu_convert_string_into_16bit )

        MAKE_LABEL

        // Y = 0
        outline1("LDB %s", _len);
        outline1("beq %sdone", label );
        outline0("STB ,-S");
        outline1("LDU %s", _string);

        outline0("LDX #0");
        outhead1("%sloop", label );
        
        // X=X*10
        outline0("TFR X,D");    //6
        outline0("LSLB");       //2
        outline0("ROLA");       //2
        outline0("TFR D,X");    //6 D=X=2val
        outline0("LSLB");       //2 
        outline0("ROLA");       //2 D=4val
        outline0("LSLB");       //2 
        outline0("ROLA");       //2 D=8val
        outline0("LEAX D,X");   //8 D=8val+2val=10val (32 cycles)
                
        // leggo carattere
        outline0("LDB ,U+" );

        // numero? no -> fine
        outline0("SUBB #48" );
        outline1("BMI %sdone", label );
        outline0("CMPB #9" );
        outline1("BHI %sdone", label );

        // aggiungo il numero al registro X
        outline0("ABX");
        
        // ripeti
        outline0("DEC ,S" );
        outline1("BNE %sloop", label );
        outline0("LEAS 1,S");

        outhead1("%sdone", label );
        outline1("STX %s", _value );

    no_embedded( cpu_convert_string_into_16bit )

}

void cpu6809_fill_indirect( Environment * _environment, char * _address, char * _size, char * _pattern ) {

    inline( cpu_fill_indirect )

        MAKE_LABEL

        outline1("LDB %s", _size);
        outline0("LDA #0");
        outline0("LEAY D,Y");
        outline1("LDX %s", _pattern );
        outline0("LDA ,X" );
        outline1("LDX %s", _address);
        outhead1("%s", label);
        outhead1("%sinner", label);
        outline0("DECB");
        outline0("STA B,X");
        outline0("CMPB #$ff");
        outline1("BNE %sinner", label);

    no_embedded( cpu_fill_indirect )

}

void cpu6809_flip( Environment * _environment, char * _source, char * _size, char * _destination ) {

    inline( cpu_flip )

        MAKE_LABEL

        outline1("LDU %s", _source);
        outline1("LDX %s", _destination);
        outline1("LDB %s", _size);
        outline1("BEQ %sdone", label);
        outline0("ABX");
        outhead1("%sx", label);
        outline0("LDA ,U+");
        outline0("STA ,-X");
        outline0("DECB");
        outline1("BNE %sx", label);
        outhead1("%sdone", label);

    no_embedded( cpu_flip )

}

void cpu6809_bit_check( Environment * _environment, char * _value, int _position, char *_result, int _bitwidth ) {

    inline( cpu_bit_check )

        MAKE_LABEL

        //outline0("STB <MATHPTR0" );
        switch( _position ) {
            case 31: case 30: case 29: case 28: case 27: case 26: case 25: case 24:
                outline1("LDB %s", _value);
                break;
            case 23: case 22: case 21: case 20: case 19: case 18: case 17: case 16:
                outline1("LDB %s", address_displacement(_environment, _value, "1"));
                break;
            case 15: case 14: case 13: case 12: case 11: case 10: case 9: case 8:
                outline2("LDB %s+%d", _value, ( _bitwidth / 8 ) - 2 );
                break;
            case 7:  case 6:  case 5:  case 4:  case 3:  case 2:  case 1: case 0:
                outline2("LDB %s+%d", _value, ( _bitwidth / 8 ) - 1 );
                break;
        }
        outline1("ANDB #$%2.2x", 1 << ( ( _position ) & 0x07 ) );
        outline1("BEQ %send", label);
        outline0("LDB #$ff");
        outhead1("%send", label)
        outline1("STB %s", _result);

    no_embedded( cpu_bit_check )

}

void cpu6809_bit_check_extended( Environment * _environment, char * _value, char * _position, char *_result, int _bitwidth ) {

    static int shift_tab = 0;
    
    inline( cpu_bit_check_extended )

        MAKE_LABEL
        
        if(!shift_tab) {
            shift_tab = 1;
            outline0("BRA _bit_check_extended_tab_after");
            outhead0("bit_check_extended_tab");
            outline0("fcb 1,2,4,8,16,32,64,128");
            outhead0("_bit_check_extended_tab_after");
        }
        
        outline2("LDB %s+%d", _value, ( _bitwidth / 8 ) - 1 );
        outline1("LDA %s", _position);
        if(_bitwidth>8) {
            outline0("CMPA #8");
            outline1("BLO %seval", label);
            outline2("LDB %s+%d", _value, ( _bitwidth / 8 ) - 2 );
        }
        if(_bitwidth>16) {
            outline0("CMPA #16");
            outline1("BLO %seval", label);
            outline1("LDB %s", address_displacement(_environment, _value, "1"));
            outline0("CMPA #24");
            outline1("BLO %seval", label);
            outline1("LDB %s", _value);
        }
        
        outhead1("%seval", label );
        outline0("LDX #bit_check_extended_tab");
        outline1("LDA %s", _position);
        outline0("ANDA #7");
        outline0("ANDB A,X");
        
        outline1("BEQ %send", label);
        outline0("LDB #$ff");
        outhead1("%send", label)
        outline1("STB %s", _result);
        
    no_embedded( cpu_bit_check_extended )

}

void cpu6809_number_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits, int _signed ) {

    MAKE_LABEL

    deploy( numberToString, src_hw_6809_number_to_string_asm );
	

    switch( _bits ) {
        case 32:
			outline1("LDD %s", address_displacement(_environment, _number, "2") );
            outline0("STD <MATHPTR2");
            outline1("LDD %s", _number );
            outline0("STD <MATHPTR0");
            if ( _signed ) {
                outline0("STA <MATHPTR4");
                outline1("BPL %spositive", label );
                cpu6809_complement2_32bit( _environment, "<MATHPTR0", NULL);
                outhead1("%spositive", label );
            } else {
                outline0("CLR <MATHPTR4");
            }
            break;
        case 16:
            outline1("LDD %s", _number );
            outline0("STD <MATHPTR2");
            if ( _signed ) {
                outline0("STA <MATHPTR4");
                outline1("BPL %spositive", label );
                cpu6809_complement2_16bit( _environment, "<MATHPTR2", NULL);
                outhead1("%spositive", label );
            }
            outline0("LDD #0");
            outline0("STD <MATHPTR0");
            if ( !_signed ) outline0("STA <MATHPTR4");
            break;
        case 8:
            outline1("LDB %s", _number );
            outline0("CLRA");
            outline0("STD <MATHPTR2");
            if ( _signed && _bits == 8 ) {
                outline0("STB <MATHPTR4");
                outline1("BPL %spositive", label );
                cpu6809_complement2_8bit( _environment, "<MATHPTR3", NULL);
                outhead1("%spositive", label );
            }
            outline0("CLRB");
            outline0("STD <MATHPTR0");
            if ( !_signed ) outline0("STA <MATHPTR4");
            break;
    }


    outline1("LDX %s", _string );
    outline1("LDA #$%2.2X", _bits );
    outline0("JSR N2STRING");

    outline1("STA %s", _string_size);

}

void cpu6809_bits_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits ) {

    deploy( bitsToString, src_hw_6809_bits_to_string_asm );

    switch( _bits ) {
        case 32:
            outline1("LDD %s", _number );
            outline0("STD <MATHPTR0" );
            outline1("LDD %s", address_displacement(_environment, _number, "2") );
            outline0("STD <MATHPTR2" );
            outline0("LDB #32" );
            outline1("STB %s", _string_size );
            break;
        case 16:
            outline0("LDD #0" );
            outline0("STD <MATHPTR0" );
            outline1("LDD %s", _number );
            outline0("STD <MATHPTR2" );
            outline0("LDB #16" );
            outline1("STB %s", _string_size );
            break;
        case 8:
            outline0("LDD #0" );
            outline0("STD <MATHPTR0" );
            outline0("LDA #0" );
            outline0("STA <MATHPTR2" );
            outline1("LDA %s", _number );
            outline0("STA <MATHPTR3" );
            outline0("LDB #8" );
            outline1("STB %s", _string_size );
            break;
    }

    outline1("LDB #$%2.2x", _bits );
    outline0("JSR BINSTR");

    cpu6809_mem_move_direct_indirect_size( _environment, "BINSTRBUF", _string, _bits );

}

void cpu6809_hex_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits ) {

    MAKE_LABEL

    inline( cpu_hex_to_string )

    embedded( cpu_hex_to_string, src_hw_6809_cpu_hex_to_string_asm );

        outline1("LDB #$%2.2x", ( _bits >> 3 ) );
        outline1("LDX #%s", _number );
        outline1("LDY %s", _string );
        
        outline0("JSR H2STRING" );

        outline1("LDB #$%2.2x", ( _bits >> 2 ) );
        outline1("STB %s", _string_size );

    done()

}

void cpu6809_dsdefine( Environment * _environment, char * _string, char * _index ) {

    deploy( dstring, src_hw_6809_dstring_asm );

    outline1( "LDY #%s", _string );
    outline0( "JSR DSDEFINE" );
    outline1( "STB %s", _index );

}

void cpu6809_dsalloc( Environment * _environment, char * _size, char * _index ) {

    deploy( dstring, src_hw_6809_dstring_asm );

    outline1( "LDA %s", _size );
    outline0( "JSR DSALLOC" );
    outline1( "STB %s", _index );

}

void cpu6809_dsalloc_size( Environment * _environment, int _size, char * _index ) {

    deploy( dstring, src_hw_6809_dstring_asm );

    outline1( "LDA #$%2.2x", _size );
    outline0( "JSR DSALLOC" );
    outline1( "STB %s", _index );

}

void cpu6809_dsfree( Environment * _environment, char * _index ) {

    deploy( dstring, src_hw_6809_dstring_asm );

    outline1( "LDB %s", _index );
    outline0( "JSR DSFREE" );

}

void cpu6809_dswrite( Environment * _environment, char * _index ) {

    deploy( dstring, src_hw_6809_dstring_asm );

    outline1( "LDB %s", _index );
    outline0( "JSR DSWRITE" );

}

void cpu6809_dsresize( Environment * _environment, char * _index, char * _resize ) {

    deploy( dstring, src_hw_6809_dstring_asm );

    outline1( "LDB %s", _index );
    outline1( "LDA %s", _resize );
    outline0( "JSR DSRESIZE" );

}

void cpu6809_dsresize_size( Environment * _environment, char * _index, int _resize ) {

    deploy( dstring, src_hw_6809_dstring_asm );

    outline1( "LDB %s", _index );
    outline1( "LDA #$%2.2X", _resize );
    outline0( "JSR DSRESIZE" );

}

void cpu6809_dsgc( Environment * _environment ) {

    deploy( dstring, src_hw_6809_dstring_asm );

    outline0( "JSR DSGC" );

}

void cpu6809_dsdescriptor( Environment * _environment, char * _index, char * _address, char * _size ) {

    deploy( dstring,src_hw_6809_dstring_asm );

    outline1( "LDB %s", _index );
    outline0( "JSR DSDESCRIPTOR" );
    outline0( "LDD 1, X" );
    outline1( "STD %s", _address );
    outline0( "LDA , X" );
    outline1( "STA %s", _size );

}

void cpu6809_store_8bit_with_offset( Environment * _environment, char *_destination, int _value, int _offset ) {

    outline1("LDX %s", _destination);
    outline1("LDB #$%2.2x", _value);
    outline1("STB $%2.2x,X", _offset);

}

void cpu6809_complement2_8bit( Environment * _environment, char * _source, char * _destination ) {

    if ( _destination ) {
        outline1( "LDB %s", _source );
        outline0( "NEGB");
        outline1( "STB %s", _destination );
    } else {
        outline1( "NEG %s", _source );
    }

}

void cpu6809_complement2_16bit( Environment * _environment, char * _source, char * _destination ) {

    outline1( "LDD %s", _source );
    outline0( "NEGA" );
    outline0( "NEGB" );
    outline0( "SBCA #0" );
    if ( _destination ) {
        outline1( "STD %s", _destination );
    } else {
        outline1( "STD %s", _source );
    }

}

void cpu6809_complement2_32bit( Environment * _environment, char * _source, char * _destination ) {
    char *out = _destination ?_destination : _source;

    MAKE_LABEL
    
    outline1( "LDD %s", _source );
    outline0( "COMA");
    outline0( "COMB");
    outline1( "STD %s", out );
    
    outline1( "LDD %s", address_displacement(_environment, _source, "2") );
    outline0( "NEGA" );
    outline0( "NEGB" );
    outline0( "SBCA #0" );
    outline1( "STD %s", address_displacement(_environment, out, "2") );
    
    outline1( "BNE %s", label);
    outline1( "INC %s", address_displacement(_environment, out, "1"));
    outline1( "BNE %s", label);
    outline1( "INC %s", out);
    outhead1( "%s", label);

}

void cpu6809_sqroot( Environment * _environment, char * _number, char * _result ) {

    deploy( sqr, src_hw_6809_sqr_asm );

    outline1("LDD %s", _number );
    outline0("STA <Numberh" );
    outline0("STB <Numberl" );

    outline0("JSR SQROOT" );

    outline0("LDB <Root" );
    outline1("STB %s", _result );

}

void cpu6809_dstring_vars( Environment * _environment ) {

    int count = _environment->dstring.count == 0 ? DSTRING_DEFAULT_COUNT : _environment->dstring.count;
    int space = _environment->dstring.space == 0 ? DSTRING_DEFAULT_SPACE : _environment->dstring.space;

    outhead1("MAXSTRINGS                    equ %d", count );
    outhead1("DESCRIPTORS                   rzb %d", count * 4 );
    outhead1("WORKING                       rzb %d", space );
    outhead1("TEMPORARY                     rzb %d", space );
    outhead1("FREE_STRING                   fdb %d", space );

}

void cpu6809_protothread_vars( Environment * _environment ) {

    int count = _environment->protothreadConfig.count == 0 ? PROTOTHREAD_DEFAULT_COUNT : _environment->protothreadConfig.count;

    outhead1("PROTOTHREADLC       rzb        %d", count );
    outhead1("PROTOTHREADST       rzb        %d", count );
    outhead0("PROTOTHREADCT       fcb        0" );
    outhead0("PROTOTHREADLOOP");

    for( int i=0; i<count; ++i ) {
        outline1("LDB #%d-1", i+1 ); /* prevents optimizer changing code length */
        outline0("STB PROTOTHREADCT" );
        outline0("JSR PROTOTHREADVOID" );
    }

    outline0("RTS" );
    
}

void cpu6809_protothread_loop( Environment * _environment ) {

    deploy_with_vars( protothread, src_hw_6809_protothread_asm, cpu_protothread_vars );

    outline0("JSR PROTOTHREADLOOP" );

}

void cpu6809_protothread_register_at( Environment * _environment, char * _index, char * _label ) {

    deploy_with_vars( protothread, src_hw_6809_protothread_asm, cpu_protothread_vars );

    outline1("LDY #%s", _label );
    outline1("LDB %s", _index );

    outline0("JSR PROTOTHREADREGAT" );

}

void cpu6809_protothread_register( Environment * _environment, char * _label, char * _index ) {

    deploy_with_vars( protothread, src_hw_6809_protothread_asm, cpu_protothread_vars );

    outline1("LDY #%s", _label );

    outline0("JSR PROTOTHREADREG" );

    outline1("STB %s", _index );

}

void cpu6809_protothread_unregister( Environment * _environment, char * _index ) {

    deploy_with_vars( protothread, src_hw_6809_protothread_asm, cpu_protothread_vars );

    outline1("LDB %s", _index );

    outline0("JSR PROTOTHREADUNREG" );

}

void cpu6809_protothread_save( Environment * _environment, char * _index, int _step ) {

    deploy_with_vars( protothread, src_hw_6809_protothread_asm, cpu_protothread_vars );

    outline1("LDB %s", _index );
    outline1("LDA #$%2.2x", _step );

    outline0("JSR PROTOTHREADSAVE" );

}

void cpu6809_protothread_restore( Environment * _environment, char * _index, char * _step ) {

    deploy_with_vars( protothread, src_hw_6809_protothread_asm, cpu_protothread_vars );

    outline1("LDB %s", _index );

    outline0("JSR PROTOTHREADRESTORE" );

    outline1("STA %s", _step );

}

void cpu6809_protothread_set_state( Environment * _environment, char * _index, int _state ) {

    deploy_with_vars( protothread, src_hw_6809_protothread_asm, cpu_protothread_vars );

    outline1("LDB %s", _index );
    outline1("LDA #$%2.2x", _state );

    outline0("JSR PROTOTHREADSETSTATE" );

}

void cpu6809_protothread_get_state( Environment * _environment, char * _index, char * _state ) {

    deploy_with_vars( protothread, src_hw_6809_protothread_asm, cpu_protothread_vars );

    outline1("LDB %s", _index );

    outline0("JSR PROTOTHREADGETSTATE" );

    outline1("STA %s", _state );

}

void cpu6809_protothread_current( Environment * _environment, char * _current ) {

    deploy_with_vars( protothread, src_hw_6809_protothread_asm, cpu_protothread_vars );

    outline0("LDB PROTOTHREADCT" );
    outline1("STB %s", _current );

}

void cpu6809_is_negative( Environment * _environment, char * _value, char * _result ) {

    inline( cpu_is_negative )

        outline1("LDB %s", _value);
        outline0("SEX");
        outline1("STA %s", _result );

    no_embedded( cpu_is_negative )

}

void cpu6809_set_callback( Environment * _environment, char * _callback, char * _label ) {

    outline1("LDY #%s", _label );
    outline1("LDU #%s", _callback );
    outline0("LEAU 1, U" );
    outline0("STY ,U" );

}

void cpu6809_msc1_uncompress_direct_direct( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_6809_msc1_asm );

        outline1("LDX #%s", _input);
        outline1("LDY #%s", _output);
        outline0("JSR MSC1UNCOMPRESS");

    done()

}

void cpu6809_msc1_uncompress_direct_indirect( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_6809_msc1_asm );

        outline1("LDX #%s", _input);
        outline1("LDY %s", _output);
        outline0("JSR MSC1UNCOMPRESS");

    done()

}

void cpu6809_msc1_uncompress_indirect_direct( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_6809_msc1_asm );

        outline1("LDX %s", _input);
        outline1("LDY #%s", _output);
        outline0("JSR MSC1UNCOMPRESS");

    done()

}

void cpu6809_msc1_uncompress_indirect_indirect( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_6809_msc1_asm );

        outline1("LDX %s", _input);
        outline1("LDY %s", _output);
        outline0("JSR MSC1UNCOMPRESS");

    done()

}

void cpu6809_out( Environment * _environment, char * _port, char * _value ) {

}

void cpu6809_in( Environment * _environment, char * _port, char * _value ) {
    
}

void cpu6809_out_direct( Environment * _environment, char * _port, char * _value ) {

}

void cpu6809_in_direct( Environment * _environment, char * _port, char * _value ) {
    
}


void cpu6809_string_sub( Environment * _environment, char * _source, char * _source_size, char * _pattern, char * _pattern_size, char * _destination, char * _destination_size ) {
    
    MAKE_LABEL

    inline( cpu_string_sub )

    embedded( cpu_string_sub, src_hw_6809_cpu_string_sub_asm );

        outline1("LDY %s", _source);
        outline1("LDA %s", _source_size);
        outline0("STA MATHPTR0");
        outline1("LDX %s", _pattern);
        outline1("LDA %s", _pattern_size);
        outline0("STA MATHPTR1");
        outline1("LDU %s", _destination);

        outline0("JSR CPUSTRINGSUB");

        outline0("LDA MATHPTR2");
        outline1("STA %s", _destination_size);

    done()
}

static char CPU6809_BLIT_REGISTER[][9] = {
    "BLITR0",
    "BLITR1",
    "BLITR2",
    "BLITR3"
};

#define CPU6809_BLIT_REGISTER_COUNT ( sizeof( CPU6809_BLIT_REGISTER ) / 9 )

void cpu6809_blit_initialize( Environment * _environment ) {

    _environment->blit.freeRegisters = 0;
    _environment->blit.usedMemory = 0;

}

void cpu6809_blit_finalize( Environment * _environment ) {

    _environment->blit.freeRegisters = 0;
    _environment->blit.usedMemory = 0;

}

char * cpu6809_blit_register_name(  Environment * _environment, int _register ) {
    
    if ( _register < CPU6809_BLIT_REGISTER_COUNT ) {
        return &CPU6809_BLIT_REGISTER[_register][0];
    } else {
        return &CPU6809_BLIT_REGISTER[ (_register & 0xff00) >> 8][0];
    }
}

int cpu6809_blit_alloc_register(  Environment * _environment ) {

    int reg = 0;

    for( reg = 0; reg < CPU6809_BLIT_REGISTER_COUNT; ++reg ) {
        int registerMask = ( 0x01 << reg );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( ! isRegisterUsed ) {
            _environment->blit.freeRegisters |= registerMask;
            return reg;
        }
    }

    int location = _environment->blit.usedMemory++;

    if ( location > 0xff ) {
        CRITICAL_BLIT_ALLOC_MEMORY_EXHAUSTED( );
    }

    for( reg = 0; reg < CPU6809_BLIT_REGISTER_COUNT; ++reg ) {
        int registerMask = ( 0x10 << reg );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( ! isRegisterUsed ) {
            outline1( "LDA %s", &CPU6809_BLIT_REGISTER[reg][0] );
            outline2( "STA _%sbs+$%2.2x",  _environment->blit.name, location );
            _environment->blit.freeRegisters |= registerMask;
            return ( ( reg << 8 ) | location );
        }
    }

    CRITICAL_BLIT_ALLOC_REGISTER_EXHAUSTED( );

}

void cpu6809_blit_free_register(  Environment * _environment, int _register ) {

    // printf( "z80_blit_free_register($%4.4x)\n", _register );

    int location = _register & 0xff;
    int reg;

    if ( _register < CPU6809_BLIT_REGISTER_COUNT ) {
        int registerMask = ( 0x01 << _register );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( isRegisterUsed ) {
            _environment->blit.freeRegisters &= ~registerMask;
            return;
        } else {
            CRITICAL_BLIT_INVALID_FREE_REGISTER( _environment->blit.name, _register );
        }
    } else {
        int registerMask = 0x10 << ( ( _register >> 8 ) & 0xff );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( isRegisterUsed ) {
            outline2( "LDA (_%sbs+$%2.2x)",  _environment->blit.name, location );
            outline1( "LDA %s", &CPU6809_BLIT_REGISTER[reg][0] );
            _environment->blit.freeRegisters &= ~registerMask;
            return;
        }
    }

    CRITICAL_BLIT_INVALID_FREE_REGISTER( _environment->blit.name, _register );

}

/**
 * @brief <i>CPU 6809</i>: emit code to store n bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _n bits to store (>32)
 * @param _value[] Value to store (segmented in 32 bit each)
 */
void cpu6809_store_nbit( Environment * _environment, char *_destination, int _n, int _value[] ) {

    int i = 0;
    while( _n ) {
        char destinationAddress[MAX_TEMPORARY_STORAGE]; sprintf( destinationAddress, "%s+%d", _destination, i*4 );
        if ( _n <= 32 ) {
            switch( _n ) {
                case 1: case 2: case 3: case 4:
                case 5: case 6: case 7: case 8:
                    cpu6809_store_8bit( _environment, destinationAddress, ( _value[i*4] & (0xff>>(8-_n)) ) );
                    break;
                case 9: case 10: case 11: case 12:
                case 13: case 14: case 15: case 16:
                    cpu6809_store_8bit( _environment, destinationAddress, ( _value[i*4] & (0xff>>(16-_n)) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu6809_store_8bit( _environment, destinationAddress, ( _value[i*4+1] & (0xff) ) );
                    break;
                case 17: case 18: case 19: case 20:
                case 21: case 22: case 23: case 24:
                    cpu6809_store_8bit( _environment, destinationAddress, ( _value[i*4] & (0xff>>(24-_n)) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu6809_store_8bit( _environment, destinationAddress, ( _value[i*4+1] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    cpu6809_store_8bit( _environment, destinationAddress, ( _value[i*4+2] & (0xff) ) );
                    break;
                case 25: case 26: case 27: case 28:
                case 29: case 30: case 31: case 32:
                default:
                    cpu6809_store_8bit( _environment, destinationAddress, ( _value[i*4] & (0xff>>(32-_n)) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu6809_store_8bit( _environment, destinationAddress, ( _value[i*4+1] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    cpu6809_store_8bit( _environment, destinationAddress, ( _value[i*4+2] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
                    cpu6809_store_8bit( _environment, destinationAddress, ( _value[i*4+3] & (0xff) ) );
                    break;
            }
            _n = 0;
        } else {
            cpu6809_store_8bit( _environment, destinationAddress, ( _value[i*4] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
            cpu6809_store_8bit( _environment, destinationAddress, ( _value[i*4+1] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
            cpu6809_store_8bit( _environment, destinationAddress, ( _value[i*4+2] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
            cpu6809_store_8bit( _environment, destinationAddress, ( _value[i*4+3] & (0xff) ) );
            _n -= 32;
        }
        ++i;
    }


}

/**
 * @brief <i>CPU cpu6809</i>: emit code to store n bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _n bits to store (>32)
 * @param _value[] Value to store (segmented in 32 bit each)
 */
void cpu6809_move_nbit( Environment * _environment, int _n, char * _source, char *_destination ) {

    int i = 0;
    while( _n ) {
        char sourceAddress[MAX_TEMPORARY_STORAGE]; sprintf( sourceAddress, "%s+%d", _source, i*4 );
        char destinationAddress[MAX_TEMPORARY_STORAGE]; sprintf( destinationAddress, "%s+%d", _destination, i*4 );
        if ( _n <= 32 ) {
            switch( _n ) {
                case 1: case 2: case 3: case 4:
                case 5: case 6: case 7: case 8:
                    cpu6809_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
                case 9: case 10: case 11: case 12:
                case 13: case 14: case 15: case 16:
                    cpu6809_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu6809_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
                case 17: case 18: case 19: case 20:
                case 21: case 22: case 23: case 24:
                    cpu6809_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu6809_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    cpu6809_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
                case 25: case 26: case 27: case 28:
                case 29: case 30: case 31: case 32:
                default:
                    cpu6809_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu6809_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    cpu6809_move_8bit( _environment, sourceAddress, destinationAddress );
                    sprintf( sourceAddress, "%s+%d", _source, i*4+3 );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
                    cpu6809_move_8bit( _environment, sourceAddress, destinationAddress );
                    break;
            }
            _n = 0;
        } else {
            cpu6809_move_8bit( _environment, sourceAddress, destinationAddress );
            sprintf( sourceAddress, "%s+%d", _source, i*4+1 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
            cpu6809_move_8bit( _environment, sourceAddress, destinationAddress );
            sprintf( sourceAddress, "%s+%d", _source, i*4+2 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
            cpu6809_move_8bit( _environment, sourceAddress, destinationAddress );
            sprintf( sourceAddress, "%s+%d", _source, i*4+3 );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
            cpu6809_move_8bit( _environment, sourceAddress, destinationAddress );
            _n -= 32;
        }
        ++i;
    }

}

void cpu6809_move_nbit_indirect( Environment * _environment, int _n, char *_source, char * _value ) {

    outline1("LDX %s", _value);

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
            outline1("LDD %s", address_displacement(_environment, _source, step) );
            outline1("STD %d,X", stepIndex);
            outline1("LDD %s", address_displacement(_environment, _source, step2) );
            outline1("STD %d,X", stepIndex+2);
            stepIndex += 4;
            _n -= 32;
            break;
        } else {
            switch( _n ) {
                case 32: case 31: case 30: case 29:
                case 28: case 27: case 26: case 25:
                    outline1("LDD %s", address_displacement(_environment, _source, step) );
                    outline1("STD %d,X", stepIndex);
                    outline1("LDD %s", address_displacement(_environment, _source, step2) );
                    outline1("STD %d,X", stepIndex+2);
                    break;
                case 24: case 23: case 22: case 21:
                case 20: case 19: case 18: case 17:
                    outline1("LDD %s", address_displacement(_environment, _source, step) );
                    outline1("STD %d,X", stepIndex);
                    outline1("LDA %s", address_displacement(_environment, _source, step2) );
                    outline1("STA %d,X", stepIndex+2);
                    break;
                case 16: case 15: case 14: case 13:
                case 12: case 11: case 10: case 9:
                    outline1("LDD %s", address_displacement(_environment, _source, step) );
                    outline1("STD %d,X", stepIndex);
                    break;
                case 8: case 7: case 6: case 5:
                case 4: case 3: case 2: case 1:
                    outline1("LDA %s", address_displacement(_environment, _source, step) );
                    outline1("STA %d,X", stepIndex);
                    break;
            }
            _n = 0;
        }
    }

}

void cpu6809_move_nbit_indirect2( Environment * _environment, int _n, char * _value, char *_source ) {

    outline1("LDX %s", _value);

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
            outline1("LDD %d,X", stepIndex);
            outline1("STD %s", address_displacement(_environment, _source, step) );
            outline1("LDD %d,X", stepIndex+2);
            outline1("STD %s", address_displacement(_environment, _source, step2) );
            stepIndex += 4;
            _n -= 32;
            break;
        } else {
            switch( _n ) {
                case 32: case 31: case 30: case 29:
                case 28: case 27: case 26: case 25:
                    outline1("LDD %d,X", stepIndex);
                    outline1("STD %s", address_displacement(_environment, _source, step) );
                    outline1("LDD %d,X", stepIndex+2);
                    outline1("STD %s", address_displacement(_environment, _source, step2) );
                    break;
                case 24: case 23: case 22: case 21:
                case 20: case 19: case 18: case 17:
                    outline1("LDD %d,X", stepIndex);
                    outline1("STD %s", address_displacement(_environment, _source, step) );
                    outline1("LDA %d,X", stepIndex+2);
                    outline1("STA %s", address_displacement(_environment, _source, step2) );
                    break;
                case 16: case 15: case 14: case 13:
                case 12: case 11: case 10: case 9:
                    outline1("LDD %d,X", stepIndex);
                    outline1("STD %s", address_displacement(_environment, _source, step) );
                    break;
                case 8: case 7: case 6: case 5:
                case 4: case 3: case 2: case 1:
                    outline1("LDA %d,X", stepIndex);
                    outline1("STA %s", address_displacement(_environment, _source, step) );
                    break;
            }
            _n = 0;
        }
    }

}



//
//                  [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]      [8]      [9]
// SINGLE	(40)  	eeeeeeee smmmmmmm mmmmmmmm mmmmmmmm mmmmmmmm
//

void cpu6809_float_fast_from_double_to_int_array( Environment * _environment, double _value, int _result[] ) {
    cpu6809_float_single_from_double_to_int_array( _environment, _value, _result );
}

void cpu6809_float_single_from_double_to_int_array( Environment * _environment, double _value, int _result[] ) {
    
    double value = 0.0;
    double integral = 0.0;
    double fractional = 0.0;
    int sign = 0;
    int left = 0;
    int right[4];
    int steps = 0;
    int exp = 0;
    int mantissa_bits = 32;

    memset( &right[0], 0, sizeof( int ) * 4 );

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

        printf("%f %d %2.2x %2.2x %2.2x %2.2x\n", fractional, steps, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2], (unsigned char) right[3] );

        right[3] = right[3] << 1;
        right[2] = right[2] << 1;
        right[1] = right[1] << 1;
        right[0] = right[0] << 1;
        if ( ( right[3] & 0x100 )  ) {
            right[2] = right[2] | 0x1;
        }
        if ( ( right[2] & 0x100 )  ) {
            right[1] = right[1] | 0x1;
        }
        if ( ( right[1] & 0x100 )  ) {
            right[0] = right[0] | 0x1;
        }
        right[3] = right[3] & 0xff;
        right[2] = right[2] & 0xff;
        right[1] = right[1] & 0xff;
        right[0] = right[0] & 0x7f;

        fractional = fractional * 2;

        if ( fractional >= 1.0 ) {
            right[3] |= 1;
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

                printf("b) exp = %d left = %2.2x right = %2.2x %2.2x %2.2x\n", exp, (unsigned char) left, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2] );

                if ( ! right[0] && ! right[1] && ! right[2] && ! right[3] ) {
                    left = 0x1;
                }

                if ( right[0] & 0x40 ) {
                    left = 0x1;
                }

                right[0] = right[0] << 1;
                right[1] = right[1] << 1;
                right[2] = right[2] << 1;
                right[3] = right[3] << 1;
                if ( ( right[1] & 0x100 )) {
                    right[0] = right[0] | 0x1;
                }
                if ( ( right[2] & 0x100 )) {
                    right[1] = right[1] | 0x1;
                }
                if ( ( right[3] & 0x100 )) {
                    right[2] = right[2] | 0x1;
                }
                right[0] = right[0] & 0x7f;
                right[1] = right[1] & 0xff;
                right[2] = right[2] & 0xff;
                right[3] = right[3] & 0xff;

                --exp;
            }

            ++exp;

        } else {

            exp = -128;

        }

        printf("exp = %d left = %2.2x right = %2.2x %2.2x %2.2x %2.2x\n", exp, (unsigned char) left, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2], (unsigned char) right[3]  );

    } else {

        while( left ) {

            printf("a) left = %8.8x right = %2.2x %2.2x %2.2x %2.2x\n", left, (unsigned char) right[0], (unsigned char) right[1], (unsigned char) right[2], (unsigned char) right[3] );

            if ( ( right[0] & 0x01 ) ) {
                right[1] = right[1] | 0x100;
            }
            if ( ( right[1] & 0x01 ) ) {
                right[2] = right[2] | 0x100;
            }
            if ( ( right[2] & 0x01 ) ) {
                right[3] = right[3] | 0x100;
            }
            right[0] = right[0] >> 1;
            right[1] = right[1] >> 1;
            right[2] = right[2] >> 1;
            right[3] = right[3] >> 1;
            if ( left & 0x1 ) {
                right[0] = right[0] | 0x40;
            }
            left = left >> 1;
            ++exp;
        }
        // --exp;
        left = 1;
        right[3] = right[3] << 1;
        right[2] = right[2] << 1;
        right[1] = right[1] << 1;
        right[0] = right[0] << 1;
        if ( right[3] & 0x100 ) {
            right[2] = right[2] | 0x01;
        }
        if ( right[2] & 0x100 ) {
            right[1] = right[1] | 0x01;
        }
        if ( right[1] & 0x100 ) {
            right[0] = right[0] | 0x01;
        }
        right[3] = right[3] & 0xff;
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

    printf("exp = %2.2x\n", exp );

    // Step 6: Convert the Biased Exponent to Unsigned Binary
    // The biased exponent value from the previous step must be converted into unsigned binary, using the usual process.
    // The result must be exactly 8 bits. It should not be possible to need more than 8 bits. If fewer than 8 bits are 
    // needed in this conversion process, then leading zeros must be added to the front of the result to produce an 
    // 8-bit value.

    exp = exp & 0xff;

    printf("exp = %2.2x\n", exp );

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

    if ( _value == 0.0f ) {
        exp = 0;
    }

    // Step 8: Put it All Together
    // The sign bit from step 1 will be the first bit of the final result. The next 8 bits will be from the exponent from 
    // step 6. The last 23 bits will be from the mantissa from step 7. The result will be a 32-bit number encoded in 
    // IEEE-754 binary32 format, assuming no mistakes were made in the process.

    //                  [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]      [8]      [9]
    // SINGLE	(32)  	seeeeeee emmmmmmm mmmmmmmm mmmmmmmm

    _result[0] = exp & 0xff;
    _result[1] = ( sign << 7 ) | ( right[0] & 0x7f );
    _result[2] = ( right[1] );
    _result[3] = ( right[2] );
    _result[4] = ( right[3] );

    printf( "\n| %f = %2.2x %2.2x %2.2x %2.2x %2.2x\n\n", _value, _result[0], _result[1], _result[2], _result[3], _result[4] );

}

void cpu6809_float_fast_to_string( Environment * _environment, char * _x, char * _string, char * _string_size ) {
    cpu6809_float_single_to_string( _environment, _x, _string, _string_size );
}

void cpu6809_float_single_to_string( Environment * _environment, char * _x, char * _string, char * _string_size ) {

    MAKE_LABEL

    deploy( fp_vars, src_hw_6809_fp_routines_asm );

    outline0( "LDU #FPSPAREA" );
    outline1( "LDX #%s",_x );
    outline0( "JSR FPLOD" );

    outline1( "LDY %s", _string );

    outline0( "JSR FPSCIENT" );

    outline0( "TFR Y, D" );
    outline1( "SUBD %s", _string );
    outline1( "STB %s", _string_size );

}

void cpu6809_float_fast_from_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    cpu6809_float_single_from_8( _environment, _value, _result, _signed );
}

void cpu6809_float_single_from_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    deploy( fp_vars, src_hw_6809_fp_routines_asm );

    outline0( "CLRA" );
    outline1( "LDB %s", _value );
    outline0( "LDU #FPSPAREA" );

    if ( _signed ) {
        outline0( "JSR INT2FP" );
    } else {
        outline0( "JSR UNINT2FP" );
    }

    outline1( "LDX #%s", _result );
    outline0( "JSR FPSTO" );

}

void cpu6809_float_fast_from_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    cpu6809_float_single_from_16( _environment, _value, _result, _signed );
}

void cpu6809_float_single_from_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    deploy( fp_vars, src_hw_6809_fp_routines_asm );

    outline1( "LDD %s", _value );
    outline0( "LDU #FPSPAREA" );

    if ( _signed ) {
        outline0( "JSR INT2FP" );
    } else {
        outline0( "JSR UNINT2FP" );
    }

    outline1( "LDX #%s", _result );
    outline0( "JSR FPSTO" );

}

void cpu6809_float_fast_to_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    cpu6809_float_single_to_8( _environment, _value, _result, _signed );
}

void cpu6809_float_single_to_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    deploy( fp_vars, src_hw_6809_fp_routines_asm );

    outline0( "LDU #FPSPAREA" );
    outline1( "LDX #%s", _value );
    outline0( "JSR FPLOD" );

    if ( _signed ) {
        outline0( "JSR FP2INT" );
    } else {
        outline0( "JSR FP2UINT" );
    }
    outline1( "STB %s", _result );

}

void cpu6809_float_fast_to_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    cpu6809_float_single_to_16( _environment, _value, _result, _signed );
}

void cpu6809_float_single_to_16( Environment * _environment, char * _value, char * _result, int _signed ) {

    deploy( fp_vars, src_hw_6809_fp_routines_asm );

    outline0( "LDU #FPSPAREA" );
    outline1( "LDX #%s", _value );
    outline0( "JSR FPLOD" );

    if ( _signed ) {
        outline0( "JSR FP2INT" );
    } else {
        outline0( "JSR FP2UINT" );
    }
    outline1( "STD %s", _result );

}

void cpu6809_float_fast_sub( Environment * _environment, char * _x, char * _y, char * _result ) {
    cpu6809_float_single_sub( _environment, _x, _y, _result );
}

void cpu6809_float_single_sub( Environment * _environment, char * _x, char * _y, char * _result ) {
    
    deploy( fp_vars, src_hw_6809_fp_routines_asm );

    outline0( "LDU #FPSPAREA" );
    outline1( "LDX #%s", _x );
    outline0( "JSR FPLOD" );
    outline1( "LDX #%s", _y );
    outline0( "JSR FPLOD" );

    outline0( "JSR FPSUB" );

    outline1( "LDX #%s", _result );
    outline0( "JSR FPSTO" );

}

void cpu6809_float_fast_add( Environment * _environment, char * _x, char * _y, char * _result ) {
    cpu6809_float_single_add( _environment, _x, _y, _result );
}

void cpu6809_float_single_add( Environment * _environment, char * _x, char * _y, char * _result ) {
    
    deploy( fp_vars, src_hw_6809_fp_routines_asm );

    outline0( "LDU #FPSPAREA" );
    outline1( "LDX #%s", _x );
    outline0( "JSR FPLOD" );
    outline1( "LDX #%s", _y );
    outline0( "JSR FPLOD" );

    outline0( "JSR FPADD" );

    outline1( "LDX #%s", _result );
    outline0( "JSR FPSTO" );

}

void cpu6809_float_fast_cmp( Environment * _environment, char * _x, char * _y, char * _result ) {
    cpu6809_float_single_cmp( _environment, _x, _y, _result );
}

void cpu6809_float_single_cmp( Environment * _environment, char * _x, char * _y, char * _result ) {
    
    MAKE_LABEL

    deploy( fp_vars, src_hw_6809_fp_routines_asm );

    outline0( "LDU #FPSPAREA" );
    outline1( "LDX #%s", _x );
    outline0( "JSR FPLOD" );
    outline1( "LDX #%s", _y );
    outline0( "JSR FPLOD" );

    outline0( "JSR FPCMP" );

    outline1( "BEQ %sequal", label );
    outline1( "BCS %sless", label );
    outline0( "LDA #$1" );
    outline1( "STA %s", _result );
    outline1( "JMP %sdone", label );
    outhead1( "%sequal", label );
    outline0( "LDA #$0" );
    outline1( "STA %s", _result );
    outline1( "JMP %sdone", label );
    outhead1( "%sless", label );
    outline0( "LDA #$ff" );
    outline1( "STA %s", _result );
    outline1( "JMP %sdone", label );
    outhead1( "%sdone", label );

}

void cpu6809_float_fast_mul( Environment * _environment, char * _x, char * _y, char * _result ) {
    cpu6809_float_single_mul( _environment, _x, _y, _result );
}

void cpu6809_float_single_mul( Environment * _environment, char * _x, char * _y, char * _result ) {
    
    deploy( fp_vars, src_hw_6809_fp_routines_asm );

    outline0( "LDU #FPSPAREA" );
    outline1( "LDX #%s", _x );
    outline0( "JSR FPLOD" );
    outline1( "LDX #%s", _y );
    outline0( "JSR FPLOD" );

    outline0( "JSR FPMUL" );

    outline1( "LDX #%s", _result );
    outline0( "JSR FPSTO" );

}

void cpu6809_float_fast_div( Environment * _environment, char * _x, char * _y, char * _result ) {
    cpu6809_float_single_div( _environment, _x, _y, _result );
}

void cpu6809_float_single_div( Environment * _environment, char * _x, char * _y, char * _result ) {
    
    deploy( fp_vars, src_hw_6809_fp_routines_asm );

    outline0( "LDU #FPSPAREA" );
    outline1( "LDX #%s", _x );
    outline0( "JSR FPLOD" );
    outline1( "LDX #%s", _y );
    outline0( "JSR FPLOD" );

    outline0( "JSR FPDIV" );

    outline1( "LDX #%s", _result );
    outline0( "JSR FPSTO" );

}

void cpu6809_float_fast_sin( Environment * _environment, char * _angle, char * _result ) {
    cpu6809_float_single_sin( _environment, _angle, _result );
}

void cpu6809_float_single_sin( Environment * _environment, char * _angle, char * _result ) {
    
    deploy( fp_vars, src_hw_6809_fp_routines_asm );

    outline0( "LDU #FPSPAREA" );
    outline1( "LDX #%s", _angle );
    outline0( "JSR FPLOD" );

    outline0( "JSR FPSIN" );

    outline1( "LDX #%s", _result );
    outline0( "JSR FPSTO" );

}

void cpu6809_float_fast_cos( Environment * _environment, char * _angle, char * _result ) {
    cpu6809_float_single_cos( _environment, _angle, _result );
}

void cpu6809_float_single_cos( Environment * _environment, char * _angle, char * _result ) {
    
    deploy( fp_vars, src_hw_6809_fp_routines_asm );

    outline0( "LDU #FPSPAREA" );
    outline1( "LDX #%s", _angle );
    outline0( "JSR FPLOD" );

    outline0( "JSR FPCOS" );

    outline1( "LDX #%s", _result );
    outline0( "JSR FPSTO" );

}

void cpu6809_float_fast_tan( Environment * _environment, char * _angle, char * _result ) {
    cpu6809_float_single_tan( _environment, _angle, _result );
}

void cpu6809_float_single_tan( Environment * _environment, char * _angle, char * _result ) {
    
    deploy( fp_vars, src_hw_6809_fp_routines_asm );

    outline0( "LDU #FPSPAREA" );
    outline1( "LDX #%s", _angle );
    outline0( "JSR FPLOD" );

    outline0( "JSR FPTAN" );

    outline1( "LDX #%s", _result );
    outline0( "JSR FPSTO" );

}

#endif