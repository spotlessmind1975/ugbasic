REM DOJO PROJECT SIMPLE CHAT CLIENT
REM
REM This example shows how to write a program that uses the DOJO protocol with a 
REM FujiNet (virtual / real). To work, you 
REM need to connect the retro computer ccording to the official instructions 
REM on the dedicated web site. Alternatively, you can use an appropriately 
REM configured emulator. 
REM 
REM For more information:
REM https://dojo.ugbasic.iwashere.eu/
REM
REM @italian
REM PROGETTO DOJO (ESEMPI) CLIENT CHAT
REM
REM Questo esempio mostra come scrivere un programma che usa il protocollo DOJO 
REM con un FujiNet (virtualizzato o reale). Per funzionare, devi 
REM collegare il computer retro secondo le istruzioni ufficiali sul sito web 
REM dedicato. In alternativa, puoi usare un emulatore opportunamente 
REM configurato. Per maggiori info: https://dojo.ugbasic.iwashere.eu/
REM 
REM @include atari

DEFINE DOJO ON FUJINET
DEFINE FUJINET ON HDBDOS

CLS

PRINT "==========="
PRINT "CHAT CLIENT"
PRINT "==========="
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
			PRINT "Room ID: ";port
			PRINT
			EXIT
		ENDIF
	ENDIF
LOOP	

DO
	IF PEEK MESSAGE(port, myChannel) THEN
		PRINT GET MESSAGE(port, myChannel)
	ENDIF
	INPUT "> ",message$
	PUT MESSAGE port, otherChannel, message$
LOOP
	

