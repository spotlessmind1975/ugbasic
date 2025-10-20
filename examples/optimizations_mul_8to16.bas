REM @english
REM OPTIMIZATION BENCHMARKS MULTIPLICATION 8/16 BITS
REM
REM This example attempts to calculate the time required to 
REM perform integer multiplications from 8 bit to 16 bit.
REM 
REM @italian
REM MISURE DI OTTIMIZZAZIONE CONVERTIRE STRINGHE IN VALORI
REM
REM Questo esempio cerca di calcolare il tempo necessario per 
REM svolgere moltiplicazioni intere da 8 a 16 bit
REM
REM @include 

	CONST maxCounter = 20000

	CLS

	DIM originalValue1 AS BYTE
	DIM originalValue2 AS BYTE
	DIM targetValue AS WORD
	
	originalValue1 = 42
	originalValue2 = 30
	
	startTime = TIME
	
	counter = 0
	DO
		targetValue = originalValue1 * originalValue2
		INC counter
		EXIT IF counter = maxCounter
	LOOP
	
	PRINT (TIME - startTime); " jiffy(s)"
	
	PRINT originalValue1;" x ";originalValue2;" = ";targetValue
	