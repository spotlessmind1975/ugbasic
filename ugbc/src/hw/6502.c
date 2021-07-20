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

#if defined(__c64__) || defined(__plus4__) || defined(__atari__)

/**
 * @brief <i>CPU 6502</i>: emit code to make long conditional jump
 * 
 * This function outputs a code that guarantees an arbitrary distance jump 
 * with conditional check on equality. In fact, the opcode BEQ of the 
 * CPU 6502 processor allows to make a jump of maximum +/- 128 bytes with 
 * respect to the address where the processor is at that moment. 
 * To overcome this problem, this function will make a conditional jump to
 * a very close location, which (in turn) will make an unconditional jump 
 * to the true destination.
 * 
 * @param _environment Current calling environment
 * @param _label Destination of the conditional jump.
 */
void cpu6502_beq( Environment * _environment, char * _label ) {
    
    MAKE_LABEL

    outline1("BNE %s", label);
    outline1("JMP %s", _label);    
    outline1("%s:", label);
    
}

/**
 * @brief <i>CPU 6502</i>: emit code to make long conditional jump
 * 
 * @param _environment Current calling environment
 * @param _label Destination of the conditional jump.
 */
void cpu6502_bneq( Environment * _environment, char * _label ) {
    
    MAKE_LABEL

    outline1("BEQ %s", label);
    outline1("JMP %s", _label);    
    outline1("%s:", label);
    
}

void cpu6502_bveq( Environment * _environment, char * _value, char * _label ) {

    outline1("LDA %s", _value);
    cpu6502_beq( _environment,  _label );

}

void cpu6502_bvneq( Environment * _environment, char * _value, char * _label ) {

    outline1("LDA %s", _value);
    cpu6502_bneq( _environment,  _label );

}

void cpu6502_label( Environment * _environment, char * _label ) {
    outhead1("%s:", _label);
}

void cpu6502_peek( Environment * _environment, char * _address, char * _target ) {

    outline1("LDA %s", _address);
    outline0("STA TMPPTR");
    outline1("LDA %s+1", _address);
    outline0("STA TMPPTR+1");
    outline0("LDY #0");
    outline0("LDA (TMPPTR),Y");
    outline1("STA %s", _target);

}

