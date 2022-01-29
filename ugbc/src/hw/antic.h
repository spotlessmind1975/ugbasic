#ifndef __UGBC_ANTIC__
#define __UGBC_ANTIC__

/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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

#define DLI_COUNT           1024

/*

Display Lists
We introduced you briefly in chapter I to a graphics microprocessor called ANTIC that
is capable of displaying any of fourteen graphics modes. Since any screen actually 
consists of a collection or vertical stack of these individual graphics modes, ANTIC 
looks to a program called the display list to determine in which graphics mode it 
should display the screen data. The fact that there is something resembling a graphics 
display instruction set makes the computer extremely flexible. It becomes possible to 
display any collection of graphics modes from data in screen memory that can be stored 
virtually anywhere within the computer's RAM memory. This flexibility allows the user 
to mix graphics modes and even scroll the screen in any direction by altering the 
portion of screen memory displayed.

ANTIC, like most true microprocessors, has an instruction set that is used to write
the display list program. The display list specifies three things: where the screen 
data is located, what display modes to use to interpret the screen data, and what
special display options, if any, to implement.

Antic Instruction Set
ANTIC has a simple instruction set with only four basic instruction types. 
-there are map mode instructions, character mode instructions, 
 blank line instructions, and jump instructions. 
 
Map mode instructions instruct ANTIC to display a mode line as colored pixels, 
while character mode instructions tell ANTIC to display a mode line with character 
data either from its internal ROM or from your own custom designed set. 
Blank line instructions instruct ANTIC to display a number of horizontal scan 
lines with solid background color. Like GOTO statements in BASIC, jump instructions 
change the value in ANTIC's program counter so that it looks for its next opcode 
somewhere else.

Special Options or Modifiers
ANTIC also has a number of special options or modifiers to its map and character 
mode instructions. These are specified by setting one of four high bits in the 
instruction set. These options are load memory scan (LMS), display list interrupt 
(DLI), vertical scroll, and horizontal scroll.

The load memory scan option is the most frequently used option for it occurs at 
least once in every display list. It specifies where the screen data is stored 
in memory. Technically, only one of these instructions is actually needed in 
any series of display modes because screen memory is usually continuous. 
However, if memory isn't continuous, either within a particular display mode 
or at the boundry between different modes, an LMS instruction is needed 
each time a new section of memory is used. Another instance where an 
additional LMS instruction is required, is in ANTIC modes E and F (GRAPHICS 8) 
where continuous screen memory crosses a 4K boundary. The load memory scan 
option is invoked by adding a decimal 64 ($40) to the map or character in the
 mode instruction. This is equivalent to setting the sixth bit in the instruction. 
LMS instructions are three bytes long. The first byte is the opcode specifying 
the mode and the last two bytes contain the address of screen memory in low byte, 
high byte order.

The other three modifiers are sometimes used by Assembly language programmers 
to achieve special effects. Setting bit 7 or adding 128 to the opcode enables 
a display list interrupt. Execution of this instruction causes ANTIC to force the 
6502 to generate an interrupt. The interrupt service routine will be at the 
address pointed to in memory locations 512,513 decimal ($200, 201). 

Display list interrupts are often used to change the colors in the color 
registers over part of a screen or to change between character sets midway 
down the screen. We will discuss these uses in detail in chapter 
6 and 4, respectively.

Horizontal scrolling can be set up by adding 16 to the opcode or setting bit 4. 
Likewise, you enable vertical scrolling by adding 32 to the opcode or by 
setting bit five. These modifiers allow you to fine scroll the screen in 
either direction. Naturally if you are planning to scroll through memory 
by changing the start of screen memory, you will need to combine your 
scroll modifier with a load memory scan modifier. 
This technique will be shown in more detail in chapter 7.

Note:
1) Display List Interrupts can be enabled by adding 128 decimal, $80 Hex to above values
2) Since it is impractical to do horizontal scrolling without a LMS instruction values are not referenced.

load memory scan (LMS)

*/

