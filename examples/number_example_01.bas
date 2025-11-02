REM @english
REM ADVANCED MATH DEFINE HIGH PRECISION VARIABLES
REM
REM This example shows how to define a 80-bit numeric variable 
REM and perform a series of mathematical calculations on it. 
REM Note that, for efficiency reasons, we always stick to this 
REM type of variable.
REM
REM @italian
REM MATEMATICA CON PRECISIONE DEFINIRE VARIABILI AD ALTA PRECISIONE
REM
REM Questo esempio mostra come definire una variabile numerica di 
REM 80 bit, e come operare una serie di calcoli matematici su di 
REM essa. Da notare che, per questioni di efficienza, si rimane 
REM sempre su questo tipo di variabili.
REM
REM @include atari,atarixl

	' Define the number width of 10 bytes (80 bits)
	DEFINE NUMBER BYTES 10
	
	' Define the maximum number of digits to represent the number
	DEFINE NUMBER DIGITS 40

	' Define two variables
	DIM a AS NUMBER, b AS NUMBER

	' Assign a value to them
	a = 100000: b = 100000
	
	' Clear the screen and print the sum
	CLS
	INK WHITE
	PRINT a;"+";b;"=";
	PRINT a+b
	'PRINT a;"-";b;"=";a-b
	'PRINT a;"*";b;"=";a*b
	'PRINT a;"/";b;"=";a/b
	