REM @english
REM OPTIMIZATION BENCHMARKS ADDITIONS USING 32 BITS
REM
REM This example attempts to calculate the time required to 
REM perform integer calculations, specifically 32 bit additions.
REM 
REM @italian
REM MISURE DI OTTIMIZZAZIONE MOLTIPLICAZIONI IN VIRGOLA MOBILE
REM
REM Questo esempio cerca di calcolare il tempo necessario per 
REM effettuare calcoli con numeri interi, in particolare a 32 bit.
REM
REM @include 

	CONST maxCounter = 20000

	CLS

	DIM originalValue AS DWORD
	DIM offset AS DWORD
	DIM targetValue AS DWORD
	
	originalValue = 2000
	offset = 1000
	
	startTime = TIME
	
	counter = 0
	DO
		targetValue = originalValue+offset
		INC counter
		EXIT IF counter = maxCounter
	LOOP
	
	PRINT (TIME - startTime); " jiffy(s)"
	
	PRINT originalValue;"+";offset;" = ";targetValue
	