REM @english
REM FLOATING POINT USING SINE FUNCTION
REM
REM This small example will show how to use the ''SIN'' function. Note that
REM we require to use the single precision for floating points.
REM 
REM @italian
REM NUMERI VIRGOLA MOBILE USARE LA FUNZIONE SENO
REM
REM Questo piccolo esempio mostrerà come usare la funzione ''SIN''. Da notare
REM che stiamo richiedendo di utilizzare la precisione singola.
REM
REM @include atari,atarixl

DEFINE FLOAT PRECISION SINGLE

	CLS
	
	INK WHITE

	RADIAN
	PRINT "SIN(PI  ) = "; SIN(PI)
	PRINT "SIN(PI/2) = "; SIN(PI/2)
	PRINT "SIN(PI/4) = "; SIN(PI/4)
	DEGREE
	PRINT "SIN(0) = "; SIN(0)
	PRINT "SIN(45) = "; SIN(45)
	PRINT "SIN(90) = "; SIN(90)


