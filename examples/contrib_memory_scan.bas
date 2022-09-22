REM @english
REM OTHER CONTRIBUTIONS MEMORY SCANNER
REM
REM A RAM-scanner, written (originally) in XC=BASIC by the Italian JJ Flash, 
REM and translated in ugBASIC which displays part of the contents of the RAM, 
REM in PETSCII characters. With it you can run from one part of the retro computer 
REM memory to another by simply using the joystick. A nice example of how to take 
REM advantage of the powerful MMOVE instruction. The original source can be found here:
REM https://github.com/JJFlash-IT/XCB3_Examples/blob/main/RAM_Scan_XCB/xcb-ramscan.bas
REM
REM @italian
REM VARI ALTRI CONTRIBUTI SCANNER DI MEMORIA
REM
REM Un RAM-scanner scritto (originariamente) in XC=BASIC dallo sviluppatore JJ Flash e
REM tradotto in ugBASIC. Visualizza a video parte del contenuto della RAM, in caratteri PETSCII. 
REM Con esso ? possibile scorrazzare da una parte all'altra della memoria del retro computer
REM attraverso il direzionamento del joystick. Un bell'esempio di come sfruttare la potente 
REM istruzione MMOVE. Il sorgente originale lo trovate qui:
REM https://github.com/JJFlash-IT/XCB3_Examples/blob/main/RAM_Scan_XCB/xcb-ramscan.bas
REM

'
' ORIGINALLY PUBLISHED ON 
' 
' HEAVILY inspired by RAM Scan 64's video by Robin Harbron 
' -- https://www.youtube.com/watch?v=6g0Cev-3D2g&t=1276s
'

''' Commented code since in ugBASIC cursor keys are managed 
''' differently and we will use the joystick, too
'Const CRSR_DN = 65152
'Const CRSR_RT = 65028
'Const LSHIFT =  64896
'Const RSHIFT =  48912

''' Variable definition is a bit different.
''' On ugBASIC we have ADDRESS as data type 
''' to store memory addresses
' Dim wSourceAddress as WORD : wSourceAddress = 0

VAR wSourceAddress AS ADDRESS = 0

''' This is useless -- on C=64 it is done by default
' poke $d018, $17 'changes to lowercase

''' Command replacement.
' poke 646, 1 'foreground, white
INK WHITE

''' Command replacement.
' sys $E544 FAST 'clear screen
CLS

DO

    ''' Command replacement
	' memcpy wSourceAddress, 1024, 960
	MMOVE wSourceAddress TO TEXTADDRESS SIZE SCREEN ROWS * SCREEN COLUMNS
	
	''' Command replacement
	' textat 0, 24, str$(wSourceAddress) + "    "
	LOCATE 0, (SCREEN ROWS - 1)
	PRINT wSourceAddress; "    ";

	''' Command replacement
	'if key(LSHIFT) or key(RSHIFT) then
	'	if key(CRSR_DN) then 'it's actually UP
	'		wSourceAddress = wSourceAddress - 80
	'	else
	'		if key(CRSR_RT) then 'it's actually LEFT
	'			wSourceAddress = wSourceAddress - 1
	'		end if
	'	end if
	'else
	'	if key(CRSR_DN) then
	'		wSourceAddress = wSourceAddress + 80
	'	else
	'		if key(CRSR_RT) then
	'			wSourceAddress = wSourceAddress + 1
	'		end if
	'	end if
	'end if
	joy = JOY(0): kbd = SCANCODE
	IF ( joy HAS BIT LEFT ) OR ( kbd = KEY A ) THEN : wSourceAddress = wSourceAddress - 1 : ENDIF
	IF ( joy HAS BIT RIGHT ) OR ( kbd = KEY S ) THEN : wSourceAddress = wSourceAddress + 1 : ENDIF
	IF ( joy HAS BIT UP ) OR ( kbd = KEY W ) THEN : wSourceAddress = wSourceAddress - 80 : ENDIF
	IF ( joy HAS BIT DOWN ) OR ( kbd = KEY Z ) THEN : wSourceAddress = wSourceAddress + 80 : ENDIF
	
LOOP
