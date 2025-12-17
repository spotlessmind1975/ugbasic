REM @english
REM I/O CONTROL STRIG FUNCTION
REM
REM This example will read the status of the fire button of a joystick.
REM
REM @italian
REM CONTROLLI DI I/O FUNZIONE STRIG
REM
REM Questo esempio leggerà lo stato del pulsante FIRE di un joystick.
REM
REM @include atari,atarixl,c128, 

OPTION COMPILE ON ATARI,ATARIXL,C128

    CLS

	PRINT "+--------+----+"
	PRINT "| STRIG  |JFIR|"
	PRINT "+--------+----+"

	j = 0
	k = 0
	DO
		LOCATE , 3+k
		PRINT "|";
		i = 0
		DO
			IF j = 300 THEN
				IF STRIG(i) THEN 
					PRINT "**";
				ELSE
					PRINT "  ";
				ENDIF
			ELSE
				PRINT "  ";
			ENDIF
			INC i
		LOOP UNTIL i = 4
		PRINT "|";
		INC j
		i = 0
		DO
			IF JFIRE(i) THEN 
				PRINT "++";
			ELSE
				PRINT " ";
			ENDIF
			INC i
		LOOP UNTIL i = 2
		PRINT "|"
		IF j = 301 THEN 
			IF k < 10 THEN
				INC k
			ENDIF
		ENDIF
		PRINT j
		IF j > 320 THEN j = 0
	LOOP
