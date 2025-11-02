REM @english
REM OPTIMIZATION BENCHMARKS CLEARING (BOXED) SCREEN
REM
REM This example attempts to measure the time it takes to 
REM clear a portion of the graphics screen.
REM 
REM @italian
REM MISURE DI OTTIMIZZAZIONE MOLTIPLICAZIONI CON POTENZE DI 2
REM
REM Questo esempio prova a misurare a misurare il tempo 
REM necessario a cancellare una porzione dello schermo grafico.
REM
REM @include 

	CONST maxCounter = 200
	
	BITMAP ENABLE(16)

	CLS
	
	BAR 10,10 TO SCREEN WIDTH-10, SCREEN HEIGHT-10, RED
	
	startTime = TIME
	
	counter = 0
	DO
		CLS 20, 20, 64, 64
		EXIT IF counter = maxCounter
		INC counter
	LOOP
	
	PRINT (TIME - startTime); " jiffy(s)"
	
	