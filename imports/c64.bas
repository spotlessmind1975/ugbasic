' /*****************************************************************************
'  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
'  *****************************************************************************
'  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
'  *
'  * Licensed under the Apache License, Version 2.0 (the "License");
'  * you may not use this file except in compliance with the License.
'  * You may obtain a copy of the License at
'  *
'  * http://www.apache.org/licenses/LICENSE-2.0
'  *
'  * Unless required by applicable law or agreed to in writing, software
'  * distributed under the License is distributed on an "AS IS" BASIS,
'  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
'  * See the License for the specific language governing permissions and
'  * limitations under the License.
'  *----------------------------------------------------------------------------
'  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
'  * (la "Licenza"); è proibito usare questo file se non in conformità alla
'  * Licenza. Una copia della Licenza è disponibile all'indirizzo:
'  *
'  * http://www.apache.org/licenses/LICENSE-2.0
'  *
'  * Se non richiesto dalla legislazione vigente o concordato per iscritto,
'  * il software distribuito nei termini della Licenza è distribuito
'  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
'  * implicite. Consultare la Licenza per il testo specifico che regola le
'  * autorizzazioni e le limitazioni previste dalla medesima.
'  ****************************************************************************/
'  ****************************************************************************
'  *** IMPORT DECLARES FOR TARGET c64 (Commodore 64)
'  ****************************************************************************
'  ** Informations from: https://www.pagetable.com/c64ref/kernal/
'  ****************************************************************************
'  * Tested with ugBASIC v1.14.1
'  ****************************************************************************

' ----------------------------------------------------------------------------
' CINT - Initialize screen editor & 6567 video chip
'
' This routine sets up the 6567 video controller chip in the Commodore 64 
' for normal operation. The KERNAL screen editor is also initialized. 
' This routine should be called by a Commodore 64 program cartridge.
' [NOT WORKING]
DECLARE SYSTEM PROC cint AT $FF81 ON C64

' ----------------------------------------------------------------------------
' IOINIT - Initialize I/O devices
'
' This routine initializes all input/output devices and routines. It is 
' normally called as part of the initialization procedure of a Commodore 64 
' program cartridge.
DECLARE SYSTEM PROC ioinit AT $FF84 ON C64

' ----------------------------------------------------------------------------
' RAMTAS - Perform RAM test
'
' This routine is used to test RAM and set the top and bottom of memory 
' pointers accordingly. It also clears locations $00 to $0101 and $0200 to 
' $03FF. It also allocates the cassette buffer, and sets the screen base to 
' $0400. Normally, this routine is called as part of the initialization 
' process of a Commodore 64 program cartridge.
DECLARE SYSTEM PROC ramtas AT $FF87 ON C64

' ----------------------------------------------------------------------------
' RESTOR - Restore default system and interrupt vectors
'
' This routine restores the default values of all system vectors used in 
' KERNAL and BASIC routines and interrupts. (See the Memory Map for the 
' default vector contents). The KERNAL VECTOR routine is used to read and 
' alter individual system vectors.
DECLARE SYSTEM PROC restor AT $FF8A ON C64