#define     DLI_MODE( _list, _n )      \
                                    *_list++ = ((unsigned char)( /*0x30 |*/ _n ));

#define     DLI_MODE_VHSCROLL( _list, _n )      \
                                    *_list++ = ((unsigned char)( 0x30 | _n ));

#define     DLI_LMS( _list, _n, _addr )      \
                                    *_list++ = ((unsigned char)( /*0x30 |*/ 0x40 | _n )); \
                                    *_list++ = ((unsigned char)( _addr & 0xff )); \
                                    *_list++ = ((unsigned char)( _addr >> 8 ));

#define     DLI_LMS_VHSCROLL( _list, _n, _addr )      \
                                    *_list++ = ((unsigned char)( 0x30 | 0x40 | _n )); \
                                    *_list++ = ((unsigned char)( _addr & 0xff )); \
                                    *_list++ = ((unsigned char)( _addr >> 8 ));

#define     DLI_IRQ( _list, _n )    \
                                    *_list++ = ((unsigned char)( /*0x10 |*/ 0x80 | _n ));

#define     DLI_HSCROLL( _list )      \
                                    *_list++ = ((unsigned char)( 0x10 ));

#define     DLI_VSCROLL( _list )      \
                                    *_list++ = ((unsigned char)( 0x20 ));

/*

display list interrupt (DLI)
vertical scroll
horizontal scroll


Blanking Instructions

The blanking instructions generate a certain number of blank scan lines in
the color and luminance of the background or border color. From 1 to 8 blank scan lines 
can be generated by these opcodes. They are primarily used to correct the overscan on
a television set.

Instruction       Comment
Decimal  Hex                                  
  0      0        1 Blank Line
 16     10        2 Blank Lines
 32     20        3 Blank Lines
 48     30        4 Blank Lines
 64     40        5 Blank Lines
 80     50        6 Blank Lines
 96     60        7 Blank Lines
112     70        8 Blank Lines
 

*/

#define     DLI_BLANK( _list, _n )      \
                                    *_list++ = ((unsigned char)( ( (_n-1)<<4 ) ));
                                    

/*

Jump Instructions

There are two jump instructions. The first (JMP) tells ANTIC to continue looking for
instructions at a different address. It is equivalent to a GOTO in the display list. 
It is a three byte instruction with the address in low byte, high byte order following 
the opcode. Its only function is to provide a solution to the display list's 
inability to cross a 1K boundary. If for any reason your display list must cross 
a 1K boundary, then it must use a JMP instruction. Otherwise, don't worry about 
this instruction.

Instruction       Comment
Decimal  Hex                                  
  1      1        Jump to Location

*/

#define     DLI_JMP( list, addr )      \
                                    *list++ = ((unsigned char)(0x1)); \
                                    *list++ = ((unsigned char)(addr&0xff)); \
                                    *list++ = ((unsigned char)(addr>>8));
                                    

/*
The second jump instruction (JVB)-Jump and wait for Vertical Blank-is used in 
every display list. It is a three byte instruction; the address in low byte, 
high byte order follows the opcode. JVB tells ANTIC to jump to the start of the
display list and wait for a new screen refresh to begin. Surprisingly, this 
address doesn't have to be accurate, because the OS keeps track of the top of
the display list and passes it to ANTIC during the vertical blank. However, 
you should try to maintain the real address because if you use any SIO 
functions such as the disk drive or the printer, ANTIC won't be updated 
properly and the jump will be to the address that you specify in the instruction.

Instruction       Comment
Decimal  Hex                                  
 65     41        Jump & Wait for VBlank

*/

#define     DLI_JVB( list, addr )      \
                                    *list++ = ((unsigned char)(0x41)); \
                                    *list++ = ((unsigned char)(addr&0xff)); \
                                    *list++ = ((unsigned char)(addr>>8));

void antic_initialization( Environment * _environment );
void antic_finalization( Environment * _environment );

void antic_next_raster( Environment * _environment );
void antic_next_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );
void antic_raster_at( Environment * _environment, char * _label, char * _positionlo, char * _positionhi );

#endif