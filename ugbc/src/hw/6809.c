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
#include <time.h>

/****************************************************************************
 * CODE SECTION
 ****************************************************************************/

#if defined(__d32__) || defined(__d64__) || defined(__pc128op__)

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
    
    MAKE_LABEL

    inline( cpu_beq )

        outline1("BNE %s", label);
        outline1("JMP %s", _label);    
        outhead1("%s", label);

    no_embedded( cpu_beq )

}

/**
 * @brief <i>CPU 6809</i>: emit code to make long conditional jump
 * 
 * @param _environment Current calling environment
 * @param _label Destination of the conditional jump.
 */
void cpu6809_bneq( Environment * _environment, char * _label ) {
    
    MAKE_LABEL

    inline( cpu_bneq )

        outline1("BEQ %s", label);
        outline1("JMP %s", _label);    
        outhead1("%s", label);

    no_embedded( cpu_bneq )

}

void cpu6809_bveq( Environment * _environment, char * _value, char * _label ) {

    inline( cpu_bveq )

        outline1("LDA %s", _value);
        outline0("CMPA #0");
        cpu6809_beq( _environment,  _label );

    no_embedded( cpu_bveq )

}

void cpu6809_bvneq( Environment * _environment, char * _value, char * _label ) {

    inline( cpu_bveq )

        outline1("LDA %s", _value);
        outline0("CMPA #0");
        cpu6809_bneq( _environment,  _label );

    no_embedded( cpu_bvneq )
    
}

void cpu6809_label( Environment * _environment, char * _label ) {

    inline( cpu_label )

        outhead1("%s", _label);

    no_embedded( cpu_label )

}

void cpu6809_peek( Environment * _environment, char * _address, char * _target ) {

    inline( cpu_peek )

        outline1("LDX %s", _address);
        outline0("LDA , X");
        outline1("STA %s", _target);

    no_embedded( cpu_peek )

}

void cpu6809_poke( Environment * _environment, char * _address, char * _source ) {

    inline( cpu_poke )

        outline1("LDA %s", _source );
        outline1("LDX %s", _address);
        outline0("STA ,X");

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

        outline1("LDA %s", _source);
        outline1("STA %s", _destination);

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

        if ( _value ) {
            outline1("LDA #$%2.2x", _value );
            outline1("STA %s", _destination );
        } else {
            outline1("CLR %s", _destination );
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

        MAKE_LABEL

        outline1("LDA %s", _source);
        outline1("CMPA %s", _destination);
        outline1("BEQ %seq", label);
        outline1("LDA #$%2.2x", ( _positive ) ? 0x00 : 0xff );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("JMP %sdone", label);
        outhead1("%seq", label );
        outline1("LDA #$%2.2x", ( _positive ) ? 0xff : 0x00 );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outhead1("%sdone", label );

    no_embedded( cpu_compare_8bit )

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

        MAKE_LABEL

        outline1("LDA %s", _source);
        outline1("CMPA %s", _destination);
        if ( _signed ) {
            if ( _equal ) {
                outline1("BLE %seq", label);
            } else {
                outline1("BLT %seq", label);
            }
        } else {
            if ( _equal ) {
                outline1("BLS %seq", label);
            } else {
                outline1("BLO %seq", label);    
            }
        }
        outline1("LDA #$%2.2x", 0x00 );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("JMP %sdone", label);
        outhead1("%seq", label );
        outline1("LDA #$%2.2x", 0xff );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outhead1("%sdone", label );

    no_embedded( cpu_less_than_8bit )

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

        MAKE_LABEL

        outline1("LDA %s", _source);
        outline1("CMPA %s", _destination);
        if ( _signed ) {
            if ( _equal ) {
                outline1("BGE %seq", label);
            } else {
                outline1("BGT %seq", label);
            }
        } else {
            if ( _equal ) {
                outline1("BHS %seq", label);
            } else {
                outline1("BHI %seq", label);    
            }
        }
        outline1("LDA #$%2.2x", 0x00 );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("JMP %sdone", label);
        outhead1("%seq", label );
        outline1("LDA #$%2.2x", 0xff );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outhead1("%sdone", label );

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

        outline1("LDA %s", _source);
        outline1("ADDA %s", _destination);
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }

    no_embedded( cpu_greater_than_8bit )

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

        outline1("LDA %s", _source);
        outline1("SUBA %s", _destination);
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }

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

        outline1("LDA %s", _source);
        outline0("ASLA");
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _source);
        }

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
            outline0("EOR #$FF");
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
            outline0("EOR #$FF");
            outline0("ADDA #1");
            outhead1("%spos2", label);
        }
        outline1("STA %s", _source);

    embedded( cpu_math_div2_8bit, src_hw_6809_cpu_math_div2_8bit_asm );

        outline1("LDA %s", _source);
        outline1("LDB #$%2.2x", _steps);
        if ( _signed ) {
            outline0("JSR CPUMATHDIV28BIT_SIGNED");
        } else {
            outline0("JSR CPUMATHDIV28BIT");
        }
        outline1("STA %s", _source);

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

        if ( _signed ) {
            outline1("LDA %s", _source );
            outline0("STA <MATHPTR1" );
            outline1("LDB %s", _destination );
            outline0("STB <MATHPTR2" );
            outline0("JSR CPUMATHMUL8BITTO16BIT_SIGNED" );
            outline1("STD %s", _other );
        } else {
            outline1("LDA %s", _source );
            outline1("LDB %s", _destination );
            outline0("MUL" );
            outline1("STD %s", _other );
        }

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

        outline0("LDX #$0");
        outline1("LDA %s", _source);
        outline0("STA <MATHPTR0");
        outline1("LDA %s", _destination);
        outline0("STA <MATHPTR1");
        if ( _signed ) {
            outline0("JSR CPUMATHDIV8BITTO8BIT_SIGNED");
        } else {
            outline0("JSR CPUMATHDIV8BITTO8BIT");
        }
        outline0("LDA <MATHPTR2");
        outline1("STA %s", _other);
        outline0("LDA <MATHPTR3");
        outline1("STA %s", _other_remainder);

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

        outline1("LDA %s", _source);
        outline1("LDB #$%2.2x", _steps);
        if ( _signed ) {
            outline0("JSR CPUMATHDIV28BIT_SIGNED");
        } else {
            outline0("JSR CPUMATHDIV28BIT");
        }
        outline1("STA %s", _source);

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

    inline( cpu_math_mul2_const_8bit )

        MAKE_LABEL

        outline1("LDA %s", _source);
        outline1("LDB #$%2.2x", _steps);
        outline0("CMPB #0");
        outline1("BEQ %sdone", label);
        outhead1("%sloop", label);
        outline0("ASLA");
        outline0("DECB");
        outline0("CMPB #0");
        outline1("BNE %sloop", label);
        outhead1("%sdone", label);
        outline1("STA %s", _source);

    embedded( cpu_math_mul2_const_8bit, src_hw_6809_cpu_math_mul2_const_8bit_asm );

        outline1("LDA %s", _source);
        outline1("LDB #$%2.2x", _steps);
        outline0("JSR CPUMATHMUL2CONST8BIT" );
        outline1("STA %s", _source);

    done( )

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

        outline1("LDA #$%2.2x", _value);
        outline1("SUBA %s", _source);
        outline1("STA %s", _source);

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

        outline1("LDA %s", _source);
        outline1("ANDA %2.2x", _mask);
        outline1("STA %s", _source);

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

        outline1("LDX #%s", _source);
        outline1("STX %s", _destination);

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

        if ( _value ) {
            outline1("LDD #$%4.4x", (unsigned int)( _value & 0xffff ) );
            outline1("STD %s", _destination );
        } else {
            outline1("CLR %s", _destination );
            outline1("CLR %s+1", _destination );
        }

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

        MAKE_LABEL

        outline1("LDX %s", _source);
        outline1("CMPX %s", _destination);
        outline1("BEQ %seq", label);
        outline1("LDA #$%2.2x", ( _positive ) ? 0x00 : 0xff );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("JMP %sdone", label);
        outhead1("%seq", label );
        outline1("LDA #$%2.2x", ( _positive ) ? 0xff : 0x00 );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outhead1("%sdone", label );

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
void cpu6809_less_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    inline( cpu_less_than_16bit )

        MAKE_LABEL

        outline1("LDX %s", _source);
        outline1("CMPX %s", _destination);
        if ( _signed ) {
            if ( _equal ) {
                outline1("BLE %seq", label);
            } else {
                outline1("BLT %seq", label);
            }
        } else {
            if ( _equal ) {
                outline1("BLS %seq", label);
            } else {
                outline1("BLO %seq", label);    
            }
        }
        outline1("LDA #$%2.2x", 0x00 );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("JMP %sdone", label);
        outhead1("%seq", label );
        outline1("LDA #$%2.2x", 0xff );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outhead1("%sdone", label );

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

        MAKE_LABEL

        outline1("LDX %s", _source);
        outline1("CMPX %s", _destination);
        if ( _signed ) {
            if ( _equal ) {
                outline1("BGE %seq", label);
            } else {
                outline1("BGT %seq", label);
            }
        } else {
            if ( _equal ) {
                outline1("BHS %seq", label);
            } else {
                outline1("BHI %seq", label);    
            }
        }
        outline1("LDA #$%2.2x", 0x00 );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("JMP %sdone", label);
        outhead1("%seq", label );
        outline1("LDA #$%2.2x", 0xff );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outhead1("%sdone", label );

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

        outline1("LDD %s", _source);
        outline1("ADDD %s", _destination);
        if ( _other ) {
            outline1("STD %s", _other);
        } else {
            outline1("STD %s", _destination);
        }

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
        if ( _other ) {
            outline1("STD %s", _other);
        } else {
            outline1("STD %s", _destination);
        }

    no_embedded( cpu_math_add_16bit_with_16bit )

}

