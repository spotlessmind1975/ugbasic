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

#if defined(__pccga__)

void cpu_init( Environment * _environment ) {

}

void cpu_nop( Environment * _environment ) {

    outline0("NOP");

}

void cpu_ztoa( Environment * _environment ) {

    inline( cpu_ztoa )

        MAKE_LABEL

        outline1("JE %syes", label );
        outline0("MOV AL, 0");
        outline1("JMP %s", label );
        outhead1("%syes:", label );
        outline0("MOV AL, 0xff");
        outhead1("%s:", label );

    no_embedded( cpu_ztoa )

}

void cpu_ctoa( Environment * _environment ) {

    inline( cpu_ctoa )

        MAKE_LABEL

        outline1("JC %syes", label );
        outline0("MOV AL, 0");
        outline1("JMP %s", label );
        outhead1("%syes:", label );
        outline0("MOV AL, 0xff");
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

        outline1("JZ %s", _label);

    no_embedded( cpu_beq )

}

/**
 * @brief <i>Z80</i>: emit code to make long conditional jump

 * @param _environment Current calling environment
 * @param _label Destination of the conditional jump.
 */
void cpu_bneq( Environment * _environment, char * _label ) {

    inline( cpu_bneq )

        outline1("JNZ %s", _label);

    no_embedded( cpu_bneq )

}

void cpu_bveq( Environment * _environment, char * _value, char * _label ) {

    inline( cpu_bveq )

        outline1("MOV AL, [%s]", _value);
        outline0("CMP AL, 0");
        cpu_beq( _environment, _label );

    no_embedded( cpu_bneq )

}

void cpu_bvneq( Environment * _environment, char * _value, char * _label ) {

    inline( cpu_bvneq )

        outline1("MOV AL, [%s]", _value);
        outline0("CMP AL, 0");
        cpu_bneq( _environment, _label );

    no_embedded( cpu_bvneq )

}

void cpu_label( Environment * _environment, char * _label ) {
    outhead1("%s:", _label);
}

void cpu_peek( Environment * _environment, char * _address, char * _target ) {

    inline( cpu_peek )

        outline1("MOV SI, [%s]", _address);
        outline0("MOV AL, [SI]");
        outline1("MOV [%s], AL", _target);

    no_embedded( cpu_peek )

}

void cpu_poke( Environment * _environment, char * _address, char * _source ) {

    inline( cpu_poke )

        outline1("MOV AL, [%s]", _source);
        outline1("MOV DI, [%s]", _address);
        outline0("MOV [DI], AL");

    no_embedded( cpu_poke )

}

void cpu_poke_const( Environment * _environment, char * _address, int _source ) {

    // inline( cpu_poke )

        outline1("MOV AL, 0x%2.2x", (unsigned char)(_source&0xff));
        outline1("MOV DI, [%s]", _address);
        outline0("MOV [DI], AL");

    // no_embedded( cpu_poke )

}

void cpu_peekw( Environment * _environment, char * _address, char * _target ) {

    inline( cpu_peek )

        outline1("MOV SI, [%s]", _address);
        outline0("MOV AX, [SI]");
        outline1("MOV [%s], AX", _target);

    no_embedded( cpu_peek )

}

void cpu_pokew( Environment * _environment, char * _address, char * _source ) {

    inline( cpu_poke )

        outline1("MOV AX, [%s]", _source);
        outline1("MOV DI, [%s]", _address);
        outline0("MOV [DI], AX");

    no_embedded( cpu_poke )

}

void cpu_pokew_const( Environment * _environment, char * _address, int _source ) {

    // inline( cpu_poke )

        outline1("MOV AX, 0x%4.4x", (unsigned short)(_source&0xffFF));
        outline1("MOV DI, [%s]", _address);
        outline0("MOV [DI], AX");

    // no_embedded( cpu_poke )

}

void cpu_peekd( Environment * _environment, char * _address, char * _target ) {

    inline( cpu_peek )

        outline1("MOV SI, [%s]", _address);
        outline0("MOV AX, [SI]");
        outline1("MOV [%s], AX", _target);
        outline0("INC SI" );
        outline0("INC SI" );
        outline0("MOV AX, [SI]");
        outline1("MOV [%s], AX", address_displacement( _environment, _target, "+2" ));

    no_embedded( cpu_peek )

}

void cpu_poked( Environment * _environment, char * _address, char * _source ) {

    inline( cpu_poke )

        outline1("MOV AX, [%s]", _source);
        outline1("MOV DI, [%s]", _address);
        outline0("MOV [DI], AX");
        outline0("INC DI");
        outline0("INC DI");
        outline1("MOV AX, [%s]", address_displacement( _environment, _source, "+2") );
        outline0("MOV [DI], AX");

    no_embedded( cpu_poke )

}

void cpu_poked_const( Environment * _environment, char * _address, int _source ) {

    // inline( cpu_poke )

        outline1("MOV AX, 0x%4.4x", (unsigned short)(_source&0xffff));
        outline1("MOV DI, [%s]", _address);
        outline0("MOV [DI], AX");
        outline0("INC DI");
        outline0("INC DI");
        outline1("MOV AX, 0x%4.4x", (unsigned short)((_source>>16)&0xffff));
        outline0("MOV [DI], AX");

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

    no_inline( cpu_fill_blocks )

    embedded( cpu_fill_blocks, src_hw_8086_cpu_fill_blocks_asm );

        outline1("MOV CL, [%s]", _blocks);
        outline1("MOV AL, [%s]", _pattern);
        outline1("MOV DI, [%s]", _address);
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

    embedded( cpu_fill, src_hw_8086_cpu_fill_asm );

        if ( _bytes_width == 8 ) {
            outline1("MOV CL, [%s]", _bytes);
        } else {
            outline1("MOV CX, [%s]", _bytes);
        }

        outline1("MOV AL, [%s]", _pattern);
        outline1("MOV BX, [%s]", _address);

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

    embedded( cpu_fill, src_hw_8086_cpu_fill_asm );

        outline1("MOV CL, 0x%2.2x", (unsigned char) ( _bytes & 0xff ) );

        if ( _bytes < 256 ) {

        } else {
            outline1("MOV CH, 0x%2.2x", (unsigned char) ( ( _bytes >> 8 ) & 0xff ) );
        }

        outline1("MOV AL, [%s]", _pattern);
        outline1("MOV BX, [%s]", _address);
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

    embedded( cpu_fill, src_hw_8086_cpu_fill_asm );

        outline1("MOV CL, 0x%2.2x", (unsigned char) ( _bytes & 0xff ) );

        if ( _bytes < 256 ) {

        } else {
            outline1("MOV CH, 0x%2.2x", (unsigned char) ( ( _bytes >> 8 ) & 0xff ) );
        }

        outline1("MOV AL, 0x%2.2x", _pattern);
        outline1("MOV BX, [%s]", _address);
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

    embedded( cpu_fill, src_hw_8086_cpu_fill_asm );

        outline1("MOV CX, [%s]", _bytes);
        outline1("MOV AL, [%s]", _pattern);
        outline1("MOV BX, %s", _address);
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

    embedded( cpu_fill, src_hw_8086_cpu_fill_asm );

        outline1("MOV CL, 0x%2.2x", (unsigned char) ( _bytes & 0xff ) );

        if ( _bytes < 256 ) {

        } else {
            outline1("MOV CH, 0x%2.2x", (unsigned char) ( ( _bytes >> 8 ) & 0xff ) );
        }

        outline1("MOV AL, [%s]", _pattern);
        outline1("MOV BX, %s", _address);
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

    embedded( cpu_fill, src_hw_8086_cpu_fill_asm );

        outline1("MOV CL, 0x%2.2x", (unsigned char) ( _bytes & 0xff ) );

        if ( _bytes < 256 ) {

        } else {
            outline1("MOV CH, 0x%2.2x", (unsigned char) ( ( _bytes >> 8 ) & 0xff ) );
        }

        outline1("MOV AL, 0x%2.2x", _pattern);
        outline1("MOV BX, %s", _address);
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

        outline1("MOV AL, [%s]", _source);
        outline1("MOV [%s], AL", _destination);

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

        outline2("MOV BYTE [%s], 0x%2.2x", _destination, ( _value & 0xff ) );

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

        outline2("MOV BYTE [%s], '%c'", _destination, ( _value & 0xff ) );

    no_embedded( cpu_store_char )

}

void cpu_store_8bit_with_offset( Environment * _environment, char *_destination, int _value, int _offset ) {

    inline( cpu_store_8bit_with_offset )

        outline3("MOV BYTE [%s+%d], 0x%2.2x", _destination, ( _offset & 0xff ), ( _value & 0xff ));

    no_embedded( cpu_store_8bit_with_offset )

}

