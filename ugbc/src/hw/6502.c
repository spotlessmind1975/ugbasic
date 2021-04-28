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

#ifdef __c64__

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
void cpu6502_fill( Environment * _environment, char * _address, char * _blocks, char * _pattern ) {

    MAKE_LABEL

    // Use the current bitmap address as starting address for filling routine.
    outline1("LDA %s", _address);
    outline0("STA $22");
    outline1("LDA %s+1", _address);
    outline0("STA $23");

    // Fill the bitmap with the given pattern.
    outline1("LDX %s", _blocks );
    outhead1("%sx:", label);
    outline0("LDY #0");
    outline1("LDA %s", _pattern );
    outhead1("%sy:", label);
    outline0("STA ($22),y");
    outline0("INY");
    outline1("BNE %sy", label);
    outline0("INC $23");
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
    outline1("LDA #%d", _positive );
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline1("LDA #%d", (1-_positive) );
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outhead1("%s2:", label);

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
void cpu6502_less_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal ) {

    MAKE_LABEL

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
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline0("LDA #1" );
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outhead1("%s2:", label);

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
void cpu6502_greater_than_8bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal ) {

    MAKE_LABEL

    outline1("LDA %s", _source);
    outline1("CMP %s", _destination );
    outline1("BCS %s", label);
    if ( _equal ) {
        outline1("BEQ %s", label);
    }
    outline0("LDA #0" );
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline0("LDA #1" );
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outhead1("%s2:", label);

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
void cpu6502_math_double_8bit( Environment * _environment, char *_source, char *_other ) {
    outline1("LDA %s", _source);
    outline0("ASL A");
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _source);
    }
}

/**
 * @brief <i>CPU 6502</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6502_math_div2_8bit( Environment * _environment, char *_source, int _steps ) {
    int i=0;
    outline1("LDA %s", _source);
    for(i=0; i<_steps; ++i ) {
        outline0("LSR A");
    }
    outline1("STA %s", _source);
}

/**
 * @brief <i>CPU 6502</i>: emit code to multiply two 8bit values in a 16 bit register
 * 
 * @param _environment Current calling environment
 * @param _source First value to multipy (8 bit)
 * @param _destination Second value to multipy (8 bit)
 * @param _other Destination address for result (16 bit)
 */
void cpu6502_math_mul_8bit_to_16bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    MAKE_LABEL

    outline0("LDA #0");
    outline0("LDX #8");
    outhead1("%s1:", label);
    outline1("LSR %s", _destination);
    outline1("BCC %s2", label);
    outline0("CLC");
    outline1("ADC %s", _source);
    outline1("%s2:", label);
    outline0("ROR A");
    outline1("ROR %s", _other);
    outline0("DEX" );
    outline1("BNE %s1", label);
    outline1("STA %s+1", _other );
}

/**
 * @brief <i>CPU 6502</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6502_math_div2_const_8bit( Environment * _environment, char *_source, int _steps ) {

    while( _steps ) {
        outline0("CLC");
        outline1("ROR %s", _source);
        --_steps;
    }

}

/**
 * @brief <i>CPU 6502</i>: emit code to double for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 */