void cpu6809_math_add_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_add_16bit_with_8bit )

        outline1("LDX %s", _source);
        outline1("LDB %s", _destination);
        outline0("LDA #$0");
        outline0("LEAX D, X");
        if ( _other ) {
            outline1("STX %s", _other);
        } else {
            outline1("STX %s", _destination);
        }

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

        outline1("LDX %s", _source);
        outline0("TFR X, D");
        outline0("LEAX D, X");
        if ( _other ) {
            outline1("STX %s", _other);
        } else {
            outline1("STX %s", _source);
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
            outline1("LDA %s+1", _source );
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
            outline1("LDA %s+1", _destination );
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
            outline1("LDX %s", _source );
            outline0("STX <MATHPTR0" );
            outline1("LDX %s", _destination );
            outline0("STX <MATHPTR2" );
        }
        outline0("LDA <MATHPTR0" );
        outline0("LDB <MATHPTR2" );
        outline0("MUL");
        outline1("STD %s", _other );

        outline0("LDA <MATHPTR1" );
        outline0("LDB <MATHPTR3" );
        outline0("MUL" );
        outline1("STD %s+2", _other );

        outline0("LDA <MATHPTR1" ); 
        outline0("LDB <MATHPTR2" );
        outline0("MUL" );
        outline0("TFR D, X" );

        outline0("LDA <MATHPTR0" );
        outline0("LDB <MATHPTR3" );
        outline0("MUL" );
        outline0("LEAX D, X" );

        outline0("TFR X, D" );

        outline1("ADDB %s+2", _other );
        outline1("STB %s+2", _other );

        outline1("ADDA %s+1", _other );
        outline1("STA %s+1", _other );

        if ( _signed ) {
            outline0("LDA <TMPPTR" );
            outline0("CMPA #0" );
            outline1("BEQ %sdonex", label );
            outline1("LDA %s", _other );
            outline0("EORA #$FF" );
            outline1("STA %s", _other );
            outline1("LDA %s+1", _other );
            outline0("EORA #$FF" );
            outline1("STA %s+1", _other );
            outline1("LDA %s+2", _other );
            outline0("EORA #$FF" );
            outline1("STA %s+2", _other );
            outline1("LDA %s+3", _other );
            outline0("EORA #$FF" );
            outline1("STA %s+3", _other );
            outline1("LDA %s+3", _other );
            outline0("ADDA #1" );
            outline1("STA %s+3", _other );
            outline1("LDA %s+2", _other );
            outline0("ADDA #0" );
            outline1("STA %s+2", _other );
            outline1("LDA %s+1", _other );
            outline0("ADDA #0" );
            outline1("STA %s+1", _other );
            outline1("LDA %s", _other );
            outline0("ADDA #0" );
            outline1("STA %s", _other );
            outhead1("%sdonex", label );
        }

    embedded( cpu_math_mul_16bit_to_32bit, src_hw_6809_cpu_math_mul_16bit_to_32bit_asm );

        outline1("LDX %s", _source );
        outline0("STX <MATHPTR0" );
        outline1("LDX %s", _destination );
        outline0("STX <MATHPTR2" );

        if ( _signed ) {
            outline0("JSR CPUMATHMUL16BITTO32BIT_SIGNED" );
        } else {
            outline0("JSR CPUMATHMUL16BITTO32BIT" );
        }

        outline0("LDX <MATHPTR4" );
        outline1("STX %s", _other );
        outline0("LDX <MATHPTR6" );
        outline1("STX %s+2", _other );

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
            outline1("LDA %s+1", _source );
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
            outline1("LDA %s+1", _destination );
            outline0("ANDA #$80" );
            outline1("BEQ %sthird", label );
            outline0("ANDCC #$FE" );
            outline1("LDA %s", _destination );
            outline0("EORA #$ff" );
            outline0("STA <MATHPTR2" );
            outline1("LDA %s+1", _destination );
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
            outline1("LDA %s+1", _other );
            outline0("EORA #$ff" );
            outline1("STA %s+1", _other );
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

        outline1("LDX %s", _source );
        outline1("LDY %s", _destination );
        if ( _signed ) {
            outline0("JSR CPUMATHDIV16BITTO16BIT_SIGNED" );
        } else {
            outline0("JSR CPUMATHDIV16BITTO16BIT" );
        }
        outline1("STX %s", _other );
        outline1("STY %s", _other_remainder );

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

        outline1("LDD %s", _destination );
        outline0("ANDCC #$FE" );
        outline0("EORA #$FF" );
        outline0("EORB #$FF" );
        outline0("ADDD #1" );

        outline1("LDY %s", _source );
        outline0("LEAY D, Y" );
        if ( _other ) {
            outline1("STY %s", _other );
        } else {
            outline1("STY %s", _destination );
        }

    no_embedded( cpu_math_sub_16bit );

}