void cpu_store_8bit_with_offset2( Environment * _environment, char *_destination, char * _offset, int _value ) {

    inline( cpu_store_8bit_with_offset2 )

        outline1("MOV DI, %s", _destination );
        outline1("MOV AL, [%s]", _offset );
        outline0("MOV AH, 0" );
        outline0("ADD DI, AX" );
        outline1("MOV BYTE [DI], 0x%2.2x", ( _value & 0xff ));

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

        outline1("MOV AL, [%s]", _destination);
        outline1("MOV DI, %s", _source);
        outline0("CMP AL, [DI]");
        outline1("JNZ %s", label);
        outline1("MOV AL, 0x%2.2x", (unsigned char)(0xff*_positive));
        if ( _other ) {
            outline1("MOV [%s], AL", _other);
        } else {
            outline1("MOV [%s], AL", _destination);
        }
        outline1("JMP %sb2", label);
        outhead1("%s:", label);
        outline1("MOV AL, 0x%2.2x", (unsigned char)(0xff*(1-_positive)));
        if ( _other ) {
            outline1("MOV [%s], AL", _other);
        } else {
            outline1("MOV [%s], AL", _destination);
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

        outline1("MOV DI, %s", _source);
        outline1("CMP BYTE [DI], 0x%2.2x", (unsigned char)(_destination&0xff));
        outline1("JNZ %s", label);
        outline1("MOV AL, 0x%2.2x", (unsigned char)(0xff*_positive));
        outline1("MOV [%s], AL", _other);
        outline1("JMP %sb2", label);
        outhead1("%s:", label);
        outline1("MOV AL, 0x%2.2x", (unsigned char)(0xff*(1-_positive)));
        outline1("MOV [%s], AL", _other);
        outhead1("%sb2:", label);

    no_embedded( cpu_compare_8bit )

}

void cpu_compare_and_branch_8bit( Environment * _environment, char *_source, char * _destination,  char *_label, int _positive ) {

    inline( cpu_compare_and_branch_8bit )

        MAKE_LABEL

        outline1("MOV AL, [%s]", _destination);
        outline1("MOV BL, [%s]", _source);
        outline0("CMP AL, BL" );
        if ( _positive ) {
            outline1("JZ %s", _label);
        } else {
            outline1("JNZ %s", _label);
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

        outline1("MOV AL, 0x%2.2x", _destination);
        outline1("MOV BL, [%s]", _source);
        outline1("CMP AL, BL", _destination );
        if ( _positive ) {
            outline1("JZ %s", _label);
        } else {
            outline1("JNZ %s", _label);
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

        outline1("MOV AL, [%s]", _source);

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

        outline1("CMP AL, 0x%2.2x", _destination );
        if ( _positive ) {
            outline1("JZ %s", _label);
        } else {
            outline1("JNZ %s", _label);
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

        outline1("MOV AL, [%s]", _source);
        outline1("CMP AL, '%c'", _destination );
        if ( _positive ) {
            outline1("JZ %s", _label);
        } else {
            outline1("JNZ %s", _label);
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

    no_inline( cpu_less_than_8bit )

    embedded( cpu_less_than_8bit, src_hw_8086_cpu_less_than_8bit_asm );

        outline1("MOV AL, [%s]", _source);
        outline1("MOV BL, [%s]", _destination);
        if ( _signed ) {
            if ( _equal ) {
                outline0("CALL CPULTE8S");
            } else {
                outline0("CALL CPULT8S");
            }
        } else {
            if ( _equal ) {
                outline0("CALL CPULTE8U");
            } else {
                outline0("CALL CPULT8U");
            }
        }
        if ( _other ) {
            outline1("MOV [%s], AL", _other);
        } else {
            outline1("MOV [%s], AL", _destination);
        }

    done(  )

}

void cpu_less_than_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    no_inline( cpu_less_than_8bit )

    embedded( cpu_less_than_8bit, src_hw_8086_cpu_less_than_8bit_asm );

        outline1("MOV AL, [%s]", _source);
        outline1("MOV BL, 0x%2.2x", (unsigned char)(_destination&0xff));
        if ( _signed ) {
            if ( _equal ) {
                outline0("CALL CPULTE8S");
            } else {
                outline0("CALL CPULT8S");
            }
        } else {
            if ( _equal ) {
                outline0("CALL CPULTE8U");
            } else {
                outline0("CALL CPULT8U");
            }
        }
        if ( _other ) {
            outline1("MOV [%s], AL", _other);
        } else {
            outline1("MOV [%s], AL", _destination);
        }

    done(  )

}

void cpu_less_than_and_branch_8bit_const( Environment * _environment, char *_source, int _destination,  char *_label, int _equal, int _signed ) {

    MAKE_LABEL

    no_inline( cpu_less_than_8bit )

    embedded( cpu_less_than_8bit, src_hw_8086_cpu_less_than_8bit_asm );

        outline1("MOV AL, [%s]", _source);
        outline1("MOV BL, 0x%2.2x", (unsigned char)(_destination&0xff));
        if ( _signed ) {
            if ( _equal ) {
                outline0("CALL CPULTE8S");
            } else {
                outline0("CALL CPULT8S");
            }
        } else {
            if ( _equal ) {
                outline0("CALL CPULTE8U");
            } else {
                outline0("CALL CPULT8U");
            }
        }
        outline0("CMP AL, 0");
        outline1("JZ %sb2:", label);
        outline1("JMP %s", _label);
        outhead1("%sb2:", label);

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

        outline1("MOV AL, [%s]", _source );
        outline1("MOV BL, [%s]", _destination );
        outline0("ADD AL, BL" );
        if ( _other ) {
            outline1("MOV [%s], AL", _other );
        } else {
            outline1("MOV [%s], AL", _destination );
        }

    no_embedded( cpu_math_add_8bit )

}

void cpu_math_add_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

    inline( cpu_math_add_8bit )

        outline1("MOV AL, [%s]", _source );
        outline1("MOV BL, 0x%2.2x", (unsigned char)(_destination&0xff) );
        outline0("ADD AL, BL" );
        outline1("MOV [%s], AL", _other );

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

        outline1("MOV AL, [%s]", _source );
        outline1("MOV BL, [%s]", _destination );
        outline0("SUB AL, BL" );
        if ( _other ) {
            outline1("MOV [%s], AL", _other );
        } else {
            outline1("MOV [%s], AL", _destination );
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

        outline1("MOV AL, [%s]", _source );
        outline0("ADD AL, AL" );
        if ( _other ) {
            outline1("MOV [%s], AL", _other );
        } else {
            outline1("MOV [%s], AL", _source );
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

            outline1("MOV AL, [%s]", _source );
            outline0("MOV AH, 0" );
            outline1("MOV BL, [%s]", _destination );
            outline0("MOV BH, 0" );
            outline0("IMUL BX" );
            outline1("MOV [%s], AX", _other );

        } else {

            outline1("MOV AL, [%s]", _source );
            outline0("MOV AH, 0" );
            outline1("MOV BL, [%s]", _destination );
            outline0("MOV BH, 0" );
            outline0("MUL BX" );
            outline1("MOV [%s], AX", _other );

        }

    no_embedded( cpu_math_mul_8bit_to_16bit )

}

/**
 * @brief <i>Z80</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu_math_div2_const_8bit( Environment * _environment, char *_source, int _steps, int _signed, char * _remainder ) {

    no_inline( cpu_math_div2_const_8bit )

    embedded( cpu_math_div2_const_8bit, src_hw_8086_cpu_math_div2_const_8bit_asm );

        if ( _remainder ) {
            outline1("MOV AL, [%s]", _source );
            outline0("AND 0x1" );
            outline1("MOV [%s], AL", _remainder );
        }
        outline1("MOV AL, [%s]", _source);
        outline1("MOV CL, 0x%2.2x", _steps);
        if ( _signed ) {
            outline0("CALL CPUDIV2CONST8S");
        } else {
            outline0("CALL CPUDIV2CONST8U");
        }
        outline1("MOV [%s], AL", _source);

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

    embedded( cpu_math_mul2_const_8bit, src_hw_8086_cpu_math_mul2_const_8bit_asm );

        outline1("MOV AL, [%s]", _source);
        outline1("MOV CL, 0x%2.2x", _steps);
        if ( _signed ) {
            outline0("CALL CPUMUL2CONST8S");
        } else {
            outline0("CALL CPUMUL2CONST8U");
        }
        outline1("MOV [%s], AL", _source);

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

        outline1("MOV BL, [%s]", _source );
        outline1("MOV AL, 0x%2.2x", ( _value & 0xff ) );
        outline0("SUB AL, BL" );
        outline1("MOV [%s], AL", _source );

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

        outline1("MOV AL, [%s]", _source );
        outline1("AND AL, 0x%2.2x", _mask );
        outline1("MOV [%s], AL", _source );

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

        outline1("MOV AX, [%s]", _source );
        outline1("MOV [%s], AX", _destination );

    no_embedded( cpu_move_16bit )

}

void cpu_addressof_16bit( Environment * _environment, char *_source, char *_destination ) {
    
    inline( cpu_addressof_16bit )

        outline1("MOV AX, %s", _source );
        outline1("MOV [%s], AX", _destination );

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

        outline1("MOV AX, 0x%4.4x", _value & 0xffff );
        outline1("MOV [%s], AX", _destination );

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

        outline1("MOV AX, [%s]", _source);
        outline1("MOV BX, [%s]", _destination);
        outline0("CMP AX, BX");
        outline1("JNZ %s", label);
        outline1("MOV AL, 0x%2.2x", 0xff*_positive);
        if ( _other ) {
            outline1("MOV [%s], AL", _other);
        } else {
            outline1("MOV [%s], AL", _destination);
        }
        outline1("JMP %sb2", label);
        outhead1("%s:", label);
        outline1("MOV AL, 0x%2.2x", 0xff*(1-_positive));
        if ( _other ) {
            outline1("MOV [%s], AL", _other);
        } else {
            outline1("MOV [%s], AL", _destination);
        }
        outhead1("%sb2:", label);

    no_embedded( cpu_compare_16bit )

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

        outline1("MOV AX, [%s]", _source);
        outline1("MOV BX, 0x%4.4x", _destination);
        outline0("CMP AX, BX");
        outline1("JNZ %s", label);
        outline1("MOV AL, 0x%2.2x", 0xff*_positive);
        if ( _other ) {
            outline1("MOV [%s], AL", _other);
        } else {
            outline1("MOV [%s], AL", _destination);
        }
        outline1("JMP %sb2", label);
        outhead1("%s:", label);
        outline1("MOV AL, 0x%2.2x", 0xff*(1-_positive));
        if ( _other ) {
            outline1("MOV [%s], AL", _other);
        } else {
            outline1("MOV [%s], AL", _destination);
        }
        outhead1("%sb2:", label);

    no_embedded( cpu_compare_16bit )

}

void cpu_compare_and_branch_16bit( Environment * _environment, char *_source, char *_destination,  char *_label, int _positive ) {

    inline( cpu_compare_and_branch_16bit )

        MAKE_LABEL

        outline1("MOV AX, [%s]", _source);
        outline1("MOV BX, [%s]", _destination);
        outline0("CMP AX, BX");
        if ( _positive ) {
            outline1("JZ %s", _label);
        } else {
            outline1("JNZ %s", _label);
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

        outline1("MOV AX, [%s]", _source);
        outline1("MOV BX, 0x%4.4x", _destination);
        outline0("CMP AX, BX");
        if ( _positive ) {
            outline1("JZ %s", _label);
        } else {
            outline1("JNZ %s", _label);
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

    no_inline( cpu_less_than_16bit )

    embedded( cpu_less_than_16bit, src_hw_8086_cpu_less_than_16bit_asm );

        if ( _signed ) {

            outline1("MOV AX, [%s]", _source);
            outline1("MOV BX, [%s]", _destination);
            if ( _equal ) {
                outline0("CALL CPULTE16S");
            } else {
                outline0("CALL CPULT16S");
            }
            if ( _other ) {
                outline1("MOV [%s], AL", _other);
            } else {
                outline1("MOV [%s], AL", _destination);
            }

        } else {

            outline1("MOV AX, [%s]", _destination);
            outline1("MOV BX, [%s]", _source);
            if ( _equal ) {
                outline0("CALL CPULTE16U");
            } else {
                outline0("CALL CPULT16U");
            }
            if ( _other ) {
                outline1("MOV [%s], AL", _other);
            } else {
                outline1("MOV [%s], AL", _destination);
            }

        }

    done(  )

}

void cpu_less_than_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    no_inline( cpu_less_than_16bit )

    embedded( cpu_less_than_16bit, src_hw_8086_cpu_less_than_16bit_asm );

        if ( _signed ) {

            outline1("MOV AX, [%s]", _source);
            outline1("MOV BX, 0x%4.4x", _destination);
            if ( _equal ) {
                outline0("CALL CPULTE16S");
            } else {
                outline0("CALL CPULT16S");
            }
            if ( _other ) {
                outline1("MOV [%s], AL", _other);
            } else {
                outline1("MOV [%s], AL", _destination);
            }

        } else {

            outline1("MOV AX, 0x%4.4x", _destination);
            outline1("MOV BX, [%s]", _source);
            if ( _equal ) {
                outline0("CALL CPULTE16U");
            } else {
                outline0("CALL CPULT16U");
            }
            if ( _other ) {
                outline1("MOV [%s], AL", _other);
            } else {
                outline1("MOV [%s], AL", _destination);
            }

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

        outline1("MOV AX, [%s]", _source );
        outline1("MOV BX, [%s]", _destination );
        outline0("ADD AX, BX" );
        if ( _other ) {
            outline1("MOV [%s], AX", _other );
        } else {
            outline1("MOV [%s], AX", _destination );
        }

    no_embedded( cpu_math_add_16bit )

}

void cpu_math_add_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

    inline( cpu_math_add_16bit )

        outline1("MOV AX, [%s]", _source );
        outline1("MOV BX, 0x%4.4x", ( _destination & 0xffff ) );
        outline0("ADD AX, BX" );
        outline1("MOV [%s], AX", _other );

    no_embedded( cpu_math_add_16bit )

}

void cpu_math_add_16bit_with_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    inline( cpu_math_add_16bit_with_16bit )

        outline1("MOV AX, [%s]", _source );
        outline1("MOV BX, %s", _destination );
        outline0("ADD AX, BX" );
        outline1("MOV [%s], AX", _other );

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

        outline1("MOV AX, [%s]", _source );
        outline0("SAL AX, 1" );
        if ( _other ) {
            outline1("MOV [%s], AX", _other );
        } else {
            outline1("MOV [%s], AX", _source );
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

        outline1("MOV AX, [%s]", _source );
        outline1("MOV BX, [%s]", _destination );
        if ( _signed ) {

            outline0("IMUL BX" );

        } else {

            outline1("MUL BX", _source );

        }

        outline1("MOV [%s], AX", _other );
        outline1("MOV [%s], DX", address_displacement( _environment, _other, "+2" ) );

    no_embedded( cpu_math_mul_16bit_to_32bit );

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

        outline1("JMP %s", afterLabel );

        outhead2("CPUMATHMULNBITTONBIT%d_SOURCE: times %d db 0", _bits>>3, _bits>>3 );
        outhead2("CPUMATHMULNBITTONBIT%d_DESTINATION: times %d db 0", _bits>>3, _bits>>3 );
        outhead2("CPUMATHMULNBITTONBIT%d_OTHER: times %d db 0", _bits>>3, _bits>>3 );

        outhead1("CPUMATHMULNBITTONBIT%d:", _bits>>3);
        outhead0("MOV AL, $00");
        for( i=0; i<(_bits>>3); ++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
            outline1("MOV [%s], AL", address_displacement( _environment, other, offset ) );
        }
        outline1("MOV CL, 0x%2.2x", _bits );

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

        outline1("MOV AL, [%s]", address_displacement( _environment, destination, offset ) );
        outline0("SAR AL, 1" );
        outline1("MOV [%s], AL", address_displacement( _environment, destination, offset ) );
        for( i=(_bits>>3)-2; i>-1; --i ) {
            sprintf( offset, "%d", i );
            outline1("MOV AL, [%s]", address_displacement( _environment, destination, offset ) );
            outline0("ROR AL, 1" );
            outline1("MOV [%s], AL", address_displacement( _environment, destination, offset ) );
        }
        outline1("JC %sx", multiplyByBit0Label );
        outline1("JMP %s", multiplyByBit0Label );
        outhead1("%sx:", multiplyByBit0Label );

        // Step 2: Multiply the rightmost digit or the least significant bit (LSB) 
        // of the multiplier (1) with all the digits of the multiplicand (11101).

        outline0("CLC" );
        for( i=0; i<(_bits>>3); ++i ) {
            sprintf( offset, "%d", i );
            outline1("MOV AL, [%s]", address_displacement( _environment, source, offset ) );
            outline1("ADC AL, [%s]", address_displacement( _environment, other, offset ) );
            outline1("MOV [%s], AL", address_displacement( _environment, other, offset ) );
        }

        // Step 3: Add a place holder of '0' or 'X' before multiplying the next 
        // higher order digit of the multiplier& with the multiplicand.

        outhead1("%s:", multiplyByBit0Label);

        outline0("CLC" );
        outline1("MOV AL, [%s]", address_displacement( _environment, source, "0" ) );
        outline0("SAL AL, 1" );
        outline1("MOV [%s], AL", address_displacement( _environment, source, "0" ) );
        for( i=1; i<(_bits>>3); ++i ) {
            sprintf( offset, "%d", i );
            outline1("MOV AL, [%s]", address_displacement( _environment, source, offset ) );
            outline0("ROL AL, 1" );
            outline1("MOV [%s], AL", address_displacement( _environment, source, offset ) );
        }

        // Step 4: Repeat the same process for all the next higher-order digits 
        // until we reach the most significant bit (MSB) which is the left-most 
        // digit of the multiplicand with the multiplier.

        outline0("DEC CL" );
        outline0("CMP CL, 0" );
        outline1("JNZ CPUMATHMULNBITTONBIT%dL1", (_bits>>3) );

        outline0("RET" );

        // Step 5: The product obtained in each row is called the partial product. 
        // Finally, add all the partial products. To add all the binary numbers 
        // use the rules of binary addition.

        // (The rules for binary addition are listed as follows: 0 + 0 = 0, 0 + 1 = 1, and 1 + 1 = 0, with a carryover of 1. So, 1 + 1 = 10 and 1 + 1 + 1 = 11 in the binary number system)
        outhead1("%s:", afterLabel );

    }

    for( i=0; i<(_bits>>3); ++i ) {
        char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
        outline1("MOV AL, [%s]", address_displacement( _environment, _source, offset ) );
        outline1("MOV [%s], AL", address_displacement( _environment, source, offset ) );
        outline1("MOV AL, [%s]", address_displacement( _environment, _destination, offset ) );
        outline1("MOV [%s], AL", address_displacement( _environment, destination, offset ) );
    }
    outline1("CALL CPUMATHMULNBITTONBIT%d", _bits >> 3 );
    for( i=0; i<(_bits>>3); ++i ) {
        char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
        outline1("MOV AL, [%s]", address_displacement( _environment, other, offset ) );
        if ( _other ) {
            outline1("MOV [%s], AL", address_displacement( _environment, _other, offset ) );
        } else {
            outline1("MOV [%s], AL", address_displacement( _environment, _destination, offset ) );
        }
    }

    // done()

}


void cpu_math_mul2_const_nbit( Environment * _environment, char *_source, int _steps, int _bits ) {

    int i;

    inline( cpu_math_mul2_const_nbit )

        char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", (_bits>>3)-1 );
        outline1("MOV AL, [%s]", address_displacement(_environment, _source, offset));
        outline0("AND AL, 0x80");
        outline0("MOV BL, AL");
        while( _steps ) {
            outline0("CLC")
            outline1("MOV AL, [%s]", address_displacement(_environment, _source, "0"));
            outline0("SAL AL, 1");
            outline1("MOV [%s], AL", address_displacement(_environment, _source, "0"));
            for( i=1; i<(_bits>>3); ++i ) {
                char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i);
                outline1("MOV AL, [%s]", address_displacement(_environment, _source, offset));
                outline0("ROL AL, 1");
                outline1("MOV [%s], AL", address_displacement(_environment, _source, offset));
            }
            --_steps;
        }
        outline1("MOV AL, [%s]", address_displacement(_environment, _source, offset));
        outline0("OR AL, BL");
        outline1("MOV [%s], AL", address_displacement(_environment, _source, offset));

    no_embedded( cpu_math_mul2_const_nbit )

}

void cpu_math_div2_const_nbit( Environment * _environment, char *_source, int _steps, int _bits, char * _remainder ) {

    inline( cpu_math_div2_const_nbit )

        MAKE_LABEL

        if ( _remainder ) {
            outline1("MOV AL, [%s]", _source);
            outline0("AND AL, 0x01" );
            outline1("MOV [%s], AL", _remainder);
        }
        char offsetMsb[MAX_TEMPORARY_STORAGE]; sprintf( offsetMsb, "%d", (_bits>>3)-1 );

        outline1("MOV AL, [%s]", address_displacement(_environment, _source, offsetMsb));
        outline0("AND AL, 0x80");
        outline0("MOV BL, AL");
        outline0("CMP AL, 0x80");
        outline1("JNZ %snocomplement", label );
        cpu_complement2_nbit( _environment, _source, _source, _bits );
        outhead1("%snocomplement:", label );
        while( _steps ) {
            outline0("CLC");
            outline1("MOV AL, [%s]", address_displacement(_environment, _source, offsetMsb));
            outline0("SAR AL, 1");
            outline1("MOV [%s], AL", address_displacement(_environment, _source, offsetMsb));
            for( int i=(_bits>>3)-2; i>-1; --i ) {
                char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
                outline1("MOV AL, [%s]", address_displacement(_environment, _source, offset));
                outline0("ROR AL, 1");
                outline1("MOV [%s], AL", address_displacement(_environment, _source, offset));
            }
            --_steps;
        }
        outline0("MOV AL, BL");
        outline0("CMP AL, 0x80");
        outline1("JNZ %snocomplement2", label );
        cpu_complement2_nbit( _environment, _source, _source, _bits );
        outhead1("%snocomplement2:", label );

    no_embedded( cpu_math_div2_const_nbit )

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

        outline1("MOV AX, [%s]", _source );
        outline1("MOV BX, [%s]", _destination );
        outline0("SBB AX, BX" );
        if ( _other ) {
            outline1("MOV [%s], AX", _other );
        } else {
            outline1("MOV [%s], AX", _destination );
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

        outline1("MOV AX, 0x%4.4x", _value );
        outline1("MOV BX, [%s]", _source );
        outline0("SUB AX, BX" );
        outline1("MOV [%s], AX", _source );

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

    no_inline( cpu_math_div2_const_16bit )

    embedded( cpu_math_div2_const_16bit, src_hw_8086_cpu_math_div2_const_16bit_asm )

        if ( _remainder ) {
            outline1("MOV AX, [%s]", _source );
            outline0("AND AL, 0x1" );
            outline1("MOV [%s], AL", _remainder );
        }
        if ( _signed ) {
            if ( _steps ) {
                outline1("MOV AX, [%s]", _source );
                outline1("MOV CL, 0x%2.2x", _steps );
                outline0("CALL CPUDIV2CONST16S" );
                outline1("MOV [%s], AX", _source );
            }
        } else {
            if ( _steps ) {
                outline1("MOV AX, [%s]", _source );
                outline1("MOV CL, 0x%2.2x", _steps );
                outline0("CALL CPUDIV2CONST16U" );
                outline1("MOV [%s], AX", _source );
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

        outline1("MOV AX, [%s]", _source );
        outline1("MOV CL, 0x%2.2x", _steps );
        outline0("SAL AX, CL" );
        outline1("MOV [%s], AX", _source );

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

        outline1("MOV AX, [%s]", _source );
        outline1("AND AX, 0x%4.4x", (unsigned short)( _mask & 0xffff ) );
        outline1("MOV [%s], AX", _source );

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

        outline1("MOV AX, [%s]", _source );
        outline1("MOV [%s], AX", _destination );
        outline1("MOV AX, [%s]", address_displacement(_environment, _source, "2") );
        outline1("MOV [%s], AX", address_displacement(_environment, _destination, "2") );
        
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

        outline1("MOV AX, 0x%4.4x", ( _value & 0xffff ) );
        outline1("MOV [%s], AX", _destination );
        outline1("MOV AX, 0x%4.4x", ( ( _value >> 16 ) & 0xffff ) );
        outline1("MOV [%s], AX", address_displacement(_environment, _destination, "2") );

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

        outline1("MOV AX, [%s]", _source);
        outline1("MOV BX, [%s]", _destination);
        outline0("CMP AX, BX");
        outline1("JNZ %s", label);
        outline1("MOV AX, [%s]", address_displacement(_environment, _source, "2"));
        outline1("MOV BX, [%s]", address_displacement(_environment, _destination, "2"));
        outline0("CMP AX, BX");
        outline1("JNZ %s", label);
        outline1("MOV AL, 0x%2.2x", 0xff*_positive);
        if ( _other ) {
            outline1("MOV [%s], AL", _other);
        } else {
            outline1("MOV [%s], AL", _destination);
        }
        outline1("JMP %s_2", label);
        outhead1("%s:", label);
        outline1("MOV AL, 0x%2.2x", 0xff*(1-_positive));
        if ( _other ) {
            outline1("MOV [%s], AL", _other);
        } else {
            outline1("MOV [%s], AL", _destination);
        }
        outhead1("%s_2:", label);

    no_embedded( cpu_compare_32bit )
    
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

        outline1("MOV AX, [%s]", _source);
        outline1("MOV BX, 0x%4.4x", (unsigned short)(_destination&0xffff));
        outline0("CMP AX, BX");
        outline1("JNZ %s", label);
        outline1("MOV AX, [%s]", address_displacement(_environment, _source, "2"));
        outline1("MOV BX, 0x%4.4x", (unsigned short)((_destination>>16)&0xffff));
        outline0("CMP AX, BX");
        outline1("JNZ %s", label);
        outline1("MOV AL, 0x%2.2x", 0xff*_positive);
        outline1("MOV [%s], AL", _other);
        outline1("JMP %s_2", label);
        outhead1("%s:", label);
        outline1("MOV AL, 0x%2.2x", 0xff*(1-_positive));
        outline1("MOV [%s], AL", _other);
        outhead1("%s_2:", label);

    no_embedded( cpu_compare_32bit )
    
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

        outline1("MOV AX, [%s]", _source);
        outline1("MOV BX, 0x%4.4x", (unsigned short)(_destination&0xffff));
        outline0("CMP AX, BX");
        outline1("JNZ %s", label);
        outline1("MOV AX, [%s]", address_displacement(_environment, _source, "2"));
        outline1("MOV BX, 0x%4.4x", (unsigned short)((_destination>>16)&0xffff));
        outline0("CMP AX, BX");
        outline1("JNZ %s", label);
        if ( _positive ) {
            outline1("JMP %s", _label);
            outhead1("%s:", label );
        } else {
            outline1("JMP %snot", label);
            outhead1("%s:", label );
            outline1("JMP %s", _label);
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

    no_inline( cpu_less_than_32bit )

    embedded( cpu_less_than_32bit, src_hw_8086_cpu_less_than_32bit_asm );

        outline1("MOV BX, [%s]", _source);
        outline1("MOV AX, [%s]", address_displacement( _environment, _source, "+2" ) );
        outline1("MOV DX, [%s]", _destination);
        outline1("MOV CX, [%s]", address_displacement( _environment, _destination, "+2" ) );
        if ( _signed ) {

            if ( _equal ) {
                outline0("CALL CPULTE32S");
            } else {
                outline0("CALL CPULT32S");
            }
        } else {
            if ( _equal ) {
                outline0("CALL CPULTE32U");
            } else {
                outline0("CALL CPULT32U");
            }
        }
        if ( _other ) {
            outline1("MOV [%s], AL", _other);
        } else {
            outline1("MOV [%s], AL", _destination);
        }

    done(  )


}

void cpu_less_than_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    MAKE_LABEL

    no_inline( cpu_less_than_32bit )

    embedded( cpu_less_than_32bit, src_hw_8086_cpu_less_than_32bit_asm );

        outline1("MOV BX, [%s]", _source);
        outline1("MOV AX, [%s]", address_displacement( _environment, _source, "+2" ) );
        outline1("MOV DX, 0x%4.4x", (unsigned short)(_destination&0xffff));
        outline1("MOV CX, 0x%4.4x", (unsigned short)((_destination>>16)&0xffff));
        if ( _signed ) {

            if ( _equal ) {
                outline0("CALL CPULTE32S");
            } else {
                outline0("CALL CPULT32S");
            }
        } else {
            if ( _equal ) {
                outline0("CALL CPULTE32U");
            } else {
                outline0("CALL CPULT32U");
            }
        }
        if ( _other ) {
            outline1("MOV [%s], AL", _other);
        } else {
            outline1("MOV [%s], AL", _destination);
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
void cpu_greater_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal, int _signed ) {

    cpu_less_than_32bit( _environment, _source, _destination, _other, !_equal, _signed );
    if ( _other ) {
        cpu_not_8bit( _environment, _other, _other );
    } else {
        cpu_not_8bit( _environment, _destination, _destination );
    }

}

void cpu_greater_than_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _signed ) {

    cpu_less_than_32bit_const( _environment, _source, _destination, _other, !_equal, _signed );
    cpu_not_8bit( _environment, _other, _other );

}

void cpu_greater_than_nbit( Environment * _environment, char *_source, char * _destination,  char *_other, int _equal, int _bits ) {

    inline( cpu_greater_than_nbit )

        cpu_less_than_nbit( _environment, _source, _destination, _other, !_equal, _bits );
        cpu_not_8bit( _environment, _other, _other );

    no_embedded( cpu_greater_than_nbit )

}

void cpu_greater_than_nbit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _bits ) {

    inline( cpu_greater_than_nbit )

        cpu_less_than_nbit_const( _environment, _source, _destination, _other, !_equal, _bits );
        cpu_not_8bit( _environment, _other, _other );

    no_embedded( cpu_greater_than_nbit )

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

        outline1("MOV AX, [%s]", _source );
        outline1("MOV BX, [%s]", _destination );
        outline0("ADD AX, BX" );
        if ( _other ) {
            outline1("MOV [%s], AX", _other );
        } else {
            outline1("MOV [%s], AX", _destination );
        }
        outline1("MOV AX, [%s]", address_displacement( _environment, _source, "+2" ) );
        outline1("MOV BX, [%s]", address_displacement( _environment, _destination, "+2" ) );
        outline0("ADD AX, BX" );
        if ( _other ) {
            outline1("MOV [%s], AX", address_displacement( _environment, _other, "+2" ) );
        } else {
            outline1("MOV [%s], AX", address_displacement( _environment, _destination, "+2" ) );
        }

    no_embedded( cpu_math_add_32bit )

}

void cpu_math_add_32bit_const( Environment * _environment, char *_source, int _destination,  char *_other ) {

    inline( cpu_math_add_32bit_const )

        outline1("MOV AX, [%s]", _source );
        outline1("MOV BX, 0x%4.4x", (unsigned short)(_destination&0xffff) );
        outline0("ADD AX, BX" );
        outline1("MOV [%s], AX", _other );
        outline1("MOV AX, [%s]", address_displacement( _environment, _source, "+2" ) );
        outline1("MOV BX, 0x%4.4x", (unsigned short)((_destination>>16)&0xffff) );
        outline0("ADC AX, BX" );
        outline1("MOV [%s], AX", address_displacement( _environment, _other, "+2" ) );

    no_embedded( cpu_math_add_32bit_const )

}

void cpu_math_add_nbit( Environment * _environment, char *_source, char *_destination,  char *_other, int _bits ) {

    inline( cpu_math_add_nbit )

        outline0("CLC");
        for( int i=0; i<(_bits>>3); ++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
            outline1("MOV AL, [%s]", address_displacement(_environment, _source, offset));
            outline1("ADC AL, [%s]", address_displacement(_environment, _destination, offset));
            if ( _other ) {
                outline1("MOV [%s], AL", address_displacement(_environment, _other, offset));
            } else {
                outline1("MOV [%s], AL", address_displacement(_environment, _destination, offset));
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

        outline1("MOV AX, [%s]", _source );
        outline1("MOV BX, [%s]", _destination );
        outline0("SUB AX, BX" );
        outline1("MOV [%s], AX", _other );
        outline1("MOV AX, [%s]", address_displacement( _environment, _source, "+2" ) );
        outline1("MOV BX, [%s]", address_displacement( _environment, _destination, "+2" ) );
        outline0("SBB AX, BX" );
        outline1("MOV [%s], AX", address_displacement( _environment, _other, "+2" ) );

    no_embedded( cpu_math_sub_32bit )

}

void cpu_math_sub_nbit( Environment * _environment, char *_source, char *_destination,  char *_other, int _bits ) {

    inline( cpu_math_sub_nbit )

        outline0("CLC");
        for( int i=0; i<(_bits)>>3; ++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
            outline1("MOV AL, [%s]", address_displacement(_environment, _source, offset));
            outline1("SBB AL, [%s]", address_displacement(_environment, _destination, offset));
            if ( _other ) {
                outline1("MOV [%s], AL", address_displacement(_environment, _other, offset));
            } else {
                outline1("MOV [%s], AL", address_displacement(_environment, _destination, offset));
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

        outline1("MOV AX, 0x%4.4x", (unsigned short)(_value&0xffff) );
        outline1("MOV BX, [%s]", _source );
        outline0("SUB AX, BX" );
        outline1("MOV [%s], AX", _source );
        outline1("MOV BX, [%s]", address_displacement( _environment, _source, "+2" ) );
        outline1("MOV AX, 0x%4.4x", (unsigned short)((_value>>16)&0xffff) );
        outline0("SBB AX, BX" );
        outline1("MOV [%s], AX", address_displacement( _environment, _source, "+2" ) );

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
            outline1("MOV AL, [%s]", _source );
            outline0("AND 0x1" );
            outline1("MOV [%s], AL", _remainder );
        }
        if ( _signed ) {
            outline1("MOV AL, [%s]", address_displacement(_environment, _source, "3") );
            outline0("AND AL, 0x80" );
            outline0("PUSH AX" );
            outline0("CMP AL, 0" );
            outline1("JZ %spos", label );
            cpu_complement2_32bit( _environment, _source, _source );
            outline1("JMP %spos2", label );
            outhead1("%spos:", label );
            outhead1("%spos2:", label );
            outline1("MOV AX, [%s]", _source );
            outline1("MOV BX, [%s]", address_displacement(_environment, _source, "2") );
            while( _steps ) {
                outline0("SAR BX, 1" );
                outline0("ROR AX, 1" );
                --_steps;
            }
            outline1("MOV [%s], AX", _source );
            outline1("MOV [%s], BX", address_displacement( _environment, _source, "2" ) );
            outline0("POP AX" );
            outline0("CMP AL, 0" );
            outline1("JZ %sdone", label );
            cpu_complement2_32bit( _environment, _source, _source );
            outhead1("%sdone:", label );
        } else {
            outline1("MOV AX, [%s]", _source );
            outline1("MOV BX, [%s]", address_displacement(_environment, _source, "2") );
            while( _steps ) {
                outline0("SAR BX, 1" );
                outline0("ROR AX, 1" );
                --_steps;
            }
            outline1("MOV [%s], AX", _source );
            outline1("MOV [%s], BX", address_displacement( _environment, _source, "2" ) );    
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
void cpu_math_mul2_const_32bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    inline( cpu_math_mul2_const_32bit )

        MAKE_LABEL

        if ( _signed ) {
            outline1("MOV AL, [%s]", address_displacement(_environment, _source, "3") );
            outline0("AND AL, 0x80" );
            outline0("PUSH AX" );
            outline0("CMP AL, 0" );
            outline1("JZ %spos", label );
            cpu_complement2_32bit( _environment, _source, _source );
            outline1("JMP %spos2", label );
            outhead1("%spos:", label );
            outhead1("%spos2:", label );
            outline1("MOV AX, [%s]", _source );
            outline1("MOV BX, [%s]", address_displacement(_environment, _source, "2") );
            while( _steps ) {
                outline0("SAL AX, 1" );
                outline0("ROL BX, 1" );
                --_steps;
            }
            outline1("MOV [%s], AX", _source );
            outline1("MOV [%s], BX", address_displacement( _environment, _source, "2" ) );
            outline0("POP AX" );
            outline0("CMP AL, 0" );
            outline1("JZ %sdone", label );
            cpu_complement2_32bit( _environment, _source, _source );
            outhead1("%sdone:", label );
        } else {
            outline1("MOV AX, [%s]", _source );
            outline1("MOV BX, [%s]", address_displacement(_environment, _source, "2") );
            while( _steps ) {
                outline0("SAL AX, 1" );
                outline0("ROL BX, 1" );
                --_steps;
            }
            outline1("MOV [%s], AX", _source );
            outline1("MOV [%s], BX", address_displacement( _environment, _source, "2" ) );    
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

        outline1("MOV AX, [%s]", _source );
        outline1("AND AX, 0x%4.4x", (unsigned short)( _mask & 0xffff ) );
        outline1("MOV [%s], AX", _source );
        outline1("MOV AX, [%s]", address_displacement(_environment, _source, "2") );
        outline1("AND AX, 0x%4.4x", (unsigned short)( (_mask>>16) & 0xffff ) );
        outline1("MOV [%s], AX", address_displacement(_environment, _source, "2") );

    no_embedded( cpu_math_and_const_32bit )

}

/**
 * @brief <i>Z80</i>: emit code to combine nibbles
 * 
 * @todo Not yet implemented
 */
void cpu_combine_nibbles( Environment * _environment, char * _low_nibble, char * _hi_nibble, char * _byte ) {

    inline( cpu_combine_nibbles )

        outline1("MOV BL, [%s]", _low_nibble );
        outline1("MOV AL, [%s]", _hi_nibble );
        outline0("SAL AL, 1");
        outline0("SAL AL, 1");
        outline0("SAL AL, 1");
        outline0("SAL AL, 1");
        outline0("OR AL, BL");
        outline1("MOV [%s], AL", _byte );

    no_embedded( cpu_combine_nibbles );

}

void cpu_jump( Environment * _environment, char * _label ) {

    outline1("JMP %s", _label );

}

void cpu_call_addr( Environment * _environment, int _address ) {

    outline1("CALL 0x%4.4x", _address );

}

void cpu_call( Environment * _environment, char * _label ) {

    outline1("CALL %s", _label );

}

void cpu_call_indirect( Environment * _environment, char * _value ) {

    outline1( "CALL [%s]", _value )

}

void cpu_jump_indirect( Environment * _environment, char * _value ) {

    outline1( "JMP [%s]", _value )

}

int cpu_register_decode( Environment * _environment, char * _register ) {

    CPU8086Register result = REGISTER_NONE;

    if ( !_environment->emptyProcedure ) {

        if ( strcmp( _register, "AL" ) == 0 ) {
            result = REGISTER_AL;
        } else if ( strcmp( _register, "AH" ) == 0 ) {
            result = REGISTER_AH;
        } else if ( strcmp( _register, "BL" ) == 0 ) {
            result = REGISTER_BL;
        } else if ( strcmp( _register, "BH" ) == 0 ) {
            result = REGISTER_BH;
        } else if ( strcmp( _register, "CL" ) == 0 ) {
            result = REGISTER_CL;
        } else if ( strcmp( _register, "CH" ) == 0 ) {
            result = REGISTER_CH;
        } else if ( strcmp( _register, "DL" ) == 0 ) {
            result = REGISTER_DL;
        } else if ( strcmp( _register, "DH" ) == 0 ) {
            result = REGISTER_DH;
        } else if ( strcmp( _register, "AX" ) == 0 ) {
            result = REGISTER_AX;
        } else if ( strcmp( _register, "BX" ) == 0 ) {
            result = REGISTER_BX;
        } else if ( strcmp( _register, "CX" ) == 0 ) {
            result = REGISTER_CX;
        } else if ( strcmp( _register, "DX" ) == 0 ) {
            result = REGISTER_DX;
        } else if ( strcmp( _register, "SP" ) == 0 ) {
            result = REGISTER_SP;
        } else if ( strcmp( _register, "BP" ) == 0 ) {
            result = REGISTER_BP;
        } else if ( strcmp( _register, "SI" ) == 0 ) {
            result = REGISTER_SI;
        } else if ( strcmp( _register, "DI" ) == 0 ) {
            result = REGISTER_DI;
        } else if ( strcmp( _register, "CARRY" ) == 0 ) {
            result = REGISTER_CARRY;
        } else if ( strcmp( _register, "ZERO" ) == 0 ) {
            result = REGISTER_ZERO;
        } else {

        }

    }

    return (int)result;

}

void cpu_set_asmio( Environment * _environment, int _asmio, int _value ) {

    if ( IS_REGISTER( _asmio ) ) {

        MAKE_LABEL

        CPU8086Register reg = (CPU8086Register) _asmio;

        switch ( reg ) {
            case REGISTER_NONE:
                CRITICAL_UNKNOWN_CPU_REGISTER( );
                break;
                break;
            case REGISTER_AL:
                outline1( "MOV AL, 0x%2.2x", (unsigned char)(_value & 0xff ) );
                break;
            case REGISTER_AH:
                outline1( "MOV AH, 0x%2.2x", (unsigned char)(_value & 0xff ) );
                break;
            case REGISTER_BL:
                outline1( "MOV BL, 0x%2.2x", (unsigned char)(_value & 0xff ) );
                break;
            case REGISTER_BH:
                outline1( "MOV BH, 0x%2.2x", (unsigned char)(_value & 0xff ) );
                break;
            case REGISTER_CL:
                outline1( "MOV CL, 0x%2.2x", (unsigned char)(_value & 0xff ) );
                break;
            case REGISTER_CH:
                outline1( "MOV CH, 0x%2.2x", (unsigned char)(_value & 0xff ) );
                break;
            case REGISTER_DL:
                outline1( "MOV DL, 0x%2.2x", (unsigned char)(_value & 0xff ) );
                break;
            case REGISTER_DH:
                outline1( "MOV DH, 0x%2.2x", (unsigned char)(_value & 0xff ) );
                break;
            case REGISTER_AX:
                outline1( "MOV AX, 0x%4.4x", (unsigned short)(_value & 0xffff ) );
                break;
            case REGISTER_BX:
                outline1( "MOV BX, 0x%4.4x", (unsigned short)(_value & 0xffff ) );
                break;
            case REGISTER_CX:
                outline1( "MOV CX, 0x%4.4x", (unsigned short)(_value & 0xffff ) );
                break;
            case REGISTER_DX:
                outline1( "MOV DX, 0x%4.4x", (unsigned short)(_value & 0xffff ) );
                break;
            case REGISTER_SP:
                outline1( "MOV SP, 0x%4.4x", (unsigned short)(_value & 0xffff ) );
                break;
            case REGISTER_BP:
                outline1( "MOV BP, 0x%4.4x", (unsigned short)(_value & 0xffff ) );
                break;
            case REGISTER_SI:
                outline1( "MOV SI, 0x%4.4x", (unsigned short)(_value & 0xffff ) );
                break;
            case REGISTER_DI:
                outline1( "MOV DI, 0x%4.4x", (unsigned short)(_value & 0xffff ) );
                break;
        }

    } else {

        CPU8086Stack stk = (CPU8086Stack) _asmio;

        switch ( stk ) {
            case STACK_NONE:
                break;
            case STACK_BYTE:
                outline1( "MOV AL, 0x%2.2x", (unsigned char)(_value & 0xff ) );
                outline0( "PUSH AL" );
                break;
            case STACK_WORD:
                outline1( "MOV AX, 0x%4.4x", (unsigned short)(_value & 0xffff) );
                outline0( "PUSH AX" );
                break;
            case STACK_DWORD:
                outline1( "MOV AX, 0x%4.4x", (unsigned short)(_value & 0xffff) );
                outline0( "PUSH AX" );
                outline1( "MOV AX, 0x%4.4x", (unsigned short)((_value>>16) & 0xffff) );
                outline0( "PUSH AX" );
                break;
        }

    }

}

void cpu_set_asmio_indirect( Environment * _environment, int _asmio, char * _value ) {

    if ( IS_REGISTER( _asmio ) ) {

        MAKE_LABEL

        CPU8086Register reg = (CPU8086Register) _asmio;

        switch ( reg ) {
            case REGISTER_NONE:
                CRITICAL_UNKNOWN_CPU_REGISTER( );
                break;
                break;
            case REGISTER_AL:
                outline1( "MOV AL, [%s]", _value );
                break;
            case REGISTER_AH:
                outline1( "MOV AH, [%s]", _value );
                break;
            case REGISTER_BL:
                outline1( "MOV BL, [%s]", _value );
                break;
            case REGISTER_BH:
                outline1( "MOV BH, [%s]", _value );
                break;
            case REGISTER_CL:
                outline1( "MOV CL, [%s]", _value );
                break;
            case REGISTER_CH:
                outline1( "MOV CH, [%s]", _value );
                break;
            case REGISTER_DL:
                outline1( "MOV DL, [%s]", _value );
                break;
            case REGISTER_DH:
                outline1( "MOV DH, [%s]", _value );
                break;
            case REGISTER_AX:
                outline1( "MOV AX, [%s]", _value );
                break;
            case REGISTER_BX:
                outline1( "MOV BX, [%s]", _value );
                break;
            case REGISTER_CX:
                outline1( "MOV CX, [%s]", _value );
                break;
            case REGISTER_DX:
                outline1( "MOV DX, [%s]", _value );
                break;
            case REGISTER_SP:
                outline1( "MOV SP, [%s]", _value );
                break;
            case REGISTER_BP:
                outline1( "MOV BP, [%s]", _value );
                break;
            case REGISTER_SI:
                outline1( "MOV SI, [%s]", _value );
                break;
            case REGISTER_DI:
                outline1( "MOV DI, [%s]", _value );
                break;
        }

    } else {

        CPU8086Stack stk = (CPU8086Stack) _asmio;

        switch ( stk ) {
            case STACK_NONE:
                break;
            case STACK_BYTE:
                outline1( "MOV AL, [%s]", _value );
                outline0( "PUSH AL" );
                break;
            case STACK_WORD:
                outline1( "MOV AX, [%s]", _value );
                outline0( "PUSH AX" );
                break;
            case STACK_DWORD:
                outline1( "MOV AX, [%s]", _value );
                outline0( "PUSH AX" );
                outline1( "MOV AX, [%s]", address_displacement( _environment, _value, "+2" ) );
                outline0( "PUSH AX" );
                break;
        }

    }
    
}

void cpu_get_asmio_indirect( Environment * _environment, int _asmio, char * _value ) {

    if ( IS_REGISTER( _asmio ) ) {

        MAKE_LABEL

        CPU8086Register reg = (CPU8086Register) _asmio;

        switch ( reg ) {
            case REGISTER_NONE:
                CRITICAL_UNKNOWN_CPU_REGISTER( );
                break;
                break;
            case REGISTER_AL:
                outline1( "MOV [%s], AL", _value );
                break;
            case REGISTER_AH:
                outline1( "MOV [%s], AH", _value );
                break;
            case REGISTER_BL:
                outline1( "MOV [%s], BL", _value );
                break;
            case REGISTER_BH:
                outline1( "MOV [%s], BH", _value );
                break;
            case REGISTER_CL:
                outline1( "MOV [%s], CL", _value );
                break;
            case REGISTER_CH:
                outline1( "MOV [%s], CH", _value );
                break;
            case REGISTER_DL:
                outline1( "MOV [%s], DL", _value );
                break;
            case REGISTER_DH:
                outline1( "MOV [%s], DH", _value );
                break;
            case REGISTER_AX:
                outline1( "MOV [%s], AX", _value );
                break;
            case REGISTER_BX:
                outline1( "MOV [%s], BX", _value );
                break;
            case REGISTER_CX:
                outline1( "MOV [%s], CX", _value );
                break;
            case REGISTER_DX:
                outline1( "MOV [%s], DX", _value );
                break;
            case REGISTER_SP:
                outline1( "MOV [%s], SP", _value );
                break;
            case REGISTER_BP:
                outline1( "MOV [%s], BP", _value );
                break;
            case REGISTER_SI:
                outline1( "MOV [%s], SI", _value );
                break;
            case REGISTER_DI:
                outline1( "MOV [%s], DI", _value );
                break;
        }

    } else {

        CPU8086Stack stk = (CPU8086Stack) _asmio;

        switch ( stk ) {
            case STACK_NONE:
                break;
            case STACK_BYTE:
                outline0( "POP AL" );
                outline1( "MOV [%s], AL", _value );
                break;
            case STACK_WORD:
                outline0( "POP AX" );
                outline1( "MOV [%s], AX", _value );
                break;
            case STACK_DWORD:
                outline0( "POP AX" );
                outline1( "MOV [%s], AX", address_displacement( _environment, _value, "+2" ) );
                outline0( "POP AX" );
                outline1( "MOV [%s], AX", _value );
                break;
        }

    }

}

void cpu_return( Environment * _environment ) {

    outline0("RET" );

}

void cpu_pop( Environment * _environment ) {

    outline0("POP AX" );

}

void cpu_halt( Environment * _environment ) {

    MAKE_LABEL

    outhead1("%s:", label );
    outline1("JMP %s", label );

}

void cpu_end( Environment * _environment ) {

    outline0("HLT");

}

void cpu_random( Environment * _environment, char * _entropy ) {

    MAKE_LABEL

    no_inline( cpu_random )

    embedded( cpu_random, src_hw_8086_cpu_random_asm );
       
    done()


}

void cpu_random_8bit( Environment * _environment, char * _entropy, char * _result ) {

    cpu_random( _environment, _entropy );

    if ( _result ) {
        outline0("CALL CPURANDOM16" );
        outline1("MOV [%s], AL", _result );
    }

}

void cpu_random_16bit( Environment * _environment, char * _entropy, char * _result ) {

    cpu_random( _environment, _entropy );

    if ( _result ) {
        outline0("CALL CPURANDOM16" );
        outline1("MOV [%s], AX", _result );
    }

}

void cpu_random_32bit( Environment * _environment, char * _entropy, char * _result ) {

    cpu_random( _environment, _entropy );

    if ( _result ) {
        outline0("CALL CPURANDOM32" );
        outline1("MOV [%s], AX", _result );
        outline1("MOV [%s], BX", address_displacement( _environment, _result, "2" ) );
    }

}

void cpu_limit_16bit( Environment * _environment, char * _variable, int _value ) {

    MAKE_LABEL

    outline1( "MOV AL, [%s]", _variable );
    outline1( "CMP AL, 0x%2.2x", (unsigned char)(_value&0xff) );
    outline1( "JB %s", label );
    outline1( "SUB AL, 0x%2.2x", (unsigned char)(_value&0xff) );
    outline1( "MOV [%s], AL", _variable );
    outhead1( "%s:", label );

}

void cpu_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline1("MOV AL, [%s]", _timing );
    outhead1("%s:", label );
    outline0("DEC AL");
    outline1("JNZ %s", label);

}

/**
 * @brief <i>Z80</i>: emit code to send one byte throught a I/O port
 * 
 * @param _environment Current calling environment
 * @param _port Port to connect
 * @param _value Value to send
 */
void cpu_port_out( Environment * _environment, char * _port, char * _value ) {

    outline1("MOV AL, [%s]", _value );
    outline1("MOV DL, [%s]", _port );
    outline0("MOV dh, 0" );
    outline0("OUT DX, AL" );

}

void cpu_logical_and_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("MOV AL, [%s]", _left );
    outline0("CMP AL, 0" );
    outline1("JZ %s", label );
    outline1("MOV AL, [%s]", _right );
    outline0("CMP AL, 0" );
    outline1("JZ %s", label );
    outline0("MOV AL, 0xff" );
    outline1("MOV [%s], AL", _result );
    outline1("JMP %s_2", label );
    outhead1("%s:", label );
    outline0("MOV AL, 0" );
    outline1("MOV [%s], AL", _result );
    outhead1("%s_2:", label );

}

void cpu_and_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    outline1("MOV AL, [%s]", _left );
    outline1("MOV AH, [%s]", _right );
    outline0("AND AL, AH" );
    outline1("MOV [%s], AL", _result );

}

void cpu_and_8bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    outline1("MOV AL, [%s]", _left );
    outline1("MOV AH, 0x%2.2x", _right );
    outline0("AND AL, AH" );
    outline1("MOV [%s], AL", _result );

}

