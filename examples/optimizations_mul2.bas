REM @english
REM OPTIMIZATION BENCHMARKS POWER OF 2 MULTIPLICATIONS
REM
REM This example tries to measure the time needed to multiply a number 
REM that is a multiple of 2. This type of calculation is not performed 
REM like a classic multiplication, but by using a bit shift.
REM 
REM @italian
REM MISURE DI OTTIMIZZAZIONE MOLTIPLICAZIONI CON POTENZE DI 2
REM
REM Questo esempio prova a misurare il tempo necessario a effettuare 
REM una moltiplicazione per un numero multiplo di 2. Questo tipo di 
REM calcoli non viene infatti svolto come una moltiplicazione 
REM classica, ma con l'utilizzo di uno scorrimento di bit.
REM
REM @include 

	CONST maxCounter = 30000

	CLS
	
	originalValue = 42
	
	startTime = TIME
	
	counter = 0
	DO
		targetValue = originalValue**8
		INC counter
		EXIT IF counter = maxCounter
	LOOP
	
	PRINT (TIME - startTime); " jiffy(s)"
	
	PRINT originalValue;" x 8 = ";targetValue