REM @english
REM OPTIMIZATION BENCHMARKS DIVISION WITH POWERS OF TWO
REM
REM This example attempts to calculate the time required to 
REM perform integer divisions using powers of two.
REM 
REM @italian
REM MISURE DI OTTIMIZZAZIONE CONVERTIRE STRINGHE IN VALORI
REM
REM Questo esempio cerca di calcolare il tempo necessario per 
REM svolgere divisini intere usando potenze di due
REM
REM @include 

	CONST maxCounter = 20000

	CLS

	DIM originalValue AS WORD
	DIM targetValue AS WORD
	
	originalValue = 1000
	
	startTime = TIME
	
	counter = 0
	DO
		targetValue = originalValue \ 8
		INC counter
		EXIT IF counter = maxCounter
	LOOP
	
	PRINT (TIME - startTime); " jiffy(s)"
	
	PRINT "VAL(";originalValue;") = ";targetValue
	