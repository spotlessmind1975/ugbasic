REM @english
REM OTHER CONTRIBUTIONS IF SPEED TEST
REM
REM This example is intended to illustrate the speed with which logical comparisons are performed
REM within the IFs. Which solution is the fastest?
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI SPEED TEST DI IF
REM
REM Questo esempio ha lo scopo di illustrare la velocità con cui vengono eseguiti i confronti 
REM logici all'interno degli IF. Quale soluzione è la più veloce?
REM
REM @url https://www.facebook.com/groups/2057165187928233/posts/3451955151782556/
REM @include atari,atarixl,c128,c64,coco,coleco,cpc

	CLS

	DIM a AS BYTE
	DIM b AS BYTE
	DIM i AS WORD

	DIM ti AS WORD

	PRINT "------------------------"
	PRINT "SPEED TEST"
	PRINT "IF + AND (16.000 cycles)"
	PRINT "------------------------"
	PRINT

	TIMER = 0

	REM 1 if a=0 and b=0 then

	ti = TIMER

	FOR i=0 TO 16000
		IF a=0 AND b=0 THEN
			NOP
		ENDIF
	NEXT

	ti = TIMER - ti

	PRINT "1) a=0 and b=0     : t = "; (ti / TICKS PER SECOND); " sec(s)"

	REM 2 if a=0 then if b=0 then

	ti = TIMER

	FOR i=0 TO 16000
		IF a=0 THEN
			IF b=0 THEN
				NOP
			ENDIF
		ENDIF
	NEXT

	ti = TIMER - ti

	PRINT "2) a=0 then b=0    : t = "; (ti / TICKS PER SECOND); " sec(s)"

	REM 3 if (a=0)*(b=0)=1 then

	ti = TIMER

	FOR i=0 TO 16000
		IF (a=0)*(b=0)=1 THEN
			NOP
		ENDIF
	NEXT

	ti = TIMER - ti

	PRINT "3) (a=0)*(b=0)=1   : t = "; (ti / TICKS PER SECOND); " sec(s)"

	REM 4 if a*a+b*b=0 then

	ti = TIMER

	FOR i=0 TO 16000
		IF (a*a)+(b*b)=0 THEN
			NOP
		ENDIF
	NEXT

	ti = TIMER - ti

	PRINT "4) a*a+b*b=0       : t = "; (ti / TICKS PER SECOND); " sec(s)"

	REM 5 if abs(a)+abs(b)=0 then

	ti = TIMER

	FOR i=0 TO 16000
		IF ABS(a)+ABS(b)=0 THEN
			NOP
		ENDIF
	NEXT

	ti = TIMER - ti

	PRINT "5) abs(a)+abs(b)=0 : t = "; (ti / TICKS PER SECOND); " sec(s)"