void cpu6809_math_sub_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_sub_16bit_with_8bit )

        outline1("LDB %s", _destination );
        outline0("LDA #0" );
        outline0("ANDCC #$FE" );
        outline0("EORA #$FF" );
        outline0("EORB #$FF" );
        outline0("ADDD #1" );

        outline1("LDY %s", _source );
        outline0("LEAY D, Y" );
        if ( _other ) {
            outline1("STY %s", _other );
        } else {
            outline1("STY %s", _destination );
        }

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

        outline1("LDX #$%2.2x", _value);
        outline1("LDD %s", _source );
        outline0("ANDCC #$FE" );
        outline0("EORA #$FF" );
        outline0("EORB #$FF" );
        outline0("ADDD #1" );
        outline0("LEAX D, X");
        outline1("STX %s", _source);

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

    inline( cpu_math_mul2_const_16bit )

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
            outline0("ASLB" );
            outline0("ROLA" );
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
            outline0("ASLB" );
            outline0("ROLA" );
            outline0("LEAX -1, X");
            outline0("CMPX #0");
            outline1("BNE %sloop", label );
            outline1("STD %s", _source );

        }

    embedded( cpu_math_mul2_const_16bit, src_hw_6809_cpu_math_mul2_const_16bit_asm );

        outline1("LDD %s", _source );
        outline1("LDX #$%2.2x", _steps );

        if ( _signed ) {
            outline0("JSR CPUMATHMUL2CONST16BIT_SIGNED");
        } else {
            outline0("JSR CPUMATHMUL2CONST16BIT");
        }
        outline1("STD %s", _source );

    done( )

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
        outline1("LDD %s+2", _source );
        outline1("STD %s+2", _destination );

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

        if ( _value ) {
            outline1("LDD #$%4.4x", ( _value >> 16 ) & 0xffff );
            outline1("STD %s", _destination );
            outline1("LDD #$%4.4x", ( _value & 0xffff ) );
            outline1("STD %s+2", _destination );
        } else {
            outline1("CLR %s", _destination );
            outline1("CLR %s+1", _destination );
            outline1("CLR %s+2", _destination );
            outline1("CLR %s+3", _destination );
        }

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

        char sourceEffective[MAX_TEMPORARY_STORAGE]; sprintf(sourceEffective, "%s+2", _source );
        char destinationEffective[MAX_TEMPORARY_STORAGE]; sprintf(destinationEffective, "%s+2", _source );

        if ( _positive ) {

            cpu6809_compare_16bit( _environment, _source, _destination, _other, _positive );

            outline1("LDA %s", _other );
            outline1("BEQ %sdone", _other );

            cpu6809_compare_16bit( _environment, sourceEffective, destinationEffective, _other, _positive );

        } else {

            cpu6809_compare_16bit( _environment, _source, _destination, _other, _positive );

            outline1("LDA %s", _other );
            outline1("BNE %sdone", _other );

            cpu6809_compare_16bit( _environment, sourceEffective, destinationEffective, _other, _positive );

        }

        outhead1("%sdone", _other );

    no_embedded( cpu_compare_32bit )

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

        outline1("LDX %s", _source);
        outline1("CMPX %s", _destination);
        outline1("BEQ %slow", label);

        outline1("LDX %s", _source);
        outline1("CMPX %s", _destination);
        if ( _signed ) {
            if ( _equal ) {
                outline1("BLE %seq", label);
            } else {
                outline1("BLT %seq", label);
            }
        } else {
            if ( _equal ) {
                outline1("BLS %seq", label);
            } else {
                outline1("BLO %seq", label);    
            }
        }
        outline1("JMP %sdiff", label);

        outhead1("%slow", label );
        outline1("LDX %s+2", _source);
        outline1("CMPX %s+2", _destination);
        if ( _signed ) {
            if ( _equal ) {
                outline1("BLE %seq", label);
            } else {
                outline1("BLT %seq", label);
            }
        } else {
            if ( _equal ) {
                outline1("BLS %seq", label);
            } else {
                outline1("BLO %seq", label);    
            }
        }
        outline1("JMP %sdiff", label);

        outhead1("%sdiff", label );
        outline1("LDA #$%2.2x", 0x00 );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("JMP %sdone", label);
        outhead1("%seq", label );
        outline1("LDA #$%2.2x", 0xff );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("JMP %sdone", label);


        outhead1("%sdone", label );

    no_embedded( cpu_less_than_32bit )


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
        
        outline1("LDX %s", _source);
        outline1("CMPX %s", _destination);
        outline1("BEQ %slow", label);

        outline1("LDX %s", _source);
        outline1("CMPX %s", _destination);
        if ( _signed ) {
            if ( _equal ) {
                outline1("BGE %seq", label);
            } else {
                outline1("BGT %seq", label);
            }
        } else {
            if ( _equal ) {
                outline1("BHS %seq", label);
            } else {
                outline1("BHI %seq", label);    
            }
        }
        outline1("JMP %sdiff", label);

        outhead1("%slow", label );
        outline1("LDX %s+2", _source);
        outline1("CMPX %s+2", _destination);
        if ( _signed ) {
            if ( _equal ) {
                outline1("BGE %seq", label);
            } else {
                outline1("BGT %seq", label);
            }
        } else {
            if ( _equal ) {
                outline1("BHS %seq", label);
            } else {
                outline1("BHI %seq", label);    
            }
        }
        outline1("JMP %sdiff", label);

        outhead1("%sdiff", label );
        outline1("LDA #$%2.2x", 0x00 );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("JMP %sdone", label);
        outhead1("%seq", label );
        outline1("LDA #$%2.2x", 0xff );
        if ( _other ) {
            outline1("STA %s", _other);
        } else {
            outline1("STA %s", _destination);
        }
        outline1("JMP %sdone", label);

        outhead1("%sdone", label );

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

        outline0("ANDCC #$FF");
        outline1("LDD %s+2", _source);
        outline1("ADDD %s+2", _destination);
        if ( _other ) {
            outline1("STD %s+2", _other);
        } else {
            outline1("STD %s+2", _destination);
        }
        outline1("BCC %snocarry", label);
        outline0("LDA #1");
        outline0("STA <MATHPTR0");
        outhead1("%snocarry", label);
        outline1("LDD %s", _source);
        outline1("ADDD %s", _destination);
        if ( _other ) {
            outline1("STD %s", _other);
        } else {
            outline1("STD %s", _destination);
        }
        outline0("LDA <MATHPTR0");
        outline0("CMPA #1");
        outline1("BNE %snocarry2", label);
        if ( _other ) {
            outline1("LDD %s", _other);
        } else {
            outline1("LDD %s", _destination);
        }
        outline0("ADDD #1");
        if ( _other ) {
            outline1("STD %s", _other);
        } else {
            outline1("STD %s", _destination);
        }
        outhead1("%snocarry2", label);

    no_embedded( cpu_math_add_32bit )

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

    cpu6809_math_add_32bit( _environment, _source, _source, _other );

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

        MAKE_LABEL

        outline0("ANDCC #$FF");
        outline1("LDD %s+2", _source);
        outline1("SUBD %s+2", _destination);
        if ( _other ) {
            outline1("STD %s+2", _other);
        } else {
            outline1("STD %s+2", _destination);
        }
        outline1("BCC %snocarry", label);
        outline0("LDA #1");
        outline0("STA <MATHPTR0");
        outhead1("%snocarry", label);
        outline1("LDD %s", _source);
        outline1("SUBD %s", _destination);
        if ( _other ) {
            outline1("STD %s", _other);
        } else {
            outline1("STD %s", _destination);
        }
        outline0("LDA <MATHPTR0");
        outline0("CMPA #1");
        outline1("BNE %snocarry2", label);
        if ( _other ) {
            outline1("LDD %s", _other);
        } else {
            outline1("LDD %s", _destination);
        }
        outline0("SUBD #1");
        if ( _other ) {
            outline1("STD %s", _other);
        } else {
            outline1("STD %s", _destination);
        }
        outhead1("%snocarry2", label);
    
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

        MAKE_LABEL

        outline0("ANDCC #$FF");
        outline1("LDD #$%4.4x", ( _value ) & 0xffff );
        outline1("SUBD %s+2", _source);
        outline1("STD %s+2", _source);
        outline1("BCC %snocarry", label);
        outline0("LDA #1");
        outline0("STA <MATHPTR0");
        outhead1("%snocarry", label);
        outline1("LDD #$%4.4x", ( _value>>16 ) & 0xffff );
        outline1("SUBD %s", _source);
        outline1("STD %s", _source);
        outline0("LDA <MATHPTR0");
        outline0("CMPA #1");
        outline1("BNE %snocarry2", label);
        outline1("LDD %s", _source);
        outline0("SUBD #1");
        outline1("STD %s", _source);
        outhead1("%snocarry2", label);

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
            
            outline1("LDD %s+2", _source );
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
            outline1("LDD %s+2", _source );
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
            outline1("STD %s+2", _source );
            outline0("LDD <MATHPTR0" );
            outline0("ADDD #0" );
            outline1("STD %s", _source );

            outline1("JMP %sdone2", label );

            outhead1("%spos2", label );
            outline0("LDD <MATHPTR3" );
            outline1("STD %s+3", _source );
            outline0("LDD <MATHPTR2" );
            outline1("STD %s+2", _source );
            outline0("LDD <MATHPTR1" );
            outline1("STD %s+1", _source );
            outline0("LDD <MATHPTR0" );
            outline1("STD %s", _source );
            outhead1("%sdone2", label );

        } else {

            outline1("LDD %s", _source );
            outline0("STD <MATHPTR0" );
            outline1("LDD %s+2", _source );
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
            outline1("STD %s+2", _source );
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
            
            outline1("LDD %s+2", _source );
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
            outline1("LDD %s+2", _source );
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
            outline1("STD %s+2", _source );
            outline0("LDD <MATHPTR0" );
            outline0("ADDD #0" );
            outline1("STD %s", _source );

            outline1("JMP %sdone2", label );

            outhead1("%spos2", label );
            outline0("LDD <MATHPTR3" );
            outline1("STD %s+3", _source );
            outline0("LDD <MATHPTR2" );
            outline1("STD %s+2", _source );
            outline0("LDD <MATHPTR1" );
            outline1("STD %s+1", _source );
            outline0("LDD <MATHPTR0" );
            outline1("STD %s", _source );
            outhead1("%sdone2", label );

        } else {

            outline1("LDD %s", _source );
            outline0("STD <MATHPTR0" );
            outline1("LDD %s+2", _source );
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
            outline1("STD %s+2", _source );
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

        outline1("LDD %s", _source );
        outline1("ANDA #$%2.2x", ( _mask >> 8 ) & 0xff );
        outline1("ANDB #$%2.2x", ( _mask & 0xff ) );
        outline1("STD %s", _source );
        outline1("LDD %s+2", _source );
        outline1("ANDA #$%2.2x", ( _mask >> 8 ) & 0xff );
        outline1("ANDB #$%2.2x", ( _mask & 0xff ) );
        outline1("STD %s+2", _source );

    no_embedded( cpu_math_and_const_32bit )

}

