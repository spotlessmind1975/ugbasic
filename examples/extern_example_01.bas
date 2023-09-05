REM EXTERNAL INTEGRATION CALL MACHINE LANGUAGE
REM 
REM This small example explains how to invoke external
REM machine language, already present on the system. Note
REM that this code will not work since there is no
REM assembly code at that position.
REM 
REM @italian
REM INTEGRAZIONE CODICE ESTERNO CHIAMARE CODICE MACCHINA
REM
REM Questo piccolo esempio spiega come invocare codice
REM macchina esterno, già presente sul sistema. Da notare che
REM questo codice non funzionerà dato che non c'è codice assembly
REM in quella posizione
REM
REM @include atari,atarixl,c128,c64

	CLS

	SYS #49152
	
	address = 49152
	
	SYS address
