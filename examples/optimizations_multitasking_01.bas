REM @english
REM OPTIMIZATION BENCHMARKS MULTITASKING
REM
REM This example attempts to calculate the time required to 
REM perform task switching.
REM 
REM @italian
REM MISURE DI OTTIMIZZAZIONE CONVERTIRE STRINGHE IN VALORI
REM
REM Questo esempio cerca di calcolare il tempo necessario per 
REM svolgere il task switching.
REM
REM @include 

	CONST maxCounter = 10000

	x = 0
	
PARALLEL PROCEDURE procedure

	SHARED x
	
	DO
		INC x
	LOOP

END PROCEDURE

	CLS
	
	p1 = SPAWN procedure
	p2 = SPAWN procedure
	p3 = SPAWN procedure

	startTime = TIME
	
	counter = 0
	DO
		RUN PARALLEL
		INC counter
		EXIT IF counter = maxCounter
	LOOP
	
	PRINT "x = ";x
	PRINT (TIME - startTime); " jiffy(s)"
	
	