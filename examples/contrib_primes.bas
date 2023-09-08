REM @english
REM OTHER CONTRIBUTIONS PRIME NUMBERS
REM
REM This small example will extract the prime numbers between 2 and 400.
REM The algorithm is quite simple and, accordingly, very slow.
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI NUMERI PRIMI
REM
REM Questo piccolo esempio estrarrà i numeri primi fra 2 e 400.
REM L'algoritmo è abbastanza semplice e, di conseguenza, molto lento.
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,cpc

    CLS

    FOR n=2 TO 400
        trov% = 0
        FOR d=2 TO n-1
            prime% = n MOD d
            IF prime% == 0 THEN
                trov% = 1
                d% = n
            ENDIF
        NEXT
        IF trov% == 0 THEN
            PRINT n;" ";
        ENDIF
    NEXT
