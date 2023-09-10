REM @english
REM STRING MANIPULATION SUBTRACTING STRINGS
REM
REM This example shows how the string subtraction works.
REM
REM @italian
REM MANIPOLAZIONE DI STRIGHE DIFFERENZA TRA STRINGHE
REM
REM Questo esempio mostra come funziona la differenza tra stringhe.
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,sg1000,sc3000,cpc

    CLS

    a$ = "I DON'T WANT ANY N IN THIS SENTENCE"
    b$ = "N"
    c$ = a$ - b$

    PRINT a$
    PRINT b$
    PRINT c$
    PRINT "OK"