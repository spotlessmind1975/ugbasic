REM @english
REM OPTIMIZATION BENCHMARKS ADDITIONS USING FLOATING POINTS
REM
REM This example attempts to calculate the time required to 
REM perform floating-point calculations, specifically additions.
REM 
REM @italian
REM MISURE DI OTTIMIZZAZIONE ADDIZIONI IN VIRGOLA MOBILE
REM
REM Questo esempio cerca di calcolare il tempo necessario per 
REM effettuare calcoli in virgola mobile, in particolare addizioni.
REM
REM @include 

	CONST maxCounter = 1

	CLS
	
	originalValue = 42.0
	
	startTime = TIME
	
	counter = 0
	DO
		targetValue = originalValue+1.0
		INC counter
		EXIT IF counter = maxCounter
	LOOP
	
	PRINT (TIME - startTime); " jiffy(s)"
	
	PRINT originalValue;"+1.0 = ";targetValue