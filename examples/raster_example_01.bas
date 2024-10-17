REM @english
REM RASTER ROUTINES VERTICAL BANDING
REM
REM This small example will show how to use the raster
REM routines to create an horizontal banding on the border
REM of the screen.
REM 
REM @italian
REM AUDIO E MUSICA ESEMPIO CON SOUND (3)
REM
REM Questo piccolo esempio mostrerà come usare le routine
REM raster per creare una banda orizzontale sul bordo dello
REM schermo.
REM

	BITMAP ENABLE
	CLS BLACK
	
	RASTER AT #10 WITH red
	
	HALT
	
red:
	COLOR BORDER RED
	NEXT RASTER AT #50 WITH blue
	
blue:
	COLOR BORDER BLUE
	NEXT RASTER AT #10 WITH red
