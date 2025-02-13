REM FUJINET PROJECT NETWORK STATUS
REM
REM This example shows the realtime status
REM of the Fujinet networking system.
REM
REM @italian
REM PROGETTO FUJINET (ESEMPI) STATO DELLA RETE
REM
REM Questo esempio mostra lo stato in tempo
REM reale del sistema di rete di Fujinet.
REM 
REM @include coco

CLS

DO
	
	FUJINET STATUS

	HOME
	PRINT TIMER
	PRINT
	PRINT "bytes waiting: ";FUJINET BYTES
	PRINT "connected    : ";FUJINET CONNECTED
	PRINT "error        : ";FUJINET ERROR
    
LOOP
