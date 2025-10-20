REM @english
REM OPTIMIZATION BENCHMARKS CONVERTING STRING INTO VALUE
REM
REM This example attempts to calculate the time required to 
REM perform string to integer conversion.
REM 
REM @italian
REM MISURE DI OTTIMIZZAZIONE CONVERTIRE STRINGHE IN VALORI
REM
REM Questo esempio cerca di calcolare il tempo necessario per 
REM svolgere conversioni da stringa a intero.
REM
REM @include 

	CONST maxCounter = 20000

	CLS

	DIM originalValue AS STRING
	DIM targetValue AS WORD
	
	originalValue = "1000"
	
	startTime = TIME
	
	counter = 0
	DO
		targetValue = VAL(originalValue)
		INC counter
		EXIT IF counter = maxCounter
	LOOP
	
	PRINT (TIME - startTime); " jiffy(s)"
	
	PRINT "VAL(";originalValue;") = ";targetValue
	