void cpu6502_poke( Environment * _environment, char * _address, char * _source ) {

    outline1("LDA %s", _source);
    outline1("STA %s", _address);

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

    // Use the current bitmap address as starting address for filling routine.
    outline1("LDA %s", _address);
    outline0("STA TMPPTR");
    outline1("LDA %s+1", _address);
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
void cpu6502_fill( Environment * _environment, char * _address, char * _bytes, char * _pattern ) {

    MAKE_LABEL

    // Use the current bitmap address as starting address for filling routine.
    outline1("LDA %s", _address);
    outline0("STA TMPPTR");
    outline1("LDA %s+1", _address);
    outline0("STA TMPPTR+1");

    outline1("LDA %s", _pattern);
    outline0("STA TMPPTR2");
    outline1("LDA %s+1", _pattern);
    outline0("STA TMPPTR2+1");

    // Fill the bitmap with the given pattern.
    outline1("LDX %s", _bytes );
    outline0("LDY #0");
    outline0("LDA (TMPPTR2),Y");
    outhead1("%sx:", label);
    outline0("STA (TMPPTR),Y");
    outline0("INY");
    outline0("DEX");
    outline1("BNE %sx", label);

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
    outline0("; cpu6502_move_8bit");
    outline1("LDA %s", _source);
    outline1("STA %s", _destination);
}

/**
 * @brief <i>CPU 6502</i>: emit code to store 8 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void cpu6502_store_8bit( Environment * _environment, char *_destination, int _value ) {
    outline1("LDA #$%2.2x", (_value & 0xff));
    outline1("STA %s", _destination);
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

    cpu6502_less_than_8bit( _environment, _source, _destination, _other, !_equal, _signed );
    if ( _other ) {
        cpu6502_logical_not_8bit( _environment, _other, _other );
    } else {
        cpu6502_logical_not_8bit( _environment, _destination, _destination );
    }

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
    outline0("CLC");
    outline1("LDA %s", _source);
    outline1("ADC %s", _destination);
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
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
    outline0("SEC");
    outline1("LDA %s", _source);
    outline1("SBC %s", _destination);
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
}

/**
 * @brief <i>CPU 6502</i>: emit code to double a 8 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6502_math_double_8bit( Environment * _environment, char *_source, char *_other, int _signed ) {
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
}

/**
 * @brief <i>CPU 6502</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6502_math_div2_8bit( Environment * _environment, char *_source, int _steps, int _signed ) {
    int i=0;
    if ( _signed ) {
        outline1("LDA %s", _source);
        outline0("AND #$80");
        outline0("TAX");
        outline1("LDA %s", _source);
        for(i=0; i<_steps; ++i ) {
            outline0("LSR A");
        }
        outline1("STA %s", _source);
        outline0("TXA");
        outline1("ORA %s", _source);
        outline1("STA %s", _source);
    } else {
        outline1("LDA %s", _source);
        for(i=0; i<_steps; ++i ) {
            outline0("LSR A");
        }
        outline1("STA %s", _source);
    }
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
        outhead1("%s1:", label);
        outline0("LSR MATHPTR1");
        outline1("BCC %s_2", label);
        outline0("CLC");
        outline0("ADC MATHPTR0");
        outline1("%s_2:", label);
        outline0("ROR A");
        outline1("ROR %s", _other);
        outline0("DEX" );
        outline1("BNE %s1", label);
        outline1("STA %s+1", _other );

        outline0("PLA");
        outline0("AND #$80");
        outline1("BEQ %sdone", label);
        outline1("LDA %s", _other );
        outline0("EOR #$ff" );
        outline1("STA %s", _other );
        outline1("LDA %s+1", _other );
        outline0("EOR #$ff" );
        outline1("STA %s+1", _other );
        outline0("CLC" );
        outline1("LDA %s", _other );
        outline0("ADC #1" );
        outline1("STA %s", _other );
        outline1("LDA %s+1", _other );
        outline0("ADC #0" );
        outline1("STA %s+1", _other );
        outhead1("%sdone:", label );

    } else {
        outline0("LDA #0");
        outline0("LDX #8");
        outhead1("%s1:", label);
        outline1("LSR %s", _destination);
        outline1("BCC %s_2", label);
        outline0("CLC");
        outline1("ADC %s", _source);
        outline1("%s_2:", label);
        outline0("ROR A");
        outline1("ROR %s", _other);
        outline0("DEX" );
        outline1("BNE %s1", label);
        outline1("STA %s+1", _other );
    }
}

void cpu6502_math_div_8bit_to_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

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
    
}

/**
 * @brief <i>CPU 6502</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6502_math_div2_const_8bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    if ( _signed ) {
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
        while( _steps ) {
            outline0("CLC");
            outline1("ROR %s", _source);
            --_steps;
        }
    }

}

/**
 * @brief <i>CPU 6502</i>: emit code to double for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 */
void cpu6502_math_mul2_const_8bit( Environment * _environment, char *_source, int _steps, int _signed ) {

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

}

/**
 * @brief <i>CPU 6502</i>: emit code to calculate an 8 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void cpu6502_math_complement_const_8bit( Environment * _environment, char *_source, int _value ) {

    outline0("SEC");
    outline1("LDA #$%2.2x", ( _value & 0xff ) );
    outline1("SBC %s", _source);
    outline1("STA %s", _source );

}

/**
 * @brief <i>CPU 6502</i>: emit code to mask with "and" a value of 8 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void cpu6502_math_and_const_8bit( Environment * _environment, char *_source, int _mask ) {

    outline1("LDA %s", _source);
    outline1("AND #$%2.2x", (_mask & 0xff));
    outline1("STA %s", _source);

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
    outline1("LDA %s", _source);
    outline1("STA %s", _destination);
    outline1("LDA %s+1", _source);
    outline1("STA %s+1", _destination);
}

void cpu6502_addressof_16bit( Environment * _environment, char *_source, char *_destination ) {
    outline1("LDA #<%s", _source);
    outline1("STA %s", _destination);
    outline1("LDA #>%s", _source);
    outline1("STA %s+1", _destination);
}

/**
 * @brief <i>CPU 6502</i>: emit code to store 16 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void cpu6502_store_16bit( Environment * _environment, char *_destination, int _value ) {
    outline0(";; variable store 16 bit");
    outline1("LDA #$%2.2x", ( _value & 0xff ) );
    outline1("STA %s", _destination);
    outline1("LDA #$%2.2x", ( ( _value >> 8 ) & 0xff ) );
    outline1("STA %s+1", _destination);
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

    outline1("LDA %s", _source);
    outline1("CMP %s", _destination);
    outline1("BNE %s", label);
    outline1("LDA %s+1", _source);
    outline1("CMP %s+1", _destination);
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

    if ( _signed ) {
        outline1("LDA %s", _source);
        outline1("CMP %s", _destination);
        outline1("LDA %s+1", _source);
        outline1("SBC %s+1", _destination);
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
        outline1("LDA %s+1", _source);
        outline1("CMP %s+1", _destination );
        outline1("BEQ %s_1", label);
        outline1("BCC %s", label);
        outline1("BCS %s_0", label);
        outhead1("%s_1:", label);
        outline1("LDA %s", _source);
        outline1("CMP %s", _destination );
        outline1("BCC %s", label);
        if ( _equal ) {
            outline1("BEQ %s", label);
        }
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

    cpu6502_less_than_16bit( _environment, _source, _destination, _other, !_equal, _signed );
    if ( _other ) {
        cpu6502_logical_not_8bit( _environment, _other, _other );
    } else {
        cpu6502_logical_not_8bit( _environment, _destination, _destination );
    }

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
    outline0("CLC");
    outline1("LDA %s", _source);
    outline1("ADC %s", _destination);
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outline1("LDA %s+1", _source);
    outline1("ADC %s+1", _destination);
    if ( _other ) {
        outline1("STA %s+1", _other);
    } else {
        outline1("STA %s+1", _destination);
    }
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
    outline0("CLC");
    outline1("LDA %s", _source);
    outline1("ADC #<%s", _destination);
    outline1("STA %s", _other);
    outline1("LDA %s+1", _source);
    outline1("ADC #>%s", _destination);
    outline1("STA %s+1", _other);
}

void cpu6502_math_add_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {
    outline0("CLC");
    outline1("LDA %s", _source);
    outline1("ADC %s", _destination);
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outline1("LDA %s+1", _source);
    outline0("ADC #$0");
    if ( _other ) {
        outline1("STA %s+1", _other);
    } else {
        outline1("STA %s+1", _destination);
    }
}

/**
 * @brief <i>CPU 6502</i>: emit code to double a 16 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6502_math_double_16bit( Environment * _environment, char *_source, char *_other, int _signed ) {
    outline1("LDA %s", _source);
    outline0("ASL A");
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _source);
    }
    outline1("LDA %s+1", _source);
    outline0("ROL A");
    if ( _other ) {
        outline1("STA %s+1", _other);
    } else {
        outline1("STA %s+1", _source);
    }
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

    if ( _signed ) {

        outline1("LDA %s+1", _source );
        outline1("EOR %s+1", _destination );
        outline0("AND #$80" );
        outline0("PHA");

        outline1("LDA %s+1", _source );
        outline0("AND #$80" );
        outline1("BEQ %ssecond", label );
        outline0("CLC" );
        outline1("LDA %s", _source );
        outline0("EOR #$ff" );
        outline0("STA MATHPTR0" );
        outline1("LDA %s+1", _source );
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
        outline1("LDA %s+1", _source );
        outline0("STA MATHPTR1");
        outline1("JMP %ssecond2", label );

        outhead1("%ssecond2:", label );
        outline1("LDA %s+1", _destination );
        outline0("AND #$80" );
        outline1("BEQ %sthird", label );
        outline0("CLC" );
        outline1("LDA %s", _destination );
        outline0("EOR #$ff" );
        outline0("STA MATHPTR2" );
        outline1("LDA %s+1", _destination );
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
        outline1("LDA %s+1", _destination );
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
        outline1("STA %s+1", _other );
        outline0("LDA MATHPTR6");
        outline1("STA %s+2", _other );
        outline0("LDA MATHPTR7");
        outline1("STA %s+3", _other );

        outline0("PLA");
        outline0("AND #$80");
        outline1("BEQ %sdone", label);
        outline1("LDA %s", _other );
        outline0("EOR #$ff" );
        outline1("STA %s", _other );
        outline1("LDA %s+1", _other );
        outline0("EOR #$ff" );
        outline1("STA %s+1", _other );
        outline1("LDA %s+2", _other );
        outline0("EOR #$ff" );
        outline1("STA %s+2", _other );
        outline1("LDA %s+3", _other );
        outline0("EOR #$ff" );
        outline1("STA %s+3", _other );
        outline0("CLC" );
        outline1("LDA %s", _other );
        outline0("ADC #1" );
        outline1("STA %s", _other );
        outline1("LDA %s+1", _other );
        outline0("ADC #0" );
        outline1("STA %s+1", _other );
        outline1("LDA %s+2", _other );
        outline0("ADC #0" );
        outline1("STA %s+2", _other );
        outline1("LDA %s+3", _other );
        outline0("ADC #0" );
        outline1("STA %s+3", _other );
        outhead1("%sdone:", label );


    } else {

        outline1("LDA %s", _source );
        outline0("STA MATHPTR0");
        outline1("LDA %s+1", _source );
        outline0("STA MATHPTR1");
        outline1("LDA %s", _destination );
        outline0("STA MATHPTR2");
        outline1("LDA %s+1", _destination );
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
        outline1("STA %s+1", _other );
        outline0("LDA MATHPTR6");
        outline1("STA %s+2", _other );
        outline0("LDA MATHPTR7");
        outline1("STA %s+3", _other );

    }
    

}

void cpu6502_math_div_16bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    if ( _signed ) {

        outline1("LDA %s+1", _source );
        outline1("EOR %s+1", _destination );
        outline0("AND #$80" );
        outline0("PHA");

        outline1("LDA %s+1", _source );
        outline0("AND #$80" );
        outline1("BEQ %ssecond", label );
        outline0("CLC" );
        outline1("LDA %s", _source );
        outline0("EOR #$ff" );
        outline0("STA MATHPTR0" );
        outline1("LDA %s+1", _source );
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
        outline1("LDA %s+1", _source );
        outline0("STA MATHPTR1");
        outline1("JMP %ssecond2", label );

        outhead1("%ssecond2:", label );
        outline1("LDA %s+1", _destination );
        outline0("AND #$80" );
        outline1("BEQ %sthird", label );
        outline0("CLC" );
        outline1("LDA %s", _destination );
        outline0("EOR #$ff" );
        outline0("STA MATHPTR2" );
        outline1("LDA %s+1", _destination );
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
        outline1("LDA %s+1", _destination );
        outline0("STA MATHPTR3");
        outline1("JMP %sthird2", label );

        outhead1("%sthird2:", label );

        outline0("LDA MATHPTR0" );
        outline1("STA %s", _other );
        outline0("LDA MATHPTR1" );
        outline1("STA %s+1", _other );

        outline0("LDA #0" );
        outline1("STA %s", _other_remainder );
        outline1("STA %s+1", _other_remainder );
        outline0("LDX #16" );
        outhead1("%sL1:", label );
        outline1("ASL %s", _other );
        outline1("ROL %s+1", _other );
        outline1("ROL %s", _other_remainder );
        outline1("ROL %s+1", _other_remainder );
        outline1("LDA %s", _other_remainder );
        outline0("SEC" );
        outline0("SBC MATHPTR2" );
        outline0("TAY" );
        outline1("LDA %s+1", _other_remainder );
        outline0("SBC MATHPTR3" );
        outline1("BCC %sL2", label );
        outline1("STA %s+1", _other_remainder );
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
        outline1("LDA %s+1", _other );
        outline0("EOR #$ff" );
        outline1("STA %s+1", _other );
        outline0("CLC" );
        outline1("LDA %s", _other );
        outline0("ADC #1" );
        outline1("STA %s", _other );
        outline1("LDA %s+1", _other );
        outline0("ADC #0" );
        outline1("STA %s+1", _other );
        outhead1("%sdone:", label );
                
    } else {
        outline1("LDA %s", _source );
        outline1("STA %s", _other );
        outline1("LDA %s+1", _source );
        outline1("STA %s+1", _other );

        outline0("LDA #0" );
        outline1("STA %s", _other_remainder );
        outline1("STA %s+1", _other_remainder );
        outline0("LDX #16" );
        outhead1("%sL1:", label );
        outline1("ASL %s", _other );
        outline1("ROL %s+1", _other );
        outline1("ROL %s", _other_remainder );
        outline1("ROL %s+1", _other_remainder );
        outline1("LDA %s", _other_remainder );
        outline0("SEC" );
        outline1("SBC %s", _destination );
        outline0("TAY" );
        outline1("LDA %s+1", _other_remainder );
        outline1("SBC %s+1", _destination );
        outline1("BCC %sL2", label );
        outline1("STA %s+1", _other_remainder );
        outline1("STY %s", _other_remainder );
        outline1("INC %s", _other );
        outhead1("%sL2:", label );
        outline0("DEX" );
        outhead1("BNE %sL1", label );
    }


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
    outline0("SEC");
    outline1("LDA %s", _source);
    outline1("SBC %s", _destination);
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outline1("LDA %s+1", _source);
    outline1("SBC %s+1", _destination);
    if ( _other ) {
        outline1("STA %s+1", _other);
    } else {
        outline1("STA %s+1", _destination);
    }
}

void cpu6502_math_sub_16bit_with_8bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {
    outline0("SEC");
    outline1("LDA %s", _source);
    outline1("SBC %s", _destination);
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outline1("LDA %s+1", _source);
    outline0("SBC #$0");
    if ( _other ) {
        outline1("STA %s+1", _other);
    } else {
        outline1("STA %s+1", _destination);
    }
}

/**
 * @brief <i>CPU 6502</i>: emit code to calculate a 16 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void cpu6502_math_complement_const_16bit( Environment * _environment, char *_source, int _value ) {

    outline0("SEC");
    outline1("LDA #$%2.2x", ( _value & 0xff ) );
    outline1("SBC %s", _source);
    outline1("STA %s", _source );
    outline1("LDA #$%2.2x", ( ( _value >> 8 ) & 0xff ) );
    outline1("SBC %s+1", _source);
    outline1("STA %s+1", _source );

}

/**
 * @brief <i>CPU 6502</i>: emit code to halves for several times a 16 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6502_math_div2_const_16bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    if ( _signed ) {
        outline1("LDA %s+1", _source);
        outline0("AND #$80" );
        outline0("TAX")
        while( _steps ) {
            outline0("CLC");
            outline1("LSR %s+1", _source);
            outline1("ROR %s", _source);
            --_steps;
        }
        outline0("TXA")
        outline1("ORA %s+1", _source);
        outline1("STA %s+1", _source);
    } else {
        while( _steps ) {
            outline0("CLC");
            outline1("LSR %s+1", _source);
            outline1("ROR %s", _source);
            --_steps;
        }
    }

}

/**
 * @brief <i>CPU 6502</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6502_math_mul2_const_16bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    if ( _signed ) {
        outline1("LDA %s+1", _source);
        outline0("AND #$80" );
        outline0("TAX")
        while( _steps ) {
            outline0("CLC");
            outline1("ASL %s", _source);
            outline1("ROL %s+1", _source);
            --_steps;
        }
        outline0("TXA")
        outline1("ORA %s+1", _source);
        outline1("STA %s+1", _source);
    } else {
        while( _steps ) {
            outline0("CLC");
            outline1("ASL %s", _source);
            outline1("ROL %s+1", _source);
            --_steps;
        }
    }

}

/**
 * @brief <i>CPU 6502</i>: emit code to mask with "and" a value of 16 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void cpu6502_math_and_const_16bit( Environment * _environment, char *_source, int _mask ) {

    outline1("LDA %s", _source);
    outline1("AND #$%2.2x", (_mask & 0xff ) );
    outline1("STA %s", _source);
    outline1("LDA %s+1", _source);
    outline1("AND #$%2.2x", ((_mask>>8) & 0xff ));
    outline1("STA %s+1", _source);

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
    outline1("LDA %s", _source);
    outline1("STA %s", _destination);
    outline1("LDA %s+1", _source);
    outline1("STA %s+1", _destination);
    outline1("LDA %s+2", _source);
    outline1("STA %s+2", _destination);
    outline1("LDA %s+3", _source);
    outline1("STA %s+3", _destination);
}

/**
 * @brief <i>CPU 6502</i>: emit code to store 32 bit
 * 
 * @param _environment Current calling environment
 * @param _destination Destination of store
 * @param _value Value to store
 */
void cpu6502_store_32bit( Environment * _environment, char *_destination, int _value ) {
    outline1("LDA #$%2.2x", ( _value & 0xff ) );
    outline1("STA %s", _destination);
    outline1("LDA #$%2.2x", ( ( _value >> 8 ) & 0xff ) );
    outline1("STA %s+1", _destination);
    outline1("LDA #$%2.2x", ( ( _value >> 16 ) & 0xff ) );
    outline1("STA %s+2", _destination);
    outline1("LDA #$%2.2x", ( ( _value >> 24 ) & 0xff ) );
    outline1("STA %s+3", _destination);
}

void cpu6502_math_div_32bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, char * _other_remainder, int _signed ) {

    MAKE_LABEL

    outline1("LDA %s", _source );
    outline0("STA MATHPTR4");
    outline1("LDA %s+1", _source );
    outline0("STA MATHPTR5");
    outline1("LDA %s+2", _source );
    outline0("STA MATHPTR2");
    outline1("LDA %s+3", _source );
    outline0("STA MATHPTR3" );

    outline1("LDA %s", _destination );
    outline0("STA MATHPTR0");
    outline1("LDA %s+1", _destination );
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
    outline1("STA %s+1", _other );
    outline0("LDA MATHPTR2");
    outline1("STA %s", _other_remainder );
    outline0("LDA MATHPTR3");
    outline1("STA %s+1", _other_remainder );

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

    outline1("LDA %s", _source);
    outline1("CMP %s", _destination);
    outline1("BNE %s", label);
    outline1("LDA %s+1", _source);
    outline1("CMP %s+1", _destination);
    outline1("BNE %s", label);
    outline1("LDA %s+2", _source);
    outline1("CMP %s+2", _destination);
    outline1("BNE %s", label);
    outline1("LDA %s+3", _source);
    outline1("CMP %s+3", _destination);
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

    if ( _signed ) {
        outline1("LDA %s", _source);
        outline1("CMP %s", _destination);
        outline1("LDA %s+1", _source);
        outline1("SBC %s+1", _destination);
        outline1("LDA %s+2", _source);
        outline1("SBC %s+2", _destination);
        outline1("LDA %s+3", _source);
        outline1("SBC %s+3", _destination);
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
        outline1("LDA %s+3", _source);
        outline1("CMP %s+3", _destination );
        outline1("BEQ %s_1a", label);
        outline1("BCC %s", label);
        outline1("BCS %s_0", label);
        outhead1("%s_1a:", label);
        outline1("LDA %s+2", _source);
        outline1("CMP %s+2", _destination );
        outline1("BEQ %s_1", label);
        outline1("BCC %s", label);
        outline1("BCS %s_0", label);
        outhead1("%s_1:", label);
        outline1("LDA %s+1", _source);
        outline1("CMP %s+1", _destination );
        outline1("BEQ %s_1b", label);
        outline1("BCC %s", label);
        outline1("BCS %s_0", label);
        outhead1("%s_1b:", label);
        outline1("LDA %s", _source);
        outline1("CMP %s", _destination );
        if ( _equal ) {
            outline1("BEQ %s", label);
        }
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

    cpu6502_less_than_32bit( _environment, _source, _destination, _other, !_equal, _signed );
    if ( _other ) {
        cpu6502_logical_not_8bit( _environment, _other, _other );
    } else {
        cpu6502_logical_not_8bit( _environment, _destination, _destination );
    }

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
    outline0("CLC");
    outline1("LDA %s", _source);
    outline1("ADC %s", _destination);
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outline1("LDA %s+1", _source);
    outline1("ADC %s+1", _destination);
    if ( _other ) {
        outline1("STA %s+1", _other);
    } else {
        outline1("STA %s+1", _destination);
    }
    outline1("LDA %s+2", _source);
    outline1("ADC %s+2", _destination);
    if ( _other ) {
        outline1("STA %s+2", _other);
    } else {
        outline1("STA %s+2", _destination);
    }
    outline1("LDA %s+3", _source);
    outline1("ADC %s+3", _destination);
    if ( _other ) {
        outline1("STA %s+3", _other);
    } else {
        outline1("STA %s+3", _destination);
    }
}

/**
 * @brief <i>CPU 6502</i>: emit code to double a 32 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6502_math_double_32bit( Environment * _environment, char *_source, char *_other, int _signed ) {
    outline1("LDA %s", _source);
    outline0("ASL A");
    if ( _other ) {
        outline1("STA %s", _source);
    } else {
        outline1("STA %s", _source);
    }
    outline1("LDA %s+1", _source);
    outline0("ROL A");
    if ( _other ) {
        outline1("STA %s+1", _source);
    } else {
        outline1("STA %s+1", _source);
    }
    outline1("LDA %s+2", _source);
    outline0("ROL A");
    if ( _other ) {
        outline1("STA %s+2", _source);
    } else {
        outline1("STA %s+2", _source);
    }
    outline1("LDA %s+3", _source);
    outline0("ROL A");
    if ( _other ) {
        outline1("STA %s+3", _source);
    } else {
        outline1("STA %s+3", _source);
    }
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
    outline0("SEC");
    outline1("LDA %s", _source);
    outline1("SBC %s", _destination);
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outline1("LDA %s+1", _source);
    outline1("SBC %s+1", _destination);
    if ( _other ) {
        outline1("STA %s+1", _other);
    } else {
        outline1("STA %s+1", _destination);
    }
    outline1("LDA %s+2", _source);
    outline1("SBC %s+2", _destination);
    if ( _other ) {
        outline1("STA %s+2", _other);
    } else {
        outline1("STA %s+2", _destination);
    }
    outline1("LDA %s+3", _source);
    outline1("SBC %s+3", _destination);
    if ( _other ) {
        outline1("STA %s+3", _other);
    } else {
        outline1("STA %s+3", _destination);
    }
}

/**
 * @brief <i>CPU 6502</i>: emit code to calculate a 32 bit complement of a number
 * 
 * @param _environment Current calling environment
 * @param _source Value to complement
 * @param _value Valure to use as base for complement
 */
void cpu6502_math_complement_const_32bit( Environment * _environment, char *_source, int _value ) {

    outline0("SEC");
    outline1("LDA #$%2.2x", ( _value & 0xff ) );
    outline1("SBC %s", _source);
    outline1("STA %s", _source );
    outline1("LDA #$%2.2x", ( ( _value >> 8 ) & 0xff ) );
    outline1("SBC %s+1", _source);
    outline1("STA %s+1", _source );
    outline1("LDA #$%2.2x", ( ( _value >> 16 ) & 0xff ) );
    outline1("SBC %s+2", _source);
    outline1("STA %s+2", _source );
    outline1("LDA #$%2.2x", ( ( _value >> 24 ) & 0xff ) );
    outline1("SBC %s+3", _source);
    outline1("STA %s+3", _source );

}

/**
 * @brief <i>CPU 6502</i>: emit code to halves for several times a 32 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6502_math_div2_const_32bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    if ( _signed ) {
        outline1("LDA %s+3", _source);
        outline0("AND #$80");
        outline0("TAX");
        while( _steps ) {
            outline0("CLC");
            outline1("LSR %s+3", _source);
            outline1("ROR %s+2", _source);
            outline1("ROR %s+1", _source);
            outline1("ROR %s", _source);
            --_steps;
        }
        outline0("TXA");
        outline1("ORA %s+3", _source);
        outline1("STA %s+3", _source);
    } else {
        while( _steps ) {
            outline0("CLC");
            outline1("LSR %s+3", _source);
            outline1("ROR %s+2", _source);
            outline1("ROR %s+1", _source);
            outline1("ROR %s", _source);
            --_steps;
        }
    }

}

/**
 * @brief <i>CPU 6502</i>: emit code to double for several times a 32 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 */
void cpu6502_math_mul2_const_32bit( Environment * _environment, char *_source, int _steps, int _signed ) {

    if ( _signed ) {
        outline1("LDA %s+3", _source);
        outline0("AND #$80");
        outline0("TAX");
        while( _steps ) {
            outline0("CLC");
            outline1("ASL %s", _source);
            outline1("ROL %s+1", _source);
            outline1("ROL %s+2", _source);
            outline1("ROL %s+3", _source);
            --_steps;
        }
        outline0("TXA");
        outline1("ORA %s+3", _source);
        outline1("STA %s+3", _source);
    } else {
        while( _steps ) {
            outline0("CLC");
            outline1("ASL %s", _source);
            outline1("ROL %s+1", _source);
            outline1("ROL %s+2", _source);
            outline1("ROL %s+3", _source);
            --_steps;
        }
    }

}

/**
 * @brief <i>CPU 6502</i>: emit code to mask with "and" a value of 32 bit
 * 
 * @param _environment Current calling environment
 * @param _source Value to mask (and destination of mask operation)
 * @param _mask Mask to use
 */
void cpu6502_math_and_const_32bit( Environment * _environment, char *_source, int _mask ) {

    outline1("LDA %s", _source);
    outline1("AND #$%2.2x", (_mask & 0xff ) );
    outline1("STA %s", _source);
    outline1("LDA %s+1", _source);
    outline1("AND #$%2.2x", ((_mask>>8) & 0xff ));
    outline1("STA %s+1", _source);
    outline1("LDA %s+2", _source);
    outline1("AND #$%2.2x", ((_mask>>16) & 0xff ) );
    outline1("STA %s+2", _source);
    outline1("LDA %s+3", _source);
    outline1("AND #$%2.2x", ((_mask>>24) & 0xff ));
    outline1("STA %s+3", _source);

}

void cpu6502_combine_nibbles( Environment * _environment, char * _low_nibble, char * _hi_nibble, char * _byte ) {

    outline1("LDA %s", _low_nibble);
    outline1("STA %s", _byte);
    outline1("LDA %s", _hi_nibble);
    outline0("ASL");
    outline0("ASL");
    outline0("ASL");
    outline0("ASL");
    outline1("ORA %s", _byte);
    outline1("STA %s", _byte);

}

void cpu6502_jump( Environment * _environment, char * _label ) {

    outline1("JMP %s", _label );

}

void cpu6502_call( Environment * _environment, char * _label ) {

    outline1("JSR %s", _label );

}

void cpu6502_return( Environment * _environment ) {

    outline0("RTS" );

}

void cpu6502_pop( Environment * _environment ) {

    outline0("PLA" );
    outline0("PLA" );

}

void cpu6502_halt( Environment * _environment ) {

    MAKE_LABEL

    outhead1("%s:", label );
    outline1("JMP %s", label);

}

void cpu6502_end( Environment * _environment ) {

    outline0("SEI");
    cpu6502_halt( _environment );

}

void cpu6502_random( Environment * _environment, char * _seed, char * _entropy ) {

    MAKE_LABEL

    outhead1("%s:", label);
    outline1("ASL %s", _seed);
    outline1("ROL %s+1", _seed);
    outline1("ROL %s+2", _seed);
    outline1("ROL %s+3", _seed);
    outline1("BCC %sxx2", label);
    outline1("LDA %s", _seed);
    outline1("EOR %s", _entropy)
    outline1("STA %s", _seed);
    outline1("LDA %s+1", _seed);
    outline0("EOR #$1D");
    outline1("STA %s+1", _seed );
    outline1("LDA %s+2", _seed );
    outline0("EOR #$C1" );
    outline1("STA %s+2", _seed );
    outline1("LDA %s+3", _seed );
    outline0("EOR #$04" );
    outline1("STA %s+3", _seed );
    outhead1("%sxx2:", label);

}

void cpu6502_random_8bit( Environment * _environment, char * _seed, char * _entropy, char * _result ) {

    cpu6502_random( _environment, _seed, _entropy );

    outline1("LDA %s", _seed );
    outline1("STA %s", _result );

}

void cpu6502_random_16bit( Environment * _environment, char * _seed, char * _entropy, char * _result ) {

    cpu6502_random( _environment, _seed, _entropy );

    outline1("LDA %s", _seed );
    outline1("STA %s", _result );
    outline1("LDA %s+1", _seed );
    outline1("STA %s+1", _result );

}

void cpu6502_random_32bit( Environment * _environment, char * _seed, char * _entropy, char * _result ) {

    cpu6502_random( _environment, _seed, _entropy );

    outline1("LDA %s", _seed );
    outline1("STA %s", _result );
    outline1("LDA %s+1", _seed );
    outline1("STA %s+1", _result );
    outline1("LDA %s+2", _seed );
    outline1("STA %s+2", _result );
    outline1("LDA %s+3", _seed );
    outline1("STA %s+3", _result );

}

void cpu6502_limit_16bit( Environment * _environment, char * _variable, int _value ) {

    MAKE_LABEL

    outline0( "LDA #$0" );
    outline1( "STA %s+1", _variable );
    outline1( "LDA %s", _variable );
    outline1( "CMP #$%2.2x", _value );
    outline1( "BCC %s", label );
    outline1( "SBC #$%2.2x", _value );
    outline1( "STA %s", _variable );
    outhead1( "%s:", label );

}

void cpu6502_busy_wait( Environment * _environment, char * _timing ) {

    MAKE_LABEL

    outline1("LDX %s", _timing );
    outhead1("%s:", label );
    outline0("DEX");
    outline1("BNE %s", label);

}

void cpu6502_logical_and_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

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

}

