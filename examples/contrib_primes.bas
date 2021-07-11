REM @english
REM OTHER CONTRIBUTIONS PRIME NUMBERS
REM
REM This small example will extract the first 1000 prime numbers.
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI NUMERI PRIMI
REM
REM Questo piccolo esempio estrarrà i primi 1000 numeri primi.
REM

FOR n=3 TO 1000
    trov = 0
    FOR d=2 TO n-1
        prime = n MOD d
        IF prime == 0 THEN
            trov = 1
            d = n
        ENDIF
    NEXT
    IF trov == 0 THEN
        PRINT n;" ";
    ENDIF
NEXT

HALT