void cpu_and_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    outline1("MOV AX, [%s]", _left );
    outline1("MOV BX, [%s]", _right );
    outline0("AND AX, BX" );
    outline1("MOV [%s], AX", _result );

}

void cpu_and_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    cpu_and_16bit( _environment, _left, _right, _result );
    cpu_and_16bit( _environment, 
            address_displacement( _environment, _left, "+2" ), 
            address_displacement( _environment, _right, "+2" ),
            address_displacement( _environment, _result, "+2" )
        );

}

void cpu_logical_or_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("MOV AL, [%s]", _left );
    outline0("CMP AL, 0" );
    outline1("JZ %s", label );
    outline0("MOV AL, 0xff" );
    outline1("MOV [%s], AL", _result );
    outline1("JMP %s_2", label );
    outline1("MOV AL, [%s]", _right );
    outline0("CMP AL, 0" );
    outline1("JZ %s", label );
    outline0("MOV AL, 0xff" );
    outline1("MOV [%s], AL", _result );
    outline1("JMP %s_2", label );
    outhead1("%s:", label );
    outline0("MOV AL, 0" );
    outline1("MOV [%s], AL", _result );
    outhead1("%s_2:", label );

}

void cpu_or_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    outline1("MOV AL, [%s]", _left );
    outline1("MOV AH, [%s]", _right );
    outline0("OR AL, AH" );
    outline1("MOV [%s], AL", _result );

}