void cpu6502_logical_or_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LDA %s", _left );
    outhead1("BNE %s1", label );
    outline1("LDA %s", _right );
    outline1("BNE %s1", label);
    outline1("JMP %s0", label);
    outhead1("%s1:", label);
    outline0("LDA #$FF");
    outline1("STA %s", _result);
    outline1("JMP %sx", label);
    outhead1("%s0:", label);
    outline0("LDA #0");
    outline1("STA %s", _result);
    outhead1("%sx:", label);

}

void cpu6502_logical_not_8bit( Environment * _environment, char * _value, char * _result ) {

    MAKE_LABEL

    outline1("LDA %s", _value );
    outline0("EOR #$FF" );
    outline1("STA %s", _result );

}

void cpu6502_di( Environment * _environment ) {

    outline0("SEI" );

}

void cpu6502_ei( Environment * _environment ) {

    outline0("CLI" );

}

void cpu6502_inc( Environment * _environment, char * _variable ) {

    outline1("INC %s", _variable );

}

void cpu6502_inc_16bit( Environment * _environment, char * _variable ) {

    MAKE_LABEL

    outline1("INC %s", _variable );
    outline1("BNE %s", label );
    outline1("INC %s+1", _variable );
    outhead1("%s:", label );

}

void cpu6502_inc_32bit( Environment * _environment, char * _variable ) {

    MAKE_LABEL

    outline1("INC %s", _variable );
    outline1("BNE %s", label );
    outline1("INC %s+1", _variable );
    outline1("BNE %s", label );
    outline1("INC %s+2", _variable );
    outline1("BNE %s", label );
    outline1("INC %s+3", _variable );
    outhead1("%s:", label );

}

