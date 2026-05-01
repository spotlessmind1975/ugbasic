REM @english
REM OPTIMIZATION BENCHMARKS USING CPUSPEED
REM
REM This example attempts to calculate the difference between
REM the running speed when using CPUSPEED instruction.
REM 
REM @italian
REM MISURE DI OTTIMIZZAZIONE USANDO CPUSPEED
REM
REM Questo esempio prova a calcolare la differenza di velocità
REM usando l'istruzione CPUSPEED.
REM
REM @include 

	CONST maxCounter = 10000

	CLS

	CPUSPEED 3
	
	startTime = TIME
	
	counter = 0
	DO
		INC counter
		EXIT IF counter = maxCounter
	LOOP
	
	PRINT (TIME - startTime); " jiffy(s)"
	
	CPUSPEED 1
 	
	startTime = TIME
	
	counter = 0
	DO
		INC counter
		EXIT IF counter = maxCounter
	LOOP
	
	PRINT (TIME - startTime); " jiffy(s)"

	