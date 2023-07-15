REM EXTERNAL INTEGRATION CALL MACHINE LANGUAGE
REM 
REM This small example explains how to invoke external
REM machine language, already present on the system
REM 
REM @italian
REM INTEGRAZIONE CODICE ESTERNO CHIAMARE CODICE MACCHINA
REM
REM Questo piccolo esempio spiega come invocare codice
REM macchina esterno, già presente sul sistema.

	CLS

	SYS #49152
	
	address = 49152
	
	SYS address

