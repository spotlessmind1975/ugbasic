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

first:
DATA 42, 21, 10
second:
DATA 1, 2, 3, 99

DIM a AS SIGNED WORD
a = 0
DO
    DO
        READ a
        PRINT a;" "
        EXIT IF a = 99
    LOOP
    RESTORE first
LOOP