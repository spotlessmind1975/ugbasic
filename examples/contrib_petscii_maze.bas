REM OTHER CONTRIBUTIONS PETSCII MAZE
REM
REM This example is inspired by an example posted in some groups, 
REM which compares the execution speed of BASIC 2.0, BASIC 2.0 
REM compiled with BasicBoss, and, finally, directly from ugBASIC. 
REM This code is specific to ugBASIC and serves to provide 
REM benchmarks of achievable performance.
REM
REM @url https://www.facebook.com/groups/2503729026388481/?multi_permalinks=25143380621996666
REM
REM @italian
REM VARI ALTRI CONTRIBUTI CALCULATE FIBONACCI
REM 
REM Questo esempio è ispirato all'esempio pubblicato su alcuni 
REM gruppi, in cui si confronta la velocità di esecuzione tra 
REM BASIC 2.0, BASIC 2.0 compilato con BasicBoss e, infine, 
REM direttamente da ugBASIC. Questo codice è specifico per 
REM ugBASIC, e serve per dare indicazioni di benchmark sulle 
REM performance che possono essere raggiunte.
REM
REM @url https://www.facebook.com/groups/2503729026388481/?multi_permalinks=25143380621996666
REM
REM @include c16,c128,c64,c64reu,vic20

PROCEDURE example ON C128, C64, C64REU, VIC20

	endAddress = TEXTADDRESS + ROWS*COLUMNS
	
	INK WHITE
	PAPER BLACK
	CLS
	POKE &HD018, &H15
	
	slash1# = 77
	slash2# = 78

	t0 = TIME
	
	t = TEXTADDRESS
	DO
		a# = RANDOM BYTE AND 1
		IF a#=#0 THEN : POKE t, slash1# : ELSE : POKE t, slash2# : ENDIF
		INC t
		EXIT IF t = endAddress
	LOOP

	t1 = TIME
	
	dauer = (t1 - t0) * 1000 / TPS
	
	BOTTOM: CLINE: PRINT "elapsed: ";dauer;" ms.";
	
END PROCEDURE

example[] ON C128, C64, C64REU, VIC20
	