void cpu_or_8bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    outline1("MOV AL, [%s]", _left );
    outline1("MOV AH, 0x%2.2x", _right );
    outline0("OR AL, AH" );
    outline1("MOV [%s], AL", _result );

}

void cpu_or_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    outline1("MOV AX, [%s]", _left );
    outline1("MOV BX, [%s]", _right );
    outline0("OR AX, BX" );
    outline1("MOV [%s], AX", _result );

}

void cpu_or_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    cpu_or_16bit( _environment, _left, _right, _result );
    cpu_or_16bit( _environment, 
            address_displacement( _environment, _left, "+2" ), 
            address_displacement( _environment, _right, "+2" ),
            address_displacement( _environment, _result, "+2" )
        );

}

void cpu_xor_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    outline1("MOV AL, [%s]", _left );
    outline1("MOV AH, [%s]", _right );
    outline0("XOR AL, AH" );
    outline1("MOV [%s], AL", _result );

}

void cpu_xor_8bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    outline1("MOV AL, [%s]", _left );
    outline1("MOV AH, 0x%2.2x", _right );
    outline0("XOR AL, AH" );
    outline1("MOV [%s], AL", _result );

}

void cpu_xor_16bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    outline1("MOV AX, [%s]", _left );
    outline1("MOV BX, [%s]", _right );
    outline0("XOR AX, BX" );
    outline1("MOV [%s], AX", _result );

}

void cpu_xor_16bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    outline1("MOV AX, [%s]", _left );
    outline1("MOV BX, 0x%4.4x", _right );
    outline0("XOR AX, BX" );
    outline1("MOV [%s], AX", _result );

}


void cpu_xor_32bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    cpu_xor_16bit( _environment, _left, _right, _result );
    cpu_xor_16bit( _environment, 
            address_displacement( _environment, _left, "+2" ), 
            address_displacement( _environment, _right, "+2" ),
            address_displacement( _environment, _result, "+2" )
        );

}

void cpu_xor_32bit_const( Environment * _environment, char * _left, int _right, char * _result ) {

    cpu_xor_16bit_const( _environment, _left, (unsigned short)(_right&0xffff), _result );
    cpu_xor_16bit_const( _environment, 
            address_displacement( _environment, _left, "+2" ), 
            (unsigned short)((_right>>16)&0xffff),
            address_displacement( _environment, _result, "+2" )
        );

}

void cpu_swap_8bit( Environment * _environment, char * _left, char * _right ) {

    inline( cpu_swap_8bit )

        outline1("MOV AL, [%s]", _right );
        outline1("MOV AH, [%s]", _left );
        outline0("XCHG AL, AH" );
        outline1("MOV [%s], AL", _right );
        outline1("MOV [%s], AH", _left );

    no_embedded( cpu_swap_8bit ) 

}    

void cpu_swap_16bit( Environment * _environment, char * _left, char * _right ) {

    inline( cpu_swap_8bit )

        outline1("MOV AX, [%s]", _right );
        outline1("MOV BX, [%s]", _left );
        outline0("XCHG AX, BX" );
        outline1("MOV [%s], AX", _right );
        outline1("MOV [%s], BX", _left );

    no_embedded( cpu_swap_8bit ) 

}

void cpu_swap_32bit( Environment * _environment, char * _left, char * _right ) {

    cpu_swap_16bit( _environment, _left, _right );
    cpu_swap_16bit( _environment, address_displacement( _environment, _left, "+2" ), address_displacement( _environment, _right, "+2" ) );
    
}

void cpu_logical_not_8bit( Environment * _environment, char * _value, char * _result ) {

    outline1("MOV AL, [%s]", _value );
    outline0("XOR AL, 0xff" );
    outline1("MOV [%s], AL", _result );

}

void cpu_not_8bit( Environment * _environment, char * _value, char * _result ) {

    outline1("MOV AL, [%s]", _value );
    outline0("XOR AL, 0xff" );
    outline1("MOV [%s], AL", _result );

}

void cpu_not_16bit( Environment * _environment, char * _value, char * _result ) {

    outline1("MOV AX, [%s]", _value );
    outline0("XOR AX, 0xffff" );
    outline1("MOV [%s], AX", _result );

}

void cpu_not_32bit( Environment * _environment, char * _value, char * _result ) {

    cpu_not_16bit( _environment, _value, _result );
    cpu_not_16bit( _environment, 
        address_displacement( _environment, _value, "+2" ), 
        address_displacement( _environment, _result, "+2" ) 
    );

}

void cpu_di( Environment * _environment ) {

    outline0("CLI");

}

void cpu_ei( Environment * _environment ) {

    outline0("STI");

}

void cpu_inc( Environment * _environment, char * _variable ) {

    outline1("MOV AL, [%s]", _variable  );
    outline0("INC AL" );
    outline1("MOV [%s], AL", _variable  );

}

void cpu_dec( Environment * _environment, char * _variable ) {

    outline1("MOV AL, [%s]", _variable  );
    outline0("DEC AL" );
    outline1("MOV [%s], AL", _variable  );

}

void cpu_inc_16bit( Environment * _environment, char * _variable ) {

    outline1("MOV AX, [%s]", _variable  );
    outline0("INC AX" );
    outline1("MOV [%s], AX", _variable  );

}

void cpu_inc_32bit( Environment * _environment, char * _variable ) {

    MAKE_LABEL

    outline1("MOV AX, [%s]", _variable  );
    outline0("INC AX" );
    outline1("MOV [%s], AX", _variable  );
    outline1("JNC %s", label  );
    outline1("MOV AX, [%s]", address_displacement( _environment, _variable, "+2" ) );
    outline0("INC AX" );
    outline1("MOV [%s], AX", address_displacement( _environment, _variable, "+2" )  );
    outhead1("%s:", label  );

}

void cpu_inc_nbit( Environment * _environment, char * _variable, int _bits ) {

    MAKE_LABEL

    inline( cpu_inc_nbit )

        for( int i=0; i<(_bits>>3);++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf(offset, "%d", i );
            outline1("MOV AL, [%s]", address_displacement(_environment, _variable, offset ) );
            outline0("INC AL");
            outline1("MOV [%s], AL", address_displacement(_environment, _variable, offset ) );
            outline1("JNZ %s", label );
        }
        outhead1("%s:", label );

    no_embedded( cpu_inc_nbit )

}

void cpu_dec_16bit( Environment * _environment, char * _variable ) {

    outline1("MOV AX, [%s]", _variable  );
    outline0("DEC AX" );
    outline1("MOV [%s], AX", _variable  );

}

void cpu_dec_32bit( Environment * _environment, char * _variable ) {

    MAKE_LABEL

    outline1("MOV AX, [%s]", _variable  );
    outline0("DEC AX" );
    outline1("MOV [%s], AX", _variable  );
    outline0("CMP AX, 0xffff" );
    outline1("JNZ %s", label  );
    outline1("MOV AX, [%s]", address_displacement( _environment, _variable, "+2" ) );
    outline0("DEC AX" );
    outline1("MOV [%s], AX", address_displacement( _environment, _variable, "+2" )  );
    outhead1("%s:", label  );

}

void cpu_dec_nbit( Environment * _environment, char * _variable, int _bits ) {

    MAKE_LABEL

    inline( cpu_dec_32bit )

        for( int i=0; i<(_bits>>3); ++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
            outline1("MOV AL, [%s]", address_displacement(_environment, _variable, offset) );
            outline0("DEC AL" );
            outline1("MOV [%s], AL", address_displacement(_environment, _variable, offset) );
            outline0("CMP AL, 0xFF" );
            outline1("JNZ %s", label );
        }
        outhead1("%s:", label );

    no_embedded( cpu_dec_32bit )

}

void cpu_less_than_nbit( Environment * _environment, char *_source, char * _destination,  char *_other, int _equal, int _bits ) {

    MAKE_LABEL

    int i;

    inline( cpu_less_than_nbit )

        if ( _equal ) {

            cpu_compare_nbit( _environment, _source, _destination, _other, 1, _bits );

            if ( _other ) {
                outline1("MOV AL, [%s]", _other);
            } else {
                outline1("MOV AL, [%s]", _destination);
            }

            outline0("CMP AL, 0" );
            outline1("JZ %sless", label );
            outline1("JMP %sdone", label );
            outhead1("%sless:", label );

        }

        for( i=(_bits>>3)-1; i>-1; --i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf(offset, "%d", i );
            outline1("MOV AL, [%s]", address_displacement(_environment, _destination, offset ) );
            outline0("MOV BL, AL");
            outline1("MOV AL, [%s]", address_displacement(_environment, _source, offset ) );
            outline0("CMP AL, BL");
            outline2("JZ %snext%dx", label, i );
            outline1("JC %sbga", label );
            outline1("JMP %sagb", label );
            outhead2("%snext%dx:", label, i );
        }

        outhead1("%sbga:", label );
        outline0("MOV AL, 0xff" );
        outline1("MOV [%s], AL", _other );
        outline1("JMP %sdone", label );

        outhead1("%sagb:", label );
        outline0("MOV AL, 0x00" );
        outline1("MOV [%s], AL", _other );
        outline1("JMP %sdone", label );

        outhead1("%sdone:", label );

    no_embedded( cpu_less_than_nbit )

}

void cpu_less_than_nbit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _equal, int _bits ) {

    MAKE_LABEL

    int i;

    inline( cpu_less_than_nbit_const )

        if ( _equal ) {

            cpu_compare_nbit_const( _environment, _source, _destination, _other, 1, _bits );

            outline1("MOV AL, [%s]", _other);
            outline0("CMP AL, 0" );
            outline1("JZ %sless", label );
            outline1("JMP %sdone", label );
            outhead1("%sless:", label );

        }

        for( i=(_bits>>3)-2; i>-1; --i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf(offset, "%d", i );
            outline1("MOV BL, $%2.2x", (unsigned char)((_destination>>(i*8))&0xff) );
            outline1("MOV AL, [%s]", address_displacement(_environment, _source, offset ) );
            outline0("CMP AL, BL");
            outline2("JZ %snext%dx", label, i );
            outline1("JC %sbga", label );
            outline1("JMP %sagb", label );
            outhead2("%snext%dx:", label, i );
        }

        outhead1("%sbga:", label );
        outline0("MOV AL, 0xff" );
        outline1("MOV [%s], AL", _other );
        outline1("JMP %sdone", label );

        outhead1("%sagb:", label );
        outline0("MOV AL, 0x00" );
        outline1("MOV [%s], AL", _other );
        outline1("JMP %sdone", label );

        outhead1("%sdone:", label );

    no_embedded( cpu_less_than_nbit_const )

}

