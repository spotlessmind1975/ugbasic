REM @english
REM OPTIMIZATION BENCHMARKS DIVISION 8/8 BITS
REM
REM This example attempts to calculate the time required to 
REM perform integer divisions with 8 bit numbers.
REM 
REM @italian
REM MISURE DI OTTIMIZZAZIONE DIVISIONI 8/8 BITS
REM
REM Questo esempio cerca di calcolare il tempo necessario per 
REM svolgere divisioni con numeri da 8 bit.
REM
REM @include 

	CONST maxCounter = 20000

	CLS

	DIM originalValue1 AS BYTE
	DIM originalValue2 AS BYTE
	DIM targetValue AS BYTE
	
	originalValue1 = 42
	originalValue2 = 21
	
	startTime = TIME
	
	counter = 0
	DO
		targetValue = originalValue1 / originalValue2
		INC counter
		EXIT IF counter = maxCounter
	LOOP
	
	PRINT (TIME - startTime); " jiffy(s)"
	
	PRINT originalValue1;" / ";originalValue2;" = ";targetValue
	