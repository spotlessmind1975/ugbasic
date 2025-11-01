REM EXTERNAL INTEGRATION DECLARE EXTERNAL PROCEDURES
REM 
REM This small example explains how to declare external
REM procedures to be called as normal procedure inside ugBASIC. Note
REM that this code will not work since there is no
REM assembly code at that position.
REM 
REM @italian
REM INTEGRAZIONE CODICE ESTERNO DICHIARAZIONE DI PROCEDURE
REM
REM Questo piccolo esempio spiega come dichiarare procedure
REM esterne affinché siano chiamate come procedure tradizionali
REM all'interno di ugBASIC. Da notare che
REM questo codice non funzionerà dato che non c'è codice assembly
REM in quella posizione.

DECLARE PROC test AT 49142

	CLS
		
	CALL test
	PROC test
	test[]
	