void cpu_mem_move( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    deploy( duff, src_hw_8086_duff_asm );

    outline1("MOV SI, [%s]", _source);
    outline1("MOV DI, [%s]", _destination);
    outline1("MOV CL, [%s]", _size);
    outline0("MOV CH, 0");
    outline0("CALL DUFFDEVICE");

}

void cpu_mem_move_16bit( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    deploy( duff, src_hw_8086_duff_asm );

    outline1("MOV SI, [%s]", _source);
    outline1("MOV DI, [%s]", _destination);
    outline1("MOV CX, [%s]", _size);
    outline0("CALL DUFFDEVICE");

}

void cpu_mem_move_direct( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    deploy( duff, src_hw_8086_duff_asm );

    outline1("MOV SI, %s", _source);
    outline1("MOV DI, %s", _destination);
    outline1("MOV CL, [%s]", _size);
    outline0("MOV CH, 0");
    outline0("CALL DUFFDEVICE");

}

void cpu_mem_move_direct2( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    deploy( duff, src_hw_8086_duff_asm );

    outline1("MOV SI, %s", _source);
    outline1("MOV DI, %s", _destination);
    outline1("MOV CX, [%s]", _size);
    outline0("CALL DUFFDEVICE");

}

void cpu_mem_move_direct2_size( Environment * _environment, char *_source, char *_destination,  int _size ) {

    deploy( duff, src_hw_8086_duff_asm );

    outline1("MOV SI, [%s]", _source);
    outline1("MOV DI, %s", _destination);
    outline1("MOV CX, 0x%4.4x", _size );
    outline0("CALL DUFFDEVICE");

}

void cpu_mem_move_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size > 0 ) {

        deploy( duff, src_hw_8086_duff_asm );

        outline1("MOV SI, [%s]", _source);
        outline1("MOV DI, [%s]", _destination);
        outline1("MOV CX, 0x%4.4x", _size );
        outline0("CALL DUFFDEVICE");

    }

}

void cpu_mem_move_direct_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size > 0 ) {

        deploy( duff, src_hw_8086_duff_asm );

        outline1("MOV SI, %s", _source);
        outline1("MOV DI, %s", _destination);
        outline1("MOV CX, 0x%4.4x", _size );
        outline0("CALL DUFFDEVICE");

    }

}

void cpu_mem_move_direct_indirect_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size ) {

        deploy( duff, src_hw_8086_duff_asm );

        outline1("MOV SI, %s", _source);
        outline1("MOV DI, [%s]", _destination);
        outline1("MOV CX, 0x%4.4x", _size );
        outline0("CALL DUFFDEVICE");

    }

}

void cpu_mem_move_indirect_direct_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size ) {

        deploy( duff, src_hw_8086_duff_asm );

        outline1("MOV SI, [%s]", _source);
        outline1("MOV DI, %s", _destination);
        outline1("MOV CX, 0x%4.4x", _size );
        outline0("CALL DUFFDEVICE");

    }

}

void cpu_compare_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    MAKE_LABEL

    outline1("MOV SI, [%s]", _source);
    outline1("MOV DI, [%s]", _destination);
    outline1("MOV CX, [%s]", _size);
    outline0("PUSH ES");
    outline0("PUSH DX");
    outline0("MOV DX, DS");
    outline0("MOV ES, DX");
    outline0("POP DX");
    outline0("CLD");
    outline0("REPE CMPSB");
    outline0("POP ES");

    outline1("JNE %sdiff", label);
    outhead1("%sequal:", label );
    outline1("MOV AL, 0x%2.2x", _equal ? 255 : 0 );
    outline1("MOV [%s], AL", _result );
    outline1("JMP %sfinal", label );
    outhead1("%sdiff:", label );
    outline1("MOV AL, 0x%2.2x", _equal ? 0 : 255 );
    outline1("MOV [%s], AL", _result );
    outhead1("%sfinal:", label );

}

void cpu_compare_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    MAKE_LABEL
    
    outline1("MOV SI, [%s]", _source);
    outline1("MOV DI, [%s]", _destination);
    outline1("MOV CX, 0x%4.4x", (unsigned short)(_size&0xffff));
    outline0("PUSH ES");
    outline0("PUSH DX");
    outline0("MOV DX, DS");
    outline0("MOV ES, DX");
    outline0("POP DX");
    outline0("CLD");
    outline0("REPE CMPSB");
    outline0("POP ES");

    outline1("JNE %sdiff", label);
    outhead1("%sequal:", label );
    outline1("MOV AL, 0x%2.2x", _equal ? 255 : 0 );
    outline1("MOV [%s], AL", _result );
    outline1("JMP %sfinal", label );
    outhead1("%sdiff:", label );
    outline1("MOV AL, 0x%2.2x", _equal ? 0 : 255 );
    outline1("MOV [%s], AL", _result );
    outhead1("%sfinal:", label );

    // comparazione:
    // cmpsb                       ; Confronta [SI] con [DI]
    // ja  string_maggiore         ; Salta se il primo byte è maggiore (no carry)
    // jb  string_minore           ; Salta se il primo byte è minore (carry)

    // loop comparazione           ; Ripeti il ciclo se i byte sono uguali

}

void cpu_less_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    MAKE_LABEL

    char greaterLabel[MAX_TEMPORARY_STORAGE];
    sprintf( greaterLabel, "%sgt", label );
    char lesserLabel[MAX_TEMPORARY_STORAGE];
    sprintf( lesserLabel, "%slt", label );

    outline1("MOV SI, [%s]", _source);
    outline1("MOV DI, [%s]", _destination);
    outline1("MOV CX, %s]", _size);
    outline0("PUSH ES");
    outline0("PUSH DX");
    outline0("MOV DX, DS");
    outline0("MOV ES, DX");
    outline0("POP DX");
    outline0("CLD");

    outhead1("%s:", label);
    outline0("CMPSB");
    if ( !_equal ) {
        outline1("JAE %s", greaterLabel);
    } else {
        outline1("JA %s", greaterLabel);
    }
    outline1("LOOP %s", label );
    outline0("POP ES");

    outline0("MOV AL, 0xff");
    outline1("JMP %s", label);

    outhead1("%s:", greaterLabel );
    outline0("MOV AL, 0");
    outhead1("%s:", label );

}

void cpu_less_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    MAKE_LABEL

    char greaterLabel[MAX_TEMPORARY_STORAGE];
    sprintf( greaterLabel, "%sgt", label );
    char lesserLabel[MAX_TEMPORARY_STORAGE];
    sprintf( lesserLabel, "%slt", label );

    outline1("MOV SI, [%s]", _source);
    outline1("MOV DI, [%s]", _destination);
    outline1("MOV CX, 0x%4.4x", (unsigned short)(_size&0xffff));
    outline0("PUSH ES");
    outline0("PUSH DX");
    outline0("MOV DX, DS");
    outline0("MOV ES, DX");
    outline0("POP DX");
    outline0("CLD");

    outhead1("%s:", label);
    outline0("CMPSB");
    if ( !_equal ) {
        outline1("JAE %s", greaterLabel);
    } else {
        outline1("JA %s", greaterLabel);
    }
    outline1("LOOP %s", label );

    outline0("MOV AL, 0xff");
    outline1("JMP %s", label);
    outline0("POP ES");
    
    outhead1("%s:", greaterLabel );
    outline0("MOV AL, 0");
    outhead1("%s:", label );

}

void cpu_greater_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {

    cpu_less_than_memory( _environment, _source, _destination, _size, _result, !_equal );
    cpu_not_8bit( _environment, _result, _result );

}

void cpu_greater_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {

    cpu_less_than_memory_size( _environment, _source, _destination, _size, _result, !_equal );
    cpu_not_8bit( _environment, _result, _result );

}

void cpu_math_add_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    outline1("MOV AX, [%s]", _source );
    outline1("MOV BL, [%s]", _destination );
    outline0("MOV BH, 0" );
    outline0("ADD AX, BX" );
    if ( _other ) {
        outline1("MOV [%s], AX", _other );
    } else {
        outline1("MOV [%s], AX", _destination );
    }

}

void cpu_math_sub_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    outline1("MOV AX, [%s]", _source );
    outline1("MOV BL, [%s]", _destination );
    outline0("MOV BH, 0" );
    outline0("SUB AX, BX" );
    if ( _other ) {
        outline1("MOV [%s], AX", _other );
    } else {
        outline1("MOV [%s], AX", _destination );
    }

}

void cpu_uppercase( Environment * _environment, char *_source, char *_size, char *_result ) {

    MAKE_LABEL

    outline1("MOV CL, [%s]", _size);
    outline1("MOV SI, [%s]", _source );
    if ( _result ) {
        outline1("MOV DI, [%s]", _result );
    } else {
        outline1("MOV DI, [%s]", _source );
    }
    outhead1("%supper:", label );
    outline0("MOV AL, [SI]" );

    outline0("CMP AL, 97");
    outline1("JC %snext", label);

    outline0("CMP AL, 122");
    outline1("JNC %snext", label);

    outline0("SUB AL, 32");
    outline0("MOV [DI], AL" );
    outline1("JMP %sdone", label );

    outhead1("%snext:", label );
    outline0("MOV [DI], AL" );

    outhead1("%sdone:", label );
    outline0("INC SI" );
    outline0("INC DI" );
    outline0("DEC CX" );
    outline0("CMP CX, 0" );
    outline1("JNZ %supper", label);

}

void cpu_lowercase( Environment * _environment, char *_source, char *_size, char *_result ) {

    MAKE_LABEL

    outline1("MOV CL, [%s]", _size);
    outline1("MOV SI, [%s]", _source );
    if ( _result ) {
        outline1("MOV DI, [%s]", _result );
    } else {
        outline1("MOV DI, [%s]", _source );
    }
    outhead1("%slower:", label );
    outline0("MOV AL, [SI]" );

    outline0("CMP AL, 65");
    outline1("JC %snext", label);

    outline0("CMP AL, 91");
    outline1("JNC %snext", label);

    outline0("SUB AL, 32");
    outline0("MOV [DI], AL" );
    outline1("JMP %sdone", label );

    outhead1("%snext:", label );
    outline0("MOV [DI], AL" );

    outhead1("%sdone:", label );
    outline0("INC SI" );
    outline0("INC DI" );
    outline0("DEC CX" );
    outline0("CMP CX, 0" );
    outline1("JNZ %slower", label);

}

void cpu_convert_string_into_8bit( Environment * _environment, char * _string, char * _len, char * _value ) {

    Variable * temp = variable_temporary( _environment, VT_WORD, "(temp)" );
    cpu_convert_string_into_16bit( _environment, _string, _len, temp->realName );
    cpu_move_8bit( _environment, temp->realName, _value );
  
}

void cpu_convert_string_into_16bit( Environment * _environment, char * _string, char * _len, char * _value ) {

    no_inline( cpu_convert_string_into_16bit )

    embedded( cpu_convert_string_into_16bit, src_hw_8086_cpu_convert_string_into_16bit_asm );

        outline1( "MOV SI, %s", _string );
        outline1( "MOV CX, [%s]", _len );
        outline0( "CALL CONVERTSTRING16BIT" );
        outline1( "MOV [%s], AX", _value );

    done( )

}

void cpu_fill_indirect( Environment * _environment, char * _address, char * _size, char * _pattern, int _size_size ) {

    MAKE_LABEL

    // Use the current bitmap address as starting address for filling routine.
    outline1("MOV DI, [%s]", _address);
    outline1("MOV SI, [%s]", _pattern);

    // Fill the bitmap with the given pattern.
    if ( _size_size >= 16 ) {
        outline1("MOV CX, [%s]", _size);
        outhead1("%sx:", label);
        outline0("MOV AL, [SI]");
        outline0("MOV [DI], AL");
        outline0("INC DI");
        outline0("DEC CX");
        outline0("CMP CX, 0");
        outline1("JNZ %sx", label);
    } else {
        outline1("MOV CL, [%s]", _size);
        outline0("MOV CH, 0" );
        outhead1("%sx:", label);
        outline0("MOV AL, [SI]");
        outline0("MOV [DI], AL");
        outline0("INC DI");
        outline0("CMP CL, 0");
        outline1("JNZ %sx", label);
    }

}

void cpu_flip_8bit( Environment * _environment, char * _source, char * _destination ) {

    no_inline( cpu_flip )

    embedded( cpu_flip, src_hw_8086_cpu_flip_asm );

        outline1("MOV SI, [%s]", _source);
        outline0("MOV AL, [SI]");
        outline0("CALL CPUFLIP8");
        if ( _destination ) {
            outline1("MOV DI, [%s]", _destination);
            outline0("MOV [DI], BL");
        } else {
            outline0("MOV [SI], BL");
        }

    done( )

}

void cpu_flip( Environment * _environment, char * _source, char * _size, char * _destination ) {

    no_inline( cpu_flip )

    embedded( cpu_flip, src_hw_8086_cpu_flip_asm );

        outline1("MOV SI, [%s]", _source);
        outline1("MOV DI, [%s]", _destination);
        outline1("MOV CL, [%s]", _size);
        outline0("CALL CPUFLIP");

    done(  )

}

void cpu_move_8bit_indirect( Environment * _environment, char *_source, char * _value ) {

    outline1("MOV DI, [%s]", _value);
    outline1("MOV AL, [%s]", _source);
    outline0("MOV [DI], AL");

}

void cpu_move_8bit_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

    outline1("MOV SI, %s", _value);
    outline1("MOV AL, [%s]", _offset );
    outline0("MOV AH, 0" );
    outline0("ADD SI, AX" );
    outline1("MOV AL, [%s]", _source);
    outline0("MOV [SI], AL");

}

void cpu_move_8bit_indirect_with_offset( Environment * _environment, char *_source, char * _value, int _offset ) {

    outline1("MOV SI, [%s]", _value);
    outline1("MOV AX, 0x%2.2x", ( _offset & 0xff ) );
    outline0("ADD SI, AX" );
    outline1("MOV AL, [%s]", _source);
    outline0("MOV [SI], AL");

}

void cpu_move_8bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    outline1("MOV DI, [%s]", _value);
    outline0("MOV AL, [DI]");
    outline1("MOV [%s], AL", _source);

}

void cpu_move_8bit_indirect2_8bit( Environment * _environment, char * _value, char * _offset, char *_source ) {

    outline1("MOV SI, %s", _value);
    outline1("MOV AL, [%s]", _offset);
    outline0("MOV AH, 0");
    outline0("ADD SI, AX");
    outline0("MOV AL, [SI]");
    outline1("MOV [%s], AL", _source );

}

void cpu_move_8bit_indirect2_16bit( Environment * _environment, char * _value, char * _offset, char *_source ) {

    outline1("MOV SI, %s", _value);
    outline1("MOV AX, [%s]", _offset);
    outline0("ADD SI, AX");
    outline0("MOV AL, [SI]");
    outline1("MOV [%s], AL", _source );

}

void cpu_move_16bit_indirect( Environment * _environment, char *_source, char * _value ) {

    outline1("MOV DI, [%s]", _value);
    outline1("MOV AX, [%s]", _source);
    outline0("MOV [DI], AX");

}

void cpu_move_16bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    outline1("MOV DI, [%s]", _value);
    outline0("MOV AX, [DI]");
    outline1("MOV [%s], AX", _source);

}

void cpu_move_16bit_indirect2_8bit( Environment * _environment, char * _value, char * _offset, char *_source ) {

    outline1("MOV SI, %s", _value);
    outline1("MOV AL, [%s]", _offset);
    outline0("MOV AH, 0");
    outline0("ADD SI, AX");
    outline0("ADD SI, AX");
    outline0("MOV AX, [SI]");
    outline1("MOV [%s], AX", _source );

}

void cpu_move_32bit_indirect( Environment * _environment, char *_source, char * _value ) {

    outline1("MOV DI, [%s]", _value);
    outline1("MOV AX, [%s]", _source);
    outline0("MOV [DI], AX");
    outline0("INC DI");
    outline0("INC DI");
    outline1("MOV AX, [%s]", address_displacement(_environment, _source, "2"));
    outline0("MOV [DI], AX");

}

void cpu_move_nbit_indirect( Environment * _environment, int _n, char *_source, char * _value ) {

    outline1("MOV DI, [%s]", _value);

    char step[MAX_TEMPORARY_STORAGE];
    char step2[MAX_TEMPORARY_STORAGE];

    int stepIndex = 0;
    while( _n ) {
        sprintf( step, "%d", stepIndex );
        sprintf( step2, "%d", stepIndex+2 );
        if ( _n >= 32 ) {
            outline1("MOV AX, [%s]", address_displacement(_environment, _source, step));
            outline0("MOV [DI], AX");
            outline0("INC DI");
            outline0("INC DI");
            outline1("MOV AX, [%s]", address_displacement(_environment, _source, step2));
            outline0("MOV [DI], AX");
            outline0("INC DI");
            outline0("INC DI");
            stepIndex += 4;
            _n -= 32;
        } else {
            switch( _n ) {
                case 32: case 31: case 30: case 29:
                case 28: case 27: case 26: case 25:
                    outline1("MOV AX, [%s]", address_displacement(_environment, _source, step));
                    outline0("MOV [DI], AX");
                    outline0("INC DI");
                    outline0("INC DI");
                    outline1("MOV AX, [%s]", address_displacement(_environment, _source, step2));
                    outline0("MOV [DI], AX");
                    outline0("INC DI");
                    outline0("INC DI");
                    break;
                case 24: case 23: case 22: case 21:
                case 20: case 19: case 18: case 17:
                    outline1("MOV AX, [%s]", address_displacement(_environment, _source, step));
                    outline0("MOV [DI], AX");
                    outline0("INC DI");
                    outline0("INC DI");
                    outline1("MOV AL, [%s]", address_displacement(_environment, _source, step2));
                    outline0("MOV [DI], AL");
                    outline0("INC DI");
                    break;
                case 16: case 15: case 14: case 13:
                case 12: case 11: case 10: case 9:
                    outline1("MOV AX, [%s]", address_displacement(_environment, _source, step));
                    outline0("MOV [DI], AX");
                    outline0("INC DI");
                    outline0("INC DI");
                    break;
                case 8: case 7: case 6: case 5:
                case 4: case 3: case 2: case 1:
                    outline1("MOV AL, [%s]", address_displacement(_environment, _source, step2));
                    outline0("MOV [DI], AL");
                    outline0("INC DI");
                    break;
            }
            _n = 0;
        }
    }

}

