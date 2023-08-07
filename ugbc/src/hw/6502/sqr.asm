; Square Root Calculator by Lee Davison
;
; How to calculate the 8-bit unsigned integer square root of an unsigned 16-bit integer.
; By Lee Davison (leeedavison@googlemail.com), 23 July 2001.
; Calculates the 8 bit root and 9 bit remainder of a 16 bit unsigned integer in
; Numberl/Numberh. The result is always in the range 0 to 255 and is held in
; Root, the remainder is in the range 0 to 511 and is held in Reml/Remh
;
; partial results are held in templ/temph
;
; This routine is the complement to the integer square program.
;
; Destroys A, X registers.
;
; variables - must be in RAM
; Originally published on http://6502.org/source/integers/root.htm 
; Adapted by Marco Spedaletti for ugBASIC   
;
; @thirdparts Lee Davison                                       *                                                                             *


Numberl		= $98		; number to find square root of low byte
Numberh		= Numberl+1	; number to find square root of high byte
Reml		= Numberh+1		; remainder low byte
Remh		= Reml+1	; remainder high byte
templ		= Remh+1		; temp partial low byte
temph		= templ+1	; temp partial high byte
Root		= temph+1		; square root

SQROOT:
	LDA	#$00		; clear A
	STA	Reml		; clear remainder low byte
	STA	Remh		; clear remainder high byte
	STA	Root		; clear Root
	LDX	#$08		; 8 pairs of bits to do
SQROOTL1:
	ASL	Root		; Root = Root * 2

	ASL	Numberl		; shift highest bit of number ..
	ROL	Numberh		;
	ROL	Reml		; .. into remainder
	ROL	Remh		;

	ASL	Numberl		; shift highest bit of number ..
	ROL	Numberh		;
	ROL	Reml		; .. into remainder
	ROL	Remh		;

	LDA	Root		; copy Root ..
	STA	templ		; .. to templ
	LDA	#$00		; clear byte
	STA	temph		; clear temp high byte

	SEC			; +1
	ROL	templ		; temp = temp * 2 + 1
	ROL	temph		;

	LDA	Remh		; get remainder high byte
	CMP	temph		; comapre with partial high byte
	BCC	SQROOTNX		; skip sub if remainder high byte smaller

	BNE	SQROOTSB		; do sub if <> (must be remainder>partial !)

	LDA	Reml		; get remainder low byte
	CMP	templ		; comapre with partial low byte
	BCC	SQROOTNX		; skip sub if remainder low byte smaller

				; else remainder>=partial so subtract then
				; and add 1 to root. carry is always set here
SQROOTSB:
	LDA	Reml		; get remainder low byte
	SBC	templ		; subtract partial low byte
	STA	Reml		; save remainder low byte
	LDA	Remh		; get remainder high byte
	SBC	temph		; subtract partial high byte
	STA	Remh		; save remainder high byte

	INC	Root		; increment Root
SQROOTNX:
	DEX			; decrement bit pair count
	BNE	SQROOTL1		; loop if not all done

	RTS