void cpu6809_combine_nibbles( Environment * _environment, char * _low_nibble, char * _hi_nibble, char * _byte ) {

    inline( cpu_combine_nibbles )

        outline1("LDA %s", _low_nibble);
        outline1("STA %s", _byte);
        outline1("LDA %s", _hi_nibble);
        outline0("LSLA");
        outline0("LSLA");
        outline0("LSLA");
        outline0("LSLA");
        outline1("ORA %s", _byte);
        outline1("STA %s", _byte);

    no_embedded( cpu_combine_nibbles )

}

void cpu6809_jump( Environment * _environment, char * _label ) {

    inline( cpu_jump )

        outline1( "JMP %s", _label );

    no_embedded( cpu_jump )

}

void cpu6809_call( Environment * _environment, char * _label ) {

    inline( cpu_call )
    
        outline1( "JSR %s", _label );

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

        outhead1("%s", label );
        outline1("JMP %s", label);

    no_embedded( cpu_halt )

}

void cpu6809_end( Environment * _environment ) {

    inline( cpu_end )

        outline0( "ANDCC #%6f" );
        cpu6809_halt( _environment );

    no_embedded( cpu_end )

}

void cpu6809_random( Environment * _environment, char * _seed, char * _entropy ) {

    inline( cpu_random )

        MAKE_LABEL

        srand( time( NULL ) );

        outline1("JMP %s", label);
        outhead5("%sseed fcb %d, %d, %d, %d", label, rand() & 0xff, rand() & 0xff, rand() & 0xff, rand() & 0xff);
        outhead1("%s", label);
        outline1("LDD %sseed", label);
        outline0("ASLB");
        outline0("ASLB");
        outline0("ROLA");
        outline1("ADDD %sseed+2", label);
        outline1("LSR %sseed", label);
        outline1("ROR %sseed+1", label);
        outline0("ASLB");
        outline0("ROLA");
        outline1("ADDA %s", _entropy);
        outline0("ASLB");
        outline0("ROLA");
        outline0("ASLB");
        outline0("ROLA");
        outline1("ADDD %sseed+1", label);
        outline1("STD %sseed+1", label);

        outline1("LDD %sseed", label);
        outline1("STD %s", _seed);
        outline1("LDD %sseed+2", label);
        outline1("STD %s+2", _seed);

    embedded( cpu_random, src_hw_6809_cpu_random_asm );

        outline1( "LDA %s", _entropy );
        outline0( "STA <PATTERN" );
        outline0( "JSR CPURANDOM0" );
        outline0( "LDD <CPURANDOMSEED" );
        outline1( "STD %s", _seed );
        outline0( "LDD <CPURANDOMSEED+2" );
        outline1( "STD %s+2", _seed );

    done( )

}