void cpu6502_dec( Environment * _environment, char * _variable ) {

    outline1("DEC %s", _variable );

}

void cpu6502_dec_16bit( Environment * _environment, char * _variable ) {

    MAKE_LABEL

    outline1("DEC %s", _variable );
    outline1("BNE %s", label );
    outline1("DEC %s+1", _variable );
    outhead1("%s:", label );

}

void cpu6502_mem_move( Environment * _environment, char *_source, char *_destination,  char *_size ) {

    MAKE_LABEL

    outline1("LDY %s", _size );
    outline1("BEQ %sdone", label );
    outline0("LDY #$0" );
    outline1("LDA %s+1", _source );
    outline0("STA TMPPTR+1" );
    outline1("LDA %s", _source );
    outline0("STA TMPPTR" );
    outline1("LDA %s+1", _destination );
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

}

void cpu6502_mem_move_size( Environment * _environment, char *_source, char *_destination, int _size ) {

    if ( _size ) {

        MAKE_LABEL

        outline0("LDY #$0" );
        outline1("LDA %s+1", _source );
        outline0("STA TMPPTR+1" );
        outline1("LDA %s", _source );
        outline0("STA TMPPTR" );
        outline1("LDA %s+1", _destination );
        outline0("STA TMPPTR2+1" );
        outline1("LDA %s", _destination );
        outline0("STA TMPPTR2" );
        outhead1("%s:", label );
        outline0("LDA (TMPPTR), Y" );
        outline0("STA (TMPPTR2), Y" );
        outline0("INY" );
        outline1("CPY #$%2.2x", (_size & 0xff ) );
        outline1("BNE %s", label );

    }

}

