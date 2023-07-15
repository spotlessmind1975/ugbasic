REM EXTERNAL INTEGRATION DECLARE EXTERNAL FUNCTIONS (WITH PARAMETERS)
REM 
REM This small example explains how to declare external
REM functions to be called as normal functions inside ugBASIC.
REM Moreover, it explain the syntax on parameter definition and
REM target limitation.
REM 
REM @italian
REM INTEGRAZIONE CODICE ESTERNO DICHIARAZIONE DI FUNZIONI (CON PARAMETRI)
REM
REM Questo piccolo esempio spiega come dichiarare funzioni
REM esterne affinché siano chiamate come funzioni tradizionali
REM all'interno di ugBASIC. In più, da indicazioni sulla sintassi
REM da utilizzare per passare parametri e limitare la definizione
REM a un processore specifico.


DECLARE FUNCTION seriale AT $c000 ( valore AS BYTE ON STACK(BYTE) ) RETURN STACK(BYTE) AS BYTE ON CPU6502

	seriale[42] ON CPU6502
	
	PRINT PARAM(seriale)
	

