REM @english
REM FLOATING POINT USING TANGENT FUNCTION
REM
REM This small example will show how to use the ''TAN'' function. Note that
REM we require to use the single precision for floating points.
REM 
REM @italian
REM NUMERI VIRGOLA MOBILE USARE LA FUNZIONE COSENO
REM
REM Questo piccolo esempio mostrerà come usare la funzione ''TAN''. Da notare
REM che stiamo richiedendo di utilizzare la precisione singola.
REM
REM @include atari,atarixl

DEFINE FLOAT PRECISION SINGLE

	CLS
	
	INK WHITE

	RADIAN
	PRINT "TAN(0) = "; TAN(0)
	PRINT "TAN(PI/2) = "; TAN(PI/2)

	DEGREE
	PRINT "TAN(0) = "; TAN(0)
	PRINT "TAN(45) = "; TAN(45)