void cpu6809_random_8bit( Environment * _environment, char * _seed, char * _entropy, char * _result ) {

    cpu6809_random( _environment, _seed, _entropy );

    outline1("LDA %s", _seed );
    outline1("STA %s", _result );

}

void cpu6809_random_16bit( Environment * _environment, char * _seed, char * _entropy, char * _result ) {

    cpu6809_random( _environment, _seed, _entropy );

    outline1("LDD %s", _seed );
    outline1("STD %s", _result );

}

void cpu6809_random_32bit( Environment * _environment, char * _seed, char * _entropy, char * _result ) {

    cpu6809_random( _environment, _seed, _entropy );

    outline1("LDD %s", _seed );
    outline1("STD %s", _result );
    outline1("LDD %s+2", _seed );
    outline1("STD %s+2", _result );

}

void cpu6809_limit_16bit( Environment * _environment, char * _variable, int _value ) {

    inline( cpu_limit_16bit )

        MAKE_LABEL

        outline0( "LDA #$0" );
        outline1( "STA %s", _variable );
        outline1( "LDA %s+1", _variable );
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

        outline1("LDA %s", _left );
        outline0("CMPA #0" );
        outline1("BEQ %s", label );
        outline1("LDA %s", _right );
        outline0("CMPA #0" );
        outline1("BEQ %s", label);
        outline0("LDA #$FF");
        outline1("STA %s", _result);
        outline1("JMP %s_2", label);
        outhead1("%s", label);
        outline0("LDA #0");
        outline1("STA %s", _result);
        outhead1("%s_2", label);

    no_embedded( cpu_logical_and_8bit )

}

void cpu6809_logical_or_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    inline( cpu_logical_or_8bit )

        MAKE_LABEL

        outline1("LDA %s", _left );
        outline0("CMPA #0" );
        outline1("BNE %s1", label );
        outline1("LDA %s", _right );
        outline0("CMPA #0" );
        outline1("BNE %s1", label);
        outline1("JMP %s0", label);
        outhead1("%s1", label);
        outline0("LDA #$FF");
        outline1("STA %s", _result);
        outline1("JMP %sx", label);
        outhead1("%s0", label);
        outline0("LDA #0");
        outline1("STA %s", _result);
        outhead1("%sx", label);

    no_embedded( cpu_logical_and_8bit )

}

void cpu6809_logical_not_8bit( Environment * _environment, char * _value, char * _result ) {

    inline( cpu_logical_not_8bit )

        outline1("LDA %s", _value );
        outline0("EORA #$FF" );
        outline1("STA %s", _result );

    no_embedded( cpu_logical_not_8bit )

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

        outline1("LDD %s", _variable );
        outline0("ADDD #1" );
        outline1("STD %s", _variable );

    no_embedded( cpu_inc_16bit )

}

void cpu6809_inc_32bit( Environment * _environment, char * _variable ) {

    inline( cpu_inc_32bit )

        outline0("ANDCC #$fe" );
        outline1("LDD %s+2", _variable );
        outline0("ADDD #1" );
        outline1("STD %s+2", _variable );
        outline1("LDD %s", _variable );
        outline0("ADDD #0" );
        outline1("STD %s", _variable );

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

        outline1("LDX %s", _value);
        outline1("LDA %s", _source);
        outline0("STA ,X");

    no_embedded( cpu_move_8bit_indirect )

}

void cpu6809_move_8bit_indirect_with_offset( Environment * _environment, char *_source, char * _value, int _offset ) {

    inline( cpu_move_8bit_indirect_with_offset )

        outline1("LDX %s", _value);
        if ( _offset >= 0x7f ) {
            outline0("LEAX 127,X" );
            _offset -= 0x7f;
        }
        outline1("LEAX %d,X", ( _offset & 0x7f ) );
        outline1("LDA %s", _source);
        outline0("STA ,X");

    no_embedded( cpu_move_8bit_indirect_with_offset )

}

void cpu6809_move_8bit_with_offset( Environment * _environment, char *_source, char * _value, int _offset ) {

    inline( cpu_move_8bit_with_offset )

        outline1("LDX %s", _value);
        if ( _offset >= 0x7f ) {
            outline0("LEAX 127,X" );
            _offset -= 0x7f;
        }
        outline1("LEAX %d,X", ( _offset & 0x7f ) );
        outline1("LDA %s", _source);
        outline0("STA ,X");

    no_embedded( cpu_move_8bit_with_offset )

}

