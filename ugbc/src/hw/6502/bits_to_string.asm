;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                CONVERT 32-BIT BINARY TO ASCII NUMBER STRING                 *
;*                                                                             *
;*                             by BigDumbDinosaur                              *
;*                                                                             *
;* This 6502 assembly language program converts a 32-bit unsigned binary value *
;* into a null-terminated ASCII string whose format may be in  binary,  octal, *
;* decimal or hexadecimal.                                                     *
;*                                                                             *
;* --------------------------------------------------------------------------- *
;*                                                                             *
;* Copyright (C)1985 by BCS Technology Limited.  All rights reserved.          *
;*                                                                             *
;* Permission is hereby granted to copy and redistribute this software,  prov- *
;* ided this copyright notice remains in the source code & proper  attribution *
;* is given.  Any redistribution, regardless of form, must be at no charge  to *
;* the end user.  This code MAY NOT be incorporated into any package  intended *
;* for sale unless written permission has been given by the copyright holder.  *
;*                                                                             *
;* THERE IS NO WARRANTY OF ANY KIND WITH THIS SOFTWARE.  It's free, so no mat- *
;* ter what, you're getting a great deal.                                      *
;*                                                                             *
;* Originally published on http://6502.org/source/strings/32bit-to-ascii.html  *
;* Adapted by Marco Spedaletti for ugBASIC                                     *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;
;	CALLING SYNTAX:
;
;	        LDA #RADIX         ;radix character, see below
;	        LDX #<OPERAND      ;binary value address LSB
;	        LDY #>OPERAND      ;binary value address MSB
;	        (ORA #%10000000)   ;radix suppression, see below
;	        JSR BINSTR         ;perform conversion
;	        STX ZPPTR          ;save string address LSB
;	        STY ZPPTR+1        ;save string address MSB
;	        TAY                ;string length
;	LOOP    LDA (ZPPTR),Y      ;copy string to...
;	        STA MYSPACE,Y      ;safe storage, will include...
;	        DEY                ;the terminator
;	        BPL LOOP
;
;	CALLING PARAMETERS:
;
;	.A      Conversion radix, which may be any of the following:
;
;	        '%'  Binary.
;	        '@'  Octal.
;	        '$'  Hexadecimal.
;
;	        If the radix is not one of the above characters decimal will be
;	        assumed.  Binary, octal & hex conversion will prepend the radix
;	        character to the string.  To suppress this feature set bit 7 of
;	        the radix.
;
;	.X/.Y   The address of the 32-bit binary value (operand) that is to be
;	        converted.  The operand must be in little-endian format.
;
;   $35     Number of bits to convert.
;
;	REGISTER RETURNS:
;
;	.A      The printable string length.  The exact length will depend on
;	        the radix that has been selected, whether the radix is to be
;	        prepended to the string & the number of significant digits.
;	        Maximum possible printable string lengths for each radix type
;	        are as follows:
;
;	        %  Binary   33
;	        @  Octal    12
;	           Decimal  11
;	        $  Hex       9
;
;	.X/.Y   The LSB/MSB address at which the null-terminated conversion
;	        string will be located.  The string will be assembled into a
;	        statically allocated buffer and should be promptly copied to
;	        user-defined safe storage.
;
;	.C      The carry flag will always be clear.
;
;	APPROXIMATE EXECUTION TIMES in CLOCK CYCLES:
;
;	        Binary    5757
;	        Octal     4533
;	        Decimal  13390
;	        Hex       4373
;
;	The above execution times assume the operand is $FFFFFFFF, the radix
;	is to be prepended to the conversion string & all workspace other than
;	the string buffer is on zero page.  Relocating ZP workspace to absolute
;	memory will increase execution time approximately 8 percent.
;
;================================================================================
;
;ATOMIC CONSTANTS
;
_zpage_  =$10                  ;start of ZP storage
;
;	------------------------------------------
;	Modify the above to suit your application.
;	------------------------------------------
;
a_hexdec ='A'-'9'-2            ;hex to decimal difference
m_bits   =32                   ;operand bit size
m_cbits  =48                   ;workspace bit size
m_strlen =m_bits+1             ;maximum printable string length
n_radix  =4                    ;number of supported radices
s_pfac   =m_bits/8             ;primary accumulator size
s_ptr    =2                    ;pointer size
s_wrkspc =m_cbits/8            ;conversion workspace size
;
;================================================================================
;
;ZERO PAGE ASSIGNMENTS
;
ptr01    =_zpage_              ;string storage pointer
;
;	---------------------------------
;	The following may be relocated to
;	absolute storage if desired.
;	---------------------------------
;
pfac     =ptr01+s_ptr          ;primary accumulator
wrkspc01 =pfac+s_pfac          ;conversion...
wrkspc02 =wrkspc01+s_wrkspc    ;workspace
formflag =wrkspc02+s_wrkspc    ;string format flag
radix    =formflag+1           ;radix index
stridx   =radix+1              ;string buffer index
;
;================================================================================
;
;CONVERT 32-BIT BINARY TO NULL-TERMINATED ASCII NUMBER STRING
;
;	----------------------------------------------------------------
;	WARNING! If this code is run on an NMOS MPU it will be necessary
;	         to disable IRQs during binary to BCD conversion unless
;	         the target system's IRQ handler clears decimal mode.
;	         Refer to the FACBCD subroutine.
;	----------------------------------------------------------------
;
;
binstr:  stx ptr01             ;operand pointer LSB
         sty ptr01+1           ;operand pointer MSB
         tax                   ;protect radix
         ldy #s_pfac-1         ;operand size
;
binstr01:lda (ptr01),y         ;copy operand to...
         sta pfac,y            ;workspace
         dey
         bpl binstr01
;
         iny
         sty stridx            ;initialize string index
;
;	--------------
;	evaluate radix
;	--------------
;
         txa                   ;radix character
         asl                   ;extract format flag &...
         ror formflag          ;save it
         lsr                   ;extract radix character
         ldx #n_radix-1        ;total radices
;
binstr03:cmp radxtab,x         ;recognized radix?
         beq binstr04          ;yes
;
         dex
         bne binstr03          ;try next
;
;	------------------------------------
;	radix not recognized, assume decimal
;	------------------------------------
;
binstr04:stx radix             ;save radix index for later
         txa                   ;converting to decimal?
         bne binstr05          ;no
;
;	------------------------------
;	prepare for decimal conversion
;	------------------------------
;
         jsr facbcd            ;convert operand to BCD
         lda #0
         beq binstr09          ;skip binary stuff
;
;	-------------------------------------------
;	prepare for binary, octal or hex conversion
;	-------------------------------------------
;
binstr05:bit formflag
         bmi binstr06          ;no radix symbol wanted
;
         lda radxtab,x         ;radix table
         sta strbuf            ;prepend to string
         inc stridx            ;bump string index
;
binstr06:ldx #0                ;operand index
         ldy #s_wrkspc-1       ;workspace index
;
binstr07:lda pfac,x            ;copy operand to...
         sta wrkspc01,y        ;workspace in...
         dey                   ;big-endian order
         inx
         cpx #s_pfac
         bne binstr07
;
         lda #0
;
binstr08:sta wrkspc01,y        ;pad workspace
         dey
         bpl binstr08
;
;	----------------------------
;	set up conversion parameters
;	----------------------------
;
binstr09:sta wrkspc02          ;initialize byte counter
         ldy radix             ;radix index
         lda numstab,y         ;numerals in string
         sta wrkspc02+1        ;set remaining numeral count
         lda bitstab,y         ;bits per numeral
         sta wrkspc02+2        ;set
         lda lzsttab,y         ;leading zero threshold
         sta wrkspc02+3        ;set
;
;	--------------------------
;	generate conversion string
;	--------------------------
;
binstr10:lda #0
         ldy wrkspc02+2        ;bits per numeral
;
binstr11:ldx #s_wrkspc-1       ;workspace size
         clc                   ;avoid starting carry
;
binstr12:rol wrkspc01,x        ;shift out a bit...
         dex                   ;from the operand or...
         bpl binstr12          ;BCD conversion result
;
         rol                   ;bit to .A
         dey
         bne binstr11          ;more bits to grab
;
         tay                   ;if numeral isn't zero...
         bne binstr13          ;skip leading zero tests
;
         ldx wrkspc02+1        ;remaining numerals
         cpx wrkspc02+3        ;leading zero threshold
         bcc binstr13          ;below it, must convert
;
         ldx wrkspc02          ;processed byte count
         beq binstr15          ;discard leading zero
;
binstr13:cmp #10               ;check range
         bcc binstr14          ;is 0-9
;
         adc #a_hexdec         ;apply hex adjust
;
binstr14:adc #'0'              ;change to ASCII
         ldy stridx            ;string index
         sta strbuf,y          ;save numeral in buffer
         inc stridx            ;next buffer position
         inc wrkspc02          ;bytes=bytes+1
;
binstr15:dec wrkspc02+1        ;numerals=numerals-1
         bne binstr10          ;not done
;
;	-----------------------
;	terminate string & exit
;	-----------------------
;
         lda #0
         ldx stridx            ;printable string length
         sta strbuf,x          ;terminate string
         txa
         ldx #<strbuf          ;converted string LSB
         ldy #>strbuf          ;converted string MSB
         clc                   ;all okay
         cld
         rts
;
;================================================================================
;
;CONVERT PFAC INTO BCD
;
;	---------------------------------------------------------------
;	Uncomment noted instructions if this code is to be used  on  an
;	NMOS system whose interrupt handlers do not clear decimal mode.
;	---------------------------------------------------------------
;
facbcd:   ldx #s_pfac-1         ;primary accumulator size -1
;
facbcd01:lda pfac,x            ;value to be converted
         pha                   ;protect
         dex
         bpl facbcd01          ;next
;
         lda #0
         ldx #s_wrkspc-1       ;workspace size
;
facbcd02:sta wrkspc01,x        ;clear final result
         sta wrkspc02,x        ;clear scratchpad
         dex
         bpl facbcd02
;
         inc wrkspc02+s_wrkspc-1
         ;php                   ;!!! uncomment for NMOS MPU !!!
         ;sei                   ;!!! uncomment for NMOS MPU !!!
         sed                   ;select decimal mode
         ; ldy #m_bits-1         ;bits to convert -1
         ldy $35                ;bits to convert -1
         dey
;
facbcd03:ldx #s_pfac-1         ;operand size
         clc                   ;no carry at start
;
facbcd04:ror pfac,x            ;grab LS bit in operand
         dex
         bpl facbcd04
;
         bcc facbcd06          ;LS bit clear
;
         clc
         ldx #s_wrkspc-1
;
facbcd05:lda wrkspc01,x        ;partial result
         adc wrkspc02,x        ;scratchpad
         sta wrkspc01,x        ;new partial result
         dex
         bpl facbcd05
;
         clc
;
facbcd06:ldx #s_wrkspc-1
;
facbcd07:lda wrkspc02,x        ;scratchpad
         adc wrkspc02,x        ;double &...
         sta wrkspc02,x        ;save
         dex
         bpl facbcd07
;
         dey
         bpl facbcd03          ;next operand bit
;
         ;plp                   ;!!! uncomment for NMOS MPU !!!
         ldx #0
;
facbcd08:pla                   ;operand
         sta pfac,x            ;restore
         inx
         cpx #s_pfac
         bne facbcd08          ;next
;
         rts
;
;================================================================================
;
;PER RADIX CONVERSION TABLES
;
bitstab:  .byte 4,1,3,4         ;bits per numeral
lzsttab:  .byte 2,9,2,3         ;leading zero suppression thresholds
numstab:  .byte 12,48,16,12     ;maximum numerals
radxtab:  .byte 0,37,64,36         ;recognized symbols
;
;================================================================================
;
;STATIC STORAGE
;
strbuf:   .res m_strlen+1        ;conversion string buffer
;
;================================================================================
