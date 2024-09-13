REM DOJO PROJECT SIMPLE CHAT CLIENT
REM
REM This example will show how to use the DOJO server
REM under ugBASIC, by emulating a (very simple)
REM chat client. In order to chat with another user
REM you must known its name.
REM
REM @italian
REM PROGETTO DOJO (ESEMPI) CLIENT CHAT
REM
REM Questo esempio mostrerà come usare il server DOJO
REM sotto ugBASIC, emulando un (molto semplice)
REM client chat. Per usarlo con un altro utente,
REM devi conoscere il nome.
REM 
REM @include coco,c64

CONST applicationName = "ugchat"

DO
	CLS
	PRINT "==========="
	PRINT "CHAT CLIENT"
	PRINT "==========="
	WHILE NOT PING()
		PRINT ".";
		WAIT 300 MS
	WEND
	PRINT
	INPUT "USERNAME: ", username$
	INPUT "PASSWORD: ", password$
	PRINT
	PRINT "CONNECTING TO SERVER: ";
	player = LOGIN(username$, password$)
	
	IF SUCCESS(player) THEN
		PRINT "OK"
		PRINT "CREATING PORT: ";
		port = CREATE PORT(player,applicationName)
		IF SUCCESS(port) THEN
			PRINT "OK"
			DO
				INPUT "RECIPIENT: ", recipient$
				port2 = FIND PORT(player,recipient$,applicationName)
				IF SUCCESS(port2) THEN
					DO
						WHILE PEEK MESSAGE(port)
							PRINT recipient$;"> ";GET MESSAGE(port)
						WEND
						TIMER = 0
						WHILE ( c$ = "" ) AND ( TIMER < ( TICKS PER SECOND / 2 ) )
							c$ = INKEY$					
							IF c$<>"" THEN
								PUT KEY c$
								INPUT ">",message$
								IF message$<>"" THEN
									PUT MESSAGE port2, message$
								ENDIF
								c$ = ""
							ENDIF							
						WEND
					LOOP
				ELSE
					PRINT "ERROR: RECIPIENT UNAVAILABLE"
					WAIT KEY RELEASE
				ENDIF
			LOOP
		ELSE
			PRINT "ERROR: CANNOT CREATE PORT"
			WAIT KEY RELEASE
		ENDIF
	ELSE
		PRINT "ERROR: ACCESS DENIED!"
		WAIT KEY RELEASE
	ENDIF
LOOP
	

