REM @english
REM OTHER CONTRIBUTIONS ITALIAN FLAG
REM
REM This small program draws a waving Italian flag. The original program
REM was written by Matthew Logue and posted in the "BASIC on the ZX 
REM Spectrum" group. He modified a program that generated bar graphs. 
REM The program has been adapted to run on many ugBASIC-supported 
REM computers.
REM
REM @url https://www.facebook.com/groups/vintagecomputerclubitalia.it/posts/31346776444920826/
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI BANDIERA ITALIANA
REM 
REM Questo piccolo programma disegna una bandiera italiana che sventola. 
REM Il programma originale è di Matthew Logue, e pubblicata nel gruppo 
REM "BASIC on the ZX Spectrum". Ha modificato un programma che generava 
REM grafici a barre. Il programma è stato adattato per girare su molti 
REM computer supportati da ugBASIC.
REM
REM @url https://www.facebook.com/groups/vintagecomputerclubitalia.it/posts/31346776444920826/
REM 
REM @include cpc,coleco,msx,pc128op,sg1000,sc3000,mo5,to8,coco3,zx

	' Enable colorfull bitmap graphic (up to 16 colors)
	
	BITMAP ENABLE(16)
	
	' Clear the screen
	
	CLS
	
	' Enable trigonometric functions using radiants.
	
	RADIAN
	
	' ugBASIC is an integer BASIC, so we need to
	' specify that some variables are floating point,
	' instead. Using the DIM instruction we can
	' declare the type of each variable.
	
	' This is the center of the screen.
	
	DIM cx AS FLOAT, cy AS FLOAT
	
	' These variables store the coordinates
	' of each point to draw, in a 3D reference system.
	
	DIM x AS FLOAT, y AS FLOAT, z AS FLOAT
	
	' These variables store the coordinates
	' of each point to draw, in a 2D reference system.
	
	DIM stx AS FLOAT, sty AS FLOAT

	' Calculate the "center" of the flag using
	' a proportional calculation with the original
	' values on the ZX spectrum resolution.
	
	cx=(SCREEN WIDTH / 2.0)
	cy=(SCREEN HEIGHT / 12.0)
	
	' Do nested loops.
	FOR ix=120 TO -19 STEP -4
	
		FOR iy=100 TO 1 STEP -4
	
		' Calculate the 3D coordinates.
		
		x = ix
		y = iy
		z = 30 + ( (10*SIN(x/11.0)) * COS(y/52.0) )
		
		' Transform them in a 2D projection.
		
		stx = cx+x-y: 
		sty = cy+x/2+y/2+z
		
		' Draw the point on the screen.
		PLOT stx, sty
		PLOT stx, sty+1

		' Change the color on the flag based 
		' on the abscissa of the 2D point.
		' (and avoid to draw the "star" if outside range).
		INK LIGHT RED
		IF x<(SCREEN WIDTH / 3.41) THEN INK LIGHT WHITE
		IF x<(SCREEN WIDTH / 16.0) THEN INK LIGHT GREEN
		IF x<(SCREEN WIDTH / 3.12) AND x>(SCREEN WIDTH / 3.76) THEN GOTO skip
		IF x<(SCREEN WIDTH / 10.66) AND x>(SCREEN WIDTH / 32.0) THEN GOTO skip
		
		' Draw the star around the point.
		' Fixed by Francesco Sblendorio here:
		' https://www.facebook.com/groups/2057165187928233/posts/4023940781250654/?comment_id=4025561614421904 
		
		PLOT stx+1, sty+1
		PLOT stx, sty+2
		PLOT stx-1, sty+1
		PLOT stx, sty
				
skip:
	
		NEXT iy
	NEXT ix