void cpu_move_32bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    outline1("MOV DI, [%s]", _value);
    outline0("MOV AX, [DI]");
    outline1("MOV [%s], AX", _source);
    outline0("INC DI");
    outline0("INC DI");
    outline0("MOV AX, [DI]");
    outline1("MOV [%s], AX", address_displacement( _environment, _source, "2" ) );

}

void cpu_move_nbit_indirect2( Environment * _environment, int _n, char * _value, char *_source ) {

    outline1("MOV DI, [%s]", _value);

    char step[MAX_TEMPORARY_STORAGE];
    char step2[MAX_TEMPORARY_STORAGE];

    int stepIndex = 0;
    while( _n ) {
        sprintf( step, "%d", stepIndex );
        sprintf( step2, "%d", stepIndex+2 );
        if ( _n >= 32 ) {
            outline0("MOV AX, [DI]");
            outline1("MOV [%s], AX", address_displacement( _environment, _source, step ) );
            outline0("INC DI");
            outline0("INC DI");
            outline0("MOV AX, [DI]");
            outline1("MOV [%s], AX", address_displacement( _environment, _source, step2 ) );
            outline0("INC DI");
            outline0("INC DI");
            stepIndex += 4;
            _n -= 32;
        } else {
            switch( _n ) {
                case 32: case 31: case 30: case 29:
                case 28: case 27: case 26: case 25:
                    outline0("MOV AX, [DI]");
                    outline1("MOV [%s], AX", address_displacement( _environment, _source, step ) );
                    outline0("INC DI");
                    outline0("INC DI");
                    outline0("MOV AX, [DI]");
                    outline1("MOV [%s], AX", address_displacement( _environment, _source, step2 ) );
                    outline0("INC DI");
                    outline0("INC DI");
                    break;
                case 24: case 23: case 22: case 21:
                case 20: case 19: case 18: case 17:
                    outline0("MOV AX, [DI]");
                    outline1("MOV [%s], AX", address_displacement( _environment, _source, step ) );
                    outline0("INC DI");
                    outline0("INC DI");
                    outline0("MOV AL, [DI]");
                    outline1("MOV [%s], AL", address_displacement( _environment, _source, step2 ) );
                    outline0("INC DI");
                    break;
                case 16: case 15: case 14: case 13:
                case 12: case 11: case 10: case 9:
                    outline0("MOV AX, [DI]");
                    outline1("MOV [%s], AX", address_displacement( _environment, _source, step ) );
                    outline0("INC DI");
                    outline0("INC DI");
                    break;
                case 8: case 7: case 6: case 5:
                case 4: case 3: case 2: case 1:
                    outline0("MOV AL, [DI]");
                    outline1("MOV [%s], AL", address_displacement( _environment, _source, step ) );
                    outline0("INC DI");
                    break;
            }
            _n = 0;
        }
    }

}

void cpu_math_div_32bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    outline1( "MOV DX, [%s]", address_displacement( _environment, _source, "+2" ) );
    outline1( "MOV AX, [%s]", _source );
    outline1( "MOV BX, [%s]", _destination );

    if ( _signed ) {
        outline0( "IDIV BX" );
    } else {
        outline0( "DIV BX" );
    }

    outline1("MOV [%s], DX", _other_remainder);
    outline1("MOV [%s], AX", _other);
 
}

void cpu_math_div_32bit_to_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    outline1( "MOV DX, [%s]", address_displacement( _environment, _source, "+2" ) );
    outline1( "MOV AX, [%s]", _source );
    outline1( "MOV BX, 0x%4.4x", _destination );

    if ( _signed ) {
        outline0( "IDIV BX" );
    } else {
        outline0( "DIV BX" );
    }

    outline1("MOV [%s], DX", _other_remainder);
    outline1("MOV [%s], AX", _other);
 
}

void cpu_math_div_16bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    outline0( "MOV DX, 0" );
    outline1( "MOV AX, [%s]", _source );
    outline1( "MOV BX, [%s]", _destination );

    if ( _signed ) {
        outline0( "IDIV BX" );
    } else {
        outline0( "DIV BX" );
    }

    outline1("MOV [%s], DX", _other_remainder);
    outline1("MOV [%s], AX", _other);
    
}

void cpu_math_div_16bit_to_16bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    outline0( "MOV DX, 0" );
    outline1( "MOV AX, [%s]", _source );
    outline1( "MOV BX, 0x%4.4x", (unsigned short)(_destination&0xffff) );

    if ( _signed ) {
        outline0( "IDIV BX" );
    } else {
        outline0( "DIV BX" );
    }

    outline1("MOV [%s], DX", _other_remainder);
    outline1("MOV [%s], AX", _other);
    
}

void cpu_math_div_8bit_to_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    outline1( "MOV AX, [%s]", _source );
    outline1( "MOV BL, [%s]", _destination );

    if ( _signed ) {
        outline0( "IDIV BL" );
    } else {
        outline0( "DIV BL" );
    }

    outline1("MOV [%s], DX", _other_remainder);
    outline1("MOV [%s], AL", _other);

}

void cpu_math_div_8bit_to_8bit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    outline1( "MOV AL, [%s]", _source );
    outline1( "MOV BL, 0x%2.2x", (unsigned char)(_destination&0xff) );

    if ( _signed ) {
        outline0( "IDIV BL" );
    } else {
        outline0( "DIV BL" );
    }

    outline1("MOV [%s], DX", _other_remainder);
    outline1("MOV [%s], AL", _other);

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

            outhead2("%s: times %d db 0", quotient, _bits>>3 );
            outhead2("%s: times %d db 0", divisor, _bits>>3 );
            outhead2("%s: times %d db 0", dividend, _bits>>3 );
            outhead1("%s: db 0", k );
            outhead1("%s: db 0", result1 );
            outhead1("%s: db 0", result2 );

            // public static long div(long dividend, long divisor) {
            //     long quotient = 0;

            outhead1("CPUMATHDIVNBITTONBIT%d:", _bits>>3);
            outhead0("MOV AL, 0x00");
            for( i=0; i<(_bits>>3); ++i ) {
                char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
                outline1("MOV [%s], AL", address_displacement( _environment, quotient, offset ) );
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
            outline1("MOV AL, [%s]", address_displacement( _environment, _source, offset ) );
            outline1("MOV [%s], AL", address_displacement( _environment, dividend, offset ) );
            outline1("MOV AL, [%s]", address_displacement( _environment, _destination, offset ) );
            outline1("MOV [%s], AL", address_displacement( _environment, divisor, offset ) );
        }
        outline1("CALL CPUMATHDIVNBITTONBIT%d", _bits>>3);

        for( i=0; i<(_bits>>3); ++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
            if ( _other ) {
                outline1("MOV AL, [%s]", address_displacement( _environment, quotient, offset ) );
                outline1("MOV [%s], AL", address_displacement( _environment, _other, offset ) );
            } else {
                outline1("MOV AL, [%s]", address_displacement( _environment, quotient, offset ) );
                outline1("MOV [%s], AL", address_displacement( _environment, _destination, offset ) );            
            }
        }

        // }
    no_embedded( cpu_math_div_nbit_to_nbit )

}

void cpu_math_div_nbit_to_nbit_const( Environment * _environment, char *_source, int _destination,  char *_other, char * _other_remainder, int _bits ) {

    MAKE_LABEL

    int i;
    
    inline( cpu_math_div_nbit_to_nbit )

        char afterLabel[MAX_TEMPORARY_STORAGE]; sprintf( afterLabel, "%safter", label );
        char data[MAX_TEMPORARY_STORAGE]; sprintf( data, "CPUMATHDIVNBITTONBITCONST%d_DATA", _bits >> 3 );

        if ( ! _environment->cpuOptimization.cpu_math_div_nbit_to_nbit_const[_bits>>3] ) {

            cpu_jump( _environment, afterLabel );

            outhead2("%s: times %d db 0", data, _bits>>3 );

            cpu_label( _environment, afterLabel );
            
        }

        for( i=0; i<(_bits>>3); ++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
            outline1("MOL AL, 0x%2.2x", (unsigned char)( (_destination >> (i*8)) & 0xff ) );
            outline1("MOV [%s], AL", address_displacement( _environment, data, offset ) );
        }
        cpu_math_div_nbit_to_nbit( _environment, _source, data, _other, _other_remainder, _bits );

        // }
    no_embedded( cpu_math_div_nbit_to_nbit )

}

void cpu_bit_check( Environment * _environment, char *_value, int _position, char * _result, int _bitwidth ) {

    no_inline( cpu_bit_check_extended )

    embedded( cpu_bit_check_extended, src_hw_8086_cpu_bit_check_extended_asm );

        outline1("MOV DI, %s", _value);
        outline1("MOV AL, 0x%2.2x", _position );
        outline0("CALL CPUBITCHECKEXTENDED" );

        if ( _result ) {
            outline1("MOV [%s], AL", _result);
        }

    done( )

}

void cpu_bit_check_extended( Environment * _environment, char *_value, char * _position, char * _result, int _bitwidth ) {

    MAKE_LABEL

    no_inline( cpu_bit_check_extended )

    embedded( cpu_bit_check_extended, src_hw_8086_cpu_bit_check_extended_asm );

        outline1("MOV DI, %s", _value);
        outline1("MOV AL, [%s]", _position );
        outline0("CALL CPUBITCHECKEXTENDED" );

        if ( _result ) {
            outline1("MOV [%s], AL", _result);
        }

    done( )
    
}

void cpu_bit_inplace_8bit( Environment * _environment, char * _value, int _position, int * _bit ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    no_inline( cpu_bit_inplace )

    embedded( cpu_bit_inplace, src_hw_8086_cpu_bit_inplace_asm );

        if ( _bit ) {
            if ( * _bit ) {
                outline0("MOV AL, 0xff" );
            } else {
                outline0("MOV AL, 0x0" );
            }
            outline0("SAL AL, 1" );
        }
        outline1("MOV DI, %s", _value );
        outline1("MOV AL, 0x%2.2x", _position);
        outline0("CALL CPUBITINPLACE");

    done( )

}

void cpu_bit_inplace_8bit_extended_indirect( Environment * _environment, char * _address, char * _position, char * _bit ) {

    _environment->bitmaskNeeded = 1;

    MAKE_LABEL

    no_inline( cpu_bit_inplace )

    embedded( cpu_bit_inplace, src_hw_8086_cpu_bit_inplace_asm );

        if ( _bit ) {
            outline1("MOV AL, [%s]", _bit );
            outline0("CMP AL, 0" );
            outline1("JZ %s", label );
            outline0("MOV AL, 1" );;
            outline0("SAL AL, 1" );
            outhead1("%s:", label );
        }
        outline1("MOV DI, [%s]", _address );
        outline1("MOV AL, [%s]", _position);
        outline0("CALL CPUBITINPLACE");

    done( )

}

void cpu_number_to_string_vars( Environment * _environment ) {

    // variable_import( _environment, "N2DINV", VT_BUFFER, _environment->numberConfig.maxBytes );
    // variable_import( _environment, "N2DBUF", VT_BUFFER, _environment->numberConfig.maxDigits );
    // variable_import( _environment, "N2DEND", VT_BUFFER, 1 );

}

void cpu_number_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits, int _signed ) {

    MAKE_LABEL
        
    deploy_with_vars( numberToString, src_hw_8086_number_to_string_asm, cpu_number_to_string_vars );

    outline0("MOV BL, 0");
    switch( _bits ) {
        case 8:
            outline1("MOV AL, [%s]", _number);
            outline0("MOV [N2DINV], AL");
            if ( _signed ) {
                outline0("AND AL, 0x80");
                outline0("CMP AL, 0");
                outline1("JZ %sp81", label);
                cpu_complement2_8bit( _environment, "N2DINV", NULL );
                outline0("MOV BL, 0xff");
                outhead1("%sp81:", label);
            }
            break;
        case 16:
            outline1("MOV AX, [%s]", _number);
            outline0("MOV [N2DINV], AX");
            if ( _signed ) {
                outline0("AND AH, 0x80");
                outline0("CMP AH, 0");
                outline1("JZ %sp81", label);
                cpu_complement2_16bit( _environment, "N2DINV", NULL );
                outline0("MOV BL, 0xff");
                outhead1("%sp81:", label);
            }
            break;
        case 32:
            outline1("MOV AX, [%s]", _number);
            outline0("MOV [N2DINV], AX");
            outline1("MOV AX, [%s]", address_displacement(_environment, _number, "2"));
            outline0("MOV [N2DINV+2], HL");
            if ( _signed ) {
                outline0("AND AH, 0x80");
                outline0("CMP AH, 0");
                outline1("JZ %sp81", label);
                cpu_complement2_32bit( _environment, "N2DINV", NULL  );
                outline0("MOV BL, 0xff");
                outhead1("%sp81:", label);
            }
            break;
        default:
            cpu_mem_move_direct_size( _environment, _number, "N2DINV", _bits >> 3 );
            if ( _signed ) {
                outline1("MOV AL, [N2DINV+%d]", (_bits >> 3)-1 );
                outline0("AND AL, 0x80");
                outline0("CMP AL, 0");
                outline1("JZ %sp81", label);
                cpu_complement2_nbit( _environment, "N2DINV", NULL, _bits  );
                outline0("MOV BL, 0xff");
                outhead1("%sp81:", label);
            }
            break;
        case 0:
            CRITICAL_DEBUG_UNSUPPORTED( _number, "unknown");
    }

    outline1("MOV SI, [%s]", _string);
    outline0("CALL NUMBERTOSTRINGSIGNED");
    outline1("MOV [%s], AL", _string_size);

}

void cpu_bits_to_string_vars( Environment * _environment ) {

    // variable_import( _environment, "BINSTRBUF", VT_BUFFER, 32 );
    variable_import( _environment, "BINTOSTRDIGIT0", VT_BYTE, '0' );
    variable_import( _environment, "BINTOSTRDIGIT1", VT_BYTE, '1' );
}

void cpu_bits_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits, char * _zero, char * _one ) {

    deploy_with_vars( bitsToString,src_hw_8086_bits_to_string_asm, cpu_bits_to_string_vars );

    if ( _zero ) {
        outline1("MOV AL, [%s]", _zero);
    } else {
        outline0("MOV AL, '0'" );
    }
    outline0("MOV [BINTOSTRDIGIT0], AL" );

    if ( _one ) {
        outline1("MOV AL, [%s]", _one);
    } else {
        outline0("MOV AL, '1'" );
    }
    outline0("MOV [BINTOSTRDIGIT1], AL" );

    switch( _bits ) {
        case 32:
            outline1("MOV AX, [%s]", address_displacement(_environment, _number, "2") );
            outline1("MOV BX, [%s]", _number );
            break;
        case 16:
            outline0("MOV AX, 0" );
            outline1("MOV BX, [%s]", _number );
            break;
        case 8:        
            outline0("MOV AX, 0" );
            outline0("MOV BH, 0" );
            outline1("MOV BL, [%s]", _number );
            break;
    }

    outline1("MOV DI, [%s]", _string);
    outline0("CALL BINSTR");
    
    outline1("MOV AL, 0x%2.2x", ( _bits & 0xff ) );
    outline1("MOV [%s], AL", _string_size );

}

void cpu_hex_to_string_calc_string( Environment * _environment, char * _size, int _separator, char * _string_size ) {

    MAKE_LABEL

    outline1("MOV AL, [%s]", _size );
    outline0("MOV AH, 0" );
    outline1("MOV BL, 0X%2.2x", 2 + (_separator?1:0));
    outline0("MOV BH, 0" );
    outline0("IMUL BX" );
    outline1("MOV [%s], AL", _string_size );

}

void cpu_hex_to_string_calc_string_size( Environment * _environment, int _size, int _separator, char * _string_size ) {

    MAKE_LABEL

    outline1("MOV AL, $%2.2x", (unsigned char)(_size&0xff) );
    outline0("MOV AH, 0" );
    outline1("MOV BL, 0X%2.2x", 2 + (_separator?1:0));
    outline0("MOV BH, 0" );
    outline0("IMUL BX" );
    outline1("MOV [%s], AL", _string_size );

}

void cpu_hex_to_string( Environment * _environment, char * _number, char * _string, int _size ) {

    MAKE_LABEL

    inline( cpu_hex_to_string )

    embedded( cpu_hex_to_string, src_hw_8086_cpu_hex_to_string_asm );

        outline1("MOV CL, 0x%2.2x", (unsigned char)(_size));
        outline1("MOV SI, [%s]", _number );
        outline1("MOV DI, [%s]", _string );
        outline0("CALL H2STRING" );

    done()

}

void cpu_encrypt( Environment * _environment, char * _data, char * _size, char * _key, char * _output ) {

    deploy( encrypt, src_hw_8086_encrypt_asm );

    outline1("MOV SI, (%s)", _data );
    outline1("MOV DX, (%s)", _key );
    outline1("MOV DI, (%s)", _output );
    outline1("MOV CL, (%s)", _size );
    outline0("CALL ENCRYPT" );

}

void cpu_decrypt( Environment * _environment, char * _data, char * _size, char * _key, char * _output, char * _result ) {

    deploy( decrypt, src_hw_8086_decrypt_asm );

    outline1("MOV SI, (%s)", _data );
    outline1("MOV DX, (%s)", _key );
    outline1("MOV DI, (%s)", _output );
    outline1("MOV CL, (%s)", _size );
    outline0("CALL DECRYPT" );
    cpu_ztoa( _environment );
    outline1("MOV [%s], AL", _result );

}