void cpu6809_move_8bit_indirect_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

    inline( cpu_move_8bit_indirect_with_offset2 )

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

        outline1("LDX %s", _value);
        outline0("LDA ,X");
        outline1("STA %s", _source );

    no_embedded( cpu_move_8bit_indirect_with_offset2 )

}

void cpu6809_move_16bit_indirect( Environment * _environment, char *_source, char * _value ) {

    inline( cpu_move_16bit_indirect )

        MAKE_LABEL

        outline1("LDX %s", _value);
        outline1("LDD %s", _source);
        outline0("STD ,X");

    no_embedded( cpu_move_16bit_indirect )

}

void cpu6809_move_16bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    inline( cpu_move_16bit_indirect2 )

        MAKE_LABEL

        outline1("LDX %s", _value);
        outline0("LDD ,X");
        outline1("STD %s", _source );

    no_embedded( cpu_move_16bit_indirect2 )

}

void cpu6809_move_32bit_indirect( Environment * _environment, char *_source, char * _value ) {

    inline( cpu_move_32bit_indirect )

        MAKE_LABEL

        outline1("LDX %s", _value);
        outline0("LDD ,X");
        outline1("STD %s", _source );
        outline0("LEAX 2,X");
        outline0("LDD ,X");
        outline1("STD %s+2", _source );

    no_embedded( cpu_move_32bit_indirect )

}

void cpu6809_move_32bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    inline( cpu_move_32bit_indirect2 )

        MAKE_LABEL

        outline1("LDX %s", _value);
        outline0("LDD ,X");
        outline1("STD %s", _source );
        outline0("LEAX 2,X");
        outline0("LDD ,X");
        outline1("STD %s+2", _source );
    
    no_embedded( cpu_move_32bit_indirect2 )

}

void cpu6809_uppercase( Environment * _environment, char *_source, char *_size, char *_result ) {

    inline( cpu_uppercase )

        MAKE_LABEL

        outline0("LDB #0" );
        outline1("LDX %s", _source );
        if ( _result ) {
            outline1("LDY %s", _result );
        } else {
            outline1("LDY %s", _source );
        }
        outhead1("%supper", label );
        outline0("LDA B, X" );
        
        outline0("CMPA #97");
        outline1("BLO %snext", label);

        outline0("CMPA #122");
        outline1("BHI %snext", label);

        outline0("ANDCC #$FE");
        outline0("SUBA #32");

        outhead1("%snext", label );
        outline0("STA B, Y" );
        outline0("ADDB #1" );
        outline1("CMPB %s", _size );
        outline1("BNE %supper", label );

    no_embedded( cpu_uppercase )


}

void cpu6809_lowercase( Environment * _environment, char *_source, char *_size, char *_result ) {

    inline( cpu_lowercase )

        MAKE_LABEL

        outline0("LDB #0" );
        outline1("LDX %s", _source );
        if ( _result ) {
            outline1("LDY %s", _result );
        } else {
            outline1("LDY %s", _source );
        }
        outhead1("%slower", label );
        outline0("LDA B, X" );
        
        outline0("CMPA #65");
        outline1("BLO %snext", label);

        outline0("CMPA #90");
        outline1("BHI %snext", label);

        outline0("ANDCC #$FE");
        outline0("ADDA #32");

        outhead1("%snext", label );
        outline0("STA B, Y" );
        outline0("ADDB #1" );
        outline1("CMPB %s", _size );
        outline1("BNE %slower", label );

    no_embedded( cpu_lowercase )

}

void cpu6809_convert_string_into_16bit( Environment * _environment, char * _string, char * _len, char * _value ) {

    inline( cpu_convert_string_into_16bit )

        MAKE_LABEL

        // Y = 0
        outline0("LDY #0");

        outline0("LDB #0");
        outline1("LDX %s", _string );

        outhead1("%sloop", label );

        // stringa finita? -> fine
        outline1("CMPB %s", _len );
        outline1("BEQ %sdone", label );

        // moltiplico Y per 10
        outline0("PSHS D" );
        outline0("TFR Y, D" );
        outline0("LEAY D, Y" );
        outline0("LEAY D, Y" );
        outline0("LEAY D, Y" );
        outline0("LEAY D, Y" );
        outline0("TFR Y, D" );
        outline0("LEAY D, Y" );
        outline0("PULS D" );

        // leggo carattere
        outline0("LDA B,X" );

        // numero? no -> fine
        outline0("CMPA #48" );
        outline1("BLO %sdone", label );
        outline0("CMPA #57" );
        outline1("BHI %sdone", label );

        // aggiungo il numero al registro Y
        outline0("SUBA #48" );
        outline0("LEAY A, Y" );

        // ripeti
        outline0("INCB" );
        outline1("JMP %sloop", label );

        outhead1("%sdone", label );

        outline1("STY %s", _value );

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

        outline1("LDX %s", _source);
        outline1("LDY %s", _destination);
        outline1("LDB %s", _size);
        outline0("LEAY B, Y");
        outline0("LEAY -1, Y");
        outline0("LDB #0");

        outhead1("%sx", label);
        outline1("CMPB %s", _size);
        outline1("BEQ %sdone", label);
        outline0("LDA B,X");
        outline0("STA ,Y");
        outline0("LEAY -1, Y");
        outline0("INCB");
        outline1("JMP %sx", label);
        outhead1("%sdone", label);

    no_embedded( cpu_flip )

}

void cpu6809_bit_check( Environment * _environment, char * _value, int _position, char *_result, int _bitwidth ) {

    inline( cpu_bit_check )

        MAKE_LABEL

        outline1("LDB #$%2.2x", 1 << ( ( _position ) & 0x07 ) );
        outline0("STB <MATHPTR0" );
        switch( _position ) {
            case 31: case 30: case 29: case 28: case 27: case 26: case 25: case 24: 
                outline1("LDA %s", _value);
                break;
            case 23: case 22: case 21: case 20: case 19: case 18: case 17: case 16:
                outline1("LDA %s+1", _value);
                break;
            case 15: case 14: case 13: case 12: case 11: case 10: case 9: case 8:
                outline2("LDA %s+%d", _value, ( _bitwidth / 8 ) - 2 );
                break;
            case 7:  case 6:  case 5:  case 4:  case 3:  case 2:  case 1: case 0:
                outline2("LDA %s+%d", _value, ( _bitwidth / 8 ) - 1 );
                break;
        }
        outline0("ANDA <MATHPTR0" );
        outline0("CMPA #0" );
        outline1("BEQ %szero", label);
        outhead1("%sone", label)
        outline0("LDA #$ff");
        outline1("JMP %send", label );
        outhead1("%szero", label)
        outline0("LDA #$0");
        outhead1("%send", label)
        outline1("STA %s", _result);

    no_embedded( cpu_bit_check )

}

