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

	CONST maxCounter = 2000

	BITMAP ENABLE(16)
	
	CLS
	
    airplane = LOAD IMAGE("air_attack_airplane.png")

	startTime = TIME
	
	counter = 0
	DO
    	PUT IMAGE airplane AT 20,20	
		INC counter
		EXIT IF counter = maxCounter
	LOOP
	
	PRINT (TIME - startTime); " jiffy(s)"
		