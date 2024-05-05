REM @english
REM OTHER CONTRIBUTIONS RANDOM DISTRIBUTION
REM
REM This example shows the statistical distribution 
REM of the random number generator.
REM
REM @italian
REM VARI ALTRI CONTRIBUTI DISTRIBUZIONE CASUALE
REM
REM Questo esempio mostra la distribuzione statistica 
REM del generatore di numeri casuali.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,cpc,zx,pc128op,to8

	CLS

	CONST range = SCREEN COLUMNS
	CONST height = SCREEN ROWS - 2
	CONST maxSteps = 512

	DIM value AS INTEGER
	DIM steps AS INTEGER
	DIM count AS INTEGER
		
	DIM v(range) AS INTEGER
	
	DO
		value = RND(range)
		HOME: PRINT "step: ";steps;" value: ";value
		INC v(value)
		INC steps
		EXIT IF steps > maxSteps
	LOOP
	
	CLS
	
	FOR i = 0 TO ( range - 1 )
		count = ( ( maxSteps - v(i) ) * height ) / maxSteps
		FOR j = count TO height
			LOCATE i, j: PRINT "*";
		NEXT j
	NEXT i
	