void cpu6809_bit_check_extended( Environment * _environment, char * _value, char * _position, char *_result, int _bitwidth ) {

    inline( cpu_bit_check_extended )

        MAKE_LABEL

        outline0("LDA #1" );
        outline1("LDB %s", _position );
        outline0("ANDB #$07" );
        outhead1("%s", label );
        outline0("CMPB #0" );
        outline1("BEQ %sdone", label );
        outline0("LSLA" );
        outline0("DECB" );
        outline1("JMP %s", label );

        outhead1("%sdone", label );
        outline0("STA <MATHPTR0" );

        outline1("LDB %s", _position );
        outline0("CMPB #24" );
        outline1("BLO %s_24", label );

        // 32-24
        outline1("LDA %s", _value );
        outline1("JMP %seval", label );

        outhead1("%s_24", label );
        outline0("CMPB #16" );
        outline1("BLO %s_16", label );

        // 24-16
        outline1("LDA %s+1", _value );
        outline1("JMP %seval", label );

        outhead1("%s_16", label );
        outline0("CMPB #8" );
        outline1("BLO %s_8", label );

        // 16-8
        outline2("LDA %s+%d", _value, ( _bitwidth / 8 ) - 2  );
        outline1("JMP %seval", label );

        outhead1("%s_8", label );

        // 8-0
        outline2("LDA %s+%d", _value, ( _bitwidth / 8 ) - 1  );
        outline1("JMP %seval", label );

        outhead1("%seval", label );
        outline0("ANDA <MATHPTR0" );
        outline0("CMPA #0" );
        outline1("BEQ %szero", label);
        outhead1("%sone", label)
        outline0("LDA #$ff");
        outline1("JMP %send", label );
        outhead1("%szero", label)
        outline0("LDA #$0");
        outhead1("%send", label)
        outline1("STA %s", _result);

    no_embedded( cpu_bit_check_extended )

}

void cpu6809_number_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits, int _signed ) {

    MAKE_LABEL

    deploy( numberToString, src_hw_6809_number_to_string_asm );

    outline1("LDX %s", _string );
    outline0("STX <TMPPTR");

    outline0("LDA #0");
    outline0("STA <MATHPTR0");
    outline0("STA <MATHPTR3");
    outline0("STA <MATHPTR2");
    outline0("STA <MATHPTR1");
    outline0("STA <MATHPTR4");

    switch( _bits ) {
        case 32:
            outline1("LDA %s", _number );
            if ( _signed && _bits == 32 ) {
                outline0("AND #$80");
                outline0("STA <MATHPTR4");
                outline1("LDA %s", _number );
            }
            outline0("STA <MATHPTR0");
            outline1("LDA %s+1", _number );
            outline0("STA <MATHPTR1");
            outline1("LDA %s+2", _number );    
            outline0("STA <MATHPTR2");
            outline1("LDA %s+3", _number );
            outline0("STA <MATHPTR3");
            break;
        case 16:
            outline0("LDA #0" );
            outline0("STA <MATHPTR0");
            outline0("STA <MATHPTR1");
            outline1("LDA %s", _number );    
            if ( _signed && _bits == 16 ) {
                outline0("ANDA #$80");
                outline0("STA <MATHPTR4");
                outline1("LDA %s", _number );
            }
            outline0("STA <MATHPTR2");
            outline1("LDA %s+1", _number );
            outline0("STA <MATHPTR3");
            break;
        case 8:
            outline0("LDA #0" );
            outline0("STA <MATHPTR0");
            outline0("STA <MATHPTR1");
            outline0("STA <MATHPTR2");
            outline1("LDA %s", _number );    
            if ( _signed && _bits == 8 ) {
                outline0("ANDA #$80");
                outline0("STA <MATHPTR4");
                outline1("LDA %s", _number );
            }
            outline0("STA <MATHPTR3");
            break;
    }

    outline0("LDA <MATHPTR4");
    outline0("ANDA #$80" );
    outline1("BEQ %spositive", label );

    switch( _bits ) {
        case 32:
            outline0("LDA <MATHPTR0" );
            outline0("EORA #$ff" );
            outline0("STA <MATHPTR0" );
            outline0("LDA <MATHPTR1" );
            outline0("EORA #$ff" );
            outline0("STA <MATHPTR1" );
            outline0("LDA <MATHPTR2" );
            outline0("EORA #$ff" );
            outline0("STA <MATHPTR2" );
            outline0("LDA <MATHPTR3" );
            outline0("EORA #$ff" );
            outline0("STA <MATHPTR3" );

            outline0("ANDCC #$FE" );
            outline0("LDA #$01" );
            outline0("ADDA <MATHPTR3" );
            outline0("STA <MATHPTR3" );
            outline0("LDA #$00" );
            outline0("ADDA <MATHPTR2" );
            outline0("STA <MATHPTR2" );
            outline0("LDA #$00" );
            outline0("ADDA <MATHPTR1" );
            outline0("STA <MATHPTR1" );
            outline0("LDA #$00" );
            outline0("ADDA <MATHPTR0" );
            outline0("STA <MATHPTR0" );
            break;
        case 16:
            outline0("LDA <MATHPTR2" );
            outline0("EORA #$ff" );
            outline0("STA <MATHPTR2" );
            outline0("LDA <MATHPTR3" );
            outline0("EORA #$ff" );
            outline0("STA <MATHPTR3" );

            outline0("ANDCC #$FE" );
            outline0("LDA #$01" );
            outline0("ADDA <MATHPTR3" );
            outline0("STA <MATHPTR3" );
            outline0("LDA #$00" );
            outline0("ADDA <MATHPTR2" );
            outline0("STA <MATHPTR2" );
            break;
        case 8:
            outline0("LDA <MATHPTR3" );
            outline0("EORA #$ff" );
            outline0("STA <MATHPTR3" );

            outline0("ANDCC #$FE" );
            outline0("LDA #$01" );
            outline0("ADDA <MATHPTR3" );
            outline0("STA <MATHPTR3" );
            break;
    }

    outline0("LDX <MATHPTR2" );

    outhead1("%spositive", label );
    outline1("LDA #$%2.2X", _bits );
    outline0("STA <MATHPTR5");

    outline0("JSR N2STRING");

    outline0("LDA <MATHPTR5" );
    outline1("STA %s", _string_size);

}

