REM @english
REM FLOATING POINT USING COSINE FUNCTION
REM
REM This small example will show how to use the ''COS'' function. Note that
REM we require to use the single precision for floating points.
REM 
REM @italian
REM NUMERI VIRGOLA MOBILE USARE LA FUNZIONE COSENO
REM
REM Questo piccolo esempio mostrerà come usare la funzione ''COS''. Da notare
REM che stiamo richiedendo di utilizzare la precisione singola.
REM
REM @include atari,atarixl,c128,c64,coco,coleco,cpc

DEFINE FLOAT PRECISION SINGLE

	CLS
	
	INK WHITE

	PRINT "COS(0) = "; COS(0)

	RADIAN
	PRINT "COS(PI  ) = "; COS(PI)
	PRINT "COS(PI/2) = "; COS(PI/2)
	PRINT "COS(PI/4) = "; COS(PI/4)
	DEGREE
	PRINT "COS(0) = "; COS(0)
	PRINT "COS(45) = "; COS(45)
	PRINT "COS(90) = "; COS(90)