void cpu_dsdefine( Environment * _environment, char * _string, char * _index ) {

    deploy( duff, src_hw_8086_duff_asm );
    deploy( dstring,src_hw_8086_dstring_asm );

    outline1( "MOV SI, %s", _string );
    outline0( "CALL DSDEFINE" );
    outline1( "MOV [%s], BL", _index );
    
}

void cpu_dsalloc( Environment * _environment, char * _size, char * _index ) {

    deploy( duff, src_hw_8086_duff_asm );
    deploy( dstring,src_hw_8086_dstring_asm );

    outline1( "MOV CL, [%s]", _size );
    outline0( "CALL DSALLOC" );
    outline1( "MOV [%s], BL", _index );

}

void cpu_dsalloc_size( Environment * _environment, int _size, char * _index ) {

    deploy( duff, src_hw_8086_duff_asm );
    deploy( dstring,src_hw_8086_dstring_asm );

    outline1( "MOV CL, 0x%2.2x", ( _size & 0xff ) );
    outline0( "CALL DSALLOC" );
    outline1( "MOV [%s], BL", _index );

}

void cpu_dsfree( Environment * _environment, char * _index ) {

    deploy( duff, src_hw_8086_duff_asm );
    deploy( dstring,src_hw_8086_dstring_asm );

    outline1( "MOV BL, [%s]", _index );
    outline0( "CALL DSFREE" );

}

void cpu_dswrite( Environment * _environment, char * _index ) {

    deploy( duff, src_hw_8086_duff_asm );
    deploy( dstring,src_hw_8086_dstring_asm );

    outline1( "MOV BL, [%s]", _index );
    outline0( "CALL DSWRITE" );

}

void cpu_dsresize( Environment * _environment, char * _index, char * _resize ) {

    deploy( duff, src_hw_8086_duff_asm );
    deploy( dstring,src_hw_8086_dstring_asm );

    outline1( "MOV BL, [%s]", _index );
    outline1( "MOV CL, [%s]", _resize );
    outline0( "CALL DSRESIZE" );

}

void cpu_dsresize_size( Environment * _environment, char * _index, int _resize ) {

    deploy( duff, src_hw_8086_duff_asm );
    deploy( dstring,src_hw_8086_dstring_asm );

    outline1( "MOV BL, [%s]", _index );
    outline1( "MOV CL, 0x%2.2x", ( _resize & 0xff ) );
    outline0( "CALL DSRESIZE" );

}

void cpu_dsgc( Environment * _environment ) {

    deploy( duff, src_hw_8086_duff_asm );
    deploy( dstring,src_hw_8086_dstring_asm );

    outline0( "CALL DSGC" );

}

void cpu_dsinit( Environment * _environment ) {

    deploy( duff, src_hw_8086_duff_asm );
    deploy( dstring,src_hw_8086_dstring_asm );

    outline0( "CALL DSINIT" );

}

void cpu_dsdescriptor( Environment * _environment, char * _index, char * _address, char * _size ) {

    deploy( duff, src_hw_8086_duff_asm );
    deploy( dstring,src_hw_8086_dstring_asm );

    if ( _address || _size ) {
        outline1( "MOV BL, [%s]", _index );
        outline0( "CALL DSDESCRIPTOR" );
        if ( _size ) {
            outline0( "MOV AL, [DI]" );
            outline1( "MOV [%s], AL", _size );
        }
        if ( _address ) {
            outline0( "MOV DX, [DI+1]" );
            outline1( "MOV [%s], DX", _address );
        }
    }

}

void cpu_dsassign( Environment * _environment, char * _original, char * _copy ) {

    deploy_preferred( duff, src_hw_8086_duff_asm );
    deploy( dstring,src_hw_8086_dstring_asm );

    outline1( "MOV AL, [%s]", _original );
    outline1( "MOV BL, [%s]", _copy );
    outline0( "CALL DSASSIGN" );
    outline1( "MOV [%s], BL", _copy );

}

void cpu_move_8bit_indirect_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

    outline1("MOV DI, [%s]", _value);
    outline1("MOV CL, [%s]", _offset );
    outline0("MOV CH, 0" );
    outline0("ADD DI, CX" );
    outline1("MOV AL, [%s]", _source);
    outline0("MOV (DI), AL");

}

void cpu_complement2_8bit( Environment * _environment, char * _source, char * _destination ) {
    outline1( "MOV AL, [%s]", _source );
    outline0( "XOR AL, 0xff" );
    if ( _destination ) {
        outline1( "MOV [%s], AL", _destination );        
    } else {
        outline1( "MOV [%s], AL", _source );        
    }
    if ( _destination ) {
        cpu_inc( _environment, _destination );
    } else {
        cpu_inc( _environment, _source );
    }
}

void cpu_complement2_16bit( Environment * _environment, char * _source, char * _destination ) {
    outline1( "MOV AX, [%s]", _source );
    outline0( "XOR AX, 0xffff" );
    if ( _destination ) {
        outline1( "MOV [%s], AX", _destination );        
    } else {
        outline1( "MOV [%s], AX", _source );        
    }
    if ( _destination ) {
        cpu_inc_16bit( _environment, _destination );
    } else {
        cpu_inc_16bit( _environment, _source );
    }
}

void cpu_complement2_32bit( Environment * _environment, char * _source, char * _destination ) {
    outline1( "MOV AX, [%s]", _source );
    outline0( "XOR AX, 0xffff" );
    if ( _destination ) {
        outline1( "MOV [%s], AX", _destination );        
    } else {
        outline1( "MOV [%s], AX", _source );        
    }
    outline1( "MOV AX, [%s]", address_displacement( _environment, _source, "+2" ) );
    outline0( "XOR AX, 0xffff" );
    if ( _destination ) {
        outline1( "MOV [%s], AX", address_displacement( _environment, _destination, "+2" ) );        
    } else {
        outline1( "MOV [%s], AX", address_displacement( _environment, _source, "+2" ) );        
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
        outline1( "MOV AL, [%s]", address_displacement(_environment, _source, offset) );
        outline0( "XOR AL, 0xFF" );
        if ( _destination ) {
            outline1( "MOV [%s], AL", address_displacement(_environment, _destination, "1") );
        } else {
            outline1( "MOV [%s], AL", address_displacement(_environment, _source, "1") );
        }
    }
    if ( _destination ) {
        cpu_inc_nbit( _environment, _destination, _bits );
    } else {
        cpu_inc_nbit( _environment, _source, _bits );
    }

}

void cpu_sqroot( Environment * _environment, char * _number, char * _result ) {

    deploy( sqr, src_hw_8086_sqr_asm );

    outline1("MOV AX, [%s]", _number );
    outline0("MOV DX, 0" );

    outline0("CALL SQROOT" );

    outline1("MOV [%s], AX", _result );

}

void cpu_dstring_vars( Environment * _environment ) {

    int count = _environment->dstring.count == 0 ? DSTRING_DEFAULT_COUNT : _environment->dstring.count;
    int space = _environment->dstring.space == 0 ? DSTRING_DEFAULT_SPACE : _environment->dstring.space;

    outhead1("stringscount EQU                %d", count );
    outhead1("stringsspace EQU                %d", space );
    outhead0("MAXSTRINGS:                   db stringscount" );
    outhead0("DESCRIPTORS:                  times stringscount*4 db 0" );
    outhead0("WORKING:                      times stringsspace db 0" );
    outhead0("TEMPORARY:                    times stringsspace db 0" );
    outhead0("FREE_STRING:                  dw (stringsspace-1)" );

}

void cpu_protothread_vars( Environment * _environment ) {

    int count = _environment->protothreadConfig.count;

    outhead1("PROTOTHREADLC:      times %d db 0", count );
    outhead1("PROTOTHREADST:      times %d db 0", count );
    outhead0("PROTOTHREADCT:      db 0" );
    outhead0("PROTOTHREADLOOP:");

    for( int i=0; i<count; ++i ) {
        outline1("MOV AL, #%d-1", i+1 ); /* prevents optimizer changing code length */
        outline0("MOV [PROTOTHREADCT], AL" );
        outline0("CALL PROTOTHREADVOID" );
    }
    outhead1("PROTOTHREADCOUNT:      db %d", count );

}


void cpu_protothread_loop( Environment * _environment ) {

    deploy_with_vars( protothread, src_hw_8086_protothread_asm, cpu_protothread_vars );

    outline0("CALL PROTOTHREADLOOP" );

}

void cpu_protothread_register_at( Environment * _environment, char * _index, char * _label ) {

    deploy_with_vars( protothread, src_hw_8086_protothread_asm, cpu_protothread_vars );

    outline1("MOV SI, %s", _label );
    outline1("MOV BL, [%s]", _index );

    outline0("CALL PROTOTHREADREGAT" );

}

void cpu_protothread_register( Environment * _environment, char * _label, char * _index ) {

    deploy_with_vars( protothread, src_hw_8086_protothread_asm, cpu_protothread_vars );

    outline1("MOV SI, %s", _label );

    outline0("CALL PROTOTHREADREG" );

    outline1("MOV [%s], BL", _index );

}

void cpu_protothread_unregister( Environment * _environment, char * _index ) {

    deploy_with_vars( protothread, src_hw_8086_protothread_asm, cpu_protothread_vars );

    outline1("MOV BL, [%s]", _index );

    outline0("CALL PROTOTHREADUNREG" );

}

void cpu_protothread_save( Environment * _environment, char * _index, int _step ) {

    deploy_with_vars( protothread, src_hw_8086_protothread_asm, cpu_protothread_vars );

    outline1("MOV BL, [%s]", _index );
    outline1("MOV AL, 0x%2.2x", ( _step & 0xff ) );

    outline0("CALL PROTOTHREADSAVE" );

}

void cpu_protothread_restore( Environment * _environment, char * _index, char * _step ) {

    deploy_with_vars( protothread, src_hw_8086_protothread_asm, cpu_protothread_vars );

    outline1("MOV BL, [%s]", _index );

    outline0("CALL PROTOTHREADRESTORE" );

    outline1("MOV [%s], AL", _step );
    
}

void cpu_protothread_set_state( Environment * _environment, char * _index, int _state ) {

    deploy_with_vars( protothread, src_hw_8086_protothread_asm, cpu_protothread_vars );

    outline1("MOV BL, [%s]", _index );
    outline1("MOV AL, 0x%2.2x", ( _state & 0xff ) );

    outline0("CALL PROTOTHREADSETSTATE" );

}

void cpu_protothread_get_state( Environment * _environment, char * _index, char * _state ) {

    deploy_with_vars( protothread, src_hw_8086_protothread_asm, cpu_protothread_vars );

    outline1("MOV BL, [%s]", _index );
    outline0("CALL PROTOTHREADGETSTATE" );
    outline1("MOV [%s], AL", _state );

}

void cpu_protothread_get_address( Environment * _environment, char * _index, char * _address ) {

    deploy_with_vars( protothread, src_hw_8086_protothread_asm, cpu_protothread_vars );

    outline1("MOV BL, [%s]", _index );
    outline0("CALL PROTOTHREADGETADDRESS" );
    outline1("MOV [%s], DI", _address );

}

void cpu_protothread_current( Environment * _environment, char * _current ) {

    deploy_with_vars( protothread, src_hw_8086_protothread_asm, cpu_protothread_vars );

    outline0("MOV AL, [PROTOTHREADCT]" );
    outline1("MOV [%s], AL", _current );

}

void cpu_set_callback( Environment * _environment, char * _callback, char * _label ) {

    outline1("MOV AX, %s", _label );
    outline1("MOV DI, %s", _callback );
    outline0("MOV [DI], AX" );

}

void cpu_msc1_uncompress_direct_direct( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_8086_msc1_asm );

        outline1("MOV SI, %s", _input);
        outline1("MOV DI, %s", _output);
        outline0("CALL MSC1UNCOMPRESS");

    done()

}

void cpu_msc1_uncompress_direct_indirect( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_8086_msc1_asm );

        outline1("MOV SI, %s", _input);
        outline1("MOV DI, [%s]", _output);
        outline0("CALL MSC1UNCOMPRESS");

    done()

}

void cpu_msc1_uncompress_indirect_direct( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_8086_msc1_asm );

        outline1("MOV SI, [%s]", _input);
        outline1("MOV DI, %s", _output);
        outline0("CALL MSC1UNCOMPRESS");

    done()

}

void cpu_msc1_uncompress_indirect_indirect( Environment * _environment, char * _input, char * _output ) {

    MAKE_LABEL

    inline( cpu_msc1_uncompress )

    embedded( cpu_msc1_uncompress, src_hw_8086_msc1_asm );

        outline1("MOV SI, [%s]", _input);
        outline1("MOV DI, [%s]", _output);
        outline0("CALL MSC1UNCOMPRESS");

    done()

}

void cpu_out( Environment * _environment, char * _port, char * _value ) {

    outline1("MOV AL, [%s]", _value );
    outline1("MOV DX, [%s]", _port );
    outline0("OUT DX, AL" );

}

void cpu_in( Environment * _environment, char * _port, char * _value ) {

    outline1("MOV DX, [%s]", _port );
    outline0("IN AL, DX" );
    outline1("MOV [%s], AL", _value );
        
}

void cpu_out_direct( Environment * _environment, char * _port, char * _value ) {

    outline1("MOV AL, [%s]", _value );
    outline1("MOV DX, %s", _port );
    outline0("OUT DX, AL" );

}

void cpu_in_direct( Environment * _environment, char * _port, char * _value ) {

    outline1("MOV DX, %s", _port );
    outline0("IN AL, DX" );
    outline1("MOV [%s], AL", _value );
        
}

void cpu_string_sub( Environment * _environment, char * _source, char * _source_size, char * _pattern, char * _pattern_size, char * _destination, char * _destination_size ) {
    
    MAKE_LABEL

    inline( cpu_string_sub )

    embedded( cpu_string_sub, src_hw_8086_cpu_string_sub_asm );

        outline1("MOV SI, [%s]", _source);
        outline1("MOV CL, [%s]", _source_size);
        outline1("MOV DX, [%s]", _pattern);
        outline1("MOV CH, [%s]", _pattern_size);
        outline1("MOV DI, [%s]", _destination);
        outline0("CALL CPUSTRINGSUB");
        outline0("MOV AL, CL");
        outline1("MOV [%s], AL", _destination_size);

    done()
}

static char CPU8086_BLIT_REGISTER[][2] = {
    "DL",
    "DH",
    "CL",
    "CH"
};

#define CPU8086_BLIT_REGISTER_COUNT ( sizeof( CPU8086_BLIT_REGISTER ) / 2 )

void cpu_blit_initialize( Environment * _environment ) {

    _environment->blit.freeRegisters = 0;
    _environment->blit.usedMemory = 0;

    // outline0("; cpu_blit_initialize");

    outline0("PUSH SI");
    outline0("PUSH DI");

}

void cpu_blit_finalize( Environment * _environment ) {

    // outline0("; cpu_blit_finalize");

    _environment->blit.freeRegisters = 0;
    _environment->blit.usedMemory = 0;

    outline0("POP DI");
    outline0("POP SI");
    
}

char * cpu_blit_register_name(  Environment * _environment, int _register ) {
    
    if ( _register < CPU8086_BLIT_REGISTER_COUNT ) {
        return &CPU8086_BLIT_REGISTER[_register][0];
    } else {
        return &CPU8086_BLIT_REGISTER[ (_register & 0xff00) >> 8][0];
    }
}

int cpu_blit_alloc_register(  Environment * _environment ) {

    int reg = 0;

    for( reg = 0; reg < CPU8086_BLIT_REGISTER_COUNT; ++reg ) {
        int registerMask = ( 0x01 << reg );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( ! isRegisterUsed ) {
            _environment->blit.freeRegisters |= registerMask;
            // printf( "cpu_blit_alloc_register() %4.4x -> 0x%4.4x\n", _environment->blit.freeRegisters, reg );
            // outline1("; cpu_blit_alloc_register = %d", reg );
            return reg;
        }
    }

    int location = _environment->blit.usedMemory++;

    if ( location > 0xff ) {
        CRITICAL_BLIT_ALLOC_MEMORY_EXHAUSTED( );
    }

    for( reg = 0; reg < CPU8086_BLIT_REGISTER_COUNT; ++reg ) {
        int registerMask = ( 0x10 << reg );
        int isRegisterUsed = _environment->blit.freeRegisters & registerMask;
        if ( ! isRegisterUsed ) {
            outline1( "MOV AL, %s", &CPU8086_BLIT_REGISTER[reg][0] );
            outline2( "MOV [%sbs+0x%2.2x], AL",  _environment->blit.realName, location );
            _environment->blit.freeRegisters |= registerMask;
            // printf( "cpu_blit_alloc_register() -> %4.4x 0x%4.4x\n", _environment->blit.freeRegisters, ( ( reg << 8 ) | location ) );
            // outline1("; cpu_blit_alloc_register = %d", ( ( (reg+1) << 8 ) | location ) );
            return ( ( (reg+1) << 8 ) | location );
        }
    }

    CRITICAL_BLIT_ALLOC_REGISTER_EXHAUSTED( );

}