void cpu6502_mem_move_displacement(  Environment * _environment, char *_source, char *_destination, char * _displacement, char *_size ) {

    MAKE_LABEL

    outline1("LDY %s", _size );
    outline1("BEQ %sdone", label );
    outline0("LDY #$0" );
    outline1("LDA %s+1", _source );
    outline0("STA TMPPTR+1" );
    outline1("LDA %s", _source );
    outline1("ADC %s", _displacement );
    outline0("STA TMPPTR" );
    outline1("LDA %s+1", _destination );
    outline0("STA TMPPTR2+1" );
    outline1("LDA %s", _destination );
    outline0("STA TMPPTR2" );
    outhead1("%s:", label );
    outline0("LDA (TMPPTR2), Y" );
    outline0("STA (TMPPTR), Y" );
    outline0("INY" );
    outline1("CPY %s", _size );
    outline1("BNE %s", label );
    outhead1("%sdone:", label );

}

void cpu6502_compare_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {
    
    MAKE_LABEL

    outline1("LDA %s", _size );
    outline1("BEQ %sequal", label );
    outline0("LDY #$0" );
    outline1("LDA %s+1", _source );
    outline0("STA TMPPTR+1" );
    outline1("LDA %s", _source );
    outline0("STA TMPPTR" );
    outline1("LDA %s+1", _destination );
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

}

void cpu6502_compare_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {
    
    MAKE_LABEL

    outline0("LDY #$0" );
    outline1("LDA %s+1", _source );
    outline0("STA TMPPTR+1" );
    outline1("LDA %s", _source );
    outline0("STA TMPPTR" );
    outline1("LDA %s+1", _destination );
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

}

void cpu6502_less_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {
    
    MAKE_LABEL

    outline0("LDY #$0" );
    outline1("LDA %s+1", _source );
    outline0("STA TMPPTR+1" );
    outline1("LDA %s", _source );
    outline0("STA TMPPTR" );
    outline1("LDA %s+1", _destination );
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

}

void cpu6502_less_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {
    
    MAKE_LABEL

    outline0("LDY #$0" );
    outline1("LDA %s+1", _source );
    outline0("STA TMPPTR+1" );
    outline1("LDA %s", _source );
    outline0("STA TMPPTR" );
    outline1("LDA %s+1", _destination );
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

}

