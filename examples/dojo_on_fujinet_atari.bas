REM DOJO PROJECT TESTING FUJINET ON ATARI
REM
REM This example will allow to show how to make
REM applications communicate each other using
REM FujiNet.
REM 
REM For more information:
REM https://dojo.ugbasic.iwashere.eu/
REM
REM @italian
REM PROGETTO DOJO (ESEMPI) FUJINET SU ATARI
REM
REM Questo esempio mostra come far comunicare
REM tra loro le applicazioni, utilizzando FujiNet.
REM 
REM @include atari

DEFINE DOJO ON FUJINET
DEFINE FUJINET ON SIO

CLS

PRINT "================"
PRINT "DOJO ON FUJINET"
PRINT "================"
PRINT

DO
	PRINT "Digit ID or leave blank for new:"
	INPUT roomId$
	digits = LEN(roomId$)
	IF digits <> 8 AND digits <> 0 THEN
		PRINT "ID must be of eight hex digits."
	ELSE
		IF digits = 0 THEN
			port = CREATE PORT()
			myChannel = 0
			otherChannel = 1
		ELSE
			port = OPEN PORT(roomId$)
			myChannel = 1
			otherChannel = 0
		ENDIF
		IF DOJO ERROR > 0 THEN
			PRINT "Invalid port or unavailabe service."
		ELSE
			PRINT "ID: ";port
			PRINT
			EXIT
		ENDIF
	ENDIF
LOOP	

IF myChannel = 0 THEN
	PRINT "Please, send this ID to the other party"
	PRINT "and type a word to send to the other"
	PRINT "application."
	INPUT "> ",message$
	PRINT
	PRINT "Sending..."
	PUT MESSAGE port, otherChannel, message$
	PRINT "... sent!"
ELSE
	DO
		IF PEEK MESSAGE(port, myChannel) THEN
			PRINT GET MESSAGE(port, myChannel)
		ENDIF		
	LOOP
ENDIF
