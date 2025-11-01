REM @english
REM TEXTS OUTPUT TEXT POSITIONING (USING SPC())
REM
REM This example shows the use of ''SPC'' function.
REM
REM @italian
REM STAMPA DI TESTI USANDO SPC()
REM
REM Questo esempio mostra l'uso della funzione ''SPC'.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc

    CLS

    FOR a=0 TO 10
        PRINT SPC(a);"*"
    NEXT