void cpu6502_greater_than_memory( Environment * _environment, char *_source, char *_destination, char *_size, char * _result, int _equal ) {
    
    MAKE_LABEL

    outline0("LDY #$0" );
    outline1("LDA %s+1", _source );
    outline0("STA TMPPTR+1" );
    outline1("LDA %s", _source );
    outline0("STA TMPPTR" );
    outline1("LDA %s+1", _destination );
    outline0("STA TMPPTR2+1" );
    outline1("LDA %s", _destination );
    outline0("STA TMPPTR2" );    
    outhead1("%sloop:", label );
    outline0("LDA (TMPPTR2), Y" );
    outline0("CMP (TMPPTR), Y" );
    if ( ! _equal ) {
        outline1("BEQ %sfalse", label);
    }
    outline1("BCS %sfalse", label);
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

}

void cpu6502_greater_than_memory_size( Environment * _environment, char *_source, char *_destination, int _size, char * _result, int _equal ) {
    
    MAKE_LABEL

    outline0("LDY #$0" );
    outline1("LDA %s+1", _source );
    outline0("STA TMPPTR+1" );
    outline1("LDA %s", _source );
    outline0("STA TMPPTR" );
    outline1("LDA %s+1", _destination );
    outline0("STA TMPPTR2+1" );
    outline1("LDA %s", _destination );
    outline0("STA TMPPTR2" );    
    outhead1("%sloop:", label );
    outline0("LDA (TMPPTR2), Y" );
    outline0("CMP (TMPPTR), Y" );
    outline1("BCC %sfalse", label);
    if ( ! _equal ) {
        outline1("BEQ %sfalse", label);
    }
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

}

void cpu6502_store_8bit_indirect( Environment * _environment, char *_source, int _value ) {

    outline1("LDA %s", _source);
    outline0("STA TMPPTR");
    outline1("LDA %s+1", _source);
    outline0("STA TMPPTR+1");
    outline1("LDA #$%2.2x", (_value & 0xff));
    outline0("LDY #$0" );
    outline0("STA (TMPPTR),Y");

}

void cpu6502_store_8bit_indirect_with_offset( Environment * _environment, char *_source, int _value, int _offset ) {

    outline1("LDA %s", _source);
    outline0("STA TMPPTR");
    outline1("LDA %s+1", _source);
    outline0("STA TMPPTR+1");
    outline1("LDA #$%2.2x", (_value & 0xff));
    outline1("LDy #$%2.2x", (_offset & 0xff));
    outline0("STA (TMPPTR),Y");

}


void cpu6502_move_8bit_indirect( Environment * _environment, char *_source, char * _value ) {

    outline1("LDA %s", _value);
    outline0("STA TMPPTR");
    outline1("LDA %s+1", _value);
    outline0("STA TMPPTR+1");
    outline1("LDA %s", _source);
    outline0("LDY #$0" );
    outline0("STA (TMPPTR),Y");

}

void cpu6502_move_8bit_indirect_with_offset( Environment * _environment, char *_source, char * _value, int _offset ) {

    outline1("LDA %s", _value);
    outline0("STA TMPPTR");
    outline1("LDA %s+1", _value);
    outline0("STA TMPPTR+1");
    outline1("LDA %s", _source);
    outline1("LDY #$%2.2x", (_offset & 0xff ) );
    outline0("STA (TMPPTR),Y");

}

void cpu6502_move_8bit_with_offset( Environment * _environment, char *_source, char * _value, int _offset ) {

    outline1("LDA %s", _value);
    outline0("STA TMPPTR");
    outline1("LDA %s+1", _value);
    outline0("STA TMPPTR+1");
    outline1("LDA %s", _source);
    outline1("LDY #$%2.2x", (_offset & 0xff ) );
    outline0("STA (TMPPTR),Y");

}

void cpu6502_move_8bit_indirect_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

    outline1("LDA %s", _value);
    outline0("STA TMPPTR");
    outline1("LDA %s+1", _value);
    outline0("STA TMPPTR+1");
    outline1("LDA %s", _source);
    outline1("LDY %s", _offset );
    outline0("STA (TMPPTR),Y");

}

void cpu6502_move_8bit_with_offset2( Environment * _environment, char *_source, char * _value, char * _offset ) {

    outline1("LDA #<%s", _value);
    outline0("STA TMPPTR");
    outline1("LDA #>%s", _value);
    outline0("STA TMPPTR+1");
    outline1("LDA %s", _source);
    outline1("LDY %s", _offset );
    outline0("STA (TMPPTR),Y");

}

void cpu6502_move_8bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    outline1("LDA %s", _value);
    outline0("STA TMPPTR");
    outline1("LDA %s+1", _value);
    outline0("STA TMPPTR+1");
    outline0("LDY #$0" );
    outline0("LDA (TMPPTR),Y");
    outline1("STA %s", _source);

}

void cpu6502_move_16bit_indirect( Environment * _environment, char *_source, char * _value ) {

    outline1("LDA %s", _value);
    outline0("STA TMPPTR");
    outline1("LDA %s+1", _value);
    outline0("STA TMPPTR+1");
    outline1("LDA %s", _source);
    outline0("LDY #$0" );
    outline0("STA (TMPPTR),Y");
    outline1("LDA %s+1", _source);
    outline0("LDY #$1" );
    outline0("STA (TMPPTR),Y");

}

void cpu6502_move_16bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    outline1("LDA %s", _value);
    outline0("STA TMPPTR");
    outline1("LDA %s+1", _value);
    outline0("STA TMPPTR+1");
    outline0("LDY #$0" );
    outline0("LDA (TMPPTR),Y");
    outline1("STA %s", _source);
    outline0("LDY #$1" );
    outline0("LDA (TMPPTR),Y");
    outline1("STA %s+1", _source);

}

void cpu6502_move_32bit_indirect( Environment * _environment, char *_source, char * _value ) {

    outline1("LDA %s", _value);
    outline0("STA TMPPTR");
    outline1("LDA %s+1", _value);
    outline0("STA TMPPTR+1");
    outline1("LDA %s", _source);
    outline0("LDY #$0" );
    outline0("STA (TMPPTR),Y");
    outline1("LDA %s+1", _source);
    outline0("LDY #$1" );
    outline0("STA (TMPPTR),Y");
    outline1("LDA %s+2", _source);
    outline0("LDY #$2" );
    outline0("STA (TMPPTR),Y");
    outline1("LDA %s+2", _source);
    outline0("LDY #$2" );
    outline0("STA (TMPPTR),Y");

}

void cpu6502_move_32bit_indirect2( Environment * _environment, char * _value, char *_source ) {

    outline1("LDA %s", _value);
    outline0("STA TMPPTR");
    outline1("LDA %s+1", _value);
    outline0("STA TMPPTR+1");
    outline0("LDY #$0" );
    outline0("LDA (TMPPTR),Y");
    outline1("STA %s", _source);
    outline0("LDY #$1" );
    outline0("LDA (TMPPTR),Y");
    outline1("STA %s+1", _source);
    outline0("LDY #$2" );
    outline0("LDA (TMPPTR),Y");
    outline1("STA %s+2", _source);
    outline0("LDY #$3" );
    outline0("LDA (TMPPTR),Y");
    outline1("STA %s+3", _source);

}

