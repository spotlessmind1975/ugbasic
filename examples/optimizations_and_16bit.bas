REM @english
REM OPTIMIZATION BENCHMARKS 16 BIT BITWISE AND
REM
REM This example attempts to calculate the time required to 
REM perform bitwise AND between 16 bit numbers.
REM 
REM @italian
REM MISURE DI OTTIMIZZAZIONE CONVERTIRE STRINGHE IN VALORI
REM
REM Questo esempio cerca di calcolare il tempo necessario per 
REM svolgere delle operazioni di AND tra bit con numeri a 16 bit.
REM
REM @include 

	CONST maxCounter = 20000

	CLS

	DIM originalValue1 AS WORD
	DIM originalValue2 AS WORD
	DIM targetValue AS WORD
	
	originalValue1 = &H55
	originalValue2 = &H11
	
	startTime = TIME
	
	counter = 0
	DO
		targetValue = originalValue1 AND originalValue2
		INC counter
		EXIT IF counter = maxCounter
	LOOP
	
	PRINT (TIME - startTime); " jiffy(s)"
	
	PRINT originalValue1;" AND ";originalValue2;" = ";targetValue
	