REM @english
REM ADVANCED MATH DEFINE HIGH PRECISION SERIES
REM
REM This example shows how to calculate an high precision series of numbers.
REM
REM @italian
REM MATEMATICA CON PRECISIONE DEFINIRE VARIABILI AD ALTA PRECISIONE
REM
REM Questo esempio mostra come calcolare una serie di numeri in alta precisione.
REM
REM @include atari,atarixl

	' Define the number width of 10 bytes (80 bits)
	DEFINE NUMBER BYTES 10
	
	' Define the maximum number of digits to represent the number
	DEFINE NUMBER DIGITS 40

	' Define starting number
	DIM a AS NUMBER
	
	' Assign a value to them
	a = 100000
	
	' Clear the screen
	CLS: INK WHITE
	
	' Now let's make a loop, doubling and increment
	' the original value
	DO
		PRINT a
		WAIT KEY
		a = ( a * 2 ) + 1
	LOOP
	
	