void cpu6502_math_mul2_const_8bit( Environment * _environment, char *_source, int _steps ) {

    while( _steps ) {
        outline0("CLC");
        outline1("ASL %s", _source);
        --_steps;
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
    outline1("LDA #%d", _positive );
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline1("LDA #%d", (1-_positive) );
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outhead1("%s2:", label);
    
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
void cpu6502_less_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal ) {

    MAKE_LABEL

    outline1("LDA %s+1", _source);
    outline1("CMP %s+1", _destination );
    outline1("BCC %s", label);
    outline1("LDA %s", _source);
    outline1("CMP %s", _destination );
    if ( _equal ) {
        outline1("BEQ %s", label);
    }
    outline0("LDA #0" );
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline0("LDA #1" );
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outhead1("%s2:", label);

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
void cpu6502_greater_than_16bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal ) {

    MAKE_LABEL

    outline1("LDA %s+1", _source);
    outline1("CMP %s+1", _destination );
    if ( ! _equal ) {
        outline1("BEQ %sfalse", label);
    }
    outline1("LDA %s", _source);
    outline1("CMP %s", _destination );
    if ( ! _equal ) {
        outline1("BEQ %sfalse", label);
    }
    outline1("BCS %strue", label);
    if ( _equal ) {
        outline1("BEQ %s", label);
    }
    outhead1("%sfalse:", label);
    outline0("LDA #0" );
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outline1("JMP %sfinal", label);
    outhead1("%strue:", label);
    outline0("LDA #1" );
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outhead1("%sfinal:", label);

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
 * @brief <i>CPU 6502</i>: emit code to double a 16 bit value
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result (if _other is NULL)
 * @param _other Destination address for result
 */
void cpu6502_math_double_16bit( Environment * _environment, char *_source, char *_other ) {
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
void cpu6502_math_mul_16bit_to_32bit( Environment * _environment, char *_source, char *_destination,  char *_other ) {

    MAKE_LABEL

    outline1("LDA %s", _source );
    outline0("STA $F7");
    outline1("LDA %s+1", _source );
    outline0("STA $F8");
    outline1("LDA %s", _destination );
    outline0("STA $F9");
    outline1("LDA %s+1", _destination );
    outline0("STA $FA");

 	outline0("LDA #$00");
 	outline0("STA $FB");
 	outline0("STA $FB+1");
 	outline0("STA $FB+2");
 	outline0("STA $FB+3");
 	outline0("LDX #$10");

 	outhead1("%s:", label);
 	outline0("LSR $F8");
 	outline0("ROR $F7");
 	outline1("BCC %s2", label);
    outline0("LDA $FB+2");
    outline0("CLC");
    outline0("ADC $F9");
    outline0("STA $FB+2");
    outline0("LDA $FB+3");
    outline0("ADC $FA");

 	outhead1("%s2:", label);
    outline0("ROR");
    outline0("STA $FB+3");
    outline0("ROR $FB+2");
    outline0("ROR $FB+1");
    outline0("ROR $FB");
    outline0("DEX");
    outline1("BNE %s", label);

    outline0("LDA $FB");
    outline1("STA %s", _other );
    outline0("LDA $FC");
    outline1("STA %s+1", _other );
    outline0("LDA $FD");
    outline1("STA %s+2", _other );
    outline0("LDA $FE");
    outline1("STA %s+3", _other );

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
void cpu6502_math_div2_const_16bit( Environment * _environment, char *_source, int _steps ) {

    while( _steps ) {
        outline0("CLC");
        outline1("LSR %s+1", _source);
        outline1("ROR %s", _source);
        --_steps;
    }

}

/**
 * @brief <i>CPU 6502</i>: emit code to halves for several times a 8 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to halves and destination for result
 * @param _steps Times to halves
 */
void cpu6502_math_mul2_const_16bit( Environment * _environment, char *_source, int _steps ) {

    while( _steps ) {
        outline0("CLC");
        outline1("ASL %s", _source);
        outline1("ROL %s+1", _source);
        --_steps;
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
    outline1("LDA #%d", _positive);
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline1("LDA #%d", (1-_positive));
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outhead1("%s2:", label);
    
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
void cpu6502_less_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal ) {

    MAKE_LABEL

    outline1("LDA %s+3", _source);
    outline1("CMP %s+3", _destination );
    outline1("BCC %s", label);
    outline1("LDA %s+2", _source);
    outline1("CMP %s+2", _destination );
    outline1("BCC %s", label);
    outline1("LDA %s+1", _source);
    outline1("CMP %s+1", _destination );
    outline1("BCC %s", label);
    outline1("LDA %s", _source);
    outline1("CMP %s", _destination );
    if ( _equal ) {
        outline1("BEQ %s", label);
    }
    outline0("LDA #0" );
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline0("LDA #1" );
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outhead1("%s2:", label);

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
void cpu6502_greater_than_32bit( Environment * _environment, char *_source, char *_destination,  char *_other, int _equal ) {

    MAKE_LABEL

    outline1("LDA %s+3", _source);
    outline1("CMP %s+3", _destination );
    outline1("BCS %s", label);
    outline1("LDA %s+2", _source);
    outline1("CMP %s+2", _destination );
    outline1("BCS %s", label);
    outline1("LDA %s+1", _source);
    outline1("CMP %s+1", _destination );
    outline1("BCS %s", label);
    outline1("LDA %s", _source);
    outline1("CMP %s", _destination );
    outline1("BCS %s", label);
    if ( _equal ) {
        outline1("BEQ %s", label);
    }
    outline0("LDA #0" );
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline0("LDA #1" );
    if ( _other ) {
        outline1("STA %s", _other);
    } else {
        outline1("STA %s", _destination);
    }
    outhead1("%s2:", label);

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
void cpu6502_math_double_32bit( Environment * _environment, char *_source, char *_other ) {
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
void cpu6502_math_div2_const_32bit( Environment * _environment, char *_source, int _steps ) {

    while( _steps ) {
        outline0("CLC");
        outline1("LSR %s+3", _source);
        outline1("ROR %s+2", _source);
        outline1("ROR %s+1", _source);
        outline1("ROR %s", _source);
        --_steps;
    }

}

/**
 * @brief <i>CPU 6502</i>: emit code to double for several times a 32 bit value 
 * 
 * @param _environment Current calling environment
 * @param _source Value to double and destination for result
 * @param _steps Times to double
 */
void cpu6502_math_mul2_const_32bit( Environment * _environment, char *_source, int _steps ) {

    while( _steps ) {
        outline0("CLC");
        outline1("ASL %s", _source);
        outline1("ROL %s+1", _source);
        outline1("ROL %s+2", _source);
        outline1("ROL %s+3", _source);
        --_steps;
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

    outline0("INC SP" );
    outline0("INC SP" );

}

void cpu6502_halt( Environment * _environment ) {

    MAKE_LABEL

    outhead1("%s:", label );
    outline1("JMP %s", label);

}

void cpu6502_random( Environment * _environment, char * _seed, char * _entropy ) {

    MAKE_LABEL

    outhead1("%s:", label);
    outline1("ASL %s", _seed);
    outline1("ROL %s+1", _seed);
    outline1("ROL %s+2", _seed);
    outline1("ROL %s+3", _seed);
    outline1("BCC %s2", label);
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
    outhead1("%s2:", label);

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
    outline0("LDA #1");
    outline1("STA %s", _result);
    outline1("JMP %s2", label);
    outhead1("%s:", label);
    outline0("LDA #0");
    outline1("STA %s", _result);
    outhead1("%s2:", label);

}

void cpu6502_logical_or_8bit( Environment * _environment, char * _left, char * _right, char * _result ) {

    MAKE_LABEL

    outline1("LDA %s", _left );
    outhead1("BNE %s1", label );
    outline1("LDA %s", _right );
    outline1("BNE %s1", label);
    outline1("JMP %s0", label);
    outhead1("%s1:", label);
    outline0("LDA #1");
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
    outline0("EOR $FF" );
    outline1("STA %s", _result );

}

#endif