void cpu_blit_free_register(  Environment * _environment, int _register ) {

    // outline1("; cpu_blit_free_register = %d", _register );

    // printf( "cpu_blit_free_register(0x%4.4x)\n", _register );

    int location = _register & 0xff;
    int reg;

    if ( _register < CPU8086_BLIT_REGISTER_COUNT ) {
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
            outline2( "MOV AL, [%sbs+0x%2.2x]",  _environment->blit.realName, location );
            outline1( "MOV %s, AL", &CPU8086_BLIT_REGISTER[reg][0] );
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
                    cpu_store_8bit( _environment, destinationAddress, ( _value[(i*4)] & (0xff>>(8-_n)) ) );
                    i = i + 1;
                    break;
                case 9: case 10: case 11: case 12:
                case 13: case 14: case 15: case 16:
                    cpu_store_8bit( _environment, destinationAddress, ( _value[(i*4)] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu_store_8bit( _environment, destinationAddress, ( _value[(i*4)+1] & (0xff>>(16-_n)) ) );
                    i = i + 2;
                    break;
                case 17: case 18: case 19: case 20:
                case 21: case 22: case 23: case 24:
                    cpu_store_8bit( _environment, destinationAddress, ( _value[(i*4)] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu_store_8bit( _environment, destinationAddress, ( _value[(i*4)+1] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    cpu_store_8bit( _environment, destinationAddress, ( _value[(i*4)+2] & (0xff>>(24-_n)) ) );
                    i = i + 3;
                    break;
                case 25: case 26: case 27: case 28:
                case 29: case 30: case 31: case 32:
                default:
                    cpu_store_8bit( _environment, destinationAddress, ( _value[(i*4)] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
                    cpu_store_8bit( _environment, destinationAddress, ( _value[(i*4)+1] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
                    cpu_store_8bit( _environment, destinationAddress, ( _value[(i*4)+2] & (0xff) ) );
                    sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
                    cpu_store_8bit( _environment, destinationAddress, ( _value[(i*4)+3] & (0xff>>(32-_n)) ) );
                    i = i + 4;
                    break;
            }
            _n = 0;
        } else {
            cpu_store_8bit( _environment, destinationAddress, ( _value[(i*4)] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+1 );
            cpu_store_8bit( _environment, destinationAddress, ( _value[(i*4)+1] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+2 );
            cpu_store_8bit( _environment, destinationAddress, ( _value[(i*4)+2] & (0xff) ) );
            sprintf( destinationAddress, "%s+%d", _destination, i*4+3 );
            cpu_store_8bit( _environment, destinationAddress, ( _value[(i*4)+3] & (0xff>>(32-_n)) ) );
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
            outline1("MOV AL, [%s]", address_displacement(_environment, _source, offset));
            outline1("CMP AL, [%s]", address_displacement(_environment, _destination, offset));
            outline1("JNZ %s", label);
        }
        outline1("MOV AL, 0x%2.2x", 0xff*_positive);
        if ( _other ) {
            outline1("MOV [%s], AL", _other);
        } else {
            outline1("MOV [%s], AL", _destination);
        }
        outline1("JMP %s_2", label);
        outhead1("%s:", label);
        outline1("MOV AL, 0x%2.2x", 0xff*(1-_positive));
        if ( _other ) {
            outline1("MOV [%s], AL", _other);
        } else {
            outline1("MOV [%s], AL", _destination);
        }
        outhead1("%s_2:", label);
    
    no_embedded( cpu_compare_nbit )

}

void cpu_compare_nbit_const( Environment * _environment, char *_source, int _destination,  char *_other, int _positive, int _bits ) {

    MAKE_LABEL

    inline( cpu_compare_nbit )

        for( int i=0; i<(_bits>>3); ++i ) {
            char offset[MAX_TEMPORARY_STORAGE]; sprintf( offset, "%d", i );
            outline1("MOV AL, [%s]", address_displacement(_environment, _source, offset));
            outline1("CMP AL, 0x%2.2x", (unsigned char)((_destination>>(i*8)) && 0xff));
            outline1("JNZ %s", label);
        }
        outline1("MOV AL, 0x%2.2x", 0xff*_positive);
        if ( _other ) {
            outline1("MOV [%s], AL", _other);
        } else {
            outline1("MOV [%s], AL", _destination);
        }
        outline1("JMP %s_2", label);
        outhead1("%s:", label);
        outline1("MOV AL, 0x%2.2x", 0xff*(1-_positive));
        if ( _other ) {
            outline1("MOV [%s], AL", _other);
        } else {
            outline1("MOV [%s], AL", _destination);
        }
        outhead1("%s_2:", label);
    
    no_embedded( cpu_compare_nbit )

}

//                  [0]      [1]      [2]      [3]      [4]      [5]      [6]      [7]      [8]      [9]
// FAST	    (24)	seeeeeee mmmmmmmm mmmmmmmm

void cpu_float_fast_from_double_to_int_array( Environment * _environment, double _value, int _result[] ) {

    cpu_float_single_from_double_to_int_array( _environment, _value, _result );

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

    cpu_float_single_to_string( _environment, _x, _string,  _string_size );

}

void cpu_float_single_to_string( Environment * _environment, char * _x, char * _string, char * _string_size ) {

    MAKE_LABEL

    deploy( fp_vars, src_hw_8086_fp_vars_asm );
    deploy( fp_single_to_string, src_hw_8086_fp_single_to_string_asm );
    deploy( numberToString, src_hw_8086_number_to_string_asm );
    deploy( duff, src_hw_8086_duff_asm );

    outline1( "MOV DI, [%s]", _string );
    outline1( "FLD DWORD [%s]", _x );
    outline0( "CALL FPSINGLETOA" );
    outline1( "MOV [%s], CL", _string_size );

}

void cpu_float_double_to_string( Environment * _environment, char * _x, char * _string, char * _string_size ) {
    
}

void cpu_float_fast_from_16( Environment * _environment, char * _value, char * _result, int _signed ) {

    cpu_float_single_from_16( _environment, _value, _result, _signed );

}

void cpu_float_fast_from_8( Environment * _environment, char * _value, char * _result, int _signed ) {

    cpu_float_single_from_8( _environment, _value, _result, _signed );

}

void cpu_float_fast_to_16( Environment * _environment, char * _value, char * _result, int _signed ) {

    cpu_float_single_to_16( _environment, _value, _result, _signed );

}

void cpu_float_fast_to_8( Environment * _environment, char * _value, char * _result, int _signed ) {

    cpu_float_single_to_8( _environment, _value, _result, _signed );

}

void cpu_float_fast_add( Environment * _environment, char * _x, char * _y, char * _result ) {

    cpu_float_single_add(  _environment, _x, _y, _result );

}

void cpu_float_fast_sub( Environment * _environment, char * _x, char * _y, char * _result ) {

    cpu_float_single_sub( _environment, _x, _y, _result );

}

void cpu_float_fast_mul( Environment * _environment, char * _x, char * _y, char * _result ) {

    cpu_float_single_mul( _environment, _x, _y, _result );

}

void cpu_float_fast_div( Environment * _environment, char * _x, char * _y, char * _result ) {

    cpu_float_single_div( _environment, _x, _y, _result );

}

void cpu_float_fast_cmp( Environment * _environment, char * _x, char * _y, char * _result ) {

    cpu_float_single_cmp( _environment, _x, _y, _result );

}

void cpu_float_fast_sin( Environment * _environment, char * _angle, char * _result ) {

    cpu_float_single_sin( _environment, _angle, _result );

}

void cpu_float_fast_cos( Environment * _environment, char * _angle, char * _result ) {

    cpu_float_single_cos( _environment, _angle, _result );

}

void cpu_float_fast_tan( Environment * _environment, char * _angle, char * _result ) {

    cpu_float_single_tan( _environment, _angle, _result );

}

void cpu_float_fast_sqr( Environment * _environment, char * _value, char * _result ) {

    cpu_float_fast_sqr( _environment, _value, _result );

}

void cpu_float_fast_neg( Environment * _environment, char * _value, char * _result ) {

    cpu_float_fast_neg( _environment, _value, _result );

}

void cpu_float_single_from_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    deploy( fp_vars, src_hw_8086_fp_vars_asm );

    outline1( "FILD WORD [%s]", _value );
    outline1( "FSTP DWORD [%s]", _result );

}

void cpu_float_single_from_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    deploy( fp_vars, src_hw_8086_fp_vars_asm );

    outline1( "FILD BYTE [%s]", _value );
    outline1( "FSTP DWORD [%s]", _result );

}

void cpu_float_single_to_16( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    deploy( fp_vars, src_hw_8086_fp_vars_asm );

    outline1( "FLD DWORD [%s]", _value );
    outline1( "FISTP WORD [%s]", _result );

}

void cpu_float_single_to_8( Environment * _environment, char * _value, char * _result, int _signed ) {
    
    deploy( fp_vars, src_hw_8086_fp_vars_asm );

    outline1( "FLD BYTE [%s]", _value );
    outline1( "FISTP BYTE [%s]", _result );

}

void cpu_float_single_add( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy( fp_vars, src_hw_8086_fp_vars_asm );

    outline1( "FLD DWORD [%s]", _x );
    outline1( "FLD DWORD [%s]", _y );
    outline0( "FADD");
    outline1( "FSTP DWORD [%s]", _result );

}

void cpu_float_single_sub( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy( fp_vars, src_hw_8086_fp_vars_asm );

    outline1( "FLD DWORD [%s]", _x );
    outline1( "FLD DWORD [%s]", _y );
    outline0( "FSUB");
    outline1( "FSTP DWORD [%s]", _result );
    
}

void cpu_float_single_mul( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy( fp_vars, src_hw_8086_fp_vars_asm );

    outline1( "FLD DWORD [%s]", _x );
    outline1( "FLD DWORD [%s]", _y );
    outline0( "FMUL");
    outline1( "FSTP DWORD [%s]", _result );

}

void cpu_float_single_div( Environment * _environment, char * _x, char * _y, char * _result ) {

    deploy( fp_vars, src_hw_8086_fp_vars_asm );

    outline1( "FLD DWORD [%s]", _x );
    outline1( "FLD DWORD [%s]", _y );
    outline0( "FDIV");
    outline1( "FSTP DWORD [%s]", _result );
    
}

void cpu_float_single_cmp( Environment * _environment, char * _x, char * _y, char * _result ) {

    MAKE_LABEL
    
    deploy( fp_vars, src_hw_8086_fp_vars_asm );

    outline1( "FLD DWORD [%s]", _y );
    outline1( "FLD DWORD [%s]", _x );
    outline0( "FCMP");
    outline0( "FSTSW AX");
    outline0( "AND AX, %0100011100000000");
    outline0( "CMP AX, %0000000000000000");
    outline1( "JE %sgreater", label );
    outline0( "CMP AX, %0000000100000000B");
    outline1( "JE %sless", label );
    outline0( "CMP AX, %0100000000000000B");
    outline1( "JE %sequal", label );
    outhead1( "%sgreater:", label );
    outline0( "MOV AL, 1" );
    outline1( "MOV [%s], A", _result );
    outline1( "JMP %sdone", label );
    outhead1( "%sequal:", label );
    outline0( "MOV AL, 0" );
    outline1( "MOV [%s], AL", _result );
    outline1( "JMP %sdone", label );
    outhead1( "%sless:", label );
    outline0( "MOV AL, 0xff" );
    outline1( "MOV [%s], AL", _result );
    outline1( "JMP %sdone", label );
    outhead1( "%sdone:", label );

}

void cpu_float_single_neg( Environment * _environment, char * _value, char * _result ) {

    deploy( fp_vars, src_hw_8086_fp_vars_asm );

    Variable * zero = variable_temporary( _environment, VT_WORD, "()");
    variable_store( _environment, zero->realName, 0 );

    outline1( "FILD DWORD [%s]", zero->realName );
    outline1( "FLD DWORD [%s]", _value );
    outline0( "FSUB");
    outline1( "FSTP DWORD [%s]", _result );

}

void cpu_float_single_sin( Environment * _environment, char * _angle, char * _result ) {

    CRITICAL_UNIMPLEMENTED("SIN");

}

void cpu_float_single_cos( Environment * _environment, char * _angle, char * _result ) {

    deploy( fp_vars, src_hw_8086_fp_vars_asm );
    deploy( fp_single_cos, src_hw_8086_fp_cos_asm );

    outline1( "FLD DWORD [%s]", _angle );
    outline0( "CALL FPCOS");
    outline1( "FSTP DWORD [%s]", _result );

}

void cpu_float_single_tan( Environment * _environment, char * _angle, char * _result ) {

    deploy( fp_vars, src_hw_8086_fp_vars_asm );

    outline1( "FLD DWORD [%s]", _angle );
    outline0( "FTAN");
    outline1( "FSTP DWORD [%s]", _result );

}

void cpu_float_single_sqr( Environment * _environment, char * _value, char * _result ) {

    CRITICAL_UNIMPLEMENTED("SQR");

}

void cpu_address_table_build( Environment * _environment, char * _table, int * _values, char *_address[], int _count ) {

    // outhead1("%s:", _table );
    // for( int i=0; i<_count; ++i ) {
    //     outline2("DEFW 0x%4.4x, %s", _values[i], _address[i] );
    // }

}

void cpu_address_table_lookup( Environment * _environment, char * _table, int _count ) {

    // outhead1("LOOKFOR%s:", _table );
    // if ( _count ) {
    //     outline1("MOV HL, %s", _table );
    //     outline0("MOV C, 0" );
    //     outhead1("LOOKFOR%sL1:", _table );
    //     outline0("MOV AL, (HL)" );
    //     outline0("INC HL" );
    //     outline0("MOV B, A" );
    //     outline0("MOV AL, E" );
    //     outline0("CP B" );
    //     outline1("JR NZ, LOOKFOR%sNEXT3", _table );
    //     outline0("MOV AL, (HL)" );
    //     outline0("INC HL" );
    //     outline0("MOV B, A" );
    //     outline0("MOV AL, D" );
    //     outline0("CP B" );
    //     outline1("JR NZ, LOOKFOR%sNEXT2", _table );
    //     outline0("MOV AL, (HL)" );
    //     outline0("INC HL" );
    //     outline0("MOV E, A" );
    //     outline0("MOV AL, (HL)" );
    //     outline0("INC HL" );
    //     outline0("MOV D, A" );
    //     outline0("RET" );
    //     outhead1("LOOKFOR%sNEXT3:", _table );
    //     outline0("INC HL" );
    //     outhead1("LOOKFOR%sNEXT2:", _table );
    //     outline0("INC HL" );
    //     outline0("INC HL" );
    //     outline0("INC C" );
    //     outline0("MOV AL, C" );
    //     outline1("CMP AL, 0x%4.4x", (_count+1) );
    //     outline1("JR NZ, LOOKFOR%sL1", _table );
    // }
    // outline0("RET" );

}

void cpu_address_table_call( Environment * _environment, char * _table, char * _value, char * _address ) {

    // outline1("MOV DE, [%s]", _value );
    // outline1("CALL LOOKFOR%s", _table );
    // outline1("MOV [%s], DE", _address );

}

void cpu_move_8bit_signed_16bit_signed( Environment * _environment, char *_source, char *_destination ) {

    outline1("MOV AL, [%s]", _source );
    outline0("CBW" );
    outline1("MOV [%s], AX", _destination );

}

void cpu_move_8bit_signed_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AL, [%s]", _source );
    outline0("CBW" );
    outline1("MOV [%s], AX", _destination );

}

void cpu_move_8bit_unsigned_16bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AL, [%s]", _source );
    outline0("MOV AH, 0" );
    outline1("MOV [%s], AX", _destination );

}

void cpu_move_8bit_unsigned_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AL, [%s]", _source );
    outline0("MOV AH, 0" );
    outline1("MOV [%s], AX", _destination );

}

void cpu_move_8bit_signed_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AL, [%s]", _source );
    outline0("CBW" );
    outline0("CWD" );
    outline1("MOV [%s], AX", _destination );
    outline1("MOV [%s], DX", address_displacement( _environment, _destination, "+2" ) );

}

void cpu_move_8bit_signed_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AL, [%s]", _source );
    outline0("CBW" );
    outline0("CWD" );
    outline1("MOV [%s], AX", _destination );
    outline1("MOV [%s], DX", address_displacement( _environment, _destination, "+2" ) );

}

void cpu_move_8bit_unsigned_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AL, [%s]", _source );
    outline0("MOV AH, 0" );
    outline1("MOV [%s], AX", _destination );
    outline0("MOV AX, 0" );
    outline1("MOV [%s], AX", address_displacement( _environment, _destination, "+2" ) );

}
void cpu_move_8bit_unsigned_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AL, [%s]", _source );
    outline0("MOV AH, 0" );
    outline1("MOV [%s], AX", _destination );
    outline0("MOV AX, 0" );
    outline1("MOV [%s], AX", address_displacement( _environment, _destination, "+2" ) );

}

void cpu_move_16bit_signed_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AX, [%s]", _source );
    outline1("MOV [%s], AL", _destination );

}

void cpu_move_16bit_signed_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AX, [%s]", _source );
    outline1("MOV [%s], AL", _destination );

}
void cpu_move_16bit_unsigned_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AX, [%s]", _source );
    outline1("MOV [%s], AL", _destination );

}
void cpu_move_16bit_unsigned_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AX, [%s]", _source );
    outline1("MOV [%s], AL", _destination );

}

void cpu_move_16bit_signed_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AX, [%s]", _source );
    outline0("CWD" );
    outline1("MOV [%s], AX", _destination );
    outline1("MOV [%s], DX", address_displacement( _environment, _destination, "+2" ) );

}

void cpu_move_16bit_signed_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AX, [%s]", _source );
    outline0("CWD" );
    outline1("MOV [%s], AX", _destination );
    outline1("MOV [%s], DX", address_displacement( _environment, _destination, "+2" ) );

}

void cpu_move_16bit_unsigned_32bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AX, [%s]", _source );
    outline0("MOV DX, 0" );
    outline1("MOV [%s], AX", _destination );
    outline1("MOV [%s], DX", address_displacement( _environment, _destination, "+2" ) );

}
void cpu_move_16bit_unsigned_32bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AX, [%s]", _source );
    outline0("MOV DX, 0" );
    outline1("MOV [%s], AX", _destination );
    outline1("MOV [%s], DX", address_displacement( _environment, _destination, "+2" ) );

}

void cpu_move_32bit_signed_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AL, [%s]", _source );
    outline1("MOV [%s], AL", _destination );

}
void cpu_move_32bit_signed_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AL, [%s]", _source );
    outline1("MOV [%s], AL", _destination );

}
void cpu_move_32bit_unsigned_8bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AL, [%s]", _source );
    outline1("MOV [%s], AL", _destination );

}
void cpu_move_32bit_unsigned_8bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AL, [%s]", _source );
    outline1("MOV [%s], AL", _destination );

}

void cpu_move_32bit_signed_16bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AX, [%s]", _source );
    outline1("MOV [%s], AX", _destination );

}

void cpu_move_32bit_signed_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AX, [%s]", _source );
    outline1("MOV [%s], AX", _destination );

}

void cpu_move_32bit_unsigned_16bit_signed( Environment * _environment, char *_source, char *_destination ){

    outline1("MOV AX, [%s]", _source );
    outline1("MOV [%s], AX", _destination );

}

void cpu_move_32bit_unsigned_16bit_unsigned( Environment * _environment, char *_source, char *_destination ){
    
    outline1("MOV AX, [%s]", _source );
    outline1("MOV [%s], AX", _destination );

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