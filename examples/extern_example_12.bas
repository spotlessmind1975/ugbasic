REM EXTERNAL INTEGRATION DECLARE EXTERNAL PROCEDURES (WITH PARAMETERS)
REM 
REM This small example explains how to declare external
REM procedures to be called as normal procedure inside ugBASIC.
REM Moreover, it explain the syntax on parameter definition and
REM target limitation. Note that this code will not work since there is no
REM assembly code at that position.
REM 
REM @italian
REM INTEGRAZIONE CODICE ESTERNO DICHIARAZIONE DI PROCEDURE (CON PARAMETRI)
REM
REM Questo piccolo esempio spiega come dichiarare procedure
REM esterne affinché siano chiamate come procedure tradizionali
REM all'interno di ugBASIC. In più, da indicazioni sulla sintassi
REM da utilizzare per passare parametri e limitare la definizione
REM a un processore specifico. Da notare che
REM questo codice non funzionerà dato che non c'è codice assembly
REM in quella posizione.
REM
REM @include atari

DECLARE PROCEDURE seriale AT $c000 ( valore AS BYTE ON STACK(BYTE) ) ON CPU6502

	CLS
	
	CALL seriale[42] ON CPU6502
	PROC seriale[42] ON CPU6502
	seriale[42] ON CPU6502
	
