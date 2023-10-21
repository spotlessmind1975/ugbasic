REM @english
REM EMBEDDED DATA USING RESTORE INSTRUCTION
REM
REM This small example will show how to use the RESTORE instruction.
REM 
REM @italian
REM INCLUDENDO DEI DATI USANDO L'ISTRUZIONE RESTORE
REM
REM Questo piccolo esempio mostra come usare l'istruzione RESTORE
REM
REM @include atari

DATA 42, 21, 10

DIM a AS SIGNED WORD
a = 0
DO
    READ a
    PRINT a;" "
    WAIT KEY
LOOP
