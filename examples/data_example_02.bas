REM @english
REM EMBEDDED DATA USING DATA AND READ INSTRUCTION
REM
REM This small example will show how to limit the code generation
REM of the libraries to the screen mode selected.
REM 
REM @italian
REM INCLUDENDO DEI DATI USANDO LE ISTRUZIONI DATA E READ
REM
REM Questo piccolo esempio mostra come limitare la generazione del
REM codice delle librerie alla modalità selezionata.
REM
REM @include atari

first:
DATA 42, 21, 10
second:
DATA 1, 2, 3, 99

a = 0
DO
    READ a
    PRINT a;" "
    EXIT IF a = 99
LOOP