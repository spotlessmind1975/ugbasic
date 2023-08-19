REM @english
REM OTHER CONTRIBUTIONS IF SPEED TEST
REM
REM Speed test: ANDing two conditions in IF statement. 
REM Which solution is the fastest?
REM Original post: https://www.facebook.com/groups/2057165187928233/posts/3451955151782556/
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI SPEED TEST DI IF
REM
REM Test di velocità: l'AND di due condizioni in un
REM comando IF. Quale soluzione è più veloce?
REM Post originale: https://www.facebook.com/groups/2057165187928233/posts/3451955151782556/
REM

CLS

DIM a AS BYTE
DIM b AS BYTE
DIM i AS WORD

DIM ti AS WORD

TIMER = 0

REM 1 if a=0 and b=0 then

ti = TIMER

FOR i=0 TO 16000
	IF a=0 AND b=0 THEN
		NOP
	ENDIF
NEXT

ti = TIMER - ti

PRINT "1 if a=0 and b=0 then : t = "; ti / 60; " sec"

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

PRINT "2 if a=0 then if b=0 then : t = "; ti / 60; " sec"

REM 3 if (a=0)*(b=0)=1 then

ti = TIMER

FOR i=0 TO 16000
	IF (a=0)*(b=0)=1 THEN
		NOP
	ENDIF
NEXT

ti = TIMER - ti

PRINT "3 if (a=0)*(b=0)=1 then : t = "; ti / 60; " sec"

REM 4 if a*a+b*b=0 then

ti = TIMER

FOR i=0 TO 16000
	IF (a*a)+(b*b)=0 THEN
		NOP
	ENDIF
NEXT

ti = TIMER - ti

PRINT "4 if a*a+b*b=0 then : t = "; ti / 60; " sec"

REM 5 if abs(a)+abs(b)=0 then

ti = TIMER

FOR i=0 TO 16000
	IF ABS(a)+ABS(b)=0 THEN
		NOP
	ENDIF
NEXT

ti = TIMER - ti

PRINT "5 if abs(a)+abs(b)=0 then : t = "; ti / 60; " sec"