' ----------------------------------------------------------------------------
' VECTOR - Manage RAM vectors
'
' This routine manages all system vector jump addresses stored in RAM. 
' Calling this routine with the the accumulator carry bit set stores the 
' current contents of the RAM vectors in a list pointed to by the X and Y 
' registers. When this routine is called with the carry clear, the user list 
' pointed to by the X and Y registers is transferred to the system RAM vectors. 
' The RAM vectors are listed in the memory map.
' 
' NOTE: This routine requires caution in its use. The best way to use it is 
' to first read the entire vector contents into the user area, alter the desired 
' vectors, and then copy the contents back to the system vectors.
'
' direction = 1 => READ THE SYSTEM RAM VECTORS
' direction = 0 => WRITE THE SYSTEM RAM VECTORS
' POSITIVE CONST vectorWrite = 0
' POSITIVE CONST vectorRead = 1
DECLARE SYSTEM PROC vectorRead AT $FF8D( buffer AS ADDRESS ON REG(YX), #1 ON REG(CARRY) ) ON C64
DECLARE SYSTEM PROC vectorWrite AT $FF8D( buffer AS ADDRESS ON REG(YX), #0 ON REG(CARRY) ) ON C64

' ----------------------------------------------------------------------------
' SETMSG - Control system message output
'
' This routine controls the printing of error and control messages by the 
' KERNAL. Either print error messages or print control messages can be 
' selected by setting the accumulator when the routine is called. 
'
' FILE NOT FOUND is an example of an error message. 
' PRESS PLAY ON CASSETTE is an example of a control message.
'
' Bits 6 and 7 of this value determine where the message will come from. 
' If bit 7 is 1, one of the error messages from the KERNAL is printed. 
' If bit 6 is set, control messages are printed.
POSITIVE CONST setmsgError = $80
POSITIVE CONST setmsgControl = $40
DECLARE SYSTEM PROC setmsg AT $FF90( bitmask AS BYTE ON REG(A) ) ON C64

' ----------------------------------------------------------------------------
' SECOND - Send secondary address for LISTEN
'
' This routine is used to send a secondary address to an I/O device after 
' a call to the LISTEN routine is made, and the device is commanded to 
' LISTEN. The routine canNOT be used to send a secondary address after a 
' call to the TALK routine.
'
' A secondary address is usually used to give setup information to a device 
' before I/O operations begin. When a secondary address is to be sent to a 
' device on the serial bus, the address must first be ORed with $60.
DECLARE SYSTEM PROC second AT $FF93( address AS BYTE ON REG(A) ) ON C64

' ----------------------------------------------------------------------------
' TKSA - Send a secondary address to a device commanded to TALK
'
' This routine transmits a secondary address on the serial bus for a TALK 
' device. This routine must be called with a number between 0 and 31 in the 
' accumulator. The routine sends this number as a secondary address command 
' over the serial bus. This routine can only be called after a call to the 
' TALK routine. It will not work after a LISTEN.
DECLARE SYSTEM PROC tksa AT $FF96( command AS BYTE ON REG(A) ) ON C64

' ----------------------------------------------------------------------------
' MEMTOP - Set the top of RAM
'
' This routine is used to set the top of RAM. When this routine is called 
' with the carry bit of the accumulator set, the pointer to the top of RAM 
' will be loaded into the X and Y registers. When this routine is called with 
' the accumulator carry bit clear, the contents of the X and Y registers are 
' loaded in the top of memory pointer, changing the top of memory.
' POSITIVE CONST memtopRead = 1
' POSITIVE CONST memtopWrite = 0
DECLARE SYSTEM PROC memtopWrite AT $FF99( address AS ADDRESS ON REG(YX), #0 ON REG(CARRY) ) ON C64
DECLARE SYSTEM FUNCTION memtopRead AT $FF99( #1 ON REG(CARRY) ) RETURN REG(YX) AS ADDRESS ON C64

' ----------------------------------------------------------------------------
' MEMBOT - Set bottom of memory
'
' This routine is used to set the bottom of the memory. If the accumulator 
' carry bit is set when this routine is called, a pointer to the lowest byte 
' of RAM is returned in the X and Y registers. On the unexpanded Commodore 64 
' the initial value of this pointer is $0800 (2048 in decimal). If the 
' accumulator carry bit is clear (-O) when this routine is called, the values 
' of the X and Y registers are transferred to the low and high bytes, 
' respectively, of the pointer to the beginning of RAM.
' POSITIVE CONST membotRead = 1
' POSITIVE CONST membotWrite = 0
DECLARE SYSTEM PROC membotWrite AT $FF99( address AS ADDRESS ON REG(YX), #0 ON REG(CARRY) ) ON C64
DECLARE SYSTEM FUNCTION membotRead AT $FF99( #1 ON REG(CARRY) ) RETURN REG(YX) AS ADDRESS ON C64

' ----------------------------------------------------------------------------
' SCNKEY - Scan the keyboard
'
' This routine scans the Commodore 64 keyboard and checks for pressed keys. 
' It is the same routine called by the interrupt handler. If a key is down, 
' its ASCII value is placed in the keyboard queue. This routine is called only
' if the normal IRQ interrupt is bypassed.
DECLARE SYSTEM PROC scnkey AT $FF9F ON C64

' ----------------------------------------------------------------------------
' SETTMO - Set IEEE bus card timeout flag
'
' NOTE: This routine is used ONLY with an IEEE add-on card!
' Description: This routine sets the timeout flag for the IEEE bus. When the 
' timeout flag is set, the Commodore 64 will wait for a device on the IEEE 
' port for 64 milliseconds. If the device does not respond to the Commodore 
' 64's Data Address Valid (DAV) signal within that time the Commodore 64 
' will recognize an error condition and leave the handshake sequence. 
' When this routine is called when the accumulator contains a 0 in bit 7, 
' timeouts are enabled. A 1 in bit 7 will disable the timeouts.
'
' NOTE: The Commodore 64 uses the timeout feature to communicate that a 
' disk file is not found on an attempt to OPEN a file only with an 
' IEEE card.
POSITIVE CONST settmoDisable = 0
POSITIVE CONST settmoEnable = $80
DECLARE SYSTEM PROC settmo AT $FFA2( enable AS BYTE ON REG(A) ) ON C64
DECLARE SYSTEM PROC settmoEnable AT $FFA2( #settmoEnable ON REG(A) ) ON C64
DECLARE SYSTEM PROC settmoDisable AT $FFA2( #settmoDisable ON REG(A) ) ON C64

' ----------------------------------------------------------------------------
' ACPTR - Get data from the serial bus
'
' This is the routine to use when you want to get information from a device 
' on the serial bus, like a disk. This routine gets a byte of data off the 
' serial bus using full handshaking. The data is returned in the accumulator. 
' To prepare for this routine the TALK routine must be called first to command
' the device on the serial bus to send data through the bus. If the input device
' needs a secondary command, it must be sent by using the TKSA KERNAL routine 
' before calling this routine. Errors are returned in the status word. The 
' READST routine is used to read the status word.
DECLARE SYSTEM FUNCTION acptr AT $FFA5 RETURN REG(A) AS BYTE ON C64

' ----------------------------------------------------------------------------
' CIOUT - Transmit a byte over the serial bus
'
' Description: This routine is used to send information to devices on the 
' serial bus. A call to this routine will put a data byte onto the serial 
' bus using full serial handshaking. Before this routine is called, the 
' LISTEN KERNAL routine must be used to command a device on the serial bus 
' to get ready to receive data. (If a device needs a secondary address, 
' it must also be sent by using the SECOND KERNAL routine.) The accumulator 
' is loaded with a byte to handshake as data on the serial bus. A device 
' must be listening or the status word will return a timeout. This 
' routine always buffers one character. (The routine holds the previous 
' character to be sent back.) So when a call to the KERNAL UNLSN routine 
' is made to end the data transmission, the buffered character is sent 
' with an End Or Identify (EOI) set. Then the UNLSN command is sent to 
' the device.
DECLARE SYSTEM PROC ciout AT $FFA8 ( data AS BYTE ON REG(A) ) ON C64

' ----------------------------------------------------------------------------
' UNTALK - Send an UNTALK command
'
' This routine transmits an UNTALK command on the serial bus. All devices 
' previously set to TALK will stop sending data when this command is received.
DECLARE SYSTEM PROC untalk AT $FFAB ON C64

' ----------------------------------------------------------------------------
' UNLSN - Send an UNLISTEN command
'
' This routine commands all devices on the serial bus to stop receiving 
' data from the Commodore 64 (i.e., UNLISTEN). Calling this routine results 
' in an UNLISTEN command being transmitted on the serial bus. Only devices 
' previously commanded to listen are affected. This routine is normally used
' after the Commodore 64 is finished sending data to external devices. 
' Sending the UNLISTEN commands the listening devices to get off the serial 
' bus so it can be used for other purposes.
DECLARE SYSTEM PROC unlsn AT $FFAE ON C64

' ----------------------------------------------------------------------------
' LISTEN - Command a device on the serial bus to listen
'
' This routine will command a device on the serial bus to receive data. 
' The accumulator must be loaded with a device number between 0 and 31 before
' calling the routine. LISTEN will OR the number bit by bit to convert to a 
' listen address, then transmits this data as a command on the serial bus. 
' The specified device will then go into listen mode, and be ready to accept 
' information.
DECLARE SYSTEM PROC listen AT $FFB1 ( device AS BYTE ON REG(A) ) ON C64

' ----------------------------------------------------------------------------
' TALK - Command a device on the serial bus to TALK
'
' To use this routine the accumulator must first be loaded with a device 
' number between 0 and 31. When called, this routine then ORs bit by bit to 
' convert this device number to a talk address. Then this data is transmitted 
' as a command on the serial bus.
DECLARE SYSTEM PROC talk AT $FFB4 ( device AS BYTE ON REG(A) ) ON C64

' ----------------------------------------------------------------------------
' READST - Read status word
'
' This routine returns the current status of the I/O devices in the 
' accumulator. The routine is usually called after new communication to an 
' I/O device. The routine gives you information about device status, or errors 
' that have occurred during the I/O operation.
'
' The bits returned in the accumulator contain the following information: 
'  (see table below)
'
' ST BIT ST   Cassette Read	 Serial Bus R/W	    Tape Verify + Load
'    0    1                  time out write	
'    1    2                  time out read	
'    2	  4	  short block		                short block
'    3	  8	  long block		                long block
'    4	 16	  unrecoverable read error		    any mismatch
'    5   32   checksum error		            checksum error
'    6   64   end of file    EOI line	
'    7	-128  end of tape	 device not present	end of tape
POSITIVE CONST readstTimeoutWrite = $01
POSITIVE CONST readstTimeoutRead = $02
POSITIVE CONST readstShortBlock = $04
POSITIVE CONST readstLongBlock = $08
POSITIVE CONST readstUnrecoverableError = $10
POSITIVE CONST readstChecksumError = $20
POSITIVE CONST readstEndOfFile = $40
POSITIVE CONST readstEndOfTape = $80
DECLARE SYSTEM FUNCTION readst AT $FFB7 RETURN REG(A) AS BYTE ON C64

' ----------------------------------------------------------------------------
' SETLFS - Set up a logical file
'
' This routine sets the logical file number, device address, and secondary 
' address (command number) for other KERNAL routines.
'
' The logical file number is used by the system as a key to the file table 
' created by the OPEN file routine. Device addresses can range from 0 to 31. 
' The following codes are used by the Commodore 64 to stand for the CBM devices 
' listed below:
'
' ADDRESS	DEVICE
' 0         Keyboard
' 1         Datassette™
' 2         RS-232C device
' 3         CRT display
' 4         Serial bus printer
' 8         CBM serial bus disk drive
' Device numbers 4 or greater automatically refer to devices on the serial bus.
'
' A command to the device is sent as a secondary address on the serial bus 
' after the device number is sent during the serial attention handshaking 
' sequence. If no secondary address is to be sent, the Y index register 
' should be set to 255.
POSITIVE CONST setlfsKeyboard = 0
POSITIVE CONST setlfsDatassette = 1
POSITIVE CONST setlfsRs232 = 2
POSITIVE CONST setlfsCRT = 3
POSITIVE CONST setlfsPrinter = 4
POSITIVE CONST setlfsDiskDrive = 8
POSITIVE CONST setlfsNoSecondaryAddress = 255
DECLARE SYSTEM PROC setlfs AT $FFBA ( address AS BYTE ON REG(A), device AS BYTE ON REG(X), command AS BYTE ON REG(Y) ) ON C64

' ----------------------------------------------------------------------------
' SETNAM - Set file name
' 
' This routine is used to set up the file name for the OPEN, SAVE, or LOAD 
' routines. The accumulator must be loaded with the length of the file name. 
' The X and Y registers must be loaded with the address of the file name, 
' in standard 6502 low-byte/high-byte format. The address can be any valid 
' memory address in the system where a string of characters for the file name 
' is stored. If no file name is desired, the accumulator must be set to 0, 
' representing a zero file length. The X and Y registers can be set to any 
' memory address in that case.
DECLARE SYSTEM PROC setnam AT $FFBD ( len AS BYTE ON REG(A), filename AS ADDRESS ON REG(YX) ) ON C64

' ----------------------------------------------------------------------------
' OPEN - Open a logical file
'
' This routine is used to OPEN a logical file. Once the logical file is set 
' up, it can be used for input/output operations. Most of the I/O KERNAL 
' routines call on this routine to create the logical files to operate on.
' No arguments need to be set up to use this routine, but both the SETLFS 
' and SETNAM KERNAL routines must be called before using this routine.
DECLARE SYSTEM PROC open AT $FFC0 ON C64

' ----------------------------------------------------------------------------
' CLOSE - Close a logical file
'
' This routine is used to close a logical file after all I/O operations have 
' been completed on that file. This routine is called after the accumulator 
' is loaded with the logical file number to be closed (the same number used 
' when the file was opened using the OPEN routine).
DECLARE SYSTEM PROC close AT $FFC3 ( file AS BYTE ON REG(A) ) ON C64

' ----------------------------------------------------------------------------
' CHKIN - Open a channel for input
'
' Any logical file that has already been opened by the KERNAL OPEN routine can
' be defined as an input channel by this routine. Naturally, the device on 
' the channel must be an input device. Otherwise an error will occur, and the
' routine will abort.
'
' If you are getting data from anywhere other than the keyboard, this 
' routine must be called before using either the CHRIN or the GETIN KERNAL 
' routines for data input. If you want to use the input from the keyboard, 
' and no other input channels are opened, then the calls to this routine, 
' and to the OPEN routine are not needed.
'
' When this routine is used with a device on the serial bus, it automatically
' sends the talk address (and the secondary address if one was specified by 
' the OPEN routine) over the bus.
'
DECLARE SYSTEM PROC chkin AT $FFC6 ( file AS BYTE ON REG(X) ) ON C64

' ----------------------------------------------------------------------------
' CHKOUT - Open a channel for output
'
' Any logical file number that has been created by the KERNAL routine OPEN 
' can be defined as an output channel. Of course, the device you intend 
' opening a channel to must be an output device. Otherwise an error will 
' occur, and the routine will be aborted.
'
' This routine must be called before any data is sent to any output device 
' unless you want to use the Commodore 64 screen as your output device.
' If screen output is desired, and there are no other output channels 
' already defined, then calls to this routine, and to the OPEN routine 
' are not needed.
'
' When used to open a channel to a device on the serial bus, this routine 
' will automatically send the LISTEN address specified by the OPEN routine 
' (and a secondary address if there was one).
DECLARE SYSTEM PROC chkout AT $FFC9 ( file AS BYTE ON REG(X) ) ON C64

' ----------------------------------------------------------------------------
' CLRCHN - Clear I/O channels
'
' This routine is called to clear all open channels and restore the I/O 
' channels to their original default values. It is usually called after 
' opening other I/O channels (like a tape or disk drive) and using them 
' for input/output operations. The default input device is 0 (keyboard). 
' The default output device is 3 (the Commodore 64 screen).
'
' If one of the channels to be closed is to the serial port, an UNTALK signal
' is sent first to clear the input channel or an UNLISTEN is sent to clear 
' the output channel. By not calling this routine (and leaving listener(s) 
' active on the serial bus) several devices can receive the same data from
' the Commodore 64 at the same time. One way to take advantage of this 
' would be to command the printer to TALK and the disk to LISTEN. 
' This would allow direct printing of a disk file.
'
' This routine is automatically called when the KERNAL CLALL 
' routine is executed.
DECLARE SYSTEM PROC clrchn AT $FFCC ON C64

' ----------------------------------------------------------------------------
' CHRIN - Get a character from the input channel
'
' This routine gets a byte of data from a channel already set up as the 
' input channel by the KERNAL routine CHKIN. If the CHKIN has NOT been used 
' to define another input channel, then all your data is expected from the
' keyboard. The data byte is returned in the accumulator. The channel remains
' open after the call.
'
' Input from the keyboard is handled in a special way. First, the cursor is
' turned on, and blinks until a carriage return is typed on the keyboard. 
' All characters on the line can be retrieved one at a time by calling this 
' routine once for each character. When the carriage return is retrieved, the
' entire line has been processed. The next time this routine is called, the 
' whole process begins again, i.e., by flashing the cursor.
DECLARE SYSTEM FUNCTION chrin AT $FFCF RETURN REG(A) AS BYTE ON C64

' ----------------------------------------------------------------------------
' CHROUT - Output a character
'
' This routine outputs a character to an already opened channel. Use the 
' KERNAL OPEN and CHKOUT routines to set up the output channel before calling
' this routine, If this call is omitted, data is sent to the default output 
' device (number 3, the screen). The data byte to be output is loaded into 
' the accumulator, and this routine is called. The data is then sent to the 
' specified output device. The channel is left open after the call.
'
' NOTE: Care must be taken when using this routine to send data to a specific
' serial device since data will be sent to all open output channels on the 
' bus. Unless this is desired, all open output channels on the serial bus 
' other than the intended destination channel must be closed by a call to
' the KERNAL CLRCHN routine.
DECLARE SYSTEM PROC chrout AT $FFD2( char AS BYTE ON REG(A) ) ON C64

' ----------------------------------------------------------------------------
' LOAD - Load RAM from device
' 
' This routine LOADs data bytes from any input device directly into the memory
' of the Commodore 64. It can also be used for a verify operation, comparing 
' data from a device with the data already in memory, while leaving the data 
' stored in RAM unchanged.
'
' The accumulator (.A) must be set to 0 for a LOAD operation, or 1 for a 
' verify, If the input device is OPENed with a secondary address (SA) 
' of 0 the header information from the device is ignored. In this case, 
' the X and Y registers must contain the starting address for the load. 
' If the device is addressed with a secondary address of 1, then the data 
' is loaded into memory starting at the location specified by the header. 
' This routine returns the address of the highest RAM location loaded.
'
' Before this routine can be called, the KERNAL SETLFS, and SETNAM routines
' must be called.
' 
' NOTE: You can NOT LOAD from the keyboard (0), RS-232 (2), or the 
' screen (3).
POSITIVE CONST loadLoad = 0
POSITIVE CONST loadVerify = 1
DECLARE SYSTEM PROC load AT $FFD5( mode AS BYTE ON REG(A), address AS ADDRESS ON REG(YX) ) ON C64

' ----------------------------------------------------------------------------
' SAVE - Save memory to a device
'
' This routine saves a section of memory. Memory is saved from an indirect 
' address on page 0 specified by the accumulator to the address stored in 
' the X and Y registers. It is then sent to a logical file on an input/output
' device. The SETLFS and SETNAM routines must be used before calling this 
' routine. However, a file name is not required to SAVE to device 1 
' (the Datassette™ recorder). Any attempt to save to other devices without
' using a file name results in an error.
'
' NOTE: Device 0 (the keyboard), device 2 (RS-232), and device 3 (the screen)
' cannot be SAVEd to. If the attempt is made, an error occurs, and the SAVE
' is stopped.
DECLARE SYSTEM PROC save AT $FFD8( startAddress AS ADDRESS ON REG(34,35), endAddress AS ADDRESS ON REG(YX), #34 ON REG(A) ) ON C64

' ----------------------------------------------------------------------------
' SETTIM - Set the system clock
'
' A system clock is maintained by an interrupt routine that updates the clock
' every 1/60th of a second (one "jiffy"). The clock is three bytes long, which
' gives it the capability to count up to 5,184,000 jiffies (24 hours). At that
' point the clock resets to zero. Before calling this routine to set the 
' clock, the accumulator must contain the most significant byte, the X index
' register the next most significant byte, and the Y index register the least
' significant byte of the initial time setting (in jiffies).
DECLARE SYSTEM PROC settim AT $FFDB( jiffies AS DWORD ON REG(AXY) ) ON C64

' ----------------------------------------------------------------------------
' RDTIM - Read system clock
'
' This routine is used to read the system clock. The clock's resolution is a
' 60th of a second. Three bytes are returned by the routine. The accumulator 
' contains the most significant byte, the X index register contains the next 
' most significant byte, and the Y index register contains the least 
' significant byte.
DECLARE SYSTEM FUNCTION rdtim AT $FFDE RETURN REG(AXY) AS DWORD ON C64

' ----------------------------------------------------------------------------
' STOP - Check if key is pressed
'
' If the key on the keyboard was pressed during a UDTIM call, this call 
' returns the Z flag set. In addition, the channels will be reset to default
' values. All other flags remain unchanged. If the key is not pressed then the
' accumulator will contain a byte representing the lost row of the keyboard 
' scan. The user can also check for certain other keys this way.
DECLARE SYSTEM FUNCTION stop AT $FFE1 RETURN REG(ZERO) AS BYTE ON C64

' ----------------------------------------------------------------------------
' GETIN - Get a character
'
' If the channel is the keyboard, this subroutine removes one character from 
' the keyboard queue and returns it as an ASCII value in the accumulator.
' If the queue is empty, the value returned in the accumulator will be zero.
' Characters are put into the queue automatically by an interrupt driven 
' keyboard scan routine which calls the SCNKEY routine. The keyboard buffer 
' can hold up to ten characters. After the buffer is filled, additional 
' characters are ignored until at least one character has been removed 
' from the queue. If the channel is RS-232, then only the A register is used
' and a single character is returned. See READST to check validity. If the 
' channel is serial, cassette, or screen, call BASIN routine.
DECLARE SYSTEM FUNCTION getin AT $FFE4 RETURN REG(A) AS BYTE ON C64

' ----------------------------------------------------------------------------
' CLALL - Close all files
'
' This routine closes all open files. When this routine is called, the 
' pointers into the open file table are reset, closing all files. Also, the 
' CLRCHN routine is automatically called to reset the I/O channels.
DECLARE SYSTEM PROC clall AT $FFE7 ON C64

' ----------------------------------------------------------------------------
' UDTIM - Update the system clock
'
' This routine updates the system clock. Normally this routine is called by 
' the normal KERNAL interrupt routine every 1/60th of a second. If the user 
' program processes its own interrupts this routine must be called to update 
' the time. In addition, the <STOP> key routine must be called, if the <STOP>
' key is to remain functional.
DECLARE SYSTEM PROC udtim AT $FFEA ON C64

' ----------------------------------------------------------------------------
' SCREEN - Return screen format
'
' This routine returns the format of the screen, e.g., 40 columns in X and 25
' lines in Y. The routine can be used to determine what machine a program is 
' running on. This function has been implemented on the Commodore 64 to help 
' upward compatibility of your programs.
DECLARE SYSTEM FUNCTION screenX AT $FFED RETURN REG(X) AS BYTE ON C64
DECLARE SYSTEM FUNCTION screenY AT $FFED RETURN REG(Y) AS BYTE ON C64

' ----------------------------------------------------------------------------
' PLOT - Set cursor location
'
' A call to this routine with the accumulator carry flag set loads the 
' current position of the cursor on the screen (in X,Y coordinates) into the
' Y and X registers. Y is the column number of the cursor location (6-39), 
' and X is the row number of the location of the cursor (0-24). A call with 
' the carry bit clear moves the cursor to X,Y as determined by the Y and X 
' registers.
DECLARE SYSTEM PROC plot AT $FFF0( x AS BYTE ON REG(Y), y AS BYTE ON REG(X), #0 ON REG(CARRY) ) ON C64
DECLARE SYSTEM FUNCTION plotX AT $FFF0( #1 ON REG(CARRY) ) RETURN REG(Y) AS BYTE ON C64
DECLARE SYSTEM FUNCTION plotY AT $FFF0( #1 ON REG(CARRY) ) RETURN REG(X) AS BYTE ON C64

' ----------------------------------------------------------------------------
' IOBASE - Define I/O memory page
'
' This routine sets the X and Y registers to the address of the memory 
' section where the memory mapped 110 devices are located. This address can 
' then be used with an offset to access the memory mapped I/O devices in the 
' Commodore 64. The offset is the number of locations from the beginning of the
' page on which the I/O register you want is located. The X register contains the 
' low order address byte, while the Y register contains the high order address byte.
'
' This routine exists to provide compatibility between the Commodore 64, VIC-20,
' and future models of the Commodore 64. If the I/O locations for a machine
' language program are set by a call to this routine, they should still remain 
' compatible with future versions of the Commodore 64, the KERNAL and BASIC.
DECLARE SYSTEM FUNCTION iobase AT $FFF3 RETURN REG(YX) AS ADDRESS ON C64
