REM @english
REM TEXTS OUTPUT GET TEXT POSITION (USING XCURS()/YCURS())
REM
REM This example shows the use of ''XCURS'' and ''YCURS'' function.
REM
REM @italian
REM STAMPA DI TESTI CON POSIZIONAMENTO (10)
REM
REM Questo esempio mostra l'uso di ''XCURS'' oppure ''YCURS''.
REM
REM @include c128,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc

    CLS
    LOCATE 5, 10
    PRINT "5,10 = ";XCURS;" ";YCURS
