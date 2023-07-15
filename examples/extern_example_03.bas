REM EXTERNAL INTEGRATION CALL MACHINE LANGUAGE IN BINARY FILE
REM 
REM This small example explains how to invoke external
REM machine language, loaded from a binary file and included
REM on the system.
REM 
REM @italian
REM INTEGRAZIONE CODICE ESTERNO CHIAMARE CODICE MACCHINA SU FILE BINARIO 
REM
REM Questo piccolo esempio spiega come invocare codice
REM macchina esterno, caricato a sistema da un file binario.

	executable := LOAD("executable_nop.bin")

	address = VARPTR(executable)

	SYS address
	
