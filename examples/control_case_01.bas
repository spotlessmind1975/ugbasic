REM @english
REM FLOW CONTROL BY SELECT CASE (1)
REM
REM This example will show how to use the ''SELECT CASE'' instruction.
REM 
REM @italian
REM CONTROLLO DI FLUSSO CON SELEZIONE MULTIPLA (1)
REM
REM Questo esempio mostra come usare il comando ''SELECT CASE''.
REM

CLS

INPUT "digit a number between 0 and 5: ";number

SELECT CASE number
    CASE 0
        PRINT "zero!"
    CASE 1
        PRINT "odd"
    CASE 2
        PRINT "even"
    CASE 3
        PRINT "odd"
    CASE 4
        PRINT "even"
    CASE 5
        PRINT "odd"
ENDSELECT