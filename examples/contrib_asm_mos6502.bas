REM OTHER CONTRIBUTIONS ASSEMBLY FOR BEGINNERS (MOS 6502)
REM
REM This is a short program that shows how easy it is to learn assembly 
REM with ugBASIC. Since version 1.14.1, in fact, it allows you to insert 
REM assembly code online. Clearly accessing all the BASIC features. 
REM This program shows how a 16-bit (2 x 8-bit) addition works under
REM the MOS 6502 processor.
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI ASSEMBLY PER PRINCIPIANTI (MOS 6502)
REM
REM Questo è un breve programma che mostra come sia facile imparare 
REM l'assembly con ugBASIC. Dalla versione 1.14.1, infatti, permette
REM di inserire codice assembly in linea. Accedendo, chiaramente, a 
REM tutte le caratteristiche del BASIC. Questo programma mostra come 
REM si opera una somma a 16 bit (2 x 8 bit) con il processore MOS 6502.
REM 

CLS

x = 10: y = 40: z = 0

PRINT x;" + "; y; " = ";

BEGIN ASM

	CLC
	
	LDA _x
	ADC _y
	STA _z
	
	LDA _x+1
	ADC _y+1
	STA _z+1
	
END ASM

PRINT z


