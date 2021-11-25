REM Starfield, by S.Devulder for ugBasic

CONST numr  =  1000 : REM num of random position in pool 
CONST nums  =    20 : REM number of stars in starfield
CONST speed =     8 : REM speed of stars (smaller = faster)
CONST bg    = BLACK : REM background color

DIM xrnd AS POSITION (numr+1)
DIM yrnd AS POSITION (numr+1)

DIM xtab AS POSITION (nums+1)
DIM ytab AS POSITION (nums+1)
DIM ctab AS BYTE (nums+1)

BITMAP ENABLE (320,200,2)
REM BITMAP ENABLE(320,200,4)
REM BITMAP ENABLE(160,200,16)
COLOR BORDER bg 
CLS bg

REM init pool of random position (faster than calling RND over and over again)
FOR i=0 TO numr
	xrnd(i) = RND(SCREEN WIDTH)
	yrnd(i) = RND(SCREEN HEIGHT)
NEXT
irnd = 0

REM initial stars
FOR i=0 TO nums
	REPEAT : c = RND(SCREEN COLORS) : UNTIL c<>bg
	xtab(i) = RND(SCREEN WIDTH)
	ytab(i) = RND(SCREEN HEIGHT) 
	ctab(i) = c
	
	PLOT xtab(i),ytab(i),ctab(i)
NEXT

VAR x0 AS SIGNED WORD = (SCREEN WIDTH / 2)
VAR y0 AS SIGNED WORD = (SCREEN HEIGHT / 2)

TI=0
DO
	PLOT x0,y0,WHITE
	LOCATE 0,0 : PRINT TI;"    "; : TI = 0
	FOR i=0 TO nums
		z = xtab(i)
		x = z + (z - x0)/speed

		t = ytab(i)	
		y = t + (t - y0)/speed
		
		IF ((x OR y)<0) OR (y>=SCREEN HEIGHT) OR (x>=SCREEN WIDTH) THEN
			REPEAT
				x = xrnd(irnd)
				y = yrnd(irnd)
				ADD irnd,1,0 TO numr
				REM avoid fixed stars, these are the ones where
				REM ((x-x0)/speed)==0 or ((y-y0)/speed)==0
				REM which result in the folowing bitwise AND expression
			UNTIL ((x-x0)/speed) AND ((y-y0)/speed)
		ENDIF
		
		xtab(i) = x
		ytab(i) = y
		
		PLOT z,t,bg
		PLOT x,y,ctab(i)
	NEXT
	joy = JOY(0) : dx = 0 : dy = 0
	IF joy HAS BIT LEFT  THEN : DEC dx : ENDIF
	IF joy HAS BIT RIGHT THEN : INC dx : ENDIF
	IF joy HAS BIT UP    THEN : DEC dy : ENDIF
	IF joy HAS BIT DOWN  THEN : INC dy : ENDIF
	IF (dx OR dy)<>0 THEN
		IF joy HAS BIT FIRE THEN : MUL dx,4 : MUL dy,4 : ENDIF
		PLOT x0,y0,bg
		ADD x0,dx,0 TO SCREEN WIDTH
		ADD y0,dy,0 TO SCREEN HEIGHT
	ENDIF
LOOP
