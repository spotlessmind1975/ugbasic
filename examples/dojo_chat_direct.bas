REM DOJO PROJECT SIMPLE CHAT CLIENT
REM
REM This example shows how to write a program that uses the DOJO protocol with a 
REM direct connection, that is, not mediated by specific hardware. To work, you 
REM need to connect the retro computer via serial according to the instructions 
REM on the dedicated web site. Alternatively, you can use an appropriately 
REM configured emulator. 
REM 
REM For more information:
REM https://dojo.ugbasic.iwashere.eu/
REM
REM @italian
REM PROGETTO DOJO (ESEMPI) CLIENT CHAT
REM
REM Questo esempio mostra come scrivere un programma che utilizzi il protocollo 
REM DOJO con una connessione diretta, cioè non mediata da hardware specifico. Per
REM funzionare è necessario collegare il retro computer via seriale secondo le 
REM indicazioni contenute nel sito. In alternativa, è possibile utilizzare un 
REM emulatore configurato opportunamente. Per maggiori informazioni si può far 
REM riferimento al sito dedicato: https://dojo.ugbasic.iwashere.eu/
REM 
REM @include coco,atari

CLS

PRINT "================"
PRINT "DOJO CHAT CLIENT"
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
	