void cpu6502_uppercase( Environment * _environment, char *_source, char *_size, char *_result ) {

    MAKE_LABEL

    outline0("LDY #$0" );
    outline1("LDA %s+1", _source );
    outline0("STA TMPPTR+1" );
    outline1("LDA %s", _source );
    outline0("STA TMPPTR" );
    if ( _result ) {
        outline1("LDA %s+1", _result );
        outline0("STA TMPPTR2+1" );
        outline1("LDA %s", _result );
        outline0("STA TMPPTR2" );
    } else {
        outline1("LDA %s+1", _source );
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

}

void cpu6502_lowercase( Environment * _environment, char *_source, char *_size, char *_result ) {

    MAKE_LABEL

    outline0("LDY #$0" );
    outline1("LDA %s+1", _source );
    outline0("STA TMPPTR+1" );
    outline1("LDA %s", _source );
    outline0("STA TMPPTR" );
    if ( _result ) {
        outline1("LDA %s+1", _result );
        outline0("STA TMPPTR2+1" );
        outline1("LDA %s", _result );
        outline0("STA TMPPTR2" );
    } else {
        outline1("LDA %s+1", _source );
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

}

void cpu6502_convert_upto_24bit_bcd( Environment * _environment, char * _source, char * _dest, int _bits ) {

    MAKE_LABEL

    outline0("SED");
    outline0("LDA #0");
    outline1("STA %s+0", _dest);
    outline1("STA %s+1", _dest);
    outline1("STA %s+2", _dest);
    outline1("LDX #%d", _bits );

    outhead1("%sCNVBIT:", label );

    outline1("ASL %s+0", _source );
    outline1("ROL %s+1", _source );
    outline1("LDA %s+0", _dest);
    outline1("ADC %s+0", _dest);
    outline1("STA %s+0", _dest);
    outline1("LDA %s+1", _dest);
    outline1("ADC %s+1", _dest);
    outline1("STA %s+1", _dest);
    outline1("LDA %s+2", _dest);
    outline1("ADC %s+2", _dest);
    outline1("STA %s+2", _dest);
    outline0("DEX");
    outline1("BNE %sCNVBIT", label);
    outline0("CLD");

}

void cpu6502_convert_bcd_to_digits( Environment * _environment, char * _source, char * _dest ) {

    MAKE_LABEL

    outline1("LDA %s+1", _dest );
    outline0("STA TMPPTR+1" );
    outline1("LDA %s", _dest  );
    outline0("STA TMPPTR" );

    outline0("LDX #$0");
    outline0("LDY #$ff");
    outline1("LDA %s+2", _source);
    outline0("LSR A");
    outline0("LSR A");
    outline0("LSR A");
    outline0("LSR A");
    outline0("AND #$0F");
    outline1("BEQ %sd0", label);
    outline0("LDX #$1");
    outline0("ADC #48");
    outline0("INY");
    outline0("STA (TMPPTR),Y");
    outhead1("%sd0:", label);
    outline1("LDA %s+2", _source);
    outline0("AND #$0F");
    outline1("BNE %sd1a", label);
    outline0("CPX #$1");
    outline1("BNE %sd1", label);
    outline0("LDX #$1");
    outhead1("%sd1a:", label);
    outline0("ADC #48");
    outline0("INY");
    outline0("STA (TMPPTR),Y");

    outhead1("%sd1:", label);
    outline1("LDA %s+1", _source);
    outline0("LSR A");
    outline0("LSR A");
    outline0("LSR A");
    outline0("LSR A");
    outline0("AND #$0F");
    outline1("BNE %sd2a", label);
    outline0("CPX #$1");
    outline1("BNE %sd2", label);
    outline0("LDX #$1");
    outhead1("%sd2a:", label);
    outline0("ADC #48");
    outline0("INY");
    outline0("STA (TMPPTR),Y");

    outhead1("%sd2:", label);
    outline1("LDA %s+1", _source);
    outline0("AND #$0F");
    outline1("BNE %sd3a", label);
    outline0("CPX #$1");
    outline1("BNE %sd3", label);
    outline0("LDX #$1");
    outhead1("%sd3a:", label);
    outline0("ADC #48");
    outline0("INY");
    outline0("STA (TMPPTR),Y");

    outhead1("%sd3:", label);
    outline1("LDA %s", _source);
    outline0("LSR A");
    outline0("LSR A");
    outline0("LSR A");
    outline0("LSR A");
    outline0("AND #$0F");
    outline1("BNE %sd4a", label);
    outline0("CPX #$1");
    outline1("BNE %sd4", label);
    outline0("LDX #$1");
    outhead1("%sd4a:", label);
    outline0("ADC #48");
    outline0("INY");
    outline0("STA (TMPPTR),Y");

    outhead1("%sd4:", label);
    outline1("LDA %s", _source);
    outline0("AND #$0F");
    outline0("ADC #48");
    outline0("INY");
    outline0("STA (TMPPTR),Y");

    outline0("INY" );
    outline0("TYA" );
    outline1("STA %s-1", _dest );

}

void cpu6502_convert_string_into_16bit( Environment * _environment, char * _string, char * _len, char * _value ) {

    MAKE_LABEL

    outline0("LDA #$0" );
    outline1("STA %s", _value );
    outline1("STA %s+1", _value );

    outline1("LDA %s+1", _string );
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
    outline1("ADC %s+1", _value);
    outline1("STA %s+1", _value);

    outline1("LDA %s+1", _value );
    outline0("STA TMPPTR2+1" );
    outline1("LDA %s", _value  );
    outline0("STA TMPPTR2" );

    outline0("INY");
    outline1("CPY %s", _len );
    outline1("BEQ %send", label );

    outline0("LDA TMPPTR2" );
    outline1("STA %s", _value );
    outline0("LDA TMPPTR2+1" );
    outline1("STA %s+1", _value );
    outline1("ASL %s", _value );
    outline1("ROL %s+1", _value );
    outline1("ASL %s", _value );
    outline1("ROL %s+1", _value );
    outline0("CLC" );
    outline0("LDA TMPPTR2" );
    outline1("ADC %s", _value );
    outline1("STA %s", _value );
    outline0("LDA TMPPTR2+1" );
    outline1("ADC %s+1", _value );
    outline1("STA %s+1", _value );
    outline1("ASL %s", _value );
    outline1("ROL %s+1", _value );

    outline1("JMP %srepeat", label );

    outhead1("%send:", label );

}

void cpu6502_fill_indirect( Environment * _environment, char * _address, char * _size, char * _pattern ) {

    MAKE_LABEL

    // Use the current bitmap address as starting address for filling routine.
    outline1("LDA %s", _address);
    outline0("STA TMPPTR");
    outline1("LDA %s+1", _address);
    outline0("STA TMPPTR+1");

    outline1("LDA %s", _pattern);
    outline0("STA TMPPTR2");
    outline1("LDA %s+1", _pattern);
    outline0("STA TMPPTR2+1");

    // Fill the bitmap with the given pattern.
    outline1("LDX %s", _size );
    outhead1("%sx:", label);
    outline0("LDY #$0");
    outline0("LDA (TMPPTR2),Y");
    outhead1("%sy:", label);
    outline0("STA (TMPPTR),y");
    outline0("INY");
    outline1("BNE %sy", label);
    outline0("INC TMPPTR+1");
    outline0("DEX");
    outline1("BNE %sx", label);

}

void cpu6502_flip( Environment * _environment, char * _source, char * _size, char * _destination ) {

    MAKE_LABEL

    outline1("LDA %s", _source);
    outline0("STA TMPPTR");
    outline1("LDA %s+1", _source);
    outline0("STA TMPPTR+1");

    outline1("LDA %s", _destination);
    outline0("STA TMPPTR2");
    outline1("LDA %s+1", _destination);
    outline0("STA TMPPTR2+1");

    outline1("LDA %s", _size);
    outline0("ADC TMPPTR2");
    outline0("STA TMPPTR2");
    outline0("DEC TMPPTR2");

    outline1("LDX %s", _size );
    outline0("LDY #$0");
    outhead1("%sx:", label);
    outline0("LDA (TMPPTR),Y");
    outline0("STA (TMPPTR2),Y");
    outline0("DEC TMPPTR2");
    outline0("INC TMPPTR");
    outline0("DEX");
    outline1("BNE %sx", label);

}

void cpu6502_bit_check( Environment * _environment, char * _value, int _position, char *_result ) {

    MAKE_LABEL

    outline1("LDA #$%2.2x", 1 << ( ( _position ) & 0x07 ) );
    outline0("STA TMPPTR" );
    switch( _position ) {
        case 31: case 30: case 29: case 28: case 27: case 26: case 25: case 24: 
            outline1("LDA %s+3", _value);
            break;
        case 23: case 22: case 21: case 20: case 19: case 18: case 17: case 16:
            outline1("LDA %s+2", _value);
            break;
        case 15: case 14: case 13: case 12: case 11: case 10: case 9: case 8:
            outline1("LDA %s+1", _value);
            break;
        case 7:  case 6:  case 5:  case 4:  case 3:  case 2:  case 1: case 0:
            outline1("LDA %s", _value);
            break;
    }
    outline0("AND TMPPTR" );
    outline1("BEQ %szero", label);
    outhead1("%sone:", label)
    outline0("LDA #$ff");
    outline1("JMP %send", label );
    outhead1("%szero:", label)
    outline0("LDA #$0");
    outhead1("%send:", label)
    outline1("STA %s", _result);

}

void cpu6502_bit_check_extended( Environment * _environment, char * _value, char * _position, char *_result ) {

    MAKE_LABEL

    outline1("LDA %s", _position );
    outline0("AND #$07" );
    outline1("BEQ %sl3", label );
    outline0("TAX" );
    outline0("LDA #$1" );
    outhead1("%sl1:", label );
    outline0("ASL A" );
    outline0("DEX" );
    outline1("BNE %sl1", label );
    outhead1("JMP %sl2", label );
    outhead1("%sl3:", label );
    outline0("LDA #$1" );
    outhead1("%sl2:", label );
    outline0("STA TMPPTR" );
    outline1("LDA %s", _position );
    outline0("CMP #8" );
    outline1("BCC %sb0", label );
    outline0("CMP #16" );
    outline1("BCC %sb1", label );
    outline0("CMP #24" );
    outline1("BCC %sb2", label );
    outline1("JMP %sb3", label );

    outhead1("%sb0:", label );
    outline1("LDA %s", _value );
    outline1("JMP %sbit", label );
    outhead1("%sb1:", label );
    outline1("LDA %s+1", _value );
    outline1("JMP %sbit", label );
    outhead1("%sb2:", label );
    outline1("LDA %s+2", _value );
    outline1("JMP %sbit", label );
    outhead1("%sb3:", label );
    outline1("LDA %s+3", _value );
    outline1("JMP %sbit", label );

    outhead1("%sbit:", label );
    outline0("AND TMPPTR" );
    outline1("BEQ %szero", label);
    outhead1("%sone:", label)
    outline0("LDA #$ff");
    outline1("JMP %send", label );
    outhead1("%szero:", label)
    outline0("LDA #$0");
    outhead1("%send:", label)
    outline1("STA %s", _result);

}

void cpu6502_number_to_string( Environment * _environment, char * _number, char * _string, char * _string_size, int _bits, int _signed ) {

    MAKE_LABEL

    deploy( numberToStringDeployed,"./ugbc/src/hw/6502/number_to_string.asm" );

    outline1("LDA %s", _string );
    outline0("STA TMPPTR");
    outline1("LDA %s+1", _string );
    outline0("STA TMPPTR+1");

    outline0("LDA #0");
    outline0("STA MATHPTR3");
    outline0("STA MATHPTR2");
    outline0("STA MATHPTR1");
    outline0("STA MATHPTR0");
    outline0("STA MATHPTR4");

    switch( _bits ) {
        case 32:
            outline1("LDA %s+3", _number );
            if ( _signed ) {
                outline0("AND #$80");
                outline0("STA MATHPTR4");
                outline1("LDA %s+3", _number );
            }
            outline0("STA MATHPTR3");
            outline1("LDA %s+2", _number );
            outline0("STA MATHPTR2");
        case 16:
            outline1("LDA %s+1", _number );
            if ( _signed && _bits == 16 ) {
                outline0("AND #$80");
                outline0("STA MATHPTR4");
                outline1("LDA %s+1", _number );
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

    deploy( bitsToStringDeployed,"./ugbc/src/hw/6502/bits_to_string.asm" );

    outline1("LDA #$%2.2x", _bits);
    outline0("STA BITSTOCONVERT");
    outline0("LDA #37");
    outline1("LDX #<%s", _number);
    outline1("LDY #>%s", _number);
    outline0("ORA #%10000000" );
    outline0("JSR binstr");

    outline0("STX TMPPTR");
    outline0("STY TMPPTR+1");
    outline1("STA %s", _string_size);
    outline0("TAY");
    outline1("LDA %s", _string);
    outline0("STA TMPPTR2");
    outline1("LDA %s+1", _string);
    outline0("STA TMPPTR2+1");
    outline1("%sLOOP:", label );
    outline0("LDA (TMPPTR),Y" );
    outline0("STA (TMPPTR2),Y");
    outline0("DEY");
    outline1("BPL %sLOOP", label );

}

void cpu6502_dsdefine( Environment * _environment, char * _string, char * _index ) {

    deploy( dstringDeployed,"./ugbc/src/hw/6502/dstring.asm" );

    outline1( "LDA #<%s", _string );
    outline0( "STA DSADDRLO" );
    outline1( "LDA #>%s", _string );
    outline0( "STA DSADDRHI" );
    outline0( "JSR DSDEFINE" );
    outline1( "STX %s", _index );
    
}

void cpu6502_dsalloc( Environment * _environment, char * _size, char * _index ) {

    deploy( dstringDeployed,"./ugbc/src/hw/6502/dstring.asm" );

    outline1( "LDA %s", _size );
    outline0( "STA DSSIZE" );
    outline0( "JSR DSALLOC" );
    outline1( "STX %s", _index );

}

void cpu6502_dsalloc_size( Environment * _environment, int _size, char * _index ) {

    deploy( dstringDeployed,"./ugbc/src/hw/6502/dstring.asm" );

    outline1( "LDA #$%2.2x", _size );
    outline0( "STA DSSIZE" );
    outline0( "JSR DSALLOC" );
    outline1( "STX %s", _index );

}

void cpu6502_dsfree( Environment * _environment, char * _index ) {

    deploy( dstringDeployed,"./ugbc/src/hw/6502/dstring.asm" );

    outline1( "LDX %s", _index );
    outline0( "JSR DSFREE" );

}

void cpu6502_dswrite( Environment * _environment, char * _index ) {

    deploy( dstringDeployed,"./ugbc/src/hw/6502/dstring.asm" );

    outline1( "LDX %s", _index );
    outline0( "JSR DSWRITE" );

}

void cpu6502_dsresize( Environment * _environment, char * _index, char * _resize ) {

    deploy( dstringDeployed,"./ugbc/src/hw/6502/dstring.asm" );

    outline1( "LDX %s", _index );
    outline1( "LDA %s", _resize );
    outline0( "STA DSSIZE" );
    outline0( "JSR DSRESIZE" );

}

void cpu6502_dsresize_size( Environment * _environment, char * _index, int _resize ) {

    deploy( dstringDeployed,"./ugbc/src/hw/6502/dstring.asm" );

    outline1( "LDX %s", _index );
    outline1( "LDA #$%2.2x", _resize );
    outline0( "STA DSSIZE" );
    outline0( "JSR DSRESIZE" );

}

void cpu6502_dsgc( Environment * _environment ) {

    deploy( dstringDeployed,"./ugbc/src/hw/6502/dstring.asm" );

    outline0( "JSR DSGC" );

}

void cpu6502_dsdescriptor( Environment * _environment, char * _index, char * _address, char * _size ) {

    deploy( dstringDeployed,"./ugbc/src/hw/6502/dstring.asm" );

    outline1( "LDX %s", _index );
    outline0( "JSR DSDESCRIPTOR" );
    outline0( "LDA DSADDRLO" );
    outline1( "STA %s", _address );
    outline0( "LDA DSADDRHI" );
    outline1( "STA %s+1", _address );
    outline0( "LDA DSSIZE" );
    outline1( "STA %s", _size );

}

void cpu6502_store_8bit_with_offset( Environment * _environment, char *_destination, int _value, int _offset ) {

    outline1("LDY $%2.2x", _offset);
    outline1("LDA #<%s", _destination);
    outline0("STA TMPPTR");
    outline1("LDA #>%s", _destination);
    outline0("STA TMPPTR+1");
    outline1("LDA $%2.2x", _value);
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
    outline1( "LDA %s+1", _source );
    outline0( "EOR #$FF" );
    if ( _destination ) {
        outline1( "STA %s+1", _destination );
    } else {
        outline1( "STA %s+1", _source );
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
        cpu6502_inc_32bit( _environment, _destination );
    } else {
        cpu6502_inc_32bit( _environment, _source );
    }

}

#endif