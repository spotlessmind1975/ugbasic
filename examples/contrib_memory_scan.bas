REM @english
REM OTHER CONTRIBUTIONS MEMORY SCANNER
REM
REM A RAM-scanner, written (originally) in XC=BASIC by the Italian JJ Flash, 
REM and translated in ugBASIC which displays part of the contents of the RAM, 
REM in PETSCII characters. With it you can run from one part of the retro computer 
REM memory to another by simply using the joystick. A nice example of how to take 
REM advantage of the powerful MMOVE instruction.
REM
REM @italian
REM VARI ALTRI CONTRIBUTI SCANNER DI MEMORIA
REM
REM Un RAM-scanner scritto (originariamente) in XC=BASIC dallo sviluppatore JJ Flash e
REM tradotto in ugBASIC. Visualizza a video parte del contenuto della RAM, in caratteri PETSCII. 
REM Con esso ? possibile scorrazzare da una parte all'altra della memoria del retro computer
REM attraverso il direzionamento del joystick. Un bell'esempio di come sfruttare la potente 
REM istruzione MMOVE.
REM 
REM @url https://github.com/JJFlash-IT/XCB3_Examples/blob/main/RAM_Scan_XCB/xcb-ramscan.bas
REM
REM @include atari,atarixl,c128,c64,coco

	VAR wSourceAddress AS ADDRESS = 0

	INK WHITE

	CLS

	DO

		MMOVE wSourceAddress TO VIDEO TEXTADDRESS SIZE ( SCREEN ROWS - 1 ) * SCREEN COLUMNS
		
		LOCATE 0, (SCREEN ROWS - 1)
		PRINT wSourceAddress; "    ";

		joy = JOY(0): kbd = SCANCODE
		IF ( joy HAS BIT LEFT ) OR ( kbd = KEY A ) THEN 
			wSourceAddress = wSourceAddress - 1
		ENDIF
		IF ( joy HAS BIT RIGHT ) OR ( kbd = KEY S ) THEN
			wSourceAddress = wSourceAddress + 1
		ENDIF
		IF ( joy HAS BIT UP ) OR ( kbd = KEY W ) THEN
			wSourceAddress = wSourceAddress - 80
		ENDIF
		IF ( joy HAS BIT DOWN ) OR ( kbd = KEY Z ) THEN
			wSourceAddress = wSourceAddress + 80
		ENDIF
		
	LOOP