void cpu6809_bits_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits ) {

    deploy( bitsToString, src_hw_6809_bits_to_string_asm );

    switch( _bits ) {
        case 32:
            outline1("LDD %s", _number );
            outline0("STD <MATHPTR0" );
            outline1("LDD %s+2", _number );
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

void cpu6809_dsdefine( Environment * _environment, char * _string, char * _index ) {
    
    deploy_with_vars( dstring, src_hw_6809_dstring_asm, cpu_dstring_vars );

    outline1( "LDY #%s", _string );
    outline0( "JSR DSDEFINE" );
    outline1( "STB %s", _index );

}

void cpu6809_dsalloc( Environment * _environment, char * _size, char * _index ) {

    deploy_with_vars( dstring, src_hw_6809_dstring_asm, cpu_dstring_vars );

    outline1( "LDA %s", _size );
    outline0( "JSR DSALLOC" );
    outline1( "STB %s", _index );

}

void cpu6809_dsalloc_size( Environment * _environment, int _size, char * _index ) {

    deploy_with_vars( dstring, src_hw_6809_dstring_asm, cpu_dstring_vars );

    outline1( "LDA #$%2.2x", _size );
    outline0( "JSR DSALLOC" );
    outline1( "STB %s", _index );

}

void cpu6809_dsfree( Environment * _environment, char * _index ) {

    deploy_with_vars( dstring, src_hw_6809_dstring_asm, cpu_dstring_vars );

    outline1( "LDB %s", _index );
    outline0( "JSR DSFREE" );

}

void cpu6809_dswrite( Environment * _environment, char * _index ) {

    deploy_with_vars( dstring, src_hw_6809_dstring_asm, cpu_dstring_vars );

    outline1( "LDB %s", _index );
    outline0( "JSR DSWRITE" );

}

void cpu6809_dsresize( Environment * _environment, char * _index, char * _resize ) {

    deploy_with_vars( dstring, src_hw_6809_dstring_asm, cpu_dstring_vars );

    outline1( "LDB %s", _index );
    outline1( "LDA %s", _resize );
    outline0( "JSR DSRESIZE" );

}

void cpu6809_dsresize_size( Environment * _environment, char * _index, int _resize ) {

    deploy_with_vars( dstring, src_hw_6809_dstring_asm, cpu_dstring_vars );

    outline1( "LDB %s", _index );
    outline1( "LDA #$%2.2X", _resize );
    outline0( "JSR DSRESIZE" );

}

void cpu6809_dsgc( Environment * _environment ) {

    deploy_with_vars( dstring, src_hw_6809_dstring_asm, cpu_dstring_vars );

    outline0( "JSR DSGC" );

}

void cpu6809_dsdescriptor( Environment * _environment, char * _index, char * _address, char * _size ) {

    deploy_with_vars( dstring,src_hw_6809_dstring_asm, cpu_dstring_vars );

    outline1( "LDB %s", _index );
    outline0( "JSR DSDESCRIPTOR" );
    outline0( "LDD 1, X" );
    outline1( "STD %s", _address );
    outline0( "LDA , X" );
    outline1( "STA %s", _size );

}

void cpu6809_store_8bit_with_offset( Environment * _environment, char *_destination, int _value, int _offset ) {

    outline1("LDB $%2.2x", _offset);
    outline1("LDX #%s", _destination);
    outline1("LDA $%2.2x", _value);
    outline0("STA B,X");

}

void cpu6809_complement2_8bit( Environment * _environment, char * _source, char * _destination ) {

    outline1( "LDA %s", _source );
    outline0( "EORA #$FF" );
    if ( _destination ) {
        outline1( "STA %s", _destination );
    } else {
        outline1( "STA %s", _source );
    }
    if ( _destination ) {
        cpu6809_inc( _environment, _destination );
    } else {
        cpu6809_inc( _environment, _source );
    }

}

void cpu6809_complement2_16bit( Environment * _environment, char * _source, char * _destination ) {

    outline1( "LDA %s", _source );
    outline0( "EORA #$FF" );
    if ( _destination ) {
        outline1( "STA %s", _destination );
    } else {
        outline1( "STA %s", _source );
    }
    outline1( "LDA %s+1", _source );
    outline0( "EORA #$FF" );
    if ( _destination ) {
        outline1( "STA %s+1", _destination );
    } else {
        outline1( "STA %s+1", _source );
    }
    if ( _destination ) {
        cpu6809_inc_16bit( _environment, _destination );
    } else {
        cpu6809_inc_16bit( _environment, _source );
    }    

}

void cpu6809_complement2_32bit( Environment * _environment, char * _source, char * _destination ) {

    outline1( "LDA %s", _source );
    outline0( "EOR #$FF" );
    if ( _destination ) {
        outline1( "STA %s", _destination );
    } else {
        outline1( "STA %s", _source );
    }
    outline1( "LDA %s+1", _source );
    outline0( "EOR #$FF" );
    if ( _destination ) {
        outline1( "STA %s+1", _destination );
    } else {
        outline1( "STA %s+1", _source );
    }
    outline1( "LDA %s+2", _source );
    outline0( "EOR #$FF" );
    if ( _destination ) {
        outline1( "STA %s+2", _destination );
    } else {
        outline1( "STA %s+2", _source );
    }
    outline1( "LDA %s+3", _source );
    outline0( "EOR #$FF" );
    if ( _destination ) {
        outline1( "STA %s+3", _destination );
    } else {
        outline1( "STA %s+3", _source );
    }
    if ( _destination ) {
        cpu6809_inc_32bit( _environment, _destination );
    } else {
        cpu6809_inc_32bit( _environment, _source );
    }

}

char * src_hw_chipset_mob_asm;
unsigned int src_hw_chipset_mob_asm_len;

void cpu6809_mobinit( Environment * _environment, char * _index, char *_x, char *_y,  char *_draw) {

    // TODO: implementation
    
}

void cpu6809_mobshow( Environment * _environment, char * _index ) {

    // TODO: implementation
    
}

void cpu6809_mobhide( Environment * _environment, char * _index ) {

    // TODO: implementation
    
}

void cpu6809_mobat( Environment * _environment, char * _index, char *_x, char *_y ) {

    // TODO: implementation
    
}

void cpu6809_mobrender( Environment * _environment, int _on_vbl ) {

    // TODO: implementation
    
}

void cpu6809_sqroot( Environment * _environment, char * _number, char * _result ) {

    deploy( sqr, src_hw_6809_sqr_asm );

    outline1("LDA %s", _number );
    outline0("STA Numberh" );
    outline1("LDA %s+1", _number );
    outline0("STA Numberl" );

    outline0("JSR SQROOT" );

    outline0("LDA Root" );
    outline1("STA %s", _result );
    
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

#endif