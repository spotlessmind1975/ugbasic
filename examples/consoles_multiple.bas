REM @english
REM CONSOLE MANAGEMENT MULTIPLE CONSOLE EXAMPLE
REM
REM This example shows how three consoles work.
REM 
REM @italian
REM GESTIONE DELLA CONSOLE ESEMPIO DI CONSOLE MULTIPLE
REM
REM Questo esempio mostra come funzionano tre console.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,pc128op,to8,cpc
	
	CLS
	
	FOR i = 0 TO SCREEN COLUMNS - 1
		PRINT ( i MOD 10 );
	NEXT i
	
	FOR i = 1 TO SCREEN ROWS - 2
		PRINT ( i MOD 10 )
	NEXT i
	
	PRINT ( i MOD 10 );
	
	CONSOLE 1, 1 TO 10, 2
	CONSOLE SAVE 0
	CONSOLE 2, 5 TO 11, 7
	CONSOLE SAVE 1
	CONSOLE 3, 9 TO 13, 11
	CONSOLE SAVE 2
	
	i = 0: j = 0
	DO
		CONSOLE USE i
		PRINT (j MOD (10-(i+1)));
		ADD i, 1, 0 TO 2
		INC j
	LOOP

