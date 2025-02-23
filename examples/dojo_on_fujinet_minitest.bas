	CLS
	
	PRINT "DOJO ON FUJINET"
	PRINT "==============="
	PRINT
	PRINT "PRESS ANY KEY WHEN READY"
	
	WAIT KEY RELEASE
	
	DEFINE DOJO ON FUJINET
	
	DO
	
		PRINT
		PRINT "PINGING ..."
		PRINT
		response = HEX$(PING(&H15,&H16))
		
		IF response = "15162A2B" OR response = "2B2A1615" THEN
			PRINT " ... TEST OK!"
		ELSE
			PRINT " ... test ko :("
			PRINT
			PRINT " Expected: 15162A2B"
			PRINT " Received: ";response
		ENDIF

		PRINT
		PRINT "PRESS ANY KEY"
		PRINT
		
		WAIT KEY RELEASE
		
	LOOP