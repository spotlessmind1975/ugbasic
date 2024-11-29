REM @english
REM TRAVELLING PATHS LINEAR PATHS
REM
REM This small example shows how to use the PATH
REM data type and the TRAVEL command to make a linear
REM path between two points.
REM
REM @italian
REM PERCORSI DI NAVIGAZIONE PERCORSI LINEARI
REM
REM Questo piccolo esempio mostra come utilizzare il tipo di dati 
REM PATH e il comando TRAVEL per creare un percorso lineare tra due punti.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,cpc,zx,pc128op,to8

	BITMAP ENABLE

	CLS

	DIM t AS PATH
	DIM x AS POSITION, y AS POSITION
	DIM x0 AS POSITION, y0 AS POSITION
	DIM x1 AS POSITION, y1 AS POSITION
	
	x0 = 0: y0 = 10
	x1 = 5: y1 = 5
	
	t = CREATE PATH( x0, y0 TO x1, y1 )
	DO
	     TRAVEL t TO x, y
	     PLOT x, y
	     WAIT KEY
	     EXIT IF x = x1 AND y = y1
	LOOP
	
