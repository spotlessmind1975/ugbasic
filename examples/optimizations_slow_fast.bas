REM @english
REM OPTIMIZATION BENCHMARKS USING FAST / SLOW
REM
REM This example attempts to calculate the difference between
REM the running speed when in FAST or in SLOW mode.
REM 
REM @italian
REM MISURE DI OTTIMIZZAZIONE USANDO FAST / SLOW
REM
REM Questo esempio prova a calcolare la differenza di velocità tra
REM le modalità FAST e SLOW.
REM
REM @include 

	CONST maxCounter = 10000

	CLS

	FAST
	
	startTime = TIME
	
	counter = 0
	DO
		INC counter
		EXIT IF counter = maxCounter
	LOOP
	
	PRINT (TIME - startTime); " jiffy(s)"
	
 	SLOW
 	
	startTime = TIME
	
	counter = 0
	DO
		INC counter
		EXIT IF counter = maxCounter
	LOOP
	
	PRINT (TIME - startTime); " jiffy(s)"

	